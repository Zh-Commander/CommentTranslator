
#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) != RESET)
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) == RESET)
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) != RESET)
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) == RESET)
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
#define __HAL_RCC_USART3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) != RESET)
#define __HAL_RCC_USART3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) == RESET)
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_USB_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) != RESET)
#define __HAL_RCC_USB_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) == RESET)
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F100xB) || defined  (STM32F100xE)
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#define __HAL_RCC_CEC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) != RESET)
#define __HAL_RCC_CEC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) == RESET)
#endif /* STM32F100xB || STM32F100xE */
#ifdef STM32F100xE
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) != RESET)
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) == RESET)
#endif /* STM32F100xE */
#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#endif /* STM32F105xC || STM32F107xC */
#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Clock_Enable_Disable APB2 Clock Enable Disable
  * @brief  Enable or disable the High Speed APB (APB2) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
#define __HAL_RCC_ADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC2_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC2EN))
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */

#if defined(STM32F100xB) || defined(STM32F100xE)
#define __HAL_RCC_TIM15_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM16_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM17_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM15_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15EN))
#define __HAL_RCC_TIM16_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16EN))
#define __HAL_RCC_TIM17_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17EN))
#endif /* STM32F100xB || STM32F100xE */

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOE_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPEEN))
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/

#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM8_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
#define __HAL_RCC_ADC3_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC3EN))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F100xE)
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif /* STM32F100xE */

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM9_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM10_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM11_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM9_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
#define __HAL_RCC_TIM10_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM10EN))
#define __HAL_RCC_TIM11_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
