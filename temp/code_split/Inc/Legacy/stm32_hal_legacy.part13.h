
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Macros HAL UART Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_UART_GETCLOCKSOURCE       UART_GETCLOCKSOURCE
#define __HAL_UART_MASK_COMPUTATION     UART_MASK_COMPUTATION
#define __UART_GETCLOCKSOURCE           UART_GETCLOCKSOURCE
#define __UART_MASK_COMPUTATION         UART_MASK_COMPUTATION

#define IS_UART_WAKEUPMETHODE           IS_UART_WAKEUPMETHOD

#define IS_UART_ONEBIT_SAMPLE           IS_UART_ONE_BIT_SAMPLE
#define IS_UART_ONEBIT_SAMPLING         IS_UART_ONE_BIT_SAMPLE

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Macros HAL USART Aliased Macros maintained for legacy purpose
  * @{
  */

#define __USART_ENABLE_IT               __HAL_USART_ENABLE_IT
#define __USART_DISABLE_IT              __HAL_USART_DISABLE_IT
#define __USART_ENABLE                  __HAL_USART_ENABLE
#define __USART_DISABLE                 __HAL_USART_DISABLE

#define __HAL_USART_GETCLOCKSOURCE      USART_GETCLOCKSOURCE
#define __USART_GETCLOCKSOURCE          USART_GETCLOCKSOURCE

#if defined(STM32F0) || defined(STM32F3) || defined(STM32F7)
#define USART_OVERSAMPLING_16               0x00000000U
#define USART_OVERSAMPLING_8                USART_CR1_OVER8

#define IS_USART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == USART_OVERSAMPLING_16) || \
                                             ((__SAMPLING__) == USART_OVERSAMPLING_8))
#endif /* STM32F0 || STM32F3 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_USB_Aliased_Macros HAL USB Aliased Macros maintained for legacy purpose
  * @{
  */
#define USB_EXTI_LINE_WAKEUP                               USB_WAKEUP_EXTI_LINE

#define USB_FS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE
#define USB_FS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE
#define USB_FS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE
#define USB_FS_EXTI_LINE_WAKEUP                            USB_OTG_FS_WAKEUP_EXTI_LINE

#define USB_HS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE
#define USB_HS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE
#define USB_HS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE
#define USB_HS_EXTI_LINE_WAKEUP                            USB_OTG_HS_WAKEUP_EXTI_LINE

#define __HAL_USB_EXTI_ENABLE_IT                           __HAL_USB_WAKEUP_EXTI_ENABLE_IT
#define __HAL_USB_EXTI_DISABLE_IT                          __HAL_USB_WAKEUP_EXTI_DISABLE_IT
#define __HAL_USB_EXTI_GET_FLAG                            __HAL_USB_WAKEUP_EXTI_GET_FLAG
#define __HAL_USB_EXTI_CLEAR_FLAG                          __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_USB_EXTI_SET_RISING_EDGE_TRIGGER             __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE
#define __HAL_USB_EXTI_SET_FALLING_EDGE_TRIGGER            __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE
#define __HAL_USB_EXTI_SET_FALLINGRISING_TRIGGER           __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE

#define __HAL_USB_FS_EXTI_ENABLE_IT                        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT
#define __HAL_USB_FS_EXTI_DISABLE_IT                       __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT
#define __HAL_USB_FS_EXTI_GET_FLAG                         __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG
#define __HAL_USB_FS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_USB_FS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE
#define __HAL_USB_FS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
#define __HAL_USB_FS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
#define __HAL_USB_FS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT

#define __HAL_USB_HS_EXTI_ENABLE_IT                        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT
#define __HAL_USB_HS_EXTI_DISABLE_IT                       __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT
#define __HAL_USB_HS_EXTI_GET_FLAG                         __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG
#define __HAL_USB_HS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_USB_HS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE
#define __HAL_USB_HS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
#define __HAL_USB_HS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
#define __HAL_USB_HS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT

#define HAL_PCD_ActiveRemoteWakeup                         HAL_PCD_ActivateRemoteWakeup
#define HAL_PCD_DeActiveRemoteWakeup                       HAL_PCD_DeActivateRemoteWakeup

#define HAL_PCD_SetTxFiFo                                  HAL_PCDEx_SetTxFiFo
#define HAL_PCD_SetRxFiFo                                  HAL_PCDEx_SetRxFiFo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE

#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT

#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE

#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE

#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1

#define TIM_OCMODE_ASSYMETRIC_PWM1      TIM_OCMODE_ASYMMETRIC_PWM1
#define TIM_OCMODE_ASSYMETRIC_PWM2      TIM_OCMODE_ASYMMETRIC_PWM2
/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Macros HAL ETH Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_ETH_EXTI_ENABLE_IT                   __HAL_ETH_WAKEUP_EXTI_ENABLE_IT
#define __HAL_ETH_EXTI_DISABLE_IT                  __HAL_ETH_WAKEUP_EXTI_DISABLE_IT
#define __HAL_ETH_EXTI_GET_FLAG                    __HAL_ETH_WAKEUP_EXTI_GET_FLAG
#define __HAL_ETH_EXTI_CLEAR_FLAG                  __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_ETH_EXTI_SET_RISING_EGDE_TRIGGER     __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER
#define __HAL_ETH_EXTI_SET_FALLING_EGDE_TRIGGER    __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER
#define __HAL_ETH_EXTI_SET_FALLINGRISING_TRIGGER   __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER

#define ETH_PROMISCIOUSMODE_ENABLE   ETH_PROMISCUOUS_MODE_ENABLE
#define ETH_PROMISCIOUSMODE_DISABLE  ETH_PROMISCUOUS_MODE_DISABLE
#define IS_ETH_PROMISCIOUS_MODE      IS_ETH_PROMISCUOUS_MODE
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Macros HAL LTDC Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_LTDC_LAYER LTDC_LAYER
#define __HAL_LTDC_RELOAD_CONFIG  __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG
/**
  * @}
  */

/** @defgroup HAL_SAI_Aliased_Macros HAL SAI Aliased Macros maintained for legacy purpose
  * @{
  */
#define SAI_OUTPUTDRIVE_DISABLED          SAI_OUTPUTDRIVE_DISABLE
#define SAI_OUTPUTDRIVE_ENABLED           SAI_OUTPUTDRIVE_ENABLE
#define SAI_MASTERDIVIDER_ENABLED         SAI_MASTERDIVIDER_ENABLE
#define SAI_MASTERDIVIDER_DISABLED        SAI_MASTERDIVIDER_DISABLE
#define SAI_STREOMODE                     SAI_STEREOMODE
#define SAI_FIFOStatus_Empty              SAI_FIFOSTATUS_EMPTY
#define SAI_FIFOStatus_Less1QuarterFull   SAI_FIFOSTATUS_LESS1QUARTERFULL
#define SAI_FIFOStatus_1QuarterFull       SAI_FIFOSTATUS_1QUARTERFULL
#define SAI_FIFOStatus_HalfFull           SAI_FIFOSTATUS_HALFFULL
#define SAI_FIFOStatus_3QuartersFull      SAI_FIFOSTATUS_3QUARTERFULL
#define SAI_FIFOStatus_Full               SAI_FIFOSTATUS_FULL
#define IS_SAI_BLOCK_MONO_STREO_MODE      IS_SAI_BLOCK_MONO_STEREO_MODE
#define SAI_SYNCHRONOUS_EXT               SAI_SYNCHRONOUS_EXT_SAI1
#define SAI_SYNCEXT_IN_ENABLE             SAI_SYNCEXT_OUTBLOCKA_ENABLE
/**
  * @}
  */

/** @defgroup HAL_SPDIFRX_Aliased_Macros HAL SPDIFRX Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined(STM32H7)
#define HAL_SPDIFRX_ReceiveControlFlow      HAL_SPDIFRX_ReceiveCtrlFlow
#define HAL_SPDIFRX_ReceiveControlFlow_IT   HAL_SPDIFRX_ReceiveCtrlFlow_IT
#define HAL_SPDIFRX_ReceiveControlFlow_DMA  HAL_SPDIFRX_ReceiveCtrlFlow_DMA
#endif
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Functions HAL HRTIM Aliased Functions maintained for legacy purpose
  * @{
  */
#if defined (STM32H7) || defined (STM32G4) || defined (STM32F3)
#define HAL_HRTIM_WaveformCounterStart_IT      HAL_HRTIM_WaveformCountStart_IT
#define HAL_HRTIM_WaveformCounterStart_DMA     HAL_HRTIM_WaveformCountStart_DMA
#define HAL_HRTIM_WaveformCounterStart         HAL_HRTIM_WaveformCountStart
#define HAL_HRTIM_WaveformCounterStop_IT       HAL_HRTIM_WaveformCountStop_IT
#define HAL_HRTIM_WaveformCounterStop_DMA      HAL_HRTIM_WaveformCountStop_DMA
#define HAL_HRTIM_WaveformCounterStop          HAL_HRTIM_WaveformCountStop
#endif
/**
  * @}
  */

/** @defgroup HAL_QSPI_Aliased_Macros HAL QSPI Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined (STM32L4) || defined (STM32F4) || defined (STM32F7) || defined(STM32H7)
#define HAL_QPSI_TIMEOUT_DEFAULT_VALUE HAL_QSPI_TIMEOUT_DEFAULT_VALUE
#endif /* STM32L4 || STM32F4 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_Generic_Aliased_Macros HAL Generic Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined (STM32F7)
#define ART_ACCLERATOR_ENABLE ART_ACCELERATOR_ENABLE
#endif /* STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_PPP_Aliased_Macros HAL PPP Aliased Macros maintained for legacy purpose
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32_HAL_LEGACY */


