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
/** @brief  检查指定的 I2C 标志位是否被置位。
  * @param  __HANDLE__ 指定 I2C 句柄，该句柄包含了 I2C 模块的配置信息。
  * @param  __FLAG__ 指定需要检查的标志位。
  *         该参数可以是以下值之一：
  *            @arg I2C_FLAG_OVR: 溢出/下溢标志位
  *            @arg I2C_FLAG_AF: 应答失败标志位
  *            @arg I2C_FLAG_ARLO: 仲裁丢失标志位
  *            @arg I2C_FLAG_BERR: 总线错误标志位
  *            @arg I2C_FLAG_TXE: 数据寄存器为空标志位
  *            @arg I2C_FLAG_RXNE: 数据寄存器非空标志位
  *            @arg I2C_FLAG_STOPF: 停止位检测标志位
  *            @arg I2C_FLAG_ADD10: 10位头发送标志位
  *            @arg I2C_FLAG_BTF: 字节传输结束标志位
  *            @arg I2C_FLAG_ADDR: 地址发送标志位
  *                                地址匹配标志位
  *            @arg I2C_FLAG_SB: 起始位标志位
  *            @arg I2C_FLAG_DUALF: 双地址标志位
  *            @arg I2C_FLAG_GENCALL: 广播呼叫头标志位
  *            @arg I2C_FLAG_TRA: 发送/接收模式标志位
  *            @arg I2C_FLAG_BUSY: 总线忙标志位
  *            @arg I2C_FLAG_MSL: 主/从模式标志位
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
/* 获取 I2C 标志位状态的宏定义 */
/* 逻辑说明：通过判断标志位的高16位（用于区分SR1或SR2寄存器）来选择读取SR1还是SR2寄存器，
   然后与掩码后的标志位进行与运算，判断是否置位 */
#define __HAL_I2C_GET_FLAG(__HANDLE__, __FLAG__) ((((uint8_t)((__FLAG__) >> 16U)) == 0x01U) ? \
                                                  (((((__HANDLE__)->Instance->SR1) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET) : \
                                                  (((((__HANDLE__)->Instance->SR2) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET))

/** @brief  清除 I2C 挂起标志位，这些标志位通过在特定位置写 0 来清除（实际操作是读取寄存器后写0，这里直接对SR1赋值）。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @param  __FLAG__ 指定需要清除的标志位。
  *         该参数可以是以下值的任意组合：
  *            @arg I2C_FLAG_OVR: 溢出/下溢标志位 (从模式)
  *            @arg I2C_FLAG_AF: 应答失败标志位
  *            @arg I2C_FLAG_ARLO: 仲裁丢失标志位 (主模式)
  *            @arg I2C_FLAG_BERR: 总线错误标志位
  * @retval 无
  */
/* 清除 I2C 标志位的宏定义 */
/* 原理：对 SR1 寄存器写入取反后的值（对应位写0清除），仅清除掩码范围内的位 */
#define __HAL_I2C_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR1 = ~((__FLAG__) & I2C_FLAG_MASK))

/** @brief  清除 I2C ADDR 挂起标志位。
  * @param  __HANDLE__ 指定 I2C 句柄。
  *         该参数可以是 I2C，其中 x: 1, 2, 或 3 用于选择 I2C 外设。
  * @retval 无
  */
/* 清除 ADDR 标志位的宏定义 */
/* 注意：清除 ADDR 标志位需要特定的软件时序：先读 SR1，再读 SR2。
   这里定义了一个临时变量 tmpreg 来执行这些读取操作。 */
#define __HAL_I2C_CLEAR_ADDRFLAG(__HANDLE__)    \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR1;       \
    tmpreg = (__HANDLE__)->Instance->SR2;       \
    UNUSED(tmpreg);                             \
  } while(0)

/** @brief  清除 I2C STOPF 挂起标志位。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @retval 无
  */
/* 清除 STOPF 标志位的宏定义 */
/* 注意：清除 STOPF 标志位需要特定的软件时序：先读 SR1，然后写 CR1 寄存器。
   这里通过 SET_BIT 重置 CR1 的 PE 位来完成清除操作。 */
#define __HAL_I2C_CLEAR_STOPFLAG(__HANDLE__)           \
  do{                                                  \
    __IO uint32_t tmpreg = 0x00U;                      \
    tmpreg = (__HANDLE__)->Instance->SR1;              \
    SET_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE);  \
    UNUSED(tmpreg);                                    \
  } while(0)

/** @brief  使能指定的 I2C 外设。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @retval 无
  */
/* 使能 I2C 外设：置位 CR1 寄存器的 PE 位 */
#define __HAL_I2C_ENABLE(__HANDLE__)                  SET_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE)

/** @brief  禁用指定的 I2C 外设。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @retval 无
  */
/* 禁用 I2C 外设：清除 CR1 寄存器的 PE 位 */
#define __HAL_I2C_DISABLE(__HANDLE__)                 CLEAR_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE)

/**
  * @}
  */

/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup I2C_Exported_Functions
  * @{
  */

/** @addtogroup I2C_Exported_Functions_Group1 初始化和反初始化函数
  * @{
  */
/* 初始化和反初始化函数 ******************************************************/
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);  // 初始化 I2C 外设，配置参数
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c); // 反初始化 I2C 外设，恢复默认状态
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);           // MSP 初始化回调函数，用于配置 GPIO、时钟、中断等底层硬件
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);         // MSP 反初始化回调函数，用于释放底层硬件资源

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_I2C_RegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID, pI2C_CallbackTypeDef pCallback); // 注册用户自定义回调函数
HAL_StatusTypeDef HAL_I2C_UnRegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID); // 注销回调函数，恢复默认

HAL_StatusTypeDef HAL_I2C_RegisterAddrCallback(I2C_HandleTypeDef *hi2c, pI2C_AddrCallbackTypeDef pCallback); // 注册地址匹配回调函数
HAL_StatusTypeDef HAL_I2C_UnRegisterAddrCallback(I2C_HandleTypeDef *hi2c); // 注销地址匹配回调函数
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group2 输入输出操作函数
  * @{
  */
/* IO 操作函数  ****************************************************/
/******* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout); // 主机发送数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);  // 主机接收数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout); // 从机发送数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout);  // 从机接收数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout); // 写入指定设备的指定内存地址（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);  // 读取指定设备的指定内存地址（阻塞模式）
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout); // 检测设备是否就绪（阻塞模式）

/******* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size); // 主机发送数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);  // 主机接收数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size); // 从机发送数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);  // 从机接收数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size); // 写入内存地址（中断模式）
HAL_StatusTypeDef HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);  // 读取内存地址（中断模式）

HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 主机顺序发送（中断模式）
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 主机顺序接收（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 从机顺序发送（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 从机顺序接收（中断模式）
HAL_StatusTypeDef HAL_I2C_EnableListen_IT(I2C_HandleTypeDef *hi2c); // 使能监听模式（中断模式），用于从机地址匹配监听
HAL_StatusTypeDef HAL_I2C_DisableListen_IT(I2C_HandleTypeDef *hi2c); // 禁用监听模式
HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress); // 主机中止传输（中断模式）

/******* 非阻塞模式：DMA 方式 */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size); // 主机发送数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);  // 主机接收数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size); // 从机发送数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);  // 从机接收数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size); // 写入内存地址（DMA模式）
HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);  // 读取内存地址（DMA模式）

HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 主机顺序发送（DMA模式）
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 主机顺序接收（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 从机顺序发送（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 从机顺序接收（DMA模式）
/**
  * @}
  */

/** @addtogroup I2C_IRQ_Handler_and_Callbacks IRQ 处理程序和回调函数
 * @{
 */
/******* I2C IRQHandler 和回调函数，用于非阻塞模式 (中断和 DMA) */
void HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c); // I2C 事件中断处理函数
void HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c); // I2C 错误中断处理函数
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c); // 主机发送完成回调函数
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c); // 主机接收完成回调函数
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);  // 从机发送完成回调函数
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);  // 从机接收完成回调函数
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode); // 地址匹配回调函数
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c); // 监听完成回调函数
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c); // 内存写入完成回调函数
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c); // 内存读取完成回调函数
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c); // 错误回调函数
void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c); // 中止传输完成回调函数
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group3 外设状态、模式和错误函数
  * @{
  */
/* 外设状态、模式和错误函数  *********************************/
HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c); // 获取 I2C 当前状态（如就绪、忙、错误等）
HAL_I2C_ModeTypeDef HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c);   // 获取 I2C 当前模式（主机模式、从机模式）
uint32_t HAL_I2C_GetError(I2C_HandleTypeDef *hi2c); // 获取 I2C 错误代码

/**
  * @}
  */

/**
  * @}
  */
/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup I2C_Private_Constants I2C 私有常量
  * @{
  */
#define I2C_FLAG_MASK                    0x0000FFFFU  // I2C 标志位掩码，用于提取有效的标志位
#define I2C_MIN_PCLK_FREQ_STANDARD       2000000U     /*!< 标准模式下的最小 PCLK 频率：2 MHz */
#define I2C_MIN_PCLK_FREQ_FAST           4000000U     /*!< 快速模式下的最小 PCLK 频率：4 MHz */
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup I2C_Private_Macros I2C 私有宏
  * @{
  */

/* 检查 PCLK 时钟频率是否满足 I2C 速度要求 */
#define I2C_MIN_PCLK_FREQ(__PCLK__, __SPEED__)             (((__SPEED__) <= 100000U) ? ((__PCLK__) < I2C_MIN_PCLK_FREQ_STANDARD) : ((__PCLK__) < I2C_MIN_PCLK_FREQ_FAST))

/* 计算时钟控制寄存器 (CCR) 的值 */
#define I2C_CCR_CALCULATION(__PCLK__, __SPEED__, __COEFF__)     (((((__PCLK__) - 1U)/((__SPEED__) * (__COEFF__))) + 1U) & I2C_CCR_CCR)

/* 计算频率范围，单位 MHz */
#define I2C_FREQRANGE(__PCLK__)                            ((__PCLK__)/1000000U)

/* 计算上升时间 */
#define I2C_RISE_TIME(__FREQRANGE__, __SPEED__)            (((__SPEED__) <= 100000U) ? ((__FREQRANGE__) + 1U) : ((((__FREQRANGE__) * 300U) / 1000U) + 1U))

/* 计算标准模式下的 CCR 值 */
#define I2C_SPEED_STANDARD(__PCLK__, __SPEED__)            ((I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 2U) < 4U)? 4U:I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 2U))

/* 计算快速模式下的 CCR 值 */
#define I2C_SPEED_FAST(__PCLK__, __SPEED__, __DUTYCYCLE__) (((__DUTYCYCLE__) == I2C_DUTYCYCLE_2)? I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 3U) : (I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 25U) | I2C_DUTYCYCLE_16_9))

/* 根据速度模式自动选择计算标准模式或快速模式的 CCR 值 */
#define I2C_SPEED(__PCLK__, __SPEED__, __DUTYCYCLE__)      (((__SPEED__) <= 100000U)? (I2C_SPEED_STANDARD((__PCLK__), (__SPEED__))) : \
                                                                  ((I2C_SPEED_FAST((__PCLK__), (__SPEED__), (__DUTYCYCLE__)) & I2C_CCR_CCR) == 0U)? 1U : \
                                                                  ((I2C_SPEED_FAST((__PCLK__), (__SPEED__), (__DUTYCYCLE__))) | I2C_CCR_FS))

/* 将 7 位地址转换为写地址（最低位为 0） */
#define I2C_7BIT_ADD_WRITE(__ADDRESS__)                    ((uint8_t)((__ADDRESS__) & (uint8_t)(~I2C_OAR1_ADD0)))

/* 将 7 位地址转换为读地址（最低位为 1） */
#define I2C_7BIT_ADD_READ(__ADDRESS__)                     ((uint8_t)((__ADDRESS__) | I2C_OAR1_ADD0))

/* 获取 10 位地址的低位 */
#define I2C_10BIT_ADDRESS(__ADDRESS__)                     ((uint8_t)((uint16_t)((__ADDRESS__) & (uint16_t)0x00FF)))

/* 获取 10 位地址发送时的头字节（写方向） */
#define I2C_10BIT_HEADER_WRITE(__ADDRESS__)                ((uint8_t)((uint16_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0x0300)) >> 7) | (uint16_t)0x00F0)))

/* 获取 10 位地址发送时的头字节（读方向） */
#define I2C_10BIT_HEADER_READ(__ADDRESS__)                 ((uint8_t)((uint16_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0x0300)) >> 7) | (uint16_t)(0x00F1))))

/* 获取内存地址的高 8 位 */
#define I2C_MEM_ADD_MSB(__ADDRESS__)                       ((uint8_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0xFF00)) >> 8)))

/* 获取内存地址的低 8 位 */
#define I2C_MEM_ADD_LSB(__ADDRESS__)                       ((uint8_t)((uint16_t)((__ADDRESS__) & (uint16_t)0x00FF)))

/** @defgroup I2C_IS_RTC_Definitions I2C 私有宏用于检查输入参数
  * @{
  */
/* 检查占空比设置是否有效 */
#define IS_I2C_DUTY_CYCLE(CYCLE) (((CYCLE) == I2C_DUTYCYCLE_2) || \
                                  ((CYCLE) == I2C_DUTYCYCLE_16_9))

/* 检查寻址模式是否有效（7位或10位） */
#define IS_I2C_ADDRESSING_MODE(ADDRESS) (((ADDRESS) == I2C_ADDRESSINGMODE_7BIT) || \
                                         ((ADDRESS) == I2C_ADDRESSINGMODE_10BIT))

/* 检查双地址模式是否有效 */
#define IS_I2C_DUAL_ADDRESS(ADDRESS) (((ADDRESS) == I2C_DUALADDRESS_DISABLE) || \
                                      ((ADDRESS) == I2C_DUALADDRESS_ENABLE))

/* 检查广播呼叫是否有效 */
#define IS_I2C_GENERAL_CALL(CALL) (((CALL) == I2C_GENERALCALL_DISABLE) || \
                                   ((CALL) == I2C_GENERALCALL_ENABLE))

/* 检查时钟拉伸是否有效 */
#define IS_I2C_NO_STRETCH(STRETCH) (((STRETCH) == I2C_NOSTRETCH_DISABLE) || \
                                    ((STRETCH) == I2C_NOSTRETCH_ENABLE))

/* 检查内存地址大小是否有效（8位或16位） */
#define IS_I2C_MEMADD_SIZE(SIZE) (((SIZE) == I2C_MEMADD_SIZE_8BIT) || \
                                  ((SIZE) == I2C_MEMADD_SIZE_16BIT))

/* 检查时钟速度是否在有效范围内 (0, 400k] */
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) > 0U) && ((SPEED) <= 400000U))

/* 检查自身地址 1 是否有效 */
#define IS_I2C_OWN_ADDRESS1(ADDRESS1) (((ADDRESS1) & 0xFFFFFC00U) == 0U)

/* 检查自身地址 2 是否有效 */
#define IS_I2C_OWN_ADDRESS2(ADDRESS2) (((ADDRESS2) & 0xFFFFFF01U) == 0U)

/* 检查传输选项请求是否有效 */
#define IS_I2C_TRANSFER_OPTIONS_REQUEST(REQUEST)      (((REQUEST) == I2C_FIRST_FRAME)              || \
                                                       ((REQUEST) == I2C_FIRST_AND_NEXT_FRAME)     || \
                                                       ((REQUEST) == I2C_NEXT_FRAME)               || \
                                                       ((REQUEST) == I2C_FIRST_AND_LAST_FRAME)     || \
                                                       ((REQUEST) == I2C_LAST_FRAME)               || \
                                                       ((REQUEST) == I2C_LAST_FRAME_NO_STOP)       || \
                                                       IS_I2C_TRANSFER_OTHER_OPTIONS_REQUEST(REQUEST))

/* 检查其他传输选项请求是否有效 */
#define IS_I2C_TRANSFER_OTHER_OPTIONS_REQUEST(REQUEST) (((REQUEST) == I2C_OTHER_FRAME)     || \
                                                        ((REQUEST) == I2C_OTHER_AND_LAST_FRAME))

/* 检查标志位状态的内部宏 */
#define I2C_CHECK_FLAG(__ISR__, __FLAG__)         ((((__ISR__) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET)

/* 检查中断源是否使能的内部宏 */
#define I2C_CHECK_IT_SOURCE(__CR1__, __IT__)      ((((__CR1__) & (__IT__)) == (__IT__)) ? SET : RESET)
/**
  * @}
  */

/**
  * @}
  */

/* 私有函数 ---------------------------------------------------------*/
/** @defgroup I2C_Private_Functions I2C 私有函数
  * @{
  */

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


#endif /* __STM32F1xx_HAL_I2C_H */
