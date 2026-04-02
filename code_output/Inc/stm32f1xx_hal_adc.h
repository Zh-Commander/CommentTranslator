/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc.h
  * @author  MCD Application Team
  * @brief   ADC HAL库函数原型头文件。
  ******************************************************************************
  * @attention
  *
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_ADC_H
#define __STM32F1xx_HAL_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"  
/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */ 

/* 导出类型 ------------------------------------------------------------*/ 
/** @defgroup ADC_Exported_Types ADC 导出类型
  * @{
  */

/** 
  * @brief  ADC初始化结构体定义 (用于ADC及常规组初始化)
  * @note   该结构体的参数分为两个作用域:
  *          - 整个ADC作用域 (影响常规组和注入组): DataAlign, ScanConvMode.
  *          - 常规组作用域: ContinuousConvMode, NbrOfConversion, DiscontinuousConvMode, NbrOfDiscConversion, ExternalTrigConvEdge, ExternalTrigConv.
  * @note   使用函数 HAL_ADC_Init() 设置这些参数的前提是ADC处于特定状态。
  *         ADC必须处于禁用状态，或者处于使能状态但常规组没有正在进行的转换。
  */
typedef struct
{
  uint32_t DataAlign;                        /*!< 指定ADC数据对齐方式为右对齐 (寄存器第11位为MSB，第0位为LSB，默认设置)
                                                  或左对齐 (如果是常规组: 寄存器第15位为MSB，第4位为LSB；如果是注入组 (由于偏移应用后可能为负值，MSB保留为符号位): 寄存器第14位为MSB，第3位为LSB)。
                                                  该参数可以是 @ref ADC_Data_align 中的值 */
  uint32_t ScanConvMode;                     /*!< 配置常规组和注入组的序列器。
                                                  该参数可以与参数 'DiscontinuousConvMode' 关联使用，将主序列细分为连续的部分。
                                                  如果禁用: 转换在单次模式下执行 (转换一个通道，即等级1定义的通道)。
                                                               参数 'NbrOfConversion' 和 'InjectedNbrOfConversion' 被忽略 (相当于设置为1)。
                                                  如果使能:  转换在序列模式下执行 (由 'NbrOfConversion'/'InjectedNbrOfConversion' 定义多个等级，每个等级对应一个通道)。
                                                               扫描方向向上: 从等级1到等级 'n'。
                                                  该参数可以是 @ref ADC_Scan_mode 中的值
                                                  注意: 对于常规组，此参数应在转换时通过轮询 (HAL_ADC_Start 且 Discontinuous mode 和 NbrOfDiscConversion=1)
                                                        或通过 DMA (HAL_ADC_Start_DMA) 使能，而不是通过中断 (HAL_ADC_Start_IT): 在扫描模式下，中断仅在序列的
                                                        最后一次转换时触发。之前的所有转换都会被最后一次转换覆盖。
                                                        注入组在扫描模式下使用没有此限制: 每个等级都有自己的结果寄存器，数据不会被覆盖。 */
  FunctionalState ContinuousConvMode;         /*!< 指定常规组的转换是在单次模式 (一次转换) 还是连续模式下执行，
                                                  在选定的触发器触发后 (软件启动或外部触发)。
                                                  该参数可设置为 ENABLE 或 DISABLE。 */
  uint32_t NbrOfConversion;                  /*!< 指定常规组序列器中转换的等级数量。
                                                  要使用常规组序列器并转换多个等级，必须使能参数 'ScanConvMode'。
                                                  该参数必须是 Min_Data = 1 到 Max_Data = 16 之间的数字。 */
  FunctionalState  DiscontinuousConvMode;    /*!< 指定常规组的转换序列是在完整序列还是不连续序列 (主序列细分为连续部分) 下执行。
                                                  不连续模式仅在序列器使能时 (参数 'ScanConvMode') 使用。如果序列器禁用，此参数被忽略。
                                                  不连续模式仅在连续模式禁用时才能使能。如果连续模式使能，此参数设置将被忽略。
                                                  该参数可设置为 ENABLE 或 DISABLE。 */
  uint32_t NbrOfDiscConversion;              /*!< 指定常规组主序列 (参数 NbrOfConversion) 将被细分的不连续转换次数。
                                                  如果参数 'DiscontinuousConvMode' 禁用，此参数被忽略。
                                                  该参数必须是 Min_Data = 1 到 Max_Data = 8 之间的数字。 */
  uint32_t ExternalTrigConv;                 /*!< 选择用于触发常规组转换开始的外部事件。
                                                  如果设置为 ADC_SOFTWARE_START，则禁用外部触发。
                                                  如果设置为外部触发源，则在事件上升沿触发。
                                                  该参数可以是 @ref ADC_External_trigger_source_Regular 中的值 */
}ADC_InitTypeDef;

/** 
  * @brief  ADC通道配置结构体定义 (用于常规组)
  * @note   使用函数 HAL_ADC_ConfigChannel() 设置这些参数的前提是ADC处于特定状态。
  *         ADC必须处于禁用状态，或者处于使能状态但常规组没有正在进行的转换。
  */ 
typedef struct 
{
  uint32_t Channel;                /*!< 指定要配置到ADC常规组中的通道。
                                        该参数可以是 @ref ADC_channels 中的值
                                        注意: 根据具体设备，某些通道可能在封装引脚上不可用。请参考设备数据手册了解通道可用性。
                                        注意: 在具有多个ADC的STM32F1设备上: 只有ADC1可以访问内部测量通道。
                                        注意: 在STM32F10xx8和STM32F10xxB设备上: 当ADC使用注入触发进行转换时，可能会在PA0引脚上产生低幅度电压毛刺 (在ADC输入0上)。
                                              建议分配模拟通道，以便将通道0配置为注入通道。
                                              更多详情请参考这些设备的勘误表。 */
  uint32_t Rank;                   /*!< 指定在常规组序列器中的等级 
                                        该参数可以是 @ref ADC_regular_rank 中的值
                                        注意: 如果需要禁用某个通道或更改转换序列的顺序，可以通过新的通道设置覆盖包含先前通道设置的等级 (或调整参数转换数量) */
  uint32_t SamplingTime;           /*!< 为选定通道设置的采样时间值。
                                        单位: ADC时钟周期
                                        转换时间是采样时间与处理时间 (12位ADC分辨率下为12.5个ADC时钟周期) 之和。
                                        该参数可以是 @ref ADC_sampling_times 中的值
                                        注意: 此参数更新通道的属性，该通道可用于常规组和/或注入组。
                                                 如果同一通道之前已在另一组 (常规/注入) 中配置，它将被更新为最新设置。
                                        注意: 在使用内部测量通道 时，
                                              必须遵守采样时间限制 (采样时间可根据ADC时钟频率和采样时间设置进行调整)
                                              请参考设备数据手册获取时序值，参数 TS_vrefint, TS_temp (大致范围: 5us 到 17.1us 最小值)。 */
}ADC_ChannelConfTypeDef;

/**
  * @brief  ADC 模拟看门狗配置结构体定义
  * @note   通过函数设置这些参数的前提是ADC处于特定状态。
  *         ADC状态可以是禁用，或者是使能但常规组和注入组没有正在进行的转换。
  */
typedef struct
{
  uint32_t WatchdogMode;      /*!< 配置ADC模拟看门狗模式: 单通道/所有通道, 常规组/注入组。
                                   该参数可以是 @ref ADC_analog_watchdog_mode 中的值。 */
  uint32_t Channel;           /*!< 选择模拟看门狗监控的ADC通道。
                                   仅当看门狗模式配置为单通道时 (参数 WatchdogMode)，此参数有效。
                                   该参数可以是 @ref ADC_channels 中的值。 */
  FunctionalState  ITMode;    /*!< 指定模拟看门狗是配置为中断模式还是轮询模式。
                                   该参数可设置为 ENABLE 或 DISABLE */
  uint32_t HighThreshold;     /*!< 配置ADC模拟看门狗高阈值。
                                   该参数必须是 Min_Data = 0x000 到 Max_Data = 0xFFF 之间的数字。 */
  uint32_t LowThreshold;      /*!< 配置ADC模拟看门狗低阈值。
                                   该参数必须是 Min_Data = 0x000 到 Max_Data = 0xFFF 之间的数字。 */
  uint32_t WatchdogNumber;    /*!< 保留供将来使用，可设置为 0 */
}ADC_AnalogWDGConfTypeDef;

/** 
  * @brief  HAL ADC 状态机: ADC状态定义 (位域)
  */ 
/* ADC全局范围的状态 */
#define HAL_ADC_STATE_RESET             0x00000000U    /*!< ADC尚未初始化或已禁用 */
#define HAL_ADC_STATE_READY             0x00000001U    /*!< ADC外设准备就绪 */
#define HAL_ADC_STATE_BUSY_INTERNAL     0x00000002U    /*!< ADC忙于内部处理 (初始化、校准) */
#define HAL_ADC_STATE_TIMEOUT           0x00000004U    /*!< 发生超时 */

/* ADC错误状态 */
#define HAL_ADC_STATE_ERROR_INTERNAL    0x00000010U    /*!< 发生内部错误 */
#define HAL_ADC_STATE_ERROR_CONFIG      0x00000020U    /*!< 发生配置错误 */
#define HAL_ADC_STATE_ERROR_DMA         0x00000040U    /*!< 发生DMA错误 */

/* ADC常规组状态 */
#define HAL_ADC_STATE_REG_BUSY          0x00000100U    /*!< 常规组正在进行转换或可能发生转换 (通过连续模式、
                                                           外部触发、低功耗自动上电、多模式ADC主控) */
#define HAL_ADC_STATE_REG_EOC           0x00000200U    /*!< 常规组转换数据可用 */
#define HAL_ADC_STATE_REG_OVR           0x00000400U    /*!< STM32F1设备上不可用: 发生溢出 */
#define HAL_ADC_STATE_REG_EOSMP         0x00000800U    /*!< STM32F1设备上不可用: 采样结束标志置位 */

/* ADC注入组状态 */
#define HAL_ADC_STATE_INJ_BUSY          0x00001000U    /*!< 注入组正在进行转换或可能发生转换 (通过自动注入模式、
                                                           外部触发、低功耗自动上电、多模式ADC主控) */
#define HAL_ADC_STATE_INJ_EOC           0x00002000U    /*!< 注入组转换数据可用 */
#define HAL_ADC_STATE_INJ_JQOVF         0x00004000U    /*!< STM32F1设备上不可用: 注入队列溢出发生 */

/* ADC模拟看门狗状态 */
#define HAL_ADC_STATE_AWD1              0x00010000U    /*!< 模拟看门狗1越界发生 */
#define HAL_ADC_STATE_AWD2              0x00020000U    /*!< STM32F1设备上不可用: 模拟看门狗2越界发生 */
#define HAL_ADC_STATE_AWD3              0x00040000U    /*!< STM32F1设备上不可用: 模拟看门狗3越界发生 */

/* ADC多模式状态 */
#define HAL_ADC_STATE_MULTIMODE_SLAVE   0x00100000U    /*!< ADC处于多模式从状态，由另一个ADC主控 ( */


/**
  * @brief  ADC 句柄结构体定义  
  */ 
typedef struct __ADC_HandleTypeDef
{
  ADC_TypeDef                   *Instance;              /*!< 寄存器基地址 */

  ADC_InitTypeDef               Init;                   /*!< ADC初始化参数 */

  DMA_HandleTypeDef             *DMA_Handle;            /*!< DMA处理句柄指针 */

  HAL_LockTypeDef               Lock;                   /*!< ADC锁定对象 */
  
  __IO uint32_t                 State;                  /*!< ADC通信状态 (ADC状态的位图) */

  __IO uint32_t                 ErrorCode;              /*!< ADC错误代码 */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  void (* ConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);              /*!< ADC转换完成回调函数 */
  void (* ConvHalfCpltCallback)(struct __ADC_HandleTypeDef *hadc);          /*!< ADC转换DMA半传输回调函数 */
  void (* LevelOutOfWindowCallback)(struct __ADC_HandleTypeDef *hadc);      /*!< ADC模拟看门狗1回调函数 */
  void (* ErrorCallback)(struct __ADC_HandleTypeDef *hadc);                 /*!< ADC错误回调函数 */
  void (* InjectedConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);      /*!< ADC注入组转换完成回调函数 */       /*!< ADC采样结束回调函数 */
  void (* MspInitCallback)(struct __ADC_HandleTypeDef *hadc);               /*!< ADC Msp初始化回调函数 */
  void (* MspDeInitCallback)(struct __ADC_HandleTypeDef *hadc);             /*!< ADC Msp反初始化回调函数 */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}ADC_HandleTypeDef;


#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL ADC 回调ID枚举定义
  */
typedef enum
{
  HAL_ADC_CONVERSION_COMPLETE_CB_ID     = 0x00U,  /*!< ADC转换完成回调ID */
  HAL_ADC_CONVERSION_HALF_CB_ID         = 0x01U,  /*!< ADC转换DMA半传输回调ID */
  HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID   = 0x02U,  /*!< ADC模拟看门狗1回调ID */
  HAL_ADC_ERROR_CB_ID                   = 0x03U,  /*!< ADC错误回调ID */
  HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID = 0x04U,  /*!< ADC注入组转换完成回调ID */
  HAL_ADC_MSPINIT_CB_ID                 = 0x09U,  /*!< ADC Msp初始化回调ID */
  HAL_ADC_MSPDEINIT_CB_ID               = 0x0AU   /*!< ADC Msp反初始化回调ID */
} HAL_ADC_CallbackIDTypeDef;

/**
  * @brief  HAL ADC 回调函数指针定义
  */
typedef  void (*pADC_CallbackTypeDef)(ADC_HandleTypeDef *hadc); /*!< 指向ADC回调函数的指针 */

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */



/* 导出常量 --------------------------------------------------------*/

/** @defgroup ADC_Exported_Constants ADC 导出常量
  * @{
  */

/** @defgroup ADC_Error_Code ADC 错误代码
  * @{
  */
#define HAL_ADC_ERROR_NONE                0x00U   /*!< 无错误                                              */
#define HAL_ADC_ERROR_INTERNAL            0x01U   /*!< ADC IP内部错误: 如时钟问题、
                                                       使能/禁用、错误状态                       */
#define HAL_ADC_ERROR_OVR                 0x02U   /*!< 溢出错误                                         */
#define HAL_ADC_ERROR_DMA                 0x04U   /*!< DMA传输错误                                    */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define HAL_ADC_ERROR_INVALID_CALLBACK  (0x10U)   /*!< 无效回调错误 */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
/**
  * @}
  */


/** @defgroup ADC_Data_align ADC 数据对齐
  * @{
  */
#define ADC_DATAALIGN_RIGHT      0x00000000U
#define ADC_DATAALIGN_LEFT       ((uint32_t)ADC_CR2_ALIGN)
/**
  * @}
  */

/** @defgroup ADC_Scan_mode ADC 扫描模式
  * @{
  */
/* 注意: 扫描模式值不是 ENABLE/DISABLE 二选一，是为了     */
/*       兼容其他具有带附加选项序列器的STM32设备。                                                  */
#define ADC_SCAN_DISABLE         0x00000000U
#define ADC_SCAN_ENABLE          ((uint32_t)ADC_CR1_SCAN)
/**
  * @}
  */

/** @defgroup ADC_External_trigger_edge_Regular 常规组ADC外部触发使能
  * @{
  */
#define ADC_EXTERNALTRIGCONVEDGE_NONE           0x00000000U
#define ADC_EXTERNALTRIGCONVEDGE_RISING         ((uint32_t)ADC_CR2_EXTTRIG)
/**
  * @}
  */
/** @defgroup ADC_channels ADC channels
  * @{
  */
/* 注意：取决于具体的设备型号，某些通道可能在封装引脚上不可用 */
/*       请参考设备数据手册以获取通道可用性信息           */
#define ADC_CHANNEL_0                       0x00000000U   // ADC通道0，通常对应内部连接或保留
#define ADC_CHANNEL_1           ((uint32_t)(                                                                    ADC_SQR3_SQ1_0))  // ADC通道1
#define ADC_CHANNEL_2           ((uint32_t)(                                                   ADC_SQR3_SQ1_1                 ))  // ADC通道2
#define ADC_CHANNEL_3           ((uint32_t)(                                                   ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))  // ADC通道3
#define ADC_CHANNEL_4           ((uint32_t)(                                  ADC_SQR3_SQ1_2                                  ))  // ADC通道4
#define ADC_CHANNEL_5           ((uint32_t)(                                  ADC_SQR3_SQ1_2                  | ADC_SQR3_SQ1_0))  // ADC通道5
#define ADC_CHANNEL_6           ((uint32_t)(                                  ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1                 ))  // ADC通道6
#define ADC_CHANNEL_7           ((uint32_t)(                                  ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))  // ADC通道7
#define ADC_CHANNEL_8           ((uint32_t)(                 ADC_SQR3_SQ1_3                                                   ))  // ADC通道8
#define ADC_CHANNEL_9           ((uint32_t)(                 ADC_SQR3_SQ1_3                                   | ADC_SQR3_SQ1_0))  // ADC通道9
#define ADC_CHANNEL_10          ((uint32_t)(                 ADC_SQR3_SQ1_3                  | ADC_SQR3_SQ1_1                 ))  // ADC通道10
#define ADC_CHANNEL_11          ((uint32_t)(                 ADC_SQR3_SQ1_3                  | ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))  // ADC通道11
#define ADC_CHANNEL_12          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2                                  ))  // ADC通道12
#define ADC_CHANNEL_13          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2                  | ADC_SQR3_SQ1_0))  // ADC通道13
#define ADC_CHANNEL_14          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1                 ))  // ADC通道14
#define ADC_CHANNEL_15          ((uint32_t)(                 ADC_SQR3_SQ1_3 | ADC_SQR3_SQ1_2 | ADC_SQR3_SQ1_1 | ADC_SQR3_SQ1_0))  // ADC通道15
#define ADC_CHANNEL_16          ((uint32_t)(ADC_SQR3_SQ1_4                                                                    ))  // ADC通道16
#define ADC_CHANNEL_17          ((uint32_t)(ADC_SQR3_SQ1_4                                                    | ADC_SQR3_SQ1_0))  // ADC通道17

#define ADC_CHANNEL_TEMPSENSOR  ADC_CHANNEL_16  /* ADC内部通道：温度传感器 (没有连接到设备引脚) */
#define ADC_CHANNEL_VREFINT     ADC_CHANNEL_17  /* ADC内部通道：内部参考电压 (没有连接到设备引脚) */
/**
  * @}
  */

/** @defgroup ADC_sampling_times ADC sampling times
  * @{
  */
#define ADC_SAMPLETIME_1CYCLE_5                   0x00000000U                                              /*!< 采样时间：1.5个ADC时钟周期 */
#define ADC_SAMPLETIME_7CYCLES_5      ((uint32_t)(                                      ADC_SMPR2_SMP0_0)) /*!< 采样时间：7.5个ADC时钟周期 */
#define ADC_SAMPLETIME_13CYCLES_5     ((uint32_t)(                   ADC_SMPR2_SMP0_1                   )) /*!< 采样时间：13.5个ADC时钟周期 */
#define ADC_SAMPLETIME_28CYCLES_5     ((uint32_t)(                   ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)) /*!< 采样时间：28.5个ADC时钟周期 */
#define ADC_SAMPLETIME_41CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2                                      )) /*!< 采样时间：41.5个ADC时钟周期 */
#define ADC_SAMPLETIME_55CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2                    | ADC_SMPR2_SMP0_0)) /*!< 采样时间：55.5个ADC时钟周期 */
#define ADC_SAMPLETIME_71CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1                   )) /*!< 采样时间：71.5个ADC时钟周期 */
#define ADC_SAMPLETIME_239CYCLES_5    ((uint32_t)(ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)) /*!< 采样时间：239.5个ADC时钟周期 */
/**
  * @}
  */

/** @defgroup ADC_regular_rank ADC rank into regular group
  * @{
  */
/* ADC规则组中的排名定义，用于设置转换顺序 */
#define ADC_REGULAR_RANK_1                 0x00000001U  // 规则组第1个转换通道
#define ADC_REGULAR_RANK_2                 0x00000002U  // 规则组第2个转换通道
#define ADC_REGULAR_RANK_3                 0x00000003U  // 规则组第3个转换通道
#define ADC_REGULAR_RANK_4                 0x00000004U  // 规则组第4个转换通道
#define ADC_REGULAR_RANK_5                 0x00000005U  // 规则组第5个转换通道
#define ADC_REGULAR_RANK_6                 0x00000006U  // 规则组第6个转换通道
#define ADC_REGULAR_RANK_7                 0x00000007U  // 规则组第7个转换通道
#define ADC_REGULAR_RANK_8                 0x00000008U  // 规则组第8个转换通道
#define ADC_REGULAR_RANK_9                 0x00000009U  // 规则组第9个转换通道
#define ADC_REGULAR_RANK_10                0x0000000AU  // 规则组第10个转换通道
#define ADC_REGULAR_RANK_11                0x0000000BU  // 规则组第11个转换通道
#define ADC_REGULAR_RANK_12                0x0000000CU  // 规则组第12个转换通道
#define ADC_REGULAR_RANK_13                0x0000000DU  // 规则组第13个转换通道
#define ADC_REGULAR_RANK_14                0x0000000EU  // 规则组第14个转换通道
#define ADC_REGULAR_RANK_15                0x0000000FU  // 规则组第15个转换通道
#define ADC_REGULAR_RANK_16                0x00000010U  // 规则组第16个转换通道
/**
  * @}
  */

/** @defgroup ADC_analog_watchdog_mode ADC analog watchdog mode
  * @{
  */
/* ADC模拟看门狗模式配置 */
#define ADC_ANALOGWATCHDOG_NONE                             0x00000000U  // 不使用模拟看门狗
#define ADC_ANALOGWATCHDOG_SINGLE_REG           ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN))  // 单通道模式，监控规则组
#define ADC_ANALOGWATCHDOG_SINGLE_INJEC         ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_JAWDEN)) // 单通道模式，监控注入组
#define ADC_ANALOGWATCHDOG_SINGLE_REGINJEC      ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN)) // 单通道模式，监控规则组和注入组
#define ADC_ANALOGWATCHDOG_ALL_REG              ((uint32_t)ADC_CR1_AWDEN)  // 所有通道模式，监控规则组
#define ADC_ANALOGWATCHDOG_ALL_INJEC            ((uint32_t)ADC_CR1_JAWDEN) // 所有通道模式，监控注入组
#define ADC_ANALOGWATCHDOG_ALL_REGINJEC         ((uint32_t)(ADC_CR1_AWDEN | ADC_CR1_JAWDEN)) // 所有通道模式，监控规则组和注入组
/**
  * @}
  */

/** @defgroup ADC_conversion_group ADC conversion group
  * @{
  */
/* ADC转换组定义 */
#define ADC_REGULAR_GROUP             ((uint32_t)(ADC_FLAG_EOC))  // 规则转换组
#define ADC_INJECTED_GROUP            ((uint32_t)(ADC_FLAG_JEOC)) // 注入转换组
#define ADC_REGULAR_INJECTED_GROUP    ((uint32_t)(ADC_FLAG_EOC | ADC_FLAG_JEOC)) // 规则组和注入组
/**
  * @}
  */

/** @defgroup ADC_Event_type ADC Event type
  * @{
  */
#define ADC_AWD_EVENT               ((uint32_t)ADC_FLAG_AWD)   /*!< ADC模拟看门狗事件 */

#define ADC_AWD1_EVENT              ADC_AWD_EVENT              /*!< ADC模拟看门狗1事件：为了与其他具有多个模拟看门狗的STM32设备兼容的替代命名 */
/**
  * @}
  */

/** @defgroup ADC_interrupts_definition ADC interrupts definition
  * @{
  */
/* ADC中断定义 */
#define ADC_IT_EOC           ADC_CR1_EOCIE        /*!< ADC规则组转换结束中断源 */
#define ADC_IT_JEOC          ADC_CR1_JEOCIE       /*!< ADC注入组转换结束中断源 */
#define ADC_IT_AWD           ADC_CR1_AWDIE        /*!< ADC模拟看门狗中断源 */
/**
  * @}
  */

/** @defgroup ADC_flags_definition ADC flags definition
  * @{
  */
/* ADC标志位定义 */
#define ADC_FLAG_STRT          ADC_SR_STRT     /*!< ADC规则组转换开始标志 */
#define ADC_FLAG_JSTRT         ADC_SR_JSTRT    /*!< ADC注入组转换开始标志 */
#define ADC_FLAG_EOC           ADC_SR_EOC      /*!< ADC规则组转换结束标志 */
#define ADC_FLAG_JEOC          ADC_SR_JEOC     /*!< ADC注入组转换结束标志 */
#define ADC_FLAG_AWD           ADC_SR_AWD      /*!< ADC模拟看门狗标志 */
/**
  * @}
  */


/**
  * @}
  */ 

/* Private constants ---------------------------------------------------------*/
/* 私有常量 -------------------------------------------------------------------*/

/** @addtogroup ADC_Private_Constants ADC Private Constants
  * @{
  */

/** @defgroup ADC_conversion_cycles ADC conversion cycles
  * @{
  */
/* ADC转换周期数 (单位: ADC时钟周期)                           */
/* (选定的采样时间 + 12.5个ADC时钟周期的转换时间，分辨率为12位) */
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_1CYCLE5                  14U   // 采样时间1.5周期 + 转换时间12.5周期 = 14周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_7CYCLES5                 20U   // 采样时间7.5周期 + 转换时间12.5周期 = 20周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_13CYCLES5                26U   // 采样时间13.5周期 + 转换时间12.5周期 = 26周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_28CYCLES5                41U   // 采样时间28.5周期 + 转换时间12.5周期 = 41周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_41CYCLES5                54U   // 采样时间41.5周期 + 转换时间12.5周期 = 54周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_55CYCLES5                68U   // 采样时间55.5周期 + 转换时间12.5周期 = 68周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_71CYCLES5                84U   // 采样时间71.5周期 + 转换时间12.5周期 = 84周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_239CYCLES5              252U   // 采样时间239.5周期 + 转换时间12.5周期 = 252周期
/**
  * @}
  */

/** @defgroup ADC_sampling_times_all_channels ADC sampling times all channels
  * @{
  */
/* 用于配置所有通道采样时间的掩码定义，主要用于SMPR1和SMPR2寄存器 */
/* SMPR2寄存器控制通道0-9的采样时间 */
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2                                          \
     (ADC_SMPR2_SMP9_2 | ADC_SMPR2_SMP8_2 | ADC_SMPR2_SMP7_2 | ADC_SMPR2_SMP6_2 |     \
      ADC_SMPR2_SMP5_2 | ADC_SMPR2_SMP4_2 | ADC_SMPR2_SMP3_2 | ADC_SMPR2_SMP2_2 |     \
      ADC_SMPR2_SMP1_2 | ADC_SMPR2_SMP0_2)
/* SMPR1寄存器控制通道10-17的采样时间 */
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2                                          \
     (ADC_SMPR1_SMP17_2 | ADC_SMPR1_SMP16_2 | ADC_SMPR1_SMP15_2 | ADC_SMPR1_SMP14_2 | \
      ADC_SMPR1_SMP13_2 | ADC_SMPR1_SMP12_2 | ADC_SMPR1_SMP11_2 | ADC_SMPR1_SMP10_2 )

#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1                                          \
     (ADC_SMPR2_SMP9_1 | ADC_SMPR2_SMP8_1 | ADC_SMPR2_SMP7_1 | ADC_SMPR2_SMP6_1 |     \
      ADC_SMPR2_SMP5_1 | ADC_SMPR2_SMP4_1 | ADC_SMPR2_SMP3_1 | ADC_SMPR2_SMP2_1 |     \
      ADC_SMPR2_SMP1_1 | ADC_SMPR2_SMP0_1)
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1                                          \
     (ADC_SMPR1_SMP17_1 | ADC_SMPR1_SMP16_1 | ADC_SMPR1_SMP15_1 | ADC_SMPR1_SMP14_1 | \
      ADC_SMPR1_SMP13_1 | ADC_SMPR1_SMP12_1 | ADC_SMPR1_SMP11_1 | ADC_SMPR1_SMP10_1 )

#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0                                          \
     (ADC_SMPR2_SMP9_0 | ADC_SMPR2_SMP8_0 | ADC_SMPR2_SMP7_0 | ADC_SMPR2_SMP6_0 |     \
      ADC_SMPR2_SMP5_0 | ADC_SMPR2_SMP4_0 | ADC_SMPR2_SMP3_0 | ADC_SMPR2_SMP2_0 |     \
      ADC_SMPR2_SMP1_0 | ADC_SMPR2_SMP0_0)
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0                                          \
     (ADC_SMPR1_SMP17_0 | ADC_SMPR1_SMP16_0 | ADC_SMPR1_SMP15_0 | ADC_SMPR1_SMP14_0 | \
      ADC_SMPR1_SMP13_0 | ADC_SMPR1_SMP12_0 | ADC_SMPR1_SMP11_0 | ADC_SMPR1_SMP10_0 )

/* 以下宏定义用于一次性设置SMPR2寄存器中所有通道(通道0-9)的采样时间 */
#define ADC_SAMPLETIME_1CYCLE5_SMPR2ALLCHANNELS    0x00000000U
#define ADC_SAMPLETIME_7CYCLES5_SMPR2ALLCHANNELS   (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
#define ADC_SAMPLETIME_13CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1)
#define ADC_SAMPLETIME_28CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
#define ADC_SAMPLETIME_41CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2)
#define ADC_SAMPLETIME_55CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
#define ADC_SAMPLETIME_71CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1)
#define ADC_SAMPLETIME_239CYCLES5_SMPR2ALLCHANNELS (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)

/* 以下宏定义用于一次性设置SMPR1寄存器中所有通道(通道10-17)的采样时间 */
#define ADC_SAMPLETIME_1CYCLE5_SMPR1ALLCHANNELS    0x00000000U
#define ADC_SAMPLETIME_7CYCLES5_SMPR1ALLCHANNELS   (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
#define ADC_SAMPLETIME_13CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1)
#define ADC_SAMPLETIME_28CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
#define ADC_SAMPLETIME_41CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2)
#define ADC_SAMPLETIME_55CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
#define ADC_SAMPLETIME_71CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1)
#define ADC_SAMPLETIME_239CYCLES5_SMPR1ALLCHANNELS (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
/**
  * @}
  */

/* 所有转换后标志位的组合：EOC/EOS, JEOC/JEOS, OVR, AWDx */
#define ADC_FLAG_POSTCONV_ALL   (ADC_FLAG_EOC | ADC_FLAG_JEOC | ADC_FLAG_AWD )

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/* 导出宏 --------------------------------------------------------------------*/

/** @defgroup ADC_Exported_Macros ADC Exported Macros
  * @{
  */
/* 宏定义供HAL驱动内部使用，也可能用于最终用户的代码中 */    

/**
  * @brief 使能ADC外设
  * @note ADC使能后需要延时一段时间等待ADC稳定
  *       (请参考设备数据手册，参数 tSTAB)
  * @note 在STM32F1系列上，如果ADC已经使能，此宏会触发规则组的软件启动转换
  * @param __HANDLE__: ADC句柄指针
  * @retval 无
  */
#define __HAL_ADC_ENABLE(__HANDLE__)                                           \
  (SET_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADON)))  // 设置CR2寄存器的ADON位使能ADC
    
/**
  * @brief 关闭ADC外设
  * @param __HANDLE__: ADC句柄指针
  * @retval 无
  */
#define __HAL_ADC_DISABLE(__HANDLE__)                                          \
  (CLEAR_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADON))) // 清除CR2寄存器的ADON位关闭ADC
    
/** @brief 使能ADC转换结束中断。
  * @param __HANDLE__: ADC句柄指针
  * @param __INTERRUPT__: ADC中断源
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_IT_EOC: ADC规则组转换结束中断源
  *            @arg ADC_IT_JEOC: ADC注入组转换结束中断源
  *            @arg ADC_IT_AWD: ADC模拟看门狗中断源
  * @retval 无
  */
#define __HAL_ADC_ENABLE_IT(__HANDLE__, __INTERRUPT__)                         \
  (SET_BIT((__HANDLE__)->Instance->CR1, (__INTERRUPT__)))  // 设置CR1寄存器中对应的中断使能位
    
/** @brief 关闭ADC转换结束中断。
  * @param __HANDLE__: ADC句柄指针
  * @param __INTERRUPT__: ADC中断源
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_IT_EOC: ADC规则组转换结束中断源
  *            @arg ADC_IT_JEOC: ADC注入组转换结束中断源
  *            @arg ADC_IT_AWD: ADC模拟看门狗中断源
  * @retval 无
  */
#define __HAL_ADC_DISABLE_IT(__HANDLE__, __INTERRUPT__)                        \
  (CLEAR_BIT((__HANDLE__)->Instance->CR1, (__INTERRUPT__))) // 清除CR1寄存器中对应的中断使能位

/** @brief  检查指定的ADC中断源是否已使能。
  * @param __HANDLE__: ADC句柄指针
  * @param __INTERRUPT__: 需要检查的ADC中断源
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_IT_EOC: ADC规则组转换结束中断源
  *            @arg ADC_IT_JEOC: ADC注入组转换结束中断源
  *            @arg ADC_IT_AWD: ADC模拟看门狗中断源
  * @retval 无
  */
#define __HAL_ADC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)                     \
  (((__HANDLE__)->Instance->CR1 & (__INTERRUPT__)) == (__INTERRUPT__)) // 读取CR1寄存器并判断中断使能位是否置位

/** @brief 获取选定的ADC标志位状态。
  * @param __HANDLE__: ADC句柄指针
  * @param __FLAG__: ADC标志位
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_FLAG_STRT: ADC规则组转换开始标志
  *            @arg ADC_FLAG_JSTRT: ADC注入组转换开始标志
  *            @arg ADC_FLAG_EOC: ADC规则组转换结束标志
  *            @arg ADC_FLAG_JEOC: ADC注入组转换结束标志
  *            @arg ADC_FLAG_AWD: ADC模拟看门狗标志
  * @retval 无
  */
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__)                               \
  ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__)) // 读取状态寄存器SR并判断标志位是否置位
    
/** @brief 清除ADC的挂起标志位
  * @param __HANDLE__: ADC句柄指针
  * @param __FLAG__: ADC标志位
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_FLAG_STRT: ADC规则组转换开始标志
  *            @arg ADC_FLAG_JSTRT: ADC注入组转换开始标志
  *            @arg ADC_FLAG_EOC: ADC规则组转换结束标志
  *            @arg ADC_FLAG_JEOC: ADC注入组转换结束标志
  *            @arg ADC_FLAG_AWD: ADC模拟看门狗标志
  * @retval 无
  */
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__)                             \
  (WRITE_REG((__HANDLE__)->Instance->SR, ~(__FLAG__))) // 向状态寄存器SR写入取反后的标志位来清除标志

/** @brief  复位ADC句柄状态
  * @param  __HANDLE__: ADC句柄指针
  * @retval 无
  */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  do{                                                                          \
     (__HANDLE__)->State = HAL_ADC_STATE_RESET;                                \
     (__HANDLE__)->MspInitCallback = NULL;                                     \
     (__HANDLE__)->MspDeInitCallback = NULL;                                   \
    } while(0)
#else
#define __HAL_ADC_RESET_HANDLE_STATE(__HANDLE__)                               \
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET) // 将句柄状态复位为RESET
#endif

/**
  * @}
  */

/* Private macro ------------------------------------------------------------*/
/* 私有宏 --------------------------------------------------------------------*/

/** @defgroup ADC_Private_Macros ADC Private Macros
  * @{
  */
/* 宏定义保留供HAL驱动内部使用，不打算用于最终用户的代码中 */

/**
  * @brief 验证ADC状态：使能或失能
  * @param __HANDLE__: ADC句柄指针
  * @retval SET (ADC已使能) 或 RESET (ADC已失能)
  */
#define ADC_IS_ENABLE(__HANDLE__)                                              \
  ((( ((__HANDLE__)->Instance->CR2 & ADC_CR2_ADON) == ADC_CR2_ADON )           \
   ) ? SET : RESET) // 检查CR2寄存器的ADON位来判断ADC是否使能

/**
  * @brief 测试规则组的转换触发是否为软件启动或外部触发。
  * @param __HANDLE__: ADC句柄指针
  * @retval SET (软件启动) 或 RESET (外部触发)
  */
#define ADC_IS_SOFTWARE_START_REGULAR(__HANDLE__)                              \
  (READ_BIT((__HANDLE__)->Instance->CR2, ADC_CR2_EXTSEL) == ADC_SOFTWARE_START) // 检查CR2寄存器的EXTSEL位是否为软件触发

/**
  * @brief 测试注入组的转换触发是否为软件启动或外部触发。
  * @param __HANDLE__: ADC句柄指针
  * @retval SET (软件启动) 或 RESET (外部触发)
  */
#define ADC_IS_SOFTWARE_START_INJECTED(__HANDLE__)                             \
  (READ_BIT((__HANDLE__)->Instance->CR2, ADC_CR2_JEXTSEL) == ADC_INJECTED_SOFTWARE_START) // 检查CR2寄存器的JEXTSEL位是否为软件触发

/**
  * @brief 同时清除和设置句柄状态的特定位
  * @note: ADC_STATE_CLR_SET() 宏仅仅是通用宏 MODIFY_REG() 的别名，
  *        第一个参数是ADC句柄状态，第二个参数是要清除的位域，
  *        第三个也是最后一个参数是要设置的位域。
  * @retval 无
  */
#define ADC_STATE_CLR_SET MODIFY_REG

/**
  * @brief 清除ADC错误代码 (将其设置为错误代码: "无错误")
  * @param __HANDLE__: ADC句柄指针
  * @retval 无
  */
#define ADC_CLEAR_ERRORCODE(__HANDLE__)                                        \
  ((__HANDLE__)->ErrorCode = HAL_ADC_ERROR_NONE) // 将错误代码重置为无错误

/**
  * @brief 设置ADC规则组通道序列长度的转换数量。
  * @param _NbrOfConversion_: 规则组通道序列长度 
  * @retval 无
  */
#define ADC_SQR1_L_SHIFT(_NbrOfConversion_)                                    \
  (((_NbrOfConversion_) - (uint8_t)1) << ADC_SQR1_L_Pos) // 将转换数量减1后左移到SQR1寄存器的L位位置

/**
  * @brief 设置通道号在10到18之间的ADC采样时间。
  * @param _SAMPLETIME_: 采样时间参数。
  * @param _CHANNELNB_: 通道号。  
  * @retval 无
  */
#define ADC_SMPR1(_SAMPLETIME_, _CHANNELNB_)                                   \
  ((_SAMPLETIME_) << (ADC_SMPR1_SMP11_Pos * ((_CHANNELNB_) - 10))) // 根据通道号计算移位位置并设置采样时间
/**
  * @brief  设置ADC通道0到通道9的采样时间
  * @param  _SAMPLETIME_: 采样时间参数
  * @param  _CHANNELNB_: 通道编号
  * @retval 无
  */
// 宏定义：设置SMPR2寄存器中的采样时间
// SMPR2寄存器负责管理通道0-9的采样时间
// 通过通道编号计算移位位置，将采样时间设置到对应通道的位域中
#define ADC_SMPR2(_SAMPLETIME_, _CHANNELNB_)                                   \
  ((_SAMPLETIME_) << (ADC_SMPR2_SMP1_Pos * (_CHANNELNB_)))

/**
  * @brief  设置规则组通道的转换顺序，适用于排名1到6
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 转换序列中的排名(1-6)
  * @retval 无
  */
// 宏定义：设置SQR3寄存器中的通道转换顺序
// SQR3寄存器管理规则组序列中的第1到第6个转换
// 通过排名计算移位量，将通道编号填入对应的SQ位置
#define ADC_SQR3_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR3_SQ2_Pos * ((_RANKNB_) - 1)))

/**
  * @brief  设置规则组通道的转换顺序，适用于排名7到12
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 转换序列中的排名(7-12)
  * @retval 无
  */
// 宏定义：设置SQR2寄存器中的通道转换顺序
// SQR2寄存器管理规则组序列中的第7到第12个转换
// 注意：排名需要减去7来计算正确的移位位置
#define ADC_SQR2_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR2_SQ8_Pos * ((_RANKNB_) - 7)))

/**
  * @brief  设置规则组通道的转换顺序，适用于排名13到16
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 转换序列中的排名(13-16)
  * @retval 无
  */
// 宏定义：设置SQR1寄存器中的通道转换顺序
// SQR1寄存器管理规则组序列中的第13到第16个转换
// 注意：排名需要减去13来计算正确的移位位置
#define ADC_SQR1_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR1_SQ14_Pos * ((_RANKNB_) - 13)))

/**
  * @brief  设置注入组的序列长度
  * @param  _JSQR_JL_: 序列长度
  * @retval 无
  */
// 宏定义：设置JSQR寄存器中的注入序列长度
// 实际长度需要减1后左移到对应位置
#define ADC_JSQR_JL_SHIFT(_JSQR_JL_)                                           \
  (((_JSQR_JL_) -1) << ADC_JSQR_JL_Pos)

/**
  * @brief  设置选定的注入组通道排名
  *         注意: 在STM32F1系列设备上，JSQR寄存器中的通道排名位置
  *               取决于注入序列器中选定的总排名数(排名序列从4-JL开始)
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 排名编号
  * @param  _JSQR_JL_: 序列长度
  * @retval 无
  */
// 宏定义：设置注入组通道的转换顺序
// 注入组的序列配置较为复杂，位置取决于序列总长度
#define ADC_JSQR_RK_JL(_CHANNELNB_, _RANKNB_, _JSQR_JL_)                       \
  ((_CHANNELNB_) << (ADC_JSQR_JSQ2_Pos * ((4 - ((_JSQR_JL_) - (_RANKNB_))) - 1)))

/**
  * @brief  使能ADC连续转换模式
  * @param  _CONTINUOUS_MODE_: 连续模式设置
  * @retval 无
  */
// 宏定义：配置CR2寄存器中的CONT位
// 用于控制ADC是单次转换还是连续转换
#define ADC_CR2_CONTINUOUS(_CONTINUOUS_MODE_)                                  \
  ((_CONTINUOUS_MODE_) << ADC_CR2_CONT_Pos)

/**
  * @brief  配置规则组通道的不连续转换数量
  * @param  _NBR_DISCONTINUOUS_CONV_: 不连续转换的数量
  * @retval 无
  */
// 宏定义：设置CR1寄存器中的DISCNUM位
// 用于设置每次触发转换的通道数量
#define ADC_CR1_DISCONTINUOUS_NUM(_NBR_DISCONTINUOUS_CONV_)                    \
  (((_NBR_DISCONTINUOUS_CONV_) - 1) << ADC_CR1_DISCNUM_Pos)

/**
  * @brief  使能ADC扫描模式，以便使用序列器转换多个排名
  * @param  _SCAN_MODE_: 扫描转换模式
  * @retval 无
  */
/* 注意: 扫描模式与ENABLE进行比较是为了兼容旧代码，该参数等同于ADC_SCAN_ENABLE */
// 宏定义：配置CR1寄存器中的SCAN位
// 扫描模式用于多通道采集
#define ADC_CR1_SCAN_SET(_SCAN_MODE_)                                          \
  (( ((_SCAN_MODE_) == ADC_SCAN_ENABLE) || ((_SCAN_MODE_) == ENABLE)           \
   )? (ADC_SCAN_ENABLE) : (ADC_SCAN_DISABLE)                                   \
  )

/**
  * @brief  获取所有通道上的最大ADC转换周期数
  *         返回选定的采样时间 + 转换时间(12.5个ADC时钟周期)
  *         在4个范围内近似采样时间，返回最高值：
  *           低于7.5个周期 {1.5个周期; 7.5个周期},
  *           介于13.5个周期和28.5个周期之间 {13.5个周期; 28.5个周期}
  *           介于41.5个周期和71.5个周期之间 {41.5个周期; 55.5个周期; 71.5个周期}
  *           等于239.5个周期
  *         单位: ADC时钟周期
  * @param  __HANDLE__: ADC句柄
  * @retval 所有通道上的ADC转换周期数
  */   
// 宏定义：计算最大转换周期
// 通过检查SMPR1和SMPR2寄存器的位状态，估算当前配置下的最大采样时间
// 这对于计算ADC转换超时时间非常有用
#define ADC_CONVCYCLES_MAX_RANGE(__HANDLE__)                                                                     \
    (( (((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2) == RESET)  &&                     \
       (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2) == RESET) ) ?                     \
                                                                                                                 \
          (( (((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1) == RESET)  &&               \
             (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1) == RESET) ) ?               \
               ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_7CYCLES5 : ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_28CYCLES5)   \
          :                                                                                                      \
          ((((((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1) == RESET)  &&               \
             (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1) == RESET)) ||               \
            ((((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0) == RESET)  &&               \
             (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0) == RESET))) ?               \
               ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_71CYCLES5 : ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_239CYCLES5) \
     )

// 参数检查宏：检查数据对齐方式是否合法
#define IS_ADC_DATA_ALIGN(ALIGN) (((ALIGN) == ADC_DATAALIGN_RIGHT) || \
                                  ((ALIGN) == ADC_DATAALIGN_LEFT)    )

// 参数检查宏：检查扫描模式参数是否合法
#define IS_ADC_SCAN_MODE(SCAN_MODE) (((SCAN_MODE) == ADC_SCAN_DISABLE) || \
                                     ((SCAN_MODE) == ADC_SCAN_ENABLE)    )

// 参数检查宏：检查外部触发转换边沿设置是否合法
#define IS_ADC_EXTTRIG_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGCONVEDGE_NONE)  || \
                                   ((EDGE) == ADC_EXTERNALTRIGCONVEDGE_RISING)  )

// 参数检查宏：检查ADC通道编号是否合法
#define IS_ADC_CHANNEL(CHANNEL) (((CHANNEL) == ADC_CHANNEL_0)           || \
                                 ((CHANNEL) == ADC_CHANNEL_1)           || \
                                 ((CHANNEL) == ADC_CHANNEL_2)           || \
                                 ((CHANNEL) == ADC_CHANNEL_3)           || \
                                 ((CHANNEL) == ADC_CHANNEL_4)           || \
                                 ((CHANNEL) == ADC_CHANNEL_5)           || \
                                 ((CHANNEL) == ADC_CHANNEL_6)           || \
                                 ((CHANNEL) == ADC_CHANNEL_7)           || \
                                 ((CHANNEL) == ADC_CHANNEL_8)           || \
                                 ((CHANNEL) == ADC_CHANNEL_9)           || \
                                 ((CHANNEL) == ADC_CHANNEL_10)          || \
                                 ((CHANNEL) == ADC_CHANNEL_11)          || \
                                 ((CHANNEL) == ADC_CHANNEL_12)          || \
                                 ((CHANNEL) == ADC_CHANNEL_13)          || \
                                 ((CHANNEL) == ADC_CHANNEL_14)          || \
                                 ((CHANNEL) == ADC_CHANNEL_15)          || \
                                 ((CHANNEL) == ADC_CHANNEL_16)          || \
                                 ((CHANNEL) == ADC_CHANNEL_17)            )

// 参数检查宏：检查采样时间设置是否合法
#define IS_ADC_SAMPLE_TIME(TIME) (((TIME) == ADC_SAMPLETIME_1CYCLE_5)    || \
                                  ((TIME) == ADC_SAMPLETIME_7CYCLES_5)   || \
                                  ((TIME) == ADC_SAMPLETIME_13CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_28CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_41CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_55CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_71CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_239CYCLES_5)   )

// 参数检查宏：检查规则组转换排名是否合法(1-16)
#define IS_ADC_REGULAR_RANK(CHANNEL) (((CHANNEL) == ADC_REGULAR_RANK_1 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_2 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_3 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_4 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_5 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_6 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_7 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_8 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_9 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_10) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_11) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_12) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_13) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_14) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_15) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_16)   )

// 参数检查宏：检查模拟看门狗模式配置是否合法
#define IS_ADC_ANALOG_WATCHDOG_MODE(WATCHDOG) (((WATCHDOG) == ADC_ANALOGWATCHDOG_NONE)             || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REG)       || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_INJEC)     || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)  || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REG)          || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_INJEC)        || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REGINJEC)       )

// 参数检查宏：检查转换组类型是否合法(规则组、注入组或两者)
#define IS_ADC_CONVERSION_GROUP(CONVERSION) (((CONVERSION) == ADC_REGULAR_GROUP)         || \
                                             ((CONVERSION) == ADC_INJECTED_GROUP)        || \
                                             ((CONVERSION) == ADC_REGULAR_INJECTED_GROUP)  )

// 参数检查宏：检查ADC事件类型是否合法
#define IS_ADC_EVENT_TYPE(EVENT) ((EVENT) == ADC_AWD_EVENT)


/** @defgroup ADC_range_verification ADC范围验证
  * 对于唯一的ADC分辨率：12位
  * @{
  */
// 参数检查宏：检查ADC转换值是否在12位范围内(0-4095)
#define IS_ADC_RANGE(ADC_VALUE) ((ADC_VALUE) <= 0x0FFFU)
/**
  * @}
  */

/** @defgroup ADC_regular_nb_conv_verification ADC规则组转换数量验证
  * @{
  */
// 参数检查宏：检查规则组转换通道数量是否在1到16之间
#define IS_ADC_REGULAR_NB_CONV(LENGTH) (((LENGTH) >= 1U) && ((LENGTH) <= 16U))
/**
  * @}
  */

/** @defgroup ADC_regular_discontinuous_mode_number_verification ADC规则组不连续模式数量验证
  * @{
  */
// 参数检查宏：检查规则组不连续模式下的转换数量是否在1到8之间
#define IS_ADC_REGULAR_DISCONT_NUMBER(NUMBER) (((NUMBER) >= 1U) && ((NUMBER) <= 8U))
/**
  * @}
  */
      
/**
  * @}
  */
    
/* 包含ADC HAL扩展模块 */
#include "stm32f1xx_hal_adc_ex.h"

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup ADC_Exported_Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1
  * @{
  */


/* 初始化和反初始化函数  **********************************/
// ADC初始化函数
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef* hadc);
// ADC反初始化函数(恢复寄存器到默认值)
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
// ADC MSP初始化函数(用于配置底层硬件，如时钟、GPIO等)
void                    HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
// ADC MSP反初始化函数(用于释放底层硬件资源)
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/* 回调注册/注销函数  ***********************************/
// 注册ADC回调函数
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback);
// 注销ADC回调函数
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* IO操作函数  *****************************************************/

/** @addtogroup ADC_Exported_Functions_Group2
  * @{
  */


/* 阻塞模式：轮询方式 */
// 启动ADC转换(阻塞模式)
HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef* hadc);
// 停止ADC转换(阻塞模式)
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
// 等待ADC转换完成(阻塞模式，带超时)
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);
// 等待ADC事件发生(阻塞模式，带超时)
HAL_StatusTypeDef       HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout);

/* 非阻塞模式：中断方式 */
// 启动ADC转换(中断模式)
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
// 停止ADC转换(中断模式)
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);

/* 非阻塞模式：DMA方式 */
// 启动ADC转换(DMA模式)
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
// 停止ADC转换(DMA模式)
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);

/* ADC获取转换值，用于轮询或中断模式 */
// 获取ADC转换结果
uint32_t                HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);

/* ADC中断处理函数和回调函数，用于非阻塞模式(中断和DMA) */
// ADC中断处理函数(需在stm32f1xx_it.c中调用)
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc);
// 转换完成回调函数
void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
// 转换半完成回调函数(DMA模式使用)
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
// 模拟看门狗越限回调函数
void                    HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc);
// 错误回调函数
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
/**
  * @}
  */


/* 外设控制函数 ***********************************************/
/** @addtogroup ADC_Exported_Functions_Group3
  * @{
  */
// 配置ADC通道参数(采样时间、排名等)
HAL_StatusTypeDef       HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
// 配置模拟看门狗参数
HAL_StatusTypeDef       HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig);
/**
  * @}
  */


/* 外设状态函数 *************************************************/
/** @addtogroup ADC_Exported_Functions_Group4
  * @{
  */
// 获取ADC状态
uint32_t                HAL_ADC_GetState(ADC_HandleTypeDef* hadc);
// 获取ADC错误码
uint32_t                HAL_ADC_GetError(ADC_HandleTypeDef *hadc);
/**
  * @}
  */


/**
  * @}
  */


/* 内部HAL驱动函数 **********************************************/
/** @addtogroup ADC_Private_Functions
  * @{
  */
// 使能ADC
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc);
// 停止转换并禁用ADC
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc);
// ADC稳定时间延时
void              ADC_StabilizationTime(uint32_t DelayUs);
// DMA转换完成回调(内部调用)
void              ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);
// DMA半转换完成回调(内部调用)
void              ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma);
// DMA错误回调(内部调用)
void              ADC_DMAError(DMA_HandleTypeDef *hdma);
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


#endif /* __STM32F1xx_HAL_ADC_H */
