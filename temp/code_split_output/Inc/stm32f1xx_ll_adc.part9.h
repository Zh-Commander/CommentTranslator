/**
  * @brief  设置ADC常规组转换数据传输模式：无传输或DMA传输，以及DMA请求模式。
  * @note   如果选择了DMA传输，则指定DMA请求模式：
  *         - 有限模式(单次模式)：当达到DMA数据传输次数(ADC转换次数)时，
  *           DMA传输请求停止。此ADC模式旨在与DMA非循环模式配合使用。
  *         - 无限模式：DMA传输请求是无限的，无论DMA数据传输次数(ADC转换次数)如何。
  *           此ADC模式旨在与DMA循环模式配合使用。
  * @note   如果ADC DMA请求模式设置为无限模式，而DMA设置为非循环模式：
  *         当达到DMA传输大小时，DMA将停止传输ADC转换数据，
  *         ADC将引发溢出错误(如果使能了溢出标志和中断)。
  * @note   要配置DMA源地址(外设地址)，请使用函数 @ref LL_ADC_DMA_GetRegAddr()。
  * @rmtoll CR2      DMA            LL_ADC_REG_SetDMATransfer
  * @param  ADCx ADC实例
  * @param  DMATransfer 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_NONE    // 不使用DMA传输
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_UNLIMITED // 使用DMA传输(无限模式)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetDMATransfer(ADC_TypeDef *ADCx, uint32_t DMATransfer)
{
  // 修改ADCx->CR2寄存器中的DMA位，设置为参数指定的DMA传输模式
  MODIFY_REG(ADCx->CR2, ADC_CR2_DMA, DMATransfer);
}

/**
  * @brief  获取ADC常规组转换数据传输模式：无传输或DMA传输，以及DMA请求模式。
  * @note   如果选择了DMA传输，则指定DMA请求模式：
  *         - 有限模式(单次模式)：当达到DMA数据传输次数(ADC转换次数)时，
  *           DMA传输请求停止。此ADC模式旨在与DMA非循环模式配合使用。
  *         - 无限模式：DMA传输请求是无限的，无论DMA数据传输次数(ADC转换次数)如何。
  *           此ADC模式旨在与DMA循环模式配合使用。
  * @note   如果ADC DMA请求模式设置为无限模式，而DMA设置为非循环模式：
  *         当达到DMA传输大小时，DMA将停止传输ADC转换数据，
  *         ADC将引发溢出错误(如果使能了溢出标志和中断)。
  * @note   要配置DMA源地址(外设地址)，请使用函数 @ref LL_ADC_DMA_GetRegAddr()。
  * @rmtoll CR2      DMA            LL_ADC_REG_GetDMATransfer
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_NONE
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_UNLIMITED
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetDMATransfer(ADC_TypeDef *ADCx)
{
  // 读取ADCx->CR2寄存器中的DMA位，并返回当前的DMA传输配置
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_DMA));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Group_Injected ADC层级范围配置：注入组
  * @{
  */

/**
  * @brief  设置ADC注入组转换触发源：内部(软件启动)或来自外部IP(定时器事件，外部中断线)。
  * @note   在此STM32系列上，外部触发设置为上升沿触发极性(此STM32系列上唯一可用的触发极性)。
  * @note   来自定时器的触发源参数可用性取决于所选设备上定时器的可用性。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_SetTriggerSource
  * @param  ADCx ADC实例
  * @param  TriggerSource 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_SOFTWARE          // 软件触发
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_TRGO     (1) // TIM1 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_CH4      (1) // TIM1通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_TRGO     (2) // TIM2 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_CH1      (2) // TIM2通道1
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM3_CH4      (2) // TIM3通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_TRGO     (2) // TIM4 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_EXTI_LINE15   (2) // 外部中断线15
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (2)(4) // TIM8通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3 (3) // TIM8通道4(ADC3专用)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_CH3      (3) // TIM4通道3
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH2      (3) // TIM8通道2
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (3) // TIM8通道4
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_TRGO     (3) // TIM5 TRGO事件
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_CH4      (3) // TIM5通道4
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1、ADC2、ADC3。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1、ADC2。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度设备。必须在顶层完成触发重映射(参考AFIO外设)。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
/* 注意：在此STM32系列上，ADC注入组外部触发边沿用于执行ADC转换启动。       */
/*       此函数不设置外部触发边沿。                                          */
/*       此功能使用函数 @ref LL_ADC_INJ_StartConversionExtTrig() 设置。       */
  // 修改ADCx->CR2寄存器的JEXTSEL位，设置注入组触发源
  // TriggerSource & ADC_CR2_JEXTSEL 用于确保只写入有效的位
  MODIFY_REG(ADCx->CR2, ADC_CR2_JEXTSEL, (TriggerSource & ADC_CR2_JEXTSEL));
}

/**
  * @brief  获取ADC注入组转换触发源：内部(软件启动)或来自外部IP(定时器事件，外部中断线)。
  * @note   要确定注入组触发源是内部(软件启动)还是外部，而不详细说明选择了哪个外设作为外部触发，
  *         (相当于 "if(LL_ADC_INJ_GetTriggerSource(ADC1) == LL_ADC_INJ_TRIG_SOFTWARE)")
  *         请使用函数 @ref LL_ADC_INJ_IsTriggerSourceSWStart。
  * @note   来自定时器的触发源参数可用性取决于所选设备上定时器的可用性。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_GetTriggerSource
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_TRGO     (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_CH4      (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_CH1      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM3_CH4      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_EXTI_LINE15   (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (2)(4)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3 (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_CH3      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH2      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_TRGO     (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_CH4      (3)
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1、ADC2、ADC3。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1、ADC2。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度设备。必须在顶层完成触发重映射(参考AFIO外设)。
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTriggerSource(ADC_TypeDef *ADCx)
{
  // 读取ADCx->CR2寄存器中的JEXTSEL位，返回当前的触发源配置
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_JEXTSEL));
}

/**
  * @brief  获取ADC注入组转换触发源是内部(软件启动)还是外部
  * @note   如果注入组触发源设置为外部触发，要确定选择了哪个外设作为外部触发，
  *         请使用函数 @ref LL_ADC_INJ_GetTriggerSource。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_IsTriggerSourceSWStart
  * @param  ADCx ADC实例
  * @retval 值 "0" 表示触发源为外部触发
  *         值 "1" 表示触发源为软件启动。
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  // 判断CR2寄存器中的JEXTSEL位是否等于LL_ADC_INJ_TRIG_SOFTWARE
  return (READ_BIT(ADCx->CR2, ADC_CR2_JEXTSEL) == LL_ADC_INJ_TRIG_SOFTWARE);
}

/**
  * @brief  设置ADC注入组序列器长度和扫描方向。
  * @note   此函数执行以下配置：
  *         - 序列长度：扫描序列中的排名数量。
  *         - 序列方向：除非参数中指定，否则序列器扫描方向为正向(从排名1到排名n)。
  * @note   在此STM32系列上，注入组序列器配置取决于ADC实例序列器模式。
  *         如果禁用了ADC实例序列器模式，则所有组(常规组、注入组)的序列器可以配置，
  *         但其执行被禁用(仅限于排名1)。
  *         请参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器相当于1个排名的序列器：ADC仅在1个通道上转换。
  * @rmtoll JSQR     JL             LL_ADC_INJ_SetSequencerLength
  * @param  ADCx ADC实例
  * @param  SequencerNbRanks 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_DISABLE      // 禁用扫描(1个通道)
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS // 启用扫描(2个通道)
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS // 启用扫描(3个通道)
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS // 启用扫描(4个通道)
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  // 修改ADCx->JSQR寄存器中的JL位，设置注入序列器的转换通道数量
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JL, SequencerNbRanks);
}

/**
  * @brief  获取ADC注入组序列器长度和扫描方向。
  * @note   此函数检索：
  *         - 序列长度：扫描序列中的排名数量。
  *         - 序列方向：除非参数中指定，否则序列器扫描方向为正向(从排名1到排名n)。
  * @note   在此STM32系列上，注入组序列器配置取决于ADC实例序列器模式。
  *         如果禁用了ADC实例序列器模式，则所有组(常规组、注入组)的序列器可以配置，
  *         但其执行被禁用(仅限于排名1)。
  *         请参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器相当于1个排名的序列器：ADC仅在1个通道上转换。
  * @rmtoll JSQR     JL             LL_ADC_INJ_GetSequencerLength
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerLength(ADC_TypeDef *ADCx)
{
  // 读取ADCx->JSQR寄存器中的JL位，返回当前注入序列器的长度配置
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JL));
}

/**
  * @brief  设置ADC注入组序列器不连续模式：序列细分，每选定的排名数中断扫描转换。
  * @note   无法同时启用ADC注入组自动注入模式和序列器不连续模式。
  * @rmtoll CR1      DISCEN         LL_ADC_INJ_SetSequencerDiscont
  * @param  ADCx ADC实例
  * @param  SeqDiscont 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_DISABLE  // 禁用不连续模式
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_1RANK    // 启用不连续模式，每次转换1个通道
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  // 修改ADCx->CR1寄存器中的JDISCEN位，配置注入序列器的不连续模式
  MODIFY_REG(ADCx->CR1, ADC_CR1_JDISCEN, SeqDiscont);
}

/**
  * @brief  获取ADC注入组序列器不连续模式：序列细分，每选定的排名数中断扫描转换。
  * @rmtoll CR1      DISCEN         LL_ADC_REG_GetSequencerDiscont
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_1RANK
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerDiscont(ADC_TypeDef *ADCx)
{
  // 读取ADCx->CR1寄存器中的JDISCEN位，返回当前不连续模式的配置
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_JDISCEN));
}

/**
  * @brief  设置ADC注入组序列：选定序列排名上的通道。
  * @note   根据设备和封装，某些通道可能不可用。有关通道可用性，请参考设备数据手册。
  * @note   在此STM32系列上，要测量内部通道(VrefInt，温度传感器等)，
  *         必须单独启用到内部通道的测量路径。
  *         这可以使用函数 @ref LL_ADC_SetCommonPathInternalCh() 完成。
  * @rmtoll JSQR     JSQ1           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ2           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ3           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ4           LL_ADC_INJ_SetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1  // 注入组序列排名1
  *         @arg @ref LL_ADC_INJ_RANK_2  // 注入组序列排名2
  *         @arg @ref LL_ADC_INJ_RANK_3  // 注入组序列排名3
  *         @arg @ref LL_ADC_INJ_RANK_4  // 注入组序列排名4
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
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1) // 内部参考电压通道
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1) // 温度传感器通道
  *         
  *         (1) 在STM32F1上，参数仅适用于ADC实例：ADC1。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* 根据参数"Rank"在寄存器中的位置，设置参数"Channel"的内容位。          */
  /* 参数"Rank"和"Channel"使用掩码，因为它们包含用于其他目的的保留位。       */
  
  // 读取当前JSQR寄存器中的JL位(注入序列长度)，并计算出实际的转换数量(+1)
  uint32_t tmpreg1 = (READ_BIT(ADCx->JSQR, ADC_JSQR_JL) >> ADC_JSQR_JL_Pos) + 1U;
  
  // 修改ADCx->JSQR寄存器
  // ADC注入序列器的JSQx位置是动态计算的，取决于序列长度(JL)和当前排名
  // 公式: 5U * (uint8_t)(((Rank) + 3U) - (tmpreg1)) 用于计算移位位数
  MODIFY_REG(ADCx->JSQR,
             ADC_CHANNEL_ID_NUMBER_MASK << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))),
             (Channel & ADC_CHANNEL_ID_NUMBER_MASK) << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))));
}

/**
  * @brief  获取ADC注入组序列：选定序列排名上的通道。
  * @note   根据设备和封装，某些通道可能不可用。有关通道可用性，请参考设备数据手册。
  * @note   返回通道号的使用方法：
  *         - 要将此通道重新注入到另一个函数LL_ADC_xxx中：
  *           返回的通道号仅在LL_ADC_CHANNEL_x文字的定义上部分格式化。
  *           因此，必须将其与LL_ADC_CHANNEL_x文字的部分进行比较，或使用
  *           辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  *           然后可以将选定的文字LL_ADC_CHANNEL_x用作另一个函数的参数。
  *         - 要获取十进制格式的通道号：
  *           使用辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB() 处理返回值。
  * @rmtoll JSQR     JSQ1           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ2           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ3           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ4           LL_ADC_INJ_SetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval 返回值可以是以下值之一:
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
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅适用于ADC实例：ADC1。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，与内部通道参数的比较应
  *             使用辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL() 进行。
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank)
{
  // 读取当前JSQR寄存器中的JL位(注入序列长度)，并计算出实际的转换数量(+1)
  uint32_t tmpreg1 = (READ_BIT(ADCx->JSQR, ADC_JSQR_JL) >> ADC_JSQR_JL_Pos)  + 1U;
  
  // 读取JSQR寄存器中对应Rank的通道编号
  // 计算移位位数，提取对应的JSQx字段，并右移对齐
  return (uint32_t)(READ_BIT(ADCx->JSQR,
                             ADC_CHANNEL_ID_NUMBER_MASK << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))))
                    >> (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1)))
                   );
}
