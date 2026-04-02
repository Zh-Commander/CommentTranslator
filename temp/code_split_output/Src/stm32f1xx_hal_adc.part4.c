/* 规则序列配置 */
  /* 对于排名 1 到 6 的通道 */
  if (sConfig->Rank < 7U)
  {
    /* 修改SQR3寄存器，配置排名1-6的通道 */
    MODIFY_REG(hadc->Instance->SQR3                        ,  // SQR3寄存器存放第1-6个转换通道
               ADC_SQR3_RK(ADC_SQR3_SQ1, sConfig->Rank)    ,  // 清除对应排名的通道位
               ADC_SQR3_RK(sConfig->Channel, sConfig->Rank) ); // 设置对应排名的通道号
  }
  /* 对于排名 7 到 12 的通道 */
  else if (sConfig->Rank < 13U)
  {
    /* 修改SQR2寄存器，配置排名7-12的通道 */
    MODIFY_REG(hadc->Instance->SQR2                        ,  // SQR2寄存器存放第7-12个转换通道
               ADC_SQR2_RK(ADC_SQR2_SQ7, sConfig->Rank)    ,  // 清除对应排名的通道位
               ADC_SQR2_RK(sConfig->Channel, sConfig->Rank) ); // 设置对应排名的通道号
  }
  /* 对于排名 13 到 16 的通道 */
  else
  {
    /* 修改SQR1寄存器，配置排名13-16的通道 */
    MODIFY_REG(hadc->Instance->SQR1                        ,  // SQR1寄存器存放第13-16个转换通道
               ADC_SQR1_RK(ADC_SQR1_SQ13, sConfig->Rank)   ,  // 清除对应排名的通道位
               ADC_SQR1_RK(sConfig->Channel, sConfig->Rank) ); // 设置对应排名的通道号
  }
  
  
  /* 通道采样时间配置 */
  /* 对于通道 10 到 17 */
  if (sConfig->Channel >= ADC_CHANNEL_10)
  {
    /* 修改SMPR1寄存器，配置通道10-17的采样时间 */
    MODIFY_REG(hadc->Instance->SMPR1                             ,
               ADC_SMPR1(ADC_SMPR1_SMP10, sConfig->Channel)      ,  // 清除对应通道的采样时间位
               ADC_SMPR1(sConfig->SamplingTime, sConfig->Channel) ); // 设置对应通道的采样时间
  }
  else /* 对于通道 0 到 9 */
  {
    /* 修改SMPR2寄存器，配置通道0-9的采样时间 */
    MODIFY_REG(hadc->Instance->SMPR2                             ,
               ADC_SMPR2(ADC_SMPR2_SMP0, sConfig->Channel)       ,  // 清除对应通道的采样时间位
               ADC_SMPR2(sConfig->SamplingTime, sConfig->Channel) ); // 设置对应通道的采样时间
  }
  
  /* 如果选择了ADC1的通道16或通道17，则使能温度传感器和内部参考电压测量路径 */
  if ((sConfig->Channel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfig->Channel == ADC_CHANNEL_VREFINT)      )
  {
    /* 对于具有多个ADC的STM32F1设备：只有ADC1能访问内部测量通道(VrefInt/TempSensor)。
       如果试图在其他ADC实例上设置这些通道，则报告错误。 */
    if (hadc->Instance == ADC1)
    {
      /* 检查TSVREFE位是否已置位，避免重复配置 */
      if (READ_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE) == RESET)
      {
        /* 使能温度传感器和VREFINT通道 */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
        
        /* 如果是温度传感器通道，需要等待其稳定 */
        if (sConfig->Channel == ADC_CHANNEL_TEMPSENSOR)
        {
          /* 延时等待温度传感器稳定时间 */
          /* 计算需要等待的CPU时钟周期数 */
          wait_loop_index = (ADC_TEMPSENSOR_DELAY_US * (SystemCoreClock / 1000000U));
          while(wait_loop_index != 0U)
          {
            wait_loop_index--;
          }
        }
      }
    }
    else
    {
      /* 如果不是ADC1，则更新ADC状态机为配置错误 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      /* 返回错误状态 */
      tmp_hal_status = HAL_ERROR;
    }
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  配置模拟看门狗
  * @note   模拟看门狗阈值可以在ADC转换进行时修改。
  *         在这种情况下，必须考虑到一些限制：
  *         编程的阈值将在下一个ADC EOC(单元转换结束)后生效。
  *         考虑到由于总线活动可能发生寄存器写入延迟，这可能会导致新编程阈值值的实际定时存在不确定性。
  * @param  hadc: ADC句柄指针
  * @param  AnalogWDGConfig: ADC模拟看门狗配置结构体指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig)
{
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance)); // 检查ADC实例是否有效
  assert_param(IS_ADC_ANALOG_WATCHDOG_MODE(AnalogWDGConfig->WatchdogMode)); // 检查看门狗模式
  assert_param(IS_FUNCTIONAL_STATE(AnalogWDGConfig->ITMode)); // 检查中断模式使能状态
  assert_param(IS_ADC_RANGE(AnalogWDGConfig->HighThreshold)); // 检查高阈值是否在有效范围
  assert_param(IS_ADC_RANGE(AnalogWDGConfig->LowThreshold)); // 检查低阈值是否在有效范围
  
  /* 如果看门狗模式配置为单通道模式(常规或注入或两者)，则需要检查通道号 */
  if((AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REG)     ||
     (AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_INJEC)   ||
     (AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)  )
  {
    assert_param(IS_ADC_CHANNEL(AnalogWDGConfig->Channel));
  }
  
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
  /* 模拟看门狗配置 */

  /* 配置ADC模拟看门狗中断 */
  if(AnalogWDGConfig->ITMode == ENABLE)
  {
    /* 使能ADC模拟看门狗中断 */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_AWD);
  }
  else
  {
    /* 禁用ADC模拟看门狗中断 */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IT_AWD);
  }
  
  /* 模拟看门狗的配置：                                        */
  /*  - 设置模拟看门狗使能模式：常规组和/或注入组，单通道或所有通道  */
  /*  - 设置模拟看门狗通道 (如果模式为"所有通道": ADC_CFGR_AWD1SGL=0，则不使用此设置) */
  MODIFY_REG(hadc->Instance->CR1            , // 修改CR1寄存器
             ADC_CR1_AWDSGL | // 单通道看门狗选择位
             ADC_CR1_JAWDEN | // 注入组看门狗使能位
             ADC_CR1_AWDEN  | // 常规组看门狗使能位
             ADC_CR1_AWDCH  , // 看门狗通道选择位
             AnalogWDGConfig->WatchdogMode | // 设置看门狗模式
             AnalogWDGConfig->Channel        ); // 设置看门狗监控的通道
  
  /* 设置高阈值 */
  WRITE_REG(hadc->Instance->HTR, AnalogWDGConfig->HighThreshold);
  
  /* 设置低阈值 */
  WRITE_REG(hadc->Instance->LTR, AnalogWDGConfig->LowThreshold);

  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return HAL_OK;
}


/**
  * @}
  */


/** @defgroup ADC_Exported_Functions_Group4 Peripheral State functions
  * @brief    外设状态函数
  *
@verbatim
 ===============================================================================
            ##### 外设状态和错误函数 #####
 ===============================================================================  
    [..]
    本小节提供在运行时获取外设状态的函数。
      (+) 检查ADC状态
      (+) 检查ADC错误代码

@endverbatim
  * @{
  */

/**
  * @brief  返回ADC状态
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
uint32_t HAL_ADC_GetState(ADC_HandleTypeDef* hadc)
{
  /* 返回ADC状态 */
  return hadc->State;
}

/**
  * @brief  返回ADC错误代码
  * @param  hadc: ADC句柄指针
  * @retval ADC错误代码
  */
uint32_t HAL_ADC_GetError(ADC_HandleTypeDef *hadc)
{
  return hadc->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */

/**
  * @brief  使能选定的ADC
  * @note   使用此函数的前提条件：ADC必须处于禁用状态，且稳压器必须已使能(在HAL_ADC_Init()中完成)。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U; // 用于超时计时的变量
  __IO uint32_t wait_loop_index = 0U; // 用于延时循环的变量
  
  /* ADC使能并等待ADC就绪(如果ADC处于禁用状态或使能阶段尚未完成：就绪标志尚未置位) */
  /* 实施超时机制以避免在ADC无法使能时卡死(可能原因：ADC时钟未运行等) */
  if (ADC_IS_ENABLE(hadc) == RESET)
  {
    /* 使能外设 */
    __HAL_ADC_ENABLE(hadc);
    
    /* 延时等待ADC稳定时间 */
    /* 计算需要等待的CPU时钟周期数 */
    wait_loop_index = (ADC_STAB_DELAY_US * (SystemCoreClock / 1000000U));
    while(wait_loop_index != 0U)
    {
      wait_loop_index--;
    }
    
    /* 获取当前滴答数 */
    tickstart = HAL_GetTick();

    /* 等待ADC有效使能 */
    while(ADC_IS_ENABLE(hadc) == RESET)
    {
      /* 检查是否超时 */
      if((HAL_GetTick() - tickstart) > ADC_ENABLE_TIMEOUT)
      {
        /* 新的检查以避免在发生抢占时出现错误的超时检测 */
        if(ADC_IS_ENABLE(hadc) == RESET)
        {
          /* 更新ADC状态机为内部错误 */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* 设置ADC错误代码为ADC IP内部错误 */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          /* 解锁进程 */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR;
        }
      }
    }
  }
   
  /* 返回HAL状态 */
  return HAL_OK;
}

/**
  * @brief  停止ADC转换并禁用选定的ADC
  * @note   使用此函数的前提条件：必须停止ADC转换才能禁用ADC。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U; // 用于超时计时的变量
  
  /* 验证ADC是否尚未禁用 */
  if (ADC_IS_ENABLE(hadc) != RESET)
  {
    /* 禁用ADC外设 */
    __HAL_ADC_DISABLE(hadc);
     
    /* 获取当前滴答数 */
    tickstart = HAL_GetTick();
    
    /* 等待ADC有效禁用 */
    while(ADC_IS_ENABLE(hadc) != RESET)
    {
      /* 检查是否超时 */
      if((HAL_GetTick() - tickstart) > ADC_DISABLE_TIMEOUT)
      {
        /* 新的检查以避免在发生抢占时出现错误的超时检测 */
        if(ADC_IS_ENABLE(hadc) != RESET)
        {
          /* 更新ADC状态机为内部错误 */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* 设置ADC错误代码为ADC IP内部错误 */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          return HAL_ERROR;
        }
      }
    }
  }
  
  /* 返回HAL状态 */
  return HAL_OK;
}

/**
  * @brief  DMA传输完成回调函数
  * @param  hdma: 指向DMA句柄的指针
  * @retval 无
  */
void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* 获取当前DMA句柄对应的ADC句柄 */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
 
  /* 如果未处于错误状态，则更新转换状态的状态机 */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL | HAL_ADC_STATE_ERROR_DMA))
  {
    /* 更新ADC状态机：常规组转换结束 */
    SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
    
    /* 确定是否还有即将进行的常规组转换(通过外部触发、连续模式或正在进行的扫描序列) */
    /* 注意：在STM32F1设备上，如果排序器使能(选择了多个排名)，转换结束标志在序列结束时置起 */
    if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&  // 如果是软件触发
       (hadc->Init.ContinuousConvMode == DISABLE)   )  // 且非连续转换模式
    {
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
  }
  else
  {
    /* 调用DMA错误回调函数 */
    hadc->DMA_Handle->XferErrorCallback(hdma);
  }
}

/**
  * @brief  DMA半传输完成回调函数
  * @param  hdma: 指向DMA句柄的指针
  * @retval 无
  */
void ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma)   
{
  /* 获取当前DMA句柄对应的ADC句柄 */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  
  /* 半转换回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvHalfCpltCallback(hadc);
#else
  HAL_ADC_ConvHalfCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA错误回调函数
  * @param  hdma: 指向DMA句柄的指针
  * @retval 无
  */
void ADC_DMAError(DMA_HandleTypeDef *hdma)   
{
  /* 获取当前DMA句柄对应的ADC句柄 */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  
  /* 设置ADC状态：DMA错误 */
  SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
  
  /* 设置ADC错误代码为DMA错误 */
  SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);
  
  /* 错误回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  hadc->ErrorCallback(hadc);
#else
  HAL_ADC_ErrorCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @}
  */

#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
