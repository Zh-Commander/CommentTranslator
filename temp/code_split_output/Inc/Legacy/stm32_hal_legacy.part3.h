#define I2S_FLAG_TXE             I2S_FLAG_TXP // I2S发送缓冲区空标志位，映射到I2S_FLAG_TXP
#define I2S_FLAG_RXNE            I2S_FLAG_RXP // I2S接收缓冲区非空标志位，映射到I2S_FLAG_RXP
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
// 以下是Compact Flash（CF卡）与ATA接口寄存器描述的宏定义别名
// 旧版代码使用CF_前缀，新版HAL库统一使用ATA_前缀，此处为了兼容旧代码进行映射
#define CF_DATA                       ATA_DATA // 数据寄存器
#define CF_SECTOR_COUNT               ATA_SECTOR_COUNT // 扇区计数寄存器
#define CF_SECTOR_NUMBER              ATA_SECTOR_NUMBER // 扇区号寄存器
#define CF_CYLINDER_LOW               ATA_CYLINDER_LOW // 柱面低字节寄存器
#define CF_CYLINDER_HIGH              ATA_CYLINDER_HIGH // 柱面高字节寄存器
#define CF_CARD_HEAD                  ATA_CARD_HEAD // 卡/磁头寄存器
#define CF_STATUS_CMD                 ATA_STATUS_CMD // 状态/命令寄存器
#define CF_STATUS_CMD_ALTERNATE       ATA_STATUS_CMD_ALTERNATE // 备用状态/命令寄存器
#define CF_COMMON_DATA_AREA           ATA_COMMON_DATA_AREA // 通用数据区域

/* Compact Flash-ATA commands */
// CF卡/ATA 命令宏定义别名，用于兼容旧代码
#define CF_READ_SECTOR_CMD            ATA_READ_SECTOR_CMD // 读扇区命令
#define CF_WRITE_SECTOR_CMD           ATA_WRITE_SECTOR_CMD // 写扇区命令
#define CF_ERASE_SECTOR_CMD           ATA_ERASE_SECTOR_CMD // 擦除扇区命令
#define CF_IDENTIFY_CMD               ATA_IDENTIFY_CMD // 识别设备命令

// PCCARD状态类型定义别名，将旧版类型名映射到新版标准类型名
#define PCCARD_StatusTypedef          HAL_PCCARD_StatusTypeDef
// 以下是PCCARD状态码的宏定义别名
#define PCCARD_SUCCESS                HAL_PCCARD_STATUS_SUCCESS // 操作成功
#define PCCARD_ONGOING                HAL_PCCARD_STATUS_ONGOING // 操作正在进行
#define PCCARD_ERROR                  HAL_PCCARD_STATUS_ERROR // 操作错误
#define PCCARD_TIMEOUT                HAL_PCCARD_STATUS_TIMEOUT // 操作超时
/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Defines HAL RTC Aliased Defines maintained for legacy purpose
  * @{
  */

// RTC（实时时钟）格式定义别名
#define FORMAT_BIN                  RTC_FORMAT_BIN // 二进制格式
#define FORMAT_BCD                  RTC_FORMAT_BCD // BCD码格式

// RTC闹钟子秒掩码配置别名
#define RTC_ALARMSUBSECONDMASK_None     RTC_ALARMSUBSECONDMASK_NONE // 无掩码

// RTC篡改相关配置别名
#define RTC_TAMPERERASEBACKUP_DISABLED  RTC_TAMPER_ERASE_BACKUP_DISABLE // 禁止篡改事件擦除备份区域
#define RTC_TAMPERMASK_FLAG_DISABLED    RTC_TAMPERMASK_FLAG_DISABLE // 禁止篡改标志掩码
#define RTC_TAMPERMASK_FLAG_ENABLED     RTC_TAMPERMASK_FLAG_ENABLE // 使能篡改标志掩码

#define RTC_MASKTAMPERFLAG_DISABLED     RTC_TAMPERMASK_FLAG_DISABLE // 禁止篡改标志掩码（旧命名）
#define RTC_MASKTAMPERFLAG_ENABLED      RTC_TAMPERMASK_FLAG_ENABLE // 使能篡改标志掩码（旧命名）
#define RTC_TAMPERERASEBACKUP_ENABLED   RTC_TAMPER_ERASE_BACKUP_ENABLE // 使能篡改事件擦除备份区域
#define RTC_TAMPER1_2_INTERRUPT         RTC_ALL_TAMPER_INTERRUPT // 篡改1和2中断
#define RTC_TAMPER1_2_3_INTERRUPT       RTC_ALL_TAMPER_INTERRUPT // 篡改1、2和3中断

// RTC时间戳引脚映射别名
#define RTC_TIMESTAMPPIN_PC13  RTC_TIMESTAMPPIN_DEFAULT // 时间戳引脚PC13（默认）
#define RTC_TIMESTAMPPIN_PA0   RTC_TIMESTAMPPIN_POS1 // 时间戳引脚PA0（位置1）
#define RTC_TIMESTAMPPIN_PI8   RTC_TIMESTAMPPIN_POS1 // 时间戳引脚PI8（位置1）
#define RTC_TIMESTAMPPIN_PC1   RTC_TIMESTAMPPIN_POS2 // 时间戳引脚PC1（位置2）

// RTC输出重映射配置别名
#define RTC_OUTPUT_REMAP_PC13  RTC_OUTPUT_REMAP_NONE // 输出重映射到PC13（无重映射）
#define RTC_OUTPUT_REMAP_PB14  RTC_OUTPUT_REMAP_POS1 // 输出重映射到PB14（位置1）
#define RTC_OUTPUT_REMAP_PB2   RTC_OUTPUT_REMAP_POS1 // 输出重映射到PB2（位置1）

// RTC篡改引脚映射别名
#define RTC_TAMPERPIN_PC13 RTC_TAMPERPIN_DEFAULT // 篡改引脚PC13（默认）
#define RTC_TAMPERPIN_PA0  RTC_TAMPERPIN_POS1 // 篡改引脚PA0（位置1）
#define RTC_TAMPERPIN_PI8  RTC_TAMPERPIN_POS1 // 篡改引脚PI8（位置1）

#if defined(STM32H5) || defined(STM32H7RS)
// 针对STM32H5和STM32H7RS系列，秘密设备擦除配置别名
#define TAMP_SECRETDEVICE_ERASE_NONE        TAMP_DEVICESECRETS_ERASE_NONE // 不擦除
#define TAMP_SECRETDEVICE_ERASE_BKP_SRAM    TAMP_DEVICESECRETS_ERASE_BKPSRAM // 擦除备份SRAM
#endif /* STM32H5 || STM32H7RS */

#if defined(STM32WBA)
// 针对STM32WBA系列，秘密设备擦除配置别名
#define TAMP_SECRETDEVICE_ERASE_NONE            TAMP_DEVICESECRETS_ERASE_NONE // 不擦除
#define TAMP_SECRETDEVICE_ERASE_SRAM2           TAMP_DEVICESECRETS_ERASE_SRAM2 // 擦除SRAM2
#define TAMP_SECRETDEVICE_ERASE_RHUK            TAMP_DEVICESECRETS_ERASE_RHUK // 擦除RHUK
#define TAMP_SECRETDEVICE_ERASE_ICACHE          TAMP_DEVICESECRETS_ERASE_ICACHE // 擦除指令缓存
#define TAMP_SECRETDEVICE_ERASE_SAES_AES_HASH   TAMP_DEVICESECRETS_ERASE_SAES_AES_HASH // 擦除安全AES/哈希
#define TAMP_SECRETDEVICE_ERASE_PKA_SRAM        TAMP_DEVICESECRETS_ERASE_PKA_SRAM // 擦除PKA SRAM
#define TAMP_SECRETDEVICE_ERASE_ALL             TAMP_DEVICESECRETS_ERASE_ALL // 擦除所有
#endif /* STM32WBA */

#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
// 通用秘密设备擦除使能/禁用别名
#define TAMP_SECRETDEVICE_ERASE_DISABLE     TAMP_DEVICESECRETS_ERASE_NONE // 禁用擦除
#define TAMP_SECRETDEVICE_ERASE_ENABLE      TAMP_DEVICESECRETS_ERASE_ALL // 使能擦除
#endif /* STM32H5 || STM32WBA || STM32H7RS */

#if defined(STM32F7)
// STM32F7系列RTC篡改控制寄存器位定义别名
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_ENABLE_BITS_MASK // 篡改使能位掩码
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_IT_ENABLE_BITS_MASK // 篡改中断使能位掩码
#endif /* STM32F7 */

#if defined(STM32H7)
// STM32H7系列RTC篡改控制寄存器位定义别名
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_X // 篡改X
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_X_INTERRUPT // 篡改X中断
#endif /* STM32H7 */

#if defined(STM32F7) || defined(STM32H7) || defined(STM32L0)
// 多系列通用的RTC篡改中断定义别名
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
// 智能卡相关配置别名，主要涉及NACK、采样位、超时和最后一位设置
#define SMARTCARD_NACK_ENABLED                  SMARTCARD_NACK_ENABLE // 使能NACK
#define SMARTCARD_NACK_DISABLED                 SMARTCARD_NACK_DISABLE // 禁用NACK

#define SMARTCARD_ONEBIT_SAMPLING_DISABLED      SMARTCARD_ONE_BIT_SAMPLE_DISABLE // 禁用单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_ENABLED       SMARTCARD_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_DISABLE       SMARTCARD_ONE_BIT_SAMPLE_DISABLE // 禁用单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_ENABLE        SMARTCARD_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样

#define SMARTCARD_TIMEOUT_DISABLED              SMARTCARD_TIMEOUT_DISABLE // 禁用超时
#define SMARTCARD_TIMEOUT_ENABLED               SMARTCARD_TIMEOUT_ENABLE // 使能超时

#define SMARTCARD_LASTBIT_DISABLED              SMARTCARD_LASTBIT_DISABLE // 禁用最后一位脉冲
#define SMARTCARD_LASTBIT_ENABLED               SMARTCARD_LASTBIT_ENABLE // 使能最后一位脉冲
/**
  * @}
  */


/** @defgroup HAL_SMBUS_Aliased_Defines HAL SMBUS Aliased Defines maintained for legacy purpose
  * @{
  */
// SMBUS（系统管理总线）相关配置别名
#define SMBUS_DUALADDRESS_DISABLED      SMBUS_DUALADDRESS_DISABLE // 禁用双地址模式
#define SMBUS_DUALADDRESS_ENABLED       SMBUS_DUALADDRESS_ENABLE // 使能双地址模式
#define SMBUS_GENERALCALL_DISABLED      SMBUS_GENERALCALL_DISABLE // 禁用广播呼叫
#define SMBUS_GENERALCALL_ENABLED       SMBUS_GENERALCALL_ENABLE // 使能广播呼叫
#define SMBUS_NOSTRETCH_DISABLED        SMBUS_NOSTRETCH_DISABLE // 禁用时钟延长
#define SMBUS_NOSTRETCH_ENABLED         SMBUS_NOSTRETCH_ENABLE // 使能时钟延长
#define SMBUS_ANALOGFILTER_ENABLED      SMBUS_ANALOGFILTER_ENABLE // 使能模拟滤波器
#define SMBUS_ANALOGFILTER_DISABLED     SMBUS_ANALOGFILTER_DISABLE // 禁用模拟滤波器
#define SMBUS_PEC_DISABLED              SMBUS_PEC_DISABLE // 禁用PEC（包错误校验）
#define SMBUS_PEC_ENABLED               SMBUS_PEC_ENABLE // 使能PEC
#define HAL_SMBUS_STATE_SLAVE_LISTEN    HAL_SMBUS_STATE_LISTEN // 从机监听状态
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Defines HAL SPI Aliased Defines maintained for legacy purpose
  * @{
  */
// SPI（串行外设接口）相关配置别名
#define SPI_TIMODE_DISABLED             SPI_TIMODE_DISABLE // 禁用TI模式
#define SPI_TIMODE_ENABLED              SPI_TIMODE_ENABLE // 使能TI模式

#define SPI_CRCCALCULATION_DISABLED     SPI_CRCCALCULATION_DISABLE // 禁用CRC计算
#define SPI_CRCCALCULATION_ENABLED      SPI_CRCCALCULATION_ENABLE // 使能CRC计算

#define SPI_NSS_PULSE_DISABLED          SPI_NSS_PULSE_DISABLE // 禁用NSS脉冲
#define SPI_NSS_PULSE_ENABLED           SPI_NSS_PULSE_ENABLE // 使能NSS脉冲

#if defined(STM32H7)

// STM32H7系列SPI标志位和中断别名
#define SPI_FLAG_TXE                    SPI_FLAG_TXP // 发送缓冲区空标志
#define SPI_FLAG_RXNE                   SPI_FLAG_RXP // 接收缓冲区非空标志

#define SPI_IT_TXE                      SPI_IT_TXP // 发送中断
#define SPI_IT_RXNE                     SPI_IT_RXP // 接收中断

// SPI FIFO级别定义别名
#define SPI_FRLVL_EMPTY                 SPI_RX_FIFO_0PACKET // FIFO为空
#define SPI_FRLVL_QUARTER_FULL          SPI_RX_FIFO_1PACKET // FIFO 1/4满（1个包）
#define SPI_FRLVL_HALF_FULL             SPI_RX_FIFO_2PACKET // FIFO 1/2满（2个包）
#define SPI_FRLVL_FULL                  SPI_RX_FIFO_3PACKET // FIFO满（3个包）

#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
// TIM（定时器）相关宏定义别名
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK // 输出使能通道x掩码
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK // 互补输出使能通道x掩码

// DMA基地址定义别名，用于配置DMA传输定时器寄存器地址
#define TIM_DMABase_CR1                  TIM_DMABASE_CR1 // CR1寄存器基地址
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2 // CR2寄存器基地址
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR // SMCR寄存器基地址
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER // DIER寄存器基地址
#define TIM_DMABase_SR                   TIM_DMABASE_SR // SR寄存器基地址
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR // EGR寄存器基地址
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1 // CCMR1寄存器基地址
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2 // CCMR2寄存器基地址
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER // CCER寄存器基地址
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT // CNT寄存器基地址
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC // PSC寄存器基地址
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR // ARR寄存器基地址
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR // RCR寄存器基地址
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1 // CCR1寄存器基地址
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2 // CCR2寄存器基地址
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3 // CCR3寄存器基地址
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4 // CCR4寄存器基地址
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR // BDTR寄存器基地址
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR // DCR寄存器基地址
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR // DMAR寄存器基地址
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1 // OR1寄存器基地址
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3 // CCMR3寄存器基地址
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5 // CCR5寄存器基地址
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6 // CCR6寄存器基地址
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2 // OR2寄存器基地址
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3 // OR3寄存器基地址
#define TIM_DMABase_OR                   TIM_DMABASE_OR // OR寄存器基地址

// 定时器事件源定义别名
#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE // 更新事件
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1 // 捕获/比较1事件
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2 // 捕获/比较2事件
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3 // 捕获/比较3事件
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4 // 捕获/比较4事件
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM // 通信事件
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER // 触发事件
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK // 刹车事件
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2 // 刹车2事件

// DMA突发传输长度定义别名
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
// STM32L0系列TIM22输入捕获通道映射
#define TIM22_TI1_GPIO1   TIM22_TI1_GPIO // TIM22 TI1来自GPIO1
#define TIM22_TI1_GPIO2   TIM22_TI1_GPIO // TIM22 TI1来自GPIO2
#endif

#if defined(STM32F3)
// STM32F3系列霍尔传感器接口实例检查宏
#define IS_TIM_HALL_INTERFACE_INSTANCE   IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE
#endif

#if defined(STM32H7)
// STM32H7系列定时器输入捕获/外部触发映射配置
#define TIM_TIM1_ETR_COMP1_OUT        TIM_TIM1_ETR_COMP1 // TIM1 ETR来自比较器1输出
#define TIM_TIM1_ETR_COMP2_OUT        TIM_TIM1_ETR_COMP2 // TIM1 ETR来自比较器2输出
#define TIM_TIM8_ETR_COMP1_OUT        TIM_TIM8_ETR_COMP1 // TIM8 ETR来自比较器1输出
#define TIM_TIM8_ETR_COMP2_OUT        TIM_TIM8_ETR_COMP2 // TIM8 ETR来自比较器2输出
#define TIM_TIM2_ETR_COMP1_OUT        TIM_TIM2_ETR_COMP1 // TIM2 ETR来自比较器1输出
#define TIM_TIM2_ETR_COMP2_OUT        TIM_TIM2_ETR_COMP2 // TIM2 ETR来自比较器2输出
#define TIM_TIM3_ETR_COMP1_OUT        TIM_TIM3_ETR_COMP1 // TIM3 ETR来自比较器1输出
#define TIM_TIM1_TI1_COMP1_OUT        TIM_TIM1_TI1_COMP1 // TIM1 TI1来自比较器1输出
#define TIM_TIM8_TI1_COMP2_OUT        TIM_TIM8_TI1_COMP2 // TIM8 TI1来自比较器2输出
#define TIM_TIM2_TI4_COMP1_OUT        TIM_TIM2_TI4_COMP1 // TIM2 TI4来自比较器1输出
#define TIM_TIM2_TI4_COMP2_OUT        TIM_TIM2_TI4_COMP2 // TIM2 TI4来自比较器2输出
#define TIM_TIM2_TI4_COMP1COMP2_OUT   TIM_TIM2_TI4_COMP1_COMP2 // TIM2 TI4来自比较器1和2
#define TIM_TIM3_TI1_COMP1_OUT        TIM_TIM3_TI1_COMP1 // TIM3 TI1来自比较器1输出
#define TIM_TIM3_TI1_COMP2_OUT        TIM_TIM3_TI1_COMP2 // TIM3 TI1来自比较器2输出
#define TIM_TIM3_TI1_COMP1COMP2_OUT   TIM_TIM3_TI1_COMP1_COMP2 // TIM3 TI1来自比较器1和2
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
// TSC（触摸传感控制器）同步极性定义别名
#define TSC_SYNC_POL_FALL        TSC_SYNC_POLARITY_FALLING // 下降沿同步
#define TSC_SYNC_POL_RISE_HIGH   TSC_SYNC_POLARITY_RISING // 上升沿同步
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Defines HAL UART Aliased Defines maintained for legacy purpose
  * @{
  */
// UART（通用异步收发传输器）相关配置别名
#define UART_ONEBIT_SAMPLING_DISABLED   UART_ONE_BIT_SAMPLE_DISABLE // 禁用单比特采样
#define UART_ONEBIT_SAMPLING_ENABLED    UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define UART_ONE_BIT_SAMPLE_DISABLED    UART_ONE_BIT_SAMPLE_DISABLE // 禁用单比特采样
#define UART_ONE_BIT_SAMPLE_ENABLED     UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样

// 单比特采样使能/禁用宏别名
#define __HAL_UART_ONEBIT_ENABLE        __HAL_UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define __HAL_UART_ONEBIT_DISABLE       __HAL_UART_ONE_BIT_SAMPLE_DISABLE // 禁用单比特采样

// UART波特率计算相关宏别名（16倍过采样）
#define __DIV_SAMPLING16                UART_DIV_SAMPLING16 // 除法因子
#define __DIVMANT_SAMPLING16            UART_DIVMANT_SAMPLING16 // 除法整数部分
#define __DIVFRAQ_SAMPLING16            UART_DIVFRAQ_SAMPLING16 // 除法小数部分
#define __UART_BRR_SAMPLING16           UART_BRR_SAMPLING16 // BRR寄存器值

// UART波特率计算相关宏别名（8倍过采样）
#define __DIV_SAMPLING8                 UART_DIV_SAMPLING8 // 除法因子
#define __DIVMANT_SAMPLING8             UART_DIVMANT_SAMPLING8 // 除法整数部分
#define __DIVFRAQ_SAMPLING8             UART_DIVFRAQ_SAMPLING8 // 除法小数部分
#define __UART_BRR_SAMPLING8            UART_BRR_SAMPLING8 // BRR寄存器值

// LPUART（低功耗UART）波特率计算宏别名
#define __DIV_LPUART                    UART_DIV_LPUART

// UART唤醒方式定义别名
#define UART_WAKEUPMETHODE_IDLELINE     UART_WAKEUPMETHOD_IDLELINE // 空闲线路唤醒
#define UART_WAKEUPMETHODE_ADDRESSMARK  UART_WAKEUPMETHOD_ADDRESSMARK // 地址标记唤醒

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Defines HAL USART Aliased Defines maintained for legacy purpose
  * @{
  */

// USART（通用同步/异步收发传输器）相关配置别名
#define USART_CLOCK_DISABLED            USART_CLOCK_DISABLE // 禁用时钟
#define USART_CLOCK_ENABLED             USART_CLOCK_ENABLE // 使能时钟

#define USARTNACK_ENABLED               USART_NACK_ENABLE // 使能NACK
#define USARTNACK_DISABLED              USART_NACK_DISABLE // 禁用NACK
/**
  * @}
  */

/** @defgroup HAL_WWDG_Aliased_Defines HAL WWDG Aliased Defines maintained for legacy purpose
  * @{
  */
// WWDG（窗口看门狗）寄存器基地址别名
#define CFR_BASE                    WWDG_CFR_BASE

/**
  * @}
  */

/** @defgroup HAL_CAN_Aliased_Defines HAL CAN Aliased Defines maintained for legacy purpose
  * @{
  */
// CAN（控制器局域网）相关定义别名
#define CAN_FilterFIFO0             CAN_FILTER_FIFO0 // 滤波器FIFO0
#define CAN_FilterFIFO1             CAN_FILTER_FIFO1 // 滤波器FIFO1
#define CAN_IT_RQCP0                CAN_IT_TME // 发送邮箱0请求完成中断
#define CAN_IT_RQCP1                CAN_IT_TME // 发送邮箱1请求完成中断
#define CAN_IT_RQCP2                CAN_IT_TME // 发送邮箱2请求完成中断
#define INAK_TIMEOUT                CAN_TIMEOUT_VALUE // 初始化超时
#define SLAK_TIMEOUT                CAN_TIMEOUT_VALUE // 睡眠超时
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

// ETH（以太网）相关定义别名
#define VLAN_TAG                ETH_VLAN_TAG // VLAN标签
#define MIN_ETH_PAYLOAD         ETH_MIN_ETH_PAYLOAD // 最小以太网负载
#define MAX_ETH_PAYLOAD         ETH_MAX_ETH_PAYLOAD // 最大以太网负载
#define JUMBO_FRAME_PAYLOAD     ETH_JUMBO_FRAME_PAYLOAD // 巨帧负载
#define MACMIIAR_CR_MASK        ETH_MACMIIAR_CR_MASK // MII地址寄存器时钟范围掩码
#define MACCR_CLEAR_MASK        ETH_MACCR_CLEAR_MASK // MAC配置寄存器清除掩码
#define MACFCR_CLEAR_MASK       ETH_MACFCR_CLEAR_MASK // 流控寄存器清除掩码
#define DMAOMR_CLEAR_MASK       ETH_DMAOMR_CLEAR_MASK // DMA操作模式寄存器清除掩码

// 以太网MAC MMC寄存器地址定义
#define ETH_MMCCR              0x00000100U // MMC控制寄存器
#define ETH_MMCRIR             0x00000104U // MMC接收中断寄存器
#define ETH_MMCTIR             0x00000108U // MMC发送中断寄存器
#define ETH_MMCRIMR            0x0000010CU // MMC接收中断掩码寄存器
#define ETH_MMCTIMR            0x00000110U // MMC发送中断掩码寄存器
#define ETH_MMCTGFSCCR         0x0000014CU // MMC发送良好单播帧计数器
#define ETH_MMCTGFMSCCR        0x00000150U // MMC发送良好多播帧计数器
#define ETH_MMCTGFCR           0x00000168U // MMC发送良好帧计数器
#define ETH_MMCRFCECR          0x00000194U // MMC接收FIFO错误计数器
#define ETH_MMCRFAECR          0x00000198U // MMC接收对齐错误计数器
#define ETH_MMCRGUFCR          0x000001C4U // MMC接收良好单播帧计数器

// 以太网MAC状态标志位定义
#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* 发送FIFO满 */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* 发送FIFO非空 */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* 发送FIFO写活动 */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* 发送FIFO读状态: 空闲 */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* 发送FIFO读状态: 读取 (正在传输数据到MAC发送器) */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* 发送FIFO读状态: 等待来自MAC发送器的发送状态 */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* 发送FIFO读状态: 正在写入接收到的发送状态或刷新发送FIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC发送器处于暂停状态 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC发送帧控制器: 空闲 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC发送帧控制器: 等待上一帧状态或IFG/退避时间结束 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC发送帧控制器: 生成并发送暂停控制帧 (全双工模式) */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC发送帧控制器: 正在传输输入帧以进行发送 */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII发送引擎活动 */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* 接收FIFO填充级别: 空 */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* 接收FIFO填充级别: 低于流控去激活阈值 */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* 接收FIFO填充级别: 高于流控激活阈值 */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* 接收FIFO填充级别: 满 */
#if defined(STM32F1)
#else
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* 接收FIFO读控制器空闲状态 */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* 接收FIFO读控制器正在读取帧数据 */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* 接收FIFO读控制器正在读取帧状态 (或时间戳) */
#endif
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* 接收FIFO读控制器正在刷新帧数据和状态 */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* 接收FIFO写控制器活动 */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC小FIFO读/写控制器不活动 */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC小FIFO读控制器活动 */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC小FIFO写控制器活动 */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC小FIFO读/写控制器活动 */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII接收协议引擎活动 */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* 发送包配置结构体定义 */

/**
  * @}
  */
