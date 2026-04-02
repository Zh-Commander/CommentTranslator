/** @defgroup HAL_RTC_Aliased_Functions HAL RTC 别名函数（用于保持旧代码兼容性）
  * @{
  */
#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
// 定义RTC扩展函数别名：将旧函数名映射到新函数名，便于旧代码兼容
#define HAL_RTCEx_SetBoothardwareKey            HAL_RTCEx_LockBootHardwareKey    // 设置硬件密钥
#define HAL_RTCEx_BKUPBlock_Enable              HAL_RTCEx_BKUPBlock              // 启用备份域块保护
#define HAL_RTCEx_BKUPBlock_Disable             HAL_RTCEx_BKUPUnblock            // 禁用备份域块保护
#define HAL_RTCEx_Erase_SecretDev_Conf          HAL_RTCEx_ConfigEraseDeviceSecrets // 擦除秘密设备配置
#endif /* STM32H5 || STM32WBA || STM32H7RS */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Functions HAL SMBUS 别名函数（用于保持旧代码兼容性）
  * @{
  */
// SMBUS相关函数别名定义
#define HAL_SMBUS_Slave_Listen_IT          HAL_SMBUS_EnableListen_IT          // 从机监听中断使能
#define HAL_SMBUS_SlaveAddrCallback        HAL_SMBUS_AddrCallback             // 从机地址回调函数
#define HAL_SMBUS_SlaveListenCpltCallback  HAL_SMBUS_ListenCpltCallback       // 从机监听完成回调
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Functions HAL SPI 别名函数（用于保持旧代码兼容性）
  * @{
  */
// SPI相关函数别名定义
#define HAL_SPI_FlushRxFifo                HAL_SPIEx_FlushRxFifo              // 清空SPI接收FIFO
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Functions HAL TIM 别名函数（用于保持旧代码兼容性）
  * @{
  */
// TIM(定时器)相关函数别名定义
#define HAL_TIM_DMADelayPulseCplt                       TIM_DMADelayPulseCplt           // DMA延时脉冲完成回调
#define HAL_TIM_DMAError                                TIM_DMAError                    // DMA错误处理
#define HAL_TIM_DMACaptureCplt                          TIM_DMACaptureCplt              // DMA捕获完成回调
#define HAL_TIMEx_DMACommutationCplt                    TIMEx_DMACommutationCplt        // DMA交换完成回调
#if defined(STM32H7) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || defined(STM32L4)
// 针对特定STM32系列的定时器别名定义
#define HAL_TIM_SlaveConfigSynchronization              HAL_TIM_SlaveConfigSynchro      // 从模式同步配置
#define HAL_TIM_SlaveConfigSynchronization_IT           HAL_TIM_SlaveConfigSynchro_IT   // 从模式同步配置(中断模式)
#define HAL_TIMEx_CommutationCallback                   HAL_TIMEx_CommutCallback        // 交换回调函数
#define HAL_TIMEx_ConfigCommutationEvent                HAL_TIMEx_ConfigCommutEvent     // 配置交换事件
#define HAL_TIMEx_ConfigCommutationEvent_IT             HAL_TIMEx_ConfigCommutEvent_IT  // 配置交换事件(中断模式)
#define HAL_TIMEx_ConfigCommutationEvent_DMA            HAL_TIMEx_ConfigCommutEvent_DMA // 配置交换事件(DMA模式)
#endif /* STM32H7 || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Functions HAL UART 别名函数（用于保持旧代码兼容性）
  * @{
  */
// UART(串口)相关函数别名定义
#define HAL_UART_WakeupCallback HAL_UARTEx_WakeupCallback                   // UART唤醒回调函数
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Functions HAL LTDC 别名函数（用于保持旧代码兼容性）
  * @{
  */
// LTDC(LCD-TFT控制器)相关函数别名定义
#define HAL_LTDC_LineEvenCallback HAL_LTDC_LineEventCallback                // 行事件回调函数
#define HAL_LTDC_Relaod           HAL_LTDC_Reload                          // 重新加载配置
#define HAL_LTDC_StructInitFromVideoConfig  HAL_LTDCEx_StructInitFromVideoConfig // 从视频配置初始化结构体
#define HAL_LTDC_StructInitFromAdaptedCommandConfig  HAL_LTDCEx_StructInitFromAdaptedCommandConfig // 从适配命令配置初始化结构体
/**
  * @}
  */


/** @defgroup HAL_PPP_Aliased_Functions HAL PPP 别名函数（用于保持旧代码兼容性）
  * @{
  */

/**
  * @}
  */

/* 导出的宏 ------------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Macros HAL CRYP 别名宏（用于保持旧代码兼容性）
  * @{
  */
// AES加密相关宏别名，映射到新的CRYP(加密处理器)宏
#define AES_IT_CC                      CRYP_IT_CC                        // AES加密完成中断
#define AES_IT_ERR                     CRYP_IT_ERR                       // AES错误中断
#define AES_FLAG_CCF                   CRYP_FLAG_CCF                     // AES加密完成标志
/**
  * @}
  */

/** @defgroup HAL_Aliased_Macros HAL 通用别名宏（用于保持旧代码兼容性）
  * @{
  */
// 系统配置相关宏别名定义
#define __HAL_GET_BOOT_MODE                   __HAL_SYSCFG_GET_BOOT_MODE         // 获取启动模式
#define __HAL_REMAPMEMORY_FLASH               __HAL_SYSCFG_REMAPMEMORY_FLASH     // 重映射Flash到0x00000000
#define __HAL_REMAPMEMORY_SYSTEMFLASH         __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH // 重映射系统Flash
#define __HAL_REMAPMEMORY_SRAM                __HAL_SYSCFG_REMAPMEMORY_SRAM      // 重映射SRAM
#define __HAL_REMAPMEMORY_FMC                 __HAL_SYSCFG_REMAPMEMORY_FMC       // 重映射FMC(可变存储控制器)
#define __HAL_REMAPMEMORY_FMC_SDRAM           __HAL_SYSCFG_REMAPMEMORY_FMC_SDRAM // 重映射FMC SDRAM
#define __HAL_REMAPMEMORY_FSMC                __HAL_SYSCFG_REMAPMEMORY_FSMC      // 重映射FSMC(静态存储控制器)
#define __HAL_REMAPMEMORY_QUADSPI             __HAL_SYSCFG_REMAPMEMORY_QUADSPI   // 重映射QSPI(四线SPI)
#define __HAL_FMC_BANK                        __HAL_SYSCFG_FMC_BANK              // FMC存储块配置
#define __HAL_GET_FLAG                        __HAL_SYSCFG_GET_FLAG              // 获取系统配置标志
#define __HAL_CLEAR_FLAG                      __HAL_SYSCFG_CLEAR_FLAG            // 清除系统配置标志
#define __HAL_VREFINT_OUT_ENABLE              __HAL_SYSCFG_VREFINT_OUT_ENABLE    // 使能内部参考电压输出
#define __HAL_VREFINT_OUT_DISABLE             __HAL_SYSCFG_VREFINT_OUT_DISABLE   // 禁用内部参考电压输出
#define __HAL_SYSCFG_SRAM2_WRP_ENABLE         __HAL_SYSCFG_SRAM2_WRP_0_31_ENABLE // 使能SRAM2写保护

// 标志和配置别名定义
#define SYSCFG_FLAG_VREF_READY                SYSCFG_FLAG_VREFINT_READY          // 参考电压就绪标志
#define SYSCFG_FLAG_RC48                      RCC_FLAG_HSI48                     // 48MHz RC振荡器标志
#define IS_SYSCFG_FASTMODEPLUS_CONFIG         IS_I2C_FASTMODEPLUS                // 快速模式Plus配置检查
#define UFB_MODE_BitNumber                    UFB_MODE_BIT_NUMBER                // USB模式位编号
#define CMP_PD_BitNumber                      CMP_PD_BIT_NUMBER                  // 比较器掉电位编号

/**
  * @}
  */


/** @defgroup HAL_ADC_Aliased_Macros HAL ADC 别名宏（用于保持旧代码兼容性）
  * @{
  */
// ADC(模数转换器)使能与状态检查相关宏
#define __ADC_ENABLE                                     __HAL_ADC_ENABLE                     // 使能ADC
#define __ADC_DISABLE                                    __HAL_ADC_DISABLE                    // 禁用ADC
#define __HAL_ADC_ENABLING_CONDITIONS                    ADC_ENABLING_CONDITIONS              // ADC使能条件检查
#define __HAL_ADC_DISABLING_CONDITIONS                   ADC_DISABLING_CONDITIONS             // ADC禁用条件检查
#define __HAL_ADC_IS_ENABLED                             ADC_IS_ENABLE                        // 检查ADC是否使能
#define __ADC_IS_ENABLED                                 ADC_IS_ENABLE                        // 检查adc是否使能
#define __HAL_ADC_IS_SOFTWARE_START_REGULAR              ADC_IS_SOFTWARE_START_REGULAR        // 检查是否为规则组软件启动
#define __HAL_ADC_IS_SOFTWARE_START_INJECTED             ADC_IS_SOFTWARE_START_INJECTED       // 检查是否为注入组软件启动
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED // 检查规则组和注入组转换是否正在进行
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR          ADC_IS_CONVERSION_ONGOING_REGULAR    // 检查规则组转换是否正在进行
#define __HAL_ADC_IS_CONVERSION_ONGOING_INJECTED         ADC_IS_CONVERSION_ONGOING_INJECTED   // 检查注入组转换是否正在进行
#define __HAL_ADC_IS_CONVERSION_ONGOING                  ADC_IS_CONVERSION_ONGOING            // 检查转换是否正在进行
#define __HAL_ADC_CLEAR_ERRORCODE                        ADC_CLEAR_ERRORCODE                  // 清除错误代码

// ADC配置与参数获取相关宏
#define __HAL_ADC_GET_RESOLUTION                         ADC_GET_RESOLUTION                   // 获取ADC分辨率
#define __HAL_ADC_JSQR_RK                                ADC_JSQR_RK                          // 注入序列寄存器配置
#define __HAL_ADC_CFGR_AWD1CH                            ADC_CFGR_AWD1CH_SHIFT                // 模拟看门狗1通道移位
#define __HAL_ADC_CFGR_AWD23CR                           ADC_CFGR_AWD23CR                     // 模拟看门狗2/3配置
#define __HAL_ADC_CFGR_INJECT_AUTO_CONVERSION            ADC_CFGR_INJECT_AUTO_CONVERSION      // 注入组自动转换配置
#define __HAL_ADC_CFGR_INJECT_CONTEXT_QUEUE              ADC_CFGR_INJECT_CONTEXT_QUEUE        // 注入组上下文队列配置
#define __HAL_ADC_CFGR_INJECT_DISCCONTINUOUS             ADC_CFGR_INJECT_DISCCONTINUOUS       // 注入组不连续模式配置
#define __HAL_ADC_CFGR_REG_DISCCONTINUOUS                ADC_CFGR_REG_DISCCONTINUOUS          // 规则组不连续模式配置
#define __HAL_ADC_CFGR_DISCONTINUOUS_NUM                 ADC_CFGR_DISCONTINUOUS_NUM           // 不连续模式通道数配置
#define __HAL_ADC_CFGR_AUTOWAIT                          ADC_CFGR_AUTOWAIT                    // 自动延迟配置
#define __HAL_ADC_CFGR_CONTINUOUS                        ADC_CFGR_CONTINUOUS                  // 连续转换模式配置
#define __HAL_ADC_CFGR_OVERRUN                           ADC_CFGR_OVERRUN                     // 溢出处理配置
#define __HAL_ADC_CFGR_DMACONTREQ                        ADC_CFGR_DMACONTREQ                  // DMA连续请求配置
#define __HAL_ADC_CFGR_EXTSEL                            ADC_CFGR_EXTSEL_SET                  // 规则组外部触发源选择
#define __HAL_ADC_JSQR_JEXTSEL                           ADC_JSQR_JEXTSEL_SET                 // 注入组外部触发源选择
#define __HAL_ADC_OFR_CHANNEL                            ADC_OFR_CHANNEL                      // 偏移量通道配置
#define __HAL_ADC_DIFSEL_CHANNEL                         ADC_DIFSEL_CHANNEL                   // 差分模式通道选择
#define __HAL_ADC_CALFACT_DIFF_SET                       ADC_CALFACT_DIFF_SET                 // 设置差分校准因子
#define __HAL_ADC_CALFACT_DIFF_GET                       ADC_CALFACT_DIFF_GET                 // 获取差分校准因子
#define __HAL_ADC_TRX_HIGHTHRESHOLD                      ADC_TRX_HIGHTHRESHOLD                // 高阈值配置

// ADC阈值与分辨率相关宏
#define __HAL_ADC_OFFSET_SHIFT_RESOLUTION                ADC_OFFSET_SHIFT_RESOLUTION          // 偏移量分辨率移位
#define __HAL_ADC_AWD1THRESHOLD_SHIFT_RESOLUTION         ADC_AWD1THRESHOLD_SHIFT_RESOLUTION   // 看门狗1阈值分辨率移位
#define __HAL_ADC_AWD23THRESHOLD_SHIFT_RESOLUTION        ADC_AWD23THRESHOLD_SHIFT_RESOLUTION  // 看门狗2/3阈值分辨率移位
#define __HAL_ADC_COMMON_REGISTER                        ADC_COMMON_REGISTER                  // ADC通用寄存器
#define __HAL_ADC_COMMON_CCR_MULTI                       ADC_COMMON_CCR_MULTI                 // 多模式配置
#define __HAL_ADC_MULTIMODE_IS_ENABLED                   ADC_MULTIMODE_IS_ENABLE              // 检查多模式是否使能
#define __ADC_MULTIMODE_IS_ENABLED                       ADC_MULTIMODE_IS_ENABLE              // 检查多模式是否使能
#define __HAL_ADC_NONMULTIMODE_OR_MULTIMODEMASTER        ADC_NONMULTIMODE_OR_MULTIMODEMASTER  // 非多模式或多模式主设备检查
#define __HAL_ADC_COMMON_ADC_OTHER                       ADC_COMMON_ADC_OTHER                 // 其他ADC通用设置
#define __HAL_ADC_MULTI_SLAVE                            ADC_MULTI_SLAVE                      // 多模式从设备配置

// ADC寄存器操作相关宏
#define __HAL_ADC_SQR1_L                                 ADC_SQR1_L_SHIFT                     // 规则序列长度移位
#define __HAL_ADC_JSQR_JL                                ADC_JSQR_JL_SHIFT                    // 注入序列长度移位
#define __HAL_ADC_JSQR_RK_JL                             ADC_JSQR_RK_JL                       // 注入序列配置
#define __HAL_ADC_CR1_DISCONTINUOUS_NUM                  ADC_CR1_DISCONTINUOUS_NUM            // 不连续模式通道数
#define __HAL_ADC_CR1_SCAN                               ADC_CR1_SCAN_SET                     // 扫描模式设置
#define __HAL_ADC_CONVCYCLES_MAX_RANGE                   ADC_CONVCYCLES_MAX_RANGE             // 最大转换周期范围
#define __HAL_ADC_CLOCK_PRESCALER_RANGE                  ADC_CLOCK_PRESCALER_RANGE            // 时钟预分频范围
#define __HAL_ADC_GET_CLOCK_PRESCALER                    ADC_GET_CLOCK_PRESCALER              // 获取时钟预分频值

// ADC寄存器映射宏
#define __HAL_ADC_SQR1                                   ADC_SQR1                             // 规则序列寄存器1
#define __HAL_ADC_SMPR1                                  ADC_SMPR1                            // 采样时间寄存器1
#define __HAL_ADC_SMPR2                                  ADC_SMPR2                            // 采样时间寄存器2
#define __HAL_ADC_SQR3_RK                                ADC_SQR3_RK                          // 规则序列寄存器3通道配置
#define __HAL_ADC_SQR2_RK                                ADC_SQR2_RK                          // 规则序列寄存器2通道配置
#define __HAL_ADC_SQR1_RK                                ADC_SQR1_RK                          // 规则序列寄存器1通道配置
#define __HAL_ADC_CR2_CONTINUOUS                         ADC_CR2_CONTINUOUS                   // 连续转换模式
#define __HAL_ADC_CR1_DISCONTINUOUS                      ADC_CR1_DISCONTINUOUS                // 不连续模式
#define __HAL_ADC_CR1_SCANCONV                           ADC_CR1_SCANCONV                     // 扫描转换模式
#define __HAL_ADC_CR2_EOCSelection                       ADC_CR2_EOCSelection                 // EOC(转换结束)选择
#define __HAL_ADC_CR2_DMAContReq                         ADC_CR2_DMAContReq                   // DMA连续请求
#define __HAL_ADC_JSQR                                   ADC_JSQR                             // 注入序列寄存器

// ADC通道选择与配置寄存器宏
#define __HAL_ADC_CHSELR_CHANNEL                         ADC_CHSELR_CHANNEL                   // 通道选择寄存器
#define __HAL_ADC_CFGR1_REG_DISCCONTINUOUS               ADC_CFGR1_REG_DISCCONTINUOUS         // 规则组不连续模式
#define __HAL_ADC_CFGR1_AUTOOFF                          ADC_CFGR1_AUTOOFF                    // 自动关闭模式
#define __HAL_ADC_CFGR1_AUTOWAIT                         ADC_CFGR1_AUTOWAIT                   // 自动等待模式
#define __HAL_ADC_CFGR1_CONTINUOUS                       ADC_CFGR1_CONTINUOUS                 // 连续转换模式
#define __HAL_ADC_CFGR1_OVERRUN                          ADC_CFGR1_OVERRUN                    // 溢出处理
#define __HAL_ADC_CFGR1_SCANDIR                          ADC_CFGR1_SCANDIR                    // 扫描方向
#define __HAL_ADC_CFGR1_DMACONTREQ                       ADC_CFGR1_DMACONTREQ                 // DMA连续请求

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC 别名宏（用于保持旧代码兼容性）
  * @{
  */
// DAC(数模转换器)对齐与配置相关宏
#define __HAL_DHR12R1_ALIGNEMENT                        DAC_DHR12R1_ALIGNMENT              // 通道1 12位右对齐数据保持寄存器对齐
#define __HAL_DHR12R2_ALIGNEMENT                        DAC_DHR12R2_ALIGNMENT              // 通道2 12位右对齐数据保持寄存器对齐
#define __HAL_DHR12RD_ALIGNEMENT                        DAC_DHR12RD_ALIGNMENT              // 双通道 12位右对齐数据保持寄存器对齐
#define IS_DAC_GENERATE_WAVE                            IS_DAC_WAVE                        // 检查是否为DAC生成的波形

/**
  * @}
  */

/** @defgroup HAL_DBGMCU_Aliased_Macros HAL DBGMCU 别名宏（用于保持旧代码兼容性）
  * @{
  */
// 调试接口定时器冻结/解冻控制宏，用于调试时暂停定时器
#define __HAL_FREEZE_TIM1_DBGMCU __HAL_DBGMCU_FREEZE_TIM1                    // 冻结TIM1
#define __HAL_UNFREEZE_TIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM1                // 解冻TIM1
#define __HAL_FREEZE_TIM2_DBGMCU __HAL_DBGMCU_FREEZE_TIM2                    // 冻结TIM2
#define __HAL_UNFREEZE_TIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM2                // 解冻TIM2
#define __HAL_FREEZE_TIM3_DBGMCU __HAL_DBGMCU_FREEZE_TIM3                    // 冻结TIM3
#define __HAL_UNFREEZE_TIM3_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM3                // 解冻TIM3
#define __HAL_FREEZE_TIM4_DBGMCU __HAL_DBGMCU_FREEZE_TIM4                    // 冻结TIM4
#define __HAL_UNFREEZE_TIM4_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM4                // 解冻TIM4
#define __HAL_FREEZE_TIM5_DBGMCU __HAL_DBGMCU_FREEZE_TIM5                    // 冻结TIM5
#define __HAL_UNFREEZE_TIM5_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM5                // 解冻TIM5
#define __HAL_FREEZE_TIM6_DBGMCU __HAL_DBGMCU_FREEZE_TIM6                    // 冻结TIM6
#define __HAL_UNFREEZE_TIM6_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM6                // 解冻TIM6
#define __HAL_FREEZE_TIM7_DBGMCU __HAL_DBGMCU_FREEZE_TIM7                    // 冻结TIM7
#define __HAL_UNFREEZE_TIM7_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM7                // 解冻TIM7
#define __HAL_FREEZE_TIM8_DBGMCU __HAL_DBGMCU_FREEZE_TIM8                    // 冻结TIM8
#define __HAL_UNFREEZE_TIM8_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM8                // 解冻TIM8

#define __HAL_FREEZE_TIM9_DBGMCU __HAL_DBGMCU_FREEZE_TIM9                    // 冻结TIM9
#define __HAL_UNFREEZE_TIM9_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM9                // 解冻TIM9
#define __HAL_FREEZE_TIM10_DBGMCU __HAL_DBGMCU_FREEZE_TIM10                  // 冻结TIM10
#define __HAL_UNFREEZE_TIM10_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM10              // 解冻TIM10
#define __HAL_FREEZE_TIM11_DBGMCU __HAL_DBGMCU_FREEZE_TIM11                  // 冻结TIM11
#define __HAL_UNFREEZE_TIM11_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM11              // 解冻TIM11
#define __HAL_FREEZE_TIM12_DBGMCU __HAL_DBGMCU_FREEZE_TIM12                  // 冻结TIM12
#define __HAL_UNFREEZE_TIM12_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM12              // 解冻TIM12
#define __HAL_FREEZE_TIM13_DBGMCU __HAL_DBGMCU_FREEZE_TIM13                  // 冻结TIM13
#define __HAL_UNFREEZE_TIM13_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM13              // 解冻TIM13
#define __HAL_FREEZE_TIM14_DBGMCU __HAL_DBGMCU_FREEZE_TIM14                  // 冻结TIM14
#define __HAL_UNFREEZE_TIM14_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM14              // 解冻TIM14
#define __HAL_FREEZE_CAN2_DBGMCU __HAL_DBGMCU_FREEZE_CAN2                    // 冻结CAN2
#define __HAL_UNFREEZE_CAN2_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN2                // 解冻CAN2


#define __HAL_FREEZE_TIM15_DBGMCU __HAL_DBGMCU_FREEZE_TIM15                  // 冻结TIM15
#define __HAL_UNFREEZE_TIM15_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM15              // 解冻TIM15
#define __HAL_FREEZE_TIM16_DBGMCU __HAL_DBGMCU_FREEZE_TIM16                  // 冻结TIM16
#define __HAL_UNFREEZE_TIM16_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM16              // 解冻TIM16
#define __HAL_FREEZE_TIM17_DBGMCU __HAL_DBGMCU_FREEZE_TIM17                  // 冻结TIM17
#define __HAL_UNFREEZE_TIM17_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM17              // 解冻TIM17
#define __HAL_FREEZE_RTC_DBGMCU __HAL_DBGMCU_FREEZE_RTC                      // 冻结RTC(实时时钟)
#define __HAL_UNFREEZE_RTC_DBGMCU __HAL_DBGMCU_UNFREEZE_RTC                  // 解冻RTC
#if defined(STM32H7)
// H7系列看门狗冻结/解冻宏
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG1                   // 冻结窗口看门狗1
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UnFreeze_WWDG1               // 解冻窗口看门狗1
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG1                   // 冻结独立看门狗1
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UnFreeze_IWDG1               // 解冻独立看门狗1
#else
// 其他系列看门狗冻结/解冻宏
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG                    // 冻结窗口看门狗
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_WWDG                // 解冻窗口看门狗
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG                    // 冻结独立看门狗
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_IWDG                // 解冻独立看门狗
#endif /* STM32H7 */
// I2C超时冻结/解冻宏
#define __HAL_FREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT    // 冻结I2C1超时
#define __HAL_UNFREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT // 解冻I2C1超时
#define __HAL_FREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT    // 冻结I2C2超时
#define __HAL_UNFREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT // 解冻I2C2超时
#define __HAL_FREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT    // 冻结I2C3超时
#define __HAL_UNFREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT // 解冻I2C3超时
#define __HAL_FREEZE_CAN1_DBGMCU __HAL_DBGMCU_FREEZE_CAN1                    // 冻结CAN1
#define __HAL_UNFREEZE_CAN1_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN1                // 解冻CAN1
#define __HAL_FREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM1                // 冻结低功耗定时器1
#define __HAL_UNFREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM1            // 解冻低功耗定时器1
#define __HAL_FREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM2                // 冻结低功耗定时器2
#define __HAL_UNFREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM2            // 解冻低功耗定时器2

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Macros HAL COMP 别名宏（用于保持旧代码兼容性）
  * @{
  */
#if defined(STM32F3)
// COMP(比较器)控制宏定义
#define COMP_START                                       __HAL_COMP_ENABLE                  // 启动比较器(使能)
#define COMP_STOP                                        __HAL_COMP_DISABLE                 // 停止比较器(禁用)
#define COMP_LOCK                                        __HAL_COMP_LOCK                    // 锁定比较器配置
