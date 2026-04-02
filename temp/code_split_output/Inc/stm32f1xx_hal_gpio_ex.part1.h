/**
  * @brief Enable the Serial wire JTAG configuration
  * @note  NONJTRST: Full SWJ (JTAG-DP + SW-DP) but without NJTRST
  * @retval None
  */
// 宏定义：启用串行线JTAG配置，释放NJTRST引脚（即完全SWJ但不含NJTRST）
#define __HAL_AFIO_REMAP_SWJ_NONJTRST()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_NOJNTRST)

/**
  * @brief Enable the Serial wire JTAG configuration
  * @note  NOJTAG: JTAG-DP Disabled and SW-DP Enabled
  * @retval None
  */
// 宏定义：启用串行线JTAG配置，禁用JTAG-DP，仅启用SW-DP
#define __HAL_AFIO_REMAP_SWJ_NOJTAG()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_JTAGDISABLE)

/**
  * @brief Disable the Serial wire JTAG configuration
  * @note  DISABLE: JTAG-DP Disabled and SW-DP Disabled
  * @retval None
  */
// 宏定义：禁用串行线JTAG配置，JTAG-DP和SW-DP均禁用（释放相关GPIO引脚用于普通IO）
#define __HAL_AFIO_REMAP_SWJ_DISABLE()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_DISABLE)

#if defined(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief Enable the remapping of SPI3 alternate functions SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD.
  * @note  ENABLE: Remap     (SPI3_NSS-I2S3_WS/PA4,  SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 宏定义：启用SPI3重映射，将SPI3引脚映射到PA4, PC10, PC11, PC12
#define __HAL_AFIO_REMAP_SPI3_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief Disable the remapping of SPI3 alternate functions SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD.
  * @note  DISABLE: No remap (SPI3_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3,  SPI3_MISO/PB4,  SPI3_MOSI-I2S3_SD/PB5).
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 宏定义：禁用SPI3重映射，使用默认引脚PA15, PB3, PB4, PB5
#define __HAL_AFIO_REMAP_SPI3_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_SPI3_REMAP)
#endif

#if defined(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief Control of TIM2_ITR1 internal mapping.
  * @note  TO_USB: Connect USB OTG SOF (Start of Frame) output to TIM2_ITR1 for calibration purposes.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 宏定义：将TIM2_ITR1内部映射连接到USB OTG SOF输出（用于校准）
#define __HAL_AFIO_TIM2ITR1_TO_USB() AFIO_REMAP_ENABLE(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief Control of TIM2_ITR1 internal mapping.
  * @note  TO_ETH: Connect TIM2_ITR1 internally to the Ethernet PTP output for calibration purposes.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 宏定义：将TIM2_ITR1内部映射连接到以太网PTP输出（用于校准）
#define __HAL_AFIO_TIM2ITR1_TO_ETH() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM2ITR1_IREMAP)
#endif

#if defined(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief Enable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @note  ENABLE: PTP_PPS is output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 宏定义：启用以太网PTP PPS信号输出到PB5引脚
#define __HAL_AFIO_ETH_PTP_PPS_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief Disable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @note  DISABLE: PTP_PPS not output on PB5 pin.
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 宏定义：禁用PTP PPS信号输出
#define __HAL_AFIO_ETH_PTP_PPS_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_PTP_PPS_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief Enable the remapping of TIM9_CH1 and TIM9_CH2.
  * @note  ENABLE: Remap     (TIM9_CH1 on PE5 and TIM9_CH2 on PE6).
  * @retval None
  */
// 宏定义：启用TIM9重映射，TIM9_CH1映射到PE5，TIM9_CH2映射到PE6
#define __HAL_AFIO_REMAP_TIM9_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief Disable the remapping of TIM9_CH1 and TIM9_CH2.
  * @note  DISABLE: No remap (TIM9_CH1 on PA2 and TIM9_CH2 on PA3).
  * @retval None
  */
// 宏定义：禁用TIM9重映射，使用默认引脚PA2, PA3
#define __HAL_AFIO_REMAP_TIM9_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief Enable the remapping of TIM10_CH1.
  * @note  ENABLE: Remap     (TIM10_CH1 on PF6).
  * @retval None
  */
// 宏定义：启用TIM10重映射，TIM10_CH1映射到PF6
#define __HAL_AFIO_REMAP_TIM10_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief Disable the remapping of TIM10_CH1.
  * @note  DISABLE: No remap (TIM10_CH1 on PB8).
  * @retval None
  */
// 宏定义：禁用TIM10重映射，使用默认引脚PB8
#define __HAL_AFIO_REMAP_TIM10_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM11_REMAP)
/**
  * @brief Enable the remapping of TIM11_CH1.
  * @note  ENABLE: Remap     (TIM11_CH1 on PF7).
  * @retval None
  */
// 宏定义：启用TIM11重映射，TIM11_CH1映射到PF7
#define __HAL_AFIO_REMAP_TIM11_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP)

/**
  * @brief Disable the remapping of TIM11_CH1.
  * @note  DISABLE: No remap (TIM11_CH1 on PB9).
  * @retval None
  */
// 宏定义：禁用TIM11重映射，使用默认引脚PB9
#define __HAL_AFIO_REMAP_TIM11_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief Enable the remapping of TIM13_CH1.
  * @note  ENABLE: Remap     STM32F100:(TIM13_CH1 on PF8). Others:(TIM13_CH1 on PB0).
  * @retval None
  */
// 宏定义：启用TIM13重映射，引脚映射取决于具体型号（PF8或PB0）
#define __HAL_AFIO_REMAP_TIM13_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief Disable the remapping of TIM13_CH1.
  * @note  DISABLE: No remap STM32F100:(TIM13_CH1 on PA6). Others:(TIM13_CH1 on PC8).
  * @retval None
  */
// 宏定义：禁用TIM13重映射，使用默认引脚（PA6或PC8）
#define __HAL_AFIO_REMAP_TIM13_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief Enable the remapping of TIM14_CH1.
  * @note  ENABLE: Remap     STM32F100:(TIM14_CH1 on PB1). Others:(TIM14_CH1 on PF9).
  * @retval None
  */
// 宏定义：启用TIM14重映射，引脚映射取决于具体型号（PB1或PF9）
#define __HAL_AFIO_REMAP_TIM14_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief Disable the remapping of TIM14_CH1.
  * @note  DISABLE: No remap STM32F100:(TIM14_CH1 on PC9). Others:(TIM14_CH1 on PA7).
  * @retval None
  */
// 宏定义：禁用TIM14重映射，使用默认引脚（PC9或PA7）
#define __HAL_AFIO_REMAP_TIM14_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP)
#endif

#if defined(AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief Controls the use of the optional FSMC_NADV signal.
  * @note  DISCONNECTED: The NADV signal is not connected. The I/O pin can be used by another peripheral.
  * @retval None
  */
// 宏定义：断开FSMC_NADV信号连接，释放该引脚供其他外设使用
#define __HAL_AFIO_FSMCNADV_DISCONNECTED() SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief Controls the use of the optional FSMC_NADV signal.
  * @note  CONNECTED: The NADV signal is connected to the output (default).
  * @retval None
  */
// 宏定义：连接FSMC_NADV信号（默认状态）
#define __HAL_AFIO_FSMCNADV_CONNECTED()    CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief Enable the remapping of TIM15_CH1 and TIM15_CH2.
  * @note  ENABLE: Remap     (TIM15_CH1 on PB14 and TIM15_CH2 on PB15).
  * @retval None
  */
// 宏定义：启用TIM15重映射，TIM15_CH1映射到PB14，TIM15_CH2映射到PB15
#define __HAL_AFIO_REMAP_TIM15_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief Disable the remapping of TIM15_CH1 and TIM15_CH2.
  * @note  DISABLE: No remap (TIM15_CH1 on PA2  and TIM15_CH2 on PA3).
  * @retval None
  */
// 宏定义：禁用TIM15重映射，使用默认引脚PA2, PA3
#define __HAL_AFIO_REMAP_TIM15_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief Enable the remapping of TIM16_CH1.
  * @note  ENABLE: Remap     (TIM16_CH1 on PA6).
  * @retval None
  */
// 宏定义：启用TIM16重映射，TIM16_CH1映射到PA6
#define __HAL_AFIO_REMAP_TIM16_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief Disable the remapping of TIM16_CH1.
  * @note  DISABLE: No remap (TIM16_CH1 on PB8).
  * @retval None
  */
// 宏定义：禁用TIM16重映射，使用默认引脚PB8
#define __HAL_AFIO_REMAP_TIM16_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief Enable the remapping of TIM17_CH1.
  * @note  ENABLE: Remap     (TIM17_CH1 on PA7).
  * @retval None
  */
// 宏定义：启用TIM17重映射，TIM17_CH1映射到PA7
#define __HAL_AFIO_REMAP_TIM17_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief Disable the remapping of TIM17_CH1.
  * @note  DISABLE: No remap (TIM17_CH1 on PB9).
  * @retval None
  */
// 宏定义：禁用TIM17重映射，使用默认引脚PB9
#define __HAL_AFIO_REMAP_TIM17_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP)
#endif

#if defined(AFIO_MAPR2_CEC_REMAP)

/**
  * @brief Enable the remapping of CEC.
  * @note  ENABLE: Remap     (CEC on PB10).
  * @retval None
  */
// 宏定义：启用CEC（HDMI消费电子控制）重映射，映射到PB10
#define __HAL_AFIO_REMAP_CEC_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP)

/**
  * @brief Disable the remapping of CEC.
  * @note  DISABLE: No remap (CEC on PB8).
  * @retval None
  */
// 宏定义：禁用CEC重映射，使用默认引脚PB8
#define __HAL_AFIO_REMAP_CEC_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief Controls the mapping of the TIM1_CH1 TIM1_CH2 DMA requests onto the DMA1 channels.
  * @note  ENABLE: Remap (TIM1_CH1 DMA request/DMA1 Channel6, TIM1_CH2 DMA request/DMA1 Channel6)
  * @retval None
  */
// 宏定义：启用TIM1 DMA请求重映射，将TIM1_CH1/CH2 DMA请求映射到DMA1通道6
#define __HAL_AFIO_REMAP_TIM1DMA_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief Controls the mapping of the TIM1_CH1 TIM1_CH2 DMA requests onto the DMA1 channels.
  * @note  DISABLE: No remap (TIM1_CH1 DMA request/DMA1 Channel2, TIM1_CH2 DMA request/DMA1 Channel3).
  * @retval None
  */
// 宏定义：禁用TIM1 DMA请求重映射，使用默认通道（CH1->DMA1 Ch2, CH2->DMA1 Ch3）
#define __HAL_AFIO_REMAP_TIM1DMA_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief Controls the mapping of the TIM6_DAC1 and TIM7_DAC2 DMA requests onto the DMA1 channels.
  * @note  ENABLE: Remap (TIM6_DAC1 DMA request/DMA1 Channel3, TIM7_DAC2 DMA request/DMA1 Channel4)
  * @retval None
  */
// 宏定义：启用TIM6/TIM7 DAC DMA请求重映射，映射到DMA1通道3和通道4
#define __HAL_AFIO_REMAP_TIM67DACDMA_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief Controls the mapping of the TIM6_DAC1 and TIM7_DAC2 DMA requests onto the DMA1 channels.
  * @note  DISABLE: No remap (TIM6_DAC1 DMA request/DMA2 Channel3, TIM7_DAC2 DMA request/DMA2 Channel4)
  * @retval None
  */
// 宏定义：禁用TIM6/TIM7 DAC DMA请求重映射，使用默认DMA2通道
#define __HAL_AFIO_REMAP_TIM67DACDMA_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief Enable the remapping of TIM12_CH1 and TIM12_CH2.
  * @note  ENABLE: Remap     (TIM12_CH1 on PB12 and TIM12_CH2 on PB13).
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
// 宏定义：启用TIM12重映射，TIM12_CH1映射到PB12，TIM12_CH2映射到PB13
#define __HAL_AFIO_REMAP_TIM12_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief Disable the remapping of TIM12_CH1 and TIM12_CH2.
  * @note  DISABLE: No remap (TIM12_CH1 on PC4  and TIM12_CH2 on PC5).
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
// 宏定义：禁用TIM12重映射，使用默认引脚PC4, PC5
#define __HAL_AFIO_REMAP_TIM12_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP)
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief Miscellaneous features remapping.
  *        This bit is set and cleared by software. It controls miscellaneous features.
  *        The DMA2 channel 5 interrupt position in the vector table.
  *        The timer selection for DAC trigger 3 (TSEL[2:0] = 011, for more details refer to the DAC_CR register).
  * @note  ENABLE: DMA2 channel 5 interrupt is mapped separately at position 60 and TIM15 TRGO event is
  *        selected as DAC Trigger 3, TIM15 triggers TIM1/3.
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
// 宏定义：启用杂项功能重映射，影响DMA2 Ch5中断向量位置和DAC触发源选择
#define __HAL_AFIO_REMAP_MISC_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP)

/**
  * @brief Miscellaneous features remapping.
  *        This bit is set and cleared by software. It controls miscellaneous features.
  *        The DMA2 channel 5 interrupt position in the vector table.
  *        The timer selection for DAC trigger 3 (TSEL[2:0] = 011, for more details refer to the DAC_CR register).
  * @note  DISABLE: DMA2 channel 5 interrupt is mapped with DMA2 channel 4 at position 59, TIM5 TRGO
  *        event is selected as DAC Trigger 3, TIM5 triggers TIM1/3.
  * @note  This bit is available only in high density value line devices.
  * @retval None
  */
// 宏定义：禁用杂项功能重映射，恢复默认配置
#define __HAL_AFIO_REMAP_MISC_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP)
#endif

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIOEx_Private_Macros GPIOEx Private Macros
  * @{
  */
// 根据不同的STM32F1系列型号，定义获取GPIO端口号索引的宏
// 该宏用于将GPIOx（如GPIOA, GPIOB）转换为对应的数字索引（0, 1, 2...），便于数组操作
#if defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :3uL)
#elif defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F103xB) || defined(STM32F105xC) || defined(STM32F107xC)
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :\
                                   ((__GPIOx__) == (GPIOD))? 3uL :4uL)
#elif defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F103xE) || defined(STM32F103xG)
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :\
                                   ((__GPIOx__) == (GPIOD))? 3uL :\
                                   ((__GPIOx__) == (GPIOE))? 4uL :\
                                   ((__GPIOx__) == (GPIOF))? 5uL :6uL)
#endif

// 内部宏：启用AFIO重映射
// 参数 REMAP_PIN: 重映射位的掩码（如 AFIO_MAPR_SPI3_REMAP）
// 逻辑：读-改-写过程，保留SWJ配置位，设置重映射位
#define AFIO_REMAP_ENABLE(REMAP_PIN)       do{ uint32_t tmpreg = AFIO->MAPR; \
                                               tmpreg |= AFIO_MAPR_SWJ_CFG;  \
                                               tmpreg |= REMAP_PIN;          \
                                               AFIO->MAPR = tmpreg;          \
                                               }while(0u)

// 内部宏：禁用AFIO重映射
// 参数 REMAP_PIN: 重映射位的掩码
// 逻辑：读-改-写过程，保留SWJ配置位，清除重映射位
#define AFIO_REMAP_DISABLE(REMAP_PIN)      do{ uint32_t tmpreg = AFIO->MAPR;  \
                                               tmpreg |= AFIO_MAPR_SWJ_CFG;   \
                                               tmpreg &= ~REMAP_PIN;          \
                                               AFIO->MAPR = tmpreg;           \
                                               }while(0u)

// 内部宏：部分启用AFIO重映射（用于具有多个位的重映射配置）
// 参数 REMAP_PIN: 重映射位的值
// 参数 REMAP_PIN_MASK: 重映射位的掩码
// 逻辑：先清除相关位，再设置新值，保留SWJ配置
#define AFIO_REMAP_PARTIAL(REMAP_PIN, REMAP_PIN_MASK) do{ uint32_t tmpreg = AFIO->MAPR; \
                                                          tmpreg &= ~REMAP_PIN_MASK;    \
                                                          tmpreg |= AFIO_MAPR_SWJ_CFG;  \
                                                          tmpreg |= REMAP_PIN;          \
                                                          AFIO->MAPR = tmpreg;          \
                                                          }while(0u)

// 内部宏：配置调试接口(AFIO_DBGAFR)
// 参数 DBGAFR_SWJCFG: SWJ配置值
// 逻辑：清除SWJ配置位，设置新配置
#define AFIO_DBGAFR_CONFIG(DBGAFR_SWJCFG)  do{ uint32_t tmpreg = AFIO->MAPR;     \
                                               tmpreg &= ~AFIO_MAPR_SWJ_CFG_Msk; \
                                               tmpreg |= DBGAFR_SWJCFG;          \
                                               AFIO->MAPR = tmpreg;              \
                                               }while(0u)

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

/** @addtogroup GPIOEx_Exported_Functions
  * @{
  */

/** @addtogroup GPIOEx_Exported_Functions_Group1
  * @{
  */
// 函数声明：配置Eventout输出引脚
// 参数 GPIO_PortSource: GPIO端口源
// 参数 GPIO_PinSource: GPIO引脚源
void HAL_GPIOEx_ConfigEventout(uint32_t GPIO_PortSource, uint32_t GPIO_PinSource);

// 函数声明：启用Eventout输出功能
void HAL_GPIOEx_EnableEventout(void);

// 函数声明：禁用Eventout输出功能
void HAL_GPIOEx_DisableEventout(void);

/**
  * @}
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

#endif /* STM32F1xx_HAL_GPIO_EX_H */
