
#define I2S_FLAG_TXE             I2S_FLAG_TXP
#define I2S_FLAG_RXNE            I2S_FLAG_RXP
#endif

#if defined(STM32F7)
#define I2S_CLOCK_SYSCLK           I2S_CLOCK_PLL
#endif
/**
  * @}
  */

/** @defgroup HAL_PCCARD_Aliased_Defines HAL PCCARD Aliased Defines maintained for legacy purpose
  * @{
  */

/* Compact Flash-ATA registers description */
#define CF_DATA                       ATA_DATA
#define CF_SECTOR_COUNT               ATA_SECTOR_COUNT
#define CF_SECTOR_NUMBER              ATA_SECTOR_NUMBER
#define CF_CYLINDER_LOW               ATA_CYLINDER_LOW
#define CF_CYLINDER_HIGH              ATA_CYLINDER_HIGH
#define CF_CARD_HEAD                  ATA_CARD_HEAD
#define CF_STATUS_CMD                 ATA_STATUS_CMD
#define CF_STATUS_CMD_ALTERNATE       ATA_STATUS_CMD_ALTERNATE
#define CF_COMMON_DATA_AREA           ATA_COMMON_DATA_AREA

/* Compact Flash-ATA commands */
#define CF_READ_SECTOR_CMD            ATA_READ_SECTOR_CMD
#define CF_WRITE_SECTOR_CMD           ATA_WRITE_SECTOR_CMD
#define CF_ERASE_SECTOR_CMD           ATA_ERASE_SECTOR_CMD
#define CF_IDENTIFY_CMD               ATA_IDENTIFY_CMD

#define PCCARD_StatusTypedef          HAL_PCCARD_StatusTypeDef
#define PCCARD_SUCCESS                HAL_PCCARD_STATUS_SUCCESS
#define PCCARD_ONGOING                HAL_PCCARD_STATUS_ONGOING
#define PCCARD_ERROR                  HAL_PCCARD_STATUS_ERROR
#define PCCARD_TIMEOUT                HAL_PCCARD_STATUS_TIMEOUT
/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Defines HAL RTC Aliased Defines maintained for legacy purpose
  * @{
  */

#define FORMAT_BIN                  RTC_FORMAT_BIN
#define FORMAT_BCD                  RTC_FORMAT_BCD

#define RTC_ALARMSUBSECONDMASK_None     RTC_ALARMSUBSECONDMASK_NONE
#define RTC_TAMPERERASEBACKUP_DISABLED  RTC_TAMPER_ERASE_BACKUP_DISABLE
#define RTC_TAMPERMASK_FLAG_DISABLED    RTC_TAMPERMASK_FLAG_DISABLE
#define RTC_TAMPERMASK_FLAG_ENABLED     RTC_TAMPERMASK_FLAG_ENABLE

#define RTC_MASKTAMPERFLAG_DISABLED     RTC_TAMPERMASK_FLAG_DISABLE
#define RTC_MASKTAMPERFLAG_ENABLED      RTC_TAMPERMASK_FLAG_ENABLE
#define RTC_TAMPERERASEBACKUP_ENABLED   RTC_TAMPER_ERASE_BACKUP_ENABLE
#define RTC_TAMPER1_2_INTERRUPT         RTC_ALL_TAMPER_INTERRUPT
#define RTC_TAMPER1_2_3_INTERRUPT       RTC_ALL_TAMPER_INTERRUPT

#define RTC_TIMESTAMPPIN_PC13  RTC_TIMESTAMPPIN_DEFAULT
#define RTC_TIMESTAMPPIN_PA0   RTC_TIMESTAMPPIN_POS1
#define RTC_TIMESTAMPPIN_PI8   RTC_TIMESTAMPPIN_POS1
#define RTC_TIMESTAMPPIN_PC1   RTC_TIMESTAMPPIN_POS2

#define RTC_OUTPUT_REMAP_PC13  RTC_OUTPUT_REMAP_NONE
#define RTC_OUTPUT_REMAP_PB14  RTC_OUTPUT_REMAP_POS1
#define RTC_OUTPUT_REMAP_PB2   RTC_OUTPUT_REMAP_POS1

#define RTC_TAMPERPIN_PC13 RTC_TAMPERPIN_DEFAULT
#define RTC_TAMPERPIN_PA0  RTC_TAMPERPIN_POS1
#define RTC_TAMPERPIN_PI8  RTC_TAMPERPIN_POS1

#if defined(STM32H5) || defined(STM32H7RS)
#define TAMP_SECRETDEVICE_ERASE_NONE        TAMP_DEVICESECRETS_ERASE_NONE
#define TAMP_SECRETDEVICE_ERASE_BKP_SRAM    TAMP_DEVICESECRETS_ERASE_BKPSRAM
#endif /* STM32H5 || STM32H7RS */

#if defined(STM32WBA)
#define TAMP_SECRETDEVICE_ERASE_NONE            TAMP_DEVICESECRETS_ERASE_NONE
#define TAMP_SECRETDEVICE_ERASE_SRAM2           TAMP_DEVICESECRETS_ERASE_SRAM2
#define TAMP_SECRETDEVICE_ERASE_RHUK            TAMP_DEVICESECRETS_ERASE_RHUK
#define TAMP_SECRETDEVICE_ERASE_ICACHE          TAMP_DEVICESECRETS_ERASE_ICACHE
#define TAMP_SECRETDEVICE_ERASE_SAES_AES_HASH   TAMP_DEVICESECRETS_ERASE_SAES_AES_HASH
#define TAMP_SECRETDEVICE_ERASE_PKA_SRAM        TAMP_DEVICESECRETS_ERASE_PKA_SRAM
#define TAMP_SECRETDEVICE_ERASE_ALL             TAMP_DEVICESECRETS_ERASE_ALL
#endif /* STM32WBA */

#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
#define TAMP_SECRETDEVICE_ERASE_DISABLE     TAMP_DEVICESECRETS_ERASE_NONE
#define TAMP_SECRETDEVICE_ERASE_ENABLE      TAMP_SECRETDEVICE_ERASE_ALL
#endif /* STM32H5 || STM32WBA || STM32H7RS */

#if defined(STM32F7)
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_ENABLE_BITS_MASK
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_IT_ENABLE_BITS_MASK
#endif /* STM32F7 */

#if defined(STM32H7)
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_X
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_X_INTERRUPT
#endif /* STM32H7 */

#if defined(STM32F7) || defined(STM32H7) || defined(STM32L0)
#define RTC_TAMPER1_INTERRUPT      RTC_IT_TAMP1
#define RTC_TAMPER2_INTERRUPT      RTC_IT_TAMP2
#define RTC_TAMPER3_INTERRUPT      RTC_IT_TAMP3
#define RTC_ALL_TAMPER_INTERRUPT   RTC_IT_TAMP
#endif /* STM32F7 || STM32H7 || STM32L0 */

/**
  * @}
  */


/** @defgroup HAL_SMARTCARD_Aliased_Defines HAL SMARTCARD Aliased Defines maintained for legacy purpose
  * @{
  */
#define SMARTCARD_NACK_ENABLED                  SMARTCARD_NACK_ENABLE
#define SMARTCARD_NACK_DISABLED                 SMARTCARD_NACK_DISABLE

#define SMARTCARD_ONEBIT_SAMPLING_DISABLED      SMARTCARD_ONE_BIT_SAMPLE_DISABLE
#define SMARTCARD_ONEBIT_SAMPLING_ENABLED       SMARTCARD_ONE_BIT_SAMPLE_ENABLE
#define SMARTCARD_ONEBIT_SAMPLING_DISABLE       SMARTCARD_ONE_BIT_SAMPLE_DISABLE
#define SMARTCARD_ONEBIT_SAMPLING_ENABLE        SMARTCARD_ONE_BIT_SAMPLE_ENABLE

#define SMARTCARD_TIMEOUT_DISABLED              SMARTCARD_TIMEOUT_DISABLE
#define SMARTCARD_TIMEOUT_ENABLED               SMARTCARD_TIMEOUT_ENABLE

#define SMARTCARD_LASTBIT_DISABLED              SMARTCARD_LASTBIT_DISABLE
#define SMARTCARD_LASTBIT_ENABLED               SMARTCARD_LASTBIT_ENABLE
/**
  * @}
  */


/** @defgroup HAL_SMBUS_Aliased_Defines HAL SMBUS Aliased Defines maintained for legacy purpose
  * @{
  */
#define SMBUS_DUALADDRESS_DISABLED      SMBUS_DUALADDRESS_DISABLE
#define SMBUS_DUALADDRESS_ENABLED       SMBUS_DUALADDRESS_ENABLE
#define SMBUS_GENERALCALL_DISABLED      SMBUS_GENERALCALL_DISABLE
#define SMBUS_GENERALCALL_ENABLED       SMBUS_GENERALCALL_ENABLE
#define SMBUS_NOSTRETCH_DISABLED        SMBUS_NOSTRETCH_DISABLE
#define SMBUS_NOSTRETCH_ENABLED         SMBUS_NOSTRETCH_ENABLE
#define SMBUS_ANALOGFILTER_ENABLED      SMBUS_ANALOGFILTER_ENABLE
#define SMBUS_ANALOGFILTER_DISABLED     SMBUS_ANALOGFILTER_DISABLE
#define SMBUS_PEC_DISABLED              SMBUS_PEC_DISABLE
#define SMBUS_PEC_ENABLED               SMBUS_PEC_ENABLE
#define HAL_SMBUS_STATE_SLAVE_LISTEN    HAL_SMBUS_STATE_LISTEN
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Defines HAL SPI Aliased Defines maintained for legacy purpose
  * @{
  */
#define SPI_TIMODE_DISABLED             SPI_TIMODE_DISABLE
#define SPI_TIMODE_ENABLED              SPI_TIMODE_ENABLE

#define SPI_CRCCALCULATION_DISABLED     SPI_CRCCALCULATION_DISABLE
#define SPI_CRCCALCULATION_ENABLED      SPI_CRCCALCULATION_ENABLE

#define SPI_NSS_PULSE_DISABLED          SPI_NSS_PULSE_DISABLE
#define SPI_NSS_PULSE_ENABLED           SPI_NSS_PULSE_ENABLE

#if defined(STM32H7)

#define SPI_FLAG_TXE                    SPI_FLAG_TXP
#define SPI_FLAG_RXNE                   SPI_FLAG_RXP

#define SPI_IT_TXE                      SPI_IT_TXP
#define SPI_IT_RXNE                     SPI_IT_RXP

#define SPI_FRLVL_EMPTY                 SPI_RX_FIFO_0PACKET
#define SPI_FRLVL_QUARTER_FULL          SPI_RX_FIFO_1PACKET
#define SPI_FRLVL_HALF_FULL             SPI_RX_FIFO_2PACKET
#define SPI_FRLVL_FULL                  SPI_RX_FIFO_3PACKET

#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK

#define TIM_DMABase_CR1                  TIM_DMABASE_CR1
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER
#define TIM_DMABase_SR                   TIM_DMABASE_SR
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3
#define TIM_DMABase_OR                   TIM_DMABASE_OR

#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2

#define TIM_DMABurstLength_1Transfer     TIM_DMABURSTLENGTH_1TRANSFER
#define TIM_DMABurstLength_2Transfers    TIM_DMABURSTLENGTH_2TRANSFERS
#define TIM_DMABurstLength_3Transfers    TIM_DMABURSTLENGTH_3TRANSFERS
#define TIM_DMABurstLength_4Transfers    TIM_DMABURSTLENGTH_4TRANSFERS
#define TIM_DMABurstLength_5Transfers    TIM_DMABURSTLENGTH_5TRANSFERS
#define TIM_DMABurstLength_6Transfers    TIM_DMABURSTLENGTH_6TRANSFERS
#define TIM_DMABurstLength_7Transfers    TIM_DMABURSTLENGTH_7TRANSFERS
#define TIM_DMABurstLength_8Transfers    TIM_DMABURSTLENGTH_8TRANSFERS
#define TIM_DMABurstLength_9Transfers    TIM_DMABURSTLENGTH_9TRANSFERS
#define TIM_DMABurstLength_10Transfers   TIM_DMABURSTLENGTH_10TRANSFERS
#define TIM_DMABurstLength_11Transfers   TIM_DMABURSTLENGTH_11TRANSFERS
#define TIM_DMABurstLength_12Transfers   TIM_DMABURSTLENGTH_12TRANSFERS
#define TIM_DMABurstLength_13Transfers   TIM_DMABURSTLENGTH_13TRANSFERS
#define TIM_DMABurstLength_14Transfers   TIM_DMABURSTLENGTH_14TRANSFERS
#define TIM_DMABurstLength_15Transfers   TIM_DMABURSTLENGTH_15TRANSFERS
#define TIM_DMABurstLength_16Transfers   TIM_DMABURSTLENGTH_16TRANSFERS
#define TIM_DMABurstLength_17Transfers   TIM_DMABURSTLENGTH_17TRANSFERS
#define TIM_DMABurstLength_18Transfers   TIM_DMABURSTLENGTH_18TRANSFERS

#if defined(STM32L0)
#define TIM22_TI1_GPIO1   TIM22_TI1_GPIO
#define TIM22_TI1_GPIO2   TIM22_TI1_GPIO
#endif

#if defined(STM32F3)
#define IS_TIM_HALL_INTERFACE_INSTANCE   IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE
#endif

#if defined(STM32H7)
#define TIM_TIM1_ETR_COMP1_OUT        TIM_TIM1_ETR_COMP1
#define TIM_TIM1_ETR_COMP2_OUT        TIM_TIM1_ETR_COMP2
#define TIM_TIM8_ETR_COMP1_OUT        TIM_TIM8_ETR_COMP1
#define TIM_TIM8_ETR_COMP2_OUT        TIM_TIM8_ETR_COMP2
#define TIM_TIM2_ETR_COMP1_OUT        TIM_TIM2_ETR_COMP1
#define TIM_TIM2_ETR_COMP2_OUT        TIM_TIM2_ETR_COMP2
#define TIM_TIM3_ETR_COMP1_OUT        TIM_TIM3_ETR_COMP1
#define TIM_TIM1_TI1_COMP1_OUT        TIM_TIM1_TI1_COMP1
#define TIM_TIM8_TI1_COMP2_OUT        TIM_TIM8_TI1_COMP2
#define TIM_TIM2_TI4_COMP1_OUT        TIM_TIM2_TI4_COMP1
#define TIM_TIM2_TI4_COMP2_OUT        TIM_TIM2_TI4_COMP2
#define TIM_TIM2_TI4_COMP1COMP2_OUT   TIM_TIM2_TI4_COMP1_COMP2
#define TIM_TIM3_TI1_COMP1_OUT        TIM_TIM3_TI1_COMP1
#define TIM_TIM3_TI1_COMP2_OUT        TIM_TIM3_TI1_COMP2
#define TIM_TIM3_TI1_COMP1COMP2_OUT   TIM_TIM3_TI1_COMP1_COMP2
#endif

#if defined(STM32U5)
#define OCREF_CLEAR_SELECT_Pos       OCREF_CLEAR_SELECT_POS
#define OCREF_CLEAR_SELECT_Msk       OCREF_CLEAR_SELECT_MSK
#endif
/**
  * @}
  */

/** @defgroup HAL_TSC_Aliased_Defines HAL TSC Aliased Defines maintained for legacy purpose
  * @{
  */
#define TSC_SYNC_POL_FALL        TSC_SYNC_POLARITY_FALLING
#define TSC_SYNC_POL_RISE_HIGH   TSC_SYNC_POLARITY_RISING
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Defines HAL UART Aliased Defines maintained for legacy purpose
  * @{
  */
#define UART_ONEBIT_SAMPLING_DISABLED   UART_ONE_BIT_SAMPLE_DISABLE
#define UART_ONEBIT_SAMPLING_ENABLED    UART_ONE_BIT_SAMPLE_ENABLE
#define UART_ONE_BIT_SAMPLE_DISABLED    UART_ONE_BIT_SAMPLE_DISABLE
#define UART_ONE_BIT_SAMPLE_ENABLED     UART_ONE_BIT_SAMPLE_ENABLE

#define __HAL_UART_ONEBIT_ENABLE        __HAL_UART_ONE_BIT_SAMPLE_ENABLE
#define __HAL_UART_ONEBIT_DISABLE       __HAL_UART_ONE_BIT_SAMPLE_DISABLE

#define __DIV_SAMPLING16                UART_DIV_SAMPLING16
#define __DIVMANT_SAMPLING16            UART_DIVMANT_SAMPLING16
#define __DIVFRAQ_SAMPLING16            UART_DIVFRAQ_SAMPLING16
#define __UART_BRR_SAMPLING16           UART_BRR_SAMPLING16

#define __DIV_SAMPLING8                 UART_DIV_SAMPLING8
#define __DIVMANT_SAMPLING8             UART_DIVMANT_SAMPLING8
#define __DIVFRAQ_SAMPLING8             UART_DIVFRAQ_SAMPLING8
#define __UART_BRR_SAMPLING8            UART_BRR_SAMPLING8

#define __DIV_LPUART                    UART_DIV_LPUART

#define UART_WAKEUPMETHODE_IDLELINE     UART_WAKEUPMETHOD_IDLELINE
#define UART_WAKEUPMETHODE_ADDRESSMARK  UART_WAKEUPMETHOD_ADDRESSMARK

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Defines HAL USART Aliased Defines maintained for legacy purpose
  * @{
  */

#define USART_CLOCK_DISABLED            USART_CLOCK_DISABLE
#define USART_CLOCK_ENABLED             USART_CLOCK_ENABLE

#define USARTNACK_ENABLED               USART_NACK_ENABLE
#define USARTNACK_DISABLED              USART_NACK_DISABLE
/**
  * @}
  */

/** @defgroup HAL_WWDG_Aliased_Defines HAL WWDG Aliased Defines maintained for legacy purpose
  * @{
  */
#define CFR_BASE                    WWDG_CFR_BASE

/**
  * @}
  */

/** @defgroup HAL_CAN_Aliased_Defines HAL CAN Aliased Defines maintained for legacy purpose
  * @{
  */
#define CAN_FilterFIFO0             CAN_FILTER_FIFO0
#define CAN_FilterFIFO1             CAN_FILTER_FIFO1
#define CAN_IT_RQCP0                CAN_IT_TME
#define CAN_IT_RQCP1                CAN_IT_TME
#define CAN_IT_RQCP2                CAN_IT_TME
#define INAK_TIMEOUT                CAN_TIMEOUT_VALUE
#define SLAK_TIMEOUT                CAN_TIMEOUT_VALUE
#define CAN_TXSTATUS_FAILED         ((uint8_t)0x00U)
#define CAN_TXSTATUS_OK             ((uint8_t)0x01U)
#define CAN_TXSTATUS_PENDING        ((uint8_t)0x02U)

/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Defines HAL ETH Aliased Defines maintained for legacy purpose
  * @{
  */

#define VLAN_TAG                ETH_VLAN_TAG
#define MIN_ETH_PAYLOAD         ETH_MIN_ETH_PAYLOAD
#define MAX_ETH_PAYLOAD         ETH_MAX_ETH_PAYLOAD
#define JUMBO_FRAME_PAYLOAD     ETH_JUMBO_FRAME_PAYLOAD
#define MACMIIAR_CR_MASK        ETH_MACMIIAR_CR_MASK
#define MACCR_CLEAR_MASK        ETH_MACCR_CLEAR_MASK
#define MACFCR_CLEAR_MASK       ETH_MACFCR_CLEAR_MASK
#define DMAOMR_CLEAR_MASK       ETH_DMAOMR_CLEAR_MASK

#define ETH_MMCCR              0x00000100U
#define ETH_MMCRIR             0x00000104U
#define ETH_MMCTIR             0x00000108U
#define ETH_MMCRIMR            0x0000010CU
#define ETH_MMCTIMR            0x00000110U
#define ETH_MMCTGFSCCR         0x0000014CU
#define ETH_MMCTGFMSCCR        0x00000150U
#define ETH_MMCTGFCR           0x00000168U
#define ETH_MMCRFCECR          0x00000194U
#define ETH_MMCRFAECR          0x00000198U
#define ETH_MMCRGUFCR          0x000001C4U

#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* Tx FIFO full */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* Tx FIFO not empty */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* Tx FIFO write active */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* Tx FIFO read status: Idle */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* Tx FIFO read status: Read (transferring data to 
                                                                      the MAC transmitter) */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* Tx FIFO read status: Waiting for TxStatus from 
                                                                      MAC transmitter */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* Tx FIFO read status: Writing the received TxStatus
                                                                      or flushing the TxFIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC transmitter in pause */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC transmit frame controller: Idle */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC transmit frame controller: Waiting for Status 
                                                                   of previous frame or IFG/backoff period to be over */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC transmit frame controller: Generating and 
                                                             transmitting a Pause control frame (in full duplex mode) */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC transmit frame controller: Transferring input 
                                                                      frame for transmission */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII transmit engine active */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* Rx FIFO fill level: empty */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* Rx FIFO fill level: fill-level below flow-control 
                                                              de-activate threshold */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* Rx FIFO fill level: fill-level above flow-control 
                                                              activate threshold */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* Rx FIFO fill level: full */
#if defined(STM32F1)
#else
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* Rx FIFO read controller IDLE state */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* Rx FIFO read controller Reading frame data */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* Rx FIFO read controller Reading frame status 
                                                             (or time-stamp) */
#endif
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* Rx FIFO read controller Flushing the frame data and 
                                                              status */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* Rx FIFO write controller active */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC small FIFO read / write controllers not active */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC small FIFO read controller active */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC small FIFO write controller active */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC small FIFO read / write controllers active */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII receive protocol engine active */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* Transmit Packet Configuration structure definition */

/**
  * @}
  */
