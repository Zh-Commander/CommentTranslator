/**
  * @brief  Structure definition of some features of ADC group regular.
  *         ADC 规则组部分特性结构体定义。
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         这些参数影响 ADC 范围：ADC 规则组。
  *         Refer to corresponding unitary functions into
  *         请参阅 @ref ADC_LL_EF_Configuration_ADC_Group_Regular 中的相应独立功能函数
  *         @ref ADC_LL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "REG").
  *         (带有前缀 "REG" 的函数)。
  * @note   The setting of these parameters by function @ref LL_ADC_REG_Init()
  *         通过函数 @ref LL_ADC_REG_Init() 设置这些参数的条件：
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         ADC 实例必须处于禁用状态。
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all STM32 families. However, the different
  *         features can be set under different ADC state conditions
  *         此条件适用于所有 ADC 特性，以提高效率和兼容性。
  *         但是，不同的特性可以在不同的 ADC 状态条件下设置
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         (例如：可在 ADC 使能但无转换进行时设置，或 ADC 使能且有转换进行时设置等)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  *         每个特性随后都可以通过独立函数进行更新，并且可能在 ADC 处于非禁用状态时进行，
  *         具体请参阅每个函数的描述中关于 ADC 状态条件的说明。
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< Set ADC group regular conversion trigger source: internal (SW start) or from external IP (timer event, external interrupt line).
                                             设置 ADC 规则组转换触发源：内部（软件启动）或来自外部 IP（定时器事件，外部中断线）。
                                             This parameter can be a value of @ref ADC_LL_EC_REG_TRIGGER_SOURCE
                                             此参数可取值为 @ref ADC_LL_EC_REG_TRIGGER_SOURCE
                                             @note On this STM32 series, external trigger is set with trigger polarity: rising edge
                                                   (only trigger polarity available on this STM32 series).
                                             注意：在此 STM32 系列上，外部触发设置为上升沿触发极性
                                                   （此 STM32 系列仅支持此触发极性）。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetTriggerSource(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_REG_SetTriggerSource() 进行修改。

  uint32_t SequencerLength;             /*!< Set ADC group regular sequencer length.
                                             设置 ADC 规则组序列器长度。
                                             This parameter can be a value of @ref ADC_LL_EC_REG_SEQ_SCAN_LENGTH
                                             此参数可取值为 @ref ADC_LL_EC_REG_SEQ_SCAN_LENGTH
                                             @note This parameter is discarded if scan mode is disabled (refer to parameter 'ADC_SequencersScanMode').
                                             注意：如果禁用了扫描模式（请参阅参数 'ADC_SequencersScanMode'），则此参数将被忽略。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetSequencerLength(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_REG_SetSequencerLength() 进行修改。

  uint32_t SequencerDiscont;            /*!< Set ADC group regular sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks.
                                             设置 ADC 规则组序列器间断模式：序列被细分，每选定的等级数中断一次扫描转换。
                                             This parameter can be a value of @ref ADC_LL_EC_REG_SEQ_DISCONT_MODE
                                             此参数可取值为 @ref ADC_LL_EC_REG_SEQ_DISCONT_MODE
                                             @note This parameter has an effect only if group regular sequencer is enabled
                                                   (scan length of 2 ranks or more).
                                             注意：此参数仅在规则组序列器使能时有效（扫描长度为 2 个或更多等级）。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetSequencerDiscont(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_REG_SetSequencerDiscont() 进行修改。

  uint32_t ContinuousMode;              /*!< Set ADC continuous conversion mode on ADC group regular, whether ADC conversions are performed in single mode (one conversion per trigger) or in continuous mode (after the first trigger, following conversions launched successively automatically).
                                             设置 ADC 规则组的连续转换模式，即 ADC 转换是单次模式（每次触发转换一次）还是连续模式（第一次触发后，后续转换自动连续启动）。
                                             This parameter can be a value of @ref ADC_LL_EC_REG_CONTINUOUS_MODE
                                             此参数可取值为 @ref ADC_LL_EC_REG_CONTINUOUS_MODE
                                             Note: It is not possible to enable both ADC group regular continuous mode and discontinuous mode.
                                             注意：不能同时使能 ADC 规则组连续模式和间断模式。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetContinuousMode(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_REG_SetContinuousMode() 进行修改。

  uint32_t DMATransfer;                 /*!< Set ADC group regular conversion data transfer: no transfer or transfer by DMA, and DMA requests mode.
                                             设置 ADC 规则组转换数据传输：无传输或通过 DMA 传输，以及 DMA 请求模式。
                                             This parameter can be a value of @ref ADC_LL_EC_REG_DMA_TRANSFER
                                             此参数可取值为 @ref ADC_LL_EC_REG_DMA_TRANSFER
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetDMATransfer(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_REG_SetDMATransfer() 进行修改。

} LL_ADC_REG_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group injected.
  *         ADC 注入组部分特性结构体定义。
  * @note   These parameters have an impact on ADC scope: ADC group injected.
  *         这些参数影响 ADC 范围：ADC 注入组。
  *         Refer to corresponding unitary functions into
  *         请参阅 @ref ADC_LL_EF_Configuration_ADC_Group_Regular 中的相应独立功能函数
  *         @ref ADC_LL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "INJ").
  *         (带有前缀 "INJ" 的函数)。
  * @note   The setting of these parameters by function @ref LL_ADC_INJ_Init()
  *         通过函数 @ref LL_ADC_INJ_Init() 设置这些参数的条件：
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         ADC 实例必须处于禁用状态。
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all STM32 families. However, the different
  *         features can be set under different ADC state conditions
  *         此条件适用于所有 ADC 特性，以提高效率和兼容性。
  *         但是，不同的特性可以在不同的 ADC 状态条件下设置
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         (例如：可在 ADC 使能但无转换进行时设置，或 ADC 使能且有转换进行时设置等)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  *         每个特性随后都可以通过独立函数进行更新，并且可能在 ADC 处于非禁用状态时进行，
  *         具体请参阅每个函数的描述中关于 ADC 状态条件的说明。
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< Set ADC group injected conversion trigger source: internal (SW start) or from external IP (timer event, external interrupt line).
                                             设置 ADC 注入组转换触发源：内部（软件启动）或来自外部 IP（定时器事件，外部中断线）。
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_TRIGGER_SOURCE
                                             此参数可取值为 @ref ADC_LL_EC_INJ_TRIGGER_SOURCE
                                             @note On this STM32 series, external trigger is set with trigger polarity: rising edge
                                                   (only trigger polarity available on this STM32 series).
                                             注意：在此 STM32 系列上，外部触发设置为上升沿触发极性
                                                   （此 STM32 系列仅支持此触发极性）。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetTriggerSource(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_INJ_SetTriggerSource() 进行修改。

  uint32_t SequencerLength;             /*!< Set ADC group injected sequencer length.
                                             设置 ADC 注入组序列器长度。
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_SEQ_SCAN_LENGTH
                                             此参数可取值为 @ref ADC_LL_EC_INJ_SEQ_SCAN_LENGTH
                                             @note This parameter is discarded if scan mode is disabled (refer to parameter 'ADC_SequencersScanMode').
                                             注意：如果禁用了扫描模式（请参阅参数 'ADC_SequencersScanMode'），则此参数将被忽略。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetSequencerLength(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_INJ_SetSequencerLength() 进行修改。

  uint32_t SequencerDiscont;            /*!< Set ADC group injected sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks.
                                             设置 ADC 注入组序列器间断模式：序列被细分，每选定的等级数中断一次扫描转换。
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_SEQ_DISCONT_MODE
                                             此参数可取值为 @ref ADC_LL_EC_INJ_SEQ_DISCONT_MODE
                                             @note This parameter has an effect only if group injected sequencer is enabled
                                                   (scan length of 2 ranks or more).
                                             注意：此参数仅在注入组序列器使能时有效（扫描长度为 2 个或更多等级）。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetSequencerDiscont(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_INJ_SetSequencerDiscont() 进行修改。

  uint32_t TrigAuto;                    /*!< Set ADC group injected conversion trigger: independent or from ADC group regular.
                                             设置 ADC 注入组转换触发：独立触发或来自 ADC 规则组触发。
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_TRIG_AUTO
                                             此参数可取值为 @ref ADC_LL_EC_INJ_TRIG_AUTO
                                             Note: This parameter must be set to set to independent trigger if injected trigger source is set to an external trigger. 
                                             注意：如果注入触发源设置为外部触发，则此参数必须设置为独立触发。
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetTrigAuto(). */
                                             // 此特性随后可使用独立函数 @ref LL_ADC_INJ_SetTrigAuto() 进行修改。

} LL_ADC_INJ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/* 导出常量 ------------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Constants ADC Exported Constants
  *         ADC 导出常量
  * @{
  */

/** @defgroup ADC_LL_EC_FLAG ADC flags
  *         ADC 标志位
  * @brief    Flags defines which can be used with LL_ADC_ReadReg function
  *           可与 LL_ADC_ReadReg 函数一起使用的标志位定义
  * @{
  */
#define LL_ADC_FLAG_STRT                   ADC_SR_STRT        /*!< ADC flag ADC group regular conversion start */
                                                              /*!< ADC 标志：ADC 规则组转换开始 */
#define LL_ADC_FLAG_EOS                    ADC_SR_EOC         /*!< ADC flag ADC group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) */
                                                              /*!< ADC 标志：ADC 规则组序列转换结束（注意：在此 STM32 系列上，没有规则组单一转换结束标志。
                                                                   标记为 "EOC" 的标志对应于其他 STM32 系列中的 "EOS" 标志） */
#define LL_ADC_FLAG_JSTRT                  ADC_SR_JSTRT       /*!< ADC flag ADC group injected conversion start */
                                                              /*!< ADC 标志：ADC 注入组转换开始 */
#define LL_ADC_FLAG_JEOS                   ADC_SR_JEOC        /*!< ADC flag ADC group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) */
                                                              /*!< ADC 标志：ADC 注入组序列转换结束（注意：在此 STM32 系列上，没有注入组单一转换结束标志。
                                                                   标记为 "JEOC" 的标志对应于其他 STM32 系列中的 "JEOS" 标志） */
#define LL_ADC_FLAG_AWD1                   ADC_SR_AWD         /*!< ADC flag ADC analog watchdog 1 */
                                                              /*!< ADC 标志：ADC 模拟看门狗 1 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_FLAG_EOS_MST                ADC_SR_EOC         /*!< ADC flag ADC multimode master group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) */
                                                              /*!< ADC 标志：ADC 多模式主设备规则组序列转换结束 */
#define LL_ADC_FLAG_EOS_SLV                ADC_SR_EOC         /*!< ADC flag ADC multimode slave group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) (on STM32F1, this flag must be read from ADC instance slave: ADC2) */
                                                              /*!< ADC 标志：ADC 多模式从设备规则组序列转换结束（在 STM32F1 上，此标志必须从 ADC 从设备实例 ADC2 读取） */
#define LL_ADC_FLAG_JEOS_MST               ADC_SR_JEOC        /*!< ADC flag ADC multimode master group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) */
                                                              /*!< ADC 标志：ADC 多模式主设备注入组序列转换结束 */
#define LL_ADC_FLAG_JEOS_SLV               ADC_SR_JEOC        /*!< ADC flag ADC multimode slave group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) (on STM32F1, this flag must be read from ADC instance slave: ADC2) */
                                                              /*!< ADC 标志：ADC 多模式从设备注入组序列转换结束（在 STM32F1 上，此标志必须从 ADC 从设备实例 ADC2 读取） */
#define LL_ADC_FLAG_AWD1_MST               ADC_SR_AWD         /*!< ADC flag ADC multimode master analog watchdog 1 of the ADC master */
                                                              /*!< ADC 标志：ADC 多模式主设备模拟看门狗 1 */
#define LL_ADC_FLAG_AWD1_SLV               ADC_SR_AWD         /*!< ADC flag ADC multimode slave analog watchdog 1 of the ADC slave (on STM32F1, this flag must be read from ADC instance slave: ADC2) */
                                                              /*!< ADC 标志：ADC 多模式从设备模拟看门狗 1（在 STM32F1 上，此标志必须从 ADC 从设备实例 ADC2 读取） */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_IT ADC interruptions for configuration (interruption enable or disable)
  *         ADC 中断配置（中断使能或禁用）
  * @brief    IT defines which can be used with LL_ADC_ReadReg and  LL_ADC_WriteReg functions
  *           可与 LL_ADC_ReadReg 和 LL_ADC_WriteReg 函数一起使用的中断定义
  * @{
  */
#define LL_ADC_IT_EOS                      ADC_CR1_EOCIE      /*!< ADC interruption ADC group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) */
                                                              /*!< ADC 中断：ADC 规则组序列转换结束 */
#define LL_ADC_IT_JEOS                     ADC_CR1_JEOCIE     /*!< ADC interruption ADC group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) */
                                                              /*!< ADC 中断：ADC 注入组序列转换结束 */
#define LL_ADC_IT_AWD1                     ADC_CR1_AWDIE      /*!< ADC interruption ADC analog watchdog 1 */
                                                              /*!< ADC 中断：ADC 模拟看门狗 1 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REGISTERS  ADC registers compliant with specific purpose
  *         符合特定用途的 ADC 寄存器
  * @{
  */
/* List of ADC registers intended to be used (most commonly) with             */
/* DMA transfer.                                                              */
/* 旨在（最常）与 DMA 传输一起使用的 ADC 寄存器列表。                            */
/* Refer to function @ref LL_ADC_DMA_GetRegAddr().                            */
/* 请参阅函数 @ref LL_ADC_DMA_GetRegAddr()。                                   */
#define LL_ADC_DMA_REG_REGULAR_DATA          0x00000000U   /* ADC group regular conversion data register (corresponding to register DR) to be used with ADC configured in independent mode. Without DMA transfer, register accessed by LL function @ref LL_ADC_REG_ReadConversionData32() and other functions @ref LL_ADC_REG_ReadConversionDatax() */
                                                          /* ADC 规则组转换数据寄存器（对应寄存器 DR），用于独立模式配置的 ADC。
                                                             无 DMA 传输时，可通过 LL 函数 @ref LL_ADC_REG_ReadConversionData32() 
                                                             和其他函数 @ref LL_ADC_REG_ReadConversionDatax() 访问 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_DMA_REG_REGULAR_DATA_MULTI    0x00000001U   /* ADC group regular conversion data register (corresponding to register CDR) to be used with ADC configured in multimode (available on STM32 devices with several ADC instances). Without DMA transfer, register accessed by LL function @ref LL_ADC_REG_ReadMultiConversionData32() */
                                                          /* ADC 规则组转换数据寄存器（对应寄存器 CDR），用于多模式配置的 ADC
                                                            （适用于具有多个 ADC 实例的 STM32 设备）。
                                                             无 DMA 传输时，可通过 LL 函数 @ref LL_ADC_REG_ReadMultiConversionData32() 访问 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_COMMON_PATH_INTERNAL  ADC common - Measurement path to internal channels
  *         ADC 公共 - 内部通道测量路径
  * @{
  */
/* Note: Other measurement paths to internal channels may be available        */
/*       (connections to other peripherals).                                  */
/* 注意：可能存在其他内部通道测量路径（连接到其他外设）。                          */
/*       If they are not listed below, they do not require any specific       */
/*       path enable. In this case, Access to measurement path is done        */
/*       only by selecting the corresponding ADC internal channel.            */
/*       如果未在下面列出，则它们不需要特定的路径使能。在这种情况下，访问测量路径   
         仅需选择相应的 ADC 内部通道。                                         */
#define LL_ADC_PATH_INTERNAL_NONE          0x00000000U            /*!< ADC measurement paths all disabled */
                                                                  /*!< ADC 测量路径全部禁用 */
#define LL_ADC_PATH_INTERNAL_VREFINT       (ADC_CR2_TSVREFE)      /*!< ADC measurement path to internal channel VrefInt */
                                                                  /*!< ADC 内部通道 VrefInt（内部参考电压）的测量路径 */
#define LL_ADC_PATH_INTERNAL_TEMPSENSOR    (ADC_CR2_TSVREFE)      /*!< ADC measurement path to internal channel temperature sensor */
                                                                  /*!< ADC 内部通道温度传感器的测量路径 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_RESOLUTION  ADC instance - Resolution
  *         ADC 实例 - 分辨率
  * @{
  */
#define LL_ADC_RESOLUTION_12B              0x00000000U                         /*!< ADC resolution 12 bits */
                                                                              /*!< ADC 分辨率 12 位 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_DATA_ALIGN  ADC instance - Data alignment
  *         ADC 实例 - 数据对齐方式
  * @{
  */
#define LL_ADC_DATA_ALIGN_RIGHT            0x00000000U            /*!< ADC conversion data alignment: right aligned (alignment on data register LSB bit 0)*/
                                                                  /*!< ADC 转换数据对齐：右对齐（对齐数据寄存器最低位 LSB 位 0）*/
#define LL_ADC_DATA_ALIGN_LEFT             (ADC_CR2_ALIGN)        /*!< ADC conversion data alignment: left aligned (alignment on data register MSB bit 15)*/
                                                                  /*!< ADC 转换数据对齐：左对齐（对齐数据寄存器最高位 MSB 位 15）*/
/**
  * @}
  */

/** @defgroup ADC_LL_EC_SCAN_SELECTION ADC instance - Scan selection
  *         ADC 实例 - 扫描选择
  * @{
  */
#define LL_ADC_SEQ_SCAN_DISABLE            0x00000000U    /*!< ADC conversion is performed in unitary conversion mode (one channel converted, that defined in rank 1). Configuration of both groups regular and injected sequencers (sequence length, ...) is discarded: equivalent to length of 1 rank.*/
                                                         /*!< ADC 转换在单一转换模式下执行（转换一个通道，即在等级 1 中定义的通道）。
                                                             规则组和注入组序列器的配置（序列长度等）将被忽略：相当于长度为 1 个等级。*/
#define LL_ADC_SEQ_SCAN_ENABLE             (ADC_CR1_SCAN) /*!< ADC conversions are performed in sequence conversions mode, according to configuration of both groups regular and injected sequencers (sequence length, ...). */
                                                         /*!< ADC 转换在序列转换模式下执行，根据规则组和注入组序列器的配置（序列长度等）。*/
/**
  * @}
  */

/** @defgroup ADC_LL_EC_GROUPS  ADC instance - Groups
  *         ADC 实例 - 组
  * @{
  */
#define LL_ADC_GROUP_REGULAR               0x00000001U   /*!< ADC group regular (available on all STM32 devices) */
                                                        /*!< ADC 规则组（所有 STM32 设备均可用）*/
#define LL_ADC_GROUP_INJECTED              0x00000002U   /*!< ADC group injected (not available on all STM32 devices)*/
                                                        /*!< ADC 注入组（并非所有 STM32 设备都可用）*/
#define LL_ADC_GROUP_REGULAR_INJECTED      0x00000003U   /*!< ADC both groups regular and injected */
                                                        /*!< ADC 规则组和注入组 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL  ADC instance - Channel number
  *         ADC 实例 - 通道编号
  * @{
  */
#define LL_ADC_CHANNEL_0                   (ADC_CHANNEL_0_NUMBER  | ADC_CHANNEL_0_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN0  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN0  */
#define LL_ADC_CHANNEL_1                   (ADC_CHANNEL_1_NUMBER  | ADC_CHANNEL_1_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN1  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN1  */
#define LL_ADC_CHANNEL_2                   (ADC_CHANNEL_2_NUMBER  | ADC_CHANNEL_2_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN2  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN2  */
#define LL_ADC_CHANNEL_3                   (ADC_CHANNEL_3_NUMBER  | ADC_CHANNEL_3_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN3  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN3  */
#define LL_ADC_CHANNEL_4                   (ADC_CHANNEL_4_NUMBER  | ADC_CHANNEL_4_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN4  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN4  */
#define LL_ADC_CHANNEL_5                   (ADC_CHANNEL_5_NUMBER  | ADC_CHANNEL_5_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN5  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN5  */
#define LL_ADC_CHANNEL_6                   (ADC_CHANNEL_6_NUMBER  | ADC_CHANNEL_6_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN6  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN6  */
#define LL_ADC_CHANNEL_7                   (ADC_CHANNEL_7_NUMBER  | ADC_CHANNEL_7_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN7  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN7  */
#define LL_ADC_CHANNEL_8                   (ADC_CHANNEL_8_NUMBER  | ADC_CHANNEL_8_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN8  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN8  */
#define LL_ADC_CHANNEL_9                   (ADC_CHANNEL_9_NUMBER  | ADC_CHANNEL_9_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN9  */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN9  */
#define LL_ADC_CHANNEL_10                  (ADC_CHANNEL_10_NUMBER | ADC_CHANNEL_10_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN10 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN10 */
#define LL_ADC_CHANNEL_11                  (ADC_CHANNEL_11_NUMBER | ADC_CHANNEL_11_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN11 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN11 */
#define LL_ADC_CHANNEL_12                  (ADC_CHANNEL_12_NUMBER | ADC_CHANNEL_12_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN12 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN12 */
#define LL_ADC_CHANNEL_13                  (ADC_CHANNEL_13_NUMBER | ADC_CHANNEL_13_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN13 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN13 */
#define LL_ADC_CHANNEL_14                  (ADC_CHANNEL_14_NUMBER | ADC_CHANNEL_14_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN14 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN14 */
#define LL_ADC_CHANNEL_15                  (ADC_CHANNEL_15_NUMBER | ADC_CHANNEL_15_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN15 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN15 */
#define LL_ADC_CHANNEL_16                  (ADC_CHANNEL_16_NUMBER | ADC_CHANNEL_16_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN16 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN16 */
#define LL_ADC_CHANNEL_17                  (ADC_CHANNEL_17_NUMBER | ADC_CHANNEL_17_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN17 */
                                                                                        /*!< ADC 外部通道（连接到 GPIO 引脚的通道）ADCx_IN17 */
#define LL_ADC_CHANNEL_VREFINT             (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC internal channel connected to VrefInt: Internal voltage reference. On STM32F1, ADC channel available only on ADC instance: ADC1. */
                                                                                            /*!< ADC 内部通道连接到 VrefInt：内部参考电压。
                                                                                                在 STM32F1 上，此 ADC 通道仅在 ADC 实例 ADC1 上可用。 */
#define LL_ADC_CHANNEL_TEMPSENSOR          (LL_ADC_CHANNEL_16 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC internal channel connected to Temperature sensor. */
                                                                                            /*!< ADC 内部通道连接到温度传感器。 */
/**
  * @}
  */
