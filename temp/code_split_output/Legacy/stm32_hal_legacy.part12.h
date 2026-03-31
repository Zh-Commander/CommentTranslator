/** @defgroup HAL_ADC_Aliased_Macros HAL ADC 为保持向后兼容而维护的别名宏
  * @{
  */
#define __ADC_ENABLE                                     __HAL_ADC_ENABLE                                        /* 使能 ADC */
#define __ADC_DISABLE                                    __HAL_ADC_DISABLE                                       /* 禁用 ADC */
#define __HAL_ADC_ENABLING_CONDITIONS                    ADC_ENABLING_CONDITIONS                                 /* ADC 使能条件 */
#define __HAL_ADC_DISABLING_CONDITIONS                   ADC_DISABLING_CONDITIONS                                /* ADC 禁用条件 */
#define __HAL_ADC_IS_ENABLED                             ADC_IS_ENABLE                                           /* 检查 ADC 是否使能 */
#define __ADC_IS_ENABLED                                 ADC_IS_ENABLE                                           /* 检查 ADC 是否使能（别名） */
#define __HAL_ADC_IS_SOFTWARE_START_REGULAR              ADC_IS_SOFTWARE_START_REGULAR                           /* 检查是否软件启动常规转换 */
#define __HAL_ADC_IS_SOFTWARE_START_INJECTED             ADC_IS_SOFTWARE_START_INJECTED                          /* 检查是否软件启动注入转换 */
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED              /* 检查常规或注入转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR          ADC_IS_CONVERSION_ONGOING_REGULAR                       /* 检查常规转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING_INJECTED         ADC_IS_CONVERSION_ONGOING_INJECTED                      /* 检查注入转换是否正在进行 */
#define __HAL_ADC_IS_CONVERSION_ONGOING                  ADC_IS_CONVERSION_ONGOING                               /* 检查转换是否正在进行 */
#define __HAL_ADC_CLEAR_ERRORCODE                        ADC_CLEAR_ERRORCODE                                     /* 清除错误代码 */

#define __HAL_ADC_GET_RESOLUTION                         ADC_GET_RESOLUTION                                      /* 获取 ADC 分辨率 */
#define __HAL_ADC_JSQR_RK                                ADC_JSQR_RK                                              /* 获取注入序列器中的第 K 个通道 */
#define __HAL_ADC_CFGR_AWD1CH                            ADC_CFGR_AWD1CH_SHIFT                                   /* 获取模拟看门狗 1 通道偏移 */
#define __HAL_ADC_CFGR_AWD23CR                           ADC_CFGR_AWD23CR                                        /* 获取模拟看门狗 2/3 控制寄存器位 */
#define __HAL_ADC_CFGR_INJECT_AUTO_CONVERSION            ADC_CFGR_INJECT_AUTO_CONVERSION                         /* 获取注入自动转换位 */
#define __HAL_ADC_CFGR_INJECT_CONTEXT_QUEUE              ADC_CFGR_INJECT_CONTEXT_QUEUE                           /* 获取注入上下文队列位 */
#define __HAL_ADC_CFGR_INJECT_DISCCONTINUOUS             ADC_CFGR_INJECT_DISCCONTINUOUS                          /* 获取注入不连续模式位 */
#define __HAL_ADC_CFGR_REG_DISCCONTINUOUS                ADC_CFGR_REG_DISCCONTINUOUS                             /* 获取常规不连续模式位 */
#define __HAL_ADC_CFGR_DISCONTINUOUS_NUM                 ADC_CFGR_DISCONTINUOUS_NUM                              /* 获取不连续模式序列长度 */
#define __HAL_ADC_CFGR_AUTOWAIT                          ADC_CFGR_AUTOWAIT                                       /* 获取自动等待位 */
#define __HAL_ADC_CFGR_CONTINUOUS                        ADC_CFGR_CONTINUOUS                                     /* 获取连续转换模式位 */
#define __HAL_ADC_CFGR_OVERRUN                           ADC_CFGR_OVERRUN                                        /* 获取溢出配置位 */
#define __HAL_ADC_CFGR_DMACONTREQ                        ADC_CFGR_DMACONTREQ                                     /* 获取 DMA 连续请求位 */
#define __HAL_ADC_CFGR_EXTSEL                            ADC_CFGR_EXTSEL_SET                                     /* 获取外部触发选择位（常规转换） */
#define __HAL_ADC_JSQR_JEXTSEL                           ADC_JSQR_JEXTSEL_SET                                    /* 获取外部触发选择位（注入转换） */
#define __HAL_ADC_OFR_CHANNEL                            ADC_OFR_CHANNEL                                         /* 获取偏移通道选择位 */
#define __HAL_ADC_DIFSEL_CHANNEL                         ADC_DIFSEL_CHANNEL                                      /* 获取差分输入选择位 */
#define __HAL_ADC_CALFACT_DIFF_SET                       ADC_CALFACT_DIFF_SET                                    /* 设置差分模式校准因子 */
#define __HAL_ADC_CALFACT_DIFF_GET                       ADC_CALFACT_DIFF_GET                                    /* 获取差分模式校准因子 */
#define __HAL_ADC_TRX_HIGHTHRESHOLD                      ADC_TRX_HIGHTHRESHOLD                                   /* 获取高阈值位 */

#define __HAL_ADC_OFFSET_SHIFT_RESOLUTION                ADC_OFFSET_SHIFT_RESOLUTION                             /* 偏移值分辨率移位 */
#define __HAL_ADC_AWD1THRESHOLD_SHIFT_RESOLUTION         ADC_AWD1THRESHOLD_SHIFT_RESOLUTION                      /* 模拟看门狗1阈值分辨率移位 */
#define __HAL_ADC_AWD23THRESHOLD_SHIFT_RESOLUTION        ADC_AWD23THRESHOLD_SHIFT_RESOLUTION                     /* 模拟看门狗2/3阈值分辨率移位 */
#define __HAL_ADC_COMMON_REGISTER                        ADC_COMMON_REGISTER                                     /* 获取 ADC 通用寄存器 */
#define __HAL_ADC_COMMON_CCR_MULTI                       ADC_COMMON_CCR_MULTI                                    /* 获取多 ADC 模式控制位 */
#define __HAL_ADC_MULTIMODE_IS_ENABLED                   ADC_MULTIMODE_IS_ENABLE                                 /* 检查多 ADC 模式是否使能 */
#define __ADC_MULTIMODE_IS_ENABLED                       ADC_MULTIMODE_IS_ENABLE                                 /* 检查多 ADC 模式是否使能（别名） */
#define __HAL_ADC_NONMULTIMODE_OR_MULTIMODEMASTER        ADC_NONMULTIMODE_OR_MULTIMODEMASTER                     /* 检查是否为非多模式或多模式主设备 */
#define __HAL_ADC_COMMON_ADC_OTHER                       ADC_COMMON_ADC_OTHER                                    /* 获取其他 ADC 的通用寄存器 */
#define __HAL_ADC_MULTI_SLAVE                            ADC_MULTI_SLAVE                                         /* 获取多 ADC 模式中的从设备 */

#define __HAL_ADC_SQR1_L                                 ADC_SQR1_L_SHIFT                                        /* 获取常规序列长度偏移 */
#define __HAL_ADC_JSQR_JL                                ADC_JSQR_JL_SHIFT                                       /* 获取注入序列长度偏移 */
#define __HAL_ADC_JSQR_RK_JL                             ADC_JSQR_RK_JL                                          /* 获取注入序列中第 K 个通道（考虑序列长度） */
#define __HAL_ADC_CR1_DISCONTINUOUS_NUM                  ADC_CR1_DISCONTINUOUS_NUM                               /* 获取不连续模式序列长度（CR1 寄存器） */
#define __HAL_ADC_CR1_SCAN                               ADC_CR1_SCAN_SET                                        /* 获取扫描模式位 */
#define __HAL_ADC_CONVCYCLES_MAX_RANGE                   ADC_CONVCYCLES_MAX_RANGE                                /* 获取最大转换周期范围 */
#define __HAL_ADC_CLOCK_PRESCALER_RANGE                  ADC_CLOCK_PRESCALER_RANGE                               /* 获取时钟预分频器范围 */
#define __HAL_ADC_GET_CLOCK_PRESCALER                    ADC_GET_CLOCK_PRESCALER                                 /* 获取时钟预分频器 */

#define __HAL_ADC_SQR1                                   ADC_SQR1                                                /* 获取序列寄存器 1 */
#define __HAL_ADC_SMPR1                                  ADC_SMPR1                                               /* 获取采样时间寄存器 1 */
#define __HAL_ADC_SMPR2                                  ADC_SMPR2                                               /* 获取采样时间寄存器 2 */
#define __HAL_ADC_SQR3_RK                                ADC_SQR3_RK                                             /* 获取序列寄存器 3 中第 K 个通道 */
#define __HAL_ADC_SQR2_RK                                ADC_SQR2_RK                                             /* 获取序列寄存器 2 中第 K 个通道 */
#define __HAL_ADC_SQR1_RK                                ADC_SQR1_RK                                             /* 获取序列寄存器 1 中第 K 个通道 */
#define __HAL_ADC_CR2_CONTINUOUS                         ADC_CR2_CONTINUOUS                                      /* 获取连续转换模式位（CR2 寄存器） */
#define __HAL_ADC_CR1_DISCONTINUOUS                      ADC_CR1_DISCONTINUOUS                                   /* 获取不连续模式位 */
#define __HAL_ADC_CR1_SCANCONV                           ADC_CR1_SCANCONV                                        /* 获取扫描转换模式位 */
#define __HAL_ADC_CR2_EOCSelection                       ADC_CR2_EOCSelection                                    /* 获取转换结束选择位 */
#define __HAL_ADC_CR2_DMAContReq                         ADC_CR2_DMAContReq                                      /* 获取 DMA 连续请求位（CR2 寄存器） */
#define __HAL_ADC_JSQR                                   ADC_JSQR                                                /* 获取注入序列寄存器 */

#define __HAL_ADC_CHSELR_CHANNEL                         ADC_CHSELR_CHANNEL                                      /* 获取通道选择寄存器中的通道位 */
#define __HAL_ADC_CFGR1_REG_DISCCONTINUOUS               ADC_CFGR1_REG_DISCCONTINUOUS                            /* 获取常规不连续模式位（CFGR1 寄存器） */
#define __HAL_ADC_CFGR1_AUTOOFF                          ADC_CFGR1_AUTOOFF                                       /* 获取自动关闭模式位 */
#define __HAL_ADC_CFGR1_AUTOWAIT                         ADC_CFGR1_AUTOWAIT                                      /* 获取自动等待位（CFGR1 寄存器） */
#define __HAL_ADC_CFGR1_CONTINUOUS                       ADC_CFGR1_CONTINUOUS                                    /* 获取连续转换模式位（CFGR1 寄存器） */
#define __HAL_ADC_CFGR1_OVERRUN                          ADC_CFGR1_OVERRUN                                       /* 获取溢出配置位（CFGR1 寄存器） */
#define __HAL_ADC_CFGR1_SCANDIR                          ADC_CFGR1_SCANDIR                                       /* 获取扫描方向位 */
#define __HAL_ADC_CFGR1_DMACONTREQ                       ADC_CFGR1_DMACONTREQ                                    /* 获取 DMA 连续请求位（CFGR1 寄存器） */

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC 为保持向后兼容而维护的别名宏
  * @{
  */
#define __HAL_DHR12R1_ALIGNEMENT                        DAC_DHR12R1_ALIGNMENT                                     /* 12 位右对齐数据保持寄存器 1 对齐方式 */
#define __HAL_DHR12R2_ALIGNEMENT                        DAC_DHR12R2_ALIGNMENT                                     /* 12 位右对齐数据保持寄存器 2 对齐方式 */
#define __HAL_DHR12RD_ALIGNEMENT                        DAC_DHR12RD_ALIGNMENT                                     /* 12 位右对齐双数据保持寄存器对齐方式 */
#define IS_DAC_GENERATE_WAVE                            IS_DAC_WAVE                                               /* 检查是否为 DAC 波形生成 */

/**
  * @}
  */

/** @defgroup HAL_DBGMCU_Aliased_Macros HAL DBGMCU 为保持向后兼容而维护的别名宏
  * @{
  */
#define __HAL_FREEZE_TIM1_DBGMCU __HAL_DBGMCU_FREEZE_TIM1                                                          /* 在调试时冻结 TIM1 */
#define __HAL_UNFREEZE_TIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM1                                                      /* 在调试时解冻 TIM1 */
#define __HAL_FREEZE_TIM2_DBGMCU __HAL_DBGMCU_FREEZE_TIM2                                                          /* 在调试时冻结 TIM2 */
#define __HAL_UNFREEZE_TIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM2                                                      /* 在调试时解冻 TIM2 */
#define __HAL_FREEZE_TIM3_DBGMCU __HAL_DBGMCU_FREEZE_TIM3                                                          /* 在调试时冻结 TIM3 */
#define __HAL_UNFREEZE_TIM3_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM3                                                      /* 在调试时解冻 TIM3 */
#define __HAL_FREEZE_TIM4_DBGMCU __HAL_DBGMCU_FREEZE_TIM4                                                          /* 在调试时冻结 TIM4 */
#define __HAL_UNFREEZE_TIM4_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM4                                                      /* 在调试时解冻 TIM4 */
#define __HAL_FREEZE_TIM5_DBGMCU __HAL_DBGMCU_FREEZE_TIM5                                                          /* 在调试时冻结 TIM5 */
#define __HAL_UNFREEZE_TIM5_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM5                                                      /* 在调试时解冻 TIM5 */
#define __HAL_FREEZE_TIM6_DBGMCU __HAL_DBGMCU_FREEZE_TIM6                                                          /* 在调试时冻结 TIM6 */
#define __HAL_UNFREEZE_TIM6_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM6                                                      /* 在调试时解冻 TIM6 */
#define __HAL_FREEZE_TIM7_DBGMCU __HAL_DBGMCU_FREEZE_TIM7                                                          /* 在调试时冻结 TIM7 */
#define __HAL_UNFREEZE_TIM7_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM7                                                      /* 在调试时解冻 TIM7 */
#define __HAL_FREEZE_TIM8_DBGMCU __HAL_DBGMCU_FREEZE_TIM8                                                          /* 在调试时冻结 TIM8 */
#define __HAL_UNFREEZE_TIM8_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM8                                                      /* 在调试时解冻 TIM8 */

#define __HAL_FREEZE_TIM9_DBGMCU __HAL_DBGMCU_FREEZE_TIM9                                                          /* 在调试时冻结 TIM9 */
#define __HAL_UNFREEZE_TIM9_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM9                                                      /* 在调试时解冻 TIM9 */
#define __HAL_FREEZE_TIM10_DBGMCU __HAL_DBGMCU_FREEZE_TIM10                                                        /* 在调试时冻结 TIM10 */
#define __HAL_UNFREEZE_TIM10_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM10                                                    /* 在调试时解冻 TIM10 */
#define __HAL_FREEZE_TIM11_DBGMCU __HAL_DBGMCU_FREEZE_TIM11                                                        /* 在调试时冻结 TIM11 */
#define __HAL_UNFREEZE_TIM11_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM11                                                    /* 在调试时解冻 TIM11 */
#define __HAL_FREEZE_TIM12_DBGMCU __HAL_DBGMCU_FREEZE_TIM12                                                        /* 在调试时冻结 TIM12 */
#define __HAL_UNFREEZE_TIM12_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM12                                                    /* 在调试时解冻 TIM12 */
#define __HAL_FREEZE_TIM13_DBGMCU __HAL_DBGMCU_FREEZE_TIM13                                                        /* 在调试时冻结 TIM13 */
#define __HAL_UNFREEZE_TIM13_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM13                                                    /* 在调试时解冻 TIM13 */
#define __HAL_FREEZE_TIM14_DBGMCU __HAL_DBGMCU_FREEZE_TIM14                                                        /* 在调试时冻结 TIM14 */
#define __HAL_UNFREEZE_TIM14_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM14                                                    /* 在调试时解冻 TIM14 */
#define __HAL_FREEZE_CAN2_DBGMCU __HAL_DBGMCU_FREEZE_CAN2                                                          /* 在调试时冻结 CAN2 */
#define __HAL_UNFREEZE_CAN2_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN2                                                      /* 在调试时解冻 CAN2 */


#define __HAL_FREEZE_TIM15_DBGMCU __HAL_DBGMCU_FREEZE_TIM15                                                        /* 在调试时冻结 TIM15 */
#define __HAL_UNFREEZE_TIM15_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM15                                                    /* 在调试时解冻 TIM15 */
#define __HAL_FREEZE_TIM16_DBGMCU __HAL_DBGMCU_FREEZE_TIM16                                                        /* 在调试时冻结 TIM16 */
#define __HAL_UNFREEZE_TIM16_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM16                                                    /* 在调试时解冻 TIM16 */
#define __HAL_FREEZE_TIM17_DBGMCU __HAL_DBGMCU_FREEZE_TIM17                                                        /* 在调试时冻结 TIM17 */
#define __HAL_UNFREEZE_TIM17_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM17                                                    /* 在调试时解冻 TIM17 */
#define __HAL_FREEZE_RTC_DBGMCU __HAL_DBGMCU_FREEZE_RTC                                                            /* 在调试时冻结 RTC */
#define __HAL_UNFREEZE_RTC_DBGMCU __HAL_DBGMCU_UNFREEZE_RTC                                                        /* 在调试时解冻 RTC */
#if defined(STM32H7)
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG1                                                         /* 在调试时冻结 WWDG1（适用于 STM32H7） */
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UnFreeze_WWDG1                                                     /* 在调试时解冻 WWDG1（适用于 STM32H7） */
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG1                                                         /* 在调试时冻结 IWDG1（适用于 STM32H7） */
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UnFreeze_IWDG1                                                     /* 在调试时解冻 IWDG1（适用于 STM32H7） */
#else
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG                                                          /* 在调试时冻结 WWDG（非 STM32H7） */
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_WWDG                                                      /* 在调试时解冻 WWDG（非 STM32H7） */
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG                                                          /* 在调试时冻结 IWDG（非 STM32H7） */
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_IWDG                                                      /* 在调试时解冻 IWDG（非 STM32H7） */
#endif /* STM32H7 */
#define __HAL_FREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT                                          /* 在调试时冻结 I2C1 超时 */
#define __HAL_UNFREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT                                      /* 在调试时解冻 I2C1 超时 */
#define __HAL_FREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT                                          /* 在调试时冻结 I2C2 超时 */
#define __HAL_UNFREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT                                      /* 在调试时解冻 I2C2 超时 */
#define __HAL_FREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT                                          /* 在调试时冻结 I2C3 超时 */
#define __HAL_UNFREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT                                      /* 在调试时解冻 I2C3 超时 */
#define __HAL_FREEZE_CAN1_DBGMCU __HAL_DBGMCU_FREEZE_CAN1                                                          /* 在调试时冻结 CAN1 */
#define __HAL_UNFREEZE_CAN1_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN1                                                      /* 在调试时解冻 CAN1 */
#define __HAL_FREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM1                                                      /* 在调试时冻结 LPTIM1 */
#define __HAL_UNFREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM1                                                  /* 在调试时解冻 LPTIM1 */
#define __HAL_FREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM2                                                      /* 在调试时冻结 LPTIM2 */
#define __HAL_UNFREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM2                                                  /* 在调试时解冻 LPTIM2 */

/**
  * @}
  */