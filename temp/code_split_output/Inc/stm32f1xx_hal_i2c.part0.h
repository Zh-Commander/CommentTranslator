/**
  ******************************************************************************
  * @file    stm32f1xx_hal_i2c.h
  * @author  MCD Application Team
  * @brief   Header file of I2C HAL module.
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
// 防止递归包含
#ifndef __STM32F1xx_HAL_I2C_H
#define __STM32F1xx_HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含文件
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/** @defgroup I2C_Configuration_Structure_definition I2C Configuration Structure definition
  * @brief  I2C Configuration Structure definition
  * @{
  */
// I2C初始化结构体定义
typedef struct
{
  uint32_t ClockSpeed;       /*!< Specifies the clock frequency.
                                  This parameter must be set to a value lower than 400kHz */
  // 指定时钟频率，单位Hz。此参数必须设置为低于400kHz的值（标准模式100kHz，快速模式400kHz）

  uint32_t DutyCycle;        /*!< Specifies the I2C fast mode duty cycle.
                                  This parameter can be a value of @ref I2C_duty_cycle_in_fast_mode */
  // 指定I2C快速模式下的占空比。此参数可以是 @ref I2C_duty_cycle_in_fast_mode 中的一个值

  uint32_t OwnAddress1;      /*!< Specifies the first device own address.
                                  This parameter can be a 7-bit or 10-bit address. */
  // 指定第一个设备自身地址。此参数可以是7位或10位地址

  uint32_t AddressingMode;   /*!< Specifies if 7-bit or 10-bit addressing mode is selected.
                                  This parameter can be a value of @ref I2C_addressing_mode */
  // 指定是否选择7位或10位寻址模式。此参数可以是 @ref I2C_addressing_mode 中的一个值

  uint32_t DualAddressMode;  /*!< Specifies if dual addressing mode is selected.
                                  This parameter can be a value of @ref I2C_dual_addressing_mode */
  // 指定是否选择双地址模式。此参数可以是 @ref I2C_dual_addressing_mode 中的一个值

  uint32_t OwnAddress2;      /*!< Specifies the second device own address if dual addressing mode is selected
                                  This parameter can be a 7-bit address. */
  // 如果选择了双地址模式，则指定第二个设备自身地址。此参数可以是7位地址

  uint32_t GeneralCallMode;  /*!< Specifies if general call mode is selected.
                                  This parameter can be a value of @ref I2C_general_call_addressing_mode */
  // 指定是否选择广播呼叫模式。此参数可以是 @ref I2C_general_call_addressing_mode 中的一个值

  uint32_t NoStretchMode;    /*!< Specifies if nostretch mode is selected.
                                  This parameter can be a value of @ref I2C_nostretch_mode */
  // 指定是否选择禁止时钟延长模式。此参数可以是 @ref I2C_nostretch_mode 中的一个值

} I2C_InitTypeDef;

/**
  * @}
  */

/** @defgroup HAL_state_structure_definition HAL state structure definition
  * @brief  HAL State structure definition
  * @note  HAL I2C State value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : Abort (Abort user request on going)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral initialized and ready to use. HAL I2C Init function called)
  *          b4     (not used)
  *             x  : Should be set to 0
  *          b3
  *             0  : Ready or Busy (No Listen mode ongoing)
  *             1  : Listen (Peripheral in Address Listen Mode)
  *          b2     Intrinsic process state
  *             0  : Ready
  *             1  : Busy (Peripheral busy with some configuration or internal operations)
  *          b1     Rx state
  *             0  : Ready (no Rx operation ongoing)
  *             1  : Busy (Rx operation ongoing)
  *          b0     Tx state
  *             0  : Ready (no Tx operation ongoing)
  *             1  : Busy (Tx operation ongoing)
  * @{
  */
// HAL状态结构体定义
// 注：HAL I2C 状态值编码遵循下面描述的位图：
// b7-b6 错误信息 (00:无错误, 01:中止中, 10:超时, 11:错误)
// b5 外设初始化状态 (0:未初始化, 1:已初始化)
// b4 保留
// b3 监听模式 (0:非监听模式, 1:监听模式)
// b2 内部进程状态 (0:就绪, 1:忙)
// b1 接收状态 (0:就绪, 1:忙)
// b0 发送状态 (0:就绪, 1:忙)
typedef enum
{
  HAL_I2C_STATE_RESET             = 0x00U,   /*!< Peripheral is not yet Initialized         */
  // 外设尚未初始化
  HAL_I2C_STATE_READY             = 0x20U,   /*!< Peripheral Initialized and ready for use  */
  // 外设已初始化并准备就绪
  HAL_I2C_STATE_BUSY              = 0x24U,   /*!< An internal process is ongoing            */
  // 正在进行内部处理
  HAL_I2C_STATE_BUSY_TX           = 0x21U,   /*!< Data Transmission process is ongoing      */
  // 正在进行数据发送处理
  HAL_I2C_STATE_BUSY_RX           = 0x22U,   /*!< Data Reception process is ongoing         */
  // 正在进行数据接收处理
  HAL_I2C_STATE_LISTEN            = 0x28U,   /*!< Address Listen Mode is ongoing            */
  // 地址监听模式正在进行
  HAL_I2C_STATE_BUSY_TX_LISTEN    = 0x29U,   /*!< Address Listen Mode and Data Transmission
                                                 process is ongoing                         */
  // 地址监听模式和数据发送处理正在进行
  HAL_I2C_STATE_BUSY_RX_LISTEN    = 0x2AU,   /*!< Address Listen Mode and Data Reception
                                                 process is ongoing                         */
  // 地址监听模式和数据接收处理正在进行
  HAL_I2C_STATE_ABORT             = 0x60U,   /*!< Abort user request ongoing                */
  // 用户请求中止正在进行
  HAL_I2C_STATE_TIMEOUT           = 0xA0U,   /*!< Timeout state                             */
  // 超时状态
  HAL_I2C_STATE_ERROR             = 0xE0U    /*!< Error                                     */
  // 错误状态

} HAL_I2C_StateTypeDef;

/**
  * @}
  */

/** @defgroup HAL_mode_structure_definition HAL mode structure definition
  * @brief  HAL Mode structure definition
  * @note  HAL I2C Mode value coding follow below described bitmap :\n
  *          b7     (not used)\n
  *             x  : Should be set to 0\n
  *          b6\n
  *             0  : None\n
  *             1  : Memory (HAL I2C communication is in Memory Mode)\n
  *          b5\n
  *             0  : None\n
  *             1  : Slave (HAL I2C communication is in Slave Mode)\n
  *          b4\n
  *             0  : None\n
  *             1  : Master (HAL I2C communication is in Master Mode)\n
  *          b3-b2-b1-b0  (not used)\n
  *             xxxx : Should be set to 0000
  * @{
  */
// HAL模式结构体定义
// 注：HAL I2C 模式值编码遵循下面描述的位图：
// b6 内存模式
// b5 从机模式
// b4 主机模式
typedef enum
{
  HAL_I2C_MODE_NONE               = 0x00U,   /*!< No I2C communication on going             */
  // 无I2C通信正在进行
  HAL_I2C_MODE_MASTER             = 0x10U,   /*!< I2C communication is in Master Mode       */
  // I2C通信处于主机模式
  HAL_I2C_MODE_SLAVE              = 0x20U,   /*!< I2C communication is in Slave Mode        */
  // I2C通信处于从机模式
  HAL_I2C_MODE_MEM                = 0x40U    /*!< I2C communication is in Memory Mode       */
  // I2C通信处于内存模式

} HAL_I2C_ModeTypeDef;

/**
  * @}
  */

/** @defgroup I2C_Error_Code_definition I2C Error Code definition
  * @brief  I2C Error Code definition
  * @{
  */
// I2C错误代码定义
#define HAL_I2C_ERROR_NONE              0x00000000U    /*!< No error              */
// 无错误
#define HAL_I2C_ERROR_BERR              0x00000001U    /*!< BERR error            */
// 总线错误
#define HAL_I2C_ERROR_ARLO              0x00000002U    /*!< ARLO error            */
// 仲裁丢失错误
#define HAL_I2C_ERROR_AF                0x00000004U    /*!< AF error              */
// 应答失败错误
#define HAL_I2C_ERROR_OVR               0x00000008U    /*!< OVR error             */
// 过载/欠载错误
#define HAL_I2C_ERROR_DMA               0x00000010U    /*!< DMA transfer error    */
// DMA传输错误
#define HAL_I2C_ERROR_TIMEOUT           0x00000020U    /*!< Timeout Error         */
// 超时错误
#define HAL_I2C_ERROR_SIZE              0x00000040U    /*!< Size Management error */
// 大小管理错误
#define HAL_I2C_ERROR_DMA_PARAM         0x00000080U    /*!< DMA Parameter Error   */
// DMA参数错误
#define HAL_I2C_WRONG_START             0x00000200U    /*!< Wrong start Error     */
// 错误的起始条件错误
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define HAL_I2C_ERROR_INVALID_CALLBACK  0x00000100U    /*!< Invalid Callback error */
// 无效的回调函数错误
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup I2C_handle_Structure_definition I2C handle Structure definition
  * @brief  I2C handle Structure definition
  * @{
  */
// I2C句柄结构体定义
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
typedef struct __I2C_HandleTypeDef
#else
typedef struct
#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
{
  I2C_TypeDef                *Instance;      /*!< I2C registers base address               */
  // I2C寄存器基地址指针，指向特定的I2C外设（如I2C1, I2C2）

  I2C_InitTypeDef            Init;           /*!< I2C communication parameters             */
  // I2C通信参数结构体，包含时钟速度、地址模式等配置

  uint8_t                    *pBuffPtr;      /*!< Pointer to I2C transfer buffer           */
  // 指向I2C传输数据缓冲区的指针

  uint16_t                   XferSize;       /*!< I2C transfer size                        */
  // I2C传输数据的大小

  __IO uint16_t              XferCount;      /*!< I2C transfer counter                     */
  // I2C传输计数器，记录剩余待传输的数据量

  __IO uint32_t              XferOptions;    /*!< I2C transfer options                     */
  // I2C传输选项，用于控制传输的具体行为（如是否发送停止位等）

  __IO uint32_t              PreviousState;  /*!< I2C communication Previous state and mode
                                                  context for internal usage               */
  // I2C通信的前一个状态和模式，供内部使用

  DMA_HandleTypeDef          *hdmatx;        /*!< I2C Tx DMA handle parameters             */
  // I2C发送DMA句柄参数

  DMA_HandleTypeDef          *hdmarx;        /*!< I2C Rx DMA handle parameters             */
  // I2C接收DMA句柄参数

  HAL_LockTypeDef            Lock;           /*!< I2C locking object                       */
  // I2C锁定对象，用于资源管理，防止并发访问

  __IO HAL_I2C_StateTypeDef  State;          /*!< I2C communication state                  */
  // I2C通信状态

  __IO HAL_I2C_ModeTypeDef   Mode;           /*!< I2C communication mode                   */
  // I2C通信模式

  __IO uint32_t              ErrorCode;      /*!< I2C Error code                           */
  // I2C错误代码

  __IO uint32_t              Devaddress;     /*!< I2C Target device address                */
  // I2C目标设备地址

  __IO uint32_t              Memaddress;     /*!< I2C Target memory address                */
  // I2C目标内存地址（用于读写EEPROM等存储器时）

  __IO uint32_t              MemaddSize;     /*!< I2C Target memory address  size          */
  // I2C目标内存地址大小（8位或16位）

  __IO uint32_t              EventCount;     /*!< I2C Event counter                        */
  // I2C事件计数器


#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
  void (* MasterTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);           /*!< I2C Master Tx Transfer completed callback */
  // I2C主机发送完成回调函数指针
  void (* MasterRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);           /*!< I2C Master Rx Transfer completed callback */
  // I2C主机接收完成回调函数指针
  void (* SlaveTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);            /*!< I2C Slave Tx Transfer completed callback  */
  // I2C从机发送完成回调函数指针
  void (* SlaveRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);            /*!< I2C Slave Rx Transfer completed callback  */
  // I2C从机接收完成回调函数指针
  void (* ListenCpltCallback)(struct __I2C_HandleTypeDef *hi2c);             /*!< I2C Listen Complete callback              */
  // I2C监听完成回调函数指针
  void (* MemTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Memory Tx Transfer completed callback */
  // I2C内存写完成回调函数指针
  void (* MemRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Memory Rx Transfer completed callback */
  // I2C内存读完成回调函数指针
  void (* ErrorCallback)(struct __I2C_HandleTypeDef *hi2c);                  /*!< I2C Error callback                        */
  // I2C错误回调函数指针
  void (* AbortCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Abort callback                        */
  // I2C中止完成回调函数指针

  void (* AddrCallback)(struct __I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);  /*!< I2C Slave Address Match callback */
  // I2C从机地址匹配回调函数指针

  void (* MspInitCallback)(struct __I2C_HandleTypeDef *hi2c);                /*!< I2C Msp Init callback                     */
  // I2C MSP初始化回调函数指针（底层硬件初始化，如GPIO、时钟）
  void (* MspDeInitCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Msp DeInit callback                   */
  // I2C MSP反初始化回调函数指针（底层硬件反初始化）

#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
} I2C_HandleTypeDef;

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL I2C Callback ID enumeration definition
  */
// HAL I2C 回调函数ID枚举定义，用于注册或注销特定的回调函数
typedef enum
{
  HAL_I2C_MASTER_TX_COMPLETE_CB_ID      = 0x00U,    /*!< I2C Master Tx Transfer completed callback ID  */
  // 主机发送完成回调ID
  HAL_I2C_MASTER_RX_COMPLETE_CB_ID      = 0x01U,    /*!< I2C Master Rx Transfer completed callback ID  */
  // 主机接收完成回调ID
  HAL_I2C_SLAVE_TX_COMPLETE_CB_ID       = 0x02U,    /*!< I2C Slave Tx Transfer completed callback ID   */
  // 从机发送完成回调ID
  HAL_I2C_SLAVE_RX_COMPLETE_CB_ID       = 0x03U,    /*!< I2C Slave Rx Transfer completed callback ID   */
  // 从机接收完成回调ID
  HAL_I2C_LISTEN_COMPLETE_CB_ID         = 0x04U,    /*!< I2C Listen Complete callback ID               */
  // 监听完成回调ID
  HAL_I2C_MEM_TX_COMPLETE_CB_ID         = 0x05U,    /*!< I2C Memory Tx Transfer callback ID            */
  // 内存写完成回调ID
  HAL_I2C_MEM_RX_COMPLETE_CB_ID         = 0x06U,    /*!< I2C Memory Rx Transfer completed callback ID  */
  // 内存读完成回调ID
  HAL_I2C_ERROR_CB_ID                   = 0x07U,    /*!< I2C Error callback ID                         */
  // 错误回调ID
  HAL_I2C_ABORT_CB_ID                   = 0x08U,    /*!< I2C Abort callback ID                         */
  // 中止回调ID

  HAL_I2C_MSPINIT_CB_ID                 = 0x09U,    /*!< I2C Msp Init callback ID                      */
  // MSP初始化回调ID
  HAL_I2C_MSPDEINIT_CB_ID               = 0x0AU     /*!< I2C Msp DeInit callback ID                    */
  // MSP反初始化回调ID

} HAL_I2C_CallbackIDTypeDef;

/**
  * @brief  HAL I2C Callback pointer definition
  */
// HAL I2C 回调函数指针类型定义
typedef  void (*pI2C_CallbackTypeDef)(I2C_HandleTypeDef *hi2c); /*!< pointer to an I2C callback function */
// 指向I2C回调函数的指针
typedef  void (*pI2C_AddrCallbackTypeDef)(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode); /*!< pointer to an I2C Address Match callback function */
// 指向I2C地址匹配回调函数的指针

#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/
// 导出的常量定义

/** @defgroup I2C_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_duty_cycle_in_fast_mode I2C duty cycle in fast mode
  * @{
  */
// I2C快速模式下的占空比定义
// 占空比决定了SCL高低电平的时间比例，影响数据传输的稳定性
#define I2C_DUTYCYCLE_2                 0x00000000U
// Tlow/Thigh = 2，标准快速模式占空比
#define I2C_DUTYCYCLE_16_9              I2C_CCR_DUTY
// Tlow/Thigh = 16/9，用于更高速率的通信
/**
  * @}
  */

/** @defgroup I2C_addressing_mode I2C addressing mode
  * @{
  */
// I2C寻址模式定义
#define I2C_ADDRESSINGMODE_7BIT         0x00004000U
// 7位寻址模式（最常用）
#define I2C_ADDRESSINGMODE_10BIT        (I2C_OAR1_ADDMODE | 0x00004000U)
// 10位寻址模式（用于需要更多地址的场合）
/**
  * @}
  */

/** @defgroup I2C_dual_addressing_mode  I2C dual addressing mode
  * @{
  */
// I2C双地址模式定义
// 允许从机响应两个不同的地址
#define I2C_DUALADDRESS_DISABLE        0x00000000U
// 禁用双地址模式
#define I2C_DUALADDRESS_ENABLE         I2C_OAR2_ENDUAL
// 启用双地址模式
/**
  * @}
  */

/** @defgroup I2C_general_call_addressing_mode I2C general call addressing mode
  * @{
  */
// I2C广播呼叫寻址模式定义
// 允许从机响应通用广播地址（0x00）
#define I2C_GENERALCALL_DISABLE        0x00000000U
// 禁用广播呼叫模式
#define I2C_GENERALCALL_ENABLE         I2C_CR1_ENGC
// 启用广播呼叫模式
/**
  * @}
  */

/** @defgroup I2C_nostretch_mode I2C nostretch mode
  * @{
  */
// I2C禁止时钟延长模式定义
// 时钟延长允许从机拉低SCL以延迟主机的时钟，给自己更多处理时间
#define I2C_NOSTRETCH_DISABLE          0x00000000U
// 禁用“禁止时钟延长”，即允许时钟延长
#define I2C_NOSTRETCH_ENABLE           I2C_CR1_NOSTRETCH
// 启用“禁止时钟延长”，即不允许时钟延长
/**
  * @}
  */

/** @defgroup I2C_Memory_Address_Size I2C Memory Address Size
  * @{
  */
// I2C内存地址大小定义
// 用于操作EEPROM等外部存储器时指定内部地址长度
#define I2C_MEMADD_SIZE_8BIT            0x00000001U
// 8位内存地址
#define I2C_MEMADD_SIZE_16BIT           0x00000010U
// 16位内存地址
/**
  * @}
  */

/** @defgroup I2C_XferDirection_definition I2C XferDirection definition
  * @{
  */
// I2C传输方向定义
#define I2C_DIRECTION_RECEIVE           0x00000000U
// 接收方向
#define I2C_DIRECTION_TRANSMIT          0x00000001U
// 发送方向
/**
  * @}
  */

/** @defgroup I2C_XferOptions_definition I2C XferOptions definition
  * @{
  */
// I2C传输选项定义
// 这些宏定义用于控制连续传输时的起始和停止条件
#define  I2C_FIRST_FRAME                0x00000001U
// 第一帧
#define  I2C_FIRST_AND_NEXT_FRAME       0x00000002U
// 第一帧和下一帧
#define  I2C_NEXT_FRAME                 0x00000004U
// 下一帧
#define  I2C_FIRST_AND_LAST_FRAME       0x00000008U
// 第一帧和最后一帧
#define  I2C_LAST_FRAME_NO_STOP         0x00000010U
// 最后一帧但不发送停止条件
#define  I2C_LAST_FRAME                 0x00000020U
// 最后一帧

/* List of XferOptions in usage of :
 * 1- Restart condition in all use cases (direction change or not)
 */
// 其他帧选项，用于特殊情况下的重启条件
#define  I2C_OTHER_FRAME                (0x00AA0000U)
#define  I2C_OTHER_AND_LAST_FRAME       (0xAA000000U)
/**
  * @}
  */

/** @defgroup I2C_Interrupt_configuration_definition I2C Interrupt configuration definition
  * @brief I2C Interrupt definition
  *        Elements values convention: 0xXXXXXXXX
  *           - XXXXXXXX  : Interrupt control mask
  * @{
  */
// I2C中断配置定义
#define I2C_IT_BUF                      I2C_CR2_ITBUFEN
// 缓冲中断使能（用于TXE/RXNE标志）
#define I2C_IT_EVT                      I2C_CR2_ITEVTEN
// 事件中断使能（用于SB/ADDR/STOPF等标志）
#define I2C_IT_ERR                      I2C_CR2_ITERREN
// 错误中断使能（用于BERR/ARLO/AF等标志）
/**
  * @}
  */

/** @defgroup I2C_Flag_definition I2C Flag definition
  * @{
  */
// I2C标志位定义
// 用于检查I2C外设的当前状态
#define I2C_FLAG_OVR                    0x00010800U
// 过载/欠载标志
#define I2C_FLAG_AF                     0x00010400U
// 应答失败标志
#define I2C_FLAG_ARLO                   0x00010200U
// 仲裁丢失标志
#define I2C_FLAG_BERR                   0x00010100U
// 总线错误标志
#define I2C_FLAG_TXE                    0x00010080U
// 数据寄存器为空标志（发送）
#define I2C_FLAG_RXNE                   0x00010040U
// 数据寄存器非空标志（接收）
#define I2C_FLAG_STOPF                  0x00010010U
// 停止条件检测标志
#define I2C_FLAG_ADD10                  0x00010008U
// 10位地址头标志
#define I2C_FLAG_BTF                    0x00010004U
// 字节传输结束标志
#define I2C_FLAG_ADDR                   0x00010002U
// 地址发送标志
#define I2C_FLAG_SB                     0x00010001U
// 起始条件标志
#define I2C_FLAG_DUALF                  0x00100080U
// 双地址标志
#define I2C_FLAG_GENCALL                0x00100010U
// 广播呼叫标志
#define I2C_FLAG_TRA                    0x00100004U
// 发送/接收标志
#define I2C_FLAG_BUSY                   0x00100002U
// 总线忙标志
#define I2C_FLAG_MSL                    0x00100001U
// 主机/从机标志
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/
// 导出的宏定义

/** @defgroup I2C_Exported_Macros I2C Exported Macros
  * @{
  */

/** @brief Reset I2C handle state.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
// 复位I2C句柄状态
// 参数: __HANDLE__ 指定I2C句柄
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                do{                                                   \
                                                                    (__HANDLE__)->State = HAL_I2C_STATE_RESET;       \
                                                                    (__HANDLE__)->MspInitCallback = NULL;            \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                                  } while(0)
// 如果启用了回调注册功能，复位状态的同时清空Msp回调指针
#else
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_I2C_STATE_RESET)
// 仅复位状态为 RESET
#endif

/** @brief  Enable or disable the specified I2C interrupts.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the interrupt source to enable or disable.
  *         This parameter can be one of the following values:
  *            @arg I2C_IT_BUF: Buffer interrupt enable
  *            @arg I2C_IT_EVT: Event interrupt enable
  *            @arg I2C_IT_ERR: Error interrupt enable
  * @retval None
  */
// 使能或失能指定的I2C中断
// 参数: __HANDLE__ 指定I2C句柄
// 参数: __INTERRUPT__ 指定中断源 (I2C_IT_BUF, I2C_IT_EVT, I2C_IT_ERR)
#define __HAL_I2C_ENABLE_IT(__HANDLE__, __INTERRUPT__)   SET_BIT((__HANDLE__)->Instance->CR2,(__INTERRUPT__))
// 使能中断：设置CR2寄存器中的对应位
#define __HAL_I2C_DISABLE_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT((__HANDLE__)->Instance->CR2, (__INTERRUPT__))
// 失能中断：清除CR2寄存器中的对应位

/** @brief  Checks if the specified I2C interrupt source is enabled or disabled.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the I2C interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg I2C_IT_BUF: Buffer interrupt enable
  *            @arg I2C_IT_EVT: Event interrupt enable
  *            @arg I2C_IT_ERR: Error interrupt enable
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
// 检查指定的I2C中断源是否使能
// 参数: __HANDLE__ 指定I2C句柄
// 参数: __INTERRUPT__ 指定中断源
// 返回值: 中断状态 (SET 或 RESET)
#define __HAL_I2C_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->CR2 & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)
