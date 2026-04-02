
/** @defgroup ADC_LL_EC_REG_TRIGGER_SOURCE  ADC group regular - Trigger source
  * @{
  */
/* ADC group regular external triggers for ADC instances: ADC1, ADC2, ADC3 (for ADC instances ADCx available on the selected device) */
#define LL_ADC_REG_TRIG_SOFTWARE           (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0) /*!< ADC group regular conversion trigger internal: SW start. */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH3       (ADC_CR2_EXTSEL_1)                                       /*!< ADC group regular conversion trigger from external IP: TIM1 channel 3 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
/* ADC group regular external triggers for ADC instances: ADC1, ADC2 (for ADC instances ADCx available on the selected device) */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH1       0x00000000U                                              /*!< ADC group regular conversion trigger from external IP: TIM1 channel 1 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH2       (ADC_CR2_EXTSEL_0)                                       /*!< ADC group regular conversion trigger from external IP: TIM1 channel 2 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM2_CH2       (ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0)                    /*!< ADC group regular conversion trigger from external IP: TIM2 channel 2 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (ADC_CR2_EXTSEL_2)                                       /*!< ADC group regular conversion trigger from external IP: TIM3 TRGO. Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM4_CH4       (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_0)                    /*!< ADC group regular conversion trigger from external IP: TIM4 channel 4 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1)                    /*!< ADC group regular conversion trigger from external IP: external interrupt line 11. Trigger edge set to rising edge (default setting). */
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/* Note: TIM8_TRGO is available on ADC1 and ADC2 only in high-density and     */
/*       XL-density devices.                                                  */
/* Note: To use TIM8_TRGO on ADC1 or ADC2, a remap of trigger must be done    */
/*       A remap of trigger must be done at top level (refer to               */
/*       AFIO peripheral).                                                    */
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                        /*!< ADC group regular conversion trigger from external IP: TIM8 TRGO. Trigger edge set to rising edge (default setting). Available only on high-density and XL-density devices. A remap of trigger must be done at top level (refer to AFIO peripheral).*/
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC group regular external triggers for ADC instances: ADC3 (for ADC instances ADCx available on the selected device) */
#define LL_ADC_REG_TRIG_EXT_TIM3_CH1       (LL_ADC_REG_TRIG_EXT_TIM1_CH1)                           /*!< ADC group regular conversion trigger from external IP: TIM3 channel 1 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM2_CH3       (LL_ADC_REG_TRIG_EXT_TIM1_CH2)                           /*!< ADC group regular conversion trigger from external IP: TIM2 channel 3 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM8_CH1       (LL_ADC_REG_TRIG_EXT_TIM2_CH2)                           /*!< ADC group regular conversion trigger from external IP: TIM8 channel 1 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (LL_ADC_REG_TRIG_EXT_TIM3_TRGO)                          /*!< ADC group regular conversion trigger from external IP: TIM8 TRGO. Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM5_CH1       (LL_ADC_REG_TRIG_EXT_TIM4_CH4)                           /*!< ADC group regular conversion trigger from external IP: TIM5 channel 1 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_REG_TRIG_EXT_TIM5_CH3       (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                        /*!< ADC group regular conversion trigger from external IP: TIM5 channel 3 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_TRIGGER_EDGE  ADC group regular - Trigger edge
  * @{
  */
#define LL_ADC_REG_TRIG_EXT_RISING         ADC_CR2_EXTTRIG                         /*!< ADC group regular conversion trigger polarity set to rising edge */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_CONTINUOUS_MODE  ADC group regular - Continuous mode
* @{
*/
#define LL_ADC_REG_CONV_SINGLE             0x00000000U             /*!< ADC conversions are performed in single mode: one conversion per trigger */
#define LL_ADC_REG_CONV_CONTINUOUS         (ADC_CR2_CONT)          /*!< ADC conversions are performed in continuous mode: after the first trigger, following conversions launched successively automatically */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_DMA_TRANSFER  ADC group regular - DMA transfer of ADC conversion data
  * @{
  */
#define LL_ADC_REG_DMA_TRANSFER_NONE       0x00000000U              /*!< ADC conversions are not transferred by DMA */
#define LL_ADC_REG_DMA_TRANSFER_UNLIMITED  (ADC_CR2_DMA)                        /*!< ADC conversion data are transferred by DMA, in unlimited mode: DMA transfer requests are unlimited, whatever number of DMA data transferred (number of ADC conversions). This ADC mode is intended to be used with DMA mode circular. */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_SCAN_LENGTH  ADC group regular - Sequencer scan length
  * @{
  */
#define LL_ADC_REG_SEQ_SCAN_DISABLE        0x00000000U                                                 /*!< ADC group regular sequencer disable (equivalent to sequencer of 1 rank: ADC conversion on only 1 channel) */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS  (                                             ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 2 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS  (                              ADC_SQR1_L_1               ) /*!< ADC group regular sequencer enable with 3 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS  (                              ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 4 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS  (               ADC_SQR1_L_2                              ) /*!< ADC group regular sequencer enable with 5 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS  (               ADC_SQR1_L_2                | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 6 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS  (               ADC_SQR1_L_2 | ADC_SQR1_L_1               ) /*!< ADC group regular sequencer enable with 7 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS  (               ADC_SQR1_L_2 | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 8 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS  (ADC_SQR1_L_3                                             ) /*!< ADC group regular sequencer enable with 9 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS (ADC_SQR1_L_3                               | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 10 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS (ADC_SQR1_L_3                | ADC_SQR1_L_1               ) /*!< ADC group regular sequencer enable with 11 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS (ADC_SQR1_L_3                | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 12 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2                              ) /*!< ADC group regular sequencer enable with 13 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2                | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 14 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 | ADC_SQR1_L_1               ) /*!< ADC group regular sequencer enable with 15 ranks in the sequence */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC group regular sequencer enable with 16 ranks in the sequence */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_DISCONT_MODE  ADC group regular - Sequencer discontinuous mode
  * @{
  */
#define LL_ADC_REG_SEQ_DISCONT_DISABLE     0x00000000U                                                                  /*!< ADC group regular sequencer discontinuous mode disable */
#define LL_ADC_REG_SEQ_DISCONT_1RANK       (                                                            ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every rank */
#define LL_ADC_REG_SEQ_DISCONT_2RANKS      (                                        ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enabled with sequence interruption every 2 ranks */
#define LL_ADC_REG_SEQ_DISCONT_3RANKS      (                    ADC_CR1_DISCNUM_1                     | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 3 ranks */
#define LL_ADC_REG_SEQ_DISCONT_4RANKS      (                    ADC_CR1_DISCNUM_1 | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 4 ranks */
#define LL_ADC_REG_SEQ_DISCONT_5RANKS      (ADC_CR1_DISCNUM_2                                         | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 5 ranks */
#define LL_ADC_REG_SEQ_DISCONT_6RANKS      (ADC_CR1_DISCNUM_2                     | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 6 ranks */
#define LL_ADC_REG_SEQ_DISCONT_7RANKS      (ADC_CR1_DISCNUM_2 | ADC_CR1_DISCNUM_1                     | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 7 ranks */
#define LL_ADC_REG_SEQ_DISCONT_8RANKS      (ADC_CR1_DISCNUM_2 | ADC_CR1_DISCNUM_1 | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC group regular sequencer discontinuous mode enable with sequence interruption every 8 ranks */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_RANKS  ADC group regular - Sequencer ranks
  * @{
  */
#define LL_ADC_REG_RANK_1                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_1_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 1 */
#define LL_ADC_REG_RANK_2                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_2_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 2 */
#define LL_ADC_REG_RANK_3                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_3_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 3 */
#define LL_ADC_REG_RANK_4                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_4_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 4 */
#define LL_ADC_REG_RANK_5                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_5_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 5 */
#define LL_ADC_REG_RANK_6                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_6_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 6 */
#define LL_ADC_REG_RANK_7                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_7_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 7 */
#define LL_ADC_REG_RANK_8                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_8_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 8 */
#define LL_ADC_REG_RANK_9                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_9_SQRX_BITOFFSET_POS)  /*!< ADC group regular sequencer rank 9 */
#define LL_ADC_REG_RANK_10                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_10_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 10 */
#define LL_ADC_REG_RANK_11                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_11_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 11 */
#define LL_ADC_REG_RANK_12                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_12_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 12 */
#define LL_ADC_REG_RANK_13                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_13_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 13 */
#define LL_ADC_REG_RANK_14                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_14_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 14 */
#define LL_ADC_REG_RANK_15                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_15_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 15 */
#define LL_ADC_REG_RANK_16                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_16_SQRX_BITOFFSET_POS) /*!< ADC group regular sequencer rank 16 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIGGER_SOURCE  ADC group injected - Trigger source
  * @{
  */
/* ADC group injected external triggers for ADC instances: ADC1, ADC2, ADC3 (for ADC instances ADCx available on the selected device) */
#define LL_ADC_INJ_TRIG_SOFTWARE           (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0) /*!< ADC group injected conversion trigger internal: SW start. */
#define LL_ADC_INJ_TRIG_EXT_TIM1_TRGO      0x00000000U                                                 /*!< ADC group injected conversion trigger from external IP: TIM1 TRGO. Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM1_CH4       (ADC_CR2_JEXTSEL_0)                                         /*!< ADC group injected conversion trigger from external IP: TIM1 channel 4 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
/* ADC group injected external triggers for ADC instances: ADC1, ADC2 (for ADC instances ADCx available on the selected device) */
#define LL_ADC_INJ_TRIG_EXT_TIM2_TRGO      (ADC_CR2_JEXTSEL_1)                                         /*!< ADC group injected conversion trigger from external IP: TIM2 TRGO. Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM2_CH1       (ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0)                     /*!< ADC group injected conversion trigger from external IP: TIM2 channel 1 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM3_CH4       (ADC_CR2_JEXTSEL_2)                                         /*!< ADC group injected conversion trigger from external IP: TIM3 channel 4 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM4_TRGO      (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_0)                     /*!< ADC group injected conversion trigger from external IP: TIM4 TRGO. Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_EXTI_LINE15    (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1)                     /*!< ADC group injected conversion trigger from external IP: external interrupt line 15. Trigger edge set to rising edge (default setting). */
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/* Note: TIM8_CH4 is available on ADC1 and ADC2 only in high-density and      */
/*       XL-density devices.                                                  */
/* Note: To use TIM8_TRGO on ADC1 or ADC2, a remap of trigger must be done    */
/*       A remap of trigger must be done at top level (refer to               */
/*       AFIO peripheral).                                                    */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4        (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                          /*!< ADC group injected conversion trigger from external IP: TIM8 channel 4 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). Available only on high-density and XL-density devices. A remap of trigger must be done at top level (refer to AFIO peripheral). */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC group injected external triggers for ADC instances: ADC3 (for ADC instances ADCx available on the selected device) */
#define LL_ADC_INJ_TRIG_EXT_TIM4_CH3        (LL_ADC_INJ_TRIG_EXT_TIM2_TRGO)                            /*!< ADC group injected conversion trigger from external IP: TIM4 channel 3 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH2        (LL_ADC_INJ_TRIG_EXT_TIM2_CH1)                             /*!< ADC group injected conversion trigger from external IP: TIM8 channel 2 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3   (LL_ADC_INJ_TRIG_EXT_TIM3_CH4)                             /*!< ADC group injected conversion trigger from external IP: TIM8 channel 4 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM5_TRGO       (LL_ADC_INJ_TRIG_EXT_TIM4_TRGO)                            /*!< ADC group injected conversion trigger from external IP: TIM5 TRGO. Trigger edge set to rising edge (default setting). */
#define LL_ADC_INJ_TRIG_EXT_TIM5_CH4        (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                          /*!< ADC group injected conversion trigger from external IP: TIM5 channel 4 event (capture compare: input capture or output capture). Trigger edge set to rising edge (default setting). */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIGGER_EDGE  ADC group injected - Trigger edge
  * @{
  */
#define LL_ADC_INJ_TRIG_EXT_RISING         ADC_CR2_JEXTTRIG                        /*!< ADC group injected conversion trigger polarity set to rising edge */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIG_AUTO  ADC group injected - Automatic trigger mode
* @{
*/
#define LL_ADC_INJ_TRIG_INDEPENDENT        0x00000000U            /*!< ADC group injected conversion trigger independent. Setting mandatory if ADC group injected injected trigger source is set to an external trigger. */
#define LL_ADC_INJ_TRIG_FROM_GRP_REGULAR   (ADC_CR1_JAUTO)        /*!< ADC group injected conversion trigger from ADC group regular. Setting compliant only with group injected trigger source set to SW start, without any further action on  ADC group injected conversion start or stop: in this case, ADC group injected is controlled only from ADC group regular. */
/**
  * @}
  */

