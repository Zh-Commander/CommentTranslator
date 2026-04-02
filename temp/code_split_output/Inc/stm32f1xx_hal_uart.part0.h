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
// 防止头文件被重复包含
#ifndef __STM32F1xx_HAL_UART_H
#define __STM32F1xx_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含HAL库通用的定义头文件
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
  * @brief UART 初始化结构体定义
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
                                           The baud rate is computed using the following formula:
                                           - IntegerDivider = ((PCLKx) / (16 * (huart->Init.BaudRate)))
                                           - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5 */
                                       /*!< 该成员用于配置UART通信的波特率。
                                            波特率的计算公式如下：
                                            - 整数部分 = ((PCLKx) / (16 * (huart->Init.BaudRate)))
                                            - 小数部分 = ((整数部分 - ((uint32_t) 整数部分)) * 16) + 0.5 */

  uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                           This parameter can be a value of @ref UART_Word_Length */
                                       /*!< 指定一帧数据中传输或接收的数据位个数。
                                            该参数可以是 @ref UART_Word_Length 中的一个值 */

  uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                           This parameter can be a value of @ref UART_Stop_Bits */
                                       /*!< 指定传输的停止位个数。
                                            该参数可以是 @ref UART_Stop_Bits 中的一个值 */

  uint32_t Parity;                    /*!< Specifies the parity mode.
                                           This parameter can be a value of @ref UART_Parity
                                           @note When parity is enabled, the computed parity is inserted
                                                 at the MSB position of the transmitted data (9th bit when
                                                 the word length is set to 9 data bits; 8th bit when the
                                                 word length is set to 8 data bits). */
                                       /*!< 指定奇偶校验模式。
                                            该参数可以是 @ref UART_Parity 中的一个值
                                            @note 当使能奇偶校验时，计算出的校验位将被插入
                                                  到传输数据的最高位（MSB）位置（当字长设置为9位数据位时
                                                  为第9位；当字长设置为8位数据位时为第8位）。 */

  uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_Mode */
                                       /*!< 指定接收或发送模式是使能还是禁止。
                                            该参数可以是 @ref UART_Mode 中的一个值 */

  uint32_t HwFlowCtl;                 /*!< Specifies whether the hardware flow control mode is enabled or disabled.
                                           This parameter can be a value of @ref UART_Hardware_Flow_Control */
                                       /*!< 指定硬件流控制模式是使能还是禁止。
                                            该参数可以是 @ref UART_Hardware_Flow_Control 中的一个值 */

  uint32_t OverSampling;              /*!< Specifies whether the Over sampling 8 is enabled or disabled, to achieve higher speed (up to fPCLK/8).
                                           This parameter can be a value of @ref UART_Over_Sampling. This feature is only available
                                           on STM32F100xx family, so OverSampling parameter should always be set to 16. */
                                       /*!< 指定是否使能8倍过采样，以实现更高的速度（最高可达 fPCLK/8）。
                                            该参数可以是 @ref UART_Over_Sampling 中的一个值。此功能仅在
                                            STM32F100xx系列上可用，因此OverSampling参数应始终设置为16。 */
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
/**
  * @brief HAL UART 状态结构体定义
  * @note  HAL UART 状态值由两个不同的子状态组合而成：gState 和 RxState。
  *        - gState 包含与全局句柄管理相关的 UART 状态信息，以及与发送操作相关的信息。
  *          gState 值的编码遵循下面描述的位图：
  *          b7-b6  错误信息
  *             00 : 无错误
  *             01 : (未使用)
  *             10 : 超时
  *             11 : 错误
  *          b5     外设初始化状态
  *             0  : 复位 (外设未初始化)
  *             1  : 初始化完成 (外设已初始化，HAL UART Init 函数已被调用)
  *          b4-b3  (未使用)
  *             xx : 应设置为 00
  *          b2     内部处理状态
  *             0  : 就绪
  *             1  : 忙碌 (外设正忙于某些配置或内部操作)
  *          b1     (未使用)
  *             x  : 应设置为 0
  *          b0     发送状态
  *             0  : 就绪 (无正在进行的发送操作)
  *             1  : 忙碌 (正在进行的发送操作)
  *        - RxState 包含与接收操作相关的信息。
  *          RxState 值的编码遵循下面描述的位图：
  *          b7-b6  (未使用)
  *             xx : 应设置为 00
  *          b5     外设初始化状态
  *             0  : 复位 (外设未初始化)
  *             1  : 初始化完成 (外设已初始化)
  *          b4-b2  (未使用)
  *            xxx : 应设置为 000
  *          b1     接收状态
  *             0  : 就绪 (无正在进行的接收操作)
  *             1  : 忙碌 (正在进行的接收操作)
  *          b0     (未使用)
  *             x  : 应设置为 0。
  */
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    /*!< Peripheral is not yet Initialized
                                                   Value is allowed for gState and RxState */
                                               /*!< 外设尚未初始化
                                                    该值允许用于 gState 和 RxState */
  HAL_UART_STATE_READY             = 0x20U,    /*!< Peripheral Initialized and ready for use
                                                   Value is allowed for gState and RxState */
                                               /*!< 外设已初始化并准备好使用
                                                    该值允许用于 gState 和 RxState */
  HAL_UART_STATE_BUSY              = 0x24U,    /*!< an internal process is ongoing
                                                   Value is allowed for gState only */
                                               /*!< 正在进行内部处理
                                                    该值仅允许用于 gState */
  HAL_UART_STATE_BUSY_TX           = 0x21U,    /*!< Data Transmission process is ongoing
                                                   Value is allowed for gState only */
                                               /*!< 数据发送过程正在进行
                                                    该值仅允许用于 gState */
  HAL_UART_STATE_BUSY_RX           = 0x22U,    /*!< Data Reception process is ongoing
                                                   Value is allowed for RxState only */
                                               /*!< 数据接收过程正在进行
                                                    该值仅允许用于 RxState */
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    /*!< Data Transmission and Reception process is ongoing
                                                   Not to be used for neither gState nor RxState.
                                                   Value is result of combination (Or) between gState and RxState values */
                                               /*!< 数据发送和接收过程正在进行
                                                    既不用于 gState 也不用于 RxState。
                                                    该值是 gState 和 RxState 值组合（或运算）的结果 */
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    /*!< Timeout state
                                                   Value is allowed for gState only */
                                               /*!< 超时状态
                                                    该值仅允许用于 gState */
  HAL_UART_STATE_ERROR             = 0xE0U     /*!< Error
                                                   Value is allowed for gState only */
                                               /*!< 错误
                                                    该值仅允许用于 gState */
} HAL_UART_StateTypeDef;

/**
  * @brief HAL UART Reception type definition
  * @note  HAL UART Reception type value aims to identify which type of Reception is ongoing.
  *        This parameter can be a value of @ref UART_Reception_Type_Values :
  *           HAL_UART_RECEPTION_STANDARD         = 0x00U,
  *           HAL_UART_RECEPTION_TOIDLE           = 0x01U,
  */
/**
  * @brief HAL UART 接收类型定义
  * @note  HAL UART 接收类型值旨在识别正在进行的接收类型。
  *        该参数可以是 @ref UART_Reception_Type_Values 中的一个值：
  *           HAL_UART_RECEPTION_STANDARD         = 0x00U, (标准接收)
  *           HAL_UART_RECEPTION_TOIDLE           = 0x01U, (接收直到空闲)
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
/**
  * @brief HAL UART 接收事件类型定义
  * @note  HAL UART 接收事件类型值旨在识别导致调用 RxEvent 回调的事件类型。
  *        该参数可以是 @ref UART_RxEvent_Type_Values 中的一个值：
  *           HAL_UART_RXEVENT_TC                 = 0x00U, (传输完成事件)
  *           HAL_UART_RXEVENT_HT                 = 0x01U, (半传输完成事件)
  *           HAL_UART_RXEVENT_IDLE               = 0x02U, (空闲线路检测事件)
  */
typedef uint32_t HAL_UART_RxEventTypeTypeDef;

/**
  * @brief  UART handle Structure definition
  * @brief  UART 句柄结构体定义
  */
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;        /*!< UART registers base address        */
                                                   /*!< UART 寄存器基地址指针              */

  UART_InitTypeDef              Init;             /*!< UART communication parameters      */
                                                   /*!< UART 通信参数结构体                */

  const uint8_t                 *pTxBuffPtr;      /*!< Pointer to UART Tx transfer Buffer */
                                                   /*!< 指向 UART 发送缓冲区的指针         */

  uint16_t                      TxXferSize;       /*!< UART Tx Transfer size              */
                                                   /*!< UART 发送数据大小                  */

  __IO uint16_t                 TxXferCount;      /*!< UART Tx Transfer Counter           */
                                                   /*!< UART 发送计数器（剩余待发送数量）  */

  uint8_t                       *pRxBuffPtr;      /*!< Pointer to UART Rx transfer Buffer */
                                                   /*!< 指向 UART 接收缓冲区的指针         */

  uint16_t                      RxXferSize;       /*!< UART Rx Transfer size              */
                                                   /*!< UART 接收数据大小                  */

  __IO uint16_t                 RxXferCount;      /*!< UART Rx Transfer Counter           */
                                                   /*!< UART 接收计数器（剩余待接收数量）  */

  __IO HAL_UART_RxTypeTypeDef ReceptionType;      /*!< Type of ongoing reception          */
                                                   /*!< 正在进行的接收类型                 */

  __IO HAL_UART_RxEventTypeTypeDef RxEventType;   /*!< Type of Rx Event                   */
                                                   /*!< 接收事件类型                       */

  DMA_HandleTypeDef             *hdmatx;          /*!< UART Tx DMA Handle parameters      */
                                                   /*!< UART 发送 DMA 句柄参数             */

  DMA_HandleTypeDef             *hdmarx;          /*!< UART Rx DMA Handle parameters      */
                                                   /*!< UART 接收 DMA 句柄参数             */

  HAL_LockTypeDef               Lock;             /*!< Locking object                     */
                                                   /*!< 锁对象，用于资源保护               */

  __IO HAL_UART_StateTypeDef    gState;           /*!< UART state information related to global Handle management
                                                       and also related to Tx operations.
                                                       This parameter can be a value of @ref HAL_UART_StateTypeDef */
                                                   /*!< 与全局句柄管理相关的 UART 状态信息，
                                                      也与发送操作相关。
                                                      该参数可以是 @ref HAL_UART_StateTypeDef 中的一个值 */

  __IO HAL_UART_StateTypeDef    RxState;          /*!< UART state information related to Rx operations.
                                                       This parameter can be a value of @ref HAL_UART_StateTypeDef */
                                                   /*!< 与接收操作相关的 UART 状态信息。
                                                      该参数可以是 @ref HAL_UART_StateTypeDef 中的一个值 */

  __IO uint32_t                 ErrorCode;        /*!< UART Error code                    */
                                                   /*!< UART 错误代码                      */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART Tx Half Complete Callback        */
                                                                           /*!< UART 发送半完成回调函数              */
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Tx Complete Callback             */
                                                                           /*!< UART 发送完成回调函数                */
  void (* RxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART Rx Half Complete Callback        */
                                                                           /*!< UART 接收半完成回调函数              */
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Rx Complete Callback             */
                                                                           /*!< UART 接收完成回调函数                */
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             /*!< UART Error Callback                   */
                                                                           /*!< UART 错误回调函数                    */
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Abort Complete Callback          */
                                                                           /*!< UART 中止完成回调函数                */
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); /*!< UART Abort Transmit Complete Callback */
                                                                           /*!< UART 中止发送完成回调函数            */
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  /*!< UART Abort Receive Complete Callback  */
                                                                           /*!< UART 中止接收完成回调函数            */
  void (* WakeupCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART Wakeup Callback                  */
                                                                           /*!< UART 唤醒回调函数                    */
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); /*!< UART Reception Event Callback     */
                                                                             /*!< UART 接收事件回调函数                */

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Msp Init callback                */
                                                                           /*!< UART Msp 初始化回调函数              */
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Msp DeInit callback              */
                                                                           /*!< UART Msp 反初始化回调函数            */
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART Callback ID enumeration definition
  * @brief  HAL UART 回调函数ID枚举定义
  */
typedef enum
{
  HAL_UART_TX_HALFCOMPLETE_CB_ID         = 0x00U,    /*!< UART Tx Half Complete Callback ID        */
                                                      /*!< UART 发送半完成回调函数ID                */
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    /*!< UART Tx Complete Callback ID             */
                                                      /*!< UART 发送完成回调函数ID                  */
  HAL_UART_RX_HALFCOMPLETE_CB_ID         = 0x02U,    /*!< UART Rx Half Complete Callback ID        */
                                                      /*!< UART 接收半完成回调函数ID                */
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    /*!< UART Rx Complete Callback ID             */
                                                      /*!< UART 接收完成回调函数ID                  */
  HAL_UART_ERROR_CB_ID                   = 0x04U,    /*!< UART Error Callback ID                   */
                                                      /*!< UART 错误回调函数ID                      */
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    /*!< UART Abort Complete Callback ID          */
                                                      /*!< UART 中止完成回调函数ID                  */
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    /*!< UART Abort Transmit Complete Callback ID */
                                                      /*!< UART 中止发送完成回调函数ID              */
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    /*!< UART Abort Receive Complete Callback ID  */
                                                      /*!< UART 中止接收完成回调函数ID              */
  HAL_UART_WAKEUP_CB_ID                  = 0x08U,    /*!< UART Wakeup Callback ID                  */
                                                      /*!< UART 唤醒回调函数ID                      */

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    /*!< UART MspInit callback ID                 */
                                                      /*!< UART Msp初始化回调函数ID                 */
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU     /*!< UART MspDeInit callback ID               */
                                                      /*!< UART Msp反初始化回调函数ID               */

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART Callback pointer definition
  * @brief  HAL UART 回调函数指针定义
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart);  /*!< pointer to an UART callback function */
                                                                    /*!< 指向 UART 回调函数的指针             */
typedef  void (*pUART_RxEventCallbackTypeDef)(struct __UART_HandleTypeDef *huart, uint16_t Pos);   /*!< pointer to a UART Rx Event specific callback function */
                                                                                                    /*!< 指向 UART 接收事件特定回调函数的指针 */

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
                                                       /*!< 无错误              */
#define HAL_UART_ERROR_PE                0x00000001U   /*!< Parity error        */
                                                       /*!< 奇偶校验错误        */
#define HAL_UART_ERROR_NE                0x00000002U   /*!< Noise error         */
                                                       /*!< 噪声错误            */
#define HAL_UART_ERROR_FE                0x00000004U   /*!< Frame error         */
                                                       /*!< 帧错误              */
#define HAL_UART_ERROR_ORE               0x00000008U   /*!< Overrun error       */
                                                       /*!< 溢出错误            */
#define HAL_UART_ERROR_DMA               0x00000010U   /*!< DMA transfer error  */
                                                       /*!< DMA传输错误         */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK 0x00000020U   /*!< Invalid Callback error  */
                                                       /*!< 无效回调错误            */
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Word_Length UART Word Length
  * @{
  */
#define UART_WORDLENGTH_8B                  0x00000000U   // 8位字长
#define UART_WORDLENGTH_9B                  ((uint32_t)USART_CR1_M)  // 9位字长
/**
  * @}
  */

/** @defgroup UART_Stop_Bits UART Number of Stop Bits
  * @{
  */
#define UART_STOPBITS_1                     0x00000000U   // 1个停止位
#define UART_STOPBITS_2                     ((uint32_t)USART_CR2_STOP_1)  // 2个停止位
/**
  * @}
  */

/** @defgroup UART_Parity UART Parity
  * @{
  */
#define UART_PARITY_NONE                    0x00000000U   // 无奇偶校验
#define UART_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)  // 偶校验
#define UART_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS))  // 奇校验
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control UART Hardware Flow Control
  * @{
  */
#define UART_HWCONTROL_NONE                  0x00000000U   // 无硬件流控
#define UART_HWCONTROL_RTS                   ((uint32_t)USART_CR3_RTSE)  // 仅使能 RTS 硬件流控
#define UART_HWCONTROL_CTS                   ((uint32_t)USART_CR3_CTSE)  // 仅使能 CTS 硬件流控
#define UART_HWCONTROL_RTS_CTS               ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE))  // 使能 RTS 和 CTS 硬件流控
/**
  * @}
  */

/** @defgroup UART_Mode UART Transfer Mode
  * @{
  */
#define UART_MODE_RX                        ((uint32_t)USART_CR1_RE)   // 接收模式
#define UART_MODE_TX                        ((uint32_t)USART_CR1_TE)   // 发送模式
#define UART_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE | USART_CR1_RE))  // 发送和接收模式
/**
  * @}
  */

/** @defgroup UART_State UART State
  * @{
  */
#define UART_STATE_DISABLE                  0x00000000U   // UART 禁用
#define UART_STATE_ENABLE                   ((uint32_t)USART_CR1_UE)  // UART 使能
/**
  * @}
  */

/** @defgroup UART_Over_Sampling UART Over Sampling
  * @{
  */
#define UART_OVERSAMPLING_16                    0x00000000U   // 16倍过采样
#if defined(USART_CR1_OVER8)
#define UART_OVERSAMPLING_8                     ((uint32_t)USART_CR1_OVER8)  // 8倍过采样
#endif /* USART_CR1_OVER8 */
/**
  * @}
  */

/** @defgroup UART_LIN_Break_Detection_Length  UART LIN Break Detection Length
  * @{
  */
#define UART_LINBREAKDETECTLENGTH_10B      0x00000000U   // LIN断路检测长度为10位
#define UART_LINBREAKDETECTLENGTH_11B      ((uint32_t)USART_CR2_LBDL)  // LIN断路检测长度为11位
/**
  * @}
  */

/** @defgroup UART_WakeUp_functions  UART Wakeup Functions
  * @{
  */
#define UART_WAKEUPMETHOD_IDLELINE                0x00000000U   // 空闲线路唤醒方法
#define UART_WAKEUPMETHOD_ADDRESSMARK             ((uint32_t)USART_CR1_WAKE)  // 地址标记唤醒方法
/**
  * @}
  */

/** @defgroup UART_Flags   UART FLags
  *        Elements values convention: 0xXXXX
  *           - 0xXXXX  : Flag mask in the SR register
  * @{
  */
#define UART_FLAG_CTS                       ((uint32_t)USART_SR_CTS)   // CTS变化标志
#define UART_FLAG_LBD                       ((uint32_t)USART_SR_LBD)   // LIN断路检测标志
#define UART_FLAG_TXE                       ((uint32_t)USART_SR_TXE)   // 发送数据寄存器空标志
#define UART_FLAG_TC                        ((uint32_t)USART_SR_TC)    // 发送完成标志
#define UART_FLAG_RXNE                      ((uint32_t)USART_SR_RXNE)  // 接收数据寄存器非空标志
#define UART_FLAG_IDLE                      ((uint32_t)USART_SR_IDLE)  // 空闲线路检测标志
#define UART_FLAG_ORE                       ((uint32_t)USART_SR_ORE)   // 溢出错误标志
#define UART_FLAG_NE                        ((uint32_t)USART_SR_NE)    // 噪声错误标志
#define UART_FLAG_FE                        ((uint32_t)USART_SR_FE)    // 帧错误标志
#define UART_FLAG_PE                        ((uint32_t)USART_SR_PE)    // 奇偶校验错误标志
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

#define UART_IT_PE                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_PEIE))   // 奇偶校验错误中断
#define UART_IT_TXE                      ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TXEIE))  // 发送数据寄存器空中断
#define UART_IT_TC                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TCIE))   // 发送完成中断
#define UART_IT_RXNE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_RXNEIE)) // 接收数据寄存器非空中断
#define UART_IT_IDLE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_IDLEIE)) // 空闲线路检测中断

#define UART_IT_LBD                      ((uint32_t)(UART_CR2_REG_INDEX << 28U | USART_CR2_LBDIE))  // LIN断路检测中断

#define UART_IT_CTS                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_CTSIE))  // CTS中断
#define UART_IT_ERR                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_EIE))    // 错误中断
/**
  * @}
  */

/** @defgroup UART_Reception_Type_Values  UART Reception type values
  * @{
  */
#define HAL_UART_RECEPTION_STANDARD          (0x00000000U)             /*!< Standard reception                       */
                                                           /*!< 标准接收                                 */
#define HAL_UART_RECEPTION_TOIDLE            (0x00000001U)             /*!< Reception till completion or IDLE event  */
                                                           /*!< 接收直到完成或IDLE事件                   */
/**
  * @}
  */

/** @defgroup UART_RxEvent_Type_Values  UART RxEvent type values
  * @{
  */
#define HAL_UART_RXEVENT_TC                  (0x00000000U)             /*!< RxEvent linked to Transfer Complete event */
                                                           /*!< 链接到传输完成事件的接收事件             */
#define HAL_UART_RXEVENT_HT                  (0x00000001U)             /*!< RxEvent linked to Half Transfer event     */
                                                           /*!< 链接到半传输完成事件的接收事件           */
#define HAL_UART_RXEVENT_IDLE                (0x00000002U)             /*!< RxEvent linked to IDLE event              */
                                                           /*!< 链接到IDLE事件的接收事件                 */
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
