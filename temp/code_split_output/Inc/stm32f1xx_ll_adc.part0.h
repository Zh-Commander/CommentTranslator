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
// 防止递归包含
#ifndef __STM32F1xx_LL_ADC_H
#define __STM32F1xx_LL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含STM32F1系列芯片的头文件，定义了寄存器结构体和地址映射
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
/* ADC规则组序列器的内部掩码：                                                   */
/* 用于在字面量 LL_ADC_REG_RANK_x 中选择相关位：                                  */
/* - 序列器寄存器偏移量                                                          */
/* - 序列器排名位在选定寄存器中的位置                                              */

/* Internal register offset for ADC group regular sequencer configuration */
/* (offset placed into a spare area of literal definition) */
/* ADC规则组序列器配置的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域中) */
// 定义SQRx寄存器的偏移标识，用于后续计算寄存器地址
#define ADC_SQR1_REGOFFSET                 0x00000000U  // SQR1寄存器偏移
#define ADC_SQR2_REGOFFSET                 0x00000100U  // SQR2寄存器偏移
#define ADC_SQR3_REGOFFSET                 0x00000200U  // SQR3寄存器偏移
#define ADC_SQR4_REGOFFSET                 0x00000300U  // SQR4寄存器偏移 (F1系列未使用，保留兼容)

// 序列器寄存器偏移掩码，用于提取偏移信息
#define ADC_REG_SQRX_REGOFFSET_MASK        (ADC_SQR1_REGOFFSET | ADC_SQR2_REGOFFSET | ADC_SQR3_REGOFFSET | ADC_SQR4_REGOFFSET)
// 规则组通道ID掩码
#define ADC_REG_RANK_ID_SQRX_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0)

/* Definition of ADC group regular sequencer bits information to be inserted  */
/* into ADC group regular sequencer ranks literals definition.                */
/* 定义要插入到ADC规则组序列器排名字面量定义中的位信息                             */
// 定义规则组序列排名在寄存器中的位偏移位置
// 例如：Rank 1 位于 SQR3寄存器的 bit 0
#define ADC_REG_RANK_1_SQRX_BITOFFSET_POS  ( 0U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ1) */
#define ADC_REG_RANK_2_SQRX_BITOFFSET_POS  ( 5U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ2) */
#define ADC_REG_RANK_3_SQRX_BITOFFSET_POS  (10U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ3) */
#define ADC_REG_RANK_4_SQRX_BITOFFSET_POS  (15U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ4) */
#define ADC_REG_RANK_5_SQRX_BITOFFSET_POS  (20U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ5) */
#define ADC_REG_RANK_6_SQRX_BITOFFSET_POS  (25U) /* Value equivalent to POSITION_VAL(ADC_SQR3_SQ6) */
// Rank 7-12 位于 SQR2寄存器
#define ADC_REG_RANK_7_SQRX_BITOFFSET_POS  ( 0U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ7) */
#define ADC_REG_RANK_8_SQRX_BITOFFSET_POS  ( 5U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ8) */
#define ADC_REG_RANK_9_SQRX_BITOFFSET_POS  (10U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ9) */
#define ADC_REG_RANK_10_SQRX_BITOFFSET_POS (15U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ10) */
#define ADC_REG_RANK_11_SQRX_BITOFFSET_POS (20U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ11) */
#define ADC_REG_RANK_12_SQRX_BITOFFSET_POS (25U) /* Value equivalent to POSITION_VAL(ADC_SQR2_SQ12) */
// Rank 13-16 位于 SQR1寄存器
#define ADC_REG_RANK_13_SQRX_BITOFFSET_POS ( 0U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ13) */
#define ADC_REG_RANK_14_SQRX_BITOFFSET_POS ( 5U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ14) */
#define ADC_REG_RANK_15_SQRX_BITOFFSET_POS (10U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ15) */
#define ADC_REG_RANK_16_SQRX_BITOFFSET_POS (15U) /* Value equivalent to POSITION_VAL(ADC_SQR1_SQ16) */

/* Internal mask for ADC group injected sequencer:                            */
/* To select into literal LL_ADC_INJ_RANK_x the relevant bits for:            */
/* - data register offset                                                     */
/* - offset register offset                                                   */
/* - sequencer rank bits position into the selected register                  */
/* ADC注入组序列器的内部掩码：                                                   */
/* 用于在字面量 LL_ADC_INJ_RANK_x 中选择相关位：                                  */
/* - 数据寄存器偏移量                                                           */
/* - 偏移寄存器偏移量                                                           */
/* - 序列器排名位在选定寄存器中的位置                                              */

/* Internal register offset for ADC group injected data register */
/* (offset placed into a spare area of literal definition) */
/* ADC注入组数据寄存器的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域中) */
#define ADC_JDR1_REGOFFSET                 0x00000000U  // 注入数据寄存器1偏移
#define ADC_JDR2_REGOFFSET                 0x00000100U  // 注入数据寄存器2偏移
#define ADC_JDR3_REGOFFSET                 0x00000200U  // 注入数据寄存器3偏移
#define ADC_JDR4_REGOFFSET                 0x00000300U  // 注入数据寄存器4偏移

/* Internal register offset for ADC group injected offset configuration */
/* (offset placed into a spare area of literal definition) */
/* ADC注入组偏移配置寄存器的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域中) */
#define ADC_JOFR1_REGOFFSET                0x00000000U  // 注入偏移寄存器1偏移
#define ADC_JOFR2_REGOFFSET                0x00001000U  // 注入偏移寄存器2偏移
#define ADC_JOFR3_REGOFFSET                0x00002000U  // 注入偏移寄存器3偏移
#define ADC_JOFR4_REGOFFSET                0x00003000U  // 注入偏移寄存器4偏移

// 注入组数据寄存器偏移掩码
#define ADC_INJ_JDRX_REGOFFSET_MASK        (ADC_JDR1_REGOFFSET | ADC_JDR2_REGOFFSET | ADC_JDR3_REGOFFSET | ADC_JDR4_REGOFFSET)
// 注入组偏移寄存器偏移掩码
#define ADC_INJ_JOFRX_REGOFFSET_MASK       (ADC_JOFR1_REGOFFSET | ADC_JOFR2_REGOFFSET | ADC_JOFR3_REGOFFSET | ADC_JOFR4_REGOFFSET)
// 注入组通道ID掩码
#define ADC_INJ_RANK_ID_JSQR_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0)

/* Internal mask for ADC channel:                                             */
/* To select into literal LL_ADC_CHANNEL_x the relevant bits for:             */
/* - channel identifier defined by number                                     */
/* - channel differentiation between external channels (connected to          */
/*   GPIO pins) and internal channels (connected to internal paths)           */
/* - channel sampling time defined by SMPRx register offset                   */
/*   and SMPx bits positions into SMPRx register                              */
/* ADC通道的内部掩码：                                                          */
/* 用于在字面量 LL_ADC_CHANNEL_x 中选择相关位：                                   */
/* - 由数字定义的通道标识符                                                      */
/* - 外部通道（连接到GPIO引脚）和内部通道（连接到内部路径）之间的区分                 */
/* - 由 SMPRx 寄存器偏移量和 SMPx 位在 SMPRx 寄存器中的位置定义的通道采样时间        */

// 通道ID号掩码，对应CR1寄存器的AWDCH位
#define ADC_CHANNEL_ID_NUMBER_MASK         (ADC_CR1_AWDCH)
// 通道ID号在寄存器中的位偏移
#define ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS ( 0U)/* Value equivalent to POSITION_VAL(ADC_CHANNEL_ID_NUMBER_MASK) */
// 通道ID完整掩码（包含内部通道标记）
#define ADC_CHANNEL_ID_MASK                (ADC_CHANNEL_ID_NUMBER_MASK | ADC_CHANNEL_ID_INTERNAL_CH_MASK)
/* Equivalent mask of ADC_CHANNEL_NUMBER_MASK aligned on register LSB (bit 0) */
/* ADC_CHANNEL_NUMBER_MASK 对齐到寄存器LSB（位0）的等效掩码 */
#define ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 0x0000001FU /* Equivalent to shift: (ADC_CHANNEL_NUMBER_MASK >> POSITION_VAL(ADC_CHANNEL_NUMBER_MASK)) */

/* Channel differentiation between external and internal channels */
/* 外部通道和内部通道的区分 */
#define ADC_CHANNEL_ID_INTERNAL_CH         0x80000000U   /* Marker of internal channel */ // 内部通道标记
#define ADC_CHANNEL_ID_INTERNAL_CH_2       0x40000000U   /* Marker of internal channel for other ADC instances, in case of different ADC internal channels mapped on same channel number on different ADC instances */ // 用于不同ADC实例的内部通道标记
// 内部通道掩码
#define ADC_CHANNEL_ID_INTERNAL_CH_MASK    (ADC_CHANNEL_ID_INTERNAL_CH | ADC_CHANNEL_ID_INTERNAL_CH_2)

/* Internal register offset for ADC channel sampling time configuration */
/* (offset placed into a spare area of literal definition) */
/* ADC通道采样时间配置的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域中) */
#define ADC_SMPR1_REGOFFSET                0x00000000U  // SMPR1寄存器偏移
#define ADC_SMPR2_REGOFFSET                0x02000000U  // SMPR2寄存器偏移
// 采样时间寄存器偏移掩码
#define ADC_CHANNEL_SMPRX_REGOFFSET_MASK   (ADC_SMPR1_REGOFFSET | ADC_SMPR2_REGOFFSET)

// 采样时间位偏移掩码
#define ADC_CHANNEL_SMPx_BITOFFSET_MASK    0x01F00000U
// 采样时间位偏移位置
#define ADC_CHANNEL_SMPx_BITOFFSET_POS     (20U)           /* Value equivalent to POSITION_VAL(ADC_CHANNEL_SMPx_BITOFFSET_MASK) */

/* Definition of channels ID number information to be inserted into           */
/* channels literals definition.                                              */
/* 定义要插入到通道字面量定义中的通道ID号信息                                      */
// 定义通道编号，对应CR1寄存器中的模拟看门狗通道选择位
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
/* 定义要插入到通道字面量定义中的通道采样时间信息                                   */
// 定义各通道的采样时间配置信息，包含寄存器偏移和位偏移
// 通道0-9 使用 SMPR2 寄存器
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
// 通道10-17 使用 SMPR1 寄存器
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
/* ADC模拟看门狗的内部掩码：                                                     */
/* 用于在字面量 LL_ADC_AWD_CHANNELx_xxx 中选择相关位：                            */
/* （用于不同模拟看门狗的多个位的串联，                                           */
/* （多个看门狗功能并非在所有STM32系列上都可用））。                                */
/* - 模拟看门狗 1：由编号定义的监控通道，                                         */
/*   ADC组的选择（ADC规则组和/或注入组）。                                        */

/* Internal register offset for ADC analog watchdog channel configuration */
/* ADC模拟看门狗通道配置的内部寄存器偏移量 */
#define ADC_AWD_CR1_REGOFFSET              0x00000000U

// 看门狗控制寄存器偏移掩码
#define ADC_AWD_CRX_REGOFFSET_MASK         (ADC_AWD_CR1_REGOFFSET)

// 模拟看门狗CR1寄存器相关位掩码（通道号、使能位等）
#define ADC_AWD_CR1_CHANNEL_MASK           (ADC_CR1_AWDCH | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL)
// 所有看门狗通道掩码
#define ADC_AWD_CR_ALL_CHANNEL_MASK        (ADC_AWD_CR1_CHANNEL_MASK)

/* Internal register offset for ADC analog watchdog threshold configuration */
/* ADC模拟看门狗阈值配置的内部寄存器偏移量 */
#define ADC_AWD_TR1_HIGH_REGOFFSET         0x00000000U  // 高阈值偏移
#define ADC_AWD_TR1_LOW_REGOFFSET          0x00000001U  // 低阈值偏移
// 阈值寄存器偏移掩码
#define ADC_AWD_TRX_REGOFFSET_MASK         (ADC_AWD_TR1_HIGH_REGOFFSET | ADC_AWD_TR1_LOW_REGOFFSET)

/* ADC registers bits positions */
/* ADC寄存器位位置 */
// CR1寄存器中DUALMOD位的位置（双模式配置）
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
  *         驱动宏保留供内部使用：用选定的掩码隔离位并将它们移位到寄存器LSB
  *         （在寄存器位置位0上移位掩码）。
  * @param  __BITS__ Bits in register 32 bits // 寄存器32位中的位值
  * @param  __MASK__ Mask in register 32 bits // 寄存器32位中的掩码
  * @retval Bits in register 32 bits // 寄存器32位中的位值（已移位）
  */
#define __ADC_MASK_SHIFT(__BITS__, __MASK__)                                   \
  (((__BITS__) & (__MASK__)) >> POSITION_VAL((__MASK__)))

/**
  * @brief  Driver macro reserved for internal use: set a pointer to
  *         a register from a register basis from which an offset
  *         is applied.
  *         驱动宏保留供内部使用：设置一个指针指向寄存器，
  *         该指针基于一个应用了偏移量的寄存器基址。
  * @param  __REG__ Register basis from which the offset is applied. // 应用偏移量的寄存器基址
  * @param  __REG_OFFFSET__ Offset to be applied (unit: number of registers). // 要应用的偏移量（单位：寄存器数量）
  * @retval Pointer to register address // 指向寄存器地址的指针
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
  *         ADC公共参数和多模式的一些特性的结构定义
  *         （属于同一个ADC公共实例的所有ADC实例）。
  * @note   The setting of these parameters by function @ref LL_ADC_CommonInit()
  *         is conditioned to ADC instances state (all ADC instances
  *         sharing the same ADC common instance):
  *         All ADC instances sharing the same ADC common instance must be
  *         disabled.
  *         注意：通过函数 @ref LL_ADC_CommonInit() 设置这些参数取决于ADC实例的状态
  *         （共享同一个ADC公共实例的所有ADC实例）：
  *         共享同一个ADC公共实例的所有ADC实例必须被禁用。
  */
typedef struct
{
  uint32_t Multimode;                   /*!< Set ADC multimode configuration to operate in independent mode or multimode (for devices with several ADC instances).
                                             This parameter can be a value of @ref ADC_LL_EC_MULTI_MODE
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetMultimode(). */
                                         /*!< 设置ADC多模式配置，以独立模式或多模式运行（适用于具有多个ADC实例的设备）。
                                              此参数可以是 @ref ADC_LL_EC_MULTI_MODE 的值
                                              
                                              此特性随后可以使用单元函数 @ref LL_ADC_SetMultimode() 进行修改。 */
} LL_ADC_CommonInitTypeDef;
/**
  * @brief  Structure definition of some features of ADC instance.
  *         ADC实例的一些特性的结构定义。
  * @note   These parameters have an impact on ADC scope: ADC instance.
  *         Affects both group regular and group injected (availability
  *         of ADC group injected depends on STM32 families).
  *         Refer to corresponding unitary functions into
  *         @ref ADC_LL_EF_Configuration_ADC_Instance .
  *         注意：这些参数对ADC范围有影响：ADC实例。
  *         影响规则组和注入组（注入组的可用性取决于STM32系列）。
  *         请参阅 @ref ADC_LL_EF_Configuration_ADC_Instance 中的相应单元函数。
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
  *         注意：通过函数 @ref LL_ADC_Init() 设置这些参数取决于ADC状态：
  *         ADC实例必须被禁用。
  *         此条件适用于所有ADC特性，以提高效率和在所有STM32系列上的兼容性。
  *         但是，不同的特性可以在不同的ADC状态条件下设置
  *         （可以在ADC使能且无转换进行时设置，ADC使能且有转换进行时设置等...）
  *         每个特性随后可以使用单元函数进行更新，并且可能在ADC处于非禁用状态时进行，
  *         请参阅每个函数的描述以了解取决于ADC状态的设置。
  */
typedef struct
{
  uint32_t DataAlignment;               /*!< Set ADC conversion data alignment.
                                             This parameter can be a value of @ref ADC_LL_EC_DATA_ALIGN
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetDataAlignment(). */
                                         /*!< 设置ADC转换数据对齐方式。
                                              此参数可以是 @ref ADC_LL_EC_DATA_ALIGN 的值
                                              
                                              此特性随后可以使用单元函数 @ref LL_ADC_SetDataAlignment() 进行修改。 */

  uint32_t SequencersScanMode;          /*!< Set ADC scan selection.
                                             This parameter can be a value of @ref ADC_LL_EC_SCAN_SELECTION
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_SetSequencersScanMode(). */
                                         /*!< 设置ADC扫描选择。
                                              此参数可以是 @ref ADC_LL_EC_SCAN_SELECTION 的值
                                              
                                              此特性随后可以使用单元函数 @ref LL_ADC_SetSequencersScanMode() 进行修改。 */

} LL_ADC_InitTypeDef;
