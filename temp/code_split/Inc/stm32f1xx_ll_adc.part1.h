
/**
  * @brief  Structure definition of some features of ADC group regular.
  * @note   These parameters have an impact on ADC scope: ADC group regular.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_LL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "REG").
  * @note   The setting of these parameters by function @ref LL_ADC_REG_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all STM32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< Set ADC group regular conversion trigger source: internal (SW start) or from external IP (timer event, external interrupt line).
                                             This parameter can be a value of @ref ADC_LL_EC_REG_TRIGGER_SOURCE
                                             @note On this STM32 series, external trigger is set with trigger polarity: rising edge
                                                   (only trigger polarity available on this STM32 series).
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetTriggerSource(). */

  uint32_t SequencerLength;             /*!< Set ADC group regular sequencer length.
                                             This parameter can be a value of @ref ADC_LL_EC_REG_SEQ_SCAN_LENGTH
                                             @note This parameter is discarded if scan mode is disabled (refer to parameter 'ADC_SequencersScanMode').
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetSequencerLength(). */

  uint32_t SequencerDiscont;            /*!< Set ADC group regular sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks.
                                             This parameter can be a value of @ref ADC_LL_EC_REG_SEQ_DISCONT_MODE
                                             @note This parameter has an effect only if group regular sequencer is enabled
                                                   (scan length of 2 ranks or more).
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetSequencerDiscont(). */

  uint32_t ContinuousMode;              /*!< Set ADC continuous conversion mode on ADC group regular, whether ADC conversions are performed in single mode (one conversion per trigger) or in continuous mode (after the first trigger, following conversions launched successively automatically).
                                             This parameter can be a value of @ref ADC_LL_EC_REG_CONTINUOUS_MODE
                                             Note: It is not possible to enable both ADC group regular continuous mode and discontinuous mode.
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetContinuousMode(). */

  uint32_t DMATransfer;                 /*!< Set ADC group regular conversion data transfer: no transfer or transfer by DMA, and DMA requests mode.
                                             This parameter can be a value of @ref ADC_LL_EC_REG_DMA_TRANSFER
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_REG_SetDMATransfer(). */

} LL_ADC_REG_InitTypeDef;

/**
  * @brief  Structure definition of some features of ADC group injected.
  * @note   These parameters have an impact on ADC scope: ADC group injected.
  *         Refer to corresponding unitary functions into
  *         @ref ADC_LL_EF_Configuration_ADC_Group_Regular
  *         (functions with prefix "INJ").
  * @note   The setting of these parameters by function @ref LL_ADC_INJ_Init()
  *         is conditioned to ADC state:
  *         ADC instance must be disabled.
  *         This condition is applied to all ADC features, for efficiency
  *         and compatibility over all STM32 families. However, the different
  *         features can be set under different ADC state conditions
  *         (setting possible with ADC enabled without conversion on going,
  *         ADC enabled with conversion on going, ...)
  *         Each feature can be updated afterwards with a unitary function
  *         and potentially with ADC in a different state than disabled,
  *         refer to description of each function for setting
  *         conditioned to ADC state.
  */
typedef struct
{
  uint32_t TriggerSource;               /*!< Set ADC group injected conversion trigger source: internal (SW start) or from external IP (timer event, external interrupt line).
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_TRIGGER_SOURCE
                                             @note On this STM32 series, external trigger is set with trigger polarity: rising edge
                                                   (only trigger polarity available on this STM32 series).
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetTriggerSource(). */

  uint32_t SequencerLength;             /*!< Set ADC group injected sequencer length.
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_SEQ_SCAN_LENGTH
                                             @note This parameter is discarded if scan mode is disabled (refer to parameter 'ADC_SequencersScanMode').
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetSequencerLength(). */

  uint32_t SequencerDiscont;            /*!< Set ADC group injected sequencer discontinuous mode: sequence subdivided and scan conversions interrupted every selected number of ranks.
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_SEQ_DISCONT_MODE
                                             @note This parameter has an effect only if group injected sequencer is enabled
                                                   (scan length of 2 ranks or more).
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetSequencerDiscont(). */

  uint32_t TrigAuto;                    /*!< Set ADC group injected conversion trigger: independent or from ADC group regular.
                                             This parameter can be a value of @ref ADC_LL_EC_INJ_TRIG_AUTO
                                             Note: This parameter must be set to set to independent trigger if injected trigger source is set to an external trigger. 
                                             
                                             This feature can be modified afterwards using unitary function @ref LL_ADC_INJ_SetTrigAuto(). */

} LL_ADC_INJ_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_LL_EC_FLAG ADC flags
  * @brief    Flags defines which can be used with LL_ADC_ReadReg function
  * @{
  */
#define LL_ADC_FLAG_STRT                   ADC_SR_STRT        /*!< ADC flag ADC group regular conversion start */
#define LL_ADC_FLAG_EOS                    ADC_SR_EOC         /*!< ADC flag ADC group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) */
#define LL_ADC_FLAG_JSTRT                  ADC_SR_JSTRT       /*!< ADC flag ADC group injected conversion start */
#define LL_ADC_FLAG_JEOS                   ADC_SR_JEOC        /*!< ADC flag ADC group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) */
#define LL_ADC_FLAG_AWD1                   ADC_SR_AWD         /*!< ADC flag ADC analog watchdog 1 */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_FLAG_EOS_MST                ADC_SR_EOC         /*!< ADC flag ADC multimode master group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) */
#define LL_ADC_FLAG_EOS_SLV                ADC_SR_EOC         /*!< ADC flag ADC multimode slave group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) (on STM32F1, this flag must be read from ADC instance slave: ADC2) */
#define LL_ADC_FLAG_JEOS_MST               ADC_SR_JEOC        /*!< ADC flag ADC multimode master group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) */
#define LL_ADC_FLAG_JEOS_SLV               ADC_SR_JEOC        /*!< ADC flag ADC multimode slave group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) (on STM32F1, this flag must be read from ADC instance slave: ADC2) */
#define LL_ADC_FLAG_AWD1_MST               ADC_SR_AWD         /*!< ADC flag ADC multimode master analog watchdog 1 of the ADC master */
#define LL_ADC_FLAG_AWD1_SLV               ADC_SR_AWD         /*!< ADC flag ADC multimode slave analog watchdog 1 of the ADC slave (on STM32F1, this flag must be read from ADC instance slave: ADC2) */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_IT ADC interruptions for configuration (interruption enable or disable)
  * @brief    IT defines which can be used with LL_ADC_ReadReg and  LL_ADC_WriteReg functions
  * @{
  */
#define LL_ADC_IT_EOS                      ADC_CR1_EOCIE      /*!< ADC interruption ADC group regular end of sequence conversions (Note: on this STM32 series, there is no flag ADC group regular end of unitary conversion. Flag noted as "EOC" is corresponding to flag "EOS" in other STM32 families) */
#define LL_ADC_IT_JEOS                     ADC_CR1_JEOCIE     /*!< ADC interruption ADC group injected end of sequence conversions (Note: on this STM32 series, there is no flag ADC group injected end of unitary conversion. Flag noted as "JEOC" is corresponding to flag "JEOS" in other STM32 families) */
#define LL_ADC_IT_AWD1                     ADC_CR1_AWDIE      /*!< ADC interruption ADC analog watchdog 1 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REGISTERS  ADC registers compliant with specific purpose
  * @{
  */
/* List of ADC registers intended to be used (most commonly) with             */
/* DMA transfer.                                                              */
/* Refer to function @ref LL_ADC_DMA_GetRegAddr().                            */
#define LL_ADC_DMA_REG_REGULAR_DATA          0x00000000U   /* ADC group regular conversion data register (corresponding to register DR) to be used with ADC configured in independent mode. Without DMA transfer, register accessed by LL function @ref LL_ADC_REG_ReadConversionData32() and other functions @ref LL_ADC_REG_ReadConversionDatax() */
#if defined(ADC_MULTIMODE_SUPPORT)
#define LL_ADC_DMA_REG_REGULAR_DATA_MULTI    0x00000001U   /* ADC group regular conversion data register (corresponding to register CDR) to be used with ADC configured in multimode (available on STM32 devices with several ADC instances). Without DMA transfer, register accessed by LL function @ref LL_ADC_REG_ReadMultiConversionData32() */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_COMMON_PATH_INTERNAL  ADC common - Measurement path to internal channels
  * @{
  */
/* Note: Other measurement paths to internal channels may be available        */
/*       (connections to other peripherals).                                  */
/*       If they are not listed below, they do not require any specific       */
/*       path enable. In this case, Access to measurement path is done        */
/*       only by selecting the corresponding ADC internal channel.            */
#define LL_ADC_PATH_INTERNAL_NONE          0x00000000U            /*!< ADC measurement paths all disabled */
#define LL_ADC_PATH_INTERNAL_VREFINT       (ADC_CR2_TSVREFE)      /*!< ADC measurement path to internal channel VrefInt */
#define LL_ADC_PATH_INTERNAL_TEMPSENSOR    (ADC_CR2_TSVREFE)      /*!< ADC measurement path to internal channel temperature sensor */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_RESOLUTION  ADC instance - Resolution
  * @{
  */
#define LL_ADC_RESOLUTION_12B              0x00000000U                         /*!< ADC resolution 12 bits */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_DATA_ALIGN  ADC instance - Data alignment
  * @{
  */
#define LL_ADC_DATA_ALIGN_RIGHT            0x00000000U            /*!< ADC conversion data alignment: right aligned (alignment on data register LSB bit 0)*/
#define LL_ADC_DATA_ALIGN_LEFT             (ADC_CR2_ALIGN)        /*!< ADC conversion data alignment: left aligned (alignment on data register MSB bit 15)*/
/**
  * @}
  */

/** @defgroup ADC_LL_EC_SCAN_SELECTION ADC instance - Scan selection
  * @{
  */
#define LL_ADC_SEQ_SCAN_DISABLE            0x00000000U    /*!< ADC conversion is performed in unitary conversion mode (one channel converted, that defined in rank 1). Configuration of both groups regular and injected sequencers (sequence length, ...) is discarded: equivalent to length of 1 rank.*/
#define LL_ADC_SEQ_SCAN_ENABLE             (ADC_CR1_SCAN) /*!< ADC conversions are performed in sequence conversions mode, according to configuration of both groups regular and injected sequencers (sequence length, ...). */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_GROUPS  ADC instance - Groups
  * @{
  */
#define LL_ADC_GROUP_REGULAR               0x00000001U   /*!< ADC group regular (available on all STM32 devices) */
#define LL_ADC_GROUP_INJECTED              0x00000002U   /*!< ADC group injected (not available on all STM32 devices)*/
#define LL_ADC_GROUP_REGULAR_INJECTED      0x00000003U   /*!< ADC both groups regular and injected */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL  ADC instance - Channel number
  * @{
  */
#define LL_ADC_CHANNEL_0                   (ADC_CHANNEL_0_NUMBER  | ADC_CHANNEL_0_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN0  */
#define LL_ADC_CHANNEL_1                   (ADC_CHANNEL_1_NUMBER  | ADC_CHANNEL_1_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN1  */
#define LL_ADC_CHANNEL_2                   (ADC_CHANNEL_2_NUMBER  | ADC_CHANNEL_2_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN2  */
#define LL_ADC_CHANNEL_3                   (ADC_CHANNEL_3_NUMBER  | ADC_CHANNEL_3_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN3  */
#define LL_ADC_CHANNEL_4                   (ADC_CHANNEL_4_NUMBER  | ADC_CHANNEL_4_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN4  */
#define LL_ADC_CHANNEL_5                   (ADC_CHANNEL_5_NUMBER  | ADC_CHANNEL_5_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN5  */
#define LL_ADC_CHANNEL_6                   (ADC_CHANNEL_6_NUMBER  | ADC_CHANNEL_6_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN6  */
#define LL_ADC_CHANNEL_7                   (ADC_CHANNEL_7_NUMBER  | ADC_CHANNEL_7_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN7  */
#define LL_ADC_CHANNEL_8                   (ADC_CHANNEL_8_NUMBER  | ADC_CHANNEL_8_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN8  */
#define LL_ADC_CHANNEL_9                   (ADC_CHANNEL_9_NUMBER  | ADC_CHANNEL_9_SMP)  /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN9  */
#define LL_ADC_CHANNEL_10                  (ADC_CHANNEL_10_NUMBER | ADC_CHANNEL_10_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN10 */
#define LL_ADC_CHANNEL_11                  (ADC_CHANNEL_11_NUMBER | ADC_CHANNEL_11_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN11 */
#define LL_ADC_CHANNEL_12                  (ADC_CHANNEL_12_NUMBER | ADC_CHANNEL_12_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN12 */
#define LL_ADC_CHANNEL_13                  (ADC_CHANNEL_13_NUMBER | ADC_CHANNEL_13_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN13 */
#define LL_ADC_CHANNEL_14                  (ADC_CHANNEL_14_NUMBER | ADC_CHANNEL_14_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN14 */
#define LL_ADC_CHANNEL_15                  (ADC_CHANNEL_15_NUMBER | ADC_CHANNEL_15_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN15 */
#define LL_ADC_CHANNEL_16                  (ADC_CHANNEL_16_NUMBER | ADC_CHANNEL_16_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN16 */
#define LL_ADC_CHANNEL_17                  (ADC_CHANNEL_17_NUMBER | ADC_CHANNEL_17_SMP) /*!< ADC external channel (channel connected to GPIO pin) ADCx_IN17 */
#define LL_ADC_CHANNEL_VREFINT             (LL_ADC_CHANNEL_17 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC internal channel connected to VrefInt: Internal voltage reference. On STM32F1, ADC channel available only on ADC instance: ADC1. */
#define LL_ADC_CHANNEL_TEMPSENSOR          (LL_ADC_CHANNEL_16 | ADC_CHANNEL_ID_INTERNAL_CH) /*!< ADC internal channel connected to Temperature sensor. */
/**
  * @}
  */
