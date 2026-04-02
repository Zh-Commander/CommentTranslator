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
