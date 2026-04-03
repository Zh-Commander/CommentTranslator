/**
  ******************************************************************************
  * @file    stm32f1xx_hal_tim.h
  * @author  MCD Application Team
  * @brief   TIM HAL 模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的 LICENSE 文件中找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef STM32F1xx_HAL_TIM_H
#define STM32F1xx_HAL_TIM_H

#ifdef __cplusplus
extern "C" { /* 为了在 C++ 代码中调用 C 函数，确保链接正确 */
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h" /* 包含 HAL 库通用定义 */

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
  *         用于配置定时器的基本工作参数，如预分频、计数模式等。
  */
typedef struct
{
  uint32_t Prescaler;         /* 指定预分频值，用于对 TIM 时钟进行分频。
                                 该参数数值范围：Min_Data = 0x0000，Max_Data = 0xFFFF。
                                 实际分频系数为 Prescaler + 1。 */

  uint32_t CounterMode;       /* 指定计数器模式。
                                 该参数可取值为 @ref TIM_Counter_Mode 中的值，
                                 例如向上计数、向下计数或中心对齐计数。 */

  uint32_t Period;            /* 指定在下一个更新事件时加载到活动自动重装载寄存器 (ARR) 中的周期值。
                                 该参数数值范围：Min_Data = 0x0000，Max_Data = 0xFFFF。
                                 决定了定时器的计数周期。 */

  uint32_t ClockDivision;     /* 指定时钟分频因子。
                                 该参数可取值为 @ref TIM_ClockDivision 中的值。
                                 此分频用于死区时间生成和数字滤波器（ETR, TIx）。 */

  uint32_t RepetitionCounter;  /* 指定重复计数器值。每当 RCR 递减计数器
                                 达到零时，就会生成更新事件，并从 RCR 值 (N) 重新开始计数。
                                 这意味着在 PWM 模式下 (N+1) 对应于：
                                     - 边沿对齐模式下的 PWM 周期数
                                     - 中心对齐模式下的半 PWM 周期数
                                  通用定时器: 该参数数值范围：Min_Data = 0x00，Max_Data = 0xFF。
                                  高级定时器: 该参数数值范围：Min_Data = 0x0000，Max_Data = 0xFFFF。 */

  uint32_t AutoReloadPreload;  /* 指定自动重装载预装载使能状态。
                                 该参数可取值为 @ref TIM_AutoReloadPreload 中的值。
                                 使能后，写入 ARR 的值会在下一个更新事件才生效。 */
} TIM_Base_InitTypeDef;

/**
  * @brief  TIM 输出比较配置结构体定义
  *         用于配置定时器的输出比较模式，常用于 PWM 输出或波形生成。
  */
typedef struct
{
  uint32_t OCMode;        /* 指定 TIM 输出比较模式。
                             该参数可取值为 @ref TIM_Output_Compare_and_PWM_modes 中的值。 */

  uint32_t Pulse;         /* 指定加载到捕获比较寄存器 (CCR) 的脉冲值。
                             该参数数值范围：Min_Data = 0x0000，Max_Data = 0xFFFF。
                             在 PWM 模式下决定了占空比。 */

  uint32_t OCPolarity;    /* 指定输出极性（有效电平）。
                             该参数可取值为 @ref TIM_Output_Compare_Polarity 中的值。 */

  uint32_t OCNPolarity;   /* 指定互补输出极性。
                             该参数可取值为 @ref TIM_Output_Compare_N_Polarity 中的值。
                             @note 此参数仅适用于支持刹车功能的定时器实例（高级定时器）。 */

  uint32_t OCFastMode;    /* 指定快速模式状态。
                             该参数可取值为 @ref TIM_Output_Fast_State 中的值。
                             @note 此参数仅在 PWM1 和 PWM2 模式下有效。 */


  uint32_t OCIdleState;   /* 指定空闲状态下的 TIM 输出比较引脚状态。
                             该参数可取值为 @ref TIM_Output_Compare_Idle_State 中的值。
                             @note 此参数仅适用于支持刹车功能的定时器实例。 */

  uint32_t OCNIdleState;  /* 指定空闲状态下的 TIM 互补输出比较引脚状态。
                             该参数可取值为 @ref TIM_Output_Compare_N_Idle_State 中的值。
                             @note 此参数仅适用于支持刹车功能的定时器实例。 */
} TIM_OC_InitTypeDef;

/**
  * @brief  TIM 单脉冲模式配置结构体定义
  *         用于配置单脉冲模式，常用于产生精确的脉冲延时或脉宽。
  */
typedef struct
{
  uint32_t OCMode;        /* 指定 TIM 模式。
                             该参数可取值为 @ref TIM_Output_Compare_and_PWM_modes 中的值。 */

  uint32_t Pulse;         /* 指定加载到捕获比较寄存器的脉冲值。
                             该参数数值范围：Min_Data = 0x0000，Max_Data = 0xFFFF。 */

  uint32_t OCPolarity;    /* 指定输出极性。
                             该参数可取值为 @ref TIM_Output_Compare_Polarity 中的值。 */

  uint32_t OCNPolarity;   /* 指定互补输出极性。
                             该参数可取值为 @ref TIM_Output_Compare_N_Polarity 中的值。
                             @note 此参数仅适用于支持刹车功能的定时器实例。 */

  uint32_t OCIdleState;   /* 指定空闲状态下的 TIM 输出比较引脚状态。
                             该参数可取值为 @ref TIM_Output_Compare_Idle_State 中的值。
                             @note 此参数仅适用于支持刹车功能的定时器实例。 */

  uint32_t OCNIdleState;  /* 指定空闲状态下的 TIM 互补输出比较引脚状态。
                             该参数可取值为 @ref TIM_Output_Compare_N_Idle_State 中的值。
                             @note 此参数仅适用于支持刹车功能的定时器实例。 */

  uint32_t ICPolarity;    /* 指定输入信号的有效边沿（触发脉冲产生的边沿）。
                             该参数可取值为 @ref TIM_Input_Capture_Polarity 中的值。 */

  uint32_t ICSelection;   /* 指定输入端选择。
                             该参数可取值为 @ref TIM_Input_Capture_Selection 中的值。 */

  uint32_t ICFilter;      /* 指定输入捕获滤波器。
                             该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。
                             用于滤除高频噪声。 */
} TIM_OnePulse_InitTypeDef;

/**
  * @brief  TIM 输入捕获配置结构体定义
  *         用于配置定时器的输入捕获模式，常用于测量信号频率或脉宽。
  */
typedef struct
{
  uint32_t  ICPolarity;  /* 指定输入信号的有效边沿。
                            该参数可取值为 @ref TIM_Input_Capture_Polarity 中的值。 */

  uint32_t ICSelection;  /* 指定输入映射选择。
                            该参数可取值为 @ref TIM_Input_Capture_Selection 中的值。 */

  uint32_t ICPrescaler;  /* 指定输入捕获预分频器。
                            该参数可取值为 @ref TIM_Input_Capture_Prescaler 中的值。
                            决定每几次事件触发一次捕获。 */

  uint32_t ICFilter;     /* 指定输入捕获滤波器。
                            该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。 */
} TIM_IC_InitTypeDef;

/**
  * @brief  TIM 编码器配置结构体定义
  *         用于配置定时器的编码器接口模式，常用于电机测速或测位。
  */
typedef struct
{
  uint32_t EncoderMode;   /* 指定编码器模式。
                             该参数可取值为 @ref TIM_Encoder_Mode 中的值。 */

  uint32_t IC1Polarity;   /* 指定通道 1 输入信号的有效边沿。
                             该参数可取值为 @ref TIM_Encoder_Input_Polarity 中的值。 */

  uint32_t IC1Selection;  /* 指定通道 1 输入映射选择。
                             该参数可取值为 @ref TIM_Input_Capture_Selection 中的值。 */

  uint32_t IC1Prescaler;  /* 指定通道 1 输入捕获预分频器。
                             该参数可取值为 @ref TIM_Input_Capture_Prescaler 中的值。 */

  uint32_t IC1Filter;     /* 指定通道 1 输入捕获滤波器。
                             该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。 */

  uint32_t IC2Polarity;   /* 指定通道 2 输入信号的有效边沿。
                             该参数可取值为 @ref TIM_Encoder_Input_Polarity 中的值。 */

  uint32_t IC2Selection;  /* 指定通道 2 输入映射选择。
                             该参数可取值为 @ref TIM_Input_Capture_Selection 中的值。 */

  uint32_t IC2Prescaler;  /* 指定通道 2 输入捕获预分频器。
                             该参数可取值为 @ref TIM_Input_Capture_Prescaler 中的值。 */

  uint32_t IC2Filter;     /* 指定通道 2 输入捕获滤波器。
                             该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。 */
} TIM_Encoder_InitTypeDef;

/**
  * @brief  时钟配置句柄结构体定义
  *         用于配置外部时钟输入模式。
  */
typedef struct
{
  uint32_t ClockSource;     /* TIM 时钟源选择
                                 该参数可取值为 @ref TIM_Clock_Source 中的值。 */
  uint32_t ClockPolarity;   /* TIM 时钟极性
                                 该参数可取值为 @ref TIM_Clock_Polarity 中的值。 */
  uint32_t ClockPrescaler;  /* TIM 时钟预分频
                                 该参数可取值为 @ref TIM_Clock_Prescaler 中的值。 */
  uint32_t ClockFilter;     /* TIM 时钟滤波器
                                 该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。 */
} TIM_ClockConfigTypeDef;

/**
  * @brief  TIM 清除输入配置句柄结构体定义
  *         用于配置 OCREF 清除功能，常用于安全控制。
  */
typedef struct
{
  uint32_t ClearInputState;      /* TIM 清除输入状态
                                      该参数可以是 ENABLE 或 DISABLE。 */
  uint32_t ClearInputSource;     /* TIM 清除输入源
                                      该参数可取值为 @ref TIM_ClearInput_Source 中的值。 */
  uint32_t ClearInputPolarity;   /* TIM 清除输入极性
                                      该参数可取值为 @ref TIM_ClearInput_Polarity 中的值。 */
  uint32_t ClearInputPrescaler;  /* TIM 清除输入预分频
                                      该参数必须为 0：当 OCRef 清除功能与 ETR 源一起使用时，
                                      ETR 预分频器必须关闭。 */
  uint32_t ClearInputFilter;     /* TIM 清除输入滤波器
                                      该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。 */
} TIM_ClearInputConfigTypeDef;

/**
  * @brief  TIM 主模式配置结构体定义
  *         用于配置定时器作为主设备时的触发输出 (TRGO)。
  */
typedef struct
{
  uint32_t  MasterOutputTrigger;   /* 触发输出 (TRGO) 选择
                                        该参数可取值为 @ref TIM_Master_Mode_Selection 中的值。 */
  uint32_t  MasterSlaveMode;       /* 主/从模式选择
                                        该参数可取值为 @ref TIM_Master_Slave_Mode 中的值。
                                        @note 当主/从模式使能时，触发输入 (TRGI) 上的事件效果会被延迟，
                                        以允许当前定时器与其从定时器（通过 TRGO）之间的完美同步。
                                        在定时器同步模式下这不是强制性的。 */
} TIM_MasterConfigTypeDef;

/**
  * @brief  TIM 从模式配置结构体定义
  *         用于配置定时器作为从设备时的同步模式。
  */
typedef struct
{
  uint32_t  SlaveMode;         /* 从模式选择
                                    该参数可取值为 @ref TIM_Slave_Mode 中的值。 */
  uint32_t  InputTrigger;      /* 输入触发源
                                    该参数可取值为 @ref TIM_Trigger_Selection 中的值。 */
  uint32_t  TriggerPolarity;   /* 输入触发极性
                                    该参数可取值为 @ref TIM_Trigger_Polarity 中的值。 */
  uint32_t  TriggerPrescaler;  /* 输入触发预分频
                                    该参数可取值为 @ref TIM_Trigger_Prescaler 中的值。 */
  uint32_t  TriggerFilter;     /* 输入触发滤波器
                                    该参数数值范围：Min_Data = 0x0，Max_Data = 0xF  */

} TIM_SlaveConfigTypeDef;

/**
  * @brief  TIM 刹车输入和死区时间配置结构体定义
  * @note   可以配置 2 个刹车输入 (BKIN 和 BKIN2)，具有可配置的滤波器和极性。
  *         仅适用于高级定时器。
  */
typedef struct
{
  uint32_t OffStateRunMode;      /* 运行模式下的关闭状态选择 (OSSR)，
                                    该参数可取值为 @ref TIM_OSSR_Off_State_Selection_for_Run_mode_state 中的值。 */

  uint32_t OffStateIDLEMode;     /* 空闲模式下的关闭状态选择 (OSSI)，
                                    该参数可取值为 @ref TIM_OSSI_Off_State_Selection_for_Idle_mode_state 中的值。 */

  uint32_t LockLevel;            /* TIM 锁定级别，用于写保护配置，
                                    该参数可取值为 @ref TIM_Lock_level 中的值。 */

  uint32_t DeadTime;             /* TIM 死区时间，
                                    该参数数值范围：Min_Data = 0x00，Max_Data = 0xFF。 */

  uint32_t BreakState;           /* TIM 刹车输入使能状态，
                                    该参数可取值为 @ref TIM_Break_Input_enable_disable 中的值。 */

  uint32_t BreakPolarity;        /* TIM 刹车输入极性，
                                    该参数可取值为 @ref TIM_Break_Polarity 中的值。 */

  uint32_t BreakFilter;          /* 指定刹车输入滤波器，
                                    该参数数值范围：Min_Data = 0x0，Max_Data = 0xF。 */

  uint32_t AutomaticOutput;      /* TIM 自动输出使能状态，
                                    该参数可取值为 @ref TIM_AOE_Bit_Set_Reset 中的值。 */

} TIM_BreakDeadTimeConfigTypeDef;

/**
  * @brief  HAL 状态结构体定义
  *         用于表示 HAL 库函数的执行状态。
  */
typedef enum
{
  HAL_TIM_STATE_RESET             = 0x00U,    /* 外设尚未初始化或已禁用 */
  HAL_TIM_STATE_READY             = 0x01U,    /* 外设已初始化并准备使用 */
  HAL_TIM_STATE_BUSY              = 0x02U,    /* 内部处理正在进行中 */
  HAL_TIM_STATE_TIMEOUT           = 0x03U,    /* 超时状态 */
  HAL_TIM_STATE_ERROR             = 0x04U     /* 错误状态 */
} HAL_TIM_StateTypeDef;

/**
  * @brief  TIM 通道状态定义
  *         用于跟踪特定定时器通道的状态。
  */
typedef enum
{
  HAL_TIM_CHANNEL_STATE_RESET             = 0x00U,    /* TIM 通道初始状态 */
  HAL_TIM_CHANNEL_STATE_READY             = 0x01U,    /* TIM 通道准备就绪 */
  HAL_TIM_CHANNEL_STATE_BUSY              = 0x02U,    /* TIM 通道正在进行内部处理 */
} HAL_TIM_ChannelStateTypeDef;

/**
  * @brief  DMA 突发状态定义
  *         用于跟踪 DMA 突发传输的状态。
  */
typedef enum
{
  HAL_DMA_BURST_STATE_RESET             = 0x00U,    /* DMA 突发初始状态 */
  HAL_DMA_BURST_STATE_READY             = 0x01U,    /* DMA 突发准备就绪 */
  HAL_DMA_BURST_STATE_BUSY              = 0x02U,    /* 正在进行 DMA 突发传输 */
} HAL_TIM_DMABurstStateTypeDef;

/**
  * @brief  HAL 活动通道结构体定义
  *         用于标识当前正在操作的定时器通道。
  */
typedef enum
{
  HAL_TIM_ACTIVE_CHANNEL_1        = 0x01U,    /* 当前活动通道为通道 1 */
  HAL_TIM_ACTIVE_CHANNEL_2        = 0x02U,    /* 当前活动通道为通道 2 */
  HAL_TIM_ACTIVE_CHANNEL_3        = 0x04U,    /* 当前活动通道为通道 3 */
  HAL_TIM_ACTIVE_CHANNEL_4        = 0x08U,    /* 当前活动通道为通道 4 */
  HAL_TIM_ACTIVE_CHANNEL_CLEARED  = 0x00U     /* 所有活动通道已清除 */
} HAL_TIM_ActiveChannel;

/**
  * @brief  TIM 时基句柄结构体定义
  *         这是 TIM 外设的主要句柄结构体，包含配置、状态和回调指针。
  */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
typedef struct __TIM_HandleTypeDef
#else
typedef struct
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
{
  TIM_TypeDef                        *Instance;         /* 寄存器基地址，指向具体的 TIMx 外设 */
  TIM_Base_InitTypeDef               Init;              /* TIM 时基所需的配置参数 */
  HAL_TIM_ActiveChannel              Channel;           /* 活动通道，标识当前正在使用的通道 */
  DMA_HandleTypeDef                  *hdma[7];          /* DMA 句柄数组
                                                             该数组通过 @ref DMA_Handle_index 进行访问 */
  HAL_LockTypeDef                    Lock;              /* 锁定对象，用于资源保护 */
  __IO HAL_TIM_StateTypeDef          State;             /* TIM 操作状态 */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelState[4];   /* TIM 通道操作状态，对应通道 1-4 */
  __IO HAL_TIM_ChannelStateTypeDef   ChannelNState[4];  /* TIM 互补通道操作状态，对应互补通道 1-4 */
  __IO HAL_TIM_DMABurstStateTypeDef  DMABurstState;     /* DMA 突发操作状态 */
