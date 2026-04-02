
#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
#define __HAL_RCC_ADC2_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) == RESET)
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */
#if defined(STM32F100xB) || defined(STM32F100xE)
#define __HAL_RCC_TIM15_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) != RESET)
#define __HAL_RCC_TIM15_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) == RESET)
#define __HAL_RCC_TIM16_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) != RESET)
#define __HAL_RCC_TIM16_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) == RESET)
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) != RESET)
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) == RESET)
#endif /* STM32F100xB || STM32F100xE */
#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) != RESET)
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) == RESET)
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/
#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
#define __HAL_RCC_ADC3_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) != RESET)
#define __HAL_RCC_ADC3_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) == RESET)
#endif /* STM32F103xE || STM32F103xG */
#if defined(STM32F100xE)
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif /* STM32F100xE */
#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
#define __HAL_RCC_TIM10_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) != RESET)
#define __HAL_RCC_TIM10_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) == RESET)
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)
#define __HAL_RCC_TIM11_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) == RESET)
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_Peripheral_Clock_Force_Release Peripheral Clock Force Release
  * @brief  Force or release AHB peripheral reset.
  * @{
  */
#define __HAL_RCC_AHB_FORCE_RESET()         (RCC->AHBRSTR = 0xFFFFFFFFU)
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()       (RCC->AHBRSTR |= (RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_FORCE_RESET()      (RCC->AHBRSTR |= (RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

#define __HAL_RCC_AHB_RELEASE_RESET()       (RCC->AHBRSTR = 0x00)
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()     (RCC->AHBRSTR &= ~(RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
#define __HAL_RCC_ETHMAC_RELEASE_RESET()    (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  Force or release APB1 peripheral reset.
  * @{
  */

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
#define __HAL_RCC_CAN1_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN1RST))

#define __HAL_RCC_CAN1_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN1RST))
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM4_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_SPI2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_USART3_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_I2C2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))

#define __HAL_RCC_TIM4_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
#define __HAL_RCC_SPI2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
#define __HAL_RCC_USART3_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST))
#define __HAL_RCC_I2C2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_USB_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_USBRST))
#define __HAL_RCC_USB_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USBRST))
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))

#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined  (STM32F100xE)
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))
#define __HAL_RCC_CEC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_CECRST))

#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#define __HAL_RCC_CEC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CECRST))
#endif /* STM32F100xB || STM32F100xE */

#if defined  (STM32F100xE)
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))

#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#endif /* STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
#define __HAL_RCC_CAN2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN2RST))

#define __HAL_RCC_CAN2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN2RST))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))

#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
#endif /* STM32F101xG || STM32F103xG */

/**
  * @}
  */

/** @defgroup RCCEx_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  Force or release APB2 peripheral reset.
  * @{
  */

#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
#define __HAL_RCC_ADC2_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC2RST))

#define __HAL_RCC_ADC2_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC2RST))
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */

#if defined(STM32F100xB) || defined(STM32F100xE)
#define __HAL_RCC_TIM15_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM17RST))

#define __HAL_RCC_TIM15_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST))
#define __HAL_RCC_TIM16_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM16RST))
#define __HAL_RCC_TIM17_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM17RST))
#endif /* STM32F100xB || STM32F100xE */

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
#define __HAL_RCC_GPIOE_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPERST))

#define __HAL_RCC_GPIOE_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPERST))
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/

#if defined(STM32F103xE) || defined(STM32F103xG)
#define __HAL_RCC_TIM8_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_ADC3_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC3RST))

#define __HAL_RCC_TIM8_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
#define __HAL_RCC_ADC3_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC3RST))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F100xE)
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif /* STM32F100xE */

#if defined(STM32F101xG) || defined(STM32F103xG)
#define __HAL_RCC_TIM9_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))

#define __HAL_RCC_TIM9_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
#define __HAL_RCC_TIM10_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM10RST))
#define __HAL_RCC_TIM11_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM11RST))
#endif /* STM32F101xG || STM32F103xG*/

/**
  * @}
  */

/** @defgroup RCCEx_HSE_Configuration HSE Configuration
  * @{
  */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/**
  * @brief  Macro to configure the External High Speed oscillator (HSE) Predivision factor for PLL.
  * @note   Predivision factor can not be changed if PLL is used as system clock
  *         In this case, you have to select another source of the system clock, disable the PLL and
  *         then change the HSE predivision factor.
  * @param  __HSE_PREDIV_VALUE__ specifies the division value applied to HSE.
  *         This parameter must be a number between RCC_HSE_PREDIV_DIV1 and RCC_HSE_PREDIV_DIV16.
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV1, (uint32_t)(__HSE_PREDIV_VALUE__))
#else
/**
  * @brief  Macro to configure the External High Speed oscillator (HSE) Predivision factor for PLL.
  * @note   Predivision factor can not be changed if PLL is used as system clock
  *         In this case, you have to select another source of the system clock, disable the PLL and
  *         then change the HSE predivision factor.
  * @param  __HSE_PREDIV_VALUE__ specifies the division value applied to HSE.
  *         This parameter must be a number between RCC_HSE_PREDIV_DIV1 and RCC_HSE_PREDIV_DIV2.
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR,RCC_CFGR_PLLXTPRE, (uint32_t)(__HSE_PREDIV_VALUE__))

#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/**
  * @brief  Macro to get prediv1 factor for PLL.
  */
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1)

#else
/**
  * @brief  Macro to get prediv1 factor for PLL.
  */
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR, RCC_CFGR_PLLXTPRE)

#endif /* STM32F105xC || STM32F107xC || STM32F100xB || STM32F100xE */

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @defgroup RCCEx_PLLI2S_Configuration PLLI2S Configuration
  * @{
  */

/** @brief Macros to enable the main PLLI2S.
  * @note   After enabling the main PLLI2S, the application software should wait on
  *         PLLI2SRDY flag to be set indicating that PLLI2S clock is stable and can
  *         be used as system clock source.
  * @note   The main PLLI2S is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLLI2S_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = ENABLE)

/** @brief Macros to disable the main PLLI2S.
  * @note   The main PLLI2S is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLLI2S_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = DISABLE)

/** @brief macros to configure the main PLLI2S multiplication factor.
  * @note   This function must be used only when the main PLLI2S is disabled.
  *
  * @param  __PLLI2SMUL__ specifies the multiplication factor for PLLI2S VCO output clock
  *          This parameter can be one of the following values:
  *             @arg @ref RCC_PLLI2S_MUL8 PLLI2SVCO = PLLI2S clock entry x 8
  *             @arg @ref RCC_PLLI2S_MUL9 PLLI2SVCO = PLLI2S clock entry x 9
  *             @arg @ref RCC_PLLI2S_MUL10 PLLI2SVCO = PLLI2S clock entry x 10
  *             @arg @ref RCC_PLLI2S_MUL11 PLLI2SVCO = PLLI2S clock entry x 11
  *             @arg @ref RCC_PLLI2S_MUL12 PLLI2SVCO = PLLI2S clock entry x 12
  *             @arg @ref RCC_PLLI2S_MUL13 PLLI2SVCO = PLLI2S clock entry x 13
  *             @arg @ref RCC_PLLI2S_MUL14 PLLI2SVCO = PLLI2S clock entry x 14
  *             @arg @ref RCC_PLLI2S_MUL16 PLLI2SVCO = PLLI2S clock entry x 16
  *             @arg @ref RCC_PLLI2S_MUL20 PLLI2SVCO = PLLI2S clock entry x 20
  *
  */
#define __HAL_RCC_PLLI2S_CONFIG(__PLLI2SMUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL3MUL,(__PLLI2SMUL__))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_Peripheral_Configuration Peripheral Configuration
  * @brief  Macros to configure clock source of different peripherals.
  * @{
  */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
/** @brief  Macro to configure the USB clock.
  * @param  __USBCLKSOURCE__ specifies the USB clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL clock divided by 1 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL clock divided by 1.5 selected as USB clock
  */
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  Macro to get the USB clock (USBCLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL clock divided by 1 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL clock divided by 1.5 selected as USB clock
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @brief  Macro to configure the USB OTSclock.
  * @param  __USBCLKSOURCE__ specifies the USB clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as USB OTG FS clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as USB OTG FS clock
  */
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_OTGFSPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  Macro to get the USB clock (USBCLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as USB OTG FS clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as USB OTG FS clock
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_OTGFSPRE)))

#endif /* STM32F105xC || STM32F107xC */

/** @brief  Macro to configure the ADCx clock (x=1 to 3 depending on devices).
  * @param  __ADCCLKSOURCE__ specifies the ADC clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2 clock divided by 2 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2 clock divided by 4 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2 clock divided by 6 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2 clock divided by 8 selected as ADC clock
  */
#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

/** @brief  Macro to get the ADC clock (ADCxCLK, x=1 to 3 depending on devices).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2 clock divided by 2 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2 clock divided by 4 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2 clock divided by 6 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2 clock divided by 8 selected as ADC clock
  */
#define __HAL_RCC_GET_ADC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE)))

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @addtogroup RCCEx_HSE_Configuration
  * @{
  */

/**
  * @brief  Macro to configure the PLL2 & PLLI2S Predivision factor.
  * @note   Predivision factor can not be changed if PLL2 is used indirectly as system clock
  *         In this case, you have to select another source of the system clock, disable the PLL2 and PLLI2S and
  *         then change the PREDIV2 factor.
  * @param  __HSE_PREDIV2_VALUE__ specifies the PREDIV2 value applied to PLL2 & PLLI2S.
  *         This parameter must be a number between RCC_HSE_PREDIV2_DIV1 and RCC_HSE_PREDIV2_DIV16.
  */
#define __HAL_RCC_HSE_PREDIV2_CONFIG(__HSE_PREDIV2_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV2, (uint32_t)(__HSE_PREDIV2_VALUE__))

/**
  * @brief  Macro to get prediv2 factor for PLL2 & PLL3.
  */
#define __HAL_RCC_HSE_GET_PREDIV2() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV2)

/**
  * @}
  */

/** @addtogroup RCCEx_PLLI2S_Configuration
  * @{
  */

/** @brief Macros to enable the main PLL2.
  * @note   After enabling the main PLL2, the application software should wait on
  *         PLL2RDY flag to be set indicating that PLL2 clock is stable and can
  *         be used as system clock source.
  * @note   The main PLL2 is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLL2_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = ENABLE)

/** @brief Macros to disable the main PLL2.
  * @note   The main PLL2 can not be disabled if it is used indirectly as system clock source
  * @note   The main PLL2 is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLL2_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = DISABLE)

/** @brief macros to configure the main PLL2 multiplication factor.
  * @note   This function must be used only when the main PLL2 is disabled.
  *
  * @param  __PLL2MUL__ specifies the multiplication factor for PLL2 VCO output clock
  *          This parameter can be one of the following values:
  *             @arg @ref RCC_PLL2_MUL8 PLL2VCO = PLL2 clock entry x 8
  *             @arg @ref RCC_PLL2_MUL9 PLL2VCO = PLL2 clock entry x 9
  *             @arg @ref RCC_PLL2_MUL10 PLL2VCO = PLL2 clock entry x 10
  *             @arg @ref RCC_PLL2_MUL11 PLL2VCO = PLL2 clock entry x 11
  *             @arg @ref RCC_PLL2_MUL12 PLL2VCO = PLL2 clock entry x 12
  *             @arg @ref RCC_PLL2_MUL13 PLL2VCO = PLL2 clock entry x 13
  *             @arg @ref RCC_PLL2_MUL14 PLL2VCO = PLL2 clock entry x 14
  *             @arg @ref RCC_PLL2_MUL16 PLL2VCO = PLL2 clock entry x 16
  *             @arg @ref RCC_PLL2_MUL20 PLL2VCO = PLL2 clock entry x 20
  *
  */
#define __HAL_RCC_PLL2_CONFIG(__PLL2MUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL2MUL,(__PLL2MUL__))

/**
  * @}
  */

/** @defgroup RCCEx_I2S_Configuration I2S Configuration
  * @brief  Macros to configure clock source of I2S peripherals.
  * @{
  */

/** @brief  Macro to configure the I2S2 clock.
  * @param  __I2S2CLKSOURCE__ specifies the I2S2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
#define __HAL_RCC_I2S2_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S2SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  Macro to get the I2S2 clock (I2S2CLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
#define __HAL_RCC_GET_I2S2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S2SRC)))

/** @brief  Macro to configure the I2S3 clock.
  * @param  __I2S2CLKSOURCE__ specifies the I2S3 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
#define __HAL_RCC_I2S3_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S3SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  Macro to get the I2S3 clock (I2S3CLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
#define __HAL_RCC_GET_I2S3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S3SRC)))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @addtogroup RCCEx_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);

/**
  * @}
  */

/** @addtogroup RCCEx_Exported_Functions_Group3
  * @{
  */
HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(RCC_PLL2InitTypeDef  *PLL2Init);
HAL_StatusTypeDef HAL_RCCEx_DisablePLL2(void);

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_HAL_RCC_EX_H */


