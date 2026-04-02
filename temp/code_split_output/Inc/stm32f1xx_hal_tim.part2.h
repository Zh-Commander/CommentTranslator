/** @defgroup TIM_Commutation_Source  TIM Commutation Source
  * @{
  */
// 定义定时器换相源选择
// 当捕获/比较控制位被预装载时，此宏定义控制更新发生的时机
#define TIM_COMMUTATION_TRGI              TIM_CR2_CCUS                          /*!< 当捕获/比较控制位被预装载时，它们可以通过设置COMG位或在触发输入上出现上升沿时更新 */
#define TIM_COMMUTATION_SOFTWARE          0x00000000U                           /*!< 当捕获/比较控制位被预装载时，它们只能通过设置COMG位（软件方式）来更新 */
/**
  * @}
  */

/** @defgroup TIM_DMA_sources TIM DMA Sources
  * @{
  */
// 定义定时器DMA请求触发源
// 每个宏定义对应一种事件，当该事件发生时，定时器会向DMA控制器发送请求
#define TIM_DMA_UPDATE                     TIM_DIER_UDE                         /*!< DMA请求由更新事件触发（如计数器溢出） */
#define TIM_DMA_CC1                        TIM_DIER_CC1DE                       /*!< DMA请求由捕获/比较匹配1事件触发 */
#define TIM_DMA_CC2                        TIM_DIER_CC2DE                       /*!< DMA请求由捕获/比较匹配2事件触发 */
#define TIM_DMA_CC3                        TIM_DIER_CC3DE                       /*!< DMA请求由捕获/比较匹配3事件触发 */
#define TIM_DMA_CC4                        TIM_DIER_CC4DE                       /*!< DMA请求由捕获/比较匹配4事件触发 */
#define TIM_DMA_COM                        TIM_DIER_COMDE                       /*!< DMA请求由换相事件触发 */
#define TIM_DMA_TRIGGER                    TIM_DIER_TDE                         /*!< DMA请求由触发事件触发 */
/**
  * @}
  */

/** @defgroup TIM_CC_DMA_Request CCx DMA request selection
  * @{
  */
// 定义捕获/比较通道（CCx）的DMA请求选择
#define TIM_CCDMAREQUEST_CC                 0x00000000U                         /*!< CCx DMA请求在发生捕获或比较匹配事件时发送 */
#define TIM_CCDMAREQUEST_UPDATE             TIM_CR2_CCDS                        /*!< CCx DMA请求在发生更新事件时发送 */
/**
  * @}
  */

/** @defgroup TIM_Flag_definition TIM Flag Definition
  * @{
  */
// 定义定时器状态标志位
// 这些标志位用于检查定时器当前的状态（如是否发生更新、是否捕获成功等）
#define TIM_FLAG_UPDATE                    TIM_SR_UIF                           /*!< 更新中断标志：当发生更新事件（如溢出）时由硬件置1 */
#define TIM_FLAG_CC1                       TIM_SR_CC1IF                         /*!< 捕获/比较1中断标志：当CC1通道发生捕获或比较匹配时置1 */
#define TIM_FLAG_CC2                       TIM_SR_CC2IF                         /*!< 捕获/比较2中断标志 */
#define TIM_FLAG_CC3                       TIM_SR_CC3IF                         /*!< 捕获/比较3中断标志 */
#define TIM_FLAG_CC4                       TIM_SR_CC4IF                         /*!< 捕获/比较4中断标志 */
#define TIM_FLAG_COM                       TIM_SR_COMIF                         /*!< 换相中断标志：当发生换相事件时置1 */
#define TIM_FLAG_TRIGGER                   TIM_SR_TIF                           /*!< 触发中断标志：当发生触发事件时置1 */
#define TIM_FLAG_BREAK                     TIM_SR_BIF                           /*!< 刹车中断标志：当检测到刹车信号时置1 */
#define TIM_FLAG_CC1OF                     TIM_SR_CC1OF                         /*!< 捕获1溢出标志：当CC1通道发生捕获溢出时置1 */
#define TIM_FLAG_CC2OF                     TIM_SR_CC2OF                         /*!< 捕获2溢出标志 */
#define TIM_FLAG_CC3OF                     TIM_SR_CC3OF                         /*!< 捕获3溢出标志 */
#define TIM_FLAG_CC4OF                     TIM_SR_CC4OF                         /*!< 捕获4溢出标志 */
/**
  * @}
  */

/** @defgroup TIM_Channel TIM Channel
  * @{
  */
// 定义定时器通道
// 用于函数参数，指定操作哪个定时器通道
#define TIM_CHANNEL_1                      0x00000000U                          /*!< 捕获/比较通道1标识 */
#define TIM_CHANNEL_2                      0x00000004U                          /*!< 捕获/比较通道2标识 */
#define TIM_CHANNEL_3                      0x00000008U                          /*!< 捕获/比较通道3标识 */
#define TIM_CHANNEL_4                      0x0000000CU                          /*!< 捕获/比较通道4标识 */
#define TIM_CHANNEL_ALL                    0x0000003CU                          /*!< 全局捕获/比较通道标识（用于同时操作多个通道） */
/**
  * @}
  */

/** @defgroup TIM_Clock_Source TIM Clock Source
  * @{
  */
// 定义定时器时钟源选择
// 定时器计数器的驱动时钟来源
#define TIM_CLOCKSOURCE_INTERNAL    TIM_SMCR_ETPS_0      /*!< 内部时钟源：通常来自RCC提供的内部时钟（如APB时钟） */
#define TIM_CLOCKSOURCE_ETRMODE1    TIM_TS_ETRF          /*!< 外部时钟源模式1：使用ETRF引脚作为时钟输入 */
#define TIM_CLOCKSOURCE_ETRMODE2    TIM_SMCR_ETPS_1      /*!< 外部时钟源模式2：使用ETR引脚作为时钟输入 */
#define TIM_CLOCKSOURCE_TI1ED       TIM_TS_TI1F_ED       /*!< 外部时钟源模式1：使用TI1边沿检测器作为时钟输入 */
#define TIM_CLOCKSOURCE_TI1         TIM_TS_TI1FP1        /*!< 外部时钟源模式1：使用TI1FP1作为时钟输入 */
#define TIM_CLOCKSOURCE_TI2         TIM_TS_TI2FP2        /*!< 外部时钟源模式1：使用TI2FP2作为时钟输入 */
#define TIM_CLOCKSOURCE_ITR0        TIM_TS_ITR0          /*!< 外部时钟源模式1：使用内部触发输入0（ITR0），通常用于定时器级联 */
#define TIM_CLOCKSOURCE_ITR1        TIM_TS_ITR1          /*!< 外部时钟源模式1：使用内部触发输入1（ITR1） */
#define TIM_CLOCKSOURCE_ITR2        TIM_TS_ITR2          /*!< 外部时钟源模式1：使用内部触发输入2（ITR2） */
#define TIM_CLOCKSOURCE_ITR3        TIM_TS_ITR3          /*!< 外部时钟源模式1：使用内部触发输入3（ITR3） */
/**
  * @}
  */

/** @defgroup TIM_Clock_Polarity TIM Clock Polarity
  * @{
  */
// 定义时钟极性选择
// 主要用于外部时钟输入时的边沿检测
#define TIM_CLOCKPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED           /*!< ETRx时钟源极性反转：下降沿或低电平有效 */
#define TIM_CLOCKPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED        /*!< ETRx时钟源极性不反转：上升沿或高电平有效 */
#define TIM_CLOCKPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING    /*!< TIx时钟源极性：上升沿有效 */
#define TIM_CLOCKPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING   /*!< TIx时钟源极性：下降沿有效 */
#define TIM_CLOCKPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE  /*!< TIx时钟源极性：双边沿有效（上升沿和下降沿都触发） */
/**
  * @}
  */

/** @defgroup TIM_Clock_Prescaler TIM Clock Prescaler
  * @{
  */
// 定义时钟预分频器
// 用于对外部时钟信号进行分频，降低计数频率
#define TIM_CLOCKPRESCALER_DIV1                 TIM_ETRPRESCALER_DIV1           /*!< 不分频：外部时钟信号直接驱动计数器 */
#define TIM_CLOCKPRESCALER_DIV2                 TIM_ETRPRESCALER_DIV2           /*!< 2分频：每2个外部事件捕获一次（计数一次） */
#define TIM_CLOCKPRESCALER_DIV4                 TIM_ETRPRESCALER_DIV4           /*!< 4分频：每4个外部事件捕获一次 */
#define TIM_CLOCKPRESCALER_DIV8                 TIM_ETRPRESCALER_DIV8           /*!< 8分频：每8个外部事件捕获一次 */
/**
  * @}
  */

/** @defgroup TIM_ClearInput_Polarity TIM Clear Input Polarity
  * @{
  */
// 定义清除输入极性
// 用于配置清除输入信号（如ETR引脚）的有效电平
#define TIM_CLEARINPUTPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED      /*!< ETRx引脚极性反转：低电平有效 */
#define TIM_CLEARINPUTPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED   /*!< ETRx引脚极性不反转：高电平有效 */
/**
  * @}
  */

/** @defgroup TIM_ClearInput_Prescaler TIM Clear Input Prescaler
  * @{
  */
// 定义清除输入预分频
// 用于配置清除输入信号的采样频率
#define TIM_CLEARINPUTPRESCALER_DIV1              TIM_ETRPRESCALER_DIV1         /*!< 不分频 */
#define TIM_CLEARINPUTPRESCALER_DIV2              TIM_ETRPRESCALER_DIV2         /*!< 2分频：每2个事件采样一次 */
#define TIM_CLEARINPUTPRESCALER_DIV4              TIM_ETRPRESCALER_DIV4         /*!< 4分频：每4个事件采样一次 */
#define TIM_CLEARINPUTPRESCALER_DIV8              TIM_ETRPRESCALER_DIV8         /*!< 8分频：每8个事件采样一次 */
/**
  * @}
  */

/** @defgroup TIM_OSSR_Off_State_Selection_for_Run_mode_state TIM OSSR OffState Selection for Run mode state
  * @{
  */
// 定义运行模式下的关闭状态选择
// 当定时器处于运行模式但通道输出处于非活动状态时，输出引脚的行为
#define TIM_OSSR_ENABLE                          TIM_BDTR_OSSR                  /*!< 使能：当通道处于非活动状态时，OC/OCN输出仍然使能，由定时器控制输出空闲电平 */
#define TIM_OSSR_DISABLE                         0x00000000U                    /*!< 禁止：当通道处于非活动状态时，OC/OCN输出被禁止，引脚变为高阻态或由GPIO控制 */
/**
  * @}
  */

/** @defgroup TIM_OSSI_Off_State_Selection_for_Idle_mode_state TIM OSSI OffState Selection for Idle mode state
  * @{
  */
// 定义空闲模式下的关闭状态选择
// 当定时器处于空闲模式（MOE位为0）时，输出引脚的行为
#define TIM_OSSI_ENABLE                          TIM_BDTR_OSSI                  /*!< 使能：当定时器处于空闲状态时，OC/OCN输出仍然使能，由定时器控制输出空闲电平 */
#define TIM_OSSI_DISABLE                         0x00000000U                    /*!< 禁止：当定时器处于空闲状态时，OC/OCN输出被禁止 */
/**
  * @}
  */
/** @defgroup TIM_Lock_level  TIM Lock level
  * @{
  */
// 定义锁定级别
// 用于防止软件错误修改关键寄存器配置，级别越高保护越严格
#define TIM_LOCKLEVEL_OFF                  0x00000000U                          /*!< 不锁定：没有写保护 */
#define TIM_LOCKLEVEL_1                    TIM_BDTR_LOCK_0                      /*!< 锁定级别1：禁止写入某些控制位 */
#define TIM_LOCKLEVEL_2                    TIM_BDTR_LOCK_1                      /*!< 锁定级别2：比级别1更多的保护 */
#define TIM_LOCKLEVEL_3                    TIM_BDTR_LOCK                        /*!< 锁定级别3：最高级别保护，禁止写入所有受保护的位 */
/**
  * @}
  */

/** @defgroup TIM_Break_Input_enable_disable TIM Break Input Enable
  * @{
  */
// 定义刹车输入使能
// 刹车功能用于在紧急情况下强制将定时器输出置为安全状态
#define TIM_BREAK_ENABLE                   TIM_BDTR_BKE                         /*!< 使能刹车输入：刹车功能开启 */
#define TIM_BREAK_DISABLE                  0x00000000U                          /*!< 禁止刹车输入：刹车功能关闭 */
/**
  * @}
  */

/** @defgroup TIM_Break_Polarity TIM Break Input Polarity
  * @{
  */
// 定义刹车输入极性
// 设置刹车信号的有效电平
#define TIM_BREAKPOLARITY_LOW              0x00000000U                          /*!< 刹车输入低电平有效 */
#define TIM_BREAKPOLARITY_HIGH             TIM_BDTR_BKP                         /*!< 刹车输入高电平有效 */
/**
  * @}
  */

/** @defgroup TIM_AOE_Bit_Set_Reset TIM Automatic Output Enable
  * @{
  */
// 定义自动输出使能
// 控制MOE（主输出使能）位如何被置位
#define TIM_AUTOMATICOUTPUT_DISABLE        0x00000000U                          /*!< 禁止自动输出：MOE位只能由软件手动置1 */
#define TIM_AUTOMATICOUTPUT_ENABLE         TIM_BDTR_AOE                         /*!< 使能自动输出：MOE位可由软件置1，或在下一个更新事件时自动置1（前提是无刹车信号） */
/**
  * @}
  */

/** @defgroup TIM_Master_Mode_Selection TIM Master Mode Selection
  * @{
  */
// 定义主模式选择
// 决定主定时器（TRGO）向从定时器发送什么信号作为触发源
#define TIM_TRGO_RESET            0x00000000U                                      /*!< 复位：TIMx_EGR.UG位用作触发输出(TRGO) */
#define TIM_TRGO_ENABLE           TIM_CR2_MMS_0                                    /*!< 使能：TIMx_CR1.CEN位（计数器使能）用作触发输出(TRGO) */
#define TIM_TRGO_UPDATE           TIM_CR2_MMS_1                                    /*!< 更新事件：更新事件用作触发输出(TRGO) */
#define TIM_TRGO_OC1              (TIM_CR2_MMS_1 | TIM_CR2_MMS_0)                  /*!< 比较匹配1：捕获/比较1发生匹配时产生TRGO */
#define TIM_TRGO_OC1REF           TIM_CR2_MMS_2                                    /*!< OC1REF信号：OC1REF信号用作触发输出(TRGO) */
#define TIM_TRGO_OC2REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_0)                  /*!< OC2REF信号：OC2REF信号用作触发输出(TRGO) */
#define TIM_TRGO_OC3REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_1)                  /*!< OC3REF信号：OC3REF信号用作触发输出(TRGO) */
#define TIM_TRGO_OC4REF           (TIM_CR2_MMS_2 | TIM_CR2_MMS_1 | TIM_CR2_MMS_0)  /*!< OC4REF信号：OC4REF信号用作触发输出(TRGO) */
/**
  * @}
  */

/** @defgroup TIM_Master_Slave_Mode TIM Master/Slave Mode
  * @{
  */
// 定义主/从模式选择
// 控制定时器是否与外部触发信号同步
#define TIM_MASTERSLAVEMODE_ENABLE         TIM_SMCR_MSM                         /*!< 使能主/从模式：定时器与触发输入同步 */
#define TIM_MASTERSLAVEMODE_DISABLE        0x00000000U                          /*!< 禁止主/从模式：无特殊同步操作 */
/**
  * @}
  */

/** @defgroup TIM_Slave_Mode TIM Slave mode
  * @{
  */
// 定义从模式选择
// 决定定时器作为从设备时如何响应触发信号
#define TIM_SLAVEMODE_DISABLE                0x00000000U                                        /*!< 禁止从模式：定时器独立运行 */
#define TIM_SLAVEMODE_RESET                  TIM_SMCR_SMS_2                                     /*!< 复位模式：触发信号到来时复位计数器 */
#define TIM_SLAVEMODE_GATED                  (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_0)                  /*!< 门控模式：触发信号为高时计数器计数，为低时停止 */
#define TIM_SLAVEMODE_TRIGGER                (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1)                  /*!< 触发模式：触发信号到来时启动计数器 */
#define TIM_SLAVEMODE_EXTERNAL1              (TIM_SMCR_SMS_2 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0) /*!< 外部时钟模式1：触发信号作为计数器的时钟源 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_and_PWM_modes TIM Output Compare and PWM Modes
  * @{
  */
// 定义输出比较和PWM模式
// 控制输出比较通道的行为
#define TIM_OCMODE_TIMING                   0x00000000U                                              /*!< 冻结模式：比较匹配不影响输出，仅产生中断/DMA请求 */
#define TIM_OCMODE_ACTIVE                   TIM_CCMR1_OC1M_0                                         /*!< 匹配时置有效电平：比较匹配时通道输出有效电平 */
#define TIM_OCMODE_INACTIVE                 TIM_CCMR1_OC1M_1                                         /*!< 匹配时置无效电平：比较匹配时通道输出无效电平 */
#define TIM_OCMODE_TOGGLE                   (TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0)                    /*!< 翻转模式：比较匹配时输出电平翻转 */
#define TIM_OCMODE_PWM1                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1)                    /*!< PWM模式1：向上计数时，CNT<CCR为有效电平，否则为无效电平 */
#define TIM_OCMODE_PWM2                     (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0) /*!< PWM模式2：向上计数时，CNT<CCR为无效电平，否则为有效电平 */
#define TIM_OCMODE_FORCED_ACTIVE            (TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_0)                    /*!< 强制有效电平：强制输出有效电平，忽略比较结果 */
#define TIM_OCMODE_FORCED_INACTIVE          TIM_CCMR1_OC1M_2                                         /*!< 强制无效电平：强制输出无效电平，忽略比较结果 */
/**
  * @}
  */

/** @defgroup TIM_Trigger_Selection TIM Trigger Selection
  * @{
  */
// 定义触发输入选择
// 选择哪个信号作为从模式的触发输入（ITR、TIx或ETR）
#define TIM_TS_ITR0          0x00000000U                                                       /*!< 内部触发输入0 (ITR0)：通常连接其他定时器的TRGO */
#define TIM_TS_ITR1          TIM_SMCR_TS_0                                                     /*!< 内部触发输入1 (ITR1) */
#define TIM_TS_ITR2          TIM_SMCR_TS_1                                                     /*!< 内部触发输入2 (ITR2) */
#define TIM_TS_ITR3          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1)                                   /*!< 内部触发输入3 (ITR3) */
#define TIM_TS_TI1F_ED       TIM_SMCR_TS_2                                                     /*!< TI1边沿检测器 (TI1F_ED) */
#define TIM_TS_TI1FP1        (TIM_SMCR_TS_0 | TIM_SMCR_TS_2)                                   /*!< 滤波后的定时器输入1 (TI1FP1) */
#define TIM_TS_TI2FP2        (TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                                   /*!< 滤波后的定时器输入2 (TI2FP2) */
#define TIM_TS_ETRF          (TIM_SMCR_TS_0 | TIM_SMCR_TS_1 | TIM_SMCR_TS_2)                   /*!< 滤波后的外部触发输入 (ETRF) */
#define TIM_TS_NONE          0x0000FFFFU                                                       /*!< 无触发选择：复位触发选择 */
/**
  * @}
  */

/** @defgroup TIM_Trigger_Polarity TIM Trigger Polarity
  * @{
  */
// 定义触发极性
// 设置触发输入信号的有效边沿
#define TIM_TRIGGERPOLARITY_INVERTED           TIM_ETRPOLARITY_INVERTED               /*!< ETRx触发源极性反转（下降沿/低电平） */
#define TIM_TRIGGERPOLARITY_NONINVERTED        TIM_ETRPOLARITY_NONINVERTED            /*!< ETRx触发源极性不反转（上升沿/高电平） */
#define TIM_TRIGGERPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING        /*!< TIxFPx或TI1_ED触发源上升沿有效 */
#define TIM_TRIGGERPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING       /*!< TIxFPx或TI1_ED触发源下降沿有效 */
#define TIM_TRIGGERPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE      /*!< TIxFPx或TI1_ED触发源双边沿有效 */
/**
  * @}
  */

/** @defgroup TIM_Trigger_Prescaler TIM Trigger Prescaler
  * @{
  */
// 定义触发预分频
// 对外部触发信号进行分频
#define TIM_TRIGGERPRESCALER_DIV1             TIM_ETRPRESCALER_DIV1             /*!< 不分频 */
#define TIM_TRIGGERPRESCALER_DIV2             TIM_ETRPRESCALER_DIV2             /*!< 2分频：每2个事件触发一次 */
#define TIM_TRIGGERPRESCALER_DIV4             TIM_ETRPRESCALER_DIV4             /*!< 4分频：每4个事件触发一次 */
#define TIM_TRIGGERPRESCALER_DIV8             TIM_ETRPRESCALER_DIV8             /*!< 8分频：每8个事件触发一次 */
/**
  * @}
  */

/** @defgroup TIM_TI1_Selection TIM TI1 Input Selection
  * @{
  */
// 定义TI1输入选择
// 决定定时器通道1的输入信号来源
#define TIM_TI1SELECTION_CH1               0x00000000U                          /*!< TIMx_CH1引脚连接到TI1输入（常规模式） */
#define TIM_TI1SELECTION_XORCOMBINATION    TIM_CR2_TI1S                         /*!< TIMx_CH1、CH2和CH3引脚异或后连接到TI1输入（异或模式） */
/**
  * @}
  */
