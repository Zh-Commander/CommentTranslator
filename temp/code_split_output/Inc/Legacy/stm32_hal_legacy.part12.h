/* DFSDM (数字滤波器) 相关宏定义别名，用于兼容旧版本代码 */
#define __HAL_RCC_DFSDM_CLK_ENABLE             __HAL_RCC_DFSDM1_CLK_ENABLE              // 使能 DFSDM1 时钟
#define __HAL_RCC_DFSDM_CLK_DISABLE            __HAL_RCC_DFSDM1_CLK_DISABLE             // 禁止 DFSDM1 时钟
#define __HAL_RCC_DFSDM_IS_CLK_ENABLED         __HAL_RCC_DFSDM1_IS_CLK_ENABLED          // 检查 DFSDM1 时钟是否已使能
#define __HAL_RCC_DFSDM_IS_CLK_DISABLED        __HAL_RCC_DFSDM1_IS_CLK_DISABLED         // 检查 DFSDM1 时钟是否已禁止
#define __HAL_RCC_DFSDM_FORCE_RESET            __HAL_RCC_DFSDM1_FORCE_RESET             // 强制复位 DFSDM1
#define __HAL_RCC_DFSDM_RELEASE_RESET          __HAL_RCC_DFSDM1_RELEASE_RESET           // 释放 DFSDM1 复位
#define __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE       __HAL_RCC_DFSDM1_CLK_SLEEP_ENABLE        // 睡眠模式下使能 DFSDM1 时钟
#define __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE      __HAL_RCC_DFSDM1_CLK_SLEEP_DISABLE       // 睡眠模式下禁止 DFSDM1 时钟
#define __HAL_RCC_DFSDM_IS_CLK_SLEEP_ENABLED   __HAL_RCC_DFSDM1_IS_CLK_SLEEP_ENABLED    // 检查睡眠模式下 DFSDM1 时钟是否已使能
#define __HAL_RCC_DFSDM_IS_CLK_SLEEP_DISABLED  __HAL_RCC_DFSDM1_IS_CLK_SLEEP_DISABLED   // 检查睡眠模式下 DFSDM1 时钟是否已禁止

/* DFSDM 时钟源配置相关别名 */
#define DfsdmClockSelection         Dfsdm1ClockSelection     // DFSDM 时钟选择别名
#define RCC_PERIPHCLK_DFSDM         RCC_PERIPHCLK_DFSDM1     // DFSDM 外设时钟定义
#define RCC_DFSDMCLKSOURCE_PCLK     RCC_DFSDM1CLKSOURCE_PCLK2   // DFSDM 时钟源选择 PCLK
#define RCC_DFSDMCLKSOURCE_SYSCLK   RCC_DFSDM1CLKSOURCE_SYSCLK // DFSDM 时钟源选择系统时钟
#define __HAL_RCC_DFSDM_CONFIG      __HAL_RCC_DFSDM1_CONFIG     // 配置 DFSDM 时钟源宏
#define __HAL_RCC_GET_DFSDM_SOURCE  __HAL_RCC_GET_DFSDM1_SOURCE // 获取 DFSDM 时钟源宏
#define RCC_DFSDM1CLKSOURCE_PCLK    RCC_DFSDM1CLKSOURCE_PCLK2   // DFSDM1 时钟源 PCLK 定义

/* 其他外设时钟源别名 */
#define RCC_SWPMI1CLKSOURCE_PCLK    RCC_SWPMI1CLKSOURCE_PCLK1   // SWPMI1 时钟源选择 PCLK1

#if !defined(STM32U0)
#define RCC_LPTIM1CLKSOURCE_PCLK    RCC_LPTIM1CLKSOURCE_PCLK1   // LPTIM1 时钟源选择 PCLK1
#define RCC_LPTIM2CLKSOURCE_PCLK    RCC_LPTIM2CLKSOURCE_PCLK1   // LPTIM2 时钟源选择 PCLK1
#endif

/* DFSDM 音频时钟源别名定义 */
#define RCC_DFSDM1AUDIOCLKSOURCE_I2SAPB1    RCC_DFSDM1AUDIOCLKSOURCE_I2S1  // DFSDM1 音频时钟源来自 I2S1 (APB1)
#define RCC_DFSDM1AUDIOCLKSOURCE_I2SAPB2    RCC_DFSDM1AUDIOCLKSOURCE_I2S2  // DFSDM1 音频时钟源来自 I2S2 (APB2)
#define RCC_DFSDM2AUDIOCLKSOURCE_I2SAPB1    RCC_DFSDM2AUDIOCLKSOURCE_I2S1  // DFSDM2 音频时钟源来自 I2S1 (APB1)
#define RCC_DFSDM2AUDIOCLKSOURCE_I2SAPB2    RCC_DFSDM2AUDIOCLKSOURCE_I2S2  // DFSDM2 音频时钟源来自 I2S2 (APB2)

/* DFSDM 时钟源 APB 总线别名 */
#define RCC_DFSDM1CLKSOURCE_APB2            RCC_DFSDM1CLKSOURCE_PCLK2     // DFSDM1 时钟源 APB2
#define RCC_DFSDM2CLKSOURCE_APB2            RCC_DFSDM2CLKSOURCE_PCLK2     // DFSDM2 时钟源 APB2
#define RCC_FMPI2C1CLKSOURCE_APB            RCC_FMPI2C1CLKSOURCE_PCLK1    // FMPI2C1 时钟源 APB

/* 针对 STM32U5 系列的特定宏定义别名 */
#if defined(STM32U5)
#define MSIKPLLModeSEL                        RCC_MSIKPLL_MODE_SEL        // MSI 时钟 PLL 模式选择
#define MSISPLLModeSEL                        RCC_MSISPLL_MODE_SEL        // MSI 系统 PLL 模式选择
#define __HAL_RCC_AHB21_CLK_DISABLE           __HAL_RCC_AHB2_1_CLK_DISABLE  // 关闭 AHB2_1 时钟
#define __HAL_RCC_AHB22_CLK_DISABLE           __HAL_RCC_AHB2_2_CLK_DISABLE  // 关闭 AHB2_2 时钟
#define __HAL_RCC_AHB1_CLK_Disable_Clear      __HAL_RCC_AHB1_CLK_ENABLE     // AHB1 时钟禁用清除（别名）
#define __HAL_RCC_AHB21_CLK_Disable_Clear     __HAL_RCC_AHB2_1_CLK_ENABLE   // AHB2_1 时钟禁用清除（别名）
#define __HAL_RCC_AHB22_CLK_Disable_Clear     __HAL_RCC_AHB2_2_CLK_ENABLE   // AHB2_2 时钟禁用清除（别名）
#define __HAL_RCC_AHB3_CLK_Disable_Clear      __HAL_RCC_AHB3_CLK_ENABLE     // AHB3 时钟禁用清除（别名）
#define __HAL_RCC_APB1_CLK_Disable_Clear      __HAL_RCC_APB1_CLK_ENABLE     // APB1 时钟禁用清除（别名）
#define __HAL_RCC_APB2_CLK_Disable_Clear      __HAL_RCC_APB2_CLK_ENABLE     // APB2 时钟禁用清除（别名）
#define __HAL_RCC_APB3_CLK_Disable_Clear      __HAL_RCC_APB3_CLK_ENABLE     // APB3 时钟禁用清除（别名）
#define IS_RCC_MSIPLLModeSelection            IS_RCC_MSIPLLMODE_SELECT      // 检查 MSI PLL 模式选择参数

/* CLK48 (USB/SDIO/RNG) 时钟源别名 */
#define RCC_PERIPHCLK_CLK48                   RCC_PERIPHCLK_ICLK           // 外设时钟 CLK48 别名
#define RCC_CLK48CLKSOURCE_HSI48              RCC_ICLK_CLKSOURCE_HSI48     // CLK48 时钟源选择 HSI48
#define RCC_CLK48CLKSOURCE_PLL2               RCC_ICLK_CLKSOURCE_PLL2      // CLK48 时钟源选择 PLL2
#define RCC_CLK48CLKSOURCE_PLL1               RCC_ICLK_CLKSOURCE_PLL1      // CLK48 时钟源选择 PLL1
#define RCC_CLK48CLKSOURCE_MSIK               RCC_ICLK_CLKSOURCE_MSIK      // CLK48 时钟源选择 MSIK

/* ADC1 外设时钟控制别名 */
#define __HAL_RCC_ADC1_CLK_ENABLE             __HAL_RCC_ADC12_CLK_ENABLE   // 使能 ADC1 时钟
#define __HAL_RCC_ADC1_CLK_DISABLE            __HAL_RCC_ADC12_CLK_DISABLE  // 禁止 ADC1 时钟
#define __HAL_RCC_ADC1_IS_CLK_ENABLED         __HAL_RCC_ADC12_IS_CLK_ENABLED  // 检查 ADC1 时钟是否使能
#define __HAL_RCC_ADC1_IS_CLK_DISABLED        __HAL_RCC_ADC12_IS_CLK_DISABLED // 检查 ADC1 时钟是否禁止
#define __HAL_RCC_ADC1_FORCE_RESET            __HAL_RCC_ADC12_FORCE_RESET  // 强制复位 ADC1
#define __HAL_RCC_ADC1_RELEASE_RESET          __HAL_RCC_ADC12_RELEASE_RESET // 释放复位 ADC1
#define __HAL_RCC_ADC1_CLK_SLEEP_ENABLE       __HAL_RCC_ADC12_CLK_SLEEP_ENABLE  // 睡眠模式使能 ADC1 时钟
#define __HAL_RCC_ADC1_CLK_SLEEP_DISABLE      __HAL_RCC_ADC12_CLK_SLEEP_DISABLE // 睡眠模式禁止 ADC1 时钟
#define __HAL_RCC_GET_CLK48_SOURCE            __HAL_RCC_GET_ICLK_SOURCE    // 获取 CLK48 时钟源

/* PLL 分数倍频器控制别名 */
#define __HAL_RCC_PLLFRACN_ENABLE             __HAL_RCC_PLL_FRACN_ENABLE   // 使能 PLL 分数倍频
#define __HAL_RCC_PLLFRACN_DISABLE            __HAL_RCC_PLL_FRACN_DISABLE  // 禁止 PLL 分数倍频
#define __HAL_RCC_PLLFRACN_CONFIG             __HAL_RCC_PLL_FRACN_CONFIG   // 配置 PLL 分数倍频值
#define IS_RCC_PLLFRACN_VALUE                 IS_RCC_PLL_FRACN_VALUE       // 检查 PLL 分数倍频值参数
#endif /* STM32U5 */

/* 针对 STM32H5 系列的特定宏定义别名 */
#if defined(STM32H5)
/* PLL 分数倍频控制 */
#define __HAL_RCC_PLLFRACN_ENABLE       __HAL_RCC_PLL_FRACN_ENABLE    // 使能 PLL 分数倍频
#define __HAL_RCC_PLLFRACN_DISABLE      __HAL_RCC_PLL_FRACN_DISABLE   // 禁止 PLL 分数倍频
#define __HAL_RCC_PLLFRACN_CONFIG       __HAL_RCC_PLL_FRACN_CONFIG    // 配置 PLL 分数倍频值
#define IS_RCC_PLLFRACN_VALUE           IS_RCC_PLL_FRACN_VALUE        // 检查 PLL 分数倍频值参数

/* PLL1 (主 PLL) 时钟源和配置别名 */
#define RCC_PLLSOURCE_NONE              RCC_PLL1_SOURCE_NONE          // PLL 时钟源：无
#define RCC_PLLSOURCE_HSI               RCC_PLL1_SOURCE_HSI           // PLL 时钟源：HSI (内部高速时钟)
#define RCC_PLLSOURCE_CSI               RCC_PLL1_SOURCE_CSI           // PLL 时钟源：CSI (低功耗内部时钟)
#define RCC_PLLSOURCE_HSE               RCC_PLL1_SOURCE_HSE           // PLL 时钟源：HSE (外部高速时钟)

/* PLL 输入时钟范围配置 */
#define RCC_PLLVCIRANGE_0               RCC_PLL1_VCIRANGE_0           // PLL 输入时钟范围 0
#define RCC_PLLVCIRANGE_1               RCC_PLL1_VCIRANGE_1           // PLL 输入时钟范围 1
#define RCC_PLLVCIRANGE_2               RCC_PLL1_VCIRANGE_2           // PLL 输入时钟范围 2
#define RCC_PLLVCIRANGE_3               RCC_PLL1_VCIRANGE_3           // PLL 输入时钟范围 3

/* PLL VCO 输出范围配置 */
#define RCC_PLL1VCOWIDE                 RCC_PLL1_VCORANGE_WIDE        // PLL1 VCO 宽范围
#define RCC_PLL1VCOMEDIUM               RCC_PLL1_VCORANGE_MEDIUM      // PLL1 VCO 中等范围

/* 参数检查宏别名 */
#define IS_RCC_PLLSOURCE                IS_RCC_PLL1_SOURCE            // 检查 PLL 时钟源参数
#define IS_RCC_PLLRGE_VALUE             IS_RCC_PLL1_VCIRGE_VALUE      // 检查 PLL 输入范围参数
#define IS_RCC_PLLVCORGE_VALUE          IS_RCC_PLL1_VCORGE_VALUE      // 检查 PLL VCO 范围参数
#define IS_RCC_PLLCLOCKOUT_VALUE        IS_RCC_PLL1_CLOCKOUT_VALUE    // 检查 PLL 输出时钟参数
#define IS_RCC_PLL_FRACN_VALUE          IS_RCC_PLL1_FRACN_VALUE       // 检查 PLL 分数倍频值参数
#define IS_RCC_PLLM_VALUE               IS_RCC_PLL1_DIVM_VALUE        // 检查 PLL M 分频系数参数
#define IS_RCC_PLLN_VALUE               IS_RCC_PLL1_MULN_VALUE        // 检查 PLL N 倍频系数参数
#define IS_RCC_PLLP_VALUE               IS_RCC_PLL1_DIVP_VALUE        // 检查 PLL P 分频系数参数
#define IS_RCC_PLLQ_VALUE               IS_RCC_PLL1_DIVQ_VALUE        // 检查 PLL Q 分频系数参数
#define IS_RCC_PLLR_VALUE               IS_RCC_PLL1_DIVR_VALUE        // 检查 PLL R 分频系数参数

/* PLL1 控制宏别名 */
#define __HAL_RCC_PLL_ENABLE            __HAL_RCC_PLL1_ENABLE         // 使能 PLL1
#define __HAL_RCC_PLL_DISABLE           __HAL_RCC_PLL1_DISABLE        // 禁止 PLL1
#define __HAL_RCC_PLL_FRACN_ENABLE      __HAL_RCC_PLL1_FRACN_ENABLE   // 使能 PLL1 分数倍频
#define __HAL_RCC_PLL_FRACN_DISABLE     __HAL_RCC_PLL1_FRACN_DISABLE  // 禁止 PLL1 分数倍频
#define __HAL_RCC_PLL_CONFIG            __HAL_RCC_PLL1_CONFIG         // 配置 PLL1 参数
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG  __HAL_RCC_PLL1_PLLSOURCE_CONFIG // 配置 PLL1 输入时钟源
#define __HAL_RCC_PLL_DIVM_CONFIG       __HAL_RCC_PLL1_DIVM_CONFIG    // 配置 PLL1 M 分频器
#define __HAL_RCC_PLL_FRACN_CONFIG      __HAL_RCC_PLL1_FRACN_CONFIG   // 配置 PLL1 分数倍频器
#define __HAL_RCC_PLL_VCIRANGE          __HAL_RCC_PLL1_VCIRANGE       // 配置 PLL1 输入时钟范围
#define __HAL_RCC_PLL_VCORANGE          __HAL_RCC_PLL1_VCORANGE       // 配置 PLL1 VCO 范围
#define __HAL_RCC_GET_PLL_OSCSOURCE     __HAL_RCC_GET_PLL1_OSCSOURCE  // 获取 PLL1 输入时钟源
#define __HAL_RCC_PLLCLKOUT_ENABLE      __HAL_RCC_PLL1_CLKOUT_ENABLE  // 使能 PLL1 时钟输出
#define __HAL_RCC_PLLCLKOUT_DISABLE     __HAL_RCC_PLL1_CLKOUT_DISABLE // 禁止 PLL1 时钟输出
#define __HAL_RCC_GET_PLLCLKOUT_CONFIG  __HAL_RCC_GET_PLL1_CLKOUT_CONFIG // 获取 PLL1 时钟输出配置

/* PLL2 控制宏别名 */
#define __HAL_RCC_PLL2FRACN_ENABLE      __HAL_RCC_PLL2_FRACN_ENABLE   // 使能 PLL2 分数倍频
#define __HAL_RCC_PLL2FRACN_DISABLE     __HAL_RCC_PLL2_FRACN_DISABLE  // 禁止 PLL2 分数倍频
#define __HAL_RCC_PLL2CLKOUT_ENABLE     __HAL_RCC_PLL2_CLKOUT_ENABLE  // 使能 PLL2 时钟输出
#define __HAL_RCC_PLL2CLKOUT_DISABLE    __HAL_RCC_PLL2_CLKOUT_DISABLE // 禁止 PLL2 时钟输出
#define __HAL_RCC_PLL2FRACN_CONFIG      __HAL_RCC_PLL2_FRACN_CONFIG   // 配置 PLL2 分数倍频器
#define __HAL_RCC_GET_PLL2CLKOUT_CONFIG __HAL_RCC_GET_PLL2_CLKOUT_CONFIG // 获取 PLL2 时钟输出配置

/* PLL3 控制宏别名 */
#define __HAL_RCC_PLL3FRACN_ENABLE      __HAL_RCC_PLL3_FRACN_ENABLE   // 使能 PLL3 分数倍频
#define __HAL_RCC_PLL3FRACN_DISABLE     __HAL_RCC_PLL3_FRACN_DISABLE  // 禁止 PLL3 分数倍频
#define __HAL_RCC_PLL3CLKOUT_ENABLE     __HAL_RCC_PLL3_CLKOUT_ENABLE  // 使能 PLL3 时钟输出
#define __HAL_RCC_PLL3CLKOUT_DISABLE    __HAL_RCC_PLL3_CLKOUT_DISABLE // 禁止 PLL3 时钟输出
#define __HAL_RCC_PLL3FRACN_CONFIG      __HAL_RCC_PLL3_FRACN_CONFIG   // 配置 PLL3 分数倍频器
#define __HAL_RCC_GET_PLL3CLKOUT_CONFIG __HAL_RCC_GET_PLL3_CLKOUT_CONFIG // 获取 PLL3 时钟输出配置

/* PLL2 输入范围和时钟源配置 */
#define RCC_PLL2VCIRANGE_0              RCC_PLL2_VCIRANGE_0           // PLL2 输入时钟范围 0
#define RCC_PLL2VCIRANGE_1              RCC_PLL2_VCIRANGE_1           // PLL2 输入时钟范围 1
#define RCC_PLL2VCIRANGE_2              RCC_PLL2_VCIRANGE_2           // PLL2 输入时钟范围 2
#define RCC_PLL2VCIRANGE_3              RCC_PLL2_VCIRANGE_3           // PLL2 输入时钟范围 3

#define RCC_PLL2VCOWIDE                 RCC_PLL2_VCORANGE_WIDE        // PLL2 VCO 宽范围
#define RCC_PLL2VCOMEDIUM               RCC_PLL2_VCORANGE_MEDIUM      // PLL2 VCO 中等范围

#define RCC_PLL2SOURCE_NONE             RCC_PLL2_SOURCE_NONE          // PLL2 时钟源：无
#define RCC_PLL2SOURCE_HSI              RCC_PLL2_SOURCE_HSI           // PLL2 时钟源：HSI
#define RCC_PLL2SOURCE_CSI              RCC_PLL2_SOURCE_CSI           // PLL2 时钟源：CSI
#define RCC_PLL2SOURCE_HSE              RCC_PLL2_SOURCE_HSE           // PLL2 时钟源：HSE

/* PLL3 输入范围和时钟源配置 */
#define RCC_PLL3VCIRANGE_0              RCC_PLL3_VCIRANGE_0           // PLL3 输入时钟范围 0
#define RCC_PLL3VCIRANGE_1              RCC_PLL3_VCIRANGE_1           // PLL3 输入时钟范围 1
#define RCC_PLL3VCIRANGE_2              RCC_PLL3_VCIRANGE_2           // PLL3 输入时钟范围 2
#define RCC_PLL3VCIRANGE_3              RCC_PLL3_VCIRANGE_3           // PLL3 输入时钟范围 3

#define RCC_PLL3VCOWIDE                 RCC_PLL3_VCORANGE_WIDE        // PLL3 VCO 宽范围
#define RCC_PLL3VCOMEDIUM               RCC_PLL3_VCORANGE_MEDIUM      // PLL3 VCO 中等范围

#define RCC_PLL3SOURCE_NONE             RCC_PLL3_SOURCE_NONE          // PLL3 时钟源：无
#define RCC_PLL3SOURCE_HSI              RCC_PLL3_SOURCE_HSI           // PLL3 时钟源：HSI
#define RCC_PLL3SOURCE_CSI              RCC_PLL3_SOURCE_CSI           // PLL3 时钟源：CSI
#define RCC_PLL3SOURCE_HSE              RCC_PLL3_SOURCE_HSE           // PLL3 时钟源：HSE


#endif /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_RNG_Aliased_Macros HAL RNG Aliased Macros maintained for legacy purpose
  * @{
  */
/* RNG (随机数生成器) 回调函数别名，用于兼容旧版本 */
#define  HAL_RNG_ReadyCallback(__HANDLE__)  HAL_RNG_ReadyDataCallback((__HANDLE__), uint32_t random32bit)

/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Macros HAL RTC Aliased Macros maintained for legacy purpose
  * @{
  */
/* RTC (实时时钟) 中断和标志位处理宏别名 */
#if defined (STM32G0) || defined (STM32L5) || defined (STM32L412xx) || defined (STM32L422xx) || \
    defined (STM32L4P5xx)|| defined (STM32L4Q5xx) || defined (STM32G4) || defined (STM32WL) || defined (STM32U5) || \
    defined (STM32WBA) || defined (STM32H5) || \
    defined (STM32C0) || defined (STM32H7RS) ||  defined (STM32U0)
/* 针对新型号芯片，此处为空，因为它们有独立的标志位清除机制 */
#else
#define __HAL_RTC_CLEAR_FLAG                      __HAL_RTC_EXTI_CLEAR_FLAG   // 清除 RTC EXTI 标志（旧版本别名）
#endif
#define __HAL_RTC_DISABLE_IT                      __HAL_RTC_EXTI_DISABLE_IT   // 禁止 RTC EXTI 中断
#define __HAL_RTC_ENABLE_IT                       __HAL_RTC_EXTI_ENABLE_IT    // 使能 RTC EXTI 中断

/* 针对 STM32F1 系列的 RTC EXTI 处理 */
#if defined (STM32F1)
#define __HAL_RTC_EXTI_CLEAR_FLAG(RTC_EXTI_LINE_ALARM_EVENT)  __HAL_RTC_ALARM_EXTI_CLEAR_FLAG()  // 清除闹钟 EXTI 标志

#define __HAL_RTC_EXTI_ENABLE_IT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_ENABLE_IT()   // 使能闹钟 EXTI 中断

#define __HAL_RTC_EXTI_DISABLE_IT(RTC_EXTI_LINE_ALARM_EVENT)  __HAL_RTC_ALARM_EXTI_DISABLE_IT()  // 禁止闹钟 EXTI 中断

#define __HAL_RTC_EXTI_GET_FLAG(RTC_EXTI_LINE_ALARM_EVENT)    __HAL_RTC_ALARM_EXTI_GET_FLAG()    // 获取闹钟 EXTI 标志

#define __HAL_RTC_EXTI_GENERATE_SWIT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_GENERATE_SWIT() // 软件触发闹钟中断
#else
/* 针对非 F1 系列，根据事件类型（闹钟、唤醒、时间戳）选择对应的 EXTI 操作 */
#define __HAL_RTC_EXTI_CLEAR_FLAG(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_CLEAR_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_CLEAR_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_CLEAR_FLAG()))
#define __HAL_RTC_EXTI_ENABLE_IT(__EXTI_LINE__)   (((__EXTI_LINE__)  == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_ENABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_IT()))
#define __HAL_RTC_EXTI_DISABLE_IT(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_DISABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_IT()))
#define __HAL_RTC_EXTI_GET_FLAG(__EXTI_LINE__)    (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GET_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GET_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GET_FLAG()))
#define __HAL_RTC_EXTI_GENERATE_SWIT(__EXTI_LINE__)   (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GENERATE_SWIT() : \
                                                       (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GENERATE_SWIT() :  \
                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GENERATE_SWIT()))
#endif   /* STM32F1 */

/* TAMPER (入侵检测) 标志获取宏别名 */
#if defined (STM32F0) || defined (STM32F2) || defined (STM32F3) || defined (STM32F4) || defined (STM32F7) || \
    defined (STM32H7) || \
    defined (STM32L0) || defined (STM32L1) || \
    defined (STM32WB)
#define __HAL_RTC_TAMPER_GET_IT                   __HAL_RTC_TAMPER_GET_FLAG   // 获取入侵检测中断标志
#endif

/* RTC 参数检查宏别名 */
#define IS_ALARM                                  IS_RTC_ALARM                // 检查闹钟参数
#define IS_ALARM_MASK                             IS_RTC_ALARM_MASK           // 检查闹钟掩码参数
#define IS_TAMPER                                 IS_RTC_TAMPER               // 检查入侵检测参数
#define IS_TAMPER_ERASE_MODE                      IS_RTC_TAMPER_ERASE_MODE    // 检查入侵检测擦除模式参数
#define IS_TAMPER_FILTER                          IS_RTC_TAMPER_FILTER        // 检查入侵检测滤波参数
#define IS_TAMPER_INTERRUPT                       IS_RTC_TAMPER_INTERRUPT     // 检查入侵检测中断参数
#define IS_TAMPER_MASKFLAG_STATE                  IS_RTC_TAMPER_MASKFLAG_STATE // 检查入侵检测标志掩码状态
#define IS_TAMPER_PRECHARGE_DURATION              IS_RTC_TAMPER_PRECHARGE_DURATION // 检查入侵检测预充电时长
#define IS_TAMPER_PULLUP_STATE                    IS_RTC_TAMPER_PULLUP_STATE  // 检查入侵检测上拉状态
#define IS_TAMPER_SAMPLING_FREQ                   IS_RTC_TAMPER_SAMPLING_FREQ // 检查入侵检测采样频率
#define IS_TAMPER_TIMESTAMPONTAMPER_DETECTION     IS_RTC_TAMPER_TIMESTAMPONTAMPER_DETECTION // 检查入侵检测时间戳功能
#define IS_TAMPER_TRIGGER                         IS_RTC_TAMPER_TRIGGER       // 检查入侵检测触发方式
#define IS_WAKEUP_CLOCK                           IS_RTC_WAKEUP_CLOCK         // 检查唤醒时钟参数
#define IS_WAKEUP_COUNTER                         IS_RTC_WAKEUP_COUNTER       // 检查唤醒计数器参数

/* RTC 写保护控制宏别名 */
#define __RTC_WRITEPROTECTION_ENABLE  __HAL_RTC_WRITEPROTECTION_ENABLE   // 使能 RTC 写保护
#define __RTC_WRITEPROTECTION_DISABLE  __HAL_RTC_WRITEPROTECTION_DISABLE // 禁止 RTC 写保护

#if defined (STM32H5)
#define __HAL_RCC_RTCAPB_CLK_ENABLE   __HAL_RCC_RTC_CLK_ENABLE    // 使能 RTC APB 时钟
#define __HAL_RCC_RTCAPB_CLK_DISABLE  __HAL_RCC_RTC_CLK_DISABLE   // 禁止 RTC APB 时钟
#endif   /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_SD_Aliased_Macros HAL SD/MMC Aliased Macros maintained for legacy purpose
  * @{
  */

/* SD 卡 OCR 寄存器和命令别名 */
#define SD_OCR_CID_CSD_OVERWRIETE   SD_OCR_CID_CSD_OVERWRITE     // 修正拼写错误：CID/CSD 覆盖状态位
#define SD_CMD_SD_APP_STAUS         SD_CMD_SD_APP_STATUS         // 修正拼写错误：SD 应用状态命令

/* eMMC 和 SD 速度模式定义 */
#if !defined(STM32F1) && !defined(STM32F2) && !defined(STM32F4) && !defined(STM32L1)
#define eMMC_HIGH_VOLTAGE_RANGE     EMMC_HIGH_VOLTAGE_RANGE      // eMMC 高电压范围
#define eMMC_DUAL_VOLTAGE_RANGE     EMMC_DUAL_VOLTAGE_RANGE      // eMMC 双电压范围
#define eMMC_LOW_VOLTAGE_RANGE      EMMC_LOW_VOLTAGE_RANGE       // eMMC 低电压范围

#define SDMMC_NSpeed_CLK_DIV        SDMMC_NSPEED_CLK_DIV         // SDMMC 正常速度时钟分频
#define SDMMC_HSpeed_CLK_DIV        SDMMC_HSPEED_CLK_DIV         // SDMMC 高速度时钟分频
#endif

/* 针对 STM32F4/F2 系列的 SDIO (SD/MMC) 宏别名 */
#if defined(STM32F4) || defined(STM32F2)
#define  SD_SDMMC_DISABLED          SD_SDIO_DISABLED             // SDMMC 禁用状态
#define  SD_SDMMC_FUNCTION_BUSY     SD_SDIO_FUNCTION_BUSY        // SDMMC 功能忙
#define  SD_SDMMC_FUNCTION_FAILED   SD_SDIO_FUNCTION_FAILED      // SDMMC 功能失败
#define  SD_SDMMC_UNKNOWN_FUNCTION  SD_SDIO_UNKNOWN_FUNCTION     // SDMMC 未知功能
#define  SD_CMD_SDMMC_SEN_OP_COND   SD_CMD_SDIO_SEN_OP_COND      // SDMMC 发送操作条件命令
#define  SD_CMD_SDMMC_RW_DIRECT     SD_CMD_SDIO_RW_DIRECT        // SDMMC 直接读写命令
#define  SD_CMD_SDMMC_RW_EXTENDED   SD_CMD_SDIO_RW_EXTENDED      // SDMMC 扩展读写命令
#define  __HAL_SD_SDMMC_ENABLE      __HAL_SD_SDIO_ENABLE         // 使能 SDIO
#define  __HAL_SD_SDMMC_DISABLE     __HAL_SD_SDIO_DISABLE        // 禁止 SDIO
#define  __HAL_SD_SDMMC_DMA_ENABLE  __HAL_SD_SDIO_DMA_ENABLE     // 使能 SDIO DMA
#define  __HAL_SD_SDMMC_DMA_DISABLE __HAL_SD_SDIO_DMA_DISABL     // 禁止 SDIO DMA
#define  __HAL_SD_SDMMC_ENABLE_IT   __HAL_SD_SDIO_ENABLE_IT      // 使能 SDIO 中断
#define  __HAL_SD_SDMMC_DISABLE_IT  __HAL_SD_SDIO_DISABLE_IT     // 禁止 SDIO 中断
#define  __HAL_SD_SDMMC_GET_FLAG    __HAL_SD_SDIO_GET_FLAG       // 获取 SDIO 标志
#define  __HAL_SD_SDMMC_CLEAR_FLAG  __HAL_SD_SDIO_CLEAR_FLAG     // 清除 SDIO 标志
#define  __HAL_SD_SDMMC_GET_IT      __HAL_SD_SDIO_GET_IT         // 获取 SDIO 中断状态
#define  __HAL_SD_SDMMC_CLEAR_IT    __HAL_SD_SDIO_CLEAR_IT       // 清除 SDIO 中断状态
#define  SDMMC_STATIC_FLAGS         SDIO_STATIC_FLAGS            // SDIO 静态标志
#define  SDMMC_CMD0TIMEOUT          SDIO_CMD0TIMEOUT             // SDIO CMD0 超时时间
#define  SD_SDMMC_SEND_IF_COND      SD_SDIO_SEND_IF_COND         // SDIO 发送接口条件
/* alias CMSIS */
#define  SDMMC1_IRQn                SDIO_IRQn                    // SDMMC1 中断号别名
#define  SDMMC1_IRQHandler          SDIO_IRQHandler              // SDMMC1 中断服务函数别名
#endif

/* 针对 STM32F7/L4 系列的 SDMMC 宏别名 (将旧版 SDIO 名称映射到新版 SDMMC) */
#if defined(STM32F7) || defined(STM32L4)
#define  SD_SDIO_DISABLED           SD_SDMMC_DISABLED            // SDIO 禁用状态
#define  SD_SDIO_FUNCTION_BUSY      SD_SDMMC_FUNCTION_BUSY       // SDIO 功能忙
#define  SD_SDIO_FUNCTION_FAILED    SD_SDMMC_FUNCTION_FAILED     // SDIO 功能失败
#define  SD_SDIO_UNKNOWN_FUNCTION   SD_SDMMC_UNKNOWN_FUNCTION    // SDIO 未知功能
#define  SD_CMD_SDIO_SEN_OP_COND    SD_CMD_SDMMC_SEN_OP_COND     // SDIO 发送操作条件命令
#define  SD_CMD_SDIO_RW_DIRECT      SD_CMD_SDMMC_RW_DIRECT       // SDIO 直接读写命令
#define  SD_CMD_SDIO_RW_EXTENDED    SD_CMD_SDMMC_RW_EXTENDED     // SDIO 扩展读写命令
#define  __HAL_SD_SDIO_ENABLE       __HAL_SD_SDMMC_ENABLE        // 使能 SDMMC
#define  __HAL_SD_SDIO_DISABLE      __HAL_SD_SDMMC_DISABLE       // 禁止 SDMMC
#define  __HAL_SD_SDIO_DMA_ENABLE   __HAL_SD_SDMMC_DMA_ENABLE    // 使能 SDMMC DMA
#define  __HAL_SD_SDIO_DMA_DISABL   __HAL_SD_SDMMC_DMA_DISABLE   // 禁止 SDMMC DMA
#define  __HAL_SD_SDIO_ENABLE_IT    __HAL_SD_SDMMC_ENABLE_IT     // 使能 SDMMC 中断
#define  __HAL_SD_SDIO_DISABLE_IT   __HAL_SD_SDMMC_DISABLE_IT    // 禁止 SDMMC 中断
#define  __HAL_SD_SDIO_GET_FLAG     __HAL_SD_SDMMC_GET_FLAG      // 获取 SDMMC 标志
#define  __HAL_SD_SDIO_CLEAR_FLAG   __HAL_SD_SDMMC_CLEAR_FLAG    // 清除 SDMMC 标志
#define  __HAL_SD_SDIO_GET_IT       __HAL_SD_SDMMC_GET_IT        // 获取 SDMMC 中断状态
#define  __HAL_SD_SDIO_CLEAR_IT     __HAL_SD_SDMMC_CLEAR_IT      // 清除 SDMMC 中断状态
#define  SDIO_STATIC_FLAGS          SDMMC_STATIC_FLAGS           // SDMMC 静态标志
#define  SDIO_CMD0TIMEOUT           SDMMC_CMD0TIMEOUT            // SDMMC CMD0 超时时间
#define  SD_SDIO_SEND_IF_COND       SD_SDMMC_SEND_IF_COND        // SDMMC 发送接口条件
/* alias CMSIS for compatibilities */
#define  SDIO_IRQn                  SDMMC1_IRQn                  // SDIO 中断号别名
#define  SDIO_IRQHandler            SDMMC1_IRQHandler            // SDIO 中断服务函数别名
#endif

/* SD 卡结构体类型定义别名，修正拼写后缀 (Typedef -> TypeDef) */
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F2) || defined(STM32L4) || defined(STM32H7)
#define  HAL_SD_CardCIDTypedef       HAL_SD_CardCIDTypeDef       // SD 卡 CID 寄存器结构体别名
#define  HAL_SD_CardCSDTypedef       HAL_SD_CardCSDTypeDef       // SD 卡 CSD 寄存器结构体别名
#define  HAL_SD_CardStatusTypedef    HAL_SD_CardStatusTypeDef    // SD 卡状态结构体别名
#define  HAL_SD_CardStateTypedef     HAL_SD_CardStateTypeDef     // SD 卡状态枚举别名
#endif

/* MMC/SD DMA 双缓冲回调函数别名 */
#if defined(STM32H7) || defined(STM32L5)
#define HAL_MMCEx_Read_DMADoubleBuffer0CpltCallback   HAL_MMCEx_Read_DMADoubleBuf0CpltCallback   // MMC DMA 读双缓冲 0 完成回调
#define HAL_MMCEx_Read_DMADoubleBuffer1CpltCallback   HAL_MMCEx_Read_DMADoubleBuf1CpltCallback   // MMC DMA 读双缓冲 1 完成回调
#define HAL_MMCEx_Write_DMADoubleBuffer0CpltCallback  HAL_MMCEx_Write_DMADoubleBuf0CpltCallback  // MMC DMA 写双缓冲 0 完成回调
#define HAL_MMCEx_Write_DMADoubleBuffer1CpltCallback  HAL_MMCEx_Write_DMADoubleBuf1CpltCallback  // MMC DMA 写双缓冲 1 完成回调
#define HAL_SDEx_Read_DMADoubleBuffer0CpltCallback    HAL_SDEx_Read_DMADoubleBuf0CpltCallback    // SD DMA 读双缓冲 0 完成回调
#define HAL_SDEx_Read_DMADoubleBuffer1CpltCallback    HAL_SDEx_Read_DMADoubleBuf1CpltCallback    // SD DMA 读双缓冲 1 完成回调
#define HAL_SDEx_Write_DMADoubleBuffer0CpltCallback   HAL_SDEx_Write_DMADoubleBuf0CpltCallback   // SD DMA 写双缓冲 0 完成回调
#define HAL_SDEx_Write_DMADoubleBuffer1CpltCallback   HAL_SDEx_Write_DMADoubleBuf1CpltCallback   // SD DMA 写双缓冲 1 完成回调
#define HAL_SD_DriveTransciver_1_8V_Callback          HAL_SD_DriveTransceiver_1_8V_Callback      // SD 卡驱动 1.8V 收发器回调
#endif
/**
  * @}
  */

/** @defgroup HAL_SMARTCARD_Aliased_Macros HAL SMARTCARD Aliased Macros maintained for legacy purpose
  * @{
  */

/* SMARTCARD (智能卡) 外设宏别名 */
#define __SMARTCARD_ENABLE_IT           __HAL_SMARTCARD_ENABLE_IT           // 使能智能卡中断
#define __SMARTCARD_DISABLE_IT          __HAL_SMARTCARD_DISABLE_IT          // 禁止智能卡中断
#define __SMARTCARD_ENABLE              __HAL_SMARTCARD_ENABLE              // 使能智能卡
#define __SMARTCARD_DISABLE             __HAL_SMARTCARD_DISABLE             // 禁止智能卡
#define __SMARTCARD_DMA_REQUEST_ENABLE  __HAL_SMARTCARD_DMA_REQUEST_ENABLE  // 使能智能卡 DMA 请求
#define __SMARTCARD_DMA_REQUEST_DISABLE __HAL_SMARTCARD_DMA_REQUEST_DISABLE // 禁止智能卡 DMA 请求

#define __HAL_SMARTCARD_GETCLOCKSOURCE  SMARTCARD_GETCLOCKSOURCE            // 获取智能卡时钟源（旧版宏）
#define __SMARTCARD_GETCLOCKSOURCE      SMARTCARD_GETCLOCKSOURCE            // 获取智能卡时钟源（旧版宏）

#define IS_SMARTCARD_ONEBIT_SAMPLING    IS_SMARTCARD_ONE_BIT_SAMPLE         // 检查智能卡单比特采样参数

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Macros HAL SMBUS Aliased Macros maintained for legacy purpose
  * @{
  */
/* SMBUS (系统管理总线) 宏别名 */
#define __HAL_SMBUS_RESET_CR1           SMBUS_RESET_CR1           // 复位 SMBUS CR1 寄存器
#define __HAL_SMBUS_RESET_CR2           SMBUS_RESET_CR2           // 复位 SMBUS CR2 寄存器
#define __HAL_SMBUS_GENERATE_START      SMBUS_GENERATE_START      // 产生 SMBUS 起始条件
#define __HAL_SMBUS_GET_ADDR_MATCH      SMBUS_GET_ADDR_MATCH      // 获取 SMBUS 匹配地址
#define __HAL_SMBUS_GET_DIR             SMBUS_GET_DIR             // 获取 SMBUS 传输方向
#define __HAL_SMBUS_GET_STOP_MODE       SMBUS_GET_STOP_MODE       // 获取 SMBUS 停止模式
#define __HAL_SMBUS_GET_PEC_MODE        SMBUS_GET_PEC_MODE        // 获取 SMBUS PEC 模式
#define __HAL_SMBUS_GET_ALERT_ENABLED   SMBUS_GET_ALERT_ENABLED   // 获取 SMBUS 警报使能状态
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Macros HAL SPI Aliased Macros maintained for legacy purpose
  * @{
  */

/* SPI (串行外设接口) 宏别名 */
#define __HAL_SPI_1LINE_TX              SPI_1LINE_TX              // SPI 单线发送模式
#define __HAL_SPI_1LINE_RX              SPI_1LINE_RX              // SPI 单线接收模式
#define __HAL_SPI_RESET_CRC             SPI_RESET_CRC             // 复位 SPI CRC 校验
