/**
  * @brief  设置ADC常规组序列器的长度和扫描方向。
  * @note   ADC常规组序列器功能描述：
  *         - 对于序列器完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerRanks()" 可用):
  *           序列器长度和每个排名对应的通道
  *           都是可配置的。
  *           此函数执行以下配置：
  *           - 序列长度：扫描序列中的排名数量。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从排名1到排名n)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerRanks()"。
  *         - 对于序列器不完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerChannels()" 可用):
  *           序列器长度和每个排名对应的通道
  *           由通道编号定义。
  *           此函数执行以下配置：
  *           - 序列长度：扫描序列中的排名数量由
  *             序列中设置的通道数量定义，
  *             每个通道的排名由硬件通道号固定。
  *             (通道0固定在排名0，通道1固定在排名1，...)。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从最低通道号到
  *             最高通道号)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerChannels()"。
  * @note   在此STM32系列上，常规组序列器配置
  *         取决于ADC实例的序列器模式。
  *         如果ADC实例序列器模式被禁用，则
  *         所有组(常规组、注入组)的序列器可以被配置
  *         但其执行被禁用(仅限于排名1)。
  *         参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器等同于1个排名的序列器：
  *         仅在1个通道上进行ADC转换。
  * @rmtoll SQR1     L              LL_ADC_REG_SetSequencerLength
  * @param  ADCx ADC实例
  * @param  SequencerNbRanks 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  /* 修改ADCx->SQR1寄存器的L位，设置常规组序列器的转换通道数量 */
  MODIFY_REG(ADCx->SQR1, ADC_SQR1_L, SequencerNbRanks);
}

/**
  * @brief  获取ADC常规组序列器的长度和扫描方向。
  * @note   ADC常规组序列器功能描述：
  *         - 对于序列器完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerRanks()" 可用):
  *           序列器长度和每个排名对应的通道
  *           都是可配置的。
  *           此函数检索：
  *           - 序列长度：扫描序列中的排名数量。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从排名1到排名n)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerRanks()"。
  *         - 对于序列器不完全可配置的设备
  *           (函数 "LL_ADC_REG_SetSequencerChannels()" 可用):
  *           序列器长度和每个排名对应的通道
  *           由通道编号定义。
  *           此函数检索：
  *           - 序列长度：扫描序列中的排名数量由
  *             序列中设置的通道数量定义，
  *             每个通道的排名由硬件通道号固定。
  *             (通道0固定在排名0，通道1固定在排名1，...)。
  *           - 序列方向：除非参数中指定，否则序列器
  *             扫描方向为正向(从最低通道号到
  *             最高通道号)。
  *           序列器排名选择使用
  *           函数 "LL_ADC_REG_SetSequencerChannels()"。
  * @note   在此STM32系列上，常规组序列器配置
  *         取决于ADC实例的序列器模式。
  *         如果ADC实例序列器模式被禁用，则
  *         所有组(常规组、注入组)的序列器可以被配置
  *         但其执行被禁用(仅限于排名1)。
  *         参考函数 @ref LL_ADC_SetSequencersScanMode()。
  * @note   禁用序列器等同于1个排名的序列器：
  *         仅在1个通道上进行ADC转换。
  * @rmtoll SQR1     L              LL_ADC_REG_SetSequencerLength
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS
  *         @arg @ref LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerLength(ADC_TypeDef *ADCx)
{
  /* 读取ADCx->SQR1寄存器的L位，获取常规组序列器的转换通道数量 */
  return (uint32_t)(READ_BIT(ADCx->SQR1, ADC_SQR1_L));
}

/**
  * @brief  设置ADC常规组序列器的不连续模式：
  *         序列被细分，每选定的排名数后扫描转换中断一次。
  * @note   不能同时启用ADC常规组连续模式和序列器不连续模式。
  * @note   不能同时启用ADC自动注入模式
  *         和ADC常规组序列器不连续模式。
  * @rmtoll CR1      DISCEN         LL_ADC_REG_SetSequencerDiscont\n
  *         CR1      DISCNUM        LL_ADC_REG_SetSequencerDiscont
  * @param  ADCx ADC实例
  * @param  SeqDiscont 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_1RANK
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_8RANKS
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  /* 修改ADCx->CR1寄存器，配置DISCEN(不连续模式使能)和DISCNUM(不连续模式通道数)位 */
  MODIFY_REG(ADCx->CR1, ADC_CR1_DISCEN | ADC_CR1_DISCNUM, SeqDiscont);
}

/**
  * @brief  获取ADC常规组序列器的不连续模式：
  *         序列被细分，每选定的排名数后扫描转换中断一次。
  * @rmtoll CR1      DISCEN         LL_ADC_REG_GetSequencerDiscont\n
  *         CR1      DISCNUM        LL_ADC_REG_GetSequencerDiscont
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_1RANK
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_2RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_3RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_4RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_5RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_6RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_7RANKS
  *         @arg @ref LL_ADC_REG_SEQ_DISCONT_8RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerDiscont(ADC_TypeDef *ADCx)
{
  /* 读取ADCx->CR1寄存器，获取不连续模式配置 */
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_DISCEN | ADC_CR1_DISCNUM));
}

/**
  * @brief  设置ADC常规组序列：选定扫描序列排名上的通道。
  * @note   此函数执行以下配置：
  *         - 通道在扫描序列每个排名中的排序：
  *           任何通道都可以放置在任何排名中。
  * @note   在此STM32系列上，ADC常规组序列器是
  *         完全可配置的：序列器长度和每个排名
  *         对应的通道都是可配置的。
  *         参考函数 @ref LL_ADC_REG_SetSequencerLength() 的描述。
  * @note   根据设备和封装，某些通道可能不可用。
  *         请参考设备数据手册了解通道可用性。
  * @note   在此STM32系列上，要测量内部通道(VrefInt,
  *         TempSensor, ...)，必须单独启用
  *         到内部通道的测量路径。
  *         这可以使用函数 @ref LL_ADC_SetCommonPathInternalCh() 完成。
  * @rmtoll SQR3     SQ1            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ2            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ3            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ4            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ5            LL_ADC_REG_SetSequencerRanks\n
  *         SQR3     SQ6            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ7            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ8            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ9            LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ10           LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ11           LL_ADC_REG_SetSequencerRanks\n
  *         SQR2     SQ12           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ13           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ14           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ15           LL_ADC_REG_SetSequencerRanks\n
  *         SQR1     SQ16           LL_ADC_REG_SetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_RANK_1
  *         @arg @ref LL_ADC_REG_RANK_2
  *         @arg @ref LL_ADC_REG_RANK_3
  *         @arg @ref LL_ADC_REG_RANK_4
  *         @arg @ref LL_ADC_REG_RANK_5
  *         @arg @ref LL_ADC_REG_RANK_6
  *         @arg @ref LL_ADC_REG_RANK_7
  *         @arg @ref LL_ADC_REG_RANK_8
  *         @arg @ref LL_ADC_REG_RANK_9
  *         @arg @ref LL_ADC_REG_RANK_10
  *         @arg @ref LL_ADC_REG_RANK_11
  *         @arg @ref LL_ADC_REG_RANK_12
  *         @arg @ref LL_ADC_REG_RANK_13
  *         @arg @ref LL_ADC_REG_RANK_14
  *         @arg @ref LL_ADC_REG_RANK_15
  *         @arg @ref LL_ADC_REG_RANK_16
  * @param  Channel 此参数可以是以下值之一：
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
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* 根据参数"Rank"在寄存器中的位置和寄存器位置设置参数"Channel"的内容。 */
  /* 参数"Rank"和"Channel"使用掩码，因为它们包含用于其他目的的保留位。 */
  
  /* 计算目标寄存器地址：根据Rank确定操作SQR1, SQR2还是SQR3寄存器 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, __ADC_MASK_SHIFT(Rank, ADC_REG_SQRX_REGOFFSET_MASK));
  
  /* 修改目标寄存器：将通道号写入到指定Rank对应的位域中 */
  MODIFY_REG(*preg,
             ADC_CHANNEL_ID_NUMBER_MASK << (Rank & ADC_REG_RANK_ID_SQRX_MASK),
             (Channel & ADC_CHANNEL_ID_NUMBER_MASK) << (Rank & ADC_REG_RANK_ID_SQRX_MASK));
}

/**
  * @brief  获取ADC常规组序列：选定扫描序列排名上的通道。
  * @note   在此STM32系列上，ADC常规组序列器是
  *         完全可配置的：序列器长度和每个排名
  *         对应的通道都是可配置的。
  *         参考函数 @ref LL_ADC_REG_SetSequencerLength() 的描述。
  * @note   根据设备和封装，某些通道可能不可用。
  *         请参考设备数据手册了解通道可用性。
  * @note   返回通道号的使用方法：
  *         - 要将此通道重新注入另一个函数LL_ADC_xxx中：
  *           返回的通道号仅在LL_ADC_CHANNEL_x字面量定义上部分格式化。
  *           因此，必须将其与LL_ADC_CHANNEL_x字面量的部分进行比较，
  *           或使用辅助宏 @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  *           然后选定的字面量LL_ADC_CHANNEL_x可以用作
  *           另一个函数的参数。
  *         - 要获取十进制格式的通道号：
  *           使用辅助宏处理返回值
  *           @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB()。
  * @rmtoll SQR3     SQ1            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ2            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ3            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ4            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ5            LL_ADC_REG_GetSequencerRanks\n
  *         SQR3     SQ6            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ7            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ8            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ9            LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ10           LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ11           LL_ADC_REG_GetSequencerRanks\n
  *         SQR2     SQ12           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ13           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ14           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ15           LL_ADC_REG_GetSequencerRanks\n
  *         SQR1     SQ16           LL_ADC_REG_GetSequencerRanks
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_RANK_1
  *         @arg @ref LL_ADC_REG_RANK_2
  *         @arg @ref LL_ADC_REG_RANK_3
  *         @arg @ref LL_ADC_REG_RANK_4
  *         @arg @ref LL_ADC_REG_RANK_5
  *         @arg @ref LL_ADC_REG_RANK_6
  *         @arg @ref LL_ADC_REG_RANK_7
  *         @arg @ref LL_ADC_REG_RANK_8
  *         @arg @ref LL_ADC_REG_RANK_9
  *         @arg @ref LL_ADC_REG_RANK_10
  *         @arg @ref LL_ADC_REG_RANK_11
  *         @arg @ref LL_ADC_REG_RANK_12
  *         @arg @ref LL_ADC_REG_RANK_13
  *         @arg @ref LL_ADC_REG_RANK_14
  *         @arg @ref LL_ADC_REG_RANK_15
  *         @arg @ref LL_ADC_REG_RANK_16
  * @retval 返回值可以是以下值之一：
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
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，
  *             与内部通道参数的比较应使用
  *             辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL()。
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank计算目标寄存器地址(SQR1, SQR2或SQR3) */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->SQR1, __ADC_MASK_SHIFT(Rank, ADC_REG_SQRX_REGOFFSET_MASK));
  
  /* 读取目标寄存器，提取指定Rank对应的通道号并右移对齐 */
  return (uint32_t) (READ_BIT(*preg,
                              ADC_CHANNEL_ID_NUMBER_MASK << (Rank & ADC_REG_RANK_ID_SQRX_MASK))
                     >> (Rank & ADC_REG_RANK_ID_SQRX_MASK)
                    );
}

/**
  * @brief  设置ADC常规组的连续转换模式。
  * @note   ADC连续转换模式描述：
  *         - 单次模式：每次触发进行一次转换
  *         - 连续模式：第一次触发后，随后的
  *           转换自动连续启动。
  * @note   不能同时启用ADC常规组连续模式和序列器不连续模式。
  * @rmtoll CR2      CONT           LL_ADC_REG_SetContinuousMode
  * @param  ADCx ADC实例
  * @param  Continuous 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_CONV_SINGLE
  *         @arg @ref LL_ADC_REG_CONV_CONTINUOUS
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetContinuousMode(ADC_TypeDef *ADCx, uint32_t Continuous)
{
  /* 修改ADCx->CR2寄存器的CONT位，设置单次转换或连续转换模式 */
  MODIFY_REG(ADCx->CR2, ADC_CR2_CONT, Continuous);
}

/**
  * @brief  获取ADC常规组的连续转换模式。
  * @note   ADC连续转换模式描述：
  *         - 单次模式：每次触发进行一次转换
  *         - 连续模式：第一次触发后，随后的
  *           转换自动连续启动。
  * @rmtoll CR2      CONT           LL_ADC_REG_GetContinuousMode
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_CONV_SINGLE
  *         @arg @ref LL_ADC_REG_CONV_CONTINUOUS
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetContinuousMode(ADC_TypeDef *ADCx)
{
  /* 读取ADCx->CR2寄存器的CONT位，获取当前转换模式配置 */
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_CONT));
}
