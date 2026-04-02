
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** @defgroup ADCEx_Common_mode ADC Extended Dual ADC Mode
  * @{
  */
#define ADC_MODE_INDEPENDENT                              0x00000000U                                                                     /*!< ADC dual mode disabled (ADC independent mode) */
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT    ((uint32_t)(                                                            ADC_CR1_DUALMOD_0)) /*!< ADC dual mode enabled: Combined regular simultaneous + injected simultaneous mode, on groups regular and injected */
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG      ((uint32_t)(                                        ADC_CR1_DUALMOD_1                    )) /*!< ADC dual mode enabled: Combined regular simultaneous + alternate trigger mode, on groups regular and injected */
#define ADC_DUALMODE_INJECSIMULT_INTERLFAST   ((uint32_t)(                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0)) /*!< ADC dual mode enabled: Combined injected simultaneous + fast interleaved mode, on groups regular and injected (delay between ADC sampling phases: 7 ADC clock cycles (equivalent to parameter "TwoSamplingDelay" set to "ADC_TWOSAMPLINGDELAY_7CYCLES" on other STM32 devices)) */
#define ADC_DUALMODE_INJECSIMULT_INTERLSLOW   ((uint32_t)(                    ADC_CR1_DUALMOD_2                                        )) /*!< ADC dual mode enabled: Combined injected simultaneous + slow Interleaved mode, on groups regular and injected (delay between ADC sampling phases: 14 ADC clock cycles (equivalent to parameter "TwoSamplingDelay" set to "ADC_TWOSAMPLINGDELAY_7CYCLES" on other STM32 devices)) */
#define ADC_DUALMODE_INJECSIMULT              ((uint32_t)(                    ADC_CR1_DUALMOD_2 |                     ADC_CR1_DUALMOD_0)) /*!< ADC dual mode enabled: Injected simultaneous mode, on group injected */
#define ADC_DUALMODE_REGSIMULT                ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    )) /*!< ADC dual mode enabled: Regular simultaneous mode, on group regular */
#define ADC_DUALMODE_INTERLFAST               ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0)) /*!< ADC dual mode enabled: Fast interleaved mode, on group regular (delay between ADC sampling phases: 7 ADC clock cycles (equivalent to parameter "TwoSamplingDelay" set to "ADC_TWOSAMPLINGDELAY_7CYCLES" on other STM32 devices)) */
#define ADC_DUALMODE_INTERLSLOW               ((uint32_t)(ADC_CR1_DUALMOD_3                                                            )) /*!< ADC dual mode enabled: Slow interleaved mode, on group regular (delay between ADC sampling phases: 14 ADC clock cycles (equivalent to parameter "TwoSamplingDelay" set to "ADC_TWOSAMPLINGDELAY_7CYCLES" on other STM32 devices)) */
#define ADC_DUALMODE_ALTERTRIG                ((uint32_t)(ADC_CR1_DUALMOD_3 |                                         ADC_CR1_DUALMOD_0)) /*!< ADC dual mode enabled: Alternate trigger mode, on group injected */
/**
  * @}
  */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* Private constants ---------------------------------------------------------*/

/** @addtogroup ADCEx_Private_Constants ADCEx Private Constants
  * @{
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Regular ADC Extended Internal HAL driver trigger selection for regular group
  * @{
  */
/* List of external triggers of regular group for ADC1, ADC2, ADC3 (if ADC    */
/* instance is available on the selected device).                             */
/* (used internally by HAL driver. To not use into HAL structure parameters)  */

/* External triggers of regular group for ADC1&ADC2 (if ADCx available) */
#define ADC1_2_EXTERNALTRIG_T1_CC1                       0x00000000U
#define ADC1_2_EXTERNALTRIG_T1_CC2           ((uint32_t)(                                      ADC_CR2_EXTSEL_0))
#define ADC1_2_EXTERNALTRIG_T2_CC2           ((uint32_t)(                   ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
#define ADC1_2_EXTERNALTRIG_T3_TRGO          ((uint32_t)(ADC_CR2_EXTSEL_2                                      ))
#define ADC1_2_EXTERNALTRIG_T4_CC4           ((uint32_t)(ADC_CR2_EXTSEL_2 |                    ADC_CR2_EXTSEL_0))
#define ADC1_2_EXTERNALTRIG_EXT_IT11         ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1                   ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* Note: TIM8_TRGO is available on ADC1 and ADC2 only in high-density and     */
/* XL-density devices.                                                        */
#define ADC1_2_EXTERNALTRIG_T8_TRGO          ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* External triggers of regular group for ADC3 */
#define ADC3_EXTERNALTRIG_T3_CC1             ADC1_2_EXTERNALTRIG_T1_CC1
#define ADC3_EXTERNALTRIG_T2_CC3             ADC1_2_EXTERNALTRIG_T1_CC2
#define ADC3_EXTERNALTRIG_T8_CC1             ADC1_2_EXTERNALTRIG_T2_CC2
#define ADC3_EXTERNALTRIG_T8_TRGO            ADC1_2_EXTERNALTRIG_T3_TRGO
#define ADC3_EXTERNALTRIG_T5_CC1             ADC1_2_EXTERNALTRIG_T4_CC4
#define ADC3_EXTERNALTRIG_T5_CC3             ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

/* External triggers of regular group for ADC1&ADC2&ADC3 (if ADCx available) */
#define ADC1_2_3_EXTERNALTRIG_T1_CC3         ((uint32_t)(                   ADC_CR2_EXTSEL_1                   ))
#define ADC1_2_3_SWSTART                     ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/**
  * @}
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Injected ADC Extended Internal HAL driver trigger selection for injected group
  * @{
  */
/* List of external triggers of injected group for ADC1, ADC2, ADC3 (if ADC    */
/* instance is available on the selected device).                             */
/* (used internally by HAL driver. To not use into HAL structure parameters)  */

/* External triggers of injected group for ADC1&ADC2 (if ADCx available) */
#define ADC1_2_EXTERNALTRIGINJEC_T2_TRGO          ((uint32_t)(                    ADC_CR2_JEXTSEL_1                    ))
#define ADC1_2_EXTERNALTRIGINJEC_T2_CC1           ((uint32_t)(                    ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
#define ADC1_2_EXTERNALTRIGINJEC_T3_CC4           ((uint32_t)(ADC_CR2_JEXTSEL_2                                        ))
#define ADC1_2_EXTERNALTRIGINJEC_T4_TRGO          ((uint32_t)(ADC_CR2_JEXTSEL_2 |                     ADC_CR2_JEXTSEL_0))
#define ADC1_2_EXTERNALTRIGINJEC_EXT_IT15         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1                    ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* Note: TIM8_CC4 is available on ADC1 and ADC2 only in high-density and      */
/* XL-density devices.                                                        */
#define ADC1_2_EXTERNALTRIGINJEC_T8_CC4           ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* External triggers of injected group for ADC3 */
#define ADC3_EXTERNALTRIGINJEC_T4_CC3             ADC1_2_EXTERNALTRIGINJEC_T2_TRGO
#define ADC3_EXTERNALTRIGINJEC_T8_CC2             ADC1_2_EXTERNALTRIGINJEC_T2_CC1
#define ADC3_EXTERNALTRIGINJEC_T8_CC4             ADC1_2_EXTERNALTRIGINJEC_T3_CC4
#define ADC3_EXTERNALTRIGINJEC_T5_TRGO            ADC1_2_EXTERNALTRIGINJEC_T4_TRGO
#define ADC3_EXTERNALTRIGINJEC_T5_CC4             ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif /* STM32F103xE || defined STM32F103xG */

/* External triggers of injected group for ADC1&ADC2&ADC3 (if ADCx available) */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO                    0x00000000U
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4         ((uint32_t)(                                        ADC_CR2_JEXTSEL_0))
#define ADC1_2_3_JSWSTART                         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/** @defgroup ADCEx_Private_Macro ADCEx Private Macro
  * @{
  */
/* Macro reserved for internal HAL driver usage, not intended to be used in   */
/* code of final user.                                                        */

    
/**
  * @brief For devices with 3 ADCs: Defines the external trigger source 
  *        for regular group according to ADC into common group ADC1&ADC2 or 
  *        ADC3 (some triggers with same source have different value to
  *        be programmed into ADC EXTSEL bits of CR2 register).
  *        For devices with 2 ADCs or less: this macro makes no change.
  * @param __HANDLE__: ADC handle
  * @param __EXT_TRIG_CONV__: External trigger selected for regular group.
  * @retval External trigger to be programmed into EXTSEL bits of CR2 register
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
 (( (((__HANDLE__)->Instance) == ADC3)                                         \
  )?                                                                           \
   ( ( (__EXT_TRIG_CONV__) == ADC_EXTERNALTRIGCONV_T8_TRGO                     \
     )?                                                                        \
      (ADC3_EXTERNALTRIG_T8_TRGO)                                              \
      :                                                                        \
      (__EXT_TRIG_CONV__)                                                      \
   )                                                                           \
   :                                                                           \
   (__EXT_TRIG_CONV__)                                                         \
 )
#else
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
  (__EXT_TRIG_CONV__)
#endif /* STM32F103xE || STM32F103xG */

/**
  * @brief For devices with 3 ADCs: Defines the external trigger source 
  *        for injected group according to ADC into common group ADC1&ADC2 or 
  *        ADC3 (some triggers with same source have different value to
  *        be programmed into ADC JEXTSEL bits of CR2 register).
  *        For devices with 2 ADCs or less: this macro makes no change.
  * @param __HANDLE__: ADC handle
  * @param __EXT_TRIG_INJECTCONV__: External trigger selected for injected group.
  * @retval External trigger to be programmed into JEXTSEL bits of CR2 register
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
 (( (((__HANDLE__)->Instance) == ADC3)                                         \
  )?                                                                           \
   ( ( (__EXT_TRIG_INJECTCONV__) == ADC_EXTERNALTRIGINJECCONV_T8_CC4           \
     )?                                                                        \
      (ADC3_EXTERNALTRIGINJEC_T8_CC4)                                          \
      :                                                                        \
      (__EXT_TRIG_INJECTCONV__)                                                \
   )                                                                           \
   :                                                                           \
   (__EXT_TRIG_INJECTCONV__)                                                   \
 )
#else
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
   (__EXT_TRIG_INJECTCONV__)
#endif /* STM32F103xE || STM32F103xG */


/**
  * @brief Verification if multimode is enabled for the selected ADC (multimode ADC master or ADC slave) (applicable for devices with several ADCs)
  * @param __HANDLE__: ADC handle
  * @retval Multimode state: RESET if multimode is disabled, other value if multimode is enabled
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
 (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)   \
  )?                                                                           \
   (ADC1->CR1 & ADC_CR1_DUALMOD)                                               \
   :                                                                           \
   (RESET)                                                                     \
 )
#else
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief Verification of condition for ADC start conversion: ADC must be in non-multimode, or multimode with handle of ADC master (applicable for devices with several ADCs)
  * @param __HANDLE__: ADC handle
  * @retval None
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (( (((__HANDLE__)->Instance) == ADC2)                                        \
   )?                                                                          \
    ((ADC1->CR1 & ADC_CR1_DUALMOD) == RESET)                                   \
    :                                                                          \
    (!RESET)                                                                   \
  )
#else
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (!RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief Check ADC multimode setting: In case of multimode, check whether ADC master of the selected ADC has feature auto-injection enabled (applicable for devices with several ADCs)
  * @param __HANDLE__: ADC handle
  * @retval None
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)  \
   )?                                                                          \
    (ADC1->CR1 & ADC_CR1_JAUTO)                                                \
    :                                                                          \
    (RESET)                                                                    \
  )
#else
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief Set handle of the other ADC sharing the common multimode settings
  * @param __HANDLE__: ADC handle
  * @param __HANDLE_OTHER_ADC__: other ADC handle
  * @retval None
  */
#define ADC_COMMON_ADC_OTHER(__HANDLE__, __HANDLE_OTHER_ADC__)                 \
  ((__HANDLE_OTHER_ADC__)->Instance = ADC2)

/**
  * @brief Set handle of the ADC slave associated to the ADC master
  * On STM32F1 devices, ADC slave is always ADC2 (this can be different
  * on other STM32 devices)
  * @param __HANDLE_MASTER__: ADC master handle
  * @param __HANDLE_SLAVE__: ADC slave handle
  * @retval None
  */
#define ADC_MULTI_SLAVE(__HANDLE_MASTER__, __HANDLE_SLAVE__)                   \
  ((__HANDLE_SLAVE__)->Instance = ADC2)
       
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

#define IS_ADC_INJECTED_RANK(CHANNEL) (((CHANNEL) == ADC_INJECTED_RANK_1) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_2) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_3) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_4))

#define IS_ADC_EXTTRIGINJEC_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)  || \
                                        ((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING))

/** @defgroup ADCEx_injected_nb_conv_verification ADCEx injected nb conv verification
  * @{
  */
#define IS_ADC_INJECTED_NB_CONV(LENGTH)  (((LENGTH) >= 1U) && ((LENGTH) <= 4U))
/**
  * @}
  */
