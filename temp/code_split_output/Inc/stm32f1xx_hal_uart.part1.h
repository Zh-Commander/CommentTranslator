/** @brief 复位UART句柄的状态(gState 和 RxState)
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @retval 无
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/* 如果启用了回调函数注册功能，则在复位时也需要清空回调指针 */
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \ /* 复位全局状态 */
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \ /* 复位接收状态 */
                                                       (__HANDLE__)->MspInitCallback = NULL;             \ /* 清空Msp初始化回调指针 */
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \ /* 清空Msp反初始化回调指针 */
                                                     } while(0U)
#else
/* 如果未启用回调函数注册功能，仅复位状态 */
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \ /* 复位全局状态 */
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \ /* 复位接收状态 */
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/** @brief  刷新UART数据寄存器(DR)
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @note   实际上这是一个读取操作，用于清除接收缓冲区中的数据
  */
#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  检查指定的UART标志位是否被置位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @param  __FLAG__ 指定需要检查的标志位。
  *        该参数可以是以下值之一:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (UART4和UART5不可用)
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志
  *            @arg UART_FLAG_TXE:  发送数据寄存器空标志
  *            @arg UART_FLAG_TC:   发送完成标志
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志
  *            @arg UART_FLAG_IDLE: 空闲线路检测标志
  *            @arg UART_FLAG_ORE:  溢出错误标志
  *            @arg UART_FLAG_NE:   噪声错误标志
  *            @arg UART_FLAG_FE:   帧错误标志
  *            @arg UART_FLAG_PE:   奇偶校验错误标志
  * @retval __FLAG__的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  清除指定的UART挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @param  __FLAG__ 指定需要清除的标志位。
  *          该参数可以是以下值的任意组合:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (UART4和UART5不可用)。
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志。
  *            @arg UART_FLAG_TC:   发送完成标志。
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志。
  *
  * @note   PE (奇偶错误), FE (帧错误), NE (噪声错误), ORE (溢出
  *          错误) 和 IDLE (空闲线路检测) 标志位通过软件
  *          序列清除: 先读取 USART_SR 寄存器，然后读取
  *          USART_DR 寄存器。
  * @note   RXNE 标志位也可以通过读取 USART_DR 寄存器来清除。
  * @note   TC 标志位也可以通过软件序列清除: 先读取
  *          USART_SR 寄存器，然后写入 USART_DR 寄存器。
  * @note   TXE 标志位只能通过写入 USART_DR 寄存器来清除。
  *
  * @retval 无
  */
#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  清除UART奇偶校验错误(PE)挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @note   通过先读SR寄存器再读DR寄存器的序列来清除PE标志
  * @retval 无
  */
#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)     \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \ /* 定义临时变量 */
    tmpreg = (__HANDLE__)->Instance->SR;        \ /* 读取状态寄存器SR */
    tmpreg = (__HANDLE__)->Instance->DR;        \ /* 读取数据寄存器DR */
    UNUSED(tmpreg);                             \ /* 防止编译器警告，变量tmpreg未使用 */
  } while(0U)

/** @brief  清除UART帧错误(FE)挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @note   清除方法与PE标志相同
  * @retval 无
  */
#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除UART噪声错误(NE)挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @note   清除方法与PE标志相同
  * @retval 无
  */
#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除UART溢出错误(ORE)挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @note   清除方法与PE标志相同
  * @retval 无
  */
#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除UART空闲线路(IDLE)挂起标志位。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @note   清除方法与PE标志相同
  * @retval 无
  */
#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  使能指定的UART中断。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @param  __INTERRUPT__ 指定要使能的UART中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断(帧错误, 噪声错误, 溢出错误)
  * @note   通过移位操作判断中断属于CR1, CR2还是CR3寄存器，并执行或运算置位
  * @retval 无
  */
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 |= ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  禁用指定的UART中断。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @param  __INTERRUPT__ 指定要禁用的UART中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断(帧错误, 噪声错误, 溢出错误)
  * @note   通过移位操作判断中断属于CR1, CR2还是CR3寄存器，并执行与运算清零
  * @retval 无
  */
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  检查指定的UART中断源是否已使能。
  * @param  __HANDLE__ 指定UART句柄。
  *         UART句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART的可用性及x,y值取决于具体的设备型号)。
  * @param  __IT__ 指定需要检查的UART中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS: CTS 变化中断 (UART4和UART5不可用)
  *            @arg UART_IT_LBD: LIN 断路检测中断
  *            @arg UART_IT_TXE: 发送数据寄存器空中断
  *            @arg UART_IT_TC:  发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_ERR: 错误中断
  * @retval __IT__的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) (((((__IT__) >> 28U) == UART_CR1_REG_INDEX)? (__HANDLE__)->Instance->CR1:(((((uint32_t)(__IT__)) >> 28U) == UART_CR2_REG_INDEX)? \
                                                       (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (((uint32_t)(__IT__)) & UART_IT_MASK))

/** @brief  使能CTS硬件流控制
  * @note   此宏允许使能指定UART实例的CTS硬件流控制，
  *         无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改CTS硬件流控制功能的激活状态，
  *         而无需USART实例的Deinit/Init，因此调用此宏应满足以下条件 :
  *           - UART实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择USART外设 (USART可用性及x值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \ /* 原子操作设置CR3寄存器的CTSE位 */
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \ /* 同步更新句柄中的初始化配置 */
  } while(0U)

/** @brief  禁用CTS硬件流控制
  * @note   此宏允许禁用指定UART实例的CTS硬件流控制，
  *         无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改CTS硬件流控制功能的激活状态，
  *         而无需USART实例的Deinit/Init，因此调用此宏应满足以下条件 :
  *           - UART实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择USART外设 (USART可用性及x值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \ /* 原子操作清除CR3寄存器的CTSE位 */
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \ /* 同步更新句柄中的初始化配置 */
  } while(0U)

/** @brief  使能RTS硬件流控制
  *         此宏允许使能指定UART实例的RTS硬件流控制，
  *         无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改RTS硬件流控制功能的激活状态，
  *         而无需USART实例的Deinit/Init，因此调用此宏应满足以下条件 :
  *           - UART实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择USART外设 (USART可用性及x值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \ /* 原子操作设置CR3寄存器的RTSE位 */
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \ /* 同步更新句柄中的初始化配置 */
  } while(0U)

/** @brief  禁用RTS硬件流控制
  *         此宏允许禁用指定UART实例的RTS硬件流控制，
  *         无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问UART寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改RTS硬件流控制功能的激活状态，
  *         而无需USART实例的Deinit/Init，因此调用此宏应满足以下条件 :
  *           - UART实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的UART实例禁用时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应紧跟一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定UART句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择USART外设 (USART可用性及x值取决于设备)。
  * @retval 无
  */
#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\ /* 原子操作清除CR3寄存器的RTSE位 */
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \ /* 同步更新句柄中的初始化配置 */
  } while(0U)
#if defined(USART_CR3_ONEBIT)

/** @brief  使能UART单比特采样方法的宏
  * @param  __HANDLE__ 指定UART句柄。
  * @note   单比特采样可以减少噪声对采样的影响，提高抗干扰能力
  * @retval 无
  */
#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

/** @brief  禁用UART单比特采样方法的宏
  * @param  __HANDLE__ 指定UART句柄。
  * @note   禁用后将恢复为默认的多比特采样（通常为3次采样）
  * @retval 无
  */
#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                       &= (uint16_t)~((uint16_t)USART_CR3_ONEBIT))
#endif /* UART_ONE_BIT_SAMPLE_Feature */

/** @brief  使能UART
  * @param  __HANDLE__ 指定UART句柄。
  * @note   设置CR1寄存器的UE位 (UART Enable)
  * @retval 无
  */
#define __HAL_UART_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  禁用UART
  * @param  __HANDLE__ 指定UART句柄。
  * @note   清除CR1寄存器的UE位 (UART Enable)
  * @retval 无
  */
#define __HAL_UART_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)
/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup UART_Exported_Functions
  * @{
  */

/** @addtogroup UART_Exported_Functions_Group1 初始化和反初始化函数
  * @{
  */

/* 初始化/反初始化函数  **********************************/
/* UART初始化函数 */
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
/* UART半双工模式初始化函数 */
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
/* UART LIN模式初始化函数 */
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
/* UART多处理器模式初始化函数 */
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
/* UART反初始化函数 */
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
/* UART MSP初始化函数 (底层硬件初始化，如GPIO时钟配置) */
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
/* UART MSP反初始化函数 (底层硬件反初始化) */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
/* 注册UART回调函数 */
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback);
/* 注销UART回调函数 */
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);

/* 注册UART接收事件回调函数 */
HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback);
/* 注销UART接收事件回调函数 */
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group2 IO操作函数
  * @{
  */

/* IO操作函数 *******************************************************/
/* 阻塞模式发送数据 */
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
/* 阻塞模式接收数据 */
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
/* 非阻塞模式(中断)发送数据 */
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
/* 非阻塞模式(中断)接收数据 */
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 非阻塞模式(DMA)发送数据 */
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
/* 非阻塞模式(DMA)接收数据 */
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 暂停DMA传输 */
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
/* 恢复DMA传输 */
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
/* 停止DMA传输 */
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

/* 扩展功能：阻塞模式接收数据直到检测到空闲线路 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
/* 扩展功能：非阻塞模式(中断)接收数据直到检测到空闲线路 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 扩展功能：非阻塞模式(DMA)接收数据直到检测到空闲线路 */
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/* 获取接收事件类型 */
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(UART_HandleTypeDef *huart);

/* 传输中止函数 */
/* 阻塞模式下中止正在进行的传输(发送和接收) */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
/* 阻塞模式下中止正在进行的发送传输 */
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
/* 阻塞模式下中止正在进行的接收传输 */
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
/* 非阻塞模式下中止正在进行的传输(发送和接收) */
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
/* 非阻塞模式下中止正在进行的发送传输 */
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
/* 非阻塞模式下中止正在进行的接收传输 */
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

/* UART中断处理函数，需在stm32f1xx_it.c中调用 */
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
/* 发送完成回调函数 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
/* 发送半完成回调函数 (DMA模式) */
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
/* 接收完成回调函数 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/* 接收半完成回调函数 (DMA模式) */
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
/* 错误回调函数 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
/* 中止完成回调函数 */
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
/* 发送中止完成回调函数 */
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
/* 接收中止完成回调函数 */
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

/* 扩展功能：接收事件回调函数 (用于ReceiveToIdle系列函数) */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* 外设控制函数  **************************************************/
/* LIN模式发送断路信号 */
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
/* 多处理器模式进入静默模式 */
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
/* 多处理器模式退出静默模式 */
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
/* 半双工模式使能发送器 */
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
/* 半双工模式使能接收器 */
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* 外设状态函数  **************************************************/
/* 获取UART当前状态 */
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
/* 获取UART错误码 */
uint32_t              HAL_UART_GetError(const UART_HandleTypeDef *huart);
/**
  * @}
  */

/**
  * @}
  */
/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup UART_Private_Constants UART 私有常量
  * @{
  */
/** @brief UART中断标志掩码
  *         用于提取中断标志位
  */
#define UART_IT_MASK                     0x0000FFFFU

/* 定义控制寄存器索引，用于中断操作中判断寄存器位置 */
#define UART_CR1_REG_INDEX               1U
#define UART_CR2_REG_INDEX               2U
#define UART_CR3_REG_INDEX               3U
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART 私有宏
  * @{
  */
/* 检查字长参数是否有效：8位或9位 */
#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))
/* 检查LIN模式字长参数是否有效：LIN模式仅支持8位 */
#define IS_UART_LIN_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B))
/* 检查停止位参数是否有效：1位或2位 */
#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_2))
/* 检查校验位参数是否有效：无校验、偶校验或奇校验 */
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))
/* 检查硬件流控制参数是否有效：无、RTS、CTS或RTS_CTS */
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HWCONTROL_NONE) || \
                               ((CONTROL) == UART_HWCONTROL_RTS) || \
                               ((CONTROL) == UART_HWCONTROL_CTS) || \
                               ((CONTROL) == UART_HWCONTROL_RTS_CTS))
/* 检查模式参数是否有效：TX/RX模式组合 */
#define IS_UART_MODE(MODE) ((((MODE) & 0x0000FFF3U) == 0x00U) && ((MODE) != 0x00U))
/* 检查状态参数是否有效：使能或禁用 */
#define IS_UART_STATE(STATE) (((STATE) == UART_STATE_DISABLE) || \
                              ((STATE) == UART_STATE_ENABLE))
#if defined(USART_CR1_OVER8)
/* 检查过采样参数是否有效：16倍或8倍过采样 */
#define IS_UART_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16) || \
                                        ((SAMPLING) == UART_OVERSAMPLING_8))
#endif /* USART_CR1_OVER8 */
/* 检查LIN模式过采样参数是否有效：LIN模式仅支持16倍过采样 */
#define IS_UART_LIN_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16))
/* 检查LIN断路检测长度参数是否有效：10位或11位 */
#define IS_UART_LIN_BREAK_DETECT_LENGTH(LENGTH) (((LENGTH) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                 ((LENGTH) == UART_LINBREAKDETECTLENGTH_11B))
/* 检查唤醒方法参数是否有效：空闲线路或地址标记 */
#define IS_UART_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == UART_WAKEUPMETHOD_IDLELINE) || \
                                      ((WAKEUP) == UART_WAKEUPMETHOD_ADDRESSMARK))
/* 检查波特率参数是否有效：最大4.5Mbps */
#define IS_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 4500000U)
/* 检查UART地址参数是否有效：最大地址0x0F (4位) */
#define IS_UART_ADDRESS(ADDRESS) ((ADDRESS) <= 0x0FU)

/* 以下宏用于计算波特率寄存器(BRR)的值 */
/* 计算16倍过采样下的分频系数 (DIV) */
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
/* 计算16倍过采样下的分频系数整数部分 (DIV_Mantissa) */
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
/* 计算16倍过采样下的分频系数小数部分 (DIV_Fraction) */
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR寄存器值 = 尾数 + 溢出 + 小数
            = (DIV_Mantissa << 4) + (DIV_Fraction & 0xF0) + (DIV_Fraction & 0x0F) */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

/* 计算8倍过采样下的分频系数 (DIV) */
#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
/* 计算8倍过采样下的分频系数整数部分 (DIV_Mantissa) */
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
/* 计算8倍过采样下的分频系数小数部分 (DIV_Fraction) */
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)
/* UART BRR寄存器值 = 尾数 + 溢出 + 小数
            = (DIV_Mantissa << 4) + ((DIV_Fraction & 0xF8) << 1) + (DIV_Fraction & 0x07U) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                         ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

/**
  * @}
  */

/* 私有函数 ---------------------------------------------------------*/
/** @defgroup UART_Private_Functions UART 私有函数
  * @{
  */

/* 启动中断模式接收 */
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
/* 启动DMA模式接收 */
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

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

#endif /* __STM32F1xx_HAL_UART_H */
