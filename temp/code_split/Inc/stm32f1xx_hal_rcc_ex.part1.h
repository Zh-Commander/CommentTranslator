
/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_Prediv1_Factor HSE Prediv1 Factor
  * @{
  */

#define RCC_HSE_PREDIV_DIV1              0x00000000U

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR2_PREDIV1_DIV2
#define RCC_HSE_PREDIV_DIV3              RCC_CFGR2_PREDIV1_DIV3
#define RCC_HSE_PREDIV_DIV4              RCC_CFGR2_PREDIV1_DIV4
#define RCC_HSE_PREDIV_DIV5              RCC_CFGR2_PREDIV1_DIV5
#define RCC_HSE_PREDIV_DIV6              RCC_CFGR2_PREDIV1_DIV6
#define RCC_HSE_PREDIV_DIV7              RCC_CFGR2_PREDIV1_DIV7
#define RCC_HSE_PREDIV_DIV8              RCC_CFGR2_PREDIV1_DIV8
#define RCC_HSE_PREDIV_DIV9              RCC_CFGR2_PREDIV1_DIV9
#define RCC_HSE_PREDIV_DIV10             RCC_CFGR2_PREDIV1_DIV10
#define RCC_HSE_PREDIV_DIV11             RCC_CFGR2_PREDIV1_DIV11
#define RCC_HSE_PREDIV_DIV12             RCC_CFGR2_PREDIV1_DIV12
#define RCC_HSE_PREDIV_DIV13             RCC_CFGR2_PREDIV1_DIV13
#define RCC_HSE_PREDIV_DIV14             RCC_CFGR2_PREDIV1_DIV14
#define RCC_HSE_PREDIV_DIV15             RCC_CFGR2_PREDIV1_DIV15
#define RCC_HSE_PREDIV_DIV16             RCC_CFGR2_PREDIV1_DIV16
#else
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR_PLLXTPRE
#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Prediv2_Factor HSE Prediv2 Factor
  * @{
  */

#define RCC_HSE_PREDIV2_DIV1                RCC_CFGR2_PREDIV2_DIV1   /*!< PREDIV2 input clock not divided */
#define RCC_HSE_PREDIV2_DIV2                RCC_CFGR2_PREDIV2_DIV2   /*!< PREDIV2 input clock divided by 2 */
#define RCC_HSE_PREDIV2_DIV3                RCC_CFGR2_PREDIV2_DIV3   /*!< PREDIV2 input clock divided by 3 */
#define RCC_HSE_PREDIV2_DIV4                RCC_CFGR2_PREDIV2_DIV4   /*!< PREDIV2 input clock divided by 4 */
#define RCC_HSE_PREDIV2_DIV5                RCC_CFGR2_PREDIV2_DIV5   /*!< PREDIV2 input clock divided by 5 */
#define RCC_HSE_PREDIV2_DIV6                RCC_CFGR2_PREDIV2_DIV6   /*!< PREDIV2 input clock divided by 6 */
#define RCC_HSE_PREDIV2_DIV7                RCC_CFGR2_PREDIV2_DIV7   /*!< PREDIV2 input clock divided by 7 */
#define RCC_HSE_PREDIV2_DIV8                RCC_CFGR2_PREDIV2_DIV8   /*!< PREDIV2 input clock divided by 8 */
#define RCC_HSE_PREDIV2_DIV9                RCC_CFGR2_PREDIV2_DIV9   /*!< PREDIV2 input clock divided by 9 */
#define RCC_HSE_PREDIV2_DIV10               RCC_CFGR2_PREDIV2_DIV10  /*!< PREDIV2 input clock divided by 10 */
#define RCC_HSE_PREDIV2_DIV11               RCC_CFGR2_PREDIV2_DIV11  /*!< PREDIV2 input clock divided by 11 */
#define RCC_HSE_PREDIV2_DIV12               RCC_CFGR2_PREDIV2_DIV12  /*!< PREDIV2 input clock divided by 12 */
#define RCC_HSE_PREDIV2_DIV13               RCC_CFGR2_PREDIV2_DIV13  /*!< PREDIV2 input clock divided by 13 */
#define RCC_HSE_PREDIV2_DIV14               RCC_CFGR2_PREDIV2_DIV14  /*!< PREDIV2 input clock divided by 14 */
#define RCC_HSE_PREDIV2_DIV15               RCC_CFGR2_PREDIV2_DIV15  /*!< PREDIV2 input clock divided by 15 */
#define RCC_HSE_PREDIV2_DIV16               RCC_CFGR2_PREDIV2_DIV16  /*!< PREDIV2 input clock divided by 16 */

/**
  * @}
  */

/** @defgroup RCCEx_PLL2_Config PLL Config
  * @{
  */
#define RCC_PLL2_NONE                      0x00000000U
#define RCC_PLL2_OFF                       0x00000001U
#define RCC_PLL2_ON                        0x00000002U

/**
  * @}
  */

/** @defgroup RCCEx_PLL2_Multiplication_Factor PLL2 Multiplication Factor
  * @{
  */

#define RCC_PLL2_MUL8                   RCC_CFGR2_PLL2MUL8   /*!< PLL2 input clock * 8 */
#define RCC_PLL2_MUL9                   RCC_CFGR2_PLL2MUL9   /*!< PLL2 input clock * 9 */
#define RCC_PLL2_MUL10                  RCC_CFGR2_PLL2MUL10  /*!< PLL2 input clock * 10 */
#define RCC_PLL2_MUL11                  RCC_CFGR2_PLL2MUL11  /*!< PLL2 input clock * 11 */
#define RCC_PLL2_MUL12                  RCC_CFGR2_PLL2MUL12  /*!< PLL2 input clock * 12 */
#define RCC_PLL2_MUL13                  RCC_CFGR2_PLL2MUL13  /*!< PLL2 input clock * 13 */
#define RCC_PLL2_MUL14                  RCC_CFGR2_PLL2MUL14  /*!< PLL2 input clock * 14 */
#define RCC_PLL2_MUL16                  RCC_CFGR2_PLL2MUL16  /*!< PLL2 input clock * 16 */
#define RCC_PLL2_MUL20                  RCC_CFGR2_PLL2MUL20  /*!< PLL2 input clock * 20 */

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_PLL_Multiplication_Factor PLL Multiplication Factor
  * @{
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
#else
#define RCC_PLL_MUL2                    RCC_CFGR_PLLMULL2
#define RCC_PLL_MUL3                    RCC_CFGR_PLLMULL3
#endif /* STM32F105xC || STM32F107xC */
#define RCC_PLL_MUL4                    RCC_CFGR_PLLMULL4
#define RCC_PLL_MUL5                    RCC_CFGR_PLLMULL5
#define RCC_PLL_MUL6                    RCC_CFGR_PLLMULL6
#define RCC_PLL_MUL7                    RCC_CFGR_PLLMULL7
#define RCC_PLL_MUL8                    RCC_CFGR_PLLMULL8
#define RCC_PLL_MUL9                    RCC_CFGR_PLLMULL9
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_PLL_MUL6_5                  RCC_CFGR_PLLMULL6_5
#else
#define RCC_PLL_MUL10                   RCC_CFGR_PLLMULL10
#define RCC_PLL_MUL11                   RCC_CFGR_PLLMULL11
#define RCC_PLL_MUL12                   RCC_CFGR_PLLMULL12
#define RCC_PLL_MUL13                   RCC_CFGR_PLLMULL13
#define RCC_PLL_MUL14                   RCC_CFGR_PLLMULL14
#define RCC_PLL_MUL15                   RCC_CFGR_PLLMULL15
#define RCC_PLL_MUL16                   RCC_CFGR_PLLMULL16
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_MCO1_Clock_Source MCO1 Clock Source
  * @{
  */
#define RCC_MCO1SOURCE_NOCLOCK           ((uint32_t)RCC_CFGR_MCO_NOCLOCK)
#define RCC_MCO1SOURCE_SYSCLK            ((uint32_t)RCC_CFGR_MCO_SYSCLK)
#define RCC_MCO1SOURCE_HSI               ((uint32_t)RCC_CFGR_MCO_HSI)
#define RCC_MCO1SOURCE_HSE               ((uint32_t)RCC_CFGR_MCO_HSE)
#define RCC_MCO1SOURCE_PLLCLK            ((uint32_t)RCC_CFGR_MCO_PLLCLK_DIV2)
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_MCO1SOURCE_PLL2CLK           ((uint32_t)RCC_CFGR_MCO_PLL2CLK)
#define RCC_MCO1SOURCE_PLL3CLK_DIV2      ((uint32_t)RCC_CFGR_MCO_PLL3CLK_DIV2)
#define RCC_MCO1SOURCE_EXT_HSE           ((uint32_t)RCC_CFGR_MCO_EXT_HSE)
#define RCC_MCO1SOURCE_PLL3CLK           ((uint32_t)RCC_CFGR_MCO_PLL3CLK)
#endif /* STM32F105xC || STM32F107xC*/
/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Interrupt RCCEx Interrupt
  * @{
  */
#define RCC_IT_PLL2RDY                   ((uint8_t)RCC_CIR_PLL2RDYF)
#define RCC_IT_PLLI2SRDY                 ((uint8_t)RCC_CIR_PLL3RDYF)
/**
  * @}
  */

/** @defgroup RCCEx_Flag RCCEx Flag
  *        Elements values convention: 0XXYYYYYb
  *           - YYYYY  : Flag position in the register
  *           - XX  : Register index
  *                 - 01: CR register
  * @{
  */
/* Flags in the CR register */
#define RCC_FLAG_PLL2RDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL2RDY_Pos))
#define RCC_FLAG_PLLI2SRDY                ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL3RDY_Pos))
/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC*/

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCCEx_Exported_Macros RCCEx Exported Macros
 * @{
 */

/** @defgroup RCCEx_Peripheral_Clock_Enable_Disable Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined  (STM32F107xC)\
 || defined  (STM32F100xE)
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_DMA2_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_DMA2EN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F105xC || STM32F107xC || STM32F100xE */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
#define __HAL_RCC_FSMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_FSMC_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_FSMCEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F100xE */

#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_SDIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)


#define __HAL_RCC_SDIO_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_SDIOEN))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)


#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()       (RCC->AHBENR &= ~(RCC_AHBENR_OTGFSEN))
#endif /* STM32F105xC || STM32F107xC*/

#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ETHMACTX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ETHMACRX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ETHMAC_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACEN))
#define __HAL_RCC_ETHMACTX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACTXEN))
#define __HAL_RCC_ETHMACRX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACRXEN))

/**
  * @brief  Enable ETHERNET clock.
  */
#define __HAL_RCC_ETH_CLK_ENABLE() do {                                     \
                                        __HAL_RCC_ETHMAC_CLK_ENABLE();      \
                                        __HAL_RCC_ETHMACTX_CLK_ENABLE();    \
                                        __HAL_RCC_ETHMACRX_CLK_ENABLE();    \
                                      } while(0U)
/**
  * @brief  Disable ETHERNET clock.
  */
#define __HAL_RCC_ETH_CLK_DISABLE()  do {                                      \
                                          __HAL_RCC_ETHMACTX_CLK_DISABLE();    \
                                          __HAL_RCC_ETHMACRX_CLK_DISABLE();    \
                                          __HAL_RCC_ETHMAC_CLK_DISABLE();      \
                                        } while(0U)

#endif /* STM32F107xC*/

/**
  * @}
  */

/** @defgroup RCCEx_AHB1_Peripheral_Clock_Enable_Disable_Status AHB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined  (STM32F107xC)\
 || defined  (STM32F100xE)
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) != RESET)
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F105xC || STM32F107xC || STM32F100xE */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
#define __HAL_RCC_FSMC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) != RESET)
#define __HAL_RCC_FSMC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F100xE */
#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_SDIO_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) != RESET)
#define __HAL_RCC_SDIO_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) == RESET)
#endif /* STM32F103xE || STM32F103xG */
#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) != RESET)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) == RESET)
#endif /* STM32F105xC || STM32F107xC*/
#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) != RESET)
#define __HAL_RCC_ETHMAC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) == RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) != RESET)
#define __HAL_RCC_ETHMACTX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) == RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) != RESET)
#define __HAL_RCC_ETHMACRX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) == RESET)
#endif /* STM32F107xC*/

/**
  * @}
  */

/** @defgroup RCCEx_APB1_Clock_Enable_Disable APB1 Clock Enable Disable
  * @brief  Enable or disable the Low Speed APB (APB1) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_CAN1_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN1EN))
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM4_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
#define __HAL_RCC_SPI2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
#define __HAL_RCC_USART3_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN))
#define __HAL_RCC_I2C2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
