/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Macros HAL UART 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

// 宏定义：获取UART时钟源（旧版宏 __HAL_UART_GETCLOCKSOURCE 映射到新版 UART_GETCLOCKSOURCE）
#define __HAL_UART_GETCLOCKSOURCE       UART_GETCLOCKSOURCE
// 宏定义：计算UART掩码（旧版宏 __HAL_UART_MASK_COMPUTATION 映射到新版 UART_MASK_COMPUTATION）
#define __HAL_UART_MASK_COMPUTATION     UART_MASK_COMPUTATION
// 宏定义：获取UART时钟源（旧版命名方式，映射到新版 UART_GETCLOCKSOURCE）
#define __UART_GETCLOCKSOURCE           UART_GETCLOCKSOURCE
// 宏定义：计算UART掩码（旧版命名方式，映射到新版 UART_MASK_COMPUTATION）
#define __UART_MASK_COMPUTATION         UART_MASK_COMPUTATION

// 宏定义：检查UART唤醒方法是否有效（修正了旧版拼写错误 METHODE -> METHOD）
#define IS_UART_WAKEUPMETHODE           IS_UART_WAKEUPMETHOD

// 宏定义：检查是否为单比特采样模式（旧版宏 IS_UART_ONEBIT_SAMPLE 映射到新版 IS_UART_ONE_BIT_SAMPLE）
#define IS_UART_ONEBIT_SAMPLE           IS_UART_ONE_BIT_SAMPLE
// 宏定义：检查是否为单比特采样模式（旧版别名，映射到新版 IS_UART_ONE_BIT_SAMPLE）
#define IS_UART_ONEBIT_SAMPLING         IS_UART_ONE_BIT_SAMPLE

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Macros HAL USART 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

// 宏定义：使能USART中断（旧版宏映射到新版 __HAL_USART_ENABLE_IT）
#define __USART_ENABLE_IT               __HAL_USART_ENABLE_IT
// 宏定义：禁能USART中断（旧版宏映射到新版 __HAL_USART_DISABLE_IT）
#define __USART_DISABLE_IT              __HAL_USART_DISABLE_IT
// 宏定义：使能USART（旧版宏映射到新版 __HAL_USART_ENABLE）
#define __USART_ENABLE                  __HAL_USART_ENABLE
// 宏定义：禁能USART（旧版宏映射到新版 __HAL_USART_DISABLE）
#define __USART_DISABLE                 __HAL_USART_DISABLE

// 宏定义：获取USART时钟源（旧版宏映射到新版 USART_GETCLOCKSOURCE）
#define __HAL_USART_GETCLOCKSOURCE      USART_GETCLOCKSOURCE
// 宏定义：获取USART时钟源（旧版命名方式，映射到新版 USART_GETCLOCKSOURCE）
#define __USART_GETCLOCKSOURCE          USART_GETCLOCKSOURCE

// 条件编译：仅适用于 STM32F0, STM32F3, STM32F7 系列芯片
#if defined(STM32F0) || defined(STM32F3) || defined(STM32F7)
// 宏定义：USART 16倍过采样模式（值为0，即不设置OVER8位）
#define USART_OVERSAMPLING_16               0x00000000U
// 宏定义：USART 8倍过采样模式（值为 USART_CR1_OVER8 寄存器位）
#define USART_OVERSAMPLING_8                USART_CR1_OVER8

// 宏定义：检查USART过采样参数是否有效（必须是16倍或8倍过采样之一）
#define IS_USART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == USART_OVERSAMPLING_16) || \
                                             ((__SAMPLING__) == USART_OVERSAMPLING_8))
#endif /* STM32F0 || STM32F3 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_USB_Aliased_Macros HAL USB 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：USB唤醒外部中断线（旧版宏映射到新版 USB_WAKEUP_EXTI_LINE）
#define USB_EXTI_LINE_WAKEUP                               USB_WAKEUP_EXTI_LINE

// 宏定义：USB全速外部中断上升沿触发（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE）
#define USB_FS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE
// 宏定义：USB全速外部中断下降沿触发（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE）
#define USB_FS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE
// 宏定义：USB全速外部中断双边沿触发（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE）
#define USB_FS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE
// 宏定义：USB全速唤醒外部中断线（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_LINE）
#define USB_FS_EXTI_LINE_WAKEUP                            USB_OTG_FS_WAKEUP_EXTI_LINE

// 宏定义：USB高速外部中断上升沿触发（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE）
#define USB_HS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE
// 宏定义：USB高速外部中断下降沿触发（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE）
#define USB_HS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE
// 宏定义：USB高速外部中断双边沿触发（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE）
#define USB_HS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE
// 宏定义：USB高速唤醒外部中断线（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_LINE）
#define USB_HS_EXTI_LINE_WAKEUP                            USB_OTG_HS_WAKEUP_EXTI_LINE

// 宏定义：使能USB唤醒外部中断（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_USB_EXTI_ENABLE_IT                           __HAL_USB_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能USB唤醒外部中断（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_USB_EXTI_DISABLE_IT                          __HAL_USB_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取USB唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_GET_FLAG）
#define __HAL_USB_EXTI_GET_FLAG                            __HAL_USB_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除USB唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_USB_EXTI_CLEAR_FLAG                          __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置USB唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE）
#define __HAL_USB_EXTI_SET_RISING_EDGE_TRIGGER             __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 宏定义：设置USB唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE）
#define __HAL_USB_EXTI_SET_FALLING_EDGE_TRIGGER            __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 宏定义：设置USB唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE）
#define __HAL_USB_EXTI_SET_FALLINGRISING_TRIGGER           __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE

// 宏定义：使能USB OTG全速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_USB_FS_EXTI_ENABLE_IT                        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能USB OTG全速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_USB_FS_EXTI_DISABLE_IT                       __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取USB OTG全速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG）
#define __HAL_USB_FS_EXTI_GET_FLAG                         __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除USB OTG全速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_USB_FS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置USB OTG全速唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE）
#define __HAL_USB_FS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 宏定义：设置USB OTG全速唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE）
#define __HAL_USB_FS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 宏定义：设置USB OTG全速唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE）
#define __HAL_USB_FS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
// 宏定义：USB OTG全速唤醒外部中断软件中断触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT）
#define __HAL_USB_FS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT

// 宏定义：使能USB OTG高速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_USB_HS_EXTI_ENABLE_IT                        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能USB OTG高速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_USB_HS_EXTI_DISABLE_IT                       __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取USB OTG高速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG）
#define __HAL_USB_HS_EXTI_GET_FLAG                         __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除USB OTG高速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_USB_HS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置USB OTG高速唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE）
#define __HAL_USB_HS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 宏定义：设置USB OTG高速唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE）
#define __HAL_USB_HS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 宏定义：设置USB OTG高速唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE）
#define __HAL_USB_HS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
// 宏定义：USB OTG高速唤醒外部中断软件中断触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT）
#define __HAL_USB_HS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT

// 宏定义：激活PCD远程唤醒（旧版宏 Active 映射到新版 Activate）
#define HAL_PCD_ActiveRemoteWakeup                         HAL_PCD_ActivateRemoteWakeup
// 宏定义：去激活PCD远程唤醒（旧版宏 DeActive 映射到新版 DeActivate）
#define HAL_PCD_DeActiveRemoteWakeup                       HAL_PCD_DeActivateRemoteWakeup

// 宏定义：设置PCD发送FIFO（旧版宏映射到扩展功能 HAL_PCDEx_SetTxFiFo）
#define HAL_PCD_SetTxFiFo                                  HAL_PCDEx_SetTxFiFo
// 宏定义：设置PCD接收FIFO（旧版宏映射到扩展功能 HAL_PCDEx_SetRxFiFo）
#define HAL_PCD_SetRxFiFo                                  HAL_PCDEx_SetRxFiFo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：设置定时器输入捕获预分频值（旧版宏映射到新版 TIM_SET_ICPRESCALERVALUE）
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE
// 宏定义：重置定时器输入捕获预分频值（旧版宏映射到新版 TIM_RESET_ICPRESCALERVALUE）
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE

// 宏定义：获取定时器中断状态（旧版宏映射到新版 __HAL_TIM_GET_IT_SOURCE）
#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE
// 宏定义：清除定时器中断标志（旧版宏映射到新版 __HAL_TIM_CLEAR_IT）
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT

// 宏定义：获取定时器中断状态（旧版宏映射到新版 __HAL_TIM_GET_IT_SOURCE）
#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE

// 宏定义：获取定时器计数方向状态（旧版宏映射到新版 __HAL_TIM_IS_TIM_COUNTING_DOWN）
#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN
// 宏定义：设置定时器预分频值（旧版宏映射到新版 __HAL_TIM_SET_PRESCALER）
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER
// 宏定义：设置定时器计数器值（旧版宏映射到新版 __HAL_TIM_SET_COUNTER）
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER
// 宏定义：获取定时器计数器值（旧版宏映射到新版 __HAL_TIM_GET_COUNTER）
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER
// 宏定义：设置定时器自动重装载值（旧版宏映射到新版 __HAL_TIM_SET_AUTORELOAD）
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD
// 宏定义：获取定时器自动重装载值（旧版宏映射到新版 __HAL_TIM_GET_AUTORELOAD）
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD
// 宏定义：设置定时器时钟分频（旧版宏映射到新版 __HAL_TIM_SET_CLOCKDIVISION）
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION
// 宏定义：获取定时器时钟分频（旧版宏映射到新版 __HAL_TIM_GET_CLOCKDIVISION）
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION
// 宏定义：设置定时器输入捕获预分频（旧版宏映射到新版 __HAL_TIM_SET_ICPRESCALER）
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER
// 宏定义：获取定时器输入捕获预分频（旧版宏映射到新版 __HAL_TIM_GET_ICPRESCALER）
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER
// 宏定义：设置定时器比较值（旧版宏映射到新版 __HAL_TIM_SET_COMPARE）
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE
// 宏定义：获取定时器比较值（旧版宏映射到新版 __HAL_TIM_GET_COMPARE）
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE

// 宏定义：定时器断路输入源 DFSDM（旧版宏映射到新版 TIM_BREAKINPUTSOURCE_DFSDM1）
#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1

// 宏定义：非对称PWM模式1（修正拼写错误 ASSYMETRIC -> ASYMMETRIC）
#define TIM_OCMODE_ASSYMETRIC_PWM1      TIM_OCMODE_ASYMMETRIC_PWM1
// 宏定义：非对称PWM模式2（修正拼写错误 ASSYMETRIC -> ASYMMETRIC）
#define TIM_OCMODE_ASSYMETRIC_PWM2      TIM_OCMODE_ASYMMETRIC_PWM2
/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Macros HAL ETH 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

// 宏定义：使能以太网唤醒外部中断（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_ETH_EXTI_ENABLE_IT                   __HAL_ETH_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能以太网唤醒外部中断（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_ETH_EXTI_DISABLE_IT                  __HAL_ETH_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取以太网唤醒外部中断标志（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_GET_FLAG）
#define __HAL_ETH_EXTI_GET_FLAG                    __HAL_ETH_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除以太网唤醒外部中断标志（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_ETH_EXTI_CLEAR_FLAG                  __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置以太网唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER）
#define __HAL_ETH_EXTI_SET_RISING_EGDE_TRIGGER     __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER
// 宏定义：设置以太网唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER）
#define __HAL_ETH_EXTI_SET_FALLING_EGDE_TRIGGER    __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER
// 宏定义：设置以太网唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER）
#define __HAL_ETH_EXTI_SET_FALLINGRISING_TRIGGER   __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER

// 宏定义：使能以太网混杂模式（修正拼写错误 PROMISCIOUS -> PROMISCUOUS）
#define ETH_PROMISCIOUSMODE_ENABLE   ETH_PROMISCUOUS_MODE_ENABLE
// 宏定义：禁能以太网混杂模式（修正拼写错误 PROMISCIOUS -> PROMISCUOUS）
#define ETH_PROMISCIOUSMODE_DISABLE  ETH_PROMISCUOUS_MODE_DISABLE
// 宏定义：检查是否为以太网混杂模式（修正拼写错误 PROMISCIOUS -> PROMISCUOUS）
#define IS_ETH_PROMISCIOUS_MODE      IS_ETH_PROMISCUOUS_MODE
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Macros HAL LTDC 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：获取LTDC层（旧版宏映射到新版 LTDC_LAYER）
#define __HAL_LTDC_LAYER LTDC_LAYER
// 宏定义：立即重载LTDC配置（旧版宏映射到新版 __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG）
#define __HAL_LTDC_RELOAD_CONFIG  __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG
/**
  * @}
  */

/** @defgroup HAL_SAI_Aliased_Macros HAL SAI 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：SAI输出驱动禁能（旧版宏 DISABLED 映射到新版 DISABLE）
#define SAI_OUTPUTDRIVE_DISABLED          SAI_OUTPUTDRIVE_DISABLE
// 宏定义：SAI输出驱动使能（旧版宏 ENABLED 映射到新版 ENABLE）
#define SAI_OUTPUTDRIVE_ENABLED           SAI_OUTPUTDRIVE_ENABLE
// 宏定义：SAI主分频器使能（旧版宏 ENABLED 映射到新版 ENABLE）
#define SAI_MASTERDIVIDER_ENABLED         SAI_MASTERDIVIDER_ENABLE
// 宏定义：SAI主分频器禁能（旧版宏 DISABLED 映射到新版 DISABLE）
#define SAI_MASTERDIVIDER_DISABLED        SAI_MASTERDIVIDER_DISABLE
// 宏定义：SAI立体声模式（修正拼写错误 STREOMODE -> STEREOMODE）
#define SAI_STREOMODE                     SAI_STEREOMODE
// 宏定义：SAI FIFO状态为空（修正大小写命名风格）
#define SAI_FIFOStatus_Empty              SAI_FIFOSTATUS_EMPTY
// 宏定义：SAI FIFO状态少于1/4满（修正大小写命名风格）
#define SAI_FIFOStatus_Less1QuarterFull   SAI_FIFOSTATUS_LESS1QUARTERFULL
// 宏定义：SAI FIFO状态1/4满（修正大小写命名风格）
#define SAI_FIFOStatus_1QuarterFull       SAI_FIFOSTATUS_1QUARTERFULL
// 宏定义：SAI FIFO状态半满（修正大小写命名风格）
#define SAI_FIFOStatus_HalfFull           SAI_FIFOSTATUS_HALFFULL
// 宏定义：SAI FIFO状态3/4满（修正大小写命名风格）
#define SAI_FIFOStatus_3QuartersFull      SAI_FIFOSTATUS_3QUARTERFULL
// 宏定义：SAI FIFO状态满（修正大小写命名风格）
#define SAI_FIFOStatus_Full               SAI_FIFOSTATUS_FULL
// 宏定义：检查SAI块单声道/立体声模式（修正拼写错误 STREO -> STEREO）
#define IS_SAI_BLOCK_MONO_STREO_MODE      IS_SAI_BLOCK_MONO_STEREO_MODE
// 宏定义：SAI同步模式：外部同步（映射到具体的SAI1外部同步）
#define SAI_SYNCHRONOUS_EXT               SAI_SYNCHRONOUS_EXT_SAI1
// 宏定义：SAI外部同步输入使能（映射到输出块A使能）
#define SAI_SYNCEXT_IN_ENABLE             SAI_SYNCEXT_OUTBLOCKA_ENABLE
/**
  * @}
  */

/** @defgroup HAL_SPDIFRX_Aliased_Macros HAL SPDIFRX 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32H7 系列芯片
#if defined(STM32H7)
// 宏定义：SPDIFRX接收控制流（旧版函数名 ControlFlow 映射到新版 CtrlFlow）
#define HAL_SPDIFRX_ReceiveControlFlow      HAL_SPDIFRX_ReceiveCtrlFlow
// 宏定义：SPDIFRX中断模式接收控制流（旧版函数名 ControlFlow 映射到新版 CtrlFlow）
#define HAL_SPDIFRX_ReceiveControlFlow_IT   HAL_SPDIFRX_ReceiveCtrlFlow_IT
// 宏定义：SPDIFRX DMA模式接收控制流（旧版函数名 ControlFlow 映射到新版 CtrlFlow）
#define HAL_SPDIFRX_ReceiveControlFlow_DMA  HAL_SPDIFRX_ReceiveCtrlFlow_DMA
#endif
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Functions HAL HRTIM 旧版别名函数（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32H7, STM32G4, STM32F3 系列芯片
#if defined (STM32H7) || defined (STM32G4) || defined (STM32F3)
// 宏定义：HRTIM波形计数器中断启动（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStart_IT      HAL_HRTIM_WaveformCountStart_IT
// 宏定义：HRTIM波形计数器DMA启动（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStart_DMA     HAL_HRTIM_WaveformCountStart_DMA
// 宏定义：HRTIM波形计数器启动（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStart         HAL_HRTIM_WaveformCountStart
// 宏定义：HRTIM波形计数器中断停止（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStop_IT       HAL_HRTIM_WaveformCountStop_IT
// 宏定义：HRTIM波形计数器DMA停止（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStop_DMA      HAL_HRTIM_WaveformCountStop_DMA
// 宏定义：HRTIM波形计数器停止（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStop          HAL_HRTIM_WaveformCountStop
#endif
/**
  * @}
  */

/** @defgroup HAL_QSPI_Aliased_Macros HAL QSPI 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32L4, STM32F4, STM32F7, STM32H7 系列芯片
#if defined (STM32L4) || defined (STM32F4) || defined (STM32F7) || defined(STM32H7)
// 宏定义：QSPI默认超时值（修正拼写错误 QPSI -> QSPI）
#define HAL_QPSI_TIMEOUT_DEFAULT_VALUE HAL_QSPI_TIMEOUT_DEFAULT_VALUE
#endif /* STM32L4 || STM32F4 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_Generic_Aliased_Macros HAL 通用旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32F7 系列芯片
#if defined (STM32F7)
// 宏定义：ART加速器使能（修正拼写错误 ACCLERATOR -> ACCELERATOR）
#define ART_ACCLERATOR_ENABLE ART_ACCELERATOR_ENABLE
#endif /* STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_PPP_Aliased_Macros HAL PPP 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

/**
  * @}
  */

// 结束 C++ extern "C" 块
#ifdef __cplusplus
}
#endif

// 结束 STM32_HAL_LEGACY 宏定义保护
#endif /* STM32_HAL_LEGACY */

