/* 定时器DMA基地址寄存器别名定义 */
#define TIM_DMABase_CR1                  TIM_DMABASE_CR1  /* 控制寄存器1的DMA基地址 */
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2  /* 控制寄存器2的DMA基地址 */
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR /* 从模式控制寄存器的DMA基地址 */
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER /* 中断使能寄存器的DMA基地址 */
#define TIM_DMABase_SR                   TIM_DMABASE_SR   /* 状态寄存器的DMA基地址 */
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR  /* 事件生成寄存器的DMA基地址 */
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1 /* 捕获/比较模式寄存器1的DMA基地址 */
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2 /* 捕获/比较模式寄存器2的DMA基地址 */
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER /* 捕获/比较使能寄存器的DMA基地址 */
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT  /* 计数器的DMA基地址 */
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC  /* 预分频器的DMA基地址 */
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR  /* 自动重装载寄存器的DMA基地址 */
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR  /* 重复计数寄存器的DMA基地址 */
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1 /* 捕获/比较寄存器1的DMA基地址 */
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2 /* 捕获/比较寄存器2的DMA基地址 */
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3 /* 捕获/比较寄存器3的DMA基地址 */
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4 /* 捕获/比较寄存器4的DMA基地址 */
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR /* 刹车和死区控制寄存器的DMA基地址 */
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR  /* DMA控制寄存器的DMA基地址 */
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR /* DMA连续传输地址寄存器的DMA基地址 */
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1  /* 选项寄存器1的DMA基地址 */
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3 /* 捕获/比较模式寄存器3的DMA基地址 */
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5 /* 捕获/比较寄存器5的DMA基地址 */
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6 /* 捕获/比较寄存器6的DMA基地址 */
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2  /* 选项寄存器2的DMA基地址 */
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3  /* 选项寄存器3的DMA基地址 */
#define TIM_DMABase_OR                   TIM_DMABASE_OR   /* 选项寄存器的DMA基地址 */

/* 定时器事件源别名定义 */
#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE   /* 更新事件 */
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1     /* 捕获/比较通道1事件 */
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2     /* 捕获/比较通道2事件 */
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3     /* 捕获/比较通道3事件 */
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4     /* 捕获/比较通道4事件 */
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM     /* COM事件 */
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER /* 触发事件 */
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK   /* 刹车事件 */
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2  /* 刹车2事件 */

/* 定时器DMA突发传输长度别名定义 */
#define TIM_DMABurstLength_1Transfer     TIM_DMABURSTLENGTH_1TRANSFER   /* 1次传输 */
#define TIM_DMABurstLength_2Transfers    TIM_DMABURSTLENGTH_2TRANSFERS  /* 2次传输 */
#define TIM_DMABurstLength_3Transfers    TIM_DMABURSTLENGTH_3TRANSFERS  /* 3次传输 */
#define TIM_DMABurstLength_4Transfers    TIM_DMABURSTLENGTH_4TRANSFERS  /* 4次传输 */
#define TIM_DMABurstLength_5Transfers    TIM_DMABURSTLENGTH_5TRANSFERS  /* 5次传输 */
#define TIM_DMABurstLength_6Transfers    TIM_DMABURSTLENGTH_6TRANSFERS  /* 6次传输 */
#define TIM_DMABurstLength_7Transfers    TIM_DMABURSTLENGTH_7TRANSFERS  /* 7次传输 */
#define TIM_DMABurstLength_8Transfers    TIM_DMABURSTLENGTH_8TRANSFERS  /* 8次传输 */
#define TIM_DMABurstLength_9Transfers    TIM_DMABURSTLENGTH_9TRANSFERS  /* 9次传输 */
#define TIM_DMABurstLength_10Transfers   TIM_DMABURSTLENGTH_10TRANSFERS /* 10次传输 */
#define TIM_DMABurstLength_11Transfers   TIM_DMABURSTLENGTH_11TRANSFERS /* 11次传输 */
#define TIM_DMABurstLength_12Transfers   TIM_DMABURSTLENGTH_12TRANSFERS /* 12次传输 */
#define TIM_DMABurstLength_13Transfers   TIM_DMABURSTLENGTH_13TRANSFERS /* 13次传输 */
#define TIM_DMABurstLength_14Transfers   TIM_DMABURSTLENGTH_14TRANSFERS /* 14次传输 */
#define TIM_DMABurstLength_15Transfers   TIM_DMABURSTLENGTH_15TRANSFERS /* 15次传输 */
#define TIM_DMABurstLength_16Transfers   TIM_DMABURSTLENGTH_16TRANSFERS /* 16次传输 */
#define TIM_DMABurstLength_17Transfers   TIM_DMABURSTLENGTH_17TRANSFERS /* 17次传输 */
#define TIM_DMABurstLength_18Transfers   TIM_DMABURSTLENGTH_18TRANSFERS /* 18次传输 */

/* STM32L0系列特定定义 */
#if defined(STM32L0)
#define TIM22_TI1_GPIO1   TIM22_TI1_GPIO  /* TIM22定时器通道1输入，映射到GPIO引脚1 */
#define TIM22_TI1_GPIO2   TIM22_TI1_GPIO  /* TIM22定时器通道1输入，映射到GPIO引脚2 */
#endif

/* STM32F3系列特定定义 */
#if defined(STM32F3)
/* 霍尔传感器接口实例检查宏别名 */
#define IS_TIM_HALL_INTERFACE_INSTANCE   IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE
#endif

/* STM32H7系列特定定义 - 定时器外部触发和输入捕获映射到比较器输出 */
#if defined(STM32H7)
#define TIM_TIM1_ETR_COMP1_OUT        TIM_TIM1_ETR_COMP1         /* TIM1 ETR 映射到 COMP1 输出 */
#define TIM_TIM1_ETR_COMP2_OUT        TIM_TIM1_ETR_COMP2         /* TIM1 ETR 映射到 COMP2 输出 */
#define TIM_TIM8_ETR_COMP1_OUT        TIM_TIM8_ETR_COMP1         /* TIM8 ETR 映射到 COMP1 输出 */
#define TIM_TIM8_ETR_COMP2_OUT        TIM_TIM8_ETR_COMP2         /* TIM8 ETR 映射到 COMP2 输出 */
#define TIM_TIM2_ETR_COMP1_OUT        TIM_TIM2_ETR_COMP1         /* TIM2 ETR 映射到 COMP1 输出 */
#define TIM_TIM2_ETR_COMP2_OUT        TIM_TIM2_ETR_COMP2         /* TIM2 ETR 映射到 COMP2 输出 */
#define TIM_TIM3_ETR_COMP1_OUT        TIM_TIM3_ETR_COMP1         /* TIM3 ETR 映射到 COMP1 输出 */
#define TIM_TIM1_TI1_COMP1_OUT        TIM_TIM1_TI1_COMP1         /* TIM1 TI1 映射到 COMP1 输出 */
#define TIM_TIM8_TI1_COMP2_OUT        TIM_TIM8_TI1_COMP2         /* TIM8 TI1 映射到 COMP2 输出 */
#define TIM_TIM2_TI4_COMP1_OUT        TIM_TIM2_TI4_COMP1         /* TIM2 TI4 映射到 COMP1 输出 */
#define TIM_TIM2_TI4_COMP2_OUT        TIM_TIM2_TI4_COMP2         /* TIM2 TI4 映射到 COMP2 输出 */
#define TIM_TIM2_TI4_COMP1COMP2_OUT   TIM_TIM2_TI4_COMP1_COMP2   /* TIM2 TI4 映射到 COMP1 和 COMP2 输出 */
#define TIM_TIM3_TI1_COMP1_OUT        TIM_TIM3_TI1_COMP1         /* TIM3 TI1 映射到 COMP1 输出 */
#define TIM_TIM3_TI1_COMP2_OUT        TIM_TIM3_TI1_COMP2         /* TIM3 TI1 映射到 COMP2 输出 */
#define TIM_TIM3_TI1_COMP1COMP2_OUT   TIM_TIM3_TI1_COMP1_COMP2   /* TIM3 TI1 映射到 COMP1 和 COMP2 输出 */
#endif

/* STM32U5系列特定定义 - 输出比较清除选择位定义 */
#if defined(STM32U5)
#define OCREF_CLEAR_SELECT_Pos       OCREF_CLEAR_SELECT_POS /* 输出比较清除选择位位置 */
#define OCREF_CLEAR_SELECT_Msk       OCREF_CLEAR_SELECT_MSK /* 输出比较清除选择位掩码 */
#endif
/**
  * @}
  */

/** @defgroup HAL_TSC_Aliased_Defines HAL TSC Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL触摸感应控制器(TSC)别名定义
  * @{
  */
#define TSC_SYNC_POL_FALL        TSC_SYNC_POLARITY_FALLING   /* 同步信号下降沿有效 */
#define TSC_SYNC_POL_RISE_HIGH   TSC_SYNC_POLARITY_RISING    /* 同步信号上升沿有效 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Defines HAL UART Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL通用异步收发器(UART)别名定义
  * @{
  */
/* 单比特采样使能/禁用别名 */
#define UART_ONEBIT_SAMPLING_DISABLED   UART_ONE_BIT_SAMPLE_DISABLE /* 禁用单比特采样 */
#define UART_ONEBIT_SAMPLING_ENABLED    UART_ONE_BIT_SAMPLE_ENABLE  /* 使能单比特采样 */
#define UART_ONE_BIT_SAMPLE_DISABLED    UART_ONE_BIT_SAMPLE_DISABLE /* 禁用单比特采样 */
#define UART_ONE_BIT_SAMPLE_ENABLED     UART_ONE_BIT_SAMPLE_ENABLE  /* 使能单比特采样 */

/* 单比特采样使能/禁用宏别名 */
#define __HAL_UART_ONEBIT_ENABLE        __HAL_UART_ONE_BIT_SAMPLE_ENABLE    /* 使能单比特采样宏 */
#define __HAL_UART_ONEBIT_DISABLE       __HAL_UART_ONE_BIT_SAMPLE_DISABLE   /* 禁用单比特采样宏 */

/* 16倍过采样分频寄存器计算相关别名 */
#define __DIV_SAMPLING16                UART_DIV_SAMPLING16         /* 16倍过采样分频值 */
#define __DIVMANT_SAMPLING16            UART_DIVMANT_SAMPLING16     /* 16倍过采样分频值整数部分 */
#define __DIVFRAQ_SAMPLING16            UART_DIVFRAQ_SAMPLING16     /* 16倍过采样分频值小数部分 */
#define __UART_BRR_SAMPLING16           UART_BRR_SAMPLING16         /* 16倍过采样波特率寄存器值 */

/* 8倍过采样分频寄存器计算相关别名 */
#define __DIV_SAMPLING8                 UART_DIV_SAMPLING8          /* 8倍过采样分频值 */
#define __DIVMANT_SAMPLING8             UART_DIVMANT_SAMPLING8      /* 8倍过采样分频值整数部分 */
#define __DIVFRAQ_SAMPLING8             UART_DIVFRAQ_SAMPLING8      /* 8倍过采样分频值小数部分 */
#define __UART_BRR_SAMPLING8            UART_BRR_SAMPLING8          /* 8倍过采样波特率寄存器值 */

/* 低功耗UART分频计算别名 */
#define __DIV_LPUART                    UART_DIV_LPUART             /* 低功耗UART分频值 */

/* UART唤醒方法别名 */
#define UART_WAKEUPMETHODE_IDLELINE     UART_WAKEUPMETHOD_IDLELINE     /* 空闲线唤醒 */
#define UART_WAKEUPMETHODE_ADDRESSMARK  UART_WAKEUPMETHOD_ADDRESSMARK  /* 地址标记唤醒 */

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Defines HAL USART Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL通用同步异步收发器(USART)别名定义
  * @{
  */

/* USART时钟控制别名 */
#define USART_CLOCK_DISABLED            USART_CLOCK_DISABLE  /* 禁用USART时钟 */
#define USART_CLOCK_ENABLED             USART_CLOCK_ENABLE   /* 使能USART时钟 */

/* USART NACK功能别名 */
#define USARTNACK_ENABLED               USART_NACK_ENABLE   /* 使能NACK（非应答） */
#define USARTNACK_DISABLED              USART_NACK_DISABLE  /* 禁用NACK（非应答） */
/**
  * @}
  */

/** @defgroup HAL_WWDG_Aliased_Defines HAL WWDG Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL窗口看门狗(WWDG)别名定义
  * @{
  */
#define CFR_BASE                    WWDG_CFR_BASE  /* 配置寄存器(CFR)基地址 */
/**
  * @}
  */

/** @defgroup HAL_CAN_Aliased_Defines HAL CAN Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL控制器局域网(CAN)别名定义
  * @{
  */
/* CAN过滤器FIFO分配别名 */
#define CAN_FilterFIFO0             CAN_FILTER_FIFO0  /* 过滤器映射到FIFO0 */
#define CAN_FilterFIFO1             CAN_FILTER_FIFO1  /* 过滤器映射到FIFO1 */

/* CAN发送邮箱请求完成中断别名 */
#define CAN_IT_RQCP0                CAN_IT_TME  /* 发送邮箱0请求完成中断 */
#define CAN_IT_RQCP1                CAN_IT_TME  /* 发送邮箱1请求完成中断 */
#define CAN_IT_RQCP2                CAN_IT_TME  /* 发送邮箱2请求完成中断 */

/* CAN超时值别名 */
#define INAK_TIMEOUT                CAN_TIMEOUT_VALUE  /* 初始化应答超时值 */
#define SLAK_TIMEOUT                CAN_TIMEOUT_VALUE  /* 睡眠应答超时值 */

/* CAN发送状态别名 */
#define CAN_TXSTATUS_FAILED         ((uint8_t)0x00U)  /* 发送失败 */
#define CAN_TXSTATUS_OK             ((uint8_t)0x01U)  /* 发送成功 */
#define CAN_TXSTATUS_PENDING        ((uint8_t)0x02U)  /* 发送挂起 */

/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Defines HAL ETH Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL以太网(ETH)别名定义
  * @{
  */

/* 以太网帧相关常量别名 */
#define VLAN_TAG                ETH_VLAN_TAG                 /* VLAN标签长度 */
#define MIN_ETH_PAYLOAD         ETH_MIN_ETH_PAYLOAD          /* 最小以太网载荷长度 */
#define MAX_ETH_PAYLOAD         ETH_MAX_ETH_PAYLOAD          /* 最大以太网载荷长度 */
#define JUMBO_FRAME_PAYLOAD     ETH_JUMBO_FRAME_PAYLOAD      /* 巨帧载荷长度 */

/* 以太网寄存器掩码别名 */
#define MACMIIAR_CR_MASK        ETH_MACMIIAR_CR_MASK         /* MII地址寄存器时钟范围掩码 */
#define MACCR_CLEAR_MASK        ETH_MACCR_CLEAR_MASK         /* MAC控制寄存器清除掩码 */
#define MACFCR_CLEAR_MASK       ETH_MACFCR_CLEAR_MASK        /* MAC流控制寄存器清除掩码 */
#define DMAOMR_CLEAR_MASK       ETH_DMAOMR_CLEAR_MASK        /* DMA操作模式寄存器清除掩码 */

/* 以太网MMC（MAC管理计数器）寄存器偏移地址定义 */
#define ETH_MMCCR              0x00000100U  /* MMC控制寄存器偏移地址 */
#define ETH_MMCRIR             0x00000104U  /* MMC接收中断寄存器偏移地址 */
#define ETH_MMCTIR             0x00000108U  /* MMC发送中断寄存器偏移地址 */
#define ETH_MMCRIMR            0x0000010CU  /* MMC接收中断掩码寄存器偏移地址 */
#define ETH_MMCTIMR            0x00000110U  /* MMC发送中断掩码寄存器偏移地址 */
#define ETH_MMCTGFSCCR         0x0000014CU  /* MMC发送良好单冲突帧计数器寄存器偏移地址 */
#define ETH_MMCTGFMSCCR        0x00000150U  /* MMC发送良好多冲突帧计数器寄存器偏移地址 */
#define ETH_MMCTGFCR           0x00000168U  /* MMC发送良好帧计数器寄存器偏移地址 */
#define ETH_MMCRFCECR          0x00000194U  /* MMC接收CRC错误帧计数器寄存器偏移地址 */
#define ETH_MMCRFAECR          0x00000198U  /* MMC接收对齐错误帧计数器寄存器偏移地址 */
#define ETH_MMCRGUFCR          0x000001C4U  /* MMC接收良好单播帧计数器寄存器偏移地址 */

/**
  * @}
  */