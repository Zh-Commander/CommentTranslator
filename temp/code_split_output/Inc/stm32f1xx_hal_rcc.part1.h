#define __HAL_RCC_BKP_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_BKPEN)) // 关闭BKP(备份寄存器)时钟，通过清除APB1ENR寄存器中的BKPEN位实现
#define __HAL_RCC_PWR_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_PWREN)) // 关闭PWR(电源控制)时钟，通过清除APB1ENR寄存器中的PWREN位实现

/**
  * @}
  */

/** @defgroup RCC_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB1 peripheral clock.
  *         获取APB1外设时钟的使能或禁用状态。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是禁用的，应用程序在使用前必须使能该时钟。
  * @{
  */

/* APB1外设时钟状态检查宏：读取APB1ENR寄存器对应位，判断时钟是否使能 */
#define __HAL_RCC_TIM2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) != RESET)  // 检查TIM2时钟是否已使能
#define __HAL_RCC_TIM2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) == RESET)  // 检查TIM2时钟是否已禁用
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) != RESET)  // 检查TIM3时钟是否已使能
#define __HAL_RCC_TIM3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) == RESET)  // 检查TIM3时钟是否已禁用
#define __HAL_RCC_WWDG_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) != RESET)  // 检查WWDG(窗口看门狗)时钟是否已使能
#define __HAL_RCC_WWDG_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) == RESET)  // 检查WWDG时钟是否已禁用
#define __HAL_RCC_USART2_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) != RESET)// 检查USART2时钟是否已使能
#define __HAL_RCC_USART2_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) == RESET)// 检查USART2时钟是否已禁用
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) != RESET)  // 检查I2C1时钟是否已使能
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) == RESET)  // 检查I2C1时钟是否已禁用
#define __HAL_RCC_BKP_IS_CLK_ENABLED()        ((RCC->APB1ENR & (RCC_APB1ENR_BKPEN)) != RESET)   // 检查BKP时钟是否已使能
#define __HAL_RCC_BKP_IS_CLK_DISABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_BKPEN)) == RESET)   // 检查BKP时钟是否已禁用
#define __HAL_RCC_PWR_IS_CLK_ENABLED()        ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) != RESET)   // 检查PWR时钟是否已使能
#define __HAL_RCC_PWR_IS_CLK_DISABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) == RESET)   // 检查PWR时钟是否已禁用

/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Enable_Disable APB2 Clock Enable Disable
  * @brief  Enable or disable the High Speed APB (APB2) peripheral clock.
  *         使能或禁用高速APB(APB2)外设时钟。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是禁用的，应用程序在使用前必须使能该时钟。
  * @{
  */

/* APB2外设时钟使能宏：使用do-while(0)结构确保宏定义的安全性，并包含读操作延时 */
#define __HAL_RCC_AFIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \ // 定义临时变量，用于产生延时
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);\ // 设置AFIOEN位，使能AFIO时钟
                                        /* Delay after an RCC peripheral clock enabling */\ // RCC外设时钟使能后的延时
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);\ // 读取刚设置的位，确保时钟使能生效
                                        UNUSED(tmpreg); \ // 防止编译器警告变量未使用
                                      } while(0U)

#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);\ // 设置IOPAEN位，使能GPIOA时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);\ // 设置IOPBEN位，使能GPIOB时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);\ // 设置IOPCEN位，使能GPIOC时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_GPIOD_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);\ // 设置IOPDEN位，使能GPIOD时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\ // 设置ADC1EN位，使能ADC1时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_TIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\ // 设置TIM1EN位，使能TIM1时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\ // 设置SPI1EN位，使能SPI1时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

#define __HAL_RCC_USART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\ // 设置USART1EN位，使能USART1时钟
                                        /* Delay after an RCC peripheral clock enabling */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* APB2外设时钟禁用宏：直接清除对应的使能位 */
#define __HAL_RCC_AFIO_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_AFIOEN)) // 禁用AFIO时钟
#define __HAL_RCC_GPIOA_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPAEN)) // 禁用GPIOA时钟
#define __HAL_RCC_GPIOB_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPBEN)) // 禁用GPIOB时钟
#define __HAL_RCC_GPIOC_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPCEN)) // 禁用GPIOC时钟
#define __HAL_RCC_GPIOD_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPDEN)) // 禁用GPIOD时钟
#define __HAL_RCC_ADC1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN)) // 禁用ADC1时钟

#define __HAL_RCC_TIM1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN)) // 禁用TIM1时钟
#define __HAL_RCC_SPI1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN)) // 禁用SPI1时钟
#define __HAL_RCC_USART1_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN)) // 禁用USART1时钟

/**
  * @}
  */

/** @defgroup RCC_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  Get the enable or disable status of the APB2 peripheral clock.
  *         获取APB2外设时钟的使能或禁用状态。
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  *         复位后，外设时钟（用于寄存器读写访问）是禁用的，应用程序在使用前必须使能该时钟。
  * @{
  */

/* APB2外设时钟状态检查宏：读取APB2ENR寄存器对应位，判断时钟是否使能 */
#define __HAL_RCC_AFIO_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_AFIOEN)) != RESET) // 检查AFIO时钟是否已使能
#define __HAL_RCC_AFIO_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_AFIOEN)) == RESET) // 检查AFIO时钟是否已禁用
#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPAEN)) != RESET) // 检查GPIOA时钟是否已使能
#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPAEN)) == RESET) // 检查GPIOA时钟是否已禁用
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPBEN)) != RESET) // 检查GPIOB时钟是否已使能
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPBEN)) == RESET) // 检查GPIOB时钟是否已禁用
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPCEN)) != RESET) // 检查GPIOC时钟是否已使能
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPCEN)) == RESET) // 检查GPIOC时钟是否已禁用
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPDEN)) != RESET) // 检查GPIOD时钟是否已使能
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPDEN)) == RESET) // 检查GPIOD时钟是否已禁用
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) != RESET) // 检查ADC1时钟是否已使能
#define __HAL_RCC_ADC1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) == RESET) // 检查ADC1时钟是否已禁用
#define __HAL_RCC_TIM1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET) // 检查TIM1时钟是否已使能
#define __HAL_RCC_TIM1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET) // 检查TIM1时钟是否已禁用
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET) // 检查SPI1时钟是否已使能
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET) // 检查SPI1时钟是否已禁用
#define __HAL_RCC_USART1_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) != RESET)// 检查USART1时钟是否已使能
#define __HAL_RCC_USART1_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) == RESET)// 检查USART1时钟是否已禁用

/**
  * @}
  */

/** @defgroup RCC_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  Force or release APB1 peripheral reset.
  *         强制或释放APB1外设复位。
  * @{
  */
/* APB1外设强制复位宏：通过置位APB1RSTR寄存器对应位触发复位 */
#define __HAL_RCC_APB1_FORCE_RESET()       (RCC->APB1RSTR = 0xFFFFFFFFU) // 强制复位所有APB1外设
#define __HAL_RCC_TIM2_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM2RST)) // 强制复位TIM2
#define __HAL_RCC_TIM3_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST)) // 强制复位TIM3
#define __HAL_RCC_WWDG_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_WWDGRST)) // 强制复位WWDG
#define __HAL_RCC_USART2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_USART2RST)) // 强制复位USART2
#define __HAL_RCC_I2C1_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C1RST)) // 强制复位I2C1

#define __HAL_RCC_BKP_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_BKPRST)) // 强制复位BKP
#define __HAL_RCC_PWR_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_PWRRST)) // 强制复位PWR

/* APB1外设释放复位宏：通过清除APB1RSTR寄存器对应位结束复位 */
#define __HAL_RCC_APB1_RELEASE_RESET()      (RCC->APB1RSTR = 0x00) // 释放所有APB1外设复位
#define __HAL_RCC_TIM2_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM2RST)) // 释放TIM2复位
#define __HAL_RCC_TIM3_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST)) // 释放TIM3复位
#define __HAL_RCC_WWDG_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_WWDGRST)) // 释放WWDG复位
#define __HAL_RCC_USART2_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST)) // 释放USART2复位
#define __HAL_RCC_I2C1_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C1RST)) // 释放I2C1复位

#define __HAL_RCC_BKP_RELEASE_RESET()        (RCC->APB1RSTR &= ~(RCC_APB1RSTR_BKPRST)) // 释放BKP复位
#define __HAL_RCC_PWR_RELEASE_RESET()        (RCC->APB1RSTR &= ~(RCC_APB1RSTR_PWRRST)) // 释放PWR复位

/**
  * @}
  */

/** @defgroup RCC_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  Force or release APB2 peripheral reset.
  *         强制或释放APB2外设复位。
  * @{
  */
/* APB2外设强制复位宏：通过置位APB2RSTR寄存器对应位触发复位 */
#define __HAL_RCC_APB2_FORCE_RESET()       (RCC->APB2RSTR = 0xFFFFFFFFU) // 强制复位所有APB2外设
#define __HAL_RCC_AFIO_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_AFIORST)) // 强制复位AFIO
#define __HAL_RCC_GPIOA_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPARST)) // 强制复位GPIOA
#define __HAL_RCC_GPIOB_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPBRST)) // 强制复位GPIOB
#define __HAL_RCC_GPIOC_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPCRST)) // 强制复位GPIOC
#define __HAL_RCC_GPIOD_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPDRST)) // 强制复位GPIOD
#define __HAL_RCC_ADC1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC1RST)) // 强制复位ADC1

#define __HAL_RCC_TIM1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST)) // 强制复位TIM1
#define __HAL_RCC_SPI1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST)) // 强制复位SPI1
#define __HAL_RCC_USART1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST)) // 强制复位USART1

/* APB2外设释放复位宏：通过清除APB2RSTR寄存器对应位结束复位 */
#define __HAL_RCC_APB2_RELEASE_RESET()      (RCC->APB2RSTR = 0x00) // 释放所有APB2外设复位
#define __HAL_RCC_AFIO_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_AFIORST)) // 释放AFIO复位
#define __HAL_RCC_GPIOA_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPARST)) // 释放GPIOA复位
#define __HAL_RCC_GPIOB_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPBRST)) // 释放GPIOB复位
#define __HAL_RCC_GPIOC_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPCRST)) // 释放GPIOC复位
#define __HAL_RCC_GPIOD_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPDRST)) // 释放GPIOD复位
#define __HAL_RCC_ADC1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC1RST)) // 释放ADC1复位

#define __HAL_RCC_TIM1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST)) // 释放TIM1复位
#define __HAL_RCC_SPI1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST)) // 释放SPI1复位
#define __HAL_RCC_USART1_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST)) // 释放USART1复位

/**
  * @}
  */

/** @defgroup RCC_HSI_Configuration HSI Configuration
  * @{
  */

/** @brief  Macros to enable or disable the Internal High Speed oscillator (HSI).
  *         使能或禁用内部高速振荡器(HSI)的宏。
  * @note   The HSI is stopped by hardware when entering STOP and STANDBY modes.
  *         当进入STOP和STANDBY模式时，硬件会停止HSI。
  * @note   HSI can not be stopped if it is used as system clock source. In this case,
  *         you have to select another source of the system clock then stop the HSI.
  *         如果HSI被用作系统时钟源，则不能停止HSI。在这种情况下，必须先选择另一个系统时钟源，然后停止HSI。
  * @note   After enabling the HSI, the application software should wait on HSIRDY
  *         flag to be set indicating that HSI clock is stable and can be used as
  *         system clock source.
  *         使能HSI后，应用程序软件应等待HSIRDY标志置位，表明HSI时钟已稳定，可用作系统时钟源。
  * @note   When the HSI is stopped, HSIRDY flag goes low after 6 HSI oscillator
  *         clock cycles.
  *         当HSI停止时，HSIRDY标志在6个HSI振荡器时钟周期后变低。
  */
/* 使用位带操作使能/禁用HSI，效率更高 */
#define __HAL_RCC_HSI_ENABLE()  (*(__IO uint32_t *) RCC_CR_HSION_BB = ENABLE)  // 使能内部高速时钟HSI
#define __HAL_RCC_HSI_DISABLE() (*(__IO uint32_t *) RCC_CR_HSION_BB = DISABLE) // 禁用内部高速时钟HSI

/** @brief  Macro to adjust the Internal High Speed oscillator (HSI) calibration value.
  *         调整内部高速振荡器(HSI)校准值的宏。
  * @note   The calibration is used to compensate for the variations in voltage
  *         and temperature that influence the frequency of the internal HSI RC.
  *         校准用于补偿电压和温度变化对内部HSI RC频率的影响。
  * @param  _HSICALIBRATIONVALUE_ specifies the calibration trimming value.
  *         (default is RCC_HSICALIBRATION_DEFAULT).
  *         This parameter must be a number between 0 and 0x1F.
  *         指定校准调整值(默认为RCC_HSICALIBRATION_DEFAULT)，该参数必须是0到0x1F之间的数字。
  */
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(_HSICALIBRATIONVALUE_) \
          (MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, (uint32_t)(_HSICALIBRATIONVALUE_) << RCC_CR_HSITRIM_Pos)) // 修改CR寄存器中的HSITRIM位域，调整HSI校准值

/**
  * @}
  */

/** @defgroup RCC_LSI_Configuration  LSI Configuration
  * @{
  */

/** @brief Macro to enable the Internal Low Speed oscillator (LSI).
  *        使能内部低速振荡器(LSI)的宏。
  * @note   After enabling the LSI, the application software should wait on
  *         LSIRDY flag to be set indicating that LSI clock is stable and can
  *         be used to clock the IWDG and/or the RTC.
  *         使能LSI后，应用程序软件应等待LSIRDY标志置位，表明LSI时钟已稳定，可用于驱动IWDG和/或RTC。
  */
#define __HAL_RCC_LSI_ENABLE()  (*(__IO uint32_t *) RCC_CSR_LSION_BB = ENABLE) // 使能内部低速时钟LSI

/** @brief Macro to disable the Internal Low Speed oscillator (LSI).
  *        禁用内部低速振荡器(LSI)的宏。
  * @note   LSI can not be disabled if the IWDG is running.
  *         如果IWDG正在运行，则不能禁用LSI。
  * @note   When the LSI is stopped, LSIRDY flag goes low after 6 LSI oscillator
  *         clock cycles.
  *         当LSI停止时，LSIRDY标志在6个LSI振荡器时钟周期后变低。
  */
#define __HAL_RCC_LSI_DISABLE() (*(__IO uint32_t *) RCC_CSR_LSION_BB = DISABLE) // 禁用内部低速时钟LSI

/**
  * @}
  */

/** @defgroup RCC_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @brief  Macro to configure the External High Speed oscillator (HSE).
  *         配置外部高速振荡器(HSE)的宏。
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this macro. User should request a transition to HSE Off
  *         first and then HSE On or HSE Bypass.
  *         此宏不支持从HSE旁路到HSE开启，以及从HSE开启到HSE旁路的直接转换。用户应先转换为HSE关闭，然后再转为HSE开启或旁路。
  * @note   After enabling the HSE (RCC_HSE_ON or RCC_HSE_Bypass), the application
  *         software should wait on HSERDY flag to be set indicating that HSE clock
  *         is stable and can be used to clock the PLL and/or system clock.
  *         使能HSE（RCC_HSE_ON或RCC_HSE_Bypass）后，应用程序软件应等待HSERDY标志置位，表明HSE时钟已稳定，可用于驱动PLL和/或系统时钟。
  * @note   HSE state can not be changed if it is used directly or through the
  *         PLL as system clock. In this case, you have to select another source
  *         of the system clock then change the HSE state (ex. disable it).
  *         如果HSE直接或通过PLL用作系统时钟，则不能更改HSE状态。在这种情况下，必须先选择另一个系统时钟源，然后更改HSE状态（例如禁用它）。
  * @note   The HSE is stopped by hardware when entering STOP and STANDBY modes.
  *         当进入STOP和STANDBY模式时，硬件会停止HSE。
  * @note   This function reset the CSSON bit, so if the clock security system(CSS)
  *         was previously enabled you have to enable it again after calling this
  *         function.
  *         此函数会重置CSSON位，因此如果之前启用了时钟安全系统(CSS)，则在调用此函数后必须再次启用它。
  * @param  __STATE__ specifies the new state of the HSE.
  *                   指定HSE的新状态。
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_HSE_OFF turn OFF the HSE oscillator, HSERDY flag goes low after
  *                              6 HSE oscillator clock cycles.
  *                              关闭HSE振荡器，HSERDY标志在6个HSE振荡器时钟周期后变低。
  *            @arg @ref RCC_HSE_ON turn ON the HSE oscillator
  *                              开启HSE振荡器。
  *            @arg @ref RCC_HSE_BYPASS HSE oscillator bypassed with external clock
  *                              HSE振荡器被外部时钟旁路。
  */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_HSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \ // 开启HSE：设置HSEON位
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \ // 关闭HSE：清除HSEON位
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \ // 同时清除HSEBYP位
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);                    \ // 旁路模式：先设置HSEBYP位
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \ // 再设置HSEON位
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \ // 默认情况：关闭HSE
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \ // 清除旁路设置
                      }                                                     \
                    }while(0U)

/**
  * @}
  */

/** @defgroup RCC_LSE_Configuration LSE Configuration
  * @{
  */
