/** @brief Reset UART handle gstate & RxState
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @retval None
  */
// 复位UART句柄状态
#if (USE_HAL_UART_REGISTER_CALLBACKS == 1)
// 如果定义了使用HAL库注册回调功能
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \ // 将全局状态复位
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \ // 将接收状态复位
                                                       (__HANDLE__)->MspInitCallback = NULL;             \ // 清空中断回调指针
                                                       (__HANDLE__)->MspDeInitCallback = NULL;           \ // 清空反初始化回调指针
                                                     } while(0U)
#else
// 如果未定义使用HAL库注册回调功能
#define __HAL_UART_RESET_HANDLE_STATE(__HANDLE__)  do{                                                   \
                                                       (__HANDLE__)->gState = HAL_UART_STATE_RESET;      \ // 将全局状态复位
                                                       (__HANDLE__)->RxState = HAL_UART_STATE_RESET;     \ // 将接收状态复位
                                                     } while(0U)
#endif /*USE_HAL_UART_REGISTER_CALLBACKS */

/** @brief  Flushes the UART DR register
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  */
// 刷新UART数据寄存器（读取数据寄存器以清除某些标志位或丢弃数据）
#define __HAL_UART_FLUSH_DRREGISTER(__HANDLE__) ((__HANDLE__)->Instance->DR)

/** @brief  Checks whether the specified UART flag is set or not.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *        This parameter can be one of the following values:
  *            @arg UART_FLAG_CTS:  CTS Change flag (not available for UART4 and UART5)
  *            @arg UART_FLAG_LBD:  LIN Break detection flag
  *            @arg UART_FLAG_TXE:  Transmit data register empty flag
  *            @arg UART_FLAG_TC:   Transmission Complete flag
  *            @arg UART_FLAG_RXNE: Receive data register not empty flag
  *            @arg UART_FLAG_IDLE: Idle Line detection flag
  *            @arg UART_FLAG_ORE:  Overrun Error flag
  *            @arg UART_FLAG_NE:   Noise Error flag
  *            @arg UART_FLAG_FE:   Framing Error flag
  *            @arg UART_FLAG_PE:   Parity Error flag
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
// 获取指定的UART标志位状态
// 逻辑：读取状态寄存器(SR)并与指定的标志位进行与运算，判断是否相等
#define __HAL_UART_GET_FLAG(__HANDLE__, __FLAG__) (((__HANDLE__)->Instance->SR & (__FLAG__)) == (__FLAG__))

/** @brief  Clears the specified UART pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be any combination of the following values:
  *            @arg UART_FLAG_CTS:  CTS Change flag (not available for UART4 and UART5).
  *            @arg UART_FLAG_LBD:  LIN Break detection flag.
  *            @arg UART_FLAG_TC:   Transmission Complete flag.
  *            @arg UART_FLAG_RXNE: Receive data register not empty flag.
  *
  * @note   PE (Parity error), FE (Framing error), NE (Noise error), ORE (Overrun
  *          error) and IDLE (Idle line detected) flags are cleared by software
  *          sequence: a read operation to USART_SR register followed by a read
  *          operation to USART_DR register.
  * @note   RXNE flag can be also cleared by a read to the USART_DR register.
  * @note   TC flag can be also cleared by software sequence: a read operation to
  *          USART_SR register followed by a write operation to USART_DR register.
  * @note   TXE flag is cleared only by a write to the USART_DR register.
  *
  * @retval None
  */
// 清除指定的UART挂起标志位
// 逻辑：向状态寄存器(SR)写入标志位的反码（硬件特性：写入0清除，写入1无影响，此处通过取反实现）
#define __HAL_UART_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR = ~(__FLAG__))

/** @brief  Clears the UART PE pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @retval None
  */
// 清除奇偶校验错误标志(PE)
// 序列：读状态寄存器(SR) -> 读数据寄存器(DR)
#define __HAL_UART_CLEAR_PEFLAG(__HANDLE__)     \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \ // 定义临时变量
    tmpreg = (__HANDLE__)->Instance->SR;        \ // 读取SR寄存器
    tmpreg = (__HANDLE__)->Instance->DR;        \ // 读取DR寄存器
    UNUSED(tmpreg);                             \ // 防止编译器警告变量未使用
  } while(0U)

/** @brief  Clears the UART FE pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @retval None
  */
// 清除帧错误标志(FE)，清除序列与PE标志相同
#define __HAL_UART_CLEAR_FEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the UART NE pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @retval None
  */
// 清除噪声错误标志(NE)，清除序列与PE标志相同
#define __HAL_UART_CLEAR_NEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the UART ORE pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @retval None
  */
// 清除溢出错误标志(ORE)，清除序列与PE标志相同
#define __HAL_UART_CLEAR_OREFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Clears the UART IDLE pending flag.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @retval None
  */
// 清除空闲线路检测标志(IDLE)，清除序列与PE标志相同
#define __HAL_UART_CLEAR_IDLEFLAG(__HANDLE__) __HAL_UART_CLEAR_PEFLAG(__HANDLE__)

/** @brief  Enable the specified UART interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @param  __INTERRUPT__ specifies the UART interrupt source to enable.
  *          This parameter can be one of the following values:
  *            @arg UART_IT_CTS:  CTS change interrupt
  *            @arg UART_IT_LBD:  LIN Break detection interrupt
  *            @arg UART_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg UART_IT_TC:   Transmission complete interrupt
  *            @arg UART_IT_RXNE: Receive Data register not empty interrupt
  *            @arg UART_IT_IDLE: Idle line detection interrupt
  *            @arg UART_IT_PE:   Parity Error interrupt
  *            @arg UART_IT_ERR:  Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
// 使能指定的UART中断
// 逻辑：根据中断源的高4位（用于区分CR1/CR2/CR3寄存器），将中断掩码写入对应的控制寄存器
#define __HAL_UART_ENABLE_IT(__HANDLE__, __INTERRUPT__)   ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 |= ((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 |= ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  Disable the specified UART interrupt.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @param  __INTERRUPT__ specifies the UART interrupt source to disable.
  *          This parameter can be one of the following values:
  *            @arg UART_IT_CTS:  CTS change interrupt
  *            @arg UART_IT_LBD:  LIN Break detection interrupt
  *            @arg UART_IT_TXE:  Transmit Data Register empty interrupt
  *            @arg UART_IT_TC:   Transmission complete interrupt
  *            @arg UART_IT_RXNE: Receive Data register not empty interrupt
  *            @arg UART_IT_IDLE: Idle line detection interrupt
  *            @arg UART_IT_PE:   Parity Error interrupt
  *            @arg UART_IT_ERR:  Error interrupt(Frame error, noise error, overrun error)
  * @retval None
  */
// 禁用指定的UART中断
// 逻辑：根据中断源的高4位，在对应的控制寄存器中清除中断掩码位
#define __HAL_UART_DISABLE_IT(__HANDLE__, __INTERRUPT__)  ((((__INTERRUPT__) >> 28U) == UART_CR1_REG_INDEX)? ((__HANDLE__)->Instance->CR1 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           (((__INTERRUPT__) >> 28U) == UART_CR2_REG_INDEX)? ((__HANDLE__)->Instance->CR2 &= ~((__INTERRUPT__) & UART_IT_MASK)): \
                                                           ((__HANDLE__)->Instance->CR3 &= ~ ((__INTERRUPT__) & UART_IT_MASK)))

/** @brief  Checks whether the specified UART interrupt source is enabled or not.
  * @param  __HANDLE__ specifies the UART Handle.
  *         UART Handle selects the USARTx or UARTy peripheral
  *         (USART,UART availability and x,y values depending on device).
  * @param  __IT__ specifies the UART interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg UART_IT_CTS: CTS change interrupt (not available for UART4 and UART5)
  *            @arg UART_IT_LBD: LIN Break detection interrupt
  *            @arg UART_IT_TXE: Transmit Data Register empty interrupt
  *            @arg UART_IT_TC:  Transmission complete interrupt
  *            @arg UART_IT_RXNE: Receive Data register not empty interrupt
  *            @arg UART_IT_IDLE: Idle line detection interrupt
  *            @arg UART_IT_ERR: Error interrupt
  * @retval The new state of __IT__ (TRUE or FALSE).
  */
// 检查指定的UART中断源是否已使能
// 逻辑：读取对应的控制寄存器(CR1/CR2/CR3)并与中断掩码进行与运算
#define __HAL_UART_GET_IT_SOURCE(__HANDLE__, __IT__) (((((__IT__) >> 28U) == UART_CR1_REG_INDEX)? (__HANDLE__)->Instance->CR1:(((((uint32_t)(__IT__)) >> 28U) == UART_CR2_REG_INDEX)? \
                                                       (__HANDLE__)->Instance->CR2 : (__HANDLE__)->Instance->CR3)) & (((uint32_t)(__IT__)) & UART_IT_MASK))

/** @brief  Enable CTS flow control
  * @note   This macro allows to enable CTS hardware flow control for a given UART instance,
  *         without need to call HAL_UART_Init() function.
  *         As involving direct access to UART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying CTS Hw flow control feature activation, without need
  *         for USART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - UART instance should have already been initialised (through call of HAL_UART_Init() )
  *           - macro could only be called when corresponding UART instance is disabled (i.e __HAL_UART_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_UART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the UART Handle.
  *         The Handle Instance can be any USARTx (supporting the HW Flow control feature).
  *         It is used to select the USART peripheral (USART availability and x value depending on device).
  * @retval None
  */
// 使能CTS硬件流控制
// 逻辑：原子操作设置CR3寄存器的CTSE位，并更新句柄中的配置参数
#define __HAL_UART_HWCONTROL_CTS_ENABLE(__HANDLE__)        \
  do{                                                      \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE);  \ // 原子操作设置CTSE位
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_CTSE;        \ // 同步更新句柄初始化配置
  } while(0U)

/** @brief  Disable CTS flow control
  * @note   This macro allows to disable CTS hardware flow control for a given UART instance,
  *         without need to call HAL_UART_Init() function.
  *         As involving direct access to UART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying CTS Hw flow control feature activation, without need
  *         for USART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - UART instance should have already been initialised (through call of HAL_UART_Init() )
  *           - macro could only be called when corresponding UART instance is disabled (i.e __HAL_UART_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_UART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the UART Handle.
  *         The Handle Instance can be any USARTx (supporting the HW Flow control feature).
  *         It is used to select the USART peripheral (USART availability and x value depending on device).
  * @retval None
  */
// 禁用CTS硬件流控制
// 逻辑：原子操作清除CR3寄存器的CTSE位，并更新句柄中的配置参数
#define __HAL_UART_HWCONTROL_CTS_DISABLE(__HANDLE__)        \
  do{                                                       \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_CTSE); \ // 原子操作清除CTSE位
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_CTSE);      \ // 同步更新句柄初始化配置
  } while(0U)

/** @brief  Enable RTS flow control
  *         This macro allows to enable RTS hardware flow control for a given UART instance,
  *         without need to call HAL_UART_Init() function.
  *         As involving direct access to UART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying RTS Hw flow control feature activation, without need
  *         for USART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - UART instance should have already been initialised (through call of HAL_UART_Init() )
  *           - macro could only be called when corresponding UART instance is disabled (i.e __HAL_UART_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_UART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the UART Handle.
  *         The Handle Instance can be any USARTx (supporting the HW Flow control feature).
  *         It is used to select the USART peripheral (USART availability and x value depending on device).
  * @retval None
  */
// 使能RTS硬件流控制
// 逻辑：原子操作设置CR3寄存器的RTSE位，并更新句柄中的配置参数
#define __HAL_UART_HWCONTROL_RTS_ENABLE(__HANDLE__)       \
  do{                                                     \
    ATOMIC_SET_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE); \ // 原子操作设置RTSE位
    (__HANDLE__)->Init.HwFlowCtl |= USART_CR3_RTSE;       \ // 同步更新句柄初始化配置
  } while(0U)

/** @brief  Disable RTS flow control
  *         This macro allows to disable RTS hardware flow control for a given UART instance,
  *         without need to call HAL_UART_Init() function.
  *         As involving direct access to UART registers, usage of this macro should be fully endorsed by user.
  * @note   As macro is expected to be used for modifying RTS Hw flow control feature activation, without need
  *         for USART instance Deinit/Init, following conditions for macro call should be fulfilled :
  *           - UART instance should have already been initialised (through call of HAL_UART_Init() )
  *           - macro could only be called when corresponding UART instance is disabled (i.e __HAL_UART_DISABLE(__HANDLE__))
  *             and should be followed by an Enable macro (i.e __HAL_UART_ENABLE(__HANDLE__)).
  * @param  __HANDLE__ specifies the UART Handle.
  *         The Handle Instance can be any USARTx (supporting the HW Flow control feature).
  *         It is used to select the USART peripheral (USART availability and x value depending on device).
  * @retval None
  */
// 禁用RTS硬件流控制
// 逻辑：原子操作清除CR3寄存器的RTSE位，并更新句柄中的配置参数
#define __HAL_UART_HWCONTROL_RTS_DISABLE(__HANDLE__)       \
  do{                                                      \
    ATOMIC_CLEAR_BIT((__HANDLE__)->Instance->CR3, USART_CR3_RTSE);\ // 原子操作清除RTSE位
    (__HANDLE__)->Init.HwFlowCtl &= ~(USART_CR3_RTSE);     \ // 同步更新句柄初始化配置
  } while(0U)
#if defined(USART_CR3_ONEBIT)

/** @brief  Macro to enable the UART's one bit sample method
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval None
  */
// 使能UART一位采样方法（抑制噪声干扰）
#define __HAL_UART_ONE_BIT_SAMPLE_ENABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3|= USART_CR3_ONEBIT)

/** @brief  Macro to disable the UART's one bit sample method
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval None
  */
// 禁用UART一位采样方法（恢复为3位采样）
#define __HAL_UART_ONE_BIT_SAMPLE_DISABLE(__HANDLE__) ((__HANDLE__)->Instance->CR3\
                                                       &= (uint16_t)~((uint16_t)USART_CR3_ONEBIT))
#endif /* UART_ONE_BIT_SAMPLE_Feature */

/** @brief  Enable UART
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval None
  */
// 使能UART外设（设置CR1寄存器的UE位）
#define __HAL_UART_ENABLE(__HANDLE__)               ((__HANDLE__)->Instance->CR1 |=  USART_CR1_UE)

/** @brief  Disable UART
  * @param  __HANDLE__ specifies the UART Handle.
  * @retval None
  */
// 禁用UART外设（清除CR1寄存器的UE位）
#define __HAL_UART_DISABLE(__HANDLE__)              ((__HANDLE__)->Instance->CR1 &=  ~USART_CR1_UE)
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup UART_Exported_Functions
  * @{
  */

/** @addtogroup UART_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */

/* Initialization/de-initialization functions  **********************************/
/* 初始化/反初始化函数 */
// 初始化UART
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
// 初始化半双工模式
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
// 初始化LIN模式
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
// 初始化多处理器模式
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
// 反初始化UART
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
// MSP初始化回调函数（用户在此编写底层硬件配置，如GPIO、时钟）
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
// MSP反初始化回调函数（用户在此编写底层硬件复位）
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

/* Callbacks Register/UnRegister functions  ***********************************/
/* 回调函数注册/注销函数 */
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

/** @addtogroup UART_Exported_Functions_Group2 IO operation functions
  * @{
  */

/* IO operation functions *******************************************************/
/* IO操作函数 */
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
// 暂停DMA传输
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
// 恢复DMA传输
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
// 停止DMA传输
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

// 阻塞模式接收数据直到检测到空闲线路
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
// 非阻塞模式（中断）接收数据直到检测到空闲线路
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
// 非阻塞模式（DMA）接收数据直到检测到空闲线路
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

// 获取接收事件类型
HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(UART_HandleTypeDef *huart);

/* Transfer Abort functions */
/* 传输中止函数 */
// 中止正在进行的传输（阻塞模式）
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
// 仅中止发送传输
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
// 仅中止接收传输
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
// 中止正在进行的传输（非阻塞模式，使用中断）
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
// 仅中止发送传输（非阻塞模式）
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
// 仅中止接收传输（非阻塞模式）
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

// UART中断处理函数（需在stm32f1xx_it.c中调用）
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

// 扩展接收事件回调函数
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* Peripheral Control functions  ************************************************/
/* 外设控制函数 */
// 发送LIN断开信号
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
// 进入多处理器静默模式
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
// 退出多处理器静默模式
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
// 使能半双工发送器
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
// 使能半双工接收器
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* Peripheral State functions  **************************************************/
/* 外设状态函数 */
// 获取UART当前状态
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
// 获取UART错误码
uint32_t              HAL_UART_GetError(const UART_HandleTypeDef *huart);
/**
  * @}
  */

/**
  * @}
  */
/* Private types -------------------------------------------------------------*/
/* 私有类型 -------------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* 私有变量 -------------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* 私有常量 -------------------------------------------------------------------*/
/** @defgroup UART_Private_Constants UART Private Constants
  * @{
  */
/** @brief UART interruptions flag mask
  *
  */
// UART中断标志掩码，用于提取中断标志位
#define UART_IT_MASK                     0x0000FFFFU

// 定义控制寄存器索引，用于中断操作中定位寄存器
#define UART_CR1_REG_INDEX               1U // 控制寄存器1索引
#define UART_CR2_REG_INDEX               2U // 控制寄存器2索引
#define UART_CR3_REG_INDEX               3U // 控制寄存器3索引
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* 私有宏 ---------------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART Private Macros
  * @{
  */
// 检查字长参数是否有效（8位或9位）
#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))
// 检查LIN模式字长参数是否有效（仅限8位）
#define IS_UART_LIN_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B))
// 检查停止位参数是否有效（1位或2位）
#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_2))
// 检查校验位参数是否有效（无校验、偶校验、奇校验）
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))
// 检查硬件流控制参数是否有效
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HWCONTROL_NONE) || \
                               ((CONTROL) == UART_HWCONTROL_RTS) || \
                               ((CONTROL) == UART_HWCONTROL_CTS) || \
                               ((CONTROL) == UART_HWCONTROL_RTS_CTS))
// 检查模式参数是否有效（TX/RX模式）
#define IS_UART_MODE(MODE) ((((MODE) & 0x0000FFF3U) == 0x00U) && ((MODE) != 0x00U))
// 检查状态参数是否有效
#define IS_UART_STATE(STATE) (((STATE) == UART_STATE_DISABLE) || \
                              ((STATE) == UART_STATE_ENABLE))
#if defined(USART_CR1_OVER8)
// 检查过采样参数是否有效（16倍或8倍）
#define IS_UART_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16) || \
                                        ((SAMPLING) == UART_OVERSAMPLING_8))
#endif /* USART_CR1_OVER8 */
// 检查LIN模式过采样参数是否有效（仅限16倍）
#define IS_UART_LIN_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16))
// 检查LIN断开检测长度参数是否有效（10位或11位）
#define IS_UART_LIN_BREAK_DETECT_LENGTH(LENGTH) (((LENGTH) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                 ((LENGTH) == UART_LINBREAKDETECTLENGTH_11B))
// 检查唤醒方法参数是否有效（空闲线路或地址标记）
#define IS_UART_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == UART_WAKEUPMETHOD_IDLELINE) || \
                                      ((WAKEUP) == UART_WAKEUPMETHOD_ADDRESSMARK))
// 检查波特率参数是否有效（最大4.5Mbps）
#define IS_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 4500000U)
// 检查地址参数是否有效（最大0x0F，即4位地址）
#define IS_UART_ADDRESS(ADDRESS) ((ADDRESS) <= 0x0FU)

// 计算波特率寄存器值（16倍过采样）
// DIV = PCLK * 25 / (4 * BaudRate)
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))
// 计算整数部分
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)
// 计算小数部分
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + (UART DIVFRAQ & 0xF0) + (UART DIVFRAQ & 0x0FU) */
// 组合BRR寄存器值（整数部分左移4位 + 小数部分）
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xFU))

// 计算波特率寄存器值（8倍过采样）
// DIV = PCLK * 25 / (2 * BaudRate)
#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))
// 计算整数部分
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)
// 计算小数部分
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)
/* UART BRR = mantissa + overflow + fraction
            = (UART DIVMANT << 4) + ((UART DIVFRAQ & 0xF8) << 1) + (UART DIVFRAQ & 0x07U) */
// 组合BRR寄存器值（整数部分左移4位 + 小数部分处理）
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                         ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/* 私有函数 -------------------------------------------------------------------*/
/** @defgroup UART_Private_Functions UART Private Functions
  * @{
  */

// 启动中断接收
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
// 启动DMA接收
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
