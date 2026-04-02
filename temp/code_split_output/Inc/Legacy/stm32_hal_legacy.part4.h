/** @defgroup HAL_DCMI_Aliased_Defines HAL DCMI Aliased Defines maintained for legacy purpose
  * @{
  */
/*
  * DCMI: Digital Camera Interface，数字摄像头接口
  * 下面的宏定义是为了兼容旧版本的代码，将旧的宏名称映射到新的宏名称
  * OVF: Overflow，溢出
  * OVR: Overrun，溢出（新版本命名）
  */
#define HAL_DCMI_ERROR_OVF      HAL_DCMI_ERROR_OVR       // DCMI错误标志：溢出错误，映射到新的OVR标志
#define DCMI_IT_OVF             DCMI_IT_OVR              // DCMI中断标志：溢出中断，映射到新的OVR标志
#define DCMI_FLAG_OVFRI         DCMI_FLAG_OVRRI          // DCMI状态标志：溢出原始中断标志，映射到新名称
#define DCMI_FLAG_OVFMI         DCMI_FLAG_OVRMI          // DCMI状态标志：溢出屏蔽中断标志，映射到新名称

/* CROP: 裁剪功能，用于设置摄像头捕获窗口 */
#define HAL_DCMI_ConfigCROP     HAL_DCMI_ConfigCrop      // 配置裁剪功能
#define HAL_DCMI_EnableCROP     HAL_DCMI_EnableCrop      // 使能裁剪功能
#define HAL_DCMI_DisableCROP    HAL_DCMI_DisableCrop     // 禁用裁剪功能

/**
  * @}
  */

/* 预编译判断：仅当芯片型号为 STM32L4, F7, 特定F4系列或H7时，以下代码才有效 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7)
/** @defgroup HAL_DMA2D_Aliased_Defines HAL DMA2D Aliased Defines maintained for legacy purpose
  * @{
  */
/*
  * DMA2D: Chrom-Art Accelerator，2D图形加速器
  * 下面定义主要是颜色模式的重命名
  * OUTPUT: 输出颜色格式
  * ARGB8888: 32位颜色，每通道8位 (Alpha, Red, Green, Blue)
  * RGB888: 24位颜色
  * RGB565: 16位颜色
  */
#define DMA2D_ARGB8888          DMA2D_OUTPUT_ARGB8888    // 输出格式：ARGB8888
#define DMA2D_RGB888            DMA2D_OUTPUT_RGB888      // 输出格式：RGB888
#define DMA2D_RGB565            DMA2D_OUTPUT_RGB565      // 输出格式：RGB565
#define DMA2D_ARGB1555          DMA2D_OUTPUT_ARGB1555    // 输出格式：ARGB1555
#define DMA2D_ARGB4444          DMA2D_OUTPUT_ARGB4444    // 输出格式：ARGB4444

/*
  * CM: Color Mode，输入颜色模式
  * INPUT: 输入颜色格式
  * L8: 8位 Luminance (亮度/灰度)
  * AL44: 4位 Alpha + 4位 Luminance
  * AL88: 8位 Alpha + 8位 Luminance
  * L4: 4位 Luminance
  * A8/A4: 8位/4位 Alpha only
  */
#define CM_ARGB8888             DMA2D_INPUT_ARGB8888     // 输入格式：ARGB8888
#define CM_RGB888               DMA2D_INPUT_RGB888       // 输入格式：RGB888
#define CM_RGB565               DMA2D_INPUT_RGB565       // 输入格式：RGB565
#define CM_ARGB1555             DMA2D_INPUT_ARGB1555     // 输入格式：ARGB1555
#define CM_ARGB4444             DMA2D_INPUT_ARGB4444     // 输入格式：ARGB4444
#define CM_L8                   DMA2D_INPUT_L8           // 输入格式：L8
#define CM_AL44                 DMA2D_INPUT_AL44         // 输入格式：AL44
#define CM_AL88                 DMA2D_INPUT_AL88         // 输入格式：AL88
#define CM_L4                   DMA2D_INPUT_L4           // 输入格式：L4
#define CM_A8                   DMA2D_INPUT_A8           // 输入格式：A8
#define CM_A4                   DMA2D_INPUT_A4           // 输入格式：A4
/**
  * @}
  */
#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 */

/* 预编译判断：支持 DMA2D 的芯片型号，增加了 STM32U5 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7) || defined(STM32U5)
/** @defgroup DMA2D_Aliases DMA2D API Aliases
  * @{
  */
/*
  * CLUT: Color Look-Up Table，颜色查找表
  * 此宏将旧的禁用CLUT函数名映射到新的中止CLUT加载函数名
  */
#define HAL_DMA2D_DisableCLUT       HAL_DMA2D_CLUTLoading_Abort    /*!< Aliased to HAL_DMA2D_CLUTLoading_Abort
                                                                        for compatibility with legacy code */
                                                                        // 别名映射到 HAL_DMA2D_CLUTLoading_Abort，用于兼容旧代码
/**
  * @}
  */

#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 || STM32U5 */

/** @defgroup HAL_PPP_Aliased_Defines HAL PPP Aliased Defines maintained for legacy purpose
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数部分 --------------------------------------------------------*/

/** @defgroup HAL_CRYP_Aliased_Functions HAL CRYP Aliased Functions maintained for legacy purpose
  * @{
  */
/* CRYP: Cryptography，加密处理器 */
#define HAL_CRYP_ComputationCpltCallback     HAL_CRYPEx_ComputationCpltCallback // 计算完成回调函数别名
/**
  * @}
  */

/** @defgroup HAL_DCACHE_Aliased_Functions HAL DCACHE Aliased Functions maintained for legacy purpose
  * @{
  */
/* DCACHE: Data Cache，数据缓存 */

#if defined(STM32U5)
/* 清除并无效化指定地址的数据缓存（旧名称 -> 新名称） */
#define HAL_DCACHE_CleanInvalidateByAddr     HAL_DCACHE_CleanInvalidByAddr
/* 中断模式下清除并无效化指定地址的数据缓存（旧名称 -> 新名称） */
#define HAL_DCACHE_CleanInvalidateByAddr_IT  HAL_DCACHE_CleanInvalidByAddr_IT
#endif /* STM32U5 */

/**
  * @}
  */

#if !defined(STM32F2)
/** @defgroup HASH_alias HASH API alias
  * @{
  */
/* HASH: 哈希处理器 */
#define HAL_HASHEx_IRQHandler   HAL_HASH_IRQHandler  /*!< Redirection for compatibility with legacy code */
                                                     // 重定向以兼容旧代码：哈希中断处理函数
/**
  *
  * @}
  */
#endif /* STM32F2 */
/** @defgroup HAL_HASH_Aliased_Functions HAL HASH Aliased Functions maintained for legacy purpose
  * @{
  */
/* 状态类型定义别名 */
#define HAL_HASH_STATETypeDef        HAL_HASH_StateTypeDef
/* 阶段类型定义别名 */
#define HAL_HASHPhaseTypeDef         HAL_HASH_PhaseTypeDef

/* HMAC (Hash-based Message Authentication Code) 完成函数别名 */
#define HAL_HMAC_MD5_Finish          HAL_HASH_MD5_Finish
#define HAL_HMAC_SHA1_Finish         HAL_HASH_SHA1_Finish
#define HAL_HMAC_SHA224_Finish       HAL_HASH_SHA224_Finish
#define HAL_HMAC_SHA256_Finish       HAL_HASH_SHA256_Finish

/*HASH Algorithm Selection*/
/* HASH 算法选择宏定义 */

#define HASH_AlgoSelection_SHA1      HASH_ALGOSELECTION_SHA1      // 选择 SHA1 算法
#define HASH_AlgoSelection_SHA224    HASH_ALGOSELECTION_SHA224    // 选择 SHA224 算法
#define HASH_AlgoSelection_SHA256    HASH_ALGOSELECTION_SHA256    // 选择 SHA256 算法
#define HASH_AlgoSelection_MD5       HASH_ALGOSELECTION_MD5       // 选择 MD5 算法

/* HASH 算法模式：是纯 HASH 还是 HMAC */
#define HASH_AlgoMode_HASH         HASH_ALGOMODE_HASH             // HASH 模式
#define HASH_AlgoMode_HMAC         HASH_ALGOMODE_HMAC             // HMAC 模式

/* HMAC 密钥类型：短密钥还是长密钥 */
#define HASH_HMACKeyType_ShortKey  HASH_HMAC_KEYTYPE_SHORTKEY     // 短密钥
#define HASH_HMACKeyType_LongKey   HASH_HMAC_KEYTYPE_LONGKEY      // 长密钥

#if defined(STM32L4) || defined(STM32L5) || defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)

/* HASH 累积函数别名：Accumulate -> Accmlt (Accumulate)
   累积函数用于分批次输入数据，不立即产生结果 */
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

/** @defgroup HAL_Aliased_Functions HAL Generic Aliased Functions maintained for legacy purpose
  * @{
  */
/* 调试相关函数别名：DBGMCU (Debug MCU) */
#define HAL_EnableDBGSleepMode HAL_DBGMCU_EnableDBGSleepMode       // 使能睡眠模式下的调试
#define HAL_DisableDBGSleepMode HAL_DBGMCU_DisableDBGSleepMode     // 禁用睡眠模式下的调试
#define HAL_EnableDBGStopMode HAL_DBGMCU_EnableDBGStopMode         // 使能停止模式下的调试
#define HAL_DisableDBGStopMode HAL_DBGMCU_DisableDBGStopMode       // 禁用停止模式下的调试
#define HAL_EnableDBGStandbyMode HAL_DBGMCU_EnableDBGStandbyMode   // 使能待机模式下的调试
#define HAL_DisableDBGStandbyMode HAL_DBGMCU_DisableDBGStandbyMode // 禁用待机模式下的调试

/* 低功耗配置宏函数：根据 cmd 参数使能或禁用低功耗配置 */
#define HAL_DBG_LowPowerConfig(Periph, cmd) (((cmd\
                                              )==ENABLE)? HAL_DBGMCU_DBG_EnableLowPowerConfig(Periph) : \
                                             HAL_DBGMCU_DBG_DisableLowPowerConfig(Periph))
/* 内部参考电压输出选择 */
#define HAL_VREFINT_OutputSelect  HAL_SYSCFG_VREFINT_OutputSelect

/* 锁定命令宏函数：用于锁定内部参考电压 */
#define HAL_Lock_Cmd(cmd) (((cmd)==ENABLE) ? HAL_SYSCFG_Enable_Lock_VREFINT() : HAL_SYSCFG_Disable_Lock_VREFINT())
#if defined(STM32L0)
#else
/* 内部参考电压使能/禁用命令 */
#define HAL_VREFINT_Cmd(cmd) (((cmd)==ENABLE)? HAL_SYSCFG_EnableVREFINT() : HAL_SYSCFG_DisableVREFINT())
#endif
/* ADC 缓冲使能命令 */
#define HAL_ADC_EnableBuffer_Cmd(cmd)  (((cmd)==ENABLE) ? HAL_ADCEx_EnableVREFINT() : HAL_ADCEx_DisableVREFINT())
/* ADC 温度传感器缓冲使能命令 */
#define HAL_ADC_EnableBufferSensor_Cmd(cmd) (((cmd\
                                              )==ENABLE) ?  HAL_ADCEx_EnableVREFINTTempSensor() : \
                                             HAL_ADCEx_DisableVREFINTTempSensor())
#if defined(STM32H7A3xx) || defined(STM32H7B3xx) || defined(STM32H7B0xx) || defined(STM32H7A3xxQ) || \
    defined(STM32H7B3xxQ) || defined(STM32H7B0xxQ)
/* H7系列特定域调试使能/禁用 */
#define HAL_EnableSRDomainDBGStopMode      HAL_EnableDomain3DBGStopMode
#define HAL_DisableSRDomainDBGStopMode     HAL_DisableDomain3DBGStopMode
#define HAL_EnableSRDomainDBGStandbyMode   HAL_EnableDomain3DBGStandbyMode
#define HAL_DisableSRDomainDBGStandbyMode  HAL_DisableDomain3DBGStandbyMode
#endif /* STM32H7A3xx || STM32H7B3xx || STM32H7B0xx || STM32H7A3xxQ || STM32H7B3xxQ  || STM32H7B0xxQ */

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Functions HAL FLASH Aliased Functions maintained for legacy purpose
  * @{
  */
/* FLASH 相关函数别名 */
#define FLASH_HalfPageProgram      HAL_FLASHEx_HalfPageProgram        // 半页编程
#define FLASH_EnableRunPowerDown   HAL_FLASHEx_EnableRunPowerDown     // 使能运行掉电模式
#define FLASH_DisableRunPowerDown  HAL_FLASHEx_DisableRunPowerDown    // 禁用运行掉电模式
/* DATA EEPROM 相关函数别名 (部分STM32系列Flash包含EEPROM区域) */
#define HAL_DATA_EEPROMEx_Unlock   HAL_FLASHEx_DATAEEPROM_Unlock      // 解锁数据EEPROM
#define HAL_DATA_EEPROMEx_Lock     HAL_FLASHEx_DATAEEPROM_Lock        // 锁定数据EEPROM
#define HAL_DATA_EEPROMEx_Erase    HAL_FLASHEx_DATAEEPROM_Erase       // 擦除数据EEPROM
#define HAL_DATA_EEPROMEx_Program  HAL_FLASHEx_DATAEEPROM_Program     // 编程数据EEPROM

/**
  * @}
 */

/** @defgroup HAL_I2C_Aliased_Functions HAL I2C Aliased Functions maintained for legacy purpose
  * @{
  */
/* I2C 滤波器配置函数别名 */
#define HAL_I2CEx_AnalogFilter_Config         HAL_I2CEx_ConfigAnalogFilter    // 配置模拟滤波器
#define HAL_I2CEx_DigitalFilter_Config        HAL_I2CEx_ConfigDigitalFilter   // 配置数字滤波器
/* FMPI2C: Fast Mode Plus I2C */
#define HAL_FMPI2CEx_AnalogFilter_Config      HAL_FMPI2CEx_ConfigAnalogFilter
#define HAL_FMPI2CEx_DigitalFilter_Config     HAL_FMPI2CEx_ConfigDigitalFilter

/* 快速模式Plus配置宏 */
#define HAL_I2CFastModePlusConfig(SYSCFG_I2CFastModePlus, cmd) (((cmd) == ENABLE)? \
                                                                HAL_I2CEx_EnableFastModePlus(SYSCFG_I2CFastModePlus): \
                                                                HAL_I2CEx_DisableFastModePlus(SYSCFG_I2CFastModePlus))

#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || \
    defined(STM32L4) || defined(STM32L5) || defined(STM32G4) || defined(STM32L1)
/* I2C 顺序传输函数别名：Sequential -> Seq */
#define HAL_I2C_Master_Sequential_Transmit_IT  HAL_I2C_Master_Seq_Transmit_IT
#define HAL_I2C_Master_Sequential_Receive_IT   HAL_I2C_Master_Seq_Receive_IT
#define HAL_I2C_Slave_Sequential_Transmit_IT   HAL_I2C_Slave_Seq_Transmit_IT
#define HAL_I2C_Slave_Sequential_Receive_IT    HAL_I2C_Slave_Seq_Receive_IT
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 ||
          STM32L4 || STM32L5 || STM32G4 || STM32L1 */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F4) || defined(STM32F7) || \
    defined(STM32L0) || defined(STM32L4) || defined(STM32L5) || defined(STM32G4)|| defined(STM32L1)
/* I2C DMA 顺序传输函数别名 */
#define HAL_I2C_Master_Sequential_Transmit_DMA HAL_I2C_Master_Seq_Transmit_DMA
#define HAL_I2C_Master_Sequential_Receive_DMA  HAL_I2C_Master_Seq_Receive_DMA
#define HAL_I2C_Slave_Sequential_Transmit_DMA  HAL_I2C_Slave_Seq_Transmit_DMA
#define HAL_I2C_Slave_Sequential_Receive_DMA   HAL_I2C_Slave_Seq_Receive_DMA
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F4 || STM32F7 || STM32L0 || STM32L4 || STM32L5 || STM32G4 || STM32L1 */

#if defined(STM32F4)
/* FMPI2C 顺序传输函数别名 (仅F4系列) */
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

/** @defgroup HAL_PWR_Aliased HAL PWR Aliased maintained for legacy purpose
  * @{
  */
/* PWR: Power Control，电源控制 */

#if defined(STM32G0)
/* PVD: Programmable Voltage Detector，可编程电压检测器 */
#define HAL_PWR_ConfigPVD                             HAL_PWREx_ConfigPVD
#define HAL_PWR_EnablePVD                             HAL_PWREx_EnablePVD
#define HAL_PWR_DisablePVD                            HAL_PWREx_DisablePVD
#define HAL_PWR_PVD_IRQHandler                        HAL_PWREx_PVD_IRQHandler
#endif
/* 电源控制相关函数别名 */
#define HAL_PWR_PVDConfig                             HAL_PWR_ConfigPVD
#define HAL_PWR_DisableBkUpReg                        HAL_PWREx_DisableBkUpReg          // 禁用备份域调节器
#define HAL_PWR_DisableFlashPowerDown                 HAL_PWREx_DisableFlashPowerDown  // 禁用Flash掉电
#define HAL_PWR_DisableVddio2Monitor                  HAL_PWREx_DisableVddio2Monitor   // 禁用VDDIO2监控
#define HAL_PWR_EnableBkUpReg                         HAL_PWREx_EnableBkUpReg           // 使能备份域调节器
#define HAL_PWR_EnableFlashPowerDown                  HAL_PWREx_EnableFlashPowerDown   // 使能Flash掉电
#define HAL_PWR_EnableVddio2Monitor                   HAL_PWREx_EnableVddio2Monitor    // 使能VDDIO2监控
#define HAL_PWR_PVD_PVM_IRQHandler                    HAL_PWREx_PVD_PVM_IRQHandler      // PVD/PVM中断处理
#define HAL_PWR_PVDLevelConfig                        HAL_PWR_ConfigPVD                 // PVD电平配置
#define HAL_PWR_Vddio2Monitor_IRQHandler              HAL_PWREx_Vddio2Monitor_IRQHandler
#define HAL_PWR_Vddio2MonitorCallback                 HAL_PWREx_Vddio2MonitorCallback
/* OverDrive: 过驱动模式，用于提高主频 */
#define HAL_PWREx_ActivateOverDrive                   HAL_PWREx_EnableOverDrive
#define HAL_PWREx_DeactivateOverDrive                 HAL_PWREx_DisableOverDrive
/* SDADC: Sigma-Delta ADC */
#define HAL_PWREx_DisableSDADCAnalog                  HAL_PWREx_DisableSDADC
#define HAL_PWREx_EnableSDADCAnalog                   HAL_PWREx_EnableSDADC
/* PVM: Peripheral Voltage Monitoring，外设电压监控 */
#define HAL_PWREx_PVMConfig                           HAL_PWREx_ConfigPVM

/* PWR 模式定义别名 */
#define PWR_MODE_NORMAL                               PWR_PVD_MODE_NORMAL               // 正常模式
#define PWR_MODE_IT_RISING                            PWR_PVD_MODE_IT_RISING            // 中断模式：上升沿
#define PWR_MODE_IT_FALLING                           PWR_PVD_MODE_IT_FALLING           // 中断模式：下降沿
#define PWR_MODE_IT_RISING_FALLING                    PWR_PVD_MODE_IT_RISING_FALLING    // 中断模式：双边沿
#define PWR_MODE_EVENT_RISING                         PWR_PVD_MODE_EVENT_RISING         // 事件模式：上升沿
#define PWR_MODE_EVENT_FALLING                        PWR_PVD_MODE_EVENT_FALLING        // 事件模式：下降沿
#define PWR_MODE_EVENT_RISING_FALLING                 PWR_PVD_MODE_EVENT_RISING_FALLING // 事件模式：双边沿

/* 位带操作相关别名 (Bit Banding) */
#define CR_OFFSET_BB                                  PWR_CR_OFFSET_BB
#define CSR_OFFSET_BB                                 PWR_CSR_OFFSET_BB
#define PMODE_BIT_NUMBER                              VOS_BIT_NUMBER
#define CR_PMODE_BB                                   CR_VOS_BB

/* 寄存器位编号别名 */
#define DBP_BitNumber                                 DBP_BIT_NUMBER
#define PVDE_BitNumber                                PVDE_BIT_NUMBER
#define PMODE_BitNumber                               PMODE_BIT_NUMBER
#define EWUP_BitNumber                                EWUP_BIT_NUMBER
#define FPDS_BitNumber                                FPDS_BIT_NUMBER
#define ODEN_BitNumber                                ODEN_BIT_NUMBER
#define ODSWEN_BitNumber                              ODSWEN_BIT_NUMBER
#define MRLVDS_BitNumber                              MRLVDS_BIT_NUMBER
#define LPLVDS_BitNumber                              LPLVDS_BIT_NUMBER
#define BRE_BitNumber                                 BRE_BIT_NUMBER

#define PWR_MODE_EVT                                  PWR_PVD_MODE_NORMAL

#if defined (STM32U5)
/* SRAM 页面停止模式保留配置别名 (U5系列支持低功耗下的RAM保留) */
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

#define PWR_SRAM2_PAGE1_STOP_RETENTION                PWR_SRAM2_PAGE1_STOP
#define PWR_SRAM2_PAGE2_STOP_RETENTION                PWR_SRAM2_PAGE2_STOP
#define PWR_SRAM2_FULL_STOP_RETENTION                 PWR_SRAM2_FULL_STOP

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

#define PWR_SRAM4_FULL_STOP_RETENTION                 PWR_SRAM4_FULL_STOP

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

#define PWR_SRAM6_PAGE1_STOP_RETENTION                PWR_SRAM6_PAGE1_STOP
#define PWR_SRAM6_PAGE2_STOP_RETENTION                PWR_SRAM6_PAGE2_STOP
#define PWR_SRAM6_PAGE3_STOP_RETENTION                PWR_SRAM6_PAGE3_STOP
#define PWR_SRAM6_PAGE4_STOP_RETENTION                PWR_SRAM6_PAGE4_STOP
#define PWR_SRAM6_PAGE5_STOP_RETENTION                PWR_SRAM6_PAGE5_STOP
#define PWR_SRAM6_PAGE6_STOP_RETENTION                PWR_SRAM6_PAGE6_STOP
#define PWR_SRAM6_PAGE7_STOP_RETENTION                PWR_SRAM6_PAGE7_STOP
#define PWR_SRAM6_PAGE8_STOP_RETENTION                PWR_SRAM6_PAGE8_STOP
#define PWR_SRAM6_FULL_STOP_RETENTION                 PWR_SRAM6_FULL_STOP

/* Cache 和外设 RAM 停止模式保留配置 */
#define PWR_ICACHE_FULL_STOP_RETENTION                PWR_ICACHE_FULL_STOP
#define PWR_DCACHE1_FULL_STOP_RETENTION               PWR_DCACHE1_FULL_STOP
#define PWR_DCACHE2_FULL_STOP_RETENTION               PWR_DCACHE2_FULL_STOP
#define PWR_DMA2DRAM_FULL_STOP_RETENTION              PWR_DMA2DRAM_FULL_STOP
#define PWR_PERIPHRAM_FULL_STOP_RETENTION             PWR_PERIPHRAM_FULL_STOP
#define PWR_PKA32RAM_FULL_STOP_RETENTION              PWR_PKA32RAM_FULL_STOP
#define PWR_GRAPHICPRAM_FULL_STOP_RETENTION           PWR_GRAPHICPRAM_FULL_STOP
#define PWR_DSIRAM_FULL_STOP_RETENTION                PWR_DSIRAM_FULL_STOP
#define PWR_JPEGRAM_FULL_STOP_RETENTION               PWR_JPEGRAM_FULL_STOP

/* 待机模式 RAM 保留配置 */
#define PWR_SRAM2_PAGE1_STANDBY_RETENTION             PWR_SRAM2_PAGE1_STANDBY
#define PWR_SRAM2_PAGE2_STANDBY_RETENTION             PWR_SRAM2_PAGE2_STANDBY
#define PWR_SRAM2_FULL_STANDBY_RETENTION              PWR_SRAM2_FULL_STANDBY

/* 运行模式 RAM 保留配置 */
#define PWR_SRAM1_FULL_RUN_RETENTION                  PWR_SRAM1_FULL_RUN
#define PWR_SRAM2_FULL_RUN_RETENTION                  PWR_SRAM2_FULL_RUN
#define PWR_SRAM3_FULL_RUN_RETENTION                  PWR_SRAM3_FULL_RUN
#define PWR_SRAM4_FULL_RUN_RETENTION                  PWR_SRAM4_FULL_RUN
#define PWR_SRAM5_FULL_RUN_RETENTION                  PWR_SRAM5_FULL_RUN
#define PWR_SRAM6_FULL_RUN_RETENTION                  PWR_SRAM6_FULL_RUN

#define PWR_ALL_RAM_RUN_RETENTION_MASK                PWR_ALL_RAM_RUN_MASK
#endif

/**
  * @}
 */
