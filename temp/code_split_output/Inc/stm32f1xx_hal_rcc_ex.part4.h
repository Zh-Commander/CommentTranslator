#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
// 检查ADC2时钟是否使能 // 检查APB2外设时钟使能寄存器中的ADC2使能位
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
// 检查ADC2时钟是否禁用
#define __HAL_RCC_ADC2_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) == RESET)
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */
#if defined(STM32F100xB) || defined(STM32F100xE)
// 检查TIM15时钟是否使能
#define __HAL_RCC_TIM15_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) != RESET)
// 检查TIM15时钟是否禁用
#define __HAL_RCC_TIM15_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM15EN)) == RESET)
// 检查TIM16时钟是否使能
#define __HAL_RCC_TIM16_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) != RESET)
// 检查TIM16时钟是否禁用
#define __HAL_RCC_TIM16_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM16EN)) == RESET)
// 检查TIM17时钟是否使能
#define __HAL_RCC_TIM17_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) != RESET)
// 检查TIM17时钟是否禁用
#define __HAL_RCC_TIM17_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM17EN)) == RESET)
#endif /* STM32F100xB || STM32F100xE */
#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
// 检查GPIOE时钟是否使能
#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) != RESET)
// 检查GPIOE时钟是否禁用
#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPEEN)) == RESET)
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */
#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
// 检查GPIOF时钟是否使能
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
// 检查GPIOF时钟是否禁用
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
// 检查GPIOG时钟是否使能
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
// 检查GPIOG时钟是否禁用
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/
#if defined(STM32F103xE) || defined(STM32F103xG)
// 检查TIM8时钟是否使能
#define __HAL_RCC_TIM8_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) != RESET)
// 检查TIM8时钟是否禁用
#define __HAL_RCC_TIM8_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM8EN)) == RESET)
// 检查ADC3时钟是否使能
#define __HAL_RCC_ADC3_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) != RESET)
// 检查ADC3时钟是否禁用
#define __HAL_RCC_ADC3_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC3EN)) == RESET)
#endif /* STM32F103xE || STM32F103xG */
#if defined(STM32F100xE)
// 检查GPIOF时钟是否使能
#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) != RESET)
// 检查GPIOF时钟是否禁用
#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPFEN)) == RESET)
// 检查GPIOG时钟是否使能
#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) != RESET)
// 检查GPIOG时钟是否禁用
#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPGEN)) == RESET)
#endif /* STM32F100xE */
#if defined(STM32F101xG) || defined(STM32F103xG)
// 检查TIM9时钟是否使能
#define __HAL_RCC_TIM9_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) != RESET)
// 检查TIM9时钟是否禁用
#define __HAL_RCC_TIM9_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM9EN)) == RESET)
// 检查TIM10时钟是否使能
#define __HAL_RCC_TIM10_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) != RESET)
// 检查TIM10时钟是否禁用
#define __HAL_RCC_TIM10_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM10EN)) == RESET)
// 检查TIM11时钟是否使能
#define __HAL_RCC_TIM11_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM11EN)) != RESET)
// 检查TIM11时钟是否禁用
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
// 强制复位所有AHB外设 // 将AHB复位寄存器设置为全1
#define __HAL_RCC_AHB_FORCE_RESET()         (RCC->AHBRSTR = 0xFFFFFFFFU)
// 强制复位USB OTG FS // 设置USB OTG全速复位位
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()       (RCC->AHBRSTR |= (RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
// 强制复位以太网MAC // 设置以太网MAC复位位
#define __HAL_RCC_ETHMAC_FORCE_RESET()      (RCC->AHBRSTR |= (RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

// 释放AHB外设复位 // 将AHB复位寄存器清零
#define __HAL_RCC_AHB_RELEASE_RESET()       (RCC->AHBRSTR = 0x00)
// 释放USB OTG FS复位 // 清除USB OTG全速复位位
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()     (RCC->AHBRSTR &= ~(RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
// 释放以太网MAC复位 // 清除以太网MAC复位位
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
// 强制复位CAN1 // 设置CAN1复位位
#define __HAL_RCC_CAN1_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN1RST))

// 释放CAN1复位 // 清除CAN1复位位
#define __HAL_RCC_CAN1_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN1RST))
#endif /* STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined(STM32F100xE) || defined(STM32F101xB)\
 || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F102xB)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)\
 || defined(STM32F105xC) || defined(STM32F107xC)
// 强制复位TIM4
#define __HAL_RCC_TIM4_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM4RST))
// 强制复位SPI2
#define __HAL_RCC_SPI2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI2RST))
// 强制复位USART3
#define __HAL_RCC_USART3_FORCE_RESET()      (RCC->APB1RSTR |= (RCC_APB1RSTR_USART3RST))
// 强制复位I2C2
#define __HAL_RCC_I2C2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C2RST))

// 释放TIM4复位
#define __HAL_RCC_TIM4_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM4RST))
// 释放SPI2复位
#define __HAL_RCC_SPI2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI2RST))
// 释放USART3复位
#define __HAL_RCC_USART3_RELEASE_RESET()    (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART3RST))
// 释放I2C2复位
#define __HAL_RCC_I2C2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C2RST))
#endif /* STM32F100xB || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
// 强制复位USB
#define __HAL_RCC_USB_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_USBRST))
// 释放USB复位
#define __HAL_RCC_USB_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USBRST))
#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC)
// 强制复位TIM5
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
// 强制复位TIM6
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
// 强制复位TIM7
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
// 强制复位SPI3
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
// 强制复位UART4
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
// 强制复位UART5
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))
// 强制复位DAC
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))

// 释放TIM5复位
#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
// 释放TIM6复位
#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
// 释放TIM7复位
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
// 释放SPI3复位
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
// 释放UART4复位
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
// 释放UART5复位
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
// 释放DAC复位
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F100xB) || defined  (STM32F100xE)
// 强制复位TIM6
#define __HAL_RCC_TIM6_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM6RST))
// 强制复位TIM7
#define __HAL_RCC_TIM7_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM7RST))
// 强制复位DAC
#define __HAL_RCC_DAC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_DACRST))
// 强制复位CEC (HDMI-CEC)
#define __HAL_RCC_CEC_FORCE_RESET()         (RCC->APB1RSTR |= (RCC_APB1RSTR_CECRST))

// 释放TIM6复位
#define __HAL_RCC_TIM6_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM6RST))
// 释放TIM7复位
#define __HAL_RCC_TIM7_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM7RST))
// 释放DAC复位
#define __HAL_RCC_DAC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_DACRST))
// 释放CEC复位
#define __HAL_RCC_CEC_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CECRST))
#endif /* STM32F100xB || STM32F100xE */

#if defined  (STM32F100xE)
// 强制复位TIM5
#define __HAL_RCC_TIM5_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM5RST))
// 强制复位TIM12
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
// 强制复位TIM13
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
// 强制复位TIM14
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))
// 强制复位SPI3
#define __HAL_RCC_SPI3_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_SPI3RST))
// 强制复位UART4
#define __HAL_RCC_UART4_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART4RST))
// 强制复位UART5
#define __HAL_RCC_UART5_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_UART5RST))

// 释放TIM5复位
#define __HAL_RCC_TIM5_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM5RST))
// 释放TIM12复位
#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
// 释放TIM13复位
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
// 释放TIM14复位
#define __HAL_RCC_TIM14_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM14RST))
// 释放SPI3复位
#define __HAL_RCC_SPI3_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_SPI3RST))
// 释放UART4复位
#define __HAL_RCC_UART4_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART4RST))
// 释放UART5复位
#define __HAL_RCC_UART5_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_UART5RST))
#endif /* STM32F100xE */

#if defined(STM32F105xC) || defined(STM32F107xC)
// 强制复位CAN2
#define __HAL_RCC_CAN2_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN2RST))

// 释放CAN2复位
#define __HAL_RCC_CAN2_RELEASE_RESET()      (RCC->APB1RSTR &= ~(RCC_APB1RSTR_CAN2RST))
#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F101xG) || defined(STM32F103xG)
// 强制复位TIM12
#define __HAL_RCC_TIM12_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM12RST))
// 强制复位TIM13
#define __HAL_RCC_TIM13_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM13RST))
// 强制复位TIM14
#define __HAL_RCC_TIM14_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM14RST))

// 释放TIM12复位
#define __HAL_RCC_TIM12_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM12RST))
// 释放TIM13复位
#define __HAL_RCC_TIM13_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM13RST))
// 释放TIM14复位
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
// 强制复位ADC2
#define __HAL_RCC_ADC2_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC2RST))

// 释放ADC2复位
#define __HAL_RCC_ADC2_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC2RST))
#endif /* STM32F101xG || STM32F103x6 || STM32F103xB || STM32F105xC || STM32F107xC || STM32F103xE || STM32F103xG */

#if defined(STM32F100xB) || defined(STM32F100xE)
// 强制复位TIM15
#define __HAL_RCC_TIM15_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM15RST))
// 强制复位TIM16
#define __HAL_RCC_TIM16_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM16RST))
// 强制复位TIM17
#define __HAL_RCC_TIM17_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM17RST))

// 释放TIM15复位
#define __HAL_RCC_TIM15_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM15RST))
// 释放TIM16复位
#define __HAL_RCC_TIM16_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM16RST))
// 释放TIM17复位
#define __HAL_RCC_TIM17_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM17RST))
#endif /* STM32F100xB || STM32F100xE */

#if defined(STM32F100xE) || defined(STM32F101xB) || defined(STM32F101xE)\
 || defined(STM32F101xG) || defined(STM32F100xB) || defined(STM32F103xB)\
 || defined(STM32F103xE) || defined(STM32F103xG) || defined(STM32F105xC)\
 || defined(STM32F107xC)
// 强制复位GPIOE
#define __HAL_RCC_GPIOE_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPERST))

// 释放GPIOE复位
#define __HAL_RCC_GPIOE_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPERST))
#endif /* STM32F101x6 || STM32F101xB || STM32F101xE || (...) || STM32F105xC || STM32F107xC */

#if defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG)\
 || defined(STM32F103xG)
// 强制复位GPIOF
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
// 强制复位GPIOG
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

// 释放GPIOF复位
#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
// 释放GPIOG复位
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif /* STM32F101xE || STM32F103xE || STM32F101xG || STM32F103xG*/

#if defined(STM32F103xE) || defined(STM32F103xG)
// 强制复位TIM8
#define __HAL_RCC_TIM8_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM8RST))
// 强制复位ADC3
#define __HAL_RCC_ADC3_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC3RST))

// 释放TIM8复位
#define __HAL_RCC_TIM8_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM8RST))
// 释放ADC3复位
#define __HAL_RCC_ADC3_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC3RST))
#endif /* STM32F103xE || STM32F103xG */

#if defined(STM32F100xE)
// 强制复位GPIOF
#define __HAL_RCC_GPIOF_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPFRST))
// 强制复位GPIOG
#define __HAL_RCC_GPIOG_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPGRST))

// 释放GPIOF复位
#define __HAL_RCC_GPIOF_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPFRST))
// 释放GPIOG复位
#define __HAL_RCC_GPIOG_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPGRST))
#endif /* STM32F100xE */

#if defined(STM32F101xG) || defined(STM32F103xG)
// 强制复位TIM9
#define __HAL_RCC_TIM9_FORCE_RESET()        (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM9RST))
// 强制复位TIM10
#define __HAL_RCC_TIM10_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM10RST))
// 强制复位TIM11
#define __HAL_RCC_TIM11_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM11RST))

// 释放TIM9复位
#define __HAL_RCC_TIM9_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM9RST))
// 释放TIM10复位
#define __HAL_RCC_TIM10_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM10RST))
// 释放TIM11复位
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
// 配置HSE预分频因子(适用于互联型和价值型产品) // 通过修改CFGR2寄存器来设置PREDIV1
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
// 配置HSE预分频因子(适用于其他产品) // 通过修改CFGR寄存器来设置PLLXTPRE
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR,RCC_CFGR_PLLXTPRE, (uint32_t)(__HSE_PREDIV_VALUE__))

#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/**
  * @brief  Macro to get prediv1 factor for PLL.
  */
// 获取HSE预分频因子(适用于互联型和价值型产品) // 读取CFGR2寄存器的PREDIV1位
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1)

#else
/**
  * @brief  Macro to get prediv1 factor for PLL.
  */
// 获取HSE预分频因子(适用于其他产品) // 读取CFGR寄存器的PLLXTPRE位
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
// 使能PLLI2S // 使用位带操作使能PLLI2S
#define __HAL_RCC_PLLI2S_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = ENABLE)

/** @brief Macros to disable the main PLLI2S.
  * @note   The main PLLI2S is disabled by hardware when entering STOP and STANDBY modes.
  */
// 禁用PLLI2S // 使用位带操作禁用PLLI2S
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
// 配置PLLI2S倍频因子 // 修改CFGR2寄存器中的PLL3MUL位
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
// 配置USB时钟源 // 修改CFGR寄存器中的USBPRE位
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  Macro to get the USB clock (USBCLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL clock divided by 1 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL clock divided by 1.5 selected as USB clock
  */
// 获取USB时钟源配置 // 读取CFGR寄存器中的USBPRE位
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @brief  Macro to configure the USB OTSclock.
  * @param  __USBCLKSOURCE__ specifies the USB clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as USB OTG FS clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as USB OTG FS clock
  */
// 配置USB OTG FS时钟源 // 修改CFGR寄存器中的OTGFSPRE位
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_OTGFSPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  Macro to get the USB clock (USBCLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as USB OTG FS clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as USB OTG FS clock
  */
// 获取USB OTG FS时钟源配置 // 读取CFGR寄存器中的OTGFSPRE位
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
// 配置ADC时钟源 // 修改CFGR寄存器中的ADCPRE位
#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

/** @brief  Macro to get the ADC clock (ADCxCLK, x=1 to 3 depending on devices).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2 clock divided by 2 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2 clock divided by 4 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2 clock divided by 6 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2 clock divided by 8 selected as ADC clock
  */
// 获取ADC时钟源配置 // 读取CFGR寄存器中的ADCPRE位
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
// 配置PREDIV2因子(用于PLL2和PLLI2S) // 修改CFGR2寄存器中的PREDIV2位
#define __HAL_RCC_HSE_PREDIV2_CONFIG(__HSE_PREDIV2_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV2, (uint32_t)(__HSE_PREDIV2_VALUE__))

/**
  * @brief  Macro to get prediv2 factor for PLL2 & PLL3.
  */
// 获取PREDIV2因子 // 读取CFGR2寄存器中的PREDIV2位
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
// 使能PLL2 // 使用位带操作使能PLL2
#define __HAL_RCC_PLL2_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = ENABLE)

/** @brief Macros to disable the main PLL2.
  * @note   The main PLL2 can not be disabled if it is used indirectly as system clock source
  * @note   The main PLL2 is disabled by hardware when entering STOP and STANDBY modes.
  */
// 禁用PLL2 // 使用位带操作禁用PLL2
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
// 配置PLL2倍频因子 // 修改CFGR2寄存器中的PLL2MUL位
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
// 配置I2S2时钟源 // 修改CFGR2寄存器中的I2S2SRC位
#define __HAL_RCC_I2S2_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S2SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  Macro to get the I2S2 clock (I2S2CLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 获取I2S2时钟源配置 // 读取CFGR2寄存器中的I2S2SRC位
#define __HAL_RCC_GET_I2S2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S2SRC)))

/** @brief  Macro to configure the I2S3 clock.
  * @param  __I2S2CLKSOURCE__ specifies the I2S3 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 配置I2S3时钟源 // 修改CFGR2寄存器中的I2S3SRC位
#define __HAL_RCC_I2S3_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S3SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  Macro to get the I2S3 clock (I2S3CLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 获取I2S3时钟源配置 // 读取CFGR2寄存器中的I2S3SRC位
#define __HAL_RCC_GET_I2S3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S3SRC)))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

// 初始化外设时钟 // 参数: PeriphClkInit 指向RCC_PeriphCLKInitTypeDef结构的指针，包含外设时钟配置信息
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
// 获取外设时钟配置 // 参数: PeriphClkInit 指向RCC_PeriphCLKInitTypeDef结构的指针，用于返回当前外设时钟配置
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
// 获取特定外设时钟频率 // 参数: PeriphClk 外设时钟标识，返回值: 外设时钟频率
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @addtogroup RCCEx_Exported_Functions_Group2
  * @{
  */
// 使能PLLI2S // 参数: PLLI2SInit 指向RCC_PLLI2SInitTypeDef结构的指针，包含PLLI2S配置信息
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
// 禁用PLLI2S
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);

/**
  * @}
  */

/** @addtogroup RCCEx_Exported_Functions_Group3
  * @{
  */
// 使能PLL2 // 参数: PLL2Init 指向RCC_PLL2InitTypeDef结构的指针，包含PLL2配置信息
HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(RCC_PLL2InitTypeDef  *PLL2Init);
// 禁用PLL2
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
