/**
  * @brief  停止ADC注入组的外部触发转换。
  * @note   在执行停止转换命令后，下一个触发事件将不再启动ADC转换。
  *         如果当前正在进行转换，它将会完成。
  * @note   在此STM32系列中，没有特定的命令来停止正在进行的转换
  *         或停止连续模式下的ADC转换。这些操作可以通过
  *         函数 @ref LL_ADC_Disable() 来执行。
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_StopConversionExtTrig
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_INJ_StopConversionExtTrig(ADC_TypeDef *ADCx)
{
  /* 清除CR2寄存器中的JEXTTRIG位，禁止注入组的外部触发转换 */
  CLEAR_BIT(ADCx->CR2, ADC_CR2_JEXTTRIG);
}

/**
  * @brief  读取ADC注入组转换数据，数据范围适用于所有ADC配置：
  *         所有ADC分辨率以及所有过采样增加的数据宽度（针对支持
  *         过采样功能的设备）。
  * @rmtoll JDR1     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR2     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR3     JDATA          LL_ADC_INJ_ReadConversionData32\n
  *         JDR4     JDATA          LL_ADC_INJ_ReadConversionData32
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1 (注入通道1)
  *         @arg @ref LL_ADC_INJ_RANK_2 (注入通道2)
  *         @arg @ref LL_ADC_INJ_RANK_3 (注入通道3)
  *         @arg @ref LL_ADC_INJ_RANK_4 (注入通道4)
  * @retval 介于 Min_Data=0x00000000 和 Max_Data=0xFFFFFFFF 之间的值
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_ReadConversionData32(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank（序列排名）计算JDRx寄存器的地址偏移量 */
  /* __ADC_PTR_REG_OFFSET用于计算指针偏移，__ADC_MASK_SHIFT用于计算偏移掩码 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JDRX_REGOFFSET_MASK));
  
  /* 读取对应JDRx寄存器的值，并屏蔽掉非数据位，返回32位数据 */
  return (uint32_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
  * @brief  读取ADC注入组转换数据，数据范围适用于12位分辨率。
  * @note   对于具有过采样功能的设备：过采样可能会增加数据宽度，
  *         可能需要使用扩展范围的函数：@ref LL_ADC_INJ_ReadConversionData32。
  * @rmtoll JDR1     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR2     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR3     JDATA          LL_ADC_INJ_ReadConversionData12\n
  *         JDR4     JDATA          LL_ADC_INJ_ReadConversionData12
  * @param  ADCx ADC实例
  * @param  Rank 此参数可以是以下值之一:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval 介于 Min_Data=0x000 和 Max_Data=0xFFF 之间的值
  */
__STATIC_INLINE uint16_t LL_ADC_INJ_ReadConversionData12(ADC_TypeDef *ADCx, uint32_t Rank)
{
  /* 根据Rank计算JDRx寄存器的地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCx->JDR1, __ADC_MASK_SHIFT(Rank, ADC_INJ_JDRX_REGOFFSET_MASK));
  
  /* 读取数据并强制转换为16位无符号整数返回 */
  return (uint16_t)(READ_BIT(*preg,
                             ADC_JDR1_JDATA)
                   );
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_FLAG_Management ADC 标志位管理
  * @{
  */

/**
  * @brief  获取ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_EOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /*       读取SR寄存器中的EOS标志位，判断是否置1 */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_EOS) == (LL_ADC_FLAG_EOS));
}


/**
  * @brief  获取ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_JEOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /*       读取SR寄存器中的JEOS标志位，判断是否置1 */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_JEOS) == (LL_ADC_FLAG_JEOS));
}

/**
  * @brief  获取ADC模拟看门狗1标志位
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_AWD1
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_AWD1(ADC_TypeDef *ADCx)
{
  /* 读取SR寄存器中的AWD1标志位，判断是否置1 */
  return (READ_BIT(ADCx->SR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

/**
  * @brief  清除ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_ClearFlag_EOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_ClearFlag_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /*       向SR寄存器写入对应位的反码来清除标志位 */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_EOS);
}


/**
  * @brief  清除ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_ClearFlag_JEOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_ClearFlag_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /*       向SR寄存器写入对应位的反码来清除标志位 */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_JEOS);
}

/**
  * @brief  清除ADC模拟看门狗1标志位。
  * @rmtoll SR       AWD            LL_ADC_ClearFlag_AWD1
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_ClearFlag_AWD1(ADC_TypeDef *ADCx)
{
  /* 向SR寄存器写入对应位的反码来清除AWD1标志位 */
  WRITE_REG(ADCx->SR, ~LL_ADC_FLAG_AWD1);
}

#if defined(ADC_MULTIMODE_SUPPORT)
/**
  * @brief  获取多模式ADC主ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_MST_EOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_EOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /*       读取通用状态寄存器中的EOC位 */
  return (READ_BIT(ADCxy_COMMON->SR, ADC_SR_EOC) == (ADC_SR_EOC));
}

/**
  * @brief  获取多模式ADC从ADC规则组转换序列结束标志位。
  * @rmtoll SR       EOC            LL_ADC_IsActiveFlag_SLV_EOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_EOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  
  /* 计算从ADC状态寄存器的指针地址（偏移量为1个字） */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  /* 读取从ADC的EOS标志位 */
  return (READ_BIT(*preg, LL_ADC_FLAG_EOS_SLV) == (LL_ADC_FLAG_EOS_SLV));
}


/**
  * @brief  获取多模式ADC主ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_MST_JEOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_JEOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /*       读取通用状态寄存器中的JEOC位 */
  return (READ_BIT(ADCxy_COMMON->SR, ADC_SR_JEOC) == (ADC_SR_JEOC));
}

/**
  * @brief  获取多模式ADC从ADC注入组转换序列结束标志位。
  * @rmtoll SR       JEOC           LL_ADC_IsActiveFlag_SLV_JEOS
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_JEOS(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  
  /* 计算从ADC状态寄存器的指针地址（偏移量为1个字） */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  /* 读取从ADC的JEOS标志位 */
  return (READ_BIT(*preg, LL_ADC_FLAG_JEOS_SLV) == (LL_ADC_FLAG_JEOS_SLV));
}

/**
  * @brief  获取多模式ADC主ADC模拟看门狗1标志位。
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_MST_AWD1
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_MST_AWD1(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 读取主ADC的AWD1标志位 */
  return (READ_BIT(ADCxy_COMMON->SR, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

/**
  * @brief  获取多模式ADC从ADC模拟看门狗1标志位。
  * @rmtoll SR       AWD            LL_ADC_IsActiveFlag_SLV_AWD1
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsActiveFlag_SLV_AWD1(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 计算从ADC状态寄存器的指针地址 */
  __IO uint32_t *preg = __ADC_PTR_REG_OFFSET(ADCxy_COMMON->SR, 1U);
  
  /* 读取从ADC的AWD1标志位 */
  return (READ_BIT(*preg, LL_ADC_FLAG_AWD1) == (LL_ADC_FLAG_AWD1));
}

#endif /* ADC_MULTIMODE_SUPPORT */

/**
  * @}
  */

/** @defgroup ADC_LL_EF_IT_Management ADC 中断管理
  * @{
  */

/**
  * @brief  使能ADC规则组转换序列结束中断。
  * @rmtoll CR1      EOCIE          LL_ADC_EnableIT_EOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_EnableIT_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /* 设置CR1寄存器中的EOCIE位，使能转换结束中断 */
  SET_BIT(ADCx->CR1, ADC_CR1_EOCIE);
}


/**
  * @brief  使能ADC注入组转换序列结束中断。
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_EnableIT_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /* 设置CR1寄存器中的JEOCIE位，使能注入组转换结束中断 */
  SET_BIT(ADCx->CR1, LL_ADC_IT_JEOS);
}

/**
  * @brief  使能ADC模拟看门狗1中断。
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_EnableIT_AWD1(ADC_TypeDef *ADCx)
{
  /* 设置CR1寄存器中的AWDIE位，使能模拟看门狗中断 */
  SET_BIT(ADCx->CR1, LL_ADC_IT_AWD1);
}

/**
  * @brief  禁止ADC规则组转换序列结束中断。
  * @rmtoll CR1      EOCIE          LL_ADC_DisableIT_EOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_DisableIT_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /* 清除CR1寄存器中的EOCIE位，禁止转换结束中断 */
  CLEAR_BIT(ADCx->CR1, ADC_CR1_EOCIE);
}


/**
  * @brief  禁止ADC注入组转换序列结束中断。
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_DisableIT_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /* 清除CR1寄存器中的JEOCIE位，禁止注入组转换结束中断 */
  CLEAR_BIT(ADCx->CR1, LL_ADC_IT_JEOS);
}

/**
  * @brief  禁止ADC模拟看门狗1中断。
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC实例
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_DisableIT_AWD1(ADC_TypeDef *ADCx)
{
  /* 清除CR1寄存器中的AWDIE位，禁止模拟看门狗中断 */
  CLEAR_BIT(ADCx->CR1, LL_ADC_IT_AWD1);
}

/**
  * @brief  获取ADC规则组转换序列结束中断状态
  *         (0: 中断禁止, 1: 中断使能)。
  * @rmtoll CR1      EOCIE          LL_ADC_IsEnabledIT_EOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_EOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有规则组单元转换结束标志位。 */
  /*       标记为 "EOC" 的标志对应于其他STM32系列中的 "EOS" 标志。 */
  /* 读取CR1寄存器中的EOCIE位状态 */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_EOS) == (LL_ADC_IT_EOS));
}


/**
  * @brief  获取ADC注入组转换序列结束中断状态
  *         (0: 中断禁止, 1: 中断使能)。
  * @rmtoll CR1      JEOCIE         LL_ADC_EnableIT_JEOS
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_JEOS(ADC_TypeDef *ADCx)
{
  /* 注意：在此STM32系列中，没有注入组单元转换结束标志位。 */
  /*       标记为 "JEOC" 的标志对应于其他STM32系列中的 "JEOS" 标志。 */
  /* 读取CR1寄存器中的JEOCIE位状态 */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_JEOS) == (LL_ADC_IT_JEOS));
}

/**
  * @brief  获取ADC模拟看门狗1中断状态
  *         (0: 中断禁止, 1: 中断使能)。
  * @rmtoll CR1      AWDIE          LL_ADC_EnableIT_AWD1
  * @param  ADCx ADC实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_ADC_IsEnabledIT_AWD1(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器中的AWDIE位状态 */
  return (READ_BIT(ADCx->CR1, LL_ADC_IT_AWD1) == (LL_ADC_IT_AWD1));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup ADC_LL_EF_Init 初始化和反初始化函数
  * @{
  */

/* ADC通用参数和多模式的某些功能的初始化 */
ErrorStatus LL_ADC_CommonDeInit(ADC_Common_TypeDef *ADCxy_COMMON);
ErrorStatus LL_ADC_CommonInit(ADC_Common_TypeDef *ADCxy_COMMON, LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
void        LL_ADC_CommonStructInit(LL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);

/* ADC实例、规则组和注入组的反初始化 */
/* (注入组的可用性取决于STM32系列) */
ErrorStatus LL_ADC_DeInit(ADC_TypeDef *ADCx);

/* ADC实例某些功能的初始化 */
ErrorStatus LL_ADC_Init(ADC_TypeDef *ADCx, LL_ADC_InitTypeDef *ADC_InitStruct);
void        LL_ADC_StructInit(LL_ADC_InitTypeDef *ADC_InitStruct);

/* ADC实例和规则组某些功能的初始化 */
ErrorStatus LL_ADC_REG_Init(ADC_TypeDef *ADCx, LL_ADC_REG_InitTypeDef *ADC_REG_InitStruct);
void        LL_ADC_REG_StructInit(LL_ADC_REG_InitTypeDef *ADC_REG_InitStruct);

/* ADC实例和注入组某些功能的初始化 */
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
