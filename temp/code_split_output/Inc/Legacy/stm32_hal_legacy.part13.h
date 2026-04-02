/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Macros HAL UART Aliased Macros maintained for legacy purpose
  * @{
  */

// 以下宏定义是为了兼容旧版本代码，将旧的宏名称映射到新的宏名称
// 获取UART时钟源
#define __HAL_UART_GETCLOCKSOURCE       UART_GETCLOCKSOURCE
// UART掩码计算
#define __HAL_UART_MASK_COMPUTATION     UART_MASK_COMPUTATION
// 以下为不带HAL前缀的旧宏定义，同样映射到新名称
#define __UART_GETCLOCKSOURCE           UART_GETCLOCKSOURCE
#define __UART_MASK_COMPUTATION         UART_MASK_COMPUTATION

// 检查UART唤醒方式是否有效（旧名称修正）
#define IS_UART_WAKEUPMETHODE           IS_UART_WAKEUPMETHOD

// 检查UART单比特采样模式是否有效（旧名称修正）
#define IS_UART_ONEBIT_SAMPLE           IS_UART_ONE_BIT_SAMPLE
// 同上，旧名称修正
#define IS_UART_ONEBIT_SAMPLING         IS_UART_ONE_BIT_SAMPLE

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Macros HAL USART Aliased Macros maintained for legacy purpose
  * @{
  */

// USART相关宏定义兼容
// 使能USART中断
#define __USART_ENABLE_IT               __HAL_USART_ENABLE_IT
// 禁能USART中断
#define __USART_DISABLE_IT              __HAL_USART_DISABLE_IT
// 使能USART外设
#define __USART_ENABLE                  __HAL_USART_ENABLE
// 禁能USART外设
#define __USART_DISABLE                 __HAL_USART_DISABLE

// 获取USART时钟源
#define __HAL_USART_GETCLOCKSOURCE      USART_GETCLOCKSOURCE
#define __USART_GETCLOCKSOURCE          USART_GETCLOCKSOURCE

// 针对STM32F0, F3, F7系列定义的过采样模式
#if defined(STM32F0) || defined(STM32F3) || defined(STM32F7)
// 16倍过采样模式
#define USART_OVERSAMPLING_16               0x00000000U
// 8倍过采样模式
#define USART_OVERSAMPLING_8                USART_CR1_OVER8

// 检查过采样参数是否有效
#define IS_USART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == USART_OVERSAMPLING_16) || \
                                             ((__SAMPLING__) == USART_OVERSAMPLING_8))
#endif /* STM32F0 || STM32F3 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_USB_Aliased_Macros HAL USB Aliased Macros maintained for legacy purpose
  * @{
  */
// USB唤醒外部中断线定义
#define USB_EXTI_LINE_WAKEUP                               USB_WAKEUP_EXTI_LINE

// USB FS (Full Speed) 外部中断触发方式定义
// 上升沿触发
#define USB_FS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE
// 下降沿触发
#define USB_FS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE
// 双边沿触发
#define USB_FS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE
// FS唤醒中断线
#define USB_FS_EXTI_LINE_WAKEUP                            USB_OTG_FS_WAKEUP_EXTI_LINE

// USB HS (High Speed) 外部中断触发方式定义
// 上升沿触发
#define USB_HS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE
// 下降沿触发
#define USB_HS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE
// 双边沿触发
#define USB_HS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE
// HS唤醒中断线
#define USB_HS_EXTI_LINE_WAKEUP                            USB_OTG_HS_WAKEUP_EXTI_LINE

// USB通用外部中断操作宏定义
// 使能USB外部中断
#define __HAL_USB_EXTI_ENABLE_IT                           __HAL_USB_WAKEUP_EXTI_ENABLE_IT
// 禁能USB外部中断
#define __HAL_USB_EXTI_DISABLE_IT                          __HAL_USB_WAKEUP_EXTI_DISABLE_IT
// 获取USB外部中断标志
#define __HAL_USB_EXTI_GET_FLAG                            __HAL_USB_WAKEUP_EXTI_GET_FLAG
// 清除USB外部中断标志
#define __HAL_USB_EXTI_CLEAR_FLAG                          __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG
// 设置上升沿触发
#define __HAL_USB_EXTI_SET_RISING_EDGE_TRIGGER             __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 设置下降沿触发
#define __HAL_USB_EXTI_SET_FALLING_EDGE_TRIGGER            __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 设置双边沿触发
#define __HAL_USB_EXTI_SET_FALLINGRISING_TRIGGER           __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE

// USB FS (Full Speed) 外部中断操作宏定义
#define __HAL_USB_FS_EXTI_ENABLE_IT                        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT
#define __HAL_USB_FS_EXTI_DISABLE_IT                       __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT
#define __HAL_USB_FS_EXTI_GET_FLAG                         __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG
#define __HAL_USB_FS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_USB_FS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE
#define __HAL_USB_FS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
#define __HAL_USB_FS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
// 产生软件中断
#define __HAL_USB_FS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT

// USB HS (High Speed) 外部中断操作宏定义
#define __HAL_USB_HS_EXTI_ENABLE_IT                        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT
#define __HAL_USB_HS_EXTI_DISABLE_IT                       __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT
#define __HAL_USB_HS_EXTI_GET_FLAG                         __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG
#define __HAL_USB_HS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_USB_HS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE
#define __HAL_USB_HS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
#define __HAL_USB_HS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
// 产生软件中断
#define __HAL_USB_HS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT

// PCD (Peripheral Control Driver) 外设控制驱动相关函数别名
// 激活远程唤醒
#define HAL_PCD_ActiveRemoteWakeup                         HAL_PCD_ActivateRemoteWakeup
// 关闭远程唤醒
#define HAL_PCD_DeActiveRemoteWakeup                       HAL_PCD_DeActivateRemoteWakeup

// 设置TX FIFO (发送缓冲区)
#define HAL_PCD_SetTxFiFo                                  HAL_PCDEx_SetTxFiFo
// 设置RX FIFO (接收缓冲区)
#define HAL_PCD_SetRxFiFo                                  HAL_PCDEx_SetRxFiFo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM Aliased Macros maintained for legacy purpose
  * @{
  */
// TIM (定时器) 相关宏定义兼容
// 设置输入捕获预分频值
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE
// 复位输入捕获预分频值
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE

// 获取中断状态
#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE
// 清除中断标志
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT

// 获取中断状态（旧名称）
#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE

// 获取定时器计数方向状态
#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN
// 设置预分频器
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER
// 设置计数器值
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER
// 获取计数器值
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER
// 设置自动重装载值
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD
// 获取自动重装载值
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD
// 设置时钟分频
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION
// 获取时钟分频
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION
// 设置输入捕获预分频
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER
// 获取输入捕获预分频
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER
// 设置比较值
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE
// 获取比较值
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE

// 断路输入源定义（DFSDM）
#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1

// 输出比较模式定义（修正拼写错误 ASSYMETRIC -> ASYMMETRIC）
#define TIM_OCMODE_ASSYMETRIC_PWM1      TIM_OCMODE_ASYMMETRIC_PWM1
#define TIM_OCMODE_ASSYMETRIC_PWM2      TIM_OCMODE_ASYMMETRIC_PWM2
/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Macros HAL ETH Aliased Macros maintained for legacy purpose
  * @{
  */

// ETH (以太网) 外部中断相关宏定义兼容
#define __HAL_ETH_EXTI_ENABLE_IT                   __HAL_ETH_WAKEUP_EXTI_ENABLE_IT
#define __HAL_ETH_EXTI_DISABLE_IT                  __HAL_ETH_WAKEUP_EXTI_DISABLE_IT
#define __HAL_ETH_EXTI_GET_FLAG                    __HAL_ETH_WAKEUP_EXTI_GET_FLAG
#define __HAL_ETH_EXTI_CLEAR_FLAG                  __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG
#define __HAL_ETH_EXTI_SET_RISING_EGDE_TRIGGER     __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER
#define __HAL_ETH_EXTI_SET_FALLING_EGDE_TRIGGER    __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER
#define __HAL_ETH_EXTI_SET_FALLINGRISING_TRIGGER   __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER

// 混杂模式使能/失能（修正拼写 PROMISCIOUS -> PROMISCUOUS）
#define ETH_PROMISCIOUSMODE_ENABLE   ETH_PROMISCUOUS_MODE_ENABLE
#define ETH_PROMISCIOUSMODE_DISABLE  ETH_PROMISCUOUS_MODE_DISABLE
#define IS_ETH_PROMISCIOUS_MODE      IS_ETH_PROMISCUOUS_MODE
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Macros HAL LTDC Aliased Macros maintained for legacy purpose
  * @{
  */
// LTDC (LCD-TFT控制器) 相关宏定义兼容
// 层配置
#define __HAL_LTDC_LAYER LTDC_LAYER
// 重载配置
#define __HAL_LTDC_RELOAD_CONFIG  __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG
/**
  * @}
  */

/** @defgroup HAL_SAI_Aliased_Macros HAL SAI Aliased Macros maintained for legacy purpose
  * @{
  */
// SAI (串行音频接口) 相关宏定义兼容
// 输出驱动使能/失能
#define SAI_OUTPUTDRIVE_DISABLED          SAI_OUTPUTDRIVE_DISABLE
#define SAI_OUTPUTDRIVE_ENABLED           SAI_OUTPUTDRIVE_ENABLE
// 主时钟分频器使能/失能
#define SAI_MASTERDIVIDER_ENABLED         SAI_MASTERDIVIDER_ENABLE
#define SAI_MASTERDIVIDER_DISABLED        SAI_MASTERDIVIDER_DISABLE
// 立体声模式（修正拼写 STREO -> STEREO）
#define SAI_STREOMODE                     SAI_STEREOMODE
// FIFO状态定义
#define SAI_FIFOStatus_Empty              SAI_FIFOSTATUS_EMPTY
#define SAI_FIFOStatus_Less1QuarterFull   SAI_FIFOSTATUS_LESS1QUARTERFULL
#define SAI_FIFOStatus_1QuarterFull       SAI_FIFOSTATUS_1QUARTERFULL
#define SAI_FIFOStatus_HalfFull           SAI_FIFOSTATUS_HALFFULL
#define SAI_FIFOStatus_3QuartersFull      SAI_FIFOSTATUS_3QUARTERFULL
#define SAI_FIFOStatus_Full               SAI_FIFOSTATUS_FULL
// 检查单声道/立体声模式（修正拼写）
#define IS_SAI_BLOCK_MONO_STREO_MODE      IS_SAI_BLOCK_MONO_STEREO_MODE
// 同步配置
#define SAI_SYNCHRONOUS_EXT               SAI_SYNCHRONOUS_EXT_SAI1
#define SAI_SYNCEXT_IN_ENABLE             SAI_SYNCEXT_OUTBLOCKA_ENABLE
/**
  * @}
  */

/** @defgroup HAL_SPDIFRX_Aliased_Macros HAL SPDIFRX Aliased Macros maintained for legacy purpose
  * @{
  */
// SPDIFRX (SPDIF接收器) 相关定义，仅适用于STM32H7系列
#if defined(STM32H7)
// 接收控制流数据
#define HAL_SPDIFRX_ReceiveControlFlow      HAL_SPDIFRX_ReceiveCtrlFlow
// 中断模式接收控制流数据
#define HAL_SPDIFRX_ReceiveControlFlow_IT   HAL_SPDIFRX_ReceiveCtrlFlow_IT
// DMA模式接收控制流数据
#define HAL_SPDIFRX_ReceiveControlFlow_DMA  HAL_SPDIFRX_ReceiveCtrlFlow_DMA
#endif
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Macros HAL HRTIM Aliased Functions maintained for legacy purpose
  * @{
  */
// HRTIM (高分辨率定时器) 函数别名，适用于STM32H7, G4, F3系列
#if defined (STM32H7) || defined (STM32G4) || defined (STM32F3)
// 启动波形计数器（中断模式）
#define HAL_HRTIM_WaveformCounterStart_IT      HAL_HRTIM_WaveformCountStart_IT
// 启动波形计数器（DMA模式）
#define HAL_HRTIM_WaveformCounterStart_DMA     HAL_HRTIM_WaveformCountStart_DMA
// 启动波形计数器
#define HAL_HRTIM_WaveformCounterStart         HAL_HRTIM_WaveformCountStart
// 停止波形计数器（中断模式）
#define HAL_HRTIM_WaveformCounterStop_IT       HAL_HRTIM_WaveformCountStop_IT
// 停止波形计数器（DMA模式）
#define HAL_HRTIM_WaveformCounterStop_DMA      HAL_HRTIM_WaveformCountStop_DMA
// 停止波形计数器
#define HAL_HRTIM_WaveformCounterStop          HAL_HRTIM_WaveformCountStop
#endif
/**
  * @}
  */

/** @defgroup HAL_QSPI_Aliased_Macros HAL QSPI Aliased Macros maintained for legacy purpose
  * @{
  */
// QSPI (四线SPI) 默认超时值定义，适用于L4, F4, F7, H7系列
#if defined (STM32L4) || defined (STM32F4) || defined (STM32F7) || defined(STM32H7)
// 修正拼写 QPSI -> QSPI
#define HAL_QPSI_TIMEOUT_DEFAULT_VALUE HAL_QSPI_TIMEOUT_DEFAULT_VALUE
#endif /* STM32L4 || STM32F4 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_Generic_Aliased_Macros HAL Generic Aliased Macros maintained for legacy purpose
  * @{
  */
// 通用宏定义，适用于STM32F7系列
#if defined (STM32F7)
// ART加速器使能（修正拼写 ACCLERATOR -> ACCELERATOR）
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

// C++编译环境支持
#ifdef __cplusplus
}
#endif

// 头文件结束保护
#endif /* STM32_HAL_LEGACY */

