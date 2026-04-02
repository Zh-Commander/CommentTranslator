
/**
  * @brief  Helper macro to calculate the temperature (unit: degree Celsius)
  *         from ADC conversion data of internal temperature sensor.
  * @note   Computation is using temperature sensor typical values
  *         (refer to device datasheet).
  * @note   Calculation formula:
  *           Temperature = (TS_TYP_CALx_VOLT(uV) - TS_ADC_DATA * Conversion_uV)
  *                         / Avg_Slope + CALx_TEMP
  *           with TS_ADC_DATA      = temperature sensor raw data measured by ADC
  *                                   (unit: digital value)
  *                Avg_Slope        = temperature sensor slope
  *                                   (unit: uV/Degree Celsius)
  *                TS_TYP_CALx_VOLT = temperature sensor digital value at
  *                                   temperature CALx_TEMP (unit: mV)
  *         Caution: Calculation relevancy under reserve the temperature sensor
  *                  of the current device has characteristics in line with
  *                  datasheet typical values.
  *                  If temperature sensor calibration values are available on
  *                  on this device (presence of macro __LL_ADC_CALC_TEMPERATURE()),
  *                  temperature calculation will be more accurate using
  *                  helper macro @ref __LL_ADC_CALC_TEMPERATURE().
  * @note   As calculation input, the analog reference voltage (Vref+) must be
  *         defined as it impacts the ADC LSB equivalent voltage.
  * @note   Analog reference voltage (Vref+) must be known from
  *         user board environment or can be calculated using ADC measurement.
  * @note   ADC measurement data must correspond to a resolution of 12bits
  *         (full scale digital value 4095). If not the case, the data must be
  *         preliminarily rescaled to an equivalent resolution of 12 bits.
  * @param  __TEMPSENSOR_TYP_AVGSLOPE__   Device datasheet data: Temperature sensor slope typical value (unit: uV/DegCelsius).
  *                                       On STM32F1, refer to device datasheet parameter "Avg_Slope".
  * @param  __TEMPSENSOR_TYP_CALX_V__     Device datasheet data: Temperature sensor voltage typical value (at temperature and Vref+ defined in parameters below) (unit: mV).
  *                                       On STM32F1, refer to device datasheet parameter "V25".
  * @param  __TEMPSENSOR_CALX_TEMP__      Device datasheet data: Temperature at which temperature sensor voltage (see parameter above) is corresponding (unit: mV)
  * @param  __VREFANALOG_VOLTAGE__        Analog voltage reference (Vref+) voltage (unit: mV)
  * @param  __TEMPSENSOR_ADC_DATA__       ADC conversion data of internal temperature sensor (unit: digital value).
  * @param  __ADC_RESOLUTION__            ADC resolution at which internal temperature sensor voltage has been measured.
  *         This parameter can be one of the following values:
  *         @arg @ref LL_ADC_RESOLUTION_12B
  * @retval Temperature (unit: degree Celsius)
  */
#define __LL_ADC_CALC_TEMPERATURE_TYP_PARAMS(__TEMPSENSOR_TYP_AVGSLOPE__,\
                                             __TEMPSENSOR_TYP_CALX_V__,\
                                             __TEMPSENSOR_CALX_TEMP__,\
                                             __VREFANALOG_VOLTAGE__,\
                                             __TEMPSENSOR_ADC_DATA__,\
                                             __ADC_RESOLUTION__)               \
  ((( (                                                                        \
       (int32_t)(((__TEMPSENSOR_TYP_CALX_V__))                                 \
                 * 1000)                                                       \
       -                                                                       \
       (int32_t)((((__TEMPSENSOR_ADC_DATA__) * (__VREFANALOG_VOLTAGE__))       \
                  / __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__))                \
                 * 1000)                                                       \
      )                                                                        \
    ) / (__TEMPSENSOR_TYP_AVGSLOPE__)                                          \
   ) + (__TEMPSENSOR_CALX_TEMP__)                                              \
  )

/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Functions ADC Exported Functions
  * @{
  */

/** @defgroup ADC_LL_EF_DMA_Management ADC DMA management
  * @{
  */
/* Note: LL ADC functions to set DMA transfer are located into sections of    */
/*       configuration of ADC instance, groups and multimode (if available):  */
/*       @ref LL_ADC_REG_SetDMATransfer(), ...                                */

/**
  * @brief  Function to help to configure DMA transfer from ADC: retrieve the
  *         ADC register address from ADC instance and a list of ADC registers
  *         intended to be used (most commonly) with DMA transfer.
  * @note   These ADC registers are data registers:
  *         when ADC conversion data is available in ADC data registers,
  *         ADC generates a DMA transfer request.
  * @note   This macro is intended to be used with LL DMA driver, refer to
  *         function "LL_DMA_ConfigAddresses()".
  *         Example:
  *           LL_DMA_ConfigAddresses(DMA1,
  *                                  LL_DMA_CHANNEL_1,
  *                                  LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
  *                                  (uint32_t)&< array or variable >,
  *                                  LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  * @note   For devices with several ADC: in multimode, some devices
  *         use a different data register outside of ADC instance scope
  *         (common data register). This macro manages this register difference,
  *         only ADC instance has to be set as parameter.
  * @note   On STM32F1, only ADC instances ADC1 and ADC3 have DMA transfer
  *         capability, not ADC2 (ADC2 and ADC3 instances not available on
  *         all devices).
  * @note   On STM32F1, multimode can be used only with ADC1 and ADC2, not ADC3.
  *         Therefore, the corresponding parameter of data transfer
  *         for multimode can be used only with ADC1 and ADC2.
  *         (ADC2 and ADC3 instances not available on all devices).
  * @rmtoll DR       DATA           LL_ADC_DMA_GetRegAddr
  * @param  ADCx ADC instance
  * @param  Register This parameter can be one of the following values:
  *         @arg @ref LL_ADC_DMA_REG_REGULAR_DATA
  *         @arg @ref LL_ADC_DMA_REG_REGULAR_DATA_MULTI (1)
  *         
  *         (1) Available on devices with several ADC instances.
  * @retval ADC register address
  */
#if defined(ADC_MULTIMODE_SUPPORT)
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  uint32_t data_reg_addr = 0U;
  
  if (Register == LL_ADC_DMA_REG_REGULAR_DATA)
  {
    /* Retrieve address of register DR */
    data_reg_addr = (uint32_t)&(ADCx->DR);
  }
  else /* (Register == LL_ADC_DMA_REG_REGULAR_DATA_MULTI) */
  {
    /* Retrieve address of register of multimode data */
    data_reg_addr = (uint32_t)&(ADC12_COMMON->DR);
  }
  
  return data_reg_addr;
}
#else
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  /* Retrieve address of register DR */
  return (uint32_t)&(ADCx->DR);
}
#endif

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Common Configuration of ADC hierarchical scope: common to several ADC instances
  * @{
  */

/**
  * @brief  Set parameter common to several ADC: measurement path to internal
  *         channels (VrefInt, temperature sensor, ...).
  * @note   One or several values can be selected.
  *         Example: (LL_ADC_PATH_INTERNAL_VREFINT |
  *                   LL_ADC_PATH_INTERNAL_TEMPSENSOR)
  * @note   Stabilization time of measurement path to internal channel:
  *         After enabling internal paths, before starting ADC conversion,
  *         a delay is required for internal voltage reference and
  *         temperature sensor stabilization time.
  *         Refer to device datasheet.
  *         Refer to literal @ref LL_ADC_DELAY_TEMPSENSOR_STAB_US.
  * @note   ADC internal channel sampling time constraint:
  *         For ADC conversion of internal channels,
  *         a sampling time minimum value is required.
  *         Refer to device datasheet.
  * @rmtoll CR2      TSVREFE        LL_ADC_SetCommonPathInternalCh
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  PathInternal This parameter can be a combination of the following values:
  *         @arg @ref LL_ADC_PATH_INTERNAL_NONE
  *         @arg @ref LL_ADC_PATH_INTERNAL_VREFINT
  *         @arg @ref LL_ADC_PATH_INTERNAL_TEMPSENSOR
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t PathInternal)
{
  MODIFY_REG(ADCxy_COMMON->CR2, (ADC_CR2_TSVREFE), PathInternal);
}

/**
  * @brief  Get parameter common to several ADC: measurement path to internal
  *         channels (VrefInt, temperature sensor, ...).
  * @note   One or several values can be selected.
  *         Example: (LL_ADC_PATH_INTERNAL_VREFINT |
  *                   LL_ADC_PATH_INTERNAL_TEMPSENSOR)
  * @rmtoll CR2      TSVREFE        LL_ADC_GetCommonPathInternalCh
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval Returned value can be a combination of the following values:
  *         @arg @ref LL_ADC_PATH_INTERNAL_NONE
  *         @arg @ref LL_ADC_PATH_INTERNAL_VREFINT
  *         @arg @ref LL_ADC_PATH_INTERNAL_TEMPSENSOR
  */
__STATIC_INLINE uint32_t LL_ADC_GetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CR2, ADC_CR2_TSVREFE));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Instance Configuration of ADC hierarchical scope: ADC instance
  * @{
  */

/**
  * @brief  Set ADC conversion data alignment.
  * @note   Refer to reference manual for alignments formats
  *         dependencies to ADC resolutions.
  * @rmtoll CR2      ALIGN          LL_ADC_SetDataAlignment
  * @param  ADCx ADC instance
  * @param  DataAlignment This parameter can be one of the following values:
  *         @arg @ref LL_ADC_DATA_ALIGN_RIGHT
  *         @arg @ref LL_ADC_DATA_ALIGN_LEFT
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetDataAlignment(ADC_TypeDef *ADCx, uint32_t DataAlignment)
{
  MODIFY_REG(ADCx->CR2, ADC_CR2_ALIGN, DataAlignment);
}

/**
  * @brief  Get ADC conversion data alignment.
  * @note   Refer to reference manual for alignments formats
  *         dependencies to ADC resolutions.
  * @rmtoll CR2      ALIGN          LL_ADC_SetDataAlignment
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_DATA_ALIGN_RIGHT
  *         @arg @ref LL_ADC_DATA_ALIGN_LEFT
  */
__STATIC_INLINE uint32_t LL_ADC_GetDataAlignment(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_ALIGN));
}

/**
  * @brief  Set ADC sequencers scan mode, for all ADC groups
  *         (group regular, group injected).
  * @note  According to sequencers scan mode :
  *         - If disabled: ADC conversion is performed in unitary conversion
  *           mode (one channel converted, that defined in rank 1).
  *           Configuration of sequencers of all ADC groups
  *           (sequencer scan length, ...) is discarded: equivalent to
  *           scan length of 1 rank.
  *         - If enabled: ADC conversions are performed in sequence conversions
  *           mode, according to configuration of sequencers of
  *           each ADC group (sequencer scan length, ...).
  *           Refer to function @ref LL_ADC_REG_SetSequencerLength()
  *           and to function @ref LL_ADC_INJ_SetSequencerLength().
  * @rmtoll CR1      SCAN           LL_ADC_SetSequencersScanMode
  * @param  ADCx ADC instance
  * @param  ScanMode This parameter can be one of the following values:
  *         @arg @ref LL_ADC_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_SEQ_SCAN_ENABLE
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetSequencersScanMode(ADC_TypeDef *ADCx, uint32_t ScanMode)
{
  MODIFY_REG(ADCx->CR1, ADC_CR1_SCAN, ScanMode);
}

/**
  * @brief  Get ADC sequencers scan mode, for all ADC groups
  *         (group regular, group injected).
  * @note  According to sequencers scan mode :
  *         - If disabled: ADC conversion is performed in unitary conversion
  *           mode (one channel converted, that defined in rank 1).
  *           Configuration of sequencers of all ADC groups
  *           (sequencer scan length, ...) is discarded: equivalent to
  *           scan length of 1 rank.
  *         - If enabled: ADC conversions are performed in sequence conversions
  *           mode, according to configuration of sequencers of
  *           each ADC group (sequencer scan length, ...).
  *           Refer to function @ref LL_ADC_REG_SetSequencerLength()
  *           and to function @ref LL_ADC_INJ_SetSequencerLength().
  * @rmtoll CR1      SCAN           LL_ADC_GetSequencersScanMode
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_SEQ_SCAN_ENABLE
  */
__STATIC_INLINE uint32_t LL_ADC_GetSequencersScanMode(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_SCAN));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Group_Regular Configuration of ADC hierarchical scope: group regular
  * @{
  */

/**
  * @brief  Set ADC group regular conversion trigger source:
  *         internal (SW start) or from external IP (timer event,
  *         external interrupt line).
  * @note   On this STM32 series, external trigger is set with trigger polarity:
  *         rising edge (only trigger polarity available on this STM32 series).
  * @note   Availability of parameters of trigger sources from timer 
  *         depends on timers availability on the selected device.
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_SetTriggerSource
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref LL_ADC_REG_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH3       (1)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH1       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM4_CH4       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (2)(4)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH3       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH3       (3)
  *         
  *         (1) On STM32F1, parameter available on all ADC instances: ADC1, ADC2, ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (2) On STM32F1, parameter available only on ADC instances: ADC1, ADC2 (for ADC instances ADCx available on the selected device).\n
  *         (3) On STM32F1, parameter available only on ADC instances: ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (4) On STM32F1, parameter available only on high-density and XL-density devices. A remap of trigger must be done at top level (refer to AFIO peripheral).
  * @retval None
  */
__STATIC_INLINE void LL_ADC_REG_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
/* Note: On this STM32 series, ADC group regular external trigger edge        */
/*       is used to perform a ADC conversion start.                           */
/*       This function does not set external trigger edge.                    */
/*       This feature is set using function                                   */
/*       @ref LL_ADC_REG_StartConversionExtTrig().                            */
  MODIFY_REG(ADCx->CR2, ADC_CR2_EXTSEL, (TriggerSource & ADC_CR2_EXTSEL));
}

/**
  * @brief  Get ADC group regular conversion trigger source:
  *         internal (SW start) or from external IP (timer event,
  *         external interrupt line).
  * @note   To determine whether group regular trigger source is
  *         internal (SW start) or external, without detail
  *         of which peripheral is selected as external trigger,
  *         (equivalent to 
  *         "if(LL_ADC_REG_GetTriggerSource(ADC1) == LL_ADC_REG_TRIG_SOFTWARE)")
  *         use function @ref LL_ADC_REG_IsTriggerSourceSWStart.
  * @note   Availability of parameters of trigger sources from timer 
  *         depends on timers availability on the selected device.
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_GetTriggerSource
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_REG_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH3       (1)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH1       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM4_CH4       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (2)(4)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH3       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH3       (3)
  *         
  *         (1) On STM32F1, parameter available on all ADC instances: ADC1, ADC2, ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (2) On STM32F1, parameter available only on ADC instances: ADC1, ADC2 (for ADC instances ADCx available on the selected device).\n
  *         (3) On STM32F1, parameter available only on ADC instances: ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (4) On STM32F1, parameter available only on high-density and XL-density devices. A remap of trigger must be done at top level (refer to AFIO peripheral).
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetTriggerSource(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_EXTSEL));
}

/**
  * @brief  Get ADC group regular conversion trigger source internal (SW start)
            or external.
  * @note   In case of group regular trigger source set to external trigger,
  *         to determine which peripheral is selected as external trigger,
  *         use function @ref LL_ADC_REG_GetTriggerSource().
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_IsTriggerSourceSWStart
  * @param  ADCx ADC instance
  * @retval Value "0" if trigger source external trigger
  *         Value "1" if trigger source SW start.
  */
__STATIC_INLINE uint32_t LL_ADC_REG_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  return (READ_BIT(ADCx->CR2, ADC_CR2_EXTSEL) == (LL_ADC_REG_TRIG_SOFTWARE));
}

