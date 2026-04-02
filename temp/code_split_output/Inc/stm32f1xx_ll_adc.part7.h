/**
  * @brief  辅助宏：根据内部温度传感器的ADC转换数据计算温度（单位：摄氏度）
  * @note   计算过程使用了温度传感器的典型值（请参阅器件数据手册）。
  * @note   计算公式：
  *           温度 = (TS_TYP_CALx_VOLT(uV) - TS_ADC_DATA * Conversion_uV)
  *                         / Avg_Slope + CALx_TEMP
  *           其中 TS_ADC_DATA      = ADC测量的温度传感器原始数据
  *                                   (单位：数字值)
  *                Avg_Slope        = 温度传感器斜率
  *                                   (单位：微伏/摄氏度)
  *                TS_TYP_CALx_VOLT = 温度为CALx_TEMP时的温度传感器数字值
  *                                   (单位：毫伏)
  *         注意：计算结果的有效性取决于当前器件的温度传感器特性是否与
  *                  数据手册中的典型值一致。
  *                  如果当前器件具备温度传感器校准值（即存在宏 __LL_ADC_CALC_TEMPERATURE()），
  *                  使用辅助宏 @ref __LL_ADC_CALC_TEMPERATURE() 计算温度会更准确。
  * @note   作为计算输入，必须定义模拟参考电压，因为它会影响ADC的LSB等效电压。
  * @note   模拟参考电压必须通过用户板级环境获知，或者可以通过ADC测量计算得出。
  * @note   ADC测量数据必须对应12位分辨率（满量程数字值4095）。
  *         如果不是这种情况，必须预先将数据重新缩放到等效的12位分辨率。
  * @param  __TEMPSENSOR_TYP_AVGSLOPE__   器件数据手册数据：温度传感器斜率典型值 (单位: uV/摄氏度)。
  *                                       在STM32F1上，请参考数据手册参数 "Avg_Slope"。
  * @param  __TEMPSENSOR_TYP_CALX_V__     器件数据手册数据：温度传感器电压典型值（在下面参数定义的温度和Vref+下）(单位: mV)。
  *                                       在STM32F1上，请参考数据手册参数 "V25"。
  * @param  __TEMPSENSOR_CALX_TEMP__      器件数据手册数据：温度传感器电压（见上参数）所对应的温度 (单位: mV)
  * @param  __VREFANALOG_VOLTAGE__        模拟电压参考电压 (单位: mV)
  * @param  __TEMPSENSOR_ADC_DATA__       内部温度传感器的ADC转换数据 (单位: 数字值)。
  * @param  __ADC_RESOLUTION__            测量内部温度传感器电压时的ADC分辨率。
  *         该参数可以是以下值之一：
  *         @arg @ref LL_ADC_RESOLUTION_12B
  * @retval 温度 (单位: 摄氏度)
  */
#define __LL_ADC_CALC_TEMPERATURE_TYP_PARAMS(__TEMPSENSOR_TYP_AVGSLOPE__,\
                                             __TEMPSENSOR_TYP_CALX_V__,\
                                             __TEMPSENSOR_CALX_TEMP__,\
                                             __VREFANALOG_VOLTAGE__,\
                                             __TEMPSENSOR_ADC_DATA__,\
                                             __ADC_RESOLUTION__)               \
  ((( (                                                                        \
       (int32_t)(((__TEMPSENSOR_TYP_CALX_V__))                                 \
                 * 1000)                                                       \
       -                                                                       \
       (int32_t)((((__TEMPSENSOR_ADC_DATA__) * (__VREFANALOG_VOLTAGE__))       \
                  / __LL_ADC_DIGITAL_SCALE(__ADC_RESOLUTION__))                \
                 * 1000)                                                       \
      )                                                                        \
    ) / (__TEMPSENSOR_TYP_AVGSLOPE__)                                          \
   ) + (__TEMPSENSOR_CALX_TEMP__)                                              \
  )

/**
  * @}
  */

/**
  * @}
  */


/* Exported functions --------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Functions ADC导出函数
  * @{
  */

/** @defgroup ADC_LL_EF_DMA_Management ADC DMA管理
  * @{
  */
/* 注意：用于设置DMA传输的LL ADC函数位于ADC实例、组和多模（如果可用）的配置部分：*/
/*       @ref LL_ADC_REG_SetDMATransfer(), ...                                */

/**
  * @brief  辅助配置从ADC进行DMA传输的函数：从ADC实例检索ADC寄存器地址
  *         以及旨在（最常）用于DMA传输的ADC寄存器列表。
  * @note   这些ADC寄存器是数据寄存器：
  *         当ADC转换数据在ADC数据寄存器中可用时，ADC会生成DMA传输请求。
  * @note   此宏旨在与LL DMA驱动程序一起使用，请参考函数 "LL_DMA_ConfigAddresses()"。
  *         示例：
  *           LL_DMA_ConfigAddresses(DMA1,
  *                                  LL_DMA_CHANNEL_1,
  *                                  LL_ADC_DMA_GetRegAddr(ADC1, LL_ADC_DMA_REG_REGULAR_DATA),
  *                                  (uint32_t)&< 数组或变量 >,
  *                                  LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
  * @note   对于具有多个ADC的器件：在多模模式下，某些器件使用ADC实例范围之外的不同数据寄存器
  *         （公共数据寄存器）。此宏管理此寄存器差异，只需将ADC实例设置为参数即可。
  * @note   在STM32F1上，只有ADC1和ADC3实例具有DMA传输功能，ADC2没有
  *         （并非所有器件都有ADC2和ADC3实例）。
  * @note   在STM32F1上，多模只能与ADC1和ADC2一起使用，不能与ADC3一起使用。
  *         因此，多模数据传输的相应参数只能与ADC1和ADC2一起使用。
  *         （并非所有器件都有ADC2和ADC3实例）。
  * @rmtoll DR       DATA           LL_ADC_DMA_GetRegAddr
  * @param  ADCx ADC实例
  * @param  Register 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_DMA_REG_REGULAR_DATA
  *         @arg @ref LL_ADC_DMA_REG_REGULAR_DATA_MULTI (1)
  *         
  *         (1) 适用于具有多个ADC实例的器件。
  * @retval ADC寄存器地址
  */
#if defined(ADC_MULTIMODE_SUPPORT)
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  uint32_t data_reg_addr = 0U;
  
  if (Register == LL_ADC_DMA_REG_REGULAR_DATA)
  {
    /* 检索寄存器DR的地址 */
    data_reg_addr = (uint32_t)&(ADCx->DR);
  }
  else /* (Register == LL_ADC_DMA_REG_REGULAR_DATA_MULTI) */
  {
    /* 检索多模数据寄存器的地址 */
    data_reg_addr = (uint32_t)&(ADC12_COMMON->DR);
  }
  
  return data_reg_addr;
}
#else
__STATIC_INLINE uint32_t LL_ADC_DMA_GetRegAddr(ADC_TypeDef *ADCx, uint32_t Register)
{
  /* 检索寄存器DR的地址 */
  return (uint32_t)&(ADCx->DR);
}
#endif

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Common 配置ADC层级范围：多个ADC实例的通用设置
  * @{
  */

/**
  * @brief  设置多个ADC的通用参数：内部通道的测量路径
  *         (内部参考电压VrefInt, 温度传感器, ...)。
  * @note   可以选择一个或多个值。
  *         示例: (LL_ADC_PATH_INTERNAL_VREFINT |
  *                   LL_ADC_PATH_INTERNAL_TEMPSENSOR)
  * @note   内部通道测量路径的稳定时间：
  *         使能内部路径后，在启动ADC转换之前，
  *         需要一段延迟时间用于内部参考电压和
  *         温度传感器的稳定。
  *         请参考器件数据手册。
  *         请参考常量 @ref LL_ADC_DELAY_TEMPSENSOR_STAB_US。
  * @note   ADC内部通道采样时间约束：
  *         对于内部通道的ADC转换，
  *         需要满足最小采样时间要求。
  *         请参考器件数据手册。
  * @rmtoll CR2      TSVREFE        LL_ADC_SetCommonPathInternalCh
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置，或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @param  PathInternal 此参数可以是以下值的组合：
  *         @arg @ref LL_ADC_PATH_INTERNAL_NONE
  *         @arg @ref LL_ADC_PATH_INTERNAL_VREFINT
  *         @arg @ref LL_ADC_PATH_INTERNAL_TEMPSENSOR
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON, uint32_t PathInternal)
{
  /* 修改CR2寄存器的TSVREFE位，配置内部通道路径 */
  MODIFY_REG(ADCxy_COMMON->CR2, (ADC_CR2_TSVREFE), PathInternal);
}

/**
  * @brief  获取多个ADC的通用参数：内部通道的测量路径
  *         (内部参考电压VrefInt, 温度传感器, ...)。
  * @note   可以选择一个或多个值。
  *         示例: (LL_ADC_PATH_INTERNAL_VREFINT |
  *                   LL_ADC_PATH_INTERNAL_TEMPSENSOR)
  * @rmtoll CR2      TSVREFE        LL_ADC_GetCommonPathInternalCh
  * @param  ADCxy_COMMON ADC通用实例
  *         (可以直接从CMSIS定义设置，或使用辅助宏 @ref __LL_ADC_COMMON_INSTANCE() )
  * @retval 返回值可以是以下值的组合：
  *         @arg @ref LL_ADC_PATH_INTERNAL_NONE
  *         @arg @ref LL_ADC_PATH_INTERNAL_VREFINT
  *         @arg @ref LL_ADC_PATH_INTERNAL_TEMPSENSOR
  */
__STATIC_INLINE uint32_t LL_ADC_GetCommonPathInternalCh(ADC_Common_TypeDef *ADCxy_COMMON)
{
  /* 读取CR2寄存器的TSVREFE位，获取当前配置的内部通道路径 */
  return (uint32_t)(READ_BIT(ADCxy_COMMON->CR2, ADC_CR2_TSVREFE));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Instance 配置ADC层级范围：ADC实例
  * @{
  */

/**
  * @brief  设置ADC转换数据对齐方式。
  * @note   请参考参考手册中关于对齐格式与ADC分辨率的依赖关系。
  * @rmtoll CR2      ALIGN          LL_ADC_SetDataAlignment
  * @param  ADCx ADC实例
  * @param  DataAlignment 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_DATA_ALIGN_RIGHT 右对齐
  *         @arg @ref LL_ADC_DATA_ALIGN_LEFT 左对齐
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetDataAlignment(ADC_TypeDef *ADCx, uint32_t DataAlignment)
{
  /* 修改CR2寄存器的ALIGN位，设置数据对齐方式 */
  MODIFY_REG(ADCx->CR2, ADC_CR2_ALIGN, DataAlignment);
}

/**
  * @brief  获取ADC转换数据对齐方式。
  * @note   请参考参考手册中关于对齐格式与ADC分辨率的依赖关系。
  * @rmtoll CR2      ALIGN          LL_ADC_SetDataAlignment
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_DATA_ALIGN_RIGHT
  *         @arg @ref LL_ADC_DATA_ALIGN_LEFT
  */
__STATIC_INLINE uint32_t LL_ADC_GetDataAlignment(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的ALIGN位，获取当前数据对齐方式 */
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_ALIGN));
}

/**
  * @brief  设置所有ADC组（规则组、注入组）的ADC序列器扫描模式。
  * @note  根据序列器扫描模式：
  *         - 如果禁用：ADC转换在单次转换模式下执行
  *           （转换一个通道，即在秩1中定义的通道）。
  *           所有ADC组的序列器配置（序列器扫描长度等）将被忽略：相当于
  *           扫描长度为1个秩。
  *         - 如果使能：ADC转换在序列转换模式下执行，
  *           根据每个ADC组的序列器配置（序列器扫描长度等）。
  *           请参考函数 @ref LL_ADC_REG_SetSequencerLength()
  *           和函数 @ref LL_ADC_INJ_SetSequencerLength()。
  * @rmtoll CR1      SCAN           LL_ADC_SetSequencersScanMode
  * @param  ADCx ADC实例
  * @param  ScanMode 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_SEQ_SCAN_DISABLE 禁用扫描模式
  *         @arg @ref LL_ADC_SEQ_SCAN_ENABLE 使能扫描模式
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_SetSequencersScanMode(ADC_TypeDef *ADCx, uint32_t ScanMode)
{
  /* 修改CR1寄存器的SCAN位，设置扫描模式 */
  MODIFY_REG(ADCx->CR1, ADC_CR1_SCAN, ScanMode);
}

/**
  * @brief  获取所有ADC组（规则组、注入组）的ADC序列器扫描模式。
  * @note  根据序列器扫描模式：
  *         - 如果禁用：ADC转换在单次转换模式下执行
  *           （转换一个通道，即在秩1中定义的通道）。
  *           所有ADC组的序列器配置（序列器扫描长度等）将被忽略：相当于
  *           扫描长度为1个秩。
  *         - 如果使能：ADC转换在序列转换模式下执行，
  *           根据每个ADC组的序列器配置（序列器扫描长度等）。
  *           请参考函数 @ref LL_ADC_REG_SetSequencerLength()
  *           和函数 @ref LL_ADC_INJ_SetSequencerLength()。
  * @rmtoll CR1      SCAN           LL_ADC_GetSequencersScanMode
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_SEQ_SCAN_ENABLE
  */
__STATIC_INLINE uint32_t LL_ADC_GetSequencersScanMode(ADC_TypeDef *ADCx)
{
  /* 读取CR1寄存器的SCAN位，获取当前扫描模式状态 */
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_SCAN));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Group_Regular 配置ADC层级范围：规则组
  * @{
  */

/**
  * @brief  设置ADC规则组转换触发源：
  *         内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
  * @note   在此STM32系列上，外部触发设置为触发极性：上升沿
  *         （此STM32系列上唯一可用的触发极性）。
  * @note   来自定时器的触发源参数的可用性取决于所选器件上定时器的可用性。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_SetTriggerSource
  * @param  ADCx ADC实例
  * @param  TriggerSource 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_REG_TRIG_SOFTWARE 软件触发
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH3       (1)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH1       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM4_CH4       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (2)(4)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH3       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH3       (3)
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1, ADC2, ADC3（针对所选器件上可用的ADC实例）。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1, ADC2（针对所选器件上可用的ADC实例）。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3（针对所选器件上可用的ADC实例）。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度器件。必须在顶层重映射触发（请参考AFIO外设）。
  * @retval 无
  */
__STATIC_INLINE void LL_ADC_REG_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
/* 注意：在此STM32系列上，ADC规则组外部触发边沿用于执行ADC转换启动。        */
/*       此函数不设置外部触发边沿。                    */
/*       此功能使用函数设置：                                   */
/*       @ref LL_ADC_REG_StartConversionExtTrig().                            */
  /* 修改CR2寄存器的EXTSEL位，设置触发源 */
  MODIFY_REG(ADCx->CR2, ADC_CR2_EXTSEL, (TriggerSource & ADC_CR2_EXTSEL));
}

/**
  * @brief  获取ADC规则组转换触发源：
  *         内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
  * @note   要确定规则组触发源是内部（软件启动）还是外部，而不需要
  *         详细了解选择了哪个外设作为外部触发，
  *         （相当于 
  *         "if(LL_ADC_REG_GetTriggerSource(ADC1) == LL_ADC_REG_TRIG_SOFTWARE)"）
  *         请使用函数 @ref LL_ADC_REG_IsTriggerSourceSWStart。
  * @note   来自定时器的触发源参数的可用性取决于所选器件上定时器的可用性。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_GetTriggerSource
  * @param  ADCx ADC实例
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_REG_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH3       (1)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH1       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM1_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH2       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM4_CH4       (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (2)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (2)(4)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM3_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM2_CH3       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH1       (3)
  *         @arg @ref LL_ADC_REG_TRIG_EXT_TIM5_CH3       (3)
  *         
  *         (1) 在STM32F1上，参数适用于所有ADC实例：ADC1, ADC2, ADC3（针对所选器件上可用的ADC实例）。\n
  *         (2) 在STM32F1上，参数仅适用于ADC实例：ADC1, ADC2（针对所选器件上可用的ADC实例）。\n
  *         (3) 在STM32F1上，参数仅适用于ADC实例：ADC3（针对所选器件上可用的ADC实例）。\n
  *         (4) 在STM32F1上，参数仅适用于高密度和XL密度器件。必须在顶层重映射触发（请参考AFIO外设）。
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetTriggerSource(ADC_TypeDef *ADCx)
{
  /* 读取CR2寄存器的EXTSEL位，获取当前触发源配置 */
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_EXTSEL));
}

/**
  * @brief  获取ADC规则组转换触发源是内部（软件启动）还是外部。
  * @note   如果规则组触发源设置为外部触发，
  *         要确定选择了哪个外设作为外部触发，
  *         请使用函数 @ref LL_ADC_REG_GetTriggerSource()。
  * @rmtoll CR2      EXTSEL         LL_ADC_REG_IsTriggerSourceSWStart
  * @param  ADCx ADC实例
  * @retval 值 "0" 表示触发源为外部触发
  *         值 "1" 表示触发源为软件启动。
  */
__STATIC_INLINE uint32_t LL_ADC_REG_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  /* 判断EXTSEL位是否等于软件触发宏定义值 */
  return (READ_BIT(ADCx->CR2, ADC_CR2_EXTSEL) == (LL_ADC_REG_TRIG_SOFTWARE));
}

