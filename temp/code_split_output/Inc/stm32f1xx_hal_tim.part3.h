/** @defgroup TIM_DMA_Burst_Length TIM DMA 突发传输长度
  * @{
  */
/* DMA传输长度配置，数值对应DCR寄存器的[12:8]位 (即左移8位) */
/* DBA (DMA Base Address) 定义了DMA传输的起始寄存器偏移 */
#define TIM_DMABURSTLENGTH_1TRANSFER       0x00000000U                          /*!< 传输长度为1个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_2TRANSFERS      0x00000100U                          /*!< 传输长度为2个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_3TRANSFERS      0x00000200U                          /*!< 传输长度为3个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_4TRANSFERS      0x00000300U                          /*!< 传输长度为4个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_5TRANSFERS      0x00000400U                          /*!< 传输长度为5个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_6TRANSFERS      0x00000500U                          /*!< 传输长度为6个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_7TRANSFERS      0x00000600U                          /*!< 传输长度为7个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_8TRANSFERS      0x00000700U                          /*!< 传输长度为8个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_9TRANSFERS      0x00000800U                          /*!< 传输长度为9个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_10TRANSFERS     0x00000900U                          /*!< 传输长度为10个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_11TRANSFERS     0x00000A00U                          /*!< 传输长度为11个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_12TRANSFERS     0x00000B00U                          /*!< 传输长度为12个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_13TRANSFERS     0x00000C00U                          /*!< 传输长度为13个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_14TRANSFERS     0x00000D00U                          /*!< 传输长度为14个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_15TRANSFERS     0x00000E00U                          /*!< 传输长度为15个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_16TRANSFERS     0x00000F00U                          /*!< 传输长度为16个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_17TRANSFERS     0x00001000U                          /*!< 传输长度为17个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
#define TIM_DMABURSTLENGTH_18TRANSFERS     0x00001100U                          /*!< 传输长度为18个寄存器，起始地址为 TIMx_CR1 + TIMx_DCR.DBA */
/**
  * @}
  */

/** @defgroup DMA_Handle_index TIM DMA 句柄索引
  * @{
  */
/* 用于标识定时器关联的DMA句柄在句柄数组中的索引位置 */
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

/** @defgroup Channel_CC_State TIM 捕获/比较通道状态
  * @{
  */
/* 定义通道的使能和禁用状态，用于配置CCER寄存器 */
#define TIM_CCx_ENABLE                   0x00000001U                            /*!< 输入或输出通道使能 */
#define TIM_CCx_DISABLE                  0x00000000U                            /*!< 输入或输出通道禁用 */
#define TIM_CCxN_ENABLE                  0x00000004U                            /*!< 互补输出通道使能 */
#define TIM_CCxN_DISABLE                 0x00000000U                            /*!< 互补输出通道禁用 */
/**
  * @}
  */

/**
  * @}
  */
/* 导出常量结束 -------------------------------------------------*/

/* 导出宏 -----------------------------------------------------------*/
/** @defgroup TIM_Exported_Macros TIM 导出宏
  * @{
  */

/** @brief  复位TIM句柄状态。
  * @param  __HANDLE__: TIM句柄。
  * @retval 无
  */
/* 如果启用了回调函数注册功能，则需要将所有的回调函数指针重置为NULL */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
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
/* 未启用回调注册功能时，仅复位基本状态和通道状态 */
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
  * @brief  使能TIM外设。
  * @param  __HANDLE__: TIM句柄
  * @retval 无
  */
/* 设置CR1寄存器的CEN位 (Counter Enable) 来启动计数器 */
#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))

/**
  * @brief  使能TIM主输出。
  * @param  __HANDLE__: TIM句柄
  * @retval 无
  */
/* 设置BDTR寄存器的MOE位 来使能主输出，这对于PWM模式是必须的 */
#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))

/**
  * @brief  禁用TIM外设。
  * @param  __HANDLE__: TIM句柄
  * @retval 无
  */
/* 禁用定时器计数器，只有在所有通道(CCxE)和互补通道(CCxNE)都未使能时才安全关闭 */
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
  * @brief  禁用TIM主输出。
  * @param  __HANDLE__: TIM句柄
  * @retval 无
  * @note 只有当所有的CCx和CCxN通道都被禁用时，定时器的主输出使能才会被禁用
  */
/* 禁用主输出(MOE位)，只有在所有通道(CCxE)和互补通道(CCxNE)都未使能时才关闭 */
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
  * @brief  禁用TIM主输出。
  * @param  __HANDLE__: TIM句柄
  * @retval 无
  * @note 无条件禁用定时器实例的主输出使能
  */
/* 无条件禁用主输出(MOE位)，不检查通道状态 */
#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)

/** @brief  使能指定的TIM中断。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __INTERRUPT__: 指定要使能的TIM中断源。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:    捕获/比较1中断
  *            @arg TIM_IT_CC2:    捕获/比较2中断
  *            @arg TIM_IT_CC3:    捕获/比较3中断
  *            @arg TIM_IT_CC4:    捕获/比较4中断
  *            @arg TIM_IT_COM:    换相中断
  *            @arg TIM_IT_TRIGGER:触发中断
  *            @arg TIM_IT_BREAK:  刹车中断
  * @retval 无
  */
/* 在DIER寄存器中设置相应的中断使能位 */
#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  禁用指定的TIM中断。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __INTERRUPT__: 指定要禁用的TIM中断源。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:    捕获/比较1中断
  *            @arg TIM_IT_CC2:    捕获/比较2中断
  *            @arg TIM_IT_CC3:    捕获/比较3中断
  *            @arg TIM_IT_CC4:    捕获/比较4中断
  *            @arg TIM_IT_COM:    换相中断
  *            @arg TIM_IT_TRIGGER:触发中断
  *            @arg TIM_IT_BREAK:  刹车中断
  * @retval 无
  */
/* 在DIER寄存器中清除相应的中断使能位 */
#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

/** @brief  使能指定的DMA请求。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __DMA__: 指定要使能的TIM DMA请求。
  *          该参数可以是以下值之一:
  *            @arg TIM_DMA_UPDATE: 更新DMA请求
  *            @arg TIM_DMA_CC1:    捕获/比较1 DMA请求
  *            @arg TIM_DMA_CC2:    捕获/比较2 DMA请求
  *            @arg TIM_DMA_CC3:    捕获/比较3 DMA请求
  *            @arg TIM_DMA_CC4:    捕获/比较4 DMA请求
  *            @arg TIM_DMA_COM:    换相DMA请求
  *            @arg TIM_DMA_TRIGGER:触发DMA请求
  * @retval 无
  */
/* 在DIER寄存器中设置相应的DMA请求使能位 */
#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  禁用指定的DMA请求。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __DMA__: 指定要禁用的TIM DMA请求。
  *          该参数可以是以下值之一:
  *            @arg TIM_DMA_UPDATE: 更新DMA请求
  *            @arg TIM_DMA_CC1:    捕获/比较1 DMA请求
  *            @arg TIM_DMA_CC2:    捕获/比较2 DMA请求
  *            @arg TIM_DMA_CC3:    捕获/比较3 DMA请求
  *            @arg TIM_DMA_CC4:    捕获/比较4 DMA请求
  *            @arg TIM_DMA_COM:    换相DMA请求
  *            @arg TIM_DMA_TRIGGER:触发DMA请求
  * @retval 无
  */
/* 在DIER寄存器中清除相应的DMA请求使能位 */
#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))

/** @brief  检查指定的TIM中断标志位是否被置位。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __FLAG__: 指定要检查的TIM中断标志。
  *        该参数可以是以下值之一:
  *            @arg TIM_FLAG_UPDATE: 更新中断标志
  *            @arg TIM_FLAG_CC1: 捕获/比较1 中断标志
  *            @arg TIM_FLAG_CC2: 捕获/比较2 中断标志
  *            @arg TIM_FLAG_CC3: 捕获/比较3 中断标志
  *            @arg TIM_FLAG_CC4: 捕获/比较4 中断标志
  *            @arg TIM_FLAG_COM:  换相中断标志
  *            @arg TIM_FLAG_TRIGGER: 触发中断标志
  *            @arg TIM_FLAG_BREAK: 刹车中断标志
  *            @arg TIM_FLAG_CC1OF: 捕获/比较1 捕获溢出标志
  *            @arg TIM_FLAG_CC2OF: 捕获/比较2 捕获溢出标志
  *            @arg TIM_FLAG_CC3OF: 捕获/比较3 捕获溢出标志
  *            @arg TIM_FLAG_CC4OF: 捕获/比较4 捕获溢出标志
  * @retval __FLAG__的新状态 (TRUE 或 FALSE)。
  */
/* 读取SR寄存器，检查指定标志位是否置位 */
#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  清除指定的TIM中断标志位。
  * @param  __HANDLE__: 指定TIM句柄。
  * @param  __FLAG__: 指定要清除的TIM中断标志。
  *        该参数可以是以下值之一:
  *            @arg TIM_FLAG_UPDATE: 更新中断标志
  *            @arg TIM_FLAG_CC1: 捕获/比较1 中断标志
  *            @arg TIM_FLAG_CC2: 捕获/比较2 中断标志
  *            @arg TIM_FLAG_CC3: 捕获/比较3 中断标志
  *            @arg TIM_FLAG_CC4: 捕获/比较4 中断标志
  *            @arg TIM_FLAG_COM:  换相中断标志
  *            @arg TIM_FLAG_TRIGGER: 触发中断标志
  *            @arg TIM_FLAG_BREAK: 刹车中断标志
  *            @arg TIM_FLAG_CC1OF: 捕获/比较1 捕获溢出标志
  *            @arg TIM_FLAG_CC2OF: 捕获/比较2 捕获溢出标志
  *            @arg TIM_FLAG_CC3OF: 捕获/比较3 捕获溢出标志
  *            @arg TIM_FLAG_CC4OF: 捕获/比较4 捕获溢出标志
  * @retval __FLAG__的新状态 (TRUE 或 FALSE)。
  */
/* 向SR寄存器写入取反后的标志位来清除标志 (写0不影响，写1清除，这里通过写反码实现) */
#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  检查指定的TIM中断源是否被使能。
  * @param  __HANDLE__: TIM句柄
  * @param  __INTERRUPT__: 指定要检查的TIM中断源。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:    捕获/比较1中断
  *            @arg TIM_IT_CC2:    捕获/比较2中断
  *            @arg TIM_IT_CC3:    捕获/比较3中断
  *            @arg TIM_IT_CC4:    捕获/比较4中断
  *            @arg TIM_IT_COM:    换相中断
  *            @arg TIM_IT_TRIGGER:触发中断
  *            @arg TIM_IT_BREAK:  刹车中断
  * @retval TIM_IT的状态 (SET 或 RESET)。
  */
/* 检查DIER寄存器中对应的中断使能位是否置位 */
#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief 清除TIM中断挂起位。
  * @param  __HANDLE__: TIM句柄
  * @param  __INTERRUPT__: 指定要清除的中断挂起位。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:    捕获/比较1中断
  *            @arg TIM_IT_CC2:    捕获/比较2中断
  *            @arg TIM_IT_CC3:    捕获/比较3中断
  *            @arg TIM_IT_CC4:    捕获/比较4中断
  *            @arg TIM_IT_COM:    换相中断
  *            @arg TIM_IT_TRIGGER:触发中断
  *            @arg TIM_IT_BREAK:  刹车中断
  * @retval 无
  */
/* 清除SR寄存器中的中断标志，与CLEAR_FLAG功能类似 */
#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  指示TIM计数器是否正在向下计数。
  * @param  __HANDLE__: TIM句柄。
  * @retval False (计数器向上计数) 或 True (计数器向下计数)
  * @note 该宏在定时器工作在中心对齐模式或编码器模式时，对于获取计数方向特别有用。
  */
/* 读取CR1寄存器的DIR位，判断当前计数方向 */
#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))

/**
  * @brief  运行时设置TIM预分频器。
  * @param  __HANDLE__: TIM句柄。
  * @param  __PRESC__: 指定预分频器的新值。
  * @retval 无
  */
/* 直接写入PSC寄存器，修改时钟分频系数 */
#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  运行时设置TIM计数器寄存器值。
  * @param  __HANDLE__: TIM句柄。
  * @param  __COUNTER__: 指定计数器寄存器的新值。
  * @retval 无
  */
/* 直接写入CNT寄存器，设置当前计数值 */
#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  运行时获取TIM计数器寄存器值。
  * @param  __HANDLE__: TIM句柄。
  * @retval 16位或32位的定时器计数器寄存器值 (TIMx_CNT)
  */
/* 读取CNT寄存器，获取当前计数值 */
#define __HAL_TIM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)
