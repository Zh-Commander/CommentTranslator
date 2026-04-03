#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  void (* Base_MspInitCallback)(struct __TIM_HandleTypeDef *htim);              /* 基础定时器模式 MSP 初始化回调函数指针 */
  void (* Base_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);            /* 基础定时器模式 MSP 反初始化回调函数指针 */
  void (* IC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /* 输入捕获模式 MSP 初始化回调函数指针 */
  void (* IC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /* 输入捕获模式 MSP 反初始化回调函数指针 */
  void (* OC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /* 输出比较模式 MSP 初始化回调函数指针 */
  void (* OC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /* 输出比较模式 MSP 反初始化回调函数指针 */
  void (* PWM_MspInitCallback)(struct __TIM_HandleTypeDef *htim);               /* PWM 模式 MSP 初始化回调函数指针 */
  void (* PWM_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);             /* PWM 模式 MSP 反初始化回调函数指针 */
  void (* OnePulse_MspInitCallback)(struct __TIM_HandleTypeDef *htim);          /* 单脉冲模式 MSP 初始化回调函数指针 */
  void (* OnePulse_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);        /* 单脉冲模式 MSP 反初始化回调函数指针 */
  void (* Encoder_MspInitCallback)(struct __TIM_HandleTypeDef *htim);           /* 编码器模式 MSP 初始化回调函数指针 */
  void (* Encoder_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);         /* 编码器模式 MSP 反初始化回调函数指针 */
  void (* HallSensor_MspInitCallback)(struct __TIM_HandleTypeDef *htim);        /* 霍尔传感器模式 MSP 初始化回调函数指针 */
  void (* HallSensor_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);      /* 霍尔传感器模式 MSP 反初始化回调函数指针 */
  void (* PeriodElapsedCallback)(struct __TIM_HandleTypeDef *htim);             /* 周期溢出回调函数指针（更新中断时调用） */
  void (* PeriodElapsedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);     /* 周期溢出半完成回调函数指针（DMA传输过半时调用） */
  void (* TriggerCallback)(struct __TIM_HandleTypeDef *htim);                   /* 触发回调函数指针 */
  void (* TriggerHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);           /* 触发半完成回调函数指针 */
  void (* IC_CaptureCallback)(struct __TIM_HandleTypeDef *htim);                /* 输入捕获回调函数指针 */
  void (* IC_CaptureHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);        /* 输入捕获半完成回调函数指针 */
  void (* OC_DelayElapsedCallback)(struct __TIM_HandleTypeDef *htim);           /* 输出比较延迟结束回调函数指针 */
  void (* PWM_PulseFinishedCallback)(struct __TIM_HandleTypeDef *htim);         /* PWM 脉冲完成回调函数指针 */
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim); /* PWM 脉冲完成半完成回调函数指针 */
  void (* ErrorCallback)(struct __TIM_HandleTypeDef *htim);                     /* 错误回调函数指针 */
  void (* CommutationCallback)(struct __TIM_HandleTypeDef *htim);               /* 换相回调函数指针（用于电机控制） */
  void (* CommutationHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);       /* 换相半完成回调函数指针 */
  void (* BreakCallback)(struct __TIM_HandleTypeDef *htim);                     /* 刹车回调函数指针（用于电机保护） */
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
} TIM_HandleTypeDef;

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TIM 回调ID枚举定义，用于注册或注销特定的回调函数
  */
typedef enum
{
  HAL_TIM_BASE_MSPINIT_CB_ID              = 0x00U   /* 基础模式 MSP 初始化 回调 ID */
  , HAL_TIM_BASE_MSPDEINIT_CB_ID          = 0x01U   /* 基础模式 MSP 反初始化 回调 ID */
  , HAL_TIM_IC_MSPINIT_CB_ID              = 0x02U   /* 输入捕获模式 MSP 初始化 回调 ID */
  , HAL_TIM_IC_MSPDEINIT_CB_ID            = 0x03U   /* 输入捕获模式 MSP 反初始化 回调 ID */
  , HAL_TIM_OC_MSPINIT_CB_ID              = 0x04U   /* 输出比较模式 MSP 初始化 回调 ID */
  , HAL_TIM_OC_MSPDEINIT_CB_ID            = 0x05U   /* 输出比较模式 MSP 反初始化 回调 ID */
  , HAL_TIM_PWM_MSPINIT_CB_ID             = 0x06U   /* PWM 模式 MSP 初始化 回调 ID */
  , HAL_TIM_PWM_MSPDEINIT_CB_ID           = 0x07U   /* PWM 模式 MSP 反初始化 回调 ID */
  , HAL_TIM_ONE_PULSE_MSPINIT_CB_ID       = 0x08U   /* 单脉冲模式 MSP 初始化 回调 ID */
  , HAL_TIM_ONE_PULSE_MSPDEINIT_CB_ID     = 0x09U   /* 单脉冲模式 MSP 反初始化 回调 ID */
  , HAL_TIM_ENCODER_MSPINIT_CB_ID         = 0x0AU   /* 编码器模式 MSP 初始化 回调 ID */
  , HAL_TIM_ENCODER_MSPDEINIT_CB_ID       = 0x0BU   /* 编码器模式 MSP 反初始化 回调 ID */
  , HAL_TIM_HALL_SENSOR_MSPINIT_CB_ID     = 0x0CU   /* 霍尔传感器模式 MSP 初始化 回调 ID */
  , HAL_TIM_HALL_SENSOR_MSPDEINIT_CB_ID   = 0x0DU   /* 霍尔传感器模式 MSP 反初始化 回调 ID */
  , HAL_TIM_PERIOD_ELAPSED_CB_ID          = 0x0EU   /* 周期溢出 回调 ID */
  , HAL_TIM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU   /* 周期溢出半完成 回调 ID */
  , HAL_TIM_TRIGGER_CB_ID                 = 0x10U   /* 触发 回调 ID */
  , HAL_TIM_TRIGGER_HALF_CB_ID            = 0x11U   /* 触发半完成 回调 ID */
  , HAL_TIM_IC_CAPTURE_CB_ID              = 0x12U   /* 输入捕获 回调 ID */
  , HAL_TIM_IC_CAPTURE_HALF_CB_ID         = 0x13U   /* 输入捕获半完成 回调 ID */
  , HAL_TIM_OC_DELAY_ELAPSED_CB_ID        = 0x14U   /* 输出比较延迟结束 回调 ID */
  , HAL_TIM_PWM_PULSE_FINISHED_CB_ID      = 0x15U   /* PWM 脉冲完成 回调 ID */
  , HAL_TIM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U   /* PWM 脉冲完成半完成 回调 ID */
  , HAL_TIM_ERROR_CB_ID                   = 0x17U   /* 错误 回调 ID */
  , HAL_TIM_COMMUTATION_CB_ID             = 0x18U   /* 换相 回调 ID */
  , HAL_TIM_COMMUTATION_HALF_CB_ID        = 0x19U   /* 换相半完成 回调 ID */
  , HAL_TIM_BREAK_CB_ID                   = 0x1AU   /* 刹车 回调 ID */
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
#define TIM_CLEARINPUTSOURCE_NONE           0x00000000U   /* 禁用 OCREF_CLR 输入（清除输入功能关闭） */
#define TIM_CLEARINPUTSOURCE_ETR            0x00000001U   /* OCREF_CLR 输入连接到 ETRF 引脚（使用外部触发清除输出参考信号） */
/**
  * @}
  */

/** @defgroup TIM_DMA_Base_address TIM DMA 基地址
  * @{
  */
#define TIM_DMABASE_CR1                    0x00000000U    /* DMA 基地址指向控制寄存器 1 (CR1) */
#define TIM_DMABASE_CR2                    0x00000001U    /* DMA 基地址指向控制寄存器 2 (CR2) */
#define TIM_DMABASE_SMCR                   0x00000002U    /* DMA 基地址指向从模式控制寄存器 (SMCR) */
#define TIM_DMABASE_DIER                   0x00000003U    /* DMA 基地址指向 DMA/中断使能寄存器 (DIER) */
#define TIM_DMABASE_SR                     0x00000004U    /* DMA 基地址指向状态寄存器 (SR) */
#define TIM_DMABASE_EGR                    0x00000005U    /* DMA 基地址指向事件生成寄存器 (EGR) */
#define TIM_DMABASE_CCMR1                  0x00000006U    /* DMA 基地址指向捕获/比较模式寄存器 1 (CCMR1) */
#define TIM_DMABASE_CCMR2                  0x00000007U    /* DMA 基地址指向捕获/比较模式寄存器 2 (CCMR2) */
#define TIM_DMABASE_CCER                   0x00000008U    /* DMA 基地址指向捕获/比较使能寄存器 (CCER) */
#define TIM_DMABASE_CNT                    0x00000009U    /* DMA 基地址指向计数器寄存器 (CNT) */
#define TIM_DMABASE_PSC                    0x0000000AU    /* DMA 基地址指向预分频器寄存器 (PSC) */
#define TIM_DMABASE_ARR                    0x0000000BU    /* DMA 基地址指向自动重装载寄存器 (ARR) */
#define TIM_DMABASE_RCR                    0x0000000CU    /* DMA 基地址指向重复计数器寄存器 (RCR) */
#define TIM_DMABASE_CCR1                   0x0000000DU    /* DMA 基地址指向捕获/比较寄存器 1 (CCR1) */
#define TIM_DMABASE_CCR2                   0x0000000EU    /* DMA 基地址指向捕获/比较寄存器 2 (CCR2) */
#define TIM_DMABASE_CCR3                   0x0000000FU    /* DMA 基地址指向捕获/比较寄存器 3 (CCR3) */
#define TIM_DMABASE_CCR4                   0x00000010U    /* DMA 基地址指向捕获/比较寄存器 4 (CCR4) */
#define TIM_DMABASE_BDTR                   0x00000011U    /* DMA 基地址指向刹车和死区寄存器 (BDTR) */
#define TIM_DMABASE_DCR                    0x00000012U    /* DMA 基地址指向 DMA 控制寄存器 (DCR) */
#define TIM_DMABASE_DMAR                   0x00000013U    /* DMA 基地址指向 DMA 地址寄存器 (DMAR) */
/**
  * @}
  */

/** @defgroup TIM_Event_Source TIM 事件源
  * @{
  */
#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG     /* 产生更新事件：重新初始化计数器并生成寄存器更新 */
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G   /* 产生捕获/比较事件：在通道 1 上生成捕获/比较事件 */
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G   /* 产生捕获/比较事件：在通道 2 上生成捕获/比较事件 */
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G   /* 产生捕获/比较事件：在通道 3 上生成捕获/比较事件 */
#define TIM_EVENTSOURCE_CC4                 TIM_EGR_CC4G   /* 产生捕获/比较事件：在通道 4 上生成捕获/比较事件 */
#define TIM_EVENTSOURCE_COM                 TIM_EGR_COMG   /* 产生换相事件：生成换相事件 */
#define TIM_EVENTSOURCE_TRIGGER             TIM_EGR_TG     /* 产生触发事件：生成触发事件 */
#define TIM_EVENTSOURCE_BREAK               TIM_EGR_BG     /* 产生刹车事件：生成刹车事件 */
/**
  * @}
  */

/** @defgroup TIM_Input_Channel_Polarity TIM 输入通道极性
  * @{
  */
#define  TIM_INPUTCHANNELPOLARITY_RISING      0x00000000U                       /* 输入捕获上升沿极性 */
#define  TIM_INPUTCHANNELPOLARITY_FALLING     TIM_CCER_CC1P                     /* 输入捕获下降沿极性 */
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)  /* 输入捕获双边沿极性（上升沿和下降沿均捕获） */
/**
  * @}
  */

/** @defgroup TIM_ETR_Polarity TIM ETR 极性
  * @{
  */
#define TIM_ETRPOLARITY_INVERTED              TIM_SMCR_ETP                      /* ETR 极性反转：低电平或下降沿有效 */
#define TIM_ETRPOLARITY_NONINVERTED           0x00000000U                       /* ETR 极性不反转：高电平或上升沿有效 */
/**
  * @}
  */

/** @defgroup TIM_ETR_Prescaler TIM ETR 预分频
  * @{
  */
#define TIM_ETRPRESCALER_DIV1                 0x00000000U                       /* ETR 预分频：不分频 */
#define TIM_ETRPRESCALER_DIV2                 TIM_SMCR_ETPS_0                   /* ETR 预分频：2 分频 */
#define TIM_ETRPRESCALER_DIV4                 TIM_SMCR_ETPS_1                   /* ETR 预分频：4 分频 */
#define TIM_ETRPRESCALER_DIV8                 TIM_SMCR_ETPS                     /* ETR 预分频：8 分频 */
/**
  * @}
  */

/** @defgroup TIM_Counter_Mode TIM 计数模式
  * @{
  */
#define TIM_COUNTERMODE_UP                 0x00000000U                          /* 向上计数模式 */
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR                          /* 向下计数模式 */
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0                        /* 中心对齐模式 1：仅在计数器向下计数时产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1                        /* 中心对齐模式 2：仅在计数器向上计数时产生比较中断 */
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS                          /* 中心对齐模式 3：在计数器向上和向下计数时均产生比较中断 */
/**
  * @}
  */

/** @defgroup TIM_ClockDivision TIM 时钟分频
  * @{
  */
#define TIM_CLOCKDIVISION_DIV1             0x00000000U                          /* 时钟分频：tDTS = tCK_INT (不分频) */
#define TIM_CLOCKDIVISION_DIV2             TIM_CR1_CKD_0                        /* 时钟分频：tDTS = 2 * tCK_INT (2分频) */
#define TIM_CLOCKDIVISION_DIV4             TIM_CR1_CKD_1                        /* 时钟分频：tDTS = 4 * tCK_INT (4分频) */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_State TIM 输出比较状态
  * @{
  */
#define TIM_OUTPUTSTATE_DISABLE            0x00000000U                          /* 输出比较禁用：捕获/比较输出关闭 */
#define TIM_OUTPUTSTATE_ENABLE             TIM_CCER_CC1E                        /* 输出比较使能：捕获/比较输出开启 */
/**
  * @}
  */

/** @defgroup TIM_AutoReloadPreload TIM 自动重装载预装载
  * @{
  */
#define TIM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U               /* 禁用自动重装载预装载：TIMx_ARR 寄存器无缓冲，写入立即生效 */
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 TIM_CR1_ARPE              /* 使能自动重装载预装载：TIMx_ARR 寄存器有缓冲，在更新事件时写入生效 */

/**
  * @}
  */

/** @defgroup TIM_Output_Fast_State TIM 输出快速状态
  * @{
  */
#define TIM_OCFAST_DISABLE                 0x00000000U                          /* 输出比较快速模式禁用 */
#define TIM_OCFAST_ENABLE                  TIM_CCMR1_OC1FE                      /* 输出比较快速模式使能：触发输入有效时，快速设置输出 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_State TIM 互补输出比较状态
  * @{
  */
#define TIM_OUTPUTNSTATE_DISABLE           0x00000000U                          /* 互补输出禁用：OCxN 输出关闭 */
#define TIM_OUTPUTNSTATE_ENABLE            TIM_CCER_CC1NE                       /* 互补输出使能：OCxN 输出开启 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Polarity TIM 输出比较极性
  * @{
  */
#define TIM_OCPOLARITY_HIGH                0x00000000U                          /* 输出比较极性高：有效状态为高电平 */
#define TIM_OCPOLARITY_LOW                 TIM_CCER_CC1P                        /* 输出比较极性低：有效状态为低电平 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Polarity TIM 互补输出比较极性
  * @{
  */
#define TIM_OCNPOLARITY_HIGH               0x00000000U                          /* 互补输出比较极性高：有效状态为高电平 */
#define TIM_OCNPOLARITY_LOW                TIM_CCER_CC1NP                       /* 互补输出比较极性低：有效状态为低电平 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Idle_State TIM 输出比较空闲状态
  * @{
  */
#define TIM_OCIDLESTATE_SET                TIM_CR2_OIS1                         /* 空闲状态输出高电平：当 MOE=0 时，OCx=1 */
#define TIM_OCIDLESTATE_RESET              0x00000000U                          /* 空闲状态输出低电平：当 MOE=0 时，OCx=0 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Idle_State TIM 互补输出比较空闲状态
  * @{
  */
#define TIM_OCNIDLESTATE_SET               TIM_CR2_OIS1N                        /* 互补输出空闲状态高电平：当 MOE=0 时，OCxN=1 */
#define TIM_OCNIDLESTATE_RESET             0x00000000U                          /* 互补输出空闲状态低电平：当 MOE=0 时，OCxN=0 */
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Polarity TIM 输入捕获极性
  * @{
  */
#define  TIM_ICPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING      /* 输入捕获上升沿触发 */
#define  TIM_ICPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING     /* 输入捕获下降沿触发 */
#define  TIM_ICPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE    /* 输入捕获双边沿触发（上升沿和下降沿均触发捕获） */
/**
  * @}
  */

/** @defgroup TIM_Encoder_Input_Polarity TIM 编码器输入极性
  * @{
  */
#define  TIM_ENCODERINPUTPOLARITY_RISING   TIM_INPUTCHANNELPOLARITY_RISING      /* 编码器输入上升沿极性 */
#define  TIM_ENCODERINPUTPOLARITY_FALLING  TIM_INPUTCHANNELPOLARITY_FALLING     /* 编码器输入下降沿极性 */
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Selection TIM 输入捕获选择
  * @{
  */
#define TIM_ICSELECTION_DIRECTTI           TIM_CCMR1_CC1S_0                     /* 直连模式：TI1 映射到 IC1，TI2 映射到 IC2，以此类推 */
#define TIM_ICSELECTION_INDIRECTTI         TIM_CCMR1_CC1S_1                     /* 间接模式：TI1 映射到 IC2，TI2 映射到 IC1，以此类推 */
#define TIM_ICSELECTION_TRC                TIM_CCMR1_CC1S                       /* TRC 模式：输入捕获连接到 TRC 信号（内部触发输入） */
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Prescaler TIM 输入捕获预分频
  * @{
  */
#define TIM_ICPSC_DIV1                     0x00000000U                          /* 输入捕获预分频：不分频，每次检测到边沿都执行捕获 */
#define TIM_ICPSC_DIV2                     TIM_CCMR1_IC1PSC_0                   /* 输入捕获预分频：每 2 个事件执行一次捕获 */
#define TIM_ICPSC_DIV4                     TIM_CCMR1_IC1PSC_1                   /* 输入捕获预分频：每 4 个事件执行一次捕获 */
#define TIM_ICPSC_DIV8                     TIM_CCMR1_IC1PSC                     /* 输入捕获预分频：每 8 个事件执行一次捕获 */
/**
  * @}
  */

/** @defgroup TIM_One_Pulse_Mode TIM 单脉冲模式
  * @{
  */
#define TIM_OPMODE_SINGLE                  TIM_CR1_OPM                          /* 单脉冲模式：在下一个更新事件停止计数器 */
#define TIM_OPMODE_REPETITIVE              0x00000000U                          /* 重复模式：更新事件不会停止计数器 */
/**
  * @}
  */

/** @defgroup TIM_Encoder_Mode TIM 编码器模式
  * @{
  */
#define TIM_ENCODERMODE_TI1                      TIM_SMCR_SMS_0                                                      /* 编码器模式 1：TI1 计数，x2 模式，根据 TI2FP2 电平在 TI1FP1 边沿计数 */
#define TIM_ENCODERMODE_TI2                      TIM_SMCR_SMS_1                                                      /* 编码器模式 2：TI2 计数，x2 模式，根据 TI1FP1 电平在 TI2FP2 边沿计数 */
#define TIM_ENCODERMODE_TI12                     (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)                                   /* 编码器模式 3：TI1 和 TI2 均计数，x4 模式，在两个输入的边沿均计数 */
/**
  * @}
  */

/** @defgroup TIM_Interrupt_definition TIM 中断定义
  * @{
  */
#define TIM_IT_UPDATE                      TIM_DIER_UIE                         /* 更新中断使能 */
#define TIM_IT_CC1                         TIM_DIER_CC1IE                       /* 捕获/比较 1 中断使能 */
#define TIM_IT_CC2                         TIM_DIER_CC2IE                       /* 捕获/比较 2 中断使能 */
#define TIM_IT_CC3                         TIM_DIER_CC3IE                       /* 捕获/比较 3 中断使能 */
#define TIM_IT_CC4                         TIM_DIER_CC4IE                       /* 捕获/比较 4 中断使能 */
#define TIM_IT_COM                         TIM_DIER_COMIE                       /* 换相中断使能 */
#define TIM_IT_TRIGGER                     TIM_DIER_TIE                         /* 触发中断使能 */
#define TIM_IT_BREAK                       TIM_DIER_BIE                         /* 刹车中断使能 */
/**
  * @}
  */
