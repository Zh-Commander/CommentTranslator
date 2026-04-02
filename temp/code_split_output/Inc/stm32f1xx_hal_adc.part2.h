/**
  * @brief  设置ADC通道0到通道9的采样时间
  * @param  _SAMPLETIME_: 采样时间参数
  * @param  _CHANNELNB_: 通道编号
  * @retval 无
  */
// 宏定义：设置SMPR2寄存器中的采样时间
// SMPR2寄存器负责管理通道0-9的采样时间
// 通过通道编号计算移位位置，将采样时间设置到对应通道的位域中
#define ADC_SMPR2(_SAMPLETIME_, _CHANNELNB_)                                   \
  ((_SAMPLETIME_) << (ADC_SMPR2_SMP1_Pos * (_CHANNELNB_)))

/**
  * @brief  设置规则组通道的转换顺序，适用于排名1到6
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 转换序列中的排名(1-6)
  * @retval 无
  */
// 宏定义：设置SQR3寄存器中的通道转换顺序
// SQR3寄存器管理规则组序列中的第1到第6个转换
// 通过排名计算移位量，将通道编号填入对应的SQ位置
#define ADC_SQR3_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR3_SQ2_Pos * ((_RANKNB_) - 1)))

/**
  * @brief  设置规则组通道的转换顺序，适用于排名7到12
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 转换序列中的排名(7-12)
  * @retval 无
  */
// 宏定义：设置SQR2寄存器中的通道转换顺序
// SQR2寄存器管理规则组序列中的第7到第12个转换
// 注意：排名需要减去7来计算正确的移位位置
#define ADC_SQR2_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR2_SQ8_Pos * ((_RANKNB_) - 7)))

/**
  * @brief  设置规则组通道的转换顺序，适用于排名13到16
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 转换序列中的排名(13-16)
  * @retval 无
  */
// 宏定义：设置SQR1寄存器中的通道转换顺序
// SQR1寄存器管理规则组序列中的第13到第16个转换
// 注意：排名需要减去13来计算正确的移位位置
#define ADC_SQR1_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR1_SQ14_Pos * ((_RANKNB_) - 13)))

/**
  * @brief  设置注入组的序列长度
  * @param  _JSQR_JL_: 序列长度
  * @retval 无
  */
// 宏定义：设置JSQR寄存器中的注入序列长度
// 实际长度需要减1后左移到对应位置
#define ADC_JSQR_JL_SHIFT(_JSQR_JL_)                                           \
  (((_JSQR_JL_) -1) << ADC_JSQR_JL_Pos)

/**
  * @brief  设置选定的注入组通道排名
  *         注意: 在STM32F1系列设备上，JSQR寄存器中的通道排名位置
  *               取决于注入序列器中选定的总排名数(排名序列从4-JL开始)
  * @param  _CHANNELNB_: 通道编号
  * @param  _RANKNB_: 排名编号
  * @param  _JSQR_JL_: 序列长度
  * @retval 无
  */
// 宏定义：设置注入组通道的转换顺序
// 注入组的序列配置较为复杂，位置取决于序列总长度
#define ADC_JSQR_RK_JL(_CHANNELNB_, _RANKNB_, _JSQR_JL_)                       \
  ((_CHANNELNB_) << (ADC_JSQR_JSQ2_Pos * ((4 - ((_JSQR_JL_) - (_RANKNB_))) - 1)))

/**
  * @brief  使能ADC连续转换模式
  * @param  _CONTINUOUS_MODE_: 连续模式设置
  * @retval 无
  */
// 宏定义：配置CR2寄存器中的CONT位
// 用于控制ADC是单次转换还是连续转换
#define ADC_CR2_CONTINUOUS(_CONTINUOUS_MODE_)                                  \
  ((_CONTINUOUS_MODE_) << ADC_CR2_CONT_Pos)

/**
  * @brief  配置规则组通道的不连续转换数量
  * @param  _NBR_DISCONTINUOUS_CONV_: 不连续转换的数量
  * @retval 无
  */
// 宏定义：设置CR1寄存器中的DISCNUM位
// 用于设置每次触发转换的通道数量
#define ADC_CR1_DISCONTINUOUS_NUM(_NBR_DISCONTINUOUS_CONV_)                    \
  (((_NBR_DISCONTINUOUS_CONV_) - 1) << ADC_CR1_DISCNUM_Pos)

/**
  * @brief  使能ADC扫描模式，以便使用序列器转换多个排名
  * @param  _SCAN_MODE_: 扫描转换模式
  * @retval 无
  */
/* 注意: 扫描模式与ENABLE进行比较是为了兼容旧代码，该参数等同于ADC_SCAN_ENABLE */
// 宏定义：配置CR1寄存器中的SCAN位
// 扫描模式用于多通道采集
#define ADC_CR1_SCAN_SET(_SCAN_MODE_)                                          \
  (( ((_SCAN_MODE_) == ADC_SCAN_ENABLE) || ((_SCAN_MODE_) == ENABLE)           \
   )? (ADC_SCAN_ENABLE) : (ADC_SCAN_DISABLE)                                   \
  )

/**
  * @brief  获取所有通道上的最大ADC转换周期数
  *         返回选定的采样时间 + 转换时间(12.5个ADC时钟周期)
  *         在4个范围内近似采样时间，返回最高值：
  *           低于7.5个周期 {1.5个周期; 7.5个周期},
  *           介于13.5个周期和28.5个周期之间 {13.5个周期; 28.5个周期}
  *           介于41.5个周期和71.5个周期之间 {41.5个周期; 55.5个周期; 71.5个周期}
  *           等于239.5个周期
  *         单位: ADC时钟周期
  * @param  __HANDLE__: ADC句柄
  * @retval 所有通道上的ADC转换周期数
  */   
// 宏定义：计算最大转换周期
// 通过检查SMPR1和SMPR2寄存器的位状态，估算当前配置下的最大采样时间
// 这对于计算ADC转换超时时间非常有用
#define ADC_CONVCYCLES_MAX_RANGE(__HANDLE__)                                                                     \
    (( (((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT2) == RESET)  &&                     \
       (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT2) == RESET) ) ?                     \
                                                                                                                 \
          (( (((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1) == RESET)  &&               \
             (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1) == RESET) ) ?               \
               ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_7CYCLES5 : ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_28CYCLES5)   \
          :                                                                                                      \
          ((((((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR2BIT1) == RESET)  &&               \
             (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT1) == RESET)) ||               \
            ((((__HANDLE__)->Instance->SMPR2 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0) == RESET)  &&               \
             (((__HANDLE__)->Instance->SMPR1 & ADC_SAMPLETIME_ALLCHANNELS_SMPR1BIT0) == RESET))) ?               \
               ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_71CYCLES5 : ADC_CONVERSIONCLOCKCYCLES_SAMPLETIME_239CYCLES5) \
     )

// 参数检查宏：检查数据对齐方式是否合法
#define IS_ADC_DATA_ALIGN(ALIGN) (((ALIGN) == ADC_DATAALIGN_RIGHT) || \
                                  ((ALIGN) == ADC_DATAALIGN_LEFT)    )

// 参数检查宏：检查扫描模式参数是否合法
#define IS_ADC_SCAN_MODE(SCAN_MODE) (((SCAN_MODE) == ADC_SCAN_DISABLE) || \
                                     ((SCAN_MODE) == ADC_SCAN_ENABLE)    )

// 参数检查宏：检查外部触发转换边沿设置是否合法
#define IS_ADC_EXTTRIG_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGCONVEDGE_NONE)  || \
                                   ((EDGE) == ADC_EXTERNALTRIGCONVEDGE_RISING)  )

// 参数检查宏：检查ADC通道编号是否合法
#define IS_ADC_CHANNEL(CHANNEL) (((CHANNEL) == ADC_CHANNEL_0)           || \
                                 ((CHANNEL) == ADC_CHANNEL_1)           || \
                                 ((CHANNEL) == ADC_CHANNEL_2)           || \
                                 ((CHANNEL) == ADC_CHANNEL_3)           || \
                                 ((CHANNEL) == ADC_CHANNEL_4)           || \
                                 ((CHANNEL) == ADC_CHANNEL_5)           || \
                                 ((CHANNEL) == ADC_CHANNEL_6)           || \
                                 ((CHANNEL) == ADC_CHANNEL_7)           || \
                                 ((CHANNEL) == ADC_CHANNEL_8)           || \
                                 ((CHANNEL) == ADC_CHANNEL_9)           || \
                                 ((CHANNEL) == ADC_CHANNEL_10)          || \
                                 ((CHANNEL) == ADC_CHANNEL_11)          || \
                                 ((CHANNEL) == ADC_CHANNEL_12)          || \
                                 ((CHANNEL) == ADC_CHANNEL_13)          || \
                                 ((CHANNEL) == ADC_CHANNEL_14)          || \
                                 ((CHANNEL) == ADC_CHANNEL_15)          || \
                                 ((CHANNEL) == ADC_CHANNEL_16)          || \
                                 ((CHANNEL) == ADC_CHANNEL_17)            )

// 参数检查宏：检查采样时间设置是否合法
#define IS_ADC_SAMPLE_TIME(TIME) (((TIME) == ADC_SAMPLETIME_1CYCLE_5)    || \
                                  ((TIME) == ADC_SAMPLETIME_7CYCLES_5)   || \
                                  ((TIME) == ADC_SAMPLETIME_13CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_28CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_41CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_55CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_71CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_239CYCLES_5)   )

// 参数检查宏：检查规则组转换排名是否合法(1-16)
#define IS_ADC_REGULAR_RANK(CHANNEL) (((CHANNEL) == ADC_REGULAR_RANK_1 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_2 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_3 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_4 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_5 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_6 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_7 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_8 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_9 ) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_10) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_11) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_12) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_13) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_14) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_15) || \
                                      ((CHANNEL) == ADC_REGULAR_RANK_16)   )

// 参数检查宏：检查模拟看门狗模式配置是否合法
#define IS_ADC_ANALOG_WATCHDOG_MODE(WATCHDOG) (((WATCHDOG) == ADC_ANALOGWATCHDOG_NONE)             || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REG)       || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_INJEC)     || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)  || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REG)          || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_INJEC)        || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REGINJEC)       )

// 参数检查宏：检查转换组类型是否合法(规则组、注入组或两者)
#define IS_ADC_CONVERSION_GROUP(CONVERSION) (((CONVERSION) == ADC_REGULAR_GROUP)         || \
                                             ((CONVERSION) == ADC_INJECTED_GROUP)        || \
                                             ((CONVERSION) == ADC_REGULAR_INJECTED_GROUP)  )

// 参数检查宏：检查ADC事件类型是否合法
#define IS_ADC_EVENT_TYPE(EVENT) ((EVENT) == ADC_AWD_EVENT)


/** @defgroup ADC_range_verification ADC范围验证
  * 对于唯一的ADC分辨率：12位
  * @{
  */
// 参数检查宏：检查ADC转换值是否在12位范围内(0-4095)
#define IS_ADC_RANGE(ADC_VALUE) ((ADC_VALUE) <= 0x0FFFU)
/**
  * @}
  */

/** @defgroup ADC_regular_nb_conv_verification ADC规则组转换数量验证
  * @{
  */
// 参数检查宏：检查规则组转换通道数量是否在1到16之间
#define IS_ADC_REGULAR_NB_CONV(LENGTH) (((LENGTH) >= 1U) && ((LENGTH) <= 16U))
/**
  * @}
  */

/** @defgroup ADC_regular_discontinuous_mode_number_verification ADC规则组不连续模式数量验证
  * @{
  */
// 参数检查宏：检查规则组不连续模式下的转换数量是否在1到8之间
#define IS_ADC_REGULAR_DISCONT_NUMBER(NUMBER) (((NUMBER) >= 1U) && ((NUMBER) <= 8U))
/**
  * @}
  */
      
/**
  * @}
  */
    
/* 包含ADC HAL扩展模块 */
#include "stm32f1xx_hal_adc_ex.h"

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup ADC_Exported_Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1
  * @{
  */


/* 初始化和反初始化函数  **********************************/
// ADC初始化函数
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef* hadc);
// ADC反初始化函数(恢复寄存器到默认值)
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
// ADC MSP初始化函数(用于配置底层硬件，如时钟、GPIO等)
void                    HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
// ADC MSP反初始化函数(用于释放底层硬件资源)
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/* 回调注册/注销函数  ***********************************/
// 注册ADC回调函数
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback);
// 注销ADC回调函数
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* IO操作函数  *****************************************************/

/** @addtogroup ADC_Exported_Functions_Group2
  * @{
  */


/* 阻塞模式：轮询方式 */
// 启动ADC转换(阻塞模式)
HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef* hadc);
// 停止ADC转换(阻塞模式)
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
// 等待ADC转换完成(阻塞模式，带超时)
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);
// 等待ADC事件发生(阻塞模式，带超时)
HAL_StatusTypeDef       HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout);

/* 非阻塞模式：中断方式 */
// 启动ADC转换(中断模式)
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
// 停止ADC转换(中断模式)
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);

/* 非阻塞模式：DMA方式 */
// 启动ADC转换(DMA模式)
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
// 停止ADC转换(DMA模式)
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);

/* ADC获取转换值，用于轮询或中断模式 */
// 获取ADC转换结果
uint32_t                HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);

/* ADC中断处理函数和回调函数，用于非阻塞模式(中断和DMA) */
// ADC中断处理函数(需在stm32f1xx_it.c中调用)
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc);
// 转换完成回调函数
void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
// 转换半完成回调函数(DMA模式使用)
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
// 模拟看门狗越限回调函数
void                    HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc);
// 错误回调函数
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
/**
  * @}
  */


/* 外设控制函数 ***********************************************/
/** @addtogroup ADC_Exported_Functions_Group3
  * @{
  */
// 配置ADC通道参数(采样时间、排名等)
HAL_StatusTypeDef       HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
// 配置模拟看门狗参数
HAL_StatusTypeDef       HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig);
/**
  * @}
  */


/* 外设状态函数 *************************************************/
/** @addtogroup ADC_Exported_Functions_Group4
  * @{
  */
// 获取ADC状态
uint32_t                HAL_ADC_GetState(ADC_HandleTypeDef* hadc);
// 获取ADC错误码
uint32_t                HAL_ADC_GetError(ADC_HandleTypeDef *hadc);
/**
  * @}
  */


/**
  * @}
  */


/* 内部HAL驱动函数 **********************************************/
/** @addtogroup ADC_Private_Functions
  * @{
  */
// 使能ADC
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc);
// 停止转换并禁用ADC
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc);
// ADC稳定时间延时
void              ADC_StabilizationTime(uint32_t DelayUs);
// DMA转换完成回调(内部调用)
void              ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);
// DMA半转换完成回调(内部调用)
void              ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma);
// DMA错误回调(内部调用)
void              ADC_DMAError(DMA_HandleTypeDef *hdma);
/**
  * @}
  */ 


/**
  * @}
  */ 

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


#endif /* __STM32F1xx_HAL_ADC_H */
