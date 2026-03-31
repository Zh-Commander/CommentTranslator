/** @defgroup HAL_Aliased_Functions HAL Generic Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_EnableDBGSleepMode HAL_DBGMCU_EnableDBGSleepMode
#define HAL_DisableDBGSleepMode HAL_DBGMCU_DisableDBGSleepMode
#define HAL_EnableDBGStopMode HAL_DBGMCU_EnableDBGStopMode
#define HAL_DisableDBGStopMode HAL_DBGMCU_DisableDBGStopMode
#define HAL_EnableDBGStandbyMode HAL_DBGMCU_EnableDBGStandbyMode
#define HAL_DisableDBGStandbyMode HAL_DBGMCU_DisableDBGStandbyMode
#define HAL_DBG_LowPowerConfig(Periph, cmd) (((cmd\
                                              )==ENABLE)? HAL_DBGMCU_DBG_EnableLowPowerConfig(Periph) : \
                                             HAL_DBGMCU_DBG_DisableLowPowerConfig(Periph))
#define HAL_VREFINT_OutputSelect  HAL_SYSCFG_VREFINT_OutputSelect
#define HAL_Lock_Cmd(cmd) (((cmd)==ENABLE) ? HAL_SYSCFG_Enable_Lock_VREFINT() : HAL_SYSCFG_Disable_Lock_VREFINT())
#if defined(STM32L0)
#else
#define HAL_VREFINT_Cmd(cmd) (((cmd)==ENABLE)? HAL_SYSCFG_EnableVREFINT() : HAL_SYSCFG_DisableVREFINT())
#endif
#define HAL_ADC_EnableBuffer_Cmd(cmd)  (((cmd)==ENABLE) ? HAL_ADCEx_EnableVREFINT() : HAL_ADCEx_DisableVREFINT())
#define HAL_ADC_EnableBufferSensor_Cmd(cmd) (((cmd\
                                              )==ENABLE) ?  HAL_ADCEx_EnableVREFINTTempSensor() : \
                                             HAL_ADCEx_DisableVREFINTTempSensor())
#if defined(STM32H7A3xx) || defined(STM32H7B3xx) || defined(STM32H7B0xx) || defined(STM32H7A3xxQ) || \
    defined(STM32H7B3xxQ) || defined(STM32H7B0xxQ)
#define HAL_EnableSRDomainDBGStopMode      HAL_EnableDomain3DBGStopMode
#define HAL_DisableSRDomainDBGStopMode     HAL_DisableDomain3DBGStopMode
#define HAL_EnableSRDomainDBGStandbyMode   HAL_EnableDomain3DBGStandbyMode
#define HAL_DisableSRDomainDBGStandbyMode  HAL_DisableDomain3DBGStandbyMode
#endif /* STM32H7A3xx || STM32H7B3xx || STM32H7B0xx || STM32H7A3xxQ || STM32H7B3xxQ  || STM32H7B0xxQ */

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Functions HAL FLASH Aliased Functions maintained for legacy purpose
  * @{
  */
#define FLASH_HalfPageProgram      HAL_FLASHEx_HalfPageProgram
#define FLASH_EnableRunPowerDown   HAL_FLASHEx_EnableRunPowerDown
#define FLASH_DisableRunPowerDown  HAL_FLASHEx_DisableRunPowerDown
#define HAL_DATA_EEPROMEx_Unlock   HAL_FLASHEx_DATAEEPROM_Unlock
#define HAL_DATA_EEPROMEx_Lock     HAL_FLASHEx_DATAEEPROM_Lock
#define HAL_DATA_EEPROMEx_Erase    HAL_FLASHEx_DATAEEPROM_Erase
#define HAL_DATA_EEPROMEx_Program  HAL_FLASHEx_DATAEEPROM_Program

/**
  * @}
 */

/** @defgroup HAL_I2C_Aliased_Functions HAL I2C Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_I2CEx_AnalogFilter_Config         HAL_I2CEx_ConfigAnalogFilter
#define HAL_I2CEx_DigitalFilter_Config        HAL_I2CEx_ConfigDigitalFilter
#define HAL_FMPI2CEx_AnalogFilter_Config      HAL_FMPI2CEx_ConfigAnalogFilter
#define HAL_FMPI2CEx_DigitalFilter_Config     HAL_FMPI2CEx_ConfigDigitalFilter

#define HAL_I2CFastModePlusConfig(SYSCFG_I2CFastModePlus, cmd) (((cmd) == ENABLE)? \
                                                                HAL_I2CEx_EnableFastModePlus(SYSCFG_I2CFastModePlus): \
                                                                HAL_I2CEx_DisableFastModePlus(SYSCFG_I2CFastModePlus))

#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || \
    defined(STM32L4) || defined(STM32L5) || defined(STM32G4) || defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_IT  HAL_I2C_Master_Seq_Transmit_IT
#define HAL_I2C_Master_Sequential_Receive_IT   HAL_I2C_Master_Seq_Receive_IT
#define HAL_I2C_Slave_Sequential_Transmit_IT   HAL_I2C_Slave_Seq_Transmit_IT
#define HAL_I2C_Slave_Sequential_Receive_IT    HAL_I2C_Slave_Seq_Receive_IT
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 ||
          STM32L4 || STM32L5 || STM32G4 || STM32L1 */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F4) || defined(STM32F7) || \
    defined(STM32L0) || defined(STM32L4) || defined(STM32L5) || defined(STM32G4)|| defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_DMA HAL_I2C_Master_Seq_Transmit_DMA
#define HAL_I2C_Master_Sequential_Receive_DMA  HAL_I2C_Master_Seq_Receive_DMA
#define HAL_I2C_Slave_Sequential_Transmit_DMA  HAL_I2C_Slave_Seq_Transmit_DMA
#define HAL_I2C_Slave_Sequential_Receive_DMA   HAL_I2C_Slave_Seq_Receive_DMA
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F4 || STM32F7 || STM32L0 || STM32L4 || STM32L5 || STM32G4 || STM32L1 */

#if defined(STM32F4)
#define HAL_FMPI2C_Master_Sequential_Transmit_IT  HAL_FMPI2C_Master_Seq_Transmit_IT
#define HAL_FMPI2C_Master_Sequential_Receive_IT   HAL_FMPI2C_Master_Seq_Receive_IT
#define HAL_FMPI2C_Slave_Sequential_Transmit_IT   HAL_FMPI2C_Slave_Seq_Transmit_IT
#define HAL_FMPI2C_Slave_Sequential_Receive_IT    HAL_FMPI2C_Slave_Seq_Receive_IT
#define HAL_FMPI2C_Master_Sequential_Transmit_DMA HAL_FMPI2C_Master_Seq_Transmit_DMA
#define HAL_FMPI2C_Master_Sequential_Receive_DMA  HAL_FMPI2C_Master_Seq_Receive_DMA
#define HAL_FMPI2C_Slave_Sequential_Transmit_DMA  HAL_FMPI2C_Slave_Seq_Transmit_DMA
#define HAL_FMPI2C_Slave_Sequential_Receive_DMA   HAL_FMPI2C_Slave_Seq_Receive_DMA
#endif /* STM32F4 */
/**
  * @}
 */

/** @defgroup HAL_PWR_Aliased HAL PWR Aliased maintained for legacy purpose
  * @{
  */

#if defined(STM32G0)
#define HAL_PWR_ConfigPVD                             HAL_PWREx_ConfigPVD
#define HAL_PWR_EnablePVD                             HAL_PWREx_EnablePVD
#define HAL_PWR_DisablePVD                            HAL_PWREx_DisablePVD
#define HAL_PWR_PVD_IRQHandler                        HAL_PWREx_PVD_IRQHandler
#endif
#define HAL_PWR_PVDConfig                             HAL_PWR_ConfigPVD
#define HAL_PWR_DisableBkUpReg                        HAL_PWREx_DisableBkUpReg
#define HAL_PWR_DisableFlashPowerDown                 HAL_PWREx_DisableFlashPowerDown
#define HAL_PWR_DisableVddio2Monitor                  HAL_PWREx_DisableVddio2Monitor
#define HAL_PWR_EnableBkUpReg                         HAL_PWREx_EnableBkUpReg
#define HAL_PWR_EnableFlashPowerDown                  HAL_PWREx_EnableFlashPowerDown
#define HAL_PWR_EnableVddio2Monitor                   HAL_PWREx_EnableVddio2Monitor
#define HAL_PWR_PVD_PVM_IRQHandler                    HAL_PWREx_PVD_PVM_IRQHandler
#define HAL_PWR_PVDLevelConfig                        HAL_PWR_ConfigPVD
#define HAL_PWR_Vddio2Monitor_IRQHandler              HAL_PWREx_Vddio2Monitor_IRQHandler
#define HAL_PWR_Vddio2MonitorCallback                 HAL_PWREx_Vddio2MonitorCallback
#define HAL_PWREx_ActivateOverDrive                   HAL_PWREx_EnableOverDrive
#define HAL_PWREx_DeactivateOverDrive                 HAL_PWREx_DisableOverDrive
#define HAL_PWREx_DisableSDADCAnalog                  HAL_PWREx_DisableSDADC
#define HAL_PWREx_EnableSDADCAnalog                   HAL_PWREx_EnableSDADC
#define HAL_PWREx_PVMConfig                           HAL_PWREx_ConfigPVM

#define PWR_MODE_NORMAL                               PWR_PVD_MODE_NORMAL
#define PWR_MODE_IT_RISING                            PWR_PVD_MODE_IT_RISING
#define PWR_MODE_IT_FALLING                           PWR_PVD_MODE_IT_FALLING
#define PWR_MODE_IT_RISING_FALLING                    PWR_PVD_MODE_IT_RISING_FALLING
#define PWR_MODE_EVENT_RISING                         PWR_PVD_MODE_EVENT_RISING
#define PWR_MODE_EVENT_FALLING                        PWR_PVD_MODE_EVENT_FALLING
#define PWR_MODE_EVENT_RISING_FALLING                 PWR_PVD_MODE_EVENT_RISING_FALLING

#define CR_OFFSET_BB                                  PWR_CR_OFFSET_BB
#define CSR_OFFSET_BB                                 PWR_CSR_OFFSET_BB
#define PMODE_BIT_NUMBER                              VOS_BIT_NUMBER
#define CR_PMODE_BB                                   CR_VOS_BB

#define DBP_BitNumber                                 DBP_BIT_NUMBER
#define PVDE_BitNumber                                PVDE_BIT_NUMBER
#define PMODE_BitNumber                               PMODE_BIT_NUMBER
#define EWUP_BitNumber                                EWUP_BIT_NUMBER
#define FPDS_BitNumber                                FPDS_BIT_NUMBER
#define ODEN_BitNumber                                ODEN_BIT_NUMBER
#define ODSWEN_BitNumber                              ODSWEN_BIT_NUMBER
#define MRLVDS_BitNumber                              MRLVDS_BIT_NUMBER
#define LPLVDS_BitNumber                              LPLVDS_BIT_NUMBER
#define BRE_BitNumber                                 BRE_BIT_NUMBER

#define PWR_MODE_EVT                                  PWR_PVD_MODE_NORMAL

#if defined (STM32U5)
#define PWR_SRAM1_PAGE1_STOP_RETENTION                PWR_SRAM1_PAGE1_STOP
#define PWR_SRAM1_PAGE2_STOP_RETENTION                PWR_SRAM1_PAGE2_STOP
#define PWR_SRAM1_PAGE3_STOP_RETENTION                PWR_SRAM1_PAGE3_STOP
#define PWR_SRAM1_PAGE4_STOP_RETENTION                PWR_SRAM1_PAGE4_STOP
#define PWR_SRAM1_PAGE5_STOP_RETENTION                PWR_SRAM1_PAGE5_STOP
#define PWR_SRAM1_PAGE6_STOP_RETENTION                PWR_SRAM1_PAGE6_STOP
#define PWR_SRAM1_PAGE7_STOP_RETENTION                PWR_SRAM1_PAGE7_STOP
#define PWR_SRAM1_PAGE8_STOP_RETENTION                PWR_SRAM1_PAGE8_STOP
#define PWR_SRAM1_PAGE9_STOP_RETENTION                PWR_SRAM1_PAGE9_STOP
#define PWR_SRAM1_PAGE10_STOP_RETENTION               PWR_SRAM1_PAGE10_STOP
#define PWR_SRAM1_PAGE11_STOP_RETENTION               PWR_SRAM1_PAGE11_STOP
#define PWR_SRAM1_PAGE12_STOP_RETENTION               PWR_SRAM1_PAGE12_STOP
#define PWR_SRAM1_FULL_STOP_RETENTION                 PWR_SRAM1_FULL_STOP

#define PWR_SRAM2_PAGE1_STOP_RETENTION                PWR_SRAM2_PAGE1_STOP
#define PWR_SRAM2_PAGE2_STOP_RETENTION                PWR_SRAM2_PAGE2_STOP
#define PWR_SRAM2_FULL_STOP_RETENTION                 PWR_SRAM2_FULL_STOP

