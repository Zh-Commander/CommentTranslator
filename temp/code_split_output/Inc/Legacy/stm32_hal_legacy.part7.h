#if defined(STM32L0) || defined(STM32L4)
/** @defgroup HAL_COMP_Aliased_Functions HAL COMP别名函数（用于保持旧版兼容性）
  * @{
  */
/* 将旧版中断启动函数映射为新版普通启动函数，因为EXTI事件或中断配置已移至HAL_COMP_Init()中处理 */
#define HAL_COMP_Start_IT       HAL_COMP_Start 
/* 将旧版中断停止函数映射为新版普通停止函数，因为EXTI事件或中断配置已移至HAL_COMP_Init()中处理 */
#define HAL_COMP_Stop_IT        HAL_COMP_Stop  
/**
  * @}
  */
#endif

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC别名宏（用于保持旧版兼容性）
  * @{
  */

/* 检查DAC波形生成参数是否合法 */
/* 参数说明：WAVE可以是 DAC_WAVE_NONE(无波形), DAC_WAVE_NOISE(噪声), DAC_WAVE_TRIANGLE(三角波) */
#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_WAVE_NONE) || \
                           ((WAVE) == DAC_WAVE_NOISE)|| \
                           ((WAVE) == DAC_WAVE_TRIANGLE))

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Macros HAL FLASH别名宏（用于保持旧版兼容性）
  * @{
  */

/* 旧版写保护区域检查宏，映射为新版IS_OB_WRPAREA */
#define IS_WRPAREA          IS_OB_WRPAREA
/* 旧版编程类型检查宏，映射为新版IS_FLASH_TYPEPROGRAM */
#define IS_TYPEPROGRAM      IS_FLASH_TYPEPROGRAM
/* 旧版Flash编程类型检查宏，映射为新版IS_FLASH_TYPEPROGRAM */
#define IS_TYPEPROGRAMFLASH IS_FLASH_TYPEPROGRAM
/* 旧版擦除类型检查宏，映射为新版IS_FLASH_TYPEERASE */
#define IS_TYPEERASE        IS_FLASH_TYPEERASE
/* 旧版扇区数量检查宏，映射为新版IS_FLASH_NBSECTORS */
#define IS_NBSECTORS        IS_FLASH_NBSECTORS
/* 旧版看门狗源检查宏，映射为新版IS_OB_IWDG_SOURCE */
#define IS_OB_WDG_SOURCE    IS_OB_IWDG_SOURCE

/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Macros HAL I2C别名宏（用于保持旧版兼容性）
  * @{
  */

/* 复位I2C CR2寄存器 */
#define __HAL_I2C_RESET_CR2             I2C_RESET_CR2
/* 产生I2C起始信号 */
#define __HAL_I2C_GENERATE_START        I2C_GENERATE_START
#if defined(STM32F1)
/* STM32F1系列频率范围宏定义 */
#define __HAL_I2C_FREQ_RANGE            I2C_FREQRANGE
#else
/* 非STM32F1系列频率范围宏定义 */
#define __HAL_I2C_FREQ_RANGE            I2C_FREQ_RANGE
#endif /* STM32F1 */
/* 计算I2C上升时间 */
#define __HAL_I2C_RISE_TIME             I2C_RISE_TIME
/* 设置I2C标准速度模式 */
#define __HAL_I2C_SPEED_STANDARD        I2C_SPEED_STANDARD
/* 设置I2C快速速度模式 */
#define __HAL_I2C_SPEED_FAST            I2C_SPEED_FAST
/* I2C速度设置宏 */
#define __HAL_I2C_SPEED                 I2C_SPEED
/* I2C 7位地址写模式 */
#define __HAL_I2C_7BIT_ADD_WRITE        I2C_7BIT_ADD_WRITE
/* I2C 7位地址读模式 */
#define __HAL_I2C_7BIT_ADD_READ         I2C_7BIT_ADD_READ
/* I2C 10位地址处理 */
#define __HAL_I2C_10BIT_ADDRESS         I2C_10BIT_ADDRESS
/* I2C 10位地址头写模式 */
#define __HAL_I2C_10BIT_HEADER_WRITE    I2C_10BIT_HEADER_WRITE
/* I2C 10位地址头读模式 */
#define __HAL_I2C_10BIT_HEADER_READ     I2C_10BIT_HEADER_READ
/* 获取I2C内存地址高字节 */
#define __HAL_I2C_MEM_ADD_MSB           I2C_MEM_ADD_MSB
/* 获取I2C内存地址低字节 */
#define __HAL_I2C_MEM_ADD_LSB           I2C_MEM_ADD_LSB
/* I2C频率范围定义 */
#define __HAL_I2C_FREQRANGE             I2C_FREQRANGE
/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Macros HAL I2S别名宏（用于保持旧版兼容性）
  * @{
  */

/* 检查是否为I2S实例 */
#define IS_I2S_INSTANCE                 IS_I2S_ALL_INSTANCE
/* 检查是否为扩展I2S实例 */
#define IS_I2S_INSTANCE_EXT             IS_I2S_ALL_INSTANCE_EXT

#if defined(STM32H7)
/* STM32H7系列清除I2S帧错误标志 */
#define __HAL_I2S_CLEAR_FREFLAG       __HAL_I2S_CLEAR_TIFREFLAG
#endif

/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Macros HAL IRDA别名宏（用于保持旧版兼容性）
  * @{
  */

/* 禁用IRDA外设 */
#define __IRDA_DISABLE                  __HAL_IRDA_DISABLE
/* 使能IRDA外设 */
#define __IRDA_ENABLE                   __HAL_IRDA_ENABLE

/* 获取IRDA时钟源 */
#define __HAL_IRDA_GETCLOCKSOURCE       IRDA_GETCLOCKSOURCE
/* IRDA掩码计算 */
#define __HAL_IRDA_MASK_COMPUTATION     IRDA_MASK_COMPUTATION
/* 获取IRDA时钟源（旧版命名） */
#define __IRDA_GETCLOCKSOURCE           IRDA_GETCLOCKSOURCE
/* IRDA掩码计算（旧版命名） */
#define __IRDA_MASK_COMPUTATION         IRDA_MASK_COMPUTATION

/* 检查IRDA单比特采样配置 */
#define IS_IRDA_ONEBIT_SAMPLE           IS_IRDA_ONE_BIT_SAMPLE


/**
  * @}
  */


/** @defgroup HAL_IWDG_Aliased_Macros HAL IWDG别名宏（用于保持旧版兼容性）
  * @{
  */
/* 使能独立看门狗写访问权限 */
#define __HAL_IWDG_ENABLE_WRITE_ACCESS  IWDG_ENABLE_WRITE_ACCESS
/* 禁用独立看门狗写访问权限 */
#define __HAL_IWDG_DISABLE_WRITE_ACCESS IWDG_DISABLE_WRITE_ACCESS
/**
  * @}
  */


/** @defgroup HAL_LPTIM_Aliased_Macros HAL LPTIM别名宏（用于保持旧版兼容性）
  * @{
  */

/* 使能LPTIM中断（旧版命名映射为新版IT宏） */
#define __HAL_LPTIM_ENABLE_INTERRUPT    __HAL_LPTIM_ENABLE_IT
/* 禁用LPTIM中断（旧版命名映射为新版IT宏） */
#define __HAL_LPTIM_DISABLE_INTERRUPT   __HAL_LPTIM_DISABLE_IT
/* 获取LPTIM中断状态（旧版命名映射为新版SOURCE宏） */
#define __HAL_LPTIM_GET_ITSTATUS        __HAL_LPTIM_GET_IT_SOURCE

/**
  * @}
  */


/** @defgroup HAL_OPAMP_Aliased_Macros HAL OPAMP别名宏（用于保持旧版兼容性）
  * @{
  */
/* 运放CSR寄存器：运放电源控制位 */
#define __OPAMP_CSR_OPAXPD                OPAMP_CSR_OPAXPD
/* 运放CSR寄存器：开关S3选择位 */
#define __OPAMP_CSR_S3SELX                OPAMP_CSR_S3SELX
/* 运放CSR寄存器：开关S4选择位 */
#define __OPAMP_CSR_S4SELX                OPAMP_CSR_S4SELX
/* 运放CSR寄存器：开关S5选择位 */
#define __OPAMP_CSR_S5SELX                OPAMP_CSR_S5SELX
/* 运放CSR寄存器：开关S6选择位 */
#define __OPAMP_CSR_S6SELX                OPAMP_CSR_S6SELX
/* 运放CSR寄存器：低位校准位 */
#define __OPAMP_CSR_OPAXCAL_L             OPAMP_CSR_OPAXCAL_L
/* 运放CSR寄存器：高位校准位 */
#define __OPAMP_CSR_OPAXCAL_H             OPAMP_CSR_OPAXCAL_H
/* 运放CSR寄存器：低功耗模式位 */
#define __OPAMP_CSR_OPAXLPM               OPAMP_CSR_OPAXLPM
/* 运放CSR寄存器：所有开关掩码 */
#define __OPAMP_CSR_ALL_SWITCHES          OPAMP_CSR_ALL_SWITCHES
/* 运放CSR寄存器：模拟开关选择 */
#define __OPAMP_CSR_ANAWSELX              OPAMP_CSR_ANAWSELX
/* 运放CSR寄存器：校准输出位 */
#define __OPAMP_CSR_OPAXCALOUT            OPAMP_CSR_OPAXCALOUT
/* 运放偏移修剪位位置定义 */
#define __OPAMP_OFFSET_TRIM_BITSPOSITION  OPAMP_OFFSET_TRIM_BITSPOSITION
/* 运放偏移修剪设置 */
#define __OPAMP_OFFSET_TRIM_SET           OPAMP_OFFSET_TRIM_SET

/**
  * @}
  */


/** @defgroup HAL_PWR_Aliased_Macros HAL PWR别名宏（用于保持旧版兼容性）
  * @{
  */
/* 禁用PVD（可编程电压检测器）事件 */
#define __HAL_PVD_EVENT_DISABLE                                  __HAL_PWR_PVD_EXTI_DISABLE_EVENT
/* 使能PVD事件 */
#define __HAL_PVD_EVENT_ENABLE                                   __HAL_PWR_PVD_EXTI_ENABLE_EVENT
/* 禁用PVD EXTI下降沿触发 */
#define __HAL_PVD_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
/* 使能PVD EXTI下降沿触发 */
#define __HAL_PVD_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
/* 禁用PVD EXTI上升沿触发 */
#define __HAL_PVD_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
/* 使能PVD EXTI上升沿触发 */
#define __HAL_PVD_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
/* 禁用PVM（外设电压监测）事件 */
#define __HAL_PVM_EVENT_DISABLE                                  __HAL_PWR_PVM_EVENT_DISABLE
/* 使能PVM事件 */
#define __HAL_PVM_EVENT_ENABLE                                   __HAL_PWR_PVM_EVENT_ENABLE
/* 禁用PVM EXTI下降沿触发 */
#define __HAL_PVM_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_DISABLE
/* 使能PVM EXTI下降沿触发 */
#define __HAL_PVM_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_ENABLE
/* 禁用PVM EXTI上升沿触发 */
#define __HAL_PVM_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVM_EXTI_RISINGTRIGGER_DISABLE
/* 使能PVM EXTI上升沿触发 */
#define __HAL_PVM_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVM_EXTI_RISINGTRIGGER_ENABLE
/* 禁用内部唤醒线路 */
#define __HAL_PWR_INTERNALWAKEUP_DISABLE                         HAL_PWREx_DisableInternalWakeUpLine
/* 使能内部唤醒线路 */
#define __HAL_PWR_INTERNALWAKEUP_ENABLE                          HAL_PWREx_EnableInternalWakeUpLine
/* 禁用上下拉配置 */
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_DISABLE                    HAL_PWREx_DisablePullUpPullDownConfig
/* 使能上下拉配置 */
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_ENABLE                     HAL_PWREx_EnablePullUpPullDownConfig
/* 清除PVD EXTI边沿触发（同时禁用上升沿和下降沿） */
#define __HAL_PWR_PVD_EXTI_CLEAR_EGDE_TRIGGER()                  do { __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE(); \
                                                                      __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); \
                                                                    } while(0)
/* 禁用PVD EXTI事件 */
#define __HAL_PWR_PVD_EXTI_EVENT_DISABLE                         __HAL_PWR_PVD_EXTI_DISABLE_EVENT
/* 使能PVD EXTI事件 */
#define __HAL_PWR_PVD_EXTI_EVENT_ENABLE                          __HAL_PWR_PVD_EXTI_ENABLE_EVENT
/* 禁用PVD EXTI下降沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_DISABLE                __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
/* 使能PVD EXTI下降沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_ENABLE                 __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
/* 禁用PVD EXTI上升沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_DISABLE                 __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
/* 使能PVD EXTI上升沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_ENABLE                  __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
/* 设置PVD EXTI下降沿触发 */
#define __HAL_PWR_PVD_EXTI_SET_FALLING_EGDE_TRIGGER              __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
/* 设置PVD EXTI上升沿触发 */
#define __HAL_PWR_PVD_EXTI_SET_RISING_EDGE_TRIGGER               __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
/* 禁用所有PVM（外设电压监测器1-4） */
#define __HAL_PWR_PVM_DISABLE()                                  do { HAL_PWREx_DisablePVM1();HAL_PWREx_DisablePVM2(); \
                                                                      HAL_PWREx_DisablePVM3();HAL_PWREx_DisablePVM4(); \
                                                                    } while(0)
/* 使能所有PVM（外设电压监测器1-4） */
#define __HAL_PWR_PVM_ENABLE()                                   do { HAL_PWREx_EnablePVM1();HAL_PWREx_EnablePVM2(); \
                                                                      HAL_PWREx_EnablePVM3();HAL_PWREx_EnablePVM4(); \
                                                                    } while(0)
/* 禁用SRAM2内容保留功能 */
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_DISABLE                  HAL_PWREx_DisableSRAM2ContentRetention
/* 使能SRAM2内容保留功能 */
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_ENABLE                   HAL_PWREx_EnableSRAM2ContentRetention
/* 禁用VDDIO2电源 */
#define __HAL_PWR_VDDIO2_DISABLE                                 HAL_PWREx_DisableVddIO2
/* 使能VDDIO2电源 */
#define __HAL_PWR_VDDIO2_ENABLE                                  HAL_PWREx_EnableVddIO2
/* 清除VDDIO2 EXTI边沿触发 */
#define __HAL_PWR_VDDIO2_EXTI_CLEAR_EGDE_TRIGGER                 __HAL_PWR_VDDIO2_EXTI_DISABLE_FALLING_EDGE
/* 设置VDDIO2 EXTI下降沿触发 */
#define __HAL_PWR_VDDIO2_EXTI_SET_FALLING_EGDE_TRIGGER           __HAL_PWR_VDDIO2_EXTI_ENABLE_FALLING_EDGE
/* 禁用VDDUSB电源 */
#define __HAL_PWR_VDDUSB_DISABLE                                 HAL_PWREx_DisableVddUSB
/* 使能VDDUSB电源 */
#define __HAL_PWR_VDDUSB_ENABLE                                  HAL_PWREx_EnableVddUSB

#if defined (STM32F4)
/* STM32F4系列：使能PVD EXTI中断，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_ENABLE_IT(PWR_EXTI_LINE_PVD)         __HAL_PWR_PVD_EXTI_ENABLE_IT()
/* STM32F4系列：禁用PVD EXTI中断，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_DISABLE_IT(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_DISABLE_IT()
/* STM32F4系列：获取PVD EXTI标志，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_GET_FLAG(PWR_EXTI_LINE_PVD)          __HAL_PWR_PVD_EXTI_GET_FLAG()
/* STM32F4系列：清除PVD EXTI标志，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_CLEAR_FLAG(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_CLEAR_FLAG()
/* STM32F4系列：产生PVD软件中断，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_GENERATE_SWIT(PWR_EXTI_LINE_PVD)     __HAL_PWR_PVD_EXTI_GENERATE_SWIT()
#else
/* 非STM32F4系列：清除PVD EXTI标志 */
#define __HAL_PVD_EXTI_CLEAR_FLAG                                __HAL_PWR_PVD_EXTI_CLEAR_FLAG
/* 非STM32F4系列：禁用PVD EXTI中断 */
#define __HAL_PVD_EXTI_DISABLE_IT                                __HAL_PWR_PVD_EXTI_DISABLE_IT
/* 非STM32F4系列：使能PVD EXTI中断 */
#define __HAL_PVD_EXTI_ENABLE_IT                                 __HAL_PWR_PVD_EXTI_ENABLE_IT
/* 非STM32F4系列：产生PVD软件中断 */
#define __HAL_PVD_EXTI_GENERATE_SWIT                             __HAL_PWR_PVD_EXTI_GENERATE_SWIT
/* 非STM32F4系列：获取PVD EXTI标志 */
#define __HAL_PVD_EXTI_GET_FLAG                                  __HAL_PWR_PVD_EXTI_GET_FLAG
#endif /* STM32F4 */
/**
  * @}
  */


/** @defgroup HAL_RCC_Aliased HAL RCC别名宏（用于保持旧版兼容性）
  * @{
  */

/* 停机模式唤醒时钟选择MSI */
#define RCC_StopWakeUpClock_MSI     RCC_STOP_WAKEUPCLOCK_MSI
/* 停机模式唤醒时钟选择HSI */
#define RCC_StopWakeUpClock_HSI     RCC_STOP_WAKEUPCLOCK_HSI

/* 时钟安全系统(CSS)回调函数别名，修正旧版拼写错误(CCSCallback -> CSSCallback) */
#define HAL_RCC_CCSCallback HAL_RCC_CSSCallback
/* RC48使能缓冲命令：根据参数使能或禁用HSI48 VREFINT缓冲 */
#define HAL_RC48_EnableBuffer_Cmd(cmd) (((cmd)==ENABLE) ? \
                                        HAL_RCCEx_EnableHSI48_VREFINT() : HAL_RCCEx_DisableHSI48_VREFINT())
