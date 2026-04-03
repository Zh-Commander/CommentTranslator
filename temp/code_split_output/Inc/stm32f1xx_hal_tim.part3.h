/** @defgroup TIM_DMA_Burst_Length TIM DMA 突发传输长度
  * @{
  */
/* 传输长度为1次，即传输到1个寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_1TRANSFER       0x00000000U
/* 传输长度为2次，即传输到2个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_2TRANSFERS      0x00000100U
/* 传输长度为3次，即传输到3个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_3TRANSFERS      0x00000200U
/* 传输长度为4次，即传输到4个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_4TRANSFERS      0x00000300U
/* 传输长度为5次，即传输到5个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_5TRANSFERS      0x00000400U
/* 传输长度为6次，即传输到6个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_6TRANSFERS      0x00000500U
/* 传输长度为7次，即传输到7个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_7TRANSFERS      0x00000600U
/* 传输长度为8次，即传输到8个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_8TRANSFERS      0x00000700U
/* 传输长度为9次，即传输到9个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_9TRANSFERS      0x00000800U
/* 传输长度为10次，即传输到10个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_10TRANSFERS     0x00000900U
/* 传输长度为11次，即传输到11个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_11TRANSFERS     0x00000A00U
/* 传输长度为12次，即传输到12个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_12TRANSFERS     0x00000B00U
/* 传输长度为13次，即传输到13个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_13TRANSFERS     0x00000C00U
/* 传输长度为14次，即传输到14个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_14TRANSFERS     0x00000D00U
/* 传输长度为15次，即传输到15个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_15TRANSFERS     0x00000E00U
/* 传输长度为16次，即传输到16个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_16TRANSFERS     0x00000F00U
/* 传输长度为17次，即传输到17个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_17TRANSFERS     0x00001000U
/* 传输长度为18次，即传输到18个连续寄存器，起始地址由 TIMx_CR1 + TIMx_DCR.DBA 决定 */
#define TIM_DMABURSTLENGTH_18TRANSFERS     0x00001100U
/**
  * @}
  */

/** @defgroup DMA_Handle_index TIM DMA 句柄索引
  * @{
  */
/* 用于更新 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_UPDATE                ((uint16_t) 0x0000)
/* 用于捕获/比较通道1 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_CC1                   ((uint16_t) 0x0001)
/* 用于捕获/比较通道2 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_CC2                   ((uint16_t) 0x0002)
/* 用于捕获/比较通道3 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_CC3                   ((uint16_t) 0x0003)
/* 用于捕获/比较通道4 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_CC4                   ((uint16_t) 0x0004)
/* 用于换相 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_COMMUTATION           ((uint16_t) 0x0005)
/* 用于触发 DMA 请求的 DMA 句柄索引 */
#define TIM_DMA_ID_TRIGGER               ((uint16_t) 0x0006)
/**
  * @}
  */

/** @defgroup Channel_CC_State TIM 捕获/比较通道状态
  * @{
  */
/* 输入或输出通道已使能 */
#define TIM_CCx_ENABLE                   0x00000001U
/* 输入或输出通道已禁用 */
#define TIM_CCx_DISABLE                  0x00000000U
/* 互补输出通道已使能 */
#define TIM_CCxN_ENABLE                  0x00000004U
/* 互补输出通道已禁用 */
#define TIM_CCxN_DISABLE                 0x00000000U
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

/** @brief  复位 TIM 句柄状态。
  * @param  __HANDLE__: TIM 句柄。
  * @retval 无
  */
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;         /* 复位句柄状态 */ \
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道1状态 */ \
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道2状态 */ \
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道3状态 */ \
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道4状态 */ \
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道1状态 */ \
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道2状态 */ \
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道3状态 */ \
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道4状态 */ \
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;   /* 复位DMA突发状态 */ \
                                                      (__HANDLE__)->Base_MspInitCallback         = NULL;            /* 基础模式MspInit回调置空 */ \
                                                      (__HANDLE__)->Base_MspDeInitCallback       = NULL;            /* 基础模式MspDeInit回调置空 */ \
                                                      (__HANDLE__)->IC_MspInitCallback           = NULL;            /* 输入捕获MspInit回调置空 */ \
                                                      (__HANDLE__)->IC_MspDeInitCallback         = NULL;            /* 输入捕获MspDeInit回调置空 */ \
                                                      (__HANDLE__)->OC_MspInitCallback           = NULL;            /* 输出比较MspInit回调置空 */ \
                                                      (__HANDLE__)->OC_MspDeInitCallback         = NULL;            /* 输出比较MspDeInit回调置空 */ \
                                                      (__HANDLE__)->PWM_MspInitCallback          = NULL;            /* PWM模式MspInit回调置空 */ \
                                                      (__HANDLE__)->PWM_MspDeInitCallback        = NULL;            /* PWM模式MspDeInit回调置空 */ \
                                                      (__HANDLE__)->OnePulse_MspInitCallback     = NULL;            /* 单脉冲模式MspInit回调置空 */ \
                                                      (__HANDLE__)->OnePulse_MspDeInitCallback   = NULL;            /* 单脉冲模式MspDeInit回调置空 */ \
                                                      (__HANDLE__)->Encoder_MspInitCallback      = NULL;            /* 编码器模式MspInit回调置空 */ \
                                                      (__HANDLE__)->Encoder_MspDeInitCallback    = NULL;            /* 编码器模式MspDeInit回调置空 */ \
                                                      (__HANDLE__)->HallSensor_MspInitCallback   = NULL;            /* 霍尔传感器MspInit回调置空 */ \
                                                      (__HANDLE__)->HallSensor_MspDeInitCallback = NULL;            /* 霍尔传感器MspDeInit回调置空 */ \
                                                     } while(0)
#else
#define __HAL_TIM_RESET_HANDLE_STATE(__HANDLE__) do {                                                               \
                                                      (__HANDLE__)->State            = HAL_TIM_STATE_RESET;         /* 复位句柄状态 */ \
                                                      (__HANDLE__)->ChannelState[0]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道1状态 */ \
                                                      (__HANDLE__)->ChannelState[1]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道2状态 */ \
                                                      (__HANDLE__)->ChannelState[2]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道3状态 */ \
                                                      (__HANDLE__)->ChannelState[3]  = HAL_TIM_CHANNEL_STATE_RESET; /* 复位通道4状态 */ \
                                                      (__HANDLE__)->ChannelNState[0] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道1状态 */ \
                                                      (__HANDLE__)->ChannelNState[1] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道2状态 */ \
                                                      (__HANDLE__)->ChannelNState[2] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道3状态 */ \
                                                      (__HANDLE__)->ChannelNState[3] = HAL_TIM_CHANNEL_STATE_RESET; /* 复位互补通道4状态 */ \
                                                      (__HANDLE__)->DMABurstState    = HAL_DMA_BURST_STATE_RESET;   /* 复位DMA突发状态 */ \
                                                     } while(0)
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @brief  使能 TIM 外设（启动计数器）。
  * @param  __HANDLE__: TIM 句柄
  * @retval 无
  */
/* 设置控制寄存器1(TIMx_CR1)的CEN位(位0)为1，使能计数器 */
#define __HAL_TIM_ENABLE(__HANDLE__)                 ((__HANDLE__)->Instance->CR1|=(TIM_CR1_CEN))

/**
  * @brief  使能 TIM 主输出。
  * @param  __HANDLE__: TIM 句柄
  * @retval 无
  */
/* 设置断点和死区寄存器(TIMx_BDTR)的MOE位(位15)为1，使能主输出(对于高级定时器TIM1/TIM8等，必须设置此位才能输出PWM) */
#define __HAL_TIM_MOE_ENABLE(__HANDLE__)             ((__HANDLE__)->Instance->BDTR|=(TIM_BDTR_MOE))

/**
  * @brief  关闭 TIM 外设（停止计数器）。
  * @param  __HANDLE__: TIM 句柄
  * @retval 无
  */
#define __HAL_TIM_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) /* 检查所有通道(CC1..CC4)是否都禁用 */ \
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) /* 检查所有互补通道(CC1N..CC4N)是否都禁用 */ \
      { \
        (__HANDLE__)->Instance->CR1 &= ~(TIM_CR1_CEN); /* 如果通道和互补通道都未使能，则关闭计数器 */ \
      } \
    } \
  } while(0)

/**
  * @brief  关闭 TIM 主输出。
  * @param  __HANDLE__: TIM 句柄
  * @retval 无
  * @note 定时器实例的主输出使能仅在所有 CCx 和 CCxN 通道都禁用时才会被关闭
  */
#define __HAL_TIM_MOE_DISABLE(__HANDLE__) \
  do { \
    if (((__HANDLE__)->Instance->CCER & TIM_CCER_CCxE_MASK) == 0UL) /* 检查所有通道是否禁用 */ \
    { \
      if(((__HANDLE__)->Instance->CCER & TIM_CCER_CCxNE_MASK) == 0UL) /* 检查所有互补通道是否禁用 */ \
      { \
        (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE); /* 如果都禁用，则关闭主输出MOE位 */ \
      } \
    } \
  } while(0)

/**
  * @brief  无条件关闭 TIM 主输出。
  * @param  __HANDLE__: TIM 句柄
  * @retval 无
  * @note 定时器实例的主输出使能无条件关闭
  */
/* 直接清除MOE位，不检查通道状态 */
#define __HAL_TIM_MOE_DISABLE_UNCONDITIONALLY(__HANDLE__)  (__HANDLE__)->Instance->BDTR &= ~(TIM_BDTR_MOE)

/** @brief  使能指定的 TIM 中断。
  * @param  __HANDLE__: 指定 TIM 句柄。
  * @param  __INTERRUPT__: 指定要使能的 TIM 中断源。
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
/* 设置DMA/中断使能寄存器(TIMx_DIER)的对应中断位 */
#define __HAL_TIM_ENABLE_IT(__HANDLE__, __INTERRUPT__)    ((__HANDLE__)->Instance->DIER |= (__INTERRUPT__))

/** @brief  关闭指定的 TIM 中断。
  * @param  __HANDLE__: 指定 TIM 句柄。
  * @param  __INTERRUPT__: 指定要关闭的 TIM 中断源。
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
/* 清除DMA/中断使能寄存器(TIMx_DIER)的对应中断位 */
#define __HAL_TIM_DISABLE_IT(__HANDLE__, __INTERRUPT__)   ((__HANDLE__)->Instance->DIER &= ~(__INTERRUPT__))

/** @brief  使能指定的 DMA 请求。
  * @param  __HANDLE__: 指定 TIM 句柄。
  * @param  __DMA__: 指定要使能的 TIM DMA 请求。
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
/* 设置DMA/中断使能寄存器(TIMx_DIER)的对应DMA请求位 */
#define __HAL_TIM_ENABLE_DMA(__HANDLE__, __DMA__)         ((__HANDLE__)->Instance->DIER |= (__DMA__))

/** @brief  关闭指定的 DMA 请求。
  * @param  __HANDLE__: 指定 TIM 句柄。
  * @param  __DMA__: 指定要关闭的 TIM DMA 请求。
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
/* 清除DMA/中断使能寄存器(TIMx_DIER)的对应DMA请求位 */
#define __HAL_TIM_DISABLE_DMA(__HANDLE__, __DMA__)        ((__HANDLE__)->Instance->DIER &= ~(__DMA__))

/** @brief  检查指定的 TIM 中断标志位是否置位。
  * @param  __HANDLE__: 指定 TIM 句柄。
  * @param  __FLAG__: 指定要检查的 TIM 中断标志位。
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
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
/* 读取状态寄存器(TIMx_SR)并检查指定标志位 */
#define __HAL_TIM_GET_FLAG(__HANDLE__, __FLAG__)          (((__HANDLE__)->Instance->SR &(__FLAG__)) == (__FLAG__))

/** @brief  清除指定的 TIM 中断标志位。
  * @param  __HANDLE__: 指定 TIM 句柄。
  * @param  __FLAG__: 指定要清除的 TIM 中断标志位。
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
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
/* 向状态寄存器(TIMx_SR)写入反码来清除标志位 */
#define __HAL_TIM_CLEAR_FLAG(__HANDLE__, __FLAG__)        ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/**
  * @brief  检查指定的 TIM 中断源是否已使能。
  * @param  __HANDLE__: TIM 句柄
  * @param  __INTERRUPT__: 指定要检查的 TIM 中断源。
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
/* 检查DMA/中断使能寄存器(TIMx_DIER)中的中断使能位是否置位 */
#define __HAL_TIM_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->DIER & (__INTERRUPT__)) \
                                                             == (__INTERRUPT__)) ? SET : RESET)

/** @brief 清除 TIM 中断挂起位。
  * @param  __HANDLE__: TIM 句柄
  * @param  __INTERRUPT__: 指定要清除的中断挂起位。
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
/* 此宏功能与__HAL_TIM_CLEAR_FLAG相同，用于清除状态寄存器中的中断标志 */
#define __HAL_TIM_CLEAR_IT(__HANDLE__, __INTERRUPT__)      ((__HANDLE__)->Instance->SR = ~(__INTERRUPT__))

/**
  * @brief  指示 TIM 计数器是否正在向下计数。
  * @param  __HANDLE__: TIM 句柄。
  * @retval False (计数器向上计数) 或 True (计数器向下计数)
  * @note 此宏在定时器工作在中心对齐模式或编码器模式时，对于获取计数方向特别有用。
  */
/* 检查控制寄存器1(TIMx_CR1)中的DIR位(位4)。0:向上计数，1:向下计数 */
#define __HAL_TIM_IS_TIM_COUNTING_DOWN(__HANDLE__)    (((__HANDLE__)->Instance->CR1 &(TIM_CR1_DIR)) == (TIM_CR1_DIR))

/**
  * @brief  运行时设置 TIM 预分频值。
  * @param  __HANDLE__: TIM 句柄。
  * @param  __PRESC__: 指定预分频的新值。
  * @retval 无
  */
/* 直接写入预分频寄存器(TIMx_PSC) */
#define __HAL_TIM_SET_PRESCALER(__HANDLE__, __PRESC__)       ((__HANDLE__)->Instance->PSC = (__PRESC__))

/**
  * @brief  运行时设置 TIM 计数器寄存器值。
  * @param  __HANDLE__: TIM 句柄。
  * @param  __COUNTER__: 指定计数器寄存器的新值。
  * @retval 无
  */
/* 直接写入计数器寄存器(TIMx_CNT) */
#define __HAL_TIM_SET_COUNTER(__HANDLE__, __COUNTER__)  ((__HANDLE__)->Instance->CNT = (__COUNTER__))

/**
  * @brief  运行时获取 TIM 计数器寄存器值。
  * @param  __HANDLE__: TIM 句柄。
  * @retval 16位或32位的定时器计数器寄存器值 (TIMx_CNT)
  */
/* 读取计数器寄存器(TIMx_CNT)的当前值 */
#define __HAL_TIM_GET_COUNTER(__HANDLE__)  ((__HANDLE__)->Instance->CNT)
