/** @defgroup ADC_LL_EC_AWD_CHANNELS  模拟看门狗 - 监控通道
  * @{
  */

/* 模拟看门狗监控禁用 */
#define LL_ADC_AWD_DISABLE                 0x00000000U                                                                                   /*!< ADC模拟看门狗监控禁用 */

/* 监控所有通道：仅限常规通道组 */
#define LL_ADC_AWD_ALL_CHANNELS_REG        (                                                             ADC_CR1_AWDEN                 ) /*!< ADC模拟看门狗监控所有通道，仅限常规通道组转换 */

/* 监控所有通道：仅限注入通道组 */
#define LL_ADC_AWD_ALL_CHANNELS_INJ        (                                            ADC_CR1_JAWDEN                                 ) /*!< ADC模拟看门狗监控所有通道，仅限注入通道组转换 */

/* 监控所有通道：常规通道组或注入通道组 */
#define LL_ADC_AWD_ALL_CHANNELS_REG_INJ    (                                            ADC_CR1_JAWDEN | ADC_CR1_AWDEN                 ) /*!< ADC模拟看门狗监控所有通道，常规通道组或注入通道组转换均可 */

/* 监控通道0：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_0_REG           ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN0，仅限常规通道组转换 */

/* 监控通道0：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_0_INJ           ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN0，仅限注入通道组转换 */

/* 监控通道0：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_0_REG_INJ       ((LL_ADC_CHANNEL_0  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN0，常规通道组或注入通道组转换均可 */

/* 监控通道1：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_1_REG           ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN1，仅限常规通道组转换 */

/* 监控通道1：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_1_INJ           ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN1，仅限注入通道组转换 */

/* 监控通道1：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_1_REG_INJ       ((LL_ADC_CHANNEL_1  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN1，常规通道组或注入通道组转换均可 */

/* 监控通道2：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_2_REG           ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN2，仅限常规通道组转换 */

/* 监控通道2：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_2_INJ           ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN2，仅限注入通道组转换 */

/* 监控通道2：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_2_REG_INJ       ((LL_ADC_CHANNEL_2  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN2，常规通道组或注入通道组转换均可 */

/* 监控通道3：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_3_REG           ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN3，仅限常规通道组转换 */

/* 监控通道3：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_3_INJ           ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN3，仅限注入通道组转换 */

/* 监控通道3：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_3_REG_INJ       ((LL_ADC_CHANNEL_3  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN3，常规通道组或注入通道组转换均可 */

/* 监控通道4：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_4_REG           ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN4，仅限常规通道组转换 */

/* 监控通道4：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_4_INJ           ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN4，仅限注入通道组转换 */

/* 监控通道4：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_4_REG_INJ       ((LL_ADC_CHANNEL_4  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN4，常规通道组或注入通道组转换均可 */

/* 监控通道5：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_5_REG           ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN5，仅限常规通道组转换 */

/* 监控通道5：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_5_INJ           ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN5，仅限注入通道组转换 */

/* 监控通道5：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_5_REG_INJ       ((LL_ADC_CHANNEL_5  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN5，常规通道组或注入通道组转换均可 */

/* 监控通道6：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_6_REG           ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN6，仅限常规通道组转换 */

/* 监控通道6：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_6_INJ           ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN6，仅限注入通道组转换 */

/* 监控通道6：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_6_REG_INJ       ((LL_ADC_CHANNEL_6  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN6，常规通道组或注入通道组转换均可 */

/* 监控通道7：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_7_REG           ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN7，仅限常规通道组转换 */

/* 监控通道7：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_7_INJ           ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN7，仅限注入通道组转换 */

/* 监控通道7：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_7_REG_INJ       ((LL_ADC_CHANNEL_7  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN7，常规通道组或注入通道组转换均可 */

/* 监控通道8：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_8_REG           ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN8，仅限常规通道组转换 */

/* 监控通道8：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_8_INJ           ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN8，仅限注入通道组转换 */

/* 监控通道8：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_8_REG_INJ       ((LL_ADC_CHANNEL_8  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN8，常规通道组或注入通道组转换均可 */

/* 监控通道9：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_9_REG           ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN9，仅限常规通道组转换 */

/* 监控通道9：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_9_INJ           ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN9，仅限注入通道组转换 */

/* 监控通道9：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_9_REG_INJ       ((LL_ADC_CHANNEL_9  & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN9，常规通道组或注入通道组转换均可 */

/* 监控通道10：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_10_REG          ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN10，仅限常规通道组转换 */

/* 监控通道10：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_10_INJ          ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN10，仅限注入通道组转换 */

/* 监控通道10：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_10_REG_INJ      ((LL_ADC_CHANNEL_10 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN10，常规通道组或注入通道组转换均可 */

/* 监控通道11：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_11_REG          ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN11，仅限常规通道组转换 */

/* 监控通道11：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_11_INJ          ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN11，仅限注入通道组转换 */

/* 监控通道11：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_11_REG_INJ      ((LL_ADC_CHANNEL_11 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN11，常规通道组或注入通道组转换均可 */

/* 监控通道12：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_12_REG          ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN12，仅限常规通道组转换 */

/* 监控通道12：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_12_INJ          ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN12，仅限注入通道组转换 */

/* 监控通道12：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_12_REG_INJ      ((LL_ADC_CHANNEL_12 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN12，常规通道组或注入通道组转换均可 */

/* 监控通道13：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_13_REG          ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN13，仅限常规通道组转换 */

/* 监控通道13：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_13_INJ          ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN13，仅限注入通道组转换 */

/* 监控通道13：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_13_REG_INJ      ((LL_ADC_CHANNEL_13 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN13，常规通道组或注入通道组转换均可 */

/* 监控通道14：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_14_REG          ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN14，仅限常规通道组转换 */

/* 监控通道14：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_14_INJ          ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN14，仅限注入通道组转换 */

/* 监控通道14：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_14_REG_INJ      ((LL_ADC_CHANNEL_14 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN14，常规通道组或注入通道组转换均可 */

/* 监控通道15：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_15_REG          ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN15，仅限常规通道组转换 */

/* 监控通道15：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_15_INJ          ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN15，仅限注入通道组转换 */

/* 监控通道15：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_15_REG_INJ      ((LL_ADC_CHANNEL_15 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN15，常规通道组或注入通道组转换均可 */

/* 监控通道16：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_16_REG          ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN16，仅限常规通道组转换 */

/* 监控通道16：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_16_INJ          ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN16，仅限注入通道组转换 */

/* 监控通道16：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_16_REG_INJ      ((LL_ADC_CHANNEL_16 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN16，常规通道组或注入通道组转换均可 */

/* 监控通道17：仅限常规通道组 */
#define LL_ADC_AWD_CHANNEL_17_REG          ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN17，仅限常规通道组转换 */

/* 监控通道17：仅限注入通道组 */
#define LL_ADC_AWD_CHANNEL_17_INJ          ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN17，仅限注入通道组转换 */

/* 监控通道17：常规通道组或注入通道组 */
#define LL_ADC_AWD_CHANNEL_17_REG_INJ      ((LL_ADC_CHANNEL_17 & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC外部通道(连接到GPIO引脚)ADCx_IN17，常规通道组或注入通道组转换均可 */

/* 监控内部通道VrefInt：仅限常规通道组 */
#define LL_ADC_AWD_CH_VREFINT_REG          ((LL_ADC_CHANNEL_VREFINT    & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道VrefInt：内部参考电压，仅限常规通道组转换 */

/* 监控内部通道VrefInt：仅限注入通道组 */
#define LL_ADC_AWD_CH_VREFINT_INJ          ((LL_ADC_CHANNEL_VREFINT    & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道VrefInt：内部参考电压，仅限注入通道组转换 */

/* 监控内部通道VrefInt：常规通道组或注入通道组 */
#define LL_ADC_AWD_CH_VREFINT_REG_INJ      ((LL_ADC_CHANNEL_VREFINT    & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道VrefInt：内部参考电压，常规通道组或注入通道组转换均可 */

/* 监控内部通道温度传感器：仅限常规通道组 */
#define LL_ADC_AWD_CH_TEMPSENSOR_REG       ((LL_ADC_CHANNEL_TEMPSENSOR & ADC_CHANNEL_ID_MASK)                  | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道温度传感器，仅限常规通道组转换 */

/* 监控内部通道温度传感器：仅限注入通道组 */
#define LL_ADC_AWD_CH_TEMPSENSOR_INJ       ((LL_ADC_CHANNEL_TEMPSENSOR & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN                 | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道温度传感器，仅限注入通道组转换 */

/* 监控内部通道温度传感器：常规通道组或注入通道组 */
#define LL_ADC_AWD_CH_TEMPSENSOR_REG_INJ   ((LL_ADC_CHANNEL_TEMPSENSOR & ADC_CHANNEL_ID_MASK) | ADC_CR1_JAWDEN | ADC_CR1_AWDEN | ADC_CR1_AWDSGL) /*!< ADC模拟看门狗监控ADC内部通道温度传感器，常规通道组或注入通道组转换均可 */
/**
  * @}
  */

/** @defgroup ADC_LL_EC_AWD_THRESHOLDS  模拟看门狗 - 阈值
  * @{
  */
/* 模拟看门狗高阈值 */
#define LL_ADC_AWD_THRESHOLD_HIGH          (ADC_AWD_TR1_HIGH_REGOFFSET) /*!< ADC模拟看门狗高阈值 */

/* 模拟看门狗低阈值 */
#define LL_ADC_AWD_THRESHOLD_LOW           (ADC_AWD_TR1_LOW_REGOFFSET)  /*!< ADC模拟看门狗低阈值 */
/**
  * @}
  */
