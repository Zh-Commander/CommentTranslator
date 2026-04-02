
/**
  * @brief  Check if USART1 has been remapped or not
  * @rmtoll MAPR         USART1_REMAP         LL_GPIO_AF_IsEnabledRemap_USART1
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_USART1(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_USART1_REMAP) == (AFIO_MAPR_USART1_REMAP));
}

/**
  * @brief Enable the remapping of USART2 alternate function CTS, RTS, CK, TX and RX.
  * @rmtoll MAPR          USART2_REMAP           LL_GPIO_AF_EnableRemap_USART2
  * @note  ENABLE: Remap     (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART2(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_USART2_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of USART2 alternate function CTS, RTS, CK, TX and RX.
  * @rmtoll MAPR          USART2_REMAP           LL_GPIO_AF_DisableRemap_USART2
  * @note  DISABLE: No remap (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART2(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART2_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if USART2 has been remapped or not
  * @rmtoll MAPR         USART2_REMAP         LL_GPIO_AF_IsEnabledRemap_USART2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_USART2(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_USART2_REMAP) == (AFIO_MAPR_USART2_REMAP));
}

#if defined (AFIO_MAPR_USART3_REMAP)
/**
  * @brief Enable the remapping of USART3 alternate function CTS, RTS, CK, TX and RX.
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_EnableRemap_USART3
  * @note  ENABLE: Full remap     (TX/PD8,  RX/PD9,  CK/PD10, CTS/PD11, RTS/PD12)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of USART3 alternate function CTS, RTS, CK, TX and RX.
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_RemapPartial_USART3
  * @note  PARTIAL: Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_USART3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Disable the remapping of USART3 alternate function CTS, RTS, CK, TX and RX.
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_DisableRemap_USART3
  * @note  DISABLE: No remap      (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}
#endif

/**
  * @brief Enable the remapping of TIM1 alternate function channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_EnableRemap_TIM1
  * @note  ENABLE: Full remap     (ETR/PE7,  CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8,  CH2N/PE10, CH3N/PE12)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM1(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of TIM1 alternate function channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_RemapPartial_TIM1
  * @note  PARTIAL: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PA6,  CH1N/PA7,  CH2N/PB0,  CH3N/PB1)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_TIM1(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Disable the remapping of TIM1 alternate function channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_DisableRemap_TIM1
  * @note  DISABLE: No remap      (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM1(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_EnableRemap_TIM2
  * @note  ENABLE: Full remap       (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM2(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_RemapPartial2_TIM2
  * @note  PARTIAL_2: Partial remap (CH1/ETR/PA0,  CH2/PA1, CH3/PB10, CH4/PB11)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial2_TIM2(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_RemapPartial1_TIM2
  * @note  PARTIAL_1: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2,  CH4/PA3)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial1_TIM2(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Disable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_DisableRemap_TIM2
  * @note  DISABLE: No remap        (CH1/ETR/PA0,  CH2/PA1, CH3/PA2,  CH4/PA3)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM2(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of TIM3 alternate function channels 1 to 4
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_EnableRemap_TIM3
  * @note  ENABLE: Full remap     (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
  * @note  TIM3_ETR on PE0 is not re-mapped.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable the remapping of TIM3 alternate function channels 1 to 4
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_RemapPartial_TIM3
  * @note  PARTIAL: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 is not re-mapped.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_TIM3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Disable the remapping of TIM3 alternate function channels 1 to 4
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_DisableRemap_TIM3
  * @note  DISABLE: No remap      (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 is not re-mapped.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM3(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

#if defined(AFIO_MAPR_TIM4_REMAP)
/**
  * @brief Enable the remapping of TIM4 alternate function channels 1 to 4.
  * @rmtoll MAPR          TIM4_REMAP           LL_GPIO_AF_EnableRemap_TIM4
  * @note  ENABLE: Full remap (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
  * @note  TIM4_ETR on PE0 is not re-mapped.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM4(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM4_REMAP | AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief Disable the remapping of TIM4 alternate function channels 1 to 4.
  * @rmtoll MAPR          TIM4_REMAP           LL_GPIO_AF_DisableRemap_TIM4
  * @note  DISABLE: No remap  (TIM4_CH1/PB6,  TIM4_CH2/PB7,  TIM4_CH3/PB8,  TIM4_CH4/PB9)
  * @note  TIM4_ETR on PE0 is not re-mapped.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM4(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM4_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if TIM4 has been remapped or not
  * @rmtoll MAPR         TIM4_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM4(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_TIM4_REMAP) == (AFIO_MAPR_TIM4_REMAP));
}
#endif

#if defined(AFIO_MAPR_CAN_REMAP_REMAP1)

/**
  * @brief Enable or disable the remapping of CAN alternate function CAN_RX and CAN_TX in devices with a single CAN interface.
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial1_CAN1
  * @note  CASE 1: CAN_RX mapped to PA11, CAN_TX mapped to PA12
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial1_CAN1(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP1 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable or disable the remapping of CAN alternate function CAN_RX and CAN_TX in devices with a single CAN interface.
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial2_CAN1
  * @note  CASE 2: CAN_RX mapped to PB8,  CAN_TX mapped to PB9 (not available on 36-pin package)
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial2_CAN1(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP2 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief Enable or disable the remapping of CAN alternate function CAN_RX and CAN_TX in devices with a single CAN interface.
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial3_CAN1
  * @note  CASE 3: CAN_RX mapped to PD0,  CAN_TX mapped to PD1
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial3_CAN1(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP3 | AFIO_MAPR_SWJ_CFG));
}
#endif

/**
  * @brief Enable the remapping of PD0 and PD1. When the HSE oscillator is not used
  *        (application running on internal 8 MHz RC) PD0 and PD1 can be mapped on OSC_IN and
  *        OSC_OUT. This is available only on 36, 48 and 64 pins packages (PD0 and PD1 are available
  *        on 100-pin and 144-pin packages, no need for remapping).
  * @rmtoll MAPR          PD01_REMAP           LL_GPIO_AF_EnableRemap_PD01
  * @note  ENABLE: PD0 remapped on OSC_IN, PD1 remapped on OSC_OUT.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_PD01(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_PD01_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of PD0 and PD1. When the HSE oscillator is not used
  *        (application running on internal 8 MHz RC) PD0 and PD1 can be mapped on OSC_IN and
  *        OSC_OUT. This is available only on 36, 48 and 64 pins packages (PD0 and PD1 are available
  *        on 100-pin and 144-pin packages, no need for remapping).
  * @rmtoll MAPR          PD01_REMAP           LL_GPIO_AF_DisableRemap_PD01
  * @note  DISABLE: No remapping of PD0 and PD1
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_PD01(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_PD01_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if PD01 has been remapped or not
  * @rmtoll MAPR         PD01_REMAP         LL_GPIO_AF_IsEnabledRemap_PD01
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_PD01(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_PD01_REMAP) == (AFIO_MAPR_PD01_REMAP));
}

#if defined(AFIO_MAPR_TIM5CH4_IREMAP)
/**
  * @brief Enable the remapping of TIM5CH4.
  * @rmtoll MAPR          TIM5CH4_IREMAP           LL_GPIO_AF_EnableRemap_TIM5CH4
  * @note  ENABLE: LSI internal clock is connected to TIM5_CH4 input for calibration purpose.
  * @note  This function is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM5CH4(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM5CH4_IREMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of TIM5CH4.
  * @rmtoll MAPR          TIM5CH4_IREMAP           LL_GPIO_AF_DisableRemap_TIM5CH4
  * @note  DISABLE: TIM5_CH4 is connected to PA3
  * @note  This function is available only in high density value line devices.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM5CH4(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM5CH4_IREMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if TIM5CH4 has been remapped or not
  * @rmtoll MAPR         TIM5CH4_IREMAP         LL_GPIO_AF_IsEnabledRemap_TIM5CH4
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM5CH4(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_TIM5CH4_IREMAP) == (AFIO_MAPR_TIM5CH4_IREMAP));
}
#endif

#if defined(AFIO_MAPR_ETH_REMAP)
/**
  * @brief Enable the remapping of Ethernet MAC connections with the PHY.
  * @rmtoll MAPR          ETH_REMAP           LL_GPIO_AF_EnableRemap_ETH
  * @note  ENABLE: Remap     (RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ETH(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ETH_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of Ethernet MAC connections with the PHY.
  * @rmtoll MAPR          ETH_REMAP           LL_GPIO_AF_DisableRemap_ETH
  * @note  DISABLE: No remap (RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5,  RXD2/PB0,  RXD3/PB1)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ETH(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ETH_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if ETH has been remapped or not
  * @rmtoll MAPR         ETH_REMAP         LL_GPIO_AF_IsEnabledRemap_ETH
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ETH(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ETH_REMAP) == (AFIO_MAPR_ETH_REMAP));
}
#endif

#if defined(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief Enable the remapping of CAN2 alternate function CAN2_RX and CAN2_TX.
  * @rmtoll MAPR          CAN2_REMAP           LL_GPIO_AF_EnableRemap_CAN2
  * @note  ENABLE: Remap     (CAN2_RX/PB5,  CAN2_TX/PB6)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_CAN2(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_CAN2_REMAP | AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief Disable the remapping of CAN2 alternate function CAN2_RX and CAN2_TX.
  * @rmtoll MAPR          CAN2_REMAP           LL_GPIO_AF_DisableRemap_CAN2
  * @note  DISABLE: No remap (CAN2_RX/PB12, CAN2_TX/PB13)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_CAN2(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN2_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if CAN2 has been remapped or not
  * @rmtoll MAPR         CAN2_REMAP         LL_GPIO_AF_IsEnabledRemap_CAN2
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_CAN2(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_CAN2_REMAP) == (AFIO_MAPR_CAN2_REMAP));
}
#endif

#if defined(AFIO_MAPR_MII_RMII_SEL)
/**
  * @brief Configures the Ethernet MAC internally for use with an external MII or RMII PHY.
  * @rmtoll MAPR          MII_RMII_SEL           LL_GPIO_AF_Select_ETH_RMII
  * @note  ETH_RMII: Configure Ethernet MAC for connection with an RMII PHY
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Select_ETH_RMII(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_MII_RMII_SEL | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Configures the Ethernet MAC internally for use with an external MII or RMII PHY.
  * @rmtoll MAPR          MII_RMII_SEL           LL_GPIO_AF_Select_ETH_MII
  * @note  ETH_MII: Configure Ethernet MAC for connection with an MII PHY
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_Select_ETH_MII(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_MII_RMII_SEL | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR_ADC1_ETRGINJ_REMAP)
/**
  * @brief Enable the remapping of ADC1_ETRGINJ (ADC 1 External trigger injected conversion).
  * @rmtoll MAPR          ADC1_ETRGINJ_REMAP           LL_GPIO_AF_EnableRemap_ADC1_ETRGINJ
  * @note  ENABLE: ADC1 External Event injected conversion is connected to TIM8 Channel4.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC1_ETRGINJ(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of ADC1_ETRGINJ (ADC 1 External trigger injected conversion).
  * @rmtoll MAPR          ADC1_ETRGINJ_REMAP           LL_GPIO_AF_DisableRemap_ADC1_ETRGINJ
  * @note  DISABLE: ADC1 External trigger injected conversion is connected to EXTI15
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC1_ETRGINJ(void)
{
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC1_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if ADC1_ETRGINJ has been remapped or not
  * @rmtoll MAPR         ADC1_ETRGINJ_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGINJ
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGINJ(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGINJ_REMAP) == (AFIO_MAPR_ADC1_ETRGINJ_REMAP));
}
#endif

#if defined(AFIO_MAPR_ADC1_ETRGREG_REMAP)
/**
  * @brief Enable the remapping of ADC1_ETRGREG (ADC 1 External trigger regular conversion).
  * @rmtoll MAPR          ADC1_ETRGREG_REMAP           LL_GPIO_AF_EnableRemap_ADC1_ETRGREG
  * @note  ENABLE: ADC1 External Event regular conversion is connected to TIM8 TRG0.
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC1_ETRGREG(void)
{
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief Disable the remapping of ADC1_ETRGREG (ADC 1 External trigger regular conversion).
  * @rmtoll MAPR          ADC1_ETRGREG_REMAP           LL_GPIO_AF_DisableRemap_ADC1_ETRGREG
  * @note  DISABLE: ADC1 External trigger regular conversion is connected to EXTI11
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC1_ETRGREG(void)
{
   MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC1_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  Check if ADC1_ETRGREG has been remapped or not
  * @rmtoll MAPR         ADC1_ETRGREG_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGREG
  * @retval State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGREG(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGREG_REMAP) == (AFIO_MAPR_ADC1_ETRGREG_REMAP));
}
#endif

#if defined(AFIO_MAPR_ADC2_ETRGINJ_REMAP)
