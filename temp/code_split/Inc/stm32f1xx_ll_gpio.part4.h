
/**
  * @brief  Check if TIM67DACDMA has been remapped or not
  * @rmtoll MAPR2         TIM76_DAC_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP) == (AFIO_MAPR2_TIM67_DAC_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief Enable the remapping of TIM12_CH1 and TIM12_CH2.
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_EnableRemap_TIM12
  * @note  ENABLE: Remap     (TIM12_CH1 on PB12 and TIM12_CH2 on PB13).
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM12(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief Disable the remapping of TIM12_CH1 and TIM12_CH2.
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_DisableRemap_TIM12
  * @note  DISABLE: No remap (TIM12_CH1 on PC4  and TIM12_CH2 on PC5).
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM12(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief  Check if TIM12_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM12_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM12
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM12(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP) == (AFIO_MAPR2_TIM12_REMAP));
}
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief Miscellaneous features remapping.
  *        This bit is set and cleared by software. It controls miscellaneous features.
  *        The DMA2 channel 5 interrupt position in the vector table.
  *        The timer selection for DAC trigger 3 (TSEL[2:0] = 011, for more details refer to the DAC_CR register).
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_EnableRemap_MISC
  * @note  ENABLE: DMA2 channel 5 interrupt is mapped separately at position 60 and TIM15 TRGO event is
  *        selected as DAC Trigger 3, TIM15 triggers TIM1/3.
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_MISC(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief Miscellaneous features remapping.
  *        This bit is set and cleared by software. It controls miscellaneous features.
  *        The DMA2 channel 5 interrupt position in the vector table.
  *        The timer selection for DAC trigger 3 (TSEL[2:0] = 011, for more details refer to the DAC_CR register).
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_DisableRemap_MISC
  * @note  DISABLE: DMA2 channel 5 interrupt is mapped with DMA2 channel 4 at position 59, TIM5 TRGO
  *        event is selected as DAC Trigger 3, TIM5 triggers TIM1/3.
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_MISC(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief  Check if MISC has been remapped or not
  * @rmtoll MAPR2         MISC_REMAP         LL_GPIO_AF_IsEnabledRemap_MISC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_MISC(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP) == (AFIO_MAPR2_MISC_REMAP));
}
#endif

/**
  * @}
  */

/** @defgroup GPIO_AF_LL_EVENTOUT Output Event configuration
  * @brief This section propose definition to Configure EVENTOUT Cortex feature .
  * @{
  */

/**
  * @brief  Configures the port and pin on which the EVENTOUT Cortex signal will be connected.
  * @rmtoll EVCR          PORT           LL_GPIO_AF_ConfigEventout\n
  *         EVCR          PIN            LL_GPIO_AF_ConfigEventout
  * @param  LL_GPIO_PortSource This parameter can be one of the following values:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_A
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_B
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_C
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_D
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_E
  * @param  LL_GPIO_PinSource This parameter can be one of the following values:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_0
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_1
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_2
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_3
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_4
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_5
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_6
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_7
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_8
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_9
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_10
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_11
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_12
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_13
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_14
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_15
  * @retval None
*/
__STATIC_INLINE void LL_GPIO_AF_ConfigEventout(uint32_t LL_GPIO_PortSource, uint32_t LL_GPIO_PinSource)
{
  MODIFY_REG(AFIO->EVCR, (AFIO_EVCR_PORT) | (AFIO_EVCR_PIN), (LL_GPIO_PortSource) | (LL_GPIO_PinSource));
}

/**
  * @brief  Enables the Event Output.
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_EnableEventout
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableEventout(void)
{
  SET_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @brief  Disables the Event Output.
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_DisableEventout
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableEventout(void)
{
  CLEAR_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @}
  */
/** @defgroup GPIO_AF_LL_EXTI EXTI external interrupt
  * @brief This section Configure source input for the EXTI external interrupt .
  * @{
  */

/**
  * @brief  Configure source input for the EXTI external interrupt.
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_SetEXTISource
  * @param  Port This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  * @param  Line This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_AF_EXTI_LINE0
  *         @arg @ref LL_GPIO_AF_EXTI_LINE1
  *         @arg @ref LL_GPIO_AF_EXTI_LINE2
  *         @arg @ref LL_GPIO_AF_EXTI_LINE3
  *         @arg @ref LL_GPIO_AF_EXTI_LINE4
  *         @arg @ref LL_GPIO_AF_EXTI_LINE5
  *         @arg @ref LL_GPIO_AF_EXTI_LINE6
  *         @arg @ref LL_GPIO_AF_EXTI_LINE7
  *         @arg @ref LL_GPIO_AF_EXTI_LINE8
  *         @arg @ref LL_GPIO_AF_EXTI_LINE9
  *         @arg @ref LL_GPIO_AF_EXTI_LINE10
  *         @arg @ref LL_GPIO_AF_EXTI_LINE11
  *         @arg @ref LL_GPIO_AF_EXTI_LINE12
  *         @arg @ref LL_GPIO_AF_EXTI_LINE13
  *         @arg @ref LL_GPIO_AF_EXTI_LINE14
  *         @arg @ref LL_GPIO_AF_EXTI_LINE15
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_SetEXTISource(uint32_t Port, uint32_t Line)
{
  MODIFY_REG(AFIO->EXTICR[Line & 0xFF], (Line >> 16), Port << POSITION_VAL((Line >> 16)));
}

/**
  * @brief  Get the configured defined for specific EXTI Line
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_GetEXTISource
  * @param  Line This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_AF_EXTI_LINE0
  *         @arg @ref LL_GPIO_AF_EXTI_LINE1
  *         @arg @ref LL_GPIO_AF_EXTI_LINE2
  *         @arg @ref LL_GPIO_AF_EXTI_LINE3
  *         @arg @ref LL_GPIO_AF_EXTI_LINE4
  *         @arg @ref LL_GPIO_AF_EXTI_LINE5
  *         @arg @ref LL_GPIO_AF_EXTI_LINE6
  *         @arg @ref LL_GPIO_AF_EXTI_LINE7
  *         @arg @ref LL_GPIO_AF_EXTI_LINE8
  *         @arg @ref LL_GPIO_AF_EXTI_LINE9
  *         @arg @ref LL_GPIO_AF_EXTI_LINE10
  *         @arg @ref LL_GPIO_AF_EXTI_LINE11
  *         @arg @ref LL_GPIO_AF_EXTI_LINE12
  *         @arg @ref LL_GPIO_AF_EXTI_LINE13
  *         @arg @ref LL_GPIO_AF_EXTI_LINE14
  *         @arg @ref LL_GPIO_AF_EXTI_LINE15
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_GetEXTISource(uint32_t Line)
{
  return (uint32_t)(READ_BIT(AFIO->EXTICR[Line & 0xFF], (Line >> 16)) >> POSITION_VAL(Line >> 16));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct);
void        LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct);

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

#endif /* defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF) || defined (GPIOG) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F1xx_LL_GPIO_H */

