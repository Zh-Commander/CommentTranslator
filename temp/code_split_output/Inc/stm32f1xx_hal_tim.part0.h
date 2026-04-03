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
                                   此参数可以是 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数值 */

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
  *         用于配置定时器的输出比较模式，常用于PWM输出、波形生成等
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
  *         用于配置定时器的单脉冲模式，常用于产生特定数量的脉冲
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

  uint32_t ICSelection;   /*!< 指定输入通道选择。
                              此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t ICFilter;      /*!< 指定输入捕获滤波器。
                              此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_OnePulse_InitTypeDef;

/**
  * @brief  TIM 输入捕获配置结构体定义
  *         用于配置定时器的输入捕获模式，常用于测量信号脉宽、频率等
  */
typedef struct
{
  uint32_t  ICPolarity;  /*!< 指定输入信号的有效边沿。
                              此参数可以是 @ref TIM_Input_Capture_Polarity 的值 */

  uint32_t ICSelection;  /*!< 指定输入通道选择。
                              此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t ICPrescaler;  /*!< 指定输入捕获预分频器。
                              此参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t ICFilter;     /*!< 指定输入捕获滤波器。
                              此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_IC_InitTypeDef;

/**
  * @brief  TIM 编码器配置结构体定义
  *         用于配置定时器的编码器接口模式，常用于电机测速、测方向
  */
typedef struct
{
  uint32_t EncoderMode;   /*!< 指定编码器模式。
                               此参数可以是 @ref TIM_Encoder_Mode 的值 */

  uint32_t IC1Polarity;   /*!< 指定输入通道1的有效边沿。
                               此参数可以是 @ref TIM_Encoder_Input_Polarity 的值 */

  uint32_t IC1Selection;  /*!< 指定输入通道1的选择。
                               此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t IC1Prescaler;  /*!< 指定输入捕获1的预分频器。
                               此参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t IC1Filter;     /*!< 指定输入捕获1的滤波器。
                               此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */

  uint32_t IC2Polarity;   /*!< 指定输入通道2的有效边沿。
                               此参数可以是 @ref TIM_Encoder_Input_Polarity 的值 */

  uint32_t IC2Selection;  /*!< 指定输入通道2的选择。
                              此参数可以是 @ref TIM_Input_Capture_Selection 的值 */

  uint32_t IC2Prescaler;  /*!< 指定输入捕获2的预分频器。
                               此参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t IC2Filter;     /*!< 指定输入捕获2的滤波器。
                               此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_Encoder_InitTypeDef;

/**
  * @brief  时钟配置句柄结构体定义
  *         用于配置定时器的时钟源、极性、预分频和滤波等参数
  */
typedef struct
{
  uint32_t ClockSource;     /*!< TIM 时钟源
                                 此参数可以是 @ref TIM_Clock_Source 的值 */
  uint32_t ClockPolarity;   /*!< TIM 时钟极性
                                 此参数可以是 @ref TIM_Clock_Polarity 的值 */
  uint32_t ClockPrescaler;  /*!< TIM 时钟预分频
                                 此参数可以是 @ref TIM_Clock_Prescaler 的值 */
  uint32_t ClockFilter;     /*!< TIM 时钟滤波
                                 此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_ClockConfigTypeDef;

/**
  * @brief  TIM 清除输入配置句柄结构体定义
  *         用于配置清除输入功能，常用于OCREF清除
  */
typedef struct
{
  uint32_t ClearInputState;      /*!< TIM 清除输入状态
                                      此参数可以是 ENABLE 或 DISABLE */
  uint32_t ClearInputSource;     /*!< TIM 清除输入源
                                      此参数可以是 @ref TIM_ClearInput_Source 的值 */
  uint32_t ClearInputPolarity;   /*!< TIM 清除输入极性
                                      此参数可以是 @ref TIM_ClearInput_Polarity 的值 */
  uint32_t ClearInputPrescaler;  /*!< TIM 清除输入预分频
                                      此参数必须为0：当OCRef清除功能与ETR源一起使用时，
                                      ETR预分频器必须关闭 */
  uint32_t ClearInputFilter;     /*!< TIM 清除输入滤波器
                                      此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */
} TIM_ClearInputConfigTypeDef;

/**
  * @brief  TIM 主模式配置结构体定义
  *         用于配置定时器作为主设备时的触发输出(TRGO)设置
  */
typedef struct
{
  uint32_t  MasterOutputTrigger;   /*!< 触发输出(TRGO)选择
                                        此参数可以是 @ref TIM_Master_Mode_Selection 的值 */
  uint32_t  MasterSlaveMode;       /*!< 主/从模式选择
                                        此参数可以是 @ref TIM_Master_Slave_Mode 的值
                                        @note 当主/从模式使能时，触发输入(TRGI)上的事件效果会被延迟，
                                        以允许当前定时器与其从定时器(通过TRGO)之间实现完美的同步。
                                        在定时器同步模式下这不是强制性的。 */
} TIM_MasterConfigTypeDef;

/**
  * @brief  TIM 从模式配置结构体定义
  *         用于配置定时器作为从设备时的模式、触发源等
  */
typedef struct
{
  uint32_t  SlaveMode;         /*!< 从模式选择
                                    此参数可以是 @ref TIM_Slave_Mode 的值 */
  uint32_t  InputTrigger;      /*!< 输入触发源
                                    此参数可以是 @ref TIM_Trigger_Selection 的值 */
  uint32_t  TriggerPolarity;   /*!< 输入触发极性
                                    此参数可以是 @ref TIM_Trigger_Polarity 的值 */
  uint32_t  TriggerPrescaler;  /*!< 输入触发预分频
                                    此参数可以是 @ref TIM_Trigger_Prescaler 的值 */
  uint32_t  TriggerFilter;     /*!< 输入触发滤波器
                                    此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值  */

} TIM_SlaveConfigTypeDef;

/**
  * @brief  TIM 断路输入和死区配置结构体定义
  * @note   可以配置2个断路输入(BKIN和BKIN2)，具有可配置的滤波器和极性。
  */
typedef struct
{
  uint32_t OffStateRunMode;      /*!< 运行模式下的TIM关闭状态选择，此参数可以是 @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state 的值 */

  uint32_t OffStateIDLEMode;     /*!< 空闲模式下的TIM关闭状态选择，此参数可以是 @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state 的值 */

  uint32_t LockLevel;            /*!< TIM 锁定级别，此参数可以是 @ref TIM_Lock_level 的值 */

  uint32_t DeadTime;             /*!< TIM 死区时间，此参数可以是 Min_Data = 0x00 和 Max_Data = 0xFF 之间的数值 */

  uint32_t BreakState;           /*!< TIM 断路状态，此参数可以是 @ref TIM_Break_Input_enable_disable 的值 */

  uint32_t BreakPolarity;        /*!< TIM 断路输入极性，此参数可以是 @ref TIM_Break_Polarity 的值 */

  uint32_t BreakFilter;          /*!< 指定断路输入滤波器。此参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数值 */

  uint32_t AutomaticOutput;      /*!< TIM 自动输出使能状态，此参数可以是 @ref TIM_AOE_Bit_Set_Reset 的值 */

} TIM_BreakDeadTimeConfigTypeDef;

/**
  * @brief  HAL 状态结构体定义
  *         用于表示定时器外设的当前工作状态
  */
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /*!< 外设尚未初始化或已禁用 */
  HAL_TIM_STATE_READY             = 0x01U,    /*!< 外设已初始化并准备使用 */
  HAL_TIM_STATE_BUSY              = 0x02U,    /*!< 正在进行内部处理 */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /*!< 超时状态 */
  HAL_TIM_STATE_ERROR             = 0x04U     /*!< 错误状态 */
} HAL_TIM_StateTypeDef;

/**
  * @brief  TIM 通道状态定义
  *         用于表示定时器通道的当前工作状态
  */
typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM 通道初始状态 */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM 通道准备就绪 */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< TIM 通道正在进行内部处理 */
} HAL_TIM_ChannelStateTypeDef;

/**
  * @brief  DMA 突发状态定义
  *         用于表示DMA突发传输的状态
  */
typedef enum
{
  HAL_DMA_BURST_STATE_RESET             = 0x00U,    /*!< DMA 突发初始状态 */
  HAL_DMA_BURST_STATE_READY             = 0x01U,    /*!< DMA 突发准备就绪 */
  HAL_DMA_BURST_STATE_BUSY              = 0x02U,    /*!< 正在进行 DMA 突发传输 */
} HAL_TIM_DMABurstStateTypeDef;

/**
  * @brief  HAL 活动通道结构体定义
  *         用于标识当前正在操作的定时器通道
  */
typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< 活动通道为通道1 */
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< 活动通道为通道2 */
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< 活动通道为通道3 */
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< 活动通道为通道4 */
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< 所有活动通道已清除 */
} HAL_TIM_ActiveChannel;

/**
  * @brief  TIM 时基句柄结构体定义
  *         这是TIM外设的主要句柄结构体，包含了操作定时器所需的所有信息
  */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
typedef struct __TIM_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
{
  TIM_TypeDef                        *Instance;         /*!< 寄存器基地址指针 */
  TIM_Base_InitTypeDef               Init;              /*!< TIM 时基初始化配置参数 */
  HAL_TIM_ActiveChannel              Channel;           /*!< 当前活动通道 */
  DMA_HandleTypeDef                  *hdma[7];          /*!< DMA 句柄数组
                                                             此数组通过 @ref DMA_Handle_index 访问 */
  HAL_LockTypeDef                    Lock;              /*!< 锁定对象，用于资源保护 */
  __IO HAL_TIM_StateTypeDef          State;             /*!< TIM 操作状态 */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelState[4];   /*!< TIM 通道操作状态 */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /*!< TIM 互补通道操作状态 */
  __IO HAL_TIM_DMABurstStateTypeDef  DMABurstState;     /*!< DMA 突发操作状态 */
