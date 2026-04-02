/** @defgroup TIM_DMA_Burst_Length TIM DMA Burst Length
  * @{
  */
// 以下宏定义用于配置DMA突发传输的长度，即每次DMA请求传输的寄存器数量
// 值对应TIMx_DCR寄存器的BL[4:0]位，左移了8位（0x100）
#define TIM_DMABURSTLENGTH_1TRANSFER       0x00000000U                          /*!< 传输长度为1个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定   */
#define TIM_DMABURSTLENGTH_2TRANSFERS      0x00000100U                          /*!< 传输长度为2个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_3TRANSFERS      0x00000200U                          /*!< 传输长度为3个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_4TRANSFERS      0x00000300U                          /*!< 传输长度为4个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_5TRANSFERS      0x00000400U                          /*!< 传输长度为5个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_6TRANSFERS      0x00000500U                          /*!< 传输长度为6个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_7TRANSFERS      0x00000600U                          /*!< 传输长度为7个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_8TRANSFERS      0x00000700U                          /*!< 传输长度为8个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_9TRANSFERS      0x00000800U                          /*!< 传输长度为9个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定  */
#define TIM_DMABURSTLENGTH_10TRANSFERS     0x00000900U                          /*!< 传输长度为10个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_11TRANSFERS     0x00000A00U                          /*!< 传输长度为11个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_12TRANSFERS     0x00000B00U                          /*!< 传输长度为12个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_13TRANSFERS     0x00000C00U                          /*!< 传输长度为13个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_14TRANSFERS     0x00000D00U                          /*!< 传输长度为14个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_15TRANSFERS     0x00000E00U                          /*!< 传输长度为15个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_16TRANSFERS     0x00000F00U                          /*!< 传输长度为16个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_17TRANSFERS     0x00001000U                          /*!< 传输长度为17个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_18TRANSFERS     0x00001100U                          /*!< 传输长度为18个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
/**
  * @}
  */

/** @defgroup DMA_Handle_index TIM DMA Handle Index
  * @{
  */
// 定义DMA句柄的索引，用于在定时器结构体中查找对应的DMA句柄
#define TIM_DMA_ID_UPDATE                ((uint16_t) 0x0000)       /*!< 用于更新事件的DMA句柄索引 */
#define TIM_DMA_ID_CC1                   ((uint16_t) 0x0001)       /*!< 用于捕获/比较通道1的DMA句柄索引 */
#define TIM_DMA_ID_CC2                   ((uint16_t) 0x0002)       /*!< 用于捕获/比较通道2的DMA句柄索引 */
#define TIM_DMA_ID_CC3                   ((uint16_t) 0x0003)       /*!< 用于捕获/比较通道3的DMA句柄索引 */
#define TIM_DMA_ID_CC4                   ((uint16_t) 0x0004)       /*!< 用于捕获/比较通道4的DMA句柄索引 */
#define TIM_DMA_ID_COMMUTATION           ((uint16_t) 0x0005)       /*!< 用于换相事件的DMA句柄索引 */
#define TIM_DMA_ID_TRIGGER               ((uint16_t) 0x0006)       /*!< 用于触发事件的DMA句柄索引 */
/**
  * @}
  */

/** @defgroup Channel_CC_State TIM Capture/Compare Channel State
  * @{
  */
// 定义通道状态，用于标记通道是否使能
#define TIM_CCx_ENABLE                   0x00000001U                            /*!< 输入或输出通道已使能 */
#define TIM_CCx_DISABLE                  0x00000000U                            /*!< 输入或输出通道已禁用 */
#define TIM_CCxN_ENABLE                  0x00000004U                            /*!< 互补输出通道已使能 */
#define TIM_CCxN_DISABLE                 0x00000000U                            /*!< 互补输出通道已禁用 */
/**
  * @}
  */

/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/
/* 导出常量结束 */

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TIM_Exported_Macros TIM Exported Macros
  * @{
  */

/** @brief  Reset TIM handle state.
  * @brief  复位TIM句柄状态。
  * @param  __HANDLE__ TIM handle.
  * @param  __HANDLE__ TIM句柄。
  * @retval None
  * @retval 无
  */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
// 如果启用了回调函数注册功能，则需要将所有的回调函数指针重置为NULL
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;         \
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;   \
                                                      (__HANDLE__)->Base_MspInitCallback         = NULL;            \
                                                      (__HANDLE__)->Base_MspDeInitCallback       = NULL;            \
                                                      (__HANDLE__)->IC_MspInitCallback           = NULL;            \
                                                      (__HANDLE__)->IC_MspDeInitCallback         = NULL;            \
                                                      (__HANDLE__)->OC_MspInitCallback           = NULL;            \
                                                      (__HANDLE__)->OC_MspDeInitCallback         = NULL;            \
                                                      (__HANDLE__)->PWM_MspInitCallback          = NULL;            \
                                                      (__HANDLE__)->PWM_MspDeInitCallback        = NULL;            \
                                                      (__HANDLE__)->OnePulse_MspInitCallback     = NULL;            \
                                                      (__HANDLE__)->OnePulse_MspDeInitCallback   = NULL;            \
                                                      (__HANDLE__)->Encoder_MspInitCallback      = NULL;            \
                                                      (__HANDLE__)->Encoder_MspDeInitCallback    = NULL;            \
                                                      (__HANDLE__)->HallSensor_MspInitCallback   = NULL;            \
                                                      (__HANDLE__)->HallSensor_MspDeInitCallback = NULL;            \
                                                     } while(0)
#else
// 如果未启用回调函数注册功能，则只复位状态标志
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;         \
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET; \
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;   \
                                                     } while(0)
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @brief  Enable the TIM peripheral.
  * @brief  使能TIM外设（计数器）。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @retval None
  * @retval 无
  */
// 设置CR1寄存器的CEN位（Counter Enable），启动定时器计数
#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))

/**
  * @brief  Enable the TIM main Output.
  * @brief  使能TIM主输出。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @retval None
  * @retval 无
  */
// 设置BDTR寄存器的MOE位，使能主输出，这对于高级定时器输出PWM至关重要
#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))

/**
  * @brief  Disable the TIM peripheral.
  * @brief  禁用TIM外设（计数器）。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @retval None
  * @retval 无
  */
// 只有当所有通道(CCxE)和互补通道(CCxNE)都未使能时，才关闭计数器，防止PWM输出异常
#define __HAL_TIM_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) \
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) \
      { \
        (__HANDLE__)->Instance->CR1 &= ~(TIM_CR1_CEN); \
      } \
    } \
  } while(0)

/**
  * @brief  Disable the TIM main Output.
  * @brief  禁用TIM主输出。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @retval None
  * @retval 无
  * @note The Main Output Enable of a timer instance is disabled only if all the CCx and CCxN channels have been
  *       disabled
  * @note 只有当所有的CCx和CCxN通道都被禁用时，定时器的主输出使能才会被禁用
  */
// 只有当所有通道(CCxE)和互补通道(CCxNE)都未使能时，才关闭主输出(MOE)
#define __HAL_TIM_MOE_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) \
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) \
      { \
        (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE); \
      } \
    } \
  } while(0)

/**
  * @brief  Disable the TIM main Output.
  * @brief  无条件禁用TIM主输出。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @retval None
  * @retval 无
  * @note The Main Output Enable of a timer instance is disabled unconditionally
  * @note 定时器实例的主输出使能无条件禁用
  */
// 直接清除MOE位，不检查通道状态
#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)

/** @brief  Enable the specified TIM interrupt.
  * @brief  使能指定的TIM中断。
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __HANDLE__ 指定TIM句柄。
  * @param  __INTERRUPT__ specifies the TIM interrupt source to enable.
  * @param  __INTERRUPT__ 指定要使能的TIM中断源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_IT_UPDATE: Update interrupt (更新中断)
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt (捕获/比较1中断)
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt (捕获/比较2中断)
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt (捕获/比较3中断)
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt (捕获/比较4中断)
  *            @arg TIM_IT_COM:   Commutation interrupt (换相中断)
  *            @arg TIM_IT_TRIGGER: Trigger interrupt (触发中断)
  *            @arg TIM_IT_BREAK: Break interrupt (刹车中断)
  * @retval None
  * @retval 无
  */
// 设置DIER寄存器的对应位，使能中断
#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  Disable the specified TIM interrupt.
  * @brief  禁用指定的TIM中断。
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __HANDLE__ 指定TIM句柄。
  * @param  __INTERRUPT__ specifies the TIM interrupt source to disable.
  * @param  __INTERRUPT__ 指定要禁用的TIM中断源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_IT_UPDATE: Update interrupt (更新中断)
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt (捕获/比较1中断)
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt (捕获/比较2中断)
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt (捕获/比较3中断)
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt (捕获/比较4中断)
  *            @arg TIM_IT_COM:   Commutation interrupt (换相中断)
  *            @arg TIM_IT_TRIGGER: Trigger interrupt (触发中断)
  *            @arg TIM_IT_BREAK: Break interrupt (刹车中断)
  * @retval None
  * @retval 无
  */
// 清除DIER寄存器的对应位，禁用中断
#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

/** @brief  Enable the specified DMA request.
  * @brief  使能指定的DMA请求。
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __HANDLE__ 指定TIM句柄。
  * @param  __DMA__ specifies the TIM DMA request to enable.
  * @param  __DMA__ 指定要使能的TIM DMA请求。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_DMA_UPDATE: Update DMA request (更新DMA请求)
  *            @arg TIM_DMA_CC1:   Capture/Compare 1 DMA request (捕获/比较1 DMA请求)
  *            @arg TIM_DMA_CC2:  Capture/Compare 2 DMA request (捕获/比较2 DMA请求)
  *            @arg TIM_DMA_CC3:  Capture/Compare 3 DMA request (捕获/比较3 DMA请求)
  *            @arg TIM_DMA_CC4:  Capture/Compare 4 DMA request (捕获/比较4 DMA请求)
  *            @arg TIM_DMA_COM:   Commutation DMA request (换相DMA请求)
  *            @arg TIM_DMA_TRIGGER: Trigger DMA request (触发DMA请求)
  * @retval None
  * @retval 无
  */
// 设置DIER寄存器的对应位，使能DMA请求
#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  Disable the specified DMA request.
  * @brief  禁用指定的DMA请求。
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __HANDLE__ 指定TIM句柄。
  * @param  __DMA__ specifies the TIM DMA request to disable.
  * @param  __DMA__ 指定要禁用的TIM DMA请求。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_DMA_UPDATE: Update DMA request (更新DMA请求)
  *            @arg TIM_DMA_CC1:   Capture/Compare 1 DMA request (捕获/比较1 DMA请求)
  *            @arg TIM_DMA_CC2:  Capture/Compare 2 DMA request (捕获/比较2 DMA请求)
  *            @arg TIM_DMA_CC3:  Capture/Compare 3 DMA request (捕获/比较3 DMA请求)
  *            @arg TIM_DMA_CC4:  Capture/Compare 4 DMA request (捕获/比较4 DMA请求)
  *            @arg TIM_DMA_COM:   Commutation DMA request (换相DMA请求)
  *            @arg TIM_DMA_TRIGGER: Trigger DMA request (触发DMA请求)
  * @retval None
  * @retval 无
  */
// 清除DIER寄存器的对应位，禁用DMA请求
#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))

/** @brief  Check whether the specified TIM interrupt flag is set or not.
  * @brief  检查指定的TIM中断标志位是否被置位。
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __HANDLE__ 指定TIM句柄。
  * @param  __FLAG__ specifies the TIM interrupt flag to check.
  * @param  __FLAG__ 指定要检查的TIM中断标志位。
  *        This parameter can be one of the following values:
  *        该参数可以是以下值之一：
  *            @arg TIM_FLAG_UPDATE: Update interrupt flag (更新中断标志)
  *            @arg TIM_FLAG_CC1: Capture/Compare 1 interrupt flag (捕获/比较1中断标志)
  *            @arg TIM_FLAG_CC2: Capture/Compare 2 interrupt flag (捕获/比较2中断标志)
  *            @arg TIM_FLAG_CC3: Capture/Compare 3 interrupt flag (捕获/比较3中断标志)
  *            @arg TIM_FLAG_CC4: Capture/Compare 4 interrupt flag (捕获/比较4中断标志)
  *            @arg TIM_FLAG_COM:  Commutation interrupt flag (换相中断标志)
  *            @arg TIM_FLAG_TRIGGER: Trigger interrupt flag (触发中断标志)
  *            @arg TIM_FLAG_BREAK: Break interrupt flag (刹车中断标志)
  *            @arg TIM_FLAG_CC1OF: Capture/Compare 1 overcapture flag (捕获/比较1过捕获标志)
  *            @arg TIM_FLAG_CC2OF: Capture/Compare 2 overcapture flag (捕获/比较2过捕获标志)
  *            @arg TIM_FLAG_CC3OF: Capture/Compare 3 overcapture flag (捕获/比较3过捕获标志)
  *            @arg TIM_FLAG_CC4OF: Capture/Compare 4 overcapture flag (捕获/比较4过捕获标志)
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  * @retval __FLAG__的新状态 (TRUE 或 FALSE)。
  */
// 读取SR寄存器，检查指定标志位是否置位
#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  Clear the specified TIM interrupt flag.
  * @brief  清除指定的TIM中断标志位。
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __HANDLE__ 指定TIM句柄。
  * @param  __FLAG__ specifies the TIM interrupt flag to clear.
  * @param  __FLAG__ 指定要清除的TIM中断标志位。
  *        This parameter can be one of the following values:
  *        该参数可以是以下值之一：
  *            @arg TIM_FLAG_UPDATE: Update interrupt flag (更新中断标志)
  *            @arg TIM_FLAG_CC1: Capture/Compare 1 interrupt flag (捕获/比较1中断标志)
  *            @arg TIM_FLAG_CC2: Capture/Compare 2 interrupt flag (捕获/比较2中断标志)
  *            @arg TIM_FLAG_CC3: Capture/Compare 3 interrupt flag (捕获/比较3中断标志)
  *            @arg TIM_FLAG_CC4: Capture/Compare 4 interrupt flag (捕获/比较4中断标志)
  *            @arg TIM_FLAG_COM:  Commutation interrupt flag (换相中断标志)
  *            @arg TIM_FLAG_TRIGGER: Trigger interrupt flag (触发中断标志)
  *            @arg TIM_FLAG_BREAK: Break interrupt flag (刹车中断标志)
  *            @arg TIM_FLAG_CC1OF: Capture/Compare 1 overcapture flag (捕获/比较1过捕获标志)
  *            @arg TIM_FLAG_CC2OF: Capture/Compare 2 overcapture flag (捕获/比较2过捕获标志)
  *            @arg TIM_FLAG_CC3OF: Capture/Compare 3 overcapture flag (捕获/比较3过捕获标志)
  *            @arg TIM_FLAG_CC4OF: Capture/Compare 4 overcapture flag (捕获/比较4过捕获标志)
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  * @retval __FLAG__的新状态 (TRUE 或 FALSE)。
  */
// 向SR寄存器写入取反后的值来清除标志位（这是STM32硬件特性，写0清除，写1无影响，这里通过写反码实现）
#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  Check whether the specified TIM interrupt source is enabled or not.
  * @brief  检查指定的TIM中断源是否已使能。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @param  __INTERRUPT__ specifies the TIM interrupt source to check.
  * @param  __INTERRUPT__ 指定要检查的TIM中断源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_IT_UPDATE: Update interrupt (更新中断)
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt (捕获/比较1中断)
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt (捕获/比较2中断)
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt (捕获/比较3中断)
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt (捕获/比较4中断)
  *            @arg TIM_IT_COM:   Commutation interrupt (换相中断)
  *            @arg TIM_IT_TRIGGER: Trigger interrupt (触发中断)
  *            @arg TIM_IT_BREAK: Break interrupt (刹车中断)
  * @retval The state of TIM_IT (SET or RESET).
  * @retval TIM_IT的状态 (SET 或 RESET)。
  */
// 检查DIER寄存器中的中断使能位是否置位
#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief Clear the TIM interrupt pending bits.
  * @brief  清除TIM中断挂起位。
  * @param  __HANDLE__ TIM handle
  * @param  __HANDLE__ TIM句柄
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  * @param  __INTERRUPT__ 指定要清除的中断挂起位。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg TIM_IT_UPDATE: Update interrupt (更新中断)
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt (捕获/比较1中断)
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt (捕获/比较2中断)
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt (捕获/比较3中断)
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt (捕获/比较4中断)
  *            @arg TIM_IT_COM:   Commutation interrupt (换相中断)
  *            @arg TIM_IT_TRIGGER: Trigger interrupt (触发中断)
  *            @arg TIM_IT_BREAK: Break interrupt (刹车中断)
  * @retval None
  * @retval 无
  */
// 此宏功能与__HAL_TIM_CLEAR_FLAG类似，用于清除中断标志
#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  Indicates whether or not the TIM Counter is used as downcounter.
  * @brief  指示TIM计数器是否正在向下计数。
  * @param  __HANDLE__ TIM handle.
  * @param  __HANDLE__ TIM句柄。
  * @retval False (Counter used as upcounter) or True (Counter used as downcounter)
  * @retval False (计数器用作向上计数) 或 True (计数器用作向下计数)
  * @note This macro is particularly useful to get the counting mode when the timer operates in Center-aligned mode
  *       or Encoder mode.
  * @note 当定时器工作在中心对齐模式或编码器模式时，此宏对于获取计数方向特别有用。
  */
// 读取CR1寄存器的DIR位，判断当前计数方向
#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))

/**
  * @brief  Set the TIM Prescaler on runtime.
  * @brief  在运行时设置TIM预分频器。
  * @param  __HANDLE__ TIM handle.
  * @param  __HANDLE__ TIM句柄。
  * @param  __PRESC__ specifies the Prescaler new value.
  * @param  __PRESC__ 指定预分频器的新值。
  * @retval None
  * @retval 无
  */
// 直接写入PSC寄存器，修改预分频系数
#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  Set the TIM Counter Register value on runtime.
  * @brief  在运行时设置TIM计数器寄存器值。
  * @param  __HANDLE__ TIM handle.
  * @param  __HANDLE__ TIM句柄。
  * @param  __COUNTER__ specifies the Counter register new value.
  * @param  __COUNTER__ 指定计数器寄存器的新值。
  * @retval None
  * @retval 无
  */
// 直接写入CNT寄存器，设置当前计数值
#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  Get the TIM Counter Register value on runtime.
  * @brief  在运行时获取TIM计数器寄存器值。
  * @param  __HANDLE__ TIM handle.
  * @param  __HANDLE__ TIM句柄。
  * @retval 16-bit or 32-bit value of the timer counter register (TIMx_CNT)
  * @retval 定时器计数器寄存器的16位或32位值 (TIMx_CNT)
  */
// 读取CNT寄存器，获取当前计数值
#define __HAL_TIM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)
