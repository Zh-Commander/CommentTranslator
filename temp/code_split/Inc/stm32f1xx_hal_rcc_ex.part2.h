
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_USB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USB_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_USBEN))
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined  (STM32F100xE)
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CEC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#define __HAL_RCC_CEC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_CECEN))
#endif /* STM32F100xB || STM32F100xE */

#ifdef STM32F100xE
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#endif /* STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_CAN2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CAN2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN2EN))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
