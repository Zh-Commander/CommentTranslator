#define PWR_SRAM3_PAGE1_STOP_RETENTION                PWR_SRAM3_PAGE1_STOP
#define PWR_SRAM3_PAGE2_STOP_RETENTION                PWR_SRAM3_PAGE2_STOP
#define PWR_SRAM3_PAGE3_STOP_RETENTION                PWR_SRAM3_PAGE3_STOP
#define PWR_SRAM3_PAGE4_STOP_RETENTION                PWR_SRAM3_PAGE4_STOP
#define PWR_SRAM3_PAGE5_STOP_RETENTION                PWR_SRAM3_PAGE5_STOP
#define PWR_SRAM3_PAGE6_STOP_RETENTION                PWR_SRAM3_PAGE6_STOP
#define PWR_SRAM3_PAGE7_STOP_RETENTION                PWR_SRAM3_PAGE7_STOP
#define PWR_SRAM3_PAGE8_STOP_RETENTION                PWR_SRAM3_PAGE8_STOP
#define PWR_SRAM3_PAGE9_STOP_RETENTION                PWR_SRAM3_PAGE9_STOP
#define PWR_SRAM3_PAGE10_STOP_RETENTION               PWR_SRAM3_PAGE10_STOP
#define PWR_SRAM3_PAGE11_STOP_RETENTION               PWR_SRAM3_PAGE11_STOP
#define PWR_SRAM3_PAGE12_STOP_RETENTION               PWR_SRAM3_PAGE12_STOP
#define PWR_SRAM3_PAGE13_STOP_RETENTION               PWR_SRAM3_PAGE13_STOP
#define PWR_SRAM3_FULL_STOP_RETENTION                 PWR_SRAM3_FULL_STOP

#define PWR_SRAM4_FULL_STOP_RETENTION                 PWR_SRAM4_FULL_STOP

#define PWR_SRAM5_PAGE1_STOP_RETENTION                PWR_SRAM5_PAGE1_STOP
#define PWR_SRAM5_PAGE2_STOP_RETENTION                PWR_SRAM5_PAGE2_STOP
#define PWR_SRAM5_PAGE3_STOP_RETENTION                PWR_SRAM5_PAGE3_STOP
#define PWR_SRAM5_PAGE4_STOP_RETENTION                PWR_SRAM5_PAGE4_STOP
#define PWR_SRAM5_PAGE5_STOP_RETENTION                PWR_SRAM5_PAGE5_STOP
#define PWR_SRAM5_PAGE6_STOP_RETENTION                PWR_SRAM5_PAGE6_STOP
#define PWR_SRAM5_PAGE7_STOP_RETENTION                PWR_SRAM5_PAGE7_STOP
#define PWR_SRAM5_PAGE8_STOP_RETENTION                PWR_SRAM5_PAGE8_STOP
#define PWR_SRAM5_PAGE9_STOP_RETENTION                PWR_SRAM5_PAGE9_STOP
#define PWR_SRAM5_PAGE10_STOP_RETENTION               PWR_SRAM5_PAGE10_STOP
#define PWR_SRAM5_PAGE11_STOP_RETENTION               PWR_SRAM5_PAGE11_STOP
#define PWR_SRAM5_PAGE12_STOP_RETENTION               PWR_SRAM5_PAGE12_STOP
#define PWR_SRAM5_PAGE13_STOP_RETENTION               PWR_SRAM5_PAGE13_STOP
#define PWR_SRAM5_FULL_STOP_RETENTION                 PWR_SRAM5_FULL_STOP

#define PWR_SRAM6_PAGE1_STOP_RETENTION                PWR_SRAM6_PAGE1_STOP
#define PWR_SRAM6_PAGE2_STOP_RETENTION                PWR_SRAM6_PAGE2_STOP
#define PWR_SRAM6_PAGE3_STOP_RETENTION                PWR_SRAM6_PAGE3_STOP
#define PWR_SRAM6_PAGE4_STOP_RETENTION                PWR_SRAM6_PAGE4_STOP
#define PWR_SRAM6_PAGE5_STOP_RETENTION                PWR_SRAM6_PAGE5_STOP
#define PWR_SRAM6_PAGE6_STOP_RETENTION                PWR_SRAM6_PAGE6_STOP
#define PWR_SRAM6_PAGE7_STOP_RETENTION                PWR_SRAM6_PAGE7_STOP
#define PWR_SRAM6_PAGE8_STOP_RETENTION                PWR_SRAM6_PAGE8_STOP
#define PWR_SRAM6_FULL_STOP_RETENTION                 PWR_SRAM6_FULL_STOP


#define PWR_ICACHE_FULL_STOP_RETENTION                PWR_ICACHE_FULL_STOP
#define PWR_DCACHE1_FULL_STOP_RETENTION               PWR_DCACHE1_FULL_STOP
#define PWR_DCACHE2_FULL_STOP_RETENTION               PWR_DCACHE2_FULL_STOP
#define PWR_DMA2DRAM_FULL_STOP_RETENTION              PWR_DMA2DRAM_FULL_STOP
#define PWR_PERIPHRAM_FULL_STOP_RETENTION             PWR_PERIPHRAM_FULL_STOP
#define PWR_PKA32RAM_FULL_STOP_RETENTION              PWR_PKA32RAM_FULL_STOP
#define PWR_GRAPHICPRAM_FULL_STOP_RETENTION           PWR_GRAPHICPRAM_FULL_STOP
#define PWR_DSIRAM_FULL_STOP_RETENTION                PWR_DSIRAM_FULL_STOP
#define PWR_JPEGRAM_FULL_STOP_RETENTION               PWR_JPEGRAM_FULL_STOP


#define PWR_SRAM2_PAGE1_STANDBY_RETENTION             PWR_SRAM2_PAGE1_STANDBY
#define PWR_SRAM2_PAGE2_STANDBY_RETENTION             PWR_SRAM2_PAGE2_STANDBY
#define PWR_SRAM2_FULL_STANDBY_RETENTION              PWR_SRAM2_FULL_STANDBY

#define PWR_SRAM1_FULL_RUN_RETENTION                  PWR_SRAM1_FULL_RUN
#define PWR_SRAM2_FULL_RUN_RETENTION                  PWR_SRAM2_FULL_RUN
#define PWR_SRAM3_FULL_RUN_RETENTION                  PWR_SRAM3_FULL_RUN
#define PWR_SRAM4_FULL_RUN_RETENTION                  PWR_SRAM4_FULL_RUN
#define PWR_SRAM5_FULL_RUN_RETENTION                  PWR_SRAM5_FULL_RUN
#define PWR_SRAM6_FULL_RUN_RETENTION                  PWR_SRAM6_FULL_RUN

#define PWR_ALL_RAM_RUN_RETENTION_MASK                PWR_ALL_RAM_RUN_MASK
#endif

/**
  * @}
 */

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


