/** @defgroup TIM_DMA_Burst_Length TIM DMA Burst Length
  * @{
  */
/* DMA突发传输长度配置：配置DMA一次突发传输访问的寄存器数量 */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输1个寄存器 */
#define TIM_DMABURSTLENGTH_1TRANSFER       0x00000000U                          /*!< The transfer is done to 1 register starting from TIMx_CR1 + TIMx_DCR.DBA   */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输2个寄存器 */
#define TIM_DMABURSTLENGTH_2TRANSFERS      0x00000100U                          /*!< The transfer is done to 2 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输3个寄存器 */
#define TIM_DMABURSTLENGTH_3TRANSFERS      0x00000200U                          /*!< The transfer is done to 3 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输4个寄存器 */
#define TIM_DMABURSTLENGTH_4TRANSFERS      0x00000300U                          /*!< The transfer is done to 4 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输5个寄存器 */
#define TIM_DMABURSTLENGTH_5TRANSFERS      0x00000400U                          /*!< The transfer is done to 5 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输6个寄存器 */
#define TIM_DMABURSTLENGTH_6TRANSFERS      0x00000500U                          /*!< The transfer is done to 6 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输7个寄存器 */
#define TIM_DMABURSTLENGTH_7TRANSFERS      0x00000600U                          /*!< The transfer is done to 7 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输8个寄存器 */
#define TIM_DMABURSTLENGTH_8TRANSFERS      0x00000700U                          /*!< The transfer is done to 8 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输9个寄存器 */
#define TIM_DMABURSTLENGTH_9TRANSFERS      0x00000800U                          /*!< The transfer is done to 9 registers starting from TIMx_CR1 + TIMx_DCR.DBA  */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输10个寄存器 */
#define TIM_DMABURSTLENGTH_10TRANSFERS     0x00000900U                          /*!< The transfer is done to 10 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输11个寄存器 */
#define TIM_DMABURSTLENGTH_11TRANSFERS     0x00000A00U                          /*!< The transfer is done to 11 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输12个寄存器 */
#define TIM_DMABURSTLENGTH_12TRANSFERS     0x00000B00U                          /*!< The transfer is done to 12 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输13个寄存器 */
#define TIM_DMABURSTLENGTH_13TRANSFERS     0x00000C00U                          /*!< The transfer is done to 13 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输14个寄存器 */
#define TIM_DMABURSTLENGTH_14TRANSFERS     0x00000D00U                          /*!< The transfer is done to 14 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输15个寄存器 */
#define TIM_DMABURSTLENGTH_15TRANSFERS     0x00000E00U                          /*!< The transfer is done to 15 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输16个寄存器 */
#define TIM_DMABURSTLENGTH_16TRANSFERS     0x00000F00U                          /*!< The transfer is done to 16 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输17个寄存器 */
#define TIM_DMABURSTLENGTH_17TRANSFERS     0x00001000U                          /*!< The transfer is done to 17 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/* 传输从 TIMx_CR1 + TIMx_DCR.DBA 指定的地址开始，共传输18个寄存器 */
#define TIM_DMABURSTLENGTH_18TRANSFERS     0x00001100U                          /*!< The transfer is done to 18 registers starting from TIMx_CR1 + TIMx_DCR.DBA */
/**
  * @}
  */

/** @defgroup DMA_Handle_index TIM DMA Handle Index
  * @{
  */
/* DMA句柄索引定义：用于区分不同的TIM DMA请求源 */
/* 用于更新事件的DMA请求索引 */
#define TIM_DMA_ID_UPDATE                ((uint16_t) 0x0000)       /*!< Index of the DMA handle used for Update DMA requests */
/* 用于捕获/比较通道1的DMA请求索引 */
#define TIM_DMA_ID_CC1                   ((uint16_t) 0x0001)       /*!< Index of the DMA handle used for Capture/Compare 1 DMA requests */
/* 用于捕获/比较通道2的DMA请求索引 */
#define TIM_DMA_ID_CC2                   ((uint16_t) 0x0002)       /*!< Index of the DMA handle used for Capture/Compare 2 DMA requests */
/* 用于捕获/比较通道3的DMA请求索引 */
#define TIM_DMA_ID_CC3                   ((uint16_t) 0x0003)       /*!< Index of the DMA handle used for Capture/Compare 3 DMA requests */
/* 用于捕获/比较通道4的DMA请求索引 */
#define TIM_DMA_ID_CC4                   ((uint16_t) 0x0004)       /*!< Index of the DMA handle used for Capture/Compare 4 DMA requests */
/* 用于换相事件的DMA请求索引 */
#define TIM_DMA_ID_COMMUTATION           ((uint16_t) 0x0005)       /*!< Index of the DMA handle used for Commutation DMA requests */
/* 用于触发事件的DMA请求索引 */
#define TIM_DMA_ID_TRIGGER               ((uint16_t) 0x0006)       /*!< Index of the DMA handle used for Trigger DMA requests */
/**
  * @}
  */

/** @defgroup Channel_CC_State TIM Capture/Compare Channel State
  * @{
  */
/* 捕获/比较通道状态定义 */
/* 输入或输出通道使能 */
#define TIM_CCx_ENABLE                   0x00000001U                            /*!< Input or output channel is enabled */
/* 输入或输出通道禁用 */
#define TIM_CCx_DISABLE                  0x00000000U                            /*!< Input or output channel is disabled */
/* 互补输出通道使能 */
#define TIM_CCxN_ENABLE                  0x00000004U                            /*!< Complementary output channel is enabled */
/* 互补输出通道禁用 */
#define TIM_CCxN_DISABLE                 0x00000000U                            /*!< Complementary output channel is enabled */
/**
  * @}
  */

/**
  * @}
  */
/* End of exported constants -------------------------------------------------*/

/* Exported macros -----------------------------------------------------------*/
/** @defgroup TIM_Exported_Macros TIM Exported Macros
  * @{
  */

/** @brief  Reset TIM handle state.
  * @param  __HANDLE__ TIM handle.
  * @retval None
  */
/* 复位TIM句柄状态：将TIM句柄中的所有状态变量和回调函数指针重置为初始值 */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \ /* 如果启用了回调注册功能，则同时将回调函数指针置空 */
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;         \ /* 复位TIM状态 */
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道1状态 */
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道2状态 */
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道3状态 */
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道4状态 */
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道1状态 */
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道2状态 */
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道3状态 */
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道4状态 */
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;   \ /* 复位DMA突发传输状态 */
                                                      (__HANDLE__)->Base_MspInitCallback         = NULL;            \ /* 基础模式MspInit回调置空 */
                                                      (__HANDLE__)->Base_MspDeInitCallback       = NULL;            \ /* 基础模式MspDeInit回调置空 */
                                                      (__HANDLE__)->IC_MspInitCallback           = NULL;            \ /* 输入捕获MspInit回调置空 */
                                                      (__HANDLE__)->IC_MspDeInitCallback         = NULL;            \ /* 输入捕获MspDeInit回调置空 */
                                                      (__HANDLE__)->OC_MspInitCallback           = NULL;            \ /* 输出比较MspInit回调置空 */
                                                      (__HANDLE__)->OC_MspDeInitCallback         = NULL;            \ /* 输出比较MspDeInit回调置空 */
                                                      (__HANDLE__)->PWM_MspInitCallback          = NULL;            \ /* PWM模式MspInit回调置空 */
                                                      (__HANDLE__)->PWM_MspDeInitCallback        = NULL;            \ /* PWM模式MspDeInit回调置空 */
                                                      (__HANDLE__)->OnePulse_MspInitCallback     = NULL;            \ /* 单脉冲模式MspInit回调置空 */
                                                      (__HANDLE__)->OnePulse_MspDeInitCallback   = NULL;            \ /* 单脉冲模式MspDeInit回调置空 */
                                                      (__HANDLE__)->Encoder_MspInitCallback      = NULL;            \ /* 编码器模式MspInit回调置空 */
                                                      (__HANDLE__)->Encoder_MspDeInitCallback    = NULL;            \ /* 编码器模式MspDeInit回调置空 */
                                                      (__HANDLE__)->HallSensor_MspInitCallback   = NULL;            \ /* 霍尔传感器MspInit回调置空 */
                                                      (__HANDLE__)->HallSensor_MspDeInitCallback = NULL;            \ /* 霍尔传感器MspDeInit回调置空 */
                                                     } while(0)
#else
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \ /* 仅复位状态变量，不处理回调函数 */
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;         \ /* 复位TIM状态 */
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道1状态 */
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道2状态 */
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道3状态 */
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位通道4状态 */
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道1状态 */
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道2状态 */
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道3状态 */
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET; \ /* 复位互补通道4状态 */
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;   \ /* 复位DMA突发传输状态 */
                                                     } while(0)
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @brief  Enable the TIM peripheral.
  * @param  __HANDLE__ TIM handle
  * @retval None
  */
/* 使能TIM外设：置位CR1寄存器的CEN位（计数器使能位），启动定时器计数 */
#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))

/**
  * @brief  Enable the TIM main Output.
  * @param  __HANDLE__ TIM handle
  * @retval None
  */
/* 使能TIM主输出：置位BDTR寄存器的MOE位（主输出使能），对于高级定时器输出PWM必须使能此位 */
#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))

/**
  * @brief  Disable the TIM peripheral.
  * @param  __HANDLE__ TIM handle
  * @retval None
  */
/* 禁用TIM外设：只有当所有通道(CCxE)和互补通道(CCxNE)都未使能时，才关闭计数器(CEN) */
#define __HAL_TIM_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) \ /* 检查是否所有输入/输出通道都禁用 */
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) \ /* 检查是否所有互补输出通道都禁用 */
      { \
        (__HANDLE__)->Instance->CR1 &= ~(TIM_CR1_CEN); \ /* 如果都禁用，则清除CEN位，停止计数 */
      } \
    } \
  } while(0)

/**
  * @brief  Disable the TIM main Output.
  * @param  __HANDLE__ TIM handle
  * @retval None
  * @note The Main Output Enable of a timer instance is disabled only if all the CCx and CCxN channels have been
  *       disabled
  */
/* 禁用TIM主输出：只有当所有通道(CCxE)和互补通道(CCxNE)都未使能时，才关闭主输出(MOE) */
#define __HAL_TIM_MOE_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) \ /* 检查是否所有输入/输出通道都禁用 */
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) \ /* 检查是否所有互补输出通道都禁用 */
      { \
        (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE); \ /* 如果都禁用，则清除MOE位，关闭主输出 */
      } \
    } \
  } while(0)

/**
  * @brief  Disable the TIM main Output.
  * @param  __HANDLE__ TIM handle
  * @retval None
  * @note The Main Output Enable of a timer instance is disabled unconditionally
  */
/* 无条件禁用TIM主输出：直接清除MOE位，不检查通道状态 */
#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)

/** @brief  Enable the specified TIM interrupt.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __INTERRUPT__ specifies the TIM interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval None
  */
/* 使能指定的TIM中断：通过设置DIER寄存器的对应位来开启中断 */
#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  Disable the specified TIM interrupt.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __INTERRUPT__ specifies the TIM interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval None
  */
/* 禁用指定的TIM中断：通过清除DIER寄存器的对应位来关闭中断 */
#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

/** @brief  Enable the specified DMA request.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __DMA__ specifies the TIM DMA request to enable.
  *          This parameter can be one of the following values:
  *            @arg TIM_DMA_UPDATE: Update DMA request
  *            @arg TIM_DMA_CC1:   Capture/Compare 1 DMA request
  *            @arg TIM_DMA_CC2:  Capture/Compare 2 DMA request
  *            @arg TIM_DMA_CC3:  Capture/Compare 3 DMA request
  *            @arg TIM_DMA_CC4:  Capture/Compare 4 DMA request
  *            @arg TIM_DMA_COM:   Commutation DMA request
  *            @arg TIM_DMA_TRIGGER: Trigger DMA request
  * @retval None
  */
/* 使能指定的DMA请求：通过设置DIER寄存器的对应位来开启DMA请求 */
#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  Disable the specified DMA request.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __DMA__ specifies the TIM DMA request to disable.
  *          This parameter can be one of the following values:
  *            @arg TIM_DMA_UPDATE: Update DMA request
  *            @arg TIM_DMA_CC1:   Capture/Compare 1 DMA request
  *            @arg TIM_DMA_CC2:  Capture/Compare 2 DMA request
  *            @arg TIM_DMA_CC3:  Capture/Compare 3 DMA request
  *            @arg TIM_DMA_CC4:  Capture/Compare 4 DMA request
  *            @arg TIM_DMA_COM:   Commutation DMA request
  *            @arg TIM_DMA_TRIGGER: Trigger DMA request
  * @retval None
  */
/* 禁用指定的DMA请求：通过清除DIER寄存器的对应位来关闭DMA请求 */
#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))

/** @brief  Check whether the specified TIM interrupt flag is set or not.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __FLAG__ specifies the TIM interrupt flag to check.
  *        This parameter can be one of the following values:
  *            @arg TIM_FLAG_UPDATE: Update interrupt flag
  *            @arg TIM_FLAG_CC1: Capture/Compare 1 interrupt flag
  *            @arg TIM_FLAG_CC2: Capture/Compare 2 interrupt flag
  *            @arg TIM_FLAG_CC3: Capture/Compare 3 interrupt flag
  *            @arg TIM_FLAG_CC4: Capture/Compare 4 interrupt flag
  *            @arg TIM_FLAG_COM:  Commutation interrupt flag
  *            @arg TIM_FLAG_TRIGGER: Trigger interrupt flag
  *            @arg TIM_FLAG_BREAK: Break interrupt flag
  *            @arg TIM_FLAG_CC1OF: Capture/Compare 1 overcapture flag
  *            @arg TIM_FLAG_CC2OF: Capture/Compare 2 overcapture flag
  *            @arg TIM_FLAG_CC3OF: Capture/Compare 3 overcapture flag
  *            @arg TIM_FLAG_CC4OF: Capture/Compare 4 overcapture flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
/* 检查指定的TIM中断标志位是否被置位：读取SR寄存器并判断对应标志位 */
#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  Clear the specified TIM interrupt flag.
  * @param  __HANDLE__ specifies the TIM Handle.
  * @param  __FLAG__ specifies the TIM interrupt flag to clear.
  *        This parameter can be one of the following values:
  *            @arg TIM_FLAG_UPDATE: Update interrupt flag
  *            @arg TIM_FLAG_CC1: Capture/Compare 1 interrupt flag
  *            @arg TIM_FLAG_CC2: Capture/Compare 2 interrupt flag
  *            @arg TIM_FLAG_CC3: Capture/Compare 3 interrupt flag
  *            @arg TIM_FLAG_CC4: Capture/Compare 4 interrupt flag
  *            @arg TIM_FLAG_COM:  Commutation interrupt flag
  *            @arg TIM_FLAG_TRIGGER: Trigger interrupt flag
  *            @arg TIM_FLAG_BREAK: Break interrupt flag
  *            @arg TIM_FLAG_CC1OF: Capture/Compare 1 overcapture flag
  *            @arg TIM_FLAG_CC2OF: Capture/Compare 2 overcapture flag
  *            @arg TIM_FLAG_CC3OF: Capture/Compare 3 overcapture flag
  *            @arg TIM_FLAG_CC4OF: Capture/Compare 4 overcapture flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
/* 清除指定的TIM中断标志位：向SR寄存器写入反码来清除标志位 */
#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  Check whether the specified TIM interrupt source is enabled or not.
  * @param  __HANDLE__ TIM handle
  * @param  __INTERRUPT__ specifies the TIM interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval The state of TIM_IT (SET or RESET).
  */
/* 检查指定的TIM中断源是否已使能：读取DIER寄存器并判断对应的中断使能位 */
#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief Clear the TIM interrupt pending bits.
  * @param  __HANDLE__ TIM handle
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *          This parameter can be one of the following values:
  *            @arg TIM_IT_UPDATE: Update interrupt
  *            @arg TIM_IT_CC1:   Capture/Compare 1 interrupt
  *            @arg TIM_IT_CC2:  Capture/Compare 2 interrupt
  *            @arg TIM_IT_CC3:  Capture/Compare 3 interrupt
  *            @arg TIM_IT_CC4:  Capture/Compare 4 interrupt
  *            @arg TIM_IT_COM:   Commutation interrupt
  *            @arg TIM_IT_TRIGGER: Trigger interrupt
  *            @arg TIM_IT_BREAK: Break interrupt
  * @retval None
  */
/* 清除TIM中断挂起位：向SR寄存器写入反码，功能与__HAL_TIM_CLEAR_FLAG类似 */
#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  Indicates whether or not the TIM Counter is used as downcounter.
  * @param  __HANDLE__ TIM handle.
  * @retval False (Counter used as upcounter) or True (Counter used as downcounter)
  * @note This macro is particularly useful to get the counting mode when the timer operates in Center-aligned mode
  *       or Encoder mode.
  */
/* 检查TIM计数器是否正在向下计数：读取CR1寄存器的DIR位，用于判断当前计数方向 */
#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))

/**
  * @brief  Set the TIM Prescaler on runtime.
  * @param  __HANDLE__ TIM handle.
  * @param  __PRESC__ specifies the Prescaler new value.
  * @retval None
  */
/* 运行时设置TIM预分频值：直接写入PSC寄存器，用于动态调整定时器时钟频率 */
#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  Set the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @param  __COUNTER__ specifies the Counter register new value.
  * @retval None
  */
/* 运行时设置TIM计数器值：直接写入CNT寄存器，用于设置当前计数值 */
#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  Get the TIM Counter Register value on runtime.
  * @param  __HANDLE__ TIM handle.
  * @retval 16-bit or 32-bit value of the timer counter register (TIMx_CNT)
  */
/* 运行时获取TIM计数器当前值：读取CNT寄存器，用于获取当前计数值 */
#define __HAL_TIM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)
