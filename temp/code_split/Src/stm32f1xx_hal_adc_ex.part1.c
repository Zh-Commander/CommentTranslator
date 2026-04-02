  
  /* Start conversion if ADC is effectively enabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Set ADC state                                                          */
    /* - Clear state bitfield related to injected group conversion results    */
    /* - Set state bitfield related to injected operation                     */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_INJ_EOC,
                      HAL_ADC_STATE_INJ_BUSY);
    
    /* Case of independent mode or multimode (for devices with several ADCs): */
    /* Set multimode state.                                                   */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    else
    {
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    
    /* Check if a regular conversion is ongoing */
    /* Note: On this device, there is no ADC error code fields related to     */
    /*       conversions on group injected only. In case of conversion on     */
    /*       going on group regular, no error code is reset.                  */
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
    {
      /* Reset ADC all error code fields */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* Process unlocked */
    /* Unlock before starting ADC conversions: in case of potential           */
    /* interruption, to let the process to ADC IRQ Handler.                   */
    __HAL_UNLOCK(hadc);
    
    /* Clear injected group conversion flag */
    /* (To ensure of no unknown state from potential previous ADC operations) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JEOC);
    
    /* Enable end of conversion interrupt for injected channels */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOC);
    
    /* Start conversion of injected group if software start has been selected */
    /* and if automatic injected conversion is disabled.                      */
    /* If external trigger has been selected, conversion will start at next   */
    /* trigger event.                                                         */
    /* If automatic injected conversion is enabled, conversion will start     */
    /* after next regular group conversion.                                   */
    if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO))
    {
      if (ADC_IS_SOFTWARE_START_INJECTED(hadc)     &&
          ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
      {
        /* Start ADC conversion on injected group with SW start */
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
      }
      else
      {
        /* Start ADC conversion on injected group with external trigger */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_JEXTTRIG);
      }
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
  * @brief  Stop conversion of injected channels, disable interruption of 
  *         end-of-conversion. Disable ADC peripheral if no regular conversion
  *         is on going.
  * @note   If ADC must be disabled and if conversion is on going on 
  *         regular group, function HAL_ADC_Stop must be used to stop both
  *         injected and regular groups, and disable the ADC.
  * @note   If injected group mode auto-injection is enabled,
  *         function HAL_ADC_Stop must be used.
  * @param  hadc: ADC handle
  * @retval None
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Process locked */
  __HAL_LOCK(hadc);
    
  /* Stop potential conversion and disable ADC peripheral                     */
  /* Conditioned to:                                                          */
  /* - No conversion on the other group (regular group) is intended to        */
  /*   continue (injected and regular groups stop conversion and ADC disable  */
  /*   are common)                                                            */
  /* - In case of auto-injection mode, HAL_ADC_Stop must be used.             */ 
  if(((hadc->State & HAL_ADC_STATE_REG_BUSY) == RESET)  &&
     HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO)   )
  {
    /* Stop potential conversion on going, on regular and injected groups */
    /* Disable ADC peripheral */
    tmp_hal_status = ADC_ConversionStop_Disable(hadc);
    
    /* Check if ADC is effectively disabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Disable ADC end of conversion interrupt for injected channels */
      __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
      
      /* Set ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }
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

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  Enables ADC, starts conversion of regular group and transfers result
  *         through DMA.
  *         Multimode must have been previously configured using 
  *         HAL_ADCEx_MultiModeConfigChannel() function.
  *         Interruptions enabled in this function:
  *          - DMA transfer complete
  *          - DMA half transfer
  *         Each of these interruptions has its dedicated callback function.
  * @note:  On STM32F1 devices, ADC slave regular group must be configured 
  *         with conversion trigger ADC_SOFTWARE_START.
  * @note:  ADC slave can be enabled preliminarily using single-mode  
  *         HAL_ADC_Start() function.
  * @param  hadc: ADC handle of ADC master (handle of ADC slave must not be used)
  * @param  pData: The destination Buffer address.
  * @param  Length: The length of data to be transferred from ADC peripheral to memory.
  * @retval None
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};

  /* Check the parameters */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  
  /* Process locked */
  __HAL_LOCK(hadc);

  /* Set a temporary handle of the ADC slave associated to the ADC master     */
  ADC_MULTI_SLAVE(hadc, &tmphadcSlave);
  
  /* On STM32F1 devices, ADC slave regular group must be configured with      */
  /* conversion trigger ADC_SOFTWARE_START.                                   */
  /* Note: External trigger of ADC slave must be enabled, it is already done  */
  /*       into function "HAL_ADC_Init()".                                    */
  if(!ADC_IS_SOFTWARE_START_REGULAR(&tmphadcSlave))  
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    /* Process unlocked */
    __HAL_UNLOCK(hadc);
    
    return HAL_ERROR;
  }
  
  /* Enable the ADC peripherals: master and slave (in case if not already     */
  /* enabled previously)                                                      */
  tmp_hal_status = ADC_Enable(hadc);
  if (tmp_hal_status == HAL_OK)
  {
    tmp_hal_status = ADC_Enable(&tmphadcSlave);
  }
  
  /* Start conversion if all ADCs of multimode are effectively enabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Set ADC state (ADC master)                                             */
    /* - Clear state bitfield related to regular group conversion results     */
    /* - Set state bitfield related to regular operation                      */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_MULTIMODE_SLAVE,
                      HAL_ADC_STATE_REG_BUSY);
      
    /* If conversions on group regular are also triggering group injected,    */
    /* update ADC state.                                                      */
    if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
    {
      ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
    }
    
    /* Process unlocked */
    /* Unlock before starting ADC conversions: in case of potential           */
    /* interruption, to let the process to ADC IRQ Handler.                   */
    __HAL_UNLOCK(hadc);
    
    /* Set ADC error code to none */
    ADC_CLEAR_ERRORCODE(hadc);
    
    
    /* Set the DMA transfer complete callback */
    hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;
       
    /* Set the DMA half transfer complete callback */
    hadc->DMA_Handle->XferHalfCpltCallback = ADC_DMAHalfConvCplt;
    
    /* Set the DMA error callback */
    hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;

    
    /* Manage ADC and DMA start: ADC overrun interruption, DMA start, ADC     */
    /* start (in case of SW start):                                           */
    
    /* Clear regular group conversion flag and overrun flag */
    /* (To ensure of no unknown state from potential previous ADC operations) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    /* Enable ADC DMA mode of ADC master */
    SET_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* Start the DMA channel */
    HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);
    
    /* Start conversion of regular group if software start has been selected. */
    /* If external trigger has been selected, conversion will start at next   */
    /* trigger event.                                                         */
    /* Note: Alternate trigger for single conversion could be to force an     */
    /*       additional set of bit ADON "hadc->Instance->CR2 |= ADC_CR2_ADON;"*/
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
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected channels in 
  *         case of auto_injection mode), disable ADC DMA transfer, disable 
  *         ADC peripheral.
  * @note   Multimode is kept enabled after this function. To disable multimode 
  *         (set with HAL_ADCEx_MultiModeConfigChannel(), ADC must be 
  *         reinitialized using HAL_ADC_Init() or HAL_ADC_ReInit().
  * @note   In case of DMA configured in circular mode, function 
  *         HAL_ADC_Stop_DMA must be called after this function with handle of
  *         ADC slave, to properly disable the DMA channel.
  * @param  hadc: ADC handle of ADC master (handle of ADC slave must not be used)
  * @retval None
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};
  
  /* Check the parameters */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  
  /* Process locked */
  __HAL_LOCK(hadc);

  /* Stop potential conversion on going, on regular and injected groups */
  /* Disable ADC master peripheral */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* Check if ADC is effectively disabled */
  if(tmp_hal_status == HAL_OK)
  {
    /* Set a temporary handle of the ADC slave associated to the ADC master   */
    ADC_MULTI_SLAVE(hadc, &tmphadcSlave);

    /* Disable ADC slave peripheral */
    tmp_hal_status = ADC_ConversionStop_Disable(&tmphadcSlave);

    /* Check if ADC is effectively disabled */
    if(tmp_hal_status != HAL_OK)
    {
      /* Update ADC state machine to error */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

      /* Process unlocked */
      __HAL_UNLOCK(hadc);

      return HAL_ERROR;
    }

    /* Disable ADC DMA mode */
    CLEAR_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* Reset configuration of ADC DMA continuous request for dual mode */
    CLEAR_BIT(hadc->Instance->CR1, ADC_CR1_DUALMOD);
        
    /* Disable the DMA channel (in case of DMA in circular mode or stop while */
    /* while DMA transfer is on going)                                        */
    tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);

    /* Change ADC state (ADC master) */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return tmp_hal_status;
}
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief  Get ADC injected group conversion result.
  * @note   Reading register JDRx automatically clears ADC flag JEOC
  *         (ADC group injected end of unitary conversion).
  * @note   This function does not clear ADC flag JEOS 
  *         (ADC group injected end of sequence conversion)
  *         Occurrence of flag JEOS rising:
  *          - If sequencer is composed of 1 rank, flag JEOS is equivalent
  *            to flag JEOC.
  *          - If sequencer is composed of several ranks, during the scan
  *            sequence flag JEOC only is raised, at the end of the scan sequence
  *            both flags JEOC and EOS are raised.
  *         Flag JEOS must not be cleared by this function because
  *         it would not be compliant with low power features
  *         (feature low power auto-wait, not available on all STM32 families).
  *         To clear this flag, either use function: 
  *         in programming model IT: @ref HAL_ADC_IRQHandler(), in programming
  *         model polling: @ref HAL_ADCEx_InjectedPollForConversion() 
  *         or @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_JEOS).
  * @param  hadc: ADC handle
  * @param  InjectedRank: the converted ADC injected rank.
  *          This parameter can be one of the following values:
  *            @arg ADC_INJECTED_RANK_1: Injected Channel1 selected
  *            @arg ADC_INJECTED_RANK_2: Injected Channel2 selected
  *            @arg ADC_INJECTED_RANK_3: Injected Channel3 selected
  *            @arg ADC_INJECTED_RANK_4: Injected Channel4 selected
  * @retval ADC group injected conversion data
  */
uint32_t HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank)
{
  uint32_t tmp_jdr = 0U;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_INJECTED_RANK(InjectedRank));
  
  /* Get ADC converted value */ 
  switch(InjectedRank)
  {  
    case ADC_INJECTED_RANK_4: 
      tmp_jdr = hadc->Instance->JDR4;
      break;
    case ADC_INJECTED_RANK_3: 
      tmp_jdr = hadc->Instance->JDR3;
      break;
    case ADC_INJECTED_RANK_2: 
      tmp_jdr = hadc->Instance->JDR2;
      break;
    case ADC_INJECTED_RANK_1:
    default:
      tmp_jdr = hadc->Instance->JDR1;
      break;
  }
  
  /* Return ADC converted value */ 
  return tmp_jdr;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  Returns the last ADC Master&Slave regular conversions results data
  *         in the selected multi mode.
  * @param  hadc: ADC handle of ADC master (handle of ADC slave must not be used)
  * @retval The converted data value.
  */
uint32_t HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef* hadc)
{
  uint32_t tmpDR = 0U;
  
  /* Check the parameters */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Note: EOC flag is not cleared here by software because automatically     */
  /*       cleared by hardware when reading register DR.                      */
  
  /* On STM32F1 devices, ADC1 data register DR contains ADC2 conversions      */
  /* only if ADC1 DMA mode is enabled.                                        */
  tmpDR = hadc->Instance->DR;

  if (HAL_IS_BIT_CLR(ADC1->CR2, ADC_CR2_DMA))
  {
    tmpDR |= (ADC2->DR << 16U);
  }
    
  /* Return ADC converted value */ 
  return tmpDR;
}
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief  Injected conversion complete callback in non blocking mode 
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_ADCEx_InjectedConvCpltCallback could be implemented in the user file
  */
}

/**
  * @}
  */

/** @defgroup ADCEx_Exported_Functions_Group2 Extended Peripheral Control functions
  * @brief    Extended Peripheral Control functions
  *
@verbatim   
 ===============================================================================
             ##### Peripheral Control functions #####
 ===============================================================================  
    [..]  This section provides functions allowing to:
      (+) Configure channels on injected group
      (+) Configure multimode

@endverbatim
  * @{
  */

/**
  * @brief  Configures the ADC injected group and the selected channel to be
  *         linked to the injected group.
  * @note   Possibility to update parameters on the fly:
  *         This function initializes injected group, following calls to this 
  *         function can be used to reconfigure some parameters of structure
  *         "ADC_InjectionConfTypeDef" on the fly, without resetting the ADC.
  *         The setting of these parameters is conditioned to ADC state: 
  *         this function must be called when ADC is not under conversion.
  * @param  hadc: ADC handle
  * @param  sConfigInjected: Structure of ADC injected group and ADC channel for
  *         injected group.
  * @retval None
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc, ADC_InjectionConfTypeDef* sConfigInjected)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  __IO uint32_t wait_loop_index = 0U;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_CHANNEL(sConfigInjected->InjectedChannel));
  assert_param(IS_ADC_SAMPLE_TIME(sConfigInjected->InjectedSamplingTime));
  assert_param(IS_FUNCTIONAL_STATE(sConfigInjected->AutoInjectedConv));
  assert_param(IS_ADC_EXTTRIGINJEC(sConfigInjected->ExternalTrigInjecConv));
  assert_param(IS_ADC_RANGE(sConfigInjected->InjectedOffset));
  
  if(hadc->Init.ScanConvMode != ADC_SCAN_DISABLE)
  {
    assert_param(IS_ADC_INJECTED_RANK(sConfigInjected->InjectedRank));
    assert_param(IS_ADC_INJECTED_NB_CONV(sConfigInjected->InjectedNbrOfConversion));
    assert_param(IS_FUNCTIONAL_STATE(sConfigInjected->InjectedDiscontinuousConvMode));
  }
  
  /* Process locked */
  __HAL_LOCK(hadc);
