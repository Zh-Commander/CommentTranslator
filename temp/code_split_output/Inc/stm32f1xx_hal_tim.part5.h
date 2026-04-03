/* 检查时钟源参数是否有效：支持内部时钟、ETR模式1/2、TI1/2输入、内部触发(ITR)等 */
#define IS_TIM_CLOCKSOURCE(__CLOCK__) (((__CLOCK__) == TIM_CLOCKSOURCE_INTERNAL) || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ETRMODE1) || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ETRMODE2) || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI1ED)    || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI1)      || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_TI2)      || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR0)     || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR1)     || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR2)     || \
                                       ((__CLOCK__) == TIM_CLOCKSOURCE_ITR3))

/* 检查时钟极性参数是否有效：反相、非反相、上升沿、下降沿、双边沿 */
#define IS_TIM_CLOCKPOLARITY(__POLARITY__) (((__POLARITY__) == TIM_CLOCKPOLARITY_INVERTED)    || \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_NONINVERTED) || \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_RISING)      || \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_FALLING)     || \
                                            ((__POLARITY__) == TIM_CLOCKPOLARITY_BOTHEDGE))

/* 检查时钟预分频参数是否有效：1、2、4、8分频 */
#define IS_TIM_CLOCKPRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV1) || \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV2) || \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV4) || \
                                              ((__PRESCALER__) == TIM_CLOCKPRESCALER_DIV8))

/* 检查时钟滤波参数是否有效：滤波值范围0-15 */
#define IS_TIM_CLOCKFILTER(__ICFILTER__)      ((__ICFILTER__) <= 0xFU)

/* 检查清除输入极性参数是否有效：反相或非反相 */
#define IS_TIM_CLEARINPUT_POLARITY(__POLARITY__) (((__POLARITY__) == TIM_CLEARINPUTPOLARITY_INVERTED) || \
                                                  ((__POLARITY__) == TIM_CLEARINPUTPOLARITY_NONINVERTED))

/* 检查清除输入预分频参数是否有效：1、2、4、8分频 */
#define IS_TIM_CLEARINPUT_PRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV1) || \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV2) || \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV4) || \
                                                    ((__PRESCALER__) == TIM_CLEARINPUTPRESCALER_DIV8))

/* 检查清除输入滤波参数是否有效：滤波值范围0-15 */
#define IS_TIM_CLEARINPUT_FILTER(__ICFILTER__) ((__ICFILTER__) <= 0xFU)

/* 检查运行模式下的关闭状态参数是否有效：使能或禁用 */
#define IS_TIM_OSSR_STATE(__STATE__)       (((__STATE__) == TIM_OSSR_ENABLE) || \
                                            ((__STATE__) == TIM_OSSR_DISABLE))

/* 检查空闲模式下的关闭状态参数是否有效：使能或禁用 */
#define IS_TIM_OSSI_STATE(__STATE__)       (((__STATE__) == TIM_OSSI_ENABLE) || \
                                            ((__STATE__) == TIM_OSSI_DISABLE))

/* 检查锁定级别参数是否有效：关闭、级别1/2/3 */
#define IS_TIM_LOCK_LEVEL(__LEVEL__)       (((__LEVEL__) == TIM_LOCKLEVEL_OFF) || \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_1)   || \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_2)   || \
                                            ((__LEVEL__) == TIM_LOCKLEVEL_3))

/* 检查刹车滤波参数是否有效：滤波值范围0-15 */
#define IS_TIM_BREAK_FILTER(__BRKFILTER__) ((__BRKFILTER__) <= 0xFUL)

/* 检查刹车状态参数是否有效：使能或禁用 */
#define IS_TIM_BREAK_STATE(__STATE__)      (((__STATE__) == TIM_BREAK_ENABLE) || \
                                            ((__STATE__) == TIM_BREAK_DISABLE))

/* 检查刹车极性参数是否有效：低电平或高电平有效 */
#define IS_TIM_BREAK_POLARITY(__POLARITY__) (((__POLARITY__) == TIM_BREAKPOLARITY_LOW) || \
                                             ((__POLARITY__) == TIM_BREAKPOLARITY_HIGH))

/* 检查自动输出状态参数是否有效：使能或禁用 */
#define IS_TIM_AUTOMATIC_OUTPUT_STATE(__STATE__) (((__STATE__) == TIM_AUTOMATICOUTPUT_ENABLE) || \
                                                  ((__STATE__) == TIM_AUTOMATICOUTPUT_DISABLE))

/* 检查触发输出(TRGO)源参数是否有效：复位、使能、更新、OC1/2/3/4REF等 */
#define IS_TIM_TRGO_SOURCE(__SOURCE__) (((__SOURCE__) == TIM_TRGO_RESET)  || \
                                        ((__SOURCE__) == TIM_TRGO_ENABLE) || \
                                        ((__SOURCE__) == TIM_TRGO_UPDATE) || \
                                        ((__SOURCE__) == TIM_TRGO_OC1)    || \
                                        ((__SOURCE__) == TIM_TRGO_OC1REF) || \
                                        ((__SOURCE__) == TIM_TRGO_OC2REF) || \
                                        ((__SOURCE__) == TIM_TRGO_OC3REF) || \
                                        ((__SOURCE__) == TIM_TRGO_OC4REF))

/* 检查主从模式参数是否有效：使能或禁用 */
#define IS_TIM_MSM_STATE(__STATE__)      (((__STATE__) == TIM_MASTERSLAVEMODE_ENABLE) || \
                                          ((__STATE__) == TIM_MASTERSLAVEMODE_DISABLE))

/* 检查从模式参数是否有效：禁用、复位、门控、触发、外部模式1 */
#define IS_TIM_SLAVE_MODE(__MODE__) (((__MODE__) == TIM_SLAVEMODE_DISABLE)   || \
                                     ((__MODE__) == TIM_SLAVEMODE_RESET)     || \
                                     ((__MODE__) == TIM_SLAVEMODE_GATED)     || \
                                     ((__MODE__) == TIM_SLAVEMODE_TRIGGER)   || \
                                     ((__MODE__) == TIM_SLAVEMODE_EXTERNAL1))

/* 检查PWM模式参数是否有效：PWM模式1或PWM模式2 */
#define IS_TIM_PWM_MODE(__MODE__) (((__MODE__) == TIM_OCMODE_PWM1)               || \
                                   ((__MODE__) == TIM_OCMODE_PWM2))

/* 检查输出比较模式参数是否有效：冻结、有效、无效、翻转、强制有效、强制无效 */
#define IS_TIM_OC_MODE(__MODE__)  (((__MODE__) == TIM_OCMODE_TIMING)             || \
                                   ((__MODE__) == TIM_OCMODE_ACTIVE)             || \
                                   ((__MODE__) == TIM_OCMODE_INACTIVE)           || \
                                   ((__MODE__) == TIM_OCMODE_TOGGLE)             || \
                                   ((__MODE__) == TIM_OCMODE_FORCED_ACTIVE)      || \
                                   ((__MODE__) == TIM_OCMODE_FORCED_INACTIVE))

/* 检查触发选择参数是否有效：内部触发(ITR)、TI1边沿检测、TI1/2滤波、外部触发(ETRF) */
#define IS_TIM_TRIGGER_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_TS_ITR0)    || \
                                                 ((__SELECTION__) == TIM_TS_ITR1)    || \
                                                 ((__SELECTION__) == TIM_TS_ITR2)    || \
                                                 ((__SELECTION__) == TIM_TS_ITR3)    || \
                                                 ((__SELECTION__) == TIM_TS_TI1F_ED) || \
                                                 ((__SELECTION__) == TIM_TS_TI1FP1)  || \
                                                 ((__SELECTION__) == TIM_TS_TI2FP2)  || \
                                                 ((__SELECTION__) == TIM_TS_ETRF))

/* 检查内部触发事件选择参数是否有效：ITR0-3或无 */
#define IS_TIM_INTERNAL_TRIGGEREVENT_SELECTION(__SELECTION__) (((__SELECTION__) == TIM_TS_ITR0) || \
                                                               ((__SELECTION__) == TIM_TS_ITR1) || \
                                                               ((__SELECTION__) == TIM_TS_ITR2) || \
                                                               ((__SELECTION__) == TIM_TS_ITR3) || \
                                                               ((__SELECTION__) == TIM_TS_NONE))

/* 检查触发极性参数是否有效：反相、非反相、上升沿、下降沿、双边沿 */
#define IS_TIM_TRIGGERPOLARITY(__POLARITY__)   (((__POLARITY__) == TIM_TRIGGERPOLARITY_INVERTED   ) || \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_NONINVERTED) || \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_RISING     ) || \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_FALLING    ) || \
                                                ((__POLARITY__) == TIM_TRIGGERPOLARITY_BOTHEDGE   ))

/* 检查触发预分频参数是否有效：1、2、4、8分频 */
#define IS_TIM_TRIGGERPRESCALER(__PRESCALER__) (((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV1) || \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV2) || \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV4) || \
                                                ((__PRESCALER__) == TIM_TRIGGERPRESCALER_DIV8))

/* 检查触发滤波参数是否有效：滤波值范围0-15 */
#define IS_TIM_TRIGGERFILTER(__ICFILTER__) ((__ICFILTER__) <= 0xFU)

/* 检查TI1选择参数是否有效：通道1或异或组合 */
#define IS_TIM_TI1SELECTION(__TI1SELECTION__)  (((__TI1SELECTION__) == TIM_TI1SELECTION_CH1) || \
                                                ((__TI1SELECTION__) == TIM_TI1SELECTION_XORCOMBINATION))

/* 检查DMA传输长度参数是否有效：1次到18次传输 */
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

/* 检查DMA数据长度参数是否有效：范围1到65535 */
#define IS_TIM_DMA_DATA_LENGTH(LENGTH) (((LENGTH) >= 0x1U) && ((LENGTH) < 0x10000U))

/* 检查输入捕获滤波参数是否有效：滤波值范围0-15 */
#define IS_TIM_IC_FILTER(__ICFILTER__)   ((__ICFILTER__) <= 0xFU)

/* 检查死区时间参数是否有效：范围0-255 */
#define IS_TIM_DEADTIME(__DEADTIME__)    ((__DEADTIME__) <= 0xFFU)

/* 检查从模式触发是否使能 */
#define IS_TIM_SLAVEMODE_TRIGGER_ENABLED(__TRIGGER__) ((__TRIGGER__) == TIM_SLAVEMODE_TRIGGER)

/* 设置输入捕获预分频值宏定义：根据通道号设置CCMR寄存器的ICPSC位 */
#define TIM_SET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__, __ICPSC__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 |= (__ICPSC__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 |= ((__ICPSC__) << 8U)) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 |= (__ICPSC__)) :\
   ((__HANDLE__)->Instance->CCMR2 |= ((__ICPSC__) << 8U)))

/* 复位输入捕获预分频值宏定义：清除CCMR寄存器的ICPSC位 */
#define TIM_RESET_ICPRESCALERVALUE(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_IC1PSC) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCMR1 &= ~TIM_CCMR1_IC2PSC) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_IC3PSC) :\
   ((__HANDLE__)->Instance->CCMR2 &= ~TIM_CCMR2_IC4PSC))

/* 设置捕获极性宏定义：根据通道号设置CCER寄存器的极性位 */
#define TIM_SET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__, __POLARITY__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER |= (__POLARITY__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 4U)) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER |= ((__POLARITY__) << 8U)) :\
   ((__HANDLE__)->Instance->CCER |= (((__POLARITY__) << 12U))))

/* 复位捕获极性宏定义：清除CCER寄存器的极性位 */
#define TIM_RESET_CAPTUREPOLARITY(__HANDLE__, __CHANNEL__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP)) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC2P | TIM_CCER_CC2NP)) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC3P)) :\
   ((__HANDLE__)->Instance->CCER &= ~(TIM_CCER_CC4P)))

/* 获取通道状态宏定义：返回指定通道的当前状态 */
#define TIM_CHANNEL_STATE_GET(__HANDLE__, __CHANNEL__)\
  (((__CHANNEL__) == TIM_CHANNEL_1) ? (__HANDLE__)->ChannelState[0] :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (__HANDLE__)->ChannelState[1] :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? (__HANDLE__)->ChannelState[2] :\
   (__HANDLE__)->ChannelState[3])

/* 设置通道状态宏定义：设置指定通道的状态 */
#define TIM_CHANNEL_STATE_SET(__HANDLE__, __CHANNEL__, __CHANNEL_STATE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->ChannelState[0] = (__CHANNEL_STATE__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->ChannelState[1] = (__CHANNEL_STATE__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->ChannelState[2] = (__CHANNEL_STATE__)) :\
   ((__HANDLE__)->ChannelState[3] = (__CHANNEL_STATE__)))

/* 设置所有通道状态宏定义：统一设置所有4个通道的状态 */
#define TIM_CHANNEL_STATE_SET_ALL(__HANDLE__,  __CHANNEL_STATE__) do { \
                                                                       (__HANDLE__)->ChannelState[0]  = (__CHANNEL_STATE__);  \
                                                                       (__HANDLE__)->ChannelState[1]  = (__CHANNEL_STATE__);  \
                                                                       (__HANDLE__)->ChannelState[2]  = (__CHANNEL_STATE__);  \
                                                                       (__HANDLE__)->ChannelState[3]  = (__CHANNEL_STATE__);  \
                                                                     } while(0)

/* 获取互补通道状态宏定义：返回指定互补通道的当前状态 */
#define TIM_CHANNEL_N_STATE_GET(__HANDLE__, __CHANNEL__)\
  (((__CHANNEL__) == TIM_CHANNEL_1) ? (__HANDLE__)->ChannelNState[0] :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? (__HANDLE__)->ChannelNState[1] :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? (__HANDLE__)->ChannelNState[2] :\
   (__HANDLE__)->ChannelNState[3])

/* 设置互补通道状态宏定义：设置指定互补通道的状态 */
#define TIM_CHANNEL_N_STATE_SET(__HANDLE__, __CHANNEL__, __CHANNEL_STATE__) \
  (((__CHANNEL__) == TIM_CHANNEL_1) ? ((__HANDLE__)->ChannelNState[0] = (__CHANNEL_STATE__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_2) ? ((__HANDLE__)->ChannelNState[1] = (__CHANNEL_STATE__)) :\
   ((__CHANNEL__) == TIM_CHANNEL_3) ? ((__HANDLE__)->ChannelNState[2] = (__CHANNEL_STATE__)) :\
   ((__HANDLE__)->ChannelNState[3] = (__CHANNEL_STATE__)))

/* 设置所有互补通道状态宏定义：统一设置所有4个互补通道的状态 */
#define TIM_CHANNEL_N_STATE_SET_ALL(__HANDLE__,  __CHANNEL_STATE__) do { \
                                                                         (__HANDLE__)->ChannelNState[0] = \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[1] = \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[2] = \
                                                                         (__CHANNEL_STATE__);  \
                                                                         (__HANDLE__)->ChannelNState[3] = \
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
HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim); // 初始化定时器时基单元
HAL_StatusTypeDef HAL_TIM_Base_DeInit(TIM_HandleTypeDef *htim); // 反初始化定时器时基单元
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim); // 初始化底层硬件(MSP)，如时钟使能、GPIO配置
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim); // 反初始化底层硬件(MSP)
/* 阻塞模式：轮询 */
HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim); // 启动定时器(阻塞模式)
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim); // 停止定时器(阻塞模式)
/* 非阻塞模式：中断 */
HAL_StatusTypeDef HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *htim); // 启动定时器(中断模式)
HAL_StatusTypeDef HAL_TIM_Base_Stop_IT(TIM_HandleTypeDef *htim); // 停止定时器(中断模式)
/* 非阻塞模式：DMA */
HAL_StatusTypeDef HAL_TIM_Base_Start_DMA(TIM_HandleTypeDef *htim, const uint32_t *pData, uint16_t Length); // 启动定时器(DMA模式)
HAL_StatusTypeDef HAL_TIM_Base_Stop_DMA(TIM_HandleTypeDef *htim); // 停止定时器(DMA模式)
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group2 TIM 输出比较功能函数
  *  @brief   TIM 输出比较功能函数
  * @{
  */
/* 定时器输出比较功能函数 *********************************************/
HAL_StatusTypeDef HAL_TIM_OC_Init(TIM_HandleTypeDef *htim); // 初始化输出比较模式
HAL_StatusTypeDef HAL_TIM_OC_DeInit(TIM_HandleTypeDef *htim); // 反初始化输出比较模式
void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim); // 初始化底层硬件(MSP)
void HAL_TIM_OC_MspDeInit(TIM_HandleTypeDef *htim); // 反初始化底层硬件(MSP)
/* 阻塞模式：轮询 */
HAL_StatusTypeDef HAL_TIM_OC_Start(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动输出比较(阻塞模式)
HAL_StatusTypeDef HAL_TIM_OC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止输出比较(阻塞模式)
/* 非阻塞模式：中断 */
HAL_StatusTypeDef HAL_TIM_OC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动输出比较(中断模式)
HAL_StatusTypeDef HAL_TIM_OC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止输出比较(中断模式)
/* 非阻塞模式：DMA */
HAL_StatusTypeDef HAL_TIM_OC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                       uint16_t Length); // 启动输出比较(DMA模式)
HAL_StatusTypeDef HAL_TIM_OC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止输出比较(DMA模式)
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group3 TIM PWM功能函数
  *  @brief   TIM PWM功能函数
  * @{
  */
/* 定时器PWM功能函数 ********************************************************/
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim); // 初始化PWM模式
HAL_StatusTypeDef HAL_TIM_PWM_DeInit(TIM_HandleTypeDef *htim); // 反初始化PWM模式
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim); // 初始化底层硬件(MSP)
void HAL_TIM_PWM_MspDeInit(TIM_HandleTypeDef *htim); // 反初始化底层硬件(MSP)
/* 阻塞模式：轮询 */
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动PWM输出(阻塞模式)
HAL_StatusTypeDef HAL_TIM_PWM_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止PWM输出(阻塞模式)
/* 非阻塞模式：中断 */
HAL_StatusTypeDef HAL_TIM_PWM_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动PWM输出(中断模式)
HAL_StatusTypeDef HAL_TIM_PWM_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止PWM输出(中断模式)
/* 非阻塞模式：DMA */
HAL_StatusTypeDef HAL_TIM_PWM_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                        uint16_t Length); // 启动PWM输出(DMA模式)
HAL_StatusTypeDef HAL_TIM_PWM_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止PWM输出(DMA模式)
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group4 TIM 输入捕获功能函数
  *  @brief   TIM 输入捕获功能函数
  * @{
  */
/* 定时器输入捕获功能函数 **********************************************/
HAL_StatusTypeDef HAL_TIM_IC_Init(TIM_HandleTypeDef *htim); // 初始化输入捕获模式
HAL_StatusTypeDef HAL_TIM_IC_DeInit(TIM_HandleTypeDef *htim); // 反初始化输入捕获模式
void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim); // 初始化底层硬件(MSP)
void HAL_TIM_IC_MspDeInit(TIM_HandleTypeDef *htim); // 反初始化底层硬件(MSP)
/* 阻塞模式：轮询 */
HAL_StatusTypeDef HAL_TIM_IC_Start(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动输入捕获(阻塞模式)
HAL_StatusTypeDef HAL_TIM_IC_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止输入捕获(阻塞模式)
/* 非阻塞模式：中断 */
HAL_StatusTypeDef HAL_TIM_IC_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动输入捕获(中断模式)
HAL_StatusTypeDef HAL_TIM_IC_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止输入捕获(中断模式)
/* 非阻塞模式：DMA */
HAL_StatusTypeDef HAL_TIM_IC_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData, uint16_t Length); // 启动输入捕获(DMA模式)
HAL_StatusTypeDef HAL_TIM_IC_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止输入捕获(DMA模式)
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group5 TIM 单脉冲功能函数
  *  @brief   TIM 单脉冲功能函数
  * @{
  */
/* 定时器单脉冲功能函数 **************************************************/
HAL_StatusTypeDef HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode); // 初始化单脉冲模式
HAL_StatusTypeDef HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim); // 反初始化单脉冲模式
void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim); // 初始化底层硬件(MSP)
void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim); // 反初始化底层硬件(MSP)
/* 阻塞模式：轮询 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel); // 启动单脉冲输出(阻塞模式)
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel); // 停止单脉冲输出(阻塞模式)
/* 非阻塞模式：中断 */
HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel); // 启动单脉冲输出(中断模式)
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel); // 停止单脉冲输出(中断模式)
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group6 TIM 编码器功能函数
  *  @brief   TIM 编码器功能函数
  * @{
  */
/* 定时器编码器功能函数 ****************************************************/
HAL_StatusTypeDef HAL_TIM_Encoder_Init(TIM_HandleTypeDef *htim, const TIM_Encoder_InitTypeDef *sConfig); // 初始化编码器模式
HAL_StatusTypeDef HAL_TIM_Encoder_DeInit(TIM_HandleTypeDef *htim); // 反初始化编码器模式
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim); // 初始化底层硬件(MSP)
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim); // 反初始化底层硬件(MSP)
/* 阻塞模式：轮询 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动编码器接口(阻塞模式)
HAL_StatusTypeDef HAL_TIM_Encoder_Stop(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止编码器接口(阻塞模式)
/* 非阻塞模式：中断 */
HAL_StatusTypeDef HAL_TIM_Encoder_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 启动编码器接口(中断模式)
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止编码器接口(中断模式)
/* 非阻塞模式：DMA */
HAL_StatusTypeDef HAL_TIM_Encoder_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1,
                                            uint32_t *pData2, uint16_t Length); // 启动编码器接口(DMA模式)
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel); // 停止编码器接口(DMA模式)
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group7 TIM 中断处理管理
  *  @brief   中断处理管理
  * @{
  */
/* 中断处理函数  ***********************************************/
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim); // 定时器中断通用处理函数
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group8 TIM 外设控制功能函数
  *  @brief   外设控制功能函数
  * @{
  */
/* 控制函数  *********************************************************/
HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                           uint32_t Channel); // 配置输出比较通道
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                            uint32_t Channel); // 配置PWM通道
HAL_StatusTypeDef HAL_TIM_IC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_IC_InitTypeDef *sConfig,
                                           uint32_t Channel); // 配置输入捕获通道
HAL_StatusTypeDef HAL_TIM_OnePulse_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OnePulse_InitTypeDef *sConfig,
                                                 uint32_t OutputChannel,  uint32_t InputChannel); // 配置单脉冲通道
HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim,
                                           const TIM_ClearInputConfigTypeDef *sClearInputConfig,
                                           uint32_t Channel); // 配置输出比较参考清除
HAL_StatusTypeDef HAL_TIM_ConfigClockSource(TIM_HandleTypeDef *htim, const TIM_ClockConfigTypeDef *sClockSourceConfig); // 配置定时器时钟源
HAL_StatusTypeDef HAL_TIM_ConfigTI1Input(TIM_HandleTypeDef *htim, uint32_t TI1_Selection); // 配置TI1输入
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig); // 配置从模式同步(阻塞)
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro_IT(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig); // 配置从模式同步(中断)
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                              uint32_t BurstRequestSrc, const uint32_t  *BurstBuffer,
                                              uint32_t  BurstLength); // 启动DMA突发写操作
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiWriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                   uint32_t BurstRequestSrc, const uint32_t *BurstBuffer,
                                                   uint32_t BurstLength,  uint32_t DataLength); // 启动DMA多次突发写操作
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc); // 停止DMA突发写操作
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                             uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength); // 启动DMA突发读操作
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                  uint32_t BurstRequestSrc, uint32_t  *BurstBuffer,
                                                  uint32_t  BurstLength, uint32_t  DataLength); // 启动DMA多次突发读操作
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc); // 停止DMA突发读操作
HAL_StatusTypeDef HAL_TIM_GenerateEvent(TIM_HandleTypeDef *htim, uint32_t EventSource); // 软件生成事件
uint32_t HAL_TIM_ReadCapturedValue(const TIM_HandleTypeDef *htim, uint32_t Channel); // 读取捕获值
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group9 TIM 回调函数
  *  @brief   TIM 回调函数
  * @{
  */
/* 非阻塞模式下的回调函数 (中断和DMA) *************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim); // 周期溢出回调函数(更新中断)
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim); // 周期溢出半完成回调函数(DMA双缓冲)
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim); // 输出比较延时结束回调函数
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim); // 输入捕获回调函数
void HAL_TIM_IC_CaptureHalfCpltCallback(TIM_HandleTypeDef *htim); // 输入捕获半完成回调函数(DMA双缓冲)
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim); // PWM脉冲结束回调函数
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim); // PWM脉冲半结束回调函数(DMA双缓冲)
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim); // 触发检测回调函数
void HAL_TIM_TriggerHalfCpltCallback(TIM_HandleTypeDef *htim); // 触发检测半完成回调函数(DMA双缓冲)
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim); // 错误回调函数

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_TIM_RegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID,
                                           pTIM_CallbackTypeDef pCallback); // 注册用户自定义回调函数
HAL_StatusTypeDef HAL_TIM_UnRegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID); // 注销回调函数，恢复默认
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group10 TIM 外设状态功能函数
  *  @brief  外设状态功能函数
  * @{
  */
/* 外设状态函数  ************************************************/
HAL_TIM_StateTypeDef HAL_TIM_Base_GetState(const TIM_HandleTypeDef *htim); // 获取时基模式状态
HAL_TIM_StateTypeDef HAL_TIM_OC_GetState(const TIM_HandleTypeDef *htim); // 获取输出比较模式状态
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(const TIM_HandleTypeDef *htim); // 获取PWM模式状态
HAL_TIM_StateTypeDef HAL_TIM_IC_GetState(const TIM_HandleTypeDef *htim); // 获取输入捕获模式状态
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(const TIM_HandleTypeDef *htim); // 获取单脉冲模式状态
HAL_TIM_StateTypeDef HAL_TIM_Encoder_GetState(const TIM_HandleTypeDef *htim); // 获取编码器模式状态

/* 外设通道状态函数  ************************************************/
HAL_TIM_ActiveChannel HAL_TIM_GetActiveChannel(const TIM_HandleTypeDef *htim); // 获取当前活动的通道
HAL_TIM_ChannelStateTypeDef HAL_TIM_GetChannelState(const TIM_HandleTypeDef *htim,  uint32_t Channel); // 获取指定通道的状态
HAL_TIM_DMABurstStateTypeDef HAL_TIM_DMABurstState(const TIM_HandleTypeDef *htim); // 获取DMA突发传输状态
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
void TIM_Base_SetConfig(TIM_TypeDef *TIMx, const TIM_Base_InitTypeDef *Structure); // 时基单元配置底层函数
void TIM_TI1_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter); // TI1配置底层函数
void TIM_OC2_SetConfig(TIM_TypeDef *TIMx, const TIM_OC_InitTypeDef *OC_Config); // OC2配置底层函数
void TIM_ETR_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ExtTRGPrescaler,
                       uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter); // ETR配置底层函数

void TIM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma); // DMA延时脉冲半完成回调
void TIM_DMAError(DMA_HandleTypeDef *hdma); // DMA错误处理
void TIM_DMACaptureCplt(DMA_HandleTypeDef *hdma); // DMA捕获完成回调
void TIM_DMACaptureHalfCplt(DMA_HandleTypeDef *hdma); // DMA捕获半完成回调
void TIM_CCxChannelCmd(TIM_TypeDef *TIMx, uint32_t Channel, uint32_t ChannelState); // 通道使能/禁用底层函数

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
void TIM_ResetCallback(TIM_HandleTypeDef *htim); // 重置回调函数为默认值
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
