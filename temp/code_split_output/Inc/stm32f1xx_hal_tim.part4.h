/**
  * @brief  Set the TIM Autoreload Register value on runtime without calling another time any Init function.
  *         在运行时设置TIM自动重装载寄存器值，无需再次调用初始化函数。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __AUTORELOAD__ specifies the Counter register new value.
  *         指定计数器寄存器的新值（自动重装载值）。
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_SET_AUTORELOAD(__HANDLE__, __AUTORELOAD__) \
  do{                                                    \
    (__HANDLE__)->Instance->ARR = (__AUTORELOAD__);  /* 设置TIMx_ARR寄存器，决定计数器周期 */ \
    (__HANDLE__)->Init.Period = (__AUTORELOAD__);    /* 同步更新句柄中的初始化结构体参数，保持一致性 */ \
  } while(0)

/**
  * @brief  Get the TIM Autoreload Register value on runtime.
  *         在运行时获取TIM自动重装载寄存器值。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @retval 16-bit or 32-bit value of the timer auto-reload register(TIMx_ARR)
  *         返回定时器自动重装载寄存器(TIMx_ARR)的值（16位或32位）。
  */
#define __HAL_TIM_GET_AUTORELOAD(__HANDLE__)  ((__HANDLE__)->Instance->ARR)

/**
  * @brief  Set the TIM Clock Division value on runtime without calling another time any Init function.
  *         在运行时设置TIM时钟分频值，无需再次调用初始化函数。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CKD__ specifies the clock division value.
  *         指定时钟分频值。
  *          This parameter can be one of the following value:
  *          该参数可以是以下值之一：
  *            @arg TIM_CLOCKDIVISION_DIV1: tDTS=tCK_INT (不分频)
  *            @arg TIM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT (2分频)
  *            @arg TIM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT (4分频)
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_SET_CLOCKDIVISION(__HANDLE__, __CKD__) \
  do{                                                   \
    (__HANDLE__)->Instance->CR1 &= (~TIM_CR1_CKD);  /* 清除CR1寄存器中的CKD位 */ \
    (__HANDLE__)->Instance->CR1 |= (__CKD__);       /* 设置新的CKD位值 */ \
    (__HANDLE__)->Init.ClockDivision = (__CKD__);   /* 同步更新句柄中的初始化结构体参数 */ \
  } while(0)

/**
  * @brief  Get the TIM Clock Division value on runtime.
  *         在运行时获取TIM时钟分频值。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @retval The clock division can be one of the following values:
  *         返回的时钟分频值可以是以下值之一：
  *            @arg TIM_CLOCKDIVISION_DIV1: tDTS=tCK_INT
  *            @arg TIM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT
  *            @arg TIM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT
  */
#define __HAL_TIM_GET_CLOCKDIVISION(__HANDLE__)  ((__HANDLE__)->Instance->CR1 & TIM_CR1_CKD)

/**
  * @brief  Set the TIM Input Capture prescaler on runtime without calling another time HAL_TIM_IC_ConfigChannel()
  *         function.
  *         在运行时设置TIM输入捕获预分频值，无需再次调用HAL_TIM_IC_ConfigChannel()函数。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected (选择通道1)
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected (选择通道2)
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected (选择通道3)
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected (选择通道4)
  * @param  __ICPSC__ specifies the Input Capture4 prescaler new value.
  *         指定输入捕获预分频新值。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_ICPSC_DIV1: no prescaler (无预分频)
  *            @arg TIM_ICPSC_DIV2: capture is done once every 2 events (每2个事件捕获一次)
  *            @arg TIM_ICPSC_DIV4: capture is done once every 4 events (每4个事件捕获一次)
  *            @arg TIM_ICPSC_DIV8: capture is done once every 8 events (每8个事件捕获一次)
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_SET_ICPRESCALER(__HANDLE__, __CHANNEL__, __ICPSC__) \
  do{                                                    \
    TIM_RESET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__));  /* 复位指定通道的输入捕获预分频值 */ \
    TIM_SET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__), (__ICPSC__)); /* 设置指定通道的输入捕获预分频值 */ \
  } while(0)

/**
  * @brief  Get the TIM Input Capture prescaler on runtime.
  *         在运行时获取TIM输入捕获预分频值。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: get input capture 1 prescaler value (获取输入捕获1预分频值)
  *            @arg TIM_CHANNEL_2: get input capture 2 prescaler value (获取输入捕获2预分频值)
  *            @arg TIM_CHANNEL_3: get input capture 3 prescaler value (获取输入捕获3预分频值)
  *            @arg TIM_CHANNEL_4: get input capture 4 prescaler value (获取输入捕获4预分频值)
  * @retval The input capture prescaler can be one of the following values:
  *         返回输入捕获预分频值，可以是以下值之一：
  *            @arg TIM_ICPSC_DIV1: no prescaler
  *            @arg TIM_ICPSC_DIV2: capture is done once every 2 events
  *            @arg TIM_ICPSC_DIV4: capture is done once every 4 events
  *            @arg TIM_ICPSC_DIV8: capture is done once every 8 events
  */
#define __HAL_TIM_GET_ICPRESCALER(__HANDLE__, __CHANNEL__)  \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC1PSC) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC2PSC) >> 8U) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC3PSC) :\
   (((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC4PSC)) >> 8U)
   /* 根据通道号，读取CCMR1或CCMR2寄存器中对应的ICxPSC位，通道2和4需要右移8位 */

/**
  * @brief  Set the TIM Capture Compare Register value on runtime without calling another time ConfigChannel function.
  *         在运行时设置TIM捕获/比较寄存器值，无需再次调用ConfigChannel函数。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @param  __COMPARE__ specifies the Capture Compare register new value.
  *         指定捕获/比较寄存器的新值（比较值）。
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1 = (__COMPARE__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2 = (__COMPARE__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3 = (__COMPARE__)) :\
   ((__HANDLE__)->Instance->CCR4 = (__COMPARE__)))
   /* 根据通道号，设置对应的CCR寄存器值，常用于PWM占空比调节 */

/**
  * @brief  Get the TIM Capture Compare Register value on runtime.
  *         在运行时获取TIM捕获/比较寄存器值。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channel associated with the capture compare register
  *         与捕获/比较寄存器关联的TIM通道
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: get capture/compare 1 register value
  *            @arg TIM_CHANNEL_2: get capture/compare 2 register value
  *            @arg TIM_CHANNEL_3: get capture/compare 3 register value
  *            @arg TIM_CHANNEL_4: get capture/compare 4 register value
  * @retval 16-bit or 32-bit value of the capture/compare register (TIMx_CCRy)
  *         返回捕获/比较寄存器(TIMx_CCRy)的值（16位或32位）。
  */
#define __HAL_TIM_GET_COMPARE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3) :\
   ((__HANDLE__)->Instance->CCR4))

/**
  * @brief  Set the TIM Output compare preload.
  *         使能TIM输出比较预装载功能。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_ENABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1PE) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2PE) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3PE) :\
   ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4PE))
   /* 使能OCxPE位，写入CCR的值会在更新事件时才传输到影子寄存器，防止波形畸变 */

/**
  * @brief  Reset the TIM Output compare preload.
  *         禁用TIM输出比较预装载功能。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_DISABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC1PE) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC2PE) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC3PE) :\
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC4PE))
   /* 禁用OCxPE位，写入CCR的值会立即生效 */

/**
  * @brief  Enable fast mode for a given channel.
  *         使能指定通道的快速模式。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @note  When fast mode is enabled an active edge on the trigger input acts
  *        like a compare match on CCx output. Delay to sample the trigger
  *        input and to activate CCx output is reduced to 3 clock cycles.
  *        当使能快速模式时，触发输入上的有效边沿就像CCx输出上的比较匹配一样。
  *        采样触发输入和激活CCx输出的延迟减少到3个时钟周期。
  * @note  Fast mode acts only if the channel is configured in PWM1 or PWM2 mode.
  *        快速模式仅在通道配置为PWM1或PWM2模式时起作用。
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_ENABLE_OCxFAST(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1FE) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2FE) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3FE) :\
   ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4FE))

/**
  * @brief  Disable fast mode for a given channel.
  *         禁用指定通道的快速模式。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @note  When fast mode is disabled CCx output behaves normally depending
  *        on counter and CCRx values even when the trigger is ON. The minimum
  *        delay to activate CCx output when an active edge occurs on the
  *        trigger input is 5 clock cycles.
  *        当禁用快速模式时，即使触发开启，CCx输出也根据计数器和CCRx值正常表现。
  *        当触发输入上出现有效边沿时，激活CCx输出的最小延迟为5个时钟周期。
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_DISABLE_OCxFAST(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC1FE) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC2FE) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC3FE) :\
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC4FE))

/**
  * @brief  Set the Update Request Source (URS) bit of the TIMx_CR1 register.
  *         设置TIMx_CR1寄存器的更新请求源(URS)位。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @note  When the URS bit of the TIMx_CR1 register is set, only counter
  *        overflow/underflow generates an update interrupt or DMA request (if
  *        enabled)
  *        当设置TIMx_CR1寄存器的URS位时，只有计数器溢出/下溢才生成更新中断或DMA请求（如果使能）。
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_URS_ENABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1|= TIM_CR1_URS)

/**
  * @brief  Reset the Update Request Source (URS) bit of the TIMx_CR1 register.
  *         复位TIMx_CR1寄存器的更新请求源(URS)位。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @note  When the URS bit of the TIMx_CR1 register is reset, any of the
  *        following events generate an update interrupt or DMA request (if
  *        enabled):
  *        当复位TIMx_CR1寄存器的URS位时，以下任何事件都会生成更新中断或DMA请求（如果使能）：
  *           _ Counter overflow underflow (计数器溢出/下溢)
  *           _ Setting the UG bit (设置UG位)
  *           _ Update generation through the slave mode controller (通过从模式控制器生成的更新)
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_URS_DISABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1&=~TIM_CR1_URS)

/**
  * @brief  Set the TIM Capture x input polarity on runtime.
  *         在运行时设置TIM捕获通道x的输入极性。
  * @param  __HANDLE__ TIM handle.
  *         TIM句柄。
  * @param  __CHANNEL__ TIM Channels to be configured.
  *         要配置的TIM通道。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CHANNEL_1: TIM Channel 1 selected
  *            @arg TIM_CHANNEL_2: TIM Channel 2 selected
  *            @arg TIM_CHANNEL_3: TIM Channel 3 selected
  *            @arg TIM_CHANNEL_4: TIM Channel 4 selected
  * @param  __POLARITY__ Polarity for TIx source
  *         TIx输入源的极性
  *            @arg TIM_INPUTCHANNELPOLARITY_RISING: Rising Edge (上升沿)
  *            @arg TIM_INPUTCHANNELPOLARITY_FALLING: Falling Edge (下降沿)
  *            @arg TIM_INPUTCHANNELPOLARITY_BOTHEDGE: Rising and Falling Edge (双边沿)
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__)    \
  do{                                                                     \
    TIM_RESET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__));               /* 复位捕获极性设置 */ \
    TIM_SET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__), (__POLARITY__)); /* 设置新的捕获极性 */ \
  }while(0)

/** @brief  Select the Capture/compare DMA request source.
  *         选择捕获/比较DMA请求源。
  * @param  __HANDLE__ specifies the TIM Handle.
  *         指定TIM句柄。
  * @param  __CCDMA__ specifies Capture/compare DMA request source
  *         指定捕获/比较DMA请求源
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_CCDMAREQUEST_CC: CCx DMA request generated on Capture/Compare event (在捕获/比较事件上产生CCx DMA请求)
  *            @arg TIM_CCDMAREQUEST_UPDATE: CCx DMA request generated on Update event (在更新事件上产生CCx DMA请求)
  * @retval None
  *         无返回值。
  */
#define __HAL_TIM_SELECT_CCDMAREQUEST(__HANDLE__, __CCDMA__)    \
  MODIFY_REG((__HANDLE__)->Instance->CR2, TIM_CR2_CCDS, (__CCDMA__))
  /* 使用MODIFY_REG宏修改CR2寄存器的CCDS位 */

/**
  * @}
  */
/* End of exported macros ----------------------------------------------------*/
/* 导出宏结束 */

/* Private constants ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup TIM_Private_Constants TIM Private Constants
  *         TIM私有常量
  * @{
  */
/* The counter of a timer instance is disabled only if all the CCx and CCxN
   channels have been disabled */
/* 只有当所有CCx和CCxN通道都被禁用时，定时器实例的计数器才会被禁用 */
#define TIM_CCER_CCxE_MASK  ((uint32_t)(TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E))
/* 定义CCxE通道使能位的掩码（通道1-4输出使能） */
#define TIM_CCER_CCxNE_MASK ((uint32_t)(TIM_CCER_CC1NE | TIM_CCER_CC2NE | TIM_CCER_CC3NE))
/* 定义CCxNE通道使能位的掩码（通道1-3互补输出使能） */
/**
  * @}
  */
/* End of private constants --------------------------------------------------*/
/* 私有常量结束 */

/* Private macros ------------------------------------------------------------*/
/* 私有宏 ------------------------------------------------------------*/
/** @defgroup TIM_Private_Macros TIM Private Macros
  *         TIM私有宏
  * @{
  */
#define IS_TIM_CLEARINPUT_SOURCE(__MODE__)  (((__MODE__) == TIM_CLEARINPUTSOURCE_NONE)      || \
                                             ((__MODE__) == TIM_CLEARINPUTSOURCE_ETR))
/* 检查是否为有效的清除输入源：无或ETR引脚 */

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
/* 检查是否为有效的DMA基地址（用于DMA突发传输配置） */

#define IS_TIM_EVENT_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFFFF00U) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))
/* 检查是否为有效的事件源，确保高8位为0且不为0 */

#define IS_TIM_COUNTER_MODE(__MODE__)      (((__MODE__) == TIM_COUNTERMODE_UP)              || \
                                            ((__MODE__) == TIM_COUNTERMODE_DOWN)            || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED1)  || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED2)  || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED3))
/* 检查是否为有效的计数模式：向上、向下、中心对齐1/2/3 */

#define IS_TIM_CLOCKDIVISION_DIV(__DIV__)  (((__DIV__) == TIM_CLOCKDIVISION_DIV1) || \
                                            ((__DIV__) == TIM_CLOCKDIVISION_DIV2) || \
                                            ((__DIV__) == TIM_CLOCKDIVISION_DIV4))
/* 指定时钟分频因子：1分频、2分频、4分频 */

#define IS_TIM_AUTORELOAD_PRELOAD(PRELOAD) (((PRELOAD) == TIM_AUTORELOAD_PRELOAD_DISABLE) || \
                                            ((PRELOAD) == TIM_AUTORELOAD_PRELOAD_ENABLE))
/* 检查是否使能自动重装载预装载：禁用或使能 */

#define IS_TIM_FAST_STATE(__STATE__)       (((__STATE__) == TIM_OCFAST_DISABLE) || \
                                            ((__STATE__) == TIM_OCFAST_ENABLE))
/* 检查快速输出状态是否有效 */

#define IS_TIM_OC_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_OCPOLARITY_HIGH) || \
                                            ((__POLARITY__) == TIM_OCPOLARITY_LOW))
/* 检查输出比较极性是否有效：高电平有效或低电平有效 */

#define IS_TIM_OCN_POLARITY(__POLARITY__)  (((__POLARITY__) == TIM_OCNPOLARITY_HIGH) || \
                                            ((__POLARITY__) == TIM_OCNPOLARITY_LOW))
/* 检查互补输出比较极性是否有效：高电平有效或低电平有效 */

#define IS_TIM_OCIDLE_STATE(__STATE__)     (((__STATE__) == TIM_OCIDLESTATE_SET) || \
                                            ((__STATE__) == TIM_OCIDLESTATE_RESET))
/* 检查空闲状态下的输出比较电平是否有效：高电平或低电平 */

#define IS_TIM_OCNIDLE_STATE(__STATE__)    (((__STATE__) == TIM_OCNIDLESTATE_SET) || \
                                            ((__STATE__) == TIM_OCNIDLESTATE_RESET))
/* 检查空闲状态下的互补输出比较电平是否有效：高电平或低电平 */

#define IS_TIM_ENCODERINPUT_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_ENCODERINPUTPOLARITY_RISING)   || \
                                                      ((__POLARITY__) == TIM_ENCODERINPUTPOLARITY_FALLING))
/* 检查编码器输入极性是否有效：上升沿或下降沿 */

#define IS_TIM_IC_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_ICPOLARITY_RISING)   || \
                                            ((__POLARITY__) == TIM_ICPOLARITY_FALLING)  || \
                                            ((__POLARITY__) == TIM_ICPOLARITY_BOTHEDGE))
/* 检查输入捕获极性是否有效：上升沿、下降沿或双边沿 */

#define IS_TIM_IC_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_ICSELECTION_DIRECTTI) || \
                                            ((__SELECTION__) == TIM_ICSELECTION_INDIRECTTI) || \
                                            ((__SELECTION__) == TIM_ICSELECTION_TRC))
/* 检查输入捕获映射选择是否有效：直接映射、间接映射或TRC */

#define IS_TIM_IC_PRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_ICPSC_DIV1) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV2) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV4) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV8))
/* 检查输入捕获预分频值是否有效：1/2/4/8分频 */

#define IS_TIM_OPM_MODE(__MODE__)          (((__MODE__) == TIM_OPMODE_SINGLE) || \
                                            ((__MODE__) == TIM_OPMODE_REPETITIVE))
/* 检查单脉冲模式是否有效：单次或重复 */

#define IS_TIM_ENCODER_MODE(__MODE__)      (((__MODE__) == TIM_ENCODERMODE_TI1) || \
                                            ((__MODE__) == TIM_ENCODERMODE_TI2) || \
                                            ((__MODE__) == TIM_ENCODERMODE_TI12))
/* 检查编码器接口模式是否有效：TI1、TI2或TI1和TI2 */

#define IS_TIM_DMA_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFF80FFU) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))
/* 检查DMA请求源是否有效 */

#define IS_TIM_CHANNELS(__CHANNEL__)       (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_2) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_3) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_4) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_ALL))
/* 检查通道号是否有效：通道1-4或全部通道 */

#define IS_TIM_OPM_CHANNELS(__CHANNEL__)   (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_2))
/* 检查单脉冲模式通道是否有效：仅通道1和通道2支持 */

#define IS_TIM_PERIOD(__PERIOD__)      (((__PERIOD__) > 0U) && ((__PERIOD__) <= 0xFFFFU))
/* 检查周期值(ARR)是否在有效范围内：0到0xFFFF */

#define IS_TIM_COMPLEMENTARY_CHANNELS(__CHANNEL__) (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                                    ((__CHANNEL__) == TIM_CHANNEL_2) || \
                                                    ((__CHANNEL__) == TIM_CHANNEL_3))
/* 检查是否为有效的互补通道：通道1-3支持互补输出 */
