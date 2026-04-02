case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        // 注册注入组转换完成回调函数，指向默认的弱定义函数
        hadc->InjectedConvCpltCallback = HAL_ADCEx_InjectedConvCpltCallback;
        break;
      
      case HAL_ADC_MSPINIT_CB_ID :
        // 注册MSP初始化回调函数，指向默认的弱定义函数
        hadc->MspInitCallback = HAL_ADC_MspInit;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        // 注册MSP反初始化回调函数，指向默认的弱定义函数
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;
        break;
      
      default :
        // 更新错误码，标记为无效的回调ID
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
        
        // 返回错误状态
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    // 如果ADC处于复位状态，处理相关的回调注册
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        // 注册MSP初始化回调函数
        hadc->MspInitCallback = HAL_ADC_MspInit;
        break;
        
      case HAL_ADC_MSPDEINIT_CB_ID :
        // 注册MSP反初始化回调函数
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;
        break;
        
      default :
        // 更新错误码，标记为无效的回调ID
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
        
        // 返回错误状态
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    // 如果ADC状态既不是就绪也不是复位，则更新错误码
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
    
    // 返回错误状态
    status =  HAL_ERROR;
  }
  
  return status;
}

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group2 IO operation functions
 *  @brief    Input and Output operation functions
 *
@verbatim   
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Start conversion of regular group.
      (+) Stop conversion of regular group.
      (+) Poll for conversion complete on regular group.
      (+) Poll for conversion event.
      (+) Get result of regular channel conversion.
      (+) Start conversion of regular group and enable interruptions.
      (+) Stop conversion of regular group and disable interruptions.
      (+) Handle ADC interrupt request
      (+) Start conversion of regular group and enable DMA transfer.
      (+) Stop conversion of regular group and disable ADC DMA transfer.
@endverbatim
  * @{
  */

/**
  * @brief  Enables ADC, starts conversion of regular group.
  *         Interruptions enabled in this function: None.
  * @param  hadc: ADC handle
  * @retval HAL status
  */
// 函数功能: 使能ADC，启动常规组转换。注意：此函数不开启任何中断。
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  // 检查参数有效性，确认ADC实例是否合法
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  // 锁定进程，防止多线程冲突
  __HAL_LOCK(hadc);
   
  // 使能ADC外设
  tmp_hal_status = ADC_Enable(hadc);
  
  // 如果ADC成功使能，则启动转换
  if (tmp_hal_status == HAL_OK)
  {
    // 设置ADC状态
    // - 清除与常规组转换结果相关的状态位
    // - 设置与常规操作相关的状态位
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC,
                      HAL_ADC_STATE_REG_BUSY);
    
    // 设置注入组状态（针对自动注入模式）和多模式状态
    // 适用于多模式的所有情况：独立模式、多模式ADC主设备或多模式ADC从设备
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      // 设置ADC状态（独立模式或主模式）
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组（自动注入模式），则更新ADC状态
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      // 设置ADC状态（从模式）
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组（自动注入模式），则更新ADC状态
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
    
    // 状态机更新: 检查是否有注入转换正在进行
    if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    {
      // 仅清除与常规组转换相关的ADC错误码字段
      CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
    }
    else
    {
      // 清除所有ADC错误码字段
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    // 解锁进程
    // 在启动ADC转换之前解锁，以便在发生中断时允许ADC IRQ Handler处理
    __HAL_UNLOCK(hadc);
  
    // 清除常规组转换标志
    // 确保不会因为之前潜在的ADC操作而处于未知状态
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    // 使能常规组转换
    // 如果选择了软件启动，转换立即开始
    // 如果选择了外部触发，转换将在下一个触发事件开始
    // 多模式使能的情况:
    //  - 如果是从ADC，仅使能ADC（不启动转换）
    //  - 如果是主ADC，使能ADC并启动转换
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc)      &&
        ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
    {
      // 通过软件启动ADC常规组转换
      // 设置SWSTART位和EXTTRIG位
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      // 通过外部触发启动ADC常规组转换
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    // 如果ADC使能失败，解锁进程
    __HAL_UNLOCK(hadc);
  }
    
  // 返回函数执行状态
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected channels in 
  *         case of auto_injection mode), disable ADC peripheral.
  * @note:  ADC peripheral disable is forcing stop of potential 
  *         conversion on injected group. If injected group is under use, it
  *         should be preliminarily stopped using HAL_ADCEx_InjectedStop function.
  * @param  hadc: ADC handle
  * @retval HAL status.
  */
// 函数功能: 停止ADC常规组转换（如果是自动注入模式，也包括注入通道），并关闭ADC外设。
// 注意: 关闭ADC外设会强制停止注入组正在进行的转换。如果正在使用注入组，应先调用HAL_ADCEx_InjectedStop停止。
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
     
  // 锁定进程
  __HAL_LOCK(hadc);
  
  // 停止常规组和注入组正在进行的转换，并关闭ADC外设
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  // 检查ADC是否成功关闭
  if (tmp_hal_status == HAL_OK)
  {
    // 设置ADC状态为就绪
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  // 解锁进程
  __HAL_UNLOCK(hadc);
  
  // 返回函数执行状态
  return tmp_hal_status;
}

/**
  * @brief  Wait for regular group conversion to be completed.
  * @note   This function cannot be used in a particular setup: ADC configured 
  *         in DMA mode.
  *         In this case, DMA resets the flag EOC and polling cannot be
  *         performed on each conversion.
  * @note   On STM32F1 devices, limitation in case of sequencer enabled
  *         (several ranks selected): polling cannot be done on each 
  *         conversion inside the sequence. In this case, polling is replaced by
  *         wait for maximum conversion time.
  * @param  hadc: ADC handle
  * @param  Timeout: Timeout value in millisecond.
  * @retval HAL status
  */
// 函数功能: 等待常规组转换完成（轮询模式）。
// 注意: 此函数不能用于配置了DMA模式的ADC，因为DMA会清除EOC标志。
// 注意: 在STM32F1系列中，如果启用了扫描模式（多个通道），无法对每个转换进行轮询，
// 此时通过等待最大转换时间来替代。
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout)
{
  uint32_t tickstart = 0U;
  
  // 用于扫描模式轮询的变量
  __IO uint32_t Conversion_Timeout_CPU_cycles = 0U;
  uint32_t Conversion_Timeout_CPU_cycles_max = 0U;
 
  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  // 获取当前滴答计时器值，用于超时计算
  tickstart = HAL_GetTick();
  
  // 验证ADC配置是否支持轮询模式
  // 特殊情况：如果ADC配置为DMA模式
  if (HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_DMA))
  {
    // 更新ADC状态机为配置错误
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    // 解锁进程
    __HAL_UNLOCK(hadc);
    
    return HAL_ERROR;
  }
  
  // 轮询转换结束标志：区分单次转换和序列转换
  // - 如果是常规组单次转换（扫描模式禁用或转换数为1），使用EOC标志判断转换完成
  // - 如果是常规组序列转换（扫描模式使能且转换数>=2），EOC标志仅在序列结束时置位
  //   为了轮询每次转换，需要计算最大转换时间
  if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_SCAN) &&
      HAL_IS_BIT_CLR(hadc->Instance->SQR1, ADC_SQR1_L)    )
  {
    // 等待转换结束标志(EOC)被置位
    while(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_EOC))
    {
      // 检查是否超时（如果不设置为无限等待）
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
        {
          // 再次检查以避免抢占导致的误判超时
          if(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_EOC))
          {
            // 更新ADC状态机为超时
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);
            
            // 解锁进程
            __HAL_UNLOCK(hadc);
            
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  else
  {
    // 对于扫描模式序列转换，使用等待最大转换时间替代轮询EOC标志
    // 计算对应ADC时钟周期和所有通道最大转换周期的CPU时钟周期数
    Conversion_Timeout_CPU_cycles_max = ((SystemCoreClock
                                          / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                                         * ADC_CONVCYCLES_MAX_RANGE(hadc)                 );
    
    // 循环等待计算出的CPU周期数
    while(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
    {
      // 检查是否超时
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
        {
          // 再次检查以避免误判
          if(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
          {
            // 更新ADC状态机为超时
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            // 解锁进程
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT;
          }
        }
      }
      Conversion_Timeout_CPU_cycles ++;
    }
  }
  
  // 清除常规组转换标志（开始标志和转换结束标志）
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT | ADC_FLAG_EOC);
  
  // 更新ADC状态机，设置常规组转换结束标志
  SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
  
  // 判断是否还有后续转换（通过外部触发、连续模式或扫描序列）
  // 注意: 在STM32F1上，如果使能了扫描模式，转换结束标志在序列结束时产生
  if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        && 
     (hadc->Init.ContinuousConvMode == DISABLE)   )
  {   
    // 如果是软件启动且非连续转换模式，则认为转换已完成，清除忙状态
    CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);   

    // 如果注入组也不忙，则设置ADC为就绪状态
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    { 
      SET_BIT(hadc->State, HAL_ADC_STATE_READY);
    }
  }
  
  // 返回ADC状态
  return HAL_OK;
}

/**
  * @brief  Poll for conversion event.
  * @param  hadc: ADC handle
  * @param  EventType: the ADC event type.
  *          This parameter can be one of the following values:
  *            @arg ADC_AWD_EVENT: ADC Analog watchdog event.
  * @param  Timeout: Timeout value in millisecond.
  * @retval HAL status
  */
// 函数功能: 轮询转换事件。
// 参数 EventType: ADC事件类型，例如 ADC_AWD_EVENT (模拟看门狗事件)。
HAL_StatusTypeDef HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout)
{
  uint32_t tickstart = 0U; 

  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_EVENT_TYPE(EventType));
  
  // 获取当前滴答计时器值
  tickstart = HAL_GetTick();
  
  // 检查选定的事件标志
  while(__HAL_ADC_GET_FLAG(hadc, EventType) == RESET)
  {
    // 检查是否超时
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
      {
        // 再次检查以避免误判
        if(__HAL_ADC_GET_FLAG(hadc, EventType) == RESET)
        {
          // 更新ADC状态机为超时
          SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

          // 解锁进程
          __HAL_UNLOCK(hadc);

          return HAL_TIMEOUT;
        }
      }
    }
  }
  
  // 模拟看门狗事件（超出窗口范围）
  // 设置ADC状态
  SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);
    
  // 清除模拟看门狗标志
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD);
  
  // 返回ADC状态
  return HAL_OK;
}

/**
  * @brief  Enables ADC, starts conversion of regular group with interruption.
  *         Interruptions enabled in this function:
  *          - EOC (end of conversion of regular group)
  *         Each of these interruptions has its dedicated callback function.
  * @param  hadc: ADC handle
  * @retval HAL status
  */
// 函数功能: 使能ADC，启动常规组转换并开启中断。
// 此函数开启的中断：EOC (常规组转换结束中断)。
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  // 锁定进程
  __HAL_LOCK(hadc);
    
  // 使能ADC外设
  tmp_hal_status = ADC_Enable(hadc);
  
  // 如果ADC成功使能，则启动转换
  if (tmp_hal_status == HAL_OK)
  {
    // 设置ADC状态
    // - 清除与常规组转换结果相关的状态位
    // - 设置与常规操作相关的状态位
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_OVR | HAL_ADC_STATE_REG_EOSMP,
                      HAL_ADC_STATE_REG_BUSY);
    
    // 设置注入组状态（针对自动注入模式）和多模式状态
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      // 设置ADC状态（独立模式或主模式）
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组，更新ADC状态
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      // 设置ADC状态（从模式）
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组，更新ADC状态
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
    
    // 状态机更新: 检查是否有注入转换正在进行
    if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    {
      // 仅清除与常规组转换相关的ADC错误码字段
      CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
    }
    else
    {
      // 清除所有ADC错误码字段
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    // 解锁进程
    // 在启动ADC转换之前解锁，以便在发生中断时允许ADC IRQ Handler处理
    __HAL_UNLOCK(hadc);
    
    // 清除常规组转换标志和溢出标志
    // 确保不会因为之前潜在的ADC操作而处于未知状态
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    // 使能常规组转换结束中断(EOC)
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_EOC);
    
    // 使能常规组转换
    // 如果选择了软件启动，转换立即开始
    // 如果选择了外部触发，转换将在下一个触发事件开始
    // 多模式使能的情况:
    //  - 如果是从ADC，仅使能ADC（不启动转换）
    //  - 如果是主ADC，使能ADC并启动转换
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc)      &&
        ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
    {
      // 通过软件启动ADC常规组转换
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      // 通过外部触发启动ADC常规组转换
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    // 如果ADC使能失败，解锁进程
    __HAL_UNLOCK(hadc);
  }
  
  // 返回函数执行状态
  return tmp_hal_status;
}
