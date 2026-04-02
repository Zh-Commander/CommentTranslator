/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_Prediv1_Factor HSE Prediv1 Factor
  * @{
  */

// HSE预分频1的分频因子定义
#define RCC_HSE_PREDIV_DIV1              0x00000000U        // HSE不分频

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
// 适用于互联型和超大容量产品的预分频配置
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR2_PREDIV1_DIV2   // HSE 2分频
#define RCC_HSE_PREDIV_DIV3              RCC_CFGR2_PREDIV1_DIV3   // HSE 3分频
#define RCC_HSE_PREDIV_DIV4              RCC_CFGR2_PREDIV1_DIV4   // HSE 4分频
#define RCC_HSE_PREDIV_DIV5              RCC_CFGR2_PREDIV1_DIV5   // HSE 5分频
#define RCC_HSE_PREDIV_DIV6              RCC_CFGR2_PREDIV1_DIV6   // HSE 6分频
#define RCC_HSE_PREDIV_DIV7              RCC_CFGR2_PREDIV1_DIV7   // HSE 7分频
#define RCC_HSE_PREDIV_DIV8              RCC_CFGR2_PREDIV1_DIV8   // HSE 8分频
#define RCC_HSE_PREDIV_DIV9              RCC_CFGR2_PREDIV1_DIV9   // HSE 9分频
#define RCC_HSE_PREDIV_DIV10             RCC_CFGR2_PREDIV1_DIV10  // HSE 10分频
#define RCC_HSE_PREDIV_DIV11             RCC_CFGR2_PREDIV1_DIV11  // HSE 11分频
#define RCC_HSE_PREDIV_DIV12             RCC_CFGR2_PREDIV1_DIV12  // HSE 12分频
#define RCC_HSE_PREDIV_DIV13             RCC_CFGR2_PREDIV1_DIV13  // HSE 13分频
#define RCC_HSE_PREDIV_DIV14             RCC_CFGR2_PREDIV1_DIV14  // HSE 14分频
#define RCC_HSE_PREDIV_DIV15             RCC_CFGR2_PREDIV1_DIV15  // HSE 15分频
#define RCC_HSE_PREDIV_DIV16             RCC_CFGR2_PREDIV1_DIV16  // HSE 16分频
#else
// 适用于其他系列（如F103）的预分频配置，仅支持1分频和2分频
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR_PLLXTPRE        // HSE 2分频作为PLL输入
#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Prediv2_Factor HSE Prediv2 Factor
  * @{
  */

// HSE预分频2的分频因子定义（仅限互联型设备）
#define RCC_HSE_PREDIV2_DIV1                RCC_CFGR2_PREDIV2_DIV1   /*!< PREDIV2输入时钟不分频 */
#define RCC_HSE_PREDIV2_DIV2                RCC_CFGR2_PREDIV2_DIV2   /*!< PREDIV2输入时钟2分频 */
#define RCC_HSE_PREDIV2_DIV3                RCC_CFGR2_PREDIV2_DIV3   /*!< PREDIV2输入时钟3分频 */
#define RCC_HSE_PREDIV2_DIV4                RCC_CFGR2_PREDIV2_DIV4   /*!< PREDIV2输入时钟4分频 */
#define RCC_HSE_PREDIV2_DIV5                RCC_CFGR2_PREDIV2_DIV5   /*!< PREDIV2输入时钟5分频 */
#define RCC_HSE_PREDIV2_DIV6                RCC_CFGR2_PREDIV2_DIV6   /*!< PREDIV2输入时钟6分频 */
#define RCC_HSE_PREDIV2_DIV7                RCC_CFGR2_PREDIV2_DIV7   /*!< PREDIV2输入时钟7分频 */
#define RCC_HSE_PREDIV2_DIV8                RCC_CFGR2_PREDIV2_DIV8   /*!< PREDIV2输入时钟8分频 */
#define RCC_HSE_PREDIV2_DIV9                RCC_CFGR2_PREDIV2_DIV9   /*!< PREDIV2输入时钟9分频 */
#define RCC_HSE_PREDIV2_DIV10               RCC_CFGR2_PREDIV2_DIV10  /*!< PREDIV2输入时钟10分频 */
#define RCC_HSE_PREDIV2_DIV11               RCC_CFGR2_PREDIV2_DIV11  /*!< PREDIV2输入时钟11分频 */
#define RCC_HSE_PREDIV2_DIV12               RCC_CFGR2_PREDIV2_DIV12  /*!< PREDIV2输入时钟12分频 */
#define RCC_HSE_PREDIV2_DIV13               RCC_CFGR2_PREDIV2_DIV13  /*!< PREDIV2输入时钟13分频 */
#define RCC_HSE_PREDIV2_DIV14               RCC_CFGR2_PREDIV2_DIV14  /*!< PREDIV2输入时钟14分频 */
#define RCC_HSE_PREDIV2_DIV15               RCC_CFGR2_PREDIV2_DIV15  /*!< PREDIV2输入时钟15分频 */
#define RCC_HSE_PREDIV2_DIV16               RCC_CFGR2_PREDIV2_DIV16  /*!< PREDIV2输入时钟16分频 */

/**
  * @}
  */

/** @defgroup RCCEx_PLL2_Config PLL Config
  * @{
  */
// PLL2配置状态定义
#define RCC_PLL2_NONE                      0x00000000U       // PLL2未配置
#define RCC_PLL2_OFF                       0x00000001U       // PLL2关闭
#define RCC_PLL2_ON                        0x00000002U       // PLL2开启

/**
  * @}
  */

/** @defgroup RCCEx_PLL2_Multiplication_Factor PLL2 Multiplication Factor
  * @{
  */

// PLL2倍频因子定义
#define RCC_PLL2_MUL8                   RCC_CFGR2_PLL2MUL8   /*!< PLL2输入时钟 x 8 */
#define RCC_PLL2_MUL9                   RCC_CFGR2_PLL2MUL9   /*!< PLL2输入时钟 x 9 */
#define RCC_PLL2_MUL10                  RCC_CFGR2_PLL2MUL10  /*!< PLL2输入时钟 x 10 */
#define RCC_PLL2_MUL11                  RCC_CFGR2_PLL2MUL11  /*!< PLL2输入时钟 x 11 */
#define RCC_PLL2_MUL12                  RCC_CFGR2_PLL2MUL12  /*!< PLL2输入时钟 x 12 */
#define RCC_PLL2_MUL13                  RCC_CFGR2_PLL2MUL13  /*!< PLL2输入时钟 x 13 */
#define RCC_PLL2_MUL14                  RCC_CFGR2_PLL2MUL14  /*!< PLL2输入时钟 x 14 */
#define RCC_PLL2_MUL16                  RCC_CFGR2_PLL2MUL16  /*!< PLL2输入时钟 x 16 */
#define RCC_PLL2_MUL20                  RCC_CFGR2_PLL2MUL20  /*!< PLL2输入时钟 x 20 */

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_PLL_Multiplication_Factor PLL Multiplication Factor
  * @{
  */

// PLL倍频因子定义
#if defined(STM32F105xC) || defined(STM32F107xC)
// 互联型设备不包含MUL2和MUL3
#else
// 非互联型设备支持MUL2和MUL3
#define RCC_PLL_MUL2                    RCC_CFGR_PLLMULL2    // PLL 2倍频
#define RCC_PLL_MUL3                    RCC_CFGR_PLLMULL3    // PLL 3倍频
#endif /* STM32F105xC || STM32F107xC */
#define RCC_PLL_MUL4                    RCC_CFGR_PLLMULL4    // PLL 4倍频
#define RCC_PLL_MUL5                    RCC_CFGR_PLLMULL5    // PLL 5倍频
#define RCC_PLL_MUL6                    RCC_CFGR_PLLMULL6    // PLL 6倍频
#define RCC_PLL_MUL7                    RCC_CFGR_PLLMULL7    // PLL 7倍频
#define RCC_PLL_MUL8                    RCC_CFGR_PLLMULL8    // PLL 8倍频
#define RCC_PLL_MUL9                    RCC_CFGR_PLLMULL9    // PLL 9倍频
#if defined(STM32F105xC) || defined(STM32F107xC)
// 互联型设备特有的6.5倍频
#define RCC_PLL_MUL6_5                  RCC_CFGR_PLLMULL6_5  // PLL 6.5倍频
#else
// 非互联型设备支持10到16倍频
#define RCC_PLL_MUL10                   RCC_CFGR_PLLMULL10   // PLL 10倍频
#define RCC_PLL_MUL11                   RCC_CFGR_PLLMULL11   // PLL 11倍频
#define RCC_PLL_MUL12                   RCC_CFGR_PLLMULL12   // PLL 12倍频
#define RCC_PLL_MUL13                   RCC_CFGR_PLLMULL13   // PLL 13倍频
#define RCC_PLL_MUL14                   RCC_CFGR_PLLMULL14   // PLL 14倍频
#define RCC_PLL_MUL15                   RCC_CFGR_PLLMULL15   // PLL 15倍频
#define RCC_PLL_MUL16                   RCC_CFGR_PLLMULL16   // PLL 16倍频
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_MCO1_Clock_Source MCO1 Clock Source
  * @{
  */
// MCO1时钟输出源配置
#define RCC_MCO1SOURCE_NOCLOCK           ((uint32_t)RCC_CFGR_MCO_NOCLOCK)      // 无时钟输出
#define RCC_MCO1SOURCE_SYSCLK            ((uint32_t)RCC_CFGR_MCO_SYSCLK)       // 系统时钟(SYSCLK)输出
#define RCC_MCO1SOURCE_HSI               ((uint32_t)RCC_CFGR_MCO_HSI)          // 内部高速时钟(HSI)输出
#define RCC_MCO1SOURCE_HSE               ((uint32_t)RCC_CFGR_MCO_HSE)          // 外部高速时钟(HSE)输出
#define RCC_MCO1SOURCE_PLLCLK            ((uint32_t)RCC_CFGR_MCO_PLLCLK_DIV2)  // PLL时钟2分频后输出
#if defined(STM32F105xC) || defined(STM32F107xC)
// 互联型设备特有的时钟输出源
#define RCC_MCO1SOURCE_PLL2CLK           ((uint32_t)RCC_CFGR_MCO_PLL2CLK)      // PLL2时钟输出
#define RCC_MCO1SOURCE_PLL3CLK_DIV2      ((uint32_t)RCC_CFGR_MCO_PLL3CLK_DIV2) // PLL3时钟2分频后输出
#define RCC_MCO1SOURCE_EXT_HSE           ((uint32_t)RCC_CFGR_MCO_EXT_HSE)      // 外部HSE输出
#define RCC_MCO1SOURCE_PLL3CLK           ((uint32_t)RCC_CFGR_MCO_PLL3CLK)      // PLL3时钟输出
#endif /* STM32F105xC || STM32F107xC*/
/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Interrupt RCCEx Interrupt
  * @{
  */
// RCC扩展中断定义
#define RCC_IT_PLL2RDY                   ((uint8_t)RCC_CIR_PLL2RDYF)   // PLL2就绪中断标志
#define RCC_IT_PLLI2SRDY                 ((uint8_t)RCC_CIR_PLL3RDYF)   // PLL3(PLLI2S)就绪中断标志
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
// CR寄存器中的标志位定义
#define RCC_FLAG_PLL2RDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL2RDY_Pos))   // PLL2就绪标志
#define RCC_FLAG_PLLI2SRDY                ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL3RDY_Pos))   // PLL3(PLLI2S)就绪标志
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
/**
  * @brief  使能DMA2时钟
  * @note   这是一个宏定义，通过操作AHBENR寄存器来开启时钟
  */
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  关闭DMA2时钟
  */
#define __HAL_RCC_DMA2_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_DMA2EN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F105xC || STM32F107xC || STM32F100xE */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
/**
  * @brief  使能FSMC时钟（可变静态存储控制器）
  */
#define __HAL_RCC_FSMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  关闭FSMC时钟
  */
#define __HAL_RCC_FSMC_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_FSMCEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F100xE */

#if defined(STM32F103xE) || defined(STM32F103xG)
/**
  * @brief  使能SDIO时钟
  */
#define __HAL_RCC_SDIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)


/**
  * @brief  关闭SDIO时钟
  */
#define __HAL_RCC_SDIO_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_SDIOEN))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  使能USB OTG FS时钟
  */
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)


/**
  * @brief  关闭USB OTG FS时钟
  */
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()       (RCC->AHBENR &= ~(RCC_AHBENR_OTGFSEN))
#endif /* STM32F105xC || STM32F107xC*/

#if defined(STM32F107xC)
/**
  * @brief  使能以太网MAC时钟
  */
#define __HAL_RCC_ETHMAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能以太网MAC发送时钟
  */
#define __HAL_RCC_ETHMACTX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能以太网MAC接收时钟
  */
#define __HAL_RCC_ETHMACRX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  关闭以太网MAC时钟
  */
#define __HAL_RCC_ETHMAC_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACEN))
/**
  * @brief  关闭以太网MAC发送时钟
  */
#define __HAL_RCC_ETHMACTX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACTXEN))
/**
  * @brief  关闭以太网MAC接收时钟
  */
#define __HAL_RCC_ETHMACRX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACRXEN))

/**
  * @brief  Enable ETHERNET clock.
  *         使能以太网时钟（包含MAC、发送、接收）
  */
#define __HAL_RCC_ETH_CLK_ENABLE() do {                                     \
                                        __HAL_RCC_ETHMAC_CLK_ENABLE();      \
                                        __HAL_RCC_ETHMACTX_CLK_ENABLE();    \
                                        __HAL_RCC_ETHMACRX_CLK_ENABLE();    \
                                      } while(0U)
/**
  * @brief  Disable ETHERNET clock.
  *         关闭以太网时钟（包含发送、接收、MAC）
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
// 检查DMA2时钟是否已使能
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) != RESET)
// 检查DMA2时钟是否已关闭
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F105xC || STM32F107xC || STM32F100xE */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
// 检查FSMC时钟是否已使能
#define __HAL_RCC_FSMC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) != RESET)
// 检查FSMC时钟是否已关闭
#define __HAL_RCC_FSMC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F100xE */
#if defined(STM32F103xE) || defined(STM32F103xG)
// 检查SDIO时钟是否已使能
#define __HAL_RCC_SDIO_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) != RESET)
// 检查SDIO时钟是否已关闭
#define __HAL_RCC_SDIO_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) == RESET)
#endif /* STM32F103xE || STM32F103xG */
#if defined(STM32F105xC) || defined(STM32F107xC)
// 检查USB OTG FS时钟是否已使能
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) != RESET)
// 检查USB OTG FS时钟是否已关闭
#define __HAL_RCC_USB_OTG_FS_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) == RESET)
#endif /* STM32F105xC || STM32F107xC*/
#if defined(STM32F107xC)
// 检查以太网MAC时钟是否已使能
#define __HAL_RCC_ETHMAC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) != RESET)
// 检查以太网MAC时钟是否已关闭
#define __HAL_RCC_ETHMAC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) == RESET)
// 检查以太网MAC发送时钟是否已使能
#define __HAL_RCC_ETHMACTX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) != RESET)
// 检查以太网MAC发送时钟是否已关闭
#define __HAL_RCC_ETHMACTX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) == RESET)
// 检查以太网MAC接收时钟是否已使能
#define __HAL_RCC_ETHMACRX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) != RESET)
// 检查以太网MAC接收时钟是否已关闭
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
/**
  * @brief  使能CAN1时钟
  */
#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  关闭CAN1时钟
  */
#define __HAL_RCC_CAN1_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN1EN))
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  使能TIM4时钟
  */
#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能SPI2时钟
  */
#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能USART3时钟
  */
#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能I2C2时钟
  */
#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        /* Delay after an RCC peripheral clock enabling */ \
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  关闭TIM4时钟
  */
#define __HAL_RCC_TIM4_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
/**
  * @brief  关闭SPI2时钟
  */
#define __HAL_RCC_SPI2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
/**
  * @brief  关闭USART3时钟
  */
#define __HAL_RCC_USART3_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN))
/**
  * @brief  关闭I2C2时钟
  */
#define __HAL_RCC_I2C2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
