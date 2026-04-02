#if !defined(ADC_MULTIMODE_SUPPORT)
/** @defgroup ADC_LL_EC_MULTI_MODE 多重模式 - 模式
  * @{
  */
// 独立模式：ADC双模式禁用（ADC工作在独立模式）
#define LL_ADC_MULTI_INDEPENDENT              0x00000000U                                                         /*!< ADC dual mode disabled (ADC independent mode) */
/**
  * @}
  */
#endif
#if defined(ADC_MULTIMODE_SUPPORT)
/** @defgroup ADC_LL_EC_MULTI_MODE  多重模式 - 模式
  * @{
  */
// 独立模式：ADC双模式禁用（ADC工作在独立模式）
#define LL_ADC_MULTI_INDEPENDENT              0x00000000U                                                                     /*!< ADC dual mode disabled (ADC independent mode) */
// 双重模式：规则组同时采样模式
#define LL_ADC_MULTI_DUAL_REG_SIMULT          (                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1                    ) /*!< ADC dual mode enabled: group regular simultaneous */
// 双重模式：规则组快速交错模式（采样相位间隔：7个ADC时钟周期）
#define LL_ADC_MULTI_DUAL_REG_INTERL_FAST     (                    ADC_CR1_DUALMOD_2 | ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: Combined group regular interleaved fast (delay between ADC sampling phases: 7 ADC clock cycles) (equivalent to multimode sampling delay set to "LL_ADC_MULTI_TWOSMP_DELAY_7CYCLES" on other STM32 devices)) */
// 双重模式：规则组慢速交错模式（采样相位间隔：14个ADC时钟周期）
#define LL_ADC_MULTI_DUAL_REG_INTERL_SLOW     (ADC_CR1_DUALMOD_3                                                            ) /*!< ADC dual mode enabled: Combined group regular interleaved slow (delay between ADC sampling phases: 14 ADC clock cycles) (equivalent to multimode sampling delay set to "LL_ADC_MULTI_TWOSMP_DELAY_14CYCLES" on other STM32 devices)) */
// 双重模式：注入组同时采样模式
#define LL_ADC_MULTI_DUAL_INJ_SIMULT          (                    ADC_CR1_DUALMOD_2                     | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: group injected simultaneous slow (delay between ADC sampling phases: 14 ADC clock cycles) (equivalent to multimode sampling delay set to "LL_ADC_MULTI_TWOSMP_DELAY_14CYCLES" on other STM32 devices)) */
// 双重模式：注入组交替触发模式（仅适用于外部触发，不适用于内部软件启动）
#define LL_ADC_MULTI_DUAL_INJ_ALTERN          (ADC_CR1_DUALMOD_3                                         | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: group injected alternate trigger. Works only with external triggers (not internal SW start) */
// 双重模式：规则组同时采样 + 注入组同时采样
#define LL_ADC_MULTI_DUAL_REG_SIM_INJ_SIM     (                                                            ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected simultaneous */
// 双重模式：规则组同时采样 + 注入组交替触发
#define LL_ADC_MULTI_DUAL_REG_SIM_INJ_ALT     (                                        ADC_CR1_DUALMOD_1                    ) /*!< ADC dual mode enabled: Combined group regular simultaneous + group injected alternate trigger */
// 双重模式：规则组快速交错 + 注入组同时采样
#define LL_ADC_MULTI_DUAL_REG_INTFAST_INJ_SIM (                                        ADC_CR1_DUALMOD_1 | ADC_CR1_DUALMOD_0) /*!< ADC dual mode enabled: Combined group regular interleaved fast (delay between ADC sampling phases: 7 ADC clock cycles) + group injected simultaneous */
// 双重模式：规则组慢速交错 + 注入组同时采样
#define LL_ADC_MULTI_DUAL_REG_INTSLOW_INJ_SIM (                    ADC_CR1_DUALMOD_2                                        ) /*!< ADC dual mode enabled: Combined group regular interleaved slow (delay between ADC sampling phases: 14 ADC clock cycles) + group injected simultaneous */

/**
  * @}
  */

/** @defgroup ADC_LL_EC_MULTI_MASTER_SLAVE  多重模式 - ADC主从模式选择
  * @{
  */
// 多重模式下的数据选择：选择ADC主模式数据
#define LL_ADC_MULTI_MASTER                (                  ADC_DR_DATA) /*!< In multimode, selection among several ADC instances: ADC master */
// 多重模式下的数据选择：选择ADC从模式数据（ADC2）
#define LL_ADC_MULTI_SLAVE                 (ADC_DR_ADC2DATA              ) /*!< In multimode, selection among several ADC instances: ADC slave */
// 多重模式下的数据选择：同时选择ADC主模式和从模式数据
#define LL_ADC_MULTI_MASTER_SLAVE          (ADC_DR_ADC2DATA | ADC_DR_DATA) /*!< In multimode, selection among several ADC instances: both ADC master and ADC slave */
/**
  * @}
  */

#endif /* ADC_MULTIMODE_SUPPORT */


/** @defgroup ADC_LL_EC_HW_DELAYS  ADC硬件约束延时定义
  * @note   只有ADC IP硬件延时在ADC LL驱动中定义，
  *         不包括超时值。
  *         关于延时值的详细信息，请参考源代码中
  *         每个字面量定义上方的描述。
  * @{
  */
  
/* 注意：ADC LL驱动中仅定义了ADC IP硬件延时，           */
/*       不包括超时值。                                                  */
/*       ADC操作的超时值取决于设备时钟配置      */
/*       （系统时钟与ADC时钟），                       */
/*       因此必须在用户应用程序中定义。                   */
/*       此STM32系列ADC超时延时的估算指示：           */
/*       - ADC使能时间：最大延时为1us                              */
/*         （参考设备数据手册，参数 "tSTAB"）                     */
/*       - ADC转换时间：持续时间取决于ADC时钟和ADC配置       */
/*         （参考设备参考手册，“时序”部分）               */

/* 温度传感器稳定时间的延时。                           */
/* 字面量设置为最大值（参考设备数据手册，                   */
/* 参数 "tSTART"）。                                                       */
/* 单位: us                                                                   */
// 内部参考电压稳定时间的延时（单位：微秒）
#define LL_ADC_DELAY_TEMPSENSOR_STAB_US       (10U)  /*!< Delay for internal voltage reference stabilization time */

/* ADC禁用与ADC校准开始之间所需的延时。              */
/* 注意：在此STM32系列上，开始校准前，                  */
/*       ADC必须处于禁用状态。                                                */
/*       ADC禁用状态与校准开始之间需要最少数量的ADC时钟周期                    */
/*       参考字面量 @ref LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES.          */
/*       用户应用程序中可以通过等待等效的CPU周期数来计算等待时间，     */
/*       需考虑CPU时钟与ADC时钟预分频器的比率。                      */
/* 单位: ADC时钟周期。                                                    */
// ADC禁用与ADC校准开始之间所需的延时（单位：ADC时钟周期）
#define LL_ADC_DELAY_DISABLE_CALIB_ADC_CYCLES  (2U)  /*!< Delay required between ADC disable and ADC calibration start */

/* ADC使能结束与ADC校准开始之间所需的延时。 */
/* 注意：在此STM32系列上，ADC使能结束与校准开始之间            */
/*       需要最少数量的ADC时钟周期。            */
/*       用户应用程序中可以通过等待等效的CPU周期数来计算等待时间，     */
/*       需考虑CPU时钟与ADC时钟预分频器的比率。                      */
/* 单位: ADC时钟周期。                                                    */
// ADC使能结束与ADC校准开始之间所需的延时（单位：ADC时钟周期）
#define LL_ADC_DELAY_ENABLE_CALIB_ADC_CYCLES  (2U)  /*!< Delay required between end of ADC enable and the start of ADC calibration */

/**
  * @}
  */

/**
  * @}
  */


/* Exported macro ------------------------------------------------------------*/
/** @defgroup ADC_LL_Exported_Macros ADC导出宏
  * @{
  */

/** @defgroup ADC_LL_EM_WRITE_READ 通用读写寄存器宏
  * @{
  */

/**
  * @brief  向ADC寄存器写入值
  * @param  __INSTANCE__ ADC实例
  * @param  __REG__ 要写入的寄存器
  * @param  __VALUE__ 要写入寄存器的值
  * @retval 无
  */
// 写ADC寄存器宏：将值写入指定ADC实例的指定寄存器
#define LL_ADC_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  读取ADC寄存器中的值
  * @param  __INSTANCE__ ADC实例
  * @param  __REG__ 要读取的寄存器
  * @retval 寄存器值
  */
// 读ADC寄存器宏：读取指定ADC实例的指定寄存器的值
#define LL_ADC_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup ADC_LL_EM_HELPER_MACRO ADC辅助宏
  * @{
  */

/**
  * @brief  辅助宏：将LL_ADC_CHANNEL_x字面量转换为十进制格式的ADC通道号
  * @note   示例：
  *           __LL_ADC_CHANNEL_TO_DECIMAL_NB(LL_ADC_CHANNEL_4)
  *           将返回十进制数 "4"。
  * @note   输入可以是返回通道号的函数值，可以是数字定义
  *         也可以是位域定义（只能设置一位）。
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 介于 Min_Data=0 和 Max_Data=18 之间的值
  */
// 将通道定义转换为十进制通道号
#define __LL_ADC_CHANNEL_TO_DECIMAL_NB(__CHANNEL__)                                        \
  (((__CHANNEL__) & ADC_CHANNEL_ID_NUMBER_MASK) >> ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)

/**
  * @brief  辅助宏：将十进制格式的数字转换为LL_ADC_CHANNEL_x字面量格式的ADC通道
  * @note   示例：
  *           __LL_ADC_DECIMAL_NB_TO_CHANNEL(4)
  *           将返回等同于 "LL_ADC_CHANNEL_4" 的数据。
  * @param  __DECIMAL_NB__: 介于 Min_Data=0 和 Max_Data=18 之间的值
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。\n
  *         (1) 对于从ADC寄存器读回的ADC通道，
  *             与内部通道参数的比较应使用辅助宏 @ref __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL() 进行。
  */
// 将十进制通道号转换为通道定义（包含寄存器偏移信息）
#define __LL_ADC_DECIMAL_NB_TO_CHANNEL(__DECIMAL_NB__)                                                          \
  (((__DECIMAL_NB__) <= 9U)                                                                                     \
    ? (                                                                                                         \
       ((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)                                       |        \
       (ADC_SMPR2_REGOFFSET | (((uint32_t) (3U * (__DECIMAL_NB__))) << ADC_CHANNEL_SMPx_BITOFFSET_POS))         \
      )                                                                                                         \
      :                                                                                                         \
      (                                                                                                         \
       ((__DECIMAL_NB__) << ADC_CHANNEL_ID_NUMBER_BITOFFSET_POS)                                              | \
       (ADC_SMPR1_REGOFFSET | (((uint32_t) (3U * ((__DECIMAL_NB__) - 10U))) << ADC_CHANNEL_SMPx_BITOFFSET_POS)) \
      )                                                                                                         \
  )

/**
  * @brief  辅助宏：确定所选通道是否对应于驱动程序的字面量定义。
  * @note   ADC通道的不同字面量定义包括：
  *         - ADC内部通道：
  *           LL_ADC_CHANNEL_VREFINT, LL_ADC_CHANNEL_TEMPSENSOR, ...
  *         - ADC外部通道（连接到GPIO引脚的通道）：
  *           LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...
  * @note   通道参数必须是ADC内部通道字面量定义的值（LL_ADC_CHANNEL_VREFINT,
  *         LL_ADC_CHANNEL_TEMPSENSOR, ...），
  *         ADC外部通道（LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...），
  *         不能是从ADC寄存器返回通道号的函数值，
  *         因为内部和外部通道在ADC寄存器中共享相同的通道号。
  *         区别仅通过驱动程序的参数定义进行。
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 值 "0" 表示通道对应于ADC外部通道的参数定义（连接到GPIO引脚的通道）。
  *         值 "1" 表示通道对应于ADC内部通道的参数定义。
  */
// 判断是否为内部通道
#define __LL_ADC_IS_CHANNEL_INTERNAL(__CHANNEL__)                              \
  (((__CHANNEL__) & ADC_CHANNEL_ID_INTERNAL_CH_MASK) != 0U)

/**
  * @brief  辅助宏：将ADC内部通道的参数定义（LL_ADC_CHANNEL_VREFINT,
  *         LL_ADC_CHANNEL_TEMPSENSOR, ...）转换为其等效的ADC外部通道参数定义
  *         （LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...）。
  * @note   通道参数除了可以是ADC内部通道参数定义的值
  *         （LL_ADC_CHANNEL_VREFINT, LL_ADC_CHANNEL_TEMPSENSOR, ...），
  *         还可以是ADC外部通道参数定义的值
  *         （LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...）
  *         或从ADC寄存器返回通道号的函数值。
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_0
  *         @arg @ref LL_ADC_CHANNEL_1
  *         @arg @ref LL_ADC_CHANNEL_2
  *         @arg @ref LL_ADC_CHANNEL_3
  *         @arg @ref LL_ADC_CHANNEL_4
  *         @arg @ref LL_ADC_CHANNEL_5
  *         @arg @ref LL_ADC_CHANNEL_6
  *         @arg @ref LL_ADC_CHANNEL_7
  *         @arg @ref LL_ADC_CHANNEL_8
  *         @arg @ref LL_ADC_CHANNEL_9
  *         @arg @ref LL_ADC_CHANNEL_10
  *         @arg @ref LL_ADC_CHANNEL_11
  *         @arg @ref LL_ADC_CHANNEL_12
  *         @arg @ref LL_ADC_CHANNEL_13
  *         @arg @ref LL_ADC_CHANNEL_14
  *         @arg @ref LL_ADC_CHANNEL_15
  *         @arg @ref LL_ADC_CHANNEL_16
  *         @arg @ref LL_ADC_CHANNEL_17
  */
// 将内部通道定义转换为外部通道定义（清除内部通道标志位）
#define __LL_ADC_CHANNEL_INTERNAL_TO_EXTERNAL(__CHANNEL__)                     \
  ((__CHANNEL__) & ~ADC_CHANNEL_ID_INTERNAL_CH_MASK)

/**
  * @brief  辅助宏：确定所选内部通道在所选ADC实例上是否可用。
  * @note   通道参数必须是ADC内部通道参数定义的值（LL_ADC_CHANNEL_VREFINT,
  *         LL_ADC_CHANNEL_TEMPSENSOR, ...），
  *         不能是ADC外部通道参数定义的值（LL_ADC_CHANNEL_1, LL_ADC_CHANNEL_2, ...）
  *         或从ADC寄存器返回通道号的函数值，
  *         因为内部和外部通道在ADC寄存器中共享相同的通道号。
  *         区别仅通过驱动程序的参数定义进行。
  * @param  __ADC_INSTANCE__ ADC实例
  * @param  __CHANNEL__ 此参数可以是以下值之一：
  *         @arg @ref LL_ADC_CHANNEL_VREFINT      (1)
  *         @arg @ref LL_ADC_CHANNEL_TEMPSENSOR   (1)
  *         
  *         (1) 在STM32F1上，参数仅在ADC实例上可用：ADC1。
  * @retval 值 "0" 表示所选内部通道在所选ADC实例上不可用。
  *         值 "1" 表示所选内部通道在所选ADC实例上可用。
  */
// 判断指定的ADC实例是否支持指定的内部通道
#define __LL_ADC_IS_CHANNEL_INTERNAL_AVAILABLE(__ADC_INSTANCE__, __CHANNEL__)  \
  (((__ADC_INSTANCE__) == ADC1)                                                \
    ? (                                                                        \
       ((__CHANNEL__) == LL_ADC_CHANNEL_VREFINT)    ||                         \
       ((__CHANNEL__) == LL_ADC_CHANNEL_TEMPSENSOR)                            \
      )                                                                        \
      :                                                                        \
      (0U)                                                                     \
  )
