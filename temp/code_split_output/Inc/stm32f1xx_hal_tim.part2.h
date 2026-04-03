/** @defgroup TIM_Commutation_Source  TIM 换相源
  * @{
  */
#define TIM_COMMUTATION_TRGI              TIM_CR2_CCUS                          /*!< 当捕获/比较控制位被预装载时，通过设置COMG位或触发输入出现上升沿来更新 */
#define TIM_COMMUTATION_SOFTWARE          0x00000000U                           /*!< 当捕获/比较控制位被预装载时，仅通过设置COMG位来更新 */
/**
  * @}
  */

/** @defgroup TIM_DMA_sources TIM DMA 源
  * @{
  */
#define TIM_DMA_UPDATE                     TIM_DIER_UDE                         /*!< DMA请求由更新事件触发 */
#define TIM_DMA_CC1                        TIM_DIER_CC1DE                       /*!< DMA请求由捕获/比较匹配1事件触发 */
#define TIM_DMA_CC2                        TIM_DIER_CC2DE                       /*!< DMA请求由捕获/比较匹配2事件触发 */
#define TIM_DMA_CC3                        TIM_DIER_CC3DE                       /*!< DMA请求由捕获/比较匹配3事件触发 */
#define TIM_DMA_CC4                        TIM_DIER_CC4DE                       /*!< DMA请求由捕获/比较匹配4事件触发 */
#define TIM_DMA_COM                        TIM_DIER_COMDE                       /*!< DMA请求由换相事件触发 */
#define TIM_DMA_TRIGGER                    TIM_DIER_TDE                         /*!< DMA请求由触发事件触发 */
/**
  * @}
  */

/** @defgroup TIM_CC_DMA_Request 捕获/比较通道 DMA 请求选择
  * @{
  */
#define TIM_CCDMAREQUEST_CC                 0x00000000U                         /*!< 当发生捕获或比较匹配事件时发送CCx DMA请求 */
#define TIM_CCDMAREQUEST_UPDATE             TIM_CR2_CCDS                        /*!< 当发生更新事件时发送CCx DMA请求 */
/**
  * @}
  */

/** @defgroup TIM_Flag_definition TIM 标志定义
  * @{
  */
#define TIM_FLAG_UPDATE                    TIM_SR_UIF                           /*!< 更新中断标志 */
#define TIM_FLAG_CC1                       TIM_SR_CC1IF                         /*!< 捕获/比较1中断标志 */
#define TIM_FLAG_CC2                       TIM_SR_CC2IF                         /*!< 捕获/比较2中断标志 */
#define TIM_FLAG_CC3                       TIM_SR_CC3IF                         /*!< 捕获/比较3中断标志 */
#define TIM_FLAG_CC4                       TIM_SR_CC4IF                         /*!< 捕获/比较4中断标志 */
#define TIM_FLAG_COM                       TIM_SR_COMIF                         /*!< 换相中断标志 */
#define TIM_FLAG_TRIGGER                   TIM_SR_TIF                           /*!< 触发中断标志 */
#define TIM_FLAG_BREAK                     TIM_SR_BIF                           /*!< 刹车中断标志 */
#define TIM_FLAG_CC1OF                     TIM_SR_CC1OF                         /*!< 捕获1过捕获标志 */
#define TIM_FLAG_CC2OF                     TIM_SR_CC2OF                         /*!< 捕获2过捕获标志 */
#define TIM_FLAG_CC3OF                     TIM_SR_CC3OF                         /*!< 捕获3过捕获标志 */
#define TIM_FLAG_CC4OF                     TIM_SR_CC4OF                         /*!< 捕获4过捕获标志 */
/**
  * @}
  */

/** @defgroup TIM_Channel TIM 通道
  * @{
  */
#define TIM_CHANNEL_1                      0x00000000U                          /*!< 捕获/比较通道1标识 */
#define TIM_CHANNEL_2                      0x00000004U                          /*!< 捕获/比较通道2标识 */
#define TIM_CHANNEL_3                      0x00000008U                          /*!< 捕获/比较通道3标识 */
#define TIM_CHANNEL_4                      0x0000000CU                          /*!< 捕获/比较通道4标识 */
#define TIM_CHANNEL_ALL                    0x0000003CU                          /*!< 全局捕获/比较通道标识 */
/**
  * @}
  */

/** @defgroup TIM_Clock_Source TIM 时钟源
  * @{
  */
#define TIM_CLOCKSOURCE_INTERNAL    TIM_SMCR_ETPS_0      /*!< 内部时钟源 */
#define TIM_CLOCKSOURCE_ETRMODE1    TIM_TS_ETRF          /*!< 外部时钟源模式1 (ETRF) */
#define TIM_CLOCKSOURCE_ETRMODE2    TIM_SMCR_ETPS_1      /*!< 外部时钟源模式2 */
#define TIM_CLOCKSOURCE_TI1ED       TIM_TS_TI1F_ED       /*!< 外部时钟源模式1 (TTI1FP1 + 边沿检测) */
#define TIM_CLOCKSOURCE_TI1         TIM_TS_TI1FP1        /*!< 外部时钟源模式1 (TTI1FP1) */
#define TIM_CLOCKSOURCE_TI2         TIM_TS_TI2FP2        /*!< 外部时钟源模式1 (TTI2FP2) */
#define TIM_CLOCKSOURCE_ITR0        TIM_TS_ITR0          /*!< 外部时钟源模式1 (ITR0) */
#define TIM_CLOCKSOURCE_ITR1        TIM_TS_ITR1          /*!< 外部时钟源模式1 (ITR1) */
#define TIM_CLOCKSOURCE_ITR2        TIM_TS_ITR2          /*!< 外部时钟源模式1 (ITR2) */
#define TIM_CLOCKSOURCE_ITR3        TIM_TS_ITR3          /*!< 外部时钟源模式1 (ITR3) */
/**
  * @}
  */

/** @defgroup TIM_Clock_Polarity TIM 时钟极性
  * @{
  */
#define TIM_CLOCKPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED           /*!< ETRx时钟源的反转极性 */
#define TIM_CLOCKPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED        /*!< ETRx时钟源的非反转极性 */
#define TIM_CLOCKPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING    /*!< TIx时钟源的上升沿极性 */
#define TIM_CLOCKPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING   /*!< TIx时钟源的下降沿极性 */
#define TIM_CLOCKPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE  /*!< TIx时钟源的双边沿极性 */
/**
  * @}
  */

/** @defgroup TIM_Clock_Prescaler TIM 时钟预分频
  * @{
  */
#define TIM_CLOCKPRESCALER_DIV1                 TIM_ETRPRESCALER_DIV1           /*!< 不使用预分频 */
#define TIM_CLOCKPRESCALER_DIV2                 TIM_ETRPRESCALER_DIV2           /*!< 外部ETR时钟预分频：每2个事件捕获一次 */
#define TIM_CLOCKPRESCALER_DIV4                 TIM_ETRPRESCALER_DIV4           /*!< 外部ETR时钟预分频：每4个事件捕获一次 */
#define TIM_CLOCKPRESCALER_DIV8                 TIM_ETRPRESCALER_DIV8           /*!< 外部ETR时钟预分频：每8个事件捕获一次 */
/**
  * @}
  */

/** @defgroup TIM_ClearInput_Polarity TIM 清除输入极性
  * @{
  */
#define TIM_CLEARINPUTPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED      /*!< ETRx引脚的反转极性 */
#define TIM_CLEARINPUTPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED   /*!< ETRx引脚的非反转极性 */
/**
  * @}
  */

/** @defgroup TIM_ClearInput_Prescaler TIM 清除输入预分频
  * @{
  */
#define TIM_CLEARINPUTPRESCALER_DIV1              TIM_ETRPRESCALER_DIV1         /*!< 不使用预分频 */
#define TIM_CLEARINPUTPRESCALER_DIV2              TIM_ETRPRESCALER_DIV2         /*!< 外部ETR引脚预分频：每2个事件捕获一次 */
#define TIM_CLEARINPUTPRESCALER_DIV4              TIM_ETRPRESCALER_DIV4         /*!< 外部ETR引脚预分频：每4个事件捕获一次 */
#define TIM_CLEARINPUTPRESCALER_DIV8              TIM_ETRPRESCALER_DIV8         /*!< 外部ETR引脚预分频：每8个事件捕获一次 */
/**
  * @}
  */

/** @defgroup TIM_OSSR_Off_State_Selection_for_Run_mode_state TIM 运行模式下的关闭状态选择
  * @{
  */
#define TIM_OSSR_ENABLE                          TIM_BDTR_OSSR                  /*!< 当不活动时，OC/OCN输出被使能（仍由定时器控制） */
#define TIM_OSSR_DISABLE                         0x00000000U                    /*!< 当不活动时，OC/OCN输出被禁用（不再由定时器控制） */
/**
  * @}
  */

/** @defgroup TIM_OSSI_Off_State_Selection_for_Idle_mode_state TIM 空闲模式下的关闭状态选择
  * @{
  */
#define TIM_OSSI_ENABLE                          TIM_BDTR_OSSI                  /*!< 当不活动时，OC/OCN输出被使能（仍由定时器控制） */
#define TIM_OSSI_DISABLE                         0x00000000U                    /*!< 当不活动时，OC/OCN输出被禁用（不再由定时器控制） */
/**
  * @}
  */
/** @defgroup TIM_Lock_level  TIM 锁定级别
  * @{
  */
#define TIM_LOCKLEVEL_OFF                  0x00000000U                          /*!< 锁定关闭 */
#define TIM_LOCKLEVEL_1                    TIM_BDTR_LOCK_0                      /*!< 锁定级别1 */
#define TIM_LOCKLEVEL_2                    TIM_BDTR_LOCK_1                      /*!< 锁定级别2 */
#define TIM_LOCKLEVEL_3                    TIM_BDTR_LOCK                        /*!< 锁定级别3 */
/**
  * @}
  */

/** @defgroup TIM_Break_Input_enable_disable TIM 刹车输入使能
  * @{
  */
#define TIM_BREAK_ENABLE                   TIM_BDTR_BKE                         /*!< 刹车输入BRK使能 */
#define TIM_BREAK_DISABLE                  0x00000000U                          /*!< 刹车输入BRK禁用 */
/**
  * @}
  */

/** @defgroup TIM_Break_Polarity TIM 刹车输入极性
  * @{
  */
#define TIM_BREAKPOLARITY_LOW              0x00000000U                          /*!< 刹车输入BRK低电平有效 */
#define TIM_BREAKPOLARITY_HIGH             TIM_BDTR_BKP                         /*!< 刹车输入BRK高电平有效 */
/**
  * @}
  */

/** @defgroup TIM_AOE_Bit_Set_Reset TIM 自动输出使能
  * @{
  */
#define TIM_AUTOMATICOUTPUT_DISABLE        0x00000000U                          /*!< MOE位仅能通过软件设置 */
#define TIM_AUTOMATICOUTPUT_ENABLE         TIM_BDTR_AOE                         /*!< MOE位可以通过软件设置，或在下一个更新事件时自动设置（前提是没有刹车输入BRK和BRK2处于活动状态） */
/**
  * @}
  */

/** @defgroup TIM_Master_Mode_Selection TIM 主模式选择
  * @{
  */
#define TIM_TRGO_RESET            0x00000000U                                      /*!< TIMx_EGR.UG位被用作触发输出(TRGO) */
#define TIM_TRGO_ENABLE           TIM_CR2_MMS_0                                    /*!< TIMx_CR1.CEN位被用作触发输出(TRGO) */
#define TIM_TRGO_UPDATE           TIM_CR2_MMS_1                                    /*!< 更新事件被用作触发输出(TRGO) */
#define TIM_TRGO_OC1              (TIM_CR2_MMS_1 | TIM_CR2_MMS_0)                  /*!< 捕获或比较匹配1被用作触发输出(TRGO) */
#define TIM_TRGO_OC1REF           TIM_CR2_MMS_2                                    /*!< OC1REF信号被用作触发输出(TRGO) */
#define TIM_TRGO_OC2REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_0)                  /*!< OC2REF信号被用作触发输出(TRGO) */
#define TIM_TRGO_OC3REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_1)                  /*!< OC3REF信号被用作触发输出(TRGO) */
#define TIM_TRGO_OC4REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_1 | TIM_CR2_MMS_0)  /*!< OC4REF信号被用作触发输出(TRGO) */
/**
  * @}
  */

/** @defgroup TIM_Master_Slave_Mode TIM 主/从模式
  * @{
  */
#define TIM_MASTERSLAVEMODE_ENABLE         TIM_SMCR_MSM                         /*!< 启用主/从模式 */
#define TIM_MASTERSLAVEMODE_DISABLE        0x00000000U                          /*!< 禁用主/从模式 */
/**
  * @}
  */

/** @defgroup TIM_Slave_Mode TIM 从模式
  * @{
  */
#define TIM_SLAVEMODE_DISABLE                0x00000000U                                        /*!< 从模式禁用 */
#define TIM_SLAVEMODE_RESET                  TIM_SMCR_SMS_2                                     /*!< 复位模式 */
#define TIM_SLAVEMODE_GATED                  (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0)                  /*!< 门控模式 */
#define TIM_SLAVEMODE_TRIGGER                (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1)                  /*!< 触发模式 */
#define TIM_SLAVEMODE_EXTERNAL1              (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0) /*!< 外部时钟模式1 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_and_PWM_modes TIM 输出比较和 PWM 模式
  * @{
  */
#define TIM_OCMODE_TIMING                   0x00000000U                                              /*!< 冻结模式（比较匹配时输出不变） */
#define TIM_OCMODE_ACTIVE                   TIM_CCMR1_OC1M_0                                         /*!< 匹配时将通道设置为有效电平 */
#define TIM_OCMODE_INACTIVE                 TIM_CCMR1_OC1M_1                                         /*!< 匹配时将通道设置为无效电平 */
#define TIM_OCMODE_TOGGLE                   (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)                    /*!< 翻转模式（匹配时输出电平翻转） */
#define TIM_OCMODE_PWM1                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1)                    /*!< PWM模式1 */
#define TIM_OCMODE_PWM2                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0) /*!< PWM模式2 */
#define TIM_OCMODE_FORCED_ACTIVE            (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0)                    /*!< 强制为有效电平 */
#define TIM_OCMODE_FORCED_INACTIVE          TIM_CCMR1_OC1M_2                                         /*!< 强制为无效电平 */
/**
  * @}
  */

/** @defgroup TIM_Trigger_Selection TIM 触发选择
  * @{
  */
#define TIM_TS_ITR0          0x00000000U                                                       /*!< 内部触发0 (ITR0) */
#define TIM_TS_ITR1          TIM_SMCR_TS_0                                                     /*!< 内部触发1 (ITR1) */
#define TIM_TS_ITR2          TIM_SMCR_TS_1                                                     /*!< 内部触发2 (ITR2) */
#define TIM_TS_ITR3          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1)                                   /*!< 内部触发3 (ITR3) */
#define TIM_TS_TI1F_ED       TIM_SMCR_TS_2                                                     /*!< TI1边沿检测器 (TI1F_ED) */
#define TIM_TS_TI1FP1        (TIM_SMCR_TS_0 | TIM_SMCR_TS_2)                                   /*!< 滤波后的定时器输入1 (TI1FP1) */
#define TIM_TS_TI2FP2        (TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                                   /*!< 滤波后的定时器输入2 (TI2FP2) */
#define TIM_TS_ETRF          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                   /*!< 滤波后的外部触发输入 (ETRF) */
#define TIM_TS_NONE          0x0000FFFFU                                                       /*!< 未选择触发源 */
/**
  * @}
  */

/** @defgroup TIM_Trigger_Polarity TIM 触发极性
  * @{
  */
#define TIM_TRIGGERPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED               /*!< ETRx触发源的反转极性 */
#define TIM_TRIGGERPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED            /*!< ETRx触发源的非反转极性 */
#define TIM_TRIGGERPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING        /*!< TIxFPx或TI1_ED触发源的上升沿极性 */
#define TIM_TRIGGERPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING       /*!< TIxFPx或TI1_ED触发源的下降沿极性 */
#define TIM_TRIGGERPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE      /*!< TIxFPx或TI1_ED触发源的双边沿极性 */
/**
  * @}
  */

/** @defgroup TIM_Trigger_Prescaler TIM 触发预分频
  * @{
  */
#define TIM_TRIGGERPRESCALER_DIV1             TIM_ETRPRESCALER_DIV1             /*!< 不使用预分频 */
#define TIM_TRIGGERPRESCALER_DIV2             TIM_ETRPRESCALER_DIV2             /*!< 外部ETR触发预分频：每2个事件捕获一次 */
#define TIM_TRIGGERPRESCALER_DIV4             TIM_ETRPRESCALER_DIV4             /*!< 外部ETR触发预分频：每4个事件捕获一次 */
#define TIM_TRIGGERPRESCALER_DIV8             TIM_ETRPRESCALER_DIV8             /*!< 外部ETR触发预分频：每8个事件捕获一次 */
/**
  * @}
  */

/** @defgroup TIM_TI1_Selection TIM TI1 输入选择
  * @{
  */
#define TIM_TI1SELECTION_CH1               0x00000000U                          /*!< TIMx_CH1引脚连接到TI1输入 */
#define TIM_TI1SELECTION_XORCOMBINATION    TIM_CR2_TI1S                         /*!< TIMx_CH1、CH2和CH3引脚连接到TI1输入（异或组合） */
/**
  * @}
  */
