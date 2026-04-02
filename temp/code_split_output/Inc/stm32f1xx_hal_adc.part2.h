/**
  * @brief Set the ADC's sample time for channel numbers between 0 and 9.
  *         设置通道号 0 到 9 的 ADC 采样时间
  * @param _SAMPLETIME_: Sample time parameter.
  *                       采样时间参数
  * @param _CHANNELNB_: Channel number.  
  *                     通道编号
  * @retval None
  *         无返回值
  */
// 宏定义：设置 SMPR2 寄存器中的采样时间
// SMPR2 寄存器控制通道 0-9 的采样时间
// 计算原理：将采样时间值左移到对应通道的位位置
#define ADC_SMPR2(_SAMPLETIME_, _CHANNELNB_)                                   \
  ((_SAMPLETIME_) << (ADC_SMPR2_SMP1_Pos * (_CHANNELNB_)))

/**
  * @brief Set the selected regular channel rank for rank between 1 and 6.
  *         设置规则序列中排名 1 到 6 的通道
  * @param _CHANNELNB_: Channel number.
  *                     通道编号
  * @param _RANKNB_: Rank number.    
  *                  排名编号（转换顺序）
  * @retval None
  *         无返回值
  */
// 宏定义：设置 SQR3 寄存器中的通道排名
// SQR3 寄存器管理规则序列中的第 1 到第 6 个转换
#define ADC_SQR3_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR3_SQ2_Pos * ((_RANKNB_) - 1)))

/**
  * @brief Set the selected regular channel rank for rank between 7 and 12.
  *         设置规则序列中排名 7 到 12 的通道
  * @param _CHANNELNB_: Channel number.
  *                     通道编号
  * @param _RANKNB_: Rank number.    
  *                  排名编号（转换顺序）
  * @retval None
  *         无返回值
  */
// 宏定义：设置 SQR2 寄存器中的通道排名
// SQR2 寄存器管理规则序列中的第 7 到第 12 个转换
#define ADC_SQR2_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR2_SQ8_Pos * ((_RANKNB_) - 7)))

/**
  * @brief Set the selected regular channel rank for rank between 13 and 16.
  *         设置规则序列中排名 13 到 16 的通道
  * @param _CHANNELNB_: Channel number.
  *                     通道编号
  * @param _RANKNB_: Rank number.    
  *                  排名编号（转换顺序）
  * @retval None
  *         无返回值
  */
// 宏定义：设置 SQR1 寄存器中的通道排名
// SQR1 寄存器管理规则序列中的第 13 到第 16 个转换
#define ADC_SQR1_RK(_CHANNELNB_, _RANKNB_)                                     \
  ((_CHANNELNB_) << (ADC_SQR1_SQ14_Pos * ((_RANKNB_) - 13)))

/**
  * @brief Set the injected sequence length.
  *         设置注入组的序列长度
  * @param _JSQR_JL_: Sequence length.
  *                   序列长度
  * @retval None
  *         无返回值
  */
// 宏定义：计算注入序列长度的移位值
// 注入序列长度在 JSQR 寄存器中配置，实际长度 = JL + 1
#define ADC_JSQR_JL_SHIFT(_JSQR_JL_)                                           \
  (((_JSQR_JL_) -1) << ADC_JSQR_JL_Pos)

/**
  * @brief Set the selected injected channel rank
  *         设置选定的注入通道排名
  *        Note: on STM32F1 devices, channel rank position in JSQR register
  *              is depending on total number of ranks selected into
  *              injected sequencer (ranks sequence starting from 4-JL)
  *        注意：在 STM32F1 设备上，JSQR 寄存器中的通道排名位置取决于
  *              注入序列器中选定的排名总数（排名序列从 4-JL 开始）
  * @param _CHANNELNB_: Channel number.
  *                     通道编号
  * @param _RANKNB_: Rank number.
  *                  排名编号
  * @param _JSQR_JL_: Sequence length.
  *                   序列长度
  * @retval None
  *         无返回值
  */
// 宏定义：设置注入通道的排名
// 注入序列的排名位置计算比较特殊，依赖于总序列长度
#define ADC_JSQR_RK_JL(_CHANNELNB_, _RANKNB_, _JSQR_JL_)                       \
  ((_CHANNELNB_) << (ADC_JSQR_JSQ2_Pos * ((4 - ((_JSQR_JL_) - (_RANKNB_))) - 1)))

/**
  * @brief Enable ADC continuous conversion mode.
  *         使能 ADC 连续转换模式
  * @param _CONTINUOUS_MODE_: Continuous mode.
  *                           连续模式参数
  * @retval None
  *         无返回值
  */
// 宏定义：配置 CR2 寄存器中的 CONT 位，控制是否连续转换
#define ADC_CR2_CONTINUOUS(_CONTINUOUS_MODE_)                                  \
  ((_CONTINUOUS_MODE_) << ADC_CR2_CONT_Pos)

/**
  * @brief Configures the number of discontinuous conversions for the regular group channels.
  *         配置规则组通道的不连续转换数量
  * @param _NBR_DISCONTINUOUS_CONV_: Number of discontinuous conversions.
  *                                  不连续转换的数量
  * @retval None
  *         无返回值
  */
// 宏定义：设置 CR1 寄存器中的 DISCNUM 位
// 用于设置每次触发转换的通道数量（不连续模式）
#define ADC_CR1_DISCONTINUOUS_NUM(_NBR_DISCONTINUOUS_CONV_)                    \
  (((_NBR_DISCONTINUOUS_CONV_) - 1) << ADC_CR1_DISCNUM_Pos)

/**
  * @brief Enable ADC scan mode to convert multiple ranks with sequencer.
  *         使能 ADC 扫描模式，以便使用序列器转换多个排名
  * @param _SCAN_MODE_: Scan conversion mode.
  *                     扫描转换模式
  * @retval None
  *         无返回值
  */
/* Note: Scan mode is compared to ENABLE for legacy purpose, this parameter   */
/*       is equivalent to ADC_SCAN_ENABLE.                                    */
/* 注意：为了兼容性，扫描模式与 ENABLE 进行比较，此参数等效于 ADC_SCAN_ENABLE */
// 宏定义：设置扫描模式
// 如果参数是 ADC_SCAN_ENABLE 或 ENABLE，则返回使能值，否则返回禁用值
#define ADC_CR1_SCAN_SET(_SCAN_MODE_)                                          \
  (( ((_SCAN_MODE_) == ADC_SCAN_ENABLE) || ((_SCAN_MODE_) == ENABLE)           \
   )? (ADC_SCAN_ENABLE) : (ADC_SCAN_DISABLE)                                   \
  )

/**
  * @brief Get the maximum ADC conversion cycles on all channels.
  *         获取所有通道上的最大 ADC 转换周期数
  * Returns the selected sampling time + conversion time (12.5 ADC clock cycles)
  * 返回选定的采样时间 + 转换时间（12.5 个 ADC 时钟周期）
  * Approximation of sampling time within 4 ranges, returns the highest value:
  * 采样时间在 4 个范围内的近似值，返回最高值：
  *   below 7.5 cycles {1.5 cycle; 7.5 cycles},
  *   低于 7.5 周期 {1.5 周期; 7.5 周期}
  *   between 13.5 cycles and 28.5 cycles {13.5 cycles; 28.5 cycles}
  *   介于 13.5 周期和 28.5 周期之间 {13.5 周期; 28.5 周期}
  *   between 41.5 cycles and 71.5 cycles {41.5 cycles; 55.5 cycles; 71.5cycles}
  *   介于 41.5 周期和 71.5 周期之间 {41.5 周期; 55.5 周期; 71.5 周期}
  *   equal to 239.5 cycles
  *   等于 239.5 周期
  * Unit: ADC clock cycles
  * 单位：ADC 时钟周期
  * @param __HANDLE__: ADC handle
  *                    ADC 句柄
  * @retval ADC conversion cycles on all channels
  *         所有通道上的 ADC 转换周期
  */   
// 宏定义：计算最大转换周期
// 通过检查 SMPR1 和 SMPR2 寄存器中的位，估算当前配置下的最大采样时间
// 这对于计算 ADC 转换所需的总时间很有用
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
// 参数：ALIGN，对齐方式
// 检查是否为右对齐或左对齐
#define IS_ADC_DATA_ALIGN(ALIGN) (((ALIGN) == ADC_DATAALIGN_RIGHT) || \
                                  ((ALIGN) == ADC_DATAALIGN_LEFT)    )

// 参数检查宏：检查扫描模式设置是否合法
// 参数：SCAN_MODE，扫描模式
// 检查是否为使能或禁用
#define IS_ADC_SCAN_MODE(SCAN_MODE) (((SCAN_MODE) == ADC_SCAN_DISABLE) || \
                                     ((SCAN_MODE) == ADC_SCAN_ENABLE)    )

// 参数检查宏：检查外部触发边沿设置是否合法
// 参数：EDGE，触发边沿
// 检查是否为无触发或上升沿触发
#define IS_ADC_EXTTRIG_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGCONVEDGE_NONE)  || \
                                   ((EDGE) == ADC_EXTERNALTRIGCONVEDGE_RISING)  )

// 参数检查宏：检查 ADC 通道是否合法
// 参数：CHANNEL，通道号
// 检查通道号是否在 0 到 17 之间
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
// 参数：TIME，采样时间
// 检查是否为预定义的采样周期值之一
#define IS_ADC_SAMPLE_TIME(TIME) (((TIME) == ADC_SAMPLETIME_1CYCLE_5)    || \
                                  ((TIME) == ADC_SAMPLETIME_7CYCLES_5)   || \
                                  ((TIME) == ADC_SAMPLETIME_13CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_28CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_41CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_55CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_71CYCLES_5)  || \
                                  ((TIME) == ADC_SAMPLETIME_239CYCLES_5)   )

// 参数检查宏：检查规则组排名是否合法
// 参数：CHANNEL，此处实为 Rank（排名）
// 检查排名是否在 1 到 16 之间
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

// 参数检查宏：检查模拟看门狗模式是否合法
// 参数：WATCHDOG，看门狗模式
// 检查是否为单通道、所有通道等模式
#define IS_ADC_ANALOG_WATCHDOG_MODE(WATCHDOG) (((WATCHDOG) == ADC_ANALOGWATCHDOG_NONE)             || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REG)       || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_INJEC)     || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)  || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REG)          || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_INJEC)        || \
                                               ((WATCHDOG) == ADC_ANALOGWATCHDOG_ALL_REGINJEC)       )

// 参数检查宏：检查转换组类型是否合法
// 参数：CONVERSION，转换组
// 检查是否为规则组、注入组或两者
#define IS_ADC_CONVERSION_GROUP(CONVERSION) (((CONVERSION) == ADC_REGULAR_GROUP)         || \
                                             ((CONVERSION) == ADC_INJECTED_GROUP)        || \
                                             ((CONVERSION) == ADC_REGULAR_INJECTED_GROUP)  )

// 参数检查宏：检查 ADC 事件类型是否合法
// 参数：EVENT，事件类型
// 目前仅支持模拟看门狗事件
#define IS_ADC_EVENT_TYPE(EVENT) ((EVENT) == ADC_AWD_EVENT)


/** @defgroup ADC_range_verification ADC range verification
  *         ADC 范围验证
  * For a unique ADC resolution: 12 bits
  * 对于唯一的 ADC 分辨率：12 位
  * @{
  */
// 参数检查宏：检查 ADC 转换值是否在 12 位范围内
// 参数：ADC_VALUE，ADC 数值
// 12 位最大值为 0xFFF (4095)
#define IS_ADC_RANGE(ADC_VALUE) ((ADC_VALUE) <= 0x0FFFU)
/**
  * @}
  */

/** @defgroup ADC_regular_nb_conv_verification ADC regular nb conv verification
  *         ADC 规则组转换数量验证
  * @{
  */
// 参数检查宏：检查规则组转换通道数量是否合法
// 参数：LENGTH，转换数量
// 范围：1 到 16
#define IS_ADC_REGULAR_NB_CONV(LENGTH) (((LENGTH) >= 1U) && ((LENGTH) <= 16U))
/**
  * @}
  */

/** @defgroup ADC_regular_discontinuous_mode_number_verification ADC regular discontinuous mode number verification
  *         ADC 规则组不连续模式数量验证
  * @{
  */
// 参数检查宏：检查规则组不连续模式下的通道数量是否合法
// 参数：NUMBER，数量
// 范围：1 到 8
#define IS_ADC_REGULAR_DISCONT_NUMBER(NUMBER) (((NUMBER) >= 1U) && ((NUMBER) <= 8U))
/**
  * @}
  */
      
/**
  * @}
  */
    
/* Include ADC HAL Extension module */
/* 包含 ADC HAL 扩展模块头文件 */
#include "stm32f1xx_hal_adc_ex.h"

/* Exported functions --------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/
/** @addtogroup ADC_Exported_Functions
  * @{
  */

/** @addtogroup ADC_Exported_Functions_Group1
  * @{
  */


/* Initialization and de-initialization functions  **********************************/
/* 初始化和反初始化函数  **********************************/
// 初始化 ADC
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef* hadc);
// 反初始化 ADC（恢复默认状态）
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
// ADC 底层硬件初始化（时钟、GPIO 等），由用户在应用层实现
void                    HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
// ADC 底层硬件反初始化，由用户在应用层实现
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/* Callbacks Register/UnRegister functions  ***********************************/
/* 回调函数注册/注销函数  ***********************************/
// 注册 ADC 回调函数
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback);
// 注销 ADC 回调函数
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/* IO operation functions  *****************************************************/
/* IO 操作函数  *****************************************************/

/** @addtogroup ADC_Exported_Functions_Group2
  * @{
  */


/* Blocking mode: Polling */
/* 阻塞模式：轮询方式 */
// 启动 ADC 转换（阻塞式）
HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef* hadc);
// 停止 ADC 转换（阻塞式）
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
// 等待转换完成（轮询方式）
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);
// 等待事件（如模拟看门狗事件）
HAL_StatusTypeDef       HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout);

/* Non-blocking mode: Interruption */
/* 非阻塞模式：中断方式 */
// 启动 ADC 转换（中断方式）
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
// 停止 ADC 转换（中断方式）
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);

/* Non-blocking mode: DMA */
/* 非阻塞模式：DMA 方式 */
// 启动 ADC 转换（DMA 方式）
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
// 停止 ADC 转换（DMA 方式）
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);

/* ADC retrieve conversion value intended to be used with polling or interruption */
/* 获取 ADC 转换值，用于轮询或中断方式 */
uint32_t                HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);

/* ADC IRQHandler and Callbacks used in non-blocking modes (Interruption and DMA) */
/* ADC 中断处理函数和回调函数，用于非阻塞模式（中断和 DMA） */
// ADC 中断处理函数，需在 stm32f1xx_it.c 中调用
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc);
// 转换完成回调函数
void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
// 转换半完成回调函数（用于 DMA 循环模式）
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
// 模拟看门狗越界回调函数
void                    HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc);
// 错误回调函数
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);
/**
  * @}
  */


/* Peripheral Control functions ***********************************************/
/* 外设控制函数 ***********************************************/
/** @addtogroup ADC_Exported_Functions_Group3
  * @{
  */
// 配置 ADC 通道参数（采样时间、排名等）
HAL_StatusTypeDef       HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
// 配置模拟看门狗参数
HAL_StatusTypeDef       HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig);
/**
  * @}
  */


/* Peripheral State functions *************************************************/
/* 外设状态函数 *************************************************/
/** @addtogroup ADC_Exported_Functions_Group4
  * @{
  */
// 获取 ADC 状态
uint32_t                HAL_ADC_GetState(ADC_HandleTypeDef* hadc);
// 获取 ADC 错误码
uint32_t                HAL_ADC_GetError(ADC_HandleTypeDef *hadc);
/**
  * @}
  */


/**
  * @}
  */


/* Internal HAL driver functions **********************************************/
/* HAL 内部驱动函数 **********************************************/
/** @addtogroup ADC_Private_Functions
  * @{
  */
// 使能 ADC
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc);
// 停止转换并禁用 ADC
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc);
// 等待 ADC 稳定时间
void              ADC_StabilizationTime(uint32_t DelayUs);
// DMA 转换完成回调（内部调用）
void              ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);
// DMA 半转换完成回调（内部调用）
void              ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma);
// DMA 错误回调（内部调用）
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
