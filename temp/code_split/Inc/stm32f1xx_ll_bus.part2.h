
/**
  * @brief  Disable APB2 peripherals clock.
  * @rmtoll APB2ENR      ADC1EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      ADC2EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      ADC3EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      AFIOEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPAEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPBEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPCEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPDEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPEEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPFEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPGEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      SPI1EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM10EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM11EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM15EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM16EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM17EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM1EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM8EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM9EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      USART1EN      LL_APB2_GRP1_DisableClock
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void LL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2ENR, Periphs);
}

/**
  * @brief  Force APB2 peripherals reset.
  * @rmtoll APB2RSTR     ADC1RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     ADC2RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     ADC3RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     AFIORST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPARST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPBRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPCRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPDRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPERST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPFRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPGRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     SPI1RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM10RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM11RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM15RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM16RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM17RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM1RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM8RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM9RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     USART1RST     LL_APB2_GRP1_ForceReset
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void LL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->APB2RSTR, Periphs);
}

/**
  * @brief  Release APB2 peripherals reset.
  * @rmtoll APB2RSTR     ADC1RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     ADC2RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     ADC3RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     AFIORST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPARST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPBRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPCRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPDRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPERST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPFRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPGRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     SPI1RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM10RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM11RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM15RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM16RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM17RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM1RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM8RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM9RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     USART1RST     LL_APB2_GRP1_ReleaseReset
  * @param  Periphs This parameter can be a combination of the following values:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) value not defined in all devices.
  * @retval None
*/
__STATIC_INLINE void LL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->APB2RSTR, Periphs);
}

/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RCC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_LL_BUS_H */

