/* DFSDM外设相关宏定义别名，用于兼容旧版本代码，将DFSDM映射到DFSDM1 */
#define __HAL_RCC_DFSDM_CLK_ENABLE             __HAL_RCC_DFSDM1_CLK_ENABLE    // 使能DFSDM1时钟
#define __HAL_RCC_DFSDM_CLK_DISABLE            __HAL_RCC_DFSDM1_CLK_DISABLE   // 关闭DFSDM1时钟
#define __HAL_RCC_DFSDM_IS_CLK_ENABLED         __HAL_RCC_DFSDM1_IS_CLK_ENABLED  // 检查DFSDM1时钟是否已使能
#define __HAL_RCC_DFSDM_IS_CLK_DISABLED        __HAL_RCC_DFSDM1_IS_CLK_DISABLED // 检查DFSDM1时钟是否已禁用
#define __HAL_RCC_DFSDM_FORCE_RESET            __HAL_RCC_DFSDM1_FORCE_RESET   // 强制复位DFSDM1
#define __HAL_RCC_DFSDM_RELEASE_RESET          __HAL_RCC_DFSDM1_RELEASE_RESET // 释放DFSDM1复位
#define __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE       __HAL_RCC_DFSDM1_CLK_SLEEP_ENABLE  // 睡眠模式下使能DFSDM1时钟
#define __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE      __HAL_RCC_DFSDM1_CLK_SLEEP_DISABLE // 睡眠模式下关闭DFSDM1时钟
#define __HAL_RCC_DFSDM_IS_CLK_SLEEP_ENABLED   __HAL_RCC_DFSDM1_IS_CLK_SLEEP_ENABLED  // 检查睡眠模式下DFSDM1时钟是否使能
#define __HAL_RCC_DFSDM_IS_CLK_SLEEP_DISABLED  __HAL_RCC_DFSDM1_IS_CLK_SLEEP_DISABLED // 检查睡眠模式下DFSDM1时钟是否禁用
#define DfsdmClockSelection         Dfsdm1ClockSelection   // DFSDM时钟选择别名
#define RCC_PERIPHCLK_DFSDM         RCC_PERIPHCLK_DFSDM1   // DFSDM外设时钟定义
#define RCC_DFSDMCLKSOURCE_PCLK     RCC_DFSDM1CLKSOURCE_PCLK2  // DFSDM时钟源选择PCLK
#define RCC_DFSDMCLKSOURCE_SYSCLK   RCC_DFSDM1CLKSOURCE_SYSCLK // DFSDM时钟源选择系统时钟
#define __HAL_RCC_DFSDM_CONFIG      __HAL_RCC_DFSDM1_CONFIG    // 配置DFSDM时钟
#define __HAL_RCC_GET_DFSDM_SOURCE  __HAL_RCC_GET_DFSDM1_SOURCE // 获取DFSDM时钟源
#define RCC_DFSDM1CLKSOURCE_PCLK    RCC_DFSDM1CLKSOURCE_PCLK2  // DFSDM1时钟源为PCLK2
#define RCC_SWPMI1CLKSOURCE_PCLK    RCC_SWPMI1CLKSOURCE_PCLK1  // SWPMI1时钟源为PCLK1

/* 针对非STM32U0系列设备的LPTIM时钟源定义 */
#if !defined(STM32U0)
#define RCC_LPTIM1CLKSOURCE_PCLK    RCC_LPTIM1CLKSOURCE_PCLK1  // LPTIM1时钟源为PCLK1
#define RCC_LPTIM2CLKSOURCE_PCLK    RCC_LPTIM2CLKSOURCE_PCLK1  // LPTIM2时钟源为PCLK1
#endif

/* DFSDM音频时钟源别名定义，将具体的APB总线映射到I2S实例 */
#define RCC_DFSDM1AUDIOCLKSOURCE_I2SAPB1    RCC_DFSDM1AUDIOCLKSOURCE_I2S1 // DFSDM1音频时钟源为I2S1(APB1)
#define RCC_DFSDM1AUDIOCLKSOURCE_I2SAPB2    RCC_DFSDM1AUDIOCLKSOURCE_I2S2 // DFSDM1音频时钟源为I2S2(APB2)
#define RCC_DFSDM2AUDIOCLKSOURCE_I2SAPB1    RCC_DFSDM2AUDIOCLKSOURCE_I2S1 // DFSDM2音频时钟源为I2S1(APB1)
#define RCC_DFSDM2AUDIOCLKSOURCE_I2SAPB2    RCC_DFSDM2AUDIOCLKSOURCE_I2S2 // DFSDM2音频时钟源为I2S2(APB2)
#define RCC_DFSDM1CLKSOURCE_APB2            RCC_DFSDM1CLKSOURCE_PCLK2     // DFSDM1时钟源为APB2
#define RCC_DFSDM2CLKSOURCE_APB2            RCC_DFSDM2CLKSOURCE_PCLK2     // DFSDM2时钟源为APB2
#define RCC_FMPI2C1CLKSOURCE_APB            RCC_FMPII2C1CLKSOURCE_PCLK1   // FMPI2C1时钟源为APB

/* 针对STM32U5系列设备的特定宏定义别名 */
#if defined(STM32U5)
#define MSIKPLLModeSEL                        RCC_MSIKPLL_MODE_SEL       // MSI内核PLL模式选择
#define MSISPLLModeSEL                        RCC_MSISPLL_MODE_SEL       // MSI系统PLL模式选择
#define __HAL_RCC_AHB21_CLK_DISABLE           __HAL_RCC_AHB2_1_CLK_DISABLE  // 关闭AHB2_1时钟
#define __HAL_RCC_AHB22_CLK_DISABLE           __HAL_RCC_AHB2_2_CLK_DISABLE  // 关闭AHB2_2时钟
#define __HAL_RCC_AHB1_CLK_Disable_Clear      __HAL_RCC_AHB1_CLK_ENABLE     // AHB1禁用清除(映射到使能)
#define __HAL_RCC_AHB21_CLK_Disable_Clear     __HAL_RCC_AHB2_1_CLK_ENABLE   // AHB2_1禁用清除
#define __HAL_RCC_AHB22_CLK_Disable_Clear     __HAL_RCC_AHB2_2_CLK_ENABLE   // AHB2_2禁用清除
#define __HAL_RCC_AHB3_CLK_Disable_Clear      __HAL_RCC_AHB3_CLK_ENABLE     // AHB3禁用清除
#define __HAL_RCC_APB1_CLK_Disable_Clear      __HAL_RCC_APB1_CLK_ENABLE     // APB1禁用清除
#define __HAL_RCC_APB2_CLK_Disable_Clear      __HAL_RCC_APB2_CLK_ENABLE     // APB2禁用清除
#define __HAL_RCC_APB3_CLK_Disable_Clear      __HAL_RCC_APB3_CLK_ENABLE     // APB3禁用清除
#define IS_RCC_MSIPLLModeSelection            IS_RCC_MSIPLLMODE_SELECT      // MSI PLL模式选择检查宏
#define RCC_PERIPHCLK_CLK48                   RCC_PERIPHCLK_ICLK            // CLK48外设时钟别名
#define RCC_CLK48CLKSOURCE_HSI48              RCC_ICLK_CLKSOURCE_HSI48      // CLK48时钟源为HSI48
#define RCC_CLK48CLKSOURCE_PLL2               RCC_ICLK_CLKSOURCE_PLL2       // CLK48时钟源为PLL2
#define RCC_CLK48CLKSOURCE_PLL1               RCC_ICLK_CLKSOURCE_PLL1       // CLK48时钟源为PLL1
#define RCC_CLK48CLKSOURCE_MSIK               RCC_ICLK_CLKSOURCE_MSIK       // CLK48时钟源为MSIK
#define __HAL_RCC_ADC1_CLK_ENABLE             __HAL_RCC_ADC12_CLK_ENABLE    // 使能ADC1时钟(映射到ADC12)
#define __HAL_RCC_ADC1_CLK_DISABLE            __HAL_RCC_ADC12_CLK_DISABLE   // 关闭ADC1时钟
#define __HAL_RCC_ADC1_IS_CLK_ENABLED         __HAL_RCC_ADC12_IS_CLK_ENABLED  // 检查ADC1时钟是否使能
#define __HAL_RCC_ADC1_IS_CLK_DISABLED        __HAL_RCC_ADC12_IS_CLK_DISABLED // 检查ADC1时钟是否禁用
#define __HAL_RCC_ADC1_FORCE_RESET            __HAL_RCC_ADC12_FORCE_RESET   // 强制复位ADC1
#define __HAL_RCC_ADC1_RELEASE_RESET          __HAL_RCC_ADC12_RELEASE_RESET // 释放ADC1复位
#define __HAL_RCC_ADC1_CLK_SLEEP_ENABLE       __HAL_RCC_ADC12_CLK_SLEEP_ENABLE  // 睡眠模式下使能ADC1时钟
#define __HAL_RCC_ADC1_CLK_SLEEP_DISABLE      __HAL_RCC_ADC12_CLK_SLEEP_DISABLE // 睡眠模式下关闭ADC1时钟
#define __HAL_RCC_GET_CLK48_SOURCE            __HAL_RCC_GET_ICLK_SOURCE     // 获取CLK48时钟源
#define __HAL_RCC_PLLFRACN_ENABLE             __HAL_RCC_PLL_FRACN_ENABLE    // 使能PLL分数N
#define __HAL_RCC_PLLFRACN_DISABLE            __HAL_RCC_PLL_FRACN_DISABLE   // 关闭PLL分数N
#define __HAL_RCC_PLLFRACN_CONFIG             __HAL_RCC_PLL_FRACN_CONFIG    // 配置PLL分数N
#define IS_RCC_PLLFRACN_VALUE                 IS_RCC_PLL_FRACN_VALUE        // 检查PLL分数N值
#endif /* STM32U5 */

/* 针对STM32H5系列设备的特定宏定义别名 */
#if defined(STM32H5)
#define __HAL_RCC_PLLFRACN_ENABLE       __HAL_RCC_PLL_FRACN_ENABLE      // 使能PLL分数N
#define __HAL_RCC_PLLFRACN_DISABLE      __HAL_RCC_PLL_FRACN_DISABLE     // 关闭PLL分数N
#define __HAL_RCC_PLLFRACN_CONFIG       __HAL_RCC_PLL_FRACN_CONFIG      // 配置PLL分数N
#define IS_RCC_PLLFRACN_VALUE           IS_RCC_PLL_FRACN_VALUE          // 检查PLL分数N值

/* PLL时钟源选择别名 */
#define RCC_PLLSOURCE_NONE              RCC_PLL1_SOURCE_NONE            // PLL源：无
#define RCC_PLLSOURCE_HSI               RCC_PLL1_SOURCE_HSI             // PLL源：HSI
#define RCC_PLLSOURCE_CSI               RCC_PLL1_SOURCE_CSI             // PLL源：CSI
#define RCC_PLLSOURCE_HSE               RCC_PLL1_SOURCE_HSE             // PLL源：HSE

/* PLL输入时钟范围配置 */
#define RCC_PLLVCIRANGE_0               RCC_PLL1_VCIRANGE_0             // VCI范围0
#define RCC_PLLVCIRANGE_1               RCC_PLL1_VCIRANGE_1             // VCI范围1
#define RCC_PLLVCIRANGE_2               RCC_PLL1_VCIRANGE_2             // VCI范围2
#define RCC_PLLVCIRANGE_3               RCC_PLL1_VCIRANGE_3             // VCI范围3

/* PLL输出时钟范围配置 */
#define RCC_PLL1VCOWIDE                 RCC_PLL1_VCORANGE_WIDE          // VCO宽范围
#define RCC_PLL1VCOMEDIUM               RCC_PLL1_VCORANGE_MEDIUM        // VCO中等范围

/* 参数检查宏别名 */
#define IS_RCC_PLLSOURCE                IS_RCC_PLL1_SOURCE              // 检查PLL源
#define IS_RCC_PLLRGE_VALUE             IS_RCC_PLL1_VCIRGE_VALUE        // 检查PLL输入范围值
#define IS_RCC_PLLVCORGE_VALUE          IS_RCC_PLL1_VCORGE_VALUE        // 检查PLL VCO范围值
#define IS_RCC_PLLCLOCKOUT_VALUE        IS_RCC_PLL1_CLOCKOUT_VALUE      // 检查PLL输出时钟值
#define IS_RCC_PLL_FRACN_VALUE          IS_RCC_PLL1_FRACN_VALUE         // 检查PLL分数N值
#define IS_RCC_PLLM_VALUE               IS_RCC_PLL1_DIVM_VALUE          // 检查PLL M分频值
#define IS_RCC_PLLN_VALUE               IS_RCC_PLL1_MULN_VALUE          // 检查PLL N倍频值
#define IS_RCC_PLLP_VALUE               IS_RCC_PLL1_DIVP_VALUE          // 检查PLL P分频值
#define IS_RCC_PLLQ_VALUE               IS_RCC_PLL1_DIVQ_VALUE          // 检查PLL Q分频值
#define IS_RCC_PLLR_VALUE               IS_RCC_PLL1_DIVR_VALUE          // 检查PLL R分频值

/* PLL控制宏别名 */
#define __HAL_RCC_PLL_ENABLE            __HAL_RCC_PLL1_ENABLE           // 使能PLL1
#define __HAL_RCC_PLL_DISABLE           __HAL_RCC_PLL1_DISABLE          // 关闭PLL1
#define __HAL_RCC_PLL_FRACN_ENABLE      __HAL_RCC_PLL1_FRACN_ENABLE     // 使能PLL1分数N
#define __HAL_RCC_PLL_FRACN_DISABLE     __HAL_RCC_PLL1_FRACN_DISABLE    // 关闭PLL1分数N
#define __HAL_RCC_PLL_CONFIG            __HAL_RCC_PLL1_CONFIG           // 配置PLL1
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG  __HAL_RCC_PLL1_PLLSOURCE_CONFIG // 配置PLL1时钟源
#define __HAL_RCC_PLL_DIVM_CONFIG       __HAL_RCC_PLL1_DIVM_CONFIG      // 配置PLL1 M分频
#define __HAL_RCC_PLL_FRACN_CONFIG      __HAL_RCC_PLL1_FRACN_CONFIG     // 配置PLL1分数N
#define __HAL_RCC_PLL_VCIRANGE          __HAL_RCC_PLL1_VCIRANGE         // 配置PLL1输入范围
#define __HAL_RCC_PLL_VCORANGE          __HAL_RCC_PLL1_VCORANGE         // 配置PLL1 VCO范围
#define __HAL_RCC_GET_PLL_OSCSOURCE     __HAL_RCC_GET_PLL1_OSCSOURCE    // 获取PLL1振荡源
#define __HAL_RCC_PLLCLKOUT_ENABLE      __HAL_RCC_PLL1_CLKOUT_ENABLE    // 使能PLL1时钟输出
#define __HAL_RCC_PLLCLKOUT_DISABLE     __HAL_RCC_PLL1_CLKOUT_DISABLE   // 关闭PLL1时钟输出
#define __HAL_RCC_GET_PLLCLKOUT_CONFIG  __HAL_RCC_GET_PLL1_CLKOUT_CONFIG // 获取PLL1时钟输出配置

/* PLL2控制宏别名 */
#define __HAL_RCC_PLL2FRACN_ENABLE      __HAL_RCC_PLL2_FRACN_ENABLE     // 使能PLL2分数N
#define __HAL_RCC_PLL2FRACN_DISABLE     __HAL_RCC_PLL2_FRACN_DISABLE    // 关闭PLL2分数N
#define __HAL_RCC_PLL2CLKOUT_ENABLE     __HAL_RCC_PLL2_CLKOUT_ENABLE    // 使能PLL2时钟输出
#define __HAL_RCC_PLL2CLKOUT_DISABLE    __HAL_RCC_PLL2_CLKOUT_DISABLE   // 关闭PLL2时钟输出
#define __HAL_RCC_PLL2FRACN_CONFIG      __HAL_RCC_PLL2_FRACN_CONFIG     // 配置PLL2分数N
#define __HAL_RCC_GET_PLL2CLKOUT_CONFIG __HAL_RCC_GET_PLL2_CLKOUT_CONFIG // 获取PLL2时钟输出配置

/* PLL3控制宏别名 */
#define __HAL_RCC_PLL3FRACN_ENABLE      __HAL_RCC_PLL3_FRACN_ENABLE     // 使能PLL3分数N
#define __HAL_RCC_PLL3FRACN_DISABLE     __HAL_RCC_PLL3_FRACN_DISABLE    // 关闭PLL3分数N
#define __HAL_RCC_PLL3CLKOUT_ENABLE     __HAL_RCC_PLL3_CLKOUT_ENABLE    // 使能PLL3时钟输出
#define __HAL_RCC_PLL3CLKOUT_DISABLE    __HAL_RCC_PLL3_CLKOUT_DISABLE   // 关闭PLL3时钟输出
#define __HAL_RCC_PLL3FRACN_CONFIG      __HAL_RCC_PLL3_FRACN_CONFIG     // 配置PLL3分数N
#define __HAL_RCC_GET_PLL3CLKOUT_CONFIG __HAL_RCC_GET_PLL3_CLKOUT_CONFIG // 获取PLL3时钟输出配置

/* PLL2配置参数别名 */
#define RCC_PLL2VCIRANGE_0              RCC_PLL2_VCIRANGE_0             // PLL2输入范围0
#define RCC_PLL2VCIRANGE_1              RCC_PLL2_VCIRANGE_1             // PLL2输入范围1
#define RCC_PLL2VCIRANGE_2              RCC_PLL2_VCIRANGE_2             // PLL2输入范围2
#define RCC_PLL2VCIRANGE_3              RCC_PLL2_VCIRANGE_3             // PLL2输入范围3

#define RCC_PLL2VCOWIDE                 RCC_PLL2_VCORANGE_WIDE          // PLL2 VCO宽范围
#define RCC_PLL2VCOMEDIUM               RCC_PLL2_VCORANGE_MEDIUM        // PLL2 VCO中等范围

#define RCC_PLL2SOURCE_NONE             RCC_PLL2_SOURCE_NONE            // PLL2源：无
#define RCC_PLL2SOURCE_HSI              RCC_PLL2_SOURCE_HSI             // PLL2源：HSI
#define RCC_PLL2SOURCE_CSI              RCC_PLL2_SOURCE_CSI             // PLL2源：CSI
#define RCC_PLL2SOURCE_HSE              RCC_PLL2_SOURCE_HSE             // PLL2源：HSE

/* PLL3配置参数别名 */
#define RCC_PLL3VCIRANGE_0              RCC_PLL3_VCIRANGE_0             // PLL3输入范围0
#define RCC_PLL3VCIRANGE_1              RCC_PLL3_VCIRANGE_1             // PLL3输入范围1
#define RCC_PLL3VCIRANGE_2              RCC_PLL3_VCIRANGE_2             // PLL3输入范围2
#define RCC_PLL3VCIRANGE_3              RCC_PLL3_VCIRANGE_3             // PLL3输入范围3

#define RCC_PLL3VCOWIDE                 RCC_PLL3_VCORANGE_WIDE          // PLL3 VCO宽范围
#define RCC_PLL3VCOMEDIUM               RCC_PLL3_VCORANGE_MEDIUM        // PLL3 VCO中等范围

#define RCC_PLL3SOURCE_NONE             RCC_PLL3_SOURCE_NONE            // PLL3源：无
#define RCC_PLL3SOURCE_HSI              RCC_PLL3_SOURCE_HSI             // PLL3源：HSI
#define RCC_PLL3SOURCE_CSI              RCC_PLL3_SOURCE_CSI             // PLL3源：CSI
#define RCC_PLL3SOURCE_HSE              RCC_PLL3_SOURCE_HSE             // PLL3源：HSE


#endif /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_RNG_Aliased_Macros HAL RNG Aliased Macros maintained for legacy purpose
  * @{
  */
/* RNG(随机数生成器)回调函数别名，用于兼容旧版API */
#define  HAL_RNG_ReadyCallback(__HANDLE__)  HAL_RNG_ReadyDataCallback((__HANDLE__), uint32_t random32bit)

/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Macros HAL RTC Aliased Macros maintained for legacy purpose
  * @{
  */
/* RTC(实时时钟)相关宏别名，针对不同系列进行条件编译 */
#if defined (STM32G0) || defined (STM32L5) || defined (STM32L412xx) || defined (STM32L422xx) || \
    defined (STM32L4P5xx)|| defined (STM32L4Q5xx) || defined (STM32G4) || defined (STM32WL) || defined (STM32U5) || \
    defined (STM32WBA) || defined (STM32H5) || \
    defined (STM32C0) || defined (STM32H7RS) ||  defined (STM32U0)
/* 新设备直接使用自身定义，此处为空 */
#else
/* 旧设备将RTC清除标志映射到EXTI清除标志 */
#define __HAL_RTC_CLEAR_FLAG                      __HAL_RTC_EXTI_CLEAR_FLAG
#endif
/* RTC中断配置宏别名 */
#define __HAL_RTC_DISABLE_IT                      __HAL_RTC_EXTI_DISABLE_IT   // 禁用RTC中断
#define __HAL_RTC_ENABLE_IT                       __HAL_RTC_EXTI_ENABLE_IT    // 使能RTC中断

/* 针对STM32F1系列的RTC EXTI(外部中断)宏定义 */
#if defined (STM32F1)
#define __HAL_RTC_EXTI_CLEAR_FLAG(RTC_EXTI_LINE_ALARM_EVENT)  __HAL_RTC_ALARM_EXTI_CLEAR_FLAG() // 清除报警EXTI标志

#define __HAL_RTC_EXTI_ENABLE_IT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_ENABLE_IT()  // 使能报警EXTI中断

#define __HAL_RTC_EXTI_DISABLE_IT(RTC_EXTI_LINE_ALARM_EVENT)  __HAL_RTC_ALARM_EXTI_DISABLE_IT() // 禁用报警EXTI中断

#define __HAL_RTC_EXTI_GET_FLAG(RTC_EXTI_LINE_ALARM_EVENT)    __HAL_RTC_ALARM_EXTI_GET_FLAG()   // 获取报警EXTI标志

#define __HAL_RTC_EXTI_GENERATE_SWIT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_GENERATE_SWIT() // 产生软件中断
#else
/* 针对非STM32F1系列，根据事件线(闹钟、唤醒、篡改)选择对应的EXTI操作 */
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

/* 针对特定系列的篡改(Tamper)中断标志获取别名 */
#if defined (STM32F0) || defined (STM32F2) || defined (STM32F3) || defined (STM32F4) || defined (STM32F7) || \
    defined (STM32H7) || \
    defined (STM32L0) || defined (STM32L1) || \
    defined (STM32WB)
#define __HAL_RTC_TAMPER_GET_IT                   __HAL_RTC_TAMPER_GET_FLAG
#endif

/* RTC参数检查宏别名 */
#define IS_ALARM                                  IS_RTC_ALARM            // 检查闹钟
#define IS_ALARM_MASK                             IS_RTC_ALARM_MASK       // 检查闹钟掩码
#define IS_TAMPER                                 IS_RTC_TAMPER           // 检查篡改配置
#define IS_TAMPER_ERASE_MODE                      IS_RTC_TAMPER_ERASE_MODE // 检查篡改擦除模式
#define IS_TAMPER_FILTER                          IS_RTC_TAMPER_FILTER    // 检查篡改滤波器
#define IS_TAMPER_INTERRUPT                       IS_RTC_TAMPER_INTERRUPT // 检查篡改中断
#define IS_TAMPER_MASKFLAG_STATE                  IS_RTC_TAMPER_MASKFLAG_STATE // 检查篡改标志掩码状态
#define IS_TAMPER_PRECHARGE_DURATION              IS_RTC_TAMPER_PRECHARGE_DURATION // 检查篡改预充电时长
#define IS_TAMPER_PULLUP_STATE                    IS_RTC_TAMPER_PULLUP_STATE // 检查篡改上拉状态
#define IS_TAMPER_SAMPLING_FREQ                   IS_RTC_TAMPER_SAMPLING_FREQ // 检查篡改采样频率
#define IS_TAMPER_TIMESTAMPONTAMPER_DETECTION     IS_RTC_TAMPER_TIMESTAMPONTAMPER_DETECTION // 检查篡改时间戳检测
#define IS_TAMPER_TRIGGER                         IS_RTC_TAMPER_TRIGGER   // 检查篡改触发
#define IS_WAKEUP_CLOCK                           IS_RTC_WAKEUP_CLOCK     // 检查唤醒时钟
#define IS_WAKEUP_COUNTER                         IS_RTC_WAKEUP_COUNTER   // 检查唤醒计数器

/* RTC写保护宏别名 */
#define __RTC_WRITEPROTECTION_ENABLE  __HAL_RTC_WRITEPROTECTION_ENABLE   // 使能写保护
#define __RTC_WRITEPROTECTION_DISABLE  __HAL_RTC_WRITEPROTECTION_DISABLE // 禁用写保护

/* STM32H5系列RTC APB时钟使能别名 */
#if defined (STM32H5)
#define __HAL_RCC_RTCAPB_CLK_ENABLE   __HAL_RCC_RTC_CLK_ENABLE   // 使能RTC APB时钟
#define __HAL_RCC_RTCAPB_CLK_DISABLE  __HAL_RCC_RTC_CLK_DISABLE  // 关闭RTC APB时钟
#endif   /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_SD_Aliased_Macros HAL SD/MMC Aliased Macros maintained for legacy purpose
  * @{
  */

/* SD卡(安全数字卡)宏别名 */
#define SD_OCR_CID_CSD_OVERWRIETE   SD_OCR_CID_CSD_OVERWRITE // 修正拼写错误：OVERWRIETE -> OVERWRITE
#define SD_CMD_SD_APP_STAUS         SD_CMD_SD_APP_STATUS     // 修正拼写错误：STAUS -> STATUS

/* 针对非F1/F2/F4/L1系列定义的eMMC电压范围和速度模式宏 */
#if !defined(STM32F1) && !defined(STM32F2) && !defined(STM32F4) && !defined(STM32L1)
#define eMMC_HIGH_VOLTAGE_RANGE     EMMC_HIGH_VOLTAGE_RANGE  // eMMC高压范围
#define eMMC_DUAL_VOLTAGE_RANGE     EMMC_DUAL_VOLTAGE_RANGE  // eMMC双电压范围
#define eMMC_LOW_VOLTAGE_RANGE      EMMC_LOW_VOLTAGE_RANGE   // eMMC低压范围

#define SDMMC_NSpeed_CLK_DIV        SDMMC_NSPEED_CLK_DIV     // SDMMC正常速度时钟分频
#define SDMMC_HSpeed_CLK_DIV        SDMMC_HSPEED_CLK_DIV     // SDMMC高速时钟分频
#endif

/* 针对STM32F4/F2系列，将SDMMC宏映射到SDIO宏(硬件接口名称变更) */
#if defined(STM32F4) || defined(STM32F2)
#define  SD_SDMMC_DISABLED          SD_SDIO_DISABLED         // SDIO禁用
#define  SD_SDMMC_FUNCTION_BUSY     SD_SDIO_FUNCTION_BUSY    // SDIO功能忙
#define  SD_SDMMC_FUNCTION_FAILED   SD_SDIO_FUNCTION_FAILED  // SDIO功能失败
#define  SD_SDMMC_UNKNOWN_FUNCTION  SD_SDIO_UNKNOWN_FUNCTION // SDIO未知功能
#define  SD_CMD_SDMMC_SEN_OP_COND   SD_CMD_SDIO_SEN_OP_COND  // SDIO发送OP_COND命令
#define  SD_CMD_SDMMC_RW_DIRECT     SD_CMD_SDIO_RW_DIRECT    // SDIO直接读写命令
#define  SD_CMD_SDMMC_RW_EXTENDED   SD_CMD_SDIO_RW_EXTENDED  // SDIO扩展读写命令
#define  __HAL_SD_SDMMC_ENABLE      __HAL_SD_SDIO_ENABLE     // 使能SDIO
#define  __HAL_SD_SDMMC_DISABLE     __HAL_SD_SDIO_DISABLE    // 禁用SDIO
#define  __HAL_SD_SDMMC_DMA_ENABLE  __HAL_SD_SDIO_DMA_ENABLE // 使能SDIO DMA
#define  __HAL_SD_SDMMC_DMA_DISABLE __HAL_SD_SDIO_DMA_DISABL // 禁用SDIO DMA
#define  __HAL_SD_SDMMC_ENABLE_IT   __HAL_SD_SDIO_ENABLE_IT  // 使能SDIO中断
#define  __HAL_SD_SDMMC_DISABLE_IT  __HAL_SD_SDIO_DISABLE_IT // 禁用SDIO中断
#define  __HAL_SD_SDMMC_GET_FLAG    __HAL_SD_SDIO_GET_FLAG   // 获取SDIO标志
#define  __HAL_SD_SDMMC_CLEAR_FLAG  __HAL_SD_SDIO_CLEAR_FLAG // 清除SDIO标志
#define  __HAL_SD_SDMMC_GET_IT      __HAL_SD_SDIO_GET_IT     // 获取SDIO中断
#define  __HAL_SD_SDMMC_CLEAR_IT    __HAL_SD_SDIO_CLEAR_IT   // 清除SDIO中断
#define  SDMMC_STATIC_FLAGS         SDIO_STATIC_FLAGS        // SDIO静态标志
#define  SDMMC_CMD0TIMEOUT          SDIO_CMD0TIMEOUT         // SDIO CMD0超时
#define  SD_SDMMC_SEND_IF_COND      SD_SDIO_SEND_IF_COND     // SDIO发送接口条件
/* alias CMSIS */ // CMSIS别名，用于中断处理函数映射
#define  SDMMC1_IRQn                SDIO_IRQn                // SDIO中断号
#define  SDMMC1_IRQHandler          SDIO_IRQHandler          // SDIO中断服务函数
#endif

/* 针对STM32F7/L4系列，将SDIO宏映射到SDMMC宏(硬件接口名称变更) */
#if defined(STM32F7) || defined(STM32L4)
#define  SD_SDIO_DISABLED           SD_SDMMC_DISABLED        // SDMMC禁用
#define  SD_SDIO_FUNCTION_BUSY      SD_SDMMC_FUNCTION_BUSY   // SDMMC功能忙
#define  SD_SDIO_FUNCTION_FAILED    SD_SDMMC_FUNCTION_FAILED // SDMMC功能失败
#define  SD_SDIO_UNKNOWN_FUNCTION   SD_SDMMC_UNKNOWN_FUNCTION// SDMMC未知功能
#define  SD_CMD_SDIO_SEN_OP_COND    SD_CMD_SDMMC_SEN_OP_COND // SDMMC发送OP_COND命令
#define  SD_CMD_SDIO_RW_DIRECT      SD_CMD_SDMMC_RW_DIRECT   // SDMMC直接读写命令
#define  SD_CMD_SDIO_RW_EXTENDED    SD_CMD_SDMMC_RW_EXTENDED // SDMMC扩展读写命令
#define  __HAL_SD_SDIO_ENABLE       __HAL_SD_SDMMC_ENABLE    // 使能SDMMC
#define  __HAL_SD_SDIO_DISABLE      __HAL_SD_SDMMC_DISABLE   // 禁用SDMMC
#define  __HAL_SD_SDIO_DMA_ENABLE   __HAL_SD_SDMMC_DMA_ENABLE// 使能SDMMC DMA
#define  __HAL_SD_SDIO_DMA_DISABL   __HAL_SD_SDMMC_DMA_DISABLE// 禁用SDMMC DMA
#define  __HAL_SD_SDIO_ENABLE_IT    __HAL_SD_SDMMC_ENABLE_IT // 使能SDMMC中断
#define  __HAL_SD_SDIO_DISABLE_IT   __HAL_SD_SDMMC_DISABLE_IT// 禁用SDMMC中断
#define  __HAL_SD_SDIO_GET_FLAG     __HAL_SD_SDMMC_GET_FLAG  // 获取SDMMC标志
#define  __HAL_SD_SDIO_CLEAR_FLAG   __HAL_SD_SDMMC_CLEAR_FLAG// 清除SDMMC标志
#define  __HAL_SD_SDIO_GET_IT       __HAL_SD_SDMMC_GET_IT    // 获取SDMMC中断
#define  __HAL_SD_SDIO_CLEAR_IT     __HAL_SD_SDMMC_CLEAR_IT  // 清除SDMMC中断
#define  SDIO_STATIC_FLAGS          SDMMC_STATIC_FLAGS       // SDMMC静态标志
#define  SDIO_CMD0TIMEOUT           SDMMC_CMD0TIMEOUT        // SDMMC CMD0超时
#define  SD_SDIO_SEND_IF_COND       SD_SDMMC_SEND_IF_COND    // SDMMC发送接口条件
/* alias CMSIS for compatibilities */ // CMSIS别名，用于兼容性
#define  SDIO_IRQn                  SDMMC1_IRQn              // SDMMC1中断号
#define  SDIO_IRQHandler            SDMMC1_IRQHandler        // SDMMC1中断服务函数
#endif

/* SD卡结构体类型定义别名，用于兼容性 */
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F2) || defined(STM32L4) || defined(STM32H7)
#define  HAL_SD_CardCIDTypedef       HAL_SD_CardCIDTypeDef    // SD卡CID寄存器结构体别名
#define  HAL_SD_CardCSDTypedef       HAL_SD_CardCSDTypeDef    // SD卡CSD寄存器结构体别名
#define  HAL_SD_CardStatusTypedef    HAL_SD_CardStatusTypeDef // SD卡状态结构体别名
#define  HAL_SD_CardStateTypedef     HAL_SD_CardStateTypeDef  // SD卡状态枚举别名
#endif

/* MMC/SD DMA双缓冲回调函数别名，用于兼容旧版函数名 */
#if defined(STM32H7) || defined(STM32L5)
#define HAL_MMCEx_Read_DMADoubleBuffer0CpltCallback   HAL_MMCEx_Read_DMADoubleBuf0CpltCallback   // MMC读双缓冲0完成回调
#define HAL_MMCEx_Read_DMADoubleBuffer1CpltCallback   HAL_MMCEx_Read_DMADoubleBuf1CpltCallback   // MMC读双缓冲1完成回调
#define HAL_MMCEx_Write_DMADoubleBuffer0CpltCallback  HAL_MMCEx_Write_DMADoubleBuf0CpltCallback  // MMC写双缓冲0完成回调
#define HAL_MMCEx_Write_DMADoubleBuffer1CpltCallback  HAL_MMCEx_Write_DMADoubleBuf1CpltCallback  // MMC写双缓冲1完成回调
#define HAL_SDEx_Read_DMADoubleBuffer0CpltCallback    HAL_SDEx_Read_DMADoubleBuf0CpltCallback    // SD读双缓冲0完成回调
#define HAL_SDEx_Read_DMADoubleBuffer1CpltCallback    HAL_SDEx_Read_DMADoubleBuf1CpltCallback    // SD读双缓冲1完成回调
#define HAL_SDEx_Write_DMADoubleBuffer0CpltCallback   HAL_SDEx_Write_DMADoubleBuf0CpltCallback   // SD写双缓冲0完成回调
#define HAL_SDEx_Write_DMADoubleBuffer1CpltCallback   HAL_SDEx_Write_DMADoubleBuf1CpltCallback   // SD写双缓冲1完成回调
#define HAL_SD_DriveTransciver_1_8V_Callback          HAL_SD_DriveTransceiver_1_8V_Callback      // SD驱动收发器1.8V回调(修正拼写Transciver->Transceiver)
#endif
/**
  * @}
  */

/** @defgroup HAL_SMARTCARD_Aliased_Macros HAL SMARTCARD Aliased Macros maintained for legacy purpose
  * @{
  */

/* SMARTCARD(智能卡)宏别名 */
#define __SMARTCARD_ENABLE_IT           __HAL_SMARTCARD_ENABLE_IT          // 使能智能卡中断
#define __SMARTCARD_DISABLE_IT          __HAL_SMARTCARD_DISABLE_IT         // 禁用智能卡中断
#define __SMARTCARD_ENABLE              __HAL_SMARTCARD_ENABLE             // 使能智能卡
#define __SMARTCARD_DISABLE             __HAL_SMARTCARD_DISABLE            // 禁用智能卡
#define __SMARTCARD_DMA_REQUEST_ENABLE  __HAL_SMARTCARD_DMA_REQUEST_ENABLE // 使能智能卡DMA请求
#define __SMARTCARD_DMA_REQUEST_DISABLE __HAL_SMARTCARD_DMA_REQUEST_DISABLE// 禁用智能卡DMA请求

#define __HAL_SMARTCARD_GETCLOCKSOURCE  SMARTCARD_GETCLOCKSOURCE           // 获取智能卡时钟源
#define __SMARTCARD_GETCLOCKSOURCE      SMARTCARD_GETCLOCKSOURCE           // 获取智能卡时钟源

#define IS_SMARTCARD_ONEBIT_SAMPLING    IS_SMARTCARD_ONE_BIT_SAMPLE        // 检查智能卡单比特采样

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Macros HAL SMBUS Aliased Macros maintained for legacy purpose
  * @{
  */
/* SMBUS(系统管理总线)宏别名 */
#define __HAL_SMBUS_RESET_CR1           SMBUS_RESET_CR1            // 复位SMBUS CR1寄存器
#define __HAL_SMBUS_RESET_CR2           SMBUS_RESET_CR2            // 复位SMBUS CR2寄存器
#define __HAL_SMBUS_GENERATE_START      SMBUS_GENERATE_START       // 产生起始条件
#define __HAL_SMBUS_GET_ADDR_MATCH      SMBUS_GET_ADDR_MATCH       // 获取匹配地址
#define __HAL_SMBUS_GET_DIR             SMBUS_GET_DIR              // 获取传输方向
#define __HAL_SMBUS_GET_STOP_MODE       SMBUS_GET_STOP_MODE        // 获取停止模式
#define __HAL_SMBUS_GET_PEC_MODE        SMBUS_GET_PEC_MODE         // 获取PEC(包错误校验)模式
#define __HAL_SMBUS_GET_ALERT_ENABLED   SMBUS_GET_ALERT_ENABLED    // 获取警报使能状态
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Macros HAL SPI Aliased Macros maintained for legacy purpose
  * @{
  */

/* SPI(串行外设接口)宏别名 */
#define __HAL_SPI_1LINE_TX              SPI_1LINE_TX    // SPI单线发送模式
#define __HAL_SPI_1LINE_RX              SPI_1LINE_RX    // SPI单线接收模式
#define __HAL_SPI_RESET_CRC             SPI_RESET_CRC   // 复位CRC校验
