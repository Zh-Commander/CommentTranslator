/** @brief 复位 UART 句柄的状态 gState 和 RxState
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
// 如果启用了回调注册功能，则复位状态并将回调函数指针置空
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \ // 复位全局状态
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \ // 复位接收状态
                                                       (__HANDLE__)->MspInitCallback = NULL;             \ // 清除 MspInit 回调指针
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \ // 清除 MspDeInit 回调指针
                                                     } while(0U)
#else
// 如果未启用回调注册功能，仅复位状态
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \ // 复位全局状态
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \ // 复位接收状态
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/** @brief  刷新 UART 数据寄存器 (DR)
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  */
// 通过读取数据寄存器来清除接收缓冲区（实际上是一个读取操作，常用于清除溢出错误等标志）
#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  检查指定的 UART 标志位是否被置位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __FLAG__ 指定需要检查的标志位。
  *        该参数可以是以下值之一:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (不适用于 UART4 和 UART5)
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志
  *            @arg UART_FLAG_TXE:  发送数据寄存器空标志
  *            @arg UART_FLAG_TC:   发送完成标志
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志
  *            @arg UART_FLAG_IDLE: 空闲线路检测标志
  *            @arg UART_FLAG_ORE:  溢出错误标志
  *            @arg UART_FLAG_NE:   噪声错误标志
  *            @arg UART_FLAG_FE:   帧错误标志
  *            @arg UART_FLAG_PE:   奇偶校验错误标志
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
// 读取状态寄存器 (SR) 并与指定标志位进行与运算，判断标志位是否置位
#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  清除指定的 UART 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __FLAG__ 指定需要清除的标志位。
  *          该参数可以是以下值的任意组合:
  *            @arg UART_FLAG_CTS:  CTS 变化标志 (不适用于 UART4 和 UART5)。
  *            @arg UART_FLAG_LBD:  LIN 断路检测标志。
  *            @arg UART_FLAG_TC:   发送完成标志。
  *            @arg UART_FLAG_RXNE: 接收数据寄存器非空标志。
  *
  * @note   PE (奇偶校验错误), FE (帧错误), NE (噪声错误), ORE (溢出错误)
  *          和 IDLE (空闲线路检测) 标志位通过软件序列清除:
  *          先读取 USART_SR 寄存器，然后读取 USART_DR 寄存器。
  * @note   RXNE 标志位也可以通过读取 USART_DR 寄存器来清除。
  * @note   TC 标志位也可以通过软件序列清除:
  *          先读取 USART_SR 寄存器，然后写入 USART_DR 寄存器。
  * @note   TXE 标志位只能通过写入 USART_DR 寄存器来清除。
  *
  * @retval 无
  */
// 通过向状态寄存器 (SR) 写入标志位的反码来清除标志位
#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  清除 UART PE (奇偶校验错误) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
// 清除 PE 标志位的序列：读取 SR 寄存器，然后读取 DR 寄存器
#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)     \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \ // 定义临时变量
    tmpreg = (__HANDLE__)->Instance->SR;        \ // 读取状态寄存器
    tmpreg = (__HANDLE__)->Instance->DR;        \ // 读取数据寄存器
    UNUSED(tmpreg);                             \ // 防止编译器警告变量未使用
  } while(0U)

/** @brief  清除 UART FE (帧错误) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
// FE 标志位的清除序列与 PE 标志位相同
#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除 UART NE (噪声错误) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
// NE 标志位的清除序列与 PE 标志位相同
#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除 UART ORE (溢出错误) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
// ORE 标志位的清除序列与 PE 标志位相同
#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  清除 UART IDLE (空闲线路) 挂起标志位。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @retval 无
  */
// IDLE 标志位的清除序列与 PE 标志位相同
#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  使能指定的 UART 中断。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __INTERRUPT__ 指定要使能的 UART 中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断 (帧错误, 噪声错误, 溢出错误)
  * @retval 无
  */
// 根据中断号的高28位判断中断属于 CR1, CR2 还是 CR3 寄存器，并在相应寄存器中使能中断
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 |= ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  禁止指定的 UART 中断。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __INTERRUPT__ 指定要禁止的 UART 中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS:  CTS 变化中断
  *            @arg UART_IT_LBD:  LIN 断路检测中断
  *            @arg UART_IT_TXE:  发送数据寄存器空中断
  *            @arg UART_IT_TC:   发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_PE:   奇偶校验错误中断
  *            @arg UART_IT_ERR:  错误中断 (帧错误, 噪声错误, 溢出错误)
  * @retval 无
  */
// 根据中断号的高28位判断中断属于 CR1, CR2 还是 CR3 寄存器，并在相应寄存器中禁止中断
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  检查指定的 UART 中断源是否已使能。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         UART 句柄选择 USARTx 或 UARTy 外设
  *         (USART,UART 的可用性及 x,y 的值取决于具体的设备型号)。
  * @param  __IT__ 指定要检查的 UART 中断源。
  *          该参数可以是以下值之一:
  *            @arg UART_IT_CTS: CTS 变化中断 (不适用于 UART4 和 UART5)
  *            @arg UART_IT_LBD: LIN 断路检测中断
  *            @arg UART_IT_TXE: 发送数据寄存器空中断
  *            @arg UART_IT_TC:  发送完成中断
  *            @arg UART_IT_RXNE: 接收数据寄存器非空中断
  *            @arg UART_IT_IDLE: 空闲线路检测中断
  *            @arg UART_IT_ERR: 错误中断
  * @retval __IT__ 的新状态 (TRUE 或 FALSE)。
  */
// 读取控制寄存器并检查对应的中断使能位是否置位
#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) (((((__IT__) >> 28U) == UART_CR1_REG_INDEX)? (__HANDLE__)->Instance->CR1:(((((uint32_t)(__IT__)) >> 28U) == UART_CR2_REG_INDEX)? \
                                                       (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (((uint32_t)(__IT__)) & UART_IT_MASK))

/** @brief  使能 CTS 流控制
  * @note   此宏允许为给定的 UART 实例使能 CTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 CTS 硬件流控制功能的激活状态，而无需
  *         对 USART 实例进行 Deinit/Init，因此调用此宏应满足以下条件：
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例被禁止时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应跟随一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
// 使能 CTS 流控：原子操作设置 CR3 寄存器的 CTSE 位，并更新句柄中的初始化配置
#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \ // 原子操作置位 CTSE
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \ // 同步更新句柄配置
  } while(0U)

/** @brief  禁止 CTS 流控制
  * @note   此宏允许为给定的 UART 实例禁止 CTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 CTS 硬件流控制功能的激活状态，而无需
  *         对 USART 实例进行 Deinit/Init，因此调用此宏应满足以下条件：
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例被禁止时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应跟随一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
// 禁止 CTS 流控：原子操作清除 CR3 寄存器的 CTSE 位，并更新句柄中的初始化配置
#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \ // 原子操作清零 CTSE
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \ // 同步更新句柄配置
  } while(0U)

/** @brief  使能 RTS 流控制
  *         此宏允许为给定的 UART 实例使能 RTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 RTS 硬件流控制功能的激活状态，而无需
  *         对 USART 实例进行 Deinit/Init，因此调用此宏应满足以下条件：
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例被禁止时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应跟随一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
// 使能 RTS 流控：原子操作设置 CR3 寄存器的 RTSE 位，并更新句柄中的初始化配置
#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \ // 原子操作置位 RTSE
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \ // 同步更新句柄配置
  } while(0U)

/** @brief  禁止 RTS 流控制
  *         此宏允许为给定的 UART 实例禁止 RTS 硬件流控制，
  *         而无需调用 HAL_UART_Init() 函数。
  *         由于涉及直接访问 UART 寄存器，用户应完全认可此宏的使用。
  * @note   由于此宏预期用于修改 RTS 硬件流控制功能的激活状态，而无需
  *         对 USART 实例进行 Deinit/Init，因此调用此宏应满足以下条件：
  *           - UART 实例应已经初始化 (通过调用 HAL_UART_Init() )
  *           - 此宏只能在相应的 UART 实例被禁止时调用 (即 __HAL_UART_DISABLE(__HANDLE__))
  *             并且随后应跟随一个使能宏 (即 __HAL_UART_ENABLE(__HANDLE__))。
  * @param  __HANDLE__ 指定 UART 句柄。
  *         句柄实例可以是任何支持硬件流控制功能的 USARTx。
  *         它用于选择 USART 外设 (USART 可用性及 x 值取决于设备)。
  * @retval 无
  */
// 禁止 RTS 流控：原子操作清除 CR3 寄存器的 RTSE 位，并更新句柄中的初始化配置
#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\ // 原子操作清零 RTSE
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \ // 同步更新句柄配置
  } while(0U)
#if defined(USART_CR3_ONEBIT)

/** @brief  宏: 使能 UART 的单比特采样方法
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
// 设置 CR3 寄存器的 ONEBIT 位，使能单比特采样（用于降低噪声干扰）
#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

/** @brief  宏: 禁止 UART 的单比特采样方法
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
// 清除 CR3 寄存器的 ONEBIT 位，禁止单比特采样（恢复为多数表决采样）
#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                       &= (uint16_t)~((uint16_t)USART_CR3_ONEBIT))
#endif /* UART_ONE_BIT_SAMPLE_Feature */

/** @brief  使能 UART
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
// 设置 CR1 寄存器的 UE 位 (UART Enable)，使能 UART 外设
#define __HAL_UART_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  禁止 UART
  * @param  __HANDLE__ 指定 UART 句柄。
  * @retval 无
  */
// 清除 CR1 寄存器的 UE 位，禁止 UART 外设
#define __HAL_UART_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)
/**
  * @}
  */

/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup UART_Exported_Functions
  * @{
  */

/** @addtogroup UART_Exported_Functions_Group1 初始化和反初始化函数
  * @{
  */

/* 初始化/反初始化函数  **********************************/
// 初始化 UART 模式
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
// 初始化半双工模式
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
// 初始化 LIN 模式
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
// 初始化多处理器模式
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
// 反初始化 UART
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
// MSP 初始化 (底层硬件初始化，如时钟、GPIO)
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
// MSP 反初始化 (底层硬件反初始化)
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

/* 回调注册/注销函数  ***********************************/
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
// 注册用户回调函数
HAL_StatusTypeDef HAL_UART_RegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID,
                                            pUART_CallbackTypeDef pCallback);
// 注销用户回调函数
HAL_StatusTypeDef HAL_UART_UnRegisterCallback(UART_HandleTypeDef *huart, HAL_UART_CallbackIDTypeDef CallbackID);

// 注册接收事件回调函数
HAL_StatusTypeDef HAL_UART_RegisterRxEventCallback(UART_HandleTypeDef *huart, pUART_RxEventCallbackTypeDef pCallback);
// 注销接收事件回调函数
HAL_StatusTypeDef HAL_UART_UnRegisterRxEventCallback(UART_HandleTypeDef *huart);
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group2 IO 操作函数
  * @{
  */

/* IO 操作函数 *******************************************************/
// 阻塞模式发送数据
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 阻塞模式接收数据
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 非阻塞模式（中断）发送数据
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
// 非阻塞模式（中断）接收数据
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
// 非阻塞模式（DMA）发送数据
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
// 非阻塞模式（DMA）接收数据
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
// 暂停 DMA 传输
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
// 恢复 DMA 传输
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
// 停止 DMA 传输
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

// 扩展功能：阻塞模式接收数据直到检测到空闲线路
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
// 扩展功能：非阻塞模式（中断）接收数据直到检测到空闲线路
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
// 扩展功能：非阻塞模式（DMA）接收数据直到检测到空闲线路
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

// 获取接收事件类型
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(UART_HandleTypeDef *huart);

/* 传输中止函数 */
// 阻塞模式下中止 UART 传输（发送和接收）
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
// 阻塞模式下中止 UART 发送
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
// 阻塞模式下中止 UART 接收
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
// 非阻塞模式下中止 UART 传输（发送和接收）
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
// 非阻塞模式下中止 UART 发送
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
// 非阻塞模式下中止 UART 接收
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

// UART 中断处理函数（需要放在中断服务函数中调用）
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
// 发送完成回调函数
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
// 发送过半回调函数
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
// 接收完成回调函数
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
// 接收过半回调函数
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
// 错误回调函数
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
// 中止完成回调函数
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
// 发送中止完成回调函数
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
// 接收中止完成回调函数
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

// 扩展功能：接收事件回调函数
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* 外设控制函数  **************************************************/
// 发送 LIN 断路信号
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
// 进入多处理器静默模式
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
// 退出多处理器静默模式
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
// 使能半双工模式的发送器
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
// 使能半双工模式的接收器
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* 外设状态函数  **************************************************/
// 获取 UART 状态
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
// 获取 UART 错误码
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
/** @brief UART 中断标志掩码
  *
  */
// 用于提取中断标志位的掩码
#define UART_IT_MASK                     0x0000FFFFU

// 控制寄存器 CR1 的索引
#define UART_CR1_REG_INDEX               1U
// 控制寄存器 CR2 的索引
#define UART_CR2_REG_INDEX               2U
// 控制寄存器 CR3 的索引
#define UART_CR3_REG_INDEX               3U
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART 私有宏
  * @{
  */
// 检查字长参数是否有效 (8位或9位)
#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))
// 检查 LIN 模式下的字长参数是否有效 (仅限8位)
#define IS_UART_LIN_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B))
// 检查停止位参数是否有效 (1位或2位)
#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_2))
// 检查校验位参数是否有效 (无校验, 偶校验, 奇校验)
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))
// 检查硬件流控制参数是否有效 (无, RTS, CTS, RTS_CTS)
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HWCONTROL_NONE) || \
                               ((CONTROL) == UART_HWCONTROL_RTS) || \
                               ((CONTROL) == UART_HWCONTROL_CTS) || \
                               ((CONTROL) == UART_HWCONTROL_RTS_CTS))
// 检查模式参数是否有效 (TX, RX 或 TX_RX)
#define IS_UART_MODE(MODE) ((((MODE) & 0x0000FFF3U) == 0x00U) && ((MODE) != 0x00U))
// 检查状态参数是否有效 (使能或禁止)
#define IS_UART_STATE(STATE) (((STATE) == UART_STATE_DISABLE) || \
                              ((STATE) == UART_STATE_ENABLE))
#if defined(USART_CR1_OVER8)
// 检查过采样参数是否有效 (16倍或8倍)
#define IS_UART_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16) || \
                                        ((SAMPLING) == UART_OVERSAMPLING_8))
#endif /* USART_CR1_OVER8 */
// 检查 LIN 模式下的过采样参数是否有效 (仅限16倍)
#define IS_UART_LIN_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16))
// 检查 LIN 断路检测长度参数是否有效 (10位或11位)
#define IS_UART_LIN_BREAK_DETECT_LENGTH(LENGTH) (((LENGTH) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                 ((LENGTH) == UART_LINBREAKDETECTLENGTH_11B))
// 检查唤醒方法参数是否有效 (空闲线路或地址标记)
#define IS_UART_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == UART_WAKEUPMETHOD_IDLELINE) || \
                                      ((WAKEUP) == UART_WAKEUPMETHOD_ADDRESSMARK))
// 检查波特率参数是否有效 (最大 4.5 Mbps)
#define IS_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 4500000U)
// 检查地址参数是否有效 (最大 0x0F, 即4位地址)
#define IS_UART_ADDRESS(ADDRESS) ((ADDRESS) <= 0x0FU)

// 计算波特率分频系数 (16倍过采样)
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
// 计算波特率分频系数的整数部分 (16倍过采样)
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
// 计算波特率分频系数的小数部分 (16倍过采样)
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
// 计算波特率寄存器 (BRR) 的值 (16倍过采样)
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

// 计算波特率分频系数 (8倍过采样)
#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
// 计算波特率分频系数的整数部分 (8倍过采样)
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
// 计算波特率分频系数的小数部分 (8倍过采样)
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
// 计算波特率寄存器 (BRR) 的值 (8倍过采样)
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

// 启动中断接收
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
// 启动 DMA 接收
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
