/**
  ******************************************************************************
  * @file    stm32f1xx_ll_adc.h
  * @author  MCD Application Team
  * @brief   Header file of ADC LL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_LL_ADC_H
#define __STM32F1xx_LL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined (ADC1) || defined (ADC2) || defined (ADC3)

/** @defgroup ADC_LL ADC
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private constants ---------------------------------------------------------*/
/** @defgroup ADC_LL_Private_Constants ADC Private Constants
  * @{
  */

/* Internal mask for ADC group regular sequencer:                             */
/* To select into literal LL_ADC_REG_RANK_x the relevant bits for:            */
/* - sequencer register offset                                                */
/* - sequencer rank bits position into the selected register                  */

/* Internal register offset for ADC group regular sequencer configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC_SQR1_REGOFFSET                 0x00000000U
#define ADC_SQR2_REGOFFSET                 0x00000100U
#define ADC_SQR3_REGOFFSET                 0x00000200U
#define ADC_SQR4_REGOFFSET                 0x00000300U

#define ADC_REG_SQRX_REGOFFSET_MASK        (ADC_SQR1_REGOFFSET | ADC_SQR2_REGOFFSET | ADC_SQR3_REGOFFSET | ADC_SQR4_REGOFFSET)
#define ADC_REG_RANK_ID_SQRX_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0)

/* Definition of ADC group regular sequencer bits information to be inserted  */
/* into ADC group regular sequencer ranks literals definition.                */
#define ADC_REG_RANK_1_SQRX_BITOFFSET_POS  ( 0U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ1) */
#define ADC_REG_RANK_2_SQRX_BITOFFSET_POS  ( 5U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ2) */
#define ADC_REG_RANK_3_SQRX_BITOFFSET_POS  (10U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ3) */
#define ADC_REG_RANK_4_SQRX_BITOFFSET_POS  (15U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ4) */
#define ADC_REG_RANK_5_SQRX_BITOFFSET_POS  (20U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ5) */
#define ADC_REG_RANK_6_SQRX_BITOFFSET_POS  (25U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ6) */
#define ADC_REG_RANK_7_SQRX_BITOFFSET_POS  ( 0U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ7) */
#define ADC_REG_RANK_8_SQRX_BITOFFSET_POS  ( 5U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ8) */
#define ADC_REG_RANK_9_SQRX_BITOFFSET_POS  (10U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ9) */
#define ADC_REG_RANK_10_SQRX_BITOFFSET_POS (15U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ10) */
#define ADC_REG_RANK_11_SQRX_BITOFFSET_POS (20U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ11) */
#define ADC_REG_RANK_12_SQRX_BITOFFSET_POS (25U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ12) */
#define ADC_REG_RANK_13_SQRX_BITOFFSET_POS ( 0U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ13) */
#define ADC_REG_RANK_14_SQRX_BITOFFSET_POS ( 5U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ14) */
#define ADC_REG_RANK_15_SQRX_BITOFFSET_POS (10U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ15) */
#define ADC_REG_RANK_16_SQRX_BITOFFSET_POS (15U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ16) */

/* Internal mask for ADC group injected sequencer:                            */
/* To select into literal LL_ADC_INJ_RANK_x the relevant bits for:            */
/* - data register offset                                                     */
/* - offset register offset                                                   */
/* - sequencer rank bits position into the selected register                  */

/* Internal register offset for ADC group injected data register */
/* (offset placed into a spare area of literal definition) */
#define ADC_JDR1_REGOFFSET                 0x00000000U
#define ADC_JDR2_REGOFFSET                 0x00000100U
#define ADC_JDR3_REGOFFSET                 0x00000200U
#define ADC_JDR4_REGOFFSET                 0x00000300U

/* Internal register offset for ADC group injected offset configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC_JOFR1_REGOFFSET                0x00000000U
#define ADC_JOFR2_REGOFFSET                0x00001000U
#define ADC_JOFR3_REGOFFSET                0x00002000U
#define ADC_JOFR4_REGOFFSET                0x00003000U

#define ADC_INJ_JDRX_REGOFFSET_MASK        (ADC_JDR1_REGOFFSET | ADC_JDR2_REGOFFSET | ADC_JDR3_REGOFFSET | ADC_JDR4_REGOFFSET)
#define ADC_INJ_JOFRX_REGOFFSET_MASK       (ADC_JOFR1_REGOFFSET | ADC_JOFR2_REGOFFSET | ADC_JOFR3_REGOFFSET | ADC_JOFR4_REGOFFSET)
#define ADC_INJ_RANK_ID_JSQR_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0)

/* Internal mask for ADC channel:                                             */
/* To select into literal LL_ADC_CHANNEL_x the relevant bits for:             */
/* - channel identifier defined by number                                     */
/* - channel differentiation between external channels (connected to          */
/*   GPIO pins) and internal channels (connected to internal paths)           */
/* - channel sampling time defined by SMPRx register offset                   */
/*   and SMPx bits positions into SMPRx register                              */
#define ADC_CHANNEL_ID_NUMBER_MASK         (ADC_CR1_AWDCH)
#define ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS ( 0U)/* Value equivalent to POSITION_VAL(ADC_CHANNEL_ID_NUMBER_MASK) */
#define ADC_CHANNEL_ID_MASK                (ADC_CHANNEL_ID_NUMBER_MASK | ADC_CHANNEL_ID_INTERNAL_CH_MASK)
/* Equivalent mask of ADC_CHANNEL_NUMBER_MASK aligned on register LSB (bit 0) */
#define ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 0x0000001FU /* Equivalent to shift: (ADC_CHANNEL_NUMBER_MASK >> POSITION_VAL(ADC_CHANNEL_NUMBER_MASK)) */

/* Channel differentiation between external and internal channels */
#define ADC_CHANNEL_ID_INTERNAL_CH         0x80000000U   /* Marker of internal channel */
#define ADC_CHANNEL_ID_INTERNAL_CH_2       0x40000000U   /* Marker of internal channel for other ADC instances, in case of different ADC internal channels mapped on same channel number on different ADC instances */
#define ADC_CHANNEL_ID_INTERNAL_CH_MASK    (ADC_CHANNEL_ID_INTERNAL_CH | ADC_CHANNEL_ID_INTERNAL_CH_2)

/* Internal register offset for ADC channel sampling time configuration */
/* (offset placed into a spare area of literal definition) */
#define ADC_SMPR1_REGOFFSET                0x00000000U
#define ADC_SMPR2_REGOFFSET                0x02000000U
#define ADC_CHANNEL_SMPRX_REGOFFSET_MASK   (ADC_SMPR1_REGOFFSET | ADC_SMPR2_REGOFFSET)

#define ADC_CHANNEL_SMPx_BITOFFSET_MASK    0x01F00000U
#define ADC_CHANNEL_SMPx_BITOFFSET_POS     (20U)           /* Value equivalent to POSITION_VAL(ADC_CHANNEL_SMPx_BITOFFSET_MASK) */

/* Definition of channels ID number information to be inserted into           */
/* channels literals definition.                                              */
#define ADC_CHANNEL_0_NUMBER               0x00000000U
#define ADC_CHANNEL_1_NUMBER               (                                                                        ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_2_NUMBER               (                                                      ADC_CR1_AWDCH_1                  )
#define ADC_CHANNEL_3_NUMBER               (                                                      ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_4_NUMBER               (                                    ADC_CR1_AWDCH_2                                    )
#define ADC_CHANNEL_5_NUMBER               (                                    ADC_CR1_AWDCH_2                   | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_6_NUMBER               (                                    ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1                  )
#define ADC_CHANNEL_7_NUMBER               (                                    ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_8_NUMBER               (                  ADC_CR1_AWDCH_3                                                      )
#define ADC_CHANNEL_9_NUMBER               (                  ADC_CR1_AWDCH_3                                     | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_10_NUMBER              (                  ADC_CR1_AWDCH_3                   | ADC_CR1_AWDCH_1                  )
#define ADC_CHANNEL_11_NUMBER              (                  ADC_CR1_AWDCH_3                   | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_12_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2                                    )
#define ADC_CHANNEL_13_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2                   | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_14_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1                  )
#define ADC_CHANNEL_15_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0)
#define ADC_CHANNEL_16_NUMBER              (ADC_CR1_AWDCH_4                                                                        )
#define ADC_CHANNEL_17_NUMBER              (ADC_CR1_AWDCH_4                                                       | ADC_CR1_AWDCH_0)

/* Definition of channels sampling time information to be inserted into       */
/* channels literals definition.                                              */
#define ADC_CHANNEL_0_SMP                  (ADC_SMPR2_REGOFFSET | (( 0U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP0) */
#define ADC_CHANNEL_1_SMP                  (ADC_SMPR2_REGOFFSET | (( 3U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP1) */
#define ADC_CHANNEL_2_SMP                  (ADC_SMPR2_REGOFFSET | (( 6U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP2) */
#define ADC_CHANNEL_3_SMP                  (ADC_SMPR2_REGOFFSET | (( 9U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP3) */
#define ADC_CHANNEL_4_SMP                  (ADC_SMPR2_REGOFFSET | ((12U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP4) */
#define ADC_CHANNEL_5_SMP                  (ADC_SMPR2_REGOFFSET | ((15U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP5) */
#define ADC_CHANNEL_6_SMP                  (ADC_SMPR2_REGOFFSET | ((18U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP6) */
#define ADC_CHANNEL_7_SMP                  (ADC_SMPR2_REGOFFSET | ((21U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP7) */
#define ADC_CHANNEL_8_SMP                  (ADC_SMPR2_REGOFFSET | ((24U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP8) */
#define ADC_CHANNEL_9_SMP                  (ADC_SMPR2_REGOFFSET | ((27U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR2_SMP9) */
#define ADC_CHANNEL_10_SMP                 (ADC_SMPR1_REGOFFSET | (( 0U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP10) */
#define ADC_CHANNEL_11_SMP                 (ADC_SMPR1_REGOFFSET | (( 3U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP11) */
#define ADC_CHANNEL_12_SMP                 (ADC_SMPR1_REGOFFSET | (( 6U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP12) */
#define ADC_CHANNEL_13_SMP                 (ADC_SMPR1_REGOFFSET | (( 9U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP13) */
#define ADC_CHANNEL_14_SMP                 (ADC_SMPR1_REGOFFSET | ((12U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP14) */
#define ADC_CHANNEL_15_SMP                 (ADC_SMPR1_REGOFFSET | ((15U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP15) */
#define ADC_CHANNEL_16_SMP                 (ADC_SMPR1_REGOFFSET | ((18U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP16) */
#define ADC_CHANNEL_17_SMP                 (ADC_SMPR1_REGOFFSET | ((21U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* Value shifted is equivalent to POSITION_VAL(ADC_SMPR1_SMP17) */

/* Internal mask for ADC analog watchdog:                                     */
/* To select into literals LL_ADC_AWD_CHANNELx_xxx the relevant bits for:     */
/* (concatenation of multiple bits used in different analog watchdogs,        */
/* (feature of several watchdogs not available on all STM32 families)).       */
/* - analog watchdog 1: monitored channel defined by number,                  */
/*   selection of ADC group (ADC groups regular and-or injected).             */

/* Internal register offset for ADC analog watchdog channel configuration */
#define ADC_AWD_CR1_REGOFFSET              0x00000000U

#define ADC_AWD_CRX_REGOFFSET_MASK         (ADC_AWD_CR1_REGOFFSET)

#define ADC_AWD_CR1_CHANNEL_MASK           (ADC_CR1_AWDCH | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL)
#define ADC_AWD_CR_ALL_CHANNEL_MASK        (ADC_AWD_CR1_CHANNEL_MASK)

/* Internal register offset for ADC analog watchdog threshold configuration */
#define ADC_AWD_TR1_HIGH_REGOFFSET         0x00000000U
#define ADC_AWD_TR1_LOW_REGOFFSET          0x00000001U
#define ADC_AWD_TRX_REGOFFSET_MASK         (ADC_AWD_TR1_HIGH_REGOFFSET | ADC_AWD_TR1_LOW_REGOFFSET)

/* ADC registers bits positions */
#define ADC_CR1_DUALMOD_BITOFFSET_POS      (16U) /* Value equivalent to POSITION_VAL(ADC_CR1_DUALMOD) */

/**
  * @}
  */


/* Private macros ------------------------------------------------------------*/
/** @defgroup ADC_LL_Private_Macros ADC Private Macros
  * @{
  */

/**
  * @brief  Driver macro reserved for internal use: isolate bits with the
  *         selected mask and shift them to the register LSB
  *         (shift mask on register position bit 0).
  * @param  __BITS__ Bits in register 32 bits
  * @param  __MASK__ Mask in register 32 bits
  * @retval Bits in register 32 bits
  */
#define __ADC_MASK_SHIFT(__BITS__, __MASK__)                                   \
  (((__BITS__) & (__MASK__)) >> POSITION_VAL((__MASK__)))

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  * @param  __REG__ Register basis from which the offset is applied.
  * @param  __REG_OFFFSET__ Offset to be applied (unit: number of registers).
  * @retval Pointer to register address
  */
#define __ADC_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                         \
 ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2U))))

/**
  * @}
  */


/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_ES_INIT ADC Exported Init structure
  * @{
  */

/**
  * @brief  Structure definition of some features of ADC common parameters
  *         and multimode
  *         (all ADC instances belonging to the same ADC common instance).
  * @note   The setting of these parameters by function @ref LL_ADC_CommonInit()
  *         is conditioned to ADC instances state (all ADC instances
  *         sharing the same ADC common instance):
  *         All ADC instances sharing the same ADC common instance must be
  *         disabled.
  */
typedef struct
{
  uint32_t Multimode;                   /*!< Set ADC multimode configuration to operate in independent mode or multimode (for devices with several ADC instances).
                                             This parameter can be a value of @ref ADC_LL_EC_MULTI_MODE
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetMultimode(). */
} LL_ADC_CommonInitTypeDef;
/**
  * @brief  Structure definition of some features of ADC instance.
  * @note   These parameters have an impact on ADC scope: ADC instance.
  *         Affects both group regular and group injected (availability
  *         of ADC group injected depends on STM32 families).
  *         Refer to corresponding unitary functions into
  *         @ref ADC_LL_EF_Configuration_ADC_Instance .
  * @note   The setting of these parameters by function @ref LL_ADC_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all STM32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t DataAlignment;               /*!< Set ADC conversion data alignment.
                                             This parameter can be a value of @ref ADC_LL_EC_DATA_ALIGN
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetDataAlignment(). */

  uint32_t SequencersScanMode;          /*!< Set ADC scan selection.
                                             This parameter can be a value of @ref ADC_LL_EC_SCAN_SELECTION
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetSequencersScanMode(). */

} LL_ADC_InitTypeDef;
