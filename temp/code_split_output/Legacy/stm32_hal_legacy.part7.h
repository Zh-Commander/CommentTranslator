#define OPAMP_SEC_NONINVERTINGINPUT_VP0       OPAMP_SEC_NONINVERTINGINPUT_IO0  ///< 第二运放同相输入VP0，映射到IO0引脚
#define OPAMP_SEC_NONINVERTINGINPUT_VP1       OPAMP_SEC_NONINVERTINGINPUT_IO1  ///< 第二运放同相输入VP1，映射到IO1引脚
#define OPAMP_SEC_NONINVERTINGINPUT_VP2       OPAMP_SEC_NONINVERTINGINPUT_IO2  ///< 第二运放同相输入VP2，映射到IO2引脚
#define OPAMP_SEC_NONINVERTINGINPUT_VP3       OPAMP_SEC_NONINVERTINGINPUT_IO3  ///< 第二运放同相输入VP3，映射到IO3引脚

#define OPAMP_INVERTINGINPUT_VM0              OPAMP_INVERTINGINPUT_IO0         ///< 运放反相输入VM0，映射到IO0引脚
#define OPAMP_INVERTINGINPUT_VM1              OPAMP_INVERTINGINPUT_IO1         ///< 运放反相输入VM1，映射到IO1引脚

#define IOPAMP_INVERTINGINPUT_VM0             OPAMP_INVERTINGINPUT_IO0         ///< 内部运放反相输入VM0，映射到IO0引脚
#define IOPAMP_INVERTINGINPUT_VM1             OPAMP_INVERTINGINPUT_IO1         ///< 内部运放反相输入VM1，映射到IO1引脚

#define OPAMP_SEC_INVERTINGINPUT_VM0          OPAMP_SEC_INVERTINGINPUT_IO0     ///< 第二运放反相输入VM0，映射到IO0引脚
#define OPAMP_SEC_INVERTINGINPUT_VM1          OPAMP_SEC_INVERTINGINPUT_IO1     ///< 第二运放反相输入VM1，映射到IO1引脚

#define OPAMP_INVERTINGINPUT_VINM             OPAMP_SEC_INVERTINGINPUT_IO1     ///< 运放反相输入VINM，映射到第二运放反相输入IO1引脚

#define OPAMP_PGACONNECT_NO                   OPAMP_PGA_CONNECT_INVERTINGINPUT_NO   ///< PGA（可编程增益放大器）不连接反相输入
#define OPAMP_PGACONNECT_VM0                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO0  ///< PGA连接反相输入VM0
#define OPAMP_PGACONNECT_VM1                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO1  ///< PGA连接反相输入VM1

#if defined(STM32L1) || defined(STM32L4) || defined(STM32L5) || defined(STM32H7) || defined(STM32G4) || defined(STM32U5)
#define HAL_OPAMP_MSP_INIT_CB_ID       HAL_OPAMP_MSPINIT_CB_ID                 ///< 运放MSP初始化回调ID
#define HAL_OPAMP_MSP_DEINIT_CB_ID     HAL_OPAMP_MSPDEINIT_CB_ID               ///< 运放MSP反初始化回调ID
#endif

#if defined(STM32L4) || defined(STM32L5)
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALPOWER     ///< 运放正常功耗模式
#elif defined(STM32G4)
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALSPEED     ///< 运放正常速度模式
#endif

/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Defines HAL I2S Aliased Defines maintained for legacy purpose
  * @{
  */
#define I2S_STANDARD_PHILLIPS      I2S_STANDARD_PHILIPS                       ///< I2S标准：飞利浦标准（旧版拼写，为兼容性保留）

#if defined(STM32H7)
#define I2S_IT_TXE               I2S_IT_TXP                                   ///< I2S发送中断（旧版定义，映射到发送完成中断）
#define I2S_IT_RXNE              I2S_IT_RXP                                   ///< I2S接收中断（旧版定义，映射到接收完成中断）

#define I2S_FLAG_TXE             I2S_FLAG_TXP                                 ///< I2S发送标志（旧版定义，映射到发送完成标志）
#define I2S_FLAG_RXNE            I2S_FLAG_RXP                                 ///< I2S接收标志（旧版定义，映射到接收完成标志）
#endif

#if defined(STM32F7)
#define I2S_CLOCK_SYSCLK           I2S_CLOCK_PLL                              ///< I2S时钟源：系统时钟（旧版定义，映射到PLL时钟）
#endif
/**
  * @}
  */

/** @defgroup HAL_PCCARD_Aliased_Defines HAL PCCARD Aliased Defines maintained for legacy purpose
  * @{
  */

/* Compact Flash-ATA寄存器描述 */
#define CF_DATA                       ATA_DATA                                 ///< CF-ATA数据寄存器
#define CF_SECTOR_COUNT               ATA_SECTOR_COUNT                         ///< CF-ATA扇区计数寄存器
#define CF_SECTOR_NUMBER              ATA_SECTOR_NUMBER                        ///< CF-ATA扇区号寄存器
#define CF_CYLINDER_LOW               ATA_CYLINDER_LOW                         ///< CF-ATA柱面低字节寄存器
#define CF_CYLINDER_HIGH              ATA_CYLINDER_HIGH                        ///< CF-ATA柱面高字节寄存器
#define CF_CARD_HEAD                  ATA_CARD_HEAD                            ///< CF-ATA卡头寄存器
#define CF_STATUS_CMD                 ATA_STATUS_CMD                           ///< CF-ATA状态/命令寄存器
#define CF_STATUS_CMD_ALTERNATE       ATA_STATUS_CMD_ALTERNATE                 ///< CF-ATA备用状态/命令寄存器
#define CF_COMMON_DATA_AREA           ATA_COMMON_DATA_AREA                     ///< CF-ATA公共数据区域

/* Compact Flash-ATA命令 */
#define CF_READ_SECTOR_CMD            ATA_READ_SECTOR_CMD                     ///< CF-ATA读扇区命令
#define CF_WRITE_SECTOR_CMD           ATA_WRITE_SECTOR_CMD                    ///< CF-ATA写扇区命令
#define CF_ERASE_SECTOR_CMD           ATA_ERASE_SECTOR_CMD                    ///< CF-ATA擦除扇区命令
#define CF_IDENTIFY_CMD               ATA_IDENTIFY_CMD                        ///< CF-ATA识别命令

#define PCCARD_StatusTypedef          HAL_PCCARD_StatusTypeDef                ///< PCCARD状态类型定义（旧版定义，为兼容性保留）
#define PCCARD_SUCCESS                HAL_PCCARD_STATUS_SUCCESS               ///< PCCARD操作成功（旧版定义）
#define PCCARD_ONGOING                HAL_PCCARD_STATUS_ONGOING               ///< PCCARD操作进行中（旧版定义）
#define PCCARD_ERROR                  HAL_PCCARD_STATUS_ERROR                 ///< PCCARD操作错误（旧版定义）
#define PCCARD_TIMEOUT                HAL_PCCARD_STATUS_TIMEOUT               ///< PCCARD操作超时（旧版定义）
/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Defines HAL RTC Aliased Defines maintained for legacy purpose
  * @{
  */

#define FORMAT_BIN                  RTC_FORMAT_BIN                            ///< RTC格式：二进制格式（旧版定义）
#define FORMAT_BCD                  RTC_FORMAT_BCD                            ///< RTC格式：BCD格式（旧版定义）

#define RTC_ALARMSUBSECONDMASK_None     RTC_ALARMSUBSECONDMASK_NONE            ///< RTC报警子秒掩码：无掩码（旧版定义）
#define RTC_TAMPERERASEBACKUP_DISABLED  RTC_TAMPER_ERASE_BACKUP_DISABLE        ///< RTC篡改检测擦除备份寄存器：禁用（旧版定义）
#define RTC_TAMPERMASK_FLAG_DISABLED    RTC_TAMPERMASK_FLAG_DISABLE            ///< RTC篡改检测掩码标志：禁用（旧版定义）
#define RTC_TAMPERMASK_FLAG_ENABLED     RTC_TAMPERMASK_FLAG_ENABLE             ///< RTC篡改检测掩码标志：使能（旧版定义）

#define RTC_MASKTAMPERFLAG_DISABLED     RTC_TAMPERMASK_FLAG_DISABLE            ///< RTC掩码篡改标志：禁用（旧版定义）
#define RTC_MASKTAMPERFLAG_ENABLED      RTC_TAMPERMASK_FLAG_ENABLE             ///< RTC掩码篡改标志：使能（旧版定义）
#define RTC_TAMPERERASEBACKUP_ENABLED   RTC_TAMPER_ERASE_BACKUP_ENABLE         ///< RTC篡改检测擦除备份寄存器：使能（旧版定义）
#define RTC_TAMPER1_2_INTERRUPT         RTC_ALL_TAMPER_INTERRUPT               ///< RTC篡改检测1和2中断（旧版定义，映射到所有篡改中断）
#define RTC_TAMPER1_2_3_INTERRUPT       RTC_ALL_TAMPER_INTERRUPT               ///< RTC篡改检测1、2和3中断（旧版定义，映射到所有篡改中断）

#define RTC_TIMESTAMPPIN_PC13  RTC_TIMESTAMPPIN_DEFAULT                        ///< RTC时间戳引脚：默认引脚PC13（旧版定义）
#define RTC_TIMESTAMPPIN_PA0   RTC_TIMESTAMPPIN_POS1                           ///< RTC时间戳引脚：位置1引脚PA0（旧版定义）
#define RTC_TIMESTAMPPIN_PI8   RTC_TIMESTAMPPIN_POS1                           ///< RTC时间戳引脚：位置1引脚PI8（旧版定义）
#define RTC_TIMESTAMPPIN_PC1   RTC_TIMESTAMPPIN_POS2                           ///< RTC时间戳引脚：位置2引脚PC1（旧版定义）

#define RTC_OUTPUT_REMAP_PC13  RTC_OUTPUT_REMAP_NONE                           ///< RTC输出重映射：无重映射（PC13）（旧版定义）
#define RTC_OUTPUT_REMAP_PB14  RTC_OUTPUT_REMAP_POS1                           ///< RTC输出重映射：位置1（PB14）（旧版定义）
#define RTC_OUTPUT_REMAP_PB2   RTC_OUTPUT_REMAP_POS1                           ///< RTC输出重映射：位置1（PB2）（旧版定义）

#define RTC_TAMPERPIN_PC13 RTC_TAMPERPIN_DEFAULT                               ///< RTC篡改检测引脚：默认引脚PC13（旧版定义）
#define RTC_TAMPERPIN_PA0  RTC_TAMPERPIN_POS1                                  ///< RTC篡改检测引脚：位置1引脚PA0（旧版定义）
#define RTC_TAMPERPIN_PI8  RTC_TAMPERPIN_POS1                                  ///< RTC篡改检测引脚：位置1引脚PI8（旧版定义）

#if defined(STM32H5) || defined(STM32H7RS)
#define TAMP_SECRETDEVICE_ERASE_NONE        TAMP_DEVICESECRETS_ERASE_NONE      ///< 篡改检测秘密设备擦除：无擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_BKP_SRAM    TAMP_DEVICESECRETS_ERASE_BKPSRAM   ///< 篡改检测秘密设备擦除：备份SRAM擦除（旧版定义）
#endif /* STM32H5 || STM32H7RS */

#if defined(STM32WBA)
#define TAMP_SECRETDEVICE_ERASE_NONE            TAMP_DEVICESECRETS_ERASE_NONE          ///< 篡改检测秘密设备擦除：无擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_SRAM2           TAMP_DEVICESECRETS_ERASE_SRAM2         ///< 篡改检测秘密设备擦除：SRAM2擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_RHUK            TAMP_DEVICESECRETS_ERASE_RHUK          ///< 篡改检测秘密设备擦除：RHUK擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_ICACHE          TAMP_DEVICESECRETS_ERASE_ICACHE        ///< 篡改检测秘密设备擦除：指令缓存擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_SAES_AES_HASH   TAMP_DEVICESECRETS_ERASE_SAES_AES_HASH ///< 篡改检测秘密设备擦除：SAES/AES/HASH擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_PKA_SRAM        TAMP_DEVICESECRETS_ERASE_PKA_SRAM      ///< 篡改检测秘密设备擦除：PKA SRAM擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_ALL             TAMP_DEVICESECRETS_ERASE_ALL           ///< 篡改检测秘密设备擦除：全部擦除（旧版定义）
#endif /* STM32WBA */

#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
#define TAMP_SECRETDEVICE_ERASE_DISABLE     TAMP_DEVICESECRETS_ERASE_NONE       ///< 篡改检测秘密设备擦除：禁用（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_ENABLE      TAMP_SECRETDEVICE_ERASE_ALL         ///< 篡改检测秘密设备擦除：使能（旧版定义）
#endif /* STM32H5 || STM32WBA || STM32H7RS */

#if defined(STM32F7)
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_ENABLE_BITS_MASK                 ///< RTC篡改检测使能位掩码（旧版定义）
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_IT_ENABLE_BITS_MASK              ///< RTC篡改检测中断使能位掩码（旧版定义）
#endif /* STM32F7 */

#if defined(STM32H7)
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_X                                ///< RTC篡改检测使能位（旧版定义）
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_X_INTERRUPT                      ///< RTC篡改检测中断使能位（旧版定义）
#endif /* STM32H7 */

#if defined(STM32F7) || defined(STM32H7) || defined(STM32L0)
#define RTC_TAMPER1_INTERRUPT      RTC_IT_TAMP1                                ///< RTC篡改检测1中断（旧版定义）
#define RTC_TAMPER2_INTERRUPT      RTC_IT_TAMP2                                ///< RTC篡改检测2中断（旧版定义）
#define RTC_TAMPER3_INTERRUPT      RTC_IT_TAMP3                                ///< RTC篡改检测3中断（旧版定义）
#define RTC_ALL_TAMPER_INTERRUPT   RTC_IT_TAMP                                 ///< RTC所有篡改检测中断（旧版定义）
#endif /* STM32F7 || STM32H7 || STM32L0 */

/**
  * @}
  */


/** @defgroup HAL_SMARTCARD_Aliased_Defines HAL SMARTCARD Aliased Defines maintained for legacy purpose
  * @{
  */
#define SMARTCARD_NACK_ENABLED                  SMARTCARD_NACK_ENABLE           ///< 智能卡NACK（非确认）使能（旧版定义）
#define SMARTCARD_NACK_DISABLED                 SMARTCARD_NACK_DISABLE          ///< 智能卡NACK（非确认）禁用（旧版定义）

#define SMARTCARD_ONEBIT_SAMPLING_DISABLED      SMARTCARD_ONE_BIT_SAMPLE_DISABLE  ///< 智能卡单比特采样禁用（旧版定义）
#define SMARTCARD_ONEBIT_SAMPLING_ENABLED       SMARTCARD_ONE_BIT_SAMPLE_ENABLE   ///< 智能卡单比特采样使能（旧版定义）
#define SMARTCARD_ONEBIT_SAMPLING_DISABLE       SMARTCARD_ONE_BIT_SAMPLE_DISABLE  ///< 智能卡单比特采样禁用（旧版定义）
#define SMARTCARD_ONEBIT_SAMPLING_ENABLE        SMARTCARD_ONE_BIT_SAMPLE_ENABLE   ///< 智能卡单比特采样使能（旧版定义）

#define SMARTCARD_TIMEOUT_DISABLED              SMARTCARD_TIMEOUT_DISABLE       ///< 智能卡超时禁用（旧版定义）
#define SMARTCARD_TIMEOUT_ENABLED               SMARTCARD_TIMEOUT_ENABLE        ///< 智能卡超时使能（旧版定义）

#define SMARTCARD_LASTBIT_DISABLED              SMARTCARD_LASTBIT_DISABLE       ///< 智能卡最后一位禁用（旧版定义）
#define SMARTCARD_LASTBIT_ENABLED               SMARTCARD_LASTBIT_ENABLE        ///< 智能卡最后一位使能（旧版定义）
/**
  * @}
  */


/** @defgroup HAL_SMBUS_Aliased_Defines HAL SMBUS Aliased Defines maintained for legacy purpose
  * @{
  */
#define SMBUS_DUALADDRESS_DISABLED      SMBUS_DUALADDRESS_DISABLE               ///< SMBUS双地址模式禁用（旧版定义）
#define SMBUS_DUALADDRESS_ENABLED       SMBUS_DUALADDRESS_ENABLE                ///< SMBUS双地址模式使能（旧版定义）
#define SMBUS_GENERALCALL_DISABLED      SMBUS_GENERALCALL_DISABLE               ///< SMBUS广播呼叫禁用（旧版定义）
#define SMBUS_GENERALCALL_ENABLED       SMBUS_GENERALCALL_ENABLE                ///< SMBUS广播呼叫使能（旧版定义）
#define SMBUS_NOSTRETCH_DISABLED        SMBUS_NOSTRETCH_DISABLE                 ///< SMBUS时钟延展禁用（旧版定义）
#define SMBUS_NOSTRETCH_ENABLED         SMBUS_NOSTRETCH_ENABLE                  ///< SMBUS时钟延展使能（旧版定义）
#define SMBUS_ANALOGFILTER_ENABLED      SMBUS_ANALOGFILTER_ENABLE               ///< SMBUS模拟滤波器使能（旧版定义）
#define SMBUS_ANALOGFILTER_DISABLED     SMBUS_ANALOGFILTER_DISABLE              ///< SMBUS模拟滤波器禁用（旧版定义）
#define SMBUS_PEC_DISABLED              SMBUS_PEC_DISABLE                       ///< SMBUS数据包错误检查（PEC）禁用（旧版定义）
#define SMBUS_PEC_ENABLED               SMBUS_PEC_ENABLE                        ///< SMBUS数据包错误检查（PEC）使能（旧版定义）
#define HAL_SMBUS_STATE_SLAVE_LISTEN    HAL_SMBUS_STATE_LISTEN                  ///< SMBUS从机监听状态（旧版定义）
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Defines HAL SPI Aliased Defines maintained for legacy purpose
  * @{
  */
#define SPI_TIMODE_DISABLED             SPI_TIMODE_DISABLE                     ///< SPI TI模式禁用（旧版定义）
#define SPI_TIMODE_ENABLED              SPI_TIMODE_ENABLE                      ///< SPI TI模式使能（旧版定义）

#define SPI_CRCCALCULATION_DISABLED     SPI_CRCCALCULATION_DISABLE             ///< SPI CRC计算禁用（旧版定义）
#define SPI_CRCCALCULATION_ENABLED      SPI_CRCCALCULATION_ENABLE              ///< SPI CRC计算使能（旧版定义）

#define SPI_NSS_PULSE_DISABLED          SPI_NSS_PULSE_DISABLE                  ///< SPI NSS脉冲禁用（旧版定义）
#define SPI_NSS_PULSE_ENABLED           SPI_NSS_PULSE_ENABLE                   ///< SPI NSS脉冲使能（旧版定义）

#if defined(STM32H7)

#define SPI_FLAG_TXE                    SPI_FLAG_TXP                           ///< SPI发送标志（旧版定义，映射到发送完成标志）
#define SPI_FLAG_RXNE                   SPI_FLAG_RXP                           ///< SPI接收标志（旧版定义，映射到接收完成标志）

#define SPI_IT_TXE                      SPI_IT_TXP                             ///< SPI发送中断（旧版定义，映射到发送完成中断）
#define SPI_IT_RXNE                     SPI_IT_RXP                             ///< SPI接收中断（旧版定义，映射到接收完成中断）

#define SPI_FRLVL_EMPTY                 SPI_RX_FIFO_0PACKET                    ///< SPI接收FIFO空（旧版定义，映射到0包）
#define SPI_FRLVL_QUARTER_FULL          SPI_RX_FIFO_1PACKET                    ///< SPI接收FIFO四分之一满（旧版定义，映射到1包）
#define SPI_FRLVL_HALF_FULL             SPI_RX_FIFO_2PACKET                    ///< SPI接收FIFO半满（旧版定义，映射到2包）
#define SPI_FRLVL_FULL                  SPI_RX_FIFO_3PACKET                    ///< SPI接收FIFO全满（旧版定义，映射到3包）

#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK                    ///< 定时器捕获/比较使能位掩码（旧版定义）
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK                   ///< 定时器捕获/比较互补输出使能位掩码（旧版定义）