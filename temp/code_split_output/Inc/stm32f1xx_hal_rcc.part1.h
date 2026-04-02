#define __HAL_RCC_BKP_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_BKPEN)) // 关闭BKP(备份寄存器)时钟，通过清除APB1ENR寄存器的对应位
#define __HAL_RCC_PWR_CLK_DISABLE()       (RCC->APB1ENR &= ~(RCC_APB1ENR_PWREN)) // 关闭PWR(电源接口)时钟，通过清除APB1ENR寄存器的对应位

/**
  * @}
  */

/** @defgroup RCC_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enable Disable Status
  * @brief  获取APB1外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */

/* 检查TIM2时钟是否已使能 (通过读取APB1ENR寄存器对应位) */
#define __HAL_RCC_TIM2_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) != RESET)
/* 检查TIM2时钟是否已禁用 */
#define __HAL_RCC_TIM2_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM2EN)) == RESET)
/* 检查TIM3时钟是否已使能 */
#define __HAL_RCC_TIM3_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) != RESET)
/* 检查TIM3时钟是否已禁用 */
#define __HAL_RCC_TIM3_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_TIM3EN)) == RESET)
/* 检查WWDG(窗口看门狗)时钟是否已使能 */
#define __HAL_RCC_WWDG_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) != RESET)
/* 检查WWDG时钟是否已禁用 */
#define __HAL_RCC_WWDG_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_WWDGEN)) == RESET)
/* 检查USART2时钟是否已使能 */
#define __HAL_RCC_USART2_IS_CLK_ENABLED()     ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) != RESET)
/* 检查USART2时钟是否已禁用 */
#define __HAL_RCC_USART2_IS_CLK_DISABLED()    ((RCC->APB1ENR & (RCC_APB1ENR_USART2EN)) == RESET)
/* 检查I2C1时钟是否已使能 */
#define __HAL_RCC_I2C1_IS_CLK_ENABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) != RESET)
/* 检查I2C1时钟是否已禁用 */
#define __HAL_RCC_I2C1_IS_CLK_DISABLED()      ((RCC->APB1ENR & (RCC_APB1ENR_I2C1EN)) == RESET)
/* 检查BKP时钟是否已使能 */
#define __HAL_RCC_BKP_IS_CLK_ENABLED()        ((RCC->APB1ENR & (RCC_APB1ENR_BKPEN)) != RESET)
/* 检查BKP时钟是否已禁用 */
#define __HAL_RCC_BKP_IS_CLK_DISABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_BKPEN)) == RESET)
/* 检查PWR时钟是否已使能 */
#define __HAL_RCC_PWR_IS_CLK_ENABLED()        ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) != RESET)
/* 检查PWR时钟是否已禁用 */
#define __HAL_RCC_PWR_IS_CLK_DISABLED()       ((RCC->APB1ENR & (RCC_APB1ENR_PWREN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Enable_Disable APB2 Clock Enable Disable
  * @brief  使能或禁用高速APB (APB2) 外设时钟。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */

/* 使能AFIO(复用功能I/O)时钟。
   使用do...while(0)结构是为了保证宏定义的安全性。
   操作步骤：1. 设置APB2ENR寄存器的AFIOEN位。
            2. 读取该位以产生一个时钟周期的延迟，确保时钟使能生效。 */
#define __HAL_RCC_AFIO_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOA时钟。
   操作步骤：设置APB2ENR寄存器的IOPAEN位，并读取延迟。 */
#define __HAL_RCC_GPIOA_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPAEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOB时钟 */
#define __HAL_RCC_GPIOB_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOC时钟 */
#define __HAL_RCC_GPIOC_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能GPIOD时钟 */
#define __HAL_RCC_GPIOD_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPDEN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能ADC1时钟 */
#define __HAL_RCC_ADC1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能TIM1时钟 */
#define __HAL_RCC_TIM1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能SPI1时钟 */
#define __HAL_RCC_SPI1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 使能USART1时钟 */
#define __HAL_RCC_USART1_CLK_ENABLE()   do { \
                                        __IO uint32_t tmpreg; \
                                        SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        /* RCC外设时钟使能后的延迟 */\
                                        tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN);\
                                        UNUSED(tmpreg); \
                                      } while(0U)

/* 禁用AFIO时钟 */
#define __HAL_RCC_AFIO_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_AFIOEN))
/* 禁用GPIOA时钟 */
#define __HAL_RCC_GPIOA_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPAEN))
/* 禁用GPIOB时钟 */
#define __HAL_RCC_GPIOB_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPBEN))
/* 禁用GPIOC时钟 */
#define __HAL_RCC_GPIOC_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPCEN))
/* 禁用GPIOD时钟 */
#define __HAL_RCC_GPIOD_CLK_DISABLE()     (RCC->APB2ENR &= ~(RCC_APB2ENR_IOPDEN))
/* 禁用ADC1时钟 */
#define __HAL_RCC_ADC1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_ADC1EN))

/* 禁用TIM1时钟 */
#define __HAL_RCC_TIM1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_TIM1EN))
/* 禁用SPI1时钟 */
#define __HAL_RCC_SPI1_CLK_DISABLE()      (RCC->APB2ENR &= ~(RCC_APB2ENR_SPI1EN))
/* 禁用USART1时钟 */
#define __HAL_RCC_USART1_CLK_DISABLE()    (RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN))

/**
  * @}
  */

/** @defgroup RCC_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enable Disable Status
  * @brief  获取APB2外设时钟的使能或禁用状态。
  * @note   复位后，外设时钟（用于寄存器读/写访问）是禁用的，
  *         应用程序在使用之前必须使能该时钟。
  * @{
  */

/* 检查AFIO时钟是否已使能 */
#define __HAL_RCC_AFIO_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_AFIOEN)) != RESET)
/* 检查AFIO时钟是否已禁用 */
#define __HAL_RCC_AFIO_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_AFIOEN)) == RESET)
/* 检查GPIOA时钟是否已使能 */
#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPAEN)) != RESET)
/* 检查GPIOA时钟是否已禁用 */
#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPAEN)) == RESET)
/* 检查GPIOB时钟是否已使能 */
#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPBEN)) != RESET)
/* 检查GPIOB时钟是否已禁用 */
#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPBEN)) == RESET)
/* 检查GPIOC时钟是否已使能 */
#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPCEN)) != RESET)
/* 检查GPIOC时钟是否已禁用 */
#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPCEN)) == RESET)
/* 检查GPIOD时钟是否已使能 */
#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_IOPDEN)) != RESET)
/* 检查GPIOD时钟是否已禁用 */
#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_IOPDEN)) == RESET)
/* 检查ADC1时钟是否已使能 */
#define __HAL_RCC_ADC1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) != RESET)
/* 检查ADC1时钟是否已禁用 */
#define __HAL_RCC_ADC1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_ADC1EN)) == RESET)
/* 检查TIM1时钟是否已使能 */
#define __HAL_RCC_TIM1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) != RESET)
/* 检查TIM1时钟是否已禁用 */
#define __HAL_RCC_TIM1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_TIM1EN)) == RESET)
/* 检查SPI1时钟是否已使能 */
#define __HAL_RCC_SPI1_IS_CLK_ENABLED()       ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) != RESET)
/* 检查SPI1时钟是否已禁用 */
#define __HAL_RCC_SPI1_IS_CLK_DISABLED()      ((RCC->APB2ENR & (RCC_APB2ENR_SPI1EN)) == RESET)
/* 检查USART1时钟是否已使能 */
#define __HAL_RCC_USART1_IS_CLK_ENABLED()     ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) != RESET)
/* 检查USART1时钟是否已禁用 */
#define __HAL_RCC_USART1_IS_CLK_DISABLED()    ((RCC->APB2ENR & (RCC_APB2ENR_USART1EN)) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB1_Force_Release_Reset APB1 Force Release Reset
  * @brief  强制或释放APB1外设复位。
  * @{
  */
/* 强制复位APB1总线上的所有外设 */
#define __HAL_RCC_APB1_FORCE_RESET()       (RCC->APB1RSTR = 0xFFFFFFFFU)
/* 强制复位TIM2 */
#define __HAL_RCC_TIM2_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM2RST))
/* 强制复位TIM3 */
#define __HAL_RCC_TIM3_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_TIM3RST))
/* 强制复位WWDG(窗口看门狗) */
#define __HAL_RCC_WWDG_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_WWDGRST))
/* 强制复位USART2 */
#define __HAL_RCC_USART2_FORCE_RESET()     (RCC->APB1RSTR |= (RCC_APB1RSTR_USART2RST))
/* 强制复位I2C1 */
#define __HAL_RCC_I2C1_FORCE_RESET()       (RCC->APB1RSTR |= (RCC_APB1RSTR_I2C1RST))

/* 强制复位BKP(备份寄存器) */
#define __HAL_RCC_BKP_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_BKPRST))
/* 强制复位PWR(电源接口) */
#define __HAL_RCC_PWR_FORCE_RESET()        (RCC->APB1RSTR |= (RCC_APB1RSTR_PWRRST))

/* 释放APB1总线上所有外设的复位状态 */
#define __HAL_RCC_APB1_RELEASE_RESET()      (RCC->APB1RSTR = 0x00)
/* 释放TIM2的复位状态 */
#define __HAL_RCC_TIM2_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM2RST))
/* 释放TIM3的复位状态 */
#define __HAL_RCC_TIM3_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_TIM3RST))
/* 释放WWDG的复位状态 */
#define __HAL_RCC_WWDG_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_WWDGRST))
/* 释放USART2的复位状态 */
#define __HAL_RCC_USART2_RELEASE_RESET()     (RCC->APB1RSTR &= ~(RCC_APB1RSTR_USART2RST))
/* 释放I2C1的复位状态 */
#define __HAL_RCC_I2C1_RELEASE_RESET()       (RCC->APB1RSTR &= ~(RCC_APB1RSTR_I2C1RST))

/* 释放BKP的复位状态 */
#define __HAL_RCC_BKP_RELEASE_RESET()        (RCC->APB1RSTR &= ~(RCC_APB1RSTR_BKPRST))
/* 释放PWR的复位状态 */
#define __HAL_RCC_PWR_RELEASE_RESET()        (RCC->APB1RSTR &= ~(RCC_APB1RSTR_PWRRST))

/**
  * @}
  */

/** @defgroup RCC_APB2_Force_Release_Reset APB2 Force Release Reset
  * @brief  强制或释放APB2外设复位。
  * @{
  */
/* 强制复位APB2总线上的所有外设 */
#define __HAL_RCC_APB2_FORCE_RESET()       (RCC->APB2RSTR = 0xFFFFFFFFU)
/* 强制复位AFIO */
#define __HAL_RCC_AFIO_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_AFIORST))
/* 强制复位GPIOA */
#define __HAL_RCC_GPIOA_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPARST))
/* 强制复位GPIOB */
#define __HAL_RCC_GPIOB_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPBRST))
/* 强制复位GPIOC */
#define __HAL_RCC_GPIOC_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPCRST))
/* 强制复位GPIOD */
#define __HAL_RCC_GPIOD_FORCE_RESET()      (RCC->APB2RSTR |= (RCC_APB2RSTR_IOPDRST))
/* 强制复位ADC1 */
#define __HAL_RCC_ADC1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_ADC1RST))

/* 强制复位TIM1 */
#define __HAL_RCC_TIM1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_TIM1RST))
/* 强制复位SPI1 */
#define __HAL_RCC_SPI1_FORCE_RESET()       (RCC->APB2RSTR |= (RCC_APB2RSTR_SPI1RST))
/* 强制复位USART1 */
#define __HAL_RCC_USART1_FORCE_RESET()     (RCC->APB2RSTR |= (RCC_APB2RSTR_USART1RST))

/* 释放APB2总线上所有外设的复位状态 */
#define __HAL_RCC_APB2_RELEASE_RESET()      (RCC->APB2RSTR = 0x00)
/* 释放AFIO的复位状态 */
#define __HAL_RCC_AFIO_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_AFIORST))
/* 释放GPIOA的复位状态 */
#define __HAL_RCC_GPIOA_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPARST))
/* 释放GPIOB的复位状态 */
#define __HAL_RCC_GPIOB_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPBRST))
/* 释放GPIOC的复位状态 */
#define __HAL_RCC_GPIOC_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPCRST))
/* 释放GPIOD的复位状态 */
#define __HAL_RCC_GPIOD_RELEASE_RESET()      (RCC->APB2RSTR &= ~(RCC_APB2RSTR_IOPDRST))
/* 释放ADC1的复位状态 */
#define __HAL_RCC_ADC1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_ADC1RST))

/* 释放TIM1的复位状态 */
#define __HAL_RCC_TIM1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_TIM1RST))
/* 释放SPI1的复位状态 */
#define __HAL_RCC_SPI1_RELEASE_RESET()       (RCC->APB2RSTR &= ~(RCC_APB2RSTR_SPI1RST))
/* 释放USART1的复位状态 */
#define __HAL_RCC_USART1_RELEASE_RESET()     (RCC->APB2RSTR &= ~(RCC_APB2RSTR_USART1RST))

/**
  * @}
  */

/** @defgroup RCC_HSI_Configuration HSI Configuration
  * @{
  */

/** @brief  使能或禁用内部高速振荡器 (HSI) 的宏。
  * @note   进入停止和待机模式时，硬件会停止HSI。
  * @note   如果HSI被用作系统时钟源，则不能停止HSI。在这种情况下，
  *         必须选择另一个系统时钟源，然后才能停止HSI。
  * @note   使能HSI后，应用程序软件应等待HSIRDY标志置位，
  *         这表明HSI时钟已稳定，可以用作系统时钟源。
  * @note   当HSI停止时，HSIRDY标志在6个HSI振荡器时钟周期后变低。
  */
/* 使能HSI (内部高速时钟)，使用位带操作实现原子操作 */
#define __HAL_RCC_HSI_ENABLE()  (*(__IO uint32_t *) RCC_CR_HSION_BB = ENABLE)
/* 禁用HSI */
#define __HAL_RCC_HSI_DISABLE() (*(__IO uint32_t *) RCC_CR_HSION_BB = DISABLE)

/** @brief  调整内部高速振荡器 (HSI) 校准值的宏。
  * @note   校准用于补偿电压和温度变化对内部HSI RC频率的影响。
  * @param  _HSICALIBRATIONVALUE_ 指定校准修剪值。
  *         (默认值为 RCC_HSICALIBRATION_DEFAULT)。
  *         该参数必须是0到0x1F之间的数字。
  */
/* 调整HSI校准值，修改CR寄存器的HSITRIM位 */
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(_HSICALIBRATIONVALUE_) \
          (MODIFY_REG(RCC->CR, RCC_CR_HSITRIM, (uint32_t)(_HSICALIBRATIONVALUE_) << RCC_CR_HSITRIM_Pos))

/**
  * @}
  */

/** @defgroup RCC_LSI_Configuration  LSI Configuration
  * @{
  */

/** @brief 使能内部低速振荡器 (LSI) 的宏。
  * @note   使能LSI后，应用程序软件应等待LSIRDY标志置位，
  *         这表明LSI时钟已稳定，可用于为IWDG和/或RTC提供时钟。
  */
/* 使能LSI (内部低速时钟)，通常用于看门狗或RTC */
#define __HAL_RCC_LSI_ENABLE()  (*(__IO uint32_t *) RCC_CSR_LSION_BB = ENABLE)

/** @brief 禁用内部低速振荡器 (LSI) 的宏。
  * @note   如果IWDG正在运行，则不能禁用LSI。
  * @note   当LSI停止时，LSIRDY标志在6个LSI振荡器时钟周期后变低。
  */
/* 禁用LSI */
#define __HAL_RCC_LSI_DISABLE() (*(__IO uint32_t *) RCC_CSR_LSION_BB = DISABLE)

/**
  * @}
  */

/** @defgroup RCC_HSE_Configuration HSE Configuration
  * @{
  */

/**
  * @brief  配置外部高速振荡器 (HSE) 的宏。
  * @note   此宏不支持从HSE旁路到HSE开启，或从HSE开启到HSE旁路的直接转换。
  *         用户应先请求转换到HSE关闭状态，然后再转换到HSE开启或HSE旁路。
  * @note   使能HSE (RCC_HSE_ON 或 RCC_HSE_Bypass) 后，应用程序软件应等待
  *         HSERDY标志置位，这表明HSE时钟已稳定，可用于为PLL和/或系统时钟提供时钟。
  * @note   如果HSE直接或通过PLL用作系统时钟，则不能更改HSE状态。
  *         在这种情况下，必须选择另一个系统时钟源，然后更改HSE状态（例如禁用它）。
  * @note   进入停止和待机模式时，硬件会停止HSE。
  * @note   此函数会复位CSSON位，因此如果之前启用了时钟安全系统(CSS)，
  *         则在调用此函数后必须再次启用它。
  * @param  __STATE__ 指定HSE的新状态。
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_HSE_OFF 关闭HSE振荡器，HSERDY标志在6个HSE振荡器时钟周期后变低。
  *            @arg @ref RCC_HSE_ON 开启HSE振荡器
  *            @arg @ref RCC_HSE_BYPASS HSE振荡器旁路，使用外部时钟源
  */
/* 配置HSE (外部高速时钟)。
   根据传入的参数状态，设置CR寄存器的HSEON和HSEBYP位。
   RCC_HSE_ON: 开启外部晶振
   RCC_HSE_OFF: 关闭外部晶振
   RCC_HSE_BYPASS: 旁路模式，直接输入外部时钟信号 */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_HSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                      else if ((__STATE__) == RCC_HSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);                    \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);                     \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);                   \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);                  \
                      }                                                     \
                    }while(0U)

/**
  * @}
  */

/** @defgroup RCC_LSE_Configuration LSE Configuration
  * @{
  */
