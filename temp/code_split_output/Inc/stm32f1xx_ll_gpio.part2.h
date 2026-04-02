/**
  * @brief  检查USART1是否已被重映射
  * @rmtoll MAPR         USART1_REMAP         LL_GPIO_AF_IsEnabledRemap_USART1
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_USART1(void)
{
  // 读取AFIO_MAPR寄存器中的USART1_REMAP位，判断是否使能了重映射
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_USART1_REMAP) == (AFIO_MAPR_USART1_REMAP));
}

/**
  * @brief 使能USART2的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART2_REMAP           LL_GPIO_AF_EnableRemap_USART2
  * @note  使能: 重映射     (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART2(void)
{
  // 设置AFIO_MAPR寄存器中的USART2_REMAP位，将USART2引脚映射到PD端口
  // 同时保留SWJ_CFG配置（调试接口配置），防止修改调试引脚
  SET_BIT(AFIO->MAPR, AFIO_MAPR_USART2_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用USART2的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART2_REMAP           LL_GPIO_AF_DisableRemap_USART2
  * @note  禁用: 无重映射 (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART2(void)
{
  // 清除AFIO_MAPR寄存器中的USART2_REMAP位，恢复为默认引脚PA端口
  // 使用MODIFY_REG宏确保SWJ_CFG配置不受影响
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART2_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查USART2是否已被重映射
  * @rmtoll MAPR         USART2_REMAP         LL_GPIO_AF_IsEnabledRemap_USART2
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_USART2(void)
{
  // 读取AFIO_MAPR寄存器中的USART2_REMAP位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_USART2_REMAP) == (AFIO_MAPR_USART2_REMAP));
}

#if defined (AFIO_MAPR_USART3_REMAP)
/**
  * @brief 使能USART3的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_EnableRemap_USART3
  * @note  使能: 完全重映射     (TX/PD8,  RX/PD9,  CK/PD10, CTS/PD11, RTS/PD12)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART3(void)
{
  // 配置USART3为完全重映射模式，引脚映射到PD端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能USART3的复用功能部分重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_RemapPartial_USART3
  * @note  部分: 部分重映射 (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_USART3(void)
{
  // 配置USART3为部分重映射模式
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用USART3的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_DisableRemap_USART3
  * @note  禁用: 无重映射      (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART3(void)
{
  // 配置USART3为无重映射模式，即默认引脚PB端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}
#endif

/**
  * @brief 使能TIM1的复用功能重映射 (通道1到4, 1N到3N, 外部触发ETR和刹车输入BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_EnableRemap_TIM1
  * @note  使能: 完全重映射     (ETR/PE7,  CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8,  CH2N/PE10, CH3N/PE12)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM1(void)
{
  // 配置TIM1为完全重映射，引脚映射到PE端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM1的复用功能部分重映射 (通道1到4, 1N到3N, 外部触发ETR和刹车输入BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_RemapPartial_TIM1
  * @note  部分: 部分重映射 (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PA6,  CH1N/PA7,  CH2N/PB0,  CH3N/PB1)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_TIM1(void)
{
  // 配置TIM1为部分重映射
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用TIM1的复用功能重映射 (通道1到4, 1N到3N, 外部触发ETR和刹车输入BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_DisableRemap_TIM1
  * @note  禁用: 无重映射      (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM1(void)
{
  // 配置TIM1为无重映射，恢复默认引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM2的复用功能重映射 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_EnableRemap_TIM2
  * @note  使能: 完全重映射       (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM2(void)
{
  // 配置TIM2为完全重映射
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM2的复用功能部分重映射2 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_RemapPartial2_TIM2
  * @note  部分_2: 部分重映射 (CH1/ETR/PA0,  CH2/PA1, CH3/PB10, CH4/PB11)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial2_TIM2(void)
{
  // 配置TIM2为部分重映射模式2
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM2的复用功能部分重映射1 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_RemapPartial1_TIM2
  * @note  部分_1: 部分重映射 (CH1/ETR/PA15, CH2/PB3, CH3/PA2,  CH4/PA3)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial1_TIM2(void)
{
  // 配置TIM2为部分重映射模式1
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用TIM2的复用功能重映射 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_DisableRemap_TIM2
  * @note  禁用: 无重映射        (CH1/ETR/PA0,  CH2/PA1, CH3/PA2,  CH4/PA3)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM2(void)
{
  // 配置TIM2为无重映射，恢复默认引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM3的复用功能重映射 (通道1到4)
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_EnableRemap_TIM3
  * @note  使能: 完全重映射     (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
  * @note  TIM3_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM3(void)
{
  // 配置TIM3为完全重映射，引脚映射到PC端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM3的复用功能部分重映射 (通道1到4)
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_RemapPartial_TIM3
  * @note  部分: 部分重映射 (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_TIM3(void)
{
  // 配置TIM3为部分重映射
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用TIM3的复用功能重映射 (通道1到4)
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_DisableRemap_TIM3
  * @note  禁用: 无重映射      (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM3(void)
{
  // 配置TIM3为无重映射，恢复默认引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

#if defined(AFIO_MAPR_TIM4_REMAP)
/**
  * @brief 使能TIM4的复用功能重映射 (通道1到4)。
  * @rmtoll MAPR          TIM4_REMAP           LL_GPIO_AF_EnableRemap_TIM4
  * @note  使能: 完全重映射 (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
  * @note  TIM4_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM4(void)
{
  // 设置TIM4重映射位，将TIM4引脚映射到PD端口
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM4_REMAP | AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief 禁用TIM4的复用功能重映射 (通道1到4)。
  * @rmtoll MAPR          TIM4_REMAP           LL_GPIO_AF_DisableRemap_TIM4
  * @note  禁用: 无重映射  (TIM4_CH1/PB6,  TIM4_CH2/PB7,  TIM4_CH3/PB8,  TIM4_CH4/PB9)
  * @note  TIM4_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM4(void)
{
  // 清除TIM4重映射位，恢复默认PB端口引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM4_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查TIM4是否已被重映射
  * @rmtoll MAPR         TIM4_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM4
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM4(void)
{
  // 读取TIM4重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_TIM4_REMAP) == (AFIO_MAPR_TIM4_REMAP));
}
#endif

#if defined(AFIO_MAPR_CAN_REMAP_REMAP1)

/**
  * @brief 使能或禁用CAN复用功能 CAN_RX 和 CAN_TX 的重映射 (针对单CAN接口设备)。
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial1_CAN1
  * @note  情况 1: CAN_RX 映射到 PA11, CAN_TX 映射到 PA12
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial1_CAN1(void)
{
  // 配置CAN重映射为模式1 (PA11/PA12)
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP1 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能或禁用CAN复用功能 CAN_RX 和 CAN_TX 的重映射 (针对单CAN接口设备)。
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial2_CAN1
  * @note  情况 2: CAN_RX 映射到 PB8,  CAN_TX 映射到 PB9 (36引脚封装不可用)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial2_CAN1(void)
{
  // 配置CAN重映射为模式2 (PB8/PB9)
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP2 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能或禁用CAN复用功能 CAN_RX 和 CAN_TX 的重映射 (针对单CAN接口设备)。
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial3_CAN1
  * @note  情况 3: CAN_RX 映射到 PD0,  CAN_TX 映射到 PD1
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial3_CAN1(void)
{
  // 配置CAN重映射为模式3 (PD0/PD1)
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP3 | AFIO_MAPR_SWJ_CFG));
}
#endif

/**
  * @brief 使能PD0和PD1的重映射。当不使用HSE振荡器时
  *        (应用程序运行在内部8MHz RC时钟)，PD0和PD1可以映射到OSC_IN和
  *        OSC_OUT。这仅在36、48和64引脚封装上可用 (PD0和PD1在
  *        100引脚和144引脚封装上可用，无需重映射)。
  * @rmtoll MAPR          PD01_REMAP           LL_GPIO_AF_EnableRemap_PD01
  * @note  使能: PD0 重映射到 OSC_IN, PD1 重映射到 OSC_OUT。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_PD01(void)
{
  // 设置PD01重映射位，将PD0/PD1映射到晶振引脚，节省IO资源
  SET_BIT(AFIO->MAPR, AFIO_MAPR_PD01_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用PD0和PD1的重映射。当不使用HSE振荡器时
  *        (应用程序运行在内部8MHz RC时钟)，PD0和PD1可以映射到OSC_IN和
  *        OSC_OUT。这仅在36、48和64引脚封装上可用 (PD0和PD1在
  *        100引脚和144引脚封装上可用，无需重映射)。
  * @rmtoll MAPR          PD01_REMAP           LL_GPIO_AF_DisableRemap_PD01
  * @note  禁用: PD0和PD1无重映射
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_PD01(void)
{
  // 清除PD01重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_PD01_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查PD01是否已被重映射
  * @rmtoll MAPR         PD01_REMAP         LL_GPIO_AF_IsEnabledRemap_PD01
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_PD01(void)
{
  // 读取PD01重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_PD01_REMAP) == (AFIO_MAPR_PD01_REMAP));
}

#if defined(AFIO_MAPR_TIM5CH4_IREMAP)
/**
  * @brief 使能TIM5通道4的重映射。
  * @rmtoll MAPR          TIM5CH4_IREMAP           LL_GPIO_AF_EnableRemap_TIM5CH4
  * @note  使能: LSI内部时钟连接到TIM5_CH4输入，用于校准目的。
  * @note  此功能仅在高密度Value Line设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM5CH4(void)
{
  // 设置TIM5通道4内部重映射位，将LSI内部时钟连接到TIM5_CH4
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM5CH4_IREMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用TIM5通道4的重映射。
  * @rmtoll MAPR          TIM5CH4_IREMAP           LL_GPIO_AF_DisableRemap_TIM5CH4
  * @note  禁用: TIM5_CH4 连接到 PA3
  * @note  此功能仅在高密度Value Line设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM5CH4(void)
{
  // 清除TIM5通道4内部重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM5CH4_IREMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查TIM5CH4是否已被重映射
  * @rmtoll MAPR         TIM5CH4_IREMAP         LL_GPIO_AF_IsEnabledRemap_TIM5CH4
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM5CH4(void)
{
  // 读取TIM5通道4内部重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_TIM5CH4_IREMAP) == (AFIO_MAPR_TIM5CH4_IREMAP));
}
#endif

#if defined(AFIO_MAPR_ETH_REMAP)
/**
  * @brief 使能以太网MAC与PHY连接的重映射。
  * @rmtoll MAPR          ETH_REMAP           LL_GPIO_AF_EnableRemap_ETH
  * @note  使能: 重映射     (RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ETH(void)
{
  // 设置以太网重映射位，将以太网引脚映射到PD端口
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ETH_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用以太网MAC与PHY连接的重映射。
  * @rmtoll MAPR          ETH_REMAP           LL_GPIO_AF_DisableRemap_ETH
  * @note  禁用: 无重映射 (RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5,  RXD2/PB0,  RXD3/PB1)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ETH(void)
{
  // 清除以太网重映射位，恢复默认引脚配置
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ETH_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ETH是否已被重映射
  * @rmtoll MAPR         ETH_REMAP         LL_GPIO_AF_IsEnabledRemap_ETH
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ETH(void)
{
  // 读取以太网重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ETH_REMAP) == (AFIO_MAPR_ETH_REMAP));
}
#endif

#if defined(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief 使能CAN2复用功能 CAN2_RX 和 CAN2_TX 的重映射。
  * @rmtoll MAPR          CAN2_REMAP           LL_GPIO_AF_EnableRemap_CAN2
  * @note  使能: 重映射     (CAN2_RX/PB5,  CAN2_TX/PB6)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_CAN2(void)
{
  // 设置CAN2重映射位
  SET_BIT(AFIO->MAPR, AFIO_MAPR_CAN2_REMAP | AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief 禁用CAN2复用功能 CAN2_RX 和 CAN2_TX 的重映射。
  * @rmtoll MAPR          CAN2_REMAP           LL_GPIO_AF_DisableRemap_CAN2
  * @note  禁用: 无重映射 (CAN2_RX/PB12, CAN2_TX/PB13)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_CAN2(void)
{
  // 清除CAN2重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN2_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查CAN2是否已被重映射
  * @rmtoll MAPR         CAN2_REMAP         LL_GPIO_AF_IsEnabledRemap_CAN2
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_CAN2(void)
{
  // 读取CAN2重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_CAN2_REMAP) == (AFIO_MAPR_CAN2_REMAP));
}
#endif

#if defined(AFIO_MAPR_MII_RMII_SEL)
/**
  * @brief 配置以太网MAC内部以用于外部MII或RMII PHY。
  * @rmtoll MAPR          MII_RMII_SEL           LL_GPIO_AF_Select_ETH_RMII
  * @note  ETH_RMII: 配置以太网MAC以连接RMII PHY
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Select_ETH_RMII(void)
{
  // 设置MII_RMII_SEL位，选择RMII模式
  SET_BIT(AFIO->MAPR, AFIO_MAPR_MII_RMII_SEL | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 配置以太网MAC内部以用于外部MII或RMII PHY。
  * @rmtoll MAPR          MII_RMII_SEL           LL_GPIO_AF_Select_ETH_MII
  * @note  ETH_MII: 配置以太网MAC以连接MII PHY
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Select_ETH_MII(void)
{
  // 清除MII_RMII_SEL位，选择MII模式
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_MII_RMII_SEL | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR_ADC1_ETRGINJ_REMAP)
/**
  * @brief 使能ADC1_ETRGINJ的重映射 (ADC 1 外部触发注入转换)。
  * @rmtoll MAPR          ADC1_ETRGINJ_REMAP           LL_GPIO_AF_EnableRemap_ADC1_ETRGINJ
  * @note  使能: ADC1 外部事件注入转换连接到 TIM8 通道4。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC1_ETRGINJ(void)
{
  // 设置ADC1外部触发注入转换重映射位
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用ADC1_ETRGINJ的重映射 (ADC 1 外部触发注入转换)。
  * @rmtoll MAPR          ADC1_ETRGINJ_REMAP           LL_GPIO_AF_DisableRemap_ADC1_ETRGINJ
  * @note  禁用: ADC1 外部触发注入转换连接到 EXTI15
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC1_ETRGINJ(void)
{
  // 清除ADC1外部触发注入转换重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC1_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC1_ETRGINJ是否已被重映射
  * @rmtoll MAPR         ADC1_ETRGINJ_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGINJ
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGINJ(void)
{
  // 读取ADC1外部触发注入转换重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGINJ_REMAP) == (AFIO_MAPR_ADC1_ETRGINJ_REMAP));
}
#endif

#if defined(AFIO_MAPR_ADC1_ETRGREG_REMAP)
/**
  * @brief 使能ADC1_ETRGREG的重映射 (ADC 1 外部触发常规转换)。
  * @rmtoll MAPR          ADC1_ETRGREG_REMAP           LL_GPIO_AF_EnableRemap_ADC1_ETRGREG
  * @note  使能: ADC1 外部事件常规转换连接到 TIM8 TRG0。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC1_ETRGREG(void)
{
  // 设置ADC1外部触发常规转换重映射位
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用ADC1_ETRGREG的重映射 (ADC 1 外部触发常规转换)。
  * @rmtoll MAPR          ADC1_ETRGREG_REMAP           LL_GPIO_AF_DisableRemap_ADC1_ETRGREG
  * @note  禁用: ADC1 外部触发常规转换连接到 EXTI11
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC1_ETRGREG(void)
{
   // 清除ADC1外部触发常规转换重映射位
   MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC1_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC1_ETRGREG是否已被重映射
  * @rmtoll MAPR         ADC1_ETRGREG_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGREG
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGREG(void)
{
  // 读取ADC1外部触发常规转换重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGREG_REMAP) == (AFIO_MAPR_ADC1_ETRGREG_REMAP));
}
#endif

#if defined(AFIO_MAPR_ADC2_ETRGINJ_REMAP)
