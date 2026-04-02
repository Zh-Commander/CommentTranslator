/** @defgroup ADC_LL_EC_REG_TRIGGER_SOURCE  ADC 规则组 - 触发源
  * @{
  */
/* ADC 规则组外部触发源，适用于 ADC 实例: ADC1, ADC2, ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_REG_TRIG_SOFTWARE           (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0) /*!< ADC 规则组转换触发源为内部：软件启动 (SW start)。 */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH3       (ADC_CR2_EXTSEL_1)                                       /*!< ADC 规则组转换触发源来自外部 IP：TIM1 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
/* ADC 规则组外部触发源，适用于 ADC 实例: ADC1, ADC2 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH1       0x00000000U                                              /*!< ADC 规则组转换触发源来自外部 IP：TIM1 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM1_CH2       (ADC_CR2_EXTSEL_0)                                       /*!< ADC 规则组转换触发源来自外部 IP：TIM1 通道 2 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM2_CH2       (ADC_CR2_EXTSEL_1 | ADC_CR2_EXTSEL_0)                    /*!< ADC 规则组转换触发源来自外部 IP：TIM2 通道 2 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM3_TRGO      (ADC_CR2_EXTSEL_2)                                       /*!< ADC 规则组转换触发源来自外部 IP：TIM3 TRGO 事件。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM4_CH4       (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_0)                    /*!< ADC 规则组转换触发源来自外部 IP：TIM4 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_EXTI_LINE11    (ADC_CR2_EXTSEL_2 | ADC_CR2_EXTSEL_1)                    /*!< ADC 规则组转换触发源来自外部 IP：外部中断线 11。触发边沿设置为上升沿 (默认设置)。 */
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/* 注意: TIM8_TRGO 仅在大容量 (High-density) 和超大容量 (XL-density) 设备的 ADC1 和 ADC2 上可用。 */
/* 注意: 要在 ADC1 或 ADC2 上使用 TIM8_TRGO，必须进行触发重映射。                           */
/*       触发重映射必须在顶层完成 (请参考 AFIO 外设)。                                      */
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO      (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                        /*!< ADC 规则组转换触发源来自外部 IP：TIM8 TRGO。触发边沿设置为上升沿 (默认设置)。仅在大容量和超大容量设备上可用。触发重映射必须在顶层完成 (请参考 AFIO 外设)。*/
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC 规则组外部触发源，适用于 ADC 实例: ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_REG_TRIG_EXT_TIM3_CH1       (LL_ADC_REG_TRIG_EXT_TIM1_CH1)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM3 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM2_CH3       (LL_ADC_REG_TRIG_EXT_TIM1_CH2)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM2 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM8_CH1       (LL_ADC_REG_TRIG_EXT_TIM2_CH2)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM8 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM8_TRGO_ADC3 (LL_ADC_REG_TRIG_EXT_TIM3_TRGO)                          /*!< ADC 规则组转换触发源来自外部 IP：TIM8 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM5_CH1       (LL_ADC_REG_TRIG_EXT_TIM4_CH4)                           /*!< ADC 规则组转换触发源来自外部 IP：TIM5 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_REG_TRIG_EXT_TIM5_CH3       (LL_ADC_REG_TRIG_EXT_EXTI_LINE11)                        /*!< ADC 规则组转换触发源来自外部 IP：TIM5 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_TRIGGER_EDGE  ADC 规则组 - 触发边沿
  * @{
  */
#define LL_ADC_REG_TRIG_EXT_RISING         ADC_CR2_EXTTRIG                         /*!< ADC 规则组转换触发极性设置为上升沿 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_CONTINUOUS_MODE  ADC 规则组 - 连续转换模式
* @{
*/
#define LL_ADC_REG_CONV_SINGLE             0x00000000U             /*!< ADC 转换在单次模式下执行：每次触发执行一次转换 */
#define LL_ADC_REG_CONV_CONTINUOUS         (ADC_CR2_CONT)          /*!< ADC 转换在连续模式下执行：在第一次触发后，后续转换自动连续启动 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_DMA_TRANSFER  ADC 规则组 - ADC 转换数据的 DMA 传输
  * @{
  */
#define LL_ADC_REG_DMA_TRANSFER_NONE       0x00000000U              /*!< ADC 转换结果不通过 DMA 传输 */
#define LL_ADC_REG_DMA_TRANSFER_UNLIMITED  (ADC_CR2_DMA)                        /*!< ADC 转换数据通过 DMA 传输，无限模式：无论传输了多少 DMA 数据 (ADC 转换次数)，DMA 传输请求都是无限的。此 ADC 模式旨在配合 DMA 循环模式使用。 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_SCAN_LENGTH  ADC 规则组 - 扫描序列长度
  * @{
  */
#define LL_ADC_REG_SEQ_SCAN_DISABLE        0x00000000U                                                 /*!< ADC 规则组扫描序列禁用 (相当于序列长度为 1：ADC 仅转换 1 个通道) */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_2RANKS  (                                             ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 2 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_3RANKS  (                              ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 3 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_4RANKS  (                              ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 4 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_5RANKS  (               ADC_SQR1_L_2                              ) /*!< ADC 规则组扫描序列使能，序列中包含 5 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_6RANKS  (               ADC_SQR1_L_2                | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 6 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_7RANKS  (               ADC_SQR1_L_2 | ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 7 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_8RANKS  (               ADC_SQR1_L_2 | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 8 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_9RANKS  (ADC_SQR1_L_3                                             ) /*!< ADC 规则组扫描序列使能，序列中包含 9 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_10RANKS (ADC_SQR1_L_3                               | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 10 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_11RANKS (ADC_SQR1_L_3                | ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 11 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_12RANKS (ADC_SQR1_L_3                | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 12 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_13RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2                              ) /*!< ADC 规则组扫描序列使能，序列中包含 13 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_14RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2                | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 14 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_15RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 | ADC_SQR1_L_1               ) /*!< ADC 规则组扫描序列使能，序列中包含 15 个通道 */
#define LL_ADC_REG_SEQ_SCAN_ENABLE_16RANKS (ADC_SQR1_L_3 | ADC_SQR1_L_2 | ADC_SQR1_L_1 | ADC_SQR1_L_0) /*!< ADC 规则组扫描序列使能，序列中包含 16 个通道 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_DISCONT_MODE  ADC 规则组 - 序列间断模式
  * @{
  */
#define LL_ADC_REG_SEQ_DISCONT_DISABLE     0x00000000U                                                                  /*!< ADC 规则组序列间断模式禁用 */
#define LL_ADC_REG_SEQ_DISCONT_1RANK       (                                                            ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 1 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_2RANKS      (                                        ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 2 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_3RANKS      (                    ADC_CR1_DISCNUM_1                     | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 3 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_4RANKS      (                    ADC_CR1_DISCNUM_1 | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 4 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_5RANKS      (ADC_CR1_DISCNUM_2                                         | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 5 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_6RANKS      (ADC_CR1_DISCNUM_2                     | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 6 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_7RANKS      (ADC_CR1_DISCNUM_2 | ADC_CR1_DISCNUM_1                     | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 7 个通道 */
#define LL_ADC_REG_SEQ_DISCONT_8RANKS      (ADC_CR1_DISCNUM_2 | ADC_CR1_DISCNUM_1 | ADC_CR1_DISCNUM_0 | ADC_CR1_DISCEN) /*!< ADC 规则组序列间断模式使能，每次触发转换序列中的 8 个通道 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_REG_SEQ_RANKS  ADC 规则组 - 序列排名
  * @{
  */
#define LL_ADC_REG_RANK_1                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_1_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 1 */
#define LL_ADC_REG_RANK_2                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_2_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 2 */
#define LL_ADC_REG_RANK_3                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_3_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 3 */
#define LL_ADC_REG_RANK_4                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_4_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 4 */
#define LL_ADC_REG_RANK_5                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_5_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 5 */
#define LL_ADC_REG_RANK_6                  (ADC_SQR3_REGOFFSET | ADC_REG_RANK_6_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 6 */
#define LL_ADC_REG_RANK_7                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_7_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 7 */
#define LL_ADC_REG_RANK_8                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_8_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 8 */
#define LL_ADC_REG_RANK_9                  (ADC_SQR2_REGOFFSET | ADC_REG_RANK_9_SQRX_BITOFFSET_POS)  /*!< ADC 规则组序列排名 9 */
#define LL_ADC_REG_RANK_10                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_10_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 10 */
#define LL_ADC_REG_RANK_11                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_11_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 11 */
#define LL_ADC_REG_RANK_12                 (ADC_SQR2_REGOFFSET | ADC_REG_RANK_12_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 12 */
#define LL_ADC_REG_RANK_13                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_13_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 13 */
#define LL_ADC_REG_RANK_14                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_14_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 14 */
#define LL_ADC_REG_RANK_15                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_15_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 15 */
#define LL_ADC_REG_RANK_16                 (ADC_SQR1_REGOFFSET | ADC_REG_RANK_16_SQRX_BITOFFSET_POS) /*!< ADC 规则组序列排名 16 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIGGER_SOURCE  ADC 注入组 - 触发源
  * @{
  */
/* ADC 注入组外部触发源，适用于 ADC 实例: ADC1, ADC2, ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_INJ_TRIG_SOFTWARE           (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0) /*!< ADC 注入组转换触发源为内部：软件启动 (SW start)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM1_TRGO      0x00000000U                                                 /*!< ADC 注入组转换触发源来自外部 IP：TIM1 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM1_CH4       (ADC_CR2_JEXTSEL_0)                                         /*!< ADC 注入组转换触发源来自外部 IP：TIM1 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
/* ADC 注入组外部触发源，适用于 ADC 实例: ADC1, ADC2 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_INJ_TRIG_EXT_TIM2_TRGO      (ADC_CR2_JEXTSEL_1)                                         /*!< ADC 注入组转换触发源来自外部 IP：TIM2 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM2_CH1       (ADC_CR2_JEXTSEL_1 | ADC_CR2_JEXTSEL_0)                     /*!< ADC 注入组转换触发源来自外部 IP：TIM2 通道 1 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM3_CH4       (ADC_CR2_JEXTSEL_2)                                         /*!< ADC 注入组转换触发源来自外部 IP：TIM3 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM4_TRGO      (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_0)                     /*!< ADC 注入组转换触发源来自外部 IP：TIM4 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_EXTI_LINE15    (ADC_CR2_JEXTSEL_2 | ADC_CR2_JEXTSEL_1)                     /*!< ADC 注入组转换触发源来自外部 IP：外部中断线 15。触发边沿设置为上升沿 (默认设置)。 */
#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/* 注意: TIM8_CH4 仅在大容量 和超大容量 设备的 ADC1 和 ADC2 上可用。    */
/* 注意: 要在 ADC1 或 ADC2 上使用 TIM8_TRGO，必须进行触发重映射。               */
/*       触发重映射必须在顶层完成 (请参考 AFIO 外设)。                          */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4        (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                          /*!< ADC 注入组转换触发源来自外部 IP：TIM8 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。仅在大容量和超大容量设备上可用。触发重映射必须在顶层完成 (请参考 AFIO 外设)。 */
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */
#if defined (STM32F103xE) || defined (STM32F103xG)
/* ADC 注入组外部触发源，适用于 ADC 实例: ADC3 (具体取决于所选设备上可用的 ADCx) */
#define LL_ADC_INJ_TRIG_EXT_TIM4_CH3        (LL_ADC_INJ_TRIG_EXT_TIM2_TRGO)                            /*!< ADC 注入组转换触发源来自外部 IP：TIM4 通道 3 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH2        (LL_ADC_INJ_TRIG_EXT_TIM2_CH1)                             /*!< ADC 注入组转换触发源来自外部 IP：TIM8 通道 2 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM8_CH4_ADC3   (LL_ADC_INJ_TRIG_EXT_TIM3_CH4)                             /*!< ADC 注入组转换触发源来自外部 IP：TIM8 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM5_TRGO       (LL_ADC_INJ_TRIG_EXT_TIM4_TRGO)                            /*!< ADC 注入组转换触发源来自外部 IP：TIM5 TRGO。触发边沿设置为上升沿 (默认设置)。 */
#define LL_ADC_INJ_TRIG_EXT_TIM5_CH4        (LL_ADC_INJ_TRIG_EXT_EXTI_LINE15)                          /*!< ADC 注入组转换触发源来自外部 IP：TIM5 通道 4 事件 (捕获比较：输入捕获或输出捕获)。触发边沿设置为上升沿 (默认设置)。 */
#endif
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIGGER_EDGE  ADC 注入组 - 触发边沿
  * @{
  */
#define LL_ADC_INJ_TRIG_EXT_RISING         ADC_CR2_JEXTTRIG                        /*!< ADC 注入组转换触发极性设置为上升沿 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_TRIG_AUTO  ADC 注入组 - 自动触发模式
* @{
*/
#define LL_ADC_INJ_TRIG_INDEPENDENT        0x00000000U            /*!< ADC 注入组转换触发独立模式。如果 ADC 注入组触发源设置为外部触发，则必须使用此设置。 */
#define LL_ADC_INJ_TRIG_FROM_GRP_REGULAR   (ADC_CR1_JAUTO)        /*!< ADC 注入组转换触发来自 ADC 规则组。仅适用于注入组触发源设置为软件启动的情况，无需对 ADC 注入组转换启动或停止进行任何进一步操作：在这种情况下，ADC 注入组仅受 ADC 规则组控制。 */
/**
  * @}
  */

