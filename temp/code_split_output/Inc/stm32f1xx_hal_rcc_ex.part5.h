/** @brief  Macro to get the USB clock (USBCLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL PLL clock divided by 1 selected as USB clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV1_5 PLL clock divided by 1.5 selected as USB clock
  */
// 获取USB时钟源的宏定义
// 读取RCC->CFGR寄存器中的RCC_CFGR_USBPRE位，返回当前的USB时钟配置
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_USBPRE)))

#endif /* STM32F102x6 || STM32F102xB || STM32F103x6 || STM32F103xB || STM32F103xE || STM32F103xG */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @brief  Macro to configure the USB OTSclock.
  * @param  __USBCLKSOURCE__ specifies the USB clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as USB OTG FS clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as USB OTG FS clock
  */
// 配置USB OTG FS时钟源的宏定义
// 使用MODIFY_REG宏修改RCC->CFGR寄存器中的RCC_CFGR_OTGFSPRE位
// __USBCLKSOURCE__: 用于设置USB时钟分频系数，可以是2分频或3分频
#define __HAL_RCC_USB_CONFIG(__USBCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_OTGFSPRE, (uint32_t)(__USBCLKSOURCE__))

/** @brief  Macro to get the USB clock (USBCLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV2 PLL clock divided by 2 selected as USB OTG FS clock
  *            @arg @ref RCC_USBCLKSOURCE_PLL_DIV3 PLL clock divided by 3 selected as USB OTG FS clock
  */
// 获取USB OTG FS时钟源的宏定义
// 读取RCC->CFGR寄存器中的RCC_CFGR_OTGFSPRE位
#define __HAL_RCC_GET_USB_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_OTGFSPRE)))

#endif /* STM32F105xC || STM32F107xC */

/** @brief  Macro to configure the ADCx clock (x=1 to 3 depending on devices).
  * @param  __ADCCLKSOURCE__ specifies the ADC clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2 clock divided by 2 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2 clock divided by 4 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2 clock divided by 6 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2 clock divided by 8 selected as ADC clock
  */
// 配置ADC时钟预分频系数的宏定义
// ADC时钟源自PCLK2（APB2总线时钟），需要对其进行分频以满足ADC最大时钟限制（通常为14MHz）
// __ADCCLKSOURCE__: 设置分频系数（2, 4, 6, 8分频）
#define __HAL_RCC_ADC_CONFIG(__ADCCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_ADCPRE, (uint32_t)(__ADCCLKSOURCE__))

/** @brief  Macro to get the ADC clock (ADCxCLK, x=1 to 3 depending on devices).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_ADCPCLK2_DIV2 PCLK2 clock divided by 2 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV4 PCLK2 clock divided by 4 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV6 PCLK2 clock divided by 6 selected as ADC clock
  *            @arg @ref RCC_ADCPCLK2_DIV8 PCLK2 clock divided by 8 selected as ADC clock
  */
// 获取当前ADC时钟预分频系数的宏定义
// 读取RCC->CFGR寄存器中的RCC_CFGR_ADCPRE位
#define __HAL_RCC_GET_ADC_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_ADCPRE)))

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)

/** @addtogroup RCCEx_HSE_Configuration
  * @{
  */

/**
  * @brief  Macro to configure the PLL2 & PLLI2S Predivision factor.
  * @note   Predivision factor can not be changed if PLL2 is used indirectly as system clock
  *         In this case, you have to select another source of the system clock, disable the PLL2 and PLLI2S and
  *         then change the PREDIV2 factor.
  * @param  __HSE_PREDIV2_VALUE__ specifies the PREDIV2 value applied to PLL2 & PLLI2S.
  *         This parameter must be a number between RCC_HSE_PREDIV2_DIV1 and RCC_HSE_PREDIV2_DIV16.
  */
// 配置PREDIV2预分频因子的宏定义（适用于互联型器件F105/F107）
// PREDIV2用于对HSE振荡器时钟进行分频，作为PLL2和PLL3的输入时钟
// __HSE_PREDIV2_VALUE__: 分频系数，范围1到16分频
#define __HAL_RCC_HSE_PREDIV2_CONFIG(__HSE_PREDIV2_VALUE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PREDIV2, (uint32_t)(__HSE_PREDIV2_VALUE__))

/**
  * @brief  Macro to get prediv2 factor for PLL2 & PLL3.
  */
// 获取当前PREDIV2预分频因子的宏定义
#define __HAL_RCC_HSE_GET_PREDIV2() READ_BIT(RCC->CFGR2, RCC_CFGR2_PREDIV2)

/**
  * @}
  */

/** @addtogroup RCCEx_PLLI2S_Configuration
  * @{
  */

/** @brief Macros to enable the main PLL2.
  * @note   After enabling the main PLL2, the application software should wait on
  *         PLL2RDY flag to be set indicating that PLL2 clock is stable and can
  *         be used as system clock source.
  * @note   The main PLL2 is disabled by hardware when entering STOP and STANDBY modes.
  */
// 使能PLL2的宏定义
// 使用位带操作（Bit-Banding）直接设置RCC_CR寄存器中的PLL2ON位
// 注意：使能后需等待PLL2RDY标志位置1，表示PLL2输出稳定
#define __HAL_RCC_PLL2_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = ENABLE)

/** @brief Macros to disable the main PLL2.
  * @note   The main PLL2 can not be disabled if it is used indirectly as system clock source
  * @note   The main main PLL2 is disabled by hardware when entering STOP and STANDBY modes.
  */
// 禁用PLL2的宏定义
// 使用位带操作直接清除RCC_CR寄存器中的PLL2ON位
// 注意：如果PLL2被用作系统时钟源，则不能被禁用
#define __HAL_RCC_PLL2_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLL2ON_BB = DISABLE)

/** @brief macros to configure the main PLL2 multiplication factor.
  * @note   This function must be used only when the main PLL2 is disabled.
  *
  * @param  __PLL2MUL__ specifies the multiplication factor for PLL2 VCO output clock
  *          This parameter can be one of the following values:
  *             @arg @ref RCC_PLL2_MUL8 PLL2VCO = PLL2 clock entry x 8
  *             @arg @ref RCC_PLL2_MUL9 PLL2VCO = PLL2 clock entry x 9
  *             @arg @ref RCC_PLL2_MUL10 PLL2VCO = PLL2 clock entry x 10
  *             @arg @ref RCC_PLL2_MUL11 PLL2VCO = PLL2 clock entry x 11
  *             @arg @ref RCC_PLL2_MUL12 PLL2VCO = PLL2 clock entry x 12
  *             @arg @ref RCC_PLL2_MUL13 PLL2VCO = PLL2 clock entry x 13
  *             @arg @ref RCC_PLL2_MUL14 PLL2VCO = PLL2 clock entry x 14
  *             @arg @ref RCC_PLL2_MUL16 PLL2VCO = PLL2 clock entry x 16
  *             @arg @ref RCC_PLL2_MUL20 PLL2VCO = PLL2 clock entry x 20
  *
  */
// 配置PLL2倍频因子的宏定义
// __PLL2MUL__: 倍频系数，决定PLL2 VCO的输出频率
// 注意：必须在PLL2禁用时配置
#define __HAL_RCC_PLL2_CONFIG(__PLL2MUL__)\
          MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PLL2MUL,(__PLL2MUL__))

/**
  * @}
  */

/** @defgroup RCCEx_I2S_Configuration I2S Configuration
  * @brief  Macros to configure clock source of I2S peripherals.
  * @{
  */

/** @brief  Macro to configure the I2S2 clock.
  * @param  __I2S2CLKSOURCE__ specifies the I2S2 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 配置I2S2时钟源的宏定义
// I2S音频接口通常需要精确的时钟频率，可以选择系统时钟或PLLI2S VCO时钟
#define __HAL_RCC_I2S2_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S2SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  Macro to get the I2S2 clock (I2S2CLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2S2CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S2CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 获取I2S2当前时钟源配置的宏定义
#define __HAL_RCC_GET_I2S2_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S2SRC)))

/** @brief  Macro to configure the I2S3 clock.
  * @param  __I2S2CLKSOURCE__ specifies the I2S3 clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 配置I2S3时钟源的宏定义
#define __HAL_RCC_I2S3_CONFIG(__I2S2CLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR2, RCC_CFGR2_I2S3SRC, (uint32_t)(__I2S2CLKSOURCE__))

/** @brief  Macro to get the I2S3 clock (I2S3CLK).
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_I2S3CLKSOURCE_SYSCLK system clock selected as I2S3 clock entry
  *            @arg @ref RCC_I2S3CLKSOURCE_PLLI2S_VCO PLLI2S VCO clock selected as I2S3 clock entry
  */
// 获取I2S3当前时钟源配置的宏定义
#define __HAL_RCC_GET_I2S3_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR2, RCC_CFGR2_I2S3SRC)))

/**
  * @}
  */

#endif /* STM32F105xC || STM32F107xC */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/
/** @addtogroup RCCEx_Exported_Functions
  * @{
  */

/** @addtogroup RCCEx_Exported_Functions_Group1
  * @{
  */

// 初始化外设时钟的函数
// PeriphClkInit: 指向RCC_PeriphCLKInitTypeDef结构体的指针，包含外设时钟配置信息
HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);

// 获取当前外设时钟配置的函数
// PeriphClkInit: 指向RCC_PeriphCLKInitTypeDef结构体的指针，用于返回配置信息
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);

// 获取特定外设时钟频率的函数
// PeriphClk: 外设时钟标识，返回该外设的时钟频率（单位：Hz）
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);

/**
  * @}
  */

#if defined(STM32F105xC) || defined(STM32F107xC)
/** @addtogroup RCCEx_Exported_Functions_Group2
  * @{
  */
// 使能PLLI2S的函数（仅互联型设备支持）
// PLLI2SInit: 指向RCC_PLLI2SInitTypeDef结构体的指针，包含PLLI2S配置信息
HAL_StatusTypeDef HAL_RCCEx_EnablePLLI2S(RCC_PLLI2SInitTypeDef  *PLLI2SInit);

// 禁用PLLI2S的函数
HAL_StatusTypeDef HAL_RCCEx_DisablePLLI2S(void);

/**
  * @}
  */

/** @addtogroup RCCEx_Exported_Functions_Group3
  * @{
  */
// 使能PLL2的函数（仅互联型设备支持）
// PLL2Init: 指向RCC_PLL2InitTypeDef结构体的指针，包含PLL2配置信息
HAL_StatusTypeDef HAL_RCCEx_EnablePLL2(RCC_PLL2InitTypeDef  *PLL2Init);

// 禁用PLL2的函数
HAL_StatusTypeDef HAL_RCCEx_DisablePLL2(void);

/**
  * @}
  */
#endif /* STM32F105xC || STM32F107xC */

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

#endif /* __STM32F1xx_HAL_RCC_EX_H */
