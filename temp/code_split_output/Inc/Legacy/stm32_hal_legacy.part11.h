/*
  这里定义了一系列用于检测外设时钟是否使能的宏。
  这些宏是旧版HAL库命名方式向新版HAL库命名方式的兼容性别名。
  例如：__ADC1_IS_CLK_ENABLED 直接对应 __HAL_RCC_ADC1_IS_CLK_ENABLED 函数式宏定义。
  这些宏通常用于在低功耗模式或外设操作前，检查当前外设时钟状态。
*/

#define __ADC1_IS_CLK_ENABLED       __HAL_RCC_ADC1_IS_CLK_ENABLED    // 检测 ADC1 时钟是否已使能
#define __ADC1_IS_CLK_DISABLED      __HAL_RCC_ADC1_IS_CLK_DISABLED   // 检测 ADC1 时钟是否已禁用
#define __ADC12_IS_CLK_ENABLED      __HAL_RCC_ADC12_IS_CLK_ENABLED   // 检测 ADC1/2 时钟是否已使能
#define __ADC12_IS_CLK_DISABLED     __HAL_RCC_ADC12_IS_CLK_DISABLED  // 检测 ADC1/2 时钟是否已禁用
#define __ADC34_IS_CLK_ENABLED      __HAL_RCC_ADC34_IS_CLK_ENABLED   // 检测 ADC3/4 时钟是否已使能
#define __ADC34_IS_CLK_DISABLED     __HAL_RCC_ADC34_IS_CLK_DISABLED  // 检测 ADC3/4 时钟是否已禁用
#define __CEC_IS_CLK_ENABLED        __HAL_RCC_CEC_IS_CLK_ENABLED     // 检测 CEC (HDMI-CEC) 时钟是否已使能
#define __CEC_IS_CLK_DISABLED       __HAL_RCC_CEC_IS_CLK_DISABLED    // 检测 CEC 时钟是否已禁用
#define __CRC_IS_CLK_ENABLED        __HAL_RCC_CRC_IS_CLK_ENABLED     // 检测 CRC (循环冗余校验) 时钟是否已使能
#define __CRC_IS_CLK_DISABLED       __HAL_RCC_CRC_IS_CLK_DISABLED    // 检测 CRC 时钟是否已禁用
#define __DAC1_IS_CLK_ENABLED       __HAL_RCC_DAC1_IS_CLK_ENABLED    // 检测 DAC1 (数模转换器1) 时钟是否已使能
#define __DAC1_IS_CLK_DISABLED      __HAL_RCC_DAC1_IS_CLK_DISABLED   // 检测 DAC1 时钟是否已禁用
#define __DAC2_IS_CLK_ENABLED       __HAL_RCC_DAC2_IS_CLK_ENABLED    // 检测 DAC2 时钟是否已使能
#define __DAC2_IS_CLK_DISABLED      __HAL_RCC_DAC2_IS_CLK_DISABLED   // 检测 DAC2 时钟是否已禁用
#define __DMA1_IS_CLK_ENABLED       __HAL_RCC_DMA1_IS_CLK_ENABLED    // 检测 DMA1 (直接存储器访问1) 时钟是否已使能
#define __DMA1_IS_CLK_DISABLED      __HAL_RCC_DMA1_IS_CLK_DISABLED   // 检测 DMA1 时钟是否已禁用
#define __DMA2_IS_CLK_ENABLED       __HAL_RCC_DMA2_IS_CLK_ENABLED    // 检测 DMA2 时钟是否已使能
#define __DMA2_IS_CLK_DISABLED      __HAL_RCC_DMA2_IS_CLK_DISABLED   // 检测 DMA2 时钟是否已禁用
#define __FLITF_IS_CLK_ENABLED      __HAL_RCC_FLITF_IS_CLK_ENABLED   // 检测 FLITF (Flash 接口) 时钟是否已使能
#define __FLITF_IS_CLK_DISABLED     __HAL_RCC_FLITF_IS_CLK_DISABLED  // 检测 FLITF 时钟是否已禁用
#define __FMC_IS_CLK_ENABLED        __HAL_RCC_FMC_IS_CLK_ENABLED     // 检测 FMC (灵活存储控制器) 时钟是否已使能
#define __FMC_IS_CLK_DISABLED       __HAL_RCC_FMC_IS_CLK_DISABLED    // 检测 FMC 时钟是否已禁用
#define __GPIOA_IS_CLK_ENABLED      __HAL_RCC_GPIOA_IS_CLK_ENABLED   // 检测 GPIOA 端口时钟是否已使能
#define __GPIOA_IS_CLK_DISABLED     __HAL_RCC_GPIOA_IS_CLK_DISABLED  // 检测 GPIOA 端口时钟是否已禁用
#define __GPIOB_IS_CLK_ENABLED      __HAL_RCC_GPIOB_IS_CLK_ENABLED   // 检测 GPIOB 端口时钟是否已使能
#define __GPIOB_IS_CLK_DISABLED     __HAL_RCC_GPIOB_IS_CLK_DISABLED  // 检测 GPIOB 端口时钟是否已禁用
#define __GPIOC_IS_CLK_ENABLED      __HAL_RCC_GPIOC_IS_CLK_ENABLED   // 检测 GPIOC 端口时钟是否已使能
#define __GPIOC_IS_CLK_DISABLED     __HAL_RCC_GPIOC_IS_CLK_DISABLED  // 检测 GPIOC 端口时钟是否已禁用
#define __GPIOD_IS_CLK_ENABLED      __HAL_RCC_GPIOD_IS_CLK_ENABLED   // 检测 GPIOD 端口时钟是否已使能
#define __GPIOD_IS_CLK_DISABLED     __HAL_RCC_GPIOD_IS_CLK_DISABLED  // 检测 GPIOD 端口时钟是否已禁用
#define __GPIOE_IS_CLK_ENABLED      __HAL_RCC_GPIOE_IS_CLK_ENABLED   // 检测 GPIOE 端口时钟是否已使能
#define __GPIOE_IS_CLK_DISABLED     __HAL_RCC_GPIOE_IS_CLK_DISABLED  // 检测 GPIOE 端口时钟是否已禁用
#define __GPIOF_IS_CLK_ENABLED      __HAL_RCC_GPIOF_IS_CLK_ENABLED   // 检测 GPIOF 端口时钟是否已使能
#define __GPIOF_IS_CLK_DISABLED     __HAL_RCC_GPIOF_IS_CLK_DISABLED  // 检测 GPIOF 端口时钟是否已禁用
#define __GPIOG_IS_CLK_ENABLED      __HAL_RCC_GPIOG_IS_CLK_ENABLED   // 检测 GPIOG 端口时钟是否已使能
#define __GPIOG_IS_CLK_DISABLED     __HAL_RCC_GPIOG_IS_CLK_DISABLED  // 检测 GPIOG 端口时钟是否已禁用
#define __GPIOH_IS_CLK_ENABLED      __HAL_RCC_GPIOH_IS_CLK_ENABLED   // 检测 GPIOH 端口时钟是否已使能
#define __GPIOH_IS_CLK_DISABLED     __HAL_RCC_GPIOH_IS_CLK_DISABLED  // 检测 GPIOH 端口时钟是否已禁用
#define __HRTIM1_IS_CLK_ENABLED     __HAL_RCC_HRTIM1_IS_CLK_ENABLED  // 检测 HRTIM1 (高分辨率定时器) 时钟是否已使能
#define __HRTIM1_IS_CLK_DISABLED    __HAL_RCC_HRTIM1_IS_CLK_DISABLED // 检测 HRTIM1 时钟是否已禁用
#define __I2C1_IS_CLK_ENABLED       __HAL_RCC_I2C1_IS_CLK_ENABLED    // 检测 I2C1 时钟是否已使能
#define __I2C1_IS_CLK_DISABLED      __HAL_RCC_I2C1_IS_CLK_DISABLED   // 检测 I2C1 时钟是否已禁用
#define __I2C2_IS_CLK_ENABLED       __HAL_RCC_I2C2_IS_CLK_ENABLED    // 检测 I2C2 时钟是否已使能
#define __I2C2_IS_CLK_DISABLED      __HAL_RCC_I2C2_IS_CLK_DISABLED   // 检测 I2C2 时钟是否已禁用
#define __I2C3_IS_CLK_ENABLED       __HAL_RCC_I2C3_IS_CLK_ENABLED    // 检测 I2C3 时钟是否已使能
#define __I2C3_IS_CLK_DISABLED      __HAL_RCC_I2C3_IS_CLK_DISABLED   // 检测 I2C3 时钟是否已禁用
#define __PWR_IS_CLK_ENABLED        __HAL_RCC_PWR_IS_CLK_ENABLED     // 检测 PWR (电源接口) 时钟是否已使能
#define __PWR_IS_CLK_DISABLED       __HAL_RCC_PWR_IS_CLK_DISABLED    // 检测 PWR 时钟是否已禁用
#define __SYSCFG_IS_CLK_ENABLED     __HAL_RCC_SYSCFG_IS_CLK_ENABLED  // 检测 SYSCFG (系统配置控制器) 时钟是否已使能
#define __SYSCFG_IS_CLK_DISABLED    __HAL_RCC_SYSCFG_IS_CLK_DISABLED // 检测 SYSCFG 时钟是否已禁用
#define __SPI1_IS_CLK_ENABLED       __HAL_RCC_SPI1_IS_CLK_ENABLED    // 检测 SPI1 时钟是否已使能
#define __SPI1_IS_CLK_DISABLED      __HAL_RCC_SPI1_IS_CLK_DISABLED   // 检测 SPI1 时钟是否已禁用
#define __SPI2_IS_CLK_ENABLED       __HAL_RCC_SPI2_IS_CLK_ENABLED    // 检测 SPI2 时钟是否已使能
#define __SPI2_IS_CLK_DISABLED      __HAL_RCC_SPI2_IS_CLK_DISABLED   // 检测 SPI2 时钟是否已禁用
#define __SPI3_IS_CLK_ENABLED       __HAL_RCC_SPI3_IS_CLK_ENABLED    // 检测 SPI3 时钟是否已使能
#define __SPI3_IS_CLK_DISABLED      __HAL_RCC_SPI3_IS_CLK_DISABLED   // 检测 SPI3 时钟是否已禁用
#define __SPI4_IS_CLK_ENABLED       __HAL_RCC_SPI4_IS_CLK_ENABLED    // 检测 SPI4 时钟是否已使能
#define __SPI4_IS_CLK_DISABLED      __HAL_RCC_SPI4_IS_CLK_DISABLED   // 检测 SPI4 时钟是否已禁用
#define __SDADC1_IS_CLK_ENABLED     __HAL_RCC_SDADC1_IS_CLK_ENABLED  // 检测 SDADC1 (Sigma-Delta ADC) 时钟是否已使能
#define __SDADC1_IS_CLK_DISABLED    __HAL_RCC_SDADC1_IS_CLK_DISABLED // 检测 SDADC1 时钟是否已禁用
#define __SDADC2_IS_CLK_ENABLED     __HAL_RCC_SDADC2_IS_CLK_ENABLED  // 检测 SDADC2 时钟是否已使能
#define __SDADC2_IS_CLK_DISABLED    __HAL_RCC_SDADC2_IS_CLK_DISABLED // 检测 SDADC2 时钟是否已禁用
#define __SDADC3_IS_CLK_ENABLED     __HAL_RCC_SDADC3_IS_CLK_ENABLED  // 检测 SDADC3 时钟是否已使能
#define __SDADC3_IS_CLK_DISABLED    __HAL_RCC_SDADC3_IS_CLK_DISABLED // 检测 SDADC3 时钟是否已禁用
#define __SRAM_IS_CLK_ENABLED       __HAL_RCC_SRAM_IS_CLK_ENABLED    // 检测 SRAM 时钟是否已使能
#define __SRAM_IS_CLK_DISABLED      __HAL_RCC_SRAM_IS_CLK_DISABLED   // 检测 SRAM 时钟是否已禁用
#define __TIM1_IS_CLK_ENABLED       __HAL_RCC_TIM1_IS_CLK_ENABLED    // 检测 TIM1 时钟是否已使能
#define __TIM1_IS_CLK_DISABLED      __HAL_RCC_TIM1_IS_CLK_DISABLED   // 检测 TIM1 时钟是否已禁用
#define __TIM2_IS_CLK_ENABLED       __HAL_RCC_TIM2_IS_CLK_ENABLED    // 检测 TIM2 时钟是否已使能
#define __TIM2_IS_CLK_DISABLED      __HAL_RCC_TIM2_IS_CLK_DISABLED   // 检测 TIM2 时钟是否已禁用
#define __TIM3_IS_CLK_ENABLED       __HAL_RCC_TIM3_IS_CLK_ENABLED    // 检测 TIM3 时钟是否已使能
#define __TIM3_IS_CLK_DISABLED      __HAL_RCC_TIM3_IS_CLK_DISABLED   // 检测 TIM3 时钟是否已禁用
#define __TIM4_IS_CLK_ENABLED       __HAL_RCC_TIM4_IS_CLK_ENABLED    // 检测 TIM4 时钟是否已使能
#define __TIM4_IS_CLK_DISABLED      __HAL_RCC_TIM4_IS_CLK_DISABLED   // 检测 TIM4 时钟是否已禁用
#define __TIM5_IS_CLK_ENABLED       __HAL_RCC_TIM5_IS_CLK_ENABLED    // 检测 TIM5 时钟是否已使能
#define __TIM5_IS_CLK_DISABLED      __HAL_RCC_TIM5_IS_CLK_DISABLED   // 检测 TIM5 时钟是否已禁用
#define __TIM6_IS_CLK_ENABLED       __HAL_RCC_TIM6_IS_CLK_ENABLED    // 检测 TIM6 时钟是否已使能
#define __TIM6_IS_CLK_DISABLED      __HAL_RCC_TIM6_IS_CLK_DISABLED   // 检测 TIM6 时钟是否已禁用
#define __TIM7_IS_CLK_ENABLED       __HAL_RCC_TIM7_IS_CLK_ENABLED    // 检测 TIM7 时钟是否已使能
#define __TIM7_IS_CLK_DISABLED      __HAL_RCC_TIM7_IS_CLK_DISABLED   // 检测 TIM7 时钟是否已禁用
#define __TIM8_IS_CLK_ENABLED       __HAL_RCC_TIM8_IS_CLK_ENABLED    // 检测 TIM8 时钟是否已使能
#define __TIM8_IS_CLK_DISABLED      __HAL_RCC_TIM8_IS_CLK_DISABLED   // 检测 TIM8 时钟是否已禁用
#define __TIM12_IS_CLK_ENABLED      __HAL_RCC_TIM12_IS_CLK_ENABLED   // 检测 TIM12 时钟是否已使能
#define __TIM12_IS_CLK_DISABLED     __HAL_RCC_TIM12_IS_CLK_DISABLED  // 检测 TIM12 时钟是否已禁用
#define __TIM13_IS_CLK_ENABLED      __HAL_RCC_TIM13_IS_CLK_ENABLED   // 检测 TIM13 时钟是否已使能
#define __TIM13_IS_CLK_DISABLED     __HAL_RCC_TIM13_IS_CLK_DISABLED  // 检测 TIM13 时钟是否已禁用
#define __TIM14_IS_CLK_ENABLED      __HAL_RCC_TIM14_IS_CLK_ENABLED   // 检测 TIM14 时钟是否已使能
#define __TIM14_IS_CLK_DISABLED     __HAL_RCC_TIM14_IS_CLK_DISABLED  // 检测 TIM14 时钟是否已禁用
#define __TIM15_IS_CLK_ENABLED      __HAL_RCC_TIM15_IS_CLK_ENABLED   // 检测 TIM15 时钟是否已使能
#define __TIM15_IS_CLK_DISABLED     __HAL_RCC_TIM15_IS_CLK_DISABLED  // 检测 TIM15 时钟是否已禁用
#define __TIM16_IS_CLK_ENABLED      __HAL_RCC_TIM16_IS_CLK_ENABLED   // 检测 TIM16 时钟是否已使能
#define __TIM16_IS_CLK_DISABLED     __HAL_RCC_TIM16_IS_CLK_DISABLED  // 检测 TIM16 时钟是否已禁用
#define __TIM17_IS_CLK_ENABLED      __HAL_RCC_TIM17_IS_CLK_ENABLED   // 检测 TIM17 时钟是否已使能
#define __TIM17_IS_CLK_DISABLED     __HAL_RCC_TIM17_IS_CLK_DISABLED  // 检测 TIM17 时钟是否已禁用
#define __TIM18_IS_CLK_ENABLED      __HAL_RCC_TIM18_IS_CLK_ENABLED   // 检测 TIM18 时钟是否已使能
#define __TIM18_IS_CLK_DISABLED     __HAL_RCC_TIM18_IS_CLK_DISABLED  // 检测 TIM18 时钟是否已禁用
#define __TIM19_IS_CLK_ENABLED      __HAL_RCC_TIM19_IS_CLK_ENABLED   // 检测 TIM19 时钟是否已使能
#define __TIM19_IS_CLK_DISABLED     __HAL_RCC_TIM19_IS_CLK_DISABLED  // 检测 TIM19 时钟是否已禁用
#define __TIM20_IS_CLK_ENABLED      __HAL_RCC_TIM20_IS_CLK_ENABLED   // 检测 TIM20 时钟是否已使能
#define __TIM20_IS_CLK_DISABLED     __HAL_RCC_TIM20_IS_CLK_DISABLED  // 检测 TIM20 时钟是否已禁用
#define __TSC_IS_CLK_ENABLED        __HAL_RCC_TSC_IS_CLK_ENABLED     // 检测 TSC (触摸感应控制器) 时钟是否已使能
#define __TSC_IS_CLK_DISABLED       __HAL_RCC_TSC_IS_CLK_DISABLED    // 检测 TSC 时钟是否已禁用
#define __UART4_IS_CLK_ENABLED      __HAL_RCC_UART4_IS_CLK_ENABLED   // 检测 UART4 时钟是否已使能
#define __UART4_IS_CLK_DISABLED     __HAL_RCC_UART4_IS_CLK_DISABLED  // 检测 UART4 时钟是否已禁用
#define __UART5_IS_CLK_ENABLED      __HAL_RCC_UART5_IS_CLK_ENABLED   // 检测 UART5 时钟是否已使能
#define __UART5_IS_CLK_DISABLED     __HAL_RCC_UART5_IS_CLK_DISABLED  // 检测 UART5 时钟是否已禁用
#define __USART1_IS_CLK_ENABLED     __HAL_RCC_USART1_IS_CLK_ENABLED  // 检测 USART1 时钟是否已使能
#define __USART1_IS_CLK_DISABLED    __HAL_RCC_USART1_IS_CLK_DISABLED // 检测 USART1 时钟是否已禁用
#define __USART2_IS_CLK_ENABLED     __HAL_RCC_USART2_IS_CLK_ENABLED  // 检测 USART2 时钟是否已使能
#define __USART2_IS_CLK_DISABLED    __HAL_RCC_USART2_IS_CLK_DISABLED // 检测 USART2 时钟是否已禁用
#define __USART3_IS_CLK_ENABLED     __HAL_RCC_USART3_IS_CLK_ENABLED  // 检测 USART3 时钟是否已使能
#define __USART3_IS_CLK_DISABLED    __HAL_RCC_USART3_IS_CLK_DISABLED // 检测 USART3 时钟是否已禁用
#define __USB_IS_CLK_ENABLED        __HAL_RCC_USB_IS_CLK_ENABLED     // 检测 USB 时钟是否已使能
#define __USB_IS_CLK_DISABLED       __HAL_RCC_USB_IS_CLK_DISABLED    // 检测 USB 时钟是否已禁用
#define __WWDG_IS_CLK_ENABLED       __HAL_RCC_WWDG_IS_CLK_ENABLED    // 检测 WWDG (窗口看门狗) 时钟是否已使能
#define __WWDG_IS_CLK_DISABLED      __HAL_RCC_WWDG_IS_CLK_DISABLED   // 检测 WWDG 时钟是否已禁用

/* 针对STM32L1系列设备的兼容性定义 */
#if defined(STM32L1)
/* 将 CRYP (加密处理器) 的宏映射到 AES (高级加密标准) 的宏，
   因为STM32L1系列中加密模块称为AES */
#define __HAL_RCC_CRYP_CLK_DISABLE         __HAL_RCC_AES_CLK_DISABLE        // 禁用 AES 时钟
#define __HAL_RCC_CRYP_CLK_ENABLE          __HAL_RCC_AES_CLK_ENABLE         // 使能 AES 时钟
#define __HAL_RCC_CRYP_CLK_SLEEP_DISABLE   __HAL_RCC_AES_CLK_SLEEP_DISABLE  // 睡眠模式下禁用 AES 时钟
#define __HAL_RCC_CRYP_CLK_SLEEP_ENABLE    __HAL_RCC_AES_CLK_SLEEP_ENABLE   // 睡眠模式下使能 AES 时钟
#define __HAL_RCC_CRYP_FORCE_RESET         __HAL_RCC_AES_FORCE_RESET        // 强制复位 AES 模块
#define __HAL_RCC_CRYP_RELEASE_RESET       __HAL_RCC_AES_RELEASE_RESET      // 释放复位 AES 模块
#endif /* STM32L1 */

/* 针对STM32F4系列设备的兼容性定义 */
#if defined(STM32F4)
/* 将 SDMMC1 (SD卡接口1) 的宏映射到 SDIO (安全数字输入输出) 的宏，
   STM32F4系列通常使用SDIO外设名称 */
#define __HAL_RCC_SDMMC1_FORCE_RESET       __HAL_RCC_SDIO_FORCE_RESET       // 强制复位 SDIO
#define __HAL_RCC_SDMMC1_RELEASE_RESET     __HAL_RCC_SDIO_RELEASE_RESET     // 释放复位 SDIO
#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE  __HAL_RCC_SDIO_CLK_SLEEP_ENABLE  // 睡眠模式下使能 SDIO 时钟
#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE __HAL_RCC_SDIO_CLK_SLEEP_DISABLE // 睡眠模式下禁用 SDIO 时钟
#define __HAL_RCC_SDMMC1_CLK_ENABLE        __HAL_RCC_SDIO_CLK_ENABLE        // 使能 SDIO 时钟
#define __HAL_RCC_SDMMC1_CLK_DISABLE       __HAL_RCC_SDIO_CLK_DISABLE       // 禁用 SDIO 时钟
#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED    __HAL_RCC_SDIO_IS_CLK_ENABLED    // 检测 SDIO 时钟是否已使能
#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED   __HAL_RCC_SDIO_IS_CLK_DISABLED   // 检测 SDIO 时钟是否已禁用
#define Sdmmc1ClockSelection               SdioClockSelection               // 时钟源选择类型别名
#define RCC_PERIPHCLK_SDMMC1               RCC_PERIPHCLK_SDIO               // 外设时钟类型定义
#define RCC_SDMMC1CLKSOURCE_CLK48          RCC_SDIOCLKSOURCE_CK48           // 时钟源：48MHz
#define RCC_SDMMC1CLKSOURCE_SYSCLK         RCC_SDIOCLKSOURCE_SYSCLK         // 时钟源：系统时钟
#define __HAL_RCC_SDMMC1_CONFIG            __HAL_RCC_SDIO_CONFIG            // 配置 SDIO 时钟源
#define __HAL_RCC_GET_SDMMC1_SOURCE        __HAL_RCC_GET_SDIO_SOURCE        // 获取 SDIO 时钟源
#endif

/* 针对STM32F7或STM32L4系列设备的兼容性定义 */
#if defined(STM32F7) || defined(STM32L4)
/* 将 SDIO 的旧名称映射到 SDMMC1 的新名称，
   STM32F7/L4系列通常使用SDMMC外设名称 */
#define __HAL_RCC_SDIO_FORCE_RESET         __HAL_RCC_SDMMC1_FORCE_RESET     // 强制复位 SDMMC1
#define __HAL_RCC_SDIO_RELEASE_RESET       __HAL_RCC_SDMMC1_RELEASE_RESET   // 释放复位 SDMMC1
#define __HAL_RCC_SDIO_CLK_SLEEP_ENABLE    __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE // 睡眠模式下使能 SDMMC1 时钟
#define __HAL_RCC_SDIO_CLK_SLEEP_DISABLE   __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE // 睡眠模式下禁用 SDMMC1 时钟
#define __HAL_RCC_SDIO_CLK_ENABLE          __HAL_RCC_SDMMC1_CLK_ENABLE      // 使能 SDMMC1 时钟
#define __HAL_RCC_SDIO_CLK_DISABLE         __HAL_RCC_SDMMC1_CLK_DISABLE     // 禁用 SDMMC1 时钟
#define __HAL_RCC_SDIO_IS_CLK_ENABLED      __HAL_RCC_SDMMC1_IS_CLK_ENABLED  // 检测 SDMMC1 时钟是否已使能
#define __HAL_RCC_SDIO_IS_CLK_DISABLED     __HAL_RCC_SDMMC1_IS_CLK_DISABLED // 检测 SDMMC1 时钟是否已禁用
#define SdioClockSelection                 Sdmmc1ClockSelection             // 时钟源选择类型别名
#define RCC_PERIPHCLK_SDIO                 RCC_PERIPHCLK_SDMMC1             // 外设时钟类型定义
#define __HAL_RCC_SDIO_CONFIG              __HAL_RCC_SDMMC1_CONFIG          // 配置 SDMMC1 时钟源
#define __HAL_RCC_GET_SDIO_SOURCE          __HAL_RCC_GET_SDMMC1_SOURCE      // 获取 SDMMC1 时钟源
#endif

/* 针对STM32F7系列设备的特定时钟源定义 */
#if defined(STM32F7)
#define RCC_SDIOCLKSOURCE_CLK48             RCC_SDMMC1CLKSOURCE_CLK48       // SDIO时钟源选择 48MHz
#define RCC_SDIOCLKSOURCE_SYSCLK           RCC_SDMMC1CLKSOURCE_SYSCLK       // SDIO时钟源选择系统时钟
#endif

/* 针对STM32H7系列设备的USB OTG兼容性定义 */
#if defined(STM32H7)
/* USB OTG HS (High Speed) 映射到 USB1 OTG HS */
#define __HAL_RCC_USB_OTG_HS_CLK_ENABLE()              __HAL_RCC_USB1_OTG_HS_CLK_ENABLE()            // 使能 USB1 OTG HS 时钟
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE()         __HAL_RCC_USB1_OTG_HS_ULPI_CLK_ENABLE()       // 使能 USB1 OTG HS ULPI 时钟
#define __HAL_RCC_USB_OTG_HS_CLK_DISABLE()             __HAL_RCC_USB1_OTG_HS_CLK_DISABLE()           // 禁用 USB1 OTG HS 时钟
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE()        __HAL_RCC_USB1_OTG_HS_ULPI_CLK_DISABLE()      // 禁用 USB1 OTG HS ULPI 时钟
#define __HAL_RCC_USB_OTG_HS_FORCE_RESET()             __HAL_RCC_USB1_OTG_HS_FORCE_RESET()           // 强制复位 USB1 OTG HS
#define __HAL_RCC_USB_OTG_HS_RELEASE_RESET()           __HAL_RCC_USB1_OTG_HS_RELEASE_RESET()         // 释放复位 USB1 OTG HS
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE()        __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_ENABLE()      // 睡眠模式下使能 USB1 OTG HS 时钟
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE()   __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_ENABLE() // 睡眠模式下使能 USB1 OTG HS ULPI 时钟
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE()       __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_DISABLE()     // 睡眠模式下禁用 USB1 OTG HS 时钟
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE()  __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_DISABLE()// 睡眠模式下禁用 USB1 OTG HS ULPI 时钟

/* USB OTG FS (Full Speed) 映射到 USB2 OTG FS */
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()             __HAL_RCC_USB2_OTG_FS_CLK_ENABLE()             // 使能 USB2 OTG FS 时钟
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_ENABLE()        __HAL_RCC_USB2_OTG_FS_ULPI_CLK_ENABLE()        // 使能 USB2 OTG FS ULPI 时钟
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()            __HAL_RCC_USB2_OTG_FS_CLK_DISABLE()            // 禁用 USB2 OTG FS 时钟
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_DISABLE()       __HAL_RCC_USB2_OTG_FS_ULPI_CLK_DISABLE()       // 禁用 USB2 OTG FS ULPI 时钟
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()            __HAL_RCC_USB2_OTG_FS_FORCE_RESET()            // 强制复位 USB2 OTG FS
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()          __HAL_RCC_USB2_OTG_FS_RELEASE_RESET()          // 释放复位 USB2 OTG FS
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()       __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_ENABLE()       // 睡眠模式下使能 USB2 OTG FS 时钟
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  // 睡眠模式下使能 USB2 OTG FS ULPI 时钟
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE()      __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_DISABLE()      // 睡眠模式下禁用 USB2 OTG FS 时钟
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_DISABLE() __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_DISABLE() // 睡眠模式下禁用 USB2 OTG FS ULPI 时钟
#endif

/* I2S (集成电路音频接口) 时钟配置相关宏别名 */
#define __HAL_RCC_I2SCLK            __HAL_RCC_I2S_CONFIG        // 配置 I2S 时钟源
#define __HAL_RCC_I2SCLK_CONFIG     __HAL_RCC_I2S_CONFIG        // 配置 I2S 时钟源（旧版命名兼容）

/* PLL (锁相环) 时钟源相关宏别名 */
#define __RCC_PLLSRC                RCC_GET_PLL_OSCSOURCE       // 获取 PLL 振荡器时钟源

/* 参数检查宏别名，用于验证函数参数的有效性 */
#define IS_RCC_MSIRANGE             IS_RCC_MSI_CLOCK_RANGE      // 检查 MSI (多速内部振荡器) 范围
#define IS_RCC_RTCCLK_SOURCE        IS_RCC_RTCCLKSOURCE         // 检查 RTC (实时时钟) 时钟源
#define IS_RCC_SYSCLK_DIV           IS_RCC_HCLK                 // 检查系统时钟分频系数 (对应 AHB 总线)
#define IS_RCC_HCLK_DIV             IS_RCC_PCLK                 // 检查 HCLK 分频系数 (对应 APB 总线)
#define IS_RCC_PERIPHCLK            IS_RCC_PERIPHCLOCK          // 检查外设时钟配置

/* 中断标志位宏别名 */
#define RCC_IT_HSI14                RCC_IT_HSI14RDY             // HSI14 (内部高速时钟14MHz) 就绪中断标志

/* CSS (时钟安全系统) 中断标志位宏别名 */
#define RCC_IT_CSSLSE               RCC_IT_LSECSS               // LSE (外部低速时钟) 安全系统中断
#define RCC_IT_CSSHSE               RCC_IT_CSS                  // HSE (外部高速时钟) 安全系统中断

/* PLL 倍频系数 宏别名 */
#define RCC_PLLMUL_3                RCC_PLL_MUL3                // PLL 倍频系数 3
#define RCC_PLLMUL_4                RCC_PLL_MUL4                // PLL 倍频系数 4
#define RCC_PLLMUL_6                RCC_PLL_MUL6                // PLL 倍频系数 6
#define RCC_PLLMUL_8                RCC_PLL_MUL8                // PLL 倍频系数 8
#define RCC_PLLMUL_12               RCC_PLL_MUL12               // PLL 倍频系数 12
#define RCC_PLLMUL_16               RCC_PLL_MUL16               // PLL 倍频系数 16
#define RCC_PLLMUL_24               RCC_PLL_MUL24               // PLL 倍频系数 24
#define RCC_PLLMUL_32               RCC_PLL_MUL32               // PLL 倍频系数 32
#define RCC_PLLMUL_48               RCC_PLL_MUL48               // PLL 倍频系数 48

/* PLL 分频系数 宏别名 */
#define RCC_PLLDIV_2                RCC_PLL_DIV2                // PLL 分频系数 2
#define RCC_PLLDIV_3                RCC_PLL_DIV3                // PLL 分频系数 3
#define RCC_PLLDIV_4                RCC_PLL_DIV4                // PLL 分频系数 4

/* MCO (微控制器时钟输出) 相关宏别名 */
#define IS_RCC_MCOSOURCE            IS_RCC_MCO1SOURCE           // 检查 MCO 时钟源
#define __HAL_RCC_MCO_CONFIG        __HAL_RCC_MCO1_CONFIG       // 配置 MCO1 输出

/* MCO 输出分频系数定义 */
#define RCC_MCO_NODIV               RCC_MCODIV_1                // MCO 不分频
#define RCC_MCO_DIV1                RCC_MCODIV_1                // MCO 1分频
#define RCC_MCO_DIV2                RCC_MCODIV_2                // MCO 2分频
#define RCC_MCO_DIV4                RCC_MCODIV_4                // MCO 4分频
#define RCC_MCO_DIV8                RCC_MCODIV_8                // MCO 8分频
#define RCC_MCO_DIV16               RCC_MCODIV_16               // MCO 16分频
#define RCC_MCO_DIV32               RCC_MCODIV_32               // MCO 32分频
#define RCC_MCO_DIV64               RCC_MCODIV_64               // MCO 64分频
#define RCC_MCO_DIV128              RCC_MCODIV_128              // MCO 128分频

/* MCO 时钟源选择定义 */
#define RCC_MCOSOURCE_NONE          RCC_MCO1SOURCE_NOCLOCK      // 无时钟输出
#define RCC_MCOSOURCE_LSI           RCC_MCO1SOURCE_LSI          // 输出 LSI (低速内部时钟)
#define RCC_MCOSOURCE_LSE           RCC_MCO1SOURCE_LSE          // 输出 LSE (低速外部时钟)
#define RCC_MCOSOURCE_SYSCLK        RCC_MCO1SOURCE_SYSCLK       // 输出系统时钟
#define RCC_MCOSOURCE_HSI           RCC_MCO1SOURCE_HSI          // 输出 HSI (高速内部时钟)
#define RCC_MCOSOURCE_HSI14         RCC_MCO1SOURCE_HSI14        // 输出 HSI14
#define RCC_MCOSOURCE_HSI48         RCC_MCO1SOURCE_HSI48        // 输出 HSI48
#define RCC_MCOSOURCE_HSE           RCC_MCO1SOURCE_HSE          // 输出 HSE (高速外部时钟)
#define RCC_MCOSOURCE_PLLCLK_DIV1   RCC_MCO1SOURCE_PLLCLK       // 输出 PLL 时钟 (不分频)
#define RCC_MCOSOURCE_PLLCLK_NODIV  RCC_MCO1SOURCE_PLLCLK       // 输出 PLL 时钟 (不分频，同上)
#define RCC_MCOSOURCE_PLLCLK_DIV2   RCC_MCO1SOURCE_PLLCLK_DIV2  // 输出 PLL 时钟 (2分频)

/* 针对STM32U0系列设备的系统时钟状态定义 */
#if defined(STM32U0)
#define RCC_SYSCLKSOURCE_STATUS_PLLR   RCC_SYSCLKSOURCE_STATUS_PLLCLK // 系统时钟状态为 PLLR (PLL R分频输出)
#endif

/* RTC 时钟源“无时钟”的跨系列兼容性定义 */
#if defined(STM32L4) || defined(STM32WB) || defined(STM32G0) || defined(STM32G4) || defined(STM32L5) || \
    defined(STM32WL) || defined(STM32C0) || defined(STM32H7RS) || defined(STM32U0)
#define RCC_RTCCLKSOURCE_NO_CLK     RCC_RTCCLKSOURCE_NONE      // 定义为 NONE
#else
#define RCC_RTCCLKSOURCE_NONE       RCC_RTCCLKSOURCE_NO_CLK    // 定义为 NO_CLK
#endif

/* USB 时钟源配置宏别名 */
#define RCC_USBCLK_PLLSAI1          RCC_USBCLKSOURCE_PLLSAI1   // USB时钟源为 PLLSAI1
#define RCC_USBCLK_PLL              RCC_USBCLKSOURCE_PLL       // USB时钟源为 主PLL
#define RCC_USBCLK_MSI              RCC_USBCLKSOURCE_MSI       // USB时钟源为 MSI
#define RCC_USBCLKSOURCE_PLLCLK     RCC_USBCLKSOURCE_PLL       // USB时钟源为 PLL (兼容旧名称)
#define RCC_USBPLLCLK_DIV1          RCC_USBCLKSOURCE_PLL       // USB PLL分频系数 1
#define RCC_USBPLLCLK_DIV1_5        RCC_USBCLKSOURCE_PLL_DIV1_5 // USB PLL分频系数 1.5
#define RCC_USBPLLCLK_DIV2          RCC_USBCLKSOURCE_PLL_DIV2  // USB PLL分频系数 2
#define RCC_USBPLLCLK_DIV3          RCC_USBCLKSOURCE_PLL_DIV3  // USB PLL分频系数 3

/* 位编号 宏别名定义 */
/* 这些宏定义了各个控制位在寄存器中的位置编号，
   常用于位带操作或寄存器位操作函数中 */
#define HSION_BitNumber        RCC_HSION_BIT_NUMBER       // HSI使能位编号
#define HSION_BITNUMBER        RCC_HSION_BIT_NUMBER       // HSI使能位编号 (兼容旧名称)
#define HSEON_BitNumber        RCC_HSEON_BIT_NUMBER       // HSE使能位编号
#define HSEON_BITNUMBER        RCC_HSEON_BIT_NUMBER       // HSE使能位编号 (兼容旧名称)
#define MSION_BITNUMBER        RCC_MSION_BIT_NUMBER       // MSI使能位编号
#define CSSON_BitNumber        RCC_CSSON_BIT_NUMBER       // CSS (时钟安全系统) 使能位编号
#define CSSON_BITNUMBER        RCC_CSSON_BIT_NUMBER       // CSS使能位编号 (兼容旧名称)
#define PLLON_BitNumber        RCC_PLLON_BIT_NUMBER       // 主PLL使能位编号
#define PLLON_BITNUMBER        RCC_PLLON_BIT_NUMBER       // 主PLL使能位编号 (兼容旧名称)
#define PLLI2SON_BitNumber     RCC_PLLI2SON_BIT_NUMBER    // PLLI2S使能位编号
#define I2SSRC_BitNumber       RCC_I2SSRC_BIT_NUMBER      // I2S时钟源选择位编号
#define RTCEN_BitNumber        RCC_RTCEN_BIT_NUMBER       // RTC使能位编号
#define RTCEN_BITNUMBER        RCC_RTCEN_BIT_NUMBER       // RTC使能位编号 (兼容旧名称)
#define BDRST_BitNumber        RCC_BDRST_BIT_NUMBER       // 备份域复位位编号
#define BDRST_BITNUMBER        RCC_BDRST_BIT_NUMBER       // 备份域复位位编号 (兼容旧名称)
#define RTCRST_BITNUMBER       RCC_RTCRST_BIT_NUMBER      // RTC复位位编号
#define LSION_BitNumber        RCC_LSION_BIT_NUMBER       // LSI使能位编号
#define LSION_BITNUMBER        RCC_LSION_BIT_NUMBER       // LSI使能位编号 (兼容旧名称)
#define LSEON_BitNumber        RCC_LSEON_BIT_NUMBER       // LSE使能位编号
#define LSEON_BITNUMBER        RCC_LSEON_BIT_NUMBER       // LSE使能位编号 (兼容旧名称)
#define LSEBYP_BITNUMBER       RCC_LSEBYP_BIT_NUMBER      // LSE旁路模式位编号
#define PLLSAION_BitNumber     RCC_PLLSAION_BIT_NUMBER    // PLLSAI使能位编号
#define TIMPRE_BitNumber       RCC_TIMPRE_BIT_NUMBER      // 定时器预分频配置位编号
#define RMVF_BitNumber         RCC_RMVF_BIT_NUMBER        // 移除复位标志位编号
#define RMVF_BITNUMBER         RCC_RMVF_BIT_NUMBER        // 移除复位标志位编号 (兼容旧名称)
#define RCC_CR2_HSI14TRIM_BitNumber RCC_HSI14TRIM_BIT_NUMBER // HSI14修剪位编号

/* 寄存器字节地址 宏别名定义 */
/* 用于直接访问寄存器的特定字节，提高效率 */
#define CR_BYTE2_ADDRESS       RCC_CR_BYTE2_ADDRESS       // CR寄存器第2字节地址
#define CIR_BYTE1_ADDRESS      RCC_CIR_BYTE1_ADDRESS      // CIR寄存器第1字节地址
#define CIR_BYTE2_ADDRESS      RCC_CIR_BYTE2_ADDRESS      // CIR寄存器第2字节地址
#define BDCR_BYTE0_ADDRESS     RCC_BDCR_BYTE0_ADDRESS     // BDCR寄存器第0字节地址

/* 超时时间定义 */
#define DBP_TIMEOUT_VALUE      RCC_DBP_TIMEOUT_VALUE      // 解除备份域写保护超时时间
#define LSE_TIMEOUT_VALUE      RCC_LSE_TIMEOUT_VALUE      // LSE启动超时时间

/* 位带别名 宏定义 */
/* 这些宏定义了对应寄存器位在位带别名区的地址，
   通过这些地址可以直接对单个位进行原子操作，不会产生中断风险 */
#define CR_HSION_BB            RCC_CR_HSION_BB            // CR寄存器 HSI使能位的位带别名
#define CR_CSSON_BB            RCC_CR_CSSON_BB            // CR寄存器 CSS使能位的位带别名
#define CR_PLLON_BB            RCC_CR_PLLON_BB            // CR寄存器 PLL使能位的位带别名
#define CR_PLLI2SON_BB         RCC_CR_PLLI2SON_BB         // CR寄存器 PLLI2S使能位的位带别名
#define CR_MSION_BB            RCC_CR_MSION_BB            // CR寄存器 MSI使能位的位带别名
#define CSR_LSION_BB           RCC_CSR_LSION_BB           // CSR寄存器 LSI使能位的位带别名
#define CSR_LSEON_BB           RCC_CSR_LSEON_BB           // CSR寄存器 LSE使能位的位带别名
#define CSR_LSEBYP_BB          RCC_CSR_LSEBYP_BB          // CSR寄存器 LSE旁路位的位带别名
#define CSR_RTCEN_BB           RCC_CSR_RTCEN_BB           // CSR寄存器 RTC使能位的位带别名
#define CSR_RTCRST_BB          RCC_CSR_RTCRST_BB          // CSR寄存器 RTC复位位的位带别名
#define CFGR_I2SSRC_BB         RCC_CFGR_I2SSRC_BB         // CFGR寄存器 I2S时钟源位的位带别名
#define BDCR_RTCEN_BB          RCC_BDCR_RTCEN_BB          // BDCR寄存器 RTC使能位的位带别名
#define BDCR_BDRST_BB          RCC_BDCR_BDRST_BB          // BDCR寄存器 备份域复位位的位带别名
#define CR_HSEON_BB            RCC_CR_HSEON_BB            // CR寄存器 HSE使能位的位带别名
#define CSR_RMVF_BB            RCC_CSR_RMVF_BB            // CSR寄存器 移除复位标志位的位带别名
#define CR_PLLSAION_BB         RCC_CR_PLLSAION_BB         // CR寄存器 PLLSAI使能位的位带别名
#define DCKCFGR_TIMPRE_BB      RCC_DCKCFGR_TIMPRE_BB      // DCKCFGR寄存器 定时器预分频位的位带别名

/* CRS (时钟恢复系统) 功能宏别名 */
#define __HAL_RCC_CRS_ENABLE_FREQ_ERROR_COUNTER     __HAL_RCC_CRS_FREQ_ERROR_COUNTER_ENABLE    // 使能频率误差计数器
#define __HAL_RCC_CRS_DISABLE_FREQ_ERROR_COUNTER    __HAL_RCC_CRS_FREQ_ERROR_COUNTER_DISABLE   // 禁用频率误差计数器
#define __HAL_RCC_CRS_ENABLE_AUTOMATIC_CALIB        __HAL_RCC_CRS_AUTOMATIC_CALIB_ENABLE       // 使能自动校准
#define __HAL_RCC_CRS_DISABLE_AUTOMATIC_CALIB       __HAL_RCC_CRS_AUTOMATIC_CALIB_DISABLE      // 禁用自动校准
#define __HAL_RCC_CRS_CALCULATE_RELOADVALUE         __HAL_RCC_CRS_RELOADVALUE_CALCULATE        // 计算重装载值

/* 中断源获取宏别名 */
#define __HAL_RCC_GET_IT_SOURCE                     __HAL_RCC_GET_IT                          // 获取中断源状态

/* CRS 状态标志宏别名 */
#define RCC_CRS_SYNCWARM       RCC_CRS_SYNCWARN            // 同步警告标志
#define RCC_CRS_TRIMOV         RCC_CRS_TRIMOVF             // 修剪溢出标志

/* CLK48 (48MHz时钟) 相关定义别名 */
#define RCC_PERIPHCLK_CK48               RCC_PERIPHCLK_CLK48    // 外设时钟类型：CLK48
#define RCC_CK48CLKSOURCE_PLLQ           RCC_CLK48CLKSOURCE_PLLQ    // CLK48时钟源：PLL Q分频输出
#define RCC_CK48CLKSOURCE_PLLSAIP        RCC_CLK48CLKSOURCE_PLLSAIP // CLK48时钟源：PLLSAI P分频输出
#define RCC_CK48CLKSOURCE_PLLI2SQ        RCC_CLK48CLKSOURCE_PLLI2SQ // CLK48时钟源：PLLI2S Q分频输出
#define IS_RCC_CK48CLKSOURCE             IS_RCC_CLK48CLKSOURCE     // 检查 CLK48 时钟源参数有效性
#define RCC_SDIOCLKSOURCE_CK48           RCC_SDIOCLKSOURCE_CLK48   // SDIO时钟源：CLK48
