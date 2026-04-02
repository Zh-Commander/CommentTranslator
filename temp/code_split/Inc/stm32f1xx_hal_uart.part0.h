/**
  ******************************************************************************
  * @file    stm32f1xx_hal_uart.h
  * @author  MCD Application Team
  * @brief   Header file of UART HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_HAL_UART_H
#define __STM32F1xx_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup UART_Exported_Types UART Exported Types
  * @{
  */

/**
  * @brief UART Init Structure definition
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
                                           The baud rate is computed using the following formula:
                                           - IntegerDivider = ((PCLKx) / (16 * (huart->Init.BaudRate)))
                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5 */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_Word_Length */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_Stop_Bits */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_Mode */

  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_Hardware_Flow_Control */

  uint32_t OverSampling;              /*!< Specifies whether the Over sampling 8 is enabled or disabled, to achieve higher speed (up to fPCLK/8).
                                           This parameter can be a value of @ref UART_Over_Sampling. This feature is only available
                                           on STM32F100xx family, so OverSampling parameter should always be set to 16. */
} UART_InitTypeDef;

/**
  * @brief HAL UART State structures definition
  * @note  HAL UART State value is a combination of 2 different substates: gState and RxState.
  *        - gState contains UART state information related to global Handle management
  *          and also information related to Tx operations.
  *          gState value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : (Not Used)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral initialized. HAL UART Init function already called)
  *          b4-b3  (not used)
  *             xx : Should be set to 00
  *          b2     Intrinsic process state
  *             0  : Ready
  *             1  : Busy (Peripheral busy with some configuration or internal operations)
  *          b1     (not used)
  *             x  : Should be set to 0
  *          b0     Tx state
  *             0  : Ready (no Tx operation ongoing)
  *             1  : Busy (Tx operation ongoing)
  *        - RxState contains information related to Rx operations.
  *          RxState value coding follow below described bitmap :
  *          b7-b6  (not used)
  *             xx : Should be set to 00
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral initialized)
  *          b4-b2  (not used)
  *            xxx : Should be set to 000
  *          b1     Rx state
  *             0  : Ready (no Rx operation ongoing)
  *             1  : Busy (Rx operation ongoing)
  *          b0     (not used)
  *             x  : Should be set to 0.
  */
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized
                                                   Value is allowed for gState and RxState */
  HAL_UART_STATE_READY             = 0x20U,    /*!< Peripheral Initialized and ready for use
                                                   Value is allowed for gState and RxState */
  HAL_UART_STATE_BUSY              = 0x24U,    /*!< an internal process is ongoing
                                                   Value is allowed for gState only */
  HAL_UART_STATE_BUSY_TX           = 0x21U,    /*!< Data Transmission process is ongoing
                                                   Value is allowed for gState only */
  HAL_UART_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing
                                                   Value is allowed for RxState only */
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    /*!< Data Transmission and Reception process is ongoing
                                                   Not to be used for neither gState nor RxState.
                                                   Value is result of combination (Or) between gState and RxState values */
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    /*!< Timeout state
                                                   Value is allowed for gState only */
  HAL_UART_STATE_ERROR             = 0xE0U     /*!< Error
                                                   Value is allowed for gState only */
} HAL_UART_StateTypeDef;

/**
  * @brief HAL UART Reception type definition
  * @note  HAL UART Reception type value aims to identify which type of Reception is ongoing.
  *        This parameter can be a value of @ref UART_Reception_Type_Values :
  *           HAL_UART_RECEPTION_STANDARD         = 0x00U,
  *           HAL_UART_RECEPTION_TOIDLE           = 0x01U,
  */
typedef uint32_t HAL_UART_RxTypeTypeDef;

/**
  * @brief HAL UART Rx Event type definition
  * @note  HAL UART Rx Event type value aims to identify which type of Event has occurred
  *        leading to call of the RxEvent callback.
  *        This parameter can be a value of @ref UART_RxEvent_Type_Values :
  *           HAL_UART_RXEVENT_TC                 = 0x00U,
  *           HAL_UART_RXEVENT_HT                 = 0x01U,
  *           HAL_UART_RXEVENT_IDLE               = 0x02U,
  */
typedef uint32_t HAL_UART_RxEventTypeTypeDef;

/**
  * @brief  UART handle Structure definition
  */
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;        /*!< UART registers base address        */

  UART_InitTypeDef              Init;             /*!< UART communication parameters      */

  const uint8_t                 *pTxBuffPtr;      /*!< Pointer to UART Tx transfer Buffer */

  uint16_t                      TxXferSize;       /*!< UART Tx Transfer size              */

  __IO uint16_t                 TxXferCount;      /*!< UART Tx Transfer Counter           */

  uint8_t                       *pRxBuffPtr;      /*!< Pointer to UART Rx transfer Buffer */

  uint16_t                      RxXferSize;       /*!< UART Rx Transfer size              */

  __IO uint16_t                 RxXferCount;      /*!< UART Rx Transfer Counter           */

  __IO HAL_UART_RxTypeTypeDef ReceptionType;      /*!< Type of ongoing reception          */

  __IO HAL_UART_RxEventTypeTypeDef RxEventType;   /*!< Type of Rx Event                   */

  DMA_HandleTypeDef             *hdmatx;          /*!< UART Tx DMA Handle parameters      */

  DMA_HandleTypeDef             *hdmarx;          /*!< UART Rx DMA Handle parameters      */

  HAL_LockTypeDef               Lock;             /*!< Locking object                     */

  __IO HAL_UART_StateTypeDef    gState;           /*!< UART state information related to global Handle management
                                                       and also related to Tx operations.
                                                       This parameter can be a value of @ref HAL_UART_StateTypeDef */

  __IO HAL_UART_StateTypeDef    RxState;          /*!< UART state information related to Rx operations.
                                                       This parameter can be a value of @ref HAL_UART_StateTypeDef */

  __IO uint32_t                 ErrorCode;        /*!< UART Error code                    */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART Tx Half Complete Callback        */
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Tx Complete Callback             */
  void (* RxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART Rx Half Complete Callback        */
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Rx Complete Callback             */
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             /*!< UART Error Callback                   */
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Abort Complete Callback          */
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); /*!< UART Abort Transmit Complete Callback */
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  /*!< UART Abort Receive Complete Callback  */
  void (* WakeupCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Wakeup Callback                  */
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); /*!< UART Reception Event Callback     */

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Msp Init callback                */
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Msp DeInit callback              */
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART Callback ID enumeration definition
  */
typedef enum
{
  HAL_UART_TX_HALFCOMPLETE_CB_ID         = 0x00U,    /*!< UART Tx Half Complete Callback ID        */
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    /*!< UART Tx Complete Callback ID             */
  HAL_UART_RX_HALFCOMPLETE_CB_ID         = 0x02U,    /*!< UART Rx Half Complete Callback ID        */
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    /*!< UART Rx Complete Callback ID             */
  HAL_UART_ERROR_CB_ID                   = 0x04U,    /*!< UART Error Callback ID                   */
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    /*!< UART Abort Complete Callback ID          */
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    /*!< UART Abort Transmit Complete Callback ID */
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    /*!< UART Abort Receive Complete Callback ID  */
  HAL_UART_WAKEUP_CB_ID                  = 0x08U,    /*!< UART Wakeup Callback ID                  */

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    /*!< UART MspInit callback ID                 */
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU     /*!< UART MspDeInit callback ID               */

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART Callback pointer definition
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart);  /*!< pointer to an UART callback function */
typedef  void (*pUART_RxEventCallbackTypeDef)(struct __UART_HandleTypeDef *huart, uint16_t Pos);   /*!< pointer to a UART Rx Event specific callback function */

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART Exported Constants
  * @{
  */

/** @defgroup UART_Error_Code UART Error Code
  * @{
  */
#define HAL_UART_ERROR_NONE              0x00000000U   /*!< No error            */
#define HAL_UART_ERROR_PE                0x00000001U   /*!< Parity error        */
#define HAL_UART_ERROR_NE                0x00000002U   /*!< Noise error         */
#define HAL_UART_ERROR_FE                0x00000004U   /*!< Frame error         */
#define HAL_UART_ERROR_ORE               0x00000008U   /*!< Overrun error       */
#define HAL_UART_ERROR_DMA               0x00000010U   /*!< DMA transfer error  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK 0x00000020U   /*!< Invalid Callback error  */
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Word_Length UART Word Length
  * @{
  */
#define UART_WORDLENGTH_8B                  0x00000000U
#define UART_WORDLENGTH_9B                  ((uint32_t)USART_CR1_M)
/**
  * @}
  */

/** @defgroup UART_Stop_Bits UART Number of Stop Bits
  * @{
  */
#define UART_STOPBITS_1                     0x00000000U
#define UART_STOPBITS_2                     ((uint32_t)USART_CR2_STOP_1)
/**
  * @}
  */

/** @defgroup UART_Parity UART Parity
  * @{
  */
#define UART_PARITY_NONE                    0x00000000U
#define UART_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)
#define UART_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS))
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control UART Hardware Flow Control
  * @{
  */
#define UART_HWCONTROL_NONE                  0x00000000U
#define UART_HWCONTROL_RTS                   ((uint32_t)USART_CR3_RTSE)
#define UART_HWCONTROL_CTS                   ((uint32_t)USART_CR3_CTSE)
#define UART_HWCONTROL_RTS_CTS               ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE))
/**
  * @}
  */

/** @defgroup UART_Mode UART Transfer Mode
  * @{
  */
#define UART_MODE_RX                        ((uint32_t)USART_CR1_RE)
#define UART_MODE_TX                        ((uint32_t)USART_CR1_TE)
#define UART_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE | USART_CR1_RE))
/**
  * @}
  */

/** @defgroup UART_State UART State
  * @{
  */
#define UART_STATE_DISABLE                  0x00000000U
#define UART_STATE_ENABLE                   ((uint32_t)USART_CR1_UE)
/**
  * @}
  */

/** @defgroup UART_Over_Sampling UART Over Sampling
  * @{
  */
#define UART_OVERSAMPLING_16                    0x00000000U
#if defined(USART_CR1_OVER8)
#define UART_OVERSAMPLING_8                     ((uint32_t)USART_CR1_OVER8)
#endif /* USART_CR1_OVER8 */
/**
  * @}
  */

/** @defgroup UART_LIN_Break_Detection_Length  UART LIN Break Detection Length
  * @{
  */
#define UART_LINBREAKDETECTLENGTH_10B      0x00000000U
#define UART_LINBREAKDETECTLENGTH_11B      ((uint32_t)USART_CR2_LBDL)
/**
  * @}
  */

/** @defgroup UART_WakeUp_functions  UART Wakeup Functions
  * @{
  */
#define UART_WAKEUPMETHOD_IDLELINE                0x00000000U
#define UART_WAKEUPMETHOD_ADDRESSMARK             ((uint32_t)USART_CR1_WAKE)
/**
  * @}
  */

/** @defgroup UART_Flags   UART FLags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the SR register
  * @{
  */
#define UART_FLAG_CTS                       ((uint32_t)USART_SR_CTS)
#define UART_FLAG_LBD                       ((uint32_t)USART_SR_LBD)
#define UART_FLAG_TXE                       ((uint32_t)USART_SR_TXE)
#define UART_FLAG_TC                        ((uint32_t)USART_SR_TC)
#define UART_FLAG_RXNE                      ((uint32_t)USART_SR_RXNE)
#define UART_FLAG_IDLE                      ((uint32_t)USART_SR_IDLE)
#define UART_FLAG_ORE                       ((uint32_t)USART_SR_ORE)
#define UART_FLAG_NE                        ((uint32_t)USART_SR_NE)
#define UART_FLAG_FE                        ((uint32_t)USART_SR_FE)
#define UART_FLAG_PE                        ((uint32_t)USART_SR_PE)
/**
  * @}
  */

/** @defgroup UART_Interrupt_definition  UART Interrupt Definitions
  *        Elements values convention: 0xY000XXXX
  *           - XXXX  : Interrupt mask (16 bits) in the Y register
  *           - Y  : Interrupt source register (2bits)
  *                   - 0001: CR1 register
  *                   - 0010: CR2 register
  *                   - 0011: CR3 register
  * @{
  */

#define UART_IT_PE                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_PEIE))
#define UART_IT_TXE                      ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TXEIE))
#define UART_IT_TC                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TCIE))
#define UART_IT_RXNE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_RXNEIE))
#define UART_IT_IDLE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_IDLEIE))

#define UART_IT_LBD                      ((uint32_t)(UART_CR2_REG_INDEX << 28U | USART_CR2_LBDIE))

#define UART_IT_CTS                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_CTSIE))
#define UART_IT_ERR                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_EIE))
/**
  * @}
  */

/** @defgroup UART_Reception_Type_Values  UART Reception type values
  * @{
  */
#define HAL_UART_RECEPTION_STANDARD          (0x00000000U)             /*!< Standard reception                       */
#define HAL_UART_RECEPTION_TOIDLE            (0x00000001U)             /*!< Reception till completion or IDLE event  */
/**
  * @}
  */

/** @defgroup UART_RxEvent_Type_Values  UART RxEvent type values
  * @{
  */
#define HAL_UART_RXEVENT_TC                  (0x00000000U)             /*!< RxEvent linked to Transfer Complete event */
#define HAL_UART_RXEVENT_HT                  (0x00000001U)             /*!< RxEvent linked to Half Transfer event     */
#define HAL_UART_RXEVENT_IDLE                (0x00000002U)
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup UART_Exported_Macros UART Exported Macros
  * @{
  */
