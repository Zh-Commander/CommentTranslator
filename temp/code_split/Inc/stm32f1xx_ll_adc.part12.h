
/**
  * @brief  Stop ADC group injected conversion from external trigger.
  * @note   No more ADC conversion will start at next trigger event
  *         following the ADC stop conversion command.
  *         If a conversion is on-going, it will be completed.
  * @note   On this STM32 series, there is no specific command
  *         to stop a conversion on-going or to stop ADC converting
  *         in continuous mode. These actions can be performed
  *         using function @ref LL_ADC_Disable().
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_StopConversionExtTrig
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_StopConversionExtTrig(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->CR2, ADC_CR2_JEXTTRIG);
}

/**
  * @brief  Get ADC group regular conversion data, range fit for
  *         all ADC configurations: all ADC resolutions and
  *         all oversampling increased data width (for devices
  *         with feature oversampling).
  * @rmtoll JDR1     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR2     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR3     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR4     JDATA          LL_ADC_INJ_ReadConversionData32
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval Value between Min_Data=0x00000000 and Max_Data=0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_ReadConversionData32(ADC_TypeDef *ADCx, uint32_t Rank)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JDRX_REGOFFSET_MASK));
  
  return (uint32_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
  * @brief  Get ADC group injected conversion data, range fit for
  *         ADC resolution 12 bits.
  * @note   For devices with feature oversampling: Oversampling
  *         can increase data width, function for extended range
  *         may be needed: @ref LL_ADC_INJ_ReadConversionData32.
  * @rmtoll JDR1     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR2     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR3     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR4     JDATA          LL_ADC_INJ_ReadConversionData12
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval Value between Min_Data=0x000 and Max_Data=0xFFF
  */
__STATIC_INLINE uint16_t LL_ADC_INJ_ReadConversionData12(ADC_TypeDef *ADCx, uint32_t Rank)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JDRX_REGOFFSET_MASK));
  
  return (uint16_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_FLAG_Management ADC flag management
  * @{
  */

/**
  * @brief  Get flag ADC group regular end of sequence conversions.
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_EOS
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_EOS) == (LL_ADC_FLAG_EOS));
}


/**
  * @brief  Get flag ADC group injected end of sequence conversions.
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_JEOS
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_JEOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_JEOS) == (LL_ADC_FLAG_JEOS));
}

/**
  * @brief  Get flag ADC analog watchdog 1 flag
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_AWD1
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD1(ADC_TypeDef *ADCx)
{
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

/**
  * @brief  Clear flag ADC group regular end of sequence conversions.
  * @rmtoll SR       EOC            LL_ADC_ClearFlag_EOS
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_EOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_EOS);
}


/**
  * @brief  Clear flag ADC group injected end of sequence conversions.
  * @rmtoll SR       JEOC           LL_ADC_ClearFlag_JEOS
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_JEOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_JEOS);
}

/**
  * @brief  Clear flag ADC analog watchdog 1.
  * @rmtoll SR       AWD            LL_ADC_ClearFlag_AWD1
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_ClearFlag_AWD1(ADC_TypeDef *ADCx)
{
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_AWD1);
}

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  Get flag multimode ADC group regular end of sequence conversions of the ADC master.
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_MST_EOS
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_EOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  return (READ_BIT(ADCxy_COMMON->SR, ADC_SR_EOC) == (ADC_SR_EOC));
}

/**
  * @brief  Get flag multimode ADC group regular end of sequence conversions of the ADC slave.
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_SLV_EOS
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_EOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  return (READ_BIT(*preg, LL_ADC_FLAG_EOS_SLV) == (LL_ADC_FLAG_EOS_SLV));
}


/**
  * @brief  Get flag multimode ADC group injected end of sequence conversions of the ADC master.
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_MST_JEOS
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_JEOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  return (READ_BIT(ADCxy_COMMON->SR, ADC_SR_JEOC) == (ADC_SR_JEOC));
}

/**
  * @brief  Get flag multimode ADC group injected end of sequence conversions of the ADC slave.
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_SLV_JEOS
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_JEOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  return (READ_BIT(*preg, LL_ADC_FLAG_JEOS_SLV) == (LL_ADC_FLAG_JEOS_SLV));
}

/**
  * @brief  Get flag multimode ADC analog watchdog 1 of the ADC master.
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_MST_AWD1
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_AWD1(ADC_Common_TypeDef *ADCxy_COMMON)
{
  return (READ_BIT(ADCxy_COMMON->SR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

/**
  * @brief  Get flag multimode analog watchdog 1 of the ADC slave.
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_SLV_AWD1
  * @param  ADCxy_COMMON ADC common instance
  *         (can be set directly from CMSIS definition or by using helper macro @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_AWD1(ADC_Common_TypeDef *ADCxy_COMMON)
{
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  return (READ_BIT(*preg, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */

/** @defgroup ADC_LL_EF_IT_Management ADC IT management
  * @{
  */

/**
  * @brief  Enable interruption ADC group regular end of sequence conversions.
  * @rmtoll CR1      EOCIE          LL_ADC_EnableIT_EOS
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_EnableIT_EOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  SET_BIT(ADCx->CR1, ADC_CR1_EOCIE);
}


/**
  * @brief  Enable interruption ADC group injected end of sequence conversions.
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_EnableIT_JEOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  SET_BIT(ADCx->CR1, LL_ADC_IT_JEOS);
}

/**
  * @brief  Enable interruption ADC analog watchdog 1.
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_EnableIT_AWD1(ADC_TypeDef *ADCx)
{
  SET_BIT(ADCx->CR1, LL_ADC_IT_AWD1);
}

/**
  * @brief  Disable interruption ADC group regular end of sequence conversions.
  * @rmtoll CR1      EOCIE          LL_ADC_DisableIT_EOS
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_DisableIT_EOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  CLEAR_BIT(ADCx->CR1, ADC_CR1_EOCIE);
}


/**
  * @brief  Disable interruption ADC group injected end of sequence conversions.
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_DisableIT_JEOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  CLEAR_BIT(ADCx->CR1, LL_ADC_IT_JEOS);
}

/**
  * @brief  Disable interruption ADC analog watchdog 1.
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC instance
  * @retval None
  */
__STATIC_INLINE void LL_ADC_DisableIT_AWD1(ADC_TypeDef *ADCx)
{
  CLEAR_BIT(ADCx->CR1, LL_ADC_IT_AWD1);
}

/**
  * @brief  Get state of interruption ADC group regular end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @rmtoll CR1      EOCIE          LL_ADC_IsEnabledIT_EOS
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group regular           */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "EOC" is corresponding to flag "EOS"                 */
  /*       in other STM32 families).                                          */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_EOS) == (LL_ADC_IT_EOS));
}


/**
  * @brief  Get state of interruption ADC group injected end of sequence conversions
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_JEOS(ADC_TypeDef *ADCx)
{
  /* Note: on this STM32 series, there is no flag ADC group injected          */
  /*       end of unitary conversion.                                         */
  /*       Flag noted as "JEOC" is corresponding to flag "JEOS"               */
  /*       in other STM32 families).                                          */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_JEOS) == (LL_ADC_IT_JEOS));
}

/**
  * @brief  Get state of interruption ADC analog watchdog 1
  *         (0: interrupt disabled, 1: interrupt enabled).
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC instance
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD1(ADC_TypeDef *ADCx)
{
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_AWD1) == (LL_ADC_IT_AWD1));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

/* Initialization of some features of ADC common parameters and multimode */
ErrorStatus LL_ADC_CommonDeInit(ADC_Common_TypeDef *ADCxy_COMMON);
ErrorStatus LL_ADC_CommonInit(ADC_Common_TypeDef *ADCxy_COMMON, LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
void        LL_ADC_CommonStructInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);

/* De-initialization of ADC instance, ADC group regular and ADC group injected */
/* (availability of ADC group injected depends on STM32 families) */
ErrorStatus LL_ADC_DeInit(ADC_TypeDef *ADCx);

/* Initialization of some features of ADC instance */
ErrorStatus LL_ADC_Init(ADC_TypeDef *ADCx, LL_ADC_InitTypeDef *ADC_InitStruct);
void        LL_ADC_StructInit(LL_ADC_InitTypeDef *ADC_InitStruct);

/* Initialization of some features of ADC instance and ADC group regular */
ErrorStatus LL_ADC_REG_Init(ADC_TypeDef *ADCx, LL_ADC_REG_InitTypeDef *ADC_REG_InitStruct);
void        LL_ADC_REG_StructInit(LL_ADC_REG_InitTypeDef *ADC_REG_InitStruct);

/* Initialization of some features of ADC instance and ADC group injected */
ErrorStatus LL_ADC_INJ_Init(ADC_TypeDef *ADCx, LL_ADC_INJ_InitTypeDef *ADC_INJ_InitStruct);
void        LL_ADC_INJ_StructInit(LL_ADC_INJ_InitTypeDef *ADC_INJ_InitStruct);

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

#endif /* ADC1 || ADC2 || ADC3 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_LL_ADC_H */
