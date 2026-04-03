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
