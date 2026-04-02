/**
  * @brief  ADC规则组特性结构体定义。
  * @note   这些参数影响ADC范围：ADC规则组。
  *         请参考 @ref ADC_LL_EF_Configuration_ADC_Group_Regular 中的相应单元函数
  *         (带有前缀 "REG" 的函数)。
  * @note   通过函数 @ref LL_ADC_REG_Init() 设置这些参数的条件是ADC状态：
  *         ADC实例必须处于禁用状态。
  *         此条件适用于所有ADC特性，以提高效率并兼容所有STM32系列。
  *         但是，不同的特性可以在不同的ADC状态条件下设置
  *         (可以在ADC使能且无转换进行时设置，ADC使能且有转换进行时设置，...)
  *         每个特性随后可以通过单元函数进行更新，
  *         并且可能在ADC处于非禁用状态时进行，
  *         请参考每个函数的说明以了解设置的ADC状态条件。
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< 设置ADC规则组转换触发源：内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
                                             此参数可以是 @ref ADC_LL_EC_REG_TRIGGER_SOURCE 中的值
                                             @note 在此STM32系列上，外部触发设置为触发极性：上升沿
                                                   （此STM32系列上唯一可用的触发极性）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetTriggerSource() 进行修改。 */

  uint32_t SequencerLength;             /*!< 设置ADC规则组序列器长度。
                                             此参数可以是 @ref ADC_LL_EC_REG_SEQ_SCAN_LENGTH 中的值
                                             @note 如果禁用扫描模式（参考参数 'ADC_SequencersScanMode'），则忽略此参数。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetSequencerLength() 进行修改。 */

  uint32_t SequencerDiscont;            /*!< 设置ADC规则组序列器间断模式：序列细分并在每个选定数量的等级中断扫描转换。
                                             此参数可以是 @ref ADC_LL_EC_REG_SEQ_DISCONT_MODE 中的值
                                             @note 此参数仅在启用规则组序列器时有效
                                                   （扫描长度为2个或更多等级）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetSequencerDiscont() 进行修改。 */

  uint32_t ContinuousMode;              /*!< 设置ADC规则组上的连续转换模式，是以单次模式执行ADC转换（每次触发一次转换）还是以连续模式执行（在第一次触发后，随后的转换自动连续启动）。
                                             此参数可以是 @ref ADC_LL_EC_REG_CONTINUOUS_MODE 中的值
                                             注意：不可能同时启用ADC规则组连续模式和间断模式。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetContinuousMode() 进行修改。 */

  uint32_t DMATransfer;                 /*!< 设置ADC规则组转换数据传输：无传输或通过DMA传输，以及DMA请求模式。
                                             此参数可以是 @ref ADC_LL_EC_REG_DMA_TRANSFER 中的值
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_REG_SetDMATransfer() 进行修改。 */

} LL_ADC_REG_InitTypeDef;

/**
  * @brief  ADC注入组特性结构体定义。
  * @note   这些参数影响ADC范围：ADC注入组。
  *         请参考 @ref ADC_LL_EF_Configuration_ADC_Group_Regular 中的相应单元函数
  *         (带有前缀 "INJ" 的函数)。
  * @note   通过函数 @ref LL_ADC_INJ_Init() 设置这些参数的条件是ADC状态：
  *         ADC实例必须处于禁用状态。
  *         此条件适用于所有ADC特性，以提高效率并兼容所有STM32系列。
  *         但是，不同的特性可以在不同的ADC状态条件下设置
  *         (可以在ADC使能且无转换进行时设置，ADC使能且有转换进行时设置，...)
  *         每个特性随后可以通过单元函数进行更新，
  *         并且可能在ADC处于非禁用状态时进行，
  *         请参考每个函数的说明以了解设置的ADC状态条件。
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< 设置ADC注入组转换触发源：内部（软件启动）或来自外部IP（定时器事件，外部中断线）。
                                             此参数可以是 @ref ADC_LL_EC_INJ_TRIGGER_SOURCE 中的值
                                             @note 在此STM32系列上，外部触发设置为触发极性：上升沿
                                                   （此STM32系列上唯一可用的触发极性）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetTriggerSource() 进行修改。 */

  uint32_t SequencerLength;             /*!< 设置ADC注入组序列器长度。
                                             此参数可以是 @ref ADC_LL_EC_INJ_SEQ_SCAN_LENGTH 中的值
                                             @note 如果禁用扫描模式（参考参数 'ADC_SequencersScanMode'），则忽略此参数。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetSequencerLength() 进行修改。 */

  uint32_t SequencerDiscont;            /*!< 设置ADC注入组序列器间断模式：序列细分并在每个选定数量的等级中断扫描转换。
                                             此参数可以是 @ref ADC_LL_EC_INJ_SEQ_DISCONT_MODE 中的值
                                             @note 此参数仅在启用注入组序列器时有效
                                                   （扫描长度为2个或更多等级）。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetSequencerDiscont() 进行修改。 */

  uint32_t TrigAuto;                    /*!< 设置ADC注入组转换触发：独立触发或来自ADC规则组。
                                             此参数可以是 @ref ADC_LL_EC_INJ_TRIG_AUTO 中的值
                                             注意：如果注入触发源设置为外部触发，则此参数必须设置为独立触发。
                                             
                                             此特性随后可以使用单元函数 @ref LL_ADC_INJ_SetTrigAuto() 进行修改。 */

} LL_ADC_INJ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* 导出常量 ------------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Constants ADC导出常量
  * @{
  */

/** @defgroup ADC_LL_EC_FLAG ADC标志位
  * @brief    标志位定义，可与 LL_ADC_ReadReg 函数一起使用
  * @{
  */
#define LL_ADC_FLAG_STRT                   ADC_SR_STRT        /*!< ADC标志：ADC规则组转换开始 */
#define LL_ADC_FLAG_EOS                    ADC_SR_EOC         /*!< ADC标志：ADC规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”） */
#define LL_ADC_FLAG_JSTRT                  ADC_SR_JSTRT       /*!< ADC标志：ADC注入组转换开始 */
#define LL_ADC_FLAG_JEOS                   ADC_SR_JEOC        /*!< ADC标志：ADC注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”） */
#define LL_ADC_FLAG_AWD1                   ADC_SR_AWD         /*!< ADC标志：ADC模拟看门狗1 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_FLAG_EOS_MST                ADC_SR_EOC         /*!< ADC标志：ADC多模式主模式规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”） */
#define LL_ADC_FLAG_EOS_SLV                ADC_SR_EOC         /*!< ADC标志：ADC多模式从模式规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”）（在STM32F1上，此标志必须从ADC实例从机读取：ADC2） */
#define LL_ADC_FLAG_JEOS_MST               ADC_SR_JEOC        /*!< ADC标志：ADC多模式主模式注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”） */
#define LL_ADC_FLAG_JEOS_SLV               ADC_SR_JEOC        /*!< ADC标志：ADC多模式从模式注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”）（在STM32F1上，此标志必须从ADC实例从机读取：ADC2） */
#define LL_ADC_FLAG_AWD1_MST               ADC_SR_AWD         /*!< ADC标志：ADC多模式主模式ADC主机的模拟看门狗1 */
#define LL_ADC_FLAG_AWD1_SLV               ADC_SR_AWD         /*!< ADC标志：ADC多模式从模式ADC从机的模拟看门狗1（在STM32F1上，此标志必须从ADC实例从机读取：ADC2） */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_IT ADC中断配置（中断使能或禁用）
  * @brief    中断定义，可与 LL_ADC_ReadReg 和 LL_ADC_WriteReg 函数一起使用
  * @{
  */
#define LL_ADC_IT_EOS                      ADC_CR1_EOCIE      /*!< ADC中断：ADC规则组序列转换结束（注意：在此STM32系列上，没有ADC规则组单元转换结束标志。标记为“EOC”的标志对应于其他STM32系列中的标志“EOS”） */
#define LL_ADC_IT_JEOS                     ADC_CR1_JEOCIE     /*!< ADC中断：ADC注入组序列转换结束（注意：在此STM32系列上，没有ADC注入组单元转换结束标志。标记为“JEOC”的标志对应于其他STM32系列中的标志“JEOS”） */
#define LL_ADC_IT_AWD1                     ADC_CR1_AWDIE      /*!< ADC中断：ADC模拟看门狗1 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REGISTERS  符合特定用途的ADC寄存器
  * @{
  */
/* 旨在（最常）与DMA传输一起使用的ADC寄存器列表。             */
/* 请参考函数 @ref LL_ADC_DMA_GetRegAddr()。                   */
#define LL_ADC_DMA_REG_REGULAR_DATA          0x00000000U   /* ADC规则组转换数据寄存器（对应于寄存器DR），用于配置为独立模式的ADC。无DMA传输时，通过LL函数 @ref LL_ADC_REG_ReadConversionData32() 和其他函数 @ref LL_ADC_REG_ReadConversionDatax() 访问的寄存器 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_DMA_REG_REGULAR_DATA_MULTI    0x00000001U   /* ADC规则组转换数据寄存器（对应于寄存器CDR），用于配置为多模式的ADC（适用于具有多个ADC实例的STM32设备）。无DMA传输时，通过LL函数 @ref LL_ADC_REG_ReadMultiConversionData32() 访问的寄存器 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_COMMON_PATH_INTERNAL  ADC通用 - 内部通道测量路径
  * @{
  */
/* 注意：可能还有其他通往内部通道的测量路径可用        */
/*       （连接到其他外设）。                                  */
/*       如果它们未在下面列出，则它们不需要任何特定的       */
/*       路径使能。在这种情况下，访问测量路径是通过        */
/*       选择相应的ADC内部通道来完成的。            */
#define LL_ADC_PATH_INTERNAL_NONE          0x00000000U            /*!< ADC测量路径全部禁用 */
#define LL_ADC_PATH_INTERNAL_VREFINT       (ADC_CR2_TSVREFE)      /*!< ADC测量路径通往内部通道VrefInt（内部参考电压） */
#define LL_ADC_PATH_INTERNAL_TEMPSENSOR    (ADC_CR2_TSVREFE)      /*!< ADC测量路径通往内部通道温度传感器 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_RESOLUTION  ADC实例 - 分辨率
  * @{
  */
#define LL_ADC_RESOLUTION_12B              0x00000000U                         /*!< ADC分辨率12位 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_DATA_ALIGN  ADC实例 - 数据对齐
  * @{
  */
#define LL_ADC_DATA_ALIGN_RIGHT            0x00000000U            /*!< ADC转换数据对齐：右对齐（对齐在数据寄存器LSB位0）*/
#define LL_ADC_DATA_ALIGN_LEFT             (ADC_CR2_ALIGN)        /*!< ADC转换数据对齐：左对齐（对齐在数据寄存器MSB位15）*/
/**
  * @}
  */

/** @defgroup ADC_LL_EC_SCAN_SELECTION ADC实例 - 扫描选择
  * @{
  */
#define LL_ADC_SEQ_SCAN_DISABLE            0x00000000U    /*!< ADC转换以单元转换模式执行（转换一个通道，即在等级1中定义的通道）。规则组和注入组序列器的配置（序列长度等）被忽略：相当于长度为1个等级。*/
#define LL_ADC_SEQ_SCAN_ENABLE             (ADC_CR1_SCAN) /*!< ADC转换以序列转换模式执行，根据规则组和注入组序列器的配置（序列长度等）。 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_GROUPS  ADC实例 - 组
  * @{
  */
#define LL_ADC_GROUP_REGULAR               0x00000001U   /*!< ADC规则组（适用于所有STM32设备） */
#define LL_ADC_GROUP_INJECTED              0x00000002U   /*!< ADC注入组（并非适用于所有STM32设备）*/
#define LL_ADC_GROUP_REGULAR_INJECTED      0x00000003U   /*!< ADC规则组和注入组两者 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL  ADC实例 - 通道号
  * @{
  */
#define LL_ADC_CHANNEL_0                   (ADC_CHANNEL_0_NUMBER  | ADC_CHANNEL_0_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN0  */
#define LL_ADC_CHANNEL_1                   (ADC_CHANNEL_1_NUMBER  | ADC_CHANNEL_1_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN1  */
#define LL_ADC_CHANNEL_2                   (ADC_CHANNEL_2_NUMBER  | ADC_CHANNEL_2_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN2  */
#define LL_ADC_CHANNEL_3                   (ADC_CHANNEL_3_NUMBER  | ADC_CHANNEL_3_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN3  */
#define LL_ADC_CHANNEL_4                   (ADC_CHANNEL_4_NUMBER  | ADC_CHANNEL_4_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN4  */
#define LL_ADC_CHANNEL_5                   (ADC_CHANNEL_5_NUMBER  | ADC_CHANNEL_5_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN5  */
#define LL_ADC_CHANNEL_6                   (ADC_CHANNEL_6_NUMBER  | ADC_CHANNEL_6_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN6  */
#define LL_ADC_CHANNEL_7                   (ADC_CHANNEL_7_NUMBER  | ADC_CHANNEL_7_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN7  */
#define LL_ADC_CHANNEL_8                   (ADC_CHANNEL_8_NUMBER  | ADC_CHANNEL_8_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN8  */
#define LL_ADC_CHANNEL_9                   (ADC_CHANNEL_9_NUMBER  | ADC_CHANNEL_9_SMP)  /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN9  */
#define LL_ADC_CHANNEL_10                  (ADC_CHANNEL_10_NUMBER | ADC_CHANNEL_10_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN10 */
#define LL_ADC_CHANNEL_11                  (ADC_CHANNEL_11_NUMBER | ADC_CHANNEL_11_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN11 */
#define LL_ADC_CHANNEL_12                  (ADC_CHANNEL_12_NUMBER | ADC_CHANNEL_12_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN12 */
#define LL_ADC_CHANNEL_13                  (ADC_CHANNEL_13_NUMBER | ADC_CHANNEL_13_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN13 */
#define LL_ADC_CHANNEL_14                  (ADC_CHANNEL_14_NUMBER | ADC_CHANNEL_14_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN14 */
#define LL_ADC_CHANNEL_15                  (ADC_CHANNEL_15_NUMBER | ADC_CHANNEL_15_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN15 */
#define LL_ADC_CHANNEL_16                  (ADC_CHANNEL_16_NUMBER | ADC_CHANNEL_16_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN16 */
#define LL_ADC_CHANNEL_17                  (ADC_CHANNEL_17_NUMBER | ADC_CHANNEL_17_SMP) /*!< ADC外部通道（连接到GPIO引脚的通道）ADCx_IN17 */
#define LL_ADC_CHANNEL_VREFINT             (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC内部通道连接到VrefInt：内部参考电压。在STM32F1上，ADC通道仅在ADC实例上可用：ADC1。 */
#define LL_ADC_CHANNEL_TEMPSENSOR          (LL_ADC_CHANNEL_16 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC内部通道连接到温度传感器。 */
/**
  * @}
  */
