#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** @defgroup ADCEx_Common_mode ADC 扩展双 ADC 模式
  * @{
  */
/* ADC 双模式禁用 (ADC 独立模式) */
#define ADC_MODE_INDEPENDENT                              0x00000000U
/* ADC 双模式使能: 组合规则同步 + 注入同步模式，作用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT    ((uint32_t)(                                                            ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 组合规则同步 + 交替触发模式，作用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG      ((uint32_t)(                                        ADC_CR1_DUALMOD_1                    ))
/* ADC 双模式使能: 组合注入同步 + 快速交错模式，作用于规则组和注入组 (ADC 采样阶段之间的延迟: 7 个 ADC 时钟周期) */
#define ADC_DUALMODE_INJECSIMULT_INTERLFAST   ((uint32_t)(                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 组合注入同步 + 慢速交错模式，作用于规则组和注入组 (ADC 采样阶段之间的延迟: 14 个 ADC 时钟周期) */
#define ADC_DUALMODE_INJECSIMULT_INTERLSLOW   ((uint32_t)(                    ADC_CR1_DUALMOD_2                                        ))
/* ADC 双模式使能: 注入同步模式，作用于注入组 */
#define ADC_DUALMODE_INJECSIMULT              ((uint32_t)(                    ADC_CR1_DUALMOD_2 |                     ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 规则同步模式，作用于规则组 */
#define ADC_DUALMODE_REGSIMULT                ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    ))
/* ADC 双模式使能: 快速交错模式，作用于规则组 (ADC 采样阶段之间的延迟: 7 个 ADC 时钟周期) */
#define ADC_DUALMODE_INTERLFAST               ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0))
/* ADC 双模式使能: 慢速交错模式，作用于规则组 (ADC 采样阶段之间的延迟: 14 个 ADC 时钟周期) */
#define ADC_DUALMODE_INTERLSLOW               ((uint32_t)(ADC_CR1_DUALMOD_3                                                            ))
/* ADC 双模式使能: 交替触发模式，作用于注入组 */
#define ADC_DUALMODE_ALTERTRIG                ((uint32_t)(ADC_CR1_DUALMOD_3 |                                         ADC_CR1_DUALMOD_0))
/**
  * @}
  */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* 私有常量 ---------------------------------------------------------*/

/** @addtogroup ADCEx_Private_Constants ADCEx 私有常量
  * @{
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Regular ADC 扩展内部 HAL 驱动规则组触发源选择
  * @{
  */
/* ADC1, ADC2, ADC3 (如果选定的设备上有该 ADC 实例) 规则组的外部触发列表。*/
/* (由 HAL 驱动内部使用。不用于 HAL 结构参数)  */

/* ADC1 和 ADC2 规则组的外部触发 (如果有 ADCx 可用) */
/* 定时器 1 捕获/比较通道 1 */
#define ADC1_2_EXTERNALTRIG_T1_CC1                       0x00000000U
/* 定时器 1 捕获/比较通道 2 */
#define ADC1_2_EXTERNALTRIG_T1_CC2           ((uint32_t)(                                      ADC_CR2_EXTSEL_0))
/* 定时器 2 捕获/比较通道 2 */
#define ADC1_2_EXTERNALTRIG_T2_CC2           ((uint32_t)(                   ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/* 定时器 3 触发输出 */
#define ADC1_2_EXTERNALTRIG_T3_TRGO          ((uint32_t)(ADC_CR2_EXTSEL_2                                      ))
/* 定时器 4 捕获/比较通道 4 */
#define ADC1_2_EXTERNALTRIG_T4_CC4           ((uint32_t)(ADC_CR2_EXTSEL_2 |                    ADC_CR2_EXTSEL_0))
/* 外部中断线 11 */
#define ADC1_2_EXTERNALTRIG_EXT_IT11         ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1                   ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意: TIM8_TRGO 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用。*/
#define ADC1_2_EXTERNALTRIG_T8_TRGO          ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3 规则组的外部触发 */
/* 定时器 3 捕获/比较通道 1 */
#define ADC3_EXTERNALTRIG_T3_CC1             ADC1_2_EXTERNALTRIG_T1_CC1
/* 定时器 2 捕获/比较通道 3 */
#define ADC3_EXTERNALTRIG_T2_CC3             ADC1_2_EXTERNALTRIG_T1_CC2
/* 定时器 8 捕获/比较通道 1 */
#define ADC3_EXTERNALTRIG_T8_CC1             ADC1_2_EXTERNALTRIG_T2_CC2
/* 定时器 8 触发输出 */
#define ADC3_EXTERNALTRIG_T8_TRGO            ADC1_2_EXTERNALTRIG_T3_TRGO
/* 定时器 5 捕获/比较通道 1 */
#define ADC3_EXTERNALTRIG_T5_CC1             ADC1_2_EXTERNALTRIG_T4_CC4
/* 定时器 5 捕获/比较通道 3 */
#define ADC3_EXTERNALTRIG_T5_CC3             ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

/* ADC1, ADC2, ADC3 规则组的外部触发 (如果有 ADCx 可用) */
/* 定时器 1 捕获/比较通道 3 */
#define ADC1_2_3_EXTERNALTRIG_T1_CC3         ((uint32_t)(                   ADC_CR2_EXTSEL_1                   ))
/* 软件触发 */
#define ADC1_2_3_SWSTART                     ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/**
  * @}
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Injected ADC 扩展内部 HAL 驱动注入组触发源选择
  * @{
  */
/* ADC1, ADC2, ADC3 (如果选定的设备上有该 ADC 实例) 注入组的外部触发列表。*/
/* (由 HAL 驱动内部使用。不用于 HAL 结构参数)  */

/* ADC1 和 ADC2 注入组的外部触发 (如果有 ADCx 可用) */
/* 定时器 2 触发输出 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_TRGO          ((uint32_t)(                    ADC_CR2_JEXTSEL_1                    ))
/* 定时器 2 捕获/比较通道 1 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_CC1           ((uint32_t)(                    ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/* 定时器 3 捕获/比较通道 4 */
#define ADC1_2_EXTERNALTRIGINJEC_T3_CC4           ((uint32_t)(ADC_CR2_JEXTSEL_2                                        ))
/* 定时器 4 触发输出 */
#define ADC1_2_EXTERNALTRIGINJEC_T4_TRGO          ((uint32_t)(ADC_CR2_JEXTSEL_2 |                     ADC_CR2_JEXTSEL_0))
/* 外部中断线 15 */
#define ADC1_2_EXTERNALTRIGINJEC_EXT_IT15         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1                    ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意: TIM8_CC4 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用。*/
#define ADC1_2_EXTERNALTRIGINJEC_T8_CC4           ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3 注入组的外部触发 */
/* 定时器 4 捕获/比较通道 3 */
#define ADC3_EXTERNALTRIGINJEC_T4_CC3             ADC1_2_EXTERNALTRIGINJEC_T2_TRGO
/* 定时器 8 捕获/比较通道 2 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC2             ADC1_2_EXTERNALTRIGINJEC_T2_CC1
/* 定时器 8 捕获/比较通道 4 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC4             ADC1_2_EXTERNALTRIGINJEC_T3_CC4
/* 定时器 5 触发输出 */
#define ADC3_EXTERNALTRIGINJEC_T5_TRGO            ADC1_2_EXTERNALTRIGINJEC_T4_TRGO
/* 定时器 5 捕获/比较通道 4 */
#define ADC3_EXTERNALTRIGINJEC_T5_CC4             ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif /* STM32F103xE || defined STM32F103xG */

/* ADC1, ADC2, ADC3 注入组的外部触发 (如果有 ADCx 可用) */
/* 定时器 1 触发输出 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO                    0x00000000U
/* 定时器 1 捕获/比较通道 4 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4         ((uint32_t)(                                        ADC_CR2_JEXTSEL_0))
/* 注入组软件触发 */
#define ADC1_2_3_JSWSTART                         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/**
  * @}
  */

/**
  * @}
  */


/* 导出宏 ------------------------------------------------------------*/

/* 私有宏 -------------------------------------------------------------*/

/** @defgroup ADCEx_Private_Macro ADCEx 私有宏
  * @{
  */
/* 宏保留供 HAL 驱动内部使用，不打算在最终用户的代码中使用。*/

    
/**
  * @brief 对于具有 3 个 ADC 的设备: 根据公共组 ADC1&ADC2 或 ADC3 中的 ADC 定义规则组的外部触发源
  *        (某些具有相同源的触发器在写入 CR2 寄存器的 EXTSEL 位时具有不同的值)。
  *        对于具有 2 个或更少 ADC 的设备: 此宏不做任何更改。
  * @param __HANDLE__: ADC 句柄
  * @param __EXT_TRIG_CONV__: 为规则组选择的外部触发。
  * @retval 要写入 CR2 寄存器 EXTSEL 位的外部触发值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 配置规则组外部触发源 (ADC3 与 ADC1/2 部分触发源不同) */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
 (( (((__HANDLE__)->Instance) == ADC3)                                         \
  )?                                                                           \
   ( ( (__EXT_TRIG_CONV__) == ADC_EXTERNALTRIGCONV_T8_TRGO                     \
     )?                                                                        \
      (ADC3_EXTERNALTRIG_T8_TRGO)                                              \
      :                                                                        \
      (__EXT_TRIG_CONV__)                                                      \
   )                                                                           \
   :                                                                           \
   (__EXT_TRIG_CONV__)                                                         \
 )
#else
/* 宏定义: 配置规则组外部触发源 (非大容量设备，直接返回传入值) */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
  (__EXT_TRIG_CONV__)
#endif /* STM32F103xE || STM32F103xG */

/**
  * @brief 对于具有 3 个 ADC 的设备: 根据公共组 ADC1&ADC2 或 ADC3 中的 ADC 定义注入组的外部触发源
  *        (某些具有相同源的触发器在写入 CR2 寄存器的 JEXTSEL 位时具有不同的值)。
  *        对于具有 2 个或更少 ADC 的设备: 此宏不做任何更改。
  * @param __HANDLE__: ADC 句柄
  * @param __EXT_TRIG_INJECTCONV__: 为注入组选择的外部触发。
  * @retval 要写入 CR2 寄存器 JEXTSEL 位的外部触发值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 配置注入组外部触发源 (ADC3 与 ADC1/2 部分触发源不同) */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
 (( (((__HANDLE__)->Instance) == ADC3)                                         \
  )?                                                                           \
   ( ( (__EXT_TRIG_INJECTCONV__) == ADC_EXTERNALTRIGINJECCONV_T8_CC4           \
     )?                                                                        \
      (ADC3_EXTERNALTRIGINJEC_T8_CC4)                                          \
      :                                                                        \
      (__EXT_TRIG_INJECTCONV__)                                                \
   )                                                                           \
   :                                                                           \
   (__EXT_TRIG_INJECTCONV__)                                                   \
 )
#else
/* 宏定义: 配置注入组外部触发源 (非大容量设备，直接返回传入值) */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
   (__EXT_TRIG_INJECTCONV__)
#endif /* STM32F103xE || STM32F103xG */


/**
  * @brief 验证所选 ADC 的多模式是否使能 (多模式 ADC 主机或 ADC 从机) (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 多模式状态: 如果多模式禁用则为 RESET，如果多模式使能则为其他值
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 检查多模式是否使能 (通过检查 ADC1 的 CR1 寄存器 DUALMOD 位) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
 (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)   \
  )?                                                                           \
   (ADC1->CR1 & ADC_CR1_DUALMOD)                                               \
   :                                                                           \
   (RESET)                                                                     \
 )
#else
/* 宏定义: 检查多模式是否使能 (无多模式功能的设备，直接返回 RESET) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief ADC 启动转换条件的验证: ADC 必须处于非多模式，或者是多模式下的 ADC 主机句柄 (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 检查是否为非多模式或多模式主机 (ADC2 作为从机时不能独立启动) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (( (((__HANDLE__)->Instance) == ADC2)                                        \
   )?                                                                          \
    ((ADC1->CR1 & ADC_CR1_DUALMOD) == RESET)                                   \
    :                                                                          \
    (!RESET)                                                                   \
  )
#else
/* 宏定义: 检查是否为非多模式或多模式主机 (无多模式功能的设备，直接返回 !RESET) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (!RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief 检查 ADC 多模式设置: 在多模式情况下，检查所选 ADC 的 ADC 主机是否启用了自动注入功能 (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义: 检查多模式下自动注入是否使能 */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)  \
   )?                                                                          \
    (ADC1->CR1 & ADC_CR1_JAUTO)                                                \
    :                                                                          \
    (RESET)                                                                    \
  )
#else
/* 宏定义: 检查多模式下自动注入是否使能 (无多模式功能的设备，直接返回 RESET) */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief 设置共享公共多模式设置的另一个 ADC 的句柄
  * @param __HANDLE__: ADC 句柄
  * @param __HANDLE_OTHER_ADC__: 另一个 ADC 句柄
  * @retval 无
  */
/* 宏定义: 获取另一个 ADC 句柄 (固定为 ADC2) */
#define ADC_COMMON_ADC_OTHER(__HANDLE__, __HANDLE_OTHER_ADC__)                 \
  ((__HANDLE_OTHER_ADC__)->Instance = ADC2)

/**
  * @brief 设置与 ADC 主机关联的 ADC 从机句柄
  * 在 STM32F1 设备上，ADC 从机始终是 ADC2 (在其他 STM32 设备上可能不同)
  * @param __HANDLE_MASTER__: ADC 主机句柄
  * @param __HANDLE_SLAVE__: ADC 从机句柄
  * @retval 无
  */
/* 宏定义: 设置 ADC 从机句柄 (固定为 ADC2) */
#define ADC_MULTI_SLAVE(__HANDLE_MASTER__, __HANDLE_SLAVE__)                   \
  ((__HANDLE_SLAVE__)->Instance = ADC2)
       
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* 宏定义: 检查注入通道排名是否有效 (1 到 4) */
#define IS_ADC_INJECTED_RANK(CHANNEL) (((CHANNEL) == ADC_INJECTED_RANK_1) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_2) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_3) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_4))

/* 宏定义: 检查注入组外部触发边沿是否有效 (无触发或上升沿) */
#define IS_ADC_EXTTRIGINJEC_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)  || \
                                        ((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING))

/** @defgroup ADCEx_injected_nb_conv_verification ADCEx 注入转换数量验证
  * @{
  */
/* 宏定义: 检查注入组转换数量是否有效 (1 到 4) */
#define IS_ADC_INJECTED_NB_CONV(LENGTH)  (((LENGTH) >= 1U) && ((LENGTH) <= 4U))
/**
  * @}
  */
