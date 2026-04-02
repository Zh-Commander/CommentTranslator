/** @defgroup HAL_RTC_Aliased_Functions HAL RTC Aliased Functions maintained for legacy purpose
  * @{
  */
/* 以下宏定义用于保持旧版本HAL库函数名的兼容性，方便旧工程迁移 */
#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
/* 设置启动硬件密钥（旧名称映射到新名称） */
#define HAL_RTCEx_SetBoothardwareKey            HAL_RTCEx_LockBootHardwareKey
/* 使能备份域块访问 */
#define HAL_RTCEx_BKUPBlock_Enable              HAL_RTCEx_BKUPBlock
/* 禁用备份域块访问 */
#define HAL_RTCEx_BKUPBlock_Disable             HAL_RTCEx_BKUPUnblock
/* 擦除保密设备配置 */
#define HAL_RTCEx_Erase_SecretDev_Conf          HAL_RTCEx_ConfigEraseDeviceSecrets
#endif /* STM32H5 || STM32WBA || STM32H7RS */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Functions HAL SMBUS Aliased Functions maintained for legacy purpose
  * @{
  */
/* SMBUS（系统管理总线）相关函数别名 */
/* 从机监听中断使能 */
#define HAL_SMBUS_Slave_Listen_IT          HAL_SMBUS_EnableListen_IT
/* 从机地址回调函数 */
#define HAL_SMBUS_SlaveAddrCallback        HAL_SMBUS_AddrCallback
/* 从机监听完成回调函数 */
#define HAL_SMBUS_SlaveListenCpltCallback  HAL_SMBUS_ListenCpltCallback
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Functions HAL SPI Aliased Functions maintained for legacy purpose
  * @{
  */
/* SPI（串行外设接口）相关函数别名 */
/* 刷新SPI接收FIFO */
#define HAL_SPI_FlushRxFifo                HAL_SPIEx_FlushRxFifo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Functions HAL TIM Aliased Functions maintained for legacy purpose
  * @{
  */
/* TIM（定时器）相关函数别名 */
/* DMA延时脉冲完成回调 */
#define HAL_TIM_DMADelayPulseCplt                       TIM_DMADelayPulseCplt
/* DMA错误处理 */
#define HAL_TIM_DMAError                                TIM_DMAError
/* DMA捕获完成回调 */
#define HAL_TIM_DMACaptureCplt                          TIM_DMACaptureCplt
/* 定时器扩展DMA通信完成回调 */
#define HAL_TIMEx_DMACommutationCplt                    TIMEx_DMACommutationCplt
#if defined(STM32H7) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || defined(STM32L4)
/* 从模式同步配置（旧名称映射） */
#define HAL_TIM_SlaveConfigSynchronization              HAL_TIM_SlaveConfigSynchro
/* 从模式同步配置（中断模式，旧名称映射） */
#define HAL_TIM_SlaveConfigSynchronization_IT           HAL_TIM_SlaveConfigSynchro_IT
/* 交换回调函数 */
#define HAL_TIMEx_CommutationCallback                   HAL_TIMEx_CommutCallback
/* 配置交换事件 */
#define HAL_TIMEx_ConfigCommutationEvent                HAL_TIMEx_ConfigCommutEvent
/* 配置交换事件（中断模式） */
#define HAL_TIMEx_ConfigCommutationEvent_IT             HAL_TIMEx_ConfigCommutEvent_IT
/* 配置交换事件（DMA模式） */
#define HAL_TIMEx_ConfigCommutationEvent_DMA            HAL_TIMEx_ConfigCommutEvent_DMA
#endif /* STM32H7 || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Functions HAL UART Aliased Functions maintained for legacy purpose
  * @{
  */
/* UART（通用异步收发传输器）相关函数别名 */
/* 唤醒回调函数 */
#define HAL_UART_WakeupCallback HAL_UARTEx_WakeupCallback
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Functions HAL LTDC Aliased Functions maintained for legacy purpose
  * @{
  */
/* LTDC（LCD-TFT控制器）相关函数别名 */
/* 行事件回调函数（修正了旧版本拼写错误Even -> Event） */
#define HAL_LTDC_LineEvenCallback HAL_LTDC_LineEventCallback
/* 重新加载配置（修正了旧版本拼写错误Relaod -> Reload） */
#define HAL_LTDC_Relaod           HAL_LTDC_Reload
/* 从视频配置初始化结构体 */
#define HAL_LTDC_StructInitFromVideoConfig  HAL_LTDCEx_StructInitFromVideoConfig
/* 从适配命令配置初始化结构体 */
#define HAL_LTDC_StructInitFromAdaptedCommandConfig  HAL_LTDCEx_StructInitFromAdaptedCommandConfig
/**
  * @}
  */


/** @defgroup HAL_PPP_Aliased_Functions HAL PPP Aliased Functions maintained for legacy purpose
  * @{
  */

/**
  * @}
  */

/* Exported macros ------------------------------------------------------------*/
/* 导出的宏定义 ---------------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Macros HAL CRYP Aliased Macros maintained for legacy purpose
  * @{
  */
/* AES（高级加密标准）相关宏别名，现已统一到CRYP（加密处理器）模块 */
/* 加密完成中断 */
#define AES_IT_CC                      CRYP_IT_CC
/* 错误中断 */
#define AES_IT_ERR                     CRYP_IT_ERR
/* 加密完成标志 */
#define AES_FLAG_CCF                   CRYP_FLAG_CCF
/**
  * @}
  */

/** @defgroup HAL_Aliased_Macros HAL Generic Aliased Macros maintained for legacy purpose
  * @{
  */
/* 通用HAL库宏别名，主要涉及系统配置(SYSCFG)相关功能 */
/* 获取启动模式 */
#define __HAL_GET_BOOT_MODE                   __HAL_SYSCFG_GET_BOOT_MODE
/* 重映射存储器到Flash */
#define __HAL_REMAPMEMORY_FLASH               __HAL_SYSCFG_REMAPMEMORY_FLASH
/* 重映射存储器到系统Flash（Bootloader区） */
#define __HAL_REMAPMEMORY_SYSTEMFLASH         __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH
/* 重映射存储器到SRAM */
#define __HAL_REMAPMEMORY_SRAM                __HAL_SYSCFG_REMAPMEMORY_SRAM
/* 重映射存储器到FMC */
#define __HAL_REMAPMEMORY_FMC                 __HAL_SYSCFG_REMAPMEMORY_FMC
/* 重映射存储器到FMC SDRAM */
#define __HAL_REMAPMEMORY_FMC_SDRAM           __HAL_SYSCFG_REMAPMEMORY_FMC_SDRAM
/* 重映射存储器到FSMC */
#define __HAL_REMAPMEMORY_FSMC                __HAL_SYSCFG_REMAPMEMORY_FSMC
/* 重映射存储器到QSPI */
#define __HAL_REMAPMEMORY_QUADSPI             __HAL_SYSCFG_REMAPMEMORY_QUADSPI
/* FMC存储块配置 */
#define __HAL_FMC_BANK                        __HAL_SYSCFG_FMC_BANK
/* 获取标志状态 */
#define __HAL_GET_FLAG                        __HAL_SYSCFG_GET_FLAG
/* 清除标志状态 */
#define __HAL_CLEAR_FLAG                      __HAL_SYSCFG_CLEAR_FLAG
/* 使能内部参考电压输出 */
#define __HAL_VREFINT_OUT_ENABLE              __HAL_SYSCFG_VREFINT_OUT_ENABLE
/* 禁用内部参考电压输出 */
#define __HAL_VREFINT_OUT_DISABLE             __HAL_SYSCFG_VREFINT_OUT_DISABLE
/* 使能SRAM2写保护（0到31字节） */
#define __HAL_SYSCFG_SRAM2_WRP_ENABLE         __HAL_SYSCFG_SRAM2_WRP_0_31_ENABLE

/* 参考电压就绪标志 */
#define SYSCFG_FLAG_VREF_READY                SYSCFG_FLAG_VREFINT_READY
/* RC48标志映射到RCC标志HSI48 */
#define SYSCFG_FLAG_RC48                      RCC_FLAG_HSI48
/* 快速模式Plus配置检查 */
#define IS_SYSCFG_FASTMODEPLUS_CONFIG         IS_I2C_FASTMODEPLUS
/* UFB模式位号 */
#define UFB_MODE_BitNumber                    UFB_MODE_BIT_NUMBER
/* 比较器掉电位号 */
#define CMP_PD_BitNumber                      CMP_PD_BIT_NUMBER

/**
  * @}
  */


/** @defgroup HAL_ADC_Aliased_Macros HAL ADC Aliased Macros maintained for legacy purpose
  * @{
  */
/* ADC（模数转换器）相关宏别名 */
/* 使能ADC */
#define __ADC_ENABLE                                     __HAL_ADC_ENABLE
/* 禁用ADC */
#define __ADC_DISABLE                                    __HAL_ADC_DISABLE
/* ADC使能条件检查 */
#define __HAL_ADC_ENABLING_CONDITIONS                    ADC_ENABLING_CONDITIONS
/* ADC禁用条件检查 */
#define __HAL_ADC_DISABLING_CONDITIONS                   ADC_DISABLING_CONDITIONS
/* 检查ADC是否已使能 */
#define __HAL_ADC_IS_ENABLED                             ADC_IS_ENABLE
/* 检查ADC是否已使能（旧名称） */
#define __ADC_IS_ENABLED                                 ADC_IS_ENABLE
/* 检查是否为规则组的软件启动 */
#define __HAL_ADC_IS_SOFTWARE_START_REGULAR              ADC_IS_SOFTWARE_START_REGULAR
/* 检查是否为注入组的软件启动 */
#define __HAL_ADC_IS_SOFTWARE_START_INJECTED             ADC_IS_SOFTWARE_START_INJECTED
/* 检查规则组和注入组转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED
/* 检查规则组转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR          ADC_IS_CONVERSION_ONGOING_REGULAR
/* 检查注入组转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING_INJECTED         ADC_IS_CONVERSION_ONGOING_INJECTED
/* 检查转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING                  ADC_IS_CONVERSION_ONGOING
/* 清除错误代码 */
#define __HAL_ADC_CLEAR_ERRORCODE                        ADC_CLEAR_ERRORCODE

/* 获取分辨率 */
#define __HAL_ADC_GET_RESOLUTION                         ADC_GET_RESOLUTION
/* 注入序列寄存器设置 */
#define __HAL_ADC_JSQR_RK                                ADC_JSQR_RK
/* 看门狗1通道配置移位 */
#define __HAL_ADC_CFGR_AWD1CH                            ADC_CFGR_AWD1CH_SHIFT
/* 看门狗2/3控制寄存器配置 */
#define __HAL_ADC_CFGR_AWD23CR                           ADC_CFGR_AWD23CR
/* 注入组自动转换配置 */
#define __HAL_ADC_CFGR_INJECT_AUTO_CONVERSION            ADC_CFGR_INJECT_AUTO_CONVERSION
/* 注入组上下文队列配置 */
#define __HAL_ADC_CFGR_INJECT_CONTEXT_QUEUE              ADC_CFGR_INJECT_CONTEXT_QUEUE
/* 注入组不连续模式配置 */
#define __HAL_ADC_CFGR_INJECT_DISCCONTINUOUS             ADC_CFGR_INJECT_DISCCONTINUOUS
/* 规则组不连续模式配置 */
#define __HAL_ADC_CFGR_REG_DISCCONTINUOUS                ADC_CFGR_REG_DISCCONTINUOUS
/* 不连续模式通道数配置 */
#define __HAL_ADC_CFGR_DISCONTINUOUS_NUM                 ADC_CFGR_DISCONTINUOUS_NUM
/* 自动等待转换配置 */
#define __HAL_ADC_CFGR_AUTOWAIT                          ADC_CFGR_AUTOWAIT
/* 连续转换模式配置 */
#define __HAL_ADC_CFGR_CONTINUOUS                        ADC_CFGR_CONTINUOUS
/* 溢出管理配置 */
#define __HAL_ADC_CFGR_OVERRUN                           ADC_CFGR_OVERRUN
/* DMA连续请求配置 */
#define __HAL_ADC_CFGR_DMACONTREQ                        ADC_CFGR_DMACONTREQ
/* 规则组外部触发选择设置 */
#define __HAL_ADC_CFGR_EXTSEL                            ADC_CFGR_EXTSEL_SET
/* 注入组外部触发选择设置 */
#define __HAL_ADC_JSQR_JEXTSEL                           ADC_JSQR_JEXTSEL_SET
/* 偏移量通道选择 */
#define __HAL_ADC_OFR_CHANNEL                            ADC_OFR_CHANNEL
/* 差分模式通道选择 */
#define __HAL_ADC_DIFSEL_CHANNEL                         ADC_DIFSEL_CHANNEL
/* 设置校准因子差分值 */
#define __HAL_ADC_CALFACT_DIFF_SET                       ADC_CALFACT_DIFF_SET
/* 获取校准因子差分值 */
#define __HAL_ADC_CALFACT_DIFF_GET                       ADC_CALFACT_DIFF_GET
/* 阈值高门限设置 */
#define __HAL_ADC_TRX_HIGHTHRESHOLD                      ADC_TRX_HIGHTHRESHOLD

/* 分辨率偏移移位 */
#define __HAL_ADC_OFFSET_SHIFT_RESOLUTION                ADC_OFFSET_SHIFT_RESOLUTION
/* 看门狗1阈值分辨率移位 */
#define __HAL_ADC_AWD1THRESHOLD_SHIFT_RESOLUTION         ADC_AWD1THRESHOLD_SHIFT_RESOLUTION
/* 看门狗2/3阈值分辨率移位 */
#define __HAL_ADC_AWD23THRESHOLD_SHIFT_RESOLUTION        ADC_AWD23THRESHOLD_SHIFT_RESOLUTION
/* ADC通用寄存器操作 */
#define __HAL_ADC_COMMON_REGISTER                        ADC_COMMON_REGISTER
/* ADC多模式配置 */
#define __HAL_ADC_COMMON_CCR_MULTI                       ADC_COMMON_CCR_MULTI
/* 检查多模式是否使能 */
#define __HAL_ADC_MULTIMODE_IS_ENABLED                   ADC_MULTIMODE_IS_ENABLE
/* 检查多模式是否使能（旧名称） */
#define __ADC_MULTIMODE_IS_ENABLED                       ADC_MULTIMODE_IS_ENABLE
/* 非多模式或多模式主模式检查 */
#define __HAL_ADC_NONMULTIMODE_OR_MULTIMODEMASTER        ADC_NONMULTIMODE_OR_MULTIMODEMASTER
/* ADC通用其他配置 */
#define __HAL_ADC_COMMON_ADC_OTHER                       ADC_COMMON_ADC_OTHER
/* 多模式从机配置 */
#define __HAL_ADC_MULTI_SLAVE                            ADC_MULTI_SLAVE

/* 规则序列长度设置 */
#define __HAL_ADC_SQR1_L                                 ADC_SQR1_L_SHIFT
/* 注入序列长度设置 */
#define __HAL_ADC_JSQR_JL                                ADC_JSQR_JL_SHIFT
/* 注入序列设置 */
#define __HAL_ADC_JSQR_RK_JL                             ADC_JSQR_RK_JL
/* 不连续模式通道数设置 */
#define __HAL_ADC_CR1_DISCONTINUOUS_NUM                  ADC_CR1_DISCONTINUOUS_NUM
/* 扫描模式设置 */
#define __HAL_ADC_CR1_SCAN                               ADC_CR1_SCAN_SET
/* 最大转换周期范围 */
#define __HAL_ADC_CONVCYCLES_MAX_RANGE                   ADC_CONVCYCLES_MAX_RANGE
/* 时钟预分频范围 */
#define __HAL_ADC_CLOCK_PRESCALER_RANGE                  ADC_CLOCK_PRESCALER_RANGE
/* 获取时钟预分频值 */
#define __HAL_ADC_GET_CLOCK_PRESCALER                    ADC_GET_CLOCK_PRESCALER

/* 规则序列寄存器1 */
#define __HAL_ADC_SQR1                                   ADC_SQR1
/* 采样时间寄存器1 */
#define __HAL_ADC_SMPR1                                  ADC_SMPR1
/* 采样时间寄存器2 */
#define __HAL_ADC_SMPR2                                  ADC_SMPR2
/* 规则序列第3个转换设置 */
#define __HAL_ADC_SQR3_RK                                ADC_SQR3_RK
/* 规则序列第2个转换设置 */
#define __HAL_ADC_SQR2_RK                                ADC_SQR2_RK
/* 规则序列第1个转换设置 */
#define __HAL_ADC_SQR1_RK                                ADC_SQR1_RK
/* 连续转换模式设置 */
#define __HAL_ADC_CR2_CONTINUOUS                         ADC_CR2_CONTINUOUS
/* 不连续模式设置 */
#define __HAL_ADC_CR1_DISCONTINUOUS                      ADC_CR1_DISCONTINUOUS
/* 扫描转换模式设置 */
#define __HAL_ADC_CR1_SCANCONV                           ADC_CR1_SCANCONV
/* EOC（转换结束）选择 */
#define __HAL_ADC_CR2_EOCSelection                       ADC_CR2_EOCSelection
/* DMA连续请求设置 */
#define __HAL_ADC_CR2_DMAContReq                         ADC_CR2_DMAContReq
/* 注入序列寄存器 */
#define __HAL_ADC_JSQR                                   ADC_JSQR

/* 通道选择寄存器通道设置 */
#define __HAL_ADC_CHSELR_CHANNEL                         ADC_CHSELR_CHANNEL
/* 规则组不连续模式配置（CFGR1寄存器） */
#define __HAL_ADC_CFGR1_REG_DISCCONTINUOUS               ADC_CFGR1_REG_DISCCONTINUOUS
/* 自动关闭模式配置 */
#define __HAL_ADC_CFGR1_AUTOOFF                          ADC_CFGR1_AUTOOFF
/* 自动等待模式配置 */
#define __HAL_ADC_CFGR1_AUTOWAIT                         ADC_CFGR1_AUTOWAIT
/* 连续转换模式配置（CFGR1寄存器） */
#define __HAL_ADC_CFGR1_CONTINUOUS                       ADC_CFGR1_CONTINUOUS
/* 溢出模式配置（CFGR1寄存器） */
#define __HAL_ADC_CFGR1_OVERRUN                          ADC_CFGR1_OVERRUN
/* 扫描方向配置 */
#define __HAL_ADC_CFGR1_SCANDIR                          ADC_CFGR1_SCANDIR
/* DMA连续请求配置（CFGR1寄存器） */
#define __HAL_ADC_CFGR1_DMACONTREQ                       ADC_CFGR1_DMACONTREQ

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC Aliased Macros maintained for legacy purpose
  * @{
  */
/* DAC（数模转换器）相关宏别名 */
/* 通道1的12位右对齐数据保持寄存器对齐设置（修正拼写错误ALIGNEMENT -> ALIGNMENT） */
#define __HAL_DHR12R1_ALIGNEMENT                        DAC_DHR12R1_ALIGNMENT
/* 通道2的12位右对齐数据保持寄存器对齐设置 */
#define __HAL_DHR12R2_ALIGNEMENT                        DAC_DHR12R2_ALIGNMENT
/* 双通道的12位右对齐数据保持寄存器对齐设置 */
#define __HAL_DHR12RD_ALIGNEMENT                        DAC_DHR12RD_ALIGNMENT
/* 检查是否产生波形 */
#define IS_DAC_GENERATE_WAVE                            IS_DAC_WAVE

/**
  * @}
  */

/** @defgroup HAL_DBGMCU_Aliased_Macros HAL DBGMCU Aliased Macros maintained for legacy purpose
  * @{
  */
/* DBGMCU（调试接口）相关宏别名，用于调试时冻结外设 */
/* 冻结TIM1 */
#define __HAL_FREEZE_TIM1_DBGMCU __HAL_DBGMCU_FREEZE_TIM1
/* 解冻TIM1 */
#define __HAL_UNFREEZE_TIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM1
/* 冻结TIM2 */
#define __HAL_FREEZE_TIM2_DBGMCU __HAL_DBGMCU_FREEZE_TIM2
/* 解冻TIM2 */
#define __HAL_UNFREEZE_TIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM2
/* 冻结TIM3 */
#define __HAL_FREEZE_TIM3_DBGMCU __HAL_DBGMCU_FREEZE_TIM3
/* 解冻TIM3 */
#define __HAL_UNFREEZE_TIM3_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM3
/* 冻结TIM4 */
#define __HAL_FREEZE_TIM4_DBGMCU __HAL_DBGMCU_FREEZE_TIM4
/* 解冻TIM4 */
#define __HAL_UNFREEZE_TIM4_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM4
/* 冻结TIM5 */
#define __HAL_FREEZE_TIM5_DBGMCU __HAL_DBGMCU_FREEZE_TIM5
/* 解冻TIM5 */
#define __HAL_UNFREEZE_TIM5_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM5
/* 冻结TIM6 */
#define __HAL_FREEZE_TIM6_DBGMCU __HAL_DBGMCU_FREEZE_TIM6
/* 解冻TIM6 */
#define __HAL_UNFREEZE_TIM6_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM6
/* 冻结TIM7 */
#define __HAL_FREEZE_TIM7_DBGMCU __HAL_DBGMCU_FREEZE_TIM7
/* 解冻TIM7 */
#define __HAL_UNFREEZE_TIM7_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM7
/* 冻结TIM8 */
#define __HAL_FREEZE_TIM8_DBGMCU __HAL_DBGMCU_FREEZE_TIM8
/* 解冻TIM8 */
#define __HAL_UNFREEZE_TIM8_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM8

/* 冻结TIM9 */
#define __HAL_FREEZE_TIM9_DBGMCU __HAL_DBGMCU_FREEZE_TIM9
/* 解冻TIM9 */
#define __HAL_UNFREEZE_TIM9_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM9
/* 冻结TIM10 */
#define __HAL_FREEZE_TIM10_DBGMCU __HAL_DBGMCU_FREEZE_TIM10
/* 解冻TIM10 */
#define __HAL_UNFREEZE_TIM10_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM10
/* 冻结TIM11 */
#define __HAL_FREEZE_TIM11_DBGMCU __HAL_DBGMCU_FREEZE_TIM11
/* 解冻TIM11 */
#define __HAL_UNFREEZE_TIM11_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM11
/* 冻结TIM12 */
#define __HAL_FREEZE_TIM12_DBGMCU __HAL_DBGMCU_FREEZE_TIM12
/* 解冻TIM12 */
#define __HAL_UNFREEZE_TIM12_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM12
/* 冻结TIM13 */
#define __HAL_FREEZE_TIM13_DBGMCU __HAL_DBGMCU_FREEZE_TIM13
/* 解冻TIM13 */
#define __HAL_UNFREEZE_TIM13_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM13
/* 冻结TIM14 */
#define __HAL_FREEZE_TIM14_DBGMCU __HAL_DBGMCU_FREEZE_TIM14
/* 解冻TIM14 */
#define __HAL_UNFREEZE_TIM14_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM14
/* 冻结CAN2 */
#define __HAL_FREEZE_CAN2_DBGMCU __HAL_DBGMCU_FREEZE_CAN2
/* 解冻CAN2 */
#define __HAL_UNFREEZE_CAN2_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN2


/* 冻结TIM15 */
#define __HAL_FREEZE_TIM15_DBGMCU __HAL_DBGMCU_FREEZE_TIM15
/* 解冻TIM15 */
#define __HAL_UNFREEZE_TIM15_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM15
/* 冻结TIM16 */
#define __HAL_FREEZE_TIM16_DBGMCU __HAL_DBGMCU_FREEZE_TIM16
/* 解冻TIM16 */
#define __HAL_UNFREEZE_TIM16_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM16
/* 冻结TIM17 */
#define __HAL_FREEZE_TIM17_DBGMCU __HAL_DBGMCU_FREEZE_TIM17
/* 解冻TIM17 */
#define __HAL_UNFREEZE_TIM17_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM17
/* 冻结RTC */
#define __HAL_FREEZE_RTC_DBGMCU __HAL_DBGMCU_FREEZE_RTC
/* 解冻RTC */
#define __HAL_UNFREEZE_RTC_DBGMCU __HAL_DBGMCU_UNFREEZE_RTC
#if defined(STM32H7)
/* 冻结窗口看门狗WWDG1 (STM32H7系列) */
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG1
/* 解冻窗口看门狗WWDG1 (STM32H7系列) */
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UnFreeze_WWDG1
/* 冻结独立看门狗IWDG1 (STM32H7系列) */
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG1
/* 解冻独立看门狗IWDG1 (STM32H7系列) */
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UnFreeze_IWDG1
#else
/* 冻结窗口看门狗WWDG (其他系列) */
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG
/* 解冻窗口看门狗WWDG (其他系列) */
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_WWDG
/* 冻结独立看门狗IWDG (其他系列) */
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG
/* 解冻独立看门狗IWDG (其他系列) */
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_IWDG
#endif /* STM32H7 */
/* 冻结I2C1超时功能 */
#define __HAL_FREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT
/* 解冻I2C1超时功能 */
#define __HAL_UNFREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT
/* 冻结I2C2超时功能 */
#define __HAL_FREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT
/* 解冻I2C2超时功能 */
#define __HAL_UNFREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT
/* 冻结I2C3超时功能 */
#define __HAL_FREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT
/* 解冻I2C3超时功能 */
#define __HAL_UNFREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT
/* 冻结CAN1 */
#define __HAL_FREEZE_CAN1_DBGMCU __HAL_DBGMCU_FREEZE_CAN1
/* 解冻CAN1 */
#define __HAL_UNFREEZE_CAN1_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN1
/* 冻结低功耗定时器LPTIM1 */
#define __HAL_FREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM1
/* 解冻低功耗定时器LPTIM1 */
#define __HAL_UNFREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM1
/* 冻结低功耗定时器LPTIM2 */
#define __HAL_FREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM2
/* 解冻低功耗定时器LPTIM2 */
#define __HAL_UNFREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM2

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Macros HAL COMP Aliased Macros maintained for legacy purpose
  * @{
  */
/* COMP（比较器）相关宏别名 */
#if defined(STM32F3)
/* 启动比较器 */
#define COMP_START                                       __HAL_COMP_ENABLE
/* 停止比较器 */
#define COMP_STOP                                        __HAL_COMP_DISABLE
/* 锁定比较器配置 */
#define COMP_LOCK                                        __HAL_COMP_LOCK
