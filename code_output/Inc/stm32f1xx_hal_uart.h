/**
  ******************************************************************************
  * @file    stm32f1xx_hal_uart.h
  * @author  MCD Application Team
  * @brief   UART HAL模块头文件。
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

/* 防止递归包含 -----------------------------------------------------*/
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
  uint32_t BaudRate;                  /* 该成员配置UART通信波特率。
                                           波特率计算公式如下：
                                           - 整数部分 = ((PCLKx) / (16 * (huart->Init.BaudRate)))
                                           - 小数部分 = ((整数部分 - ((uint32_t) 整数部分)) * 16) + 0.5 */

  uint32_t WordLength;                /* 指定帧中发送或接收的数据位数。
                                           该参数可以是 @ref UART_Word_Length 中的值 */

  uint32_t StopBits;                  /* 指定发送的停止位数。
                                           该参数可以是 @ref UART_Stop_Bits 中的值 */

  uint32_t Parity;                    /* 指定奇偶校验模式。
                                           该参数可以是 @ref UART_Parity 中的值
                                           @note 当使能奇偶校验时，计算出的校验位被插入
                                                 到发送数据的最高位位置（当字长设置为9位时
                                                 为第9位；当字长设置为8位时为第8位）。 */

  uint32_t Mode;                      /* 指定接收或发送模式是使能还是禁止。
                                           该参数可以是 @ref UART_Mode 中的值 */

  uint32_t HwFlowCtl;                 /* 指定硬件流控制模式是使能还是禁止。
                                           该参数可以是 @ref UART_Hardware_Flow_Control 中的值 */

  uint32_t OverSampling;              /* 指定是否使能8倍过采样，以实现更高的速度（最高可达 fPCLK/8）。
                                           该参数可以是 @ref UART_Over_Sampling 中的值。此功能仅在
                                           STM32F100xx系列上可用，因此OverSampling参数应始终设置为16。 */
} UART_InitTypeDef;

/**
  * @brief HAL UART 状态结构体定义
  * @note  HAL UART 状态值是两个不同子状态的组合：gState 和 RxState。
  *        - gState 包含与全局句柄管理相关的UART状态信息，也包含与发送(Tx)操作相关的信息。
  *          gState 值编码遵循以下描述的位图：
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
  *        - RxState 包含与接收(Rx)操作相关的信息。
  *          RxState 值编码遵循以下描述的位图：
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
  HAL_UART_STATE_RESET             = 0x00U,    /* 外设尚未初始化
                                                  该值允许用于 gState 和 RxState */
  HAL_UART_STATE_READY             = 0x20U,    /* 外设已初始化并准备就绪
                                                  该值允许用于 gState 和 RxState */
  HAL_UART_STATE_BUSY              = 0x24U,    /* 正在进行内部处理
                                                  该值仅允许用于 gState */
  HAL_UART_STATE_BUSY_TX           = 0x21U,    /* 数据发送过程正在进行
                                                  该值仅允许用于 gState */
  HAL_UART_STATE_BUSY_RX           = 0x22U,    /* 数据接收过程正在进行
                                                  该值仅允许用于 RxState */
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    /* 数据发送和接收过程正在进行
                                                  既不用于 gState 也不用于 RxState。
                                                  该值是 gState 和 RxState 值组合（或运算）的结果 */
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    /* 超时状态
                                                  该值仅允许用于 gState */
  HAL_UART_STATE_ERROR             = 0xE0U     /* 错误状态
                                                  该值仅允许用于 gState */
} HAL_UART_StateTypeDef;

/**
  * @brief HAL UART 接收类型定义
  * @note  HAL UART 接收类型值旨在识别正在进行的接收类型。
  *        该参数可以是 @ref UART_Reception_Type_Values 中的值：
  *           HAL_UART_RECEPTION_STANDARD         = 0x00U, (标准接收)
  *           HAL_UART_RECEPTION_TOIDLE           = 0x01U, (接收直到完成或IDLE事件)
  */
typedef uint32_t HAL_UART_RxTypeTypeDef;

/**
  * @brief HAL UART 接收事件类型定义
  * @note  HAL UART 接收事件类型值旨在识别导致调用 RxEvent 回调的事件类型
  *        该参数可以是 @ref UART_RxEvent_Type_Values 中的值：
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
  USART_TypeDef                 *Instance;        /* UART 寄存器基地址        */

  UART_InitTypeDef              Init;             /* UART 通信参数      */

  const uint8_t                 *pTxBuffPtr;      /* 指向 UART 发送缓冲区的指针 */

  uint16_t                      TxXferSize;       /* UART 发送数据大小              */

  __IO uint16_t                 TxXferCount;      /* UART 发送计数器           */

  uint8_t                       *pRxBuffPtr;      /* 指向 UART 接收缓冲区的指针 */

  uint16_t                      RxXferSize;       /* UART 接收数据大小              */

  __IO uint16_t                 RxXferCount;      /* UART 接收计数器           */

  __IO HAL_UART_RxTypeTypeDef ReceptionType;      /* 正在进行的接收类型          */

  __IO HAL_UART_RxEventTypeTypeDef RxEventType;   /* 接收事件类型                   */

  DMA_HandleTypeDef             *hdmatx;          /* UART 发送 DMA 句柄参数      */

  DMA_HandleTypeDef             *hdmarx;          /* UART 接收 DMA 句柄参数      */

  HAL_LockTypeDef               Lock;             /* 锁定对象                     */

  __IO HAL_UART_StateTypeDef    gState;           /* 与全局句柄管理相关的 UART 状态信息
                                                       也与发送操作相关。
                                                       该参数可以是 @ref HAL_UART_StateTypeDef 中的值 */

  __IO HAL_UART_StateTypeDef    RxState;          /* 与接收操作相关的 UART 状态信息。
                                                       该参数可以是 @ref HAL_UART_StateTypeDef 中的值 */

  __IO uint32_t                 ErrorCode;        /* UART 错误代码                    */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /* UART 发送半完成回调函数        */
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            /* UART 发送完成回调函数             */
  void (* RxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /* UART 接收半完成回调函数        */
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            /* UART 接收完成回调函数             */
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             /* UART 错误回调函数                   */
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         /* UART 终止完成回调函数          */
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); /* UART 终止发送完成回调函数 */
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  /* UART 终止接收完成回调函数  */
  void (* WakeupCallback)(struct __UART_HandleTypeDef *huart);            /* UART 唤醒回调函数                  */
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); /* UART 接收事件回调函数     */

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           /* UART Msp 初始化回调函数                */
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         /* UART Msp 反初始化回调函数              */
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART 回调ID枚举定义
  */
typedef enum
{
  HAL_UART_TX_HALFCOMPLETE_CB_ID         = 0x00U,    /* UART 发送半完成回调 ID        */
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    /* UART 发送完成回调 ID             */
  HAL_UART_RX_HALFCOMPLETE_CB_ID         = 0x02U,    /* UART 接收半完成回调 ID        */
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    /* UART 接收完成回调 ID             */
  HAL_UART_ERROR_CB_ID                   = 0x04U,    /* UART 错误回调 ID                   */
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    /* UART 终止完成回调 ID          */
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    /* UART 终止发送完成回调 ID */
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    /* UART 终止接收完成回调 ID  */
  HAL_UART_WAKEUP_CB_ID                  = 0x08U,    /* UART 唤醒回调 ID                  */

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    /* UART MspInit 回调 ID                 */
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU     /* UART MspDeInit 回调 ID               */

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART 回调指针定义
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart);  /* 指向 UART 回调函数的指针 */
typedef  void (*pUART_RxEventCallbackTypeDef)(struct __UART_HandleTypeDef *huart, uint16_t Pos);   /* 指向 UART 接收事件特定回调函数的指针 */

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART 导出常量
  * @{
  */

/** @defgroup UART_Error_Code UART 错误代码
  * @{
  */
#define HAL_UART_ERROR_NONE              0x00000000U   /* 无错误            */
#define HAL_UART_ERROR_PE                0x00000001U   /* 奇偶校验错误        */
#define HAL_UART_ERROR_NE                0x00000002U   /* 噪声错误         */
#define HAL_UART_ERROR_FE                0x00000004U   /* 帧错误         */
#define HAL_UART_ERROR_ORE               0x00000008U   /* 溢出错误       */
#define HAL_UART_ERROR_DMA               0x00000010U   /* DMA 传输错误  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK 0x00000020U   /* 无效回调错误  */
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Word_Length UART 字长
  * @{
  */
#define UART_WORDLENGTH_8B                  0x00000000U  /* 8位数据位 */
#define UART_WORDLENGTH_9B                  ((uint32_t)USART_CR1_M)  /* 9位数据位 */
/**
  * @}
  */

/** @defgroup UART_Stop_Bits UART 停止位
  * @{
  */
#define UART_STOPBITS_1                     0x00000000U  /* 1个停止位 */
#define UART_STOPBITS_2                     ((uint32_t)USART_CR2_STOP_1)  /* 2个停止位 */
/**
  * @}
  */

/** @defgroup UART_Parity UART 奇偶校验
  * @{
  */
#define UART_PARITY_NONE                    0x00000000U  /* 无校验 */
#define UART_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)  /* 偶校验 */
#define UART_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS))  /* 奇校验 */
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control UART 硬件流控制
  * @{
  */
#define UART_HWCONTROL_NONE                  0x00000000U  /* 无硬件流控 */
#define UART_HWCONTROL_RTS                   ((uint32_t)USART_CR3_RTSE)  /* RTS 使能 */
#define UART_HWCONTROL_CTS                   ((uint32_t)USART_CR3_CTSE)  /* CTS 使能 */
#define UART_HWCONTROL_RTS_CTS               ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE))  /* RTS 和 CTS 使能 */
/**
  * @}
  */

/** @defgroup UART_Mode UART 传输模式
  * @{
  */
#define UART_MODE_RX                        ((uint32_t)USART_CR1_RE)  /* 接收模式 */
#define UART_MODE_TX                        ((uint32_t)USART_CR1_TE)  /* 发送模式 */
#define UART_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE | USART_CR1_RE))  /* 发送和接收模式 */
/**
  * @}
  */

/** @defgroup UART_State UART 状态
  * @{
  */
#define UART_STATE_DISABLE                  0x00000000U  /* 禁止 UART */
#define UART_STATE_ENABLE                   ((uint32_t)USART_CR1_UE)  /* 使能 UART */
/**
  * @}
  */

/** @defgroup UART_Over_Sampling UART 过采样
  * @{
  */
#define UART_OVERSAMPLING_16                    0x00000000U  /* 16倍过采样 */
#if defined(USART_CR1_OVER8)
#define UART_OVERSAMPLING_8                     ((uint32_t)USART_CR1_OVER8)  /* 8倍过采样 */
#endif /* USART_CR1_OVER8 */
/**
  * @}
  */

/** @defgroup UART_LIN_Break_Detection_Length  LIN 断路检测长度
  * @{
  */
#define UART_LINBREAKDETECTLENGTH_10B      0x00000000U  /* 10位断路检测 */
#define UART_LINBREAKDETECTLENGTH_11B      ((uint32_t)USART_CR2_LBDL)  /* 11位断路检测 */
/**
  * @}
  */

/** @defgroup UART_WakeUp_functions  UART 唤醒功能
  * @{
  */
#define UART_WAKEUPMETHOD_IDLELINE                0x00000000U  /* 空闲线路唤醒 */
#define UART_WAKEUPMETHOD_ADDRESSMARK             ((uint32_t)USART_CR1_WAKE)  /* 地址标记唤醒 */
/**
  * @}
  */

/** @defgroup UART_Flags   UART 标志位
  *        元素值约定: 0xXXXX
  *           - 0xXXXX  : SR寄存器中的标志掩码
  * @{
  */
#define UART_FLAG_CTS                       ((uint32_t)USART_SR_CTS)  /* CTS 变化标志 */
#define UART_FLAG_LBD                       ((uint32_t)USART_SR_LBD)  /* LIN 断路检测标志 */
#define UART_FLAG_TXE                       ((uint32_t)USART_SR_TXE)  /* 发送数据寄存器空标志 */
#define UART_FLAG_TC                        ((uint32_t)USART_SR_TC)   /* 发送完成标志 */
#define UART_FLAG_RXNE                      ((uint32_t)USART_SR_RXNE) /* 接收数据寄存器非空标志 */
#define UART_FLAG_IDLE                      ((uint32_t)USART_SR_IDLE) /* 空闲线路检测标志 */
#define UART_FLAG_ORE                       ((uint32_t)USART_SR_ORE)  /* 溢出错误标志 */
#define UART_FLAG_NE                        ((uint32_t)USART_SR_NE)   /* 噪声错误标志 */
#define UART_FLAG_FE                        ((uint32_t)USART_SR_FE)   /* 帧错误标志 */
#define UART_FLAG_PE                        ((uint32_t)USART_SR_PE)   /* 奇偶校验错误标志 */
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

#define UART_IT_PE                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_PEIE))  /* 奇偶校验错误中断 */
#define UART_IT_TXE                      ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TXEIE)) /* 发送数据寄存器空中断 */
#define UART_IT_TC                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TCIE))  /* 发送完成中断 */
#define UART_IT_RXNE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_RXNEIE)) /* 接收数据寄存器非空中断 */
#define UART_IT_IDLE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_IDLEIE)) /* 空闲线路检测中断 */

#define UART_IT_LBD                      ((uint32_t)(UART_CR2_REG_INDEX << 28U | USART_CR2_LBDIE))  /* LIN 断路检测中断 */

#define UART_IT_CTS                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_CTSIE))  /* CTS 中断 */
#define UART_IT_ERR                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_EIE))    /* 错误中断 */
/**
  * @}
  */

/** @defgroup UART_Reception_Type_Values  UART 接收类型值
  * @{
  */
#define HAL_UART_RECEPTION_STANDARD          (0x00000000U)             /* 标准接收                       */
#define HAL_UART_RECEPTION_TOIDLE            (0x00000001U)             /* 接收直到完成或IDLE事件  */
/**
  * @}
  */

/** @defgroup UART_RxEvent_Type_Values  UART 接收事件类型值
  * @{
  */
#define HAL_UART_RXEVENT_TC                  (0x00000000U)             /* 链接到传输完成事件的 RxEvent */
#define HAL_UART_RXEVENT_HT                  (0x00000001U)             /* 链接到半传输事件的 RxEvent     */
#define HAL_UART_RXEVENT_IDLE                (0x00000002U)             /* 链接到空闲事件的 RxEvent */
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
/**
  * @brief  复位UART句柄的状态(gState 和 RxState)
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/* 如果启用了回调注册功能，则需要将回调函数指针也重置为NULL */
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                    /* do..while(0)循环结构，确保宏定义的安全性 */ \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;       /* 将全局状态复位 */ \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;      /* 将接收状态复位 */ \
                                                       (__HANDLE__)->MspInitCallback = NULL;              /* 复位Msp初始化回调指针 */ \
                                                       (__HANDLE__)->MspDeInitCallback = NULL;            /* 复位Msp反初始化回调指针 */ \
                                                     } while(0U)
#else
/* 如果未启用回调注册功能，仅复位状态 */
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                    /* do..while(0)循环结构 */ \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;       /* 将全局状态复位 */ \
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;      /* 将接收状态复位 */ \
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @brief  刷新UART数据寄存器(DR)
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @note   该宏实际上是通过读取DR寄存器来清除接收缓冲区非空标志(RXNE)，
  *         常用于清除接收缓冲区。
  */
#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/**
  * @brief  检查指定的UART标志位是否被置位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __FLAG__ 指定需要检查的标志位。
  *        该参数可以是以下值之一:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (UART4和UART5不可用)
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

/**
  * @brief  清除指定的UART挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __FLAG__ 指定需要清除的标志位。
  *          该参数可以是以下值的任意组合:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (UART4和UART5不可用)。
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志。
  *            @arg UART_FLAG_TC:   发送完成标志。
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志。
  *
  * @note   PE (奇偶校验错误), FE (帧错误), NE (噪声错误), ORE (溢出错误)
  *          和 IDLE (空闲线路检测) 标志位通过软件序列清除:
  *          先读取 USART_SR 寄存器，然后读取 USART_DR 寄存器。
  * @note   RXNE 标志位也可以通过读取 USART_DR 寄存器来清除。
  * @note   TC 标志位也可以通过软件序列清除:
  *          先读取 USART_SR 寄存器，然后写入 USART_DR 寄存器。
  * @note   TXE 标志位只能通过写入 USART_DR 寄存器来清除。
  *
  * @retval 无
  */
#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  清除UART奇偶校验错误(PE)挂起标志。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @note   清除PE标志的序列：读取状态寄存器SR，然后读取数据寄存器DR。
  * @retval 无
  */
#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)      /* 通过读SR和DR序列清除PE标志 */ \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;                /* 定义临时变量 */ \
    tmpreg = (__HANDLE__)->Instance->SR;         /* 读取状态寄存器SR */ \
    tmpreg = (__HANDLE__)->Instance->DR;         /* 读取数据寄存器DR */ \
    UNUSED(tmpreg);                              /* 防止编译器产生未使用变量的警告 */ \
  } while(0U)

/**
  * @brief  清除UART帧错误(FE)挂起标志。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @note   FE标志清除序列与PE标志相同。
  * @retval 无
  */
#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/**
  * @brief  清除UART噪声错误(NE)挂起标志。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @note   NE标志清除序列与PE标志相同。
  * @retval 无
  */
#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/**
  * @brief  清除UART溢出错误(ORE)挂起标志。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @note   ORE标志清除序列与PE标志相同。
  * @retval 无
  */
#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/**
  * @brief  清除UART空闲线路(IDLE)挂起标志。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @note   IDLE标志清除序列与PE标志相同。
  * @retval 无
  */
#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/**
  * @brief  使能指定的UART中断。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __INTERRUPT__ 指定要使能的UART中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断(帧错误, 噪声错误, 溢出错误)
  * @note   该宏根据中断向量的高位索引值，判断中断控制位位于CR1、CR2还是CR3寄存器，
  *         然后执行或运算置位相应的中断使能位。
  * @retval 无
  */
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 |= ((__INTERRUPT__) & UART_IT_MASK)))

/**
  * @brief  禁用指定的UART中断。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __INTERRUPT__ 指定要禁用的UART中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断(帧错误, 噪声错误, 溢出错误)
  * @note   该宏根据中断向量的高位索引值，判断中断控制位位于CR1、CR2还是CR3寄存器，
  *         然后执行与运算清除相应的中断使能位。
  * @retval 无
  */
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ ((__INTERRUPT__) & UART_IT_MASK)))

/**
  * @brief  检查指定的UART中断源是否已使能。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __IT__ 指定要检查的UART中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS: CTS 变化中断 (UART4和UART5不可用)
  *            @arg UART_IT_LBD: LIN 断路检测中断
  *            @arg UART_IT_TXE: 发送数据寄存器空中断
  *            @arg UART_IT_TC:  发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_ERR: 错误中断
  * @retval __IT__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) (((((__IT__) >> 28U) == UART_CR1_REG_INDEX)? (__HANDLE__)->Instance->CR1:(((((uint32_t)(__IT__)) >> 28U) == UART_CR2_REG_INDEX)? \
                                                       (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (((uint32_t)(__IT__)) & UART_IT_MASK))

/**
  * @brief  使能CTS硬件流控制
  * @note   该宏允许为指定的UART实例使能CTS硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应充分理解后使用。
  * @note   由于该宏用于修改CTS硬件流控制功能的激活状态，无需进行
  *         USART实例的 Deinit/Init，调用该宏时应满足以下条件:
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)         /* 使能CTS流控 */ \
  do{                                                      \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);   /* 原子操作设置CR3寄存器的CTSE位 */ \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;         /* 同步更新句柄初始化结构体中的流控设置 */ \
  } while(0U)

/**
  * @brief  禁用CTS硬件流控制
  * @note   该宏允许为指定的UART实例禁用CTS硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应充分理解后使用。
  * @note   由于该宏用于修改CTS硬件流控制功能的激活状态，无需进行
  *         USART实例的 Deinit/Init，调用该宏时应满足以下条件:
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)         /* 禁用CTS流控 */ \
  do{                                                       \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  /* 原子操作清除CR3寄存器的CTSE位 */ \
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);       /* 同步更新句柄初始化结构体中的流控设置 */ \
  } while(0U)

/**
  * @brief  使能RTS硬件流控制
  *         该宏允许为指定的UART实例使能RTS硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应充分理解后使用。
  * @note   由于该宏用于修改RTS硬件流控制功能的激活状态，无需进行
  *         USART实例的 Deinit/Init，调用该宏时应满足以下条件:
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)        /* 使能RTS流控 */ \
  do{                                                     \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);  /* 原子操作设置CR3寄存器的RTSE位 */ \
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;        /* 同步更新句柄初始化结构体中的流控设置 */ \
  } while(0U)

/**
  * @brief  禁用RTS硬件流控制
  *         该宏允许为指定的UART实例禁用RTS硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应充分理解后使用。
  * @note   由于该宏用于修改RTS硬件流控制功能的激活状态，无需进行
  *         USART实例的 Deinit/Init，调用该宏时应满足以下条件:
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)        /* 禁用RTS流控 */ \
  do{                                                      \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); /* 原子操作清除CR3寄存器的RTSE位 */ \
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);      /* 同步更新句柄初始化结构体中的流控设置 */ \
  } while(0U)
#if defined(USART_CR3_ONEBIT)

/**
  * @brief  使能UART单比特采样方法
  * @param  __HANDLE__ 指定UART句柄。
  * @note   单比特采样可以减少接收器对噪声的敏感度，通常在波特率较高时使用。
  * @retval 无
  */
#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

/**
  * @brief  禁用UART单比特采样方法
  * @param  __HANDLE__ 指定UART句柄。
  * @retval 无
  */
#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                       &= (uint16_t)~((uint16_t)USART_CR3_ONEBIT))
#endif /* UART_ONE_BIT_SAMPLE_Feature */

/**
  * @brief  使能UART
  * @param  __HANDLE__ 指定UART句柄。
  * @note   设置CR1寄存器的UE位(UART Enable)。
  * @retval 无
  */
#define __HAL_UART_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/**
  * @brief  禁用UART
  * @param  __HANDLE__ 指定UART句柄。
  * @note   清除CR1寄存器的UE位(UART Enable)。
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
/* 初始化UART句柄结构体，配置寄存器 */
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
/* 初始化UART为半双工模式 */
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
/* 初始化UART为LIN模式 */
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
/* 初始化UART为多处理器模式 */
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
/* 反初始化UART，恢复寄存器为默认值 */
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
/* UART底层硬件初始化回调函数 (时钟、GPIO、中断等)，由用户在应用层实现 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
/* UART底层硬件反初始化回调函数，由用户在应用层实现 */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

/* 回调注册/注销函数  ***********************************/
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/* 注册UART回调函数 */
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback);
/* 注销UART回调函数 */
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);

/* 注册接收事件回调函数 */
HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback);
/* 注销接收事件回调函数 */
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group2 IO操作函数
  * @{
  */

/* IO操作函数 *******************************************************/
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
/* 暂停DMA传输 */
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
/* 恢复DMA传输 */
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
/* 停止DMA传输 */
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

/* 阻塞模式接收数据直到检测到空闲线路 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
/* 非阻塞模式(中断)接收数据直到检测到空闲线路 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 非阻塞模式(DMA)接收数据直到检测到空闲线路 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/* 获取接收事件类型 */
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(UART_HandleTypeDef *huart);

/* 传输中止函数 */
/* 中止正在进行的传输(阻塞模式) */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
/* 仅中止发送传输 */
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
/* 仅中止接收传输 */
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
/* 中止正在进行的传输(非阻塞模式/中断) */
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
/* 仅中止发送传输(非阻塞模式/中断) */
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
/* 仅中止接收传输(非阻塞模式/中断) */
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

/* UART中断处理函数，需要放在中断服务函数中调用 */
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

/* 接收事件回调函数 (用于ReceiveToIdle系列函数) */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* 外设控制函数  **************************************************/
/* 发送LIN断路信号 */
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
/* 进入多处理器静默模式 */
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
/* 退出多处理器静默模式 */
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
/* 使能半双工模式的发送器 */
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
/* 使能半双工模式的接收器 */
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* 外设状态函数  **************************************************/
/* 获取UART当前状态 */
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
/* 获取UART错误码 */
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
/**
  * @brief UART 中断标志掩码
  * 用于提取中断标志位
  */
#define UART_IT_MASK                     0x0000FFFFU

/* CR1寄存器索引，用于中断使能宏内部判断 */
#define UART_CR1_REG_INDEX               1U
/* CR2寄存器索引，用于中断使能宏内部判断 */
#define UART_CR2_REG_INDEX               2U
/* CR3寄存器索引，用于中断使能宏内部判断 */
#define UART_CR3_REG_INDEX               3U
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART 私有宏
  * @{
  */
/* 检查字长参数是否有效：8位或9位 */
#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))
/* 检查LIN模式字长参数是否有效：仅限8位 */
#define IS_UART_LIN_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B))
/* 检查停止位参数是否有效：1位或2位 */
#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_2))
/* 检查校验位参数是否有效：无校验、偶校验或奇校验 */
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))
/* 检查硬件流控参数是否有效：无、RTS、CTS或RTS_CTS */
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HWCONTROL_NONE) || \
                               ((CONTROL) == UART_HWCONTROL_RTS) || \
                               ((CONTROL) == UART_HWCONTROL_CTS) || \
                               ((CONTROL) == UART_HWCONTROL_RTS_CTS))
/* 检查模式参数是否有效：TX/RX模式组合 */
#define IS_UART_MODE(MODE) ((((MODE) & 0x0000FFF3U) == 0x00U) && ((MODE) != 0x00U))
/* 检查状态参数是否有效：使能或禁用 */
#define IS_UART_STATE(STATE) (((STATE) == UART_STATE_DISABLE) || \
                              ((STATE) == UART_STATE_ENABLE))
#if defined(USART_CR1_OVER8)
/* 检查过采样参数是否有效：16倍或8倍 */
#define IS_UART_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16) || \
                                        ((SAMPLING) == UART_OVERSAMPLING_8))
#endif /* USART_CR1_OVER8 */
/* 检查LIN模式过采样参数是否有效：仅限16倍 */
#define IS_UART_LIN_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16))
/* 检查LIN断路检测长度参数是否有效：10位或11位 */
#define IS_UART_LIN_BREAK_DETECT_LENGTH(LENGTH) (((LENGTH) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                 ((LENGTH) == UART_LINBREAKDETECTLENGTH_11B))
/* 检查唤醒方法参数是否有效：空闲线路或地址标记 */
#define IS_UART_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == UART_WAKEUPMETHOD_IDLELINE) || \
                                      ((WAKEUP) == UART_WAKEUPMETHOD_ADDRESSMARK))
/* 检查波特率参数是否有效：最大4.5Mbps */
#define IS_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 4500000U)
/* 检查UART地址参数是否有效：最大0x0F (4位) */
#define IS_UART_ADDRESS(ADDRESS) ((ADDRESS) <= 0x0FU)

/* 以下为波特率计算相关的内部宏 */
/* 计算16倍过采样下的分频系数 (DIV) */
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
/* 计算16倍过采样下的分频系数整数部分 */
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
/* 计算16倍过采样下的分频系数小数部分 */
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* 计算16倍过采样下的BRR寄存器值
   UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

/* 计算8倍过采样下的分频系数 (DIV) */
#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
/* 计算8倍过采样下的分频系数整数部分 */
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
/* 计算8倍过采样下的分频系数小数部分 */
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)
/* 计算8倍过采样下的BRR寄存器值
   UART BRR = mantissa + overflow + fraction
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

/* 启动中断接收的内部函数 */
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 启动DMA接收的内部函数 */
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
