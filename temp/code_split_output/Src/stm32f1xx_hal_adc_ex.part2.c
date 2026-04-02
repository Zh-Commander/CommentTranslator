/* 注入组序列器配置： */
  /* - 如果扫描模式被禁用，注入通道序列长度被设置为 */
  /*   0x00：转换1个通道（常规序列排名1的通道） */
  /*   参数 "InjectedNbrOfConversion" 被忽略。 */
  /*   注意：此设备的硬件存在扫描模式，如果禁用，则自动丢弃转换数量。 */
  /*   无论如何，为了在所有STM32设备上保持一致，转换数量强制为0x00。 */
  /* - 如果扫描模式被启用，注入通道序列长度被设置为 */
  /*   参数 "InjectedNbrOfConversion"。 */
  if (hadc->Init.ScanConvMode == ADC_SCAN_DISABLE)
  {
    if (sConfigInjected->InjectedRank == ADC_INJECTED_RANK_1)
    {
      /* 清除所有注入排名的旧SQx位 */
      MODIFY_REG(hadc->Instance->JSQR                             ,
                 ADC_JSQR_JL   |
                 ADC_JSQR_JSQ4 |
                 ADC_JSQR_JSQ3 |
                 ADC_JSQR_JSQ2 |
                 ADC_JSQR_JSQ1                                    ,
                 ADC_JSQR_RK_JL(sConfigInjected->InjectedChannel,
                                  ADC_INJECTED_RANK_1,
                                  0x01U));
    }
    /* 如果试图设置除排名1以外的注入排名，由于扫描模式被禁用而无法设置，则报告错误。 */
    else
    {
      /* 更新ADC状态机为错误状态 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      tmp_hal_status = HAL_ERROR;
    }
  }
  else
  {
    /* 由于注入通道排名的转换顺序取决于注入转换的总数， */
    /* 所选排名必须小于或等于注入转换总数才能进行更新。 */
    if (sConfigInjected->InjectedRank <= sConfigInjected->InjectedNbrOfConversion)
    {
      /* 清除所选排名的旧SQx位 */
      /* 设置所选排名的SQx位 */
      MODIFY_REG(hadc->Instance->JSQR                                         ,
                 
                 ADC_JSQR_JL                                               |
                 ADC_JSQR_RK_JL(ADC_JSQR_JSQ1,                         
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion)   ,
                 
                 ADC_JSQR_JL_SHIFT(sConfigInjected->InjectedNbrOfConversion) |
                 ADC_JSQR_RK_JL(sConfigInjected->InjectedChannel,      
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion)    );
    }
    else
    {
      /* 清除所选排名的旧SQx位 */
      MODIFY_REG(hadc->Instance->JSQR                                       ,
                 
                 ADC_JSQR_JL                                               |
                 ADC_JSQR_RK_JL(ADC_JSQR_JSQ1,                         
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion) ,
                 
                 0x00000000U);
    }
  } 
    
  /* 注入组配置 */
  /* 参数更新取决于ADC状态： */
  /* 只有当ADC被禁用时才能更新的参数： */
  /*  - 外部触发启动转换 */
  /* 更新不取决于ADC状态的参数： */
  /*  - 自动注入转换 */
  /*  - 注入不连续模式 */
  /* 注意：如果ADC已经启用，在修改寄存器CR2时通过写入1到ADON位要小心不要启动意外的转换。 */
  if (ADC_IS_ENABLE(hadc) == RESET)
  {    
    MODIFY_REG(hadc->Instance->CR2                                           ,
               ADC_CR2_JEXTSEL |
               ADC_CR2_ADON                                                  ,
               ADC_CFGR_JEXTSEL(hadc, sConfigInjected->ExternalTrigInjecConv) );
  }
  
  
  /* 注入组配置 */
  /*  - 自动注入转换 */
  /*  - 注入不连续模式 */
  
    /* 如果注入组外部触发被禁用，则可以启用自动注入转换。 */
    if (sConfigInjected->AutoInjectedConv == ENABLE)
    {
      if (sConfigInjected->ExternalTrigInjecConv == ADC_INJECTED_SOFTWARE_START)
      {
        SET_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO);
      }
      else
      {
        /* 更新ADC状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        tmp_hal_status = HAL_ERROR;
      }
    }
    
    /* 只有当自动注入模式被禁用时，才能启用注入不连续模式。 */  
    if (sConfigInjected->InjectedDiscontinuousConvMode == ENABLE)
    {
      if (sConfigInjected->AutoInjectedConv == DISABLE)
      {
        SET_BIT(hadc->Instance->CR1, ADC_CR1_JDISCEN);
      } 
      else
      {
        /* 更新ADC状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        tmp_hal_status = HAL_ERROR;
      }
    }


  /* 注入通道采样时间配置 */
  /* 对于通道10到17 */
  if (sConfigInjected->InjectedChannel >= ADC_CHANNEL_10)
  {
    MODIFY_REG(hadc->Instance->SMPR1                                                             ,
               ADC_SMPR1(ADC_SMPR1_SMP10, sConfigInjected->InjectedChannel)                      ,
               ADC_SMPR1(sConfigInjected->InjectedSamplingTime, sConfigInjected->InjectedChannel) );
  }
  else /* 对于通道0到9 */
  {
    MODIFY_REG(hadc->Instance->SMPR2                                                             ,
               ADC_SMPR2(ADC_SMPR2_SMP0, sConfigInjected->InjectedChannel)                       ,
               ADC_SMPR2(sConfigInjected->InjectedSamplingTime, sConfigInjected->InjectedChannel) );
  }
  
  /* 如果选择了ADC1的注入通道16或注入通道17，则使能温度传感器 */
  /* 和内部参考电压测量路径。 */
  if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfigInjected->InjectedChannel == ADC_CHANNEL_VREFINT)      )
  {
    SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
  }
  
  
  /* 配置偏移量：偏移量使能/禁用，注入通道，偏移值 */
  switch(sConfigInjected->InjectedRank)
  {
    case 1:
      /* 设置注入通道1偏移量 */
      MODIFY_REG(hadc->Instance->JOFR1,
                 ADC_JOFR1_JOFFSET1,
                 sConfigInjected->InjectedOffset);
      break;
    case 2:
      /* 设置注入通道2偏移量 */
      MODIFY_REG(hadc->Instance->JOFR2,
                 ADC_JOFR2_JOFFSET2,
                 sConfigInjected->InjectedOffset);
      break;
    case 3:
      /* 设置注入通道3偏移量 */
      MODIFY_REG(hadc->Instance->JOFR3,
                 ADC_JOFR3_JOFFSET3,
                 sConfigInjected->InjectedOffset);
      break;
    case 4:
    default:
      MODIFY_REG(hadc->Instance->JOFR4,
                 ADC_JOFR4_JOFFSET4,
                 sConfigInjected->InjectedOffset);
      break;
  }
  
  /* 如果选择了ADC1的通道16或通道17，则使能温度传感器 */
  /* 和内部参考电压测量路径。 */
  if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfigInjected->InjectedChannel == ADC_CHANNEL_VREFINT)      )
  {
    /* 对于具有多个ADC的STM32F1设备：只有ADC1能访问内部 */
    /* 测量通道（VrefInt/TempSensor）。如果这些通道 */
    /* 试图在其他ADC实例上设置，则报告错误。 */
    if (hadc->Instance == ADC1)
    {
      if (READ_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE) == RESET)
      {
        SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
        
        if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR))
        {
          /* 温度传感器稳定时间的延时 */
          /* 计算需要等待的CPU周期数 */
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
      /* 更新ADC状态机为错误状态 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      tmp_hal_status = HAL_ERROR;
    }
  }
  
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  使能ADC多模模式并配置多模参数
  * @note   可以动态更新参数：
  *         此函数初始化多模参数，随后的调用可用于动态重新配置 
  *         结构体 "ADC_MultiModeTypeDef" 的某些参数，而无需复位 
  *         ADC（公共组的两个ADC）。
  *         这些参数的设置取决于ADC状态。
  *         关于参数约束，请参阅结构体 "ADC_MultiModeTypeDef" 的注释。
  * @note   要将配置从多模改回单模，必须复位ADC（使用函数 HAL_ADC_Init() ）。
  * @param  hadc: ADC句柄
  * @param  multimode: ADC多模配置结构体
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef* hadc, ADC_MultiModeTypeDef* multimode)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};
  
  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_MODE(multimode->Mode));
  
  /* 进程锁 */
  __HAL_LOCK(hadc);
  
  /* 设置与ADC主机关联的ADC从机的临时句柄 */
  ADC_MULTI_SLAVE(hadc, &tmphadcSlave);
  
  /* 参数更新取决于ADC状态： */
  /* 当ADC被禁用或启用但常规组没有正在进行的转换时可以更新的参数： */
  /*  - ADC主机和ADC从机DMA配置 */
  /* 只有当ADC被禁用时才能更新的参数： */
  /*  - 多模模式选择 */
  /* 为了优化代码，当公共组的两个ADC都处于禁用状态时， */
  /* 可以设置所有多模设置。 */
  if ((ADC_IS_ENABLE(hadc) == RESET)                     &&
      (ADC_IS_ENABLE(&tmphadcSlave) == RESET)            &&
      (IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance))   )
  {
    MODIFY_REG(hadc->Instance->CR1,
               ADC_CR1_DUALMOD    ,
               multimode->Mode     );
  }
  /* 如果共享同一公共组的一个ADC被启用，则无法更新 */
  /* 任何多模结构参数。 */
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
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */
/**
  * @}
  */  

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
