#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
// 使能USB时钟的宏定义
// 采用do...while(0)结构是为了确保宏定义在使用时能像函数一样安全调用，避免分号错误
#define __HAL_RCC_USB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \ // 定义一个临时变量，用于产生延时
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\ // 设置APB1外设时钟使能寄存器中的USB使能位
                                        /* Delay after an RCC peripheral clock enabling */ \ // RCC外设时钟使能后的延时
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\ // 读取刚设置的位，确保写入操作完成（硬件延时）
                                        UNUSED(tmpreg); \ // 避免编译器产生“变量未使用”的警告
                                      } while(0U)

// 关闭USB时钟的宏定义
// 直接操作APB1ENR寄存器，清除USB使能位
#define __HAL_RCC_USB_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_USBEN))
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
// 使能TIM5定时器时钟
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM6定时器时钟
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM7定时器时钟
#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能SPI3串行外设接口时钟
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能UART4串口4时钟
#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能UART5串口5时钟
#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能DAC数模转换器时钟
#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 关闭TIM5定时器时钟
#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
// 关闭TIM6定时器时钟
#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
// 关闭TIM7定时器时钟
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
// 关闭SPI3串行外设接口时钟
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
// 关闭UART4串口4时钟
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
// 关闭UART5串口5时钟
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
// 关闭DAC数模转换器时钟
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined  (STM32F100xE)
// 使能TIM6定时器时钟
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM7定时器时钟
#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能DAC数模转换器时钟
#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能CEC(消费电子控制)时钟
#define __HAL_RCC_CEC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 关闭TIM6定时器时钟
#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
// 关闭TIM7定时器时钟
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
// 关闭DAC数模转换器时钟
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
// 关闭CEC时钟
#define __HAL_RCC_CEC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_CECEN))
#endif /* STM32F100xB || STM32F100xE */

#ifdef STM32F100xE
// 使能TIM5定时器时钟
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM12定时器时钟
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM13定时器时钟
#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM14定时器时钟
#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能SPI3串行外设接口时钟
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能UART4串口4时钟
#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能UART5串口5时钟
#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 关闭TIM5定时器时钟
#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
// 关闭TIM12定时器时钟
#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
// 关闭TIM13定时器时钟
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
// 关闭TIM14定时器时钟
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
// 关闭SPI3串行外设接口时钟
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
// 关闭UART4串口4时钟
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
// 关闭UART5串口5时钟
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#endif /* STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
// 使能CAN2控制器局域网时钟
#define __HAL_RCC_CAN2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 关闭CAN2时钟
#define __HAL_RCC_CAN2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN2EN))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F101xG) || defined(STM32F103xG)
// 使能TIM12定时器时钟
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM13定时器时钟
#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM14定时器时钟
#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 关闭TIM12定时器时钟
#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
// 关闭TIM13定时器时钟
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
// 关闭TIM14定时器时钟
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB1 peripheral clock.
  *         获取APB1外设时钟的使能或禁用状态。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是被禁用的，
  *         应用程序在使用前必须使能该时钟。
  * @{
  */
