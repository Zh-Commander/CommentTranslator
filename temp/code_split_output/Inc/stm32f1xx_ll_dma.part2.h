/**
  * @brief  获取DMA通道优先级等级。
  * @rmtoll CCR          PL            LL_DMA_GetChannelPriorityLevel
  * @param  DMAx DMAx实例指针，指向DMA控制器基地址
  * @param  Channel 通道号，该参数可以是以下值之一：
  *         @arg @ref LL_DMA_CHANNEL_1 (通道1)
  *         @arg @ref LL_DMA_CHANNEL_2 (通道2)
  *         @arg @ref LL_DMA_CHANNEL_3 (通道3)
  *         @arg @ref LL_DMA_CHANNEL_4 (通道4)
  *         @arg @ref LL_DMA_CHANNEL_5 (通道5)
  *         @arg @ref LL_DMA_CHANNEL_6 (通道6)
  *         @arg @ref LL_DMA_CHANNEL_7 (通道7)
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_DMA_PRIORITY_LOW (低优先级)
  *         @arg @ref LL_DMA_PRIORITY_MEDIUM (中优先级)
  *         @arg @ref LL_DMA_PRIORITY_HIGH (高优先级)
  *         @arg @ref LL_DMA_PRIORITY_VERYHIGH (极高优先级)
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 
     1. (Channel - 1U): 通道号减1，因为数组索引从0开始
     2. CHANNEL_OFFSET_TAB[...]: 查表获取该通道寄存器的地址偏移量
     3. (uint32_t)DMAx + ...: 基地址加上偏移量，计算出具体通道的寄存器组地址
     4. 强制转换为 (DMA_Channel_TypeDef *) 指针
     5. READ_BIT: 读取CCR寄存器中的PL位域（优先级配置位）
  */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_PL));
}

/**
  * @brief  设置要传输的数据长度（数量）。
  * @note   如果通道已使能，此操作无效。
  *         必须在DMA通道禁用状态下配置。
  * @rmtoll CNDTR        NDT           LL_DMA_SetDataLength
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  NbData 要传输的数据量，范围：Min_Data = 0 到 Max_Data = 0x0000FFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetDataLength(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t NbData)
{
  /* 
     配置CNDTR寄存器中的NDT位域。
     CNDTR寄存器保存当前还需要传输的数据数目。
     MODIFY_REG宏用于修改寄存器的部分位，不影响其他位。
  */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CNDTR,
             DMA_CNDTR_NDT, NbData);
}

/**
  * @brief  获取剩余待传输的数据长度。
  * @note   一旦通道使能，返回值表示剩余待传输的字节数。
  *         随着传输进行，该值会递减。
  * @rmtoll CNDTR        NDT           LL_DMA_GetDataLength
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回剩余数据长度，范围：Min_Data = 0 到 Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetDataLength(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CNDTR寄存器中的NDT位域，获取当前剩余传输数据量 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CNDTR,
                   DMA_CNDTR_NDT));
}

/**
  * @brief  配置源地址和目标地址。
  * @note   当DMA通道使能时，禁止调用此API。
  * @note   使用DMA的外设通常会提供API直接获取寄存器地址 (LL_PPP_DMA_GetRegAddr)。
  * @rmtoll CPAR         PA            LL_DMA_ConfigAddresses\n
  *         CMAR         MA            LL_DMA_ConfigAddresses
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  SrcAddress 源地址，范围：0 到 0xFFFFFFFF
  * @param  DstAddress 目标地址，范围：0 到 0xFFFFFFFF
  * @param  Direction 传输方向，该参数可以是以下值之一：
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY (外设到内存)
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH (内存到外设)
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY (内存到内存)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ConfigAddresses(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress,
                                            uint32_t DstAddress, uint32_t Direction)
{
  /* 方向：内存到外设 */
  if (Direction == LL_DMA_DIRECTION_MEMORY_TO_PERIPH)
  {
    /* 源是内存，写入CMAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, SrcAddress);
    /* 目标是外设，写入CPAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, DstAddress);
  }
  /* 方向：外设到内存 或 内存到内存 */
  else
  {
    /* 源是外设(或内存)，写入CPAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, SrcAddress);
    /* 目标是内存，写入CMAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, DstAddress);
  }
}

/**
  * @brief  设置内存地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CMAR         MA            LL_DMA_SetMemoryAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  MemoryAddress 内存地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetMemoryAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  /* 将地址写入CMAR（DMA通道内存地址寄存器） */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, MemoryAddress);
}

/**
  * @brief  设置外设地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CPAR         PA            LL_DMA_SetPeriphAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  PeriphAddress 外设地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetPeriphAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphAddress)
{
  /* 将地址写入CPAR（DMA通道外设地址寄存器） */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, PeriphAddress);
}

/**
  * @brief  获取内存地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @rmtoll CMAR         MA            LL_DMA_GetMemoryAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回内存地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetMemoryAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CMAR寄存器的值 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR));
}

/**
  * @brief  获取外设地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @rmtoll CPAR         PA            LL_DMA_GetPeriphAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回外设地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetPeriphAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CPAR寄存器的值 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR));
}

/**
  * @brief  设置内存到内存模式的源地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CPAR         PA            LL_DMA_SetM2MSrcAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  MemoryAddress 内存地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetM2MSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  /* 在M2M模式下，CPAR寄存器被用作源地址 */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, MemoryAddress);
}

/**
  * @brief  设置内存到内存模式的目标地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CMAR         MA            LL_DMA_SetM2MDstAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  MemoryAddress 内存地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetM2MDstAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  /* 在M2M模式下，CMAR寄存器被用作目标地址 */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, MemoryAddress);
}

/**
  * @brief  获取内存到内存模式的源地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @rmtoll CPAR         PA            LL_DMA_GetM2MSrcAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回源地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetM2MSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CPAR寄存器，作为M2M模式的源地址 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR));
}

/**
  * @brief  获取内存到内存模式的目标地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @rmtoll CMAR         MA            LL_DMA_GetM2MDstAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回目标地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetM2MDstAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CMAR寄存器，作为M2M模式的目标地址 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR));
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_FLAG_Management 标志位管理
  * @{
  */

/**
  * @brief  获取通道1的全局中断标志。
  * @rmtoll ISR          GIF1          LL_DMA_IsActiveFlag_GI1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI1(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF1位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF1) == (DMA_ISR_GIF1));
}

/**
  * @brief  获取通道2的全局中断标志。
  * @rmtoll ISR          GIF2          LL_DMA_IsActiveFlag_GI2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI2(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF2位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF2) == (DMA_ISR_GIF2));
}

/**
  * @brief  获取通道3的全局中断标志。
  * @rmtoll ISR          GIF3          LL_DMA_IsActiveFlag_GI3
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI3(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF3位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF3) == (DMA_ISR_GIF3));
}

/**
  * @brief  获取通道4的全局中断标志。
  * @rmtoll ISR          GIF4          LL_DMA_IsActiveFlag_GI4
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI4(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF4位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF4) == (DMA_ISR_GIF4));
}

/**
  * @brief  获取通道5的全局中断标志。
  * @rmtoll ISR          GIF5          LL_DMA_IsActiveFlag_GI5
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI5(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF5位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF5) == (DMA_ISR_GIF5));
}

/**
  * @brief  获取通道6的全局中断标志。
  * @rmtoll ISR          GIF6          LL_DMA_IsActiveFlag_GI6
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI6(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF6位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF6) == (DMA_ISR_GIF6));
}

/**
  * @brief  获取通道7的全局中断标志。
  * @rmtoll ISR          GIF7          LL_DMA_IsActiveFlag_GI7
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI7(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF7位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF7) == (DMA_ISR_GIF7));
}

/**
  * @brief  获取通道1的传输完成标志。
  * @rmtoll ISR          TCIF1         LL_DMA_IsActiveFlag_TC1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC1(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF1位，判断通道1是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF1) == (DMA_ISR_TCIF1));
}

/**
  * @brief  获取通道2的传输完成标志。
  * @rmtoll ISR          TCIF2         LL_DMA_IsActiveFlag_TC2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC2(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF2位，判断通道2是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF2) == (DMA_ISR_TCIF2));
}

/**
  * @brief  获取通道3的传输完成标志。
  * @rmtoll ISR          TCIF3         LL_DMA_IsActiveFlag_TC3
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC3(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF3位，判断通道3是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF3) == (DMA_ISR_TCIF3));
}

/**
  * @brief  获取通道4的传输完成标志。
  * @rmtoll ISR          TCIF4         LL_DMA_IsActiveFlag_TC4
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC4(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF4位，判断通道4是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF4) == (DMA_ISR_TCIF4));
}

/**
  * @brief  获取通道5的传输完成标志。
  * @rmtoll ISR          TCIF5         LL_DMA_IsActiveFlag_TC5
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC5(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF5位，判断通道5是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF5) == (DMA_ISR_TCIF5));
}

/**
  * @brief  获取通道6的传输完成标志。
  * @rmtoll ISR          TCIF6         LL_DMA_IsActiveFlag_TC6
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC6(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF6位，判断通道6是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF6) == (DMA_ISR_TCIF6));
}

/**
  * @brief  获取通道7的传输完成标志。
  * @rmtoll ISR          TCIF7         LL_DMA_IsActiveFlag_TC7
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC7(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF7位，判断通道7是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF7) == (DMA_ISR_TCIF7));
}

/**
  * @brief  获取通道1的半传输完成标志。
  * @rmtoll ISR          HTIF1         LL_DMA_IsActiveFlag_HT1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT1(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF1位，判断通道1是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF1) == (DMA_ISR_HTIF1));
}

/**
  * @brief  获取通道2的半传输完成标志。
  * @rmtoll ISR          HTIF2         LL_DMA_IsActiveFlag_HT2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT2(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF2位，判断通道2是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF2) == (DMA_ISR_HTIF2));
}

/**
  * @brief  获取通道3的半传输完成标志。
  * @rmtoll ISR          HTIF3         LL_DMA_IsActiveFlag_HT3
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT3(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF3位，判断通道3是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF3) == (DMA_ISR_HTIF3));
}

/**
  * @brief  获取通道4的半传输完成标志。
  * @rmtoll ISR          HTIF4         LL_DMA_IsActiveFlag_HT4
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT4(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF4位，判断通道4是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF4) == (DMA_ISR_HTIF4));
}

/**
  * @brief  获取通道5的半传输完成标志。
  * @rmtoll ISR          HTIF5         LL_DMA_IsActiveFlag_HT5
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT5(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF5位，判断通道5是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF5) == (DMA_ISR_HTIF5));
}

/**
  * @brief  获取通道6的半传输完成标志。
  * @rmtoll ISR          HTIF6         LL_DMA_IsActiveFlag_HT6
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT6(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF6位，判断通道6是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF6) == (DMA_ISR_HTIF6));
}

/**
  * @brief  获取通道7的半传输完成标志。
  * @rmtoll ISR          HTIF7         LL_DMA_IsActiveFlag_HT7
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT7(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF7位，判断通道7是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF7) == (DMA_ISR_HTIF7));
}

/**
  * @brief  获取通道1的传输错误标志。
  * @rmtoll ISR          TEIF1         LL_DMA_IsActiveFlag_TE1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE1(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TEIF1位，判断通道1是否发生传输错误 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF1) == (DMA_ISR_TEIF1));
}

/**
  * @brief  获取通道2的传输错误标志。
  * @rmtoll ISR          TEIF2         LL_DMA_IsActiveFlag_TE2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE2(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TEIF2位，判断通道2是否发生传输错误 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF2) == (DMA_ISR_TEIF2));
}
