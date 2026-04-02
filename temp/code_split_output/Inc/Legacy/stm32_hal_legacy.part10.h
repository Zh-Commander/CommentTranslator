/* USB OTG FS 全速模式相关宏定义 */
#define __USB_OTG_FS_FORCE_RESET  __HAL_RCC_USB_OTG_FS_FORCE_RESET      // 强制复位 USB OTG 全速模块
#define __USB_OTG_FS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET  // 释放复位 USB OTG 全速模块
#define __USB_OTG_FS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE    // 使能 USB OTG 全速模块睡眠时钟
#define __USB_OTG_FS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE  // 禁止 USB OTG 全速模块睡眠时钟

/* USB OTG HS 高速模式相关宏定义 */
#define __USB_OTG_HS_CLK_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_DISABLE      // 禁止 USB OTG 高速模块时钟
#define __USB_OTG_HS_CLK_ENABLE          __HAL_RCC_USB_OTG_HS_CLK_ENABLE // 使能 USB OTG 高速模块时钟
#define __USB_OTG_HS_ULPI_CLK_ENABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE   // 使能 USB OTG 高速模块 ULPI 接口时钟
#define __USB_OTG_HS_ULPI_CLK_DISABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE // 禁止 USB OTG 高速模块 ULPI 接口时钟

/* TIM9 定时器相关宏定义 */
#define __TIM9_CLK_SLEEP_ENABLE          __HAL_RCC_TIM9_CLK_SLEEP_ENABLE    // 使能 TIM9 睡眠时钟
#define __TIM9_CLK_SLEEP_DISABLE  __HAL_RCC_TIM9_CLK_SLEEP_DISABLE          // 禁止 TIM9 睡眠时钟

/* TIM10 定时器相关宏定义 */
#define __TIM10_CLK_SLEEP_ENABLE  __HAL_RCC_TIM10_CLK_SLEEP_ENABLE          // 使能 TIM10 睡眠时钟
#define __TIM10_CLK_SLEEP_DISABLE  __HAL_RCC_TIM10_CLK_SLEEP_DISABLE        // 禁止 TIM10 睡眠时钟

/* TIM11 定时器相关宏定义 */
#define __TIM11_CLK_SLEEP_ENABLE  __HAL_RCC_TIM11_CLK_SLEEP_ENABLE          // 使能 TIM11 睡眠时钟
#define __TIM11_CLK_SLEEP_DISABLE  __HAL_RCC_TIM11_CLK_SLEEP_DISABLE        // 禁止 TIM11 睡眠时钟

/* 以太网 PTP 时钟相关宏定义 */
#define __ETHMACPTP_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACPTP_CLK_SLEEP_ENABLE      // 使能以太网 MAC PTP 睡眠时钟
#define __ETHMACPTP_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACPTP_CLK_SLEEP_DISABLE    // 禁止以太网 MAC PTP 睡眠时钟
#define __ETHMACPTP_CLK_ENABLE          __HAL_RCC_ETHMACPTP_CLK_ENABLE          // 使能以太网 MAC PTP 时钟
#define __ETHMACPTP_CLK_DISABLE          __HAL_RCC_ETHMACPTP_CLK_DISABLE        // 禁止以太网 MAC PTP 时钟

/* HASH 硬件哈希加速器相关宏定义 */
#define __HASH_CLK_ENABLE          __HAL_RCC_HASH_CLK_ENABLE          // 使能 HASH 模块时钟
#define __HASH_FORCE_RESET          __HAL_RCC_HASH_FORCE_RESET        // 强制复位 HASH 模块
#define __HASH_RELEASE_RESET          __HAL_RCC_HASH_RELEASE_RESET    // 释放复位 HASH 模块
#define __HASH_CLK_SLEEP_ENABLE          __HAL_RCC_HASH_CLK_SLEEP_ENABLE  // 使能 HASH 模块睡眠时钟
#define __HASH_CLK_SLEEP_DISABLE  __HAL_RCC_HASH_CLK_SLEEP_DISABLE    // 禁止 HASH 模块睡眠时钟
#define __HASH_CLK_DISABLE            __HAL_RCC_HASH_CLK_DISABLE      // 禁止 HASH 模块时钟

/* SPI5 串行外设接口相关宏定义 */
#define __SPI5_CLK_ENABLE          __HAL_RCC_SPI5_CLK_ENABLE          // 使能 SPI5 时钟
#define __SPI5_CLK_DISABLE              __HAL_RCC_SPI5_CLK_DISABLE    // 禁止 SPI5 时钟
#define __SPI5_FORCE_RESET          __HAL_RCC_SPI5_FORCE_RESET        // 强制复位 SPI5
#define __SPI5_RELEASE_RESET          __HAL_RCC_SPI5_RELEASE_RESET    // 释放复位 SPI5
#define __SPI5_CLK_SLEEP_ENABLE          __HAL_RCC_SPI5_CLK_SLEEP_ENABLE  // 使能 SPI5 睡眠时钟
#define __SPI5_CLK_SLEEP_DISABLE  __HAL_RCC_SPI5_CLK_SLEEP_DISABLE    // 禁止 SPI5 睡眠时钟

/* SPI6 串行外设接口相关宏定义 */
#define __SPI6_CLK_ENABLE          __HAL_RCC_SPI6_CLK_ENABLE          // 使能 SPI6 时钟
#define __SPI6_CLK_DISABLE          __HAL_RCC_SPI6_CLK_DISABLE        // 禁止 SPI6 时钟
#define __SPI6_FORCE_RESET          __HAL_RCC_SPI6_FORCE_RESET        // 强制复位 SPI6
#define __SPI6_RELEASE_RESET         __HAL_RCC_SPI6_RELEASE_RESET     // 释放复位 SPI6
#define __SPI6_CLK_SLEEP_ENABLE          __HAL_RCC_SPI6_CLK_SLEEP_ENABLE  // 使能 SPI6 睡眠时钟
#define __SPI6_CLK_SLEEP_DISABLE  __HAL_RCC_SPI6_CLK_SLEEP_DISABLE    // 禁止 SPI6 睡眠时钟

/* LTDC LCD-TFT 控制器相关宏定义 */
#define __LTDC_CLK_ENABLE          __HAL_RCC_LTDC_CLK_ENABLE          // 使能 LTDC 时钟
#define __LTDC_CLK_DISABLE          __HAL_RCC_LTDC_CLK_DISABLE        // 禁止 LTDC 时钟
#define __LTDC_FORCE_RESET          __HAL_RCC_LTDC_FORCE_RESET        // 强制复位 LTDC
#define __LTDC_RELEASE_RESET          __HAL_RCC_LTDC_RELEASE_RESET    // 释放复位 LTDC
#define __LTDC_CLK_SLEEP_ENABLE          __HAL_RCC_LTDC_CLK_SLEEP_ENABLE  // 使能 LTDC 睡眠时钟

/* 以太网 MAC 相关睡眠时钟宏定义 */
#define __ETHMAC_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMAC_CLK_SLEEP_ENABLE      // 使能以太网 MAC 睡眠时钟
#define __ETHMAC_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMAC_CLK_SLEEP_DISABLE    // 禁止以太网 MAC 睡眠时钟
#define __ETHMACTX_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACTX_CLK_SLEEP_ENABLE  // 使能以太网 MAC 发送端睡眠时钟
#define __ETHMACTX_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACTX_CLK_SLEEP_DISABLE // 禁止以太网 MAC 发送端睡眠时钟
#define __ETHMACRX_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACRX_CLK_SLEEP_ENABLE  // 使能以太网 MAC 接收端睡眠时钟
#define __ETHMACRX_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACRX_CLK_SLEEP_DISABLE // 禁止以太网 MAC 接收端睡眠时钟

/* TIM12/13/14 定时器睡眠时钟宏定义 */
#define __TIM12_CLK_SLEEP_ENABLE  __HAL_RCC_TIM12_CLK_SLEEP_ENABLE    // 使能 TIM12 睡眠时钟
#define __TIM12_CLK_SLEEP_DISABLE  __HAL_RCC_TIM12_CLK_SLEEP_DISABLE  // 禁止 TIM12 睡眠时钟
#define __TIM13_CLK_SLEEP_ENABLE  __HAL_RCC_TIM13_CLK_SLEEP_ENABLE    // 使能 TIM13 睡眠时钟
#define __TIM13_CLK_SLEEP_DISABLE  __HAL_RCC_TIM13_CLK_SLEEP_DISABLE  // 禁止 TIM13 睡眠时钟
#define __TIM14_CLK_SLEEP_ENABLE  __HAL_RCC_TIM14_CLK_SLEEP_ENABLE    // 使能 TIM14 睡眠时钟
#define __TIM14_CLK_SLEEP_DISABLE  __HAL_RCC_TIM14_CLK_SLEEP_DISABLE  // 禁止 TIM14 睡眠时钟

/* 备份 SRAM 相关宏定义 */
#define __BKPSRAM_CLK_ENABLE          __HAL_RCC_BKPSRAM_CLK_ENABLE      // 使能备份 SRAM 时钟
#define __BKPSRAM_CLK_DISABLE          __HAL_RCC_BKPSRAM_CLK_DISABLE    // 禁止备份 SRAM 时钟
#define __BKPSRAM_CLK_SLEEP_ENABLE  __HAL_RCC_BKPSRAM_CLK_SLEEP_ENABLE  // 使能备份 SRAM 睡眠时钟
#define __BKPSRAM_CLK_SLEEP_DISABLE  __HAL_RCC_BKPSRAM_CLK_SLEEP_DISABLE // 禁止备份 SRAM 睡眠时钟

/* CCM 数据 RAM 时钟宏定义 */
#define __CCMDATARAMEN_CLK_ENABLE  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE  // 使能 CCM 数据 RAM 时钟
#define __CCMDATARAMEN_CLK_DISABLE  __HAL_RCC_CCMDATARAMEN_CLK_DISABLE // 禁止 CCM 数据 RAM 时钟

/* USART6 通用同步/异步收发器相关宏定义 */
#define __USART6_CLK_ENABLE          __HAL_RCC_USART6_CLK_ENABLE      // 使能 USART6 时钟
#define __USART6_CLK_DISABLE          __HAL_RCC_USART6_CLK_DISABLE    // 禁止 USART6 时钟
#define __USART6_FORCE_RESET        __HAL_RCC_USART6_FORCE_RESET      // 强制复位 USART6
#define __USART6_RELEASE_RESET        __HAL_RCC_USART6_RELEASE_RESET  // 释放复位 USART6
#define __USART6_CLK_SLEEP_ENABLE  __HAL_RCC_USART6_CLK_SLEEP_ENABLE  // 使能 USART6 睡眠时钟
#define __USART6_CLK_SLEEP_DISABLE  __HAL_RCC_USART6_CLK_SLEEP_DISABLE // 禁止 USART6 睡眠时钟

/* SPI4 串行外设接口相关宏定义 */
#define __SPI4_CLK_ENABLE          __HAL_RCC_SPI4_CLK_ENABLE          // 使能 SPI4 时钟
#define __SPI4_CLK_DISABLE          __HAL_RCC_SPI4_CLK_DISABLE        // 禁止 SPI4 时钟
#define __SPI4_FORCE_RESET          __HAL_RCC_SPI4_FORCE_RESET        // 强制复位 SPI4
#define __SPI4_RELEASE_RESET        __HAL_RCC_SPI4_RELEASE_RESET      // 释放复位 SPI4
#define __SPI4_CLK_SLEEP_ENABLE   __HAL_RCC_SPI4_CLK_SLEEP_ENABLE     // 使能 SPI4 睡眠时钟
#define __SPI4_CLK_SLEEP_DISABLE  __HAL_RCC_SPI4_CLK_SLEEP_DISABLE    // 禁止 SPI4 睡眠时钟

/* GPIOI 端口 I 相关宏定义 */
#define __GPIOI_CLK_ENABLE          __HAL_RCC_GPIOI_CLK_ENABLE        // 使能 GPIOI 时钟
#define __GPIOI_CLK_DISABLE          __HAL_RCC_GPIOI_CLK_DISABLE      // 禁止 GPIOI 时钟
#define __GPIOI_FORCE_RESET          __HAL_RCC_GPIOI_FORCE_RESET      // 强制复位 GPIOI
#define __GPIOI_RELEASE_RESET          __HAL_RCC_GPIOI_RELEASE_RESET  // 释放复位 GPIOI
#define __GPIOI_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOI_CLK_SLEEP_ENABLE    // 使能 GPIOI 睡眠时钟
#define __GPIOI_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOI_CLK_SLEEP_DISABLE  // 禁止 GPIOI 睡眠时钟

/* GPIOJ 端口 J 相关宏定义 */
#define __GPIOJ_CLK_ENABLE          __HAL_RCC_GPIOJ_CLK_ENABLE        // 使能 GPIOJ 时钟
#define __GPIOJ_CLK_DISABLE          __HAL_RCC_GPIOJ_CLK_DISABLE      // 禁止 GPIOJ 时钟
#define __GPIOJ_FORCE_RESET         __HAL_RCC_GPIOJ_FORCE_RESET       // 强制复位 GPIOJ
#define __GPIOJ_RELEASE_RESET          __HAL_RCC_GPIOJ_RELEASE_RESET  // 释放复位 GPIOJ
#define __GPIOJ_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOJ_CLK_SLEEP_ENABLE    // 使能 GPIOJ 睡眠时钟
#define __GPIOJ_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOJ_CLK_SLEEP_DISABLE  // 禁止 GPIOJ 睡眠时钟

/* GPIOK 端口 K 相关宏定义 */
#define __GPIOK_CLK_ENABLE          __HAL_RCC_GPIOK_CLK_ENABLE        // 使能 GPIOK 时钟
#define __GPIOK_CLK_DISABLE          __HAL_RCC_GPIOK_CLK_DISABLE      // 禁止 GPIOK 时钟
#define __GPIOK_RELEASE_RESET          __HAL_RCC_GPIOK_RELEASE_RESET  // 释放复位 GPIOK
#define __GPIOK_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOK_CLK_SLEEP_ENABLE    // 使能 GPIOK 睡眠时钟
#define __GPIOK_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOK_CLK_SLEEP_DISABLE  // 禁止 GPIOK 睡眠时钟

/* 以太网 ETH 相关宏定义 */
#define __ETH_CLK_ENABLE          __HAL_RCC_ETH_CLK_ENABLE            // 使能以太网时钟
#define __ETH_CLK_DISABLE          __HAL_RCC_ETH_CLK_DISABLE          // 禁止以太网时钟

/* DCMI 数字摄像头接口相关宏定义 */
#define __DCMI_CLK_ENABLE          __HAL_RCC_DCMI_CLK_ENABLE          // 使能 DCMI 时钟
#define __DCMI_CLK_DISABLE          __HAL_RCC_DCMI_CLK_DISABLE        // 禁止 DCMI 时钟
#define __DCMI_FORCE_RESET          __HAL_RCC_DCMI_FORCE_RESET        // 强制复位 DCMI
#define __DCMI_RELEASE_RESET          __HAL_RCC_DCMI_RELEASE_RESET    // 释放复位 DCMI
#define __DCMI_CLK_SLEEP_ENABLE   __HAL_RCC_DCMI_CLK_SLEEP_ENABLE     // 使能 DCMI 睡眠时钟
#define __DCMI_CLK_SLEEP_DISABLE  __HAL_RCC_DCMI_CLK_SLEEP_DISABLE    // 禁止 DCMI 睡眠时钟

/* UART7 通用异步收发器相关宏定义 */
#define __UART7_CLK_ENABLE          __HAL_RCC_UART7_CLK_ENABLE        // 使能 UART7 时钟
#define __UART7_CLK_DISABLE          __HAL_RCC_UART7_CLK_DISABLE      // 禁止 UART7 时钟
#define __UART7_RELEASE_RESET       __HAL_RCC_UART7_RELEASE_RESET     // 释放复位 UART7
#define __UART7_FORCE_RESET       __HAL_RCC_UART7_FORCE_RESET         // 强制复位 UART7
#define __UART7_CLK_SLEEP_ENABLE  __HAL_RCC_UART7_CLK_SLEEP_ENABLE    // 使能 UART7 睡眠时钟
#define __UART7_CLK_SLEEP_DISABLE  __HAL_RCC_UART7_CLK_SLEEP_DISABLE  // 禁止 UART7 睡眠时钟

/* UART8 通用异步收发器相关宏定义 */
#define __UART8_CLK_ENABLE          __HAL_RCC_UART8_CLK_ENABLE        // 使能 UART8 时钟
#define __UART8_CLK_DISABLE          __HAL_RCC_UART8_CLK_DISABLE      // 禁止 UART8 时钟
#define __UART8_FORCE_RESET          __HAL_RCC_UART8_FORCE_RESET      // 强制复位 UART8
#define __UART8_RELEASE_RESET          __HAL_RCC_UART8_RELEASE_RESET  // 释放复位 UART8
#define __UART8_CLK_SLEEP_ENABLE  __HAL_RCC_UART8_CLK_SLEEP_ENABLE    // 使能 UART8 睡眠时钟
#define __UART8_CLK_SLEEP_DISABLE  __HAL_RCC_UART8_CLK_SLEEP_DISABLE  // 禁止 UART8 睡眠时钟

/* USB OTG HS 高速模式睡眠及复位相关宏定义 */
#define __OTGHS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE   // 使能 USB OTG HS 睡眠时钟
#define __OTGHS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE // 禁止 USB OTG HS 睡眠时钟
#define __OTGHS_FORCE_RESET          __HAL_RCC_USB_OTG_HS_FORCE_RESET     // 强制复位 USB OTG HS
#define __OTGHS_RELEASE_RESET          __HAL_RCC_USB_OTG_HS_RELEASE_RESET // 释放复位 USB OTG HS
#define __OTGHSULPI_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE   // 使能 USB OTG HS ULPI 睡眠时钟
#define __OTGHSULPI_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE // 禁止 USB OTG HS ULPI 睡眠时钟

/* USB OTG HS 高速模式别名宏定义，用于兼容性 */
#define __HAL_RCC_OTGHS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE
#define __HAL_RCC_OTGHS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE
#define __HAL_RCC_OTGHS_IS_CLK_SLEEP_ENABLED __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_ENABLED  // 检查 USB OTG HS 睡眠时钟是否使能
#define __HAL_RCC_OTGHS_IS_CLK_SLEEP_DISABLED __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_DISABLED // 检查 USB OTG HS 睡眠时钟是否禁止
#define __HAL_RCC_OTGHS_FORCE_RESET          __HAL_RCC_USB_OTG_HS_FORCE_RESET
#define __HAL_RCC_OTGHS_RELEASE_RESET          __HAL_RCC_USB_OTG_HS_RELEASE_RESET
#define __HAL_RCC_OTGHSULPI_CLK_SLEEP_ENABLE      __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE
#define __HAL_RCC_OTGHSULPI_CLK_SLEEP_DISABLE     __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE
#define __HAL_RCC_OTGHSULPI_IS_CLK_SLEEP_ENABLED  __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_ENABLED  // 检查 ULPI 睡眠时钟是否使能
#define __HAL_RCC_OTGHSULPI_IS_CLK_SLEEP_DISABLED __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_DISABLED // 检查 ULPI 睡眠时钟是否禁止

/* 其他外设睡眠时钟宏定义 */
#define __SRAM3_CLK_SLEEP_ENABLE       __HAL_RCC_SRAM3_CLK_SLEEP_ENABLE    // 使能 SRAM3 睡眠时钟
#define __CAN2_CLK_SLEEP_ENABLE        __HAL_RCC_CAN2_CLK_SLEEP_ENABLE     // 使能 CAN2 睡眠时钟
#define __CAN2_CLK_SLEEP_DISABLE       __HAL_RCC_CAN2_CLK_SLEEP_DISABLE    // 禁止 CAN2 睡眠时钟
#define __DAC_CLK_SLEEP_ENABLE         __HAL_RCC_DAC_CLK_SLEEP_ENABLE      // 使能 DAC 睡眠时钟
#define __DAC_CLK_SLEEP_DISABLE        __HAL_RCC_DAC_CLK_SLEEP_DISABLE     // 禁止 DAC 睡眠时钟
#define __ADC2_CLK_SLEEP_ENABLE        __HAL_RCC_ADC2_CLK_SLEEP_ENABLE     // 使能 ADC2 睡眠时钟
#define __ADC2_CLK_SLEEP_DISABLE       __HAL_RCC_ADC2_CLK_SLEEP_DISABLE    // 禁止 ADC2 睡眠时钟
#define __ADC3_CLK_SLEEP_ENABLE        __HAL_RCC_ADC3_CLK_SLEEP_ENABLE     // 使能 ADC3 睡眠时钟
#define __ADC3_CLK_SLEEP_DISABLE       __HAL_RCC_ADC3_CLK_SLEEP_DISABLE    // 禁止 ADC3 睡眠时钟

/* FSMC 可变静态存储控制器相关宏定义 */
#define __FSMC_FORCE_RESET             __HAL_RCC_FSMC_FORCE_RESET          // 强制复位 FSMC
#define __FSMC_RELEASE_RESET           __HAL_RCC_FSMC_RELEASE_RESET        // 释放复位 FSMC
#define __FSMC_CLK_SLEEP_ENABLE        __HAL_RCC_FSMC_CLK_SLEEP_ENABLE     // 使能 FSMC 睡眠时钟
#define __FSMC_CLK_SLEEP_DISABLE       __HAL_RCC_FSMC_CLK_SLEEP_DISABLE    // 禁止 FSMC 睡眠时钟

/* SDIO 安全数字输入输出接口相关宏定义 */
#define __SDIO_FORCE_RESET             __HAL_RCC_SDIO_FORCE_RESET          // 强制复位 SDIO
#define __SDIO_RELEASE_RESET           __HAL_RCC_SDIO_RELEASE_RESET        // 释放复位 SDIO
#define __SDIO_CLK_SLEEP_DISABLE       __HAL_RCC_SDIO_CLK_SLEEP_DISABLE    // 禁止 SDIO 睡眠时钟
#define __SDIO_CLK_SLEEP_ENABLE        __HAL_RCC_SDIO_CLK_SLEEP_ENABLE     // 使能 SDIO 睡眠时钟

/* DMA2D 2D 直接内存访问相关宏定义 */
#define __DMA2D_CLK_ENABLE             __HAL_RCC_DMA2D_CLK_ENABLE          // 使能 DMA2D 时钟
#define __DMA2D_CLK_DISABLE            __HAL_RCC_DMA2D_CLK_DISABLE         // 禁止 DMA2D 时钟
#define __DMA2D_FORCE_RESET            __HAL_RCC_DMA2D_FORCE_RESET         // 强制复位 DMA2D
#define __DMA2D_RELEASE_RESET          __HAL_RCC_DMA2D_RELEASE_RESET       // 释放复位 DMA2D
#define __DMA2D_CLK_SLEEP_ENABLE       __HAL_RCC_DMA2D_CLK_SLEEP_ENABLE    // 使能 DMA2D 睡眠时钟
#define __DMA2D_CLK_SLEEP_DISABLE      __HAL_RCC_DMA2D_CLK_SLEEP_DISABLE   // 禁止 DMA2D 睡眠时钟

/* alias define maintained for legacy */
/* 为了兼容旧版本代码而保留的别名定义 */
#define __HAL_RCC_OTGFS_FORCE_RESET    __HAL_RCC_USB_OTG_FS_FORCE_RESET    // USB OTG FS 强制复位别名
#define __HAL_RCC_OTGFS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET  // USB OTG FS 释放复位别名

/* ADC12/ADC34 模数转换器时钟宏定义 */
#define __ADC12_CLK_ENABLE          __HAL_RCC_ADC12_CLK_ENABLE            // 使能 ADC12 时钟
#define __ADC12_CLK_DISABLE         __HAL_RCC_ADC12_CLK_DISABLE           // 禁止 ADC12 时钟
#define __ADC34_CLK_ENABLE          __HAL_RCC_ADC34_CLK_ENABLE            // 使能 ADC34 时钟
#define __ADC34_CLK_DISABLE         __HAL_RCC_ADC34_CLK_DISABLE           // 禁止 ADC34 时钟

/* DAC2 数模转换器时钟宏定义 */
#define __DAC2_CLK_ENABLE           __HAL_RCC_DAC2_CLK_ENABLE             // 使能 DAC2 时钟
#define __DAC2_CLK_DISABLE          __HAL_RCC_DAC2_CLK_DISABLE            // 禁止 DAC2 时钟

/* TIM18/TIM19/TIM20 定时器时钟宏定义 */
#define __TIM18_CLK_ENABLE          __HAL_RCC_TIM18_CLK_ENABLE            // 使能 TIM18 时钟
#define __TIM18_CLK_DISABLE         __HAL_RCC_TIM18_CLK_DISABLE           // 禁止 TIM18 时钟
#define __TIM19_CLK_ENABLE          __HAL_RCC_TIM19_CLK_ENABLE            // 使能 TIM19 时钟
#define __TIM19_CLK_DISABLE         __HAL_RCC_TIM19_CLK_DISABLE           // 禁止 TIM19 时钟
#define __TIM20_CLK_ENABLE          __HAL_RCC_TIM20_CLK_ENABLE            // 使能 TIM20 时钟
#define __TIM20_CLK_DISABLE         __HAL_RCC_TIM20_CLK_DISABLE           // 禁止 TIM20 时钟

/* HRTIM1 高分辨率定时器时钟宏定义 */
#define __HRTIM1_CLK_ENABLE         __HAL_RCC_HRTIM1_CLK_ENABLE           // 使能 HRTIM1 时钟
#define __HRTIM1_CLK_DISABLE        __HAL_RCC_HRTIM1_CLK_DISABLE          // 禁止 HRTIM1 时钟

/* SDADC Sigma-Delta 模数转换器时钟宏定义 */
#define __SDADC1_CLK_ENABLE         __HAL_RCC_SDADC1_CLK_ENABLE           // 使能 SDADC1 时钟
#define __SDADC2_CLK_ENABLE         __HAL_RCC_SDADC2_CLK_ENABLE           // 使能 SDADC2 时钟
#define __SDADC3_CLK_ENABLE         __HAL_RCC_SDADC3_CLK_ENABLE           // 使能 SDADC3 时钟
#define __SDADC1_CLK_DISABLE        __HAL_RCC_SDADC1_CLK_DISABLE          // 禁止 SDADC1 时钟
#define __SDADC2_CLK_DISABLE        __HAL_RCC_SDADC2_CLK_DISABLE          // 禁止 SDADC2 时钟
#define __SDADC3_CLK_DISABLE        __HAL_RCC_SDADC3_CLK_DISABLE          // 禁止 SDADC3 时钟

/* ADC12/ADC34 复位控制宏定义 */
#define __ADC12_FORCE_RESET         __HAL_RCC_ADC12_FORCE_RESET           // 强制复位 ADC12
#define __ADC12_RELEASE_RESET       __HAL_RCC_ADC12_RELEASE_RESET         // 释放复位 ADC12
#define __ADC34_FORCE_RESET         __HAL_RCC_ADC34_FORCE_RESET           // 强制复位 ADC34
#define __ADC34_RELEASE_RESET       __HAL_RCC_ADC34_RELEASE_RESET         // 释放复位 ADC34

/* DAC2 复位控制宏定义 */
#define __DAC2_FORCE_RESET          __HAL_RCC_DAC2_FORCE_RESET            // 强制复位 DAC2
#define __DAC2_RELEASE_RESET        __HAL_RCC_DAC2_RELEASE_RESET          // 释放复位 DAC2

/* TIM18/TIM19/TIM20 复位控制宏定义 */
#define __TIM18_FORCE_RESET         __HAL_RCC_TIM18_FORCE_RESET           // 强制复位 TIM18
#define __TIM18_RELEASE_RESET       __HAL_RCC_TIM18_RELEASE_RESET         // 释放复位 TIM18
#define __TIM19_FORCE_RESET         __HAL_RCC_TIM19_FORCE_RESET           // 强制复位 TIM19
#define __TIM19_RELEASE_RESET       __HAL_RCC_TIM19_RELEASE_RESET         // 释放复位 TIM19
#define __TIM20_FORCE_RESET         __HAL_RCC_TIM20_FORCE_RESET           // 强制复位 TIM20
#define __TIM20_RELEASE_RESET       __HAL_RCC_TIM20_RELEASE_RESET         // 释放复位 TIM20

/* HRTIM1 复位控制宏定义 */
#define __HRTIM1_FORCE_RESET        __HAL_RCC_HRTIM1_FORCE_RESET          // 强制复位 HRTIM1
#define __HRTIM1_RELEASE_RESET      __HAL_RCC_HRTIM1_RELEASE_RESET        // 释放复位 HRTIM1

/* SDADC 复位控制宏定义 */
#define __SDADC1_FORCE_RESET        __HAL_RCC_SDADC1_FORCE_RESET          // 强制复位 SDADC1
#define __SDADC2_FORCE_RESET        __HAL_RCC_SDADC2_FORCE_RESET          // 强制复位 SDADC2
#define __SDADC3_FORCE_RESET        __HAL_RCC_SDADC3_FORCE_RESET          // 强制复位 SDADC3
#define __SDADC1_RELEASE_RESET      __HAL_RCC_SDADC1_RELEASE_RESET        // 释放复位 SDADC1
#define __SDADC2_RELEASE_RESET      __HAL_RCC_SDADC2_RELEASE_RESET        // 释放复位 SDADC2
#define __SDADC3_RELEASE_RESET      __HAL_RCC_SDADC3_RELEASE_RESET        // 释放复位 SDADC3
