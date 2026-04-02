
/** @defgroup HAL_RTC_Aliased_Functions HAL RTC Aliased Functions maintained for legacy purpose
  * @{
  */
#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
#define HAL_RTCEx_SetBoothardwareKey            HAL_RTCEx_LockBootHardwareKey
#define HAL_RTCEx_BKUPBlock_Enable              HAL_RTCEx_BKUPBlock
#define HAL_RTCEx_BKUPBlock_Disable             HAL_RTCEx_BKUPUnblock
#define HAL_RTCEx_Erase_SecretDev_Conf          HAL_RTCEx_ConfigEraseDeviceSecrets
#endif /* STM32H5 || STM32WBA || STM32H7RS */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Functions HAL SMBUS Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_SMBUS_Slave_Listen_IT          HAL_SMBUS_EnableListen_IT
#define HAL_SMBUS_SlaveAddrCallback        HAL_SMBUS_AddrCallback
#define HAL_SMBUS_SlaveListenCpltCallback  HAL_SMBUS_ListenCpltCallback
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Functions HAL SPI Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_SPI_FlushRxFifo                HAL_SPIEx_FlushRxFifo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Functions HAL TIM Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_TIM_DMADelayPulseCplt                       TIM_DMADelayPulseCplt
#define HAL_TIM_DMAError                                TIM_DMAError
#define HAL_TIM_DMACaptureCplt                          TIM_DMACaptureCplt
#define HAL_TIMEx_DMACommutationCplt                    TIMEx_DMACommutationCplt
#if defined(STM32H7) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || \
    defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || defined(STM32L4)
#define HAL_TIM_SlaveConfigSynchronization              HAL_TIM_SlaveConfigSynchro
#define HAL_TIM_SlaveConfigSynchronization_IT           HAL_TIM_SlaveConfigSynchro_IT
#define HAL_TIMEx_CommutationCallback                   HAL_TIMEx_CommutCallback
#define HAL_TIMEx_ConfigCommutationEvent                HAL_TIMEx_ConfigCommutEvent
#define HAL_TIMEx_ConfigCommutationEvent_IT             HAL_TIMEx_ConfigCommutEvent_IT
#define HAL_TIMEx_ConfigCommutationEvent_DMA            HAL_TIMEx_ConfigCommutEvent_DMA
#endif /* STM32H7 || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Functions HAL UART Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_UART_WakeupCallback HAL_UARTEx_WakeupCallback
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Functions HAL LTDC Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_LTDC_LineEvenCallback HAL_LTDC_LineEventCallback
#define HAL_LTDC_Relaod           HAL_LTDC_Reload
#define HAL_LTDC_StructInitFromVideoConfig  HAL_LTDCEx_StructInitFromVideoConfig
#define HAL_LTDC_StructInitFromAdaptedCommandConfig  HAL_LTDCEx_StructInitFromAdaptedCommandConfig
/**
  * @}
  */


/** @defgroup HAL_PPP_Aliased_Functions HAL PPP Aliased Functions maintained for legacy purpose
  * @{
  */

/**
  * @}
  */

/* Exported macros ------------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Macros HAL CRYP Aliased Macros maintained for legacy purpose
  * @{
  */
#define AES_IT_CC                      CRYP_IT_CC
#define AES_IT_ERR                     CRYP_IT_ERR
#define AES_FLAG_CCF                   CRYP_FLAG_CCF
/**
  * @}
  */

/** @defgroup HAL_Aliased_Macros HAL Generic Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_GET_BOOT_MODE                   __HAL_SYSCFG_GET_BOOT_MODE
#define __HAL_REMAPMEMORY_FLASH               __HAL_SYSCFG_REMAPMEMORY_FLASH
#define __HAL_REMAPMEMORY_SYSTEMFLASH         __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH
#define __HAL_REMAPMEMORY_SRAM                __HAL_SYSCFG_REMAPMEMORY_SRAM
#define __HAL_REMAPMEMORY_FMC                 __HAL_SYSCFG_REMAPMEMORY_FMC
#define __HAL_REMAPMEMORY_FMC_SDRAM           __HAL_SYSCFG_REMAPMEMORY_FMC_SDRAM
#define __HAL_REMAPMEMORY_FSMC                __HAL_SYSCFG_REMAPMEMORY_FSMC
#define __HAL_REMAPMEMORY_QUADSPI             __HAL_SYSCFG_REMAPMEMORY_QUADSPI
#define __HAL_FMC_BANK                        __HAL_SYSCFG_FMC_BANK
#define __HAL_GET_FLAG                        __HAL_SYSCFG_GET_FLAG
#define __HAL_CLEAR_FLAG                      __HAL_SYSCFG_CLEAR_FLAG
#define __HAL_VREFINT_OUT_ENABLE              __HAL_SYSCFG_VREFINT_OUT_ENABLE
#define __HAL_VREFINT_OUT_DISABLE             __HAL_SYSCFG_VREFINT_OUT_DISABLE
#define __HAL_SYSCFG_SRAM2_WRP_ENABLE         __HAL_SYSCFG_SRAM2_WRP_0_31_ENABLE

#define SYSCFG_FLAG_VREF_READY                SYSCFG_FLAG_VREFINT_READY
#define SYSCFG_FLAG_RC48                      RCC_FLAG_HSI48
#define IS_SYSCFG_FASTMODEPLUS_CONFIG         IS_I2C_FASTMODEPLUS
#define UFB_MODE_BitNumber                    UFB_MODE_BIT_NUMBER
#define CMP_PD_BitNumber                      CMP_PD_BIT_NUMBER

/**
  * @}
  */


/** @defgroup HAL_ADC_Aliased_Macros HAL ADC Aliased Macros maintained for legacy purpose
  * @{
  */
#define __ADC_ENABLE                                     __HAL_ADC_ENABLE
#define __ADC_DISABLE                                    __HAL_ADC_DISABLE
#define __HAL_ADC_ENABLING_CONDITIONS                    ADC_ENABLING_CONDITIONS
#define __HAL_ADC_DISABLING_CONDITIONS                   ADC_DISABLING_CONDITIONS
#define __HAL_ADC_IS_ENABLED                             ADC_IS_ENABLE
#define __ADC_IS_ENABLED                                 ADC_IS_ENABLE
#define __HAL_ADC_IS_SOFTWARE_START_REGULAR              ADC_IS_SOFTWARE_START_REGULAR
#define __HAL_ADC_IS_SOFTWARE_START_INJECTED             ADC_IS_SOFTWARE_START_INJECTED
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR          ADC_IS_CONVERSION_ONGOING_REGULAR
#define __HAL_ADC_IS_CONVERSION_ONGOING_INJECTED         ADC_IS_CONVERSION_ONGOING_INJECTED
#define __HAL_ADC_IS_CONVERSION_ONGOING                  ADC_IS_CONVERSION_ONGOING
#define __HAL_ADC_CLEAR_ERRORCODE                        ADC_CLEAR_ERRORCODE

#define __HAL_ADC_GET_RESOLUTION                         ADC_GET_RESOLUTION
#define __HAL_ADC_JSQR_RK                                ADC_JSQR_RK
#define __HAL_ADC_CFGR_AWD1CH                            ADC_CFGR_AWD1CH_SHIFT
#define __HAL_ADC_CFGR_AWD23CR                           ADC_CFGR_AWD23CR
#define __HAL_ADC_CFGR_INJECT_AUTO_CONVERSION            ADC_CFGR_INJECT_AUTO_CONVERSION
#define __HAL_ADC_CFGR_INJECT_CONTEXT_QUEUE              ADC_CFGR_INJECT_CONTEXT_QUEUE
#define __HAL_ADC_CFGR_INJECT_DISCCONTINUOUS             ADC_CFGR_INJECT_DISCCONTINUOUS
#define __HAL_ADC_CFGR_REG_DISCCONTINUOUS                ADC_CFGR_REG_DISCCONTINUOUS
#define __HAL_ADC_CFGR_DISCONTINUOUS_NUM                 ADC_CFGR_DISCONTINUOUS_NUM
#define __HAL_ADC_CFGR_AUTOWAIT                          ADC_CFGR_AUTOWAIT
#define __HAL_ADC_CFGR_CONTINUOUS                        ADC_CFGR_CONTINUOUS
#define __HAL_ADC_CFGR_OVERRUN                           ADC_CFGR_OVERRUN
#define __HAL_ADC_CFGR_DMACONTREQ                        ADC_CFGR_DMACONTREQ
#define __HAL_ADC_CFGR_EXTSEL                            ADC_CFGR_EXTSEL_SET
#define __HAL_ADC_JSQR_JEXTSEL                           ADC_JSQR_JEXTSEL_SET
#define __HAL_ADC_OFR_CHANNEL                            ADC_OFR_CHANNEL
#define __HAL_ADC_DIFSEL_CHANNEL                         ADC_DIFSEL_CHANNEL
#define __HAL_ADC_CALFACT_DIFF_SET                       ADC_CALFACT_DIFF_SET
#define __HAL_ADC_CALFACT_DIFF_GET                       ADC_CALFACT_DIFF_GET
#define __HAL_ADC_TRX_HIGHTHRESHOLD                      ADC_TRX_HIGHTHRESHOLD

#define __HAL_ADC_OFFSET_SHIFT_RESOLUTION                ADC_OFFSET_SHIFT_RESOLUTION
#define __HAL_ADC_AWD1THRESHOLD_SHIFT_RESOLUTION         ADC_AWD1THRESHOLD_SHIFT_RESOLUTION
#define __HAL_ADC_AWD23THRESHOLD_SHIFT_RESOLUTION        ADC_AWD23THRESHOLD_SHIFT_RESOLUTION
#define __HAL_ADC_COMMON_REGISTER                        ADC_COMMON_REGISTER
#define __HAL_ADC_COMMON_CCR_MULTI                       ADC_COMMON_CCR_MULTI
#define __HAL_ADC_MULTIMODE_IS_ENABLED                   ADC_MULTIMODE_IS_ENABLE
#define __ADC_MULTIMODE_IS_ENABLED                       ADC_MULTIMODE_IS_ENABLE
#define __HAL_ADC_NONMULTIMODE_OR_MULTIMODEMASTER        ADC_NONMULTIMODE_OR_MULTIMODEMASTER
#define __HAL_ADC_COMMON_ADC_OTHER                       ADC_COMMON_ADC_OTHER
#define __HAL_ADC_MULTI_SLAVE                            ADC_MULTI_SLAVE

#define __HAL_ADC_SQR1_L                                 ADC_SQR1_L_SHIFT
#define __HAL_ADC_JSQR_JL                                ADC_JSQR_JL_SHIFT
#define __HAL_ADC_JSQR_RK_JL                             ADC_JSQR_RK_JL
#define __HAL_ADC_CR1_DISCONTINUOUS_NUM                  ADC_CR1_DISCONTINUOUS_NUM
#define __HAL_ADC_CR1_SCAN                               ADC_CR1_SCAN_SET
#define __HAL_ADC_CONVCYCLES_MAX_RANGE                   ADC_CONVCYCLES_MAX_RANGE
#define __HAL_ADC_CLOCK_PRESCALER_RANGE                  ADC_CLOCK_PRESCALER_RANGE
#define __HAL_ADC_GET_CLOCK_PRESCALER                    ADC_GET_CLOCK_PRESCALER

#define __HAL_ADC_SQR1                                   ADC_SQR1
#define __HAL_ADC_SMPR1                                  ADC_SMPR1
#define __HAL_ADC_SMPR2                                  ADC_SMPR2
#define __HAL_ADC_SQR3_RK                                ADC_SQR3_RK
#define __HAL_ADC_SQR2_RK                                ADC_SQR2_RK
#define __HAL_ADC_SQR1_RK                                ADC_SQR1_RK
#define __HAL_ADC_CR2_CONTINUOUS                         ADC_CR2_CONTINUOUS
#define __HAL_ADC_CR1_DISCONTINUOUS                      ADC_CR1_DISCONTINUOUS
#define __HAL_ADC_CR1_SCANCONV                           ADC_CR1_SCANCONV
#define __HAL_ADC_CR2_EOCSelection                       ADC_CR2_EOCSelection
#define __HAL_ADC_CR2_DMAContReq                         ADC_CR2_DMAContReq
#define __HAL_ADC_JSQR                                   ADC_JSQR

#define __HAL_ADC_CHSELR_CHANNEL                         ADC_CHSELR_CHANNEL
#define __HAL_ADC_CFGR1_REG_DISCCONTINUOUS               ADC_CFGR1_REG_DISCCONTINUOUS
#define __HAL_ADC_CFGR1_AUTOOFF                          ADC_CFGR1_AUTOOFF
#define __HAL_ADC_CFGR1_AUTOWAIT                         ADC_CFGR1_AUTOWAIT
#define __HAL_ADC_CFGR1_CONTINUOUS                       ADC_CFGR1_CONTINUOUS
#define __HAL_ADC_CFGR1_OVERRUN                          ADC_CFGR1_OVERRUN
#define __HAL_ADC_CFGR1_SCANDIR                          ADC_CFGR1_SCANDIR
#define __HAL_ADC_CFGR1_DMACONTREQ                       ADC_CFGR1_DMACONTREQ

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_DHR12R1_ALIGNEMENT                        DAC_DHR12R1_ALIGNMENT
#define __HAL_DHR12R2_ALIGNEMENT                        DAC_DHR12R2_ALIGNMENT
#define __HAL_DHR12RD_ALIGNEMENT                        DAC_DHR12RD_ALIGNMENT
#define IS_DAC_GENERATE_WAVE                            IS_DAC_WAVE

/**
  * @}
  */

/** @defgroup HAL_DBGMCU_Aliased_Macros HAL DBGMCU Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_FREEZE_TIM1_DBGMCU __HAL_DBGMCU_FREEZE_TIM1
#define __HAL_UNFREEZE_TIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM1
#define __HAL_FREEZE_TIM2_DBGMCU __HAL_DBGMCU_FREEZE_TIM2
#define __HAL_UNFREEZE_TIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM2
#define __HAL_FREEZE_TIM3_DBGMCU __HAL_DBGMCU_FREEZE_TIM3
#define __HAL_UNFREEZE_TIM3_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM3
#define __HAL_FREEZE_TIM4_DBGMCU __HAL_DBGMCU_FREEZE_TIM4
#define __HAL_UNFREEZE_TIM4_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM4
#define __HAL_FREEZE_TIM5_DBGMCU __HAL_DBGMCU_FREEZE_TIM5
#define __HAL_UNFREEZE_TIM5_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM5
#define __HAL_FREEZE_TIM6_DBGMCU __HAL_DBGMCU_FREEZE_TIM6
#define __HAL_UNFREEZE_TIM6_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM6
#define __HAL_FREEZE_TIM7_DBGMCU __HAL_DBGMCU_FREEZE_TIM7
#define __HAL_UNFREEZE_TIM7_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM7
#define __HAL_FREEZE_TIM8_DBGMCU __HAL_DBGMCU_FREEZE_TIM8
#define __HAL_UNFREEZE_TIM8_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM8

#define __HAL_FREEZE_TIM9_DBGMCU __HAL_DBGMCU_FREEZE_TIM9
#define __HAL_UNFREEZE_TIM9_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM9
#define __HAL_FREEZE_TIM10_DBGMCU __HAL_DBGMCU_FREEZE_TIM10
#define __HAL_UNFREEZE_TIM10_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM10
#define __HAL_FREEZE_TIM11_DBGMCU __HAL_DBGMCU_FREEZE_TIM11
#define __HAL_UNFREEZE_TIM11_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM11
#define __HAL_FREEZE_TIM12_DBGMCU __HAL_DBGMCU_FREEZE_TIM12
#define __HAL_UNFREEZE_TIM12_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM12
#define __HAL_FREEZE_TIM13_DBGMCU __HAL_DBGMCU_FREEZE_TIM13
#define __HAL_UNFREEZE_TIM13_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM13
#define __HAL_FREEZE_TIM14_DBGMCU __HAL_DBGMCU_FREEZE_TIM14
#define __HAL_UNFREEZE_TIM14_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM14
#define __HAL_FREEZE_CAN2_DBGMCU __HAL_DBGMCU_FREEZE_CAN2
#define __HAL_UNFREEZE_CAN2_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN2


#define __HAL_FREEZE_TIM15_DBGMCU __HAL_DBGMCU_FREEZE_TIM15
#define __HAL_UNFREEZE_TIM15_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM15
#define __HAL_FREEZE_TIM16_DBGMCU __HAL_DBGMCU_FREEZE_TIM16
#define __HAL_UNFREEZE_TIM16_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM16
#define __HAL_FREEZE_TIM17_DBGMCU __HAL_DBGMCU_FREEZE_TIM17
#define __HAL_UNFREEZE_TIM17_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM17
#define __HAL_FREEZE_RTC_DBGMCU __HAL_DBGMCU_FREEZE_RTC
#define __HAL_UNFREEZE_RTC_DBGMCU __HAL_DBGMCU_UNFREEZE_RTC
#if defined(STM32H7)
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG1
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UnFreeze_WWDG1
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG1
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UnFreeze_IWDG1
#else
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_WWDG
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_IWDG
#endif /* STM32H7 */
#define __HAL_FREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT
#define __HAL_UNFREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT
#define __HAL_FREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT
#define __HAL_UNFREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT
#define __HAL_FREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT
#define __HAL_UNFREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT
#define __HAL_FREEZE_CAN1_DBGMCU __HAL_DBGMCU_FREEZE_CAN1
#define __HAL_UNFREEZE_CAN1_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN1
#define __HAL_FREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM1
#define __HAL_UNFREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM1
#define __HAL_FREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM2
#define __HAL_UNFREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM2

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Macros HAL COMP Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined(STM32F3)
#define COMP_START                                       __HAL_COMP_ENABLE
#define COMP_STOP                                        __HAL_COMP_DISABLE
#define COMP_LOCK                                        __HAL_COMP_LOCK
