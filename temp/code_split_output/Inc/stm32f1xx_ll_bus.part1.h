/**
  * @brief  检查APB1外设时钟是否使能
  * @rmtoll APB1ENR      BKPEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      CAN1EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      CAN2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      CECEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      DACEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      I2C1EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      I2C2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      PWREN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      SPI2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      SPI3EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM12EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM13EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM14EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM3EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM4EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM5EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM6EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM7EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      UART4EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      UART5EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      USART2EN      LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      USART3EN      LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      USBEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      WWDGEN        LL_APB1_GRP1_IsEnabledClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 外设状态 (1 或 0).
*/
__STATIC_INLINE uint32_t LL_APB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  /* 读取RCC->APB1ENR寄存器，检查指定的外设时钟位是否置位 */
  return (READ_BIT(RCC->APB1ENR, Periphs) == Periphs);
}

/**
  * @brief  关闭APB1外设时钟。
  * @rmtoll APB1ENR      BKPEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      CAN1EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      CAN2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      CECEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      DACEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      I2C1EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      I2C2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      PWREN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      SPI2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      SPI3EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM12EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM13EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM14EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM3EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM4EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM5EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM6EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM7EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      UART4EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      UART5EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      USART2EN      LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      USART3EN      LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      USBEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      WWDGEN        LL_APB1_GRP1_DisableClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 无
*/
__STATIC_INLINE void LL_APB1_GRP1_DisableClock(uint32_t Periphs)
{
  /* 清除RCC->APB1ENR寄存器中对应的外设时钟使能位，关闭时钟 */
  CLEAR_BIT(RCC->APB1ENR, Periphs);
}

/**
  * @brief  强制复位APB1外设。
  * @rmtoll APB1RSTR     BKPRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     CAN1RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     CAN2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     CECRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     DACRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     I2C1RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     I2C2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     PWRRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     SPI2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     SPI3RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM12RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM13RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM14RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM3RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM4RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM5RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM6RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM7RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     UART4RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     UART5RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     USART2RST     LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     USART3RST     LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     USBRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     WWDGRST       LL_APB1_GRP1_ForceReset
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 无
*/
__STATIC_INLINE void LL_APB1_GRP1_ForceReset(uint32_t Periphs)
{
  /* 置位RCC->APB1RSTR寄存器中的对应位，强制产生复位信号 */
  SET_BIT(RCC->APB1RSTR, Periphs);
}

/**
  * @brief  释放APB1外设复位。
  * @rmtoll APB1RSTR     BKPRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     CAN1RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     CAN2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     CECRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     DACRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     I2C1RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     I2C2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     PWRRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     SPI2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     SPI3RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM12RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM13RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM14RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM3RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM4RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM5RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM6RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM7RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     UART4RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     UART5RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     USART2RST     LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     USART3RST     LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     USBRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     WWDGRST       LL_APB1_GRP1_ReleaseReset
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 无
*/
__STATIC_INLINE void LL_APB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  /* 清除RCC->APB1RSTR寄存器中的对应位，释放复位信号 */
  CLEAR_BIT(RCC->APB1RSTR, Periphs);
}

/**
  * @}
  */

/** @defgroup BUS_LL_EF_APB2 APB2
  * @{
  */

/**
  * @brief  使能APB2外设时钟。
  * @rmtoll APB2ENR      ADC1EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      ADC2EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      ADC3EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      AFIOEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPAEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPBEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPCEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPDEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPEEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPFEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPGEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      SPI1EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM10EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM11EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM15EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM16EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM17EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM1EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM8EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM9EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      USART1EN      LL_APB2_GRP1_EnableClock
  * @param  Periphs 此参数可以是以下值的组合:
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
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  /* 置位RCC->APB2ENR寄存器中的对应位，使能外设时钟 */
  SET_BIT(RCC->APB2ENR, Periphs);
  /* 在RCC外设时钟使能后增加延迟，确保时钟稳定 */
  tmpreg = READ_BIT(RCC->APB2ENR, Periphs);
  (void)tmpreg;
}

/**
  * @brief  检查APB2外设时钟是否使能
  * @rmtoll APB2ENR      ADC1EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      ADC2EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      ADC3EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      AFIOEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPAEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPBEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPCEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPDEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPEEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPFEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPGEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      SPI1EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM10EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM11EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM15EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM16EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM17EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM1EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM8EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM9EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      USART1EN      LL_APB2_GRP1_IsEnabledClock
  * @param  Periphs 此参数可以是以下值的组合:
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
  *         (*) 并非在所有设备中都定义。
  * @retval 外设状态 (1 或 0)。
*/
__STATIC_INLINE uint32_t LL_APB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  /* 读取RCC->APB2ENR寄存器，检查指定的外设时钟位是否置位 */
  return (READ_BIT(RCC->APB2ENR, Periphs) == Periphs);
}

/**
  * @brief  关闭APB2外设时钟。
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
  * @param  Periphs 此参数可以是以下值的组合:
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
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  /* 清除RCC->APB2ENR寄存器中对应的外设时钟使能位，关闭时钟 */
  CLEAR_BIT(RCC->APB2ENR, Periphs);
}

/**
  * @brief  强制复位APB2外设。
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
  * @param  Periphs 此参数可以是以下值的组合:
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
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  /* 置位RCC->APB2RSTR寄存器中的对应位，强制产生复位信号 */
  SET_BIT(RCC->APB2RSTR, Periphs);
}

/**
  * @brief  释放APB2外设复位。
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
  * @param  Periphs 此参数可以是以下值的组合:
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
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  /* 清除RCC->APB2RSTR寄存器中的对应位，释放复位信号 */
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
