/**
  ******************************************************************************
  * @file    stm32_hal_legacy.h
  * @author  MCD Application Team
  * @brief   本文件包含STM32Cube HAL常量的别名定义，
  *          为了兼容旧版本代码而保留的宏和函数。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2021 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef STM32_HAL_LEGACY
#define STM32_HAL_LEGACY

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
/* 导出类型 ------------------------------------------------------------*/
/* 导出常量 --------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Defines HAL CRYP 为了兼容旧版本而保留的别名定义
  * @{
  */
/* 以下宏定义将旧的AES相关命名映射到新的CRYP(加密处理器)命名 */
#define AES_FLAG_RDERR                  CRYP_FLAG_RDERR           // 读错误标志
#define AES_FLAG_WRERR                  CRYP_FLAG_WRERR           // 写错误标志
#define AES_CLEARFLAG_CCF               CRYP_CLEARFLAG_CCF        // 清除计算完成标志
#define AES_CLEARFLAG_RDERR             CRYP_CLEARFLAG_RDERR      // 清除读错误标志
#define AES_CLEARFLAG_WRERR             CRYP_CLEARFLAG_WRERR      // 清除写错误标志
#if defined(STM32H7) || defined(STM32MP1)
/* 针对STM32H7和STM32MP1系列，定义数据交换类型的别名 */
#define CRYP_DATATYPE_32B               CRYP_NO_SWAP              // 32位数据，不交换
#define CRYP_DATATYPE_16B               CRYP_HALFWORD_SWAP        // 16位数据，半字交换
#define CRYP_DATATYPE_8B                CRYP_BYTE_SWAP            // 8位数据，字节交换
#define CRYP_DATATYPE_1B                CRYP_BIT_SWAP             // 1位数据，位交换
#endif /* STM32H7 || STM32MP1 */
/**
  * @}
  */

/** @defgroup HAL_ADC_Aliased_Defines HAL ADC 为了兼容旧版本而保留的别名定义
  * @{
  */
/* ADC分辨率定义别名 */
#define ADC_RESOLUTION12b               ADC_RESOLUTION_12B        // 12位分辨率
#define ADC_RESOLUTION10b               ADC_RESOLUTION_10B        // 10位分辨率
#define ADC_RESOLUTION8b                ADC_RESOLUTION_8B         // 8位分辨率
#define ADC_RESOLUTION6b                ADC_RESOLUTION_6B         // 6位分辨率

/* ADC溢出模式定义别名 */
#define OVR_DATA_OVERWRITTEN            ADC_OVR_DATA_OVERWRITTEN  // 溢出时数据被覆盖
#define OVR_DATA_PRESERVED              ADC_OVR_DATA_PRESERVED    // 溢出时数据保留

/* ADC结束转换模式定义别名 */
#define EOC_SINGLE_CONV                 ADC_EOC_SINGLE_CONV       // 单次转换结束
#define EOC_SEQ_CONV                    ADC_EOC_SEQ_CONV          // 序列转换结束
#define EOC_SINGLE_SEQ_CONV             ADC_EOC_SINGLE_SEQ_CONV   // 单次和序列转换结束

/* ADC转换组类型定义别名 */
#define REGULAR_GROUP                   ADC_REGULAR_GROUP         // 常规通道组
#define INJECTED_GROUP                  ADC_INJECTED_GROUP        // 注入通道组
#define REGULAR_INJECTED_GROUP          ADC_REGULAR_INJECTED_GROUP // 常规和注入通道组

/* ADC事件定义别名 */
#define AWD_EVENT                       ADC_AWD_EVENT             // 模拟看门狗事件
#define AWD1_EVENT                      ADC_AWD1_EVENT            // 模拟看门狗1事件
#define AWD2_EVENT                      ADC_AWD2_EVENT            // 模拟看门狗2事件
#define AWD3_EVENT                      ADC_AWD3_EVENT            // 模拟看门狗3事件
#define OVR_EVENT                       ADC_OVR_EVENT             // 溢出事件
#define JQOVF_EVENT                     ADC_JQOVF_EVENT           // 注入队列溢出事件

/* ADC通道类型定义别名 */
#define ALL_CHANNELS                    ADC_ALL_CHANNELS          // 所有通道
#define REGULAR_CHANNELS                ADC_REGULAR_CHANNELS      // 常规通道
#define INJECTED_CHANNELS               ADC_INJECTED_CHANNELS     // 注入通道

/* ADC系统配置标志别名 */
#define SYSCFG_FLAG_SENSOR_ADC          ADC_FLAG_SENSOR           // 传感器标志
#define SYSCFG_FLAG_VREF_ADC            ADC_FLAG_VREFINT          // 内部参考电压标志

/* ADC时钟预分频器定义别名 */
#define ADC_CLOCKPRESCALER_PCLK_DIV1    ADC_CLOCK_SYNC_PCLK_DIV1  // PCLK 1分频
#define ADC_CLOCKPRESCALER_PCLK_DIV2    ADC_CLOCK_SYNC_PCLK_DIV2  // PCLK 2分频
#define ADC_CLOCKPRESCALER_PCLK_DIV4    ADC_CLOCK_SYNC_PCLK_DIV4  // PCLK 4分频
#define ADC_CLOCKPRESCALER_PCLK_DIV6    ADC_CLOCK_SYNC_PCLK_DIV6  // PCLK 6分频
#define ADC_CLOCKPRESCALER_PCLK_DIV8    ADC_CLOCK_SYNC_PCLK_DIV8  // PCLK 8分频

/* ADC外部触发源定义别名 */
#define ADC_EXTERNALTRIG0_T6_TRGO       ADC_EXTERNALTRIGCONV_T6_TRGO    // 定时器6 TRGO触发
#define ADC_EXTERNALTRIG1_T21_CC2       ADC_EXTERNALTRIGCONV_T21_CC2    // 定时器21 通道2捕获比较触发
#define ADC_EXTERNALTRIG2_T2_TRGO       ADC_EXTERNALTRIGCONV_T2_TRGO    // 定时器2 TRGO触发
#define ADC_EXTERNALTRIG3_T2_CC4        ADC_EXTERNALTRIGCONV_T2_CC4     // 定时器2 通道4捕获比较触发
#define ADC_EXTERNALTRIG4_T22_TRGO      ADC_EXTERNALTRIGCONV_T22_TRGO   // 定时器22 TRGO触发
#define ADC_EXTERNALTRIG7_EXT_IT11      ADC_EXTERNALTRIGCONV_EXT_IT11   // 外部中断线11触发

/* ADC时钟和触发边沿定义别名 */
#define ADC_CLOCK_ASYNC                 ADC_CLOCK_ASYNC_DIV1           // 异步时钟
#define ADC_EXTERNALTRIG_EDGE_NONE      ADC_EXTERNALTRIGCONVEDGE_NONE  // 无触发边沿
#define ADC_EXTERNALTRIG_EDGE_RISING    ADC_EXTERNALTRIGCONVEDGE_RISING // 上升沿触发
#define ADC_EXTERNALTRIG_EDGE_FALLING   ADC_EXTERNALTRIGCONVEDGE_FALLING // 下降沿触发
#define ADC_EXTERNALTRIG_EDGE_RISINGFALLING ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING // 双边沿触发

/* ADC采样时间定义别名 */
#define ADC_SAMPLETIME_2CYCLE_5         ADC_SAMPLETIME_2CYCLES_5       // 采样周期2.5个时钟周期

/* ADC状态定义别名 */
#define HAL_ADC_STATE_BUSY_REG          HAL_ADC_STATE_REG_BUSY         // 常规转换忙状态
#define HAL_ADC_STATE_BUSY_INJ          HAL_ADC_STATE_INJ_BUSY         // 注入转换忙状态
#define HAL_ADC_STATE_EOC_REG           HAL_ADC_STATE_REG_EOC          // 常规转换结束状态
#define HAL_ADC_STATE_EOC_INJ           HAL_ADC_STATE_INJ_EOC          // 注入转换结束状态
#define HAL_ADC_STATE_ERROR             HAL_ADC_STATE_ERROR_INTERNAL   // 内部错误状态
#define HAL_ADC_STATE_BUSY              HAL_ADC_STATE_BUSY_INTERNAL    // 内部忙状态
#define HAL_ADC_STATE_AWD               HAL_ADC_STATE_AWD1             // 模拟看门狗1状态

#if defined(STM32H7)
/* STM32H7系列专用通道定义 */
#define ADC_CHANNEL_VBAT_DIV4           ADC_CHANNEL_VBAT               // VBAT通道(分压4)
#endif /* STM32H7 */

#if defined(STM32U5)
/* STM32U5系列专用采样时间定义 */
#define ADC_SAMPLETIME_5CYCLE           ADC_SAMPLETIME_5CYCLES         // 5个时钟周期采样
#define ADC_SAMPLETIME_391CYCLES_5      ADC_SAMPLETIME_391CYCLES       // 391.5个时钟周期采样
#define ADC4_SAMPLETIME_160CYCLES_5     ADC4_SAMPLETIME_814CYCLES_5    // ADC4采样周期别名
#endif /* STM32U5 */

#if defined(STM32H5)
/* STM32H5系列专用通道定义 */
#define ADC_CHANNEL_VCORE               ADC_CHANNEL_VDDCORE            // 内核电压通道
#endif /* STM32H5 */
/**
  * @}
  */

/** @defgroup HAL_CEC_Aliased_Defines HAL CEC 为了兼容旧版本而保留的别名定义
  * @{
  */

/* CEC(消费电子控制)中断标志获取宏别名 */
#define __HAL_CEC_GET_IT __HAL_CEC_GET_FLAG

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Defines HAL COMP 为了兼容旧版本而保留的别名定义
  * @{
  */
/* COMP(比较器)窗口模式定义别名 */
#define COMP_WINDOWMODE_DISABLED       COMP_WINDOWMODE_DISABLE        // 禁用窗口模式
#define COMP_WINDOWMODE_ENABLED        COMP_WINDOWMODE_ENABLE         // 使能窗口模式

/* COMP外部中断线定义别名 */
#define COMP_EXTI_LINE_COMP1_EVENT     COMP_EXTI_LINE_COMP1           // COMP1外部中断线
#define COMP_EXTI_LINE_COMP2_EVENT     COMP_EXTI_LINE_COMP2           // COMP2外部中断线
#define COMP_EXTI_LINE_COMP3_EVENT     COMP_EXTI_LINE_COMP3           // COMP3外部中断线
#define COMP_EXTI_LINE_COMP4_EVENT     COMP_EXTI_LINE_COMP4           // COMP4外部中断线
#define COMP_EXTI_LINE_COMP5_EVENT     COMP_EXTI_LINE_COMP5           // COMP5外部中断线
#define COMP_EXTI_LINE_COMP6_EVENT     COMP_EXTI_LINE_COMP6           // COMP6外部中断线
#define COMP_EXTI_LINE_COMP7_EVENT     COMP_EXTI_LINE_COMP7           // COMP7外部中断线

#if defined(STM32L0)
/* STM32L0系列专用：COMP连接到LPTIM的配置 */
#define COMP_LPTIMCONNECTION_ENABLED   ((uint32_t)0x00000003U)    /*!< COMPX输出通用命名：COMP1连接到LPTIM输入1，COMP2连接到LPTIM输入2 */
#endif

/* COMP输出重定向定义别名 */
#define COMP_OUTPUT_COMP6TIM2OCREFCLR  COMP_OUTPUT_COMP6_TIM2OCREFCLR // COMP6输出连接到TIM2 OCREFCLR

#if defined(STM32F373xC) || defined(STM32F378xx)
/* STM32F373xC/STM32F378xx系列专用输出重定向定义 */
#define COMP_OUTPUT_TIM3IC1            COMP_OUTPUT_COMP1_TIM3IC1       // COMP1输出连接到TIM3输入捕获1
#define COMP_OUTPUT_TIM3OCREFCLR       COMP_OUTPUT_COMP1_TIM3OCREFCLR  // COMP1输出连接到TIM3 OCREFCLR
#endif /* STM32F373xC || STM32F378xx */

#if defined(STM32L0) || defined(STM32L4)
/* STM32L0/L4系列专用定义 */

/* 窗口模式使能 */
#define COMP_WINDOWMODE_ENABLE         COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON

/* 比较器非反相输入端(正端)输入源选择 */
#define COMP_NONINVERTINGINPUT_IO1      COMP_INPUT_PLUS_IO1            // IO1作为正端输入
#define COMP_NONINVERTINGINPUT_IO2      COMP_INPUT_PLUS_IO2            // IO2作为正端输入
#define COMP_NONINVERTINGINPUT_IO3      COMP_INPUT_PLUS_IO3            // IO3作为正端输入
#define COMP_NONINVERTINGINPUT_IO4      COMP_INPUT_PLUS_IO4            // IO4作为正端输入
#define COMP_NONINVERTINGINPUT_IO5      COMP_INPUT_PLUS_IO5            // IO5作为正端输入
#define COMP_NONINVERTINGINPUT_IO6      COMP_INPUT_PLUS_IO6            // IO6作为正端输入

/* 比较器反相输入端(负端)输入源选择 */
#define COMP_INVERTINGINPUT_1_4VREFINT  COMP_INPUT_MINUS_1_4VREFINT    // 1/4 VREFINT作为负端输入
#define COMP_INVERTINGINPUT_1_2VREFINT  COMP_INPUT_MINUS_1_2VREFINT    // 1/2 VREFINT作为负端输入
#define COMP_INVERTINGINPUT_3_4VREFINT  COMP_INPUT_MINUS_3_4VREFINT    // 3/4 VREFINT作为负端输入
#define COMP_INVERTINGINPUT_VREFINT     COMP_INPUT_MINUS_VREFINT       // VREFINT作为负端输入
#define COMP_INVERTINGINPUT_DAC1_CH1    COMP_INPUT_MINUS_DAC1_CH1      // DAC1通道1作为负端输入
#define COMP_INVERTINGINPUT_DAC1_CH2    COMP_INPUT_MINUS_DAC1_CH2      // DAC1通道2作为负端输入
#define COMP_INVERTINGINPUT_DAC1        COMP_INPUT_MINUS_DAC1_CH1      // DAC1作为负端输入(兼容旧命名)
#define COMP_INVERTINGINPUT_DAC2        COMP_INPUT_MINUS_DAC1_CH2      // DAC2作为负端输入(兼容旧命名)
#define COMP_INVERTINGINPUT_IO1         COMP_INPUT_MINUS_IO1           // IO1作为负端输入
#if defined(STM32L0)
/* STM32L0系列修正：只有2个专用IO(IO1和IO2)，IO2被错误地分配给了与DAC共享的IO，
   IO3对应第二个专用IO(仅针对COMP2) */
#define COMP_INVERTINGINPUT_IO2         COMP_INPUT_MINUS_DAC1_CH2
#define COMP_INVERTINGINPUT_IO3         COMP_INPUT_MINUS_IO2
#else
#define COMP_INVERTINGINPUT_IO2         COMP_INPUT_MINUS_IO2           // IO2作为负端输入
#define COMP_INVERTINGINPUT_IO3         COMP_INPUT_MINUS_IO3           // IO3作为负端输入
#endif
#define COMP_INVERTINGINPUT_IO4         COMP_INPUT_MINUS_IO4           // IO4作为负端输入
#define COMP_INVERTINGINPUT_IO5         COMP_INPUT_MINUS_IO5           // IO5作为负端输入

/* 比较器输出电平定义 */
#define COMP_OUTPUTLEVEL_LOW            COMP_OUTPUT_LEVEL_LOW          // 输出低电平
#define COMP_OUTPUTLEVEL_HIGH           COMP_OUTPUT_LEVEL_HIGH         // 输出高电平

/* 注意：保留字面量"COMP_FLAG_LOCK"是为了兼容旧版本。
   要检查COMP锁定状态，请使用宏"__HAL_COMP_IS_LOCKED()"。 */
#if defined(COMP_CSR_LOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_LOCK                  // 锁定标志(针对单一COMP寄存器)
#elif defined(COMP_CSR_COMP1LOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_COMP1LOCK             // 锁定标志(针对COMP1)
#elif defined(COMP_CSR_COMPxLOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_COMPxLOCK             // 锁定标志(通用COMPx)
#endif

#if defined(STM32L4)
/* STM32L4系列消隐源定义 */
#define COMP_BLANKINGSRCE_TIM1OC5        COMP_BLANKINGSRC_TIM1_OC5_COMP1 // TIM1 OC5消隐源
#define COMP_BLANKINGSRCE_TIM2OC3        COMP_BLANKINGSRC_TIM2_OC3_COMP1 // TIM2 OC3消隐源
#define COMP_BLANKINGSRCE_TIM3OC3        COMP_BLANKINGSRC_TIM3_OC3_COMP1 // TIM3 OC3消隐源
#define COMP_BLANKINGSRCE_TIM3OC4        COMP_BLANKINGSRC_TIM3_OC4_COMP2 // TIM3 OC4消隐源
#define COMP_BLANKINGSRCE_TIM8OC5        COMP_BLANKINGSRC_TIM8_OC5_COMP2 // TIM8 OC5消隐源
#define COMP_BLANKINGSRCE_TIM15OC1       COMP_BLANKINGSRC_TIM15_OC1_COMP2 // TIM15 OC1消隐源
#define COMP_BLANKINGSRCE_NONE           COMP_BLANKINGSRC_NONE          // 无消隐源
#endif

#if defined(STM32L0)
/* STM32L0系列功耗模式定义 */
#define COMP_MODE_HIGHSPEED              COMP_POWERMODE_MEDIUMSPEED     // 高速模式(映射到中速)
#define COMP_MODE_LOWSPEED               COMP_POWERMODE_ULTRALOWPOWER   // 低速模式(映射到超低功耗)
#else
/* 其他系列功耗模式定义 */
#define COMP_MODE_HIGHSPEED              COMP_POWERMODE_HIGHSPEED       // 高速模式
#define COMP_MODE_MEDIUMSPEED            COMP_POWERMODE_MEDIUMSPEED     // 中速模式
#define COMP_MODE_LOWPOWER               COMP_POWERMODE_LOWPOWER        // 低功耗模式
#define COMP_MODE_ULTRALOWPOWER          COMP_POWERMODE_ULTRALOWPOWER   // 超低功耗模式
#endif

#endif

#if defined(STM32U5)
/* STM32U5系列专用宏：修正拼写错误(RASING -> RISING) */
#define __HAL_COMP_COMP1_EXTI_CLEAR_RASING_FLAG __HAL_COMP_COMP1_EXTI_CLEAR_RISING_FLAG
#endif

/**
  * @}
  */

/** @defgroup HAL_CORTEX_Aliased_Defines HAL CORTEX 为了兼容旧版本而保留的别名定义
  * @{
  */
/* SysTick时钟配置函数别名 */
#define __HAL_CORTEX_SYSTICKCLK_CONFIG HAL_SYSTICK_CLKSourceConfig
#if defined(STM32U5)
/* STM32U5系列MPU内存类型属性定义 */
#define  MPU_DEVICE_nGnRnE          MPU_DEVICE_NGNRNE               // 设备内存：非汇聚、非重排序、无早期写确认
#define  MPU_DEVICE_nGnRE           MPU_DEVICE_NGNRE                // 设备内存：非汇聚、非重排序、早期写确认
#define  MPU_DEVICE_nGRE            MPU_DEVICE_NGRE                 // 设备内存：非汇聚、重排序、早期写确认
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup CRC_Aliases CRC API 别名
  * @{
  */
#if defined(STM32H5) || defined(STM32C0)
/* STM32H5和STM32C0系列不定义以下别名 */
#else
/* CRC输入/输出数据反转函数别名，用于跨STM32系列兼容性 */
#define HAL_CRC_Input_Data_Reverse   HAL_CRCEx_Input_Data_Reverse    // 输入数据反转
#define HAL_CRC_Output_Data_Reverse  HAL_CRCEx_Output_Data_Reverse   // 输出数据反转
#endif
/**
  * @}
  */

/** @defgroup HAL_CRC_Aliased_Defines HAL CRC 为了兼容旧版本而保留的别名定义
  * @{
  */

/* CRC输出数据反转使能/禁用定义 */
#define CRC_OUTPUTDATA_INVERSION_DISABLED    CRC_OUTPUTDATA_INVERSION_DISABLE // 禁用输出数据反转
#define CRC_OUTPUTDATA_INVERSION_ENABLED     CRC_OUTPUTDATA_INVERSION_ENABLE  // 使能输出数据反转

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Defines HAL DAC 为了兼容旧版本而保留的别名定义
  * @{
  */

/* DAC通道定义别名 */
#define DAC1_CHANNEL_1                                  DAC_CHANNEL_1   // DAC1 通道1
#define DAC1_CHANNEL_2                                  DAC_CHANNEL_2   // DAC1 通道2
#define DAC2_CHANNEL_1                                  DAC_CHANNEL_1   // DAC2 通道1

/* DAC波形生成定义 */
#define DAC_WAVE_NONE                                   0x00000000U     // 无波形
#define DAC_WAVE_NOISE                                  DAC_CR_WAVE1_0  // 噪声波形
#define DAC_WAVE_TRIANGLE                               DAC_CR_WAVE1_1  // 三角波波形
#define DAC_WAVEGENERATION_NONE                         DAC_WAVE_NONE   // 无波形生成
#define DAC_WAVEGENERATION_NOISE                        DAC_WAVE_NOISE  // 噪声波形生成
#define DAC_WAVEGENERATION_TRIANGLE                     DAC_WAVE_TRIANGLE // 三角波波形生成

#if defined(STM32G4) || defined(STM32H7) || defined (STM32U5)
/* DAC片上连接(输出缓冲)配置别名 */
#define DAC_CHIPCONNECT_DISABLE       DAC_CHIPCONNECT_EXTERNAL         // 禁用片上连接(连接到外部引脚)
#define DAC_CHIPCONNECT_ENABLE        DAC_CHIPCONNECT_INTERNAL         // 使能片上连接(连接到片内)
#endif

#if defined(STM32U5)
/* STM32U5系列DAC触发源定义别名 */
#define DAC_TRIGGER_STOP_LPTIM1_OUT  DAC_TRIGGER_STOP_LPTIM1_CH1       // LPTIM1停止触发
#define DAC_TRIGGER_STOP_LPTIM3_OUT  DAC_TRIGGER_STOP_LPTIM3_CH1       // LPTIM3停止触发
#define DAC_TRIGGER_LPTIM1_OUT       DAC_TRIGGER_LPTIM1_CH1            // LPTIM1输出触发
#define DAC_TRIGGER_LPTIM3_OUT       DAC_TRIGGER_LPTIM3_CH1            // LPTIM3输出触发
#endif

#if defined(STM32H5)
/* STM32H5系列DAC触发源定义别名 */
#define DAC_TRIGGER_LPTIM1_OUT       DAC_TRIGGER_LPTIM1_CH1            // LPTIM1输出触发
#define DAC_TRIGGER_LPTIM2_OUT       DAC_TRIGGER_LPTIM2_CH1            // LPTIM2输出触发
#endif

#if defined(STM32L1) || defined(STM32L4) || defined(STM32G0) || defined(STM32L5) || defined(STM32H7) || \
    defined(STM32F4) || defined(STM32G4)
/* DAC MSP初始化回调ID定义别名 */
#define HAL_DAC_MSP_INIT_CB_ID       HAL_DAC_MSPINIT_CB_ID             // MSP初始化回调ID
#define HAL_DAC_MSP_DEINIT_CB_ID     HAL_DAC_MSPDEINIT_CB_ID           // MSP反初始化回调ID
#endif

/**
  * @}
  */

/** @defgroup HAL_DMA_Aliased_Defines HAL DMA 为了兼容旧版本而保留的别名定义
  * @{
  */
/* DMA重映射定义别名，用于将外设请求映射到特定DMA通道 */
#define HAL_REMAPDMA_ADC_DMA_CH2                DMA_REMAP_ADC_DMA_CH2            // ADC DMA通道2重映射
#define HAL_REMAPDMA_USART1_TX_DMA_CH4          DMA_REMAP_USART1_TX_DMA_CH4      // USART1发送 DMA通道4重映射
#define HAL_REMAPDMA_USART1_RX_DMA_CH5          DMA_REMAP_USART1_RX_DMA_CH5      // USART1接收 DMA通道5重映射
#define HAL_REMAPDMA_TIM16_DMA_CH4              DMA_REMAP_TIM16_DMA_CH4          // TIM16 DMA通道4重映射
#define HAL_REMAPDMA_TIM17_DMA_CH2              DMA_REMAP_TIM17_DMA_CH2          // TIM17 DMA通道2重映射
#define HAL_REMAPDMA_USART3_DMA_CH32            DMA_REMAP_USART3_DMA_CH32        // USART3 DMA通道32重映射
#define HAL_REMAPDMA_TIM16_DMA_CH6              DMA_REMAP_TIM16_DMA_CH6          // TIM16 DMA通道6重映射
#define HAL_REMAPDMA_TIM17_DMA_CH7              DMA_REMAP_TIM17_DMA_CH7          // TIM17 DMA通道7重映射
#define HAL_REMAPDMA_SPI2_DMA_CH67              DMA_REMAP_SPI2_DMA_CH67          // SPI2 DMA通道67重映射
#define HAL_REMAPDMA_USART2_DMA_CH67            DMA_REMAP_USART2_DMA_CH67        // USART2 DMA通道67重映射
#define HAL_REMAPDMA_I2C1_DMA_CH76              DMA_REMAP_I2C1_DMA_CH76          // I2C1 DMA通道76重映射
#define HAL_REMAPDMA_TIM1_DMA_CH6               DMA_REMAP_TIM1_DMA_CH6           // TIM1 DMA通道6重映射
#define HAL_REMAPDMA_TIM2_DMA_CH7               DMA_REMAP_TIM2_DMA_CH7           // TIM2 DMA通道7重映射
#define HAL_REMAPDMA_TIM3_DMA_CH6               DMA_REMAP_TIM3_DMA_CH6           // TIM3 DMA通道6重映射

/* DMA重映射检查和使能宏别名 */
#define IS_HAL_REMAPDMA                          IS_DMA_REMAP                     // 检查是否为有效的DMA重映射
#define __HAL_REMAPDMA_CHANNEL_ENABLE            __HAL_DMA_REMAP_CHANNEL_ENABLE   // 使能DMA通道重映射
#define __HAL_REMAPDMA_CHANNEL_DISABLE           __HAL_DMA_REMAP_CHANNEL_DISABLE  // 禁用DMA通道重映射

#if defined(STM32L4)

/* STM32L4系列 DMAMUX 请求生成器定义别名 */
#define HAL_DMAMUX1_REQUEST_GEN_EXTI0            HAL_DMAMUX1_REQ_GEN_EXTI0        // EXTI0触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI1            HAL_DMAMUX1_REQ_GEN_EXTI1        // EXTI1触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI2            HAL_DMAMUX1_REQ_GEN_EXTI2        // EXTI2触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI3            HAL_DMAMUX1_REQ_GEN_EXTI3        // EXTI3触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI4            HAL_DMAMUX1_REQ_GEN_EXTI4        // EXTI4触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI5            HAL_DMAMUX1_REQ_GEN_EXTI5        // EXTI5触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI6            HAL_DMAMUX1_REQ_GEN_EXTI6        // EXTI6触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI7            HAL_DMAMUX1_REQ_GEN_EXTI7        // EXTI7触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI8            HAL_DMAMUX1_REQ_GEN_EXTI8        // EXTI8触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI9            HAL_DMAMUX1_REQ_GEN_EXTI9        // EXTI9触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI10           HAL_DMAMUX1_REQ_GEN_EXTI10       // EXTI10触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI11           HAL_DMAMUX1_REQ_GEN_EXTI11       // EXTI11触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI12           HAL_DMAMUX1_REQ_GEN_EXTI12       // EXTI12触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI13           HAL_DMAMUX1_REQ_GEN_EXTI13       // EXTI13触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI14           HAL_DMAMUX1_REQ_GEN_EXTI14       // EXTI14触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_EXTI15           HAL_DMAMUX1_REQ_GEN_EXTI15       // EXTI15触发请求生成
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH0_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT // DMAMUX1通道0事件触发
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH1_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT // DMAMUX1通道1事件触发
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH2_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT // DMAMUX1通道2事件触发
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH3_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH3_EVT // DMAMUX1通道3事件触发
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM1_OUT       HAL_DMAMUX1_REQ_GEN_LPTIM1_OUT   // LPTIM1输出触发
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM2_OUT       HAL_DMAMUX1_REQ_GEN_LPTIM2_OUT   // LPTIM2输出触发
#define HAL_DMAMUX1_REQUEST_GEN_DSI_TE           HAL_DMAMUX1_REQ_GEN_DSI_TE       // DSI tearing effect触发
#define HAL_DMAMUX1_REQUEST_GEN_DSI_EOT          HAL_DMAMUX1_REQ_GEN_DSI_EOT      // DSI传输结束触发
#define HAL_DMAMUX1_REQUEST_GEN_DMA2D_EOT        HAL_DMAMUX1_REQ_GEN_DMA2D_EOT    // DMA2D传输结束触发
#define HAL_DMAMUX1_REQUEST_GEN_LTDC_IT          HAL_DMAMUX1_REQ_GEN_LTDC_IT      // LTDC中断触发

/* DMAMUX 请求生成器触发极性定义别名 */
#define HAL_DMAMUX_REQUEST_GEN_NO_EVENT          HAL_DMAMUX_REQ_GEN_NO_EVENT      // 无事件触发
#define HAL_DMAMUX_REQUEST_GEN_RISING            HAL_DMAMUX_REQ_GEN_RISING        // 上升沿触发
#define HAL_DMAMUX_REQUEST_GEN_FALLING           HAL_DMAMUX_REQ_GEN_FALLING       // 下降沿触发
#define HAL_DMAMUX_REQUEST_GEN_RISING_FALLING    HAL_DMAMUX_REQ_GEN_RISING_FALLING // 双边沿触发

#if defined(STM32L4R5xx) || defined(STM32L4R9xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || \
    defined(STM32L4S7xx) || defined(STM32L4S9xx)
/* STM32L4R/S系列专用DMA请求定义 */
#define DMA_REQUEST_DCMI_PSSI                    DMA_REQUEST_DCMI                 // DCMI/PSSI请求
#endif

#endif /* STM32L4 */

#if defined(STM32G0)
/* STM32G0系列DMA请求定义别名 */
#define DMA_REQUEST_DAC1_CHANNEL1                DMA_REQUEST_DAC1_CH1             // DAC1通道1请求
#define DMA_REQUEST_DAC1_CHANNEL2                DMA_REQUEST_DAC1_CH2             // DAC1通道2请求
#define DMA_REQUEST_TIM16_TRIG_COM               DMA_REQUEST_TIM16_COM            // TIM16触发/通信请求
#define DMA_REQUEST_TIM17_TRIG_COM               DMA_REQUEST_TIM17_COM            // TIM17触发/通信请求

/* LL库DMAMUX请求定义别名 */
#define LL_DMAMUX_REQ_TIM16_TRIG_COM             LL_DMAMUX_REQ_TIM16_COM          // LL库：TIM16触发/通信请求
#define LL_DMAMUX_REQ_TIM17_TRIG_COM             LL_DMAMUX_REQ_TIM17_COM          // LL库：TIM17触发/通信请求
#endif

#if defined(STM32H7)

/* STM32H7系列DMA请求定义别名 */
#define DMA_REQUEST_DAC1 DMA_REQUEST_DAC1_CH1                                     // DAC1请求(通道1)
#define DMA_REQUEST_DAC2 DMA_REQUEST_DAC1_CH2                                     // DAC2请求(通道2)

/* BDMA请求定义别名 */
#define BDMA_REQUEST_LP_UART1_RX BDMA_REQUEST_LPUART1_RX                          // LPUART1接收请求
#define BDMA_REQUEST_LP_UART1_TX BDMA_REQUEST_LPUART1_TX                          // LPUART1发送请求

/* DMAMUX请求生成器定义别名 */
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH0_EVT    HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT // DMAMUX1通道0事件
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH1_EVT    HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT // DMAMUX1通道1事件
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH2_EVT    HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT // DMAMUX1通道2事件
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM1_OUT         HAL_DMAMUX1_REQ_GEN_LPTIM1_OUT      // LPTIM1输出
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM2_OUT         HAL_DMAMUX1_REQ_GEN_LPTIM2_OUT      // LPTIM2输出
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM3_OUT         HAL_DMAMUX1_REQ_GEN_LPTIM3_OUT      // LPTIM3输出
#define HAL_DMAMUX1_REQUEST_GEN_EXTI0              HAL_DMAMUX1_REQ_GEN_EXTI0           // EXTI0
#define HAL_DMAMUX1_REQUEST_GEN_TIM12_TRGO         HAL_DMAMUX1_REQ_GEN_TIM12_TRGO      // TIM12 TRGO
/* DMAMUX2 请求发生器事件定义，用于DMA请求多路复用 */
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH0_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH0_EVT   // DMAMUX2 通道0事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH1_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH1_EVT   // DMAMUX2 通道1事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH2_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH2_EVT   // DMAMUX2 通道2事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH3_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH3_EVT   // DMAMUX2 通道3事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH4_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH4_EVT   // DMAMUX2 通道4事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH5_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH5_EVT   // DMAMUX2 通道5事件
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH6_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH6_EVT   // DMAMUX2 通道6事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_RX_WKUP    HAL_DMAMUX2_REQ_GEN_LPUART1_RX_WKUP   // LPUART1 接收唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_TX_WKUP    HAL_DMAMUX2_REQ_GEN_LPUART1_TX_WKUP   // LPUART1 发送唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM2_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM2_WKUP       // LPTIM2 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM2_OUT         HAL_DMAMUX2_REQ_GEN_LPTIM2_OUT        // LPTIM2 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM3_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM3_WKUP       // LPTIM3 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM3_OUT         HAL_DMAMUX2_REQ_GEN_LPTIM3_OUT        // LPTIM3 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM4_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM4_WKUP       // LPTIM4 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM5_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM5_WKUP       // LPTIM5 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_I2C4_WKUP          HAL_DMAMUX2_REQ_GEN_I2C4_WKUP         // I2C4 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_SPI6_WKUP          HAL_DMAMUX2_REQ_GEN_SPI6_WKUP         // SPI6 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_COMP1_OUT          HAL_DMAMUX2_REQ_GEN_COMP1_OUT         // 比较器1 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_COMP2_OUT          HAL_DMAMUX2_REQ_GEN_COMP2_OUT         // 比较器2 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_RTC_WKUP           HAL_DMAMUX2_REQ_GEN_RTC_WKUP          // RTC 唤醒事件
#define HAL_DMAMUX2_REQUEST_GEN_EXTI0              HAL_DMAMUX2_REQ_GEN_EXTI0             // 外部中断线0 事件
#define HAL_DMAMUX2_REQUEST_GEN_EXTI2              HAL_DMAMUX2_REQ_GEN_EXTI2             // 外部中断线2 事件
#define HAL_DMAMUX2_REQUEST_GEN_I2C4_IT_EVT        HAL_DMAMUX2_REQ_GEN_I2C4_IT_EVT       // I2C4 中断/事件
#define HAL_DMAMUX2_REQUEST_GEN_SPI6_IT            HAL_DMAMUX2_REQ_GEN_SPI6_IT           // SPI6 中断事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_TX_IT      HAL_DMAMUX2_REQ_GEN_LPUART1_TX_IT     // LPUART1 发送中断事件
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_RX_IT      HAL_DMAMUX2_REQ_GEN_LPUART1_RX_IT     // LPUART1 接收中断事件
#define HAL_DMAMUX2_REQUEST_GEN_ADC3_IT            HAL_DMAMUX2_REQ_GEN_ADC3_IT           // ADC3 中断事件
#define HAL_DMAMUX2_REQUEST_GEN_ADC3_AWD1_OUT      HAL_DMAMUX2_REQ_GEN_ADC3_AWD1_OUT     // ADC3 模拟看门狗1 输出事件
#define HAL_DMAMUX2_REQUEST_GEN_BDMA_CH0_IT        HAL_DMAMUX2_REQ_GEN_BDMA_CH0_IT       // BDMA 通道0 中断事件
#define HAL_DMAMUX2_REQUEST_GEN_BDMA_CH1_IT        HAL_DMAMUX2_REQ_GEN_BDMA_CH1_IT       // BDMA 通道1 中断事件

/* DMAMUX 请求发生器触发极性定义 */
#define HAL_DMAMUX_REQUEST_GEN_NO_EVENT            HAL_DMAMUX_REQ_GEN_NO_EVENT           // 无事件触发
#define HAL_DMAMUX_REQUEST_GEN_RISING              HAL_DMAMUX_REQ_GEN_RISING             // 上升沿触发
#define HAL_DMAMUX_REQUEST_GEN_FALLING             HAL_DMAMUX_REQ_GEN_FALLING            // 下降沿触发
#define HAL_DMAMUX_REQUEST_GEN_RISING_FALLING      HAL_DMAMUX_REQ_GEN_RISING_FALLING     // 双沿触发(上升沿和下降沿)

/* DFSDM 滤波器外部触发源定义 */
#define DFSDM_FILTER_EXT_TRIG_LPTIM1               DFSDM_FILTER_EXT_TRIG_LPTIM1_OUT      // LPTIM1 输出作为DFSDM外部触发
#define DFSDM_FILTER_EXT_TRIG_LPTIM2               DFSDM_FILTER_EXT_TRIG_LPTIM2_OUT      // LPTIM2 输出作为DFSDM外部触发
#define DFSDM_FILTER_EXT_TRIG_LPTIM3               DFSDM_FILTER_EXT_TRIG_LPTIM3_OUT      // LPTIM3 输出作为DFSDM外部触发

/* DAC 触发源定义 */
#define DAC_TRIGGER_LP1_OUT                        DAC_TRIGGER_LPTIM1_OUT                // LPTIM1 输出作为DAC触发源
#define DAC_TRIGGER_LP2_OUT                        DAC_TRIGGER_LPTIM2_OUT                // LPTIM2 输出作为DAC触发源

#endif /* STM32H7 */

#if defined(STM32U5)
#define GPDMA1_REQUEST_DCMI                        GPDMA1_REQUEST_DCMI_PSSI              // DCMI/PSSI 请求映射到 GPDMA1
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Defines HAL FLASH Aliased Defines maintained for legacy purpose
  * @{
  */

/* FLASH 编程类型定义 */
#define TYPEPROGRAM_BYTE              FLASH_TYPEPROGRAM_BYTE             // 字节编程(8位)
#define TYPEPROGRAM_HALFWORD          FLASH_TYPEPROGRAM_HALFWORD         // 半字编程(16位)
#define TYPEPROGRAM_WORD              FLASH_TYPEPROGRAM_WORD             // 字编程(32位)
#define TYPEPROGRAM_DOUBLEWORD        FLASH_TYPEPROGRAM_DOUBLEWORD       // 双字编程(64位)

/* FLASH 擦除类型定义 */
#define TYPEERASE_SECTORS             FLASH_TYPEERASE_SECTORS            // 扇区擦除
#define TYPEERASE_PAGES               FLASH_TYPEERASE_PAGES              // 页擦除
#define TYPEERASE_PAGEERASE           FLASH_TYPEERASE_PAGES              // 页擦除(旧名称兼容)
#define TYPEERASE_MASSERASE           FLASH_TYPEERASE_MASSERASE          // 全片擦除(批量擦除)

/* 写保护状态定义 */
#define WRPSTATE_DISABLE              OB_WRPSTATE_DISABLE                // 禁止写保护
#define WRPSTATE_ENABLE               OB_WRPSTATE_ENABLE                 // 使能写保护

/* FLASH 操作超时值定义 */
#define HAL_FLASH_TIMEOUT_VALUE       FLASH_TIMEOUT_VALUE                // Flash操作超时时间

/* 选项字节扩展定义 */
#define OBEX_PCROP                    OPTIONBYTE_PCROP                   // PCROP(专有代码读出保护)配置
#define OBEX_BOOTCONFIG               OPTIONBYTE_BOOTCONFIG              // 启动配置

/* PCROP 状态定义 */
#define PCROPSTATE_DISABLE            OB_PCROP_STATE_DISABLE             // 禁止 PCROP
#define PCROPSTATE_ENABLE             OB_PCROP_STATE_ENABLE              // 使能 PCROP

/* FLASH 数据擦除类型定义 */
#define TYPEERASEDATA_BYTE            FLASH_TYPEERASEDATA_BYTE           // 擦除数据-字节
#define TYPEERASEDATA_HALFWORD        FLASH_TYPEERASEDATA_HALFWORD       // 擦除数据-半字
#define TYPEERASEDATA_WORD            FLASH_TYPEERASEDATA_WORD           // 擦除数据-字

/* FLASH 数据编程类型定义 */
#define TYPEPROGRAMDATA_BYTE          FLASH_TYPEPROGRAMDATA_BYTE         // 编程数据-字节
#define TYPEPROGRAMDATA_HALFWORD      FLASH_TYPEPROGRAMDATA_HALFWORD     // 编程数据-半字
#define TYPEPROGRAMDATA_WORD          FLASH_TYPEPROGRAMDATA_WORD         // 编程数据-字
#define TYPEPROGRAMDATA_FASTBYTE      FLASH_TYPEPROGRAMDATA_FASTBYTE     // 快速编程-字节
#define TYPEPROGRAMDATA_FASTHALFWORD  FLASH_TYPEPROGRAMDATA_FASTHALFWORD // 快速编程-半字
#define TYPEPROGRAMDATA_FASTWORD      FLASH_TYPEPROGRAMDATA_FASTWORD     // 快速编程-字

#if !defined(STM32F2) && !defined(STM32F4) && !defined(STM32F7) && !defined(STM32H7)
#define PAGESIZE                      FLASH_PAGE_SIZE                    // Flash 页大小定义
#endif /* STM32F2 && STM32F4 && STM32F7 &&  STM32H7 */

/* 快速编程类型定义(兼容旧名称) */
#define TYPEPROGRAM_FASTBYTE          FLASH_TYPEPROGRAM_BYTE             // 快速字节编程
#define TYPEPROGRAM_FASTHALFWORD      FLASH_TYPEPROGRAM_HALFWORD         // 快速半字编程
#define TYPEPROGRAM_FASTWORD          FLASH_TYPEPROGRAM_WORD             // 快速字编程

/* FLASH 电压范围定义，用于擦除/编程操作 */
#define VOLTAGE_RANGE_1               FLASH_VOLTAGE_RANGE_1              // 电压范围1 (例如 2.7V - 3.6V)
#define VOLTAGE_RANGE_2               FLASH_VOLTAGE_RANGE_2              // 电压范围2
#define VOLTAGE_RANGE_3               FLASH_VOLTAGE_RANGE_3              // 电压范围3
#define VOLTAGE_RANGE_4               FLASH_VOLTAGE_RANGE_4              // 电压范围4 (例如 1.8V - 2.1V)

/* FLASH 快速编程定义 */
#define TYPEPROGRAM_FAST              FLASH_TYPEPROGRAM_FAST             // 快速编程
#define TYPEPROGRAM_FAST_AND_LAST     FLASH_TYPEPROGRAM_FAST_AND_LAST    // 快速编程且为最后一个

/* 写保护区域定义 */
#define WRPAREA_BANK1_AREAA           OB_WRPAREA_BANK1_AREAA             // Bank1 区域A 写保护
#define WRPAREA_BANK1_AREAB           OB_WRPAREA_BANK1_AREAB             // Bank1 区域B 写保护
#define WRPAREA_BANK2_AREAA           OB_WRPAREA_BANK2_AREAA             // Bank2 区域A 写保护
#define WRPAREA_BANK2_AREAB           OB_WRPAREA_BANK2_AREAB             // Bank2 区域B 写保护

/* 独立看门狗(IWDG)在低功耗模式下的行为定义 */
#define IWDG_STDBY_FREEZE             OB_IWDG_STDBY_FREEZE               // 待机模式下冻结IWDG
#define IWDG_STDBY_ACTIVE             OB_IWDG_STDBY_RUN                  // 待机模式下IWDG继续运行
#define IWDG_STOP_FREEZE              OB_IWDG_STOP_FREEZE                // 停止模式下冻结IWDG
#define IWDG_STOP_ACTIVE              OB_IWDG_STOP_RUN                   // 停止模式下IWDG继续运行

/* FLASH 错误标志定义 */
#define FLASH_ERROR_NONE              HAL_FLASH_ERROR_NONE               // 无错误
#define FLASH_ERROR_RD                HAL_FLASH_ERROR_RD                 // 读取错误
#define FLASH_ERROR_PG                HAL_FLASH_ERROR_PROG               // 编程错误
#define FLASH_ERROR_PGP               HAL_FLASH_ERROR_PGS                // 编程顺序错误
#define FLASH_ERROR_WRP               HAL_FLASH_ERROR_WRP                // 写保护错误
#define FLASH_ERROR_OPTV              HAL_FLASH_ERROR_OPTV               // 选项字节有效性错误
#define FLASH_ERROR_OPTVUSR           HAL_FLASH_ERROR_OPTVUSR            // 选项字节用户有效性错误
#define FLASH_ERROR_PROG              HAL_FLASH_ERROR_PROG               // 编程错误
#define FLASH_ERROR_OP                HAL_FLASH_ERROR_OPERATION          // 操作错误
#define FLASH_ERROR_PGA               HAL_FLASH_ERROR_PGA                // 编程对齐错误
#define FLASH_ERROR_SIZE              HAL_FLASH_ERROR_SIZE               // 大小错误
#define FLASH_ERROR_SIZ               HAL_FLASH_ERROR_SIZE               // 大小错误(旧名称)
#define FLASH_ERROR_PGS               HAL_FLASH_ERROR_PGS                // 编程顺序错误
#define FLASH_ERROR_MIS               HAL_FLASH_ERROR_MIS                // 快速编程数据丢失错误
#define FLASH_ERROR_FAST              HAL_FLASH_ERROR_FAST               // 快速编程错误
#define FLASH_ERROR_FWWERR            HAL_FLASH_ERROR_FWWERR             // 写/写错误
#define FLASH_ERROR_NOTZERO           HAL_FLASH_ERROR_NOTZERO            // 非零错误(擦除区域非0xFF)
#define FLASH_ERROR_OPERATION         HAL_FLASH_ERROR_OPERATION          // 操作错误
#define FLASH_ERROR_ERS               HAL_FLASH_ERROR_ERS                // 擦除错误

/* 选项字节：看门狗配置 */
#define OB_WDG_SW                     OB_IWDG_SW                         // 软件看门狗
#define OB_WDG_HW                     OB_IWDG_HW                         // 硬件看门狗

/* 选项字节：SDADC VDD监控配置 */
#define OB_SDADC12_VDD_MONITOR_SET    OB_SDACD_VDD_MONITOR_SET           // 设置 SDADC12 VDD 监控
#define OB_SDADC12_VDD_MONITOR_RESET  OB_SDACD_VDD_MONITOR_RESET         // 复位 SDADC12 VDD 监控

/* 选项字节：RAM奇偶校验配置 */
#define OB_RAM_PARITY_CHECK_SET       OB_SRAM_PARITY_SET                 // 使能 SRAM 奇偶校验
#define OB_RAM_PARITY_CHECK_RESET     OB_SRAM_PARITY_RESET               // 禁止 SRAM 奇偶校验
#define IS_OB_SDADC12_VDD_MONITOR     IS_OB_SDACD_VDD_MONITOR            // 检查参数宏

/* 选项字节：读保护(RDP)等级定义 */
#define OB_RDP_LEVEL0                 OB_RDP_LEVEL_0                     // 等级0 (无保护)
#define OB_RDP_LEVEL1                 OB_RDP_LEVEL_1                     // 等级1 (读保护)
#define OB_RDP_LEVEL2                 OB_RDP_LEVEL_2                     // 等级2 (永久保护)

#if defined(STM32G0) || defined(STM32C0)
#define OB_BOOT_LOCK_DISABLE          OB_BOOT_ENTRY_FORCED_NONE          // 解锁启动，不从Flash强制启动
#define OB_BOOT_LOCK_ENABLE           OB_BOOT_ENTRY_FORCED_FLASH         // 锁定启动，强制从Flash启动
#else
#define OB_BOOT_ENTRY_FORCED_NONE     OB_BOOT_LOCK_DISABLE               // 不强制启动入口
#define OB_BOOT_ENTRY_FORCED_FLASH    OB_BOOT_LOCK_ENABLE                // 强制从Flash启动
#endif

#if defined(STM32H7)
/* STM32H7 系列 Flash 标志别名 */
#define FLASH_FLAG_SNECCE_BANK1RR     FLASH_FLAG_SNECCERR_BANK1          // Bank1 单比特ECC错误
#define FLASH_FLAG_DBECCE_BANK1RR     FLASH_FLAG_DBECCERR_BANK1          // Bank1 双比特ECC错误
#define FLASH_FLAG_STRBER_BANK1R      FLASH_FLAG_STRBERR_BANK1           // Bank1 选通错误
#define FLASH_FLAG_SNECCE_BANK2RR     FLASH_FLAG_SNECCERR_BANK2          // Bank2 单比特ECC错误
#define FLASH_FLAG_DBECCE_BANK2RR     FLASH_FLAG_DBECCERR_BANK2          // Bank2 双比特ECC错误
#define FLASH_FLAG_STRBER_BANK2R      FLASH_FLAG_STRBERR_BANK2           // Bank2 选通错误
#define FLASH_FLAG_WDW                FLASH_FLAG_WBNE                    // 写缓冲非空标志
#define OB_WRP_SECTOR_All             OB_WRP_SECTOR_ALL                  // 所有扇区写保护
#endif /* STM32H7 */

#if defined(STM32U5)
/* STM32U5 系列 选项字节别名 */
#define OB_USER_nRST_STOP             OB_USER_NRST_STOP                  // 停止模式复位配置
#define OB_USER_nRST_STDBY            OB_USER_NRST_STDBY                 // 待机模式复位配置
#define OB_USER_nRST_SHDW             OB_USER_NRST_SHDW                  // 关断模式复位配置
#define OB_USER_nSWBOOT0              OB_USER_NSWBOOT0                   // 软件BOOT0配置
#define OB_USER_nBOOT0                OB_USER_NBOOT0                     // BOOT0引脚配置
#define OB_nBOOT0_RESET               OB_NBOOT0_RESET                    // nBOOT0 复位
#define OB_nBOOT0_SET                 OB_NBOOT0_SET                      // nBOOT0 置位
#define OB_USER_SRAM134_RST           OB_USER_SRAM_RST                   // SRAM复位配置
#define OB_SRAM134_RST_ERASE          OB_SRAM_RST_ERASE                  // SRAM复位时擦除
#define OB_SRAM134_RST_NOT_ERASE      OB_SRAM_RST_NOT_ERASE              // SRAM复位时不擦除
#endif /* STM32U5 */

#if defined(STM32U0)
/* STM32U0 系列 选项字节别名 */
#define OB_USER_nRST_STOP             OB_USER_NRST_STOP                  // 停止模式复位配置
#define OB_USER_nRST_STDBY            OB_USER_NRST_STDBY                 // 待机模式复位配置
#define OB_USER_nRST_SHDW             OB_USER_NRST_SHDW                  // 关断模式复位配置
#define OB_USER_nBOOT_SEL             OB_USER_NBOOT_SEL                  // BOOT选择
#define OB_USER_nBOOT0                OB_USER_NBOOT0                     // BOOT0配置
#define OB_USER_nBOOT1                OB_USER_NBOOT1                     // BOOT1配置
#define OB_nBOOT0_RESET               OB_NBOOT0_RESET                    // nBOOT0 复位
#define OB_nBOOT0_SET                 OB_NBOOT0_SET                      // nBOOT0 置位
#endif /* STM32U0 */

/**
  * @}
  */

/** @defgroup HAL_JPEG_Aliased_Macros HAL JPEG Aliased Macros maintained for legacy purpose
  * @{
  */

#if defined(STM32H7)
/* STM32H7 系列 JPEG 时钟控制宏别名 */
#define __HAL_RCC_JPEG_CLK_ENABLE               __HAL_RCC_JPGDECEN_CLK_ENABLE        // 使能 JPEG 解码时钟
#define __HAL_RCC_JPEG_CLK_DISABLE              __HAL_RCC_JPGDECEN_CLK_DISABLE       // 禁止 JPEG 解码时钟
#define __HAL_RCC_JPEG_FORCE_RESET              __HAL_RCC_JPGDECRST_FORCE_RESET      // 强制复位 JPEG
#define __HAL_RCC_JPEG_RELEASE_RESET            __HAL_RCC_JPGDECRST_RELEASE_RESET    // 释放复位 JPEG
#define __HAL_RCC_JPEG_CLK_SLEEP_ENABLE         __HAL_RCC_JPGDEC_CLK_SLEEP_ENABLE    // 睡眠模式下使能 JPEG 时钟
#define __HAL_RCC_JPEG_CLK_SLEEP_DISABLE        __HAL_RCC_JPGDEC_CLK_SLEEP_DISABLE   // 睡眠模式下禁止 JPEG 时钟
#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_SYSCFG_Aliased_Defines HAL SYSCFG Aliased Defines maintained for legacy purpose
  * @{
  */

/* SYSCFG I2C 快速模式Plus 配置定义 */
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA9    I2C_FASTMODEPLUS_PA9                // PA9 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA10   I2C_FASTMODEPLUS_PA10               // PA10 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB6    I2C_FASTMODEPLUS_PB6                // PB6 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB7    I2C_FASTMODEPLUS_PB7                // PB7 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB8    I2C_FASTMODEPLUS_PB8                // PB8 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB9    I2C_FASTMODEPLUS_PB9                // PB9 引脚 I2C 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C1       I2C_FASTMODEPLUS_I2C1               // I2C1 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C2       I2C_FASTMODEPLUS_I2C2               // I2C2 快速模式Plus
#define HAL_SYSCFG_FASTMODEPLUS_I2C3       I2C_FASTMODEPLUS_I2C3               // I2C3 快速模式Plus

#if defined(STM32G4)
/* STM32G4 系列 IO 模拟开关配置 */
#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SYSCFG_EnableIOSwitchBooster   // 使能 IO 模拟开关增强器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SYSCFG_DisableIOSwitchBooster  // 禁止 IO 模拟开关增强器
#define HAL_SYSCFG_EnableIOAnalogSwitchVDD        HAL_SYSCFG_EnableIOSwitchVDD       // 使能 IO 模拟开关 VDD
#define HAL_SYSCFG_DisableIOAnalogSwitchVDD       HAL_SYSCFG_DisableIOSwitchVDD      // 禁止 IO 模拟开关 VDD
#endif /* STM32G4 */

#if defined(STM32H5)
/* STM32H5 系列 SYSCFG 中断定义 */
#define SYSCFG_IT_FPU_IOC         SBS_IT_FPU_IOC                      // FPU 无效操作中断
#define SYSCFG_IT_FPU_DZC         SBS_IT_FPU_DZC                      // FPU 除零中断
#define SYSCFG_IT_FPU_UFC         SBS_IT_FPU_UFC                      // FPU 下溢中断
#define SYSCFG_IT_FPU_OFC         SBS_IT_FPU_OFC                      // FPU 上溢中断
#define SYSCFG_IT_FPU_IDC         SBS_IT_FPU_IDC                      // FPU 不精确中断
#define SYSCFG_IT_FPU_IXC         SBS_IT_FPU_IXC                      // FPU 不精确累加中断

/* SYSCFG 断点定义 */
#define SYSCFG_BREAK_FLASH_ECC    SBS_BREAK_FLASH_ECC                 // Flash ECC 错误断点
#define SYSCFG_BREAK_PVD          SBS_BREAK_PVD                       // PVD 阈值检测断点
#define SYSCFG_BREAK_SRAM_ECC     SBS_BREAK_SRAM_ECC                  // SRAM ECC 错误断点
#define SYSCFG_BREAK_LOCKUP       SBS_BREAK_LOCKUP                    // 内核锁定断点

/* SYSCFG VREFBUF 电压范围定义 */
#define SYSCFG_VREFBUF_VOLTAGE_SCALE0   VREFBUF_VOLTAGE_SCALE0        // 电压范围0
#define SYSCFG_VREFBUF_VOLTAGE_SCALE1   VREFBUF_VOLTAGE_SCALE1        // 电压范围1
#define SYSCFG_VREFBUF_VOLTAGE_SCALE2   VREFBUF_VOLTAGE_SCALE2        // 电压范围2
#define SYSCFG_VREFBUF_VOLTAGE_SCALE3   VREFBUF_VOLTAGE_SCALE3        // 电压范围3

/* SYSCFG VREFBUF 高阻抗模式定义 */
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE   VREFBUF_HIGH_IMPEDANCE_DISABLE  // 禁止高阻抗模式
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE    VREFBUF_HIGH_IMPEDANCE_ENABLE   // 使能高阻抗模式

/* SYSCFG I2C 快速模式Plus 引脚定义 */
#define SYSCFG_FASTMODEPLUS_PB6   SBS_FASTMODEPLUS_PB6                // PB6 快速模式Plus
#define SYSCFG_FASTMODEPLUS_PB7   SBS_FASTMODEPLUS_PB7                // PB7 快速模式Plus
#define SYSCFG_FASTMODEPLUS_PB8   SBS_FASTMODEPLUS_PB8                // PB8 快速模式Plus
#define SYSCFG_FASTMODEPLUS_PB9   SBS_FASTMODEPLUS_PB9                // PB9 快速模式Plus

/* SYSCFG 以太网接口选择 */
#define SYSCFG_ETH_MII   SBS_ETH_MII                                    // 选择 MII 接口
#define SYSCFG_ETH_RMII  SBS_ETH_RMII                                   // 选择 RMII 接口
#define IS_SYSCFG_ETHERNET_CONFIG  IS_SBS_ETHERNET_CONFIG               // 检查参数宏

/* SYSCFG 内存擦除标志 */
#define SYSCFG_MEMORIES_ERASE_FLAG_IPMEE   SBS_MEMORIES_ERASE_FLAG_IPMEE    // IPMEE 擦除标志
#define SYSCFG_MEMORIES_ERASE_FLAG_MCLR    SBS_MEMORIES_ERASE_FLAG_MCLR     // MCLR 擦除标志
#define IS_SYSCFG_MEMORIES_ERASE_FLAG      IS_SBS_MEMORIES_ERASE_FLAG       // 检查参数宏

#define IS_SYSCFG_CODE_CONFIG IS_SBS_CODE_CONFIG                          // 检查代码配置参数宏

/* SYSCFG 安全属性配置 */
#define SYSCFG_MPU_NSEC   SBS_MPU_NSEC                                  // MPU 非安全配置
#define SYSCFG_VTOR_NSEC  SBS_VTOR_NSEC                                 // VTOR 非安全配置

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
/* 安全扩展相关定义 (CMSE = 3) */
#define SYSCFG_SAU              SBS_SAU                                 // SAU 配置
#define SYSCFG_MPU_SEC          SBS_MPU_SEC                             // MPU 安全配置
#define SYSCFG_VTOR_AIRCR_SEC   SBS_VTOR_AIRCR_SEC                      // VTOR/AIRCR 安全配置
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL                            // 锁定所有
#else
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL                            // 锁定所有
#endif /* __ARM_FEATURE_CMSE */

/* SYSCFG 时钟与功能定义 */
#define SYSCFG_CLK      SBS_CLK                                         // SYSCFG 时钟
#define SYSCFG_CLASSB   SBS_CLASSB                                      // Class B 功能
#define SYSCFG_FPU      SBS_FPU                                         // FPU 配置
#define SYSCFG_ALL      SBS_ALL                                         // 所有功能

#define SYSCFG_SEC      SBS_SEC                                         // 安全配置
#define SYSCFG_NSEC     SBS_NSEC                                        // 非安全配置

/* SYSCFG 宏定义别名 */
#define __HAL_SYSCFG_FPU_INTERRUPT_ENABLE   __HAL_SBS_FPU_INTERRUPT_ENABLE    // 使能 FPU 中断
#define __HAL_SYSCFG_FPU_INTERRUPT_DISABLE  __HAL_SBS_FPU_INTERRUPT_DISABLE   // 禁止 FPU 中断

#define __HAL_SYSCFG_BREAK_ECC_LOCK        __HAL_SBS_BREAK_ECC_LOCK           // 锁定 ECC 断点
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK     __HAL_SBS_BREAK_LOCKUP_LOCK        // 锁定 Lockup 断点
#define __HAL_SYSCFG_BREAK_PVD_LOCK        __HAL_SBS_BREAK_PVD_LOCK           // 锁定 PVD 断点
#define __HAL_SYSCFG_BREAK_SRAM_ECC_LOCK   __HAL_SBS_BREAK_SRAM_ECC_LOCK      // 锁定 SRAM ECC 断点

#define __HAL_SYSCFG_FASTMODEPLUS_ENABLE   __HAL_SBS_FASTMODEPLUS_ENABLE      // 使能快速模式Plus
#define __HAL_SYSCFG_FASTMODEPLUS_DISABLE  __HAL_SBS_FASTMODEPLUS_DISABLE     // 禁止快速模式Plus

#define __HAL_SYSCFG_GET_MEMORIES_ERASE_STATUS    __HAL_SBS_GET_MEMORIES_ERASE_STATUS   // 获取内存擦除状态
#define __HAL_SYSCFG_CLEAR_MEMORIES_ERASE_STATUS  __HAL_SBS_CLEAR_MEMORIES_ERASE_STATUS // 清除内存擦除状态

/* 参数检查宏定义 */
#define IS_SYSCFG_FPU_INTERRUPT    IS_SBS_FPU_INTERRUPT
#define IS_SYSCFG_BREAK_CONFIG     IS_SBS_BREAK_CONFIG
#define IS_SYSCFG_VREFBUF_VOLTAGE_SCALE     IS_VREFBUF_VOLTAGE_SCALE
#define IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE    IS_VREFBUF_HIGH_IMPEDANCE
#define IS_SYSCFG_VREFBUF_TRIMMING  IS_VREFBUF_TRIMMING
#define IS_SYSCFG_FASTMODEPLUS      IS_SBS_FASTMODEPLUS
#define IS_SYSCFG_ITEMS_ATTRIBUTES  IS_SBS_ITEMS_ATTRIBUTES
#define IS_SYSCFG_ATTRIBUTES        IS_SBS_ATTRIBUTES
#define IS_SYSCFG_LOCK_ITEMS        IS_SBS_LOCK_ITEMS

/* HAL 函数别名定义 */
#define HAL_SYSCFG_VREFBUF_VoltageScalingConfig   HAL_VREFBUF_VoltageScalingConfig   // VREFBUF 电压缩放配置
#define HAL_SYSCFG_VREFBUF_HighImpedanceConfig    HAL_VREFBUF_HighImpedanceConfig    // VREFBUF 高阻抗配置
#define HAL_SYSCFG_VREFBUF_TrimmingConfig         HAL_VREFBUF_TrimmingConfig         // VREFBUF 修剪配置
#define HAL_SYSCFG_EnableVREFBUF                  HAL_EnableVREFBUF                  // 使能 VREFBUF
#define HAL_SYSCFG_DisableVREFBUF                 HAL_DisableVREFBUF                 // 禁止 VREFBUF

#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SBS_EnableIOAnalogSwitchBooster   // 使能 IO 模拟开关增强器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SBS_DisableIOAnalogSwitchBooster  // 禁止 IO 模拟开关增强器
#define HAL_SYSCFG_ETHInterfaceSelect             HAL_SBS_ETHInterfaceSelect            // 以太网接口选择

#define HAL_SYSCFG_Lock     HAL_SBS_Lock                                              // 锁定 SYSCFG
#define HAL_SYSCFG_GetLock  HAL_SBS_GetLock                                           // 获取锁定状态

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define HAL_SYSCFG_ConfigAttributes     HAL_SBS_ConfigAttributes                   // 配置属性(安全模式)
#define HAL_SYSCFG_GetConfigAttributes  HAL_SBS_GetConfigAttributes                 // 获取配置属性(安全模式)
#endif /* __ARM_FEATURE_CMSE */

#endif /* STM32H5 */


/**
  * @}
  */


/** @defgroup LL_FMC_Aliased_Defines LL FMC Aliased Defines maintained for compatibility purpose
  * @{
  */
/* FMC NAND/PCC 等待特性及总线宽度定义 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)
#define FMC_NAND_PCC_WAIT_FEATURE_DISABLE       FMC_NAND_WAIT_FEATURE_DISABLE       // 禁止等待特性
#define FMC_NAND_PCC_WAIT_FEATURE_ENABLE        FMC_NAND_WAIT_FEATURE_ENABLE        // 使能等待特性
#define FMC_NAND_PCC_MEM_BUS_WIDTH_8            FMC_NAND_MEM_BUS_WIDTH_8            // 8位总线宽度
#define FMC_NAND_PCC_MEM_BUS_WIDTH_16           FMC_NAND_MEM_BUS_WIDTH_16           // 16位总线宽度
#elif defined(STM32F1) || defined(STM32F2) || defined(STM32F3) || defined(STM32F4)
#define FMC_NAND_WAIT_FEATURE_DISABLE           FMC_NAND_PCC_WAIT_FEATURE_DISABLE   // 禁止等待特性(旧名称)
#define FMC_NAND_WAIT_FEATURE_ENABLE            FMC_NAND_PCC_WAIT_FEATURE_ENABLE    // 使能等待特性(旧名称)
#define FMC_NAND_MEM_BUS_WIDTH_8                FMC_NAND_PCC_MEM_BUS_WIDTH_8        // 8位总线宽度(旧名称)
#define FMC_NAND_MEM_BUS_WIDTH_16               FMC_NAND_PCC_MEM_BUS_WIDTH_16       // 16位总线宽度(旧名称)
#endif
/**
  * @}
  */

/** @defgroup LL_FSMC_Aliased_Defines LL FSMC Aliased Defines maintained for legacy purpose
  * @{
  */

/* FSMC NOR/SRAM 类型定义 */
#define FSMC_NORSRAM_TYPEDEF                      FSMC_NORSRAM_TypeDef             // FSMC NOR/SRAM 寄存器结构体类型
#define FSMC_NORSRAM_EXTENDED_TYPEDEF             FSMC_NORSRAM_EXTENDED_TypeDef    // FSMC NOR/SRAM 扩展寄存器结构体类型
/**
  * @}
  */

/** @defgroup HAL_GPIO_Aliased_Macros HAL GPIO Aliased Macros maintained for legacy purpose
  * @{
  */
/* GPIO 引脚源/索引获取宏 */
#define GET_GPIO_SOURCE                           GPIO_GET_INDEX                    // 获取 GPIO 源(旧名称)
#define GET_GPIO_INDEX                            GPIO_GET_INDEX                    // 获取 GPIO 索引

#if defined(STM32F4)
/* STM32F4 系列 GPIO 复用功能定义 */
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDIO                    // SDIO 复用功能12
#define GPIO_AF12_SDMMC1                          GPIO_AF12_SDIO                    // SDMMC1 复用功能12
#endif

#if defined(STM32F7)
/* STM32F7 系列 GPIO 复用功能定义 */
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#endif

#if defined(STM32L4)
/* STM32L4 系列 GPIO 复用功能定义 */
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#endif

#if defined(STM32H7)
/* STM32H7 系列 GPIO 复用功能定义 */
#define GPIO_AF7_SDIO1                            GPIO_AF7_SDMMC1                   // SDMMC1 复用功能7
#define GPIO_AF8_SDIO1                            GPIO_AF8_SDMMC1                   // SDMMC1 复用功能8
#define GPIO_AF12_SDIO1                           GPIO_AF12_SDMMC1                  // SDMMC1 复用功能12
#define GPIO_AF9_SDIO2                            GPIO_AF9_SDMMC2                   // SDMMC2 复用功能9
#define GPIO_AF10_SDIO2                           GPIO_AF10_SDMMC2                  // SDMMC2 复用功能10
#define GPIO_AF11_SDIO2                           GPIO_AF11_SDMMC2                  // SDMMC2 复用功能11

#if defined (STM32H743xx) || defined (STM32H753xx)  || defined (STM32H750xx) || defined (STM32H742xx) || \
    defined (STM32H745xx) || defined (STM32H755xx)  || defined (STM32H747xx) || defined (STM32H757xx)
/* STM32H7 特定型号 OTG 复用功能定义 */
#define GPIO_AF10_OTG2_HS  GPIO_AF10_OTG2_FS                                         // OTG2 高速/全速
#define GPIO_AF10_OTG1_FS  GPIO_AF10_OTG1_HS                                         // OTG1 全速/高速
#define GPIO_AF12_OTG2_FS  GPIO_AF12_OTG1_FS                                         // OTG2/OTG1 全速
#endif /*STM32H743xx || STM32H753xx || STM32H750xx || STM32H742xx || STM32H745xx || STM32H755xx || STM32H747xx || \
         STM32H757xx */
#endif /* STM32H7 */

/* LPTIM 复用功能定义 */
#define GPIO_AF0_LPTIM                            GPIO_AF0_LPTIM1                   // LPTIM1 复用功能0
#define GPIO_AF1_LPTIM                            GPIO_AF1_LPTIM1                   // LPTIM1 复用功能1
#define GPIO_AF2_LPTIM                            GPIO_AF2_LPTIM1                   // LPTIM1 复用功能2

/* GPIO 速度定义 */
#if defined(STM32L0) || defined(STM32L4) || defined(STM32F4) || defined(STM32F2) || defined(STM32F7) || \
    defined(STM32G4) || defined(STM32H7) || defined(STM32WB) || defined(STM32U5)
#define  GPIO_SPEED_LOW                           GPIO_SPEED_FREQ_LOW               // 低速
#define  GPIO_SPEED_MEDIUM                        GPIO_SPEED_FREQ_MEDIUM            // 中速
#define  GPIO_SPEED_FAST                          GPIO_SPEED_FREQ_HIGH              // 快速(高速)
#define  GPIO_SPEED_HIGH                          GPIO_SPEED_FREQ_VERY_HIGH         // 高速(极高速)
#endif /* STM32L0 || STM32L4 || STM32F4 || STM32F2 || STM32F7 || STM32G4 || STM32H7 || STM32WB || STM32U5*/

#if defined(STM32L1)
/* STM32L1 系列 GPIO 速度定义 */
#define  GPIO_SPEED_VERY_LOW    GPIO_SPEED_FREQ_LOW                                 // 极低速
#define  GPIO_SPEED_LOW         GPIO_SPEED_FREQ_MEDIUM                              // 低速
#define  GPIO_SPEED_MEDIUM      GPIO_SPEED_FREQ_HIGH                                // 中速
#define  GPIO_SPEED_HIGH        GPIO_SPEED_FREQ_VERY_HIGH                           // 高速
#endif /* STM32L1 */
#if defined(STM32F0) || defined(STM32F3) || defined(STM32F1)
// 以下宏定义是为了兼容旧版本的GPIO速度枚举命名，将LOW/MEDIUM/HIGH映射到新的FREQ命名方式
#define  GPIO_SPEED_LOW    GPIO_SPEED_FREQ_LOW        // 定义GPIO速度为低频（旧命名兼容）
#define  GPIO_SPEED_MEDIUM GPIO_SPEED_FREQ_MEDIUM     // 定义GPIO速度为中频（旧命名兼容）
#define  GPIO_SPEED_HIGH   GPIO_SPEED_FREQ_HIGH       // 定义GPIO速度为高频（旧命名兼容）
#endif /* STM32F0 || STM32F3 || STM32F1 */

// GPIO复用功能定义：将DFSDM宏映射到DFSDM1
#define GPIO_AF6_DFSDM                            GPIO_AF6_DFSDM1

#if defined(STM32U5) || defined(STM32H5)
// GPIO复用功能定义：RTC 50Hz时钟输出，兼容大小写命名
#define GPIO_AF0_RTC_50Hz                         GPIO_AF0_RTC_50HZ
#endif /* STM32U5 || STM32H5 */
#if defined(STM32U5)
// GPIO复用功能定义：停止模式相关定义别名
#define GPIO_AF0_S2DSTOP                          GPIO_AF0_SRDSTOP
// GPIO复用功能定义：低功耗GPIO复用功能别名
#define GPIO_AF11_LPGPIO                          GPIO_AF11_LPGPIO1
#endif /* STM32U5 */

#if defined(STM32WBA)
// 以下宏定义针对STM32WBA系列，将具体的RF(射频)引脚功能统一映射到通用的GPIO_AF11_RF
#define GPIO_AF11_RF_ANTSW0    GPIO_AF11_RF        // 射频天线开关0
#define GPIO_AF11_RF_ANTSW1    GPIO_AF11_RF        // 射频天线开关1
#define GPIO_AF11_RF_ANTSW2    GPIO_AF11_RF        // 射频天线开关2
#define GPIO_AF11_RF_IO1       GPIO_AF11_RF        // 射频IO1
#define GPIO_AF11_RF_IO2       GPIO_AF11_RF        // 射频IO2
#define GPIO_AF11_RF_IO3       GPIO_AF11_RF        // 射频IO3
#define GPIO_AF11_RF_IO4       GPIO_AF11_RF        // 射频IO4
#define GPIO_AF11_RF_IO5       GPIO_AF11_RF        // 射频IO5
#define GPIO_AF11_RF_IO6       GPIO_AF11_RF        // 射频IO6
#define GPIO_AF11_RF_IO7       GPIO_AF11_RF        // 射频IO7
#define GPIO_AF11_RF_IO8       GPIO_AF11_RF        // 射频IO8
#define GPIO_AF11_RF_IO9       GPIO_AF11_RF        // 射频IO9
#endif /* STM32WBA */
/**
  * @}
  */

/** @defgroup HAL_GTZC_Aliased_Defines HAL GTZC Aliased Defines maintained for legacy purpose
  * @{
  */
#if defined(STM32U5)
// GTZC(全局信任区控制器)外设定义别名，用于兼容旧命名
#define GTZC_PERIPH_DCMI                      GTZC_PERIPH_DCMI_PSSI    // DCMI外设别名
#define GTZC_PERIPH_LTDC                      GTZC_PERIPH_LTDCUSB      // LTDC外设别名
#endif /* STM32U5 */
#if defined(STM32H5)
// GTZC外设定义别名，针对STM32H5系列
#define GTZC_PERIPH_DAC12                     GTZC_PERIPH_DAC1         // DAC1/2外设别名
#define GTZC_PERIPH_ADC12                     GTZC_PERIPH_ADC          // ADC1/2外设别名
#define GTZC_PERIPH_USBFS                     GTZC_PERIPH_USB          // USB全速设备别名
#endif /* STM32H5 */
#if defined(STM32H5) || defined(STM32U5)
// GTZC MPCBB(存储保护控制块)相关配置别名，修正了拼写错误(MCPBB -> MPCBB)并保持兼容性
#define GTZC_MCPBB_NB_VCTR_REG_MAX            GTZC_MPCBB_NB_VCTR_REG_MAX            // 最大向量寄存器数量
#define GTZC_MCPBB_NB_LCK_VCTR_REG_MAX        GTZC_MPCBB_NB_LCK_VCTR_REG_MAX        // 最大锁定向量寄存器数量
#define GTZC_MCPBB_SUPERBLOCK_UNLOCKED        GTZC_MPCBB_SUPERBLOCK_UNLOCKED        // 超级块未锁定状态
#define GTZC_MCPBB_SUPERBLOCK_LOCKED          GTZC_MPCBB_SUPERBLOCK_LOCKED          // 超级块锁定状态
#define GTZC_MCPBB_BLOCK_NSEC                 GTZC_MPCBB_BLOCK_NSEC                 // 块非安全属性
#define GTZC_MCPBB_BLOCK_SEC                  GTZC_MPCBB_BLOCK_SEC                  // 块安全属性
#define GTZC_MCPBB_BLOCK_NPRIV                GTZC_MPCBB_BLOCK_NPRIV                // 块非特权访问
#define GTZC_MCPBB_BLOCK_PRIV                 GTZC_MPCBB_BLOCK_PRIV                 // 块特权访问
#define GTZC_MCPBB_LOCK_OFF                   GTZC_MPCBB_LOCK_OFF                   // 锁定关闭
#define GTZC_MCPBB_LOCK_ON                    GTZC_MPCBB_LOCK_ON                    // 锁定开启
#endif /* STM32H5 || STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Macros HAL HRTIM Aliased Macros maintained for legacy purpose
  * @{
  */
// HRTIM(高分辨率定时器)延迟保护模式别名定义
#define HRTIM_TIMDELAYEDPROTECTION_DISABLED           HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DISABLED            // 禁用延迟保护
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_EEV6    // 延迟输出1，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_EEV6    // 延迟输出2，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV6    // 延迟两者，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV68     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV6       // 平衡模式，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_DEEV7   // 延迟输出1，去抖动外部事件7/9
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_DEEV7   // 延迟输出2，去抖动外部事件7/9
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV79  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV7    // 延迟两者，外部事件7/9
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV79     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV7       // 平衡模式，外部事件7/9

// HRTIM 寄存器操作宏别名，统一命名风格（大小写兼容）
#define __HAL_HRTIM_SetCounter        __HAL_HRTIM_SETCOUNTER        // 设置计数器值
#define __HAL_HRTIM_GetCounter        __HAL_HRTIM_GETCOUNTER        // 获取计数器值
#define __HAL_HRTIM_SetPeriod         __HAL_HRTIM_SETPERIOD         // 设置周期值
#define __HAL_HRTIM_GetPeriod         __HAL_HRTIM_GETPERIOD         // 获取周期值
#define __HAL_HRTIM_SetClockPrescaler __HAL_HRTIM_SETCLOCKPRESCALER // 设置时钟预分频
#define __HAL_HRTIM_GetClockPrescaler __HAL_HRTIM_GETCLOCKPRESCALER // 获取时钟预分频
#define __HAL_HRTIM_SetCompare        __HAL_HRTIM_SETCOMPARE        // 设置比较值
#define __HAL_HRTIM_GetCompare        __HAL_HRTIM_GETCOMPARE        // 获取比较值

#if defined(STM32G4)
// HRTIM 外部事件计数器配置相关函数别名，针对STM32G4系列
#define HAL_HRTIM_ExternalEventCounterConfig    HAL_HRTIM_ExtEventCounterConfig    // 配置外部事件计数器
#define HAL_HRTIM_ExternalEventCounterEnable    HAL_HRTIM_ExtEventCounterEnable    // 使能外部事件计数器
#define HAL_HRTIM_ExternalEventCounterDisable   HAL_HRTIM_ExtEventCounterDisable   // 禁用外部事件计数器
#define HAL_HRTIM_ExternalEventCounterReset     HAL_HRTIM_ExtEventCounterReset     // 复位外部事件计数器
// HRTIM 事件计数器相关定义
#define HRTIM_TIMEEVENT_A                       HRTIM_EVENTCOUNTER_A               // 事件计数器A
#define HRTIM_TIMEEVENT_B                       HRTIM_EVENTCOUNTER_B               // 事件计数器B
#define HRTIM_TIMEEVENTRESETMODE_UNCONDITIONAL  HRTIM_EVENTCOUNTER_RSTMODE_UNCONDITIONAL // 无条件复位模式
#define HRTIM_TIMEEVENTRESETMODE_CONDITIONAL    HRTIM_EVENTCOUNTER_RSTMODE_CONDITIONAL   // 有条件复位模式
#endif /* STM32G4 */

#if defined(STM32H7)
// HRTIM 输出设置/复位事件定义，针对STM32H7系列
// 这些宏定义了定时器之间的交叉触发事件，用于设置输出
#define HRTIM_OUTPUTSET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器A输出设置事件1：定时器B比较1
#define HRTIM_OUTPUTSET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2    // 定时器A输出设置事件2：定时器B比较2
#define HRTIM_OUTPUTSET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3    // 定时器A输出设置事件3：定时器C比较2
#define HRTIM_OUTPUTSET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4    // 定时器A输出设置事件4：定时器C比较3
#define HRTIM_OUTPUTSET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5    // 定时器A输出设置事件5：定时器D比较1
#define HRTIM_OUTPUTSET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6    // 定时器A输出设置事件6：定时器D比较2
#define HRTIM_OUTPUTSET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7    // 定时器A输出设置事件7：定时器E比较3
#define HRTIM_OUTPUTSET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8    // 定时器A输出设置事件8：定时器E比较4
#define HRTIM_OUTPUTSET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9    // 定时器A输出设置事件9：定时器F比较4
#define HRTIM_OUTPUTSET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器B输出设置事件1：定时器A比较1
#define HRTIM_OUTPUTSET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2    // 定时器B输出设置事件2：定时器A比较2
#define HRTIM_OUTPUTSET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3    // 定时器B输出设置事件3：定时器C比较3
#define HRTIM_OUTPUTSET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4    // 定时器B输出设置事件4：定时器C比较4
#define HRTIM_OUTPUTSET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5    // 定时器B输出设置事件5：定时器D比较3
#define HRTIM_OUTPUTSET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6    // 定时器B输出设置事件6：定时器D比较4
#define HRTIM_OUTPUTSET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7    // 定时器B输出设置事件7：定时器E比较1
#define HRTIM_OUTPUTSET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8    // 定时器B输出设置事件8：定时器E比较2
#define HRTIM_OUTPUTSET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9    // 定时器B输出设置事件9：定时器F比较3
#define HRTIM_OUTPUTSET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器C输出设置事件1：定时器A比较1
#define HRTIM_OUTPUTSET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2    // 定时器C输出设置事件2：定时器A比较2
#define HRTIM_OUTPUTSET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3    // 定时器C输出设置事件3：定时器B比较2
#define HRTIM_OUTPUTSET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4    // 定时器C输出设置事件4：定时器B比较3
#define HRTIM_OUTPUTSET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5    // 定时器C输出设置事件5：定时器D比较2
#define HRTIM_OUTPUTSET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6    // 定时器C输出设置事件6：定时器D比较4
#define HRTIM_OUTPUTSET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7    // 定时器C输出设置事件7：定时器E比较3
#define HRTIM_OUTPUTSET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8    // 定时器C输出设置事件8：定时器E比较4
#define HRTIM_OUTPUTSET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9    // 定时器C输出设置事件9：定时器F比较2
#define HRTIM_OUTPUTSET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器D输出设置事件1：定时器A比较1
#define HRTIM_OUTPUTSET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2    // 定时器D输出设置事件2：定时器A比较4
#define HRTIM_OUTPUTSET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3    // 定时器D输出设置事件3：定时器B比较2
#define HRTIM_OUTPUTSET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4    // 定时器D输出设置事件4：定时器B比较4
#define HRTIM_OUTPUTSET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5    // 定时器D输出设置事件5：定时器C比较4
#define HRTIM_OUTPUTSET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6    // 定时器D输出设置事件6：定时器E比较1
#define HRTIM_OUTPUTSET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7    // 定时器D输出设置事件7：定时器E比较4
#define HRTIM_OUTPUTSET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8    // 定时器D输出设置事件8：定时器F比较1
#define HRTIM_OUTPUTSET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9    // 定时器D输出设置事件9：定时器F比较3
#define HRTIM_OUTPUTSET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1    // 定时器E输出设置事件1：定时器A比较4
#define HRTIM_OUTPUTSET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2    // 定时器E输出设置事件2：定时器B比较3
#define HRTIM_OUTPUTSET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3    // 定时器E输出设置事件3：定时器B比较4
#define HRTIM_OUTPUTSET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4    // 定时器E输出设置事件4：定时器C比较1
#define HRTIM_OUTPUTSET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5    // 定时器E输出设置事件5：定时器D比较2
#define HRTIM_OUTPUTSET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6    // 定时器E输出设置事件6：定时器D比较1
#define HRTIM_OUTPUTSET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7    // 定时器E输出设置事件7：定时器D比较2
#define HRTIM_OUTPUTSET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8    // 定时器E输出设置事件8：定时器F比较3
#define HRTIM_OUTPUTSET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9    // 定时器E输出设置事件9：定时器F比较4
#define HRTIM_OUTPUTSET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1    // 定时器F输出设置事件1：定时器A比较3
#define HRTIM_OUTPUTSET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2    // 定时器F输出设置事件2：定时器B比较1
#define HRTIM_OUTPUTSET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3    // 定时器F输出设置事件3：定时器B比较4
#define HRTIM_OUTPUTSET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4    // 定时器F输出设置事件4：定时器C比较1
#define HRTIM_OUTPUTSET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5    // 定时器F输出设置事件5：定时器C比较4
#define HRTIM_OUTPUTSET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6    // 定时器F输出设置事件6：定时器D比较3
#define HRTIM_OUTPUTSET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7    // 定时器F输出设置事件7：定时器D比较4
#define HRTIM_OUTPUTSET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8    // 定时器F输出设置事件8：定时器E比较2
#define HRTIM_OUTPUTSET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9    // 定时器F输出设置事件9：定时器E比较3

// HRTIM 输出复位事件定义，逻辑与设置事件类似，用于复位输出
#define HRTIM_OUTPUTRESET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9
#endif /* STM32H7 */

#if defined(STM32F3)
/** @brief Constants defining available sources associated to external events.
  * @brief 定义与外部事件相关的可用源的常量
  */
#define HRTIM_EVENTSRC_1              (0x00000000U)    // 事件源1
#define HRTIM_EVENTSRC_2              (HRTIM_EECR1_EE1SRC_0)    // 事件源2
#define HRTIM_EVENTSRC_3              (HRTIM_EECR1_EE1SRC_1)    // 事件源3
#define HRTIM_EVENTSRC_4              (HRTIM_EECR1_EE1SRC_1 | HRTIM_EECR1_EE1SRC_0)    // 事件源4

/** @brief Constants defining the DLL calibration periods (in micro seconds)
  * @brief 定义DLL校准周期的常量（单位：微秒）
  */
#define HRTIM_CALIBRATIONRATE_7300             0x00000000U    // 校准周期7300us
#define HRTIM_CALIBRATIONRATE_910              (HRTIM_DLLCR_CALRTE_0)    // 校准周期910us
#define HRTIM_CALIBRATIONRATE_114              (HRTIM_DLLCR_CALRTE_1)    // 校准周期114us
#define HRTIM_CALIBRATIONRATE_14               (HRTIM_DLLCR_CALRTE_1 | HRTIM_DLLCR_CALRTE_0)    // 校准周期14us

#endif /* STM32F3 */
/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Defines HAL I2C Aliased Defines maintained for legacy purpose
  * @{
  */
// I2C 配置参数别名，将旧的 ENABLED/DISABLED 命名映射到新的 ENABLE/DISABLE
#define I2C_DUALADDRESS_DISABLED                I2C_DUALADDRESS_DISABLE    // 禁用双地址模式
#define I2C_DUALADDRESS_ENABLED                 I2C_DUALADDRESS_ENABLE     // 使能双地址模式
#define I2C_GENERALCALL_DISABLED                I2C_GENERALCALL_DISABLE    // 禁用通用呼叫
#define I2C_GENERALCALL_ENABLED                 I2C_GENERALCALL_ENABLE     // 使能通用呼叫
#define I2C_NOSTRETCH_DISABLED                  I2C_NOSTRETCH_DISABLE      // 禁用时钟拉伸
#define I2C_NOSTRETCH_ENABLED                   I2C_NOSTRETCH_ENABLE       // 使能时钟拉伸
#define I2C_ANALOGFILTER_ENABLED                I2C_ANALOGFILTER_ENABLE    // 使能模拟滤波器
#define I2C_ANALOGFILTER_DISABLED               I2C_ANALOGFILTER_DISABLE   // 禁用模拟滤波器
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F3) || defined(STM32G0) || defined(STM32L4) || \
    defined(STM32L1) || defined(STM32F7)
// I2C 状态枚举别名，统一状态命名
#define HAL_I2C_STATE_MEM_BUSY_TX               HAL_I2C_STATE_BUSY_TX      // 存储器发送忙状态
#define HAL_I2C_STATE_MEM_BUSY_RX               HAL_I2C_STATE_BUSY_RX      // 存储器接收忙状态
#define HAL_I2C_STATE_MASTER_BUSY_TX            HAL_I2C_STATE_BUSY_TX      // 主机发送忙状态
#define HAL_I2C_STATE_MASTER_BUSY_RX            HAL_I2C_STATE_BUSY_RX      // 主机接收忙状态
#define HAL_I2C_STATE_SLAVE_BUSY_TX             HAL_I2C_STATE_BUSY_TX      // 从机发送忙状态
#define HAL_I2C_STATE_SLAVE_BUSY_RX             HAL_I2C_STATE_BUSY_RX      // 从机接收忙状态
#endif
/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Defines HAL IRDA Aliased Defines maintained for legacy purpose
  * @{
  */
// IRDA(红外数据协会)模块配置别名
#define IRDA_ONE_BIT_SAMPLE_DISABLED            IRDA_ONE_BIT_SAMPLE_DISABLE    // 禁用单比特采样
#define IRDA_ONE_BIT_SAMPLE_ENABLED             IRDA_ONE_BIT_SAMPLE_ENABLE     // 使能单比特采样

/**
  * @}
  */

/** @defgroup HAL_IWDG_Aliased_Defines HAL IWDG Aliased Defines maintained for legacy purpose
  * @{
  */
// IWDG(独立看门狗)键值定义别名
#define KR_KEY_RELOAD                   IWDG_KEY_RELOAD            // 重载键值
#define KR_KEY_ENABLE                   IWDG_KEY_ENABLE            // 使能键值
#define KR_KEY_EWA                      IWDG_KEY_WRITE_ACCESS_ENABLE    // 使能写访问键值
#define KR_KEY_DWA                      IWDG_KEY_WRITE_ACCESS_DISABLE   // 禁用写访问键值
/**
  * @}
  */

/** @defgroup HAL_LPTIM_Aliased_Defines HAL LPTIM Aliased Defines maintained for legacy purpose
  * @{
  */

// LPTIM(低功耗定时器)时钟采样时间定义，修正拼写错误 TRANSISTION -> TRANSITION
#define LPTIM_CLOCKSAMPLETIME_DIRECTTRANSISTION LPTIM_CLOCKSAMPLETIME_DIRECTTRANSITION    // 直接转换时钟采样时间
#define LPTIM_CLOCKSAMPLETIME_2TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_2TRANSITIONS        // 2次转换时钟采样时间
#define LPTIM_CLOCKSAMPLETIME_4TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_4TRANSITIONS        // 4次转换时钟采样时间
#define LPTIM_CLOCKSAMPLETIME_8TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_8TRANSITIONS        // 8次转换时钟采样时间

// LPTIM 时钟极性定义别名
#define LPTIM_CLOCKPOLARITY_RISINGEDGE          LPTIM_CLOCKPOLARITY_RISING            // 上升沿
#define LPTIM_CLOCKPOLARITY_FALLINGEDGE         LPTIM_CLOCKPOLARITY_FALLING           // 下降沿
#define LPTIM_CLOCKPOLARITY_BOTHEDGES           LPTIM_CLOCKPOLARITY_RISING_FALLING    // 双沿

// LPTIM 触发采样时间定义，修正拼写错误
#define LPTIM_TRIGSAMPLETIME_DIRECTTRANSISTION  LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION    // 直接转换触发采样时间
#define LPTIM_TRIGSAMPLETIME_2TRANSISTIONS      LPTIM_TRIGSAMPLETIME_2TRANSITIONS        // 2次转换触发采样时间
#define LPTIM_TRIGSAMPLETIME_4TRANSISTIONS      LPTIM_TRIGSAMPLETIME_4TRANSITIONS        // 4次转换触发采样时间
#define LPTIM_TRIGSAMPLETIME_8TRANSISTIONS      LPTIM_TRIGSAMPLETIME_8TRANSITIONS        // 8次转换触发采样时间

/* The following 3 definition have also been present in a temporary version of lptim.h */
/* They need to be renamed also to the right name, just in case */
/* 以下3个定义也曾出现在lptim.h的临时版本中，为了以防万一，也需要重命名为正确的名称 */
#define LPTIM_TRIGSAMPLETIME_2TRANSITION        LPTIM_TRIGSAMPLETIME_2TRANSITIONS
#define LPTIM_TRIGSAMPLETIME_4TRANSITION        LPTIM_TRIGSAMPLETIME_4TRANSITIONS
#define LPTIM_TRIGSAMPLETIME_8TRANSITION        LPTIM_TRIGSAMPLETIME_8TRANSITIONS


/** @defgroup HAL_LPTIM_Aliased_Defines HAL LPTIM Aliased Defines maintained for legacy purpose
  * @{
  */
// LPTIM 函数别名，将读取比较值函数映射为读取捕获值函数
#define HAL_LPTIM_ReadCompare      HAL_LPTIM_ReadCapturedValue
/**
  * @}
  */

#if defined(STM32U5)
// LPTIM 中断状态标志定义，针对STM32U5系列
#define LPTIM_ISR_CC1        LPTIM_ISR_CC1IF    // 捕获/比较1中断标志
#define LPTIM_ISR_CC2        LPTIM_ISR_CC2IF    // 捕获/比较2中断标志
#define LPTIM_CHANNEL_ALL    0x00000000U        // 所有通道
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_NAND_Aliased_Defines HAL NAND Aliased Defines maintained for legacy purpose
  * @{
  */
// NAND Flash 驱动函数别名，默认映射为8位宽度操作函数
#define HAL_NAND_Read_Page              HAL_NAND_Read_Page_8b        // 读取页（8位）
#define HAL_NAND_Write_Page             HAL_NAND_Write_Page_8b       // 写入页（8位）
#define HAL_NAND_Read_SpareArea         HAL_NAND_Read_SpareArea_8b   // 读取备用区（8位）
#define HAL_NAND_Write_SpareArea        HAL_NAND_Write_SpareArea_8b  // 写入备用区（8位）

// NAND Flash 类型定义别名
#define NAND_AddressTypedef             NAND_AddressTypeDef          // NAND地址结构体类型别名

// NAND Flash 宏定义别名，移除前导下划线以符合命名规范
#define __ARRAY_ADDRESS                 ARRAY_ADDRESS                // 数组地址宏
#define __ADDR_1st_CYCLE                ADDR_1ST_CYCLE               // 地址第1周期
#define __ADDR_2nd_CYCLE                ADDR_2ND_CYCLE               // 地址第2周期
#define __ADDR_3rd_CYCLE                ADDR_3RD_CYCLE               // 地址第3周期
#define __ADDR_4th_CYCLE                ADDR_4TH_CYCLE               // 地址第4周期
/**
  * @}
  */

/** @defgroup HAL_NOR_Aliased_Defines HAL NOR Aliased Defines maintained for legacy purpose
  * @{
  */
// NOR Flash 状态类型定义别名
#define NOR_StatusTypedef              HAL_NOR_StatusTypeDef         // NOR状态枚举类型别名
#define NOR_SUCCESS                    HAL_NOR_STATUS_SUCCESS        // 操作成功
#define NOR_ONGOING                    HAL_NOR_STATUS_ONGOING        // 操作进行中
#define NOR_ERROR                      HAL_NOR_STATUS_ERROR          // 操作错误
#define NOR_TIMEOUT                    HAL_NOR_STATUS_TIMEOUT        // 操作超时

// NOR Flash 宏定义别名
#define __NOR_WRITE                    NOR_WRITE                     // NOR写操作宏
#define __NOR_ADDR_SHIFT               NOR_ADDR_SHIFT                // NOR地址移位宏
/**
  * @}
  */

/** @defgroup HAL_OPAMP_Aliased_Defines HAL OPAMP Aliased Defines maintained for legacy purpose
  * @{
  */

// 运算放大器(OPAMP)输入引脚定义别名，将VPx/VMx映射到IOx命名方式
#define OPAMP_NONINVERTINGINPUT_VP0           OPAMP_NONINVERTINGINPUT_IO0    // 同相输入端IO0
#define OPAMP_NONINVERTINGINPUT_VP1           OPAMP_NONINVERTINGINPUT_IO1    // 同相输入端IO1
#define OPAMP_NONINVERTINGINPUT_VP2           OPAMP_NONINVERTINGINPUT_IO2    // 同相输入端IO2
#define OPAMP_NONINVERTINGINPUT_VP3           OPAMP_NONINVERTINGINPUT_IO3    // 同相输入端IO3

// 运算放大器次级同相输入引脚定义别名
#define OPAMP_SEC_NONINVERTINGINPUT_VP0       OPAMP_SEC_NONINVERTINGINPUT_IO0    // 次级同相输入端IO0
#define OPAMP_SEC_NONINVERTINGINPUT_VP1       OPAMP_SEC_NONINVERTINGINPUT_IO1    // 次级同相输入端IO1
#define OPAMP_SEC_NONINVERTINGINPUT_VP2       OPAMP_SEC_NONINVERTINGINPUT_IO2    // 次级同相输入端IO2
#define OPAMP_SEC_NONINVERTINGINPUT_VP3       OPAMP_SEC_NONINVERTINGINPUT_IO3    // 次级同相输入端IO3

// 运算放大器反相输入引脚定义别名
#define OPAMP_INVERTINGINPUT_VM0              OPAMP_INVERTINGINPUT_IO0    // 反相输入端IO0
#define OPAMP_INVERTINGINPUT_VM1              OPAMP_INVERTINGINPUT_IO1    // 反相输入端IO1

// 运算放大器反相输入引脚定义别名（IOPAMP前缀）
#define IOPAMP_INVERTINGINPUT_VM0             OPAMP_INVERTINGINPUT_IO0    // 反相输入端IO0
#define IOPAMP_INVERTINGINPUT_VM1             OPAMP_INVERTINGINPUT_IO1    // 反相输入端IO1

// 运算放大器次级反相输入引脚定义别名
#define OPAMP_SEC_INVERTINGINPUT_VM0          OPAMP_SEC_INVERTINGINPUT_IO0    // 次级反相输入端IO0
#define OPAMP_SEC_INVERTINGINPUT_VM1          OPAMP_SEC_INVERTINGINPUT_IO1    // 次级反相输入端IO1

// 运算放大器反相输入引脚别名
#define OPAMP_INVERTINGINPUT_VINM             OPAMP_SEC_INVERTINGINPUT_IO1    // 反相输入端VINM

// 运算放大器PGA(可编程增益放大器)连接模式定义
#define OPAMP_PGACONNECT_NO                   OPAMP_PGA_CONNECT_INVERTINGINPUT_NO    // PGA不连接反相输入
#define OPAMP_PGACONNECT_VM0                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO0   // PGA连接反相输入IO0
#define OPAMP_PGACONNECT_VM1                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO1   // PGA连接反相输入IO1

#if defined(STM32L1) || defined(STM32L4) || defined(STM32L5) || defined(STM32H7) || defined(STM32G4) || defined(STM32U5)
// 运算放大器 MSP 回调函数 ID 定义别名
#define HAL_OPAMP_MSP_INIT_CB_ID       HAL_OPAMP_MSPINIT_CB_ID       // MSP初始化回调ID
#define HAL_OPAMP_MSP_DEINIT_CB_ID     HAL_OPAMP_MSPDEINIT_CB_ID     // MSP反初始化回调ID
#endif

#if defined(STM32L4) || defined(STM32L5)
// 运算放大器功耗模式定义，针对STM32L4/L5系列
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALPOWER    // 正常功耗模式
#elif defined(STM32G4)
// 运算放大器功耗模式定义，针对STM32G4系列
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALSPEED    // 正常速度模式
#endif

/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Defines HAL I2S Aliased Defines maintained for legacy purpose
  * @{
  */
// I2S 标准定义别名，修正拼写错误 PHILLIPS -> PHILIPS
#define I2S_STANDARD_PHILLIPS      I2S_STANDARD_PHILIPS

#if defined(STM32H7)
// I2S 中断标志定义别名，针对STM32H7系列
#define I2S_IT_TXE               I2S_IT_TXP    // 发送缓冲区空中断
#define I2S_IT_RXNE              I2S_IT_RXP    // 接收缓冲区非空中断
#define I2S_FLAG_TXE             I2S_FLAG_TXP // I2S发送缓冲区为空标志，映射为TXP标志
#define I2S_FLAG_RXNE            I2S_FLAG_RXP // I2S接收缓冲区非空标志，映射为RXP标志
#endif

#if defined(STM32F7)
#define I2S_CLOCK_SYSCLK           I2S_CLOCK_PLL // 对于STM32F7系列，定义I2S系统时钟源为PLL
#endif
/**
  * @}
  */

/** @defgroup HAL_PCCARD_Aliased_Defines HAL PCCARD Aliased Defines maintained for legacy purpose
  * @{
  */

/* Compact Flash-ATA registers description */
// 以下是Compact Flash(CF卡)与ATA接口寄存器的宏定义别名映射
#define CF_DATA                       ATA_DATA // 数据寄存器
#define CF_SECTOR_COUNT               ATA_SECTOR_COUNT // 扇区计数寄存器
#define CF_SECTOR_NUMBER              ATA_SECTOR_NUMBER // 扇区号寄存器
#define CF_CYLINDER_LOW               ATA_CYLINDER_LOW // 柱面低字节寄存器
#define CF_CYLINDER_HIGH              ATA_CYLINDER_HIGH // 柱面高字节寄存器
#define CF_CARD_HEAD                  ATA_CARD_HEAD // 卡/磁头寄存器
#define CF_STATUS_CMD                 ATA_STATUS_CMD // 状态/命令寄存器
#define CF_STATUS_CMD_ALTERNATE       ATA_STATUS_CMD_ALTERNATE // 备用状态/命令寄存器
#define CF_COMMON_DATA_AREA           ATA_COMMON_DATA_AREA // 公共数据区域

/* Compact Flash-ATA commands */
// CF卡/ATA标准命令宏定义别名映射
#define CF_READ_SECTOR_CMD            ATA_READ_SECTOR_CMD // 读扇区命令
#define CF_WRITE_SECTOR_CMD           ATA_WRITE_SECTOR_CMD // 写扇区命令
#define CF_ERASE_SECTOR_CMD           ATA_ERASE_SECTOR_CMD // 擦除扇区命令
#define CF_IDENTIFY_CMD               ATA_IDENTIFY_CMD // 识别设备命令

// PCCARD状态类型定义，用于兼容旧代码
#define PCCARD_StatusTypedef          HAL_PCCARD_StatusTypeDef // PCCARD状态类型别名
#define PCCARD_SUCCESS                HAL_PCCARD_STATUS_SUCCESS // 操作成功
#define PCCARD_ONGOING                HAL_PCCARD_STATUS_ONGOING // 操作正在进行中
#define PCCARD_ERROR                  HAL_PCCARD_STATUS_ERROR // 操作错误
#define PCCARD_TIMEOUT                HAL_PCCARD_STATUS_TIMEOUT // 操作超时
/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Defines HAL RTC Aliased Defines maintained for legacy purpose
  * @{
  */

// RTC(实时时钟)相关宏定义别名映射
#define FORMAT_BIN                  RTC_FORMAT_BIN // 二进制格式
#define FORMAT_BCD                  RTC_FORMAT_BCD // BCD码格式

#define RTC_ALARMSUBSECONDMASK_None     RTC_ALARMSUBSECONDMASK_NONE // 闹钟子秒无掩码
#define RTC_TAMPERERASEBACKUP_DISABLED  RTC_TAMPER_ERASE_BACKUP_DISABLE // 篡改事件禁止擦除备份寄存器
#define RTC_TAMPERMASK_FLAG_DISABLED    RTC_TAMPERMASK_FLAG_DISABLE // 禁止篡改标志掩码
#define RTC_TAMPERMASK_FLAG_ENABLED     RTC_TAMPERMASK_FLAG_ENABLE // 使能篡改标志掩码

#define RTC_MASKTAMPERFLAG_DISABLED     RTC_TAMPERMASK_FLAG_DISABLE // 禁止篡改标志掩码(旧名称)
#define RTC_MASKTAMPERFLAG_ENABLED      RTC_TAMPERMASK_FLAG_ENABLE // 使能篡改标志掩码(旧名称)
#define RTC_TAMPERERASEBACKUP_ENABLED   RTC_TAMPER_ERASE_BACKUP_ENABLE // 篡改事件使能擦除备份寄存器
#define RTC_TAMPER1_2_INTERRUPT         RTC_ALL_TAMPER_INTERRUPT // 篡改1和2中断
#define RTC_TAMPER1_2_3_INTERRUPT       RTC_ALL_TAMPER_INTERRUPT // 篡改1、2和3中断

// RTC时间戳引脚映射定义
#define RTC_TIMESTAMPPIN_PC13  RTC_TIMESTAMPPIN_DEFAULT // 时间戳引脚PC13(默认)
#define RTC_TIMESTAMPPIN_PA0   RTC_TIMESTAMPPIN_POS1 // 时间戳引脚PA0(位置1)
#define RTC_TIMESTAMPPIN_PI8   RTC_TIMESTAMPPIN_POS1 // 时间戳引脚PI8(位置1)
#define RTC_TIMESTAMPPIN_PC1   RTC_TIMESTAMPPIN_POS2 // 时间戳引脚PC1(位置2)

// RTC输出重映射定义
#define RTC_OUTPUT_REMAP_PC13  RTC_OUTPUT_REMAP_NONE // 输出重映射到PC13(无重映射)
#define RTC_OUTPUT_REMAP_PB14  RTC_OUTPUT_REMAP_POS1 // 输出重映射到PB14(位置1)
#define RTC_OUTPUT_REMAP_PB2   RTC_OUTPUT_REMAP_POS1 // 输出重映射到PB2(位置1)

// RTC篡改检测引脚映射定义
#define RTC_TAMPERPIN_PC13 RTC_TAMPERPIN_DEFAULT // 篡改引脚PC13(默认)
#define RTC_TAMPERPIN_PA0  RTC_TAMPERPIN_POS1 // 篡改引脚PA0(位置1)
#define RTC_TAMPERPIN_PI8  RTC_TAMPERPIN_POS1 // 篡改引脚PI8(位置1)

#if defined(STM32H5) || defined(STM32H7RS)
// 篡改检测秘密设备擦除配置(针对STM32H5/H7RS系列)
#define TAMP_SECRETDEVICE_ERASE_NONE        TAMP_DEVICESECRETS_ERASE_NONE // 不擦除
#define TAMP_SECRETDEVICE_ERASE_BKP_SRAM    TAMP_DEVICESECRETS_ERASE_BKPSRAM // 擦除备份SRAM
#endif /* STM32H5 || STM32H7RS */

#if defined(STM32WBA)
// 篡改检测秘密设备擦除配置(针对STM32WBA系列)
#define TAMP_SECRETDEVICE_ERASE_NONE            TAMP_DEVICESECRETS_ERASE_NONE // 不擦除
#define TAMP_SECRETDEVICE_ERASE_SRAM2           TAMP_DEVICESECRETS_ERASE_SRAM2 // 擦除SRAM2
#define TAMP_SECRETDEVICE_ERASE_RHUK            TAMP_DEVICESECRETS_ERASE_RHUK // 擦除RHUK
#define TAMP_SECRETDEVICE_ERASE_ICACHE          TAMP_DEVICESECRETS_ERASE_ICACHE // 擦除指令缓存
#define TAMP_SECRETDEVICE_ERASE_SAES_AES_HASH   TAMP_DEVICESECRETS_ERASE_SAES_AES_HASH // 擦除SAES/AES/Hash
#define TAMP_SECRETDEVICE_ERASE_PKA_SRAM        TAMP_DEVICESECRETS_ERASE_PKA_SRAM // 擦除PKA SRAM
#define TAMP_SECRETDEVICE_ERASE_ALL             TAMP_DEVICESECRETS_ERASE_ALL // 擦除所有
#endif /* STM32WBA */

#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
// 篡改检测秘密设备擦除使能/禁止配置
#define TAMP_SECRETDEVICE_ERASE_DISABLE     TAMP_DEVICESECRETS_ERASE_NONE // 禁止擦除
#define TAMP_SECRETDEVICE_ERASE_ENABLE      TAMP_SECRETDEVICE_ERASE_ALL // 使能擦除(擦除所有)
#endif /* STM32H5 || STM32WBA || STM32H7RS */

#if defined(STM32F7)
// STM32F7系列篡改控制寄存器位定义
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_ENABLE_BITS_MASK // 篡改使能位掩码
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_IT_ENABLE_BITS_MASK // 篡改中断使能位掩码
#endif /* STM32F7 */

#if defined(STM32H7)
// STM32H7系列篡改控制寄存器位定义
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_X // 篡改X
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_X_INTERRUPT // 篡改X中断
#endif /* STM32H7 */

#if defined(STM32F7) || defined(STM32H7) || defined(STM32L0)
// 篡改中断定义
#define RTC_TAMPER1_INTERRUPT      RTC_IT_TAMP1 // 篡改1中断
#define RTC_TAMPER2_INTERRUPT      RTC_IT_TAMP2 // 篡改2中断
#define RTC_TAMPER3_INTERRUPT      RTC_IT_TAMP3 // 篡改3中断
#define RTC_ALL_TAMPER_INTERRUPT   RTC_IT_TAMP // 所有篡改中断
#endif /* STM32F7 || STM32H7 || STM32L0 */

/**
  * @}
  */


/** @defgroup HAL_SMARTCARD_Aliased_Defines HAL SMARTCARD Aliased Defines maintained for legacy purpose
  * @{
  */
// 智能卡相关配置别名定义
#define SMARTCARD_NACK_ENABLED                  SMARTCARD_NACK_ENABLE // 使能NACK
#define SMARTCARD_NACK_DISABLED                 SMARTCARD_NACK_DISABLE // 禁止NACK

#define SMARTCARD_ONEBIT_SAMPLING_DISABLED      SMARTCARD_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_ENABLED       SMARTCARD_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_DISABLE       SMARTCARD_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define SMARTCARD_ONEBIT_SAMPLING_ENABLE        SMARTCARD_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样

#define SMARTCARD_TIMEOUT_DISABLED              SMARTCARD_TIMEOUT_DISABLE // 禁止超时
#define SMARTCARD_TIMEOUT_ENABLED               SMARTCARD_TIMEOUT_ENABLE // 使能超时

#define SMARTCARD_LASTBIT_DISABLED              SMARTCARD_LASTBIT_DISABLE // 禁止最后一位
#define SMARTCARD_LASTBIT_ENABLED               SMARTCARD_LASTBIT_ENABLE // 使能最后一位
/**
  * @}
  */


/** @defgroup HAL_SMBUS_Aliased_Defines HAL SMBUS Aliased Defines maintained for legacy purpose
  * @{
  */
// SMBUS(系统管理总线)相关配置别名定义
#define SMBUS_DUALADDRESS_DISABLED      SMBUS_DUALADDRESS_DISABLE // 禁止双地址模式
#define SMBUS_DUALADDRESS_ENABLED       SMBUS_DUALADDRESS_ENABLE // 使能双地址模式
#define SMBUS_GENERALCALL_DISABLED      SMBUS_GENERALCALL_DISABLE // 禁止广播呼叫
#define SMBUS_GENERALCALL_ENABLED       SMBUS_GENERALCALL_ENABLE // 使能广播呼叫
#define SMBUS_NOSTRETCH_DISABLED        SMBUS_NOSTRETCH_DISABLE // 禁止时钟延长
#define SMBUS_NOSTRETCH_ENABLED         SMBUS_NOSTRETCH_ENABLE // 使能时钟延长
#define SMBUS_ANALOGFILTER_ENABLED      SMBUS_ANALOGFILTER_ENABLE // 使能模拟滤波器
#define SMBUS_ANALOGFILTER_DISABLED     SMBUS_ANALOGFILTER_DISABLE // 禁止模拟滤波器
#define SMBUS_PEC_DISABLED              SMBUS_PEC_DISABLE // 禁止PEC(包错误检测)
#define SMBUS_PEC_ENABLED               SMBUS_PEC_ENABLE // 使能PEC
#define HAL_SMBUS_STATE_SLAVE_LISTEN    HAL_SMBUS_STATE_LISTEN // 从机监听状态
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Defines HAL SPI Aliased Defines maintained for legacy purpose
  * @{
  */
// SPI(串行外设接口)相关配置别名定义
#define SPI_TIMODE_DISABLED             SPI_TIMODE_DISABLE // 禁止TI模式
#define SPI_TIMODE_ENABLED              SPI_TIMODE_ENABLE // 使能TI模式

#define SPI_CRCCALCULATION_DISABLED     SPI_CRCCALCULATION_DISABLE // 禁止CRC计算
#define SPI_CRCCALCULATION_ENABLED      SPI_CRCCALCULATION_ENABLE // 使能CRC计算

#define SPI_NSS_PULSE_DISABLED          SPI_NSS_PULSE_DISABLE // 禁止NSS脉冲
#define SPI_NSS_PULSE_ENABLED           SPI_NSS_PULSE_ENABLE // 使能NSS脉冲

#if defined(STM32H7)
// STM32H7系列SPI标志位和中断别名定义
#define SPI_FLAG_TXE                    SPI_FLAG_TXP // 发送缓冲区为空标志 -> 发送包标志
#define SPI_FLAG_RXNE                   SPI_FLAG_RXP // 接收缓冲区非空标志 -> 接收包标志

#define SPI_IT_TXE                      SPI_IT_TXP // 发送中断 -> 发送包中断
#define SPI_IT_RXNE                     SPI_IT_RXP // 接收中断 -> 接收包中断

// SPI FIFO接收级别定义
#define SPI_FRLVL_EMPTY                 SPI_RX_FIFO_0PACKET // FIFO为空
#define SPI_FRLVL_QUARTER_FULL          SPI_RX_FIFO_1PACKET // FIFO 1/4满(1个包)
#define SPI_FRLVL_HALF_FULL             SPI_RX_FIFO_2PACKET // FIFO 1/2满(2个包)
#define SPI_FRLVL_FULL                  SPI_RX_FIFO_3PACKET // FIFO满(3个包)

#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
// TIM(定时器)相关配置别名定义
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK // 捕获/比较使能位掩码
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK // 捕获/比较互补输出使能位掩码

// DMA基地址定义，用于配置DMA传输定时器寄存器地址
#define TIM_DMABase_CR1                  TIM_DMABASE_CR1 // DMA基地址：控制寄存器1
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2 // DMA基地址：控制寄存器2
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR // DMA基地址：从模式控制寄存器
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER // DMA基地址：DMA/中断使能寄存器
#define TIM_DMABase_SR                   TIM_DMABASE_SR // DMA基地址：状态寄存器
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR // DMA基地址：事件产生寄存器
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1 // DMA基地址：捕获/比较模式寄存器1
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2 // DMA基地址：捕获/比较模式寄存器2
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER // DMA基地址：捕获/比较使能寄存器
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT // DMA基地址：计数器寄存器
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC // DMA基地址：预分频器寄存器
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR // DMA基地址：自动重装载寄存器
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR // DMA基地址：重复计数器寄存器
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1 // DMA基地址：捕获/比较寄存器1
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2 // DMA基地址：捕获/比较寄存器2
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3 // DMA基地址：捕获/比较寄存器3
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4 // DMA基地址：捕获/比较寄存器4
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR // DMA基地址：刹车和死区寄存器
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR // DMA基地址：DMA控制寄存器
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR // DMA基地址：DMA地址寄存器
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1 // DMA基地址：选项寄存器1
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3 // DMA基地址：捕获/比较模式寄存器3
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5 // DMA基地址：捕获/比较寄存器5
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6 // DMA基地址：捕获/比较寄存器6
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2 // DMA基地址：选项寄存器2
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3 // DMA基地址：选项寄存器3
#define TIM_DMABase_OR                   TIM_DMABASE_OR // DMA基地址：选项寄存器(通用)

// 定时器事件源定义
#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE // 更新事件
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1 // 捕获/比较1事件
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2 // 捕获/比较2事件
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3 // 捕获/比较3事件
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4 // 捕获/比较4事件
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM // COM事件
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER // 触发事件
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK // 刹车事件
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2 // 刹车2事件

// DMA突发传输长度定义
#define TIM_DMABurstLength_1Transfer     TIM_DMABURSTLENGTH_1TRANSFER // 1次传输
#define TIM_DMABurstLength_2Transfers    TIM_DMABURSTLENGTH_2TRANSFERS // 2次传输
#define TIM_DMABurstLength_3Transfers    TIM_DMABURSTLENGTH_3TRANSFERS // 3次传输
#define TIM_DMABurstLength_4Transfers    TIM_DMABURSTLENGTH_4TRANSFERS // 4次传输
#define TIM_DMABurstLength_5Transfers    TIM_DMABURSTLENGTH_5TRANSFERS // 5次传输
#define TIM_DMABurstLength_6Transfers    TIM_DMABURSTLENGTH_6TRANSFERS // 6次传输
#define TIM_DMABurstLength_7Transfers    TIM_DMABURSTLENGTH_7TRANSFERS // 7次传输
#define TIM_DMABurstLength_8Transfers    TIM_DMABURSTLENGTH_8TRANSFERS // 8次传输
#define TIM_DMABurstLength_9Transfers    TIM_DMABURSTLENGTH_9TRANSFERS // 9次传输
#define TIM_DMABurstLength_10Transfers   TIM_DMABURSTLENGTH_10TRANSFERS // 10次传输
#define TIM_DMABurstLength_11Transfers   TIM_DMABURSTLENGTH_11TRANSFERS // 11次传输
#define TIM_DMABurstLength_12Transfers   TIM_DMABURSTLENGTH_12TRANSFERS // 12次传输
#define TIM_DMABurstLength_13Transfers   TIM_DMABURSTLENGTH_13TRANSFERS // 13次传输
#define TIM_DMABurstLength_14Transfers   TIM_DMABURSTLENGTH_14TRANSFERS // 14次传输
#define TIM_DMABurstLength_15Transfers   TIM_DMABURSTLENGTH_15TRANSFERS // 15次传输
#define TIM_DMABurstLength_16Transfers   TIM_DMABURSTLENGTH_16TRANSFERS // 16次传输
#define TIM_DMABurstLength_17Transfers   TIM_DMABURSTLENGTH_17TRANSFERS // 17次传输
#define TIM_DMABurstLength_18Transfers   TIM_DMABURSTLENGTH_18TRANSFERS // 18次传输

#if defined(STM32L0)
// STM32L0系列TIM22输入捕获通道1 GPIO定义
#define TIM22_TI1_GPIO1   TIM22_TI1_GPIO // TIM22 TI1输入源GPIO1
#define TIM22_TI1_GPIO2   TIM22_TI1_GPIO // TIM22 TI1输入源GPIO2
#endif

#if defined(STM32F3)
// STM32F3系列霍尔传感器接口实例检查宏
#define IS_TIM_HALL_INTERFACE_INSTANCE   IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE
#endif

#if defined(STM32H7)
// STM32H7系列定时器外部触发和输入捕获复用功能定义
#define TIM_TIM1_ETR_COMP1_OUT        TIM_TIM1_ETR_COMP1 // TIM1 ETR输入来自比较器1输出
#define TIM_TIM1_ETR_COMP2_OUT        TIM_TIM1_ETR_COMP2 // TIM1 ETR输入来自比较器2输出
#define TIM_TIM8_ETR_COMP1_OUT        TIM_TIM8_ETR_COMP1 // TIM8 ETR输入来自比较器1输出
#define TIM_TIM8_ETR_COMP2_OUT        TIM_TIM8_ETR_COMP2 // TIM8 ETR输入来自比较器2输出
#define TIM_TIM2_ETR_COMP1_OUT        TIM_TIM2_ETR_COMP1 // TIM2 ETR输入来自比较器1输出
#define TIM_TIM2_ETR_COMP2_OUT        TIM_TIM2_ETR_COMP2 // TIM2 ETR输入来自比较器2输出
#define TIM_TIM3_ETR_COMP1_OUT        TIM_TIM3_ETR_COMP1 // TIM3 ETR输入来自比较器1输出
#define TIM_TIM1_TI1_COMP1_OUT        TIM_TIM1_TI1_COMP1 // TIM1 TI1输入来自比较器1输出
#define TIM_TIM8_TI1_COMP2_OUT        TIM_TIM8_TI1_COMP2 // TIM8 TI1输入来自比较器2输出
#define TIM_TIM2_TI4_COMP1_OUT        TIM_TIM2_TI4_COMP1 // TIM2 TI4输入来自比较器1输出
#define TIM_TIM2_TI4_COMP2_OUT        TIM_TIM2_TI4_COMP2 // TIM2 TI4输入来自比较器2输出
#define TIM_TIM2_TI4_COMP1COMP2_OUT   TIM_TIM2_TI4_COMP1_COMP2 // TIM2 TI4输入来自比较器1和2
#define TIM_TIM3_TI1_COMP1_OUT        TIM_TIM3_TI1_COMP1 // TIM3 TI1输入来自比较器1输出
#define TIM_TIM3_TI1_COMP2_OUT        TIM_TIM3_TI1_COMP2 // TIM3 TI1输入来自比较器2输出
#define TIM_TIM3_TI1_COMP1COMP2_OUT   TIM_TIM3_TI1_COMP1_COMP2 // TIM3 TI1输入来自比较器1和2
#endif

#if defined(STM32U5)
// STM32U5系列OCREF清除选择位定义
#define OCREF_CLEAR_SELECT_Pos       OCREF_CLEAR_SELECT_POS // 位置定义
#define OCREF_CLEAR_SELECT_Msk       OCREF_CLEAR_SELECT_MSK // 掩码定义
#endif
/**
  * @}
  */

/** @defgroup HAL_TSC_Aliased_Defines HAL TSC Aliased Defines maintained for legacy purpose
  * @{
  */
// TSC(触摸感应控制器)相关配置别名定义
#define TSC_SYNC_POL_FALL        TSC_SYNC_POLARITY_FALLING // 同步极性：下降沿
#define TSC_SYNC_POL_RISE_HIGH   TSC_SYNC_POLARITY_RISING // 同步极性：上升沿(高电平)
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Defines HAL UART Aliased Defines maintained for legacy purpose
  * @{
  */
// UART(通用异步收发传输器)相关配置别名定义
#define UART_ONEBIT_SAMPLING_DISABLED   UART_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define UART_ONEBIT_SAMPLING_ENABLED    UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样
#define UART_ONE_BIT_SAMPLE_DISABLED    UART_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样
#define UART_ONE_BIT_SAMPLE_ENABLED     UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样

#define __HAL_UART_ONEBIT_ENABLE        __HAL_UART_ONE_BIT_SAMPLE_ENABLE // 使能单比特采样宏
#define __HAL_UART_ONEBIT_DISABLE       __HAL_UART_ONE_BIT_SAMPLE_DISABLE // 禁止单比特采样宏

// UART波特率计算相关宏定义(16倍过采样)
#define __DIV_SAMPLING16                UART_DIV_SAMPLING16 // 16倍过采样分频系数
#define __DIVMANT_SAMPLING16            UART_DIVMANT_SAMPLING16 // 16倍过采样分频系数整数部分
#define __DIVFRAQ_SAMPLING16            UART_DIVFRAQ_SAMPLING16 // 16倍过采样分频系数小数部分
#define __UART_BRR_SAMPLING16           UART_BRR_SAMPLING16 // 16倍过采样波特率寄存器值

// UART波特率计算相关宏定义(8倍过采样)
#define __DIV_SAMPLING8                 UART_DIV_SAMPLING8 // 8倍过采样分频系数
#define __DIVMANT_SAMPLING8             UART_DIVMANT_SAMPLING8 // 8倍过采样分频系数整数部分
#define __DIVFRAQ_SAMPLING8             UART_DIVFRAQ_SAMPLING8 // 8倍过采样分频系数小数部分
#define __UART_BRR_SAMPLING8            UART_BRR_SAMPLING8 // 8倍过采样波特率寄存器值

// LPUART(低功耗UART)波特率计算宏
#define __DIV_LPUART                    UART_DIV_LPUART // LPUART分频系数

// UART唤醒方式定义
#define UART_WAKEUPMETHODE_IDLELINE     UART_WAKEUPMETHOD_IDLELINE // 空闲线路唤醒
#define UART_WAKEUPMETHODE_ADDRESSMARK  UART_WAKEUPMETHOD_ADDRESSMARK // 地址标记唤醒

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Defines HAL USART Aliased Defines maintained for legacy purpose
  * @{
  */
// USART(通用同步/异步收发传输器)相关配置别名定义
#define USART_CLOCK_DISABLED            USART_CLOCK_DISABLE // 禁止时钟
#define USART_CLOCK_ENABLED             USART_CLOCK_ENABLE // 使能时钟

#define USARTNACK_ENABLED               USART_NACK_ENABLE // 使能NACK
#define USARTNACK_DISABLED              USART_NACK_DISABLE // 禁止NACK
/**
  * @}
  */

/** @defgroup HAL_WWDG_Aliased_Defines HAL WWDG Aliased Defines maintained for legacy purpose
  * @{
  */
// WWDG(窗口看门狗)相关配置别名定义
#define CFR_BASE                    WWDG_CFR_BASE // 配置寄存器基地址

/**
  * @}
  */

/** @defgroup HAL_CAN_Aliased_Defines HAL CAN Aliased Defines maintained for legacy purpose
  * @{
  */
// CAN(控制器局域网)相关配置别名定义
#define CAN_FilterFIFO0             CAN_FILTER_FIFO0 // 滤波器关联FIFO0
#define CAN_FilterFIFO1             CAN_FILTER_FIFO1 // 滤波器关联FIFO1
#define CAN_IT_RQCP0                CAN_IT_TME // 邮箱0请求完成中断 -> 发送空中断
#define CAN_IT_RQCP1                CAN_IT_TME // 邮箱1请求完成中断 -> 发送空中断
#define CAN_IT_RQCP2                CAN_IT_TME // 邮箱2请求完成中断 -> 发送空中断
#define INAK_TIMEOUT                CAN_TIMEOUT_VALUE // 初始化超时值
#define SLAK_TIMEOUT                CAN_TIMEOUT_VALUE // 从机超时值
// CAN发送状态定义
#define CAN_TXSTATUS_FAILED         ((uint8_t)0x00U) // 发送失败
#define CAN_TXSTATUS_OK             ((uint8_t)0x01U) // 发送成功
#define CAN_TXSTATUS_PENDING        ((uint8_t)0x02U) // 发送挂起

/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Defines HAL ETH Aliased Defines maintained for legacy purpose
  * @{
  */
// ETH(以太网)相关配置别名定义
#define VLAN_TAG                ETH_VLAN_TAG // VLAN标签
#define MIN_ETH_PAYLOAD         ETH_MIN_ETH_PAYLOAD // 最小以太网负载
#define MAX_ETH_PAYLOAD         ETH_MAX_ETH_PAYLOAD // 最大以太网负载
#define JUMBO_FRAME_PAYLOAD     ETH_JUMBO_FRAME_PAYLOAD // 巨帧负载
#define MACMIIAR_CR_MASK        ETH_MACMIIAR_CR_MASK // MII地址寄存器时钟范围掩码
#define MACCR_CLEAR_MASK        ETH_MACCR_CLEAR_MASK // MAC控制寄存器清除掩码
#define MACFCR_CLEAR_MASK       ETH_MACFCR_CLEAR_MASK // 流控制寄存器清除掩码
#define DMAOMR_CLEAR_MASK       ETH_DMAOMR_CLEAR_MASK // DMA操作模式寄存器清除掩码

// 以太网MMC寄存器地址定义(用于统计计数器)
#define ETH_MMCCR              0x00000100U // MMC控制寄存器
#define ETH_MMCRIR             0x00000104U // MMC接收中断寄存器
#define ETH_MMCTIR             0x00000108U // MMC发送中断寄存器
#define ETH_MMCRIMR            0x0000010CU // MMC接收中断屏蔽寄存器
#define ETH_MMCTIMR            0x00000110U // MMC发送中断屏蔽寄存器
#define ETH_MMCTGFSCCR         0x0000014CU // MMC发送良好单播帧计数器
#define ETH_MMCTGFMSCCR        0x00000150U // MMC发送良好多播帧计数器
#define ETH_MMCTGFCR           0x00000168U // MMC发送良好帧计数器
#define ETH_MMCRFCECR          0x00000194U // MMC接收FIFO错误计数器
#define ETH_MMCRFAECR          0x00000198U // MMC接收对齐错误计数器
#define ETH_MMCRGUFCR          0x000001C4U // MMC接收良好单播帧计数器

// 以太网MAC状态标志位定义
#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* 发送FIFO已满 */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* 发送FIFO非空 */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* 发送FIFO写操作激活 */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* 发送FIFO读状态：空闲 */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* 发送FIFO读状态：正在读取(将数据传输到MAC发送器) */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* 发送FIFO读状态：等待来自MAC发送器的发送状态 */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* 发送FIFO读状态：正在写入发送状态或刷新发送FIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC发送器处于暂停状态 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC发送帧控制器：空闲 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC发送帧控制器：等待上一帧状态或IFG/退避时间结束 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC发送帧控制器：正在生成并发送暂停控制帧(全双工模式) */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC发送帧控制器：正在传输输入帧以进行发送 */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII发送引擎激活 */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* 接收FIFO填充级别：空 */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* 接收FIFO填充级别：低于流控制去激活阈值 */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* 接收FIFO填充级别：高于流控制激活阈值 */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* 接收FIFO填充级别：满 */
#if defined(STM32F1)
#else
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* 接收FIFO读控制器：空闲状态 */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* 接收FIFO读控制器：正在读取帧数据 */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* 接收FIFO读控制器：正在读取帧状态(或时间戳) */
#endif
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* 接收FIFO读控制器：正在刷新帧数据和状态 */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* 接收FIFO写控制器激活 */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC小FIFO读/写控制器未激活 */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC小FIFO读控制器激活 */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC小FIFO写控制器激活 */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC小FIFO读/写控制器激活 */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII接收协议引擎激活 */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* 发送数据包配置结构体定义 */

/**
  * @}
  */
/** @defgroup HAL_DCMI_Aliased_Defines HAL DCMI别名定义，用于保持旧代码兼容性
  * @{
  */
/* DCMI错误标志别名：将旧版的溢出错误(OVF)映射为新版的覆盖错误(OVR) */
#define HAL_DCMI_ERROR_OVF      HAL_DCMI_ERROR_OVR       // DCMI错误码别名：溢出错误 -> 覆盖错误
#define DCMI_IT_OVF             DCMI_IT_OVR              // DCMI中断标志别名：溢出中断 -> 覆盖中断
#define DCMI_FLAG_OVFRI         DCMI_FLAG_OVRRI          // DCMI状态标志别名：原始中断溢出标志 -> 原始中断覆盖标志
#define DCMI_FLAG_OVFMI         DCMI_FLAG_OVRMI          // DCMI状态标志别名：掩码中断溢出标志 -> 掩码中断覆盖标志

/* DCMI裁剪功能函数别名：统一函数命名风格(CROP -> Crop) */
#define HAL_DCMI_ConfigCROP     HAL_DCMI_ConfigCrop      // 配置裁剪窗口
#define HAL_DCMI_EnableCROP     HAL_DCMI_EnableCrop      // 使能裁剪功能
#define HAL_DCMI_DisableCROP    HAL_DCMI_DisableCrop     // 禁用裁剪功能

/**
  * @}
  */

/* 针对STM32L4, F7, F4部分型号, H7系列芯片的条件编译 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7)
/** @defgroup HAL_DMA2D_Aliased_Defines HAL DMA2D别名定义，用于保持旧代码兼容性
  * @{
  */
/* DMA2D输出颜色模式别名：为了兼容旧代码，将简化的颜色模式宏映射为带OUTPUT前缀的标准宏 */
#define DMA2D_ARGB8888          DMA2D_OUTPUT_ARGB8888    // 输出格式：ARGB8888 (32位)
#define DMA2D_RGB888            DMA2D_OUTPUT_RGB888      // 输出格式：RGB888 (24位)
#define DMA2D_RGB565            DMA2D_OUTPUT_RGB565      // 输出格式：RGB565 (16位)
#define DMA2D_ARGB1555          DMA2D_OUTPUT_ARGB1555    // 输出格式：ARGB1555 (16位)
#define DMA2D_ARGB4444          DMA2D_OUTPUT_ARGB4444    // 输出格式：ARGB4444 (16位)

/* DMA2D输入颜色模式别名：将旧版CM_前缀宏映射为新版DMA2D_INPUT_前缀宏 */
#define CM_ARGB8888             DMA2D_INPUT_ARGB8888     // 输入格式：ARGB8888
#define CM_RGB888               DMA2D_INPUT_RGB888       // 输入格式：RGB888
#define CM_RGB565               DMA2D_INPUT_RGB565       // 输入格式：RGB565
#define CM_ARGB1555             DMA2D_INPUT_ARGB1555     // 输入格式：ARGB1555
#define CM_ARGB4444             DMA2D_INPUT_ARGB4444     // 输入格式：ARGB4444
#define CM_L8                   DMA2D_INPUT_L8           // 输入格式：L8 (8位亮度)
#define CM_AL44                 DMA2D_INPUT_AL44         // 输入格式：AL44 (4位亮度 + 4位Alpha)
#define CM_AL88                 DMA2D_INPUT_AL88         // 输入格式：AL88 (8位亮度 + 8位Alpha)
#define CM_L4                   DMA2D_INPUT_L4           // 输入格式：L4 (4位亮度)
#define CM_A8                   DMA2D_INPUT_A8           // 输入格式：A8 (8位Alpha)
#define CM_A4                   DMA2D_INPUT_A4           // 输入格式：A4 (4位Alpha)
/**
  * @}
  */
#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 */

/* 针对STM32L4, F7, F4部分型号, H7, U5系列芯片的条件编译 */
#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7) || defined(STM32U5)
/** @defgroup DMA2D_Aliases DMA2D API别名
  * @{
  */
/* DMA2D CLUT(颜色查找表)功能别名：将禁用CLUT映射为中止CLUT加载 */
#define HAL_DMA2D_DisableCLUT       HAL_DMA2D_CLUTLoading_Abort    // 为了兼容旧代码，重定向到 HAL_DMA2D_CLUTLoading_Abort
/**
  * @}
  */

#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 || STM32U5 */

/** @defgroup HAL_PPP_Aliased_Defines HAL PPP 别名定义，用于保持旧代码兼容性
  * @{
  */

/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/

/** @defgroup HAL_CRYP_Aliased_Functions HAL CRYP别名函数，用于保持旧代码兼容性
  * @{
  */
/* CRYP(加密处理器)回调函数别名：计算完成回调 */
#define HAL_CRYP_ComputationCpltCallback     HAL_CRYPEx_ComputationCpltCallback
/**
  * @}
  */

/** @defgroup HAL_DCACHE_Aliased_Functions HAL DCACHE别名函数，用于保持旧代码兼容性
  * @{
  */

/* 针对STM32U5系列的条件编译，处理数据缓存(DCACHE)相关函数 */
#if defined(STM32U5)
/* 函数名简化别名：清理并无效化缓存(按地址) */
#define HAL_DCACHE_CleanInvalidateByAddr     HAL_DCACHE_CleanInvalidByAddr
/* 函数名简化别名：清理并无效化缓存(按地址，中断方式) */
#define HAL_DCACHE_CleanInvalidateByAddr_IT  HAL_DCACHE_CleanInvalidByAddr_IT
#endif /* STM32U5 */

/**
  * @}
  */

/* 针对非STM32F2系列芯片的条件编译 */
#if !defined(STM32F2)
/** @defgroup HASH_alias HASH API别名
  * @{
  */
/* HASH(哈希处理器)中断处理函数别名：为了兼容旧代码进行重定向 */
#define HAL_HASHEx_IRQHandler   HAL_HASH_IRQHandler
/**
  *
  * @}
  */
#endif /* STM32F2 */
/** @defgroup HAL_HASH_Aliased_Functions HAL HASH别名函数，用于保持旧代码兼容性
  * @{
  */
/* HASH状态类型定义别名 */
#define HAL_HASH_STATETypeDef        HAL_HASH_StateTypeDef
/* HASH阶段类型定义别名 */
#define HAL_HASHPhaseTypeDef         HAL_HASH_PhaseTypeDef

/* HMAC(基于哈希的消息认证码)结束函数别名，映射到对应的HASH结束函数 */
#define HAL_HMAC_MD5_Finish          HAL_HASH_MD5_Finish
#define HAL_HMAC_SHA1_Finish         HAL_HASH_SHA1_Finish
#define HAL_HMAC_SHA224_Finish       HAL_HASH_SHA224_Finish
#define HAL_HMAC_SHA256_Finish       HAL_HASH_SHA256_Finish

/*HASH 算法选择别名，将旧版命名映射为带ALGOSELECTION前缀的新命名*/

#define HASH_AlgoSelection_SHA1      HASH_ALGOSELECTION_SHA1      // 选择SHA1算法
#define HASH_AlgoSelection_SHA224    HASH_ALGOSELECTION_SHA224    // 选择SHA224算法
#define HASH_AlgoSelection_SHA256    HASH_ALGOSELECTION_SHA256    // 选择SHA256算法
#define HASH_AlgoSelection_MD5       HASH_ALGOSELECTION_MD5       // 选择MD5算法

/* HASH算法模式别名 */
#define HASH_AlgoMode_HASH         HASH_ALGOMODE_HASH           // HASH模式
#define HASH_AlgoMode_HMAC         HASH_ALGOMODE_HMAC           // HMAC模式

/* HASH HMAC密钥类型别名 */
#define HASH_HMACKeyType_ShortKey  HASH_HMAC_KEYTYPE_SHORTKEY   // 短密钥
#define HASH_HMACKeyType_LongKey   HASH_HMAC_KEYTYPE_LONGKEY    // 长密钥

/* 针对STM32L4, L5, F2, F4, F7, H7系列的条件编译 */
#if defined(STM32L4) || defined(STM32L5) || defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)

/* HASH数据累加函数别名：将Accumulate映射为缩写Accmlt */
#define HAL_HASH_MD5_Accumulate                HAL_HASH_MD5_Accmlt
#define HAL_HASH_MD5_Accumulate_End            HAL_HASH_MD5_Accmlt_End
#define HAL_HASH_MD5_Accumulate_IT             HAL_HASH_MD5_Accmlt_IT
#define HAL_HASH_MD5_Accumulate_End_IT         HAL_HASH_MD5_Accmlt_End_IT

#define HAL_HASH_SHA1_Accumulate               HAL_HASH_SHA1_Accmlt
#define HAL_HASH_SHA1_Accumulate_End           HAL_HASH_SHA1_Accmlt_End
#define HAL_HASH_SHA1_Accumulate_IT            HAL_HASH_SHA1_Accmlt_IT
#define HAL_HASH_SHA1_Accumulate_End_IT        HAL_HASH_SHA1_Accmlt_End_IT

#define HAL_HASHEx_SHA224_Accumulate           HAL_HASHEx_SHA224_Accmlt
#define HAL_HASHEx_SHA224_Accumulate_End       HAL_HASHEx_SHA224_Accmlt_End
#define HAL_HASHEx_SHA224_Accumulate_IT        HAL_HASHEx_SHA224_Accmlt_IT
#define HAL_HASHEx_SHA224_Accumulate_End_IT    HAL_HASHEx_SHA224_Accmlt_End_IT

#define HAL_HASHEx_SHA256_Accumulate           HAL_HASHEx_SHA256_Accmlt
#define HAL_HASHEx_SHA256_Accumulate_End       HAL_HASHEx_SHA256_Accmlt_End
#define HAL_HASHEx_SHA256_Accumulate_IT        HAL_HASHEx_SHA256_Accmlt_IT
#define HAL_HASHEx_SHA256_Accumulate_End_IT    HAL_HASHEx_SHA256_Accmlt_End_IT

#endif  /* STM32L4 || STM32L5 || STM32F2 || STM32F4 || STM32F7 || STM32H7 */
/**
  * @}
  */

/** @defgroup HAL_Aliased_Functions HAL 通用别名函数，用于保持旧代码兼容性
  * @{
  */
/* 调试模式相关函数别名：将旧版HAL_前缀映射为新版HAL_DBGMCU_前缀 */
#define HAL_EnableDBGSleepMode HAL_DBGMCU_EnableDBGSleepMode       // 使能睡眠模式下的调试
#define HAL_DisableDBGSleepMode HAL_DBGMCU_DisableDBGSleepMode     // 禁用睡眠模式下的调试
#define HAL_EnableDBGStopMode HAL_DBGMCU_EnableDBGStopMode         // 使能停止模式下的调试
#define HAL_DisableDBGStopMode HAL_DBGMCU_DisableDBGStopMode       // 禁用停止模式下的调试
#define HAL_EnableDBGStandbyMode HAL_DBGMCU_EnableDBGStandbyMode   // 使能待机模式下的调试
#define HAL_DisableDBGStandbyMode HAL_DBGMCU_DisableDBGStandbyMode // 禁用待机模式下的调试

/* 调试低功耗配置宏：根据cmd参数调用使能或禁用函数 */
#define HAL_DBG_LowPowerConfig(Periph, cmd) (((cmd\
                                              )==ENABLE)? HAL_DBGMCU_DBG_EnableLowPowerConfig(Periph) : \
                                             HAL_DBGMCU_DBG_DisableLowPowerConfig(Periph))

/* 内部参考电压输出选择函数别名 */
#define HAL_VREFINT_OutputSelect  HAL_SYSCFG_VREFINT_OutputSelect

/* 锁定命令宏：根据cmd参数使能或禁用内部参考电压锁定 */
#define HAL_Lock_Cmd(cmd) (((cmd)==ENABLE) ? HAL_SYSCFG_Enable_Lock_VREFINT() : HAL_SYSCFG_Disable_Lock_VREFINT())

/* 针对STM32L0系列的条件编译，其他系列定义内部参考电压使能/禁用宏 */
#if defined(STM32L0)
#else
#define HAL_VREFINT_Cmd(cmd) (((cmd)==ENABLE)? HAL_SYSCFG_EnableVREFINT() : HAL_SYSCFG_DisableVREFINT())
#endif

/* ADC缓冲使能命令宏：映射到ADC扩展函数 */
#define HAL_ADC_EnableBuffer_Cmd(cmd)  (((cmd)==ENABLE) ? HAL_ADCEx_EnableVREFINT() : HAL_ADCEx_DisableVREFINT())

/* ADC缓冲传感器使能命令宏：映射到ADC扩展函数 */
#define HAL_ADC_EnableBufferSensor_Cmd(cmd) (((cmd\
                                              )==ENABLE) ?  HAL_ADCEx_EnableVREFINTTempSensor() : \
                                             HAL_ADCEx_DisableVREFINTTempSensor())

/* 针对STM32H7部分型号的条件编译，SR域调试停止/待机模式别名 */
#if defined(STM32H7A3xx) || defined(STM32H7B3xx) || defined(STM32H7B0xx) || defined(STM32H7A3xxQ) || \
    defined(STM32H7B3xxQ) || defined(STM32H7B0xxQ)
#define HAL_EnableSRDomainDBGStopMode      HAL_EnableDomain3DBGStopMode
#define HAL_DisableSRDomainDBGStopMode     HAL_DisableDomain3DBGStopMode
#define HAL_EnableSRDomainDBGStandbyMode   HAL_EnableDomain3DBGStandbyMode
#define HAL_DisableSRDomainDBGStandbyMode  HAL_DisableDomain3DBGStandbyMode
#endif /* STM32H7A3xx || STM32H7B3xx || STM32H7B0xx || STM32H7A3xxQ || STM32H7B3xxQ  || STM32H7B0xxQ */

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Functions HAL FLASH别名函数，用于保持旧代码兼容性
  * @{
  */
/* FLASH操作函数别名：将旧版函数名映射为HAL_FLASHEx_扩展函数 */
#define FLASH_HalfPageProgram      HAL_FLASHEx_HalfPageProgram          // 半页编程
#define FLASH_EnableRunPowerDown   HAL_FLASHEx_EnableRunPowerDown       // 使能运行掉电模式
#define FLASH_DisableRunPowerDown  HAL_FLASHEx_DisableRunPowerDown      // 禁用运行掉电模式
#define HAL_DATA_EEPROMEx_Unlock   HAL_FLASHEx_DATAEEPROM_Unlock        // 数据EEPROM解锁
#define HAL_DATA_EEPROMEx_Lock     HAL_FLASHEx_DATAEEPROM_Lock          // 数据EEPROM锁定
#define HAL_DATA_EEPROMEx_Erase    HAL_FLASHEx_DATAEEPROM_Erase         // 数据EEPROM擦除
#define HAL_DATA_EEPROMEx_Program  HAL_FLASHEx_DATAEEPROM_Program       // 数据EEPROM编程

/**
  * @}
 */

/** @defgroup HAL_I2C_Aliased_Functions HAL I2C别名函数，用于保持旧代码兼容性
  * @{
  */
/* I2C滤波器配置函数别名：统一命名风格 */
#define HAL_I2CEx_AnalogFilter_Config         HAL_I2CEx_ConfigAnalogFilter    // 配置模拟滤波器
#define HAL_I2CEx_DigitalFilter_Config        HAL_I2CEx_ConfigDigitalFilter   // 配置数字滤波器
#define HAL_FMPI2CEx_AnalogFilter_Config      HAL_FMPI2CEx_ConfigAnalogFilter // FMPI2C配置模拟滤波器
#define HAL_FMPI2CEx_DigitalFilter_Config     HAL_FMPI2CEx_ConfigDigitalFilter// FMPI2C配置数字滤波器

/* I2C快速模式Plus配置宏：根据cmd参数使能或禁用 */
#define HAL_I2CFastModePlusConfig(SYSCFG_I2CFastModePlus, cmd) (((cmd) == ENABLE)? \
                                                                HAL_I2CEx_EnableFastModePlus(SYSCFG_I2CFastModePlus): \
                                                                HAL_I2CEx_DisableFastModePlus(SYSCFG_I2CFastModePlus))

/* 针对多系列STM32芯片的条件编译，I2C顺序传输函数别名：简化函数名(Sequential -> Seq) */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || \
    defined(STM32L4) || defined(STM32L5) || defined(STM32G4) || defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_IT  HAL_I2C_Master_Seq_Transmit_IT   // 主机顺序发送(中断)
#define HAL_I2C_Master_Sequential_Receive_IT   HAL_I2C_Master_Seq_Receive_IT    // 主机顺序接收(中断)
#define HAL_I2C_Slave_Sequential_Transmit_IT   HAL_I2C_Slave_Seq_Transmit_IT    // 从机顺序发送(中断)
#define HAL_I2C_Slave_Sequential_Receive_IT    HAL_I2C_Slave_Seq_Receive_IT     // 从机顺序接收(中断)
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 ||
          STM32L4 || STM32L5 || STM32G4 || STM32L1 */
/* 针对多系列STM32芯片的条件编译，I2C顺序传输函数别名(DMA模式) */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F4) || defined(STM32F7) || \
    defined(STM32L0) || defined(STM32L4) || defined(STM32L5) || defined(STM32G4)|| defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_DMA HAL_I2C_Master_Seq_Transmit_DMA  // 主机顺序发送(DMA)
#define HAL_I2C_Master_Sequential_Receive_DMA  HAL_I2C_Master_Seq_Receive_DMA   // 主机顺序接收(DMA)
#define HAL_I2C_Slave_Sequential_Transmit_DMA  HAL_I2C_Slave_Seq_Transmit_DMA   // 从机顺序发送(DMA)
#define HAL_I2C_Slave_Sequential_Receive_DMA   HAL_I2C_Slave_Seq_Receive_DMA    // 从机顺序接收(DMA)
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F4 || STM32F7 || STM32L0 || STM32L4 || STM32L5 || STM32G4 || STM32L1 */

/* 针对STM32F4系列的条件编译，FMPI2C顺序传输函数别名 */
#if defined(STM32F4)
#define HAL_FMPI2C_Master_Sequential_Transmit_IT  HAL_FMPI2C_Master_Seq_Transmit_IT
#define HAL_FMPI2C_Master_Sequential_Receive_IT   HAL_FMPI2C_Master_Seq_Receive_IT
#define HAL_FMPI2C_Slave_Sequential_Transmit_IT   HAL_FMPI2C_Slave_Seq_Transmit_IT
#define HAL_FMPI2C_Slave_Sequential_Receive_IT    HAL_FMPI2C_Slave_Seq_Receive_IT
#define HAL_FMPI2C_Master_Sequential_Transmit_DMA HAL_FMPI2C_Master_Seq_Transmit_DMA
#define HAL_FMPI2C_Master_Sequential_Receive_DMA  HAL_FMPI2C_Master_Seq_Receive_DMA
#define HAL_FMPI2C_Slave_Sequential_Transmit_DMA  HAL_FMPI2C_Slave_Seq_Transmit_DMA
#define HAL_FMPI2C_Slave_Sequential_Receive_DMA   HAL_FMPI2C_Slave_Seq_Receive_DMA
#endif /* STM32F4 */
/**
  * @}
 */

/** @defgroup HAL_PWR_Aliased HAL PWR别名定义，用于保持旧代码兼容性
  * @{
  */

/* 针对STM32G0系列的条件编译，PVD(可编程电压检测器)配置函数别名 */
#if defined(STM32G0)
#define HAL_PWR_ConfigPVD                             HAL_PWREx_ConfigPVD
#define HAL_PWR_EnablePVD                             HAL_PWREx_EnablePVD
#define HAL_PWR_DisablePVD                            HAL_PWREx_DisablePVD
#define HAL_PWR_PVD_IRQHandler                        HAL_PWREx_PVD_IRQHandler
#endif

/* 电源管理函数别名：将旧版HAL_PWR_函数映射到新版HAL_PWREx_扩展函数 */
#define HAL_PWR_PVDConfig                             HAL_PWR_ConfigPVD
#define HAL_PWR_DisableBkUpReg                        HAL_PWREx_DisableBkUpReg           // 禁用备份域调节器
#define HAL_PWR_DisableFlashPowerDown                 HAL_PWREx_DisableFlashPowerDown    // 禁用Flash掉电
#define HAL_PWR_DisableVddio2Monitor                  HAL_PWREx_DisableVddio2Monitor     // 禁用Vddio2监控
#define HAL_PWR_EnableBkUpReg                         HAL_PWREx_EnableBkUpReg            // 使能备份域调节器
#define HAL_PWR_EnableFlashPowerDown                  HAL_PWREx_EnableFlashPowerDown     // 使能Flash掉电
#define HAL_PWR_EnableVddio2Monitor                   HAL_PWREx_EnableVddio2Monitor      // 使能Vddio2监控
#define HAL_PWR_PVD_PVM_IRQHandler                    HAL_PWREx_PVD_PVM_IRQHandler       // PVD/PVM中断处理
#define HAL_PWR_PVDLevelConfig                        HAL_PWR_ConfigPVD                  // PVD电平配置
#define HAL_PWR_Vddio2Monitor_IRQHandler              HAL_PWREx_Vddio2Monitor_IRQHandler // Vddio2监控中断处理
#define HAL_PWR_Vddio2MonitorCallback                 HAL_PWREx_Vddio2MonitorCallback    // Vddio2监控回调
#define HAL_PWREx_ActivateOverDrive                   HAL_PWREx_EnableOverDrive          // 激活过驱动模式
#define HAL_PWREx_DeactivateOverDrive                 HAL_PWREx_DisableOverDrive         // 关闭过驱动模式
#define HAL_PWREx_DisableSDADCAnalog                  HAL_PWREx_DisableSDADC             // 禁用SDADC
#define HAL_PWREx_EnableSDADCAnalog                   HAL_PWREx_EnableSDADC              // 使能SDADC
#define HAL_PWREx_PVMConfig                           HAL_PWREx_ConfigPVM                // 配置PVM(电源电压监控)

/* PWR模式定义别名：将旧版PWR_MODE_前缀映射为新版PWR_PVD_MODE_前缀 */
#define PWR_MODE_NORMAL                               PWR_PVD_MODE_NORMAL                // 正常模式
#define PWR_MODE_IT_RISING                            PWR_PVD_MODE_IT_RISING             // 上升沿中断
#define PWR_MODE_IT_FALLING                           PWR_PVD_MODE_IT_FALLING            // 下降沿中断
#define PWR_MODE_IT_RISING_FALLING                    PWR_PVD_MODE_IT_RISING_FALLING     // 上升/下降沿中断
#define PWR_MODE_EVENT_RISING                         PWR_PVD_MODE_EVENT_RISING          // 上升沿事件
#define PWR_MODE_EVENT_FALLING                        PWR_PVD_MODE_EVENT_FALLING         // 下降沿事件
#define PWR_MODE_EVENT_RISING_FALLING                 PWR_PVD_MODE_EVENT_RISING_FALLING  // 上升/下降沿事件

/* 寄存器位带操作相关别名 */
#define CR_OFFSET_BB                                  PWR_CR_OFFSET_BB                   // CR寄存器位带偏移
#define CSR_OFFSET_BB                                 PWR_CSR_OFFSET_BB                  // CSR寄存器位带偏移
#define PMODE_BIT_NUMBER                              VOS_BIT_NUMBER                     // 电源模式位号
#define CR_PMODE_BB                                   CR_VOS_BB                          // CR寄存器电源模式位带

/* 位号定义别名 */
#define DBP_BitNumber                                 DBP_BIT_NUMBER                     // 禁用备份域写保护位号
#define PVDE_BitNumber                                PVDE_BIT_NUMBER                    // PVD使能位号
#define PMODE_BitNumber                               PMODE_BIT_NUMBER                   // 电源模式位号
#define EWUP_BitNumber                                EWUP_BIT_NUMBER                    // 唤醒引脚使能位号
#define FPDS_BitNumber                                FPDS_BIT_NUMBER                    // Flash掉电停止模式位号
#define ODEN_BitNumber                                ODEN_BIT_NUMBER                    // 过驱动使能位号
#define ODSWEN_BitNumber                              ODSWEN_BIT_NUMBER                  // 过驱动切换使能位号
#define MRLVDS_BitNumber                              MRLVDS_BIT_NUMBER                  // 主调压器低电压停止模式位号
#define LPLVDS_BitNumber                              LPLVDS_BIT_NUMBER                  // 低功耗调压器低电压停止模式位号
#define BRE_BitNumber                                 BRE_BIT_NUMBER                     // 备份域就绪位号

#define PWR_MODE_EVT                                  PWR_PVD_MODE_NORMAL                // 兼容旧定义

/* 针对STM32U5系列的条件编译，SRAM保持(retention)相关定义别名 */
#if defined (STM32U5)
/* SRAM1 页面停止模式保持别名 */
#define PWR_SRAM1_PAGE1_STOP_RETENTION                PWR_SRAM1_PAGE1_STOP
#define PWR_SRAM1_PAGE2_STOP_RETENTION                PWR_SRAM1_PAGE2_STOP
#define PWR_SRAM1_PAGE3_STOP_RETENTION                PWR_SRAM1_PAGE3_STOP
#define PWR_SRAM1_PAGE4_STOP_RETENTION                PWR_SRAM1_PAGE4_STOP
#define PWR_SRAM1_PAGE5_STOP_RETENTION                PWR_SRAM1_PAGE5_STOP
#define PWR_SRAM1_PAGE6_STOP_RETENTION                PWR_SRAM1_PAGE6_STOP
#define PWR_SRAM1_PAGE7_STOP_RETENTION                PWR_SRAM1_PAGE7_STOP
#define PWR_SRAM1_PAGE8_STOP_RETENTION                PWR_SRAM1_PAGE8_STOP
#define PWR_SRAM1_PAGE9_STOP_RETENTION                PWR_SRAM1_PAGE9_STOP
#define PWR_SRAM1_PAGE10_STOP_RETENTION               PWR_SRAM1_PAGE10_STOP
#define PWR_SRAM1_PAGE11_STOP_RETENTION               PWR_SRAM1_PAGE11_STOP
#define PWR_SRAM1_PAGE12_STOP_RETENTION               PWR_SRAM1_PAGE12_STOP
#define PWR_SRAM1_FULL_STOP_RETENTION                 PWR_SRAM1_FULL_STOP

/* SRAM2 页面停止模式保持别名 */
#define PWR_SRAM2_PAGE1_STOP_RETENTION                PWR_SRAM2_PAGE1_STOP
#define PWR_SRAM2_PAGE2_STOP_RETENTION                PWR_SRAM2_PAGE2_STOP
#define PWR_SRAM2_FULL_STOP_RETENTION                 PWR_SRAM2_FULL_STOP

/* SRAM3 页面停止模式保持别名 */
#define PWR_SRAM3_PAGE1_STOP_RETENTION                PWR_SRAM3_PAGE1_STOP
#define PWR_SRAM3_PAGE2_STOP_RETENTION                PWR_SRAM3_PAGE2_STOP
#define PWR_SRAM3_PAGE3_STOP_RETENTION                PWR_SRAM3_PAGE3_STOP
#define PWR_SRAM3_PAGE4_STOP_RETENTION                PWR_SRAM3_PAGE4_STOP
#define PWR_SRAM3_PAGE5_STOP_RETENTION                PWR_SRAM3_PAGE5_STOP
#define PWR_SRAM3_PAGE6_STOP_RETENTION                PWR_SRAM3_PAGE6_STOP
#define PWR_SRAM3_PAGE7_STOP_RETENTION                PWR_SRAM3_PAGE7_STOP
#define PWR_SRAM3_PAGE8_STOP_RETENTION                PWR_SRAM3_PAGE8_STOP
#define PWR_SRAM3_PAGE9_STOP_RETENTION                PWR_SRAM3_PAGE9_STOP
#define PWR_SRAM3_PAGE10_STOP_RETENTION               PWR_SRAM3_PAGE10_STOP
#define PWR_SRAM3_PAGE11_STOP_RETENTION               PWR_SRAM3_PAGE11_STOP
#define PWR_SRAM3_PAGE12_STOP_RETENTION               PWR_SRAM3_PAGE12_STOP
#define PWR_SRAM3_PAGE13_STOP_RETENTION               PWR_SRAM3_PAGE13_STOP
#define PWR_SRAM3_FULL_STOP_RETENTION                 PWR_SRAM3_FULL_STOP

/* SRAM4 停止模式保持别名 */
#define PWR_SRAM4_FULL_STOP_RETENTION                 PWR_SRAM4_FULL_STOP

/* SRAM5 页面停止模式保持别名 */
#define PWR_SRAM5_PAGE1_STOP_RETENTION                PWR_SRAM5_PAGE1_STOP
#define PWR_SRAM5_PAGE2_STOP_RETENTION                PWR_SRAM5_PAGE2_STOP
#define PWR_SRAM5_PAGE3_STOP_RETENTION                PWR_SRAM5_PAGE3_STOP
#define PWR_SRAM5_PAGE4_STOP_RETENTION                PWR_SRAM5_PAGE4_STOP
#define PWR_SRAM5_PAGE5_STOP_RETENTION                PWR_SRAM5_PAGE5_STOP
#define PWR_SRAM5_PAGE6_STOP_RETENTION                PWR_SRAM5_PAGE6_STOP
#define PWR_SRAM5_PAGE7_STOP_RETENTION                PWR_SRAM5_PAGE7_STOP
#define PWR_SRAM5_PAGE8_STOP_RETENTION                PWR_SRAM5_PAGE8_STOP
#define PWR_SRAM5_PAGE9_STOP_RETENTION                PWR_SRAM5_PAGE9_STOP
#define PWR_SRAM5_PAGE10_STOP_RETENTION               PWR_SRAM5_PAGE10_STOP
#define PWR_SRAM5_PAGE11_STOP_RETENTION               PWR_SRAM5_PAGE11_STOP
#define PWR_SRAM5_PAGE12_STOP_RETENTION               PWR_SRAM5_PAGE12_STOP
#define PWR_SRAM5_PAGE13_STOP_RETENTION               PWR_SRAM5_PAGE13_STOP
#define PWR_SRAM5_FULL_STOP_RETENTION                 PWR_SRAM5_FULL_STOP

/* SRAM6 页面停止模式保持别名 */
#define PWR_SRAM6_PAGE1_STOP_RETENTION                PWR_SRAM6_PAGE1_STOP
#define PWR_SRAM6_PAGE2_STOP_RETENTION                PWR_SRAM6_PAGE2_STOP
#define PWR_SRAM6_PAGE3_STOP_RETENTION                PWR_SRAM6_PAGE3_STOP
#define PWR_SRAM6_PAGE4_STOP_RETENTION                PWR_SRAM6_PAGE4_STOP
#define PWR_SRAM6_PAGE5_STOP_RETENTION                PWR_SRAM6_PAGE5_STOP
#define PWR_SRAM6_PAGE6_STOP_RETENTION                PWR_SRAM6_PAGE6_STOP
#define PWR_SRAM6_PAGE7_STOP_RETENTION                PWR_SRAM6_PAGE7_STOP
#define PWR_SRAM6_PAGE8_STOP_RETENTION                PWR_SRAM6_PAGE8_STOP
#define PWR_SRAM6_FULL_STOP_RETENTION                 PWR_SRAM6_FULL_STOP

/* 缓存和外设RAM停止模式保持别名 */
#define PWR_ICACHE_FULL_STOP_RETENTION                PWR_ICACHE_FULL_STOP              // 指令缓存
#define PWR_DCACHE1_FULL_STOP_RETENTION               PWR_DCACHE1_FULL_STOP             // 数据缓存1
#define PWR_DCACHE2_FULL_STOP_RETENTION               PWR_DCACHE2_FULL_STOP             // 数据缓存2
#define PWR_DMA2DRAM_FULL_STOP_RETENTION              PWR_DMA2DRAM_FULL_STOP            // DMA2D RAM
#define PWR_PERIPHRAM_FULL_STOP_RETENTION             PWR_PERIPHRAM_FULL_STOP           // 外设RAM
#define PWR_PKA32RAM_FULL_STOP_RETENTION              PWR_PKA32RAM_FULL_STOP            // PKA32 RAM
#define PWR_GRAPHICPRAM_FULL_STOP_RETENTION           PWR_GRAPHICPRAM_FULL_STOP         // 图形RAM
#define PWR_DSIRAM_FULL_STOP_RETENTION                PWR_DSIRAM_FULL_STOP              // DSI RAM
#define PWR_JPEGRAM_FULL_STOP_RETENTION               PWR_JPEGRAM_FULL_STOP             // JPEG RAM

/* SRAM2 待机模式保持别名 */
#define PWR_SRAM2_PAGE1_STANDBY_RETENTION             PWR_SRAM2_PAGE1_STANDBY
#define PWR_SRAM2_PAGE2_STANDBY_RETENTION             PWR_SRAM2_PAGE2_STANDBY
#define PWR_SRAM2_FULL_STANDBY_RETENTION              PWR_SRAM2_FULL_STANDBY

/* SRAM 运行模式保持别名 */
#define PWR_SRAM1_FULL_RUN_RETENTION                  PWR_SRAM1_FULL_RUN
#define PWR_SRAM2_FULL_RUN_RETENTION                  PWR_SRAM2_FULL_RUN
#define PWR_SRAM3_FULL_RUN_RETENTION                  PWR_SRAM3_FULL_RUN
#define PWR_SRAM4_FULL_RUN_RETENTION                  PWR_SRAM4_FULL_RUN
#define PWR_SRAM5_FULL_RUN_RETENTION                  PWR_SRAM5_FULL_RUN
#define PWR_SRAM6_FULL_RUN_RETENTION                  PWR_SRAM6_FULL_RUN

#define PWR_ALL_RAM_RUN_RETENTION_MASK                PWR_ALL_RAM_RUN_MASK              // 所有RAM运行保持掩码
#endif

/**
  * @}
 */
/** @defgroup HAL_RTC_Aliased_Functions HAL RTC 别名函数（用于保持旧代码兼容性）
  * @{
  */
#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
// 定义RTC扩展函数别名：将旧函数名映射到新函数名，便于旧代码兼容
#define HAL_RTCEx_SetBoothardwareKey            HAL_RTCEx_LockBootHardwareKey    // 设置硬件密钥
#define HAL_RTCEx_BKUPBlock_Enable              HAL_RTCEx_BKUPBlock              // 启用备份域块保护
#define HAL_RTCEx_BKUPBlock_Disable             HAL_RTCEx_BKUPUnblock            // 禁用备份域块保护
#define HAL_RTCEx_Erase_SecretDev_Conf          HAL_RTCEx_ConfigEraseDeviceSecrets // 擦除秘密设备配置
#endif /* STM32H5 || STM32WBA || STM32H7RS */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Functions HAL SMBUS 别名函数（用于保持旧代码兼容性）
  * @{
  */
// SMBUS相关函数别名定义
#define HAL_SMBUS_Slave_Listen_IT          HAL_SMBUS_EnableListen_IT          // 从机监听中断使能
#define HAL_SMBUS_SlaveAddrCallback        HAL_SMBUS_AddrCallback             // 从机地址回调函数
#define HAL_SMBUS_SlaveListenCpltCallback  HAL_SMBUS_ListenCpltCallback       // 从机监听完成回调
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Functions HAL SPI 别名函数（用于保持旧代码兼容性）
  * @{
  */
// SPI相关函数别名定义
#define HAL_SPI_FlushRxFifo                HAL_SPIEx_FlushRxFifo              // 清空SPI接收FIFO
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Functions HAL TIM 别名函数（用于保持旧代码兼容性）
  * @{
  */
// TIM(定时器)相关函数别名定义
#define HAL_TIM_DMADelayPulseCplt                       TIM_DMADelayPulseCplt           // DMA延时脉冲完成回调
#define HAL_TIM_DMAError                                TIM_DMAError                    // DMA错误处理
#define HAL_TIM_DMACaptureCplt                          TIM_DMACaptureCplt              // DMA捕获完成回调
#define HAL_TIMEx_DMACommutationCplt                    TIMEx_DMACommutationCplt        // DMA交换完成回调
#if defined(STM32H7) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || defined(STM32L4)
// 针对特定STM32系列的定时器别名定义
#define HAL_TIM_SlaveConfigSynchronization              HAL_TIM_SlaveConfigSynchro      // 从模式同步配置
#define HAL_TIM_SlaveConfigSynchronization_IT           HAL_TIM_SlaveConfigSynchro_IT   // 从模式同步配置(中断模式)
#define HAL_TIMEx_CommutationCallback                   HAL_TIMEx_CommutCallback        // 交换回调函数
#define HAL_TIMEx_ConfigCommutationEvent                HAL_TIMEx_ConfigCommutEvent     // 配置交换事件
#define HAL_TIMEx_ConfigCommutationEvent_IT             HAL_TIMEx_ConfigCommutEvent_IT  // 配置交换事件(中断模式)
#define HAL_TIMEx_ConfigCommutationEvent_DMA            HAL_TIMEx_ConfigCommutEvent_DMA // 配置交换事件(DMA模式)
#endif /* STM32H7 || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Functions HAL UART 别名函数（用于保持旧代码兼容性）
  * @{
  */
// UART(串口)相关函数别名定义
#define HAL_UART_WakeupCallback HAL_UARTEx_WakeupCallback                   // UART唤醒回调函数
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Functions HAL LTDC 别名函数（用于保持旧代码兼容性）
  * @{
  */
// LTDC(LCD-TFT控制器)相关函数别名定义
#define HAL_LTDC_LineEvenCallback HAL_LTDC_LineEventCallback                // 行事件回调函数
#define HAL_LTDC_Relaod           HAL_LTDC_Reload                          // 重新加载配置
#define HAL_LTDC_StructInitFromVideoConfig  HAL_LTDCEx_StructInitFromVideoConfig // 从视频配置初始化结构体
#define HAL_LTDC_StructInitFromAdaptedCommandConfig  HAL_LTDCEx_StructInitFromAdaptedCommandConfig // 从适配命令配置初始化结构体
/**
  * @}
  */


/** @defgroup HAL_PPP_Aliased_Functions HAL PPP 别名函数（用于保持旧代码兼容性）
  * @{
  */

/**
  * @}
  */

/* 导出的宏 ------------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Macros HAL CRYP 别名宏（用于保持旧代码兼容性）
  * @{
  */
// AES加密相关宏别名，映射到新的CRYP(加密处理器)宏
#define AES_IT_CC                      CRYP_IT_CC                        // AES加密完成中断
#define AES_IT_ERR                     CRYP_IT_ERR                       // AES错误中断
#define AES_FLAG_CCF                   CRYP_FLAG_CCF                     // AES加密完成标志
/**
  * @}
  */

/** @defgroup HAL_Aliased_Macros HAL 通用别名宏（用于保持旧代码兼容性）
  * @{
  */
// 系统配置相关宏别名定义
#define __HAL_GET_BOOT_MODE                   __HAL_SYSCFG_GET_BOOT_MODE         // 获取启动模式
#define __HAL_REMAPMEMORY_FLASH               __HAL_SYSCFG_REMAPMEMORY_FLASH     // 重映射Flash到0x00000000
#define __HAL_REMAPMEMORY_SYSTEMFLASH         __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH // 重映射系统Flash
#define __HAL_REMAPMEMORY_SRAM                __HAL_SYSCFG_REMAPMEMORY_SRAM      // 重映射SRAM
#define __HAL_REMAPMEMORY_FMC                 __HAL_SYSCFG_REMAPMEMORY_FMC       // 重映射FMC(可变存储控制器)
#define __HAL_REMAPMEMORY_FMC_SDRAM           __HAL_SYSCFG_REMAPMEMORY_FMC_SDRAM // 重映射FMC SDRAM
#define __HAL_REMAPMEMORY_FSMC                __HAL_SYSCFG_REMAPMEMORY_FSMC      // 重映射FSMC(静态存储控制器)
#define __HAL_REMAPMEMORY_QUADSPI             __HAL_SYSCFG_REMAPMEMORY_QUADSPI   // 重映射QSPI(四线SPI)
#define __HAL_FMC_BANK                        __HAL_SYSCFG_FMC_BANK              // FMC存储块配置
#define __HAL_GET_FLAG                        __HAL_SYSCFG_GET_FLAG              // 获取系统配置标志
#define __HAL_CLEAR_FLAG                      __HAL_SYSCFG_CLEAR_FLAG            // 清除系统配置标志
#define __HAL_VREFINT_OUT_ENABLE              __HAL_SYSCFG_VREFINT_OUT_ENABLE    // 使能内部参考电压输出
#define __HAL_VREFINT_OUT_DISABLE             __HAL_SYSCFG_VREFINT_OUT_DISABLE   // 禁用内部参考电压输出
#define __HAL_SYSCFG_SRAM2_WRP_ENABLE         __HAL_SYSCFG_SRAM2_WRP_0_31_ENABLE // 使能SRAM2写保护

// 标志和配置别名定义
#define SYSCFG_FLAG_VREF_READY                SYSCFG_FLAG_VREFINT_READY          // 参考电压就绪标志
#define SYSCFG_FLAG_RC48                      RCC_FLAG_HSI48                     // 48MHz RC振荡器标志
#define IS_SYSCFG_FASTMODEPLUS_CONFIG         IS_I2C_FASTMODEPLUS                // 快速模式Plus配置检查
#define UFB_MODE_BitNumber                    UFB_MODE_BIT_NUMBER                // USB模式位编号
#define CMP_PD_BitNumber                      CMP_PD_BIT_NUMBER                  // 比较器掉电位编号

/**
  * @}
  */


/** @defgroup HAL_ADC_Aliased_Macros HAL ADC 别名宏（用于保持旧代码兼容性）
  * @{
  */
// ADC(模数转换器)使能与状态检查相关宏
#define __ADC_ENABLE                                     __HAL_ADC_ENABLE                     // 使能ADC
#define __ADC_DISABLE                                    __HAL_ADC_DISABLE                    // 禁用ADC
#define __HAL_ADC_ENABLING_CONDITIONS                    ADC_ENABLING_CONDITIONS              // ADC使能条件检查
#define __HAL_ADC_DISABLING_CONDITIONS                   ADC_DISABLING_CONDITIONS             // ADC禁用条件检查
#define __HAL_ADC_IS_ENABLED                             ADC_IS_ENABLE                        // 检查ADC是否使能
#define __ADC_IS_ENABLED                                 ADC_IS_ENABLE                        // 检查adc是否使能
#define __HAL_ADC_IS_SOFTWARE_START_REGULAR              ADC_IS_SOFTWARE_START_REGULAR        // 检查是否为规则组软件启动
#define __HAL_ADC_IS_SOFTWARE_START_INJECTED             ADC_IS_SOFTWARE_START_INJECTED       // 检查是否为注入组软件启动
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED ADC_IS_CONVERSION_ONGOING_REGULAR_INJECTED // 检查规则组和注入组转换是否正在进行
#define __HAL_ADC_IS_CONVERSION_ONGOING_REGULAR          ADC_IS_CONVERSION_ONGOING_REGULAR    // 检查规则组转换是否正在进行
#define __HAL_ADC_IS_CONVERSION_ONGOING_INJECTED         ADC_IS_CONVERSION_ONGOING_INJECTED   // 检查注入组转换是否正在进行
#define __HAL_ADC_IS_CONVERSION_ONGOING                  ADC_IS_CONVERSION_ONGOING            // 检查转换是否正在进行
#define __HAL_ADC_CLEAR_ERRORCODE                        ADC_CLEAR_ERRORCODE                  // 清除错误代码

// ADC配置与参数获取相关宏
#define __HAL_ADC_GET_RESOLUTION                         ADC_GET_RESOLUTION                   // 获取ADC分辨率
#define __HAL_ADC_JSQR_RK                                ADC_JSQR_RK                          // 注入序列寄存器配置
#define __HAL_ADC_CFGR_AWD1CH                            ADC_CFGR_AWD1CH_SHIFT                // 模拟看门狗1通道移位
#define __HAL_ADC_CFGR_AWD23CR                           ADC_CFGR_AWD23CR                     // 模拟看门狗2/3配置
#define __HAL_ADC_CFGR_INJECT_AUTO_CONVERSION            ADC_CFGR_INJECT_AUTO_CONVERSION      // 注入组自动转换配置
#define __HAL_ADC_CFGR_INJECT_CONTEXT_QUEUE              ADC_CFGR_INJECT_CONTEXT_QUEUE        // 注入组上下文队列配置
#define __HAL_ADC_CFGR_INJECT_DISCCONTINUOUS             ADC_CFGR_INJECT_DISCCONTINUOUS       // 注入组不连续模式配置
#define __HAL_ADC_CFGR_REG_DISCCONTINUOUS                ADC_CFGR_REG_DISCCONTINUOUS          // 规则组不连续模式配置
#define __HAL_ADC_CFGR_DISCONTINUOUS_NUM                 ADC_CFGR_DISCONTINUOUS_NUM           // 不连续模式通道数配置
#define __HAL_ADC_CFGR_AUTOWAIT                          ADC_CFGR_AUTOWAIT                    // 自动延迟配置
#define __HAL_ADC_CFGR_CONTINUOUS                        ADC_CFGR_CONTINUOUS                  // 连续转换模式配置
#define __HAL_ADC_CFGR_OVERRUN                           ADC_CFGR_OVERRUN                     // 溢出处理配置
#define __HAL_ADC_CFGR_DMACONTREQ                        ADC_CFGR_DMACONTREQ                  // DMA连续请求配置
#define __HAL_ADC_CFGR_EXTSEL                            ADC_CFGR_EXTSEL_SET                  // 规则组外部触发源选择
#define __HAL_ADC_JSQR_JEXTSEL                           ADC_JSQR_JEXTSEL_SET                 // 注入组外部触发源选择
#define __HAL_ADC_OFR_CHANNEL                            ADC_OFR_CHANNEL                      // 偏移量通道配置
#define __HAL_ADC_DIFSEL_CHANNEL                         ADC_DIFSEL_CHANNEL                   // 差分模式通道选择
#define __HAL_ADC_CALFACT_DIFF_SET                       ADC_CALFACT_DIFF_SET                 // 设置差分校准因子
#define __HAL_ADC_CALFACT_DIFF_GET                       ADC_CALFACT_DIFF_GET                 // 获取差分校准因子
#define __HAL_ADC_TRX_HIGHTHRESHOLD                      ADC_TRX_HIGHTHRESHOLD                // 高阈值配置

// ADC阈值与分辨率相关宏
#define __HAL_ADC_OFFSET_SHIFT_RESOLUTION                ADC_OFFSET_SHIFT_RESOLUTION          // 偏移量分辨率移位
#define __HAL_ADC_AWD1THRESHOLD_SHIFT_RESOLUTION         ADC_AWD1THRESHOLD_SHIFT_RESOLUTION   // 看门狗1阈值分辨率移位
#define __HAL_ADC_AWD23THRESHOLD_SHIFT_RESOLUTION        ADC_AWD23THRESHOLD_SHIFT_RESOLUTION  // 看门狗2/3阈值分辨率移位
#define __HAL_ADC_COMMON_REGISTER                        ADC_COMMON_REGISTER                  // ADC通用寄存器
#define __HAL_ADC_COMMON_CCR_MULTI                       ADC_COMMON_CCR_MULTI                 // 多模式配置
#define __HAL_ADC_MULTIMODE_IS_ENABLED                   ADC_MULTIMODE_IS_ENABLE              // 检查多模式是否使能
#define __ADC_MULTIMODE_IS_ENABLED                       ADC_MULTIMODE_IS_ENABLE              // 检查多模式是否使能
#define __HAL_ADC_NONMULTIMODE_OR_MULTIMODEMASTER        ADC_NONMULTIMODE_OR_MULTIMODEMASTER  // 非多模式或多模式主设备检查
#define __HAL_ADC_COMMON_ADC_OTHER                       ADC_COMMON_ADC_OTHER                 // 其他ADC通用设置
#define __HAL_ADC_MULTI_SLAVE                            ADC_MULTI_SLAVE                      // 多模式从设备配置

// ADC寄存器操作相关宏
#define __HAL_ADC_SQR1_L                                 ADC_SQR1_L_SHIFT                     // 规则序列长度移位
#define __HAL_ADC_JSQR_JL                                ADC_JSQR_JL_SHIFT                    // 注入序列长度移位
#define __HAL_ADC_JSQR_RK_JL                             ADC_JSQR_RK_JL                       // 注入序列配置
#define __HAL_ADC_CR1_DISCONTINUOUS_NUM                  ADC_CR1_DISCONTINUOUS_NUM            // 不连续模式通道数
#define __HAL_ADC_CR1_SCAN                               ADC_CR1_SCAN_SET                     // 扫描模式设置
#define __HAL_ADC_CONVCYCLES_MAX_RANGE                   ADC_CONVCYCLES_MAX_RANGE             // 最大转换周期范围
#define __HAL_ADC_CLOCK_PRESCALER_RANGE                  ADC_CLOCK_PRESCALER_RANGE            // 时钟预分频范围
#define __HAL_ADC_GET_CLOCK_PRESCALER                    ADC_GET_CLOCK_PRESCALER              // 获取时钟预分频值

// ADC寄存器映射宏
#define __HAL_ADC_SQR1                                   ADC_SQR1                             // 规则序列寄存器1
#define __HAL_ADC_SMPR1                                  ADC_SMPR1                            // 采样时间寄存器1
#define __HAL_ADC_SMPR2                                  ADC_SMPR2                            // 采样时间寄存器2
#define __HAL_ADC_SQR3_RK                                ADC_SQR3_RK                          // 规则序列寄存器3通道配置
#define __HAL_ADC_SQR2_RK                                ADC_SQR2_RK                          // 规则序列寄存器2通道配置
#define __HAL_ADC_SQR1_RK                                ADC_SQR1_RK                          // 规则序列寄存器1通道配置
#define __HAL_ADC_CR2_CONTINUOUS                         ADC_CR2_CONTINUOUS                   // 连续转换模式
#define __HAL_ADC_CR1_DISCONTINUOUS                      ADC_CR1_DISCONTINUOUS                // 不连续模式
#define __HAL_ADC_CR1_SCANCONV                           ADC_CR1_SCANCONV                     // 扫描转换模式
#define __HAL_ADC_CR2_EOCSelection                       ADC_CR2_EOCSelection                 // EOC(转换结束)选择
#define __HAL_ADC_CR2_DMAContReq                         ADC_CR2_DMAContReq                   // DMA连续请求
#define __HAL_ADC_JSQR                                   ADC_JSQR                             // 注入序列寄存器

// ADC通道选择与配置寄存器宏
#define __HAL_ADC_CHSELR_CHANNEL                         ADC_CHSELR_CHANNEL                   // 通道选择寄存器
#define __HAL_ADC_CFGR1_REG_DISCCONTINUOUS               ADC_CFGR1_REG_DISCCONTINUOUS         // 规则组不连续模式
#define __HAL_ADC_CFGR1_AUTOOFF                          ADC_CFGR1_AUTOOFF                    // 自动关闭模式
#define __HAL_ADC_CFGR1_AUTOWAIT                         ADC_CFGR1_AUTOWAIT                   // 自动等待模式
#define __HAL_ADC_CFGR1_CONTINUOUS                       ADC_CFGR1_CONTINUOUS                 // 连续转换模式
#define __HAL_ADC_CFGR1_OVERRUN                          ADC_CFGR1_OVERRUN                    // 溢出处理
#define __HAL_ADC_CFGR1_SCANDIR                          ADC_CFGR1_SCANDIR                    // 扫描方向
#define __HAL_ADC_CFGR1_DMACONTREQ                       ADC_CFGR1_DMACONTREQ                 // DMA连续请求

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC 别名宏（用于保持旧代码兼容性）
  * @{
  */
// DAC(数模转换器)对齐与配置相关宏
#define __HAL_DHR12R1_ALIGNEMENT                        DAC_DHR12R1_ALIGNMENT              // 通道1 12位右对齐数据保持寄存器对齐
#define __HAL_DHR12R2_ALIGNEMENT                        DAC_DHR12R2_ALIGNMENT              // 通道2 12位右对齐数据保持寄存器对齐
#define __HAL_DHR12RD_ALIGNEMENT                        DAC_DHR12RD_ALIGNMENT              // 双通道 12位右对齐数据保持寄存器对齐
#define IS_DAC_GENERATE_WAVE                            IS_DAC_WAVE                        // 检查是否为DAC生成的波形

/**
  * @}
  */

/** @defgroup HAL_DBGMCU_Aliased_Macros HAL DBGMCU 别名宏（用于保持旧代码兼容性）
  * @{
  */
// 调试接口定时器冻结/解冻控制宏，用于调试时暂停定时器
#define __HAL_FREEZE_TIM1_DBGMCU __HAL_DBGMCU_FREEZE_TIM1                    // 冻结TIM1
#define __HAL_UNFREEZE_TIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM1                // 解冻TIM1
#define __HAL_FREEZE_TIM2_DBGMCU __HAL_DBGMCU_FREEZE_TIM2                    // 冻结TIM2
#define __HAL_UNFREEZE_TIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM2                // 解冻TIM2
#define __HAL_FREEZE_TIM3_DBGMCU __HAL_DBGMCU_FREEZE_TIM3                    // 冻结TIM3
#define __HAL_UNFREEZE_TIM3_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM3                // 解冻TIM3
#define __HAL_FREEZE_TIM4_DBGMCU __HAL_DBGMCU_FREEZE_TIM4                    // 冻结TIM4
#define __HAL_UNFREEZE_TIM4_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM4                // 解冻TIM4
#define __HAL_FREEZE_TIM5_DBGMCU __HAL_DBGMCU_FREEZE_TIM5                    // 冻结TIM5
#define __HAL_UNFREEZE_TIM5_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM5                // 解冻TIM5
#define __HAL_FREEZE_TIM6_DBGMCU __HAL_DBGMCU_FREEZE_TIM6                    // 冻结TIM6
#define __HAL_UNFREEZE_TIM6_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM6                // 解冻TIM6
#define __HAL_FREEZE_TIM7_DBGMCU __HAL_DBGMCU_FREEZE_TIM7                    // 冻结TIM7
#define __HAL_UNFREEZE_TIM7_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM7                // 解冻TIM7
#define __HAL_FREEZE_TIM8_DBGMCU __HAL_DBGMCU_FREEZE_TIM8                    // 冻结TIM8
#define __HAL_UNFREEZE_TIM8_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM8                // 解冻TIM8

#define __HAL_FREEZE_TIM9_DBGMCU __HAL_DBGMCU_FREEZE_TIM9                    // 冻结TIM9
#define __HAL_UNFREEZE_TIM9_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM9                // 解冻TIM9
#define __HAL_FREEZE_TIM10_DBGMCU __HAL_DBGMCU_FREEZE_TIM10                  // 冻结TIM10
#define __HAL_UNFREEZE_TIM10_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM10              // 解冻TIM10
#define __HAL_FREEZE_TIM11_DBGMCU __HAL_DBGMCU_FREEZE_TIM11                  // 冻结TIM11
#define __HAL_UNFREEZE_TIM11_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM11              // 解冻TIM11
#define __HAL_FREEZE_TIM12_DBGMCU __HAL_DBGMCU_FREEZE_TIM12                  // 冻结TIM12
#define __HAL_UNFREEZE_TIM12_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM12              // 解冻TIM12
#define __HAL_FREEZE_TIM13_DBGMCU __HAL_DBGMCU_FREEZE_TIM13                  // 冻结TIM13
#define __HAL_UNFREEZE_TIM13_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM13              // 解冻TIM13
#define __HAL_FREEZE_TIM14_DBGMCU __HAL_DBGMCU_FREEZE_TIM14                  // 冻结TIM14
#define __HAL_UNFREEZE_TIM14_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM14              // 解冻TIM14
#define __HAL_FREEZE_CAN2_DBGMCU __HAL_DBGMCU_FREEZE_CAN2                    // 冻结CAN2
#define __HAL_UNFREEZE_CAN2_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN2                // 解冻CAN2


#define __HAL_FREEZE_TIM15_DBGMCU __HAL_DBGMCU_FREEZE_TIM15                  // 冻结TIM15
#define __HAL_UNFREEZE_TIM15_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM15              // 解冻TIM15
#define __HAL_FREEZE_TIM16_DBGMCU __HAL_DBGMCU_FREEZE_TIM16                  // 冻结TIM16
#define __HAL_UNFREEZE_TIM16_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM16              // 解冻TIM16
#define __HAL_FREEZE_TIM17_DBGMCU __HAL_DBGMCU_FREEZE_TIM17                  // 冻结TIM17
#define __HAL_UNFREEZE_TIM17_DBGMCU __HAL_DBGMCU_UNFREEZE_TIM17              // 解冻TIM17
#define __HAL_FREEZE_RTC_DBGMCU __HAL_DBGMCU_FREEZE_RTC                      // 冻结RTC(实时时钟)
#define __HAL_UNFREEZE_RTC_DBGMCU __HAL_DBGMCU_UNFREEZE_RTC                  // 解冻RTC
#if defined(STM32H7)
// H7系列看门狗冻结/解冻宏
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG1                   // 冻结窗口看门狗1
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UnFreeze_WWDG1               // 解冻窗口看门狗1
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG1                   // 冻结独立看门狗1
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UnFreeze_IWDG1               // 解冻独立看门狗1
#else
// 其他系列看门狗冻结/解冻宏
#define __HAL_FREEZE_WWDG_DBGMCU __HAL_DBGMCU_FREEZE_WWDG                    // 冻结窗口看门狗
#define __HAL_UNFREEZE_WWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_WWDG                // 解冻窗口看门狗
#define __HAL_FREEZE_IWDG_DBGMCU __HAL_DBGMCU_FREEZE_IWDG                    // 冻结独立看门狗
#define __HAL_UNFREEZE_IWDG_DBGMCU __HAL_DBGMCU_UNFREEZE_IWDG                // 解冻独立看门狗
#endif /* STM32H7 */
// I2C超时冻结/解冻宏
#define __HAL_FREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT    // 冻结I2C1超时
#define __HAL_UNFREEZE_I2C1_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT // 解冻I2C1超时
#define __HAL_FREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT    // 冻结I2C2超时
#define __HAL_UNFREEZE_I2C2_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT // 解冻I2C2超时
#define __HAL_FREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_FREEZE_I2C3_TIMEOUT    // 冻结I2C3超时
#define __HAL_UNFREEZE_I2C3_TIMEOUT_DBGMCU __HAL_DBGMCU_UNFREEZE_I2C3_TIMEOUT // 解冻I2C3超时
#define __HAL_FREEZE_CAN1_DBGMCU __HAL_DBGMCU_FREEZE_CAN1                    // 冻结CAN1
#define __HAL_UNFREEZE_CAN1_DBGMCU __HAL_DBGMCU_UNFREEZE_CAN1                // 解冻CAN1
#define __HAL_FREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM1                // 冻结低功耗定时器1
#define __HAL_UNFREEZE_LPTIM1_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM1            // 解冻低功耗定时器1
#define __HAL_FREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_FREEZE_LPTIM2                // 冻结低功耗定时器2
#define __HAL_UNFREEZE_LPTIM2_DBGMCU __HAL_DBGMCU_UNFREEZE_LPTIM2            // 解冻低功耗定时器2

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Macros HAL COMP 别名宏（用于保持旧代码兼容性）
  * @{
  */
#if defined(STM32F3)
// COMP(比较器)控制宏定义
#define COMP_START                                       __HAL_COMP_ENABLE                  // 启动比较器(使能)
#define COMP_STOP                                        __HAL_COMP_DISABLE                 // 停止比较器(禁用)
#define COMP_LOCK                                        __HAL_COMP_LOCK                    // 锁定比较器配置
/* 针对STM32F301x8, STM32F302x8, STM32F318xx, STM32F303x8, STM32F334x8, STM32F328xx 系列器件的配置 */
#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || defined(STM32F303x8) || \
    defined(STM32F334x8) || defined(STM32F328xx)

/* 使能比较器外部中断上升沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线，例如 COMP_EXTI_LINE_COMP2 */
/* 该宏根据传入的中断线，调用对应的具体函数来使能上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来禁能上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来使能下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来禁能下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来使能中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来禁能中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
/* 参数 __FLAG__: 比较器中断标志，对应具体的中断线 */
/* 返回值: 中断标志状态 (SET 或 RESET) */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
/* 参数 __FLAG__: 比较器中断标志，对应具体的中断线 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())
#endif

/* 针对STM32F302xE, STM32F302xC 系列器件的配置 */
#if defined(STM32F302xE) || defined(STM32F302xC)

/* 使能比较器外部中断上升沿触发 */
/* 支持 COMP1, COMP2, COMP4, COMP6 四个比较器的中断线 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())
#endif

/* 针对STM32F303xE, STM32F398xx, STM32F303xC, STM32F358xx 系列器件的配置 */
/* 这些系列拥有更多的比较器资源 (COMP1-COMP7) */
#if defined(STM32F303xE) || defined(STM32F398xx) || defined(STM32F303xC) || defined(STM32F358xx)

/* 使能比较器外部中断上升沿触发 */
/* 支持 COMP1 至 COMP7 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_CLEAR_FLAG())
#endif

/* 针对STM32F373xC, STM32F378xx 系列器件的配置 */
/* 这些系列仅支持 COMP1 和 COMP2 */
#if defined(STM32F373xC) ||defined(STM32F378xx)

/* 使能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())
#endif

/* 其他STM32系列的通用配置 (默认仅支持 COMP1 和 COMP2) */
#else
/* 使能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())
#endif

/* 获取比较器对应的外部中断线宏定义 */
#define __HAL_COMP_GET_EXTI_LINE  COMP_GET_EXTI_LINE

/* 针对STM32L0和STM32L4系列的特定配置 */
#if defined(STM32L0) || defined(STM32L4)
/* 注意: 在这些STM32系列中，此宏的唯一参数是 COMP_FLAG_LOCK */
/*       此宏已被 __HAL_COMP_IS_LOCKED 取代，后者仅接受 HAL 句柄参数 */
/* 获取比较器标志状态 (用于检查锁定状态) */
/* 参数 __HANDLE__: COMP句柄指针 */
/* 参数 __FLAG__: 标志位，此处特指锁定标志 */
#define __HAL_COMP_GET_FLAG(__HANDLE__, __FLAG__)  (__HAL_COMP_IS_LOCKED(__HANDLE__))
#endif
/**
  * @}
  */
#if defined(STM32L0) || defined(STM32L4)
/** @defgroup HAL_COMP_Aliased_Functions HAL COMP别名函数（用于保持旧版兼容性）
  * @{
  */
/* 将旧版中断启动函数映射为新版普通启动函数，因为EXTI事件或中断配置已移至HAL_COMP_Init()中处理 */
#define HAL_COMP_Start_IT       HAL_COMP_Start 
/* 将旧版中断停止函数映射为新版普通停止函数，因为EXTI事件或中断配置已移至HAL_COMP_Init()中处理 */
#define HAL_COMP_Stop_IT        HAL_COMP_Stop  
/**
  * @}
  */
#endif

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC别名宏（用于保持旧版兼容性）
  * @{
  */

/* 检查DAC波形生成参数是否合法 */
/* 参数说明：WAVE可以是 DAC_WAVE_NONE(无波形), DAC_WAVE_NOISE(噪声), DAC_WAVE_TRIANGLE(三角波) */
#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_WAVE_NONE) || \
                           ((WAVE) == DAC_WAVE_NOISE)|| \
                           ((WAVE) == DAC_WAVE_TRIANGLE))

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Macros HAL FLASH别名宏（用于保持旧版兼容性）
  * @{
  */

/* 旧版写保护区域检查宏，映射为新版IS_OB_WRPAREA */
#define IS_WRPAREA          IS_OB_WRPAREA
/* 旧版编程类型检查宏，映射为新版IS_FLASH_TYPEPROGRAM */
#define IS_TYPEPROGRAM      IS_FLASH_TYPEPROGRAM
/* 旧版Flash编程类型检查宏，映射为新版IS_FLASH_TYPEPROGRAM */
#define IS_TYPEPROGRAMFLASH IS_FLASH_TYPEPROGRAM
/* 旧版擦除类型检查宏，映射为新版IS_FLASH_TYPEERASE */
#define IS_TYPEERASE        IS_FLASH_TYPEERASE
/* 旧版扇区数量检查宏，映射为新版IS_FLASH_NBSECTORS */
#define IS_NBSECTORS        IS_FLASH_NBSECTORS
/* 旧版看门狗源检查宏，映射为新版IS_OB_IWDG_SOURCE */
#define IS_OB_WDG_SOURCE    IS_OB_IWDG_SOURCE

/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Macros HAL I2C别名宏（用于保持旧版兼容性）
  * @{
  */

/* 复位I2C CR2寄存器 */
#define __HAL_I2C_RESET_CR2             I2C_RESET_CR2
/* 产生I2C起始信号 */
#define __HAL_I2C_GENERATE_START        I2C_GENERATE_START
#if defined(STM32F1)
/* STM32F1系列频率范围宏定义 */
#define __HAL_I2C_FREQ_RANGE            I2C_FREQRANGE
#else
/* 非STM32F1系列频率范围宏定义 */
#define __HAL_I2C_FREQ_RANGE            I2C_FREQ_RANGE
#endif /* STM32F1 */
/* 计算I2C上升时间 */
#define __HAL_I2C_RISE_TIME             I2C_RISE_TIME
/* 设置I2C标准速度模式 */
#define __HAL_I2C_SPEED_STANDARD        I2C_SPEED_STANDARD
/* 设置I2C快速速度模式 */
#define __HAL_I2C_SPEED_FAST            I2C_SPEED_FAST
/* I2C速度设置宏 */
#define __HAL_I2C_SPEED                 I2C_SPEED
/* I2C 7位地址写模式 */
#define __HAL_I2C_7BIT_ADD_WRITE        I2C_7BIT_ADD_WRITE
/* I2C 7位地址读模式 */
#define __HAL_I2C_7BIT_ADD_READ         I2C_7BIT_ADD_READ
/* I2C 10位地址处理 */
#define __HAL_I2C_10BIT_ADDRESS         I2C_10BIT_ADDRESS
/* I2C 10位地址头写模式 */
#define __HAL_I2C_10BIT_HEADER_WRITE    I2C_10BIT_HEADER_WRITE
/* I2C 10位地址头读模式 */
#define __HAL_I2C_10BIT_HEADER_READ     I2C_10BIT_HEADER_READ
/* 获取I2C内存地址高字节 */
#define __HAL_I2C_MEM_ADD_MSB           I2C_MEM_ADD_MSB
/* 获取I2C内存地址低字节 */
#define __HAL_I2C_MEM_ADD_LSB           I2C_MEM_ADD_LSB
/* I2C频率范围定义 */
#define __HAL_I2C_FREQRANGE             I2C_FREQRANGE
/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Macros HAL I2S别名宏（用于保持旧版兼容性）
  * @{
  */

/* 检查是否为I2S实例 */
#define IS_I2S_INSTANCE                 IS_I2S_ALL_INSTANCE
/* 检查是否为扩展I2S实例 */
#define IS_I2S_INSTANCE_EXT             IS_I2S_ALL_INSTANCE_EXT

#if defined(STM32H7)
/* STM32H7系列清除I2S帧错误标志 */
#define __HAL_I2S_CLEAR_FREFLAG       __HAL_I2S_CLEAR_TIFREFLAG
#endif

/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Macros HAL IRDA别名宏（用于保持旧版兼容性）
  * @{
  */

/* 禁用IRDA外设 */
#define __IRDA_DISABLE                  __HAL_IRDA_DISABLE
/* 使能IRDA外设 */
#define __IRDA_ENABLE                   __HAL_IRDA_ENABLE

/* 获取IRDA时钟源 */
#define __HAL_IRDA_GETCLOCKSOURCE       IRDA_GETCLOCKSOURCE
/* IRDA掩码计算 */
#define __HAL_IRDA_MASK_COMPUTATION     IRDA_MASK_COMPUTATION
/* 获取IRDA时钟源（旧版命名） */
#define __IRDA_GETCLOCKSOURCE           IRDA_GETCLOCKSOURCE
/* IRDA掩码计算（旧版命名） */
#define __IRDA_MASK_COMPUTATION         IRDA_MASK_COMPUTATION

/* 检查IRDA单比特采样配置 */
#define IS_IRDA_ONEBIT_SAMPLE           IS_IRDA_ONE_BIT_SAMPLE


/**
  * @}
  */


/** @defgroup HAL_IWDG_Aliased_Macros HAL IWDG别名宏（用于保持旧版兼容性）
  * @{
  */
/* 使能独立看门狗写访问权限 */
#define __HAL_IWDG_ENABLE_WRITE_ACCESS  IWDG_ENABLE_WRITE_ACCESS
/* 禁用独立看门狗写访问权限 */
#define __HAL_IWDG_DISABLE_WRITE_ACCESS IWDG_DISABLE_WRITE_ACCESS
/**
  * @}
  */


/** @defgroup HAL_LPTIM_Aliased_Macros HAL LPTIM别名宏（用于保持旧版兼容性）
  * @{
  */

/* 使能LPTIM中断（旧版命名映射为新版IT宏） */
#define __HAL_LPTIM_ENABLE_INTERRUPT    __HAL_LPTIM_ENABLE_IT
/* 禁用LPTIM中断（旧版命名映射为新版IT宏） */
#define __HAL_LPTIM_DISABLE_INTERRUPT   __HAL_LPTIM_DISABLE_IT
/* 获取LPTIM中断状态（旧版命名映射为新版SOURCE宏） */
#define __HAL_LPTIM_GET_ITSTATUS        __HAL_LPTIM_GET_IT_SOURCE

/**
  * @}
  */


/** @defgroup HAL_OPAMP_Aliased_Macros HAL OPAMP别名宏（用于保持旧版兼容性）
  * @{
  */
/* 运放CSR寄存器：运放电源控制位 */
#define __OPAMP_CSR_OPAXPD                OPAMP_CSR_OPAXPD
/* 运放CSR寄存器：开关S3选择位 */
#define __OPAMP_CSR_S3SELX                OPAMP_CSR_S3SELX
/* 运放CSR寄存器：开关S4选择位 */
#define __OPAMP_CSR_S4SELX                OPAMP_CSR_S4SELX
/* 运放CSR寄存器：开关S5选择位 */
#define __OPAMP_CSR_S5SELX                OPAMP_CSR_S5SELX
/* 运放CSR寄存器：开关S6选择位 */
#define __OPAMP_CSR_S6SELX                OPAMP_CSR_S6SELX
/* 运放CSR寄存器：低位校准位 */
#define __OPAMP_CSR_OPAXCAL_L             OPAMP_CSR_OPAXCAL_L
/* 运放CSR寄存器：高位校准位 */
#define __OPAMP_CSR_OPAXCAL_H             OPAMP_CSR_OPAXCAL_H
/* 运放CSR寄存器：低功耗模式位 */
#define __OPAMP_CSR_OPAXLPM               OPAMP_CSR_OPAXLPM
/* 运放CSR寄存器：所有开关掩码 */
#define __OPAMP_CSR_ALL_SWITCHES          OPAMP_CSR_ALL_SWITCHES
/* 运放CSR寄存器：模拟开关选择 */
#define __OPAMP_CSR_ANAWSELX              OPAMP_CSR_ANAWSELX
/* 运放CSR寄存器：校准输出位 */
#define __OPAMP_CSR_OPAXCALOUT            OPAMP_CSR_OPAXCALOUT
/* 运放偏移修剪位位置定义 */
#define __OPAMP_OFFSET_TRIM_BITSPOSITION  OPAMP_OFFSET_TRIM_BITSPOSITION
/* 运放偏移修剪设置 */
#define __OPAMP_OFFSET_TRIM_SET           OPAMP_OFFSET_TRIM_SET

/**
  * @}
  */


/** @defgroup HAL_PWR_Aliased_Macros HAL PWR别名宏（用于保持旧版兼容性）
  * @{
  */
/* 禁用PVD（可编程电压检测器）事件 */
#define __HAL_PVD_EVENT_DISABLE                                  __HAL_PWR_PVD_EXTI_DISABLE_EVENT
/* 使能PVD事件 */
#define __HAL_PVD_EVENT_ENABLE                                   __HAL_PWR_PVD_EXTI_ENABLE_EVENT
/* 禁用PVD EXTI下降沿触发 */
#define __HAL_PVD_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
/* 使能PVD EXTI下降沿触发 */
#define __HAL_PVD_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
/* 禁用PVD EXTI上升沿触发 */
#define __HAL_PVD_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
/* 使能PVD EXTI上升沿触发 */
#define __HAL_PVD_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
/* 禁用PVM（外设电压监测）事件 */
#define __HAL_PVM_EVENT_DISABLE                                  __HAL_PWR_PVM_EVENT_DISABLE
/* 使能PVM事件 */
#define __HAL_PVM_EVENT_ENABLE                                   __HAL_PWR_PVM_EVENT_ENABLE
/* 禁用PVM EXTI下降沿触发 */
#define __HAL_PVM_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_DISABLE
/* 使能PVM EXTI下降沿触发 */
#define __HAL_PVM_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_ENABLE
/* 禁用PVM EXTI上升沿触发 */
#define __HAL_PVM_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVM_EXTI_RISINGTRIGGER_DISABLE
/* 使能PVM EXTI上升沿触发 */
#define __HAL_PVM_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVM_EXTI_RISINGTRIGGER_ENABLE
/* 禁用内部唤醒线路 */
#define __HAL_PWR_INTERNALWAKEUP_DISABLE                         HAL_PWREx_DisableInternalWakeUpLine
/* 使能内部唤醒线路 */
#define __HAL_PWR_INTERNALWAKEUP_ENABLE                          HAL_PWREx_EnableInternalWakeUpLine
/* 禁用上下拉配置 */
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_DISABLE                    HAL_PWREx_DisablePullUpPullDownConfig
/* 使能上下拉配置 */
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_ENABLE                     HAL_PWREx_EnablePullUpPullDownConfig
/* 清除PVD EXTI边沿触发（同时禁用上升沿和下降沿） */
#define __HAL_PWR_PVD_EXTI_CLEAR_EGDE_TRIGGER()                  do { __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE(); \
                                                                      __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); \
                                                                    } while(0)
/* 禁用PVD EXTI事件 */
#define __HAL_PWR_PVD_EXTI_EVENT_DISABLE                         __HAL_PWR_PVD_EXTI_DISABLE_EVENT
/* 使能PVD EXTI事件 */
#define __HAL_PWR_PVD_EXTI_EVENT_ENABLE                          __HAL_PWR_PVD_EXTI_ENABLE_EVENT
/* 禁用PVD EXTI下降沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_DISABLE                __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE
/* 使能PVD EXTI下降沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_ENABLE                 __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
/* 禁用PVD EXTI上升沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_DISABLE                 __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE
/* 使能PVD EXTI上升沿触发（新版命名） */
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_ENABLE                  __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
/* 设置PVD EXTI下降沿触发 */
#define __HAL_PWR_PVD_EXTI_SET_FALLING_EGDE_TRIGGER              __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE
/* 设置PVD EXTI上升沿触发 */
#define __HAL_PWR_PVD_EXTI_SET_RISING_EDGE_TRIGGER               __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE
/* 禁用所有PVM（外设电压监测器1-4） */
#define __HAL_PWR_PVM_DISABLE()                                  do { HAL_PWREx_DisablePVM1();HAL_PWREx_DisablePVM2(); \
                                                                      HAL_PWREx_DisablePVM3();HAL_PWREx_DisablePVM4(); \
                                                                    } while(0)
/* 使能所有PVM（外设电压监测器1-4） */
#define __HAL_PWR_PVM_ENABLE()                                   do { HAL_PWREx_EnablePVM1();HAL_PWREx_EnablePVM2(); \
                                                                      HAL_PWREx_EnablePVM3();HAL_PWREx_EnablePVM4(); \
                                                                    } while(0)
/* 禁用SRAM2内容保留功能 */
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_DISABLE                  HAL_PWREx_DisableSRAM2ContentRetention
/* 使能SRAM2内容保留功能 */
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_ENABLE                   HAL_PWREx_EnableSRAM2ContentRetention
/* 禁用VDDIO2电源 */
#define __HAL_PWR_VDDIO2_DISABLE                                 HAL_PWREx_DisableVddIO2
/* 使能VDDIO2电源 */
#define __HAL_PWR_VDDIO2_ENABLE                                  HAL_PWREx_EnableVddIO2
/* 清除VDDIO2 EXTI边沿触发 */
#define __HAL_PWR_VDDIO2_EXTI_CLEAR_EGDE_TRIGGER                 __HAL_PWR_VDDIO2_EXTI_DISABLE_FALLING_EDGE
/* 设置VDDIO2 EXTI下降沿触发 */
#define __HAL_PWR_VDDIO2_EXTI_SET_FALLING_EGDE_TRIGGER           __HAL_PWR_VDDIO2_EXTI_ENABLE_FALLING_EDGE
/* 禁用VDDUSB电源 */
#define __HAL_PWR_VDDUSB_DISABLE                                 HAL_PWREx_DisableVddUSB
/* 使能VDDUSB电源 */
#define __HAL_PWR_VDDUSB_ENABLE                                  HAL_PWREx_EnableVddUSB

#if defined (STM32F4)
/* STM32F4系列：使能PVD EXTI中断，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_ENABLE_IT(PWR_EXTI_LINE_PVD)         __HAL_PWR_PVD_EXTI_ENABLE_IT()
/* STM32F4系列：禁用PVD EXTI中断，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_DISABLE_IT(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_DISABLE_IT()
/* STM32F4系列：获取PVD EXTI标志，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_GET_FLAG(PWR_EXTI_LINE_PVD)          __HAL_PWR_PVD_EXTI_GET_FLAG()
/* STM32F4系列：清除PVD EXTI标志，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_CLEAR_FLAG(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_CLEAR_FLAG()
/* STM32F4系列：产生PVD软件中断，参数为PWR_EXTI_LINE_PVD */
#define __HAL_PVD_EXTI_GENERATE_SWIT(PWR_EXTI_LINE_PVD)     __HAL_PWR_PVD_EXTI_GENERATE_SWIT()
#else
/* 非STM32F4系列：清除PVD EXTI标志 */
#define __HAL_PVD_EXTI_CLEAR_FLAG                                __HAL_PWR_PVD_EXTI_CLEAR_FLAG
/* 非STM32F4系列：禁用PVD EXTI中断 */
#define __HAL_PVD_EXTI_DISABLE_IT                                __HAL_PWR_PVD_EXTI_DISABLE_IT
/* 非STM32F4系列：使能PVD EXTI中断 */
#define __HAL_PVD_EXTI_ENABLE_IT                                 __HAL_PWR_PVD_EXTI_ENABLE_IT
/* 非STM32F4系列：产生PVD软件中断 */
#define __HAL_PVD_EXTI_GENERATE_SWIT                             __HAL_PWR_PVD_EXTI_GENERATE_SWIT
/* 非STM32F4系列：获取PVD EXTI标志 */
#define __HAL_PVD_EXTI_GET_FLAG                                  __HAL_PWR_PVD_EXTI_GET_FLAG
#endif /* STM32F4 */
/**
  * @}
  */


/** @defgroup HAL_RCC_Aliased HAL RCC别名宏（用于保持旧版兼容性）
  * @{
  */

/* 停机模式唤醒时钟选择MSI */
#define RCC_StopWakeUpClock_MSI     RCC_STOP_WAKEUPCLOCK_MSI
/* 停机模式唤醒时钟选择HSI */
#define RCC_StopWakeUpClock_HSI     RCC_STOP_WAKEUPCLOCK_HSI

/* 时钟安全系统(CSS)回调函数别名，修正旧版拼写错误(CCSCallback -> CSSCallback) */
#define HAL_RCC_CCSCallback HAL_RCC_CSSCallback
/* RC48使能缓冲命令：根据参数使能或禁用HSI48 VREFINT缓冲 */
#define HAL_RC48_EnableBuffer_Cmd(cmd) (((cmd)==ENABLE) ? \
                                        HAL_RCCEx_EnableHSI48_VREFINT() : HAL_RCCEx_DisableHSI48_VREFINT())
/*
  本段代码主要定义了STM32系列芯片中各种外设的时钟控制宏。
  这些宏是对HAL库底层寄存器操作函数的别名封装，目的是为了保持代码的兼容性或提供更直观的命名。
  主要涉及的操作类型包括：
  1. CLK_ENABLE/DISABLE：使能或失能外设时钟（外设工作时必须开启）。
  2. CLK_SLEEP_ENABLE/DISABLE：在睡眠模式下使能或失能外设时钟（用于低功耗管理）。
  3. FORCE_RESET：强制复位外设。
  4. RELEASE_RESET：释放外设复位状态。
*/

/* ADC (模数转换器) 相关时钟控制宏定义 */
#define __ADC_CLK_DISABLE          __HAL_RCC_ADC_CLK_DISABLE              // 失能ADC时钟
#define __ADC_CLK_ENABLE           __HAL_RCC_ADC_CLK_ENABLE               // 使能ADC时钟
#define __ADC_CLK_SLEEP_DISABLE    __HAL_RCC_ADC_CLK_SLEEP_DISABLE        // 睡眠模式下失能ADC时钟
#define __ADC_CLK_SLEEP_ENABLE     __HAL_RCC_ADC_CLK_SLEEP_ENABLE         // 睡眠模式下使能ADC时钟
#define __ADC_FORCE_RESET          __HAL_RCC_ADC_FORCE_RESET              // 强制复位ADC
#define __ADC_RELEASE_RESET        __HAL_RCC_ADC_RELEASE_RESET            // 释放ADC复位

/* ADC1 专用时钟控制宏定义 */
#define __ADC1_CLK_DISABLE         __HAL_RCC_ADC1_CLK_DISABLE             // 失能ADC1时钟
#define __ADC1_CLK_ENABLE          __HAL_RCC_ADC1_CLK_ENABLE              // 使能ADC1时钟
#define __ADC1_FORCE_RESET         __HAL_RCC_ADC1_FORCE_RESET             // 强制复位ADC1
#define __ADC1_RELEASE_RESET       __HAL_RCC_ADC1_RELEASE_RESET           // 释放ADC1复位
#define __ADC1_CLK_SLEEP_ENABLE    __HAL_RCC_ADC1_CLK_SLEEP_ENABLE        // 睡眠模式下使能ADC1时钟
#define __ADC1_CLK_SLEEP_DISABLE   __HAL_RCC_ADC1_CLK_SLEEP_DISABLE       // 睡眠模式下失能ADC1时钟

/* ADC2 专用时钟控制宏定义 */
#define __ADC2_CLK_DISABLE         __HAL_RCC_ADC2_CLK_DISABLE             // 失能ADC2时钟
#define __ADC2_CLK_ENABLE          __HAL_RCC_ADC2_CLK_ENABLE              // 使能ADC2时钟
#define __ADC2_FORCE_RESET __HAL_RCC_ADC2_FORCE_RESET                     // 强制复位ADC2
#define __ADC2_RELEASE_RESET __HAL_RCC_ADC2_RELEASE_RESET                 // 释放ADC2复位

/* ADC3 专用时钟控制宏定义 */
#define __ADC3_CLK_DISABLE __HAL_RCC_ADC3_CLK_DISABLE                     // 失能ADC3时钟
#define __ADC3_CLK_ENABLE __HAL_RCC_ADC3_CLK_ENABLE                       // 使能ADC3时钟
#define __ADC3_FORCE_RESET __HAL_RCC_ADC3_FORCE_RESET                     // 强制复位ADC3
#define __ADC3_RELEASE_RESET __HAL_RCC_ADC3_RELEASE_RESET                 // 释放ADC3复位

/* AES (高级加密标准硬件加速器) 相关时钟控制宏定义 */
#define __AES_CLK_DISABLE __HAL_RCC_AES_CLK_DISABLE                       // 失能AES时钟
#define __AES_CLK_ENABLE __HAL_RCC_AES_CLK_ENABLE                         // 使能AES时钟
#define __AES_CLK_SLEEP_DISABLE __HAL_RCC_AES_CLK_SLEEP_DISABLE           // 睡眠模式下失能AES时钟
#define __AES_CLK_SLEEP_ENABLE __HAL_RCC_AES_CLK_SLEEP_ENABLE             // 睡眠模式下使能AES时钟
#define __AES_FORCE_RESET __HAL_RCC_AES_FORCE_RESET                       // 强制复位AES
#define __AES_RELEASE_RESET __HAL_RCC_AES_RELEASE_RESET                   // 释放AES复位

/* CRYP (加密处理器) 相关时钟控制宏定义，功能与AES类似 */
#define __CRYP_CLK_SLEEP_ENABLE      __HAL_RCC_CRYP_CLK_SLEEP_ENABLE      // 睡眠模式下使能CRYP时钟
#define __CRYP_CLK_SLEEP_DISABLE  __HAL_RCC_CRYP_CLK_SLEEP_DISABLE        // 睡眠模式下失能CRYP时钟
#define __CRYP_CLK_ENABLE  __HAL_RCC_CRYP_CLK_ENABLE                      // 使能CRYP时钟
#define __CRYP_CLK_DISABLE  __HAL_RCC_CRYP_CLK_DISABLE                    // 失能CRYP时钟
#define __CRYP_FORCE_RESET       __HAL_RCC_CRYP_FORCE_RESET               // 强制复位CRYP
#define __CRYP_RELEASE_RESET  __HAL_RCC_CRYP_RELEASE_RESET                // 释放CRYP复位

/* AFIO (复用功能I/O) 相关时钟控制宏定义 */
#define __AFIO_CLK_DISABLE __HAL_RCC_AFIO_CLK_DISABLE                     // 失能AFIO时钟
#define __AFIO_CLK_ENABLE __HAL_RCC_AFIO_CLK_ENABLE                       // 使能AFIO时钟
#define __AFIO_FORCE_RESET __HAL_RCC_AFIO_FORCE_RESET                     // 强制复位AFIO
#define __AFIO_RELEASE_RESET __HAL_RCC_AFIO_RELEASE_RESET                 // 释放AFIO复位

/* AHB (高级高性能总线) 总线整体复位控制 */
#define __AHB_FORCE_RESET __HAL_RCC_AHB_FORCE_RESET                       // 强制复位AHB总线
#define __AHB_RELEASE_RESET __HAL_RCC_AHB_RELEASE_RESET                   // 释放AHB总线复位

/* AHB1 总线复位控制 (STM32F4/F7等系列) */
#define __AHB1_FORCE_RESET __HAL_RCC_AHB1_FORCE_RESET                     // 强制复位AHB1总线
#define __AHB1_RELEASE_RESET __HAL_RCC_AHB1_RELEASE_RESET                 // 释放AHB1总线复位

/* AHB2 总线复位控制 */
#define __AHB2_FORCE_RESET __HAL_RCC_AHB2_FORCE_RESET                     // 强制复位AHB2总线
#define __AHB2_RELEASE_RESET __HAL_RCC_AHB2_RELEASE_RESET                 // 释放AHB2总线复位

/* AHB3 总线复位控制 (通常用于FMC等外设) */
#define __AHB3_FORCE_RESET __HAL_RCC_AHB3_FORCE_RESET                     // 强制复位AHB3总线
#define __AHB3_RELEASE_RESET __HAL_RCC_AHB3_RELEASE_RESET                 // 释放AHB3总线复位

/* APB1 (高级外设总线1) 总线复位控制 */
#define __APB1_FORCE_RESET __HAL_RCC_APB1_FORCE_RESET                     // 强制复位APB1总线
#define __APB1_RELEASE_RESET __HAL_RCC_APB1_RELEASE_RESET                 // 释放APB1总线复位

/* APB2 (高级外设总线2) 总线复位控制 */
#define __APB2_FORCE_RESET __HAL_RCC_APB2_FORCE_RESET                     // 强制复位APB2总线
#define __APB2_RELEASE_RESET __HAL_RCC_APB2_RELEASE_RESET                 // 释放APB2总线复位

#if defined(STM32C0)
/* STM32C0系列特有的APB1/APB2分组复位定义 */
#define __HAL_RCC_APB1_FORCE_RESET    __HAL_RCC_APB1_GRP1_FORCE_RESET     // 强制复位APB1组1
#define __HAL_RCC_APB1_RELEASE_RESET  __HAL_RCC_APB1_GRP1_RELEASE_RESET   // 释放APB1组1复位
#define __HAL_RCC_APB2_FORCE_RESET    __HAL_RCC_APB1_GRP2_FORCE_RESET     // 强制复位APB1组2 (对应APB2)
#define __HAL_RCC_APB2_RELEASE_RESET  __HAL_RCC_APB1_GRP2_RELEASE_RESET   // 释放APB1组2复位 (对应APB2)
#endif /* STM32C0 */

/* BKP (后备寄存器) 相关时钟控制宏定义 */
#define __BKP_CLK_DISABLE __HAL_RCC_BKP_CLK_DISABLE                       // 失能BKP时钟
#define __BKP_CLK_ENABLE __HAL_RCC_BKP_CLK_ENABLE                         // 使能BKP时钟
#define __BKP_FORCE_RESET __HAL_RCC_BKP_FORCE_RESET                       // 强制复位BKP
#define __BKP_RELEASE_RESET __HAL_RCC_BKP_RELEASE_RESET                   // 释放BKP复位

/* CAN1 (控制器局域网1) 相关时钟控制宏定义 */
#define __CAN1_CLK_DISABLE __HAL_RCC_CAN1_CLK_DISABLE                     // 失能CAN1时钟
#define __CAN1_CLK_ENABLE __HAL_RCC_CAN1_CLK_ENABLE                       // 使能CAN1时钟
#define __CAN1_CLK_SLEEP_DISABLE __HAL_RCC_CAN1_CLK_SLEEP_DISABLE         // 睡眠模式下失能CAN1时钟
#define __CAN1_CLK_SLEEP_ENABLE __HAL_RCC_CAN1_CLK_SLEEP_ENABLE           // 睡眠模式下使能CAN1时钟
#define __CAN1_FORCE_RESET __HAL_RCC_CAN1_FORCE_RESET                     // 强制复位CAN1
#define __CAN1_RELEASE_RESET __HAL_RCC_CAN1_RELEASE_RESET                 // 释放CAN1复位

/* CAN 通用别名 (默认指向CAN1) */
#define __CAN_CLK_DISABLE         __HAL_RCC_CAN1_CLK_DISABLE              // 失能CAN时钟 (别名)
#define __CAN_CLK_ENABLE          __HAL_RCC_CAN1_CLK_ENABLE               // 使能CAN时钟 (别名)
#define __CAN_FORCE_RESET         __HAL_RCC_CAN1_FORCE_RESET              // 强制复位CAN (别名)
#define __CAN_RELEASE_RESET       __HAL_RCC_CAN1_RELEASE_RESET            // 释放CAN复位 (别名)

/* CAN2 (控制器局域网2) 相关时钟控制宏定义 */
#define __CAN2_CLK_DISABLE __HAL_RCC_CAN2_CLK_DISABLE                     // 失能CAN2时钟
#define __CAN2_CLK_ENABLE __HAL_RCC_CAN2_CLK_ENABLE                       // 使能CAN2时钟
#define __CAN2_FORCE_RESET __HAL_RCC_CAN2_FORCE_RESET                     // 强制复位CAN2
#define __CAN2_RELEASE_RESET __HAL_RCC_CAN2_RELEASE_RESET                 // 释放CAN2复位

/* CEC (HDMI-CEC控制器) 相关时钟控制宏定义 */
#define __CEC_CLK_DISABLE __HAL_RCC_CEC_CLK_DISABLE                       // 失能CEC时钟
#define __CEC_CLK_ENABLE __HAL_RCC_CEC_CLK_ENABLE                         // 使能CEC时钟

/* COMP (比较器) 相关时钟控制宏定义 */
#define __COMP_CLK_DISABLE        __HAL_RCC_COMP_CLK_DISABLE              // 失能COMP时钟
#define __COMP_CLK_ENABLE         __HAL_RCC_COMP_CLK_ENABLE               // 使能COMP时钟
#define __COMP_FORCE_RESET        __HAL_RCC_COMP_FORCE_RESET              // 强制复位COMP
#define __COMP_RELEASE_RESET      __HAL_RCC_COMP_RELEASE_RESET            // 释放COMP复位
#define __COMP_CLK_SLEEP_ENABLE   __HAL_RCC_COMP_CLK_SLEEP_ENABLE         // 睡眠模式下使能COMP时钟
#define __COMP_CLK_SLEEP_DISABLE  __HAL_RCC_COMP_CLK_SLEEP_DISABLE        // 睡眠模式下失能COMP时钟

#define __CEC_FORCE_RESET __HAL_RCC_CEC_FORCE_RESET                       // 强制复位CEC
#define __CEC_RELEASE_RESET __HAL_RCC_CEC_RELEASE_RESET                   // 释放CEC复位

/* CRC (循环冗余校验计算单元) 相关时钟控制宏定义 */
#define __CRC_CLK_DISABLE __HAL_RCC_CRC_CLK_DISABLE                       // 失能CRC时钟
#define __CRC_CLK_ENABLE __HAL_RCC_CRC_CLK_ENABLE                         // 使能CRC时钟
#define __CRC_CLK_SLEEP_DISABLE __HAL_RCC_CRC_CLK_SLEEP_DISABLE           // 睡眠模式下失能CRC时钟
#define __CRC_CLK_SLEEP_ENABLE __HAL_RCC_CRC_CLK_SLEEP_ENABLE             // 睡眠模式下使能CRC时钟
#define __CRC_FORCE_RESET __HAL_RCC_CRC_FORCE_RESET                       // 强制复位CRC
#define __CRC_RELEASE_RESET __HAL_RCC_CRC_RELEASE_RESET                   // 释放CRC复位

/* DAC (数模转换器) 相关时钟控制宏定义 */
#define __DAC_CLK_DISABLE __HAL_RCC_DAC_CLK_DISABLE                       // 失能DAC时钟
#define __DAC_CLK_ENABLE __HAL_RCC_DAC_CLK_ENABLE                         // 使能DAC时钟
#define __DAC_FORCE_RESET __HAL_RCC_DAC_FORCE_RESET                       // 强制复位DAC
#define __DAC_RELEASE_RESET __HAL_RCC_DAC_RELEASE_RESET                   // 释放DAC复位

/* DAC1 专用时钟控制宏定义 */
#define __DAC1_CLK_DISABLE __HAL_RCC_DAC1_CLK_DISABLE                     // 失能DAC1时钟
#define __DAC1_CLK_ENABLE __HAL_RCC_DAC1_CLK_ENABLE                       // 使能DAC1时钟
#define __DAC1_CLK_SLEEP_DISABLE __HAL_RCC_DAC1_CLK_SLEEP_DISABLE         // 睡眠模式下失能DAC1时钟
#define __DAC1_CLK_SLEEP_ENABLE __HAL_RCC_DAC1_CLK_SLEEP_ENABLE           // 睡眠模式下使能DAC1时钟
#define __DAC1_FORCE_RESET __HAL_RCC_DAC1_FORCE_RESET                     // 强制复位DAC1
#define __DAC1_RELEASE_RESET __HAL_RCC_DAC1_RELEASE_RESET                 // 释放DAC1复位

/* DBGMCU (调试接口) 相关时钟控制宏定义 */
#define __DBGMCU_CLK_ENABLE     __HAL_RCC_DBGMCU_CLK_ENABLE               // 使能DBGMCU时钟
#define __DBGMCU_CLK_DISABLE     __HAL_RCC_DBGMCU_CLK_DISABLE             // 失能DBGMCU时钟
#define __DBGMCU_FORCE_RESET    __HAL_RCC_DBGMCU_FORCE_RESET              // 强制复位DBGMCU
#define __DBGMCU_RELEASE_RESET  __HAL_RCC_DBGMCU_RELEASE_RESET            // 释放DBGMCU复位

/* DFSDM (数字滤波器) 相关时钟控制宏定义 */
#define __DFSDM_CLK_DISABLE __HAL_RCC_DFSDM_CLK_DISABLE                   // 失能DFSDM时钟
#define __DFSDM_CLK_ENABLE __HAL_RCC_DFSDM_CLK_ENABLE                     // 使能DFSDM时钟
#define __DFSDM_CLK_SLEEP_DISABLE __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE       // 睡眠模式下失能DFSDM时钟
#define __DFSDM_CLK_SLEEP_ENABLE __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE         // 睡眠模式下使能DFSDM时钟
#define __DFSDM_FORCE_RESET __HAL_RCC_DFSDM_FORCE_RESET                   // 强制复位DFSDM
#define __DFSDM_RELEASE_RESET __HAL_RCC_DFSDM_RELEASE_RESET               // 释放DFSDM复位

/* DMA1 (直接存储器访问控制器1) 相关时钟控制宏定义 */
#define __DMA1_CLK_DISABLE __HAL_RCC_DMA1_CLK_DISABLE                     // 失能DMA1时钟
#define __DMA1_CLK_ENABLE __HAL_RCC_DMA1_CLK_ENABLE                       // 使能DMA1时钟
#define __DMA1_CLK_SLEEP_DISABLE __HAL_RCC_DMA1_CLK_SLEEP_DISABLE         // 睡眠模式下失能DMA1时钟
#define __DMA1_CLK_SLEEP_ENABLE __HAL_RCC_DMA1_CLK_SLEEP_ENABLE           // 睡眠模式下使能DMA1时钟
#define __DMA1_FORCE_RESET __HAL_RCC_DMA1_FORCE_RESET                     // 强制复位DMA1
#define __DMA1_RELEASE_RESET __HAL_RCC_DMA1_RELEASE_RESET                 // 释放DMA1复位

/* DMA2 (直接存储器访问控制器2) 相关时钟控制宏定义 */
#define __DMA2_CLK_DISABLE __HAL_RCC_DMA2_CLK_DISABLE                     // 失能DMA2时钟
#define __DMA2_CLK_ENABLE __HAL_RCC_DMA2_CLK_ENABLE                       // 使能DMA2时钟
#define __DMA2_CLK_SLEEP_DISABLE __HAL_RCC_DMA2_CLK_SLEEP_DISABLE         // 睡眠模式下失能DMA2时钟
#define __DMA2_CLK_SLEEP_ENABLE __HAL_RCC_DMA2_CLK_SLEEP_ENABLE           // 睡眠模式下使能DMA2时钟
#define __DMA2_FORCE_RESET __HAL_RCC_DMA2_FORCE_RESET                     // 强制复位DMA2
#define __DMA2_RELEASE_RESET __HAL_RCC_DMA2_RELEASE_RESET                 // 释放DMA2复位

/* ETHMAC (以太网MAC控制器) 相关时钟控制宏定义 */
#define __ETHMAC_CLK_DISABLE __HAL_RCC_ETHMAC_CLK_DISABLE                 // 失能以太网MAC时钟
#define __ETHMAC_CLK_ENABLE __HAL_RCC_ETHMAC_CLK_ENABLE                   // 使能以太网MAC时钟
#define __ETHMAC_FORCE_RESET __HAL_RCC_ETHMAC_FORCE_RESET                 // 强制复位以太网MAC
#define __ETHMAC_RELEASE_RESET __HAL_RCC_ETHMAC_RELEASE_RESET             // 释放以太网MAC复位
#define __ETHMACRX_CLK_DISABLE __HAL_RCC_ETHMACRX_CLK_DISABLE             // 失能以太网MAC接收时钟
#define __ETHMACRX_CLK_ENABLE __HAL_RCC_ETHMACRX_CLK_ENABLE               // 使能以太网MAC接收时钟
#define __ETHMACTX_CLK_DISABLE __HAL_RCC_ETHMACTX_CLK_DISABLE             // 失能以太网MAC发送时钟
#define __ETHMACTX_CLK_ENABLE __HAL_RCC_ETHMACTX_CLK_ENABLE               // 使能以太网MAC发送时钟

/* FIREWALL (防火墙) 相关时钟控制宏定义 */
#define __FIREWALL_CLK_DISABLE __HAL_RCC_FIREWALL_CLK_DISABLE             // 失能防火墙时钟
#define __FIREWALL_CLK_ENABLE __HAL_RCC_FIREWALL_CLK_ENABLE               // 使能防火墙时钟

/* FLASH (闪存) 相关时钟控制宏定义 */
#define __FLASH_CLK_DISABLE __HAL_RCC_FLASH_CLK_DISABLE                   // 失能Flash接口时钟
#define __FLASH_CLK_ENABLE __HAL_RCC_FLASH_CLK_ENABLE                     // 使能Flash接口时钟
#define __FLASH_CLK_SLEEP_DISABLE __HAL_RCC_FLASH_CLK_SLEEP_DISABLE       // 睡眠模式下失能Flash时钟
#define __FLASH_CLK_SLEEP_ENABLE __HAL_RCC_FLASH_CLK_SLEEP_ENABLE         // 睡眠模式下使能Flash时钟
#define __FLASH_FORCE_RESET __HAL_RCC_FLASH_FORCE_RESET                   // 强制复位Flash
#define __FLASH_RELEASE_RESET __HAL_RCC_FLASH_RELEASE_RESET               // 释放Flash复位

/* FLITF (Flash存储器接口) 相关时钟控制宏定义 */
#define __FLITF_CLK_DISABLE       __HAL_RCC_FLITF_CLK_DISABLE             // 失能FLITF时钟
#define __FLITF_CLK_ENABLE        __HAL_RCC_FLITF_CLK_ENABLE              // 使能FLITF时钟
#define __FLITF_FORCE_RESET       __HAL_RCC_FLITF_FORCE_RESET             // 强制复位FLITF
#define __FLITF_RELEASE_RESET     __HAL_RCC_FLITF_RELEASE_RESET           // 释放FLITF复位
#define __FLITF_CLK_SLEEP_ENABLE  __HAL_RCC_FLITF_CLK_SLEEP_ENABLE        // 睡眠模式下使能FLITF时钟
#define __FLITF_CLK_SLEEP_DISABLE __HAL_RCC_FLITF_CLK_SLEEP_DISABLE       // 睡眠模式下失能FLITF时钟

/* FMC (灵活存储控制器) 相关时钟控制宏定义 */
#define __FMC_CLK_DISABLE __HAL_RCC_FMC_CLK_DISABLE                       // 失能FMC时钟
#define __FMC_CLK_ENABLE __HAL_RCC_FMC_CLK_ENABLE                         // 使能FMC时钟
#define __FMC_CLK_SLEEP_DISABLE __HAL_RCC_FMC_CLK_SLEEP_DISABLE           // 睡眠模式下失能FMC时钟
#define __FMC_CLK_SLEEP_ENABLE __HAL_RCC_FMC_CLK_SLEEP_ENABLE             // 睡眠模式下使能FMC时钟
#define __FMC_FORCE_RESET __HAL_RCC_FMC_FORCE_RESET                       // 强制复位FMC
#define __FMC_RELEASE_RESET __HAL_RCC_FMC_RELEASE_RESET                   // 释放FMC复位

/* FSMC (静态存储控制器) 相关时钟控制宏定义 */
#define __FSMC_CLK_DISABLE __HAL_RCC_FSMC_CLK_DISABLE                     // 失能FSMC时钟
#define __FSMC_CLK_ENABLE __HAL_RCC_FSMC_CLK_ENABLE                       // 使能FSMC时钟

/* GPIOA (通用输入输出端口A) 相关时钟控制宏定义 */
#define __GPIOA_CLK_DISABLE __HAL_RCC_GPIOA_CLK_DISABLE                   // 失能GPIOA时钟
#define __GPIOA_CLK_ENABLE __HAL_RCC_GPIOA_CLK_ENABLE                     // 使能GPIOA时钟
#define __GPIOA_CLK_SLEEP_DISABLE __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOA时钟
#define __GPIOA_CLK_SLEEP_ENABLE __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOA时钟
#define __GPIOA_FORCE_RESET __HAL_RCC_GPIOA_FORCE_RESET                   // 强制复位GPIOA
#define __GPIOA_RELEASE_RESET __HAL_RCC_GPIOA_RELEASE_RESET               // 释放GPIOA复位

/* GPIOB (通用输入输出端口B) 相关时钟控制宏定义 */
#define __GPIOB_CLK_DISABLE __HAL_RCC_GPIOB_CLK_DISABLE                   // 失能GPIOB时钟
#define __GPIOB_CLK_ENABLE __HAL_RCC_GPIOB_CLK_ENABLE                     // 使能GPIOB时钟
#define __GPIOB_CLK_SLEEP_DISABLE __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOB时钟
#define __GPIOB_CLK_SLEEP_ENABLE __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOB时钟
#define __GPIOB_FORCE_RESET __HAL_RCC_GPIOB_FORCE_RESET                   // 强制复位GPIOB
#define __GPIOB_RELEASE_RESET __HAL_RCC_GPIOB_RELEASE_RESET               // 释放GPIOB复位

/* GPIOC (通用输入输出端口C) 相关时钟控制宏定义 */
#define __GPIOC_CLK_DISABLE __HAL_RCC_GPIOC_CLK_DISABLE                   // 失能GPIOC时钟
#define __GPIOC_CLK_ENABLE __HAL_RCC_GPIOC_CLK_ENABLE                     // 使能GPIOC时钟
#define __GPIOC_CLK_SLEEP_DISABLE __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOC时钟
#define __GPIOC_CLK_SLEEP_ENABLE __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOC时钟
#define __GPIOC_FORCE_RESET __HAL_RCC_GPIOC_FORCE_RESET                   // 强制复位GPIOC
#define __GPIOC_RELEASE_RESET __HAL_RCC_GPIOC_RELEASE_RESET               // 释放GPIOC复位

/* GPIOD (通用输入输出端口D) 相关时钟控制宏定义 */
#define __GPIOD_CLK_DISABLE __HAL_RCC_GPIOD_CLK_DISABLE                   // 失能GPIOD时钟
#define __GPIOD_CLK_ENABLE __HAL_RCC_GPIOD_CLK_ENABLE                     // 使能GPIOD时钟
#define __GPIOD_CLK_SLEEP_DISABLE __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOD时钟
#define __GPIOD_CLK_SLEEP_ENABLE __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOD时钟
#define __GPIOD_FORCE_RESET __HAL_RCC_GPIOD_FORCE_RESET                   // 强制复位GPIOD
#define __GPIOD_RELEASE_RESET __HAL_RCC_GPIOD_RELEASE_RESET               // 释放GPIOD复位

/* GPIOE (通用输入输出端口E) 相关时钟控制宏定义 */
#define __GPIOE_CLK_DISABLE __HAL_RCC_GPIOE_CLK_DISABLE                   // 失能GPIOE时钟
#define __GPIOE_CLK_ENABLE __HAL_RCC_GPIOE_CLK_ENABLE                     // 使能GPIOE时钟
#define __GPIOE_CLK_SLEEP_DISABLE __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOE时钟
#define __GPIOE_CLK_SLEEP_ENABLE __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOE时钟
#define __GPIOE_FORCE_RESET __HAL_RCC_GPIOE_FORCE_RESET                   // 强制复位GPIOE
#define __GPIOE_RELEASE_RESET __HAL_RCC_GPIOE_RELEASE_RESET               // 释放GPIOE复位

/* GPIOF (通用输入输出端口F) 相关时钟控制宏定义 */
#define __GPIOF_CLK_DISABLE __HAL_RCC_GPIOF_CLK_DISABLE                   // 失能GPIOF时钟
#define __GPIOF_CLK_ENABLE __HAL_RCC_GPIOF_CLK_ENABLE                     // 使能GPIOF时钟
#define __GPIOF_CLK_SLEEP_DISABLE __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOF时钟
#define __GPIOF_CLK_SLEEP_ENABLE __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOF时钟
#define __GPIOF_FORCE_RESET __HAL_RCC_GPIOF_FORCE_RESET                   // 强制复位GPIOF
#define __GPIOF_RELEASE_RESET __HAL_RCC_GPIOF_RELEASE_RESET               // 释放GPIOF复位

/* GPIOG (通用输入输出端口G) 相关时钟控制宏定义 */
#define __GPIOG_CLK_DISABLE __HAL_RCC_GPIOG_CLK_DISABLE                   // 失能GPIOG时钟
#define __GPIOG_CLK_ENABLE __HAL_RCC_GPIOG_CLK_ENABLE                     // 使能GPIOG时钟
#define __GPIOG_CLK_SLEEP_DISABLE __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOG时钟
#define __GPIOG_CLK_SLEEP_ENABLE __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOG时钟
#define __GPIOG_FORCE_RESET __HAL_RCC_GPIOG_FORCE_RESET                   // 强制复位GPIOG
#define __GPIOG_RELEASE_RESET __HAL_RCC_GPIOG_RELEASE_RESET               // 释放GPIOG复位

/* GPIOH (通用输入输出端口H) 相关时钟控制宏定义 */
#define __GPIOH_CLK_DISABLE __HAL_RCC_GPIOH_CLK_DISABLE                   // 失能GPIOH时钟
#define __GPIOH_CLK_ENABLE __HAL_RCC_GPIOH_CLK_ENABLE                     // 使能GPIOH时钟
#define __GPIOH_CLK_SLEEP_DISABLE __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE       // 睡眠模式下失能GPIOH时钟
#define __GPIOH_CLK_SLEEP_ENABLE __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE         // 睡眠模式下使能GPIOH时钟
#define __GPIOH_FORCE_RESET __HAL_RCC_GPIOH_FORCE_RESET                   // 强制复位GPIOH
#define __GPIOH_RELEASE_RESET __HAL_RCC_GPIOH_RELEASE_RESET               // 释放GPIOH复位

/* I2C1 (I2C总线接口1) 相关时钟控制宏定义 */
#define __I2C1_CLK_DISABLE __HAL_RCC_I2C1_CLK_DISABLE                     // 失能I2C1时钟
#define __I2C1_CLK_ENABLE __HAL_RCC_I2C1_CLK_ENABLE                       // 使能I2C1时钟
#define __I2C1_CLK_SLEEP_DISABLE __HAL_RCC_I2C1_CLK_SLEEP_DISABLE         // 睡眠模式下失能I2C1时钟
#define __I2C1_CLK_SLEEP_ENABLE __HAL_RCC_I2C1_CLK_SLEEP_ENABLE           // 睡眠模式下使能I2C1时钟
#define __I2C1_FORCE_RESET __HAL_RCC_I2C1_FORCE_RESET                     // 强制复位I2C1
#define __I2C1_RELEASE_RESET __HAL_RCC_I2C1_RELEASE_RESET                 // 释放I2C1复位

/* I2C2 (I2C总线接口2) 相关时钟控制宏定义 */
#define __I2C2_CLK_DISABLE __HAL_RCC_I2C2_CLK_DISABLE                     // 失能I2C2时钟
#define __I2C2_CLK_ENABLE __HAL_RCC_I2C2_CLK_ENABLE                       // 使能I2C2时钟
#define __I2C2_CLK_SLEEP_DISABLE __HAL_RCC_I2C2_CLK_SLEEP_DISABLE         // 睡眠模式下失能I2C2时钟
#define __I2C2_CLK_SLEEP_ENABLE __HAL_RCC_I2C2_CLK_SLEEP_ENABLE           // 睡眠模式下使能I2C2时钟
#define __I2C2_FORCE_RESET __HAL_RCC_I2C2_FORCE_RESET                     // 强制复位I2C2
#define __I2C2_RELEASE_RESET __HAL_RCC_I2C2_RELEASE_RESET                 // 释放I2C2复位

/* I2C3 (I2C总线接口3) 相关时钟控制宏定义 */
#define __I2C3_CLK_DISABLE __HAL_RCC_I2C3_CLK_DISABLE                     // 失能I2C3时钟
#define __I2C3_CLK_ENABLE __HAL_RCC_I2C3_CLK_ENABLE                       // 使能I2C3时钟
#define __I2C3_CLK_SLEEP_DISABLE __HAL_RCC_I2C3_CLK_SLEEP_DISABLE         // 睡眠模式下失能I2C3时钟
#define __I2C3_CLK_SLEEP_ENABLE __HAL_RCC_I2C3_CLK_SLEEP_ENABLE           // 睡眠模式下使能I2C3时钟
#define __I2C3_FORCE_RESET __HAL_RCC_I2C3_FORCE_RESET                     // 强制复位I2C3
#define __I2C3_RELEASE_RESET __HAL_RCC_I2C3_RELEASE_RESET                 // 释放I2C3复位

/* LCD (液晶显示控制器) 相关时钟控制宏定义 */
#define __LCD_CLK_DISABLE __HAL_RCC_LCD_CLK_DISABLE                       // 失能LCD时钟
#define __LCD_CLK_ENABLE __HAL_RCC_LCD_CLK_ENABLE                         // 使能LCD时钟
#define __LCD_CLK_SLEEP_DISABLE __HAL_RCC_LCD_CLK_SLEEP_DISABLE           // 睡眠模式下失能LCD时钟
#define __LCD_CLK_SLEEP_ENABLE __HAL_RCC_LCD_CLK_SLEEP_ENABLE             // 睡眠模式下使能LCD时钟
#define __LCD_FORCE_RESET __HAL_RCC_LCD_FORCE_RESET                       // 强制复位LCD
#define __LCD_RELEASE_RESET __HAL_RCC_LCD_RELEASE_RESET                   // 释放LCD复位

/* LPTIM1 (低功耗定时器1) 相关时钟控制宏定义 */
#define __LPTIM1_CLK_DISABLE __HAL_RCC_LPTIM1_CLK_DISABLE                 // 失能LPTIM1时钟
#define __LPTIM1_CLK_ENABLE __HAL_RCC_LPTIM1_CLK_ENABLE                   // 使能LPTIM1时钟
#define __LPTIM1_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE     // 睡眠模式下失能LPTIM1时钟
#define __LPTIM1_CLK_SLEEP_ENABLE __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE       // 睡眠模式下使能LPTIM1时钟
#define __LPTIM1_FORCE_RESET __HAL_RCC_LPTIM1_FORCE_RESET                 // 强制复位LPTIM1
#define __LPTIM1_RELEASE_RESET __HAL_RCC_LPTIM1_RELEASE_RESET             // 释放LPTIM1复位

/* LPTIM2 (低功耗定时器2) 相关时钟控制宏定义 */
#define __LPTIM2_CLK_DISABLE __HAL_RCC_LPTIM2_CLK_DISABLE                 // 失能LPTIM2时钟
#define __LPTIM2_CLK_ENABLE __HAL_RCC_LPTIM2_CLK_ENABLE                   // 使能LPTIM2时钟
#define __LPTIM2_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE     // 睡眠模式下失能LPTIM2时钟
#define __LPTIM2_CLK_SLEEP_ENABLE __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE       // 睡眠模式下使能LPTIM2时钟
#define __LPTIM2_FORCE_RESET __HAL_RCC_LPTIM2_FORCE_RESET                 // 强制复位LPTIM2
#define __LPTIM2_RELEASE_RESET __HAL_RCC_LPTIM2_RELEASE_RESET             // 释放LPTIM2复位

/* LPUART1 (低功耗通用异步收发传输器1) 相关时钟控制宏定义 */
#define __LPUART1_CLK_DISABLE __HAL_RCC_LPUART1_CLK_DISABLE               // 失能LPUART1时钟
#define __LPUART1_CLK_ENABLE __HAL_RCC_LPUART1_CLK_ENABLE                 // 使能LPUART1时钟
#define __LPUART1_CLK_SLEEP_DISABLE __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE   // 睡眠模式下失能LPUART1时钟
#define __LPUART1_CLK_SLEEP_ENABLE __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE     // 睡眠模式下使能LPUART1时钟
#define __LPUART1_FORCE_RESET __HAL_RCC_LPUART1_FORCE_RESET               // 强制复位LPUART1
#define __LPUART1_RELEASE_RESET __HAL_RCC_LPUART1_RELEASE_RESET           // 释放LPUART1复位

/* OPAMP (运算放大器) 相关时钟控制宏定义 */
#define __OPAMP_CLK_DISABLE __HAL_RCC_OPAMP_CLK_DISABLE                   // 失能OPAMP时钟
#define __OPAMP_CLK_ENABLE __HAL_RCC_OPAMP_CLK_ENABLE                     // 使能OPAMP时钟
#define __OPAMP_CLK_SLEEP_DISABLE __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE       // 睡眠模式下失能OPAMP时钟
#define __OPAMP_CLK_SLEEP_ENABLE __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE         // 睡眠模式下使能OPAMP时钟
#define __OPAMP_FORCE_RESET __HAL_RCC_OPAMP_FORCE_RESET                   // 强制复位OPAMP
#define __OPAMP_RELEASE_RESET __HAL_RCC_OPAMP_RELEASE_RESET               // 释放OPAMP复位

/* OTGFS (USB On-The-Go 全速) 相关时钟控制宏定义 */
#define __OTGFS_CLK_DISABLE __HAL_RCC_OTGFS_CLK_DISABLE                   // 失能OTGFS时钟
#define __OTGFS_CLK_ENABLE __HAL_RCC_OTGFS_CLK_ENABLE                     // 使能OTGFS时钟
#define __OTGFS_CLK_SLEEP_DISABLE __HAL_RCC_OTGFS_CLK_SLEEP_DISABLE       // 睡眠模式下失能OTGFS时钟
#define __OTGFS_CLK_SLEEP_ENABLE __HAL_RCC_OTGFS_CLK_SLEEP_ENABLE         // 睡眠模式下使能OTGFS时钟
#define __OTGFS_FORCE_RESET __HAL_RCC_OTGFS_FORCE_RESET                   // 强制复位OTGFS
#define __OTGFS_RELEASE_RESET __HAL_RCC_OTGFS_RELEASE_RESET               // 释放OTGFS复位

/* PWR (电源接口) 相关时钟控制宏定义 */
#define __PWR_CLK_DISABLE __HAL_RCC_PWR_CLK_DISABLE                       // 失能PWR时钟
#define __PWR_CLK_ENABLE __HAL_RCC_PWR_CLK_ENABLE                         // 使能PWR时钟
#define __PWR_CLK_SLEEP_DISABLE __HAL_RCC_PWR_CLK_SLEEP_DISABLE           // 睡眠模式下失能PWR时钟
#define __PWR_CLK_SLEEP_ENABLE __HAL_RCC_PWR_CLK_SLEEP_ENABLE             // 睡眠模式下使能PWR时钟
#define __PWR_FORCE_RESET __HAL_RCC_PWR_FORCE_RESET                       // 强制复位PWR
#define __PWR_RELEASE_RESET __HAL_RCC_PWR_RELEASE_RESET                   // 释放PWR复位

/* QSPI (四线SPI接口) 相关时钟控制宏定义 */
#define __QSPI_CLK_DISABLE __HAL_RCC_QSPI_CLK_DISABLE                     // 失能QSPI时钟
#define __QSPI_CLK_ENABLE __HAL_RCC_QSPI_CLK_ENABLE                       // 使能QSPI时钟
#define __QSPI_CLK_SLEEP_DISABLE __HAL_RCC_QSPI_CLK_SLEEP_DISABLE         // 睡眠模式下失能QSPI时钟
#define __QSPI_CLK_SLEEP_ENABLE __HAL_RCC_QSPI_CLK_SLEEP_ENABLE           // 睡眠模式下使能QSPI时钟
#define __QSPI_FORCE_RESET __HAL_RCC_QSPI_FORCE_RESET                     // 强制复位QSPI
#define __QSPI_RELEASE_RESET __HAL_RCC_QSPI_RELEASE_RESET                 // 释放QSPI复位

#if defined(STM32WB)
/* STM32WB系列特有定义：将QSPI宏映射到QUADSPI底层实现 */
#define __HAL_RCC_QSPI_CLK_DISABLE            __HAL_RCC_QUADSPI_CLK_DISABLE          // 失能QSPI时钟
#define __HAL_RCC_QSPI_CLK_ENABLE             __HAL_RCC_QUADSPI_CLK_ENABLE           // 使能QSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_DISABLE      __HAL_RCC_QUADSPI_CLK_SLEEP_DISABLE    // 睡眠模式下失能QSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_ENABLE       __HAL_RCC_QUADSPI_CLK_SLEEP_ENABLE     // 睡眠模式下使能QSPI时钟
#define __HAL_RCC_QSPI_FORCE_RESET            __HAL_RCC_QUADSPI_FORCE_RESET          // 强制复位QSPI
#define __HAL_RCC_QSPI_RELEASE_RESET          __HAL_RCC_QUADSPI_RELEASE_RESET        // 释放QSPI复位
#define __HAL_RCC_QSPI_IS_CLK_ENABLED         __HAL_RCC_QUADSPI_IS_CLK_ENABLED       // 检查QSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_DISABLED        __HAL_RCC_QUADSPI_IS_CLK_DISABLED      // 检查QSPI时钟是否失能
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_ENABLED   __HAL_RCC_QUADSPI_IS_CLK_SLEEP_ENABLED // 检查睡眠模式下QSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_DISABLED  __HAL_RCC_QUADSPI_IS_CLK_SLEEP_DISABLED// 检查睡眠模式下QSPI时钟是否失能
#define QSPI_IRQHandler QUADSPI_IRQHandler                                    // 中断服务函数别名映射
#endif /* __HAL_RCC_QUADSPI_CLK_ENABLE */
/*
  以下是外设时钟控制相关的宏定义别名。
  为了保持代码兼容性或简化书写，旧版的宏名称被映射到新版HAL库宏名称。
  主要涉及：RNG(随机数生成器), SAI(音频接口), SDIO/SDMMC(存储卡接口),
  SPI(串行外设接口), SRAM(静态内存), SWPMI(单线协议接口),
  SYSCFG(系统配置), TIM(定时器), TSC(触摸传感),
  UART/USART(串口), USB(通用串行总线), WWDG(窗口看门狗)等。
  操作类型包括：时钟使能(CLK_ENABLE)、时钟关闭(CLK_DISABLE)、
 睡眠模式时钟使能(CLK_SLEEP_ENABLE)、睡眠模式时钟关闭(CLK_SLEEP_DISABLE)、
	强制复位(FORCE_RESET)、释放复位(RELEASE_RESET)。
*/

/* RNG 随机数生成器 时钟控制 */
#define __RNG_CLK_DISABLE __HAL_RCC_RNG_CLK_DISABLE // 关闭 RNG 时钟
#define __RNG_CLK_ENABLE __HAL_RCC_RNG_CLK_ENABLE // 使能 RNG 时钟
#define __RNG_CLK_SLEEP_DISABLE __HAL_RCC_RNG_CLK_SLEEP_DISABLE // 睡眠模式下关闭 RNG 时钟
#define __RNG_CLK_SLEEP_ENABLE __HAL_RCC_RNG_CLK_SLEEP_ENABLE // 睡眠模式下使能 RNG 时钟
#define __RNG_FORCE_RESET __HAL_RCC_RNG_FORCE_RESET // 强制复位 RNG
#define __RNG_RELEASE_RESET __HAL_RCC_RNG_RELEASE_RESET // 释放 RNG 复位

/* SAI1 串行音频接口1 时钟控制 */
#define __SAI1_CLK_DISABLE __HAL_RCC_SAI1_CLK_DISABLE // 关闭 SAI1 时钟
#define __SAI1_CLK_ENABLE __HAL_RCC_SAI1_CLK_ENABLE // 使能 SAI1 时钟
#define __SAI1_CLK_SLEEP_DISABLE __HAL_RCC_SAI1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SAI1 时钟
#define __SAI1_CLK_SLEEP_ENABLE __HAL_RCC_SAI1_CLK_SLEEP_ENABLE // 睡眠模式下使能 SAI1 时钟
#define __SAI1_FORCE_RESET __HAL_RCC_SAI1_FORCE_RESET // 强制复位 SAI1
#define __SAI1_RELEASE_RESET __HAL_RCC_SAI1_RELEASE_RESET // 释放 SAI1 复位

/* SAI2 串行音频接口2 时钟控制 */
#define __SAI2_CLK_DISABLE __HAL_RCC_SAI2_CLK_DISABLE // 关闭 SAI2 时钟
#define __SAI2_CLK_ENABLE __HAL_RCC_SAI2_CLK_ENABLE // 使能 SAI2 时钟
#define __SAI2_CLK_SLEEP_DISABLE __HAL_RCC_SAI2_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SAI2 时钟
#define __SAI2_CLK_SLEEP_ENABLE __HAL_RCC_SAI2_CLK_SLEEP_ENABLE // 睡眠模式下使能 SAI2 时钟
#define __SAI2_FORCE_RESET __HAL_RCC_SAI2_FORCE_RESET // 强制复位 SAI2
#define __SAI2_RELEASE_RESET __HAL_RCC_SAI2_RELEASE_RESET // 释放 SAI2 复位

/* SDIO 安全数字输入输出接口 时钟控制 */
#define __SDIO_CLK_DISABLE __HAL_RCC_SDIO_CLK_DISABLE // 关闭 SDIO 时钟
#define __SDIO_CLK_ENABLE __HAL_RCC_SDIO_CLK_ENABLE // 使能 SDIO 时钟

/* SDMMC 安全数字卡控制器 时钟控制 */
#define __SDMMC_CLK_DISABLE __HAL_RCC_SDMMC_CLK_DISABLE // 关闭 SDMMC 时钟
#define __SDMMC_CLK_ENABLE __HAL_RCC_SDMMC_CLK_ENABLE // 使能 SDMMC 时钟
#define __SDMMC_CLK_SLEEP_DISABLE __HAL_RCC_SDMMC_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SDMMC 时钟
#define __SDMMC_CLK_SLEEP_ENABLE __HAL_RCC_SDMMC_CLK_SLEEP_ENABLE // 睡眠模式下使能 SDMMC 时钟
#define __SDMMC_FORCE_RESET __HAL_RCC_SDMMC_FORCE_RESET // 强制复位 SDMMC
#define __SDMMC_RELEASE_RESET __HAL_RCC_SDMMC_RELEASE_RESET // 释放 SDMMC 复位

/* SPI1 串行外设接口1 时钟控制 */
#define __SPI1_CLK_DISABLE __HAL_RCC_SPI1_CLK_DISABLE // 关闭 SPI1 时钟
#define __SPI1_CLK_ENABLE __HAL_RCC_SPI1_CLK_ENABLE // 使能 SPI1 时钟
#define __SPI1_CLK_SLEEP_DISABLE __HAL_RCC_SPI1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SPI1 时钟
#define __SPI1_CLK_SLEEP_ENABLE __HAL_RCC_SPI1_CLK_SLEEP_ENABLE // 睡眠模式下使能 SPI1 时钟
#define __SPI1_FORCE_RESET __HAL_RCC_SPI1_FORCE_RESET // 强制复位 SPI1
#define __SPI1_RELEASE_RESET __HAL_RCC_SPI1_RELEASE_RESET // 释放 SPI1 复位

/* SPI2 串行外设接口2 时钟控制 */
#define __SPI2_CLK_DISABLE __HAL_RCC_SPI2_CLK_DISABLE // 关闭 SPI2 时钟
#define __SPI2_CLK_ENABLE __HAL_RCC_SPI2_CLK_ENABLE // 使能 SPI2 时钟
#define __SPI2_CLK_SLEEP_DISABLE __HAL_RCC_SPI2_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SPI2 时钟
#define __SPI2_CLK_SLEEP_ENABLE __HAL_RCC_SPI2_CLK_SLEEP_ENABLE // 睡眠模式下使能 SPI2 时钟
#define __SPI2_FORCE_RESET __HAL_RCC_SPI2_FORCE_RESET // 强制复位 SPI2
#define __SPI2_RELEASE_RESET __HAL_RCC_SPI2_RELEASE_RESET // 释放 SPI2 复位

/* SPI3 串行外设接口3 时钟控制 */
#define __SPI3_CLK_DISABLE __HAL_RCC_SPI3_CLK_DISABLE // 关闭 SPI3 时钟
#define __SPI3_CLK_ENABLE __HAL_RCC_SPI3_CLK_ENABLE // 使能 SPI3 时钟
#define __SPI3_CLK_SLEEP_DISABLE __HAL_RCC_SPI3_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SPI3 时钟
#define __SPI3_CLK_SLEEP_ENABLE __HAL_RCC_SPI3_CLK_SLEEP_ENABLE // 睡眠模式下使能 SPI3 时钟
#define __SPI3_FORCE_RESET __HAL_RCC_SPI3_FORCE_RESET // 强制复位 SPI3
#define __SPI3_RELEASE_RESET __HAL_RCC_SPI3_RELEASE_RESET // 释放 SPI3 复位

/* SRAM 静态随机存取存储器 时钟控制 */
#define __SRAM_CLK_DISABLE __HAL_RCC_SRAM_CLK_DISABLE // 关闭 SRAM 时钟
#define __SRAM_CLK_ENABLE __HAL_RCC_SRAM_CLK_ENABLE // 使能 SRAM 时钟
#define __SRAM1_CLK_SLEEP_DISABLE __HAL_RCC_SRAM1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SRAM1 时钟
#define __SRAM1_CLK_SLEEP_ENABLE __HAL_RCC_SRAM1_CLK_SLEEP_ENABLE // 睡眠模式下使能 SRAM1 时钟
#define __SRAM2_CLK_SLEEP_DISABLE __HAL_RCC_SRAM2_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SRAM2 时钟
#define __SRAM2_CLK_SLEEP_ENABLE __HAL_RCC_SRAM2_CLK_SLEEP_ENABLE // 睡眠模式下使能 SRAM2 时钟

/* SWPMI1 单线协议接口1 时钟控制 */
#define __SWPMI1_CLK_DISABLE __HAL_RCC_SWPMI1_CLK_DISABLE // 关闭 SWPMI1 时钟
#define __SWPMI1_CLK_ENABLE __HAL_RCC_SWPMI1_CLK_ENABLE // 使能 SWPMI1 时钟
#define __SWPMI1_CLK_SLEEP_DISABLE __HAL_RCC_SWPMI1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SWPMI1 时钟
#define __SWPMI1_CLK_SLEEP_ENABLE __HAL_RCC_SWPMI1_CLK_SLEEP_ENABLE // 睡眠模式下使能 SWPMI1 时钟
#define __SWPMI1_FORCE_RESET __HAL_RCC_SWPMI1_FORCE_RESET // 强制复位 SWPMI1
#define __SWPMI1_RELEASE_RESET __HAL_RCC_SWPMI1_RELEASE_RESET // 释放 SWPMI1 复位

/* SYSCFG 系统配置控制器 时钟控制 */
#define __SYSCFG_CLK_DISABLE __HAL_RCC_SYSCFG_CLK_DISABLE // 关闭 SYSCFG 时钟
#define __SYSCFG_CLK_ENABLE __HAL_RCC_SYSCFG_CLK_ENABLE // 使能 SYSCFG 时钟
#define __SYSCFG_CLK_SLEEP_DISABLE __HAL_RCC_SYSCFG_CLK_SLEEP_DISABLE // 睡眠模式下关闭 SYSCFG 时钟
#define __SYSCFG_CLK_SLEEP_ENABLE __HAL_RCC_SYSCFG_CLK_SLEEP_ENABLE // 睡眠模式下使能 SYSCFG 时钟
#define __SYSCFG_FORCE_RESET __HAL_RCC_SYSCFG_FORCE_RESET // 强制复位 SYSCFG
#define __SYSCFG_RELEASE_RESET __HAL_RCC_SYSCFG_RELEASE_RESET // 释放 SYSCFG 复位

/* TIM1 高级定时器1 时钟控制 */
#define __TIM1_CLK_DISABLE __HAL_RCC_TIM1_CLK_DISABLE // 关闭 TIM1 时钟
#define __TIM1_CLK_ENABLE __HAL_RCC_TIM1_CLK_ENABLE // 使能 TIM1 时钟
#define __TIM1_CLK_SLEEP_DISABLE __HAL_RCC_TIM1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM1 时钟
#define __TIM1_CLK_SLEEP_ENABLE __HAL_RCC_TIM1_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM1 时钟
#define __TIM1_FORCE_RESET __HAL_RCC_TIM1_FORCE_RESET // 强制复位 TIM1
#define __TIM1_RELEASE_RESET __HAL_RCC_TIM1_RELEASE_RESET // 释放 TIM1 复位

/* TIM10 通用定时器10 时钟控制 */
#define __TIM10_CLK_DISABLE __HAL_RCC_TIM10_CLK_DISABLE // 关闭 TIM10 时钟
#define __TIM10_CLK_ENABLE __HAL_RCC_TIM10_CLK_ENABLE // 使能 TIM10 时钟
#define __TIM10_FORCE_RESET __HAL_RCC_TIM10_FORCE_RESET // 强制复位 TIM10
#define __TIM10_RELEASE_RESET __HAL_RCC_TIM10_RELEASE_RESET // 释放 TIM10 复位

/* TIM11 通用定时器11 时钟控制 */
#define __TIM11_CLK_DISABLE __HAL_RCC_TIM11_CLK_DISABLE // 关闭 TIM11 时钟
#define __TIM11_CLK_ENABLE __HAL_RCC_TIM11_CLK_ENABLE // 使能 TIM11 时钟
#define __TIM11_FORCE_RESET __HAL_RCC_TIM11_FORCE_RESET // 强制复位 TIM11
#define __TIM11_RELEASE_RESET __HAL_RCC_TIM11_RELEASE_RESET // 释放 TIM11 复位

/* TIM12 通用定时器12 时钟控制 */
#define __TIM12_CLK_DISABLE __HAL_RCC_TIM12_CLK_DISABLE // 关闭 TIM12 时钟
#define __TIM12_CLK_ENABLE __HAL_RCC_TIM12_CLK_ENABLE // 使能 TIM12 时钟
#define __TIM12_FORCE_RESET __HAL_RCC_TIM12_FORCE_RESET // 强制复位 TIM12
#define __TIM12_RELEASE_RESET __HAL_RCC_TIM12_RELEASE_RESET // 释放 TIM12 复位

/* TIM13 通用定时器13 时钟控制 */
#define __TIM13_CLK_DISABLE __HAL_RCC_TIM13_CLK_DISABLE // 关闭 TIM13 时钟
#define __TIM13_CLK_ENABLE __HAL_RCC_TIM13_CLK_ENABLE // 使能 TIM13 时钟
#define __TIM13_FORCE_RESET __HAL_RCC_TIM13_FORCE_RESET // 强制复位 TIM13
#define __TIM13_RELEASE_RESET __HAL_RCC_TIM13_RELEASE_RESET // 释放 TIM13 复位

/* TIM14 通用定时器14 时钟控制 */
#define __TIM14_CLK_DISABLE __HAL_RCC_TIM14_CLK_DISABLE // 关闭 TIM14 时钟
#define __TIM14_CLK_ENABLE __HAL_RCC_TIM14_CLK_ENABLE // 使能 TIM14 时钟
#define __TIM14_FORCE_RESET __HAL_RCC_TIM14_FORCE_RESET // 强制复位 TIM14
#define __TIM14_RELEASE_RESET __HAL_RCC_TIM14_RELEASE_RESET // 释放 TIM14 复位

/* TIM15 通用定时器15 时钟控制 */
#define __TIM15_CLK_DISABLE __HAL_RCC_TIM15_CLK_DISABLE // 关闭 TIM15 时钟
#define __TIM15_CLK_ENABLE __HAL_RCC_TIM15_CLK_ENABLE // 使能 TIM15 时钟
#define __TIM15_CLK_SLEEP_DISABLE __HAL_RCC_TIM15_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM15 时钟
#define __TIM15_CLK_SLEEP_ENABLE __HAL_RCC_TIM15_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM15 时钟
#define __TIM15_FORCE_RESET __HAL_RCC_TIM15_FORCE_RESET // 强制复位 TIM15
#define __TIM15_RELEASE_RESET __HAL_RCC_TIM15_RELEASE_RESET // 释放 TIM15 复位

/* TIM16 通用定时器16 时钟控制 */
#define __TIM16_CLK_DISABLE __HAL_RCC_TIM16_CLK_DISABLE // 关闭 TIM16 时钟
#define __TIM16_CLK_ENABLE __HAL_RCC_TIM16_CLK_ENABLE // 使能 TIM16 时钟
#define __TIM16_CLK_SLEEP_DISABLE __HAL_RCC_TIM16_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM16 时钟
#define __TIM16_CLK_SLEEP_ENABLE __HAL_RCC_TIM16_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM16 时钟
#define __TIM16_FORCE_RESET __HAL_RCC_TIM16_FORCE_RESET // 强制复位 TIM16
#define __TIM16_RELEASE_RESET __HAL_RCC_TIM16_RELEASE_RESET // 释放 TIM16 复位

/* TIM17 通用定时器17 时钟控制 */
#define __TIM17_CLK_DISABLE __HAL_RCC_TIM17_CLK_DISABLE // 关闭 TIM17 时钟
#define __TIM17_CLK_ENABLE __HAL_RCC_TIM17_CLK_ENABLE // 使能 TIM17 时钟
#define __TIM17_CLK_SLEEP_DISABLE __HAL_RCC_TIM17_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM17 时钟
#define __TIM17_CLK_SLEEP_ENABLE __HAL_RCC_TIM17_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM17 时钟
#define __TIM17_FORCE_RESET __HAL_RCC_TIM17_FORCE_RESET // 强制复位 TIM17
#define __TIM17_RELEASE_RESET __HAL_RCC_TIM17_RELEASE_RESET // 释放 TIM17 复位

/* TIM2 通用定时器2 时钟控制 */
#define __TIM2_CLK_DISABLE __HAL_RCC_TIM2_CLK_DISABLE // 关闭 TIM2 时钟
#define __TIM2_CLK_ENABLE __HAL_RCC_TIM2_CLK_ENABLE // 使能 TIM2 时钟
#define __TIM2_CLK_SLEEP_DISABLE __HAL_RCC_TIM2_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM2 时钟
#define __TIM2_CLK_SLEEP_ENABLE __HAL_RCC_TIM2_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM2 时钟
#define __TIM2_FORCE_RESET __HAL_RCC_TIM2_FORCE_RESET // 强制复位 TIM2
#define __TIM2_RELEASE_RESET __HAL_RCC_TIM2_RELEASE_RESET // 释放 TIM2 复位

/* TIM3 通用定时器3 时钟控制 */
#define __TIM3_CLK_DISABLE __HAL_RCC_TIM3_CLK_DISABLE // 关闭 TIM3 时钟
#define __TIM3_CLK_ENABLE __HAL_RCC_TIM3_CLK_ENABLE // 使能 TIM3 时钟
#define __TIM3_CLK_SLEEP_DISABLE __HAL_RCC_TIM3_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM3 时钟
#define __TIM3_CLK_SLEEP_ENABLE __HAL_RCC_TIM3_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM3 时钟
#define __TIM3_FORCE_RESET __HAL_RCC_TIM3_FORCE_RESET // 强制复位 TIM3
#define __TIM3_RELEASE_RESET __HAL_RCC_TIM3_RELEASE_RESET // 释放 TIM3 复位

/* TIM4 通用定时器4 时钟控制 */
#define __TIM4_CLK_DISABLE __HAL_RCC_TIM4_CLK_DISABLE // 关闭 TIM4 时钟
#define __TIM4_CLK_ENABLE __HAL_RCC_TIM4_CLK_ENABLE // 使能 TIM4 时钟
#define __TIM4_CLK_SLEEP_DISABLE __HAL_RCC_TIM4_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM4 时钟
#define __TIM4_CLK_SLEEP_ENABLE __HAL_RCC_TIM4_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM4 时钟
#define __TIM4_FORCE_RESET __HAL_RCC_TIM4_FORCE_RESET // 强制复位 TIM4
#define __TIM4_RELEASE_RESET __HAL_RCC_TIM4_RELEASE_RESET // 释放 TIM4 复位

/* TIM5 通用定时器5 时钟控制 */
#define __TIM5_CLK_DISABLE __HAL_RCC_TIM5_CLK_DISABLE // 关闭 TIM5 时钟
#define __TIM5_CLK_ENABLE __HAL_RCC_TIM5_CLK_ENABLE // 使能 TIM5 时钟
#define __TIM5_CLK_SLEEP_DISABLE __HAL_RCC_TIM5_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM5 时钟
#define __TIM5_CLK_SLEEP_ENABLE __HAL_RCC_TIM5_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM5 时钟
#define __TIM5_FORCE_RESET __HAL_RCC_TIM5_FORCE_RESET // 强制复位 TIM5
#define __TIM5_RELEASE_RESET __HAL_RCC_TIM5_RELEASE_RESET // 释放 TIM5 复位

/* TIM6 基本定时器6 时钟控制 */
#define __TIM6_CLK_DISABLE __HAL_RCC_TIM6_CLK_DISABLE // 关闭 TIM6 时钟
#define __TIM6_CLK_ENABLE __HAL_RCC_TIM6_CLK_ENABLE // 使能 TIM6 时钟
#define __TIM6_CLK_SLEEP_DISABLE __HAL_RCC_TIM6_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM6 时钟
#define __TIM6_CLK_SLEEP_ENABLE __HAL_RCC_TIM6_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM6 时钟
#define __TIM6_FORCE_RESET __HAL_RCC_TIM6_FORCE_RESET // 强制复位 TIM6
#define __TIM6_RELEASE_RESET __HAL_RCC_TIM6_RELEASE_RESET // 释放 TIM6 复位

/* TIM7 基本定时器7 时钟控制 */
#define __TIM7_CLK_DISABLE __HAL_RCC_TIM7_CLK_DISABLE // 关闭 TIM7 时钟
#define __TIM7_CLK_ENABLE __HAL_RCC_TIM7_CLK_ENABLE // 使能 TIM7 时钟
#define __TIM7_CLK_SLEEP_DISABLE __HAL_RCC_TIM7_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM7 时钟
#define __TIM7_CLK_SLEEP_ENABLE __HAL_RCC_TIM7_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM7 时钟
#define __TIM7_FORCE_RESET __HAL_RCC_TIM7_FORCE_RESET // 强制复位 TIM7
#define __TIM7_RELEASE_RESET __HAL_RCC_TIM7_RELEASE_RESET // 释放 TIM7 复位

/* TIM8 高级定时器8 时钟控制 */
#define __TIM8_CLK_DISABLE __HAL_RCC_TIM8_CLK_DISABLE // 关闭 TIM8 时钟
#define __TIM8_CLK_ENABLE __HAL_RCC_TIM8_CLK_ENABLE // 使能 TIM8 时钟
#define __TIM8_CLK_SLEEP_DISABLE __HAL_RCC_TIM8_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM8 时钟
#define __TIM8_CLK_SLEEP_ENABLE __HAL_RCC_TIM8_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM8 时钟
#define __TIM8_FORCE_RESET __HAL_RCC_TIM8_FORCE_RESET // 强制复位 TIM8
#define __TIM8_RELEASE_RESET __HAL_RCC_TIM8_RELEASE_RESET // 释放 TIM8 复位

/* TIM9 通用定时器9 时钟控制 */
#define __TIM9_CLK_DISABLE __HAL_RCC_TIM9_CLK_DISABLE // 关闭 TIM9 时钟
#define __TIM9_CLK_ENABLE __HAL_RCC_TIM9_CLK_ENABLE // 使能 TIM9 时钟
#define __TIM9_FORCE_RESET __HAL_RCC_TIM9_FORCE_RESET // 强制复位 TIM9
#define __TIM9_RELEASE_RESET __HAL_RCC_TIM9_RELEASE_RESET // 释放 TIM9 复位

/* TSC 触摸传感控制器 时钟控制 */
#define __TSC_CLK_DISABLE __HAL_RCC_TSC_CLK_DISABLE // 关闭 TSC 时钟
#define __TSC_CLK_ENABLE __HAL_RCC_TSC_CLK_ENABLE // 使能 TSC 时钟
#define __TSC_CLK_SLEEP_DISABLE __HAL_RCC_TSC_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TSC 时钟
#define __TSC_CLK_SLEEP_ENABLE __HAL_RCC_TSC_CLK_SLEEP_ENABLE // 睡眠模式下使能 TSC 时钟
#define __TSC_FORCE_RESET __HAL_RCC_TSC_FORCE_RESET // 强制复位 TSC
#define __TSC_RELEASE_RESET __HAL_RCC_TSC_RELEASE_RESET // 释放 TSC 复位

/* UART4 通用异步收发器4 时钟控制 */
#define __UART4_CLK_DISABLE __HAL_RCC_UART4_CLK_DISABLE // 关闭 UART4 时钟
#define __UART4_CLK_ENABLE __HAL_RCC_UART4_CLK_ENABLE // 使能 UART4 时钟
#define __UART4_CLK_SLEEP_DISABLE __HAL_RCC_UART4_CLK_SLEEP_DISABLE // 睡眠模式下关闭 UART4 时钟
#define __UART4_CLK_SLEEP_ENABLE __HAL_RCC_UART4_CLK_SLEEP_ENABLE // 睡眠模式下使能 UART4 时钟
#define __UART4_FORCE_RESET __HAL_RCC_UART4_FORCE_RESET // 强制复位 UART4
#define __UART4_RELEASE_RESET __HAL_RCC_UART4_RELEASE_RESET // 释放 UART4 复位

/* UART5 通用异步收发器5 时钟控制 */
#define __UART5_CLK_DISABLE __HAL_RCC_UART5_CLK_DISABLE // 关闭 UART5 时钟
#define __UART5_CLK_ENABLE __HAL_RCC_UART5_CLK_ENABLE // 使能 UART5 时钟
#define __UART5_CLK_SLEEP_DISABLE __HAL_RCC_UART5_CLK_SLEEP_DISABLE // 睡眠模式下关闭 UART5 时钟
#define __UART5_CLK_SLEEP_ENABLE __HAL_RCC_UART5_CLK_SLEEP_ENABLE // 睡眠模式下使能 UART5 时钟
#define __UART5_FORCE_RESET __HAL_RCC_UART5_FORCE_RESET // 强制复位 UART5
#define __UART5_RELEASE_RESET __HAL_RCC_UART5_RELEASE_RESET // 释放 UART5 复位

/* USART1 通用同步/异步收发器1 时钟控制 */
#define __USART1_CLK_DISABLE __HAL_RCC_USART1_CLK_DISABLE // 关闭 USART1 时钟
#define __USART1_CLK_ENABLE __HAL_RCC_USART1_CLK_ENABLE // 使能 USART1 时钟
#define __USART1_CLK_SLEEP_DISABLE __HAL_RCC_USART1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 USART1 时钟
#define __USART1_CLK_SLEEP_ENABLE __HAL_RCC_USART1_CLK_SLEEP_ENABLE // 睡眠模式下使能 USART1 时钟
#define __USART1_FORCE_RESET __HAL_RCC_USART1_FORCE_RESET // 强制复位 USART1
#define __USART1_RELEASE_RESET __HAL_RCC_USART1_RELEASE_RESET // 释放 USART1 复位

/* USART2 通用同步/异步收发器2 时钟控制 */
#define __USART2_CLK_DISABLE __HAL_RCC_USART2_CLK_DISABLE // 关闭 USART2 时钟
#define __USART2_CLK_ENABLE __HAL_RCC_USART2_CLK_ENABLE // 使能 USART2 时钟
#define __USART2_CLK_SLEEP_DISABLE __HAL_RCC_USART2_CLK_SLEEP_DISABLE // 睡眠模式下关闭 USART2 时钟
#define __USART2_CLK_SLEEP_ENABLE __HAL_RCC_USART2_CLK_SLEEP_ENABLE // 睡眠模式下使能 USART2 时钟
#define __USART2_FORCE_RESET __HAL_RCC_USART2_FORCE_RESET // 强制复位 USART2
#define __USART2_RELEASE_RESET __HAL_RCC_USART2_RELEASE_RESET // 释放 USART2 复位

/* USART3 通用同步/异步收发器3 时钟控制 */
#define __USART3_CLK_DISABLE __HAL_RCC_USART3_CLK_DISABLE // 关闭 USART3 时钟
#define __USART3_CLK_ENABLE __HAL_RCC_USART3_CLK_ENABLE // 使能 USART3 时钟
#define __USART3_CLK_SLEEP_DISABLE __HAL_RCC_USART3_CLK_SLEEP_DISABLE // 睡眠模式下关闭 USART3 时钟
#define __USART3_CLK_SLEEP_ENABLE __HAL_RCC_USART3_CLK_SLEEP_ENABLE // 睡眠模式下使能 USART3 时钟
#define __USART3_FORCE_RESET __HAL_RCC_USART3_FORCE_RESET // 强制复位 USART3
#define __USART3_RELEASE_RESET __HAL_RCC_USART3_RELEASE_RESET // 释放 USART3 复位

/* USART4 通用同步/异步收发器4 时钟控制 (映射到 UART4) */
#define __USART4_CLK_DISABLE        __HAL_RCC_UART4_CLK_DISABLE // 关闭 USART4 时钟
#define __USART4_CLK_ENABLE         __HAL_RCC_UART4_CLK_ENABLE // 使能 USART4 时钟
#define __USART4_CLK_SLEEP_ENABLE   __HAL_RCC_UART4_CLK_SLEEP_ENABLE // 睡眠模式下使能 USART4 时钟
#define __USART4_CLK_SLEEP_DISABLE  __HAL_RCC_UART4_CLK_SLEEP_DISABLE // 睡眠模式下关闭 USART4 时钟
#define __USART4_FORCE_RESET        __HAL_RCC_UART4_FORCE_RESET // 强制复位 USART4
#define __USART4_RELEASE_RESET      __HAL_RCC_UART4_RELEASE_RESET // 释放 USART4 复位

/* USART5 通用同步/异步收发器5 时钟控制 (映射到 UART5) */
#define __USART5_CLK_DISABLE        __HAL_RCC_UART5_CLK_DISABLE // 关闭 USART5 时钟
#define __USART5_CLK_ENABLE         __HAL_RCC_UART5_CLK_ENABLE // 使能 USART5 时钟
#define __USART5_CLK_SLEEP_ENABLE   __HAL_RCC_UART5_CLK_SLEEP_ENABLE // 睡眠模式下使能 USART5 时钟
#define __USART5_CLK_SLEEP_DISABLE  __HAL_RCC_UART5_CLK_SLEEP_DISABLE // 睡眠模式下关闭 USART5 时钟
#define __USART5_FORCE_RESET        __HAL_RCC_UART5_FORCE_RESET // 强制复位 USART5
#define __USART5_RELEASE_RESET      __HAL_RCC_UART5_RELEASE_RESET // 释放 USART5 复位

/* USART7 通用同步/异步收发器7 时钟控制 */
#define __USART7_CLK_DISABLE        __HAL_RCC_UART7_CLK_DISABLE // 关闭 USART7 时钟
#define __USART7_CLK_ENABLE         __HAL_RCC_UART7_CLK_ENABLE // 使能 USART7 时钟
#define __USART7_FORCE_RESET        __HAL_RCC_UART7_FORCE_RESET // 强制复位 USART7
#define __USART7_RELEASE_RESET      __HAL_RCC_UART7_RELEASE_RESET // 释放 USART7 复位

/* USART8 通用同步/异步收发器8 时钟控制 */
#define __USART8_CLK_DISABLE        __HAL_RCC_UART8_CLK_DISABLE // 关闭 USART8 时钟
#define __USART8_CLK_ENABLE         __HAL_RCC_UART8_CLK_ENABLE // 使能 USART8 时钟
#define __USART8_FORCE_RESET        __HAL_RCC_UART8_FORCE_RESET // 强制复位 USART8
#define __USART8_RELEASE_RESET      __HAL_RCC_UART8_RELEASE_RESET // 释放 USART8 复位

/* USB 通用串行总线 时钟控制 */
#define __USB_CLK_DISABLE         __HAL_RCC_USB_CLK_DISABLE // 关闭 USB 时钟
#define __USB_CLK_ENABLE          __HAL_RCC_USB_CLK_ENABLE // 使能 USB 时钟
#define __USB_FORCE_RESET         __HAL_RCC_USB_FORCE_RESET // 强制复位 USB
#define __USB_CLK_SLEEP_ENABLE    __HAL_RCC_USB_CLK_SLEEP_ENABLE // 睡眠模式下使能 USB 时钟
#define __USB_CLK_SLEEP_DISABLE   __HAL_RCC_USB_CLK_SLEEP_DISABLE // 睡眠模式下关闭 USB 时钟

/* USB_OTG_FS USB全速OTG控制器 时钟控制 */
#define __USB_OTG_FS_CLK_DISABLE __HAL_RCC_USB_OTG_FS_CLK_DISABLE // 关闭 USB OTG FS 时钟
#define __USB_OTG_FS_CLK_ENABLE __HAL_RCC_USB_OTG_FS_CLK_ENABLE // 使能 USB OTG FS 时钟
#define __USB_RELEASE_RESET __HAL_RCC_USB_RELEASE_RESET // 释放 USB 复位

/* 针对 STM32H7 系列的特殊定义 */
#if defined(STM32H7)
/* WWDG 窗口看门狗 时钟控制 (映射到 WWDG1) */
#define __HAL_RCC_WWDG_CLK_DISABLE   __HAL_RCC_WWDG1_CLK_DISABLE // 关闭 WWDG 时钟
#define __HAL_RCC_WWDG_CLK_ENABLE   __HAL_RCC_WWDG1_CLK_ENABLE // 使能 WWDG 时钟
#define __HAL_RCC_WWDG_CLK_SLEEP_DISABLE  __HAL_RCC_WWDG1_CLK_SLEEP_DISABLE // 睡眠模式下关闭 WWDG 时钟
#define __HAL_RCC_WWDG_CLK_SLEEP_ENABLE  __HAL_RCC_WWDG1_CLK_SLEEP_ENABLE // 睡眠模式下使能 WWDG 时钟

/* STM32H7 系列不支持独立强制/释放复位 WWDG，定义为空操作 */
#define __HAL_RCC_WWDG_FORCE_RESET    ((void)0U)  /* STM32H7 上不可用 */
#define __HAL_RCC_WWDG_RELEASE_RESET ((void)0U) /* STM32H7 上不可用 */


/* WWDG 时钟状态检查宏 */
#define  __HAL_RCC_WWDG_IS_CLK_ENABLED    __HAL_RCC_WWDG1_IS_CLK_ENABLED // 检查 WWDG 时钟是否已使能
#define  __HAL_RCC_WWDG_IS_CLK_DISABLED  __HAL_RCC_WWDG1_IS_CLK_DISABLED // 检查 WWDG 时钟是否已关闭

/* SPI 时钟源映射定义 (用于兼容性) */
#define  RCC_SPI4CLKSOURCE_D2PCLK1       RCC_SPI4CLKSOURCE_D2PCLK2 // SPI4 时钟源映射
#define  RCC_SPI5CLKSOURCE_D2PCLK1       RCC_SPI5CLKSOURCE_D2PCLK2 // SPI5 时钟源映射
#define  RCC_SPI45CLKSOURCE_D2PCLK1      RCC_SPI45CLKSOURCE_D2PCLK2 // SPI4/5 时钟源映射
#define  RCC_SPI45CLKSOURCE_CDPCLK1      RCC_SPI45CLKSOURCE_CDPCLK2 // SPI4/5 时钟源映射
#define  RCC_SPI45CLKSOURCE_PCLK1        RCC_SPI45CLKSOURCE_PCLK2 // SPI4/5 时钟源映射
#endif

/* WWDG 窗口看门狗 时钟控制 (通用定义) */
#define __WWDG_CLK_DISABLE __HAL_RCC_WWDG_CLK_DISABLE // 关闭 WWDG 时钟
#define __WWDG_CLK_ENABLE __HAL_RCC_WWDG_CLK_ENABLE // 使能 WWDG 时钟
#define __WWDG_CLK_SLEEP_DISABLE __HAL_RCC_WWDG_CLK_SLEEP_DISABLE // 睡眠模式下关闭 WWDG 时钟
#define __WWDG_CLK_SLEEP_ENABLE __HAL_RCC_WWDG_CLK_SLEEP_ENABLE // 睡眠模式下使能 WWDG 时钟
#define __WWDG_FORCE_RESET __HAL_RCC_WWDG_FORCE_RESET // 强制复位 WWDG
#define __WWDG_RELEASE_RESET __HAL_RCC_WWDG_RELEASE_RESET // 释放 WWDG 复位

/* TIM21 通用定时器21 时钟控制 */
#define __TIM21_CLK_ENABLE   __HAL_RCC_TIM21_CLK_ENABLE // 使能 TIM21 时钟
#define __TIM21_CLK_DISABLE   __HAL_RCC_TIM21_CLK_DISABLE // 关闭 TIM21 时钟
#define __TIM21_FORCE_RESET   __HAL_RCC_TIM21_FORCE_RESET // 强制复位 TIM21
#define __TIM21_RELEASE_RESET  __HAL_RCC_TIM21_RELEASE_RESET // 释放 TIM21 复位
#define __TIM21_CLK_SLEEP_ENABLE   __HAL_RCC_TIM21_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM21 时钟
#define __TIM21_CLK_SLEEP_DISABLE   __HAL_RCC_TIM21_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM21 时钟

/* TIM22 通用定时器22 时钟控制 */
#define __TIM22_CLK_ENABLE   __HAL_RCC_TIM22_CLK_ENABLE // 使能 TIM22 时钟
#define __TIM22_CLK_DISABLE   __HAL_RCC_TIM22_CLK_DISABLE // 关闭 TIM22 时钟
#define __TIM22_FORCE_RESET   __HAL_RCC_TIM22_FORCE_RESET // 强制复位 TIM22
#define __TIM22_RELEASE_RESET  __HAL_RCC_TIM22_RELEASE_RESET // 释放 TIM22 复位
#define __TIM22_CLK_SLEEP_ENABLE   __HAL_RCC_TIM22_CLK_SLEEP_ENABLE // 睡眠模式下使能 TIM22 时钟
#define __TIM22_CLK_SLEEP_DISABLE   __HAL_RCC_TIM22_CLK_SLEEP_DISABLE // 睡眠模式下关闭 TIM22 时钟

/* CRS 时钟恢复系统 时钟控制 */
#define __CRS_CLK_DISABLE __HAL_RCC_CRS_CLK_DISABLE // 关闭 CRS 时钟
#define __CRS_CLK_ENABLE __HAL_RCC_CRS_CLK_ENABLE // 使能 CRS 时钟
#define __CRS_CLK_SLEEP_DISABLE __HAL_RCC_CRS_CLK_SLEEP_DISABLE // 睡眠模式下关闭 CRS 时钟
#define __CRS_CLK_SLEEP_ENABLE __HAL_RCC_CRS_CLK_SLEEP_ENABLE // 睡眠模式下使能 CRS 时钟
#define __CRS_FORCE_RESET __HAL_RCC_CRS_FORCE_RESET // 强制复位 CRS
#define __CRS_RELEASE_RESET __HAL_RCC_CRS_RELEASE_RESET // 释放 CRS 复位

/* RCC 备份域复位控制 */
#define __RCC_BACKUPRESET_FORCE __HAL_RCC_BACKUPRESET_FORCE // 强制备份域复位
#define __RCC_BACKUPRESET_RELEASE __HAL_RCC_BACKUPRESET_RELEASE // 释放备份域复位
/* USB OTG FS 全速模式外设复位控制宏定义 */
#define __USB_OTG_FS_FORCE_RESET  __HAL_RCC_USB_OTG_FS_FORCE_RESET // 强制复位USB OTG全速模式外设
#define __USB_OTG_FS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET // 释放复位USB OTG全速模式外设

/* USB OTG FS 睡眠模式时钟控制宏定义 */
#define __USB_OTG_FS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE // 使能USB OTG FS睡眠模式时钟
#define __USB_OTG_FS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE // 禁止USB OTG FS睡眠模式时钟

/* USB OTG HS 高速模式外设时钟控制宏定义 */
#define __USB_OTG_HS_CLK_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_DISABLE // 禁止USB OTG高速模式外设时钟
#define __USB_OTG_HS_CLK_ENABLE          __HAL_RCC_USB_OTG_HS_CLK_ENABLE // 使能USB OTG高速模式外设时钟

/* USB OTG HS ULPI接口时钟控制宏定义 (用于外部PHY) */
#define __USB_OTG_HS_ULPI_CLK_ENABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE // 使能USB OTG HS ULPI时钟
#define __USB_OTG_HS_ULPI_CLK_DISABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE // 禁止USB OTG HS ULPI时钟

/* 定时器9睡眠模式时钟控制宏定义 */
#define __TIM9_CLK_SLEEP_ENABLE          __HAL_RCC_TIM9_CLK_SLEEP_ENABLE // 使能TIM9睡眠模式时钟
#define __TIM9_CLK_SLEEP_DISABLE  __HAL_RCC_TIM9_CLK_SLEEP_DISABLE // 禁止TIM9睡眠模式时钟

/* 定时器10睡眠模式时钟控制宏定义 */
#define __TIM10_CLK_SLEEP_ENABLE  __HAL_RCC_TIM10_CLK_SLEEP_ENABLE // 使能TIM10睡眠模式时钟
#define __TIM10_CLK_SLEEP_DISABLE  __HAL_RCC_TIM10_CLK_SLEEP_DISABLE // 禁止TIM10睡眠模式时钟

/* 定时器11睡眠模式时钟控制宏定义 */
#define __TIM11_CLK_SLEEP_ENABLE  __HAL_RCC_TIM11_CLK_SLEEP_ENABLE // 使能TIM11睡眠模式时钟
#define __TIM11_CLK_SLEEP_DISABLE  __HAL_RCC_TIM11_CLK_SLEEP_DISABLE // 禁止TIM11睡眠模式时钟

/* 以太网PTP时钟控制宏定义 */
#define __ETHMACPTP_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACPTP_CLK_SLEEP_ENABLE // 使能以太网MAC PTP睡眠模式时钟
#define __ETHMACPTP_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACPTP_CLK_SLEEP_DISABLE // 禁止以太网MAC PTP睡眠模式时钟
#define __ETHMACPTP_CLK_ENABLE          __HAL_RCC_ETHMACPTP_CLK_ENABLE // 使能以太网MAC PTP时钟
#define __ETHMACPTP_CLK_DISABLE          __HAL_RCC_ETHMACPTP_CLK_DISABLE // 禁止以太网MAC PTP时钟

/* HASH硬件哈希加速器时钟控制宏定义 */
#define __HASH_CLK_ENABLE          __HAL_RCC_HASH_CLK_ENABLE // 使能HASH外设时钟
#define __HASH_FORCE_RESET          __HAL_RCC_HASH_FORCE_RESET // 强制复位HASH外设
#define __HASH_RELEASE_RESET          __HAL_RCC_HASH_RELEASE_RESET // 释放复位HASH外设
#define __HASH_CLK_SLEEP_ENABLE          __HAL_RCC_HASH_CLK_SLEEP_ENABLE // 使能HASH睡眠模式时钟
#define __HASH_CLK_SLEEP_DISABLE  __HAL_RCC_HASH_CLK_SLEEP_DISABLE // 禁止HASH睡眠模式时钟
#define __HASH_CLK_DISABLE            __HAL_RCC_HASH_CLK_DISABLE // 禁止HASH外设时钟

/* SPI5串行外设接口时钟控制宏定义 */
#define __SPI5_CLK_ENABLE          __HAL_RCC_SPI5_CLK_ENABLE // 使能SPI5时钟
#define __SPI5_CLK_DISABLE              __HAL_RCC_SPI5_CLK_DISABLE // 禁止SPI5时钟
#define __SPI5_FORCE_RESET          __HAL_RCC_SPI5_FORCE_RESET // 强制复位SPI5
#define __SPI5_RELEASE_RESET          __HAL_RCC_SPI5_RELEASE_RESET // 释放复位SPI5
#define __SPI5_CLK_SLEEP_ENABLE          __HAL_RCC_SPI5_CLK_SLEEP_ENABLE // 使能SPI5睡眠模式时钟
#define __SPI5_CLK_SLEEP_DISABLE  __HAL_RCC_SPI5_CLK_SLEEP_DISABLE // 禁止SPI5睡眠模式时钟

/* SPI6串行外设接口时钟控制宏定义 */
#define __SPI6_CLK_ENABLE          __HAL_RCC_SPI6_CLK_ENABLE // 使能SPI6时钟
#define __SPI6_CLK_DISABLE          __HAL_RCC_SPI6_CLK_DISABLE // 禁止SPI6时钟
#define __SPI6_FORCE_RESET          __HAL_RCC_SPI6_FORCE_RESET // 强制复位SPI6
#define __SPI6_RELEASE_RESET         __HAL_RCC_SPI6_RELEASE_RESET // 释放复位SPI6
#define __SPI6_CLK_SLEEP_ENABLE          __HAL_RCC_SPI6_CLK_SLEEP_ENABLE // 使能SPI6睡眠模式时钟
#define __SPI6_CLK_SLEEP_DISABLE  __HAL_RCC_SPI6_CLK_SLEEP_DISABLE // 禁止SPI6睡眠模式时钟

/* LTDC液晶显示控制器时钟控制宏定义 */
#define __LTDC_CLK_ENABLE          __HAL_RCC_LTDC_CLK_ENABLE // 使能LTDC时钟
#define __LTDC_CLK_DISABLE          __HAL_RCC_LTDC_CLK_DISABLE // 禁止LTDC时钟
#define __LTDC_FORCE_RESET          __HAL_RCC_LTDC_FORCE_RESET // 强制复位LTDC
#define __LTDC_RELEASE_RESET          __HAL_RCC_LTDC_RELEASE_RESET // 释放复位LTDC
#define __LTDC_CLK_SLEEP_ENABLE          __HAL_RCC_LTDC_CLK_SLEEP_ENABLE // 使能LTDC睡眠模式时钟

/* 以太网MAC相关睡眠模式时钟控制宏定义 */
#define __ETHMAC_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMAC_CLK_SLEEP_ENABLE // 使能以太网MAC睡眠模式时钟
#define __ETHMAC_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMAC_CLK_SLEEP_DISABLE // 禁止以太网MAC睡眠模式时钟
#define __ETHMACTX_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACTX_CLK_SLEEP_ENABLE // 使能以太网MAC发送模块睡眠模式时钟
#define __ETHMACTX_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACTX_CLK_SLEEP_DISABLE // 禁止以太网MAC发送模块睡眠模式时钟
#define __ETHMACRX_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACRX_CLK_SLEEP_ENABLE // 使能以太网MAC接收模块睡眠模式时钟
#define __ETHMACRX_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACRX_CLK_SLEEP_DISABLE // 禁止以太网MAC接收模块睡眠模式时钟

/* 定时器12/13/14睡眠模式时钟控制宏定义 */
#define __TIM12_CLK_SLEEP_ENABLE  __HAL_RCC_TIM12_CLK_SLEEP_ENABLE // 使能TIM12睡眠模式时钟
#define __TIM12_CLK_SLEEP_DISABLE  __HAL_RCC_TIM12_CLK_SLEEP_DISABLE // 禁止TIM12睡眠模式时钟
#define __TIM13_CLK_SLEEP_ENABLE  __HAL_RCC_TIM13_CLK_SLEEP_ENABLE // 使能TIM13睡眠模式时钟
#define __TIM13_CLK_SLEEP_DISABLE  __HAL_RCC_TIM13_CLK_SLEEP_DISABLE // 禁止TIM13睡眠模式时钟
#define __TIM14_CLK_SLEEP_ENABLE  __HAL_RCC_TIM14_CLK_SLEEP_ENABLE // 使能TIM14睡眠模式时钟
#define __TIM14_CLK_SLEEP_DISABLE  __HAL_RCC_TIM14_CLK_SLEEP_DISABLE // 禁止TIM14睡眠模式时钟

/* 备份SRAM时钟控制宏定义 */
#define __BKPSRAM_CLK_ENABLE          __HAL_RCC_BKPSRAM_CLK_ENABLE // 使能备份SRAM时钟
#define __BKPSRAM_CLK_DISABLE          __HAL_RCC_BKPSRAM_CLK_DISABLE // 禁止备份SRAM时钟
#define __BKPSRAM_CLK_SLEEP_ENABLE  __HAL_RCC_BKPSRAM_CLK_SLEEP_ENABLE // 使能备份SRAM睡眠模式时钟
#define __BKPSRAM_CLK_SLEEP_DISABLE  __HAL_RCC_BKPSRAM_CLK_SLEEP_DISABLE // 禁止备份SRAM睡眠模式时钟

/* CCM数据RAM时钟控制宏定义 (Core Coupled Memory) */
#define __CCMDATARAMEN_CLK_ENABLE  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE // 使能CCM数据RAM时钟
#define __CCMDATARAMEN_CLK_DISABLE  __HAL_RCC_CCMDATARAMEN_CLK_DISABLE // 禁止CCM数据RAM时钟

/* USART6通用同步/异步收发器时钟控制宏定义 */
#define __USART6_CLK_ENABLE          __HAL_RCC_USART6_CLK_ENABLE // 使能USART6时钟
#define __USART6_CLK_DISABLE          __HAL_RCC_USART6_CLK_DISABLE // 禁止USART6时钟
#define __USART6_FORCE_RESET        __HAL_RCC_USART6_FORCE_RESET // 强制复位USART6
#define __USART6_RELEASE_RESET        __HAL_RCC_USART6_RELEASE_RESET // 释放复位USART6
#define __USART6_CLK_SLEEP_ENABLE  __HAL_RCC_USART6_CLK_SLEEP_ENABLE // 使能USART6睡眠模式时钟
#define __USART6_CLK_SLEEP_DISABLE  __HAL_RCC_USART6_CLK_SLEEP_DISABLE // 禁止USART6睡眠模式时钟

/* SPI4串行外设接口时钟控制宏定义 */
#define __SPI4_CLK_ENABLE          __HAL_RCC_SPI4_CLK_ENABLE // 使能SPI4时钟
#define __SPI4_CLK_DISABLE          __HAL_RCC_SPI4_CLK_DISABLE // 禁止SPI4时钟
#define __SPI4_FORCE_RESET          __HAL_RCC_SPI4_FORCE_RESET // 强制复位SPI4
#define __SPI4_RELEASE_RESET        __HAL_RCC_SPI4_RELEASE_RESET // 释放复位SPI4
#define __SPI4_CLK_SLEEP_ENABLE   __HAL_RCC_SPI4_CLK_SLEEP_ENABLE // 使能SPI4睡眠模式时钟
#define __SPI4_CLK_SLEEP_DISABLE  __HAL_RCC_SPI4_CLK_SLEEP_DISABLE // 禁止SPI4睡眠模式时钟

/* GPIOI端口时钟控制宏定义 */
#define __GPIOI_CLK_ENABLE          __HAL_RCC_GPIOI_CLK_ENABLE // 使能GPIOI端口时钟
#define __GPIOI_CLK_DISABLE          __HAL_RCC_GPIOI_CLK_DISABLE // 禁止GPIOI端口时钟
#define __GPIOI_FORCE_RESET          __HAL_RCC_GPIOI_FORCE_RESET // 强制复位GPIOI端口
#define __GPIOI_RELEASE_RESET          __HAL_RCC_GPIOI_RELEASE_RESET // 释放复位GPIOI端口
#define __GPIOI_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOI_CLK_SLEEP_ENABLE // 使能GPIOI睡眠模式时钟
#define __GPIOI_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOI_CLK_SLEEP_DISABLE // 禁止GPIOI睡眠模式时钟

/* GPIOJ端口时钟控制宏定义 */
#define __GPIOJ_CLK_ENABLE          __HAL_RCC_GPIOJ_CLK_ENABLE // 使能GPIOJ端口时钟
#define __GPIOJ_CLK_DISABLE          __HAL_RCC_GPIOJ_CLK_DISABLE // 禁止GPIOJ端口时钟
#define __GPIOJ_FORCE_RESET         __HAL_RCC_GPIOJ_FORCE_RESET // 强制复位GPIOJ端口
#define __GPIOJ_RELEASE_RESET          __HAL_RCC_GPIOJ_RELEASE_RESET // 释放复位GPIOJ端口
#define __GPIOJ_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOJ_CLK_SLEEP_ENABLE // 使能GPIOJ睡眠模式时钟
#define __GPIOJ_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOJ_CLK_SLEEP_DISABLE // 禁止GPIOJ睡眠模式时钟

/* GPIOK端口时钟控制宏定义 */
#define __GPIOK_CLK_ENABLE          __HAL_RCC_GPIOK_CLK_ENABLE // 使能GPIOK端口时钟
#define __GPIOK_CLK_DISABLE          __HAL_RCC_GPIOK_CLK_DISABLE // 禁止GPIOK端口时钟
#define __GPIOK_RELEASE_RESET          __HAL_RCC_GPIOK_RELEASE_RESET // 释放复位GPIOK端口
#define __GPIOK_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOK_CLK_SLEEP_ENABLE // 使能GPIOK睡眠模式时钟
#define __GPIOK_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOK_CLK_SLEEP_DISABLE // 禁止GPIOK睡眠模式时钟

/* 以太网总体时钟控制宏定义 */
#define __ETH_CLK_ENABLE          __HAL_RCC_ETH_CLK_ENABLE // 使能以太网时钟
#define __ETH_CLK_DISABLE          __HAL_RCC_ETH_CLK_DISABLE // 禁止以太网时钟

/* DCMI数字摄像头接口时钟控制宏定义 */
#define __DCMI_CLK_ENABLE          __HAL_RCC_DCMI_CLK_ENABLE // 使能DCMI时钟
#define __DCMI_CLK_DISABLE          __HAL_RCC_DCMI_CLK_DISABLE // 禁止DCMI时钟
#define __DCMI_FORCE_RESET          __HAL_RCC_DCMI_FORCE_RESET // 强制复位DCMI
#define __DCMI_RELEASE_RESET          __HAL_RCC_DCMI_RELEASE_RESET // 释放复位DCMI
#define __DCMI_CLK_SLEEP_ENABLE   __HAL_RCC_DCMI_CLK_SLEEP_ENABLE // 使能DCMI睡眠模式时钟
#define __DCMI_CLK_SLEEP_DISABLE  __HAL_RCC_DCMI_CLK_SLEEP_DISABLE // 禁止DCMI睡眠模式时钟

/* UART7通用异步收发器时钟控制宏定义 */
#define __UART7_CLK_ENABLE          __HAL_RCC_UART7_CLK_ENABLE // 使能UART7时钟
#define __UART7_CLK_DISABLE          __HAL_RCC_UART7_CLK_DISABLE // 禁止UART7时钟
#define __UART7_RELEASE_RESET       __HAL_RCC_UART7_RELEASE_RESET // 释放复位UART7
#define __UART7_FORCE_RESET       __HAL_RCC_UART7_FORCE_RESET // 强制复位UART7
#define __UART7_CLK_SLEEP_ENABLE  __HAL_RCC_UART7_CLK_SLEEP_ENABLE // 使能UART7睡眠模式时钟
#define __UART7_CLK_SLEEP_DISABLE  __HAL_RCC_UART7_CLK_SLEEP_DISABLE // 禁止UART7睡眠模式时钟

/* UART8通用异步收发器时钟控制宏定义 */
#define __UART8_CLK_ENABLE          __HAL_RCC_UART8_CLK_ENABLE // 使能UART8时钟
#define __UART8_CLK_DISABLE          __HAL_RCC_UART8_CLK_DISABLE // 禁止UART8时钟
#define __UART8_FORCE_RESET          __HAL_RCC_UART8_FORCE_RESET // 强制复位UART8
#define __UART8_RELEASE_RESET          __HAL_RCC_UART8_RELEASE_RESET // 释放复位UART8
#define __UART8_CLK_SLEEP_ENABLE  __HAL_RCC_UART8_CLK_SLEEP_ENABLE // 使能UART8睡眠模式时钟
#define __UART8_CLK_SLEEP_DISABLE  __HAL_RCC_UART8_CLK_SLEEP_DISABLE // 禁止UART8睡眠模式时钟

/* USB OTG HS高速模式相关控制宏定义 */
#define __OTGHS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE // 使能USB OTG HS睡眠模式时钟
#define __OTGHS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE // 禁止USB OTG HS睡眠模式时钟
#define __OTGHS_FORCE_RESET          __HAL_RCC_USB_OTG_HS_FORCE_RESET // 强制复位USB OTG HS
#define __OTGHS_RELEASE_RESET          __HAL_RCC_USB_OTG_HS_RELEASE_RESET // 释放复位USB OTG HS
#define __OTGHSULPI_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE // 使能USB OTG HS ULPI睡眠模式时钟
#define __OTGHSULPI_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE // 禁止USB OTG HS ULPI睡眠模式时钟

/* USB OTG HS高速模式HAL库内部宏定义 */
#define __HAL_RCC_OTGHS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE // 使能OTG HS睡眠模式时钟
#define __HAL_RCC_OTGHS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE // 禁止OTG HS睡眠模式时钟
#define __HAL_RCC_OTGHS_IS_CLK_SLEEP_ENABLED __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_ENABLED // 检查OTG HS睡眠模式时钟是否使能
#define __HAL_RCC_OTGHS_IS_CLK_SLEEP_DISABLED __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_DISABLED // 检查OTG HS睡眠模式时钟是否禁止
#define __HAL_RCC_OTGHS_FORCE_RESET          __HAL_RCC_USB_OTG_HS_FORCE_RESET // 强制复位OTG HS
#define __HAL_RCC_OTGHS_RELEASE_RESET          __HAL_RCC_USB_OTG_HS_RELEASE_RESET // 释放复位OTG HS
#define __HAL_RCC_OTGHSULPI_CLK_SLEEP_ENABLE      __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE // 使能OTG HS ULPI睡眠模式时钟
#define __HAL_RCC_OTGHSULPI_CLK_SLEEP_DISABLE     __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE // 禁止OTG HS ULPI睡眠模式时钟
#define __HAL_RCC_OTGHSULPI_IS_CLK_SLEEP_ENABLED  __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_ENABLED // 检查OTG HS ULPI睡眠模式时钟是否使能
#define __HAL_RCC_OTGHSULPI_IS_CLK_SLEEP_DISABLED __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_DISABLED // 检查OTG HS ULPI睡眠模式时钟是否禁止

/* 其他外设睡眠模式时钟控制宏定义 */
#define __SRAM3_CLK_SLEEP_ENABLE       __HAL_RCC_SRAM3_CLK_SLEEP_ENABLE // 使能SRAM3睡眠模式时钟
#define __CAN2_CLK_SLEEP_ENABLE        __HAL_RCC_CAN2_CLK_SLEEP_ENABLE // 使能CAN2睡眠模式时钟
#define __CAN2_CLK_SLEEP_DISABLE       __HAL_RCC_CAN2_CLK_SLEEP_DISABLE // 禁止CAN2睡眠模式时钟
#define __DAC_CLK_SLEEP_ENABLE         __HAL_RCC_DAC_CLK_SLEEP_ENABLE // 使能DAC睡眠模式时钟
#define __DAC_CLK_SLEEP_DISABLE        __HAL_RCC_DAC_CLK_SLEEP_DISABLE // 禁止DAC睡眠模式时钟
#define __ADC2_CLK_SLEEP_ENABLE        __HAL_RCC_ADC2_CLK_SLEEP_ENABLE // 使能ADC2睡眠模式时钟
#define __ADC2_CLK_SLEEP_DISABLE       __HAL_RCC_ADC2_CLK_SLEEP_DISABLE // 禁止ADC2睡眠模式时钟
#define __ADC3_CLK_SLEEP_ENABLE        __HAL_RCC_ADC3_CLK_SLEEP_ENABLE // 使能ADC3睡眠模式时钟
#define __ADC3_CLK_SLEEP_DISABLE       __HAL_RCC_ADC3_CLK_SLEEP_DISABLE // 禁止ADC3睡眠模式时钟

/* FSMC可变静态存储控制器复位与睡眠时钟控制宏定义 */
#define __FSMC_FORCE_RESET             __HAL_RCC_FSMC_FORCE_RESET // 强制复位FSMC
#define __FSMC_RELEASE_RESET           __HAL_RCC_FSMC_RELEASE_RESET // 释放复位FSMC
#define __FSMC_CLK_SLEEP_ENABLE        __HAL_RCC_FSMC_CLK_SLEEP_ENABLE // 使能FSMC睡眠模式时钟
#define __FSMC_CLK_SLEEP_DISABLE       __HAL_RCC_FSMC_CLK_SLEEP_DISABLE // 禁止FSMC睡眠模式时钟

/* SDIO安全数字输入输出接口复位与睡眠时钟控制宏定义 */
#define __SDIO_FORCE_RESET             __HAL_RCC_SDIO_FORCE_RESET // 强制复位SDIO
#define __SDIO_RELEASE_RESET           __HAL_RCC_SDIO_RELEASE_RESET // 释放复位SDIO
#define __SDIO_CLK_SLEEP_DISABLE       __HAL_RCC_SDIO_CLK_SLEEP_DISABLE // 禁止SDIO睡眠模式时钟
#define __SDIO_CLK_SLEEP_ENABLE        __HAL_RCC_SDIO_CLK_SLEEP_ENABLE // 使能SDIO睡眠模式时钟

/* DMA2D图形加速器时钟控制宏定义 */
#define __DMA2D_CLK_ENABLE             __HAL_RCC_DMA2D_CLK_ENABLE // 使能DMA2D时钟
#define __DMA2D_CLK_DISABLE            __HAL_RCC_DMA2D_CLK_DISABLE // 禁止DMA2D时钟
#define __DMA2D_FORCE_RESET            __HAL_RCC_DMA2D_FORCE_RESET // 强制复位DMA2D
#define __DMA2D_RELEASE_RESET          __HAL_RCC_DMA2D_RELEASE_RESET // 释放复位DMA2D
#define __DMA2D_CLK_SLEEP_ENABLE       __HAL_RCC_DMA2D_CLK_SLEEP_ENABLE // 使能DMA2D睡眠模式时钟
#define __DMA2D_CLK_SLEEP_DISABLE      __HAL_RCC_DMA2D_CLK_SLEEP_DISABLE // 禁止DMA2D睡眠模式时钟

/* 为了兼容旧版本代码而保留的别名定义 */
#define __HAL_RCC_OTGFS_FORCE_RESET    __HAL_RCC_USB_OTG_FS_FORCE_RESET // 强制复位USB OTG FS (旧名称别名)
#define __HAL_RCC_OTGFS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET // 释放复位USB OTG FS (旧名称别名)

/* ADC12/ADC34模数转换器时钟控制宏定义 (通常用于STM32F3系列) */
#define __ADC12_CLK_ENABLE          __HAL_RCC_ADC12_CLK_ENABLE // 使能ADC12时钟
#define __ADC12_CLK_DISABLE         __HAL_RCC_ADC12_CLK_DISABLE // 禁止ADC12时钟
#define __ADC34_CLK_ENABLE          __HAL_RCC_ADC34_CLK_ENABLE // 使能ADC34时钟
#define __ADC34_CLK_DISABLE         __HAL_RCC_ADC34_CLK_DISABLE // 禁止ADC34时钟

/* DAC2数模转换器时钟控制宏定义 */
#define __DAC2_CLK_ENABLE           __HAL_RCC_DAC2_CLK_ENABLE // 使能DAC2时钟
#define __DAC2_CLK_DISABLE          __HAL_RCC_DAC2_CLK_DISABLE // 禁止DAC2时钟

/* 定时器18/19/20时钟控制宏定义 */
#define __TIM18_CLK_ENABLE          __HAL_RCC_TIM18_CLK_ENABLE // 使能TIM18时钟
#define __TIM18_CLK_DISABLE         __HAL_RCC_TIM18_CLK_DISABLE // 禁止TIM18时钟
#define __TIM19_CLK_ENABLE          __HAL_RCC_TIM19_CLK_ENABLE // 使能TIM19时钟
#define __TIM19_CLK_DISABLE         __HAL_RCC_TIM19_CLK_DISABLE // 禁止TIM19时钟
#define __TIM20_CLK_ENABLE          __HAL_RCC_TIM20_CLK_ENABLE // 使能TIM20时钟
#define __TIM20_CLK_DISABLE         __HAL_RCC_TIM20_CLK_DISABLE // 禁止TIM20时钟

/* HRTIM1高分辨率定时器时钟控制宏定义 */
#define __HRTIM1_CLK_ENABLE         __HAL_RCC_HRTIM1_CLK_ENABLE // 使能HRTIM1时钟
#define __HRTIM1_CLK_DISABLE        __HAL_RCC_HRTIM1_CLK_DISABLE // 禁止HRTIM1时钟

/* SDADC1/2/3 sigma-delta模数转换器时钟控制宏定义 */
#define __SDADC1_CLK_ENABLE         __HAL_RCC_SDADC1_CLK_ENABLE // 使能SDADC1时钟
#define __SDADC2_CLK_ENABLE         __HAL_RCC_SDADC2_CLK_ENABLE // 使能SDADC2时钟
#define __SDADC3_CLK_ENABLE         __HAL_RCC_SDADC3_CLK_ENABLE // 使能SDADC3时钟
#define __SDADC1_CLK_DISABLE        __HAL_RCC_SDADC1_CLK_DISABLE // 禁止SDADC1时钟
#define __SDADC2_CLK_DISABLE        __HAL_RCC_SDADC2_CLK_DISABLE // 禁止SDADC2时钟
#define __SDADC3_CLK_DISABLE        __HAL_RCC_SDADC3_CLK_DISABLE // 禁止SDADC3时钟

/* ADC12/ADC34模数转换器复位控制宏定义 */
#define __ADC12_FORCE_RESET         __HAL_RCC_ADC12_FORCE_RESET // 强制复位ADC12
#define __ADC12_RELEASE_RESET       __HAL_RCC_ADC12_RELEASE_RESET // 释放复位ADC12
#define __ADC34_FORCE_RESET         __HAL_RCC_ADC34_FORCE_RESET // 强制复位ADC34
#define __ADC34_RELEASE_RESET       __HAL_RCC_ADC34_RELEASE_RESET // 释放复位ADC34

/* DAC2数模转换器复位控制宏定义 */
#define __DAC2_FORCE_RESET          __HAL_RCC_DAC2_FORCE_RESET // 强制复位DAC2
#define __DAC2_RELEASE_RESET        __HAL_RCC_DAC2_RELEASE_RESET // 释放复位DAC2

/* 定时器18/19/20复位控制宏定义 */
#define __TIM18_FORCE_RESET         __HAL_RCC_TIM18_FORCE_RESET // 强制复位TIM18
#define __TIM18_RELEASE_RESET       __HAL_RCC_TIM18_RELEASE_RESET // 释放复位TIM18
#define __TIM19_FORCE_RESET         __HAL_RCC_TIM19_FORCE_RESET // 强制复位TIM19
#define __TIM19_RELEASE_RESET       __HAL_RCC_TIM19_RELEASE_RESET // 释放复位TIM19
#define __TIM20_FORCE_RESET         __HAL_RCC_TIM20_FORCE_RESET // 强制复位TIM20
#define __TIM20_RELEASE_RESET       __HAL_RCC_TIM20_RELEASE_RESET // 释放复位TIM20

/* HRTIM1高分辨率定时器复位控制宏定义 */
#define __HRTIM1_FORCE_RESET        __HAL_RCC_HRTIM1_FORCE_RESET // 强制复位HRTIM1
#define __HRTIM1_RELEASE_RESET      __HAL_RCC_HRTIM1_RELEASE_RESET // 释放复位HRTIM1

/* SDADC1/2/3 sigma-delta模数转换器复位控制宏定义 */
#define __SDADC1_FORCE_RESET        __HAL_RCC_SDADC1_FORCE_RESET // 强制复位SDADC1
#define __SDADC2_FORCE_RESET        __HAL_RCC_SDADC2_FORCE_RESET // 强制复位SDADC2
#define __SDADC3_FORCE_RESET        __HAL_RCC_SDADC3_FORCE_RESET // 强制复位SDADC3
#define __SDADC1_RELEASE_RESET      __HAL_RCC_SDADC1_RELEASE_RESET // 释放复位SDADC1
#define __SDADC2_RELEASE_RESET      __HAL_RCC_SDADC2_RELEASE_RESET // 释放复位SDADC2
#define __SDADC3_RELEASE_RESET      __HAL_RCC_SDADC3_RELEASE_RESET // 释放复位SDADC3
/* ADC1时钟使能状态检查宏 */
#define __ADC1_IS_CLK_ENABLED       __HAL_RCC_ADC1_IS_CLK_ENABLED
/* ADC1时钟禁用状态检查宏 */
#define __ADC1_IS_CLK_DISABLED      __HAL_RCC_ADC1_IS_CLK_DISABLED
/* ADC1和ADC2时钟使能状态检查宏 */
#define __ADC12_IS_CLK_ENABLED      __HAL_RCC_ADC12_IS_CLK_ENABLED
/* ADC1和ADC2时钟禁用状态检查宏 */
#define __ADC12_IS_CLK_DISABLED     __HAL_RCC_ADC12_IS_CLK_DISABLED
/* ADC3和ADC4时钟使能状态检查宏 */
#define __ADC34_IS_CLK_ENABLED      __HAL_RCC_ADC34_IS_CLK_ENABLED
/* ADC3和ADC4时钟禁用状态检查宏 */
#define __ADC34_IS_CLK_DISABLED     __HAL_RCC_ADC34_IS_CLK_DISABLED
/* CEC(消费电子控制)时钟使能状态检查宏 */
#define __CEC_IS_CLK_ENABLED        __HAL_RCC_CEC_IS_CLK_ENABLED
/* CEC时钟禁用状态检查宏 */
#define __CEC_IS_CLK_DISABLED       __HAL_RCC_CEC_IS_CLK_DISABLED
/* CRC(循环冗余校验)时钟使能状态检查宏 */
#define __CRC_IS_CLK_ENABLED        __HAL_RCC_CRC_IS_CLK_ENABLED
/* CRC时钟禁用状态检查宏 */
#define __CRC_IS_CLK_DISABLED       __HAL_RCC_CRC_IS_CLK_DISABLED
/* DAC1(数模转换器1)时钟使能状态检查宏 */
#define __DAC1_IS_CLK_ENABLED       __HAL_RCC_DAC1_IS_CLK_ENABLED
/* DAC1时钟禁用状态检查宏 */
#define __DAC1_IS_CLK_DISABLED      __HAL_RCC_DAC1_IS_CLK_DISABLED
/* DAC2(数模转换器2)时钟使能状态检查宏 */
#define __DAC2_IS_CLK_ENABLED       __HAL_RCC_DAC2_IS_CLK_ENABLED
/* DAC2时钟禁用状态检查宏 */
#define __DAC2_IS_CLK_DISABLED      __HAL_RCC_DAC2_IS_CLK_DISABLED
/* DMA1(直接存储器访问控制器1)时钟使能状态检查宏 */
#define __DMA1_IS_CLK_ENABLED       __HAL_RCC_DMA1_IS_CLK_ENABLED
/* DMA1时钟禁用状态检查宏 */
#define __DMA1_IS_CLK_DISABLED      __HAL_RCC_DMA1_IS_CLK_DISABLED
/* DMA2时钟使能状态检查宏 */
#define __DMA2_IS_CLK_ENABLED       __HAL_RCC_DMA2_IS_CLK_ENABLED
/* DMA2时钟禁用状态检查宏 */
#define __DMA2_IS_CLK_DISABLED      __HAL_RCC_DMA2_IS_CLK_DISABLED
/* FLITF(Flash存储器接口)时钟使能状态检查宏 */
#define __FLITF_IS_CLK_ENABLED      __HAL_RCC_FLITF_IS_CLK_ENABLED
/* FLITF时钟禁用状态检查宏 */
#define __FLITF_IS_CLK_DISABLED     __HAL_RCC_FLITF_IS_CLK_DISABLED
/* FMC(灵活存储控制器)时钟使能状态检查宏 */
#define __FMC_IS_CLK_ENABLED        __HAL_RCC_FMC_IS_CLK_ENABLED
/* FMC时钟禁用状态检查宏 */
#define __FMC_IS_CLK_DISABLED       __HAL_RCC_FMC_IS_CLK_DISABLED
/* GPIOA端口时钟使能状态检查宏 */
#define __GPIOA_IS_CLK_ENABLED      __HAL_RCC_GPIOA_IS_CLK_ENABLED
/* GPIOA端口时钟禁用状态检查宏 */
#define __GPIOA_IS_CLK_DISABLED     __HAL_RCC_GPIOA_IS_CLK_DISABLED
/* GPIOB端口时钟使能状态检查宏 */
#define __GPIOB_IS_CLK_ENABLED      __HAL_RCC_GPIOB_IS_CLK_ENABLED
/* GPIOB端口时钟禁用状态检查宏 */
#define __GPIOB_IS_CLK_DISABLED     __HAL_RCC_GPIOB_IS_CLK_DISABLED
/* GPIOC端口时钟使能状态检查宏 */
#define __GPIOC_IS_CLK_ENABLED      __HAL_RCC_GPIOC_IS_CLK_ENABLED
/* GPIOC端口时钟禁用状态检查宏 */
#define __GPIOC_IS_CLK_DISABLED     __HAL_RCC_GPIOC_IS_CLK_DISABLED
/* GPIOD端口时钟使能状态检查宏 */
#define __GPIOD_IS_CLK_ENABLED      __HAL_RCC_GPIOD_IS_CLK_ENABLED
/* GPIOD端口时钟禁用状态检查宏 */
#define __GPIOD_IS_CLK_DISABLED     __HAL_RCC_GPIOD_IS_CLK_DISABLED
/* GPIOE端口时钟使能状态检查宏 */
#define __GPIOE_IS_CLK_ENABLED      __HAL_RCC_GPIOE_IS_CLK_ENABLED
/* GPIOE端口时钟禁用状态检查宏 */
#define __GPIOE_IS_CLK_DISABLED     __HAL_RCC_GPIOE_IS_CLK_DISABLED
/* GPIOF端口时钟使能状态检查宏 */
#define __GPIOF_IS_CLK_ENABLED      __HAL_RCC_GPIOF_IS_CLK_ENABLED
/* GPIOF端口时钟禁用状态检查宏 */
#define __GPIOF_IS_CLK_DISABLED     __HAL_RCC_GPIOF_IS_CLK_DISABLED
/* GPIOG端口时钟使能状态检查宏 */
#define __GPIOG_IS_CLK_ENABLED      __HAL_RCC_GPIOG_IS_CLK_ENABLED
/* GPIOG端口时钟禁用状态检查宏 */
#define __GPIOG_IS_CLK_DISABLED     __HAL_RCC_GPIOG_IS_CLK_DISABLED
/* GPIOH端口时钟使能状态检查宏 */
#define __GPIOH_IS_CLK_ENABLED      __HAL_RCC_GPIOH_IS_CLK_ENABLED
/* GPIOH端口时钟禁用状态检查宏 */
#define __GPIOH_IS_CLK_DISABLED     __HAL_RCC_GPIOH_IS_CLK_DISABLED
/* HRTIM1(高分辨率定时器1)时钟使能状态检查宏 */
#define __HRTIM1_IS_CLK_ENABLED     __HAL_RCC_HRTIM1_IS_CLK_ENABLED
/* HRTIM1时钟禁用状态检查宏 */
#define __HRTIM1_IS_CLK_DISABLED    __HAL_RCC_HRTIM1_IS_CLK_DISABLED
/* I2C1时钟使能状态检查宏 */
#define __I2C1_IS_CLK_ENABLED       __HAL_RCC_I2C1_IS_CLK_ENABLED
/* I2C1时钟禁用状态检查宏 */
#define __I2C1_IS_CLK_DISABLED      __HAL_RCC_I2C1_IS_CLK_DISABLED
/* I2C2时钟使能状态检查宏 */
#define __I2C2_IS_CLK_ENABLED       __HAL_RCC_I2C2_IS_CLK_ENABLED
/* I2C2时钟禁用状态检查宏 */
#define __I2C2_IS_CLK_DISABLED      __HAL_RCC_I2C2_IS_CLK_DISABLED
/* I2C3时钟使能状态检查宏 */
#define __I2C3_IS_CLK_ENABLED       __HAL_RCC_I2C3_IS_CLK_ENABLED
/* I2C3时钟禁用状态检查宏 */
#define __I2C3_IS_CLK_DISABLED      __HAL_RCC_I2C3_IS_CLK_DISABLED
/* PWR(电源接口)时钟使能状态检查宏 */
#define __PWR_IS_CLK_ENABLED        __HAL_RCC_PWR_IS_CLK_ENABLED
/* PWR时钟禁用状态检查宏 */
#define __PWR_IS_CLK_DISABLED       __HAL_RCC_PWR_IS_CLK_DISABLED
/* SYSCFG(系统配置控制器)时钟使能状态检查宏 */
#define __SYSCFG_IS_CLK_ENABLED     __HAL_RCC_SYSCFG_IS_CLK_ENABLED
/* SYSCFG时钟禁用状态检查宏 */
#define __SYSCFG_IS_CLK_DISABLED    __HAL_RCC_SYSCFG_IS_CLK_DISABLED
/* SPI1时钟使能状态检查宏 */
#define __SPI1_IS_CLK_ENABLED       __HAL_RCC_SPI1_IS_CLK_ENABLED
/* SPI1时钟禁用状态检查宏 */
#define __SPI1_IS_CLK_DISABLED      __HAL_RCC_SPI1_IS_CLK_DISABLED
/* SPI2时钟使能状态检查宏 */
#define __SPI2_IS_CLK_ENABLED       __HAL_RCC_SPI2_IS_CLK_ENABLED
/* SPI2时钟禁用状态检查宏 */
#define __SPI2_IS_CLK_DISABLED      __HAL_RCC_SPI2_IS_CLK_DISABLED
/* SPI3时钟使能状态检查宏 */
#define __SPI3_IS_CLK_ENABLED       __HAL_RCC_SPI3_IS_CLK_ENABLED
/* SPI3时钟禁用状态检查宏 */
#define __SPI3_IS_CLK_DISABLED      __HAL_RCC_SPI3_IS_CLK_DISABLED
/* SPI4时钟使能状态检查宏 */
#define __SPI4_IS_CLK_ENABLED       __HAL_RCC_SPI4_IS_CLK_ENABLED
/* SPI4时钟禁用状态检查宏 */
#define __SPI4_IS_CLK_DISABLED      __HAL_RCC_SPI4_IS_CLK_DISABLED
/* SDADC1(Sigma-Delta ADC1)时钟使能状态检查宏 */
#define __SDADC1_IS_CLK_ENABLED     __HAL_RCC_SDADC1_IS_CLK_ENABLED
/* SDADC1时钟禁用状态检查宏 */
#define __SDADC1_IS_CLK_DISABLED    __HAL_RCC_SDADC1_IS_CLK_DISABLED
/* SDADC2时钟使能状态检查宏 */
#define __SDADC2_IS_CLK_ENABLED     __HAL_RCC_SDADC2_IS_CLK_ENABLED
/* SDADC2时钟禁用状态检查宏 */
#define __SDADC2_IS_CLK_DISABLED    __HAL_RCC_SDADC2_IS_CLK_DISABLED
/* SDADC3时钟使能状态检查宏 */
#define __SDADC3_IS_CLK_ENABLED     __HAL_RCC_SDADC3_IS_CLK_ENABLED
/* SDADC3时钟禁用状态检查宏 */
#define __SDADC3_IS_CLK_DISABLED    __HAL_RCC_SDADC3_IS_CLK_DISABLED
/* SRAM时钟使能状态检查宏 */
#define __SRAM_IS_CLK_ENABLED       __HAL_RCC_SRAM_IS_CLK_ENABLED
/* SRAM时钟禁用状态检查宏 */
#define __SRAM_IS_CLK_DISABLED      __HAL_RCC_SRAM_IS_CLK_DISABLED
/* TIM1(定时器1)时钟使能状态检查宏 */
#define __TIM1_IS_CLK_ENABLED       __HAL_RCC_TIM1_IS_CLK_ENABLED
/* TIM1时钟禁用状态检查宏 */
#define __TIM1_IS_CLK_DISABLED      __HAL_RCC_TIM1_IS_CLK_DISABLED
/* TIM2时钟使能状态检查宏 */
#define __TIM2_IS_CLK_ENABLED       __HAL_RCC_TIM2_IS_CLK_ENABLED
/* TIM2时钟禁用状态检查宏 */
#define __TIM2_IS_CLK_DISABLED      __HAL_RCC_TIM2_IS_CLK_DISABLED
/* TIM3时钟使能状态检查宏 */
#define __TIM3_IS_CLK_ENABLED       __HAL_RCC_TIM3_IS_CLK_ENABLED
/* TIM3时钟禁用状态检查宏 */
#define __TIM3_IS_CLK_DISABLED      __HAL_RCC_TIM3_IS_CLK_DISABLED
/* TIM4时钟使能状态检查宏 */
#define __TIM4_IS_CLK_ENABLED       __HAL_RCC_TIM4_IS_CLK_ENABLED
/* TIM4时钟禁用状态检查宏 */
#define __TIM4_IS_CLK_DISABLED      __HAL_RCC_TIM4_IS_CLK_DISABLED
/* TIM5时钟使能状态检查宏 */
#define __TIM5_IS_CLK_ENABLED       __HAL_RCC_TIM5_IS_CLK_ENABLED
/* TIM5时钟禁用状态检查宏 */
#define __TIM5_IS_CLK_DISABLED      __HAL_RCC_TIM5_IS_CLK_DISABLED
/* TIM6时钟使能状态检查宏 */
#define __TIM6_IS_CLK_ENABLED       __HAL_RCC_TIM6_IS_CLK_ENABLED
/* TIM6时钟禁用状态检查宏 */
#define __TIM6_IS_CLK_DISABLED      __HAL_RCC_TIM6_IS_CLK_DISABLED
/* TIM7时钟使能状态检查宏 */
#define __TIM7_IS_CLK_ENABLED       __HAL_RCC_TIM7_IS_CLK_ENABLED
/* TIM7时钟禁用状态检查宏 */
#define __TIM7_IS_CLK_DISABLED      __HAL_RCC_TIM7_IS_CLK_DISABLED
/* TIM8时钟使能状态检查宏 */
#define __TIM8_IS_CLK_ENABLED       __HAL_RCC_TIM8_IS_CLK_ENABLED
/* TIM8时钟禁用状态检查宏 */
#define __TIM8_IS_CLK_DISABLED      __HAL_RCC_TIM8_IS_CLK_DISABLED
/* TIM12时钟使能状态检查宏 */
#define __TIM12_IS_CLK_ENABLED      __HAL_RCC_TIM12_IS_CLK_ENABLED
/* TIM12时钟禁用状态检查宏 */
#define __TIM12_IS_CLK_DISABLED     __HAL_RCC_TIM12_IS_CLK_DISABLED
/* TIM13时钟使能状态检查宏 */
#define __TIM13_IS_CLK_ENABLED      __HAL_RCC_TIM13_IS_CLK_ENABLED
/* TIM13时钟禁用状态检查宏 */
#define __TIM13_IS_CLK_DISABLED     __HAL_RCC_TIM13_IS_CLK_DISABLED
/* TIM14时钟使能状态检查宏 */
#define __TIM14_IS_CLK_ENABLED      __HAL_RCC_TIM14_IS_CLK_ENABLED
/* TIM14时钟禁用状态检查宏 */
#define __TIM14_IS_CLK_DISABLED     __HAL_RCC_TIM14_IS_CLK_DISABLED
/* TIM15时钟使能状态检查宏 */
#define __TIM15_IS_CLK_ENABLED      __HAL_RCC_TIM15_IS_CLK_ENABLED
/* TIM15时钟禁用状态检查宏 */
#define __TIM15_IS_CLK_DISABLED     __HAL_RCC_TIM15_IS_CLK_DISABLED
/* TIM16时钟使能状态检查宏 */
#define __TIM16_IS_CLK_ENABLED      __HAL_RCC_TIM16_IS_CLK_ENABLED
/* TIM16时钟禁用状态检查宏 */
#define __TIM16_IS_CLK_DISABLED     __HAL_RCC_TIM16_IS_CLK_DISABLED
/* TIM17时钟使能状态检查宏 */
#define __TIM17_IS_CLK_ENABLED      __HAL_RCC_TIM17_IS_CLK_ENABLED
/* TIM17时钟禁用状态检查宏 */
#define __TIM17_IS_CLK_DISABLED     __HAL_RCC_TIM17_IS_CLK_DISABLED
/* TIM18时钟使能状态检查宏 */
#define __TIM18_IS_CLK_ENABLED      __HAL_RCC_TIM18_IS_CLK_ENABLED
/* TIM18时钟禁用状态检查宏 */
#define __TIM18_IS_CLK_DISABLED     __HAL_RCC_TIM18_IS_CLK_DISABLED
/* TIM19时钟使能状态检查宏 */
#define __TIM19_IS_CLK_ENABLED      __HAL_RCC_TIM19_IS_CLK_ENABLED
/* TIM19时钟禁用状态检查宏 */
#define __TIM19_IS_CLK_DISABLED     __HAL_RCC_TIM19_IS_CLK_DISABLED
/* TIM20时钟使能状态检查宏 */
#define __TIM20_IS_CLK_ENABLED      __HAL_RCC_TIM20_IS_CLK_ENABLED
/* TIM20时钟禁用状态检查宏 */
#define __TIM20_IS_CLK_DISABLED     __HAL_RCC_TIM20_IS_CLK_DISABLED
/* TSC(触摸感应控制器)时钟使能状态检查宏 */
#define __TSC_IS_CLK_ENABLED        __HAL_RCC_TSC_IS_CLK_ENABLED
/* TSC时钟禁用状态检查宏 */
#define __TSC_IS_CLK_DISABLED       __HAL_RCC_TSC_IS_CLK_DISABLED
/* UART4时钟使能状态检查宏 */
#define __UART4_IS_CLK_ENABLED      __HAL_RCC_UART4_IS_CLK_ENABLED
/* UART4时钟禁用状态检查宏 */
#define __UART4_IS_CLK_DISABLED     __HAL_RCC_UART4_IS_CLK_DISABLED
/* UART5时钟使能状态检查宏 */
#define __UART5_IS_CLK_ENABLED      __HAL_RCC_UART5_IS_CLK_ENABLED
/* UART5时钟禁用状态检查宏 */
#define __UART5_IS_CLK_DISABLED     __HAL_RCC_UART5_IS_CLK_DISABLED
/* USART1时钟使能状态检查宏 */
#define __USART1_IS_CLK_ENABLED     __HAL_RCC_USART1_IS_CLK_ENABLED
/* USART1时钟禁用状态检查宏 */
#define __USART1_IS_CLK_DISABLED    __HAL_RCC_USART1_IS_CLK_DISABLED
/* USART2时钟使能状态检查宏 */
#define __USART2_IS_CLK_ENABLED     __HAL_RCC_USART2_IS_CLK_ENABLED
/* USART2时钟禁用状态检查宏 */
#define __USART2_IS_CLK_DISABLED    __HAL_RCC_USART2_IS_CLK_DISABLED
/* USART3时钟使能状态检查宏 */
#define __USART3_IS_CLK_ENABLED     __HAL_RCC_USART3_IS_CLK_ENABLED
/* USART3时钟禁用状态检查宏 */
#define __USART3_IS_CLK_DISABLED    __HAL_RCC_USART3_IS_CLK_DISABLED
/* USB时钟使能状态检查宏 */
#define __USB_IS_CLK_ENABLED        __HAL_RCC_USB_IS_CLK_ENABLED
/* USB时钟禁用状态检查宏 */
#define __USB_IS_CLK_DISABLED       __HAL_RCC_USB_IS_CLK_DISABLED
/* WWDG(窗口看门狗)时钟使能状态检查宏 */
#define __WWDG_IS_CLK_ENABLED       __HAL_RCC_WWDG_IS_CLK_ENABLED
/* WWDG时钟禁用状态检查宏 */
#define __WWDG_IS_CLK_DISABLED      __HAL_RCC_WWDG_IS_CLK_DISABLED

/* 针对STM32L1系列设备的兼容性宏定义 */
/* 将CRYP(加密处理器)相关宏映射到AES(高级加密标准)宏 */
#if defined(STM32L1)
#define __HAL_RCC_CRYP_CLK_DISABLE         __HAL_RCC_AES_CLK_DISABLE
#define __HAL_RCC_CRYP_CLK_ENABLE          __HAL_RCC_AES_CLK_ENABLE
#define __HAL_RCC_CRYP_CLK_SLEEP_DISABLE   __HAL_RCC_AES_CLK_SLEEP_DISABLE
#define __HAL_RCC_CRYP_CLK_SLEEP_ENABLE    __HAL_RCC_AES_CLK_SLEEP_ENABLE
#define __HAL_RCC_CRYP_FORCE_RESET         __HAL_RCC_AES_FORCE_RESET
#define __HAL_RCC_CRYP_RELEASE_RESET       __HAL_RCC_AES_RELEASE_RESET
#endif /* STM32L1 */

/* 针对STM32F4系列设备的兼容性宏定义 */
/* 将SDMMC1(SD/多媒体卡接口1)相关宏映射到SDIO(安全数字输入输出)宏 */
#if defined(STM32F4)
#define __HAL_RCC_SDMMC1_FORCE_RESET       __HAL_RCC_SDIO_FORCE_RESET
#define __HAL_RCC_SDMMC1_RELEASE_RESET     __HAL_RCC_SDIO_RELEASE_RESET
#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE  __HAL_RCC_SDIO_CLK_SLEEP_ENABLE
#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE __HAL_RCC_SDIO_CLK_SLEEP_DISABLE
#define __HAL_RCC_SDMMC1_CLK_ENABLE        __HAL_RCC_SDIO_CLK_ENABLE
#define __HAL_RCC_SDMMC1_CLK_DISABLE       __HAL_RCC_SDIO_CLK_DISABLE
#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED    __HAL_RCC_SDIO_IS_CLK_ENABLED
#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED   __HAL_RCC_SDIO_IS_CLK_DISABLED
#define Sdmmc1ClockSelection               SdioClockSelection
#define RCC_PERIPHCLK_SDMMC1               RCC_PERIPHCLK_SDIO
#define RCC_SDMMC1CLKSOURCE_CLK48          RCC_SDIOCLKSOURCE_CK48
#define RCC_SDMMC1CLKSOURCE_SYSCLK         RCC_SDIOCLKSOURCE_SYSCLK
#define __HAL_RCC_SDMMC1_CONFIG            __HAL_RCC_SDIO_CONFIG
#define __HAL_RCC_GET_SDMMC1_SOURCE        __HAL_RCC_GET_SDIO_SOURCE
#endif

/* 针对STM32F7或STM32L4系列设备的兼容性宏定义 */
/* 将SDIO相关宏映射到SDMMC1宏，保持向后兼容 */
#if defined(STM32F7) || defined(STM32L4)
#define __HAL_RCC_SDIO_FORCE_RESET         __HAL_RCC_SDMMC1_FORCE_RESET
#define __HAL_RCC_SDIO_RELEASE_RESET       __HAL_RCC_SDMMC1_RELEASE_RESET
#define __HAL_RCC_SDIO_CLK_SLEEP_ENABLE    __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE
#define __HAL_RCC_SDIO_CLK_SLEEP_DISABLE   __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE
#define __HAL_RCC_SDIO_CLK_ENABLE          __HAL_RCC_SDMMC1_CLK_ENABLE
#define __HAL_RCC_SDIO_CLK_DISABLE         __HAL_RCC_SDMMC1_CLK_DISABLE
#define __HAL_RCC_SDIO_IS_CLK_ENABLED      __HAL_RCC_SDMMC1_IS_CLK_ENABLED
#define __HAL_RCC_SDIO_IS_CLK_DISABLED     __HAL_RCC_SDMMC1_IS_CLK_DISABLED
#define SdioClockSelection                 Sdmmc1ClockSelection
#define RCC_PERIPHCLK_SDIO                 RCC_PERIPHCLK_SDMMC1
#define __HAL_RCC_SDIO_CONFIG              __HAL_RCC_SDMMC1_CONFIG
#define __HAL_RCC_GET_SDIO_SOURCE          __HAL_RCC_GET_SDMMC1_SOURCE
#endif

/* 针对STM32F7系列设备的SDIO时钟源宏定义 */
#if defined(STM32F7)
#define RCC_SDIOCLKSOURCE_CLK48             RCC_SDMMC1CLKSOURCE_CLK48
#define RCC_SDIOCLKSOURCE_SYSCLK           RCC_SDMMC1CLKSOURCE_SYSCLK
#endif

/* 针对STM32H7系列设备的USB OTG宏定义 */
/* 将通用的USB OTG HS(高速)宏映射到具体的USB1 OTG HS宏 */
#if defined(STM32H7)
#define __HAL_RCC_USB_OTG_HS_CLK_ENABLE()              __HAL_RCC_USB1_OTG_HS_CLK_ENABLE()
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE()         __HAL_RCC_USB1_OTG_HS_ULPI_CLK_ENABLE()
#define __HAL_RCC_USB_OTG_HS_CLK_DISABLE()             __HAL_RCC_USB1_OTG_HS_CLK_DISABLE()
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE()        __HAL_RCC_USB1_OTG_HS_ULPI_CLK_DISABLE()
#define __HAL_RCC_USB_OTG_HS_FORCE_RESET()             __HAL_RCC_USB1_OTG_HS_FORCE_RESET()
#define __HAL_RCC_USB_OTG_HS_RELEASE_RESET()           __HAL_RCC_USB1_OTG_HS_RELEASE_RESET()
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE()        __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_ENABLE()
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE()   __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_ENABLE()
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE()       __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_DISABLE()
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE()  __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_DISABLE()

/* 将通用的USB OTG FS(全速)宏映射到具体的USB2 OTG FS宏 */
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()             __HAL_RCC_USB2_OTG_FS_CLK_ENABLE()
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_ENABLE()        __HAL_RCC_USB2_OTG_FS_ULPI_CLK_ENABLE()
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()            __HAL_RCC_USB2_OTG_FS_CLK_DISABLE()
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_DISABLE()       __HAL_RCC_USB2_OTG_FS_ULPI_CLK_DISABLE()
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()            __HAL_RCC_USB2_OTG_FS_FORCE_RESET()
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()          __HAL_RCC_USB2_OTG_FS_RELEASE_RESET()
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()       __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_ENABLE()
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_ENABLE()
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE()      __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_DISABLE()
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_DISABLE() __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_DISABLE()
#endif

/* I2S(集成电路音频)时钟配置宏别名 */
#define __HAL_RCC_I2SCLK            __HAL_RCC_I2S_CONFIG
#define __HAL_RCC_I2SCLK_CONFIG     __HAL_RCC_I2S_CONFIG

/* 获取PLL(锁相环)时钟源的宏别名 */
#define __RCC_PLLSRC                RCC_GET_PLL_OSCSOURCE

/* 参数检查宏别名 */
/* 检查MSI(多速度内部振荡器)范围是否有效 */
#define IS_RCC_MSIRANGE             IS_RCC_MSI_CLOCK_RANGE
/* 检查RTC(实时时钟)时钟源是否有效 */
#define IS_RCC_RTCCLK_SOURCE        IS_RCC_RTCCLKSOURCE
/* 检查SYSCLK(系统时钟)分频系数是否有效 */
#define IS_RCC_SYSCLK_DIV           IS_RCC_HCLK
/* 检查HCLK(AHB总线时钟)分频系数是否有效 */
#define IS_RCC_HCLK_DIV             IS_RCC_PCLK
/* 检查外设时钟配置是否有效 */
#define IS_RCC_PERIPHCLK            IS_RCC_PERIPHCLOCK

/* RCC中断标志宏别名 */
/* HSI14就绪中断标志 */
#define RCC_IT_HSI14                RCC_IT_HSI14RDY

/* 时钟安全系统中断标志 */
#define RCC_IT_CSSLSE               RCC_IT_LSECSS
#define RCC_IT_CSSHSE               RCC_IT_CSS

/* PLL倍频系数宏定义 */
#define RCC_PLLMUL_3                RCC_PLL_MUL3
#define RCC_PLLMUL_4                RCC_PLL_MUL4
#define RCC_PLLMUL_6                RCC_PLL_MUL6
#define RCC_PLLMUL_8                RCC_PLL_MUL8
#define RCC_PLLMUL_12               RCC_PLL_MUL12
#define RCC_PLLMUL_16               RCC_PLL_MUL16
#define RCC_PLLMUL_24               RCC_PLL_MUL24
#define RCC_PLLMUL_32               RCC_PLL_MUL32
#define RCC_PLLMUL_48               RCC_PLL_MUL48

/* PLL分频系数宏定义 */
#define RCC_PLLDIV_2                RCC_PLL_DIV2
#define RCC_PLLDIV_3                RCC_PLL_DIV3
#define RCC_PLLDIV_4                RCC_PLL_DIV4

/* MCO(微控制器时钟输出)相关宏定义 */
/* 检查MCO时钟源是否有效 */
#define IS_RCC_MCOSOURCE            IS_RCC_MCO1SOURCE
/* 配置MCO时钟输出 */
#define __HAL_RCC_MCO_CONFIG        __HAL_RCC_MCO1_CONFIG

/* MCO输出分频系数定义 */
#define RCC_MCO_NODIV               RCC_MCODIV_1
#define RCC_MCO_DIV1                RCC_MCODIV_1
#define RCC_MCO_DIV2                RCC_MCODIV_2
#define RCC_MCO_DIV4                RCC_MCODIV_4
#define RCC_MCO_DIV8                RCC_MCODIV_8
#define RCC_MCO_DIV16               RCC_MCODIV_16
#define RCC_MCO_DIV32               RCC_MCODIV_32
#define RCC_MCO_DIV64               RCC_MCODIV_64
#define RCC_MCO_DIV128              RCC_MCODIV_128

/* MCO时钟源选择定义 */
#define RCC_MCOSOURCE_NONE          RCC_MCO1SOURCE_NOCLOCK
#define RCC_MCOSOURCE_LSI           RCC_MCO1SOURCE_LSI
#define RCC_MCOSOURCE_LSE           RCC_MCO1SOURCE_LSE
#define RCC_MCOSOURCE_SYSCLK        RCC_MCO1SOURCE_SYSCLK
#define RCC_MCOSOURCE_HSI           RCC_MCO1SOURCE_HSI
#define RCC_MCOSOURCE_HSI14         RCC_MCO1SOURCE_HSI14
#define RCC_MCOSOURCE_HSI48         RCC_MCO1SOURCE_HSI48
#define RCC_MCOSOURCE_HSE           RCC_MCO1SOURCE_HSE
#define RCC_MCOSOURCE_PLLCLK_DIV1   RCC_MCO1SOURCE_PLLCLK
#define RCC_MCOSOURCE_PLLCLK_NODIV  RCC_MCO1SOURCE_PLLCLK
#define RCC_MCOSOURCE_PLLCLK_DIV2   RCC_MCO1SOURCE_PLLCLK_DIV2

/* 针对STM32U0系列设备的系统时钟源状态宏定义 */
#if defined(STM32U0)
#define RCC_SYSCLKSOURCE_STATUS_PLLR   RCC_SYSCLKSOURCE_STATUS_PLLCLK
#endif

/* RTC时钟源无时钟的兼容性宏定义 */
#if defined(STM32L4) || defined(STM32WB) || defined(STM32G0) || defined(STM32G4) || defined(STM32L5) || \
    defined(STM32WL) || defined(STM32C0) || defined(STM32H7RS) || defined(STM32U0)
#define RCC_RTCCLKSOURCE_NO_CLK     RCC_RTCCLKSOURCE_NONE
#else
#define RCC_RTCCLKSOURCE_NONE       RCC_RTCCLKSOURCE_NO_CLK
#endif

/* USB时钟源选择宏定义 */
#define RCC_USBCLK_PLLSAI1          RCC_USBCLKSOURCE_PLLSAI1
#define RCC_USBCLK_PLL              RCC_USBCLKSOURCE_PLL
#define RCC_USBCLK_MSI              RCC_USBCLKSOURCE_MSI
#define RCC_USBCLKSOURCE_PLLCLK     RCC_USBCLKSOURCE_PLL

/* USB时钟分频系数宏定义 */
#define RCC_USBPLLCLK_DIV1          RCC_USBCLKSOURCE_PLL
#define RCC_USBPLLCLK_DIV1_5        RCC_USBCLKSOURCE_PLL_DIV1_5
#define RCC_USBPLLCLK_DIV2          RCC_USBCLKSOURCE_PLL_DIV2
#define RCC_USBPLLCLK_DIV3          RCC_USBCLKSOURCE_PLL_DIV3

/* RCC寄存器位序号宏定义，用于位带操作 */
/* HSI(高速内部振荡器)使能位序号 */
#define HSION_BitNumber        RCC_HSION_BIT_NUMBER
#define HSION_BITNUMBER        RCC_HSION_BIT_NUMBER
/* HSE(高速外部振荡器)使能位序号 */
#define HSEON_BitNumber        RCC_HSEON_BIT_NUMBER
#define HSEON_BITNUMBER        RCC_HSEON_BIT_NUMBER
/* MSI使能位序号 */
#define MSION_BITNUMBER        RCC_MSION_BIT_NUMBER
/* CSS(时钟安全系统)使能位序号 */
#define CSSON_BitNumber        RCC_CSSON_BIT_NUMBER
#define CSSON_BITNUMBER        RCC_CSSON_BIT_NUMBER
/* PLL使能位序号 */
#define PLLON_BitNumber        RCC_PLLON_BIT_NUMBER
#define PLLON_BITNUMBER        RCC_PLLON_BIT_NUMBER
/* PLLI2S使能位序号 */
#define PLLI2SON_BitNumber     RCC_PLLI2SON_BIT_NUMBER
/* I2S时钟源选择位序号 */
#define I2SSRC_BitNumber       RCC_I2SSRC_BIT_NUMBER
/* RTC使能位序号 */
#define RTCEN_BitNumber        RCC_RTCEN_BIT_NUMBER
#define RTCEN_BITNUMBER        RCC_RTCEN_BIT_NUMBER
/* 备份域复位位序号 */
#define BDRST_BitNumber        RCC_BDRST_BIT_NUMBER
#define BDRST_BITNUMBER        RCC_BDRST_BIT_NUMBER
/* RTC复位位序号 */
#define RTCRST_BITNUMBER       RCC_RTCRST_BIT_NUMBER
/* LSI(低速内部振荡器)使能位序号 */
#define LSION_BitNumber        RCC_LSION_BIT_NUMBER
#define LSION_BITNUMBER        RCC_LSION_BIT_NUMBER
/* LSE(低速外部振荡器)使能位序号 */
#define LSEON_BitNumber        RCC_LSEON_BIT_NUMBER
#define LSEON_BITNUMBER        RCC_LSEON_BIT_NUMBER
/* LSE旁路位序号 */
#define LSEBYP_BITNUMBER       RCC_LSEBYP_BIT_NUMBER
/* PLLSAI使能位序号 */
#define PLLSAION_BitNumber     RCC_PLLSAION_BIT_NUMBER
/* 定时器预分频位序号 */
#define TIMPRE_BitNumber       RCC_TIMPRE_BIT_NUMBER
/* 清除复位标志位序号 */
#define RMVF_BitNumber         RCC_RMVF_BIT_NUMBER
#define RMVF_BITNUMBER         RCC_RMVF_BIT_NUMBER
/* HSI14调整位序号 */
#define RCC_CR2_HSI14TRIM_BitNumber RCC_HSI14TRIM_BIT_NUMBER

/* RCC寄存器字节地址宏定义，用于字节操作 */
#define CR_BYTE2_ADDRESS       RCC_CR_BYTE2_ADDRESS
#define CIR_BYTE1_ADDRESS      RCC_CIR_BYTE1_ADDRESS
#define CIR_BYTE2_ADDRESS      RCC_CIR_BYTE2_ADDRESS
#define BDCR_BYTE0_ADDRESS     RCC_BDCR_BYTE0_ADDRESS

/* 超时值宏定义 */
/* 写保护解除超时值 */
#define DBP_TIMEOUT_VALUE      RCC_DBP_TIMEOUT_VALUE
/* LSE启动超时值 */
#define LSE_TIMEOUT_VALUE      RCC_LSE_TIMEOUT_VALUE

/* 位带别名地址宏定义 */
/* CR寄存器位带别名 */
#define CR_HSION_BB            RCC_CR_HSION_BB
#define CR_CSSON_BB            RCC_CR_CSSON_BB
#define CR_PLLON_BB            RCC_CR_PLLON_BB
#define CR_PLLI2SON_BB         RCC_CR_PLLI2SON_BB
#define CR_MSION_BB            RCC_CR_MSION_BB
/* CSR寄存器位带别名 */
#define CSR_LSION_BB           RCC_CSR_LSION_BB
#define CSR_LSEON_BB           RCC_CSR_LSEON_BB
#define CSR_LSEBYP_BB          RCC_CSR_LSEBYP_BB
#define CSR_RTCEN_BB           RCC_CSR_RTCEN_BB
#define CSR_RTCRST_BB          RCC_CSR_RTCRST_BB
/* CFGR寄存器位带别名 */
#define CFGR_I2SSRC_BB         RCC_CFGR_I2SSRC_BB
/* BDCR寄存器位带别名 */
#define BDCR_RTCEN_BB          RCC_BDCR_RTCEN_BB
#define BDCR_BDRST_BB          RCC_BDCR_BDRST_BB
/* CR寄存器HSEON位带别名 */
#define CR_HSEON_BB            RCC_CR_HSEON_BB
/* CSR寄存器清除复位标志位带别名 */
#define CSR_RMVF_BB            RCC_CSR_RMVF_BB
/* CR寄存器PLLSAION位带别名 */
#define CR_PLLSAION_BB         RCC_CR_PLLSAION_BB
/* DCKCFGR寄存器TIMPRE位带别名 */
#define DCKCFGR_TIMPRE_BB      RCC_DCKCFGR_TIMPRE_BB

/* CRS(时钟恢复系统)相关宏别名 */
#define __HAL_RCC_CRS_ENABLE_FREQ_ERROR_COUNTER     __HAL_RCC_CRS_FREQ_ERROR_COUNTER_ENABLE
#define __HAL_RCC_CRS_DISABLE_FREQ_ERROR_COUNTER    __HAL_RCC_CRS_FREQ_ERROR_COUNTER_DISABLE
#define __HAL_RCC_CRS_ENABLE_AUTOMATIC_CALIB        __HAL_RCC_CRS_AUTOMATIC_CALIB_ENABLE
#define __HAL_RCC_CRS_DISABLE_AUTOMATIC_CALIB       __HAL_RCC_CRS_AUTOMATIC_CALIB_DISABLE
#define __HAL_RCC_CRS_CALCULATE_RELOADVALUE         __HAL_RCC_CRS_RELOADVALUE_CALCULATE

/* 获取中断源的宏别名 */
#define __HAL_RCC_GET_IT_SOURCE                     __HAL_RCC_GET_IT

/* CRS状态标志宏别名 */
#define RCC_CRS_SYNCWARM       RCC_CRS_SYNCWARN
#define RCC_CRS_TRIMOV         RCC_CRS_TRIMOVF

/* CLK48(48MHz时钟)相关宏别名 */
#define RCC_PERIPHCLK_CK48               RCC_PERIPHCLK_CLK48
#define RCC_CK48CLKSOURCE_PLLQ           RCC_CLK48CLKSOURCE_PLLQ
#define RCC_CK48CLKSOURCE_PLLSAIP        RCC_CLK48CLKSOURCE_PLLSAIP
#define RCC_CK48CLKSOURCE_PLLI2SQ        RCC_CLK48CLKSOURCE_PLLI2SQ
#define IS_RCC_CK48CLKSOURCE             IS_RCC_CLK48CLKSOURCE
#define RCC_SDIOCLKSOURCE_CK48           RCC_SDIOCLKSOURCE_CLK48
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
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Macros HAL UART 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

// 宏定义：获取UART时钟源（旧版宏 __HAL_UART_GETCLOCKSOURCE 映射到新版 UART_GETCLOCKSOURCE）
#define __HAL_UART_GETCLOCKSOURCE       UART_GETCLOCKSOURCE
// 宏定义：计算UART掩码（旧版宏 __HAL_UART_MASK_COMPUTATION 映射到新版 UART_MASK_COMPUTATION）
#define __HAL_UART_MASK_COMPUTATION     UART_MASK_COMPUTATION
// 宏定义：获取UART时钟源（旧版命名方式，映射到新版 UART_GETCLOCKSOURCE）
#define __UART_GETCLOCKSOURCE           UART_GETCLOCKSOURCE
// 宏定义：计算UART掩码（旧版命名方式，映射到新版 UART_MASK_COMPUTATION）
#define __UART_MASK_COMPUTATION         UART_MASK_COMPUTATION

// 宏定义：检查UART唤醒方法是否有效（修正了旧版拼写错误 METHODE -> METHOD）
#define IS_UART_WAKEUPMETHODE           IS_UART_WAKEUPMETHOD

// 宏定义：检查是否为单比特采样模式（旧版宏 IS_UART_ONEBIT_SAMPLE 映射到新版 IS_UART_ONE_BIT_SAMPLE）
#define IS_UART_ONEBIT_SAMPLE           IS_UART_ONE_BIT_SAMPLE
// 宏定义：检查是否为单比特采样模式（旧版别名，映射到新版 IS_UART_ONE_BIT_SAMPLE）
#define IS_UART_ONEBIT_SAMPLING         IS_UART_ONE_BIT_SAMPLE

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Macros HAL USART 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

// 宏定义：使能USART中断（旧版宏映射到新版 __HAL_USART_ENABLE_IT）
#define __USART_ENABLE_IT               __HAL_USART_ENABLE_IT
// 宏定义：禁能USART中断（旧版宏映射到新版 __HAL_USART_DISABLE_IT）
#define __USART_DISABLE_IT              __HAL_USART_DISABLE_IT
// 宏定义：使能USART（旧版宏映射到新版 __HAL_USART_ENABLE）
#define __USART_ENABLE                  __HAL_USART_ENABLE
// 宏定义：禁能USART（旧版宏映射到新版 __HAL_USART_DISABLE）
#define __USART_DISABLE                 __HAL_USART_DISABLE

// 宏定义：获取USART时钟源（旧版宏映射到新版 USART_GETCLOCKSOURCE）
#define __HAL_USART_GETCLOCKSOURCE      USART_GETCLOCKSOURCE
// 宏定义：获取USART时钟源（旧版命名方式，映射到新版 USART_GETCLOCKSOURCE）
#define __USART_GETCLOCKSOURCE          USART_GETCLOCKSOURCE

// 条件编译：仅适用于 STM32F0, STM32F3, STM32F7 系列芯片
#if defined(STM32F0) || defined(STM32F3) || defined(STM32F7)
// 宏定义：USART 16倍过采样模式（值为0，即不设置OVER8位）
#define USART_OVERSAMPLING_16               0x00000000U
// 宏定义：USART 8倍过采样模式（值为 USART_CR1_OVER8 寄存器位）
#define USART_OVERSAMPLING_8                USART_CR1_OVER8

// 宏定义：检查USART过采样参数是否有效（必须是16倍或8倍过采样之一）
#define IS_USART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == USART_OVERSAMPLING_16) || \
                                             ((__SAMPLING__) == USART_OVERSAMPLING_8))
#endif /* STM32F0 || STM32F3 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_USB_Aliased_Macros HAL USB 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：USB唤醒外部中断线（旧版宏映射到新版 USB_WAKEUP_EXTI_LINE）
#define USB_EXTI_LINE_WAKEUP                               USB_WAKEUP_EXTI_LINE

// 宏定义：USB全速外部中断上升沿触发（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE）
#define USB_FS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE
// 宏定义：USB全速外部中断下降沿触发（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE）
#define USB_FS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE
// 宏定义：USB全速外部中断双边沿触发（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE）
#define USB_FS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE
// 宏定义：USB全速唤醒外部中断线（旧版宏映射到新版 USB_OTG_FS_WAKEUP_EXTI_LINE）
#define USB_FS_EXTI_LINE_WAKEUP                            USB_OTG_FS_WAKEUP_EXTI_LINE

// 宏定义：USB高速外部中断上升沿触发（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE）
#define USB_HS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE
// 宏定义：USB高速外部中断下降沿触发（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE）
#define USB_HS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE
// 宏定义：USB高速外部中断双边沿触发（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE）
#define USB_HS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE
// 宏定义：USB高速唤醒外部中断线（旧版宏映射到新版 USB_OTG_HS_WAKEUP_EXTI_LINE）
#define USB_HS_EXTI_LINE_WAKEUP                            USB_OTG_HS_WAKEUP_EXTI_LINE

// 宏定义：使能USB唤醒外部中断（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_USB_EXTI_ENABLE_IT                           __HAL_USB_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能USB唤醒外部中断（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_USB_EXTI_DISABLE_IT                          __HAL_USB_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取USB唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_GET_FLAG）
#define __HAL_USB_EXTI_GET_FLAG                            __HAL_USB_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除USB唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_USB_EXTI_CLEAR_FLAG                          __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置USB唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE）
#define __HAL_USB_EXTI_SET_RISING_EDGE_TRIGGER             __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 宏定义：设置USB唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE）
#define __HAL_USB_EXTI_SET_FALLING_EDGE_TRIGGER            __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 宏定义：设置USB唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE）
#define __HAL_USB_EXTI_SET_FALLINGRISING_TRIGGER           __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE

// 宏定义：使能USB OTG全速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_USB_FS_EXTI_ENABLE_IT                        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能USB OTG全速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_USB_FS_EXTI_DISABLE_IT                       __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取USB OTG全速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG）
#define __HAL_USB_FS_EXTI_GET_FLAG                         __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除USB OTG全速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_USB_FS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置USB OTG全速唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE）
#define __HAL_USB_FS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 宏定义：设置USB OTG全速唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE）
#define __HAL_USB_FS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 宏定义：设置USB OTG全速唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE）
#define __HAL_USB_FS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
// 宏定义：USB OTG全速唤醒外部中断软件中断触发（旧版宏映射到新版 __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT）
#define __HAL_USB_FS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT

// 宏定义：使能USB OTG高速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_USB_HS_EXTI_ENABLE_IT                        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能USB OTG高速唤醒外部中断（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_USB_HS_EXTI_DISABLE_IT                       __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取USB OTG高速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG）
#define __HAL_USB_HS_EXTI_GET_FLAG                         __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除USB OTG高速唤醒外部中断标志（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_USB_HS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置USB OTG高速唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE）
#define __HAL_USB_HS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE
// 宏定义：设置USB OTG高速唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE）
#define __HAL_USB_HS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE
// 宏定义：设置USB OTG高速唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE）
#define __HAL_USB_HS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE
// 宏定义：USB OTG高速唤醒外部中断软件中断触发（旧版宏映射到新版 __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT）
#define __HAL_USB_HS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT

// 宏定义：激活PCD远程唤醒（旧版宏 Active 映射到新版 Activate）
#define HAL_PCD_ActiveRemoteWakeup                         HAL_PCD_ActivateRemoteWakeup
// 宏定义：去激活PCD远程唤醒（旧版宏 DeActive 映射到新版 DeActivate）
#define HAL_PCD_DeActiveRemoteWakeup                       HAL_PCD_DeActivateRemoteWakeup

// 宏定义：设置PCD发送FIFO（旧版宏映射到扩展功能 HAL_PCDEx_SetTxFiFo）
#define HAL_PCD_SetTxFiFo                                  HAL_PCDEx_SetTxFiFo
// 宏定义：设置PCD接收FIFO（旧版宏映射到扩展功能 HAL_PCDEx_SetRxFiFo）
#define HAL_PCD_SetRxFiFo                                  HAL_PCDEx_SetRxFiFo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：设置定时器输入捕获预分频值（旧版宏映射到新版 TIM_SET_ICPRESCALERVALUE）
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE
// 宏定义：重置定时器输入捕获预分频值（旧版宏映射到新版 TIM_RESET_ICPRESCALERVALUE）
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE

// 宏定义：获取定时器中断状态（旧版宏映射到新版 __HAL_TIM_GET_IT_SOURCE）
#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE
// 宏定义：清除定时器中断标志（旧版宏映射到新版 __HAL_TIM_CLEAR_IT）
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT

// 宏定义：获取定时器中断状态（旧版宏映射到新版 __HAL_TIM_GET_IT_SOURCE）
#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE

// 宏定义：获取定时器计数方向状态（旧版宏映射到新版 __HAL_TIM_IS_TIM_COUNTING_DOWN）
#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN
// 宏定义：设置定时器预分频值（旧版宏映射到新版 __HAL_TIM_SET_PRESCALER）
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER
// 宏定义：设置定时器计数器值（旧版宏映射到新版 __HAL_TIM_SET_COUNTER）
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER
// 宏定义：获取定时器计数器值（旧版宏映射到新版 __HAL_TIM_GET_COUNTER）
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER
// 宏定义：设置定时器自动重装载值（旧版宏映射到新版 __HAL_TIM_SET_AUTORELOAD）
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD
// 宏定义：获取定时器自动重装载值（旧版宏映射到新版 __HAL_TIM_GET_AUTORELOAD）
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD
// 宏定义：设置定时器时钟分频（旧版宏映射到新版 __HAL_TIM_SET_CLOCKDIVISION）
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION
// 宏定义：获取定时器时钟分频（旧版宏映射到新版 __HAL_TIM_GET_CLOCKDIVISION）
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION
// 宏定义：设置定时器输入捕获预分频（旧版宏映射到新版 __HAL_TIM_SET_ICPRESCALER）
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER
// 宏定义：获取定时器输入捕获预分频（旧版宏映射到新版 __HAL_TIM_GET_ICPRESCALER）
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER
// 宏定义：设置定时器比较值（旧版宏映射到新版 __HAL_TIM_SET_COMPARE）
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE
// 宏定义：获取定时器比较值（旧版宏映射到新版 __HAL_TIM_GET_COMPARE）
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE

// 宏定义：定时器断路输入源 DFSDM（旧版宏映射到新版 TIM_BREAKINPUTSOURCE_DFSDM1）
#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1

// 宏定义：非对称PWM模式1（修正拼写错误 ASSYMETRIC -> ASYMMETRIC）
#define TIM_OCMODE_ASSYMETRIC_PWM1      TIM_OCMODE_ASYMMETRIC_PWM1
// 宏定义：非对称PWM模式2（修正拼写错误 ASSYMETRIC -> ASYMMETRIC）
#define TIM_OCMODE_ASSYMETRIC_PWM2      TIM_OCMODE_ASYMMETRIC_PWM2
/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Macros HAL ETH 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

// 宏定义：使能以太网唤醒外部中断（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_IT）
#define __HAL_ETH_EXTI_ENABLE_IT                   __HAL_ETH_WAKEUP_EXTI_ENABLE_IT
// 宏定义：禁能以太网唤醒外部中断（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_DISABLE_IT）
#define __HAL_ETH_EXTI_DISABLE_IT                  __HAL_ETH_WAKEUP_EXTI_DISABLE_IT
// 宏定义：获取以太网唤醒外部中断标志（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_GET_FLAG）
#define __HAL_ETH_EXTI_GET_FLAG                    __HAL_ETH_WAKEUP_EXTI_GET_FLAG
// 宏定义：清除以太网唤醒外部中断标志（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG）
#define __HAL_ETH_EXTI_CLEAR_FLAG                  __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG
// 宏定义：设置以太网唤醒外部中断为上升沿触发（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER）
#define __HAL_ETH_EXTI_SET_RISING_EGDE_TRIGGER     __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER
// 宏定义：设置以太网唤醒外部中断为下降沿触发（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER）
#define __HAL_ETH_EXTI_SET_FALLING_EGDE_TRIGGER    __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER
// 宏定义：设置以太网唤醒外部中断为双边沿触发（旧版宏映射到新版 __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER）
#define __HAL_ETH_EXTI_SET_FALLINGRISING_TRIGGER   __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER

// 宏定义：使能以太网混杂模式（修正拼写错误 PROMISCIOUS -> PROMISCUOUS）
#define ETH_PROMISCIOUSMODE_ENABLE   ETH_PROMISCUOUS_MODE_ENABLE
// 宏定义：禁能以太网混杂模式（修正拼写错误 PROMISCIOUS -> PROMISCUOUS）
#define ETH_PROMISCIOUSMODE_DISABLE  ETH_PROMISCUOUS_MODE_DISABLE
// 宏定义：检查是否为以太网混杂模式（修正拼写错误 PROMISCIOUS -> PROMISCUOUS）
#define IS_ETH_PROMISCIOUS_MODE      IS_ETH_PROMISCUOUS_MODE
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Macros HAL LTDC 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：获取LTDC层（旧版宏映射到新版 LTDC_LAYER）
#define __HAL_LTDC_LAYER LTDC_LAYER
// 宏定义：立即重载LTDC配置（旧版宏映射到新版 __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG）
#define __HAL_LTDC_RELOAD_CONFIG  __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG
/**
  * @}
  */

/** @defgroup HAL_SAI_Aliased_Macros HAL SAI 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 宏定义：SAI输出驱动禁能（旧版宏 DISABLED 映射到新版 DISABLE）
#define SAI_OUTPUTDRIVE_DISABLED          SAI_OUTPUTDRIVE_DISABLE
// 宏定义：SAI输出驱动使能（旧版宏 ENABLED 映射到新版 ENABLE）
#define SAI_OUTPUTDRIVE_ENABLED           SAI_OUTPUTDRIVE_ENABLE
// 宏定义：SAI主分频器使能（旧版宏 ENABLED 映射到新版 ENABLE）
#define SAI_MASTERDIVIDER_ENABLED         SAI_MASTERDIVIDER_ENABLE
// 宏定义：SAI主分频器禁能（旧版宏 DISABLED 映射到新版 DISABLE）
#define SAI_MASTERDIVIDER_DISABLED        SAI_MASTERDIVIDER_DISABLE
// 宏定义：SAI立体声模式（修正拼写错误 STREOMODE -> STEREOMODE）
#define SAI_STREOMODE                     SAI_STEREOMODE
// 宏定义：SAI FIFO状态为空（修正大小写命名风格）
#define SAI_FIFOStatus_Empty              SAI_FIFOSTATUS_EMPTY
// 宏定义：SAI FIFO状态少于1/4满（修正大小写命名风格）
#define SAI_FIFOStatus_Less1QuarterFull   SAI_FIFOSTATUS_LESS1QUARTERFULL
// 宏定义：SAI FIFO状态1/4满（修正大小写命名风格）
#define SAI_FIFOStatus_1QuarterFull       SAI_FIFOSTATUS_1QUARTERFULL
// 宏定义：SAI FIFO状态半满（修正大小写命名风格）
#define SAI_FIFOStatus_HalfFull           SAI_FIFOSTATUS_HALFFULL
// 宏定义：SAI FIFO状态3/4满（修正大小写命名风格）
#define SAI_FIFOStatus_3QuartersFull      SAI_FIFOSTATUS_3QUARTERFULL
// 宏定义：SAI FIFO状态满（修正大小写命名风格）
#define SAI_FIFOStatus_Full               SAI_FIFOSTATUS_FULL
// 宏定义：检查SAI块单声道/立体声模式（修正拼写错误 STREO -> STEREO）
#define IS_SAI_BLOCK_MONO_STREO_MODE      IS_SAI_BLOCK_MONO_STEREO_MODE
// 宏定义：SAI同步模式：外部同步（映射到具体的SAI1外部同步）
#define SAI_SYNCHRONOUS_EXT               SAI_SYNCHRONOUS_EXT_SAI1
// 宏定义：SAI外部同步输入使能（映射到输出块A使能）
#define SAI_SYNCEXT_IN_ENABLE             SAI_SYNCEXT_OUTBLOCKA_ENABLE
/**
  * @}
  */

/** @defgroup HAL_SPDIFRX_Aliased_Macros HAL SPDIFRX 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32H7 系列芯片
#if defined(STM32H7)
// 宏定义：SPDIFRX接收控制流（旧版函数名 ControlFlow 映射到新版 CtrlFlow）
#define HAL_SPDIFRX_ReceiveControlFlow      HAL_SPDIFRX_ReceiveCtrlFlow
// 宏定义：SPDIFRX中断模式接收控制流（旧版函数名 ControlFlow 映射到新版 CtrlFlow）
#define HAL_SPDIFRX_ReceiveControlFlow_IT   HAL_SPDIFRX_ReceiveCtrlFlow_IT
// 宏定义：SPDIFRX DMA模式接收控制流（旧版函数名 ControlFlow 映射到新版 CtrlFlow）
#define HAL_SPDIFRX_ReceiveControlFlow_DMA  HAL_SPDIFRX_ReceiveCtrlFlow_DMA
#endif
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Functions HAL HRTIM 旧版别名函数（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32H7, STM32G4, STM32F3 系列芯片
#if defined (STM32H7) || defined (STM32G4) || defined (STM32F3)
// 宏定义：HRTIM波形计数器中断启动（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStart_IT      HAL_HRTIM_WaveformCountStart_IT
// 宏定义：HRTIM波形计数器DMA启动（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStart_DMA     HAL_HRTIM_WaveformCountStart_DMA
// 宏定义：HRTIM波形计数器启动（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStart         HAL_HRTIM_WaveformCountStart
// 宏定义：HRTIM波形计数器中断停止（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStop_IT       HAL_HRTIM_WaveformCountStop_IT
// 宏定义：HRTIM波形计数器DMA停止（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStop_DMA      HAL_HRTIM_WaveformCountStop_DMA
// 宏定义：HRTIM波形计数器停止（修正函数名 Counter -> Count）
#define HAL_HRTIM_WaveformCounterStop          HAL_HRTIM_WaveformCountStop
#endif
/**
  * @}
  */

/** @defgroup HAL_QSPI_Aliased_Macros HAL QSPI 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32L4, STM32F4, STM32F7, STM32H7 系列芯片
#if defined (STM32L4) || defined (STM32F4) || defined (STM32F7) || defined(STM32H7)
// 宏定义：QSPI默认超时值（修正拼写错误 QPSI -> QSPI）
#define HAL_QPSI_TIMEOUT_DEFAULT_VALUE HAL_QSPI_TIMEOUT_DEFAULT_VALUE
#endif /* STM32L4 || STM32F4 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_Generic_Aliased_Macros HAL 通用旧版别名宏（用于保持旧代码兼容性）
  * @{
  */
// 条件编译：仅适用于 STM32F7 系列芯片
#if defined (STM32F7)
// 宏定义：ART加速器使能（修正拼写错误 ACCLERATOR -> ACCELERATOR）
#define ART_ACCLERATOR_ENABLE ART_ACCELERATOR_ENABLE
#endif /* STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_PPP_Aliased_Macros HAL PPP 旧版别名宏（用于保持旧代码兼容性）
  * @{
  */

/**
  * @}
  */

// 结束 C++ extern "C" 块
#ifdef __cplusplus
}
#endif

// 结束 STM32_HAL_LEGACY 宏定义保护
#endif /* STM32_HAL_LEGACY */

