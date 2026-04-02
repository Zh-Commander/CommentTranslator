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
