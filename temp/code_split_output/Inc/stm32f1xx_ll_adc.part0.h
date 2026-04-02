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
