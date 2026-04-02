
/** @defgroup ADC_LL_EC_INJ_SEQ_SCAN_LENGTH  ADC group injected - Sequencer scan length
  * @{
  */
#define LL_ADC_INJ_SEQ_SCAN_DISABLE        0x00000000U                     /*!< ADC group injected sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS  (                ADC_JSQR_JL_0) /*!< ADC group injected sequencer enable with 2 ranks in the sequence */
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS  (ADC_JSQR_JL_1                ) /*!< ADC group injected sequencer enable with 3 ranks in the sequence */
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS  (ADC_JSQR_JL_1 | ADC_JSQR_JL_0) /*!< ADC group injected sequencer enable with 4 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_DISCONT_MODE  ADC group injected - Sequencer discontinuous mode
  * @{
  */
#define LL_ADC_INJ_SEQ_DISCONT_DISABLE     0x00000000U            /*!< ADC group injected sequencer discontinuous mode disable */
#define LL_ADC_INJ_SEQ_DISCONT_1RANK       (ADC_CR1_JDISCEN)      /*!< ADC group injected sequencer discontinuous mode enable with sequence interruption every rank */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_RANKS  ADC group injected - Sequencer ranks
  * @{
  */
#define LL_ADC_INJ_RANK_1                  (ADC_JDR1_REGOFFSET | ADC_JOFR1_REGOFFSET | 0x00000001U) /*!< ADC group injected sequencer rank 1 */
#define LL_ADC_INJ_RANK_2                  (ADC_JDR2_REGOFFSET | ADC_JOFR2_REGOFFSET | 0x00000002U) /*!< ADC group injected sequencer rank 2 */
#define LL_ADC_INJ_RANK_3                  (ADC_JDR3_REGOFFSET | ADC_JOFR3_REGOFFSET | 0x00000003U) /*!< ADC group injected sequencer rank 3 */
#define LL_ADC_INJ_RANK_4                  (ADC_JDR4_REGOFFSET | ADC_JOFR4_REGOFFSET | 0x00000004U) /*!< ADC group injected sequencer rank 4 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL_SAMPLINGTIME  Channel - Sampling time
  * @{
  */
#define LL_ADC_SAMPLINGTIME_1CYCLE_5       0x00000000U                                              /*!< Sampling time 1.5 ADC clock cycle */
#define LL_ADC_SAMPLINGTIME_7CYCLES_5      (ADC_SMPR2_SMP0_0)                                       /*!< Sampling time 7.5 ADC clock cycles */
#define LL_ADC_SAMPLINGTIME_13CYCLES_5     (ADC_SMPR2_SMP0_1)                                       /*!< Sampling time 13.5 ADC clock cycles */
#define LL_ADC_SAMPLINGTIME_28CYCLES_5     (ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)                    /*!< Sampling time 28.5 ADC clock cycles */
#define LL_ADC_SAMPLINGTIME_41CYCLES_5     (ADC_SMPR2_SMP0_2)                                       /*!< Sampling time 41.5 ADC clock cycles */
#define LL_ADC_SAMPLINGTIME_55CYCLES_5     (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_0)                    /*!< Sampling time 55.5 ADC clock cycles */
#define LL_ADC_SAMPLINGTIME_71CYCLES_5     (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1)                    /*!< Sampling time 71.5 ADC clock cycles */
#define LL_ADC_SAMPLINGTIME_239CYCLES_5    (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0) /*!< Sampling time 239.5 ADC clock cycles */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_AWD_NUMBER Analog watchdog - Analog watchdog number
  * @{
  */
#define LL_ADC_AWD1                        (ADC_AWD_CR1_CHANNEL_MASK  | ADC_AWD_CR1_REGOFFSET) /*!< ADC analog watchdog number 1 */
/**
  * @}
  */
