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
