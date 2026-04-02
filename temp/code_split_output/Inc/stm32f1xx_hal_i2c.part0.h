/**
  ******************************************************************************
  * @file    stm32f1xx_hal_i2c.h
  * @author  MCD Application Team
  * @brief   I2C HAL模块头文件。
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

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_I2C_H
#define __STM32F1xx_HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/
/** @defgroup I2C_Exported_Types I2C 导出类型
  * @{
  */

/** @defgroup I2C_Configuration_Structure_definition I2C 配置结构体定义
  * @brief  I2C 配置结构体定义
  * @{
  */
typedef struct
{
  uint32_t ClockSpeed;       /*!< 指定时钟频率。
                                  此参数必须设置为低于400kHz的值 */

  uint32_t DutyCycle;        /*!< 指定I2C快速模式下的占空比。
                                  此参数可以是 @ref I2C_duty_cycle_in_fast_mode 中的一个值 */

  uint32_t OwnAddress1;      /*!< 指定第一个设备自身地址。
                                  此参数可以是7位或10位地址。 */

  uint32_t AddressingMode;   /*!< 指定选择7位还是10位寻址模式。
                                  此参数可以是 @ref I2C_addressing_mode 中的一个值 */

  uint32_t DualAddressMode;  /*!< 指定是否选择双地址模式。
                                  此参数可以是 @ref I2C_dual_addressing_mode 中的一个值 */

  uint32_t OwnAddress2;      /*!< 如果选择了双地址模式，指定第二个设备自身地址
                                  此参数可以是7位地址。 */

  uint32_t GeneralCallMode;  /*!< 指定是否选择通用呼叫模式。
                                  此参数可以是 @ref I2C_general_call_addressing_mode 中的一个值 */

  uint32_t NoStretchMode;    /*!< 指定是否选择无时钟拉伸模式。
                                  此参数可以是 @ref I2C_nostretch_mode 中的一个值 */

} I2C_InitTypeDef;

/**
  * @}
  */

/** @defgroup HAL_state_structure_definition HAL 状态结构体定义
  * @brief  HAL 状态结构体定义
  * @note  HAL I2C 状态值的编码遵循下面描述的位图：
  *          b7-b6  错误信息
  *             00 : 无错误
  *             01 : 中止 (正在处理用户中止请求)
  *             10 : 超时
  *             11 : 错误
  *          b5     外设初始化状态
  *             0  : 复位 (外设未初始化)
  *             1  : 初始化完成 (外设已初始化且准备就绪，调用了HAL I2C Init函数)
  *          b4     (未使用)
  *             x  : 应设置为0
  *          b3
  *             0  : 就绪或忙碌 (无正在进行的监听模式)
  *             1  : 监听 (外设处于地址监听模式)
  *          b2     内部过程状态
  *             0  : 就绪
  *             1  : 忙碌 (外设正忙于某些配置或内部操作)
  *          b1     接收状态
  *             0  : 就绪 (无正在进行的接收操作)
  *             1  : 忙碌 (正在进行接收操作)
  *          b0     发送状态
  *             0  : 就绪 (无正在进行的发送操作)
  *             1  : 忙碌 (正在进行发送操作)
  * @{
  */
typedef enum
{
  HAL_I2C_STATE_RESET             = 0x00U,   /*!< 外设尚未初始化         */
  HAL_I2C_STATE_READY             = 0x20U,   /*!< 外设已初始化并准备就绪  */
  HAL_I2C_STATE_BUSY              = 0x24U,   /*!< 正在进行内部处理            */
  HAL_I2C_STATE_BUSY_TX           = 0x21U,   /*!< 正在进行数据传输过程      */
  HAL_I2C_STATE_BUSY_RX           = 0x22U,   /*!< 正在进行数据接收过程         */
  HAL_I2C_STATE_LISTEN            = 0x28U,   /*!< 正在进行地址监听模式            */
  HAL_I2C_STATE_BUSY_TX_LISTEN    = 0x29U,   /*!< 正在进行地址监听模式和数据传输
                                                 过程                         */
  HAL_I2C_STATE_BUSY_RX_LISTEN    = 0x2AU,   /*!< 正在进行地址监听模式和数据接收
                                                 过程                         */
  HAL_I2C_STATE_ABORT             = 0x60U,   /*!< 正在处理用户中止请求                */
  HAL_I2C_STATE_TIMEOUT           = 0xA0U,   /*!< 超时状态                             */
  HAL_I2C_STATE_ERROR             = 0xE0U    /*!< 错误                                     */

} HAL_I2C_StateTypeDef;

/**
  * @}
  */

/** @defgroup HAL_mode_structure_definition HAL 模式结构体定义
  * @brief  HAL 模式结构体定义
  * @note  HAL I2C 模式值的编码遵循下面描述的位图 :\n
  *          b7     (未使用)\n
  *             x  : 应设置为0\n
  *          b6\n
  *             0  : 无\n
  *             1  : 内存 (HAL I2C 通信处于内存模式)\n
  *          b5\n
  *             0  : 无\n
  *             1  : 从机 (HAL I2C 通信处于从机模式)\n
  *          b4\n
  *             0  : 无\n
  *             1  : 主机 (HAL I2C 通信处于主机模式)\n
  *          b3-b2-b1-b0  (未使用)\n
  *             xxxx : 应设置为0000
  * @{
  */
typedef enum
{
  HAL_I2C_MODE_NONE               = 0x00U,   /*!< 无正在进行的I2C通信             */
  HAL_I2C_MODE_MASTER             = 0x10U,   /*!< I2C通信处于主机模式       */
  HAL_I2C_MODE_SLAVE              = 0x20U,   /*!< I2C通信处于从机模式        */
  HAL_I2C_MODE_MEM                = 0x40U    /*!< I2C通信处于内存模式       */

} HAL_I2C_ModeTypeDef;

/**
  * @}
  */

/** @defgroup I2C_Error_Code_definition I2C 错误代码定义
  * @brief  I2C 错误代码定义
  * @{
  */
#define HAL_I2C_ERROR_NONE              0x00000000U    /*!< 无错误              */
#define HAL_I2C_ERROR_BERR              0x00000001U    /*!< 总线错误            */
#define HAL_I2C_ERROR_ARLO              0x00000002U    /*!< 仲裁丢失错误            */
#define HAL_I2C_ERROR_AF                0x00000004U    /*!< 应答失败错误              */
#define HAL_I2C_ERROR_OVR               0x00000008U    /*!< 溢出/欠载错误             */
#define HAL_I2C_ERROR_DMA               0x00000010U    /*!< DMA传输错误    */
#define HAL_I2C_ERROR_TIMEOUT           0x00000020U    /*!< 超时错误         */
#define HAL_I2C_ERROR_SIZE              0x00000040U    /*!< 大小管理错误 */
#define HAL_I2C_ERROR_DMA_PARAM         0x00000080U    /*!< DMA参数错误   */
#define HAL_I2C_WRONG_START             0x00000200U    /*!< 错误的起始条件错误     */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define HAL_I2C_ERROR_INVALID_CALLBACK  0x00000100U    /*!< 无效的回调函数错误 */
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup I2C_handle_Structure_definition I2C 句柄结构体定义
  * @brief  I2C 句柄结构体定义
  * @{
  */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
typedef struct __I2C_HandleTypeDef
#else
typedef struct
#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
{
  I2C_TypeDef                *Instance;      /*!< I2C 寄存器基地址               */

  I2C_InitTypeDef            Init;           /*!< I2C 通信参数             */

  uint8_t                    *pBuffPtr;      /*!< 指向I2C传输缓冲区的指针           */

  uint16_t                   XferSize;       /*!< I2C 传输大小                        */

  __IO uint16_t              XferCount;      /*!< I2C 传输计数器                     */

  __IO uint32_t              XferOptions;    /*!< I2C 传输选项                     */

  __IO uint32_t              PreviousState;  /*!< I2C 通信前一个状态和模式
                                                  上下文，供内部使用               */

  DMA_HandleTypeDef          *hdmatx;        /*!< I2C 发送 DMA 句柄参数             */

  DMA_HandleTypeDef          *hdmarx;        /*!< I2C 接收 DMA 句柄参数             */

  HAL_LockTypeDef            Lock;           /*!< I2C 锁定对象                       */

  __IO HAL_I2C_StateTypeDef  State;          /*!< I2C 通信状态                  */

  __IO HAL_I2C_ModeTypeDef   Mode;           /*!< I2C 通信模式                   */

  __IO uint32_t              ErrorCode;      /*!< I2C 错误代码                           */

  __IO uint32_t              Devaddress;     /*!< I2C 目标设备地址                */

  __IO uint32_t              Memaddress;     /*!< I2C 目标内存地址                */

  __IO uint32_t              MemaddSize;     /*!< I2C 目标内存地址大小          */

  __IO uint32_t              EventCount;     /*!< I2C 事件计数器                        */


#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
  void (* MasterTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);           /*!< I2C 主机发送传输完成回调函数 */
  void (* MasterRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);           /*!< I2C 主机接收传输完成回调函数 */
  void (* SlaveTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);            /*!< I2C 从机发送传输完成回调函数  */
  void (* SlaveRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);            /*!< I2C 从机接收传输完成回调函数  */
  void (* ListenCpltCallback)(struct __I2C_HandleTypeDef *hi2c);             /*!< I2C 监听完成回调函数              */
  void (* MemTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C 内存发送传输完成回调函数 */
  void (* MemRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C 内存接收传输完成回调函数 */
  void (* ErrorCallback)(struct __I2C_HandleTypeDef *hi2c);                  /*!< I2C 错误回调函数                        */
  void (* AbortCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C 中止回调函数                        */

  void (* AddrCallback)(struct __I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);  /*!< I2C 从机地址匹配回调函数 */

  void (* MspInitCallback)(struct __I2C_HandleTypeDef *hi2c);                /*!< I2C Msp 初始化回调函数                     */
  void (* MspDeInitCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Msp 反初始化回调函数                   */

#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
} I2C_HandleTypeDef;

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL I2C 回调ID枚举定义
  */
typedef enum
{
  HAL_I2C_MASTER_TX_COMPLETE_CB_ID      = 0x00U,    /*!< I2C 主机发送传输完成回调ID  */
  HAL_I2C_MASTER_RX_COMPLETE_CB_ID      = 0x01U,    /*!< I2C 主机接收传输完成回调ID  */
  HAL_I2C_SLAVE_TX_COMPLETE_CB_ID       = 0x02U,    /*!< I2C 从机发送传输完成回调ID   */
  HAL_I2C_SLAVE_RX_COMPLETE_CB_ID       = 0x03U,    /*!< I2C 从机接收传输完成回调ID   */
  HAL_I2C_LISTEN_COMPLETE_CB_ID         = 0x04U,    /*!< I2C 监听完成回调ID               */
  HAL_I2C_MEM_TX_COMPLETE_CB_ID         = 0x05U,    /*!< I2C 内存发送传输回调ID            */
  HAL_I2C_MEM_RX_COMPLETE_CB_ID         = 0x06U,    /*!< I2C 内存接收传输完成回调ID  */
  HAL_I2C_ERROR_CB_ID                   = 0x07U,    /*!< I2C 错误回调ID                         */
  HAL_I2C_ABORT_CB_ID                   = 0x08U,    /*!< I2C 中止回调ID                         */

  HAL_I2C_MSPINIT_CB_ID                 = 0x09U,    /*!< I2C Msp 初始化回调ID                      */
  HAL_I2C_MSPDEINIT_CB_ID               = 0x0AU     /*!< I2C Msp 反初始化回调ID                    */

} HAL_I2C_CallbackIDTypeDef;

/**
  * @brief  HAL I2C 回调指针定义
  */
typedef  void (*pI2C_CallbackTypeDef)(I2C_HandleTypeDef *hi2c); /*!< 指向I2C回调函数的指针 */
typedef  void (*pI2C_AddrCallbackTypeDef)(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode); /*!< 指向I2C地址匹配回调函数的指针 */

#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/**
  * @}
  */
/* 导出常量 --------------------------------------------------------*/

/** @defgroup I2C_Exported_Constants I2C 导出常量
  * @{
  */

/** @defgroup I2C_duty_cycle_in_fast_mode I2C 快速模式下的占空比
  * @{
  */
#define I2C_DUTYCYCLE_2                 0x00000000U  // 快速模式 Tlow/Thigh = 2
#define I2C_DUTYCYCLE_16_9              I2C_CCR_DUTY // 快速模式 Tlow/Thigh = 16/9
/**
  * @}
  */

/** @defgroup I2C_addressing_mode I2C 寻址模式
  * @{
  */
#define I2C_ADDRESSINGMODE_7BIT         0x00004000U  // 7位寻址模式
#define I2C_ADDRESSINGMODE_10BIT        (I2C_OAR1_ADDMODE | 0x00004000U) // 10位寻址模式
/**
  * @}
  */

/** @defgroup I2C_dual_addressing_mode  I2C 双地址模式
  * @{
  */
#define I2C_DUALADDRESS_DISABLE        0x00000000U   // 禁用双地址模式
#define I2C_DUALADDRESS_ENABLE         I2C_OAR2_ENDUAL // 使能双地址模式
/**
  * @}
  */

/** @defgroup I2C_general_call_addressing_mode I2C 通用呼叫寻址模式
  * @{
  */
#define I2C_GENERALCALL_DISABLE        0x00000000U   // 禁用通用呼叫模式
#define I2C_GENERALCALL_ENABLE         I2C_CR1_ENGC  // 使能通用呼叫模式
/**
  * @}
  */

/** @defgroup I2C_nostretch_mode I2C 无时钟拉伸模式
  * @{
  */
#define I2C_NOSTRETCH_DISABLE          0x00000000U   // 禁用时钟拉伸 (允许时钟拉伸)
#define I2C_NOSTRETCH_ENABLE           I2C_CR1_NOSTRETCH // 使能无时钟拉伸 (禁止时钟拉伸)
/**
  * @}
  */

/** @defgroup I2C_Memory_Address_Size I2C 内存地址大小
  * @{
  */
#define I2C_MEMADD_SIZE_8BIT            0x00000001U  // 8位内存地址
#define I2C_MEMADD_SIZE_16BIT           0x00000010U  // 16位内存地址
/**
  * @}
  */

/** @defgroup I2C_XferDirection_definition I2C 传输方向定义
  * @{
  */
#define I2C_DIRECTION_RECEIVE           0x00000000U  // 接收方向
#define I2C_DIRECTION_TRANSMIT          0x00000001U  // 发送方向
/**
  * @}
  */

/** @defgroup I2C_XferOptions_definition I2C 传输选项定义
  * @{
  */
#define  I2C_FIRST_FRAME                0x00000001U  // 第一帧
#define  I2C_FIRST_AND_NEXT_FRAME       0x00000002U  // 第一帧和下一帧
#define  I2C_NEXT_FRAME                 0x00000004U  // 下一帧
#define  I2C_FIRST_AND_LAST_FRAME       0x00000008U  // 第一帧和最后一帧
#define  I2C_LAST_FRAME_NO_STOP         0x00000010U  // 最后一帧无停止条件
#define  I2C_LAST_FRAME                 0x00000020U  // 最后一帧

/* List of XferOptions in usage of :
 * 1- Restart condition in all use cases (direction change or not)
 */
#define  I2C_OTHER_FRAME                (0x00AA0000U) // 其他帧
#define  I2C_OTHER_AND_LAST_FRAME       (0xAA000000U) // 其他帧和最后一帧
/**
  * @}
  */

/** @defgroup I2C_Interrupt_configuration_definition I2C 中断配置定义
  * @brief I2C 中断定义
  *        元素值约定: 0xXXXXXXXX
  *           - XXXXXXXX  : 中断控制掩码
  * @{
  */
#define I2C_IT_BUF                      I2C_CR2_ITBUFEN // 缓冲区中断使能
#define I2C_IT_EVT                      I2C_CR2_ITEVTEN // 事件中断使能
#define I2C_IT_ERR                      I2C_CR2_ITERREN // 错误中断使能
/**
  * @}
  */

/** @defgroup I2C_Flag_definition I2C 标志定义
  * @{
  */

#define I2C_FLAG_OVR                    0x00010800U  // 溢出/欠载标志
#define I2C_FLAG_AF                     0x00010400U  // 应答失败标志
#define I2C_FLAG_ARLO                   0x00010200U  // 仲裁丢失标志
#define I2C_FLAG_BERR                   0x00010100U  // 总线错误标志
#define I2C_FLAG_TXE                    0x00010080U  // 数据寄存器为空(发送)
#define I2C_FLAG_RXNE                   0x00010040U  // 数据寄存器非空(接收)
#define I2C_FLAG_STOPF                  0x00010010U  // 停止检测标志
#define I2C_FLAG_ADD10                  0x00010008U  // 10位头序列标志
#define I2C_FLAG_BTF                    0x00010004U  // 字节传输结束标志
#define I2C_FLAG_ADDR                   0x00010002U  // 地址发送标志
#define I2C_FLAG_SB                     0x00010001U  // 起始位标志
#define I2C_FLAG_DUALF                  0x00100080U  // 双地址标志
#define I2C_FLAG_GENCALL                0x00100010U  // 通用呼叫标志
#define I2C_FLAG_TRA                    0x00100004U  // 发送/接收标志
#define I2C_FLAG_BUSY                   0x00100002U  // 总线忙标志
#define I2C_FLAG_MSL                    0x00100001U  // 主从模式标志
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 -----------------------------------------------------------*/

/** @defgroup I2C_Exported_Macros I2C 导出宏
  * @{
  */

/** @brief 重置I2C句柄状态。
  * @param  __HANDLE__ 指定I2C句柄。
  * @retval 无
  */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                do{                                                   \
                                                                    (__HANDLE__)->State = HAL_I2C_STATE_RESET;       \
                                                                    (__HANDLE__)->MspInitCallback = NULL;            \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                                  } while(0)
#else
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_I2C_STATE_RESET)
#endif

/** @brief  使能或禁用指定的I2C中断。
  * @param  __HANDLE__ 指定I2C句柄。
  * @param  __INTERRUPT__ 指定要使能或禁用的中断源。
  *         此参数可以是以下值之一:
  *            @arg I2C_IT_BUF: 缓冲区中断使能
  *            @arg I2C_IT_EVT: 事件中断使能
  *            @arg I2C_IT_ERR: 错误中断使能
  * @retval 无
  */
#define __HAL_I2C_ENABLE_IT(__HANDLE__, __INTERRUPT__)   SET_BIT((__HANDLE__)->Instance->CR2,(__INTERRUPT__)) // 使能中断
#define __HAL_I2C_DISABLE_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT((__HANDLE__)->Instance->CR2, (__INTERRUPT__)) // 禁用中断

/** @brief  检查指定的I2C中断源是否使能。
  * @param  __HANDLE__ 指定I2C句柄。
  * @param  __INTERRUPT__ 指定要检查的I2C中断源。
  *          此参数可以是以下值之一:
  *            @arg I2C_IT_BUF: 缓冲区中断使能
  *            @arg I2C_IT_EVT: 事件中断使能
  *            @arg I2C_IT_ERR: 错误中断使能
  * @retval __INTERRUPT__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_I2C_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->CR2 & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)
