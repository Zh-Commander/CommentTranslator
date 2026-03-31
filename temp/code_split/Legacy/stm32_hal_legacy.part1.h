/**
  ******************************************************************************
  * @file    stm32_hal_legacy.h
  * @author  MCD Application Team
  * @brief   This file contains aliases definition for the STM32Cube HAL constants
  *          macros and functions maintained for legacy purpose.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32_HAL_LEGACY
#define STM32_HAL_LEGACY

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Defines HAL CRYP Aliased Defines maintained for legacy purpose
  * @{
  */
#define AES_FLAG_RDERR                  CRYP_FLAG_RDERR
#define AES_FLAG_WRERR                  CRYP_FLAG_WRERR
#define AES_CLEARFLAG_CCF               CRYP_CLEARFLAG_CCF
#define AES_CLEARFLAG_RDERR             CRYP_CLEARFLAG_RDERR
#define AES_CLEARFLAG_WRERR             CRYP_CLEARFLAG_WRERR
#if defined(STM32H7) || defined(STM32MP1)
#define CRYP_DATATYPE_32B               CRYP_NO_SWAP
#define CRYP_DATATYPE_16B               CRYP_HALFWORD_SWAP
#define CRYP_DATATYPE_8B                CRYP_BYTE_SWAP
#define CRYP_DATATYPE_1B                CRYP_BIT_SWAP
#endif /* STM32H7 || STM32MP1 */
/**
  * @}
  */

/** @defgroup HAL_ADC_Aliased_Defines HAL ADC Aliased Defines maintained for legacy purpose
  * @{
  */
#define ADC_RESOLUTION12b               ADC_RESOLUTION_12B
#define ADC_RESOLUTION10b               ADC_RESOLUTION_10B
#define ADC_RESOLUTION8b                ADC_RESOLUTION_8B
#define ADC_RESOLUTION6b                ADC_RESOLUTION_6B
#define OVR_DATA_OVERWRITTEN            ADC_OVR_DATA_OVERWRITTEN
#define OVR_DATA_PRESERVED              ADC_OVR_DATA_PRESERVED
#define EOC_SINGLE_CONV                 ADC_EOC_SINGLE_CONV
#define EOC_SEQ_CONV                    ADC_EOC_SEQ_CONV
#define EOC_SINGLE_SEQ_CONV             ADC_EOC_SINGLE_SEQ_CONV
#define REGULAR_GROUP                   ADC_REGULAR_GROUP
#define INJECTED_GROUP                  ADC_INJECTED_GROUP
#define REGULAR_INJECTED_GROUP          ADC_REGULAR_INJECTED_GROUP
#define AWD_EVENT                       ADC_AWD_EVENT
#define AWD1_EVENT                      ADC_AWD1_EVENT
#define AWD2_EVENT                      ADC_AWD2_EVENT
#define AWD3_EVENT                      ADC_AWD3_EVENT
#define OVR_EVENT                       ADC_OVR_EVENT
#define JQOVF_EVENT                     ADC_JQOVF_EVENT
#define ALL_CHANNELS                    ADC_ALL_CHANNELS
#define REGULAR_CHANNELS                ADC_REGULAR_CHANNELS
#define INJECTED_CHANNELS               ADC_INJECTED_CHANNELS
#define SYSCFG_FLAG_SENSOR_ADC          ADC_FLAG_SENSOR
#define SYSCFG_FLAG_VREF_ADC            ADC_FLAG_VREFINT
#define ADC_CLOCKPRESCALER_PCLK_DIV1    ADC_CLOCK_SYNC_PCLK_DIV1
#define ADC_CLOCKPRESCALER_PCLK_DIV2    ADC_CLOCK_SYNC_PCLK_DIV2
#define ADC_CLOCKPRESCALER_PCLK_DIV4    ADC_CLOCK_SYNC_PCLK_DIV4
#define ADC_CLOCKPRESCALER_PCLK_DIV6    ADC_CLOCK_SYNC_PCLK_DIV6
#define ADC_CLOCKPRESCALER_PCLK_DIV8    ADC_CLOCK_SYNC_PCLK_DIV8
#define ADC_EXTERNALTRIG0_T6_TRGO       ADC_EXTERNALTRIGCONV_T6_TRGO
#define ADC_EXTERNALTRIG1_T21_CC2       ADC_EXTERNALTRIGCONV_T21_CC2
#define ADC_EXTERNALTRIG2_T2_TRGO       ADC_EXTERNALTRIGCONV_T2_TRGO
#define ADC_EXTERNALTRIG3_T2_CC4        ADC_EXTERNALTRIGCONV_T2_CC4
#define ADC_EXTERNALTRIG4_T22_TRGO      ADC_EXTERNALTRIGCONV_T22_TRGO
#define ADC_EXTERNALTRIG7_EXT_IT11      ADC_EXTERNALTRIGCONV_EXT_IT11
#define ADC_CLOCK_ASYNC                 ADC_CLOCK_ASYNC_DIV1
#define ADC_EXTERNALTRIG_EDGE_NONE      ADC_EXTERNALTRIGCONVEDGE_NONE
#define ADC_EXTERNALTRIG_EDGE_RISING    ADC_EXTERNALTRIGCONVEDGE_RISING
#define ADC_EXTERNALTRIG_EDGE_FALLING   ADC_EXTERNALTRIGCONVEDGE_FALLING
#define ADC_EXTERNALTRIG_EDGE_RISINGFALLING ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING
#define ADC_SAMPLETIME_2CYCLE_5         ADC_SAMPLETIME_2CYCLES_5

#define HAL_ADC_STATE_BUSY_REG          HAL_ADC_STATE_REG_BUSY
#define HAL_ADC_STATE_BUSY_INJ          HAL_ADC_STATE_INJ_BUSY
#define HAL_ADC_STATE_EOC_REG           HAL_ADC_STATE_REG_EOC
#define HAL_ADC_STATE_EOC_INJ           HAL_ADC_STATE_INJ_EOC
#define HAL_ADC_STATE_ERROR             HAL_ADC_STATE_ERROR_INTERNAL
#define HAL_ADC_STATE_BUSY              HAL_ADC_STATE_BUSY_INTERNAL
#define HAL_ADC_STATE_AWD               HAL_ADC_STATE_AWD1

#if defined(STM32H7)
#define ADC_CHANNEL_VBAT_DIV4           ADC_CHANNEL_VBAT
#endif /* STM32H7 */

#if defined(STM32U5)
#define ADC_SAMPLETIME_5CYCLE           ADC_SAMPLETIME_5CYCLES
#define ADC_SAMPLETIME_391CYCLES_5      ADC_SAMPLETIME_391CYCLES
#define ADC4_SAMPLETIME_160CYCLES_5     ADC4_SAMPLETIME_814CYCLES_5
#endif /* STM32U5 */

#if defined(STM32H5)
#define ADC_CHANNEL_VCORE               ADC_CHANNEL_VDDCORE
#endif /* STM32H5 */
/**
  * @}
  */

/** @defgroup HAL_CEC_Aliased_Defines HAL CEC Aliased Defines maintained for legacy purpose
  * @{
  */

#define __HAL_CEC_GET_IT __HAL_CEC_GET_FLAG

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Defines HAL COMP Aliased Defines maintained for legacy purpose
  * @{
  */
#define COMP_WINDOWMODE_DISABLED       COMP_WINDOWMODE_DISABLE
#define COMP_WINDOWMODE_ENABLED        COMP_WINDOWMODE_ENABLE
#define COMP_EXTI_LINE_COMP1_EVENT     COMP_EXTI_LINE_COMP1
#define COMP_EXTI_LINE_COMP2_EVENT     COMP_EXTI_LINE_COMP2
#define COMP_EXTI_LINE_COMP3_EVENT     COMP_EXTI_LINE_COMP3
#define COMP_EXTI_LINE_COMP4_EVENT     COMP_EXTI_LINE_COMP4
#define COMP_EXTI_LINE_COMP5_EVENT     COMP_EXTI_LINE_COMP5
#define COMP_EXTI_LINE_COMP6_EVENT     COMP_EXTI_LINE_COMP6
#define COMP_EXTI_LINE_COMP7_EVENT     COMP_EXTI_LINE_COMP7
#if defined(STM32L0)
#define COMP_LPTIMCONNECTION_ENABLED   ((uint32_t)0x00000003U)    /*!< COMPX output generic naming: connected to LPTIM 
                                                                       input 1 for COMP1, LPTIM input 2 for COMP2 */
#endif
#define COMP_OUTPUT_COMP6TIM2OCREFCLR  COMP_OUTPUT_COMP6_TIM2OCREFCLR
#if defined(STM32F373xC) || defined(STM32F378xx)
#define COMP_OUTPUT_TIM3IC1            COMP_OUTPUT_COMP1_TIM3IC1
#define COMP_OUTPUT_TIM3OCREFCLR       COMP_OUTPUT_COMP1_TIM3OCREFCLR
#endif /* STM32F373xC || STM32F378xx */

#if defined(STM32L0) || defined(STM32L4)
#define COMP_WINDOWMODE_ENABLE         COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON

#define COMP_NONINVERTINGINPUT_IO1      COMP_INPUT_PLUS_IO1
#define COMP_NONINVERTINGINPUT_IO2      COMP_INPUT_PLUS_IO2
#define COMP_NONINVERTINGINPUT_IO3      COMP_INPUT_PLUS_IO3
#define COMP_NONINVERTINGINPUT_IO4      COMP_INPUT_PLUS_IO4
#define COMP_NONINVERTINGINPUT_IO5      COMP_INPUT_PLUS_IO5
#define COMP_NONINVERTINGINPUT_IO6      COMP_INPUT_PLUS_IO6

#define COMP_INVERTINGINPUT_1_4VREFINT  COMP_INPUT_MINUS_1_4VREFINT
#define COMP_INVERTINGINPUT_1_2VREFINT  COMP_INPUT_MINUS_1_2VREFINT
#define COMP_INVERTINGINPUT_3_4VREFINT  COMP_INPUT_MINUS_3_4VREFINT
#define COMP_INVERTINGINPUT_VREFINT     COMP_INPUT_MINUS_VREFINT
#define COMP_INVERTINGINPUT_DAC1_CH1    COMP_INPUT_MINUS_DAC1_CH1
#define COMP_INVERTINGINPUT_DAC1_CH2    COMP_INPUT_MINUS_DAC1_CH2
#define COMP_INVERTINGINPUT_DAC1        COMP_INPUT_MINUS_DAC1_CH1
#define COMP_INVERTINGINPUT_DAC2        COMP_INPUT_MINUS_DAC1_CH2
#define COMP_INVERTINGINPUT_IO1         COMP_INPUT_MINUS_IO1
#if defined(STM32L0)
/* Issue fixed on STM32L0 COMP driver: only 2 dedicated IO (IO1 and IO2),     */
/* IO2 was wrongly assigned to IO shared with DAC and IO3 was corresponding   */
/* to the second dedicated IO (only for COMP2).                               */
#define COMP_INVERTINGINPUT_IO2         COMP_INPUT_MINUS_DAC1_CH2
#define COMP_INVERTINGINPUT_IO3         COMP_INPUT_MINUS_IO2
#else
#define COMP_INVERTINGINPUT_IO2         COMP_INPUT_MINUS_IO2
#define COMP_INVERTINGINPUT_IO3         COMP_INPUT_MINUS_IO3
#endif
#define COMP_INVERTINGINPUT_IO4         COMP_INPUT_MINUS_IO4
#define COMP_INVERTINGINPUT_IO5         COMP_INPUT_MINUS_IO5

#define COMP_OUTPUTLEVEL_LOW            COMP_OUTPUT_LEVEL_LOW
#define COMP_OUTPUTLEVEL_HIGH           COMP_OUTPUT_LEVEL_HIGH

/* Note: Literal "COMP_FLAG_LOCK" kept for legacy purpose.                    */
/*       To check COMP lock state, use macro "__HAL_COMP_IS_LOCKED()".        */
#if defined(COMP_CSR_LOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_LOCK
#elif defined(COMP_CSR_COMP1LOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_COMP1LOCK
#elif defined(COMP_CSR_COMPxLOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_COMPxLOCK
#endif

#if defined(STM32L4)
#define COMP_BLANKINGSRCE_TIM1OC5        COMP_BLANKINGSRC_TIM1_OC5_COMP1
#define COMP_BLANKINGSRCE_TIM2OC3        COMP_BLANKINGSRC_TIM2_OC3_COMP1
#define COMP_BLANKINGSRCE_TIM3OC3        COMP_BLANKINGSRC_TIM3_OC3_COMP1
#define COMP_BLANKINGSRCE_TIM3OC4        COMP_BLANKINGSRC_TIM3_OC4_COMP2
#define COMP_BLANKINGSRCE_TIM8OC5        COMP_BLANKINGSRC_TIM8_OC5_COMP2
#define COMP_BLANKINGSRCE_TIM15OC1       COMP_BLANKINGSRC_TIM15_OC1_COMP2
#define COMP_BLANKINGSRCE_NONE           COMP_BLANKINGSRC_NONE
#endif

