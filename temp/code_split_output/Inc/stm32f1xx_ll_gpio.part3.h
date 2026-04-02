/**
  * @brief  启用ADC2_ETRGREG的重映射（ADC2外部触发注入转换）。
  * @rmtoll MAPR          ADC2_ETRGINJ_REMAP           LL_GPIO_AF_EnableRemap_ADC2_ETRGINJ
  * @note  启用: ADC2外部事件注入转换连接到TIM8通道4。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC2_ETRGINJ(void)
{
  /* 设置AFIO_MAPR寄存器的ADC2_ETRGINJ_REMAP位，启用重映射，同时保持SWJ配置 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用ADC2_ETRGREG的重映射（ADC2外部触发注入转换）。
  * @rmtoll MAPR          ADC2_ETRGINJ_REMAP           LL_GPIO_AF_DisableRemap_ADC2_ETRGINJ
  * @note  禁用: ADC2外部触发注入转换连接到EXTI15
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC2_ETRGINJ(void)
{
  /* 清除ADC2_ETRGINJ_REMAP位以禁用重映射，保留SWJ配置 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC2_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC2_ETRGINJ是否已被重映射
  * @rmtoll MAPR         ADC2_ETRGINJ_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGINJ
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGINJ(void)
{
  /* 读取MAPR寄存器中的对应位，判断是否使能了重映射 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGINJ_REMAP) == (AFIO_MAPR_ADC2_ETRGINJ_REMAP));
}
#endif

#if defined (AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief  启用ADC2_ETRGREG的重映射（ADC2外部触发常规转换）。
  * @rmtoll MAPR          ADC2_ETRGREG_REMAP           LL_GPIO_AF_EnableRemap_ADC2_ETRGREG
  * @note  启用: ADC2外部事件常规转换连接到TIM8 TRG0。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC2_ETRGREG(void)
{
  /* 设置AFIO_MAPR寄存器的ADC2_ETRGREG_REMAP位，启用重映射 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用ADC2_ETRGREG的重映射（ADC2外部触发常规转换）。
  * @rmtoll MAPR          ADC2_ETRGREG_REMAP           LL_GPIO_AF_DisableRemap_ADC2_ETRGREG
  * @note  禁用: ADC2外部触发常规转换连接到EXTI11
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC2_ETRGREG(void)
{
  /* 清除ADC2_ETRGREG_REMAP位以禁用重映射 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC2_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC2_ETRGREG是否已被重映射
  * @rmtoll MAPR         ADC2_ETRGREG_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGREG
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGREG(void)
{
  /* 读取MAPR寄存器中的对应位，判断是否使能了重映射 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGREG_REMAP) == (AFIO_MAPR_ADC2_ETRGREG_REMAP));
}
#endif

/**
  * @brief  启用串行线JTAG配置
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_EnableRemap_SWJ
  * @note  启用: 全SWJ (JTAG-DP + SW-DP): 复位状态
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SWJ(void)
{
  /* 配置SWJ_CFG为复位状态，即全SWJ使能（JTAG-DP + SW-DP） */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_RESET);
}

/**
  * @brief  启用串行线JTAG配置（无NJTRST）
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_Remap_SWJ_NONJTRST
  * @note  NONJTRST: 全SWJ (JTAG-DP + SW-DP) 但没有NJTRST
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_SWJ_NONJTRST(void)
{
  /* 配置SWJ_CFG为无NJTRST模式，释放JTRST引脚作为普通IO使用 */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_NOJNTRST);
}

/**
  * @brief  启用串行线JTAG配置（无JTAG）
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_Remap_SWJ_NOJTAG
  * @note  NOJTAG: JTAG-DP禁用且SW-DP启用
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_SWJ_NOJTAG(void)
{
  /* 配置SWJ_CFG为禁用JTAG模式，仅保留SW-DP，释放JTAG引脚作为普通IO */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_JTAGDISABLE);
}

/**
  * @brief  禁用串行线JTAG配置
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_DisableRemap_SWJ
  * @note  禁用: JTAG-DP禁用且SW-DP禁用
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SWJ(void)
{
  /* 完全禁用JTAG和SWD接口，释放所有相关引脚作为普通IO */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_DISABLE);
}

#if defined(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief  启用SPI3复用功能重映射 (SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD)。
  * @rmtoll MAPR          SPI3_REMAP           LL_GPIO_AF_EnableRemap_SPI3
  * @note  启用: 重映射     (SPI3_NSS-I2S3_WS/PA4,  SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12)
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SPI3(void)
{
  /* 设置SPI3_REMAP位，将SPI3引脚映射到新的位置 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SPI3_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用SPI3复用功能重映射 (SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD)。
  * @rmtoll MAPR          SPI3_REMAP           LL_GPIO_AF_DisableRemap_SPI3
  * @note  禁用: 无重映射 (SPI3_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3,  SPI3_MISO/PB4,  SPI3_MOSI-I2S3_SD/PB5).
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SPI3(void)
{
  /* 清除SPI3_REMAP位，恢复默认引脚位置 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_SPI3_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查SPI3是否已被重映射
  * @rmtoll MAPR         SPI3_REMAP         LL_GPIO_AF_IsEnabledRemap_SPI3_REMAP
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_SPI3(void)
{
  /* 读取SPI3重映射状态 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_SPI3_REMAP) == (AFIO_MAPR_SPI3_REMAP));
}
#endif

#if defined(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief  控制TIM2_ITR1内部映射。
  * @rmtoll MAPR          TIM2ITR1_IREMAP           LL_GPIO_AF_Remap_TIM2ITR1_TO_USB
  * @note  TO_USB: 将USB OTG SOF (帧开始) 输出连接到TIM2_ITR1用于校准目的。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_TIM2ITR1_TO_USB(void)
{
  /* 设置TIM2ITR1_IREMAP位，将TIM2内部触发输入1连接到USB SOF信号 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM2ITR1_IREMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  控制TIM2_ITR1内部映射。
  * @rmtoll MAPR          TIM2ITR1_IREMAP           LL_GPIO_AF_Remap_TIM2ITR1_TO_ETH
  * @note  TO_ETH: 将TIM2_ITR1内部连接到以太网PTP输出用于校准目的。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_TIM2ITR1_TO_ETH(void)
{
  /* 清除TIM2ITR1_IREMAP位，将TIM2内部触发输入1连接到以太网PTP信号 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2ITR1_IREMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief  启用ADC2_ETRGREG的重映射（ADC 2外部触发常规转换）。
  * @rmtoll MAPR          PTP_PPS_REMAP           LL_GPIO_AF_EnableRemap_ETH_PTP_PPS
  * @note  启用: PTP_PPS输出在PB5引脚。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ETH_PTP_PPS(void)
{
  /* 设置PTP_PPS_REMAP位，将以太网PTP PPS信号映射到PB5引脚 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_PTP_PPS_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用ADC2_ETRGREG的重映射（ADC 2外部触发常规转换）。
  * @rmtoll MAPR          PTP_PPS_REMAP           LL_GPIO_AF_DisableRemap_ETH_PTP_PPS
  * @note  禁用: PTP_PPS不在PB5引脚输出。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ETH_PTP_PPS(void)
{
  /* 清除PTP_PPS_REMAP位，禁用PB5引脚的PPS输出功能 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_PTP_PPS_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief  启用TIM9_CH1和TIM9_CH2的重映射。
  * @rmtoll MAPR2          TIM9_REMAP           LL_GPIO_AF_EnableRemap_TIM9
  * @note  启用: 重映射     (TIM9_CH1在PE5 且 TIM9_CH2在PE6)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM9(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM9_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP);
}

/**
  * @brief  禁用TIM9_CH1和TIM9_CH2的重映射。
  * @rmtoll MAPR2          TIM9_REMAP           LL_GPIO_AF_DisableRemap_TIM9
  * @note  禁用: 无重映射 (TIM9_CH1在PA2 且 TIM9_CH2在PA3)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM9(void)
{
  /* 清除TIM9_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP);
}

/**
  * @brief  检查TIM9_CH1和TIM9_CH2是否已被重映射
  * @rmtoll MAPR2         TIM9_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM9
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM9(void)
{
  /* 读取TIM9重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP) == (AFIO_MAPR2_TIM9_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief  启用TIM10_CH1的重映射。
  * @rmtoll MAPR2          TIM10_REMAP           LL_GPIO_AF_EnableRemap_TIM10
  * @note  启用: 重映射     (TIM10_CH1在PF6)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM10(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM10_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP);
}

/**
  * @brief  禁用TIM10_CH1的重映射。
  * @rmtoll MAPR2          TIM10_REMAP           LL_GPIO_AF_DisableRemap_TIM10
  * @note  禁用: 无重映射 (TIM10_CH1在PB8)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM10(void)
{
  /* 清除TIM10_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP);
}

/**
  * @brief  检查TIM10_CH1是否已被重映射
  * @rmtoll MAPR2         TIM10_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM10
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM10(void)
{
  /* 读取TIM10重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP) == (AFIO_MAPR2_TIM10_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM11_REMAP)
/**
  * @brief  启用TIM11_CH1的重映射。
  * @rmtoll MAPR2          TIM11_REMAP           LL_GPIO_AF_EnableRemap_TIM11
  * @note  启用: 重映射     (TIM11_CH1在PF7)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM11(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM11_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP);
}

/**
  * @brief  禁用TIM11_CH1的重映射。
  * @rmtoll MAPR2          TIM11_REMAP           LL_GPIO_AF_DisableRemap_TIM11
  * @note  禁用: 无重映射 (TIM11_CH1在PB9)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM11(void)
{
  /* 清除TIM11_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP);
}

/**
  * @brief  检查TIM11_CH1是否已被重映射
  * @rmtoll MAPR2         TIM11_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM11
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM11(void)
{
  /* 读取TIM11重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP) == (AFIO_MAPR2_TIM11_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief  启用TIM13_CH1的重映射。
  * @rmtoll MAPR2          TIM13_REMAP           LL_GPIO_AF_EnableRemap_TIM13
  * @note  启用: 重映射     STM32F100:(TIM13_CH1在PF8). 其他:(TIM13_CH1在PB0).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM13(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM13_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP);
}

/**
  * @brief  禁用TIM13_CH1的重映射。
  * @rmtoll MAPR2          TIM13_REMAP           LL_GPIO_AF_DisableRemap_TIM13
  * @note  禁用: 无重映射 STM32F100:(TIM13_CH1在PA6). 其他:(TIM13_CH1在PC8).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM13(void)
{
  /* 清除TIM13_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP);
}

/**
  * @brief  检查TIM13_CH1是否已被重映射
  * @rmtoll MAPR2         TIM13_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM13
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM13(void)
{
  /* 读取TIM13重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP) == (AFIO_MAPR2_TIM13_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief  启用TIM14_CH1的重映射。
  * @rmtoll MAPR2          TIM14_REMAP           LL_GPIO_AF_EnableRemap_TIM14
  * @note  启用: 重映射     STM32F100:(TIM14_CH1在PB1). 其他:(TIM14_CH1在PF9).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM14(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM14_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP);
}

/**
  * @brief  禁用TIM14_CH1的重映射。
  * @rmtoll MAPR2          TIM14_REMAP           LL_GPIO_AF_DisableRemap_TIM14
  * @note  禁用: 无重映射 STM32F100:(TIM14_CH1在PC9). 其他:(TIM14_CH1在PA7).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM14(void)
{
  /* 清除TIM14_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP);
}

/**
  * @brief  检查TIM14_CH1是否已被重映射
  * @rmtoll MAPR2         TIM14_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM14
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM14(void)
{
  /* 读取TIM14重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP) == (AFIO_MAPR2_TIM14_REMAP));
}
#endif

#if defined(AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief  控制可选FSMC_NADV信号的使用。
  * @rmtoll MAPR2          FSMC_NADV           LL_GPIO_AF_Disconnect_FSMCNADV
  * @note  断开: NADV信号未连接。I/O引脚可被其他外设使用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Disconnect_FSMCNADV(void)
{
  /* 设置FSMC_NADV_REMAP位，断开NADV引脚，释放该引脚供其他功能使用 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}

/**
  * @brief  控制可选FSMC_NADV信号的使用。
  * @rmtoll MAPR2          FSMC_NADV           LL_GPIO_AF_Connect_FSMCNADV
  * @note  连接: NADV信号连接到输出 (默认)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Connect_FSMCNADV(void)
{
  /* 清除FSMC_NADV_REMAP位，连接NADV引脚，用于FSMC操作 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}
#endif

#if defined(AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief  启用TIM15_CH1和TIM15_CH2的重映射。
  * @rmtoll MAPR2          TIM15_REMAP           LL_GPIO_AF_EnableRemap_TIM15
  * @note  启用: 重映射     (TIM15_CH1在PB14 且 TIM15_CH2在PB15)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM15(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM15_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP);
}
/**
  * @brief  禁用TIM15_CH1和TIM15_CH2的重映射。
  * @rmtoll MAPR2          TIM15_REMAP           LL_GPIO_AF_DisableRemap_TIM15
  * @note  禁用: 无重映射 (TIM15_CH1在PA2  且 TIM15_CH2在PA3)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM15(void)
{
  /* 清除TIM15_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP);
}

/**
  * @brief  检查TIM15_CH1是否已被重映射
  * @rmtoll MAPR2         TIM15_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM15
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM15(void)
{
  /* 读取TIM15重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP) == (AFIO_MAPR2_TIM15_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief  启用TIM16_CH1的重映射。
  * @rmtoll MAPR2          TIM16_REMAP           LL_GPIO_AF_EnableRemap_TIM16
  * @note  启用: 重映射     (TIM16_CH1在PA6)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM16(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM16_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP);
}

/**
  * @brief  禁用TIM16_CH1的重映射。
  * @rmtoll MAPR2          TIM16_REMAP           LL_GPIO_AF_DisableRemap_TIM16
  * @note  禁用: 无重映射 (TIM16_CH1在PB8)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM16(void)
{
  /* 清除TIM16_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP);
}

/**
  * @brief  检查TIM16_CH1是否已被重映射
  * @rmtoll MAPR2         TIM16_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM16
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM16(void)
{
  /* 读取TIM16重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP) == (AFIO_MAPR2_TIM16_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief  启用TIM17_CH1的重映射。
  * @rmtoll MAPR2          TIM17_REMAP           LL_GPIO_AF_EnableRemap_TIM17
  * @note  启用: 重映射     (TIM17_CH1在PA7)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM17(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM17_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP);
}

/**
  * @brief  禁用TIM17_CH1的重映射。
  * @rmtoll MAPR2          TIM17_REMAP           LL_GPIO_AF_DisableRemap_TIM17
  * @note  禁用: 无重映射 (TIM17_CH1在PB9)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM17(void)
{
  /* 清除TIM17_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP);
}

/**
  * @brief  检查TIM17_CH1是否已被重映射
  * @rmtoll MAPR2         TIM17_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM17
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM17(void)
{
  /* 读取TIM17重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP) == (AFIO_MAPR2_TIM17_REMAP));
}
#endif

#if defined(AFIO_MAPR2_CEC_REMAP)

/**
  * @brief  启用CEC的重映射。
  * @rmtoll MAPR2          CEC_REMAP           LL_GPIO_AF_EnableRemap_CEC
  * @note  启用: 重映射     (CEC在PB10)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_CEC(void)
{
  /* 设置AFIO_MAPR2寄存器的CEC_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP);
}

/**
  * @brief  禁用CEC的重映射。
  * @rmtoll MAPR2          CEC_REMAP           LL_GPIO_AF_DisableRemap_CEC
  * @note  禁用: 无重映射 (CEC在PB8)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_CEC(void)
{
  /* 清除CEC_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP);
}

/**
  * @brief  检查CEC是否已被重映射
  * @rmtoll MAPR2         CEC_REMAP         LL_GPIO_AF_IsEnabledRemap_CEC
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_CEC(void)
{
  /* 读取CEC重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP) == (AFIO_MAPR2_CEC_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief  控制TIM1_CH1 TIM1_CH2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM1_DMA_REMAP           LL_GPIO_AF_EnableRemap_TIM1DMA
  * @note  启用: 重映射 (TIM1_CH1 DMA请求/DMA1通道6, TIM1_CH2 DMA请求/DMA1通道6)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM1DMA(void)
{
  /* 设置TIM1_DMA_REMAP位，改变TIM1 DMA请求的通道映射 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP);
}

/**
  * @brief  控制TIM1_CH1 TIM1_CH2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM1_DMA_REMAP           LL_GPIO_AF_DisableRemap_TIM1DMA
  * @note  禁用: 无重映射 (TIM1_CH1 DMA请求/DMA1通道2, TIM1_CH2 DMA请求/DMA1通道3).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM1DMA(void)
{
  /* 清除TIM1_DMA_REMAP位，恢复默认DMA通道映射 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP);
}

/**
  * @brief  检查TIM1DMA是否已被重映射
  * @rmtoll MAPR2         TIM1_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM1DMA
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM1DMA(void)
{
  /* 读取TIM1 DMA重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP) == (AFIO_MAPR2_TIM1_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM76_DAC_DMA_REMAP           LL_GPIO_AF_EnableRemap_TIM67DACDMA
  * @note  启用: 重映射 (TIM6_DAC1 DMA请求/DMA1通道3, TIM7_DAC2 DMA请求/DMA1通道4)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM67DACDMA(void)
{
  /* 设置TIM67_DAC_DMA_REMAP位，改变TIM6/7 DAC DMA请求的通道映射 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP);
}

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM76_DAC_DMA_REMAP           LL_GPIO_AF_DisableRemap_TIM67DACDMA
  * @note  禁用: 无重映射 (TIM6_DAC1 DMA请求/DMA2通道3, TIM7_DAC2 DMA请求/DMA2通道4)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM67DACDMA(void)
{
  /* 清除TIM67_DAC_DMA_REMAP位，恢复默认DMA通道映射 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP);
}

/**
  * @brief  检查TIM67DACDMA是否已被重映射
  * @rmtoll MAPR2         TIM76_DAC_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA(void)
{
  /* 读取TIM6/7 DAC DMA重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP) == (AFIO_MAPR2_TIM67_DAC_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief  启用TIM12_CH1和TIM12_CH2的重映射。
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_EnableRemap_TIM12
  * @note  启用: 重映射     (TIM12_CH1在PB12 且 TIM12_CH2在PB13)。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM12(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM12_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief  禁用TIM12_CH1和TIM12_CH2的重映射。
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_DisableRemap_TIM12
  * @note  禁用: 无重映射 (TIM12_CH1在PC4  且 TIM12_CH2在PC5)。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM12(void)
{
  /* 清除TIM12_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief  检查TIM12_CH1是否已被重映射
  * @rmtoll MAPR2         TIM12_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM12
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM12(void)
{
  /* 读取TIM12重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP) == (AFIO_MAPR2_TIM12_REMAP));
}
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief  杂项功能重映射。
  *         此位由软件置位和清除。它控制杂项功能。
  *         DMA2通道5中断在向量表中的位置。
  *         DAC触发3的定时器选择 (TSEL[2:0] = 011, 更多细节请参考DAC_CR寄存器)。
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_EnableRemap_MISC
  * @note  启用: DMA2通道5中断单独映射到位置60，TIM15 TRGO事件被选为DAC触发3，TIM15触发TIM1/3。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_MISC(void)
{
  /* 设置MISC_REMAP位以启用杂项重映射功能 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief  杂项功能重映射。
  *         此位由软件置位和清除。它控制杂项功能。
  *         DMA2通道5中断在向量表中的位置。
  *         DAC触发3的定时器选择 (TSEL[2:0] = 011, 更多细节请参考DAC_CR寄存器)。
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_DisableRemap_MISC
  * @note  禁用: DMA2通道5中断与DMA2通道4一起映射到位置59，TIM5 TRGO事件被选为DAC触发3，TIM5触发TIM1/3。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_MISC(void)
{
  /* 清除MISC_REMAP位以禁用杂项重映射功能 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief  检查MISC是否已被重映射
  * @rmtoll MAPR2         MISC_REMAP         LL_GPIO_AF_IsEnabledRemap_MISC
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_MISC(void)
{
  /* 读取MISC重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP) == (AFIO_MAPR2_MISC_REMAP));
}
#endif

/**
  * @}
  */

/** @defgroup GPIO_AF_LL_EVENTOUT 输出事件配置
  * @brief 本节提供定义以配置EVENTOUT Cortex特性。
  * @{
  */

/**
  * @brief  配置EVENTOUT Cortex信号连接的端口和引脚。
  * @rmtoll EVCR          PORT           LL_GPIO_AF_ConfigEventout\n
  *         EVCR          PIN            LL_GPIO_AF_ConfigEventout
  * @param  LL_GPIO_PortSource 此参数可以是以下值之一:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_A
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_B
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_C
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_D
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_E
  * @param  LL_GPIO_PinSource 此参数可以是以下值之一:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_0
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_1
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_2
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_3
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_4
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_5
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_6
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_7
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_8
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_9
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_10
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_11
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_12
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_13
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_14
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_15
  * @retval 无
*/
__STATIC_INLINE void LL_GPIO_AF_ConfigEventout(uint32_t LL_GPIO_PortSource, uint32_t LL_GPIO_PinSource)
{
  /* 配置EVCR寄存器，设置事件输出对应的GPIO端口和引脚号 */
  MODIFY_REG(AFIO->EVCR, (AFIO_EVCR_PORT) | (AFIO_EVCR_PIN), (LL_GPIO_PortSource) | (LL_GPIO_PinSource));
}

/**
  * @brief  启用事件输出。
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_EnableEventout
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableEventout(void)
{
  /* 设置EVOE位，使能Cortex内核的事件输出功能到指定引脚 */
  SET_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @brief  禁用事件输出。
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_DisableEventout
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableEventout(void)
{
  /* 清除EVOE位，禁用事件输出功能 */
  CLEAR_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @}
  */
/** @defgroup GPIO_AF_LL_EXTI EXTI外部中断
  * @brief 本节配置EXTI外部中断的源输入。
  * @{
  */

/**
  * @brief  配置EXTI外部中断的源输入。
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_SetEXTISource
  * @param  Port 此参数可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  * @param  Line 此参数可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_LINE0
  *         @arg @ref LL_GPIO_AF_EXTI_LINE1
  *         @arg @ref LL_GPIO_AF_EXTI_LINE2
  *         @arg @ref LL_GPIO_AF_EXTI_LINE3
  *         @arg @ref LL_GPIO_AF_EXTI_LINE4
  *         @arg @ref LL_GPIO_AF_EXTI_LINE5
  *         @arg @ref LL_GPIO_AF_EXTI_LINE6
  *         @arg @ref LL_GPIO_AF_EXTI_LINE7
  *         @arg @ref LL_GPIO_AF_EXTI_LINE8
  *         @arg @ref LL_GPIO_AF_EXTI_LINE9
  *         @arg @ref LL_GPIO_AF_EXTI_LINE10
  *         @arg @ref LL_GPIO_AF_EXTI_LINE11
  *         @arg @ref LL_GPIO_AF_EXTI_LINE12
  *         @arg @ref LL_GPIO_AF_EXTI_LINE13
  *         @arg @ref LL_GPIO_AF_EXTI_LINE14
  *         @arg @ref LL_GPIO_AF_EXTI_LINE15
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_SetEXTISource(uint32_t Port, uint32_t Line)
{
  /* 
     配置EXTI外部中断线源。
     Line参数的低8位用于索引EXTICR数组(0-3对应EXTICR1-4)。
     Line参数的高16位包含具体的配置位掩码。
     Port参数左移相应位置后写入寄存器。
  */
  MODIFY_REG(AFIO->EXTICR[Line & 0xFF], (Line >> 16), Port << POSITION_VAL((Line >> 16)));
}

/**
  * @brief  获取特定EXTI线的配置源
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_GetEXTISource
  * @param  Line 此参数可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_LINE0
  *         @arg @ref LL_GPIO_AF_EXTI_LINE1
  *         @arg @ref LL_GPIO_AF_EXTI_LINE2
  *         @arg @ref LL_GPIO_AF_EXTI_LINE3
  *         @arg @ref LL_GPIO_AF_EXTI_LINE4
  *         @arg @ref LL_GPIO_AF_EXTI_LINE5
  *         @arg @ref LL_GPIO_AF_EXTI_LINE6
  *         @arg @ref LL_GPIO_AF_EXTI_LINE7
  *         @arg @ref LL_GPIO_AF_EXTI_LINE8
  *         @arg @ref LL_GPIO_AF_EXTI_LINE9
  *         @arg @ref LL_GPIO_AF_EXTI_LINE10
  *         @arg @ref LL_GPIO_AF_EXTI_LINE11
  *         @arg @ref LL_GPIO_AF_EXTI_LINE12
  *         @arg @ref LL_GPIO_AF_EXTI_LINE13
  *         @arg @ref LL_GPIO_AF_EXTI_LINE14
  *         @arg @ref LL_GPIO_AF_EXTI_LINE15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_GetEXTISource(uint32_t Line)
{
  /* 
     读取EXTI外部中断线源配置。
     读取对应寄存器位，并右移对齐，返回端口号。
  */
  return (uint32_t)(READ_BIT(AFIO->EXTICR[Line & 0xFF], (Line >> 16)) >> POSITION_VAL(Line >> 16));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_EF_Init 初始化和反初始化函数
  * @{
  */

ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx); // GPIO外设反初始化（复位）函数声明
ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct); // GPIO初始化函数声明，根据配置结构体初始化GPIO
void        LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct); // 初始化GPIO配置结构体为默认值

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF) || defined (GPIOG) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F1xx_LL_GPIO_H */
