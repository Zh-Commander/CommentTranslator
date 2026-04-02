  
  /* Regular sequence configuration */
  /* For Rank 1 to 6 */
  if (sConfig->Rank < 7U)
  {
    MODIFY_REG(hadc->Instance->SQR3                        ,
               ADC_SQR3_RK(ADC_SQR3_SQ1, sConfig->Rank)    ,
               ADC_SQR3_RK(sConfig->Channel, sConfig->Rank) );
  }
  /* For Rank 7 to 12 */
  else if (sConfig->Rank < 13U)
  {
    MODIFY_REG(hadc->Instance->SQR2                        ,
               ADC_SQR2_RK(ADC_SQR2_SQ7, sConfig->Rank)    ,
               ADC_SQR2_RK(sConfig->Channel, sConfig->Rank) );
  }
  /* For Rank 13 to 16 */
  else
  {
    MODIFY_REG(hadc->Instance->SQR1                        ,
               ADC_SQR1_RK(ADC_SQR1_SQ13, sConfig->Rank)   ,
               ADC_SQR1_RK(sConfig->Channel, sConfig->Rank) );
  }
  
  
  /* Channel sampling time configuration */
  /* For channels 10 to 17 */
  if (sConfig->Channel >= ADC_CHANNEL_10)
  {
    MODIFY_REG(hadc->Instance->SMPR1                             ,
               ADC_SMPR1(ADC_SMPR1_SMP10, sConfig->Channel)      ,
               ADC_SMPR1(sConfig->SamplingTime, sConfig->Channel) );
  }
  else /* For channels 0 to 9 */
  {
    MODIFY_REG(hadc->Instance->SMPR2                             ,
               ADC_SMPR2(ADC_SMPR2_SMP0, sConfig->Channel)       ,
               ADC_SMPR2(sConfig->SamplingTime, sConfig->Channel) );
  }
  
  /* If ADC1 Channel_16 or Channel_17 is selected, enable Temperature sensor  */
  /* and VREFINT measurement path.                                            */
  if ((sConfig->Channel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfig->Channel == ADC_CHANNEL_VREFINT)      )
  {
    /* For STM32F1 devices with several ADC: Only ADC1 can access internal    */
    /* measurement channels (VrefInt/TempSensor). If these channels are       */
    /* intended to be set on other ADC instances, an error is reported.       */
    if (hadc->Instance == ADC1)
    {
      if (READ_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE) == RESET)
      {
        SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
        
        if (sConfig->Channel == ADC_CHANNEL_TEMPSENSOR)
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

/**
  * @brief  Configures the analog watchdog.
  * @note   Analog watchdog thresholds can be modified while ADC conversion
  *         is on going.
  *         In this case, some constraints must be taken into account:
  *         the programmed threshold values are effective from the next
  *         ADC EOC (end of unitary conversion).
  *         Considering that registers write delay may happen due to
  *         bus activity, this might cause an uncertainty on the
  *         effective timing of the new programmed threshold values.
  * @param  hadc: ADC handle
  * @param  AnalogWDGConfig: Structure of ADC analog watchdog configuration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_ANALOG_WATCHDOG_MODE(AnalogWDGConfig->WatchdogMode));
  assert_param(IS_FUNCTIONAL_STATE(AnalogWDGConfig->ITMode));
  assert_param(IS_ADC_RANGE(AnalogWDGConfig->HighThreshold));
  assert_param(IS_ADC_RANGE(AnalogWDGConfig->LowThreshold));
  
  if((AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REG)     ||
     (AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_INJEC)   ||
     (AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)  )
  {
    assert_param(IS_ADC_CHANNEL(AnalogWDGConfig->Channel));
  }
  
  /* Process locked */
  __HAL_LOCK(hadc);
  
  /* Analog watchdog configuration */

  /* Configure ADC Analog watchdog interrupt */
  if(AnalogWDGConfig->ITMode == ENABLE)
  {
    /* Enable the ADC Analog watchdog interrupt */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_AWD);
  }
  else
  {
    /* Disable the ADC Analog watchdog interrupt */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IT_AWD);
  }
  
  /* Configuration of analog watchdog:                                        */
  /*  - Set the analog watchdog enable mode: regular and/or injected groups,  */
  /*    one or all channels.                                                  */
  /*  - Set the Analog watchdog channel (is not used if watchdog              */
  /*    mode "all channels": ADC_CFGR_AWD1SGL=0).                             */
  MODIFY_REG(hadc->Instance->CR1            ,
             ADC_CR1_AWDSGL |
             ADC_CR1_JAWDEN |
             ADC_CR1_AWDEN  |
             ADC_CR1_AWDCH                  ,
             AnalogWDGConfig->WatchdogMode |
             AnalogWDGConfig->Channel        );
  
  /* Set the high threshold */
  WRITE_REG(hadc->Instance->HTR, AnalogWDGConfig->HighThreshold);
  
  /* Set the low threshold */
  WRITE_REG(hadc->Instance->LTR, AnalogWDGConfig->LowThreshold);

  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return HAL_OK;
}


/**
  * @}
  */


/** @defgroup ADC_Exported_Functions_Group4 Peripheral State functions
 *  @brief    Peripheral State functions
 *
@verbatim
 ===============================================================================
            ##### Peripheral State and Errors functions #####
 ===============================================================================  
    [..]
    This subsection provides functions to get in run-time the status of the  
    peripheral.
      (+) Check the ADC state
      (+) Check the ADC error code

@endverbatim
  * @{
  */

/**
  * @brief  return the ADC state
  * @param  hadc: ADC handle
  * @retval HAL state
  */
uint32_t HAL_ADC_GetState(ADC_HandleTypeDef* hadc)
{
  /* Return ADC state */
  return hadc->State;
}

/**
  * @brief  Return the ADC error code
  * @param  hadc: ADC handle
  * @retval ADC Error Code
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
  * @brief  Enable the selected ADC.
  * @note   Prerequisite condition to use this function: ADC must be disabled
  *         and voltage regulator must be enabled (done into HAL_ADC_Init()).
  * @param  hadc: ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U;
  __IO uint32_t wait_loop_index = 0U;
  
  /* ADC enable and wait for ADC ready (in case of ADC is disabled or         */
  /* enabling phase not yet completed: flag ADC ready not yet set).           */
  /* Timeout implemented to not be stuck if ADC cannot be enabled (possible   */
  /* causes: ADC clock not running, ...).                                     */
  if (ADC_IS_ENABLE(hadc) == RESET)
  {
    /* Enable the Peripheral */
    __HAL_ADC_ENABLE(hadc);
    
    /* Delay for ADC stabilization time */
    /* Compute number of CPU cycles to wait for */
    wait_loop_index = (ADC_STAB_DELAY_US * (SystemCoreClock / 1000000U));
    while(wait_loop_index != 0U)
    {
      wait_loop_index--;
    }
    
    /* Get tick count */
    tickstart = HAL_GetTick();

    /* Wait for ADC effectively enabled */
    while(ADC_IS_ENABLE(hadc) == RESET)
    {
      if((HAL_GetTick() - tickstart) > ADC_ENABLE_TIMEOUT)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if(ADC_IS_ENABLE(hadc) == RESET)
        {
          /* Update ADC state machine to error */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* Set ADC error code to ADC IP internal error */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          /* Process unlocked */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR;
        }
      }
    }
  }
   
  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  Stop ADC conversion and disable the selected ADC
  * @note   Prerequisite condition to use this function: ADC conversions must be
  *         stopped to disable the ADC.
  * @param  hadc: ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U;
  
  /* Verification if ADC is not already disabled */
  if (ADC_IS_ENABLE(hadc) != RESET)
  {
    /* Disable the ADC peripheral */
    __HAL_ADC_DISABLE(hadc);
     
    /* Get tick count */
    tickstart = HAL_GetTick();
    
    /* Wait for ADC effectively disabled */
    while(ADC_IS_ENABLE(hadc) != RESET)
    {
      if((HAL_GetTick() - tickstart) > ADC_DISABLE_TIMEOUT)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if(ADC_IS_ENABLE(hadc) != RESET)
        {
          /* Update ADC state machine to error */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* Set ADC error code to ADC IP internal error */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          return HAL_ERROR;
        }
      }
    }
  }
  
  /* Return HAL status */
  return HAL_OK;
}

/**
  * @brief  DMA transfer complete callback. 
  * @param  hdma: pointer to DMA handle.
  * @retval None
  */
void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
 
  /* Update state machine on conversion status if not in error state */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL | HAL_ADC_STATE_ERROR_DMA))
  {
    /* Update ADC state machine */
    SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
    
    /* Determine whether any further conversion upcoming on group regular     */
    /* by external trigger, continuous mode or scan sequence on going.        */
    /* Note: On STM32F1 devices, in case of sequencer enabled                 */
    /*       (several ranks selected), end of conversion flag is raised       */
    /*       at the end of the sequence.                                      */
    if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        && 
       (hadc->Init.ContinuousConvMode == DISABLE)   )
    {
      /* Set ADC state */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);   
      
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_INJ_BUSY))
      {
        SET_BIT(hadc->State, HAL_ADC_STATE_READY);
      }
    }
    
    /* Conversion complete callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvCpltCallback(hadc);
#else
    HAL_ADC_ConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }
  else
  {
    /* Call DMA error callback */
    hadc->DMA_Handle->XferErrorCallback(hdma);
  }
}

/**
  * @brief  DMA half transfer complete callback. 
  * @param  hdma: pointer to DMA handle.
  * @retval None
  */
void ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma)   
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  
  /* Half conversion callback */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvHalfCpltCallback(hadc);
#else
  HAL_ADC_ConvHalfCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA error callback 
  * @param  hdma: pointer to DMA handle.
  * @retval None
  */
void ADC_DMAError(DMA_HandleTypeDef *hdma)   
{
  /* Retrieve ADC handle corresponding to current DMA handle */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  
  /* Set ADC state */
  SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
  
  /* Set ADC error code to DMA error */
  SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);
  
  /* Error callback */
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
