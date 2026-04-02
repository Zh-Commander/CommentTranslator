#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  // 以下是回调函数指针定义，用于用户自定义回调函数，而不是使用HAL库默认的弱定义回调函数
  void (* Base_MspInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM Base Msp Init Callback                              */ // 基础定时器 MSP 初始化回调
  void (* Base_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);            /*!< TIM Base Msp DeInit Callback                            */ // 基础定时器 MSP 反初始化回调
  void (* IC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM IC Msp Init Callback                                */ // 输入捕获 MSP 初始化回调
  void (* IC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM IC Msp DeInit Callback                              */ // 输入捕获 MSP 反初始化回调
  void (* OC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM OC Msp Init Callback                                */ // 输出比较 MSP 初始化回调
  void (* OC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM OC Msp DeInit Callback                              */ // 输出比较 MSP 反初始化回调
  void (* PWM_MspInitCallback)(struct __TIM_HandleTypeDef *htim);               /*!< TIM PWM Msp Init Callback                               */ // PWM MSP 初始化回调
  void (* PWM_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);             /*!< TIM PWM Msp DeInit Callback                             */ // PWM MSP 反初始化回调
  void (* OnePulse_MspInitCallback)(struct __TIM_HandleTypeDef *htim);          /*!< TIM One Pulse Msp Init Callback                         */ // 单脉冲 MSP 初始化回调
  void (* OnePulse_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM One Pulse Msp DeInit Callback                       */ // 单脉冲 MSP 反初始化回调
  void (* Encoder_MspInitCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Encoder Msp Init Callback                           */ // 编码器 MSP 初始化回调
  void (* Encoder_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);         /*!< TIM Encoder Msp DeInit Callback                         */ // 编码器 MSP 反初始化回调
  void (* HallSensor_MspInitCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM Hall Sensor Msp Init Callback                       */ // 霍尔传感器 MSP 初始化回调
  void (* HallSensor_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);      /*!< TIM Hall Sensor Msp DeInit Callback                     */ // 霍尔传感器 MSP 反初始化回调
  void (* PeriodElapsedCallback)(struct __TIM_HandleTypeDef *htim);             /*!< TIM Period Elapsed Callback                             */ // 周期溢出回调（更新事件）
  void (* PeriodElapsedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);     /*!< TIM Period Elapsed half complete Callback               */ // 周期溢出半完成回调（用于DMA模式）
  void (* TriggerCallback)(struct __TIM_HandleTypeDef *htim);                   /*!< TIM Trigger Callback                                    */ // 触发回调
  void (* TriggerHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Trigger half complete Callback                      */ // 触发半完成回调（用于DMA模式）
  void (* IC_CaptureCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM Input Capture Callback                              */ // 输入捕获回调
  void (* IC_CaptureHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM Input Capture half complete Callback                */ // 输入捕获半完成回调（用于DMA模式）
  void (* OC_DelayElapsedCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Output Compare Delay Elapsed Callback               */ // 输出比较延时结束回调
  void (* PWM_PulseFinishedCallback)(struct __TIM_HandleTypeDef *htim);         /*!< TIM PWM Pulse Finished Callback                         */ // PWM 脉冲结束回调
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim); /*!< TIM PWM Pulse Finished half complete Callback           */ // PWM 脉冲结束半完成回调（用于DMA模式）
  void (* ErrorCallback)(struct __TIM_HandleTypeDef *htim);                     /*!< TIM Error Callback                                      */ // 错误回调
  void (* CommutationCallback)(struct __TIM_HandleTypeDef *htim);               /*!< TIM Commutation Callback                                */ // 换向回调（用于电机控制）
  void (* CommutationHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);       /*!< TIM Commutation half complete Callback                  */ // 换向半完成回调（用于DMA模式）
  void (* BreakCallback)(struct __TIM_HandleTypeDef *htim);                     /*!< TIM Break Callback                                      */ // 刹车回调（用于电机控制安全保护）
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
} TIM_HandleTypeDef;

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TIM Callback ID enumeration definition
  *         HAL TIM 回调 ID 枚举定义，用于注册或注销特定的回调函数
  */
typedef enum
{
  HAL_TIM_BASE_MSPINIT_CB_ID              = 0x00U   /*!< TIM Base MspInit Callback ID                               */ // 基础定时器 MSP 初始化回调 ID
  , HAL_TIM_BASE_MSPDEINIT_CB_ID          = 0x01U   /*!< TIM Base MspDeInit Callback ID                             */ // 基础定时器 MSP 反初始化回调 ID
  , HAL_TIM_IC_MSPINIT_CB_ID              = 0x02U   /*!< TIM IC MspInit Callback ID                                 */ // 输入捕获 MSP 初始化回调 ID
  , HAL_TIM_IC_MSPDEINIT_CB_ID            = 0x03U   /*!< TIM IC MspDeInit Callback ID                               */ // 输入捕获 MSP 反初始化回调 ID
  , HAL_TIM_OC_MSPINIT_CB_ID              = 0x04U   /*!< TIM OC MspInit Callback ID                                 */ // 输出比较 MSP 初始化回调 ID
  , HAL_TIM_OC_MSPDEINIT_CB_ID            = 0x05U   /*!< TIM OC MspDeInit Callback ID                               */ // 输出比较 MSP 反初始化回调 ID
  , HAL_TIM_PWM_MSPINIT_CB_ID             = 0x06U   /*!< TIM PWM MspInit Callback ID                                */ // PWM MSP 初始化回调 ID
  , HAL_TIM_PWM_MSPDEINIT_CB_ID           = 0x07U   /*!< TIM PWM MspDeInit Callback ID                              */ // PWM MSP 反初始化回调 ID
  , HAL_TIM_ONE_PULSE_MSPINIT_CB_ID       = 0x08U   /*!< TIM One Pulse MspInit Callback ID                          */ // 单脉冲 MSP 初始化回调 ID
  , HAL_TIM_ONE_PULSE_MSPDEINIT_CB_ID     = 0x09U   /*!< TIM One Pulse MspDeInit Callback ID                        */ // 单脉冲 MSP 反初始化回调 ID
  , HAL_TIM_ENCODER_MSPINIT_CB_ID         = 0x0AU   /*!< TIM Encoder MspInit Callback ID                            */ // 编码器 MSP 初始化回调 ID
  , HAL_TIM_ENCODER_MSPDEINIT_CB_ID       = 0x0BU   /*!< TIM Encoder MspDeInit Callback ID                          */ // 编码器 MSP 反初始化回调 ID
  , HAL_TIM_HALL_SENSOR_MSPINIT_CB_ID     = 0x0CU   /*!< TIM Hall Sensor MspDeInit Callback ID                      */ // 霍尔传感器 MSP 初始化回调 ID
  , HAL_TIM_HALL_SENSOR_MSPDEINIT_CB_ID   = 0x0DU   /*!< TIM Hall Sensor MspDeInit Callback ID                      */ // 霍尔传感器 MSP 反初始化回调 ID
  , HAL_TIM_PERIOD_ELAPSED_CB_ID          = 0x0EU   /*!< TIM Period Elapsed Callback ID                             */ // 周期溢出回调 ID
  , HAL_TIM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU   /*!< TIM Period Elapsed half complete Callback ID               */ // 周期溢出半完成回调 ID
  , HAL_TIM_TRIGGER_CB_ID                 = 0x10U   /*!< TIM Trigger Callback ID                                    */ // 触发回调 ID
  , HAL_TIM_TRIGGER_HALF_CB_ID            = 0x11U   /*!< TIM Trigger half complete Callback ID                      */ // 触发半完成回调 ID
  , HAL_TIM_IC_CAPTURE_CB_ID              = 0x12U   /*!< TIM Input Capture Callback ID                              */ // 输入捕获回调 ID
  , HAL_TIM_IC_CAPTURE_HALF_CB_ID         = 0x13U   /*!< TIM Input Capture half complete Callback ID                */ // 输入捕获半完成回调 ID
  , HAL_TIM_OC_DELAY_ELAPSED_CB_ID        = 0x14U   /*!< TIM Output Compare Delay Elapsed Callback ID               */ // 输出比较延时结束回调 ID
  , HAL_TIM_PWM_PULSE_FINISHED_CB_ID      = 0x15U   /*!< TIM PWM Pulse Finished Callback ID                         */ // PWM 脉冲结束回调 ID
  , HAL_TIM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U   /*!< TIM PWM Pulse Finished half complete Callback ID           */ // PWM 脉冲结束半完成回调 ID
  , HAL_TIM_ERROR_CB_ID                   = 0x17U   /*!< TIM Error Callback ID                                      */ // 错误回调 ID
  , HAL_TIM_COMMUTATION_CB_ID             = 0x18U   /*!< TIM Commutation Callback ID                                */ // 换向回调 ID
  , HAL_TIM_COMMUTATION_HALF_CB_ID        = 0x19U   /*!< TIM Commutation half complete Callback ID                  */ // 换向半完成回调 ID
  , HAL_TIM_BREAK_CB_ID                   = 0x1AU   /*!< TIM Break Callback ID                                      */ // 刹车回调 ID
} HAL_TIM_CallbackIDTypeDef;

/**
  * @brief  HAL TIM Callback pointer definition
  *         HAL TIM 回调函数指针类型定义
  */
typedef  void (*pTIM_CallbackTypeDef)(TIM_HandleTypeDef *htim);  /*!< pointer to the TIM callback function */ // 指向 TIM 回调函数的指针

#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/
/* 导出类型结束 ----------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/* 导出常量 --------------------------------------------------------------------*/
/** @defgroup TIM_Exported_Constants TIM Exported Constants
  * @{
  */

/** @defgroup TIM_ClearInput_Source TIM Clear Input Source
  * @{
  */
// 清除输入源配置，用于 OPM 模式或从模式控制
#define TIM_CLEARINPUTSOURCE_NONE           0x00000000U   /*!< OCREF_CLR is disabled */ // 禁用清除输入，OCREF_CLR 不受影响
#define TIM_CLEARINPUTSOURCE_ETR            0x00000001U   /*!< OCREF_CLR is connected to ETRF input */ // OCREF_CLR 连接到 ETRF 输入
/**
  * @}
  */

/** @defgroup TIM_DMA_Base_address TIM DMA Base Address
  * @{
  */
// DMA 基地址定义，用于配置 DMA 传输时的寄存器起始地址
#define TIM_DMABASE_CR1                    0x00000000U  // 控制寄存器 1 (Control Register 1)
#define TIM_DMABASE_CR2                    0x00000001U  // 控制寄存器 2 (Control Register 2)
#define TIM_DMABASE_SMCR                   0x00000002U  // 从模式控制寄存器 (Slave Mode Control Register)
#define TIM_DMABASE_DIER                   0x00000003U  // DMA/中断使能寄存器
#define TIM_DMABASE_SR                     0x00000004U  // 状态寄存器
#define TIM_DMABASE_EGR                    0x00000005U  // 事件产生寄存器
#define TIM_DMABASE_CCMR1                  0x00000006U  // 捕获/比较模式寄存器 1
#define TIM_DMABASE_CCMR2                  0x00000007U  // 捕获/比较模式寄存器 2
#define TIM_DMABASE_CCER                   0x00000008U  // 捕获/比较使能寄存器
#define TIM_DMABASE_CNT                    0x00000009U  // 计数器寄存器
#define TIM_DMABASE_PSC                    0x0000000AU  // 预分频器寄存器
#define TIM_DMABASE_ARR                    0x0000000BU  // 自动重装载寄存器
#define TIM_DMABASE_RCR                    0x0000000CU  // 重复计数器寄存器
#define TIM_DMABASE_CCR1                   0x0000000DU  // 捕获/比较寄存器 1
#define TIM_DMABASE_CCR2                   0x0000000EU  // 捕获/比较寄存器 2
#define TIM_DMABASE_CCR3                   0x0000000FU  // 捕获/比较寄存器 3
#define TIM_DMABASE_CCR4                   0x00000010U  // 捕获/比较寄存器 4
#define TIM_DMABASE_BDTR                   0x00000011U  // 刹车和死区寄存器
#define TIM_DMABASE_DCR                    0x00000012U  // DMA 控制寄存器
#define TIM_DMABASE_DMAR                   0x00000013U  // DMA 地址用于全传输寄存器
/**
  * @}
  */

/** @defgroup TIM_Event_Source TIM Event Source
  * @{
  */
// 事件源定义，用于软件触发特定事件
#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG     /*!< Reinitialize the counter and generates an update of the registers */ // 产生更新事件，重新初始化计数器并更新寄存器
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G   /*!< A capture/compare event is generated on channel 1 */ // 在通道 1 产生捕获/比较事件
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G   /*!< A capture/compare event is generated on channel 2 */ // 在通道 2 产生捕获/比较事件
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G   /*!< A capture/compare event is generated on channel 3 */ // 在通道 3 产生捕获/比较事件
#define TIM_EVENTSOURCE_CC4                 TIM_EGR_CC4G   /*!< A capture/compare event is generated on channel 4 */ // 在通道 4 产生捕获/比较事件
#define TIM_EVENTSOURCE_COM                 TIM_EGR_COMG   /*!< A commutation event is generated */ // 产生换向事件
#define TIM_EVENTSOURCE_TRIGGER             TIM_EGR_TG     /*!< A trigger event is generated */ // 产生触发事件
#define TIM_EVENTSOURCE_BREAK               TIM_EGR_BG     /*!< A break event is generated */ // 产生刹车事件
/**
  * @}
  */

/** @defgroup TIM_Input_Channel_Polarity TIM Input Channel polarity
  * @{
  */
// 输入通道极性定义，用于输入捕获模式
#define  TIM_INPUTCHANNELPOLARITY_RISING      0x00000000U                       /*!< Polarity for TIx source */ // 上升沿捕获
#define  TIM_INPUTCHANNELPOLARITY_FALLING     TIM_CCER_CC1P                     /*!< Polarity for TIx source */ // 下降沿捕获
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)  /*!< Polarity for TIx source */ // 双沿捕获（上升沿和下降沿都捕获）
/**
  * @}
  */

/** @defgroup TIM_ETR_Polarity TIM ETR Polarity
  * @{
  */
// 外部触发 (ETR) 极性定义
#define TIM_ETRPOLARITY_INVERTED              TIM_SMCR_ETP                      /*!< Polarity for ETR source */ // ETR 反相：低电平或下降沿有效
#define TIM_ETRPOLARITY_NONINVERTED           0x00000000U                       /*!< Polarity for ETR source */ // ETR 不反相：高电平或上升沿有效
/**
  * @}
  */

/** @defgroup TIM_ETR_Prescaler TIM ETR Prescaler
  * @{
  */
// 外部触发 (ETR) 预分频定义，用于降低外部时钟频率
#define TIM_ETRPRESCALER_DIV1                 0x00000000U                       /*!< No prescaler is used */ // 不分频
#define TIM_ETRPRESCALER_DIV2                 TIM_SMCR_ETPS_0                   /*!< ETR input source is divided by 2 */ // 2 分频
#define TIM_ETRPRESCALER_DIV4                 TIM_SMCR_ETPS_1                   /*!< ETR input source is divided by 4 */ // 4 分频
#define TIM_ETRPRESCALER_DIV8                 TIM_SMCR_ETPS                     /*!< ETR input source is divided by 8 */ // 8 分频
/**
  * @}
  */

/** @defgroup TIM_Counter_Mode TIM Counter Mode
  * @{
  */
// 计数器模式定义
#define TIM_COUNTERMODE_UP                 0x00000000U                          /*!< Counter used as up-counter   */ // 向上计数模式
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR                          /*!< Counter used as down-counter */ // 向下计数模式
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0                        /*!< Center-aligned mode 1        */ // 中心对齐模式 1：仅在向下计数时产生比较中断
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1                        /*!< Center-aligned mode 2        */ // 中心对齐模式 2：仅在向上计数时产生比较中断
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS                          /*!< Center-aligned mode 3        */ // 中心对齐模式 3：在向上和向下计数时都产生比较中断
/**
  * @}
  */

/** @defgroup TIM_ClockDivision TIM Clock Division
  * @{
  */
// 时钟分频定义，用于配置死区时间和数字滤波器 (DTG, ETR, TIx) 的采样时钟
#define TIM_CLOCKDIVISION_DIV1             0x00000000U                          /*!< Clock division: tDTS=tCK_INT   */ // tDTS = tCK_INT (不分频)
#define TIM_CLOCKDIVISION_DIV2             TIM_CR1_CKD_0                        /*!< Clock division: tDTS=2*tCK_INT */ // tDTS = 2 * tCK_INT
#define TIM_CLOCKDIVISION_DIV4             TIM_CR1_CKD_1                        /*!< Clock division: tDTS=4*tCK_INT */ // tDTS = 4 * tCK_INT
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_State TIM Output Compare State
  * @{
  */
// 输出比较状态定义，用于使能或禁用输出
#define TIM_OUTPUTSTATE_DISABLE            0x00000000U                          /*!< Capture/Compare 1 output disabled */ // 禁用捕获/比较输出
#define TIM_OUTPUTSTATE_ENABLE             TIM_CCER_CC1E                        /*!< Capture/Compare 1 output enabled */ // 使能捕获/比较输出
/**
  * @}
  */

/** @defgroup TIM_AutoReloadPreload TIM Auto-Reload Preload
  * @{
  */
// 自动重装载预装载定义，控制 ARR 寄存器的缓冲
#define TIM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U               /*!< TIMx_ARR register is not buffered */ // 禁用 ARR 预装载，写入 ARR 的值立即生效
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 TIM_CR1_ARPE              /*!< TIMx_ARR register is buffered */ // 使能 ARR 预装载，写入 ARR 的值在下一个更新事件才生效

/**
  * @}
  */

/** @defgroup TIM_Output_Fast_State TIM Output Fast State
  * @{
  */
// 输出快速模式定义，用于在 PWM 模式下快速响应触发输入
#define TIM_OCFAST_DISABLE                 0x00000000U                          /*!< Output Compare fast disable */ // 禁用快速输出
#define TIM_OCFAST_ENABLE                  TIM_CCMR1_OC1FE                      /*!< Output Compare fast enable  */ // 使能快速输出
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_State TIM Complementary Output Compare State
  * @{
  */
// 互补输出比较状态定义，用于使能或禁用互补通道 (N 通道)
#define TIM_OUTPUTNSTATE_DISABLE           0x00000000U                          /*!< OCxN is disabled  */ // 禁用互补输出
#define TIM_OUTPUTNSTATE_ENABLE            TIM_CCER_CC1NE                       /*!< OCxN is enabled   */ // 使能互补输出
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Polarity TIM Output Compare Polarity
  * @{
  */
// 输出比较极性定义
#define TIM_OCPOLARITY_HIGH                0x00000000U                          /*!< Capture/Compare output polarity  */ // 有效电平为高电平
#define TIM_OCPOLARITY_LOW                 TIM_CCER_CC1P                        /*!< Capture/Compare output polarity  */ // 有效电平为低电平
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Polarity TIM Complementary Output Compare Polarity
  * @{
  */
// 互补输出比较极性定义
#define TIM_OCNPOLARITY_HIGH               0x00000000U                          /*!< Capture/Compare complementary output polarity */ // 互补输出有效电平为高电平
#define TIM_OCNPOLARITY_LOW                TIM_CCER_CC1NP                       /*!< Capture/Compare complementary output polarity */ // 互补输出有效电平为低电平
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Idle_State TIM Output Compare Idle State
  * @{
  */
// 输出比较空闲状态定义，用于 MOE (Main Output Enable) 为 0 时的输出电平
#define TIM_OCIDLESTATE_SET                TIM_CR2_OIS1                         /*!< Output Idle state: OCx=1 when MOE=0 */ // 空闲状态输出高电平
#define TIM_OCIDLESTATE_RESET              0x00000000U                          /*!< Output Idle state: OCx=0 when MOE=0 */ // 空闲状态输出低电平
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Idle_State TIM Complementary Output Compare Idle State
  * @{
  */
// 互补输出比较空闲状态定义
#define TIM_OCNIDLESTATE_SET               TIM_CR2_OIS1N                        /*!< Complementary output Idle state: OCxN=1 when MOE=0 */ // 互补输出空闲状态为高电平
#define TIM_OCNIDLESTATE_RESET             0x00000000U                          /*!< Complementary output Idle state: OCxN=0 when MOE=0 */ // 互补输出空闲状态为低电平
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Polarity TIM Input Capture Polarity
  * @{
  */
// 输入捕获极性定义，与输入通道极性宏定义值相同，用于输入捕获配置
#define  TIM_ICPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING      /*!< Capture triggered by rising edge on timer input                  */ // 上升沿捕获
#define  TIM_ICPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING     /*!< Capture triggered by falling edge on timer input                 */ // 下降沿捕获
#define  TIM_ICPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE    /*!< Capture triggered by both rising and falling edges on timer input*/ // 双沿捕获
/**
  * @}
  */

/** @defgroup TIM_Encoder_Input_Polarity TIM Encoder Input Polarity
  * @{
  */
// 编码器输入极性定义
#define  TIM_ENCODERINPUTPOLARITY_RISING   TIM_INPUTCHANNELPOLARITY_RISING      /*!< Encoder input with rising edge polarity  */ // 编码器输入极性为上升沿
#define  TIM_ENCODERINPUTPOLARITY_FALLING  TIM_INPUTCHANNELPOLARITY_FALLING     /*!< Encoder input with falling edge polarity */ // 编码器输入极性为下降沿
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Selection TIM Input Capture Selection
  * @{
  */
// 输入捕获通道选择定义，配置输入信号与捕获寄存器的连接关系
#define TIM_ICSELECTION_DIRECTTI           TIM_CCMR1_CC1S_0                     /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to IC1, IC2, IC3 or IC4, respectively */ // 直接连接：TI1 连 IC1, TI2 连 IC2...
#define TIM_ICSELECTION_INDIRECTTI         TIM_CCMR1_CC1S_1                     /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to IC2, IC1, IC4 or IC3, respectively */ // 间接连接：TI1 连 IC2, TI2 连 IC1...
#define TIM_ICSELECTION_TRC                TIM_CCMR1_CC1S                       /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to TRC */ // 连接到 TRC (触发模式输出)
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Prescaler TIM Input Capture Prescaler
  * @{
  */
// 输入捕获预分频定义，配置捕获事件发生的频率
#define TIM_ICPSC_DIV1                     0x00000000U                          /*!< Capture performed each time an edge is detected on the capture input */ // 无预分频，每次检测到边沿都捕获
#define TIM_ICPSC_DIV2                     TIM_CCMR1_IC1PSC_0                   /*!< Capture performed once every 2 events                                */ // 每 2 个事件捕获一次
#define TIM_ICPSC_DIV4                     TIM_CCMR1_IC1PSC_1                   /*!< Capture performed once every 4 events                                */ // 每 4 个事件捕获一次
#define TIM_ICPSC_DIV8                     TIM_CCMR1_IC1PSC                     /*!< Capture performed once every 8 events                                */ // 每 8 个事件捕获一次
/**
  * @}
  */

/** @defgroup TIM_One_Pulse_Mode TIM One Pulse Mode
  * @{
  */
// 单脉冲模式定义
#define TIM_OPMODE_SINGLE                  TIM_CR1_OPM                          /*!< Counter stops counting at the next update event */ // 单脉冲模式：在下一个更新事件停止计数
#define TIM_OPMODE_REPETITIVE              0x00000000U                          /*!< Counter is not stopped at update event          */ // 重复模式：更新事件不停止计数
/**
  * @}
  */

/** @defgroup TIM_Encoder_Mode TIM Encoder Mode
  * @{
  */
// 编码器接口模式定义
#define TIM_ENCODERMODE_TI1                      TIM_SMCR_SMS_0                                                      /*!< Quadrature encoder mode 1, x2 mode, counts up/down on TI1FP1 edge depending on TI2FP2 level  */ // 编码器模式 1：在 TI1 边沿计数，TI2 决定方向
#define TIM_ENCODERMODE_TI2                      TIM_SMCR_SMS_1                                                      /*!< Quadrature encoder mode 2, x2 mode, counts up/down on TI2FP2 edge depending on TI1FP1 level. */ // 编码器模式 2：在 TI2 边沿计数，TI1 决定方向
#define TIM_ENCODERMODE_TI12                     (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)                                   /*!< Quadrature encoder mode 3, x4 mode, counts up/down on both TI1FP1 and TI2FP2 edges depending on the level of the other input. */ // 编码器模式 3：在 TI1 和 TI2 边沿都计数 (4 倍频)
/**
  * @}
  */

/** @defgroup TIM_Interrupt_definition TIM interrupt Definition
  * @{
  */
// 中断定义，用于使能特定的定时器中断
#define TIM_IT_UPDATE                      TIM_DIER_UIE                         /*!< Update interrupt            */ // 更新中断
#define TIM_IT_CC1                         TIM_DIER_CC1IE                       /*!< Capture/Compare 1 interrupt */ // 捕获/比较 1 中断
#define TIM_IT_CC2                         TIM_DIER_CC2IE                       /*!< Capture/Compare 2 interrupt */ // 捕获/比较 2 中断
#define TIM_IT_CC3                         TIM_DIER_CC3IE                       /*!< Capture/Compare 3 interrupt */ // 捕获/比较 3 中断
#define TIM_IT_CC4                         TIM_DIER_CC4IE                       /*!< Capture/Compare 4 interrupt */ // 捕获/比较 4 中断
#define TIM_IT_COM                         TIM_DIER_COMIE                       /*!< Commutation interrupt       */ // 换向中断
#define TIM_IT_TRIGGER                     TIM_DIER_TIE                         /*!< Trigger interrupt           */ // 触发中断
#define TIM_IT_BREAK                       TIM_DIER_BIE                         /*!< Break interrupt             */ // 刹车中断
/**
  * @}
  */
