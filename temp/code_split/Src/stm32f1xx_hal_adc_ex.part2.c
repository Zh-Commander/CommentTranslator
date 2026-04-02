  
  /* Configuration of injected group sequencer:                               */
  /* - if scan mode is disabled, injected channels sequence length is set to  */
  /*   0x00: 1 channel converted (channel on regular rank 1)                  */
  /*   Parameter "InjectedNbrOfConversion" is discarded.                      */
  /*   Note: Scan mode is present by hardware on this device and, if          */
  /*   disabled, discards automatically nb of conversions. Anyway, nb of      */
  /*   conversions is forced to 0x00 for alignment over all STM32 devices.    */
  /* - if scan mode is enabled, injected channels sequence length is set to   */
  /*   parameter "InjectedNbrOfConversion".                                   */
  if (hadc->Init.ScanConvMode == ADC_SCAN_DISABLE)
  {
    if (sConfigInjected->InjectedRank == ADC_INJECTED_RANK_1)
    {
      /* Clear the old SQx bits for all injected ranks */
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
    /* If another injected rank than rank1 was intended to be set, and could  */
    /* not due to ScanConvMode disabled, error is reported.                   */
    else
    {
      /* Update ADC state machine to error */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      tmp_hal_status = HAL_ERROR;
    }
  }
  else
  {
    /* Since injected channels rank conv. order depends on total number of   */
    /* injected conversions, selected rank must be below or equal to total   */
    /* number of injected conversions to be updated.                         */
    if (sConfigInjected->InjectedRank <= sConfigInjected->InjectedNbrOfConversion)
    {
      /* Clear the old SQx bits for the selected rank */
      /* Set the SQx bits for the selected rank */
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
      /* Clear the old SQx bits for the selected rank */
      MODIFY_REG(hadc->Instance->JSQR                                       ,
                 
                 ADC_JSQR_JL                                               |
                 ADC_JSQR_RK_JL(ADC_JSQR_JSQ1,                         
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion) ,
                 
                 0x00000000U);
    }
  } 
    
  /* Configuration of injected group                                          */
  /* Parameters update conditioned to ADC state:                              */
  /* Parameters that can be updated only when ADC is disabled:                */
  /*  - external trigger to start conversion                                  */
  /* Parameters update not conditioned to ADC state:                          */
  /*  - Automatic injected conversion                                         */
  /*  - Injected discontinuous mode                                           */
  /* Note: In case of ADC already enabled, caution to not launch an unwanted  */
  /*       conversion while modifying register CR2 by writing 1 to bit ADON.  */
  if (ADC_IS_ENABLE(hadc) == RESET)
  {    
    MODIFY_REG(hadc->Instance->CR2                                           ,
               ADC_CR2_JEXTSEL |
               ADC_CR2_ADON                                                  ,
               ADC_CFGR_JEXTSEL(hadc, sConfigInjected->ExternalTrigInjecConv) );
  }
  
  
  /* Configuration of injected group                                          */
  /*  - Automatic injected conversion                                         */
  /*  - Injected discontinuous mode                                           */
  
    /* Automatic injected conversion can be enabled if injected group         */
    /* external triggers are disabled.                                        */
    if (sConfigInjected->AutoInjectedConv == ENABLE)
    {
      if (sConfigInjected->ExternalTrigInjecConv == ADC_INJECTED_SOFTWARE_START)
      {
        SET_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO);
      }
      else
      {
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        tmp_hal_status = HAL_ERROR;
      }
    }
    
    /* Injected discontinuous can be enabled only if auto-injected mode is    */
    /* disabled.                                                              */  
    if (sConfigInjected->InjectedDiscontinuousConvMode == ENABLE)
    {
      if (sConfigInjected->AutoInjectedConv == DISABLE)
      {
        SET_BIT(hadc->Instance->CR1, ADC_CR1_JDISCEN);
      } 
      else
      {
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        tmp_hal_status = HAL_ERROR;
      }
    }


  /* InjectedChannel sampling time configuration */
  /* For channels 10 to 17 */
  if (sConfigInjected->InjectedChannel >= ADC_CHANNEL_10)
  {
    MODIFY_REG(hadc->Instance->SMPR1                                                             ,
               ADC_SMPR1(ADC_SMPR1_SMP10, sConfigInjected->InjectedChannel)                      ,
               ADC_SMPR1(sConfigInjected->InjectedSamplingTime, sConfigInjected->InjectedChannel) );
  }
  else /* For channels 0 to 9 */
  {
    MODIFY_REG(hadc->Instance->SMPR2                                                             ,
               ADC_SMPR2(ADC_SMPR2_SMP0, sConfigInjected->InjectedChannel)                       ,
               ADC_SMPR2(sConfigInjected->InjectedSamplingTime, sConfigInjected->InjectedChannel) );
  }
  
  /* If ADC1 InjectedChannel_16 or InjectedChannel_17 is selected, enable Temperature sensor  */
  /* and VREFINT measurement path.                                            */
  if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfigInjected->InjectedChannel == ADC_CHANNEL_VREFINT)      )
  {
    SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
  }
  
  
  /* Configure the offset: offset enable/disable, InjectedChannel, offset value */
  switch(sConfigInjected->InjectedRank)
  {
    case 1:
      /* Set injected channel 1 offset */
      MODIFY_REG(hadc->Instance->JOFR1,
                 ADC_JOFR1_JOFFSET1,
                 sConfigInjected->InjectedOffset);
      break;
    case 2:
      /* Set injected channel 2 offset */
      MODIFY_REG(hadc->Instance->JOFR2,
                 ADC_JOFR2_JOFFSET2,
                 sConfigInjected->InjectedOffset);
      break;
    case 3:
      /* Set injected channel 3 offset */
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
  
  /* If ADC1 Channel_16 or Channel_17 is selected, enable Temperature sensor  */
  /* and VREFINT measurement path.                                            */
  if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfigInjected->InjectedChannel == ADC_CHANNEL_VREFINT)      )
  {
    /* For STM32F1 devices with several ADC: Only ADC1 can access internal    */
    /* measurement channels (VrefInt/TempSensor). If these channels are       */
    /* intended to be set on other ADC instances, an error is reported.       */
    if (hadc->Instance == ADC1)
    {
      if (READ_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE) == RESET)
      {
        SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
        
        if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR))
        {
          /* Delay for temperature sensor stabilization time */
          /* Compute number of CPU cycles to wait for */
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
      /* Update ADC state machine to error */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      tmp_hal_status = HAL_ERROR;
    }
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return tmp_hal_status;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  Enable ADC multimode and configure multimode parameters
  * @note   Possibility to update parameters on the fly:
  *         This function initializes multimode parameters, following  
  *         calls to this function can be used to reconfigure some parameters 
  *         of structure "ADC_MultiModeTypeDef" on the fly, without resetting 
  *         the ADCs (both ADCs of the common group).
  *         The setting of these parameters is conditioned to ADC state.
  *         For parameters constraints, see comments of structure 
  *         "ADC_MultiModeTypeDef".
  * @note   To change back configuration from multimode to single mode, ADC must
  *         be reset (using function HAL_ADC_Init() ).
  * @param  hadc: ADC handle
  * @param  multimode: Structure of ADC multimode configuration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef* hadc, ADC_MultiModeTypeDef* multimode)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};
  
  /* Check the parameters */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_MODE(multimode->Mode));
  
  /* Process locked */
  __HAL_LOCK(hadc);
  
  /* Set a temporary handle of the ADC slave associated to the ADC master     */
  ADC_MULTI_SLAVE(hadc, &tmphadcSlave);
  
  /* Parameters update conditioned to ADC state:                              */
  /* Parameters that can be updated when ADC is disabled or enabled without   */
  /* conversion on going on regular group:                                    */
  /*  - ADC master and ADC slave DMA configuration                            */
  /* Parameters that can be updated only when ADC is disabled:                */
  /*  - Multimode mode selection                                              */
  /* To optimize code, all multimode settings can be set when both ADCs of    */
  /* the common group are in state: disabled.                                 */
  if ((ADC_IS_ENABLE(hadc) == RESET)                     &&
      (ADC_IS_ENABLE(&tmphadcSlave) == RESET)            &&
      (IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance))   )
  {
    MODIFY_REG(hadc->Instance->CR1,
               ADC_CR1_DUALMOD    ,
               multimode->Mode     );
  }
  /* If one of the ADC sharing the same common group is enabled, no update    */
  /* could be done on neither of the multimode structure parameters.          */
  else
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    tmp_hal_status = HAL_ERROR;
  }
    
    
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
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
