/** @defgroup ADC_LL_EC_INJ_SEQ_SCAN_LENGTH  ADC注入组 - 序列扫描长度
  * @{
  */
#define LL_ADC_INJ_SEQ_SCAN_DISABLE        0x00000000U                     // 禁止ADC注入组序列扫描（等同于单通道转换：仅转换1个通道）
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS  (                ADC_JSQR_JL_0) // ADC注入组序列扫描使能，序列长度为2
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS  (ADC_JSQR_JL_1                ) // ADC注入组序列扫描使能，序列长度为3
#define LL_ADC_INJ_SEQ_SCAN_ENABLE_4RANKS  (ADC_JSQR_JL_1 | ADC_JSQR_JL_0) // ADC注入组序列扫描使能，序列长度为4
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_DISCONT_MODE  ADC注入组 - 序列间断模式
  * @{
  */
#define LL_ADC_INJ_SEQ_DISCONT_DISABLE     0x00000000U            // 禁止ADC注入组序列间断模式
#define LL_ADC_INJ_SEQ_DISCONT_1RANK       (ADC_CR1_JDISCEN)      // 使能ADC注入组序列间断模式，每次触发转换序列中的一个通道
/**
  * @}
  */

/** @defgroup ADC_LL_EC_INJ_SEQ_RANKS  ADC注入组 - 序列排名
  * @{
  */
// 定义注入组的转换序列排名，包含数据寄存器偏移、偏移寄存器偏移和排名序号
#define LL_ADC_INJ_RANK_1                  (ADC_JDR1_REGOFFSET | ADC_JOFR1_REGOFFSET | 0x00000001U) // 注入组序列排名1
#define LL_ADC_INJ_RANK_2                  (ADC_JDR2_REGOFFSET | ADC_JOFR2_REGOFFSET | 0x00000002U) // 注入组序列排名2
#define LL_ADC_INJ_RANK_3                  (ADC_JDR3_REGOFFSET | ADC_JOFR3_REGOFFSET | 0x00000003U) // 注入组序列排名3
#define LL_ADC_INJ_RANK_4                  (ADC_JDR4_REGOFFSET | ADC_JOFR4_REGOFFSET | 0x00000004U) // 注入组序列排名4
/**
  * @}
  */

/** @defgroup ADC_LL_EC_CHANNEL_SAMPLINGTIME  通道 - 采样时间
  * @{
  */
// 定义ADC通道的采样时间，采样时间越长，输入阻抗匹配效果越好，但转换速度越慢
#define LL_ADC_SAMPLINGTIME_1CYCLE_5       0x00000000U                                              // 采样时间：1.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_7CYCLES_5      (ADC_SMPR2_SMP0_0)                                       // 采样时间：7.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_13CYCLES_5     (ADC_SMPR2_SMP0_1)                                       // 采样时间：13.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_28CYCLES_5     (ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0)                    // 采样时间：28.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_41CYCLES_5     (ADC_SMPR2_SMP0_2)                                       // 采样时间：41.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_55CYCLES_5     (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_0)                    // 采样时间：55.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_71CYCLES_5     (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1)                    // 采样时间：71.5个ADC时钟周期
#define LL_ADC_SAMPLINGTIME_239CYCLES_5    (ADC_SMPR2_SMP0_2 | ADC_SMPR2_SMP0_1 | ADC_SMPR2_SMP0_0) // 采样时间：239.5个ADC时钟周期
/**
  * @}
  */

/** @defgroup ADC_LL_EC_AWD_NUMBER 模拟看门狗 - 模拟看门狗编号
  * @{
  */
// 定义模拟看门狗编号，用于监控ADC转换结果是否超出设定阈值
#define LL_ADC_AWD1                        (ADC_AWD_CR1_CHANNEL_MASK  | ADC_AWD_CR1_REGOFFSET) // ADC模拟看门狗编号1
/**
  * @}
  */
