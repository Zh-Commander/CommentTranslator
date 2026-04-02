/**
  * @brief  获取通道3传输错误标志。
  * @rmtoll ISR          TEIF3         LL_DMA_IsActiveFlag_TE3
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE3(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道3的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF3) == (DMA_ISR_TEIF3));
}

/**
  * @brief  获取通道4传输错误标志。
  * @rmtoll ISR          TEIF4         LL_DMA_IsActiveFlag_TE4
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE4(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道4的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF4) == (DMA_ISR_TEIF4));
}

/**
  * @brief  获取通道5传输错误标志。
  * @rmtoll ISR          TEIF5         LL_DMA_IsActiveFlag_TE5
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE5(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道5的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF5) == (DMA_ISR_TEIF5));
}

/**
  * @brief  获取通道6传输错误标志。
  * @rmtoll ISR          TEIF6         LL_DMA_IsActiveFlag_TE6
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE6(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道6的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF6) == (DMA_ISR_TEIF6));
}

/**
  * @brief  获取通道7传输错误标志。
  * @rmtoll ISR          TEIF7         LL_DMA_IsActiveFlag_TE7
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE7(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道7的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF7) == (DMA_ISR_TEIF7));
}

/**
  * @brief  清除通道1全局中断标志。
  * @rmtoll IFCR         CGIF1         LL_DMA_ClearFlag_GI1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF1);
}

/**
  * @brief  清除通道2全局中断标志。
  * @rmtoll IFCR         CGIF2         LL_DMA_ClearFlag_GI2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF2);
}

/**
  * @brief  清除通道3全局中断标志。
  * @rmtoll IFCR         CGIF3         LL_DMA_ClearFlag_GI3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF3);
}

/**
  * @brief  清除通道4全局中断标志。
  * @rmtoll IFCR         CGIF4         LL_DMA_ClearFlag_GI4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF4);
}

/**
  * @brief  清除通道5全局中断标志。
  * @rmtoll IFCR         CGIF5         LL_DMA_ClearFlag_GI5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF5);
}

/**
  * @brief  清除通道6全局中断标志。
  * @rmtoll IFCR         CGIF6         LL_DMA_ClearFlag_GI6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF6);
}

/**
  * @brief  清除通道7全局中断标志。
  * @rmtoll IFCR         CGIF7         LL_DMA_ClearFlag_GI7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF7);
}

/**
  * @brief  清除通道1传输完成标志。
  * @rmtoll IFCR         CTCIF1        LL_DMA_ClearFlag_TC1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF1);
}

/**
  * @brief  清除通道2传输完成标志。
  * @rmtoll IFCR         CTCIF2        LL_DMA_ClearFlag_TC2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF2);
}

/**
  * @brief  清除通道3传输完成标志。
  * @rmtoll IFCR         CTCIF3        LL_DMA_ClearFlag_TC3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF3);
}

/**
  * @brief  清除通道4传输完成标志。
  * @rmtoll IFCR         CTCIF4        LL_DMA_ClearFlag_TC4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF4);
}

/**
  * @brief  清除通道5传输完成标志。
  * @rmtoll IFCR         CTCIF5        LL_DMA_ClearFlag_TC5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF5);
}

/**
  * @brief  清除通道6传输完成标志。
  * @rmtoll IFCR         CTCIF6        LL_DMA_ClearFlag_TC6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF6);
}

/**
  * @brief  清除通道7传输完成标志。
  * @rmtoll IFCR         CTCIF7        LL_DMA_ClearFlag_TC7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF7);
}

/**
  * @brief  清除通道1半传输标志。
  * @rmtoll IFCR         CHTIF1        LL_DMA_ClearFlag_HT1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF1);
}

/**
  * @brief  清除通道2半传输标志。
  * @rmtoll IFCR         CHTIF2        LL_DMA_ClearFlag_HT2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF2);
}

/**
  * @brief  清除通道3半传输标志。
  * @rmtoll IFCR         CHTIF3        LL_DMA_ClearFlag_HT3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF3);
}

/**
  * @brief  清除通道4半传输标志。
  * @rmtoll IFCR         CHTIF4        LL_DMA_ClearFlag_HT4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF4);
}

/**
  * @brief  清除通道5半传输标志。
  * @rmtoll IFCR         CHTIF5        LL_DMA_ClearFlag_HT5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF5);
}

/**
  * @brief  清除通道6半传输标志。
  * @rmtoll IFCR         CHTIF6        LL_DMA_ClearFlag_HT6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF6);
}

/**
  * @brief  清除通道7半传输标志。
  * @rmtoll IFCR         CHTIF7        LL_DMA_ClearFlag_HT7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF7);
}

/**
  * @brief  清除通道1传输错误标志。
  * @rmtoll IFCR         CTEIF1        LL_DMA_ClearFlag_TE1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF1);
}

/**
  * @brief  清除通道2传输错误标志。
  * @rmtoll IFCR         CTEIF2        LL_DMA_ClearFlag_TE2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF2);
}

/**
  * @brief  清除通道3传输错误标志。
  * @rmtoll IFCR         CTEIF3        LL_DMA_ClearFlag_TE3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF3);
}

/**
  * @brief  清除通道4传输错误标志。
  * @rmtoll IFCR         CTEIF4        LL_DMA_ClearFlag_TE4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF4);
}

/**
  * @brief  清除通道5传输错误标志。
  * @rmtoll IFCR         CTEIF5        LL_DMA_ClearFlag_TE5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF5);
}

/**
  * @brief  清除通道6传输错误标志。
  * @rmtoll IFCR         CTEIF6        LL_DMA_ClearFlag_TE6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF6);
}

/**
  * @brief  清除通道7传输错误标志。
  * @rmtoll IFCR         CTEIF7        LL_DMA_ClearFlag_TE7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF7);
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  使能传输完成中断。
  * @rmtoll CCR          TCIE          LL_DMA_EnableIT_TC
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并设置CCR寄存器中的TCIE位（传输完成中断使能）
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TCIE);
}

/**
  * @brief  使能半传输中断。
  * @rmtoll CCR          HTIE          LL_DMA_EnableIT_HT
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并设置CCR寄存器中的HTIE位（半传输中断使能）
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_HTIE);
}

/**
  * @brief  使能传输错误中断。
  * @rmtoll CCR          TEIE          LL_DMA_EnableIT_TE
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并设置CCR寄存器中的TEIE位（传输错误中断使能）
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TEIE);
}

/**
  * @brief  禁用传输完成中断。
  * @rmtoll CCR          TCIE          LL_DMA_DisableIT_TC
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并清除CCR寄存器中的TCIE位（传输完成中断使能）
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TCIE);
}

/**
  * @brief  禁用半传输中断。
  * @rmtoll CCR          HTIE          LL_DMA_DisableIT_HT
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并清除CCR寄存器中的HTIE位（半传输中断使能）
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_HTIE);
}

/**
  * @brief  禁用传输错误中断。
  * @rmtoll CCR          TEIE          LL_DMA_DisableIT_TE
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并清除CCR寄存器中的TEIE位（传输错误中断使能）
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TEIE);
}

/**
  * @brief  检查传输完成中断是否使能。
  * @rmtoll CCR          TCIE          LL_DMA_IsEnabledIT_TC
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 读取CCR寄存器，判断传输完成中断使能位是否置位
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_TCIE) == (DMA_CCR_TCIE));
}

/**
  * @brief  检查半传输中断是否使能。
  * @rmtoll CCR          HTIE          LL_DMA_IsEnabledIT_HT
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 读取CCR寄存器，判断半传输中断使能位是否置位
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_HTIE) == (DMA_CCR_HTIE));
}

/**
  * @brief  检查传输错误中断是否使能。
  * @rmtoll CCR          TEIE          LL_DMA_IsEnabledIT_TE
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 读取CCR寄存器，判断传输错误中断使能位是否置位
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_TEIE) == (DMA_CCR_TEIE));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
// 函数声明：DMA初始化函数
uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct);
// 函数声明：DMA反初始化函数（恢复默认状态）
uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel);
// 函数声明：DMA结构体参数默认值设置函数
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* DMA1 || DMA2 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_LL_DMA_H */
