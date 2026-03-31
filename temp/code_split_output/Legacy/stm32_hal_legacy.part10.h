/** @defgroup HAL_Aliased_Functions HAL通用别名函数（为保持向后兼容性而保留）
  * @{
  */
#define HAL_EnableDBGSleepMode HAL_DBGMCU_EnableDBGSleepMode                /* 使能调试模式下的睡眠模式 */
#define HAL_DisableDBGSleepMode HAL_DBGMCU_DisableDBGSleepMode              /* 禁用调试模式下的睡眠模式 */
#define HAL_EnableDBGStopMode HAL_DBGMCU_EnableDBGStopMode                  /* 使能调试模式下的停止模式 */
#define HAL_DisableDBGStopMode HAL_DBGMCU_DisableDBGStopMode                /* 禁用调试模式下的停止模式 */
#define HAL_EnableDBGStandbyMode HAL_DBGMCU_EnableDBGStandbyMode            /* 使能调试模式下的待机模式 */
#define HAL_DisableDBGStandbyMode HAL_DBGMCU_DisableDBGStandbyMode          /* 禁用调试模式下的待机模式 */
#define HAL_DBG_LowPowerConfig(Periph, cmd) (((cmd\
                                              )==ENABLE)? HAL_DBGMCU_DBG_EnableLowPowerConfig(Periph) : \
                                             HAL_DBGMCU_DBG_DisableLowPowerConfig(Periph)) /* 根据命令使能或禁用外设的低功耗调试配置 */
#define HAL_VREFINT_OutputSelect  HAL_SYSCFG_VREFINT_OutputSelect           /* 内部电压基准输出选择 */
#define HAL_Lock_Cmd(cmd) (((cmd)==ENABLE) ? HAL_SYSCFG_Enable_Lock_VREFINT() : HAL_SYSCFG_Disable_Lock_VREFINT()) /* 根据命令锁定或解锁内部电压基准 */
#if defined(STM32L0)
#else
#define HAL_VREFINT_Cmd(cmd) (((cmd)==ENABLE)? HAL_SYSCFG_EnableVREFINT() : HAL_SYSCFG_DisableVREFINT()) /* 根据命令使能或禁用内部电压基准 */
#endif
#define HAL_ADC_EnableBuffer_Cmd(cmd)  (((cmd)==ENABLE) ? HAL_ADCEx_EnableVREFINT() : HAL_ADCEx_DisableVREFINT()) /* 根据命令使能或禁用ADC内部电压基准缓冲 */
#define HAL_ADC_EnableBufferSensor_Cmd(cmd) (((cmd\
                                              )==ENABLE) ?  HAL_ADCEx_EnableVREFINTTempSensor() : \
                                             HAL_ADCEx_DisableVREFINTTempSensor()) /* 根据命令使能或禁用ADC内部电压基准温度传感器缓冲 */
#if defined(STM32H7A3xx) || defined(STM32H7B3xx) || defined(STM32H7B0xx) || defined(STM32H7A3xxQ) || \
    defined(STM32H7B3xxQ) || defined(STM32H7B0xxQ)
#define HAL_EnableSRDomainDBGStopMode      HAL_EnableDomain3DBGStopMode     /* 使能SR域调试停止模式 */
#define HAL_DisableSRDomainDBGStopMode     HAL_DisableDomain3DBGStopMode    /* 禁用SR域调试停止模式 */
#define HAL_EnableSRDomainDBGStandbyMode   HAL_EnableDomain3DBGStandbyMode  /* 使能SR域调试待机模式 */
#define HAL_DisableSRDomainDBGStandbyMode  HAL_DisableDomain3DBGStandbyMode /* 禁用SR域调试待机模式 */
#endif /* STM32H7A3xx || STM32H7B3xx || STM32H7B0xx || STM32H7A3xxQ || STM32H7B3xxQ  || STM32H7B0xxQ */

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Functions HAL FLASH别名函数（为保持向后兼容性而保留）
  * @{
  */
#define FLASH_HalfPageProgram      HAL_FLASHEx_HalfPageProgram              /* FLASH半页编程 */
#define FLASH_EnableRunPowerDown   HAL_FLASHEx_EnableRunPowerDown           /* 使能运行时的掉电模式 */
#define FLASH_DisableRunPowerDown  HAL_FLASHEx_DisableRunPowerDown          /* 禁用运行时的掉电模式 */
#define HAL_DATA_EEPROMEx_Unlock   HAL_FLASHEx_DATAEEPROM_Unlock            /* 解锁数据EEPROM */
#define HAL_DATA_EEPROMEx_Lock     HAL_FLASHEx_DATAEEPROM_Lock              /* 锁定数据EEPROM */
#define HAL_DATA_EEPROMEx_Erase    HAL_FLASHEx_DATAEEPROM_Erase             /* 擦除数据EEPROM */
#define HAL_DATA_EEPROMEx_Program  HAL_FLASHEx_DATAEEPROM_Program           /* 编程数据EEPROM */

/**
  * @}
 */

/** @defgroup HAL_I2C_Aliased_Functions HAL I2C别名函数（为保持向后兼容性而保留）
  * @{
  */
#define HAL_I2CEx_AnalogFilter_Config         HAL_I2CEx_ConfigAnalogFilter      /* 配置I2C模拟滤波器 */
#define HAL_I2CEx_DigitalFilter_Config        HAL_I2CEx_ConfigDigitalFilter     /* 配置I2C数字滤波器 */
#define HAL_FMPI2CEx_AnalogFilter_Config      HAL_FMPI2CEx_ConfigAnalogFilter   /* 配置FMPI2C模拟滤波器 */
#define HAL_FMPI2CEx_DigitalFilter_Config     HAL_FMPI2CEx_ConfigDigitalFilter  /* 配置FMPI2C数字滤波器 */

#define HAL_I2CFastModePlusConfig(SYSCFG_I2CFastModePlus, cmd) (((cmd) == ENABLE)? \
                                                                HAL_I2CEx_EnableFastModePlus(SYSCFG_I2CFastModePlus): \
                                                                HAL_I2CEx_DisableFastModePlus(SYSCFG_I2CFastModePlus)) /* 根据命令使能或禁用I2C快速模式+ */

#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || \
    defined(STM32L4) || defined(STM32L5) || defined(STM32G4) || defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_IT  HAL_I2C_Master_Seq_Transmit_IT   /* 主模式顺序发送（中断方式） */
#define HAL_I2C_Master_Sequential_Receive_IT   HAL_I2C_Master_Seq_Receive_IT    /* 主模式顺序接收（中断方式） */
#define HAL_I2C_Slave_Sequential_Transmit_IT   HAL_I2C_Slave_Seq_Transmit_IT    /* 从模式顺序发送（中断方式） */
#define HAL_I2C_Slave_Sequential_Receive_IT    HAL_I2C_Slave_Seq_Receive_IT     /* 从模式顺序接收（中断方式） */
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 ||
          STM32L4 || STM32L5 || STM32G4 || STM32L1 */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F4) || defined(STM32F7) || \
    defined(STM32L0) || defined(STM32L4) || defined(STM32L5) || defined(STM32G4)|| defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_DMA HAL_I2C_Master_Seq_Transmit_DMA  /* 主模式顺序发送（DMA方式） */
#define HAL_I2C_Master_Sequential_Receive_DMA  HAL_I2C_Master_Seq_Receive_DMA   /* 主模式顺序接收（DMA方式） */
#define HAL_I2C_Slave_Sequential_Transmit_DMA  HAL_I2C_Slave_Seq_Transmit_DMA   /* 从模式顺序发送（DMA方式） */
#define HAL_I2C_Slave_Sequential_Receive_DMA   HAL_I2C_Slave_Seq_Receive_DMA    /* 从模式顺序接收（DMA方式） */
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F4 || STM32F7 || STM32L0 || STM32L4 || STM32L5 || STM32G4 || STM32L1 */

#if defined(STM32F4)
#define HAL_FMPI2C_Master_Sequential_Transmit_IT  HAL_FMPI2C_Master_Seq_Transmit_IT   /* FMPI2C主模式顺序发送（中断方式） */
#define HAL_FMPI2C_Master_Sequential_Receive_IT   HAL_FMPI2C_Master_Seq_Receive_IT    /* FMPI2C主模式顺序接收（中断方式） */
#define HAL_FMPI2C_Slave_Sequential_Transmit_IT   HAL_FMPI2C_Slave_Seq_Transmit_IT    /* FMPI2C从模式顺序发送（中断方式） */
#define HAL_FMPI2C_Slave_Sequential_Receive_IT    HAL_FMPI2C_Slave_Seq_Receive_IT     /* FMPI2C从模式顺序接收（中断方式） */
#define HAL_FMPI2C_Master_Sequential_Transmit_DMA HAL_FMPI2C_Master_Seq_Transmit_DMA  /* FMPI2C主模式顺序发送（DMA方式） */
#define HAL_FMPI2C_Master_Sequential_Receive_DMA  HAL_FMPI2C_Master_Seq_Receive_DMA   /* FMPI2C主模式顺序接收（DMA方式） */
#define HAL_FMPI2C_Slave_Sequential_Transmit_DMA  HAL_FMPI2C_Slave_Seq_Transmit_DMA   /* FMPI2C从模式顺序发送（DMA方式） */
#define HAL_FMPI2C_Slave_Sequential_Receive_DMA   HAL_FMPI2C_Slave_Seq_Receive_DMA    /* FMPI2C从模式顺序接收（DMA方式） */
#endif /* STM32F4 */
/**
  * @}
 */

/** @defgroup HAL_PWR_Aliased HAL PWR别名（为保持向后兼容性而保留）
  * @{
  */

#if defined(STM32G0)
#define HAL_PWR_ConfigPVD                             HAL_PWREx_ConfigPVD       /* 配置可编程电压检测器 */
#define HAL_PWR_EnablePVD                             HAL_PWREx_EnablePVD       /* 使能可编程电压检测器 */
#define HAL_PWR_DisablePVD                            HAL_PWREx_DisablePVD      /* 禁用可编程电压检测器 */
#define HAL_PWR_PVD_IRQHandler                        HAL_PWREx_PVD_IRQHandler  /* 可编程电压检测器中断处理函数 */
#endif
#define HAL_PWR_PVDConfig                             HAL_PWR_ConfigPVD         /* 配置可编程电压检测器 */
#define HAL_PWR_DisableBkUpReg                        HAL_PWREx_DisableBkUpReg  /* 禁用备份寄存器 */
#define HAL_PWR_DisableFlashPowerDown                 HAL_PWREx_DisableFlashPowerDown /* 禁用Flash掉电模式 */
#define HAL_PWR_DisableVddio2Monitor                  HAL_PWREx_DisableVddio2Monitor   /* 禁用VDDIO2监控 */
#define HAL_PWR_EnableBkUpReg                         HAL_PWREx_EnableBkUpReg   /* 使能备份寄存器 */
#define HAL_PWR_EnableFlashPowerDown                  HAL_PWREx_EnableFlashPowerDown   /* 使能Flash掉电模式 */
#define HAL_PWR_EnableVddio2Monitor                   HAL_PWREx_EnableVddio2Monitor    /* 使能VDDIO2监控 */
#define HAL_PWR_PVD_PVM_IRQHandler                    HAL_PWREx_PVD_PVM_IRQHandler     /* 可编程电压检测器和可编程电压监视器中断处理函数 */
#define HAL_PWR_PVDLevelConfig                        HAL_PWR_ConfigPVD         /* 配置可编程电压检测器电平 */
#define HAL_PWR_Vddio2Monitor_IRQHandler              HAL_PWREx_Vddio2Monitor_IRQHandler /* VDDIO2监控中断处理函数 */
#define HAL_PWR_Vddio2MonitorCallback                 HAL_PWREx_Vddio2MonitorCallback  /* VDDIO2监控回调函数 */
#define HAL_PWREx_ActivateOverDrive                   HAL_PWREx_EnableOverDrive       /* 激活过驱动模式 */
#define HAL_PWREx_DeactivateOverDrive                 HAL_PWREx_DisableOverDrive      /* 取消激活过驱动模式 */
#define HAL_PWREx_DisableSDADCAnalog                  HAL_PWREx_DisableSDADC          /* 禁用SDADC模拟部分 */
#define HAL_PWREx_EnableSDADCAnalog                   HAL_PWREx_EnableSDADC           /* 使能SDADC模拟部分 */
#define HAL_PWREx_PVMConfig                           HAL_PWREx_ConfigPVM             /* 配置可编程电压监视器 */

#define PWR_MODE_NORMAL                               PWR_PVD_MODE_NORMAL            /* 正常模式 */
#define PWR_MODE_IT_RISING                            PWR_PVD_MODE_IT_RISING         /* 上升沿中断模式 */
#define PWR_MODE_IT_FALLING                           PWR_PVD_MODE_IT_FALLING        /* 下降沿中断模式 */
#define PWR_MODE_IT_RISING_FALLING                    PWR_PVD_MODE_IT_RISING_FALLING /* 上升沿和下降沿中断模式 */
#define PWR_MODE_EVENT_RISING                         PWR_PVD_MODE_EVENT_RISING      /* 上升沿事件模式 */
#define PWR_MODE_EVENT_FALLING                        PWR_PVD_MODE_EVENT_FALLING     /* 下降沿事件模式 */
#define PWR_MODE_EVENT_RISING_FALLING                 PWR_PVD_MODE_EVENT_RISING_FALLING /* 上升沿和下降沿事件模式 */

#define CR_OFFSET_BB                                  PWR_CR_OFFSET_BB               /* 控制寄存器位带偏移量 */
#define CSR_OFFSET_BB                                 PWR_CSR_OFFSET_BB              /* 控制/状态寄存器位带偏移量 */
#define PMODE_BIT_NUMBER                              VOS_BIT_NUMBER                 /* 电源模式位编号 */
#define CR_PMODE_BB                                   CR_VOS_BB                      /* 控制寄存器电源模式位带别名 */

#define DBP_BitNumber                                 DBP_BIT_NUMBER                 /* 禁用备份保护位编号 */
#define PVDE_BitNumber                                PVDE_BIT_NUMBER                /* 可编程电压检测器使能位编号 */
#define PMODE_BitNumber                               PMODE_BIT_NUMBER               /* 电源模式位编号 */
#define EWUP_BitNumber                                EWUP_BIT_NUMBER                /* 使能唤醒引脚位编号 */
#define FPDS_BitNumber                                FPDS_BIT_NUMBER                /* Flash掉电模式使能位编号 */
#define ODEN_BitNumber                                ODEN_BIT_NUMBER                /* 过驱动使能位编号 */
#define ODSWEN_BitNumber                              ODSWEN_BIT_NUMBER              /* 过驱动软件使能位编号 */
#define MRLVDS_BitNumber                              MRLVDS_BIT_NUMBER              /* 主调节器低电压检测状态位编号 */
#define LPLVDS_BitNumber                              LPLVDS_BIT_NUMBER              /* 低功耗调节器低电压检测状态位编号 */
#define BRE_BitNumber                                 BRE_BIT_NUMBER                 /* 备份寄存器复位使能位编号 */

#define PWR_MODE_EVT                                  PWR_PVD_MODE_NORMAL            /* 事件模式（已弃用，使用正常模式） */

#if defined (STM32U5)
#define PWR_SRAM1_PAGE1_STOP_RETENTION                PWR_SRAM1_PAGE1_STOP           /* SRAM1页1在停止模式下保持数据 */
#define PWR_SRAM1_PAGE2_STOP_RETENTION                PWR_SRAM1_PAGE2_STOP           /* SRAM1页2在停止模式下保持数据 */
#define PWR_SRAM1_PAGE3_STOP_RETENTION                PWR_SRAM1_PAGE3_STOP           /* SRAM1页3在停止模式下保持数据 */
#define PWR_SRAM1_PAGE4_STOP_RETENTION                PWR_SRAM1_PAGE4_STOP           /* SRAM1页4在停止模式下保持数据 */
#define PWR_SRAM1_PAGE5_STOP_RETENTION                PWR_SRAM1_PAGE5_STOP           /* SRAM1页5在停止模式下保持数据 */
#define PWR_SRAM1_PAGE6_STOP_RETENTION                PWR_SRAM1_PAGE6_STOP           /* SRAM1页6在停止模式下保持数据 */
#define PWR_SRAM1_PAGE7_STOP_RETENTION                PWR_SRAM1_PAGE7_STOP           /* SRAM1页7在停止模式下保持数据 */
#define PWR_SRAM1_PAGE8_STOP_RETENTION                PWR_SRAM1_PAGE8_STOP           /* SRAM1页8在停止模式下保持数据 */
#define PWR_SRAM1_PAGE9_STOP_RETENTION                PWR_SRAM1_PAGE9_STOP           /* SRAM1页9在停止模式下保持数据 */
#define PWR_SRAM1_PAGE10_STOP_RETENTION               PWR_SRAM1_PAGE10_STOP          /* SRAM1页10在停止模式下保持数据 */
#define PWR_SRAM1_PAGE11_STOP_RETENTION               PWR_SRAM1_PAGE11_STOP          /* SRAM1页11在停止模式下保持数据 */
#define PWR_SRAM1_PAGE12_STOP_RETENTION               PWR_SRAM1_PAGE12_STOP          /* SRAM1页12在停止模式下保持数据 */
#define PWR_SRAM1_FULL_STOP_RETENTION                 PWR_SRAM1_FULL_STOP            /* SRAM1全部分区在停止模式下保持数据 */

#define PWR_SRAM2_PAGE1_STOP_RETENTION                PWR_SRAM2_PAGE1_STOP           /* SRAM2页1在停止模式下保持数据 */
#define PWR_SRAM2_PAGE2_STOP_RETENTION                PWR_SRAM2_PAGE2_STOP           /* SRAM2页2在停止模式下保持数据 */
#define PWR_SRAM2_FULL_STOP_RETENTION                 PWR_SRAM2_FULL_STOP            /* SRAM2全部分区在停止模式下保持数据 */