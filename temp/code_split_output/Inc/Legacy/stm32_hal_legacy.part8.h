/*
  本段代码主要定义了STM32系列芯片中各种外设的时钟控制宏。
  这些宏是对HAL库底层寄存器操作函数的别名封装，目的是为了保持代码的兼容性或提供更直观的命名。
  主要涉及的操作类型包括：
  1. CLK_ENABLE/DISABLE：使能或失能外设时钟（外设工作时必须开启）。
  2. CLK_SLEEP_ENABLE/DISABLE：在睡眠模式下使能或失能外设时钟（用于低功耗管理）。
  3. FORCE_RESET：强制复位外设。
  4. RELEASE_RESET：释放外设复位状态。
*/

/* ADC (模数转换器) 相关时钟控制宏定义 */
#define __ADC_CLK_DISABLE          __HAL_RCC_ADC_CLK_DISABLE              // 失能ADC时钟
#define __ADC_CLK_ENABLE           __HAL_RCC_ADC_CLK_ENABLE               // 使能ADC时钟
#define __ADC_CLK_SLEEP_DISABLE    __HAL_RCC_ADC_CLK_SLEEP_DISABLE        // 睡眠模式下失能ADC时钟
#define __ADC_CLK_SLEEP_ENABLE     __HAL_RCC_ADC_CLK_SLEEP_ENABLE         // 睡眠模式下使能ADC时钟
#define __ADC_FORCE_RESET          __HAL_RCC_ADC_FORCE_RESET              // 强制复位ADC
#define __ADC_RELEASE_RESET        __HAL_RCC_ADC_RELEASE_RESET            // 释放ADC复位

/* ADC1 专用时钟控制宏定义 */
#define __ADC1_CLK_DISABLE         __HAL_RCC_ADC1_CLK_DISABLE             // 失能ADC1时钟
#define __ADC1_CLK_ENABLE          __HAL_RCC_ADC1_CLK_ENABLE              // 使能ADC1时钟
#define __ADC1_FORCE_RESET         __HAL_RCC_ADC1_FORCE_RESET             // 强制复位ADC1
#define __ADC1_RELEASE_RESET       __HAL_RCC_ADC1_RELEASE_RESET           // 释放ADC1复位
#define __ADC1_CLK_SLEEP_ENABLE    __HAL_RCC_ADC1_CLK_SLEEP_ENABLE        // 睡眠模式下使能ADC1时钟
#define __ADC1_CLK_SLEEP_DISABLE   __HAL_RCC_ADC1_CLK_SLEEP_DISABLE       // 睡眠模式下失能ADC1时钟

/* ADC2 专用时钟控制宏定义 */
#define __ADC2_CLK_DISABLE         __HAL_RCC_ADC2_CLK_DISABLE             // 失能ADC2时钟
#define __ADC2_CLK_ENABLE          __HAL_RCC_ADC2_CLK_ENABLE              // 使能ADC2时钟
#define __ADC2_FORCE_RESET __HAL_RCC_ADC2_FORCE_RESET                     // 强制复位ADC2
#define __ADC2_RELEASE_RESET __HAL_RCC_ADC2_RELEASE_RESET                 // 释放ADC2复位

/* ADC3 专用时钟控制宏定义 */
#define __ADC3_CLK_DISABLE __HAL_RCC_ADC3_CLK_DISABLE                     // 失能ADC3时钟
#define __ADC3_CLK_ENABLE __HAL_RCC_ADC3_CLK_ENABLE                       // 使能ADC3时钟
#define __ADC3_FORCE_RESET __HAL_RCC_ADC3_FORCE_RESET                     // 强制复位ADC3
#define __ADC3_RELEASE_RESET __HAL_RCC_ADC3_RELEASE_RESET                 // 释放ADC3复位

/* AES (高级加密标准硬件加速器) 相关时钟控制宏定义 */
#define __AES_CLK_DISABLE __HAL_RCC_AES_CLK_DISABLE                       // 失能AES时钟
#define __AES_CLK_ENABLE __HAL_RCC_AES_CLK_ENABLE                         // 使能AES时钟
#define __AES_CLK_SLEEP_DISABLE __HAL_RCC_AES_CLK_SLEEP_DISABLE           // 睡眠模式下失能AES时钟
#define __AES_CLK_SLEEP_ENABLE __HAL_RCC_AES_CLK_SLEEP_ENABLE             // 睡眠模式下使能AES时钟
#define __AES_FORCE_RESET __HAL_RCC_AES_FORCE_RESET                       // 强制复位AES
#define __AES_RELEASE_RESET __HAL_RCC_AES_RELEASE_RESET                   // 释放AES复位

/* CRYP (加密处理器) 相关时钟控制宏定义，功能与AES类似 */
#define __CRYP_CLK_SLEEP_ENABLE      __HAL_RCC_CRYP_CLK_SLEEP_ENABLE      // 睡眠模式下使能CRYP时钟
#define __CRYP_CLK_SLEEP_DISABLE  __HAL_RCC_CRYP_CLK_SLEEP_DISABLE        // 睡眠模式下失能CRYP时钟
#define __CRYP_CLK_ENABLE  __HAL_RCC_CRYP_CLK_ENABLE                      // 使能CRYP时钟
#define __CRYP_CLK_DISABLE  __HAL_RCC_CRYP_CLK_DISABLE                    // 失能CRYP时钟
#define __CRYP_FORCE_RESET       __HAL_RCC_CRYP_FORCE_RESET               // 强制复位CRYP
#define __CRYP_RELEASE_RESET  __HAL_RCC_CRYP_RELEASE_RESET                // 释放CRYP复位

/* AFIO (复用功能I/O) 相关时钟控制宏定义 */
#define __AFIO_CLK_DISABLE __HAL_RCC_AFIO_CLK_DISABLE                     // 失能AFIO时钟
#define __AFIO_CLK_ENABLE __HAL_RCC_AFIO_CLK_ENABLE                       // 使能AFIO时钟
#define __AFIO_FORCE_RESET __HAL_RCC_AFIO_FORCE_RESET                     // 强制复位AFIO
#define __AFIO_RELEASE_RESET __HAL_RCC_AFIO_RELEASE_RESET                 // 释放AFIO复位

/* AHB (高级高性能总线) 总线整体复位控制 */
#define __AHB_FORCE_RESET __HAL_RCC_AHB_FORCE_RESET                       // 强制复位AHB总线
#define __AHB_RELEASE_RESET __HAL_RCC_AHB_RELEASE_RESET                   // 释放AHB总线复位

/* AHB1 总线复位控制 (STM32F4/F7等系列) */
#define __AHB1_FORCE_RESET __HAL_RCC_AHB1_FORCE_RESET                     // 强制复位AHB1总线
#define __AHB1_RELEASE_RESET __HAL_RCC_AHB1_RELEASE_RESET                 // 释放AHB1总线复位

/* AHB2 总线复位控制 */
#define __AHB2_FORCE_RESET __HAL_RCC_AHB2_FORCE_RESET                     // 强制复位AHB2总线
#define __AHB2_RELEASE_RESET __HAL_RCC_AHB2_RELEASE_RESET                 // 释放AHB2总线复位

/* AHB3 总线复位控制 (通常用于FMC等外设) */
#define __AHB3_FORCE_RESET __HAL_RCC_AHB3_FORCE_RESET                     // 强制复位AHB3总线
#define __AHB3_RELEASE_RESET __HAL_RCC_AHB3_RELEASE_RESET                 // 释放AHB3总线复位

/* APB1 (高级外设总线1) 总线复位控制 */
#define __APB1_FORCE_RESET __HAL_RCC_APB1_FORCE_RESET                     // 强制复位APB1总线
#define __APB1_RELEASE_RESET __HAL_RCC_APB1_RELEASE_RESET                 // 释放APB1总线复位

/* APB2 (高级外设总线2) 总线复位控制 */
#define __APB2_FORCE_RESET __HAL_RCC_APB2_FORCE_RESET                     // 强制复位APB2总线
#define __APB2_RELEASE_RESET __HAL_RCC_APB2_RELEASE_RESET                 // 释放APB2总线复位

#if defined(STM32C0)
/* STM32C0系列特有的APB1/APB2分组复位定义 */
#define __HAL_RCC_APB1_FORCE_RESET    __HAL_RCC_APB1_GRP1_FORCE_RESET     // 强制复位APB1组1
#define __HAL_RCC_APB1_RELEASE_RESET  __HAL_RCC_APB1_GRP1_RELEASE_RESET   // 释放APB1组1复位
#define __HAL_RCC_APB2_FORCE_RESET    __HAL_RCC_APB1_GRP2_FORCE_RESET     // 强制复位APB1组2 (对应APB2)
#define __HAL_RCC_APB2_RELEASE_RESET  __HAL_RCC_APB1_GRP2_RELEASE_RESET   // 释放APB1组2复位 (对应APB2)
#endif /* STM32C0 */

/* BKP (后备寄存器) 相关时钟控制宏定义 */
#define __BKP_CLK_DISABLE __HAL_RCC_BKP_CLK_DISABLE                       // 失能BKP时钟
#define __BKP_CLK_ENABLE __HAL_RCC_BKP_CLK_ENABLE                         // 使能BKP时钟
#define __BKP_FORCE_RESET __HAL_RCC_BKP_FORCE_RESET                       // 强制复位BKP
#define __BKP_RELEASE_RESET __HAL_RCC_BKP_RELEASE_RESET                   // 释放BKP复位

/* CAN1 (控制器局域网1) 相关时钟控制宏定义 */
#define __CAN1_CLK_DISABLE __HAL_RCC_CAN1_CLK_DISABLE                     // 失能CAN1时钟
#define __CAN1_CLK_ENABLE __HAL_RCC_CAN1_CLK_ENABLE                       // 使能CAN1时钟
#define __CAN1_CLK_SLEEP_DISABLE __HAL_RCC_CAN1_CLK_SLEEP_DISABLE         // 睡眠模式下失能CAN1时钟
#define __CAN1_CLK_SLEEP_ENABLE __HAL_RCC_CAN1_CLK_SLEEP_ENABLE           // 睡眠模式下使能CAN1时钟
#define __CAN1_FORCE_RESET __HAL_RCC_CAN1_FORCE_RESET                     // 强制复位CAN1
#define __CAN1_RELEASE_RESET __HAL_RCC_CAN1_RELEASE_RESET                 // 释放CAN1复位

/* CAN 通用别名 (默认指向CAN1) */
#define __CAN_CLK_DISABLE         __HAL_RCC_CAN1_CLK_DISABLE              // 失能CAN时钟 (别名)
#define __CAN_CLK_ENABLE          __HAL_RCC_CAN1_CLK_ENABLE               // 使能CAN时钟 (别名)
#define __CAN_FORCE_RESET         __HAL_RCC_CAN1_FORCE_RESET              // 强制复位CAN (别名)
#define __CAN_RELEASE_RESET       __HAL_RCC_CAN1_RELEASE_RESET            // 释放CAN复位 (别名)

/* CAN2 (控制器局域网2) 相关时钟控制宏定义 */
#define __CAN2_CLK_DISABLE __HAL_RCC_CAN2_CLK_DISABLE                     // 失能CAN2时钟
#define __CAN2_CLK_ENABLE __HAL_RCC_CAN2_CLK_ENABLE                       // 使能CAN2时钟
#define __CAN2_FORCE_RESET __HAL_RCC_CAN2_FORCE_RESET                     // 强制复位CAN2
#define __CAN2_RELEASE_RESET __HAL_RCC_CAN2_RELEASE_RESET                 // 释放CAN2复位

/* CEC (HDMI-CEC控制器) 相关时钟控制宏定义 */
#define __CEC_CLK_DISABLE __HAL_RCC_CEC_CLK_DISABLE                       // 失能CEC时钟
#define __CEC_CLK_ENABLE __HAL_RCC_CEC_CLK_ENABLE                         // 使能CEC时钟

/* COMP (比较器) 相关时钟控制宏定义 */
#define __COMP_CLK_DISABLE        __HAL_RCC_COMP_CLK_DISABLE              // 失能COMP时钟
#define __COMP_CLK_ENABLE         __HAL_RCC_COMP_CLK_ENABLE               // 使能COMP时钟
#define __COMP_FORCE_RESET        __HAL_RCC_COMP_FORCE_RESET              // 强制复位COMP
#define __COMP_RELEASE_RESET      __HAL_RCC_COMP_RELEASE_RESET            // 释放COMP复位
#define __COMP_CLK_SLEEP_ENABLE   __HAL_RCC_COMP_CLK_SLEEP_ENABLE         // 睡眠模式下使能COMP时钟
#define __COMP_CLK_SLEEP_DISABLE  __HAL_RCC_COMP_CLK_SLEEP_DISABLE        // 睡眠模式下失能COMP时钟

#define __CEC_FORCE_RESET __HAL_RCC_CEC_FORCE_RESET                       // 强制复位CEC
#define __CEC_RELEASE_RESET __HAL_RCC_CEC_RELEASE_RESET                   // 释放CEC复位

/* CRC (循环冗余校验计算单元) 相关时钟控制宏定义 */
#define __CRC_CLK_DISABLE __HAL_RCC_CRC_CLK_DISABLE                       // 失能CRC时钟
#define __CRC_CLK_ENABLE __HAL_RCC_CRC_CLK_ENABLE                         // 使能CRC时钟
#define __CRC_CLK_SLEEP_DISABLE __HAL_RCC_CRC_CLK_SLEEP_DISABLE           // 睡眠模式下失能CRC时钟
#define __CRC_CLK_SLEEP_ENABLE __HAL_RCC_CRC_CLK_SLEEP_ENABLE             // 睡眠模式下使能CRC时钟
#define __CRC_FORCE_RESET __HAL_RCC_CRC_FORCE_RESET                       // 强制复位CRC
#define __CRC_RELEASE_RESET __HAL_RCC_CRC_RELEASE_RESET                   // 释放CRC复位

/* DAC (数模转换器) 相关时钟控制宏定义 */
#define __DAC_CLK_DISABLE __HAL_RCC_DAC_CLK_DISABLE                       // 失能DAC时钟
#define __DAC_CLK_ENABLE __HAL_RCC_DAC_CLK_ENABLE                         // 使能DAC时钟
#define __DAC_FORCE_RESET __HAL_RCC_DAC_FORCE_RESET                       // 强制复位DAC
#define __DAC_RELEASE_RESET __HAL_RCC_DAC_RELEASE_RESET                   // 释放DAC复位

/* DAC1 专用时钟控制宏定义 */
#define __DAC1_CLK_DISABLE __HAL_RCC_DAC1_CLK_DISABLE                     // 失能DAC1时钟
#define __DAC1_CLK_ENABLE __HAL_RCC_DAC1_CLK_ENABLE                       // 使能DAC1时钟
#define __DAC1_CLK_SLEEP_DISABLE __HAL_RCC_DAC1_CLK_SLEEP_DISABLE         // 睡眠模式下失能DAC1时钟
#define __DAC1_CLK_SLEEP_ENABLE __HAL_RCC_DAC1_CLK_SLEEP_ENABLE           // 睡眠模式下使能DAC1时钟
#define __DAC1_FORCE_RESET __HAL_RCC_DAC1_FORCE_RESET                     // 强制复位DAC1
#define __DAC1_RELEASE_RESET __HAL_RCC_DAC1_RELEASE_RESET                 // 释放DAC1复位

/* DBGMCU (调试接口) 相关时钟控制宏定义 */
#define __DBGMCU_CLK_ENABLE     __HAL_RCC_DBGMCU_CLK_ENABLE               // 使能DBGMCU时钟
#define __DBGMCU_CLK_DISABLE     __HAL_RCC_DBGMCU_CLK_DISABLE             // 失能DBGMCU时钟
#define __DBGMCU_FORCE_RESET    __HAL_RCC_DBGMCU_FORCE_RESET              // 强制复位DBGMCU
#define __DBGMCU_RELEASE_RESET  __HAL_RCC_DBGMCU_RELEASE_RESET            // 释放DBGMCU复位

/* DFSDM (数字滤波器) 相关时钟控制宏定义 */
#define __DFSDM_CLK_DISABLE __HAL_RCC_DFSDM_CLK_DISABLE                   // 失能DFSDM时钟
#define __DFSDM_CLK_ENABLE __HAL_RCC_DFSDM_CLK_ENABLE                     // 使能DFSDM时钟
#define __DFSDM_CLK_SLEEP_DISABLE __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE       // 睡眠模式下失能DFSDM时钟
#define __DFSDM_CLK_SLEEP_ENABLE __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE         // 睡眠模式下使能DFSDM时钟
#define __DFSDM_FORCE_RESET __HAL_RCC_DFSDM_FORCE_RESET                   // 强制复位DFSDM
#define __DFSDM_RELEASE_RESET __HAL_RCC_DFSDM_RELEASE_RESET               // 释放DFSDM复位

/* DMA1 (直接存储器访问控制器1) 相关时钟控制宏定义 */
#define __DMA1_CLK_DISABLE __HAL_RCC_DMA1_CLK_DISABLE                     // 失能DMA1时钟
#define __DMA1_CLK_ENABLE __HAL_RCC_DMA1_CLK_ENABLE                       // 使能DMA1时钟
#define __DMA1_CLK_SLEEP_DISABLE __HAL_RCC_DMA1_CLK_SLEEP_DISABLE         // 睡眠模式下失能DMA1时钟
#define __DMA1_CLK_SLEEP_ENABLE __HAL_RCC_DMA1_CLK_SLEEP_ENABLE           // 睡眠模式下使能DMA1时钟
#define __DMA1_FORCE_RESET __HAL_RCC_DMA1_FORCE_RESET                     // 强制复位DMA1
#define __DMA1_RELEASE_RESET __HAL_RCC_DMA1_RELEASE_RESET                 // 释放DMA1复位

/* DMA2 (直接存储器访问控制器2) 相关时钟控制宏定义 */
#define __DMA2_CLK_DISABLE __HAL_RCC_DMA2_CLK_DISABLE                     // 失能DMA2时钟
#define __DMA2_CLK_ENABLE __HAL_RCC_DMA2_CLK_ENABLE                       // 使能DMA2时钟
#define __DMA2_CLK_SLEEP_DISABLE __HAL_RCC_DMA2_CLK_SLEEP_DISABLE         // 睡眠模式下失能DMA2时钟
#define __DMA2_CLK_SLEEP_ENABLE __HAL_RCC_DMA2_CLK_SLEEP_ENABLE           // 睡眠模式下使能DMA2时钟
#define __DMA2_FORCE_RESET __HAL_RCC_DMA2_FORCE_RESET                     // 强制复位DMA2
#define __DMA2_RELEASE_RESET __HAL_RCC_DMA2_RELEASE_RESET                 // 释放DMA2复位

/* ETHMAC (以太网MAC控制器) 相关时钟控制宏定义 */
#define __ETHMAC_CLK_DISABLE __HAL_RCC_ETHMAC_CLK_DISABLE                 // 失能以太网MAC时钟
#define __ETHMAC_CLK_ENABLE __HAL_RCC_ETHMAC_CLK_ENABLE                   // 使能以太网MAC时钟
#define __ETHMAC_FORCE_RESET __HAL_RCC_ETHMAC_FORCE_RESET                 // 强制复位以太网MAC
#define __ETHMAC_RELEASE_RESET __HAL_RCC_ETHMAC_RELEASE_RESET             // 释放以太网MAC复位
#define __ETHMACRX_CLK_DISABLE __HAL_RCC_ETHMACRX_CLK_DISABLE             // 失能以太网MAC接收时钟
#define __ETHMACRX_CLK_ENABLE __HAL_RCC_ETHMACRX_CLK_ENABLE               // 使能以太网MAC接收时钟
#define __ETHMACTX_CLK_DISABLE __HAL_RCC_ETHMACTX_CLK_DISABLE             // 失能以太网MAC发送时钟
#define __ETHMACTX_CLK_ENABLE __HAL_RCC_ETHMACTX_CLK_ENABLE               // 使能以太网MAC发送时钟

/* FIREWALL (防火墙) 相关时钟控制宏定义 */
#define __FIREWALL_CLK_DISABLE __HAL_RCC_FIREWALL_CLK_DISABLE             // 失能防火墙时钟
#define __FIREWALL_CLK_ENABLE __HAL_RCC_FIREWALL_CLK_ENABLE               // 使能防火墙时钟

/* FLASH (闪存) 相关时钟控制宏定义 */
#define __FLASH_CLK_DISABLE __HAL_RCC_FLASH_CLK_DISABLE                   // 失能Flash接口时钟
#define __FLASH_CLK_ENABLE __HAL_RCC_FLASH_CLK_ENABLE                     // 使能Flash接口时钟
#define __FLASH_CLK_SLEEP_DISABLE __HAL_RCC_FLASH_CLK_SLEEP_DISABLE       // 睡眠模式下失能Flash时钟
#define __FLASH_CLK_SLEEP_ENABLE __HAL_RCC_FLASH_CLK_SLEEP_ENABLE         // 睡眠模式下使能Flash时钟
#define __FLASH_FORCE_RESET __HAL_RCC_FLASH_FORCE_RESET                   // 强制复位Flash
#define __FLASH_RELEASE_RESET __HAL_RCC_FLASH_RELEASE_RESET               // 释放Flash复位

/* FLITF (Flash存储器接口) 相关时钟控制宏定义 */
#define __FLITF_CLK_DISABLE       __HAL_RCC_FLITF_CLK_DISABLE             // 失能FLITF时钟
#define __FLITF_CLK_ENABLE        __HAL_RCC_FLITF_CLK_ENABLE              // 使能FLITF时钟
#define __FLITF_FORCE_RESET       __HAL_RCC_FLITF_FORCE_RESET             // 强制复位FLITF
#define __FLITF_RELEASE_RESET     __HAL_RCC_FLITF_RELEASE_RESET           // 释放FLITF复位
#define __FLITF_CLK_SLEEP_ENABLE  __HAL_RCC_FLITF_CLK_SLEEP_ENABLE        // 睡眠模式下使能FLITF时钟
#define __FLITF_CLK_SLEEP_DISABLE __HAL_RCC_FLITF_CLK_SLEEP_DISABLE       // 睡眠模式下失能FLITF时钟

/* FMC (灵活存储控制器) 相关时钟控制宏定义 */
#define __FMC_CLK_DISABLE __HAL_RCC_FMC_CLK_DISABLE                       // 失能FMC时钟
#define __FMC_CLK_ENABLE __HAL_RCC_FMC_CLK_ENABLE                         // 使能FMC时钟
#define __FMC_CLK_SLEEP_DISABLE __HAL_RCC_FMC_CLK_SLEEP_DISABLE           // 睡眠模式下失能FMC时钟
#define __FMC_CLK_SLEEP_ENABLE __HAL_RCC_FMC_CLK_SLEEP_ENABLE             // 睡眠模式下使能FMC时钟
#define __FMC_FORCE_RESET __HAL_RCC_FMC_FORCE_RESET                       // 强制复位FMC
#define __FMC_RELEASE_RESET __HAL_RCC_FMC_RELEASE_RESET                   // 释放FMC复位

/* FSMC (静态存储控制器) 相关时钟控制宏定义 */
#define __FSMC_CLK_DISABLE __HAL_RCC_FSMC_CLK_DISABLE                     // 失能FSMC时钟
#define __FSMC_CLK_ENABLE __HAL_RCC_FSMC_CLK_ENABLE                       // 使能FSMC时钟

/* GPIOA (通用输入输出端口A) 相关时钟控制宏定义 */
#define __GPIOA_CLK_DISABLE __HAL_RCC_GPIOA_CLK_DISABLE                   // 失能GPIOA时钟
#define __GPIOA_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE                     // 使能GPIOA时钟
#define __GPIOA_CLK_SLEEP_DISABLE __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOA时钟
#define __GPIOA_CLK_SLEEP_ENABLE __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOA时钟
#define __GPIOA_FORCE_RESET __HAL_RCC_GPIOA_FORCE_RESET                   // 强制复位GPIOA
#define __GPIOA_RELEASE_RESET __HAL_RCC_GPIOA_RELEASE_RESET               // 释放GPIOA复位

/* GPIOB (通用输入输出端口B) 相关时钟控制宏定义 */
#define __GPIOB_CLK_DISABLE __HAL_RCC_GPIOB_CLK_DISABLE                   // 失能GPIOB时钟
#define __GPIOB_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE                     // 使能GPIOB时钟
#define __GPIOB_CLK_SLEEP_DISABLE __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOB时钟
#define __GPIOB_CLK_SLEEP_ENABLE __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOB时钟
#define __GPIOB_FORCE_RESET __HAL_RCC_GPIOB_FORCE_RESET                   // 强制复位GPIOB
#define __GPIOB_RELEASE_RESET __HAL_RCC_GPIOB_RELEASE_RESET               // 释放GPIOB复位

/* GPIOC (通用输入输出端口C) 相关时钟控制宏定义 */
#define __GPIOC_CLK_DISABLE __HAL_RCC_GPIOC_CLK_DISABLE                   // 失能GPIOC时钟
#define __GPIOC_CLK_ENABLE __HAL_RCC_GPIOC_CLK_ENABLE                     // 使能GPIOC时钟
#define __GPIOC_CLK_SLEEP_DISABLE __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOC时钟
#define __GPIOC_CLK_SLEEP_ENABLE __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOC时钟
#define __GPIOC_FORCE_RESET __HAL_RCC_GPIOC_FORCE_RESET                   // 强制复位GPIOC
#define __GPIOC_RELEASE_RESET __HAL_RCC_GPIOC_RELEASE_RESET               // 释放GPIOC复位

/* GPIOD (通用输入输出端口D) 相关时钟控制宏定义 */
#define __GPIOD_CLK_DISABLE __HAL_RCC_GPIOD_CLK_DISABLE                   // 失能GPIOD时钟
#define __GPIOD_CLK_ENABLE __HAL_RCC_GPIOD_CLK_ENABLE                     // 使能GPIOD时钟
#define __GPIOD_CLK_SLEEP_DISABLE __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOD时钟
#define __GPIOD_CLK_SLEEP_ENABLE __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOD时钟
#define __GPIOD_FORCE_RESET __HAL_RCC_GPIOD_FORCE_RESET                   // 强制复位GPIOD
#define __GPIOD_RELEASE_RESET __HAL_RCC_GPIOD_RELEASE_RESET               // 释放GPIOD复位

/* GPIOE (通用输入输出端口E) 相关时钟控制宏定义 */
#define __GPIOE_CLK_DISABLE __HAL_RCC_GPIOE_CLK_DISABLE                   // 失能GPIOE时钟
#define __GPIOE_CLK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE                     // 使能GPIOE时钟
#define __GPIOE_CLK_SLEEP_DISABLE __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOE时钟
#define __GPIOE_CLK_SLEEP_ENABLE __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOE时钟
#define __GPIOE_FORCE_RESET __HAL_RCC_GPIOE_FORCE_RESET                   // 强制复位GPIOE
#define __GPIOE_RELEASE_RESET __HAL_RCC_GPIOE_RELEASE_RESET               // 释放GPIOE复位

/* GPIOF (通用输入输出端口F) 相关时钟控制宏定义 */
#define __GPIOF_CLK_DISABLE __HAL_RCC_GPIOF_CLK_DISABLE                   // 失能GPIOF时钟
#define __GPIOF_CLK_ENABLE __HAL_RCC_GPIOF_CLK_ENABLE                     // 使能GPIOF时钟
#define __GPIOF_CLK_SLEEP_DISABLE __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOF时钟
#define __GPIOF_CLK_SLEEP_ENABLE __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOF时钟
#define __GPIOF_FORCE_RESET __HAL_RCC_GPIOF_FORCE_RESET                   // 强制复位GPIOF
#define __GPIOF_RELEASE_RESET __HAL_RCC_GPIOF_RELEASE_RESET               // 释放GPIOF复位

/* GPIOG (通用输入输出端口G) 相关时钟控制宏定义 */
#define __GPIOG_CLK_DISABLE __HAL_RCC_GPIOG_CLK_DISABLE                   // 失能GPIOG时钟
#define __GPIOG_CLK_ENABLE __HAL_RCC_GPIOG_CLK_ENABLE                     // 使能GPIOG时钟
#define __GPIOG_CLK_SLEEP_DISABLE __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOG时钟
#define __GPIOG_CLK_SLEEP_ENABLE __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOG时钟
#define __GPIOG_FORCE_RESET __HAL_RCC_GPIOG_FORCE_RESET                   // 强制复位GPIOG
#define __GPIOG_RELEASE_RESET __HAL_RCC_GPIOG_RELEASE_RESET               // 释放GPIOG复位

/* GPIOH (通用输入输出端口H) 相关时钟控制宏定义 */
#define __GPIOH_CLK_DISABLE __HAL_RCC_GPIOH_CLK_DISABLE                   // 失能GPIOH时钟
#define __GPIOH_CLK_ENABLE __HAL_RCC_GPIOH_CLK_ENABLE                     // 使能GPIOH时钟
#define __GPIOH_CLK_SLEEP_DISABLE __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOH时钟
#define __GPIOH_CLK_SLEEP_ENABLE __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOH时钟
#define __GPIOH_FORCE_RESET __HAL_RCC_GPIOH_FORCE_RESET                   // 强制复位GPIOH
#define __GPIOH_RELEASE_RESET __HAL_RCC_GPIOH_RELEASE_RESET               // 释放GPIOH复位

/* I2C1 (I2C总线接口1) 相关时钟控制宏定义 */
#define __I2C1_CLK_DISABLE __HAL_RCC_I2C1_CLK_DISABLE                     // 失能I2C1时钟
#define __I2C1_CLK_ENABLE __HAL_RCC_I2C1_CLK_ENABLE                       // 使能I2C1时钟
#define __I2C1_CLK_SLEEP_DISABLE __HAL_RCC_I2C1_CLK_SLEEP_DISABLE         // 睡眠模式下失能I2C1时钟
#define __I2C1_CLK_SLEEP_ENABLE __HAL_RCC_I2C1_CLK_SLEEP_ENABLE           // 睡眠模式下使能I2C1时钟
#define __I2C1_FORCE_RESET __HAL_RCC_I2C1_FORCE_RESET                     // 强制复位I2C1
#define __I2C1_RELEASE_RESET __HAL_RCC_I2C1_RELEASE_RESET                 // 释放I2C1复位

/* I2C2 (I2C总线接口2) 相关时钟控制宏定义 */
#define __I2C2_CLK_DISABLE __HAL_RCC_I2C2_CLK_DISABLE                     // 失能I2C2时钟
#define __I2C2_CLK_ENABLE __HAL_RCC_I2C2_CLK_ENABLE                       // 使能I2C2时钟
#define __I2C2_CLK_SLEEP_DISABLE __HAL_RCC_I2C2_CLK_SLEEP_DISABLE         // 睡眠模式下失能I2C2时钟
#define __I2C2_CLK_SLEEP_ENABLE __HAL_RCC_I2C2_CLK_SLEEP_ENABLE           // 睡眠模式下使能I2C2时钟
#define __I2C2_FORCE_RESET __HAL_RCC_I2C2_FORCE_RESET                     // 强制复位I2C2
#define __I2C2_RELEASE_RESET __HAL_RCC_I2C2_RELEASE_RESET                 // 释放I2C2复位

/* I2C3 (I2C总线接口3) 相关时钟控制宏定义 */
#define __I2C3_CLK_DISABLE __HAL_RCC_I2C3_CLK_DISABLE                     // 失能I2C3时钟
#define __I2C3_CLK_ENABLE __HAL_RCC_I2C3_CLK_ENABLE                       // 使能I2C3时钟
#define __I2C3_CLK_SLEEP_DISABLE __HAL_RCC_I2C3_CLK_SLEEP_DISABLE         // 睡眠模式下失能I2C3时钟
#define __I2C3_CLK_SLEEP_ENABLE __HAL_RCC_I2C3_CLK_SLEEP_ENABLE           // 睡眠模式下使能I2C3时钟
#define __I2C3_FORCE_RESET __HAL_RCC_I2C3_FORCE_RESET                     // 强制复位I2C3
#define __I2C3_RELEASE_RESET __HAL_RCC_I2C3_RELEASE_RESET                 // 释放I2C3复位

/* LCD (液晶显示控制器) 相关时钟控制宏定义 */
#define __LCD_CLK_DISABLE __HAL_RCC_LCD_CLK_DISABLE                       // 失能LCD时钟
#define __LCD_CLK_ENABLE __HAL_RCC_LCD_CLK_ENABLE                         // 使能LCD时钟
#define __LCD_CLK_SLEEP_DISABLE __HAL_RCC_LCD_CLK_SLEEP_DISABLE           // 睡眠模式下失能LCD时钟
#define __LCD_CLK_SLEEP_ENABLE __HAL_RCC_LCD_CLK_SLEEP_ENABLE             // 睡眠模式下使能LCD时钟
#define __LCD_FORCE_RESET __HAL_RCC_LCD_FORCE_RESET                       // 强制复位LCD
#define __LCD_RELEASE_RESET __HAL_RCC_LCD_RELEASE_RESET                   // 释放LCD复位

/* LPTIM1 (低功耗定时器1) 相关时钟控制宏定义 */
#define __LPTIM1_CLK_DISABLE __HAL_RCC_LPTIM1_CLK_DISABLE                 // 失能LPTIM1时钟
#define __LPTIM1_CLK_ENABLE __HAL_RCC_LPTIM1_CLK_ENABLE                   // 使能LPTIM1时钟
#define __LPTIM1_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE     // 睡眠模式下失能LPTIM1时钟
#define __LPTIM1_CLK_SLEEP_ENABLE __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE       // 睡眠模式下使能LPTIM1时钟
#define __LPTIM1_FORCE_RESET __HAL_RCC_LPTIM1_FORCE_RESET                 // 强制复位LPTIM1
#define __LPTIM1_RELEASE_RESET __HAL_RCC_LPTIM1_RELEASE_RESET             // 释放LPTIM1复位

/* LPTIM2 (低功耗定时器2) 相关时钟控制宏定义 */
#define __LPTIM2_CLK_DISABLE __HAL_RCC_LPTIM2_CLK_DISABLE                 // 失能LPTIM2时钟
#define __LPTIM2_CLK_ENABLE __HAL_RCC_LPTIM2_CLK_ENABLE                   // 使能LPTIM2时钟
#define __LPTIM2_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE     // 睡眠模式下失能LPTIM2时钟
#define __LPTIM2_CLK_SLEEP_ENABLE __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE       // 睡眠模式下使能LPTIM2时钟
#define __LPTIM2_FORCE_RESET __HAL_RCC_LPTIM2_FORCE_RESET                 // 强制复位LPTIM2
#define __LPTIM2_RELEASE_RESET __HAL_RCC_LPTIM2_RELEASE_RESET             // 释放LPTIM2复位

/* LPUART1 (低功耗通用异步收发传输器1) 相关时钟控制宏定义 */
#define __LPUART1_CLK_DISABLE __HAL_RCC_LPUART1_CLK_DISABLE               // 失能LPUART1时钟
#define __LPUART1_CLK_ENABLE __HAL_RCC_LPUART1_CLK_ENABLE                 // 使能LPUART1时钟
#define __LPUART1_CLK_SLEEP_DISABLE __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE   // 睡眠模式下失能LPUART1时钟
#define __LPUART1_CLK_SLEEP_ENABLE __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE     // 睡眠模式下使能LPUART1时钟
#define __LPUART1_FORCE_RESET __HAL_RCC_LPUART1_FORCE_RESET               // 强制复位LPUART1
#define __LPUART1_RELEASE_RESET __HAL_RCC_LPUART1_RELEASE_RESET           // 释放LPUART1复位

/* OPAMP (运算放大器) 相关时钟控制宏定义 */
#define __OPAMP_CLK_DISABLE __HAL_RCC_OPAMP_CLK_DISABLE                   // 失能OPAMP时钟
#define __OPAMP_CLK_ENABLE __HAL_RCC_OPAMP_CLK_ENABLE                     // 使能OPAMP时钟
#define __OPAMP_CLK_SLEEP_DISABLE __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE       // 睡眠模式下失能OPAMP时钟
#define __OPAMP_CLK_SLEEP_ENABLE __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE         // 睡眠模式下使能OPAMP时钟
#define __OPAMP_FORCE_RESET __HAL_RCC_OPAMP_FORCE_RESET                   // 强制复位OPAMP
#define __OPAMP_RELEASE_RESET __HAL_RCC_OPAMP_RELEASE_RESET               // 释放OPAMP复位

/* OTGFS (USB On-The-Go 全速) 相关时钟控制宏定义 */
#define __OTGFS_CLK_DISABLE __HAL_RCC_OTGFS_CLK_DISABLE                   // 失能OTGFS时钟
#define __OTGFS_CLK_ENABLE __HAL_RCC_OTGFS_CLK_ENABLE                     // 使能OTGFS时钟
#define __OTGFS_CLK_SLEEP_DISABLE __HAL_RCC_OTGFS_CLK_SLEEP_DISABLE       // 睡眠模式下失能OTGFS时钟
#define __OTGFS_CLK_SLEEP_ENABLE __HAL_RCC_OTGFS_CLK_SLEEP_ENABLE         // 睡眠模式下使能OTGFS时钟
#define __OTGFS_FORCE_RESET __HAL_RCC_OTGFS_FORCE_RESET                   // 强制复位OTGFS
#define __OTGFS_RELEASE_RESET __HAL_RCC_OTGFS_RELEASE_RESET               // 释放OTGFS复位

/* PWR (电源接口) 相关时钟控制宏定义 */
#define __PWR_CLK_DISABLE __HAL_RCC_PWR_CLK_DISABLE                       // 失能PWR时钟
#define __PWR_CLK_ENABLE __HAL_RCC_PWR_CLK_ENABLE                         // 使能PWR时钟
#define __PWR_CLK_SLEEP_DISABLE __HAL_RCC_PWR_CLK_SLEEP_DISABLE           // 睡眠模式下失能PWR时钟
#define __PWR_CLK_SLEEP_ENABLE __HAL_RCC_PWR_CLK_SLEEP_ENABLE             // 睡眠模式下使能PWR时钟
#define __PWR_FORCE_RESET __HAL_RCC_PWR_FORCE_RESET                       // 强制复位PWR
#define __PWR_RELEASE_RESET __HAL_RCC_PWR_RELEASE_RESET                   // 释放PWR复位

/* QSPI (四线SPI接口) 相关时钟控制宏定义 */
#define __QSPI_CLK_DISABLE __HAL_RCC_QSPI_CLK_DISABLE                     // 失能QSPI时钟
#define __QSPI_CLK_ENABLE __HAL_RCC_QSPI_CLK_ENABLE                       // 使能QSPI时钟
#define __QSPI_CLK_SLEEP_DISABLE __HAL_RCC_QSPI_CLK_SLEEP_DISABLE         // 睡眠模式下失能QSPI时钟
#define __QSPI_CLK_SLEEP_ENABLE __HAL_RCC_QSPI_CLK_SLEEP_ENABLE           // 睡眠模式下使能QSPI时钟
#define __QSPI_FORCE_RESET __HAL_RCC_QSPI_FORCE_RESET                     // 强制复位QSPI
#define __QSPI_RELEASE_RESET __HAL_RCC_QSPI_RELEASE_RESET                 // 释放QSPI复位

#if defined(STM32WB)
/* STM32WB系列特有定义：将QSPI宏映射到QUADSPI底层实现 */
#define __HAL_RCC_QSPI_CLK_DISABLE            __HAL_RCC_QUADSPI_CLK_DISABLE          // 失能QSPI时钟
#define __HAL_RCC_QSPI_CLK_ENABLE             __HAL_RCC_QUADSPI_CLK_ENABLE           // 使能QSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_DISABLE      __HAL_RCC_QUADSPI_CLK_SLEEP_DISABLE    // 睡眠模式下失能QSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_ENABLE       __HAL_RCC_QUADSPI_CLK_SLEEP_ENABLE     // 睡眠模式下使能QSPI时钟
#define __HAL_RCC_QSPI_FORCE_RESET            __HAL_RCC_QUADSPI_FORCE_RESET          // 强制复位QSPI
#define __HAL_RCC_QSPI_RELEASE_RESET          __HAL_RCC_QUADSPI_RELEASE_RESET        // 释放QSPI复位
#define __HAL_RCC_QSPI_IS_CLK_ENABLED         __HAL_RCC_QUADSPI_IS_CLK_ENABLED       // 检查QSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_DISABLED        __HAL_RCC_QUADSPI_IS_CLK_DISABLED      // 检查QSPI时钟是否失能
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_ENABLED   __HAL_RCC_QUADSPI_IS_CLK_SLEEP_ENABLED // 检查睡眠模式下QSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_DISABLED  __HAL_RCC_QUADSPI_IS_CLK_SLEEP_DISABLED// 检查睡眠模式下QSPI时钟是否失能
#define QSPI_IRQHandler QUADSPI_IRQHandler                                    // 中断服务函数别名映射
#endif /* __HAL_RCC_QUADSPI_CLK_ENABLE */
