/* 传输中止函数 */

/**
  * @brief  中止正在进行的传输和接收（阻塞模式）.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);

/**
  * @brief  仅中止正在进行的发送传输（阻塞模式）.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);

/**
  * @brief  仅中止正在进行的接收传输（阻塞模式）.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);

/**
  * @brief  中止正在进行的传输和接收（非阻塞模式/中断模式）.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);

/**
  * @brief  仅中止正在进行的发送传输（非阻塞模式/中断模式）.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);

/**
  * @brief  仅中止正在进行的接收传输（非阻塞模式/中断模式）.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

/**
  * @brief  UART中断处理函数.
  * @note   这个函数应该在中断服务函数中被调用，用于处理发送、接收和错误中断。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);

/**
  * @brief  发送完成回调函数.
  * @note   当发送完成（阻塞模式）或发送中断处理完成时调用。
  *         用户可以在自己的代码中重新实现此函数。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  发送半完成回调函数.
  * @note   在DMA模式下，当发送过半时调用。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  接收完成回调函数.
  * @note   当接收完成（阻塞模式）或接收中断处理完成时调用。
  *         用户可以在自己的代码中重新实现此函数。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  接收半完成回调函数.
  * @note   在DMA模式下，当接收过半时调用。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  UART错误回调函数.
  * @note   当发生UART错误（如溢出、帧错误、噪声错误等）时调用。
  *         用户可以在自己的代码中重新实现此函数以进行错误处理。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);

/**
  * @brief  中止完成回调函数.
  * @note   当中止操作完成时调用。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  发送中止完成回调函数.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  接收中止完成回调函数.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 无
  */
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

/**
  * @brief  扩展接收事件回调函数.
  * @note   用于处理高级接收事件，如接收超时等。
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @param  Size: 接收到的数据大小
  * @retval 无
  */
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);

/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group3
  * @{
  */
/* 外设控制函数  ************************************************/

/**
  * @brief  发送LIN总线断开信号.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);

/**
  * @brief  使多处理器模式进入静默模式.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);

/**
  * @brief  使多处理器模式退出静默模式.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);

/**
  * @brief  使能半双工模式的发送器.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);

/**
  * @brief  使能半双工模式的接收器.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);
/**
  * @}
  */

/** @addtogroup UART_Exported_Functions_Group4
  * @{
  */
/* 外设状态函数  **************************************************/

/**
  * @brief  获取UART外设的状态.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval UART状态枚举值（就绪、忙、错误等）
  */
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);

/**
  * @brief  获取UART外设的错误码.
  * @param  huart: 指向包含UART配置信息的结构体的指针
  * @retval 错误码，是各种错误标志位的或运算结果
  */
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
/** @defgroup UART_Private_Constants UART Private Constants
  * @{
  */
/** @brief UART中断标志掩码
  *         用于提取中断标志位，低16位有效
  */
#define UART_IT_MASK                     0x0000FFFFU

// UART控制寄存器索引，用于内部函数定位具体的寄存器
#define UART_CR1_REG_INDEX               1U    // 控制寄存器1索引
#define UART_CR2_REG_INDEX               2U    // 控制寄存器2索引
#define UART_CR3_REG_INDEX               3U    // 控制寄存器3索引
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup UART_Private_Macros UART Private Macros
  * @{
  */

// 检查字长度参数是否有效：8位或9位
#define IS_UART_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B) || \
                                     ((LENGTH) == UART_WORDLENGTH_9B))

// 检查LIN模式下的字长度参数是否有效：LIN模式仅支持8位
#define IS_UART_LIN_WORD_LENGTH(LENGTH) (((LENGTH) == UART_WORDLENGTH_8B))

// 检查停止位参数是否有效：1位或2位
#define IS_UART_STOPBITS(STOPBITS) (((STOPBITS) == UART_STOPBITS_1) || \
                                    ((STOPBITS) == UART_STOPBITS_2))

// 检查校验位参数是否有效：无校验、偶校验或奇校验
#define IS_UART_PARITY(PARITY) (((PARITY) == UART_PARITY_NONE) || \
                                ((PARITY) == UART_PARITY_EVEN) || \
                                ((PARITY) == UART_PARITY_ODD))

// 检查硬件流控参数是否有效：无、RTS、CTS或RTS+CTS
#define IS_UART_HARDWARE_FLOW_CONTROL(CONTROL)\
                              (((CONTROL) == UART_HWCONTROL_NONE) || \
                               ((CONTROL) == UART_HWCONTROL_RTS) || \
                               ((CONTROL) == UART_HWCONTROL_CTS) || \
                               ((CONTROL) == UART_HWCONTROL_RTS_CTS))

// 检查UART模式参数是否有效
// (MODE) & 0x0000FFF3U) == 0x00U 确保只设置了允许的模式位
// ((MODE) != 0x00U) 确保至少选择了一种模式（TX或RX）
#define IS_UART_MODE(MODE) ((((MODE) & 0x0000FFF3U) == 0x00U) && ((MODE) != 0x00U))

// 检查UART状态参数是否有效：禁用或使能
#define IS_UART_STATE(STATE) (((STATE) == UART_STATE_DISABLE) || \
                              ((STATE) == UART_STATE_ENABLE))

#if defined(USART_CR1_OVER8)
// 检查过采样参数是否有效：16倍过采样或8倍过采样（如果硬件支持）
#define IS_UART_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16) || \
                                        ((SAMPLING) == UART_OVERSAMPLING_8))
#endif /* USART_CR1_OVER8 */

// 检查LIN模式下的过采样参数：LIN模式仅支持16倍过采样
#define IS_UART_LIN_OVERSAMPLING(SAMPLING) (((SAMPLING) == UART_OVERSAMPLING_16))

// 检查LIN断开检测长度参数：10位或11位
#define IS_UART_LIN_BREAK_DETECT_LENGTH(LENGTH) (((LENGTH) == UART_LINBREAKDETECTLENGTH_10B) || \
                                                 ((LENGTH) == UART_LINBREAKDETECTLENGTH_11B))

// 检查唤醒方法参数：空闲线路唤醒或地址标记唤醒
#define IS_UART_WAKEUPMETHOD(WAKEUP) (((WAKEUP) == UART_WAKEUPMETHOD_IDLELINE) || \
                                      ((WAKEUP) == UART_WAKEUPMETHOD_ADDRESSMARK))

// 检查波特率参数：最大支持4.5Mbps
#define IS_UART_BAUDRATE(BAUDRATE) ((BAUDRATE) <= 4500000U)

// 检查UART地址参数：地址最大为0x0F (4位地址)
#define IS_UART_ADDRESS(ADDRESS) ((ADDRESS) <= 0x0FU)

// ---------------------------------------------------------------------------
// 以下是一组用于计算波特率寄存器(BRR)值的宏定义
// 公式原理请参考STM32参考手册中的波特率生成章节
// ---------------------------------------------------------------------------

// 计算16倍过采样下的分频系数整数部分（DIV_Mantissa）
// 公式：Div = (PCLK * 25) / (4 * BaudRate)
#define UART_DIV_SAMPLING16(_PCLK_, _BAUD_)            (((_PCLK_)*25U)/(4U*(_BAUD_)))

// 提取16倍过采样下的整数部分（Mantissa）
#define UART_DIVMANT_SAMPLING16(_PCLK_, _BAUD_)        (UART_DIV_SAMPLING16((_PCLK_), (_BAUD_))/100U)

// 计算16倍过采样下的小数部分
// 通过四舍五入计算
#define UART_DIVFRAQ_SAMPLING16(_PCLK_, _BAUD_)        ((((UART_DIV_SAMPLING16((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) * 100U)) * 16U)\
                                                         + 50U) / 100U)

/* UART BRR寄存器值计算 = 整数部分 + 溢出位 + 小数部分
   最终写入BRR寄存器的值 = (Mantissa << 4) + Fraction
   这里进行了移位和合并操作 */
#define UART_BRR_SAMPLING16(_PCLK_, _BAUD_)            (((UART_DIVMANT_SAMPLING16((_PCLK_), (_BAUD_)) << 4U) + \
                                                         (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0xF0U)) + \
                                                        (UART_DIVFRAQ_SAMPLING16((_PCLK_), (_BAUD_)) & 0x0FU))

// 计算8倍过采样下的分频系数
// 公式：Div = (PCLK * 25) / (2 * BaudRate)
#define UART_DIV_SAMPLING8(_PCLK_, _BAUD_)             (((_PCLK_)*25U)/(2U*(_BAUD_)))

// 提取8倍过采样下的整数部分
#define UART_DIVMANT_SAMPLING8(_PCLK_, _BAUD_)         (UART_DIV_SAMPLING8((_PCLK_), (_BAUD_))/100U)

// 计算8倍过采样下的小数部分
#define UART_DIVFRAQ_SAMPLING8(_PCLK_, _BAUD_)         ((((UART_DIV_SAMPLING8((_PCLK_), (_BAUD_)) - (UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) * 100U)) * 8U)\
                                                         + 50U) / 100U)

/* UART BRR寄存器值计算 (8倍过采样)
   BRR = (Mantissa << 4) + ((Fraction & 0xF8) << 1) + (Fraction & 0x07) */
#define UART_BRR_SAMPLING8(_PCLK_, _BAUD_)             (((UART_DIVMANT_SAMPLING8((_PCLK_), (_BAUD_)) << 4U) + \
                                                         ((UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0xF8U) << 1U)) + \
                                                        (UART_DIVFRAQ_SAMPLING8((_PCLK_), (_BAUD_)) & 0x07U))

/**
  * @}
  */

/* 私有函数 ---------------------------------------------------------*/
/** @defgroup UART_Private_Functions UART Private Functions
  * @{
  */

/**
  * @brief  启动中断模式接收.
  * @param  huart: 指向UART句柄的指针
  * @param  pData: 指向接收缓冲区的指针
  * @param  Size: 预期接收的数据大小
  * @retval HAL状态
  */
HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

/**
  * @brief  启动DMA模式接收.
  * @param  huart: 指向UART句柄的指针
  * @param  pData: 指向接收缓冲区的指针
  * @param  Size: 预期接收的数据大小
  * @retval HAL状态
  */
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
