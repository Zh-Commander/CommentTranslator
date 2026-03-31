#define __HAL_COMP_GET_EXTI_LINE  COMP_GET_EXTI_LINE  // 获取比较器EXTI线的宏，映射到COMP_GET_EXTI_LINE

#if defined(STM32L0) || defined(STM32L4)
/* 注意：在这些STM32系列中，这个宏的唯一参数是COMP_FLAG_LOCK。                   */
/*       这个宏被__HAL_COMP_IS_LOCKED替换，只使用HAL句柄参数。                    */
#define __HAL_COMP_GET_FLAG(__HANDLE__, __FLAG__)  (__HAL_COMP_IS_LOCKED(__HANDLE__))  // 获取比较器标志的宏，但在STM32L0/L4上映射到__HAL_COMP_IS_LOCKED，仅检查锁定状态
#endif
/**
  * @}
  */

#if defined(STM32L0) || defined(STM32L4)
/** @defgroup HAL_COMP_Aliased_Functions HAL COMP 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_COMP_Start_IT       HAL_COMP_Start /* 该函数被视为遗留函数，因为EXTI事件或中断配置已在HAL_COMP_Init()中完成 */
#define HAL_COMP_Stop_IT        HAL_COMP_Stop  /* 该函数被视为遗留函数，因为EXTI事件或中断配置已在HAL_COMP_Init()中完成 */
/**
  * @}
  */
#endif

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC 别名宏，为向后兼容而保留
  * @{
  */

#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_WAVE_NONE) || \
                           ((WAVE) == DAC_WAVE_NOISE)|| \
                           ((WAVE) == DAC_WAVE_TRIANGLE))  // 检查DAC波形类型是否有效的宏，支持无波形、噪声波形和三角波形

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Macros HAL FLASH 别名宏，为向后兼容而保留
  * @{
  */

#define IS_WRPAREA          IS_OB_WRPAREA  // 检查写保护区域的宏，映射到IS_OB_WRPAREA
#define IS_TYPEPROGRAM      IS_FLASH_TYPEPROGRAM  // 检查编程类型的宏，映射到IS_FLASH_TYPEPROGRAM
#define IS_TYPEPROGRAMFLASH IS_FLASH_TYPEPROGRAM  // 检查Flash编程类型的宏，映射到IS_FLASH_TYPEPROGRAM
#define IS_TYPEERASE        IS_FLASH_TYPEERASE  // 检查擦除类型的宏，映射到IS_FLASH_TYPEERASE
#define IS_NBSECTORS        IS_FLASH_NBSECTORS  // 检查扇区数量的宏，映射到IS_FLASH_NBSECTORS
#define IS_OB_WDG_SOURCE    IS_OB_IWDG_SOURCE  // 检查看门狗时钟源的宏，映射到IS_OB_IWDG_SOURCE

/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Macros HAL I2C 别名宏，为向后兼容而保留
  * @{
  */

#define __HAL_I2C_RESET_CR2             I2C_RESET_CR2  // 重置I2C控制寄存器2的宏
#define __HAL_I2C_GENERATE_START        I2C_GENERATE_START  // 生成I2C起始条件的宏
#if defined(STM32F1)
#define __HAL_I2C_FREQ_RANGE            I2C_FREQRANGE  // 设置I2C频率范围的宏（STM32F1专用）
#else
#define __HAL_I2C_FREQ_RANGE            I2C_FREQ_RANGE  // 设置I2C频率范围的宏
#endif /* STM32F1 */
#define __HAL_I2C_RISE_TIME             I2C_RISE_TIME  // 设置I2C上升时间的宏
#define __HAL_I2C_SPEED_STANDARD        I2C_SPEED_STANDARD  // 设置I2C标准速度的宏
#define __HAL_I2C_SPEED_FAST            I2C_SPEED_FAST  // 设置I2C快速速度的宏
#define __HAL_I2C_SPEED                 I2C_SPEED  // 设置I2C速度的宏
#define __HAL_I2C_7BIT_ADD_WRITE        I2C_7BIT_ADD_WRITE  // 生成7位地址写操作的宏
#define __HAL_I2C_7BIT_ADD_READ         I2C_7BIT_ADD_READ  // 生成7位地址读操作的宏
#define __HAL_I2C_10BIT_ADDRESS         I2C_10BIT_ADDRESS  // 生成10位地址的宏
#define __HAL_I2C_10BIT_HEADER_WRITE    I2C_10BIT_HEADER_WRITE  // 生成10位地址写头部的宏
#define __HAL_I2C_10BIT_HEADER_READ     I2C_10BIT_HEADER_READ  // 生成10位地址读头部的宏
#define __HAL_I2C_MEM_ADD_MSB           I2C_MEM_ADD_MSB  // 设置内存地址高字节的宏
#define __HAL_I2C_MEM_ADD_LSB           I2C_MEM_ADD_LSB  // 设置内存地址低字节的宏
#define __HAL_I2C_FREQRANGE             I2C_FREQRANGE  // 设置I2C频率范围的宏（同__HAL_I2C_FREQ_RANGE）

/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Macros HAL I2S 别名宏，为向后兼容而保留
  * @{
  */

#define IS_I2S_INSTANCE                 IS_I2S_ALL_INSTANCE  // 检查I2S实例是否有效的宏，映射到IS_I2S_ALL_INSTANCE
#define IS_I2S_INSTANCE_EXT             IS_I2S_ALL_INSTANCE_EXT  // 检查扩展I2S实例是否有效的宏，映射到IS_I2S_ALL_INSTANCE_EXT

#if defined(STM32H7)
#define __HAL_I2S_CLEAR_FREFLAG       __HAL_I2S_CLEAR_TIFREFLAG  // 清除I2S帧错误标志的宏（STM32H7专用）
#endif

/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Macros HAL IRDA 别名宏，为向后兼容而保留
  * @{
  */

#define __IRDA_DISABLE                  __HAL_IRDA_DISABLE  // 禁用IRDA的宏，映射到__HAL_IRDA_DISABLE
#define __IRDA_ENABLE                   __HAL_IRDA_ENABLE  // 启用IRDA的宏，映射到__HAL_IRDA_ENABLE

#define __HAL_IRDA_GETCLOCKSOURCE       IRDA_GETCLOCKSOURCE  // 获取IRDA时钟源的宏
#define __HAL_IRDA_MASK_COMPUTATION     IRDA_MASK_COMPUTATION  // 计算IRDA掩码的宏
#define __IRDA_GETCLOCKSOURCE           IRDA_GETCLOCKSOURCE  // 获取IRDA时钟源的宏（同__HAL_AL_IRDA_GETCLOCKSOURCE）
#define __IRDA_MASK_COMPUTATION         IRDA_MASK_COMPUTATION  // 计算IRDA掩码的宏（同__HAL_IRDA_MASK_COMPUTATION）

#define IS_IRDA_ONEBIT_SAMPLE           IS_IRDA_ONE_BIT_SAMPLE  // 检查IRDA单比特采样是否有效的宏，映射到IS_IRDA_ONE_BIT_SAMPLE


/**
  * @}
  */


/** @defgroup HAL_IWDG_Aliased_Macros HAL IWDG 别名宏，为向后兼容而保留
  * @{
  */
#define __HAL_IWDG_ENABLE_WRITE_ACCESS  IWDG_ENABLE_WRITE_ACCESS  // 启用IWDG写访问的宏
#define __HAL_IWDG_DISABLE_WRITE_ACCESS IWDG_DISABLE_WRITE_ACCESS  // 禁用IWDG写访问的宏
/**
  * @}
  */


/** @defgroup HAL_LPTIM_Aliased_Macros HAL LPTIM 别名宏，为向后兼容而保留
  * @{
  */

#define __HAL_LPTIM_ENABLE_INTERRUPT    __HAL_LPTIM_ENABLE_IT  // 启用LPTIM中断的宏，映射到__HAL_LPTIM_ENABLE_IT
#define __HAL_LPTIM_DISABLE_INTERRUPT   __HAL_LPTIM_DISABLE_IT  // 禁用LPTIM中断的宏，映射到__HAL_LPTIM_DISABLE_IT
#define __HAL_LPTIM_GET_ITSTATUS        __HAL_LPTIM_GET_IT_SOURCE  // 获取LPTIM中断状态的宏，映射到__HAL_LPTIM_GET_IT_SOURCE

/**
  * @}
  */


/** @defgroup HAL_OPAMP_Aliased_Macros HAL OPAMP 别名宏，为向后兼容而保留
  * @{
  */
#define __OPAMP_CSR_OPAXPD                OPAMP_CSR_OPAXPD  // OPAMP控制寄存器中关断位字段的宏
#define __OPAMP_CSR_S3SELX                OPAMP_CSR_S3SELX  // OPAMP控制寄存器中S3选择位字段的宏
#define __OPAMP_CSR_S4SELX                OPAMP_CSR_S4SELX  // OPAMP控制寄存器中S4选择位字段的宏
#define __OPAMP_CSR_S5SELX                OPAMP_CSR_S5SELX  // OPAMP控制寄存器中S5选择位字段的宏
#define __OPAMP_CSR_S6SELX                OPAMP_CSR_S6SELX  // OPAMP控制寄存器中S6选择位字段的宏
#define __OPAMP_CSR_OPAXCAL_L             OPAMP_CSR_OPAXCAL_L  // OPAMP控制寄存器中校准低值位字段的宏
#define __OPAMP_CSR_OPAXCAL_H             OPAMP_CSR_OPAXCAL_H  // OPAMP控制寄存器中校准高值位字段的宏
#define __OPAMP_CSR_OPAXLPM               OPAMP_CSR_OPAXLPM  // OPAMP控制寄存器中低功耗模式位字段的宏
#define __OPAMP_CSR_ALL_SWITCHES          OPAMP_CSR_ALL_SWITCHES  // OPAMP控制寄存器中所有开关位字段的宏
#define __OPAMP_CSR_ANAWSELX              OPAMP_CSR_ANAWSELX  // OPAMP控制寄存器中模拟窗口选择位字段的宏
#define __OPAMP_CSR_OPAXCALOUT            OPAMP_CSR_OPAXCALOUT  // OPAMP控制寄存器中校准输出位字段的宏
#define __OPAMP_OFFSET_TRIM_BITSPOSITION  OPAMP_OFFSET_TRIM_BITSPOSITION  // OPAMP偏移修调位位置的宏
#define __OPAMP_OFFSET_TRIM_SET           OPAMP_OFFSET_TRIM_SET  // OPAMP偏移修调设置的宏

/**
  * @}
  */


/** @defgroup HAL_PWR_Aliased_Macros HAL PWR 别名宏，为向后兼容而保留
  * @{
  */
#define __HAL_PVD_EVENT_DISABLE                                  __HAL_PWR_PVD_EXTI_DISABLE_EVENT  // 禁用PVD事件中断的宏
#define __HAL_PVD_EVENT_ENABLE                                   __HAL_PWR_PVD_EXTI_ENABLE_EVENT  // 启用PVD事件中断的宏
#define __HAL_PVD_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE  // 禁用PVD EXTI下降沿触发的宏
#define __HAL_PVD_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE  // 启用PVD EXTI下降沿触发的宏
#define __HAL_PVD_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE  // 禁用PVD EXTI上升沿触发的宏
#define __HAL_PVD_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE  // 启用PVD EXTI上升沿触发的宏
#define __HAL_PVM_EVENT_DISABLE                                  __HAL_PWR_PVM_EVENT_DISABLE  // 禁用PVM事件中断的宏
#define __HAL_PVM_EVENT_ENABLE                                   __HAL_PWR_PVM_EVENT_ENABLE  // 启用PVM事件中断的宏
#define __HAL_PVM_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_DISABLE  // 禁用PVM EXTI下降沿触发的宏
#define __HAL_PVM_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_ENABLE  // 启用PVM EXTI下降沿触发的宏
#define __HAL_PVM_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVM_EXTI_RISINGTRIGGER_DISABLE  // 禁用PVM EXTI上升沿触发的宏
#define __HAL_PVM_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVM_EXTI_RISINGTRIGGER_ENABLE  // 启用PVM EXTI上升沿触发的宏
#define __HAL_PWR_INTERNALWAKEUP_DISABLE                         HAL_PWREx_DisableInternalWakeUpLine  // 禁用内部唤醒线的宏
#define __HAL_PWR_INTERNALWAKEUP_ENABLE                          HAL_PWREx_EnableInternalWakeUpLine  // 启用内部唤醒线的宏
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_DISABLE                    HAL_PWREx_DisablePullUpPullDownConfig  // 禁用上拉下拉配置的宏
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_ENABLE                     HAL_PWREx_EnablePullUpPullDownConfig  // 启用上拉下拉配置的宏
#define __HAL_PWR_PVD_EXTI_CLEAR_EGDE_TRIGGER()                  do { __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE(); \
                                                                      __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); \
                                                                    } while(0)  // 清除PVD EXTI边沿触发的宏，通过禁用上升沿和下降沿实现
#define __HAL_PWR_PVD_EXTI_EVENT_DISABLE                         __HAL_PWR_PVD_EXTI_DISABLE_EVENT  // 禁用PVD EXTI事件中断的宏
#define __HAL_PWR_PVD_EXTI_EVENT_ENABLE                          __HAL_PWR_PVD_EXTI_ENABLE_EVENT  // 启用PVD EXTI事件中断的宏
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_DISABLE                __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE  // 禁用PVD EXTI下降沿触发的宏
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_ENABLE                 __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE  // 启用PVD EXTI下降沿触发的宏
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_DISABLE                 __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE  // 禁用PVD EXTI上升沿触发的宏
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_ENABLE                  __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE  // 启用PVD EXTI上升沿触发的宏
#define __HAL_PWR_PVD_EXTI_SET_FALLING_EGDE_TRIGGER              __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE  // 设置PVD EXTI下降沿触发的宏
#define __HAL_PWR_PVD_EXTI_SET_RISING_EDGE_TRIGGER               __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE  // 设置PVD EXTI上升沿触发的宏
#define __HAL_PWR_PVM_DISABLE()                                  do { HAL_PWREx_DisablePVM1();HAL_PWREx_DisablePVM2(); \
                                                                      HAL_PWREx_DisablePVM3();HAL_PWREx_DisablePVM4(); \
                                                                    } while(0)  // 禁用所有PVM的宏
#define __HAL_PWR_PVM_ENABLE()                                   do { HAL_PWREx_EnablePVM1();HAL_PWREx_EnablePVM2(); \
                                                                      HAL_PWREx_EnablePVM3();HAL_PWREx_EnablePVM4(); \
                                                                    } while(0)  // 启用所有PVM的宏
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_DISABLE                  HAL_PWREx_DisableSRAM2ContentRetention  // 禁用SRAM2内容保留的宏
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_ENABLE                   HAL_PWREx_EnableSRAM2ContentRetention  // 启用SRAM2内容保留的宏
#define __HAL_PWR_VDDIO2_DISABLE                                 HAL_PWREx_DisableVddIO2  // 禁用VDDIO2电源的宏
#define __HAL_PWR_VDDIO2_ENABLE                                  HAL_PWREx_EnableVddIO2  // 启用VDDIO2电源的宏
#define __HAL_PWR_VDDIO2_EXTI_CLEAR_EGDE_TRIGGER                 __HAL_PWR_VDDIO2_EXTI_DISABLE_FALLING_EDGE  // 清除VDDIO2 EXTI边沿触发的宏
#define __HAL_PWR_VDDIO2_EXTI_SET_FALLING_EGDE_TRIGGER           __HAL_PWR_VDDIO2_EXTI_ENABLE_FALLING_EDGE  // 设置VDDIO2 EXTI下降沿触发的宏
#define __HAL_PWR_VDDUSB_DISABLE                                 HAL_PWREx_DisableVddUSB  // 禁用VDDUSB电源的宏
#define __HAL_PWR_VDDUSB_ENABLE                                  HAL_PWREx_EnableVddUSB  // 启用VDDUSB电源的宏