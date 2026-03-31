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

