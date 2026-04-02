/** @defgroup ADC_channels ADC channels
  * @{
  */
/* 注意：取决于具体的设备型号，某些通道可能在封装引脚上不可用 */
/*       请参考设备数据手册以了解通道的可用性情况。           */
#define ADC_CHANNEL_0                       0x00000000U  // ADC通道0，对应数值为0
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

#define ADC_CHANNEL_TEMPSENSOR  ADC_CHANNEL_16  /* ADC内部通道（设备引脚上无连接），用于测量芯片内部温度传感器 */
#define ADC_CHANNEL_VREFINT     ADC_CHANNEL_17  /* ADC内部通道（设备引脚上无连接），用于测量内部参考电压 */
/**
  * @}
  */

/** @defgroup ADC_sampling_times ADC sampling times
  * @{
  */
#define ADC_SAMPLETIME_1CYCLE_5                   0x00000000U                                              /*!< 采样时间 1.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_7CYCLES_5      ((uint32_t)(                                      ADC_SMPR2_SMP0_0)) /*!< 采样时间 7.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_13CYCLES_5     ((uint32_t)(                   ADC_SMPR2_SMP0_1                   )) /*!< 采样时间 13.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_28CYCLES_5     ((uint32_t)(                   ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)) /*!< 采样时间 28.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_41CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2                                      )) /*!< 采样时间 41.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_55CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2                    | ADC_SMPR2_SMP0_0)) /*!< 采样时间 55.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_71CYCLES_5     ((uint32_t)(ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1                   )) /*!< 采样时间 71.5 个ADC时钟周期 */
#define ADC_SAMPLETIME_239CYCLES_5    ((uint32_t)(ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)) /*!< 采样时间 239.5 个ADC时钟周期 */
/**
  * @}
  */

/** @defgroup ADC_regular_rank ADC rank into regular group
  * @{
  */
// 以下定义用于设置常规组中的转换顺序（秩），取值范围1-16
#define ADC_REGULAR_RANK_1                 0x00000001U  // 常规组序列中的第1个转换
#define ADC_REGULAR_RANK_2                 0x00000002U  // 常规组序列中的第2个转换
#define ADC_REGULAR_RANK_3                 0x00000003U  // 常规组序列中的第3个转换
#define ADC_REGULAR_RANK_4                 0x00000004U  // 常规组序列中的第4个转换
#define ADC_REGULAR_RANK_5                 0x00000005U  // 常规组序列中的第5个转换
#define ADC_REGULAR_RANK_6                 0x00000006U  // 常规组序列中的第6个转换
#define ADC_REGULAR_RANK_7                 0x00000007U  // 常规组序列中的第7个转换
#define ADC_REGULAR_RANK_8                 0x00000008U  // 常规组序列中的第8个转换
#define ADC_REGULAR_RANK_9                 0x00000009U  // 常规组序列中的第9个转换
#define ADC_REGULAR_RANK_10                0x0000000AU  // 常规组序列中的第10个转换
#define ADC_REGULAR_RANK_11                0x0000000BU  // 常规组序列中的第11个转换
#define ADC_REGULAR_RANK_12                0x0000000CU  // 常规组序列中的第12个转换
#define ADC_REGULAR_RANK_13                0x0000000DU  // 常规组序列中的第13个转换
#define ADC_REGULAR_RANK_14                0x0000000EU  // 常规组序列中的第14个转换
#define ADC_REGULAR_RANK_15                0x0000000FU  // 常规组序列中的第15个转换
#define ADC_REGULAR_RANK_16                0x00000010U  // 常规组序列中的第16个转换
/**
  * @}
  */

/** @defgroup ADC_analog_watchdog_mode ADC analog watchdog mode
  * @{
  */
// 模拟看门狗模式配置：用于监控电压是否超出阈值
#define ADC_ANALOGWATCHDOG_NONE                             0x00000000U  // 不使用模拟看门狗
#define ADC_ANALOGWATCHDOG_SINGLE_REG           ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN))  // 单通道模式，监控常规组
#define ADC_ANALOGWATCHDOG_SINGLE_INJEC         ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_JAWDEN))  // 单通道模式，监控注入组
#define ADC_ANALOGWATCHDOG_SINGLE_REGINJEC      ((uint32_t)(ADC_CR1_AWDSGL | ADC_CR1_AWDEN | ADC_CR1_JAWDEN))  // 单通道模式，监控常规组和注入组
#define ADC_ANALOGWATCHDOG_ALL_REG              ((uint32_t)ADC_CR1_AWDEN)  // 所有通道模式，监控常规组
#define ADC_ANALOGWATCHDOG_ALL_INJEC            ((uint32_t)ADC_CR1_JAWDEN)  // 所有通道模式，监控注入组
#define ADC_ANALOGWATCHDOG_ALL_REGINJEC         ((uint32_t)(ADC_CR1_AWDEN | ADC_CR1_JAWDEN))  // 所有通道模式，监控常规组和注入组
/**
  * @}
  */

/** @defgroup ADC_conversion_group ADC conversion group
  * @{
  */
// ADC转换组类型定义
#define ADC_REGULAR_GROUP             ((uint32_t)(ADC_FLAG_EOC))  // 常规转换组
#define ADC_INJECTED_GROUP            ((uint32_t)(ADC_FLAG_JEOC))  // 注入转换组
#define ADC_REGULAR_INJECTED_GROUP    ((uint32_t)(ADC_FLAG_EOC | ADC_FLAG_JEOC))  // 常规组和注入组
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
// ADC中断定义
#define ADC_IT_EOC           ADC_CR1_EOCIE        /*!< ADC常规转换结束中断源 */
#define ADC_IT_JEOC          ADC_CR1_JEOCIE       /*!< ADC注入转换结束中断源 */
#define ADC_IT_AWD           ADC_CR1_AWDIE        /*!< ADC模拟看门狗中断源 */
/**
  * @}
  */

/** @defgroup ADC_flags_definition ADC flags definition
  * @{
  */
// ADC标志位定义
#define ADC_FLAG_STRT          ADC_SR_STRT     /*!< ADC常规组转换开始标志 */
#define ADC_FLAG_JSTRT         ADC_SR_JSTRT    /*!< ADC注入组转换开始标志 */
#define ADC_FLAG_EOC           ADC_SR_EOC      /*!< ADC常规转换结束标志 */
#define ADC_FLAG_JEOC          ADC_SR_JEOC     /*!< ADC注入转换结束标志 */
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
/* ADC转换周期数（单位：ADC时钟周期）                                        */
/* （选定的采样时间 + 12.5个ADC时钟周期的转换时间，分辨率为12位）             */
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_1CYCLE5                  14U  // 采样时间1.5周期 + 12.5周期转换时间 = 14周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_7CYCLES5                 20U  // 采样时间7.5周期 + 12.5周期转换时间 = 20周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_13CYCLES5                26U  // 采样时间13.5周期 + 12.5周期转换时间 = 26周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_28CYCLES5                41U  // 采样时间28.5周期 + 12.5周期转换时间 = 41周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_41CYCLES5                54U  // 采样时间41.5周期 + 12.5周期转换时间 = 54周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_55CYCLES5                68U  // 采样时间55.5周期 + 12.5周期转换时间 = 68周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_71CYCLES5                84U  // 采样时间71.5周期 + 12.5周期转换时间 = 84周期
#define ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_239CYCLES5              252U  // 采样时间239.5周期 + 12.5周期转换时间 = 252周期
/**
  * @}
  */

/** @defgroup ADC_sampling_times_all_channels ADC sampling times all channels
  * @{
  */
// 以下宏定义用于批量设置所有ADC通道的采样时间，通过操作SMPR1和SMPR2寄存器实现
// SMPR2寄存器控制通道0-9，SMPR1寄存器控制通道10-17
// 这里的BIT2, BIT1, BIT0对应采样时间控制位的组合

// SMPR2寄存器所有通道的第2位（Bit 2）掩码
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2                                          \
     (ADC_SMPR2_SMP9_2 | ADC_SMPR2_SMP8_2 | ADC_SMPR2_SMP7_2 | ADC_SMPR2_SMP6_2 |     \
      ADC_SMPR2_SMP5_2 | ADC_SMPR2_SMP4_2 | ADC_SMPR2_SMP3_2 | ADC_SMPR2_SMP2_2 |     \
      ADC_SMPR2_SMP1_2 | ADC_SMPR2_SMP0_2)
// SMPR1寄存器所有通道的第2位（Bit 2）掩码
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2                                          \
     (ADC_SMPR1_SMP17_2 | ADC_SMPR1_SMP16_2 | ADC_SMPR1_SMP15_2 | ADC_SMPR1_SMP14_2 | \
      ADC_SMPR1_SMP13_2 | ADC_SMPR1_SMP12_2 | ADC_SMPR1_SMP11_2 | ADC_SMPR1_SMP10_2 )

// SMPR2寄存器所有通道的第1位（Bit 1）掩码
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1                                          \
     (ADC_SMPR2_SMP9_1 | ADC_SMPR2_SMP8_1 | ADC_SMPR2_SMP7_1 | ADC_SMPR2_SMP6_1 |     \
      ADC_SMPR2_SMP5_1 | ADC_SMPR2_SMP4_1 | ADC_SMPR2_SMP3_1 | ADC_SMPR2_SMP2_1 |     \
      ADC_SMPR2_SMP1_1 | ADC_SMPR2_SMP0_1)
// SMPR1寄存器所有通道的第1位（Bit 1）掩码
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1                                          \
     (ADC_SMPR1_SMP17_1 | ADC_SMPR1_SMP16_1 | ADC_SMPR1_SMP15_1 | ADC_SMPR1_SMP14_1 | \
      ADC_SMPR1_SMP13_1 | ADC_SMPR1_SMP12_1 | ADC_SMPR1_SMP11_1 | ADC_SMPR1_SMP10_1 )

// SMPR2寄存器所有通道的第0位（Bit 0）掩码
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0                                          \
     (ADC_SMPR2_SMP9_0 | ADC_SMPR2_SMP8_0 | ADC_SMPR2_SMP7_0 | ADC_SMPR2_SMP6_0 |     \
      ADC_SMPR2_SMP5_0 | ADC_SMPR2_SMP4_0 | ADC_SMPR2_SMP3_0 | ADC_SMPR2_SMP2_0 |     \
      ADC_SMPR2_SMP1_0 | ADC_SMPR2_SMP0_0)
// SMPR1寄存器所有通道的第0位（Bit 0）掩码
#define ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0                                          \
     (ADC_SMPR1_SMP17_0 | ADC_SMPR1_SMP16_0 | ADC_SMPR1_SMP15_0 | ADC_SMPR1_SMP14_0 | \
      ADC_SMPR1_SMP13_0 | ADC_SMPR1_SMP12_0 | ADC_SMPR1_SMP11_0 | ADC_SMPR1_SMP10_0 )

// SMPR2寄存器所有通道采样时间配置：1.5周期
#define ADC_SAMPLETIME_1CYCLE5_SMPR2ALLCHANNELS    0x00000000U
// SMPR2寄存器所有通道采样时间配置：7.5周期
#define ADC_SAMPLETIME_7CYCLES5_SMPR2ALLCHANNELS   (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
// SMPR2寄存器所有通道采样时间配置：13.5周期
#define ADC_SAMPLETIME_13CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1)
// SMPR2寄存器所有通道采样时间配置：28.5周期
#define ADC_SAMPLETIME_28CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
// SMPR2寄存器所有通道采样时间配置：41.5周期
#define ADC_SAMPLETIME_41CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2)
// SMPR2寄存器所有通道采样时间配置：55.5周期
#define ADC_SAMPLETIME_55CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)
// SMPR2寄存器所有通道采样时间配置：71.5周期
#define ADC_SAMPLETIME_71CYCLES5_SMPR2ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1)
// SMPR2寄存器所有通道采样时间配置：239.5周期
#define ADC_SAMPLETIME_239CYCLES5_SMPR2ALLCHANNELS (ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT0)

// SMPR1寄存器所有通道采样时间配置：1.5周期
#define ADC_SAMPLETIME_1CYCLE5_SMPR1ALLCHANNELS    0x00000000U
// SMPR1寄存器所有通道采样时间配置：7.5周期
#define ADC_SAMPLETIME_7CYCLES5_SMPR1ALLCHANNELS   (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
// SMPR1寄存器所有通道采样时间配置：13.5周期
#define ADC_SAMPLETIME_13CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1)
// SMPR1寄存器所有通道采样时间配置：28.5周期
#define ADC_SAMPLETIME_28CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
// SMPR1寄存器所有通道采样时间配置：41.5周期
#define ADC_SAMPLETIME_41CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2)
// SMPR1寄存器所有通道采样时间配置：55.5周期
#define ADC_SAMPLETIME_55CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0)
// SMPR1寄存器所有通道采样时间配置：71.5周期
#define ADC_SAMPLETIME_71CYCLES5_SMPR1ALLCHANNELS  (ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2 | ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1)
// SMPR1寄存器所有通道采样时间配置：239.5周期
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
/* 供HAL驱动内部使用的宏，也可能用于最终用户的代码中 */    

/**
  * @brief 使能ADC外设
  * @note ADC使能后需要延时等待ADC稳定时间
  *       (请参考设备数据手册，参数 tSTAB)
  * @note 在STM32F1上，如果ADC已经使能，此宏会触发常规组的软件启动转换
  * @param __HANDLE__: ADC句柄
  * @retval 无
  */
#define __HAL_ADC_ENABLE(__HANDLE__)                                           \
  (SET_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADON)))  // 设置CR2寄存器的ADON位来使能ADC
    
/**
  * @brief 关闭ADC外设
  * @param __HANDLE__: ADC句柄
  * @retval 无
  */
#define __HAL_ADC_DISABLE(__HANDLE__)                                          \
  (CLEAR_BIT((__HANDLE__)->Instance->CR2, (ADC_CR2_ADON)))  // 清除CR2寄存器的ADON位来关闭ADC
    
/** @brief 使能ADC转换结束中断。
  * @param __HANDLE__: ADC句柄
  * @param __INTERRUPT__: ADC中断类型
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_IT_EOC: ADC常规转换结束中断源
  *            @arg ADC_IT_JEOC: ADC注入转换结束中断源
  *            @arg ADC_IT_AWD: ADC模拟看门狗中断源
  * @retval 无
  */
#define __HAL_ADC_ENABLE_IT(__HANDLE__, __INTERRUPT__)                         \
  (SET_BIT((__HANDLE__)->Instance->CR1, (__INTERRUPT__)))  // 设置CR1寄存器中对应的中断使能位
    
/** @brief 关闭ADC转换结束中断。
  * @param __HANDLE__: ADC句柄
  * @param __INTERRUPT__: ADC中断类型
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_IT_EOC: ADC常规转换结束中断源
  *            @arg ADC_IT_JEOC: ADC注入转换结束中断源
  *            @arg ADC_IT_AWD: ADC模拟看门狗中断源
  * @retval 无
  */
#define __HAL_ADC_DISABLE_IT(__HANDLE__, __INTERRUPT__)                        \
  (CLEAR_BIT((__HANDLE__)->Instance->CR1, (__INTERRUPT__)))  // 清除CR1寄存器中对应的中断使能位

/** @brief  检查指定的ADC中断源是否已使能。
  * @param __HANDLE__: ADC句柄
  * @param __INTERRUPT__: 要检查的ADC中断源
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_IT_EOC: ADC常规转换结束中断源
  *            @arg ADC_IT_JEOC: ADC注入转换结束中断源
  *            @arg ADC_IT_AWD: ADC模拟看门狗中断源
  * @retval 无
  */
#define __HAL_ADC_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)                     \
  (((__HANDLE__)->Instance->CR1 & (__INTERRUPT__)) == (__INTERRUPT__))  // 读取CR1寄存器并判断中断使能位是否置位

/** @brief 获取所选ADC的标志状态。
  * @param __HANDLE__: ADC句柄
  * @param __FLAG__: ADC标志位
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_FLAG_STRT: ADC常规组转换开始标志
  *            @arg ADC_FLAG_JSTRT: ADC注入组转换开始标志
  *            @arg ADC_FLAG_EOC: ADC常规转换结束标志
  *            @arg ADC_FLAG_JEOC: ADC注入转换结束标志
  *            @arg ADC_FLAG_AWD: ADC模拟看门狗标志
  * @retval 无
  */
#define __HAL_ADC_GET_FLAG(__HANDLE__, __FLAG__)                               \
  ((((__HANDLE__)->Instance->SR) & (__FLAG__)) == (__FLAG__))  // 读取状态寄存器SR并判断指定标志位是否置位
    
/** @brief 清除ADC的挂起标志
  * @param __HANDLE__: ADC句柄
  * @param __FLAG__: ADC标志位
  *          该参数可以是以下值的任意组合:
  *            @arg ADC_FLAG_STRT: ADC常规组转换开始标志
  *            @arg ADC_FLAG_JSTRT: ADC注入组转换开始标志
  *            @arg ADC_FLAG_EOC: ADC常规转换结束标志
  *            @arg ADC_FLAG_JEOC: ADC注入转换结束标志
  *            @arg ADC_FLAG_AWD: ADC模拟看门狗标志
  * @retval 无
  */
#define __HAL_ADC_CLEAR_FLAG(__HANDLE__, __FLAG__)                             \
  (WRITE_REG((__HANDLE__)->Instance->SR, ~(__FLAG__)))  // 向SR寄存器写入取反后的标志位来清除标志（写0清除，部分标志写1清除，此处为HAL库实现方式）

/** @brief  复位ADC句柄状态
  * @param  __HANDLE__: ADC句柄
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
  ((__HANDLE__)->State = HAL_ADC_STATE_RESET)  // 将ADC句柄的状态复位为RESET
#endif

/**
  * @}
  */

/* Private macro ------------------------------------------------------------*/
/* 私有宏 --------------------------------------------------------------------*/

/** @defgroup ADC_Private_Macros ADC Private Macros
  * @{
  */
/* 保留供HAL驱动内部使用的宏，不打算让最终用户在代码中使用   */

/**
  * @brief 验证ADC状态：使能或失能
  * @param __HANDLE__: ADC句柄
  * @retval SET (ADC已使能) 或 RESET (ADC已失能)
  */
#define ADC_IS_ENABLE(__HANDLE__)                                              \
  ((( ((__HANDLE__)->Instance->CR2 & ADC_CR2_ADON) == ADC_CR2_ADON )           \
   ) ? SET : RESET)  // 检查CR2寄存器的ADON位，判断ADC是否处于工作状态

/**
  * @brief 测试常规组的转换触发是否为软件启动或外部触发。
  * @param __HANDLE__: ADC句柄
  * @retval SET (软件启动) 或 RESET (外部触发)
  */
#define ADC_IS_SOFTWARE_START_REGULAR(__HANDLE__)                              \
  (READ_BIT((__HANDLE__)->Instance->CR2, ADC_CR2_EXTSEL) == ADC_SOFTWARE_START)  // 读取CR2寄存器的EXTSEL位，判断是否为软件触发

/**
  * @brief 测试注入组的转换触发是否为软件启动或外部触发。
  * @param __HANDLE__: ADC句柄
  * @retval SET (软件启动) 或 RESET (外部触发)
  */
#define ADC_IS_SOFTWARE_START_INJECTED(__HANDLE__)                             \
  (READ_BIT((__HANDLE__)->Instance->CR2, ADC_CR2_JEXTSEL) == ADC_INJECTED_SOFTWARE_START)  // 读取CR2寄存器的JEXTSEL位，判断是否为软件触发

/**
  * @brief 同时清除和设置句柄状态的特定位
  * @note: ADC_STATE_CLR_SET() 宏仅仅是通用宏 MODIFY_REG() 的别名，
  *        第一个参数是ADC句柄状态，第二个参数是要清除的位域，
  *        第三个也是最后一个参数是要设置的位域。
  * @retval 无
  */
#define ADC_STATE_CLR_SET MODIFY_REG

/**
  * @brief 清除ADC错误代码（将其设置为错误代码：“无错误”）
  * @param __HANDLE__: ADC句柄
  * @retval 无
  */
#define ADC_CLEAR_ERRORCODE(__HANDLE__)                                        \
  ((__HANDLE__)->ErrorCode = HAL_ADC_ERROR_NONE)  // 将错误代码重置为无错误

/**
  * @brief 设置ADC常规通道序列长度（转换数量）。
  * @param _NbrOfConversion_: 常规通道序列长度 
  * @retval 无
  */
#define ADC_SQR1_L_SHIFT(_NbrOfConversion_)                                    \
  (((_NbrOfConversion_) - (uint8_t)1) << ADC_SQR1_L_Pos)  // 将转换数量减1后左移到SQR1寄存器的L位位置

/**
  * @brief 设置通道号在10到18之间的ADC采样时间。
  * @param _SAMPLETIME_: 采样时间参数。
  * @param _CHANNELNB_: 通道号。  
  * @retval 无
  */
#define ADC_SMPR1(_SAMPLETIME_, _CHANNELNB_)                                   \
  ((_SAMPLETIME_) << (ADC_SMPR1_SMP11_Pos * ((_CHANNELNB_) - 10)))  // 根据通道号计算移位位数，设置SMPR1寄存器中的采样时间
