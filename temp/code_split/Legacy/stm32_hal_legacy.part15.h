#define __HAL_COMP_GET_EXTI_LINE  COMP_GET_EXTI_LINE

#if defined(STM32L0) || defined(STM32L4)
/* Note: On these STM32 families, the only argument of this macro             */
/*       is COMP_FLAG_LOCK.                                                   */
/*       This macro is replaced by __HAL_COMP_IS_LOCKED with only HAL handle  */
/*       argument.                                                            */
#define __HAL_COMP_GET_FLAG(__HANDLE__, __FLAG__)  (__HAL_COMP_IS_LOCKED(__HANDLE__))
#endif
/**
  * @}
  */

#if defined(STM32L0) || defined(STM32L4)
/** @defgroup HAL_COMP_Aliased_Functions HAL COMP Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_COMP_Start_IT       HAL_COMP_Start /* Function considered as legacy as EXTI event or IT configuration is 
                                                  done into HAL_COMP_Init() */
#define HAL_COMP_Stop_IT        HAL_COMP_Stop  /* Function considered as legacy as EXTI event or IT configuration is 
                                                  done into HAL_COMP_Init() */
/**
  * @}
  */
#endif

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC Aliased Macros maintained for legacy purpose
  * @{
  */

#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_WAVE_NONE) || \
                           ((WAVE) == DAC_WAVE_NOISE)|| \
                           ((WAVE) == DAC_WAVE_TRIANGLE))

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Macros HAL FLASH Aliased Macros maintained for legacy purpose
  * @{
  */

#define IS_WRPAREA          IS_OB_WRPAREA
#define IS_TYPEPROGRAM      IS_FLASH_TYPEPROGRAM
#define IS_TYPEPROGRAMFLASH IS_FLASH_TYPEPROGRAM
#define IS_TYPEERASE        IS_FLASH_TYPEERASE
#define IS_NBSECTORS        IS_FLASH_NBSECTORS
#define IS_OB_WDG_SOURCE    IS_OB_IWDG_SOURCE

/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Macros HAL I2C Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_I2C_RESET_CR2             I2C_RESET_CR2
#define __HAL_I2C_GENERATE_START        I2C_GENERATE_START
#if defined(STM32F1)
#define __HAL_I2C_FREQ_RANGE            I2C_FREQRANGE
#else
#define __HAL_I2C_FREQ_RANGE            I2C_FREQ_RANGE
#endif /* STM32F1 */
#define __HAL_I2C_RISE_TIME             I2C_RISE_TIME
#define __HAL_I2C_SPEED_STANDARD        I2C_SPEED_STANDARD
#define __HAL_I2C_SPEED_FAST            I2C_SPEED_FAST
#define __HAL_I2C_SPEED                 I2C_SPEED
#define __HAL_I2C_7BIT_ADD_WRITE        I2C_7BIT_ADD_WRITE
#define __HAL_I2C_7BIT_ADD_READ         I2C_7BIT_ADD_READ
#define __HAL_I2C_10BIT_ADDRESS         I2C_10BIT_ADDRESS
#define __HAL_I2C_10BIT_HEADER_WRITE    I2C_10BIT_HEADER_WRITE
#define __HAL_I2C_10BIT_HEADER_READ     I2C_10BIT_HEADER_READ
#define __HAL_I2C_MEM_ADD_MSB           I2C_MEM_ADD_MSB
#define __HAL_I2C_MEM_ADD_LSB           I2C_MEM_ADD_LSB
#define __HAL_I2C_FREQRANGE             I2C_FREQRANGE
/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Macros HAL I2S Aliased Macros maintained for legacy purpose
  * @{
  */

#define IS_I2S_INSTANCE                 IS_I2S_ALL_INSTANCE
#define IS_I2S_INSTANCE_EXT             IS_I2S_ALL_INSTANCE_EXT

#if defined(STM32H7)
#define __HAL_I2S_CLEAR_FREFLAG       __HAL_I2S_CLEAR_TIFREFLAG
#endif

/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Macros HAL IRDA Aliased Macros maintained for legacy purpose
  * @{
  */

#define __IRDA_DISABLE                  __HAL_IRDA_DISABLE
#define __IRDA_ENABLE                   __HAL_IRDA_ENABLE

#define __HAL_IRDA_GETCLOCKSOURCE       IRDA_GETCLOCKSOURCE
#define __HAL_IRDA_MASK_COMPUTATION     IRDA_MASK_COMPUTATION
#define __IRDA_GETCLOCKSOURCE           IRDA_GETCLOCKSOURCE
#define __IRDA_MASK_COMPUTATION         IRDA_MASK_COMPUTATION

#define IS_IRDA_ONEBIT_SAMPLE           IS_IRDA_ONE_BIT_SAMPLE


/**
  * @}
  */


/** @defgroup HAL_IWDG_Aliased_Macros HAL IWDG Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_IWDG_ENABLE_WRITE_ACCESS  IWDG_ENABLE_WRITE_ACCESS
#define __HAL_IWDG_DISABLE_WRITE_ACCESS IWDG_DISABLE_WRITE_ACCESS
/**
  * @}
  */


/** @defgroup HAL_LPTIM_Aliased_Macros HAL LPTIM Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_LPTIM_ENABLE_INTERRUPT    __HAL_LPTIM_ENABLE_IT
#define __HAL_LPTIM_DISABLE_INTERRUPT   __HAL_LPTIM_DISABLE_IT
#define __HAL_LPTIM_GET_ITSTATUS        __HAL_LPTIM_GET_IT_SOURCE

/**
  * @}
  */


/** @defgroup HAL_OPAMP_Aliased_Macros HAL OPAMP Aliased Macros maintained for legacy purpose
  * @{
  */
#define __OPAMP_CSR_OPAXPD                OPAMP_CSR_OPAXPD
#define __OPAMP_CSR_S3SELX                OPAMP_CSR_S3SELX
#define __OPAMP_CSR_S4SELX                OPAMP_CSR_S4SELX
#define __OPAMP_CSR_S5SELX                OPAMP_CSR_S5SELX
#define __OPAMP_CSR_S6SELX                OPAMP_CSR_S6SELX
#define __OPAMP_CSR_OPAXCAL_L             OPAMP_CSR_OPAXCAL_L
#define __OPAMP_CSR_OPAXCAL_H             OPAMP_CSR_OPAXCAL_H
#define __OPAMP_CSR_OPAXLPM               OPAMP_CSR_OPAXLPM
#define __OPAMP_CSR_ALL_SWITCHES          OPAMP_CSR_ALL_SWITCHES
#define __OPAMP_CSR_ANAWSELX              OPAMP_CSR_ANAWSELX
#define __OPAMP_CSR_OPAXCALOUT            OPAMP_CSR_OPAXCALOUT
#define __OPAMP_OFFSET_TRIM_BITSPOSITION  OPAMP_OFFSET_TRIM_BITSPOSITION
#define __OPAMP_OFFSET_TRIM_SET           OPAMP_OFFSET_TRIM_SET

/**
  * @}
  */


/** @defgroup HAL_PWR_Aliased_Macros HAL PWR Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_PVD_EVENT_DISABLE                                  __HAL_PWR_PVD_EXTI_DISABLE_EVENT
#define __HAL_PVD_EVENT_ENABLE                                   __HAL_PWR_PVD_EXTI_ENABLE_EVENT
#define __HAL_PVD_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
#define __HAL_PVD_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
#define __HAL_PVD_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
#define __HAL_PVD_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
#define __HAL_PVM_EVENT_DISABLE                                  __HAL_PWR_PVM_EVENT_DISABLE
#define __HAL_PVM_EVENT_ENABLE                                   __HAL_PWR_PVM_EVENT_ENABLE
#define __HAL_PVM_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_DISABLE
#define __HAL_PVM_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_ENABLE
#define __HAL_PVM_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVM_EXTI_RISINGTRIGGER_DISABLE
#define __HAL_PVM_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVM_EXTI_RISINGTRIGGER_ENABLE
#define __HAL_PWR_INTERNALWAKEUP_DISABLE                         HAL_PWREx_DisableInternalWakeUpLine
#define __HAL_PWR_INTERNALWAKEUP_ENABLE                          HAL_PWREx_EnableInternalWakeUpLine
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_DISABLE                    HAL_PWREx_DisablePullUpPullDownConfig
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_ENABLE                     HAL_PWREx_EnablePullUpPullDownConfig
#define __HAL_PWR_PVD_EXTI_CLEAR_EGDE_TRIGGER()                  do { __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE(); \
                                                                      __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); \
                                                                    } while(0)
#define __HAL_PWR_PVD_EXTI_EVENT_DISABLE                         __HAL_PWR_PVD_EXTI_DISABLE_EVENT
#define __HAL_PWR_PVD_EXTI_EVENT_ENABLE                          __HAL_PWR_PVD_EXTI_ENABLE_EVENT
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_DISABLE                __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_ENABLE                 __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_DISABLE                 __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_ENABLE                  __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
#define __HAL_PWR_PVD_EXTI_SET_FALLING_EGDE_TRIGGER              __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
#define __HAL_PWR_PVD_EXTI_SET_RISING_EDGE_TRIGGER               __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
#define __HAL_PWR_PVM_DISABLE()                                  do { HAL_PWREx_DisablePVM1();HAL_PWREx_DisablePVM2(); \
                                                                      HAL_PWREx_DisablePVM3();HAL_PWREx_DisablePVM4(); \
                                                                    } while(0)
#define __HAL_PWR_PVM_ENABLE()                                   do { HAL_PWREx_EnablePVM1();HAL_PWREx_EnablePVM2(); \
                                                                      HAL_PWREx_EnablePVM3();HAL_PWREx_EnablePVM4(); \
                                                                    } while(0)
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_DISABLE                  HAL_PWREx_DisableSRAM2ContentRetention
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_ENABLE                   HAL_PWREx_EnableSRAM2ContentRetention
#define __HAL_PWR_VDDIO2_DISABLE                                 HAL_PWREx_DisableVddIO2
#define __HAL_PWR_VDDIO2_ENABLE                                  HAL_PWREx_EnableVddIO2
#define __HAL_PWR_VDDIO2_EXTI_CLEAR_EGDE_TRIGGER                 __HAL_PWR_VDDIO2_EXTI_DISABLE_FALLING_EDGE
#define __HAL_PWR_VDDIO2_EXTI_SET_FALLING_EGDE_TRIGGER           __HAL_PWR_VDDIO2_EXTI_ENABLE_FALLING_EDGE
#define __HAL_PWR_VDDUSB_DISABLE                                 HAL_PWREx_DisableVddUSB
#define __HAL_PWR_VDDUSB_ENABLE                                  HAL_PWREx_EnableVddUSB

