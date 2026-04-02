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
