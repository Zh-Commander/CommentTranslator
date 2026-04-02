/**
  * @brief  启用串行线JTAG配置（不含NJTRST引脚）
  * @note   NONJTRST模式：全SWJ（JTAG-DP + SW-DP）但禁用NJTRST引脚。
  *         此时JTAG接口仍可用，但失去JTAG复位功能，释放了NJTRST引脚供普通IO使用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SWJ_NONJTRST()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_NOJNTRST)

/**
  * @brief  启用串行线JTAG配置（禁用JTAG-DP）
  * @note   NOJTAG模式：禁用JTAG-DP，启用SW-DP。
  *         释放了JTAG占用的多个引脚，仅保留SWDIO和SWCLK两根线用于调试。
  * @retval 无
  */

#define __HAL_AFIO_REMAP_SWJ_NOJTAG()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_JTAGDISABLE)

/**
  * @brief  禁用串行线JTAG配置
  * @note   DISABLE模式：JTAG-DP和SW-DP均被禁用。
  *         释放所有调试引脚作为普通GPIO使用，注意此时将无法通过调试器连接MCU。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SWJ_DISABLE()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_DISABLE)

#if defined(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief  启用SPI3复用功能重映射
  * @note   启用重映射 (SPI3_NSS-I2S3_WS/PA4,  SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12)
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SPI3_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief  禁用SPI3复用功能重映射
  * @note   禁用重映射 (SPI3_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3,  SPI3_MISO/PB4,  SPI3_MOSI-I2S3_SD/PB5)。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SPI3_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_SPI3_REMAP)
#endif

#if defined(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief  控制TIM2_ITR1内部映射
  * @note   映射到USB：将USB OTG SOF (帧起始) 输出连接到TIM2_ITR1，用于校准目的。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_TIM2ITR1_TO_USB() AFIO_REMAP_ENABLE(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief  控制TIM2_ITR1内部映射
  * @note   映射到以太网：将TIM2_ITR1内部连接到以太网PTP输出，用于校准目的。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_TIM2ITR1_TO_ETH() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM2ITR1_IREMAP)
#endif

#if defined(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief  启用以太网PTP PPS功能重映射
  * @note   启用：PTP_PPS信号输出到PB5引脚。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_ETH_PTP_PPS_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief  禁用以太网PTP PPS功能重映射
  * @note   禁用：PTP_PPS信号不输出到PB5引脚。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_ETH_PTP_PPS_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_PTP_PPS_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief  启用TIM9通道重映射
  * @note   启用重映射 (TIM9_CH1 映射到 PE5, TIM9_CH2 映射到 PE6)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM9_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief  禁用TIM9通道重映射
  * @note   禁用重映射 (TIM9_CH1 映射到 PA2, TIM9_CH2 映射到 PA3)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM9_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief  启用TIM10通道重映射
  * @note   启用重映射 (TIM10_CH1 映射到 PF6)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM10_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief  禁用TIM10通道重映射
  * @note   禁用重映射 (TIM10_CH1 映射到 PB8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM10_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM11_REMAP)
/**
  * @brief  启用TIM11通道重映射
  * @note   启用重映射 (TIM11_CH1 映射到 PF7)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM11_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP)

/**
  * @brief  禁用TIM11通道重映射
  * @note   禁用重映射 (TIM11_CH1 映射到 PB9)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM11_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief  启用TIM13通道重映射
  * @note   启用重映射 STM32F100:(TIM13_CH1 映射到 PF8)。其他系列:(TIM13_CH1 映射到 PB0)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM13_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief  禁用TIM13通道重映射
  * @note   禁用重映射 STM32F100:(TIM13_CH1 映射到 PA6)。其他系列:(TIM13_CH1 映射到 PC8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM13_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief  启用TIM14通道重映射
  * @note   启用重映射 STM32F100:(TIM14_CH1 映射到 PB1)。其他系列:(TIM14_CH1 映射到 PF9)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM14_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief  禁用TIM14通道重映射
  * @note   禁用重映射 STM32F100:(TIM14_CH1 映射到 PC9)。其他系列:(TIM14_CH1 映射到 PA7)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM14_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP)
#endif

#if defined(AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief  控制FSMC_NADV信号的使用
  * @note   断开连接：NADV信号不连接。该I/O引脚可被其他外设使用。
  * @retval 无
  */
#define __HAL_AFIO_FSMCNADV_DISCONNECTED() SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief  控制FSMC_NADV信号的使用
  * @note   保持连接：NADV信号连接到输出（默认状态）。
  * @retval 无
  */
#define __HAL_AFIO_FSMCNADV_CONNECTED()    CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief  启用TIM15通道重映射
  * @note   启用重映射 (TIM15_CH1 映射到 PB14, TIM15_CH2 映射到 PB15)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM15_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief  禁用TIM15通道重映射
  * @note   禁用重映射 (TIM15_CH1 映射到 PA2,  TIM15_CH2 映射到 PA3)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM15_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief  启用TIM16通道重映射
  * @note   启用重映射 (TIM16_CH1 映射到 PA6)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM16_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief  禁用TIM16通道重映射
  * @note   禁用重映射 (TIM16_CH1 映射到 PB8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM16_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief  启用TIM17通道重映射
  * @note   启用重映射 (TIM17_CH1 映射到 PA7)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM17_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief  禁用TIM17通道重映射
  * @note   禁用重映射 (TIM17_CH1 映射到 PB9)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM17_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP)
#endif

#if defined(AFIO_MAPR2_CEC_REMAP)

/**
  * @brief  启用CEC功能重映射
  * @note   启用重映射 (CEC 映射到 PB10)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CEC_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP)

/**
  * @brief  禁用CEC功能重映射
  * @note   禁用重映射 (CEC 映射到 PB8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CEC_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief  控制TIM1_CH1和TIM1_CH2 DMA请求映射到DMA1通道
  * @note   启用重映射 (TIM1_CH1 DMA请求映射到 DMA1 Channel6, TIM1_CH2 DMA请求映射到 DMA1 Channel6)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1DMA_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief  控制TIM1_CH1和TIM1_CH2 DMA请求映射到DMA1通道
  * @note   禁用重映射 (TIM1_CH1 DMA请求映射到 DMA1 Channel2, TIM1_CH2 DMA请求映射到 DMA1 Channel3)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1DMA_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道
  * @note   启用重映射 (TIM6_DAC1 DMA请求映射到 DMA1 Channel3, TIM7_DAC2 DMA请求映射到 DMA1 Channel4)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM67DACDMA_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道
  * @note   禁用重映射 (TIM6_DAC1 DMA请求映射到 DMA2 Channel3, TIM7_DAC2 DMA请求映射到 DMA2 Channel4)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM67DACDMA_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief  启用TIM12通道重映射
  * @note   启用重映射 (TIM12_CH1 映射到 PB12, TIM12_CH2 映射到 PB13)。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM12_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief  禁用TIM12通道重映射
  * @note   禁用重映射 (TIM12_CH1 映射到 PC4,  TIM12_CH2 映射到 PC5)。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM12_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP)
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief  杂项功能重映射配置
  *         此位由软件置位和清除，用于控制杂项功能。
  *         包括：DMA2通道5中断在中断向量表中的位置。
  *         DAC触发源3的定时器选择 (TSEL[2:0] = 011, 详情请参考DAC_CR寄存器)。
  * @note   启用：DMA2通道5中断单独映射到位置60，TIM15 TRGO事件被选为DAC触发源3，TIM15触发TIM1/3。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_MISC_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP)

/**
  * @brief  杂项功能重映射配置
  *         此位由软件置位和清除，用于控制杂项功能。
  *         包括：DMA2通道5中断在中断向量表中的位置。
  *         DAC触发源3的定时器选择 (TSEL[2:0] = 011, 详情请参考DAC_CR寄存器)。
  * @note   禁用：DMA2通道5中断与DMA2通道4共同映射到位置59，TIM5 TRGO事件被选为DAC触发源3，TIM5触发TIM1/3。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_MISC_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP)
#endif

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIOEx_Private_Macros GPIOEx 私有宏
  * @{
  */
/* 根据具体的芯片型号定义GPIO端口索引获取宏 */
#if defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)
/* 获取GPIO端口的索引号 (0-3)，用于数组查找或位操作 */
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :3uL)
#elif defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F103xB) || defined(STM32F105xC) || defined(STM32F107xC)
/* 获取GPIO端口的索引号 (0-4) */
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :\
                                   ((__GPIOx__) == (GPIOD))? 3uL :4uL)
#elif defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F103xE) || defined(STM32F103xG)
/* 获取GPIO端口的索引号 (0-6) */
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :\
                                   ((__GPIOx__) == (GPIOD))? 3uL :\
                                   ((__GPIOx__) == (GPIOE))? 4uL :\
                                   ((__GPIOx__) == (GPIOF))? 5uL :6uL)
#endif

/* AFIO重映射使能宏定义 */
/* 参数 REMAP_PIN: 需要使能的重映射引脚定义 */
/* 使用do...while(0)结构确保宏在使用时可以像函数一样安全调用，避免分号问题 */
/* 注意：操作过程中保留了SWJ配置，防止调试接口意外失效 */
#define AFIO_REMAP_ENABLE(REMAP_PIN)       do{ uint32_t tmpreg = AFIO->MAPR; \
                                               tmpreg |= AFIO_MAPR_SWJ_CFG;  \
                                               tmpreg |= REMAP_PIN;          \
                                               AFIO->MAPR = tmpreg;          \
                                               }while(0u)

/* AFIO重映射禁用宏定义 */
/* 参数 REMAP_PIN: 需要禁用的重映射引脚定义 */
/* 使用位操作清除对应的重映射位 */
#define AFIO_REMAP_DISABLE(REMAP_PIN)      do{ uint32_t tmpreg = AFIO->MAPR;  \
                                               tmpreg |= AFIO_MAPR_SWJ_CFG;   \
                                               tmpreg &= ~REMAP_PIN;          \
                                               AFIO->MAPR = tmpreg;           \
                                               }while(0u)

/* AFIO重映射部分重映射宏定义 */
/* 参数 REMAP_PIN: 重映射设置值 */
/* 参数 REMAP_PIN_MASK: 重映射掩码，用于先清除相关位 */
#define AFIO_REMAP_PARTIAL(REMAP_PIN, REMAP_PIN_MASK) do{ uint32_t tmpreg = AFIO->MAPR; \
                                                          tmpreg &= ~REMAP_PIN_MASK;    \
                                                          tmpreg |= AFIO_MAPR_SWJ_CFG;  \
                                                          tmpreg |= REMAP_PIN;          \
                                                          AFIO->MAPR = tmpreg;          \
                                                          }while(0u)

/* AFIO调试配置宏定义 */
/* 参数 DBGAFR_SWJCFG: 调试接口配置值 */
/* 专门用于配置SWJ（JTAG/SWD）调试接口的模式 */
#define AFIO_DBGAFR_CONFIG(DBGAFR_SWJCFG)  do{ uint32_t tmpreg = AFIO->MAPR;     \
                                               tmpreg &= ~AFIO_MAPR_SWJ_CFG_Msk; \
                                               tmpreg |= DBGAFR_SWJCFG;          \
                                               AFIO->MAPR = tmpreg;              \
                                               }while(0u)

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------*/

/** @addtogroup GPIOEx_Exported_Functions
  * @{
  */

/** @addtogroup GPIOEx_Exported_Functions_Group1
  * @{
  */
/* 配置事件输出功能 */
void HAL_GPIOEx_ConfigEventout(uint32_t GPIO_PortSource, uint32_t GPIO_PinSource);
/* 使能事件输出功能 */
void HAL_GPIOEx_EnableEventout(void);
/* 禁用事件输出功能 */
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
