#if defined(STM32H7)  // 如果定义了 STM32H7 系列芯片
#define __HAL_RCC_JPEG_CLK_ENABLE               __HAL_RCC_JPGDECEN_CLK_ENABLE  // 使能 JPEG 硬件时钟
#define __HAL_RCC_JPEG_CLK_DISABLE              __HAL_RCC_JPGDECEN_CLK_DISABLE  // 禁用 JPEG 硬件时钟
#define __HAL_RCC_JPEG_FORCE_RESET              __HAL_RCC_JPGDECRST_FORCE_RESET  // 强制复位 JPEG 模块
#define __HAL_RCC_JPEG_RELEASE_RESET            __HAL_RCC_JPGDECRST_RELEASE_RESET  // 释放 JPEG 模块复位
#define __HAL_RCC_JPEG_CLK_SLEEP_ENABLE         __HAL_RCC_JPGDEC_CLK_SLEEP_ENABLE  // 使能 JPEG 睡眠模式时钟
#define __HAL_RCC_JPEG_CLK_SLEEP_DISABLE        __HAL_RCC_JPGDEC_CLK_SLEEP_DISABLE  // 禁用 JPEG 睡眠模式时钟
#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_SYSCFG_Aliased_Defines HAL SYSCFG Aliased Defines maintained for legacy purpose
  * @{
  */
// HAL SYSCFG 别名定义，为保持向后兼容性而维护

#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA9    I2C_FASTMODEPLUS_PA9  // I2C 快速模式增强 PA9 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA10   I2C_FASTMODEPLUS_PA10  // I2C 快速模式增强 PA10 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB6    I2C_FASTMODEPLUS_PB6  // I2C 快速模式增强 PB6 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB7    I2C_FASTMODEPLUS_PB7  // I2C 快速模式增强 PB7 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB8    I2C_FASTMODEPLUS_PB8  // I2C 快速模式增强 PB8 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB9    I2C_FASTMODEPLUS_PB9  // I2C 快速模式增强 PB9 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C1       I2C_FASTMODEPLUS_I2C1  // I2C1 快速模式增强
#define HAL_SYSCFG_FASTMODEPLUS_I2C2       I2C_FASTMODEPLUS_I2C2  // I2C2 快速模式增强
#define HAL_SYSCFG_FASTMODEPLUS_I2C3       I2C_FASTMODEPLUS_I2C3  // I2C3 快速模式增强
#if defined(STM32G4)  // 如果定义了 STM32G4 系列芯片

#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SYSCFG_EnableIOSwitchBooster  // 启用 IO 模拟开关升压器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SYSCFG_DisableIOSwitchBooster  // 禁用 IO 模拟开关升压器
#define HAL_SYSCFG_EnableIOAnalogSwitchVDD        HAL_SYSCFG_EnableIOSwitchVDD  // 启用 IO 模拟开关 VDD
#define HAL_SYSCFG_DisableIOAnalogSwitchVDD       HAL_SYSCFG_DisableIOSwitchVDD  // 禁用 IO 模拟开关 VDD
#endif /* STM32G4 */

#if defined(STM32H5)  // 如果定义了 STM32H5 系列芯片
// 以下为 SYSCFG 中断定义别名
#define SYSCFG_IT_FPU_IOC         SBS_IT_FPU_IOC  // FPU 输入溢出中断
#define SYSCFG_IT_FPU_DZC         SBS_IT_FPU_DZC  // FPU 除零中断
#define SYSCFG_IT_FPU_UFC         SBS_IT_FPU_UFC  // FPU 下溢中断
#define SYSCFG_IT_FPU_OFC         SBS_IT_FPU_OFC  // FPU 上溢中断
#define SYSCFG_IT_FPU_IDC         SBS_IT_FPU_IDC  // FPU 输入反规范化中断
#define SYSCFG_IT_FPU_IXC         SBS_IT_FPU_IXC  // FPU 不精确中断

// 以下为 SYSCFG 断点配置别名
#define SYSCFG_BREAK_FLASH_ECC    SBS_BREAK_FLASH_ECC  // Flash ECC 错误断点
#define SYSCFG_BREAK_PVD          SBS_BREAK_PVD  // PVD 断点
#define SYSCFG_BREAK_SRAM_ECC     SBS_BREAK_SRAM_ECC  // SRAM ECC 错误断点
#define SYSCFG_BREAK_LOCKUP       SBS_BREAK_LOCKUP  // 锁定断点

// VREFBUF 电压等级定义别名
#define SYSCFG_VREFBUF_VOLTAGE_SCALE0   VREFBUF_VOLTAGE_SCALE0  // VREFBUF 电压等级0
#define SYSCFG_VREFBUF_VOLTAGE_SCALE1   VREFBUF_VOLTAGE_SCALE1  // VREFBUF 电压等级1
#define SYSCFG_VREFBUF_VOLTAGE_SCALE2   VREFBUF_VOLTAGE_SCALE2  // VREFBUF 电压等级2
#define SYSCFG_VREFBUF_VOLTAGE_SCALE3   VREFBUF_VOLTAGE_SCALE3  // VREFBUF 电压等级3

// VREFBUF 高阻抗配置别名
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE   VREFBUF_HIGH_IMPEDANCE_DISABLE  // 禁用 VREFBUF 高阻抗模式
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE    VREFBUF_HIGH_IMPEDANCE_ENABLE  // 启用 VREFBUF 高阻抗模式

// 快速模式增强引脚配置别名
#define SYSCFG_FASTMODEPLUS_PB6   SBS_FASTMODEPLUS_PB6  // PB6 快速模式增强
#define SYSCFG_FASTMODEPLUS_PB7   SBS_FASTMODEPLUS_PB7  // PB7 快速模式增强
#define SYSCFG_FASTMODEPLUS_PB8   SBS_FASTMODEPLUS_PB8  // PB8 快速模式增强
#define SYSCFG_FASTMODEPLUS_PB9   SBS_FASTMODEPLUS_PB9  // PB9 快速模式增强

// 以太网接口配置别名
#define SYSCFG_ETH_MII   SBS_ETH_MII  // 以太网 MII 接口
#define SYSCFG_ETH_RMII  SBS_ETH_RMII  // 以太网 RMII 接口
#define IS_SYSCFG_ETHERNET_CONFIG  IS_SBS_ETHERNET_CONFIG  // 检查以太网配置是否有效

// 存储器擦除标志别名
#define SYSCFG_MEMORIES_ERASE_FLAG_IPMEE   SBS_MEMORIES_ERASE_FLAG_IPMEE  // IPMEE 存储器擦除标志
#define SYSCFG_MEMORIES_ERASE_FLAG_MCLR    SBS_MEMORIES_ERASE_FLAG_MCLR  // MCLR 存储器擦除标志
#define IS_SYSCFG_MEMORIES_ERASE_FLAG      IS_SBS_MEMORIES_ERASE_FLAG  // 检查存储器擦除标志是否有效

// 代码配置检查别名
#define IS_SYSCFG_CODE_CONFIG IS_SBS_CODE_CONFIG  // 检查代码配置是否有效

// 安全配置别名
#define SYSCFG_MPU_NSEC   SBS_MPU_NSEC  // 非安全 MPU
#define SYSCFG_VTOR_NSEC  SBS_VTOR_NSEC  // 非安全 VTOR
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)  // 如果支持 CMSE（安全扩展）
#define SYSCFG_SAU              SBS_SAU  // SAU（安全属性单元）
#define SYSCFG_MPU_SEC          SBS_MPU_SEC  // 安全 MPU
#define SYSCFG_VTOR_AIRCR_SEC   SBS_VTOR_AIRCR_SEC  // 安全 VTOR 和 AIRCR
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL  // 锁定所有配置
#else
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL  // 锁定所有配置
#endif /* __ARM_FEATURE_CMSE */

// 时钟和模块配置别名
#define SYSCFG_CLK      SBS_CLK  // 时钟配置
#define SYSCFG_CLASSB   SBS_CLASSB  // CLASSB 配置
#define SYSCFG_FPU      SBS_FPU  // FPU 配置
#define SYSCFG_ALL      SBS_ALL  // 所有配置

// 安全和飞安全配置别名
#define SYSCFG_SEC      SBS_SEC  // 安全配置
#define SYSCFG_NSEC     SBS_NSEC  // 非安全配置

// HAL 宏别名：FPU 中断使能/禁用
#define __HAL_SYSCFG_FPU_INTERRUPT_ENABLE   __HAL_SBS_FPU_INTERRUPT_ENABLE  // 使能 FPU 中断
#define __HAL_SYSCFG_FPU_INTERRUPT_DISABLE  __HAL_SBS_FPU_INTERRUPT_DISABLE  // 禁用 FPU 中断

// HAL 宏别名：断点锁定配置
#define __HAL_SYSCFG_BREAK_ECC_LOCK        __HAL_SBS_BREAK_ECC_LOCK  // 锁定 ECC 断点
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK     __HAL_SBS_BREAK_LOCKUP_LOCK  // 锁定锁定断点
#define __HAL_SYSCFG_BREAK_PVD_LOCK        __HAL_SBS_BREAK_PVD_LOCK  // 锁定 PVD 断点
#define __HAL_SYSCFG_BREAK_SRAM_ECC_LOCK   __HAL_SBS_BREAK_SRAM_ECC_LOCK  // 锁定 SRAM ECC 断点

// HAL 宏别名：快速模式增强使能/禁用
#define __HAL_SYSCFG_FASTMODEPLUS_ENABLE   __HAL_SBS_FASTMODEPLUS_ENABLE  // 使能快速模式增强
#define __HAL_SYSCFG_FASTMODEPLUS_DISABLE  __HAL_SBS_FASTMODEPLUS_DISABLE  // 禁用快速模式增强

// HAL 宏别名：获取和清除存储器擦除状态
#define __HAL_SYSCFG_GET_MEMORIES_ERASE_STATUS    __HAL_SBS_GET_MEMORIES_ERASE_STATUS  // 获取存储器擦除状态
#define __HAL_SYSCFG_CLEAR_MEMORIES_ERASE_STATUS  __HAL_SBS_CLEAR_MEMORIES_ERASE_STATUS  // 清除存储器擦除状态

// 有效性检查宏别名
#define IS_SYSCFG_FPU_INTERRUPT    IS_SBS_FPU_INTERRUPT  // 检查 FPU 中断配置是否有效
#define IS_SYSCFG_BREAK_CONFIG     IS_SBS_BREAK_CONFIG  // 检查断点配置是否有效
#define IS_SYSCFG_VREFBUF_VOLTAGE_SCALE     IS_VREFBUF_VOLTAGE_SCALE  // 检查 VREFBUF 电压等级是否有效
#define IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE    IS_VREFBUF_HIGH_IMPEDANCE  // 检查 VREFBUF 高阻抗模式是否有效
#define IS_SYSCFG_VREFBUF_TRIMMING  IS_VREFBUF_TRIMMING  // 检查 VREFBUF 微调是否有效
#define IS_SYSCFG_FASTMODEPLUS      IS_SBS_FASTMODEPLUS  // 检查快速模式增强配置是否有效
#define IS_SYSCFG_ITEMS_ATTRIBUTES  IS_SBS_ITEMS_ATTRIBUTES  // 检查项目属性是否有效
#define IS_SYSCFG_ATTRIBUTES        IS_SBS_ATTRIBUTES  // 检查属性是否有效
#define IS_SYSCFG_LOCK_ITEMS        IS_SBS_LOCK_ITEMS  // 检查锁定项目是否有效

// HAL 函数别名：VREFBUF 配置
#define HAL_SYSCFG_VREFBUF_VoltageScalingConfig   HAL_VREFBUF_VoltageScalingConfig  // 配置 VREFBUF 电压等级
#define HAL_SYSCFG_VREFBUF_HighImpedanceConfig    HAL_VREFBUF_HighImpedanceConfig  // 配置 VREFBUF 高阻抗模式
#define HAL_SYSCFG_VREFBUF_TrimmingConfig         HAL_VREFBUF_TrimmingConfig  // 配置 VREFBUF 微调
#define HAL_SYSCFG_EnableVREFBUF                  HAL_EnableVREFBUF  // 使能 VREFBUF
#define HAL_SYSCFG_DisableVREFBUF                 HAL_DisableVREFBUF  // 禁用 VREFBUF

// HAL 函数别名：IO 模拟开关和以太网接口选择
#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SBS_EnableIOAnalogSwitchBooster  // 使能 IO 模拟开关升压器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SBS_DisableIOAnalogSwitchBooster  // 禁用 IO 模拟开关升压器
#define HAL_SYSCFG_ETHInterfaceSelect             HAL_SBS_ETHInterfaceSelect  // 选择以太网接口

// HAL 函数别名：锁定配置
#define HAL_SYSCFG_Lock     HAL_SBS_Lock  // 锁定配置
#define HAL_SYSCFG_GetLock  HAL_SBS_GetLock  // 获取锁定状态

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)  // 如果支持 CMSE（安全扩展）
#define HAL_SYSCFG_ConfigAttributes     HAL_SBS_ConfigAttributes  // 配置属性
#define HAL_SYSCFG_GetConfigAttributes  HAL_SBS_GetConfigAttributes  // 获取配置属性
#endif /* __ARM_FEATURE_CMSE */

#endif /* STM32H5 */


/**
  * @}
  */


/** @defgroup LL_FMC_Aliased_Defines LL FMC Aliased Defines maintained for compatibility purpose
  * @{
  */
// LL FMC 别名定义，为保持兼容性而维护
#if defined(STM32L4) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)  // 如果定义了这些系列芯片
#define FMC_NAND_PCC_WAIT_FEATURE_DISABLE       FMC_NAND_WAIT_FEATURE_DISABLE  // 禁用 NAND PCC 等待功能
#define FMC_NAND_PCC_WAIT_FEATURE_ENABLE        FMC_NAND_WAIT_FEATURE_ENABLE  // 使能 NAND PCC 等待功能
#define FMC_NAND_PCC_MEM_BUS_WIDTH_8            FMC_NAND_MEM_BUS_WIDTH_8  // NAND 存储器总线宽度为 8 位
#define FMC_NAND_PCC_MEM_BUS_WIDTH_16           FMC_NAND_MEM_BUS_WIDTH_16  // NAND 存储器总线宽度为 16 位
#elif defined(STM32F1) || defined(STM32F2) || defined(STM32F3) || defined(STM32F4)  // 如果定义了这些系列芯片
#define FMC_NAND_WAIT_FEATURE_DISABLE           FMC_NAND_PCC_WAIT_FEATURE_DISABLE  // 禁用 NAND 等待功能
#define FMC_NAND_WAIT_FEATURE_ENABLE            FMC_NAND_PCC_WAIT_FEATURE_ENABLE  // 使能 NAND 等待功能
#define FMC_NAND_MEM_BUS_WIDTH_8                FMC_NAND_PCC_MEM_BUS_WIDTH_8  // NAND 存储器总线宽度为 8 位
#define FMC_NAND_MEM_BUS_WIDTH_16               FMC_NAND_PCC_MEM_BUS_WIDTH_16  // NAND 存储器总线宽度为 16 位
#endif
/**
  * @}
  */

/** @defgroup LL_FSMC_Aliased_Defines LL FSMC Aliased Defines maintained for legacy purpose
  * @{
  */
// LL FSMC 别名定义，为保持向后兼容性而维护

#define FSMC_NORSRAM_TYPEDEF                      FSMC_NORSRAM_TypeDef  // FSMC NOR/SRAM 类型定义别名
#define FSMC_NORSRAM_EXTENDED_TYPEDEF             FSMC_NORSRAM_EXTENDED_TypeDef  // FSMC NOR/SRAM 扩展类型定义别名
/**
  * @}
  */

/** @defgroup HAL_GPIO_Aliased_Macros HAL GPIO Aliased Macros maintained for legacy purpose
  * @{
  */
// HAL GPIO 别名宏定义，为保持向后兼容性而维护
#define GET_GPIO_SOURCE                           GPIO_GET_INDEX  // 获取 GPIO 源（索引）
#define GET_GPIO_INDEX                            GPIO_GET_INDEX  // 获取 GPIO 索引

#if defined(STM32F4)  // 如果定义了 STM32F4 系列芯片
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDIO  // 复用功能 12: SDMMC (SDIO)
#define GPIO_AF12_SDMMC1                          GPIO_AF12_SDIO  // 复用功能 12: SDMMC1 (SDIO)
#endif

#if defined(STM32F7)  // 如果定义了 STM32F7 系列芯片
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1  // 复用功能 12: SDIO (SDMMC1)
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1  // 复用功能 12: SDMMC (SDMMC1)
#endif

#if defined(STM32L4)  // 如果定义了 STM32L4 系列芯片
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1  // 复用功能 12: SDIO (SDMMC1)
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1  // 复用功能 12: SDMMC (SDMMC1)
#endif

#if defined(STM32H7)  // 如果定义了 STM32H7 系列芯片
#define GPIO_AF7_SDIO1                            GPIO_AF7_SDMMC1  // 复用功能 7: SDIO1 (SDMMC1)
#define GPIO_AF8_SDIO1                            GPIO_AF8_SDMMC1  // 复用功能 8: SDIO1 (SDMMC1)
#define GPIO_AF12_SDIO1                           GPIO_AF12_SDMMC1  // 复用功能 12: SDIO1 (SDMMC1)
#define GPIO_AF9_SDIO2                            GPIO_AF9_SDMMC2  // 复用功能 9: SDIO2 (SDMMC2)
#define GPIO_AF10_SDIO2                           GPIO_AF10_SDMMC2  // 复用功能 10: SDIO2 (SDMMC2)
#define GPIO_AF11_SDIO2                           GPIO_AF11_SDMMC2  // 复用功能 11: SDIO2 (SDMMC2)

#if defined (STM32H743xx) || defined (STM32H753xx)  || defined (STM32H750xx) || defined (STM32H742xx) || \
    defined (STM32H745xx) || defined (STM32H755xx)  || defined (STM32H747xx) || defined (STM32H757xx)
#define GPIO_AF10_OTG2_HS  GPIO_AF10_OTG2_FS  // 复用功能 10: OTG2_HS (OTG2_FS)
#define GPIO_AF10_OTG1_FS  GPIO_AF10_OTG1_HS  // 复用功能 10: OTG1_FS (OTG1_HS)
#define GPIO_AF12_OTG2_FS  GPIO_AF12_OTG1_FS  // 复用功能 12: OTG2_FS (OTG1_FS)
#endif /*STM32H743xx || STM32H753xx || STM32H750xx || STM32H742xx || STM32H745xx || STM32H755xx || STM32H747xx || \
         STM32H757xx */
#endif /* STM32H7 */

// LPTIM 复用功能别名
#define GPIO_AF0_LPTIM                            GPIO_AF0_LPTIM1  // 复用功能 0: LPTIM (LPTIM1)
#define GPIO_AF1_LPTIM                            GPIO_AF1_LPTIM1  // 复用功能 1: LPTIM (LPTIM1)
#define GPIO_AF2_LPTIM                            GPIO_AF2_LPTIM1  // 复用功能 2: LPTIM (LPTIM1)

// GPIO 速度别名定义
#if defined(STM32L0) || defined(STM32L4) || defined(STM32F4) || defined(STM32F2) || defined(STM32F7) || \
    defined(STM32G4) || defined(STM32H7) || defined(STM32WB) || defined(STM32U5)
#define  GPIO_SPEED_LOW                           GPIO_SPEED_FREQ_LOW  // 低速
#define  GPIO_SPEED_MEDIUM                        GPIO_SPEED_FREQ_MEDIUM  // 中速
#define  GPIO_SPEED_FAST                          GPIO_SPEED_FREQ_HIGH  // 快速
#define  GPIO_SPEED_HIGH                          GPIO_SPEED_FREQ_VERY_HIGH  // 高速
#endif /* STM32L0 || STM32L4 || STM32F4 || STM32F2 || STM32F7 || STM32G4 || STM32H7 || STM32WB || STM32U5*/

#if defined(STM32L1)  // 如果定义了 STM32L1 系列芯片
#define  GPIO_SPEED_VERY_LOW    GPIO_SPEED_FREQ_LOW  // 非常低速
#define  GPIO_SPEED_LOW         GPIO_SPEED_FREQ_MEDIUM  // 低速
#define  GPIO_SPEED_MEDIUM      GPIO_SPEED_FREQ_HIGH  // 中速
#define  GPIO_SPEED_HIGH        GPIO_SPEED_FREQ_VERY_HIGH  // 高速
#endif /* STM32L1 */