/**
  * @brief  获取ADC模拟看门狗监控的通道。
  * @note   返回通道号的使用方法:
  *         - 为了将该通道号重新注入到另一个函数 LL_ADC_xxx 中:
  *           返回的通道号仅在 LL_ADC_CHANNEL_x 定义的字面量上进行了部分格式化。
  *           因此，必须将其与 LL_ADC_CHANNEL_x 的部分字面量进行比较，或者使用
  *           辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  *           然后选定的 LL_ADC_CHANNEL_x 字面量可以用作另一个函数的参数。
  *         - 获取十进制格式的通道号:
  *           使用辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB() 处理返回值。
  *           仅适用于模拟看门狗设置为监控单个通道的情况。
  * @note   在此STM32系列上，只有1种模拟看门狗实例:
  *         - AWD 标准 (实例 AWD1):
  *           - 监控通道: 可以监控1个通道或所有通道。
  *           - 监控组: ADC 规则组和/或注入组。
  *           - 分辨率: 分辨率不受限制 (对应于配置的ADC分辨率)。
  * @rmtoll CR1      AWD1CH         LL_ADC_GetAnalogWDMonitChannels\n
  *         CR1      AWD1SGL        LL_ADC_GetAnalogWDMonitChannels\n
  *         CR1      AWD1EN         LL_ADC_GetAnalogWDMonitChannels
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_DISABLE
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_INJ
  *         @arg @ref LL_ADC_AWD_ALL_CHANNELS_REG_INJ
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
  */
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDMonitChannels(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器中与模拟看门狗通道配置相关的位 */
  /* ADC_CR1_AWDEN: 规则通道模拟看门狗使能 */
  /* ADC_CR1_JAWDEN: 注入通道模拟看门狗使能 */
  /* ADC_CR1_AWDSGL: 单通道/所有通道监控选择 */
  /* ADC_CR1_AWDCH: 看门狗监控的通道号选择位 */
  return (uint32_t)(READ_BIT(ADCx->CR1, (ADC_CR1_AWDEN | ADC_CR1_JAWDEN | ADC_CR1_AWDSGL | ADC_CR1_AWDCH)));
}

/**
  * @brief  设置ADC模拟看门狗的高或低阈值。
  * @note   在此STM32系列上，只有1种模拟看门狗实例:
  *         - AWD 标准 (实例 AWD1):
  *           - 监控通道: 可以监控1个通道或所有通道。
  *           - 监控组: ADC 规则组和/或注入组。
  *           - 分辨率: 分辨率不受限制 (对应于配置的ADC分辨率)。
  * @rmtoll HTR      HT             LL_ADC_SetAnalogWDThresholds\n
  *         LTR      LT             LL_ADC_SetAnalogWDThresholds
  * @param  ADCx ADC实例
  * @param  AWDThresholdsHighLow 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_THRESHOLD_HIGH (高阈值)
  *         @arg @ref LL_ADC_AWD_THRESHOLD_LOW (低阈值)
  * @param  AWDThresholdValue: 阈值数值，范围 Min_Data=0x000 到 Max_Data=0xFFF (12位)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDThresholdsHighLow, uint32_t AWDThresholdValue)
{
  /* 根据参数AWDThresholdsHighLow计算寄存器偏移量，获取对应寄存器指针(HTR或LTR) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->HTR, AWDThresholdsHighLow);
  
  /* 修改阈值寄存器的值，保留其他位不变 */
  /* ADC_HTR_HT 是高阈值寄存器中的阈值位掩码 */
  MODIFY_REG(*preg,
             ADC_HTR_HT,
             AWDThresholdValue);
}

/**
  * @brief  获取ADC模拟看门狗的高阈值或低阈值。
  * @note   如果ADC分辨率不是12位，模拟看门狗阈值数据需要特定的移位。
  *         使用辅助宏 @ref __LL_ADC_ANALOGWD_GET_THRESHOLD_RESOLUTION()。
  * @rmtoll HTR      HT             LL_ADC_GetAnalogWDThresholds\n
  *         LTR      LT             LL_ADC_GetAnalogWDThresholds
  * @param  ADCx ADC实例
  * @param  AWDThresholdsHighLow 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_AWD_THRESHOLD_HIGH (高阈值)
  *         @arg @ref LL_ADC_AWD_THRESHOLD_LOW (低阈值)
  * @retval 数值范围 Min_Data=0x000 到 Max_Data=0xFFF
*/
__STATIC_INLINE uint32_t LL_ADC_GetAnalogWDThresholds(ADC_TypeDef *ADCx, uint32_t AWDThresholdsHighLow)
{
  /* 根据参数AWDThresholdsHighLow计算寄存器偏移量，获取对应寄存器指针(HTR或LTR) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->HTR, AWDThresholdsHighLow);
  
  /* 读取并返回阈值寄存器中的数值 */
  return (uint32_t)(READ_BIT(*preg, ADC_HTR_HT));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Multimode ADC层级范围配置：多模模式
  * @{
  */

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  设置ADC多模配置，使其工作在独立模式或多模模式（适用于有多个ADC实例的设备）。
  * @note   如果配置为多模模式：选定的ADC实例根据硬件决定是主ADC还是从ADC。
  *         请参考参考手册。
  * @rmtoll CR1      DUALMOD        LL_ADC_SetMultimode
  * @param  ADCxy_COMMON ADC公共实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  Multimode 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_INDEPENDENT             (独立模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIMULT         (双ADC规则同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_FAST    (双ADC规则快速交替采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_SLOW    (双ADC规则慢速交替采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_SIMULT         (双ADC注入同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_ALTERN         (双ADC注入交替触发模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM    (双ADC规则同时采样 + 注入同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT    (双ADC规则同时采样 + 注入交替触发模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM(双ADC规则快速交替 + 注入同时采样模式)
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM(双ADC规则慢速交替 + 注入同时采样模式)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetMultimode(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t Multimode)
{
  /* 修改公共控制寄存器CR1中的DUALMOD位，设置多模模式 */
  MODIFY_REG(ADCxy_COMMON->CR1, ADC_CR1_DUALMOD, Multimode);
}

/**
  * @brief  获取ADC多模配置，当前是工作在独立模式还是多模模式（适用于有多个ADC实例的设备）。
  * @note   如果配置为多模模式：选定的ADC实例根据硬件决定是主ADC还是从ADC。
  *         请参考参考手册。
  * @rmtoll CR1      DUALMOD        LL_ADC_GetMultimode
  * @param  ADCxy_COMMON ADC公共实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_INDEPENDENT
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_FAST    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTERL_SLOW    
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_SIMULT         
  *         @arg @ref LL_ADC_MULTI_DUAL_INJ_ALTERN         
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT    
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM
  *         @arg @ref LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM
  */
__STATIC_INLINE uint32_t LL_ADC_GetMultimode(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 读取并返回公共控制寄存器CR1中的DUALMOD位 */
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CR1, ADC_CR1_DUALMOD));
}

#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */
/** @defgroup ADC_LL_EF_Operation_ADC_Instance ADC层级范围操作：ADC实例
  * @{
  */

/**
  * @brief  使能选定的ADC实例。
  * @note   在此STM32系列上，ADC使能后，需要等待一段时间用于ADC内部模拟电路稳定，
  *         才能开始ADC转换。请参考数据手册中的参数 tSTAB。
  * @rmtoll CR2      ADON           LL_ADC_Enable
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_Enable(ADC_TypeDef *ADCx)
{
  /* 设置CR2寄存器中的ADON位来使能ADC */
  SET_BIT(ADCx->CR2, ADC_CR2_ADON);
}

/**
  * @brief  关闭选定的ADC实例。
  * @rmtoll CR2      ADON           LL_ADC_Disable
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_Disable(ADC_TypeDef *ADCx)
{
  /* 清除CR2寄存器中的ADON位来关闭ADC */
  CLEAR_BIT(ADCx->CR2, ADC_CR2_ADON);
}

/**
  * @brief  获取选定ADC实例的使能状态。
  * @rmtoll CR2      ADON           LL_ADC_IsEnabled
  * @param  ADCx ADC实例
  * @retval 0: ADC已关闭, 1: ADC已使能。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabled(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的ADON位，判断ADC是否已使能 */
  return (READ_BIT(ADCx->CR2, ADC_CR2_ADON) == (ADC_CR2_ADON));
}

/**
  * @brief  启动ADC校准，模式为单端输入或差分输入（适用于支持差分模式的设备）。
  * @note   在此STM32系列上，启动校准之前，ADC必须处于关闭状态。
  *         在ADC关闭状态和校准开始之间需要最少数量的ADC时钟周期。
  *         请参考宏 @ref LL_ADC_DELAY_DISABLE_CALIB_ADC_CYCLES。
  * @note   在此STM32系列上，启动校准的硬件前提：
            ADC必须已上电至少两个ADC时钟周期。
  * @rmtoll CR2      CAL            LL_ADC_StartCalibration
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_StartCalibration(ADC_TypeDef *ADCx)
{
  /* 设置CR2寄存器中的CAL位启动校准 */
  SET_BIT(ADCx->CR2, ADC_CR2_CAL);
}

/**
  * @brief  获取ADC校准状态。
  * @rmtoll CR2      CAL            LL_ADC_IsCalibrationOnGoing
  * @param  ADCx ADC实例
  * @retval 0: 校准完成, 1: 校准正在进行中。
  */
__STATIC_INLINE uint32_t LL_ADC_IsCalibrationOnGoing(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的CAL位，判断校准是否正在进行 */
  /* 硬件会在校准完成后自动清除该位 */
  return (READ_BIT(ADCx->CR2, ADC_CR2_CAL) == (ADC_CR2_CAL));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Operation_ADC_Group_Regular ADC层级范围操作：规则组
  * @{
  */

/**
  * @brief  启动ADC规则组转换。
  * @note   在此STM32系列上，此函数仅适用于内部触发（软件启动），不适用于外部触发：
  *         - 如果ADC触发源设置为软件启动，ADC转换会立即开始。
  *         - 如果ADC触发源设置为外部触发，ADC转换启动必须使用函数
  *           @ref LL_ADC_REG_StartConversionExtTrig()。
  *           (如果在外部触发边沿设置期间ADC已使能，ADC转换将在触发事件发生时开始)。
  * @rmtoll CR2      SWSTART        LL_ADC_REG_StartConversionSWStart
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_StartConversionSWStart(ADC_TypeDef *ADCx)
{
  /* 设置SWSTART位启动软件触发转换，同时设置EXTTRIG位使能外部触发转换逻辑 */
  /* 注意：此处同时设置了SWSTART和EXTTRIG，是为了确保在软件触发模式下硬件逻辑正确响应 */
  SET_BIT(ADCx->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
}

/**
  * @brief  通过外部触发启动ADC规则组转换。
  * @note   ADC转换将在ADC启动转换命令之后的下一个触发事件（在选定的触发边沿）开始。
  * @note   在此STM32系列上，此函数适用于从外部触发启动ADC转换。
  *         如果需要内部触发（软件启动），请使用函数 @ref LL_ADC_REG_StartConversionSWStart()。
  * @rmtoll CR2      EXTEN          LL_ADC_REG_StartConversionExtTrig
  * @param  ExternalTriggerEdge 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_REG_TRIG_EXT_RISING (上升沿触发)
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_StartConversionExtTrig(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  /* 设置外部触发边沿控制位，使能外部触发转换 */
  SET_BIT(ADCx->CR2, ExternalTriggerEdge);
}

/**
  * @brief  停止ADC规则组的外部触发转换。
  * @note   在ADC停止转换命令之后，下一个触发事件将不再启动ADC转换。
  *         如果转换正在进行中，它将被完成。
  * @note   在此STM32系列上，没有特定的命令来停止正在进行的转换或停止连续转换模式下的ADC。
  *         这些操作可以通过函数 @ref LL_ADC_Disable() 执行。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_StopConversionExtTrig
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_StopConversionExtTrig(ADC_TypeDef *ADCx)
{
  /* 清除外部触发使能位，禁止外部触发信号启动转换 */
  CLEAR_BIT(ADCx->CR2, ADC_CR2_EXTTRIG);
}

/**
  * @brief  获取ADC规则组转换数据，范围适用于所有ADC配置：所有ADC分辨率和
  *         所有过采样增加的数据宽度（适用于有过采样功能的设备）。
  * @rmtoll DR       RDATA          LL_ADC_REG_ReadConversionData32
  * @param  ADCx ADC实例
  * @retval 数值范围 Min_Data=0x00000000 到 Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_REG_ReadConversionData32(ADC_TypeDef *ADCx)
{
  /* 读取数据寄存器DR的值，掩码提取数据部分 */
  /* 虽然返回值是uint32_t，但这里强制转换为uint16_t再返回是为了兼容旧代码或硬件行为，
     实际上对于过采样可能需要更多位，但此函数读取的是ADC_DR寄存器 */
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_DATA));
}

/**
  * @brief  获取ADC规则组转换数据，范围适用于12位分辨率。
  * @note   对于具有过采样功能的设备：过采样会增加数据宽度，
  *         可能需要扩展范围的函数: @ref LL_ADC_REG_ReadConversionData32。
  * @rmtoll DR       RDATA          LL_ADC_REG_ReadConversionData12
  * @param  ADCx ADC实例
  * @retval 数值范围 Min_Data=0x000 到 Max_Data=0xFFF
  */
__STATIC_INLINE uint16_t LL_ADC_REG_ReadConversionData12(ADC_TypeDef *ADCx)
{
  /* 读取数据寄存器DR的值，返回12位数据 */
  return (uint16_t)(READ_BIT(ADCx->DR, ADC_DR_DATA));
}

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  获取ADC多模转换数据，可以是主ADC数据、从ADC数据或主从拼接的原始数据。
  * @note   如果获取的是主从拼接的原始数据，可以使用宏来获取主ADC或从ADC的转换数据:
  *         参考辅助宏 @ref __LL_ADC_MULTI_CONV_DATA_MASTER_SLAVE()。
  *         (然而这个宏主要用于DMA传输的多模模式，因为此函数可以分别获取主从ADC的数据)。
  * @rmtoll DR       DATA           LL_ADC_REG_ReadMultiConversionData32\n
  *         DR       ADC2DATA       LL_ADC_REG_ReadMultiConversionData32
  * @param  ADCx ADC实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  ConversionData 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_MULTI_MASTER        (主ADC数据)
  *         @arg @ref LL_ADC_MULTI_SLAVE         (从ADC数据)
  *         @arg @ref LL_ADC_MULTI_MASTER_SLAVE  (主从拼接数据)
  * @retval 数值范围 Min_Data=0x00000000 到 Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_REG_ReadMultiConversionData32(ADC_TypeDef *ADCx, uint32_t ConversionData)
{
  /* 读取DR寄存器，根据ConversionData参数进行移位操作以获取对应的数据 */
  /* 在多模模式下，DR寄存器包含主从ADC的数据，通过移位提取 */
  return (uint32_t)(READ_BIT(ADCx->DR,
                             ADC_DR_ADC2DATA)
                    >> POSITION_VAL(ConversionData)
                   );
}
#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Operation_ADC_Group_Injected ADC层级范围操作：注入组
  * @{
  */

/**
  * @brief  启动ADC注入组转换。
  * @note   在此STM32系列上，此函数仅适用于内部触发（软件启动），不适用于外部触发：
  *         - 如果ADC触发源设置为软件启动，ADC转换会立即开始。
  *         - 如果ADC触发源设置为外部触发，ADC转换启动必须使用函数
  *           @ref LL_ADC_INJ_StartConversionExtTrig()。
  *           (如果在外部触发边沿设置期间ADC已使能，ADC转换将在触发事件发生时开始)。
  * @rmtoll CR2      JSWSTART       LL_ADC_INJ_StartConversionSWStart
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_StartConversionSWStart(ADC_TypeDef *ADCx)
{
  /* 设置JSWSTART位启动注入组软件触发转换，同时设置JEXTTRIG位使能注入组外部触发逻辑 */
  SET_BIT(ADCx->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
}

/**
  * @brief  通过外部触发启动ADC注入组转换。
  * @note   ADC转换将在ADC启动转换命令之后的下一个触发事件（在选定的触发边沿）开始。
  * @note   在此STM32系列上，此函数适用于从外部触发启动ADC注入组转换。
  *         如果需要内部触发（软件启动），请使用函数 @ref LL_ADC_INJ_StartConversionSWStart()。
  * @rmtoll CR2      JEXTEN         LL_ADC_INJ_StartConversionExtTrig
  * @param  ExternalTriggerEdge 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_RISING (上升沿触发)
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_StartConversionExtTrig(ADC_TypeDef *ADCx, uint32_t ExternalTriggerEdge)
{
  /* 设置注入组外部触发边沿控制位，使能外部触发转换 */
  SET_BIT(ADCx->CR2, ExternalTriggerEdge);
}
