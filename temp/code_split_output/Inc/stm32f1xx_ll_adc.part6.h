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

