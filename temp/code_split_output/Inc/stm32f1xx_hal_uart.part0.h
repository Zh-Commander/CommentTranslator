/**
  ******************************************************************************
  * @file    stm32f1xx_hal_uart.h
  * @author  MCD Application Team
  * @brief   UART HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件根目录的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按原样提供。
  *
  ******************************************************************************
  */

/* 防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_UART_H
#define __STM32F1xx_HAL_UART_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup UART
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/
/** @defgroup UART_Exported_Types UART 导出类型
  * @{
  */

/**
  * @brief UART 初始化结构体定义
  */
typedef struct
{
  uint32_t BaudRate;      // 波特率配置。常用的值有9600, 115200等。
                          // 波特率计算公式：
                          // - IntegerDivider = ((PCLKx) / (16 * (huart->Init.BaudRate)))
                          // - FractionalDivider = ((IntegerDivider - ((uint32_t) IntegerDivider)) * 16) + 0.5

  uint32_t WordLength;    // 字长设置，指定每帧发送或接收的数据位数。
                          // 该参数可以是 @ref UART_Word_Length 中的一个值

  uint32_t StopBits;      // 停止位设置，指定发送的停止位数。
                          // 该参数可以是 @ref UART_Stop_Bits 中的一个值

  uint32_t Parity;        // 校验模式设置。
                          // 该参数可以是 @ref UART_Parity 中的一个值
                          // @note 当启用校验时，计算出的校验位被插入到发送数据的最高位位置
                          //       (当字长设置为9位数据时为第9位；当字长设置为8位数据时为第8位)。

  uint32_t Mode;          // 指定是否启用或禁用接收或发送模式。
                          // 该参数可以是 @ref UART_Mode 中的一个值

  uint32_t HwFlowCtl;     // 指定是否启用或禁用硬件流控模式。
                          // 该参数可以是 @ref UART_Hardware_Flow_Control 中的一个值

  uint32_t OverSampling;  // 指定是否启用8倍过采样以实现更高的速度（高达 fPCLK/8）。
                          // 该参数可以是 @ref UART_Over_Sampling 中的一个值。此功能仅在
                          // STM32F100xx 系列上可用，因此 OverSampling 参数应始终设置为 16。
} UART_InitTypeDef;

/**
  * @brief HAL UART 状态结构体定义
  * @note  HAL UART 状态值由两个不同的子状态组成：gState 和 RxState。
  *        - gState 包含与全局句柄管理相关的 UART 状态信息，以及与发送操作相关的信息。
  *          gState 值编码遵循下面描述的位图：
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
  *             1  : 忙碌 (发送操作正在进行中)
  *        - RxState 包含与接收操作相关的信息。
  *          RxState 值编码遵循下面描述的位图：
  *          b7-b6  (未使用)
  *             xx : 应设置为 00
  *          b5     外设初始化状态
  *             0  : 复位 (外设未初始化)
  *             1  : 初始化完成 (外设已初始化)
  *          b4-b2  (未使用)
  *            xxx : 应设置为 000
  *          b1     接收状态
  *             0  : 就绪 (无正在进行的接收操作)
  *             1  : 忙碌 (接收操作正在进行中)
  *          b0     (未使用)
  *             x  : 应设置为 0。
  */
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    // 外设尚未初始化，允许用于 gState 和 RxState
  HAL_UART_STATE_READY             = 0x20U,    // 外设已初始化并准备就绪，允许用于 gState 和 RxState
  HAL_UART_STATE_BUSY              = 0x24U,    // 正在进行内部处理，仅允许用于 gState
  HAL_UART_STATE_BUSY_TX           = 0x21U,    // 数据发送过程正在进行中，仅允许用于 gState
  HAL_UART_STATE_BUSY_RX           = 0x22U,    // 数据接收过程正在进行中，仅允许用于 RxState
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    // 数据发送和接收过程正在进行中
                                               // 不用于 gState 或 RxState。
                                               // 该值是 gState 和 RxState 值的组合（或运算）
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    // 超时状态，仅允许用于 gState
  HAL_UART_STATE_ERROR             = 0xE0U     // 错误状态，仅允许用于 gState
} HAL_UART_StateTypeDef;

/**
  * @brief HAL UART 接收类型定义
  * @note  HAL UART 接收类型值旨在识别正在进行的接收类型。
  *        该参数可以是 @ref UART_Reception_Type_Values 中的一个值：
  *           HAL_UART_RECEPTION_STANDARD         = 0x00U, (标准接收)
  *           HAL_UART_RECEPTION_TOIDLE           = 0x01U, (接收直到完成或IDLE事件)
  */
typedef uint32_t HAL_UART_RxTypeTypeDef;

/**
  * @brief HAL UART 接收事件类型定义
  * @note  HAL UART 接收事件类型值旨在识别导致调用 RxEvent 回调的事件类型。
  *        该参数可以是 @ref UART_RxEvent_Type_Values 中的一个值：
  *           HAL_UART_RXEVENT_TC                 = 0x00U, (传输完成事件)
  *           HAL_UART_RXEVENT_HT                 = 0x01U, (半传输事件)
  *           HAL_UART_RXEVENT_IDLE               = 0x02U, (空闲检测事件)
  */
typedef uint32_t HAL_UART_RxEventTypeTypeDef;

/**
  * @brief  UART 句柄结构体定义
  */
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;        // UART 寄存器基地址

  UART_InitTypeDef              Init;             // UART 通信参数配置结构体

  const uint8_t                 *pTxBuffPtr;      // 指向 UART 发送缓冲区的指针

  uint16_t                      TxXferSize;       // UART 发送数据大小

  __IO uint16_t                 TxXferCount;      // UART 发送计数器

  uint8_t                       *pRxBuffPtr;      // 指向 UART 接收缓冲区的指针

  uint16_t                      RxXferSize;       // UART 接收数据大小

  __IO uint16_t                 RxXferCount;      // UART 接收计数器

  __IO HAL_UART_RxTypeTypeDef ReceptionType;      // 正在进行的接收类型

  __IO HAL_UART_RxEventTypeTypeDef RxEventType;   // 接收事件类型

  DMA_HandleTypeDef             *hdmatx;          // UART 发送 DMA 句柄参数

  DMA_HandleTypeDef             *hdmarx;          // UART 接收 DMA 句柄参数

  HAL_LockTypeDef               Lock;             // 锁定对象，用于资源管理

  __IO HAL_UART_StateTypeDef    gState;           // 与全局句柄管理相关的 UART 状态信息
                                                  // 也与发送操作相关。
                                                  // 该参数可以是 @ref HAL_UART_StateTypeDef 中的一个值

  __IO HAL_UART_StateTypeDef    RxState;          // 与接收操作相关的 UART 状态信息。
                                                  // 该参数可以是 @ref HAL_UART_StateTypeDef 中的一个值

  __IO uint32_t                 ErrorCode;        // UART 错误代码

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        // UART 发送半完成回调函数指针
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            // UART 发送完成回调函数指针
  void (* RxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        // UART 接收半完成回调函数指针
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            // UART 接收完成回调函数指针
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             // UART 错误回调函数指针
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         // UART 中止完成回调函数指针
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); // UART 中止发送完成回调函数指针
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  // UART 中止接收完成回调函数指针
  void (* WakeupCallback)(struct __UART_HandleTypeDef *huart);            // UART 唤醒回调函数指针
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); // UART 接收事件回调函数指针

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           // UART Msp 初始化回调函数指针
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         // UART Msp 反初始化回调函数指针
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART 回调ID枚举定义
  */
typedef enum
{
  HAL_UART_TX_HALFCOMPLETE_CB_ID         = 0x00U,    // UART 发送半完成回调ID
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    // UART 发送完成回调ID
  HAL_UART_RX_HALFCOMPLETE_CB_ID         = 0x02U,    // UART 接收半完成回调ID
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    // UART 接收完成回调ID
  HAL_UART_ERROR_CB_ID                   = 0x04U,    // UART 错误回调ID
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    // UART 中止完成回调ID
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    // UART 中止发送完成回调ID
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    // UART 中止接收完成回调ID
  HAL_UART_WAKEUP_CB_ID                  = 0x08U,    // UART 唤醒回调ID

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    // UART MspInit 回调ID
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU     // UART MspDeInit 回调ID

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART 回调指针定义
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart);  // 指向 UART 回调函数的指针
typedef  void (*pUART_RxEventCallbackTypeDef)(struct __UART_HandleTypeDef *huart, uint16_t Pos);   // 指向 UART 接收事件特定回调函数的指针

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART 导出常量
  * @{
  */

/** @defgroup UART_Error_Code UART 错误码
  * @{
  */
#define HAL_UART_ERROR_NONE              0x00000000U   // 无错误
#define HAL_UART_ERROR_PE                0x00000001U   // 校验错误
#define HAL_UART_ERROR_NE                0x00000002U   // 噪声错误
#define HAL_UART_ERROR_FE                0x00000004U   // 帧错误
#define HAL_UART_ERROR_ORE               0x00000008U   // 溢出错误
#define HAL_UART_ERROR_DMA               0x00000010U   // DMA 传输错误
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK 0x00000020U   // 无效回调错误
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Word_Length UART 字长
  * @{
  */
#define UART_WORDLENGTH_8B                  0x00000000U               // 8位字长
#define UART_WORDLENGTH_9B                  ((uint32_t)USART_CR1_M)   // 9位字长
/**
  * @}
  */

/** @defgroup UART_Stop_Bits UART 停止位
  * @{
  */
#define UART_STOPBITS_1                     0x00000000U                  // 1个停止位
#define UART_STOPBITS_2                     ((uint32_t)USART_CR2_STOP_1) // 2个停止位
/**
  * @}
  */

/** @defgroup UART_Parity UART 校验位
  * @{
  */
#define UART_PARITY_NONE                    0x00000000U                  // 无校验
#define UART_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)    // 偶校验
#define UART_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS)) // 奇校验
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control UART 硬件流控
  * @{
  */
#define UART_HWCONTROL_NONE                  0x00000000U                    // 无硬件流控
#define UART_HWCONTROL_RTS                   ((uint32_t)USART_CR3_RTSE)     // RTS 硬件流控
#define UART_HWCONTROL_CTS                   ((uint32_t)USART_CR3_CTSE)     // CTS 硬件流控
#define UART_HWCONTROL_RTS_CTS               ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE)) // RTS 和 CTS 硬件流控
/**
  * @}
  */

/** @defgroup UART_Mode UART 传输模式
  * @{
  */
#define UART_MODE_RX                        ((uint32_t)USART_CR1_RE)              // 接收模式
#define UART_MODE_TX                        ((uint32_t)USART_CR1_TE)              // 发送模式
#define UART_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE | USART_CR1_RE)) // 发送和接收模式
/**
  * @}
  */

/** @defgroup UART_State UART 状态
  * @{
  */
#define UART_STATE_DISABLE                  0x00000000U               // 禁用 UART
#define UART_STATE_ENABLE                   ((uint32_t)USART_CR1_UE)  // 使能 UART
/**
  * @}
  */

/** @defgroup UART_Over_Sampling UART 过采样
  * @{
  */
#define UART_OVERSAMPLING_16                    0x00000000U                  // 16倍过采样
#if defined(USART_CR1_OVER8)
#define UART_OVERSAMPLING_8                     ((uint32_t)USART_CR1_OVER8)  // 8倍过采样
#endif /* USART_CR1_OVER8 */
/**
  * @}
  */

/** @defgroup UART_LIN_Break_Detection_Length  UART LIN 断路检测长度
  * @{
  */
#define UART_LINBREAKDETECTLENGTH_10B      0x00000000U               // 10位断路检测
#define UART_LINBREAKDETECTLENGTH_11B      ((uint32_t)USART_CR2_LBDL) // 11位断路检测
/**
  * @}
  */

/** @defgroup UART_WakeUp_functions  UART 唤醒功能
  * @{
  */
#define UART_WAKEUPMETHOD_IDLELINE                0x00000000U              // 空闲线路唤醒
#define UART_WAKEUPMETHOD_ADDRESSMARK             ((uint32_t)USART_CR1_WAKE) // 地址标记唤醒
/**
  * @}
  */

/** @defgroup UART_Flags   UART 标志位
  *        元素值约定: 0xXXXX
  *           - 0xXXXX  : SR寄存器中的标志掩码
  * @{
  */
#define UART_FLAG_CTS                       ((uint32_t)USART_SR_CTS)  // CTS变化标志
#define UART_FLAG_LBD                       ((uint32_t)USART_SR_LBD)  // LIN断路检测标志
#define UART_FLAG_TXE                       ((uint32_t)USART_SR_TXE)  // 发送数据寄存器空标志
#define UART_FLAG_TC                        ((uint32_t)USART_SR_TC)   // 发送完成标志
#define UART_FLAG_RXNE                      ((uint32_t)USART_SR_RXNE) // 读数据寄存器非空标志
#define UART_FLAG_IDLE                      ((uint32_t)USART_SR_IDLE) // 空闲线路检测标志
#define UART_FLAG_ORE                       ((uint32_t)USART_SR_ORE)  // 溢出错误标志
#define UART_FLAG_NE                        ((uint32_t)USART_SR_NE)   // 噪声错误标志
#define UART_FLAG_FE                        ((uint32_t)USART_SR_FE)   // 帧错误标志
#define UART_FLAG_PE                        ((uint32_t)USART_SR_PE)   // 校验错误标志
/**
  * @}
  */

/** @defgroup UART_Interrupt_definition  UART 中断定义
  *        元素值约定: 0xY000XXXX
  *           - XXXX  : Y寄存器中的中断掩码 (16位)
  *           - Y  : 中断源寄存器 (2位)
  *                   - 0001: CR1 寄存器
  *                   - 0010: CR2 寄存器
  *                   - 0011: CR3 寄存器
  * @{
  */

#define UART_IT_PE                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_PEIE))   // 校验错误中断
#define UART_IT_TXE                      ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TXEIE))  // 发送寄存器空中断
#define UART_IT_TC                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TCIE))   // 发送完成中断
#define UART_IT_RXNE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_RXNEIE)) // 接收寄存器非空中断
#define UART_IT_IDLE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_IDLEIE)) // 空闲线路检测中断

#define UART_IT_LBD                      ((uint32_t)(UART_CR2_REG_INDEX << 28U | USART_CR2_LBDIE))  // LIN断路检测中断

#define UART_IT_CTS                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_CTSIE))  // CTS中断
#define UART_IT_ERR                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_EIE))    // 错误中断
/**
  * @}
  */

/** @defgroup UART_Reception_Type_Values  UART 接收类型值
  * @{
  */
#define HAL_UART_RECEPTION_STANDARD          (0x00000000U)             // 标准接收
#define HAL_UART_RECEPTION_TOIDLE            (0x00000001U)             // 接收直到完成或IDLE事件
/**
  * @}
  */

/** @defgroup UART_RxEvent_Type_Values  UART RxEvent 类型值
  * @{
  */
#define HAL_UART_RXEVENT_TC                  (0x00000000U)             // 与传输完成事件相关的 RxEvent
#define HAL_UART_RXEVENT_HT                  (0x00000001U)             // 与半传输事件相关的 RxEvent
#define HAL_UART_RXEVENT_IDLE                (0x00000002U)             // 与空闲事件相关的 RxEvent
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup UART_Exported_Macros UART 导出宏
  * @{
  */
