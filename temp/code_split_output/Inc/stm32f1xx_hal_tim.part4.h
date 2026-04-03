/**
  * @brief  在运行时设置TIM自动重装载寄存器值，无需再次调用初始化函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __AUTORELOAD__: 指定计数器寄存器的新值。
  * @retval 无
  */
#define __HAL_TIM_SET_AUTORELOAD(__HANDLE__, __AUTORELOAD__) \
  do{                                                    \
    (__HANDLE__)->Instance->ARR = (__AUTORELOAD__);  \ /* 将新的自动重装载值写入ARR寄存器 */
    (__HANDLE__)->Init.Period = (__AUTORELOAD__);    \ /* 同步更新句柄中的初始化结构体参数 */
  } while(0)

/**
  * @brief  在运行时获取TIM自动重装载寄存器值。
  * @param  __HANDLE__: TIM句柄。
  * @retval 16位或32位的定时器自动重装载寄存器值(TIMx_ARR)
  */
#define __HAL_TIM_GET_AUTORELOAD(__HANDLE__)  ((__HANDLE__)->Instance->ARR)

/**
  * @brief  在运行时设置TIM时钟分频值，无需再次调用初始化函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CKD__: 指定时钟分频值。
  *          该参数可以是以下值之一:
  *            @arg TIM_CLOCKDIVISION_DIV1: tDTS=tCK_INT (不分频)
  *            @arg TIM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT (2分频)
  *            @arg TIM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT (4分频)
  * @retval 无
  */
#define __HAL_TIM_SET_CLOCKDIVISION(__HANDLE__, __CKD__) \
  do{                                                   \
    (__HANDLE__)->Instance->CR1 &= (~TIM_CR1_CKD);  \ /* 清除CR1寄存器中的CKD位 */
    (__HANDLE__)->Instance->CR1 |= (__CKD__);       \ /* 设置新的CKD位值 */
    (__HANDLE__)->Init.ClockDivision = (__CKD__);   \ /* 同步更新句柄中的初始化结构体参数 */
  } while(0)

/**
  * @brief  在运行时获取TIM时钟分频值。
  * @param  __HANDLE__: TIM句柄。
  * @retval 时钟分频值，可以是以下值之一:
  *            @arg TIM_CLOCKDIVISION_DIV1: tDTS=tCK_INT
  *            @arg TIM_CLOCKDIVISION_DIV2: tDTS=2*tCK_INT
  *            @arg TIM_CLOCKDIVISION_DIV4: tDTS=4*tCK_INT
  */
#define __HAL_TIM_GET_CLOCKDIVISION(__HANDLE__)  ((__HANDLE__)->Instance->CR1 & TIM_CR1_CKD)

/**
  * @brief  在运行时设置TIM输入捕获预分频值，无需再次调用HAL_TIM_IC_ConfigChannel()函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @param  __ICPSC__: 指定输入捕获预分频新值。
  *          该参数可以是以下值之一:
  *            @arg TIM_ICPSC_DIV1: 无预分频
  *            @arg TIM_ICPSC_DIV2: 每2个事件捕获一次
  *            @arg TIM_ICPSC_DIV4: 每4个事件捕获一次
  *            @arg TIM_ICPSC_DIV8: 每8个事件捕获一次
  * @retval 无
  */
#define __HAL_TIM_SET_ICPRESCALER(__HANDLE__, __CHANNEL__, __ICPSC__) \
  do{                                                    \
    TIM_RESET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__));  \ /* 复位指定通道的输入捕获预分频值 */
    TIM_SET_ICPRESCALERVALUE((__HANDLE__), (__CHANNEL__), (__ICPSC__)); \ /* 设置指定通道的输入捕获预分频值 */
  } while(0)

/**
  * @brief  在运行时获取TIM输入捕获预分频值。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 获取输入捕获1预分频值
  *            @arg TIM_CHANNEL_2: 获取输入捕获2预分频值
  *            @arg TIM_CHANNEL_3: 获取输入捕获3预分频值
  *            @arg TIM_CHANNEL_4: 获取输入捕获4预分频值
  * @retval 输入捕获预分频值，可以是以下值之一:
  *            @arg TIM_ICPSC_DIV1: 无预分频
  *            @arg TIM_ICPSC_DIV2: 每2个事件捕获一次
  *            @arg TIM_ICPSC_DIV4: 每4个事件捕获一次
  *            @arg TIM_ICPSC_DIV8: 每8个事件捕获一次
  */
#define __HAL_TIM_GET_ICPRESCALER(__HANDLE__, __CHANNEL__)  \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC1PSC) :\ /* 如果是通道1，读取CCMR1的IC1PSC位 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (((__HANDLE__)->Instance->CCMR1 & TIM_CCMR1_IC2PSC) >> 8U) :\ /* 如果是通道2，读取CCMR1的IC2PSC位并右移8位 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC3PSC) :\ /* 如果是通道3，读取CCMR2的IC3PSC位 */
   (((__HANDLE__)->Instance->CCMR2 & TIM_CCMR2_IC4PSC)) >> 8U) /* 如果是通道4，读取CCMR2的IC4PSC位并右移8位 */

/**
  * @brief  在运行时设置TIM捕获/比较寄存器值，无需再次调用ConfigChannel函数。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @param  __COMPARE__: 指定捕获比较寄存器新值。
  * @retval 无
  */
#define __HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1 = (__COMPARE__)) :\ /* 如果是通道1，设置CCR1寄存器 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2 = (__COMPARE__)) :\ /* 如果是通道2，设置CCR2寄存器 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3 = (__COMPARE__)) :\ /* 如果是通道3，设置CCR3寄存器 */
   ((__HANDLE__)->Instance->CCR4 = (__COMPARE__))) /* 如果是通道4，设置CCR4寄存器 */

/**
  * @brief  在运行时获取TIM捕获/比较寄存器值。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 与捕获比较寄存器关联的TIM通道
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 获取捕获/比较1寄存器值
  *            @arg TIM_CHANNEL_2: 获取捕获/比较2寄存器值
  *            @arg TIM_CHANNEL_3: 获取捕获/比较3寄存器值
  *            @arg TIM_CHANNEL_4: 获取捕获/比较4寄存器值
  * @retval 16位或32位的捕获/比较寄存器值(TIMx_CCRy)
  */
#define __HAL_TIM_GET_COMPARE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCR1) :\ /* 如果是通道1，读取CCR1寄存器 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCR2) :\ /* 如果是通道2，读取CCR2寄存器 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCR3) :\ /* 如果是通道3，读取CCR3寄存器 */
   ((__HANDLE__)->Instance->CCR4)) /* 如果是通道4，读取CCR4寄存器 */

/**
  * @brief  设置TIM输出比较预装载。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @retval 无
  */
#define __HAL_TIM_ENABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1PE) :\ /* 通道1：使能CCR1预装载 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2PE) :\ /* 通道2：使能CCR2预装载 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3PE) :\ /* 通道3：使能CCR3预装载 */
   ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4PE)) /* 通道4：使能CCR4预装载 */

/**
  * @brief  复位TIM输出比较预装载。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @retval 无
  */
#define __HAL_TIM_DISABLE_OCxPRELOAD(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC1PE) :\ /* 通道1：禁能CCR1预装载 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC2PE) :\ /* 通道2：禁能CCR2预装载 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC3PE) :\ /* 通道3：禁能CCR3预装载 */
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC4PE)) /* 通道4：禁能CCR4预装载 */

/**
  * @brief  使能指定通道的快速模式。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @note  当快速模式使能时，触发输入上的有效边沿就像CCx输出上的比较匹配一样。
  *        采样触发输入和激活CCx输出的延迟减少到3个时钟周期。
  * @note  快速模式仅在通道配置为PWM1或PWM2模式时起作用。
  * @retval 无
  */
#define __HAL_TIM_ENABLE_OCxFAST(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC1FE) :\ /* 通道1：使能快速模式 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= TIM_CCMR1_OC2FE) :\ /* 通道2：使能快速模式 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC3FE) :\ /* 通道3：使能快速模式 */
   ((__HANDLE__)->Instance->CCMR2 |= TIM_CCMR2_OC4FE)) /* 通道4：使能快速模式 */

/**
  * @brief  禁能指定通道的快速模式。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @note  当快速模式禁能时，即使触发开启，CCx输出也取决于计数器和CCRx值正常表现。
  *        当触发输入上出现有效边沿时，激活CCx输出的最小延迟为5个时钟周期。
  * @retval 无
  */
#define __HAL_TIM_DISABLE_OCxFAST(__HANDLE__, __CHANNEL__)    \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC1FE) :\ /* 通道1：禁能快速模式 */
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_OC2FE) :\ /* 通道2：禁能快速模式 */
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC3FE) :\ /* 通道3：禁能快速模式 */
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_OC4FE)) /* 通道4：禁能快速模式 */

/**
  * @brief  设置TIMx_CR1寄存器的更新请求源(URS)位。
  * @param  __HANDLE__: TIM句柄。
  * @note  当TIMx_CR1寄存器的URS位置1时，只有计数器溢出/下溢才生成更新中断或DMA请求(如果使能)。
  * @retval 无
  */
#define __HAL_TIM_URS_ENABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1|= TIM_CR1_URS)

/**
  * @brief  复位TIMx_CR1寄存器的更新请求源(URS)位。
  * @param  __HANDLE__: TIM句柄。
  * @note  当TIMx_CR1寄存器的URS位复位时，以下任何事件都会生成更新中断或DMA请求(如果使能):
  *           _ 计数器溢出下溢
  *           _ 设置UG位
  *           _ 通过从模式控制器生成的更新
  * @retval 无
  */
#define __HAL_TIM_URS_DISABLE(__HANDLE__)  ((__HANDLE__)->Instance->CR1&=~TIM_CR1_URS)

/**
  * @brief  在运行时设置TIM捕获x输入极性。
  * @param  __HANDLE__: TIM句柄。
  * @param  __CHANNEL__: 待配置的TIM通道。
  *          该参数可以是以下值之一:
  *            @arg TIM_CHANNEL_1: 选择TIM通道1
  *            @arg TIM_CHANNEL_2: 选择TIM通道2
  *            @arg TIM_CHANNEL_3: 选择TIM通道3
  *            @arg TIM_CHANNEL_4: 选择TIM通道4
  * @param  __POLARITY__: TIx源的极性
  *            @arg TIM_INPUTCHANNELPOLARITY_RISING: 上升沿
  *            @arg TIM_INPUTCHANNELPOLARITY_FALLING: 下降沿
  *            @arg TIM_INPUTCHANNELPOLARITY_BOTHEDGE: 双边沿(上升沿和下降沿)
  * @retval 无
  */
#define __HAL_TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__)    \
  do{                                                                     \
    TIM_RESET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__));               \ /* 复位捕获极性设置 */
    TIM_SET_CAPTUREPOLARITY((__HANDLE__), (__CHANNEL__), (__POLARITY__)); \ /* 设置新的捕获极性 */
  }while(0)

/** @brief  选择捕获/比较DMA请求源。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __CCDMA__: 指定捕获/比较DMA请求源
  *          该参数可以是以下值之一:
  *            @arg TIM_CCDMAREQUEST_CC: 在捕获/比较事件上生成CCx DMA请求
  *            @arg TIM_CCDMAREQUEST_UPDATE: 在更新事件上生成CCx DMA请求
  * @retval 无
  */
#define __HAL_TIM_SELECT_CCDMAREQUEST(__HANDLE__, __CCDMA__)    \
  MODIFY_REG((__HANDLE__)->Instance->CR2, TIM_CR2_CCDS, (__CCDMA__))

/**
  * @}
  */
/* 导出宏结束 ----------------------------------------------------*/

/* 私有常量 ---------------------------------------------------------*/
/** @defgroup TIM_Private_Constants TIM 私有常量
  * @{
  */
/* 只有当所有CCx和CCxN通道都被禁能时，定时器实例的计数器才会被禁能 */
/* 定义CCER寄存器中使能位的掩码，用于输出通道 */
#define TIM_CCER_CCxE_MASK  ((uint32_t)(TIM_CCER_CC1E | TIM_CCER_CC2E | TIM_CCER_CC3E | TIM_CCER_CC4E))
/* 定义CCER寄存器中互补输出使能位的掩码 */
#define TIM_CCER_CCxNE_MASK ((uint32_t)(TIM_CCER_CC1NE | TIM_CCER_CC2NE | TIM_CCER_CC3NE))
/**
  * @}
  */
/* 私有常量结束 --------------------------------------------------*/

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup TIM_Private_Macros TIM 私有宏
  * @{
  */
/* 检查清除输入源是否合法 */
#define IS_TIM_CLEARINPUT_SOURCE(__MODE__)  (((__MODE__) == TIM_CLEARINPUTSOURCE_NONE)      || \
                                             ((__MODE__) == TIM_CLEARINPUTSOURCE_ETR))

/* 检查DMA基地址是否合法 */
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

/* 检查事件源是否合法 */
#define IS_TIM_EVENT_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFFFF00U) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))

/* 检查计数器模式是否合法 */
#define IS_TIM_COUNTER_MODE(__MODE__)      (((__MODE__) == TIM_COUNTERMODE_UP)              || \
                                            ((__MODE__) == TIM_COUNTERMODE_DOWN)            || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED1)  || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED2)  || \
                                            ((__MODE__) == TIM_COUNTERMODE_CENTERALIGNED3))

/* 检查时钟分频是否合法 */
#define IS_TIM_CLOCKDIVISION_DIV(__DIV__)  (((__DIV__) == TIM_CLOCKDIVISION_DIV1) || \
                                            ((__DIV__) == TIM_CLOCKDIVISION_DIV2) || \
                                            ((__DIV__) == TIM_CLOCKDIVISION_DIV4))

/* 检查自动重装载预装载是否合法 */
#define IS_TIM_AUTORELOAD_PRELOAD(PRELOAD) (((PRELOAD) == TIM_AUTORELOAD_PRELOAD_DISABLE) || \
                                            ((PRELOAD) == TIM_AUTORELOAD_PRELOAD_ENABLE))

/* 检查快速模式状态是否合法 */
#define IS_TIM_FAST_STATE(__STATE__)       (((__STATE__) == TIM_OCFAST_DISABLE) || \
                                            ((__STATE__) == TIM_OCFAST_ENABLE))

/* 检查输出比较极性是否合法 */
#define IS_TIM_OC_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_OCPOLARITY_HIGH) || \
                                            ((__POLARITY__) == TIM_OCPOLARITY_LOW))

/* 检查互补输出比较极性是否合法 */
#define IS_TIM_OCN_POLARITY(__POLARITY__)  (((__POLARITY__) == TIM_OCNPOLARITY_HIGH) || \
                                            ((__POLARITY__) == TIM_OCNPOLARITY_LOW))

/* 检查输出比较空闲状态是否合法 */
#define IS_TIM_OCIDLE_STATE(__STATE__)     (((__STATE__) == TIM_OCIDLESTATE_SET) || \
                                            ((__STATE__) == TIM_OCIDLESTATE_RESET))

/* 检查互补输出比较空闲状态是否合法 */
#define IS_TIM_OCNIDLE_STATE(__STATE__)    (((__STATE__) == TIM_OCNIDLESTATE_SET) || \
                                            ((__STATE__) == TIM_OCNIDLESTATE_RESET))

/* 检查编码器输入极性是否合法 */
#define IS_TIM_ENCODERINPUT_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_ENCODERINPUTPOLARITY_RISING)   || \
                                                      ((__POLARITY__) == TIM_ENCODERINPUTPOLARITY_FALLING))

/* 检查输入捕获极性是否合法 */
#define IS_TIM_IC_POLARITY(__POLARITY__)   (((__POLARITY__) == TIM_ICPOLARITY_RISING)   || \
                                            ((__POLARITY__) == TIM_ICPOLARITY_FALLING)  || \
                                            ((__POLARITY__) == TIM_ICPOLARITY_BOTHEDGE))

/* 检查输入捕获选择是否合法 */
#define IS_TIM_IC_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_ICSELECTION_DIRECTTI) || \
                                            ((__SELECTION__) == TIM_ICSELECTION_INDIRECTTI) || \
                                            ((__SELECTION__) == TIM_ICSELECTION_TRC))

/* 检查输入捕获预分频是否合法 */
#define IS_TIM_IC_PRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_ICPSC_DIV1) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV2) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV4) || \
                                            ((__PRESCALER__) == TIM_ICPSC_DIV8))

/* 检查单脉冲模式是否合法 */
#define IS_TIM_OPM_MODE(__MODE__)          (((__MODE__) == TIM_OPMODE_SINGLE) || \
                                            ((__MODE__) == TIM_OPMODE_REPETITIVE))

/* 检查编码器模式是否合法 */
#define IS_TIM_ENCODER_MODE(__MODE__)      (((__MODE__) == TIM_ENCODERMODE_TI1) || \
                                            ((__MODE__) == TIM_ENCODERMODE_TI2) || \
                                            ((__MODE__) == TIM_ENCODERMODE_TI12))

/* 检查DMA源是否合法 */
#define IS_TIM_DMA_SOURCE(__SOURCE__) ((((__SOURCE__) & 0xFFFF80FFU) == 0x00000000U) && ((__SOURCE__) != 0x00000000U))

/* 检查通道是否合法 */
#define IS_TIM_CHANNELS(__CHANNEL__)       (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_2) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_3) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_4) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_ALL))

/* 检查单脉冲模式通道是否合法 */
#define IS_TIM_OPM_CHANNELS(__CHANNEL__)   (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                            ((__CHANNEL__) == TIM_CHANNEL_2))

/* 检查周期值是否合法 */
#define IS_TIM_PERIOD(__PERIOD__)      (((__PERIOD__) > 0U) && ((__PERIOD__) <= 0xFFFFU))

/* 检查互补通道是否合法 */
#define IS_TIM_COMPLEMENTARY_CHANNELS(__CHANNEL__) (((__CHANNEL__) == TIM_CHANNEL_1) || \
                                                    ((__CHANNEL__) == TIM_CHANNEL_2) || \
                                                    ((__CHANNEL__) == TIM_CHANNEL_3))
