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
  * 本软件根据在本软件组件根目录中的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
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
/** @defgroup UART_Exported_Types UART导出类型
  * @{
  */

/**
  * @brief UART 初始化结构体定义
  */
typedef struct
{
  uint32_t BaudRate;                  /*!< 该成员配置UART通信波特率。
                                           波特率使用以下公式计算：
                                           - 整数部分 = ((PCLKx) / (16 * (huart->Init.BaudRate)))
                                           - 小数部分 = ((整数部分 - ((uint32_t) 整数部分)) * 16) + 0.5 */

  uint32_t WordLength;                /*!< 指定在一帧中传输或接收的数据位数。
                                           该参数可以是 @ref UART_Word_Length 中的值 */

  uint32_t StopBits;                  /*!< 指定传输的停止位数。
                                           该参数可以是 @ref UART_Stop_Bits 中的值 */

  uint32_t Parity;                    /*!< 指定奇偶校验模式。
                                           该参数可以是 @ref UART_Parity 中的值
                                           @note 当启用奇偶校验时，计算出的奇偶校验位被插入
                                                 在传输数据的最高位位置（当字长设置为9位时为第9位；
                                                 当字长设置为8位时为第8位）。 */

  uint32_t Mode;                      /*!< 指定是启用还是禁用接收或发送模式。
                                           该参数可以是 @ref UART_Mode 中的值 */

  uint32_t HwFlowCtl;                 /*!< 指定是启用还是禁用硬件流控模式。
                                           该参数可以是 @ref UART_Hardware_Flow_Control 中的值 */

  uint32_t OverSampling;              /*!< 指定是启用还是禁用8倍过采样，以实现更高的速度（最高可达fPCLK/8）。
                                           该参数可以是 @ref UART_Over_Sampling 中的值。此功能仅在
                                           STM32F100xx系列上可用，因此OverSampling参数应始终设置为16。 */
} UART_InitTypeDef;

/**
  * @brief HAL UART 状态结构体定义
  * @note  HAL UART 状态值是两个不同子状态的组合：gState 和 RxState。
  *        - gState 包含与全局句柄管理相关的UART状态信息
  *          以及与发送操作相关的信息。
  *          gState 值编码遵循以下描述的位图：
  *          b7-b6  错误信息
  *             00 : 无错误
  *             01 : (未使用)
  *             10 : 超时
  *             11 : 错误
  *          b5     外设初始化状态
  *             0  : 复位 (外设未初始化)
  *             1  : 初始化完成 (外设已初始化，HAL UART Init函数已被调用)
  *          b4-b3  (未使用)
  *             xx : 应设置为00
  *          b2     内部处理状态
  *             0  : 就绪
  *             1  : 忙碌 (外设正忙于某些配置或内部操作)
  *          b1     (未使用)
  *             x  : 应设置为0
  *          b0     发送状态
  *             0  : 就绪 (无正在进行的发送操作)
  *             1  : 忙碌 (正在进行的发送操作)
  *        - RxState 包含与接收操作相关的信息。
  *          RxState 值编码遵循以下描述的位图：
  *          b7-b6  (未使用)
  *             xx : 应设置为00
  *          b5     外设初始化状态
  *             0  : 复位 (外设未初始化)
  *             1  : 初始化完成 (外设已初始化)
  *          b4-b2  (未使用)
  *            xxx : 应设置为000
  *          b1     接收状态
  *             0  : 就绪 (无正在进行的接收操作)
  *             1  : 忙碌 (正在进行的接收操作)
  *          b0     (未使用)
  *             x  : 应设置为0。
  */
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    /*!< 外设尚未初始化
                                                   该值允许用于gState和RxState */
  HAL_UART_STATE_READY             = 0x20U,    /*!< 外设已初始化并准备就绪
                                                   该值允许用于gState和RxState */
  HAL_UART_STATE_BUSY              = 0x24U,    /*!< 正在进行内部处理
                                                   该值仅允许用于gState */
  HAL_UART_STATE_BUSY_TX           = 0x21U,    /*!< 数据发送过程正在进行中
                                                   该值仅允许用于gState */
  HAL_UART_STATE_BUSY_RX           = 0x22U,    /*!< 数据接收过程正在进行中
                                                   该值仅允许用于RxState */
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    /*!< 数据发送和接收过程正在进行中
                                                   不用于gState或RxState。
                                                   该值是gState和RxState值的组合（或运算）结果 */
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    /*!< 超时状态
                                                   该值仅允许用于gState */
  HAL_UART_STATE_ERROR             = 0xE0U     /*!< 错误
                                                   该值仅允许用于gState */
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
  * @note  HAL UART 接收事件类型值旨在识别导致调用RxEvent回调的事件类型。
  *        该参数可以是 @ref UART_RxEvent_Type_Values 中的值：
  *           HAL_UART_RXEVENT_TC                 = 0x00U, (传输完成事件)
  *           HAL_UART_RXEVENT_HT                 = 0x01U, (半传输事件)
  *           HAL_UART_RXEVENT_IDLE               = 0x02U, (空闲事件)
  */
typedef uint32_t HAL_UART_RxEventTypeTypeDef;

/**
  * @brief  UART 句柄结构体定义
  */
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;        /*!< UART 寄存器基地址        */

  UART_InitTypeDef              Init;             /*!< UART 通信参数      */

  const uint8_t                 *pTxBuffPtr;      /*!< 指向UART发送缓冲区的指针 */

  uint16_t                      TxXferSize;       /*!< UART发送数据大小              */

  __IO uint16_t                 TxXferCount;      /*!< UART发送计数器           */

  uint8_t                       *pRxBuffPtr;      /*!< 指向UART接收缓冲区的指针 */

  uint16_t                      RxXferSize;       /*!< UART接收数据大小              */

  __IO uint16_t                 RxXferCount;      /*!< UART接收计数器           */

  __IO HAL_UART_RxTypeTypeDef ReceptionType;      /*!< 正在进行的接收类型          */

  __IO HAL_UART_RxEventTypeTypeDef RxEventType;   /*!< 接收事件的类型                   */

  DMA_HandleTypeDef             *hdmatx;          /*!< UART发送DMA句柄参数      */

  DMA_HandleTypeDef             *hdmarx;          /*!< UART接收DMA句柄参数      */

  HAL_LockTypeDef               Lock;             /*!< 锁定对象                     */

  __IO HAL_UART_StateTypeDef    gState;           /*!< 与全局句柄管理相关的UART状态信息
                                                       也与发送操作相关。
                                                       该参数可以是 @ref HAL_UART_StateTypeDef 中的值 */

  __IO HAL_UART_StateTypeDef    RxState;          /*!< 与接收操作相关的UART状态信息。
                                                       该参数可以是 @ref HAL_UART_StateTypeDef 中的值 */

  __IO uint32_t                 ErrorCode;        /*!< UART错误代码                    */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
  void (* TxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART发送半完成回调函数        */
  void (* TxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART发送完成回调函数             */
  void (* RxHalfCpltCallback)(struct __UART_HandleTypeDef *huart);        /*!< UART接收半完成回调函数        */
  void (* RxCpltCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART接收完成回调函数             */
  void (* ErrorCallback)(struct __UART_HandleTypeDef *huart);             /*!< UART错误回调函数                   */
  void (* AbortCpltCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART中止完成回调函数          */
  void (* AbortTransmitCpltCallback)(struct __UART_HandleTypeDef *huart); /*!< UART中止发送完成回调函数 */
  void (* AbortReceiveCpltCallback)(struct __UART_HandleTypeDef *huart);  /*!< UART中止接收完成回调函数  */
  void (* WakeupCallback)(struct __UART_HandleTypeDef *huart);            /*!< UART唤醒回调函数                  */
  void (* RxEventCallback)(struct __UART_HandleTypeDef *huart, uint16_t Pos); /*!< UART接收事件回调函数     */

  void (* MspInitCallback)(struct __UART_HandleTypeDef *huart);           /*!< UART Msp初始化回调函数                */
  void (* MspDeInitCallback)(struct __UART_HandleTypeDef *huart);         /*!< UART Msp反初始化回调函数              */
#endif  /* USE_HAL_UART_REGISTER_CALLBACKS */

} UART_HandleTypeDef;

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL UART 回调ID枚举定义
  */
typedef enum
{
  HAL_UART_TX_HALFCOMPLETE_CB_ID         = 0x00U,    /*!< UART发送半完成回调ID        */
  HAL_UART_TX_COMPLETE_CB_ID             = 0x01U,    /*!< UART发送完成回调ID             */
  HAL_UART_RX_HALFCOMPLETE_CB_ID         = 0x02U,    /*!< UART接收半完成回调ID        */
  HAL_UART_RX_COMPLETE_CB_ID             = 0x03U,    /*!< UART接收完成回调ID             */
  HAL_UART_ERROR_CB_ID                   = 0x04U,    /*!< UART错误回调ID                   */
  HAL_UART_ABORT_COMPLETE_CB_ID          = 0x05U,    /*!< UART中止完成回调ID          */
  HAL_UART_ABORT_TRANSMIT_COMPLETE_CB_ID = 0x06U,    /*!< UART中止发送完成回调ID */
  HAL_UART_ABORT_RECEIVE_COMPLETE_CB_ID  = 0x07U,    /*!< UART中止接收完成回调ID  */
  HAL_UART_WAKEUP_CB_ID                  = 0x08U,    /*!< UART唤醒回调ID                  */

  HAL_UART_MSPINIT_CB_ID                 = 0x0BU,    /*!< UART Msp初始化回调ID                 */
  HAL_UART_MSPDEINIT_CB_ID               = 0x0CU     /*!< UART Msp反初始化回调ID               */

} HAL_UART_CallbackIDTypeDef;

/**
  * @brief  HAL UART 回调指针定义
  */
typedef  void (*pUART_CallbackTypeDef)(UART_HandleTypeDef *huart);  /*!< 指向UART回调函数的指针 */
typedef  void (*pUART_RxEventCallbackTypeDef)(struct __UART_HandleTypeDef *huart, uint16_t Pos);   /*!< 指向UART接收事件特定回调函数的指针 */

#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup UART_Exported_Constants UART导出常量
  * @{
  */

/** @defgroup UART_Error_Code UART错误代码
  * @{
  */
#define HAL_UART_ERROR_NONE              0x00000000U   /*!< 无错误            */
#define HAL_UART_ERROR_PE                0x00000001U   /*!< 奇偶校验错误        */
#define HAL_UART_ERROR_NE                0x00000002U   /*!< 噪声错误         */
#define HAL_UART_ERROR_FE                0x00000004U   /*!< 帧错误         */
#define HAL_UART_ERROR_ORE               0x00000008U   /*!< 溢出错误       */
#define HAL_UART_ERROR_DMA               0x00000010U   /*!< DMA传输错误  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
#define  HAL_UART_ERROR_INVALID_CALLBACK 0x00000020U   /*!< 无效的回调错误  */
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup UART_Word_Length UART字长
  * @{
  */
#define UART_WORDLENGTH_8B                  0x00000000U   // 8位数据位
#define UART_WORDLENGTH_9B                  ((uint32_t)USART_CR1_M)  // 9位数据位
/**
  * @}
  */

/** @defgroup UART_Stop_Bits UART停止位
  * @{
  */
#define UART_STOPBITS_1                     0x00000000U   // 1个停止位
#define UART_STOPBITS_2                     ((uint32_t)USART_CR2_STOP_1)  // 2个停止位
/**
  * @}
  */

/** @defgroup UART_Parity UART奇偶校验
  * @{
  */
#define UART_PARITY_NONE                    0x00000000U   // 无校验
#define UART_PARITY_EVEN                    ((uint32_t)USART_CR1_PCE)  // 偶校验
#define UART_PARITY_ODD                     ((uint32_t)(USART_CR1_PCE | USART_CR1_PS))  // 奇校验
/**
  * @}
  */

/** @defgroup UART_Hardware_Flow_Control UART硬件流控
  * @{
  */
#define UART_HWCONTROL_NONE                  0x00000000U  // 无硬件流控
#define UART_HWCONTROL_RTS                   ((uint32_t)USART_CR3_RTSE)  // 仅使能RTS
#define UART_HWCONTROL_CTS                   ((uint32_t)USART_CR3_CTSE)  // 仅使能CTS
#define UART_HWCONTROL_RTS_CTS               ((uint32_t)(USART_CR3_RTSE | USART_CR3_CTSE))  // 使能RTS和CTS
/**
  * @}
  */

/** @defgroup UART_Mode UART传输模式
  * @{
  */
#define UART_MODE_RX                        ((uint32_t)USART_CR1_RE)  // 接收模式
#define UART_MODE_TX                        ((uint32_t)USART_CR1_TE)  // 发送模式
#define UART_MODE_TX_RX                     ((uint32_t)(USART_CR1_TE | USART_CR1_RE))  // 收发模式
/**
  * @}
  */

/** @defgroup UART_State UART状态
  * @{
  */
#define UART_STATE_DISABLE                  0x00000000U  // UART禁用
#define UART_STATE_ENABLE                   ((uint32_t)USART_CR1_UE)  // UART使能
/**
  * @}
  */

/** @defgroup UART_Over_Sampling UART过采样
  * @{
  */
#define UART_OVERSAMPLING_16                    0x00000000U  // 16倍过采样
#if defined(USART_CR1_OVER8)
#define UART_OVERSAMPLING_8                     ((uint32_t)USART_CR1_OVER8)  // 8倍过采样
#endif /* USART_CR1_OVER8 */
/**
  * @}
  */

/** @defgroup UART_LIN_Break_Detection_Length  UART LIN断路检测长度
  * @{
  */
#define UART_LINBREAKDETECTLENGTH_10B      0x00000000U  // 10位断路检测
#define UART_LINBREAKDETECTLENGTH_11B      ((uint32_t)USART_CR2_LBDL)  // 11位断路检测
/**
  * @}
  */

/** @defgroup UART_WakeUp_functions  UART唤醒功能
  * @{
  */
#define UART_WAKEUPMETHOD_IDLELINE                0x00000000U  // 空闲线路唤醒
#define UART_WAKEUPMETHOD_ADDRESSMARK             ((uint32_t)USART_CR1_WAKE)  // 地址标记唤醒
/**
  * @}
  */

/** @defgroup UART_Flags   UART标志位
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
#define UART_FLAG_PE                        ((uint32_t)USART_SR_PE)   // 奇偶错误标志
/**
  * @}
  */

/** @defgroup UART_Interrupt_definition  UART中断定义
  *        元素值约定: 0xY000XXXX
  *           - XXXX  : Y寄存器中的中断掩码（16位）
  *           - Y  : 中断源寄存器（2位）
  *                   - 0001: CR1寄存器
  *                   - 0010: CR2寄存器
  *                   - 0011: CR3寄存器
  * @{
  */

#define UART_IT_PE                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_PEIE))  // 奇偶错误中断
#define UART_IT_TXE                      ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TXEIE)) // 发送数据寄存器空中断
#define UART_IT_TC                       ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_TCIE))  // 发送完成中断
#define UART_IT_RXNE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_RXNEIE))// 接收数据寄存器非空中断
#define UART_IT_IDLE                     ((uint32_t)(UART_CR1_REG_INDEX << 28U | USART_CR1_IDLEIE))// 空闲线路检测中断

#define UART_IT_LBD                      ((uint32_t)(UART_CR2_REG_INDEX << 28U | USART_CR2_LBDIE))  // LIN断路检测中断

#define UART_IT_CTS                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_CTSIE)) // CTS中断
#define UART_IT_ERR                      ((uint32_t)(UART_CR3_REG_INDEX << 28U | USART_CR3_EIE))   // 错误中断
/**
  * @}
  */

/** @defgroup UART_Reception_Type_Values  UART接收类型值
  * @{
  */
#define HAL_UART_RECEPTION_STANDARD          (0x00000000U)             /*!< 标准接收                       */
#define HAL_UART_RECEPTION_TOIDLE            (0x00000001U)             /*!< 接收直到完成或IDLE事件  */
/**
  * @}
  */

/** @defgroup UART_RxEvent_Type_Values  UART RxEvent类型值
  * @{
  */
#define HAL_UART_RXEVENT_TC                  (0x00000000U)             /*!< RxEvent链接到传输完成事件 */
#define HAL_UART_RXEVENT_HT                  (0x00000001U)             /*!< RxEvent链接到半传输事件     */
#define HAL_UART_RXEVENT_IDLE                (0x00000002U)             /*!< RxEvent链接到空闲事件 */
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup UART_Exported_Macros UART导出宏
  * @{
  */
