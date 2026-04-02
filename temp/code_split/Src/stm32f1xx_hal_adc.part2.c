      
      case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        hadc->InjectedConvCpltCallback = HAL_ADCEx_InjectedConvCpltCallback;
        break;
      
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit; /* Legacy weak MspInit              */
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit; /* Legacy weak MspDeInit            */
        break;
      
      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
        
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = HAL_ADC_MspInit;                   /* Legacy weak MspInit              */
        break;
        
      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;               /* Legacy weak MspDeInit            */
        break;
        
      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
        
        /* Return error status */
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
    
    /* Return error status */
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
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Process locked */
  __HAL_LOCK(hadc);
   
  /* Enable the ADC peripheral */
  tmp_hal_status = ADC_Enable(hadc);
  
  /* Start conversion if ADC is effectively enabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Set ADC state                                                          */
    /* - Clear state bitfield related to regular group conversion results     */
    /* - Set state bitfield related to regular operation                      */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC,
                      HAL_ADC_STATE_REG_BUSY);
    
    /* Set group injected state (from auto-injection) and multimode state     */
    /* for all cases of multimode: independent mode, multimode ADC master     */
    /* or multimode ADC slave (for devices with several ADCs):                */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      /* Set ADC state (ADC independent or master) */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* If conversions on group regular are also triggering group injected,  */
      /* update ADC state.                                                    */
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      /* Set ADC state (ADC slave) */
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* If conversions on group regular are also triggering group injected,  */
      /* update ADC state.                                                    */
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
    
    /* State machine update: Check if an injected conversion is ongoing */
    if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    {
      /* Reset ADC error code fields related to conversions on group regular */
      CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
    }
    else
    {
      /* Reset ADC all error code fields */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* Process unlocked */
    /* Unlock before starting ADC conversions: in case of potential           */
    /* interruption, to let the process to ADC IRQ Handler.                   */
    __HAL_UNLOCK(hadc);
  
    /* Clear regular group conversion flag */
    /* (To ensure of no unknown state from potential previous ADC operations) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    /* Enable conversion of regular group.                                    */
    /* If software start has been selected, conversion starts immediately.    */
    /* If external trigger has been selected, conversion will start at next   */
    /* trigger event.                                                         */
    /* Case of multimode enabled:                                             */ 
    /*  - if ADC is slave, ADC is enabled only (conversion is not started).   */
    /*  - if ADC is master, ADC is enabled and conversion is started.         */
    /* If ADC is master, ADC is enabled and conversion is started.            */
    /* Note: Alternate trigger for single conversion could be to force an     */
    /*       additional set of bit ADON "hadc->Instance->CR2 |= ADC_CR2_ADON;"*/
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc)      &&
        ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
    {
      /* Start ADC conversion on regular group with SW start */
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      /* Start ADC conversion on regular group with external trigger */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    /* Process unlocked */
    __HAL_UNLOCK(hadc);
  }
    
  /* Return function status */
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
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
     
  /* Process locked */
  __HAL_LOCK(hadc);
  
  /* Stop potential conversion on going, on regular and injected groups */
  /* Disable ADC peripheral */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* Check if ADC is effectively disabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Set ADC state */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
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
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout)
{
  uint32_t tickstart = 0U;
  
  /* Variables for polling in case of scan mode enabled and polling for each  */
  /* conversion.                                                              */
  __IO uint32_t Conversion_Timeout_CPU_cycles = 0U;
  uint32_t Conversion_Timeout_CPU_cycles_max = 0U;
 
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Get tick count */
  tickstart = HAL_GetTick();
  
  /* Verification that ADC configuration is compliant with polling for        */
  /* each conversion:                                                         */
  /* Particular case is ADC configured in DMA mode                            */
  if (HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_DMA))
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    /* Process unlocked */
    __HAL_UNLOCK(hadc);
    
    return HAL_ERROR;
  }
  
  /* Polling for end of conversion: differentiation if single/sequence        */
  /* conversion.                                                              */
  /*  - If single conversion for regular group (Scan mode disabled or enabled */
  /*    with NbrOfConversion =1), flag EOC is used to determine the           */
  /*    conversion completion.                                                */
  /*  - If sequence conversion for regular group (scan mode enabled and       */
  /*    NbrOfConversion >=2), flag EOC is set only at the end of the          */
  /*    sequence.                                                             */
  /*    To poll for each conversion, the maximum conversion time is computed  */
  /*    from ADC conversion time (selected sampling time + conversion time of */
  /*    12.5 ADC clock cycles) and APB2/ADC clock prescalers (depending on    */
  /*    settings, conversion time range can be from 28 to 32256 CPU cycles).  */
  /*    As flag EOC is not set after each conversion, no timeout status can   */
  /*    be set.                                                               */
  if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_SCAN) &&
      HAL_IS_BIT_CLR(hadc->Instance->SQR1, ADC_SQR1_L)    )
  {
    /* Wait until End of Conversion flag is raised */
    while(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_EOC))
    {
      /* Check if timeout is disabled (set to infinite wait) */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
        {
          /* New check to avoid false timeout detection in case of preemption */
          if(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_EOC))
          {
            /* Update ADC state machine to timeout */
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);
            
            /* Process unlocked */
            __HAL_UNLOCK(hadc);
            
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  else
  {
    /* Replace polling by wait for maximum conversion time */
    /*  - Computation of CPU clock cycles corresponding to ADC clock cycles   */
    /*    and ADC maximum conversion cycles on all channels.                  */
    /*  - Wait for the expected ADC clock cycles delay                        */
    Conversion_Timeout_CPU_cycles_max = ((SystemCoreClock
                                          / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                                         * ADC_CONVCYCLES_MAX_RANGE(hadc)                 );
    
    while(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
    {
      /* Check if timeout is disabled (set to infinite wait) */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
        {
          /* New check to avoid false timeout detection in case of preemption */
          if(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
          {
            /* Update ADC state machine to timeout */
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            /* Process unlocked */
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT;
          }
        }
      }
      Conversion_Timeout_CPU_cycles ++;
    }
  }
  
  /* Clear regular group conversion flag */
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT | ADC_FLAG_EOC);
  
  /* Update ADC state machine */
  SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
  
  /* Determine whether any further conversion upcoming on group regular       */
  /* by external trigger, continuous mode or scan sequence on going.          */
  /* Note: On STM32F1 devices, in case of sequencer enabled                   */
  /*       (several ranks selected), end of conversion flag is raised         */
  /*       at the end of the sequence.                                        */
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
  
  /* Return ADC state */
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
HAL_StatusTypeDef HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout)
{
  uint32_t tickstart = 0U; 

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_EVENT_TYPE(EventType));
  
  /* Get tick count */
  tickstart = HAL_GetTick();
  
  /* Check selected event flag */
  while(__HAL_ADC_GET_FLAG(hadc, EventType) == RESET)
  {
    /* Check if timeout is disabled (set to infinite wait) */
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
      {
        /* New check to avoid false timeout detection in case of preemption */
        if(__HAL_ADC_GET_FLAG(hadc, EventType) == RESET)
        {
          /* Update ADC state machine to timeout */
          SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

          /* Process unlocked */
          __HAL_UNLOCK(hadc);

          return HAL_TIMEOUT;
        }
      }
    }
  }
  
  /* Analog watchdog (level out of window) event */
  /* Set ADC state */
  SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);
    
  /* Clear ADC analog watchdog flag */
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD);
  
  /* Return ADC state */
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
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Process locked */
  __HAL_LOCK(hadc);
    
  /* Enable the ADC peripheral */
  tmp_hal_status = ADC_Enable(hadc);
  
  /* Start conversion if ADC is effectively enabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Set ADC state                                                          */
    /* - Clear state bitfield related to regular group conversion results     */
    /* - Set state bitfield related to regular operation                      */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_OVR | HAL_ADC_STATE_REG_EOSMP,
                      HAL_ADC_STATE_REG_BUSY);
    
    /* Set group injected state (from auto-injection) and multimode state     */
    /* for all cases of multimode: independent mode, multimode ADC master     */
    /* or multimode ADC slave (for devices with several ADCs):                */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      /* Set ADC state (ADC independent or master) */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* If conversions on group regular are also triggering group injected,  */
      /* update ADC state.                                                    */
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      /* Set ADC state (ADC slave) */
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* If conversions on group regular are also triggering group injected,  */
      /* update ADC state.                                                    */
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
    
    /* State machine update: Check if an injected conversion is ongoing */
    if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    {
      /* Reset ADC error code fields related to conversions on group regular */
      CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
    }
    else
    {
      /* Reset ADC all error code fields */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* Process unlocked */
    /* Unlock before starting ADC conversions: in case of potential           */
    /* interruption, to let the process to ADC IRQ Handler.                   */
    __HAL_UNLOCK(hadc);
    
    /* Clear regular group conversion flag and overrun flag */
    /* (To ensure of no unknown state from potential previous ADC operations) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    /* Enable end of conversion interrupt for regular group */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_EOC);
    
    /* Enable conversion of regular group.                                    */
    /* If software start has been selected, conversion starts immediately.    */
    /* If external trigger has been selected, conversion will start at next   */
    /* trigger event.                                                         */
    /* Case of multimode enabled:                                             */ 
    /*  - if ADC is slave, ADC is enabled only (conversion is not started).   */
    /*  - if ADC is master, ADC is enabled and conversion is started.         */
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc)      &&
        ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
    {
      /* Start ADC conversion on regular group with SW start */
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      /* Start ADC conversion on regular group with external trigger */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    /* Process unlocked */
    __HAL_UNLOCK(hadc);
  }
  
  /* Return function status */
  return tmp_hal_status;
}
