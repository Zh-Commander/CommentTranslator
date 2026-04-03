/* 检查定时器时钟源参数是否有效 */
/* 支持内部时钟、外部时钟模式1/2、TI1边沿检测、TI1/TI2输入、内部触发ITR0-ITR3 */
#define IS_TIM_CLOCKSOURCE(__CLOCK__) (((__CLOCK__) == TIM_CLOCKSOURCE_INTERNAL) || /* 内部时钟(CK_INT) */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ETRMODE1) || /* 外部时钟模式1(ETR引脚) */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ETRMODE2) || /* 外部时钟模式2(ETR引脚) */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI1ED)    || /* TI1边沿检测器 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI1)      || /* 滤波后的定时器输入1 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI2)      || /* 滤波后的定时器输入2 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR0)     || /* 内部触发0 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR1)     || /* 内部触发1 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR2)     || /* 内部触发2 */ \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR3))     /* 内部触发3 */

/* 检查时钟极性参数是否有效 */
/* 包括反相、非反相、上升沿、下降沿、双边沿 */
#define IS_TIM_CLOCKPOLARITY(__POLARITY__) (((__POLARITY__) == TIM_CLOCKPOLARITY_INVERTED)    || /* 反相(低电平或下降沿) */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_NONINVERTED) || /* 非反相(高电平或上升沿) */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_RISING)      || /* 上升沿 */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_FALLING)     || /* 下降沿 */ \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_BOTHEDGE))     /* 双边沿 */

/* 检查时钟预分频参数是否有效 */
/* 预分频系数可选1、2、4、8 */
#define IS_TIM_CLOCKPRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV1) || /* 不分频 */ \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV2) || /* 2分频 */ \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV4) || /* 4分频 */ \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV8))   /* 8分频 */

/* 检查时钟滤波参数是否有效 */
/* 滤波值范围：0x0 ~ 0xF (4位) */
#define IS_TIM_CLOCKFILTER(__ICFILTER__)      ((__ICFILTER__) <= 0xFU)

/* 检查清除输入极性参数是否有效 */
#define IS_TIM_CLEARINPUT_POLARITY(__POLARITY__) (((__POLARITY__) == TIM_CLEARINPUTPOLARITY_INVERTED) || /* 反相 */ \
                                                  ((__POLARITY__) == TIM_CLEARINPUTPOLARITY_NONINVERTED)) /* 非反相 */

/* 检查清除输入预分频参数是否有效 */
#define IS_TIM_CLEARINPUT_PRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV1) || /* 不分频 */ \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV2) || /* 2分频 */ \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV4) || /* 4分频 */ \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV8))   /* 8分频 */

/* 检查清除输入滤波参数是否有效 */
#define IS_TIM_CLEARINPUT_FILTER(__ICFILTER__) ((__ICFILTER__) <= 0xFU)

/* 检查运行模式下的关闭状态(OSSR)参数是否有效 */
/* OSSR: Off-State Selection for Run mode */
#define IS_TIM_OSSR_STATE(__STATE__)       (((__STATE__) == TIM_OSSR_ENABLE) || /* 使能 */ \
                                            ((__STATE__) == TIM_OSSR_DISABLE))  /* 禁用 */

/* 检查空闲模式下的关闭状态(OSSI)参数是否有效 */
/* OSSI: Off-State Selection for Idle mode */
#define IS_TIM_OSSI_STATE(__STATE__)       (((__STATE__) == TIM_OSSI_ENABLE) || /* 使能 */ \
                                            ((__STATE__) == TIM_OSSI_DISABLE))  /* 禁用 */

/* 检查锁定级别参数是否有效 */
/* 锁定级别越高，写保护越严格 */
#define IS_TIM_LOCK_LEVEL(__LEVEL__)       (((__LEVEL__) == TIM_LOCKLEVEL_OFF) || /* 不锁定 */ \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_1)   || /* 锁定级别1 */ \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_2)   || /* 锁定级别2 */ \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_3))     /* 锁定级别3 */

/* 检查刹车滤波参数是否有效 */
#define IS_TIM_BREAK_FILTER(__BRKFILTER__) ((__BRKFILTER__) <= 0xFUL)

/* 检查刹车功能使能状态参数是否有效 */
#define IS_TIM_BREAK_STATE(__STATE__)      (((__STATE__) == TIM_BREAK_ENABLE) || /* 使能刹车输入 */ \
                                            ((__STATE__) == TIM_BREAK_DISABLE))  /* 禁用刹车输入 */

/* 检查刹车极性参数是否有效 */
#define IS_TIM_BREAK_POLARITY(__POLARITY__) (((__POLARITY__) == TIM_BREAKPOLARITY_LOW) || /* 低电平有效 */ \
                                             ((__POLARITY__) == TIM_BREAKPOLARITY_HIGH))  /* 高电平有效 */

/* 检查自动输出使能参数是否有效 */
#define IS_TIM_AUTOMATIC_OUTPUT_STATE(__STATE__) (((__STATE__) == TIM_AUTOMATICOUTPUT_ENABLE) || /* 使能 */ \
                                                  ((__STATE__) == TIM_AUTOMATICOUTPUT_DISABLE))  /* 禁用 */

/* 检查触发输出(TRGO)源参数是否有效 */
#define IS_TIM_TRGO_SOURCE(__SOURCE__) (((__SOURCE__) == TIM_TRGO_RESET)  || /* 复位 */ \
                                        ((__SOURCE__) == TIM_TRGO_ENABLE) || /* 使能 */ \
                                        ((__SOURCE__) == TIM_TRGO_UPDATE) || /* 更新事件 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC1)    || /* 捕获比较1 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC1REF) || /* OC1参考信号 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC2REF) || /* OC2参考信号 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC3REF) || /* OC3参考信号 */ \
                                        ((__SOURCE__) == TIM_TRGO_OC4REF))     /* OC4参考信号 */

/* 检查主从模式(MSM)参数是否有效 */
#define IS_TIM_MSM_STATE(__STATE__)      (((__STATE__) == TIM_MASTERSLAVEMODE_ENABLE) || /* 使能主从模式 */ \
                                          ((__STATE__) == TIM_MASTERSLAVEMODE_DISABLE))  /* 禁用主从模式 */

/* 检查从模式参数是否有效 */
#define IS_TIM_SLAVE_MODE(__MODE__) (((__MODE__) == TIM_SLAVEMODE_DISABLE)   || /* 禁用从模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_RESET)     || /* 复位模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_GATED)     || /* 门控模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_TRIGGER)   || /* 触发模式 */ \
                                     ((__MODE__) == TIM_SLAVEMODE_EXTERNAL1))   /* 外部时钟模式1 */

/* 检查PWM模式参数是否有效 */
#define IS_TIM_PWM_MODE(__MODE__) (((__MODE__) == TIM_OCMODE_PWM1)               || /* PWM模式1 */ \
                                   ((__MODE__) == TIM_OCMODE_PWM2))                /* PWM模式2 */

/* 检查输出比较模式参数是否有效 */
#define IS_TIM_OC_MODE(__MODE__)  (((__MODE__) == TIM_OCMODE_TIMING)             || /* 输出比较时间模式(不输出) */ \
                                   ((__MODE__) == TIM_OCMODE_ACTIVE)             || /* 输出比较主动模式(匹配时输出有效电平) */ \
                                   ((__MODE__) == TIM_OCMODE_INACTIVE)           || /* 输出比较非主动模式(匹配时输出无效电平) */ \
                                   ((__MODE__) == TIM_OCMODE_TOGGLE)             || /* 输出比较翻转模式 */ \
                                   ((__MODE__) == TIM_OCMODE_FORCED_ACTIVE)      || /* 强制输出有效电平 */ \
                                   ((__MODE__) == TIM_OCMODE_FORCED_INACTIVE))      /* 强制输出无效电平 */

/* 检查触发选择参数是否有效 */
#define IS_TIM_TRIGGER_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_TS_ITR0)    || /* 内部触发0 */ \
                                                 ((__SELECTION__) == TIM_TS_ITR1)    || /* 内部触发1 */ \
                                                 ((__SELECTION__) == TIM_TS_ITR2)    || /* 内部触发2 */ \
                                                 ((__SELECTION__) == TIM_TS_ITR3)    || /* 内部触发3 */ \
                                                 ((__SELECTION__) == TIM_TS_TI1F_ED) || /* TI1边沿检测 */ \
                                                 ((__SELECTION__) == TIM_TS_TI1FP1)  || /* 滤波后的定时器输入1 */ \
                                                 ((__SELECTION__) == TIM_TS_TI2FP2)  || /* 滤波后的定时器输入2 */ \
                                                 ((__SELECTION__) == TIM_TS_ETRF))      /* 外部触发输入 */

/* 检查内部触发事件选择参数是否有效 */
#define IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_TS_ITR0) || /* 内部触发0 */ \
                                                               ((__SELECTION__) == TIM_TS_ITR1) || /* 内部触发1 */ \
                                                               ((__SELECTION__) == TIM_TS_ITR2) || /* 内部触发2 */ \
                                                               ((__SELECTION__) == TIM_TS_ITR3) || /* 内部触发3 */ \
                                                               ((__SELECTION__) == TIM_TS_NONE))     /* 无触发 */

/* 检查触发极性参数是否有效 */
#define IS_TIM_TRIGGERPOLARITY(__POLARITY__)   (((__POLARITY__) == TIM_TRIGGERPOLARITY_INVERTED   ) || /* 反相 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_NONINVERTED) || /* 非反相 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_RISING     ) || /* 上升沿 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_FALLING    ) || /* 下降沿 */ \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_BOTHEDGE   ))   /* 双边沿 */

/* 检查触发预分频参数是否有效 */
#define IS_TIM_TRIGGERPRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV1) || /* 不分频 */ \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV2) || /* 2分频 */ \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV4) || /* 4分频 */ \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV8))   /* 8分频 */

/* 检查触发滤波参数是否有效 */
#define IS_TIM_TRIGGERFILTER(__ICFILTER__) ((__ICFILTER__) <= 0xFU)

/* 检查TI1输入选择参数是否有效 */
#define IS_TIM_TI1SELECTION(__TI1SELECTION__)  (((__TI1SELECTION__) == TIM_TI1SELECTION_CH1) || /* 选择通道1输入 */ \
                                                ((__TI1SELECTION__) == TIM_TI1SELECTION_XORCOMBINATION)) /* 选择异或组合输入 */

/* 检查DMA突发传输长度参数是否有效 */
/* 范围：1次到18次传输 */
#define IS_TIM_DMA_LENGTH(__LENGTH__)      (((__LENGTH__) == TIM_DMABURSTLENGTH_1TRANSFER)   || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_2TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_3TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_4TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_5TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_6TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_7TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_8TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_9TRANSFERS)  || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_10TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_11TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_12TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_13TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_14TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_15TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_16TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_17TRANSFERS) || \
                                            ((__LENGTH__) == TIM_DMABURSTLENGTH_18TRANSFERS))

/* 检查DMA数据长度参数是否有效 */
/* 范围：0x0001 ~ 0xFFFF */
#define IS_TIM_DMA_DATA_LENGTH(LENGTH) (((LENGTH) >= 0x1U) && ((LENGTH) < 0x10000U))

/* 检查输入捕获滤波参数是否有效 */
#define IS_TIM_IC_FILTER(__ICFILTER__)   ((__ICFILTER__) <= 0xFU)

/* 检查死区时间参数是否有效 */
/* 死区时间范围：0x00 ~ 0xFF */
#define IS_TIM_DEADTIME(__DEADTIME__)    ((__DEADTIME__) <= 0xFFU)

/* 检查从模式触发是否已使能 */
#define IS_TIM_SLAVEMODE_TRIGGER_ENABLED(__TRIGGER__) ((__TRIGGER__) == TIM_SLAVEMODE_TRIGGER)

/* 设置输入捕获预分频值 */
/* 根据通道号设置CCMR寄存器中的ICxPSC位 */
#define TIM_SET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__, __ICPSC__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= (__ICPSC__)) :\  /* 通道1设置CCMR1[1:0] */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= ((__ICPSC__) << 8U)) :\ /* 通道2设置CCMR1[9:8] */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= (__ICPSC__)) :\  /* 通道3设置CCMR2[1:0] */ \
   ((__HANDLE__)->Instance->CCMR2 |= ((__ICPSC__) << 8U)))                                 /* 通道4设置CCMR2[9:8] */

/* 复位输入捕获预分频值 */
/* 将对应通道的预分频位清零 */
#define TIM_RESET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_IC1PSC) :\ /* 清除通道1预分频 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_IC2PSC) :\ /* 清除通道2预分频 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_IC3PSC) :\ /* 清除通道3预分频 */ \
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_IC4PSC))                                     /* 清除通道4预分频 */

/* 设置捕获极性 */
/* 根据通道号设置CCER寄存器中的CCxP/CCxNP位 */
#define TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER |= (__POLARITY__)) :\       /* 通道1设置CCER[1:0] */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 4U)) :\ /* 通道2设置CCER[5:4] */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 8U)) :\ /* 通道3设置CCER[9:8] */ \
   ((__HANDLE__)->Instance->CCER |= (((__POLARITY__) << 12U))))                                   /* 通道4设置CCER[13:12] */

/* 复位捕获极性 */
/* 将对应通道的极性位清零 */
#define TIM_RESET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP)) :\ /* 清除通道1极性 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC2P | TIM_CCER_CC2NP)) :\ /* 清除通道2极性 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC3P)) :\                 /* 清除通道3极性 */ \
   ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC4P)))                                                     /* 清除通道4极性 */

/* 获取通道状态 */
/* 返回句柄中对应通道的状态 */
#define TIM_CHANNEL_STATE_GET(__HANDLE__, __CHANNEL__)\
  (((__CHANNEL__) == TIM_CHANNEL_1) ? (__HANDLE__)->ChannelState[0] :\ /* 获取通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (__HANDLE__)->ChannelState[1] :\ /* 获取通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? (__HANDLE__)->ChannelState[2] :\ /* 获取通道3状态 */ \
   (__HANDLE__)->ChannelState[3])                                       /* 获取通道4状态 */

/* 设置通道状态 */
/* 设置句柄中对应通道的状态 */
#define TIM_CHANNEL_STATE_SET(__HANDLE__, __CHANNEL__, __CHANNEL_STATE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->ChannelState[0] = (__CHANNEL_STATE__)) :\ /* 设置通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->ChannelState[1] = (__CHANNEL_STATE__)) :\ /* 设置通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->ChannelState[2] = (__CHANNEL_STATE__)) :\ /* 设置通道3状态 */ \
   ((__HANDLE__)->ChannelState[3] = (__CHANNEL_STATE__)))                                        /* 设置通道4状态 */

/* 设置所有通道状态 */
/* 统一设置所有通道的状态 */
#define TIM_CHANNEL_STATE_SET_ALL(__HANDLE__,  __CHANNEL_STATE__) do { \
                                                                       (__HANDLE__)->ChannelState[0]  = (__CHANNEL_STATE__);  \ /* 设置通道1 */ \
                                                                       (__HANDLE__)->ChannelState[1]  = (__CHANNEL_STATE__);  \ /* 设置通道2 */ \
                                                                       (__HANDLE__)->ChannelState[2]  = (__CHANNEL_STATE__);  \ /* 设置通道3 */ \
                                                                       (__HANDLE__)->ChannelState[3]  = (__CHANNEL_STATE__);  \ /* 设置通道4 */ \
                                                                     } while(0)

/* 获取互补通道状态 */
/* 返回句柄中对应互补通道的状态 */
#define TIM_CHANNEL_N_STATE_GET(__HANDLE__, __CHANNEL__)\
  (((__CHANNEL__) == TIM_CHANNEL_1) ? (__HANDLE__)->ChannelNState[0] :\ /* 获取互补通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (__HANDLE__)->ChannelNState[1] :\ /* 获取互补通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? (__HANDLE__)->ChannelNState[2] :\ /* 获取互补通道3状态 */ \
   (__HANDLE__)->ChannelNState[3])                                       /* 获取互补通道4状态 */

/* 设置互补通道状态 */
/* 设置句柄中对应互补通道的状态 */
#define TIM_CHANNEL_N_STATE_SET(__HANDLE__, __CHANNEL__, __CHANNEL_STATE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->ChannelNState[0] = (__CHANNEL_STATE__)) :\ /* 设置互补通道1状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->ChannelNState[1] = (__CHANNEL_STATE__)) :\ /* 设置互补通道2状态 */ \
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->ChannelNState[2] = (__CHANNEL_STATE__)) :\ /* 设置互补通道3状态 */ \
   ((__HANDLE__)->ChannelNState[3] = (__CHANNEL_STATE__)))                                        /* 设置互补通道4状态 */

/* 设置所有互补通道状态 */
/* 统一设置所有互补通道的状态 */
#define TIM_CHANNEL_N_STATE_SET_ALL(__HANDLE__,  __CHANNEL_STATE__) do { \
                                                                         (__HANDLE__)->ChannelNState[0] = \ /* 设置互补通道1 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[1] = \ /* 设置互补通道2 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[2] = \ /* 设置互补通道3 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[3] = \ /* 设置互补通道4 */ \
                                                                         (__CHANNEL_STATE__);  \
                                                                       } while(0)

/**
  * @}
  */
/* 私有宏定义结束 -----------------------------------------------------*/

/* 包含 TIM HAL 扩展模块 */
#include "stm32f1xx_hal_tim_ex.h"

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup TIM_Exported_Functions TIM 导出函数
  * @{
  */

/** @addtogroup TIM_Exported_Functions_Group1 TIM 时基功能函数
  *  @brief   时基功能函数
  * @{
  */
/* 时基功能函数 ********************************************************/
/* 初始化与反初始化 */
HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim); /* 初始化定时器时基单元 */
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim); /* 反初始化定时器时基单元 */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim); /* 初始化底层硬件(MSP)，如时钟、GPIO */
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim); /* 反初始化底层硬件(MSP) */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim); /* 启动定时器(轮询模式) */
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim); /* 停止定时器(轮询模式) */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim); /* 启动定时器(中断模式) */
HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim); /* 停止定时器(中断模式) */

/* 非阻塞模式：DMA方式 */
HAL_StatusTypeDef HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, const uint32_t *pData, uint16_t Length); /* 启动定时器(DMA模式) */
HAL_StatusTypeDef HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim); /* 停止定时器(DMA模式) */
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group2 TIM 输出比较功能函数
  *  @brief   TIM 输出比较功能函数
  * @{
  */
/* 定时器输出比较功能 *********************************************/
/* 初始化与反初始化 */
HAL_StatusTypeDef HAL_TIM_OC_Init(TIM_HandleTypeDef *htim); /* 初始化输出比较模式 */
HAL_StatusTypeDef HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim); /* 反初始化输出比较模式 */
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim); /* 初始化底层硬件(MSP) */
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim); /* 反初始化底层硬件(MSP) */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动输出比较(轮询模式) */
HAL_StatusTypeDef HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止输出比较(轮询模式) */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动输出比较(中断模式) */
HAL_StatusTypeDef HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止输出比较(中断模式) */

/* 非阻塞模式：DMA方式 */
HAL_StatusTypeDef HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                       uint16_t Length); /* 启动输出比较(DMA模式) */
HAL_StatusTypeDef HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止输出比较(DMA模式) */
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group3 TIM PWM功能函数
  *  @brief   TIM PWM功能函数
  * @{
  */
/* 定时器PWM功能 ********************************************************/
/* 初始化与反初始化 */
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim); /* 初始化PWM模式 */
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim); /* 反初始化PWM模式 */
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim); /* 初始化底层硬件(MSP) */
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim); /* 反初始化底层硬件(MSP) */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动PWM输出(轮询模式) */
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止PWM输出(轮询模式) */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动PWM输出(中断模式) */
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止PWM输出(中断模式) */

/* 非阻塞模式：DMA方式 */
HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                        uint16_t Length); /* 启动PWM输出(DMA模式) */
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止PWM输出(DMA模式) */
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group4 TIM 输入捕获功能函数
  *  @brief   TIM 输入捕获功能函数
  * @{
  */
/* 定时器输入捕获功能 **********************************************/
/* 初始化与反初始化 */
HAL_StatusTypeDef HAL_TIM_IC_Init(TIM_HandleTypeDef *htim); /* 初始化输入捕获模式 */
HAL_StatusTypeDef HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim); /* 反初始化输入捕获模式 */
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim); /* 初始化底层硬件(MSP) */
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim); /* 反初始化底层硬件(MSP) */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_TIM_IC_Start(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动输入捕获(轮询模式) */
HAL_StatusTypeDef HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止输入捕获(轮询模式) */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_TIM_IC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动输入捕获(中断模式) */
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止输入捕获(中断模式) */

/* 非阻塞模式：DMA方式 */
HAL_StatusTypeDef HAL_TIM_IC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length); /* 启动输入捕获(DMA模式) */
HAL_StatusTypeDef HAL_TIM_IC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止输入捕获(DMA模式) */
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group5 TIM 单脉冲功能函数
  *  @brief   TIM 单脉冲功能函数
  * @{
  */
/* 定时器单脉冲功能 **************************************************/
/* 初始化与反初始化 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode); /* 初始化单脉冲模式 */
HAL_StatusTypeDef HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim); /* 反初始化单脉冲模式 */
void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim); /* 初始化底层硬件(MSP) */
void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim); /* 反初始化底层硬件(MSP) */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel); /* 启动单脉冲(轮询模式) */
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel); /* 停止单脉冲(轮询模式) */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel); /* 启动单脉冲(中断模式) */
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel); /* 停止单脉冲(中断模式) */
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group6 TIM 编码器功能函数
  *  @brief   TIM 编码器功能函数
  * @{
  */
/* 定时器编码器功能 ****************************************************/
/* 初始化与反初始化 */
HAL_StatusTypeDef HAL_TIM_Encoder_Init(TIM_HandleTypeDef *htim, const TIM_Encoder_InitTypeDef *sConfig); /* 初始化编码器模式 */
HAL_StatusTypeDef HAL_TIM_Encoder_DeInit(TIM_HandleTypeDef *htim); /* 反初始化编码器模式 */
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim); /* 初始化底层硬件(MSP) */
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim); /* 反初始化底层硬件(MSP) */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动编码器(轮询模式) */
HAL_StatusTypeDef HAL_TIM_Encoder_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止编码器(轮询模式) */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 启动编码器(中断模式) */
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止编码器(中断模式) */

/* 非阻塞模式：DMA方式 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1,
                                            uint32_t *pData2, uint16_t Length); /* 启动编码器(DMA模式) */
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); /* 停止编码器(DMA模式) */
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group7 TIM 中断处理管理
  *  @brief   中断处理管理
  * @{
  */
/* 中断处理函数  ***********************************************/
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim); /* 定时器中断通用处理函数 */
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group8 TIM 外设控制功能函数
  *  @brief   外设控制功能函数
  * @{
  */
/* 控制函数  *********************************************************/
/* 配置输出比较通道 */
HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                           uint32_t Channel);
/* 配置PWM通道 */
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                            uint32_t Channel);
/* 配置输入捕获通道 */
HAL_StatusTypeDef HAL_TIM_IC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_IC_InitTypeDef *sConfig,
                                           uint32_t Channel);
/* 配置单脉冲通道 */
HAL_StatusTypeDef HAL_TIM_OnePulse_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OnePulse_InitTypeDef *sConfig,
                                                 uint32_t OutputChannel,  uint32_t InputChannel);
/* 配置输出比较清除输入(OCREF Clear) */
HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim,
                                           const TIM_ClearInputConfigTypeDef *sClearInputConfig,
                                           uint32_t Channel);
/* 配置时钟源 */
HAL_StatusTypeDef HAL_TIM_ConfigClockSource(TIM_HandleTypeDef *htim, const TIM_ClockConfigTypeDef *sClockSourceConfig);
/* 配置TI1输入 */
HAL_StatusTypeDef HAL_TIM_ConfigTI1Input(TIM_HandleTypeDef *htim, uint32_t TI1_Selection);
/* 配置从模式同步 */
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig);
/* 配置从模式同步(中断方式) */
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro_IT(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig);
/* 启动DMA突发写操作 */
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                              uint32_t BurstRequestSrc, const uint32_t  *BurstBuffer,
                                              uint32_t  BurstLength);
/* 启动DMA突发多次写操作 */
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiWriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                   uint32_t BurstRequestSrc, const uint32_t *BurstBuffer,
                                                   uint32_t BurstLength,  uint32_t DataLength);
/* 停止DMA突发写操作 */
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
/* 启动DMA突发读操作 */
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                             uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength);
/* 启动DMA突发多次读操作 */
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                  uint32_t BurstRequestSrc, uint32_t  *BurstBuffer,
                                                  uint32_t  BurstLength, uint32_t  DataLength);
/* 停止DMA突发读操作 */
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
/* 产生事件 */
HAL_StatusTypeDef HAL_TIM_GenerateEvent(TIM_HandleTypeDef *htim, uint32_t EventSource);
/* 读取捕获值 */
uint32_t HAL_TIM_ReadCapturedValue(const TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group9 TIM 回调函数
  *  @brief   TIM 回调函数
  * @{
  */
/* 非阻塞模式下的回调函数(中断和DMA) *************************/
/* 更新事件(周期溢出)回调函数 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
/* 更新事件半完成回调函数(DMA双缓冲模式) */
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim);
/* 输出比较延迟经过回调函数 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
/* 输入捕获回调函数 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
/* 输入捕获半完成回调函数 */
void HAL_TIM_IC_CaptureHalfCpltCallback(TIM_HandleTypeDef *htim);
/* PWM脉冲完成回调函数 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
/* PWM脉冲半完成回调函数 */
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim);
/* 触发回调函数 */
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim);
/* 触发半完成回调函数 */
void HAL_TIM_TriggerHalfCpltCallback(TIM_HandleTypeDef *htim);
/* 错误回调函数 */
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/* 注册回调函数 */
HAL_StatusTypeDef HAL_TIM_RegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID,
                                           pTIM_CallbackTypeDef pCallback);
/* 注销回调函数 */
HAL_StatusTypeDef HAL_TIM_UnRegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group10 TIM 外设状态功能函数
  *  @brief  外设状态功能函数
  * @{
  */
/* 外设状态功能函数  ************************************************/
/* 获取时基模式状态 */
HAL_TIM_StateTypeDef HAL_TIM_Base_GetState(const TIM_HandleTypeDef *htim);
/* 获取输出比较模式状态 */
HAL_TIM_StateTypeDef HAL_TIM_OC_GetState(const TIM_HandleTypeDef *htim);
/* 获取PWM模式状态 */
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(const TIM_HandleTypeDef *htim);
/* 获取输入捕获模式状态 */
HAL_TIM_StateTypeDef HAL_TIM_IC_GetState(const TIM_HandleTypeDef *htim);
/* 获取单脉冲模式状态 */
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(const TIM_HandleTypeDef *htim);
/* 获取编码器模式状态 */
HAL_TIM_StateTypeDef HAL_TIM_Encoder_GetState(const TIM_HandleTypeDef *htim);

/* 外设通道状态功能函数  ************************************************/
/* 获取活动通道 */
HAL_TIM_ActiveChannel HAL_TIM_GetActiveChannel(const TIM_HandleTypeDef *htim);
/* 获取通道状态 */
HAL_TIM_ChannelStateTypeDef HAL_TIM_GetChannelState(const TIM_HandleTypeDef *htim,  uint32_t Channel);
/* 获取DMA突发状态 */
HAL_TIM_DMABurstStateTypeDef HAL_TIM_DMABurstState(const TIM_HandleTypeDef *htim);
/**
  * @}
  */

/**
  * @}
  */
/* 导出函数结束 -------------------------------------------------*/

/* 私有函数----------------------------------------------------------*/
/** @defgroup TIM_Private_Functions TIM 私有函数
  * @{
  */
/* 基础配置函数 */
void TIM_Base_SetConfig(TIM_TypeDef *TIMx, const TIM_Base_InitTypeDef *Structure);
/* TI1配置函数 */
void TIM_TI1_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter);
/* OC2配置函数 */
void TIM_OC2_SetConfig(TIM_TypeDef *TIMx, const TIM_OC_InitTypeDef *OC_Config);
/* ETR配置函数 */
void TIM_ETR_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ExtTRGPrescaler,
                       uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter);

/* DMA延迟脉冲半完成回调 */
void TIM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma);
/* DMA错误回调 */
void TIM_DMAError(DMA_HandleTypeDef *hdma);
/* DMA捕获完成回调 */
void TIM_DMACaptureCplt(DMA_HandleTypeDef *hdma);
/* DMA捕获半完成回调 */
void TIM_DMACaptureHalfCplt(DMA_HandleTypeDef *hdma);
/* 通道使能/禁用命令 */
void TIM_CCxChannelCmd(TIM_TypeDef *TIMx, uint32_t Channel, uint32_t ChannelState);

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/* 重置回调函数 */
void TIM_ResetCallback(TIM_HandleTypeDef *htim);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* 私有函数结束 --------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F1xx_HAL_TIM_H */
