/** @defgroup HAL_DCMI_Aliased_Defines HAL DCMI别名定义，用于保持旧代码兼容性
  * @{
  */
/* DCMI错误标志别名：将旧版的溢出错误(OVF)映射为新版的覆盖错误(OVR) */
#define HAL_DCMI_ERROR_OVF      HAL_DCMI_ERROR_OVR       // DCMI错误码别名：溢出错误 -> 覆盖错误
#define DCMI_IT_OVF             DCMI_IT_OVR              // DCMI中断标志别名：溢出中断 -> 覆盖中断
#define DCMI_FLAG_OVFRI         DCMI_FLAG_OVRRI          // DCMI状态标志别名：原始中断溢出标志 -> 原始中断覆盖标志
#define DCMI_FLAG_OVFMI         DCMI_FLAG_OVRMI          // DCMI状态标志别名：掩码中断溢出标志 -> 掩码中断覆盖标志

/* DCMI裁剪功能函数别名：统一函数命名风格(CROP -> Crop) */
#define HAL_DCMI_ConfigCROP     HAL_DCMI_ConfigCrop      // 配置裁剪窗口
#define HAL_DCMI_EnableCROP     HAL_DCMI_EnableCrop      // 使能裁剪功能
#define HAL_DCMI_DisableCROP    HAL_DCMI_DisableCrop     // 禁用裁剪功能

/**
  * @}
  */

/* 针对STM32L4, F7, F4部分型号, H7系列芯片的条件编译 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7)
/** @defgroup HAL_DMA2D_Aliased_Defines HAL DMA2D别名定义，用于保持旧代码兼容性
  * @{
  */
/* DMA2D输出颜色模式别名：为了兼容旧代码，将简化的颜色模式宏映射为带OUTPUT前缀的标准宏 */
#define DMA2D_ARGB8888          DMA2D_OUTPUT_ARGB8888    // 输出格式：ARGB8888 (32位)
#define DMA2D_RGB888            DMA2D_OUTPUT_RGB888      // 输出格式：RGB888 (24位)
#define DMA2D_RGB565            DMA2D_OUTPUT_RGB565      // 输出格式：RGB565 (16位)
#define DMA2D_ARGB1555          DMA2D_OUTPUT_ARGB1555    // 输出格式：ARGB1555 (16位)
#define DMA2D_ARGB4444          DMA2D_OUTPUT_ARGB4444    // 输出格式：ARGB4444 (16位)

/* DMA2D输入颜色模式别名：将旧版CM_前缀宏映射为新版DMA2D_INPUT_前缀宏 */
#define CM_ARGB8888             DMA2D_INPUT_ARGB8888     // 输入格式：ARGB8888
#define CM_RGB888               DMA2D_INPUT_RGB888       // 输入格式：RGB888
#define CM_RGB565               DMA2D_INPUT_RGB565       // 输入格式：RGB565
#define CM_ARGB1555             DMA2D_INPUT_ARGB1555     // 输入格式：ARGB1555
#define CM_ARGB4444             DMA2D_INPUT_ARGB4444     // 输入格式：ARGB4444
#define CM_L8                   DMA2D_INPUT_L8           // 输入格式：L8 (8位亮度)
#define CM_AL44                 DMA2D_INPUT_AL44         // 输入格式：AL44 (4位亮度 + 4位Alpha)
#define CM_AL88                 DMA2D_INPUT_AL88         // 输入格式：AL88 (8位亮度 + 8位Alpha)
#define CM_L4                   DMA2D_INPUT_L4           // 输入格式：L4 (4位亮度)
#define CM_A8                   DMA2D_INPUT_A8           // 输入格式：A8 (8位Alpha)
#define CM_A4                   DMA2D_INPUT_A4           // 输入格式：A4 (4位Alpha)
/**
  * @}
  */
#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 */

/* 针对STM32L4, F7, F4部分型号, H7, U5系列芯片的条件编译 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7) || defined(STM32U5)
/** @defgroup DMA2D_Aliases DMA2D API别名
  * @{
  */
/* DMA2D CLUT(颜色查找表)功能别名：将禁用CLUT映射为中止CLUT加载 */
#define HAL_DMA2D_DisableCLUT       HAL_DMA2D_CLUTLoading_Abort    // 为了兼容旧代码，重定向到 HAL_DMA2D_CLUTLoading_Abort
/**
  * @}
  */

#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 || STM32U5 */

/** @defgroup HAL_PPP_Aliased_Defines HAL PPP 别名定义，用于保持旧代码兼容性
  * @{
  */

/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/

/** @defgroup HAL_CRYP_Aliased_Functions HAL CRYP别名函数，用于保持旧代码兼容性
  * @{
  */
/* CRYP(加密处理器)回调函数别名：计算完成回调 */
#define HAL_CRYP_ComputationCpltCallback     HAL_CRYPEx_ComputationCpltCallback
/**
  * @}
  */

/** @defgroup HAL_DCACHE_Aliased_Functions HAL DCACHE别名函数，用于保持旧代码兼容性
  * @{
  */

/* 针对STM32U5系列的条件编译，处理数据缓存(DCACHE)相关函数 */
#if defined(STM32U5)
/* 函数名简化别名：清理并无效化缓存(按地址) */
#define HAL_DCACHE_CleanInvalidateByAddr     HAL_DCACHE_CleanInvalidByAddr
/* 函数名简化别名：清理并无效化缓存(按地址，中断方式) */
#define HAL_DCACHE_CleanInvalidateByAddr_IT  HAL_DCACHE_CleanInvalidByAddr_IT
#endif /* STM32U5 */

/**
  * @}
  */

/* 针对非STM32F2系列芯片的条件编译 */
#if !defined(STM32F2)
/** @defgroup HASH_alias HASH API别名
  * @{
  */
/* HASH(哈希处理器)中断处理函数别名：为了兼容旧代码进行重定向 */
#define HAL_HASHEx_IRQHandler   HAL_HASH_IRQHandler
/**
  *
  * @}
  */
#endif /* STM32F2 */
/** @defgroup HAL_HASH_Aliased_Functions HAL HASH别名函数，用于保持旧代码兼容性
  * @{
  */
/* HASH状态类型定义别名 */
#define HAL_HASH_STATETypeDef        HAL_HASH_StateTypeDef
/* HASH阶段类型定义别名 */
#define HAL_HASHPhaseTypeDef         HAL_HASH_PhaseTypeDef

/* HMAC(基于哈希的消息认证码)结束函数别名，映射到对应的HASH结束函数 */
#define HAL_HMAC_MD5_Finish          HAL_HASH_MD5_Finish
#define HAL_HMAC_SHA1_Finish         HAL_HASH_SHA1_Finish
#define HAL_HMAC_SHA224_Finish       HAL_HASH_SHA224_Finish
#define HAL_HMAC_SHA256_Finish       HAL_HASH_SHA256_Finish

/*HASH 算法选择别名，将旧版命名映射为带ALGOSELECTION前缀的新命名*/

#define HASH_AlgoSelection_SHA1      HASH_ALGOSELECTION_SHA1      // 选择SHA1算法
#define HASH_AlgoSelection_SHA224    HASH_ALGOSELECTION_SHA224    // 选择SHA224算法
#define HASH_AlgoSelection_SHA256    HASH_ALGOSELECTION_SHA256    // 选择SHA256算法
#define HASH_AlgoSelection_MD5       HASH_ALGOSELECTION_MD5       // 选择MD5算法

/* HASH算法模式别名 */
#define HASH_AlgoMode_HASH         HASH_ALGOMODE_HASH           // HASH模式
#define HASH_AlgoMode_HMAC         HASH_ALGOMODE_HMAC           // HMAC模式

/* HASH HMAC密钥类型别名 */
#define HASH_HMACKeyType_ShortKey  HASH_HMAC_KEYTYPE_SHORTKEY   // 短密钥
#define HASH_HMACKeyType_LongKey   HASH_HMAC_KEYTYPE_LONGKEY    // 长密钥

/* 针对STM32L4, L5, F2, F4, F7, H7系列的条件编译 */
#if defined(STM32L4) || defined(STM32L5) || defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)

/* HASH数据累加函数别名：将Accumulate映射为缩写Accmlt */
#define HAL_HASH_MD5_Accumulate                HAL_HASH_MD5_Accmlt
#define HAL_HASH_MD5_Accumulate_End            HAL_HASH_MD5_Accmlt_End
#define HAL_HASH_MD5_Accumulate_IT             HAL_HASH_MD5_Accmlt_IT
#define HAL_HASH_MD5_Accumulate_End_IT         HAL_HASH_MD5_Accmlt_End_IT

#define HAL_HASH_SHA1_Accumulate               HAL_HASH_SHA1_Accmlt
#define HAL_HASH_SHA1_Accumulate_End           HAL_HASH_SHA1_Accmlt_End
#define HAL_HASH_SHA1_Accumulate_IT            HAL_HASH_SHA1_Accmlt_IT
#define HAL_HASH_SHA1_Accumulate_End_IT        HAL_HASH_SHA1_Accmlt_End_IT

#define HAL_HASHEx_SHA224_Accumulate           HAL_HASHEx_SHA224_Accmlt
#define HAL_HASHEx_SHA224_Accumulate_End       HAL_HASHEx_SHA224_Accmlt_End
#define HAL_HASHEx_SHA224_Accumulate_IT        HAL_HASHEx_SHA224_Accmlt_IT
#define HAL_HASHEx_SHA224_Accumulate_End_IT    HAL_HASHEx_SHA224_Accmlt_End_IT

#define HAL_HASHEx_SHA256_Accumulate           HAL_HASHEx_SHA256_Accmlt
#define HAL_HASHEx_SHA256_Accumulate_End       HAL_HASHEx_SHA256_Accmlt_End
#define HAL_HASHEx_SHA256_Accumulate_IT        HAL_HASHEx_SHA256_Accmlt_IT
#define HAL_HASHEx_SHA256_Accumulate_End_IT    HAL_HASHEx_SHA256_Accmlt_End_IT

#endif  /* STM32L4 || STM32L5 || STM32F2 || STM32F4 || STM32F7 || STM32H7 */
/**
  * @}
  */

/** @defgroup HAL_Aliased_Functions HAL 通用别名函数，用于保持旧代码兼容性
  * @{
  */
/* 调试模式相关函数别名：将旧版HAL_前缀映射为新版HAL_DBGMCU_前缀 */
#define HAL_EnableDBGSleepMode HAL_DBGMCU_EnableDBGSleepMode       // 使能睡眠模式下的调试
#define HAL_DisableDBGSleepMode HAL_DBGMCU_DisableDBGSleepMode     // 禁用睡眠模式下的调试
#define HAL_EnableDBGStopMode HAL_DBGMCU_EnableDBGStopMode         // 使能停止模式下的调试
#define HAL_DisableDBGStopMode HAL_DBGMCU_DisableDBGStopMode       // 禁用停止模式下的调试
#define HAL_EnableDBGStandbyMode HAL_DBGMCU_EnableDBGStandbyMode   // 使能待机模式下的调试
#define HAL_DisableDBGStandbyMode HAL_DBGMCU_DisableDBGStandbyMode // 禁用待机模式下的调试

/* 调试低功耗配置宏：根据cmd参数调用使能或禁用函数 */
#define HAL_DBG_LowPowerConfig(Periph, cmd) (((cmd\
                                              )==ENABLE)? HAL_DBGMCU_DBG_EnableLowPowerConfig(Periph) : \
                                             HAL_DBGMCU_DBG_DisableLowPowerConfig(Periph))

/* 内部参考电压输出选择函数别名 */
#define HAL_VREFINT_OutputSelect  HAL_SYSCFG_VREFINT_OutputSelect

/* 锁定命令宏：根据cmd参数使能或禁用内部参考电压锁定 */
#define HAL_Lock_Cmd(cmd) (((cmd)==ENABLE) ? HAL_SYSCFG_Enable_Lock_VREFINT() : HAL_SYSCFG_Disable_Lock_VREFINT())

/* 针对STM32L0系列的条件编译，其他系列定义内部参考电压使能/禁用宏 */
#if defined(STM32L0)
#else
#define HAL_VREFINT_Cmd(cmd) (((cmd)==ENABLE)? HAL_SYSCFG_EnableVREFINT() : HAL_SYSCFG_DisableVREFINT())
#endif

/* ADC缓冲使能命令宏：映射到ADC扩展函数 */
#define HAL_ADC_EnableBuffer_Cmd(cmd)  (((cmd)==ENABLE) ? HAL_ADCEx_EnableVREFINT() : HAL_ADCEx_DisableVREFINT())

/* ADC缓冲传感器使能命令宏：映射到ADC扩展函数 */
#define HAL_ADC_EnableBufferSensor_Cmd(cmd) (((cmd\
                                              )==ENABLE) ?  HAL_ADCEx_EnableVREFINTTempSensor() : \
                                             HAL_ADCEx_DisableVREFINTTempSensor())

/* 针对STM32H7部分型号的条件编译，SR域调试停止/待机模式别名 */
#if defined(STM32H7A3xx) || defined(STM32H7B3xx) || defined(STM32H7B0xx) || defined(STM32H7A3xxQ) || \
    defined(STM32H7B3xxQ) || defined(STM32H7B0xxQ)
#define HAL_EnableSRDomainDBGStopMode      HAL_EnableDomain3DBGStopMode
#define HAL_DisableSRDomainDBGStopMode     HAL_DisableDomain3DBGStopMode
#define HAL_EnableSRDomainDBGStandbyMode   HAL_EnableDomain3DBGStandbyMode
#define HAL_DisableSRDomainDBGStandbyMode  HAL_DisableDomain3DBGStandbyMode
#endif /* STM32H7A3xx || STM32H7B3xx || STM32H7B0xx || STM32H7A3xxQ || STM32H7B3xxQ  || STM32H7B0xxQ */

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Functions HAL FLASH别名函数，用于保持旧代码兼容性
  * @{
  */
/* FLASH操作函数别名：将旧版函数名映射为HAL_FLASHEx_扩展函数 */
#define FLASH_HalfPageProgram      HAL_FLASHEx_HalfPageProgram          // 半页编程
#define FLASH_EnableRunPowerDown   HAL_FLASHEx_EnableRunPowerDown       // 使能运行掉电模式
#define FLASH_DisableRunPowerDown  HAL_FLASHEx_DisableRunPowerDown      // 禁用运行掉电模式
#define HAL_DATA_EEPROMEx_Unlock   HAL_FLASHEx_DATAEEPROM_Unlock        // 数据EEPROM解锁
#define HAL_DATA_EEPROMEx_Lock     HAL_FLASHEx_DATAEEPROM_Lock          // 数据EEPROM锁定
#define HAL_DATA_EEPROMEx_Erase    HAL_FLASHEx_DATAEEPROM_Erase         // 数据EEPROM擦除
#define HAL_DATA_EEPROMEx_Program  HAL_FLASHEx_DATAEEPROM_Program       // 数据EEPROM编程

/**
  * @}
 */

/** @defgroup HAL_I2C_Aliased_Functions HAL I2C别名函数，用于保持旧代码兼容性
  * @{
  */
/* I2C滤波器配置函数别名：统一命名风格 */
#define HAL_I2CEx_AnalogFilter_Config         HAL_I2CEx_ConfigAnalogFilter    // 配置模拟滤波器
#define HAL_I2CEx_DigitalFilter_Config        HAL_I2CEx_ConfigDigitalFilter   // 配置数字滤波器
#define HAL_FMPI2CEx_AnalogFilter_Config      HAL_FMPI2CEx_ConfigAnalogFilter // FMPI2C配置模拟滤波器
#define HAL_FMPI2CEx_DigitalFilter_Config     HAL_FMPI2CEx_ConfigDigitalFilter// FMPI2C配置数字滤波器

/* I2C快速模式Plus配置宏：根据cmd参数使能或禁用 */
#define HAL_I2CFastModePlusConfig(SYSCFG_I2CFastModePlus, cmd) (((cmd) == ENABLE)? \
                                                                HAL_I2CEx_EnableFastModePlus(SYSCFG_I2CFastModePlus): \
                                                                HAL_I2CEx_DisableFastModePlus(SYSCFG_I2CFastModePlus))

/* 针对多系列STM32芯片的条件编译，I2C顺序传输函数别名：简化函数名(Sequential -> Seq) */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || \
    defined(STM32L4) || defined(STM32L5) || defined(STM32G4) || defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_IT  HAL_I2C_Master_Seq_Transmit_IT   // 主机顺序发送(中断)
#define HAL_I2C_Master_Sequential_Receive_IT   HAL_I2C_Master_Seq_Receive_IT    // 主机顺序接收(中断)
#define HAL_I2C_Slave_Sequential_Transmit_IT   HAL_I2C_Slave_Seq_Transmit_IT    // 从机顺序发送(中断)
#define HAL_I2C_Slave_Sequential_Receive_IT    HAL_I2C_Slave_Seq_Receive_IT     // 从机顺序接收(中断)
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 ||
          STM32L4 || STM32L5 || STM32G4 || STM32L1 */
/* 针对多系列STM32芯片的条件编译，I2C顺序传输函数别名(DMA模式) */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F4) || defined(STM32F7) || \
    defined(STM32L0) || defined(STM32L4) || defined(STM32L5) || defined(STM32G4)|| defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_DMA HAL_I2C_Master_Seq_Transmit_DMA  // 主机顺序发送(DMA)
#define HAL_I2C_Master_Sequential_Receive_DMA  HAL_I2C_Master_Seq_Receive_DMA   // 主机顺序接收(DMA)
#define HAL_I2C_Slave_Sequential_Transmit_DMA  HAL_I2C_Slave_Seq_Transmit_DMA   // 从机顺序发送(DMA)
#define HAL_I2C_Slave_Sequential_Receive_DMA   HAL_I2C_Slave_Seq_Receive_DMA    // 从机顺序接收(DMA)
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F4 || STM32F7 || STM32L0 || STM32L4 || STM32L5 || STM32G4 || STM32L1 */

/* 针对STM32F4系列的条件编译，FMPI2C顺序传输函数别名 */
#if defined(STM32F4)
#define HAL_FMPI2C_Master_Sequential_Transmit_IT  HAL_FMPI2C_Master_Seq_Transmit_IT
#define HAL_FMPI2C_Master_Sequential_Receive_IT   HAL_FMPI2C_Master_Seq_Receive_IT
#define HAL_FMPI2C_Slave_Sequential_Transmit_IT   HAL_FMPI2C_Slave_Seq_Transmit_IT
#define HAL_FMPI2C_Slave_Sequential_Receive_IT    HAL_FMPI2C_Slave_Seq_Receive_IT
#define HAL_FMPI2C_Master_Sequential_Transmit_DMA HAL_FMPI2C_Master_Seq_Transmit_DMA
#define HAL_FMPI2C_Master_Sequential_Receive_DMA  HAL_FMPI2C_Master_Seq_Receive_DMA
#define HAL_FMPI2C_Slave_Sequential_Transmit_DMA  HAL_FMPI2C_Slave_Seq_Transmit_DMA
#define HAL_FMPI2C_Slave_Sequential_Receive_DMA   HAL_FMPI2C_Slave_Seq_Receive_DMA
#endif /* STM32F4 */
/**
  * @}
 */

/** @defgroup HAL_PWR_Aliased HAL PWR别名定义，用于保持旧代码兼容性
  * @{
  */

/* 针对STM32G0系列的条件编译，PVD(可编程电压检测器)配置函数别名 */
#if defined(STM32G0)
#define HAL_PWR_ConfigPVD                             HAL_PWREx_ConfigPVD
#define HAL_PWR_EnablePVD                             HAL_PWREx_EnablePVD
#define HAL_PWR_DisablePVD                            HAL_PWREx_DisablePVD
#define HAL_PWR_PVD_IRQHandler                        HAL_PWREx_PVD_IRQHandler
#endif

/* 电源管理函数别名：将旧版HAL_PWR_函数映射到新版HAL_PWREx_扩展函数 */
#define HAL_PWR_PVDConfig                             HAL_PWR_ConfigPVD
#define HAL_PWR_DisableBkUpReg                        HAL_PWREx_DisableBkUpReg           // 禁用备份域调节器
#define HAL_PWR_DisableFlashPowerDown                 HAL_PWREx_DisableFlashPowerDown    // 禁用Flash掉电
#define HAL_PWR_DisableVddio2Monitor                  HAL_PWREx_DisableVddio2Monitor     // 禁用Vddio2监控
#define HAL_PWR_EnableBkUpReg                         HAL_PWREx_EnableBkUpReg            // 使能备份域调节器
#define HAL_PWR_EnableFlashPowerDown                  HAL_PWREx_EnableFlashPowerDown     // 使能Flash掉电
#define HAL_PWR_EnableVddio2Monitor                   HAL_PWREx_EnableVddio2Monitor      // 使能Vddio2监控
#define HAL_PWR_PVD_PVM_IRQHandler                    HAL_PWREx_PVD_PVM_IRQHandler       // PVD/PVM中断处理
#define HAL_PWR_PVDLevelConfig                        HAL_PWR_ConfigPVD                  // PVD电平配置
#define HAL_PWR_Vddio2Monitor_IRQHandler              HAL_PWREx_Vddio2Monitor_IRQHandler // Vddio2监控中断处理
#define HAL_PWR_Vddio2MonitorCallback                 HAL_PWREx_Vddio2MonitorCallback    // Vddio2监控回调
#define HAL_PWREx_ActivateOverDrive                   HAL_PWREx_EnableOverDrive          // 激活过驱动模式
#define HAL_PWREx_DeactivateOverDrive                 HAL_PWREx_DisableOverDrive         // 关闭过驱动模式
#define HAL_PWREx_DisableSDADCAnalog                  HAL_PWREx_DisableSDADC             // 禁用SDADC
#define HAL_PWREx_EnableSDADCAnalog                   HAL_PWREx_EnableSDADC              // 使能SDADC
#define HAL_PWREx_PVMConfig                           HAL_PWREx_ConfigPVM                // 配置PVM(电源电压监控)

/* PWR模式定义别名：将旧版PWR_MODE_前缀映射为新版PWR_PVD_MODE_前缀 */
#define PWR_MODE_NORMAL                               PWR_PVD_MODE_NORMAL                // 正常模式
#define PWR_MODE_IT_RISING                            PWR_PVD_MODE_IT_RISING             // 上升沿中断
#define PWR_MODE_IT_FALLING                           PWR_PVD_MODE_IT_FALLING            // 下降沿中断
#define PWR_MODE_IT_RISING_FALLING                    PWR_PVD_MODE_IT_RISING_FALLING     // 上升/下降沿中断
#define PWR_MODE_EVENT_RISING                         PWR_PVD_MODE_EVENT_RISING          // 上升沿事件
#define PWR_MODE_EVENT_FALLING                        PWR_PVD_MODE_EVENT_FALLING         // 下降沿事件
#define PWR_MODE_EVENT_RISING_FALLING                 PWR_PVD_MODE_EVENT_RISING_FALLING  // 上升/下降沿事件

/* 寄存器位带操作相关别名 */
#define CR_OFFSET_BB                                  PWR_CR_OFFSET_BB                   // CR寄存器位带偏移
#define CSR_OFFSET_BB                                 PWR_CSR_OFFSET_BB                  // CSR寄存器位带偏移
#define PMODE_BIT_NUMBER                              VOS_BIT_NUMBER                     // 电源模式位号
#define CR_PMODE_BB                                   CR_VOS_BB                          // CR寄存器电源模式位带

/* 位号定义别名 */
#define DBP_BitNumber                                 DBP_BIT_NUMBER                     // 禁用备份域写保护位号
#define PVDE_BitNumber                                PVDE_BIT_NUMBER                    // PVD使能位号
#define PMODE_BitNumber                               PMODE_BIT_NUMBER                   // 电源模式位号
#define EWUP_BitNumber                                EWUP_BIT_NUMBER                    // 唤醒引脚使能位号
#define FPDS_BitNumber                                FPDS_BIT_NUMBER                    // Flash掉电停止模式位号
#define ODEN_BitNumber                                ODEN_BIT_NUMBER                    // 过驱动使能位号
#define ODSWEN_BitNumber                              ODSWEN_BIT_NUMBER                  // 过驱动切换使能位号
#define MRLVDS_BitNumber                              MRLVDS_BIT_NUMBER                  // 主调压器低电压停止模式位号
#define LPLVDS_BitNumber                              LPLVDS_BIT_NUMBER                  // 低功耗调压器低电压停止模式位号
#define BRE_BitNumber                                 BRE_BIT_NUMBER                     // 备份域就绪位号

#define PWR_MODE_EVT                                  PWR_PVD_MODE_NORMAL                // 兼容旧定义

/* 针对STM32U5系列的条件编译，SRAM保持(retention)相关定义别名 */
#if defined (STM32U5)
/* SRAM1 页面停止模式保持别名 */
#define PWR_SRAM1_PAGE1_STOP_RETENTION                PWR_SRAM1_PAGE1_STOP
#define PWR_SRAM1_PAGE2_STOP_RETENTION                PWR_SRAM1_PAGE2_STOP
#define PWR_SRAM1_PAGE3_STOP_RETENTION                PWR_SRAM1_PAGE3_STOP
#define PWR_SRAM1_PAGE4_STOP_RETENTION                PWR_SRAM1_PAGE4_STOP
#define PWR_SRAM1_PAGE5_STOP_RETENTION                PWR_SRAM1_PAGE5_STOP
#define PWR_SRAM1_PAGE6_STOP_RETENTION                PWR_SRAM1_PAGE6_STOP
#define PWR_SRAM1_PAGE7_STOP_RETENTION                PWR_SRAM1_PAGE7_STOP
#define PWR_SRAM1_PAGE8_STOP_RETENTION                PWR_SRAM1_PAGE8_STOP
#define PWR_SRAM1_PAGE9_STOP_RETENTION                PWR_SRAM1_PAGE9_STOP
#define PWR_SRAM1_PAGE10_STOP_RETENTION               PWR_SRAM1_PAGE10_STOP
#define PWR_SRAM1_PAGE11_STOP_RETENTION               PWR_SRAM1_PAGE11_STOP
#define PWR_SRAM1_PAGE12_STOP_RETENTION               PWR_SRAM1_PAGE12_STOP
#define PWR_SRAM1_FULL_STOP_RETENTION                 PWR_SRAM1_FULL_STOP

/* SRAM2 页面停止模式保持别名 */
#define PWR_SRAM2_PAGE1_STOP_RETENTION                PWR_SRAM2_PAGE1_STOP
#define PWR_SRAM2_PAGE2_STOP_RETENTION                PWR_SRAM2_PAGE2_STOP
#define PWR_SRAM2_FULL_STOP_RETENTION                 PWR_SRAM2_FULL_STOP

/* SRAM3 页面停止模式保持别名 */
#define PWR_SRAM3_PAGE1_STOP_RETENTION                PWR_SRAM3_PAGE1_STOP
#define PWR_SRAM3_PAGE2_STOP_RETENTION                PWR_SRAM3_PAGE2_STOP
#define PWR_SRAM3_PAGE3_STOP_RETENTION                PWR_SRAM3_PAGE3_STOP
#define PWR_SRAM3_PAGE4_STOP_RETENTION                PWR_SRAM3_PAGE4_STOP
#define PWR_SRAM3_PAGE5_STOP_RETENTION                PWR_SRAM3_PAGE5_STOP
#define PWR_SRAM3_PAGE6_STOP_RETENTION                PWR_SRAM3_PAGE6_STOP
#define PWR_SRAM3_PAGE7_STOP_RETENTION                PWR_SRAM3_PAGE7_STOP
#define PWR_SRAM3_PAGE8_STOP_RETENTION                PWR_SRAM3_PAGE8_STOP
#define PWR_SRAM3_PAGE9_STOP_RETENTION                PWR_SRAM3_PAGE9_STOP
#define PWR_SRAM3_PAGE10_STOP_RETENTION               PWR_SRAM3_PAGE10_STOP
#define PWR_SRAM3_PAGE11_STOP_RETENTION               PWR_SRAM3_PAGE11_STOP
#define PWR_SRAM3_PAGE12_STOP_RETENTION               PWR_SRAM3_PAGE12_STOP
#define PWR_SRAM3_PAGE13_STOP_RETENTION               PWR_SRAM3_PAGE13_STOP
#define PWR_SRAM3_FULL_STOP_RETENTION                 PWR_SRAM3_FULL_STOP

/* SRAM4 停止模式保持别名 */
#define PWR_SRAM4_FULL_STOP_RETENTION                 PWR_SRAM4_FULL_STOP

/* SRAM5 页面停止模式保持别名 */
#define PWR_SRAM5_PAGE1_STOP_RETENTION                PWR_SRAM5_PAGE1_STOP
#define PWR_SRAM5_PAGE2_STOP_RETENTION                PWR_SRAM5_PAGE2_STOP
#define PWR_SRAM5_PAGE3_STOP_RETENTION                PWR_SRAM5_PAGE3_STOP
#define PWR_SRAM5_PAGE4_STOP_RETENTION                PWR_SRAM5_PAGE4_STOP
#define PWR_SRAM5_PAGE5_STOP_RETENTION                PWR_SRAM5_PAGE5_STOP
#define PWR_SRAM5_PAGE6_STOP_RETENTION                PWR_SRAM5_PAGE6_STOP
#define PWR_SRAM5_PAGE7_STOP_RETENTION                PWR_SRAM5_PAGE7_STOP
#define PWR_SRAM5_PAGE8_STOP_RETENTION                PWR_SRAM5_PAGE8_STOP
#define PWR_SRAM5_PAGE9_STOP_RETENTION                PWR_SRAM5_PAGE9_STOP
#define PWR_SRAM5_PAGE10_STOP_RETENTION               PWR_SRAM5_PAGE10_STOP
#define PWR_SRAM5_PAGE11_STOP_RETENTION               PWR_SRAM5_PAGE11_STOP
#define PWR_SRAM5_PAGE12_STOP_RETENTION               PWR_SRAM5_PAGE12_STOP
#define PWR_SRAM5_PAGE13_STOP_RETENTION               PWR_SRAM5_PAGE13_STOP
#define PWR_SRAM5_FULL_STOP_RETENTION                 PWR_SRAM5_FULL_STOP

/* SRAM6 页面停止模式保持别名 */
#define PWR_SRAM6_PAGE1_STOP_RETENTION                PWR_SRAM6_PAGE1_STOP
#define PWR_SRAM6_PAGE2_STOP_RETENTION                PWR_SRAM6_PAGE2_STOP
#define PWR_SRAM6_PAGE3_STOP_RETENTION                PWR_SRAM6_PAGE3_STOP
#define PWR_SRAM6_PAGE4_STOP_RETENTION                PWR_SRAM6_PAGE4_STOP
#define PWR_SRAM6_PAGE5_STOP_RETENTION                PWR_SRAM6_PAGE5_STOP
#define PWR_SRAM6_PAGE6_STOP_RETENTION                PWR_SRAM6_PAGE6_STOP
#define PWR_SRAM6_PAGE7_STOP_RETENTION                PWR_SRAM6_PAGE7_STOP
#define PWR_SRAM6_PAGE8_STOP_RETENTION                PWR_SRAM6_PAGE8_STOP
#define PWR_SRAM6_FULL_STOP_RETENTION                 PWR_SRAM6_FULL_STOP

/* 缓存和外设RAM停止模式保持别名 */
#define PWR_ICACHE_FULL_STOP_RETENTION                PWR_ICACHE_FULL_STOP              // 指令缓存
#define PWR_DCACHE1_FULL_STOP_RETENTION               PWR_DCACHE1_FULL_STOP             // 数据缓存1
#define PWR_DCACHE2_FULL_STOP_RETENTION               PWR_DCACHE2_FULL_STOP             // 数据缓存2
#define PWR_DMA2DRAM_FULL_STOP_RETENTION              PWR_DMA2DRAM_FULL_STOP            // DMA2D RAM
#define PWR_PERIPHRAM_FULL_STOP_RETENTION             PWR_PERIPHRAM_FULL_STOP           // 外设RAM
#define PWR_PKA32RAM_FULL_STOP_RETENTION              PWR_PKA32RAM_FULL_STOP            // PKA32 RAM
#define PWR_GRAPHICPRAM_FULL_STOP_RETENTION           PWR_GRAPHICPRAM_FULL_STOP         // 图形RAM
#define PWR_DSIRAM_FULL_STOP_RETENTION                PWR_DSIRAM_FULL_STOP              // DSI RAM
#define PWR_JPEGRAM_FULL_STOP_RETENTION               PWR_JPEGRAM_FULL_STOP             // JPEG RAM

/* SRAM2 待机模式保持别名 */
#define PWR_SRAM2_PAGE1_STANDBY_RETENTION             PWR_SRAM2_PAGE1_STANDBY
#define PWR_SRAM2_PAGE2_STANDBY_RETENTION             PWR_SRAM2_PAGE2_STANDBY
#define PWR_SRAM2_FULL_STANDBY_RETENTION              PWR_SRAM2_FULL_STANDBY

/* SRAM 运行模式保持别名 */
#define PWR_SRAM1_FULL_RUN_RETENTION                  PWR_SRAM1_FULL_RUN
#define PWR_SRAM2_FULL_RUN_RETENTION                  PWR_SRAM2_FULL_RUN
#define PWR_SRAM3_FULL_RUN_RETENTION                  PWR_SRAM3_FULL_RUN
#define PWR_SRAM4_FULL_RUN_RETENTION                  PWR_SRAM4_FULL_RUN
#define PWR_SRAM5_FULL_RUN_RETENTION                  PWR_SRAM5_FULL_RUN
#define PWR_SRAM6_FULL_RUN_RETENTION                  PWR_SRAM6_FULL_RUN

#define PWR_ALL_RAM_RUN_RETENTION_MASK                PWR_ALL_RAM_RUN_MASK              // 所有RAM运行保持掩码
#endif

/**
  * @}
 */
