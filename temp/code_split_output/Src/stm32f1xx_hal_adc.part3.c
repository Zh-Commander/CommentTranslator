/**
  * @brief  停止ADC常规组的转换（如果是自动注入模式，也包括注入组），
  *         禁用转换结束中断，禁用ADC外设。
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
     
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
  /* 停止当前正在进行的常规组和注入组的转换 */
  /* 禁用ADC外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* 检查ADC是否确实已被禁用 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 禁用ADC常规组的转换结束中断 */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC);
    
    /* 设置ADC状态 */
    /* 清除忙状态标志，设置为就绪状态 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数执行状态 */
  return tmp_hal_status;
}

/**
  * @brief  使能ADC，启动常规组转换并通过DMA传输结果。
  *         此函数中使能的中断：
  *          - DMA传输完成中断
  *          - DMA半传输中断
  *         每个中断都有其专用的回调函数。
  * @note   对于具有多个ADC的设备：此函数仅适用于单ADC模式。
  *         对于多ADC模式，请使用专用的MultimodeStart函数。
  * @note   在STM32F1系列设备上，只有ADC1和ADC3（取决于具体设备）具有DMA功能。
  *         ADC2的转换数据可以在双ADC模式下使用ADC1的DMA进行传输（ADC1在多模式下为主ADC）。
  *         如果在具有2个ADC实例的设备上使用ADC1和DMA：
  *         ADC1转换寄存器DR包含ADC1转换结果（DR寄存器的0到11位），
  *         此外还包含ADC2的最后转换结果（DR寄存器的16到27位）。
  *         因此，如果只让DMA传输ADC1的转换结果，必须将DMA配置为半字传输。
  * @param  hadc: ADC句柄指针
  * @param  pData: 目标缓冲区地址（用于存储转换结果）
  * @param  Length: 要从ADC外设传输到内存的数据长度
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_DMA_CAPABILITY_INSTANCE(hadc->Instance));
    
  /* 验证多ADC模式是否禁用（针对有多个ADC的设备） */
  /* 如果启用了多ADC模式，必须使用专用的多模式转换启动DMA函数 */
  if(ADC_MULTIMODE_IS_ENABLE(hadc) == RESET)
  {
    /* 锁定进程 */
    __HAL_LOCK(hadc);
    
    /* 使能ADC外设 */
    tmp_hal_status = ADC_Enable(hadc);
    
    /* 如果ADC确实已使能，则开始转换 */
    if (tmp_hal_status == HAL_OK)
    {
      /* 设置ADC状态 */
      /* - 清除与常规组转换结果相关的状态位 */
      /* - 设置与常规操作相关的状态位 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_OVR | HAL_ADC_STATE_REG_EOSMP,
                        HAL_ADC_STATE_REG_BUSY);
    
    /* 设置注入组状态（来自自动注入）和多模式状态 */
    /* 适用于所有多模式情况：独立模式、多模式ADC主设备或多模式ADC从设备（针对有多个ADC的设备） */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      /* 设置ADC状态（ADC独立模式或主模式） */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* 如果常规组上的转换也触发注入组，则更新ADC状态 */
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      /* 设置ADC状态（ADC从模式） */
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* 如果常规组上的转换也触发注入组，则更新ADC状态 */
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
      
      /* 状态机更新：检查是否有注入转换正在进行 */
      if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
      {
        /* 复位与常规组转换相关的ADC错误代码字段 */
        CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
      }
      else
      {
        /* 复位所有ADC错误代码字段 */
        ADC_CLEAR_ERRORCODE(hadc);
      }
      
      /* 解锁进程 */
      /* 在启动ADC转换之前解锁：以便在发生潜在中断时，让进程能进入ADC中断处理程序 */
      __HAL_UNLOCK(hadc);
      
      /* 设置DMA传输完成回调函数 */
      hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;

      /* 设置DMA半传输完成回调函数 */
      hadc->DMA_Handle->XferHalfCpltCallback = ADC_DMAHalfConvCplt;
      
      /* 设置DMA错误回调函数 */
      hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;

      
      /* 管理ADC和DMA启动：ADC溢出中断、DMA启动、ADC启动（如果是软件触发） */
      
      /* 清除常规组转换标志和溢出标志 */
      /* (确保没有来自之前ADC操作的未知状态) */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
      
      /* 使能ADC DMA模式 */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
      
      /* 启动DMA通道 */
      /* 源地址：ADC数据寄存器DR，目的地址：用户指定的内存缓冲区pData，长度：Length */
      HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);
      
      /* 使能常规组转换 */
      /* 如果选择了软件启动，转换立即开始 */
      /* 如果选择了外部触发，转换将在下一个触发事件开始 */
      if (ADC_IS_SOFTWARE_START_REGULAR(hadc))
      {
        /* 使用软件触发启动ADC常规组转换 */
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
      }
      else
      {
        /* 使用外部触发启动ADC常规组转换 */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
      }
    }
    else
    {
      /* 解锁进程 */
      __HAL_UNLOCK(hadc);
    }
  }
  else
  {
    tmp_hal_status = HAL_ERROR;
  }
  
  /* 返回函数执行状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止ADC常规组的转换（如果是自动注入模式，也包括注入组），
  *         禁用ADC DMA传输，禁用ADC外设。
  * @note:  禁用ADC外设会强制停止注入组上可能正在进行的转换。
  *         如果正在使用注入组，应预先使用HAL_ADCEx_InjectedStop函数停止它。
  * @note   对于具有多个ADC的设备：此函数仅适用于单ADC模式。
  *         对于多ADC模式，请使用专用的MultimodeStop函数。
  * @note   在STM32F1系列设备上，只有ADC1和ADC3（取决于具体设备）具有DMA功能。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_DMA_CAPABILITY_INSTANCE(hadc->Instance));
     
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
  /* 停止当前正在进行的常规组和注入组的转换 */
  /* 禁用ADC外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* 检查ADC是否确实已被禁用 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 禁用ADC DMA模式 */
    CLEAR_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* 禁用DMA通道（防止DMA处于循环模式或DMA传输正在进行时停止失败） */
    if (hadc->DMA_Handle->State == HAL_DMA_STATE_BUSY)
    {
      tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);
      
      /* 检查DMA通道是否确实已被禁用 */
      if (tmp_hal_status == HAL_OK)
      {
        /* 设置ADC状态 */
        ADC_STATE_CLR_SET(hadc->State,
                          HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                          HAL_ADC_STATE_READY);
      }
      else
      {
        /* 更新ADC状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
      }
    }
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
    
  /* 返回函数执行状态 */
  return tmp_hal_status;
}

/**
  * @brief  获取ADC常规组的转换结果。
  * @note   读取DR寄存器会自动清除ADC标志位EOC
  *         (ADC常规组单元转换结束标志)。
  * @note   此函数不会清除ADC标志位EOS 
  *         (ADC常规组序列转换结束标志)。
  *         EOS标志出现的时机：
  *          - 如果序列器只配置了1个通道，EOS标志等同于EOC标志。
  *          - 如果序列器配置了多个通道，在扫描序列期间只会升起EOC标志，
  *            在扫描序列结束时，EOC和EOS标志都会升起。
  *         清除此标志的方法： 
  *         中断编程模式下使用：@ref HAL_ADC_IRQHandler()，
  *         轮询编程模式下使用：@ref HAL_ADC_PollForConversion() 
  *         或者 @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOS)。
  * @param  hadc: ADC句柄指针
  * @retval ADC常规组转换数据
  */
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef* hadc)
{
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 注意: 此处软件不清除EOC标志，因为硬件在读取DR寄存器时会自动清除 */
  
  /* 返回ADC转换值 */ 
  return hadc->Instance->DR;
}

/**
  * @brief  处理ADC中断请求  
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
void HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc)
{
  uint32_t tmp_sr = hadc->Instance->SR; // 读取ADC状态寄存器
  uint32_t tmp_cr1 = hadc->Instance->CR1; // 读取ADC控制寄存器1

  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  assert_param(IS_ADC_REGULAR_NB_CONV(hadc->Init.NbrOfConversion));
  
  
  /* ========== 检查常规组的转换结束标志 ========== */
  if((tmp_cr1 & ADC_IT_EOC) == ADC_IT_EOC) // 检查是否使能了EOC中断
  {
    if((tmp_sr & ADC_FLAG_EOC) == ADC_FLAG_EOC) // 检查是否产生了EOC标志
    {
      /* 如果不在内部错误状态，则更新转换状态的状态机 */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL))
      {
        /* 设置ADC状态：常规组转换完成 */
        SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC); 
      }
      
      /* 确定常规组是否还有后续转换 */
      /* 通过外部触发、连续模式或扫描序列正在进行来判断 */
      /* 注意: 在STM32F1设备上，如果序列器使能（选择了多个通道），转换结束标志会在序列结束时升起 */
      if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        && 
         (hadc->Init.ContinuousConvMode == DISABLE)   )
      {
        /* 禁用ADC常规组的转换结束中断 */
        __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC);
        
        /* 设置ADC状态：清除常规组忙标志 */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);   
        
        /* 如果注入组也不忙，则设置ADC为就绪状态 */
        if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_INJ_BUSY))
        {
          SET_BIT(hadc->State, HAL_ADC_STATE_READY);
        }
      }

      /* 转换完成回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->ConvCpltCallback(hadc);
#else
      HAL_ADC_ConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* 清除常规组转换标志 */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT | ADC_FLAG_EOC);
    }
  }
  
  /* ========== 检查注入组的转换结束标志 ========== */
  if((tmp_cr1 & ADC_IT_JEOC) == ADC_IT_JEOC) // 检查是否使能了JEQC中断
  {
    if((tmp_sr & ADC_FLAG_JEOC) == ADC_FLAG_JEOC) // 检查是否产生了JEQC标志
    {
      /* 如果不在内部错误状态，则更新转换状态的状态机 */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL))
      {
        /* 设置ADC状态：注入组转换完成 */
        SET_BIT(hadc->State, HAL_ADC_STATE_INJ_EOC);
      }

      /* 确定注入组是否还有后续转换 */
      /* 通过外部触发、扫描序列正在进行或来自常规组的自动注入转换判断 */
      /* (与上面常规组中断禁用的条件相同) */
      /* 注意: 在STM32F1设备上，如果序列器使能（选择了多个通道），转换结束标志会在序列结束时升起 */
      if(ADC_IS_SOFTWARE_START_INJECTED(hadc)                     || 
         (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO) &&     
         (ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&
          (hadc->Init.ContinuousConvMode == DISABLE)   )        )   )
      {
        /* 禁用ADC注入组的转换结束中断 */
        __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
        
        /* 设置ADC状态：清除注入组忙标志 */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_INJ_BUSY);   

        /* 如果常规组也不忙，则设置ADC为就绪状态 */
        if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
        { 
          SET_BIT(hadc->State, HAL_ADC_STATE_READY);
        }
      }

      /* 转换完成回调函数 */ 
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->InjectedConvCpltCallback(hadc);
#else
      HAL_ADCEx_InjectedConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* 清除注入组转换标志 */
      __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_JSTRT | ADC_FLAG_JEOC));
    }
  }
   
  /* ========== 检查模拟看门狗标志 ========== */
  if((tmp_cr1 & ADC_IT_AWD) == ADC_IT_AWD) // 检查是否使能了AWD中断
  {
    if((tmp_sr & ADC_FLAG_AWD) == ADC_FLAG_AWD) // 检查是否产生了AWD标志
    {
      /* 设置ADC状态：模拟看门狗标志位 */
      SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);
      
      /* 超出窗口回调函数 */ 
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->LevelOutOfWindowCallback(hadc);
#else
      HAL_ADC_LevelOutOfWindowCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* 清除ADC模拟看门狗标志 */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD);
    }
  }
  
}

/**
  * @brief  非阻塞模式下的转换完成回调函数 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_ConvCpltCallback必须在用户文件中实现。
   */
}

/**
  * @brief  非阻塞模式下的转换DMA半传输回调函数 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_ConvHalfCpltCallback必须在用户文件中实现。
  */
}

/**
  * @brief  非阻塞模式下的模拟看门狗回调函数。 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_LevelOutOfWindowCallback必须在用户文件中实现。
  */
}

/**
  * @brief  非阻塞模式下的ADC错误回调函数
  *         (带中断的ADC转换或DMA传输)
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_ErrorCallback必须在用户文件中实现。
  */
}


/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group3 Peripheral Control functions
 *  @brief    外设控制函数
 *
@verbatim   
 ===============================================================================
             ##### 外设控制函数 #####
 ===============================================================================  
    [..]  本节提供以下功能函数：
      (+) 配置常规组通道
      (+) 配置模拟看门狗
      
@endverbatim
  * @{
  */

/**
  * @brief  配置选定的通道链接到常规组。
  * @note   如果使用内部测量通道：
  *         Vbat/VrefInt/TempSensor。
  *         这些内部路径可以使用函数HAL_ADC_DeInit()禁用。
  * @note   可以动态更新参数：
  *         此函数将通道初始化到常规组中，后续调用此函数可以
  *         动态地重新配置结构体"ADC_ChannelConfTypeDef"的某些参数，
  *         而无需复位ADC。
  *         这些参数的设置受ADC状态限制。
  *         有关参数约束，请参阅结构体"ADC_ChannelConfTypeDef"的注释。
  * @param  hadc: ADC句柄指针
  * @param  sConfig: ADC常规组通道配置结构体指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig)
{ 
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  __IO uint32_t wait_loop_index = 0U; // 用于延时等待的循环变量
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_CHANNEL(sConfig->Channel)); // 检查通道号
  assert_param(IS_ADC_REGULAR_RANK(sConfig->Rank)); // 检查序列排名
  assert_param(IS_ADC_SAMPLE_TIME(sConfig->SamplingTime)); // 检查采样时间
  
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
