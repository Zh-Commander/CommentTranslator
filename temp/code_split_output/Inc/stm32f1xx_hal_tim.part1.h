#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  /* 基础定时器 MSP 初始化回调函数指针 */
  void (* Base_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 基础定时器 MSP 反初始化回调函数指针 */
  void (* Base_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输入捕获 MSP 初始化回调函数指针 */
  void (* IC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输入捕获 MSP 反初始化回调函数指针 */
  void (* IC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输出比较 MSP 初始化回调函数指针 */
  void (* OC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输出比较 MSP 反初始化回调函数指针 */
  void (* OC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 脉宽调制 MSP 初始化回调函数指针 */
  void (* PWM_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 脉宽调制 MSP 反初始化回调函数指针 */
  void (* PWM_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 单脉冲 MSP 初始化回调函数指针 */
  void (* OnePulse_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 单脉冲 MSP 反初始化回调函数指针 */
  void (* OnePulse_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 编码器 MSP 初始化回调函数指针 */
  void (* Encoder_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 编码器 MSP 反初始化回调函数指针 */
  void (* Encoder_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 霍尔传感器 MSP 初始化回调函数指针 */
  void (* HallSensor_MspInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 霍尔传感器 MSP 反初始化回调函数指针 */
  void (* HallSensor_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);
  /* 计数周期结束回调函数指针 */
  void (* PeriodElapsedCallback)(struct __TIM_HandleTypeDef *htim);
  /* 计数周期半完成回调函数指针 (用于DMA双缓冲) */
  void (* PeriodElapsedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* 触发回调函数指针 */
  void (* TriggerCallback)(struct __TIM_HandleTypeDef *htim);
  /* 触发半完成回调函数指针 (用于DMA双缓冲) */
  void (* TriggerHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输入捕获回调函数指针 */
  void (* IC_CaptureCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输入捕获半完成回调函数指针 (用于DMA双缓冲) */
  void (* IC_CaptureHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* 输出比较延迟结束回调函数指针 */
  void (* OC_DelayElapsedCallback)(struct __TIM_HandleTypeDef *htim);
  /* PWM 脉冲结束回调函数指针 */
  void (* PWM_PulseFinishedCallback)(struct __TIM_HandleTypeDef *htim);
  /* PWM 脉冲半完成回调函数指针 (用于DMA双缓冲) */
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* 错误回调函数指针 */
  void (* ErrorCallback)(struct __TIM_HandleTypeDef *htim);
  /* 换相回调函数指针 */
  void (* CommutationCallback)(struct __TIM_HandleTypeDef *htim);
  /* 换相半完成回调函数指针 (用于DMA双缓冲) */
  void (* CommutationHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);
  /* 刹车回调函数指针 */
  void (* BreakCallback)(struct __TIM_HandleTypeDef *htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
} TIM_HandleTypeDef;

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TIM 回调 ID 枚举定义
  * @note   用于区分不同的回调函数，方便注册和注销
  */
typedef enum
{
  /* 基础定时器 MSP 初始化回调 ID */
  HAL_TIM_BASE_MSPINIT_CB_ID              = 0x00U
  /* 基础定时器 MSP 反初始化回调 ID */
  , HAL_TIM_BASE_MSPDEINIT_CB_ID          = 0x01U
  /* 输入捕获 MSP 初始化回调 ID */
  , HAL_TIM_IC_MSPINIT_CB_ID              = 0x02U
  /* 输入捕获 MSP 反初始化回调 ID */
  , HAL_TIM_IC_MSPDEINIT_CB_ID            = 0x03U
  /* 输出比较 MSP 初始化回调 ID */
  , HAL_TIM_OC_MSPINIT_CB_ID              = 0x04U
  /* 输出比较 MSP 反初始化回调 ID */
  , HAL_TIM_OC_MSPDEINIT_CB_ID            = 0x05U
  /* PWM MSP 初始化回调 ID */
  , HAL_TIM_PWM_MSPINIT_CB_ID             = 0x06U
  /* PWM MSP 反初始化回调 ID */
  , HAL_TIM_PWM_MSPDEINIT_CB_ID           = 0x07U
  /* 单脉冲 MSP 初始化回调 ID */
  , HAL_TIM_ONE_PULSE_MSPINIT_CB_ID       = 0x08U
  /* 单脉冲 MSP 反初始化回调 ID */
  , HAL_TIM_ONE_PULSE_MSPDEINIT_CB_ID     = 0x09U
  /* 编码器 MSP 初始化回调 ID */
  , HAL_TIM_ENCODER_MSPINIT_CB_ID         = 0x0AU
  /* 编码器 MSP 反初始化回调 ID */
  , HAL_TIM_ENCODER_MSPDEINIT_CB_ID       = 0x0BU
  /* 霍尔传感器 MSP 初始化回调 ID */
  , HAL_TIM_HALL_SENSOR_MSPINIT_CB_ID     = 0x0CU
  /* 霍尔传感器 MSP 反初始化回调 ID */
  , HAL_TIM_HALL_SENSOR_MSPDEINIT_CB_ID   = 0x0DU
  /* 计数周期结束回调 ID */
  , HAL_TIM_PERIOD_ELAPSED_CB_ID          = 0x0EU
  /* 计数周期半完成回调 ID */
  , HAL_TIM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU
  /* 触发回调 ID */
  , HAL_TIM_TRIGGER_CB_ID                 = 0x10U
  /* 触发半完成回调 ID */
  , HAL_TIM_TRIGGER_HALF_CB_ID            = 0x11U
  /* 输入捕获回调 ID */
  , HAL_TIM_IC_CAPTURE_CB_ID              = 0x12U
  /* 输入捕获半完成回调 ID */
  , HAL_TIM_IC_CAPTURE_HALF_CB_ID         = 0x13U
  /* 输出比较延迟结束回调 ID */
  , HAL_TIM_OC_DELAY_ELAPSED_CB_ID        = 0x14U
  /* PWM 脉冲结束回调 ID */
  , HAL_TIM_PWM_PULSE_FINISHED_CB_ID      = 0x15U
  /* PWM 脉冲半完成回调 ID */
  , HAL_TIM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U
  /* 错误回调 ID */
  , HAL_TIM_ERROR_CB_ID                   = 0x17U
  /* 换相回调 ID */
  , HAL_TIM_COMMUTATION_CB_ID             = 0x18U
  /* 换相半完成回调 ID */
  , HAL_TIM_COMMUTATION_HALF_CB_ID        = 0x19U
  /* 刹车回调 ID */
  , HAL_TIM_BREAK_CB_ID                   = 0x1AU
} HAL_TIM_CallbackIDTypeDef;

/**
  * @brief  HAL TIM 回调函数指针定义
  */
typedef  void (*pTIM_CallbackTypeDef)(TIM_HandleTypeDef *htim);  /* 指向 TIM 回调函数的指针 */

#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* 导出类型结束 -----------------------------------------------------*/

/* 导出常量 --------------------------------------------------------*/
/** @defgroup TIM_Exported_Constants TIM 导出常量
  * @{
  */

/** @defgroup TIM_ClearInput_Source TIM 清除输入源
  * @{
  */
/* OCREF_CLR 功能被禁止 */
#define TIM_CLEARINPUTSOURCE_NONE           0x00000000U
/* OCREF_CLR 连接到 ETRF 输入 */
#define TIM_CLEARINPUTSOURCE_ETR            0x00000001U
/**
  * @}
  */

/** @defgroup TIM_DMA_Base_address TIM DMA 基地址
  * @{
  */
/* DMA 访问基地址指向 CR1 寄存器 */
#define TIM_DMABASE_CR1                    0x00000000U
/* DMA 访问基地址指向 CR2 寄存器 */
#define TIM_DMABASE_CR2                    0x00000001U
/* DMA 访问基地址指向 SMCR 寄存器 */
#define TIM_DMABASE_SMCR                   0x00000002U
/* DMA 访问基地址指向 DIER 寄存器 */
#define TIM_DMABASE_DIER                   0x00000003U
/* DMA 访问基地址指向 SR 寄存器 */
#define TIM_DMABASE_SR                     0x00000004U
/* DMA 访问基地址指向 EGR 寄存器 */
#define TIM_DMABASE_EGR                    0x00000005U
/* DMA 访问基地址指向 CCMR1 寄存器 */
#define TIM_DMABASE_CCMR1                  0x00000006U
/* DMA 访问基地址指向 CCMR2 寄存器 */
#define TIM_DMABASE_CCMR2                  0x00000007U
/* DMA 访问基地址指向 CCER 寄存器 */
#define TIM_DMABASE_CCER                   0x00000008U
/* DMA 访问基地址指向 CNT 计数器寄存器 */
#define TIM_DMABASE_CNT                    0x00000009U
/* DMA 访问基地址指向 PSC 预分频寄存器 */
#define TIM_DMABASE_PSC                    0x0000000AU
/* DMA 访问基地址指向 ARR 自动重装载寄存器 */
#define TIM_DMABASE_ARR                    0x0000000BU
/* DMA 访问基地址指向 RCR 重复计数寄存器 */
#define TIM_DMABASE_RCR                    0x0000000CU
/* DMA 访问基地址指向 CCR1 捕获/比较寄存器 1 */
#define TIM_DMABASE_CCR1                   0x0000000DU
/* DMA 访问基地址指向 CCR2 捕获/比较寄存器 2 */
#define TIM_DMABASE_CCR2                   0x0000000EU
/* DMA 访问基地址指向 CCR3 捕获/比较寄存器 3 */
#define TIM_DMABASE_CCR3                   0x0000000FU
/* DMA 访问基地址指向 CCR4 捕获/比较寄存器 4 */
#define TIM_DMABASE_CCR4                   0x00000010U
/* DMA 访问基地址指向 BDTR 刹车和死区寄存器 */
#define TIM_DMABASE_BDTR                   0x00000011U
/* DMA 访问基地址指向 DCR DMA 控制寄存器 */
#define TIM_DMABASE_DCR                    0x00000012U
/* DMA 访问基地址指向 DMAR DMA 地址寄存器 */
#define TIM_DMABASE_DMAR                   0x00000013U
/**
  * @}
  */

/** @defgroup TIM_Event_Source TIM 事件源
  * @{
  */
/* 重新初始化计数器并产生寄存器更新事件 */
#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG
/* 在通道 1 上产生捕获/比较事件 */
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G
/* 在通道 2 上产生捕获/比较事件 */
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G
/* 在通道 3 上产生捕获/比较事件 */
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G
/* 在通道 4 上产生捕获/比较事件 */
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
/* 输入捕获上升沿极性 */
#define  TIM_INPUTCHANNELPOLARITY_RISING      0x00000000U
/* 输入捕获下降沿极性 */
#define  TIM_INPUTCHANNELPOLARITY_FALLING     TIM_CCER_CC1P
/* 输入捕获双边沿极性 (上升沿和下降沿均捕获) */
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)
/**
  * @}
  */

/** @defgroup TIM_ETR_Polarity TIM ETR 极性 (外部触发输入)
  * @{
  */
/* ETR 反相极性：低电平或下降沿有效 */
#define TIM_ETRPOLARITY_INVERTED              TIM_SMCR_ETP
/* ETR 非反相极性：高电平或上升沿有效 */
#define TIM_ETRPOLARITY_NONINVERTED           0x00000000U
/**
  * @}
  */

/** @defgroup TIM_ETR_Prescaler TIM ETR 预分频器
  * @{
  */
/* ETR 输入源不分频 */
#define TIM_ETRPRESCALER_DIV1                 0x00000000U
/* ETR 输入源 2 分频 */
#define TIM_ETRPRESCALER_DIV2                 TIM_SMCR_ETPS_0
/* ETR 输入源 4 分频 */
#define TIM_ETRPRESCALER_DIV4                 TIM_SMCR_ETPS_1
/* ETR 输入源 8 分频 */
#define TIM_ETRPRESCALER_DIV8                 TIM_SMCR_ETPS
/**
  * @}
  */

/** @defgroup TIM_Counter_Mode TIM 计数模式
  * @{
  */
/* 向上计数模式 */
#define TIM_COUNTERMODE_UP                 0x00000000U
/* 向下计数模式 */
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR
/* 中心对齐模式 1：仅在计数器向下计数时产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0
/* 中心对齐模式 2：仅在计数器向上计数时产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1
/* 中心对齐模式 3：在计数器向上和向下计数时均产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS
/**
  * @}
  */

/** @defgroup TIM_ClockDivision TIM 时钟分频
  * @{
  */
/* 时钟分频因子为 1，tDTS=tCK_INT */
#define TIM_CLOCKDIVISION_DIV1             0x00000000U
/* 时钟分频因子为 2，tDTS=2*tCK_INT */
#define TIM_CLOCKDIVISION_DIV2             TIM_CR1_CKD_0
/* 时钟分频因子为 4，tDTS=4*tCK_INT */
#define TIM_CLOCKDIVISION_DIV4             TIM_CR1_CKD_1
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_State TIM 输出比较状态
  * @{
  */
/* 捕获/比较 1 输出禁止 (OCx 输出禁用) */
#define TIM_OUTPUTSTATE_DISABLE            0x00000000U
/* 捕获/比较 1 输出使能 (OCx 输出使能) */
#define TIM_OUTPUTSTATE_ENABLE             TIM_CCER_CC1E
/**
  * @}
  */

/** @defgroup TIM_AutoReloadPreload TIM 自动重装载预装载
  * @{
  */
/* TIMx_ARR 寄存器未缓冲，写入后立即生效 */
#define TIM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U
/* TIMx_ARR 寄存器缓冲，写入后在下一个更新事件生效 */
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 TIM_CR1_ARPE

/**
  * @}
  */

/** @defgroup TIM_Output_Fast_State TIM 输出快速状态
  * @{
  */
/* 输出比较快速模式禁止 */
#define TIM_OCFAST_DISABLE                 0x00000000U
/* 输出比较快速模式使能 */
#define TIM_OCFAST_ENABLE                  TIM_CCMR1_OC1FE
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_State TIM 互补输出比较状态
  * @{
  */
/* 互补输出 OCxN 禁止 */
#define TIM_OUTPUTNSTATE_DISABLE           0x00000000U
/* 互补输出 OCxN 使能 */
#define TIM_OUTPUTNSTATE_ENABLE            TIM_CCER_CC1NE
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Polarity TIM 输出比较极性
  * @{
  */
/* 输出比较极性高：有效电平为高电平 */
#define TIM_OCPOLARITY_HIGH                0x00000000U
/* 输出比较极性低：有效电平为低电平 */
#define TIM_OCPOLARITY_LOW                 TIM_CCER_CC1P
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Polarity TIM 互补输出比较极性
  * @{
  */
/* 互补输出比较极性高：有效电平为高电平 */
#define TIM_OCNPOLARITY_HIGH               0x00000000U
/* 互补输出比较极性低：有效电平为低电平 */
#define TIM_OCNPOLARITY_LOW                TIM_CCER_CC1NP
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Idle_State TIM 输出比较空闲状态
  * @{
  */
/* 空闲状态 OCx=1 (当 MOE=0 时) */
#define TIM_OCIDLESTATE_SET                TIM_CR2_OIS1
/* 空闲状态 OCx=0 (当 MOE=0 时) */
#define TIM_OCIDLESTATE_RESET              0x00000000U
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Idle_State TIM 互补输出比较空闲状态
  * @{
  */
/* 互补空闲状态 OCxN=1 (当 MOE=0 时) */
#define TIM_OCNIDLESTATE_SET               TIM_CR2_OIS1N
/* 互补空闲状态 OCxN=0 (当 MOE=0 时) */
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
/* 输入捕获双边沿触发 (上升沿和下降沿均触发) */
#define  TIM_ICPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE
/**
  * @}
  */

/** @defgroup TIM_Encoder_Input_Polarity TIM 编码器输入极性
  * @{
  */
/* 编码器输入上升沿极性 */
#define  TIM_ENCODERINPUTPOLARITY_RISING   TIM_INPUTCHANNELPOLARITY_RISING
/* 编码器输入下降沿极性 */
#define  TIM_ENCODERINPUTPOLARITY_FALLING  TIM_INPUTCHANNELPOLARITY_FALLING
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Selection TIM 输入捕获选择
  * @{
  */
/* 直接映射：TI1 映射到 IC1，TI2 映射到 IC2，以此类推 */
#define TIM_ICSELECTION_DIRECTTI           TIM_CCMR1_CC1S_0
/* 间接映射：TI1 映射到 IC2，TI2 映射到 IC1，以此类推 */
#define TIM_ICSELECTION_INDIRECTTI         TIM_CCMR1_CC1S_1
/* TRC 映射：输入捕获连接到 TRC 信号 */
#define TIM_ICSELECTION_TRC                TIM_CCMR1_CC1S
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Prescaler TIM 输入捕获预分频器
  * @{
  */
/* 无预分频，每次检测到边沿都执行捕获 */
#define TIM_ICPSC_DIV1                     0x00000000U
/* 2 分频，每 2 个事件执行一次捕获 */
#define TIM_ICPSC_DIV2                     TIM_CCMR1_IC1PSC_0
/* 4 分频，每 4 个事件执行一次捕获 */
#define TIM_ICPSC_DIV4                     TIM_CCMR1_IC1PSC_1
/* 8 分频，每 8 个事件执行一次捕获 */
#define TIM_ICPSC_DIV8                     TIM_CCMR1_IC1PSC
/**
  * @}
  */

/** @defgroup TIM_One_Pulse_Mode TIM 单脉冲模式
  * @{
  */
/* 单脉冲模式：在下一个更新事件停止计数器 */
#define TIM_OPMODE_SINGLE                  TIM_CR1_OPM
/* 重复模式：计数器在更新事件时不停止 */
#define TIM_OPMODE_REPETITIVE              0x00000000U
/**
  * @}
  */

/** @defgroup TIM_Encoder_Mode TIM 编码器模式
  * @{
  */
/* 编码器模式 1：TI1FP1 边沿计数 (x2 模式)，计数方向取决于 TI2FP2 电平 */
#define TIM_ENCODERMODE_TI1                      TIM_SMCR_SMS_0
/* 编码器模式 2：TI2FP2 边沿计数 (x2 模式)，计数方向取决于 TI1FP1 电平 */
#define TIM_ENCODERMODE_TI2                      TIM_SMCR_SMS_1
/* 编码器模式 3：TI1FP1 和 TI2FP2 边沿均计数 (x4 模式)，计数方向取决于另一输入电平 */
#define TIM_ENCODERMODE_TI12                     (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)
/**
  * @}
  */

/** @defgroup TIM_Interrupt_definition TIM 中断定义
  * @{
  */
/* 更新中断 */
#define TIM_IT_UPDATE                      TIM_DIER_UIE
/* 捕获/比较 1 中断 */
#define TIM_IT_CC1                         TIM_DIER_CC1IE
/* 捕获/比较 2 中断 */
#define TIM_IT_CC2                         TIM_DIER_CC2IE
/* 捕获/比较 3 中断 */
#define TIM_IT_CC3                         TIM_DIER_CC3IE
/* 捕获/比较 4 中断 */
#define TIM_IT_CC4                         TIM_DIER_CC4IE
/* 换相中断 */
#define TIM_IT_COM                         TIM_DIER_COMIE
/* 触发中断 */
#define TIM_IT_TRIGGER                     TIM_DIER_TIE
/* 刹车中断 */
#define TIM_IT_BREAK                       TIM_DIER_BIE
/**
  * @}
  */
