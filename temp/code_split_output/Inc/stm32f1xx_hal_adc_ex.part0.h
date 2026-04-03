/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc_ex.h
  * @author  MCD Application Team
  * @brief   ADC HAL 扩展模块的头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的 LICENSE 文件中可以找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义以防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_ADC_EX_H
#define __STM32F1xx_HAL_ADC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"  

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup ADCEx
  * @{
  */ 

/* 导出类型 ------------------------------------------------------------*/ 
/** @defgroup ADCEx_Exported_Types ADCEx 导出类型
  * @{
  */

/** 
  * @brief  ADC 注入通道配置结构体定义
  * @note   此结构体的参数分为两个作用域：
  *          - 通道作用域：InjectedChannel, InjectedRank, InjectedSamplingTime, InjectedOffset
  *          - 注入组作用域 (影响注入组内的所有通道)：InjectedNbrOfConversion, InjectedDiscontinuousConvMode,
  *            AutoInjectedConv, ExternalTrigInjecConvEdge, ExternalTrigInjecConv.
  * @note   使用函数 HAL_ADCEx_InjectedConfigChannel() 设置这些参数受 ADC 状态限制。
  *         ADC 状态可以是：
  *          - 对于所有参数：ADC 禁用 (这是修改参数 'ExternalTrigInjecConv' 唯一可能的 ADC 状态)
  *          - 对于除参数 'ExternalTrigInjecConv' 之外的所有参数：ADC 使能且注入组上没有正在进行的转换。
  */
typedef struct 
{
  uint32_t InjectedChannel;                       /*!< 要配置的 ADC 通道选择
                                                       此参数可以是 @ref ADC_channels 中的一个值
                                                       注意：根据设备不同，某些通道可能在封装引脚上不可用。请参考设备数据手册了解通道可用性。
                                                       注意：在具有多个 ADC 的 STM32F1 设备上：只有 ADC1 可以访问内部测量通道
                                                       注意：在 STM32F10xx8 和 STM32F10xxB 设备上：当 ADC 使用注入触发进行转换时，可能会在 PA0 引脚 (ADC 输入 0) 上产生低幅度电压毛刺。
                                                             建议分配模拟通道，以便将通道 0 配置为注入通道。
                                                             有关更多详细信息，请参阅这些设备的勘误手册。 */
  uint32_t InjectedRank;                          /*!< 注入组序列器中的排名
                                                       此参数必须是 @ref ADCEx_injected_rank 中的一个值
                                                       注意：如果需要禁用通道或更改转换序列的顺序，可以通过新的通道设置覆盖包含先前通道设置的排名 (或者可以调整参数转换次数) */
  uint32_t InjectedSamplingTime;                  /*!< 为所选通道设置的采样时间值。
                                                       单位：ADC 时钟周期
                                                       转换时间是采样时间和处理时间之和 (12 位 ADC 分辨率下为 12.5 个 ADC 时钟周期)。
                                                       此参数可以是 @ref ADC_sampling_times 中的一个值
                                                       注意：此参数更新通道的参数属性，该通道可用于常规组和/或注入组。
                                                             如果同一通道先前已在另一组 (常规/注入) 中配置，它将更新为最新设置。
                                                       注意：在使用内部测量通道 时，
                                                             必须遵守采样时间约束 (可以根据 ADC 时钟频率和采样时间设置调整采样时间)
                                                             请参考设备数据手册获取时序值，参数 TS_vrefint, TS_temp (数值大致范围：5us 到 17.1us 最小值)。 */
  uint32_t InjectedOffset;                        /*!< 定义从原始转换数据中减去的偏移量 (仅适用于注入组上的通道)。
                                                       偏移值必须为正数。
                                                       根据所选的 ADC 分辨率 (12, 10, 8 或 6 位)，
                                                       此参数必须是 Min_Data = 0x000 和 Max_Data = 0xFFF, 0x3FF, 0xFF 或 0x3F 之间的数字。 */
  uint32_t InjectedNbrOfConversion;               /*!< 指定注入组序列器中将转换的排名数量。
                                                       要使用注入组序列器并转换多个排名，必须启用参数 'ScanConvMode'。
                                                       此参数必须是 Min_Data = 1 和 Max_Data = 4 之间的数字。
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel() 
                                                             在注入组上配置通道可能会影响先前设置的其他通道的配置。 */
  FunctionalState InjectedDiscontinuousConvMode;  /*!< 指定注入组的转换序列是执行完整序列还是不连续序列 (主序列细分为连续部分)。
                                                       仅在序列器启用 (参数 'ScanConvMode') 时使用不连续模式。如果序列器禁用，则丢弃此参数。
                                                       仅在连续模式禁用时才能启用不连续模式。如果启用了连续模式，则丢弃此参数设置。
                                                       此参数可设置为 ENABLE 或 DISABLE。
                                                       注意：对于注入组，不连续排名的增量固定为逐个增加。
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel() 
                                                             在注入组上配置通道可能会影响先前设置的其他通道的配置。 */
  FunctionalState AutoInjectedConv;               /*!< 使能或禁止在常规组转换后自动进行注入组转换
                                                       此参数可设置为 ENABLE 或 DISABLE。
                                                       注意：要使用自动注入转换，必须禁用不连续模式 ('DiscontinuousConvMode' 和 'InjectedDiscontinuousConvMode' 设置为 DISABLE)
                                                       注意：要使用自动注入转换，必须禁用注入组外部触发 ('ExternalTrigInjecConv' 设置为 ADC_SOFTWARE_START)
                                                       注意：如果常规组使用 DMA：如果 DMA 配置为正常模式 (单次)，则 DMA 传输完成后 JAUTO 将停止。
                                                             要保持 JAUTO 始终启用，必须将 DMA 配置为循环模式。
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel() 
                                                             在注入组上配置通道可能会影响先前设置的其他通道的配置。 */
  uint32_t ExternalTrigInjecConv;                 /*!< 选择用于触发注入组转换启动的外部事件。
                                                       如果设置为 ADC_INJECTED_SOFTWARE_START，则禁用外部触发。
                                                       如果设置为外部触发源，则在事件上升沿触发。
                                                       此参数可以是 @ref ADCEx_External_trigger_source_Injected 中的一个值
                                                       注意：必须在 ADC 禁用时修改此参数 (在 ADC 开始转换之前或 ADC 停止转换之后)。
                                                             如果 ADC 已启用，则此参数设置将被绕过且不报告错误 (因为在动态更新其他参数时，这可能就是预期的行为)
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel() 
                                                             在注入组上配置通道可能会影响先前设置的其他通道的配置。 */
}ADC_InjectionConfTypeDef;

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** 
  * @brief  ADC 多模式结构体定义
  * @note   使用函数 HAL_ADCEx_MultiModeConfigChannel() 设置这些参数受 ADC 状态 (公共组的两个 ADC) 限制。
  *         公共组的 ADC 状态必须为：禁用。
  */
typedef struct
{
  uint32_t Mode;              /*!< 配置 ADC 在独立模式或多模式下工作。 
                                   此参数可以是 @ref ADCEx_Common_mode 中的一个值
                                   注意：在双模式下，更改通道配置会产生重启，可能会导致同步丢失。建议在进行任何配置更改之前禁用双模式。
                                   注意：在使用同时模式的情况下：应为 ADC1 和 ADC2 同时采样的 2 个通道配置完全相同的采样时间。
                                   注意：在使用交错模式的情况下：为避免转换重叠，快速交错模式允许的最大采样时间为 7 个 ADC 时钟周期，慢速交错模式为 14 个 ADC 时钟周期。
                                   注意：某些多模式参数在 STM32F1 上是固定的，而在具有多个 ADC 的其他 STM32 设备上可以配置 (多模式配置结构体可能有其他参数)。
                                         等效关系如下：
                                           - 参数 'DMAAccessMode'：在 STM32F1 上，此参数固定为 1 个 DMA 通道 (两个 ADC 共用一个 DMA 通道，即 ADC 主设备的 DMA)。在具有多个 ADC 的其他 STM32 设备上，这等效于参数 'ADC_DMAACCESSMODE_12_10_BITS'。
                                           - 参数 'TwoSamplingDelay'：在 STM32F1 上，根据选择的快速或慢速交错模式，此参数固定为 7 或 14 个 ADC 时钟周期。在具有多个 ADC 的其他 STM32 设备上，这等效于参数 'ADC_TWOSAMPLINGDELAY_7CYCLES' (用于快速交错模式)。 */

  
}ADC_MultiModeTypeDef;                                                          
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* 导出常量 --------------------------------------------------------*/
   
/** @defgroup ADCEx_Exported_Constants ADCEx 导出常量
  * @{
  */

/** @defgroup ADCEx_injected_rank ADCEx 注入组内的排名
  * @{
  */
#define ADC_INJECTED_RANK_1                           0x00000001U /* 注入组序列中的第 1 个转换 */
#define ADC_INJECTED_RANK_2                           0x00000002U /* 注入组序列中的第 2 个转换 */
#define ADC_INJECTED_RANK_3                           0x00000003U /* 注入组序列中的第 3 个转换 */
#define ADC_INJECTED_RANK_4                           0x00000004U /* 注入组序列中的第 4 个转换 */
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_edge_Injected ADCEx 注入组外部触发使能
  * @{
  */
#define ADC_EXTERNALTRIGINJECCONV_EDGE_NONE           0x00000000U /* 禁止外部触发注入转换 */
#define ADC_EXTERNALTRIGINJECCONV_EDGE_RISING         ((uint32_t)ADC_CR2_JEXTTRIG) /* 外部触发注入转换的上升沿检测使能 */
/**
  * @}
  */
    
/** @defgroup ADC_External_trigger_source_Regular ADC 常规组外部触发选择
  * @{
  */
/*!< 具有通用触发名称的外部触发列表，独立于 ADC 目标，按触发名称排序： */

/*!< 仅限 ADC1 和 ADC2 的常规组外部触发 */
#define ADC_EXTERNALTRIGCONV_T1_CC1         ADC1_2_EXTERNALTRIG_T1_CC1 /* 定时器 1 捕获比较 1 */
#define ADC_EXTERNALTRIGCONV_T1_CC2         ADC1_2_EXTERNALTRIG_T1_CC2 /* 定时器 1 捕获比较 2 */
#define ADC_EXTERNALTRIGCONV_T2_CC2         ADC1_2_EXTERNALTRIG_T2_CC2 /* 定时器 2 捕获比较 2 */
#define ADC_EXTERNALTRIGCONV_T3_TRGO        ADC1_2_EXTERNALTRIG_T3_TRGO /* 定时器 3 触发输出 */
#define ADC_EXTERNALTRIGCONV_T4_CC4         ADC1_2_EXTERNALTRIG_T4_CC4 /* 定时器 4 捕获比较 4 */
#define ADC_EXTERNALTRIGCONV_EXT_IT11       ADC1_2_EXTERNALTRIG_EXT_IT11 /* 外部中断线 11 */

#if defined (STM32F103xE) || defined (STM32F103xG)
/*!< 仅限 ADC3 的常规组外部触发 */
#define ADC_EXTERNALTRIGCONV_T2_CC3         ADC3_EXTERNALTRIG_T2_CC3 /* 定时器 2 捕获比较 3 */
#define ADC_EXTERNALTRIGCONV_T3_CC1         ADC3_EXTERNALTRIG_T3_CC1 /* 定时器 3 捕获比较 1 */
#define ADC_EXTERNALTRIGCONV_T5_CC1         ADC3_EXTERNALTRIG_T5_CC1 /* 定时器 5 捕获比较 1 */
#define ADC_EXTERNALTRIGCONV_T5_CC3         ADC3_EXTERNALTRIG_T5_CC3 /* 定时器 5 捕获比较 3 */
#define ADC_EXTERNALTRIGCONV_T8_CC1         ADC3_EXTERNALTRIG_T8_CC1 /* 定时器 8 捕获比较 1 */
#endif /* STM32F103xE || defined STM32F103xG */

/*!< 适用于所有 ADC 实例的常规组外部触发 */
#define ADC_EXTERNALTRIGCONV_T1_CC3         ADC1_2_3_EXTERNALTRIG_T1_CC3 /* 定时器 1 捕获比较 3 */

#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/*!< 注意：TIM8_TRGO 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用。   */
/*         要在 ADC 或 ADC2 上使用它，必须使用宏完成触发重映射：                              */
/*           __HAL_AFIO_REMAP_ADC1_ETRGREG_ENABLE()                           */
/*           __HAL_AFIO_REMAP_ADC2_ETRGREG_ENABLE()                           */

/* 内部常量值管理说明：如果 TIM8_TRGO 可用，    */
/* 其定义默认设置为 ADC1 和 ADC2 的值，如果选择了 ADC3，则由 HAL ADC 驱动程序更改为     */
/* ADC3 的值。                      */
#define ADC_EXTERNALTRIGCONV_T8_TRGO        ADC1_2_EXTERNALTRIG_T8_TRGO /* 定时器 8 触发输出 */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#define ADC_SOFTWARE_START                  ADC1_2_3_SWSTART /* 软件触发启动 */
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_source_Injected ADCEx 注入组外部触发选择
  * @{
  */
/*!< 具有通用触发名称的外部触发列表，独立于 ADC 目标，按触发名称排序： */

/*!< 仅限 ADC1 和 ADC2 的注入组外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_T2_TRGO        ADC1_2_EXTERNALTRIGINJEC_T2_TRGO /* 定时器 2 触发输出 */
#define ADC_EXTERNALTRIGINJECCONV_T2_CC1         ADC1_2_EXTERNALTRIGINJEC_T2_CC1 /* 定时器 2 捕获比较 1 */
#define ADC_EXTERNALTRIGINJECCONV_T3_CC4         ADC1_2_EXTERNALTRIGINJEC_T3_CC4 /* 定时器 3 捕获比较 4 */
#define ADC_EXTERNALTRIGINJECCONV_T4_TRGO        ADC1_2_EXTERNALTRIGINJEC_T4_TRGO  /* 定时器 4 触发输出 */
#define ADC_EXTERNALTRIGINJECCONV_EXT_IT15       ADC1_2_EXTERNALTRIGINJEC_EXT_IT15 /* 外部中断线 15 */

#if defined (STM32F103xE) || defined (STM32F103xG)
/*!< 仅限 ADC3 的注入组外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_T4_CC3         ADC3_EXTERNALTRIGINJEC_T4_CC3 /* 定时器 4 捕获比较 3 */
#define ADC_EXTERNALTRIGINJECCONV_T8_CC2         ADC3_EXTERNALTRIGINJEC_T8_CC2 /* 定时器 8 捕获比较 2 */
#define ADC_EXTERNALTRIGINJECCONV_T5_TRGO        ADC3_EXTERNALTRIGINJEC_T5_TRGO /* 定时器 5 触发输出 */
#define ADC_EXTERNALTRIGINJECCONV_T5_CC4         ADC3_EXTERNALTRIGINJEC_T5_CC4 /* 定时器 5 捕获比较 4 */
#endif /* STM32F103xE || defined STM32F103xG */

/*!< 适用于所有 ADC 实例的注入组外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_T1_CC4         ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4 /* 定时器 1 捕获比较 4 */
#define ADC_EXTERNALTRIGINJECCONV_T1_TRGO        ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO /* 定时器 1 触发输出 */

#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/*!< 注意：TIM8_CC4 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用。    */
/*         要在 ADC1 或 ADC2 上使用它，必须使用宏完成触发重映射：                               */
/*           __HAL_AFIO_REMAP_ADC1_ETRGINJ_ENABLE()                           */
/*           __HAL_AFIO_REMAP_ADC2_ETRGINJ_ENABLE()                           */

/* 内部常量值管理说明：如果 TIM8_CC4 可用，     */
/* 其定义默认设置为 ADC1 和 ADC2 的值，如果选择了 ADC3，则由 HAL ADC 驱动程序更改为     */
/* ADC3 的值。                      */
#define ADC_EXTERNALTRIGINJECCONV_T8_CC4         ADC1_2_EXTERNALTRIGINJEC_T8_CC4 /* 定时器 8 捕获比较 4 */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#define ADC_INJECTED_SOFTWARE_START              ADC1_2_3_JSWSTART /* 注入组软件触发启动 */
/**
  * @}
  */
