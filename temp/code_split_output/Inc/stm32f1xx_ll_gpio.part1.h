/**
  * @brief  获取指定端口上指定引脚的速度配置。
  * @note   I/O速度可以是低速、中速、快速或高速。
  * @note   警告: 参数只能传递一个引脚。
  * @note   请参考数据手册中关于每种速度的频率规格以及电源和负载条件。
  * @rmtoll CRL      MODEy       LL_GPIO_GetPinSpeed
  * @rmtoll CRH      MODEy       LL_GPIO_GetPinSpeed
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref LL_GPIO_SPEED_FREQ_HIGH
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinSpeed(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 
     计算寄存器地址：根据引脚号判断是配置低8位寄存器(CRL)还是高8位寄存器(CRH)。
     Pin >> 24 用于获取引脚所在的寄存器偏移量（STM32F1系列设计中，Pin的高8位存储了偏移信息）。
  */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  
  /* 
     读取寄存器值，提取对应位的配置。
     1. POSITION_VAL(Pin) 获取引脚号(0-15)。
     2. 引脚配置每4位一组，所以偏移量为 引脚号 * 4。
     3. 读取对应位并右移到最低位，返回速度配置值。
  */
  return (READ_BIT(*pReg, (GPIO_CRL_MODE0 << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));
}

/**
  * @brief  配置指定端口上多个引脚的输出类型。
  * @note   输出类型必须在GPIO引脚处于输出模式或复用模式时设置。可能的类型是推挽或开漏。
  * @rmtoll CRL       MODEy           LL_GPIO_SetPinOutputType
  * @rmtoll CRH       MODEy           LL_GPIO_SetPinOutputType
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @param  OutputType 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_OUTPUT_PUSHPULL (推挽输出)
  *         @arg @ref LL_GPIO_OUTPUT_OPENDRAIN (开漏输出)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t OutputType)
{
  /* 计算配置寄存器地址(CRL或CRH) */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  
  /* 
     修改寄存器配置。
     使用MODIFY_REG宏：先清除对应的CNF配置位，然后设置新的OutputType配置位。
     注意：在STM32F1中，输出类型配置在CNF位中。
  */
  MODIFY_REG(*pReg, (GPIO_CRL_CNF0_0 << (POSITION_VAL(Pin) * 4U)),
             (OutputType << (POSITION_VAL(Pin) * 4U)));
}

/**
  * @brief  获取指定端口上多个引脚的输出类型。
  * @note   输出类型必须在GPIO引脚处于输出模式或复用模式时设置。可能的类型是推挽或开漏。
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll CRL       MODEy       LL_GPIO_GetPinOutputType
  * @rmtoll CRH       MODEy       LL_GPIO_GetPinOutputType
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref LL_GPIO_OUTPUT_OPENDRAIN
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 计算配置寄存器地址(CRL或CRH) */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  
  /* 读取并返回CNF配置位，获取输出类型 */
  return (READ_BIT(*pReg, (GPIO_CRL_CNF0_0 << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));

}

/**
  * @brief  配置指定端口上指定引脚的上拉或下拉。
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll ODR        ODR         LL_GPIO_SetPinPull
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Pull 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PULL_DOWN
  *         @arg @ref LL_GPIO_PULL_UP
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Pull)
{
  /* 
     在STM32F1系列中，上拉/下拉是通过ODR(输出数据寄存器)配合模式配置实现的。
     这里通过修改ODR寄存器对应的位来设置上拉(Pull=1)或下拉(Pull=0)。
     Pin >> GPIO_PIN_MASK_POS 用于将Pin宏转换为位偏移。
  */
  MODIFY_REG(GPIOx->ODR, (Pin >> GPIO_PIN_MASK_POS), Pull << (POSITION_VAL(Pin >> GPIO_PIN_MASK_POS)));
}

/**
  * @brief  获取指定端口上指定引脚的上拉或下拉配置
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll ODR        ODR         LL_GPIO_GetPinPull
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_PULL_DOWN
  *         @arg @ref LL_GPIO_PULL_UP
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 读取ODR寄存器中对应位的值，判断是上拉还是下拉 */
  return (READ_BIT(GPIOx->ODR, (GPIO_ODR_ODR0 << (POSITION_VAL(Pin >> GPIO_PIN_MASK_POS)))) >> (POSITION_VAL(Pin >> GPIO_PIN_MASK_POS)));
}

/**
  * @brief  锁定指定端口上多个引脚的配置。
  * @note   当锁定序列应用于端口位时，该端口位的值在下次复位前不能再被修改。
  * @note   每个锁定位冻结特定的配置寄存器(控制和复用功能寄存器)。
  * @rmtoll LCKR         LCKK          LL_GPIO_LockPin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  __IO uint32_t temp;
  
  /* 
     GPIO锁定序列：
     写入LCKK位和引脚位
     这是一个特定的硬件锁定序列，用于锁定引脚配置。
  */
  /* 第1步: 写入LCKK=1 + 需要锁定的引脚位 */
  WRITE_REG(GPIOx->LCKR, GPIO_LCKR_LCKK | ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
  
  /* 第2步: 写入LCKK=0 + 需要锁定的引脚位 */
  WRITE_REG(GPIOx->LCKR, ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
  
  /* 第3步: 写入LCKK=1 + 需要锁定的引脚位 */
  WRITE_REG(GPIOx->LCKR, GPIO_LCKR_LCKK | ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
  
  /* 第4步: 读取LCKR寄存器，完成锁定 */
  temp = READ_REG(GPIOx->LCKR);
  (void) temp; // 防止编译器警告，确保读取操作发生
}

/**
  * @brief  如果指定端口上传递的所有引脚都被锁定，则返回1，否则返回0。
  * @rmtoll LCKR         LCKy          LL_GPIO_IsPinLocked
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsPinLocked(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取LCKR寄存器，检查指定引脚的锁定状态位是否匹配 */
  return (READ_BIT(GPIOx->LCKR, ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU)) == ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
}

/**
  * @brief  如果指定端口上有任意一个引脚被锁定，则返回1，否则返回0。
  * @rmtoll LCKR         LCKK          LL_GPIO_IsAnyPinLocked
  * @param  GPIOx GPIO端口
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsAnyPinLocked(GPIO_TypeDef *GPIOx)
{
  /* 读取LCKR寄存器的LCKK位(锁定键)，判断是否处于锁定状态 */
  return (READ_BIT(GPIOx->LCKR, GPIO_LCKR_LCKK) == (GPIO_LCKR_LCKK));
}

/**
  * @}
  */

/** @defgroup GPIO_LL_EF_Data_Access 数据访问
  * @{
  */

/**
  * @brief  返回指定端口的完整输入数据寄存器值。
  * @rmtoll IDR          IDy           LL_GPIO_ReadInputPort
  * @param  GPIOx GPIO端口
  * @retval 端口的输入数据寄存器值
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadInputPort(GPIO_TypeDef *GPIOx)
{
  /* 直接读取IDR寄存器，获取整个端口(16个引脚)的输入电平状态 */
  return (READ_REG(GPIOx->IDR));
}

/**
  * @brief  判断指定端口上多个引脚的输入数据电平是高还是低。
  * @rmtoll IDR          IDy           LL_GPIO_IsInputPinSet
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsInputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取IDR寄存器，判断指定引脚是否为高电平。如果所有指定引脚都为高，则返回1 */
  return (READ_BIT(GPIOx->IDR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU) == ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
}

/**
  * @brief  写入端口的输出数据寄存器。
  * @rmtoll ODR          ODy           LL_GPIO_WriteOutputPort
  * @param  GPIOx GPIO端口
  * @param  PortValue 端口每个引脚的电平值
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_WriteOutputPort(GPIO_TypeDef *GPIOx, uint32_t PortValue)
{
  /* 直接写入ODR寄存器，设置整个端口的输出电平 */
  WRITE_REG(GPIOx->ODR, PortValue);
}

/**
  * @brief  返回指定端口的完整输出数据寄存器值。
  * @rmtoll ODR          ODy           LL_GPIO_ReadOutputPort
  * @param  GPIOx GPIO端口
  * @retval 端口的输出数据寄存器值
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadOutputPort(GPIO_TypeDef *GPIOx)
{
  /* 读取ODR寄存器，获取当前端口的输出配置 */
  return (uint32_t)(READ_REG(GPIOx->ODR));
}

/**
  * @brief  判断指定端口上多个引脚的输出数据电平是高还是低。
  * @rmtoll ODR          ODy           LL_GPIO_IsOutputPinSet
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsOutputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取ODR寄存器，判断指定引脚当前的输出状态是否为高电平 */
  return (READ_BIT(GPIOx->ODR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU) == ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
}

/**
  * @brief  将指定GPIO端口上的多个引脚设置为高电平。
  * @rmtoll BSRR         BSy           LL_GPIO_SetOutputPin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 
     写入BSRR寄存器的低16位。
     BSRR寄存器是原子操作寄存器，写1置位，写0无影响。
     这里将对应的引脚设置为高电平。
  */
  WRITE_REG(GPIOx->BSRR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU);
}

/**
  * @brief  将指定GPIO端口上的多个引脚设置为低电平。
  * @rmtoll BRR          BRy           LL_GPIO_ResetOutputPin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_ResetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 
     写入BRR寄存器。
     BRR寄存器用于复位引脚电平，写1清零(置低电平)，写0无影响。
  */
  WRITE_REG(GPIOx->BRR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU);
}

/**
  * @brief  翻转指定端口上多个引脚的电平值。
  * @rmtoll ODR          ODy           LL_GPIO_TogglePin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取当前ODR寄存器的值 */
  uint32_t odr = READ_REG(GPIOx->ODR);
  /* 计算有效的引脚掩码 */
  uint32_t pinmask = ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU);
  
  /* 
     利用BSRR寄存器实现原子翻转：
     - (odr & pinmask) << 16u: 获取当前为高电平的引脚，写入BSRR的高16位(复位)，使其变低。
     - (~odr & pinmask): 获取当前为低电平的引脚，写入BSRR的低16位(置位)，使其变高。
     这样可以在一条指令内完成多个引脚的电平翻转，避免读写修改过程中发生中断干扰。
  */
  WRITE_REG(GPIOx->BSRR, ((odr & pinmask) << 16u) | (~odr & pinmask));
}

/**
  * @}
  */

/** @defgroup GPIO_AF_REMAPPING 复用功能重映射
  * @brief 本节提供将复用功能重映射到其他端口/引脚的定义。
  * @{
  */

/**
  * @brief  启用SPI1复用功能NSS, SCK, MISO和MOSI的重映射。
  * @rmtoll MAPR          SPI1_REMAP           LL_GPIO_AF_EnableRemap_SPI1
  * @note   ENABLE: 重映射 (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SPI1(void)
{
  /* 设置AFIO_MAPR寄存器中的SPI1_REMAP位，开启重映射，同时保持SWJ_CFG配置 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SPI1_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用SPI1复用功能NSS, SCK, MISO和MOSI的重映射。
  * @rmtoll MAPR          SPI1_REMAP           LL_GPIO_AF_DisableRemap_SPI1
  * @note  DISABLE: 无重映射 (NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SPI1(void)
{
  /* 清除AFIO_MAPR寄存器中的SPI1_REMAP位，恢复默认引脚，同时保持SWJ_CFG配置 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_SPI1_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查SPI1是否已被重映射
  * @rmtoll MAPR         SPI1_REMAP         LL_GPIO_AF_IsEnabledRemap_SPI1
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_SPI1(void)
{
  /* 读取并检查SPI1_REMAP位是否置位 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_SPI1_REMAP) == (AFIO_MAPR_SPI1_REMAP));
}

/**
  * @brief 启用I2C1复用功能SCL和SDA的重映射。
  * @rmtoll MAPR          I2C1_REMAP           LL_GPIO_AF_EnableRemap_I2C1
  * @note  ENABLE: 重映射     (SCL/PB8, SDA/PB9)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_I2C1(void)
{
  /* 设置I2C1_REMAP位，将I2C1引脚映射到PB8/PB9 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_I2C1_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用I2C1复用功能SCL和SDA的重映射。
  * @rmtoll MAPR          I2C1_REMAP           LL_GPIO_AF_DisableRemap_I2C1
  * @note  DISABLE: 无重映射 (SCL/PB6, SDA/PB7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_I2C1(void)
{
  /* 清除I2C1_REMAP位，恢复默认引脚PB6/PB7 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_I2C1_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查I2C1是否已被重映射
  * @rmtoll MAPR         I2C1_REMAP         LL_GPIO_AF_IsEnabledRemap_I2C1
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_I2C1(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_I2C1_REMAP) == (AFIO_MAPR_I2C1_REMAP));
}

/**
  * @brief 启用USART1复用功能TX和RX的重映射。
  * @rmtoll MAPR          USART1_REMAP           LL_GPIO_AF_EnableRemap_USART1
  * @note  ENABLE: 重映射     (TX/PB6, RX/PB7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART1(void)
{
  /* 设置USART1_REMAP位，将USART1引脚映射到PB6/PB7 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_USART1_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用USART1复用功能TX和RX的重映射。
  * @rmtoll MAPR          USART1_REMAP           LL_GPIO_AF_DisableRemap_USART1
  * @note  DISABLE: 无重映射 (TX/PA9, RX/PA10)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART1(void)
{
  /* 清除USART1_REMAP位，恢复默认引脚PA9/PA10 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART1_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
