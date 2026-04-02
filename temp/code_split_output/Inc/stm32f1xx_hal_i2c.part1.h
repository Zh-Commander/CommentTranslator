/** @brief  Checks whether the specified I2C flag is set or not.
  * @param  __HANDLE__ specifies the I2C Handle.
  *         指定 I2C 句柄。
  * @param  __FLAG__ specifies the flag to check.
  *         指定要检查的标志。
  *         This parameter can be one of the following values:
  *         该参数可以是以下值之一：
  *            @arg I2C_FLAG_OVR: Overrun/Underrun flag
  *                溢出/下溢标志
  *            @arg I2C_FLAG_AF: Acknowledge failure flag
  *                应答失败标志
  *            @arg I2C_FLAG_ARLO: Arbitration lost flag
  *                仲裁丢失标志
  *            @arg I2C_FLAG_BERR: Bus error flag
  *                总线错误标志
  *            @arg I2C_FLAG_TXE: Data register empty flag
  *                数据寄存器为空标志
  *            @arg I2C_FLAG_RXNE: Data register not empty flag
  *                数据寄存器非空标志
  *            @arg I2C_FLAG_STOPF: Stop detection flag
  *                停止位检测标志
  *            @arg I2C_FLAG_ADD10: 10-bit header sent flag
  *                10位头发送标志
  *            @arg I2C_FLAG_BTF: Byte transfer finished flag
  *                字节传输完成标志
  *            @arg I2C_FLAG_ADDR: Address sent flag
  *                                Address matched flag
  *                地址发送标志
  *                地址匹配标志
  *            @arg I2C_FLAG_SB: Start bit flag
  *                起始位标志
  *            @arg I2C_FLAG_DUALF: Dual flag
  *                双地址标志
  *            @arg I2C_FLAG_GENCALL: General call header flag
  *                广播呼叫头标志
  *            @arg I2C_FLAG_TRA: Transmitter/Receiver flag
  *                发送/接收模式标志
  *            @arg I2C_FLAG_BUSY: Bus busy flag
  *                总线忙标志
  *            @arg I2C_FLAG_MSL: Master/Slave flag
  *                主/从模式标志
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  *         返回 __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
// 宏定义：获取 I2C 标志位状态
// 逻辑说明：I2C 标志位分布在 SR1 和 SR2 两个寄存器中。
// 通过判断 __FLAG__ 的高 16 位（用于区分寄存器）来决定读取 SR1 还是 SR2。
// 如果高 16 位是 0x01，则读取 SR2；否则读取 SR1。
// 然后将读取到的值与标志位掩码进行与运算，判断该标志位是否被置位。
#define __HAL_I2C_GET_FLAG(__HANDLE__, __FLAG__) ((((uint8_t)((__FLAG__) >> 16U)) == 0x01U) ? \
                                                  (((((__HANDLE__)->Instance->SR1) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET) : \
                                                  (((((__HANDLE__)->Instance->SR2) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET))

/** @brief  Clears the I2C pending flags which are cleared by writing 0 in a specific bit.
  * @brief  清除 I2C 挂起标志，这些标志通过在特定位写入 0 来清除。
  * @param  __HANDLE__ specifies the I2C Handle.
  *         指定 I2C 句柄。
  * @param  __FLAG__ specifies the flag to clear.
  *         指定要清除的标志。
  *         This parameter can be any combination of the following values:
  *         该参数可以是以下值的任意组合：
  *            @arg I2C_FLAG_OVR: Overrun/Underrun flag (Slave mode)
  *                溢出/下溢标志 (从模式)
  *            @arg I2C_FLAG_AF: Acknowledge failure flag
  *                应答失败标志
  *            @arg I2C_FLAG_ARLO: Arbitration lost flag (Master mode)
  *                仲裁丢失标志 (主模式)
  *            @arg I2C_FLAG_BERR: Bus error flag
  *                总线错误标志
  * @retval None
  *         无返回值
  */
// 宏定义：清除 I2C 挂起标志
// 实现原理：对 SR1 寄存器写入反码（实际上是写 0 清除，写 1 无效）。
// 注意：这里利用了硬件特性，某些标志位通过软件读取或写入特定值来清除。
#define __HAL_I2C_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR1 = ~((__FLAG__) & I2C_FLAG_MASK))

/** @brief  Clears the I2C ADDR pending flag.
  * @brief  清除 I2C ADDR 挂起标志。
  * @param  __HANDLE__ specifies the I2C Handle.
  *         指定 I2C 句柄。
  *         This parameter can be I2C where x: 1, 2, or 3 to select the I2C peripheral.
  * @retval None
  *         无返回值
  */
// 宏定义：清除 ADDR 标志
// 实现原理：根据 STM32 参考手册，清除 ADDR 标志的序列是：
// 1. 读取 SR1 寄存器
// 2. 读取 SR2 寄存器
// 这段代码使用了 do...while(0) 结构，确保宏定义在使用时能像函数一样安全调用。
// UNUSED(tmpreg) 用于防止编译器产生变量未使用的警告。
#define __HAL_I2C_CLEAR_ADDRFLAG(__HANDLE__)    \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR1;       \
    tmpreg = (__HANDLE__)->Instance->SR2;       \
    UNUSED(tmpreg);                             \
  } while(0)

/** @brief  Clears the I2C STOPF pending flag.
  * @brief  清除 I2C STOPF 挂起标志。
  * @param  __HANDLE__ specifies the I2C Handle.
  *         指定 I2C 句柄。
  * @retval None
  *         无返回值
  */
// 宏定义：清除 STOPF (停止位检测) 标志
// 实现原理：根据参考手册，清除 STOPF 标志的序列是：
// 1. 读取 SR1 寄存器
// 2. 写入 CR1 寄存器 (这里重新使能了 I2C 外设)
#define __HAL_I2C_CLEAR_STOPFLAG(__HANDLE__)           \
  do{                                                  \
    __IO uint32_t tmpreg = 0x00U;                      \
    tmpreg = (__HANDLE__)->Instance->SR1;              \
    SET_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE);  \
    UNUSED(tmpreg);                                    \
  } while(0)

/** @brief  Enable the specified I2C peripheral.
  * @brief  使能指定的 I2C 外设。
  * @param  __HANDLE__ specifies the I2C Handle.
  *         指定 I2C 句柄。
  * @retval None
  *         无返回值
  */
// 宏定义：使能 I2C 外设
// 操作：设置 CR1 寄存器中的 PE 位
#define __HAL_I2C_ENABLE(__HANDLE__)                  SET_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE)

/** @brief  Disable the specified I2C peripheral.
  * @brief  禁用指定的 I2C 外设。
  * @param  __HANDLE__ specifies the I2C Handle.
  *         指定 I2C 句柄。
  * @retval None
  *         无返回值
  */
// 宏定义：禁用 I2C 外设
// 操作：清除 CR1 寄存器中的 PE 位
#define __HAL_I2C_DISABLE(__HANDLE__)                 CLEAR_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup I2C_Exported_Functions
  * @{
  */

/** @addtogroup I2C_Exported_Functions_Group1 Initialization and de-initialization functions
  * @{
  */
/* Initialization and de-initialization functions******************************/
/* 初始化和反初始化函数 ******************************************************/
// 初始化 I2C 外设，配置参数如时钟速度、地址模式等
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);
// 反初始化 I2C 外设，将寄存器恢复为默认值
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c);
// MSP 初始化函数 (MCU Specific Package)，用于配置底层硬件如 GPIO、时钟、中断
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);
// MSP 反初始化函数，用于释放底层硬件资源
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);

/* Callbacks Register/UnRegister functions  ***********************************/
/* 回调函数注册/注销函数 ***********************************/
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
// 注册用户自定义回调函数
HAL_StatusTypeDef HAL_I2C_RegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID, pI2C_CallbackTypeDef pCallback);
// 注销用户回调函数，恢复为默认弱定义回调
HAL_StatusTypeDef HAL_I2C_UnRegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID);

// 注册地址匹配回调函数 (用于从模式监听)
HAL_StatusTypeDef HAL_I2C_RegisterAddrCallback(I2C_HandleTypeDef *hi2c, pI2C_AddrCallbackTypeDef pCallback);
// 注销地址匹配回调函数
HAL_StatusTypeDef HAL_I2C_UnRegisterAddrCallback(I2C_HandleTypeDef *hi2c);
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group2 Input and Output operation functions
  * @{
  */
/* IO operation functions  ****************************************************/
/* 输入输出操作函数 ****************************************************/
/******* Blocking mode: Polling */
/******* 阻塞模式：轮询方式 */
// 主机发送数据 (阻塞模式，需指定超时时间)
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 主机接收数据 (阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 从机发送数据 (阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 从机接收数据 (阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 向指定内存地址写入数据 (阻塞模式，常用于 EEPROM 操作)
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 从指定内存地址读取数据 (阻塞模式)
HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
// 检测 I2C 设备是否就绪 (用于检测设备是否存在或总线是否忙碌)
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout);

/******* Non-Blocking mode: Interrupt */
/******* 非阻塞模式：中断方式 */
// 主机发送数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
// 主机接收数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
// 从机发送数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
// 从机接收数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
// 向指定内存地址写入数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
// 从指定内存地址读取数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);

// 主机顺序发送数据 (中断非阻塞模式，支持控制传输序列)
HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 主机顺序接收数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 从机顺序发送数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 从机顺序接收数据 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 使能监听模式 (中断非阻塞模式，用于从模式监听主机呼叫)
HAL_StatusTypeDef HAL_I2C_EnableListen_IT(I2C_HandleTypeDef *hi2c);
// 禁用监听模式
HAL_StatusTypeDef HAL_I2C_DisableListen_IT(I2C_HandleTypeDef *hi2c);
// 主机中止传输 (中断非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress);

/******* Non-Blocking mode: DMA */
/******* 非阻塞模式：DMA 方式 */
// 主机发送数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
// 主机接收数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);
// 从机发送数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
// 从机接收数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);
// 向指定内存地址写入数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);
// 从指定内存地址读取数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);

// 主机顺序发送数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 主机顺序接收数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 从机顺序发送数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
// 从机顺序接收数据 (DMA 非阻塞模式)
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);
/**
  * @}
  */

/** @addtogroup I2C_IRQ_Handler_and_Callbacks IRQ Handler and Callbacks
 * @{
 */
/******* I2C IRQHandler and Callbacks used in non blocking modes (Interrupt and DMA) */
/******* I2C 中断处理函数和回调函数，用于非阻塞模式 (中断和 DMA) */
// I2C 事件中断处理函数
void HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c);
// I2C 错误中断处理函数
void HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c);
// 主机发送完成回调函数
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c);
// 主机接收完成回调函数
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c);
// 从机发送完成回调函数
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);
// 从机接收完成回调函数
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);
// 地址匹配回调函数 (用于从模式监听)
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);
// 监听完成回调函数
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c);
// 内存写入完成回调函数
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c);
// 内存读取完成回调函数
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c);
// 错误回调函数
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
// 传输中止完成回调函数
void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c);
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group3 Peripheral State, Mode and Error functions
  * @{
  */
/* Peripheral State, Mode and Error functions  *********************************/
/* 外设状态、模式和错误函数 *********************************/
// 获取 I2C 当前状态 (如就绪、忙、错误等)
HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c);
// 获取 I2C 当前模式 (如主机模式、从机模式)
HAL_I2C_ModeTypeDef HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c);
// 获取 I2C 错误码
uint32_t HAL_I2C_GetError(I2C_HandleTypeDef *hi2c);

/**
  * @}
  */

/**
  * @}
  */
/* Private types -------------------------------------------------------------*/
/* 私有类型 -----------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* 私有变量 -----------------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* 私有常量 -----------------------------------------------------------------*/
/** @defgroup I2C_Private_Constants I2C Private Constants
  * @{
  */
// I2C 标志位掩码，用于提取标志位在寄存器中的位置
#define I2C_FLAG_MASK                    0x0000FFFFU
// 标准模式 (100kHz) 所需的最小外设时钟频率：2 MHz
#define I2C_MIN_PCLK_FREQ_STANDARD       2000000U     /*!< 2 MHz                     */
// 快速模式 (400kHz) 所需的最小外设时钟频率：4 MHz
#define I2C_MIN_PCLK_FREQ_FAST           4000000U     /*!< 4 MHz                     */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* 私有宏 --------------------------------------------------------------------*/
/** @defgroup I2C_Private_Macros I2C Private Macros
  * @{
  */

// 宏：检查 PCLK 时钟频率是否满足 I2C 速度要求
// 如果速度 <= 100kHz，检查 PCLK 是否小于 2MHz；否则检查是否小于 4MHz
#define I2C_MIN_PCLK_FREQ(__PCLK__, __SPEED__)             (((__SPEED__) <= 100000U) ? ((__PCLK__) < I2C_MIN_PCLK_FREQ_STANDARD) : ((__PCLK__) < I2C_MIN_PCLK_FREQ_FAST))

// 宏：计算 CCR (时钟控制寄存器) 的值
// CCR 决定了 SCL 的高低电平时间
#define I2C_CCR_CALCULATION(__PCLK__, __SPEED__, __COEFF__)     (((((__PCLK__) - 1U)/((__SPEED__) * (__COEFF__))) + 1U) & I2C_CCR_CCR)

// 宏：计算频率范围，单位 MHz
#define I2C_FREQRANGE(__PCLK__)                            ((__PCLK__)/1000000U)

// 宏：计算上升时间
// 标准模式最大 1000ns，快速模式最大 300ns
#define I2C_RISE_TIME(__FREQRANGE__, __SPEED__)            (((__SPEED__) <= 100000U) ? ((__FREQRANGE__) + 1U) : ((((__FREQRANGE__) * 300U) / 1000U) + 1U))

// 宏：计算标准模式下的 CCR 值
// 如果计算值小于 4，则强制设为 4 (数据手册要求)
#define I2C_SPEED_STANDARD(__PCLK__, __SPEED__)            ((I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 2U) < 4U)? 4U:I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 2U))

// 宏：计算快速模式下的 CCR 值
// 根据占空比设置 (Tlow/Thigh = 2 或 Tlow/Thigh = 16/9)
#define I2C_SPEED_FAST(__PCLK__, __SPEED__, __DUTYCYCLE__) (((__DUTYCYCLE__) == I2C_DUTYCYCLE_2)? I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 3U) : (I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 25U) | I2C_DUTYCYCLE_16_9))

// 宏：根据速度自动选择标准模式或快速模式的配置
#define I2C_SPEED(__PCLK__, __SPEED__, __DUTYCYCLE__)      (((__SPEED__) <= 100000U)? (I2C_SPEED_STANDARD((__PCLK__), (__SPEED__))) : \
                                                                  ((I2C_SPEED_FAST((__PCLK__), (__SPEED__), (__DUTYCYCLE__)) & I2C_CCR_CCR) == 0U)? 1U : \
                                                                  ((I2C_SPEED_FAST((__PCLK__), (__SPEED__), (__DUTYCYCLE__))) | I2C_CCR_FS))

// 宏：将 7 位地址转换为写地址 (最低位为 0)
#define I2C_7BIT_ADD_WRITE(__ADDRESS__)                    ((uint8_t)((__ADDRESS__) & (uint8_t)(~I2C_OAR1_ADD0)))
// 宏：将 7 位地址转换为读地址 (最低位为 1)
#define I2C_7BIT_ADD_READ(__ADDRESS__)                     ((uint8_t)((__ADDRESS__) | I2C_OAR1_ADD0))

// 宏：获取 10 位地址的低位
#define I2C_10BIT_ADDRESS(__ADDRESS__)                     ((uint8_t)((uint16_t)((__ADDRESS__) & (uint16_t)0x00FF)))
// 宏：生成 10 位地址发送时的头字节 (写方向)
#define I2C_10BIT_HEADER_WRITE(__ADDRESS__)                ((uint8_t)((uint16_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0x0300)) >> 7) | (uint16_t)0x00F0)))
// 宏：生成 10 位地址发送时的头字节 (读方向)
#define I2C_10BIT_HEADER_READ(__ADDRESS__)                 ((uint8_t)((uint16_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0x0300)) >> 7) | (uint16_t)(0x00F1))))

// 宏：获取内存地址的高字节 (MSB)
#define I2C_MEM_ADD_MSB(__ADDRESS__)                       ((uint8_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0xFF00)) >> 8)))
// 宏：获取内存地址的低字节 (LSB)
#define I2C_MEM_ADD_LSB(__ADDRESS__)                       ((uint8_t)((uint16_t)((__ADDRESS__) & (uint16_t)0x00FF)))

/** @defgroup I2C_IS_RTC_Definitions I2C Private macros to check input parameters
  * @{
  */
// 宏：检查占空比参数是否有效
#define IS_I2C_DUTY_CYCLE(CYCLE) (((CYCLE) == I2C_DUTYCYCLE_2) || \
                                  ((CYCLE) == I2C_DUTYCYCLE_16_9))
// 宏：检查寻址模式参数是否有效 (7位或10位)
#define IS_I2C_ADDRESSING_MODE(ADDRESS) (((ADDRESS) == I2C_ADDRESSINGMODE_7BIT) || \
                                         ((ADDRESS) == I2C_ADDRESSINGMODE_10BIT))
// 宏：检查双地址模式参数是否有效
#define IS_I2C_DUAL_ADDRESS(ADDRESS) (((ADDRESS) == I2C_DUALADDRESS_DISABLE) || \
                                      ((ADDRESS) == I2C_DUALADDRESS_ENABLE))
// 宏：检查广播呼叫模式参数是否有效
#define IS_I2C_GENERAL_CALL(CALL) (((CALL) == I2C_GENERALCALL_DISABLE) || \
                                   ((CALL) == I2C_GENERALCALL_ENABLE))
// 宏：检查时钟拉伸模式参数是否有效
#define IS_I2C_NO_STRETCH(STRETCH) (((STRETCH) == I2C_NOSTRETCH_DISABLE) || \
                                    ((STRETCH) == I2C_NOSTRETCH_ENABLE))
// 宏：检查内存地址大小参数是否有效 (8位或16位)
#define IS_I2C_MEMADD_SIZE(SIZE) (((SIZE) == I2C_MEMADD_SIZE_8BIT) || \
                                  ((SIZE) == I2C_MEMADD_SIZE_16BIT))
// 宏：检查时钟速度参数是否有效 (最大 400kHz)
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) > 0U) && ((SPEED) <= 400000U))
// 宏：检查自身地址 1 是否有效 (10位地址范围内)
#define IS_I2C_OWN_ADDRESS1(ADDRESS1) (((ADDRESS1) & 0xFFFFFC00U) == 0U)
// 宏：检查自身地址 2 是否有效 (7位地址范围内)
#define IS_I2C_OWN_ADDRESS2(ADDRESS2) (((ADDRESS2) & 0xFFFFFF01U) == 0U)
// 宏：检查传输选项参数是否有效
#define IS_I2C_TRANSFER_OPTIONS_REQUEST(REQUEST)      (((REQUEST) == I2C_FIRST_FRAME)              || \
                                                       ((REQUEST) == I2C_FIRST_AND_NEXT_FRAME)     || \
                                                       ((REQUEST) == I2C_NEXT_FRAME)               || \
                                                       ((REQUEST) == I2C_FIRST_AND_LAST_FRAME)     || \
                                                       ((REQUEST) == I2C_LAST_FRAME)               || \
                                                       ((REQUEST) == I2C_LAST_FRAME_NO_STOP)       || \
                                                       IS_I2C_TRANSFER_OTHER_OPTIONS_REQUEST(REQUEST))

// 宏：检查其他传输选项参数
#define IS_I2C_TRANSFER_OTHER_OPTIONS_REQUEST(REQUEST) (((REQUEST) == I2C_OTHER_FRAME)     || \
                                                        ((REQUEST) == I2C_OTHER_AND_LAST_FRAME))

// 宏：检查标志位是否置位 (内部使用)
#define I2C_CHECK_FLAG(__ISR__, __FLAG__)         ((((__ISR__) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET)
// 宏：检查中断源是否使能 (内部使用)
#define I2C_CHECK_IT_SOURCE(__CR1__, __IT__)      ((((__CR1__) & (__IT__)) == (__IT__)) ? SET : RESET)
/**
  * @}
  */

/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/* 私有函数 -----------------------------------------------------------------*/
/** @defgroup I2C_Private_Functions I2C Private Functions
  * @{
  */

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


#endif /* __STM32F1xx_HAL_I2C_H */
