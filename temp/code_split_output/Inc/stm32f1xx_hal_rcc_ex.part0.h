/**
  ******************************************************************************
  * @file    stm32f1xx_hal_rcc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of RCC HAL Extension module.
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
#ifndef __STM32F1xx_HAL_RCC_EX_H
#define __STM32F1xx_HAL_RCC_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup RCCEx
  * @{
  */

/** @addtogroup RCCEx_Private_Constants
 * @{
 */

#if defined(STM32F105xC) || defined(STM32F107xC)

/* Alias word address of PLLI2SON bit */
/* PLLI2SON位的别名地址 */
#define PLLI2SON_BITNUMBER           RCC_CR_PLL3ON_Pos
// 定义PLLI2S开启位的位号
#define RCC_CR_PLLI2SON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (PLLI2SON_BITNUMBER * 4U)))
// 通过位带操作计算PLLI2S控制位的别名地址，实现原子操作
/* Alias word address of PLL2ON bit */
/* PLL2ON位的别名地址 */
#define PLL2ON_BITNUMBER             RCC_CR_PLL2ON_Pos
// 定义PLL2开启位的位号
#define RCC_CR_PLL2ON_BB             ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (PLL2ON_BITNUMBER * 4U)))
// 通过位带操作计算PLL2控制位的别名地址

#define PLLI2S_TIMEOUT_VALUE         100U  /* 100 ms */
// PLLI2S锁定超时时间定义
#define PLL2_TIMEOUT_VALUE           100U  /* 100 ms */
// PLL2锁定超时时间定义

#endif /* STM32F105xC || STM32F107xC */


#define CR_REG_INDEX                 ((uint8_t)1)
// CR寄存器索引定义，用于寄存器操作时的索引查找

/**
  * @}
  */

/** @addtogroup RCCEx_Private_Macros
 * @{
 */

#if defined(STM32F105xC) || defined(STM32F107xC)
// 判断PREDIV1输入源是否有效，HSE或PLL2
#define IS_RCC_PREDIV1_SOURCE(__SOURCE__) (((__SOURCE__) == RCC_PREDIV1_SOURCE_HSE) || \
                                           ((__SOURCE__) == RCC_PREDIV1_SOURCE_PLL2))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
// 判断HSE预分频系数是否有效（1-16分频），适用于互联型和价值型产品
#define IS_RCC_HSE_PREDIV(__DIV__) (((__DIV__) == RCC_HSE_PREDIV_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV_DIV2)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV3)  || ((__DIV__) == RCC_HSE_PREDIV_DIV4)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV5)  || ((__DIV__) == RCC_HSE_PREDIV_DIV6)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV7)  || ((__DIV__) == RCC_HSE_PREDIV_DIV8)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV9)  || ((__DIV__) == RCC_HSE_PREDIV_DIV10) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV11) || ((__DIV__) == RCC_HSE_PREDIV_DIV12) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV13) || ((__DIV__) == RCC_HSE_PREDIV_DIV14) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV15) || ((__DIV__) == RCC_HSE_PREDIV_DIV16))

#else
// 判断HSE预分频系数是否有效（仅1或2分频），适用于普通产品
#define IS_RCC_HSE_PREDIV(__DIV__) (((__DIV__) == RCC_HSE_PREDIV_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV_DIV2))
#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
// 判断PLL倍频系数是否有效（互联型产品支持4-9倍及6.5倍）
#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5) || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7) || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9) || \
                                 ((__MUL__) == RCC_PLL_MUL6_5))

// 判断MCO1输出时钟源是否有效（互联型产品支持更多时钟源）
#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK)  || ((__SOURCE__) == RCC_MCO1SOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_HSE)     || ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_PLL2CLK) || ((__SOURCE__) == RCC_MCO1SOURCE_PLL3CLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_PLL3CLK_DIV2) || ((__SOURCE__) == RCC_MCO1SOURCE_EXT_HSE) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK))

#else
// 判断PLL倍频系数是否有效（普通产品支持2-16倍频）
#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL2)  || ((__MUL__) == RCC_PLL_MUL3)  || \
                                 ((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5)  || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7)  || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9)  || \
                                 ((__MUL__) == RCC_PLL_MUL10) || ((__MUL__) == RCC_PLL_MUL11) || \
                                 ((__MUL__) == RCC_PLL_MUL12) || ((__MUL__) == RCC_PLL_MUL13) || \
                                 ((__MUL__) == RCC_PLL_MUL14) || ((__MUL__) == RCC_PLL_MUL15) || \
                                 ((__MUL__) == RCC_PLL_MUL16))

// 判断MCO1输出时钟源是否有效（普通产品仅支持SYSCLK, HSI, HSE, PLL, NOCLOCK）
#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK)  || ((__SOURCE__) == RCC_MCO1SOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_HSE)     || ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK))

#endif /* STM32F105xC || STM32F107xC*/

// 判断ADC预分频系数是否有效（2, 4, 6, 8分频）
#define IS_RCC_ADCPLLCLK_DIV(__ADCCLK__) (((__ADCCLK__) == RCC_ADCPCLK2_DIV2)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV4)   || \
                                          ((__ADCCLK__) == RCC_ADCPCLK2_DIV6)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV8))

#if defined(STM32F105xC) || defined(STM32F107xC)
// 判断I2S2时钟源是否有效
#define IS_RCC_I2S2CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_I2S2CLKSOURCE_SYSCLK)  || ((__SOURCE__) == RCC_I2S2CLKSOURCE_PLLI2S_VCO))

// 判断I2S3时钟源是否有效
#define IS_RCC_I2S3CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_I2S3CLKSOURCE_SYSCLK)  || ((__SOURCE__) == RCC_I2S3CLKSOURCE_PLLI2S_VCO))

// 判断USB时钟预分频系数是否有效（互联型：2分频或3分频）
#define IS_RCC_USBPLLCLK_DIV(__USBCLK__) (((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV2)  || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV3))

// 判断PLLI2S倍频系数是否有效
#define IS_RCC_PLLI2S_MUL(__MUL__) (((__MUL__) == RCC_PLLI2S_MUL8)   || ((__MUL__) == RCC_PLLI2S_MUL9)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL10)  || ((__MUL__) == RCC_PLLI2S_MUL11)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL12)  || ((__MUL__) == RCC_PLLI2S_MUL13)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL14)  || ((__MUL__) == RCC_PLLI2S_MUL16)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL20))

// 判断PREDIV2预分频系数是否有效（1-16分频）
#define IS_RCC_HSE_PREDIV2(__DIV__) (((__DIV__) == RCC_HSE_PREDIV2_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV2)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV3)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV4)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV5)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV6)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV7)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV8)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV9)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV10) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV11) || ((__DIV__) == RCC_HSE_PREDIV2_DIV12) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV13) || ((__DIV__) == RCC_HSE_PREDIV2_DIV14) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV15) || ((__DIV__) == RCC_HSE_PREDIV2_DIV16))

// 判断PLL2状态是否有效
#define IS_RCC_PLL2(__PLL__) (((__PLL__) == RCC_PLL2_NONE) || ((__PLL__) == RCC_PLL2_OFF) || \
                              ((__PLL__) == RCC_PLL2_ON))

// 判断PLL2倍频系数是否有效
#define IS_RCC_PLL2_MUL(__MUL__) (((__MUL__) == RCC_PLL2_MUL8)  || ((__MUL__) == RCC_PLL2_MUL9)  || \
                                  ((__MUL__) == RCC_PLL2_MUL10)  || ((__MUL__) == RCC_PLL2_MUL11)  || \
                                  ((__MUL__) == RCC_PLL2_MUL12)  || ((__MUL__) == RCC_PLL2_MUL13)  || \
                                  ((__MUL__) == RCC_PLL2_MUL14)  || ((__MUL__) == RCC_PLL2_MUL16)  || \
                                  ((__MUL__) == RCC_PLL2_MUL20))

// 判断外设时钟选择是否有效（互联型：RTC, ADC, I2S2, I2S3, USB）
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S2)  == RCC_PERIPHCLK_I2S2)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S3)   == RCC_PERIPHCLK_I2S3)   || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB)   == RCC_PERIPHCLK_USB))

#elif defined(STM32F103xE) || defined(STM32F103xG)

// 判断I2S2时钟源是否有效（大容量产品仅支持系统时钟）
#define IS_RCC_I2S2CLKSOURCE(__SOURCE__) ((__SOURCE__) == RCC_I2S2CLKSOURCE_SYSCLK)

// 判断I2S3时钟源是否有效
#define IS_RCC_I2S3CLKSOURCE(__SOURCE__) ((__SOURCE__) == RCC_I2S3CLKSOURCE_SYSCLK)

// 判断外设时钟选择是否有效（大容量产品：RTC, ADC, I2S2, I2S3, USB）
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S2) == RCC_PERIPHCLK_I2S2)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S3) == RCC_PERIPHCLK_I2S3)   || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB)  == RCC_PERIPHCLK_USB))


#elif defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB)

// 判断外设时钟选择是否有效（中容量产品：RTC, ADC, USB）
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB) == RCC_PERIPHCLK_USB))

#else

// 判断外设时钟选择是否有效（其他产品：RTC, ADC）
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC))

#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

// 判断USB时钟预分频系数是否有效（非互联型：1分频或1.5分频）
#define IS_RCC_USBPLLCLK_DIV(__USBCLK__) (((__USBCLK__) == RCC_USBCLKSOURCE_PLL)  || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV1_5))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

/**
  * @}
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Types RCCEx Exported Types
  * @{
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  RCC PLL2 configuration structure definition
  *         RCC PLL2 配置结构体定义（仅互联型设备有PLL2）
  */
typedef struct
{
  uint32_t PLL2State;     /*!< The new state of the PLL2.
                              This parameter can be a value of @ref RCCEx_PLL2_Config */
                          /* PLL2的新状态，参数可以是RCCEx_PLL2_Config中的值 */

  uint32_t PLL2MUL;         /*!< PLL2MUL: Multiplication factor for PLL2 VCO input clock
                              This parameter must be a value of @ref RCCEx_PLL2_Multiplication_Factor*/
                          /* PLL2MUL: PLL2 VCO输入时钟的倍频因子，参数必须是RCCEx_PLL2_Multiplication_Factor中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t HSEPrediv2Value;       /*!<  The Prediv2 factor value.
                                       This parameter can be a value of @ref RCCEx_Prediv2_Factor */
                          /* Prediv2预分频因子值，参数可以是RCCEx_Prediv2_Factor中的值 */

#endif /* STM32F105xC || STM32F107xC */
} RCC_PLL2InitTypeDef;

#endif /* STM32F105xC || STM32F107xC */

/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition
  *         RCC 内部/外部振荡器 (HSE, HSI, LSE 和 LSI) 配置结构体定义
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< The oscillators to be configured.
                                       This parameter can be a value of @ref RCC_Oscillator_Type */
                          /* 需要配置的振荡器类型，参数可以是RCC_Oscillator_Type中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t Prediv1Source;       /*!<  The Prediv1 source value.
                                       This parameter can be a value of @ref RCCEx_Prediv1_Source */
                          /* Prediv1的输入源选择，参数可以是RCCEx_Prediv1_Source中的值 */
#endif /* STM32F105xC || STM32F107xC */

  uint32_t HSEState;              /*!< The new state of the HSE.
                                       This parameter can be a value of @ref RCC_HSE_Config */
                          /* HSE（外部高速时钟）的新状态，参数可以是RCC_HSE_Config中的值 */

  uint32_t HSEPredivValue;       /*!<  The Prediv1 factor value (named PREDIV1 or PLLXTPRE in RM)
                                       This parameter can be a value of @ref RCCEx_Prediv1_Factor */
                          /* Prediv1预分频因子值（在参考手册中称为PREDIV1或PLLXTPRE），参数可以是RCCEx_Prediv1_Factor中的值 */

  uint32_t LSEState;              /*!<  The new state of the LSE.
                                        This parameter can be a value of @ref RCC_LSE_Config */
                          /* LSE（外部低速时钟）的新状态，参数可以是RCC_LSE_Config中的值 */

  uint32_t HSIState;              /*!< The new state of the HSI.
                                       This parameter can be a value of @ref RCC_HSI_Config */
                          /* HSI（内部高速时钟）的新状态，参数可以是RCC_HSI_Config中的值 */

  uint32_t HSICalibrationValue;   /*!< The HSI calibration trimming value (default is RCC_HSICALIBRATION_DEFAULT).
                                       This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x1F */
                          /* HSI校准调整值（默认为RCC_HSICALIBRATION_DEFAULT），参数范围：0x00 到 0x1F */

  uint32_t LSIState;              /*!<  The new state of the LSI.
                                        This parameter can be a value of @ref RCC_LSI_Config */
                          /* LSI（内部低速时钟）的新状态，参数可以是RCC_LSI_Config中的值 */

  RCC_PLLInitTypeDef PLL;         /*!< PLL structure parameters */
                          /* PLL结构体参数，配置主PLL */

#if defined(STM32F105xC) || defined(STM32F107xC)
  RCC_PLL2InitTypeDef PLL2;         /*!< PLL2 structure parameters */
                          /* PLL2结构体参数，仅互联型设备拥有 */
#endif /* STM32F105xC || STM32F107xC */
} RCC_OscInitTypeDef;

#if defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  RCC PLLI2S configuration structure definition
  *         RCC PLLI2S 配置结构体定义（用于I2S音频时钟）
  */
typedef struct
{
  uint32_t PLLI2SMUL;         /*!< PLLI2SMUL: Multiplication factor for PLLI2S VCO input clock
                              This parameter must be a value of @ref RCCEx_PLLI2S_Multiplication_Factor*/
                          /* PLLI2SMUL: PLLI2S VCO输入时钟的倍频因子，参数必须是RCCEx_PLLI2S_Multiplication_Factor中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t HSEPrediv2Value;       /*!<  The Prediv2 factor value.
                                       This parameter can be a value of @ref RCCEx_Prediv2_Factor */
                          /* Prediv2预分频因子值，参数可以是RCCEx_Prediv2_Factor中的值 */

#endif /* STM32F105xC || STM32F107xC */
} RCC_PLLI2SInitTypeDef;
#endif /* STM32F105xC || STM32F107xC */

/**
  * @brief  RCC extended clocks structure definition
  *         RCC 扩展时钟配置结构体定义
  */
typedef struct
{
  uint32_t PeriphClockSelection;      /*!< The Extended Clock to be configured.
                                       This parameter can be a value of @ref RCCEx_Periph_Clock_Selection */
                          /* 需要配置的扩展时钟外设，参数可以是RCCEx_Periph_Clock_Selection中的值 */

  uint32_t RTCClockSelection;         /*!< specifies the RTC clock source.
                                       This parameter can be a value of @ref RCC_RTC_Clock_Source */
                          /* 指定RTC时钟源，参数可以是RCC_RTC_Clock_Source中的值 */

  uint32_t AdcClockSelection;         /*!< ADC clock source
                                       This parameter can be a value of @ref RCCEx_ADC_Prescaler */
                          /* ADC时钟源配置（预分频），参数可以是RCCEx_ADC_Prescaler中的值 */

#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
  uint32_t I2s2ClockSelection;         /*!< I2S2 clock source
                                       This parameter can be a value of @ref RCCEx_I2S2_Clock_Source */
                          /* I2S2时钟源选择，参数可以是RCCEx_I2S2_Clock_Source中的值 */

  uint32_t I2s3ClockSelection;         /*!< I2S3 clock source
                                       This parameter can be a value of @ref RCCEx_I2S3_Clock_Source */
                          /* I2S3时钟源选择，参数可以是RCCEx_I2S3_Clock_Source中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  RCC_PLLI2SInitTypeDef PLLI2S;  /*!< PLL I2S structure parameters
                                      This parameter will be used only when PLLI2S is selected as Clock Source I2S2 or I2S3 */
                          /* PLL I2S结构体参数，仅当PLLI2S被选为I2S2或I2S3时钟源时使用 */

#endif /* STM32F105xC || STM32F107xC */
#endif /* STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t UsbClockSelection;         /*!< USB clock source
                                       This parameter can be a value of @ref RCCEx_USB_Prescaler */
                          /* USB时钟源配置（预分频），参数可以是RCCEx_USB_Prescaler中的值 */

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
} RCC_PeriphCLKInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Constants RCCEx Exported Constants
  * @{
  */

/** @defgroup RCCEx_Periph_Clock_Selection Periph Clock Selection
  *         外设时钟选择宏定义
  * @{
  */
#define RCC_PERIPHCLK_RTC           0x00000001U
// RTC外设时钟选择标志位
#define RCC_PERIPHCLK_ADC           0x00000002U
// ADC外设时钟选择标志位
#if defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_PERIPHCLK_I2S2          0x00000004U
// I2S2外设时钟选择标志位
#define RCC_PERIPHCLK_I2S3          0x00000008U
// I2S3外设时钟选择标志位
#endif /* STM32F101xE || STM32F101xG || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_PERIPHCLK_USB          0x00000010U
// USB外设时钟选择标志位
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_ADC_Prescaler ADC Prescaler
  *         ADC预分频器配置
  * @{
  */
#define RCC_ADCPCLK2_DIV2              RCC_CFGR_ADCPRE_DIV2
// PCLK2 2分频后作为ADC时钟
#define RCC_ADCPCLK2_DIV4              RCC_CFGR_ADCPRE_DIV4
// PCLK2 4分频后作为ADC时钟
#define RCC_ADCPCLK2_DIV6              RCC_CFGR_ADCPRE_DIV6
// PCLK2 6分频后作为ADC时钟
#define RCC_ADCPCLK2_DIV8              RCC_CFGR_ADCPRE_DIV8
// PCLK2 8分频后作为ADC时钟

/**
  * @}
  */

#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
/** @defgroup RCCEx_I2S2_Clock_Source I2S2 Clock Source
  *         I2S2时钟源选择
  * @{
  */
#define RCC_I2S2CLKSOURCE_SYSCLK              0x00000000U
// I2S2时钟源选择系统时钟
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_I2S2CLKSOURCE_PLLI2S_VCO          RCC_CFGR2_I2S2SRC
// I2S2时钟源选择PLLI2S VCO输出（仅互联型支持）
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_I2S3_Clock_Source I2S3 Clock Source
  *         I2S3时钟源选择
  * @{
  */
#define RCC_I2S3CLKSOURCE_SYSCLK              0x00000000U
// I2S3时钟源选择系统时钟
#if defined(STM32F105xC) || defined(STM32F107xC)
#define RCC_I2S3CLKSOURCE_PLLI2S_VCO          RCC_CFGR2_I2S3SRC
// I2S3时钟源选择PLLI2S VCO输出（仅互联型支持）
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

#endif /* STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

/** @defgroup RCCEx_USB_Prescaler USB Prescaler
  *         USB预分频器配置（非互联型）
  * @{
  */
#define RCC_USBCLKSOURCE_PLL              RCC_CFGR_USBPRE
// USB时钟源为PLL 1.5分频
#define RCC_USBCLKSOURCE_PLL_DIV1_5       0x00000000U
// USB时钟源为PLL直接输出（实际对应寄存器配置，需结合参考手册理解）

/**
  * @}
  */

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */


#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_USB_Prescaler USB Prescaler
  *         USB预分频器配置（互联型）
  * @{
  */
#define RCC_USBCLKSOURCE_PLL_DIV2              RCC_CFGR_OTGFSPRE
// PLL 2分频作为USB时钟
#define RCC_USBCLKSOURCE_PLL_DIV3              0x00000000U
// PLL 3分频作为USB时钟

/**
  * @}
  */

/** @defgroup RCCEx_PLLI2S_Multiplication_Factor PLLI2S Multiplication Factor
  *         PLLI2S倍频因子配置
  * @{
  */

#define RCC_PLLI2S_MUL8                   RCC_CFGR2_PLL3MUL8   /*!< PLLI2S input clock * 8 */
// PLLI2S输入时钟乘以8
#define RCC_PLLI2S_MUL9                   RCC_CFGR2_PLL3MUL9   /*!< PLLI2S input clock * 9 */
// PLLI2S输入时钟乘以9
#define RCC_PLLI2S_MUL10                  RCC_CFGR2_PLL3MUL10  /*!< PLLI2S input clock * 10 */
// PLLI2S输入时钟乘以10
#define RCC_PLLI2S_MUL11                  RCC_CFGR2_PLL3MUL11  /*!< PLLI2S input clock * 11 */
// PLLI2S输入时钟乘以11
#define RCC_PLLI2S_MUL12                  RCC_CFGR2_PLL3MUL12  /*!< PLLI2S input clock * 12 */
// PLLI2S输入时钟乘以12
#define RCC_PLLI2S_MUL13                  RCC_CFGR2_PLL3MUL13  /*!< PLLI2S input clock * 13 */
// PLLI2S输入时钟乘以13
#define RCC_PLLI2S_MUL14                  RCC_CFGR2_PLL3MUL14  /*!< PLLI2S input clock * 14 */
// PLLI2S输入时钟乘以14
#define RCC_PLLI2S_MUL16                  RCC_CFGR2_PLL3MUL16  /*!< PLLI2S input clock * 16 */
// PLLI2S输入时钟乘以16
#define RCC_PLLI2S_MUL20                  RCC_CFGR2_PLL3MUL20  /*!< PLLI2S input clock * 20 */
// PLLI2S输入时钟乘以20

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Prediv1_Source Prediv1 Source
  *         PREDIV1输入源选择（互联型）
  * @{
  */

#define RCC_PREDIV1_SOURCE_HSE           RCC_CFGR2_PREDIV1SRC_HSE
// PREDIV1输入源选择为HSE
#define RCC_PREDIV1_SOURCE_PLL2          RCC_CFGR2_PREDIV1SRC_PLL2
// PREDIV1输入源选择为PLL2
