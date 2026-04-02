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
