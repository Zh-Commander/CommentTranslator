/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc_ex.h
  * @author  MCD Application Team
  * @brief   ADC HAL扩展模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
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
  * @note   该结构体的参数分为两个作用域：
  *          - 通道作用域：InjectedChannel, InjectedRank, InjectedSamplingTime, InjectedOffset
  *          - 注入组作用域 (影响注入组内的所有通道)：InjectedNbrOfConversion, InjectedDiscontinuousConvMode,
  *            AutoInjectedConv, ExternalTrigInjecConvEdge, ExternalTrigInjecConv.
  * @note   使用函数 HAL_ADCEx_InjectedConfigChannel() 设置这些参数的前提是ADC处于特定状态。
  *         ADC状态可以是：
  *          - 对于所有参数：ADC禁用 (这是修改参数 'ExternalTrigInjecConv' 唯一可能的ADC状态)
  *          - 对于除 'ExternalTrigInjecConv' 之外的所有参数：ADC使能且注入组没有正在进行的转换。
  */
typedef struct 
{
  uint32_t InjectedChannel;                       /*!< 要配置的ADC通道选择
                                                       此参数可以是 @ref ADC_channels 中的值
                                                       注意：根据设备不同，某些通道可能在封装引脚上不可用。请参考设备数据手册了解通道可用性。
                                                       注意：在具有多个ADC的STM32F1设备上：只有ADC1可以访问内部测量通道 (VrefInt/TempSensor)
                                                       注意：在STM32F10xx8和STM32F10xxB设备上：当ADC使用注入触发进行转换时，可能会在PA0引脚 (ADC输入0) 上产生低幅度电压毛刺。
                                                             建议分配模拟通道时，将通道0配置为注入通道。
                                                             有关更多详细信息，请参阅这些设备的勘误表。 */
  uint32_t InjectedRank;                          /*!< 注入组序列器中的排名
                                                       此参数必须是 @ref ADCEx_injected_rank 中的值
                                                       注意：如果需要禁用通道或更改转换序列的顺序，可以通过新的通道设置覆盖包含先前通道设置的排名 (或者可以调整参数转换数量) */
  uint32_t InjectedSamplingTime;                  /*!< 为所选通道设置的采样时间值。
                                                       单位：ADC时钟周期
                                                       转换时间是采样时间和处理时间之和 (12位ADC分辨率下为12.5个ADC时钟周期)。
                                                       此参数可以是 @ref ADC_sampling_times 中的值
                                                       注意：此参数更新通道的属性，该通道可用于常规组和/或注入组。
                                                             如果同一通道先前已在另一组 (常规/注入) 中配置，它将更新为最新的设置。
                                                       注意：在使用内部测量通道 (VrefInt/TempSensor) 的情况下，
                                                             必须遵守采样时间约束 (采样时间可根据ADC时钟频率和采样时间设置进行调整)
                                                             请参考设备数据手册获取时序值，参数 TS_vrefint, TS_temp (数值大致范围：5us 到 17.1us 最小值)。 */
  uint32_t InjectedOffset;                        /*!< 定义从原始转换数据中减去的偏移量 (仅适用于注入组上的通道)。
                                                       偏移值必须为正数。
                                                       根据所选的ADC分辨率 (12, 10, 8 或 6 位)，
                                                       此参数必须是 Min_Data = 0x000 和 Max_Data = 0xFFF, 0x3FF, 0xFF 或 0x3F 之间的数字。 */
  uint32_t InjectedNbrOfConversion;               /*!< 指定注入组序列器中将被转换的排名数量。
                                                       要使用注入组序列器并转换多个排名，必须启用参数 'ScanConvMode'。
                                                       此参数必须是 Min_Data = 1 和 Max_Data = 4 之间的数字。
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel()
                                                             配置注入组上的通道可能会影响先前设置的其他通道的配置。 */
  FunctionalState InjectedDiscontinuousConvMode;  /*!< 指定注入组的转换序列是执行完整序列还是不连续序列 (主序列细分为连续部分)。
                                                       只有在序列器启用 (参数 'ScanConvMode') 时才使用不连续模式。如果序列器禁用，则忽略此参数。
                                                       只有在连续模式禁用时才能启用不连续模式。如果启用了连续模式，则忽略此参数设置。
                                                       此参数可设置为 ENABLE 或 DISABLE。
                                                       注意：对于注入组，不连续排名的增量固定为逐个增加。
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel()
                                                             配置注入组上的通道可能会影响先前设置的其他通道的配置。 */
  FunctionalState AutoInjectedConv;               /*!< 使能或禁用选择的ADC在常规组转换后自动进行注入组转换
                                                       此参数可设置为 ENABLE 或 DISABLE。
                                                       注意：要使用自动注入转换，必须禁用不连续模式 ('DiscontinuousConvMode' 和 'InjectedDiscontinuousConvMode' 设置为 DISABLE)
                                                       注意：要使用自动注入转换，必须禁用注入组外部触发 ('ExternalTrigInjecConv' 设置为 ADC_SOFTWARE_START)
                                                       注意：如果常规组使用DMA：如果DMA配置为正常模式 (单次)，JAUTO将在DMA传输完成后停止。
                                                             要保持JAUTO始终启用，必须将DMA配置为循环模式。
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel()
                                                             配置注入组上的通道可能会影响先前设置的其他通道的配置。 */
  uint32_t ExternalTrigInjecConv;                 /*!< 选择用于触发注入组开始转换的外部事件。
                                                       如果设置为 ADC_INJECTED_SOFTWARE_START，则禁用外部触发。
                                                       如果设置为外部触发源，则在事件上升沿触发。
                                                       此参数可以是 @ref ADCEx_External_trigger_source_Injected 中的值
                                                       注意：必须在ADC禁用时修改此参数 (在ADC开始转换之前或ADC停止转换之后)。
                                                             如果ADC已启用，此参数设置将被绕过且不报告错误 (因为在动态更新其他参数时可能是预期行为)
                                                       注意：此设置影响整个注入组。因此，调用 HAL_ADCEx_InjectedConfigChannel()
                                                             配置注入组上的通道可能会影响先前设置的其他通道的配置。 */
}ADC_InjectionConfTypeDef;

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** 
  * @brief  ADC 多模式结构体定义
  * @note   使用函数 HAL_ADCEx_MultiModeConfigChannel() 设置这些参数的前提是ADC状态 (公共组的两个ADC)。
  *         公共组的ADC状态必须是：禁用。
  */
typedef struct
{
  uint32_t Mode;              /*!< 配置ADC在独立模式或多模式下工作。 
                                   此参数可以是 @ref ADCEx_Common_mode 中的值
                                   注意：在双模式下，更改通道配置会产生重启，可能导致同步丢失。建议在进行任何配置更改之前禁用双模式。
                                   注意：在使用同时模式的情况下：应为ACD1和ADC2同时采样的两个通道配置完全相同的采样时间。
                                   注意：在使用交错模式的情况下：为避免转换重叠，快速交错模式允许的最大采样时间为7个ADC时钟周期，慢速交错模式为14个ADC时钟周期。
                                   注意：某些多模式参数在STM32F1上是固定的，而在具有多个ADC的其他STM32设备上可以配置 (多模式配置结构体可能有额外参数)。
                                         等效关系如下：
                                           - 参数 'DMAAccessMode'：在STM32F1上，此参数固定为1个DMA通道 (两个ADC共用一个DMA通道，即ADC主设备的DMA)。在其他具有多个ADC的STM32设备上，这等效于参数 'ADC_DMAACCESSMODE_12_10_BITS'。
                                           - 参数 'TwoSamplingDelay'：在STM32F1上，根据选择的快速或慢速交错模式，此参数固定为7或14个ADC时钟周期。在其他具有多个ADC的STM32设备上，这等效于参数 'ADC_TWOSAMPLINGDELAY_7CYCLES' (用于快速交错模式)。 */

  
}ADC_MultiModeTypeDef;                                                          
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* 导出常量 --------------------------------------------------------*/
   
/** @defgroup ADCEx_Exported_Constants ADCEx 导出常量
  * @{
  */

/** @defgroup ADCEx_injected_rank ADCEx 注入组排名
  * @{
  */
#define ADC_INJECTED_RANK_1                           0x00000001U  /* 注入组排名1 */
#define ADC_INJECTED_RANK_2                           0x00000002U  /* 注入组排名2 */
#define ADC_INJECTED_RANK_3                           0x00000003U  /* 注入组排名3 */
#define ADC_INJECTED_RANK_4                           0x00000004U  /* 注入组排名4 */
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_edge_Injected ADCEx 注入组外部触发使能
  * @{
  */
#define ADC_EXTERNALTRIGINJECCONV_EDGE_NONE           0x00000000U  /* 禁用外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_EDGE_RISING         ((uint32_t)ADC_CR2_JEXTTRIG)  /* 外部触发上升沿使能 */
/**
  * @}
  */
    
/** @defgroup ADC_External_trigger_source_Regular ADC 常规组外部触发选择
  * @{
  */
/*!< 具有通用触发名称的外部触发列表，独立于    */
/* ADC目标，按触发名称排序：                                        */

/*!< 仅适用于 ADC1&ADC2 的常规组外部触发 */
#define ADC_EXTERNALTRIGCONV_T1_CC1         ADC1_2_EXTERNALTRIG_T1_CC1    /* 定时器1捕获比较1 */
#define ADC_EXTERNALTRIGCONV_T1_CC2         ADC1_2_EXTERNALTRIG_T1_CC2    /* 定时器1捕获比较2 */
#define ADC_EXTERNALTRIGCONV_T2_CC2         ADC1_2_EXTERNALTRIG_T2_CC2    /* 定时器2捕获比较2 */
#define ADC_EXTERNALTRIGCONV_T3_TRGO        ADC1_2_EXTERNALTRIG_T3_TRGO   /* 定时器3触发输出 */
#define ADC_EXTERNALTRIGCONV_T4_CC4         ADC1_2_EXTERNALTRIG_T4_CC4    /* 定时器4捕获比较4 */
#define ADC_EXTERNALTRIGCONV_EXT_IT11       ADC1_2_EXTERNALTRIG_EXT_IT11  /* 外部中断线11 */

#if defined (STM32F103xE) || defined (STM32F103xG)
/*!< 仅适用于 ADC3 的常规组外部触发 */
#define ADC_EXTERNALTRIGCONV_T2_CC3         ADC3_EXTERNALTRIG_T2_CC3      /* 定时器2捕获比较3 */
#define ADC_EXTERNALTRIGCONV_T3_CC1         ADC3_EXTERNALTRIG_T3_CC1      /* 定时器3捕获比较1 */
#define ADC_EXTERNALTRIGCONV_T5_CC1         ADC3_EXTERNALTRIG_T5_CC1      /* 定时器5捕获比较1 */
#define ADC_EXTERNALTRIGCONV_T5_CC3         ADC3_EXTERNALTRIG_T5_CC3      /* 定时器5捕获比较3 */
#define ADC_EXTERNALTRIGCONV_T8_CC1         ADC3_EXTERNALTRIG_T8_CC1      /* 定时器8捕获比较1 */
#endif /* STM32F103xE || defined STM32F103xG */

/*!< 适用于所有 ADC 实例的常规组外部触发 */
#define ADC_EXTERNALTRIGCONV_T1_CC3         ADC1_2_3_EXTERNALTRIG_T1_CC3  /* 定时器1捕获比较3 */

#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/*!< 注意：TIM8_TRGO 仅在大容量和超高容量设备的 ADC1 和 ADC2 上可用。   */
/*         要在 ADC 或 ADC2 上使用它，必须通过宏完成触发重映射：     */
/*           __HAL_AFIO_REMAP_ADC1_ETRGREG_ENABLE()                           */
/*           __HAL_AFIO_REMAP_ADC2_ETRGREG_ENABLE()                           */

/* 内部常量值管理说明：如果 TIM8_TRGO 可用，    */
/* 其定义默认设置为 ADC1&ADC2 的值，如果选择了 ADC3，则由 HAL ADC 驱动程序更改为     */
/* ADC3 的值。                      */
#define ADC_EXTERNALTRIGCONV_T8_TRGO        ADC1_2_EXTERNALTRIG_T8_TRGO  /* 定时器8触发输出 */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#define ADC_SOFTWARE_START                  ADC1_2_3_SWSTART              /* 软件触发 */
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_source_Injected ADCEx 注入组外部触发选择
  * @{
  */
/*!< 具有通用触发名称的外部触发列表，独立于    */
/* ADC目标，按触发名称排序：                                        */

/*!< 仅适用于 ADC1&ADC2 的注入组外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_T2_TRGO        ADC1_2_EXTERNALTRIGINJEC_T2_TRGO    /* 定时器2触发输出 */
#define ADC_EXTERNALTRIGINJECCONV_T2_CC1         ADC1_2_EXTERNALTRIGINJEC_T2_CC1     /* 定时器2捕获比较1 */
#define ADC_EXTERNALTRIGINJECCONV_T3_CC4         ADC1_2_EXTERNALTRIGINJEC_T3_CC4     /* 定时器3捕获比较4 */
#define ADC_EXTERNALTRIGINJECCONV_T4_TRGO        ADC1_2_EXTERNALTRIGINJEC_T4_TRGO    /* 定时器4触发输出 */ 
#define ADC_EXTERNALTRIGINJECCONV_EXT_IT15       ADC1_2_EXTERNALTRIGINJEC_EXT_IT15   /* 外部中断线15 */

#if defined (STM32F103xE) || defined (STM32F103xG)
/*!< 仅适用于 ADC3 的注入组外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_T4_CC3         ADC3_EXTERNALTRIGINJEC_T4_CC3       /* 定时器4捕获比较3 */
#define ADC_EXTERNALTRIGINJECCONV_T8_CC2         ADC3_EXTERNALTRIGINJEC_T8_CC2       /* 定时器8捕获比较2 */
#define ADC_EXTERNALTRIGINJECCONV_T5_TRGO        ADC3_EXTERNALTRIGINJEC_T5_TRGO      /* 定时器5触发输出 */
#define ADC_EXTERNALTRIGINJECCONV_T5_CC4         ADC3_EXTERNALTRIGINJEC_T5_CC4       /* 定时器5捕获比较4 */
#endif /* STM32F103xE || defined STM32F103xG */

/*!< 适用于所有 ADC 实例的注入组外部触发 */
#define ADC_EXTERNALTRIGINJECCONV_T1_CC4         ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4   /* 定时器1捕获比较4 */
#define ADC_EXTERNALTRIGINJECCONV_T1_TRGO        ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO  /* 定时器1触发输出 */

#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/*!< 注意：TIM8_CC4 仅在大容量和超高容量设备的 ADC1 和 ADC2 上可用。    */
/*         要在 ADC1 或 ADC2 上使用它，必须通过宏完成触发重映射：    */
/*           __HAL_AFIO_REMAP_ADC1_ETRGINJ_ENABLE()                           */
/*           __HAL_AFIO_REMAP_ADC2_ETRGINJ_ENABLE()                           */

/* 内部常量值管理说明：如果 TIM8_CC4 可用，     */
/* 其定义默认设置为 ADC1&ADC2 的值，如果选择了 ADC3，则由 HAL ADC 驱动程序更改为     */
/* ADC3 的值。                      */
#define ADC_EXTERNALTRIGINJECCONV_T8_CC4         ADC1_2_EXTERNALTRIGINJEC_T8_CC4     /* 定时器8捕获比较4 */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#define ADC_INJECTED_SOFTWARE_START              ADC1_2_3_JSWSTART                   /* 注入组软件触发 */
/**
  * @}
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** @defgroup ADCEx_Common_mode ADC 扩展双 ADC 模式
  * @{
  */
/* ADC 双模式禁用 (ADC 独立模式) */
#define ADC_MODE_INDEPENDENT                              0x00000000U
/* ADC 双模式使能: 组合规则同步 + 注入同步模式，作用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT    ((uint32_t)(                                                            ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 组合规则同步 + 交替触发模式，作用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG      ((uint32_t)(                                        ADC_CR1_DUALMOD_1                    ))
/* ADC 双模式使能: 组合注入同步 + 快速交错模式，作用于规则组和注入组 (ADC 采样阶段之间的延迟: 7 个 ADC 时钟周期) */
#define ADC_DUALMODE_INJECSIMULT_INTERLFAST   ((uint32_t)(                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 组合注入同步 + 慢速交错模式，作用于规则组和注入组 (ADC 采样阶段之间的延迟: 14 个 ADC 时钟周期) */
#define ADC_DUALMODE_INJECSIMULT_INTERLSLOW   ((uint32_t)(                    ADC_CR1_DUALMOD_2                                        ))
/* ADC 双模式使能: 注入同步模式，作用于注入组 */
#define ADC_DUALMODE_INJECSIMULT              ((uint32_t)(                    ADC_CR1_DUALMOD_2 |                     ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 规则同步模式，作用于规则组 */
#define ADC_DUALMODE_REGSIMULT                ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    ))
/* ADC 双模式使能: 快速交错模式，作用于规则组 (ADC 采样阶段之间的延迟: 7 个 ADC 时钟周期) */
#define ADC_DUALMODE_INTERLFAST               ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 慢速交错模式，作用于规则组 (ADC 采样阶段之间的延迟: 14 个 ADC 时钟周期) */
#define ADC_DUALMODE_INTERLSLOW               ((uint32_t)(ADC_CR1_DUALMOD_3                                                            ))
/* ADC 双模式使能: 交替触发模式，作用于注入组 */
#define ADC_DUALMODE_ALTERTRIG                ((uint32_t)(ADC_CR1_DUALMOD_3 |                                         ADC_CR1_DUALMOD_0))
/**
  * @}
  */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* 私有常量 ---------------------------------------------------------*/

/** @addtogroup ADCEx_Private_Constants ADCEx 私有常量
  * @{
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Regular ADC 扩展内部 HAL 驱动规则组触发源选择
  * @{
  */
/* ADC1, ADC2, ADC3 (如果选定的设备上有该 ADC 实例) 规则组的外部触发列表。*/
/* (由 HAL 驱动内部使用。不用于 HAL 结构参数)  */

/* ADC1 和 ADC2 规则组的外部触发 (如果有 ADCx 可用) */
/* 定时器 1 捕获/比较通道 1 */
#define ADC1_2_EXTERNALTRIG_T1_CC1                       0x00000000U
/* 定时器 1 捕获/比较通道 2 */
#define ADC1_2_EXTERNALTRIG_T1_CC2           ((uint32_t)(                                      ADC_CR2_EXTSEL_0))
/* 定时器 2 捕获/比较通道 2 */
#define ADC1_2_EXTERNALTRIG_T2_CC2           ((uint32_t)(                   ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/* 定时器 3 触发输出 */
#define ADC1_2_EXTERNALTRIG_T3_TRGO          ((uint32_t)(ADC_CR2_EXTSEL_2                                      ))
/* 定时器 4 捕获/比较通道 4 */
#define ADC1_2_EXTERNALTRIG_T4_CC4           ((uint32_t)(ADC_CR2_EXTSEL_2 |                    ADC_CR2_EXTSEL_0))
/* 外部中断线 11 */
#define ADC1_2_EXTERNALTRIG_EXT_IT11         ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1                   ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意: TIM8_TRGO 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用。*/
#define ADC1_2_EXTERNALTRIG_T8_TRGO          ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3 规则组的外部触发 */
/* 定时器 3 捕获/比较通道 1 */
#define ADC3_EXTERNALTRIG_T3_CC1             ADC1_2_EXTERNALTRIG_T1_CC1
/* 定时器 2 捕获/比较通道 3 */
#define ADC3_EXTERNALTRIG_T2_CC3             ADC1_2_EXTERNALTRIG_T1_CC2
/* 定时器 8 捕获/比较通道 1 */
#define ADC3_EXTERNALTRIG_T8_CC1             ADC1_2_EXTERNALTRIG_T2_CC2
/* 定时器 8 触发输出 */
#define ADC3_EXTERNALTRIG_T8_TRGO            ADC1_2_EXTERNALTRIG_T3_TRGO
/* 定时器 5 捕获/比较通道 1 */
#define ADC3_EXTERNALTRIG_T5_CC1             ADC1_2_EXTERNALTRIG_T4_CC4
/* 定时器 5 捕获/比较通道 3 */
#define ADC3_EXTERNALTRIG_T5_CC3             ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

/* ADC1, ADC2, ADC3 规则组的外部触发 (如果有 ADCx 可用) */
/* 定时器 1 捕获/比较通道 3 */
#define ADC1_2_3_EXTERNALTRIG_T1_CC3         ((uint32_t)(                   ADC_CR2_EXTSEL_1                   ))
/* 软件触发 */
#define ADC1_2_3_SWSTART                     ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/**
  * @}
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Injected ADC 扩展内部 HAL 驱动注入组触发源选择
  * @{
  */
/* ADC1, ADC2, ADC3 (如果选定的设备上有该 ADC 实例) 注入组的外部触发列表。*/
/* (由 HAL 驱动内部使用。不用于 HAL 结构参数)  */

/* ADC1 和 ADC2 注入组的外部触发 (如果有 ADCx 可用) */
/* 定时器 2 触发输出 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_TRGO          ((uint32_t)(                    ADC_CR2_JEXTSEL_1                    ))
/* 定时器 2 捕获/比较通道 1 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_CC1           ((uint32_t)(                    ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/* 定时器 3 捕获/比较通道 4 */
#define ADC1_2_EXTERNALTRIGINJEC_T3_CC4           ((uint32_t)(ADC_CR2_JEXTSEL_2                                        ))
/* 定时器 4 触发输出 */
#define ADC1_2_EXTERNALTRIGINJEC_T4_TRGO          ((uint32_t)(ADC_CR2_JEXTSEL_2 |                     ADC_CR2_JEXTSEL_0))
/* 外部中断线 15 */
#define ADC1_2_EXTERNALTRIGINJEC_EXT_IT15         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1                    ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意: TIM8_CC4 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用。*/
#define ADC1_2_EXTERNALTRIGINJEC_T8_CC4           ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3 注入组的外部触发 */
/* 定时器 4 捕获/比较通道 3 */
#define ADC3_EXTERNALTRIGINJEC_T4_CC3             ADC1_2_EXTERNALTRIGINJEC_T2_TRGO
/* 定时器 8 捕获/比较通道 2 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC2             ADC1_2_EXTERNALTRIGINJEC_T2_CC1
/* 定时器 8 捕获/比较通道 4 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC4             ADC1_2_EXTERNALTRIGINJEC_T3_CC4
/* 定时器 5 触发输出 */
#define ADC3_EXTERNALTRIGINJEC_T5_TRGO            ADC1_2_EXTERNALTRIGINJEC_T4_TRGO
/* 定时器 5 捕获/比较通道 4 */
#define ADC3_EXTERNALTRIGINJEC_T5_CC4             ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif /* STM32F103xE || defined STM32F103xG */

/* ADC1, ADC2, ADC3 注入组的外部触发 (如果有 ADCx 可用) */
/* 定时器 1 触发输出 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO                    0x00000000U
/* 定时器 1 捕获/比较通道 4 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4         ((uint32_t)(                                        ADC_CR2_JEXTSEL_0))
/* 注入组软件触发 */
#define ADC1_2_3_JSWSTART                         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/**
  * @}
  */

/**
  * @}
  */


/* 导出宏 ------------------------------------------------------------*/

/* 私有宏 -------------------------------------------------------------*/

/** @defgroup ADCEx_Private_Macro ADCEx 私有宏
  * @{
  */
/* 宏保留供 HAL 驱动内部使用，不打算在最终用户的代码中使用。*/

    
/**
  * @brief 对于具有 3 个 ADC 的设备: 根据公共组 ADC1&ADC2 或 ADC3 中的 ADC 定义规则组的外部触发源
  *        (某些具有相同源的触发器在写入 CR2 寄存器的 EXTSEL 位时具有不同的值)。
  *        对于具有 2 个或更少 ADC 的设备: 此宏不做任何更改。
  * @param __HANDLE__: ADC 句柄
  * @param __EXT_TRIG_CONV__: 为规则组选择的外部触发。
  * @retval 要写入 CR2 寄存器 EXTSEL 位的外部触发值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 配置规则组外部触发源 (ADC3 与 ADC1/2 部分触发源不同) */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
 (( (((__HANDLE__)->Instance) == ADC3)                                         \
  )?                                                                           \
   ( ( (__EXT_TRIG_CONV__) == ADC_EXTERNALTRIGCONV_T8_TRGO                     \
     )?                                                                        \
      (ADC3_EXTERNALTRIG_T8_TRGO)                                              \
      :                                                                        \
      (__EXT_TRIG_CONV__)                                                      \
   )                                                                           \
   :                                                                           \
   (__EXT_TRIG_CONV__)                                                         \
 )
#else
/* 宏定义: 配置规则组外部触发源 (非大容量设备，直接返回传入值) */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
  (__EXT_TRIG_CONV__)
#endif /* STM32F103xE || STM32F103xG */

/**
  * @brief 对于具有 3 个 ADC 的设备: 根据公共组 ADC1&ADC2 或 ADC3 中的 ADC 定义注入组的外部触发源
  *        (某些具有相同源的触发器在写入 CR2 寄存器的 JEXTSEL 位时具有不同的值)。
  *        对于具有 2 个或更少 ADC 的设备: 此宏不做任何更改。
  * @param __HANDLE__: ADC 句柄
  * @param __EXT_TRIG_INJECTCONV__: 为注入组选择的外部触发。
  * @retval 要写入 CR2 寄存器 JEXTSEL 位的外部触发值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 配置注入组外部触发源 (ADC3 与 ADC1/2 部分触发源不同) */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
 (( (((__HANDLE__)->Instance) == ADC3)                                         \
  )?                                                                           \
   ( ( (__EXT_TRIG_INJECTCONV__) == ADC_EXTERNALTRIGINJECCONV_T8_CC4           \
     )?                                                                        \
      (ADC3_EXTERNALTRIGINJEC_T8_CC4)                                          \
      :                                                                        \
      (__EXT_TRIG_INJECTCONV__)                                                \
   )                                                                           \
   :                                                                           \
   (__EXT_TRIG_INJECTCONV__)                                                   \
 )
#else
/* 宏定义: 配置注入组外部触发源 (非大容量设备，直接返回传入值) */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
   (__EXT_TRIG_INJECTCONV__)
#endif /* STM32F103xE || STM32F103xG */


/**
  * @brief 验证所选 ADC 的多模式是否使能 (多模式 ADC 主机或 ADC 从机) (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 多模式状态: 如果多模式禁用则为 RESET，如果多模式使能则为其他值
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 检查多模式是否使能 (通过检查 ADC1 的 CR1 寄存器 DUALMOD 位) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
 (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)   \
  )?                                                                           \
   (ADC1->CR1 & ADC_CR1_DUALMOD)                                               \
   :                                                                           \
   (RESET)                                                                     \
 )
#else
/* 宏定义: 检查多模式是否使能 (无多模式功能的设备，直接返回 RESET) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief ADC 启动转换条件的验证: ADC 必须处于非多模式，或者是多模式下的 ADC 主机句柄 (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 检查是否为非多模式或多模式主机 (ADC2 作为从机时不能独立启动) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (( (((__HANDLE__)->Instance) == ADC2)                                        \
   )?                                                                          \
    ((ADC1->CR1 & ADC_CR1_DUALMOD) == RESET)                                   \
    :                                                                          \
    (!RESET)                                                                   \
  )
#else
/* 宏定义: 检查是否为非多模式或多模式主机 (无多模式功能的设备，直接返回 !RESET) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (!RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief 检查 ADC 多模式设置: 在多模式情况下，检查所选 ADC 的 ADC 主机是否启用了自动注入功能 (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 检查多模式下自动注入是否使能 */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)  \
   )?                                                                          \
    (ADC1->CR1 & ADC_CR1_JAUTO)                                                \
    :                                                                          \
    (RESET)                                                                    \
  )
#else
/* 宏定义: 检查多模式下自动注入是否使能 (无多模式功能的设备，直接返回 RESET) */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief 设置共享公共多模式设置的另一个 ADC 的句柄
  * @param __HANDLE__: ADC 句柄
  * @param __HANDLE_OTHER_ADC__: 另一个 ADC 句柄
  * @retval 无
  */
/* 宏定义: 获取另一个 ADC 句柄 (固定为 ADC2) */
#define ADC_COMMON_ADC_OTHER(__HANDLE__, __HANDLE_OTHER_ADC__)                 \
  ((__HANDLE_OTHER_ADC__)->Instance = ADC2)

/**
  * @brief 设置与 ADC 主机关联的 ADC 从机句柄
  * 在 STM32F1 设备上，ADC 从机始终是 ADC2 (在其他 STM32 设备上可能不同)
  * @param __HANDLE_MASTER__: ADC 主机句柄
  * @param __HANDLE_SLAVE__: ADC 从机句柄
  * @retval 无
  */
/* 宏定义: 设置 ADC 从机句柄 (固定为 ADC2) */
#define ADC_MULTI_SLAVE(__HANDLE_MASTER__, __HANDLE_SLAVE__)                   \
  ((__HANDLE_SLAVE__)->Instance = ADC2)
       
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* 宏定义: 检查注入通道排名是否有效 (1 到 4) */
#define IS_ADC_INJECTED_RANK(CHANNEL) (((CHANNEL) == ADC_INJECTED_RANK_1) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_2) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_3) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_4))

/* 宏定义: 检查注入组外部触发边沿是否有效 (无触发或上升沿) */
#define IS_ADC_EXTTRIGINJEC_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)  || \
                                        ((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING))

/** @defgroup ADCEx_injected_nb_conv_verification ADCEx 注入转换数量验证
  * @{
  */
/* 宏定义: 检查注入组转换数量是否有效 (1 到 4) */
#define IS_ADC_INJECTED_NB_CONV(LENGTH)  (((LENGTH) >= 1U) && ((LENGTH) <= 4U))
/**
  * @}
  */
#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
/* 检查ADC常规通道外部触发源是否有效 */
/* 参数REGTRIG: 外部触发源选择 */
/* 支持的触发源: 定时器1捕获比较1/2, 定时器2捕获比较2, 定时器3TRGO, 定时器4捕获比较4, 外部中断11, 软件启动 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F101xE)
/* 检查ADC常规通道外部触发源是否有效 (适用于STM32F101xE系列) */
/* 相比上一段定义，此处增加了对定时器8 TRGO事件的支持 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F101xG)
/* 检查ADC常规通道外部触发源是否有效 (适用于STM32F101xG系列) */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 检查ADC常规通道外部触发源是否有效 (适用于STM32F103xE/G大容量系列) */
/* 大容量系列拥有最丰富的外部触发源选择，支持多个定时器的捕获比较通道 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC3)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC3)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC3)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif

#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
/* 检查ADC注入通道外部触发源是否有效 */
/* 参数REGTRIG: 注入通道外部触发源选择 */
/* 注入通道通常用于高优先级的转换，支持定时器触发或外部中断触发 */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F101xE)
/* 检查ADC注入通道外部触发源是否有效 (适用于STM32F101xE系列) */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F101xG)
/* 检查ADC注入通道外部触发源是否有效 (适用于STM32F101xG系列) */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 检查ADC注入通道外部触发源是否有效 (适用于STM32F103xE/G大容量系列) */
/* 大容量系列支持更多的注入通道触发源组合 */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_CC3)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC2)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 检查ADC多模模式配置是否有效 */
/* 参数MODE: ADC多模工作模式 */
/* 多模模式用于配置两个ADC协同工作，如同步采样、交替采样等 */
#define IS_ADC_MODE(MODE) (((MODE) == ADC_MODE_INDEPENDENT)                || \
                           ((MODE) == ADC_DUALMODE_REGSIMULT_INJECSIMULT)  || \
                           ((MODE) == ADC_DUALMODE_REGSIMULT_ALTERTRIG)    || \
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLFAST) || \
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLSLOW) || \
                           ((MODE) == ADC_DUALMODE_INJECSIMULT)            || \
                           ((MODE) == ADC_DUALMODE_REGSIMULT)              || \
                           ((MODE) == ADC_DUALMODE_INTERLFAST)             || \
                           ((MODE) == ADC_DUALMODE_INTERLSLOW)             || \
                           ((MODE) == ADC_DUALMODE_ALTERTRIG) )
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */      
    
/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup ADCEx_Exported_Functions
  * @{
  */

/* 输入输出操作函数 *****************************************************/
/** @addtogroup ADCEx_Exported_Functions_Group1
  * @{
  */

/* ADC校验功能 */
/* 启动ADC校准过程，校准可以减小ADC转换误差 */
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc);

/* 阻塞模式: 轮询方式 */
/* 启动注入通道转换 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc);
/* 停止注入通道转换 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc);
/* 等待注入通道转换完成(阻塞式)，参数Timeout为超时时间 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);

/* 非阻塞模式: 中断方式 */
/* 启动注入通道转换(中断模式)，转换完成后会触发中断 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc);
/* 停止注入通道转换(中断模式) */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc);

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* ADC多模模式 */
/* 启动多模转换并通过DMA传输数据，用于双ADC同步采集场景 */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
/* 停止多模转换并关闭DMA */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc); 
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC获取转换值，通常用于轮询或中断方式读取结果 */
/* 获取注入通道转换结果，参数InjectedRank为注入通道排名(1-4) */
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank);
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 获取多模模式下的转换结果 */
uint32_t                HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef *hadc);
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC中断处理函数和回调函数，用于非阻塞模式(中断) */
/* 注入通道转换完成回调函数，用户可在自己的代码中重新实现此函数 */
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc);
/**
  * @}
  */


/* 外设控制函数 ***********************************************/
/** @addtogroup ADCEx_Exported_Functions_Group2
  * @{
  */
/* 配置注入通道参数，如通道号、采样周期等 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected);
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 配置ADC多模工作模式参数 */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef *hadc, ADC_MultiModeTypeDef *multimode);
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */
/**
  * @}
  */


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

#endif /* __STM32F1xx_HAL_ADC_EX_H */
