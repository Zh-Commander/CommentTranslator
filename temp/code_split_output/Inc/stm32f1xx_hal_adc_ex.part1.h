#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** @defgroup ADCEx_Common_mode ADC Extended Dual ADC Mode
  * @{
  */
/* ADC双模禁用（ADC独立模式） */
#define ADC_MODE_INDEPENDENT                              0x00000000U                                                                     
/* ADC双模使能：组合规则同步 + 注入同步模式，作用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT    ((uint32_t)(                                                            ADC_CR1_DUALMOD_0)) 
/* ADC双模使能：组合规则同步 + 交替触发模式，作用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG      ((uint32_t)(                                        ADC_CR1_DUALMOD_1                    )) 
/* ADC双模使能：组合注入同步 + 快速交错模式，作用于规则组和注入组（ADC采样阶段间延迟：7个ADC时钟周期） */
#define ADC_DUALMODE_INJECSIMULT_INTERLFAST   ((uint32_t)(                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0)) 
/* ADC双模使能：组合注入同步 + 慢速交错模式，作用于规则组和注入组（ADC采样阶段间延迟：14个ADC时钟周期） */
#define ADC_DUALMODE_INJECSIMULT_INTERLSLOW   ((uint32_t)(                    ADC_CR1_DUALMOD_2                                        )) 
/* ADC双模使能：注入同步模式，作用于注入组 */
#define ADC_DUALMODE_INJECSIMULT              ((uint32_t)(                    ADC_CR1_DUALMOD_2 |                     ADC_CR1_DUALMOD_0)) 
/* ADC双模使能：规则同步模式，作用于规则组 */
#define ADC_DUALMODE_REGSIMULT                ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    )) 
/* ADC双模使能：快速交错模式，作用于规则组（ADC采样阶段间延迟：7个ADC时钟周期） */
#define ADC_DUALMODE_INTERLFAST               ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0)) 
/* ADC双模使能：慢速交错模式，作用于规则组（ADC采样阶段间延迟：14个ADC时钟周期） */
#define ADC_DUALMODE_INTERLSLOW               ((uint32_t)(ADC_CR1_DUALMOD_3                                                            )) 
/* ADC双模使能：交替触发模式，作用于注入组 */
#define ADC_DUALMODE_ALTERTRIG                ((uint32_t)(ADC_CR1_DUALMOD_3 |                                         ADC_CR1_DUALMOD_0)) 
/**
  * @}
  */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* Private constants ---------------------------------------------------------*/
/* 私有常量定义 ---------------------------------------------------------*/

/** @addtogroup ADCEx_Private_Constants ADCEx Private Constants
  * @{
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Regular ADC Extended Internal HAL driver trigger selection for regular group
  * @{
  */
/* ADC1, ADC2, ADC3（如果选定设备上有ADC实例）规则组的外部触发源列表。*/
/* （由HAL驱动程序内部使用。不要在HAL结构参数中使用）*/

/* ADC1和ADC2规则组的外部触发源（如果有ADCx可用） */
/* 定时器1捕获比较通道1 */
#define ADC1_2_EXTERNALTRIG_T1_CC1                       0x00000000U
/* 定时器1捕获比较通道2 */
#define ADC1_2_EXTERNALTRIG_T1_CC2           ((uint32_t)(                                      ADC_CR2_EXTSEL_0))
/* 定时器2捕获比较通道2 */
#define ADC1_2_EXTERNALTRIG_T2_CC2           ((uint32_t)(                   ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/* 定时器3触发输出 */
#define ADC1_2_EXTERNALTRIG_T3_TRGO          ((uint32_t)(ADC_CR2_EXTSEL_2                                      ))
/* 定时器4捕获比较通道4 */
#define ADC1_2_EXTERNALTRIG_T4_CC4           ((uint32_t)(ADC_CR2_EXTSEL_2 |                    ADC_CR2_EXTSEL_0))
/* 外部中断线11 */
#define ADC1_2_EXTERNALTRIG_EXT_IT11         ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1                   ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意：TIM8_TRGO仅在超大容量和大容量设备的ADC1和ADC2上可用。*/
#define ADC1_2_EXTERNALTRIG_T8_TRGO          ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3规则组的外部触发源 */
/* 定时器3捕获比较通道1 */
#define ADC3_EXTERNALTRIG_T3_CC1             ADC1_2_EXTERNALTRIG_T1_CC1
/* 定时器2捕获比较通道3 */
#define ADC3_EXTERNALTRIG_T2_CC3             ADC1_2_EXTERNALTRIG_T1_CC2
/* 定时器8捕获比较通道1 */
#define ADC3_EXTERNALTRIG_T8_CC1             ADC1_2_EXTERNALTRIG_T2_CC2
/* 定时器8触发输出 */
#define ADC3_EXTERNALTRIG_T8_TRGO            ADC1_2_EXTERNALTRIG_T3_TRGO
/* 定时器5捕获比较通道1 */
#define ADC3_EXTERNALTRIG_T5_CC1             ADC1_2_EXTERNALTRIG_T4_CC4
/* 定时器5捕获比较通道3 */
#define ADC3_EXTERNALTRIG_T5_CC3             ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

/* ADC1、ADC2、ADC3规则组的外部触发源（如果有ADCx可用） */
/* 定时器1捕获比较通道3 */
#define ADC1_2_3_EXTERNALTRIG_T1_CC3         ((uint32_t)(                   ADC_CR2_EXTSEL_1                   ))
/* 软件触发 */
#define ADC1_2_3_SWSTART                     ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/**
  * @}
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Injected ADC Extended Internal HAL driver trigger selection for injected group
  * @{
  */
/* ADC1, ADC2, ADC3（如果选定设备上有ADC实例）注入组的外部触发源列表。*/
/* （由HAL驱动程序内部使用。不要在HAL结构参数中使用）*/

/* ADC1和ADC2注入组的外部触发源（如果有ADCx可用） */
/* 定时器2触发输出 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_TRGO          ((uint32_t)(                    ADC_CR2_JEXTSEL_1                    ))
/* 定时器2捕获比较通道1 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_CC1           ((uint32_t)(                    ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/* 定时器3捕获比较通道4 */
#define ADC1_2_EXTERNALTRIGINJEC_T3_CC4           ((uint32_t)(ADC_CR2_JEXTSEL_2                                        ))
/* 定时器4触发输出 */
#define ADC1_2_EXTERNALTRIGINJEC_T4_TRGO          ((uint32_t)(ADC_CR2_JEXTSEL_2 |                     ADC_CR2_JEXTSEL_0))
/* 外部中断线15 */
#define ADC1_2_EXTERNALTRIGINJEC_EXT_IT15         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1                    ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意：TIM8_CC4仅在超大容量和大容量设备的ADC1和ADC2上可用。*/
#define ADC1_2_EXTERNALTRIGINJEC_T8_CC4           ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3注入组的外部触发源 */
/* 定时器4捕获比较通道3 */
#define ADC3_EXTERNALTRIGINJEC_T4_CC3             ADC1_2_EXTERNALTRIGINJEC_T2_TRGO
/* 定时器8捕获比较通道2 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC2             ADC1_2_EXTERNALTRIGINJEC_T2_CC1
/* 定时器8捕获比较通道4 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC4             ADC1_2_EXTERNALTRIGINJEC_T3_CC4
/* 定时器5触发输出 */
#define ADC3_EXTERNALTRIGINJEC_T5_TRGO            ADC1_2_EXTERNALTRIGINJEC_T4_TRGO
/* 定时器5捕获比较通道4 */
#define ADC3_EXTERNALTRIGINJEC_T5_CC4             ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif /* STM32F103xE || defined STM32F103xG */

/* ADC1、ADC2、ADC3注入组的外部触发源（如果有ADCx可用） */
/* 定时器1触发输出 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO                    0x00000000U
/* 定时器1捕获比较通道4 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4         ((uint32_t)(                                        ADC_CR2_JEXTSEL_0))
/* 注入组软件触发 */
#define ADC1_2_3_JSWSTART                         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/* 导出宏定义 ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* 私有宏定义 -------------------------------------------------------------*/

/** @defgroup ADCEx_Private_Macro ADCEx Private Macro
  * @{
  */
/* 宏保留供HAL驱动程序内部使用，不打算在最终用户的代码中使用。*/

    
/**
  * @brief 对于具有3个ADC的设备：根据公共组ADC1和ADC2或ADC3中的ADC定义规则组的外部触发源
  *        （某些具有相同源的触发器在CR2寄存器的ADC EXTSEL位中具有不同的编程值）。
  *        对于具有2个或更少ADC的设备：此宏不进行任何更改。
  * @param __HANDLE__: ADC句柄
  * @param __EXT_TRIG_CONV__: 为规则组选择的外部触发源。
  * @retval 要编程到CR2寄存器EXTSEL位的外部触发源值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：配置规则组外部触发源 (ADC_CFGR_EXTSEL) */
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
/* 非大容量设备，直接返回传入的触发源 */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
  (__EXT_TRIG_CONV__)
#endif /* STM32F103xE || STM32F103xG */

/**
  * @brief 对于具有3个ADC的设备：根据公共组ADC1和ADC2或ADC3中的ADC定义注入组的外部触发源
  *        （某些具有相同源的触发器在CR2寄存器的ADC JEXTSEL位中具有不同的编程值）。
  *        对于具有2个或更少ADC的设备：此宏不进行任何更改。
  * @param __HANDLE__: ADC句柄
  * @param __EXT_TRIG_INJECTCONV__: 为注入组选择的外部触发源。
  * @retval 要编程到CR2寄存器JEXTSEL位的外部触发源值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：配置注入组外部触发源 (ADC_CFGR_JEXTSEL) */
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
/* 非大容量设备，直接返回传入的触发源 */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
   (__EXT_TRIG_INJECTCONV__)
#endif /* STM32F103xE || STM32F103xG */


/**
  * @brief 验证所选ADC（多模ADC主设备或ADC从设备）是否启用了多模模式（适用于具有多个ADC的设备）
  * @param __HANDLE__: ADC句柄
  * @retval 多模状态：如果禁用多模则为RESET，如果启用多模则为其他值
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：检查多模模式是否使能 (ADC_MULTIMODE_IS_ENABLE) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
 (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)   \
  )?                                                                           \
   (ADC1->CR1 & ADC_CR1_DUALMOD)                                               \
   :                                                                           \
   (RESET)                                                                     \
 )
#else
/* 不支持多模的设备，直接返回RESET */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief ADC启动转换的条件验证：ADC必须处于非多模模式，或者处于多模模式但使用的是ADC主设备的句柄（适用于具有多个ADC的设备）
  * @param __HANDLE__: ADC句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined STM32F103xG)
/* 宏定义：检查是否为非多模模式或多模主模式 (ADC_NONMULTIMODE_OR_MULTIMODEMASTER) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (( (((__HANDLE__)->Instance) == ADC2)                                        \
   )?                                                                          \
    ((ADC1->CR1 & ADC_CR1_DUALMOD) == RESET)                                   \
    :                                                                          \
    (!RESET)                                                                   \
  )
#else
/* 不支持多模的设备，直接返回!RESET (真) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (!RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief 检查ADC多模设置：在多模模式下，检查所选ADC的ADC主设备是否启用了自动注入功能（适用于具有多个ADC的设备）
  * @param __HANDLE__: ADC句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：检查多模自动注入模式 (ADC_MULTIMODE_AUTO_INJECTED) */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)  \
   )?                                                                          \
    (ADC1->CR1 & ADC_CR1_JAUTO)                                                \
    :                                                                          \
    (RESET)                                                                    \
  )
#else
/* 不支持多模的设备，直接返回RESET */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief 设置共享公共多模设置的其他ADC的句柄
  * @param __HANDLE__: ADC句柄
  * @param __HANDLE_OTHER_ADC__: 其他ADC句柄
  * @retval 无
  */
/* 宏定义：设置共享多模设置的另一个ADC句柄 (ADC_COMMON_ADC_OTHER) */
#define ADC_COMMON_ADC_OTHER(__HANDLE__, __HANDLE_OTHER_ADC__)                 \
  ((__HANDLE_OTHER_ADC__)->Instance = ADC2)

/**
  * @brief 设置与ADC主设备关联的ADC从设备的句柄
  * 在STM32F1设备上，ADC从设备始终为ADC2（在其他STM32设备上可能不同）
  * @param __HANDLE_MASTER__: ADC主设备句柄
  * @param __HANDLE_SLAVE__: ADC从设备句柄
  * @retval 无
  */
/* 宏定义：设置多模从ADC句柄 (ADC_MULTI_SLAVE) */
#define ADC_MULTI_SLAVE(__HANDLE_MASTER__, __HANDLE_SLAVE__)                   \
  ((__HANDLE_SLAVE__)->Instance = ADC2)
       
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* 宏定义：检查注入通道排名是否有效 */
#define IS_ADC_INJECTED_RANK(CHANNEL) (((CHANNEL) == ADC_INJECTED_RANK_1) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_2) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_3) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_4))

/* 宏定义：检查注入组外部触发边沿是否有效 */
#define IS_ADC_EXTTRIGINJEC_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)  || \
                                        ((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING))

/** @defgroup ADCEx_injected_nb_conv_verification ADCEx injected nb conv verification
  * @{
  */
/* 宏定义：检查注入组转换数量是否在1到4之间 */
#define IS_ADC_INJECTED_NB_CONV(LENGTH)  (((LENGTH) >= 1U) && ((LENGTH) <= 4U))
/**
  * @}
  */
