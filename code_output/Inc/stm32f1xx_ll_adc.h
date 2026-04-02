/**
  ******************************************************************************
  * @file    stm32f1xx_ll_adc.h
  * @author  MCD Application Team
  * @brief   ADC LL模块头文件。
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

/* 定义防止递归包含 -----------------------------------------------------*/
#ifndef __STM32F1xx_LL_ADC_H
#define __STM32F1xx_LL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined (ADC1) || defined (ADC2) || defined (ADC3)

/** @defgroup ADC_LL ADC
  * @{
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/

/* 私有常量 ---------------------------------------------------------*/
/** @defgroup ADC_LL_Private_Constants ADC 私有常量
  * @{
  */

/* ADC规则组序列器的内部掩码：                             */
/* 用于在字面量 LL_ADC_REG_RANK_x 中选择相关位：            */
/* - 序列器寄存器偏移量                                                */
/* - 序列器排名在选定寄存器中的位位置                  */

/* ADC规则组序列器配置的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域) */
#define ADC_SQR1_REGOFFSET                 0x00000000U // 对应 SQR1 寄存器偏移
#define ADC_SQR2_REGOFFSET                 0x00000100U // 对应 SQR2 寄存器偏移
#define ADC_SQR3_REGOFFSET                 0x00000200U // 对应 SQR3 寄存器偏移
#define ADC_SQR4_REGOFFSET                 0x00000300U // 对应 SQR4 寄存器偏移 (F1系列通常无SQR4，此处预留)

#define ADC_REG_SQRX_REGOFFSET_MASK        (ADC_SQR1_REGOFFSET | ADC_SQR2_REGOFFSET | ADC_SQR3_REGOFFSET | ADC_SQR4_REGOFFSET) // 规则组序列器寄存器偏移掩码
#define ADC_REG_RANK_ID_SQRX_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0) // 规则组排名ID掩码

/* ADC规则组序列器位信息的定义，用于插入  */
/* 到ADC规则组序列器排名字面量定义中。                */
#define ADC_REG_RANK_1_SQRX_BITOFFSET_POS  ( 0U) /* 值等效于 POSITION_VAL(ADC_SQR3_SQ1)，第1个转换排名的位偏移 */
#define ADC_REG_RANK_2_SQRX_BITOFFSET_POS  ( 5U) /* 值等效于 POSITION_VAL(ADC_SQR3_SQ2)，第2个转换排名的位偏移 */
#define ADC_REG_RANK_3_SQRX_BITOFFSET_POS  (10U) /* 值等效于 POSITION_VAL(ADC_SQR3_SQ3)，第3个转换排名的位偏移 */
#define ADC_REG_RANK_4_SQRX_BITOFFSET_POS  (15U) /* 值等效于 POSITION_VAL(ADC_SQR3_SQ4)，第4个转换排名的位偏移 */
#define ADC_REG_RANK_5_SQRX_BITOFFSET_POS  (20U) /* 值等效于 POSITION_VAL(ADC_SQR3_SQ5)，第5个转换排名的位偏移 */
#define ADC_REG_RANK_6_SQRX_BITOFFSET_POS  (25U) /* 值等效于 POSITION_VAL(ADC_SQR3_SQ6)，第6个转换排名的位偏移 */
#define ADC_REG_RANK_7_SQRX_BITOFFSET_POS  ( 0U) /* 值等效于 POSITION_VAL(ADC_SQR2_SQ7)，第7个转换排名的位偏移 */
#define ADC_REG_RANK_8_SQRX_BITOFFSET_POS  ( 5U) /* 值等效于 POSITION_VAL(ADC_SQR2_SQ8)，第8个转换排名的位偏移 */
#define ADC_REG_RANK_9_SQRX_BITOFFSET_POS  (10U) /* 值等效于 POSITION_VAL(ADC_SQR2_SQ9)，第9个转换排名的位偏移 */
#define ADC_REG_RANK_10_SQRX_BITOFFSET_POS (15U) /* 值等效于 POSITION_VAL(ADC_SQR2_SQ10)，第10个转换排名的位偏移 */
#define ADC_REG_RANK_11_SQRX_BITOFFSET_POS (20U) /* 值等效于 POSITION_VAL(ADC_SQR2_SQ11)，第11个转换排名的位偏移 */
#define ADC_REG_RANK_12_SQRX_BITOFFSET_POS (25U) /* 值等效于 POSITION_VAL(ADC_SQR2_SQ12)，第12个转换排名的位偏移 */
#define ADC_REG_RANK_13_SQRX_BITOFFSET_POS ( 0U) /* 值等效于 POSITION_VAL(ADC_SQR1_SQ13)，第13个转换排名的位偏移 */
#define ADC_REG_RANK_14_SQRX_BITOFFSET_POS ( 5U) /* 值等效于 POSITION_VAL(ADC_SQR1_SQ14)，第14个转换排名的位偏移 */
#define ADC_REG_RANK_15_SQRX_BITOFFSET_POS (10U) /* 值等效于 POSITION_VAL(ADC_SQR1_SQ15)，第15个转换排名的位偏移 */
#define ADC_REG_RANK_16_SQRX_BITOFFSET_POS (15U) /* 值等效于 POSITION_VAL(ADC_SQR1_SQ16)，第16个转换排名的位偏移 */

/* 注入组序列器的内部掩码：                            */
/* 用于在字面量 LL_ADC_INJ_RANK_x 中选择相关位：            */
/* - 数据寄存器偏移量                                                     */
/* - 偏移寄存器偏移量                                                   */
/* - 序列器排名在选定寄存器中的位位置                  */

/* 注入组数据寄存器的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域) */
#define ADC_JDR1_REGOFFSET                 0x00000000U // 注入组数据寄存器1偏移
#define ADC_JDR2_REGOFFSET                 0x00000100U // 注入组数据寄存器2偏移
#define ADC_JDR3_REGOFFSET                 0x00000200U // 注入组数据寄存器3偏移
#define ADC_JDR4_REGOFFSET                 0x00000300U // 注入组数据寄存器4偏移

/* 注入组偏移配置的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域) */
#define ADC_JOFR1_REGOFFSET                0x00000000U // 注入组偏移寄存器1偏移
#define ADC_JOFR2_REGOFFSET                0x00001000U // 注入组偏移寄存器2偏移
#define ADC_JOFR3_REGOFFSET                0x00002000U // 注入组偏移寄存器3偏移
#define ADC_JOFR4_REGOFFSET                0x00003000U // 注入组偏移寄存器4偏移

#define ADC_INJ_JDRX_REGOFFSET_MASK        (ADC_JDR1_REGOFFSET | ADC_JDR2_REGOFFSET | ADC_JDR3_REGOFFSET | ADC_JDR4_REGOFFSET) // 注入组数据寄存器偏移掩码
#define ADC_INJ_JOFRX_REGOFFSET_MASK       (ADC_JOFR1_REGOFFSET | ADC_JOFR2_REGOFFSET | ADC_JOFR3_REGOFFSET | ADC_JOFR4_REGOFFSET) // 注入组偏移寄存器偏移掩码
#define ADC_INJ_RANK_ID_JSQR_MASK          (ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0) // 注入组排名ID掩码

/* ADC通道的内部掩码：                                             */
/* 用于在字面量 LL_ADC_CHANNEL_x 中选择相关位：             */
/* - 由数字定义的通道标识符                                     */
/* - 外部通道（连接到          */
/*   GPIO引脚）和内部通道（连接到内部路径）之间的通道区分           */
/* - 由 SMPRx 寄存器偏移定义的通道采样时间                   */
/*   以及 SMPx 在 SMPRx 寄存器中的位位置                              */
#define ADC_CHANNEL_ID_NUMBER_MASK         (ADC_CR1_AWDCH) // 通道ID号掩码，对应CR1寄存器中的AWDCH位
#define ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS ( 0U)/* 值等效于 POSITION_VAL(ADC_CHANNEL_ID_NUMBER_MASK)，通道号位偏移 */
#define ADC_CHANNEL_ID_MASK                (ADC_CHANNEL_ID_NUMBER_MASK | ADC_CHANNEL_ID_INTERNAL_CH_MASK) // 通道ID完整掩码（包含编号和内部/外部区分）
/* ADC_CHANNEL_NUMBER_MASK 对齐到寄存器LSB（位0）的等效掩码 */
#define ADC_CHANNEL_ID_NUMBER_MASK_POSBIT0 0x0000001FU /* 等效于移位: (ADC_CHANNEL_NUMBER_MASK >> POSITION_VAL(ADC_CHANNEL_NUMBER_MASK)) */

/* 外部通道和内部通道的区分 */
#define ADC_CHANNEL_ID_INTERNAL_CH         0x80000000U   /* 内部通道标记，用于标识内部通道（如温度传感器） */
#define ADC_CHANNEL_ID_INTERNAL_CH_2       0x40000000U   /* 用于其他ADC实例的内部通道标记，针对不同ADC实例内部通道映射到同一通道号的情况 */
#define ADC_CHANNEL_ID_INTERNAL_CH_MASK    (ADC_CHANNEL_ID_INTERNAL_CH | ADC_CHANNEL_ID_INTERNAL_CH_2) // 内部通道标记掩码

/* ADC通道采样时间配置的内部寄存器偏移量 */
/* (偏移量放置在字面量定义的空闲区域) */
#define ADC_SMPR1_REGOFFSET                0x00000000U // 采样时间寄存器1偏移
#define ADC_SMPR2_REGOFFSET                0x02000000U // 采样时间寄存器2偏移
#define ADC_CHANNEL_SMPRX_REGOFFSET_MASK   (ADC_SMPR1_REGOFFSET | ADC_SMPR2_REGOFFSET) // 采样时间寄存器偏移掩码

#define ADC_CHANNEL_SMPx_BITOFFSET_MASK    0x01F00000U // 采样时间位偏移掩码
#define ADC_CHANNEL_SMPx_BITOFFSET_POS     (20U)           /* 值等效于 POSITION_VAL(ADC_CHANNEL_SMPx_BITOFFSET_MASK)，采样时间配置位的起始位置 */

/* 要插入通道ID号信息的定义           */
/* 通道字面量定义。                                              */
#define ADC_CHANNEL_0_NUMBER               0x00000000U // 通道0编号
#define ADC_CHANNEL_1_NUMBER               (                                                                        ADC_CR1_AWDCH_0) // 通道1编号
#define ADC_CHANNEL_2_NUMBER               (                                                      ADC_CR1_AWDCH_1                  ) // 通道2编号
#define ADC_CHANNEL_3_NUMBER               (                                                      ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0) // 通道3编号
#define ADC_CHANNEL_4_NUMBER               (                                    ADC_CR1_AWDCH_2                                    ) // 通道4编号
#define ADC_CHANNEL_5_NUMBER               (                                    ADC_CR1_AWDCH_2                   | ADC_CR1_AWDCH_0) // 通道5编号
#define ADC_CHANNEL_6_NUMBER               (                                    ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1                  ) // 通道6编号
#define ADC_CHANNEL_7_NUMBER               (                                    ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0) // 通道7编号
#define ADC_CHANNEL_8_NUMBER               (                  ADC_CR1_AWDCH_3                                                      ) // 通道8编号
#define ADC_CHANNEL_9_NUMBER               (                  ADC_CR1_AWDCH_3                                     | ADC_CR1_AWDCH_0) // 通道9编号
#define ADC_CHANNEL_10_NUMBER              (                  ADC_CR1_AWDCH_3                   | ADC_CR1_AWDCH_1                  ) // 通道10编号
#define ADC_CHANNEL_11_NUMBER              (                  ADC_CR1_AWDCH_3                   | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0) // 通道11编号
#define ADC_CHANNEL_12_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2                                    ) // 通道12编号
#define ADC_CHANNEL_13_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2                   | ADC_CR1_AWDCH_0) // 通道13编号
#define ADC_CHANNEL_14_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1                  ) // 通道14编号
#define ADC_CHANNEL_15_NUMBER              (                  ADC_CR1_AWDCH_3 | ADC_CR1_AWDCH_2 | ADC_CR1_AWDCH_1 | ADC_CR1_AWDCH_0) // 通道15编号
#define ADC_CHANNEL_16_NUMBER              (ADC_CR1_AWDCH_4                                                                        ) // 通道16编号
#define ADC_CHANNEL_17_NUMBER              (ADC_CR1_AWDCH_4                                                       | ADC_CR1_AWDCH_0) // 通道17编号

/* 要插入通道采样时间信息的定义       */
/* 通道字面量定义。                                              */
#define ADC_CHANNEL_0_SMP                  (ADC_SMPR2_REGOFFSET | (( 0U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP0)，通道0采样时间配置 */
#define ADC_CHANNEL_1_SMP                  (ADC_SMPR2_REGOFFSET | (( 3U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP1)，通道1采样时间配置 */
#define ADC_CHANNEL_2_SMP                  (ADC_SMPR2_REGOFFSET | (( 6U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP2)，通道2采样时间配置 */
#define ADC_CHANNEL_3_SMP                  (ADC_SMPR2_REGOFFSET | (( 9U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP3)，通道3采样时间配置 */
#define ADC_CHANNEL_4_SMP                  (ADC_SMPR2_REGOFFSET | ((12U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP4)，通道4采样时间配置 */
#define ADC_CHANNEL_5_SMP                  (ADC_SMPR2_REGOFFSET | ((15U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP5)，通道5采样时间配置 */
#define ADC_CHANNEL_6_SMP                  (ADC_SMPR2_REGOFFSET | ((18U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP6)，通道6采样时间配置 */
#define ADC_CHANNEL_7_SMP                  (ADC_SMPR2_REGOFFSET | ((21U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP7)，通道7采样时间配置 */
#define ADC_CHANNEL_8_SMP                  (ADC_SMPR2_REGOFFSET | ((24U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP8)，通道8采样时间配置 */
#define ADC_CHANNEL_9_SMP                  (ADC_SMPR2_REGOFFSET | ((27U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR2_SMP9)，通道9采样时间配置 */
#define ADC_CHANNEL_10_SMP                 (ADC_SMPR1_REGOFFSET | (( 0U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP10)，通道10采样时间配置 */
#define ADC_CHANNEL_11_SMP                 (ADC_SMPR1_REGOFFSET | (( 3U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP11)，通道11采样时间配置 */
#define ADC_CHANNEL_12_SMP                 (ADC_SMPR1_REGOFFSET | (( 6U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP12)，通道12采样时间配置 */
#define ADC_CHANNEL_13_SMP                 (ADC_SMPR1_REGOFFSET | (( 9U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP13)，通道13采样时间配置 */
#define ADC_CHANNEL_14_SMP                 (ADC_SMPR1_REGOFFSET | ((12U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP14)，通道14采样时间配置 */
#define ADC_CHANNEL_15_SMP                 (ADC_SMPR1_REGOFFSET | ((15U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP15)，通道15采样时间配置 */
#define ADC_CHANNEL_16_SMP                 (ADC_SMPR1_REGOFFSET | ((18U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP16)，通道16采样时间配置 */
#define ADC_CHANNEL_17_SMP                 (ADC_SMPR1_REGOFFSET | ((21U) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) /* 移位值等效于 POSITION_VAL(ADC_SMPR1_SMP17)，通道17采样时间配置 */

/* ADC模拟看门狗的内部掩码：                                     */
/* 用于在字面量 LL_ADC_AWD_CHANNELx_xxx 中选择相关位：     */
/* (用于不同模拟看门狗的多个位的串联，        */
/* (并非所有STM32系列都支持多个看门狗功能)。       */
/* - 模拟看门狗 1：由编号定义的监控通道，                  */
/*   ADC组的选择（ADC规则组和/或注入组）。             */

/* ADC模拟看门狗通道配置的内部寄存器偏移量 */
#define ADC_AWD_CR1_REGOFFSET              0x00000000U // 看门狗控制寄存器1偏移

#define ADC_AWD_CRX_REGOFFSET_MASK         (ADC_AWD_CR1_REGOFFSET) // 看门狗控制寄存器偏移掩码

#define ADC_AWD_CR1_CHANNEL_MASK           (ADC_CR1_AWDCH | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) // 看门狗通道使能及模式掩码
#define ADC_AWD_CR_ALL_CHANNEL_MASK        (ADC_AWD_CR1_CHANNEL_MASK) // 所有看门狗通道掩码

/* ADC模拟看门狗阈值配置的内部寄存器偏移量 */
#define ADC_AWD_TR1_HIGH_REGOFFSET         0x00000000U // 高阈值寄存器偏移
#define ADC_AWD_TR1_LOW_REGOFFSET          0x00000001U // 低阈值寄存器偏移
#define ADC_AWD_TRX_REGOFFSET_MASK         (ADC_AWD_TR1_HIGH_REGOFFSET | ADC_AWD_TR1_LOW_REGOFFSET) // 阈值寄存器偏移掩码

/* ADC寄存器位位置 */
#define ADC_CR1_DUALMOD_BITOFFSET_POS      (16U) /* 值等效于 POSITION_VAL(ADC_CR1_DUALMOD)，双模式配置位偏移 */

/**
  * @}
  */


/* 私有宏 ------------------------------------------------------------*/
/** @defgroup ADC_LL_Private_Macros ADC 私有宏
  * @{
  */

/**
  * @brief  保留供内部使用的驱动程序宏：用选定的掩码隔离位并将它们移位到寄存器LSB
  *         (将掩码移位到寄存器位置位0)。
  * @param  __BITS__ 寄存器32位值
  * @param  __MASK__ 寄存器32位掩码
  * @retval 寄存器32位值
  */
#define __ADC_MASK_SHIFT(__BITS__, __MASK__)                                   \
  (((__BITS__) & (__MASK__)) >> POSITION_VAL((__MASK__)))

/**
  * @brief  保留供内部使用的驱动程序宏：设置一个指向寄存器的指针，
  *         该指针基于应用了偏移量的寄存器基址。
  * @param  __REG__ 应用偏移量的寄存器基址。
  * @param  __REG_OFFFSET__ 要应用的偏移量（单位：寄存器数量）。
  * @retval 指向寄存器地址的指针
  */
#define __ADC_PTR_REG_OFFSET(__REG__, __REG_OFFFSET__)                         \
 ((__IO uint32_t *)((uint32_t) ((uint32_t)(&(__REG__)) + ((__REG_OFFFSET__) << 2U))))

/**
  * @}
  */


/* 导出类型 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_ES_INIT ADC 导出初始化结构体
  * @{
  */

/**
  * @brief  ADC公共参数和多模式的一些特性的结构体定义
  *         （属于同一个ADC公共实例的所有ADC实例）。
  * @note   通过函数 @ref LL_ADC_CommonInit() 设置这些参数的条件是ADC实例状态
  *         （共享同一个ADC公共实例的所有ADC实例）：
  *         共享同一个ADC公共实例的所有ADC实例必须被禁用。
  */
typedef struct
{
  uint32_t Multimode;                   /*!< 设置ADC多模式配置，以独立模式或多模式运行（针对具有多个ADC实例的设备）。
                                             此参数可以是 @ref ADC_LL_EC_MULTI_MODE 中的一个值
                                             
                                             此特性之后可以使用单元函数 @ref LL_ADC_SetMultimode() 进行修改。 */
} LL_ADC_CommonInitTypeDef;
/**
  * @brief  ADC实例的一些特性的结构体定义。
  * @note   这些参数影响ADC范围：ADC实例。
  *         影响规则组和注入组（注入组的可用性取决于STM32系列）。
  *         参见 @ref ADC_LL_EF_Configuration_ADC_Instance 中的相应单元函数。
  * @note   通过函数 @ref LL_ADC_Init() 设置这些参数的条件是ADC状态：
  *         ADC实例必须被禁用。
  *         此条件适用于所有ADC特性，以提高效率和兼容性。
  *         然而，不同的特性可以在不同的ADC状态条件下设置
  *         （可以在ADC使能且无转换进行时设置，
  *         ADC使能且有转换进行时设置，等等）
  *         每个特性之后都可以使用单元函数更新，
  *         并且可能在ADC处于非禁用的不同状态下，
  *         请参阅每个函数的说明以了解设置的ADC状态条件。
  */
typedef struct
{
  uint32_t DataAlignment;               /*!< 设置ADC转换数据对齐方式。
                                             此参数可以是 @ref ADC_LL_EC_DATA_ALIGN 中的一个值
                                             
                                             此特性之后可以使用单元函数 @ref LL_ADC_SetDataAlignment() 进行修改。 */

  uint32_t SequencersScanMode;          /*!< 设置ADC扫描选择。
                                             此参数可以是 @ref ADC_LL_EC_SCAN_SELECTION 中的一个值
                                             
                                             此特性之后可以使用单元函数 @ref LL_ADC_SetSequencersScanMode() 进行修改。 */

} LL_ADC_InitTypeDef;
/**
  * @brief  ADC规则组特性结构体定义。
  * @note   这些参数影响ADC范围：ADC规则组。
  *         请参考 @ref ADC_LL_EF_Configuration_ADC_Group_Regular 中的相应单元函数
  *         (带有前缀 "REG" 的函数)。
  * @note   通过函数 @ref LL_ADC_REG_Init() 设置这些参数的条件是ADC状态：
  *         ADC实例必须处于禁用状态。
  *         此条件适用于所有ADC特性，以提高效率并兼容所有STM32系列。
  *         但是，不同的特性可以在不同的ADC状态条件下设置
  *         (可以在ADC使能且无转换进行时设置，ADC使能且有转换进行时设置，...)
  *         每个特性随后可以通过单元函数进行更新，
  *         并且可能在ADC处于非禁用状态时进行，
  *         请参考每个函数的说明以了解设置的ADC状态条件。
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< 设置ADC规则组转换触发源：内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
                                             此参数可以是 @ref ADC_LL_EC_REG_TRIGGER_SOURCE 中的值
                                             @note 在此STM32系列上，外部触发设置为触发极性：上升沿
                                                   （此STM32系列上唯一可用的触发极性）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetTriggerSource() 进行修改。 */

  uint32_t SequencerLength;             /*!< 设置ADC规则组序列器长度。
                                             此参数可以是 @ref ADC_LL_EC_REG_SEQ_SCAN_LENGTH 中的值
                                             @note 如果禁用扫描模式（参考参数 'ADC_SequencersScanMode'），则忽略此参数。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetSequencerLength() 进行修改。 */

  uint32_t SequencerDiscont;            /*!< 设置ADC规则组序列器间断模式：序列细分并在每个选定数量的等级中断扫描转换。
                                             此参数可以是 @ref ADC_LL_EC_REG_SEQ_DISCONT_MODE 中的值
                                             @note 此参数仅在启用规则组序列器时有效
                                                   （扫描长度为2个或更多等级）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetSequencerDiscont() 进行修改。 */

  uint32_t ContinuousMode;              /*!< 设置ADC规则组上的连续转换模式，是以单次模式执行ADC转换（每次触发一次转换）还是以连续模式执行（在第一次触发后，随后的转换自动连续启动）。
                                             此参数可以是 @ref ADC_LL_EC_REG_CONTINUOUS_MODE 中的值
                                             注意：不可能同时启用ADC规则组连续模式和间断模式。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetContinuousMode() 进行修改。 */

  uint32_t DMATransfer;                 /*!< 设置ADC规则组转换数据传输：无传输或通过DMA传输，以及DMA请求模式。
                                             此参数可以是 @ref ADC_LL_EC_REG_DMA_TRANSFER 中的值
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetDMATransfer() 进行修改。 */

} LL_ADC_REG_InitTypeDef;

/**
  * @brief  ADC注入组特性结构体定义。
  * @note   这些参数影响ADC范围：ADC注入组。
  *         请参考 @ref ADC_LL_EF_Configuration_ADC_Group_Regular 中的相应单元函数
  *         (带有前缀 "INJ" 的函数)。
  * @note   通过函数 @ref LL_ADC_INJ_Init() 设置这些参数的条件是ADC状态：
  *         ADC实例必须处于禁用状态。
  *         此条件适用于所有ADC特性，以提高效率并兼容所有STM32系列。
  *         但是，不同的特性可以在不同的ADC状态条件下设置
  *         (可以在ADC使能且无转换进行时设置，ADC使能且有转换进行时设置，...)
  *         每个特性随后可以通过单元函数进行更新，
  *         并且可能在ADC处于非禁用状态时进行，
  *         请参考每个函数的说明以了解设置的ADC状态条件。
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< 设置ADC注入组转换触发源：内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
                                             此参数可以是 @ref ADC_LL_EC_INJ_TRIGGER_SOURCE 中的值
                                             @note 在此STM32系列上，外部触发设置为触发极性：上升沿
                                                   （此STM32系列上唯一可用的触发极性）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetTriggerSource() 进行修改。 */

  uint32_t SequencerLength;             /*!< 设置ADC注入组序列器长度。
                                             此参数可以是 @ref ADC_LL_EC_INJ_SEQ_SCAN_LENGTH 中的值
                                             @note 如果禁用扫描模式（参考参数 'ADC_SequencersScanMode'），则忽略此参数。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetSequencerLength() 进行修改。 */

  uint32_t SequencerDiscont;            /*!< 设置ADC注入组序列器间断模式：序列细分并在每个选定数量的等级中断扫描转换。
                                             此参数可以是 @ref ADC_LL_EC_INJ_SEQ_DISCONT_MODE 中的值
                                             @note 此参数仅在启用注入组序列器时有效
                                                   （扫描长度为2个或更多等级）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetSequencerDiscont() 进行修改。 */

  uint32_t TrigAuto;                    /*!< 设置ADC注入组转换触发：独立触发或来自ADC规则组。
                                             此参数可以是 @ref ADC_LL_EC_INJ_TRIG_AUTO 中的值
                                             注意：如果注入触发源设置为外部触发，则此参数必须设置为独立触发。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetTrigAuto() 进行修改。 */

} LL_ADC_INJ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* 导出常量 ------------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Constants ADC导出常量
  * @{
  */

/** @defgroup ADC_LL_EC_FLAG ADC标志位
  * @brief    标志位定义，可与 LL_ADC_ReadReg 函数一起使用
  * @{
  */
#define LL_ADC_FLAG_STRT                   ADC_SR_STRT        /*!< ADC标志：ADC规则组转换开始 */
#define LL_ADC_FLAG_EOS                    ADC_SR_EOC         /*!< ADC标志：ADC规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”） */
#define LL_ADC_FLAG_JSTRT                  ADC_SR_JSTRT       /*!< ADC标志：ADC注入组转换开始 */
#define LL_ADC_FLAG_JEOS                   ADC_SR_JEOC        /*!< ADC标志：ADC注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”） */
#define LL_ADC_FLAG_AWD1                   ADC_SR_AWD         /*!< ADC标志：ADC模拟看门狗1 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_FLAG_EOS_MST                ADC_SR_EOC         /*!< ADC标志：ADC多模式主模式规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”） */
#define LL_ADC_FLAG_EOS_SLV                ADC_SR_EOC         /*!< ADC标志：ADC多模式从模式规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”）（在STM32F1上，此标志必须从ADC实例从机读取：ADC2） */
#define LL_ADC_FLAG_JEOS_MST               ADC_SR_JEOC        /*!< ADC标志：ADC多模式主模式注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”） */
#define LL_ADC_FLAG_JEOS_SLV               ADC_SR_JEOC        /*!< ADC标志：ADC多模式从模式注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”）（在STM32F1上，此标志必须从ADC实例从机读取：ADC2） */
#define LL_ADC_FLAG_AWD1_MST               ADC_SR_AWD         /*!< ADC标志：ADC多模式主模式ADC主机的模拟看门狗1 */
#define LL_ADC_FLAG_AWD1_SLV               ADC_SR_AWD         /*!< ADC标志：ADC多模式从模式ADC从机的模拟看门狗1（在STM32F1上，此标志必须从ADC实例从机读取：ADC2） */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_IT ADC中断配置（中断使能或禁用）
  * @brief    中断定义，可与 LL_ADC_ReadReg 和 LL_ADC_WriteReg 函数一起使用
  * @{
  */
#define LL_ADC_IT_EOS                      ADC_CR1_EOCIE      /*!< ADC中断：ADC规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”） */
#define LL_ADC_IT_JEOS                     ADC_CR1_JEOCIE     /*!< ADC中断：ADC注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”） */
#define LL_ADC_IT_AWD1                     ADC_CR1_AWDIE      /*!< ADC中断：ADC模拟看门狗1 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REGISTERS  符合特定用途的ADC寄存器
  * @{
  */
/* 旨在（最常）与DMA传输一起使用的ADC寄存器列表。             */
/* 请参考函数 @ref LL_ADC_DMA_GetRegAddr()。                   */
#define LL_ADC_DMA_REG_REGULAR_DATA          0x00000000U   /* ADC规则组转换数据寄存器（对应于寄存器DR），用于配置为独立模式的ADC。无DMA传输时，通过LL函数 @ref LL_ADC_REG_ReadConversionData32() 和其他函数 @ref LL_ADC_REG_ReadConversionDatax() 访问的寄存器 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_DMA_REG_REGULAR_DATA_MULTI    0x00000001U   /* ADC规则组转换数据寄存器（对应于寄存器CDR），用于配置为多模式的ADC（适用于具有多个ADC实例的STM32设备）。无DMA传输时，通过LL函数 @ref LL_ADC_REG_ReadMultiConversionData32() 访问的寄存器 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_COMMON_PATH_INTERNAL  ADC通用 - 内部通道测量路径
  * @{
  */
/* 注意：可能还有其他通往内部通道的测量路径可用        */
/*       （连接到其他外设）。                                  */
/*       如果它们未在下面列出，则它们不需要任何特定的       */
/*       路径使能。在这种情况下，访问测量路径是通过        */
/*       选择相应的ADC内部通道来完成的。            */
#define LL_ADC_PATH_INTERNAL_NONE          0x00000000U            /*!< ADC测量路径全部禁用 */
#define LL_ADC_PATH_INTERNAL_VREFINT       (ADC_CR2_TSVREFE)      /*!< ADC测量路径通往内部通道VrefInt（内部参考电压） */
#define LL_ADC_PATH_INTERNAL_TEMPSENSOR    (ADC_CR2_TSVREFE)      /*!< ADC测量路径通往内部通道温度传感器 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_RESOLUTION  ADC实例 - 分辨率
  * @{
  */
#define LL_ADC_RESOLUTION_12B              0x00000000U                         /*!< ADC分辨率12位 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_DATA_ALIGN  ADC实例 - 数据对齐
  * @{
  */
#define LL_ADC_DATA_ALIGN_RIGHT            0x00000000U            /*!< ADC转换数据对齐：右对齐（对齐在数据寄存器LSB位0）*/
#define LL_ADC_DATA_ALIGN_LEFT             (ADC_CR2_ALIGN)        /*!< ADC转换数据对齐：左对齐（对齐在数据寄存器MSB位15）*/
/**
  * @}
  */

/** @defgroup ADC_LL_EC_SCAN_SELECTION ADC实例 - 扫描选择
  * @{
  */
#define LL_ADC_SEQ_SCAN_DISABLE            0x00000000U    /*!< ADC转换以单元转换模式执行（转换一个通道，即在等级1中定义的通道）。规则组和注入组序列器的配置（序列长度等）被忽略：相当于长度为1个等级。*/
#define LL_ADC_SEQ_SCAN_ENABLE             (ADC_CR1_SCAN) /*!< ADC转换以序列转换模式执行，根据规则组和注入组序列器的配置（序列长度等）。 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_GROUPS  ADC实例 - 组
  * @{
  */
#define LL_ADC_GROUP_REGULAR               0x00000001U   /*!< ADC规则组（适用于所有STM32设备） */
#define LL_ADC_GROUP_INJECTED              0x00000002U   /*!< ADC注入组（并非适用于所有STM32设备）*/
#define LL_ADC_GROUP_REGULAR_INJECTED      0x00000003U   /*!< ADC规则组和注入组两者 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL  ADC实例 - 通道号
  * @{
  */
#define LL_ADC_CHANNEL_0                   (ADC_CHANNEL_0_NUMBER  | ADC_CHANNEL_0_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN0  */
#define LL_ADC_CHANNEL_1                   (ADC_CHANNEL_1_NUMBER  | ADC_CHANNEL_1_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN1  */
#define LL_ADC_CHANNEL_2                   (ADC_CHANNEL_2_NUMBER  | ADC_CHANNEL_2_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN2  */
#define LL_ADC_CHANNEL_3                   (ADC_CHANNEL_3_NUMBER  | ADC_CHANNEL_3_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN3  */
#define LL_ADC_CHANNEL_4                   (ADC_CHANNEL_4_NUMBER  | ADC_CHANNEL_4_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN4  */
#define LL_ADC_CHANNEL_5                   (ADC_CHANNEL_5_NUMBER  | ADC_CHANNEL_5_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN5  */
#define LL_ADC_CHANNEL_6                   (ADC_CHANNEL_6_NUMBER  | ADC_CHANNEL_6_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN6  */
#define LL_ADC_CHANNEL_7                   (ADC_CHANNEL_7_NUMBER  | ADC_CHANNEL_7_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN7  */
#define LL_ADC_CHANNEL_8                   (ADC_CHANNEL_8_NUMBER  | ADC_CHANNEL_8_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN8  */
#define LL_ADC_CHANNEL_9                   (ADC_CHANNEL_9_NUMBER  | ADC_CHANNEL_9_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN9  */
#define LL_ADC_CHANNEL_10                  (ADC_CHANNEL_10_NUMBER | ADC_CHANNEL_10_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN10 */
#define LL_ADC_CHANNEL_11                  (ADC_CHANNEL_11_NUMBER | ADC_CHANNEL_11_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN11 */
#define LL_ADC_CHANNEL_12                  (ADC_CHANNEL_12_NUMBER | ADC_CHANNEL_12_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN12 */
#define LL_ADC_CHANNEL_13                  (ADC_CHANNEL_13_NUMBER | ADC_CHANNEL_13_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN13 */
#define LL_ADC_CHANNEL_14                  (ADC_CHANNEL_14_NUMBER | ADC_CHANNEL_14_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN14 */
#define LL_ADC_CHANNEL_15                  (ADC_CHANNEL_15_NUMBER | ADC_CHANNEL_15_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN15 */
#define LL_ADC_CHANNEL_16                  (ADC_CHANNEL_16_NUMBER | ADC_CHANNEL_16_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN16 */
#define LL_ADC_CHANNEL_17                  (ADC_CHANNEL_17_NUMBER | ADC_CHANNEL_17_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN17 */
#define LL_ADC_CHANNEL_VREFINT             (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC内部通道连接到VrefInt：内部参考电压。在STM32F1上，ADC通道仅在ADC实例上可用：ADC1。 */
#define LL_ADC_CHANNEL_TEMPSENSOR          (LL_ADC_CHANNEL_16 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC内部通道连接到温度传感器。 */
/**
  * @}
  */
/** @defgroup ADC_LL_EC_REG_TRIGGER_SOURCE  ADC 规则组 - 触发源
  * @{
  */
/* ADC 规则组外部触发源，适用于 ADC 实例: ADC1, ADC2, ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_REG_TRIG_SOFTWARE           (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0) /*!< ADC 规则组转换触发源为内部：软件启动 (SW start)。 */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH3       (ADC_CR2_EXTSEL_1)                                       /*!< ADC 规则组转换触发源来自外部 IP：TIM1 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
/* ADC 规则组外部触发源，适用于 ADC 实例: ADC1, ADC2 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH1       0x00000000U                                              /*!< ADC 规则组转换触发源来自外部 IP：TIM1 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH2       (ADC_CR2_EXTSEL_0)                                       /*!< ADC 规则组转换触发源来自外部 IP：TIM1 通道 2 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM2_CH2       (ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0)                    /*!< ADC 规则组转换触发源来自外部 IP：TIM2 通道 2 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (ADC_CR2_EXTSEL_2)                                       /*!< ADC 规则组转换触发源来自外部 IP：TIM3 TRGO 事件。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM4_CH4       (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_0)                    /*!< ADC 规则组转换触发源来自外部 IP：TIM4 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1)                    /*!< ADC 规则组转换触发源来自外部 IP：外部中断线 11。触发边沿设置为上升沿 (默认设置)。 */
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/* 注意: TIM8_TRGO 仅在大容量 (High-density) 和超大容量 (XL-density) 设备的 ADC1 和 ADC2 上可用。 */
/* 注意: 要在 ADC1 或 ADC2 上使用 TIM8_TRGO，必须进行触发重映射。                           */
/*       触发重映射必须在顶层完成 (请参考 AFIO 外设)。                                      */
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                        /*!< ADC 规则组转换触发源来自外部 IP：TIM8 TRGO。触发边沿设置为上升沿 (默认设置)。仅在大容量和超大容量设备上可用。触发重映射必须在顶层完成 (请参考 AFIO 外设)。*/
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC 规则组外部触发源，适用于 ADC 实例: ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_REG_TRIG_EXT_TIM3_CH1       (LL_ADC_REG_TRIG_EXT_TIM1_CH1)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM3 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM2_CH3       (LL_ADC_REG_TRIG_EXT_TIM1_CH2)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM2 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM8_CH1       (LL_ADC_REG_TRIG_EXT_TIM2_CH2)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM8 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (LL_ADC_REG_TRIG_EXT_TIM3_TRGO)                          /*!< ADC 规则组转换触发源来自外部 IP：TIM8 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM5_CH1       (LL_ADC_REG_TRIG_EXT_TIM4_CH4)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM5 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM5_CH3       (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                        /*!< ADC 规则组转换触发源来自外部 IP：TIM5 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_TRIGGER_EDGE  ADC 规则组 - 触发边沿
  * @{
  */
#define LL_ADC_REG_TRIG_EXT_RISING         ADC_CR2_EXTTRIG                         /*!< ADC 规则组转换触发极性设置为上升沿 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_CONTINUOUS_MODE  ADC 规则组 - 连续转换模式
* @{
*/
#define LL_ADC_REG_CONV_SINGLE             0x00000000U             /*!< ADC 转换在单次模式下执行：每次触发执行一次转换 */
#define LL_ADC_REG_CONV_CONTINUOUS         (ADC_CR2_CONT)          /*!< ADC 转换在连续模式下执行：在第一次触发后，后续转换自动连续启动 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_DMA_TRANSFER  ADC 规则组 - ADC 转换数据的 DMA 传输
  * @{
  */
#define LL_ADC_REG_DMA_TRANSFER_NONE       0x00000000U              /*!< ADC 转换结果不通过 DMA 传输 */
#define LL_ADC_REG_DMA_TRANSFER_UNLIMITED  (ADC_CR2_DMA)                        /*!< ADC 转换数据通过 DMA 传输，无限模式：无论传输了多少 DMA 数据 (ADC 转换次数)，DMA 传输请求都是无限的。此 ADC 模式旨在配合 DMA 循环模式使用。 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_SCAN_LENGTH  ADC 规则组 - 扫描序列长度
  * @{
  */
#define LL_ADC_REG_SEQ_SCAN_DISABLE        0x00000000U                                                 /*!< ADC 规则组扫描序列禁用 (相当于序列长度为 1：ADC 仅转换 1 个通道) */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS  (                                             ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 2 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS  (                              ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 3 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS  (                              ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 4 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS  (               ADC_SQR1_L_2                              ) /*!< ADC 规则组扫描序列使能，序列中包含 5 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS  (               ADC_SQR1_L_2                | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 6 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS  (               ADC_SQR1_L_2 | ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 7 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS  (               ADC_SQR1_L_2 | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 8 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS  (ADC_SQR1_L_3                                             ) /*!< ADC 规则组扫描序列使能，序列中包含 9 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS (ADC_SQR1_L_3                               | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 10 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS (ADC_SQR1_L_3                | ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 11 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS (ADC_SQR1_L_3                | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 12 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2                              ) /*!< ADC 规则组扫描序列使能，序列中包含 13 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2                | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 14 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 | ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 15 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 16 个通道 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_DISCONT_MODE  ADC 规则组 - 序列间断模式
  * @{
  */
#define LL_ADC_REG_SEQ_DISCONT_DISABLE     0x00000000U                                                                  /*!< ADC 规则组序列间断模式禁用 */
#define LL_ADC_REG_SEQ_DISCONT_1RANK       (                                                            ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 1 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_2RANKS      (                                        ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 2 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_3RANKS      (                    ADC_CR1_DISCNUM_1                     | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 3 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_4RANKS      (                    ADC_CR1_DISCNUM_1 | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 4 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_5RANKS      (ADC_CR1_DISCNUM_2                                         | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 5 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_6RANKS      (ADC_CR1_DISCNUM_2                     | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 6 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_7RANKS      (ADC_CR1_DISCNUM_2 | ADC_CR1_DISCNUM_1                     | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 7 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_8RANKS      (ADC_CR1_DISCNUM_2 | ADC_CR1_DISCNUM_1 | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 8 个通道 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_RANKS  ADC 规则组 - 序列排名
  * @{
  */
#define LL_ADC_REG_RANK_1                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_1_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 1 */
#define LL_ADC_REG_RANK_2                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_2_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 2 */
#define LL_ADC_REG_RANK_3                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_3_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 3 */
#define LL_ADC_REG_RANK_4                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_4_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 4 */
#define LL_ADC_REG_RANK_5                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_5_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 5 */
#define LL_ADC_REG_RANK_6                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_6_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 6 */
#define LL_ADC_REG_RANK_7                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_7_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 7 */
#define LL_ADC_REG_RANK_8                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_8_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 8 */
#define LL_ADC_REG_RANK_9                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_9_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 9 */
#define LL_ADC_REG_RANK_10                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_10_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 10 */
#define LL_ADC_REG_RANK_11                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_11_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 11 */
#define LL_ADC_REG_RANK_12                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_12_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 12 */
#define LL_ADC_REG_RANK_13                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_13_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 13 */
#define LL_ADC_REG_RANK_14                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_14_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 14 */
#define LL_ADC_REG_RANK_15                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_15_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 15 */
#define LL_ADC_REG_RANK_16                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_16_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 16 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIGGER_SOURCE  ADC 注入组 - 触发源
  * @{
  */
/* ADC 注入组外部触发源，适用于 ADC 实例: ADC1, ADC2, ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_INJ_TRIG_SOFTWARE           (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0) /*!< ADC 注入组转换触发源为内部：软件启动 (SW start)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM1_TRGO      0x00000000U                                                 /*!< ADC 注入组转换触发源来自外部 IP：TIM1 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM1_CH4       (ADC_CR2_JEXTSEL_0)                                         /*!< ADC 注入组转换触发源来自外部 IP：TIM1 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
/* ADC 注入组外部触发源，适用于 ADC 实例: ADC1, ADC2 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_INJ_TRIG_EXT_TIM2_TRGO      (ADC_CR2_JEXTSEL_1)                                         /*!< ADC 注入组转换触发源来自外部 IP：TIM2 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM2_CH1       (ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0)                     /*!< ADC 注入组转换触发源来自外部 IP：TIM2 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM3_CH4       (ADC_CR2_JEXTSEL_2)                                         /*!< ADC 注入组转换触发源来自外部 IP：TIM3 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM4_TRGO      (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_0)                     /*!< ADC 注入组转换触发源来自外部 IP：TIM4 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_EXTI_LINE15    (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1)                     /*!< ADC 注入组转换触发源来自外部 IP：外部中断线 15。触发边沿设置为上升沿 (默认设置)。 */
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/* 注意: TIM8_CH4 仅在大容量 和超大容量 设备的 ADC1 和 ADC2 上可用。    */
/* 注意: 要在 ADC1 或 ADC2 上使用 TIM8_TRGO，必须进行触发重映射。               */
/*       触发重映射必须在顶层完成 (请参考 AFIO 外设)。                          */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4        (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                          /*!< ADC 注入组转换触发源来自外部 IP：TIM8 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。仅在大容量和超大容量设备上可用。触发重映射必须在顶层完成 (请参考 AFIO 外设)。 */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC 注入组外部触发源，适用于 ADC 实例: ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_INJ_TRIG_EXT_TIM4_CH3        (LL_ADC_INJ_TRIG_EXT_TIM2_TRGO)                            /*!< ADC 注入组转换触发源来自外部 IP：TIM4 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH2        (LL_ADC_INJ_TRIG_EXT_TIM2_CH1)                             /*!< ADC 注入组转换触发源来自外部 IP：TIM8 通道 2 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3   (LL_ADC_INJ_TRIG_EXT_TIM3_CH4)                             /*!< ADC 注入组转换触发源来自外部 IP：TIM8 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM5_TRGO       (LL_ADC_INJ_TRIG_EXT_TIM4_TRGO)                            /*!< ADC 注入组转换触发源来自外部 IP：TIM5 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM5_CH4        (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                          /*!< ADC 注入组转换触发源来自外部 IP：TIM5 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIGGER_EDGE  ADC 注入组 - 触发边沿
  * @{
  */
#define LL_ADC_INJ_TRIG_EXT_RISING         ADC_CR2_JEXTTRIG                        /*!< ADC 注入组转换触发极性设置为上升沿 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIG_AUTO  ADC 注入组 - 自动触发模式
* @{
*/
#define LL_ADC_INJ_TRIG_INDEPENDENT        0x00000000U            /*!< ADC 注入组转换触发独立模式。如果 ADC 注入组触发源设置为外部触发，则必须使用此设置。 */
#define LL_ADC_INJ_TRIG_FROM_GRP_REGULAR   (ADC_CR1_JAUTO)        /*!< ADC 注入组转换触发来自 ADC 规则组。仅适用于注入组触发源设置为软件启动的情况，无需对 ADC 注入组转换启动或停止进行任何进一步操作：在这种情况下，ADC 注入组仅受 ADC 规则组控制。 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_SCAN_LENGTH  ADC注入组 - 序列扫描长度
  * @{
  */
#define LL_ADC_INJ_SEQ_SCAN_DISABLE        0x00000000U                     // 禁止ADC注入组序列扫描（等同于单通道转换：仅转换1个通道）
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS  (                ADC_JSQR_JL_0) // ADC注入组序列扫描使能，序列长度为2
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS  (ADC_JSQR_JL_1                ) // ADC注入组序列扫描使能，序列长度为3
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS  (ADC_JSQR_JL_1 | ADC_JSQR_JL_0) // ADC注入组序列扫描使能，序列长度为4
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_DISCONT_MODE  ADC注入组 - 序列间断模式
  * @{
  */
#define LL_ADC_INJ_SEQ_DISCONT_DISABLE     0x00000000U            // 禁止ADC注入组序列间断模式
#define LL_ADC_INJ_SEQ_DISCONT_1RANK       (ADC_CR1_JDISCEN)      // 使能ADC注入组序列间断模式，每次触发转换序列中的一个通道
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_RANKS  ADC注入组 - 序列排名
  * @{
  */
// 定义注入组的转换序列排名，包含数据寄存器偏移、偏移寄存器偏移和排名序号
#define LL_ADC_INJ_RANK_1                  (ADC_JDR1_REGOFFSET | ADC_JOFR1_REGOFFSET | 0x00000001U) // 注入组序列排名1
#define LL_ADC_INJ_RANK_2                  (ADC_JDR2_REGOFFSET | ADC_JOFR2_REGOFFSET | 0x00000002U) // 注入组序列排名2
#define LL_ADC_INJ_RANK_3                  (ADC_JDR3_REGOFFSET | ADC_JOFR3_REGOFFSET | 0x00000003U) // 注入组序列排名3
#define LL_ADC_INJ_RANK_4                  (ADC_JDR4_REGOFFSET | ADC_JOFR4_REGOFFSET | 0x00000004U) // 注入组序列排名4
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL_SAMPLINGTIME  通道 - 采样时间
  * @{
  */
// 定义ADC通道的采样时间，采样时间越长，输入阻抗匹配效果越好，但转换速度越慢
#define LL_ADC_SAMPLINGTIME_1CYCLE_5       0x00000000U                                              // 采样时间：1.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_7CYCLES_5      (ADC_SMPR2_SMP0_0)                                       // 采样时间：7.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_13CYCLES_5     (ADC_SMPR2_SMP0_1)                                       // 采样时间：13.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_28CYCLES_5     (ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)                    // 采样时间：28.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_41CYCLES_5     (ADC_SMPR2_SMP0_2)                                       // 采样时间：41.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_55CYCLES_5     (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_0)                    // 采样时间：55.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_71CYCLES_5     (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1)                    // 采样时间：71.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_239CYCLES_5    (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0) // 采样时间：239.5个ADC时钟周期
/**
  * @}
  */

/** @defgroup ADC_LL_EC_AWD_NUMBER 模拟看门狗 - 模拟看门狗编号
  * @{
  */
// 定义模拟看门狗编号，用于监控ADC转换结果是否超出设定阈值
#define LL_ADC_AWD1                        (ADC_AWD_CR1_CHANNEL_MASK  | ADC_AWD_CR1_REGOFFSET) // ADC模拟看门狗编号1
/**
  * @}
  */
/** @defgroup ADC_LL_EC_AWD_CHANNELS  模拟看门狗 - 监控通道
  * @{
  */

/* 模拟看门狗监控禁用 */
#define LL_ADC_AWD_DISABLE                 0x00000000U                                                                                   /*!< ADC模拟看门狗监控禁用 */

/* 监控所有通道：仅限常规通道组 */
#define LL_ADC_AWD_ALL_CHANNELS_REG        (                                                             ADC_CR1_AWDEN                 ) /*!< ADC模拟看门狗监控所有通道，仅限常规通道组转换 */

/* 监控所有通道：仅限注入通道组 */
#define LL_ADC_AWD_ALL_CHANNELS_INJ        (                                            ADC_CR1_JAWDEN                                 ) /*!< ADC模拟看门狗监控所有通道，仅限注入通道组转换 */

/* 监控所有通道：常规通道组或注入通道组 */
#define LL_ADC_AWD_ALL_CHANNELS_REG_INJ    (                                            ADC_CR1_JAWDEN | ADC_CR1_AWDEN                 ) /*!< ADC模拟看门狗监控所有通道，常规通道组或注入通道组转换均可 */

/* 监控通道0：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_0_REG           ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN0，仅限常规通道组转换 */

/* 监控通道0：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_0_INJ           ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN0，仅限注入通道组转换 */

/* 监控通道0：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_0_REG_INJ       ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN0，常规通道组或注入通道组转换均可 */

/* 监控通道1：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_1_REG           ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN1，仅限常规通道组转换 */

/* 监控通道1：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_1_INJ           ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN1，仅限注入通道组转换 */

/* 监控通道1：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_1_REG_INJ       ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN1，常规通道组或注入通道组转换均可 */

/* 监控通道2：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_2_REG           ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN2，仅限常规通道组转换 */

/* 监控通道2：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_2_INJ           ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN2，仅限注入通道组转换 */

/* 监控通道2：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_2_REG_INJ       ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN2，常规通道组或注入通道组转换均可 */

/* 监控通道3：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_3_REG           ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN3，仅限常规通道组转换 */

/* 监控通道3：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_3_INJ           ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN3，仅限注入通道组转换 */

/* 监控通道3：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_3_REG_INJ       ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN3，常规通道组或注入通道组转换均可 */

/* 监控通道4：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_4_REG           ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN4，仅限常规通道组转换 */

/* 监控通道4：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_4_INJ           ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN4，仅限注入通道组转换 */

/* 监控通道4：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_4_REG_INJ       ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN4，常规通道组或注入通道组转换均可 */

/* 监控通道5：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_5_REG           ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN5，仅限常规通道组转换 */

/* 监控通道5：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_5_INJ           ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN5，仅限注入通道组转换 */

/* 监控通道5：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_5_REG_INJ       ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN5，常规通道组或注入通道组转换均可 */

/* 监控通道6：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_6_REG           ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN6，仅限常规通道组转换 */

/* 监控通道6：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_6_INJ           ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN6，仅限注入通道组转换 */

/* 监控通道6：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_6_REG_INJ       ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN6，常规通道组或注入通道组转换均可 */

/* 监控通道7：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_7_REG           ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN7，仅限常规通道组转换 */

/* 监控通道7：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_7_INJ           ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN7，仅限注入通道组转换 */

/* 监控通道7：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_7_REG_INJ       ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN7，常规通道组或注入通道组转换均可 */

/* 监控通道8：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_8_REG           ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN8，仅限常规通道组转换 */

/* 监控通道8：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_8_INJ           ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN8，仅限注入通道组转换 */

/* 监控通道8：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_8_REG_INJ       ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN8，常规通道组或注入通道组转换均可 */

/* 监控通道9：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_9_REG           ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN9，仅限常规通道组转换 */

/* 监控通道9：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_9_INJ           ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN9，仅限注入通道组转换 */

/* 监控通道9：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_9_REG_INJ       ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN9，常规通道组或注入通道组转换均可 */

/* 监控通道10：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_10_REG          ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN10，仅限常规通道组转换 */

/* 监控通道10：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_10_INJ          ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN10，仅限注入通道组转换 */

/* 监控通道10：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_10_REG_INJ      ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN10，常规通道组或注入通道组转换均可 */

/* 监控通道11：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_11_REG          ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN11，仅限常规通道组转换 */

/* 监控通道11：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_11_INJ          ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN11，仅限注入通道组转换 */

/* 监控通道11：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_11_REG_INJ      ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN11，常规通道组或注入通道组转换均可 */

/* 监控通道12：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_12_REG          ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN12，仅限常规通道组转换 */

/* 监控通道12：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_12_INJ          ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN12，仅限注入通道组转换 */

/* 监控通道12：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_12_REG_INJ      ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN12，常规通道组或注入通道组转换均可 */

/* 监控通道13：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_13_REG          ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN13，仅限常规通道组转换 */

/* 监控通道13：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_13_INJ          ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN13，仅限注入通道组转换 */

/* 监控通道13：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_13_REG_INJ      ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN13，常规通道组或注入通道组转换均可 */

/* 监控通道14：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_14_REG          ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN14，仅限常规通道组转换 */

/* 监控通道14：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_14_INJ          ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN14，仅限注入通道组转换 */

/* 监控通道14：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_14_REG_INJ      ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN14，常规通道组或注入通道组转换均可 */

/* 监控通道15：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_15_REG          ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN15，仅限常规通道组转换 */

/* 监控通道15：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_15_INJ          ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN15，仅限注入通道组转换 */

/* 监控通道15：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_15_REG_INJ      ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN15，常规通道组或注入通道组转换均可 */

/* 监控通道16：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_16_REG          ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN16，仅限常规通道组转换 */

/* 监控通道16：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_16_INJ          ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN16，仅限注入通道组转换 */

/* 监控通道16：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_16_REG_INJ      ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN16，常规通道组或注入通道组转换均可 */

/* 监控通道17：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_17_REG          ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN17，仅限常规通道组转换 */

/* 监控通道17：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_17_INJ          ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN17，仅限注入通道组转换 */

/* 监控通道17：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_17_REG_INJ      ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN17，常规通道组或注入通道组转换均可 */

/* 监控内部通道VrefInt：仅限常规通道组 */
#define LL_ADC_AWD_CH_VREFINT_REG          ((LL_ADC_CHANNEL_VREFINT    & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道VrefInt：内部参考电压，仅限常规通道组转换 */

/* 监控内部通道VrefInt：仅限注入通道组 */
#define LL_ADC_AWD_CH_VREFINT_INJ          ((LL_ADC_CHANNEL_VREFINT    & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道VrefInt：内部参考电压，仅限注入通道组转换 */

/* 监控内部通道VrefInt：常规通道组或注入通道组 */
#define LL_ADC_AWD_CH_VREFINT_REG_INJ      ((LL_ADC_CHANNEL_VREFINT    & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道VrefInt：内部参考电压，常规通道组或注入通道组转换均可 */

/* 监控内部通道温度传感器：仅限常规通道组 */
#define LL_ADC_AWD_CH_TEMPSENSOR_REG       ((LL_ADC_CHANNEL_TEMPSENSOR & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道温度传感器，仅限常规通道组转换 */

/* 监控内部通道温度传感器：仅限注入通道组 */
#define LL_ADC_AWD_CH_TEMPSENSOR_INJ       ((LL_ADC_CHANNEL_TEMPSENSOR & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道温度传感器，仅限注入通道组转换 */

/* 监控内部通道温度传感器：常规通道组或注入通道组 */
#define LL_ADC_AWD_CH_TEMPSENSOR_REG_INJ   ((LL_ADC_CHANNEL_TEMPSENSOR & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道温度传感器，常规通道组或注入通道组转换均可 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_AWD_THRESHOLDS  模拟看门狗 - 阈值
  * @{
  */
/* 模拟看门狗高阈值 */
#define LL_ADC_AWD_THRESHOLD_HIGH          (ADC_AWD_TR1_HIGH_REGOFFSET) /*!< ADC模拟看门狗高阈值 */

/* 模拟看门狗低阈值 */
#define LL_ADC_AWD_THRESHOLD_LOW           (ADC_AWD_TR1_LOW_REGOFFSET)  /*!< ADC模拟看门狗低阈值 */
/**
  * @}
  */
#if !defined(ADC_MULTIMODE_SUPPORT)
/** @defgroup ADC_LL_EC_MULTI_MODE 多重模式 - 模式
  * @{
  */
// 独立模式：ADC双模式禁用（ADC工作在独立模式）
#define LL_ADC_MULTI_INDEPENDENT              0x00000000U                                                         /*!< ADC dual mode disabled (ADC independent mode) */
/**
  * @}
  */
#endif
#if defined(ADC_MULTIMODE_SUPPORT)
/** @defgroup ADC_LL_EC_MULTI_MODE  多重模式 - 模式
  * @{
  */
// 独立模式：ADC双模式禁用（ADC工作在独立模式）
#define LL_ADC_MULTI_INDEPENDENT              0x00000000U                                                                     /*!< ADC dual mode disabled (ADC independent mode) */
// 双重模式：规则组同时采样模式
#define LL_ADC_MULTI_DUAL_REG_SIMULT          (                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    ) /*!< ADC dual mode enabled: group regular simultaneous */
// 双重模式：规则组快速交错模式（采样相位间隔：7个ADC时钟周期）
#define LL_ADC_MULTI_DUAL_REG_INTERL_FAST     (                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: Combined group regular interleaved fast (delay between ADC sampling phases: 7 ADC clock cycles) (equivalent to multimode sampling delay set to "LL_ADC_MULTI_TWOSMP_DELAY_7CYCLES" on other STM32 devices)) */
// 双重模式：规则组慢速交错模式（采样相位间隔：14个ADC时钟周期）
#define LL_ADC_MULTI_DUAL_REG_INTERL_SLOW     (ADC_CR1_DUALMOD_3                                                            ) /*!< ADC dual mode enabled: Combined group regular interleaved slow (delay between ADC sampling phases: 14 ADC clock cycles) (equivalent to multimode sampling delay set to "LL_ADC_MULTI_TWOSMP_DELAY_14CYCLES" on other STM32 devices)) */
// 双重模式：注入组同时采样模式
#define LL_ADC_MULTI_DUAL_INJ_SIMULT          (                    ADC_CR1_DUALMOD_2                     | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: group injected simultaneous slow (delay between ADC sampling phases: 14 ADC clock cycles) (equivalent to multimode sampling delay set to "LL_ADC_MULTI_TWOSMP_DELAY_14CYCLES" on other STM32 devices)) */
// 双重模式：注入组交替触发模式（仅适用于外部触发，不适用于内部软件启动）
#define LL_ADC_MULTI_DUAL_INJ_ALTERN          (ADC_CR1_DUALMOD_3                                         | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: group injected alternate trigger. Works only with external triggers (not internal SW start) */
// 双重模式：规则组同时采样 + 注入组同时采样
#define LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM     (                                                            ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected simultaneous */
// 双重模式：规则组同时采样 + 注入组交替触发
#define LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT     (                                        ADC_CR1_DUALMOD_1                    ) /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected alternate trigger */
// 双重模式：规则组快速交错 + 注入组同时采样
#define LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM (                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: Combined group regular interleaved fast (delay between ADC sampling phases: 7 ADC clock cycles) + group injected simultaneous */
// 双重模式：规则组慢速交错 + 注入组同时采样
#define LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM (                    ADC_CR1_DUALMOD_2                                        ) /*!< ADC dual mode enabled: Combined group regular interleaved slow (delay between ADC sampling phases: 14 ADC clock cycles) + group injected simultaneous */

/**
  * @}
  */

/** @defgroup ADC_LL_EC_MULTI_MASTER_SLAVE  多重模式 - ADC主从模式选择
  * @{
  */
// 多重模式下的数据选择：选择ADC主模式数据
#define LL_ADC_MULTI_MASTER                (                  ADC_DR_DATA) /*!< In multimode, selection among several ADC instances: ADC master */
// 多重模式下的数据选择：选择ADC从模式数据（ADC2）
#define LL_ADC_MULTI_SLAVE                 (ADC_DR_ADC2DATA              ) /*!< In multimode, selection among several ADC instances: ADC slave */
// 多重模式下的数据选择：同时选择ADC主模式和从模式数据
#define LL_ADC_MULTI_MASTER_SLAVE          (ADC_DR_ADC2DATA | ADC_DR_DATA) /*!< In multimode, selection among several ADC instances: both ADC master and ADC slave */
/**
  * @}
  */

#endif /* ADC_MULTIMODE_SUPPORT */


/** @defgroup ADC_LL_EC_HW_DELAYS  ADC硬件约束延时定义
  * @note   只有ADC IP硬件延时在ADC LL驱动中定义，
  *         不包括超时值。
  *         关于延时值的详细信息，请参考源代码中
  *         每个字面量定义上方的描述。
  * @{
  */
  
/* 注意：ADC LL驱动中仅定义了ADC IP硬件延时，           */
/*       不包括超时值。                                                  */
/*       ADC操作的超时值取决于设备时钟配置      */
/*       （系统时钟与ADC时钟），                       */
/*       因此必须在用户应用程序中定义。                   */
/*       此STM32系列ADC超时延时的估算指示：           */
/*       - ADC使能时间：最大延时为1us                              */
/*         （参考设备数据手册，参数 "tSTAB"）                     */
/*       - ADC转换时间：持续时间取决于ADC时钟和ADC配置       */
/*         （参考设备参考手册，“时序”部分）               */

/* 温度传感器稳定时间的延时。                           */
/* 字面量设置为最大值（参考设备数据手册，                   */
/* 参数 "tSTART"）。                                                       */
/* 单位: us                                                                   */
// 内部参考电压稳定时间的延时（单位：微秒）
#define LL_ADC_DELAY_TEMPSENSOR_STAB_US       (10U)  /*!< Delay for internal voltage reference stabilization time */

/* ADC禁用与ADC校准开始之间所需的延时。              */
/* 注意：在此STM32系列上，开始校准前，                  */
/*       ADC必须处于禁用状态。                                                */
/*       ADC禁用状态与校准开始之间需要最少数量的ADC时钟周期                    */
/*       参考字面量 @ref LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES.          */
/*       用户应用程序中可以通过等待等效的CPU周期数来计算等待时间，     */
/*       需考虑CPU时钟与ADC时钟预分频器的比率。                      */
/* 单位: ADC时钟周期。                                                    */
// ADC禁用与ADC校准开始之间所需的延时（单位：ADC时钟周期）
#define LL_ADC_DELAY_DISABLE_CALIB_ADC_CYCLES  (2U)  /*!< Delay required between ADC disable and ADC calibration start */

/* ADC使能结束与ADC校准开始之间所需的延时。 */
/* 注意：在此STM32系列上，ADC使能结束与校准开始之间            */
/*       需要最少数量的ADC时钟周期。            */
/*       用户应用程序中可以通过等待等效的CPU周期数来计算等待时间，     */
/*       需考虑CPU时钟与ADC时钟预分频器的比率。                      */
/* 单位: ADC时钟周期。                                                    */
// ADC使能结束与ADC校准开始之间所需的延时（单位：ADC时钟周期）
#define LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES  (2U)  /*!< Delay required between end of ADC enable and the start of ADC calibration */

/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Macros ADC导出宏
  * @{
  */

/** @defgroup ADC_LL_EM_WRITE_READ 通用读写寄存器宏
  * @{
  */

/**
  * @brief  向ADC寄存器写入值
  * @param  __INSTANCE__ ADC实例
  * @param  __REG__ 要写入的寄存器
  * @param  __VALUE__ 要写入寄存器的值
  * @retval 无
  */
// 写ADC寄存器宏：将值写入指定ADC实例的指定寄存器
#define LL_ADC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  读取ADC寄存器中的值
  * @param  __INSTANCE__ ADC实例
  * @param  __REG__ 要读取的寄存器
  * @retval 寄存器值
  */
// 读ADC寄存器宏：读取指定ADC实例的指定寄存器的值
#define LL_ADC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup ADC_LL_EM_HELPER_MACRO ADC辅助宏
  * @{
  */

/**
  * @brief  辅助宏：将LL_ADC_CHANNEL_x字面量转换为十进制格式的ADC通道号
  * @note   示例：
  *           __LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_CHANNEL_4)
  *           将返回十进制数 "4"。
  * @note   输入可以是返回通道号的函数值，可以是数字定义
  *         也可以是位域定义（只能设置一位）。
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 介于 Min_Data=0 和 Max_Data=18 之间的值
  */
// 将通道定义转换为十进制通道号
#define __LL_ADC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)                                        \
  (((__CHANNEL__) & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)

/**
  * @brief  辅助宏：将十进制格式的数字转换为LL_ADC_CHANNEL_x字面量格式的ADC通道
  * @note   示例：
  *           __LL_ADC_DECIMAL_NB_TO_CHANNEL(4)
  *           将返回等同于 "LL_ADC_CHANNEL_4" 的数据。
  * @param  __DECIMAL_NB__: 介于 Min_Data=0 和 Max_Data=18 之间的值
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，
  *             与内部通道参数的比较应使用辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL() 进行。
  */
// 将十进制通道号转换为通道定义（包含寄存器偏移信息）
#define __LL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                                                          \
  (((__DECIMAL_NB__) <= 9U)                                                                                     \
    ? (                                                                                                         \
       ((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)                                       |        \
       (ADC_SMPR2_REGOFFSET | (((uint32_t) (3U * (__DECIMAL_NB__))) << ADC_CHANNEL_SMPx_BITOFFSET_POS))         \
      )                                                                                                         \
      :                                                                                                         \
      (                                                                                                         \
       ((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)                                              | \
       (ADC_SMPR1_REGOFFSET | (((uint32_t) (3U * ((__DECIMAL_NB__) - 10U))) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) \
      )                                                                                                         \
  )

/**
  * @brief  辅助宏：确定所选通道是否对应于驱动程序的字面量定义。
  * @note   ADC通道的不同字面量定义包括：
  *         - ADC内部通道：
  *           LL_ADC_CHANNEL_VREFINT, LL_ADC_CHANNEL_TEMPSENSOR, ...
  *         - ADC外部通道（连接到GPIO引脚的通道）：
  *           LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...
  * @note   通道参数必须是ADC内部通道字面量定义的值（LL_ADC_CHANNEL_VREFINT,
  *         LL_ADC_CHANNEL_TEMPSENSOR, ...），
  *         ADC外部通道（LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...），
  *         不能是从ADC寄存器返回通道号的函数值，
  *         因为内部和外部通道在ADC寄存器中共享相同的通道号。
  *         区别仅通过驱动程序的参数定义进行。
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 值 "0" 表示通道对应于ADC外部通道的参数定义（连接到GPIO引脚的通道）。
  *         值 "1" 表示通道对应于ADC内部通道的参数定义。
  */
// 判断是否为内部通道
#define __LL_ADC_IS_CHANNEL_INTERNAL(__CHANNEL__)                              \
  (((__CHANNEL__) & ADC_CHANNEL_ID_INTERNAL_CH_MASK) != 0U)

/**
  * @brief  辅助宏：将ADC内部通道的参数定义（LL_ADC_CHANNEL_VREFINT,
  *         LL_ADC_CHANNEL_TEMPSENSOR, ...）转换为其等效的ADC外部通道参数定义
  *         （LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...）。
  * @note   通道参数除了可以是ADC内部通道参数定义的值
  *         （LL_ADC_CHANNEL_VREFINT, LL_ADC_CHANNEL_TEMPSENSOR, ...），
  *         还可以是ADC外部通道参数定义的值
  *         （LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...）
  *         或从ADC寄存器返回通道号的函数值。
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  */
// 将内部通道定义转换为外部通道定义（清除内部通道标志位）
#define __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL(__CHANNEL__)                     \
  ((__CHANNEL__) & ~ADC_CHANNEL_ID_INTERNAL_CH_MASK)

/**
  * @brief  辅助宏：确定所选内部通道在所选ADC实例上是否可用。
  * @note   通道参数必须是ADC内部通道参数定义的值（LL_ADC_CHANNEL_VREFINT,
  *         LL_ADC_CHANNEL_TEMPSENSOR, ...），
  *         不能是ADC外部通道参数定义的值（LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...）
  *         或从ADC寄存器返回通道号的函数值，
  *         因为内部和外部通道在ADC寄存器中共享相同的通道号。
  *         区别仅通过驱动程序的参数定义进行。
  * @param  __ADC_INSTANCE__ ADC实例
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 值 "0" 表示所选内部通道在所选ADC实例上不可用。
  *         值 "1" 表示所选内部通道在所选ADC实例上可用。
  */
// 判断指定的ADC实例是否支持指定的内部通道
#define __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  (((__ADC_INSTANCE__) == ADC1)                                                \
    ? (                                                                        \
       ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)    ||                         \
       ((__CHANNEL__) == LL_ADC_CHANNEL_TEMPSENSOR)                            \
      )                                                                        \
      :                                                                        \
      (0U)                                                                     \
  )
/**
  * @brief  辅助宏：用于定义ADC模拟看门狗参数。
  *         从序列器通道和组定义中，指定一个单独的通道供模拟看门狗监控。
  * @note   需配合函数 @ref LL_ADC_SetAnalogWDMonitChannels() 使用。
  *         示例:
  *           LL_ADC_SetAnalogWDMonitChannels(
  *             ADC1, LL_ADC_AWD1,
  *             __LL_ADC_ANALOGWD_CHANNEL_GROUP(LL_ADC_CHANNEL4, LL_ADC_GROUP_REGULAR))
  * @param  __CHANNEL__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1) 内部参考电压通道
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1) 温度传感器通道
  *         
  *         (1) 在STM32F1系列上，此参数仅在ADC1实例上可用。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，
  *             与内部通道参数的比较需使用辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL()。
  * @param  __GROUP__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_GROUP_REGULAR        常规通道组
  *         @arg @ref LL_ADC_GROUP_INJECTED       注入通道组
  *         @arg @ref LL_ADC_GROUP_REGULAR_INJECTED 常规和注入通道组
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_DISABLE          禁用模拟看门狗
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG 所有常规通道使能模拟看门狗
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_INJ 所有注入通道使能模拟看门狗
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG_INJ 所有常规和注入通道使能模拟看门狗
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG    通道0常规组模拟看门狗
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_INJ    通道0注入组模拟看门狗
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG_INJ 通道0常规和注入组模拟看门狗
  *         (此处省略部分通道枚举值，含义同上，格式为: 通道X_组别)
  *         (1) 在STM32F1系列上，此参数仅在ADC1实例上可用。
  */
/* 定义模拟看门狗通道组配置宏 */
#define __LL_ADC_ANALOGWD_CHANNEL_GROUP(__CHANNEL__, __GROUP__)                                           \
  (((__GROUP__) == LL_ADC_GROUP_REGULAR)                                                                  \
    ? (((__CHANNEL__) & ADC_CHANNEL_ID_MASK) | ADC_CR1_AWDEN | ADC_CR1_AWDSGL)                            \
      /* 如果是常规组：提取通道号，使能常规组看门狗(AWDEN)，使能单通道模式(AWDSGL) */       \
      :                                                                                                   \
      ((__GROUP__) == LL_ADC_GROUP_INJECTED)                                                              \
       ? (((__CHANNEL__) & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDSGL)                        \
         /* 如果是注入组：提取通道号，使能注入组看门狗(JAWDEN)，使能单通道模式(AWDSGL) */   \
         :                                                                                                \
         (((__CHANNEL__) & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL)        \
         /* 如果是常规+注入组：提取通道号，同时使能常规和注入组看门狗，使能单通道模式 */    \
  )

/**
  * @brief  辅助宏：用于根据ADC分辨率设置模拟看门狗的高或低阈值。
  *         当ADC分辨率不是12位时使用（用于兼容其他STM32系列）。
  * @note   需配合函数 @ref LL_ADC_SetAnalogWDThresholds() 使用。
  *         示例，ADC分辨率为8位时，设置模拟看门狗高阈值（8位值）:
  *           LL_ADC_SetAnalogWDThresholds
  *            (< ADCx param >,
  *             __LL_ADC_ANALOGWD_SET_THRESHOLD_RESOLUTION(LL_ADC_RESOLUTION_8B, <threshold_value_8_bits>)
  *            );
  * @param  __ADC_RESOLUTION__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_RESOLUTION_12B     12位分辨率
  * @param  __AWD_THRESHOLD__ 阈值范围: Min_Data=0x000, Max_Data=0xFFF
  * @retval 返回处理后的阈值范围: Min_Data=0x000, Max_Data=0xFFF
  */
/* 注意: 在STM32F1系列中，ADC固定为12位分辨率。                           */
/*       保留此宏是为了兼容其他具有不同ADC分辨率的STM32系列。               */
#define __LL_ADC_ANALOGWD_SET_THRESHOLD_RESOLUTION(__ADC_RESOLUTION__, __AWD_THRESHOLD__) \
  ((__AWD_THRESHOLD__) << (0U)) // F1系列固定12位，无需移位，直接返回原值

/**
  * @brief  辅助宏：用于根据ADC分辨率获取模拟看门狗的高或低阈值。
  *         当ADC分辨率不是12位时使用（用于兼容其他STM32系列）。
  * @note   需配合函数 @ref LL_ADC_GetAnalogWDThresholds() 使用。
  *         示例，ADC分辨率为8位时，获取模拟看门狗高阈值（8位值）:
  *           < threshold_value_6_bits > = __LL_ADC_ANALOGWD_GET_THRESHOLD_RESOLUTION
  *            (LL_ADC_RESOLUTION_8B,
  *             LL_ADC_GetAnalogWDThresholds(<ADCx param>, LL_ADC_AWD_THRESHOLD_HIGH)
  *            );
  * @param  __ADC_RESOLUTION__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_RESOLUTION_12B
  * @param  __AWD_THRESHOLD_12_BITS__ 12位格式的阈值数据 (范围: 0x000 to 0xFFF)
  * @retval 返回转换后的阈值数据 (范围: 0x000 to 0xFFF)
  */
/* 注意: 在STM32F1系列中，ADC固定为12位分辨率。                           */
/*       保留此宏是为了兼容其他具有不同ADC分辨率的STM32系列。               */
#define __LL_ADC_ANALOGWD_GET_THRESHOLD_RESOLUTION(__ADC_RESOLUTION__, __AWD_THRESHOLD_12_BITS__) \
  (__AWD_THRESHOLD_12_BITS__) // F1系列固定12位，直接返回原值

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  辅助宏：从双ADC模式下的原始数据中提取主ADC或从ADC的转换数据。
  * @note   此宏用于多模式DMA传输场景。
  *         传输的数据包含主从ADC的数据，需要通过此宏分离。
  * @param  __ADC_MULTI_MASTER_SLAVE__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_MASTER   选择主ADC数据
  *         @arg @ref LL_ADC_MULTI_SLAVE    选择从ADC数据
  * @param  __ADC_MULTI_CONV_DATA__ 原始多模式转换数据 (范围: 0x000 to 0xFFF)
  * @retval 提取后的ADC转换数据 (范围: 0x000 to 0xFFF)
  */
/* 定义多模式转换数据提取宏 */
#define __LL_ADC_MULTI_CONV_DATA_MASTER_SLAVE(__ADC_MULTI_MASTER_SLAVE__, __ADC_MULTI_CONV_DATA__)  \
  (((__ADC_MULTI_CONV_DATA__) >> POSITION_VAL((__ADC_MULTI_MASTER_SLAVE__))) & ADC_DR_DATA)
  /* 实现原理：根据主从选择参数进行右移，然后与数据掩码相与，提取出对应的12位数据 */
#endif

/**
  * @brief  辅助宏：获取选定ADC实例所属的ADC公共实例。
  * @note   ADC公共寄存器实例可用于:
  *         - 设置多个ADC实例的公共参数
  *         - 多模式配置 (针对有多个ADC实例的设备)
  *         参考参数为 "ADCxy_COMMON" 的函数。
  * @note   在STM32F1系列中，没有专门的ADC公共实例寄存器。
  *         但是，ADC1实例充当了ADC1和ADC2的公共实例角色:
  *         用于管理内部通道和多模式(在其他STM32设备中由公共实例管理)。
  *         ADC3 (如果存在) 没有对应的ADC公共实例。
  * @param  __ADCx__ ADC实例 (如 ADC1, ADC2)
  * @retval ADC公共寄存器实例 (如 ADC12_COMMON)
  */
#if defined(ADC1) && defined(ADC2) && defined(ADC3)
/* 如果定义了ADC1, ADC2, ADC3 */
#define __LL_ADC_COMMON_INSTANCE(__ADCx__)                                     \
  ((((__ADCx__) == ADC1) || ((__ADCx__) == ADC2))                              \
    ? (                                                                        \
       (ADC12_COMMON)                                                          \
      )                                                                        \
      /* 如果是ADC1或ADC2，返回ADC12公共实例 */                                \
      :                                                                        \
      (                                                                        \
       (0U)                                                                    \
      )                                                                        \
      /* 如果是ADC3，返回0 (F1系列ADC3无公共实例) */                           \
  )
#elif defined(ADC1) && defined(ADC2)
/* 如果只定义了ADC1, ADC2 */
#define __LL_ADC_COMMON_INSTANCE(__ADCx__)                                     \
  (ADC12_COMMON) // 直接返回ADC12公共实例
#else
/* 如果只有一个ADC1 */
#define __LL_ADC_COMMON_INSTANCE(__ADCx__)                                     \
  (ADC1_COMMON) // 返回ADC1公共实例
#endif

/**
  * @brief  辅助宏：检查共享同一ADC公共实例的所有ADC实例是否都处于禁用状态。
  * @note   某些配置函数要求ADC处于特定状态才能设置：
  *         ADC公共组内的所有ADC实例必须禁用。
  *         参考参数为 "ADCxy_COMMON" 的函数。
  * @note   在只有一个ADC公共实例的设备上，此宏的参数无用(保留是为了兼容)。
  * @note   在STM32F1系列中，ADC1充当ADC1和ADC2的公共实例。
  *         ADC3 (如果存在) 没有ADC公共实例。
  * @param  __ADCXY_COMMON__ ADC公共实例
  *         (可直接使用CMSIS定义或通过宏 @ref __LL_ADC_COMMON_INSTANCE() 获取)
  * @retval 返回 "0": 所有共享该公共实例的ADC都已禁用。
  *         返回 "1": 至少有一个共享该公共实例的ADC已使能。
  */
#if defined(ADC1) && defined(ADC2) && defined(ADC3)
/* 定义检查所有公共实例是否禁用的宏 (适用于ADC1,2,3场景) */
#define __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  (((__ADCXY_COMMON__) == ADC12_COMMON)                                        \
    ? (                                                                        \
       (LL_ADC_IsEnabled(ADC1) |                                               \
        LL_ADC_IsEnabled(ADC2)  )                                              \
      )                                                                        \
      /* 如果是ADC12公共组，检查ADC1或ADC2是否使能 */                          \
      :                                                                        \
      (                                                                        \
       LL_ADC_IsEnabled(ADC3)                                                  \
      )                                                                        \
      /* 否则检查ADC3是否使能 */                                               \
  )
#elif defined(ADC1) && defined(ADC2)
/* 定义检查所有公共实例是否禁用的宏 (适用于ADC1,2场景) */
#define __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  (LL_ADC_IsEnabled(ADC1) |                                                    \
   LL_ADC_IsEnabled(ADC2)  ) // 检查ADC1或ADC2是否使能
#else
/* 定义检查所有公共实例是否禁用的宏 (适用于单ADC场景) */
#define __LL_ADC_IS_ENABLED_ALL_COMMON_INSTANCE(__ADCXY_COMMON__)              \
  LL_ADC_IsEnabled(ADC1) // 仅检查ADC1是否使能
#endif

/**
  * @brief  辅助宏：定义对应所选ADC分辨率的转换数据满量程数字值。
  * @note   ADC转换数据满量程对应于由模拟参考电压 Vref+ 和 Vref- 决定的电压范围。
  * @param  __ADC_RESOLUTION__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_RESOLUTION_12B
  * @retval ADC转换数据对应的满量程值 (对于12位ADC，通常为 0xFFF = 4095)
  */
#define __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__)                             \
  (0xFFFU) // STM32F1固定为12位分辨率，满量程值为0xFFF


/**
  * @brief  辅助宏：计算ADC转换数据对应的电压值 (单位: mV)。
  * @note   模拟参考电压 必须已知，或者可以通过ADC测量计算得出。
  * @param  __VREFANALOG_VOLTAGE__ 模拟参考电压 (单位: mV)
  * @param  __ADC_DATA__ ADC转换数据 (12位分辨率) (单位: 数字值)。
  * @param  __ADC_RESOLUTION__ 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_RESOLUTION_12B
  * @retval ADC转换数据对应的电压值 (单位: mV)
  */
/* 电压计算公式: 电压 = (数字值 * 参考电压) / 满量程值 */
#define __LL_ADC_CALC_DATA_TO_VOLTAGE(__VREFANALOG_VOLTAGE__,\
                                      __ADC_DATA__,\
                                      __ADC_RESOLUTION__)                      \
  ((__ADC_DATA__) * (__VREFANALOG_VOLTAGE__)                                   \
   / __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__)                                \
  )

/**
  * @brief  辅助宏：根据内部温度传感器的ADC转换数据计算温度（单位：摄氏度）
  * @note   计算过程使用了温度传感器的典型值（请参阅器件数据手册）。
  * @note   计算公式：
  *           温度 = (TS_TYP_CALx_VOLT(uV) - TS_ADC_DATA * Conversion_uV)
  *                         / Avg_Slope + CALx_TEMP
  *           其中 TS_ADC_DATA      = ADC测量的温度传感器原始数据
  *                                   (单位：数字值)
  *                Avg_Slope        = 温度传感器斜率
  *                                   (单位：微伏/摄氏度)
  *                TS_TYP_CALx_VOLT = 温度为CALx_TEMP时的温度传感器数字值
  *                                   (单位：毫伏)
  *         注意：计算结果的有效性取决于当前器件的温度传感器特性是否与
  *                  数据手册中的典型值一致。
  *                  如果当前器件具备温度传感器校准值（即存在宏 __LL_ADC_CALC_TEMPERATURE()），
  *                  使用辅助宏 @ref __LL_ADC_CALC_TEMPERATURE() 计算温度会更准确。
  * @note   作为计算输入，必须定义模拟参考电压，因为它会影响ADC的LSB等效电压。
  * @note   模拟参考电压必须通过用户板级环境获知，或者可以通过ADC测量计算得出。
  * @note   ADC测量数据必须对应12位分辨率（满量程数字值4095）。
  *         如果不是这种情况，必须预先将数据重新缩放到等效的12位分辨率。
  * @param  __TEMPSENSOR_TYP_AVGSLOPE__   器件数据手册数据：温度传感器斜率典型值 (单位: uV/摄氏度)。
  *                                       在STM32F1上，请参考数据手册参数 "Avg_Slope"。
  * @param  __TEMPSENSOR_TYP_CALX_V__     器件数据手册数据：温度传感器电压典型值（在下面参数定义的温度和Vref+下）(单位: mV)。
  *                                       在STM32F1上，请参考数据手册参数 "V25"。
  * @param  __TEMPSENSOR_CALX_TEMP__      器件数据手册数据：温度传感器电压（见上参数）所对应的温度 (单位: mV)
  * @param  __VREFANALOG_VOLTAGE__        模拟电压参考电压 (单位: mV)
  * @param  __TEMPSENSOR_ADC_DATA__       内部温度传感器的ADC转换数据 (单位: 数字值)。
  * @param  __ADC_RESOLUTION__            测量内部温度传感器电压时的ADC分辨率。
  *         该参数可以是以下值之一：
  *         @arg @ref LL_ADC_RESOLUTION_12B
  * @retval 温度 (单位: 摄氏度)
  */
#define __LL_ADC_CALC_TEMPERATURE_TYP_PARAMS(__TEMPSENSOR_TYP_AVGSLOPE__,\
                                             __TEMPSENSOR_TYP_CALX_V__,\
                                             __TEMPSENSOR_CALX_TEMP__,\
                                             __VREFANALOG_VOLTAGE__,\
                                             __TEMPSENSOR_ADC_DATA__,\
                                             __ADC_RESOLUTION__)               \
  ((( (                                                                        \
       (int32_t)(((__TEMPSENSOR_TYP_CALX_V__))                                 \
                 * 1000)                                                       \
       -                                                                       \
       (int32_t)((((__TEMPSENSOR_ADC_DATA__) * (__VREFANALOG_VOLTAGE__))       \
                  / __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__))                \
                 * 1000)                                                       \
      )                                                                        \
    ) / (__TEMPSENSOR_TYP_AVGSLOPE__)                                          \
   ) + (__TEMPSENSOR_CALX_TEMP__)                                              \
  )

/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Functions ADC导出函数
  * @{
  */

/** @defgroup ADC_LL_EF_DMA_Management ADC DMA管理
  * @{
  */
/* 注意：用于设置DMA传输的LL ADC函数位于ADC实例、组和多模（如果可用）的配置部分：*/
/*       @ref LL_ADC_REG_SetDMATransfer(), ...                                */

/**
  * @brief  辅助配置从ADC进行DMA传输的函数：从ADC实例检索ADC寄存器地址
  *         以及旨在（最常）用于DMA传输的ADC寄存器列表。
  * @note   这些ADC寄存器是数据寄存器：
  *         当ADC转换数据在ADC数据寄存器中可用时，ADC会生成DMA传输请求。
  * @note   此宏旨在与LL DMA驱动程序一起使用，请参考函数 "LL_DMA_ConfigAddresses()"。
  *         示例：
  *           LL_DMA_ConfigAddresses(DMA1,
  *                                  LL_DMA_CHANNEL_1,
  *                                  LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
  *                                  (uint32_t)&< 数组或变量 >,
  *                                  LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  * @note   对于具有多个ADC的器件：在多模模式下，某些器件使用ADC实例范围之外的不同数据寄存器
  *         （公共数据寄存器）。此宏管理此寄存器差异，只需将ADC实例设置为参数即可。
  * @note   在STM32F1上，只有ADC1和ADC3实例具有DMA传输功能，ADC2没有
  *         （并非所有器件都有ADC2和ADC3实例）。
  * @note   在STM32F1上，多模只能与ADC1和ADC2一起使用，不能与ADC3一起使用。
  *         因此，多模数据传输的相应参数只能与ADC1和ADC2一起使用。
  *         （并非所有器件都有ADC2和ADC3实例）。
  * @rmtoll DR       DATA           LL_ADC_DMA_GetRegAddr
  * @param  ADCx ADC实例
  * @param  Register 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_DMA_REG_REGULAR_DATA
  *         @arg @ref LL_ADC_DMA_REG_REGULAR_DATA_MULTI (1)
  *         
  *         (1) 适用于具有多个ADC实例的器件。
  * @retval ADC寄存器地址
  */
#if defined(ADC_MULTIMODE_SUPPORT)
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  uint32_t data_reg_addr = 0U;
  
  if (Register == LL_ADC_DMA_REG_REGULAR_DATA)
  {
    /* 检索寄存器DR的地址 */
    data_reg_addr = (uint32_t)&(ADCx->DR);
  }
  else /* (Register == LL_ADC_DMA_REG_REGULAR_DATA_MULTI) */
  {
    /* 检索多模数据寄存器的地址 */
    data_reg_addr = (uint32_t)&(ADC12_COMMON->DR);
  }
  
  return data_reg_addr;
}
#else
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  /* 检索寄存器DR的地址 */
  return (uint32_t)&(ADCx->DR);
}
#endif

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Common 配置ADC层级范围：多个ADC实例的通用设置
  * @{
  */

/**
  * @brief  设置多个ADC的通用参数：内部通道的测量路径
  *         (内部参考电压VrefInt, 温度传感器, ...)。
  * @note   可以选择一个或多个值。
  *         示例: (LL_ADC_PATH_INTERNAL_VREFINT |
  *                   LL_ADC_PATH_INTERNAL_TEMPSENSOR)
  * @note   内部通道测量路径的稳定时间：
  *         使能内部路径后，在启动ADC转换之前，
  *         需要一段延迟时间用于内部参考电压和
  *         温度传感器的稳定。
  *         请参考器件数据手册。
  *         请参考常量 @ref LL_ADC_DELAY_TEMPSENSOR_STAB_US。
  * @note   ADC内部通道采样时间约束：
  *         对于内部通道的ADC转换，
  *         需要满足最小采样时间要求。
  *         请参考器件数据手册。
  * @rmtoll CR2      TSVREFE        LL_ADC_SetCommonPathInternalCh
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置，或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  PathInternal 此参数可以是以下值的组合：
  *         @arg @ref LL_ADC_PATH_INTERNAL_NONE
  *         @arg @ref LL_ADC_PATH_INTERNAL_VREFINT
  *         @arg @ref LL_ADC_PATH_INTERNAL_TEMPSENSOR
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t PathInternal)
{
  /* 修改CR2寄存器的TSVREFE位，配置内部通道路径 */
  MODIFY_REG(ADCxy_COMMON->CR2, (ADC_CR2_TSVREFE), PathInternal);
}

/**
  * @brief  获取多个ADC的通用参数：内部通道的测量路径
  *         (内部参考电压VrefInt, 温度传感器, ...)。
  * @note   可以选择一个或多个值。
  *         示例: (LL_ADC_PATH_INTERNAL_VREFINT |
  *                   LL_ADC_PATH_INTERNAL_TEMPSENSOR)
  * @rmtoll CR2      TSVREFE        LL_ADC_GetCommonPathInternalCh
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置，或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 返回值可以是以下值的组合：
  *         @arg @ref LL_ADC_PATH_INTERNAL_NONE
  *         @arg @ref LL_ADC_PATH_INTERNAL_VREFINT
  *         @arg @ref LL_ADC_PATH_INTERNAL_TEMPSENSOR
  */
__STATIC_INLINE uint32_t LL_ADC_GetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 读取CR2寄存器的TSVREFE位，获取当前配置的内部通道路径 */
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CR2, ADC_CR2_TSVREFE));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Instance 配置ADC层级范围：ADC实例
  * @{
  */

/**
  * @brief  设置ADC转换数据对齐方式。
  * @note   请参考参考手册中关于对齐格式与ADC分辨率的依赖关系。
  * @rmtoll CR2      ALIGN          LL_ADC_SetDataAlignment
  * @param  ADCx ADC实例
  * @param  DataAlignment 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_DATA_ALIGN_RIGHT 右对齐
  *         @arg @ref LL_ADC_DATA_ALIGN_LEFT 左对齐
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetDataAlignment(ADC_TypeDef *ADCx, uint32_t DataAlignment)
{
  /* 修改CR2寄存器的ALIGN位，设置数据对齐方式 */
  MODIFY_REG(ADCx->CR2, ADC_CR2_ALIGN, DataAlignment);
}

/**
  * @brief  获取ADC转换数据对齐方式。
  * @note   请参考参考手册中关于对齐格式与ADC分辨率的依赖关系。
  * @rmtoll CR2      ALIGN          LL_ADC_SetDataAlignment
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_DATA_ALIGN_RIGHT
  *         @arg @ref LL_ADC_DATA_ALIGN_LEFT
  */
__STATIC_INLINE uint32_t LL_ADC_GetDataAlignment(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的ALIGN位，获取当前数据对齐方式 */
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_ALIGN));
}

/**
  * @brief  设置所有ADC组（规则组、注入组）的ADC序列器扫描模式。
  * @note  根据序列器扫描模式：
  *         - 如果禁用：ADC转换在单次转换模式下执行
  *           （转换一个通道，即在秩1中定义的通道）。
  *           所有ADC组的序列器配置（序列器扫描长度等）将被忽略：相当于
  *           扫描长度为1个秩。
  *         - 如果使能：ADC转换在序列转换模式下执行，
  *           根据每个ADC组的序列器配置（序列器扫描长度等）。
  *           请参考函数 @ref LL_ADC_REG_SetSequencerLength()
  *           和函数 @ref LL_ADC_INJ_SetSequencerLength()。
  * @rmtoll CR1      SCAN           LL_ADC_SetSequencersScanMode
  * @param  ADCx ADC实例
  * @param  ScanMode 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_SEQ_SCAN_DISABLE 禁用扫描模式
  *         @arg @ref LL_ADC_SEQ_SCAN_ENABLE 使能扫描模式
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetSequencersScanMode(ADC_TypeDef *ADCx, uint32_t ScanMode)
{
  /* 修改CR1寄存器的SCAN位，设置扫描模式 */
  MODIFY_REG(ADCx->CR1, ADC_CR1_SCAN, ScanMode);
}

/**
  * @brief  获取所有ADC组（规则组、注入组）的ADC序列器扫描模式。
  * @note  根据序列器扫描模式：
  *         - 如果禁用：ADC转换在单次转换模式下执行
  *           （转换一个通道，即在秩1中定义的通道）。
  *           所有ADC组的序列器配置（序列器扫描长度等）将被忽略：相当于
  *           扫描长度为1个秩。
  *         - 如果使能：ADC转换在序列转换模式下执行，
  *           根据每个ADC组的序列器配置（序列器扫描长度等）。
  *           请参考函数 @ref LL_ADC_REG_SetSequencerLength()
  *           和函数 @ref LL_ADC_INJ_SetSequencerLength()。
  * @rmtoll CR1      SCAN           LL_ADC_GetSequencersScanMode
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_SEQ_SCAN_ENABLE
  */
__STATIC_INLINE uint32_t LL_ADC_GetSequencersScanMode(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器的SCAN位，获取当前扫描模式状态 */
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_SCAN));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Group_Regular 配置ADC层级范围：规则组
  * @{
  */

/**
  * @brief  设置ADC规则组转换触发源：
  *         内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
  * @note   在此STM32系列上，外部触发设置为触发极性：上升沿
  *         （此STM32系列上唯一可用的触发极性）。
  * @note   来自定时器的触发源参数的可用性取决于所选器件上定时器的可用性。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_SetTriggerSource
  * @param  ADCx ADC实例
  * @param  TriggerSource 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_TRIG_SOFTWARE 软件触发
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH3       (1)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH1       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM4_CH4       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (2)(4)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH3       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH3       (3)
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1, ADC2, ADC3（针对所选器件上可用的ADC实例）。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1, ADC2（针对所选器件上可用的ADC实例）。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3（针对所选器件上可用的ADC实例）。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度器件。必须在顶层重映射触发（请参考AFIO外设）。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
/* 注意：在此STM32系列上，ADC规则组外部触发边沿用于执行ADC转换启动。        */
/*       此函数不设置外部触发边沿。                    */
/*       此功能使用函数设置：                                   */
/*       @ref LL_ADC_REG_StartConversionExtTrig().                            */
  /* 修改CR2寄存器的EXTSEL位，设置触发源 */
  MODIFY_REG(ADCx->CR2, ADC_CR2_EXTSEL, (TriggerSource & ADC_CR2_EXTSEL));
}

/**
  * @brief  获取ADC规则组转换触发源：
  *         内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
  * @note   要确定规则组触发源是内部（软件启动）还是外部，而不需要
  *         详细了解选择了哪个外设作为外部触发，
  *         （相当于 
  *         "if(LL_ADC_REG_GetTriggerSource(ADC1) == LL_ADC_REG_TRIG_SOFTWARE)"）
  *         请使用函数 @ref LL_ADC_REG_IsTriggerSourceSWStart。
  * @note   来自定时器的触发源参数的可用性取决于所选器件上定时器的可用性。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_GetTriggerSource
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH3       (1)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH1       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM4_CH4       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (2)(4)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH3       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH3       (3)
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1, ADC2, ADC3（针对所选器件上可用的ADC实例）。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1, ADC2（针对所选器件上可用的ADC实例）。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3（针对所选器件上可用的ADC实例）。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度器件。必须在顶层重映射触发（请参考AFIO外设）。
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetTriggerSource(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的EXTSEL位，获取当前触发源配置 */
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_EXTSEL));
}

/**
  * @brief  获取ADC规则组转换触发源是内部（软件启动）还是外部。
  * @note   如果规则组触发源设置为外部触发，
  *         要确定选择了哪个外设作为外部触发，
  *         请使用函数 @ref LL_ADC_REG_GetTriggerSource()。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_IsTriggerSourceSWStart
  * @param  ADCx ADC实例
  * @retval 值 "0" 表示触发源为外部触发
  *         值 "1" 表示触发源为软件启动。
  */
__STATIC_INLINE uint32_t LL_ADC_REG_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  /* 判断EXTSEL位是否等于软件触发宏定义值 */
  return (READ_BIT(ADCx->CR2, ADC_CR2_EXTSEL) == (LL_ADC_REG_TRIG_SOFTWARE));
}

/**
  * @brief  设置ADC常规组序列器的长度和扫描方向。
  * @note   ADC常规组序列器功能描述：
  *         - 对于序列器完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerRanks()" 可用):
  *           序列器长度和每个排名对应的通道
  *           都是可配置的。
  *           此函数执行以下配置：
  *           - 序列长度：扫描序列中的排名数量。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从排名1到排名n)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerRanks()"。
  *         - 对于序列器不完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerChannels()" 可用):
  *           序列器长度和每个排名对应的通道
  *           由通道编号定义。
  *           此函数执行以下配置：
  *           - 序列长度：扫描序列中的排名数量由
  *             序列中设置的通道数量定义，
  *             每个通道的排名由硬件通道号固定。
  *             (通道0固定在排名0，通道1固定在排名1，...)。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从最低通道号到
  *             最高通道号)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerChannels()"。
  * @note   在此STM32系列上，常规组序列器配置
  *         取决于ADC实例的序列器模式。
  *         如果ADC实例序列器模式被禁用，则
  *         所有组(常规组、注入组)的序列器可以被配置
  *         但其执行被禁用(仅限于排名1)。
  *         参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器等同于1个排名的序列器：
  *         仅在1个通道上进行ADC转换。
  * @rmtoll SQR1     L              LL_ADC_REG_SetSequencerLength
  * @param  ADCx ADC实例
  * @param  SequencerNbRanks 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  /* 修改ADCx->SQR1寄存器的L位，设置常规组序列器的转换通道数量 */
  MODIFY_REG(ADCx->SQR1, ADC_SQR1_L, SequencerNbRanks);
}

/**
  * @brief  获取ADC常规组序列器的长度和扫描方向。
  * @note   ADC常规组序列器功能描述：
  *         - 对于序列器完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerRanks()" 可用):
  *           序列器长度和每个排名对应的通道
  *           都是可配置的。
  *           此函数检索：
  *           - 序列长度：扫描序列中的排名数量。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从排名1到排名n)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerRanks()"。
  *         - 对于序列器不完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerChannels()" 可用):
  *           序列器长度和每个排名对应的通道
  *           由通道编号定义。
  *           此函数检索：
  *           - 序列长度：扫描序列中的排名数量由
  *             序列中设置的通道数量定义，
  *             每个通道的排名由硬件通道号固定。
  *             (通道0固定在排名0，通道1固定在排名1，...)。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从最低通道号到
  *             最高通道号)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerChannels()"。
  * @note   在此STM32系列上，常规组序列器配置
  *         取决于ADC实例的序列器模式。
  *         如果ADC实例序列器模式被禁用，则
  *         所有组(常规组、注入组)的序列器可以被配置
  *         但其执行被禁用(仅限于排名1)。
  *         参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器等同于1个排名的序列器：
  *         仅在1个通道上进行ADC转换。
  * @rmtoll SQR1     L              LL_ADC_REG_SetSequencerLength
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerLength(ADC_TypeDef *ADCx)
{
  /* 读取ADCx->SQR1寄存器的L位，获取常规组序列器的转换通道数量 */
  return (uint32_t)(READ_BIT(ADCx->SQR1, ADC_SQR1_L));
}

/**
  * @brief  设置ADC常规组序列器的不连续模式：
  *         序列被细分，每选定的排名数后扫描转换中断一次。
  * @note   不能同时启用ADC常规组连续模式和序列器不连续模式。
  * @note   不能同时启用ADC自动注入模式
  *         和ADC常规组序列器不连续模式。
  * @rmtoll CR1      DISCEN         LL_ADC_REG_SetSequencerDiscont\n
  *         CR1      DISCNUM        LL_ADC_REG_SetSequencerDiscont
  * @param  ADCx ADC实例
  * @param  SeqDiscont 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_1RANK
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_8RANKS
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  /* 修改ADCx->CR1寄存器，配置DISCEN(不连续模式使能)和DISCNUM(不连续模式通道数)位 */
  MODIFY_REG(ADCx->CR1, ADC_CR1_DISCEN | ADC_CR1_DISCNUM, SeqDiscont);
}

/**
  * @brief  获取ADC常规组序列器的不连续模式：
  *         序列被细分，每选定的排名数后扫描转换中断一次。
  * @rmtoll CR1      DISCEN         LL_ADC_REG_GetSequencerDiscont\n
  *         CR1      DISCNUM        LL_ADC_REG_GetSequencerDiscont
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_1RANK
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_8RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerDiscont(ADC_TypeDef *ADCx)
{
  /* 读取ADCx->CR1寄存器，获取不连续模式配置 */
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_DISCEN | ADC_CR1_DISCNUM));
}

/**
  * @brief  设置ADC常规组序列：选定扫描序列排名上的通道。
  * @note   此函数执行以下配置：
  *         - 通道在扫描序列每个排名中的排序：
  *           任何通道都可以放置在任何排名中。
  * @note   在此STM32系列上，ADC常规组序列器是
  *         完全可配置的：序列器长度和每个排名
  *         对应的通道都是可配置的。
  *         参考函数 @ref LL_ADC_REG_SetSequencerLength() 的描述。
  * @note   根据设备和封装，某些通道可能不可用。
  *         请参考设备数据手册了解通道可用性。
  * @note   在此STM32系列上，要测量内部通道(VrefInt,
  *         TempSensor, ...)，必须单独启用
  *         到内部通道的测量路径。
  *         这可以使用函数 @ref LL_ADC_SetCommonPathInternalCh() 完成。
  * @rmtoll SQR3     SQ1            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ2            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ3            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ4            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ5            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ6            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ7            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ8            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ9            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ10           LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ11           LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ12           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ13           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ14           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ15           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ16           LL_ADC_REG_SetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_RANK_1
  *         @arg @ref LL_ADC_REG_RANK_2
  *         @arg @ref LL_ADC_REG_RANK_3
  *         @arg @ref LL_ADC_REG_RANK_4
  *         @arg @ref LL_ADC_REG_RANK_5
  *         @arg @ref LL_ADC_REG_RANK_6
  *         @arg @ref LL_ADC_REG_RANK_7
  *         @arg @ref LL_ADC_REG_RANK_8
  *         @arg @ref LL_ADC_REG_RANK_9
  *         @arg @ref LL_ADC_REG_RANK_10
  *         @arg @ref LL_ADC_REG_RANK_11
  *         @arg @ref LL_ADC_REG_RANK_12
  *         @arg @ref LL_ADC_REG_RANK_13
  *         @arg @ref LL_ADC_REG_RANK_14
  *         @arg @ref LL_ADC_REG_RANK_15
  *         @arg @ref LL_ADC_REG_RANK_16
  * @param  Channel 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* 根据参数"Rank"在寄存器中的位置和寄存器位置设置参数"Channel"的内容。 */
  /* 参数"Rank"和"Channel"使用掩码，因为它们包含用于其他目的的保留位。 */
  
  /* 计算目标寄存器地址：根据Rank确定操作SQR1, SQR2还是SQR3寄存器 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, __ADC_MASK_SHIFT(Rank, ADC_REG_SQRX_REGOFFSET_MASK));
  
  /* 修改目标寄存器：将通道号写入到指定Rank对应的位域中 */
  MODIFY_REG(*preg,
             ADC_CHANNEL_ID_NUMBER_MASK << (Rank & ADC_REG_RANK_ID_SQRX_MASK),
             (Channel & ADC_CHANNEL_ID_NUMBER_MASK) << (Rank & ADC_REG_RANK_ID_SQRX_MASK));
}

/**
  * @brief  获取ADC常规组序列：选定扫描序列排名上的通道。
  * @note   在此STM32系列上，ADC常规组序列器是
  *         完全可配置的：序列器长度和每个排名
  *         对应的通道都是可配置的。
  *         参考函数 @ref LL_ADC_REG_SetSequencerLength() 的描述。
  * @note   根据设备和封装，某些通道可能不可用。
  *         请参考设备数据手册了解通道可用性。
  * @note   返回通道号的使用方法：
  *         - 要将此通道重新注入另一个函数LL_ADC_xxx中：
  *           返回的通道号仅在LL_ADC_CHANNEL_x字面量定义上部分格式化。
  *           因此，必须将其与LL_ADC_CHANNEL_x字面量的部分进行比较，
  *           或使用辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  *           然后选定的字面量LL_ADC_CHANNEL_x可以用作
  *           另一个函数的参数。
  *         - 要获取十进制格式的通道号：
  *           使用辅助宏处理返回值
  *           @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  * @rmtoll SQR3     SQ1            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ2            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ3            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ4            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ5            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ6            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ7            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ8            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ9            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ10           LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ11           LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ12           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ13           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ14           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ15           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ16           LL_ADC_REG_GetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_RANK_1
  *         @arg @ref LL_ADC_REG_RANK_2
  *         @arg @ref LL_ADC_REG_RANK_3
  *         @arg @ref LL_ADC_REG_RANK_4
  *         @arg @ref LL_ADC_REG_RANK_5
  *         @arg @ref LL_ADC_REG_RANK_6
  *         @arg @ref LL_ADC_REG_RANK_7
  *         @arg @ref LL_ADC_REG_RANK_8
  *         @arg @ref LL_ADC_REG_RANK_9
  *         @arg @ref LL_ADC_REG_RANK_10
  *         @arg @ref LL_ADC_REG_RANK_11
  *         @arg @ref LL_ADC_REG_RANK_12
  *         @arg @ref LL_ADC_REG_RANK_13
  *         @arg @ref LL_ADC_REG_RANK_14
  *         @arg @ref LL_ADC_REG_RANK_15
  *         @arg @ref LL_ADC_REG_RANK_16
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，
  *             与内部通道参数的比较应使用
  *             辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL()。
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank计算目标寄存器地址(SQR1, SQR2或SQR3) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, __ADC_MASK_SHIFT(Rank, ADC_REG_SQRX_REGOFFSET_MASK));
  
  /* 读取目标寄存器，提取指定Rank对应的通道号并右移对齐 */
  return (uint32_t) (READ_BIT(*preg,
                              ADC_CHANNEL_ID_NUMBER_MASK << (Rank & ADC_REG_RANK_ID_SQRX_MASK))
                     >> (Rank & ADC_REG_RANK_ID_SQRX_MASK)
                    );
}

/**
  * @brief  设置ADC常规组的连续转换模式。
  * @note   ADC连续转换模式描述：
  *         - 单次模式：每次触发进行一次转换
  *         - 连续模式：第一次触发后，随后的
  *           转换自动连续启动。
  * @note   不能同时启用ADC常规组连续模式和序列器不连续模式。
  * @rmtoll CR2      CONT           LL_ADC_REG_SetContinuousMode
  * @param  ADCx ADC实例
  * @param  Continuous 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_CONV_SINGLE
  *         @arg @ref LL_ADC_REG_CONV_CONTINUOUS
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetContinuousMode(ADC_TypeDef *ADCx, uint32_t Continuous)
{
  /* 修改ADCx->CR2寄存器的CONT位，设置单次转换或连续转换模式 */
  MODIFY_REG(ADCx->CR2, ADC_CR2_CONT, Continuous);
}

/**
  * @brief  获取ADC常规组的连续转换模式。
  * @note   ADC连续转换模式描述：
  *         - 单次模式：每次触发进行一次转换
  *         - 连续模式：第一次触发后，随后的
  *           转换自动连续启动。
  * @rmtoll CR2      CONT           LL_ADC_REG_GetContinuousMode
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_CONV_SINGLE
  *         @arg @ref LL_ADC_REG_CONV_CONTINUOUS
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetContinuousMode(ADC_TypeDef *ADCx)
{
  /* 读取ADCx->CR2寄存器的CONT位，获取当前转换模式配置 */
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_CONT));
}
/**
  * @brief  设置ADC常规组转换数据传输模式：无传输或DMA传输，以及DMA请求模式。
  * @note   如果选择了DMA传输，则指定DMA请求模式：
  *         - 有限模式(单次模式)：当达到DMA数据传输次数(ADC转换次数)时，
  *           DMA传输请求停止。此ADC模式旨在与DMA非循环模式配合使用。
  *         - 无限模式：DMA传输请求是无限的，无论DMA数据传输次数(ADC转换次数)如何。
  *           此ADC模式旨在与DMA循环模式配合使用。
  * @note   如果ADC DMA请求模式设置为无限模式，而DMA设置为非循环模式：
  *         当达到DMA传输大小时，DMA将停止传输ADC转换数据，
  *         ADC将引发溢出错误(如果使能了溢出标志和中断)。
  * @note   要配置DMA源地址(外设地址)，请使用函数 @ref LL_ADC_DMA_GetRegAddr()。
  * @rmtoll CR2      DMA            LL_ADC_REG_SetDMATransfer
  * @param  ADCx ADC实例
  * @param  DMATransfer 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_NONE    // 不使用DMA传输
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_UNLIMITED // 使用DMA传输(无限模式)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetDMATransfer(ADC_TypeDef *ADCx, uint32_t DMATransfer)
{
  // 修改ADCx->CR2寄存器中的DMA位，设置为参数指定的DMA传输模式
  MODIFY_REG(ADCx->CR2, ADC_CR2_DMA, DMATransfer);
}

/**
  * @brief  获取ADC常规组转换数据传输模式：无传输或DMA传输，以及DMA请求模式。
  * @note   如果选择了DMA传输，则指定DMA请求模式：
  *         - 有限模式(单次模式)：当达到DMA数据传输次数(ADC转换次数)时，
  *           DMA传输请求停止。此ADC模式旨在与DMA非循环模式配合使用。
  *         - 无限模式：DMA传输请求是无限的，无论DMA数据传输次数(ADC转换次数)如何。
  *           此ADC模式旨在与DMA循环模式配合使用。
  * @note   如果ADC DMA请求模式设置为无限模式，而DMA设置为非循环模式：
  *         当达到DMA传输大小时，DMA将停止传输ADC转换数据，
  *         ADC将引发溢出错误(如果使能了溢出标志和中断)。
  * @note   要配置DMA源地址(外设地址)，请使用函数 @ref LL_ADC_DMA_GetRegAddr()。
  * @rmtoll CR2      DMA            LL_ADC_REG_GetDMATransfer
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_NONE
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_UNLIMITED
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetDMATransfer(ADC_TypeDef *ADCx)
{
  // 读取ADCx->CR2寄存器中的DMA位，并返回当前的DMA传输配置
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_DMA));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Group_Injected ADC层级范围配置：注入组
  * @{
  */

/**
  * @brief  设置ADC注入组转换触发源：内部(软件启动)或来自外部IP(定时器事件，外部中断线)。
  * @note   在此STM32系列上，外部触发设置为上升沿触发极性(此STM32系列上唯一可用的触发极性)。
  * @note   来自定时器的触发源参数可用性取决于所选设备上定时器的可用性。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_SetTriggerSource
  * @param  ADCx ADC实例
  * @param  TriggerSource 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_SOFTWARE          // 软件触发
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_TRGO     (1) // TIM1 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_CH4      (1) // TIM1通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_TRGO     (2) // TIM2 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_CH1      (2) // TIM2通道1
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM3_CH4      (2) // TIM3通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_TRGO     (2) // TIM4 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_EXTI_LINE15   (2) // 外部中断线15
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (2)(4) // TIM8通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3 (3) // TIM8通道4(ADC3专用)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_CH3      (3) // TIM4通道3
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH2      (3) // TIM8通道2
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (3) // TIM8通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_TRGO     (3) // TIM5 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_CH4      (3) // TIM5通道4
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1、ADC2、ADC3。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1、ADC2。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度设备。必须在顶层完成触发重映射(参考AFIO外设)。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
/* 注意：在此STM32系列上，ADC注入组外部触发边沿用于执行ADC转换启动。       */
/*       此函数不设置外部触发边沿。                                          */
/*       此功能使用函数 @ref LL_ADC_INJ_StartConversionExtTrig() 设置。       */
  // 修改ADCx->CR2寄存器的JEXTSEL位，设置注入组触发源
  // TriggerSource & ADC_CR2_JEXTSEL 用于确保只写入有效的位
  MODIFY_REG(ADCx->CR2, ADC_CR2_JEXTSEL, (TriggerSource & ADC_CR2_JEXTSEL));
}

/**
  * @brief  获取ADC注入组转换触发源：内部(软件启动)或来自外部IP(定时器事件，外部中断线)。
  * @note   要确定注入组触发源是内部(软件启动)还是外部，而不详细说明选择了哪个外设作为外部触发，
  *         (相当于 "if(LL_ADC_INJ_GetTriggerSource(ADC1) == LL_ADC_INJ_TRIG_SOFTWARE)")
  *         请使用函数 @ref LL_ADC_INJ_IsTriggerSourceSWStart。
  * @note   来自定时器的触发源参数可用性取决于所选设备上定时器的可用性。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_GetTriggerSource
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_TRGO     (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_CH4      (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_CH1      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM3_CH4      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_EXTI_LINE15   (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (2)(4)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3 (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_CH3      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH2      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_TRGO     (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_CH4      (3)
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1、ADC2、ADC3。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1、ADC2。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度设备。必须在顶层完成触发重映射(参考AFIO外设)。
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTriggerSource(ADC_TypeDef *ADCx)
{
  // 读取ADCx->CR2寄存器中的JEXTSEL位，返回当前的触发源配置
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_JEXTSEL));
}

/**
  * @brief  获取ADC注入组转换触发源是内部(软件启动)还是外部
  * @note   如果注入组触发源设置为外部触发，要确定选择了哪个外设作为外部触发，
  *         请使用函数 @ref LL_ADC_INJ_GetTriggerSource。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_IsTriggerSourceSWStart
  * @param  ADCx ADC实例
  * @retval 值 "0" 表示触发源为外部触发
  *         值 "1" 表示触发源为软件启动。
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  // 判断CR2寄存器中的JEXTSEL位是否等于LL_ADC_INJ_TRIG_SOFTWARE
  return (READ_BIT(ADCx->CR2, ADC_CR2_JEXTSEL) == LL_ADC_INJ_TRIG_SOFTWARE);
}

/**
  * @brief  设置ADC注入组序列器长度和扫描方向。
  * @note   此函数执行以下配置：
  *         - 序列长度：扫描序列中的排名数量。
  *         - 序列方向：除非参数中指定，否则序列器扫描方向为正向(从排名1到排名n)。
  * @note   在此STM32系列上，注入组序列器配置取决于ADC实例序列器模式。
  *         如果禁用了ADC实例序列器模式，则所有组(常规组、注入组)的序列器可以配置，
  *         但其执行被禁用(仅限于排名1)。
  *         请参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器相当于1个排名的序列器：ADC仅在1个通道上转换。
  * @rmtoll JSQR     JL             LL_ADC_INJ_SetSequencerLength
  * @param  ADCx ADC实例
  * @param  SequencerNbRanks 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_DISABLE      // 禁用扫描(1个通道)
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS // 启用扫描(2个通道)
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS // 启用扫描(3个通道)
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS // 启用扫描(4个通道)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  // 修改ADCx->JSQR寄存器中的JL位，设置注入序列器的转换通道数量
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JL, SequencerNbRanks);
}

/**
  * @brief  获取ADC注入组序列器长度和扫描方向。
  * @note   此函数检索：
  *         - 序列长度：扫描序列中的排名数量。
  *         - 序列方向：除非参数中指定，否则序列器扫描方向为正向(从排名1到排名n)。
  * @note   在此STM32系列上，注入组序列器配置取决于ADC实例序列器模式。
  *         如果禁用了ADC实例序列器模式，则所有组(常规组、注入组)的序列器可以配置，
  *         但其执行被禁用(仅限于排名1)。
  *         请参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器相当于1个排名的序列器：ADC仅在1个通道上转换。
  * @rmtoll JSQR     JL             LL_ADC_INJ_GetSequencerLength
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerLength(ADC_TypeDef *ADCx)
{
  // 读取ADCx->JSQR寄存器中的JL位，返回当前注入序列器的长度配置
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JL));
}

/**
  * @brief  设置ADC注入组序列器不连续模式：序列细分，每选定的排名数中断扫描转换。
  * @note   无法同时启用ADC注入组自动注入模式和序列器不连续模式。
  * @rmtoll CR1      DISCEN         LL_ADC_INJ_SetSequencerDiscont
  * @param  ADCx ADC实例
  * @param  SeqDiscont 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_DISABLE  // 禁用不连续模式
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_1RANK    // 启用不连续模式，每次转换1个通道
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  // 修改ADCx->CR1寄存器中的JDISCEN位，配置注入序列器的不连续模式
  MODIFY_REG(ADCx->CR1, ADC_CR1_JDISCEN, SeqDiscont);
}

/**
  * @brief  获取ADC注入组序列器不连续模式：序列细分，每选定的排名数中断扫描转换。
  * @rmtoll CR1      DISCEN         LL_ADC_REG_GetSequencerDiscont
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_1RANK
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerDiscont(ADC_TypeDef *ADCx)
{
  // 读取ADCx->CR1寄存器中的JDISCEN位，返回当前不连续模式的配置
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_JDISCEN));
}

/**
  * @brief  设置ADC注入组序列：选定序列排名上的通道。
  * @note   根据设备和封装，某些通道可能不可用。有关通道可用性，请参考设备数据手册。
  * @note   在此STM32系列上，要测量内部通道(VrefInt，温度传感器等)，
  *         必须单独启用到内部通道的测量路径。
  *         这可以使用函数 @ref LL_ADC_SetCommonPathInternalCh() 完成。
  * @rmtoll JSQR     JSQ1           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ2           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ3           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ4           LL_ADC_INJ_SetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1  // 注入组序列排名1
  *         @arg @ref LL_ADC_INJ_RANK_2  // 注入组序列排名2
  *         @arg @ref LL_ADC_INJ_RANK_3  // 注入组序列排名3
  *         @arg @ref LL_ADC_INJ_RANK_4  // 注入组序列排名4
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1) // 内部参考电压通道
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1) // 温度传感器通道
  *         
  *         (1) 在STM32F1上，参数仅适用于ADC实例：ADC1。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* 根据参数"Rank"在寄存器中的位置，设置参数"Channel"的内容位。          */
  /* 参数"Rank"和"Channel"使用掩码，因为它们包含用于其他目的的保留位。       */
  
  // 读取当前JSQR寄存器中的JL位(注入序列长度)，并计算出实际的转换数量(+1)
  uint32_t tmpreg1 = (READ_BIT(ADCx->JSQR, ADC_JSQR_JL) >> ADC_JSQR_JL_Pos) + 1U;
  
  // 修改ADCx->JSQR寄存器
  // ADC注入序列器的JSQx位置是动态计算的，取决于序列长度(JL)和当前排名
  // 公式: 5U * (uint8_t)(((Rank) + 3U) - (tmpreg1)) 用于计算移位位数
  MODIFY_REG(ADCx->JSQR,
             ADC_CHANNEL_ID_NUMBER_MASK << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))),
             (Channel & ADC_CHANNEL_ID_NUMBER_MASK) << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))));
}

/**
  * @brief  获取ADC注入组序列：选定序列排名上的通道。
  * @note   根据设备和封装，某些通道可能不可用。有关通道可用性，请参考设备数据手册。
  * @note   返回通道号的使用方法：
  *         - 要将此通道重新注入到另一个函数LL_ADC_xxx中：
  *           返回的通道号仅在LL_ADC_CHANNEL_x文字的定义上部分格式化。
  *           因此，必须将其与LL_ADC_CHANNEL_x文字的部分进行比较，或使用
  *           辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  *           然后可以将选定的文字LL_ADC_CHANNEL_x用作另一个函数的参数。
  *         - 要获取十进制格式的通道号：
  *           使用辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB() 处理返回值。
  * @rmtoll JSQR     JSQ1           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ2           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ3           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ4           LL_ADC_INJ_SetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅适用于ADC实例：ADC1。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，与内部通道参数的比较应
  *             使用辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL() 进行。
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank)
{
  // 读取当前JSQR寄存器中的JL位(注入序列长度)，并计算出实际的转换数量(+1)
  uint32_t tmpreg1 = (READ_BIT(ADCx->JSQR, ADC_JSQR_JL) >> ADC_JSQR_JL_Pos)  + 1U;
  
  // 读取JSQR寄存器中对应Rank的通道编号
  // 计算移位位数，提取对应的JSQx字段，并右移对齐
  return (uint32_t)(READ_BIT(ADCx->JSQR,
                             ADC_CHANNEL_ID_NUMBER_MASK << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))))
                    >> (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1)))
                   );
}
/**
  * @brief  设置ADC注入组的转换触发模式：独立触发或来自ADC常规组。
  * @note   此模式可用于扩展在一次ADC转换触发后更新的数据寄存器数量，
  *         并且数据会被永久保存（不会被ADC扫描序列的后续转换覆盖），
  *         最多可扩展至5个数据寄存器：
  *         1个数据寄存器位于ADC常规组，4个数据寄存器位于ADC注入组。
  * @note   如果ADC注入组的触发源设置为外部触发，则此功能必须设置为独立触发。
  *         ADC注入组自动触发仅兼容设置为软件启动(SW start)的注入组触发源，
  *         无需对ADC注入组的转换启动或停止进行任何进一步操作：
  *         在这种情况下，ADC注入组仅由ADC常规组控制。
  * @note   无法同时启用ADC注入组自动注入模式和序列器不连续模式。
  * @rmtoll CR1      JAUTO          LL_ADC_INJ_SetTrigAuto
  * @param  ADCx ADC实例
  * @param  TrigAuto 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_INDEPENDENT      (独立触发)
  *         @arg @ref LL_ADC_INJ_TRIG_FROM_GRP_REGULAR (由常规组触发)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetTrigAuto(ADC_TypeDef *ADCx, uint32_t TrigAuto)
{
  /* 修改CR1寄存器的JAUTO位，设置自动注入转换模式 */
  MODIFY_REG(ADCx->CR1, ADC_CR1_JAUTO, TrigAuto);
}

/**
  * @brief  获取ADC注入组的转换触发模式：独立触发或来自ADC常规组。
  * @rmtoll CR1      JAUTO          LL_ADC_INJ_GetTrigAuto
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_INDEPENDENT      (独立触发)
  *         @arg @ref LL_ADC_INJ_TRIG_FROM_GRP_REGULAR (由常规组触发)
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTrigAuto(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器的JAUTO位，获取当前自动注入模式配置 */
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_JAUTO));
}

/**
  * @brief  设置ADC注入组的偏移值。
  * @note   它设置：
  *         - 将应用编程偏移量的ADC注入组排名
  *         - 偏移电平（从原始转换数据中减去的偏移量）。
  *         注意：偏移格式取决于ADC分辨率：
  *         偏移量必须在第11位左对齐，LSB（右侧位）设置为0。
  * @note   偏移无法单独启用或禁用。
  *         要模拟禁用偏移，请将偏移值设置为0。
  * @rmtoll JOFR1    JOFFSET1       LL_ADC_INJ_SetOffset\n
  *         JOFR2    JOFFSET2       LL_ADC_INJ_SetOffset\n
  *         JOFR3    JOFFSET3       LL_ADC_INJ_SetOffset\n
  *         JOFR4    JOFFSET4       LL_ADC_INJ_SetOffset
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1  (注入通道排名1)
  *         @arg @ref LL_ADC_INJ_RANK_2  (注入通道排名2)
  *         @arg @ref LL_ADC_INJ_RANK_3  (注入通道排名3)
  *         @arg @ref LL_ADC_INJ_RANK_4  (注入通道排名4)
  * @param  OffsetLevel 偏移值，范围在 Min_Data=0x000 和 Max_Data=0xFFF 之间
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetOffset(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t OffsetLevel)
{
  /* 根据Rank（排名）计算对应的JOFR寄存器地址 */
  /* __ADC_PTR_REG_OFFSET用于计算寄存器偏移量，ADCx->JOFR1是基地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JOFR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JOFRX_REGOFFSET_MASK));
  
  /* 修改计算出的JOFR寄存器，设置偏移值 */
  MODIFY_REG(*preg,
             ADC_JOFR1_JOFFSET1,
             OffsetLevel);
}

/**
  * @brief  获取ADC注入组的偏移值。
  * @note   它返回偏移电平（从原始转换数据中减去的偏移量）。
  *         注意：偏移格式取决于ADC分辨率：
  *         偏移量必须在第11位左对齐，LSB（右侧位）设置为0。
  * @rmtoll JOFR1    JOFFSET1       LL_ADC_INJ_GetOffset\n
  *         JOFR2    JOFFSET2       LL_ADC_INJ_GetOffset\n
  *         JOFR3    JOFFSET3       LL_ADC_INJ_GetOffset\n
  *         JOFR4    JOFFSET4       LL_ADC_INJ_GetOffset
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1  (注入通道排名1)
  *         @arg @ref LL_ADC_INJ_RANK_2  (注入通道排名2)
  *         @arg @ref LL_ADC_INJ_RANK_3  (注入通道排名3)
  *         @arg @ref LL_ADC_INJ_RANK_4  (注入通道排名4)
  * @retval 返回值范围在 Min_Data=0x000 和 Max_Data=0xFFF 之间
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetOffset(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank（排名）计算对应的JOFR寄存器地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JOFR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JOFRX_REGOFFSET_MASK));
  
  /* 读取计算出的JOFR寄存器中的偏移值 */
  return (uint32_t)(READ_BIT(*preg,
                             ADC_JOFR1_JOFFSET1)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_Channels Configuration of ADC hierarchical scope: channels
  * @{
  */

/**
  * @brief  设置所选ADC通道的采样时间
  *         单位：ADC时钟周期。
  * @note   在此设备上，采样时间是针对通道范围的：与通道映射在ADC常规组还是注入组无关。
  * @note   如果要转换内部通道（VrefInt, TempSensor, ...）：
  *         必须遵守采样时间约束（可以根据ADC时钟频率和采样时间设置进行调整）。
  *         有关时序值（参数TS_vrefint, TS_temp等），请参考设备数据手册。
  * @note   转换时间是采样时间与处理时间之和。
  *         有关此STM32系列的ADC处理时间，请参考参考手册。
  * @note   在ADC转换内部通道（VrefInt, 温度传感器等）的情况下，需要最小采样时间值。
  *         请参考设备数据手册。
  * @rmtoll SMPR1    SMP17          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP16          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP15          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP14          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP13          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP12          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP11          LL_ADC_SetChannelSamplingTime\n
  *         SMPR1    SMP10          LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP9           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP8           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP7           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP6           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP5           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP4           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP3           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP2           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP1           LL_ADC_SetChannelSamplingTime\n
  *         SMPR2    SMP0           LL_ADC_SetChannelSamplingTime
  * @param  ADCx ADC实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)  (内部参考电压通道)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)  (温度传感器通道)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例ADC1上可用。
  * @param  SamplingTime 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_SAMPLINGTIME_1CYCLE_5    (1.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_7CYCLES_5   (7.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_13CYCLES_5  (13.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_28CYCLES_5  (28.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_41CYCLES_5  (41.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_55CYCLES_5  (55.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_71CYCLES_5  (71.5个ADC时钟周期)
  *         @arg @ref LL_ADC_SAMPLINGTIME_239CYCLES_5 (239.5个ADC时钟周期)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetChannelSamplingTime(ADC_TypeDef *ADCx, uint32_t Channel, uint32_t SamplingTime)
{
  /* 根据参数"SamplingTime"的内容设置位，位位置在寄存器中，寄存器位置取决于参数"Channel"。 */
  /* 参数"Channel"使用掩码处理，因为它包含保留用于其他目的的位。 */
  /* 根据通道号计算SMPR寄存器的地址（SMPR1或SMPR2） */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SMPR1, __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPRX_REGOFFSET_MASK));
  
  /* 修改计算出的SMPR寄存器，设置采样时间 */
  /* 首先计算移位位数，然后将SamplingTime移位到正确位置进行配置 */
  MODIFY_REG(*preg,
             ADC_SMPR2_SMP0 << __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK),
             SamplingTime   << __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK));
}

/**
  * @brief  获取所选ADC通道的采样时间
  *         单位：ADC时钟周期。
  * @note   在此设备上，采样时间是针对通道范围的：与通道映射在ADC常规组还是注入组无关。
  * @note   转换时间是采样时间与处理时间之和。
  *         有关此STM32系列的ADC处理时间，请参考参考手册。
  * @rmtoll SMPR1    SMP17          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP16          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP15          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP14          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP13          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP12          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP11          LL_ADC_GetChannelSamplingTime\n
  *         SMPR1    SMP10          LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP9           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP8           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP7           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP6           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP5           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP4           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP3           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP2           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP1           LL_ADC_GetChannelSamplingTime\n
  *         SMPR2    SMP0           LL_ADC_GetChannelSamplingTime
  * @param  ADCx ADC实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)  (内部参考电压通道)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)  (温度传感器通道)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例ADC1上可用。
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_SAMPLINGTIME_1CYCLE_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_7CYCLES_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_13CYCLES_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_28CYCLES_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_41CYCLES_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_55CYCLES_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_71CYCLES_5
  *         @arg @ref LL_ADC_SAMPLINGTIME_239CYCLES_5
  */
__STATIC_INLINE uint32_t LL_ADC_GetChannelSamplingTime(ADC_TypeDef *ADCx, uint32_t Channel)
{
  /* 根据通道号计算SMPR寄存器的地址（SMPR1或SMPR2） */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SMPR1, __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPRX_REGOFFSET_MASK));
  
  /* 读取SMPR寄存器，将对应的采样时间位右移对齐，并返回结果 */
  return (uint32_t)(READ_BIT(*preg,
                             ADC_SMPR2_SMP0 << __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK))
                    >> __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_AnalogWatchdog Configuration of ADC transversal scope: analog watchdog
  * @{
  */

/**
  * @brief  设置ADC模拟看门狗监控通道：
  *         单个通道或所有通道，
  *         在ADC常规组和/或注入组上。
  * @note   一旦选择了监控通道，模拟看门狗即被启用。
  * @note   如果需要从序列器通道定义中定义单个通道以使用模拟看门狗进行监控，
  *         请使用辅助宏 @ref __LL_ADC_ANALOGWD_CHANNEL_GROUP()。
  * @note   在此STM32系列上，只有1种模拟看门狗实例：
  *         - AWD标准（实例AWD1）：
  *           - 监控通道：可监控1个通道或所有通道。
  *           - 监控组：ADC常规组和/或注入组。
  *           - 分辨率：分辨率不受限制（对应于配置的ADC分辨率）。
  * @rmtoll CR1      AWD1CH         LL_ADC_SetAnalogWDMonitChannels\n
  *         CR1      AWD1SGL        LL_ADC_SetAnalogWDMonitChannels\n
  *         CR1      AWD1EN         LL_ADC_SetAnalogWDMonitChannels
  * @param  ADCx ADC实例
  * @param  AWDChannelGroup 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_DISABLE               (禁用模拟看门狗)
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG      (所有常规通道)
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_INJ      (所有注入通道)
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG_INJ  (所有常规和注入通道)
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_REG_INJ
  *         @arg @ref LL_ADC_AWD_CH_VREFINT_REG          (1) (内部参考电压通道-常规)
  *         @arg @ref LL_ADC_AWD_CH_VREFINT_INJ          (1) (内部参考电压通道-注入)
  *         @arg @ref LL_ADC_AWD_CH_VREFINT_REG_INJ      (1) (内部参考电压通道-常规和注入)
  *         @arg @ref LL_ADC_AWD_CH_TEMPSENSOR_REG       (1) (温度传感器通道-常规)
  *         @arg @ref LL_ADC_AWD_CH_TEMPSENSOR_INJ       (1) (温度传感器通道-注入)
  *         @arg @ref LL_ADC_AWD_CH_TEMPSENSOR_REG_INJ   (1) (温度传感器通道-常规和注入)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例ADC1上可用。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDMonitChannels(ADC_TypeDef *ADCx, uint32_t AWDChannelGroup)
{
  /* 配置CR1寄存器：
     ADC_CR1_AWDEN: 常规组模拟看门狗使能
     ADC_CR1_JAWDEN: 注入组模拟看门狗使能
     ADC_CR1_AWDSGL: 单通道/所有通道选择
     ADC_CR1_AWDCH: 看门狗通道选择位
     AWDChannelGroup参数包含了上述所有配置信息
  */
  MODIFY_REG(ADCx->CR1,
             (ADC_CR1_AWDEN | ADC_CR1_JAWDEN | ADC_CR1_AWDSGL | ADC_CR1_AWDCH),
             AWDChannelGroup);
}
/**
  * @brief  获取ADC模拟看门狗监控的通道。
  * @note   返回通道号的使用方法:
  *         - 为了将该通道号重新注入到另一个函数 LL_ADC_xxx 中:
  *           返回的通道号仅在 LL_ADC_CHANNEL_x 定义的字面量上进行了部分格式化。
  *           因此，必须将其与 LL_ADC_CHANNEL_x 的部分字面量进行比较，或者使用
  *           辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  *           然后选定的 LL_ADC_CHANNEL_x 字面量可以用作另一个函数的参数。
  *         - 获取十进制格式的通道号:
  *           使用辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB() 处理返回值。
  *           仅适用于模拟看门狗设置为监控单个通道的情况。
  * @note   在此STM32系列上，只有1种模拟看门狗实例:
  *         - AWD 标准 (实例 AWD1):
  *           - 监控通道: 可以监控1个通道或所有通道。
  *           - 监控组: ADC 规则组和/或注入组。
  *           - 分辨率: 分辨率不受限制 (对应于配置的ADC分辨率)。
  * @rmtoll CR1      AWD1CH         LL_ADC_GetAnalogWDMonitChannels\n
  *         CR1      AWD1SGL        LL_ADC_GetAnalogWDMonitChannels\n
  *         CR1      AWD1EN         LL_ADC_GetAnalogWDMonitChannels
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_DISABLE
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_INJ
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_1_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_2_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_3_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_4_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_5_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_6_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_7_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_8_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_REG 
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_INJ 
  *         @arg @ref LL_ADC_AWD_CHANNEL_9_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_10_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_11_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_12_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_13_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_14_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_15_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_16_REG_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_REG
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_INJ
  *         @arg @ref LL_ADC_AWD_CHANNEL_17_REG_INJ
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDMonitChannels(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器中与模拟看门狗通道配置相关的位 */
  /* ADC_CR1_AWDEN: 规则通道模拟看门狗使能 */
  /* ADC_CR1_JAWDEN: 注入通道模拟看门狗使能 */
  /* ADC_CR1_AWDSGL: 单通道/所有通道监控选择 */
  /* ADC_CR1_AWDCH: 看门狗监控的通道号选择位 */
  return (uint32_t)(READ_BIT(ADCx->CR1, (ADC_CR1_AWDEN | ADC_CR1_JAWDEN | ADC_CR1_AWDSGL | ADC_CR1_AWDCH)));
}

/**
  * @brief  设置ADC模拟看门狗的高或低阈值。
  * @note   在此STM32系列上，只有1种模拟看门狗实例:
  *         - AWD 标准 (实例 AWD1):
  *           - 监控通道: 可以监控1个通道或所有通道。
  *           - 监控组: ADC 规则组和/或注入组。
  *           - 分辨率: 分辨率不受限制 (对应于配置的ADC分辨率)。
  * @rmtoll HTR      HT             LL_ADC_SetAnalogWDThresholds\n
  *         LTR      LT             LL_ADC_SetAnalogWDThresholds
  * @param  ADCx ADC实例
  * @param  AWDThresholdsHighLow 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_THRESHOLD_HIGH (高阈值)
  *         @arg @ref LL_ADC_AWD_THRESHOLD_LOW (低阈值)
  * @param  AWDThresholdValue: 阈值数值，范围 Min_Data=0x000 到 Max_Data=0xFFF (12位)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDThresholdsHighLow, uint32_t AWDThresholdValue)
{
  /* 根据参数AWDThresholdsHighLow计算寄存器偏移量，获取对应寄存器指针(HTR或LTR) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->HTR, AWDThresholdsHighLow);
  
  /* 修改阈值寄存器的值，保留其他位不变 */
  /* ADC_HTR_HT 是高阈值寄存器中的阈值位掩码 */
  MODIFY_REG(*preg,
             ADC_HTR_HT,
             AWDThresholdValue);
}

/**
  * @brief  获取ADC模拟看门狗的高阈值或低阈值。
  * @note   如果ADC分辨率不是12位，模拟看门狗阈值数据需要特定的移位。
  *         使用辅助宏 @ref __LL_ADC_ANALOGWD_GET_THRESHOLD_RESOLUTION()。
  * @rmtoll HTR      HT             LL_ADC_GetAnalogWDThresholds\n
  *         LTR      LT             LL_ADC_GetAnalogWDThresholds
  * @param  ADCx ADC实例
  * @param  AWDThresholdsHighLow 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_THRESHOLD_HIGH (高阈值)
  *         @arg @ref LL_ADC_AWD_THRESHOLD_LOW (低阈值)
  * @retval 数值范围 Min_Data=0x000 到 Max_Data=0xFFF
*/
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDThresholdsHighLow)
{
  /* 根据参数AWDThresholdsHighLow计算寄存器偏移量，获取对应寄存器指针(HTR或LTR) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->HTR, AWDThresholdsHighLow);
  
  /* 读取并返回阈值寄存器中的数值 */
  return (uint32_t)(READ_BIT(*preg, ADC_HTR_HT));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Multimode ADC层级范围配置：多模模式
  * @{
  */

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  设置ADC多模配置，使其工作在独立模式或多模模式（适用于有多个ADC实例的设备）。
  * @note   如果配置为多模模式：选定的ADC实例根据硬件决定是主ADC还是从ADC。
  *         请参考参考手册。
  * @rmtoll CR1      DUALMOD        LL_ADC_SetMultimode
  * @param  ADCxy_COMMON ADC公共实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  Multimode 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_INDEPENDENT             (独立模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIMULT         (双ADC规则同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_FAST    (双ADC规则快速交替采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_SLOW    (双ADC规则慢速交替采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_SIMULT         (双ADC注入同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_ALTERN         (双ADC注入交替触发模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM    (双ADC规则同时采样 + 注入同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT    (双ADC规则同时采样 + 注入交替触发模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM(双ADC规则快速交替 + 注入同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM(双ADC规则慢速交替 + 注入同时采样模式)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetMultimode(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t Multimode)
{
  /* 修改公共控制寄存器CR1中的DUALMOD位，设置多模模式 */
  MODIFY_REG(ADCxy_COMMON->CR1, ADC_CR1_DUALMOD, Multimode);
}

/**
  * @brief  获取ADC多模配置，当前是工作在独立模式还是多模模式（适用于有多个ADC实例的设备）。
  * @note   如果配置为多模模式：选定的ADC实例根据硬件决定是主ADC还是从ADC。
  *         请参考参考手册。
  * @rmtoll CR1      DUALMOD        LL_ADC_GetMultimode
  * @param  ADCxy_COMMON ADC公共实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_INDEPENDENT
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_FAST    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_SLOW    
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_ALTERN         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM
  */
__STATIC_INLINE uint32_t LL_ADC_GetMultimode(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 读取并返回公共控制寄存器CR1中的DUALMOD位 */
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CR1, ADC_CR1_DUALMOD));
}

#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */
/** @defgroup ADC_LL_EF_Operation_ADC_Instance ADC层级范围操作：ADC实例
  * @{
  */

/**
  * @brief  使能选定的ADC实例。
  * @note   在此STM32系列上，ADC使能后，需要等待一段时间用于ADC内部模拟电路稳定，
  *         才能开始ADC转换。请参考数据手册中的参数 tSTAB。
  * @rmtoll CR2      ADON           LL_ADC_Enable
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_Enable(ADC_TypeDef *ADCx)
{
  /* 设置CR2寄存器中的ADON位来使能ADC */
  SET_BIT(ADCx->CR2, ADC_CR2_ADON);
}

/**
  * @brief  关闭选定的ADC实例。
  * @rmtoll CR2      ADON           LL_ADC_Disable
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_Disable(ADC_TypeDef *ADCx)
{
  /* 清除CR2寄存器中的ADON位来关闭ADC */
  CLEAR_BIT(ADCx->CR2, ADC_CR2_ADON);
}

/**
  * @brief  获取选定ADC实例的使能状态。
  * @rmtoll CR2      ADON           LL_ADC_IsEnabled
  * @param  ADCx ADC实例
  * @retval 0: ADC已关闭, 1: ADC已使能。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabled(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的ADON位，判断ADC是否已使能 */
  return (READ_BIT(ADCx->CR2, ADC_CR2_ADON) == (ADC_CR2_ADON));
}

/**
  * @brief  启动ADC校准，模式为单端输入或差分输入（适用于支持差分模式的设备）。
  * @note   在此STM32系列上，启动校准之前，ADC必须处于关闭状态。
  *         在ADC关闭状态和校准开始之间需要最少数量的ADC时钟周期。
  *         请参考宏 @ref LL_ADC_DELAY_DISABLE_CALIB_ADC_CYCLES。
  * @note   在此STM32系列上，启动校准的硬件前提：
            ADC必须已上电至少两个ADC时钟周期。
  * @rmtoll CR2      CAL            LL_ADC_StartCalibration
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_StartCalibration(ADC_TypeDef *ADCx)
{
  /* 设置CR2寄存器中的CAL位启动校准 */
  SET_BIT(ADCx->CR2, ADC_CR2_CAL);
}

/**
  * @brief  获取ADC校准状态。
  * @rmtoll CR2      CAL            LL_ADC_IsCalibrationOnGoing
  * @param  ADCx ADC实例
  * @retval 0: 校准完成, 1: 校准正在进行中。
  */
__STATIC_INLINE uint32_t LL_ADC_IsCalibrationOnGoing(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的CAL位，判断校准是否正在进行 */
  /* 硬件会在校准完成后自动清除该位 */
  return (READ_BIT(ADCx->CR2, ADC_CR2_CAL) == (ADC_CR2_CAL));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Operation_ADC_Group_Regular ADC层级范围操作：规则组
  * @{
  */

/**
  * @brief  启动ADC规则组转换。
  * @note   在此STM32系列上，此函数仅适用于内部触发（软件启动），不适用于外部触发：
  *         - 如果ADC触发源设置为软件启动，ADC转换会立即开始。
  *         - 如果ADC触发源设置为外部触发，ADC转换启动必须使用函数
  *           @ref LL_ADC_REG_StartConversionExtTrig()。
  *           (如果在外部触发边沿设置期间ADC已使能，ADC转换将在触发事件发生时开始)。
  * @rmtoll CR2      SWSTART        LL_ADC_REG_StartConversionSWStart
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_StartConversionSWStart(ADC_TypeDef *ADCx)
{
  /* 设置SWSTART位启动软件触发转换，同时设置EXTTRIG位使能外部触发转换逻辑 */
  /* 注意：此处同时设置了SWSTART和EXTTRIG，是为了确保在软件触发模式下硬件逻辑正确响应 */
  SET_BIT(ADCx->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
}

/**
  * @brief  通过外部触发启动ADC规则组转换。
  * @note   ADC转换将在ADC启动转换命令之后的下一个触发事件（在选定的触发边沿）开始。
  * @note   在此STM32系列上，此函数适用于从外部触发启动ADC转换。
  *         如果需要内部触发（软件启动），请使用函数 @ref LL_ADC_REG_StartConversionSWStart()。
  * @rmtoll CR2      EXTEN          LL_ADC_REG_StartConversionExtTrig
  * @param  ExternalTriggerEdge 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_REG_TRIG_EXT_RISING (上升沿触发)
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_StartConversionExtTrig(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  /* 设置外部触发边沿控制位，使能外部触发转换 */
  SET_BIT(ADCx->CR2, ExternalTriggerEdge);
}

/**
  * @brief  停止ADC规则组的外部触发转换。
  * @note   在ADC停止转换命令之后，下一个触发事件将不再启动ADC转换。
  *         如果转换正在进行中，它将被完成。
  * @note   在此STM32系列上，没有特定的命令来停止正在进行的转换或停止连续转换模式下的ADC。
  *         这些操作可以通过函数 @ref LL_ADC_Disable() 执行。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_StopConversionExtTrig
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_StopConversionExtTrig(ADC_TypeDef *ADCx)
{
  /* 清除外部触发使能位，禁止外部触发信号启动转换 */
  CLEAR_BIT(ADCx->CR2, ADC_CR2_EXTTRIG);
}

/**
  * @brief  获取ADC规则组转换数据，范围适用于所有ADC配置：所有ADC分辨率和
  *         所有过采样增加的数据宽度（适用于有过采样功能的设备）。
  * @rmtoll DR       RDATA          LL_ADC_REG_ReadConversionData32
  * @param  ADCx ADC实例
  * @retval 数值范围 Min_Data=0x00000000 到 Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_REG_ReadConversionData32(ADC_TypeDef *ADCx)
{
  /* 读取数据寄存器DR的值，掩码提取数据部分 */
  /* 虽然返回值是uint32_t，但这里强制转换为uint16_t再返回是为了兼容旧代码或硬件行为，
     实际上对于过采样可能需要更多位，但此函数读取的是ADC_DR寄存器 */
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_DATA));
}

/**
  * @brief  获取ADC规则组转换数据，范围适用于12位分辨率。
  * @note   对于具有过采样功能的设备：过采样会增加数据宽度，
  *         可能需要扩展范围的函数: @ref LL_ADC_REG_ReadConversionData32。
  * @rmtoll DR       RDATA          LL_ADC_REG_ReadConversionData12
  * @param  ADCx ADC实例
  * @retval 数值范围 Min_Data=0x000 到 Max_Data=0xFFF
  */
__STATIC_INLINE uint16_t LL_ADC_REG_ReadConversionData12(ADC_TypeDef *ADCx)
{
  /* 读取数据寄存器DR的值，返回12位数据 */
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_DATA));
}

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  获取ADC多模转换数据，可以是主ADC数据、从ADC数据或主从拼接的原始数据。
  * @note   如果获取的是主从拼接的原始数据，可以使用宏来获取主ADC或从ADC的转换数据:
  *         参考辅助宏 @ref __LL_ADC_MULTI_CONV_DATA_MASTER_SLAVE()。
  *         (然而这个宏主要用于DMA传输的多模模式，因为此函数可以分别获取主从ADC的数据)。
  * @rmtoll DR       DATA           LL_ADC_REG_ReadMultiConversionData32\n
  *         DR       ADC2DATA       LL_ADC_REG_ReadMultiConversionData32
  * @param  ADCx ADC实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  ConversionData 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_MASTER        (主ADC数据)
  *         @arg @ref LL_ADC_MULTI_SLAVE         (从ADC数据)
  *         @arg @ref LL_ADC_MULTI_MASTER_SLAVE  (主从拼接数据)
  * @retval 数值范围 Min_Data=0x00000000 到 Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_REG_ReadMultiConversionData32(ADC_TypeDef *ADCx, uint32_t ConversionData)
{
  /* 读取DR寄存器，根据ConversionData参数进行移位操作以获取对应的数据 */
  /* 在多模模式下，DR寄存器包含主从ADC的数据，通过移位提取 */
  return (uint32_t)(READ_BIT(ADCx->DR,
                             ADC_DR_ADC2DATA)
                    >> POSITION_VAL(ConversionData)
                   );
}
#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Operation_ADC_Group_Injected ADC层级范围操作：注入组
  * @{
  */

/**
  * @brief  启动ADC注入组转换。
  * @note   在此STM32系列上，此函数仅适用于内部触发（软件启动），不适用于外部触发：
  *         - 如果ADC触发源设置为软件启动，ADC转换会立即开始。
  *         - 如果ADC触发源设置为外部触发，ADC转换启动必须使用函数
  *           @ref LL_ADC_INJ_StartConversionExtTrig()。
  *           (如果在外部触发边沿设置期间ADC已使能，ADC转换将在触发事件发生时开始)。
  * @rmtoll CR2      JSWSTART       LL_ADC_INJ_StartConversionSWStart
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_StartConversionSWStart(ADC_TypeDef *ADCx)
{
  /* 设置JSWSTART位启动注入组软件触发转换，同时设置JEXTTRIG位使能注入组外部触发逻辑 */
  SET_BIT(ADCx->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
}

/**
  * @brief  通过外部触发启动ADC注入组转换。
  * @note   ADC转换将在ADC启动转换命令之后的下一个触发事件（在选定的触发边沿）开始。
  * @note   在此STM32系列上，此函数适用于从外部触发启动ADC注入组转换。
  *         如果需要内部触发（软件启动），请使用函数 @ref LL_ADC_INJ_StartConversionSWStart()。
  * @rmtoll CR2      JEXTEN         LL_ADC_INJ_StartConversionExtTrig
  * @param  ExternalTriggerEdge 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_RISING (上升沿触发)
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_StartConversionExtTrig(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  /* 设置注入组外部触发边沿控制位，使能外部触发转换 */
  SET_BIT(ADCx->CR2, ExternalTriggerEdge);
}
/**
  * @brief  停止ADC注入组的外部触发转换。
  * @note   在执行停止转换命令后，下一个触发事件将不再启动ADC转换。
  *         如果当前正在进行转换，它将会完成。
  * @note   在此STM32系列中，没有特定的命令来停止正在进行的转换
  *         或停止连续模式下的ADC转换。这些操作可以通过
  *         函数 @ref LL_ADC_Disable() 来执行。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_StopConversionExtTrig
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_StopConversionExtTrig(ADC_TypeDef *ADCx)
{
  /* 清除CR2寄存器中的JEXTTRIG位，禁止注入组的外部触发转换 */
  CLEAR_BIT(ADCx->CR2, ADC_CR2_JEXTTRIG);
}

/**
  * @brief  读取ADC注入组转换数据，数据范围适用于所有ADC配置：
  *         所有ADC分辨率以及所有过采样增加的数据宽度（针对支持
  *         过采样功能的设备）。
  * @rmtoll JDR1     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR2     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR3     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR4     JDATA          LL_ADC_INJ_ReadConversionData32
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1 (注入通道1)
  *         @arg @ref LL_ADC_INJ_RANK_2 (注入通道2)
  *         @arg @ref LL_ADC_INJ_RANK_3 (注入通道3)
  *         @arg @ref LL_ADC_INJ_RANK_4 (注入通道4)
  * @retval 介于 Min_Data=0x00000000 和 Max_Data=0xFFFFFFFF 之间的值
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_ReadConversionData32(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank（序列排名）计算JDRx寄存器的地址偏移量 */
  /* __ADC_PTR_REG_OFFSET用于计算指针偏移，__ADC_MASK_SHIFT用于计算偏移掩码 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JDRX_REGOFFSET_MASK));
  
  /* 读取对应JDRx寄存器的值，并屏蔽掉非数据位，返回32位数据 */
  return (uint32_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
  * @brief  读取ADC注入组转换数据，数据范围适用于12位分辨率。
  * @note   对于具有过采样功能的设备：过采样可能会增加数据宽度，
  *         可能需要使用扩展范围的函数：@ref LL_ADC_INJ_ReadConversionData32。
  * @rmtoll JDR1     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR2     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR3     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR4     JDATA          LL_ADC_INJ_ReadConversionData12
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval 介于 Min_Data=0x000 和 Max_Data=0xFFF 之间的值
  */
__STATIC_INLINE uint16_t LL_ADC_INJ_ReadConversionData12(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank计算JDRx寄存器的地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JDRX_REGOFFSET_MASK));
  
  /* 读取数据并强制转换为16位无符号整数返回 */
  return (uint16_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_FLAG_Management ADC 标志位管理
  * @{
  */

/**
  * @brief  获取ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_EOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /*       读取SR寄存器中的EOS标志位，判断是否置1 */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_EOS) == (LL_ADC_FLAG_EOS));
}


/**
  * @brief  获取ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_JEOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /*       读取SR寄存器中的JEOS标志位，判断是否置1 */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_JEOS) == (LL_ADC_FLAG_JEOS));
}

/**
  * @brief  获取ADC模拟看门狗1标志位
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_AWD1
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD1(ADC_TypeDef *ADCx)
{
  /* 读取SR寄存器中的AWD1标志位，判断是否置1 */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

/**
  * @brief  清除ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_ClearFlag_EOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_ClearFlag_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /*       向SR寄存器写入对应位的反码来清除标志位 */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_EOS);
}


/**
  * @brief  清除ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_ClearFlag_JEOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_ClearFlag_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /*       向SR寄存器写入对应位的反码来清除标志位 */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_JEOS);
}

/**
  * @brief  清除ADC模拟看门狗1标志位。
  * @rmtoll SR       AWD            LL_ADC_ClearFlag_AWD1
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_ClearFlag_AWD1(ADC_TypeDef *ADCx)
{
  /* 向SR寄存器写入对应位的反码来清除AWD1标志位 */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_AWD1);
}

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  获取多模式ADC主ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_MST_EOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_EOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /*       读取通用状态寄存器中的EOC位 */
  return (READ_BIT(ADCxy_COMMON->SR, ADC_SR_EOC) == (ADC_SR_EOC));
}

/**
  * @brief  获取多模式ADC从ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_SLV_EOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_EOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  
  /* 计算从ADC状态寄存器的指针地址（偏移量为1个字） */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  /* 读取从ADC的EOS标志位 */
  return (READ_BIT(*preg, LL_ADC_FLAG_EOS_SLV) == (LL_ADC_FLAG_EOS_SLV));
}


/**
  * @brief  获取多模式ADC主ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_MST_JEOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_JEOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /*       读取通用状态寄存器中的JEOC位 */
  return (READ_BIT(ADCxy_COMMON->SR, ADC_SR_JEOC) == (ADC_SR_JEOC));
}

/**
  * @brief  获取多模式ADC从ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_SLV_JEOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_JEOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  
  /* 计算从ADC状态寄存器的指针地址（偏移量为1个字） */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  /* 读取从ADC的JEOS标志位 */
  return (READ_BIT(*preg, LL_ADC_FLAG_JEOS_SLV) == (LL_ADC_FLAG_JEOS_SLV));
}

/**
  * @brief  获取多模式ADC主ADC模拟看门狗1标志位。
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_MST_AWD1
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_AWD1(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 读取主ADC的AWD1标志位 */
  return (READ_BIT(ADCxy_COMMON->SR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

/**
  * @brief  获取多模式ADC从ADC模拟看门狗1标志位。
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_SLV_AWD1
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_AWD1(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 计算从ADC状态寄存器的指针地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  /* 读取从ADC的AWD1标志位 */
  return (READ_BIT(*preg, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */

/** @defgroup ADC_LL_EF_IT_Management ADC 中断管理
  * @{
  */

/**
  * @brief  使能ADC规则组转换序列结束中断。
  * @rmtoll CR1      EOCIE          LL_ADC_EnableIT_EOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_EnableIT_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /* 设置CR1寄存器中的EOCIE位，使能转换结束中断 */
  SET_BIT(ADCx->CR1, ADC_CR1_EOCIE);
}


/**
  * @brief  使能ADC注入组转换序列结束中断。
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_EnableIT_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /* 设置CR1寄存器中的JEOCIE位，使能注入组转换结束中断 */
  SET_BIT(ADCx->CR1, LL_ADC_IT_JEOS);
}

/**
  * @brief  使能ADC模拟看门狗1中断。
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_EnableIT_AWD1(ADC_TypeDef *ADCx)
{
  /* 设置CR1寄存器中的AWDIE位，使能模拟看门狗中断 */
  SET_BIT(ADCx->CR1, LL_ADC_IT_AWD1);
}

/**
  * @brief  禁止ADC规则组转换序列结束中断。
  * @rmtoll CR1      EOCIE          LL_ADC_DisableIT_EOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_DisableIT_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /* 清除CR1寄存器中的EOCIE位，禁止转换结束中断 */
  CLEAR_BIT(ADCx->CR1, ADC_CR1_EOCIE);
}


/**
  * @brief  禁止ADC注入组转换序列结束中断。
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_DisableIT_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /* 清除CR1寄存器中的JEOCIE位，禁止注入组转换结束中断 */
  CLEAR_BIT(ADCx->CR1, LL_ADC_IT_JEOS);
}

/**
  * @brief  禁止ADC模拟看门狗1中断。
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_DisableIT_AWD1(ADC_TypeDef *ADCx)
{
  /* 清除CR1寄存器中的AWDIE位，禁止模拟看门狗中断 */
  CLEAR_BIT(ADCx->CR1, LL_ADC_IT_AWD1);
}

/**
  * @brief  获取ADC规则组转换序列结束中断状态
  *         (0: 中断禁止, 1: 中断使能)。
  * @rmtoll CR1      EOCIE          LL_ADC_IsEnabledIT_EOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /* 读取CR1寄存器中的EOCIE位状态 */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_EOS) == (LL_ADC_IT_EOS));
}


/**
  * @brief  获取ADC注入组转换序列结束中断状态
  *         (0: 中断禁止, 1: 中断使能)。
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /* 读取CR1寄存器中的JEOCIE位状态 */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_JEOS) == (LL_ADC_IT_JEOS));
}

/**
  * @brief  获取ADC模拟看门狗1中断状态
  *         (0: 中断禁止, 1: 中断使能)。
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD1(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器中的AWDIE位状态 */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_AWD1) == (LL_ADC_IT_AWD1));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_EF_Init 初始化和反初始化函数
  * @{
  */

/* ADC通用参数和多模式的某些功能的初始化 */
ErrorStatus LL_ADC_CommonDeInit(ADC_Common_TypeDef *ADCxy_COMMON);
ErrorStatus LL_ADC_CommonInit(ADC_Common_TypeDef *ADCxy_COMMON, LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
void        LL_ADC_CommonStructInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);

/* ADC实例、规则组和注入组的反初始化 */
/* (注入组的可用性取决于STM32系列) */
ErrorStatus LL_ADC_DeInit(ADC_TypeDef *ADCx);

/* ADC实例某些功能的初始化 */
ErrorStatus LL_ADC_Init(ADC_TypeDef *ADCx, LL_ADC_InitTypeDef *ADC_InitStruct);
void        LL_ADC_StructInit(LL_ADC_InitTypeDef *ADC_InitStruct);

/* ADC实例和规则组某些功能的初始化 */
ErrorStatus LL_ADC_REG_Init(ADC_TypeDef *ADCx, LL_ADC_REG_InitTypeDef *ADC_REG_InitStruct);
void        LL_ADC_REG_StructInit(LL_ADC_REG_InitTypeDef *ADC_REG_InitStruct);

/* ADC实例和注入组某些功能的初始化 */
ErrorStatus LL_ADC_INJ_Init(ADC_TypeDef *ADCx, LL_ADC_INJ_InitTypeDef *ADC_INJ_InitStruct);
void        LL_ADC_INJ_StructInit(LL_ADC_INJ_InitTypeDef *ADC_INJ_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* ADC1 || ADC2 || ADC3 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_LL_ADC_H */
