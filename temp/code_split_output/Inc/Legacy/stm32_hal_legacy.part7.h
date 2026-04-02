#if defined(STM32L0) || defined(STM32L4)
/** @defgroup HAL_COMP_Aliased_Functions HAL COMP Aliased Functions maintained for legacy purpose
  * @{
  */
// 定义 HAL_COMP_Start_IT 宏，指向 HAL_COMP_Start 函数
// 原因：旧版本的库使用 _IT 后缀表示中断模式，新版本中将 EXTI 事件或中断配置移到了 HAL_COMP_Init() 中处理，因此该函数被视为遗留函数
#define HAL_COMP_Start_IT       HAL_COMP_Start /* Function considered as legacy as EXTI event or IT configuration is 
                                                  done into HAL_COMP_Init() */
// 定义 HAL_COMP_Stop_IT 宏，指向 HAL_COMP_Stop 函数
// 原因：同上，停止中断模式的函数也被视为遗留函数，直接调用普通的停止函数即可
#define HAL_COMP_Stop_IT        HAL_COMP_Stop  /* Function considered as legacy as EXTI event or IT configuration is 
                                                  done into HAL_COMP_Init() */
/**
  * @}
  */
#endif

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC Aliased Macros maintained for legacy purpose
  * @{
  */

// DAC波形配置检查宏
// 参数 WAVE: 波形类型
// 检查输入参数是否为以下三种之一：无波形、噪声波形、三角波波形
#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_WAVE_NONE) || \
                           ((WAVE) == DAC_WAVE_NOISE)|| \
                           ((WAVE) == DAC_WAVE_TRIANGLE))

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Macros HAL FLASH Aliased Macros maintained for legacy purpose
  * @{
  */

// 以下是 FLASH 相关的宏定义别名，用于兼容旧代码
#define IS_WRPAREA          IS_OB_WRPAREA            // 检查是否为有效的写保护区域
#define IS_TYPEPROGRAM      IS_FLASH_TYPEPROGRAM     // 检查编程类型（如字节、半字、字等）
#define IS_TYPEPROGRAMFLASH IS_FLASH_TYPEPROGRAM     // 同上，针对 FLASH 编程类型的检查
#define IS_TYPEERASE        IS_FLASH_TYPEERASE       // 检查擦除类型（如页擦除、块擦除）
#define IS_NBSECTORS        IS_FLASH_NBSECTORS       // 检查扇区数量是否有效
#define IS_OB_WDG_SOURCE    IS_OB_IWDG_SOURCE        // 检查看门狗源设置

/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Macros HAL I2C Aliased Macros maintained for legacy purpose
  * @{
  */

// I2C 相关的宏定义别名，用于兼容旧代码
#define __HAL_I2C_RESET_CR2             I2C_RESET_CR2                // 复位 I2C CR2 寄存器
#define __HAL_I2C_GENERATE_START        I2C_GENERATE_START           // 生成起始条件
#if defined(STM32F1)
#define __HAL_I2C_FREQ_RANGE            I2C_FREQRANGE                // STM32F1系列专用：获取频率范围
#else
#define __HAL_I2C_FREQ_RANGE            I2C_FREQ_RANGE               // 其他系列：获取频率范围
#endif /* STM32F1 */
#define __HAL_I2C_RISE_TIME             I2C_RISE_TIME                // 计算上升时间
#define __HAL_I2C_SPEED_STANDARD        I2C_SPEED_STANDARD           // 标准速度模式配置 (100kHz)
#define __HAL_I2C_SPEED_FAST            I2C_SPEED_FAST               // 快速速度模式配置 (400kHz)
#define __HAL_I2C_SPEED                 I2C_SPEED                    // 速度配置
#define __HAL_I2C_7BIT_ADD_WRITE        I2C_7BIT_ADD_WRITE           // 生成7位地址写模式
#define __HAL_I2C_7BIT_ADD_READ         I2C_7BIT_ADD_READ            // 生成7位地址读模式
#define __HAL_I2C_10BIT_ADDRESS         I2C_10BIT_ADDRESS            // 生成10位地址
#define __HAL_I2C_10BIT_HEADER_WRITE    I2C_10BIT_HEADER_WRITE       // 生成10位地址头写模式
#define __HAL_I2C_10BIT_HEADER_READ     I2C_10BIT_HEADER_READ        // 生成10位地址头读模式
#define __HAL_I2C_MEM_ADD_MSB           I2C_MEM_ADD_MSB              // 获取内存地址的高字节
#define __HAL_I2C_MEM_ADD_LSB           I2C_MEM_ADD_LSB              // 获取内存地址的低字节
#define __HAL_I2C_FREQRANGE             I2C_FREQRANGE                // 频率范围定义
/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Macros HAL I2S Aliased Macros maintained for legacy purpose
  * @{
  */

// I2S (音频总线) 相关的宏定义别名
#define IS_I2S_INSTANCE                 IS_I2S_ALL_INSTANCE      // 检查是否为 I2S 实例
#define IS_I2S_INSTANCE_EXT             IS_I2S_ALL_INSTANCE_EXT  // 检查是否为扩展 I2S 实例

#if defined(STM32H7)
// STM32H7系列专用：清除 I2S 标志位
#define __HAL_I2S_CLEAR_FREFLAG       __HAL_I2S_CLEAR_TIFREFLAG
#endif

/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Macros HAL IRDA Aliased Macros maintained for legacy purpose
  * @{
  */

// IRDA (红外通信) 相关的宏定义别名
#define __IRDA_DISABLE                  __HAL_IRDA_DISABLE           // 禁用 IRDA
#define __IRDA_ENABLE                   __HAL_IRDA_ENABLE            // 使能 IRDA

#define __HAL_IRDA_GETCLOCKSOURCE       IRDA_GETCLOCKSOURCE          // 获取时钟源
#define __HAL_IRDA_MASK_COMPUTATION     IRDA_MASK_COMPUTATION        // 计算掩码
#define __IRDA_GETCLOCKSOURCE           IRDA_GETCLOCKSOURCE          // 获取时钟源（旧命名）
#define __IRDA_MASK_COMPUTATION         IRDA_MASK_COMPUTATION        // 计算掩码（旧命名）

#define IS_IRDA_ONEBIT_SAMPLE           IS_IRDA_ONE_BIT_SAMPLE       // 检查是否为单比特采样模式


/**
  * @}
  */


/** @defgroup HAL_IWDG_Aliased_Macros HAL IWDG Aliased Macros maintained for legacy purpose
  * @{
  */
// IWDG (独立看门狗) 相关的宏定义别名
#define __HAL_IWDG_ENABLE_WRITE_ACCESS  IWDG_ENABLE_WRITE_ACCESS   // 使能寄存器写访问（解锁）
#define __HAL_IWDG_DISABLE_WRITE_ACCESS IWDG_DISABLE_WRITE_ACCESS  // 禁用寄存器写访问（上锁）
/**
  * @}
  */


/** @defgroup HAL_LPTIM_Aliased_Macros HAL LPTIM Aliased Macros maintained for legacy purpose
  * @{
  */

// LPTIM (低功耗定时器) 相关的宏定义别名
#define __HAL_LPTIM_ENABLE_INTERRUPT    __HAL_LPTIM_ENABLE_IT    // 使能中断（旧命名使用了 Interrupt）
#define __HAL_LPTIM_DISABLE_INTERRUPT   __HAL_LPTIM_DISABLE_IT   // 禁用中断
#define __HAL_LPTIM_GET_ITSTATUS        __HAL_LPTIM_GET_IT_SOURCE // 获取中断源状态

/**
  * @}
  */


/** @defgroup HAL_OPAMP_Aliased_Macros HAL OPAMP Aliased Macros maintained for legacy purpose
  * @{
  */
// OPAMP (运算放大器) 相关的宏定义别名
// 以下宏主要用于操作 OPAMP 的 CSR (控制状态寄存器) 相关位
#define __OPAMP_CSR_OPAXPD                OPAMP_CSR_OPAXPD                // 运放电源使能位
#define __OPAMP_CSR_S3SELX                OPAMP_CSR_S3SELX                // 输入选择开关 S3
#define __OPAMP_CSR_S4SELX                OPAMP_CSR_S4SELX                // 输入选择开关 S4
#define __OPAMP_CSR_S5SELX                OPAMP_CSR_S5SELX                // 输入选择开关 S5
#define __OPAMP_CSR_S6SELX                OPAMP_CSR_S6SELX                // 输入选择开关 S6
#define __OPAMP_CSR_OPAXCAL_L             OPAMP_CSR_OPAXCAL_L             // 低端校准位
#define __OPAMP_CSR_OPAXCAL_H             OPAMP_CSR_OPAXCAL_H             // 高端校准位
#define __OPAMP_CSR_OPAXLPM               OPAMP_CSR_OPAXLPM               // 低功耗模式位
#define __OPAMP_CSR_ALL_SWITCHES          OPAMP_CSR_ALL_SWITCHES          // 所有开关配置
#define __OPAMP_CSR_ANAWSELX              OPAMP_CSR_ANAWSELX              // 模拟开关选择
#define __OPAMP_CSR_OPAXCALOUT            OPAMP_CSR_OPAXCALOUT            // 校准输出位
#define __OPAMP_OFFSET_TRIM_BITSPOSITION  OPAMP_OFFSET_TRIM_BITSPOSITION  // 偏移修剪位的位置
#define __OPAMP_OFFSET_TRIM_SET           OPAMP_OFFSET_TRIM_SET           // 设置偏移修剪值

/**
  * @}
  */


/** @defgroup HAL_PWR_Aliased_Macros HAL PWR Aliased Macros maintained for legacy purpose
  * @{
  */
// PWR (电源控制) 相关的宏定义别名
// PVD (可编程电压检测器) 相关
#define __HAL_PVD_EVENT_DISABLE                                  __HAL_PWR_PVD_EXTI_DISABLE_EVENT         // 禁用 PVD 事件
#define __HAL_PVD_EVENT_ENABLE                                   __HAL_PWR_PVD_EXTI_ENABLE_EVENT          // 使能 PVD 事件
#define __HAL_PVD_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE  // 禁用下降沿触发
#define __HAL_PVD_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE   // 使能下降沿触发
#define __HAL_PVD_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE   // 禁用上升沿触发
#define __HAL_PVD_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE    // 使能上升沿触发
// PVM (电源电压监测) 相关
#define __HAL_PVM_EVENT_DISABLE                                  __HAL_PWR_PVM_EVENT_DISABLE              // 禁用 PVM 事件
#define __HAL_PVM_EVENT_ENABLE                                   __HAL_PWR_PVM_EVENT_ENABLE               // 使能 PVM 事件
#define __HAL_PVM_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_DISABLE
#define __HAL_PVM_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_ENABLE
#define __HAL_PVM_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVM_EXTI_RISINGTRIGGER_DISABLE
#define __HAL_PVM_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVM_EXTI_RISINGTRIGGER_ENABLE
// 电源管理功能相关
#define __HAL_PWR_INTERNALWAKEUP_DISABLE                         HAL_PWREx_DisableInternalWakeUpLine      // 禁用内部唤醒线路
#define __HAL_PWR_INTERNALWAKEUP_ENABLE                          HAL_PWREx_EnableInternalWakeUpLine       // 使能内部唤醒线路
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_DISABLE                    HAL_PWREx_DisablePullUpPullDownConfig    // 禁用上下拉配置
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_ENABLE                     HAL_PWREx_EnablePullUpPullDownConfig     // 使能上下拉配置
// 清除 PVD 边沿触发配置（同时禁用上升沿和下降沿）
#define __HAL_PWR_PVD_EXTI_CLEAR_EGDE_TRIGGER()                  do { __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE(); \
                                                                      __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); \
                                                                    } while(0)
#define __HAL_PWR_PVD_EXTI_EVENT_DISABLE                         __HAL_PWR_PVD_EXTI_DISABLE_EVENT
#define __HAL_PWR_PVD_EXTI_EVENT_ENABLE                          __HAL_PWR_PVD_EXTI_ENABLE_EVENT
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_DISABLE                __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_ENABLE                 __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_DISABLE                 __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_ENABLE                  __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
#define __HAL_PWR_PVD_EXTI_SET_FALLING_EGDE_TRIGGER              __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE   // 设置下降沿触发
#define __HAL_PWR_PVD_EXTI_SET_RISING_EDGE_TRIGGER               __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE    // 设置上升沿触发
// 批量禁用 PVM1/2/3/4
#define __HAL_PWR_PVM_DISABLE()                                  do { HAL_PWREx_DisablePVM1();HAL_PWREx_DisablePVM2(); \
                                                                      HAL_PWREx_DisablePVM3();HAL_PWREx_DisablePVM4(); \
                                                                    } while(0)
// 批量使能 PVM1/2/3/4
#define __HAL_PWR_PVM_ENABLE()                                   do { HAL_PWREx_EnablePVM1();HAL_PWREx_EnablePVM2(); \
                                                                      HAL_PWREx_EnablePVM3();HAL_PWREx_EnablePVM4(); \
                                                                    } while(0)
// SRAM2 内容保留控制
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_DISABLE                  HAL_PWREx_DisableSRAM2ContentRetention  // 禁用 SRAM2 内容保留
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_ENABLE                   HAL_PWREx_EnableSRAM2ContentRetention   // 使能 SRAM2 内容保留
// VDDIO2 电源控制
#define __HAL_PWR_VDDIO2_DISABLE                                 HAL_PWREx_DisableVddIO2                 // 禁用 VDDIO2
#define __HAL_PWR_VDDIO2_ENABLE                                  HAL_PWREx_EnableVddIO2                  // 使能 VDDIO2
#define __HAL_PWR_VDDIO2_EXTI_CLEAR_EGDE_TRIGGER                 __HAL_PWR_VDDIO2_EXTI_DISABLE_FALLING_EDGE
#define __HAL_PWR_VDDIO2_EXTI_SET_FALLING_EGDE_TRIGGER           __HAL_PWR_VDDIO2_EXTI_ENABLE_FALLING_EDGE
// VDDUSB 电源控制
#define __HAL_PWR_VDDUSB_DISABLE                                 HAL_PWREx_DisableVddUSB                 // 禁用 VDDUSB
#define __HAL_PWR_VDDUSB_ENABLE                                  HAL_PWREx_EnableVddUSB                  // 使能 VDDUSB

#if defined (STM32F4)
// STM32F4 系列专用 PVD 宏，需要传递参数 PWR_EXTI_LINE_PVD
#define __HAL_PVD_EXTI_ENABLE_IT(PWR_EXTI_LINE_PVD)         __HAL_PWR_PVD_EXTI_ENABLE_IT()
#define __HAL_PVD_EXTI_DISABLE_IT(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_DISABLE_IT()
#define __HAL_PVD_EXTI_GET_FLAG(PWR_EXTI_LINE_PVD)          __HAL_PWR_PVD_EXTI_GET_FLAG()
#define __HAL_PVD_EXTI_CLEAR_FLAG(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_CLEAR_FLAG()
#define __HAL_PVD_EXTI_GENERATE_SWIT(PWR_EXTI_LINE_PVD)     __HAL_PWR_PVD_EXTI_GENERATE_SWIT()
#else
// 其他系列不需要参数
#define __HAL_PVD_EXTI_CLEAR_FLAG                                __HAL_PWR_PVD_EXTI_CLEAR_FLAG
#define __HAL_PVD_EXTI_DISABLE_IT                                __HAL_PWR_PVD_EXTI_DISABLE_IT
#define __HAL_PVD_EXTI_ENABLE_IT                                 __HAL_PWR_PVD_EXTI_ENABLE_IT
#define __HAL_PVD_EXTI_GENERATE_SWIT                             __HAL_PWR_PVD_EXTI_GENERATE_SWIT
#define __HAL_PVD_EXTI_GET_FLAG                                  __HAL_PWR_PVD_EXTI_GET_FLAG
#endif /* STM32F4 */
/**
  * @}
  */


/** @defgroup HAL_RCC_Aliased HAL RCC Aliased maintained for legacy purpose
  * @{
  */

// RCC (复位与时钟控制) 相关的宏定义别名
#define RCC_StopWakeUpClock_MSI     RCC_STOP_WAKEUPCLOCK_MSI     // 停机模式唤醒时钟选择 MSI
#define RCC_StopWakeUpClock_HSI     RCC_STOP_WAKEUPCLOCK_HSI     // 停机模式唤醒时钟选择 HSI

// 回调函数别名修正：CSS (时钟安全系统) 回调函数名称修正
#define HAL_RCC_CCSCallback HAL_RCC_CSSCallback
// RC48 使能缓冲命令，根据 cmd 参数使能或禁用 HSI48 的 VREFINT 缓冲
#define HAL_RC48_EnableBuffer_Cmd(cmd) (((cmd)==ENABLE) ? \
                                        HAL_RCCEx_EnableHSI48_VREFINT() : HAL_RCCEx_DisableHSI48_VREFINT())
