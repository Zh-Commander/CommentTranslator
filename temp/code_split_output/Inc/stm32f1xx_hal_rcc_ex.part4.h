#if defined(STM32F101xG) || defined(STM32F103x6) || defined(STM32F103xB)\
 || defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F103xE)\
 || defined(STM32F103xG)
// 检查ADC2时钟是否使能：读取APB2ENR寄存器，判断ADC2EN位是否置1
#define __HAL_RCC_ADC2_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC2EN)) != RESET)
// 检查ADC2时钟是否禁用：读取APB2ENR寄存器，判断ADC2EN位是否清零
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
  * @brief  强制或释放AHB外设复位。
  * @{
  */
// 强制复位所有AHB外设：向AHBRSTR寄存器写入全1
#define __HAL_RCC_AHB_FORCE_RESET()         (RCC->AHBRSTR = 0xFFFFFFFFU)
// 强制复位USB OTG FS：置位AHBRSTR寄存器中的OTGFSRST位
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()       (RCC->AHBRSTR |= (RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
// 强制复位以太网MAC：置位AHBRSTR寄存器中的ETHMACRST位
#define __HAL_RCC_ETHMAC_FORCE_RESET()      (RCC->AHBRSTR |= (RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

// 释放所有AHB外设复位：向AHBRSTR寄存器写入0
#define __HAL_RCC_AHB_RELEASE_RESET()       (RCC->AHBRSTR = 0x00)
// 释放USB OTG FS复位：清除AHBRSTR寄存器中的OTGFSRST位
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()     (RCC->AHBRSTR &= ~(RCC_AHBRSTR_OTGFSRST))
#if defined(STM32F107xC)
// 释放以太网MAC复位：清除AHBRSTR寄存器中的ETHMACRST位
#define __HAL_RCC_ETHMAC_RELEASE_RESET()    (RCC->AHBRSTR &= ~(RCC_AHBRSTR_ETHMACRST))
#endif /* STM32F107xC */

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  强制或释放APB1外设复位。
  * @{
  */

#if defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE)\
 || defined(STM32F103xG) || defined(STM32F105xC) ||defined(STM32F107xC)
// 强制复位CAN1：置位APB1RSTR寄存器中的CAN1RST位
#define __HAL_RCC_CAN1_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_CAN1RST))

// 释放CAN1复位：清除APB1RSTR寄存器中的CAN1RST位
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
// 强制复位CEC
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
  * @brief  强制或释放APB2外设复位。
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
  * @brief  配置外部高速振荡器(HSE)的PLL预分频因子。
  * @note   如果PLL用作系统时钟，则不能更改预分频因子
  *         在这种情况下，必须选择另一个系统时钟源，禁用PLL，然后更改HSE预分频因子。
  * @param  __HSE_PREDIV_VALUE__ 指定应用于HSE的分频值。
  *         该参数必须是RCC_HSE_PREDIV_DIV1和RCC_HSE_PREDIV_DIV16之间的数值。
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV1, (uint32_t)(__HSE_PREDIV_VALUE__))
#else
/**
  * @brief  配置外部高速振荡器(HSE)的PLL预分频因子。
  * @note   如果PLL用作系统时钟，则不能更改预分频因子
  *         在这种情况下，必须选择另一个系统时钟源，禁用PLL，然后更改HSE预分频因子。
  * @param  __HSE_PREDIV_VALUE__ 指定应用于HSE的分频值。
  *         该参数必须是RCC_HSE_PREDIV_DIV1和RCC_HSE_PREDIV_DIV2之间的数值。
  */
#define __HAL_RCC_HSE_PREDIV_CONFIG(__HSE_PREDIV_VALUE__) \
                  MODIFY_REG(RCC->CFGR,RCC_CFGR_PLLXTPRE, (uint32_t)(__HSE_PREDIV_VALUE__))

#endif /* STM32F105xC || STM32F107xC */

#if defined(STM32F105xC) || defined(STM32F107xC) || defined(STM32F100xB)\
 || defined(STM32F100xE)
/**
  * @brief  获取PLL的prediv1因子。
  */
#define __HAL_RCC_HSE_GET_PREDIV() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV1)

#else
/**
  * @brief  获取PLL的prediv1因子。
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

/** @brief 使能主PLLI2S的宏。
  * @note   使能主PLLI2S后，应用程序软件应等待PLLI2SRDY标志置位，
  *         这表示PLLI2S时钟已稳定，可用作系统时钟源。
  * @note   进入停止和待机模式时，硬件会禁用主PLLI2S。
  */
#define __HAL_RCC_PLLI2S_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = ENABLE)

/** @brief 禁用主PLLI2S的宏。
  * @note   进入停止和待机模式时，硬件会禁用主PLLI2S。
  */
#define __HAL_RCC_PLLI2S_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLI2SON_BB = DISABLE)

/** @brief 配置主PLLI2S倍频因子的宏。
  * @note   此功能只能在主PLLI2S禁用时使用。
  *
  * @param  __PLLI2SMUL__ 指定PLLI2S VCO输出时钟的倍频因子
  *          该参数可以是以下值之一：
  *             @arg @ref RCC_PLLI2S_MUL8 PLLI2SVCO = PLLI2S时钟输入 x 8
  *             @arg @ref RCC_PLLI2S_MUL9 PLLI2SVCO = PLLI2S时钟输入 x 9
  *             @arg @ref RCC_PLLI2S_MUL10 PLLI2SVCO = PLLI2S时钟输入 x 10
  *             @arg @ref RCC_PLLI2S_MUL11 PLLI2SVCO = PLLI2S时钟输入 x 11
  *             @arg @ref RCC_PLLI2S_MUL12 PLLI2SVCO = PLLI2S时钟输入 x 12
  *             @arg @ref RCC_PLLI2S_MUL13 PLLI2SVCO = PLLI2S时钟输入 x 13
  *             @arg @ref RCC_PLLI2S_MUL14 PLLI2SVCO = PLLI2S时钟输入 x 14
  *             @arg @ref RCC_PLLI2S_MUL16 PLLI2SVCO = PLLI2S时钟输入 x 16
  *             @arg @ref RCC_PLLI2S_MUL20 PLLI2SVCO = PLLI2S时钟输入 x 20
  *
  */
#define __HAL_RCC_PLLI2S_CONFIG(__PLLI2SMUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL3MUL,(__PLLI2SMUL__))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */

/** @defgroup RCCEx_Peripheral_Configuration Peripheral Configuration
  * @brief  配置不同外设时钟源的宏。
  * @{
  */

#if defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)\
 || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG)
/** @brief  配置USB时钟的宏。
  * @param  __USBCLKSOURCE__ 指定USB时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL时钟1分频作为USB时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL时钟1.5分频作为USB时钟
  */
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_USBPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  获取USB时钟(USBCLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL时钟1分频作为USB时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL时钟1.5分频作为USB时钟
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @brief  配置USB OTG时钟的宏。
  * @param  __USBCLKSOURCE__ 指定USB时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL时钟2分频作为USB OTG FS时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL时钟3分频作为USB OTG FS时钟
  */
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_OTGFSPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  获取USB时钟(USBCLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL时钟2分频作为USB OTG FS时钟
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL时钟3分频作为USB OTG FS时钟
  */
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_OTGFSPRE)))

#endif /* STM32F105xC || STM32F107xC */

/** @brief  配置ADCx时钟的宏(x=1到3，取决于设备)。
  * @param  __ADCCLKSOURCE__ 指定ADC时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2时钟2分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2时钟4分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2时钟6分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2时钟8分频作为ADC时钟
  */
#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

/** @brief  获取ADC时钟(ADCxCLK, x=1到3，取决于设备)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2时钟2分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2时钟4分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2时钟6分频作为ADC时钟
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2时钟8分频作为ADC时钟
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
  * @brief  配置PLL2和PLLI2S预分频因子的宏。
  * @note   如果PLL2被间接用作系统时钟，则无法更改预分频因子
  *         在这种情况下，必须选择另一个系统时钟源，禁用PLL2和PLLI2S，然后更改PREDIV2因子。
  * @param  __HSE_PREDIV2_VALUE__ 指定应用于PLL2和PLLI2S的PREDIV2值。
  *         该参数必须是RCC_HSE_PREDIV2_DIV1和RCC_HSE_PREDIV2_DIV16之间的数值。
  */
#define __HAL_RCC_HSE_PREDIV2_CONFIG(__HSE_PREDIV2_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV2, (uint32_t)(__HSE_PREDIV2_VALUE__))

/**
  * @brief  获取PLL2和PLL3的prediv2因子的宏。
  */
#define __HAL_RCC_HSE_GET_PREDIV2() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV2)

/**
  * @}
  */

/** @addtogroup RCCEx_PLLI2S_Configuration
  * @{
  */

/** @brief 使能主PLL2的宏。
  * @note   使能主PLL2后，应用程序软件应等待PLL2RDY标志置位，
  *         这表示PLL2时钟已稳定，可用作系统时钟源。
  * @note   进入停止和待机模式时，硬件会禁用主PLL2。
  */
#define __HAL_RCC_PLL2_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = ENABLE)

/** @brief 禁用主PLL2的宏。
  * @note   如果PLL2被间接用作系统时钟源，则不能禁用主PLL2
  * @note   进入停止和待机模式时，硬件会禁用主PLL2。
  */
#define __HAL_RCC_PLL2_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = DISABLE)

/** @brief 配置主PLL2倍频因子的宏。
  * @note   此功能只能在主PLL2禁用时使用。
  *
  * @param  __PLL2MUL__ 指定PLL2 VCO输出时钟的倍频因子
  *          该参数可以是以下值之一：
  *             @arg @ref RCC_PLL2_MUL8 PLL2VCO = PLL2时钟输入 x 8
  *             @arg @ref RCC_PLL2_MUL9 PLL2VCO = PLL2时钟输入 x 9
  *             @arg @ref RCC_PLL2_MUL10 PLL2VCO = PLL2时钟输入 x 10
  *             @arg @ref RCC_PLL2_MUL11 PLL2VCO = PLL2时钟输入 x 11
  *             @arg @ref RCC_PLL2_MUL12 PLL2VCO = PLL2时钟输入 x 12
  *             @arg @ref RCC_PLL2_MUL13 PLL2VCO = PLL2时钟输入 x 13
  *             @arg @ref RCC_PLL2_MUL14 PLL2VCO = PLL2时钟输入 x 14
  *             @arg @ref RCC_PLL2_MUL16 PLL2VCO = PLL2时钟输入 x 16
  *             @arg @ref RCC_PLL2_MUL20 PLL2VCO = PLL2时钟输入 x 20
  *
  */
#define __HAL_RCC_PLL2_CONFIG(__PLL2MUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL2MUL,(__PLL2MUL__))

/**
  * @}
  */

/** @defgroup RCCEx_I2S_Configuration I2S Configuration
  * @brief  配置I2S外设时钟源的宏。
  * @{
  */

/** @brief  配置I2S2时钟的宏。
  * @param  __I2S2CLKSOURCE__ 指定I2S2时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_I2S2_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S2SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  获取I2S2时钟(I2S2CLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_GET_I2S2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S2SRC)))

/** @brief  配置I2S3时钟的宏。
  * @param  __I2S2CLKSOURCE__ 指定I2S3时钟源。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
  */
#define __HAL_RCC_I2S3_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S3SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  获取I2S3时钟(I2S3CLK)的宏。
  * @retval 时钟源可以是以下值之一：
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK 系统时钟作为I2S3时钟输入
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO时钟作为I2S3时钟输入
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
/* 导出函数 --------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

// 初始化外设时钟
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
// 获取外设时钟配置
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
// 获取外设时钟频率
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @addtogroup RCCEx_Exported_Functions_Group2
  * @{
  */
// 使能PLLI2S
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);
// 禁用PLLI2S
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);

/**
  * @}
  */

/** @addtogroup RCCEx_Exported_Functions_Group3
  * @{
  */
// 使能PLL2
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
