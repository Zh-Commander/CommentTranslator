
/**
  * @brief  Set ADC group regular conversion data transfer: no transfer or
  *         transfer by DMA, and DMA requests mode.
  * @note   If transfer by DMA selected, specifies the DMA requests
  *         mode:
  *         - Limited mode (One shot mode): DMA transfer requests are stopped
  *           when number of DMA data transfers (number of
  *           ADC conversions) is reached.
  *           This ADC mode is intended to be used with DMA mode non-circular.
  *         - Unlimited mode: DMA transfer requests are unlimited,
  *           whatever number of DMA data transfers (number of
  *           ADC conversions).
  *           This ADC mode is intended to be used with DMA mode circular.
  * @note   If ADC DMA requests mode is set to unlimited and DMA is set to
  *         mode non-circular:
  *         when DMA transfers size will be reached, DMA will stop transfers of
  *         ADC conversions data ADC will raise an overrun error
  *        (overrun flag and interruption if enabled).
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref LL_ADC_DMA_GetRegAddr().
  * @rmtoll CR2      DMA            LL_ADC_REG_SetDMATransfer
  * @param  ADCx ADC instance
  * @param  DMATransfer This parameter can be one of the following values:
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_NONE
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_UNLIMITED
  * @retval None
  */
__STATIC_INLINE void LL_ADC_REG_SetDMATransfer(ADC_TypeDef *ADCx, uint32_t DMATransfer)
{
  MODIFY_REG(ADCx->CR2, ADC_CR2_DMA, DMATransfer);
}

/**
  * @brief  Get ADC group regular conversion data transfer: no transfer or
  *         transfer by DMA, and DMA requests mode.
  * @note   If transfer by DMA selected, specifies the DMA requests
  *         mode:
  *         - Limited mode (One shot mode): DMA transfer requests are stopped
  *           when number of DMA data transfers (number of
  *           ADC conversions) is reached.
  *           This ADC mode is intended to be used with DMA mode non-circular.
  *         - Unlimited mode: DMA transfer requests are unlimited,
  *           whatever number of DMA data transfers (number of
  *           ADC conversions).
  *           This ADC mode is intended to be used with DMA mode circular.
  * @note   If ADC DMA requests mode is set to unlimited and DMA is set to
  *         mode non-circular:
  *         when DMA transfers size will be reached, DMA will stop transfers of
  *         ADC conversions data ADC will raise an overrun error
  *         (overrun flag and interruption if enabled).
  * @note   To configure DMA source address (peripheral address),
  *         use function @ref LL_ADC_DMA_GetRegAddr().
  * @rmtoll CR2      DMA            LL_ADC_REG_GetDMATransfer
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_NONE
  *         @arg @ref LL_ADC_REG_DMA_TRANSFER_UNLIMITED
  */
__STATIC_INLINE uint32_t LL_ADC_REG_GetDMATransfer(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_DMA));
}

/**
  * @}
  */

/** @defgroup ADC_LL_EF_Configuration_ADC_Group_Injected Configuration of ADC hierarchical scope: group injected
  * @{
  */

/**
  * @brief  Set ADC group injected conversion trigger source:
  *         internal (SW start) or from external IP (timer event,
  *         external interrupt line).
  * @note   On this STM32 series, external trigger is set with trigger polarity:
  *         rising edge (only trigger polarity available on this STM32 series).
  * @note   Availability of parameters of trigger sources from timer 
  *         depends on timers availability on the selected device.
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_SetTriggerSource
  * @param  ADCx ADC instance
  * @param  TriggerSource This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_TRGO     (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_CH4      (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_CH1      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM3_CH4      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_EXTI_LINE15   (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (2)(4)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3 (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_CH3      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH2      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_TRGO     (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_CH4      (3)
  *         
  *         (1) On STM32F1, parameter available on all ADC instances: ADC1, ADC2, ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (2) On STM32F1, parameter available only on ADC instances: ADC1, ADC2 (for ADC instances ADCx available on the selected device).\n
  *         (3) On STM32F1, parameter available only on ADC instances: ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (4) On STM32F1, parameter available only on high-density and XL-density devices. A remap of trigger must be done at top level (refer to AFIO peripheral).
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_SetTriggerSource(ADC_TypeDef *ADCx, uint32_t TriggerSource)
{
/* Note: On this STM32 series, ADC group injected external trigger edge       */
/*       is used to perform a ADC conversion start.                           */
/*       This function does not set external trigger edge.                    */
/*       This feature is set using function                                   */
/*       @ref LL_ADC_INJ_StartConversionExtTrig().                            */
  MODIFY_REG(ADCx->CR2, ADC_CR2_JEXTSEL, (TriggerSource & ADC_CR2_JEXTSEL));
}

/**
  * @brief  Get ADC group injected conversion trigger source:
  *         internal (SW start) or from external IP (timer event,
  *         external interrupt line).
  * @note   To determine whether group injected trigger source is
  *         internal (SW start) or external, without detail
  *         of which peripheral is selected as external trigger,
  *         (equivalent to 
  *         "if(LL_ADC_INJ_GetTriggerSource(ADC1) == LL_ADC_INJ_TRIG_SOFTWARE)")
  *         use function @ref LL_ADC_INJ_IsTriggerSourceSWStart.
  * @note   Availability of parameters of trigger sources from timer 
  *         depends on timers availability on the selected device.
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_GetTriggerSource
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_INJ_TRIG_SOFTWARE
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_TRGO     (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM1_CH4      (1)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM2_CH1      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM3_CH4      (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_TRGO     (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_EXTI_LINE15   (2)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (2)(4)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3 (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM4_CH3      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH2      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM8_CH4      (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_TRGO     (3)
  *         @arg @ref LL_ADC_INJ_TRIG_EXT_TIM5_CH4      (3)
  *         
  *         (1) On STM32F1, parameter available on all ADC instances: ADC1, ADC2, ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (2) On STM32F1, parameter available only on ADC instances: ADC1, ADC2 (for ADC instances ADCx available on the selected device).\n
  *         (3) On STM32F1, parameter available only on ADC instances: ADC3 (for ADC instances ADCx available on the selected device).\n
  *         (4) On STM32F1, parameter available only on high-density and XL-density devices. A remap of trigger must be done at top level (refer to AFIO peripheral).
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetTriggerSource(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR2, ADC_CR2_JEXTSEL));
}

/**
  * @brief  Get ADC group injected conversion trigger source internal (SW start)
            or external
  * @note   In case of group injected trigger source set to external trigger,
  *         to determine which peripheral is selected as external trigger,
  *         use function @ref LL_ADC_INJ_GetTriggerSource.
  * @rmtoll CR2      JEXTSEL        LL_ADC_INJ_IsTriggerSourceSWStart
  * @param  ADCx ADC instance
  * @retval Value "0" if trigger source external trigger
  *         Value "1" if trigger source SW start.
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_IsTriggerSourceSWStart(ADC_TypeDef *ADCx)
{
  return (READ_BIT(ADCx->CR2, ADC_CR2_JEXTSEL) == LL_ADC_INJ_TRIG_SOFTWARE);
}

/**
  * @brief  Set ADC group injected sequencer length and scan direction.
  * @note   This function performs configuration of:
  *         - Sequence length: Number of ranks in the scan sequence.
  *         - Sequence direction: Unless specified in parameters, sequencer
  *           scan direction is forward (from rank 1 to rank n).
  * @note   On this STM32 series, group injected sequencer configuration
  *         is conditioned to ADC instance sequencer mode.
  *         If ADC instance sequencer mode is disabled, sequencers of
  *         all groups (group regular, group injected) can be configured
  *         but their execution is disabled (limited to rank 1).
  *         Refer to function @ref LL_ADC_SetSequencersScanMode().
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @rmtoll JSQR     JL             LL_ADC_INJ_SetSequencerLength
  * @param  ADCx ADC instance
  * @param  SequencerNbRanks This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerLength(ADC_TypeDef *ADCx, uint32_t SequencerNbRanks)
{
  MODIFY_REG(ADCx->JSQR, ADC_JSQR_JL, SequencerNbRanks);
}

/**
  * @brief  Get ADC group injected sequencer length and scan direction.
  * @note   This function retrieves:
  *         - Sequence length: Number of ranks in the scan sequence.
  *         - Sequence direction: Unless specified in parameters, sequencer
  *           scan direction is forward (from rank 1 to rank n).
  * @note   On this STM32 series, group injected sequencer configuration
  *         is conditioned to ADC instance sequencer mode.
  *         If ADC instance sequencer mode is disabled, sequencers of
  *         all groups (group regular, group injected) can be configured
  *         but their execution is disabled (limited to rank 1).
  *         Refer to function @ref LL_ADC_SetSequencersScanMode().
  * @note   Sequencer disabled is equivalent to sequencer of 1 rank:
  *         ADC conversion on only 1 channel.
  * @rmtoll JSQR     JL             LL_ADC_INJ_GetSequencerLength
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS
  *         @arg @ref LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerLength(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->JSQR, ADC_JSQR_JL));
}

/**
  * @brief  Set ADC group injected sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @note   It is not possible to enable both ADC group injected
  *         auto-injected mode and sequencer discontinuous mode.
  * @rmtoll CR1      DISCEN         LL_ADC_INJ_SetSequencerDiscont
  * @param  ADCx ADC instance
  * @param  SeqDiscont This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_1RANK
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerDiscont(ADC_TypeDef *ADCx, uint32_t SeqDiscont)
{
  MODIFY_REG(ADCx->CR1, ADC_CR1_JDISCEN, SeqDiscont);
}

/**
  * @brief  Get ADC group injected sequencer discontinuous mode:
  *         sequence subdivided and scan conversions interrupted every selected
  *         number of ranks.
  * @rmtoll CR1      DISCEN         LL_ADC_REG_GetSequencerDiscont
  * @param  ADCx ADC instance
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_DISABLE
  *         @arg @ref LL_ADC_INJ_SEQ_DISCONT_1RANK
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerDiscont(ADC_TypeDef *ADCx)
{
  return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_JDISCEN));
}

/**
  * @brief  Set ADC group injected sequence: channel on the selected
  *         sequence rank.
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @note   On this STM32 series, to measure internal channels (VrefInt,
  *         TempSensor, ...), measurement paths to internal channels must be
  *         enabled separately.
  *         This can be done using function @ref LL_ADC_SetCommonPathInternalCh().
  * @rmtoll JSQR     JSQ1           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ2           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ3           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ4           LL_ADC_INJ_SetSequencerRanks
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @param  Channel This parameter can be one of the following values:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) On STM32F1, parameter available only on ADC instance: ADC1.
  * @retval None
  */
__STATIC_INLINE void LL_ADC_INJ_SetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank, uint32_t Channel)
{
  /* Set bits with content of parameter "Channel" with bits position          */
  /* in register depending on parameter "Rank".                               */
  /* Parameters "Rank" and "Channel" are used with masks because containing   */
  /* other bits reserved for other purpose.                                   */
  uint32_t tmpreg1 = (READ_BIT(ADCx->JSQR, ADC_JSQR_JL) >> ADC_JSQR_JL_Pos) + 1U;
  
  MODIFY_REG(ADCx->JSQR,
             ADC_CHANNEL_ID_NUMBER_MASK << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))),
             (Channel & ADC_CHANNEL_ID_NUMBER_MASK) << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))));
}

/**
  * @brief  Get ADC group injected sequence: channel on the selected
  *         sequence rank.
  * @note   Depending on devices and packages, some channels may not be available.
  *         Refer to device datasheet for channels availability.
  * @note   Usage of the returned channel number:
  *         - To reinject this channel into another function LL_ADC_xxx:
  *           the returned channel number is only partly formatted on definition
  *           of literals LL_ADC_CHANNEL_x. Therefore, it has to be compared
  *           with parts of literals LL_ADC_CHANNEL_x or using
  *           helper macro @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB().
  *           Then the selected literal LL_ADC_CHANNEL_x can be used
  *           as parameter for another function.
  *         - To get the channel number in decimal format:
  *           process the returned value with the helper macro
  *           @ref __LL_ADC_CHANNEL_TO_DECIMAL_NB().
  * @rmtoll JSQR     JSQ1           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ2           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ3           LL_ADC_INJ_SetSequencerRanks\n
  *         JSQR     JSQ4           LL_ADC_INJ_SetSequencerRanks
  * @param  ADCx ADC instance
  * @param  Rank This parameter can be one of the following values:
  *         @arg @ref LL_ADC_INJ_RANK_1
  *         @arg @ref LL_ADC_INJ_RANK_2
  *         @arg @ref LL_ADC_INJ_RANK_3
  *         @arg @ref LL_ADC_INJ_RANK_4
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) On STM32F1, parameter available only on ADC instance: ADC1.\n
  *         (1) For ADC channel read back from ADC register,
  *             comparison with internal channel parameter to be done
  *             using helper macro @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL().
  */
__STATIC_INLINE uint32_t LL_ADC_INJ_GetSequencerRanks(ADC_TypeDef *ADCx, uint32_t Rank)
{
  uint32_t tmpreg1 = (READ_BIT(ADCx->JSQR, ADC_JSQR_JL) >> ADC_JSQR_JL_Pos)  + 1U;
  
  return (uint32_t)(READ_BIT(ADCx->JSQR,
                             ADC_CHANNEL_ID_NUMBER_MASK << (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1))))
                    >> (5U * (uint8_t)(((Rank) + 3U) - (tmpreg1)))
                   );
}
