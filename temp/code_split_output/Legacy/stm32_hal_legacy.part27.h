#define __HAL_SPI_1LINE_TX              SPI_1LINE_TX   /* SPI单线发送模式宏定义 */
#define __HAL_SPI_1LINE_RX              SPI_1LINE_RX   /* SPI单线接收模式宏定义 */
#define __HAL_SPI_RESET_CRC             SPI_RESET_CRC  /* SPI CRC重置宏定义 */

/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Macros HAL UART Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_UART_GETCLOCKSOURCE       UART_GETCLOCKSOURCE       /* 获取UART时钟源宏定义 */
#define __HAL_UART_MASK_COMPUTATION     UART_MASK_COMPUTATION     /* UART掩码计算宏定义 */
#define __UART_GETCLOCKSOURCE           UART_GETCLOCKSOURCE       /* UART时钟源获取宏定义（旧版本） */
#define __UART_MASK_COMPUTATION         UART_MASK_COMPUTATION     /* UART掩码计算宏定义（旧版本） */

#define IS_UART_WAKEUPMETHODE           IS_UART_WAKEUPMETHOD      /* UART唤醒方法检查宏定义（旧版本拼写错误） */

#define IS_UART_ONEBIT_SAMPLE           IS_UART_ONE_BIT_SAMPLE    /* UART单比特采样检查宏定义（旧版本） */
#define IS_UART_ONEBIT_SAMPLING         IS_UART_ONE_BIT_SAMPLE    /* UART单比特采样检查宏定义（旧版本） */

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Macros HAL USART Aliased Macros maintained for legacy purpose
  * @{
  */

#define __USART_ENABLE_IT               __HAL_USART_ENABLE_IT     /* USART中断使能宏定义（旧版本） */
#define __USART_DISABLE_IT              __HAL_USART_DISABLE_IT    /* USART中断禁用宏定义（旧版本） */
#define __USART_ENABLE                  __HAL_USART_ENABLE        /* USART使能宏定义（旧版本） */
#define __USART_DISABLE                 __HAL_USART_DISABLE       /* USART禁用宏定义（旧版本） */

#define __HAL_USART_GETCLOCKSOURCE      USART_GETCLOCKSOURCE      /* USART时钟源获取宏定义 */
#define __USART_GETCLOCKSOURCE          USART_GETCLOCKSOURCE      /* USART时钟源获取宏定义（旧版本） */

#if defined(STM32F0) || defined(STM32F3) || defined(STM32F7)      /* 针对STM32F0、F3、F7系列的条件编译 */
#define USART_OVERSAMPLING_16               0x00000000U           /* USART 16倍过采样宏定义 */
#define USART_OVERSAMPLING_8                USART_CR1_OVER8       /* USART 8倍过采样宏定义 */

#define IS_USART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == USART_OVERSAMPLING_16) || \
                                             ((__SAMPLING__) == USART_OVERSAMPLING_8))  /* USART过采样模式检查宏定义 */
#endif /* STM32F0 || STM32F3 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_USB_Aliased_Macros HAL USB Aliased Macros maintained for legacy purpose
  * @{
  */
#define USB_EXTI_LINE_WAKEUP                               USB_WAKEUP_EXTI_LINE  /* USB唤醒外部中断线宏定义 */

#define USB_FS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE        /* USB FS外部中断上升沿触发宏定义 */
#define USB_FS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE       /* USB FS外部中断下降沿触发宏定义 */
#define USB_FS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE /* USB FS外部中断双边沿触发宏定义 */
#define USB_FS_EXTI_LINE_WAKEUP                            USB_OTG_FS_WAKEUP_EXTI_LINE               /* USB FS唤醒外部中断线宏定义 */

#define USB_HS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE        /* USB HS外部中断上升沿触发宏定义 */
#define USB_HS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE       /* USB HS外部中断下降沿触发宏定义 */
#define USB_HS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE /* USB HS外部中断双边沿触发宏定义 */
#define USB_HS_EXTI_LINE_WAKEUP                            USB_OTG_HS_WAKEUP_EXTI_LINE               /* USB HS唤醒外部中断线宏定义 */

#define __HAL_USB_EXTI_ENABLE_IT                           __HAL_USB_WAKEUP_EXTI_ENABLE_IT           /* USB外部中断使能宏定义 */
#define __HAL_USB_EXTI_DISABLE_IT                          __HAL_USB_WAKEUP_EXTI_DISABLE_IT          /* USB外部中断禁用宏定义 */
#define __HAL_USB_EXTI_GET_FLAG                            __HAL_USB_WAKEUP_EXTI_GET_FLAG            /* 获取USB外部中断标志宏定义 */
#define __HAL_USB_EXTI_CLEAR_FLAG                          __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG          /* 清除USB外部中断标志宏定义 */
#define __HAL_USB_EXTI_SET_RISING_EDGE_TRIGGER             __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE  /* 设置USB外部中断上升沿触发宏定义 */
#define __HAL_USB_EXTI_SET_FALLING_EDGE_TRIGGER            __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE /* 设置USB外部中断下降沿触发宏定义 */
#define __HAL_USB_EXTI_SET_FALLINGRISING_TRIGGER           __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE /* 设置USB外部中断双边沿触发宏定义 */

#define __HAL_USB_FS_EXTI_ENABLE_IT                        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT           /* USB FS外部中断使能宏定义 */
#define __HAL_USB_FS_EXTI_DISABLE_IT                       __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT          /* USB FS外部中断禁用宏定义 */
#define __HAL_USB_FS_EXTI_GET_FLAG                         __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG            /* 获取USB FS外部中断标志宏定义 */
#define __HAL_USB_FS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG          /* 清除USB FS外部中断标志宏定义 */
#define __HAL_USB_FS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE  /* 设置USB FS外部中断上升沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_FS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE /* 设置USB FS外部中断下降沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_FS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE /* 设置USB FS外部中断双边沿触发宏定义 */
#define __HAL_USB_FS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT      /* USB FS外部中断生成软件中断宏定义（旧版本拼写错误） */

#define __HAL_USB_HS_EXTI_ENABLE_IT                        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT           /* USB HS外部中断使能宏定义 */
#define __HAL_USB_HS_EXTI_DISABLE_IT                       __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT          /* USB HS外部中断禁用宏定义 */
#define __HAL_USB_HS_EXTI_GET_FLAG                         __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG            /* 获取USB HS外部中断标志宏定义 */
#define __HAL_USB_HS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG          /* 清除USB HS外部中断标志宏定义 */
#define __HAL_USB_HS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE  /* 设置USB HS外部中断上升沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_HS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE /* 设置USB HS外部中断下降沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_HS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE /* 设置USB HS外部中断双边沿触发宏定义 */
#define __HAL_USB_HS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT      /* USB HS外部中断生成软件中断宏定义（旧版本拼写错误） */

#define HAL_PCD_ActiveRemoteWakeup                         HAL_PCD_ActivateRemoteWakeup   /* PCD激活远程唤醒宏定义（旧版本拼写错误） */
#define HAL_PCD_DeActiveRemoteWakeup                       HAL_PCD_DeActivateRemoteWakeup /* PCD去激活远程唤醒宏定义（旧版本拼写错误） */

#define HAL_PCD_SetTxFiFo                                  HAL_PCDEx_SetTxFiFo            /* PCD设置发送FIFO宏定义（旧版本） */
#define HAL_PCD_SetRxFiFo                                  HAL_PCDEx_SetRxFiFo            /* PCD设置接收FIFO宏定义（旧版本） */
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE   /* 设置TIM输入捕获预分频值宏定义 */
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE /* 重置TIM输入捕获预分频值宏定义 */

#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE    /* 获取TIM中断状态宏定义（旧版本） */
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT         /* 清除TIM中断宏定义（旧版本） */

#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE    /* 获取TIM中断状态宏定义 */

#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN /* TIM计数方向状态检查宏定义（旧版本） */
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER        /* TIM预分频器设置宏定义（旧版本） */
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER          /* TIM计数器设置宏定义（旧版本） */
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER          /* TIM计数器获取宏定义（旧版本） */
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD       /* TIM自动重载值设置宏定义（旧版本） */
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD       /* TIM自动重载值获取宏定义（旧版本） */
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION    /* TIM时钟分频设置宏定义（旧版本） */
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION    /* TIM时钟分频获取宏定义（旧版本） */
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER      /* TIM输入捕获预分频设置宏定义（旧版本） */
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER      /* TIM输入捕获预分频获取宏定义（旧版本） */
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE          /* TIM比较值设置宏定义（旧版本） */
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE          /* TIM比较值获取宏定义（旧版本） */

#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1   /* TIM刹车输入源DFSDM宏定义（旧版本） */

#define TIM_OCMODE_ASSYMETRIC_PWM1      TIM_OCMODE_ASYMMETRIC_PWM1  /* TIM非对称PWM1模式宏定义（旧版本拼写错误） */
#define TIM_OCMODE_ASSYMETRIC_PWM2      TIM_OCMODE_ASYMMETRIC_PWM2  /* TIM非对称PWM2模式宏定义（旧版本拼写错误） */
/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Macros HAL ETH Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_ETH_EXTI_ENABLE_IT                   __HAL_ETH_WAKEUP_EXTI_ENABLE_IT           /* ETH外部中断使能宏定义 */
#define __HAL_ETH_EXTI_DISABLE_IT                  __HAL_ETH_WAKEUP_EXTI_DISABLE_IT          /* ETH外部中断禁用宏定义 */
#define __HAL_ETH_EXTI_GET_FLAG                    __HAL_ETH_WAKEUP_EXTI_GET_FLAG            /* 获取ETH外部中断标志宏定义 */
#define __HAL_ETH_EXTI_CLEAR_FLAG                  __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG          /* 清除ETH外部中断标志宏定义 */
#define __HAL_ETH_EXTI_SET_RISING_EGDE_TRIGGER     __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER  /* 设置ETH外部中断上升沿触发宏定义（旧版本拼写错误） */
#define __HAL_ETH_EXTI_SET_FALLING_EGDE_TRIGGER    __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER /* 设置ETH外部中断下降沿触发宏定义（旧版本拼写错误） */
#define __HAL_ETH_EXTI_SET_FALLINGRISING_TRIGGER   __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER /* 设置ETH外部中断双边沿触发宏定义 */

#define ETH_PROMISCIOUSMODE_ENABLE   ETH_PROMISCUOUS_MODE_ENABLE   /* ETH混杂模式使能宏定义（旧版本拼写错误） */
#define ETH_PROMISCIOUSMODE_DISABLE  ETH_PROMISCUOUS_MODE_DISABLE  /* ETH混杂模式禁用宏定义（旧版本拼写错误） */
#define IS_ETH_PROMISCIOUS_MODE      IS_ETH_PROMISCUOUS_MODE       /* ETH混杂模式检查宏定义（旧版本拼写错误） */
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Macros HAL LTDC Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_LTDC_LAYER LTDC_LAYER                             /* LTDC层宏定义（旧版本） */
#define __HAL_LTDC_RELOAD_CONFIG  __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG /* LTDC重载配置宏定义（旧版本） */
/**
  * @}
  */

/** @defgroup HAL_SAI_Aliased_Macros HAL SAI Aliased Macros maintained for legacy purpose
  * @{
  */
#define SAI_OUTPUTDRIVE_DISABLED          SAI_OUTPUTDRIVE_DISABLE        /* SAI输出驱动禁用宏定义（旧版本） */
#define SAI_OUTPUTDRIVE_ENABLED           SAI_OUTPUTDRIVE_ENABLE         /* SAI输出驱动使能宏定义（旧版本） */
#define SAI_MASTERDIVIDER_ENABLED         SAI_MASTERDIVIDER_ENABLE       /* SAI主分频器使能宏定义（旧版本） */
#define SAI_MASTERDIVIDER_DISABLED        SAI_MASTERDIVIDER_DISABLE      /* SAI主分频器禁用宏定义（旧版本） */
#define SAI_STREOMODE                     SAI_STEREOMODE                 /* SAI立体声模式宏定义（旧版本拼写错误） */
#define SAI_FIFOStatus_Empty              SAI_FIFOSTATUS_EMPTY           /* SAI FIFO空状态宏定义（旧版本） */
#define SAI_FIFOStatus_Less1QuarterFull   SAI_FIFOSTATUS_LESS1QUARTERFULL /* SAI FIFO少于1/4满状态宏定义（旧版本） */
#define SAI_FIFOStatus_1QuarterFull       SAI_FIFOSTATUS_1QUARTERFULL    /* SAI FIFO 1/4满状态宏定义（旧版本） */
#define SAI_FIFOStatus_HalfFull           SAI_FIFOSTATUS_HALFFULL        /* SAI FIFO半满状态宏定义（旧版本） */
#define SAI_FIFOStatus_3QuartersFull      SAI_FIFOSTATUS_3QUARTERFULL    /* SAI FIFO 3/4满状态宏定义（旧版本） */
#define SAI_FIFOStatus_Full               SAI_FIFOSTATUS_FULL            /* SAI FIFO满状态宏定义（旧版本） */
#define IS_SAI_BLOCK_MONO_STREO_MODE      IS_SAI_BLOCK_MONO_STEREO_MODE  /* SAI块单声道/立体声模式检查宏定义（旧版本拼写错误） */
#define SAI_SYNCHRONOUS_EXT               SAI_SYNCHRONOUS_EXT_SAI1       /* SAI外部同步宏定义（旧版本） */
#define SAI_SYNCEXT_IN_ENABLE             SAI_SYNCEXT_OUTBLOCKA_ENABLE   /* SAI外部同步输入使能宏定义（旧版本） */
/**
  * @}
  */

/** @defgroup HAL_SPDIFRX_Aliased_Macros HAL SPDIFRX Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined(STM32H7)
#define HAL_SPDIFRX_ReceiveControlFlow      HAL_SPDIFRX_ReceiveCtrlFlow      /* SPDIFRX接收控制流宏定义（旧版本） */
#define HAL_SPDIFRX_ReceiveControlFlow_IT   HAL_SPDIFRX_ReceiveCtrlFlow_IT   /* SPDIFRX接收控制流中断宏定义（旧版本） */
#define HAL_SPDIFRX_ReceiveControlFlow_DMA  HAL_SPDIFRX_ReceiveCtrlFlow_DMA  /* SPDIFRX接收控制流DMA宏定义（旧版本） */
#endif
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Functions HAL HRTIM Aliased Functions maintained for legacy purpose
  * @{
  */
#if defined (STM32H7) || defined (STM32G4) || defined (STM32F3)
#define HAL_HRTIM_WaveformCounterStart_IT      HAL_HRTIM_WaveformCountStart_IT   /* HRTIM波形计数器启动中断宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStart_DMA     HAL_HRTIM_WaveformCountStart_DMA  /* HRTIM波形计数器启动DMA宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStart         HAL_HRTIM_WaveformCountStart      /* HRTIM波形计数器启动宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStop_IT       HAL_HRTIM_WaveformCountStop_IT    /* HRTIM波形计数器停止中断宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStop_DMA      HAL_HRTIM_WaveformCountStop_DMA   /* HRTIM波形计数器停止DMA宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStop          HAL_HRTIM_WaveformCountStop       /* HRTIM波形计数器停止宏定义（旧版本） */
#endif
/**
  * @}
  */

/** @defgroup HAL_QSPI_Aliased_Macros HAL QSPI Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined (STM32L4) || defined (STM32F4) || defined (STM32F7) || defined(STM32H7)
#define HAL_QPSI_TIMEOUT_DEFAULT_VALUE HAL_QSPI_TIMEOUT_DEFAULT_VALUE  /* QSPI默认超时值宏定义（旧版本拼写错误） */
#endif /* STM32L4 || STM32F4 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_Generic_Aliased_Macros HAL Generic Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined (STM32F7)
#define ART_ACCLERATOR_ENABLE ART_ACCELERATOR_ENABLE  /* ART加速器使能宏定义（旧版本拼写错误） */
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