#define I2S_FLAG_TXE             I2S_FLAG_TXP // I2S发送缓冲区为空标志，映射为TXP标志
#define I2S_FLAG_RXNE            I2S_FLAG_RXP // I2S接收缓冲区非空标志，映射为RXP标志
#endif

#if defined(STM32F7)
#define I2S_CLOCK_SYSCLK           I2S_CLOCK_PLL // 对于STM32F7系列，定义I2S系统时钟源为PLL
#endif
/**
  * @}
  */

/** @defgroup HAL_PCCARD_Aliased_Defines HAL PCCARD Aliased Defines maintained for legacy purpose
  * @{
  */

/* Compact Flash-ATA registers description */
// 以下是Compact Flash(CF卡)与ATA接口寄存器的宏定义别名映射
#define CF_DATA                       ATA_DATA // 数据寄存器
#define CF_SECTOR_COUNT               ATA_SECTOR_COUNT // 扇区计数寄存器
#define CF_SECTOR_NUMBER              ATA_SECTOR_NUMBER // 扇区号寄存器
#define CF_CYLINDER_LOW               ATA_CYLINDER_LOW // 柱面低字节寄存器
#define CF_CYLINDER_HIGH              ATA_CYLINDER_HIGH // 柱面高字节寄存器
#define CF_CARD_HEAD                  ATA_CARD_HEAD // 卡/磁头寄存器
#define CF_STATUS_CMD                 ATA_STATUS_CMD // 状态/命令寄存器
#define CF_STATUS_CMD_ALTERNATE       ATA_STATUS_CMD_ALTERNATE // 备用状态/命令寄存器
#define CF_COMMON_DATA_AREA           ATA_COMMON_DATA_AREA // 公共数据区域

/* Compact Flash-ATA commands */
// CF卡/ATA标准命令宏定义别名映射
#define CF_READ_SECTOR_CMD            ATA_READ_SECTOR_CMD // 读扇区命令
#define CF_WRITE_SECTOR_CMD           ATA_WRITE_SECTOR_CMD // 写扇区命令
#define CF_ERASE_SECTOR_CMD           ATA_ERASE_SECTOR_CMD // 擦除扇区命令
#define CF_IDENTIFY_CMD               ATA_IDENTIFY_CMD // 识别设备命令

// PCCARD状态类型定义，用于兼容旧代码
#define PCCARD_StatusTypedef          HAL_PCCARD_StatusTypeDef // PCCARD状态类型别名
#define PCCARD_SUCCESS                HAL_PCCARD_STATUS_SUCCESS // 操作成功
#define PCCARD_ONGOING                HAL_PCCARD_STATUS_ONGOING // 操作正在进行中
#define PCCARD_ERROR                  HAL_PCCARD_STATUS_ERROR // 操作错误
#define PCCARD_TIMEOUT                HAL_PCCARD_STATUS_TIMEOUT // 操作超时
/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Defines HAL RTC Aliased Defines maintained for legacy purpose
  * @{
  */

// RTC(实时时钟)相关宏定义别名映射
#define FORMAT_BIN                  RTC_FORMAT_BIN // 二进制格式
#define FORMAT_BCD                  RTC_FORMAT_BCD // BCD码格式

#define RTC_ALARMSUBSECONDMASK_None     RTC_ALARMSUBSECONDMASK_NONE // 闹钟子秒无掩码
#define RTC_TAMPERERASEBACKUP_DISABLED  RTC_TAMPER_ERASE_BACKUP_DISABLE // 篡改事件禁止擦除备份寄存器
#define RTC_TAMPERMASK_FLAG_DISABLED    RTC_TAMPERMASK_FLAG_DISABLE // 禁止篡改标志掩码
#define RTC_TAMPERMASK_FLAG_ENABLED     RTC_TAMPERMASK_FLAG_ENABLE // 使能篡改标志掩码

#define RTC_MASKTAMPERFLAG_DISABLED     RTC_TAMPERMASK_FLAG_DISABLE // 禁止篡改标志掩码(旧名称)
#define RTC_MASKTAMPERFLAG_ENABLED      RTC_TAMPERMASK_FLAG_ENABLE // 使能篡改标志掩码(旧名称)
#define RTC_TAMPERERASEBACKUP_ENABLED   RTC_TAMPER_ERASE_BACKUP_ENABLE // 篡改事件使能擦除备份寄存器
#define RTC_TAMPER1_2_INTERRUPT         RTC_ALL_TAMPER_INTERRUPT // 篡改1和2中断
#define RTC_TAMPER1_2_3_INTERRUPT       RTC_ALL_TAMPER_INTERRUPT // 篡改1、2和3中断

// RTC时间戳引脚映射定义
#define RTC_TIMESTAMPPIN_PC13  RTC_TIMESTAMPPIN_DEFAULT // 时间戳引脚PC13(默认)
#define RTC_TIMESTAMPPIN_PA0   RTC_TIMESTAMPPIN_POS1 // 时间戳引脚PA0(位置1)
#define RTC_TIMESTAMPPIN_PI8   RTC_TIMESTAMPPIN_POS1 // 时间戳引脚PI8(位置1)
#define RTC_TIMESTAMPPIN_PC1   RTC_TIMESTAMPPIN_POS2 // 时间戳引脚PC1(位置2)

// RTC输出重映射定义
#define RTC_OUTPUT_REMAP_PC13  RTC_OUTPUT_REMAP_NONE // 输出重映射到PC13(无重映射)
#define RTC_OUTPUT_REMAP_PB14  RTC_OUTPUT_REMAP_POS1 // 输出重映射到PB14(位置1)
#define RTC_OUTPUT_REMAP_PB2   RTC_OUTPUT_REMAP_POS1 // 输出重映射到PB2(位置1)

// RTC篡改检测引脚映射定义
#define RTC_TAMPERPIN_PC13 RTC_TAMPERPIN_DEFAULT // 篡改引脚PC13(默认)
#define RTC_TAMPERPIN_PA0  RTC_TAMPERPIN_POS1 // 篡改引脚PA0(位置1)
#define RTC_TAMPERPIN_PI8  RTC_TAMPERPIN_POS1 // 篡改引脚PI8(位置1)

#if defined(STM32H5) || defined(STM32H7RS)
// 篡改检测秘密设备擦除配置(针对STM32H5/H7RS系列)
#define TAMP_SECRETDEVICE_ERASE_NONE        TAMP_DEVICESECRETS_ERASE_NONE // 不擦除
#define TAMP_SECRETDEVICE_ERASE_BKP_SRAM    TAMP_DEVICESECRETS_ERASE_BKPSRAM // 擦除备份SRAM
#endif /* STM32H5 || STM32H7RS */

#if defined(STM32WBA)
// 篡改检测秘密设备擦除配置(针对STM32WBA系列)
#define TAMP_SECRETDEVICE_ERASE_NONE            TAMP_DEVICESECRETS_ERASE_NONE // 不擦除
#define TAMP_SECRETDEVICE_ERASE_SRAM2           TAMP_DEVICESECRETS_ERASE_SRAM2 // 擦除SRAM2
#define TAMP_SECRETDEVICE_ERASE_RHUK            TAMP_DEVICESECRETS_ERASE_RHUK // 擦除RHUK
#define TAMP_SECRETDEVICE_ERASE_ICACHE          TAMP_DEVICESECRETS_ERASE_ICACHE // 擦除指令缓存
#define TAMP_SECRETDEVICE_ERASE_SAES_AES_HASH   TAMP_DEVICESECRETS_ERASE_SAES_AES_HASH // 擦除SAES/AES/Hash
#define TAMP_SECRETDEVICE_ERASE_PKA_SRAM        TAMP_DEVICESECRETS_ERASE_PKA_SRAM // 擦除PKA SRAM
#define TAMP_SECRETDEVICE_ERASE_ALL             TAMP_DEVICESECRETS_ERASE_ALL // 擦除所有
#endif /* STM32WBA */

#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
// 篡改检测秘密设备擦除使能/禁止配置
#define TAMP_SECRETDEVICE_ERASE_DISABLE     TAMP_DEVICESECRETS_ERASE_NONE // 禁止擦除
#define TAMP_SECRETDEVICE_ERASE_ENABLE      TAMP_SECRETDEVICE_ERASE_ALL // 使能擦除(擦除所有)
#endif /* STM32H5 || STM32WBA || STM32H7RS */

#if defined(STM32F7)
// STM32F7系列篡改控制寄存器位定义
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_ENABLE_BITS_MASK // 篡改使能位掩码
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_IT_ENABLE_BITS_MASK // 篡改中断使能位掩码
#endif /* STM32F7 */

#if defined(STM32H7)
// STM32H7系列篡改控制寄存器位定义
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_X // 篡改X
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_X_INTERRUPT // 篡改X中断
#endif /* STM32H7 */

#if defined(STM32F7) || defined(STM32H7) || defined(STM32L0)
// 篡改中断定义
#define RTC_TAMPER1_INTERRUPT      RTC_IT_TAMP1 // 篡改1中断
#define RTC_TAMPER2_INTERRUPT      RTC_IT_TAMP2 // 篡改2中断
#define RTC_TAMPER3_INTERRUPT      RTC_IT_TAMP3 // 篡改3中断
#define RTC_ALL_TAMPER_INTERRUPT   RTC_IT_TAMP // 所有篡改中断
#endif /* STM32F7 || STM32H7 || STM32L0 */

/**
  * @}
  */


/** @defgroup HAL_SMARTCARD_Aliased_Defines HAL SMARTCARD Aliased Defines maintained for legacy purpose
  * @{
  */
// 智能卡相关配置别名定义
#define SMARTCARD_NACK_ENABLED                  SMARTCARD_NACK_ENABLE // 使能NACK
#define SMARTCARD_NACK_DISABLED                 SMARTCARD_NACK_DISABLE // 禁止NACK

#define SMARTCARD_ONEBIT_SAMPLING_DISABLED      SMARTCARD_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_ENABLED       SMARTCARD_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_DISABLE       SMARTCARD_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_ENABLE        SMARTCARD_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样

#define SMARTCARD_TIMEOUT_DISABLED              SMARTCARD_TIMEOUT_DISABLE // 禁止超时
#define SMARTCARD_TIMEOUT_ENABLED               SMARTCARD_TIMEOUT_ENABLE // 使能超时

#define SMARTCARD_LASTBIT_DISABLED              SMARTCARD_LASTBIT_DISABLE // 禁止最后一位
#define SMARTCARD_LASTBIT_ENABLED               SMARTCARD_LASTBIT_ENABLE // 使能最后一位
/**
  * @}
  */


/** @defgroup HAL_SMBUS_Aliased_Defines HAL SMBUS Aliased Defines maintained for legacy purpose
  * @{
  */
// SMBUS(系统管理总线)相关配置别名定义
#define SMBUS_DUALADDRESS_DISABLED      SMBUS_DUALADDRESS_DISABLE // 禁止双地址模式
#define SMBUS_DUALADDRESS_ENABLED       SMBUS_DUALADDRESS_ENABLE // 使能双地址模式
#define SMBUS_GENERALCALL_DISABLED      SMBUS_GENERALCALL_DISABLE // 禁止广播呼叫
#define SMBUS_GENERALCALL_ENABLED       SMBUS_GENERALCALL_ENABLE // 使能广播呼叫
#define SMBUS_NOSTRETCH_DISABLED        SMBUS_NOSTRETCH_DISABLE // 禁止时钟延长
#define SMBUS_NOSTRETCH_ENABLED         SMBUS_NOSTRETCH_ENABLE // 使能时钟延长
#define SMBUS_ANALOGFILTER_ENABLED      SMBUS_ANALOGFILTER_ENABLE // 使能模拟滤波器
#define SMBUS_ANALOGFILTER_DISABLED     SMBUS_ANALOGFILTER_DISABLE // 禁止模拟滤波器
#define SMBUS_PEC_DISABLED              SMBUS_PEC_DISABLE // 禁止PEC(包错误检测)
#define SMBUS_PEC_ENABLED               SMBUS_PEC_ENABLE // 使能PEC
#define HAL_SMBUS_STATE_SLAVE_LISTEN    HAL_SMBUS_STATE_LISTEN // 从机监听状态
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Defines HAL SPI Aliased Defines maintained for legacy purpose
  * @{
  */
// SPI(串行外设接口)相关配置别名定义
#define SPI_TIMODE_DISABLED             SPI_TIMODE_DISABLE // 禁止TI模式
#define SPI_TIMODE_ENABLED              SPI_TIMODE_ENABLE // 使能TI模式

#define SPI_CRCCALCULATION_DISABLED     SPI_CRCCALCULATION_DISABLE // 禁止CRC计算
#define SPI_CRCCALCULATION_ENABLED      SPI_CRCCALCULATION_ENABLE // 使能CRC计算

#define SPI_NSS_PULSE_DISABLED          SPI_NSS_PULSE_DISABLE // 禁止NSS脉冲
#define SPI_NSS_PULSE_ENABLED           SPI_NSS_PULSE_ENABLE // 使能NSS脉冲

#if defined(STM32H7)
// STM32H7系列SPI标志位和中断别名定义
#define SPI_FLAG_TXE                    SPI_FLAG_TXP // 发送缓冲区为空标志 -> 发送包标志
#define SPI_FLAG_RXNE                   SPI_FLAG_RXP // 接收缓冲区非空标志 -> 接收包标志

#define SPI_IT_TXE                      SPI_IT_TXP // 发送中断 -> 发送包中断
#define SPI_IT_RXNE                     SPI_IT_RXP // 接收中断 -> 接收包中断

// SPI FIFO接收级别定义
#define SPI_FRLVL_EMPTY                 SPI_RX_FIFO_0PACKET // FIFO为空
#define SPI_FRLVL_QUARTER_FULL          SPI_RX_FIFO_1PACKET // FIFO 1/4满(1个包)
#define SPI_FRLVL_HALF_FULL             SPI_RX_FIFO_2PACKET // FIFO 1/2满(2个包)
#define SPI_FRLVL_FULL                  SPI_RX_FIFO_3PACKET // FIFO满(3个包)

#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
// TIM(定时器)相关配置别名定义
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK // 捕获/比较使能位掩码
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK // 捕获/比较互补输出使能位掩码

// DMA基地址定义，用于配置DMA传输定时器寄存器地址
#define TIM_DMABase_CR1                  TIM_DMABASE_CR1 // DMA基地址：控制寄存器1
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2 // DMA基地址：控制寄存器2
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR // DMA基地址：从模式控制寄存器
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER // DMA基地址：DMA/中断使能寄存器
#define TIM_DMABase_SR                   TIM_DMABASE_SR // DMA基地址：状态寄存器
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR // DMA基地址：事件产生寄存器
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1 // DMA基地址：捕获/比较模式寄存器1
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2 // DMA基地址：捕获/比较模式寄存器2
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER // DMA基地址：捕获/比较使能寄存器
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT // DMA基地址：计数器寄存器
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC // DMA基地址：预分频器寄存器
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR // DMA基地址：自动重装载寄存器
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR // DMA基地址：重复计数器寄存器
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1 // DMA基地址：捕获/比较寄存器1
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2 // DMA基地址：捕获/比较寄存器2
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3 // DMA基地址：捕获/比较寄存器3
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4 // DMA基地址：捕获/比较寄存器4
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR // DMA基地址：刹车和死区寄存器
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR // DMA基地址：DMA控制寄存器
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR // DMA基地址：DMA地址寄存器
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1 // DMA基地址：选项寄存器1
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3 // DMA基地址：捕获/比较模式寄存器3
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5 // DMA基地址：捕获/比较寄存器5
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6 // DMA基地址：捕获/比较寄存器6
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2 // DMA基地址：选项寄存器2
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3 // DMA基地址：选项寄存器3
#define TIM_DMABase_OR                   TIM_DMABASE_OR // DMA基地址：选项寄存器(通用)

// 定时器事件源定义
#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE // 更新事件
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1 // 捕获/比较1事件
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2 // 捕获/比较2事件
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3 // 捕获/比较3事件
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4 // 捕获/比较4事件
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM // COM事件
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER // 触发事件
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK // 刹车事件
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2 // 刹车2事件

// DMA突发传输长度定义
#define TIM_DMABurstLength_1Transfer     TIM_DMABURSTLENGTH_1TRANSFER // 1次传输
#define TIM_DMABurstLength_2Transfers    TIM_DMABURSTLENGTH_2TRANSFERS // 2次传输
#define TIM_DMABurstLength_3Transfers    TIM_DMABURSTLENGTH_3TRANSFERS // 3次传输
#define TIM_DMABurstLength_4Transfers    TIM_DMABURSTLENGTH_4TRANSFERS // 4次传输
#define TIM_DMABurstLength_5Transfers    TIM_DMABURSTLENGTH_5TRANSFERS // 5次传输
#define TIM_DMABurstLength_6Transfers    TIM_DMABURSTLENGTH_6TRANSFERS // 6次传输
#define TIM_DMABurstLength_7Transfers    TIM_DMABURSTLENGTH_7TRANSFERS // 7次传输
#define TIM_DMABurstLength_8Transfers    TIM_DMABURSTLENGTH_8TRANSFERS // 8次传输
#define TIM_DMABurstLength_9Transfers    TIM_DMABURSTLENGTH_9TRANSFERS // 9次传输
#define TIM_DMABurstLength_10Transfers   TIM_DMABURSTLENGTH_10TRANSFERS // 10次传输
#define TIM_DMABurstLength_11Transfers   TIM_DMABURSTLENGTH_11TRANSFERS // 11次传输
#define TIM_DMABurstLength_12Transfers   TIM_DMABURSTLENGTH_12TRANSFERS // 12次传输
#define TIM_DMABurstLength_13Transfers   TIM_DMABURSTLENGTH_13TRANSFERS // 13次传输
#define TIM_DMABurstLength_14Transfers   TIM_DMABURSTLENGTH_14TRANSFERS // 14次传输
#define TIM_DMABurstLength_15Transfers   TIM_DMABURSTLENGTH_15TRANSFERS // 15次传输
#define TIM_DMABurstLength_16Transfers   TIM_DMABURSTLENGTH_16TRANSFERS // 16次传输
#define TIM_DMABurstLength_17Transfers   TIM_DMABURSTLENGTH_17TRANSFERS // 17次传输
#define TIM_DMABurstLength_18Transfers   TIM_DMABURSTLENGTH_18TRANSFERS // 18次传输

#if defined(STM32L0)
// STM32L0系列TIM22输入捕获通道1 GPIO定义
#define TIM22_TI1_GPIO1   TIM22_TI1_GPIO // TIM22 TI1输入源GPIO1
#define TIM22_TI1_GPIO2   TIM22_TI1_GPIO // TIM22 TI1输入源GPIO2
#endif

#if defined(STM32F3)
// STM32F3系列霍尔传感器接口实例检查宏
#define IS_TIM_HALL_INTERFACE_INSTANCE   IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE
#endif

#if defined(STM32H7)
// STM32H7系列定时器外部触发和输入捕获复用功能定义
#define TIM_TIM1_ETR_COMP1_OUT        TIM_TIM1_ETR_COMP1 // TIM1 ETR输入来自比较器1输出
#define TIM_TIM1_ETR_COMP2_OUT        TIM_TIM1_ETR_COMP2 // TIM1 ETR输入来自比较器2输出
#define TIM_TIM8_ETR_COMP1_OUT        TIM_TIM8_ETR_COMP1 // TIM8 ETR输入来自比较器1输出
#define TIM_TIM8_ETR_COMP2_OUT        TIM_TIM8_ETR_COMP2 // TIM8 ETR输入来自比较器2输出
#define TIM_TIM2_ETR_COMP1_OUT        TIM_TIM2_ETR_COMP1 // TIM2 ETR输入来自比较器1输出
#define TIM_TIM2_ETR_COMP2_OUT        TIM_TIM2_ETR_COMP2 // TIM2 ETR输入来自比较器2输出
#define TIM_TIM3_ETR_COMP1_OUT        TIM_TIM3_ETR_COMP1 // TIM3 ETR输入来自比较器1输出
#define TIM_TIM1_TI1_COMP1_OUT        TIM_TIM1_TI1_COMP1 // TIM1 TI1输入来自比较器1输出
#define TIM_TIM8_TI1_COMP2_OUT        TIM_TIM8_TI1_COMP2 // TIM8 TI1输入来自比较器2输出
#define TIM_TIM2_TI4_COMP1_OUT        TIM_TIM2_TI4_COMP1 // TIM2 TI4输入来自比较器1输出
#define TIM_TIM2_TI4_COMP2_OUT        TIM_TIM2_TI4_COMP2 // TIM2 TI4输入来自比较器2输出
#define TIM_TIM2_TI4_COMP1COMP2_OUT   TIM_TIM2_TI4_COMP1_COMP2 // TIM2 TI4输入来自比较器1和2
#define TIM_TIM3_TI1_COMP1_OUT        TIM_TIM3_TI1_COMP1 // TIM3 TI1输入来自比较器1输出
#define TIM_TIM3_TI1_COMP2_OUT        TIM_TIM3_TI1_COMP2 // TIM3 TI1输入来自比较器2输出
#define TIM_TIM3_TI1_COMP1COMP2_OUT   TIM_TIM3_TI1_COMP1_COMP2 // TIM3 TI1输入来自比较器1和2
#endif

#if defined(STM32U5)
// STM32U5系列OCREF清除选择位定义
#define OCREF_CLEAR_SELECT_Pos       OCREF_CLEAR_SELECT_POS // 位置定义
#define OCREF_CLEAR_SELECT_Msk       OCREF_CLEAR_SELECT_MSK // 掩码定义
#endif
/**
  * @}
  */

/** @defgroup HAL_TSC_Aliased_Defines HAL TSC Aliased Defines maintained for legacy purpose
  * @{
  */
// TSC(触摸感应控制器)相关配置别名定义
#define TSC_SYNC_POL_FALL        TSC_SYNC_POLARITY_FALLING // 同步极性：下降沿
#define TSC_SYNC_POL_RISE_HIGH   TSC_SYNC_POLARITY_RISING // 同步极性：上升沿(高电平)
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Defines HAL UART Aliased Defines maintained for legacy purpose
  * @{
  */
// UART(通用异步收发传输器)相关配置别名定义
#define UART_ONEBIT_SAMPLING_DISABLED   UART_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define UART_ONEBIT_SAMPLING_ENABLED    UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define UART_ONE_BIT_SAMPLE_DISABLED    UART_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define UART_ONE_BIT_SAMPLE_ENABLED     UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样

#define __HAL_UART_ONEBIT_ENABLE        __HAL_UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样宏
#define __HAL_UART_ONEBIT_DISABLE       __HAL_UART_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样宏

// UART波特率计算相关宏定义(16倍过采样)
#define __DIV_SAMPLING16                UART_DIV_SAMPLING16 // 16倍过采样分频系数
#define __DIVMANT_SAMPLING16            UART_DIVMANT_SAMPLING16 // 16倍过采样分频系数整数部分
#define __DIVFRAQ_SAMPLING16            UART_DIVFRAQ_SAMPLING16 // 16倍过采样分频系数小数部分
#define __UART_BRR_SAMPLING16           UART_BRR_SAMPLING16 // 16倍过采样波特率寄存器值

// UART波特率计算相关宏定义(8倍过采样)
#define __DIV_SAMPLING8                 UART_DIV_SAMPLING8 // 8倍过采样分频系数
#define __DIVMANT_SAMPLING8             UART_DIVMANT_SAMPLING8 // 8倍过采样分频系数整数部分
#define __DIVFRAQ_SAMPLING8             UART_DIVFRAQ_SAMPLING8 // 8倍过采样分频系数小数部分
#define __UART_BRR_SAMPLING8            UART_BRR_SAMPLING8 // 8倍过采样波特率寄存器值

// LPUART(低功耗UART)波特率计算宏
#define __DIV_LPUART                    UART_DIV_LPUART // LPUART分频系数

// UART唤醒方式定义
#define UART_WAKEUPMETHODE_IDLELINE     UART_WAKEUPMETHOD_IDLELINE // 空闲线路唤醒
#define UART_WAKEUPMETHODE_ADDRESSMARK  UART_WAKEUPMETHOD_ADDRESSMARK // 地址标记唤醒

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Defines HAL USART Aliased Defines maintained for legacy purpose
  * @{
  */
// USART(通用同步/异步收发传输器)相关配置别名定义
#define USART_CLOCK_DISABLED            USART_CLOCK_DISABLE // 禁止时钟
#define USART_CLOCK_ENABLED             USART_CLOCK_ENABLE // 使能时钟

#define USARTNACK_ENABLED               USART_NACK_ENABLE // 使能NACK
#define USARTNACK_DISABLED              USART_NACK_DISABLE // 禁止NACK
/**
  * @}
  */

/** @defgroup HAL_WWDG_Aliased_Defines HAL WWDG Aliased Defines maintained for legacy purpose
  * @{
  */
// WWDG(窗口看门狗)相关配置别名定义
#define CFR_BASE                    WWDG_CFR_BASE // 配置寄存器基地址

/**
  * @}
  */

/** @defgroup HAL_CAN_Aliased_Defines HAL CAN Aliased Defines maintained for legacy purpose
  * @{
  */
// CAN(控制器局域网)相关配置别名定义
#define CAN_FilterFIFO0             CAN_FILTER_FIFO0 // 滤波器关联FIFO0
#define CAN_FilterFIFO1             CAN_FILTER_FIFO1 // 滤波器关联FIFO1
#define CAN_IT_RQCP0                CAN_IT_TME // 邮箱0请求完成中断 -> 发送空中断
#define CAN_IT_RQCP1                CAN_IT_TME // 邮箱1请求完成中断 -> 发送空中断
#define CAN_IT_RQCP2                CAN_IT_TME // 邮箱2请求完成中断 -> 发送空中断
#define INAK_TIMEOUT                CAN_TIMEOUT_VALUE // 初始化超时值
#define SLAK_TIMEOUT                CAN_TIMEOUT_VALUE // 从机超时值
// CAN发送状态定义
#define CAN_TXSTATUS_FAILED         ((uint8_t)0x00U) // 发送失败
#define CAN_TXSTATUS_OK             ((uint8_t)0x01U) // 发送成功
#define CAN_TXSTATUS_PENDING        ((uint8_t)0x02U) // 发送挂起

/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Defines HAL ETH Aliased Defines maintained for legacy purpose
  * @{
  */
// ETH(以太网)相关配置别名定义
#define VLAN_TAG                ETH_VLAN_TAG // VLAN标签
#define MIN_ETH_PAYLOAD         ETH_MIN_ETH_PAYLOAD // 最小以太网负载
#define MAX_ETH_PAYLOAD         ETH_MAX_ETH_PAYLOAD // 最大以太网负载
#define JUMBO_FRAME_PAYLOAD     ETH_JUMBO_FRAME_PAYLOAD // 巨帧负载
#define MACMIIAR_CR_MASK        ETH_MACMIIAR_CR_MASK // MII地址寄存器时钟范围掩码
#define MACCR_CLEAR_MASK        ETH_MACCR_CLEAR_MASK // MAC控制寄存器清除掩码
#define MACFCR_CLEAR_MASK       ETH_MACFCR_CLEAR_MASK // 流控制寄存器清除掩码
#define DMAOMR_CLEAR_MASK       ETH_DMAOMR_CLEAR_MASK // DMA操作模式寄存器清除掩码

// 以太网MMC寄存器地址定义(用于统计计数器)
#define ETH_MMCCR              0x00000100U // MMC控制寄存器
#define ETH_MMCRIR             0x00000104U // MMC接收中断寄存器
#define ETH_MMCTIR             0x00000108U // MMC发送中断寄存器
#define ETH_MMCRIMR            0x0000010CU // MMC接收中断屏蔽寄存器
#define ETH_MMCTIMR            0x00000110U // MMC发送中断屏蔽寄存器
#define ETH_MMCTGFSCCR         0x0000014CU // MMC发送良好单播帧计数器
#define ETH_MMCTGFMSCCR        0x00000150U // MMC发送良好多播帧计数器
#define ETH_MMCTGFCR           0x00000168U // MMC发送良好帧计数器
#define ETH_MMCRFCECR          0x00000194U // MMC接收FIFO错误计数器
#define ETH_MMCRFAECR          0x00000198U // MMC接收对齐错误计数器
#define ETH_MMCRGUFCR          0x000001C4U // MMC接收良好单播帧计数器

// 以太网MAC状态标志位定义
#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* 发送FIFO已满 */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* 发送FIFO非空 */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* 发送FIFO写操作激活 */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* 发送FIFO读状态：空闲 */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* 发送FIFO读状态：正在读取(将数据传输到MAC发送器) */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* 发送FIFO读状态：等待来自MAC发送器的发送状态 */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* 发送FIFO读状态：正在写入发送状态或刷新发送FIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC发送器处于暂停状态 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC发送帧控制器：空闲 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC发送帧控制器：等待上一帧状态或IFG/退避时间结束 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC发送帧控制器：正在生成并发送暂停控制帧(全双工模式) */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC发送帧控制器：正在传输输入帧以进行发送 */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII发送引擎激活 */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* 接收FIFO填充级别：空 */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* 接收FIFO填充级别：低于流控制去激活阈值 */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* 接收FIFO填充级别：高于流控制激活阈值 */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* 接收FIFO填充级别：满 */
#if defined(STM32F1)
#else
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* 接收FIFO读控制器：空闲状态 */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* 接收FIFO读控制器：正在读取帧数据 */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* 接收FIFO读控制器：正在读取帧状态(或时间戳) */
#endif
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* 接收FIFO读控制器：正在刷新帧数据和状态 */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* 接收FIFO写控制器激活 */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC小FIFO读/写控制器未激活 */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC小FIFO读控制器激活 */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC小FIFO写控制器激活 */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC小FIFO读/写控制器激活 */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII接收协议引擎激活 */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* 发送数据包配置结构体定义 */

/**
  * @}
  */
