/**
  ******************************************************************************
  * @file    stm32f1xx_hal_tim.h
  * @author  MCD Application Team
  * @brief   TIM HAL模块头文件。
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
#ifndef STM32F1xx_HAL_TIM_H
#define STM32F1xx_HAL_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup TIM
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/
/** @defgroup TIM_Exported_Types TIM 导出类型
  * @{
  */

/**
  * @brief  TIM 时基配置结构体定义
  *         用于配置定时器的基本工作参数，如预分频、计数模式等
  */
typedef struct
{
  uint32_t Prescaler;         /*!< 指定用于对TIM时钟进行分频的预分频值。
                                   此参数可以是 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数值 */

  uint32_t CounterMode;       /*!< 指定计数器模式。
                                   此参数可以是 @ref TIM_Counter_Mode 的值 */

  uint32_t Period;            /*!< 指定在下一个更新事件时加载到活动自动重载寄存器(ARR)中的周期值。
                                   此参数可以是 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数值。  */

  uint32_t ClockDivision;     /*!< 指定时钟分频。
                                   此参数可以是 @ref TIM_ClockDivision 的值 */

  uint32_t RepetitionCounter;  /*!< 指定重复计数器值。每次RCR递减计数器
                                    达到零时，都会生成更新事件，并从RCR值(N)重新开始计数。
                                    这意味着在PWM模式下，(N+1)对应于：
                                        - 边沿对齐模式下的PWM周期数
                                        - 中心对齐模式下的半PWM周期数
                                     通用定时器: 此参数必须是 Min_Data = 0x00 和
                                     Max_Data = 0xFF 之间的数值。
                                     高级定时器: 此参数必须是 Min_Data = 0x0000 和
                                     Max_Data = 0xFFFF 之间的数值。 */

  uint32_t AutoReloadPreload;  /*!< 指定自动重载预装载。
                                   此参数可以是 @ref TIM_AutoReloadPreload 的值 */
} TIM_Base_InitTypeDef;

/**
  * @brief  TIM 输出比较配置结构体定义
  *         用于配置定时器的输出比较模式，常用于PWM输出、电平翻转等
  */
typedef struct
{
  uint32_t OCMode;        /*!< 指定TIM模式。
                               此参数可以是 @ref TIM_Output_Compare_and_PWM_modes 的值 */

  uint32_t Pulse;         /*!< 指定要加载到捕获比较寄存器(CCR)中的脉冲值。
                               此参数可以是 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数值 */

  uint32_t OCPolarity;    /*!< 指定输出极性。
                               此参数可以是 @ref TIM_Output_Compare_Polarity 的值 */

  uint32_t OCNPolarity;   /*!< 指定互补输出极性。
                               此参数可以是 @ref TIM_Output_Compare_N_Polarity 的值
                               @note 此参数仅对支持断路功能的定时器实例有效。 */

  uint32_t OCFastMode;    /*!< 指定快速模式状态。
                               此参数可以是 @ref TIM_Output_Fast_State 的值
                               @note 此参数仅在PWM1和PWM2模式下有效。 */


  uint32_t OCIdleState;   /*!< 指定空闲状态期间的TIM输出比较引脚状态。
                               此参数可以是 @ref TIM_Output_Compare_Idle_State 的值
                               @note 此参数仅对支持断路功能的定时器实例有效。 */

  uint32_t OCNIdleState;  /*!< 指定空闲状态期间的TIM互补输出比较引脚状态。
                               此参数可以是 @ref TIM_Output_Compare_N_Idle_State 的值
                               @note 此参数仅对支持断路功能的定时器实例有效。 */
} TIM_OC_InitTypeDef;

/**
  * @brief  TIM 单脉冲模式配置结构体定义
  *         用于配置定时器的单脉冲模式，常用于产生精确的单个脉冲
  */
typedef struct
{
  uint32_t OCMode;        /*!< 指定TIM模式。
                               此参数可以是 @ref TIM_Output_Compare_and_PWM_modes 的值 */

  uint32_t Pulse;         /*!< 指定要加载到捕获比较寄存器(CCR)中的脉冲值。
                               此参数可以是 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数值 */

  uint32_t OCPolarity;    /*!< 指定输出极性。
                               此参数可以是 @ref TIM_Output_Compare_Polarity 的值 */

  uint32_t OCNPolarity;   /*!< 指定互补输出极性。
                               此参数可以是 @ref TIM_Output_Compare_N_Polarity 的值
                               @note 此参数仅对支持断路功能的定时器实例有效。 */

  uint32_t OCIdleState;   /*!< 指定空闲状态期间的TIM输出比较引脚状态。
                               此参数可以是 @ref TIM_Output_Compare_Idle_State 的值
                               @note 此参数仅对支持断路功能的定时器实例有效。 */

  uint32_t OCNIdleState;  /*!< 指定空闲状态期间的TIM互补输出比较引脚状态。
                               此参数可以是 @ref TIM_Output_Compare_N_Idle_State 的值
                               @note 此参数仅对支持断路功能的定时器实例有效。 */

  uint32_t ICPolarity;    /*!< 指定输入信号的有效边沿。
                               此参数可以是 @ref TIM_Input_Capture_Polarity 的值 */

  uint32_t ICSelection;   /*!< 指定输入映射。
                              此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t ICFilter;      /*!< 指定输入捕获滤波器。
                              此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_OnePulse_InitTypeDef;

/**
  * @brief  TIM 输入捕获配置结构体定义
  *         用于配置定时器的输入捕获模式，常用于测量信号脉宽或频率
  */
typedef struct
{
  uint32_t  ICPolarity;  /*!< 指定输入信号的有效边沿。
                              此参数可以是 @ref TIM_Input_Capture_Polarity 的值 */

  uint32_t ICSelection;  /*!< 指定输入映射。
                              此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t ICPrescaler;  /*!< 指定输入捕获预分频器。
                              此参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t ICFilter;     /*!< 指定输入捕获滤波器。
                              此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_IC_InitTypeDef;

/**
  * @brief  TIM 编码器配置结构体定义
  *         用于配置定时器的编码器接口模式，常用于电机测速或测位
  */
typedef struct
{
  uint32_t EncoderMode;   /*!< 指定编码器模式。
                               此参数可以是 @ref TIM_Encoder_Mode 的值 */

  uint32_t IC1Polarity;   /*!< 指定TI1输入信号的有效边沿。
                               此参数可以是 @ref TIM_Encoder_Input_Polarity 的值 */

  uint32_t IC1Selection;  /*!< 指定TI1输入映射。
                               此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t IC1Prescaler;  /*!< 指定TI1输入捕获预分频器。
                               此参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t IC1Filter;     /*!< 指定TI1输入捕获滤波器。
                               此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */

  uint32_t IC2Polarity;   /*!< 指定TI2输入信号的有效边沿。
                               此参数可以是 @ref TIM_Encoder_Input_Polarity 的值 */

  uint32_t IC2Selection;  /*!< 指定TI2输入映射。
                              此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t IC2Prescaler;  /*!< 指定TI2输入捕获预分频器。
                               此参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t IC2Filter;     /*!< 指定TI2输入捕获滤波器。
                               此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_Encoder_InitTypeDef;

/**
  * @brief  时钟配置句柄结构体定义
  *         用于配置定时器的外部时钟源模式
  */
typedef struct
{
  uint32_t ClockSource;     /*!< TIM时钟源
                                 此参数可以是 @ref TIM_Clock_Source 的值 */
  uint32_t ClockPolarity;   /*!< TIM时钟极性
                                 此参数可以是 @ref TIM_Clock_Polarity 的值 */
  uint32_t ClockPrescaler;  /*!< TIM时钟预分频器
                                 此参数可以是 @ref TIM_Clock_Prescaler 的值 */
  uint32_t ClockFilter;     /*!< TIM时钟滤波器
                                 此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_ClockConfigTypeDef;

/**
  * @brief  TIM 清除输入配置句柄结构体定义
  *         用于配置清除输入功能，常用于清除OCxREF信号
  */
typedef struct
{
  uint32_t ClearInputState;      /*!< TIM清除输入状态
                                      此参数可以是 ENABLE 或 DISABLE */
  uint32_t ClearInputSource;     /*!< TIM清除输入源
                                      此参数可以是 @ref TIM_ClearInput_Source 的值 */
  uint32_t ClearInputPolarity;   /*!< TIM清除输入极性
                                      此参数可以是 @ref TIM_ClearInput_Polarity 的值 */
  uint32_t ClearInputPrescaler;  /*!< TIM清除输入预分频器
                                      此参数必须为0：当OCRef清除功能与ETR源一起使用时，
                                      ETR预分频器必须关闭 */
  uint32_t ClearInputFilter;     /*!< TIM清除输入滤波器
                                      此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_ClearInputConfigTypeDef;

/**
  * @brief  TIM 主模式配置结构体定义
  *         用于配置主/从模式下的主定时器行为
  */
typedef struct
{
  uint32_t  MasterOutputTrigger;   /*!< 触发输出(TRGO)选择
                                        此参数可以是 @ref TIM_Master_Mode_Selection 的值 */
  uint32_t  MasterSlaveMode;       /*!< 主/从模式选择
                                        此参数可以是 @ref TIM_Master_Slave_Mode 的值
                                        @note 当主/从模式使能时，触发输入(TRGI)上的事件
                                        效果会被延迟，以允许当前定时器与其从定时器
                                        (通过TRGO)之间的完美同步。在定时器同步模式下
                                        这不是强制性的。 */
} TIM_MasterConfigTypeDef;

/**
  * @brief  TIM 从模式配置结构体定义
  *         用于配置主/从模式下的从定时器行为
  */
typedef struct
{
  uint32_t  SlaveMode;         /*!< 从模式选择
                                    此参数可以是 @ref TIM_Slave_Mode 的值 */
  uint32_t  InputTrigger;      /*!< 输入触发源
                                    此参数可以是 @ref TIM_Trigger_Selection 的值 */
  uint32_t  TriggerPolarity;   /*!< 输入触发极性
                                    此参数可以是 @ref TIM_Trigger_Polarity 的值 */
  uint32_t  TriggerPrescaler;  /*!< 输入触发预分频器
                                    此参数可以是 @ref TIM_Trigger_Prescaler 的值 */
  uint32_t  TriggerFilter;     /*!< 输入触发滤波器
                                    此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值  */

} TIM_SlaveConfigTypeDef;

/**
  * @brief  TIM 断路输入和死区配置结构体定义
  * @note   可以配置2个断路输入(BKIN和BKI2)，具有可配置的滤波器和极性。
  *         主要用于高级定时器，保护电机驱动电路
  */
typedef struct
{
  uint32_t OffStateRunMode;      /*!< 运行模式下的关闭状态选择，此参数可以是 @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state 的值 */

  uint32_t OffStateIDLEMode;     /*!< 空闲模式下的关闭状态选择，此参数可以是 @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state 的值 */

  uint32_t LockLevel;            /*!< TIM锁定级别，此参数可以是 @ref TIM_Lock_level 的值 */

  uint32_t DeadTime;             /*!< TIM死区时间，此参数可以是 Min_Data = 0x00 和 Max_Data = 0xFF 之间的数值 */

  uint32_t BreakState;           /*!< TIM断路状态，此参数可以是 @ref TIM_Break_Input_enable_disable 的值 */

  uint32_t BreakPolarity;        /*!< TIM断路输入极性，此参数可以是 @ref TIM_Break_Polarity 的值 */

  uint32_t BreakFilter;          /*!< 指定断路输入滤波器。此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */

  uint32_t AutomaticOutput;      /*!< TIM自动输出使能状态，此参数可以是 @ref TIM_AOE_Bit_Set_Reset 的值 */

} TIM_BreakDeadTimeConfigTypeDef;

/**
  * @brief  HAL 状态结构体定义
  *         用于表示定时器外设的当前工作状态
  */
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /*!< 外设尚未初始化或已禁用  */
  HAL_TIM_STATE_READY             = 0x01U,    /*!< 外设已初始化并准备使用    */
  HAL_TIM_STATE_BUSY              = 0x02U,    /*!< 正在进行内部处理              */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /*!< 超时状态                               */
  HAL_TIM_STATE_ERROR             = 0x04U     /*!< 错误状态                */
} HAL_TIM_StateTypeDef;

/**
  * @brief  TIM 通道状态定义
  *         用于表示定时器特定通道的状态
  */
typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM通道初始状态                         */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM通道准备使用                         */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< TIM通道正在进行内部处理 */
} HAL_TIM_ChannelStateTypeDef;

/**
  * @brief  DMA 突发状态定义
  *         用于表示DMA突发传输的状态
  */
typedef enum
{
  HAL_DMA_BURST_STATE_RESET             = 0x00U,    /*!< DMA突发初始状态 */
  HAL_DMA_BURST_STATE_READY             = 0x01U,    /*!< DMA突发准备使用 */
  HAL_DMA_BURST_STATE_BUSY              = 0x02U,    /*!< 正在进行DMA突发       */
} HAL_TIM_DMABurstStateTypeDef;

/**
  * @brief  HAL 活动通道结构体定义
  *         用于标识当前正在操作的定时器通道
  */
typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< 活动通道是1     */
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< 活动通道是2     */
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< 活动通道是3     */
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< 活动通道是4     */
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< 所有活动通道已清除 */
} HAL_TIM_ActiveChannel;

/**
  * @brief  TIM 时基句柄结构体定义
  *         这是TIM外设的主要控制结构体，包含了所有必要的配置信息和状态变量
  */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
typedef struct __TIM_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
{
  TIM_TypeDef                        *Instance;         /*!< 寄存器基地址                             */
  TIM_Base_InitTypeDef               Init;              /*!< TIM时基所需参数                 */
  HAL_TIM_ActiveChannel              Channel;           /*!< 活动通道                                    */
  DMA_HandleTypeDef                  *hdma[7];          /*!< DMA句柄数组
                                                             此数组通过 @ref DMA_Handle_index 访问 */
  HAL_LockTypeDef                    Lock;              /*!< 锁定对象                                    */
  __IO HAL_TIM_StateTypeDef          State;             /*!< TIM操作状态                               */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelState[4];   /*!< TIM通道操作状态                       */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /*!< TIM互补通道操作状态         */
  __IO HAL_TIM_DMABurstStateTypeDef  DMABurstState;     /*!< DMA突发操作状态                         */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  /* TIM 基础模式 MSP 初始化回调函数指针 */
  void (* Base_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 基础模式 MSP 反初始化回调函数指针 */
  void (* Base_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输入捕获模式 MSP 初始化回调函数指针 */
  void (* IC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输入捕获模式 MSP 反初始化回调函数指针 */
  void (* IC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输出比较模式 MSP 初始化回调函数指针 */
  void (* OC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输出比较模式 MSP 反初始化回调函数指针 */
  void (* OC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM PWM 模式 MSP 初始化回调函数指针 */
  void (* PWM_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM PWM 模式 MSP 反初始化回调函数指针 */
  void (* PWM_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 单脉冲模式 MSP 初始化回调函数指针 */
  void (* OnePulse_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 单脉冲模式 MSP 反初始化回调函数指针 */
  void (* OnePulse_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 编码器模式 MSP 初始化回调函数指针 */
  void (* Encoder_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 编码器模式 MSP 反初始化回调函数指针 */
  void (* Encoder_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 霍尔传感器模式 MSP 初始化回调函数指针 */
  void (* HallSensor_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 霍尔传感器模式 MSP 反初始化回调函数指针 */
  void (* HallSensor_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 计数周期结束回调函数指针 */
  void (* PeriodElapsedCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 计数周期半完成回调函数指针(用于DMA双缓冲) */
  void (* PeriodElapsedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 触发回调函数指针 */
  void (* TriggerCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 触发半完成回调函数指针(用于DMA双缓冲) */
  void (* TriggerHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输入捕获回调函数指针 */
  void (* IC_CaptureCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输入捕获半完成回调函数指针(用于DMA双缓冲) */
  void (* IC_CaptureHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 输出比较延迟结束回调函数指针 */
  void (* OC_DelayElapsedCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM PWM 脉冲结束回调函数指针 */
  void (* PWM_PulseFinishedCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM PWM 脉冲半完成回调函数指针(用于DMA双缓冲) */
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 错误回调函数指针 */
  void (* ErrorCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 换相回调函数指针 */
  void (* CommutationCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 换相半完成回调函数指针(用于DMA双缓冲) */
  void (* CommutationHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* TIM 刹车信号回调函数指针 */
  void (* BreakCallback)(struct __TIM_HandleTypeDef *htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
} TIM_HandleTypeDef;

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TIM 回调ID枚举定义，用于标识不同的回调函数
  */
typedef enum
{
  HAL_TIM_BASE_MSPINIT_CB_ID              = 0x00U   /* TIM 基础模式 MSP初始化 回调ID */
  , HAL_TIM_BASE_MSPDEINIT_CB_ID          = 0x01U   /* TIM 基础模式 MSP反初始化 回调ID */
  , HAL_TIM_IC_MSPINIT_CB_ID              = 0x02U   /* TIM 输入捕获 MSP初始化 回调ID */
  , HAL_TIM_IC_MSPDEINIT_CB_ID            = 0x03U   /* TIM 输入捕获 MSP反初始化 回调ID */
  , HAL_TIM_OC_MSPINIT_CB_ID              = 0x04U   /* TIM 输出比较 MSP初始化 回调ID */
  , HAL_TIM_OC_MSPDEINIT_CB_ID            = 0x05U   /* TIM 输出比较 MSP反初始化 回调ID */
  , HAL_TIM_PWM_MSPINIT_CB_ID             = 0x06U   /* TIM PWM MSP初始化 回调ID */
  , HAL_TIM_PWM_MSPDEINIT_CB_ID           = 0x07U   /* TIM PWM MSP反初始化 回调ID */
  , HAL_TIM_ONE_PULSE_MSPINIT_CB_ID       = 0x08U   /* TIM 单脉冲 MSP初始化 回调ID */
  , HAL_TIM_ONE_PULSE_MSPDEINIT_CB_ID     = 0x09U   /* TIM 单脉冲 MSP反初始化 回调ID */
  , HAL_TIM_ENCODER_MSPINIT_CB_ID         = 0x0AU   /* TIM 编码器 MSP初始化 回调ID */
  , HAL_TIM_ENCODER_MSPDEINIT_CB_ID       = 0x0BU   /* TIM 编码器 MSP反初始化 回调ID */
  , HAL_TIM_HALL_SENSOR_MSPINIT_CB_ID     = 0x0CU   /* TIM 霍尔传感器 MSP初始化 回调ID */
  , HAL_TIM_HALL_SENSOR_MSPDEINIT_CB_ID   = 0x0DU   /* TIM 霍尔传感器 MSP反初始化 回调ID */
  , HAL_TIM_PERIOD_ELAPSED_CB_ID          = 0x0EU   /* TIM 计数周期结束 回调ID */
  , HAL_TIM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU   /* TIM 计数周期半完成 回调ID */
  , HAL_TIM_TRIGGER_CB_ID                 = 0x10U   /* TIM 触发 回调ID */
  , HAL_TIM_TRIGGER_HALF_CB_ID            = 0x11U   /* TIM 触发半完成 回调ID */
  , HAL_TIM_IC_CAPTURE_CB_ID              = 0x12U   /* TIM 输入捕获 回调ID */
  , HAL_TIM_IC_CAPTURE_HALF_CB_ID         = 0x13U   /* TIM 输入捕获半完成 回调ID */
  , HAL_TIM_OC_DELAY_ELAPSED_CB_ID        = 0x14U   /* TIM 输出比较延迟结束 回调ID */
  , HAL_TIM_PWM_PULSE_FINISHED_CB_ID      = 0x15U   /* TIM PWM脉冲结束 回调ID */
  , HAL_TIM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U   /* TIM PWM脉冲半完成 回调ID */
  , HAL_TIM_ERROR_CB_ID                   = 0x17U   /* TIM 错误 回调ID */
  , HAL_TIM_COMMUTATION_CB_ID             = 0x18U   /* TIM 换相 回调ID */
  , HAL_TIM_COMMUTATION_HALF_CB_ID        = 0x19U   /* TIM 换相半完成 回调ID */
  , HAL_TIM_BREAK_CB_ID                   = 0x1AU   /* TIM 刹车 回调ID */
} HAL_TIM_CallbackIDTypeDef;

/**
  * @brief  HAL TIM 回调函数指针类型定义
  */
typedef  void (*pTIM_CallbackTypeDef)(TIM_HandleTypeDef *htim);  /* 指向TIM回调函数的指针 */

#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* 导出类型定义结束 -----------------------------------------------------*/

/* 导出常量定义 --------------------------------------------------------*/
/** @defgroup TIM_Exported_Constants TIM 导出常量
  * @{
  */

/** @defgroup TIM_ClearInput_Source TIM 清除输入源
  * @{
  */
/* 禁用OCREF_CLR(清除输入功能关闭) */
#define TIM_CLEARINPUTSOURCE_NONE           0x00000000U
/* OCREF_CLR 连接到 ETRF 输入引脚 */
#define TIM_CLEARINPUTSOURCE_ETR            0x00000001U
/**
  * @}
  */

/** @defgroup TIM_DMA_Base_address TIM DMA 基地址
  * @{
  */
/* DMA访问基地址：控制寄存器1 (CR1) */
#define TIM_DMABASE_CR1                    0x00000000U
/* DMA访问基地址：控制寄存器2 (CR2) */
#define TIM_DMABASE_CR2                    0x00000001U
/* DMA访问基地址：从模式控制寄存器 (SMCR) */
#define TIM_DMABASE_SMCR                   0x00000002U
/* DMA访问基地址：DMA/中断使能寄存器 (DIER) */
#define TIM_DMABASE_DIER                   0x00000003U
/* DMA访问基地址：状态寄存器 (SR) */
#define TIM_DMABASE_SR                     0x00000004U
/* DMA访问基地址：事件产生寄存器 (EGR) */
#define TIM_DMABASE_EGR                    0x00000005U
/* DMA访问基地址：捕获/比较模式寄存器1 (CCMR1) */
#define TIM_DMABASE_CCMR1                  0x00000006U
/* DMA访问基地址：捕获/比较模式寄存器2 (CCMR2) */
#define TIM_DMABASE_CCMR2                  0x00000007U
/* DMA访问基地址：捕获/比较使能寄存器 (CCER) */
#define TIM_DMABASE_CCER                   0x00000008U
/* DMA访问基地址：计数器寄存器 (CNT) */
#define TIM_DMABASE_CNT                    0x00000009U
/* DMA访问基地址：预分频器寄存器 (PSC) */
#define TIM_DMABASE_PSC                    0x0000000AU
/* DMA访问基地址：自动重装载寄存器 (ARR) */
#define TIM_DMABASE_ARR                    0x0000000BU
/* DMA访问基地址：重复计数器寄存器 (RCR) */
#define TIM_DMABASE_RCR                    0x0000000CU
/* DMA访问基地址：捕获/比较寄存器1 (CCR1) */
#define TIM_DMABASE_CCR1                   0x0000000DU
/* DMA访问基地址：捕获/比较寄存器2 (CCR2) */
#define TIM_DMABASE_CCR2                   0x0000000EU
/* DMA访问基地址：捕获/比较寄存器3 (CCR3) */
#define TIM_DMABASE_CCR3                   0x0000000FU
/* DMA访问基地址：捕获/比较寄存器4 (CCR4) */
#define TIM_DMABASE_CCR4                   0x00000010U
/* DMA访问基地址：刹车和死区寄存器 (BDTR) */
#define TIM_DMABASE_BDTR                   0x00000011U
/* DMA访问基地址：DMA控制寄存器 (DCR) */
#define TIM_DMABASE_DCR                    0x00000012U
/* DMA访问基地址：DMA地址传输寄存器 (DMAR) */
#define TIM_DMABASE_DMAR                   0x00000013U
/**
  * @}
  */

/** @defgroup TIM_Event_Source TIM 事件源
  * @{
  */
/* 产生更新事件：重新初始化计数器并更新寄存器 */
#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG
/* 产生通道1捕获/比较事件 */
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G
/* 产生通道2捕获/比较事件 */
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G
/* 产生通道3捕获/比较事件 */
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G
/* 产生通道4捕获/比较事件 */
#define TIM_EVENTSOURCE_CC4                 TIM_EGR_CC4G
/* 产生换相事件 */
#define TIM_EVENTSOURCE_COM                 TIM_EGR_COMG
/* 产生触发事件 */
#define TIM_EVENTSOURCE_TRIGGER             TIM_EGR_TG
/* 产生刹车事件 */
#define TIM_EVENTSOURCE_BREAK               TIM_EGR_BG
/**
  * @}
  */

/** @defgroup TIM_Input_Channel_Polarity TIM 输入通道极性
  * @{
  */
/* 输入捕获上升沿触发 */
#define  TIM_INPUTCHANNELPOLARITY_RISING      0x00000000U
/* 输入捕获下降沿触发 */
#define  TIM_INPUTCHANNELPOLARITY_FALLING     TIM_CCER_CC1P
/* 输入捕获双边沿触发(上升沿和下降沿均触发) */
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)
/**
  * @}
  */

/** @defgroup TIM_ETR_Polarity TIM 外部触发极性
  * @{
  */
/* ETR外部触发信号反相(低电平或下降沿有效) */
#define TIM_ETRPOLARITY_INVERTED              TIM_SMCR_ETP
/* ETR外部触发信号不反相(高电平或上升沿有效) */
#define TIM_ETRPOLARITY_NONINVERTED           0x00000000U
/**
  * @}
  */

/** @defgroup TIM_ETR_Prescaler TIM 外部触发预分频
  * @{
  */
/* ETR外部触发信号不分频 */
#define TIM_ETRPRESCALER_DIV1                 0x00000000U
/* ETR外部触发信号 2分频 */
#define TIM_ETRPRESCALER_DIV2                 TIM_SMCR_ETPS_0
/* ETR外部触发信号 4分频 */
#define TIM_ETRPRESCALER_DIV4                 TIM_SMCR_ETPS_1
/* ETR外部触发信号 8分频 */
#define TIM_ETRPRESCALER_DIV8                 TIM_SMCR_ETPS
/**
  * @}
  */

/** @defgroup TIM_Counter_Mode TIM 计数模式
  * @{
  */
/* 向上计数模式：计数器从0计数到自动重装载值 */
#define TIM_COUNTERMODE_UP                 0x00000000U
/* 向下计数模式：计数器从自动重装载值计数到0 */
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR
/* 中心对齐模式1：仅在计数器向下计数时产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0
/* 中心对齐模式2：仅在计数器向上计数时产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1
/* 中心对齐模式3：在计数器向上和向下计数时均产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS
/**
  * @}
  */

/** @defgroup TIM_ClockDivision TIM 时钟分频
  * @{
  */
/* 时钟分频因子为1，死区时间和数字滤波器采样时间基准 tDTS=tCK_INT */
#define TIM_CLOCKDIVISION_DIV1             0x00000000U
/* 时钟分频因子为2，tDTS=2*tCK_INT */
#define TIM_CLOCKDIVISION_DIV2             TIM_CR1_CKD_0
/* 时钟分频因子为4，tDTS=4*tCK_INT */
#define TIM_CLOCKDIVISION_DIV4             TIM_CR1_CKD_1
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_State TIM 输出比较状态
  * @{
  */
/* 禁止输出比较(OCx信号未输出到引脚) */
#define TIM_OUTPUTSTATE_DISABLE            0x00000000U
/* 使能输出比较(OCx信号输出到引脚) */
#define TIM_OUTPUTSTATE_ENABLE             TIM_CCER_CC1E
/**
  * @}
  */

/** @defgroup TIM_AutoReloadPreload TIM 自动重装载预装载
  * @{
  */
/* 禁止自动重装载预装载：TIMx_ARR寄存器未缓冲，写入后立即生效 */
#define TIM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U
/* 使能自动重装载预装载：TIMx_ARR寄存器被缓冲，写入后在下一个更新事件生效 */
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 TIM_CR1_ARPE

/**
  * @}
  */

/** @defgroup TIM_Output_Fast_State TIM 输出快速状态
  * @{
  */
/* 禁用快速输出模式 */
#define TIM_OCFAST_DISABLE                 0x00000000U
/* 使能快速输出模式：触发输入有效时，CCx立即输出比较结果 */
#define TIM_OCFAST_ENABLE                  TIM_CCMR1_OC1FE
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_State TIM 互补输出比较状态
  * @{
  */
/* 禁止互补输出(OCxN信号未输出到引脚) */
#define TIM_OUTPUTNSTATE_DISABLE           0x00000000U
/* 使能互补输出(OCxN信号输出到引脚) */
#define TIM_OUTPUTNSTATE_ENABLE            TIM_CCER_CC1NE
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Polarity TIM 输出比较极性
  * @{
  */
/* 输出比较极性为高电平有效 */
#define TIM_OCPOLARITY_HIGH                0x00000000U
/* 输出比较极性为低电平有效 */
#define TIM_OCPOLARITY_LOW                 TIM_CCER_CC1P
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Polarity TIM 互补输出比较极性
  * @{
  */
/* 互补输出比较极性为高电平有效 */
#define TIM_OCNPOLARITY_HIGH               0x00000000U
/* 互补输出比较极性为低电平有效 */
#define TIM_OCNPOLARITY_LOW                TIM_CCER_CC1NP
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Idle_State TIM 输出比较空闲状态
  * @{
  */
/* 空闲状态(当MOE=0时)，OCx输出为高电平 */
#define TIM_OCIDLESTATE_SET                TIM_CR2_OIS1
/* 空闲状态(当MOE=0时)，OCx输出为低电平 */
#define TIM_OCIDLESTATE_RESET              0x00000000U
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Idle_State TIM 互补输出比较空闲状态
  * @{
  */
/* 互补输出空闲状态(当MOE=0时)，OCxN输出为高电平 */
#define TIM_OCNIDLESTATE_SET               TIM_CR2_OIS1N
/* 互补输出空闲状态(当MOE=0时)，OCxN输出为低电平 */
#define TIM_OCNIDLESTATE_RESET             0x00000000U
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Polarity TIM 输入捕获极性
  * @{
  */
/* 输入捕获上升沿触发 */
#define  TIM_ICPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING
/* 输入捕获下降沿触发 */
#define  TIM_ICPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING
/* 输入捕获双边沿触发(上升沿和下降沿均触发) */
#define  TIM_ICPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE
/**
  * @}
  */

/** @defgroup TIM_Encoder_Input_Polarity TIM 编码器输入极性
  * @{
  */
/* 编码器输入极性：上升沿有效 */
#define  TIM_ENCODERINPUTPOLARITY_RISING   TIM_INPUTCHANNELPOLARITY_RISING
/* 编码器输入极性：下降沿有效 */
#define  TIM_ENCODERINPUTPOLARITY_FALLING  TIM_INPUTCHANNELPOLARITY_FALLING
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Selection TIM 输入捕获选择
  * @{
  */
/* 直接映射：TIM输入1/2/3/4 分别连接到 IC1/IC2/IC3/IC4 */
#define TIM_ICSELECTION_DIRECTTI           TIM_CCMR1_CC1S_0
/* 间接映射：TIM输入1/2/3/4 分别连接到 IC2/IC1/IC4/IC3 */
#define TIM_ICSELECTION_INDIRECTTI         TIM_CCMR1_CC1S_1
/* 连接到TRC(内部触发输入)，用于PWM输入模式等 */
#define TIM_ICSELECTION_TRC                TIM_CCMR1_CC1S
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Prescaler TIM 输入捕获预分频
  * @{
  */
/* 无预分频：每检测到一个边沿执行一次捕获 */
#define TIM_ICPSC_DIV1                     0x00000000U
/* 2分频：每检测到2个边沿执行一次捕获 */
#define TIM_ICPSC_DIV2                     TIM_CCMR1_IC1PSC_0
/* 4分频：每检测到4个边沿执行一次捕获 */
#define TIM_ICPSC_DIV4                     TIM_CCMR1_IC1PSC_1
/* 8分频：每检测到8个边沿执行一次捕获 */
#define TIM_ICPSC_DIV8                     TIM_CCMR1_IC1PSC
/**
  * @}
  */

/** @defgroup TIM_One_Pulse_Mode TIM 单脉冲模式
  * @{
  */
/* 单脉冲模式：在下一个更新事件发生时停止计数 */
#define TIM_OPMODE_SINGLE                  TIM_CR1_OPM
/* 重复模式：在更新事件发生时不停止计数 */
#define TIM_OPMODE_REPETITIVE              0x00000000U
/**
  * @}
  */

/** @defgroup TIM_Encoder_Mode TIM 编码器模式
  * @{
  */
/* 编码器模式1：仅在TI1边沿计数(x2模式)，计数方向取决于TI2电平 */
#define TIM_ENCODERMODE_TI1                      TIM_SMCR_SMS_0
/* 编码器模式2：仅在TI2边沿计数(x2模式)，计数方向取决于TI1电平 */
#define TIM_ENCODERMODE_TI2                      TIM_SMCR_SMS_1
/* 编码器模式3：在TI1和TI2边沿均计数(x4模式)，计数方向取决于另一路输入电平 */
#define TIM_ENCODERMODE_TI12                     (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)
/**
  * @}
  */

/** @defgroup TIM_Interrupt_definition TIM 中断定义
  * @{
  */
/* 更新中断使能 */
#define TIM_IT_UPDATE                      TIM_DIER_UIE
/* 捕获/比较1中断使能 */
#define TIM_IT_CC1                         TIM_DIER_CC1IE
/* 捕获/比较2中断使能 */
#define TIM_IT_CC2                         TIM_DIER_CC2IE
/* 捕获/比较3中断使能 */
#define TIM_IT_CC3                         TIM_DIER_CC3IE
/* 捕获/比较4中断使能 */
#define TIM_IT_CC4                         TIM_DIER_CC4IE
/* 换相中断使能 */
#define TIM_IT_COM                         TIM_DIER_COMIE
/* 触发中断使能 */
#define TIM_IT_TRIGGER                     TIM_DIER_TIE
/* 刹车中断使能 */
#define TIM_IT_BREAK                       TIM_DIER_BIE
/**
  * @}
  */
/** @defgroup TIM_Commutation_Source  TIM Commutation Source
  * @{
  */
/* 当捕获/比较控制位被预装载时，可通过设置COMG位或触发输入上升沿来更新 */
#define TIM_COMMUTATION_TRGI              TIM_CR2_CCUS                          
/* 当捕获/比较控制位被预装载时，仅通过设置COMG位来更新 */
#define TIM_COMMUTATION_SOFTWARE          0x00000000U                           
/**
  * @}
  */

/** @defgroup TIM_DMA_sources TIM DMA Sources
  * @{
  */
/* DMA请求由更新事件触发 */
#define TIM_DMA_UPDATE                     TIM_DIER_UDE                         
/* DMA请求由捕获/比较匹配1事件触发 */
#define TIM_DMA_CC1                        TIM_DIER_CC1DE                       
/* DMA请求由捕获/比较匹配2事件触发 */
#define TIM_DMA_CC2                        TIM_DIER_CC2DE                       
/* DMA请求由捕获/比较匹配3事件触发 */
#define TIM_DMA_CC3                        TIM_DIER_CC3DE                       
/* DMA请求由捕获/比较匹配4事件触发 */
#define TIM_DMA_CC4                        TIM_DIER_CC4DE                       
/* DMA请求由换相事件触发 */
#define TIM_DMA_COM                        TIM_DIER_COMDE                       
/* DMA请求由触发事件触发 */
#define TIM_DMA_TRIGGER                    TIM_DIER_TDE                         
/**
  * @}
  */

/** @defgroup TIM_CC_DMA_Request CCx DMA request selection
  * @{
  */
/* 当发生捕获或比较匹配事件时发送CCx DMA请求 */
#define TIM_CCDMAREQUEST_CC                 0x00000000U                         
/* 当发生更新事件时发送CCx DMA请求 */
#define TIM_CCDMAREQUEST_UPDATE             TIM_CR2_CCDS                        
/**
  * @}
  */

/** @defgroup TIM_Flag_definition TIM Flag Definition
  * @{
  */
/* 更新中断标志 */
#define TIM_FLAG_UPDATE                    TIM_SR_UIF                           
/* 捕获/比较1中断标志 */
#define TIM_FLAG_CC1                       TIM_SR_CC1IF                         
/* 捕获/比较2中断标志 */
#define TIM_FLAG_CC2                       TIM_SR_CC2IF                         
/* 捕获/比较3中断标志 */
#define TIM_FLAG_CC3                       TIM_SR_CC3IF                         
/* 捕获/比较4中断标志 */
#define TIM_FLAG_CC4                       TIM_SR_CC4IF                         
/* 换相中断标志 */
#define TIM_FLAG_COM                       TIM_SR_COMIF                         
/* 触发中断标志 */
#define TIM_FLAG_TRIGGER                   TIM_SR_TIF                           
/* 刹车中断标志 */
#define TIM_FLAG_BREAK                     TIM_SR_BIF                           
/* 捕获1溢出标志 */
#define TIM_FLAG_CC1OF                     TIM_SR_CC1OF                         
/* 捕获2溢出标志 */
#define TIM_FLAG_CC2OF                     TIM_SR_CC2OF                         
/* 捕获3溢出标志 */
#define TIM_FLAG_CC3OF                     TIM_SR_CC3OF                         
/* 捕获4溢出标志 */
#define TIM_FLAG_CC4OF                     TIM_SR_CC4OF                         
/**
  * @}
  */

/** @defgroup TIM_Channel TIM Channel
  * @{
  */
/* 捕获/比较通道1标识 */
#define TIM_CHANNEL_1                      0x00000000U                          
/* 捕获/比较通道2标识 */
#define TIM_CHANNEL_2                      0x00000004U                          
/* 捕获/比较通道3标识 */
#define TIM_CHANNEL_3                      0x00000008U                          
/* 捕获/比较通道4标识 */
#define TIM_CHANNEL_4                      0x0000000CU                          
/* 全局捕获/比较通道标识 */
#define TIM_CHANNEL_ALL                    0x0000003CU                          
/**
  * @}
  */

/** @defgroup TIM_Clock_Source TIM Clock Source
  * @{
  */
/* 内部时钟源 */
#define TIM_CLOCKSOURCE_INTERNAL    TIM_SMCR_ETPS_0      
/* 外部时钟源模式1 (ETRF) */
#define TIM_CLOCKSOURCE_ETRMODE1    TIM_TS_ETRF          
/* 外部时钟源模式2 */
#define TIM_CLOCKSOURCE_ETRMODE2    TIM_SMCR_ETPS_1      
/* 外部时钟源模式1 (TTI1FP1 + 边沿检测) */
#define TIM_CLOCKSOURCE_TI1ED       TIM_TS_TI1F_ED       
/* 外部时钟源模式1 (TTI1FP1) */
#define TIM_CLOCKSOURCE_TI1         TIM_TS_TI1FP1        
/* 外部时钟源模式1 (TTI2FP2) */
#define TIM_CLOCKSOURCE_TI2         TIM_TS_TI2FP2        
/* 外部时钟源模式1 (ITR0) */
#define TIM_CLOCKSOURCE_ITR0        TIM_TS_ITR0          
/* 外部时钟源模式1 (ITR1) */
#define TIM_CLOCKSOURCE_ITR1        TIM_TS_ITR1          
/* 外部时钟源模式1 (ITR2) */
#define TIM_CLOCKSOURCE_ITR2        TIM_TS_ITR2          
/* 外部时钟源模式1 (ITR3) */
#define TIM_CLOCKSOURCE_ITR3        TIM_TS_ITR3          
/**
  * @}
  */

/** @defgroup TIM_Clock_Polarity TIM Clock Polarity
  * @{
  */
/* ETRx时钟源的反极性 */
#define TIM_CLOCKPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED           
/* ETRx时钟源的非反极性 */
#define TIM_CLOCKPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED        
/* TIx时钟源的上升沿极性 */
#define TIM_CLOCKPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING    
/* TIx时钟源的下降沿极性 */
#define TIM_CLOCKPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING   
/* TIx时钟源的双边沿极性 */
#define TIM_CLOCKPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE  
/**
  * @}
  */

/** @defgroup TIM_Clock_Prescaler TIM Clock Prescaler
  * @{
  */
/* 不使用预分频器 */
#define TIM_CLOCKPRESCALER_DIV1                 TIM_ETRPRESCALER_DIV1           
/* 外部ETR时钟预分频：每2个事件执行一次捕获 */
#define TIM_CLOCKPRESCALER_DIV2                 TIM_ETRPRESCALER_DIV2           
/* 外部ETR时钟预分频：每4个事件执行一次捕获 */
#define TIM_CLOCKPRESCALER_DIV4                 TIM_ETRPRESCALER_DIV4           
/* 外部ETR时钟预分频：每8个事件执行一次捕获 */
#define TIM_CLOCKPRESCALER_DIV8                 TIM_ETRPRESCALER_DIV8           
/**
  * @}
  */

/** @defgroup TIM_ClearInput_Polarity TIM Clear Input Polarity
  * @{
  */
/* ETRx引脚的反极性 */
#define TIM_CLEARINPUTPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED      
/* ETRx引脚的非反极性 */
#define TIM_CLEARINPUTPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED   
/**
  * @}
  */

/** @defgroup TIM_ClearInput_Prescaler TIM Clear Input Prescaler
  * @{
  */
/* 不使用预分频器 */
#define TIM_CLEARINPUTPRESCALER_DIV1              TIM_ETRPRESCALER_DIV1         
/* 外部ETR引脚预分频：每2个事件执行一次捕获 */
#define TIM_CLEARINPUTPRESCALER_DIV2              TIM_ETRPRESCALER_DIV2         
/* 外部ETR引脚预分频：每4个事件执行一次捕获 */
#define TIM_CLEARINPUTPRESCALER_DIV4              TIM_ETRPRESCALER_DIV4         
/* 外部ETR引脚预分频：每8个事件执行一次捕获 */
#define TIM_CLEARINPUTPRESCALER_DIV8              TIM_ETRPRESCALER_DIV8         
/**
  * @}
  */

/** @defgroup TIM_OSSR_Off_State_Selection_for_Run_mode_state TIM OSSR OffState Selection for Run mode state
  * @{
  */
/* 运行模式下，当不活动时，OC/OCN输出使能（仍由定时器控制） */
#define TIM_OSSR_ENABLE                          TIM_BDTR_OSSR                  
/* 运行模式下，当不活动时，OC/OCN输出禁止（不再由定时器控制） */
#define TIM_OSSR_DISABLE                         0x00000000U                    
/**
  * @}
  */

/** @defgroup TIM_OSSI_Off_State_Selection_for_Idle_mode_state TIM OSSI OffState Selection for Idle mode state
  * @{
  */
/* 空闲模式下，当不活动时，OC/OCN输出使能（仍由定时器控制） */
#define TIM_OSSI_ENABLE                          TIM_BDTR_OSSI                  
/* 空闲模式下，当不活动时，OC/OCN输出禁止（不再由定时器控制） */
#define TIM_OSSI_DISABLE                         0x00000000U                    
/**
  * @}
  */
/** @defgroup TIM_Lock_level  TIM Lock level
  * @{
  */
/* 锁定关闭 */
#define TIM_LOCKLEVEL_OFF                  0x00000000U                          
/* 锁定级别1 */
#define TIM_LOCKLEVEL_1                    TIM_BDTR_LOCK_0                      
/* 锁定级别2 */
#define TIM_LOCKLEVEL_2                    TIM_BDTR_LOCK_1                      
/* 锁定级别3 */
#define TIM_LOCKLEVEL_3                    TIM_BDTR_LOCK                        
/**
  * @}
  */

/** @defgroup TIM_Break_Input_enable_disable TIM Break Input Enable
  * @{
  */
/* 刹车输入BRK使能 */
#define TIM_BREAK_ENABLE                   TIM_BDTR_BKE                         
/* 刹车输入BRK禁止 */
#define TIM_BREAK_DISABLE                  0x00000000U                          
/**
  * @}
  */

/** @defgroup TIM_Break_Polarity TIM Break Input Polarity
  * @{
  */
/* 刹车输入BRK低电平有效 */
#define TIM_BREAKPOLARITY_LOW              0x00000000U                          
/* 刹车输入BRK高电平有效 */
#define TIM_BREAKPOLARITY_HIGH             TIM_BDTR_BKP                         
/**
  * @}
  */

/** @defgroup TIM_AOE_Bit_Set_Reset TIM Automatic Output Enable
  * @{
  */
/* MOE位仅能通过软件设置 */
#define TIM_AUTOMATICOUTPUT_DISABLE        0x00000000U                          
/* MOE位可通过软件设置，或在下一个更新事件自动设置（前提是无刹车输入有效） */
#define TIM_AUTOMATICOUTPUT_ENABLE         TIM_BDTR_AOE                         
/**
  * @}
  */

/** @defgroup TIM_Master_Mode_Selection TIM Master Mode Selection
  * @{
  */
/* 使用TIMx_EGR.UG位作为触发输出(TRGO) */
#define TIM_TRGO_RESET            0x00000000U                                      
/* 使用TIMx_CR1.CEN位作为触发输出(TRGO) */
#define TIM_TRGO_ENABLE           TIM_CR2_MMS_0                                    
/* 使用更新事件作为触发输出(TRGO) */
#define TIM_TRGO_UPDATE           TIM_CR2_MMS_1                                    
/* 使用捕获或比较匹配1作为触发输出(TRGO) */
#define TIM_TRGO_OC1              (TIM_CR2_MMS_1 | TIM_CR2_MMS_0)                  
/* 使用OC1REF信号作为触发输出(TRGO) */
#define TIM_TRGO_OC1REF           TIM_CR2_MMS_2                                    
/* 使用OC2REF信号作为触发输出(TRGO) */
#define TIM_TRGO_OC2REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_0)                  
/* 使用OC3REF信号作为触发输出(TRGO) */
#define TIM_TRGO_OC3REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_1)                  
/* 使用OC4REF信号作为触发输出(TRGO) */
#define TIM_TRGO_OC4REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_1 | TIM_CR2_MMS_0)  
/**
  * @}
  */

/** @defgroup TIM_Master_Slave_Mode TIM Master/Slave Mode
  * @{
  */
/* 主/从模式使能：无动作（注：此处原文注释可能有误，实际功能为使能主从模式） */
#define TIM_MASTERSLAVEMODE_ENABLE         TIM_SMCR_MSM                         
/* 主/从模式禁止：未选择主从模式 */
#define TIM_MASTERSLAVEMODE_DISABLE        0x00000000U                          
/**
  * @}
  */

/** @defgroup TIM_Slave_Mode TIM Slave mode
  * @{
  */
/* 从模式禁止 */
#define TIM_SLAVEMODE_DISABLE                0x00000000U                                        
/* 复位模式 */
#define TIM_SLAVEMODE_RESET                  TIM_SMCR_SMS_2                                     
/* 门控模式 */
#define TIM_SLAVEMODE_GATED                  (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0)                  
/* 触发模式 */
#define TIM_SLAVEMODE_TRIGGER                (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1)                  
/* 外部时钟模式1 */
#define TIM_SLAVEMODE_EXTERNAL1              (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0) 
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_and_PWM_modes TIM Output Compare and PWM Modes
  * @{
  */
/* 冻结模式：比较寄存器与计数器之间的比较对输出无影响 */
#define TIM_OCMODE_TIMING                   0x00000000U                                              
/* 匹配时设置通道为有效电平 */
#define TIM_OCMODE_ACTIVE                   TIM_CCMR1_OC1M_0                                          
/* 匹配时设置通道为无效电平 */
#define TIM_OCMODE_INACTIVE                 TIM_CCMR1_OC1M_1                                          
/* 翻转模式：匹配时翻转输出 */
#define TIM_OCMODE_TOGGLE                   (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)                    
/* PWM模式1：向上计数时，CNT<CCR为有效电平，否则为无效电平 */
#define TIM_OCMODE_PWM1                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1)                    
/* PWM模式2：向上计数时，CNT<CCR为无效电平，否则为有效电平 */
#define TIM_OCMODE_PWM2                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0) 
/* 强制为有效电平 */
#define TIM_OCMODE_FORCED_ACTIVE            (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0)                    
/* 强制为无效电平 */
#define TIM_OCMODE_FORCED_INACTIVE          TIM_CCMR1_OC1M_2                                          
/**
  * @}
  */

/** @defgroup TIM_Trigger_Selection TIM Trigger Selection
  * @{
  */
/* 内部触发0 (ITR0) */
#define TIM_TS_ITR0          0x00000000U                                                       
/* 内部触发1 (ITR1) */
#define TIM_TS_ITR1          TIM_SMCR_TS_0                                                     
/* 内部触发2 (ITR2) */
#define TIM_TS_ITR2          TIM_SMCR_TS_1                                                     
/* 内部触发3 (ITR3) */
#define TIM_TS_ITR3          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1)                                    
/* TI1边沿检测器 (TI1F_ED) */
#define TIM_TS_TI1F_ED       TIM_SMCR_TS_2                                                     
/* 滤波后的定时器输入1 (TI1FP1) */
#define TIM_TS_TI1FP1        (TIM_SMCR_TS_0 | TIM_SMCR_TS_2)                                    
/* 滤波后的定时器输入2 (TI2FP2) */
#define TIM_TS_TI2FP2        (TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                                    
/* 滤波后的外部触发输入 (ETRF) */
#define TIM_TS_ETRF          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                   
/* 无触发选择 */
#define TIM_TS_NONE          0x0000FFFFU                                                       
/**
  * @}
  */

/** @defgroup TIM_Trigger_Polarity TIM Trigger Polarity
  * @{
  */
/* ETRx触发源的反极性 */
#define TIM_TRIGGERPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED               
/* ETRx触发源的非反极性 */
#define TIM_TRIGGERPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED            
/* TIxFPx或TI1_ED触发源的上升沿极性 */
#define TIM_TRIGGERPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING        
/* TIxFPx或TI1_ED触发源的下降沿极性 */
#define TIM_TRIGGERPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING       
/* TIxFPx或TI1_ED触发源的双边沿极性 */
#define TIM_TRIGGERPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE      
/**
  * @}
  */

/** @defgroup TIM_Trigger_Prescaler TIM Trigger Prescaler
  * @{
  */
/* 不使用预分频器 */
#define TIM_TRIGGERPRESCALER_DIV1             TIM_ETRPRESCALER_DIV1             
/* 外部ETR触发预分频：每2个事件执行一次捕获 */
#define TIM_TRIGGERPRESCALER_DIV2             TIM_ETRPRESCALER_DIV2             
/* 外部ETR触发预分频：每4个事件执行一次捕获 */
#define TIM_TRIGGERPRESCALER_DIV4             TIM_ETRPRESCALER_DIV4             
/* 外部ETR触发预分频：每8个事件执行一次捕获 */
#define TIM_TRIGGERPRESCALER_DIV8             TIM_ETRPRESCALER_DIV8             
/**
  * @}
  */

/** @defgroup TIM_TI1_Selection TIM TI1 Input Selection
  * @{
  */
/* TIMx_CH1引脚连接到TI1输入 */
#define TIM_TI1SELECTION_CH1               0x00000000U                          
/* TIMx_CH1、CH2和CH3引脚连接到TI1输入（异或组合） */
#define TIM_TI1SELECTION_XORCOMBINATION    TIM_CR2_TI1S                         
/**
  * @}
  */
/** @defgroup TIM_DMA_Burst_Length TIM DMA Burst Length
  * @{
  */
/* DMA突发传输长度配置：配置DMA一次突发传输访问的寄存器数量 */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输1个寄存器 */
#define TIM_DMABURSTLENGTH_1TRANSFER       0x00000000U                          /*!< The transfer is done to 1 register starting from TIMx_CR1 + TIMx_DCR.DBA   */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输2个寄存器 */
#define TIM_DMABURSTLENGTH_2TRANSFERS      0x00000100U                          /*!< The transfer is done to 2 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输3个寄存器 */
#define TIM_DMABURSTLENGTH_3TRANSFERS      0x00000200U                          /*!< The transfer is done to 3 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输4个寄存器 */
#define TIM_DMABURSTLENGTH_4TRANSFERS      0x00000300U                          /*!< The transfer is done to 4 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输5个寄存器 */
#define TIM_DMABURSTLENGTH_5TRANSFERS      0x00000400U                          /*!< The transfer is done to 5 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输6个寄存器 */
#define TIM_DMABURSTLENGTH_6TRANSFERS      0x00000500U                          /*!< The transfer is done to 6 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输7个寄存器 */
#define TIM_DMABURSTLENGTH_7TRANSFERS      0x00000600U                          /*!< The transfer is done to 7 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输8个寄存器 */
#define TIM_DMABURSTLENGTH_8TRANSFERS      0x00000700U                          /*!< The transfer is done to 8 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输9个寄存器 */
#define TIM_DMABURSTLENGTH_9TRANSFERS      0x00000800U                          /*!< The transfer is done to 9 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输10个寄存器 */
#define TIM_DMABURSTLENGTH_10TRANSFERS     0x00000900U                          /*!< The transfer is done to 10 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输11个寄存器 */
#define TIM_DMABURSTLENGTH_11TRANSFERS     0x00000A00U                          /*!< The transfer is done to 11 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输12个寄存器 */
#define TIM_DMABURSTLENGTH_12TRANSFERS     0x00000B00U                          /*!< The transfer is done to 12 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输13个寄存器 */
#define TIM_DMABURSTLENGTH_13TRANSFERS     0x00000C00U                          /*!< The transfer is done to 13 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输14个寄存器 */
#define TIM_DMABURSTLENGTH_14TRANSFERS     0x00000D00U                          /*!< The transfer is done to 14 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输15个寄存器 */
#define TIM_DMABURSTLENGTH_15TRANSFERS     0x00000E00U                          /*!< The transfer is done to 15 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输16个寄存器 */
#define TIM_DMABURSTLENGTH_16TRANSFERS     0x00000F00U                          /*!< The transfer is done to 16 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输17个寄存器 */
#define TIM_DMABURSTLENGTH_17TRANSFERS     0x00001000U                          /*!< The transfer is done to 17 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输18个寄存器 */
#define TIM_DMABURSTLENGTH_18TRANSFERS     0x00001100U                          /*!< The transfer is done to 18 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/**
  * @}
  */

/** @defgroup DMA_Handle_index TIM DMA Handle Index
  * @{
  */
/* DMA句柄索引定义：用于区分不同的TIM DMA请求源 */
/* 用于更新事件的DMA请求索引 */
#define TIM_DMA_ID_UPDATE                ((uint16_t) 0x0000)       /*!< Index of the DMA handle used for Update DMA requests */
/* 用于捕获/比较通道1的DMA请求索引 */
#define TIM_DMA_ID_CC1                   ((uint16_t) 0x0001)       /*!< Index of the DMA handle used for Capture/Compare 1 DMA requests */
/* 用于捕获/比较通道2的DMA请求索引 */
#define TIM_DMA_ID_CC2                   ((uint16_t) 0x0002)       /*!< Index of the DMA handle used for Capture/Compare 2 DMA requests */
/* 用于捕获/比较通道3的DMA请求索引 */
#define TIM_DMA_ID_CC3                   ((uint16_t) 0x0003)       /*!< Index of the DMA handle used for Capture/Compare 3 DMA requests */
/* 用于捕获/比较通道4的DMA请求索引 */
#define TIM_DMA_ID_CC4                   ((uint16_t) 0x0004)       /*!< Index of the DMA handle used for Capture/Compare 4 DMA requests */
/* 用于换相事件的DMA请求索引 */
#define TIM_DMA_ID_COMMUTATION           ((uint16_t) 0x0005)       /*!< Index of the DMA handle used for Commutation DMA requests */
/* 用于触发事件的DMA请求索引 */
#define TIM_DMA_ID_TRIGGER               ((uint16_t) 0x0006)       /*!< Index of the DMA handle used for Trigger DMA requests */
/**
  * @}
  */

/** @defgroup Channel_CC_State TIM Capture/Compare Channel State
  * @{
  */
/* 捕获/比较通道状态定义 */
/* 输入或输出通道使能 */
#define TIM_CCx_ENABLE                   0x00000001U                            /*!< Input or output channel is enabled */
/* 输入或输出通道禁用 */
#define TIM_CCx_DISABLE                  0x00000000U                            /*!< Input or output channel is disabled */
/* 互补输出通道使能 */
#define TIM_CCxN_ENABLE                  0x00000004U                            /*!< Complementary output channel is enabled */
/* 互补输出通道禁用 */
#define TIM_CCxN_DISABLE                 0x00000000U                            /*!< Complementary output channel is enabled */
/**
  * @}
  */

/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TIM_Exported_Macros TIM Exported Macros
  * @{
  */

/** @brief  Reset TIM handle state.
  * @param  __HANDLE__ TIM handle.
  * @retval None
  */
/* 复位TIM句柄状态：将TIM句柄中的所有状态变量和回调函数指针重置为初始值 */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                                /* 如果启用了回调注册功能，则同时将回调函数指针置空 */\
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;          /* 复位TIM状态 */\
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道1状态 */\
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道2状态 */\
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道3状态 */\
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道4状态 */\
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道1状态 */\
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道2状态 */\
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道3状态 */\
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道4状态 */\
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;    /* 复位DMA突发传输状态 */\
                                                      (__HANDLE__)->Base_MspInitCallback         = NULL;             /* 基础模式MspInit回调置空 */\
                                                      (__HANDLE__)->Base_MspDeInitCallback       = NULL;             /* 基础模式MspDeInit回调置空 */\
                                                      (__HANDLE__)->IC_MspInitCallback           = NULL;             /* 输入捕获MspInit回调置空 */\
                                                      (__HANDLE__)->IC_MspDeInitCallback         = NULL;             /* 输入捕获MspDeInit回调置空 */\
                                                      (__HANDLE__)->OC_MspInitCallback           = NULL;             /* 输出比较MspInit回调置空 */\
                                                      (__HANDLE__)->OC_MspDeInitCallback         = NULL;             /* 输出比较MspDeInit回调置空 */\
                                                      (__HANDLE__)->PWM_MspInitCallback          = NULL;             /* PWM模式MspInit回调置空 */\
                                                      (__HANDLE__)->PWM_MspDeInitCallback        = NULL;             /* PWM模式MspDeInit回调置空 */\
                                                      (__HANDLE__)->OnePulse_MspInitCallback     = NULL;             /* 单脉冲模式MspInit回调置空 */\
                                                      (__HANDLE__)->OnePulse_MspDeInitCallback   = NULL;             /* 单脉冲模式MspDeInit回调置空 */\
                                                      (__HANDLE__)->Encoder_MspInitCallback      = NULL;             /* 编码器模式MspInit回调置空 */\
                                                      (__HANDLE__)->Encoder_MspDeInitCallback    = NULL;             /* 编码器模式MspDeInit回调置空 */\
                                                      (__HANDLE__)->HallSensor_MspInitCallback   = NULL;             /* 霍尔传感器MspInit回调置空 */\
                                                      (__HANDLE__)->HallSensor_MspDeInitCallback = NULL;             /* 霍尔传感器MspDeInit回调置空 */\
                                                     } while(0)
#else
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                                /* 仅复位状态变量，不处理回调函数 */\
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;          /* 复位TIM状态 */\
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道1状态 */\
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道2状态 */\
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道3状态 */\
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位通道4状态 */\
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道1状态 */\
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道2状态 */\
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道3状态 */\
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET;  /* 复位互补通道4状态 */\
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;    /* 复位DMA突发传输状态 */\
                                                     } while(0)
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @brief  Enable the TIM peripheral.
  * @param  __HANDLE__ TIM handle
  * @retval None
  */
/* 使能TIM外设：置位CR1寄存器的CEN位（计数器使能位），启动定时器计数 */
#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))

/**
  * @brief  Enable the TIM main Output.
  * @param  __HANDLE__ TIM handle
  * @retval None
  */
/* 使能TIM主输出：置位BDTR寄存器的MOE位（主输出使能），对于高级定时器输出PWM必须使能此位 */
#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))

/**
  * @brief  Disable the TIM peripheral.
  * @param  __HANDLE__ TIM handle
  * @retval None
  */
/* 禁用TIM外设：只有当所有通道(CCxE)和互补通道(CCxNE)都未使能时，才关闭计数器(CEN) */
#define __HAL_TIM_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL)  /* 检查是否所有输入/输出通道都禁用 */\
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL)  /* 检查是否所有互补输出通道都禁用 */\
      { \
        (__HANDLE__)->Instance->CR1 &= ~(TIM_CR1_CEN);  /* 如果都禁用，则清除CEN位，停止计数 */\
      } \
    } \
  } while(0)

/**
  * @brief  Disable the TIM main Output.
  * @param  __HANDLE__ TIM handle
  * @retval None
  * @note The Main Output Enable of a timer instance is disabled only if all the CCx and CCxN channels have been
  *       disabled
  */
/* 禁用TIM主输出：只有当所有通道(CCxE)和互补通道(CCxNE)都未使能时，才关闭主输出(MOE) */
#define __HAL_TIM_MOE_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL)  /* 检查是否所有输入/输出通道都禁用 */\
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL)  /* 检查是否所有互补输出通道都禁用 */\
      { \
        (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE);  /* 如果都禁用，则清除MOE位，关闭主输出 */\
      } \
    } \
  } while(0)

/**
  * @brief  Disable the TIM main Output.
  * @param  __HANDLE__ TIM handle
  * @retval None
  * @note The Main Output Enable of a timer instance is disabled unconditionally
  */
/* 无条件禁用TIM主输出：直接清除MOE位，不检查通道状态 */
#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)

/** @brief  Enable the specified TIM interrupt.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __INTERRUPT__ specifies the TIM interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval None
  */
/* 使能指定的TIM中断：通过设置DIER寄存器的对应位来开启中断 */
#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  Disable the specified TIM interrupt.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __INTERRUPT__ specifies the TIM interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval None
  */
/* 禁用指定的TIM中断：通过清除DIER寄存器的对应位来关闭中断 */
#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

/** @brief  Enable the specified DMA request.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __DMA__ specifies the TIM DMA request to enable.
  *          This parameter can be one of the following values:
  *            @arg TIM_DMA_UPDATE: Update DMA request
  *            @arg TIM_DMA_CC1:   Capture/Compare 1 DMA request
  *            @arg TIM_DMA_CC2:  Capture/Compare 2 DMA request
  *            @arg TIM_DMA_CC3:  Capture/Compare 3 DMA request
  *            @arg TIM_DMA_CC4:  Capture/Compare 4 DMA request
  *            @arg TIM_DMA_COM:   Commutation DMA request
  *            @arg TIM_DMA_TRIGGER: Trigger DMA request
  * @retval None
  */
/* 使能指定的DMA请求：通过设置DIER寄存器的对应位来开启DMA请求 */
#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  Disable the specified DMA request.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __DMA__ specifies the TIM DMA request to disable.
  *          This parameter can be one of the following values:
  *            @arg TIM_DMA_UPDATE: Update DMA request
  *            @arg TIM_DMA_CC1:   Capture/Compare 1 DMA request
  *            @arg TIM_DMA_CC2:  Capture/Compare 2 DMA request
  *            @arg TIM_DMA_CC3:  Capture/Compare 3 DMA request
  *            @arg TIM_DMA_CC4:  Capture/Compare 4 DMA request
  *            @arg TIM_DMA_COM:   Commutation DMA request
  *            @arg TIM_DMA_TRIGGER: Trigger DMA request
  * @retval None
  */
/* 禁用指定的DMA请求：通过清除DIER寄存器的对应位来关闭DMA请求 */
#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))

/** @brief  Check whether the specified TIM interrupt flag is set or not.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __FLAG__ specifies the TIM interrupt flag to check.
  *        This parameter can be one of the following values:
  *            @arg TIM_FLAG_UPDATE: Update interrupt flag
  *            @arg TIM_FLAG_CC1: Capture/Compare 1 interrupt flag
  *            @arg TIM_FLAG_CC2: Capture/Compare 2 interrupt flag
  *            @arg TIM_FLAG_CC3: Capture/Compare 3 interrupt flag
  *            @arg TIM_FLAG_CC4: Capture/Compare 4 interrupt flag
  *            @arg TIM_FLAG_COM:  Commutation interrupt flag
  *            @arg TIM_FLAG_TRIGGER: Trigger interrupt flag
  *            @arg TIM_FLAG_BREAK: Break interrupt flag
  *            @arg TIM_FLAG_CC1OF: Capture/Compare 1 overcapture flag
  *            @arg TIM_FLAG_CC2OF: Capture/Compare 2 overcapture flag
  *            @arg TIM_FLAG_CC3OF: Capture/Compare 3 overcapture flag
  *            @arg TIM_FLAG_CC4OF: Capture/Compare 4 overcapture flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
/* 检查指定的TIM中断标志位是否被置位：读取SR寄存器并判断对应标志位 */
#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  Clear the specified TIM interrupt flag.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __FLAG__ specifies the TIM interrupt flag to clear.
  *        This parameter can be one of the following values:
  *            @arg TIM_FLAG_UPDATE: Update interrupt flag
  *            @arg TIM_FLAG_CC1: Capture/Compare 1 interrupt flag
  *            @arg TIM_FLAG_CC2: Capture/Compare 2 interrupt flag
  *            @arg TIM_FLAG_CC3: Capture/Compare 3 interrupt flag
  *            @arg TIM_FLAG_CC4: Capture/Compare 4 interrupt flag
  *            @arg TIM_FLAG_COM:  Commutation interrupt flag
  *            @arg TIM_FLAG_TRIGGER: Trigger interrupt flag
  *            @arg TIM_FLAG_BREAK: Break interrupt flag
  *            @arg TIM_FLAG_CC1OF: Capture/Compare 1 overcapture flag
  *            @arg TIM_FLAG_CC2OF: Capture/Compare 2 overcapture flag
  *            @arg TIM_FLAG_CC3OF: Capture/Compare 3 overcapture flag
  *            @arg TIM_FLAG_CC4OF: Capture/Compare 4 overcapture flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
/* 清除指定的TIM中断标志位：向SR寄存器写入反码来清除标志位 */
#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  Check whether the specified TIM interrupt source is enabled or not.
  * @param  __HANDLE__ TIM handle
  * @param  __INTERRUPT__ specifies the TIM interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval The state of TIM_IT (SET or RESET).
  */
/* 检查指定的TIM中断源是否已使能：读取DIER寄存器并判断对应的中断使能位 */
#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief Clear the TIM interrupt pending bits.
  * @param  __HANDLE__ TIM handle
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval None
  */
/* 清除TIM中断挂起位：向SR寄存器写入反码，功能与__HAL_TIM_CLEAR_FLAG类似 */
#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  Indicates whether or not the TIM Counter is used as downcounter.
  * @param  __HANDLE__ TIM handle.
  * @retval False (Counter used as upcounter) or True (Counter used as downcounter)
  * @note This macro is particularly useful to get the counting mode when the timer operates in Center-aligned mode
  *       or Encoder mode.
  */
/* 检查TIM计数器是否正在向下计数：读取CR1寄存器的DIR位，用于判断当前计数方向 */
#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))

/**
  * @brief  Set the TIM Prescaler on runtime.
  * @param  __HANDLE__ TIM handle.
  * @param  __PRESC__ specifies the Prescaler new value.
  * @retval None
  */
/* 运行时设置TIM预分频值：直接写入PSC寄存器，用于动态调整定时器时钟频率 */
#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  Set the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @param  __COUNTER__ specifies the Counter register new value.
  * @retval None
  */
/* 运行时设置TIM计数器值：直接写入CNT寄存器，用于设置当前计数值 */
#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  Get the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @retval 16-bit or 32-bit value of the timer counter register (TIMx_CNT)
  */
/* 运行时获取TIM计数器当前值：读取CNT寄存器，用于获取当前计数值 */
#define __HAL_TIM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)
/**
  * @brief  在运行时设置TIM自动重装载寄存器值，无需再次调用初始化函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __AUTORELOAD__: 指定计数器寄存器的新值。
  * @retval 无
  */
#define __HAL_TIM_SET_AUTORELOAD(__HANDLE__, __AUTORELOAD__) \
  do{                                                    \
    (__HANDLE__)->Instance->ARR = (__AUTORELOAD__);   /* 直接设置ARR寄存器，决定计数器溢出值 */\
    (__HANDLE__)->Init.Period = (__AUTORELOAD__);     /* 同步更新句柄中的初始化结构体参数，保持一致性 */\
  } while(0)

/**
  * @brief  在运行时获取TIM自动重装载寄存器值。
  * @param  __HANDLE__: TIM句柄。
  * @retval 定时器自动重装载寄存器的16位或32位值(TIMx_ARR)
  */
#define __HAL_TIM_GET_AUTORELOAD(__HANDLE__)  ((__HANDLE__)->Instance->ARR)

/**
  * @brief  在运行时设置TIM时钟分频值，无需再次调用初始化函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CKD__: 指定时钟分频值。
  *          该参数可以是以下值之一:
  *            @arg TIM_CLOCKDIVISION_DIV1: tDTS=tCK_INT (不分频)
  *            @arg TIM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT (2分频)
  *            @arg TIM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT (4分频)
  * @retval 无
  */
#define __HAL_TIM_SET_CLOCKDIVISION(__HANDLE__, __CKD__) \
  do{                                                   \
    (__HANDLE__)->Instance->CR1 &= (~TIM_CR1_CKD);   /* 清除CR1寄存器中的CKD位 */\
    (__HANDLE__)->Instance->CR1 |= (__CKD__);        /* 设置新的CKD位值 */\
    (__HANDLE__)->Init.ClockDivision = (__CKD__);    /* 同步更新句柄中的初始化结构体参数 */\
  } while(0)

/**
  * @brief  在运行时获取TIM时钟分频值。
  * @param  __HANDLE__: TIM句柄。
  * @retval 时钟分频值，可以是以下值之一:
  *            @arg TIM_CLOCKDIVISION_DIV1: tDTS=tCK_INT
  *            @arg TIM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT
  *            @arg TIM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT
  */
#define __HAL_TIM_GET_CLOCKDIVISION(__HANDLE__)  ((__HANDLE__)->Instance->CR1 & TIM_CR1_CKD)

/**
  * @brief  在运行时设置TIM输入捕获预分频值，无需再次调用HAL_TIM_IC_ConfigChannel()函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @param  __ICPSC__: 指定输入捕获预分频新值。
  *          该参数可以是以下值之一:
  *            @arg TIM_ICPSC_DIV1: 无预分频
  *            @arg TIM_ICPSC_DIV2: 每2个事件捕获一次
  *            @arg TIM_ICPSC_DIV4: 每4个事件捕获一次
  *            @arg TIM_ICPSC_DIV8: 每8个事件捕获一次
  * @retval 无
  */
#define __HAL_TIM_SET_ICPRESCALER(__HANDLE__, __CHANNEL__, __ICPSC__) \
  do{                                                    \
    TIM_RESET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__));   /* 复位该通道的预分频值 */\
    TIM_SET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__), (__ICPSC__));  /* 设置新的预分频值 */\
  } while(0)

/**
  * @brief  在运行时获取TIM输入捕获预分频值。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 获取输入捕获1预分频值
  *            @arg TIM_CHANNEL_2: 获取输入捕获2预分频值
  *            @arg TIM_CHANNEL_3: 获取输入捕获3预分频值
  *            @arg TIM_CHANNEL_4: 获取输入捕获4预分频值
  * @retval 输入捕获预分频值，可以是以下值之一:
  *            @arg TIM_ICPSC_DIV1: 无预分频
  *            @arg TIM_ICPSC_DIV2: 每2个事件捕获一次
  *            @arg TIM_ICPSC_DIV4: 每4个事件捕获一次
  *            @arg TIM_ICPSC_DIV8: 每8个事件捕获一次
  */
#define __HAL_TIM_GET_ICPRESCALER(__HANDLE__, __CHANNEL__)  \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC1PSC) : /* 如果是通道1，读取CCMR1的IC1PSC位 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC2PSC) >> 8U) : /* 如果是通道2，读取CCMR1的IC2PSC位并右移8位 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC3PSC) : /* 如果是通道3，读取CCMR2的IC3PSC位 */\
   (((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC4PSC)) >> 8U) /* 否则为通道4，读取CCMR2的IC4PSC位并右移8位 */

/**
  * @brief  在运行时设置TIM捕获比较寄存器值，无需再次调用ConfigChannel函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @param  __COMPARE__: 指定捕获比较寄存器新值。
  * @retval 无
  */
#define __HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1 = (__COMPARE__)) : /* 设置通道1的比较值 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2 = (__COMPARE__)) : /* 设置通道2的比较值 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3 = (__COMPARE__)) : /* 设置通道3的比较值 */\
   ((__HANDLE__)->Instance->CCR4 = (__COMPARE__))) /* 设置通道4的比较值 */

/**
  * @brief  在运行时获取TIM捕获比较寄存器值。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 与捕获比较寄存器关联的TIM通道
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 获取捕获/比较1寄存器值
  *            @arg TIM_CHANNEL_2: 获取捕获/比较2寄存器值
  *            @arg TIM_CHANNEL_3: 获取捕获/比较3寄存器值
  *            @arg TIM_CHANNEL_4: 获取捕获/比较4寄存器值
  * @retval 捕获/比较寄存器的16位或32位值(TIMx_CCRy)
  */
#define __HAL_TIM_GET_COMPARE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1) : /* 获取通道1的比较值 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2) : /* 获取通道2的比较值 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3) : /* 获取通道3的比较值 */\
   ((__HANDLE__)->Instance->CCR4)) /* 获取通道4的比较值 */

/**
  * @brief  设置TIM输出比较预装载使能。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @retval 无
  */
#define __HAL_TIM_ENABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1PE) : /* 使能通道1预装载 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2PE) : /* 使能通道2预装载 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3PE) : /* 使能通道3预装载 */\
   ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4PE)) /* 使能通道4预装载 */

/**
  * @brief  禁用TIM输出比较预装载。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @retval 无
  */
#define __HAL_TIM_DISABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC1PE) : /* 禁用通道1预装载 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC2PE) : /* 禁用通道2预装载 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC3PE) : /* 禁用通道3预装载 */\
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC4PE)) /* 禁用通道4预装载 */

/**
  * @brief  使能指定通道的快速模式。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @note  当快速模式使能时，触发输入上的有效边沿就像CCx输出上的比较匹配一样。
  *        采样触发输入和激活CCx输出的延迟减少到3个时钟周期。
  * @note  快速模式仅在通道配置为PWM1或PWM2模式时起作用。
  * @retval 无
  */
#define __HAL_TIM_ENABLE_OCxFAST(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1FE) : /* 使能通道1快速模式 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2FE) : /* 使能通道2快速模式 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3FE) : /* 使能通道3快速模式 */\
   ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4FE)) /* 使能通道4快速模式 */

/**
  * @brief  禁用指定通道的快速模式。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @note  当快速模式禁用时，CCx输出行为正常，取决于计数器和CCRx值，即使触发处于开启状态。
  *        当触发输入上发生有效边沿时，激活CCx输出的最小延迟为5个时钟周期。
  * @retval 无
  */
#define __HAL_TIM_DISABLE_OCxFAST(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC1FE) : /* 禁用通道1快速模式 */\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC2FE) : /* 禁用通道2快速模式 */\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC3FE) : /* 禁用通道3快速模式 */\
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC4FE)) /* 禁用通道4快速模式 */

/**
  * @brief  设置TIMx_CR1寄存器的更新请求源(URS)位。
  * @param  __HANDLE__: TIM句柄。
  * @note  当TIMx_CR1寄存器的URS位置位时，只有计数器溢出/下溢才生成更新中断或DMA请求(如果使能)。
  * @retval 无
  */
#define __HAL_TIM_URS_ENABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1|= TIM_CR1_URS)

/**
  * @brief  复位TIMx_CR1寄存器的更新请求源(URS)位。
  * @param  __HANDLE__: TIM句柄。
  * @note  当TIMx_CR1寄存器的URS位复位时，以下任何事件都会生成更新中断或DMA请求(如果使能):
  *           _ 计数器溢出下溢
  *           _ 设置UG位
  *           _ 通过从模式控制器生成的更新
  * @retval 无
  */
#define __HAL_TIM_URS_DISABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1&=~TIM_CR1_URS)

/**
  * @brief  在运行时设置TIM捕获x输入极性。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @param  __POLARITY__: TIx源的极性
  *            @arg TIM_INPUTCHANNELPOLARITY_RISING: 上升沿
  *            @arg TIM_INPUTCHANNELPOLARITY_FALLING: 下降沿
  *            @arg TIM_INPUTCHANNELPOLARITY_BOTHEDGE: 双边沿(上升和下降沿)
  * @retval 无
  */
#define __HAL_TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__)    \
  do{                                                                     \
    TIM_RESET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__));                /* 复位捕获极性设置 */\
    TIM_SET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__), (__POLARITY__));  /* 设置新的捕获极性 */\
  }while(0)

/** @brief  选择捕获/比较DMA请求源。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __CCDMA__: 指定捕获/比较DMA请求源
  *          该参数可以是以下值之一:
  *            @arg TIM_CCDMAREQUEST_CC: 在捕获/比较事件上生成CCx DMA请求
  *            @arg TIM_CCDMAREQUEST_UPDATE: 在更新事件上生成CCx DMA请求
  * @retval 无
  */
#define __HAL_TIM_SELECT_CCDMAREQUEST(__HANDLE__, __CCDMA__)    \
  MODIFY_REG((__HANDLE__)->Instance->CR2, TIM_CR2_CCDS, (__CCDMA__))

/**
  * @}
  */
/* 导出宏结束 ----------------------------------------------------*/

/* 私有常量 ---------------------------------------------------------*/
/** @defgroup TIM_Private_Constants TIM 私有常量
  * @{
  */
/* 只有当所有CCx和CCxN通道都被禁用时，定时器实例的计数器才会被禁用 */
/* 定义CCER寄存器中使能位的掩码，用于判断输出通道是否使能 */
#define TIM_CCER_CCxE_MASK  ((uint32_t)(TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E))
/* 定义CCER寄存器中互补通道使能位的掩码，用于判断互补输出通道是否使能 */
#define TIM_CCER_CCxNE_MASK ((uint32_t)(TIM_CCER_CC1NE | TIM_CCER_CC2NE | TIM_CCER_CC3NE))
/**
  * @}
  */
/* 私有常量结束 --------------------------------------------------*/

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup TIM_Private_Macros TIM 私有宏
  * @{
  */
/* 检查清除输入源是否有效 */
#define IS_TIM_CLEARINPUT_SOURCE(__MODE__)  (((__MODE__) == TIM_CLEARINPUTSOURCE_NONE)      || \
                                             ((__MODE__) == TIM_CLEARINPUTSOURCE_ETR))

/* 检查DMA基地址是否有效 */
#define IS_TIM_DMA_BASE(__BASE__) (((__BASE__) == TIM_DMABASE_CR1)   || \
                                   ((__BASE__) == TIM_DMABASE_CR2)   || \
                                   ((__BASE__) == TIM_DMABASE_SMCR)  || \
                                   ((__BASE__) == TIM_DMABASE_DIER)  || \
                                   ((__BASE__) == TIM_DMABASE_SR)    || \
                                   ((__BASE__) == TIM_DMABASE_EGR)   || \
                                   ((__BASE__) == TIM_DMABASE_CCMR1) || \
                                   ((__BASE__) == TIM_DMABASE_CCMR2) || \
                                   ((__BASE__) == TIM_DMABASE_CCER)  || \
                                   ((__BASE__) == TIM_DMABASE_CNT)   || \
                                   ((__BASE__) == TIM_DMABASE_PSC)   || \
                                   ((__BASE__) == TIM_DMABASE_ARR)   || \
                                   ((__BASE__) == TIM_DMABASE_RCR)   || \
                                   ((__BASE__) == TIM_DMABASE_CCR1)  || \
                                   ((__BASE__) == TIM_DMABASE_CCR2)  || \
                                   ((__BASE__) == TIM_DMABASE_CCR3)  || \
                                   ((__BASE__) == TIM_DMABASE_CCR4)  || \
                                   ((__BASE__) == TIM_DMABASE_BDTR))

/* 检查事件源是否有效，确保高24位为0且低8位不全为0 */
#define IS_TIM_EVENT_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFFFF00U) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))

/* 检查计数器模式是否有效 */
#define IS_TIM_COUNTER_MODE(__MODE__)      (((__MODE__) == TIM_COUNTERMODE_UP)              || \
                                            ((__MODE__) == TIM_COUNTERMODE_DOWN)            || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED1)  || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED2)  || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED3))

/* 检查时钟分频是否有效 */
#define IS_TIM_CLOCKDIVISION_DIV(__DIV__)  (((__DIV__) == TIM_CLOCKDIVISION_DIV1) || \
                                            ((__DIV__) == TIM_CLOCKDIVISION_DIV2) || \
                                            ((__DIV__) == TIM_CLOCKDIVISION_DIV4))

/* 检查自动重装载预装载是否有效 */
#define IS_TIM_AUTORELOAD_PRELOAD(PRELOAD) (((PRELOAD) == TIM_AUTORELOAD_PRELOAD_DISABLE) || \
                                            ((PRELOAD) == TIM_AUTORELOAD_PRELOAD_ENABLE))

/* 检查快速模式状态是否有效 */
#define IS_TIM_FAST_STATE(__STATE__)       (((__STATE__) == TIM_OCFAST_DISABLE) || \
                                            ((__STATE__) == TIM_OCFAST_ENABLE))

/* 检查输出比较极性是否有效 */
#define IS_TIM_OC_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_OCPOLARITY_HIGH) || \
                                            ((__POLARITY__) == TIM_OCPOLARITY_LOW))

/* 检查互补输出比较极性是否有效 */
#define IS_TIM_OCN_POLARITY(__POLARITY__)  (((__POLARITY__) == TIM_OCNPOLARITY_HIGH) || \
                                            ((__POLARITY__) == TIM_OCNPOLARITY_LOW))

/* 检查输出比较空闲状态是否有效 */
#define IS_TIM_OCIDLE_STATE(__STATE__)     (((__STATE__) == TIM_OCIDLESTATE_SET) || \
                                            ((__STATE__) == TIM_OCIDLESTATE_RESET))

/* 检查互补输出比较空闲状态是否有效 */
#define IS_TIM_OCNIDLE_STATE(__STATE__)    (((__STATE__) == TIM_OCNIDLESTATE_SET) || \
                                            ((__STATE__) == TIM_OCNIDLESTATE_RESET))

/* 检查编码器输入极性是否有效 */
#define IS_TIM_ENCODERINPUT_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_ENCODERINPUTPOLARITY_RISING)   || \
                                                      ((__POLARITY__) == TIM_ENCODERINPUTPOLARITY_FALLING))

/* 检查输入捕获极性是否有效 */
#define IS_TIM_IC_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_ICPOLARITY_RISING)   || \
                                            ((__POLARITY__) == TIM_ICPOLARITY_FALLING)  || \
                                            ((__POLARITY__) == TIM_ICPOLARITY_BOTHEDGE))

/* 检查输入捕获选择是否有效 */
#define IS_TIM_IC_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_ICSELECTION_DIRECTTI) || \
                                            ((__SELECTION__) == TIM_ICSELECTION_INDIRECTTI) || \
                                            ((__SELECTION__) == TIM_ICSELECTION_TRC))

/* 检查输入捕获预分频是否有效 */
#define IS_TIM_IC_PRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_ICPSC_DIV1) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV2) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV4) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV8))

/* 检查单脉冲模式是否有效 */
#define IS_TIM_OPM_MODE(__MODE__)          (((__MODE__) == TIM_OPMODE_SINGLE) || \
                                            ((__MODE__) == TIM_OPMODE_REPETITIVE))

/* 检查编码器模式是否有效 */
#define IS_TIM_ENCODER_MODE(__MODE__)      (((__MODE__) == TIM_ENCODERMODE_TI1) || \
                                            ((__MODE__) == TIM_ENCODERMODE_TI2) || \
                                            ((__MODE__) == TIM_ENCODERMODE_TI12))

/* 检查DMA源是否有效 */
#define IS_TIM_DMA_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFF80FFU) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))

/* 检查通道是否有效 */
#define IS_TIM_CHANNELS(__CHANNEL__)       (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_2) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_3) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_4) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_ALL))

/* 检查单脉冲模式通道是否有效 */
#define IS_TIM_OPM_CHANNELS(__CHANNEL__)   (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_2))

/* 检查周期值是否有效 */
#define IS_TIM_PERIOD(__PERIOD__)      (((__PERIOD__) > 0U) && ((__PERIOD__) <= 0xFFFFU))

/* 检查互补通道是否有效 */
#define IS_TIM_COMPLEMENTARY_CHANNELS(__CHANNEL__) (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                                    ((__CHANNEL__) == TIM_CHANNEL_2) || \
                                                    ((__CHANNEL__) == TIM_CHANNEL_3))
/* 检查定时器时钟源参数是否有效 */
#define IS_TIM_CLOCKSOURCE(__CLOCK__) (((__CLOCK__) == TIM_CLOCKSOURCE_INTERNAL) || /* 内部时钟源 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ETRMODE1) || /* 外部时钟模式1 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ETRMODE2) || /* 外部时钟模式2 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI1ED)    || /* TI1外部时钟输入 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI1)      || /* 滤波后的定时器输入1 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI2)      || /* 滤波后的定时器输入2 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR0)     || /* 内部触发0 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR1)     || /* 内部触发1 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR2)     || /* 内部触发2 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR3))     /* 内部触发3 */

/* 检查时钟极性参数是否有效 */
#define IS_TIM_CLOCKPOLARITY(__POLARITY__) (((__POLARITY__) == TIM_CLOCKPOLARITY_INVERTED)    || /* 反相 */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_NONINVERTED) || /* 不反相 */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_RISING)      || /* 上升沿 */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_FALLING)     || /* 下降沿 */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_BOTHEDGE))     /* 双沿 */

/* 检查时钟预分频参数是否有效 */
#define IS_TIM_CLOCKPRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV1) || /* 不分频 */ \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV2) || /* 2分频 */ \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV4) || /* 4分频 */ \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV8))  /* 8分频 */

/* 检查时钟滤波参数是否有效 (0-15) */
#define IS_TIM_CLOCKFILTER(__ICFILTER__)      ((__ICFILTER__) <= 0xFU)

/* 检查清除输入极性参数是否有效 */
#define IS_TIM_CLEARINPUT_POLARITY(__POLARITY__) (((__POLARITY__) == TIM_CLEARINPUTPOLARITY_INVERTED) || /* 反相 */ \
                                                  ((__POLARITY__) == TIM_CLEARINPUTPOLARITY_NONINVERTED)) /* 不反相 */

/* 检查清除输入预分频参数是否有效 */
#define IS_TIM_CLEARINPUT_PRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV1) || /* 不分频 */ \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV2) || /* 2分频 */ \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV4) || /* 4分频 */ \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV8))  /* 8分频 */

/* 检查清除输入滤波参数是否有效 (0-15) */
#define IS_TIM_CLEARINPUT_FILTER(__ICFILTER__) ((__ICFILTER__) <= 0xFU)

/* 检查运行模式下的关闭状态配置 是否有效 */
#define IS_TIM_OSSR_STATE(__STATE__)       (((__STATE__) == TIM_OSSR_ENABLE) || /* 使能 */ \
                                            ((__STATE__) == TIM_OSSR_DISABLE)) /* 禁止 */

/* 检查空闲模式下的关闭状态配置 是否有效 */
#define IS_TIM_OSSI_STATE(__STATE__)       (((__STATE__) == TIM_OSSI_ENABLE) || /* 使能 */ \
                                            ((__STATE__) == TIM_OSSI_DISABLE)) /* 禁止 */

/* 检查锁定级别参数是否有效 */
#define IS_TIM_LOCK_LEVEL(__LEVEL__)       (((__LEVEL__) == TIM_LOCKLEVEL_OFF) || /* 不锁定 */ \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_1)   || /* 锁定级别1 */ \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_2)   || /* 锁定级别2 */ \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_3))     /* 锁定级别3 */

/* 检查刹车滤波参数是否有效 (0-15) */
#define IS_TIM_BREAK_FILTER(__BRKFILTER__) ((__BRKFILTER__) <= 0xFUL)

/* 检查刹车功能使能状态是否有效 */
#define IS_TIM_BREAK_STATE(__STATE__)      (((__STATE__) == TIM_BREAK_ENABLE) || /* 使能刹车 */ \
                                            ((__STATE__) == TIM_BREAK_DISABLE)) /* 禁止刹车 */

/* 检查刹车极性参数是否有效 */
#define IS_TIM_BREAK_POLARITY(__POLARITY__) (((__POLARITY__) == TIM_BREAKPOLARITY_LOW) || /* 低电平有效 */ \
                                             ((__POLARITY__) == TIM_BREAKPOLARITY_HIGH)) /* 高电平有效 */

/* 检查自动输出使能状态是否有效 */
#define IS_TIM_AUTOMATIC_OUTPUT_STATE(__STATE__) (((__STATE__) == TIM_AUTOMATICOUTPUT_ENABLE) || /* 使能 */ \
                                                  ((__STATE__) == TIM_AUTOMATICOUTPUT_DISABLE)) /* 禁止 */

/* 检查触发输出(TRGO)源参数是否有效 */
#define IS_TIM_TRGO_SOURCE(__SOURCE__) (((__SOURCE__) == TIM_TRGO_RESET)  || /* 复位 */ \
                                        ((__SOURCE__) == TIM_TRGO_ENABLE) || /* 使能 */ \
                                        ((__SOURCE__) == TIM_TRGO_UPDATE) || /* 更新事件 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC1)    || /* 捕获比较1 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC1REF) || /* OC1REF */ \
                                        ((__SOURCE__) == TIM_TRGO_OC2REF) || /* OC2REF */ \
                                        ((__SOURCE__) == TIM_TRGO_OC3REF) || /* OC3REF */ \
                                        ((__SOURCE__) == TIM_TRGO_OC4REF))   /* OC4REF */

/* 检查主从模式参数是否有效 */
#define IS_TIM_MSM_STATE(__STATE__)      (((__STATE__) == TIM_MASTERSLAVEMODE_ENABLE) || /* 使能主从模式 */ \
                                          ((__STATE__) == TIM_MASTERSLAVEMODE_DISABLE)) /* 禁止主从模式 */

/* 检查从模式参数是否有效 */
#define IS_TIM_SLAVE_MODE(__MODE__) (((__MODE__) == TIM_SLAVEMODE_DISABLE)   || /* 禁止从模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_RESET)     || /* 复位模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_GATED)     || /* 门控模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_TRIGGER)   || /* 触发模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_EXTERNAL1))  /* 外部时钟模式1 */

/* 检查PWM模式参数是否有效 */
#define IS_TIM_PWM_MODE(__MODE__) (((__MODE__) == TIM_OCMODE_PWM1)               || /* PWM模式1 */ \
                                   ((__MODE__) == TIM_OCMODE_PWM2))               /* PWM模式2 */

/* 检查输出比较模式参数是否有效 */
#define IS_TIM_OC_MODE(__MODE__)  (((__MODE__) == TIM_OCMODE_TIMING)             || /* 输出比较时间模式 (输出引脚不变) */ \
                                   ((__MODE__) == TIM_OCMODE_ACTIVE)             || /* 输出比较主动模式 (匹配时输出高) */ \
                                   ((__MODE__) == TIM_OCMODE_INACTIVE)           || /* 输出比较非主动模式 (匹配时输出低) */ \
                                   ((__MODE__) == TIM_OCMODE_TOGGLE)             || /* 输出比较翻转模式 */ \
                                   ((__MODE__) == TIM_OCMODE_FORCED_ACTIVE)      || /* 强制输出高 */ \
                                   ((__MODE__) == TIM_OCMODE_FORCED_INACTIVE))     /* 强制输出低 */

/* 检查触发选择参数是否有效 */
#define IS_TIM_TRIGGER_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_TS_ITR0)    || /* 内部触发0 */ \
                                                 ((__SELECTION__) == TIM_TS_ITR1)    || /* 内部触发1 */ \
                                                 ((__SELECTION__) == TIM_TS_ITR2)    || /* 内部触发2 */ \
                                                 ((__SELECTION__) == TIM_TS_ITR3)    || /* 内部触发3 */ \
                                                 ((__SELECTION__) == TIM_TS_TI1F_ED) || /* TI1边沿检测 */ \
                                                 ((__SELECTION__) == TIM_TS_TI1FP1)  || /* 滤波后的定时器输入1 */ \
                                                 ((__SELECTION__) == TIM_TS_TI2FP2)  || /* 滤波后的定时器输入2 */ \
                                                 ((__SELECTION__) == TIM_TS_ETRF))     /* 外部触发输入 */

/* 检查内部触发事件选择参数是否有效 */
#define IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_TS_ITR0) || /* 内部触发0 */ \
                                                               ((__SELECTION__) == TIM_TS_ITR1) || /* 内部触发1 */ \
                                                               ((__SELECTION__) == TIM_TS_ITR2) || /* 内部触发2 */ \
                                                               ((__SELECTION__) == TIM_TS_ITR3) || /* 内部触发3 */ \
                                                               ((__SELECTION__) == TIM_TS_NONE))   /* 无触发 */

/* 检查触发极性参数是否有效 */
#define IS_TIM_TRIGGERPOLARITY(__POLARITY__)   (((__POLARITY__) == TIM_TRIGGERPOLARITY_INVERTED   ) || /* 反相 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_NONINVERTED) || /* 不反相 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_RISING     ) || /* 上升沿 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_FALLING    ) || /* 下降沿 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_BOTHEDGE   ))  /* 双沿 */

/* 检查触发预分频参数是否有效 */
#define IS_TIM_TRIGGERPRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV1) || /* 不分频 */ \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV2) || /* 2分频 */ \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV4) || /* 4分频 */ \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV8))  /* 8分频 */

/* 检查触发滤波参数是否有效 (0-15) */
#define IS_TIM_TRIGGERFILTER(__ICFILTER__) ((__ICFILTER__) <= 0xFU)

/* 检查TI1输入选择参数是否有效 */
#define IS_TIM_TI1SELECTION(__TI1SELECTION__)  (((__TI1SELECTION__) == TIM_TI1SELECTION_CH1) || /* 选择通道1输入 */ \
                                                ((__TI1SELECTION__) == TIM_TI1SELECTION_XORCOMBINATION)) /* 选择异或组合输入 */

/* 检查DMA传输长度参数是否有效 (1-18次传输) */
#define IS_TIM_DMA_LENGTH(__LENGTH__)      (((__LENGTH__) == TIM_DMABURSTLENGTH_1TRANSFER)   || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_2TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_3TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_4TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_5TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_6TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_7TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_8TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_9TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_10TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_11TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_12TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_13TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_14TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_15TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_16TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_17TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_18TRANSFERS))

/* 检查DMA数据长度参数是否有效 (1 - 65535) */
#define IS_TIM_DMA_DATA_LENGTH(LENGTH) (((LENGTH) >= 0x1U) && ((LENGTH) < 0x10000U))

/* 检查输入捕获滤波参数是否有效 (0-15) */
#define IS_TIM_IC_FILTER(__ICFILTER__)   ((__ICFILTER__) <= 0xFU)

/* 检查死区时间参数是否有效 (0-255) */
#define IS_TIM_DEADTIME(__DEADTIME__)    ((__DEADTIME__) <= 0xFFU)

/* 检查从模式触发是否使能 */
#define IS_TIM_SLAVEMODE_TRIGGER_ENABLED(__TRIGGER__) ((__TRIGGER__) == TIM_SLAVEMODE_TRIGGER)

/* 设置输入捕获预分频值宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道, __ICPSC__: 预分频值 */
#define TIM_SET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__, __ICPSC__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= (__ICPSC__)) : /* 通道1设置 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= ((__ICPSC__) << 8U)) : /* 通道2设置 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= (__ICPSC__)) : /* 通道3设置 */ \
   ((__HANDLE__)->Instance->CCMR2 |= ((__ICPSC__) << 8U))) /* 通道4设置 */

/* 重置输入捕获预分频值宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道 */
#define TIM_RESET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_IC1PSC) : /* 通道1复位 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_IC2PSC) : /* 通道2复位 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_IC3PSC) : /* 通道3复位 */ \
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_IC4PSC)) /* 通道4复位 */

/* 设置捕获极性宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道, __POLARITY__: 极性 */
#define TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER |= (__POLARITY__)) : /* 通道1设置 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 4U)) : /* 通道2设置 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 8U)) : /* 通道3设置 */ \
   ((__HANDLE__)->Instance->CCER |= (((__POLARITY__) << 12U)))) /* 通道4设置 */

/* 重置捕获极性宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道 */
#define TIM_RESET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP)) : /* 通道1复位 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC2P | TIM_CCER_CC2NP)) : /* 通道2复位 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC3P)) : /* 通道3复位 */ \
   ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC4P))) /* 通道4复位 */

/* 获取通道状态宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道 */
/* 返回值: 对应通道的状态 */
#define TIM_CHANNEL_STATE_GET(__HANDLE__, __CHANNEL__)\
  (((__CHANNEL__) == TIM_CHANNEL_1) ? (__HANDLE__)->ChannelState[0] : /* 获取通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (__HANDLE__)->ChannelState[1] : /* 获取通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? (__HANDLE__)->ChannelState[2] : /* 获取通道3状态 */ \
   (__HANDLE__)->ChannelState[3]) /* 获取通道4状态 */

/* 设置通道状态宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道, __CHANNEL_STATE__: 状态值 */
#define TIM_CHANNEL_STATE_SET(__HANDLE__, __CHANNEL__, __CHANNEL_STATE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->ChannelState[0] = (__CHANNEL_STATE__)) : /* 设置通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->ChannelState[1] = (__CHANNEL_STATE__)) : /* 设置通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->ChannelState[2] = (__CHANNEL_STATE__)) : /* 设置通道3状态 */ \
   ((__HANDLE__)->ChannelState[3] = (__CHANNEL_STATE__))) /* 设置通道4状态 */

/* 设置所有通道状态宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL_STATE__: 状态值 */
#define TIM_CHANNEL_STATE_SET_ALL(__HANDLE__,  __CHANNEL_STATE__) do { \
                                                                       (__HANDLE__)->ChannelState[0]  = (__CHANNEL_STATE__);   /* 设置通道1 */ \
                                                                       (__HANDLE__)->ChannelState[1]  = (__CHANNEL_STATE__);   /* 设置通道2 */ \
                                                                       (__HANDLE__)->ChannelState[2]  = (__CHANNEL_STATE__);   /* 设置通道3 */ \
                                                                       (__HANDLE__)->ChannelState[3]  = (__CHANNEL_STATE__);   /* 设置通道4 */ \
                                                                     } while(0)

/* 获取互补通道状态宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道 */
/* 返回值: 对应互补通道的状态 */
#define TIM_CHANNEL_N_STATE_GET(__HANDLE__, __CHANNEL__)\
  (((__CHANNEL__) == TIM_CHANNEL_1) ? (__HANDLE__)->ChannelNState[0] : /* 获取互补通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (__HANDLE__)->ChannelNState[1] : /* 获取互补通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? (__HANDLE__)->ChannelNState[2] : /* 获取互补通道3状态 */ \
   (__HANDLE__)->ChannelNState[3]) /* 获取互补通道4状态 */

/* 设置互补通道状态宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL__: 通道, __CHANNEL_STATE__: 状态值 */
#define TIM_CHANNEL_N_STATE_SET(__HANDLE__, __CHANNEL__, __CHANNEL_STATE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->ChannelNState[0] = (__CHANNEL_STATE__)) : /* 设置互补通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->ChannelNState[1] = (__CHANNEL_STATE__)) : /* 设置互补通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->ChannelNState[2] = (__CHANNEL_STATE__)) : /* 设置互补通道3状态 */ \
   ((__HANDLE__)->ChannelNState[3] = (__CHANNEL_STATE__))) /* 设置互补通道4状态 */

/* 设置所有互补通道状态宏定义 */
/* 参数: __HANDLE__: 定时器句柄, __CHANNEL_STATE__: 状态值 */
#define TIM_CHANNEL_N_STATE_SET_ALL(__HANDLE__,  __CHANNEL_STATE__) do { \
                                                                         (__HANDLE__)->ChannelNState[0] =  /* 设置互补通道1 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[1] =  /* 设置互补通道2 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[2] =  /* 设置互补通道3 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[3] =  /* 设置互补通道4 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                       } while(0)

/**
  * @}
  */
/* 私有宏定义结束 -----------------------------------------------------*/

/* 包含 TIM HAL 扩展模块 */
#include "stm32f1xx_hal_tim_ex.h"

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup TIM_Exported_Functions TIM 导出函数
  * @{
  */

/** @addtogroup TIM_Exported_Functions_Group1 TIM 时基功能函数
  *  @brief   时基功能函数
  * @{
  */
/* 时基功能函数 ********************************************************/
/* 初始化时基单元 */
HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
/* 反初始化时基单元 */
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim);
/* 初始化底层硬件 (MSP) */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim);
/* 反初始化底层硬件 (MSP) */
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式: 轮询方式启动定时器 */
HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim);
/* 阻塞模式: 停止定时器 */
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim);
/* 非阻塞模式: 中断方式启动定时器 */
HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim);
/* 非阻塞模式: 中断方式停止定时器 */
HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim);
/* 非阻塞模式: DMA方式启动定时器 */
HAL_StatusTypeDef HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, const uint32_t *pData, uint16_t Length);
/* 非阻塞模式: DMA方式停止定时器 */
HAL_StatusTypeDef HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group2 TIM 输出比较功能函数
  *  @brief   TIM 输出比较功能函数
  * @{
  */
/* 定时器输出比较功能函数 *********************************************/
/* 初始化输出比较模式 */
HAL_StatusTypeDef HAL_TIM_OC_Init(TIM_HandleTypeDef *htim);
/* 反初始化输出比较模式 */
HAL_StatusTypeDef HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim);
/* 初始化输出比较底层硬件 (MSP) */
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim);
/* 反初始化输出比较底层硬件 (MSP) */
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式: 轮询方式启动输出比较 */
HAL_StatusTypeDef HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 阻塞模式: 停止输出比较 */
HAL_StatusTypeDef HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式启动输出比较 */
HAL_StatusTypeDef HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式停止输出比较 */
HAL_StatusTypeDef HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: DMA方式启动输出比较 */
HAL_StatusTypeDef HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                       uint16_t Length);
/* 非阻塞模式: DMA方式停止输出比较 */
HAL_StatusTypeDef HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group3 TIM PWM功能函数
  *  @brief   TIM PWM功能函数
  * @{
  */
/* 定时器PWM功能函数 ********************************************************/
/* 初始化PWM模式 */
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
/* 反初始化PWM模式 */
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim);
/* 初始化PWM底层硬件 (MSP) */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);
/* 反初始化PWM底层硬件 (MSP) */
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式: 轮询方式启动PWM */
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 阻塞模式: 停止PWM */
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式启动PWM */
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式停止PWM */
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: DMA方式启动PWM */
HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                        uint16_t Length);
/* 非阻塞模式: DMA方式停止PWM */
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group4 TIM 输入捕获功能函数
  *  @brief   TIM 输入捕获功能函数
  * @{
  */
/* 定时器输入捕获功能函数 **********************************************/
/* 初始化输入捕获模式 */
HAL_StatusTypeDef HAL_TIM_IC_Init(TIM_HandleTypeDef *htim);
/* 反初始化输入捕获模式 */
HAL_StatusTypeDef HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim);
/* 初始化输入捕获底层硬件 (MSP) */
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim);
/* 反初始化输入捕获底层硬件 (MSP) */
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式: 轮询方式启动输入捕获 */
HAL_StatusTypeDef HAL_TIM_IC_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 阻塞模式: 停止输入捕获 */
HAL_StatusTypeDef HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式启动输入捕获 */
HAL_StatusTypeDef HAL_TIM_IC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式停止输入捕获 */
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: DMA方式启动输入捕获 */
HAL_StatusTypeDef HAL_TIM_IC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length);
/* 非阻塞模式: DMA方式停止输入捕获 */
HAL_StatusTypeDef HAL_TIM_IC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group5 TIM 单脉冲功能函数
  *  @brief   TIM 单脉冲功能函数
  * @{
  */
/* 定时器单脉冲功能函数 **************************************************/
/* 初始化单脉冲模式 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode);
/* 反初始化单脉冲模式 */
HAL_StatusTypeDef HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim);
/* 初始化单脉冲底层硬件 (MSP) */
void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim);
/* 反初始化单脉冲底层硬件 (MSP) */
void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式: 轮询方式启动单脉冲 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/* 阻塞模式: 停止单脉冲 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/* 非阻塞模式: 中断方式启动单脉冲 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/* 非阻塞模式: 中断方式停止单脉冲 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group6 TIM 编码器功能函数
  *  @brief   TIM 编码器功能函数
  * @{
  */
/* 定时器编码器功能函数 ****************************************************/
/* 初始化编码器模式 */
HAL_StatusTypeDef HAL_TIM_Encoder_Init(TIM_HandleTypeDef *htim, const TIM_Encoder_InitTypeDef *sConfig);
/* 反初始化编码器模式 */
HAL_StatusTypeDef HAL_TIM_Encoder_DeInit(TIM_HandleTypeDef *htim);
/* 初始化编码器底层硬件 (MSP) */
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim);
/* 反初始化编码器底层硬件 (MSP) */
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式: 轮询方式启动编码器 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 阻塞模式: 停止编码器 */
HAL_StatusTypeDef HAL_TIM_Encoder_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式启动编码器 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: 中断方式停止编码器 */
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式: DMA方式启动编码器 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1,
                                            uint32_t *pData2, uint16_t Length);
/* 非阻塞模式: DMA方式停止编码器 */
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group7 TIM 中断处理管理
  *  @brief   中断处理管理
  * @{
  */
/* 中断处理函数  ***********************************************/
/* 定时器中断统一处理函数 */
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group8 TIM 外设控制功能函数
  *  @brief   外设控制功能函数
  * @{
  */
/* 控制函数  *********************************************************/
/* 配置输出比较通道 */
HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                           uint32_t Channel);
/* 配置PWM通道 */
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                            uint32_t Channel);
/* 配置输入捕获通道 */
HAL_StatusTypeDef HAL_TIM_IC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_IC_InitTypeDef *sConfig,
                                           uint32_t Channel);
/* 配置单脉冲通道 */
HAL_StatusTypeDef HAL_TIM_OnePulse_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OnePulse_InitTypeDef *sConfig,
                                                 uint32_t OutputChannel,  uint32_t InputChannel);
/* 配置OCref清除功能 */
HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim,
                                           const TIM_ClearInputConfigTypeDef *sClearInputConfig,
                                           uint32_t Channel);
/* 配置时钟源 */
HAL_StatusTypeDef HAL_TIM_ConfigClockSource(TIM_HandleTypeDef *htim, const TIM_ClockConfigTypeDef *sClockSourceConfig);
/* 配置TI1输入 */
HAL_StatusTypeDef HAL_TIM_ConfigTI1Input(TIM_HandleTypeDef *htim, uint32_t TI1_Selection);
/* 配置从模式同步 */
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig);
/* 配置从模式同步 (中断方式) */
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro_IT(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig);
/* 启动DMA突发写入 */
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                              uint32_t BurstRequestSrc, const uint32_t  *BurstBuffer,
                                              uint32_t  BurstLength);
/* 启动DMA多次突发写入 */
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiWriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                   uint32_t BurstRequestSrc, const uint32_t *BurstBuffer,
                                                   uint32_t BurstLength,  uint32_t DataLength);
/* 停止DMA突发写入 */
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
/* 启动DMA突发读取 */
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                             uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength);
/* 启动DMA多次突发读取 */
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                  uint32_t BurstRequestSrc, uint32_t  *BurstBuffer,
                                                  uint32_t  BurstLength, uint32_t  DataLength);
/* 停止DMA突发读取 */
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
/* 产生事件 */
HAL_StatusTypeDef HAL_TIM_GenerateEvent(TIM_HandleTypeDef *htim, uint32_t EventSource);
/* 读取捕获值 */
uint32_t HAL_TIM_ReadCapturedValue(const TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group9 TIM 回调函数
  *  @brief   TIM 回调函数
  * @{
  */
/* 非阻塞模式下的回调函数 (中断和DMA) *******************************/
/* 周期结束回调函数 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
/* 周期结束半完成回调函数 (DMA双缓冲) */
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim);
/* 输出比较延迟结束回调函数 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
/* 输入捕获回调函数 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
/* 输入捕获半完成回调函数 (DMA双缓冲) */
void HAL_TIM_IC_CaptureHalfCpltCallback(TIM_HandleTypeDef *htim);
/* PWM脉冲结束回调函数 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
/* PWM脉冲半完成回调函数 (DMA双缓冲) */
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim);
/* 触发回调函数 */
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim);
/* 触发半完成回调函数 (DMA双缓冲) */
void HAL_TIM_TriggerHalfCpltCallback(TIM_HandleTypeDef *htim);
/* 错误回调函数 */
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/* 注册回调函数 */
HAL_StatusTypeDef HAL_TIM_RegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID,
                                           pTIM_CallbackTypeDef pCallback);
/* 注销回调函数 */
HAL_StatusTypeDef HAL_TIM_UnRegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group10 TIM 外设状态功能函数
  *  @brief  外设状态功能函数
  * @{
  */
/* 外设状态函数  ************************************************/
/* 获取时基状态 */
HAL_TIM_StateTypeDef HAL_TIM_Base_GetState(const TIM_HandleTypeDef *htim);
/* 获取输出比较状态 */
HAL_TIM_StateTypeDef HAL_TIM_OC_GetState(const TIM_HandleTypeDef *htim);
/* 获取PWM状态 */
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(const TIM_HandleTypeDef *htim);
/* 获取输入捕获状态 */
HAL_TIM_StateTypeDef HAL_TIM_IC_GetState(const TIM_HandleTypeDef *htim);
/* 获取单脉冲状态 */
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(const TIM_HandleTypeDef *htim);
/* 获取编码器状态 */
HAL_TIM_StateTypeDef HAL_TIM_Encoder_GetState(const TIM_HandleTypeDef *htim);

/* 外设通道状态函数  ************************************************/
/* 获取活动通道 */
HAL_TIM_ActiveChannel HAL_TIM_GetActiveChannel(const TIM_HandleTypeDef *htim);
/* 获取通道状态 */
HAL_TIM_ChannelStateTypeDef HAL_TIM_GetChannelState(const TIM_HandleTypeDef *htim,  uint32_t Channel);
/* 获取DMA突发状态 */
HAL_TIM_DMABurstStateTypeDef HAL_TIM_DMABurstState(const TIM_HandleTypeDef *htim);
/**
  * @}
  */

/**
  * @}
  */
/* 导出函数结束 -------------------------------------------------*/

/* 私有函数----------------------------------------------------------*/
/** @defgroup TIM_Private_Functions TIM 私有函数
  * @{
  */
/* 基础配置设置函数 */
void TIM_Base_SetConfig(TIM_TypeDef *TIMx, const TIM_Base_InitTypeDef *Structure);
/* TI1配置设置函数 */
void TIM_TI1_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter);
/* OC2配置设置函数 */
void TIM_OC2_SetConfig(TIM_TypeDef *TIMx, const TIM_OC_InitTypeDef *OC_Config);
/* ETR配置设置函数 */
void TIM_ETR_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ExtTRGPrescaler,
                       uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter);

/* DMA延迟脉冲半完成回调 */
void TIM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma);
/* DMA错误处理 */
void TIM_DMAError(DMA_HandleTypeDef *hdma);
/* DMA捕获完成回调 */
void TIM_DMACaptureCplt(DMA_HandleTypeDef *hdma);
/* DMA捕获半完成回调 */
void TIM_DMACaptureHalfCplt(DMA_HandleTypeDef *hdma);
/* 通道使能/禁止命令 */
void TIM_CCxChannelCmd(TIM_TypeDef *TIMx, uint32_t Channel, uint32_t ChannelState);

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/* 重置回调函数 */
void TIM_ResetCallback(TIM_HandleTypeDef *htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* 私有函数结束 --------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F1xx_HAL_TIM_H */
