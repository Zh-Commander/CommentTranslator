
/**
  * @brief Enable the remapping of ADC2_ETRGREG (ADC 2 External trigger injected conversion).
  * @rmtoll MAPR          ADC2_ETRGINJ_REMAP           LL_GPIO_AF_EnableRemap_ADC2_ETRGINJ
  * @note  ENABLE: ADC2 External Event injected conversion is connected to TIM8 Channel4.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC2_ETRGINJ(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of ADC2_ETRGREG (ADC 2 External trigger injected conversion).
  * @rmtoll MAPR          ADC2_ETRGINJ_REMAP           LL_GPIO_AF_DisableRemap_ADC2_ETRGINJ
  * @note  DISABLE: ADC2 External trigger injected conversion is connected to EXTI15
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC2_ETRGINJ(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC2_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if ADC2_ETRGINJ has been remapped or not
  * @rmtoll MAPR         ADC2_ETRGINJ_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGINJ
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGINJ(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGINJ_REMAP) == (AFIO_MAPR_ADC2_ETRGINJ_REMAP));
}
#endif

#if defined (AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief Enable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @rmtoll MAPR          ADC2_ETRGREG_REMAP           LL_GPIO_AF_EnableRemap_ADC2_ETRGREG
  * @note  ENABLE: ADC2 External Event regular conversion is connected to TIM8 TRG0.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC2_ETRGREG(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @rmtoll MAPR          ADC2_ETRGREG_REMAP           LL_GPIO_AF_DisableRemap_ADC2_ETRGREG
  * @note  DISABLE: ADC2 External trigger regular conversion is connected to EXTI11
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC2_ETRGREG(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC2_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if ADC2_ETRGREG has been remapped or not
  * @rmtoll MAPR         ADC2_ETRGREG_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGREG
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGREG(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGREG_REMAP) == (AFIO_MAPR_ADC2_ETRGREG_REMAP));
}
#endif

/**
  * @brief Enable the Serial wire JTAG configuration
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_EnableRemap_SWJ
  * @note  ENABLE: Full SWJ (JTAG-DP + SW-DP): Reset State
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SWJ(void)
{
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_RESET);
}

/**
  * @brief Enable the Serial wire JTAG configuration
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_Remap_SWJ_NONJTRST
  * @note  NONJTRST: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_SWJ_NONJTRST(void)
{
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_NOJNTRST);
}

/**
  * @brief Enable the Serial wire JTAG configuration
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_Remap_SWJ_NOJTAG
  * @note  NOJTAG: JTAG-DP Disabled and SW-DP Enabled
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_SWJ_NOJTAG(void)
{
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_JTAGDISABLE);
}

/**
  * @brief Disable the Serial wire JTAG configuration
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_DisableRemap_SWJ
  * @note  DISABLE: JTAG-DP Disabled and SW-DP Disabled
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SWJ(void)
{
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_DISABLE);
}

#if defined(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief Enable the remapping of SPI3 alternate functions SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD.
  * @rmtoll MAPR          SPI3_REMAP           LL_GPIO_AF_EnableRemap_SPI3
  * @note  ENABLE: Remap     (SPI3_NSS-I2S3_WS/PA4,  SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SPI3(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SPI3_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of SPI3 alternate functions SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD.
  * @rmtoll MAPR          SPI3_REMAP           LL_GPIO_AF_DisableRemap_SPI3
  * @note  DISABLE: No remap (SPI3_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3,  SPI3_MISO/PB4,  SPI3_MOSI-I2S3_SD/PB5).
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SPI3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_SPI3_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if SPI3 has been remapped or not
  * @rmtoll MAPR         SPI3_REMAP         LL_GPIO_AF_IsEnabledRemap_SPI3_REMAP
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_SPI3(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_SPI3_REMAP) == (AFIO_MAPR_SPI3_REMAP));
}
#endif

#if defined(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief Control of TIM2_ITR1 internal mapping.
  * @rmtoll MAPR          TIM2ITR1_IREMAP           LL_GPIO_AF_Remap_TIM2ITR1_TO_USB
  * @note  TO_USB: Connect USB OTG SOF (Start of Frame) output to TIM2_ITR1 for calibration purposes.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_TIM2ITR1_TO_USB(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM2ITR1_IREMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Control of TIM2_ITR1 internal mapping.
  * @rmtoll MAPR          TIM2ITR1_IREMAP           LL_GPIO_AF_Remap_TIM2ITR1_TO_ETH
  * @note  TO_ETH: Connect TIM2_ITR1 internally to the Ethernet PTP output for calibration purposes.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_TIM2ITR1_TO_ETH(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2ITR1_IREMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief Enable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @rmtoll MAPR          PTP_PPS_REMAP           LL_GPIO_AF_EnableRemap_ETH_PTP_PPS
  * @note  ENABLE: PTP_PPS is output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ETH_PTP_PPS(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_PTP_PPS_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @rmtoll MAPR          PTP_PPS_REMAP           LL_GPIO_AF_DisableRemap_ETH_PTP_PPS
  * @note  DISABLE: PTP_PPS not output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ETH_PTP_PPS(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_PTP_PPS_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief Enable the remapping of TIM9_CH1 and TIM9_CH2.
  * @rmtoll MAPR2          TIM9_REMAP           LL_GPIO_AF_EnableRemap_TIM9
  * @note  ENABLE: Remap     (TIM9_CH1 on PE5 and TIM9_CH2 on PE6).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM9(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP);
}

/**
  * @brief Disable the remapping of TIM9_CH1 and TIM9_CH2.
  * @rmtoll MAPR2          TIM9_REMAP           LL_GPIO_AF_DisableRemap_TIM9
  * @note  DISABLE: No remap (TIM9_CH1 on PA2 and TIM9_CH2 on PA3).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM9(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP);
}

/**
  * @brief  Check if TIM9_CH1 and TIM9_CH2 have been remapped or not
  * @rmtoll MAPR2         TIM9_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM9
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM9(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP) == (AFIO_MAPR2_TIM9_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief Enable the remapping of TIM10_CH1.
  * @rmtoll MAPR2          TIM10_REMAP           LL_GPIO_AF_EnableRemap_TIM10
  * @note  ENABLE: Remap     (TIM10_CH1 on PF6).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM10(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP);
}

/**
  * @brief Disable the remapping of TIM10_CH1.
  * @rmtoll MAPR2          TIM10_REMAP           LL_GPIO_AF_DisableRemap_TIM10
  * @note  DISABLE: No remap (TIM10_CH1 on PB8).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM10(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP);
}

/**
  * @brief  Check if TIM10_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM10_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM10
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM10(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP) == (AFIO_MAPR2_TIM10_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM11_REMAP)
/**
  * @brief Enable the remapping of TIM11_CH1.
  * @rmtoll MAPR2          TIM11_REMAP           LL_GPIO_AF_EnableRemap_TIM11
  * @note  ENABLE: Remap     (TIM11_CH1 on PF7).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM11(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP);
}

/**
  * @brief Disable the remapping of TIM11_CH1.
  * @rmtoll MAPR2          TIM11_REMAP           LL_GPIO_AF_DisableRemap_TIM11
  * @note  DISABLE: No remap (TIM11_CH1 on PB9).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM11(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP);
}

/**
  * @brief  Check if TIM11_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM11_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM11
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM11(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP) == (AFIO_MAPR2_TIM11_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief Enable the remapping of TIM13_CH1.
  * @rmtoll MAPR2          TIM13_REMAP           LL_GPIO_AF_EnableRemap_TIM13
  * @note  ENABLE: Remap     STM32F100:(TIM13_CH1 on PF8). Others:(TIM13_CH1 on PB0).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM13(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP);
}

/**
  * @brief Disable the remapping of TIM13_CH1.
  * @rmtoll MAPR2          TIM13_REMAP           LL_GPIO_AF_DisableRemap_TIM13
  * @note  DISABLE: No remap STM32F100:(TIM13_CH1 on PA6). Others:(TIM13_CH1 on PC8).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM13(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP);
}

/**
  * @brief  Check if TIM13_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM13_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM13
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM13(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP) == (AFIO_MAPR2_TIM13_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief Enable the remapping of TIM14_CH1.
  * @rmtoll MAPR2          TIM14_REMAP           LL_GPIO_AF_EnableRemap_TIM14
  * @note  ENABLE: Remap     STM32F100:(TIM14_CH1 on PB1). Others:(TIM14_CH1 on PF9).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM14(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP);
}

/**
  * @brief Disable the remapping of TIM14_CH1.
  * @rmtoll MAPR2          TIM14_REMAP           LL_GPIO_AF_DisableRemap_TIM14
  * @note  DISABLE: No remap STM32F100:(TIM14_CH1 on PC9). Others:(TIM14_CH1 on PA7).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM14(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP);
}

/**
  * @brief  Check if TIM14_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM14_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM14
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM14(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP) == (AFIO_MAPR2_TIM14_REMAP));
}
#endif

#if defined(AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief Controls the use of the optional FSMC_NADV signal.
  * @rmtoll MAPR2          FSMC_NADV           LL_GPIO_AF_Disconnect_FSMCNADV
  * @note  DISCONNECTED: The NADV signal is not connected. The I/O pin can be used by another peripheral.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Disconnect_FSMCNADV(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}

/**
  * @brief Controls the use of the optional FSMC_NADV signal.
  * @rmtoll MAPR2          FSMC_NADV           LL_GPIO_AF_Connect_FSMCNADV
  * @note  CONNECTED: The NADV signal is connected to the output (default).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Connect_FSMCNADV(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}
#endif

#if defined(AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief Enable the remapping of TIM15_CH1 and TIM15_CH2.
  * @rmtoll MAPR2          TIM15_REMAP           LL_GPIO_AF_EnableRemap_TIM15
  * @note  ENABLE: Remap     (TIM15_CH1 on PB14 and TIM15_CH2 on PB15).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM15(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP);
}
/**
  * @brief Disable the remapping of TIM15_CH1 and TIM15_CH2.
  * @rmtoll MAPR2          TIM15_REMAP           LL_GPIO_AF_DisableRemap_TIM15
  * @note  DISABLE: No remap (TIM15_CH1 on PA2  and TIM15_CH2 on PA3).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM15(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP);
}

/**
  * @brief  Check if TIM15_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM15_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM15
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM15(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP) == (AFIO_MAPR2_TIM15_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief Enable the remapping of TIM16_CH1.
  * @rmtoll MAPR2          TIM16_REMAP           LL_GPIO_AF_EnableRemap_TIM16
  * @note  ENABLE: Remap     (TIM16_CH1 on PA6).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM16(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP);
}

/**
  * @brief Disable the remapping of TIM16_CH1.
  * @rmtoll MAPR2          TIM16_REMAP           LL_GPIO_AF_DisableRemap_TIM16
  * @note  DISABLE: No remap (TIM16_CH1 on PB8).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM16(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP);
}

/**
  * @brief  Check if TIM16_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM16_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM16
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM16(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP) == (AFIO_MAPR2_TIM16_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief Enable the remapping of TIM17_CH1.
  * @rmtoll MAPR2          TIM17_REMAP           LL_GPIO_AF_EnableRemap_TIM17
  * @note  ENABLE: Remap     (TIM17_CH1 on PA7).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM17(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP);
}

/**
  * @brief Disable the remapping of TIM17_CH1.
  * @rmtoll MAPR2          TIM17_REMAP           LL_GPIO_AF_DisableRemap_TIM17
  * @note  DISABLE: No remap (TIM17_CH1 on PB9).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM17(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP);
}

/**
  * @brief  Check if TIM17_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM17_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM17
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM17(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP) == (AFIO_MAPR2_TIM17_REMAP));
}
#endif

#if defined(AFIO_MAPR2_CEC_REMAP)

/**
  * @brief Enable the remapping of CEC.
  * @rmtoll MAPR2          CEC_REMAP           LL_GPIO_AF_EnableRemap_CEC
  * @note  ENABLE: Remap     (CEC on PB10).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_CEC(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP);
}

/**
  * @brief Disable the remapping of CEC.
  * @rmtoll MAPR2          CEC_REMAP           LL_GPIO_AF_DisableRemap_CEC
  * @note  DISABLE: No remap (CEC on PB8).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_CEC(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP);
}

/**
  * @brief  Check if CEC has been remapped or not
  * @rmtoll MAPR2         CEC_REMAP         LL_GPIO_AF_IsEnabledRemap_CEC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_CEC(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP) == (AFIO_MAPR2_CEC_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief Controls the mapping of the TIM1_CH1 TIM1_CH2 DMA requests onto the DMA1 channels.
  * @rmtoll MAPR2          TIM1_DMA_REMAP           LL_GPIO_AF_EnableRemap_TIM1DMA
  * @note  ENABLE: Remap (TIM1_CH1 DMA request/DMA1 Channel6, TIM1_CH2 DMA request/DMA1 Channel6)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM1DMA(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP);
}

/**
  * @brief Controls the mapping of the TIM1_CH1 TIM1_CH2 DMA requests onto the DMA1 channels.
  * @rmtoll MAPR2          TIM1_DMA_REMAP           LL_GPIO_AF_DisableRemap_TIM1DMA
  * @note  DISABLE: No remap (TIM1_CH1 DMA request/DMA1 Channel2, TIM1_CH2 DMA request/DMA1 Channel3).
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM1DMA(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP);
}

/**
  * @brief  Check if TIM1DMA has been remapped or not
  * @rmtoll MAPR2         TIM1_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM1DMA
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM1DMA(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP) == (AFIO_MAPR2_TIM1_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief Controls the mapping of the TIM6_DAC1 and TIM7_DAC2 DMA requests onto the DMA1 channels.
  * @rmtoll MAPR2          TIM76_DAC_DMA_REMAP           LL_GPIO_AF_EnableRemap_TIM67DACDMA
  * @note  ENABLE: Remap (TIM6_DAC1 DMA request/DMA1 Channel3, TIM7_DAC2 DMA request/DMA1 Channel4)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM67DACDMA(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP);
}

/**
  * @brief Controls the mapping of the TIM6_DAC1 and TIM7_DAC2 DMA requests onto the DMA1 channels.
  * @rmtoll MAPR2          TIM76_DAC_DMA_REMAP           LL_GPIO_AF_DisableRemap_TIM67DACDMA
  * @note  DISABLE: No remap (TIM6_DAC1 DMA request/DMA2 Channel3, TIM7_DAC2 DMA request/DMA2 Channel4)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM67DACDMA(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP);
}

/**
  * @brief  Check if TIM67DACDMA has been remapped or not
  * @rmtoll MAPR2         TIM76_DAC_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP) == (AFIO_MAPR2_TIM67_DAC_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief Enable the remapping of TIM12_CH1 and TIM12_CH2.
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_EnableRemap_TIM12
  * @note  ENABLE: Remap     (TIM12_CH1 on PB12 and TIM12_CH2 on PB13).
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM12(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief Disable the remapping of TIM12_CH1 and TIM12_CH2.
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_DisableRemap_TIM12
  * @note  DISABLE: No remap (TIM12_CH1 on PC4  and TIM12_CH2 on PC5).
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM12(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief  Check if TIM12_CH1 has been remapped or not
  * @rmtoll MAPR2         TIM12_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM12
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM12(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP) == (AFIO_MAPR2_TIM12_REMAP));
}
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief Miscellaneous features remapping.
  *        This bit is set and cleared by software. It controls miscellaneous features.
  *        The DMA2 channel 5 interrupt position in the vector table.
  *        The timer selection for DAC trigger 3 (TSEL[2:0] = 011, for more details refer to the DAC_CR register).
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_EnableRemap_MISC
  * @note  ENABLE: DMA2 channel 5 interrupt is mapped separately at position 60 and TIM15 TRGO event is
  *        selected as DAC Trigger 3, TIM15 triggers TIM1/3.
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_MISC(void)
{
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief Miscellaneous features remapping.
  *        This bit is set and cleared by software. It controls miscellaneous features.
  *        The DMA2 channel 5 interrupt position in the vector table.
  *        The timer selection for DAC trigger 3 (TSEL[2:0] = 011, for more details refer to the DAC_CR register).
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_DisableRemap_MISC
  * @note  DISABLE: DMA2 channel 5 interrupt is mapped with DMA2 channel 4 at position 59, TIM5 TRGO
  *        event is selected as DAC Trigger 3, TIM5 triggers TIM1/3.
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_MISC(void)
{
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief  Check if MISC has been remapped or not
  * @rmtoll MAPR2         MISC_REMAP         LL_GPIO_AF_IsEnabledRemap_MISC
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_MISC(void)
{
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP) == (AFIO_MAPR2_MISC_REMAP));
}
#endif

/**
  * @}
  */

/** @defgroup GPIO_AF_LL_EVENTOUT Output Event configuration
  * @brief This section propose definition to Configure EVENTOUT Cortex feature .
  * @{
  */

/**
  * @brief  Configures the port and pin on which the EVENTOUT Cortex signal will be connected.
  * @rmtoll EVCR          PORT           LL_GPIO_AF_ConfigEventout\n
  *         EVCR          PIN            LL_GPIO_AF_ConfigEventout
  * @param  LL_GPIO_PortSource This parameter can be one of the following values:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_A
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_B
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_C
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_D
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_E
  * @param  LL_GPIO_PinSource This parameter can be one of the following values:
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
  * @retval None
*/
__STATIC_INLINE void LL_GPIO_AF_ConfigEventout(uint32_t LL_GPIO_PortSource, uint32_t LL_GPIO_PinSource)
{
  MODIFY_REG(AFIO->EVCR, (AFIO_EVCR_PORT) | (AFIO_EVCR_PIN), (LL_GPIO_PortSource) | (LL_GPIO_PinSource));
}

/**
  * @brief  Enables the Event Output.
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_EnableEventout
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableEventout(void)
{
  SET_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @brief  Disables the Event Output.
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_DisableEventout
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableEventout(void)
{
  CLEAR_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @}
  */
/** @defgroup GPIO_AF_LL_EXTI EXTI external interrupt
  * @brief This section Configure source input for the EXTI external interrupt .
  * @{
  */

/**
  * @brief  Configure source input for the EXTI external interrupt.
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_SetEXTISource
  * @param  Port This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  * @param  Line This parameter can be one of the following values:
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
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_SetEXTISource(uint32_t Port, uint32_t Line)
{
  MODIFY_REG(AFIO->EXTICR[Line & 0xFF], (Line >> 16), Port << POSITION_VAL((Line >> 16)));
}

/**
  * @brief  Get the configured defined for specific EXTI Line
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_GetEXTISource
  * @param  Line This parameter can be one of the following values:
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
  * @retval Returned value can be one of the following values:
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
  return (uint32_t)(READ_BIT(AFIO->EXTICR[Line & 0xFF], (Line >> 16)) >> POSITION_VAL(Line >> 16));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx);
ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct);
void        LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct);

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

