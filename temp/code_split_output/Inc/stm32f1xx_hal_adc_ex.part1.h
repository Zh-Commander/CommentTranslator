#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** @defgroup ADCEx_Common_mode ADC 扩展双 ADC 模式
  * @{
  */
/* ADC 独立模式，即双 ADC 模式禁用，ADC1 和 ADC2 独立工作 */
#define ADC_MODE_INDEPENDENT                              0x00000000U                                                                     
/* ADC 双模式：规则同步 + 注入同步模式，适用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_INJECSIMULT    ((uint32_t)(                                                            ADC_CR1_DUALMOD_0)) 
/* ADC 双模式：规则同步 + 交替触发模式，适用于规则组和注入组 */
#define ADC_DUALMODE_REGSIMULT_ALTERTRIG      ((uint32_t)(                                        ADC_CR1_DUALMOD_1                    )) 
/* ADC 双模式：注入同步 + 快速交错模式，适用于规则组和注入组（采样间隔：7个ADC时钟周期） */
#define ADC_DUALMODE_INJECSIMULT_INTERLFAST   ((uint32_t)(                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0)) 
/* ADC 双模式：注入同步 + 慢速交错模式，适用于规则组和注入组（采样间隔：14个ADC时钟周期） */
#define ADC_DUALMODE_INJECSIMULT_INTERLSLOW   ((uint32_t)(                    ADC_CR1_DUALMOD_2                                        )) 
/* ADC 双模式：注入同步模式，仅适用于注入组 */
#define ADC_DUALMODE_INJECSIMULT              ((uint32_t)(                    ADC_CR1_DUALMOD_2 |                     ADC_CR1_DUALMOD_0)) 
/* ADC 双模式：规则同步模式，仅适用于规则组 */
#define ADC_DUALMODE_REGSIMULT                ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    )) 
/* ADC 双模式：快速交错模式，仅适用于规则组（采样间隔：7个ADC时钟周期） */
#define ADC_DUALMODE_INTERLFAST               ((uint32_t)(                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0)) 
/* ADC 双模式：慢速交错模式，仅适用于规则组（采样间隔：14个ADC时钟周期） */
#define ADC_DUALMODE_INTERLSLOW               ((uint32_t)(ADC_CR1_DUALMOD_3                                                            )) 
/* ADC 双模式：交替触发模式，仅适用于注入组 */
#define ADC_DUALMODE_ALTERTRIG                ((uint32_t)(ADC_CR1_DUALMOD_3 |                                         ADC_CR1_DUALMOD_0)) 
/**
  * @}
  */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* Private constants ---------------------------------------------------------*/
/* 私有常量 -------------------------------------------------------------------*/

/** @addtogroup ADCEx_Private_Constants ADCEx 私有常量
  * @{
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Regular ADC 扩展内部 HAL 驱动规则组触发源选择
  * @{
  */
/* ADC1, ADC2, ADC3 (如果设备支持) 规则组的外部触发源列表 */
/* (仅供 HAL 驱动内部使用，不用于 HAL 结构体参数配置) */

/* ADC1 和 ADC2 规则组的外部触发源 (如果 ADCx 存在) */
/* 定时器1 CC1 事件触发 */
#define ADC1_2_EXTERNALTRIG_T1_CC1                       0x00000000U
/* 定时器1 CC2 事件触发 */
#define ADC1_2_EXTERNALTRIG_T1_CC2           ((uint32_t)(                                      ADC_CR2_EXTSEL_0))
/* 定时器2 CC2 事件触发 */
#define ADC1_2_EXTERNALTRIG_T2_CC2           ((uint32_t)(                   ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/* 定时器3 TRGO 事件触发 */
#define ADC1_2_EXTERNALTRIG_T3_TRGO          ((uint32_t)(ADC_CR2_EXTSEL_2                                      ))
/* 定时器4 CC4 事件触发 */
#define ADC1_2_EXTERNALTRIG_T4_CC4           ((uint32_t)(ADC_CR2_EXTSEL_2 |                    ADC_CR2_EXTSEL_0))
/* 外部中断线 11 触发 */
#define ADC1_2_EXTERNALTRIG_EXT_IT11         ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1                   ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意：TIM8_TRGO 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用 */
#define ADC1_2_EXTERNALTRIG_T8_TRGO          ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3 规则组的外部触发源 */
/* 定时器3 CC1 事件触发 */
#define ADC3_EXTERNALTRIG_T3_CC1             ADC1_2_EXTERNALTRIG_T1_CC1
/* 定时器2 CC3 事件触发 */
#define ADC3_EXTERNALTRIG_T2_CC3             ADC1_2_EXTERNALTRIG_T1_CC2
/* 定时器8 CC1 事件触发 */
#define ADC3_EXTERNALTRIG_T8_CC1             ADC1_2_EXTERNALTRIG_T2_CC2
/* 定时器8 TRGO 事件触发 */
#define ADC3_EXTERNALTRIG_T8_TRGO            ADC1_2_EXTERNALTRIG_T3_TRGO
/* 定时器5 CC1 事件触发 */
#define ADC3_EXTERNALTRIG_T5_CC1             ADC1_2_EXTERNALTRIG_T4_CC4
/* 定时器5 CC3 事件触发 */
#define ADC3_EXTERNALTRIG_T5_CC3             ADC1_2_EXTERNALTRIG_EXT_IT11
#endif

/* ADC1, ADC2, ADC3 规则组的外部触发源 (如果 ADCx 存在) */
/* 定时器1 CC3 事件触发 */
#define ADC1_2_3_EXTERNALTRIG_T1_CC3         ((uint32_t)(                   ADC_CR2_EXTSEL_1                   ))
/* 软件触发 */
#define ADC1_2_3_SWSTART                     ((uint32_t)(ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0))
/**
  * @}
  */

/** @defgroup ADCEx_Internal_HAL_driver_Ext_trig_src_Injected ADC 扩展内部 HAL 驱动注入组触发源选择
  * @{
  */
/* ADC1, ADC2, ADC3 (如果设备支持) 注入组的外部触发源列表 */
/* (仅供 HAL 驱动内部使用，不用于 HAL 结构体参数配置) */

/* ADC1 和 ADC2 注入组的外部触发源 (如果 ADCx 存在) */
/* 定时器2 TRGO 事件触发 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_TRGO          ((uint32_t)(                    ADC_CR2_JEXTSEL_1                    ))
/* 定时器2 CC1 事件触发 */
#define ADC1_2_EXTERNALTRIGINJEC_T2_CC1           ((uint32_t)(                    ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0))
/* 定时器3 CC4 事件触发 */
#define ADC1_2_EXTERNALTRIGINJEC_T3_CC4           ((uint32_t)(ADC_CR2_JEXTSEL_2                                        ))
/* 定时器4 TRGO 事件触发 */
#define ADC1_2_EXTERNALTRIGINJEC_T4_TRGO          ((uint32_t)(ADC_CR2_JEXTSEL_2 |                     ADC_CR2_JEXTSEL_0))
/* 外部中断线 15 触发 */
#define ADC1_2_EXTERNALTRIGINJEC_EXT_IT15         ((uint32_t)(ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1                    ))
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG)
/* 注意：TIM8_CC4 仅在大容量和超大容量设备的 ADC1 和 ADC2 上可用 */
#define ADC1_2_EXTERNALTRIGINJEC_T8_CC4           ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif

#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC3 注入组的外部触发源 */
/* 定时器4 CC3 事件触发 */
#define ADC3_EXTERNALTRIGINJEC_T4_CC3             ADC1_2_EXTERNALTRIGINJEC_T2_TRGO
/* 定时器8 CC2 事件触发 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC2             ADC1_2_EXTERNALTRIGINJEC_T2_CC1
/* 定时器8 CC4 事件触发 */
#define ADC3_EXTERNALTRIGINJEC_T8_CC4             ADC1_2_EXTERNALTRIGINJEC_T3_CC4
/* 定时器5 TRGO 事件触发 */
#define ADC3_EXTERNALTRIGINJEC_T5_TRGO            ADC1_2_EXTERNALTRIGINJEC_T4_TRGO
/* 定时器5 CC4 事件触发 */
#define ADC3_EXTERNALTRIGINJEC_T5_CC4             ADC1_2_EXTERNALTRIGINJEC_EXT_IT15
#endif /* STM32F103xE || defined STM32F103xG */

/* ADC1, ADC2, ADC3 注入组的外部触发源 (如果 ADCx 存在) */
/* 定时器1 TRGO 事件触发 */
#define ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO                    0x00000000U
/* 定时器1 CC4 事件触发 */
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
/* 导出宏 --------------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* 私有宏 --------------------------------------------------------------------*/

/** @defgroup ADCEx_Private_Macro ADCEx 私有宏
  * @{
  */
/* 宏仅供 HAL 驱动内部使用，最终用户代码中不打算使用 */

    
/**
  * @brief 对于有 3 个 ADC 的设备：根据 ADC 所属组 (ADC1&ADC2 或 ADC3) 定义规则组的外部触发源
  *        (某些具有相同源的触发器在 CR2 寄存器的 EXTSEL 位中需要写入不同的值)。
  *        对于有 2 个或更少 ADC 的设备：此宏不做任何更改。
  * @param __HANDLE__: ADC 句柄
  * @param __EXT_TRIG_CONV__: 为规则组选择的外部触发源
  * @retval 需要写入 CR2 寄存器 EXTSEL 位的外部触发值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：配置规则组外部触发源 (ADC3 与 ADC1/2 部分触发源不同) */
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
/* 宏定义：配置规则组外部触发源 (非大容量设备，直接返回传入值) */
#define ADC_CFGR_EXTSEL(__HANDLE__, __EXT_TRIG_CONV__)                         \
  (__EXT_TRIG_CONV__)
#endif /* STM32F103xE || STM32F103xG */

/**
  * @brief 对于有 3 个 ADC 的设备：根据 ADC 所属组 (ADC1&ADC2 或 ADC3) 定义注入组的外部触发源
  *        (某些具有相同源的触发器在 CR2 寄存器的 JEXTSEL 位中需要写入不同的值)。
  *        对于有 2 个或更少 ADC 的设备：此宏不做任何更改。
  * @param __HANDLE__: ADC 句柄
  * @param __EXT_TRIG_INJECTCONV__: 为注入组选择的外部触发源
  * @retval 需要写入 CR2 寄存器 JEXTSEL 位的外部触发值
  */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：配置注入组外部触发源 (ADC3 与 ADC1/2 部分触发源不同) */
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
/* 宏定义：配置注入组外部触发源 (非大容量设备，直接返回传入值) */
#define ADC_CFGR_JEXTSEL(__HANDLE__, __EXT_TRIG_INJECTCONV__)                  \
   (__EXT_TRIG_INJECTCONV__)
#endif /* STM32F103xE || STM32F103xG */


/**
  * @brief 验证所选 ADC 的多模模式是否启用 (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 多模状态：如果多模禁用则为 RESET，如果多模启用则为其他值
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：检查多模模式是否使能 (读取 ADC1 CR1 寄存器的 DUALMOD 位) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
 (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)   \
  )?                                                                           \
   (ADC1->CR1 & ADC_CR1_DUALMOD)                                               \
   :                                                                           \
   (RESET)                                                                     \
 )
#else
/* 宏定义：检查多模模式是否使能 (单 ADC 设备，始终返回 RESET) */
#define ADC_MULTIMODE_IS_ENABLE(__HANDLE__)                                    \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief 验证 ADC 启动转换的条件：ADC 必须处于非多模模式，或者处于多模模式且句柄为主 ADC (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：检查是否为非多模模式或多模模式下的主 ADC */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (( (((__HANDLE__)->Instance) == ADC2)                                        \
   )?                                                                          \
    ((ADC1->CR1 & ADC_CR1_DUALMOD) == RESET)                                   \
    :                                                                          \
    (!RESET)                                                                   \
  )
#else
/* 宏定义：检查是否为非多模模式或多模模式下的主 ADC (单 ADC 设备) */
#define ADC_NONMULTIMODE_OR_MULTIMODEMASTER(__HANDLE__)                        \
  (!RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief 检查 ADC 多模设置：在多模模式下，检查所选 ADC 的主 ADC 是否启用了自动注入功能 (适用于具有多个 ADC 的设备)
  * @param __HANDLE__: ADC 句柄
  * @retval 无
  */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 宏定义：检查多模模式下自动注入是否使能 */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (( (((__HANDLE__)->Instance) == ADC1) || (((__HANDLE__)->Instance) == ADC2)  \
   )?                                                                          \
    (ADC1->CR1 & ADC_CR1_JAUTO)                                                \
    :                                                                          \
    (RESET)                                                                    \
  )
#else
/* 宏定义：检查多模模式下自动注入是否使能 (单 ADC 设备) */
#define ADC_MULTIMODE_AUTO_INJECTED(__HANDLE__)                                \
  (RESET)
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief 设置共享公共多模设置的另一个 ADC 的句柄
  * @param __HANDLE__: ADC 句柄
  * @param __HANDLE_OTHER_ADC__: 另一个 ADC 句柄
  * @retval 无
  */
/* 宏定义：获取另一个 ADC 的句柄 (固定为 ADC2) */
#define ADC_COMMON_ADC_OTHER(__HANDLE__, __HANDLE_OTHER_ADC__)                 \
  ((__HANDLE_OTHER_ADC__)->Instance = ADC2)

/**
  * @brief 设置与主 ADC 关联的从 ADC 句柄
  * 在 STM32F1 设备上，从 ADC 始终为 ADC2 (在其他 STM32 设备上可能不同)
  * @param __HANDLE_MASTER__: 主 ADC 句柄
  * @param __HANDLE_SLAVE__: 从 ADC 句柄
  * @retval 无
  */
/* 宏定义：设置从 ADC 句柄 (固定为 ADC2) */
#define ADC_MULTI_SLAVE(__HANDLE_MASTER__, __HANDLE_SLAVE__)                   \
  ((__HANDLE_SLAVE__)->Instance = ADC2)
       
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* 宏定义：检查注入通道排名参数是否有效 (排名范围 1-4) */
#define IS_ADC_INJECTED_RANK(CHANNEL) (((CHANNEL) == ADC_INJECTED_RANK_1) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_2) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_3) || \
                                       ((CHANNEL) == ADC_INJECTED_RANK_4))

/* 宏定义：检查注入组外部触发边沿参数是否有效 (无触发或上升沿) */
#define IS_ADC_EXTTRIGINJEC_EDGE(EDGE) (((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_NONE)  || \
                                        ((EDGE) == ADC_EXTERNALTRIGINJECCONV_EDGE_RISING))

/** @defgroup ADCEx_injected_nb_conv_verification ADCEx 注入组转换次数验证
  * @{
  */
/* 宏定义：检查注入组转换次数参数是否有效 (范围 1-4) */
#define IS_ADC_INJECTED_NB_CONV(LENGTH)  (((LENGTH) >= 1U) && ((LENGTH) <= 4U))
/**
  * @}
  */
