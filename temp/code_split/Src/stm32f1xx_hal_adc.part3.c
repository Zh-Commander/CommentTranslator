
/**
  * @brief  Stop ADC conversion of regular group (and injected group in 
  *         case of auto_injection mode), disable interrution of 
  *         end-of-conversion, disable ADC peripheral.
  * @param  hadc: ADC handle
  * @retval None
  */
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc)
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
    /* Disable ADC end of conversion interrupt for regular group */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC);
    
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
  * @brief  Enables ADC, starts conversion of regular group and transfers result
  *         through DMA.
  *         Interruptions enabled in this function:
  *          - DMA transfer complete
  *          - DMA half transfer
  *         Each of these interruptions has its dedicated callback function.
  * @note   For devices with several ADCs: This function is for single-ADC mode 
  *         only. For multimode, use the dedicated MultimodeStart function.
  * @note   On STM32F1 devices, only ADC1 and ADC3 (ADC availability depending
  *         on devices) have DMA capability.
  *         ADC2 converted data can be transferred in dual ADC mode using DMA
  *         of ADC1 (ADC master in multimode).
  *         In case of using ADC1 with DMA on a device featuring 2 ADC
  *         instances: ADC1 conversion register DR contains ADC1 conversion 
  *         result (ADC1 register DR bits 0 to 11) and, additionally, ADC2 last
  *         conversion result (ADC1 register DR bits 16 to 27). Therefore, to
  *         have DMA transferring the conversion results of ADC1 only, DMA must
  *         be configured to transfer size: half word.
  * @param  hadc: ADC handle
  * @param  pData: The destination Buffer address.
  * @param  Length: The length of data to be transferred from ADC peripheral to memory.
  * @retval None
  */
HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_DMA_CAPABILITY_INSTANCE(hadc->Instance));
    
  /* Verification if multimode is disabled (for devices with several ADC)     */
  /* If multimode is enabled, dedicated function multimode conversion         */
  /* start DMA must be used.                                                  */
  if(ADC_MULTIMODE_IS_ENABLE(hadc) == RESET)
  {
    /* Process locked */
    __HAL_LOCK(hadc);
    
    /* Enable the ADC peripheral */
    tmp_hal_status = ADC_Enable(hadc);
    
    /* Start conversion if ADC is effectively enabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state                                                        */
      /* - Clear state bitfield related to regular group conversion results   */
      /* - Set state bitfield related to regular operation                    */
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
      /* Unlock before starting ADC conversions: in case of potential         */
      /* interruption, to let the process to ADC IRQ Handler.                 */
      __HAL_UNLOCK(hadc);
      
      /* Set the DMA transfer complete callback */
      hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;

      /* Set the DMA half transfer complete callback */
      hadc->DMA_Handle->XferHalfCpltCallback = ADC_DMAHalfConvCplt;
      
      /* Set the DMA error callback */
      hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;

      
      /* Manage ADC and DMA start: ADC overrun interruption, DMA start, ADC   */
      /* start (in case of SW start):                                         */
      
      /* Clear regular group conversion flag and overrun flag */
      /* (To ensure of no unknown state from potential previous ADC           */
      /* operations)                                                          */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
      
      /* Enable ADC DMA mode */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
      
      /* Start the DMA channel */
      HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);
      
      /* Enable conversion of regular group.                                  */
      /* If software start has been selected, conversion starts immediately.  */
      /* If external trigger has been selected, conversion will start at next */
      /* trigger event.                                                       */
      if (ADC_IS_SOFTWARE_START_REGULAR(hadc))
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
  }
  else
  {
    tmp_hal_status = HAL_ERROR;
  }
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected group in 
  *         case of auto_injection mode), disable ADC DMA transfer, disable 
  *         ADC peripheral.
  * @note:  ADC peripheral disable is forcing stop of potential 
  *         conversion on injected group. If injected group is under use, it
  *         should be preliminarily stopped using HAL_ADCEx_InjectedStop function.
  * @note   For devices with several ADCs: This function is for single-ADC mode 
  *         only. For multimode, use the dedicated MultimodeStop function.
  * @note   On STM32F1 devices, only ADC1 and ADC3 (ADC availability depending
  *         on devices) have DMA capability.
  * @param  hadc: ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_DMA_CAPABILITY_INSTANCE(hadc->Instance));
     
  /* Process locked */
  __HAL_LOCK(hadc);
  
  /* Stop potential conversion on going, on regular and injected groups */
  /* Disable ADC peripheral */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* Check if ADC is effectively disabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Disable ADC DMA mode */
    CLEAR_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* Disable the DMA channel (in case of DMA in circular mode or stop while */
    /* DMA transfer is on going)                                              */
    if (hadc->DMA_Handle->State == HAL_DMA_STATE_BUSY)
    {
      tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);
      
      /* Check if DMA channel effectively disabled */
      if (tmp_hal_status == HAL_OK)
      {
        /* Set ADC state */
        ADC_STATE_CLR_SET(hadc->State,
                          HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                          HAL_ADC_STATE_READY);
      }
      else
      {
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
      }
    }
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
    
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Get ADC regular group conversion result.
  * @note   Reading register DR automatically clears ADC flag EOC
  *         (ADC group regular end of unitary conversion).
  * @note   This function does not clear ADC flag EOS 
  *         (ADC group regular end of sequence conversion).
  *         Occurrence of flag EOS rising:
  *          - If sequencer is composed of 1 rank, flag EOS is equivalent
  *            to flag EOC.
  *          - If sequencer is composed of several ranks, during the scan
  *            sequence flag EOC only is raised, at the end of the scan sequence
  *            both flags EOC and EOS are raised.
  *         To clear this flag, either use function: 
  *         in programming model IT: @ref HAL_ADC_IRQHandler(), in programming
  *         model polling: @ref HAL_ADC_PollForConversion() 
  *         or @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOS).
  * @param  hadc: ADC handle
  * @retval ADC group regular conversion data
  */
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef* hadc)
{
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Note: EOC flag is not cleared here by software because automatically     */
  /*       cleared by hardware when reading register DR.                      */
  
  /* Return ADC converted value */ 
  return hadc->Instance->DR;
}

/**
  * @brief  Handles ADC interrupt request  
  * @param  hadc: ADC handle
  * @retval None
  */
void HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc)
{
  uint32_t tmp_sr = hadc->Instance->SR;
  uint32_t tmp_cr1 = hadc->Instance->CR1;

  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  assert_param(IS_ADC_REGULAR_NB_CONV(hadc->Init.NbrOfConversion));
  
  
  /* ========== Check End of Conversion flag for regular group ========== */
  if((tmp_cr1 & ADC_IT_EOC) == ADC_IT_EOC)
  {
    if((tmp_sr & ADC_FLAG_EOC) == ADC_FLAG_EOC)
    {
      /* Update state machine on conversion status if not in error state */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL))
      {
        /* Set ADC state */
        SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC); 
      }
      
      /* Determine whether any further conversion upcoming on group regular   */
      /* by external trigger, continuous mode or scan sequence on going.      */
      /* Note: On STM32F1 devices, in case of sequencer enabled               */
      /*       (several ranks selected), end of conversion flag is raised     */
      /*       at the end of the sequence.                                    */
      if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        && 
         (hadc->Init.ContinuousConvMode == DISABLE)   )
      {
        /* Disable ADC end of conversion interrupt on group regular */
        __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC);
        
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
      
      /* Clear regular group conversion flag */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT | ADC_FLAG_EOC);
    }
  }
  
  /* ========== Check End of Conversion flag for injected group ========== */
  if((tmp_cr1 & ADC_IT_JEOC) == ADC_IT_JEOC)
  {
    if((tmp_sr & ADC_FLAG_JEOC) == ADC_FLAG_JEOC)
    {
      /* Update state machine on conversion status if not in error state */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL))
      {
        /* Set ADC state */
        SET_BIT(hadc->State, HAL_ADC_STATE_INJ_EOC);
      }

      /* Determine whether any further conversion upcoming on group injected  */
      /* by external trigger, scan sequence on going or by automatic injected */
      /* conversion from group regular (same conditions as group regular      */
      /* interruption disabling above).                                       */
      /* Note: On STM32F1 devices, in case of sequencer enabled               */
      /*       (several ranks selected), end of conversion flag is raised     */
      /*       at the end of the sequence.                                    */
      if(ADC_IS_SOFTWARE_START_INJECTED(hadc)                     || 
         (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO) &&     
         (ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&
          (hadc->Init.ContinuousConvMode == DISABLE)   )        )   )
      {
        /* Disable ADC end of conversion interrupt on group injected */
        __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
        
        /* Set ADC state */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_INJ_BUSY);   

        if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
        { 
          SET_BIT(hadc->State, HAL_ADC_STATE_READY);
        }
      }

      /* Conversion complete callback */ 
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->InjectedConvCpltCallback(hadc);
#else
      HAL_ADCEx_InjectedConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* Clear injected group conversion flag */
      __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_JSTRT | ADC_FLAG_JEOC));
    }
  }
   
  /* ========== Check Analog watchdog flags ========== */
  if((tmp_cr1 & ADC_IT_AWD) == ADC_IT_AWD)
  {
    if((tmp_sr & ADC_FLAG_AWD) == ADC_FLAG_AWD)
    {
      /* Set ADC state */
      SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);
      
      /* Level out of window callback */ 
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->LevelOutOfWindowCallback(hadc);
#else
      HAL_ADC_LevelOutOfWindowCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* Clear the ADC analog watchdog flag */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD);
    }
  }
  
}

/**
  * @brief  Conversion complete callback in non blocking mode 
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvCpltCallback must be implemented in the user file.
   */
}

/**
  * @brief  Conversion DMA half-transfer callback in non blocking mode 
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ConvHalfCpltCallback must be implemented in the user file.
  */
}

/**
  * @brief  Analog watchdog callback in non blocking mode. 
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_LevelOutOfWindowCallback must be implemented in the user file.
  */
}

/**
  * @brief  ADC error callback in non blocking mode
  *        (ADC conversion with interruption or transfer by DMA)
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_ErrorCallback must be implemented in the user file.
  */
}


/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group3 Peripheral Control functions
 *  @brief    Peripheral Control functions
 *
@verbatim   
 ===============================================================================
             ##### Peripheral Control functions #####
 ===============================================================================  
    [..]  This section provides functions allowing to:
      (+) Configure channels on regular group
      (+) Configure the analog watchdog
      
@endverbatim
  * @{
  */

/**
  * @brief  Configures the the selected channel to be linked to the regular
  *         group.
  * @note   In case of usage of internal measurement channels:
  *         Vbat/VrefInt/TempSensor.
  *         These internal paths can be be disabled using function 
  *         HAL_ADC_DeInit().
  * @note   Possibility to update parameters on the fly:
  *         This function initializes channel into regular group, following  
  *         calls to this function can be used to reconfigure some parameters 
  *         of structure "ADC_ChannelConfTypeDef" on the fly, without resetting 
  *         the ADC.
  *         The setting of these parameters is conditioned to ADC state.
  *         For parameters constraints, see comments of structure 
  *         "ADC_ChannelConfTypeDef".
  * @param  hadc: ADC handle
  * @param  sConfig: Structure of ADC channel for regular group.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig)
{ 
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  __IO uint32_t wait_loop_index = 0U;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_CHANNEL(sConfig->Channel));
  assert_param(IS_ADC_REGULAR_RANK(sConfig->Rank));
  assert_param(IS_ADC_SAMPLE_TIME(sConfig->SamplingTime));
  
  /* Process locked */
  __HAL_LOCK(hadc);
  
