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
