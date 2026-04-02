
/**
  * @brief  Get Channel 3 transfer error flag.
  * @rmtoll ISR          TEIF3         LL_DMA_IsActiveFlag_TE3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF3) == (DMA_ISR_TEIF3));
}

/**
  * @brief  Get Channel 4 transfer error flag.
  * @rmtoll ISR          TEIF4         LL_DMA_IsActiveFlag_TE4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF4) == (DMA_ISR_TEIF4));
}

/**
  * @brief  Get Channel 5 transfer error flag.
  * @rmtoll ISR          TEIF5         LL_DMA_IsActiveFlag_TE5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF5) == (DMA_ISR_TEIF5));
}

/**
  * @brief  Get Channel 6 transfer error flag.
  * @rmtoll ISR          TEIF6         LL_DMA_IsActiveFlag_TE6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF6) == (DMA_ISR_TEIF6));
}

/**
  * @brief  Get Channel 7 transfer error flag.
  * @rmtoll ISR          TEIF7         LL_DMA_IsActiveFlag_TE7
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE7(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF7) == (DMA_ISR_TEIF7));
}

/**
  * @brief  Clear Channel 1 global interrupt flag.
  * @rmtoll IFCR         CGIF1         LL_DMA_ClearFlag_GI1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF1);
}

/**
  * @brief  Clear Channel 2 global interrupt flag.
  * @rmtoll IFCR         CGIF2         LL_DMA_ClearFlag_GI2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF2);
}

/**
  * @brief  Clear Channel 3 global interrupt flag.
  * @rmtoll IFCR         CGIF3         LL_DMA_ClearFlag_GI3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF3);
}

/**
  * @brief  Clear Channel 4 global interrupt flag.
  * @rmtoll IFCR         CGIF4         LL_DMA_ClearFlag_GI4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF4);
}

/**
  * @brief  Clear Channel 5 global interrupt flag.
  * @rmtoll IFCR         CGIF5         LL_DMA_ClearFlag_GI5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF5);
}

/**
  * @brief  Clear Channel 6 global interrupt flag.
  * @rmtoll IFCR         CGIF6         LL_DMA_ClearFlag_GI6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF6);
}

/**
  * @brief  Clear Channel 7 global interrupt flag.
  * @rmtoll IFCR         CGIF7         LL_DMA_ClearFlag_GI7
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF7);
}

/**
  * @brief  Clear Channel 1  transfer complete flag.
  * @rmtoll IFCR         CTCIF1        LL_DMA_ClearFlag_TC1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF1);
}

/**
  * @brief  Clear Channel 2  transfer complete flag.
  * @rmtoll IFCR         CTCIF2        LL_DMA_ClearFlag_TC2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF2);
}

/**
  * @brief  Clear Channel 3  transfer complete flag.
  * @rmtoll IFCR         CTCIF3        LL_DMA_ClearFlag_TC3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF3);
}

/**
  * @brief  Clear Channel 4  transfer complete flag.
  * @rmtoll IFCR         CTCIF4        LL_DMA_ClearFlag_TC4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF4);
}

/**
  * @brief  Clear Channel 5  transfer complete flag.
  * @rmtoll IFCR         CTCIF5        LL_DMA_ClearFlag_TC5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF5);
}

/**
  * @brief  Clear Channel 6  transfer complete flag.
  * @rmtoll IFCR         CTCIF6        LL_DMA_ClearFlag_TC6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF6);
}

/**
  * @brief  Clear Channel 7  transfer complete flag.
  * @rmtoll IFCR         CTCIF7        LL_DMA_ClearFlag_TC7
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF7);
}

/**
  * @brief  Clear Channel 1  half transfer flag.
  * @rmtoll IFCR         CHTIF1        LL_DMA_ClearFlag_HT1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF1);
}

/**
  * @brief  Clear Channel 2  half transfer flag.
  * @rmtoll IFCR         CHTIF2        LL_DMA_ClearFlag_HT2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF2);
}

/**
  * @brief  Clear Channel 3  half transfer flag.
  * @rmtoll IFCR         CHTIF3        LL_DMA_ClearFlag_HT3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF3);
}

/**
  * @brief  Clear Channel 4  half transfer flag.
  * @rmtoll IFCR         CHTIF4        LL_DMA_ClearFlag_HT4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF4);
}

/**
  * @brief  Clear Channel 5  half transfer flag.
  * @rmtoll IFCR         CHTIF5        LL_DMA_ClearFlag_HT5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF5);
}

/**
  * @brief  Clear Channel 6  half transfer flag.
  * @rmtoll IFCR         CHTIF6        LL_DMA_ClearFlag_HT6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF6);
}

/**
  * @brief  Clear Channel 7  half transfer flag.
  * @rmtoll IFCR         CHTIF7        LL_DMA_ClearFlag_HT7
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF7);
}

/**
  * @brief  Clear Channel 1 transfer error flag.
  * @rmtoll IFCR         CTEIF1        LL_DMA_ClearFlag_TE1
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE1(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF1);
}

/**
  * @brief  Clear Channel 2 transfer error flag.
  * @rmtoll IFCR         CTEIF2        LL_DMA_ClearFlag_TE2
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE2(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF2);
}

/**
  * @brief  Clear Channel 3 transfer error flag.
  * @rmtoll IFCR         CTEIF3        LL_DMA_ClearFlag_TE3
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE3(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF3);
}

/**
  * @brief  Clear Channel 4 transfer error flag.
  * @rmtoll IFCR         CTEIF4        LL_DMA_ClearFlag_TE4
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE4(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF4);
}

/**
  * @brief  Clear Channel 5 transfer error flag.
  * @rmtoll IFCR         CTEIF5        LL_DMA_ClearFlag_TE5
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE5(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF5);
}

/**
  * @brief  Clear Channel 6 transfer error flag.
  * @rmtoll IFCR         CTEIF6        LL_DMA_ClearFlag_TE6
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE6(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF6);
}

/**
  * @brief  Clear Channel 7 transfer error flag.
  * @rmtoll IFCR         CTEIF7        LL_DMA_ClearFlag_TE7
  * @param  DMAx DMAx Instance
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE7(DMA_TypeDef *DMAx)
{
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF7);
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  Enable Transfer complete interrupt.
  * @rmtoll CCR          TCIE          LL_DMA_EnableIT_TC
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TCIE);
}

/**
  * @brief  Enable Half transfer interrupt.
  * @rmtoll CCR          HTIE          LL_DMA_EnableIT_HT
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_HTIE);
}

/**
  * @brief  Enable Transfer error interrupt.
  * @rmtoll CCR          TEIE          LL_DMA_EnableIT_TE
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_DMA_EnableIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TEIE);
}

/**
  * @brief  Disable Transfer complete interrupt.
  * @rmtoll CCR          TCIE          LL_DMA_DisableIT_TC
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TCIE);
}

/**
  * @brief  Disable Half transfer interrupt.
  * @rmtoll CCR          HTIE          LL_DMA_DisableIT_HT
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_HTIE);
}

/**
  * @brief  Disable Transfer error interrupt.
  * @rmtoll CCR          TEIE          LL_DMA_DisableIT_TE
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval None
  */
__STATIC_INLINE void LL_DMA_DisableIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TEIE);
}

/**
  * @brief  Check if Transfer complete Interrupt is enabled.
  * @rmtoll CCR          TCIE          LL_DMA_IsEnabledIT_TC
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_TCIE) == (DMA_CCR_TCIE));
}

/**
  * @brief  Check if Half transfer Interrupt is enabled.
  * @rmtoll CCR          HTIE          LL_DMA_IsEnabledIT_HT
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_HTIE) == (DMA_CCR_HTIE));
}

/**
  * @brief  Check if Transfer error Interrupt is enabled.
  * @rmtoll CCR          TEIE          LL_DMA_IsEnabledIT_TE
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
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

uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct);
uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel);
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

