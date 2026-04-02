/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_Prediv1_Factor HSE Prediv1 Factor
  * @brief  HSE 预分频器1 (PREDIV1) 配置因子
  * @{
  */

/* HSE 不分频，直接作为PREDIV1输出 */
#define RCC_HSE_PREDIV_DIV1              0x00000000U

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/* 以下定义适用于互联型设备(F105/F107)或高密度值线设备(F100) */
/* HSE 2分频 */
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR2_PREDIV1_DIV2
/* HSE 3分频 */
#define RCC_HSE_PREDIV_DIV3              RCC_CFGR2_PREDIV1_DIV3
/* HSE 4分频 */
#define RCC_HSE_PREDIV_DIV4              RCC_CFGR2_PREDIV1_DIV4
/* HSE 5分频 */
#define RCC_HSE_PREDIV_DIV5              RCC_CFGR2_PREDIV1_DIV5
/* HSE 6分频 */
#define RCC_HSE_PREDIV_DIV6              RCC_CFGR2_PREDIV1_DIV6
/* HSE 7分频 */
#define RCC_HSE_PREDIV_DIV7              RCC_CFGR2_PREDIV1_DIV7
/* HSE 8分频 */
#define RCC_HSE_PREDIV_DIV8              RCC_CFGR2_PREDIV1_DIV8
/* HSE 9分频 */
#define RCC_HSE_PREDIV_DIV9              RCC_CFGR2_PREDIV1_DIV9
/* HSE 10分频 */
#define RCC_HSE_PREDIV_DIV10             RCC_CFGR2_PREDIV1_DIV10
/* HSE 11分频 */
#define RCC_HSE_PREDIV_DIV11             RCC_CFGR2_PREDIV1_DIV11
/* HSE 12分频 */
#define RCC_HSE_PREDIV_DIV12             RCC_CFGR2_PREDIV1_DIV12
/* HSE 13分频 */
#define RCC_HSE_PREDIV_DIV13             RCC_CFGR2_PREDIV1_DIV13
/* HSE 14分频 */
#define RCC_HSE_PREDIV_DIV14             RCC_CFGR2_PREDIV1_DIV14
/* HSE 15分频 */
#define RCC_HSE_PREDIV_DIV15             RCC_CFGR2_PREDIV1_DIV15
/* HSE 16分频 */
#define RCC_HSE_PREDIV_DIV16             RCC_CFGR2_PREDIV1_DIV16
#else
/* 适用于非互联型设备，仅支持1分频或2分频 */
/* HSE 2分频 (通过配置PLLXTPRE位实现) */
#define RCC_HSE_PREDIV_DIV2              RCC_CFGR_PLLXTPRE
#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Prediv2_Factor HSE Prediv2 Factor
  * @brief  HSE 预分频器2 (PREDIV2) 配置因子 (仅互联型设备)
  * @{
  */

/* PREDIV2 输入时钟不分频 */
#define RCC_HSE_PREDIV2_DIV1                RCC_CFGR2_PREDIV2_DIV1   /*!< PREDIV2 input clock not divided */
/* PREDIV2 输入时钟 2分频 */
#define RCC_HSE_PREDIV2_DIV2                RCC_CFGR2_PREDIV2_DIV2   /*!< PREDIV2 input clock divided by 2 */
/* PREDIV2 输入时钟 3分频 */
#define RCC_HSE_PREDIV2_DIV3                RCC_CFGR2_PREDIV2_DIV3   /*!< PREDIV2 input clock divided by 3 */
/* PREDIV2 输入时钟 4分频 */
#define RCC_HSE_PREDIV2_DIV4                RCC_CFGR2_PREDIV2_DIV4   /*!< PREDIV2 input clock divided by 4 */
/* PREDIV2 输入时钟 5分频 */
#define RCC_HSE_PREDIV2_DIV5                RCC_CFGR2_PREDIV2_DIV5   /*!< PREDIV2 input clock divided by 5 */
/* PREDIV2 输入时钟 6分频 */
#define RCC_HSE_PREDIV2_DIV6                RCC_CFGR2_PREDIV2_DIV6   /*!< PREDIV2 input clock divided by 6 */
/* PREDIV2 输入时钟 7分频 */
#define RCC_HSE_PREDIV2_DIV7                RCC_CFGR2_PREDIV2_DIV7   /*!< PREDIV2 input clock divided by 7 */
/* PREDIV2 输入时钟 8分频 */
#define RCC_HSE_PREDIV2_DIV8                RCC_CFGR2_PREDIV2_DIV8   /*!< PREDIV2 input clock divided by 8 */
/* PREDIV2 输入时钟 9分频 */
#define RCC_HSE_PREDIV2_DIV9                RCC_CFGR2_PREDIV2_DIV9   /*!< PREDIV2 input clock divided by 9 */
/* PREDIV2 输入时钟 10分频 */
#define RCC_HSE_PREDIV2_DIV10               RCC_CFGR2_PREDIV2_DIV10  /*!< PREDIV2 input clock divided by 10 */
/* PREDIV2 输入时钟 11分频 */
#define RCC_HSE_PREDIV2_DIV11               RCC_CFGR2_PREDIV2_DIV11  /*!< PREDIV2 input clock divided by 11 */
/* PREDIV2 输入时钟 12分频 */
#define RCC_HSE_PREDIV2_DIV12               RCC_CFGR2_PREDIV2_DIV12  /*!< PREDIV2 input clock divided by 12 */
/* PREDIV2 输入时钟 13分频 */
#define RCC_HSE_PREDIV2_DIV13               RCC_CFGR2_PREDIV2_DIV13  /*!< PREDIV2 input clock divided by 13 */
/* PREDIV2 输入时钟 14分频 */
#define RCC_HSE_PREDIV2_DIV14               RCC_CFGR2_PREDIV2_DIV14  /*!< PREDIV2 input clock divided by 14 */
/* PREDIV2 输入时钟 15分频 */
#define RCC_HSE_PREDIV2_DIV15               RCC_CFGR2_PREDIV2_DIV15  /*!< PREDIV2 input clock divided by 15 */
/* PREDIV2 输入时钟 16分频 */
#define RCC_HSE_PREDIV2_DIV16               RCC_CFGR2_PREDIV2_DIV16  /*!< PREDIV2 input clock divided by 16 */

/**
  * @}
  */

/** @defgroup RCCEx_PLL2_Config PLL Config
  * @brief  PLL2 配置参数
  * @{
  */
/* PLL2 未配置 */
#define RCC_PLL2_NONE                      0x00000000U
/* PLL2 关闭 */
#define RCC_PLL2_OFF                       0x00000001U
/* PLL2 开启 */
#define RCC_PLL2_ON                        0x00000002U

/**
  * @}
  */

/** @defgroup RCCEx_PLL2_Multiplication_Factor PLL2 Multiplication Factor
  * @brief  PLL2 倍频因子配置 (仅互联型设备)
  * @{
  */

/* PLL2 输入时钟 8倍频 */
#define RCC_PLL2_MUL8                   RCC_CFGR2_PLL2MUL8   /*!< PLL2 input clock * 8 */
/* PLL2 输入时钟 9倍频 */
#define RCC_PLL2_MUL9                   RCC_CFGR2_PLL2MUL9   /*!< PLL2 input clock * 9 */
/* PLL2 输入时钟 10倍频 */
#define RCC_PLL2_MUL10                  RCC_CFGR2_PLL2MUL10  /*!< PLL2 input clock * 10 */
/* PLL2 输入时钟 11倍频 */
#define RCC_PLL2_MUL11                  RCC_CFGR2_PLL2MUL11  /*!< PLL2 input clock * 11 */
/* PLL2 输入时钟 12倍频 */
#define RCC_PLL2_MUL12                  RCC_CFGR2_PLL2MUL12  /*!< PLL2 input clock * 12 */
/* PLL2 输入时钟 13倍频 */
#define RCC_PLL2_MUL13                  RCC_CFGR2_PLL2MUL13  /*!< PLL2 input clock * 13 */
/* PLL2 输入时钟 14倍频 */
#define RCC_PLL2_MUL14                  RCC_CFGR2_PLL2MUL14  /*!< PLL2 input clock * 14 */
/* PLL2 输入时钟 16倍频 */
#define RCC_PLL2_MUL16                  RCC_CFGR2_PLL2MUL16  /*!< PLL2 input clock * 16 */
/* PLL2 输入时钟 20倍频 */
#define RCC_PLL2_MUL20                  RCC_CFGR2_PLL2MUL20  /*!< PLL2 input clock * 20 */

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_PLL_Multiplication_Factor PLL Multiplication Factor
  * @brief  PLL 倍频因子配置
  * @{
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/* 互联型设备此处为空，因其倍频系数范围不同，具体定义在下方 */
#else
/* 非互联型设备 PLL 倍频系数 */
/* PLL 输入时钟 2倍频 */
#define RCC_PLL_MUL2                    RCC_CFGR_PLLMULL2
/* PLL 输入时钟 3倍频 */
#define RCC_PLL_MUL3                    RCC_CFGR_PLLMULL3
#endif /* STM32F105xC || STM32F107xC */
/* PLL 输入时钟 4倍频 */
#define RCC_PLL_MUL4                    RCC_CFGR_PLLMULL4
/* PLL 输入时钟 5倍频 */
#define RCC_PLL_MUL5                    RCC_CFGR_PLLMULL5
/* PLL 输入时钟 6倍频 */
#define RCC_PLL_MUL6                    RCC_CFGR_PLLMULL6
/* PLL 输入时钟 7倍频 */
#define RCC_PLL_MUL7                    RCC_CFGR_PLLMULL7
/* PLL 输入时钟 8倍频 */
#define RCC_PLL_MUL8                    RCC_CFGR_PLLMULL8
/* PLL 输入时钟 9倍频 */
#define RCC_PLL_MUL9                    RCC_CFGR_PLLMULL9
#if defined(STM32F105xC) || defined(STM32F107xC)
/* 互联型设备特有：PLL 输入时钟 6.5倍频 */
#define RCC_PLL_MUL6_5                  RCC_CFGR_PLLMULL6_5
#else
/* 非互联型设备特有倍频系数 */
/* PLL 输入时钟 10倍频 */
#define RCC_PLL_MUL10                   RCC_CFGR_PLLMULL10
/* PLL 输入时钟 11倍频 */
#define RCC_PLL_MUL11                   RCC_CFGR_PLLMULL11
/* PLL 输入时钟 12倍频 */
#define RCC_PLL_MUL12                   RCC_CFGR_PLLMULL12
/* PLL 输入时钟 13倍频 */
#define RCC_PLL_MUL13                   RCC_CFGR_PLLMULL13
/* PLL 输入时钟 14倍频 */
#define RCC_PLL_MUL14                   RCC_CFGR_PLLMULL14
/* PLL 输入时钟 15倍频 */
#define RCC_PLL_MUL15                   RCC_CFGR_PLLMULL15
/* PLL 输入时钟 16倍频 */
#define RCC_PLL_MUL16                   RCC_CFGR_PLLMULL16
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_MCO1_Clock_Source MCO1 Clock Source
  * @brief  微控制器时钟输出 (MCO1) 配置
  * @{
  */
/* 无时钟输出 */
#define RCC_MCO1SOURCE_NOCLOCK           ((uint32_t)RCC_CFGR_MCO_NOCLOCK)
/* 系统时钟 (SYSCLK) 输出 */
#define RCC_MCO1SOURCE_SYSCLK            ((uint32_t)RCC_CFGR_MCO_SYSCLK)
/* 内部高速时钟 (HSI) 输出 */
#define RCC_MCO1SOURCE_HSI               ((uint32_t)RCC_CFGR_MCO_HSI)
/* 外部高速时钟 (HSE) 输出 */
#define RCC_MCO1SOURCE_HSE               ((uint32_t)RCC_CFGR_MCO_HSE)
/* PLL 时钟 2分频后输出 */
#define RCC_MCO1SOURCE_PLLCLK            ((uint32_t)RCC_CFGR_MCO_PLLCLK_DIV2)
#if defined(STM32F105xC) || defined(STM32F107xC)
/* 互联型设备特有：PLL2 时钟输出 */
#define RCC_MCO1SOURCE_PLL2CLK           ((uint32_t)RCC_CFGR_MCO_PLL2CLK)
/* 互联型设备特有：PLL3 时钟 2分频后输出 */
#define RCC_MCO1SOURCE_PLL3CLK_DIV2      ((uint32_t)RCC_CFGR_MCO_PLL3CLK_DIV2)
/* 互联型设备特有：外部 HSE 时钟输出 */
#define RCC_MCO1SOURCE_EXT_HSE           ((uint32_t)RCC_CFGR_MCO_EXT_HSE)
/* 互联型设备特有：PLL3 时钟输出 */
#define RCC_MCO1SOURCE_PLL3CLK           ((uint32_t)RCC_CFGR_MCO_PLL3CLK)
#endif /* STM32F105xC || STM32F107xC*/
/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Interrupt RCCEx Interrupt
  * @brief  RCC 扩展中断定义 (仅互联型设备)
  * @{
  */
/* PLL2 就绪中断标志 */
#define RCC_IT_PLL2RDY                   ((uint8_t)RCC_CIR_PLL2RDYF)
/* PLL3 (PLLI2S) 就绪中断标志 */
#define RCC_IT_PLLI2SRDY                 ((uint8_t)RCC_CIR_PLL3RDYF)
/**
  * @}
  */

/** @defgroup RCCEx_Flag RCCEx Flag
  * @brief  RCC 扩展状态标志定义
  *         元素值约定: 0XXYYYYYb
  *           - YYYYY  : 标志在寄存器中的位置
  *           - XX     : 寄存器索引
  *                 - 01: CR 寄存器
  * @{
  */
/* CR 寄存器中的标志位 */
/* PLL2 就绪标志 */
#define RCC_FLAG_PLL2RDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL2RDY_Pos))
/* PLL3 (PLLI2S) 就绪标志 */
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
 * @brief  RCC 扩展导出宏
 * @{
 */

/** @defgroup RCCEx_Peripheral_Clock_Enable_Disable Peripheral Clock Enable Disable
  * @brief  使能或禁用 AHB1 外设时钟。
  * @note   复位后，外设时钟（用于寄存器读写访问）是禁用的，
  *         应用程序在使用前必须使能该时钟。
  * @{
  */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined  (STM32F107xC)\
 || defined  (STM32F100xE)
/**
  * @brief  使能 DMA2 时钟。
  * @note   执行流程：设置使能位 -> 读取使能位(延时作用) -> 防止编译器优化
  */
#define __HAL_RCC_DMA2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        /* RCC 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  禁用 DMA2 时钟。
  */
#define __HAL_RCC_DMA2_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_DMA2EN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F105xC || STM32F107xC || STM32F100xE */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
/**
  * @brief  使能 FSMC (可变静态存储控制器) 时钟。
  */
#define __HAL_RCC_FSMC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FSMCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  禁用 FSMC 时钟。
  */
#define __HAL_RCC_FSMC_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_FSMCEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F100xE */

#if defined(STM32F103xE) || defined(STM32F103xG)
/**
  * @brief  使能 SDIO 时钟。
  */
#define __HAL_RCC_SDIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SDIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)


/**
  * @brief  禁用 SDIO 时钟。
  */
#define __HAL_RCC_SDIO_CLK_DISABLE()        (RCC->AHBENR &= ~(RCC_AHBENR_SDIOEN))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  使能 USB OTG FS (全速) 时钟。
  */
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_OTGFSEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)


/**
  * @brief  禁用 USB OTG FS 时钟。
  */
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()       (RCC->AHBENR &= ~(RCC_AHBENR_OTGFSEN))
#endif /* STM32F105xC || STM32F107xC*/

#if defined(STM32F107xC)
/**
  * @brief  使能以太网 MAC 时钟。
  */
#define __HAL_RCC_ETHMAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能以太网 MAC 发送时钟。
  */
#define __HAL_RCC_ETHMACTX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACTXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能以太网 MAC 接收时钟。
  */
#define __HAL_RCC_ETHMACRX_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_ETHMACRXEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  禁用以太网 MAC 时钟。
  */
#define __HAL_RCC_ETHMAC_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACEN))
/**
  * @brief  禁用以太网 MAC 发送时钟。
  */
#define __HAL_RCC_ETHMACTX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACTXEN))
/**
  * @brief  禁用以太网 MAC 接收时钟。
  */
#define __HAL_RCC_ETHMACRX_CLK_DISABLE()    (RCC->AHBENR &= ~(RCC_AHBENR_ETHMACRXEN))

/**
  * @brief  使能以太网时钟 (MAC + TX + RX)。
  */
#define __HAL_RCC_ETH_CLK_ENABLE() do {                                     \
                                        __HAL_RCC_ETHMAC_CLK_ENABLE();      \
                                        __HAL_RCC_ETHMACTX_CLK_ENABLE();    \
                                        __HAL_RCC_ETHMACRX_CLK_ENABLE();    \
                                      } while(0U)
/**
  * @brief  禁用以太网时钟 (TX + RX + MAC)。
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
  * @brief  获取 AHB1 外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟是禁用的，应用程序在使用前必须使能该时钟。
  * @{
  */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined  (STM32F107xC)\
 || defined  (STM32F100xE)
/* 检查 DMA2 时钟是否已使能 */
#define __HAL_RCC_DMA2_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) != RESET)
/* 检查 DMA2 时钟是否已禁用 */
#define __HAL_RCC_DMA2_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_DMA2EN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F105xC || STM32F107xC || STM32F100xE */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined  (STM32F100xE)
/* 检查 FSMC 时钟是否已使能 */
#define __HAL_RCC_FSMC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) != RESET)
/* 检查 FSMC 时钟是否已禁用 */
#define __HAL_RCC_FSMC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_FSMCEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG || STM32F100xE */
#if defined(STM32F103xE) || defined(STM32F103xG)
/* 检查 SDIO 时钟是否已使能 */
#define __HAL_RCC_SDIO_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) != RESET)
/* 检查 SDIO 时钟是否已禁用 */
#define __HAL_RCC_SDIO_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_SDIOEN)) == RESET)
#endif /* STM32F103xE || STM32F103xG */
#if defined(STM32F105xC) || defined(STM32F107xC)
/* 检查 USB OTG FS 时钟是否已使能 */
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) != RESET)
/* 检查 USB OTG FS 时钟是否已禁用 */
#define __HAL_RCC_USB_OTG_FS_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_OTGFSEN)) == RESET)
#endif /* STM32F105xC || STM32F107xC*/
#if defined(STM32F107xC)
/* 检查以太网 MAC 时钟是否已使能 */
#define __HAL_RCC_ETHMAC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) != RESET)
/* 检查以太网 MAC 时钟是否已禁用 */
#define __HAL_RCC_ETHMAC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACEN)) == RESET)
/* 检查以太网 MAC 发送时钟是否已使能 */
#define __HAL_RCC_ETHMACTX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) != RESET)
/* 检查以太网 MAC 发送时钟是否已禁用 */
#define __HAL_RCC_ETHMACTX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACTXEN)) == RESET)
/* 检查以太网 MAC 接收时钟是否已使能 */
#define __HAL_RCC_ETHMACRX_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) != RESET)
/* 检查以太网 MAC 接收时钟是否已禁用 */
#define __HAL_RCC_ETHMACRX_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_ETHMACRXEN)) == RESET)
#endif /* STM32F107xC*/

/**
  * @}
  */

/** @defgroup RCCEx_APB1_Clock_Enable_Disable APB1 Clock Enable Disable
  * @brief  使能或禁用低速 APB (APB1) 外设时钟。
  * @note   复位后，外设时钟是禁用的，应用程序在使用前必须使能该时钟。
  * @{
  */

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
/**
  * @brief  使能 CAN1 时钟。
  */
#define __HAL_RCC_CAN1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  禁用 CAN1 时钟。
  */
#define __HAL_RCC_CAN1_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN1EN))
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  使能 TIM4 时钟。
  */
#define __HAL_RCC_TIM4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能 SPI2 时钟。
  */
#define __HAL_RCC_SPI2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能 USART3 时钟。
  */
#define __HAL_RCC_USART3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  使能 I2C2 时钟。
  */
#define __HAL_RCC_I2C2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        /* RCC 外设时钟使能后的延时 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief  禁用 TIM4 时钟。
  */
#define __HAL_RCC_TIM4_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM4EN))
/**
  * @brief  禁用 SPI2 时钟。
  */
#define __HAL_RCC_SPI2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI2EN))
/**
  * @brief  禁用 USART3 时钟。
  */
#define __HAL_RCC_USART3_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_USART3EN))
/**
  * @brief  禁用 I2C2 时钟。
  */
#define __HAL_RCC_I2C2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C2EN))
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
