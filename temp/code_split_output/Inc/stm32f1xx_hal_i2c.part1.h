/** @brief  检查指定的 I2C 标志位是否被置位。
  * @param  __HANDLE__ 指定 I2C 句柄，该句柄包含了 I2C 模块的配置信息。
  * @param  __FLAG__ 指定需要检查的标志位。
  *         该参数可以是以下值之一：
  *            @arg I2C_FLAG_OVR: 溢出/下溢标志位
  *            @arg I2C_FLAG_AF: 应答失败标志位
  *            @arg I2C_FLAG_ARLO: 仲裁丢失标志位
  *            @arg I2C_FLAG_BERR: 总线错误标志位
  *            @arg I2C_FLAG_TXE: 数据寄存器为空标志位
  *            @arg I2C_FLAG_RXNE: 数据寄存器非空标志位
  *            @arg I2C_FLAG_STOPF: 停止位检测标志位
  *            @arg I2C_FLAG_ADD10: 10位头发送标志位
  *            @arg I2C_FLAG_BTF: 字节传输结束标志位
  *            @arg I2C_FLAG_ADDR: 地址发送标志位
  *                                地址匹配标志位
  *            @arg I2C_FLAG_SB: 起始位标志位
  *            @arg I2C_FLAG_DUALF: 双地址标志位
  *            @arg I2C_FLAG_GENCALL: 广播呼叫头标志位
  *            @arg I2C_FLAG_TRA: 发送/接收模式标志位
  *            @arg I2C_FLAG_BUSY: 总线忙标志位
  *            @arg I2C_FLAG_MSL: 主/从模式标志位
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
/* 获取 I2C 标志位状态的宏定义 */
/* 逻辑说明：通过判断标志位的高16位（用于区分SR1或SR2寄存器）来选择读取SR1还是SR2寄存器，
   然后与掩码后的标志位进行与运算，判断是否置位 */
#define __HAL_I2C_GET_FLAG(__HANDLE__, __FLAG__) ((((uint8_t)((__FLAG__) >> 16U)) == 0x01U) ? \
                                                  (((((__HANDLE__)->Instance->SR1) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET) : \
                                                  (((((__HANDLE__)->Instance->SR2) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET))

/** @brief  清除 I2C 挂起标志位，这些标志位通过在特定位置写 0 来清除（实际操作是读取寄存器后写0，这里直接对SR1赋值）。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @param  __FLAG__ 指定需要清除的标志位。
  *         该参数可以是以下值的任意组合：
  *            @arg I2C_FLAG_OVR: 溢出/下溢标志位 (从模式)
  *            @arg I2C_FLAG_AF: 应答失败标志位
  *            @arg I2C_FLAG_ARLO: 仲裁丢失标志位 (主模式)
  *            @arg I2C_FLAG_BERR: 总线错误标志位
  * @retval 无
  */
/* 清除 I2C 标志位的宏定义 */
/* 原理：对 SR1 寄存器写入取反后的值（对应位写0清除），仅清除掩码范围内的位 */
#define __HAL_I2C_CLEAR_FLAG(__HANDLE__, __FLAG__) ((__HANDLE__)->Instance->SR1 = ~((__FLAG__) & I2C_FLAG_MASK))

/** @brief  清除 I2C ADDR 挂起标志位。
  * @param  __HANDLE__ 指定 I2C 句柄。
  *         该参数可以是 I2C，其中 x: 1, 2, 或 3 用于选择 I2C 外设。
  * @retval 无
  */
/* 清除 ADDR 标志位的宏定义 */
/* 注意：清除 ADDR 标志位需要特定的软件时序：先读 SR1，再读 SR2。
   这里定义了一个临时变量 tmpreg 来执行这些读取操作。 */
#define __HAL_I2C_CLEAR_ADDRFLAG(__HANDLE__)    \
  do{                                           \
    __IO uint32_t tmpreg = 0x00U;               \
    tmpreg = (__HANDLE__)->Instance->SR1;       \
    tmpreg = (__HANDLE__)->Instance->SR2;       \
    UNUSED(tmpreg);                             \
  } while(0)

/** @brief  清除 I2C STOPF 挂起标志位。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @retval 无
  */
/* 清除 STOPF 标志位的宏定义 */
/* 注意：清除 STOPF 标志位需要特定的软件时序：先读 SR1，然后写 CR1 寄存器。
   这里通过 SET_BIT 重置 CR1 的 PE 位来完成清除操作。 */
#define __HAL_I2C_CLEAR_STOPFLAG(__HANDLE__)           \
  do{                                                  \
    __IO uint32_t tmpreg = 0x00U;                      \
    tmpreg = (__HANDLE__)->Instance->SR1;              \
    SET_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE);  \
    UNUSED(tmpreg);                                    \
  } while(0)

/** @brief  使能指定的 I2C 外设。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @retval 无
  */
/* 使能 I2C 外设：置位 CR1 寄存器的 PE 位 */
#define __HAL_I2C_ENABLE(__HANDLE__)                  SET_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE)

/** @brief  禁用指定的 I2C 外设。
  * @param  __HANDLE__ 指定 I2C 句柄。
  * @retval 无
  */
/* 禁用 I2C 外设：清除 CR1 寄存器的 PE 位 */
#define __HAL_I2C_DISABLE(__HANDLE__)                 CLEAR_BIT((__HANDLE__)->Instance->CR1, I2C_CR1_PE)

/**
  * @}
  */

/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup I2C_Exported_Functions
  * @{
  */

/** @addtogroup I2C_Exported_Functions_Group1 初始化和反初始化函数
  * @{
  */
/* 初始化和反初始化函数 ******************************************************/
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);  // 初始化 I2C 外设，配置参数
HAL_StatusTypeDef HAL_I2C_DeInit(I2C_HandleTypeDef *hi2c); // 反初始化 I2C 外设，恢复默认状态
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);           // MSP 初始化回调函数，用于配置 GPIO、时钟、中断等底层硬件
void HAL_I2C_MspDeInit(I2C_HandleTypeDef *hi2c);         // MSP 反初始化回调函数，用于释放底层硬件资源

/* 回调函数注册/注销函数  ***********************************/
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
HAL_StatusTypeDef HAL_I2C_RegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID, pI2C_CallbackTypeDef pCallback); // 注册用户自定义回调函数
HAL_StatusTypeDef HAL_I2C_UnRegisterCallback(I2C_HandleTypeDef *hi2c, HAL_I2C_CallbackIDTypeDef CallbackID); // 注销回调函数，恢复默认

HAL_StatusTypeDef HAL_I2C_RegisterAddrCallback(I2C_HandleTypeDef *hi2c, pI2C_AddrCallbackTypeDef pCallback); // 注册地址匹配回调函数
HAL_StatusTypeDef HAL_I2C_UnRegisterAddrCallback(I2C_HandleTypeDef *hi2c); // 注销地址匹配回调函数
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group2 输入输出操作函数
  * @{
  */
/* IO 操作函数  ****************************************************/
/******* 阻塞模式：轮询方式 */
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout); // 主机发送数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);  // 主机接收数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Slave_Transmit(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout); // 从机发送数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Slave_Receive(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t Timeout);  // 从机接收数据（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout); // 写入指定设备的指定内存地址（阻塞模式）
HAL_StatusTypeDef HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);  // 读取指定设备的指定内存地址（阻塞模式）
HAL_StatusTypeDef HAL_I2C_IsDeviceReady(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint32_t Trials, uint32_t Timeout); // 检测设备是否就绪（阻塞模式）

/******* 非阻塞模式：中断方式 */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size); // 主机发送数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Master_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);  // 主机接收数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size); // 从机发送数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);  // 从机接收数据（中断模式）
HAL_StatusTypeDef HAL_I2C_Mem_Write_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size); // 写入内存地址（中断模式）
HAL_StatusTypeDef HAL_I2C_Mem_Read_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);  // 读取内存地址（中断模式）

HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 主机顺序发送（中断模式）
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 主机顺序接收（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 从机顺序发送（中断模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_IT(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 从机顺序接收（中断模式）
HAL_StatusTypeDef HAL_I2C_EnableListen_IT(I2C_HandleTypeDef *hi2c); // 使能监听模式（中断模式），用于从机地址匹配监听
HAL_StatusTypeDef HAL_I2C_DisableListen_IT(I2C_HandleTypeDef *hi2c); // 禁用监听模式
HAL_StatusTypeDef HAL_I2C_Master_Abort_IT(I2C_HandleTypeDef *hi2c, uint16_t DevAddress); // 主机中止传输（中断模式）

/******* 非阻塞模式：DMA 方式 */
HAL_StatusTypeDef HAL_I2C_Master_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size); // 主机发送数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Master_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size);  // 主机接收数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size); // 从机发送数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size);  // 从机接收数据（DMA模式）
HAL_StatusTypeDef HAL_I2C_Mem_Write_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size); // 写入内存地址（DMA模式）
HAL_StatusTypeDef HAL_I2C_Mem_Read_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size);  // 读取内存地址（DMA模式）

HAL_StatusTypeDef HAL_I2C_Master_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 主机顺序发送（DMA模式）
HAL_StatusTypeDef HAL_I2C_Master_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 主机顺序接收（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Transmit_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions); // 从机顺序发送（DMA模式）
HAL_StatusTypeDef HAL_I2C_Slave_Seq_Receive_DMA(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint16_t Size, uint32_t XferOptions);  // 从机顺序接收（DMA模式）
/**
  * @}
  */

/** @addtogroup I2C_IRQ_Handler_and_Callbacks IRQ 处理程序和回调函数
 * @{
 */
/******* I2C IRQHandler 和回调函数，用于非阻塞模式 (中断和 DMA) */
void HAL_I2C_EV_IRQHandler(I2C_HandleTypeDef *hi2c); // I2C 事件中断处理函数
void HAL_I2C_ER_IRQHandler(I2C_HandleTypeDef *hi2c); // I2C 错误中断处理函数
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c); // 主机发送完成回调函数
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c); // 主机接收完成回调函数
void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c);  // 从机发送完成回调函数
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c);  // 从机接收完成回调函数
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode); // 地址匹配回调函数
void HAL_I2C_ListenCpltCallback(I2C_HandleTypeDef *hi2c); // 监听完成回调函数
void HAL_I2C_MemTxCpltCallback(I2C_HandleTypeDef *hi2c); // 内存写入完成回调函数
void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c); // 内存读取完成回调函数
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c); // 错误回调函数
void HAL_I2C_AbortCpltCallback(I2C_HandleTypeDef *hi2c); // 中止传输完成回调函数
/**
  * @}
  */

/** @addtogroup I2C_Exported_Functions_Group3 外设状态、模式和错误函数
  * @{
  */
/* 外设状态、模式和错误函数  *********************************/
HAL_I2C_StateTypeDef HAL_I2C_GetState(I2C_HandleTypeDef *hi2c); // 获取 I2C 当前状态（如就绪、忙、错误等）
HAL_I2C_ModeTypeDef HAL_I2C_GetMode(I2C_HandleTypeDef *hi2c);   // 获取 I2C 当前模式（主机模式、从机模式）
uint32_t HAL_I2C_GetError(I2C_HandleTypeDef *hi2c); // 获取 I2C 错误代码

/**
  * @}
  */

/**
  * @}
  */
/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup I2C_Private_Constants I2C 私有常量
  * @{
  */
#define I2C_FLAG_MASK                    0x0000FFFFU  // I2C 标志位掩码，用于提取有效的标志位
#define I2C_MIN_PCLK_FREQ_STANDARD       2000000U     /*!< 标准模式下的最小 PCLK 频率：2 MHz */
#define I2C_MIN_PCLK_FREQ_FAST           4000000U     /*!< 快速模式下的最小 PCLK 频率：4 MHz */
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup I2C_Private_Macros I2C 私有宏
  * @{
  */

/* 检查 PCLK 时钟频率是否满足 I2C 速度要求 */
#define I2C_MIN_PCLK_FREQ(__PCLK__, __SPEED__)             (((__SPEED__) <= 100000U) ? ((__PCLK__) < I2C_MIN_PCLK_FREQ_STANDARD) : ((__PCLK__) < I2C_MIN_PCLK_FREQ_FAST))

/* 计算时钟控制寄存器 (CCR) 的值 */
#define I2C_CCR_CALCULATION(__PCLK__, __SPEED__, __COEFF__)     (((((__PCLK__) - 1U)/((__SPEED__) * (__COEFF__))) + 1U) & I2C_CCR_CCR)

/* 计算频率范围，单位 MHz */
#define I2C_FREQRANGE(__PCLK__)                            ((__PCLK__)/1000000U)

/* 计算上升时间 */
#define I2C_RISE_TIME(__FREQRANGE__, __SPEED__)            (((__SPEED__) <= 100000U) ? ((__FREQRANGE__) + 1U) : ((((__FREQRANGE__) * 300U) / 1000U) + 1U))

/* 计算标准模式下的 CCR 值 */
#define I2C_SPEED_STANDARD(__PCLK__, __SPEED__)            ((I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 2U) < 4U)? 4U:I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 2U))

/* 计算快速模式下的 CCR 值 */
#define I2C_SPEED_FAST(__PCLK__, __SPEED__, __DUTYCYCLE__) (((__DUTYCYCLE__) == I2C_DUTYCYCLE_2)? I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 3U) : (I2C_CCR_CALCULATION((__PCLK__), (__SPEED__), 25U) | I2C_DUTYCYCLE_16_9))

/* 根据速度模式自动选择计算标准模式或快速模式的 CCR 值 */
#define I2C_SPEED(__PCLK__, __SPEED__, __DUTYCYCLE__)      (((__SPEED__) <= 100000U)? (I2C_SPEED_STANDARD((__PCLK__), (__SPEED__))) : \
                                                                  ((I2C_SPEED_FAST((__PCLK__), (__SPEED__), (__DUTYCYCLE__)) & I2C_CCR_CCR) == 0U)? 1U : \
                                                                  ((I2C_SPEED_FAST((__PCLK__), (__SPEED__), (__DUTYCYCLE__))) | I2C_CCR_FS))

/* 将 7 位地址转换为写地址（最低位为 0） */
#define I2C_7BIT_ADD_WRITE(__ADDRESS__)                    ((uint8_t)((__ADDRESS__) & (uint8_t)(~I2C_OAR1_ADD0)))

/* 将 7 位地址转换为读地址（最低位为 1） */
#define I2C_7BIT_ADD_READ(__ADDRESS__)                     ((uint8_t)((__ADDRESS__) | I2C_OAR1_ADD0))

/* 获取 10 位地址的低位 */
#define I2C_10BIT_ADDRESS(__ADDRESS__)                     ((uint8_t)((uint16_t)((__ADDRESS__) & (uint16_t)0x00FF)))

/* 获取 10 位地址发送时的头字节（写方向） */
#define I2C_10BIT_HEADER_WRITE(__ADDRESS__)                ((uint8_t)((uint16_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0x0300)) >> 7) | (uint16_t)0x00F0)))

/* 获取 10 位地址发送时的头字节（读方向） */
#define I2C_10BIT_HEADER_READ(__ADDRESS__)                 ((uint8_t)((uint16_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0x0300)) >> 7) | (uint16_t)(0x00F1))))

/* 获取内存地址的高 8 位 */
#define I2C_MEM_ADD_MSB(__ADDRESS__)                       ((uint8_t)((uint16_t)(((uint16_t)((__ADDRESS__) & (uint16_t)0xFF00)) >> 8)))

/* 获取内存地址的低 8 位 */
#define I2C_MEM_ADD_LSB(__ADDRESS__)                       ((uint8_t)((uint16_t)((__ADDRESS__) & (uint16_t)0x00FF)))

/** @defgroup I2C_IS_RTC_Definitions I2C 私有宏用于检查输入参数
  * @{
  */
/* 检查占空比设置是否有效 */
#define IS_I2C_DUTY_CYCLE(CYCLE) (((CYCLE) == I2C_DUTYCYCLE_2) || \
                                  ((CYCLE) == I2C_DUTYCYCLE_16_9))

/* 检查寻址模式是否有效（7位或10位） */
#define IS_I2C_ADDRESSING_MODE(ADDRESS) (((ADDRESS) == I2C_ADDRESSINGMODE_7BIT) || \
                                         ((ADDRESS) == I2C_ADDRESSINGMODE_10BIT))

/* 检查双地址模式是否有效 */
#define IS_I2C_DUAL_ADDRESS(ADDRESS) (((ADDRESS) == I2C_DUALADDRESS_DISABLE) || \
                                      ((ADDRESS) == I2C_DUALADDRESS_ENABLE))

/* 检查广播呼叫是否有效 */
#define IS_I2C_GENERAL_CALL(CALL) (((CALL) == I2C_GENERALCALL_DISABLE) || \
                                   ((CALL) == I2C_GENERALCALL_ENABLE))

/* 检查时钟拉伸是否有效 */
#define IS_I2C_NO_STRETCH(STRETCH) (((STRETCH) == I2C_NOSTRETCH_DISABLE) || \
                                    ((STRETCH) == I2C_NOSTRETCH_ENABLE))

/* 检查内存地址大小是否有效（8位或16位） */
#define IS_I2C_MEMADD_SIZE(SIZE) (((SIZE) == I2C_MEMADD_SIZE_8BIT) || \
                                  ((SIZE) == I2C_MEMADD_SIZE_16BIT))

/* 检查时钟速度是否在有效范围内 (0, 400k] */
#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) > 0U) && ((SPEED) <= 400000U))

/* 检查自身地址 1 是否有效 */
#define IS_I2C_OWN_ADDRESS1(ADDRESS1) (((ADDRESS1) & 0xFFFFFC00U) == 0U)

/* 检查自身地址 2 是否有效 */
#define IS_I2C_OWN_ADDRESS2(ADDRESS2) (((ADDRESS2) & 0xFFFFFF01U) == 0U)

/* 检查传输选项请求是否有效 */
#define IS_I2C_TRANSFER_OPTIONS_REQUEST(REQUEST)      (((REQUEST) == I2C_FIRST_FRAME)              || \
                                                       ((REQUEST) == I2C_FIRST_AND_NEXT_FRAME)     || \
                                                       ((REQUEST) == I2C_NEXT_FRAME)               || \
                                                       ((REQUEST) == I2C_FIRST_AND_LAST_FRAME)     || \
                                                       ((REQUEST) == I2C_LAST_FRAME)               || \
                                                       ((REQUEST) == I2C_LAST_FRAME_NO_STOP)       || \
                                                       IS_I2C_TRANSFER_OTHER_OPTIONS_REQUEST(REQUEST))

/* 检查其他传输选项请求是否有效 */
#define IS_I2C_TRANSFER_OTHER_OPTIONS_REQUEST(REQUEST) (((REQUEST) == I2C_OTHER_FRAME)     || \
                                                        ((REQUEST) == I2C_OTHER_AND_LAST_FRAME))

/* 检查标志位状态的内部宏 */
#define I2C_CHECK_FLAG(__ISR__, __FLAG__)         ((((__ISR__) & ((__FLAG__) & I2C_FLAG_MASK)) == ((__FLAG__) & I2C_FLAG_MASK)) ? SET : RESET)

/* 检查中断源是否使能的内部宏 */
#define I2C_CHECK_IT_SOURCE(__CR1__, __IT__)      ((((__CR1__) & (__IT__)) == (__IT__)) ? SET : RESET)
/**
  * @}
  */

/**
  * @}
  */

/* 私有函数 ---------------------------------------------------------*/
/** @defgroup I2C_Private_Functions I2C 私有函数
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
