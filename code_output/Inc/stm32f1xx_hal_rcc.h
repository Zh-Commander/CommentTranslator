/**
  ******************************************************************************
  * @file    stm32f1xx_hal_rcc.h
  * @author  MCD Application Team
  * @brief   RCC HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  ******************************************************************************
  */

/* 定义以防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_RCC_H
#define __STM32F1xx_HAL_RCC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"


/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/

/** @defgroup RCC_Exported_Types RCC导出类型
  * @{
  */

/**
  * @brief  RCC PLL配置结构体定义
  *         用于配置PLL（锁相环）的相关参数
  */
typedef struct
{
  uint32_t PLLState;      /* PLLState：PLL的新状态。
                              该参数可以是 @ref RCC_PLL_Config 中的值 */

  uint32_t PLLSource;     /* PLLSource：PLL输入时钟源。
                              该参数必须是 @ref RCC_PLL_Clock_Source 中的值 */

  uint32_t PLLMUL;        /* PLLMUL：PLL VCO输入时钟的倍频系数。
                              该参数必须是 @ref RCCEx_PLL_Multiplication_Factor 中的值 */
} RCC_PLLInitTypeDef;

/**
  * @brief  RCC系统、AHB和APB总线时钟配置结构体定义
  *         用于配置系统时钟（SYSCLK）以及AHB、APB1、APB2总线的分频器
  */
typedef struct
{
  uint32_t ClockType;             /* 要配置的时钟类型。
                                       该参数可以是 @ref RCC_System_Clock_Type 中的值 */

  uint32_t SYSCLKSource;          /* 用作系统时钟的时钟源（SYSCLKS）。
                                       该参数可以是 @ref RCC_System_Clock_Source 中的值 */

  uint32_t AHBCLKDivider;         /* AHB时钟（HCLK）分频器。此时钟源自系统时钟（SYSCLK）。
                                       该参数可以是 @ref RCC_AHB_Clock_Source 中的值 */

  uint32_t APB1CLKDivider;        /* APB1时钟（PCLK1）分频器。此时钟源自AHB时钟（HCLK）。
                                       该参数可以是 @ref RCC_APB1_APB2_Clock_Source 中的值 */

  uint32_t APB2CLKDivider;        /* APB2时钟（PCLK2）分频器。此时钟源自AHB时钟（HCLK）。
                                       该参数可以是 @ref RCC_APB1_APB2_Clock_Source 中的值 */
} RCC_ClkInitTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup RCC_Exported_Constants RCC导出常量
  * @{
  */

/** @defgroup RCC_PLL_Clock_Source PLL时钟源
  * @{
  */

#define RCC_PLLSOURCE_HSI_DIV2      0x00000000U     /* HSI时钟2分频后作为PLL输入时钟源 */
#define RCC_PLLSOURCE_HSE           RCC_CFGR_PLLSRC /* HSE时钟作为PLL输入时钟源 */

/**
  * @}
  */

/** @defgroup RCC_Oscillator_Type 振荡器类型
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE            0x00000000U /* 未选择任何振荡器 */
#define RCC_OSCILLATORTYPE_HSE             0x00000001U /* 高速外部振荡器 (HSE) */
#define RCC_OSCILLATORTYPE_HSI             0x00000002U /* 高速内部振荡器 (HSI) */
#define RCC_OSCILLATORTYPE_LSE             0x00000004U /* 低速外部振荡器 (LSE) */
#define RCC_OSCILLATORTYPE_LSI             0x00000008U /* 低速内部振荡器 (LSI) */
/**
  * @}
  */

/** @defgroup RCC_HSE_Config HSE配置
  * @{
  */
#define RCC_HSE_OFF                      0x00000000U                                /* 关闭HSE时钟 */
#define RCC_HSE_ON                       RCC_CR_HSEON                               /* 开启HSE时钟 */
#define RCC_HSE_BYPASS                   ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON)) /* HSE时钟旁路，使用外部时钟源 */
/**
  * @}
  */

/** @defgroup RCC_LSE_Config LSE配置
  * @{
  */
#define RCC_LSE_OFF                      0x00000000U                                    /* 关闭LSE时钟 */
#define RCC_LSE_ON                       RCC_BDCR_LSEON                                 /* 开启LSE时钟 */
#define RCC_LSE_BYPASS                   ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON)) /* LSE时钟旁路，使用外部时钟源 */

/**
  * @}
  */

/** @defgroup RCC_HSI_Config HSI配置
  * @{
  */
#define RCC_HSI_OFF                      0x00000000U                      /* 关闭HSI时钟 */
#define RCC_HSI_ON                       RCC_CR_HSION                     /* 开启HSI时钟 */

#define RCC_HSICALIBRATION_DEFAULT       0x10U         /* 默认HSI校准修剪值 */

/**
  * @}
  */

/** @defgroup RCC_LSI_Config LSI配置
  * @{
  */
#define RCC_LSI_OFF                      0x00000000U              /* 关闭LSI时钟 */
#define RCC_LSI_ON                       RCC_CSR_LSION            /* 开启LSI时钟 */

/**
  * @}
  */

/** @defgroup RCC_PLL_Config PLL配置
  * @{
  */
#define RCC_PLL_NONE                      0x00000000U  /* PLL未配置 */
#define RCC_PLL_OFF                       0x00000001U  /* 关闭PLL */
#define RCC_PLL_ON                        0x00000002U  /* 开启PLL */

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Type 系统时钟类型
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK             0x00000001U /* 配置系统时钟 (SYSCLK) */
#define RCC_CLOCKTYPE_HCLK               0x00000002U /* 配置AHB时钟 (HCLK) */
#define RCC_CLOCKTYPE_PCLK1              0x00000004U /* 配置APB1时钟 (PCLK1) */
#define RCC_CLOCKTYPE_PCLK2              0x00000008U /* 配置APB2时钟 (PCLK2) */

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source 系统时钟源
  * @{
  */
#define RCC_SYSCLKSOURCE_HSI             RCC_CFGR_SW_HSI /* HSI作为系统时钟 */
#define RCC_SYSCLKSOURCE_HSE             RCC_CFGR_SW_HSE /* HSE作为系统时钟 */
#define RCC_SYSCLKSOURCE_PLLCLK          RCC_CFGR_SW_PLL /* PLL作为系统时钟 */

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source_Status 系统时钟源状态
  * @{
  */
#define RCC_SYSCLKSOURCE_STATUS_HSI      RCC_CFGR_SWS_HSI            /* HSI用作系统时钟 */
#define RCC_SYSCLKSOURCE_STATUS_HSE      RCC_CFGR_SWS_HSE            /* HSE用作系统时钟 */
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK   RCC_CFGR_SWS_PLL            /* PLL用作系统时钟 */

/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source AHB时钟源
  * @{
  */
#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1   /* SYSCLK不分频 */
#define RCC_SYSCLK_DIV2                  RCC_CFGR_HPRE_DIV2   /* SYSCLK 2分频 */
#define RCC_SYSCLK_DIV4                  RCC_CFGR_HPRE_DIV4   /* SYSCLK 4分频 */
#define RCC_SYSCLK_DIV8                  RCC_CFGR_HPRE_DIV8   /* SYSCLK 8分频 */
#define RCC_SYSCLK_DIV16                 RCC_CFGR_HPRE_DIV16  /* SYSCLK 16分频 */
#define RCC_SYSCLK_DIV64                 RCC_CFGR_HPRE_DIV64  /* SYSCLK 64分频 */
#define RCC_SYSCLK_DIV128                RCC_CFGR_HPRE_DIV128 /* SYSCLK 128分频 */
#define RCC_SYSCLK_DIV256                RCC_CFGR_HPRE_DIV256 /* SYSCLK 256分频 */
#define RCC_SYSCLK_DIV512                RCC_CFGR_HPRE_DIV512 /* SYSCLK 512分频 */

/**
  * @}
  */

/** @defgroup RCC_APB1_APB2_Clock_Source APB1 APB2时钟源
  * @{
  */
#define RCC_HCLK_DIV1                    RCC_CFGR_PPRE1_DIV1  /* HCLK不分频 */
#define RCC_HCLK_DIV2                    RCC_CFGR_PPRE1_DIV2  /* HCLK 2分频 */
#define RCC_HCLK_DIV4                    RCC_CFGR_PPRE1_DIV4  /* HCLK 4分频 */
#define RCC_HCLK_DIV8                    RCC_CFGR_PPRE1_DIV8  /* HCLK 8分频 */
#define RCC_HCLK_DIV16                   RCC_CFGR_PPRE1_DIV16 /* HCLK 16分频 */

/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Source RTC时钟源
  * @{
  */
#define RCC_RTCCLKSOURCE_NO_CLK          0x00000000U                 /* 无时钟 */
#define RCC_RTCCLKSOURCE_LSE             RCC_BDCR_RTCSEL_LSE                  /* LSE振荡器时钟用作RTC时钟 */
#define RCC_RTCCLKSOURCE_LSI             RCC_BDCR_RTCSEL_LSI                  /* LSI振荡器时钟用作RTC时钟 */
#define RCC_RTCCLKSOURCE_HSE_DIV128      RCC_BDCR_RTCSEL_HSE                    /* HSE振荡器时钟128分频后用作RTC时钟 */
/**
  * @}
  */


/** @defgroup RCC_MCO_Index MCO索引
  * @{
  */
#define RCC_MCO1                         0x00000000U
#define RCC_MCO                          RCC_MCO1               /* MCO1，以便与具有2个MCO的其他系列兼容 */

/**
  * @}
  */

/** @defgroup RCC_MCOx_Clock_Prescaler MCO时钟预分频
  * @{
  */
#define RCC_MCODIV_1                    0x00000000U /* MCO不分频 */

/**
  * @}
  */

/** @defgroup RCC_Interrupt 中断
  * @{
  */
#define RCC_IT_LSIRDY                    ((uint8_t)RCC_CIR_LSIRDYF)   /* LSI就绪中断标志 */
#define RCC_IT_LSERDY                    ((uint8_t)RCC_CIR_LSERDYF)   /* LSE就绪中断标志 */
#define RCC_IT_HSIRDY                    ((uint8_t)RCC_CIR_HSIRDYF)   /* HSI就绪中断标志 */
#define RCC_IT_HSERDY                    ((uint8_t)RCC_CIR_HSERDYF)   /* HSE就绪中断标志 */
#define RCC_IT_PLLRDY                    ((uint8_t)RCC_CIR_PLLRDYF)   /* PLL就绪中断标志 */
#define RCC_IT_CSS                       ((uint8_t)RCC_CIR_CSSF)      /* 时钟安全系统中断标志 */
/**
  * @}
  */

/** @defgroup RCC_Flag 标志
  *        元素值约定: XXXYYYYYb
  *           - YYYYY  : 标志在寄存器中的位置
  *           - XXX  : 寄存器索引
  *                 - 001: CR寄存器
  *                 - 010: BDCR寄存器
  *                 - 011: CSR寄存器
  * @{
  */
/* CR寄存器中的标志 */
#define RCC_FLAG_HSIRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSIRDY_Pos)) /* 内部高速时钟就绪标志 */
#define RCC_FLAG_HSERDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos)) /* 外部高速时钟就绪标志 */
#define RCC_FLAG_PLLRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLLRDY_Pos)) /* PLL时钟就绪标志 */

/* CSR寄存器中的标志 */
#define RCC_FLAG_LSIRDY                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LSIRDY_Pos))   /* 内部低速振荡器就绪 */
#define RCC_FLAG_PINRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PINRSTF_Pos))  /* 引脚复位标志 */
#define RCC_FLAG_PORRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PORRSTF_Pos))  /* POR/PDR复位标志 */
#define RCC_FLAG_SFTRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_SFTRSTF_Pos))  /* 软件复位标志 */
#define RCC_FLAG_IWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_IWDGRSTF_Pos)) /* 独立看门狗复位标志 */
#define RCC_FLAG_WWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_WWDGRSTF_Pos)) /* 窗口看门狗复位标志 */
#define RCC_FLAG_LPWRRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LPWRRSTF_Pos)) /* 低功耗复位标志 */

/* BDCR寄存器中的标志 */
#define RCC_FLAG_LSERDY                  ((uint8_t)((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSERDY_Pos)) /* 外部低速振荡器就绪 */

/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/

/** @defgroup RCC_Exported_Macros RCC导出宏
  * @{
  */

/** @defgroup RCC_Peripheral_Clock_Enable_Disable 外设时钟使能/失能
  * @brief  使能或失能AHB1外设时钟。
  * @note   复位后，外设时钟（用于寄存器读/写访问）被禁用，
  *         应用程序在使用之前必须使能此时钟。
  * @{
  */
/**
  * @brief 使能DMA1时钟
  * @note  执行流程：设置使能位 -> 读回使能位（确保操作完成，由于流水线原因需要延迟）
  */
#define __HAL_RCC_DMA1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能SRAM时钟
  */
#define __HAL_RCC_SRAM_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能FLITF（闪存接口）时钟
  */
#define __HAL_RCC_FLITF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能CRC时钟
  */
#define __HAL_RCC_CRC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 失能DMA1时钟
  */
#define __HAL_RCC_DMA1_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_DMA1EN))
/**
  * @brief 失能SRAM时钟
  */
#define __HAL_RCC_SRAM_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_SRAMEN))
/**
  * @brief 失能FLITF时钟
  */
#define __HAL_RCC_FLITF_CLK_DISABLE()     (RCC->AHBENR &= ~(RCC_AHBENR_FLITFEN))
/**
  * @brief 失能CRC时钟
  */
#define __HAL_RCC_CRC_CLK_DISABLE()       (RCC->AHBENR &= ~(RCC_AHBENR_CRCEN))

/**
  * @}
  */

/** @defgroup RCC_AHB_Peripheral_Clock_Enable_Disable_Status AHB外设时钟使能失能状态
  * @brief  获取AHB外设时钟的使能或失能状态。
  * @note   复位后，外设时钟（用于寄存器读/写访问）被禁用，
  *         应用程序在使用之前必须使能此时钟。
  * @{
  */

/**
  * @brief 检查DMA1时钟是否已使能
  */
#define __HAL_RCC_DMA1_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_DMA1EN)) != RESET)
/**
  * @brief 检查DMA1时钟是否已失能
  */
#define __HAL_RCC_DMA1_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_DMA1EN)) == RESET)
/**
  * @brief 检查SRAM时钟是否已使能
  */
#define __HAL_RCC_SRAM_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_SRAMEN)) != RESET)
/**
  * @brief 检查SRAM时钟是否已失能
  */
#define __HAL_RCC_SRAM_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_SRAMEN)) == RESET)
/**
  * @brief 检查FLITF时钟是否已使能
  */
#define __HAL_RCC_FLITF_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_FLITFEN)) != RESET)
/**
  * @brief 检查FLITF时钟是否已失能
  */
#define __HAL_RCC_FLITF_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_FLITFEN)) == RESET)
/**
  * @brief 检查CRC时钟是否已使能
  */
#define __HAL_RCC_CRC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_CRCEN)) != RESET)
/**
  * @brief 检查CRC时钟是否已失能
  */
#define __HAL_RCC_CRC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_CRCEN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Enable_Disable APB1时钟使能失能
  * @brief  使能或失能低速APB (APB1) 外设时钟。
  * @note   复位后，外设时钟（用于寄存器读/写访问）被禁用，
  *         应用程序在使用之前必须使能此时钟。
  * @{
  */
/**
  * @brief 使能TIM2时钟
  */
#define __HAL_RCC_TIM2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能TIM3时钟
  */
#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能WWDG（窗口看门狗）时钟
  */
#define __HAL_RCC_WWDG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能USART2时钟
  */
#define __HAL_RCC_USART2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能I2C1时钟
  */
#define __HAL_RCC_I2C1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能BKP（备份寄存器）时钟
  */
#define __HAL_RCC_BKP_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 使能PWR（电源接口）时钟
  */
#define __HAL_RCC_PWR_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/**
  * @brief 失能TIM2时钟
  */
#define __HAL_RCC_TIM2_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2EN))
/**
  * @brief 失能TIM3时钟
  */
#define __HAL_RCC_TIM3_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN))
/**
  * @brief 失能WWDG时钟
  */
#define __HAL_RCC_WWDG_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_WWDGEN))
/**
  * @brief 失能USART2时钟
  */
#define __HAL_RCC_USART2_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_USART2EN))
/**
  * @brief 失能I2C1时钟
  */
#define __HAL_RCC_I2C1_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C1EN))
#define __HAL_RCC_BKP_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_BKPEN)) // 关闭BKP(备份寄存器)时钟，通过清除APB1ENR寄存器的对应位
#define __HAL_RCC_PWR_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_PWREN)) // 关闭PWR(电源接口)时钟，通过清除APB1ENR寄存器的对应位

/**
  * @}
  */

/** @defgroup RCC_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  获取APB1外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */

/* 检查TIM2时钟是否已使能 (通过读取APB1ENR寄存器对应位) */
#define __HAL_RCC_TIM2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) != RESET)
/* 检查TIM2时钟是否已禁用 */
#define __HAL_RCC_TIM2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) == RESET)
/* 检查TIM3时钟是否已使能 */
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) != RESET)
/* 检查TIM3时钟是否已禁用 */
#define __HAL_RCC_TIM3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) == RESET)
/* 检查WWDG(窗口看门狗)时钟是否已使能 */
#define __HAL_RCC_WWDG_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) != RESET)
/* 检查WWDG时钟是否已禁用 */
#define __HAL_RCC_WWDG_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) == RESET)
/* 检查USART2时钟是否已使能 */
#define __HAL_RCC_USART2_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) != RESET)
/* 检查USART2时钟是否已禁用 */
#define __HAL_RCC_USART2_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) == RESET)
/* 检查I2C1时钟是否已使能 */
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) != RESET)
/* 检查I2C1时钟是否已禁用 */
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) == RESET)
/* 检查BKP时钟是否已使能 */
#define __HAL_RCC_BKP_IS_CLK_ENABLED()        ((RCC->APB1ENR & (RCC_APB1ENR_BKPEN)) != RESET)
/* 检查BKP时钟是否已禁用 */
#define __HAL_RCC_BKP_IS_CLK_DISABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_BKPEN)) == RESET)
/* 检查PWR时钟是否已使能 */
#define __HAL_RCC_PWR_IS_CLK_ENABLED()        ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) != RESET)
/* 检查PWR时钟是否已禁用 */
#define __HAL_RCC_PWR_IS_CLK_DISABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Enable_Disable APB2 Clock Enable Disable
  * @brief  使能或禁用高速APB (APB2) 外设时钟。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */

/* 使能AFIO(复用功能I/O)时钟。
   使用do...while(0)结构是为了保证宏定义的安全性。
   操作步骤：1. 设置APB2ENR寄存器的AFIOEN位。
            2. 读取该位以产生一个时钟周期的延迟，确保时钟使能生效。 */
#define __HAL_RCC_AFIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOA时钟。
   操作步骤：设置APB2ENR寄存器的IOPAEN位，并读取延迟。 */
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOB时钟 */
#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOC时钟 */
#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOD时钟 */
#define __HAL_RCC_GPIOD_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能ADC1时钟 */
#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM1时钟 */
#define __HAL_RCC_TIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能SPI1时钟 */
#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能USART1时钟 */
#define __HAL_RCC_USART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用AFIO时钟 */
#define __HAL_RCC_AFIO_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_AFIOEN))
/* 禁用GPIOA时钟 */
#define __HAL_RCC_GPIOA_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPAEN))
/* 禁用GPIOB时钟 */
#define __HAL_RCC_GPIOB_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPBEN))
/* 禁用GPIOC时钟 */
#define __HAL_RCC_GPIOC_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPCEN))
/* 禁用GPIOD时钟 */
#define __HAL_RCC_GPIOD_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPDEN))
/* 禁用ADC1时钟 */
#define __HAL_RCC_ADC1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN))

/* 禁用TIM1时钟 */
#define __HAL_RCC_TIM1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN))
/* 禁用SPI1时钟 */
#define __HAL_RCC_SPI1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
/* 禁用USART1时钟 */
#define __HAL_RCC_USART1_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN))

/**
  * @}
  */

/** @defgroup RCC_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  获取APB2外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */

/* 检查AFIO时钟是否已使能 */
#define __HAL_RCC_AFIO_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_AFIOEN)) != RESET)
/* 检查AFIO时钟是否已禁用 */
#define __HAL_RCC_AFIO_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_AFIOEN)) == RESET)
/* 检查GPIOA时钟是否已使能 */
#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPAEN)) != RESET)
/* 检查GPIOA时钟是否已禁用 */
#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPAEN)) == RESET)
/* 检查GPIOB时钟是否已使能 */
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPBEN)) != RESET)
/* 检查GPIOB时钟是否已禁用 */
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPBEN)) == RESET)
/* 检查GPIOC时钟是否已使能 */
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPCEN)) != RESET)
/* 检查GPIOC时钟是否已禁用 */
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPCEN)) == RESET)
/* 检查GPIOD时钟是否已使能 */
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPDEN)) != RESET)
/* 检查GPIOD时钟是否已禁用 */
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPDEN)) == RESET)
/* 检查ADC1时钟是否已使能 */
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) != RESET)
/* 检查ADC1时钟是否已禁用 */
#define __HAL_RCC_ADC1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) == RESET)
/* 检查TIM1时钟是否已使能 */
#define __HAL_RCC_TIM1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET)
/* 检查TIM1时钟是否已禁用 */
#define __HAL_RCC_TIM1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET)
/* 检查SPI1时钟是否已使能 */
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)
/* 检查SPI1时钟是否已禁用 */
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
/* 检查USART1时钟是否已使能 */
#define __HAL_RCC_USART1_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) != RESET)
/* 检查USART1时钟是否已禁用 */
#define __HAL_RCC_USART1_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  强制或释放APB1外设复位。
  * @{
  */
/* 强制复位APB1总线上的所有外设 */
#define __HAL_RCC_APB1_FORCE_RESET()       (RCC->APB1RSTR = 0xFFFFFFFFU)
/* 强制复位TIM2 */
#define __HAL_RCC_TIM2_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM2RST))
/* 强制复位TIM3 */
#define __HAL_RCC_TIM3_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST))
/* 强制复位WWDG(窗口看门狗) */
#define __HAL_RCC_WWDG_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_WWDGRST))
/* 强制复位USART2 */
#define __HAL_RCC_USART2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_USART2RST))
/* 强制复位I2C1 */
#define __HAL_RCC_I2C1_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C1RST))

/* 强制复位BKP(备份寄存器) */
#define __HAL_RCC_BKP_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_BKPRST))
/* 强制复位PWR(电源接口) */
#define __HAL_RCC_PWR_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_PWRRST))

/* 释放APB1总线上所有外设的复位状态 */
#define __HAL_RCC_APB1_RELEASE_RESET()      (RCC->APB1RSTR = 0x00)
/* 释放TIM2的复位状态 */
#define __HAL_RCC_TIM2_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM2RST))
/* 释放TIM3的复位状态 */
#define __HAL_RCC_TIM3_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST))
/* 释放WWDG的复位状态 */
#define __HAL_RCC_WWDG_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_WWDGRST))
/* 释放USART2的复位状态 */
#define __HAL_RCC_USART2_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST))
/* 释放I2C1的复位状态 */
#define __HAL_RCC_I2C1_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C1RST))

/* 释放BKP的复位状态 */
#define __HAL_RCC_BKP_RELEASE_RESET()        (RCC->APB1RSTR &= ~(RCC_APB1RSTR_BKPRST))
/* 释放PWR的复位状态 */
#define __HAL_RCC_PWR_RELEASE_RESET()        (RCC->APB1RSTR &= ~(RCC_APB1RSTR_PWRRST))

/**
  * @}
  */

/** @defgroup RCC_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  强制或释放APB2外设复位。
  * @{
  */
/* 强制复位APB2总线上的所有外设 */
#define __HAL_RCC_APB2_FORCE_RESET()       (RCC->APB2RSTR = 0xFFFFFFFFU)
/* 强制复位AFIO */
#define __HAL_RCC_AFIO_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_AFIORST))
/* 强制复位GPIOA */
#define __HAL_RCC_GPIOA_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPARST))
/* 强制复位GPIOB */
#define __HAL_RCC_GPIOB_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPBRST))
/* 强制复位GPIOC */
#define __HAL_RCC_GPIOC_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPCRST))
/* 强制复位GPIOD */
#define __HAL_RCC_GPIOD_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPDRST))
/* 强制复位ADC1 */
#define __HAL_RCC_ADC1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC1RST))

/* 强制复位TIM1 */
#define __HAL_RCC_TIM1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST))
/* 强制复位SPI1 */
#define __HAL_RCC_SPI1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))
/* 强制复位USART1 */
#define __HAL_RCC_USART1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST))

/* 释放APB2总线上所有外设的复位状态 */
#define __HAL_RCC_APB2_RELEASE_RESET()      (RCC->APB2RSTR = 0x00)
/* 释放AFIO的复位状态 */
#define __HAL_RCC_AFIO_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_AFIORST))
/* 释放GPIOA的复位状态 */
#define __HAL_RCC_GPIOA_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPARST))
/* 释放GPIOB的复位状态 */
#define __HAL_RCC_GPIOB_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPBRST))
/* 释放GPIOC的复位状态 */
#define __HAL_RCC_GPIOC_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPCRST))
/* 释放GPIOD的复位状态 */
#define __HAL_RCC_GPIOD_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPDRST))
/* 释放ADC1的复位状态 */
#define __HAL_RCC_ADC1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC1RST))

/* 释放TIM1的复位状态 */
#define __HAL_RCC_TIM1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST))
/* 释放SPI1的复位状态 */
#define __HAL_RCC_SPI1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
/* 释放USART1的复位状态 */
#define __HAL_RCC_USART1_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST))

/**
  * @}
  */

/** @defgroup RCC_HSI_Configuration HSI Configuration
  * @{
  */

/** @brief  使能或禁用内部高速振荡器 (HSI) 的宏。
  * @note   进入停止和待机模式时，硬件会停止HSI。
  * @note   如果HSI被用作系统时钟源，则不能停止HSI。在这种情况下，
  *         必须选择另一个系统时钟源，然后才能停止HSI。
  * @note   使能HSI后，应用程序软件应等待HSIRDY标志置位，
  *         这表明HSI时钟已稳定，可以用作系统时钟源。
  * @note   当HSI停止时，HSIRDY标志在6个HSI振荡器时钟周期后变低。
  */
/* 使能HSI (内部高速时钟)，使用位带操作实现原子操作 */
#define __HAL_RCC_HSI_ENABLE()  (*(__IO uint32_t *) RCC_CR_HSION_BB = ENABLE)
/* 禁用HSI */
#define __HAL_RCC_HSI_DISABLE() (*(__IO uint32_t *) RCC_CR_HSION_BB = DISABLE)

/** @brief  调整内部高速振荡器 (HSI) 校准值的宏。
  * @note   校准用于补偿电压和温度变化对内部HSI RC频率的影响。
  * @param  _HSICALIBRATIONVALUE_ 指定校准修剪值。
  *         (默认值为 RCC_HSICALIBRATION_DEFAULT)。
  *         该参数必须是0到0x1F之间的数字。
  */
/* 调整HSI校准值，修改CR寄存器的HSITRIM位 */
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(_HSICALIBRATIONVALUE_) \
          (MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, (uint32_t)(_HSICALIBRATIONVALUE_) << RCC_CR_HSITRIM_Pos))

/**
  * @}
  */

/** @defgroup RCC_LSI_Configuration  LSI Configuration
  * @{
  */

/** @brief 使能内部低速振荡器 (LSI) 的宏。
  * @note   使能LSI后，应用程序软件应等待LSIRDY标志置位，
  *         这表明LSI时钟已稳定，可用于为IWDG和/或RTC提供时钟。
  */
/* 使能LSI (内部低速时钟)，通常用于看门狗或RTC */
#define __HAL_RCC_LSI_ENABLE()  (*(__IO uint32_t *) RCC_CSR_LSION_BB = ENABLE)

/** @brief 禁用内部低速振荡器 (LSI) 的宏。
  * @note   如果IWDG正在运行，则不能禁用LSI。
  * @note   当LSI停止时，LSIRDY标志在6个LSI振荡器时钟周期后变低。
  */
/* 禁用LSI */
#define __HAL_RCC_LSI_DISABLE() (*(__IO uint32_t *) RCC_CSR_LSION_BB = DISABLE)

/**
  * @}
  */

/** @defgroup RCC_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @brief  配置外部高速振荡器 (HSE) 的宏。
  * @note   此宏不支持从HSE旁路到HSE开启，或从HSE开启到HSE旁路的直接转换。
  *         用户应先请求转换到HSE关闭状态，然后再转换到HSE开启或HSE旁路。
  * @note   使能HSE (RCC_HSE_ON 或 RCC_HSE_Bypass) 后，应用程序软件应等待
  *         HSERDY标志置位，这表明HSE时钟已稳定，可用于为PLL和/或系统时钟提供时钟。
  * @note   如果HSE直接或通过PLL用作系统时钟，则不能更改HSE状态。
  *         在这种情况下，必须选择另一个系统时钟源，然后更改HSE状态（例如禁用它）。
  * @note   进入停止和待机模式时，硬件会停止HSE。
  * @note   此函数会复位CSSON位，因此如果之前启用了时钟安全系统(CSS)，
  *         则在调用此函数后必须再次启用它。
  * @param  __STATE__ 指定HSE的新状态。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_HSE_OFF 关闭HSE振荡器，HSERDY标志在6个HSE振荡器时钟周期后变低。
  *            @arg @ref RCC_HSE_ON 开启HSE振荡器
  *            @arg @ref RCC_HSE_BYPASS HSE振荡器旁路，使用外部时钟源
  */
/* 配置HSE (外部高速时钟)。
   根据传入的参数状态，设置CR寄存器的HSEON和HSEBYP位。
   RCC_HSE_ON: 开启外部晶振
   RCC_HSE_OFF: 关闭外部晶振
   RCC_HSE_BYPASS: 旁路模式，直接输入外部时钟信号 */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_HSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);                    \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                    }while(0U)

/**
  * @}
  */

/** @defgroup RCC_LSE_Configuration LSE Configuration
  * @{
  */
/**
  * @brief  配置外部低速振荡器(LSE)的宏。
  * @note   此宏不支持从 LSE Bypass（旁路模式）转换到 LSE On（开启模式），
            也不支持从 LSE On 转换到 LSE Bypass。
  * @note   由于 LSE 位于备份域，复位后对该域的写访问被禁止，
            因此在配置 LSE 之前，必须使用 @ref HAL_PWR_EnableBkUpAccess() 函数
            使能写访问（复位后只需执行一次）。
  * @note   在使能 LSE (RCC_LSE_ON 或 RCC_LSE_BYPASS) 后，应用程序软件
            应等待 LSERDY 标志置位，这表明 LSE 时钟已稳定，
            可用于驱动 RTC。
  * @param  __STATE__ 指定 LSE 的新状态。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_LSE_OFF 关闭 LSE 振荡器，LSERDY 标志在
  *                              6 个 LSE 振荡器时钟周期后变低。
  *            @arg @ref RCC_LSE_ON 开启 LSE 振荡器。
  *            @arg @ref RCC_LSE_BYPASS LSE 振荡器被外部时钟旁路。
  */
#define __HAL_RCC_LSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_LSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                  \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                    }while(0U)

/**
  * @}
  */

/** @defgroup RCC_PLL_Configuration PLL 配置
  * @{
  */

/** @brief 使能主 PLL 的宏。
  * @note   在使能主 PLL 后，应用程序软件应等待 PLLRDY 标志置位，
            这表明 PLL 时钟已稳定，可用作系统时钟源。
  * @note   进入停止(STOP)和待机(STANDBY)模式时，硬件会自动禁用主 PLL。
  */
#define __HAL_RCC_PLL_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLON_BB = ENABLE)

/** @brief 禁用主 PLL 的宏。
  * @note   如果主 PLL 被用作系统时钟源，则不能被禁用。
  */
#define __HAL_RCC_PLL_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLON_BB = DISABLE)

/** @brief 配置主 PLL 时钟源和倍频因子的宏。
  * @note   此函数必须仅在主 PLL 被禁用时使用。
  *
  * @param  __RCC_PLLSOURCE__ 指定 PLL 输入时钟源。
  *          该参数可以是以下值之一:
  *            @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI 振荡器时钟经2分频后作为 PLL 输入时钟
  *            @arg @ref RCC_PLLSOURCE_HSE HSE 振荡器时钟作为 PLL 输入时钟
  * @param  __PLLMUL__ 指定 PLL VCO 输出时钟的倍频因子
  *          该参数可以是以下值之一:
  *             @arg @ref RCC_PLL_MUL4   PLLVCO = PLL 输入时钟 x 4
  *             @arg @ref RCC_PLL_MUL6   PLLVCO = PLL 输入时钟 x 6
  @if STM32F105xC
  *             @arg @ref RCC_PLL_MUL6_5 PLLVCO = PLL 输入时钟 x 6.5
  @elseif STM32F107xC
  *             @arg @ref RCC_PLL_MUL6_5 PLLVCO = PLL 输入时钟 x 6.5
  @else
  *             @arg @ref RCC_PLL_MUL2   PLLVCO = PLL 输入时钟 x 2
  *             @arg @ref RCC_PLL_MUL3   PLLVCO = PLL 输入时钟 x 3
  *             @arg @ref RCC_PLL_MUL10  PLLVCO = PLL 输入时钟 x 10
  *             @arg @ref RCC_PLL_MUL11  PLLVCO = PLL 输入时钟 x 11
  *             @arg @ref RCC_PLL_MUL12  PLLVCO = PLL 输入时钟 x 12
  *             @arg @ref RCC_PLL_MUL13  PLLVCO = PLL 输入时钟 x 13
  *             @arg @ref RCC_PLL_MUL14  PLLVCO = PLL 输入时钟 x 14
  *             @arg @ref RCC_PLL_MUL15  PLLVCO = PLL 输入时钟 x 15
  *             @arg @ref RCC_PLL_MUL16  PLLVCO = PLL 输入时钟 x 16
  @endif
  *             @arg @ref RCC_PLL_MUL8   PLLVCO = PLL 输入时钟 x 8
  *             @arg @ref RCC_PLL_MUL9   PLLVCO = PLL 输入时钟 x 9
  *
  */
#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSOURCE__, __PLLMUL__)\
          MODIFY_REG(RCC->CFGR, (RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL),((__RCC_PLLSOURCE__) | (__PLLMUL__) ))

/** @brief  获取选作 PLL 输入时钟的振荡器时钟
  * @retval 用于 PLL 输入的时钟源。返回值可以是以下值之一:
  *             @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI 振荡器时钟被选为 PLL 输入时钟
  *             @arg @ref RCC_PLLSOURCE_HSE HSE 振荡器时钟被选为 PLL 输入时钟
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PLLSRC)))

/**
  * @}
  */

/** @defgroup RCC_Get_Clock_source 获取时钟源
  * @{
  */

/**
  * @brief  配置系统时钟源的宏。
  * @param  __SYSCLKSOURCE__ 指定系统时钟源。
  *          该参数可以是以下值之一:
  *              @arg @ref RCC_SYSCLKSOURCE_HSI HSI 振荡器用作系统时钟源。
  *              @arg @ref RCC_SYSCLKSOURCE_HSE HSE 振荡器用作系统时钟源。
  *              @arg @ref RCC_SYSCLKSOURCE_PLLCLK PLL 输出用作系统时钟源。
  */
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))

/** @brief  获取用作系统时钟的时钟源。
  * @retval 用作系统时钟的时钟源。返回值可以是以下值之一:
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSI HSI 用作系统时钟
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSE HSE 用作系统时钟
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_PLLCLK PLL 用作系统时钟
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR,RCC_CFGR_SWS)))

/**
  * @}
  */

/** @defgroup RCCEx_MCOx_Clock_Config RCC 扩展 MCOx 时钟配置
  * @{
  */

#if   defined(RCC_CFGR_MCO_3)
/** @brief  配置 MCO 时钟的宏。
  * @param  __MCOCLKSOURCE__ 指定 MCO 时钟源。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK      无时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK       系统时钟 (SYSCLK) 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSI          HSI 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSE          HSE 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK       PLL 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLL2CLK      PLL2 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK_DIV2 PLL3 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_EXT_HSE XT1  外部 3-25 MHz 振荡器时钟被选为 MCO 时钟 (用于以太网)
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK      PLL3 时钟被选为 MCO 时钟 (用于以太网)
  * @param  __MCODIV__ 指定 MCO 时钟预分频器。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCODIV_1 MCO 时钟源不分频
  */
#else
/** @brief  配置 MCO 时钟的宏。
  * @param  __MCOCLKSOURCE__ 指定 MCO 时钟源。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK 无时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK  系统时钟 (SYSCLK) 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSI HSI 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSE HSE 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK  PLL 时钟 2 分频被选为 MCO 时钟
  * @param  __MCODIV__ 指定 MCO 时钟预分频器。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCODIV_1 MCO 时钟源不分频
  */
#endif

#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, (__MCOCLKSOURCE__))


/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Configuration RCC RTC 时钟配置
* @{
*/

/** @brief 配置 RTC 时钟 (RTCCLK) 的宏。
  * @note   由于 RTC 时钟配置位位于备份域，复位后对该域的写访问被禁止，
            因此在配置 RTC 时钟源之前，必须使用电源备份访问宏使能写访问
            （复位后只需执行一次）。
  * @note   一旦 RTC 时钟配置完成，除非使用 @ref __HAL_RCC_BACKUPRESET_FORCE() 宏
            复位备份域，或上电复位 (POR)，否则无法更改。
  *
  * @param  __RTC_CLKSOURCE__ 指定 RTC 时钟源。
  *          该参数可以是以下值之一:
  *             @arg @ref RCC_RTCCLKSOURCE_NO_CLK 无时钟被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_LSE LSE 被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_LSI LSI 被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE 128 分频被选为 RTC 时钟
  * @note   如果 LSE 或 LSI 用作 RTC 时钟源，RTC 在停止(STOP)和待机(STANDBY)模式下
            继续工作，并可用作唤醒源。
            然而，当 HSE 时钟用作 RTC 时钟源时，RTC 不能在停止和待机模式下使用。
  * @note   RTC 的最大输入时钟频率为 1MHz (当使用 HSE 作为 RTC 时钟源时)。
  */
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__) MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))

/** @brief 获取 RTC 时钟源的宏。
  * @retval 时钟源可以是以下值之一:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK 无时钟被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_LSE LSE 被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_LSI LSI 被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE 128 分频被选为 RTC 时钟
  */
#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

/** @brief 使能 RTC 时钟的宏。
  * @note   这些宏必须在选择了 RTC 时钟源之后使用。
  */
#define __HAL_RCC_RTC_ENABLE()          (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = ENABLE)

/** @brief 禁用 RTC 时钟的宏。
  * @note  这些宏必须在选择了 RTC 时钟源之后使用。
  */
#define __HAL_RCC_RTC_DISABLE()         (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = DISABLE)

/** @brief  强制备份域复位的宏。
  * @note   此函数复位 RTC 外设（包括备份寄存器）
            以及 RCC_BDCR 寄存器中的 RTC 时钟源选择。
  */
#define __HAL_RCC_BACKUPRESET_FORCE()   (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = ENABLE)

/** @brief  释放备份域复位的宏。
  */
#define __HAL_RCC_BACKUPRESET_RELEASE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = DISABLE)

/**
  * @}
  */

/** @defgroup RCC_Flags_Interrupts_Management 标志与中断管理
  * @brief 管理指定 RCC 标志和中断的宏。
  * @{
  */

/** @brief 使能 RCC 中断。
  * @param  __INTERRUPT__ 指定要使能的 RCC 中断源。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))

/** @brief 禁用 RCC 中断。
  * @param  __INTERRUPT__ 指定要禁用的 RCC 中断源。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))

/** @brief 清除 RCC 的中断挂起位。
  * @param  __INTERRUPT__ 指定要清除的中断挂起位。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断。
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断。
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断。
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断。
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断。
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  *            @arg @ref RCC_IT_CSS 时钟安全系统中断
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))

/** @brief 检查 RCC 中断是否发生。
  * @param  __INTERRUPT__ 指定要检查的 RCC 中断源。
  *          该参数可以是以下值之一:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断。
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断。
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断。
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断。
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断。
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  *            @arg @ref RCC_IT_CSS 时钟安全系统中断
  * @retval __INTERRUPT__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief 设置 RMVF 位以清除复位标志。
  *         复位标志包括 RCC_FLAG_PINRST, RCC_FLAG_PORRST, RCC_FLAG_SFTRST,
  *         RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST, RCC_FLAG_LPWRRST
  */
#define __HAL_RCC_CLEAR_RESET_FLAGS() (*(__IO uint32_t *)RCC_CSR_RMVF_BB = ENABLE)

/** @brief  检查 RCC 标志是否置位。
  * @param  __FLAG__ 指定要检查的标志。
  *          该参数可以是以下值之一:
  *            @arg @ref RCC_FLAG_HSIRDY HSI 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_HSERDY HSE 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_PLLRDY 主 PLL 时钟就绪。
  @if STM32F105xx
  *            @arg @ref RCC_FLAG_PLL2RDY 主 PLL2 时钟就绪。
  *            @arg @ref RCC_FLAG_PLLI2SRDY 主 PLLI2S 时钟就绪。
  @elsif STM32F107xx
  *            @arg @ref RCC_FLAG_PLL2RDY 主 PLL2 时钟就绪。
  *            @arg @ref RCC_FLAG_PLLI2SRDY 主 PLLI2S 时钟就绪。
  @endif
  *            @arg @ref RCC_FLAG_LSERDY LSE 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_LSIRDY LSI 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_PINRST  引脚复位。
  *            @arg @ref RCC_FLAG_PORRST  POR/PDR 复位。
  *            @arg @ref RCC_FLAG_SFTRST  软件复位。
  *            @arg @ref RCC_FLAG_IWDGRST 独立看门狗复位。
  *            @arg @ref RCC_FLAG_WWDGRST 窗口看门狗复位。
  *            @arg @ref RCC_FLAG_LPWRRST 低功耗复位。
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((__FLAG__) >> 5U) == CR_REG_INDEX)?   RCC->CR   : \
                                      ((((__FLAG__) >> 5U) == BDCR_REG_INDEX)? RCC->BDCR : \
                                                                              RCC->CSR)) & (1U << ((__FLAG__) & RCC_FLAG_MASK)))

/**
  * @}
  */

/**
  * @}
  */

/* 包含 RCC HAL 扩展模块 */
#include "stm32f1xx_hal_rcc_ex.h"

/* 导出的函数 --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */

/* 初始化和反初始化函数  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* 外设控制函数  ************************************************/
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
void              HAL_RCC_DisableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

/* CSS NMI IRQ 处理程序 */
void              HAL_RCC_NMI_IRQHandler(void);

/* 非阻塞模式下的用户回调函数 (中断模式) */
void              HAL_RCC_CSSCallback(void);

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCC_Private_Constants
  * @{
  */

/** @defgroup RCC_Timeout RCC 超时
  * @{
  */

/* 禁用备份域写保护状态改变的超时时间 */
#define RCC_DBP_TIMEOUT_VALUE          100U    /* 100 ms */
/* LSE 状态改变的超时时间 */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
#define CLOCKSWITCH_TIMEOUT_VALUE      5000    /* 5 s    */
#define HSE_TIMEOUT_VALUE              HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE              2U      /* 2 ms (最小 Tick + 1) */
#define LSI_TIMEOUT_VALUE              2U      /* 2 ms (最小 Tick + 1) */
#define PLL_TIMEOUT_VALUE              2U      /* 2 ms (最小 Tick + 1) */

/**
  * @}
  */

/** @defgroup RCC_Register_Offset 寄存器偏移
  * @{
  */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE) // RCC 基地址相对于外设基地址的偏移
#define RCC_CR_OFFSET             0x00U // CR 寄存器偏移
#define RCC_CFGR_OFFSET           0x04U // CFGR 寄存器偏移
#define RCC_CIR_OFFSET            0x08U // CIR 寄存器偏移
#define RCC_BDCR_OFFSET           0x20U // BDCR 寄存器偏移
#define RCC_CSR_OFFSET            0x24U // CSR 寄存器偏移

/**
  * @}
  */

/** @defgroup RCC_BitAddress_AliasRegion 位带别名区
  * @brief 别名区中 RCC 寄存器位的地址
  * @{
  */
#define RCC_CR_OFFSET_BB          (RCC_OFFSET + RCC_CR_OFFSET)
#define RCC_CFGR_OFFSET_BB        (RCC_OFFSET + RCC_CFGR_OFFSET)
#define RCC_CIR_OFFSET_BB         (RCC_OFFSET + RCC_CIR_OFFSET)
#define RCC_BDCR_OFFSET_BB        (RCC_OFFSET + RCC_BDCR_OFFSET)
#define RCC_CSR_OFFSET_BB         (RCC_OFFSET + RCC_CSR_OFFSET)

/* --- CR 寄存器 ---*/
/* HSION 位的别名地址 */
#define RCC_HSION_BIT_NUMBER      RCC_CR_HSION_Pos
#define RCC_CR_HSION_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSION_BIT_NUMBER * 4U)))
/* HSEON 位的别名地址 */
#define RCC_HSEON_BIT_NUMBER      RCC_CR_HSEON_Pos
#define RCC_CR_HSEON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSEON_BIT_NUMBER * 4U)))
/* CSSON 位的别名地址 */
#define RCC_CSSON_BIT_NUMBER      RCC_CR_CSSON_Pos
#define RCC_CR_CSSON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_CSSON_BIT_NUMBER * 4U)))
/* PLLON 位的别名地址 */
#define RCC_PLLON_BIT_NUMBER      RCC_CR_PLLON_Pos
#define RCC_CR_PLLON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_PLLON_BIT_NUMBER * 4U)))

/* --- CSR 寄存器 ---*/
/* LSION 位的别名地址 */
#define RCC_LSION_BIT_NUMBER      RCC_CSR_LSION_Pos
#define RCC_CSR_LSION_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_LSION_BIT_NUMBER * 4U)))

/* RMVF 位的别名地址 */
#define RCC_RMVF_BIT_NUMBER       RCC_CSR_RMVF_Pos
#define RCC_CSR_RMVF_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_RMVF_BIT_NUMBER * 4U)))

/* --- BDCR 寄存器 ---*/
/* LSEON 位的别名地址 */
#define RCC_LSEON_BIT_NUMBER      RCC_BDCR_LSEON_Pos
#define RCC_BDCR_LSEON_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEON_BIT_NUMBER * 4U)))

/* LSEBYP 位的别名地址 */
#define RCC_LSEBYP_BIT_NUMBER     RCC_BDCR_LSEBYP_Pos
#define RCC_BDCR_LSEBYP_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEBYP_BIT_NUMBER * 4U)))

/* RTCEN 位的别名地址 */
#define RCC_RTCEN_BIT_NUMBER      RCC_BDCR_RTCEN_Pos
#define RCC_BDCR_RTCEN_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U)))

/* BDRST 位的别名地址 */
#define RCC_BDRST_BIT_NUMBER      RCC_BDCR_BDRST_Pos
#define RCC_BDCR_BDRST_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_BDRST_BIT_NUMBER * 4U)))

/**
  * @}
  */

/* CR 寄存器字节 2 (位[23:16]) 基地址 */
#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))

/* CIR 寄存器字节 1 (位[15:8]) 基地址 */
#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))

/* CIR 寄存器字节 2 (位[23:16]) 基地址 */
#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))

/* 用于标志位的定义 */
#define CR_REG_INDEX                     ((uint8_t)1) // CR 寄存器索引
#define BDCR_REG_INDEX                   ((uint8_t)2) // BDCR 寄存器索引
#define CSR_REG_INDEX                    ((uint8_t)3) // CSR 寄存器索引

#define RCC_FLAG_MASK                    ((uint8_t)0x1F) // 标志位掩码

/**
  * @}
  */

/** @addtogroup RCC_Private_Macros
  * @{
  */
/** @defgroup RCC_Alias_For_Legacy 为兼容性保留的别名定义
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_DISABLE    __HAL_RCC_AFIO_CLK_DISABLE // SYSCFG 时钟禁用(兼容性宏)
#define __HAL_RCC_SYSCFG_CLK_ENABLE     __HAL_RCC_AFIO_CLK_ENABLE // SYSCFG 时钟使能(兼容性宏)
#define __HAL_RCC_SYSCFG_FORCE_RESET    __HAL_RCC_AFIO_FORCE_RESET // SYSCFG 强制复位(兼容性宏)
#define __HAL_RCC_SYSCFG_RELEASE_RESET  __HAL_RCC_AFIO_RELEASE_RESET // SYSCFG 释放复位(兼容性宏)
/**
  * @}
  */

#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_HSI_DIV2) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE)) // 检查是否为有效的 PLL 时钟源
#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)) // 检查是否为有效的振荡器类型
#define IS_RCC_HSE(__HSE__) (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                             ((__HSE__) == RCC_HSE_BYPASS)) // 检查是否为有效的 HSE 状态
#define IS_RCC_LSE(__LSE__) (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                             ((__LSE__) == RCC_LSE_BYPASS)) // 检查是否为有效的 LSE 状态
#define IS_RCC_HSI(__HSI__) (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON)) // 检查是否为有效的 HSI 状态
#define IS_RCC_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 0x1FU) // 检查是否为有效的 HSI 校准值
#define IS_RCC_LSI(__LSI__) (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON)) // 检查是否为有效的 LSI 状态
#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON)) // 检查是否为有效的 PLL 状态

#define IS_RCC_CLOCKTYPE(CLK) ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                               (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2)) // 检查是否为有效的时钟类型
#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK)) // 检查是否为有效的系统时钟源
#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK)) // 检查是否为有效的系统时钟源状态
#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512)) // 检查是否为有效的 AHB 分频系数
#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16)) // 检查是否为有效的 APB 分频系数
#define IS_RCC_MCO(__MCO__)  ((__MCO__) == RCC_MCO) // 检查是否为有效的 MCO
#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1)) // 检查是否为有效的 MCO 分频系数
#define IS_RCC_RTCCLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV128)) // 检查是否为有效的 RTC 时钟源

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_HAL_RCC_H */
