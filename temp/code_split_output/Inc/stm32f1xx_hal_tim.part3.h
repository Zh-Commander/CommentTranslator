/** @defgroup TIM_DMA_Burst_Length TIM DMA 突发传输长度
  * @{
  */
/* DMA突发传输长度配置宏定义 */
/* 这些宏定义用于配置TIMx_DCR寄存器中的DBL[4:0]位，决定DMA每次突发传输访问的寄存器数量 */
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

/** @defgroup DMA_Handle_index TIM DMA 句柄索引
  * @{
  */
/* DMA句柄索引定义，用于在定时器结构体中索引不同的DMA句柄 */
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
/* 通道使能状态定义 */
#define TIM_CCx_ENABLE                   0x00000001U                            /*!< 输入或输出通道已使能 */
#define TIM_CCx_DISABLE                  0x00000000U                            /*!< 输入或输出通道已禁能 */
#define TIM_CCxN_ENABLE                  0x00000004U                            /*!< 互补输出通道已使能 */
#define TIM_CCxN_DISABLE                 0x00000000U                            /*!< 互补输出通道已禁能 */
/**
  * @}
  */

/**
  * @}
  */
/* 导出常量结束 -------------------------------------------------*/

/* 导出宏定义 -----------------------------------------------------------*/
/** @defgroup TIM_Exported_Macros TIM 导出宏
  * @{
  */

/** @brief  复位 TIM 句柄状态。
  * @param  __HANDLE__ TIM 句柄。
  * @retval 无
  */
/* 如果定义了使用HAL库注册回调函数功能，则复位时需要将回调函数指针置空 */
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
/* 如果未使用回调函数注册功能，则仅复位状态标志位 */
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
  * @brief  使能 TIM 外设。
  * @param  __HANDLE__ TIM 句柄
  * @retval 无
  */
/* 设置CR1寄存器的CEN位（Counter Enable），启动计数器 */
#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))

/**
  * @brief  使能 TIM 主输出。
  * @param  __HANDLE__ TIM 句柄
  * @retval 无
  */
/* 设置BDTR寄存器的MOE位，只有在MOE=1时，OCx和OCxN输出才有效。常用于PWM输出 */
#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))

/**
  * @brief  禁能 TIM 外设。
  * @param  __HANDLE__ TIM 句柄
  * @retval 无
  */
/* 关闭计数器前需要检查通道状态，防止正在输出PWM时突然关闭导致电平异常 */
#define __HAL_TIM_DISABLE(__HANDLE__) \
  do { \
    /* 检查所有普通通道(CCxE)是否已关闭 */ \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) \
    { \
      /* 检查所有互补通道(CCxNE)是否已关闭 */ \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) \
      { \
        /* 如果通道都已关闭，则安全关闭计数器 */ \
        (__HANDLE__)->Instance->CR1 &= ~(TIM_CR1_CEN); \
      } \
    } \
  } while(0)

/**
  * @brief  禁能 TIM 主输出。
  * @param  __HANDLE__ TIM 句柄
  * @retval 无
  * @note 只有当所有的 CCx 和 CCxN 通道都被禁能时，定时器实例的主输出使能才会被禁能
  */
/* 关闭主输出前同样需要检查通道状态，确保安全 */
#define __HAL_TIM_MOE_DISABLE(__HANDLE__) \
  do { \
    /* 检查所有普通通道(CCxE)是否已关闭 */ \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) \
    { \
      /* 检查所有互补通道(CCxNE)是否已关闭 */ \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) \
      { \
        /* 如果通道都已关闭，则关闭主输出MOE位 */ \
        (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE); \
      } \
    } \
  } while(0)

/**
  * @brief  禁能 TIM 主输出。
  * @param  __HANDLE__ TIM 句柄
  * @retval 无
  * @note 无条件禁能定时器实例的主输出使能
  */
/* 无条件强制关闭主输出，不检查通道状态，用于紧急情况或强制复位 */
#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)

/** @brief  使能指定的 TIM 中断。
  * @param  __HANDLE__ 指定 TIM 句柄。
  * @param  __INTERRUPT__ 指定要使能的 TIM 中断源。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:   捕获/比较1中断
  *            @arg TIM_IT_CC2:  捕获/比较2中断
  *            @arg TIM_IT_CC3:  捕获/比较3中断
  *            @arg TIM_IT_CC4:  捕获/比较4中断
  *            @arg TIM_IT_COM:   换相中断
  *            @arg TIM_IT_TRIGGER: 触发中断
  *            @arg TIM_IT_BREAK: 刹车中断
  * @retval 无
  */
/* 设置DIER寄存器中的中断使能位 */
#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  禁能指定的 TIM 中断。
  * @param  __HANDLE__ 指定 TIM 句柄。
  * @param  __INTERRUPT__ 指定要禁能的 TIM 中断源。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:   捕获/比较1中断
  *            @arg TIM_IT_CC2:  捕获/比较2中断
  *            @arg TIM_IT_CC3:  捕获/比较3中断
  *            @arg TIM_IT_CC4:  捕获/比较4中断
  *            @arg TIM_IT_COM:   换相中断
  *            @arg TIM_IT_TRIGGER: 触发中断
  *            @arg TIM_IT_BREAK: 刹车中断
  * @retval 无
  */
/* 清除DIER寄存器中的中断使能位 */
#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

/** @brief  使能指定的 DMA 请求。
  * @param  __HANDLE__ 指定 TIM 句柄。
  * @param  __DMA__ 指定要使能的 TIM DMA 请求。
  *          该参数可以是以下值之一:
  *            @arg TIM_DMA_UPDATE: 更新 DMA 请求
  *            @arg TIM_DMA_CC1:   捕获/比较1 DMA 请求
  *            @arg TIM_DMA_CC2:  捕获/比较2 DMA 请求
  *            @arg TIM_DMA_CC3:  捕获/比较3 DMA 请求
  *            @arg TIM_DMA_CC4:  捕获/比较4 DMA 请求
  *            @arg TIM_DMA_COM:   换相 DMA 请求
  *            @arg TIM_DMA_TRIGGER: 触发 DMA 请求
  * @retval 无
  */
/* 设置DIER寄存器中的DMA使能位 */
#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  禁能指定的 DMA 请求。
  * @param  __HANDLE__ 指定 TIM 句柄。
  * @param  __DMA__ 指定要禁能的 TIM DMA 请求。
  *          该参数可以是以下值之一:
  *            @arg TIM_DMA_UPDATE: 更新 DMA 请求
  *            @arg TIM_DMA_CC1:   捕获/比较1 DMA 请求
  *            @arg TIM_DMA_CC2:  捕获/比较2 DMA 请求
  *            @arg TIM_DMA_CC3:  捕获/比较3 DMA 请求
  *            @arg TIM_DMA_CC4:  捕获/比较4 DMA 请求
  *            @arg TIM_DMA_COM:   换相 DMA 请求
  *            @arg TIM_DMA_TRIGGER: 触发 DMA 请求
  * @retval 无
  */
/* 清除DIER寄存器中的DMA使能位 */
#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))

/** @brief  检查指定的 TIM 中断标志位是否被置位。
  * @param  __HANDLE__ 指定 TIM 句柄。
  * @param  __FLAG__ 指定要检查的 TIM 中断标志位。
  *        该参数可以是以下值之一:
  *            @arg TIM_FLAG_UPDATE: 更新中断标志
  *            @arg TIM_FLAG_CC1: 捕获/比较1 中断标志
  *            @arg TIM_FLAG_CC2: 捕获/比较2 中断标志
  *            @arg TIM_FLAG_CC3: 捕获/比较3 中断标志
  *            @arg TIM_FLAG_CC4: 捕获/比较4 中断标志
  *            @arg TIM_FLAG_COM:  换相中断标志
  *            @arg TIM_FLAG_TRIGGER: 触发中断标志
  *            @arg TIM_FLAG_BREAK: 刹车中断标志
  *            @arg TIM_FLAG_CC1OF: 捕获/比较1 溢出标志
  *            @arg TIM_FLAG_CC2OF: 捕获/比较2 溢出标志
  *            @arg TIM_FLAG_CC3OF: 捕获/比较3 溢出标志
  *            @arg TIM_FLAG_CC4OF: 捕获/比较4 溢出标志
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
/* 读取SR寄存器，判断指定标志位是否置1 */
#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  清除指定的 TIM 中断标志位。
  * @param  __HANDLE__ 指定 TIM 句柄。
  * @param  __FLAG__ 指定要清除的 TIM 中断标志位。
  *        该参数可以是以下值之一:
  *            @arg TIM_FLAG_UPDATE: 更新中断标志
  *            @arg TIM_FLAG_CC1: 捕获/比较1 中断标志
  *            @arg TIM_FLAG_CC2: 捕获/比较2 中断标志
  *            @arg TIM_FLAG_CC3: 捕获/比较3 中断标志
  *            @arg TIM_FLAG_CC4: 捕获/比较4 中断标志
  *            @arg TIM_FLAG_COM:  换相中断标志
  *            @arg TIM_FLAG_TRIGGER: 触发中断标志
  *            @arg TIM_FLAG_BREAK: 刹车中断标志
  *            @arg TIM_FLAG_CC1OF: 捕获/比较1 溢出标志
  *            @arg TIM_FLAG_CC2OF: 捕获/比较2 溢出标志
  *            @arg TIM_FLAG_CC3OF: 捕获/比较3 溢出标志
  *            @arg TIM_FLAG_CC4OF: 捕获/比较4 溢出标志
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
/* 向SR寄存器写入取反后的标志位来清除标志（硬件特性：写0无作用，写1清除，这里通过写~FLAG实现写0清除） */
#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  检查指定的 TIM 中断源是否已使能。
  * @param  __HANDLE__ TIM 句柄
  * @param  __INTERRUPT__ 指定要检查的 TIM 中断源。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:   捕获/比较1中断
  *            @arg TIM_IT_CC2:  捕获/比较2中断
  *            @arg TIM_IT_CC3:  捕获/比较3中断
  *            @arg TIM_IT_CC4:  捕获/比较4中断
  *            @arg TIM_IT_COM:   换相中断
  *            @arg TIM_IT_TRIGGER: 触发中断
  *            @arg TIM_IT_BREAK: 刹车中断
  * @retval TIM_IT 的状态 (SET 或 RESET)。
  */
/* 检查DIER寄存器中的中断使能位是否置1 */
#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief 清除 TIM 中断挂起位。
  * @param  __HANDLE__ TIM 句柄
  * @param  __INTERRUPT__ 指定要清除的中断挂起位。
  *          该参数可以是以下值之一:
  *            @arg TIM_IT_UPDATE: 更新中断
  *            @arg TIM_IT_CC1:   捕获/比较1中断
  *            @arg TIM_IT_CC2:  捕获/比较2中断
  *            @arg TIM_IT_CC3:  捕获/比较3中断
  *            @arg TIM_IT_CC4:  捕获/比较4中断
  *            @arg TIM_IT_COM:   换相中断
  *            @arg TIM_IT_TRIGGER: 触发中断
  *            @arg TIM_IT_BREAK: 刹车中断
  * @retval 无
  */
/* 清除SR寄存器中的中断标志，与CLEAR_FLAG功能类似，常用于中断服务函数中 */
#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  指示 TIM 计数器是否用作递减计数器。
  * @param  __HANDLE__ TIM 句柄。
  * @retval False (计数器用作递增计数) 或 True (计数器用作递减计数)
  * @note 该宏在定时器工作在中心对齐模式或编码器模式时，对于获取计数方向特别有用。
  */
/* 读取CR1寄存器的DIR位，判断当前计数方向 */
#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))

/**
  * @brief  在运行时设置 TIM 预分频器。
  * @param  __HANDLE__ TIM 句柄。
  * @param  __PRESC__ 指定预分频器的新值。
  * @retval 无
  */
/* 直接写入PSC寄存器，修改预分频系数。注意：新值会在下一个更新事件生效 */
#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  在运行时设置 TIM 计数器寄存器值。
  * @param  __HANDLE__ TIM 句柄。
  * @param  __COUNTER__ 指定计数器寄存器的新值。
  * @retval 无
  */
/* 直接写入CNT寄存器，设置当前计数值 */
#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  在运行时获取 TIM 计数器寄存器值。
  * @param  __HANDLE__ TIM 句柄。
  * @retval 16位或32位的定时器计数器寄存器值 (TIMx_CNT)
  */
/* 读取CNT寄存器，获取当前计数值 */
#define __HAL_TIM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)
