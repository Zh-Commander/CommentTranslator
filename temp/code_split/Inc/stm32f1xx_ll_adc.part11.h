
/**
  * @brief  Get ADC analog watchdog monitored channel.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function LL_ADC_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals LL_ADC_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals LL_ADC_CHANNEL_x or using
  *           helper macro @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal LL_ADC_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB().
  *           Applicable only when the analog watchdog is set to monitor
  *           one channel.
  * @note   On this STM32 series, there is only 1 kind of analog watchdog
  *         instance:
  *         - AWD standard (instance AWD1):
  *           - channels monitored: can monitor 1 channel or all channels.
  *           - groups monitored: ADC groups regular and-or injected.
  *           - resolution: resolution is not limited (corresponds to
  *             ADC resolution configured).
  * @rmtoll CR1      AWD1CH         LL_ADC_GetAnalogWDMonitChannels\n
  *         CR1      AWD1SGL        LL_ADC_GetAnalogWDMonitChannels\n
  *         CR1      AWD1EN         LL_ADC_GetAnalogWDMonitChannels
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_AWD_DISABLE
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_INJ
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_REG_INJ
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDMonitChannels(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR1, (ADC_CR1_AWDEN | ADC_CR1_JAWDEN | ADC_CR1_AWDSGL | ADC_CR1_AWDCH)));
}

/**
  * @brief  Set ADC analog watchdog threshold value of threshold
  *         high or low.
  * @note   On this STM32 series, there is only 1 kind of analog watchdog
  *         instance:
  *         - AWD standard (instance AWD1):
  *           - channels monitored: can monitor 1 channel or all channels.
  *           - groups monitored: ADC groups regular and-or injected.
  *           - resolution: resolution is not limited (corresponds to
  *             ADC resolution configured).
  * @rmtoll HTR      HT             LL_ADC_SetAnalogWDThresholds\n
  *         LTR      LT             LL_ADC_SetAnalogWDThresholds
  * @param  ADCx ADC instance
  * @param  AWDThresholdsHighLow This parameter can be one of the following values:
  *         @arg @ref LL_ADC_AWD_THRESHOLD_HIGH
  *         @arg @ref LL_ADC_AWD_THRESHOLD_LOW
  * @param  AWDThresholdValue: Value between Min_Data=0x000 and Max_Data=0xFFF
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDThresholdsHighLow, uint32_t AWDThresholdValue)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->HTR, AWDThresholdsHighLow);
  
  MODIFY_REG(*preg,
             ADC_HTR_HT,
             AWDThresholdValue);
}

/**
  * @brief  Get ADC analog watchdog threshold value of threshold high or
  *         threshold low.
  * @note   In case of ADC resolution different of 12 bits,
  *         analog watchdog thresholds data require a specific shift.
  *         Use helper macro @ref __LL_ADC_ANALOGWD_GET_THRESHOLD_RESOLUTION().
  * @rmtoll HTR      HT             LL_ADC_GetAnalogWDThresholds\n
  *         LTR      LT             LL_ADC_GetAnalogWDThresholds
  * @param  ADCx ADC instance
  * @param  AWDThresholdsHighLow This parameter can be one of the following values:
  *         @arg @ref LL_ADC_AWD_THRESHOLD_HIGH
  *         @arg @ref LL_ADC_AWD_THRESHOLD_LOW
  * @retval Value between Min_Data=0x000 and Max_Data=0xFFF
*/
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDThresholdsHighLow)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->HTR, AWDThresholdsHighLow);
  
  return (uint32_t)(READ_BIT(*preg, ADC_HTR_HT));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Multimode Configuration of ADC hierarchical scope: multimode
  * @{
  */

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  Set ADC multimode configuration to operate in independent mode
  *         or multimode (for devices with several ADC instances).
  * @note   If multimode configuration: the selected ADC instance is
  *         either master or slave depending on hardware.
  *         Refer to reference manual.
  * @rmtoll CR1      DUALMOD        LL_ADC_SetMultimode
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  Multimode This parameter can be one of the following values:
  *         @arg @ref LL_ADC_MULTI_INDEPENDENT             
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_FAST    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_SLOW    
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_ALTERN         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetMultimode(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t Multimode)
{
  MODIFY_REG(ADCxy_COMMON->CR1, ADC_CR1_DUALMOD, Multimode);
}

/**
  * @brief  Get ADC multimode configuration to operate in independent mode
  *         or multimode (for devices with several ADC instances).
  * @note   If multimode configuration: the selected ADC instance is
  *         either master or slave depending on hardware.
  *         Refer to reference manual.
  * @rmtoll CR1      DUALMOD        LL_ADC_GetMultimode
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_MULTI_INDEPENDENT
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_FAST    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_SLOW    
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_ALTERN         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM
  */
__STATIC_INLINE uint32_t LL_ADC_GetMultimode(ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CR1, ADC_CR1_DUALMOD));
}

#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */
/** @defgroup ADC_LL_EF_Operation_ADC_Instance Operation on ADC hierarchical scope: ADC instance
  * @{
  */

/**
  * @brief  Enable the selected ADC instance.
  * @note   On this STM32 series, after ADC enable, a delay for 
  *         ADC internal analog stabilization is required before performing a
  *         ADC conversion start.
  *         Refer to device datasheet, parameter tSTAB.
  * @rmtoll CR2      ADON           LL_ADC_Enable
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_Enable(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR2, ADC_CR2_ADON);
}

/**
  * @brief  Disable the selected ADC instance.
  * @rmtoll CR2      ADON           LL_ADC_Disable
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_Disable(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->CR2, ADC_CR2_ADON);
}

/**
  * @brief  Get the selected ADC instance enable state.
  * @rmtoll CR2      ADON           LL_ADC_IsEnabled
  * @param  ADCx ADC instance
  * @retval 0: ADC is disabled, 1: ADC is enabled.
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabled(ADC_TypeDef *ADCx)
{
  return (READ_BIT(ADCx->CR2, ADC_CR2_ADON) == (ADC_CR2_ADON));
}

/**
  * @brief  Start ADC calibration in the mode single-ended
  *         or differential (for devices with differential mode available).
  * @note   On this STM32 series, before starting a calibration,
  *         ADC must be disabled.
  *         A minimum number of ADC clock cycles are required
  *         between ADC disable state and calibration start.
  *         Refer to literal @ref LL_ADC_DELAY_DISABLE_CALIB_ADC_CYCLES.
  * @note   On this STM32 series, hardware prerequisite before starting a calibration:
            the ADC must have been in power-on state for at least
            two ADC clock cycles.
  * @rmtoll CR2      CAL            LL_ADC_StartCalibration
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_StartCalibration(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR2, ADC_CR2_CAL);
}

/**
  * @brief  Get ADC calibration state.
  * @rmtoll CR2      CAL            LL_ADC_IsCalibrationOnGoing
  * @param  ADCx ADC instance
  * @retval 0: calibration complete, 1: calibration in progress.
  */
__STATIC_INLINE uint32_t LL_ADC_IsCalibrationOnGoing(ADC_TypeDef *ADCx)
{
  return (READ_BIT(ADCx->CR2, ADC_CR2_CAL) == (ADC_CR2_CAL));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Operation_ADC_Group_Regular Operation on ADC hierarchical scope: group regular
  * @{
  */

/**
  * @brief  Start ADC group regular conversion.
  * @note   On this STM32 series, this function is relevant only for
  *         internal trigger (SW start), not for external trigger:
  *         - If ADC trigger has been set to software start, ADC conversion
  *           starts immediately.
  *         - If ADC trigger has been set to external trigger, ADC conversion
  *           start must be performed using function 
  *           @ref LL_ADC_REG_StartConversionExtTrig().
  *           (if external trigger edge would have been set during ADC other 
  *           settings, ADC conversion would start at trigger event
  *           as soon as ADC is enabled).
  * @rmtoll CR2      SWSTART        LL_ADC_REG_StartConversionSWStart
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_REG_StartConversionSWStart(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
}

/**
  * @brief  Start ADC group regular conversion from external trigger.
  * @note   ADC conversion will start at next trigger event (on the selected
  *         trigger edge) following the ADC start conversion command.
  * @note   On this STM32 series, this function is relevant for 
  *         ADC conversion start from external trigger.
  *         If internal trigger (SW start) is needed, perform ADC conversion
  *         start using function @ref LL_ADC_REG_StartConversionSWStart().
  * @rmtoll CR2      EXTEN          LL_ADC_REG_StartConversionExtTrig
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref LL_ADC_REG_TRIG_EXT_RISING
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_REG_StartConversionExtTrig(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  SET_BIT(ADCx->CR2, ExternalTriggerEdge);
}

/**
  * @brief  Stop ADC group regular conversion from external trigger.
  * @note   No more ADC conversion will start at next trigger event
  *         following the ADC stop conversion command.
  *         If a conversion is on-going, it will be completed.
  * @note   On this STM32 series, there is no specific command
  *         to stop a conversion on-going or to stop ADC converting
  *         in continuous mode. These actions can be performed
  *         using function @ref LL_ADC_Disable().
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_StopConversionExtTrig
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_REG_StopConversionExtTrig(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->CR2, ADC_CR2_EXTTRIG);
}

/**
  * @brief  Get ADC group regular conversion data, range fit for
  *         all ADC configurations: all ADC resolutions and
  *         all oversampling increased data width (for devices
  *         with feature oversampling).
  * @rmtoll DR       RDATA          LL_ADC_REG_ReadConversionData32
  * @param  ADCx ADC instance
  * @retval Value between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_REG_ReadConversionData32(ADC_TypeDef *ADCx)
{
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_DATA));
}

/**
  * @brief  Get ADC group regular conversion data, range fit for
  *         ADC resolution 12 bits.
  * @note   For devices with feature oversampling: Oversampling
  *         can increase data width, function for extended range
  *         may be needed: @ref LL_ADC_REG_ReadConversionData32.
  * @rmtoll DR       RDATA          LL_ADC_REG_ReadConversionData12
  * @param  ADCx ADC instance
  * @retval Value between Min_Data=0x000 and Max_Data=0xFFF
  */
__STATIC_INLINE uint16_t LL_ADC_REG_ReadConversionData12(ADC_TypeDef *ADCx)
{
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_DATA));
}

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  Get ADC multimode conversion data of ADC master, ADC slave
  *         or raw data with ADC master and slave concatenated.
  * @note   If raw data with ADC master and slave concatenated is retrieved,
  *         a macro is available to get the conversion data of
  *         ADC master or ADC slave: see helper macro
  *         @ref __LL_ADC_MULTI_CONV_DATA_MASTER_SLAVE().
  *         (however this macro is mainly intended for multimode
  *         transfer by DMA, because this function can do the same
  *         by getting multimode conversion data of ADC master or ADC slave
  *         separately).
  * @rmtoll DR       DATA           LL_ADC_REG_ReadMultiConversionData32\n
  *         DR       ADC2DATA       LL_ADC_REG_ReadMultiConversionData32
  * @param  ADCx ADC instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  ConversionData This parameter can be one of the following values:
  *         @arg @ref LL_ADC_MULTI_MASTER
  *         @arg @ref LL_ADC_MULTI_SLAVE
  *         @arg @ref LL_ADC_MULTI_MASTER_SLAVE
  * @retval Value between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_REG_ReadMultiConversionData32(ADC_TypeDef *ADCx, uint32_t ConversionData)
{
  return (uint32_t)(READ_BIT(ADCx->DR,
                             ADC_DR_ADC2DATA)
                    >> POSITION_VAL(ConversionData)
                   );
}
#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Operation_ADC_Group_Injected Operation on ADC hierarchical scope: group injected
  * @{
  */

/**
  * @brief  Start ADC group injected conversion.
  * @note   On this STM32 series, this function is relevant only for
  *         internal trigger (SW start), not for external trigger:
  *         - If ADC trigger has been set to software start, ADC conversion
  *           starts immediately.
  *         - If ADC trigger has been set to external trigger, ADC conversion
  *           start must be performed using function 
  *           @ref LL_ADC_INJ_StartConversionExtTrig().
  *           (if external trigger edge would have been set during ADC other 
  *           settings, ADC conversion would start at trigger event
  *           as soon as ADC is enabled).
  * @rmtoll CR2      JSWSTART       LL_ADC_INJ_StartConversionSWStart
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_StartConversionSWStart(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
}

/**
  * @brief  Start ADC group injected conversion from external trigger.
  * @note   ADC conversion will start at next trigger event (on the selected
  *         trigger edge) following the ADC start conversion command.
  * @note   On this STM32 series, this function is relevant for 
  *         ADC conversion start from external trigger.
  *         If internal trigger (SW start) is needed, perform ADC conversion
  *         start using function @ref LL_ADC_INJ_StartConversionSWStart().
  * @rmtoll CR2      JEXTEN         LL_ADC_INJ_StartConversionExtTrig
  * @param  ExternalTriggerEdge This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_RISING
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_StartConversionExtTrig(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  SET_BIT(ADCx->CR2, ExternalTriggerEdge);
}
