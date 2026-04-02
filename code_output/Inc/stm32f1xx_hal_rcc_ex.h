/**
  ******************************************************************************
  * @file    stm32f1xx_hal_rcc_ex.h
  * @author  MCD Application Team
  * @brief   RCC HAL 扩展模块头文件。
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

/* PLLI2SON 位的别名地址 */
/* PLLI2S(即PLL3)使能位的位号 */
#define PLLI2SON_BITNUMBER           RCC_CR_PLL3ON_Pos
/* PLLI2S使能位的位带操作地址 */
#define RCC_CR_PLLI2SON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (PLLI2SON_BITNUMBER * 4U)))
/* PLL2ON 位的别名地址 */
/* PLL2使能位的位号 */
#define PLL2ON_BITNUMBER             RCC_CR_PLL2ON_Pos
/* PLL2使能位的位带操作地址 */
#define RCC_CR_PLL2ON_BB             ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (PLL2ON_BITNUMBER * 4U)))

/* PLLI2S 超时值定义：100毫秒 */
#define PLLI2S_TIMEOUT_VALUE         100U  /* 100 ms */
/* PLL2 超时值定义：100毫秒 */
#define PLL2_TIMEOUT_VALUE           100U  /* 100 ms */

#endif /* STM32F105xC || STM32F107xC */


/* CR寄存器索引定义 */
#define CR_REG_INDEX                 ((uint8_t)1)

/**
  * @}
  */

/** @addtogroup RCCEx_Private_Macros
 * @{
 */

#if defined(STM32F105xC) || defined(STM32F107xC)
/* 检查 PREDIV1 输入时钟源是否有效：HSE 或 PLL2 */
#define IS_RCC_PREDIV1_SOURCE(__SOURCE__) (((__SOURCE__) == RCC_PREDIV1_SOURCE_HSE) || \
                                           ((__SOURCE__) == RCC_PREDIV1_SOURCE_PLL2))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/* 检查 HSE 预分频系数是否有效（支持1-16分频），用于互联型和价值型系列 */
#define IS_RCC_HSE_PREDIV(__DIV__) (((__DIV__) == RCC_HSE_PREDIV_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV_DIV2)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV3)  || ((__DIV__) == RCC_HSE_PREDIV_DIV4)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV5)  || ((__DIV__) == RCC_HSE_PREDIV_DIV6)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV7)  || ((__DIV__) == RCC_HSE_PREDIV_DIV8)  || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV9)  || ((__DIV__) == RCC_HSE_PREDIV_DIV10) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV11) || ((__DIV__) == RCC_HSE_PREDIV_DIV12) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV13) || ((__DIV__) == RCC_HSE_PREDIV_DIV14) || \
                                    ((__DIV__) == RCC_HSE_PREDIV_DIV15) || ((__DIV__) == RCC_HSE_PREDIV_DIV16))

#else
/* 检查 HSE 预分频系数是否有效（仅支持1或2分频），用于其他系列 */
#define IS_RCC_HSE_PREDIV(__DIV__) (((__DIV__) == RCC_HSE_PREDIV_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV_DIV2))
#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
/* 检查 PLL 倍频系数是否有效（互联型系列支持4-9倍及6.5倍） */
#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5) || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7) || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9) || \
                                 ((__MUL__) == RCC_PLL_MUL6_5))

/* 检查 MCO1 输出时钟源是否有效（互联型系列支持更多时钟源） */
#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK)  || ((__SOURCE__) == RCC_MCO1SOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_HSE)     || ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_PLL2CLK) || ((__SOURCE__) == RCC_MCO1SOURCE_PLL3CLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_PLL3CLK_DIV2) || ((__SOURCE__) == RCC_MCO1SOURCE_EXT_HSE) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK))

#else
/* 检查 PLL 倍频系数是否有效（非互联型系列支持2-16倍） */
#define IS_RCC_PLL_MUL(__MUL__) (((__MUL__) == RCC_PLL_MUL2)  || ((__MUL__) == RCC_PLL_MUL3)  || \
                                 ((__MUL__) == RCC_PLL_MUL4)  || ((__MUL__) == RCC_PLL_MUL5)  || \
                                 ((__MUL__) == RCC_PLL_MUL6)  || ((__MUL__) == RCC_PLL_MUL7)  || \
                                 ((__MUL__) == RCC_PLL_MUL8)  || ((__MUL__) == RCC_PLL_MUL9)  || \
                                 ((__MUL__) == RCC_PLL_MUL10) || ((__MUL__) == RCC_PLL_MUL11) || \
                                 ((__MUL__) == RCC_PLL_MUL12) || ((__MUL__) == RCC_PLL_MUL13) || \
                                 ((__MUL__) == RCC_PLL_MUL14) || ((__MUL__) == RCC_PLL_MUL15) || \
                                 ((__MUL__) == RCC_PLL_MUL16))

/* 检查 MCO1 输出时钟源是否有效（非互联型系列） */
#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK)  || ((__SOURCE__) == RCC_MCO1SOURCE_HSI) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_HSE)     || ((__SOURCE__) == RCC_MCO1SOURCE_PLLCLK) \
                                    || ((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK))

#endif /* STM32F105xC || STM32F107xC*/

/* 检查 ADC 时钟分频系数是否有效：2, 4, 6, 8分频 */
#define IS_RCC_ADCPLLCLK_DIV(__ADCCLK__) (((__ADCCLK__) == RCC_ADCPCLK2_DIV2)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV4)   || \
                                          ((__ADCCLK__) == RCC_ADCPCLK2_DIV6)  || ((__ADCCLK__) == RCC_ADCPCLK2_DIV8))

#if defined(STM32F105xC) || defined(STM32F107xC)
/* 检查 I2S2 时钟源选择是否有效：系统时钟 或 PLLI2S VCO */
#define IS_RCC_I2S2CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_I2S2CLKSOURCE_SYSCLK)  || ((__SOURCE__) == RCC_I2S2CLKSOURCE_PLLI2S_VCO))

/* 检查 I2S3 时钟源选择是否有效：系统时钟 或 PLLI2S VCO */
#define IS_RCC_I2S3CLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_I2S3CLKSOURCE_SYSCLK)  || ((__SOURCE__) == RCC_I2S3CLKSOURCE_PLLI2S_VCO))

/* 检查 USB 时钟分频系数是否有效：PLL 2分频 或 3分频 */
#define IS_RCC_USBPLLCLK_DIV(__USBCLK__) (((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV2)  || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV3))

/* 检查 PLLI2S 倍频系数是否有效 */
#define IS_RCC_PLLI2S_MUL(__MUL__) (((__MUL__) == RCC_PLLI2S_MUL8)   || ((__MUL__) == RCC_PLLI2S_MUL9)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL10)  || ((__MUL__) == RCC_PLLI2S_MUL11)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL12)  || ((__MUL__) == RCC_PLLI2S_MUL13)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL14)  || ((__MUL__) == RCC_PLLI2S_MUL16)  || \
                                    ((__MUL__) == RCC_PLLI2S_MUL20))

/* 检查 HSE 预分频2 (PREDIV2) 系数是否有效：支持1-16分频 */
#define IS_RCC_HSE_PREDIV2(__DIV__) (((__DIV__) == RCC_HSE_PREDIV2_DIV1)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV2)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV3)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV4)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV5)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV6)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV7)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV8)  || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV9)  || ((__DIV__) == RCC_HSE_PREDIV2_DIV10) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV11) || ((__DIV__) == RCC_HSE_PREDIV2_DIV12) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV13) || ((__DIV__) == RCC_HSE_PREDIV2_DIV14) || \
                                     ((__DIV__) == RCC_HSE_PREDIV2_DIV15) || ((__DIV__) == RCC_HSE_PREDIV2_DIV16))

/* 检查 PLL2 状态配置是否有效：无、关闭 或 开启 */
#define IS_RCC_PLL2(__PLL__) (((__PLL__) == RCC_PLL2_NONE) || ((__PLL__) == RCC_PLL2_OFF) || \
                              ((__PLL__) == RCC_PLL2_ON))

/* 检查 PLL2 倍频系数是否有效 */
#define IS_RCC_PLL2_MUL(__MUL__) (((__MUL__) == RCC_PLL2_MUL8)  || ((__MUL__) == RCC_PLL2_MUL9)  || \
                                  ((__MUL__) == RCC_PLL2_MUL10)  || ((__MUL__) == RCC_PLL2_MUL11)  || \
                                  ((__MUL__) == RCC_PLL2_MUL12)  || ((__MUL__) == RCC_PLL2_MUL13)  || \
                                  ((__MUL__) == RCC_PLL2_MUL14)  || ((__MUL__) == RCC_PLL2_MUL16)  || \
                                  ((__MUL__) == RCC_PLL2_MUL20))

/* 检查外设时钟选择是否有效（互联型：RTC, ADC, I2S2, I2S3, USB） */
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S2)  == RCC_PERIPHCLK_I2S2)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S3)   == RCC_PERIPHCLK_I2S3)   || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB)   == RCC_PERIPHCLK_USB))

#elif defined(STM32F103xE) || defined(STM32F103xG)

/* 检查 I2S2 时钟源选择是否有效（大容量型：仅系统时钟） */
#define IS_RCC_I2S2CLKSOURCE(__SOURCE__) ((__SOURCE__) == RCC_I2S2CLKSOURCE_SYSCLK)

/* 检查 I2S3 时钟源选择是否有效（大容量型：仅系统时钟） */
#define IS_RCC_I2S3CLKSOURCE(__SOURCE__) ((__SOURCE__) == RCC_I2S3CLKSOURCE_SYSCLK)

/* 检查外设时钟选择是否有效（大容量型：RTC, ADC, I2S2, I2S3, USB） */
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S2) == RCC_PERIPHCLK_I2S2)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_I2S3) == RCC_PERIPHCLK_I2S3)   || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB)  == RCC_PERIPHCLK_USB))


#elif defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB)

/* 检查外设时钟选择是否有效（中容量型：RTC, ADC, USB） */
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC) == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC) == RCC_PERIPHCLK_ADC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_USB) == RCC_PERIPHCLK_USB))

#else

/* 检查外设时钟选择是否有效（其他型号：RTC, ADC） */
#define IS_RCC_PERIPHCLOCK(__SELECTION__)  \
               ((((__SELECTION__) & RCC_PERIPHCLK_RTC)  == RCC_PERIPHCLK_RTC)  || \
                (((__SELECTION__) & RCC_PERIPHCLK_ADC)  == RCC_PERIPHCLK_ADC))

#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

/* 检查 USB 时钟分频系数是否有效：PLL直接输出 或 PLL 1.5分频 */
#define IS_RCC_USBPLLCLK_DIV(__USBCLK__) (((__USBCLK__) == RCC_USBCLKSOURCE_PLL)  || ((__USBCLK__) == RCC_USBCLKSOURCE_PLL_DIV1_5))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

/**
  * @}
  */

/* 导出类型 ------------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Types RCCEx 导出类型
  * @{
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  RCC PLL2 配置结构体定义
  *         用于配置PLL2的相关参数（仅互联型设备）
  */
typedef struct
{
  uint32_t PLL2State;     /*!< PLL2 的新状态。
                               此参数可以是 @ref RCCEx_PLL2_Config 中的值 */

  uint32_t PLL2MUL;         /*!< PLL2MUL: PLL2 VCO 输入时钟的倍频因子
                               此参数必须是 @ref RCCEx_PLL2_Multiplication_Factor 中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t HSEPrediv2Value;       /*!<  Prediv2 分频因子值。
                                       此参数可以是 @ref RCCEx_Prediv2_Factor 中的值 */

#endif /* STM32F105xC || STM32F107xC */
} RCC_PLL2InitTypeDef;

#endif /* STM32F105xC || STM32F107xC */

/**
  * @brief  RCC 内部/外部振荡器 (HSE, HSI, LSE 和 LSI) 配置结构体定义
  *         用于配置系统时钟源和PLL参数
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< 需要配置的振荡器类型。
                                       此参数可以是 @ref RCC_Oscillator_Type 中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t Prediv1Source;       /*!<  Prediv1 输入时钟源值。
                                       此参数可以是 @ref RCCEx_Prediv1_Source 中的值 */
#endif /* STM32F105xC || STM32F107xC */

  uint32_t HSEState;              /*!< HSE 的新状态。
                                       此参数可以是 @ref RCC_HSE_Config 中的值 */

  uint32_t HSEPredivValue;       /*!<  Prediv1 分频因子值 (在参考手册中名为 PREDIV1 或 PLLXTPRE)。
                                       此参数可以是 @ref RCCEx_Prediv1_Factor 中的值 */

  uint32_t LSEState;              /*!<  LSE 的新状态。
                                        此参数可以是 @ref RCC_LSE_Config 中的值 */

  uint32_t HSIState;              /*!< HSI 的新状态。
                                       此参数可以是 @ref RCC_HSI_Config 中的值 */

  uint32_t HSICalibrationValue;   /*!< HSI 校准修剪值 (默认为 RCC_HSICALIBRATION_DEFAULT)。
                                       此参数必须是 Min_Data = 0x00 和 Max_Data = 0x1F 之间的数字 */

  uint32_t LSIState;              /*!<  LSI 的新状态。
                                        此参数可以是 @ref RCC_LSI_Config 中的值 */

  RCC_PLLInitTypeDef PLL;         /*!< PLL 结构体参数 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  RCC_PLL2InitTypeDef PLL2;         /*!< PLL2 结构体参数 */
#endif /* STM32F105xC || STM32F107xC */
} RCC_OscInitTypeDef;

#if defined(STM32F105xC) || defined(STM32F107xC)
/**
  * @brief  RCC PLLI2S 配置结构体定义
  *         用于配置PLLI2S（通常用于I2S音频时钟）
  */
typedef struct
{
  uint32_t PLLI2SMUL;         /*!< PLLI2SMUL: PLLI2S VCO 输入时钟的倍频因子
                              此参数必须是 @ref RCCEx_PLLI2S_Multiplication_Factor 中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t HSEPrediv2Value;       /*!<  Prediv2 分频因子值。
                                       此参数可以是 @ref RCCEx_Prediv2_Factor 中的值 */

#endif /* STM32F105xC || STM32F107xC */
} RCC_PLLI2SInitTypeDef;
#endif /* STM32F105xC || STM32F107xC */

/**
  * @brief  RCC 扩展时钟结构体定义
  *         用于配置外设时钟源（RTC, ADC, USB, I2S等）
  */
typedef struct
{
  uint32_t PeriphClockSelection;      /*!< 需要配置的扩展时钟。
                                       此参数可以是 @ref RCCEx_Periph_Clock_Selection 中的值 */

  uint32_t RTCClockSelection;         /*!< 指定 RTC 时钟源。
                                       此参数可以是 @ref RCC_RTC_Clock_Source 中的值 */

  uint32_t AdcClockSelection;         /*!< ADC 时钟源
                                       此参数可以是 @ref RCCEx_ADC_Prescaler 中的值 */

#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
  uint32_t I2s2ClockSelection;         /*!< I2S2 时钟源
                                       此参数可以是 @ref RCCEx_I2S2_Clock_Source 中的值 */

  uint32_t I2s3ClockSelection;         /*!< I2S3 时钟源
                                       此参数可以是 @ref RCCEx_I2S3_Clock_Source 中的值 */

#if defined(STM32F105xC) || defined(STM32F107xC)
  RCC_PLLI2SInitTypeDef PLLI2S;  /*!< PLL I2S 结构体参数
                                      仅当选择 PLLI2S 作为 I2S2 或 I2S3 时钟源时使用此参数 */

#endif /* STM32F105xC || STM32F107xC */
#endif /* STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
  uint32_t UsbClockSelection;         /*!< USB 时钟源
                                       此参数可以是 @ref RCCEx_USB_Prescaler 中的值 */

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
} RCC_PeriphCLKInitTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/

/** @defgroup RCCEx_Exported_Constants RCCEx 导出常量
  * @{
  */

/** @defgroup RCCEx_Periph_Clock_Selection 外设时钟选择
  * @{
  */
/* RTC外设时钟选择标志 */
#define RCC_PERIPHCLK_RTC           0x00000001U
/* ADC外设时钟选择标志 */
#define RCC_PERIPHCLK_ADC           0x00000002U
#if defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
/* I2S2外设时钟选择标志 */
#define RCC_PERIPHCLK_I2S2          0x00000004U
/* I2S3外设时钟选择标志 */
#define RCC_PERIPHCLK_I2S3          0x00000008U
#endif /* STM32F101xE || STM32F101xG || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
/* USB外设时钟选择标志 */
#define RCC_PERIPHCLK_USB          0x00000010U
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_ADC_Prescaler ADC 预分频器
  * @{
  */
/* ADC时钟 PCLK2 2分频 */
#define RCC_ADCPCLK2_DIV2              RCC_CFGR_ADCPRE_DIV2
/* ADC时钟 PCLK2 4分频 */
#define RCC_ADCPCLK2_DIV4              RCC_CFGR_ADCPRE_DIV4
/* ADC时钟 PCLK2 6分频 */
#define RCC_ADCPCLK2_DIV6              RCC_CFGR_ADCPRE_DIV6
/* ADC时钟 PCLK2 8分频 */
#define RCC_ADCPCLK2_DIV8              RCC_CFGR_ADCPRE_DIV8

/**
  * @}
  */

#if defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
/** @defgroup RCCEx_I2S2_Clock_Source I2S2 时钟源
  * @{
  */
/* I2S2 时钟源：系统时钟 */
#define RCC_I2S2CLKSOURCE_SYSCLK              0x00000000U
#if defined(STM32F105xC) || defined(STM32F107xC)
/* I2S2 时钟源：PLLI2S VCO时钟（仅互联型） */
#define RCC_I2S2CLKSOURCE_PLLI2S_VCO          RCC_CFGR2_I2S2SRC
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup RCCEx_I2S3_Clock_Source I2S3 时钟源
  * @{
  */
/* I2S3 时钟源：系统时钟 */
#define RCC_I2S3CLKSOURCE_SYSCLK              0x00000000U
#if defined(STM32F105xC) || defined(STM32F107xC)
/* I2S3 时钟源：PLLI2S VCO时钟（仅互联型） */
#define RCC_I2S3CLKSOURCE_PLLI2S_VCO          RCC_CFGR2_I2S3SRC
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

#endif /* STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)

/** @defgroup RCCEx_USB_Prescaler USB 预分频器
  * @{
  */
/* USB时钟源：PLL直接作为时钟源 */
#define RCC_USBCLKSOURCE_PLL              RCC_CFGR_USBPRE
/* USB时钟源：PLL 1.5分频 */
#define RCC_USBCLKSOURCE_PLL_DIV1_5       0x00000000U

/**
  * @}
  */

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */


#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_USB_Prescaler USB 预分频器
  * @{
  */
/* USB时钟源：PLL 2分频 */
#define RCC_USBCLKSOURCE_PLL_DIV2              RCC_CFGR_OTGFSPRE
/* USB时钟源：PLL 3分频 */
#define RCC_USBCLKSOURCE_PLL_DIV3              0x00000000U

/**
  * @}
  */

/** @defgroup RCCEx_PLLI2S_Multiplication_Factor PLLI2S 倍频因子
  * @{
  */

/* PLLI2S 输入时钟 8倍频 */
#define RCC_PLLI2S_MUL8                   RCC_CFGR2_PLL3MUL8   /*!< PLLI2S input clock * 8 */
/* PLLI2S 输入时钟 9倍频 */
#define RCC_PLLI2S_MUL9                   RCC_CFGR2_PLL3MUL9   /*!< PLLI2S input clock * 9 */
/* PLLI2S 输入时钟 10倍频 */
#define RCC_PLLI2S_MUL10                  RCC_CFGR2_PLL3MUL10  /*!< PLLI2S input clock * 10 */
/* PLLI2S 输入时钟 11倍频 */
#define RCC_PLLI2S_MUL11                  RCC_CFGR2_PLL3MUL11  /*!< PLLI2S input clock * 11 */
/* PLLI2S 输入时钟 12倍频 */
#define RCC_PLLI2S_MUL12                  RCC_CFGR2_PLL3MUL12  /*!< PLLI2S input clock * 12 */
/* PLLI2S 输入时钟 13倍频 */
#define RCC_PLLI2S_MUL13                  RCC_CFGR2_PLL3MUL13  /*!< PLLI2S input clock * 13 */
/* PLLI2S 输入时钟 14倍频 */
#define RCC_PLLI2S_MUL14                  RCC_CFGR2_PLL3MUL14  /*!< PLLI2S input clock * 14 */
/* PLLI2S 输入时钟 16倍频 */
#define RCC_PLLI2S_MUL16                  RCC_CFGR2_PLL3MUL16  /*!< PLLI2S input clock * 16 */
/* PLLI2S 输入时钟 20倍频 */
#define RCC_PLLI2S_MUL20                  RCC_CFGR2_PLL3MUL20  /*!< PLLI2S input clock * 20 */

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Prediv1_Source Prediv1 时钟源
  * @{
  */

/* PREDIV1 时钟源：HSE */
#define RCC_PREDIV1_SOURCE_HSE           RCC_CFGR2_PREDIV1SRC_HSE
/* PREDIV1 时钟源：PLL2 */
#define RCC_PREDIV1_SOURCE_PLL2          RCC_CFGR2_PREDIV1SRC_PLL2
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
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
/* 使能USB时钟宏定义 */
#define __HAL_RCC_USB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_USBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 关闭USB时钟宏定义 */
#define __HAL_RCC_USB_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_USBEN))
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
/* 使能TIM5时钟宏定义 */
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM6时钟宏定义 */
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM7时钟宏定义 */
#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能SPI3时钟宏定义 */
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能UART4时钟宏定义 */
#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能UART5时钟宏定义 */
#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能DAC时钟宏定义 */
#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 关闭TIM5时钟宏定义 */
#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
/* 关闭TIM6时钟宏定义 */
#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
/* 关闭TIM7时钟宏定义 */
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
/* 关闭SPI3时钟宏定义 */
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
/* 关闭UART4时钟宏定义 */
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
/* 关闭UART5时钟宏定义 */
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
/* 关闭DAC时钟宏定义 */
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined  (STM32F100xE)
/* 使能TIM6时钟宏定义 */
#define __HAL_RCC_TIM6_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM6EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM7时钟宏定义 */
#define __HAL_RCC_TIM7_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM7EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能DAC时钟宏定义 */
#define __HAL_RCC_DAC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_DACEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能CEC(消费电子控制)时钟宏定义 */
#define __HAL_RCC_CEC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CECEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 关闭TIM6时钟宏定义 */
#define __HAL_RCC_TIM6_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM6EN))
/* 关闭TIM7时钟宏定义 */
#define __HAL_RCC_TIM7_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM7EN))
/* 关闭DAC时钟宏定义 */
#define __HAL_RCC_DAC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_DACEN))
/* 关闭CEC时钟宏定义 */
#define __HAL_RCC_CEC_CLK_DISABLE()         (RCC->APB1ENR &= ~(RCC_APB1ENR_CECEN))
#endif /* STM32F100xB || STM32F100xE */

#ifdef STM32F100xE
/* 使能TIM5时钟宏定义 */
#define __HAL_RCC_TIM5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM12时钟宏定义 */
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM13时钟宏定义 */
#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM14时钟宏定义 */
#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能SPI3时钟宏定义 */
#define __HAL_RCC_SPI3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能UART4时钟宏定义 */
#define __HAL_RCC_UART4_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能UART5时钟宏定义 */
#define __HAL_RCC_UART5_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 关闭TIM5时钟宏定义 */
#define __HAL_RCC_TIM5_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM5EN))
/* 关闭TIM12时钟宏定义 */
#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
/* 关闭TIM13时钟宏定义 */
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
/* 关闭TIM14时钟宏定义 */
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
/* 关闭SPI3时钟宏定义 */
#define __HAL_RCC_SPI3_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_SPI3EN))
/* 关闭UART4时钟宏定义 */
#define __HAL_RCC_UART4_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART4EN))
/* 关闭UART5时钟宏定义 */
#define __HAL_RCC_UART5_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_UART5EN))
#endif /* STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
/* 使能CAN2时钟宏定义 */
#define __HAL_RCC_CAN2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_CAN2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 关闭CAN2时钟宏定义 */
#define __HAL_RCC_CAN2_CLK_DISABLE()        (RCC->APB1ENR &= ~(RCC_APB1ENR_CAN2EN))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F101xG) || defined(STM32F103xG)
/* 使能TIM12时钟宏定义 */
#define __HAL_RCC_TIM12_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM12EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM13时钟宏定义 */
#define __HAL_RCC_TIM13_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM13EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM14时钟宏定义 */
#define __HAL_RCC_TIM14_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        /* 外设时钟使能后的延时，确保时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM14EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 关闭TIM12时钟宏定义 */
#define __HAL_RCC_TIM12_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM12EN))
/* 关闭TIM13时钟宏定义 */
#define __HAL_RCC_TIM13_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM13EN))
/* 关闭TIM14时钟宏定义 */
#define __HAL_RCC_TIM14_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_TIM14EN))
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_APB1_Peripheral_Clock_Enable_Disable_Status APB1外设时钟使能禁用状态
  * @brief  获取APB1外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */
#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
/* 检查CAN1时钟是否已使能：读取APB1ENR寄存器，判断CAN1EN位是否置1 */
#define __HAL_RCC_CAN1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) != RESET)
/* 检查CAN1时钟是否已禁用：读取APB1ENR寄存器，判断CAN1EN位是否为0 */
#define __HAL_RCC_CAN1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN1EN)) == RESET)
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
/* 检查TIM4时钟是否已使能 */
#define __HAL_RCC_TIM4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) != RESET)
/* 检查TIM4时钟是否已禁用 */
#define __HAL_RCC_TIM4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM4EN)) == RESET)
/* 检查SPI2时钟是否已使能 */
#define __HAL_RCC_SPI2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) != RESET)
/* 检查SPI2时钟是否已禁用 */
#define __HAL_RCC_SPI2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI2EN)) == RESET)
/* 检查USART3时钟是否已使能 */
#define __HAL_RCC_USART3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) != RESET)
/* 检查USART3时钟是否已禁用 */
#define __HAL_RCC_USART3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USART3EN)) == RESET)
/* 检查I2C2时钟是否已使能 */
#define __HAL_RCC_I2C2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) != RESET)
/* 检查I2C2时钟是否已禁用 */
#define __HAL_RCC_I2C2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C2EN)) == RESET)
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
/* 检查USB时钟是否已使能 */
#define __HAL_RCC_USB_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) != RESET)
/* 检查USB时钟是否已禁用 */
#define __HAL_RCC_USB_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_USBEN)) == RESET)
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
/* 检查TIM5时钟是否已使能 */
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
/* 检查TIM5时钟是否已禁用 */
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
/* 检查TIM6时钟是否已使能 */
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
/* 检查TIM6时钟是否已禁用 */
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
/* 检查TIM7时钟是否已使能 */
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
/* 检查TIM7时钟是否已禁用 */
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
/* 检查SPI3时钟是否已使能 */
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
/* 检查SPI3时钟是否已禁用 */
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
/* 检查UART4时钟是否已使能 */
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
/* 检查UART4时钟是否已禁用 */
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
/* 检查UART5时钟是否已使能 */
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
/* 检查UART5时钟是否已禁用 */
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
/* 检查DAC时钟是否已使能 */
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
/* 检查DAC时钟是否已禁用 */
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F100xB) || defined  (STM32F100xE)
/* 检查TIM6时钟是否已使能 */
#define __HAL_RCC_TIM6_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) != RESET)
/* 检查TIM6时钟是否已禁用 */
#define __HAL_RCC_TIM6_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM6EN)) == RESET)
/* 检查TIM7时钟是否已使能 */
#define __HAL_RCC_TIM7_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) != RESET)
/* 检查TIM7时钟是否已禁用 */
#define __HAL_RCC_TIM7_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM7EN)) == RESET)
/* 检查DAC时钟是否已使能 */
#define __HAL_RCC_DAC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) != RESET)
/* 检查DAC时钟是否已禁用 */
#define __HAL_RCC_DAC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_DACEN)) == RESET)
/* 检查CEC时钟是否已使能 */
#define __HAL_RCC_CEC_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) != RESET)
/* 检查CEC时钟是否已禁用 */
#define __HAL_RCC_CEC_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CECEN)) == RESET)
#endif /* STM32F100xB || STM32F100xE */
#ifdef STM32F100xE
/* 检查TIM5时钟是否已使能 */
#define __HAL_RCC_TIM5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) != RESET)
/* 检查TIM5时钟是否已禁用 */
#define __HAL_RCC_TIM5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM5EN)) == RESET)
/* 检查TIM12时钟是否已使能 */
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
/* 检查TIM12时钟是否已禁用 */
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
/* 检查TIM13时钟是否已使能 */
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
/* 检查TIM13时钟是否已禁用 */
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
/* 检查TIM14时钟是否已使能 */
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
/* 检查TIM14时钟是否已禁用 */
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
/* 检查SPI3时钟是否已使能 */
#define __HAL_RCC_SPI3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) != RESET)
/* 检查SPI3时钟是否已禁用 */
#define __HAL_RCC_SPI3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_SPI3EN)) == RESET)
/* 检查UART4时钟是否已使能 */
#define __HAL_RCC_UART4_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) != RESET)
/* 检查UART4时钟是否已禁用 */
#define __HAL_RCC_UART4_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART4EN)) == RESET)
/* 检查UART5时钟是否已使能 */
#define __HAL_RCC_UART5_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) != RESET)
/* 检查UART5时钟是否已禁用 */
#define __HAL_RCC_UART5_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_UART5EN)) == RESET)
/* 检查CAN2时钟是否已使能 */
#define __HAL_RCC_CAN2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) != RESET)
/* 检查CAN2时钟是否已禁用 */
#define __HAL_RCC_CAN2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_CAN2EN)) == RESET)
#endif /* STM32F100xE */
#if defined(STM32F105xC) || defined(STM32F107xC)
/* 检查TIM12时钟是否已使能 */
#define __HAL_RCC_TIM12_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) != RESET)
/* 检查TIM12时钟是否已禁用 */
#define __HAL_RCC_TIM12_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM12EN)) == RESET)
#endif /* STM32F105xC || STM32F107xC */
#if defined(STM32F101xG) || defined(STM32F103xG)
/* 检查TIM13时钟是否已使能 */
#define __HAL_RCC_TIM13_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) != RESET)
/* 检查TIM13时钟是否已禁用 */
#define __HAL_RCC_TIM13_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM13EN)) == RESET)
/* 检查TIM14时钟是否已使能 */
#define __HAL_RCC_TIM14_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) != RESET)
/* 检查TIM14时钟是否已禁用 */
#define __HAL_RCC_TIM14_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM14EN)) == RESET)
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Clock_Enable_Disable APB2外设时钟使能/禁用
  * @brief  使能或禁用高速APB (APB2)外设时钟。
  * @note   复位后，外设时钟（用于寄存器读写访问）是禁用的，
  *         应用程序在使用外设前必须先使能该时钟。
  * @{
  */

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
/* 使能ADC2时钟宏定义
   采用do...while(0)结构确保宏定义在使用时语法安全
   步骤：
   1. 定义临时变量tmpreg
   2. 设置APB2ENR寄存器中的ADC2EN位为1，开启时钟
   3. 读取该位回写到tmpreg，确保设置生效（硬件延迟要求）
*/
#define __HAL_RCC_ADC2_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        /* RCC外设时钟使能后的延迟，等待时钟稳定 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC2EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用ADC2时钟：清除APB2ENR寄存器中的ADC2EN位 */
#define __HAL_RCC_ADC2_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC2EN))
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */

#if defined(STM32F100xB) || defined(STM32F100xE)
/* 使能TIM15时钟 */
#define __HAL_RCC_TIM15_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM16时钟 */
#define __HAL_RCC_TIM16_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM17时钟 */
#define __HAL_RCC_TIM17_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用TIM15时钟 */
#define __HAL_RCC_TIM15_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM15EN))
/* 禁用TIM16时钟 */
#define __HAL_RCC_TIM16_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM16EN))
/* 禁用TIM17时钟 */
#define __HAL_RCC_TIM17_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM17EN))
#endif /* STM32F100xB || STM32F100xE */

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
/* 使能GPIOE时钟 */
#define __HAL_RCC_GPIOE_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPEEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用GPIOE时钟 */
#define __HAL_RCC_GPIOE_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPEEN))
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
/* 使能GPIOF时钟 */
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOG时钟 */
#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用GPIOF时钟 */
#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
/* 禁用GPIOG时钟 */
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/

#if defined(STM32F103xE) || defined(STM32F103xG)
/* 使能TIM8时钟 */
#define __HAL_RCC_TIM8_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能ADC3时钟 */
#define __HAL_RCC_ADC3_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC3EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用TIM8时钟 */
#define __HAL_RCC_TIM8_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM8EN))
/* 禁用ADC3时钟 */
#define __HAL_RCC_ADC3_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC3EN))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F100xE)
/* 使能GPIOF时钟 */
#define __HAL_RCC_GPIOF_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPFEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOG时钟 */
#define __HAL_RCC_GPIOG_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPGEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用GPIOF时钟 */
#define __HAL_RCC_GPIOF_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPFEN))
/* 禁用GPIOG时钟 */
#define __HAL_RCC_GPIOG_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPGEN))
#endif /* STM32F100xE */

#if defined(STM32F101xG) || defined(STM32F103xG)
/* 使能TIM9时钟 */
#define __HAL_RCC_TIM9_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM9EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM10时钟 */
#define __HAL_RCC_TIM10_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM10EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM11时钟 */
#define __HAL_RCC_TIM11_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        /* RCC外设时钟使能后的延迟 */ \
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM11EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用TIM9时钟 */
#define __HAL_RCC_TIM9_CLK_DISABLE()        (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM9EN))
/* 禁用TIM10时钟 */
#define __HAL_RCC_TIM10_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM10EN))
/* 禁用TIM11时钟 */
#define __HAL_RCC_TIM11_CLK_DISABLE()       (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM11EN))
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Peripheral_Clock_Enable_Disable_Status APB2外设时钟使能禁用状态
  * @brief  获取APB2外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟（用于寄存器读写访问）是禁用的，
  *         应用程序在使用外设前必须先使能该时钟。
  * @{
  */
#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
// 检查ADC2时钟是否使能：读取APB2ENR寄存器，判断ADC2EN位是否置1
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
// 检查ADC2时钟是否禁用：读取APB2ENR寄存器，判断ADC2EN位是否清零
#define __HAL_RCC_ADC2_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) == RESET)
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */
#if defined(STM32F100xB) || defined(STM32F100xE)
// 检查TIM15时钟是否使能
#define __HAL_RCC_TIM15_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) != RESET)
// 检查TIM15时钟是否禁用
#define __HAL_RCC_TIM15_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) == RESET)
// 检查TIM16时钟是否使能
#define __HAL_RCC_TIM16_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) != RESET)
// 检查TIM16时钟是否禁用
#define __HAL_RCC_TIM16_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) == RESET)
// 检查TIM17时钟是否使能
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) != RESET)
// 检查TIM17时钟是否禁用
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) == RESET)
#endif /* STM32F100xB || STM32F100xE */
#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
// 检查GPIOE时钟是否使能
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) != RESET)
// 检查GPIOE时钟是否禁用
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) == RESET)
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
// 检查GPIOF时钟是否使能
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
// 检查GPIOF时钟是否禁用
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
// 检查GPIOG时钟是否使能
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
// 检查GPIOG时钟是否禁用
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/
#if defined(STM32F103xE) || defined(STM32F103xG)
// 检查TIM8时钟是否使能
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)
// 检查TIM8时钟是否禁用
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
// 检查ADC3时钟是否使能
#define __HAL_RCC_ADC3_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) != RESET)
// 检查ADC3时钟是否禁用
#define __HAL_RCC_ADC3_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) == RESET)
#endif /* STM32F103xE || STM32F103xG */
#if defined(STM32F100xE)
// 检查GPIOF时钟是否使能
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
// 检查GPIOF时钟是否禁用
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
// 检查GPIOG时钟是否使能
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
// 检查GPIOG时钟是否禁用
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif /* STM32F100xE */
#if defined(STM32F101xG) || defined(STM32F103xG)
// 检查TIM9时钟是否使能
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
// 检查TIM9时钟是否禁用
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
// 检查TIM10时钟是否使能
#define __HAL_RCC_TIM10_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) != RESET)
// 检查TIM10时钟是否禁用
#define __HAL_RCC_TIM10_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) == RESET)
// 检查TIM11时钟是否使能
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)
// 检查TIM11时钟是否禁用
#define __HAL_RCC_TIM11_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) == RESET)
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Peripheral_Clock_Force_Release Peripheral Clock Force Release
  * @brief  强制或释放AHB外设复位。
  * @{
  */
// 强制复位所有AHB外设：向AHBRSTR寄存器写入全1
#define __HAL_RCC_AHB_FORCE_RESET()         (RCC->AHBRSTR = 0xFFFFFFFFU)
// 强制复位USB OTG FS：置位AHBRSTR寄存器中的OTGFSRST位
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()       (RCC->AHBRSTR |= (RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
// 强制复位以太网MAC：置位AHBRSTR寄存器中的ETHMACRST位
#define __HAL_RCC_ETHMAC_FORCE_RESET()      (RCC->AHBRSTR |= (RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

// 释放所有AHB外设复位：向AHBRSTR寄存器写入0
#define __HAL_RCC_AHB_RELEASE_RESET()       (RCC->AHBRSTR = 0x00)
// 释放USB OTG FS复位：清除AHBRSTR寄存器中的OTGFSRST位
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()     (RCC->AHBRSTR &= ~(RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
// 释放以太网MAC复位：清除AHBRSTR寄存器中的ETHMACRST位
#define __HAL_RCC_ETHMAC_RELEASE_RESET()    (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  强制或释放APB1外设复位。
  * @{
  */

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
// 强制复位CAN1：置位APB1RSTR寄存器中的CAN1RST位
#define __HAL_RCC_CAN1_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN1RST))

// 释放CAN1复位：清除APB1RSTR寄存器中的CAN1RST位
#define __HAL_RCC_CAN1_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN1RST))
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
// 强制复位TIM4
#define __HAL_RCC_TIM4_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
// 强制复位SPI2
#define __HAL_RCC_SPI2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
// 强制复位USART3
#define __HAL_RCC_USART3_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_USART3RST))
// 强制复位I2C2
#define __HAL_RCC_I2C2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))

// 释放TIM4复位
#define __HAL_RCC_TIM4_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
// 释放SPI2复位
#define __HAL_RCC_SPI2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
// 释放USART3复位
#define __HAL_RCC_USART3_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST))
// 释放I2C2复位
#define __HAL_RCC_I2C2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
// 强制复位USB
#define __HAL_RCC_USB_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_USBRST))
// 释放USB复位
#define __HAL_RCC_USB_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USBRST))
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
// 强制复位TIM5
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
// 强制复位TIM6
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
// 强制复位TIM7
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
// 强制复位SPI3
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
// 强制复位UART4
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
// 强制复位UART5
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))
// 强制复位DAC
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))

// 释放TIM5复位
#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
// 释放TIM6复位
#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
// 释放TIM7复位
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
// 释放SPI3复位
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
// 释放UART4复位
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
// 释放UART5复位
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
// 释放DAC复位
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined  (STM32F100xE)
// 强制复位TIM6
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
// 强制复位TIM7
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
// 强制复位DAC
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))
// 强制复位CEC
#define __HAL_RCC_CEC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_CECRST))

// 释放TIM6复位
#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
// 释放TIM7复位
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
// 释放DAC复位
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
// 释放CEC复位
#define __HAL_RCC_CEC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CECRST))
#endif /* STM32F100xB || STM32F100xE */

#if defined  (STM32F100xE)
// 强制复位TIM5
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
// 强制复位TIM12
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
// 强制复位TIM13
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
// 强制复位TIM14
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))
// 强制复位SPI3
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
// 强制复位UART4
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
// 强制复位UART5
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))

// 释放TIM5复位
#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
// 释放TIM12复位
#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
// 释放TIM13复位
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
// 释放TIM14复位
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
// 释放SPI3复位
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
// 释放UART4复位
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
// 释放UART5复位
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#endif /* STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
// 强制复位CAN2
#define __HAL_RCC_CAN2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN2RST))

// 释放CAN2复位
#define __HAL_RCC_CAN2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN2RST))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F101xG) || defined(STM32F103xG)
// 强制复位TIM12
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
// 强制复位TIM13
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
// 强制复位TIM14
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))

// 释放TIM12复位
#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
// 释放TIM13复位
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
// 释放TIM14复位
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  强制或释放APB2外设复位。
  * @{
  */

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
// 强制复位ADC2
#define __HAL_RCC_ADC2_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC2RST))

// 释放ADC2复位
#define __HAL_RCC_ADC2_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC2RST))
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */

#if defined(STM32F100xB) || defined(STM32F100xE)
// 强制复位TIM15
#define __HAL_RCC_TIM15_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM15RST))
// 强制复位TIM16
#define __HAL_RCC_TIM16_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM16RST))
// 强制复位TIM17
#define __HAL_RCC_TIM17_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM17RST))

// 释放TIM15复位
#define __HAL_RCC_TIM15_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST))
// 释放TIM16复位
#define __HAL_RCC_TIM16_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM16RST))
// 释放TIM17复位
#define __HAL_RCC_TIM17_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM17RST))
#endif /* STM32F100xB || STM32F100xE */

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
// 强制复位GPIOE
#define __HAL_RCC_GPIOE_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPERST))

// 释放GPIOE复位
#define __HAL_RCC_GPIOE_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPERST))
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
// 强制复位GPIOF
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
// 强制复位GPIOG
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

// 释放GPIOF复位
#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
// 释放GPIOG复位
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/

#if defined(STM32F103xE) || defined(STM32F103xG)
// 强制复位TIM8
#define __HAL_RCC_TIM8_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))
// 强制复位ADC3
#define __HAL_RCC_ADC3_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC3RST))

// 释放TIM8复位
#define __HAL_RCC_TIM8_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
// 释放ADC3复位
#define __HAL_RCC_ADC3_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC3RST))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F100xE)
// 强制复位GPIOF
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
// 强制复位GPIOG
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

// 释放GPIOF复位
#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
// 释放GPIOG复位
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif /* STM32F100xE */

#if defined(STM32F101xG) || defined(STM32F103xG)
// 强制复位TIM9
#define __HAL_RCC_TIM9_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
// 强制复位TIM10
#define __HAL_RCC_TIM10_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM10RST))
// 强制复位TIM11
#define __HAL_RCC_TIM11_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))

// 释放TIM9复位
#define __HAL_RCC_TIM9_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
// 释放TIM10复位
#define __HAL_RCC_TIM10_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM10RST))
// 释放TIM11复位
#define __HAL_RCC_TIM11_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM11RST))
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_HSE_Configuration HSE Configuration
  * @{
  */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/**
  * @brief  配置外部高速振荡器(HSE)的PLL预分频因子。
  * @note   如果PLL用作系统时钟，则不能更改预分频因子
  *         在这种情况下，必须选择另一个系统时钟源，禁用PLL，然后更改HSE预分频因子。
  * @param  __HSE_PREDIV_VALUE__ 指定应用于HSE的分频值。
  *         该参数必须是RCC_HSE_PREDIV_DIV1和RCC_HSE_PREDIV_DIV16之间的数值。
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV1, (uint32_t)(__HSE_PREDIV_VALUE__))
#else
/**
  * @brief  配置外部高速振荡器(HSE)的PLL预分频因子。
  * @note   如果PLL用作系统时钟，则不能更改预分频因子
  *         在这种情况下，必须选择另一个系统时钟源，禁用PLL，然后更改HSE预分频因子。
  * @param  __HSE_PREDIV_VALUE__ 指定应用于HSE的分频值。
  *         该参数必须是RCC_HSE_PREDIV_DIV1和RCC_HSE_PREDIV_DIV2之间的数值。
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR,RCC_CFGR_PLLXTPRE, (uint32_t)(__HSE_PREDIV_VALUE__))

#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/**
  * @brief  获取PLL的prediv1因子。
  */
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1)

#else
/**
  * @brief  获取PLL的prediv1因子。
  */
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR, RCC_CFGR_PLLXTPRE)

#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_PLLI2S_Configuration PLLI2S Configuration
  * @{
  */

/** @brief 使能主PLLI2S的宏。
  * @note   使能主PLLI2S后，应用程序软件应等待PLLI2SRDY标志置位，
  *         这表示PLLI2S时钟已稳定，可用作系统时钟源。
  * @note   进入停止和待机模式时，硬件会禁用主PLLI2S。
  */
#define __HAL_RCC_PLLI2S_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = ENABLE)

/** @brief 禁用主PLLI2S的宏。
  * @note   进入停止和待机模式时，硬件会禁用主PLLI2S。
  */
#define __HAL_RCC_PLLI2S_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = DISABLE)

/** @brief 配置主PLLI2S倍频因子的宏。
  * @note   此功能只能在主PLLI2S禁用时使用。
  *
  * @param  __PLLI2SMUL__ 指定PLLI2S VCO输出时钟的倍频因子
  *          该参数可以是以下值之一：
  *             @arg @ref RCC_PLLI2S_MUL8 PLLI2SVCO = PLLI2S时钟输入 x 8
  *             @arg @ref RCC_PLLI2S_MUL9 PLLI2SVCO = PLLI2S时钟输入 x 9
  *             @arg @ref RCC_PLLI2S_MUL10 PLLI2SVCO = PLLI2S时钟输入 x 10
  *             @arg @ref RCC_PLLI2S_MUL11 PLLI2SVCO = PLLI2S时钟输入 x 11
  *             @arg @ref RCC_PLLI2S_MUL12 PLLI2SVCO = PLLI2S时钟输入 x 12
  *             @arg @ref RCC_PLLI2S_MUL13 PLLI2SVCO = PLLI2S时钟输入 x 13
  *             @arg @ref RCC_PLLI2S_MUL14 PLLI2SVCO = PLLI2S时钟输入 x 14
  *             @arg @ref RCC_PLLI2S_MUL16 PLLI2SVCO = PLLI2S时钟输入 x 16
  *             @arg @ref RCC_PLLI2S_MUL20 PLLI2SVCO = PLLI2S时钟输入 x 20
  *
  */
#define __HAL_RCC_PLLI2S_CONFIG(__PLLI2SMUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL3MUL,(__PLLI2SMUL__))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_Peripheral_Configuration Peripheral Configuration
  * @brief  配置不同外设时钟源的宏。
  * @{
  */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
/** @brief  配置USB时钟的宏。
  * @param  __USBCLKSOURCE__ 指定USB时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL时钟1分频作为USB时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL时钟1.5分频作为USB时钟
  */
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  获取USB时钟(USBCLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL时钟1分频作为USB时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL时钟1.5分频作为USB时钟
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @brief  配置USB OTG时钟的宏。
  * @param  __USBCLKSOURCE__ 指定USB时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL时钟2分频作为USB OTG FS时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL时钟3分频作为USB OTG FS时钟
  */
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_OTGFSPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  获取USB时钟(USBCLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL时钟2分频作为USB OTG FS时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL时钟3分频作为USB OTG FS时钟
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_OTGFSPRE)))

#endif /* STM32F105xC || STM32F107xC */

/** @brief  配置ADCx时钟的宏(x=1到3，取决于设备)。
  * @param  __ADCCLKSOURCE__ 指定ADC时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2时钟2分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2时钟4分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2时钟6分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2时钟8分频作为ADC时钟
  */
#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

/** @brief  获取ADC时钟(ADCxCLK, x=1到3，取决于设备)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2时钟2分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2时钟4分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2时钟6分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2时钟8分频作为ADC时钟
  */
#define __HAL_RCC_GET_ADC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE)))

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @addtogroup RCCEx_HSE_Configuration
  * @{
  */

/**
  * @brief  配置PLL2和PLLI2S预分频因子的宏。
  * @note   如果PLL2被间接用作系统时钟，则无法更改预分频因子
  *         在这种情况下，必须选择另一个系统时钟源，禁用PLL2和PLLI2S，然后更改PREDIV2因子。
  * @param  __HSE_PREDIV2_VALUE__ 指定应用于PLL2和PLLI2S的PREDIV2值。
  *         该参数必须是RCC_HSE_PREDIV2_DIV1和RCC_HSE_PREDIV2_DIV16之间的数值。
  */
#define __HAL_RCC_HSE_PREDIV2_CONFIG(__HSE_PREDIV2_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV2, (uint32_t)(__HSE_PREDIV2_VALUE__))

/**
  * @brief  获取PLL2和PLL3的prediv2因子的宏。
  */
#define __HAL_RCC_HSE_GET_PREDIV2() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV2)

/**
  * @}
  */

/** @addtogroup RCCEx_PLLI2S_Configuration
  * @{
  */

/** @brief 使能主PLL2的宏。
  * @note   使能主PLL2后，应用程序软件应等待PLL2RDY标志置位，
  *         这表示PLL2时钟已稳定，可用作系统时钟源。
  * @note   进入停止和待机模式时，硬件会禁用主PLL2。
  */
#define __HAL_RCC_PLL2_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = ENABLE)

/** @brief 禁用主PLL2的宏。
  * @note   如果PLL2被间接用作系统时钟源，则不能禁用主PLL2
  * @note   进入停止和待机模式时，硬件会禁用主PLL2。
  */
#define __HAL_RCC_PLL2_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = DISABLE)

/** @brief 配置主PLL2倍频因子的宏。
  * @note   此功能只能在主PLL2禁用时使用。
  *
  * @param  __PLL2MUL__ 指定PLL2 VCO输出时钟的倍频因子
  *          该参数可以是以下值之一：
  *             @arg @ref RCC_PLL2_MUL8 PLL2VCO = PLL2时钟输入 x 8
  *             @arg @ref RCC_PLL2_MUL9 PLL2VCO = PLL2时钟输入 x 9
  *             @arg @ref RCC_PLL2_MUL10 PLL2VCO = PLL2时钟输入 x 10
  *             @arg @ref RCC_PLL2_MUL11 PLL2VCO = PLL2时钟输入 x 11
  *             @arg @ref RCC_PLL2_MUL12 PLL2VCO = PLL2时钟输入 x 12
  *             @arg @ref RCC_PLL2_MUL13 PLL2VCO = PLL2时钟输入 x 13
  *             @arg @ref RCC_PLL2_MUL14 PLL2VCO = PLL2时钟输入 x 14
  *             @arg @ref RCC_PLL2_MUL16 PLL2VCO = PLL2时钟输入 x 16
  *             @arg @ref RCC_PLL2_MUL20 PLL2VCO = PLL2时钟输入 x 20
  *
  */
#define __HAL_RCC_PLL2_CONFIG(__PLL2MUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL2MUL,(__PLL2MUL__))

/**
  * @}
  */

/** @defgroup RCCEx_I2S_Configuration I2S Configuration
  * @brief  配置I2S外设时钟源的宏。
  * @{
  */

/** @brief  配置I2S2时钟的宏。
  * @param  __I2S2CLKSOURCE__ 指定I2S2时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_I2S2_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S2SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  获取I2S2时钟(I2S2CLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_GET_I2S2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S2SRC)))

/** @brief  配置I2S3时钟的宏。
  * @param  __I2S2CLKSOURCE__ 指定I2S3时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_I2S3_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S3SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  获取I2S3时钟(I2S3CLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_GET_I2S3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S3SRC)))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

// 初始化外设时钟
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
// 获取外设时钟配置
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
// 获取外设时钟频率
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @addtogroup RCCEx_Exported_Functions_Group2
  * @{
  */
// 使能PLLI2S
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
// 禁用PLLI2S
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);

/**
  * @}
  */

/** @addtogroup RCCEx_Exported_Functions_Group3
  * @{
  */
// 使能PLL2
HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(RCC_PLL2InitTypeDef  *PLL2Init);
// 禁用PLL2
HAL_StatusTypeDef HAL_RCCEx_DisablePLL2(void);

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

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

#endif /* __STM32F1xx_HAL_RCC_EX_H */
