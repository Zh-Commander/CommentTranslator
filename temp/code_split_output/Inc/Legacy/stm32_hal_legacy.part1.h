/* DMAMUX2 请求发生器事件定义，用于DMA请求多路复用 */
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH0_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH0_EVT   // DMAMUX2 通道0事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH1_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH1_EVT   // DMAMUX2 通道1事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH2_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH2_EVT   // DMAMUX2 通道2事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH3_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH3_EVT   // DMAMUX2 通道3事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH4_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH4_EVT   // DMAMUX2 通道4事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH5_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH5_EVT   // DMAMUX2 通道5事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH6_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH6_EVT   // DMAMUX2 通道6事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_RX_WKUP    HAL_DMAMUX2_REQ_GEN_LPUART1_RX_WKUP   // LPUART1 接收唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_TX_WKUP    HAL_DMAMUX2_REQ_GEN_LPUART1_TX_WKUP   // LPUART1 发送唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM2_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM2_WKUP       // LPTIM2 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM2_OUT         HAL_DMAMUX2_REQ_GEN_LPTIM2_OUT        // LPTIM2 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM3_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM3_WKUP       // LPTIM3 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM3_OUT         HAL_DMAMUX2_REQ_GEN_LPTIM3_OUT        // LPTIM3 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM4_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM4_WKUP       // LPTIM4 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM5_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM5_WKUP       // LPTIM5 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_I2C4_WKUP          HAL_DMAMUX2_REQ_GEN_I2C4_WKUP         // I2C4 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_SPI6_WKUP          HAL_DMAMUX2_REQ_GEN_SPI6_WKUP         // SPI6 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_COMP1_OUT          HAL_DMAMUX2_REQ_GEN_COMP1_OUT         // 比较器1 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_COMP2_OUT          HAL_DMAMUX2_REQ_GEN_COMP2_OUT         // 比较器2 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_RTC_WKUP           HAL_DMAMUX2_REQ_GEN_RTC_WKUP          // RTC 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_EXTI0              HAL_DMAMUX2_REQ_GEN_EXTI0             // 外部中断线0 事件
#define HAL_DMAMUX2_REQUEST_GEN_EXTI2              HAL_DMAMUX2_REQ_GEN_EXTI2             // 外部中断线2 事件
#define HAL_DMAMUX2_REQUEST_GEN_I2C4_IT_EVT        HAL_DMAMUX2_REQ_GEN_I2C4_IT_EVT       // I2C4 中断/事件
#define HAL_DMAMUX2_REQUEST_GEN_SPI6_IT            HAL_DMAMUX2_REQ_GEN_SPI6_IT           // SPI6 中断事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_TX_IT      HAL_DMAMUX2_REQ_GEN_LPUART1_TX_IT     // LPUART1 发送中断事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_RX_IT      HAL_DMAMUX2_REQ_GEN_LPUART1_RX_IT     // LPUART1 接收中断事件
#define HAL_DMAMUX2_REQUEST_GEN_ADC3_IT            HAL_DMAMUX2_REQ_GEN_ADC3_IT           // ADC3 中断事件
#define HAL_DMAMUX2_REQUEST_GEN_ADC3_AWD1_OUT      HAL_DMAMUX2_REQ_GEN_ADC3_AWD1_OUT     // ADC3 模拟看门狗1 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_BDMA_CH0_IT        HAL_DMAMUX2_REQ_GEN_BDMA_CH0_IT       // BDMA 通道0 中断事件
#define HAL_DMAMUX2_REQUEST_GEN_BDMA_CH1_IT        HAL_DMAMUX2_REQ_GEN_BDMA_CH1_IT       // BDMA 通道1 中断事件

/* DMAMUX 请求发生器触发极性定义 */
#define HAL_DMAMUX_REQUEST_GEN_NO_EVENT            HAL_DMAMUX_REQ_GEN_NO_EVENT           // 无事件触发
#define HAL_DMAMUX_REQUEST_GEN_RISING              HAL_DMAMUX_REQ_GEN_RISING             // 上升沿触发
#define HAL_DMAMUX_REQUEST_GEN_FALLING             HAL_DMAMUX_REQ_GEN_FALLING            // 下降沿触发
#define HAL_DMAMUX_REQUEST_GEN_RISING_FALLING      HAL_DMAMUX_REQ_GEN_RISING_FALLING     // 双沿触发(上升沿和下降沿)

/* DFSDM 滤波器外部触发源定义 */
#define DFSDM_FILTER_EXT_TRIG_LPTIM1               DFSDM_FILTER_EXT_TRIG_LPTIM1_OUT      // LPTIM1 输出作为DFSDM外部触发
#define DFSDM_FILTER_EXT_TRIG_LPTIM2               DFSDM_FILTER_EXT_TRIG_LPTIM2_OUT      // LPTIM2 输出作为DFSDM外部触发
#define DFSDM_FILTER_EXT_TRIG_LPTIM3               DFSDM_FILTER_EXT_TRIG_LPTIM3_OUT      // LPTIM3 输出作为DFSDM外部触发

/* DAC 触发源定义 */
#define DAC_TRIGGER_LP1_OUT                        DAC_TRIGGER_LPTIM1_OUT                // LPTIM1 输出作为DAC触发源
#define DAC_TRIGGER_LP2_OUT                        DAC_TRIGGER_LPTIM2_OUT                // LPTIM2 输出作为DAC触发源

#endif /* STM32H7 */

#if defined(STM32U5)
#define GPDMA1_REQUEST_DCMI                        GPDMA1_REQUEST_DCMI_PSSI              // DCMI/PSSI 请求映射到 GPDMA1
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Defines HAL FLASH Aliased Defines maintained for legacy purpose
  * @{
  */

/* FLASH 编程类型定义 */
#define TYPEPROGRAM_BYTE              FLASH_TYPEPROGRAM_BYTE             // 字节编程(8位)
#define TYPEPROGRAM_HALFWORD          FLASH_TYPEPROGRAM_HALFWORD         // 半字编程(16位)
#define TYPEPROGRAM_WORD              FLASH_TYPEPROGRAM_WORD             // 字编程(32位)
#define TYPEPROGRAM_DOUBLEWORD        FLASH_TYPEPROGRAM_DOUBLEWORD       // 双字编程(64位)

/* FLASH 擦除类型定义 */
#define TYPEERASE_SECTORS             FLASH_TYPEERASE_SECTORS            // 扇区擦除
#define TYPEERASE_PAGES               FLASH_TYPEERASE_PAGES              // 页擦除
#define TYPEERASE_PAGEERASE           FLASH_TYPEERASE_PAGES              // 页擦除(旧名称兼容)
#define TYPEERASE_MASSERASE           FLASH_TYPEERASE_MASSERASE          // 全片擦除(批量擦除)

/* 写保护状态定义 */
#define WRPSTATE_DISABLE              OB_WRPSTATE_DISABLE                // 禁止写保护
#define WRPSTATE_ENABLE               OB_WRPSTATE_ENABLE                 // 使能写保护

/* FLASH 操作超时值定义 */
#define HAL_FLASH_TIMEOUT_VALUE       FLASH_TIMEOUT_VALUE                // Flash操作超时时间

/* 选项字节扩展定义 */
#define OBEX_PCROP                    OPTIONBYTE_PCROP                   // PCROP(专有代码读出保护)配置
#define OBEX_BOOTCONFIG               OPTIONBYTE_BOOTCONFIG              // 启动配置

/* PCROP 状态定义 */
#define PCROPSTATE_DISABLE            OB_PCROP_STATE_DISABLE             // 禁止 PCROP
#define PCROPSTATE_ENABLE             OB_PCROP_STATE_ENABLE              // 使能 PCROP

/* FLASH 数据擦除类型定义 */
#define TYPEERASEDATA_BYTE            FLASH_TYPEERASEDATA_BYTE           // 擦除数据-字节
#define TYPEERASEDATA_HALFWORD        FLASH_TYPEERASEDATA_HALFWORD       // 擦除数据-半字
#define TYPEERASEDATA_WORD            FLASH_TYPEERASEDATA_WORD           // 擦除数据-字

/* FLASH 数据编程类型定义 */
#define TYPEPROGRAMDATA_BYTE          FLASH_TYPEPROGRAMDATA_BYTE         // 编程数据-字节
#define TYPEPROGRAMDATA_HALFWORD      FLASH_TYPEPROGRAMDATA_HALFWORD     // 编程数据-半字
#define TYPEPROGRAMDATA_WORD          FLASH_TYPEPROGRAMDATA_WORD         // 编程数据-字
#define TYPEPROGRAMDATA_FASTBYTE      FLASH_TYPEPROGRAMDATA_FASTBYTE     // 快速编程-字节
#define TYPEPROGRAMDATA_FASTHALFWORD  FLASH_TYPEPROGRAMDATA_FASTHALFWORD // 快速编程-半字
#define TYPEPROGRAMDATA_FASTWORD      FLASH_TYPEPROGRAMDATA_FASTWORD     // 快速编程-字

#if !defined(STM32F2) && !defined(STM32F4) && !defined(STM32F7) && !defined(STM32H7)
#define PAGESIZE                      FLASH_PAGE_SIZE                    // Flash 页大小定义
#endif /* STM32F2 && STM32F4 && STM32F7 &&  STM32H7 */

/* 快速编程类型定义(兼容旧名称) */
#define TYPEPROGRAM_FASTBYTE          FLASH_TYPEPROGRAM_BYTE             // 快速字节编程
#define TYPEPROGRAM_FASTHALFWORD      FLASH_TYPEPROGRAM_HALFWORD         // 快速半字编程
#define TYPEPROGRAM_FASTWORD          FLASH_TYPEPROGRAM_WORD             // 快速字编程

/* FLASH 电压范围定义，用于擦除/编程操作 */
#define VOLTAGE_RANGE_1               FLASH_VOLTAGE_RANGE_1              // 电压范围1 (例如 2.7V - 3.6V)
#define VOLTAGE_RANGE_2               FLASH_VOLTAGE_RANGE_2              // 电压范围2
#define VOLTAGE_RANGE_3               FLASH_VOLTAGE_RANGE_3              // 电压范围3
#define VOLTAGE_RANGE_4               FLASH_VOLTAGE_RANGE_4              // 电压范围4 (例如 1.8V - 2.1V)

/* FLASH 快速编程定义 */
#define TYPEPROGRAM_FAST              FLASH_TYPEPROGRAM_FAST             // 快速编程
#define TYPEPROGRAM_FAST_AND_LAST     FLASH_TYPEPROGRAM_FAST_AND_LAST    // 快速编程且为最后一个

/* 写保护区域定义 */
#define WRPAREA_BANK1_AREAA           OB_WRPAREA_BANK1_AREAA             // Bank1 区域A 写保护
#define WRPAREA_BANK1_AREAB           OB_WRPAREA_BANK1_AREAB             // Bank1 区域B 写保护
#define WRPAREA_BANK2_AREAA           OB_WRPAREA_BANK2_AREAA             // Bank2 区域A 写保护
#define WRPAREA_BANK2_AREAB           OB_WRPAREA_BANK2_AREAB             // Bank2 区域B 写保护

/* 独立看门狗(IWDG)在低功耗模式下的行为定义 */
#define IWDG_STDBY_FREEZE             OB_IWDG_STDBY_FREEZE               // 待机模式下冻结IWDG
#define IWDG_STDBY_ACTIVE             OB_IWDG_STDBY_RUN                  // 待机模式下IWDG继续运行
#define IWDG_STOP_FREEZE              OB_IWDG_STOP_FREEZE                // 停止模式下冻结IWDG
#define IWDG_STOP_ACTIVE              OB_IWDG_STOP_RUN                   // 停止模式下IWDG继续运行

/* FLASH 错误标志定义 */
#define FLASH_ERROR_NONE              HAL_FLASH_ERROR_NONE               // 无错误
#define FLASH_ERROR_RD                HAL_FLASH_ERROR_RD                 // 读取错误
#define FLASH_ERROR_PG                HAL_FLASH_ERROR_PROG               // 编程错误
#define FLASH_ERROR_PGP               HAL_FLASH_ERROR_PGS                // 编程顺序错误
#define FLASH_ERROR_WRP               HAL_FLASH_ERROR_WRP                // 写保护错误
#define FLASH_ERROR_OPTV              HAL_FLASH_ERROR_OPTV               // 选项字节有效性错误
#define FLASH_ERROR_OPTVUSR           HAL_FLASH_ERROR_OPTVUSR            // 选项字节用户有效性错误
#define FLASH_ERROR_PROG              HAL_FLASH_ERROR_PROG               // 编程错误
#define FLASH_ERROR_OP                HAL_FLASH_ERROR_OPERATION          // 操作错误
#define FLASH_ERROR_PGA               HAL_FLASH_ERROR_PGA                // 编程对齐错误
#define FLASH_ERROR_SIZE              HAL_FLASH_ERROR_SIZE               // 大小错误
#define FLASH_ERROR_SIZ               HAL_FLASH_ERROR_SIZE               // 大小错误(旧名称)
#define FLASH_ERROR_PGS               HAL_FLASH_ERROR_PGS                // 编程顺序错误
#define FLASH_ERROR_MIS               HAL_FLASH_ERROR_MIS                // 快速编程数据丢失错误
#define FLASH_ERROR_FAST              HAL_FLASH_ERROR_FAST               // 快速编程错误
#define FLASH_ERROR_FWWERR            HAL_FLASH_ERROR_FWWERR             // 写/写错误
#define FLASH_ERROR_NOTZERO           HAL_FLASH_ERROR_NOTZERO            // 非零错误(擦除区域非0xFF)
#define FLASH_ERROR_OPERATION         HAL_FLASH_ERROR_OPERATION          // 操作错误
#define FLASH_ERROR_ERS               HAL_FLASH_ERROR_ERS                // 擦除错误

/* 选项字节：看门狗配置 */
#define OB_WDG_SW                     OB_IWDG_SW                         // 软件看门狗
#define OB_WDG_HW                     OB_IWDG_HW                         // 硬件看门狗

/* 选项字节：SDADC VDD监控配置 */
#define OB_SDADC12_VDD_MONITOR_SET    OB_SDACD_VDD_MONITOR_SET           // 设置 SDADC12 VDD 监控
#define OB_SDADC12_VDD_MONITOR_RESET  OB_SDACD_VDD_MONITOR_RESET         // 复位 SDADC12 VDD 监控

/* 选项字节：RAM奇偶校验配置 */
#define OB_RAM_PARITY_CHECK_SET       OB_SRAM_PARITY_SET                 // 使能 SRAM 奇偶校验
#define OB_RAM_PARITY_CHECK_RESET     OB_SRAM_PARITY_RESET               // 禁止 SRAM 奇偶校验
#define IS_OB_SDADC12_VDD_MONITOR     IS_OB_SDACD_VDD_MONITOR            // 检查参数宏

/* 选项字节：读保护(RDP)等级定义 */
#define OB_RDP_LEVEL0                 OB_RDP_LEVEL_0                     // 等级0 (无保护)
#define OB_RDP_LEVEL1                 OB_RDP_LEVEL_1                     // 等级1 (读保护)
#define OB_RDP_LEVEL2                 OB_RDP_LEVEL_2                     // 等级2 (永久保护)

#if defined(STM32G0) || defined(STM32C0)
#define OB_BOOT_LOCK_DISABLE          OB_BOOT_ENTRY_FORCED_NONE          // 解锁启动，不从Flash强制启动
#define OB_BOOT_LOCK_ENABLE           OB_BOOT_ENTRY_FORCED_FLASH         // 锁定启动，强制从Flash启动
#else
#define OB_BOOT_ENTRY_FORCED_NONE     OB_BOOT_LOCK_DISABLE               // 不强制启动入口
#define OB_BOOT_ENTRY_FORCED_FLASH    OB_BOOT_LOCK_ENABLE                // 强制从Flash启动
#endif

#if defined(STM32H7)
/* STM32H7 系列 Flash 标志别名 */
#define FLASH_FLAG_SNECCE_BANK1RR     FLASH_FLAG_SNECCERR_BANK1          // Bank1 单比特ECC错误
#define FLASH_FLAG_DBECCE_BANK1RR     FLASH_FLAG_DBECCERR_BANK1          // Bank1 双比特ECC错误
#define FLASH_FLAG_STRBER_BANK1R      FLASH_FLAG_STRBERR_BANK1           // Bank1 选通错误
#define FLASH_FLAG_SNECCE_BANK2RR     FLASH_FLAG_SNECCERR_BANK2          // Bank2 单比特ECC错误
#define FLASH_FLAG_DBECCE_BANK2RR     FLASH_FLAG_DBECCERR_BANK2          // Bank2 双比特ECC错误
#define FLASH_FLAG_STRBER_BANK2R      FLASH_FLAG_STRBERR_BANK2           // Bank2 选通错误
#define FLASH_FLAG_WDW                FLASH_FLAG_WBNE                    // 写缓冲非空标志
#define OB_WRP_SECTOR_All             OB_WRP_SECTOR_ALL                  // 所有扇区写保护
#endif /* STM32H7 */

#if defined(STM32U5)
/* STM32U5 系列 选项字节别名 */
#define OB_USER_nRST_STOP             OB_USER_NRST_STOP                  // 停止模式复位配置
#define OB_USER_nRST_STDBY            OB_USER_NRST_STDBY                 // 待机模式复位配置
#define OB_USER_nRST_SHDW             OB_USER_NRST_SHDW                  // 关断模式复位配置
#define OB_USER_nSWBOOT0              OB_USER_NSWBOOT0                   // 软件BOOT0配置
#define OB_USER_nBOOT0                OB_USER_NBOOT0                     // BOOT0引脚配置
#define OB_nBOOT0_RESET               OB_NBOOT0_RESET                    // nBOOT0 复位
#define OB_nBOOT0_SET                 OB_NBOOT0_SET                      // nBOOT0 置位
#define OB_USER_SRAM134_RST           OB_USER_SRAM_RST                   // SRAM复位配置
#define OB_SRAM134_RST_ERASE          OB_SRAM_RST_ERASE                  // SRAM复位时擦除
#define OB_SRAM134_RST_NOT_ERASE      OB_SRAM_RST_NOT_ERASE              // SRAM复位时不擦除
#endif /* STM32U5 */

#if defined(STM32U0)
/* STM32U0 系列 选项字节别名 */
#define OB_USER_nRST_STOP             OB_USER_NRST_STOP                  // 停止模式复位配置
#define OB_USER_nRST_STDBY            OB_USER_NRST_STDBY                 // 待机模式复位配置
#define OB_USER_nRST_SHDW             OB_USER_NRST_SHDW                  // 关断模式复位配置
#define OB_USER_nBOOT_SEL             OB_USER_NBOOT_SEL                  // BOOT选择
#define OB_USER_nBOOT0                OB_USER_NBOOT0                     // BOOT0配置
#define OB_USER_nBOOT1                OB_USER_NBOOT1                     // BOOT1配置
#define OB_nBOOT0_RESET               OB_NBOOT0_RESET                    // nBOOT0 复位
#define OB_nBOOT0_SET                 OB_NBOOT0_SET                      // nBOOT0 置位
#endif /* STM32U0 */

/**
  * @}
  */

/** @defgroup HAL_JPEG_Aliased_Macros HAL JPEG Aliased Macros maintained for legacy purpose
  * @{
  */

#if defined(STM32H7)
/* STM32H7 系列 JPEG 时钟控制宏别名 */
#define __HAL_RCC_JPEG_CLK_ENABLE               __HAL_RCC_JPGDECEN_CLK_ENABLE        // 使能 JPEG 解码时钟
#define __HAL_RCC_JPEG_CLK_DISABLE              __HAL_RCC_JPGDECEN_CLK_DISABLE       // 禁止 JPEG 解码时钟
#define __HAL_RCC_JPEG_FORCE_RESET              __HAL_RCC_JPGDECRST_FORCE_RESET      // 强制复位 JPEG
#define __HAL_RCC_JPEG_RELEASE_RESET            __HAL_RCC_JPGDECRST_RELEASE_RESET    // 释放复位 JPEG
#define __HAL_RCC_JPEG_CLK_SLEEP_ENABLE         __HAL_RCC_JPGDEC_CLK_SLEEP_ENABLE    // 睡眠模式下使能 JPEG 时钟
#define __HAL_RCC_JPEG_CLK_SLEEP_DISABLE        __HAL_RCC_JPGDEC_CLK_SLEEP_DISABLE   // 睡眠模式下禁止 JPEG 时钟
#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_SYSCFG_Aliased_Defines HAL SYSCFG Aliased Defines maintained for legacy purpose
  * @{
  */

/* SYSCFG I2C 快速模式Plus 配置定义 */
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA9    I2C_FASTMODEPLUS_PA9                // PA9 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA10   I2C_FASTMODEPLUS_PA10               // PA10 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB6    I2C_FASTMODEPLUS_PB6                // PB6 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB7    I2C_FASTMODEPLUS_PB7                // PB7 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB8    I2C_FASTMODEPLUS_PB8                // PB8 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB9    I2C_FASTMODEPLUS_PB9                // PB9 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C1       I2C_FASTMODEPLUS_I2C1               // I2C1 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C2       I2C_FASTMODEPLUS_I2C2               // I2C2 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C3       I2C_FASTMODEPLUS_I2C3               // I2C3 快速模式Plus

#if defined(STM32G4)
/* STM32G4 系列 IO 模拟开关配置 */
#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SYSCFG_EnableIOSwitchBooster   // 使能 IO 模拟开关增强器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SYSCFG_DisableIOSwitchBooster  // 禁止 IO 模拟开关增强器
#define HAL_SYSCFG_EnableIOAnalogSwitchVDD        HAL_SYSCFG_EnableIOSwitchVDD       // 使能 IO 模拟开关 VDD
#define HAL_SYSCFG_DisableIOAnalogSwitchVDD       HAL_SYSCFG_DisableIOSwitchVDD      // 禁止 IO 模拟开关 VDD
#endif /* STM32G4 */

#if defined(STM32H5)
/* STM32H5 系列 SYSCFG 中断定义 */
#define SYSCFG_IT_FPU_IOC         SBS_IT_FPU_IOC                      // FPU 无效操作中断
#define SYSCFG_IT_FPU_DZC         SBS_IT_FPU_DZC                      // FPU 除零中断
#define SYSCFG_IT_FPU_UFC         SBS_IT_FPU_UFC                      // FPU 下溢中断
#define SYSCFG_IT_FPU_OFC         SBS_IT_FPU_OFC                      // FPU 上溢中断
#define SYSCFG_IT_FPU_IDC         SBS_IT_FPU_IDC                      // FPU 不精确中断
#define SYSCFG_IT_FPU_IXC         SBS_IT_FPU_IXC                      // FPU 不精确累加中断

/* SYSCFG 断点定义 */
#define SYSCFG_BREAK_FLASH_ECC    SBS_BREAK_FLASH_ECC                 // Flash ECC 错误断点
#define SYSCFG_BREAK_PVD          SBS_BREAK_PVD                       // PVD 阈值检测断点
#define SYSCFG_BREAK_SRAM_ECC     SBS_BREAK_SRAM_ECC                  // SRAM ECC 错误断点
#define SYSCFG_BREAK_LOCKUP       SBS_BREAK_LOCKUP                    // 内核锁定断点

/* SYSCFG VREFBUF 电压范围定义 */
#define SYSCFG_VREFBUF_VOLTAGE_SCALE0   VREFBUF_VOLTAGE_SCALE0        // 电压范围0
#define SYSCFG_VREFBUF_VOLTAGE_SCALE1   VREFBUF_VOLTAGE_SCALE1        // 电压范围1
#define SYSCFG_VREFBUF_VOLTAGE_SCALE2   VREFBUF_VOLTAGE_SCALE2        // 电压范围2
#define SYSCFG_VREFBUF_VOLTAGE_SCALE3   VREFBUF_VOLTAGE_SCALE3        // 电压范围3

/* SYSCFG VREFBUF 高阻抗模式定义 */
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE   VREFBUF_HIGH_IMPEDANCE_DISABLE  // 禁止高阻抗模式
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE    VREFBUF_HIGH_IMPEDANCE_ENABLE   // 使能高阻抗模式

/* SYSCFG I2C 快速模式Plus 引脚定义 */
#define SYSCFG_FASTMODEPLUS_PB6   SBS_FASTMODEPLUS_PB6                // PB6 快速模式Plus
#define SYSCFG_FASTMODEPLUS_PB7   SBS_FASTMODEPLUS_PB7                // PB7 快速模式Plus
#define SYSCFG_FASTMODEPLUS_PB8   SBS_FASTMODEPLUS_PB8                // PB8 快速模式Plus
#define SYSCFG_FASTMODEPLUS_PB9   SBS_FASTMODEPLUS_PB9                // PB9 快速模式Plus

/* SYSCFG 以太网接口选择 */
#define SYSCFG_ETH_MII   SBS_ETH_MII                                    // 选择 MII 接口
#define SYSCFG_ETH_RMII  SBS_ETH_RMII                                   // 选择 RMII 接口
#define IS_SYSCFG_ETHERNET_CONFIG  IS_SBS_ETHERNET_CONFIG               // 检查参数宏

/* SYSCFG 内存擦除标志 */
#define SYSCFG_MEMORIES_ERASE_FLAG_IPMEE   SBS_MEMORIES_ERASE_FLAG_IPMEE    // IPMEE 擦除标志
#define SYSCFG_MEMORIES_ERASE_FLAG_MCLR    SBS_MEMORIES_ERASE_FLAG_MCLR     // MCLR 擦除标志
#define IS_SYSCFG_MEMORIES_ERASE_FLAG      IS_SBS_MEMORIES_ERASE_FLAG       // 检查参数宏

#define IS_SYSCFG_CODE_CONFIG IS_SBS_CODE_CONFIG                          // 检查代码配置参数宏

/* SYSCFG 安全属性配置 */
#define SYSCFG_MPU_NSEC   SBS_MPU_NSEC                                  // MPU 非安全配置
#define SYSCFG_VTOR_NSEC  SBS_VTOR_NSEC                                 // VTOR 非安全配置

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/* 安全扩展相关定义 (CMSE = 3) */
#define SYSCFG_SAU              SBS_SAU                                 // SAU 配置
#define SYSCFG_MPU_SEC          SBS_MPU_SEC                             // MPU 安全配置
#define SYSCFG_VTOR_AIRCR_SEC   SBS_VTOR_AIRCR_SEC                      // VTOR/AIRCR 安全配置
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL                            // 锁定所有
#else
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL                            // 锁定所有
#endif /* __ARM_FEATURE_CMSE */

/* SYSCFG 时钟与功能定义 */
#define SYSCFG_CLK      SBS_CLK                                         // SYSCFG 时钟
#define SYSCFG_CLASSB   SBS_CLASSB                                      // Class B 功能
#define SYSCFG_FPU      SBS_FPU                                         // FPU 配置
#define SYSCFG_ALL      SBS_ALL                                         // 所有功能

#define SYSCFG_SEC      SBS_SEC                                         // 安全配置
#define SYSCFG_NSEC     SBS_NSEC                                        // 非安全配置

/* SYSCFG 宏定义别名 */
#define __HAL_SYSCFG_FPU_INTERRUPT_ENABLE   __HAL_SBS_FPU_INTERRUPT_ENABLE    // 使能 FPU 中断
#define __HAL_SYSCFG_FPU_INTERRUPT_DISABLE  __HAL_SBS_FPU_INTERRUPT_DISABLE   // 禁止 FPU 中断

#define __HAL_SYSCFG_BREAK_ECC_LOCK        __HAL_SBS_BREAK_ECC_LOCK           // 锁定 ECC 断点
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK     __HAL_SBS_BREAK_LOCKUP_LOCK        // 锁定 Lockup 断点
#define __HAL_SYSCFG_BREAK_PVD_LOCK        __HAL_SBS_BREAK_PVD_LOCK           // 锁定 PVD 断点
#define __HAL_SYSCFG_BREAK_SRAM_ECC_LOCK   __HAL_SBS_BREAK_SRAM_ECC_LOCK      // 锁定 SRAM ECC 断点

#define __HAL_SYSCFG_FASTMODEPLUS_ENABLE   __HAL_SBS_FASTMODEPLUS_ENABLE      // 使能快速模式Plus
#define __HAL_SYSCFG_FASTMODEPLUS_DISABLE  __HAL_SBS_FASTMODEPLUS_DISABLE     // 禁止快速模式Plus

#define __HAL_SYSCFG_GET_MEMORIES_ERASE_STATUS    __HAL_SBS_GET_MEMORIES_ERASE_STATUS   // 获取内存擦除状态
#define __HAL_SYSCFG_CLEAR_MEMORIES_ERASE_STATUS  __HAL_SBS_CLEAR_MEMORIES_ERASE_STATUS // 清除内存擦除状态

/* 参数检查宏定义 */
#define IS_SYSCFG_FPU_INTERRUPT    IS_SBS_FPU_INTERRUPT
#define IS_SYSCFG_BREAK_CONFIG     IS_SBS_BREAK_CONFIG
#define IS_SYSCFG_VREFBUF_VOLTAGE_SCALE     IS_VREFBUF_VOLTAGE_SCALE
#define IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE    IS_VREFBUF_HIGH_IMPEDANCE
#define IS_SYSCFG_VREFBUF_TRIMMING  IS_VREFBUF_TRIMMING
#define IS_SYSCFG_FASTMODEPLUS      IS_SBS_FASTMODEPLUS
#define IS_SYSCFG_ITEMS_ATTRIBUTES  IS_SBS_ITEMS_ATTRIBUTES
#define IS_SYSCFG_ATTRIBUTES        IS_SBS_ATTRIBUTES
#define IS_SYSCFG_LOCK_ITEMS        IS_SBS_LOCK_ITEMS

/* HAL 函数别名定义 */
#define HAL_SYSCFG_VREFBUF_VoltageScalingConfig   HAL_VREFBUF_VoltageScalingConfig   // VREFBUF 电压缩放配置
#define HAL_SYSCFG_VREFBUF_HighImpedanceConfig    HAL_VREFBUF_HighImpedanceConfig    // VREFBUF 高阻抗配置
#define HAL_SYSCFG_VREFBUF_TrimmingConfig         HAL_VREFBUF_TrimmingConfig         // VREFBUF 修剪配置
#define HAL_SYSCFG_EnableVREFBUF                  HAL_EnableVREFBUF                  // 使能 VREFBUF
#define HAL_SYSCFG_DisableVREFBUF                 HAL_DisableVREFBUF                 // 禁止 VREFBUF

#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SBS_EnableIOAnalogSwitchBooster   // 使能 IO 模拟开关增强器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SBS_DisableIOAnalogSwitchBooster  // 禁止 IO 模拟开关增强器
#define HAL_SYSCFG_ETHInterfaceSelect             HAL_SBS_ETHInterfaceSelect            // 以太网接口选择

#define HAL_SYSCFG_Lock     HAL_SBS_Lock                                              // 锁定 SYSCFG
#define HAL_SYSCFG_GetLock  HAL_SBS_GetLock                                           // 获取锁定状态

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define HAL_SYSCFG_ConfigAttributes     HAL_SBS_ConfigAttributes                   // 配置属性(安全模式)
#define HAL_SYSCFG_GetConfigAttributes  HAL_SBS_GetConfigAttributes                 // 获取配置属性(安全模式)
#endif /* __ARM_FEATURE_CMSE */

#endif /* STM32H5 */


/**
  * @}
  */


/** @defgroup LL_FMC_Aliased_Defines LL FMC Aliased Defines maintained for compatibility purpose
  * @{
  */
/* FMC NAND/PCC 等待特性及总线宽度定义 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)
#define FMC_NAND_PCC_WAIT_FEATURE_DISABLE       FMC_NAND_WAIT_FEATURE_DISABLE       // 禁止等待特性
#define FMC_NAND_PCC_WAIT_FEATURE_ENABLE        FMC_NAND_WAIT_FEATURE_ENABLE        // 使能等待特性
#define FMC_NAND_PCC_MEM_BUS_WIDTH_8            FMC_NAND_MEM_BUS_WIDTH_8            // 8位总线宽度
#define FMC_NAND_PCC_MEM_BUS_WIDTH_16           FMC_NAND_MEM_BUS_WIDTH_16           // 16位总线宽度
#elif defined(STM32F1) || defined(STM32F2) || defined(STM32F3) || defined(STM32F4)
#define FMC_NAND_WAIT_FEATURE_DISABLE           FMC_NAND_PCC_WAIT_FEATURE_DISABLE   // 禁止等待特性(旧名称)
#define FMC_NAND_WAIT_FEATURE_ENABLE            FMC_NAND_PCC_WAIT_FEATURE_ENABLE    // 使能等待特性(旧名称)
#define FMC_NAND_MEM_BUS_WIDTH_8                FMC_NAND_PCC_MEM_BUS_WIDTH_8        // 8位总线宽度(旧名称)
#define FMC_NAND_MEM_BUS_WIDTH_16               FMC_NAND_PCC_MEM_BUS_WIDTH_16       // 16位总线宽度(旧名称)
#endif
/**
  * @}
  */

/** @defgroup LL_FSMC_Aliased_Defines LL FSMC Aliased Defines maintained for legacy purpose
  * @{
  */

/* FSMC NOR/SRAM 类型定义 */
#define FSMC_NORSRAM_TYPEDEF                      FSMC_NORSRAM_TypeDef             // FSMC NOR/SRAM 寄存器结构体类型
#define FSMC_NORSRAM_EXTENDED_TYPEDEF             FSMC_NORSRAM_EXTENDED_TypeDef    // FSMC NOR/SRAM 扩展寄存器结构体类型
/**
  * @}
  */

/** @defgroup HAL_GPIO_Aliased_Macros HAL GPIO Aliased Macros maintained for legacy purpose
  * @{
  */
/* GPIO 引脚源/索引获取宏 */
#define GET_GPIO_SOURCE                           GPIO_GET_INDEX                    // 获取 GPIO 源(旧名称)
#define GET_GPIO_INDEX                            GPIO_GET_INDEX                    // 获取 GPIO 索引

#if defined(STM32F4)
/* STM32F4 系列 GPIO 复用功能定义 */
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDIO                    // SDIO 复用功能12
#define GPIO_AF12_SDMMC1                          GPIO_AF12_SDIO                    // SDMMC1 复用功能12
#endif

#if defined(STM32F7)
/* STM32F7 系列 GPIO 复用功能定义 */
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#endif

#if defined(STM32L4)
/* STM32L4 系列 GPIO 复用功能定义 */
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#endif

#if defined(STM32H7)
/* STM32H7 系列 GPIO 复用功能定义 */
#define GPIO_AF7_SDIO1                            GPIO_AF7_SDMMC1                   // SDMMC1 复用功能7
#define GPIO_AF8_SDIO1                            GPIO_AF8_SDMMC1                   // SDMMC1 复用功能8
#define GPIO_AF12_SDIO1                           GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#define GPIO_AF9_SDIO2                            GPIO_AF9_SDMMC2                   // SDMMC2 复用功能9
#define GPIO_AF10_SDIO2                           GPIO_AF10_SDMMC2                  // SDMMC2 复用功能10
#define GPIO_AF11_SDIO2                           GPIO_AF11_SDMMC2                  // SDMMC2 复用功能11

#if defined (STM32H743xx) || defined (STM32H753xx)  || defined (STM32H750xx) || defined (STM32H742xx) || \
    defined (STM32H745xx) || defined (STM32H755xx)  || defined (STM32H747xx) || defined (STM32H757xx)
/* STM32H7 特定型号 OTG 复用功能定义 */
#define GPIO_AF10_OTG2_HS  GPIO_AF10_OTG2_FS                                         // OTG2 高速/全速
#define GPIO_AF10_OTG1_FS  GPIO_AF10_OTG1_HS                                         // OTG1 全速/高速
#define GPIO_AF12_OTG2_FS  GPIO_AF12_OTG1_FS                                         // OTG2/OTG1 全速
#endif /*STM32H743xx || STM32H753xx || STM32H750xx || STM32H742xx || STM32H745xx || STM32H755xx || STM32H747xx || \
         STM32H757xx */
#endif /* STM32H7 */

/* LPTIM 复用功能定义 */
#define GPIO_AF0_LPTIM                            GPIO_AF0_LPTIM1                   // LPTIM1 复用功能0
#define GPIO_AF1_LPTIM                            GPIO_AF1_LPTIM1                   // LPTIM1 复用功能1
#define GPIO_AF2_LPTIM                            GPIO_AF2_LPTIM1                   // LPTIM1 复用功能2

/* GPIO 速度定义 */
#if defined(STM32L0) || defined(STM32L4) || defined(STM32F4) || defined(STM32F2) || defined(STM32F7) || \
    defined(STM32G4) || defined(STM32H7) || defined(STM32WB) || defined(STM32U5)
#define  GPIO_SPEED_LOW                           GPIO_SPEED_FREQ_LOW               // 低速
#define  GPIO_SPEED_MEDIUM                        GPIO_SPEED_FREQ_MEDIUM            // 中速
#define  GPIO_SPEED_FAST                          GPIO_SPEED_FREQ_HIGH              // 快速(高速)
#define  GPIO_SPEED_HIGH                          GPIO_SPEED_FREQ_VERY_HIGH         // 高速(极高速)
#endif /* STM32L0 || STM32L4 || STM32F4 || STM32F2 || STM32F7 || STM32G4 || STM32H7 || STM32WB || STM32U5*/

#if defined(STM32L1)
/* STM32L1 系列 GPIO 速度定义 */
#define  GPIO_SPEED_VERY_LOW    GPIO_SPEED_FREQ_LOW                                 // 极低速
#define  GPIO_SPEED_LOW         GPIO_SPEED_FREQ_MEDIUM                              // 低速
#define  GPIO_SPEED_MEDIUM      GPIO_SPEED_FREQ_HIGH                                // 中速
#define  GPIO_SPEED_HIGH        GPIO_SPEED_FREQ_VERY_HIGH                           // 高速
#endif /* STM32L1 */
