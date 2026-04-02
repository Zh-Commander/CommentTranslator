/**
  * @brief  Set ADC group injected conversion trigger:
  *         independent or from ADC group regular.
  *         设置ADC注入组的转换触发方式：独立触发或来自ADC常规组触发。
  * @note   This mode can be used to extend number of data registers
  *         updated after one ADC conversion trigger and with data 
  *         permanently kept (not erased by successive conversions of scan of
  *         ADC sequencer ranks), up to 5 data registers:
  *         1 data register on ADC group regular, 4 data registers
  *         on ADC group injected.            
  *         此模式可用于扩展在一次ADC转换触发后更新的数据寄存器数量，
  *         并且数据永久保留（不会被ADC序列器等级的连续扫描转换擦除），
  *         最多可达5个数据寄存器：常规组1个，注入组4个。
  * @note   If ADC group injected injected trigger source is set to an
  *         external trigger, this feature must be must be set to
  *         independent trigger.
  *         ADC group injected automatic trigger is compliant only with 
  *         group injected trigger source set to SW start, without any 
  *         further action on  ADC group injected conversion start or stop: 
  *         in this case, ADC group injected is controlled only 
  *         from ADC group regular.
  *         如果ADC注入组触发源设置为外部触发，则此功能必须设置为独立触发。
  *         ADC注入组自动触发仅兼容设置为软件启动(SW start)的注入组触发源，
  *         无需对ADC注入组转换启动或停止进行任何进一步操作：
  *         在这种情况下，ADC注入组仅由ADC常规组控制。
  * @note   It is not possible to enable both ADC group injected
  *         auto-injected mode and sequencer discontinuous mode.
  *         不能同时使能ADC注入组自动注入模式和序列器不连续模式。
  * @rmtoll CR1      JAUTO          LL_ADC_INJ_SetTrigAuto
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @param  TrigAuto This parameter can be one of the following values:
  *         此参数可以是以下值之一：
  *         @arg @ref LL_ADC_INJ_TRIG_INDEPENDENT    // 注入组触发独立于常规组
  *         @arg @ref LL_ADC_INJ_TRIG_FROM_GRP_REGULAR // 注入组触发由常规组触发
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_SetTrigAuto(ADC_TypeDef *ADCx, uint32_t TrigAuto)
{
  /* 修改CR1寄存器的JAUTO位，设置自动注入模式 */
  MODIFY_REG(ADCx->CR1, ADC_CR1_JAUTO, TrigAuto);
}

/**
  * @brief  Get ADC group injected conversion trigger:
  *         independent or from ADC group regular.
  *         获取ADC注入组的转换触发方式：独立触发或来自ADC常规组触发。
  * @rmtoll CR1      JAUTO          LL_ADC_INJ_GetTrigAuto
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @retval Returned value can be one of the following values:
  *         返回值可以是以下值之一：
  *         @arg @ref LL_ADC_INJ_TRIG_INDEPENDENT
  *         @arg @ref LL_ADC_INJ_TRIG_FROM_GRP_REGULAR
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTrigAuto(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器的JAUTO位，返回当前的自动注入配置 */
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_JAUTO));
}

/**
  * @brief  Set ADC group injected offset.
  *         设置ADC注入组的偏移值。
  * @note   It sets:
  *         - ADC group injected rank to which the offset programmed
  *           will be applied
  *         - Offset level (offset to be subtracted from the raw
  *           converted data).
  *         Caution: Offset format is dependent to ADC resolution:
  *         offset has to be left-aligned on bit 11, the LSB (right bits)
  *         are set to 0.
  *         它设置：
  *         - 将应用编程偏移量的ADC注入组等级
  *         - 偏移电平（从原始转换数据中减去的偏移量）。
  *         注意：偏移格式取决于ADC分辨率：偏移量必须在第11位左对齐，LSB（右位）设置为0。
  * @note   Offset cannot be enabled or disabled.
  *         To emulate offset disabled, set an offset value equal to 0.
  *         偏移量不能被使能或禁用。要模拟禁用偏移量，请将偏移值设置为0。
  * @rmtoll JOFR1    JOFFSET1       LL_ADC_INJ_SetOffset\n
  *         JOFR2    JOFFSET2       LL_ADC_INJ_SetOffset\n
  *         JOFR3    JOFFSET3       LL_ADC_INJ_SetOffset\n
  *         JOFR4    JOFFSET4       LL_ADC_INJ_SetOffset
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @param  Rank This parameter can be one of the following values:
  *         此参数可以是以下值之一（注入组序列等级）：
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @param  OffsetLevel Value between Min_Data=0x000 and Max_Data=0xFFF
  *         偏移值，范围在0x000到0xFFF之间
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_SetOffset(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t OffsetLevel)
{
  /* 根据Rank（等级）计算对应的JOFR寄存器指针 */
  /* __ADC_PTR_REG_OFFSET用于计算寄存器地址偏移，ADCx->JOFR1是基地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JOFR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JOFRX_REGOFFSET_MASK));
  
  /* 修改对应的JOFR寄存器，设置偏移值 */
  MODIFY_REG(*preg,
             ADC_JOFR1_JOFFSET1,
             OffsetLevel);
}

/**
  * @brief  Get ADC group injected offset.
  *         获取ADC注入组的偏移值。
  * @note   It gives offset level (offset to be subtracted from the raw converted data).
  *         Caution: Offset format is dependent to ADC resolution:
  *         offset has to be left-aligned on bit 11, the LSB (right bits)
  *         are set to 0.
  *         它返回偏移电平（从原始转换数据中减去的偏移量）。
  *         注意：偏移格式取决于ADC分辨率。
  * @rmtoll JOFR1    JOFFSET1       LL_ADC_INJ_GetOffset\n
  *         JOFR2    JOFFSET2       LL_ADC_INJ_GetOffset\n
  *         JOFR3    JOFFSET3       LL_ADC_INJ_GetOffset\n
  *         JOFR4    JOFFSET4       LL_ADC_INJ_GetOffset
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @param  Rank This parameter can be one of the following values:
  *         此参数可以是以下值之一（注入组序列等级）：
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval Value between Min_Data=0x000 and Max_Data=0xFFF
  *         返回偏移值，范围在0x000到0xFFF之间
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetOffset(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank（等级）计算对应的JOFR寄存器指针 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JOFR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JOFRX_REGOFFSET_MASK));
  
  /* 读取并返回对应JOFR寄存器中的偏移值 */
  return (uint32_t)(READ_BIT(*preg,
                             ADC_JOFR1_JOFFSET1)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_Channels Configuration of ADC hierarchical scope: channels
  *         ADC层级范围配置：通道配置
  * @{
  */

/**
  * @brief  Set sampling time of the selected ADC channel
  *         Unit: ADC clock cycles.
  *         设置所选ADC通道的采样时间
  *         单位：ADC时钟周期。
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  *         在此设备上，采样时间是基于通道范围的：与通道映射在ADC常规组还是注入组无关。
  * @note   In case of internal channel (VrefInt, TempSensor, ...) to be
  *         converted:
  *         sampling time constraints must be respected (sampling time can be
  *         adjusted in function of ADC clock frequency and sampling time
  *         setting).
  *         Refer to device datasheet for timings values (parameters TS_vrefint,
  *         TS_temp, ...).
  *         如果转换内部通道（VrefInt, TempSensor等）：
  *         必须遵守采样时间约束（可以根据ADC时钟频率和采样时间设置进行调整）。
  *         请参考设备数据手册获取时序值（参数TS_vrefint, TS_temp等）。
  * @note   Conversion time is the addition of sampling time and processing time.
  *         Refer to reference manual for ADC processing time of
  *         this STM32 series.
  *         转换时间是采样时间和处理时间的总和。
  *         请参考参考手册了解此STM32系列的ADC处理时间。
  * @note   In case of ADC conversion of internal channel (VrefInt,
  *         temperature sensor, ...), a sampling time minimum value
  *         is required.
  *         Refer to device datasheet.
  *         如果转换内部通道（VrefInt, 温度传感器等），需要最小采样时间值。
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
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @param  Channel This parameter can be one of the following values:
  *         此参数可以是以下值之一（ADC通道号）：
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
  *         (1) On STM32F1, parameter available only on ADC instance: ADC1.
  *             在STM32F1上，此参数仅在ADC1实例上可用。
  * @param  SamplingTime This parameter can be one of the following values:
  *         此参数可以是以下值之一（采样周期数）：
  *         @arg @ref LL_ADC_SAMPLINGTIME_1CYCLE_5    // 1.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_7CYCLES_5   // 7.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_13CYCLES_5  // 13.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_28CYCLES_5  // 28.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_41CYCLES_5  // 41.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_55CYCLES_5  // 55.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_71CYCLES_5  // 71.5个时钟周期
  *         @arg @ref LL_ADC_SAMPLINGTIME_239CYCLES_5 // 239.5个时钟周期
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetChannelSamplingTime(ADC_TypeDef *ADCx, uint32_t Channel, uint32_t SamplingTime)
{
  /* Set bits with content of parameter "SamplingTime" with bits position     */
  /* in register and register position depending on parameter "Channel".      */
  /* Parameter "Channel" is used with masks because containing                */
  /* other bits reserved for other purpose.                                   */
  /* 根据参数"Channel"（通道）设置寄存器位置和位偏移， */
  /* 将参数"SamplingTime"（采样时间）的内容写入对应位。 */
  /* 参数"Channel"使用掩码处理，因为它包含保留给其他用途的位。 */
  
  /* 计算采样时间寄存器指针(SMPR1或SMPR2) */
  /* ADC_CHANNEL_SMPRX_REGOFFSET_MASK 用于确定是SMPR1还是SMPR2 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SMPR1, __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPRX_REGOFFSET_MASK));
  
  /* 修改对应的采样时间位 */
  /* ADC_CHANNEL_SMPx_BITOFFSET_MASK 用于确定通道在寄存器中的位偏移 */
  MODIFY_REG(*preg,
             ADC_SMPR2_SMP0 << __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK),
             SamplingTime   << __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK));
}

/**
  * @brief  Get sampling time of the selected ADC channel
  *         Unit: ADC clock cycles.
  *         获取所选ADC通道的采样时间
  *         单位：ADC时钟周期。
  * @note   On this device, sampling time is on channel scope: independently
  *         of channel mapped on ADC group regular or injected.
  *         在此设备上，采样时间是基于通道范围的：与通道映射在ADC常规组还是注入组无关。
  * @note   Conversion time is the addition of sampling time and processing time.
  *         Refer to reference manual for ADC processing time of
  *         this STM32 series.
  *         转换时间是采样时间和处理时间的总和。
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
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @param  Channel This parameter can be one of the following values:
  *         此参数可以是以下值之一（ADC通道号）：
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
  *         (1) On STM32F1, parameter available only on ADC instance: ADC1.
  *             在STM32F1上，此参数仅在ADC1实例上可用。
  * @retval Returned value can be one of the following values:
  *         返回值可以是以下值之一：
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
  /* 计算采样时间寄存器指针(SMPR1或SMPR2) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SMPR1, __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPRX_REGOFFSET_MASK));
  
  /* 读取对应的采样时间位，并右移对齐后返回 */
  return (uint32_t)(READ_BIT(*preg,
                             ADC_SMPR2_SMP0 << __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK))
                    >> __ADC_MASK_SHIFT(Channel, ADC_CHANNEL_SMPx_BITOFFSET_MASK)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_AnalogWatchdog Configuration of ADC transversal scope: analog watchdog
  *         ADC横向范围配置：模拟看门狗配置
  * @{
  */

/**
  * @brief  Set ADC analog watchdog monitored channels:
  *         a single channel or all channels,
  *         on ADC groups regular and-or injected.
  *         设置ADC模拟看门狗监控的通道：
  *         单个通道或所有通道，
  *         在ADC常规组和/或注入组上。
  * @note   Once monitored channels are selected, analog watchdog
  *         is enabled.
  *         一旦选择了监控通道，模拟看门狗即被使能。
  * @note   In case of need to define a single channel to monitor
  *         with analog watchdog from sequencer channel definition,
  *         use helper macro @ref __LL_ADC_ANALOGWD_CHANNEL_GROUP().
  *         如果需要从序列器通道定义中定义单个通道由模拟看门狗监控，
  *         请使用辅助宏 @ref __LL_ADC_ANALOGWD_CHANNEL_GROUP()。
  * @note   On this STM32 series, there is only 1 kind of analog watchdog
  *         instance:
  *         - AWD standard (instance AWD1):
  *           - channels monitored: can monitor 1 channel or all channels.
  *           - groups monitored: ADC groups regular and-or injected.
  *           - resolution: resolution is not limited (corresponds to
  *             ADC resolution configured).
  *         在此STM32系列上，只有1种模拟看门狗实例：
  *         - AWD标准（实例AWD1）：
  *           - 监控通道：可以监控1个通道或所有通道。
  *           - 监控组：ADC常规组和/或注入组。
  *           - 分辨率：分辨率不受限制（对应于配置的ADC分辨率）。
  * @rmtoll CR1      AWD1CH         LL_ADC_SetAnalogWDMonitChannels\n
  *         CR1      AWD1SGL        LL_ADC_SetAnalogWDMonitChannels\n
  *         CR1      AWD1EN         LL_ADC_SetAnalogWDMonitChannels
  * @param  ADCx ADC instance
  *         ADC实例指针
  * @param  AWDChannelGroup This parameter can be one of the following values:
  *         此参数可以是以下值之一（模拟看门狗通道及组配置）：
  *         @arg @ref LL_ADC_AWD_DISABLE               // 禁用模拟看门狗
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG      // 监控所有常规组通道
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_INJ      // 监控所有注入组通道
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG_INJ  // 监控所有常规组和注入组通道
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG         // 监控通道0（常规组）
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_INJ         // 监控通道0（注入组）
  *         @arg @ref LL_ADC_AWD_CHANNEL_0_REG_INJ     // 监控通道0（常规组和注入组）
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
  *         @arg @ref LL_ADC_AWD_CH_VREFINT_REG          (1) // 监控内部参考电压（常规组）
  *         @arg @ref LL_ADC_AWD_CH_VREFINT_INJ          (1) // 监控内部参考电压（注入组）
  *         @arg @ref LL_ADC_AWD_CH_VREFINT_REG_INJ      (1)
  *         @arg @ref LL_ADC_AWD_CH_TEMPSENSOR_REG       (1) // 监控温度传感器（常规组）
  *         @arg @ref LL_ADC_AWD_CH_TEMPSENSOR_INJ       (1) // 监控温度传感器（注入组）
  *         @arg @ref LL_ADC_AWD_CH_TEMPSENSOR_REG_INJ   (1)
  *         
  *         (1) On STM32F1, parameter available only on ADC instance: ADC1.
  *             在STM32F1上，此参数仅在ADC1实例上可用。
  * @retval None
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDMonitChannels(ADC_TypeDef *ADCx, uint32_t AWDChannelGroup)
{
  /* 配置CR1寄存器：
     ADC_CR1_AWDEN:  常规组模拟看门狗使能
     ADC_CR1_JAWDEN: 注入组模拟看门狗使能
     ADC_CR1_AWDSGL: 单通道/所有通道选择
     ADC_CR1_AWDCH:  看门狗通道选择位
  */
  MODIFY_REG(ADCx->CR1,
             (ADC_CR1_AWDEN | ADC_CR1_JAWDEN | ADC_CR1_AWDSGL | ADC_CR1_AWDCH),
             AWDChannelGroup);
}
