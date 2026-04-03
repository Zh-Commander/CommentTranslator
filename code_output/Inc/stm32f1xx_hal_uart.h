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
/** @brief  复位 UART 句柄的状态 和 接收状态
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @retval 无
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/* 如果定义了使用HAL库注册回调功能，则复位时还需要清空回调指针 */
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                       (__HANDLE__)->MspInitCallback = NULL;             \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \
                                                     } while(0U)
#else
/* 标准情况下，仅复位全局状态和接收状态 */
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/** @brief  刷新 UART 数据寄存器 (DR)
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @note   读取 DR 寄存器通常用于清除接收缓冲区非空标志(RXNE)
  */
#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  检查指定的 UART 标志位是否被置位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @param  __FLAG__ 指定要检查的标志位。
  *        该参数可以是以下值之一:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (不适用于 UART4 和 UART5)
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志
  *            @arg UART_FLAG_TXE:  发送数据寄存器空标志
  *            @arg UART_FLAG_TC:   发送完成标志
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志
  *            @arg UART_FLAG_IDLE: 空闲线路检测标志
  *            @arg UART_FLAG_ORE:  溢出错误标志
  *            @arg UART_FLAG_NE:   噪声错误标志
  *            @arg UART_FLAG_FE:   帧错误标志
  *            @arg UART_FLAG_PE:   奇偶校验错误标志
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  清除指定的 UART 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @param  __FLAG__ 指定要清除的标志位。
  *          该参数可以是以下值的任意组合:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (不适用于 UART4 和 UART5)。
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志。
  *            @arg UART_FLAG_TC:   发送完成标志。
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志。
  *
  * @note   PE (奇偶错误), FE (帧错误), NE (噪声错误), ORE (溢出
  *          错误) 和 IDLE (空闲线路检测) 标志位通过软件
  *          序列清除: 先读取 USART_SR 寄存器，再读取
  *          USART_DR 寄存器。
  * @note   RXNE 标志位也可以通过读取 USART_DR 寄存器来清除。
  * @note   TC 标志位也可以通过软件序列清除: 先读取
  *          USART_SR 寄存器，再写入 USART_DR 寄存器。
  * @note   TXE 标志位只能通过写入 USART_DR 寄存器来清除。
  *
  * @retval 无
  */
#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  清除 UART 奇偶校验错误 (PE) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @retval 无
  */
#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)     \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR;        \
    tmpreg = (__HANDLE__)->Instance->DR;        \
    UNUSED(tmpreg);                             \
  } while(0U)

/** @brief  清除 UART 帧错误 (FE) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @retval 无
  */
#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除 UART 噪声错误 (NE) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @retval 无
  */
#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除 UART 溢出错误 (ORE) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @retval 无
  */
#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除 UART 空闲线路 (IDLE) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @retval 无
  */
#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  使能指定的 UART 中断。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @param  __INTERRUPT__ 指定要使能的 UART 中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断 (帧错误, 噪声错误, 溢出错误)
  * @retval 无
  */
/* 通过判断中断号的高28位来确定中断控制寄存器(CR1/CR2/CR3)，然后设置对应的中断使能位 */
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 |= ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  禁止指定的 UART 中断。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @param  __INTERRUPT__ 指定要禁止的 UART 中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断 (帧错误, 噪声错误, 溢出错误)
  * @retval 无
  */
/* 通过判断中断号的高28位来确定中断控制寄存器(CR1/CR2/CR3)，然后清除对应的中断使能位 */
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  检查指定的 UART 中断源是否已使能。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择了 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备)。
  * @param  __IT__ 指定要检查的 UART 中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS: CTS 变化中断 (不适用于 UART4 和 UART5)
  *            @arg UART_IT_LBD: LIN 断路检测中断
  *            @arg UART_IT_TXE: 发送数据寄存器空中断
  *            @arg UART_IT_TC:  发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_ERR: 错误中断
  * @retval __IT__ 的新状态 (TRUE 或 FALSE)。
  */
/* 读取对应控制寄存器的位，判断中断是否使能 */
#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) (((((__IT__) >> 28U) == UART_CR1_REG_INDEX)? (__HANDLE__)->Instance->CR1:(((((uint32_t)(__IT__)) >> 28U) == UART_CR2_REG_INDEX)? \
                                                       (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (((uint32_t)(__IT__)) & UART_IT_MASK))

/** @brief  使能 CTS 流控制
  * @note   此宏允许为给定的 UART 实例使能 CTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 CTS 硬件流控制功能的激活状态，
  *         而无需 USART 实例的 Deinit/Init，因此应满足以下调用条件 :
  *           - UART 实例应已初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且之后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \
  } while(0U)

/** @brief  禁止 CTS 流控制
  * @note   此宏允许为给定的 UART 实例禁止 CTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 CTS 硬件流控制功能的激活状态，
  *         而无需 USART 实例的 Deinit/Init，因此应满足以下调用条件 :
  *           - UART 实例应已初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且之后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \
  } while(0U)

/** @brief  使能 RTS 流控制
  *         此宏允许为给定的 UART 实例使能 RTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 RTS 硬件流控制功能的激活状态，
  *         而无需 USART 实例的 Deinit/Init，因此应满足以下调用条件 :
  *           - UART 实例应已初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且之后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \
  } while(0U)

/** @brief  禁止 RTS 流控制
  *         此宏允许为给定的 UART 实例禁止 RTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 RTS 硬件流控制功能的激活状态，
  *         而无需 USART 实例的 Deinit/Init，因此应满足以下调用条件 :
  *           - UART 实例应已初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且之后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \
  } while(0U)
#if defined(USART_CR3_ONEBIT)

/** @brief  宏: 使能 UART 的单比特采样方法
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

/** @brief  宏: 禁止 UART 的单比特采样方法
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                       &= (uint16_t)~((uint16_t)USART_CR3_ONEBIT))
#endif /* UART_ONE_BIT_SAMPLE_Feature */

/** @brief  使能 UART
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
#define __HAL_UART_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  禁止 UART
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
#define __HAL_UART_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)
/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup UART_Exported_Functions
  * @{
  */

/** @addtogroup UART_Exported_Functions_Group1 初始化和反初始化函数
  * @{
  */

/* 初始化/反初始化函数  **********************************/
/* 初始化 UART */
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
/* 初始化 UART 为半双工模式 */
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
/* 初始化 UART 为 LIN 模式 */
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
/* 初始化 UART 为多处理器模式 */
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
/* 反初始化 UART */
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
/* MSP 初始化 (底层硬件初始化，如 GPIO 时钟等，由用户重写) */
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
/* MSP 反初始化 (底层硬件反初始化，由用户重写) */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

/* 回调注册/注销函数  ***********************************/
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/* 注册回调函数 */
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback);
/* 注销回调函数 */
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);
/* 注册接收事件回调函数 */
HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback);
/* 注销接收事件回调函数 */
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group2 IO 操作函数
  * @{
  */

/* IO 操作函数 *******************************************************/
/* 阻塞模式发送数据 */
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
/* 阻塞模式接收数据 */
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
/* 非阻塞模式(中断)发送数据 */
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
/* 非阻塞模式(中断)接收数据 */
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 非阻塞模式(DMA)发送数据 */
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
/* 非阻塞模式(DMA)接收数据 */
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 暂停 DMA 传输 */
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
/* 恢复 DMA 传输 */
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
/* 停止 DMA 传输 */
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

/* 阻塞模式接收数据直到空闲 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
/* 非阻塞模式(中断)接收数据直到空闲 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 非阻塞模式(DMA)接收数据直到空闲 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/* 获取接收事件类型 */
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(UART_HandleTypeDef *huart);

/* 传输中止函数 */
/* 中止正在进行的传输(阻塞模式) */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
/* 仅中止发送(阻塞模式) */
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
/* 仅中止接收(阻塞模式) */
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
/* 中止正在进行的传输(非阻塞模式) */
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
/* 仅中止发送(非阻塞模式) */
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
/* 仅中止接收(非阻塞模式) */
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

/* UART 中断处理函数(需在 stm32fxxx_it.c 中调用) */
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
/* 发送完成回调函数 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
/* 发送过半回调函数 */
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
/* 接收完成回调函数 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/* 接收过半回调函数 */
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
/* 错误回调函数 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
/* 中止完成回调函数 */
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
/* 发送中止完成回调函数 */
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
/* 接收中止完成回调函数 */
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

/* 接收事件回调函数(用于 ReceiveToIdle) */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* 外设控制函数  **************************************************/
/* 发送 LIN 断路信号 */
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
/* 多处理器模式：进入静默模式 */
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
/* 多处理器模式：退出静默模式 */
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
/* 半双工模式：使能发送器 */
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
/* 半双工模式：使能接收器 */
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* 外设状态函数  **************************************************/
/* 获取 UART 状态 */
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
/* 获取 UART 错误码 */
uint32_t              HAL_UART_GetError(const UART_HandleTypeDef *huart);
/**
  * @}
  */

/**
  * @}
  */
/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup UART_Private_Constants UART 私有常量
  * @{
  */
/** @brief UART 中断标志掩码
  *
  */
#define UART_IT_MASK                     0x0000FFFFU

/* CR1 寄存器索引 */
#define UART_CR1_REG_INDEX               1U
/* CR2 寄存器索引 */
#define UART_CR2_REG_INDEX               2U
/* CR3 寄存器索引 */
#define UART_CR3_REG_INDEX               3U
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART 私有宏
  * @{
  */
/* 检查字长参数是否有效 */
#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))
/* 检查 LIN 模式字长参数是否有效 */
#define IS_UART_LIN_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B))
/* 检查停止位参数是否有效 */
#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_2))
/* 检查校验位参数是否有效 */
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))
/* 检查硬件流控参数是否有效 */
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HWCONTROL_NONE) || \
                               ((CONTROL) == UART_HWCONTROL_RTS) || \
                               ((CONTROL) == UART_HWCONTROL_CTS) || \
                               ((CONTROL) == UART_HWCONTROL_RTS_CTS))
/* 检查模式参数是否有效 */
#define IS_UART_MODE(MODE) ((((MODE) & 0x0000FFF3U) == 0x00U) && ((MODE) != 0x00U))
/* 检查状态参数是否有效 */
#define IS_UART_STATE(STATE) (((STATE) == UART_STATE_DISABLE) || \
                              ((STATE) == UART_STATE_ENABLE))
#if defined(USART_CR1_OVER8)
/* 检查过采样参数是否有效 */
#define IS_UART_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16) || \
                                        ((SAMPLING) == UART_OVERSAMPLING_8))
#endif /* USART_CR1_OVER8 */
/* 检查 LIN 模式过采样参数是否有效 */
#define IS_UART_LIN_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16))
/* 检查 LIN 断路检测长度参数是否有效 */
#define IS_UART_LIN_BREAK_DETECT_LENGTH(LENGTH) (((LENGTH) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                 ((LENGTH) == UART_LINBREAKDETECTLENGTH_11B))
/* 检查唤醒方法参数是否有效 */
#define IS_UART_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == UART_WAKEUPMETHOD_IDLELINE) || \
                                      ((WAKEUP) == UART_WAKEUPMETHOD_ADDRESSMARK))
/* 检查波特率参数是否有效 */
#define IS_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 4500000U)
/* 检查地址参数是否有效 */
#define IS_UART_ADDRESS(ADDRESS) ((ADDRESS) <= 0x0FU)

/* 以下为波特率计算相关的宏，用于计算 BRR 寄存器值 */
/* 16倍采样模式下的分频系数计算 (整数部分 + 小数部分) */
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
/* 16倍采样模式下的分频系数整数部分 */
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
/* 16倍采样模式下的分频系数小数部分 */
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR 寄存器值 = 尾数 + 溢出 + 小数
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

/* 8倍采样模式下的分频系数计算 */
#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
/* 8倍采样模式下的分频系数整数部分 */
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
/* 8倍采样模式下的分频系数小数部分 */
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)
/* UART BRR 寄存器值 = 尾数 + 溢出 + 小数
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                         ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

/**
  * @}
  */

/* 私有函数 ---------------------------------------------------------*/
/** @defgroup UART_Private_Functions UART 私有函数
  * @{
  */

/* 启动中断接收 */
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 启动 DMA 接收 */
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_HAL_UART_H */
