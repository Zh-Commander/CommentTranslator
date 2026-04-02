/**
  ******************************************************************************
  * @file    stm32f1xx_hal_tim.h
  * @author  MCD Application Team
  * @brief   Header file of TIM HAL module.
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
#ifndef STM32F1xx_HAL_TIM_H
#define STM32F1xx_HAL_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含文件
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup TIM
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup TIM_Exported_Types TIM Exported Types
  * @{
  */

/**
  * @brief  TIM Time base Configuration Structure definition
  * @brief  TIM 时基配置结构体定义
  */
typedef struct
{
  uint32_t Prescaler;         /*!< Specifies the prescaler value used to divide the TIM clock.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
                                   /*!< 指定用于对 TIM 时钟进行分频的预分频器值。
                                        此参数可以是 0x0000 到 0xFFFF 之间的数值 */

  uint32_t CounterMode;       /*!< Specifies the counter mode.
                                   This parameter can be a value of @ref TIM_Counter_Mode */
                                   /*!< 指定计数器模式。
                                        此参数可以是 @ref TIM_Counter_Mode 中的一个值 */

  uint32_t Period;            /*!< Specifies the period value to be loaded into the active
                                   Auto-Reload Register at the next update event.
                                   This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF.  */
                                   /*!< 指定在下一个更新事件时加载到活动自动重载寄存器 (ARR) 的周期值。
                                        此参数可以是 0x0000 到 0xFFFF 之间的数值 */

  uint32_t ClockDivision;     /*!< Specifies the clock division.
                                   This parameter can be a value of @ref TIM_ClockDivision */
                                   /*!< 指定时钟分割。
                                        此参数可以是 @ref TIM_ClockDivision 中的一个值 */

  uint32_t RepetitionCounter;  /*!< Specifies the repetition counter value. Each time the RCR downcounter
                                    reaches zero, an update event is generated and counting restarts
                                    from the RCR value (N).
                                    This means in PWM mode that (N+1) corresponds to:
                                        - the number of PWM periods in edge-aligned mode
                                        - the number of half PWM period in center-aligned mode
                                     GP timers: this parameter must be a number between Min_Data = 0x00 and
                                     Max_Data = 0xFF.
                                     Advanced timers: this parameter must be a number between Min_Data = 0x0000 and
                                     Max_Data = 0xFFFF. */
                                    /*!< 指定重复计数器值。每次 RCR 递减计数器达到零时，
                                         会生成更新事件并从 RCR 值 (N) 重新开始计数。
                                         这意味着在 PWM 模式下 (N+1) 对应于：
                                            - 边沿对齐模式下的 PWM 周期数
                                            - 中心对齐模式下的半个 PWM 周期数
                                         通用定时器：此参数必须是 0x00 到 0xFF 之间的数值。
                                         高级定时器：此参数必须是 0x0000 到 0xFFFF 之间的数值。 */

  uint32_t AutoReloadPreload;  /*!< Specifies the auto-reload preload.
                                   This parameter can be a value of @ref TIM_AutoReloadPreload */
                                   /*!< 指定自动重载预装载值。
                                        此参数可以是 @ref TIM_AutoReloadPreload 中的一个值 */
} TIM_Base_InitTypeDef;

/**
  * @brief  TIM Output Compare Configuration Structure definition
  * @brief  TIM 输出比较配置结构体定义
  */
typedef struct
{
  uint32_t OCMode;        /*!< Specifies the TIM mode.
                               This parameter can be a value of @ref TIM_Output_Compare_and_PWM_modes */
                               /*!< 指定 TIM 模式。
                                    此参数可以是 @ref TIM_Output_Compare_and_PWM_modes 中的一个值 */

  uint32_t Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register.
                               This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
                               /*!< 指定要加载到捕获比较寄存器 (CCR) 的脉冲值。
                                    此参数可以是 0x0000 到 0xFFFF 之间的数值 */

  uint32_t OCPolarity;    /*!< Specifies the output polarity.
                               This parameter can be a value of @ref TIM_Output_Compare_Polarity */
                               /*!< 指定输出极性。
                                    此参数可以是 @ref TIM_Output_Compare_Polarity 中的一个值 */

  uint32_t OCNPolarity;   /*!< Specifies the complementary output polarity.
                               This parameter can be a value of @ref TIM_Output_Compare_N_Polarity
                               @note This parameter is valid only for timer instances supporting break feature. */
                               /*!< 指定互补输出极性。
                                    此参数可以是 @ref TIM_Output_Compare_N_Polarity 中的一个值
                                    @note 此参数仅对支持刹车功能的定时器实例有效 */

  uint32_t OCFastMode;    /*!< Specifies the Fast mode state.
                               This parameter can be a value of @ref TIM_Output_Fast_State
                               @note This parameter is valid only in PWM1 and PWM2 mode. */
                               /*!< 指定快速模式状态。
                                    此参数可以是 @ref TIM_Output_Fast_State 中的一个值
                                    @note 此参数仅在 PWM1 和 PWM2 模式下有效 */


  uint32_t OCIdleState;   /*!< Specifies the TIM Output Compare pin state during Idle state.
                               This parameter can be a value of @ref TIM_Output_Compare_Idle_State
                               @note This parameter is valid only for timer instances supporting break feature. */
                               /*!< 指定空闲状态期间的 TIM 输出比较引脚状态。
                                    此参数可以是 @ref TIM_Output_Compare_Idle_State 中的一个值
                                    @note 此参数仅对支持刹车功能的定时器实例有效 */

  uint32_t OCNIdleState;  /*!< Specifies the TIM Output Compare pin state during Idle state.
                               This parameter can be a value of @ref TIM_Output_Compare_N_Idle_State
                               @note This parameter is valid only for timer instances supporting break feature. */
                               /*!< 指定空闲状态期间的 TIM 输出比较引脚状态。
                                    此参数可以是 @ref TIM_Output_Compare_N_Idle_State 中的一个值
                                    @note 此参数仅对支持刹车功能的定时器实例有效 */
} TIM_OC_InitTypeDef;

/**
  * @brief  TIM One Pulse Mode Configuration Structure definition
  * @brief  TIM 单脉冲模式配置结构体定义
  */
typedef struct
{
  uint32_t OCMode;        /*!< Specifies the TIM mode.
                               This parameter can be a value of @ref TIM_Output_Compare_and_PWM_modes */
                               /*!< 指定 TIM 模式。
                                    此参数可以是 @ref TIM_Output_Compare_and_PWM_modes 中的一个值 */

  uint32_t Pulse;         /*!< Specifies the pulse value to be loaded into the Capture Compare Register.
                               This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
                               /*!< 指定要加载到捕获比较寄存器 (CCR) 的脉冲值。
                                    此参数可以是 0x0000 到 0xFFFF 之间的数值 */

  uint32_t OCPolarity;    /*!< Specifies the output polarity.
                               This parameter can be a value of @ref TIM_Output_Compare_Polarity */
                               /*!< 指定输出极性。
                                    此参数可以是 @ref TIM_Output_Compare_Polarity 中的一个值 */

  uint32_t OCNPolarity;   /*!< Specifies the complementary output polarity.
                               This parameter can be a value of @ref TIM_Output_Compare_N_Polarity
                               @note This parameter is valid only for timer instances supporting break feature. */
                               /*!< 指定互补输出极性。
                                    此参数可以是 @ref TIM_Output_Compare_N_Polarity 中的一个值
                                    @note 此参数仅对支持刹车功能的定时器实例有效 */

  uint32_t OCIdleState;   /*!< Specifies the TIM Output Compare pin state during Idle state.
                               This parameter can be a value of @ref TIM_Output_Compare_Idle_State
                               @note This parameter is valid only for timer instances supporting break feature. */
                               /*!< 指定空闲状态期间的 TIM 输出比较引脚状态。
                                    此参数可以是 @ref TIM_Output_Compare_Idle_State 中的一个值
                                    @note 此参数仅对支持刹车功能的定时器实例有效 */

  uint32_t OCNIdleState;  /*!< Specifies the TIM Output Compare pin state during Idle state.
                               This parameter can be a value of @ref TIM_Output_Compare_N_Idle_State
                               @note This parameter is valid only for timer instances supporting break feature. */
                               /*!< 指定空闲状态期间的 TIM 输出比较引脚状态。
                                    此参数可以是 @ref TIM_Output_Compare_N_Idle_State 中的一个值
                                    @note 此参数仅对支持刹车功能的定时器实例有效 */

  uint32_t ICPolarity;    /*!< Specifies the active edge of the input signal.
                               This parameter can be a value of @ref TIM_Input_Capture_Polarity */
                               /*!< 指定输入信号的有效边沿。
                                    此参数可以是 @ref TIM_Input_Capture_Polarity 中的一个值 */

  uint32_t ICSelection;   /*!< Specifies the input.
                              This parameter can be a value of @ref TIM_Input_Capture_Selection */
                              /*!< 指定输入通道。
                                   此参数可以是 @ref TIM_Input_Capture_Selection 中的一个值 */

  uint32_t ICFilter;      /*!< Specifies the input capture filter.
                              This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                              /*!< 指定输入捕获滤波器。
                                   此参数可以是 0x0 到 0xF 之间的数值 */
} TIM_OnePulse_InitTypeDef;

/**
  * @brief  TIM Input Capture Configuration Structure definition
  * @brief  TIM 输入捕获配置结构体定义
  */
typedef struct
{
  uint32_t  ICPolarity;  /*!< Specifies the active edge of the input signal.
                              This parameter can be a value of @ref TIM_Input_Capture_Polarity */
                              /*!< 指定输入信号的有效边沿。
                                   此参数可以是 @ref TIM_Input_Capture_Polarity 中的一个值 */

  uint32_t ICSelection;  /*!< Specifies the input.
                              This parameter can be a value of @ref TIM_Input_Capture_Selection */
                              /*!< 指定输入通道。
                                   此参数可以是 @ref TIM_Input_Capture_Selection 中的一个值 */

  uint32_t ICPrescaler;  /*!< Specifies the Input Capture Prescaler.
                              This parameter can be a value of @ref TIM_Input_Capture_Prescaler */
                              /*!< 指定输入捕获预分频器。
                                   此参数可以是 @ref TIM_Input_Capture_Prescaler 中的一个值 */

  uint32_t ICFilter;     /*!< Specifies the input capture filter.
                              This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                              /*!< 指定输入捕获滤波器。
                                   此参数可以是 0x0 到 0xF 之间的数值 */
} TIM_IC_InitTypeDef;

/**
  * @brief  TIM Encoder Configuration Structure definition
  * @brief  TIM 编码器配置结构体定义
  */
typedef struct
{
  uint32_t EncoderMode;   /*!< Specifies the active edge of the input signal.
                               This parameter can be a value of @ref TIM_Encoder_Mode */
                               /*!< 指定编码器模式。
                                    此参数可以是 @ref TIM_Encoder_Mode 中的一个值 */

  uint32_t IC1Polarity;   /*!< Specifies the active edge of the input signal.
                               This parameter can be a value of @ref TIM_Encoder_Input_Polarity */
                               /*!< 指定输入信号的有效边沿 (通道1)。
                                    此参数可以是 @ref TIM_Encoder_Input_Polarity 中的一个值 */

  uint32_t IC1Selection;  /*!< Specifies the input.
                               This parameter can be a value of @ref TIM_Input_Capture_Selection */
                               /*!< 指定输入通道 (通道1)。
                                    此参数可以是 @ref TIM_Input_Capture_Selection 中的一个值 */

  uint32_t IC1Prescaler;  /*!< Specifies the Input Capture Prescaler.
                               This parameter can be a value of @ref TIM_Input_Capture_Prescaler */
                               /*!< 指定输入捕获预分频器 (通道1)。
                                    此参数可以是 @ref TIM_Input_Capture_Prescaler 中的一个值 */

  uint32_t IC1Filter;     /*!< Specifies the input capture filter.
                               This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                               /*!< 指定输入捕获滤波器 (通道1)。
                                    此参数可以是 0x0 到 0xF 之间的数值 */

  uint32_t IC2Polarity;   /*!< Specifies the active edge of the input signal.
                               This parameter can be a value of @ref TIM_Encoder_Input_Polarity */
                               /*!< 指定输入信号的有效边沿 (通道2)。
                                    此参数可以是 @ref TIM_Encoder_Input_Polarity 中的一个值 */

  uint32_t IC2Selection;  /*!< Specifies the input.
                              This parameter can be a value of @ref TIM_Input_Capture_Selection */
                              /*!< 指定输入通道 (通道2)。
                                   此参数可以是 @ref TIM_Input_Capture_Selection 中的一个值 */

  uint32_t IC2Prescaler;  /*!< Specifies the Input Capture Prescaler.
                               This parameter can be a value of @ref TIM_Input_Capture_Prescaler */
                               /*!< 指定输入捕获预分频器 (通道2)。
                                    此参数可以是 @ref TIM_Input_Capture_Prescaler 中的一个值 */

  uint32_t IC2Filter;     /*!< Specifies the input capture filter.
                               This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                               /*!< 指定输入捕获滤波器 (通道2)。
                                    此参数可以是 0x0 到 0xF 之间的数值 */
} TIM_Encoder_InitTypeDef;

/**
  * @brief  Clock Configuration Handle Structure definition
  * @brief  时钟配置句柄结构体定义
  */
typedef struct
{
  uint32_t ClockSource;     /*!< TIM clock sources
                                 This parameter can be a value of @ref TIM_Clock_Source */
                                 /*!< TIM 时钟源。
                                      此参数可以是 @ref TIM_Clock_Source 中的一个值 */
  uint32_t ClockPolarity;   /*!< TIM clock polarity
                                 This parameter can be a value of @ref TIM_Clock_Polarity */
                                 /*!< TIM 时钟极性。
                                      此参数可以是 @ref TIM_Clock_Polarity 中的一个值 */
  uint32_t ClockPrescaler;  /*!< TIM clock prescaler
                                 This parameter can be a value of @ref TIM_Clock_Prescaler */
                                 /*!< TIM 时钟预分频器。
                                      此参数可以是 @ref TIM_Clock_Prescaler 中的一个值 */
  uint32_t ClockFilter;     /*!< TIM clock filter
                                 This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                                 /*!< TIM 时钟滤波器。
                                      此参数可以是 0x0 到 0xF 之间的数值 */
} TIM_ClockConfigTypeDef;

/**
  * @brief  TIM Clear Input Configuration Handle Structure definition
  * @brief  TIM 清除输入配置句柄结构体定义
  */
typedef struct
{
  uint32_t ClearInputState;      /*!< TIM clear Input state
                                      This parameter can be ENABLE or DISABLE */
                                      /*!< TIM 清除输入状态。
                                           此参数可以是 ENABLE 或 DISABLE */
  uint32_t ClearInputSource;     /*!< TIM clear Input sources
                                      This parameter can be a value of @ref TIM_ClearInput_Source */
                                      /*!< TIM 清除输入源。
                                           此参数可以是 @ref TIM_ClearInput_Source 中的一个值 */
  uint32_t ClearInputPolarity;   /*!< TIM Clear Input polarity
                                      This parameter can be a value of @ref TIM_ClearInput_Polarity */
                                      /*!< TIM 清除输入极性。
                                           此参数可以是 @ref TIM_ClearInput_Polarity 中的一个值 */
  uint32_t ClearInputPrescaler;  /*!< TIM Clear Input prescaler
                                      This parameter must be 0: When OCRef clear feature is used with ETR source,
                                      ETR prescaler must be off */
                                      /*!< TIM 清除输入预分频器。
                                           此参数必须为 0：当 OCRef 清除功能与 ETR 源一起使用时，
                                           ETR 预分频器必须关闭 */
  uint32_t ClearInputFilter;     /*!< TIM Clear Input filter
                                      This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                                      /*!< TIM 清除输入滤波器。
                                           此参数可以是 0x0 到 0xF 之间的数值 */
} TIM_ClearInputConfigTypeDef;

/**
  * @brief  TIM Master configuration Structure definition
  * @brief  TIM 主模式配置结构体定义
  */
typedef struct
{
  uint32_t  MasterOutputTrigger;   /*!< Trigger output (TRGO) selection
                                        This parameter can be a value of @ref TIM_Master_Mode_Selection */
                                        /*!< 触发输出 (TRGO) 选择。
                                             此参数可以是 @ref TIM_Master_Mode_Selection 中的一个值 */
  uint32_t  MasterSlaveMode;       /*!< Master/slave mode selection
                                        This parameter can be a value of @ref TIM_Master_Slave_Mode
                                        @note When the Master/slave mode is enabled, the effect of
                                        an event on the trigger input (TRGI) is delayed to allow a
                                        perfect synchronization between the current timer and its
                                        slaves (through TRGO). It is not mandatory in case of timer
                                        synchronization mode. */
                                        /*!< 主/从模式选择。
                                             此参数可以是 @ref TIM_Master_Slave_Mode 中的一个值
                                             @note 当主/从模式启用时，触发输入 (TRGI) 上事件的影响会被延迟，
                                             以允许当前定时器与其从定时器之间（通过 TRGO）实现完美的同步。
                                             在定时器同步模式下这不是强制性的。 */
} TIM_MasterConfigTypeDef;

/**
  * @brief  TIM Slave configuration Structure definition
  * @brief  TIM 从模式配置结构体定义
  */
typedef struct
{
  uint32_t  SlaveMode;         /*!< Slave mode selection
                                    This parameter can be a value of @ref TIM_Slave_Mode */
                                    /*!< 从模式选择。
                                         此参数可以是 @ref TIM_Slave_Mode 中的一个值 */
  uint32_t  InputTrigger;      /*!< Input Trigger source
                                    This parameter can be a value of @ref TIM_Trigger_Selection */
                                    /*!< 输入触发源。
                                         此参数可以是 @ref TIM_Trigger_Selection 中的一个值 */
  uint32_t  TriggerPolarity;   /*!< Input Trigger polarity
                                    This parameter can be a value of @ref TIM_Trigger_Polarity */
                                    /*!< 输入触发极性。
                                         此参数可以是 @ref TIM_Trigger_Polarity 中的一个值 */
  uint32_t  TriggerPrescaler;  /*!< Input trigger prescaler
                                    This parameter can be a value of @ref TIM_Trigger_Prescaler */
                                    /*!< 输入触发预分频器。
                                         此参数可以是 @ref TIM_Trigger_Prescaler 中的一个值 */
  uint32_t  TriggerFilter;     /*!< Input trigger filter
                                    This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF  */
                                    /*!< 输入触发滤波器。
                                         此参数可以是 0x0 到 0xF 之间的数值 */

} TIM_SlaveConfigTypeDef;

/**
  * @brief  TIM Break input(s) and Dead time configuration Structure definition
  * @brief  TIM 刹车输入和死区时间配置结构体定义
  * @note   2 break inputs can be configured (BKIN and BKIN2) with configurable
  *        filter and polarity.
  *        可配置 2 个刹车输入（BKIN 和 BKIN2），具有可配置的滤波器和极性。
  */
typedef struct
{
  uint32_t OffStateRunMode;      /*!< TIM off state in run mode, This parameter can be a value of @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state */
                                 /*!< 运行模式下的 TIM 关断状态选择 (OSSR)。
                                      此参数可以是 @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state 中的一个值 */

  uint32_t OffStateIDLEMode;     /*!< TIM off state in IDLE mode, This parameter can be a value of @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state */
                                 /*!< 空闲模式下的 TIM 关断状态选择 (OSSI)。
                                      此参数可以是 @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state 中的一个值 */

  uint32_t LockLevel;            /*!< TIM Lock level, This parameter can be a value of @ref TIM_Lock_level */
                                 /*!< TIM 锁定级别，用于锁定配置寄存器防止误修改。
                                      此参数可以是 @ref TIM_Lock_level 中的一个值 */

  uint32_t DeadTime;             /*!< TIM dead Time, This parameter can be a number between Min_Data = 0x00 and Max_Data = 0xFF */
                                 /*!< TIM 死区时间，用于互补输出时防止上下桥臂直通。
                                      此参数可以是 0x00 到 0xFF 之间的数值 */

  uint32_t BreakState;           /*!< TIM Break State, This parameter can be a value of @ref TIM_Break_Input_enable_disable */
                                 /*!< TIM 刹车状态（使能或失能）。
                                      此参数可以是 @ref TIM_Break_Input_enable_disable 中的一个值 */

  uint32_t BreakPolarity;        /*!< TIM Break input polarity, This parameter can be a value of @ref TIM_Break_Polarity */
                                 /*!< TIM 刹车输入极性。
                                      此参数可以是 @ref TIM_Break_Polarity 中的一个值 */

  uint32_t BreakFilter;          /*!< Specifies the break input filter.This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                                 /*!< 指定刹车输入滤波器。此参数可以是 0x0 到 0xF 之间的数值 */

  uint32_t AutomaticOutput;      /*!< TIM Automatic Output Enable state, This parameter can be a value of @ref TIM_AOE_Bit_Set_Reset */
                                 /*!< TIM 自动输出使能状态。
                                      此参数可以是 @ref TIM_AOE_Bit_Set_Reset 中的一个值 */

} TIM_BreakDeadTimeConfigTypeDef;

/**
  * @brief  HAL State structures definition
  * @brief  HAL 状态结构体定义
  */
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /*!< Peripheral not yet initialized or disabled  */
                                              /*!< 外设尚未初始化或已禁用 */
  HAL_TIM_STATE_READY             = 0x01U,    /*!< Peripheral Initialized and ready for use    */
                                              /*!< 外设已初始化并准备就绪 */
  HAL_TIM_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing              */
                                              /*!< 正在进行内部处理 */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /*!< Timeout state                               */
                                              /*!< 超时状态 */
  HAL_TIM_STATE_ERROR             = 0x04U     /*!< Reception process is ongoing                */
                                              /*!< 错误状态 */
} HAL_TIM_StateTypeDef;

/**
  * @brief  TIM Channel States definition
  * @brief  TIM 通道状态定义
  */
typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /*!< TIM Channel initial state                         */
                                                       /*!< TIM 通道初始状态 */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /*!< TIM Channel ready for use                         */
                                                       /*!< TIM 通道准备就绪 */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /*!< An internal process is ongoing on the TIM channel */
                                                       /*!< TIM 通道正在进行内部处理 */
} HAL_TIM_ChannelStateTypeDef;

/**
  * @brief  DMA Burst States definition
  * @brief  DMA 突发状态定义
  */
typedef enum
{
  HAL_DMA_BURST_STATE_RESET             = 0x00U,    /*!< DMA Burst initial state */
                                                     /*!< DMA 突发初始状态 */
  HAL_DMA_BURST_STATE_READY             = 0x01U,    /*!< DMA Burst ready for use */
                                                     /*!< DMA 突发准备就绪 */
  HAL_DMA_BURST_STATE_BUSY              = 0x02U,    /*!< Ongoing DMA Burst       */
                                                     /*!< 正在进行 DMA 突发 */
} HAL_TIM_DMABurstStateTypeDef;

/**
  * @brief  HAL Active channel structures definition
  * @brief  HAL 活动通道结构体定义
  */
typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,    /*!< The active channel is 1     */
                                              /*!< 活动通道为 1 */
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,    /*!< The active channel is 2     */
                                              /*!< 活动通道为 2 */
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,    /*!< The active channel is 3     */
                                              /*!< 活动通道为 3 */
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,    /*!< The active channel is 4     */
                                              /*!< 活动通道为 4 */
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /*!< All active channels cleared */
                                              /*!< 所有活动通道已清除 */
} HAL_TIM_ActiveChannel;

/**
  * @brief  TIM Time Base Handle Structure definition
  * @brief  TIM 时基句柄结构体定义
  */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
typedef struct __TIM_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
{
  TIM_TypeDef                        *Instance;         /*!< Register base address                             */
                                                        /*!< 寄存器基地址 */
  TIM_Base_InitTypeDef               Init;              /*!< TIM Time Base required parameters                 */
                                                        /*!< TIM 时基所需参数 */
  HAL_TIM_ActiveChannel              Channel;           /*!< Active channel                                    */
                                                        /*!< 活动通道 */
  DMA_HandleTypeDef                  *hdma[7];          /*!< DMA Handlers array
                                                             This array is accessed by a @ref DMA_Handle_index */
                                                        /*!< DMA 句柄数组
                                                             此数组通过 @ref DMA_Handle_index 访问 */
  HAL_LockTypeDef                    Lock;              /*!< Locking object                                    */
                                                        /*!< 锁定对象 */
  __IO HAL_TIM_StateTypeDef          State;             /*!< TIM operation state                               */
                                                        /*!< TIM 操作状态 */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelState[4];   /*!< TIM channel operation state                       */
                                                        /*!< TIM 通道操作状态 */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /*!< TIM complementary channel operation state         */
                                                        /*!< TIM 互补通道操作状态 */
  __IO HAL_TIM_DMABurstStateTypeDef  DMABurstState;     /*!< DMA burst operation state                         */
                                                        /*!< DMA 突发操作状态 */
