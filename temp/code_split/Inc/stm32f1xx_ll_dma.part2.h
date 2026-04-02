
/**
  * @brief  Get Channel priority level.
  * @rmtoll CCR          PL            LL_DMA_GetChannelPriorityLevel
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_DMA_PRIORITY_LOW
  *         @arg @ref LL_DMA_PRIORITY_MEDIUM
  *         @arg @ref LL_DMA_PRIORITY_HIGH
  *         @arg @ref LL_DMA_PRIORITY_VERYHIGH
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_PL));
}

/**
  * @brief  Set Number of data to transfer.
  * @note   This action has no effect if
  *         channel is enabled.
  * @rmtoll CNDTR        NDT           LL_DMA_SetDataLength
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  NbData Between Min_Data = 0 and Max_Data = 0x0000FFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetDataLength(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t NbData)
{
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CNDTR,
             DMA_CNDTR_NDT, NbData);
}

/**
  * @brief  Get Number of data to transfer.
  * @note   Once the channel is enabled, the return value indicate the
  *         remaining bytes to be transmitted.
  * @rmtoll CNDTR        NDT           LL_DMA_GetDataLength
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetDataLength(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CNDTR,
                   DMA_CNDTR_NDT));
}

/**
  * @brief  Configure the Source and Destination addresses.
  * @note   This API must not be called when the DMA channel is enabled.
  * @note   Each IP using DMA provides an API to get directly the register address (LL_PPP_DMA_GetRegAddr).
  * @rmtoll CPAR         PA            LL_DMA_ConfigAddresses\n
  *         CMAR         MA            LL_DMA_ConfigAddresses
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  SrcAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @param  DstAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @param  Direction This parameter can be one of the following values:
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY
  * @retval None
  */
__STATIC_INLINE void LL_DMA_ConfigAddresses(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress,
                                            uint32_t DstAddress, uint32_t Direction)
{
  /* Direction Memory to Periph */
  if (Direction == LL_DMA_DIRECTION_MEMORY_TO_PERIPH)
  {
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, SrcAddress);
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, DstAddress);
  }
  /* Direction Periph to Memory and Memory to Memory */
  else
  {
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, SrcAddress);
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, DstAddress);
  }
}

/**
  * @brief  Set the Memory address.
  * @note   Interface used for direction LL_DMA_DIRECTION_PERIPH_TO_MEMORY or LL_DMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CMAR         MA            LL_DMA_SetMemoryAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  MemoryAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetMemoryAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, MemoryAddress);
}

/**
  * @brief  Set the Peripheral address.
  * @note   Interface used for direction LL_DMA_DIRECTION_PERIPH_TO_MEMORY or LL_DMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CPAR         PA            LL_DMA_SetPeriphAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  PeriphAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetPeriphAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, PeriphAddress);
}

/**
  * @brief  Get Memory address.
  * @note   Interface used for direction LL_DMA_DIRECTION_PERIPH_TO_MEMORY or LL_DMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @rmtoll CMAR         MA            LL_DMA_GetMemoryAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetMemoryAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR));
}

/**
  * @brief  Get Peripheral address.
  * @note   Interface used for direction LL_DMA_DIRECTION_PERIPH_TO_MEMORY or LL_DMA_DIRECTION_MEMORY_TO_PERIPH only.
  * @rmtoll CPAR         PA            LL_DMA_GetPeriphAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetPeriphAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR));
}

/**
  * @brief  Set the Memory to Memory Source address.
  * @note   Interface used for direction LL_DMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CPAR         PA            LL_DMA_SetM2MSrcAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  MemoryAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetM2MSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, MemoryAddress);
}

/**
  * @brief  Set the Memory to Memory Destination address.
  * @note   Interface used for direction LL_DMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @note   This API must not be called when the DMA channel is enabled.
  * @rmtoll CMAR         MA            LL_DMA_SetM2MDstAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  MemoryAddress Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  * @retval None
  */
__STATIC_INLINE void LL_DMA_SetM2MDstAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, MemoryAddress);
}

/**
  * @brief  Get the Memory to Memory Source address.
  * @note   Interface used for direction LL_DMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @rmtoll CPAR         PA            LL_DMA_GetM2MSrcAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetM2MSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR));
}

/**
  * @brief  Get the Memory to Memory Destination address.
  * @note   Interface used for direction LL_DMA_DIRECTION_MEMORY_TO_MEMORY only.
  * @rmtoll CMAR         MA            LL_DMA_GetM2MDstAddress
  * @param  DMAx DMAx Instance
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval Between Min_Data = 0 and Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetM2MDstAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR));
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_FLAG_Management FLAG_Management
  * @{
  */

/**
  * @brief  Get Channel 1 global interrupt flag.
  * @rmtoll ISR          GIF1          LL_DMA_IsActiveFlag_GI1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF1) == (DMA_ISR_GIF1));
}

/**
  * @brief  Get Channel 2 global interrupt flag.
  * @rmtoll ISR          GIF2          LL_DMA_IsActiveFlag_GI2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF2) == (DMA_ISR_GIF2));
}

/**
  * @brief  Get Channel 3 global interrupt flag.
  * @rmtoll ISR          GIF3          LL_DMA_IsActiveFlag_GI3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF3) == (DMA_ISR_GIF3));
}

/**
  * @brief  Get Channel 4 global interrupt flag.
  * @rmtoll ISR          GIF4          LL_DMA_IsActiveFlag_GI4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF4) == (DMA_ISR_GIF4));
}

/**
  * @brief  Get Channel 5 global interrupt flag.
  * @rmtoll ISR          GIF5          LL_DMA_IsActiveFlag_GI5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF5) == (DMA_ISR_GIF5));
}

/**
  * @brief  Get Channel 6 global interrupt flag.
  * @rmtoll ISR          GIF6          LL_DMA_IsActiveFlag_GI6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF6) == (DMA_ISR_GIF6));
}

/**
  * @brief  Get Channel 7 global interrupt flag.
  * @rmtoll ISR          GIF7          LL_DMA_IsActiveFlag_GI7
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI7(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF7) == (DMA_ISR_GIF7));
}

/**
  * @brief  Get Channel 1 transfer complete flag.
  * @rmtoll ISR          TCIF1         LL_DMA_IsActiveFlag_TC1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF1) == (DMA_ISR_TCIF1));
}

/**
  * @brief  Get Channel 2 transfer complete flag.
  * @rmtoll ISR          TCIF2         LL_DMA_IsActiveFlag_TC2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF2) == (DMA_ISR_TCIF2));
}

/**
  * @brief  Get Channel 3 transfer complete flag.
  * @rmtoll ISR          TCIF3         LL_DMA_IsActiveFlag_TC3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF3) == (DMA_ISR_TCIF3));
}

/**
  * @brief  Get Channel 4 transfer complete flag.
  * @rmtoll ISR          TCIF4         LL_DMA_IsActiveFlag_TC4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF4) == (DMA_ISR_TCIF4));
}

/**
  * @brief  Get Channel 5 transfer complete flag.
  * @rmtoll ISR          TCIF5         LL_DMA_IsActiveFlag_TC5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF5) == (DMA_ISR_TCIF5));
}

/**
  * @brief  Get Channel 6 transfer complete flag.
  * @rmtoll ISR          TCIF6         LL_DMA_IsActiveFlag_TC6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF6) == (DMA_ISR_TCIF6));
}

/**
  * @brief  Get Channel 7 transfer complete flag.
  * @rmtoll ISR          TCIF7         LL_DMA_IsActiveFlag_TC7
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC7(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF7) == (DMA_ISR_TCIF7));
}

/**
  * @brief  Get Channel 1 half transfer flag.
  * @rmtoll ISR          HTIF1         LL_DMA_IsActiveFlag_HT1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF1) == (DMA_ISR_HTIF1));
}

/**
  * @brief  Get Channel 2 half transfer flag.
  * @rmtoll ISR          HTIF2         LL_DMA_IsActiveFlag_HT2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF2) == (DMA_ISR_HTIF2));
}

/**
  * @brief  Get Channel 3 half transfer flag.
  * @rmtoll ISR          HTIF3         LL_DMA_IsActiveFlag_HT3
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT3(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF3) == (DMA_ISR_HTIF3));
}

/**
  * @brief  Get Channel 4 half transfer flag.
  * @rmtoll ISR          HTIF4         LL_DMA_IsActiveFlag_HT4
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT4(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF4) == (DMA_ISR_HTIF4));
}

/**
  * @brief  Get Channel 5 half transfer flag.
  * @rmtoll ISR          HTIF5         LL_DMA_IsActiveFlag_HT5
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT5(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF5) == (DMA_ISR_HTIF5));
}

/**
  * @brief  Get Channel 6 half transfer flag.
  * @rmtoll ISR          HTIF6         LL_DMA_IsActiveFlag_HT6
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT6(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF6) == (DMA_ISR_HTIF6));
}

/**
  * @brief  Get Channel 7 half transfer flag.
  * @rmtoll ISR          HTIF7         LL_DMA_IsActiveFlag_HT7
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT7(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF7) == (DMA_ISR_HTIF7));
}

/**
  * @brief  Get Channel 1 transfer error flag.
  * @rmtoll ISR          TEIF1         LL_DMA_IsActiveFlag_TE1
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE1(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF1) == (DMA_ISR_TEIF1));
}

/**
  * @brief  Get Channel 2 transfer error flag.
  * @rmtoll ISR          TEIF2         LL_DMA_IsActiveFlag_TE2
  * @param  DMAx DMAx Instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE2(DMA_TypeDef *DMAx)
{
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF2) == (DMA_ISR_TEIF2));
}
