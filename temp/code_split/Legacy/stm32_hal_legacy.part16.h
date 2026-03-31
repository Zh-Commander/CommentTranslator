#if defined (STM32F4)
#define __HAL_PVD_EXTI_ENABLE_IT(PWR_EXTI_LINE_PVD)         __HAL_PWR_PVD_EXTI_ENABLE_IT()
#define __HAL_PVD_EXTI_DISABLE_IT(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_DISABLE_IT()
#define __HAL_PVD_EXTI_GET_FLAG(PWR_EXTI_LINE_PVD)          __HAL_PWR_PVD_EXTI_GET_FLAG()
#define __HAL_PVD_EXTI_CLEAR_FLAG(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_CLEAR_FLAG()
#define __HAL_PVD_EXTI_GENERATE_SWIT(PWR_EXTI_LINE_PVD)     __HAL_PWR_PVD_EXTI_GENERATE_SWIT()
#else
#define __HAL_PVD_EXTI_CLEAR_FLAG                                __HAL_PWR_PVD_EXTI_CLEAR_FLAG
#define __HAL_PVD_EXTI_DISABLE_IT                                __HAL_PWR_PVD_EXTI_DISABLE_IT
#define __HAL_PVD_EXTI_ENABLE_IT                                 __HAL_PWR_PVD_EXTI_ENABLE_IT
#define __HAL_PVD_EXTI_GENERATE_SWIT                             __HAL_PWR_PVD_EXTI_GENERATE_SWIT
#define __HAL_PVD_EXTI_GET_FLAG                                  __HAL_PWR_PVD_EXTI_GET_FLAG
#endif /* STM32F4 */
/**
  * @}
  */


/** @defgroup HAL_RCC_Aliased HAL RCC Aliased maintained for legacy purpose
  * @{
  */

#define RCC_StopWakeUpClock_MSI     RCC_STOP_WAKEUPCLOCK_MSI
#define RCC_StopWakeUpClock_HSI     RCC_STOP_WAKEUPCLOCK_HSI

#define HAL_RCC_CCSCallback HAL_RCC_CSSCallback
#define HAL_RC48_EnableBuffer_Cmd(cmd) (((cmd)==ENABLE) ? \
                                        HAL_RCCEx_EnableHSI48_VREFINT() : HAL_RCCEx_DisableHSI48_VREFINT())

