#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* 初始化 ADC 回调函数设置 */
    hadc->ConvCpltCallback              = HAL_ADC_ConvCpltCallback;                 /* 注册默认的弱定义回调函数：转换完成回调 */
    hadc->ConvHalfCpltCallback          = HAL_ADC_ConvHalfCpltCallback;             /* 注册默认的弱定义回调函数：半转换完成回调 */
    hadc->LevelOutOfWindowCallback      = HAL_ADC_LevelOutOfWindowCallback;         /* 注册默认的弱定义回调函数：模拟看门狗越界回调 */
    hadc->ErrorCallback                 = HAL_ADC_ErrorCallback;                    /* 注册默认的弱定义回调函数：错误回调 */
    hadc->InjectedConvCpltCallback      = HAL_ADCEx_InjectedConvCpltCallback;       /* 注册默认的弱定义回调函数：注入组转换完成回调 */
    
    /* 如果用户没有注册底层的 MspInit 回调函数 */
    if (hadc->MspInitCallback == NULL)
    {
      /* 则使用默认的弱定义 MspInit 回调函数 */
      hadc->MspInitCallback = HAL_ADC_MspInit; 
    }
    
    /* 初始化底层硬件（如时钟、GPIO等） */
    hadc->MspInitCallback(hadc);
#else
    /* 初始化底层硬件（如时钟、GPIO等），不使用回调机制时直接调用函数 */
    HAL_ADC_MspInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }
  
  /* 停止正在进行中的转换，包括规则组和注入组 */
  /* 关闭 ADC 外设 */
  /* 注意：如果 ADC 已经使能，在修改 CR2 寄存器时写入 1 到 ADON 位可能会意外启动转换，需要特别注意 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  
  /* 如果上述预备操作正确完成，则配置 ADC 参数 */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL) &&
      (tmp_hal_status == HAL_OK)                                  )
  {
    /* 设置 ADC 状态：清除忙状态，置位内部忙状态 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_BUSY_INTERNAL);
    
    /* 设置 ADC 参数 */
    
    /* 配置 ADC 参数： */
    /*  - 数据对齐方式 */
    /*  - 外部触发转换选择 */
    /*  - 外部触发极性（始终设为 1，因为所有触发源都需要，包括软件触发） */
    /*  - 连续转换模式 */
    /* 注意：外部触发极性 (ADC_CR2_EXTTRIG) 在 HAL_ADC_Start_xxx 函数中设置， */
    /* 因为如果在此函数中设置，使能 ADC 后注入组转换可能会意外启动规则组转换。 */
    tmp_cr2 |= (hadc->Init.DataAlign                                          |
                ADC_CFGR_EXTSEL(hadc, hadc->Init.ExternalTrigConv)            |
                ADC_CR2_CONTINUOUS((uint32_t)hadc->Init.ContinuousConvMode)   );

    /* 配置 ADC 参数： */
    /*  - 扫描模式 */
    /*  - 不连续模式禁用/使能 */
    /*  - 不连续模式转换数量 */
    tmp_cr1 |= (ADC_CR1_SCAN_SET(hadc->Init.ScanConvMode));
    
    /* 仅在连续模式禁用时使能不连续模式 */
    /* 注意：如果参数 "Init.ScanConvMode" 为禁用，不连续模式设置无效，但不会影响硬件 */
    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      if (hadc->Init.ContinuousConvMode == DISABLE)
      {
        /* 使能选定的 ADC 规则组不连续模式 */
        /* 设置不连续模式下的转换通道数 */
        SET_BIT(tmp_cr1, ADC_CR1_DISCEN                                            |
                         ADC_CR1_DISCONTINUOUS_NUM(hadc->Init.NbrOfDiscConversion)  );
      }
      else
      {
        /* ADC 规则组设置：连续模式和序列器不连续模式不能同时使能 */
        
        /* 更新 ADC 状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        /* 设置 ADC 错误码为内部错误 */
        SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      }
    }
    
    /* 使用之前的设置更新 ADC 配置寄存器 CR1 */
      MODIFY_REG(hadc->Instance->CR1,
                 ADC_CR1_SCAN    |
                 ADC_CR1_DISCEN  |
                 ADC_CR1_DISCNUM    ,
                 tmp_cr1             );
    
    /* 使用之前的设置更新 ADC 配置寄存器 CR2 */
      MODIFY_REG(hadc->Instance->CR2,
                 ADC_CR2_ALIGN   |
                 ADC_CR2_EXTSEL  |
                 ADC_CR2_EXTTRIG |
                 ADC_CR2_CONT       ,
                 tmp_cr2             );

    /* 配置规则组序列器： */
    /* - 如果扫描模式禁用，规则通道序列长度设为 0x00：转换 1 个通道（规则排名 1 的通道） */
    /*   参数 "NbrOfConversion" 被忽略。 */
    /*   注意：硬件上存在扫描模式，禁用时会自动忽略转换数量。强制设为 0x00 是为了兼容所有 STM32 设备。 */
    /* - 如果扫描模式使能，规则通道序列长度设为参数 "NbrOfConversion" */
    if (ADC_CR1_SCAN_SET(hadc->Init.ScanConvMode) == ADC_SCAN_ENABLE)
    {
      tmp_sqr1 = ADC_SQR1_L_SHIFT(hadc->Init.NbrOfConversion);
    }
      
    MODIFY_REG(hadc->Instance->SQR1,
               ADC_SQR1_L          ,
               tmp_sqr1             );
    
    /* 回读检查 ADC 寄存器是否已有效配置，确保 ADC 核心时钟没有问题 */
    /* 通过检查寄存器 CR2（排除其他函数设置的位：执行控制位 ADON, JSWSTART, SWSTART，规则组位 DMA，注入组位 JEXTTRIG 和 JEXTSEL，内部测量通道位 TSVREFE） */
    if (READ_BIT(hadc->Instance->CR2, ~(ADC_CR2_ADON | ADC_CR2_DMA |
                                        ADC_CR2_SWSTART | ADC_CR2_JSWSTART |
                                        ADC_CR2_JEXTTRIG | ADC_CR2_JEXTSEL |
                                        ADC_CR2_TSVREFE                     ))
         == tmp_cr2)
    {
      /* 设置 ADC 错误码为无错误 */
      ADC_CLEAR_ERRORCODE(hadc);
      
      /* 设置 ADC 状态为就绪 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_READY);
    }
    else
    {
      /* 更新 ADC 状态机为内部错误状态 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_ERROR_INTERNAL);
      
      /* 设置 ADC 错误码为 ADC IP 内部错误 */
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      
      tmp_hal_status = HAL_ERROR;
    }
  
  }
  else
  {
    /* 更新 ADC 状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);
        
    tmp_hal_status = HAL_ERROR;
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  反初始化 ADC 外设寄存器到默认复位值，同时反初始化 ADC MSP。
  *         如果需要，可以复制示例代码并取消注释到函数 HAL_ADC_MspDeInit() 中。
  * @param  hadc: ADC 句柄指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查 ADC 句柄是否有效 */
  if(hadc == NULL)
  {
     return HAL_ERROR;
  }
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* 设置 ADC 状态为内部忙 */
  SET_BIT(hadc->State, HAL_ADC_STATE_BUSY_INTERNAL);
  
  /* 停止正在进行中的转换，包括规则组和注入组 */
  /* 关闭 ADC 外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  
  /* 如果上述预备操作正确完成，则配置 ADC 参数 */
  if (tmp_hal_status == HAL_OK)
  {
    /* ========== 复位 ADC 寄存器 ========== */




    /* 复位状态寄存器 SR */
    __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_AWD | ADC_FLAG_JEOC | ADC_FLAG_EOC |
                                ADC_FLAG_JSTRT | ADC_FLAG_STRT));
                         
    /* 复位控制寄存器 CR1：清除模拟看门狗、扫描模式、中断使能等配置位 */
    CLEAR_BIT(hadc->Instance->CR1, (ADC_CR1_AWDEN   | ADC_CR1_JAWDEN | ADC_CR1_DISCNUM | 
                                    ADC_CR1_JDISCEN | ADC_CR1_DISCEN | ADC_CR1_JAUTO   | 
                                    ADC_CR1_AWDSGL  | ADC_CR1_SCAN   | ADC_CR1_JEOCIE  |   
                                    ADC_CR1_AWDIE   | ADC_CR1_EOCIE  | ADC_CR1_AWDCH    ));
    
    /* 复位控制寄存器 CR2：清除温度传感器、启动转换、外部触发、对齐、DMA、校准、连续模式等配置位 */
    CLEAR_BIT(hadc->Instance->CR2, (ADC_CR2_TSVREFE | ADC_CR2_SWSTART | ADC_CR2_JSWSTART | 
                                    ADC_CR2_EXTTRIG | ADC_CR2_EXTSEL  | ADC_CR2_JEXTTRIG |  
                                    ADC_CR2_JEXTSEL | ADC_CR2_ALIGN   | ADC_CR2_DMA      |        
                                    ADC_CR2_RSTCAL  | ADC_CR2_CAL     | ADC_CR2_CONT     |          
                                    ADC_CR2_ADON                                          ));
    
    /* 复位采样时间寄存器 SMPR1：清除通道 10-17 的采样时间配置 */
    CLEAR_BIT(hadc->Instance->SMPR1, (ADC_SMPR1_SMP17 | ADC_SMPR1_SMP16 | ADC_SMPR1_SMP15 | 
                                      ADC_SMPR1_SMP14 | ADC_SMPR1_SMP13 | ADC_SMPR1_SMP12 | 
                                      ADC_SMPR1_SMP11 | ADC_SMPR1_SMP10                    ));
    
    /* 复位采样时间寄存器 SMPR2：清除通道 0-9 的采样时间配置 */
    CLEAR_BIT(hadc->Instance->SMPR2, (ADC_SMPR2_SMP9 | ADC_SMPR2_SMP8 | ADC_SMPR2_SMP7 | 
                                      ADC_SMPR2_SMP6 | ADC_SMPR2_SMP5 | ADC_SMPR2_SMP4 | 
                                      ADC_SMPR2_SMP3 | ADC_SMPR2_SMP2 | ADC_SMPR2_SMP1 | 
                                      ADC_SMPR2_SMP0                                    ));

    /* 复位注入通道偏移寄存器 JOFR1 */
    CLEAR_BIT(hadc->Instance->JOFR1, ADC_JOFR1_JOFFSET1);
    /* 复位注入通道偏移寄存器 JOFR2 */
    CLEAR_BIT(hadc->Instance->JOFR2, ADC_JOFR2_JOFFSET2);
    /* 复位注入通道偏移寄存器 JOFR3 */
    CLEAR_BIT(hadc->Instance->JOFR3, ADC_JOFR3_JOFFSET3);
    /* 复位注入通道偏移寄存器 JOFR4 */
    CLEAR_BIT(hadc->Instance->JOFR4, ADC_JOFR4_JOFFSET4);
    
    /* 复位看门狗高阈值寄存器 HTR */
    CLEAR_BIT(hadc->Instance->HTR, ADC_HTR_HT);
    /* 复位看门狗低阈值寄存器 LTR */
    CLEAR_BIT(hadc->Instance->LTR, ADC_LTR_LT);
    
    /* 复位规则序列寄存器 SQR1：清除序列长度和通道配置 */
    CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L    |
                                    ADC_SQR1_SQ16 | ADC_SQR1_SQ15 | 
                                    ADC_SQR1_SQ14 | ADC_SQR1_SQ13  );
    
    /* 复位规则序列寄存器 SQR1（此处为源码重复操作） */
    CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L    |
                                    ADC_SQR1_SQ16 | ADC_SQR1_SQ15 | 
                                    ADC_SQR1_SQ14 | ADC_SQR1_SQ13  );
    
    /* 复位规则序列寄存器 SQR2：清除通道 7-12 的配置 */
    CLEAR_BIT(hadc->Instance->SQR2, ADC_SQR2_SQ12 | ADC_SQR2_SQ11 | ADC_SQR2_SQ10 | 
                                    ADC_SQR2_SQ9  | ADC_SQR2_SQ8  | ADC_SQR2_SQ7   );
    
    /* 复位规则序列寄存器 SQR3：清除通道 1-6 的配置 */
    CLEAR_BIT(hadc->Instance->SQR3, ADC_SQR3_SQ6 | ADC_SQR3_SQ5 | ADC_SQR3_SQ4 | 
                                    ADC_SQR3_SQ3 | ADC_SQR3_SQ2 | ADC_SQR3_SQ1  );
    
    /* 复位注入序列寄存器 JSQR */
    CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL |
                                    ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | 
                                    ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1  );
    
    /* 复位注入序列寄存器 JSQR（此处为源码重复操作） */
    CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL |
                                    ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | 
                                    ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1  );
    
    /* 复位数据寄存器 DR */
    /* 该寄存器为只读，无法直接复位 */
    
    /* 复位注入数据寄存器 JDR1, JDR2, JDR3, JDR4 */
    /* 这些寄存器为只读，无法直接复位 */
    
    /* ========== ADC 外设硬件复位 ========== */
    /* 执行整个 ADC 外设的全局复位：ADC 状态被强制为类似上电后的状态。 */
    /* 如果需要，请将以下复位代码复制并取消注释到函数 "void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)" 中： */
    /*                                                                        */
    /*  __HAL_RCC_ADC1_FORCE_RESET()                                          */
    /*  __HAL_RCC_ADC1_RELEASE_RESET()                                        */
    
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* 如果未注册底层的 MspDeInit 回调函数 */
    if (hadc->MspDeInitCallback == NULL)
    {
      /* 则使用默认的弱定义 MspDeInit 回调函数 */
      hadc->MspDeInitCallback = HAL_ADC_MspDeInit; 
    }
    
    /* 反初始化底层硬件（如关闭时钟、反初始化 GPIO 等） */
    hadc->MspDeInitCallback(hadc);
#else
    /* 反初始化底层硬件（如关闭时钟、反初始化 GPIO 等），不使用回调机制时直接调用函数 */
    HAL_ADC_MspDeInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
    
    /* 设置 ADC 错误码为无错误 */
    ADC_CLEAR_ERRORCODE(hadc);
    
    /* 设置 ADC 状态为复位态 */
    hadc->State = HAL_ADC_STATE_RESET; 
  
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  初始化 ADC MSP（MCU特定包）。
  *         此函数用于配置底层硬件，如 GPIO、时钟等。
  * @param  hadc: ADC 句柄指针
  * @retval 无
  */
__weak void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  /* 防止编译器产生未使用参数的警告 */
  UNUSED(hadc);
  /* 注意：此函数不应被修改。当需要回调时，
           函数 HAL_ADC_MspInit 必须在用户文件中实现。
   */ 
}

/**
  * @brief  反初始化 ADC MSP（MCU特定包）。
  *         此函数用于复位底层硬件，如 GPIO、时钟等。
  * @param  hadc: ADC 句柄指针
  * @retval 无
  */
__weak void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  /* 防止编译器产生未使用参数的警告 */
  UNUSED(hadc);
  /* 注意：此函数不应被修改。当需要回调时，
           函数 HAL_ADC_MspDeInit 必须在用户文件中实现。
   */ 
}

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  注册用户自定义的 ADC 回调函数
  *         用于替代默认的弱定义回调函数
  * @param  hadc 指向 ADC_HandleTypeDef 结构体的指针，包含指定 ADC 的配置信息
  * @param  CallbackID 要注册的回调函数 ID
  *         此参数可以是以下值之一:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC 转换完成回调 ID
  *          @arg @ref HAL_ADC_CONVERSION_HALF_CB_ID          ADC 半转换完成回调 ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC 模拟看门狗 1 回调 ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC 错误回调 ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC 注入组转换完成回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp 初始化回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp 反初始化回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID MspInit 回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID MspDeInit 回调 ID
  * @param  pCallback 指向回调函数的指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* 检查回调函数指针是否为空 */
  if (pCallback == NULL)
  {
    /* 更新错误码 */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  
  /* 如果 ADC 处于就绪状态 */
  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        /* 注册转换完成回调函数 */
        hadc->ConvCpltCallback = pCallback;
        break;
      
      case HAL_ADC_CONVERSION_HALF_CB_ID :
        /* 注册半转换完成回调函数 */
        hadc->ConvHalfCpltCallback = pCallback;
        break;
      
      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        /* 注册模拟看门狗越界回调函数 */
        hadc->LevelOutOfWindowCallback = pCallback;
        break;
      
      case HAL_ADC_ERROR_CB_ID :
        /* 注册错误回调函数 */
        hadc->ErrorCallback = pCallback;
        break;
      
      case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        /* 注册注入组转换完成回调函数 */
        hadc->InjectedConvCpltCallback = pCallback;
        break;
      
      case HAL_ADC_MSPINIT_CB_ID :
        /* 注册 Msp 初始化回调函数 */
        hadc->MspInitCallback = pCallback;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        /* 注册 Msp 反初始化回调函数 */
        hadc->MspDeInitCallback = pCallback;
        break;
      
      default :
        /* 更新错误码 */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* 返回错误状态 */
        status = HAL_ERROR;
        break;
    }
  }
  /* 如果 ADC 处于复位状态 */
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        /* 注册 Msp 初始化回调函数 */
        hadc->MspInitCallback = pCallback;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        /* 注册 Msp 反初始化回调函数 */
        hadc->MspDeInitCallback = pCallback;
        break;
      
      default :
        /* 更新错误码 */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
      
        /* 返回错误状态 */
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    /* 更新错误码 */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
    
    /* 返回错误状态 */
    status =  HAL_ERROR;
  }
  
  return status;
}

/**
  * @brief  注销 ADC 回调函数
  *         ADC 回调函数将被重定向到默认的弱定义回调函数
  * @param  hadc 指向 ADC_HandleTypeDef 结构体的指针，包含指定 ADC 的配置信息
  * @param  CallbackID 要注销的回调函数 ID
  *         此参数可以是以下值之一:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC 转换完成回调 ID
  *          @arg @ref HAL_ADC_CONVERSION_HALF_CB_ID          ADC 半转换完成回调 ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC 模拟看门狗 1 回调 ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC 错误回调 ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC 注入组转换完成回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp 初始化回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp 反初始化回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID MspInit 回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID MspDeInit 回调 ID
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* 如果 ADC 处于就绪状态 */
  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        /* 恢复为默认的弱定义转换完成回调函数 */
        hadc->ConvCpltCallback = HAL_ADC_ConvCpltCallback;
        break;
      
      case HAL_ADC_CONVERSION_HALF_CB_ID :
        /* 恢复为默认的弱定义半转换完成回调函数 */
        hadc->ConvHalfCpltCallback = HAL_ADC_ConvHalfCpltCallback;
        break;
      
      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        /* 恢复为默认的弱定义模拟看门狗越界回调函数 */
        hadc->LevelOutOfWindowCallback = HAL_ADC_LevelOutOfWindowCallback;
        break;
      
      case HAL_ADC_ERROR_CB_ID :
        /* 恢复为默认的弱定义错误回调函数 */
        hadc->ErrorCallback = HAL_ADC_ErrorCallback;
        break;
