    
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* Init the ADC Callback settings */
    hadc->ConvCpltCallback              = HAL_ADC_ConvCpltCallback;                 /* Legacy weak callback */
    hadc->ConvHalfCpltCallback          = HAL_ADC_ConvHalfCpltCallback;             /* Legacy weak callback */
    hadc->LevelOutOfWindowCallback      = HAL_ADC_LevelOutOfWindowCallback;         /* Legacy weak callback */
    hadc->ErrorCallback                 = HAL_ADC_ErrorCallback;                    /* Legacy weak callback */
    hadc->InjectedConvCpltCallback      = HAL_ADCEx_InjectedConvCpltCallback;       /* Legacy weak callback */
    
    if (hadc->MspInitCallback == NULL)
    {
      hadc->MspInitCallback = HAL_ADC_MspInit; /* Legacy weak MspInit  */
    }
    
    /* Init the low level hardware */
    hadc->MspInitCallback(hadc);
#else
    /* Init the low level hardware */
    HAL_ADC_MspInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }
  
  /* Stop potential conversion on going, on regular and injected groups */
  /* Disable ADC peripheral */
  /* Note: In case of ADC already enabled, precaution to not launch an        */
  /*       unwanted conversion while modifying register CR2 by writing 1 to   */
  /*       bit ADON.                                                          */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  
  /* Configuration of ADC parameters if previous preliminary actions are      */ 
  /* correctly completed.                                                     */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL) &&
      (tmp_hal_status == HAL_OK)                                  )
  {
    /* Set ADC state */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_BUSY_INTERNAL);
    
    /* Set ADC parameters */
    
    /* Configuration of ADC:                                                  */
    /*  - data alignment                                                      */
    /*  - external trigger to start conversion                                */
    /*  - external trigger polarity (always set to 1, because needed for all  */
    /*    triggers: external trigger of SW start)                             */
    /*  - continuous conversion mode                                          */
    /* Note: External trigger polarity (ADC_CR2_EXTTRIG) is set into          */
    /*       HAL_ADC_Start_xxx functions because if set in this function,     */
    /*       a conversion on injected group would start a conversion also on  */
    /*       regular group after ADC enabling.                                */
    tmp_cr2 |= (hadc->Init.DataAlign                                          |
                ADC_CFGR_EXTSEL(hadc, hadc->Init.ExternalTrigConv)            |
                ADC_CR2_CONTINUOUS((uint32_t)hadc->Init.ContinuousConvMode)   );

    /* Configuration of ADC:                                                  */
    /*  - scan mode                                                           */
    /*  - discontinuous mode disable/enable                                   */
    /*  - discontinuous mode number of conversions                            */
    tmp_cr1 |= (ADC_CR1_SCAN_SET(hadc->Init.ScanConvMode));
    
    /* Enable discontinuous mode only if continuous mode is disabled */
    /* Note: If parameter "Init.ScanConvMode" is set to disable, parameter    */
    /*       discontinuous is set anyway, but will have no effect on ADC HW.  */
    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      if (hadc->Init.ContinuousConvMode == DISABLE)
      {
        /* Enable the selected ADC regular discontinuous mode */
        /* Set the number of channels to be converted in discontinuous mode */
        SET_BIT(tmp_cr1, ADC_CR1_DISCEN                                            |
                         ADC_CR1_DISCONTINUOUS_NUM(hadc->Init.NbrOfDiscConversion)  );
      }
      else
      {
        /* ADC regular group settings continuous and sequencer discontinuous*/
        /* cannot be enabled simultaneously.                                */
        
        /* Update ADC state machine to error */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        /* Set ADC error code to ADC IP internal error */
        SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      }
    }
    
    /* Update ADC configuration register CR1 with previous settings */
      MODIFY_REG(hadc->Instance->CR1,
                 ADC_CR1_SCAN    |
                 ADC_CR1_DISCEN  |
                 ADC_CR1_DISCNUM    ,
                 tmp_cr1             );
    
    /* Update ADC configuration register CR2 with previous settings */
      MODIFY_REG(hadc->Instance->CR2,
                 ADC_CR2_ALIGN   |
                 ADC_CR2_EXTSEL  |
                 ADC_CR2_EXTTRIG |
                 ADC_CR2_CONT       ,
                 tmp_cr2             );

    /* Configuration of regular group sequencer:                              */
    /* - if scan mode is disabled, regular channels sequence length is set to */
    /*   0x00: 1 channel converted (channel on regular rank 1)                */
    /*   Parameter "NbrOfConversion" is discarded.                            */
    /*   Note: Scan mode is present by hardware on this device and, if        */
    /*   disabled, discards automatically nb of conversions. Anyway, nb of    */
    /*   conversions is forced to 0x00 for alignment over all STM32 devices.  */
    /* - if scan mode is enabled, regular channels sequence length is set to  */
    /*   parameter "NbrOfConversion"                                          */
    if (ADC_CR1_SCAN_SET(hadc->Init.ScanConvMode) == ADC_SCAN_ENABLE)
    {
      tmp_sqr1 = ADC_SQR1_L_SHIFT(hadc->Init.NbrOfConversion);
    }
      
    MODIFY_REG(hadc->Instance->SQR1,
               ADC_SQR1_L          ,
               tmp_sqr1             );
    
    /* Check back that ADC registers have effectively been configured to      */
    /* ensure of no potential problem of ADC core IP clocking.                */
    /* Check through register CR2 (excluding bits set in other functions:     */
    /* execution control bits (ADON, JSWSTART, SWSTART), regular group bits   */
    /* (DMA), injected group bits (JEXTTRIG and JEXTSEL), channel internal    */
    /* measurement path bit (TSVREFE).                                        */
    if (READ_BIT(hadc->Instance->CR2, ~(ADC_CR2_ADON | ADC_CR2_DMA |
                                        ADC_CR2_SWSTART | ADC_CR2_JSWSTART |
                                        ADC_CR2_JEXTTRIG | ADC_CR2_JEXTSEL |
                                        ADC_CR2_TSVREFE                     ))
         == tmp_cr2)
    {
      /* Set ADC error code to none */
      ADC_CLEAR_ERRORCODE(hadc);
      
      /* Set the ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_READY);
    }
    else
    {
      /* Update ADC state machine to error */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_ERROR_INTERNAL);
      
      /* Set ADC error code to ADC IP internal error */
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      
      tmp_hal_status = HAL_ERROR;
    }
  
  }
  else
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);
        
    tmp_hal_status = HAL_ERROR;
  }
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Deinitialize the ADC peripheral registers to their default reset
  *         values, with deinitialization of the ADC MSP.
  *         If needed, the example code can be copied and uncommented into
  *         function HAL_ADC_MspDeInit().
  * @param  hadc: ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check ADC handle */
  if(hadc == NULL)
  {
     return HAL_ERROR;
  }
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Set ADC state */
  SET_BIT(hadc->State, HAL_ADC_STATE_BUSY_INTERNAL);
  
  /* Stop potential conversion on going, on regular and injected groups */
  /* Disable ADC peripheral */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  
  /* Configuration of ADC parameters if previous preliminary actions are      */ 
  /* correctly completed.                                                     */
  if (tmp_hal_status == HAL_OK)
  {
    /* ========== Reset ADC registers ========== */




    /* Reset register SR */
    __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_AWD | ADC_FLAG_JEOC | ADC_FLAG_EOC |
                                ADC_FLAG_JSTRT | ADC_FLAG_STRT));
                         
    /* Reset register CR1 */
    CLEAR_BIT(hadc->Instance->CR1, (ADC_CR1_AWDEN   | ADC_CR1_JAWDEN | ADC_CR1_DISCNUM | 
                                    ADC_CR1_JDISCEN | ADC_CR1_DISCEN | ADC_CR1_JAUTO   | 
                                    ADC_CR1_AWDSGL  | ADC_CR1_SCAN   | ADC_CR1_JEOCIE  |   
                                    ADC_CR1_AWDIE   | ADC_CR1_EOCIE  | ADC_CR1_AWDCH    ));
    
    /* Reset register CR2 */
    CLEAR_BIT(hadc->Instance->CR2, (ADC_CR2_TSVREFE | ADC_CR2_SWSTART | ADC_CR2_JSWSTART | 
                                    ADC_CR2_EXTTRIG | ADC_CR2_EXTSEL  | ADC_CR2_JEXTTRIG |  
                                    ADC_CR2_JEXTSEL | ADC_CR2_ALIGN   | ADC_CR2_DMA      |        
                                    ADC_CR2_RSTCAL  | ADC_CR2_CAL     | ADC_CR2_CONT     |          
                                    ADC_CR2_ADON                                          ));
    
    /* Reset register SMPR1 */
    CLEAR_BIT(hadc->Instance->SMPR1, (ADC_SMPR1_SMP17 | ADC_SMPR1_SMP16 | ADC_SMPR1_SMP15 | 
                                      ADC_SMPR1_SMP14 | ADC_SMPR1_SMP13 | ADC_SMPR1_SMP12 | 
                                      ADC_SMPR1_SMP11 | ADC_SMPR1_SMP10                    ));
    
    /* Reset register SMPR2 */
    CLEAR_BIT(hadc->Instance->SMPR2, (ADC_SMPR2_SMP9 | ADC_SMPR2_SMP8 | ADC_SMPR2_SMP7 | 
                                      ADC_SMPR2_SMP6 | ADC_SMPR2_SMP5 | ADC_SMPR2_SMP4 | 
                                      ADC_SMPR2_SMP3 | ADC_SMPR2_SMP2 | ADC_SMPR2_SMP1 | 
                                      ADC_SMPR2_SMP0                                    ));

    /* Reset register JOFR1 */
    CLEAR_BIT(hadc->Instance->JOFR1, ADC_JOFR1_JOFFSET1);
    /* Reset register JOFR2 */
    CLEAR_BIT(hadc->Instance->JOFR2, ADC_JOFR2_JOFFSET2);
    /* Reset register JOFR3 */
    CLEAR_BIT(hadc->Instance->JOFR3, ADC_JOFR3_JOFFSET3);
    /* Reset register JOFR4 */
    CLEAR_BIT(hadc->Instance->JOFR4, ADC_JOFR4_JOFFSET4);
    
    /* Reset register HTR */
    CLEAR_BIT(hadc->Instance->HTR, ADC_HTR_HT);
    /* Reset register LTR */
    CLEAR_BIT(hadc->Instance->LTR, ADC_LTR_LT);
    
    /* Reset register SQR1 */
    CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L    |
                                    ADC_SQR1_SQ16 | ADC_SQR1_SQ15 | 
                                    ADC_SQR1_SQ14 | ADC_SQR1_SQ13  );
    
    /* Reset register SQR1 */
    CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L    |
                                    ADC_SQR1_SQ16 | ADC_SQR1_SQ15 | 
                                    ADC_SQR1_SQ14 | ADC_SQR1_SQ13  );
    
    /* Reset register SQR2 */
    CLEAR_BIT(hadc->Instance->SQR2, ADC_SQR2_SQ12 | ADC_SQR2_SQ11 | ADC_SQR2_SQ10 | 
                                    ADC_SQR2_SQ9  | ADC_SQR2_SQ8  | ADC_SQR2_SQ7   );
    
    /* Reset register SQR3 */
    CLEAR_BIT(hadc->Instance->SQR3, ADC_SQR3_SQ6 | ADC_SQR3_SQ5 | ADC_SQR3_SQ4 | 
                                    ADC_SQR3_SQ3 | ADC_SQR3_SQ2 | ADC_SQR3_SQ1  );
    
    /* Reset register JSQR */
    CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL |
                                    ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | 
                                    ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1  );
    
    /* Reset register JSQR */
    CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL |
                                    ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | 
                                    ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1  );
    
    /* Reset register DR */
    /* bits in access mode read only, no direct reset applicable*/
    
    /* Reset registers JDR1, JDR2, JDR3, JDR4 */
    /* bits in access mode read only, no direct reset applicable*/
    
    /* ========== Hard reset ADC peripheral ========== */
    /* Performs a global reset of the entire ADC peripheral: ADC state is     */
    /* forced to a similar state after device power-on.                       */
    /* If needed, copy-paste and uncomment the following reset code into      */
    /* function "void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)":              */
    /*                                                                        */
    /*  __HAL_RCC_ADC1_FORCE_RESET()                                          */
    /*  __HAL_RCC_ADC1_RELEASE_RESET()                                        */
    
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    if (hadc->MspDeInitCallback == NULL)
    {
      hadc->MspDeInitCallback = HAL_ADC_MspDeInit; /* Legacy weak MspDeInit  */
    }
    
    /* DeInit the low level hardware */
    hadc->MspDeInitCallback(hadc);
#else
    /* DeInit the low level hardware */
    HAL_ADC_MspDeInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
    
    /* Set ADC error code to none */
    ADC_CLEAR_ERRORCODE(hadc);
    
    /* Set ADC state */
    hadc->State = HAL_ADC_STATE_RESET; 
  
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Initializes the ADC MSP.
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_MspInit must be implemented in the user file.
   */ 
}

/**
  * @brief  DeInitializes the ADC MSP.
  * @param  hadc: ADC handle
  * @retval None
  */
__weak void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hadc);
  /* NOTE : This function should not be modified. When the callback is needed,
            function HAL_ADC_MspDeInit must be implemented in the user file.
   */ 
}

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  Register a User ADC Callback
  *         To be used instead of the weak predefined callback
  * @param  hadc Pointer to a ADC_HandleTypeDef structure that contains
  *                the configuration information for the specified ADC.
  * @param  CallbackID ID of the callback to be registered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC conversion complete callback ID
  *          @arg @ref HAL_ADC_CONVERSION_HALF_CB_ID          ADC conversion complete callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC analog watchdog 1 callback ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC error callback ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC group injected conversion complete callback ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp Init callback ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp DeInit callback ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID MspDeInit callback ID
  * @param  pCallback pointer to the Callback function
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  if (pCallback == NULL)
  {
    /* Update the error code */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  
  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        hadc->ConvCpltCallback = pCallback;
        break;
      
      case HAL_ADC_CONVERSION_HALF_CB_ID :
        hadc->ConvHalfCpltCallback = pCallback;
        break;
      
      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        hadc->LevelOutOfWindowCallback = pCallback;
        break;
      
      case HAL_ADC_ERROR_CB_ID :
        hadc->ErrorCallback = pCallback;
        break;
      
      case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        hadc->InjectedConvCpltCallback = pCallback;
        break;
      
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = pCallback;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = pCallback;
        break;
      
      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* Return error status */
        status = HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        hadc->MspInitCallback = pCallback;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        hadc->MspDeInitCallback = pCallback;
        break;
      
      default :
        /* Update the error code */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
      
        /* Return error status */
        status = HAL_ERROR;
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

/**
  * @brief  Unregister a ADC Callback
  *         ADC callback is redirected to the weak predefined callback
  * @param  hadc Pointer to a ADC_HandleTypeDef structure that contains
  *                the configuration information for the specified ADC.
  * @param  CallbackID ID of the callback to be unregistered
  *         This parameter can be one of the following values:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC conversion complete callback ID
  *          @arg @ref HAL_ADC_CONVERSION_HALF_CB_ID          ADC conversion complete callback ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC analog watchdog 1 callback ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC error callback ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC group injected conversion complete callback ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp Init callback ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp DeInit callback ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID MspInit callback ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID MspDeInit callback ID
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        hadc->ConvCpltCallback = HAL_ADC_ConvCpltCallback;
        break;
      
      case HAL_ADC_CONVERSION_HALF_CB_ID :
        hadc->ConvHalfCpltCallback = HAL_ADC_ConvHalfCpltCallback;
        break;
      
      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        hadc->LevelOutOfWindowCallback = HAL_ADC_LevelOutOfWindowCallback;
        break;
      
      case HAL_ADC_ERROR_CB_ID :
        hadc->ErrorCallback = HAL_ADC_ErrorCallback;
        break;
