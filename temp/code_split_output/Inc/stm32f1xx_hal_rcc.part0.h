/**
  ******************************************************************************
  * @file    stm32f1xx_hal_rcc.h
  * @author  MCD Application Team
  * @brief   Header file of RCC HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
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

/** @defgroup RCC_Exported_Types RCC Exported Types
  * @{
  */

/**
  * @brief  RCC PLL configuration structure definition
  *         RCC PLL 配置结构体定义
  */
typedef struct
{
  uint32_t PLLState;      /*!< PLLState: The new state of the PLL.
                              PLL状态：PLL的新状态。
                              This parameter can be a value of @ref RCC_PLL_Config
                              此参数可以是 @ref RCC_PLL_Config 中的一个值 */

  uint32_t PLLSource;     /*!< PLLSource: PLL entry clock source.
                              PLL时钟源：PLL输入时钟源。
                              This parameter must be a value of @ref RCC_PLL_Clock_Source
                              此参数必须是 @ref RCC_PLL_Clock_Source 中的一个值 */

  uint32_t PLLMUL;        /*!< PLLMUL: Multiplication factor for PLL VCO input clock
                              PLL倍频系数：用于PLL VCO输入时钟的倍频因子
                              This parameter must be a value of @ref RCCEx_PLL_Multiplication_Factor
                              此参数必须是 @ref RCCEx_PLL_Multiplication_Factor 中的一个值 */
} RCC_PLLInitTypeDef;

/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  *         RCC 系统、AHB 和 APB 总线时钟配置结构体定义
  */
typedef struct
{
  uint32_t ClockType;             /*!< The clock to be configured.
                                       要配置的时钟类型。
                                       This parameter can be a value of @ref RCC_System_Clock_Type
                                       此参数可以是 @ref RCC_System_Clock_Type 中的一个值 */

  uint32_t SYSCLKSource;          /*!< The clock source (SYSCLKS) used as system clock.
                                       用作系统时钟的时钟源。
                                       This parameter can be a value of @ref RCC_System_Clock_Source
                                       此参数可以是 @ref RCC_System_Clock_Source 中的一个值 */

  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       AHB时钟(HCLK)分频系数。此时钟源自系统时钟(SYSCLK)。
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source
                                       此参数可以是 @ref RCC_AHB_Clock_Source 中的一个值 */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       APB1时钟(PCLK1)分频系数。此时钟源自AHB时钟(HCLK)。
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source
                                       此参数可以是 @ref RCC_APB1_APB2_Clock_Source 中的一个值 */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       APB2时钟(PCLK2)分频系数。此时钟源自AHB时钟(HCLK)。
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source
                                       此参数可以是 @ref RCC_APB1_APB2_Clock_Source 中的一个值 */
} RCC_ClkInitTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup RCC_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_PLL_Clock_Source PLL Clock Source
  * @{
  */

#define RCC_PLLSOURCE_HSI_DIV2      0x00000000U     /*!< HSI clock divided by 2 selected as PLL entry clock source */
                                                    // HSI时钟2分频后作为PLL输入时钟源
#define RCC_PLLSOURCE_HSE           RCC_CFGR_PLLSRC /*!< HSE clock selected as PLL entry clock source */
                                                    // HSE时钟作为PLL输入时钟源

/**
  * @}
  */

/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE            0x00000000U // 不配置任何振荡器
#define RCC_OSCILLATORTYPE_HSE             0x00000001U // 配置外部高速振荡器(HSE)
#define RCC_OSCILLATORTYPE_HSI             0x00000002U // 配置内部高速振荡器(HSI)
#define RCC_OSCILLATORTYPE_LSE             0x00000004U // 配置外部低速振荡器(LSE)
#define RCC_OSCILLATORTYPE_LSI             0x00000008U // 配置内部低速振荡器(LSI)
/**
  * @}
  */

/** @defgroup RCC_HSE_Config HSE Config
  * @{
  */
#define RCC_HSE_OFF                      0x00000000U                                /*!< HSE clock deactivation */
                                                                               // 关闭HSE时钟
#define RCC_HSE_ON                       RCC_CR_HSEON                               /*!< HSE clock activation */
                                                                               // 开启HSE时钟
#define RCC_HSE_BYPASS                   ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON)) /*!< External clock source for HSE clock */
                                                                               // HSE时钟旁路模式（使用外部时钟源）
/**
  * @}
  */

/** @defgroup RCC_LSE_Config LSE Config
  * @{
  */
#define RCC_LSE_OFF                      0x00000000U                                    /*!< LSE clock deactivation */
                                                                                   // 关闭LSE时钟
#define RCC_LSE_ON                       RCC_BDCR_LSEON                                 /*!< LSE clock activation */
                                                                                   // 开启LSE时钟
#define RCC_LSE_BYPASS                   ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON)) /*!< External clock source for LSE clock */
                                                                                   // LSE时钟旁路模式（使用外部时钟源）

/**
  * @}
  */

/** @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF                      0x00000000U                      /*!< HSI clock deactivation */
                                                                         // 关闭HSI时钟
#define RCC_HSI_ON                       RCC_CR_HSION                     /*!< HSI clock activation */
                                                                         // 开启HSI时钟

#define RCC_HSICALIBRATION_DEFAULT       0x10U         /* Default HSI calibration trimming value */
                                                       // 默认HSI校准修调值

/**
  * @}
  */

/** @defgroup RCC_LSI_Config LSI Config
  * @{
  */
#define RCC_LSI_OFF                      0x00000000U              /*!< LSI clock deactivation */
                                                                 // 关闭LSI时钟
#define RCC_LSI_ON                       RCC_CSR_LSION            /*!< LSI clock activation */
                                                                 // 开启LSI时钟

/**
  * @}
  */

/** @defgroup RCC_PLL_Config PLL Config
  * @{
  */
#define RCC_PLL_NONE                      0x00000000U  /*!< PLL is not configured */
                                                     // PLL未配置
#define RCC_PLL_OFF                       0x00000001U  /*!< PLL deactivation */
                                                     // 关闭PLL
#define RCC_PLL_ON                        0x00000002U  /*!< PLL activation */
                                                     // 开启PLL

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK             0x00000001U /*!< SYSCLK to configure */
                                                   // 配置系统时钟(SYSCLK)
#define RCC_CLOCKTYPE_HCLK               0x00000002U /*!< HCLK to configure */
                                                   // 配置AHB时钟(HCLK)
#define RCC_CLOCKTYPE_PCLK1              0x00000004U /*!< PCLK1 to configure */
                                                   // 配置APB1时钟(PCLK1)
#define RCC_CLOCKTYPE_PCLK2              0x00000008U /*!< PCLK2 to configure */
                                                   // 配置APB2时钟(PCLK2)

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source System Clock Source
  * @{
  */
#define RCC_SYSCLKSOURCE_HSI             RCC_CFGR_SW_HSI /*!< HSI selected as system clock */
                                                       // 选择HSI作为系统时钟
#define RCC_SYSCLKSOURCE_HSE             RCC_CFGR_SW_HSE /*!< HSE selected as system clock */
                                                       // 选择HSE作为系统时钟
#define RCC_SYSCLKSOURCE_PLLCLK          RCC_CFGR_SW_PLL /*!< PLL selected as system clock */
                                                       // 选择PLL作为系统时钟

/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source_Status System Clock Source Status
  * @{
  */
#define RCC_SYSCLKSOURCE_STATUS_HSI      RCC_CFGR_SWS_HSI            /*!< HSI used as system clock */
                                                                   // HSI正被用作系统时钟
#define RCC_SYSCLKSOURCE_STATUS_HSE      RCC_CFGR_SWS_HSE            /*!< HSE used as system clock */
                                                                   // HSE正被用作系统时钟
#define RCC_SYSCLKSOURCE_STATUS_PLLCLK   RCC_CFGR_SWS_PLL            /*!< PLL used as system clock */
                                                                   // PLL正被用作系统时钟

/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_SYSCLK_DIV1                  RCC_CFGR_HPRE_DIV1   /*!< SYSCLK not divided */
                                                            // SYSCLK不分频
#define RCC_SYSCLK_DIV2                  RCC_CFGR_HPRE_DIV2   /*!< SYSCLK divided by 2 */
                                                            // SYSCLK 2分频
#define RCC_SYSCLK_DIV4                  RCC_CFGR_HPRE_DIV4   /*!< SYSCLK divided by 4 */
                                                            // SYSCLK 4分频
#define RCC_SYSCLK_DIV8                  RCC_CFGR_HPRE_DIV8   /*!< SYSCLK divided by 8 */
                                                            // SYSCLK 8分频
#define RCC_SYSCLK_DIV16                 RCC_CFGR_HPRE_DIV16  /*!< SYSCLK divided by 16 */
                                                            // SYSCLK 16分频
#define RCC_SYSCLK_DIV64                 RCC_CFGR_HPRE_DIV64  /*!< SYSCLK divided by 64 */
                                                            // SYSCLK 64分频
#define RCC_SYSCLK_DIV128                RCC_CFGR_HPRE_DIV128 /*!< SYSCLK divided by 128 */
                                                            // SYSCLK 128分频
#define RCC_SYSCLK_DIV256                RCC_CFGR_HPRE_DIV256 /*!< SYSCLK divided by 256 */
                                                            // SYSCLK 256分频
#define RCC_SYSCLK_DIV512                RCC_CFGR_HPRE_DIV512 /*!< SYSCLK divided by 512 */
                                                            // SYSCLK 512分频

/**
  * @}
  */

/** @defgroup RCC_APB1_APB2_Clock_Source APB1 APB2 Clock Source
  * @{
  */
#define RCC_HCLK_DIV1                    RCC_CFGR_PPRE1_DIV1  /*!< HCLK not divided */
                                                            // HCLK不分频
#define RCC_HCLK_DIV2                    RCC_CFGR_PPRE1_DIV2  /*!< HCLK divided by 2 */
                                                            // HCLK 2分频
#define RCC_HCLK_DIV4                    RCC_CFGR_PPRE1_DIV4  /*!< HCLK divided by 4 */
                                                            // HCLK 4分频
#define RCC_HCLK_DIV8                    RCC_CFGR_PPRE1_DIV8  /*!< HCLK divided by 8 */
                                                            // HCLK 8分频
#define RCC_HCLK_DIV16                   RCC_CFGR_PPRE1_DIV16 /*!< HCLK divided by 16 */
                                                            // HCLK 16分频

/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Source RTC Clock Source
  * @{
  */
#define RCC_RTCCLKSOURCE_NO_CLK          0x00000000U                 /*!< No clock */
                                                                   // 无时钟
#define RCC_RTCCLKSOURCE_LSE             RCC_BDCR_RTCSEL_LSE                  /*!< LSE oscillator clock used as RTC clock */
                                                                           // LSE振荡器时钟用作RTC时钟
#define RCC_RTCCLKSOURCE_LSI             RCC_BDCR_RTCSEL_LSI                  /*!< LSI oscillator clock used as RTC clock */
                                                                           // LSI振荡器时钟用作RTC时钟
#define RCC_RTCCLKSOURCE_HSE_DIV128      RCC_BDCR_RTCSEL_HSE                    /*!< HSE oscillator clock divided by 128 used as RTC clock */
                                                                             // HSE振荡器时钟128分频后用作RTC时钟
/**
  * @}
  */


/** @defgroup RCC_MCO_Index MCO Index
  * @{
  */
#define RCC_MCO1                         0x00000000U // MCO1引脚索引

#define RCC_MCO                          RCC_MCO1               /*!< MCO1 to be compliant with other families with 2 MCOs*/
                                                              // 宏定义MCO为MCO1，以便与具有2个MCO的其他系列兼容

/**
  * @}
  */

/** @defgroup RCC_MCOx_Clock_Prescaler MCO Clock Prescaler
  * @{
  */
#define RCC_MCODIV_1                    0x00000000U // MCO时钟预分频系数为1（不分频）

/**
  * @}
  */

/** @defgroup RCC_Interrupt Interrupts
  * @{
  */
#define RCC_IT_LSIRDY                    ((uint8_t)RCC_CIR_LSIRDYF)   /*!< LSI Ready Interrupt flag */
                                                                     // LSI就绪中断标志
#define RCC_IT_LSERDY                    ((uint8_t)RCC_CIR_LSERDYF)   /*!< LSE Ready Interrupt flag */
                                                                     // LSE就绪中断标志
#define RCC_IT_HSIRDY                    ((uint8_t)RCC_CIR_HSIRDYF)   /*!< HSI Ready Interrupt flag */
                                                                     // HSI就绪中断标志
#define RCC_IT_HSERDY                    ((uint8_t)RCC_CIR_HSERDYF)   /*!< HSE Ready Interrupt flag */
                                                                     // HSE就绪中断标志
#define RCC_IT_PLLRDY                    ((uint8_t)RCC_CIR_PLLRDYF)   /*!< PLL Ready Interrupt flag */
                                                                     // PLL就绪中断标志
#define RCC_IT_CSS                       ((uint8_t)RCC_CIR_CSSF)      /*!< Clock Security System Interrupt flag */
                                                                     // 时钟安全系统中断标志
/**
  * @}
  */

/** @defgroup RCC_Flag Flags
  *        Elements values convention: XXXYYYYYb
  *           - YYYYY  : Flag position in the register (标志在寄存器中的位置)
  *           - XXX  : Register index (寄存器索引)
  *                 - 001: CR register (CR寄存器)
  *                 - 010: BDCR register (BDCR寄存器)
  *                 - 011: CSR register (CSR寄存器)
  * @{
  */
/* Flags in the CR register */
/* CR寄存器中的标志 */
#define RCC_FLAG_HSIRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSIRDY_Pos)) /*!< Internal High Speed clock ready flag */
                                                                                           // 内部高速时钟就绪标志
#define RCC_FLAG_HSERDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos)) /*!< External High Speed clock ready flag */
                                                                                           // 外部高速时钟就绪标志
#define RCC_FLAG_PLLRDY                  ((uint8_t)((CR_REG_INDEX << 5U) | RCC_CR_PLLRDY_Pos)) /*!< PLL clock ready flag */
                                                                                           // PLL时钟就绪标志

/* Flags in the CSR register */
/* CSR寄存器中的标志 */
#define RCC_FLAG_LSIRDY                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LSIRDY_Pos))   /*!< Internal Low Speed oscillator Ready */
                                                                                                 // 内部低速振荡器就绪
#define RCC_FLAG_PINRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PINRSTF_Pos))  /*!< PIN reset flag */
                                                                                                 // 引脚复位标志
#define RCC_FLAG_PORRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PORRSTF_Pos))  /*!< POR/PDR reset flag */
                                                                                                 // 上电/掉电复位标志
#define RCC_FLAG_SFTRST                  ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_SFTRSTF_Pos))  /*!< Software Reset flag */
                                                                                                 // 软件复位标志
#define RCC_FLAG_IWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_IWDGRSTF_Pos)) /*!< Independent Watchdog reset flag */
                                                                                                 // 独立看门狗复位标志
#define RCC_FLAG_WWDGRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_WWDGRSTF_Pos)) /*!< Window watchdog reset flag */
                                                                                                 // 窗口看门狗复位标志
#define RCC_FLAG_LPWRRST                 ((uint8_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LPWRRSTF_Pos)) /*!< Low-Power reset flag */
                                                                                                 // 低功耗复位标志

/* Flags in the BDCR register */
/* BDCR寄存器中的标志 */
#define RCC_FLAG_LSERDY                  ((uint8_t)((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSERDY_Pos)) /*!< External Low Speed oscillator Ready */
                                                                                                 // 外部低速振荡器就绪

/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/

/** @defgroup RCC_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_Peripheral_Clock_Enable_Disable Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock.
  *         使能或失能AHB1外设时钟。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是关闭的，应用程序在使用前必须使能该时钟。
  * @{
  */
// 使能DMA1时钟
#define __HAL_RCC_DMA1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时，确保时钟稳定 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_DMA1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能SRAM时钟
#define __HAL_RCC_SRAM_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_SRAMEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能FLITF时钟（Flash接口）
#define __HAL_RCC_FLITF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_FLITFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能CRC时钟
#define __HAL_RCC_CRC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->AHBENR, RCC_AHBENR_CRCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 失能DMA1时钟
#define __HAL_RCC_DMA1_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_DMA1EN))
// 失能SRAM时钟
#define __HAL_RCC_SRAM_CLK_DISABLE()      (RCC->AHBENR &= ~(RCC_AHBENR_SRAMEN))
// 失能FLITF时钟
#define __HAL_RCC_FLITF_CLK_DISABLE()     (RCC->AHBENR &= ~(RCC_AHBENR_FLITFEN))
// 失能CRC时钟
#define __HAL_RCC_CRC_CLK_DISABLE()       (RCC->AHBENR &= ~(RCC_AHBENR_CRCEN))

/**
  * @}
  */

/** @defgroup RCC_AHB_Peripheral_Clock_Enable_Disable_Status AHB Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the AHB peripheral clock.
  *         获取AHB外设时钟的使能或失能状态。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟是关闭的，应用程序在使用前必须使能该时钟。
  * @{
  */

// 检查DMA1时钟是否已使能
#define __HAL_RCC_DMA1_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_DMA1EN)) != RESET)
// 检查DMA1时钟是否已失能
#define __HAL_RCC_DMA1_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_DMA1EN)) == RESET)
// 检查SRAM时钟是否已使能
#define __HAL_RCC_SRAM_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_SRAMEN)) != RESET)
// 检查SRAM时钟是否已失能
#define __HAL_RCC_SRAM_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_SRAMEN)) == RESET)
// 检查FLITF时钟是否已使能
#define __HAL_RCC_FLITF_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_FLITFEN)) != RESET)
// 检查FLITF时钟是否已失能
#define __HAL_RCC_FLITF_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_FLITFEN)) == RESET)
// 检查CRC时钟是否已使能
#define __HAL_RCC_CRC_IS_CLK_ENABLED()       ((RCC->AHBENR & (RCC_AHBENR_CRCEN)) != RESET)
// 检查CRC时钟是否已失能
#define __HAL_RCC_CRC_IS_CLK_DISABLED()      ((RCC->AHBENR & (RCC_AHBENR_CRCEN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Enable_Disable APB1 Clock Enable Disable
  * @brief  Enable or disable the Low Speed APB (APB1) peripheral clock.
  *         使能或失能低速APB(APB1)外设时钟。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟是关闭的，应用程序在使用前必须使能该时钟。
  * @{
  */
// 使能TIM2时钟
#define __HAL_RCC_TIM2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能TIM3时钟
#define __HAL_RCC_TIM3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能WWDG时钟（窗口看门狗）
#define __HAL_RCC_WWDG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_WWDGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能USART2时钟
#define __HAL_RCC_USART2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能I2C1时钟
#define __HAL_RCC_I2C1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能BKP时钟（备份寄存器）
#define __HAL_RCC_BKP_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_BKPEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 使能PWR时钟（电源接口）
#define __HAL_RCC_PWR_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        /* Delay after an RCC peripheral clock enabling */\
                                        /* RCC外设时钟使能后的延时 */\
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_PWREN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

// 失能TIM2时钟
#define __HAL_RCC_TIM2_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM2EN))
// 失能TIM3时钟
#define __HAL_RCC_TIM3_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM3EN))
// 失能WWDG时钟
#define __HAL_RCC_WWDG_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_WWDGEN))
// 失能USART2时钟
#define __HAL_RCC_USART2_CLK_DISABLE()    (RCC->APB1ENR &= ~(RCC_APB1ENR_USART2EN))
// 失能I2C1时钟
#define __HAL_RCC_I2C1_CLK_DISABLE()      (RCC->APB1ENR &= ~(RCC_APB1ENR_I2C1EN))
