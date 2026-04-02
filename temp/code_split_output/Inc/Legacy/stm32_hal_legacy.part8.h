/*
  这里定义的是STM32外设时钟控制相关的宏定义别名。
  为了保持代码兼容性，旧版本的HAL库宏定义（左侧）被映射为新版本的HAL库宏定义（右侧）。
  这些宏主要用于控制外设的时钟使能、失能、休眠模式时钟控制以及强制/释放复位。
  对于初学者，建议在代码中直接使用右侧的新版宏定义（如 __HAL_RCC_...），更符合HAL库的最新规范。
*/

/* ADC (模数转换器) 相关时钟及复位控制 */
#define __ADC_CLK_DISABLE          __HAL_RCC_ADC_CLK_DISABLE           // 禁用ADC时钟
#define __ADC_CLK_ENABLE           __HAL_RCC_ADC_CLK_ENABLE            // 使能ADC时钟
#define __ADC_CLK_SLEEP_DISABLE    __HAL_RCC_ADC_CLK_SLEEP_DISABLE     // 禁用ADC休眠模式时钟
#define __ADC_CLK_SLEEP_ENABLE     __HAL_RCC_ADC_CLK_SLEEP_ENABLE      // 使能ADC休眠模式时钟
#define __ADC_FORCE_RESET          __HAL_RCC_ADC_FORCE_RESET           // 强制复位ADC
#define __ADC_RELEASE_RESET        __HAL_RCC_ADC_RELEASE_RESET         // 释放ADC复位（结束复位状态）

/* ADC1 外设专用控制 */
#define __ADC1_CLK_DISABLE         __HAL_RCC_ADC1_CLK_DISABLE          // 禁用ADC1时钟
#define __ADC1_CLK_ENABLE          __HAL_RCC_ADC1_CLK_ENABLE           // 使能ADC1时钟
#define __ADC1_FORCE_RESET         __HAL_RCC_ADC1_FORCE_RESET          // 强制复位ADC1
#define __ADC1_RELEASE_RESET       __HAL_RCC_ADC1_RELEASE_RESET        // 释放ADC1复位
#define __ADC1_CLK_SLEEP_ENABLE    __HAL_RCC_ADC1_CLK_SLEEP_ENABLE     // 使能ADC1休眠时钟
#define __ADC1_CLK_SLEEP_DISABLE   __HAL_RCC_ADC1_CLK_SLEEP_DISABLE    // 禁用ADC1休眠时钟

/* ADC2 外设专用控制 */
#define __ADC2_CLK_DISABLE         __HAL_RCC_ADC2_CLK_DISABLE          // 禁用ADC2时钟
#define __ADC2_CLK_ENABLE          __HAL_RCC_ADC2_CLK_ENABLE           // 使能ADC2时钟
#define __ADC2_FORCE_RESET __HAL_RCC_ADC2_FORCE_RESET                  // 强制复位ADC2
#define __ADC2_RELEASE_RESET __HAL_RCC_ADC2_RELEASE_RESET              // 释放ADC2复位

/* ADC3 外设专用控制 */
#define __ADC3_CLK_DISABLE __HAL_RCC_ADC3_CLK_DISABLE                  // 禁用ADC3时钟
#define __ADC3_CLK_ENABLE __HAL_RCC_ADC3_CLK_ENABLE                    // 使能ADC3时钟
#define __ADC3_FORCE_RESET __HAL_RCC_ADC3_FORCE_RESET                  // 强制复位ADC3
#define __ADC3_RELEASE_RESET __HAL_RCC_ADC3_RELEASE_RESET              // 释放ADC3复位

/* AES (高级加密标准) 硬件加密模块控制 */
#define __AES_CLK_DISABLE __HAL_RCC_AES_CLK_DISABLE                    // 禁用AES时钟
#define __AES_CLK_ENABLE __HAL_RCC_AES_CLK_ENABLE                      // 使能AES时钟
#define __AES_CLK_SLEEP_DISABLE __HAL_RCC_AES_CLK_SLEEP_DISABLE        // 禁用AES休眠时钟
#define __AES_CLK_SLEEP_ENABLE __HAL_RCC_AES_CLK_SLEEP_ENABLE          // 使能AES休眠时钟
#define __AES_FORCE_RESET __HAL_RCC_AES_FORCE_RESET                    // 强制复位AES
#define __AES_RELEASE_RESET __HAL_RCC_AES_RELEASE_RESET                // 释放AES复位

/* CRYP (加密处理器) 模块控制，部分STM32系列中AES模块称为CRYP */
#define __CRYP_CLK_SLEEP_ENABLE      __HAL_RCC_CRYP_CLK_SLEEP_ENABLE   // 使能CRYP休眠时钟
#define __CRYP_CLK_SLEEP_DISABLE  __HAL_RCC_CRYP_CLK_SLEEP_DISABLE     // 禁用CRYP休眠时钟
#define __CRYP_CLK_ENABLE  __HAL_RCC_CRYP_CLK_ENABLE                   // 使能CRYP时钟
#define __CRYP_CLK_DISABLE  __HAL_RCC_CRYP_CLK_DISABLE                 // 禁用CRYP时钟
#define __CRYP_FORCE_RESET       __HAL_RCC_CRYP_FORCE_RESET            // 强制复位CRYP
#define __CRYP_RELEASE_RESET  __HAL_RCC_CRYP_RELEASE_RESET             // 释放CRYP复位

/* AFIO (复用功能I/O) 模块控制，用于引脚复用重映射 */
#define __AFIO_CLK_DISABLE __HAL_RCC_AFIO_CLK_DISABLE                  // 禁用AFIO时钟
#define __AFIO_CLK_ENABLE __HAL_RCC_AFIO_CLK_ENABLE                    // 使能AFIO时钟
#define __AFIO_FORCE_RESET __HAL_RCC_AFIO_FORCE_RESET                  // 强制复位AFIO
#define __AFIO_RELEASE_RESET __HAL_RCC_AFIO_RELEASE_RESET              // 释放AFIO复位

/* AHB (高级高性能总线) 总线整体复位控制 */
#define __AHB_FORCE_RESET __HAL_RCC_AHB_FORCE_RESET                    // 强制复位整个AHB总线
#define __AHB_RELEASE_RESET __HAL_RCC_AHB_RELEASE_RESET                // 释放AHB总线复位

/* AHB1/2/3 总线单独复位控制（针对多总线架构的STM32） */
#define __AHB1_FORCE_RESET __HAL_RCC_AHB1_FORCE_RESET                  // 强制复位AHB1总线
#define __AHB1_RELEASE_RESET __HAL_RCC_AHB1_RELEASE_RESET              // 释放AHB1总线复位
#define __AHB2_FORCE_RESET __HAL_RCC_AHB2_FORCE_RESET                  // 强制复位AHB2总线
#define __AHB2_RELEASE_RESET __HAL_RCC_AHB2_RELEASE_RESET              // 释放AHB2总线复位
#define __AHB3_FORCE_RESET __HAL_RCC_AHB3_FORCE_RESET                  // 强制复位AHB3总线
#define __AHB3_RELEASE_RESET __HAL_RCC_AHB3_RELEASE_RESET              // 释放AHB3总线复位

/* APB1/2 (高级外设总线) 总线整体复位控制 */
#define __APB1_FORCE_RESET __HAL_RCC_APB1_FORCE_RESET                  // 强制复位APB1总线
#define __APB1_RELEASE_RESET __HAL_RCC_APB1_RELEASE_RESET              // 释放APB1总线复位
#define __APB2_FORCE_RESET __HAL_RCC_APB2_FORCE_RESET                  // 强制复位APB2总线
#define __APB2_RELEASE_RESET __HAL_RCC_APB2_RELEASE_RESET              // 释放APB2总线复位

/* STM32C0系列特殊定义：APB1分为GRP1和GRP2两组 */
#if defined(STM32C0)
#define __HAL_RCC_APB1_FORCE_RESET    __HAL_RCC_APB1_GRP1_FORCE_RESET  // 强制复位APB1组1
#define __HAL_RCC_APB1_RELEASE_RESET  __HAL_RCC_APB1_GRP1_RELEASE_RESET // 释放复位APB1组1
#define __HAL_RCC_APB2_FORCE_RESET    __HAL_RCC_APB1_GRP2_FORCE_RESET  // 强制复位APB1组2（此处映射为APB2）
#define __HAL_RCC_APB2_RELEASE_RESET  __HAL_RCC_APB1_GRP2_RELEASE_RESET // 释放复位APB1组2
#endif /* STM32C0 */

/* BKP (备份寄存器) 模块控制 */
#define __BKP_CLK_DISABLE __HAL_RCC_BKP_CLK_DISABLE                    // 禁用BKP时钟
#define __BKP_CLK_ENABLE __HAL_RCC_BKP_CLK_ENABLE                      // 使能BKP时钟
#define __BKP_FORCE_RESET __HAL_RCC_BKP_FORCE_RESET                    // 强制复位BKP
#define __BKP_RELEASE_RESET __HAL_RCC_BKP_RELEASE_RESET                // 释放BKP复位

/* CAN1 (控制器局域网模块1) 控制 */
#define __CAN1_CLK_DISABLE __HAL_RCC_CAN1_CLK_DISABLE                  // 禁用CAN1时钟
#define __CAN1_CLK_ENABLE __HAL_RCC_CAN1_CLK_ENABLE                    // 使能CAN1时钟
#define __CAN1_CLK_SLEEP_DISABLE __HAL_RCC_CAN1_CLK_SLEEP_DISABLE      // 禁用CAN1休眠时钟
#define __CAN1_CLK_SLEEP_ENABLE __HAL_RCC_CAN1_CLK_SLEEP_ENABLE        // 使能CAN1休眠时钟
#define __CAN1_FORCE_RESET __HAL_RCC_CAN1_FORCE_RESET                  // 强制复位CAN1
#define __CAN1_RELEASE_RESET __HAL_RCC_CAN1_RELEASE_RESET              // 释放CAN1复位

/* CAN 通用别名 (默认指向CAN1) */
#define __CAN_CLK_DISABLE         __HAL_RCC_CAN1_CLK_DISABLE           // 禁用CAN时钟（别名）
#define __CAN_CLK_ENABLE          __HAL_RCC_CAN1_CLK_ENABLE            // 使能CAN时钟（别名）
#define __CAN_FORCE_RESET         __HAL_RCC_CAN1_FORCE_RESET           // 强制复位CAN（别名）
#define __CAN_RELEASE_RESET       __HAL_RCC_CAN1_RELEASE_RESET         // 释放CAN复位（别名）

/* CAN2 (控制器局域网模块2) 控制 */
#define __CAN2_CLK_DISABLE __HAL_RCC_CAN2_CLK_DISABLE                  // 禁用CAN2时钟
#define __CAN2_CLK_ENABLE __HAL_RCC_CAN2_CLK_ENABLE                    // 使能CAN2时钟
#define __CAN2_FORCE_RESET __HAL_RCC_CAN2_FORCE_RESET                  // 强制复位CAN2
#define __CAN2_RELEASE_RESET __HAL_RCC_CAN2_RELEASE_RESET              // 释放CAN2复位

/* CEC (消费电子控制) 模块控制，用于HDMI CEC功能 */
#define __CEC_CLK_DISABLE __HAL_RCC_CEC_CLK_DISABLE                    // 禁用CEC时钟
#define __CEC_CLK_ENABLE __HAL_RCC_CEC_CLK_ENABLE                      // 使能CEC时钟

/* COMP (比较器) 模块控制 */
#define __COMP_CLK_DISABLE        __HAL_RCC_COMP_CLK_DISABLE           // 禁用COMP时钟
#define __COMP_CLK_ENABLE         __HAL_RCC_COMP_CLK_ENABLE            // 使能COMP时钟
#define __COMP_FORCE_RESET        __HAL_RCC_COMP_FORCE_RESET           // 强制复位COMP
#define __COMP_RELEASE_RESET      __HAL_RCC_COMP_RELEASE_RESET         // 释放COMP复位
#define __COMP_CLK_SLEEP_ENABLE   __HAL_RCC_COMP_CLK_SLEEP_ENABLE      // 使能COMP休眠时钟
#define __COMP_CLK_SLEEP_DISABLE  __HAL_RCC_COMP_CLK_SLEEP_DISABLE     // 禁用COMP休眠时钟

#define __CEC_FORCE_RESET __HAL_RCC_CEC_FORCE_RESET                    // 强制复位CEC
#define __CEC_RELEASE_RESET __HAL_RCC_CEC_RELEASE_RESET                // 释放CEC复位

/* CRC (循环冗余校验) 计算单元控制 */
#define __CRC_CLK_DISABLE __HAL_RCC_CRC_CLK_DISABLE                    // 禁用CRC时钟
#define __CRC_CLK_ENABLE __HAL_RCC_CRC_CLK_ENABLE                      // 使能CRC时钟
#define __CRC_CLK_SLEEP_DISABLE __HAL_RCC_CRC_CLK_SLEEP_DISABLE        // 禁用CRC休眠时钟
#define __CRC_CLK_SLEEP_ENABLE __HAL_RCC_CRC_CLK_SLEEP_ENABLE          // 使能CRC休眠时钟
#define __CRC_FORCE_RESET __HAL_RCC_CRC_FORCE_RESET                    // 强制复位CRC
#define __CRC_RELEASE_RESET __HAL_RCC_CRC_RELEASE_RESET                // 释放CRC复位

/* DAC (数模转换器) 模块控制 */
#define __DAC_CLK_DISABLE __HAL_RCC_DAC_CLK_DISABLE                    // 禁用DAC时钟
#define __DAC_CLK_ENABLE __HAL_RCC_DAC_CLK_ENABLE                      // 使能DAC时钟
#define __DAC_FORCE_RESET __HAL_RCC_DAC_FORCE_RESET                    // 强制复位DAC
#define __DAC_RELEASE_RESET __HAL_RCC_DAC_RELEASE_RESET                // 释放DAC复位

/* DAC1 外设专用控制 */
#define __DAC1_CLK_DISABLE __HAL_RCC_DAC1_CLK_DISABLE                  // 禁用DAC1时钟
#define __DAC1_CLK_ENABLE __HAL_RCC_DAC1_CLK_ENABLE                    // 使能DAC1时钟
#define __DAC1_CLK_SLEEP_DISABLE __HAL_RCC_DAC1_CLK_SLEEP_DISABLE      // 禁用DAC1休眠时钟
#define __DAC1_CLK_SLEEP_ENABLE __HAL_RCC_DAC1_CLK_SLEEP_ENABLE        // 使能DAC1休眠时钟
#define __DAC1_FORCE_RESET __HAL_RCC_DAC1_FORCE_RESET                  // 强制复位DAC1
#define __DAC1_RELEASE_RESET __HAL_RCC_DAC1_RELEASE_RESET              // 释放DAC1复位

/* DBGMCU (调试接口) 控制 */
#define __DBGMCU_CLK_ENABLE     __HAL_RCC_DBGMCU_CLK_ENABLE            // 使能DBGMCU时钟
#define __DBGMCU_CLK_DISABLE     __HAL_RCC_DBGMCU_CLK_DISABLE          // 禁用DBGMCU时钟
#define __DBGMCU_FORCE_RESET    __HAL_RCC_DBGMCU_FORCE_RESET           // 强制复位DBGMCU
#define __DBGMCU_RELEASE_RESET  __HAL_RCC_DBGMCU_RELEASE_RESET         // 释放DBGMCU复位

/* DFSDM (数字滤波器) 模块控制 */
#define __DFSDM_CLK_DISABLE __HAL_RCC_DFSDM_CLK_DISABLE                // 禁用DFSDM时钟
#define __DFSDM_CLK_ENABLE __HAL_RCC_DFSDM_CLK_ENABLE                  // 使能DFSDM时钟
#define __DFSDM_CLK_SLEEP_DISABLE __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE    // 禁用DFSDM休眠时钟
#define __DFSDM_CLK_SLEEP_ENABLE __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE      // 使能DFSDM休眠时钟
#define __DFSDM_FORCE_RESET __HAL_RCC_DFSDM_FORCE_RESET                // 强制复位DFSDM
#define __DFSDM_RELEASE_RESET __HAL_RCC_DFSDM_RELEASE_RESET            // 释放DFSDM复位

/* DMA1 (直接存储器访问控制器1) 控制 */
#define __DMA1_CLK_DISABLE __HAL_RCC_DMA1_CLK_DISABLE                  // 禁用DMA1时钟
#define __DMA1_CLK_ENABLE __HAL_RCC_DMA1_CLK_ENABLE                    // 使能DMA1时钟
#define __DMA1_CLK_SLEEP_DISABLE __HAL_RCC_DMA1_CLK_SLEEP_DISABLE      // 禁用DMA1休眠时钟
#define __DMA1_CLK_SLEEP_ENABLE __HAL_RCC_DMA1_CLK_SLEEP_ENABLE        // 使能DMA1休眠时钟
#define __DMA1_FORCE_RESET __HAL_RCC_DMA1_FORCE_RESET                  // 强制复位DMA1
#define __DMA1_RELEASE_RESET __HAL_RCC_DMA1_RELEASE_RESET              // 释放DMA1复位

/* DMA2 (直接存储器访问控制器2) 控制 */
#define __DMA2_CLK_DISABLE __HAL_RCC_DMA2_CLK_DISABLE                  // 禁用DMA2时钟
#define __DMA2_CLK_ENABLE __HAL_RCC_DMA2_CLK_ENABLE                    // 使能DMA2时钟
#define __DMA2_CLK_SLEEP_DISABLE __HAL_RCC_DMA2_CLK_SLEEP_DISABLE      // 禁用DMA2休眠时钟
#define __DMA2_CLK_SLEEP_ENABLE __HAL_RCC_DMA2_CLK_SLEEP_ENABLE        // 使能DMA2休眠时钟
#define __DMA2_FORCE_RESET __HAL_RCC_DMA2_FORCE_RESET                  // 强制复位DMA2
#define __DMA2_RELEASE_RESET __HAL_RCC_DMA2_RELEASE_RESET              // 释放DMA2复位

/* ETHMAC (以太网MAC) 模块控制 */
#define __ETHMAC_CLK_DISABLE __HAL_RCC_ETHMAC_CLK_DISABLE              // 禁用以太网MAC时钟
#define __ETHMAC_CLK_ENABLE __HAL_RCC_ETHMAC_CLK_ENABLE                // 使能以太网MAC时钟
#define __ETHMAC_FORCE_RESET __HAL_RCC_ETHMAC_FORCE_RESET              // 强制复位以太网MAC
#define __ETHMAC_RELEASE_RESET __HAL_RCC_ETHMAC_RELEASE_RESET          // 释放以太网MAC复位
#define __ETHMACRX_CLK_DISABLE __HAL_RCC_ETHMACRX_CLK_DISABLE          // 禁用以太网MAC接收时钟
#define __ETHMACRX_CLK_ENABLE __HAL_RCC_ETHMACRX_CLK_ENABLE            // 使能以太网MAC接收时钟
#define __ETHMACTX_CLK_DISABLE __HAL_RCC_ETHMACTX_CLK_DISABLE          // 禁用以太网MAC发送时钟
#define __ETHMACTX_CLK_ENABLE __HAL_RCC_ETHMACTX_CLK_ENABLE            // 使能以太网MAC发送时钟

/* FIREWALL (防火墙) 模块控制 */
#define __FIREWALL_CLK_DISABLE __HAL_RCC_FIREWALL_CLK_DISABLE          // 禁用防火墙时钟
#define __FIREWALL_CLK_ENABLE __HAL_RCC_FIREWALL_CLK_ENABLE            // 使能防火墙时钟

/* FLASH (闪存) 接口控制 */
#define __FLASH_CLK_DISABLE __HAL_RCC_FLASH_CLK_DISABLE                // 禁用FLASH接口时钟
#define __FLASH_CLK_ENABLE __HAL_RCC_FLASH_CLK_ENABLE                  // 使能FLASH接口时钟
#define __FLASH_CLK_SLEEP_DISABLE __HAL_RCC_FLASH_CLK_SLEEP_DISABLE    // 禁用FLASH休眠时钟
#define __FLASH_CLK_SLEEP_ENABLE __HAL_RCC_FLASH_CLK_SLEEP_ENABLE      // 使能FLASH休眠时钟
#define __FLASH_FORCE_RESET __HAL_RCC_FLASH_FORCE_RESET                // 强制复位FLASH接口
#define __FLASH_RELEASE_RESET __HAL_RCC_FLASH_RELEASE_RESET            // 释放FLASH接口复位

/* FLITF (Flash指令预取接口) 控制 */
#define __FLITF_CLK_DISABLE       __HAL_RCC_FLITF_CLK_DISABLE          // 禁用FLITF时钟
#define __FLITF_CLK_ENABLE        __HAL_RCC_FLITF_CLK_ENABLE           // 使能FLITF时钟
#define __FLITF_FORCE_RESET       __HAL_RCC_FLITF_FORCE_RESET          // 强制复位FLITF
#define __FLITF_RELEASE_RESET     __HAL_RCC_FLITF_RELEASE_RESET        // 释放FLITF复位
#define __FLITF_CLK_SLEEP_ENABLE  __HAL_RCC_FLITF_CLK_SLEEP_ENABLE     // 使能FLITF休眠时钟
#define __FLITF_CLK_SLEEP_DISABLE __HAL_RCC_FLITF_CLK_SLEEP_DISABLE    // 禁用FLITF休眠时钟

/* FMC (灵活存储控制器) 控制，用于SDRAM/SRAM等外扩存储器 */
#define __FMC_CLK_DISABLE __HAL_RCC_FMC_CLK_DISABLE                    // 禁用FMC时钟
#define __FMC_CLK_ENABLE __HAL_RCC_FMC_CLK_ENABLE                      // 使能FMC时钟
#define __FMC_CLK_SLEEP_DISABLE __HAL_RCC_FMC_CLK_SLEEP_DISABLE        // 禁用FMC休眠时钟
#define __FMC_CLK_SLEEP_ENABLE __HAL_RCC_FMC_CLK_SLEEP_ENABLE          // 使能FMC休眠时钟
#define __FMC_FORCE_RESET __HAL_RCC_FMC_FORCE_RESET                    // 强制复位FMC
#define __FMC_RELEASE_RESET __HAL_RCC_FMC_RELEASE_RESET                // 释放FMC复位

/* FSMC (灵活静态存储控制器) 控制，用于NOR/NAND等 */
#define __FSMC_CLK_DISABLE __HAL_RCC_FSMC_CLK_DISABLE                  // 禁用FSMC时钟
#define __FSMC_CLK_ENABLE __HAL_RCC_FSMC_CLK_ENABLE                    // 使能FSMC时钟

/* GPIOA 端口控制 */
#define __GPIOA_CLK_DISABLE __HAL_RCC_GPIOA_CLK_DISABLE                // 禁用GPIOA时钟
#define __GPIOA_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE                  // 使能GPIOA时钟
#define __GPIOA_CLK_SLEEP_DISABLE __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE    // 禁用GPIOA休眠时钟
#define __GPIOA_CLK_SLEEP_ENABLE __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE      // 使能GPIOA休眠时钟
#define __GPIOA_FORCE_RESET __HAL_RCC_GPIOA_FORCE_RESET                // 强制复位GPIOA
#define __GPIOA_RELEASE_RESET __HAL_RCC_GPIOA_RELEASE_RESET            // 释放GPIOA复位

/* GPIOB 端口控制 */
#define __GPIOB_CLK_DISABLE __HAL_RCC_GPIOB_CLK_DISABLE                // 禁用GPIOB时钟
#define __GPIOB_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE                  // 使能GPIOB时钟
#define __GPIOB_CLK_SLEEP_DISABLE __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE    // 禁用GPIOB休眠时钟
#define __GPIOB_CLK_SLEEP_ENABLE __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE      // 使能GPIOB休眠时钟
#define __GPIOB_FORCE_RESET __HAL_RCC_GPIOB_FORCE_RESET                // 强制复位GPIOB
#define __GPIOB_RELEASE_RESET __HAL_RCC_GPIOB_RELEASE_RESET            // 释放GPIOB复位

/* GPIOC 端口控制 */
#define __GPIOC_CLK_DISABLE __HAL_RCC_GPIOC_CLK_DISABLE                // 禁用GPIOC时钟
#define __GPIOC_CLK_ENABLE __HAL_RCC_GPIOC_CLK_ENABLE                  // 使能GPIOC时钟
#define __GPIOC_CLK_SLEEP_DISABLE __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE    // 禁用GPIOC休眠时钟
#define __GPIOC_CLK_SLEEP_ENABLE __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE      // 使能GPIOC休眠时钟
#define __GPIOC_FORCE_RESET __HAL_RCC_GPIOC_FORCE_RESET                // 强制复位GPIOC
#define __GPIOC_RELEASE_RESET __HAL_RCC_GPIOC_RELEASE_RESET            // 释放GPIOC复位

/* GPIOD 端口控制 */
#define __GPIOD_CLK_DISABLE __HAL_RCC_GPIOD_CLK_DISABLE                // 禁用GPIOD时钟
#define __GPIOD_CLK_ENABLE __HAL_RCC_GPIOD_CLK_ENABLE                  // 使能GPIOD时钟
#define __GPIOD_CLK_SLEEP_DISABLE __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE    // 禁用GPIOD休眠时钟
#define __GPIOD_CLK_SLEEP_ENABLE __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE      // 使能GPIOD休眠时钟
#define __GPIOD_FORCE_RESET __HAL_RCC_GPIOD_FORCE_RESET                // 强制复位GPIOD
#define __GPIOD_RELEASE_RESET __HAL_RCC_GPIOD_RELEASE_RESET            // 释放GPIOD复位

/* GPIOE 端口控制 */
#define __GPIOE_CLK_DISABLE __HAL_RCC_GPIOE_CLK_DISABLE                // 禁用GPIOE时钟
#define __GPIOE_CLK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE                  // 使能GPIOE时钟
#define __GPIOE_CLK_SLEEP_DISABLE __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE    // 禁用GPIOE休眠时钟
#define __GPIOE_CLK_SLEEP_ENABLE __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE      // 使能GPIOE休眠时钟
#define __GPIOE_FORCE_RESET __HAL_RCC_GPIOE_FORCE_RESET                // 强制复位GPIOE
#define __GPIOE_RELEASE_RESET __HAL_RCC_GPIOE_RELEASE_RESET            // 释放GPIOE复位

/* GPIOF 端口控制 */
#define __GPIOF_CLK_DISABLE __HAL_RCC_GPIOF_CLK_DISABLE                // 禁用GPIOF时钟
#define __GPIOF_CLK_ENABLE __HAL_RCC_GPIOF_CLK_ENABLE                  // 使能GPIOF时钟
#define __GPIOF_CLK_SLEEP_DISABLE __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE    // 禁用GPIOF休眠时钟
#define __GPIOF_CLK_SLEEP_ENABLE __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE      // 使能GPIOF休眠时钟
#define __GPIOF_FORCE_RESET __HAL_RCC_GPIOF_FORCE_RESET                // 强制复位GPIOF
#define __GPIOF_RELEASE_RESET __HAL_RCC_GPIOF_RELEASE_RESET            // 释放GPIOF复位

/* GPIOG 端口控制 */
#define __GPIOG_CLK_DISABLE __HAL_RCC_GPIOG_CLK_DISABLE                // 禁用GPIOG时钟
#define __GPIOG_CLK_ENABLE __HAL_RCC_GPIOG_CLK_ENABLE                  // 使能GPIOG时钟
#define __GPIOG_CLK_SLEEP_DISABLE __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE    // 禁用GPIOG休眠时钟
#define __GPIOG_CLK_SLEEP_ENABLE __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE      // 使能GPIOG休眠时钟
#define __GPIOG_FORCE_RESET __HAL_RCC_GPIOG_FORCE_RESET                // 强制复位GPIOG
#define __GPIOG_RELEASE_RESET __HAL_RCC_GPIOG_RELEASE_RESET            // 释放GPIOG复位

/* GPIOH 端口控制 */
#define __GPIOH_CLK_DISABLE __HAL_RCC_GPIOH_CLK_DISABLE                // 禁用GPIOH时钟
#define __GPIOH_CLK_ENABLE __HAL_RCC_GPIOH_CLK_ENABLE                  // 使能GPIOH时钟
#define __GPIOH_CLK_SLEEP_DISABLE __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE    // 禁用GPIOH休眠时钟
#define __GPIOH_CLK_SLEEP_ENABLE __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE      // 使能GPIOH休眠时钟
#define __GPIOH_FORCE_RESET __HAL_RCC_GPIOH_FORCE_RESET                // 强制复位GPIOH
#define __GPIOH_RELEASE_RESET __HAL_RCC_GPIOH_RELEASE_RESET            // 释放GPIOH复位

/* I2C1 (I2C总线接口1) 控制 */
#define __I2C1_CLK_DISABLE __HAL_RCC_I2C1_CLK_DISABLE                  // 禁用I2C1时钟
#define __I2C1_CLK_ENABLE __HAL_RCC_I2C1_CLK_ENABLE                    // 使能I2C1时钟
#define __I2C1_CLK_SLEEP_DISABLE __HAL_RCC_I2C1_CLK_SLEEP_DISABLE      // 禁用I2C1休眠时钟
#define __I2C1_CLK_SLEEP_ENABLE __HAL_RCC_I2C1_CLK_SLEEP_ENABLE        // 使能I2C1休眠时钟
#define __I2C1_FORCE_RESET __HAL_RCC_I2C1_FORCE_RESET                  // 强制复位I2C1
#define __I2C1_RELEASE_RESET __HAL_RCC_I2C1_RELEASE_RESET              // 释放I2C1复位

/* I2C2 (I2C总线接口2) 控制 */
#define __I2C2_CLK_DISABLE __HAL_RCC_I2C2_CLK_DISABLE                  // 禁用I2C2时钟
#define __I2C2_CLK_ENABLE __HAL_RCC_I2C2_CLK_ENABLE                    // 使能I2C2时钟
#define __I2C2_CLK_SLEEP_DISABLE __HAL_RCC_I2C2_CLK_SLEEP_DISABLE      // 禁用I2C2休眠时钟
#define __I2C2_CLK_SLEEP_ENABLE __HAL_RCC_I2C2_CLK_SLEEP_ENABLE        // 使能I2C2休眠时钟
#define __I2C2_FORCE_RESET __HAL_RCC_I2C2_FORCE_RESET                  // 强制复位I2C2
#define __I2C2_RELEASE_RESET __HAL_RCC_I2C2_RELEASE_RESET              // 释放I2C2复位

/* I2C3 (I2C总线接口3) 控制 */
#define __I2C3_CLK_DISABLE __HAL_RCC_I2C3_CLK_DISABLE                  // 禁用I2C3时钟
#define __I2C3_CLK_ENABLE __HAL_RCC_I2C3_CLK_ENABLE                    // 使能I2C3时钟
#define __I2C3_CLK_SLEEP_DISABLE __HAL_RCC_I2C3_CLK_SLEEP_DISABLE      // 禁用I2C3休眠时钟
#define __I2C3_CLK_SLEEP_ENABLE __HAL_RCC_I2C3_CLK_SLEEP_ENABLE        // 使能I2C3休眠时钟
#define __I2C3_FORCE_RESET __HAL_RCC_I2C3_FORCE_RESET                  // 强制复位I2C3
#define __I2C3_RELEASE_RESET __HAL_RCC_I2C3_RELEASE_RESET              // 释放I2C3复位

/* LCD (液晶显示控制器) 控制 */
#define __LCD_CLK_DISABLE __HAL_RCC_LCD_CLK_DISABLE                    // 禁用LCD时钟
#define __LCD_CLK_ENABLE __HAL_RCC_LCD_CLK_ENABLE                      // 使能LCD时钟
#define __LCD_CLK_SLEEP_DISABLE __HAL_RCC_LCD_CLK_SLEEP_DISABLE        // 禁用LCD休眠时钟
#define __LCD_CLK_SLEEP_ENABLE __HAL_RCC_LCD_CLK_SLEEP_ENABLE          // 使能LCD休眠时钟
#define __LCD_FORCE_RESET __HAL_RCC_LCD_FORCE_RESET                    // 强制复位LCD
#define __LCD_RELEASE_RESET __HAL_RCC_LCD_RELEASE_RESET                // 释放LCD复位

/* LPTIM1 (低功耗定时器1) 控制 */
#define __LPTIM1_CLK_DISABLE __HAL_RCC_LPTIM1_CLK_DISABLE              // 禁用LPTIM1时钟
#define __LPTIM1_CLK_ENABLE __HAL_RCC_LPTIM1_CLK_ENABLE                // 使能LPTIM1时钟
#define __LPTIM1_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE  // 禁用LPTIM1休眠时钟
#define __LPTIM1_CLK_SLEEP_ENABLE __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE    // 使能LPTIM1休眠时钟
#define __LPTIM1_FORCE_RESET __HAL_RCC_LPTIM1_FORCE_RESET              // 强制复位LPTIM1
#define __LPTIM1_RELEASE_RESET __HAL_RCC_LPTIM1_RELEASE_RESET          // 释放LPTIM1复位

/* LPTIM2 (低功耗定时器2) 控制 */
#define __LPTIM2_CLK_DISABLE __HAL_RCC_LPTIM2_CLK_DISABLE              // 禁用LPTIM2时钟
#define __LPTIM2_CLK_ENABLE __HAL_RCC_LPTIM2_CLK_ENABLE                // 使能LPTIM2时钟
#define __LPTIM2_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE  // 禁用LPTIM2休眠时钟
#define __LPTIM2_CLK_SLEEP_ENABLE __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE    // 使能LPTIM2休眠时钟
#define __LPTIM2_FORCE_RESET __HAL_RCC_LPTIM2_FORCE_RESET              // 强制复位LPTIM2
#define __LPTIM2_RELEASE_RESET __HAL_RCC_LPTIM2_RELEASE_RESET          // 释放LPTIM2复位

/* LPUART1 (低功耗通用异步收发器1) 控制 */
#define __LPUART1_CLK_DISABLE __HAL_RCC_LPUART1_CLK_DISABLE            // 禁用LPUART1时钟
#define __LPUART1_CLK_ENABLE __HAL_RCC_LPUART1_CLK_ENABLE              // 使能LPUART1时钟
#define __LPUART1_CLK_SLEEP_DISABLE __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE // 禁用LPUART1休眠时钟
#define __LPUART1_CLK_SLEEP_ENABLE __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE  // 使能LPUART1休眠时钟
#define __LPUART1_FORCE_RESET __HAL_RCC_LPUART1_FORCE_RESET            // 强制复位LPUART1
#define __LPUART1_RELEASE_RESET __HAL_RCC_LPUART1_RELEASE_RESET        // 释放LPUART1复位

/* OPAMP (运算放大器) 控制 */
#define __OPAMP_CLK_DISABLE __HAL_RCC_OPAMP_CLK_DISABLE                // 禁用OPAMP时钟
#define __OPAMP_CLK_ENABLE __HAL_RCC_OPAMP_CLK_ENABLE                  // 使能OPAMP时钟
#define __OPAMP_CLK_SLEEP_DISABLE __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE    // 禁用OPAMP休眠时钟
#define __OPAMP_CLK_SLEEP_ENABLE __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE      // 使能OPAMP休眠时钟
#define __OPAMP_FORCE_RESET __HAL_RCC_OPAMP_FORCE_RESET                // 强制复位OPAMP
#define __OPAMP_RELEASE_RESET __HAL_RCC_OPAMP_RELEASE_RESET            // 释放OPAMP复位

/* OTGFS (USB On-The-Go Full Speed) 控制 */
#define __OTGFS_CLK_DISABLE __HAL_RCC_OTGFS_CLK_DISABLE                // 禁用OTGFS时钟
#define __OTGFS_CLK_ENABLE __HAL_RCC_OTGFS_CLK_ENABLE                  // 使能OTGFS时钟
#define __OTGFS_CLK_SLEEP_DISABLE __HAL_RCC_OTGFS_CLK_SLEEP_DISABLE    // 禁用OTGFS休眠时钟
#define __OTGFS_CLK_SLEEP_ENABLE __HAL_RCC_OTGFS_CLK_SLEEP_ENABLE      // 使能OTGFS休眠时钟
#define __OTGFS_FORCE_RESET __HAL_RCC_OTGFS_FORCE_RESET                // 强制复位OTGFS
#define __OTGFS_RELEASE_RESET __HAL_RCC_OTGFS_RELEASE_RESET            // 释放OTGFS复位

/* PWR (电源控制) 模块控制 */
#define __PWR_CLK_DISABLE __HAL_RCC_PWR_CLK_DISABLE                    // 禁用PWR时钟
#define __PWR_CLK_ENABLE __HAL_RCC_PWR_CLK_ENABLE                      // 使能PWR时钟
#define __PWR_CLK_SLEEP_DISABLE __HAL_RCC_PWR_CLK_SLEEP_DISABLE        // 禁用PWR休眠时钟
#define __PWR_CLK_SLEEP_ENABLE __HAL_RCC_PWR_CLK_SLEEP_ENABLE          // 使能PWR休眠时钟
#define __PWR_FORCE_RESET __HAL_RCC_PWR_FORCE_RESET                    // 强制复位PWR
#define __PWR_RELEASE_RESET __HAL_RCC_PWR_RELEASE_RESET                // 释放PWR复位

/* QSPI (四线SPI接口) 控制，常用于连接外部Flash */
#define __QSPI_CLK_DISABLE __HAL_RCC_QSPI_CLK_DISABLE                  // 禁用QSPI时钟
#define __QSPI_CLK_ENABLE __HAL_RCC_QSPI_CLK_ENABLE                    // 使能QSPI时钟
#define __QSPI_CLK_SLEEP_DISABLE __HAL_RCC_QSPI_CLK_SLEEP_DISABLE      // 禁用QSPI休眠时钟
#define __QSPI_CLK_SLEEP_ENABLE __HAL_RCC_QSPI_CLK_SLEEP_ENABLE        // 使能QSPI休眠时钟
#define __QSPI_FORCE_RESET __HAL_RCC_QSPI_FORCE_RESET                  // 强制复位QSPI
#define __QSPI_RELEASE_RESET __HAL_RCC_QSPI_RELEASE_RESET              // 释放QSPI复位

/* STM32WB系列特殊定义：QSPI与QUADSPI兼容性映射 */
#if defined(STM32WB)
#define __HAL_RCC_QSPI_CLK_DISABLE            __HAL_RCC_QUADSPI_CLK_DISABLE       // 禁用QUADSPI时钟
#define __HAL_RCC_QSPI_CLK_ENABLE             __HAL_RCC_QUADSPI_CLK_ENABLE        // 使能QUADSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_DISABLE      __HAL_RCC_QUADSPI_CLK_SLEEP_DISABLE // 禁用QUADSPI休眠时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_ENABLE       __HAL_RCC_QUADSPI_CLK_SLEEP_ENABLE  // 使能QUADSPI休眠时钟
#define __HAL_RCC_QSPI_FORCE_RESET            __HAL_RCC_QUADSPI_FORCE_RESET       // 强制复位QUADSPI
#define __HAL_RCC_QSPI_RELEASE_RESET          __HAL_RCC_QUADSPI_RELEASE_RESET     // 释放QUADSPI复位
#define __HAL_RCC_QSPI_IS_CLK_ENABLED         __HAL_RCC_QUADSPI_IS_CLK_ENABLED    // 检查QUADSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_DISABLED        __HAL_RCC_QUADSPI_IS_CLK_DISABLED   // 检查QUADSPI时钟是否禁用
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_ENABLED   __HAL_RCC_QUADSPI_IS_CLK_SLEEP_ENABLED  // 检查QUADSPI休眠时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_DISABLED  __HAL_RCC_QUADSPI_IS_CLK_SLEEP_DISABLED // 检查QUADSPI休眠时钟是否禁用
#define QSPI_IRQHandler QUADSPI_IRQHandler    // 中断服务函数别名映射
#endif /* __HAL_RCC_QUADSPI_CLK_ENABLE */
