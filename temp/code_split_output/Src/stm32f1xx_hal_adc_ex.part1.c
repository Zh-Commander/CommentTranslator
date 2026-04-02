/* 如果ADC有效启用，则开始转换 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 设置ADC状态 */
    /* - 清除与注入组转换结果相关的状态位 */
    /* - 设置与注入操作相关的状态位 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_INJ_EOC,
                      HAL_ADC_STATE_INJ_BUSY);
    
    /* 独立模式或多重模式（适用于具有多个ADC的设备）的情况： */
    /* 设置多重模式状态。 */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      // 清除多重模式从机状态位，当前处于非多重模式或为主机模式
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    else
    {
      // 设置多重模式从机状态位
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    
    /* 检查是否有规则通道转换正在进行 */
    /* 注意：在该设备上，没有仅与注入组转换相关的ADC错误代码字段。 */
    /*       如果规则组上有转换正在进行，则不会重置错误代码。 */
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
    {
      /* 重置ADC所有错误代码字段 */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* 进程解锁 */
    /* 在开始ADC转换之前解锁：以防发生中断，让进程能进入ADC中断处理程序。 */
    __HAL_UNLOCK(hadc);
    
    /* 清除注入组转换标志 */
    /* (确保不会受到之前潜在的ADC操作带来的未知状态影响) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JEOC);
    
    /* 使能注入通道的转换结束中断 */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOC);
    
    /* 如果选择了软件触发启动注入组转换，并且禁止了自动注入转换，则启动注入组转换 */
    /* 如果选择了外部触发，转换将在下一个触发事件开始。 */
    /* 如果使能了自动注入转换，转换将在下一个规则组转换之后开始。 */
    if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO))
    {
      // 判断是否为软件触发且非多模式从机
      if (ADC_IS_SOFTWARE_START_INJECTED(hadc)     &&
          ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
      {
        /* 使用软件启动ADC注入组转换 */
        // 设置软件启动位和外部触发使能位
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
      }
      else
      {
        /* 使用外部触发启动ADC注入组转换 */
        // 仅设置外部触发使能位
        SET_BIT(hadc->Instance->CR2, ADC_CR2_JEXTTRIG);
      }
    }
  }
  else
  {
    /* 进程解锁 */
    __HAL_UNLOCK(hadc);
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止注入通道转换，禁止转换结束中断。
  *         如果没有正在进行的规则转换，则关闭ADC外设。
  * @note   如果需要关闭ADC且规则组正在进行转换，
  *         必须使用 HAL_ADC_Stop 函数来同时停止注入组和规则组，并关闭ADC。
  * @note   如果注入组模式自动注入已使能，
  *         必须使用 HAL_ADC_Stop 函数。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 进程锁定 */
  __HAL_LOCK(hadc);
    
  /* 停止潜在的转换并关闭ADC外设 */
  /* 条件： */
  /* - 另一组（规则组）没有打算继续转换（注入组和规则组停止转换和ADC关闭是共同操作） */
  /* - 在自动注入模式下，必须使用 HAL_ADC_Stop。 */ 
  if(((hadc->State & HAL_ADC_STATE_REG_BUSY) == RESET)  &&
     HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO)   )
  {
    /* 停止正在进行的规则和注入组潜在转换 */
    /* 关闭ADC外设 */
    tmp_hal_status = ADC_ConversionStop_Disable(hadc);
    
    /* 检查ADC是否有效关闭 */
    if (tmp_hal_status == HAL_OK)
    {
      /* 禁止注入通道的转换结束中断 */
      __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
      
      /* 设置ADC状态 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }
  else
  {
    /* 更新ADC状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
    tmp_hal_status = HAL_ERROR;
  }
  
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  使能ADC，启动规则组转换并通过DMA传输结果。
  *         多重模式必须事先使用 HAL_ADCEx_MultiModeConfigChannel() 函数配置。
  *         此函数中使能的中断：
  *          - DMA传输完成
  *          - DMA半传输
  *         每个中断都有其专用的回调函数。
  * @note:  在STM32F1设备上，ADC从机规则组必须配置为转换触发 ADC_SOFTWARE_START。
  * @note:  ADC从机可以预先使用单模式 HAL_ADC_Start() 函数使能。
  * @param  hadc: ADC主机句柄指针（不应使用ADC从机句柄）
  * @param  pData: 目标缓冲区地址。
  * @param  Length: 从ADC外设传输到内存的数据长度。
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};

  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  
  /* 进程锁定 */
  __HAL_LOCK(hadc);

  /* 设置与ADC主机关联的ADC从机的临时句柄 */
  ADC_MULTI_SLAVE(hadc, &tmphadcSlave);
  
  /* 在STM32F1设备上，ADC从机规则组必须配置为转换触发 ADC_SOFTWARE_START。 */
  /* 注意：ADC从机的外部触发必须使能，这已在函数 "HAL_ADC_Init()" 中完成。 */
  if(!ADC_IS_SOFTWARE_START_REGULAR(&tmphadcSlave))  
  {
    /* 更新ADC状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    /* 进程解锁 */
    __HAL_UNLOCK(hadc);
    
    return HAL_ERROR;
  }
  
  /* 使能ADC外设：主机和从机（如果之前尚未使能） */
  tmp_hal_status = ADC_Enable(hadc);
  if (tmp_hal_status == HAL_OK)
  {
    tmp_hal_status = ADC_Enable(&tmphadcSlave);
  }
  
  /* 如果多重模式下的所有ADC都有效使能，则开始转换 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 设置ADC状态（ADC主机） */
    /* - 清除与规则组转换结果相关的状态位 */
    /* - 设置与规则操作相关的状态位 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_MULTIMODE_SLAVE,
                      HAL_ADC_STATE_REG_BUSY);
      
    /* 如果规则组上的转换也触发注入组，更新ADC状态。 */
    if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
    {
      ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
    }
    
    /* 进程解锁 */
    /* 在开始ADC转换之前解锁：以防发生中断，让进程能进入ADC中断处理程序。 */
    __HAL_UNLOCK(hadc);
    
    /* 设置ADC错误代码为无 */
    ADC_CLEAR_ERRORCODE(hadc);
    
    
    /* 设置DMA传输完成回调函数 */
    hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;
       
    /* 设置DMA半传输完成回调函数 */
    hadc->DMA_Handle->XferHalfCpltCallback = ADC_DMAHalfConvCplt;
    
    /* 设置DMA错误回调函数 */
    hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;

    
    /* 管理ADC和DMA启动：ADC溢出中断，DMA启动，ADC启动（如果是软件启动）： */
    
    /* 清除规则组转换标志和溢出标志 */
    /* (确保不会受到之前潜在的ADC操作带来的未知状态影响) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    /* 使能ADC主机的DMA模式 */
    SET_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* 启动DMA通道 */
    HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);
    
    /* 如果选择了软件触发，则启动规则组转换。 */
    /* 如果选择了外部触发，转换将在下一个触发事件开始。 */
    /* 注意：单次转换的替代触发方式可以是强制设置ADON位 "hadc->Instance->CR2 |= ADC_CR2_ADON;"*/
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc))
    {
      /* 使用软件启动ADC规则组转换 */
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      /* 使用外部触发启动ADC规则组转换 */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    /* 进程解锁 */
    __HAL_UNLOCK(hadc);
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止规则组的ADC转换（如果是自动注入模式，也包括注入通道），
  *         禁止ADC DMA传输，关闭ADC外设。
  * @note   此函数后多重模式保持使能。要禁止多重模式
  *         （通过 HAL_ADCEx_MultiModeConfigChannel() 设置），ADC必须
  *         使用 HAL_ADC_Init() 或 HAL_ADC_ReInit() 重新初始化。
  * @note   如果DMA配置为循环模式，在此函数之后必须调用
  *         HAL_ADC_Stop_DMA 并使用ADC从机的句柄，以正确禁止DMA通道。
  * @param  hadc: ADC主机句柄指针（不应使用ADC从机句柄）
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};
  
  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  
  /* 进程锁定 */
  __HAL_LOCK(hadc);

  /* 停止正在进行的规则和注入组潜在转换 */
  /* 关闭ADC主机外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* 检查ADC是否有效关闭 */
  if(tmp_hal_status == HAL_OK)
  {
    /* 设置与ADC主机关联的ADC从机的临时句柄 */
    ADC_MULTI_SLAVE(hadc, &tmphadcSlave);

    /* 关闭ADC从机外设 */
    tmp_hal_status = ADC_ConversionStop_Disable(&tmphadcSlave);

    /* 检查ADC是否有效关闭 */
    if(tmp_hal_status != HAL_OK)
    {
      /* 更新ADC状态机为错误状态 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

      /* 进程解锁 */
      __HAL_UNLOCK(hadc);

      return HAL_ERROR;
    }

    /* 禁止ADC DMA模式 */
    CLEAR_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* 重置双模式下的ADC DMA连续请求配置 */
    CLEAR_BIT(hadc->Instance->CR1, ADC_CR1_DUALMOD);
        
    /* 禁止DMA通道（以防DMA处于循环模式或在DMA传输正在进行时停止） */
    tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);

    /* 更改ADC状态（ADC主机） */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief  获取ADC注入组转换结果。
  * @note   读取寄存器JDRx会自动清除ADC标志JEOC
  *         (ADC注入组单元转换结束)。
  * @note   此函数不清除ADC标志JEOS
  *         (ADC注入组序列转换结束)
  *         标志JEOS上升沿的发生：
  *          - 如果序列器由1个等级组成，标志JEOS等同于
  *            标志JEOC。
  *          - 如果序列器由多个等级组成，在扫描
  *            序列期间仅升起JEOC标志，在扫描序列结束时
  *            JEOC和EOS标志都会升起。
  *         标志JEOS不应由此函数清除，因为
  *         这将不符合低功耗特性
  *         （低功耗自动等待特性，并非所有STM32系列都可用）。
  *         要清除此标志，可以使用以下函数： 
  *         编程模型 IT: @ref HAL_ADC_IRQHandler(), 编程
  *         模型轮询: @ref HAL_ADCEx_InjectedPollForConversion() 
  *         或 @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_JEOS)。
  * @param  hadc: ADC句柄指针
  * @param  InjectedRank: 转换的ADC注入等级。
  *          该参数可以是以下值之一：
  *            @arg ADC_INJECTED_RANK_1: 选择注入通道1
  *            @arg ADC_INJECTED_RANK_2: 选择注入通道2
  *            @arg ADC_INJECTED_RANK_3: 选择注入通道3
  *            @arg ADC_INJECTED_RANK_4: 选择注入通道4
  * @retval ADC注入组转换数据
  */
uint32_t HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank)
{
  uint32_t tmp_jdr = 0U;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_INJECTED_RANK(InjectedRank));
  
  /* 获取ADC转换值 */ 
  switch(InjectedRank)
  {  
    case ADC_INJECTED_RANK_4: 
      // 获取注入组第4个通道的数据
      tmp_jdr = hadc->Instance->JDR4;
      break;
    case ADC_INJECTED_RANK_3: 
      // 获取注入组第3个通道的数据
      tmp_jdr = hadc->Instance->JDR3;
      break;
    case ADC_INJECTED_RANK_2: 
      // 获取注入组第2个通道的数据
      tmp_jdr = hadc->Instance->JDR2;
      break;
    case ADC_INJECTED_RANK_1:
    default:
      // 获取注入组第1个通道的数据
      tmp_jdr = hadc->Instance->JDR1;
      break;
  }
  
  /* 返回ADC转换值 */ 
  return tmp_jdr;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  在选定的多重模式下返回上次ADC主机和从机规则转换结果数据。
  * @param  hadc: ADC主机句柄指针（不应使用ADC从机句柄）
  * @retval 转换的数据值。
  */
uint32_t HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef* hadc)
{
  uint32_t tmpDR = 0U;
  
  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 注意：此处软件不清除EOC标志，因为读取寄存器DR时硬件会自动清除。 */
  
  /* 在STM32F1设备上，ADC1数据寄存器DR仅在ADC1 DMA模式使能时包含ADC2转换结果。 */
  tmpDR = hadc->Instance->DR;

  if (HAL_IS_BIT_CLR(ADC1->CR2, ADC_CR2_DMA))
  {
    // 如果DMA未使能，手动合并ADC2的数据（高16位）
    tmpDR |= (ADC2->DR << 16U);
  }
    
  /* 返回ADC转换值 */ 
  return tmpDR;
}
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief  非阻塞模式下的注入转换完成回调函数 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数编译警告 */
  UNUSED(hadc);
  /* 注意：此函数不应被修改，当需要回调时，
           HAL_ADCEx_InjectedConvCpltCallback 可以在用户文件中实现
  */
}

/**
  * @}
  */

/** @defgroup ADCEx_Exported_Functions_Group2 扩展外设控制函数
  * @brief    扩展外设控制函数
  *
@verbatim   
 ===============================================================================
             ##### 外设控制函数 #####
 ===============================================================================  
    [..]  本节提供允许执行以下操作的函数：
      (+) 配置注入组上的通道
      (+) 配置多重模式

@endverbatim
  * @{
  */

/**
  * @brief  配置ADC注入组以及选定的通道链接到注入组。
  * @note   可以动态更新参数：
  *         此函数初始化注入组，随后调用此函数可用于动态重新配置
  *         结构体 "ADC_InjectionConfTypeDef" 的某些参数，而无需重置ADC。
  *         这些参数的设置取决于ADC状态：
  *         必须在ADC未进行转换时调用此函数。
  * @param  hadc: ADC句柄指针
  * @param  sConfigInjected: ADC注入组和注入组ADC通道的结构体指针。
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc, ADC_InjectionConfTypeDef* sConfigInjected)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  __IO uint32_t wait_loop_index = 0U;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_CHANNEL(sConfigInjected->InjectedChannel)); // 检查注入通道
  assert_param(IS_ADC_SAMPLE_TIME(sConfigInjected->InjectedSamplingTime)); // 检查采样时间
  assert_param(IS_FUNCTIONAL_STATE(sConfigInjected->AutoInjectedConv)); // 检查自动注入转换状态
  assert_param(IS_ADC_EXTTRIGINJEC(sConfigInjected->ExternalTrigInjecConv)); // 检查外部触发注入转换
  assert_param(IS_ADC_RANGE(sConfigInjected->InjectedOffset)); // 检查注入偏移量范围
  
  if(hadc->Init.ScanConvMode != ADC_SCAN_DISABLE)
  {
    assert_param(IS_ADC_INJECTED_RANK(sConfigInjected->InjectedRank)); // 检查注入等级
    assert_param(IS_ADC_INJECTED_NB_CONV(sConfigInjected->InjectedNbrOfConversion)); // 检查注入转换数目
    assert_param(IS_FUNCTIONAL_STATE(sConfigInjected->InjectedDiscontinuousConvMode)); // 检查注入不连续转换模式
  }
  
  /* 进程锁定 */
  __HAL_LOCK(hadc);
