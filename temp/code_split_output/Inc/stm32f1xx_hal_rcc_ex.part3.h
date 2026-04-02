#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
// 检查CAN1时钟是否已使能：读取APB1ENR寄存器，判断CAN1EN位是否置1
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) != RESET)
// 检查CAN1时钟是否已禁用：读取APB1ENR寄存器，判断CAN1EN位是否清零
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) == RESET)
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
// 检查TIM4时钟是否已使能
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) != RESET)
// 检查TIM4时钟是否已禁用
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) == RESET)
// 检查SPI2时钟是否已使能
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
// 检查SPI2时钟是否已禁用
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
// 检查USART3时钟是否已使能
#define __HAL_RCC_USART3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) != RESET)
// 检查USART3时钟是否已禁用
#define __HAL_RCC_USART3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) == RESET)
// 检查I2C2时钟是否已使能
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
// 检查I2C2时钟是否已禁用
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
// 检查USB时钟是否已使能
#define __HAL_RCC_USB_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) != RESET)
// 检查USB时钟是否已禁用
#define __HAL_RCC_USB_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) == RESET)
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
// 检查TIM5时钟是否已使能
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
// 检查TIM5时钟是否已禁用
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
// 检查TIM6时钟是否已使能
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
// 检查TIM6时钟是否已禁用
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
// 检查TIM7时钟是否已使能
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
// 检查TIM7时钟是否已禁用
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
// 检查SPI3时钟是否已使能
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
// 检查SPI3时钟是否已禁用
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
// 检查UART4时钟是否已使能
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
// 检查UART4时钟是否已禁用
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
// 检查UART5时钟是否已使能
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
// 检查UART5时钟是否已禁用
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
// 检查DAC时钟是否已使能
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
// 检查DAC时钟是否已禁用
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F100xB) || defined  (STM32F100xE)
// 检查TIM6时钟是否已使能
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
// 检查TIM6时钟是否已禁用
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
// 检查TIM7时钟是否已使能
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
// 检查TIM7时钟是否已禁用
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
// 检查DAC时钟是否已使能
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
// 检查DAC时钟是否已禁用
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
// 检查CEC(消费电子控制)时钟是否已使能
#define __HAL_RCC_CEC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) != RESET)
// 检查CEC时钟是否已禁用
#define __HAL_RCC_CEC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) == RESET)
#endif /* STM32F100xB || STM32F100xE */
#ifdef STM32F100xE
// 检查TIM5时钟是否已使能
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
// 检查TIM5时钟是否已禁用
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
// 检查TIM12时钟是否已使能
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
// 检查TIM12时钟是否已禁用
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
// 检查TIM13时钟是否已使能
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
// 检查TIM13时钟是否已禁用
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
// 检查TIM14时钟是否已使能
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
// 检查TIM14时钟是否已禁用
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
// 检查SPI3时钟是否已使能
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
// 检查SPI3时钟是否已禁用
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
// 检查UART4时钟是否已使能
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
// 检查UART4时钟是否已禁用
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
// 检查UART5时钟是否已使能
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
// 检查UART5时钟是否已禁用
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
// 检查CAN2时钟是否已使能
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) != RESET)
// 检查CAN2时钟是否已禁用
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) == RESET)
#endif /* STM32F100xE */
#if defined(STM32F105xC) || defined(STM32F107xC)
// 检查TIM12时钟是否已使能
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
// 检查TIM12时钟是否已禁用
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#endif /* STM32F105xC || STM32F107xC */
#if defined(STM32F101xG) || defined(STM32F103xG)
// 检查TIM13时钟是否已使能
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
// 检查TIM13时钟是否已禁用
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
// 检查TIM14时钟是否已使能
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
// 检查TIM14时钟是否已禁用
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Clock_Enable_Disable APB2 Clock Enable Disable
  * @brief  Enable or disable the High Speed APB (APB2) peripheral clock.
  *         使能或禁用高速APB(APB2)外设时钟。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是禁用状态，应用程序在使用前必须使能该时钟。
  * @{
  */

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
// 使能ADC2时钟
// 宏实现原理：
// 1. 使用SET_BIT宏将RCC->APB2ENR寄存器中的ADC2EN位置1，从而开启时钟
// 2. 读取该位到tmpreg变量中，这并非无用操作，而是为了确保时钟使能操作完成后再继续执行后续代码
//    这通常是为了应对MCU流水线设计，防止后续对外设的访问因时钟未稳定而出错
#define __HAL_RCC_ADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* RCC外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用ADC2时钟：将RCC->APB2ENR寄存器中的ADC2EN位清零
#define __HAL_RCC_ADC2_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC2EN))
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */

#if defined(STM32F100xB) || defined(STM32F100xE)
// 使能TIM15时钟
#define __HAL_RCC_TIM15_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM16时钟
#define __HAL_RCC_TIM16_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM17时钟
#define __HAL_RCC_TIM17_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用TIM15时钟
#define __HAL_RCC_TIM15_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15EN))
// 禁用TIM16时钟
#define __HAL_RCC_TIM16_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16EN))
// 禁用TIM17时钟
#define __HAL_RCC_TIM17_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17EN))
#endif /* STM32F100xB || STM32F100xE */

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
// 使能GPIOE时钟
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用GPIOE时钟
#define __HAL_RCC_GPIOE_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPEEN))
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
// 使能GPIOF时钟
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能GPIOG时钟
#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用GPIOF时钟
#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
// 禁用GPIOG时钟
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/

#if defined(STM32F103xE) || defined(STM32F103xG)
// 使能TIM8时钟
#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能ADC3时钟
#define __HAL_RCC_ADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用TIM8时钟
#define __HAL_RCC_TIM8_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
// 禁用ADC3时钟
#define __HAL_RCC_ADC3_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC3EN))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F100xE)
// 使能GPIOF时钟
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能GPIOG时钟
#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用GPIOF时钟
#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
// 禁用GPIOG时钟
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif /* STM32F100xE */

#if defined(STM32F101xG) || defined(STM32F103xG)
// 使能TIM9时钟
#define __HAL_RCC_TIM9_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM10时钟
#define __HAL_RCC_TIM10_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM11时钟
#define __HAL_RCC_TIM11_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 禁用TIM9时钟
#define __HAL_RCC_TIM9_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
// 禁用TIM10时钟
#define __HAL_RCC_TIM10_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM10EN))
// 禁用TIM11时钟
#define __HAL_RCC_TIM11_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB2 peripheral clock.
  *         获取APB2外设时钟的使能或禁用状态。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是禁用状态，应用程序在使用前必须使能该时钟。
  * @{
  */
