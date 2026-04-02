
/** @defgroup ADC_channels ADC channels
  * @{
  */
/* Note: Depending on devices, some channels may not be available on package  */
/*       pins. Refer to device datasheet for channels availability.           */
#define ADC_CHANNEL_0                       0x00000000U
#define ADC_CHANNEL_1           ((uint32_t)(                                                                    ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_2           ((uint32_t)(                                                   ADC_SQR3_SQ1_1                 ))
#define ADC_CHANNEL_3           ((uint32_t)(                                                   ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_4           ((uint32_t)(                                  ADC_SQR3_SQ1_2                                  ))
#define ADC_CHANNEL_5           ((uint32_t)(                                  ADC_SQR3_SQ1_2                  | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_6           ((uint32_t)(                                  ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1                 ))
#define ADC_CHANNEL_7           ((uint32_t)(                                  ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_8           ((uint32_t)(                 ADC_SQR3_SQ1_3                                                   ))
#define ADC_CHANNEL_9           ((uint32_t)(                 ADC_SQR3_SQ1_3                                   | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_10          ((uint32_t)(                 ADC_SQR3_SQ1_3                  | ADC_SQR3_SQ1_1                 ))
#define ADC_CHANNEL_11          ((uint32_t)(                 ADC_SQR3_SQ1_3                  | ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_12          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2                                  ))
#define ADC_CHANNEL_13          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2                  | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_14          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1                 ))
#define ADC_CHANNEL_15          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))
#define ADC_CHANNEL_16          ((uint32_t)(ADC_SQR3_SQ1_4                                                                    ))
#define ADC_CHANNEL_17          ((uint32_t)(ADC_SQR3_SQ1_4                                                    | ADC_SQR3_SQ1_0))

#define ADC_CHANNEL_TEMPSENSOR  ADC_CHANNEL_16  /* ADC internal channel (no connection on device pin) */
#define ADC_CHANNEL_VREFINT     ADC_CHANNEL_17  /* ADC internal channel (no connection on device pin) */
/**
  * @}
  */

/** @defgroup ADC_sampling_times ADC sampling times
  * @{
  */
#define ADC_SAMPLETIME_1CYCLE_5                   0x00000000U                                              /*!< Sampling time 1.5 ADC clock cycle */
#define ADC_SAMPLETIME_7CYCLES_5      ((uint32_t)(                                      ADC_SMPR2_SMP0_0)) /*!< Sampling time 7.5 ADC clock cycles */
#define ADC_SAMPLETIME_13CYCLES_5     ((uint32_t)(                   ADC_SMPR2_SMP0_1                   )) /*!< Sampling time 13.5 ADC clock cycles */
#define ADC_SAMPLETIME_28CYCLES_5     ((uint32_t)(                   ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)) /*!< Sampling time 28.5 ADC clock cycles */
#define ADC_SAMPLETIME_41CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2                                      )) /*!< Sampling time 41.5 ADC clock cycles */
#define ADC_SAMPLETIME_55CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2                    | ADC_SMPR2_SMP0_0)) /*!< Sampling time 55.5 ADC clock cycles */
#define ADC_SAMPLETIME_71CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1                   )) /*!< Sampling time 71.5 ADC clock cycles */
#define ADC_SAMPLETIME_239CYCLES_5    ((uint32_t)(ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)) /*!< Sampling time 239.5 ADC clock cycles */
/**
  * @}
  */

/** @defgroup ADC_regular_rank ADC rank into regular group
  * @{
  */
#define ADC_REGULAR_RANK_1                 0x00000001U
#define ADC_REGULAR_RANK_2                 0x00000002U
#define ADC_REGULAR_RANK_3                 0x00000003U
#define ADC_REGULAR_RANK_4                 0x00000004U
#define ADC_REGULAR_RANK_5                 0x00000005U
#define ADC_REGULAR_RANK_6                 0x00000006U
#define ADC_REGULAR_RANK_7                 0x00000007U
#define ADC_REGULAR_RANK_8                 0x00000008U
#define ADC_REGULAR_RANK_9                 0x00000009U
#define ADC_REGULAR_RANK_10                0x0000000AU
#define ADC_REGULAR_RANK_11                0x0000000BU
#define ADC_REGULAR_RANK_12                0x0000000CU
#define ADC_REGULAR_RANK_13                0x0000000DU
#define ADC_REGULAR_RANK_14                0x0000000EU
#define ADC_REGULAR_RANK_15                0x0000000FU
#define ADC_REGULAR_RANK_16                0x00000010U
/**
  * @}
  */

/** @defgroup ADC_analog_watchdog_mode ADC analog watchdog mode
  * @{
  */
#define ADC_ANALOGWATCHDOG_NONE                             0x00000000U
#define ADC_ANALOGWATCHDOG_SINGLE_REG           ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN))
#define ADC_ANALOGWATCHDOG_SINGLE_INJEC         ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_JAWDEN))
#define ADC_ANALOGWATCHDOG_SINGLE_REGINJEC      ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN))
#define ADC_ANALOGWATCHDOG_ALL_REG              ((uint32_t)ADC_CR1_AWDEN)
#define ADC_ANALOGWATCHDOG_ALL_INJEC            ((uint32_t)ADC_CR1_JAWDEN)
#define ADC_ANALOGWATCHDOG_ALL_REGINJEC         ((uint32_t)(ADC_CR1_AWDEN | ADC_CR1_JAWDEN))
/**
  * @}
  */

/** @defgroup ADC_conversion_group ADC conversion group
  * @{
  */
#define ADC_REGULAR_GROUP             ((uint32_t)(ADC_FLAG_EOC))
#define ADC_INJECTED_GROUP            ((uint32_t)(ADC_FLAG_JEOC))
#define ADC_REGULAR_INJECTED_GROUP    ((uint32_t)(ADC_FLAG_EOC | ADC_FLAG_JEOC))
/**
  * @}
  */

/** @defgroup ADC_Event_type ADC Event type
  * @{
  */
#define ADC_AWD_EVENT               ((uint32_t)ADC_FLAG_AWD)   /*!< ADC Analog watchdog event */

#define ADC_AWD1_EVENT              ADC_AWD_EVENT              /*!< ADC Analog watchdog 1 event: Alternate naming for compatibility with other STM32 devices having several analog watchdogs */
/**
  * @}
  */

/** @defgroup ADC_interrupts_definition ADC interrupts definition
  * @{
  */
#define ADC_IT_EOC           ADC_CR1_EOCIE        /*!< ADC End of Regular Conversion interrupt source */
#define ADC_IT_JEOC          ADC_CR1_JEOCIE       /*!< ADC End of Injected Conversion interrupt source */
#define ADC_IT_AWD           ADC_CR1_AWDIE        /*!< ADC Analog watchdog interrupt source */
/**
  * @}
  */

/** @defgroup ADC_flags_definition ADC flags definition
  * @{
  */
#define ADC_FLAG_STRT          ADC_SR_STRT     /*!< ADC Regular group start flag */
#define ADC_FLAG_JSTRT         ADC_SR_JSTRT    /*!< ADC Injected group start flag */
#define ADC_FLAG_EOC           ADC_SR_EOC      /*!< ADC End of Regular conversion flag */
#define ADC_FLAG_JEOC          ADC_SR_JEOC     /*!< ADC End of Injected conversion flag */
#define ADC_FLAG_AWD           ADC_SR_AWD      /*!< ADC Analog watchdog flag */
/**
  * @}
  */


/**
  * @}
  */ 

/* Private constants ---------------------------------------------------------*/

/** @addtogroup ADC_Private_Constants ADC Private Constants
  * @{
  */

/** @defgroup ADC_conversion_cycles ADC conversion cycles
  * @{
  */
/* ADC conversion cycles (unit: ADC clock cycles)                           */
/* (selected sampling time + conversion time of 12.5 ADC clock cycles, with */
/* resolution 12 bits)                                                      */
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_1CYCLE5                  14U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_7CYCLES5                 20U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_13CYCLES5                26U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_28CYCLES5                41U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_41CYCLES5                54U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_55CYCLES5                68U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_71CYCLES5                84U
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_239CYCLES5              252U
/**
  * @}
  */

/** @defgroup ADC_sampling_times_all_channels ADC sampling times all channels
  * @{
  */
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2                                          \
     (ADC_SMPR2_SMP9_2 | ADC_SMPR2_SMP8_2 | ADC_SMPR2_SMP7_2 | ADC_SMPR2_SMP6_2 |     \
      ADC_SMPR2_SMP5_2 | ADC_SMPR2_SMP4_2 | ADC_SMPR2_SMP3_2 | ADC_SMPR2_SMP2_2 |     \
      ADC_SMPR2_SMP1_2 | ADC_SMPR2_SMP0_2)
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2                                          \
     (ADC_SMPR1_SMP17_2 | ADC_SMPR1_SMP16_2 | ADC_SMPR1_SMP15_2 | ADC_SMPR1_SMP14_2 | \
      ADC_SMPR1_SMP13_2 | ADC_SMPR1_SMP12_2 | ADC_SMPR1_SMP11_2 | ADC_SMPR1_SMP10_2 )

#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1                                          \
     (ADC_SMPR2_SMP9_1 | ADC_SMPR2_SMP8_1 | ADC_SMPR2_SMP7_1 | ADC_SMPR2_SMP6_1 |     \
      ADC_SMPR2_SMP5_1 | ADC_SMPR2_SMP4_1 | ADC_SMPR2_SMP3_1 | ADC_SMPR2_SMP2_1 |     \
      ADC_SMPR2_SMP1_1 | ADC_SMPR2_SMP0_1)
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1                                          \
     (ADC_SMPR1_SMP17_1 | ADC_SMPR1_SMP16_1 | ADC_SMPR1_SMP15_1 | ADC_SMPR1_SMP14_1 | \
      ADC_SMPR1_SMP13_1 | ADC_SMPR1_SMP12_1 | ADC_SMPR1_SMP11_1 | ADC_SMPR1_SMP10_1 )

#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0                                          \
     (ADC_SMPR2_SMP9_0 | ADC_SMPR2_SMP8_0 | ADC_SMPR2_SMP7_0 | ADC_SMPR2_SMP6_0 |     \
      ADC_SMPR2_SMP5_0 | ADC_SMPR2_SMP4_0 | ADC_SMPR2_SMP3_0 | ADC_SMPR2_SMP2_0 |     \
      ADC_SMPR2_SMP1_0 | ADC_SMPR2_SMP0_0)
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0                                          \
     (ADC_SMPR1_SMP17_0 | ADC_SMPR1_SMP16_0 | ADC_SMPR1_SMP15_0 | ADC_SMPR1_SMP14_0 | \
      ADC_SMPR1_SMP13_0 | ADC_SMPR1_SMP12_0 | ADC_SMPR1_SMP11_0 | ADC_SMPR1_SMP10_0 )

#define ADC_SAMPLETIME_1CYCLE5_SMPR2ALLCHANNELS    0x00000000U
#define ADC_SAMPLETIME_7CYCLES5_SMPR2ALLCHANNELS   (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
#define ADC_SAMPLETIME_13CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1)
#define ADC_SAMPLETIME_28CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
#define ADC_SAMPLETIME_41CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2)
#define ADC_SAMPLETIME_55CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
#define ADC_SAMPLETIME_71CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1)
#define ADC_SAMPLETIME_239CYCLES5_SMPR2ALLCHANNELS (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)

#define ADC_SAMPLETIME_1CYCLE5_SMPR1ALLCHANNELS    0x00000000U
#define ADC_SAMPLETIME_7CYCLES5_SMPR1ALLCHANNELS   (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
#define ADC_SAMPLETIME_13CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1)
#define ADC_SAMPLETIME_28CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
#define ADC_SAMPLETIME_41CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2)
#define ADC_SAMPLETIME_55CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
#define ADC_SAMPLETIME_71CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1)
#define ADC_SAMPLETIME_239CYCLES5_SMPR1ALLCHANNELS (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
/**
  * @}
  */

/* Combination of all post-conversion flags bits: EOC/EOS, JEOC/JEOS, OVR, AWDx */
#define ADC_FLAG_POSTCONV_ALL   (ADC_FLAG_EOC | ADC_FLAG_JEOC | ADC_FLAG_AWD )

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/

/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */
/* Macro for internal HAL driver usage, and possibly can be used into code of */
/* final user.                                                                */    

/**
  * @brief Enable the ADC peripheral
  * @note ADC enable requires a delay for ADC stabilization time
  *       (refer to device datasheet, parameter tSTAB)
  * @note On STM32F1, if ADC is already enabled this macro trigs a conversion 
  *       SW start on regular group.
  * @param __HANDLE__: ADC handle
  * @retval None
  */
#define __HAL_ADC_ENABLE(__HANDLE__)                                           \
  (SET_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADON)))
    
/**
  * @brief Disable the ADC peripheral
  * @param __HANDLE__: ADC handle
  * @retval None
  */
#define __HAL_ADC_DISABLE(__HANDLE__)                                          \
  (CLEAR_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADON)))
    
/** @brief Enable the ADC end of conversion interrupt.
  * @param __HANDLE__: ADC handle
  * @param __INTERRUPT__: ADC Interrupt
  *          This parameter can be any combination of the following values:
  *            @arg ADC_IT_EOC: ADC End of Regular Conversion interrupt source
  *            @arg ADC_IT_JEOC: ADC End of Injected Conversion interrupt source
  *            @arg ADC_IT_AWD: ADC Analog watchdog interrupt source
  * @retval None
  */
#define __HAL_ADC_ENABLE_IT(__HANDLE__, __INTERRUPT__)                         \
  (SET_BIT((__HANDLE__)->Instance->CR1, (__INTERRUPT__)))
    
/** @brief Disable the ADC end of conversion interrupt.
  * @param __HANDLE__: ADC handle
  * @param __INTERRUPT__: ADC Interrupt
  *          This parameter can be any combination of the following values:
  *            @arg ADC_IT_EOC: ADC End of Regular Conversion interrupt source
  *            @arg ADC_IT_JEOC: ADC End of Injected Conversion interrupt source
  *            @arg ADC_IT_AWD: ADC Analog watchdog interrupt source
  * @retval None
  */
#define __HAL_ADC_DISABLE_IT(__HANDLE__, __INTERRUPT__)                        \
  (CLEAR_BIT((__HANDLE__)->Instance->CR1, (__INTERRUPT__)))

/** @brief  Checks if the specified ADC interrupt source is enabled or disabled.
  * @param __HANDLE__: ADC handle
  * @param __INTERRUPT__: ADC interrupt source to check
  *          This parameter can be any combination of the following values:
  *            @arg ADC_IT_EOC: ADC End of Regular Conversion interrupt source
  *            @arg ADC_IT_JEOC: ADC End of Injected Conversion interrupt source
  *            @arg ADC_IT_AWD: ADC Analog watchdog interrupt source
  * @retval None
  */
#define __HAL_ADC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)                     \
  (((__HANDLE__)->Instance->CR1 & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief Get the selected ADC's flag status.
  * @param __HANDLE__: ADC handle
  * @param __FLAG__: ADC flag
  *          This parameter can be any combination of the following values:
  *            @arg ADC_FLAG_STRT: ADC Regular group start flag
  *            @arg ADC_FLAG_JSTRT: ADC Injected group start flag
  *            @arg ADC_FLAG_EOC: ADC End of Regular conversion flag
  *            @arg ADC_FLAG_JEOC: ADC End of Injected conversion flag
  *            @arg ADC_FLAG_AWD: ADC Analog watchdog flag
  * @retval None
  */
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__)                               \
  ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__))
    
/** @brief Clear the ADC's pending flags
  * @param __HANDLE__: ADC handle
  * @param __FLAG__: ADC flag
  *          This parameter can be any combination of the following values:
  *            @arg ADC_FLAG_STRT: ADC Regular group start flag
  *            @arg ADC_FLAG_JSTRT: ADC Injected group start flag
  *            @arg ADC_FLAG_EOC: ADC End of Regular conversion flag
  *            @arg ADC_FLAG_JEOC: ADC End of Injected conversion flag
  *            @arg ADC_FLAG_AWD: ADC Analog watchdog flag
  * @retval None
  */
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__)                             \
  (WRITE_REG((__HANDLE__)->Instance->SR, ~(__FLAG__)))

/** @brief  Reset ADC handle state
  * @param  __HANDLE__: ADC handle
  * @retval None
  */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  do{                                                                          \
     (__HANDLE__)->State = HAL_ADC_STATE_RESET;                                \
     (__HANDLE__)->MspInitCallback = NULL;                                     \
     (__HANDLE__)->MspDeInitCallback = NULL;                                   \
    } while(0)
#else
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET)
#endif

/**
  * @}
  */

/* Private macro ------------------------------------------------------------*/

/** @defgroup ADC_Private_Macros ADC Private Macros
  * @{
  */
/* Macro reserved for internal HAL driver usage, not intended to be used in   */
/* code of final user.                                                        */

/**
  * @brief Verification of ADC state: enabled or disabled
  * @param __HANDLE__: ADC handle
  * @retval SET (ADC enabled) or RESET (ADC disabled)
  */
#define ADC_IS_ENABLE(__HANDLE__)                                              \
  ((( ((__HANDLE__)->Instance->CR2 & ADC_CR2_ADON) == ADC_CR2_ADON )           \
   ) ? SET : RESET)

/**
  * @brief Test if conversion trigger of regular group is software start
  *        or external trigger.
  * @param __HANDLE__: ADC handle
  * @retval SET (software start) or RESET (external trigger)
  */
#define ADC_IS_SOFTWARE_START_REGULAR(__HANDLE__)                              \
  (READ_BIT((__HANDLE__)->Instance->CR2, ADC_CR2_EXTSEL) == ADC_SOFTWARE_START)

/**
  * @brief Test if conversion trigger of injected group is software start
  *        or external trigger.
  * @param __HANDLE__: ADC handle
  * @retval SET (software start) or RESET (external trigger)
  */
#define ADC_IS_SOFTWARE_START_INJECTED(__HANDLE__)                             \
  (READ_BIT((__HANDLE__)->Instance->CR2, ADC_CR2_JEXTSEL) == ADC_INJECTED_SOFTWARE_START)

/**
  * @brief Simultaneously clears and sets specific bits of the handle State
  * @note: ADC_STATE_CLR_SET() macro is merely aliased to generic macro MODIFY_REG(),
  *        the first parameter is the ADC handle State, the second parameter is the
  *        bit field to clear, the third and last parameter is the bit field to set.
  * @retval None
  */
#define ADC_STATE_CLR_SET MODIFY_REG

/**
  * @brief Clear ADC error code (set it to error code: "no error")
  * @param __HANDLE__: ADC handle
  * @retval None
  */
#define ADC_CLEAR_ERRORCODE(__HANDLE__)                                        \
  ((__HANDLE__)->ErrorCode = HAL_ADC_ERROR_NONE)

/**
  * @brief Set ADC number of conversions into regular channel sequence length.
  * @param _NbrOfConversion_: Regular channel sequence length 
  * @retval None
  */
#define ADC_SQR1_L_SHIFT(_NbrOfConversion_)                                    \
  (((_NbrOfConversion_) - (uint8_t)1) << ADC_SQR1_L_Pos)

/**
  * @brief Set the ADC's sample time for channel numbers between 10 and 18.
  * @param _SAMPLETIME_: Sample time parameter.
  * @param _CHANNELNB_: Channel number.  
  * @retval None
  */
#define ADC_SMPR1(_SAMPLETIME_, _CHANNELNB_)                                   \
  ((_SAMPLETIME_) << (ADC_SMPR1_SMP11_Pos * ((_CHANNELNB_) - 10)))
