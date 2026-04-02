/** @addtogroup TIM_Exported_Functions_Group5 TIM One Pulse functions
  *  @brief   TIM One Pulse functions
  * @{
  */
/* 定时器单脉冲函数 **************************************************/
// 单脉冲模式初始化
HAL_StatusTypeDef HAL_TIM_OnePulse_Init(TIM_HandleTypeDef *htim, uint32_t OnePulseMode);
// 单脉冲模式反初始化（复位）
HAL_StatusTypeDef HAL_TIM_OnePulse_DeInit(TIM_HandleTypeDef *htim);
// 单脉冲模式 MSP 初始化（时钟、GPIO 等，由用户重写）
void HAL_TIM_OnePulse_MspInit(TIM_HandleTypeDef *htim);
// 单脉冲模式 MSP 反初始化
void HAL_TIM_OnePulse_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式：轮询 */
// 启动单脉冲模式（阻塞方式）
HAL_StatusTypeDef HAL_TIM_OnePulse_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
// 停止单脉冲模式（阻塞方式）
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/* 非阻塞模式：中断 */
// 启动单脉冲模式（中断方式）
HAL_StatusTypeDef HAL_TIM_OnePulse_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
// 停止单脉冲模式（中断方式）
HAL_StatusTypeDef HAL_TIM_OnePulse_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group6 TIM Encoder functions
  *  @brief   TIM Encoder functions
  * @{
  */
/* 定时器编码器函数 ****************************************************/
// 编码器模式初始化
HAL_StatusTypeDef HAL_TIM_Encoder_Init(TIM_HandleTypeDef *htim, const TIM_Encoder_InitTypeDef *sConfig);
// 编码器模式反初始化
HAL_StatusTypeDef HAL_TIM_Encoder_DeInit(TIM_HandleTypeDef *htim);
// 编码器模式 MSP 初始化
void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim);
// 编码器模式 MSP 反初始化
void HAL_TIM_Encoder_MspDeInit(TIM_HandleTypeDef *htim);
/* 阻塞模式：轮询 */
// 启动编码器模式（阻塞方式）
HAL_StatusTypeDef HAL_TIM_Encoder_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止编码器模式（阻塞方式）
HAL_StatusTypeDef HAL_TIM_Encoder_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式：中断 */
// 启动编码器模式（中断方式）
HAL_StatusTypeDef HAL_TIM_Encoder_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止编码器模式（中断方式）
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式：DMA */
// 启动编码器模式（DMA方式）
HAL_StatusTypeDef HAL_TIM_Encoder_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t *pData1,
                                            uint32_t *pData2, uint16_t Length);
// 停止编码器模式（DMA方式）
HAL_StatusTypeDef HAL_TIM_Encoder_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIM_Exported_Functions_Group7 TIM IRQ handler management
  *  @brief   IRQ handler management
  * @{
  */
/* 中断处理函数  ***********************************************/
// 定时器中断通用处理函数
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group8 TIM Peripheral Control functions
  *  @brief   Peripheral Control functions
  * @{
  */
/* 控制函数  *********************************************************/
// 配置输出比较通道
HAL_StatusTypeDef HAL_TIM_OC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                           uint32_t Channel);
// 配置 PWM 通道
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_OC_InitTypeDef *sConfig,
                                            uint32_t Channel);
// 配置输入捕获通道
HAL_StatusTypeDef HAL_TIM_IC_ConfigChannel(TIM_HandleTypeDef *htim, const TIM_IC_InitTypeDef *sConfig,
                                           uint32_t Channel);
// 配置单脉冲通道
HAL_StatusTypeDef HAL_TIM_OnePulse_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OnePulse_InitTypeDef *sConfig,
                                                 uint32_t OutputChannel,  uint32_t InputChannel);
// 配置输出比较参考清除（OCREF clear）
HAL_StatusTypeDef HAL_TIM_ConfigOCrefClear(TIM_HandleTypeDef *htim,
                                           const TIM_ClearInputConfigTypeDef *sClearInputConfig,
                                           uint32_t Channel);
// 配置定时器时钟源
HAL_StatusTypeDef HAL_TIM_ConfigClockSource(TIM_HandleTypeDef *htim, const TIM_ClockConfigTypeDef *sClockSourceConfig);
// 配置 TI1 输入选择
HAL_StatusTypeDef HAL_TIM_ConfigTI1Input(TIM_HandleTypeDef *htim, uint32_t TI1_Selection);
// 配置从模式同步
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig);
// 配置从模式同步（中断方式）
HAL_StatusTypeDef HAL_TIM_SlaveConfigSynchro_IT(TIM_HandleTypeDef *htim, const TIM_SlaveConfigTypeDef *sSlaveConfig);
// 启动 DMA 突发写入
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                              uint32_t BurstRequestSrc, const uint32_t  *BurstBuffer,
                                              uint32_t  BurstLength);
// 启动 DMA 多次突发写入
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiWriteStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                   uint32_t BurstRequestSrc, const uint32_t *BurstBuffer,
                                                   uint32_t BurstLength,  uint32_t DataLength);
// 停止 DMA 突发写入
HAL_StatusTypeDef HAL_TIM_DMABurst_WriteStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
// 启动 DMA 突发读取
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                             uint32_t BurstRequestSrc, uint32_t  *BurstBuffer, uint32_t  BurstLength);
// 启动 DMA 多次突发读取
HAL_StatusTypeDef HAL_TIM_DMABurst_MultiReadStart(TIM_HandleTypeDef *htim, uint32_t BurstBaseAddress,
                                                  uint32_t BurstRequestSrc, uint32_t  *BurstBuffer,
                                                  uint32_t  BurstLength, uint32_t  DataLength);
// 停止 DMA 突发读取
HAL_StatusTypeDef HAL_TIM_DMABurst_ReadStop(TIM_HandleTypeDef *htim, uint32_t BurstRequestSrc);
// 软件生成事件
HAL_StatusTypeDef HAL_TIM_GenerateEvent(TIM_HandleTypeDef *htim, uint32_t EventSource);
// 读取捕获值
uint32_t HAL_TIM_ReadCapturedValue(const TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group9 TIM Callbacks functions
  *  @brief   TIM Callbacks functions
  * @{
  */
/* 非阻塞模式下的回调函数 (中断和 DMA) *************************/
// 更新中断回调（周期溢出）
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
// 更新中断半完成回调（用于 DMA 双缓冲）
void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef *htim);
// 输出比较延迟结束回调
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);
// 输入捕获回调
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim);
// 输入捕获半完成回调
void HAL_TIM_IC_CaptureHalfCpltCallback(TIM_HandleTypeDef *htim);
// PWM 脉冲结束回调
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim);
// PWM 脉冲半完成回调
void HAL_TIM_PWM_PulseFinishedHalfCpltCallback(TIM_HandleTypeDef *htim);
// 触发回调
void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim);
// 触发半完成回调
void HAL_TIM_TriggerHalfCpltCallback(TIM_HandleTypeDef *htim);
// 错误回调
void HAL_TIM_ErrorCallback(TIM_HandleTypeDef *htim);

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
// 注册自定义回调函数
HAL_StatusTypeDef HAL_TIM_RegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID,
                                           pTIM_CallbackTypeDef pCallback);
// 注销回调函数（恢复默认）
HAL_StatusTypeDef HAL_TIM_UnRegisterCallback(TIM_HandleTypeDef *htim, HAL_TIM_CallbackIDTypeDef CallbackID);
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup TIM_Exported_Functions_Group10 TIM Peripheral State functions
  *  @brief  Peripheral State functions
  * @{
  */
/* 外设状态函数  ************************************************/
// 获取基础定时器状态
HAL_TIM_StateTypeDef HAL_TIM_Base_GetState(const TIM_HandleTypeDef *htim);
// 获取输出比较状态
HAL_TIM_StateTypeDef HAL_TIM_OC_GetState(const TIM_HandleTypeDef *htim);
// 获取 PWM 状态
HAL_TIM_StateTypeDef HAL_TIM_PWM_GetState(const TIM_HandleTypeDef *htim);
// 获取输入捕获状态
HAL_TIM_StateTypeDef HAL_TIM_IC_GetState(const TIM_HandleTypeDef *htim);
// 获取单脉冲状态
HAL_TIM_StateTypeDef HAL_TIM_OnePulse_GetState(const TIM_HandleTypeDef *htim);
// 获取编码器状态
HAL_TIM_StateTypeDef HAL_TIM_Encoder_GetState(const TIM_HandleTypeDef *htim);

/* 外设通道状态函数  ************************************************/
// 获取当前活动的通道
HAL_TIM_ActiveChannel HAL_TIM_GetActiveChannel(const TIM_HandleTypeDef *htim);
// 获取指定通道的状态
HAL_TIM_ChannelStateTypeDef HAL_TIM_GetChannelState(const TIM_HandleTypeDef *htim,  uint32_t Channel);
// 获取 DMA 突发传输状态
HAL_TIM_DMABurstStateTypeDef HAL_TIM_DMABurstState(const TIM_HandleTypeDef *htim);
/**
  * @}
  */

/**
  * @}
  */
/* 导出函数结束 -------------------------------------------------*/

/* 私有函数----------------------------------------------------------*/
/** @defgroup TIM_Private_Functions TIM Private Functions
  * @{
  */
// 基础定时器配置函数
void TIM_Base_SetConfig(TIM_TypeDef *TIMx, const TIM_Base_InitTypeDef *Structure);
// TI1 输入配置函数
void TIM_TI1_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ICPolarity, uint32_t TIM_ICSelection, uint32_t TIM_ICFilter);
// OC2 输出比较配置函数
void TIM_OC2_SetConfig(TIM_TypeDef *TIMx, const TIM_OC_InitTypeDef *OC_Config);
// ETR 外部触发配置函数
void TIM_ETR_SetConfig(TIM_TypeDef *TIMx, uint32_t TIM_ExtTRGPrescaler,
                       uint32_t TIM_ExtTRGPolarity, uint32_t ExtTRGFilter);

// DMA 延迟脉冲半传输完成回调
void TIM_DMADelayPulseHalfCplt(DMA_HandleTypeDef *hdma);
// DMA 错误处理
void TIM_DMAError(DMA_HandleTypeDef *hdma);
// DMA 捕获完成回调
void TIM_DMACaptureCplt(DMA_HandleTypeDef *hdma);
// DMA 捕获半传输完成回调
void TIM_DMACaptureHalfCplt(DMA_HandleTypeDef *hdma);
// 通道使能/禁用控制
void TIM_CCxChannelCmd(TIM_TypeDef *TIMx, uint32_t Channel, uint32_t ChannelState);

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
// 重置回调函数指针
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
