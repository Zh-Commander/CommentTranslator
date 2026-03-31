/**
  ******************************************************************************
  * @file    stm32_hal_legacy.h
  * @author  MCD Application Team
  * @brief   该文件包含了为STM32Cube HAL常量、宏和函数定义的别名，用于向后兼容遗留代码。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2021 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据可在本软件组件根目录的LICENSE文件中找到的条款获得许可。
  * 如果未随本软件提供LICENSE文件，则按"原样"提供。
  *
  ******************************************************************************
  */

/* 防止递归包含的定义 -------------------------------------*/
#ifndef STM32_HAL_LEGACY
#define STM32_HAL_LEGACY

#ifdef __cplusplus
extern "C" {
#endif

/* 包含头文件 ------------------------------------------------------------------*/
/* 导出类型 ------------------------------------------------------------*/
/* 导出常量 --------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Defines 为遗留目的维护的HAL CRYP别名定义
  * @{
  */
#define AES_FLAG_RDERR                  CRYP_FLAG_RDERR   /* AES读取错误标志的别名，对应CRYP模块的标志 */
#define AES_FLAG_WRERR                  CRYP_FLAG_WRERR   /* AES写入错误标志的别名，对应CRYP模块的标志 */
#define AES_CLEARFLAG_CCF               CRYP_CLEARFLAG_CCF /* AES清除计算完成标志的别名，对应CRYP模块的标志 */
#define AES_CLEARFLAG_RDERR             CRYP_CLEARFLAG_RDERR /* AES清除读取错误标志的别名，对应CRYP模块的标志 */
#define AES_CLEARFLAG_WRERR             CRYP_CLEARFLAG_WRERR /* AES清除写入错误标志的别名，对应CRYP模块的标志 */
#if defined(STM32H7) || defined(STM32MP1)
#define CRYP_DATATYPE_32B               CRYP_NO_SWAP      /* 32位数据类型的别名，对应无交换模式 */
#define CRYP_DATATYPE_16B               CRYP_HALFWORD_SWAP /* 16位数据类型的别名，对应半字交换模式 */
#define CRYP_DATATYPE_8B                CRYP_BYTE_SWAP    /* 8位数据类型的别名，对应字节交换模式 */
#define CRYP_DATATYPE_1B                CRYP_BIT_SWAP     /* 1位数据类型的别名，对应位交换模式 */
#endif /* STM32H7 || STM32MP1 */
/**
  * @}
  */

/** @defgroup HAL_ADC_Aliased_Defines 为遗留目的维护的HAL ADC别名定义
  * @{
  */
#define ADC_RESOLUTION12b               ADC_RESOLUTION_12B /* 12位ADC分辨率的别名 */
#define ADC_RESOLUTION10b               ADC_RESOLUTION_10B /* 10位ADC分辨率的别名 */
#define ADC_RESOLUTION8b                ADC_RESOLUTION_8B  /* 8位ADC分辨率的别名 */
#define ADC_RESOLUTION6b                ADC_RESOLUTION_6B  /* 6位ADC分辨率的别名 */
#define OVR_DATA_OVERWRITTEN            ADC_OVR_DATA_OVERWRITTEN /* 溢出数据被覆盖的别名 */
#define OVR_DATA_PRESERVED              ADC_OVR_DATA_PRESERVED /* 溢出数据被保留的别名 */
#define EOC_SINGLE_CONV                 ADC_EOC_SINGLE_CONV /* 单次转换结束标志的别名 */
#define EOC_SEQ_CONV                    ADC_EOC_SEQ_CONV    /* 序列转换结束标志的别名 */
#define EOC_SINGLE_SEQ_CONV             ADC_EOC_SINGLE_SEQ_CONV /* 单次或序列转换结束标志的别名 */
#define REGULAR_GROUP                   ADC_REGULAR_GROUP   /* 规则转换组的别名 */
#define INJECTED_GROUP                  ADC_INJECTED_GROUP  /* 注入转换组的别名 */
#define REGULAR_INJECTED_GROUP          ADC_REGULAR_INJECTED_GROUP /* 规则和注入转换组的别名 */
#define AWD_EVENT                       ADC_AWD_EVENT      /* 模拟看门狗事件的别名 */
#define AWD1_EVENT                      ADC_AWD1_EVENT     /* 模拟看门狗1事件的别名 */
#define AWD2_EVENT                      ADC_AWD2_EVENT     /* 模拟看门狗2事件的别名 */
#define AWD3_EVENT                      ADC_AWD3_EVENT     /* 模拟看门狗3事件的别名 */
#define OVR_EVENT                       ADC_OVR_EVENT      /* 溢出事件的别名 */
#define JQOVF_EVENT                     ADC_JQOVF_EVENT    /* 注入队列溢出事件的别名 */
#define ALL_CHANNELS                    ADC_ALL_CHANNELS   /* 所有通道的别名 */
#define REGULAR_CHANNELS                ADC_REGULAR_CHANNELS /* 规则通道的别名 */
#define INJECTED_CHANNELS               ADC_INJECTED_CHANNELS /* 注入通道的别名 */
#define SYSCFG_FLAG_SENSOR_ADC          ADC_FLAG_SENSOR    /* 传感器ADC标志的别名 */
#define SYSCFG_FLAG_VREF_ADC            ADC_FLAG_VREFINT   /* 内部参考电压ADC标志的别名 */
#define ADC_CLOCKPRESCALER_PCLK_DIV1    ADC_CLOCK_SYNC_PCLK_DIV1 /* ADC时钟预分频器：PCLK除以1的别名 */
#define ADC_CLOCKPRESCALER_PCLK_DIV2    ADC_CLOCK_SYNC_PCLK_DIV2 /* ADC时钟预分频器：PCLK除以2的别名 */
#define ADC_CLOCKPRESCALER_PCLK_DIV4    ADC_CLOCK_SYNC_PCLK_DIV4 /* ADC时钟预分频器：PCLK除以4的别名 */
#define ADC_CLOCKPRESCALER_PCLK_DIV6    ADC_CLOCK_SYNC_PCLK_DIV6 /* ADC时钟预分频器：PCLK除以6的别名 */
#define ADC_CLOCKPRESCALER_PCLK_DIV8    ADC_CLOCK_SYNC_PCLK_DIV8 /* ADC时钟预分频器：PCLK除以8的别名 */
#define ADC_EXTERNALTRIG0_T6_TRGO       ADC_EXTERNALTRIGCONV_T6_TRGO /* 外部触发0：TIM6_TRGO的别名 */
#define ADC_EXTERNALTRIG1_T21_CC2       ADC_EXTERNALTRIGCONV_T21_CC2 /* 外部触发1：TIM21_CC2的别名 */
#define ADC_EXTERNALTRIG2_T2_TRGO       ADC_EXTERNALTRIGCONV_T2_TRGO /* 外部触发2：TIM2_TRGO的别名 */
#define ADC_EXTERNALTRIG3_T2_CC4        ADC_EXTERNALTRIGCONV_T2_CC4 /* 外部触发3：TIM2_CC4的别名 */
#define ADC_EXTERNALTRIG4_T22_TRGO      ADC_EXTERNALTRIGCONV_T22_TRGO /* 外部触发4：TIM22_TRGO的别名 */
#define ADC_EXTERNALTRIG7_EXT_IT11      ADC_EXTERNALTRIGCONV_EXT_IT11 /* 外部触发7：外部中断11的别名 */
#define ADC_CLOCK_ASYNC                 ADC_CLOCK_ASYNC_DIV1 /* 异步ADC时钟的别名 */
#define ADC_EXTERNALTRIG_EDGE_NONE      ADC_EXTERNALTRIGCONVEDGE_NONE /* 外部触发边沿：无的别名 */
#define ADC_EXTERNALTRIG_EDGE_RISING    ADC_EXTERNALTRIGCONVEDGE_RISING /* 外部触发边沿：上升沿的别名 */
#define ADC_EXTERNALTRIG_EDGE_FALLING   ADC_EXTERNALTRIGCONVEDGE_FALLING /* 外部触发边沿：下降沿的别名 */
#define ADC_EXTERNALTRIG_EDGE_RISINGFALLING ADC_EXTERNALTRIGCONVEDGE_RISINGFALLING /* 外部触发边沿：上升沿和下降沿的别名 */
#define ADC_SAMPLETIME_2CYCLE_5         ADC_SAMPLETIME_2CYCLES_5 /* 采样时间：2.5个周期的别名 */

#define HAL_ADC_STATE_BUSY_REG          HAL_ADC_STATE_REG_BUSY /* ADC状态：规则转换忙的别名 */
#define HAL_ADC_STATE_BUSY_INJ          HAL_ADC_STATE_INJ_BUSY /* ADC状态：注入转换忙的别名 */
#define HAL_ADC_STATE_EOC_REG           HAL_ADC_STATE_REG_EOC /* ADC状态：规则转换结束的别名 */
#define HAL_ADC_STATE_EOC_INJ           HAL_ADC_STATE_INJ_EOC /* ADC状态：注入转换结束的别名 */
#define HAL_ADC_STATE_ERROR             HAL_ADC_STATE_ERROR_INTERNAL /* ADC状态：错误的别名 */
#define HAL_ADC_STATE_BUSY              HAL_ADC_STATE_BUSY_INTERNAL /* ADC状态：忙的别名 */
#define HAL_ADC_STATE_AWD               HAL_ADC_STATE_AWD1    /* ADC状态：模拟看门狗的别名 */

#if defined(STM32H7)
#define ADC_CHANNEL_VBAT_DIV4           ADC_CHANNEL_VBAT    /* VBAT除以4通道的别名，对应STM32H7 */
#endif /* STM32H7 */

#if defined(STM32U5)
#define ADC_SAMPLETIME_5CYCLE           ADC_SAMPLETIME_5CYCLES /* 采样时间：5个周期的别名，对应STM32U5 */
#define ADC_SAMPLETIME_391CYCLES_5      ADC_SAMPLETIME_391CYCLES /* 采样时间：391.5个周期的别名，对应STM32U5 */
#define ADC4_SAMPLETIME_160CYCLES_5     ADC4_SAMPLETIME_814CYCLES_5 /* ADC4采样时间：160.5个周期的别名，对应STM32U5 */
#endif /* STM32U5 */

#if defined(STM32H5)
#define ADC_CHANNEL_VCORE               ADC_CHANNEL_VDDCORE /* 核心电压通道的别名，对应STM32H5 */
#endif /* STM32H5 */
/**
  * @}
  */

/** @defgroup HAL_CEC_Aliased_Defines 为遗留目的维护的HAL CEC别名定义
  * @{
  */

#define __HAL_CEC_GET_IT __HAL_CEC_GET_FLAG /* 获取CEC中断标志的宏别名 */

/**
  * @}
  */

/** @defgroup HAL_COMP_Aliased_Defines 为遗留目的维护的HAL COMP别名定义
  * @{
  */
#define COMP_WINDOWMODE_DISABLED       COMP_WINDOWMODE_DISABLE /* 窗口模式禁用的别名 */
#define COMP_WINDOWMODE_ENABLED        COMP_WINDOWMODE_ENABLE  /* 窗口模式启用的别名 */
#define COMP_EXTI_LINE_COMP1_EVENT     COMP_EXTI_LINE_COMP1    /* COMP1外部中断线的别名 */
#define COMP_EXTI_LINE_COMP2_EVENT     COMP_EXTI_LINE_COMP2    /* COMP2外部中断线的别名 */
#define COMP_EXTI_LINE_COMP3_EVENT     COMP_EXTI_LINE_COMP3    /* COMP3外部中断线的别名 */
#define COMP_EXTI_LINE_COMP4_EVENT     COMP_EXTI_LINE_COMP4    /* COMP4外部中断线的别名 */
#define COMP_EXTI_LINE_COMP5_EVENT     COMP_EXTI_LINE_COMP5    /* COMP5外部中断线的别名 */
#define COMP_EXTI_LINE_COMP6_EVENT     COMP_EXTI_LINE_COMP6    /* COMP6外部中断线的别名 */
#define COMP_EXTI_LINE_COMP7_EVENT     COMP_EXTI_LINE_COMP7    /* COMP7外部中断线的别名 */
#if defined(STM32L0)
#define COMP_LPTIMCONNECTION_ENABLED   ((uint32_t)0x00000003U)    /*!< COMPX输出通用命名：COMP1连接到LPTIM输入1，COMP2连接到LPTIM输入2 */
#endif
#define COMP_OUTPUT_COMP6TIM2OCREFCLR  COMP_OUTPUT_COMP6_TIM2OCREFCLR /* COMP6输出到TIM2 OCREF清除的别名 */
#if defined(STM32F373xC) || defined(STM32F378xx)
#define COMP_OUTPUT_TIM3IC1            COMP_OUTPUT_COMP1_TIM3IC1 /* COMP1输出到TIM3输入捕获1的别名 */
#define COMP_OUTPUT_TIM3OCREFCLR       COMP_OUTPUT_COMP1_TIM3OCREFCLR /* COMP1输出到TIM3 OCREF清除的别名 */
#endif /* STM32F373xC || STM32F378xx */

#if defined(STM32L0) || defined(STM32L4)
#define COMP_WINDOWMODE_ENABLE         COMP_WINDOWMODE_COMP1_INPUT_PLUS_COMMON /* 窗口模式启用：COMP1正输入作为公共端的别名 */

#define COMP_NONINVERTINGINPUT_IO1      COMP_INPUT_PLUS_IO1 /* 非反相输入IO1的别名 */
#define COMP_NONINVERTINGINPUT_IO2      COMP_INPUT_PLUS_IO2 /* 非反相输入IO2的别名 */
#define COMP_NONINVERTINGINPUT_IO3      COMP_INPUT_PLUS_IO3 /* 非反相输入IO3的别名 */
#define COMP_NONINVERTINGINPUT_IO4      COMP_INPUT_PLUS_IO4 /* 非反相输入IO4的别名 */
#define COMP_NONINVERTINGINPUT_IO5      COMP_INPUT_PLUS_IO5 /* 非反相输入IO5的别名 */
#define COMP_NONINVERTINGINPUT_IO6      COMP_INPUT_PLUS_IO6 /* 非反相输入IO6的别名 */

#define COMP_INVERTINGINPUT_1_4VREFINT  COMP_INPUT_MINUS_1_4VREFINT /* 反相输入1/4 VREFINT的别名 */
#define COMP_INVERTINGINPUT_1_2VREFINT  COMP_INPUT_MINUS_1_2VREFINT /* 反相输入1/2 VREFINT的别名 */
#define COMP_INVERTINGINPUT_3_4VREFINT  COMP_INPUT_MINUS_3_4VREFINT /* 反相输入3/4 VREFINT的别名 */
#define COMP_INVERTINGINPUT_VREFINT     COMP_INPUT_MINUS_VREFINT   /* 反相输入VREFINT的别名 */
#define COMP_INVERTINGINPUT_DAC1_CH1    COMP_INPUT_MINUS_DAC1_CH1  /* 反相输入DAC1通道1的别名 */
#define COMP_INVERTINGINPUT_DAC1_CH2    COMP_INPUT_MINUS_DAC1_CH2  /* 反相输入DAC1通道2的别名 */
#define COMP_INVERTINGINPUT_DAC1        COMP_INPUT_MINUS_DAC1_CH1  /* 反相输入DAC1的别名 */
#define COMP_INVERTINGINPUT_DAC2        COMP_INPUT_MINUS_DAC1_CH2  /* 反相输入DAC2的别名 */
#define COMP_INVERTINGINPUT_IO1         COMP_INPUT_MINUS_IO1       /* 反相输入IO1的别名 */
#if defined(STM32L0)
/* STM32L0 COMP驱动问题修复：只有2个专用IO（IO1和IO2），IO2被错误地分配为与DAC共享的IO，而IO3对应第二个专用IO（仅用于COMP2）。 */
#define COMP_INVERTINGINPUT_IO2         COMP_INPUT_MINUS_DAC1_CH2  /* 反相输入IO2的别名，对应STM32L0 */
#define COMP_INVERTINGINPUT_IO3         COMP_INPUT_MINUS_IO2       /* 反相输入IO3的别名，对应STM32L0 */
#else
#define COMP_INVERTINGINPUT_IO2         COMP_INPUT_MINUS_IO2       /* 反相输入IO2的别名 */
#define COMP_INVERTINGINPUT_IO3         COMP_INPUT_MINUS_IO3       /* 反相输入IO3的别名 */
#endif
#define COMP_INVERTINGINPUT_IO4         COMP_INPUT_MINUS_IO4       /* 反相输入IO4的别名 */
#define COMP_INVERTINGINPUT_IO5         COMP_INPUT_MINUS_IO5       /* 反相输入IO5的别名 */

#define COMP_OUTPUTLEVEL_LOW            COMP_OUTPUT_LEVEL_LOW      /* 输出低电平的别名 */
#define COMP_OUTPUTLEVEL_HIGH           COMP_OUTPUT_LEVEL_HIGH     /* 输出高电平的别名 */

/* 注意：保留字面量"COMP_FLAG_LOCK"用于遗留目的。 */
/*       要检查COMP锁定状态，请使用宏"__HAL_COMP_IS_LOCKED()"。 */
#if defined(COMP_CSR_LOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_LOCK               /* COMP锁定标志的别名 */
#elif defined(COMP_CSR_COMP1LOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_COMP1LOCK          /* COMP1锁定标志的别名 */
#elif defined(COMP_CSR_COMPxLOCK)
#define COMP_FLAG_LOCK                 COMP_CSR_COMPxLOCK          /* COMPx锁定标志的别名 */
#endif

#if defined(STM32L4)
#define COMP_BLANKINGSRCE_TIM1OC5        COMP_BLANKINGSRC_TIM1_OC5_COMP1 /* 消隐源：TIM1 OC5对应COMP1的别名 */
#define COMP_BLANKINGSRCE_TIM2OC3        COMP_BLANKINGSRC_TIM2_OC3_COMP1 /* 消隐源：TIM2 OC3对应COMP1的别名 */
#define COMP_BLANKINGSRCE_TIM3OC3        COMP_BLANKINGSRC_TIM3_OC3_COMP1 /* 消隐源：TIM3 OC3对应COMP1的别名 */
#define COMP_BLANKINGSRCE_TIM3OC4        COMP_BLANKINGSRC_TIM3_OC4_COMP2 /* 消隐源：TIM3 OC4对应COMP2的别名 */
#define COMP_BLANKINGSRCE_TIM8OC5        COMP_BLANKINGSRC_TIM8_OC5_COMP2 /* 消隐源：TIM8 OC5对应COMP2的别名 */
#define COMP_BLANKINGSRCE_TIM15OC1       COMP_BLANKINGSRC_TIM15_OC1_COMP2 /* 消隐源：TIM15 OC1对应COMP2的别名 */
#define COMP_BLANKINGSRCE_NONE           COMP_BLANKINGSRC_NONE      /* 无消隐源的别名 */
#endif
#if defined(STM32L0)
/* 对于STM32L0系列，将高速模式宏定义为中等速度模式（出于兼容性考虑） */
#define COMP_MODE_HIGHSPEED              COMP_POWERMODE_MEDIUMSPEED
/* 对于STM32L0系列，将低速模式宏定义为超低功耗模式（出于兼容性考虑） */
#define COMP_MODE_LOWSPEED               COMP_POWERMODE_ULTRALOWPOWER
#else
/* 高速模式宏定义 */
#define COMP_MODE_HIGHSPEED              COMP_POWERMODE_HIGHSPEED
/* 中速模式宏定义 */
#define COMP_MODE_MEDIUMSPEED            COMP_POWERMODE_MEDIUMSPEED
/* 低功耗模式宏定义 */
#define COMP_MODE_LOWPOWER               COMP_POWERMODE_LOWPOWER
/* 超低功耗模式宏定义 */
#define COMP_MODE_ULTRALOWPOWER          COMP_POWERMODE_ULTRALOWPOWER
#endif

#endif  /* 结束条件编译块 */

#if defined(STM32U5)
/* 针对STM32U5系列，修正RASING拼写错误，映射到正确的RISING标志清除宏 */
#define __HAL_COMP_COMP1_EXTI_CLEAR_RASING_FLAG __HAL_COMP_COMP1_EXTI_CLEAR_RISING_FLAG
#endif

/**
  * @}
  */

/** @defgroup HAL_CORTEX_Aliased_Defines 为保持向后兼容性而维护的HAL CORTEX别名定义
  * @{
  */
/* 将旧的系统时钟配置宏映射到新的HAL函数宏 */
#define __HAL_CORTEX_SYSTICKCLK_CONFIG HAL_SYSTICK_CLKSourceConfig
#if defined(STM32U5)
/* 内存保护单元设备属性：非聚集、非重排、非提前写 */
#define  MPU_DEVICE_nGnRnE          MPU_DEVICE_NGNRNE
/* 内存保护单元设备属性：非聚集、非重排、可提前写 */
#define  MPU_DEVICE_nGnRE           MPU_DEVICE_NGNRE
/* 内存保护单元设备属性：非聚集、可重排、可提前写 */
#define  MPU_DEVICE_nGRE            MPU_DEVICE_NGRE
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup CRC_Aliases CRC API别名
  * @{
  */
#if defined(STM32H5) || defined(STM32C0)
/* STM32H5和STM32C0系列不使用这些别名 */
#else
/* 将旧的数据输入反转函数映射到新的扩展函数（用于跨STM32系列兼容性） */
#define HAL_CRC_Input_Data_Reverse   HAL_CRCEx_Input_Data_Reverse
/* 将旧的数据输出反转函数映射到新的扩展函数（用于跨STM32系列兼容性） */
#define HAL_CRC_Output_Data_Reverse  HAL_CRCEx_Output_Data_Reverse
#endif
/**
  * @}
  */

/** @defgroup HAL_CRC_Aliased_Defines 为保持向后兼容性而维护的HAL CRC别名定义
  * @{
  */

/* 禁用CRC输出数据反转的旧宏定义 */
#define CRC_OUTPUTDATA_INVERSION_DISABLED    CRC_OUTPUTDATA_INVERSION_DISABLE
/* 启用CRC输出数据反转的旧宏定义 */
#define CRC_OUTPUTDATA_INVERSION_ENABLED     CRC_OUTPUTDATA_INVERSION_ENABLE

/**
  * @}
  */

/** @defgroup HAL_DAC_Aliased_Defines 为保持向后兼容性而维护的HAL DAC别名定义
  * @{
  */

/* DAC通道的旧宏定义 */
#define DAC1_CHANNEL_1                                  DAC_CHANNEL_1
#define DAC1_CHANNEL_2                                  DAC_CHANNEL_2
#define DAC2_CHANNEL_1                                  DAC_CHANNEL_1
/* 无波形生成模式 */
#define DAC_WAVE_NONE                                   0x00000000U
/* 噪声波形生成模式 */
#define DAC_WAVE_NOISE                                  DAC_CR_WAVE1_0
/* 三角波形生成模式 */
#define DAC_WAVE_TRIANGLE                               DAC_CR_WAVE1_1
/* 无波形生成的旧宏定义 */
#define DAC_WAVEGENERATION_NONE                         DAC_WAVE_NONE
/* 噪声波形生成的旧宏定义 */
#define DAC_WAVEGENERATION_NOISE                        DAC_WAVE_NOISE
/* 三角波形生成的旧宏定义 */
#define DAC_WAVEGENERATION_TRIANGLE                     DAC_WAVE_TRIANGLE

#if defined(STM32G4) || defined(STM32H7) || defined (STM32U5)
/* 禁用DAC芯片连接（使用外部连接） */
#define DAC_CHIPCONNECT_DISABLE       DAC_CHIPCONNECT_EXTERNAL
/* 启用DAC芯片连接（使用内部连接） */
#define DAC_CHIPCONNECT_ENABLE        DAC_CHIPCONNECT_INTERNAL
#endif

#if defined(STM32U5)
/* 停止LPTIM1输出的触发源旧宏定义 */
#define DAC_TRIGGER_STOP_LPTIM1_OUT  DAC_TRIGGER_STOP_LPTIM1_CH1
/* 停止LPTIM3输出的触发源旧宏定义 */
#define DAC_TRIGGER_STOP_LPTIM3_OUT  DAC_TRIGGER_STOP_LPTIM3_CH1
/* LPTIM1输出触发源旧宏定义 */
#define DAC_TRIGGER_LPTIM1_OUT       DAC_TRIGGER_LPTIM1_CH1
/* LPTIM3输出触发源旧宏定义 */
#define DAC_TRIGGER_LPTIM3_OUT       DAC_TRIGGER_LPTIM3_CH1
#endif

#if defined(STM32H5)
/* LPTIM1输出触发源旧宏定义 */
#define DAC_TRIGGER_LPTIM1_OUT       DAC_TRIGGER_LPTIM1_CH1
/* LPTIM2输出触发源旧宏定义 */
#define DAC_TRIGGER_LPTIM2_OUT       DAC_TRIGGER_LPTIM2_CH1
#endif

#if defined(STM32L1) || defined(STM32L4) || defined(STM32G0) || defined(STM32L5) || defined(STM32H7) || \
    defined(STM32F4) || defined(STM32G4)
/* DAC MSP初始化回调ID的旧宏定义 */
#define HAL_DAC_MSP_INIT_CB_ID       HAL_DAC_MSPINIT_CB_ID
/* DAC MSP反初始化回调ID的旧宏定义 */
#define HAL_DAC_MSP_DEINIT_CB_ID     HAL_DAC_MSPDEINIT_CB_ID
#endif

/**
  * @}
  */

/** @defgroup HAL_DMA_Aliased_Defines 为保持向后兼容性而维护的HAL DMA别名定义
  * @{
  */
/* DMA重映射通道的旧宏定义 */
#define HAL_REMAPDMA_ADC_DMA_CH2                DMA_REMAP_ADC_DMA_CH2
#define HAL_REMAPDMA_USART1_TX_DMA_CH4          DMA_REMAP_USART1_TX_DMA_CH4
#define HAL_REMAPDMA_USART1_RX_DMA_CH5          DMA_REMAP_USART1_RX_DMA_CH5
#define HAL_REMAPDMA_TIM16_DMA_CH4              DMA_REMAP_TIM16_DMA_CH4
#define HAL_REMAPDMA_TIM17_DMA_CH2              DMA_REMAP_TIM17_DMA_CH2
#define HAL_REMAPDMA_USART3_DMA_CH32            DMA_REMAP_USART3_DMA_CH32
#define HAL_REMAPDMA_TIM16_DMA_CH6              DMA_REMAP_TIM16_DMA_CH6
#define HAL_REMAPDMA_TIM17_DMA_CH7              DMA_REMAP_TIM17_DMA_CH7
#define HAL_REMAPDMA_SPI2_DMA_CH67              DMA_REMAP_SPI2_DMA_CH67
#define HAL_REMAPDMA_USART2_DMA_CH67            DMA_REMAP_USART2_DMA_CH67
#define HAL_REMAPDMA_I2C1_DMA_CH76              DMA_REMAP_I2C1_DMA_CH76
#define HAL_REMAPDMA_TIM1_DMA_CH6               DMA_REMAP_TIM1_DMA_CH6
#define HAL_REMAPDMA_TIM2_DMA_CH7               DMA_REMAP_TIM2_DMA_CH7
#define HAL_REMAPDMA_TIM3_DMA_CH6               DMA_REMAP_TIM3_DMA_CH6

/* DMA重映射检查宏的旧定义 */
#define IS_HAL_REMAPDMA                          IS_DMA_REMAP
/* 启用DMA重映射通道的旧宏定义 */
#define __HAL_REMAPDMA_CHANNEL_ENABLE            __HAL_DMA_REMAP_CHANNEL_ENABLE
/* 禁用DMA重映射通道的旧宏定义 */
#define __HAL_REMAPDMA_CHANNEL_DISABLE           __HAL_DMA_REMAP_CHANNEL_DISABLE

#if defined(STM32L4)

/* DMAMUX1请求生成事件源的旧宏定义 */
#define HAL_DMAMUX1_REQUEST_GEN_EXTI0            HAL_DMAMUX1_REQ_GEN_EXTI0
#define HAL_DMAMUX1_REQUEST_GEN_EXTI1            HAL_DMAMUX1_REQ_GEN_EXTI1
#define HAL_DMAMUX1_REQUEST_GEN_EXTI2            HAL_DMAMUX1_REQ_GEN_EXTI2
#define HAL_DMAMUX1_REQUEST_GEN_EXTI3            HAL_DMAMUX1_REQ_GEN_EXTI3
#define HAL_DMAMUX1_REQUEST_GEN_EXTI4            HAL_DMAMUX1_REQ_GEN_EXTI4
#define HAL_DMAMUX1_REQUEST_GEN_EXTI5            HAL_DMAMUX1_REQ_GEN_EXTI5
#define HAL_DMAMUX1_REQUEST_GEN_EXTI6            HAL_DMAMUX1_REQ_GEN_EXTI6
#define HAL_DMAMUX1_REQUEST_GEN_EXTI7            HAL_DMAMUX1_REQ_GEN_EXTI7
#define HAL_DMAMUX1_REQUEST_GEN_EXTI8            HAL_DMAMUX1_REQ_GEN_EXTI8
#define HAL_DMAMUX1_REQUEST_GEN_EXTI9            HAL_DMAMUX1_REQ_GEN_EXTI9
#define HAL_DMAMUX1_REQUEST_GEN_EXTI10           HAL_DMAMUX1_REQ_GEN_EXTI10
#define HAL_DMAMUX1_REQUEST_GEN_EXTI11           HAL_DMAMUX1_REQ_GEN_EXTI11
#define HAL_DMAMUX1_REQUEST_GEN_EXTI12           HAL_DMAMUX1_REQ_GEN_EXTI12
#define HAL_DMAMUX1_REQUEST_GEN_EXTI13           HAL_DMAMUX1_REQ_GEN_EXTI13
#define HAL_DMAMUX1_REQUEST_GEN_EXTI14           HAL_DMAMUX1_REQ_GEN_EXTI14
#define HAL_DMAMUX1_REQUEST_GEN_EXTI15           HAL_DMAMUX1_REQ_GEN_EXTI15
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH0_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH1_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH2_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH3_EVT  HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH3_EVT
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM1_OUT       HAL_DMAMUX1_REQ_GEN_LPTIM1_OUT
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM2_OUT       HAL_DMAMUX1_REQ_GEN_LPTIM2_OUT
#define HAL_DMAMUX1_REQUEST_GEN_DSI_TE           HAL_DMAMUX1_REQ_GEN_DSI_TE
#define HAL_DMAMUX1_REQUEST_GEN_DSI_EOT          HAL_DMAMUX1_REQ_GEN_DSI_EOT
#define HAL_DMAMUX1_REQUEST_GEN_DMA2D_EOT        HAL_DMAMUX1_REQ_GEN_DMA2D_EOT
#define HAL_DMAMUX1_REQUEST_GEN_LTDC_IT          HAL_DMAMUX1_REQ_GEN_LTDC_IT

/* DMAMUX请求生成事件的旧宏定义 */
#define HAL_DMAMUX_REQUEST_GEN_NO_EVENT          HAL_DMAMUX_REQ_GEN_NO_EVENT
#define HAL_DMAMUX_REQUEST_GEN_RISING            HAL_DMAMUX_REQ_GEN_RISING
#define HAL_DMAMUX_REQUEST_GEN_FALLING           HAL_DMAMUX_REQ_GEN_FALLING
#define HAL_DMAMUX_REQUEST_GEN_RISING_FALLING    HAL_DMAMUX_REQ_GEN_RISING_FALLING

#if defined(STM32L4R5xx) || defined(STM32L4R9xx) || defined(STM32L4R9xx) || defined(STM32L4S5xx) || \
    defined(STM32L4S7xx) || defined(STM32L4S9xx)
/* DCMI/PSSI DMA请求的旧宏定义 */
#define DMA_REQUEST_DCMI_PSSI                    DMA_REQUEST_DCMI
#endif

#endif /* STM32L4 */

#if defined(STM32G0)
/* DAC1通道1 DMA请求的旧宏定义 */
#define DMA_REQUEST_DAC1_CHANNEL1                DMA_REQUEST_DAC1_CH1
/* DAC1通道2 DMA请求的旧宏定义 */
#define DMA_REQUEST_DAC1_CHANNEL2                DMA_REQUEST_DAC1_CH2
/* TIM16触发/COM DMA请求的旧宏定义 */
#define DMA_REQUEST_TIM16_TRIG_COM               DMA_REQUEST_TIM16_COM
/* TIM17触发/COM DMA请求的旧宏定义 */
#define DMA_REQUEST_TIM17_TRIG_COM               DMA_REQUEST_TIM17_COM

/* LL库中TIM16触发/COM DMAMUX请求的旧宏定义 */
#define LL_DMAMUX_REQ_TIM16_TRIG_COM             LL_DMAMUX_REQ_TIM16_COM
/* LL库中TIM17触发/COM DMAMUX请求的旧宏定义 */
#define LL_DMAMUX_REQ_TIM17_TRIG_COM             LL_DMAMUX_REQ_TIM17_COM
#endif

#if defined(STM32H7)

/* DAC1 DMA请求的旧宏定义 */
#define DMA_REQUEST_DAC1 DMA_REQUEST_DAC1_CH1
/* DAC2 DMA请求的旧宏定义 */
#define DMA_REQUEST_DAC2 DMA_REQUEST_DAC1_CH2

/* LPUART1 RX BDMA请求的旧宏定义 */
#define BDMA_REQUEST_LP_UART1_RX BDMA_REQUEST_LPUART1_RX
/* LPUART1 TX BDMA请求的旧宏定义 */
#define BDMA_REQUEST_LP_UART1_TX BDMA_REQUEST_LPUART1_TX

/* DMAMUX1请求生成事件源的旧宏定义 */
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH0_EVT    HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH0_EVT
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH1_EVT    HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH1_EVT
#define HAL_DMAMUX1_REQUEST_GEN_DMAMUX1_CH2_EVT    HAL_DMAMUX1_REQ_GEN_DMAMUX1_CH2_EVT
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM1_OUT         HAL_DMAMUX1_REQ_GEN_LPTIM1_OUT
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM2_OUT         HAL_DMAMUX1_REQ_GEN_LPTIM2_OUT
#define HAL_DMAMUX1_REQUEST_GEN_LPTIM3_OUT         HAL_DMAMUX1_REQ_GEN_LPTIM3_OUT
#define HAL_DMAMUX1_REQUEST_GEN_EXTI0              HAL_DMAMUX1_REQ_GEN_EXTI0
#define HAL_DMAMUX1_REQUEST_GEN_TIM12_TRGO         HAL_DMAMUX1_REQ_GEN_TIM12_TRGO
/* DMAMUX2请求生成器事件别名定义 */
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH0_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH0_EVT    // DMAMUX2请求生成器：DMAMUX2通道0事件别名
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH1_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH1_EVT    // DMAMUX2请求生成器：DMAMUX2通道1事件别名
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH2_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH2_EVT    // DMAMUX2请求生成器：DMAMUX2通道2事件别名
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH3_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH3_EVT    // DMAMUX2请求生成器：DMAMUX2通道3事件别名
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH4_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH4_EVT    // DMAMUX2请求生成器：DMAMUX2通道4事件别名
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH5_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH5_EVT    // DMAMUX2请求生成器：DMAMUX2通道5事件别名
#define HAL_DMAMUX2_REQUEST_GEN_DMAMUX2_CH6_EVT    HAL_DMAMUX2_REQ_GEN_DMAMUX2_CH6_EVT    // DMAMUX2请求生成器：DMAMUX2通道6事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_RX_WKUP    HAL_DMAMUX2_REQ_GEN_LPUART1_RX_WKUP    // DMAMUX2请求生成器：LPUART1接收唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_TX_WKUP    HAL_DMAMUX2_REQ_GEN_LPUART1_TX_WKUP    // DMAMUX2请求生成器：LPUART1发送唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM2_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM2_WKUP        // DMAMUX2请求生成器：LPTIM2唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM2_OUT         HAL_DMAMUX2_REQ_GEN_LPTIM2_OUT         // DMAMUX2请求生成器：LPTIM2输出事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM3_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM3_WKUP        // DMAMUX2请求生成器：LPTIM3唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM3_OUT         HAL_DMAMUX2_REQ_GEN_LPTIM3_OUT         // DMAMUX2请求生成器：LPTIM3输出事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM4_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM4_WKUP        // DMAMUX2请求生成器：LPTIM4唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPTIM5_WKUP        HAL_DMAMUX2_REQ_GEN_LPTIM5_WKUP        // DMAMUX2请求生成器：LPTIM5唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_I2C4_WKUP          HAL_DMAMUX2_REQ_GEN_I2C4_WKUP          // DMAMUX2请求生成器：I2C4唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_SPI6_WKUP          HAL_DMAMUX2_REQ_GEN_SPI6_WKUP          // DMAMUX2请求生成器：SPI6唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_COMP1_OUT          HAL_DMAMUX2_REQ_GEN_COMP1_OUT          // DMAMUX2请求生成器：比较器1输出事件别名
#define HAL_DMAMUX2_REQUEST_GEN_COMP2_OUT          HAL_DMAMUX2_REQ_GEN_COMP2_OUT          // DMAMUX2请求生成器：比较器2输出事件别名
#define HAL_DMAMUX2_REQUEST_GEN_RTC_WKUP           HAL_DMAMUX2_REQ_GEN_RTC_WKUP           // DMAMUX2请求生成器：RTC唤醒事件别名
#define HAL_DMAMUX2_REQUEST_GEN_EXTI0              HAL_DMAMUX2_REQ_GEN_EXTI0              // DMAMUX2请求生成器：外部中断线0事件别名
#define HAL_DMAMUX2_REQUEST_GEN_EXTI2              HAL_DMAMUX2_REQ_GEN_EXTI2              // DMAMUX2请求生成器：外部中断线2事件别名
#define HAL_DMAMUX2_REQUEST_GEN_I2C4_IT_EVT        HAL_DMAMUX2_REQ_GEN_I2C4_IT_EVT        // DMAMUX2请求生成器：I2C4中断事件别名
#define HAL_DMAMUX2_REQUEST_GEN_SPI6_IT            HAL_DMAMUX2_REQ_GEN_SPI6_IT            // DMAMUX2请求生成器：SPI6中断事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_TX_IT      HAL_DMAMUX2_REQ_GEN_LPUART1_TX_IT      // DMAMUX2请求生成器：LPUART1发送中断事件别名
#define HAL_DMAMUX2_REQUEST_GEN_LPUART1_RX_IT      HAL_DMAMUX2_REQ_GEN_LPUART1_RX_IT      // DMAMUX2请求生成器：LPUART1接收中断事件别名
#define HAL_DMAMUX2_REQUEST_GEN_ADC3_IT            HAL_DMAMUX2_REQ_GEN_ADC3_IT            // DMAMUX2请求生成器：ADC3中断事件别名
#define HAL_DMAMUX2_REQUEST_GEN_ADC3_AWD1_OUT      HAL_DMAMUX2_REQ_GEN_ADC3_AWD1_OUT      // DMAMUX2请求生成器：ADC3模拟看门狗1输出事件别名
#define HAL_DMAMUX2_REQUEST_GEN_BDMA_CH0_IT        HAL_DMAMUX2_REQ_GEN_BDMA_CH0_IT        // DMAMUX2请求生成器：BDMA通道0中断事件别名
#define HAL_DMAMUX2_REQUEST_GEN_BDMA_CH1_IT        HAL_DMAMUX2_REQ_GEN_BDMA_CH1_IT        // DMAMUX2请求生成器：BDMA通道1中断事件别名

/* DMAMUX请求生成器触发边沿别名定义 */
#define HAL_DMAMUX_REQUEST_GEN_NO_EVENT            HAL_DMAMUX_REQ_GEN_NO_EVENT            // DMAMUX请求生成器：无事件触发别名
#define HAL_DMAMUX_REQUEST_GEN_RISING              HAL_DMAMUX_REQ_GEN_RISING              // DMAMUX请求生成器：上升沿触发别名
#define HAL_DMAMUX_REQUEST_GEN_FALLING             HAL_DMAMUX_REQ_GEN_FALLING             // DMAMUX请求生成器：下降沿触发别名
#define HAL_DMAMUX_REQUEST_GEN_RISING_FALLING      HAL_DMAMUX_REQ_GEN_RISING_FALLING      // DMAMUX请求生成器：上升沿和下降沿触发别名

/* DFSDM滤波器外部触发源别名定义 */
#define DFSDM_FILTER_EXT_TRIG_LPTIM1               DFSDM_FILTER_EXT_TRIG_LPTIM1_OUT       // DFSDM滤波器外部触发：LPTIM1输出别名
#define DFSDM_FILTER_EXT_TRIG_LPTIM2               DFSDM_FILTER_EXT_TRIG_LPTIM2_OUT       // DFSDM滤波器外部触发：LPTIM2输出别名
#define DFSDM_FILTER_EXT_TRIG_LPTIM3               DFSDM_FILTER_EXT_TRIG_LPTIM3_OUT       // DFSDM滤波器外部触发：LPTIM3输出别名

/* DAC触发器别名定义 */
#define DAC_TRIGGER_LP1_OUT                        DAC_TRIGGER_LPTIM1_OUT                 // DAC触发器：LPTIM1输出别名
#define DAC_TRIGGER_LP2_OUT                        DAC_TRIGGER_LPTIM2_OUT                 // DAC触发器：LPTIM2输出别名

#endif /* STM32H7 结束 */  // 结束STM32H7系列的条件编译

#if defined(STM32U5)  // 针对STM32U5系列的定义
#define GPDMA1_REQUEST_DCMI                        GPDMA1_REQUEST_DCMI_PSSI               // GPDMA1请求：DCMI/PSSI接口别名
#endif /* STM32U5 结束 */  // 结束STM32U5系列的条件编译

/**
  * @}
  */  // Doxygen注释块：结束前一个分组

/** @defgroup HAL_FLASH_Aliased_Defines HAL FLASH Aliased Defines maintained for legacy purpose
  * @{
  */  // Doxygen注释块：开始HAL FLASH别名定义分组（保持原样，不翻译）

/* FLASH编程和擦除类型别名定义 */
#define TYPEPROGRAM_BYTE              FLASH_TYPEPROGRAM_BYTE                              // 字节编程类型别名
#define TYPEPROGRAM_HALFWORD          FLASH_TYPEPROGRAM_HALFWORD                          // 半字编程类型别名
#define TYPEPROGRAM_WORD              FLASH_TYPEPROGRAM_WORD                              // 字编程类型别名
#define TYPEPROGRAM_DOUBLEWORD        FLASH_TYPEPROGRAM_DOUBLEWORD                        // 双字编程类型别名
#define TYPEERASE_SECTORS             FLASH_TYPEERASE_SECTORS                             // 扇区擦除类型别名
#define TYPEERASE_PAGES               FLASH_TYPEERASE_PAGES                               // 页擦除类型别名
#define TYPEERASE_PAGEERASE           FLASH_TYPEERASE_PAGES                               // 页擦除类型别名（重复定义，兼容性）
#define TYPEERASE_MASSERASE           FLASH_TYPEERASE_MASSERASE                           // 全片擦除类型别名
#define WRPSTATE_DISABLE              OB_WRPSTATE_DISABLE                                 // 写保护状态禁用别名
#define WRPSTATE_ENABLE               OB_WRPSTATE_ENABLE                                  // 写保护状态启用别名
#define HAL_FLASH_TIMEOUT_VALUE       FLASH_TIMEOUT_VALUE                                 // FLASH超时值别名
#define OBEX_PCROP                    OPTIONBYTE_PCROP                                    // 选项字节PCROP配置别名
#define OBEX_BOOTCONFIG               OPTIONBYTE_BOOTCONFIG                               // 选项字节启动配置别名
#define PCROPSTATE_DISABLE            OB_PCROP_STATE_DISABLE                              // PCROP状态禁用别名
#define PCROPSTATE_ENABLE             OB_PCROP_STATE_ENABLE                               // PCROP状态启用别名
#define TYPEERASEDATA_BYTE            FLASH_TYPEERASEDATA_BYTE                            // 字节数据擦除类型别名
#define TYPEERASEDATA_HALFWORD        FLASH_TYPEERASEDATA_HALFWORD                        // 半字数据擦除类型别名
#define TYPEERASEDATA_WORD            FLASH_TYPEERASEDATA_WORD                            // 字数据擦除类型别名
#define TYPEPROGRAMDATA_BYTE          FLASH_TYPEPROGRAMDATA_BYTE                          // 字节数据编程类型别名
#define TYPEPROGRAMDATA_HALFWORD      FLASH_TYPEPROGRAMDATA_HALFWORD                      // 半字数据编程类型别名
#define TYPEPROGRAMDATA_WORD          FLASH_TYPEPROGRAMDATA_WORD                          // 字数据编程类型别名
#define TYPEPROGRAMDATA_FASTBYTE      FLASH_TYPEPROGRAMDATA_FASTBYTE                      // 快速字节数据编程类型别名
#define TYPEPROGRAMDATA_FASTHALFWORD  FLASH_TYPEPROGRAMDATA_FASTHALFWORD                  // 快速半字数据编程类型别名
#define TYPEPROGRAMDATA_FASTWORD      FLASH_TYPEPROGRAMDATA_FASTWORD                      // 快速字数据编程类型别名
#if !defined(STM32F2) && !defined(STM32F4) && !defined(STM32F7) && !defined(STM32H7)  // 排除指定系列的条件编译
#define PAGESIZE                      FLASH_PAGE_SIZE                                     // FLASH页大小别名
#endif /* STM32F2 && STM32F4 && STM32F7 &&  STM32H7 结束 */  // 结束排除条件编译
#define TYPEPROGRAM_FASTBYTE          FLASH_TYPEPROGRAM_BYTE                              // 快速字节编程类型别名
#define TYPEPROGRAM_FASTHALFWORD      FLASH_TYPEPROGRAM_HALFWORD                          // 快速半字编程类型别名
#define TYPEPROGRAM_FASTWORD          FLASH_TYPEPROGRAM_WORD                              // 快速字编程类型别名
#define VOLTAGE_RANGE_1               FLASH_VOLTAGE_RANGE_1                               // 电压范围1别名
#define VOLTAGE_RANGE_2               FLASH_VOLTAGE_RANGE_2                               // 电压范围2别名
#define VOLTAGE_RANGE_3               FLASH_VOLTAGE_RANGE_3                               // 电压范围3别名
#define VOLTAGE_RANGE_4               FLASH_VOLTAGE_RANGE_4                               // 电压范围4别名
#define TYPEPROGRAM_FAST              FLASH_TYPEPROGRAM_FAST                              // 快速编程类型别名
#define TYPEPROGRAM_FAST_AND_LAST     FLASH_TYPEPROGRAM_FAST_AND_LAST                     // 快速且最后一次编程类型别名
#define WRPAREA_BANK1_AREAA           OB_WRPAREA_BANK1_AREAA                              // 存储区1写保护区域A别名
#define WRPAREA_BANK1_AREAB           OB_WRPAREA_BANK1_AREAB                              // 存储区1写保护区域B别名
#define WRPAREA_BANK2_AREAA           OB_WRPAREA_BANK2_AREAA                              // 存储区2写保护区域A别名
#define WRPAREA_BANK2_AREAB           OB_WRPAREA_BANK2_AREAB                              // 存储区2写保护区域B别名
#define IWDG_STDBY_FREEZE             OB_IWDG_STDBY_FREEZE                                // 独立看门狗待机模式冻结别名
#define IWDG_STDBY_ACTIVE             OB_IWDG_STDBY_RUN                                   // 独立看门狗待机模式运行别名
#define IWDG_STOP_FREEZE              OB_IWDG_STOP_FREEZE                                 // 独立看门狗停止模式冻结别名
#define IWDG_STOP_ACTIVE              OB_IWDG_STOP_RUN                                    // 独立看门狗停止模式运行别名
#define FLASH_ERROR_NONE              HAL_FLASH_ERROR_NONE                                // FLASH无错误别名
#define FLASH_ERROR_RD                HAL_FLASH_ERROR_RD                                  // FLASH读取错误别名
#define FLASH_ERROR_PG                HAL_FLASH_ERROR_PROG                                // FLASH编程错误别名
#define FLASH_ERROR_PGP               HAL_FLASH_ERROR_PGS                                 // FLASH编程序列错误别名
#define FLASH_ERROR_WRP               HAL_FLASH_ERROR_WRP                                 // FLASH写保护错误别名
#define FLASH_ERROR_OPTV              HAL_FLASH_ERROR_OPTV                                // FLASH选项字节验证错误别名
#define FLASH_ERROR_OPTVUSR           HAL_FLASH_ERROR_OPTVUSR                             // FLASH用户选项字节验证错误别名
#define FLASH_ERROR_PROG              HAL_FLASH_ERROR_PROG                                // FLASH编程错误别名（重复定义，兼容性）
#define FLASH_ERROR_OP                HAL_FLASH_ERROR_OPERATION                           // FLASH操作错误别名
#define FLASH_ERROR_PGA               HAL_FLASH_ERROR_PGA                                 // FLASH编程对齐错误别名
#define FLASH_ERROR_SIZE              HAL_FLASH_ERROR_SIZE                                // FLASH大小错误别名
#define FLASH_ERROR_SIZ               HAL_FLASH_ERROR_SIZE                                // FLASH大小错误别名（重复定义，兼容性）
#define FLASH_ERROR_PGS               HAL_FLASH_ERROR_PGS                                 // FLASH编程序列错误别名（重复定义，兼容性）
#define FLASH_ERROR_MIS               HAL_FLASH_ERROR_MIS                                 // FLASH不匹配错误别名
#define FLASH_ERROR_FAST              HAL_FLASH_ERROR_FAST                                // FLASH快速编程错误别名
#define FLASH_ERROR_FWWERR            HAL_FLASH_ERROR_FWWERR                              // FLASH写操作错误别名
#define FLASH_ERROR_NOTZERO           HAL_FLASH_ERROR_NOTZERO                             // FLASH非零错误别名
#define FLASH_ERROR_OPERATION         HAL_FLASH_ERROR_OPERATION                           // FLASH操作错误别名（重复定义，兼容性）
#define FLASH_ERROR_ERS               HAL_FLASH_ERROR_ERS                                 // FLASH擦除错误别名
#define OB_WDG_SW                     OB_IWDG_SW                                          // 看门狗软件模式别名
#define OB_WDG_HW                     OB_IWDG_HW                                          // 看门狗硬件模式别名
#define OB_SDADC12_VDD_MONITOR_SET    OB_SDACD_VDD_MONITOR_SET                            // SDADC1/2 VDD监控设置别名
#define OB_SDADC12_VDD_MONITOR_RESET  OB_SDACD_VDD_MONITOR_RESET                          // SDADC1/2 VDD监控复位别名
#define OB_RAM_PARITY_CHECK_SET       OB_SRAM_PARITY_SET                                  // RAM奇偶校验设置别名
#define OB_RAM_PARITY_CHECK_RESET     OB_SRAM_PARITY_RESET                                // RAM奇偶校验复位别名
#define IS_OB_SDADC12_VDD_MONITOR     IS_OB_SDACD_VDD_MONITOR                             // SDADC1/2 VDD监控检查宏别名
#define OB_RDP_LEVEL0                 OB_RDP_LEVEL_0                                      // RDP级别0别名
#define OB_RDP_LEVEL1                 OB_RDP_LEVEL_1                                      // RDP级别1别名
#define OB_RDP_LEVEL2                 OB_RDP_LEVEL_2                                      // RDP级别2别名
#if defined(STM32G0) || defined(STM32C0)  // 针对STM32G0或STM32C0系列的条件编译
#define OB_BOOT_LOCK_DISABLE          OB_BOOT_ENTRY_FORCED_NONE                           // 启动入口强制无锁定别名
#define OB_BOOT_LOCK_ENABLE           OB_BOOT_ENTRY_FORCED_FLASH                          // 启动入口强制FLASH锁定别名
#else  // 其他系列
#define OB_BOOT_ENTRY_FORCED_NONE     OB_BOOT_LOCK_DISABLE                                // 启动入口强制无锁定别名（反向定义）
#define OB_BOOT_ENTRY_FORCED_FLASH    OB_BOOT_LOCK_ENABLE                                 // 启动入口强制FLASH锁定别名（反向定义）
#endif  // 结束条件编译
#if defined(STM32H7)  // 针对STM32H7系列的条件编译
#define FLASH_FLAG_SNECCE_BANK1RR     FLASH_FLAG_SNECCERR_BANK1                           // 存储区1单ECC错误标志别名
#define FLASH_FLAG_DBECCE_BANK1RR     FLASH_FLAG_DBECCERR_BANK1                           // 存储区1双ECC错误标志别名
#define FLASH_FLAG_STRBER_BANK1R      FLASH_FLAG_STRBERR_BANK1                            // 存储区1存储错误标志别名
#define FLASH_FLAG_SNECCE_BANK2RR     FLASH_FLAG_SNECCERR_BANK2                           // 存储区2单ECC错误标志别名
#define FLASH_FLAG_DBECCE_BANK2RR     FLASH_FLAG_DBECCERR_BANK2                           // 存储区2双ECC错误标志别名
#define FLASH_FLAG_STRBER_BANK2R      FLASH_FLAG_STRBERR_BANK2                            // 存储区2存储错误标志别名
#define FLASH_FLAG_WDW                FLASH_FLAG_WBNE                                     // 写缓冲区非空标志别名
#define OB_WRP_SECTOR_All             OB_WRP_SECTOR_ALL                                   // 所有扇区写保护别名
#endif /* STM32H7 结束 */  // 结束STM32H7系列的条件编译
#if defined(STM32U5)  // 针对STM32U5系列的条件编译
#define OB_USER_nRST_STOP             OB_USER_NRST_STOP                                   // 用户选项：停止模式复位别名
#define OB_USER_nRST_STDBY            OB_USER_NRST_STDBY                                  // 用户选项：待机模式复位别名
#define OB_USER_nRST_SHDW             OB_USER_NRST_SHDW                                   // 用户选项：阴影复位别名
#define OB_USER_nSWBOOT0              OB_USER_NSWBOOT0                                    // 用户选项：软件启动0别名
#define OB_USER_nBOOT0                OB_USER_NBOOT0                                      // 用户选项：启动0别名
#define OB_nBOOT0_RESET               OB_NBOOT0_RESET                                     // 启动0复位别名
#define OB_nBOOT0_SET                 OB_NBOOT0_SET                                       // 启动0设置别名
#define OB_USER_SRAM134_RST           OB_USER_SRAM_RST                                    // 用户选项：SRAM复位别名
#define OB_SRAM134_RST_ERASE          OB_SRAM_RST_ERASE                                   // SRAM复位擦除别名
#define OB_SRAM134_RST_NOT_ERASE      OB_SRAM_RST_NOT_ERASE                               // SRAM复位不擦除别名
#endif /* STM32U5 结束 */  // 结束STM32U5系列的条件编译
#if defined(STM32U0)  // 针对STM32U0系列的条件编译
#define OB_USER_nRST_STOP             OB_USER_NRST_STOP                                   // 用户选项：停止模式复位别名
#define OB_USER_nRST_STDBY            OB_USER_NRST_STDBY                                  // 用户选项：待机模式复位别名
#define OB_USER_nRST_SHDW             OB_USER_NRST_SHDW                                   // 用户选项：阴影复位别名
#define OB_USER_nBOOT_SEL             OB_USER_NBOOT_SEL                                   // 用户选项：启动选择别名
#define OB_USER_nBOOT0                OB_USER_NBOOT0                                      // 用户选项：启动0别名
#define OB_USER_nBOOT1                OB_USER_NBOOT1                                      // 用户选项：启动1别名
#define OB_nBOOT0_RESET               OB_NBOOT0_RESET                                     // 启动0复位别名
#define OB_nBOOT0_SET                 OB_NBOOT0_SET                                       // 启动0设置别名
#endif /* STM32U0 结束 */  // 结束STM32U0系列的条件编译

/**
  * @}
  */  // Doxygen注释块：结束HAL FLASH别名定义分组

/** @defgroup HAL_JPEG_Aliased_Macros HAL JPEG Aliased Macros maintained for legacy purpose
  * @{
  */  // Doxygen注释块：开始HAL JPEG别名宏分组（保持原样，不翻译）
#if defined(STM32H7)  // 如果定义了 STM32H7 系列芯片
#define __HAL_RCC_JPEG_CLK_ENABLE               __HAL_RCC_JPGDECEN_CLK_ENABLE  // 使能 JPEG 硬件时钟
#define __HAL_RCC_JPEG_CLK_DISABLE              __HAL_RCC_JPGDECEN_CLK_DISABLE  // 禁用 JPEG 硬件时钟
#define __HAL_RCC_JPEG_FORCE_RESET              __HAL_RCC_JPGDECRST_FORCE_RESET  // 强制复位 JPEG 模块
#define __HAL_RCC_JPEG_RELEASE_RESET            __HAL_RCC_JPGDECRST_RELEASE_RESET  // 释放 JPEG 模块复位
#define __HAL_RCC_JPEG_CLK_SLEEP_ENABLE         __HAL_RCC_JPGDEC_CLK_SLEEP_ENABLE  // 使能 JPEG 睡眠模式时钟
#define __HAL_RCC_JPEG_CLK_SLEEP_DISABLE        __HAL_RCC_JPGDEC_CLK_SLEEP_DISABLE  // 禁用 JPEG 睡眠模式时钟
#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_SYSCFG_Aliased_Defines HAL SYSCFG Aliased Defines maintained for legacy purpose
  * @{
  */
// HAL SYSCFG 别名定义，为保持向后兼容性而维护

#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA9    I2C_FASTMODEPLUS_PA9  // I2C 快速模式增强 PA9 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PA10   I2C_FASTMODEPLUS_PA10  // I2C 快速模式增强 PA10 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB6    I2C_FASTMODEPLUS_PB6  // I2C 快速模式增强 PB6 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB7    I2C_FASTMODEPLUS_PB7  // I2C 快速模式增强 PB7 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB8    I2C_FASTMODEPLUS_PB8  // I2C 快速模式增强 PB8 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C_PB9    I2C_FASTMODEPLUS_PB9  // I2C 快速模式增强 PB9 引脚
#define HAL_SYSCFG_FASTMODEPLUS_I2C1       I2C_FASTMODEPLUS_I2C1  // I2C1 快速模式增强
#define HAL_SYSCFG_FASTMODEPLUS_I2C2       I2C_FASTMODEPLUS_I2C2  // I2C2 快速模式增强
#define HAL_SYSCFG_FASTMODEPLUS_I2C3       I2C_FASTMODEPLUS_I2C3  // I2C3 快速模式增强
#if defined(STM32G4)  // 如果定义了 STM32G4 系列芯片

#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SYSCFG_EnableIOSwitchBooster  // 启用 IO 模拟开关升压器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SYSCFG_DisableIOSwitchBooster  // 禁用 IO 模拟开关升压器
#define HAL_SYSCFG_EnableIOAnalogSwitchVDD        HAL_SYSCFG_EnableIOSwitchVDD  // 启用 IO 模拟开关 VDD
#define HAL_SYSCFG_DisableIOAnalogSwitchVDD       HAL_SYSCFG_DisableIOSwitchVDD  // 禁用 IO 模拟开关 VDD
#endif /* STM32G4 */

#if defined(STM32H5)  // 如果定义了 STM32H5 系列芯片
// 以下为 SYSCFG 中断定义别名
#define SYSCFG_IT_FPU_IOC         SBS_IT_FPU_IOC  // FPU 输入溢出中断
#define SYSCFG_IT_FPU_DZC         SBS_IT_FPU_DZC  // FPU 除零中断
#define SYSCFG_IT_FPU_UFC         SBS_IT_FPU_UFC  // FPU 下溢中断
#define SYSCFG_IT_FPU_OFC         SBS_IT_FPU_OFC  // FPU 上溢中断
#define SYSCFG_IT_FPU_IDC         SBS_IT_FPU_IDC  // FPU 输入反规范化中断
#define SYSCFG_IT_FPU_IXC         SBS_IT_FPU_IXC  // FPU 不精确中断

// 以下为 SYSCFG 断点配置别名
#define SYSCFG_BREAK_FLASH_ECC    SBS_BREAK_FLASH_ECC  // Flash ECC 错误断点
#define SYSCFG_BREAK_PVD          SBS_BREAK_PVD  // PVD 断点
#define SYSCFG_BREAK_SRAM_ECC     SBS_BREAK_SRAM_ECC  // SRAM ECC 错误断点
#define SYSCFG_BREAK_LOCKUP       SBS_BREAK_LOCKUP  // 锁定断点

// VREFBUF 电压等级定义别名
#define SYSCFG_VREFBUF_VOLTAGE_SCALE0   VREFBUF_VOLTAGE_SCALE0  // VREFBUF 电压等级0
#define SYSCFG_VREFBUF_VOLTAGE_SCALE1   VREFBUF_VOLTAGE_SCALE1  // VREFBUF 电压等级1
#define SYSCFG_VREFBUF_VOLTAGE_SCALE2   VREFBUF_VOLTAGE_SCALE2  // VREFBUF 电压等级2
#define SYSCFG_VREFBUF_VOLTAGE_SCALE3   VREFBUF_VOLTAGE_SCALE3  // VREFBUF 电压等级3

// VREFBUF 高阻抗配置别名
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_DISABLE   VREFBUF_HIGH_IMPEDANCE_DISABLE  // 禁用 VREFBUF 高阻抗模式
#define SYSCFG_VREFBUF_HIGH_IMPEDANCE_ENABLE    VREFBUF_HIGH_IMPEDANCE_ENABLE  // 启用 VREFBUF 高阻抗模式

// 快速模式增强引脚配置别名
#define SYSCFG_FASTMODEPLUS_PB6   SBS_FASTMODEPLUS_PB6  // PB6 快速模式增强
#define SYSCFG_FASTMODEPLUS_PB7   SBS_FASTMODEPLUS_PB7  // PB7 快速模式增强
#define SYSCFG_FASTMODEPLUS_PB8   SBS_FASTMODEPLUS_PB8  // PB8 快速模式增强
#define SYSCFG_FASTMODEPLUS_PB9   SBS_FASTMODEPLUS_PB9  // PB9 快速模式增强

// 以太网接口配置别名
#define SYSCFG_ETH_MII   SBS_ETH_MII  // 以太网 MII 接口
#define SYSCFG_ETH_RMII  SBS_ETH_RMII  // 以太网 RMII 接口
#define IS_SYSCFG_ETHERNET_CONFIG  IS_SBS_ETHERNET_CONFIG  // 检查以太网配置是否有效

// 存储器擦除标志别名
#define SYSCFG_MEMORIES_ERASE_FLAG_IPMEE   SBS_MEMORIES_ERASE_FLAG_IPMEE  // IPMEE 存储器擦除标志
#define SYSCFG_MEMORIES_ERASE_FLAG_MCLR    SBS_MEMORIES_ERASE_FLAG_MCLR  // MCLR 存储器擦除标志
#define IS_SYSCFG_MEMORIES_ERASE_FLAG      IS_SBS_MEMORIES_ERASE_FLAG  // 检查存储器擦除标志是否有效

// 代码配置检查别名
#define IS_SYSCFG_CODE_CONFIG IS_SBS_CODE_CONFIG  // 检查代码配置是否有效

// 安全配置别名
#define SYSCFG_MPU_NSEC   SBS_MPU_NSEC  // 非安全 MPU
#define SYSCFG_VTOR_NSEC  SBS_VTOR_NSEC  // 非安全 VTOR
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)  // 如果支持 CMSE（安全扩展）
#define SYSCFG_SAU              SBS_SAU  // SAU（安全属性单元）
#define SYSCFG_MPU_SEC          SBS_MPU_SEC  // 安全 MPU
#define SYSCFG_VTOR_AIRCR_SEC   SBS_VTOR_AIRCR_SEC  // 安全 VTOR 和 AIRCR
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL  // 锁定所有配置
#else
#define SYSCFG_LOCK_ALL         SBS_LOCK_ALL  // 锁定所有配置
#endif /* __ARM_FEATURE_CMSE */

// 时钟和模块配置别名
#define SYSCFG_CLK      SBS_CLK  // 时钟配置
#define SYSCFG_CLASSB   SBS_CLASSB  // CLASSB 配置
#define SYSCFG_FPU      SBS_FPU  // FPU 配置
#define SYSCFG_ALL      SBS_ALL  // 所有配置

// 安全和飞安全配置别名
#define SYSCFG_SEC      SBS_SEC  // 安全配置
#define SYSCFG_NSEC     SBS_NSEC  // 非安全配置

// HAL 宏别名：FPU 中断使能/禁用
#define __HAL_SYSCFG_FPU_INTERRUPT_ENABLE   __HAL_SBS_FPU_INTERRUPT_ENABLE  // 使能 FPU 中断
#define __HAL_SYSCFG_FPU_INTERRUPT_DISABLE  __HAL_SBS_FPU_INTERRUPT_DISABLE  // 禁用 FPU 中断

// HAL 宏别名：断点锁定配置
#define __HAL_SYSCFG_BREAK_ECC_LOCK        __HAL_SBS_BREAK_ECC_LOCK  // 锁定 ECC 断点
#define __HAL_SYSCFG_BREAK_LOCKUP_LOCK     __HAL_SBS_BREAK_LOCKUP_LOCK  // 锁定锁定断点
#define __HAL_SYSCFG_BREAK_PVD_LOCK        __HAL_SBS_BREAK_PVD_LOCK  // 锁定 PVD 断点
#define __HAL_SYSCFG_BREAK_SRAM_ECC_LOCK   __HAL_SBS_BREAK_SRAM_ECC_LOCK  // 锁定 SRAM ECC 断点

// HAL 宏别名：快速模式增强使能/禁用
#define __HAL_SYSCFG_FASTMODEPLUS_ENABLE   __HAL_SBS_FASTMODEPLUS_ENABLE  // 使能快速模式增强
#define __HAL_SYSCFG_FASTMODEPLUS_DISABLE  __HAL_SBS_FASTMODEPLUS_DISABLE  // 禁用快速模式增强

// HAL 宏别名：获取和清除存储器擦除状态
#define __HAL_SYSCFG_GET_MEMORIES_ERASE_STATUS    __HAL_SBS_GET_MEMORIES_ERASE_STATUS  // 获取存储器擦除状态
#define __HAL_SYSCFG_CLEAR_MEMORIES_ERASE_STATUS  __HAL_SBS_CLEAR_MEMORIES_ERASE_STATUS  // 清除存储器擦除状态

// 有效性检查宏别名
#define IS_SYSCFG_FPU_INTERRUPT    IS_SBS_FPU_INTERRUPT  // 检查 FPU 中断配置是否有效
#define IS_SYSCFG_BREAK_CONFIG     IS_SBS_BREAK_CONFIG  // 检查断点配置是否有效
#define IS_SYSCFG_VREFBUF_VOLTAGE_SCALE     IS_VREFBUF_VOLTAGE_SCALE  // 检查 VREFBUF 电压等级是否有效
#define IS_SYSCFG_VREFBUF_HIGH_IMPEDANCE    IS_VREFBUF_HIGH_IMPEDANCE  // 检查 VREFBUF 高阻抗模式是否有效
#define IS_SYSCFG_VREFBUF_TRIMMING  IS_VREFBUF_TRIMMING  // 检查 VREFBUF 微调是否有效
#define IS_SYSCFG_FASTMODEPLUS      IS_SBS_FASTMODEPLUS  // 检查快速模式增强配置是否有效
#define IS_SYSCFG_ITEMS_ATTRIBUTES  IS_SBS_ITEMS_ATTRIBUTES  // 检查项目属性是否有效
#define IS_SYSCFG_ATTRIBUTES        IS_SBS_ATTRIBUTES  // 检查属性是否有效
#define IS_SYSCFG_LOCK_ITEMS        IS_SBS_LOCK_ITEMS  // 检查锁定项目是否有效

// HAL 函数别名：VREFBUF 配置
#define HAL_SYSCFG_VREFBUF_VoltageScalingConfig   HAL_VREFBUF_VoltageScalingConfig  // 配置 VREFBUF 电压等级
#define HAL_SYSCFG_VREFBUF_HighImpedanceConfig    HAL_VREFBUF_HighImpedanceConfig  // 配置 VREFBUF 高阻抗模式
#define HAL_SYSCFG_VREFBUF_TrimmingConfig         HAL_VREFBUF_TrimmingConfig  // 配置 VREFBUF 微调
#define HAL_SYSCFG_EnableVREFBUF                  HAL_EnableVREFBUF  // 使能 VREFBUF
#define HAL_SYSCFG_DisableVREFBUF                 HAL_DisableVREFBUF  // 禁用 VREFBUF

// HAL 函数别名：IO 模拟开关和以太网接口选择
#define HAL_SYSCFG_EnableIOAnalogSwitchBooster    HAL_SBS_EnableIOAnalogSwitchBooster  // 使能 IO 模拟开关升压器
#define HAL_SYSCFG_DisableIOAnalogSwitchBooster   HAL_SBS_DisableIOAnalogSwitchBooster  // 禁用 IO 模拟开关升压器
#define HAL_SYSCFG_ETHInterfaceSelect             HAL_SBS_ETHInterfaceSelect  // 选择以太网接口

// HAL 函数别名：锁定配置
#define HAL_SYSCFG_Lock     HAL_SBS_Lock  // 锁定配置
#define HAL_SYSCFG_GetLock  HAL_SBS_GetLock  // 获取锁定状态

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)  // 如果支持 CMSE（安全扩展）
#define HAL_SYSCFG_ConfigAttributes     HAL_SBS_ConfigAttributes  // 配置属性
#define HAL_SYSCFG_GetConfigAttributes  HAL_SBS_GetConfigAttributes  // 获取配置属性
#endif /* __ARM_FEATURE_CMSE */

#endif /* STM32H5 */


/**
  * @}
  */


/** @defgroup LL_FMC_Aliased_Defines LL FMC Aliased Defines maintained for compatibility purpose
  * @{
  */
// LL FMC 别名定义，为保持兼容性而维护
#if defined(STM32L4) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)  // 如果定义了这些系列芯片
#define FMC_NAND_PCC_WAIT_FEATURE_DISABLE       FMC_NAND_WAIT_FEATURE_DISABLE  // 禁用 NAND PCC 等待功能
#define FMC_NAND_PCC_WAIT_FEATURE_ENABLE        FMC_NAND_WAIT_FEATURE_ENABLE  // 使能 NAND PCC 等待功能
#define FMC_NAND_PCC_MEM_BUS_WIDTH_8            FMC_NAND_MEM_BUS_WIDTH_8  // NAND 存储器总线宽度为 8 位
#define FMC_NAND_PCC_MEM_BUS_WIDTH_16           FMC_NAND_MEM_BUS_WIDTH_16  // NAND 存储器总线宽度为 16 位
#elif defined(STM32F1) || defined(STM32F2) || defined(STM32F3) || defined(STM32F4)  // 如果定义了这些系列芯片
#define FMC_NAND_WAIT_FEATURE_DISABLE           FMC_NAND_PCC_WAIT_FEATURE_DISABLE  // 禁用 NAND 等待功能
#define FMC_NAND_WAIT_FEATURE_ENABLE            FMC_NAND_PCC_WAIT_FEATURE_ENABLE  // 使能 NAND 等待功能
#define FMC_NAND_MEM_BUS_WIDTH_8                FMC_NAND_PCC_MEM_BUS_WIDTH_8  // NAND 存储器总线宽度为 8 位
#define FMC_NAND_MEM_BUS_WIDTH_16               FMC_NAND_PCC_MEM_BUS_WIDTH_16  // NAND 存储器总线宽度为 16 位
#endif
/**
  * @}
  */

/** @defgroup LL_FSMC_Aliased_Defines LL FSMC Aliased Defines maintained for legacy purpose
  * @{
  */
// LL FSMC 别名定义，为保持向后兼容性而维护

#define FSMC_NORSRAM_TYPEDEF                      FSMC_NORSRAM_TypeDef  // FSMC NOR/SRAM 类型定义别名
#define FSMC_NORSRAM_EXTENDED_TYPEDEF             FSMC_NORSRAM_EXTENDED_TypeDef  // FSMC NOR/SRAM 扩展类型定义别名
/**
  * @}
  */

/** @defgroup HAL_GPIO_Aliased_Macros HAL GPIO Aliased Macros maintained for legacy purpose
  * @{
  */
// HAL GPIO 别名宏定义，为保持向后兼容性而维护
#define GET_GPIO_SOURCE                           GPIO_GET_INDEX  // 获取 GPIO 源（索引）
#define GET_GPIO_INDEX                            GPIO_GET_INDEX  // 获取 GPIO 索引

#if defined(STM32F4)  // 如果定义了 STM32F4 系列芯片
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDIO  // 复用功能 12: SDMMC (SDIO)
#define GPIO_AF12_SDMMC1                          GPIO_AF12_SDIO  // 复用功能 12: SDMMC1 (SDIO)
#endif

#if defined(STM32F7)  // 如果定义了 STM32F7 系列芯片
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1  // 复用功能 12: SDIO (SDMMC1)
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1  // 复用功能 12: SDMMC (SDMMC1)
#endif

#if defined(STM32L4)  // 如果定义了 STM32L4 系列芯片
#define GPIO_AF12_SDIO                            GPIO_AF12_SDMMC1  // 复用功能 12: SDIO (SDMMC1)
#define GPIO_AF12_SDMMC                           GPIO_AF12_SDMMC1  // 复用功能 12: SDMMC (SDMMC1)
#endif

#if defined(STM32H7)  // 如果定义了 STM32H7 系列芯片
#define GPIO_AF7_SDIO1                            GPIO_AF7_SDMMC1  // 复用功能 7: SDIO1 (SDMMC1)
#define GPIO_AF8_SDIO1                            GPIO_AF8_SDMMC1  // 复用功能 8: SDIO1 (SDMMC1)
#define GPIO_AF12_SDIO1                           GPIO_AF12_SDMMC1  // 复用功能 12: SDIO1 (SDMMC1)
#define GPIO_AF9_SDIO2                            GPIO_AF9_SDMMC2  // 复用功能 9: SDIO2 (SDMMC2)
#define GPIO_AF10_SDIO2                           GPIO_AF10_SDMMC2  // 复用功能 10: SDIO2 (SDMMC2)
#define GPIO_AF11_SDIO2                           GPIO_AF11_SDMMC2  // 复用功能 11: SDIO2 (SDMMC2)

#if defined (STM32H743xx) || defined (STM32H753xx)  || defined (STM32H750xx) || defined (STM32H742xx) || \
    defined (STM32H745xx) || defined (STM32H755xx)  || defined (STM32H747xx) || defined (STM32H757xx)
#define GPIO_AF10_OTG2_HS  GPIO_AF10_OTG2_FS  // 复用功能 10: OTG2_HS (OTG2_FS)
#define GPIO_AF10_OTG1_FS  GPIO_AF10_OTG1_HS  // 复用功能 10: OTG1_FS (OTG1_HS)
#define GPIO_AF12_OTG2_FS  GPIO_AF12_OTG1_FS  // 复用功能 12: OTG2_FS (OTG1_FS)
#endif /*STM32H743xx || STM32H753xx || STM32H750xx || STM32H742xx || STM32H745xx || STM32H755xx || STM32H747xx || \
         STM32H757xx */
#endif /* STM32H7 */

// LPTIM 复用功能别名
#define GPIO_AF0_LPTIM                            GPIO_AF0_LPTIM1  // 复用功能 0: LPTIM (LPTIM1)
#define GPIO_AF1_LPTIM                            GPIO_AF1_LPTIM1  // 复用功能 1: LPTIM (LPTIM1)
#define GPIO_AF2_LPTIM                            GPIO_AF2_LPTIM1  // 复用功能 2: LPTIM (LPTIM1)

// GPIO 速度别名定义
#if defined(STM32L0) || defined(STM32L4) || defined(STM32F4) || defined(STM32F2) || defined(STM32F7) || \
    defined(STM32G4) || defined(STM32H7) || defined(STM32WB) || defined(STM32U5)
#define  GPIO_SPEED_LOW                           GPIO_SPEED_FREQ_LOW  // 低速
#define  GPIO_SPEED_MEDIUM                        GPIO_SPEED_FREQ_MEDIUM  // 中速
#define  GPIO_SPEED_FAST                          GPIO_SPEED_FREQ_HIGH  // 快速
#define  GPIO_SPEED_HIGH                          GPIO_SPEED_FREQ_VERY_HIGH  // 高速
#endif /* STM32L0 || STM32L4 || STM32F4 || STM32F2 || STM32F7 || STM32G4 || STM32H7 || STM32WB || STM32U5*/

#if defined(STM32L1)  // 如果定义了 STM32L1 系列芯片
#define  GPIO_SPEED_VERY_LOW    GPIO_SPEED_FREQ_LOW  // 非常低速
#define  GPIO_SPEED_LOW         GPIO_SPEED_FREQ_MEDIUM  // 低速
#define  GPIO_SPEED_MEDIUM      GPIO_SPEED_FREQ_HIGH  // 中速
#define  GPIO_SPEED_HIGH        GPIO_SPEED_FREQ_VERY_HIGH  // 高速
#endif /* STM32L1 */
#if defined(STM32F0) || defined(STM32F3) || defined(STM32F1)
#define  GPIO_SPEED_LOW    GPIO_SPEED_FREQ_LOW      /* GPIO低速模式别名 */
#define  GPIO_SPEED_MEDIUM GPIO_SPEED_FREQ_MEDIUM   /* GPIO中速模式别名 */
#define  GPIO_SPEED_HIGH   GPIO_SPEED_FREQ_HIGH     /* GPIO高速模式别名 */
#endif /* 针对STM32F0、STM32F3或STM32F1系列 */

#define GPIO_AF6_DFSDM                            GPIO_AF6_DFSDM1  /* DFSDM1模块的AF6复用功能别名 */

#if defined(STM32U5) || defined(STM32H5)
#define GPIO_AF0_RTC_50Hz                         GPIO_AF0_RTC_50HZ  /* RTC 50Hz时钟的AF0复用功能别名 */
#endif /* 针对STM32U5或STM32H5系列 */
#if defined(STM32U5)
#define GPIO_AF0_S2DSTOP                          GPIO_AF0_SRDSTOP   /* 停止模式下的安全域复位AF0别名 */
#define GPIO_AF11_LPGPIO                          GPIO_AF11_LPGPIO1  /* 低功耗GPIO的AF11复用功能别名 */
#endif /* 针对STM32U5系列 */

#if defined(STM32WBA)
#define GPIO_AF11_RF_ANTSW0    GPIO_AF11_RF  /* RF天线开关0的AF11复用功能别名 */
#define GPIO_AF11_RF_ANTSW1    GPIO_AF11_RF  /* RF天线开关1的AF11复用功能别名 */
#define GPIO_AF11_RF_ANTSW2    GPIO_AF11_RF  /* RF天线开关2的AF11复用功能别名 */
#define GPIO_AF11_RF_IO1       GPIO_AF11_RF  /* RF IO1的AF11复用功能别名 */
#define GPIO_AF11_RF_IO2       GPIO_AF11_RF  /* RF IO2的AF11复用功能别名 */
#define GPIO_AF11_RF_IO3       GPIO_AF11_RF  /* RF IO3的AF11复用功能别名 */
#define GPIO_AF11_RF_IO4       GPIO_AF11_RF  /* RF IO4的AF11复用功能别名 */
#define GPIO_AF11_RF_IO5       GPIO_AF11_RF  /* RF IO5的AF11复用功能别名 */
#define GPIO_AF11_RF_IO6       GPIO_AF11_RF  /* RF IO6的AF11复用功能别名 */
#define GPIO_AF11_RF_IO7       GPIO_AF11_RF  /* RF IO7的AF11复用功能别名 */
#define GPIO_AF11_RF_IO8       GPIO_AF11_RF  /* RF IO8的AF11复用功能别名 */
#define GPIO_AF11_RF_IO9       GPIO_AF11_RF  /* RF IO9的AF11复用功能别名 */
#endif /* 针对STM32WBA系列 */
/**
  * @}
  */

/** @defgroup HAL_GTZC_Aliased_Defines HAL GTZC 别名定义，用于保持向后兼容性
  * @{
  */
#if defined(STM32U5)
#define GTZC_PERIPH_DCMI                      GTZC_PERIPH_DCMI_PSSI  /* DCMI外设的GTZC别名 */
#define GTZC_PERIPH_LTDC                      GTZC_PERIPH_LTDCUSB    /* LTDC外设的GTZC别名 */
#endif /* 针对STM32U5系列 */
#if defined(STM32H5)
#define GTZC_PERIPH_DAC12                     GTZC_PERIPH_DAC1       /* DAC1外设的GTZC别名 */
#define GTZC_PERIPH_ADC12                     GTZC_PERIPH_ADC        /* ADC外设的GTZC别名 */
#define GTZC_PERIPH_USBFS                     GTZC_PERIPH_USB        /* USB外设的GTZC别名 */
#endif /* 针对STM32H5系列 */
#if defined(STM32H5) || defined(STM32U5)
#define GTZC_MCPBB_NB_VCTR_REG_MAX            GTZC_MPCBB_NB_VCTR_REG_MAX        /* MPCBB向量寄存器最大数量的别名 */
#define GTZC_MCPBB_NB_LCK_VCTR_REG_MAX        GTZC_MPCBB_NB_LCK_VCTR_REG_MAX    /* MPCBB锁定向量寄存器最大数量的别名 */
#define GTZC_MCPBB_SUPERBLOCK_UNLOCKED        GTZC_MPCBB_SUPERBLOCK_UNLOCKED    /* MPCBB超级块未锁定状态的别名 */
#define GTZC_MCPBB_SUPERBLOCK_LOCKED          GTZC_MPCBB_SUPERBLOCK_LOCKED      /* MPCBB超级块锁定状态的别名 */
#define GTZC_MCPBB_BLOCK_NSEC                 GTZC_MPCBB_BLOCK_NSEC             /* MPCBB非安全块的别名 */
#define GTZC_MCPBB_BLOCK_SEC                  GTZC_MPCBB_BLOCK_SEC              /* MPCBB安全块的别名 */
#define GTZC_MCPBB_BLOCK_NPRIV                GTZC_MPCBB_BLOCK_NPRIV            /* MPCBB非特权块的别名 */
#define GTZC_MCPBB_BLOCK_PRIV                 GTZC_MPCBB_BLOCK_PRIV             /* MPCBB特权块的别名 */
#define GTZC_MCPBB_LOCK_OFF                   GTZC_MPCBB_LOCK_OFF               /* MPCBB锁定关闭的别名 */
#define GTZC_MCPBB_LOCK_ON                    GTZC_MPCBB_LOCK_ON                /* MPCBB锁定开启的别名 */
#endif /* 针对STM32H5或STM32U5系列 */
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Macros HAL HRTIM 别名宏，用于保持向后兼容性
  * @{
  */
#define HRTIM_TIMDELAYEDPROTECTION_DISABLED           HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DISABLED            /* HRTIM延迟保护禁用模式的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_EEV6    /* HRTIM输出1延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_EEV6    /* HRTIM输出2延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV6    /* HRTIM双输出延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV68     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV6       /* HRTIM平衡延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_DEEV7   /* HRTIM输出1延迟保护模式（事件7/9）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_DEEV7   /* HRTIM输出2延迟保护模式（事件7/9）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV79  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV7    /* HRTIM双输出延迟保护模式（事件7/9）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV79     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV7       /* HRTIM平衡延迟保护模式（事件7/9）的别名 */

#define __HAL_HRTIM_SetCounter        __HAL_HRTIM_SETCOUNTER        /* 设置HRTIM计数器的别名 */
#define __HAL_HRTIM_GetCounter        __HAL_HRTIM_GETCOUNTER        /* 获取HRTIM计数器的别名 */
#define __HAL_HRTIM_SetPeriod         __HAL_HRTIM_SETPERIOD         /* 设置HRTIM周期的别名 */
#define __HAL_HRTIM_GetPeriod         __HAL_HRTIM_GETPERIOD         /* 获取HRTIM周期的别名 */
#define __HAL_HRTIM_SetClockPrescaler __HAL_HRTIM_SETCLOCKPRESCALER /* 设置HRTIM时钟预分频器的别名 */
#define __HAL_HRTIM_GetClockPrescaler __HAL_HRTIM_GETCLOCKPRESCALER /* 获取HRTIM时钟预分频器的别名 */
#define __HAL_HRTIM_SetCompare        __HAL_HRTIM_SETCOMPARE        /* 设置HRTIM比较值的别名 */
#define __HAL_HRTIM_GetCompare        __HAL_HRTIM_GETCOMPARE        /* 获取HRTIM比较值的别名 */

#if defined(STM32G4)
#define HAL_HRTIM_ExternalEventCounterConfig    HAL_HRTIM_ExtEventCounterConfig     /* 外部事件计数器配置函数的别名 */
#define HAL_HRTIM_ExternalEventCounterEnable    HAL_HRTIM_ExtEventCounterEnable     /* 启用外部事件计数器的别名 */
#define HAL_HRTIM_ExternalEventCounterDisable   HAL_HRTIM_ExtEventCounterDisable    /* 禁用外部事件计数器的别名 */
#define HAL_HRTIM_ExternalEventCounterReset     HAL_HRTIM_ExtEventCounterReset      /* 复位外部事件计数器的别名 */
#define HRTIM_TIMEEVENT_A                       HRTIM_EVENTCOUNTER_A                /* 事件计数器A的别名 */
#define HRTIM_TIMEEVENT_B                       HRTIM_EVENTCOUNTER_B                /* 事件计数器B的别名 */
#define HRTIM_TIMEEVENTRESETMODE_UNCONDITIONAL  HRTIM_EVENTCOUNTER_RSTMODE_UNCONDITIONAL  /* 无条件复位模式的别名 */
#define HRTIM_TIMEEVENTRESETMODE_CONDITIONAL    HRTIM_EVENTCOUNTER_RSTMODE_CONDITIONAL    /* 条件复位模式的别名 */
#endif /* 针对STM32G4系列 */

#if defined(STM32H7)
#define HRTIM_OUTPUTSET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器A事件1到定时器B比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器A事件2到定时器B比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器A事件3到定时器C比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器A事件4到定时器C比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器A事件5到定时器D比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器A事件6到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器A事件7到定时器E比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器A事件8到定时器E比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器A事件9到定时器F比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器B事件1到定时器A比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器B事件2到定时器A比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器B事件3到定时器C比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器B事件4到定时器C比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器B事件5到定时器D比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器B事件6到定时器D比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器B事件7到定时器E比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器B事件8到定时器E比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器B事件9到定时器F比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器C事件1到定时器A比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器C事件2到定时器A比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器C事件3到定时器B比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器C事件4到定时器B比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器C事件5到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器C事件6到定时器D比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器C事件7到定时器E比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器C事件8到定时器E比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器C事件9到定时器F比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器D事件1到定时器A比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器D事件2到定时器A比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器D事件3到定时器B比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器D事件4到定时器B比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器D事件5到定时器C比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器D事件6到定时器E比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器D事件7到定时器E比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器D事件8到定时器F比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器D事件9到定时器F比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器E事件1到定时器A比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器E事件2到定时器B比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器E事件3到定时器B比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器E事件4到定时器C比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器E事件5到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器E事件6到定时器D比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器E事件7到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器E事件8到定时器F比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器E事件9到定时器F比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器F事件1到定时器A比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器F事件2到定时器B比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器F事件3到定时器B比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器F事件4到定时器C比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器F事件5到定时器C比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器F事件6到定时器D比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器F事件7到定时器D比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器F事件8到定时器E比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器F事件9到定时器E比较3的输出设置别名 */
#define HRTIM_OUTPUTRESET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1    /* 定时器A事件1与定时器B比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2    /* 定时器A事件2与定时器B比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3    /* 定时器A事件3与定时器C比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4    /* 定时器A事件4与定时器C比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5    /* 定时器A事件5与定时器D比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6    /* 定时器A事件6与定时器D比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7    /* 定时器A事件7与定时器E比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8    /* 定时器A事件8与定时器E比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9    /* 定时器A事件9与定时器F比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    /* 定时器B事件1与定时器A比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2    /* 定时器B事件2与定时器A比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3    /* 定时器B事件3与定时器C比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4    /* 定时器B事件4与定时器C比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5    /* 定时器B事件5与定时器D比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6    /* 定时器B事件6与定时器D比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7    /* 定时器B事件7与定时器E比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8    /* 定时器B事件8与定时器E比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9    /* 定时器B事件9与定时器F比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    /* 定时器C事件1与定时器A比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2    /* 定时器C事件2与定时器A比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3    /* 定时器C事件3与定时器B比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4    /* 定时器C事件4与定时器B比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5    /* 定时器C事件5与定时器D比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6    /* 定时器C事件6与定时器D比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7    /* 定时器C事件7与定时器E比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8    /* 定时器C事件8与定时器E比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9    /* 定时器C事件9与定时器F比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    /* 定时器D事件1与定时器A比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2    /* 定时器D事件2与定时器A比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3    /* 定时器D事件3与定时器B比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4    /* 定时器D事件4与定时器B比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5    /* 定时器D事件5与定时器C比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6    /* 定时器D事件6与定时器E比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7    /* 定时器D事件7与定时器E比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8    /* 定时器D事件8与定时器F比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9    /* 定时器D事件9与定时器F比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1    /* 定时器E事件1与定时器A比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2    /* 定时器E事件2与定时器B比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3    /* 定时器E事件3与定时器B比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4    /* 定时器E事件4与定时器C比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5    /* 定时器E事件5与定时器D比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6    /* 定时器E事件6与定时器D比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7    /* 定时器E事件7与定时器D比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8    /* 定时器E事件8与定时器F比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9    /* 定时器E事件9与定时器F比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1    /* 定时器F事件1与定时器A比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2    /* 定时器F事件2与定时器B比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3    /* 定时器F事件3与定时器B比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4    /* 定时器F事件4与定时器C比较器1对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5    /* 定时器F事件5与定时器C比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6    /* 定时器F事件6与定时器D比较器3对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7    /* 定时器F事件7与定时器D比较器4对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8    /* 定时器F事件8与定时器E比较器2对应的输出复位设置 */
#define HRTIM_OUTPUTRESET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9    /* 定时器F事件9与定时器E比较器3对应的输出复位设置 */
#endif /* STM32H7 */

#if defined(STM32F3)
/** @brief 定义与外部事件关联的可用源常量。
  */
#define HRTIM_EVENTSRC_1              (0x00000000U)          /* 事件源1 */
#define HRTIM_EVENTSRC_2              (HRTIM_EECR1_EE1SRC_0) /* 事件源2 */
#define HRTIM_EVENTSRC_3              (HRTIM_EECR1_EE1SRC_1) /* 事件源3 */
#define HRTIM_EVENTSRC_4              (HRTIM_EECR1_EE1SRC_1 | HRTIM_EECR1_EE1SRC_0) /* 事件源4 */

/** @brief 定义DLL校准周期的常量（单位为微秒）
  */
#define HRTIM_CALIBRATIONRATE_7300             0x00000000U   /* 7300微秒校准周期 */
#define HRTIM_CALIBRATIONRATE_910              (HRTIM_DLLCR_CALRTE_0) /* 910微秒校准周期 */
#define HRTIM_CALIBRATIONRATE_114              (HRTIM_DLLCR_CALRTE_1) /* 114微秒校准周期 */
#define HRTIM_CALIBRATIONRATE_14               (HRTIM_DLLCR_CALRTE_1 | HRTIM_DLLCR_CALRTE_0) /* 14微秒校准周期 */

#endif /* STM32F3 */
/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Defines 为保持向后兼容而维护的HAL I2C别名定义
  * @{
  */
#define I2C_DUALADDRESS_DISABLED                I2C_DUALADDRESS_DISABLE     /* 禁用双地址模式 */
#define I2C_DUALADDRESS_ENABLED                 I2C_DUALADDRESS_ENABLE      /* 启用双地址模式 */
#define I2C_GENERALCALL_DISABLED                I2C_GENERALCALL_DISABLE     /* 禁用广播呼叫 */
#define I2C_GENERALCALL_ENABLED                 I2C_GENERALCALL_ENABLE      /* 启用广播呼叫 */
#define I2C_NOSTRETCH_DISABLED                  I2C_NOSTRETCH_DISABLE       /* 禁用时钟拉伸 */
#define I2C_NOSTRETCH_ENABLED                   I2C_NOSTRETCH_ENABLE        /* 启用时钟拉伸 */
#define I2C_ANALOGFILTER_ENABLED                I2C_ANALOGFILTER_ENABLE     /* 启用模拟滤波器 */
#define I2C_ANALOGFILTER_DISABLED               I2C_ANALOGFILTER_DISABLE    /* 禁用模拟滤波器 */
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F3) || defined(STM32G0) || defined(STM32L4) || \
    defined(STM32L1) || defined(STM32F7)
#define HAL_I2C_STATE_MEM_BUSY_TX               HAL_I2C_STATE_BUSY_TX       /* 存储器繁忙发送状态 */
#define HAL_I2C_STATE_MEM_BUSY_RX               HAL_I2C_STATE_BUSY_RX       /* 存储器繁忙接收状态 */
#define HAL_I2C_STATE_MASTER_BUSY_TX            HAL_I2C_STATE_BUSY_TX       /* 主设备繁忙发送状态 */
#define HAL_I2C_STATE_MASTER_BUSY_RX            HAL_I2C_STATE_BUSY_RX       /* 主设备繁忙接收状态 */
#define HAL_I2C_STATE_SLAVE_BUSY_TX             HAL_I2C_STATE_BUSY_TX       /* 从设备繁忙发送状态 */
#define HAL_I2C_STATE_SLAVE_BUSY_RX             HAL_I2C_STATE_BUSY_RX       /* 从设备繁忙接收状态 */
#endif
/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Defines 为保持向后兼容而维护的HAL IRDA别名定义
  * @{
  */
#define IRDA_ONE_BIT_SAMPLE_DISABLED            IRDA_ONE_BIT_SAMPLE_DISABLE   /* 禁用单比特采样 */
#define IRDA_ONE_BIT_SAMPLE_ENABLED             IRDA_ONE_BIT_SAMPLE_ENABLE    /* 启用单比特采样 */

/**
  * @}
  */

/** @defgroup HAL_IWDG_Aliased_Defines 为保持向后兼容而维护的HAL IWDG别名定义
  * @{
  */
#define KR_KEY_RELOAD                   IWDG_KEY_RELOAD                     /* 重载密钥 */
#define KR_KEY_ENABLE                   IWDG_KEY_ENABLE                     /* 使能密钥 */
#define KR_KEY_EWA                      IWDG_KEY_WRITE_ACCESS_ENABLE        /* 写访问使能密钥 */
#define KR_KEY_DWA                      IWDG_KEY_WRITE_ACCESS_DISABLE       /* 写访问禁用密钥 */
/**
  * @}
  */

/** @defgroup HAL_LPTIM_Aliased_Defines 为保持向后兼容而维护的HAL LPTIM别名定义
  * @{
  */

#define LPTIM_CLOCKSAMPLETIME_DIRECTTRANSISTION LPTIM_CLOCKSAMPLETIME_DIRECTTRANSITION    /* 时钟采样时间：直接过渡 */
#define LPTIM_CLOCKSAMPLETIME_2TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_2TRANSITIONS        /* 时钟采样时间：2次过渡 */
#define LPTIM_CLOCKSAMPLETIME_4TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_4TRANSITIONS        /* 时钟采样时间：4次过渡 */
#define LPTIM_CLOCKSAMPLETIME_8TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_8TRANSITIONS        /* 时钟采样时间：8次过渡 */

#define LPTIM_CLOCKPOLARITY_RISINGEDGE          LPTIM_CLOCKPOLARITY_RISING                /* 时钟极性：上升沿 */
#define LPTIM_CLOCKPOLARITY_FALLINGEDGE         LPTIM_CLOCKPOLARITY_FALLING               /* 时钟极性：下降沿 */
#define LPTIM_CLOCKPOLARITY_BOTHEDGES           LPTIM_CLOCKPOLARITY_RISING_FALLING        /* 时钟极性：双边沿 */

#define LPTIM_TRIGSAMPLETIME_DIRECTTRANSISTION  LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION     /* 触发采样时间：直接过渡 */
#define LPTIM_TRIGSAMPLETIME_2TRANSISTIONS      LPTIM_TRIGSAMPLETIME_2TRANSITIONS         /* 触发采样时间：2次过渡 */
#define LPTIM_TRIGSAMPLETIME_4TRANSISTIONS      LPTIM_TRIGSAMPLETIME_4TRANSITIONS         /* 触发采样时间：4次过渡 */
#define LPTIM_TRIGSAMPLETIME_8TRANSISTIONS      LPTIM_TRIGSAMPLETIME_8TRANSITIONS         /* 触发采样时间：8次过渡 */

/* 以下3个定义也曾出现在lptim.h的临时版本中 */
/* 为了保持兼容性，需要将它们重命名为正确的名称 */
#define LPTIM_TRIGSAMPLETIME_2TRANSITION        LPTIM_TRIGSAMPLETIME_2TRANSITIONS         /* 触发采样时间：2次过渡（旧名称） */
#define LPTIM_TRIGSAMPLETIME_4TRANSITION        LPTIM_TRIGSAMPLETIME_4TRANSITIONS         /* 触发采样时间：4次过渡（旧名称） */
#define LPTIM_TRIGSAMPLETIME_8TRANSITION        LPTIM_TRIGSAMPLETIME_8TRANSITIONS         /* 触发采样时间：8次过渡（旧名称） */


/** @defgroup HAL_LPTIM_Aliased_Defines 为保持向后兼容而维护的HAL LPTIM别名定义
  * @{
  */
#define HAL_LPTIM_ReadCompare      HAL_LPTIM_ReadCapturedValue             /* 读取比较值（旧名称） */
/**
  * @}
  */

#if defined(STM32U5)
#define LPTIM_ISR_CC1        LPTIM_ISR_CC1IF                               /* 捕获/比较1中断标志 */
#define LPTIM_ISR_CC2        LPTIM_ISR_CC2IF                               /* 捕获/比较2中断标志 */
#define LPTIM_CHANNEL_ALL    0x00000000U                                    /* 所有通道 */
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_NAND_Aliased_Defines 为保持向后兼容而维护的HAL NAND别名定义
  * @{
  */
#define HAL_NAND_Read_Page              HAL_NAND_Read_Page_8b              /* 读取页（8位数据总线） */
#define HAL_NAND_Write_Page             HAL_NAND_Write_Page_8b             /* 写入页（8位数据总线） */
#define HAL_NAND_Read_SpareArea         HAL_NAND_Read_SpareArea_8b         /* 读取备用区（8位数据总线） */
#define HAL_NAND_Write_SpareArea        HAL_NAND_Write_SpareArea_8b        /* 写入备用区（8位数据总线） */

#define NAND_AddressTypedef             NAND_AddressTypeDef                /* NAND地址类型定义 */

#define __ARRAY_ADDRESS                 ARRAY_ADDRESS                      /* 阵列地址 */
#define __ADDR_1st_CYCLE                ADDR_1ST_CYCLE                     /* 地址第一周期 */
#define __ADDR_2nd_CYCLE                ADDR_2ND_CYCLE                     /* 地址第二周期 */
#define __ADDR_3rd_CYCLE                ADDR_3RD_CYCLE                     /* 地址第三周期 */
#define __ADDR_4th_CYCLE                ADDR_4TH_CYCLE                     /* 地址第四周期 */
/**
  * @}
  */

/** @defgroup HAL_NOR_Aliased_Defines 为保持向后兼容而维护的HAL NOR别名定义
  * @{
  */
#define NOR_StatusTypedef              HAL_NOR_StatusTypeDef               /* NOR状态类型定义 */
#define NOR_SUCCESS                    HAL_NOR_STATUS_SUCCESS              /* NOR操作成功 */
#define NOR_ONGOING                    HAL_NOR_STATUS_ONGOING              /* NOR操作进行中 */
#define NOR_ERROR                      HAL_NOR_STATUS_ERROR                /* NOR操作错误 */
#define NOR_TIMEOUT                    HAL_NOR_STATUS_TIMEOUT              /* NOR操作超时 */

#define __NOR_WRITE                    NOR_WRITE                           /* NOR写入 */
#define __NOR_ADDR_SHIFT               NOR_ADDR_SHIFT                      /* NOR地址偏移 */
/**
  * @}
  */

/** @defgroup HAL_OPAMP_Aliased_Defines 为保持向后兼容而维护的HAL OPAMP别名定义
  * @{
  */

#define OPAMP_NONINVERTINGINPUT_VP0           OPAMP_NONINVERTINGINPUT_IO0  /* 运放同相输入VP0 */
#define OPAMP_NONINVERTINGINPUT_VP1           OPAMP_NONINVERTINGINPUT_IO1  /* 运放同相输入VP1 */
#define OPAMP_NONINVERTINGINPUT_VP2           OPAMP_NONINVERTINGINPUT_IO2  /* 运放同相输入VP2 */
#define OPAMP_NONINVERTINGINPUT_VP3           OPAMP_NONINVERTINGINPUT_IO3  /* 运放同相输入VP3 */
#define OPAMP_SEC_NONINVERTINGINPUT_VP0       OPAMP_SEC_NONINVERTINGINPUT_IO0  ///< 第二运放同相输入VP0，映射到IO0引脚
#define OPAMP_SEC_NONINVERTINGINPUT_VP1       OPAMP_SEC_NONINVERTINGINPUT_IO1  ///< 第二运放同相输入VP1，映射到IO1引脚
#define OPAMP_SEC_NONINVERTINGINPUT_VP2       OPAMP_SEC_NONINVERTINGINPUT_IO2  ///< 第二运放同相输入VP2，映射到IO2引脚
#define OPAMP_SEC_NONINVERTINGINPUT_VP3       OPAMP_SEC_NONINVERTINGINPUT_IO3  ///< 第二运放同相输入VP3，映射到IO3引脚

#define OPAMP_INVERTINGINPUT_VM0              OPAMP_INVERTINGINPUT_IO0         ///< 运放反相输入VM0，映射到IO0引脚
#define OPAMP_INVERTINGINPUT_VM1              OPAMP_INVERTINGINPUT_IO1         ///< 运放反相输入VM1，映射到IO1引脚

#define IOPAMP_INVERTINGINPUT_VM0             OPAMP_INVERTINGINPUT_IO0         ///< 内部运放反相输入VM0，映射到IO0引脚
#define IOPAMP_INVERTINGINPUT_VM1             OPAMP_INVERTINGINPUT_IO1         ///< 内部运放反相输入VM1，映射到IO1引脚

#define OPAMP_SEC_INVERTINGINPUT_VM0          OPAMP_SEC_INVERTINGINPUT_IO0     ///< 第二运放反相输入VM0，映射到IO0引脚
#define OPAMP_SEC_INVERTINGINPUT_VM1          OPAMP_SEC_INVERTINGINPUT_IO1     ///< 第二运放反相输入VM1，映射到IO1引脚

#define OPAMP_INVERTINGINPUT_VINM             OPAMP_SEC_INVERTINGINPUT_IO1     ///< 运放反相输入VINM，映射到第二运放反相输入IO1引脚

#define OPAMP_PGACONNECT_NO                   OPAMP_PGA_CONNECT_INVERTINGINPUT_NO   ///< PGA（可编程增益放大器）不连接反相输入
#define OPAMP_PGACONNECT_VM0                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO0  ///< PGA连接反相输入VM0
#define OPAMP_PGACONNECT_VM1                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO1  ///< PGA连接反相输入VM1

#if defined(STM32L1) || defined(STM32L4) || defined(STM32L5) || defined(STM32H7) || defined(STM32G4) || defined(STM32U5)
#define HAL_OPAMP_MSP_INIT_CB_ID       HAL_OPAMP_MSPINIT_CB_ID                 ///< 运放MSP初始化回调ID
#define HAL_OPAMP_MSP_DEINIT_CB_ID     HAL_OPAMP_MSPDEINIT_CB_ID               ///< 运放MSP反初始化回调ID
#endif

#if defined(STM32L4) || defined(STM32L5)
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALPOWER     ///< 运放正常功耗模式
#elif defined(STM32G4)
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALSPEED     ///< 运放正常速度模式
#endif

/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Defines HAL I2S Aliased Defines maintained for legacy purpose
  * @{
  */
#define I2S_STANDARD_PHILLIPS      I2S_STANDARD_PHILIPS                       ///< I2S标准：飞利浦标准（旧版拼写，为兼容性保留）

#if defined(STM32H7)
#define I2S_IT_TXE               I2S_IT_TXP                                   ///< I2S发送中断（旧版定义，映射到发送完成中断）
#define I2S_IT_RXNE              I2S_IT_RXP                                   ///< I2S接收中断（旧版定义，映射到接收完成中断）

#define I2S_FLAG_TXE             I2S_FLAG_TXP                                 ///< I2S发送标志（旧版定义，映射到发送完成标志）
#define I2S_FLAG_RXNE            I2S_FLAG_RXP                                 ///< I2S接收标志（旧版定义，映射到接收完成标志）
#endif

#if defined(STM32F7)
#define I2S_CLOCK_SYSCLK           I2S_CLOCK_PLL                              ///< I2S时钟源：系统时钟（旧版定义，映射到PLL时钟）
#endif
/**
  * @}
  */

/** @defgroup HAL_PCCARD_Aliased_Defines HAL PCCARD Aliased Defines maintained for legacy purpose
  * @{
  */

/* Compact Flash-ATA寄存器描述 */
#define CF_DATA                       ATA_DATA                                 ///< CF-ATA数据寄存器
#define CF_SECTOR_COUNT               ATA_SECTOR_COUNT                         ///< CF-ATA扇区计数寄存器
#define CF_SECTOR_NUMBER              ATA_SECTOR_NUMBER                        ///< CF-ATA扇区号寄存器
#define CF_CYLINDER_LOW               ATA_CYLINDER_LOW                         ///< CF-ATA柱面低字节寄存器
#define CF_CYLINDER_HIGH              ATA_CYLINDER_HIGH                        ///< CF-ATA柱面高字节寄存器
#define CF_CARD_HEAD                  ATA_CARD_HEAD                            ///< CF-ATA卡头寄存器
#define CF_STATUS_CMD                 ATA_STATUS_CMD                           ///< CF-ATA状态/命令寄存器
#define CF_STATUS_CMD_ALTERNATE       ATA_STATUS_CMD_ALTERNATE                 ///< CF-ATA备用状态/命令寄存器
#define CF_COMMON_DATA_AREA           ATA_COMMON_DATA_AREA                     ///< CF-ATA公共数据区域

/* Compact Flash-ATA命令 */
#define CF_READ_SECTOR_CMD            ATA_READ_SECTOR_CMD                     ///< CF-ATA读扇区命令
#define CF_WRITE_SECTOR_CMD           ATA_WRITE_SECTOR_CMD                    ///< CF-ATA写扇区命令
#define CF_ERASE_SECTOR_CMD           ATA_ERASE_SECTOR_CMD                    ///< CF-ATA擦除扇区命令
#define CF_IDENTIFY_CMD               ATA_IDENTIFY_CMD                        ///< CF-ATA识别命令

#define PCCARD_StatusTypedef          HAL_PCCARD_StatusTypeDef                ///< PCCARD状态类型定义（旧版定义，为兼容性保留）
#define PCCARD_SUCCESS                HAL_PCCARD_STATUS_SUCCESS               ///< PCCARD操作成功（旧版定义）
#define PCCARD_ONGOING                HAL_PCCARD_STATUS_ONGOING               ///< PCCARD操作进行中（旧版定义）
#define PCCARD_ERROR                  HAL_PCCARD_STATUS_ERROR                 ///< PCCARD操作错误（旧版定义）
#define PCCARD_TIMEOUT                HAL_PCCARD_STATUS_TIMEOUT               ///< PCCARD操作超时（旧版定义）
/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Defines HAL RTC Aliased Defines maintained for legacy purpose
  * @{
  */

#define FORMAT_BIN                  RTC_FORMAT_BIN                            ///< RTC格式：二进制格式（旧版定义）
#define FORMAT_BCD                  RTC_FORMAT_BCD                            ///< RTC格式：BCD格式（旧版定义）

#define RTC_ALARMSUBSECONDMASK_None     RTC_ALARMSUBSECONDMASK_NONE            ///< RTC报警子秒掩码：无掩码（旧版定义）
#define RTC_TAMPERERASEBACKUP_DISABLED  RTC_TAMPER_ERASE_BACKUP_DISABLE        ///< RTC篡改检测擦除备份寄存器：禁用（旧版定义）
#define RTC_TAMPERMASK_FLAG_DISABLED    RTC_TAMPERMASK_FLAG_DISABLE            ///< RTC篡改检测掩码标志：禁用（旧版定义）
#define RTC_TAMPERMASK_FLAG_ENABLED     RTC_TAMPERMASK_FLAG_ENABLE             ///< RTC篡改检测掩码标志：使能（旧版定义）

#define RTC_MASKTAMPERFLAG_DISABLED     RTC_TAMPERMASK_FLAG_DISABLE            ///< RTC掩码篡改标志：禁用（旧版定义）
#define RTC_MASKTAMPERFLAG_ENABLED      RTC_TAMPERMASK_FLAG_ENABLE             ///< RTC掩码篡改标志：使能（旧版定义）
#define RTC_TAMPERERASEBACKUP_ENABLED   RTC_TAMPER_ERASE_BACKUP_ENABLE         ///< RTC篡改检测擦除备份寄存器：使能（旧版定义）
#define RTC_TAMPER1_2_INTERRUPT         RTC_ALL_TAMPER_INTERRUPT               ///< RTC篡改检测1和2中断（旧版定义，映射到所有篡改中断）
#define RTC_TAMPER1_2_3_INTERRUPT       RTC_ALL_TAMPER_INTERRUPT               ///< RTC篡改检测1、2和3中断（旧版定义，映射到所有篡改中断）

#define RTC_TIMESTAMPPIN_PC13  RTC_TIMESTAMPPIN_DEFAULT                        ///< RTC时间戳引脚：默认引脚PC13（旧版定义）
#define RTC_TIMESTAMPPIN_PA0   RTC_TIMESTAMPPIN_POS1                           ///< RTC时间戳引脚：位置1引脚PA0（旧版定义）
#define RTC_TIMESTAMPPIN_PI8   RTC_TIMESTAMPPIN_POS1                           ///< RTC时间戳引脚：位置1引脚PI8（旧版定义）
#define RTC_TIMESTAMPPIN_PC1   RTC_TIMESTAMPPIN_POS2                           ///< RTC时间戳引脚：位置2引脚PC1（旧版定义）

#define RTC_OUTPUT_REMAP_PC13  RTC_OUTPUT_REMAP_NONE                           ///< RTC输出重映射：无重映射（PC13）（旧版定义）
#define RTC_OUTPUT_REMAP_PB14  RTC_OUTPUT_REMAP_POS1                           ///< RTC输出重映射：位置1（PB14）（旧版定义）
#define RTC_OUTPUT_REMAP_PB2   RTC_OUTPUT_REMAP_POS1                           ///< RTC输出重映射：位置1（PB2）（旧版定义）

#define RTC_TAMPERPIN_PC13 RTC_TAMPERPIN_DEFAULT                               ///< RTC篡改检测引脚：默认引脚PC13（旧版定义）
#define RTC_TAMPERPIN_PA0  RTC_TAMPERPIN_POS1                                  ///< RTC篡改检测引脚：位置1引脚PA0（旧版定义）
#define RTC_TAMPERPIN_PI8  RTC_TAMPERPIN_POS1                                  ///< RTC篡改检测引脚：位置1引脚PI8（旧版定义）

#if defined(STM32H5) || defined(STM32H7RS)
#define TAMP_SECRETDEVICE_ERASE_NONE        TAMP_DEVICESECRETS_ERASE_NONE      ///< 篡改检测秘密设备擦除：无擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_BKP_SRAM    TAMP_DEVICESECRETS_ERASE_BKPSRAM   ///< 篡改检测秘密设备擦除：备份SRAM擦除（旧版定义）
#endif /* STM32H5 || STM32H7RS */

#if defined(STM32WBA)
#define TAMP_SECRETDEVICE_ERASE_NONE            TAMP_DEVICESECRETS_ERASE_NONE          ///< 篡改检测秘密设备擦除：无擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_SRAM2           TAMP_DEVICESECRETS_ERASE_SRAM2         ///< 篡改检测秘密设备擦除：SRAM2擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_RHUK            TAMP_DEVICESECRETS_ERASE_RHUK          ///< 篡改检测秘密设备擦除：RHUK擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_ICACHE          TAMP_DEVICESECRETS_ERASE_ICACHE        ///< 篡改检测秘密设备擦除：指令缓存擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_SAES_AES_HASH   TAMP_DEVICESECRETS_ERASE_SAES_AES_HASH ///< 篡改检测秘密设备擦除：SAES/AES/HASH擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_PKA_SRAM        TAMP_DEVICESECRETS_ERASE_PKA_SRAM      ///< 篡改检测秘密设备擦除：PKA SRAM擦除（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_ALL             TAMP_DEVICESECRETS_ERASE_ALL           ///< 篡改检测秘密设备擦除：全部擦除（旧版定义）
#endif /* STM32WBA */

#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
#define TAMP_SECRETDEVICE_ERASE_DISABLE     TAMP_DEVICESECRETS_ERASE_NONE       ///< 篡改检测秘密设备擦除：禁用（旧版定义）
#define TAMP_SECRETDEVICE_ERASE_ENABLE      TAMP_SECRETDEVICE_ERASE_ALL         ///< 篡改检测秘密设备擦除：使能（旧版定义）
#endif /* STM32H5 || STM32WBA || STM32H7RS */

#if defined(STM32F7)
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_ENABLE_BITS_MASK                 ///< RTC篡改检测使能位掩码（旧版定义）
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_IT_ENABLE_BITS_MASK              ///< RTC篡改检测中断使能位掩码（旧版定义）
#endif /* STM32F7 */

#if defined(STM32H7)
#define RTC_TAMPCR_TAMPXE          RTC_TAMPER_X                                ///< RTC篡改检测使能位（旧版定义）
#define RTC_TAMPCR_TAMPXIE         RTC_TAMPER_X_INTERRUPT                      ///< RTC篡改检测中断使能位（旧版定义）
#endif /* STM32H7 */

#if defined(STM32F7) || defined(STM32H7) || defined(STM32L0)
#define RTC_TAMPER1_INTERRUPT      RTC_IT_TAMP1                                ///< RTC篡改检测1中断（旧版定义）
#define RTC_TAMPER2_INTERRUPT      RTC_IT_TAMP2                                ///< RTC篡改检测2中断（旧版定义）
#define RTC_TAMPER3_INTERRUPT      RTC_IT_TAMP3                                ///< RTC篡改检测3中断（旧版定义）
#define RTC_ALL_TAMPER_INTERRUPT   RTC_IT_TAMP                                 ///< RTC所有篡改检测中断（旧版定义）
#endif /* STM32F7 || STM32H7 || STM32L0 */

/**
  * @}
  */


/** @defgroup HAL_SMARTCARD_Aliased_Defines HAL SMARTCARD Aliased Defines maintained for legacy purpose
  * @{
  */
#define SMARTCARD_NACK_ENABLED                  SMARTCARD_NACK_ENABLE           ///< 智能卡NACK（非确认）使能（旧版定义）
#define SMARTCARD_NACK_DISABLED                 SMARTCARD_NACK_DISABLE          ///< 智能卡NACK（非确认）禁用（旧版定义）

#define SMARTCARD_ONEBIT_SAMPLING_DISABLED      SMARTCARD_ONE_BIT_SAMPLE_DISABLE  ///< 智能卡单比特采样禁用（旧版定义）
#define SMARTCARD_ONEBIT_SAMPLING_ENABLED       SMARTCARD_ONE_BIT_SAMPLE_ENABLE   ///< 智能卡单比特采样使能（旧版定义）
#define SMARTCARD_ONEBIT_SAMPLING_DISABLE       SMARTCARD_ONE_BIT_SAMPLE_DISABLE  ///< 智能卡单比特采样禁用（旧版定义）
#define SMARTCARD_ONEBIT_SAMPLING_ENABLE        SMARTCARD_ONE_BIT_SAMPLE_ENABLE   ///< 智能卡单比特采样使能（旧版定义）

#define SMARTCARD_TIMEOUT_DISABLED              SMARTCARD_TIMEOUT_DISABLE       ///< 智能卡超时禁用（旧版定义）
#define SMARTCARD_TIMEOUT_ENABLED               SMARTCARD_TIMEOUT_ENABLE        ///< 智能卡超时使能（旧版定义）

#define SMARTCARD_LASTBIT_DISABLED              SMARTCARD_LASTBIT_DISABLE       ///< 智能卡最后一位禁用（旧版定义）
#define SMARTCARD_LASTBIT_ENABLED               SMARTCARD_LASTBIT_ENABLE        ///< 智能卡最后一位使能（旧版定义）
/**
  * @}
  */


/** @defgroup HAL_SMBUS_Aliased_Defines HAL SMBUS Aliased Defines maintained for legacy purpose
  * @{
  */
#define SMBUS_DUALADDRESS_DISABLED      SMBUS_DUALADDRESS_DISABLE               ///< SMBUS双地址模式禁用（旧版定义）
#define SMBUS_DUALADDRESS_ENABLED       SMBUS_DUALADDRESS_ENABLE                ///< SMBUS双地址模式使能（旧版定义）
#define SMBUS_GENERALCALL_DISABLED      SMBUS_GENERALCALL_DISABLE               ///< SMBUS广播呼叫禁用（旧版定义）
#define SMBUS_GENERALCALL_ENABLED       SMBUS_GENERALCALL_ENABLE                ///< SMBUS广播呼叫使能（旧版定义）
#define SMBUS_NOSTRETCH_DISABLED        SMBUS_NOSTRETCH_DISABLE                 ///< SMBUS时钟延展禁用（旧版定义）
#define SMBUS_NOSTRETCH_ENABLED         SMBUS_NOSTRETCH_ENABLE                  ///< SMBUS时钟延展使能（旧版定义）
#define SMBUS_ANALOGFILTER_ENABLED      SMBUS_ANALOGFILTER_ENABLE               ///< SMBUS模拟滤波器使能（旧版定义）
#define SMBUS_ANALOGFILTER_DISABLED     SMBUS_ANALOGFILTER_DISABLE              ///< SMBUS模拟滤波器禁用（旧版定义）
#define SMBUS_PEC_DISABLED              SMBUS_PEC_DISABLE                       ///< SMBUS数据包错误检查（PEC）禁用（旧版定义）
#define SMBUS_PEC_ENABLED               SMBUS_PEC_ENABLE                        ///< SMBUS数据包错误检查（PEC）使能（旧版定义）
#define HAL_SMBUS_STATE_SLAVE_LISTEN    HAL_SMBUS_STATE_LISTEN                  ///< SMBUS从机监听状态（旧版定义）
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Defines HAL SPI Aliased Defines maintained for legacy purpose
  * @{
  */
#define SPI_TIMODE_DISABLED             SPI_TIMODE_DISABLE                     ///< SPI TI模式禁用（旧版定义）
#define SPI_TIMODE_ENABLED              SPI_TIMODE_ENABLE                      ///< SPI TI模式使能（旧版定义）

#define SPI_CRCCALCULATION_DISABLED     SPI_CRCCALCULATION_DISABLE             ///< SPI CRC计算禁用（旧版定义）
#define SPI_CRCCALCULATION_ENABLED      SPI_CRCCALCULATION_ENABLE              ///< SPI CRC计算使能（旧版定义）

#define SPI_NSS_PULSE_DISABLED          SPI_NSS_PULSE_DISABLE                  ///< SPI NSS脉冲禁用（旧版定义）
#define SPI_NSS_PULSE_ENABLED           SPI_NSS_PULSE_ENABLE                   ///< SPI NSS脉冲使能（旧版定义）

#if defined(STM32H7)

#define SPI_FLAG_TXE                    SPI_FLAG_TXP                           ///< SPI发送标志（旧版定义，映射到发送完成标志）
#define SPI_FLAG_RXNE                   SPI_FLAG_RXP                           ///< SPI接收标志（旧版定义，映射到接收完成标志）

#define SPI_IT_TXE                      SPI_IT_TXP                             ///< SPI发送中断（旧版定义，映射到发送完成中断）
#define SPI_IT_RXNE                     SPI_IT_RXP                             ///< SPI接收中断（旧版定义，映射到接收完成中断）

#define SPI_FRLVL_EMPTY                 SPI_RX_FIFO_0PACKET                    ///< SPI接收FIFO空（旧版定义，映射到0包）
#define SPI_FRLVL_QUARTER_FULL          SPI_RX_FIFO_1PACKET                    ///< SPI接收FIFO四分之一满（旧版定义，映射到1包）
#define SPI_FRLVL_HALF_FULL             SPI_RX_FIFO_2PACKET                    ///< SPI接收FIFO半满（旧版定义，映射到2包）
#define SPI_FRLVL_FULL                  SPI_RX_FIFO_3PACKET                    ///< SPI接收FIFO全满（旧版定义，映射到3包）

#endif /* STM32H7 */

/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Defines HAL TIM Aliased Defines maintained for legacy purpose
  * @{
  */
#define CCER_CCxE_MASK                   TIM_CCER_CCxE_MASK                    ///< 定时器捕获/比较使能位掩码（旧版定义）
#define CCER_CCxNE_MASK                  TIM_CCER_CCxNE_MASK                   ///< 定时器捕获/比较互补输出使能位掩码（旧版定义）
/* 定时器DMA基地址寄存器别名定义 */
#define TIM_DMABase_CR1                  TIM_DMABASE_CR1  /* 控制寄存器1的DMA基地址 */
#define TIM_DMABase_CR2                  TIM_DMABASE_CR2  /* 控制寄存器2的DMA基地址 */
#define TIM_DMABase_SMCR                 TIM_DMABASE_SMCR /* 从模式控制寄存器的DMA基地址 */
#define TIM_DMABase_DIER                 TIM_DMABASE_DIER /* 中断使能寄存器的DMA基地址 */
#define TIM_DMABase_SR                   TIM_DMABASE_SR   /* 状态寄存器的DMA基地址 */
#define TIM_DMABase_EGR                  TIM_DMABASE_EGR  /* 事件生成寄存器的DMA基地址 */
#define TIM_DMABase_CCMR1                TIM_DMABASE_CCMR1 /* 捕获/比较模式寄存器1的DMA基地址 */
#define TIM_DMABase_CCMR2                TIM_DMABASE_CCMR2 /* 捕获/比较模式寄存器2的DMA基地址 */
#define TIM_DMABase_CCER                 TIM_DMABASE_CCER /* 捕获/比较使能寄存器的DMA基地址 */
#define TIM_DMABase_CNT                  TIM_DMABASE_CNT  /* 计数器的DMA基地址 */
#define TIM_DMABase_PSC                  TIM_DMABASE_PSC  /* 预分频器的DMA基地址 */
#define TIM_DMABase_ARR                  TIM_DMABASE_ARR  /* 自动重装载寄存器的DMA基地址 */
#define TIM_DMABase_RCR                  TIM_DMABASE_RCR  /* 重复计数寄存器的DMA基地址 */
#define TIM_DMABase_CCR1                 TIM_DMABASE_CCR1 /* 捕获/比较寄存器1的DMA基地址 */
#define TIM_DMABase_CCR2                 TIM_DMABASE_CCR2 /* 捕获/比较寄存器2的DMA基地址 */
#define TIM_DMABase_CCR3                 TIM_DMABASE_CCR3 /* 捕获/比较寄存器3的DMA基地址 */
#define TIM_DMABase_CCR4                 TIM_DMABASE_CCR4 /* 捕获/比较寄存器4的DMA基地址 */
#define TIM_DMABase_BDTR                 TIM_DMABASE_BDTR /* 刹车和死区控制寄存器的DMA基地址 */
#define TIM_DMABase_DCR                  TIM_DMABASE_DCR  /* DMA控制寄存器的DMA基地址 */
#define TIM_DMABase_DMAR                 TIM_DMABASE_DMAR /* DMA连续传输地址寄存器的DMA基地址 */
#define TIM_DMABase_OR1                  TIM_DMABASE_OR1  /* 选项寄存器1的DMA基地址 */
#define TIM_DMABase_CCMR3                TIM_DMABASE_CCMR3 /* 捕获/比较模式寄存器3的DMA基地址 */
#define TIM_DMABase_CCR5                 TIM_DMABASE_CCR5 /* 捕获/比较寄存器5的DMA基地址 */
#define TIM_DMABase_CCR6                 TIM_DMABASE_CCR6 /* 捕获/比较寄存器6的DMA基地址 */
#define TIM_DMABase_OR2                  TIM_DMABASE_OR2  /* 选项寄存器2的DMA基地址 */
#define TIM_DMABase_OR3                  TIM_DMABASE_OR3  /* 选项寄存器3的DMA基地址 */
#define TIM_DMABase_OR                   TIM_DMABASE_OR   /* 选项寄存器的DMA基地址 */

/* 定时器事件源别名定义 */
#define TIM_EventSource_Update           TIM_EVENTSOURCE_UPDATE   /* 更新事件 */
#define TIM_EventSource_CC1              TIM_EVENTSOURCE_CC1     /* 捕获/比较通道1事件 */
#define TIM_EventSource_CC2              TIM_EVENTSOURCE_CC2     /* 捕获/比较通道2事件 */
#define TIM_EventSource_CC3              TIM_EVENTSOURCE_CC3     /* 捕获/比较通道3事件 */
#define TIM_EventSource_CC4              TIM_EVENTSOURCE_CC4     /* 捕获/比较通道4事件 */
#define TIM_EventSource_COM              TIM_EVENTSOURCE_COM     /* COM事件 */
#define TIM_EventSource_Trigger          TIM_EVENTSOURCE_TRIGGER /* 触发事件 */
#define TIM_EventSource_Break            TIM_EVENTSOURCE_BREAK   /* 刹车事件 */
#define TIM_EventSource_Break2           TIM_EVENTSOURCE_BREAK2  /* 刹车2事件 */

/* 定时器DMA突发传输长度别名定义 */
#define TIM_DMABurstLength_1Transfer     TIM_DMABURSTLENGTH_1TRANSFER   /* 1次传输 */
#define TIM_DMABurstLength_2Transfers    TIM_DMABURSTLENGTH_2TRANSFERS  /* 2次传输 */
#define TIM_DMABurstLength_3Transfers    TIM_DMABURSTLENGTH_3TRANSFERS  /* 3次传输 */
#define TIM_DMABurstLength_4Transfers    TIM_DMABURSTLENGTH_4TRANSFERS  /* 4次传输 */
#define TIM_DMABurstLength_5Transfers    TIM_DMABURSTLENGTH_5TRANSFERS  /* 5次传输 */
#define TIM_DMABurstLength_6Transfers    TIM_DMABURSTLENGTH_6TRANSFERS  /* 6次传输 */
#define TIM_DMABurstLength_7Transfers    TIM_DMABURSTLENGTH_7TRANSFERS  /* 7次传输 */
#define TIM_DMABurstLength_8Transfers    TIM_DMABURSTLENGTH_8TRANSFERS  /* 8次传输 */
#define TIM_DMABurstLength_9Transfers    TIM_DMABURSTLENGTH_9TRANSFERS  /* 9次传输 */
#define TIM_DMABurstLength_10Transfers   TIM_DMABURSTLENGTH_10TRANSFERS /* 10次传输 */
#define TIM_DMABurstLength_11Transfers   TIM_DMABURSTLENGTH_11TRANSFERS /* 11次传输 */
#define TIM_DMABurstLength_12Transfers   TIM_DMABURSTLENGTH_12TRANSFERS /* 12次传输 */
#define TIM_DMABurstLength_13Transfers   TIM_DMABURSTLENGTH_13TRANSFERS /* 13次传输 */
#define TIM_DMABurstLength_14Transfers   TIM_DMABURSTLENGTH_14TRANSFERS /* 14次传输 */
#define TIM_DMABurstLength_15Transfers   TIM_DMABURSTLENGTH_15TRANSFERS /* 15次传输 */
#define TIM_DMABurstLength_16Transfers   TIM_DMABURSTLENGTH_16TRANSFERS /* 16次传输 */
#define TIM_DMABurstLength_17Transfers   TIM_DMABURSTLENGTH_17TRANSFERS /* 17次传输 */
#define TIM_DMABurstLength_18Transfers   TIM_DMABURSTLENGTH_18TRANSFERS /* 18次传输 */

/* STM32L0系列特定定义 */
#if defined(STM32L0)
#define TIM22_TI1_GPIO1   TIM22_TI1_GPIO  /* TIM22定时器通道1输入，映射到GPIO引脚1 */
#define TIM22_TI1_GPIO2   TIM22_TI1_GPIO  /* TIM22定时器通道1输入，映射到GPIO引脚2 */
#endif

/* STM32F3系列特定定义 */
#if defined(STM32F3)
/* 霍尔传感器接口实例检查宏别名 */
#define IS_TIM_HALL_INTERFACE_INSTANCE   IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE
#endif

/* STM32H7系列特定定义 - 定时器外部触发和输入捕获映射到比较器输出 */
#if defined(STM32H7)
#define TIM_TIM1_ETR_COMP1_OUT        TIM_TIM1_ETR_COMP1         /* TIM1 ETR 映射到 COMP1 输出 */
#define TIM_TIM1_ETR_COMP2_OUT        TIM_TIM1_ETR_COMP2         /* TIM1 ETR 映射到 COMP2 输出 */
#define TIM_TIM8_ETR_COMP1_OUT        TIM_TIM8_ETR_COMP1         /* TIM8 ETR 映射到 COMP1 输出 */
#define TIM_TIM8_ETR_COMP2_OUT        TIM_TIM8_ETR_COMP2         /* TIM8 ETR 映射到 COMP2 输出 */
#define TIM_TIM2_ETR_COMP1_OUT        TIM_TIM2_ETR_COMP1         /* TIM2 ETR 映射到 COMP1 输出 */
#define TIM_TIM2_ETR_COMP2_OUT        TIM_TIM2_ETR_COMP2         /* TIM2 ETR 映射到 COMP2 输出 */
#define TIM_TIM3_ETR_COMP1_OUT        TIM_TIM3_ETR_COMP1         /* TIM3 ETR 映射到 COMP1 输出 */
#define TIM_TIM1_TI1_COMP1_OUT        TIM_TIM1_TI1_COMP1         /* TIM1 TI1 映射到 COMP1 输出 */
#define TIM_TIM8_TI1_COMP2_OUT        TIM_TIM8_TI1_COMP2         /* TIM8 TI1 映射到 COMP2 输出 */
#define TIM_TIM2_TI4_COMP1_OUT        TIM_TIM2_TI4_COMP1         /* TIM2 TI4 映射到 COMP1 输出 */
#define TIM_TIM2_TI4_COMP2_OUT        TIM_TIM2_TI4_COMP2         /* TIM2 TI4 映射到 COMP2 输出 */
#define TIM_TIM2_TI4_COMP1COMP2_OUT   TIM_TIM2_TI4_COMP1_COMP2   /* TIM2 TI4 映射到 COMP1 和 COMP2 输出 */
#define TIM_TIM3_TI1_COMP1_OUT        TIM_TIM3_TI1_COMP1         /* TIM3 TI1 映射到 COMP1 输出 */
#define TIM_TIM3_TI1_COMP2_OUT        TIM_TIM3_TI1_COMP2         /* TIM3 TI1 映射到 COMP2 输出 */
#define TIM_TIM3_TI1_COMP1COMP2_OUT   TIM_TIM3_TI1_COMP1_COMP2   /* TIM3 TI1 映射到 COMP1 和 COMP2 输出 */
#endif

/* STM32U5系列特定定义 - 输出比较清除选择位定义 */
#if defined(STM32U5)
#define OCREF_CLEAR_SELECT_Pos       OCREF_CLEAR_SELECT_POS /* 输出比较清除选择位位置 */
#define OCREF_CLEAR_SELECT_Msk       OCREF_CLEAR_SELECT_MSK /* 输出比较清除选择位掩码 */
#endif
/**
  * @}
  */

/** @defgroup HAL_TSC_Aliased_Defines HAL TSC Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL触摸感应控制器(TSC)别名定义
  * @{
  */
#define TSC_SYNC_POL_FALL        TSC_SYNC_POLARITY_FALLING   /* 同步信号下降沿有效 */
#define TSC_SYNC_POL_RISE_HIGH   TSC_SYNC_POLARITY_RISING    /* 同步信号上升沿有效 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Defines HAL UART Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL通用异步收发器(UART)别名定义
  * @{
  */
/* 单比特采样使能/禁用别名 */
#define UART_ONEBIT_SAMPLING_DISABLED   UART_ONE_BIT_SAMPLE_DISABLE /* 禁用单比特采样 */
#define UART_ONEBIT_SAMPLING_ENABLED    UART_ONE_BIT_SAMPLE_ENABLE  /* 使能单比特采样 */
#define UART_ONE_BIT_SAMPLE_DISABLED    UART_ONE_BIT_SAMPLE_DISABLE /* 禁用单比特采样 */
#define UART_ONE_BIT_SAMPLE_ENABLED     UART_ONE_BIT_SAMPLE_ENABLE  /* 使能单比特采样 */

/* 单比特采样使能/禁用宏别名 */
#define __HAL_UART_ONEBIT_ENABLE        __HAL_UART_ONE_BIT_SAMPLE_ENABLE    /* 使能单比特采样宏 */
#define __HAL_UART_ONEBIT_DISABLE       __HAL_UART_ONE_BIT_SAMPLE_DISABLE   /* 禁用单比特采样宏 */

/* 16倍过采样分频寄存器计算相关别名 */
#define __DIV_SAMPLING16                UART_DIV_SAMPLING16         /* 16倍过采样分频值 */
#define __DIVMANT_SAMPLING16            UART_DIVMANT_SAMPLING16     /* 16倍过采样分频值整数部分 */
#define __DIVFRAQ_SAMPLING16            UART_DIVFRAQ_SAMPLING16     /* 16倍过采样分频值小数部分 */
#define __UART_BRR_SAMPLING16           UART_BRR_SAMPLING16         /* 16倍过采样波特率寄存器值 */

/* 8倍过采样分频寄存器计算相关别名 */
#define __DIV_SAMPLING8                 UART_DIV_SAMPLING8          /* 8倍过采样分频值 */
#define __DIVMANT_SAMPLING8             UART_DIVMANT_SAMPLING8      /* 8倍过采样分频值整数部分 */
#define __DIVFRAQ_SAMPLING8             UART_DIVFRAQ_SAMPLING8      /* 8倍过采样分频值小数部分 */
#define __UART_BRR_SAMPLING8            UART_BRR_SAMPLING8          /* 8倍过采样波特率寄存器值 */

/* 低功耗UART分频计算别名 */
#define __DIV_LPUART                    UART_DIV_LPUART             /* 低功耗UART分频值 */

/* UART唤醒方法别名 */
#define UART_WAKEUPMETHODE_IDLELINE     UART_WAKEUPMETHOD_IDLELINE     /* 空闲线唤醒 */
#define UART_WAKEUPMETHODE_ADDRESSMARK  UART_WAKEUPMETHOD_ADDRESSMARK  /* 地址标记唤醒 */

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Defines HAL USART Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL通用同步异步收发器(USART)别名定义
  * @{
  */

/* USART时钟控制别名 */
#define USART_CLOCK_DISABLED            USART_CLOCK_DISABLE  /* 禁用USART时钟 */
#define USART_CLOCK_ENABLED             USART_CLOCK_ENABLE   /* 使能USART时钟 */

/* USART NACK功能别名 */
#define USARTNACK_ENABLED               USART_NACK_ENABLE   /* 使能NACK（非应答） */
#define USARTNACK_DISABLED              USART_NACK_DISABLE  /* 禁用NACK（非应答） */
/**
  * @}
  */

/** @defgroup HAL_WWDG_Aliased_Defines HAL WWDG Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL窗口看门狗(WWDG)别名定义
  * @{
  */
#define CFR_BASE                    WWDG_CFR_BASE  /* 配置寄存器(CFR)基地址 */
/**
  * @}
  */

/** @defgroup HAL_CAN_Aliased_Defines HAL CAN Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL控制器局域网(CAN)别名定义
  * @{
  */
/* CAN过滤器FIFO分配别名 */
#define CAN_FilterFIFO0             CAN_FILTER_FIFO0  /* 过滤器映射到FIFO0 */
#define CAN_FilterFIFO1             CAN_FILTER_FIFO1  /* 过滤器映射到FIFO1 */

/* CAN发送邮箱请求完成中断别名 */
#define CAN_IT_RQCP0                CAN_IT_TME  /* 发送邮箱0请求完成中断 */
#define CAN_IT_RQCP1                CAN_IT_TME  /* 发送邮箱1请求完成中断 */
#define CAN_IT_RQCP2                CAN_IT_TME  /* 发送邮箱2请求完成中断 */

/* CAN超时值别名 */
#define INAK_TIMEOUT                CAN_TIMEOUT_VALUE  /* 初始化应答超时值 */
#define SLAK_TIMEOUT                CAN_TIMEOUT_VALUE  /* 睡眠应答超时值 */

/* CAN发送状态别名 */
#define CAN_TXSTATUS_FAILED         ((uint8_t)0x00U)  /* 发送失败 */
#define CAN_TXSTATUS_OK             ((uint8_t)0x01U)  /* 发送成功 */
#define CAN_TXSTATUS_PENDING        ((uint8_t)0x02U)  /* 发送挂起 */

/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Defines HAL ETH Aliased Defines maintained for legacy purpose
  * @brief 为向后兼容而保留的HAL以太网(ETH)别名定义
  * @{
  */

/* 以太网帧相关常量别名 */
#define VLAN_TAG                ETH_VLAN_TAG                 /* VLAN标签长度 */
#define MIN_ETH_PAYLOAD         ETH_MIN_ETH_PAYLOAD          /* 最小以太网载荷长度 */
#define MAX_ETH_PAYLOAD         ETH_MAX_ETH_PAYLOAD          /* 最大以太网载荷长度 */
#define JUMBO_FRAME_PAYLOAD     ETH_JUMBO_FRAME_PAYLOAD      /* 巨帧载荷长度 */

/* 以太网寄存器掩码别名 */
#define MACMIIAR_CR_MASK        ETH_MACMIIAR_CR_MASK         /* MII地址寄存器时钟范围掩码 */
#define MACCR_CLEAR_MASK        ETH_MACCR_CLEAR_MASK         /* MAC控制寄存器清除掩码 */
#define MACFCR_CLEAR_MASK       ETH_MACFCR_CLEAR_MASK        /* MAC流控制寄存器清除掩码 */
#define DMAOMR_CLEAR_MASK       ETH_DMAOMR_CLEAR_MASK        /* DMA操作模式寄存器清除掩码 */

/* 以太网MMC（MAC管理计数器）寄存器偏移地址定义 */
#define ETH_MMCCR              0x00000100U  /* MMC控制寄存器偏移地址 */
#define ETH_MMCRIR             0x00000104U  /* MMC接收中断寄存器偏移地址 */
#define ETH_MMCTIR             0x00000108U  /* MMC发送中断寄存器偏移地址 */
#define ETH_MMCRIMR            0x0000010CU  /* MMC接收中断掩码寄存器偏移地址 */
#define ETH_MMCTIMR            0x00000110U  /* MMC发送中断掩码寄存器偏移地址 */
#define ETH_MMCTGFSCCR         0x0000014CU  /* MMC发送良好单冲突帧计数器寄存器偏移地址 */
#define ETH_MMCTGFMSCCR        0x00000150U  /* MMC发送良好多冲突帧计数器寄存器偏移地址 */
#define ETH_MMCTGFCR           0x00000168U  /* MMC发送良好帧计数器寄存器偏移地址 */
#define ETH_MMCRFCECR          0x00000194U  /* MMC接收CRC错误帧计数器寄存器偏移地址 */
#define ETH_MMCRFAECR          0x00000198U  /* MMC接收对齐错误帧计数器寄存器偏移地址 */
#define ETH_MMCRGUFCR          0x000001C4U  /* MMC接收良好单播帧计数器寄存器偏移地址 */

/**
  * @}
  */
#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* Tx FIFO 满 */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* Tx FIFO 非空 */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* Tx FIFO 写操作活跃 */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* Tx FIFO 读状态：空闲 */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* Tx FIFO 读状态：读取（数据传输到 MAC 发送器） */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* Tx FIFO 读状态：等待来自 MAC 发送器的 TxStatus */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* Tx FIFO 读状态：写入接收到的 TxStatus 或清空 TxFIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC 发送器处于暂停状态 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC 发送帧控制器：空闲 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC 发送帧控制器：等待上一帧状态或 IFG/退避期结束 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC 发送帧控制器：生成并发送暂停控制帧（全双工模式） */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC 发送帧控制器：传输输入帧以进行发送 */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII 发送引擎活跃 */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* Rx FIFO 填充等级：空 */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* Rx FIFO 填充等级：填充水平低于流量控制停用阈值 */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* Rx FIFO 填充等级：填充水平高于流量控制激活阈值 */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* Rx FIFO 填充等级：满 */
#if defined(STM32F1)  /* STM32F1 系列微控制器 */
#else  /* 非 STM32F1 系列微控制器 */
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* Rx FIFO 读控制器空闲状态 */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* Rx FIFO 读控制器正在读取帧数据 */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* Rx FIFO 读控制器正在读取帧状态（或时间戳） */
#endif  /* 条件编译结束 */
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* Rx FIFO 读控制器正在清空帧数据和状态 */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* Rx FIFO 写控制器活跃 */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC 小型 FIFO 读/写控制器不活跃 */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC 小型 FIFO 读控制器活跃 */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC 小型 FIFO 写控制器活跃 */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC 小型 FIFO 读/写控制器均活跃 */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII 接收协议引擎活跃 */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* 发送数据包配置结构体定义 */

/**
  * @}
  */

/** @defgroup HAL_DCMI_Aliased_Defines HAL DCMI 别名的定义，为保持向后兼容而保留
  * @{
  */
#define HAL_DCMI_ERROR_OVF      HAL_DCMI_ERROR_OVR  /* 溢出错误别名 */
#define DCMI_IT_OVF             DCMI_IT_OVR         /* 溢出中断别名 */
#define DCMI_FLAG_OVFRI         DCMI_FLAG_OVRRI     /* 溢出原始中断标志别名 */
#define DCMI_FLAG_OVFMI         DCMI_FLAG_OVRMI     /* 溢出屏蔽中断标志别名 */

#define HAL_DCMI_ConfigCROP     HAL_DCMI_ConfigCrop  /* 配置裁剪区域函数别名 */
#define HAL_DCMI_EnableCROP     HAL_DCMI_EnableCrop  /* 启用裁剪函数别名 */
#define HAL_DCMI_DisableCROP    HAL_DCMI_DisableCrop /* 禁用裁剪函数别名 */

/**
  * @}
  */

#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7)  /* 适用于 STM32L4、STM32F7、STM32F4（特定型号）和 STM32H7 系列 */
/** @defgroup HAL_DMA2D_Aliased_Defines HAL DMA2D 别名的定义，为保持向后兼容而保留
  * @{
  */
#define DMA2D_ARGB8888          DMA2D_OUTPUT_ARGB8888  /* 输出格式别名：ARGB8888 */
#define DMA2D_RGB888            DMA2D_OUTPUT_RGB888    /* 输出格式别名：RGB888 */
#define DMA2D_RGB565            DMA2D_OUTPUT_RGB565    /* 输出格式别名：RGB565 */
#define DMA2D_ARGB1555          DMA2D_OUTPUT_ARGB1555  /* 输出格式别名：ARGB1555 */
#define DMA2D_ARGB4444          DMA2D_OUTPUT_ARGB4444  /* 输出格式别名：ARGB4444 */

#define CM_ARGB8888             DMA2D_INPUT_ARGB8888   /* 输入格式别名：ARGB8888 */
#define CM_RGB888               DMA2D_INPUT_RGB888     /* 输入格式别名：RGB888 */
#define CM_RGB565               DMA2D_INPUT_RGB565     /* 输入格式别名：RGB565 */
#define CM_ARGB1555             DMA2D_INPUT_ARGB1555   /* 输入格式别名：ARGB1555 */
#define CM_ARGB4444             DMA2D_INPUT_ARGB4444   /* 输入格式别名：ARGB4444 */
#define CM_L8                   DMA2D_INPUT_L8         /* 输入格式别名：L8（8位亮度） */
#define CM_AL44                 DMA2D_INPUT_AL44       /* 输入格式别名：AL44（4位Alpha + 4位亮度） */
#define CM_AL88                 DMA2D_INPUT_AL88       /* 输入格式别名：AL88（8位Alpha + 8位亮度） */
#define CM_L4                   DMA2D_INPUT_L4         /* 输入格式别名：L4（4位亮度） */
#define CM_A8                   DMA2D_INPUT_A8         /* 输入格式别名：A8（8位Alpha） */
#define CM_A4                   DMA2D_INPUT_A4         /* 输入格式别名：A4（4位Alpha） */
/**
  * @}
  */
#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 */

#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7) || defined(STM32U5)  /* 适用于 STM32L4、STM32F7、STM32F4（特定型号）、STM32H7 和 STM32U5 系列 */
/** @defgroup DMA2D_Aliases DMA2D API 别名
  * @{
  */
#define HAL_DMA2D_DisableCLUT       HAL_DMA2D_CLUTLoading_Abort    /*!< 为兼容旧代码，别名到 HAL_DMA2D_CLUTLoading_Abort */
/**
  * @}
  */

#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 || STM32U5 */

/** @defgroup HAL_PPP_Aliased_Defines HAL PPP 别名的定义，为保持向后兼容而保留
  * @{
  */

/**
  * @}
  */

/* 导出的函数 --------------------------------------------------------*/

/** @defgroup HAL_CRYP_Aliased_Functions HAL CRYP 别名的函数，为保持向后兼容而保留
  * @{
  */
#define HAL_CRYP_ComputationCpltCallback     HAL_CRYPEx_ComputationCpltCallback  /* 计算完成回调函数别名 */
/**
  * @}
  */

/** @defgroup HAL_DCACHE_Aliased_Functions HAL DCACHE 别名的函数，为保持向后兼容而保留
  * @{
  */

#if defined(STM32U5)  /* STM32U5 系列微控制器 */
#define HAL_DCACHE_CleanInvalidateByAddr     HAL_DCACHE_CleanInvalidByAddr       /* 按地址清理并失效缓存别名 */
#define HAL_DCACHE_CleanInvalidateByAddr_IT  HAL_DCACHE_CleanInvalidByAddr_IT    /* 按地址清理并失效缓存（中断模式）别名 */
#endif /* STM32U5 */

/**
  * @}
  */

#if !defined(STM32F2)  /* 非 STM32F2 系列微控制器 */
/** @defgroup HASH_alias HASH API 别名
  * @{
  */
#define HAL_HASHEx_IRQHandler   HAL_HASH_IRQHandler  /*!< 为兼容旧代码，重定向到 HAL_HASH_IRQHandler */
/**
  *
  * @}
  */
#endif /* STM32F2 */
/** @defgroup HAL_HASH_Aliased_Functions HAL HASH 别名的函数，为保持向后兼容而保留
  * @{
  */
#define HAL_HASH_STATETypeDef        HAL_HASH_StateTypeDef  /* HASH 状态类型定义别名 */
#define HAL_HASHPhaseTypeDef         HAL_HASH_PhaseTypeDef  /* HASH 阶段类型定义别名 */
#define HAL_HMAC_MD5_Finish          HAL_HASH_MD5_Finish    /* HMAC MD5 完成函数别名 */
#define HAL_HMAC_SHA1_Finish         HAL_HASH_SHA1_Finish   /* HMAC SHA1 完成函数别名 */
#define HAL_HMAC_SHA224_Finish       HAL_HASH_SHA224_Finish /* HMAC SHA224 完成函数别名 */
#define HAL_HMAC_SHA256_Finish       HAL_HASH_SHA256_Finish /* HMAC SHA256 完成函数别名 */

/* HASH 算法选择 */

#define HASH_AlgoSelection_SHA1      HASH_ALGOSELECTION_SHA1    /* SHA1 算法选择别名 */
#define HASH_AlgoSelection_SHA224    HASH_ALGOSELECTION_SHA224  /* SHA224 算法选择别名 */
#define HASH_AlgoSelection_SHA256    HASH_ALGOSELECTION_SHA256  /* SHA256 算法选择别名 */
#define HASH_AlgoSelection_MD5       HASH_ALGOSELECTION_MD5     /* MD5 算法选择别名 */

#define HASH_AlgoMode_HASH         HASH_ALGOMODE_HASH  /* HASH 算法模式别名 */
#define HASH_AlgoMode_HMAC         HASH_ALGOMODE_HMAC  /* HMAC 算法模式别名 */

#define HASH_HMACKeyType_ShortKey  HASH_HMAC_KEYTYPE_SHORTKEY  /* HMAC 短密钥类型别名 */
#define HASH_HMACKeyType_LongKey   HASH_HMAC_KEYTYPE_LONGKEY   /* HMAC 长密钥类型别名 */

#if defined(STM32L4) || defined(STM32L5) || defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)  /* 适用于多个 STM32 系列 */

#define HAL_HASH_MD5_Accumulate                HAL_HASH_MD5_Accmlt             /* MD5 累积函数别名 */
#define HAL_HASH_MD5_Accumulate_End            HAL_HASH_MD5_Accmlt_End         /* MD5 累积结束函数别名 */
#define HAL_HASH_MD5_Accumulate_IT             HAL_HASH_MD5_Accmlt_IT          /* MD5 累积（中断模式）函数别名 */
#define HAL_HASH_MD5_Accumulate_End_IT         HAL_HASH_MD5_Accmlt_End_IT      /* MD5 累积结束（中断模式）函数别名 */

#define HAL_HASH_SHA1_Accumulate               HAL_HASH_SHA1_Accmlt            /* SHA1 累积函数别名 */
#define HAL_HASH_SHA1_Accumulate_End           HAL_HASH_SHA1_Accmlt_End        /* SHA1 累积结束函数别名 */
#define HAL_HASH_SHA1_Accumulate_IT            HAL_HASH_SHA1_Accmlt_IT         /* SHA1 累积（中断模式）函数别名 */
#define HAL_HASH_SHA1_Accumulate_End_IT        HAL_HASH_SHA1_Accmlt_End_IT     /* SHA1 累积结束（中断模式）函数别名 */

#define HAL_HASHEx_SHA224_Accumulate           HAL_HASHEx_SHA224_Accmlt        /* SHA224 累积函数别名 */
#define HAL_HASHEx_SHA224_Accumulate_End       HAL_HASHEx_SHA224_Accmlt_End    /* SHA224 累积结束函数别名 */
#define HAL_HASHEx_SHA224_Accumulate_IT        HAL_HASHEx_SHA224_Accmlt_IT     /* SHA224 累积（中断模式）函数别名 */
#define HAL_HASHEx_SHA224_Accumulate_End_IT    HAL_HASHEx_SHA224_Accmlt_End_IT /* SHA224 累积结束（中断模式）函数别名 */

#define HAL_HASHEx_SHA256_Accumulate           HAL_HASHEx_SHA256_Accmlt        /* SHA256 累积函数别名 */
#define HAL_HASHEx_SHA256_Accumulate_End       HAL_HASHEx_SHA256_Accmlt_End    /* SHA256 累积结束函数别名 */
#define HAL_HASHEx_SHA256_Accumulate_IT        HAL_HASHEx_SHA256_Accmlt_IT     /* SHA256 累积（中断模式）函数别名 */
#define HAL_HASHEx_SHA256_Accumulate_End_IT    HAL_HASHEx_SHA256_Accmlt_End_IT /* SHA256 累积结束（中断模式）函数别名 */

#endif  /* STM32L4 || STM32L5 || STM32F2 || STM32F4 || STM32F7 || STM32H7 */
/**
  * @}
  */
/** @defgroup HAL_Aliased_Functions HAL通用别名函数（为保持向后兼容性而保留）
  * @{
  */
#define HAL_EnableDBGSleepMode HAL_DBGMCU_EnableDBGSleepMode                /* 使能调试模式下的睡眠模式 */
#define HAL_DisableDBGSleepMode HAL_DBGMCU_DisableDBGSleepMode              /* 禁用调试模式下的睡眠模式 */
#define HAL_EnableDBGStopMode HAL_DBGMCU_EnableDBGStopMode                  /* 使能调试模式下的停止模式 */
#define HAL_DisableDBGStopMode HAL_DBGMCU_DisableDBGStopMode                /* 禁用调试模式下的停止模式 */
#define HAL_EnableDBGStandbyMode HAL_DBGMCU_EnableDBGStandbyMode            /* 使能调试模式下的待机模式 */
#define HAL_DisableDBGStandbyMode HAL_DBGMCU_DisableDBGStandbyMode          /* 禁用调试模式下的待机模式 */
#define HAL_DBG_LowPowerConfig(Periph, cmd) (((cmd\
                                              )==ENABLE)? HAL_DBGMCU_DBG_EnableLowPowerConfig(Periph) : \
                                             HAL_DBGMCU_DBG_DisableLowPowerConfig(Periph)) /* 根据命令使能或禁用外设的低功耗调试配置 */
#define HAL_VREFINT_OutputSelect  HAL_SYSCFG_VREFINT_OutputSelect           /* 内部电压基准输出选择 */
#define HAL_Lock_Cmd(cmd) (((cmd)==ENABLE) ? HAL_SYSCFG_Enable_Lock_VREFINT() : HAL_SYSCFG_Disable_Lock_VREFINT()) /* 根据命令锁定或解锁内部电压基准 */
#if defined(STM32L0)
#else
#define HAL_VREFINT_Cmd(cmd) (((cmd)==ENABLE)? HAL_SYSCFG_EnableVREFINT() : HAL_SYSCFG_DisableVREFINT()) /* 根据命令使能或禁用内部电压基准 */
#endif
#define HAL_ADC_EnableBuffer_Cmd(cmd)  (((cmd)==ENABLE) ? HAL_ADCEx_EnableVREFINT() : HAL_ADCEx_DisableVREFINT()) /* 根据命令使能或禁用ADC内部电压基准缓冲 */
#define HAL_ADC_EnableBufferSensor_Cmd(cmd) (((cmd\
                                              )==ENABLE) ?  HAL_ADCEx_EnableVREFINTTempSensor() : \
                                             HAL_ADCEx_DisableVREFINTTempSensor()) /* 根据命令使能或禁用ADC内部电压基准温度传感器缓冲 */
#if defined(STM32H7A3xx) || defined(STM32H7B3xx) || defined(STM32H7B0xx) || defined(STM32H7A3xxQ) || \
    defined(STM32H7B3xxQ) || defined(STM32H7B0xxQ)
#define HAL_EnableSRDomainDBGStopMode      HAL_EnableDomain3DBGStopMode     /* 使能SR域调试停止模式 */
#define HAL_DisableSRDomainDBGStopMode     HAL_DisableDomain3DBGStopMode    /* 禁用SR域调试停止模式 */
#define HAL_EnableSRDomainDBGStandbyMode   HAL_EnableDomain3DBGStandbyMode  /* 使能SR域调试待机模式 */
#define HAL_DisableSRDomainDBGStandbyMode  HAL_DisableDomain3DBGStandbyMode /* 禁用SR域调试待机模式 */
#endif /* STM32H7A3xx || STM32H7B3xx || STM32H7B0xx || STM32H7A3xxQ || STM32H7B3xxQ  || STM32H7B0xxQ */

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Functions HAL FLASH别名函数（为保持向后兼容性而保留）
  * @{
  */
#define FLASH_HalfPageProgram      HAL_FLASHEx_HalfPageProgram              /* FLASH半页编程 */
#define FLASH_EnableRunPowerDown   HAL_FLASHEx_EnableRunPowerDown           /* 使能运行时的掉电模式 */
#define FLASH_DisableRunPowerDown  HAL_FLASHEx_DisableRunPowerDown          /* 禁用运行时的掉电模式 */
#define HAL_DATA_EEPROMEx_Unlock   HAL_FLASHEx_DATAEEPROM_Unlock            /* 解锁数据EEPROM */
#define HAL_DATA_EEPROMEx_Lock     HAL_FLASHEx_DATAEEPROM_Lock              /* 锁定数据EEPROM */
#define HAL_DATA_EEPROMEx_Erase    HAL_FLASHEx_DATAEEPROM_Erase             /* 擦除数据EEPROM */
#define HAL_DATA_EEPROMEx_Program  HAL_FLASHEx_DATAEEPROM_Program           /* 编程数据EEPROM */

/**
  * @}
 */

/** @defgroup HAL_I2C_Aliased_Functions HAL I2C别名函数（为保持向后兼容性而保留）
  * @{
  */
#define HAL_I2CEx_AnalogFilter_Config         HAL_I2CEx_ConfigAnalogFilter      /* 配置I2C模拟滤波器 */
#define HAL_I2CEx_DigitalFilter_Config        HAL_I2CEx_ConfigDigitalFilter     /* 配置I2C数字滤波器 */
#define HAL_FMPI2CEx_AnalogFilter_Config      HAL_FMPI2CEx_ConfigAnalogFilter   /* 配置FMPI2C模拟滤波器 */
#define HAL_FMPI2CEx_DigitalFilter_Config     HAL_FMPI2CEx_ConfigDigitalFilter  /* 配置FMPI2C数字滤波器 */

#define HAL_I2CFastModePlusConfig(SYSCFG_I2CFastModePlus, cmd) (((cmd) == ENABLE)? \
                                                                HAL_I2CEx_EnableFastModePlus(SYSCFG_I2CFastModePlus): \
                                                                HAL_I2CEx_DisableFastModePlus(SYSCFG_I2CFastModePlus)) /* 根据命令使能或禁用I2C快速模式+ */

#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || \
    defined(STM32F2) || defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || \
    defined(STM32L4) || defined(STM32L5) || defined(STM32G4) || defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_IT  HAL_I2C_Master_Seq_Transmit_IT   /* 主模式顺序发送（中断方式） */
#define HAL_I2C_Master_Sequential_Receive_IT   HAL_I2C_Master_Seq_Receive_IT    /* 主模式顺序接收（中断方式） */
#define HAL_I2C_Slave_Sequential_Transmit_IT   HAL_I2C_Slave_Seq_Transmit_IT    /* 从模式顺序发送（中断方式） */
#define HAL_I2C_Slave_Sequential_Receive_IT    HAL_I2C_Slave_Seq_Receive_IT     /* 从模式顺序接收（中断方式） */
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 ||
          STM32L4 || STM32L5 || STM32G4 || STM32L1 */
#if defined(STM32H7) || defined(STM32WB) || defined(STM32G0) || defined(STM32F4) || defined(STM32F7) || \
    defined(STM32L0) || defined(STM32L4) || defined(STM32L5) || defined(STM32G4)|| defined(STM32L1)
#define HAL_I2C_Master_Sequential_Transmit_DMA HAL_I2C_Master_Seq_Transmit_DMA  /* 主模式顺序发送（DMA方式） */
#define HAL_I2C_Master_Sequential_Receive_DMA  HAL_I2C_Master_Seq_Receive_DMA   /* 主模式顺序接收（DMA方式） */
#define HAL_I2C_Slave_Sequential_Transmit_DMA  HAL_I2C_Slave_Seq_Transmit_DMA   /* 从模式顺序发送（DMA方式） */
#define HAL_I2C_Slave_Sequential_Receive_DMA   HAL_I2C_Slave_Seq_Receive_DMA    /* 从模式顺序接收（DMA方式） */
#endif /* STM32H7 || STM32WB  || STM32G0 || STM32F4 || STM32F7 || STM32L0 || STM32L4 || STM32L5 || STM32G4 || STM32L1 */

#if defined(STM32F4)
#define HAL_FMPI2C_Master_Sequential_Transmit_IT  HAL_FMPI2C_Master_Seq_Transmit_IT   /* FMPI2C主模式顺序发送（中断方式） */
#define HAL_FMPI2C_Master_Sequential_Receive_IT   HAL_FMPI2C_Master_Seq_Receive_IT    /* FMPI2C主模式顺序接收（中断方式） */
#define HAL_FMPI2C_Slave_Sequential_Transmit_IT   HAL_FMPI2C_Slave_Seq_Transmit_IT    /* FMPI2C从模式顺序发送（中断方式） */
#define HAL_FMPI2C_Slave_Sequential_Receive_IT    HAL_FMPI2C_Slave_Seq_Receive_IT     /* FMPI2C从模式顺序接收（中断方式） */
#define HAL_FMPI2C_Master_Sequential_Transmit_DMA HAL_FMPI2C_Master_Seq_Transmit_DMA  /* FMPI2C主模式顺序发送（DMA方式） */
#define HAL_FMPI2C_Master_Sequential_Receive_DMA  HAL_FMPI2C_Master_Seq_Receive_DMA   /* FMPI2C主模式顺序接收（DMA方式） */
#define HAL_FMPI2C_Slave_Sequential_Transmit_DMA  HAL_FMPI2C_Slave_Seq_Transmit_DMA   /* FMPI2C从模式顺序发送（DMA方式） */
#define HAL_FMPI2C_Slave_Sequential_Receive_DMA   HAL_FMPI2C_Slave_Seq_Receive_DMA    /* FMPI2C从模式顺序接收（DMA方式） */
#endif /* STM32F4 */
/**
  * @}
 */

/** @defgroup HAL_PWR_Aliased HAL PWR别名（为保持向后兼容性而保留）
  * @{
  */

#if defined(STM32G0)
#define HAL_PWR_ConfigPVD                             HAL_PWREx_ConfigPVD       /* 配置可编程电压检测器 */
#define HAL_PWR_EnablePVD                             HAL_PWREx_EnablePVD       /* 使能可编程电压检测器 */
#define HAL_PWR_DisablePVD                            HAL_PWREx_DisablePVD      /* 禁用可编程电压检测器 */
#define HAL_PWR_PVD_IRQHandler                        HAL_PWREx_PVD_IRQHandler  /* 可编程电压检测器中断处理函数 */
#endif
#define HAL_PWR_PVDConfig                             HAL_PWR_ConfigPVD         /* 配置可编程电压检测器 */
#define HAL_PWR_DisableBkUpReg                        HAL_PWREx_DisableBkUpReg  /* 禁用备份寄存器 */
#define HAL_PWR_DisableFlashPowerDown                 HAL_PWREx_DisableFlashPowerDown /* 禁用Flash掉电模式 */
#define HAL_PWR_DisableVddio2Monitor                  HAL_PWREx_DisableVddio2Monitor   /* 禁用VDDIO2监控 */
#define HAL_PWR_EnableBkUpReg                         HAL_PWREx_EnableBkUpReg   /* 使能备份寄存器 */
#define HAL_PWR_EnableFlashPowerDown                  HAL_PWREx_EnableFlashPowerDown   /* 使能Flash掉电模式 */
#define HAL_PWR_EnableVddio2Monitor                   HAL_PWREx_EnableVddio2Monitor    /* 使能VDDIO2监控 */
#define HAL_PWR_PVD_PVM_IRQHandler                    HAL_PWREx_PVD_PVM_IRQHandler     /* 可编程电压检测器和可编程电压监视器中断处理函数 */
#define HAL_PWR_PVDLevelConfig                        HAL_PWR_ConfigPVD         /* 配置可编程电压检测器电平 */
#define HAL_PWR_Vddio2Monitor_IRQHandler              HAL_PWREx_Vddio2Monitor_IRQHandler /* VDDIO2监控中断处理函数 */
#define HAL_PWR_Vddio2MonitorCallback                 HAL_PWREx_Vddio2MonitorCallback  /* VDDIO2监控回调函数 */
#define HAL_PWREx_ActivateOverDrive                   HAL_PWREx_EnableOverDrive       /* 激活过驱动模式 */
#define HAL_PWREx_DeactivateOverDrive                 HAL_PWREx_DisableOverDrive      /* 取消激活过驱动模式 */
#define HAL_PWREx_DisableSDADCAnalog                  HAL_PWREx_DisableSDADC          /* 禁用SDADC模拟部分 */
#define HAL_PWREx_EnableSDADCAnalog                   HAL_PWREx_EnableSDADC           /* 使能SDADC模拟部分 */
#define HAL_PWREx_PVMConfig                           HAL_PWREx_ConfigPVM             /* 配置可编程电压监视器 */

#define PWR_MODE_NORMAL                               PWR_PVD_MODE_NORMAL            /* 正常模式 */
#define PWR_MODE_IT_RISING                            PWR_PVD_MODE_IT_RISING         /* 上升沿中断模式 */
#define PWR_MODE_IT_FALLING                           PWR_PVD_MODE_IT_FALLING        /* 下降沿中断模式 */
#define PWR_MODE_IT_RISING_FALLING                    PWR_PVD_MODE_IT_RISING_FALLING /* 上升沿和下降沿中断模式 */
#define PWR_MODE_EVENT_RISING                         PWR_PVD_MODE_EVENT_RISING      /* 上升沿事件模式 */
#define PWR_MODE_EVENT_FALLING                        PWR_PVD_MODE_EVENT_FALLING     /* 下降沿事件模式 */
#define PWR_MODE_EVENT_RISING_FALLING                 PWR_PVD_MODE_EVENT_RISING_FALLING /* 上升沿和下降沿事件模式 */

#define CR_OFFSET_BB                                  PWR_CR_OFFSET_BB               /* 控制寄存器位带偏移量 */
#define CSR_OFFSET_BB                                 PWR_CSR_OFFSET_BB              /* 控制/状态寄存器位带偏移量 */
#define PMODE_BIT_NUMBER                              VOS_BIT_NUMBER                 /* 电源模式位编号 */
#define CR_PMODE_BB                                   CR_VOS_BB                      /* 控制寄存器电源模式位带别名 */

#define DBP_BitNumber                                 DBP_BIT_NUMBER                 /* 禁用备份保护位编号 */
#define PVDE_BitNumber                                PVDE_BIT_NUMBER                /* 可编程电压检测器使能位编号 */
#define PMODE_BitNumber                               PMODE_BIT_NUMBER               /* 电源模式位编号 */
#define EWUP_BitNumber                                EWUP_BIT_NUMBER                /* 使能唤醒引脚位编号 */
#define FPDS_BitNumber                                FPDS_BIT_NUMBER                /* Flash掉电模式使能位编号 */
#define ODEN_BitNumber                                ODEN_BIT_NUMBER                /* 过驱动使能位编号 */
#define ODSWEN_BitNumber                              ODSWEN_BIT_NUMBER              /* 过驱动软件使能位编号 */
#define MRLVDS_BitNumber                              MRLVDS_BIT_NUMBER              /* 主调节器低电压检测状态位编号 */
#define LPLVDS_BitNumber                              LPLVDS_BIT_NUMBER              /* 低功耗调节器低电压检测状态位编号 */
#define BRE_BitNumber                                 BRE_BIT_NUMBER                 /* 备份寄存器复位使能位编号 */

#define PWR_MODE_EVT                                  PWR_PVD_MODE_NORMAL            /* 事件模式（已弃用，使用正常模式） */

#if defined (STM32U5)
#define PWR_SRAM1_PAGE1_STOP_RETENTION                PWR_SRAM1_PAGE1_STOP           /* SRAM1页1在停止模式下保持数据 */
#define PWR_SRAM1_PAGE2_STOP_RETENTION                PWR_SRAM1_PAGE2_STOP           /* SRAM1页2在停止模式下保持数据 */
#define PWR_SRAM1_PAGE3_STOP_RETENTION                PWR_SRAM1_PAGE3_STOP           /* SRAM1页3在停止模式下保持数据 */
#define PWR_SRAM1_PAGE4_STOP_RETENTION                PWR_SRAM1_PAGE4_STOP           /* SRAM1页4在停止模式下保持数据 */
#define PWR_SRAM1_PAGE5_STOP_RETENTION                PWR_SRAM1_PAGE5_STOP           /* SRAM1页5在停止模式下保持数据 */
#define PWR_SRAM1_PAGE6_STOP_RETENTION                PWR_SRAM1_PAGE6_STOP           /* SRAM1页6在停止模式下保持数据 */
#define PWR_SRAM1_PAGE7_STOP_RETENTION                PWR_SRAM1_PAGE7_STOP           /* SRAM1页7在停止模式下保持数据 */
#define PWR_SRAM1_PAGE8_STOP_RETENTION                PWR_SRAM1_PAGE8_STOP           /* SRAM1页8在停止模式下保持数据 */
#define PWR_SRAM1_PAGE9_STOP_RETENTION                PWR_SRAM1_PAGE9_STOP           /* SRAM1页9在停止模式下保持数据 */
#define PWR_SRAM1_PAGE10_STOP_RETENTION               PWR_SRAM1_PAGE10_STOP          /* SRAM1页10在停止模式下保持数据 */
#define PWR_SRAM1_PAGE11_STOP_RETENTION               PWR_SRAM1_PAGE11_STOP          /* SRAM1页11在停止模式下保持数据 */
#define PWR_SRAM1_PAGE12_STOP_RETENTION               PWR_SRAM1_PAGE12_STOP          /* SRAM1页12在停止模式下保持数据 */
#define PWR_SRAM1_FULL_STOP_RETENTION                 PWR_SRAM1_FULL_STOP            /* SRAM1全部分区在停止模式下保持数据 */

#define PWR_SRAM2_PAGE1_STOP_RETENTION                PWR_SRAM2_PAGE1_STOP           /* SRAM2页1在停止模式下保持数据 */
#define PWR_SRAM2_PAGE2_STOP_RETENTION                PWR_SRAM2_PAGE2_STOP           /* SRAM2页2在停止模式下保持数据 */
#define PWR_SRAM2_FULL_STOP_RETENTION                 PWR_SRAM2_FULL_STOP            /* SRAM2全部分区在停止模式下保持数据 */
#define PWR_SRAM3_PAGE1_STOP_RETENTION                PWR_SRAM3_PAGE1_STOP  // SRAM3页面1在停止模式下的保留设置，作为PWR_SRAM3_PAGE1_STOP的别名
#define PWR_SRAM3_PAGE2_STOP_RETENTION                PWR_SRAM3_PAGE2_STOP  // SRAM3页面2在停止模式下的保留设置，作为PWR_SRAM3_PAGE2_STOP的别名
#define PWR_SRAM3_PAGE3_STOP_RETENTION                PWR_SRAM3_PAGE3_STOP  // SRAM3页面3在停止模式下的保留设置，作为PWR_SRAM3_PAGE3_STOP的别名
#define PWR_SRAM3_PAGE4_STOP_RETENTION                PWR_SRAM3_PAGE4_STOP  // SRAM3页面4在停止模式下的保留设置，作为PWR_SRAM3_PAGE4_STOP的别名
#define PWR_SRAM3_PAGE5_STOP_RETENTION                PWR_SRAM3_PAGE5_STOP  // SRAM3页面5在停止模式下的保留设置，作为PWR_SRAM3_PAGE5_STOP的别名
#define PWR_SRAM3_PAGE6_STOP_RETENTION                PWR_SRAM3_PAGE6_STOP  // SRAM3页面6在停止模式下的保留设置，作为PWR_SRAM3_PAGE6_STOP的别名
#define PWR_SRAM3_PAGE7_STOP_RETENTION                PWR_SRAM3_PAGE7_STOP  // SRAM3页面7在停止模式下的保留设置，作为PWR_SRAM3_PAGE7_STOP的别名
#define PWR_SRAM3_PAGE8_STOP_RETENTION                PWR_SRAM3_PAGE8_STOP  // SRAM3页面8在停止模式下的保留设置，作为PWR_SRAM3_PAGE8_STOP的别名
#define PWR_SRAM3_PAGE9_STOP_RETENTION                PWR_SRAM3_PAGE9_STOP  // SRAM3页面9在停止模式下的保留设置，作为PWR_SRAM3_PAGE9_STOP的别名
#define PWR_SRAM3_PAGE10_STOP_RETENTION               PWR_SRAM3_PAGE10_STOP // SRAM3页面10在停止模式下的保留设置，作为PWR_SRAM3_PAGE10_STOP的别名
#define PWR_SRAM3_PAGE11_STOP_RETENTION               PWR_SRAM3_PAGE11_STOP // SRAM3页面11在停止模式下的保留设置，作为PWR_SRAM3_PAGE11_STOP的别名
#define PWR_SRAM3_PAGE12_STOP_RETENTION               PWR_SRAM3_PAGE12_STOP // SRAM3页面12在停止模式下的保留设置，作为PWR_SRAM3_PAGE12_STOP的别名
#define PWR_SRAM3_PAGE13_STOP_RETENTION               PWR_SRAM3_PAGE13_STOP // SRAM3页面13在停止模式下的保留设置，作为PWR_SRAM3_PAGE13_STOP的别名
#define PWR_SRAM3_FULL_STOP_RETENTION                 PWR_SRAM3_FULL_STOP   // SRAM3全部分区在停止模式下的保留设置，作为PWR_SRAM3_FULL_STOP的别名

#define PWR_SRAM4_FULL_STOP_RETENTION                 PWR_SRAM4_FULL_STOP   // SRAM4全部分区在停止模式下的保留设置，作为PWR_SRAM4_FULL_STOP的别名

#define PWR_SRAM5_PAGE1_STOP_RETENTION                PWR_SRAM5_PAGE1_STOP  // SRAM5页面1在停止模式下的保留设置，作为PWR_SRAM5_PAGE1_STOP的别名
#define PWR_SRAM5_PAGE2_STOP_RETENTION                PWR_SRAM5_PAGE2_STOP  // SRAM5页面2在停止模式下的保留设置，作为PWR_SRAM5_PAGE2_STOP的别名
#define PWR_SRAM5_PAGE3_STOP_RETENTION                PWR_SRAM5_PAGE3_STOP  // SRAM5页面3在停止模式下的保留设置，作为PWR_SRAM5_PAGE3_STOP的别名
#define PWR_SRAM5_PAGE4_STOP_RETENTION                PWR_SRAM5_PAGE4_STOP  // SRAM5页面4在停止模式下的保留设置，作为PWR_SRAM5_PAGE4_STOP的别名
#define PWR_SRAM5_PAGE5_STOP_RETENTION                PWR_SRAM5_PAGE5_STOP  // SRAM5页面5在停止模式下的保留设置，作为PWR_SRAM5_PAGE5_STOP的别名
#define PWR_SRAM5_PAGE6_STOP_RETENTION                PWR_SRAM5_PAGE6_STOP  // SRAM5页面6在停止模式下的保留设置，作为PWR_SRAM5_PAGE6_STOP的别名
#define PWR_SRAM5_PAGE7_STOP_RETENTION                PWR_SRAM5_PAGE7_STOP  // SRAM5页面7在停止模式下的保留设置，作为PWR_SRAM5_PAGE7_STOP的别名
#define PWR_SRAM5_PAGE8_STOP_RETENTION                PWR_SRAM5_PAGE8_STOP  // SRAM5页面8在停止模式下的保留设置，作为PWR_SRAM5_PAGE8_STOP的别名
#define PWR_SRAM5_PAGE9_STOP_RETENTION                PWR_SRAM5_PAGE9_STOP  // SRAM5页面9在停止模式下的保留设置，作为PWR_SRAM5_PAGE9_STOP的别名
#define PWR_SRAM5_PAGE10_STOP_RETENTION               PWR_SRAM5_PAGE10_STOP // SRAM5页面10在停止模式下的保留设置，作为PWR_SRAM5_PAGE10_STOP的别名
#define PWR_SRAM5_PAGE11_STOP_RETENTION               PWR_SRAM5_PAGE11_STOP // SRAM5页面11在停止模式下的保留设置，作为PWR_SRAM5_PAGE11_STOP的别名
#define PWR_SRAM5_PAGE12_STOP_RETENTION               PWR_SRAM5_PAGE12_STOP // SRAM5页面12在停止模式下的保留设置，作为PWR_SRAM5_PAGE12_STOP的别名
#define PWR_SRAM5_PAGE13_STOP_RETENTION               PWR_SRAM5_PAGE13_STOP // SRAM5页面13在停止模式下的保留设置，作为PWR_SRAM5_PAGE13_STOP的别名
#define PWR_SRAM5_FULL_STOP_RETENTION                 PWR_SRAM5_FULL_STOP   // SRAM5全部分区在停止模式下的保留设置，作为PWR_SRAM5_FULL_STOP的别名

#define PWR_SRAM6_PAGE1_STOP_RETENTION                PWR_SRAM6_PAGE1_STOP  // SRAM6页面1在停止模式下的保留设置，作为PWR_SRAM6_PAGE1_STOP的别名
#define PWR_SRAM6_PAGE2_STOP_RETENTION                PWR_SRAM6_PAGE2_STOP  // SRAM6页面2在停止模式下的保留设置，作为PWR_SRAM6_PAGE2_STOP的别名
#define PWR_SRAM6_PAGE3_STOP_RETENTION                PWR_SRAM6_PAGE3_STOP  // SRAM6页面3在停止模式下的保留设置，作为PWR_SRAM6_PAGE3_STOP的别名
#define PWR_SRAM6_PAGE4_STOP_RETENTION                PWR_SRAM6_PAGE4_STOP  // SRAM6页面4在停止模式下的保留设置，作为PWR_SRAM6_PAGE4_STOP的别名
#define PWR_SRAM6_PAGE5_STOP_RETENTION                PWR_SRAM6_PAGE5_STOP  // SRAM6页面5在停止模式下的保留设置，作为PWR_SRAM6_PAGE5_STOP的别名
#define PWR_SRAM6_PAGE6_STOP_RETENTION                PWR_SRAM6_PAGE6_STOP  // SRAM6页面6在停止模式下的保留设置，作为PWR_SRAM6_PAGE6_STOP的别名
#define PWR_SRAM6_PAGE7_STOP_RETENTION                PWR_SRAM6_PAGE7_STOP  // SRAM6页面7在停止模式下的保留设置，作为PWR_SRAM6_PAGE7_STOP的别名
#define PWR_SRAM6_PAGE8_STOP_RETENTION                PWR_SRAM6_PAGE8_STOP  // SRAM6页面8在停止模式下的保留设置，作为PWR_SRAM6_PAGE8_STOP的别名
#define PWR_SRAM6_FULL_STOP_RETENTION                 PWR_SRAM6_FULL_STOP   // SRAM6全部分区在停止模式下的保留设置，作为PWR_SRAM6_FULL_STOP的别名

#define PWR_ICACHE_FULL_STOP_RETENTION                PWR_ICACHE_FULL_STOP  // 指令缓存全部分区在停止模式下的保留设置，作为PWR_ICACHE_FULL_STOP的别名
#define PWR_DCACHE1_FULL_STOP_RETENTION               PWR_DCACHE1_FULL_STOP // 数据缓存1全部分区在停止模式下的保留设置，作为PWR_DCACHE1_FULL_STOP的别名
#define PWR_DCACHE2_FULL_STOP_RETENTION               PWR_DCACHE2_FULL_STOP // 数据缓存2全部分区在停止模式下的保留设置，作为PWR_DCACHE2_FULL_STOP的别名
#define PWR_DMA2DRAM_FULL_STOP_RETENTION              PWR_DMA2DRAM_FULL_STOP // DMA到DRAM全部分区在停止模式下的保留设置，作为PWR_DMA2DRAM_FULL_STOP的别名
#define PWR_PERIPHRAM_FULL_STOP_RETENTION             PWR_PERIPHRAM_FULL_STOP // 外设RAM全部分区在停止模式下的保留设置，作为PWR_PERIPHRAM_FULL_STOP的别名
#define PWR_PKA32RAM_FULL_STOP_RETENTION              PWR_PKA32RAM_FULL_STOP // PKA32 RAM全部分区在停止模式下的保留设置，作为PWR_PKA32RAM_FULL_STOP的别名
#define PWR_GRAPHICPRAM_FULL_STOP_RETENTION           PWR_GRAPHICPRAM_FULL_STOP // 图形处理RAM全部分区在停止模式下的保留设置，作为PWR_GRAPHICPRAM_FULL_STOP的别名
#define PWR_DSIRAM_FULL_STOP_RETENTION                PWR_DSIRAM_FULL_STOP // DSI RAM全部分区在停止模式下的保留设置，作为PWR_DSIRAM_FULL_STOP的别名
#define PWR_JPEGRAM_FULL_STOP_RETENTION               PWR_JPEGRAM_FULL_STOP // JPEG RAM全部分区在停止模式下的保留设置，作为PWR_JPEGRAM_FULL_STOP的别名

#define PWR_SRAM2_PAGE1_STANDBY_RETENTION             PWR_SRAM2_PAGE1_STANDBY // SRAM2页面1在待机模式下的保留设置，作为PWR_SRAM2_PAGE1_STANDBY的别名
#define PWR_SRAM2_PAGE2_STANDBY_RETENTION             PWR_SRAM2_PAGE2_STANDBY // SRAM2页面2在待机模式下的保留设置，作为PWR_SRAM2_PAGE2_STANDBY的别名
#define PWR_SRAM2_FULL_STANDBY_RETENTION              PWR_SRAM2_FULL_STANDBY  // SRAM2全部分区在待机模式下的保留设置，作为PWR_SRAM2_FULL_STANDBY的别名

#define PWR_SRAM1_FULL_RUN_RETENTION                  PWR_SRAM1_FULL_RUN // SRAM1全部分区在运行模式下的保留设置，作为PWR_SRAM1_FULL_RUN的别名
#define PWR_SRAM2_FULL_RUN_RETENTION                  PWR_SRAM2_FULL_RUN // SRAM2全部分区在运行模式下的保留设置，作为PWR_SRAM2_FULL_RUN的别名
#define PWR_SRAM3_FULL_RUN_RETENTION                  PWR_SRAM3_FULL_RUN // SRAM3全部分区在运行模式下的保留设置，作为PWR_SRAM3_FULL_RUN的别名
#define PWR_SRAM4_FULL_RUN_RETENTION                  PWR_SRAM4_FULL_RUN // SRAM4全部分区在运行模式下的保留设置，作为PWR_SRAM4_FULL_RUN的别名
#define PWR_SRAM5_FULL_RUN_RETENTION                  PWR_SRAM5_FULL_RUN // SRAM5全部分区在运行模式下的保留设置，作为PWR_SRAM5_FULL_RUN的别名
#define PWR_SRAM6_FULL_RUN_RETENTION                  PWR_SRAM6_FULL_RUN // SRAM6全部分区在运行模式下的保留设置，作为PWR_SRAM6_FULL_RUN的别名

#define PWR_ALL_RAM_RUN_RETENTION_MASK                PWR_ALL_RAM_RUN_MASK // 所有RAM在运行模式下的保留设置掩码，作为PWR_ALL_RAM_RUN_MASK的别名
#endif

/**
  * @}
 */

/** @defgroup HAL_RTC_Aliased_Functions HAL RTC 别名函数，为向后兼容而保留
  * @{
  */
#if defined(STM32H5) || defined(STM32WBA) || defined(STM32H7RS)
#define HAL_RTCEx_SetBoothardwareKey            HAL_RTCEx_LockBootHardwareKey  // 别名宏，用于向后兼容，实际调用HAL_RTCEx_LockBootHardwareKey
#define HAL_RTCEx_BKUPBlock_Enable              HAL_RTCEx_BKUPBlock            // 别名宏，用于向后兼容，实际调用HAL_RTCEx_BKUPBlock
#define HAL_RTCEx_BKUPBlock_Disable             HAL_RTCEx_BKUPUnblock          // 别名宏，用于向后兼容，实际调用HAL_RTCEx_BKUPUnblock
#define HAL_RTCEx_Erase_SecretDev_Conf          HAL_RTCEx_ConfigEraseDeviceSecrets // 别名宏，用于向后兼容，实际调用HAL_RTCEx_ConfigEraseDeviceSecrets
#endif /* STM32H5 || STM32WBA || STM32H7RS */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Functions HAL SMBUS 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_SMBUS_Slave_Listen_IT          HAL_SMBUS_EnableListen_IT          // 别名宏，用于向后兼容，实际调用HAL_SMBUS_EnableListen_IT
#define HAL_SMBUS_SlaveAddrCallback        HAL_SMBUS_AddrCallback             // 别名宏，用于向后兼容，实际调用HAL_SMBUS_AddrCallback
#define HAL_SMBUS_SlaveListenCpltCallback  HAL_SMBUS_ListenCpltCallback       // 别名宏，用于向后兼容，实际调用HAL_SMBUS_ListenCpltCallback
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Functions HAL SPI 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_SPI_FlushRxFifo                HAL_SPIEx_FlushRxFifo              // 别名宏，用于向后兼容，实际调用HAL_SPIEx_FlushRxFifo
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Functions HAL TIM 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_TIM_DMADelayPulseCplt                       TIM_DMADelayPulseCplt // 别名宏，用于向后兼容，实际调用TIM_DMADelayPulseCplt
#define HAL_TIM_DMAError                                TIM_DMAError          // 别名宏，用于向后兼容，实际调用TIM_DMAError
#define HAL_TIM_DMACaptureCplt                          TIM_DMACaptureCplt    // 别名宏，用于向后兼容，实际调用TIM_DMACaptureCplt
#define HAL_TIMEx_DMACommutationCplt                    TIMEx_DMACommutationCplt // 别名宏，用于向后兼容，实际调用TIMEx_DMACommutationCplt
#if defined(STM32H7) || defined(STM32G0) || defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || \
    defined(STM32F3) || defined(STM32F4) || defined(STM32F7) || defined(STM32L0) || defined(STM32L4)
#define HAL_TIM_SlaveConfigSynchronization              HAL_TIM_SlaveConfigSynchro // 别名宏，用于向后兼容，实际调用HAL_TIM_SlaveConfigSynchro
#define HAL_TIM_SlaveConfigSynchronization_IT           HAL_TIM_SlaveConfigSynchro_IT // 别名宏，用于向后兼容，实际调用HAL_TIM_SlaveConfigSynchro_IT
#define HAL_TIMEx_CommutationCallback                   HAL_TIMEx_CommutCallback // 别名宏，用于向后兼容，实际调用HAL_TIMEx_CommutCallback
#define HAL_TIMEx_ConfigCommutationEvent                HAL_TIMEx_ConfigCommutEvent // 别名宏，用于向后兼容，实际调用HAL_TIMEx_ConfigCommutEvent
#define HAL_TIMEx_ConfigCommutationEvent_IT             HAL_TIMEx_ConfigCommutEvent_IT // 别名宏，用于向后兼容，实际调用HAL_TIMEx_ConfigCommutEvent_IT
#define HAL_TIMEx_ConfigCommutationEvent_DMA            HAL_TIMEx_ConfigCommutEvent_DMA // 别名宏，用于向后兼容，实际调用HAL_TIMEx_ConfigCommutEvent_DMA
#endif /* STM32H7 || STM32G0 || STM32F0 || STM32F1 || STM32F2 || STM32F3 || STM32F4 || STM32F7 || STM32L0 */
/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Functions HAL UART 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_UART_WakeupCallback HAL_UARTEx_WakeupCallback // 别名宏，用于向后兼容，实际调用HAL_UARTEx_WakeupCallback
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Functions HAL LTDC 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_LTDC_LineEvenCallback HAL_LTDC_LineEventCallback // 别名宏，用于向后兼容，实际调用HAL_LTDC_LineEventCallback
#define HAL_LTDC_Relaod           HAL_LTDC_Reload            // 别名宏，用于向后兼容，实际调用HAL_LTDC_Reload
#define HAL_LTDC_StructInitFromVideoConfig  HAL_LTDCEx_StructInitFromVideoConfig // 别名宏，用于向后兼容，实际调用HAL_LTDCEx_StructInitFromVideoConfig
#define HAL_LTDC_StructInitFromAdaptedCommandConfig  HAL_LTDCEx_StructInitFromAdaptedCommandConfig // 别名宏，用于向后兼容，实际调用HAL_LTDCEx_StructInitFromAdaptedCommandConfig
/**
  * @}
  */


/** @defgroup HAL_PPP_Aliased_Functions HAL PPP 别名函数，为向后兼容而保留
  * @{
  */

/**
  * @}
  */

/* 导出的宏 ------------------------------------------------------------*/

/** @defgroup HAL_AES_Aliased_Macros HAL CRYP 别名宏，为向后兼容而保留
  * @{
  */
#define AES_IT_CC                      CRYP_IT_CC   // 别名宏，用于向后兼容，实际使用CRYP_IT_CC
#define AES_IT_ERR                     CRYP_IT_ERR  // 别名宏，用于向后兼容，实际使用CRYP_IT_ERR
#define AES_FLAG_CCF                   CRYP_FLAG_CCF // 别名宏，用于向后兼容，实际使用CRYP_FLAG_CCF
/**
  * @}
  */

/** @defgroup HAL_Aliased_Macros HAL 通用别名宏，为向后兼容而保留
  * @{
  */
#define __HAL_GET_BOOT_MODE                   __HAL_SYSCFG_GET_BOOT_MODE // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_GET_BOOT_MODE
#define __HAL_REMAPMEMORY_FLASH               __HAL_SYSCFG_REMAPMEMORY_FLASH // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_FLASH
#define __HAL_REMAPMEMORY_SYSTEMFLASH         __HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_SYSTEMFLASH
#define __HAL_REMAPMEMORY_SRAM                __HAL_SYSCFG_REMAPMEMORY_SRAM // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_SRAM
#define __HAL_REMAPMEMORY_FMC                 __HAL_SYSCFG_REMAPMEMORY_FMC // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_FMC
#define __HAL_REMAPMEMORY_FMC_SDRAM           __HAL_SYSCFG_REMAPMEMORY_FMC_SDRAM // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_FMC_SDRAM
#define __HAL_REMAPMEMORY_FSMC                __HAL_SYSCFG_REMAPMEMORY_FSMC // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_FSMC
#define __HAL_REMAPMEMORY_QUADSPI             __HAL_SYSCFG_REMAPMEMORY_QUADSPI // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_REMAPMEMORY_QUADSPI
#define __HAL_FMC_BANK                        __HAL_SYSCFG_FMC_BANK // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_FMC_BANK
#define __HAL_GET_FLAG                        __HAL_SYSCFG_GET_FLAG // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_GET_FLAG
#define __HAL_CLEAR_FLAG                      __HAL_SYSCFG_CLEAR_FLAG // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_CLEAR_FLAG
#define __HAL_VREFINT_OUT_ENABLE              __HAL_SYSCFG_VREFINT_OUT_ENABLE // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_VREFINT_OUT_ENABLE
#define __HAL_VREFINT_OUT_DISABLE             __HAL_SYSCFG_VREFINT_OUT_DISABLE // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_VREFINT_OUT_DISABLE
#define __HAL_SYSCFG_SRAM2_WRP_ENABLE         __HAL_SYSCFG_SRAM2_WRP_0_31_ENABLE // 别名宏，用于向后兼容，实际调用__HAL_SYSCFG_SRAM2_WRP_0_31_ENABLE

#define SYSCFG_FLAG_VREF_READY                SYSCFG_FLAG_VREFINT_READY // 别名宏，用于向后兼容，实际使用SYSCFG_FLAG_VREFINT_READY
#define SYSCFG_FLAG_RC48                      RCC_FLAG_HSI48            // 别名宏，用于向后兼容，实际使用RCC_FLAG_HSI48
#define IS_SYSCFG_FASTMODEPLUS_CONFIG         IS_I2C_FASTMODEPLUS       // 别名宏，用于向后兼容，实际使用IS_I2C_FASTMODEPLUS
#define UFB_MODE_BitNumber                    UFB_MODE_BIT_NUMBER      // 别名宏，用于向后兼容，实际使用UFB_MODE_BIT_NUMBER
#define CMP_PD_BitNumber                      CMP_PD_BIT_NUMBER        // 别名宏，用于向后兼容，实际使用CMP_PD_BIT_NUMBER

/**
  * @}
  */
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
/** @defgroup HAL_COMP_Aliased_Macros HAL COMP 别名宏，为遗留目的维护
  * @{
  */
#if defined(STM32F3) /* 条件编译：仅在STM32F3系列芯片中定义 */
#define COMP_START                                       __HAL_COMP_ENABLE /* 启动比较器的别名宏 */
#define COMP_STOP                                        __HAL_COMP_DISABLE /* 停止比较器的别名宏 */
#define COMP_LOCK                                        __HAL_COMP_LOCK /* 锁定比较器配置的别名宏 */
#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || defined(STM32F303x8) || \
    defined(STM32F334x8) || defined(STM32F328xx)
/* 针对特定STM32型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#if defined(STM32F302xE) || defined(STM32F302xC)
/* 针对STM32F302xE/F302xC型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#if defined(STM32F303xE) || defined(STM32F398xx) || defined(STM32F303xC) || defined(STM32F358xx)
/* 针对STM32F303xE/F398xx/F303xC/F358xx型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#if defined(STM32F373xC) ||defined(STM32F378xx)
/* 针对STM32F373xC/F378xx型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#else
/* 默认情况下的比较器(COMP)外部中断(EXTI)配置宏（针对其他STM32型号） */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#define __HAL_COMP_GET_EXTI_LINE  COMP_GET_EXTI_LINE  // 获取比较器EXTI线的宏，映射到COMP_GET_EXTI_LINE

#if defined(STM32L0) || defined(STM32L4)
/* 注意：在这些STM32系列中，这个宏的唯一参数是COMP_FLAG_LOCK。                   */
/*       这个宏被__HAL_COMP_IS_LOCKED替换，只使用HAL句柄参数。                    */
#define __HAL_COMP_GET_FLAG(__HANDLE__, __FLAG__)  (__HAL_COMP_IS_LOCKED(__HANDLE__))  // 获取比较器标志的宏，但在STM32L0/L4上映射到__HAL_COMP_IS_LOCKED，仅检查锁定状态
#endif
/**
  * @}
  */

#if defined(STM32L0) || defined(STM32L4)
/** @defgroup HAL_COMP_Aliased_Functions HAL COMP 别名函数，为向后兼容而保留
  * @{
  */
#define HAL_COMP_Start_IT       HAL_COMP_Start /* 该函数被视为遗留函数，因为EXTI事件或中断配置已在HAL_COMP_Init()中完成 */
#define HAL_COMP_Stop_IT        HAL_COMP_Stop  /* 该函数被视为遗留函数，因为EXTI事件或中断配置已在HAL_COMP_Init()中完成 */
/**
  * @}
  */
#endif

/** @defgroup HAL_DAC_Aliased_Macros HAL DAC 别名宏，为向后兼容而保留
  * @{
  */

#define IS_DAC_WAVE(WAVE) (((WAVE) == DAC_WAVE_NONE) || \
                           ((WAVE) == DAC_WAVE_NOISE)|| \
                           ((WAVE) == DAC_WAVE_TRIANGLE))  // 检查DAC波形类型是否有效的宏，支持无波形、噪声波形和三角波形

/**
  * @}
  */

/** @defgroup HAL_FLASH_Aliased_Macros HAL FLASH 别名宏，为向后兼容而保留
  * @{
  */

#define IS_WRPAREA          IS_OB_WRPAREA  // 检查写保护区域的宏，映射到IS_OB_WRPAREA
#define IS_TYPEPROGRAM      IS_FLASH_TYPEPROGRAM  // 检查编程类型的宏，映射到IS_FLASH_TYPEPROGRAM
#define IS_TYPEPROGRAMFLASH IS_FLASH_TYPEPROGRAM  // 检查Flash编程类型的宏，映射到IS_FLASH_TYPEPROGRAM
#define IS_TYPEERASE        IS_FLASH_TYPEERASE  // 检查擦除类型的宏，映射到IS_FLASH_TYPEERASE
#define IS_NBSECTORS        IS_FLASH_NBSECTORS  // 检查扇区数量的宏，映射到IS_FLASH_NBSECTORS
#define IS_OB_WDG_SOURCE    IS_OB_IWDG_SOURCE  // 检查看门狗时钟源的宏，映射到IS_OB_IWDG_SOURCE

/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Macros HAL I2C 别名宏，为向后兼容而保留
  * @{
  */

#define __HAL_I2C_RESET_CR2             I2C_RESET_CR2  // 重置I2C控制寄存器2的宏
#define __HAL_I2C_GENERATE_START        I2C_GENERATE_START  // 生成I2C起始条件的宏
#if defined(STM32F1)
#define __HAL_I2C_FREQ_RANGE            I2C_FREQRANGE  // 设置I2C频率范围的宏（STM32F1专用）
#else
#define __HAL_I2C_FREQ_RANGE            I2C_FREQ_RANGE  // 设置I2C频率范围的宏
#endif /* STM32F1 */
#define __HAL_I2C_RISE_TIME             I2C_RISE_TIME  // 设置I2C上升时间的宏
#define __HAL_I2C_SPEED_STANDARD        I2C_SPEED_STANDARD  // 设置I2C标准速度的宏
#define __HAL_I2C_SPEED_FAST            I2C_SPEED_FAST  // 设置I2C快速速度的宏
#define __HAL_I2C_SPEED                 I2C_SPEED  // 设置I2C速度的宏
#define __HAL_I2C_7BIT_ADD_WRITE        I2C_7BIT_ADD_WRITE  // 生成7位地址写操作的宏
#define __HAL_I2C_7BIT_ADD_READ         I2C_7BIT_ADD_READ  // 生成7位地址读操作的宏
#define __HAL_I2C_10BIT_ADDRESS         I2C_10BIT_ADDRESS  // 生成10位地址的宏
#define __HAL_I2C_10BIT_HEADER_WRITE    I2C_10BIT_HEADER_WRITE  // 生成10位地址写头部的宏
#define __HAL_I2C_10BIT_HEADER_READ     I2C_10BIT_HEADER_READ  // 生成10位地址读头部的宏
#define __HAL_I2C_MEM_ADD_MSB           I2C_MEM_ADD_MSB  // 设置内存地址高字节的宏
#define __HAL_I2C_MEM_ADD_LSB           I2C_MEM_ADD_LSB  // 设置内存地址低字节的宏
#define __HAL_I2C_FREQRANGE             I2C_FREQRANGE  // 设置I2C频率范围的宏（同__HAL_I2C_FREQ_RANGE）

/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Macros HAL I2S 别名宏，为向后兼容而保留
  * @{
  */

#define IS_I2S_INSTANCE                 IS_I2S_ALL_INSTANCE  // 检查I2S实例是否有效的宏，映射到IS_I2S_ALL_INSTANCE
#define IS_I2S_INSTANCE_EXT             IS_I2S_ALL_INSTANCE_EXT  // 检查扩展I2S实例是否有效的宏，映射到IS_I2S_ALL_INSTANCE_EXT

#if defined(STM32H7)
#define __HAL_I2S_CLEAR_FREFLAG       __HAL_I2S_CLEAR_TIFREFLAG  // 清除I2S帧错误标志的宏（STM32H7专用）
#endif

/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Macros HAL IRDA 别名宏，为向后兼容而保留
  * @{
  */

#define __IRDA_DISABLE                  __HAL_IRDA_DISABLE  // 禁用IRDA的宏，映射到__HAL_IRDA_DISABLE
#define __IRDA_ENABLE                   __HAL_IRDA_ENABLE  // 启用IRDA的宏，映射到__HAL_IRDA_ENABLE

#define __HAL_IRDA_GETCLOCKSOURCE       IRDA_GETCLOCKSOURCE  // 获取IRDA时钟源的宏
#define __HAL_IRDA_MASK_COMPUTATION     IRDA_MASK_COMPUTATION  // 计算IRDA掩码的宏
#define __IRDA_GETCLOCKSOURCE           IRDA_GETCLOCKSOURCE  // 获取IRDA时钟源的宏（同__HAL_AL_IRDA_GETCLOCKSOURCE）
#define __IRDA_MASK_COMPUTATION         IRDA_MASK_COMPUTATION  // 计算IRDA掩码的宏（同__HAL_IRDA_MASK_COMPUTATION）

#define IS_IRDA_ONEBIT_SAMPLE           IS_IRDA_ONE_BIT_SAMPLE  // 检查IRDA单比特采样是否有效的宏，映射到IS_IRDA_ONE_BIT_SAMPLE


/**
  * @}
  */


/** @defgroup HAL_IWDG_Aliased_Macros HAL IWDG 别名宏，为向后兼容而保留
  * @{
  */
#define __HAL_IWDG_ENABLE_WRITE_ACCESS  IWDG_ENABLE_WRITE_ACCESS  // 启用IWDG写访问的宏
#define __HAL_IWDG_DISABLE_WRITE_ACCESS IWDG_DISABLE_WRITE_ACCESS  // 禁用IWDG写访问的宏
/**
  * @}
  */


/** @defgroup HAL_LPTIM_Aliased_Macros HAL LPTIM 别名宏，为向后兼容而保留
  * @{
  */

#define __HAL_LPTIM_ENABLE_INTERRUPT    __HAL_LPTIM_ENABLE_IT  // 启用LPTIM中断的宏，映射到__HAL_LPTIM_ENABLE_IT
#define __HAL_LPTIM_DISABLE_INTERRUPT   __HAL_LPTIM_DISABLE_IT  // 禁用LPTIM中断的宏，映射到__HAL_LPTIM_DISABLE_IT
#define __HAL_LPTIM_GET_ITSTATUS        __HAL_LPTIM_GET_IT_SOURCE  // 获取LPTIM中断状态的宏，映射到__HAL_LPTIM_GET_IT_SOURCE

/**
  * @}
  */


/** @defgroup HAL_OPAMP_Aliased_Macros HAL OPAMP 别名宏，为向后兼容而保留
  * @{
  */
#define __OPAMP_CSR_OPAXPD                OPAMP_CSR_OPAXPD  // OPAMP控制寄存器中关断位字段的宏
#define __OPAMP_CSR_S3SELX                OPAMP_CSR_S3SELX  // OPAMP控制寄存器中S3选择位字段的宏
#define __OPAMP_CSR_S4SELX                OPAMP_CSR_S4SELX  // OPAMP控制寄存器中S4选择位字段的宏
#define __OPAMP_CSR_S5SELX                OPAMP_CSR_S5SELX  // OPAMP控制寄存器中S5选择位字段的宏
#define __OPAMP_CSR_S6SELX                OPAMP_CSR_S6SELX  // OPAMP控制寄存器中S6选择位字段的宏
#define __OPAMP_CSR_OPAXCAL_L             OPAMP_CSR_OPAXCAL_L  // OPAMP控制寄存器中校准低值位字段的宏
#define __OPAMP_CSR_OPAXCAL_H             OPAMP_CSR_OPAXCAL_H  // OPAMP控制寄存器中校准高值位字段的宏
#define __OPAMP_CSR_OPAXLPM               OPAMP_CSR_OPAXLPM  // OPAMP控制寄存器中低功耗模式位字段的宏
#define __OPAMP_CSR_ALL_SWITCHES          OPAMP_CSR_ALL_SWITCHES  // OPAMP控制寄存器中所有开关位字段的宏
#define __OPAMP_CSR_ANAWSELX              OPAMP_CSR_ANAWSELX  // OPAMP控制寄存器中模拟窗口选择位字段的宏
#define __OPAMP_CSR_OPAXCALOUT            OPAMP_CSR_OPAXCALOUT  // OPAMP控制寄存器中校准输出位字段的宏
#define __OPAMP_OFFSET_TRIM_BITSPOSITION  OPAMP_OFFSET_TRIM_BITSPOSITION  // OPAMP偏移修调位位置的宏
#define __OPAMP_OFFSET_TRIM_SET           OPAMP_OFFSET_TRIM_SET  // OPAMP偏移修调设置的宏

/**
  * @}
  */


/** @defgroup HAL_PWR_Aliased_Macros HAL PWR 别名宏，为向后兼容而保留
  * @{
  */
#define __HAL_PVD_EVENT_DISABLE                                  __HAL_PWR_PVD_EXTI_DISABLE_EVENT  // 禁用PVD事件中断的宏
#define __HAL_PVD_EVENT_ENABLE                                   __HAL_PWR_PVD_EXTI_ENABLE_EVENT  // 启用PVD事件中断的宏
#define __HAL_PVD_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE  // 禁用PVD EXTI下降沿触发的宏
#define __HAL_PVD_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE  // 启用PVD EXTI下降沿触发的宏
#define __HAL_PVD_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE  // 禁用PVD EXTI上升沿触发的宏
#define __HAL_PVD_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE  // 启用PVD EXTI上升沿触发的宏
#define __HAL_PVM_EVENT_DISABLE                                  __HAL_PWR_PVM_EVENT_DISABLE  // 禁用PVM事件中断的宏
#define __HAL_PVM_EVENT_ENABLE                                   __HAL_PWR_PVM_EVENT_ENABLE  // 启用PVM事件中断的宏
#define __HAL_PVM_EXTI_FALLINGTRIGGER_DISABLE                    __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_DISABLE  // 禁用PVM EXTI下降沿触发的宏
#define __HAL_PVM_EXTI_FALLINGTRIGGER_ENABLE                     __HAL_PWR_PVM_EXTI_FALLINGTRIGGER_ENABLE  // 启用PVM EXTI下降沿触发的宏
#define __HAL_PVM_EXTI_RISINGTRIGGER_DISABLE                     __HAL_PWR_PVM_EXTI_RISINGTRIGGER_DISABLE  // 禁用PVM EXTI上升沿触发的宏
#define __HAL_PVM_EXTI_RISINGTRIGGER_ENABLE                      __HAL_PWR_PVM_EXTI_RISINGTRIGGER_ENABLE  // 启用PVM EXTI上升沿触发的宏
#define __HAL_PWR_INTERNALWAKEUP_DISABLE                         HAL_PWREx_DisableInternalWakeUpLine  // 禁用内部唤醒线的宏
#define __HAL_PWR_INTERNALWAKEUP_ENABLE                          HAL_PWREx_EnableInternalWakeUpLine  // 启用内部唤醒线的宏
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_DISABLE                    HAL_PWREx_DisablePullUpPullDownConfig  // 禁用上拉下拉配置的宏
#define __HAL_PWR_PULL_UP_DOWN_CONFIG_ENABLE                     HAL_PWREx_EnablePullUpPullDownConfig  // 启用上拉下拉配置的宏
#define __HAL_PWR_PVD_EXTI_CLEAR_EGDE_TRIGGER()                  do { __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE(); \
                                                                      __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE(); \
                                                                    } while(0)  // 清除PVD EXTI边沿触发的宏，通过禁用上升沿和下降沿实现
#define __HAL_PWR_PVD_EXTI_EVENT_DISABLE                         __HAL_PWR_PVD_EXTI_DISABLE_EVENT  // 禁用PVD EXTI事件中断的宏
#define __HAL_PWR_PVD_EXTI_EVENT_ENABLE                          __HAL_PWR_PVD_EXTI_ENABLE_EVENT  // 启用PVD EXTI事件中断的宏
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_DISABLE                __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE  // 禁用PVD EXTI下降沿触发的宏
#define __HAL_PWR_PVD_EXTI_FALLINGTRIGGER_ENABLE                 __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE  // 启用PVD EXTI下降沿触发的宏
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_DISABLE                 __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE  // 禁用PVD EXTI上升沿触发的宏
#define __HAL_PWR_PVD_EXTI_RISINGTRIGGER_ENABLE                  __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE  // 启用PVD EXTI上升沿触发的宏
#define __HAL_PWR_PVD_EXTI_SET_FALLING_EGDE_TRIGGER              __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE  // 设置PVD EXTI下降沿触发的宏
#define __HAL_PWR_PVD_EXTI_SET_RISING_EDGE_TRIGGER               __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE  // 设置PVD EXTI上升沿触发的宏
#define __HAL_PWR_PVM_DISABLE()                                  do { HAL_PWREx_DisablePVM1();HAL_PWREx_DisablePVM2(); \
                                                                      HAL_PWREx_DisablePVM3();HAL_PWREx_DisablePVM4(); \
                                                                    } while(0)  // 禁用所有PVM的宏
#define __HAL_PWR_PVM_ENABLE()                                   do { HAL_PWREx_EnablePVM1();HAL_PWREx_EnablePVM2(); \
                                                                      HAL_PWREx_EnablePVM3();HAL_PWREx_EnablePVM4(); \
                                                                    } while(0)  // 启用所有PVM的宏
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_DISABLE                  HAL_PWREx_DisableSRAM2ContentRetention  // 禁用SRAM2内容保留的宏
#define __HAL_PWR_SRAM2CONTENT_PRESERVE_ENABLE                   HAL_PWREx_EnableSRAM2ContentRetention  // 启用SRAM2内容保留的宏
#define __HAL_PWR_VDDIO2_DISABLE                                 HAL_PWREx_DisableVddIO2  // 禁用VDDIO2电源的宏
#define __HAL_PWR_VDDIO2_ENABLE                                  HAL_PWREx_EnableVddIO2  // 启用VDDIO2电源的宏
#define __HAL_PWR_VDDIO2_EXTI_CLEAR_EGDE_TRIGGER                 __HAL_PWR_VDDIO2_EXTI_DISABLE_FALLING_EDGE  // 清除VDDIO2 EXTI边沿触发的宏
#define __HAL_PWR_VDDIO2_EXTI_SET_FALLING_EGDE_TRIGGER           __HAL_PWR_VDDIO2_EXTI_ENABLE_FALLING_EDGE  // 设置VDDIO2 EXTI下降沿触发的宏
#define __HAL_PWR_VDDUSB_DISABLE                                 HAL_PWREx_DisableVddUSB  // 禁用VDDUSB电源的宏
#define __HAL_PWR_VDDUSB_ENABLE                                  HAL_PWREx_EnableVddUSB  // 启用VDDUSB电源的宏
#if defined (STM32F4)  // 如果定义了STM32F4系列
#define __HAL_PVD_EXTI_ENABLE_IT(PWR_EXTI_LINE_PVD)         __HAL_PWR_PVD_EXTI_ENABLE_IT()  // 启用PVD（可编程电压检测器）外部中断
#define __HAL_PVD_EXTI_DISABLE_IT(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_DISABLE_IT() // 禁用PVD外部中断
#define __HAL_PVD_EXTI_GET_FLAG(PWR_EXTI_LINE_PVD)          __HAL_PWR_PVD_EXTI_GET_FLAG()   // 获取PVD标志位状态
#define __HAL_PVD_EXTI_CLEAR_FLAG(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_CLEAR_FLAG() // 清除PVD标志位
#define __HAL_PVD_EXTI_GENERATE_SWIT(PWR_EXTI_LINE_PVD)     __HAL_PWR_PVD_EXTI_GENERATE_SWIT() // 生成PVD软件中断（SWIT: Software Interrupt）
#else  // 其他STM32系列
#define __HAL_PVD_EXTI_CLEAR_FLAG                                __HAL_PWR_PVD_EXTI_CLEAR_FLAG  // 清除PVD标志位的别名宏
#define __HAL_PVD_EXTI_DISABLE_IT                                __HAL_PWR_PVD_EXTI_DISABLE_IT // 禁用PVD外部中断的别名宏
#define __HAL_PVD_EXTI_ENABLE_IT                                 __HAL_PWR_PVD_EXTI_ENABLE_IT  // 启用PVD外部中断的别名宏
#define __HAL_PVD_EXTI_GENERATE_SWIT                             __HAL_PWR_PVD_EXTI_GENERATE_SWIT // 生成PVD软件中断的别名宏
#define __HAL_PVD_EXTI_GET_FLAG                                  __HAL_PWR_PVD_EXTI_GET_FLAG   // 获取PVD标志位的别名宏
#endif /* STM32F4 */
/**
  * @}
  */


/** @defgroup HAL_RCC_Aliased 为向后兼容而维护的HAL RCC（复位和时钟控制）别名
  * @{
  */

#define RCC_StopWakeUpClock_MSI     RCC_STOP_WAKEUPCLOCK_MSI  // 停止唤醒时钟使用MSI（内部多速振荡器）的别名
#define RCC_StopWakeUpClock_HSI     RCC_STOP_WAKEUPCLOCK_HSI  // 停止唤醒时钟使用HSI（内部高速振荡器）的别名

#define HAL_RCC_CCSCallback HAL_RCC_CSSCallback  // 时钟安全系统（CSS）回调函数的别名，用于兼容旧代码

#define HAL_RC48_EnableBuffer_Cmd(cmd) (((cmd)==ENABLE) ? \
                                        HAL_RCCEx_EnableHSI48_VREFINT() : HAL_RCCEx_DisableHSI48_VREFINT())  // 宏函数：根据命令启用或禁用HSI48（48MHz内部振荡器）和VREFINT（内部电压参考）缓冲区
/* ADC（模数转换器）时钟控制宏定义 */
#define __ADC_CLK_DISABLE          __HAL_RCC_ADC_CLK_DISABLE          /* 禁用ADC时钟 */
#define __ADC_CLK_ENABLE           __HAL_RCC_ADC_CLK_ENABLE           /* 使能ADC时钟 */
#define __ADC_CLK_SLEEP_DISABLE    __HAL_RCC_ADC_CLK_SLEEP_DISABLE    /* 休眠模式下禁用ADC时钟 */
#define __ADC_CLK_SLEEP_ENABLE     __HAL_RCC_ADC_CLK_SLEEP_ENABLE     /* 休眠模式下使能ADC时钟 */
#define __ADC_FORCE_RESET          __HAL_RCC_ADC_FORCE_RESET          /* 强制复位ADC */
#define __ADC_RELEASE_RESET        __HAL_RCC_ADC_RELEASE_RESET        /* 释放ADC复位 */

/* ADC1（模数转换器1）时钟控制宏定义 */
#define __ADC1_CLK_DISABLE         __HAL_RCC_ADC1_CLK_DISABLE         /* 禁用ADC1时钟 */
#define __ADC1_CLK_ENABLE          __HAL_RCC_ADC1_CLK_ENABLE          /* 使能ADC1时钟 */
#define __ADC1_FORCE_RESET         __HAL_RCC_ADC1_FORCE_RESET         /* 强制复位ADC1 */
#define __ADC1_RELEASE_RESET       __HAL_RCC_ADC1_RELEASE_RESET       /* 释放ADC1复位 */
#define __ADC1_CLK_SLEEP_ENABLE    __HAL_RCC_ADC1_CLK_SLEEP_ENABLE    /* 休眠模式下使能ADC1时钟 */
#define __ADC1_CLK_SLEEP_DISABLE   __HAL_RCC_ADC1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用ADC1时钟 */

/* ADC2（模数转换器2）时钟控制宏定义 */
#define __ADC2_CLK_DISABLE         __HAL_RCC_ADC2_CLK_DISABLE         /* 禁用ADC2时钟 */
#define __ADC2_CLK_ENABLE          __HAL_RCC_ADC2_CLK_ENABLE          /* 使能ADC2时钟 */
#define __ADC2_FORCE_RESET         __HAL_RCC_ADC2_FORCE_RESET         /* 强制复位ADC2 */
#define __ADC2_RELEASE_RESET       __HAL_RCC_ADC2_RELEASE_RESET       /* 释放ADC2复位 */

/* ADC3（模数转换器3）时钟控制宏定义 */
#define __ADC3_CLK_DISABLE         __HAL_RCC_ADC3_CLK_DISABLE         /* 禁用ADC3时钟 */
#define __ADC3_CLK_ENABLE          __HAL_RCC_ADC3_CLK_ENABLE          /* 使能ADC3时钟 */
#define __ADC3_FORCE_RESET         __HAL_RCC_ADC3_FORCE_RESET         /* 强制复位ADC3 */
#define __ADC3_RELEASE_RESET       __HAL_RCC_ADC3_RELEASE_RESET       /* 释放ADC3复位 */

/* AES（高级加密标准）时钟控制宏定义 */
#define __AES_CLK_DISABLE          __HAL_RCC_AES_CLK_DISABLE          /* 禁用AES时钟 */
#define __AES_CLK_ENABLE           __HAL_RCC_AES_CLK_ENABLE           /* 使能AES时钟 */
#define __AES_CLK_SLEEP_DISABLE    __HAL_RCC_AES_CLK_SLEEP_DISABLE    /* 休眠模式下禁用AES时钟 */
#define __AES_CLK_SLEEP_ENABLE     __HAL_RCC_AES_CLK_SLEEP_ENABLE     /* 休眠模式下使能AES时钟 */
#define __AES_FORCE_RESET          __HAL_RCC_AES_FORCE_RESET          /* 强制复位AES */
#define __AES_RELEASE_RESET        __HAL_RCC_AES_RELEASE_RESET        /* 释放AES复位 */

/* CRYP（加密）时钟控制宏定义 */
#define __CRYP_CLK_SLEEP_ENABLE    __HAL_RCC_CRYP_CLK_SLEEP_ENABLE    /* 休眠模式下使能CRYP时钟 */
#define __CRYP_CLK_SLEEP_DISABLE   __HAL_RCC_CRYP_CLK_SLEEP_DISABLE   /* 休眠模式下禁用CRYP时钟 */
#define __CRYP_CLK_ENABLE          __HAL_RCC_CRYP_CLK_ENABLE          /* 使能CRYP时钟 */
#define __CRYP_CLK_DISABLE         __HAL_RCC_CRYP_CLK_DISABLE         /* 禁用CRYP时钟 */
#define __CRYP_FORCE_RESET         __HAL_RCC_CRYP_FORCE_RESET         /* 强制复位CRYP */
#define __CRYP_RELEASE_RESET       __HAL_RCC_CRYP_RELEASE_RESET       /* 释放CRYP复位 */

/* AFIO（复用功能I/O）时钟控制宏定义 */
#define __AFIO_CLK_DISABLE         __HAL_RCC_AFIO_CLK_DISABLE         /* 禁用AFIO时钟 */
#define __AFIO_CLK_ENABLE          __HAL_RCC_AFIO_CLK_ENABLE          /* 使能AFIO时钟 */
#define __AFIO_FORCE_RESET         __HAL_RCC_AFIO_FORCE_RESET         /* 强制复位AFIO */
#define __AFIO_RELEASE_RESET       __HAL_RCC_AFIO_RELEASE_RESET       /* 释放AFIO复位 */

/* AHB总线复位控制宏定义 */
#define __AHB_FORCE_RESET          __HAL_RCC_AHB_FORCE_RESET          /* 强制复位AHB总线 */
#define __AHB_RELEASE_RESET        __HAL_RCC_AHB_RELEASE_RESET        /* 释放AHB总线复位 */
#define __AHB1_FORCE_RESET         __HAL_RCC_AHB1_FORCE_RESET         /* 强制复位AHB1总线 */
#define __AHB1_RELEASE_RESET       __HAL_RCC_AHB1_RELEASE_RESET       /* 释放AHB1总线复位 */
#define __AHB2_FORCE_RESET         __HAL_RCC_AHB2_FORCE_RESET         /* 强制复位AHB2总线 */
#define __AHB2_RELEASE_RESET       __HAL_RCC_AHB2_RELEASE_RESET       /* 释放AHB2总线复位 */
#define __AHB3_FORCE_RESET         __HAL_RCC_AHB3_FORCE_RESET         /* 强制复位AHB3总线 */
#define __AHB3_RELEASE_RESET       __HAL_RCC_AHB3_RELEASE_RESET       /* 释放AHB3总线复位 */

/* APB总线复位控制宏定义 */
#define __APB1_FORCE_RESET         __HAL_RCC_APB1_FORCE_RESET         /* 强制复位APB1总线 */
#define __APB1_RELEASE_RESET       __HAL_RCC_APB1_RELEASE_RESET       /* 释放APB1总线复位 */
#define __APB2_FORCE_RESET         __HAL_RCC_APB2_FORCE_RESET         /* 强制复位APB2总线 */
#define __APB2_RELEASE_RESET       __HAL_RCC_APB2_RELEASE_RESET       /* 释放APB2总线复位 */

/* 针对STM32C0系列的特殊定义 */
#if defined(STM32C0)
#define __HAL_RCC_APB1_FORCE_RESET    __HAL_RCC_APB1_GRP1_FORCE_RESET    /* 强制复位APB1组1（STM32C0专用） */
#define __HAL_RCC_APB1_RELEASE_RESET  __HAL_RCC_APB1_GRP1_RELEASE_RESET  /* 释放APB1组1复位（STM32C0专用） */
#define __HAL_RCC_APB2_FORCE_RESET    __HAL_RCC_APB1_GRP2_FORCE_RESET    /* 强制复位APB1组2（STM32C0专用） */
#define __HAL_RCC_APB2_RELEASE_RESET  __HAL_RCC_APB1_GRP2_RELEASE_RESET  /* 释放APB1组2复位（STM32C0专用） */
#endif /* STM32C0 */

/* BKP（备份寄存器）时钟控制宏定义 */
#define __BKP_CLK_DISABLE          __HAL_RCC_BKP_CLK_DISABLE          /* 禁用BKP时钟 */
#define __BKP_CLK_ENABLE           __HAL_RCC_BKP_CLK_ENABLE           /* 使能BKP时钟 */
#define __BKP_FORCE_RESET          __HAL_RCC_BKP_FORCE_RESET          /* 强制复位BKP */
#define __BKP_RELEASE_RESET        __HAL_RCC_BKP_RELEASE_RESET        /* 释放BKP复位 */

/* CAN1（控制器局域网1）时钟控制宏定义 */
#define __CAN1_CLK_DISABLE         __HAL_RCC_CAN1_CLK_DISABLE         /* 禁用CAN1时钟 */
#define __CAN1_CLK_ENABLE          __HAL_RCC_CAN1_CLK_ENABLE          /* 使能CAN1时钟 */
#define __CAN1_CLK_SLEEP_DISABLE   __HAL_RCC_CAN1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用CAN1时钟 */
#define __CAN1_CLK_SLEEP_ENABLE    __HAL_RCC_CAN1_CLK_SLEEP_ENABLE    /* 休眠模式下使能CAN1时钟 */
#define __CAN1_FORCE_RESET         __HAL_RCC_CAN1_FORCE_RESET         /* 强制复位CAN1 */
#define __CAN1_RELEASE_RESET       __HAL_RCC_CAN1_RELEASE_RESET       /* 释放CAN1复位 */

/* CAN（控制器局域网）通用时钟控制宏定义 */
#define __CAN_CLK_DISABLE          __HAL_RCC_CAN1_CLK_DISABLE         /* 禁用CAN时钟（通常指向CAN1） */
#define __CAN_CLK_ENABLE           __HAL_RCC_CAN1_CLK_ENABLE          /* 使能CAN时钟（通常指向CAN1） */
#define __CAN_FORCE_RESET          __HAL_RCC_CAN1_FORCE_RESET         /* 强制复位CAN（通常指向CAN1） */
#define __CAN_RELEASE_RESET        __HAL_RCC_CAN1_RELEASE_RESET       /* 释放CAN复位（通常指向CAN1） */

/* CAN2（控制器局域网2）时钟控制宏定义 */
#define __CAN2_CLK_DISABLE         __HAL_RCC_CAN2_CLK_DISABLE         /* 禁用CAN2时钟 */
#define __CAN2_CLK_ENABLE          __HAL_RCC_CAN2_CLK_ENABLE          /* 使能CAN2时钟 */
#define __CAN2_FORCE_RESET         __HAL_RCC_CAN2_FORCE_RESET         /* 强制复位CAN2 */
#define __CAN2_RELEASE_RESET       __HAL_RCC_CAN2_RELEASE_RESET       /* 释放CAN2复位 */

/* CEC（消费电子控制）时钟控制宏定义 */
#define __CEC_CLK_DISABLE          __HAL_RCC_CEC_CLK_DISABLE          /* 禁用CEC时钟 */
#define __CEC_CLK_ENABLE           __HAL_RCC_CEC_CLK_ENABLE           /* 使能CEC时钟 */
#define __CEC_FORCE_RESET          __HAL_RCC_CEC_FORCE_RESET          /* 强制复位CEC */
#define __CEC_RELEASE_RESET        __HAL_RCC_CEC_RELEASE_RESET        /* 释放CEC复位 */

/* COMP（比较器）时钟控制宏定义 */
#define __COMP_CLK_DISABLE         __HAL_RCC_COMP_CLK_DISABLE         /* 禁用COMP时钟 */
#define __COMP_CLK_ENABLE          __HAL_RCC_COMP_CLK_ENABLE          /* 使能COMP时钟 */
#define __COMP_FORCE_RESET         __HAL_RCC_COMP_FORCE_RESET         /* 强制复位COMP */
#define __COMP_RELEASE_RESET       __HAL_RCC_COMP_RELEASE_RESET       /* 释放COMP复位 */
#define __COMP_CLK_SLEEP_ENABLE    __HAL_RCC_COMP_CLK_SLEEP_ENABLE    /* 休眠模式下使能COMP时钟 */
#define __COMP_CLK_SLEEP_DISABLE   __HAL_RCC_COMP_CLK_SLEEP_DISABLE   /* 休眠模式下禁用COMP时钟 */

/* CRC（循环冗余校验）时钟控制宏定义 */
#define __CRC_CLK_DISABLE          __HAL_RCC_CRC_CLK_DISABLE          /* 禁用CRC时钟 */
#define __CRC_CLK_ENABLE           __HAL_RCC_CRC_CLK_ENABLE           /* 使能CRC时钟 */
#define __CRC_CLK_SLEEP_DISABLE    __HAL_RCC_CRC_CLK_SLEEP_DISABLE    /* 休眠模式下禁用CRC时钟 */
#define __CRC_CLK_SLEEP_ENABLE     __HAL_RCC_CRC_CLK_SLEEP_ENABLE     /* 休眠模式下使能CRC时钟 */
#define __CRC_FORCE_RESET          __HAL_RCC_CRC_FORCE_RESET          /* 强制复位CRC */
#define __CRC_RELEASE_RESET        __HAL_RCC_CRC_RELEASE_RESET        /* 释放CRC复位 */

/* DAC（数模转换器）时钟控制宏定义 */
#define __DAC_CLK_DISABLE          __HAL_RCC_DAC_CLK_DISABLE          /* 禁用DAC时钟 */
#define __DAC_CLK_ENABLE           __HAL_RCC_DAC_CLK_ENABLE           /* 使能DAC时钟 */
#define __DAC_FORCE_RESET          __HAL_RCC_DAC_FORCE_RESET          /* 强制复位DAC */
#define __DAC_RELEASE_RESET        __HAL_RCC_DAC_RELEASE_RESET        /* 释放DAC复位 */

/* DAC1（数模转换器1）时钟控制宏定义 */
#define __DAC1_CLK_DISABLE         __HAL_RCC_DAC1_CLK_DISABLE         /* 禁用DAC1时钟 */
#define __DAC1_CLK_ENABLE          __HAL_RCC_DAC1_CLK_ENABLE          /* 使能DAC1时钟 */
#define __DAC1_CLK_SLEEP_DISABLE   __HAL_RCC_DAC1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用DAC1时钟 */
#define __DAC1_CLK_SLEEP_ENABLE    __HAL_RCC_DAC1_CLK_SLEEP_ENABLE    /* 休眠模式下使能DAC1时钟 */
#define __DAC1_FORCE_RESET         __HAL_RCC_DAC1_FORCE_RESET         /* 强制复位DAC1 */
#define __DAC1_RELEASE_RESET       __HAL_RCC_DAC1_RELEASE_RESET       /* 释放DAC1复位 */

/* DBGMCU（调试MCU）时钟控制宏定义 */
#define __DBGMCU_CLK_ENABLE        __HAL_RCC_DBGMCU_CLK_ENABLE        /* 使能DBGMCU时钟 */
#define __DBGMCU_CLK_DISABLE       __HAL_RCC_DBGMCU_CLK_DISABLE       /* 禁用DBGMCU时钟 */
#define __DBGMCU_FORCE_RESET       __HAL_RCC_DBGMCU_FORCE_RESET       /* 强制复位DBGMCU */
#define __DBGMCU_RELEASE_RESET     __HAL_RCC_DBGMCU_RELEASE_RESET     /* 释放DBGMCU复位 */

/* DFSDM（数字滤波器用于sigma-delta调制器）时钟控制宏定义 */
#define __DFSDM_CLK_DISABLE        __HAL_RCC_DFSDM_CLK_DISABLE        /* 禁用DFSDM时钟 */
#define __DFSDM_CLK_ENABLE         __HAL_RCC_DFSDM_CLK_ENABLE         /* 使能DFSDM时钟 */
#define __DFSDM_CLK_SLEEP_DISABLE  __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE  /* 休眠模式下禁用DFSDM时钟 */
#define __DFSDM_CLK_SLEEP_ENABLE   __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE   /* 休眠模式下使能DFSDM时钟 */
#define __DFSDM_FORCE_RESET        __HAL_RCC_DFSDM_FORCE_RESET        /* 强制复位DFSDM */
#define __DFSDM_RELEASE_RESET      __HAL_RCC_DFSDM_RELEASE_RESET      /* 释放DFSDM复位 */

/* DMA1（直接存储器访问1）时钟控制宏定义 */
#define __DMA1_CLK_DISABLE         __HAL_RCC_DMA1_CLK_DISABLE         /* 禁用DMA1时钟 */
#define __DMA1_CLK_ENABLE          __HAL_RCC_DMA1_CLK_ENABLE          /* 使能DMA1时钟 */
#define __DMA1_CLK_SLEEP_DISABLE   __HAL_RCC_DMA1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用DMA1时钟 */
#define __DMA1_CLK_SLEEP_ENABLE    __HAL_RCC_DMA1_CLK_SLEEP_ENABLE    /* 休眠模式下使能DMA1时钟 */
#define __DMA1_FORCE_RESET         __HAL_RCC_DMA1_FORCE_RESET         /* 强制复位DMA1 */
#define __DMA1_RELEASE_RESET       __HAL_RCC_DMA1_RELEASE_RESET       /* 释放DMA1复位 */

/* DMA2（直接存储器访问2）时钟控制宏定义 */
#define __DMA2_CLK_DISABLE         __HAL_RCC_DMA2_CLK_DISABLE         /* 禁用DMA2时钟 */
#define __DMA2_CLK_ENABLE          __HAL_RCC_DMA2_CLK_ENABLE          /* 使能DMA2时钟 */
#define __DMA2_CLK_SLEEP_DISABLE   __HAL_RCC_DMA2_CLK_SLEEP_DISABLE   /* 休眠模式下禁用DMA2时钟 */
#define __DMA2_CLK_SLEEP_ENABLE    __HAL_RCC_DMA2_CLK_SLEEP_ENABLE    /* 休眠模式下使能DMA2时钟 */
#define __DMA2_FORCE_RESET         __HAL_RCC_DMA2_FORCE_RESET         /* 强制复位DMA2 */
#define __DMA2_RELEASE_RESET       __HAL_RCC_DMA2_RELEASE_RESET       /* 释放DMA2复位 */

/* ETHMAC（以太网MAC）时钟控制宏定义 */
#define __ETHMAC_CLK_DISABLE       __HAL_RCC_ETHMAC_CLK_DISABLE       /* 禁用ETHMAC时钟 */
#define __ETHMAC_CLK_ENABLE        __HAL_RCC_ETHMAC_CLK_ENABLE        /* 使能ETHMAC时钟 */
#define __ETHMAC_FORCE_RESET       __HAL_RCC_ETHMAC_FORCE_RESET       /* 强制复位ETHMAC */
#define __ETHMAC_RELEASE_RESET     __HAL_RCC_ETHMAC_RELEASE_RESET     /* 释放ETHMAC复位 */
#define __ETHMACRX_CLK_DISABLE     __HAL_RCC_ETHMACRX_CLK_DISABLE     /* 禁用ETHMAC接收时钟 */
#define __ETHMACRX_CLK_ENABLE      __HAL_RCC_ETHMACRX_CLK_ENABLE      /* 使能ETHMAC接收时钟 */
#define __ETHMACTX_CLK_DISABLE     __HAL_RCC_ETHMACTX_CLK_DISABLE     /* 禁用ETHMAC发送时钟 */
#define __ETHMACTX_CLK_ENABLE      __HAL_RCC_ETHMACTX_CLK_ENABLE      /* 使能ETHMAC发送时钟 */

/* FIREWALL（防火墙）时钟控制宏定义 */
#define __FIREWALL_CLK_DISABLE     __HAL_RCC_FIREWALL_CLK_DISABLE     /* 禁用防火墙时钟 */
#define __FIREWALL_CLK_ENABLE      __HAL_RCC_FIREWALL_CLK_ENABLE      /* 使能防火墙时钟 */

/* FLASH（闪存）时钟控制宏定义 */
#define __FLASH_CLK_DISABLE        __HAL_RCC_FLASH_CLK_DISABLE        /* 禁用FLASH时钟 */
#define __FLASH_CLK_ENABLE         __HAL_RCC_FLASH_CLK_ENABLE         /* 使能FLASH时钟 */
#define __FLASH_CLK_SLEEP_DISABLE  __HAL_RCC_FLASH_CLK_SLEEP_DISABLE  /* 休眠模式下禁用FLASH时钟 */
#define __FLASH_CLK_SLEEP_ENABLE   __HAL_RCC_FLASH_CLK_SLEEP_ENABLE   /* 休眠模式下使能FLASH时钟 */
#define __FLASH_FORCE_RESET        __HAL_RCC_FLASH_FORCE_RESET        /* 强制复位FLASH */
#define __FLASH_RELEASE_RESET      __HAL_RCC_FLASH_RELEASE_RESET      /* 释放FLASH复位 */

/* FLITF（闪存接口）时钟控制宏定义 */
#define __FLITF_CLK_DISABLE        __HAL_RCC_FLITF_CLK_DISABLE        /* 禁用FLITF时钟 */
#define __FLITF_CLK_ENABLE         __HAL_RCC_FLITF_CLK_ENABLE         /* 使能FLITF时钟 */
#define __FLITF_FORCE_RESET        __HAL_RCC_FLITF_FORCE_RESET        /* 强制复位FLITF */
#define __FLITF_RELEASE_RESET      __HAL_RCC_FLITF_RELEASE_RESET      /* 释放FLITF复位 */
#define __FLITF_CLK_SLEEP_ENABLE   __HAL_RCC_FLITF_CLK_SLEEP_ENABLE   /* 休眠模式下使能FLITF时钟 */
#define __FLITF_CLK_SLEEP_DISABLE  __HAL_RCC_FLITF_CLK_SLEEP_DISABLE  /* 休眠模式下禁用FLITF时钟 */

/* FMC（灵活存储器控制器）时钟控制宏定义 */
#define __FMC_CLK_DISABLE          __HAL_RCC_FMC_CLK_DISABLE          /* 禁用FMC时钟 */
#define __FMC_CLK_ENABLE           __HAL_RCC_FMC_CLK_ENABLE           /* 使能FMC时钟 */
#define __FMC_CLK_SLEEP_DISABLE    __HAL_RCC_FMC_CLK_SLEEP_DISABLE    /* 休眠模式下禁用FMC时钟 */
#define __FMC_CLK_SLEEP_ENABLE     __HAL_RCC_FMC_CLK_SLEEP_ENABLE     /* 休眠模式下使能FMC时钟 */
#define __FMC_FORCE_RESET          __HAL_RCC_FMC_FORCE_RESET          /* 强制复位FMC */
#define __FMC_RELEASE_RESET        __HAL_RCC_FMC_RELEASE_RESET        /* 释放FMC复位 */

/* FSMC（灵活静态存储器控制器）时钟控制宏定义 */
#define __FSMC_CLK_DISABLE         __HAL_RCC_FSMC_CLK_DISABLE         /* 禁用FSMC时钟 */
#define __FSMC_CLK_ENABLE          __HAL_RCC_FSMC_CLK_ENABLE          /* 使能FSMC时钟 */

/* GPIOA时钟控制宏定义 */
#define __GPIOA_CLK_DISABLE        __HAL_RCC_GPIOA_CLK_DISABLE        /* 禁用GPIOA时钟 */
#define __GPIOA_CLK_ENABLE         __HAL_RCC_GPIOA_CLK_ENABLE         /* 使能GPIOA时钟 */
#define __GPIOA_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOA时钟 */
#define __GPIOA_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOA时钟 */
#define __GPIOA_FORCE_RESET        __HAL_RCC_GPIOA_FORCE_RESET        /* 强制复位GPIOA */
#define __GPIOA_RELEASE_RESET      __HAL_RCC_GPIOA_RELEASE_RESET      /* 释放GPIOA复位 */

/* GPIOB时钟控制宏定义 */
#define __GPIOB_CLK_DISABLE        __HAL_RCC_GPIOB_CLK_DISABLE        /* 禁用GPIOB时钟 */
#define __GPIOB_CLK_ENABLE         __HAL_RCC_GPIOB_CLK_ENABLE         /* 使能GPIOB时钟 */
#define __GPIOB_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOB时钟 */
#define __GPIOB_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOB时钟 */
#define __GPIOB_FORCE_RESET        __HAL_RCC_GPIOB_FORCE_RESET        /* 强制复位GPIOB */
#define __GPIOB_RELEASE_RESET      __HAL_RCC_GPIOB_RELEASE_RESET      /* 释放GPIOB复位 */

/* GPIOC时钟控制宏定义 */
#define __GPIOC_CLK_DISABLE        __HAL_RCC_GPIOC_CLK_DISABLE        /* 禁用GPIOC时钟 */
#define __GPIOC_CLK_ENABLE         __HAL_RCC_GPIOC_CLK_ENABLE         /* 使能GPIOC时钟 */
#define __GPIOC_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOC时钟 */
#define __GPIOC_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOC时钟 */
#define __GPIOC_FORCE_RESET        __HAL_RCC_GPIOC_FORCE_RESET        /* 强制复位GPIOC */
#define __GPIOC_RELEASE_RESET      __HAL_RCC_GPIOC_RELEASE_RESET      /* 释放GPIOC复位 */

/* GPIOD时钟控制宏定义 */
#define __GPIOD_CLK_DISABLE        __HAL_RCC_GPIOD_CLK_DISABLE        /* 禁用GPIOD时钟 */
#define __GPIOD_CLK_ENABLE         __HAL_RCC_GPIOD_CLK_ENABLE         /* 使能GPIOD时钟 */
#define __GPIOD_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOD时钟 */
#define __GPIOD_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOD时钟 */
#define __GPIOD_FORCE_RESET        __HAL_RCC_GPIOD_FORCE_RESET        /* 强制复位GPIOD */
#define __GPIOD_RELEASE_RESET      __HAL_RCC_GPIOD_RELEASE_RESET      /* 释放GPIOD复位 */

/* GPIOE时钟控制宏定义 */
#define __GPIOE_CLK_DISABLE        __HAL_RCC_GPIOE_CLK_DISABLE        /* 禁用GPIOE时钟 */
#define __GPIOE_CLK_ENABLE         __HAL_RCC_GPIOE_CLK_ENABLE         /* 使能GPIOE时钟 */
#define __GPIOE_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOE时钟 */
#define __GPIOE_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOE时钟 */
#define __GPIOE_FORCE_RESET        __HAL_RCC_GPIOE_FORCE_RESET        /* 强制复位GPIOE */
#define __GPIOE_RELEASE_RESET      __HAL_RCC_GPIOE_RELEASE_RESET      /* 释放GPIOE复位 */

/* GPIOF时钟控制宏定义 */
#define __GPIOF_CLK_DISABLE        __HAL_RCC_GPIOF_CLK_DISABLE        /* 禁用GPIOF时钟 */
#define __GPIOF_CLK_ENABLE         __HAL_RCC_GPIOF_CLK_ENABLE         /* 使能GPIOF时钟 */
#define __GPIOF_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOF时钟 */
#define __GPIOF_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOF时钟 */
#define __GPIOF_FORCE_RESET        __HAL_RCC_GPIOF_FORCE_RESET        /* 强制复位GPIOF */
#define __GPIOF_RELEASE_RESET      __HAL_RCC_GPIOF_RELEASE_RESET      /* 释放GPIOF复位 */

/* GPIOG时钟控制宏定义 */
#define __GPIOG_CLK_DISABLE        __HAL_RCC_GPIOG_CLK_DISABLE        /* 禁用GPIOG时钟 */
#define __GPIOG_CLK_ENABLE         __HAL_RCC_GPIOG_CLK_ENABLE         /* 使能GPIOG时钟 */
#define __GPIOG_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOG时钟 */
#define __GPIOG_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOG时钟 */
#define __GPIOG_FORCE_RESET        __HAL_RCC_GPIOG_FORCE_RESET        /* 强制复位GPIOG */
#define __GPIOG_RELEASE_RESET      __HAL_RCC_GPIOG_RELEASE_RESET      /* 释放GPIOG复位 */

/* GPIOH时钟控制宏定义 */
#define __GPIOH_CLK_DISABLE        __HAL_RCC_GPIOH_CLK_DISABLE        /* 禁用GPIOH时钟 */
#define __GPIOH_CLK_ENABLE         __HAL_RCC_GPIOH_CLK_ENABLE         /* 使能GPIOH时钟 */
#define __GPIOH_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOH时钟 */
#define __GPIOH_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOH时钟 */
#define __GPIOH_FORCE_RESET        __HAL_RCC_GPIOH_FORCE_RESET        /* 强制复位GPIOH */
#define __GPIOH_RELEASE_RESET      __HAL_RCC_GPIOH_RELEASE_RESET      /* 释放GPIOH复位 */

/* I2C1时钟控制宏定义 */
#define __I2C1_CLK_DISABLE         __HAL_RCC_I2C1_CLK_DISABLE         /* 禁用I2C1时钟 */
#define __I2C1_CLK_ENABLE          __HAL_RCC_I2C1_CLK_ENABLE          /* 使能I2C1时钟 */
#define __I2C1_CLK_SLEEP_DISABLE   __HAL_RCC_I2C1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用I2C1时钟 */
#define __I2C1_CLK_SLEEP_ENABLE    __HAL_RCC_I2C1_CLK_SLEEP_ENABLE    /* 休眠模式下使能I2C1时钟 */
#define __I2C1_FORCE_RESET         __HAL_RCC_I2C1_FORCE_RESET         /* 强制复位I2C1 */
#define __I2C1_RELEASE_RESET       __HAL_RCC_I2C1_RELEASE_RESET       /* 释放I2C1复位 */

/* I2C2时钟控制宏定义 */
#define __I2C2_CLK_DISABLE         __HAL_RCC_I2C2_CLK_DISABLE         /* 禁用I2C2时钟 */
#define __I2C2_CLK_ENABLE          __HAL_RCC_I2C2_CLK_ENABLE          /* 使能I2C2时钟 */
#define __I2C2_CLK_SLEEP_DISABLE   __HAL_RCC_I2C2_CLK_SLEEP_DISABLE   /* 休眠模式下禁用I2C2时钟 */
#define __I2C2_CLK_SLEEP_ENABLE    __HAL_RCC_I2C2_CLK_SLEEP_ENABLE    /* 休眠模式下使能I2C2时钟 */
#define __I2C2_FORCE_RESET         __HAL_RCC_I2C2_FORCE_RESET         /* 强制复位I2C2 */
#define __I2C2_RELEASE_RESET       __HAL_RCC_I2C2_RELEASE_RESET       /* 释放I2C2复位 */

/* I2C3时钟控制宏定义 */
#define __I2C3_CLK_DISABLE         __HAL_RCC_I2C3_CLK_DISABLE         /* 禁用I2C3时钟 */
#define __I2C3_CLK_ENABLE          __HAL_RCC_I2C3_CLK_ENABLE          /* 使能I2C3时钟 */
#define __I2C3_CLK_SLEEP_DISABLE   __HAL_RCC_I2C3_CLK_SLEEP_DISABLE   /* 休眠模式下禁用I2C3时钟 */
#define __I2C3_CLK_SLEEP_ENABLE    __HAL_RCC_I2C3_CLK_SLEEP_ENABLE    /* 休眠模式下使能I2C3时钟 */
#define __I2C3_FORCE_RESET         __HAL_RCC_I2C3_FORCE_RESET         /* 强制复位I2C3 */
#define __I2C3_RELEASE_RESET       __HAL_RCC_I2C3_RELEASE_RESET       /* 释放I2C3复位 */

/* LCD时钟控制宏定义 */
#define __LCD_CLK_DISABLE          __HAL_RCC_LCD_CLK_DISABLE          /* 禁用LCD时钟 */
#define __LCD_CLK_ENABLE           __HAL_RCC_LCD_CLK_ENABLE           /* 使能LCD时钟 */
#define __LCD_CLK_SLEEP_DISABLE    __HAL_RCC_LCD_CLK_SLEEP_DISABLE    /* 休眠模式下禁用LCD时钟 */
#define __LCD_CLK_SLEEP_ENABLE     __HAL_RCC_LCD_CLK_SLEEP_ENABLE     /* 休眠模式下使能LCD时钟 */
#define __LCD_FORCE_RESET          __HAL_RCC_LCD_FORCE_RESET          /* 强制复位LCD */
#define __LCD_RELEASE_RESET        __HAL_RCC_LCD_RELEASE_RESET        /* 释放LCD复位 */

/* LPTIM1（低功耗定时器1）时钟控制宏定义 */
#define __LPTIM1_CLK_DISABLE       __HAL_RCC_LPTIM1_CLK_DISABLE       /* 禁用LPTIM1时钟 */
#define __LPTIM1_CLK_ENABLE        __HAL_RCC_LPTIM1_CLK_ENABLE        /* 使能LPTIM1时钟 */
#define __LPTIM1_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE /* 休眠模式下禁用LPTIM1时钟 */
#define __LPTIM1_CLK_SLEEP_ENABLE  __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE  /* 休眠模式下使能LPTIM1时钟 */
#define __LPTIM1_FORCE_RESET       __HAL_RCC_LPTIM1_FORCE_RESET       /* 强制复位LPTIM1 */
#define __LPTIM1_RELEASE_RESET     __HAL_RCC_LPTIM1_RELEASE_RESET     /* 释放LPTIM1复位 */

/* LPTIM2（低功耗定时器2）时钟控制宏定义 */
#define __LPTIM2_CLK_DISABLE       __HAL_RCC_LPTIM2_CLK_DISABLE       /* 禁用LPTIM2时钟 */
#define __LPTIM2_CLK_ENABLE        __HAL_RCC_LPTIM2_CLK_ENABLE        /* 使能LPTIM2时钟 */
#define __LPTIM2_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE /* 休眠模式下禁用LPTIM2时钟 */
#define __LPTIM2_CLK_SLEEP_ENABLE  __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE  /* 休眠模式下使能LPTIM2时钟 */
#define __LPTIM2_FORCE_RESET       __HAL_RCC_LPTIM2_FORCE_RESET       /* 强制复位LPTIM2 */
#define __LPTIM2_RELEASE_RESET     __HAL_RCC_LPTIM2_RELEASE_RESET     /* 释放LPTIM2复位 */

/* LPUART1（低功耗通用异步收发器1）时钟控制宏定义 */
#define __LPUART1_CLK_DISABLE      __HAL_RCC_LPUART1_CLK_DISABLE      /* 禁用LPUART1时钟 */
#define __LPUART1_CLK_ENABLE       __HAL_RCC_LPUART1_CLK_ENABLE       /* 使能LPUART1时钟 */
#define __LPUART1_CLK_SLEEP_DISABLE __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE /* 休眠模式下禁用LPUART1时钟 */
#define __LPUART1_CLK_SLEEP_ENABLE __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE /* 休眠模式下使能LPUART1时钟 */
#define __LPUART1_FORCE_RESET      __HAL_RCC_LPUART1_FORCE_RESET      /* 强制复位LPUART1 */
#define __LPUART1_RELEASE_RESET    __HAL_RCC_LPUART1_RELEASE_RESET    /* 释放LPUART1复位 */

/* OPAMP（运算放大器）时钟控制宏定义 */
#define __OPAMP_CLK_DISABLE        __HAL_RCC_OPAMP_CLK_DISABLE        /* 禁用OPAMP时钟 */
#define __OPAMP_CLK_ENABLE         __HAL_RCC_OPAMP_CLK_ENABLE         /* 使能OPAMP时钟 */
#define __OPAMP_CLK_SLEEP_DISABLE  __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE  /* 休眠模式下禁用OPAMP时钟 */
#define __OPAMP_CLK_SLEEP_ENABLE   __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE   /* 休眠模式下使能OPAMP时钟 */
#define __OPAMP_FORCE_RESET        __HAL_RCC_OPAMP_FORCE_RESET        /* 强制复位OPAMP */
#define __OPAMP_RELEASE_RESET      __HAL_RCC_OPAMP_RELEASE_RESET      /* 释放OPAMP复位 */

/* OTGFS（USB OTG全速）时钟控制宏定义 */
#define __OTGFS_CLK_DISABLE        __HAL_RCC_OTGFS_CLK_DISABLE        /* 禁用OTGFS时钟 */
#define __OTGFS_CLK_ENABLE         __HAL_RCC_OTGFS_CLK_ENABLE         /* 使能OTGFS时钟 */
#define __OTGFS_CLK_SLEEP_DISABLE  __HAL_RCC_OTGFS_CLK_SLEEP_DISABLE  /* 休眠模式下禁用OTGFS时钟 */
#define __OTGFS_CLK_SLEEP_ENABLE   __HAL_RCC_OTGFS_CLK_SLEEP_ENABLE   /* 休眠模式下使能OTGFS时钟 */
#define __OTGFS_FORCE_RESET        __HAL_RCC_OTGFS_FORCE_RESET        /* 强制复位OTGFS */
#define __OTGFS_RELEASE_RESET      __HAL_RCC_OTGFS_RELEASE_RESET      /* 释放OTGFS复位 */

/* PWR（电源）时钟控制宏定义 */
#define __PWR_CLK_DISABLE          __HAL_RCC_PWR_CLK_DISABLE          /* 禁用PWR时钟 */
#define __PWR_CLK_ENABLE           __HAL_RCC_PWR_CLK_ENABLE           /* 使能PWR时钟 */
#define __PWR_CLK_SLEEP_DISABLE    __HAL_RCC_PWR_CLK_SLEEP_DISABLE    /* 休眠模式下禁用PWR时钟 */
#define __PWR_CLK_SLEEP_ENABLE     __HAL_RCC_PWR_CLK_SLEEP_ENABLE     /* 休眠模式下使能PWR时钟 */
#define __PWR_FORCE_RESET          __HAL_RCC_PWR_FORCE_RESET          /* 强制复位PWR */
#define __PWR_RELEASE_RESET        __HAL_RCC_PWR_RELEASE_RESET        /* 释放PWR复位 */

/* QSPI（四线SPI）时钟控制宏定义 */
#define __QSPI_CLK_DISABLE         __HAL_RCC_QSPI_CLK_DISABLE         /* 禁用QSPI时钟 */
#define __QSPI_CLK_ENABLE          __HAL_RCC_QSPI_CLK_ENABLE          /* 使能QSPI时钟 */
#define __QSPI_CLK_SLEEP_DISABLE   __HAL_RCC_QSPI_CLK_SLEEP_DISABLE   /* 休眠模式下禁用QSPI时钟 */
#define __QSPI_CLK_SLEEP_ENABLE    __HAL_RCC_QSPI_CLK_SLEEP_ENABLE    /* 休眠模式下使能QSPI时钟 */
#define __QSPI_FORCE_RESET         __HAL_RCC_QSPI_FORCE_RESET         /* 强制复位QSPI */
#define __QSPI_RELEASE_RESET       __HAL_RCC_QSPI_RELEASE_RESET       /* 释放QSPI复位 */
#if defined(STM32WB)  // 如果定义了STM32WB系列芯片
#define __HAL_RCC_QSPI_CLK_DISABLE            __HAL_RCC_QUADSPI_CLK_DISABLE  // 禁用QSPI时钟
#define __HAL_RCC_QSPI_CLK_ENABLE             __HAL_RCC_QUADSPI_CLK_ENABLE   // 使能QSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_DISABLE      __HAL_RCC_QUADSPI_CLK_SLEEP_DISABLE  // 睡眠模式下禁用QSPI时钟
#define __HAL_RCC_QSPI_CLK_SLEEP_ENABLE       __HAL_RCC_QUADSPI_CLK_SLEEP_ENABLE   // 睡眠模式下使能QSPI时钟
#define __HAL_RCC_QSPI_FORCE_RESET            __HAL_RCC_QUADSPI_FORCE_RESET  // 强制复位QSPI
#define __HAL_RCC_QSPI_RELEASE_RESET          __HAL_RCC_QUADSPI_RELEASE_RESET  // 释放QSPI复位
#define __HAL_RCC_QSPI_IS_CLK_ENABLED         __HAL_RCC_QUADSPI_IS_CLK_ENABLED  // 检查QSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_DISABLED        __HAL_RCC_QUADSPI_IS_CLK_DISABLED  // 检查QSPI时钟是否禁用
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_ENABLED   __HAL_RCC_QUADSPI_IS_CLK_SLEEP_ENABLED  // 检查睡眠模式下QSPI时钟是否使能
#define __HAL_RCC_QSPI_IS_CLK_SLEEP_DISABLED  __HAL_RCC_QUADSPI_IS_CLK_SLEEP_DISABLED  // 检查睡眠模式下QSPI时钟是否禁用
#define QSPI_IRQHandler QUADSPI_IRQHandler  // 定义QSPI中断处理函数
#endif /* __HAL_RCC_QUADSPI_CLK_ENABLE */  // 结束条件编译块
#define __RNG_CLK_DISABLE __HAL_RCC_RNG_CLK_DISABLE             // 禁用随机数生成器(RNG)时钟
#define __RNG_CLK_ENABLE __HAL_RCC_RNG_CLK_ENABLE               // 使能随机数生成器(RNG)时钟
#define __RNG_CLK_SLEEP_DISABLE __HAL_RCC_RNG_CLK_SLEEP_DISABLE // 在睡眠模式下禁用RNG时钟
#define __RNG_CLK_SLEEP_ENABLE __HAL_RCC_RNG_CLK_SLEEP_ENABLE   // 在睡眠模式下使能RNG时钟
#define __RNG_FORCE_RESET __HAL_RCC_RNG_FORCE_RESET             // 强制复位RNG外设
#define __RNG_RELEASE_RESET __HAL_RCC_RNG_RELEASE_RESET         // 释放RNG外设的复位

#define __SAI1_CLK_DISABLE __HAL_RCC_SAI1_CLK_DISABLE           // 禁用串行音频接口1(SAI1)时钟
#define __SAI1_CLK_ENABLE __HAL_RCC_SAI1_CLK_ENABLE             // 使能串行音频接口1(SAI1)时钟
#define __SAI1_CLK_SLEEP_DISABLE __HAL_RCC_SAI1_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SAI1时钟
#define __SAI1_CLK_SLEEP_ENABLE __HAL_RCC_SAI1_CLK_SLEEP_ENABLE // 在睡眠模式下使能SAI1时钟
#define __SAI1_FORCE_RESET __HAL_RCC_SAI1_FORCE_RESET           // 强制复位SAI1外设
#define __SAI1_RELEASE_RESET __HAL_RCC_SAI1_RELEASE_RESET       // 释放SAI1外设的复位

#define __SAI2_CLK_DISABLE __HAL_RCC_SAI2_CLK_DISABLE           // 禁用串行音频接口2(SAI2)时钟
#define __SAI2_CLK_ENABLE __HAL_RCC_SAI2_CLK_ENABLE             // 使能串行音频接口2(SAI2)时钟
#define __SAI2_CLK_SLEEP_DISABLE __HAL_RCC_SAI2_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SAI2时钟
#define __SAI2_CLK_SLEEP_ENABLE __HAL_RCC_SAI2_CLK_SLEEP_ENABLE // 在睡眠模式下使能SAI2时钟
#define __SAI2_FORCE_RESET __HAL_RCC_SAI2_FORCE_RESET           // 强制复位SAI2外设
#define __SAI2_RELEASE_RESET __HAL_RCC_SAI2_RELEASE_RESET       // 释放SAI2外设的复位

#define __SDIO_CLK_DISABLE __HAL_RCC_SDIO_CLK_DISABLE           // 禁用安全数字输入输出(SDIO)时钟
#define __SDIO_CLK_ENABLE __HAL_RCC_SDIO_CLK_ENABLE             // 使能安全数字输入输出(SDIO)时钟

#define __SDMMC_CLK_DISABLE __HAL_RCC_SDMMC_CLK_DISABLE         // 禁用安全数字多媒体卡(SDMMC)时钟
#define __SDMMC_CLK_ENABLE __HAL_RCC_SDMMC_CLK_ENABLE           // 使能安全数字多媒体卡(SDMMC)时钟
#define __SDMMC_CLK_SLEEP_DISABLE __HAL_RCC_SDMMC_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SDMMC时钟
#define __SDMMC_CLK_SLEEP_ENABLE __HAL_RCC_SDMMC_CLK_SLEEP_ENABLE // 在睡眠模式下使能SDMMC时钟
#define __SDMMC_FORCE_RESET __HAL_RCC_SDMMC_FORCE_RESET         // 强制复位SDMMC外设
#define __SDMMC_RELEASE_RESET __HAL_RCC_SDMMC_RELEASE_RESET     // 释放SDMMC外设的复位

#define __SPI1_CLK_DISABLE __HAL_RCC_SPI1_CLK_DISABLE           // 禁用串行外设接口1(SPI1)时钟
#define __SPI1_CLK_ENABLE __HAL_RCC_SPI1_CLK_ENABLE             // 使能串行外设接口1(SPI1)时钟
#define __SPI1_CLK_SLEEP_DISABLE __HAL_RCC_SPI1_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SPI1时钟
#define __SPI1_CLK_SLEEP_ENABLE __HAL_RCC_SPI1_CLK_SLEEP_ENABLE // 在睡眠模式下使能SPI1时钟
#define __SPI1_FORCE_RESET __HAL_RCC_SPI1_FORCE_RESET           // 强制复位SPI1外设
#define __SPI1_RELEASE_RESET __HAL_RCC_SPI1_RELEASE_RESET       // 释放SPI1外设的复位

#define __SPI2_CLK_DISABLE __HAL_RCC_SPI2_CLK_DISABLE           // 禁用串行外设接口2(SPI2)时钟
#define __SPI2_CLK_ENABLE __HAL_RCC_SPI2_CLK_ENABLE             // 使能串行外设接口2(SPI2)时钟
#define __SPI2_CLK_SLEEP_DISABLE __HAL_RCC_SPI2_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SPI2时钟
#define __SPI2_CLK_SLEEP_ENABLE __HAL_RCC_SPI2_CLK_SLEEP_ENABLE // 在睡眠模式下使能SPI2时钟
#define __SPI2_FORCE_RESET __HAL_RCC_SPI2_FORCE_RESET           // 强制复位SPI2外设
#define __SPI2_RELEASE_RESET __HAL_RCC_SPI2_RELEASE_RESET       // 释放SPI2外设的复位

#define __SPI3_CLK_DISABLE __HAL_RCC_SPI3_CLK_DISABLE           // 禁用串行外设接口3(SPI3)时钟
#define __SPI3_CLK_ENABLE __HAL_RCC_SPI3_CLK_ENABLE             // 使能串行外设接口3(SPI3)时钟
#define __SPI3_CLK_SLEEP_DISABLE __HAL_RCC_SPI3_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SPI3时钟
#define __SPI3_CLK_SLEEP_ENABLE __HAL_RCC_SPI3_CLK_SLEEP_ENABLE // 在睡眠模式下使能SPI3时钟
#define __SPI3_FORCE_RESET __HAL_RCC_SPI3_FORCE_RESET           // 强制复位SPI3外设
#define __SPI3_RELEASE_RESET __HAL_RCC_SPI3_RELEASE_RESET       // 释放SPI3外设的复位

#define __SRAM_CLK_DISABLE __HAL_RCC_SRAM_CLK_DISABLE           // 禁用SRAM时钟
#define __SRAM_CLK_ENABLE __HAL_RCC_SRAM_CLK_ENABLE             // 使能SRAM时钟
#define __SRAM1_CLK_SLEEP_DISABLE __HAL_RCC_SRAM1_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SRAM1时钟
#define __SRAM1_CLK_SLEEP_ENABLE __HAL_RCC_SRAM1_CLK_SLEEP_ENABLE // 在睡眠模式下使能SRAM1时钟
#define __SRAM2_CLK_SLEEP_DISABLE __HAL_RCC_SRAM2_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SRAM2时钟
#define __SRAM2_CLK_SLEEP_ENABLE __HAL_RCC_SRAM2_CLK_SLEEP_ENABLE // 在睡眠模式下使能SRAM2时钟

#define __SWPMI1_CLK_DISABLE __HAL_RCC_SWPMI1_CLK_DISABLE       // 禁用单线协议管理器接口1(SWPMI1)时钟
#define __SWPMI1_CLK_ENABLE __HAL_RCC_SWPMI1_CLK_ENABLE         // 使能单线协议管理器接口1(SWPMI1)时钟
#define __SWPMI1_CLK_SLEEP_DISABLE __HAL_RCC_SWPMI1_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SWPMI1时钟
#define __SWPMI1_CLK_SLEEP_ENABLE __HAL_RCC_SWPMI1_CLK_SLEEP_ENABLE // 在睡眠模式下使能SWPMI1时钟
#define __SWPMI1_FORCE_RESET __HAL_RCC_SWPMI1_FORCE_RESET       // 强制复位SWPMI1外设
#define __SWPMI1_RELEASE_RESET __HAL_RCC_SWPMI1_RELEASE_RESET   // 释放SWPMI1外设的复位

#define __SYSCFG_CLK_DISABLE __HAL_RCC_SYSCFG_CLK_DISABLE       // 禁用系统配置(SYSCFG)时钟
#define __SYSCFG_CLK_ENABLE __HAL_RCC_SYSCFG_CLK_ENABLE         // 使能系统配置(SYSCFG)时钟
#define __SYSCFG_CLK_SLEEP_DISABLE __HAL_RCC_SYSCFG_CLK_SLEEP_DISABLE // 在睡眠模式下禁用SYSCFG时钟
#define __SYSCFG_CLK_SLEEP_ENABLE __HAL_RCC_SYSCFG_CLK_SLEEP_ENABLE // 在睡眠模式下使能SYSCFG时钟
#define __SYSCFG_FORCE_RESET __HAL_RCC_SYSCFG_FORCE_RESET       // 强制复位SYSCFG外设
#define __SYSCFG_RELEASE_RESET __HAL_RCC_SYSCFG_RELEASE_RESET   // 释放SYSCFG外设的复位

#define __TIM1_CLK_DISABLE __HAL_RCC_TIM1_CLK_DISABLE           // 禁用定时器1(TIM1)时钟
#define __TIM1_CLK_ENABLE __HAL_RCC_TIM1_CLK_ENABLE             // 使能定时器1(TIM1)时钟
#define __TIM1_CLK_SLEEP_DISABLE __HAL_RCC_TIM1_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM1时钟
#define __TIM1_CLK_SLEEP_ENABLE __HAL_RCC_TIM1_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM1时钟
#define __TIM1_FORCE_RESET __HAL_RCC_TIM1_FORCE_RESET           // 强制复位TIM1外设
#define __TIM1_RELEASE_RESET __HAL_RCC_TIM1_RELEASE_RESET       // 释放TIM1外设的复位

#define __TIM10_CLK_DISABLE __HAL_RCC_TIM10_CLK_DISABLE         // 禁用定时器10(TIM10)时钟
#define __TIM10_CLK_ENABLE __HAL_RCC_TIM10_CLK_ENABLE           // 使能定时器10(TIM10)时钟
#define __TIM10_FORCE_RESET __HAL_RCC_TIM10_FORCE_RESET         // 强制复位TIM10外设
#define __TIM10_RELEASE_RESET __HAL_RCC_TIM10_RELEASE_RESET     // 释放TIM10外设的复位

#define __TIM11_CLK_DISABLE __HAL_RCC_TIM11_CLK_DISABLE         // 禁用定时器11(TIM11)时钟
#define __TIM11_CLK_ENABLE __HAL_RCC_TIM11_CLK_ENABLE           // 使能定时器11(TIM11)时钟
#define __TIM11_FORCE_RESET __HAL_RCC_TIM11_FORCE_RESET         // 强制复位TIM11外设
#define __TIM11_RELEASE_RESET __HAL_RCC_TIM11_RELEASE_RESET     // 释放TIM11外设的复位

#define __TIM12_CLK_DISABLE __HAL_RCC_TIM12_CLK_DISABLE         // 禁用定时器12(TIM12)时钟
#define __TIM12_CLK_ENABLE __HAL_RCC_TIM12_CLK_ENABLE           // 使能定时器12(TIM12)时钟
#define __TIM12_FORCE_RESET __HAL_RCC_TIM12_FORCE_RESET         // 强制复位TIM12外设
#define __TIM12_RELEASE_RESET __HAL_RCC_TIM12_RELEASE_RESET     // 释放TIM12外设的复位

#define __TIM13_CLK_DISABLE __HAL_RCC_TIM13_CLK_DISABLE         // 禁用定时器13(TIM13)时钟
#define __TIM13_CLK_ENABLE __HAL_RCC_TIM13_CLK_ENABLE           // 使能定时器13(TIM13)时钟
#define __TIM13_FORCE_RESET __HAL_RCC_TIM13_FORCE_RESET         // 强制复位TIM13外设
#define __TIM13_RELEASE_RESET __HAL_RCC_TIM13_RELEASE_RESET     // 释放TIM13外设的复位

#define __TIM14_CLK_DISABLE __HAL_RCC_TIM14_CLK_DISABLE         // 禁用定时器14(TIM14)时钟
#define __TIM14_CLK_ENABLE __HAL_RCC_TIM14_CLK_ENABLE           // 使能定时器14(TIM14)时钟
#define __TIM14_FORCE_RESET __HAL_RCC_TIM14_FORCE_RESET         // 强制复位TIM14外设
#define __TIM14_RELEASE_RESET __HAL_RCC_TIM14_RELEASE_RESET     // 释放TIM14外设的复位

#define __TIM15_CLK_DISABLE __HAL_RCC_TIM15_CLK_DISABLE         // 禁用定时器15(TIM15)时钟
#define __TIM15_CLK_ENABLE __HAL_RCC_TIM15_CLK_ENABLE           // 使能定时器15(TIM15)时钟
#define __TIM15_CLK_SLEEP_DISABLE __HAL_RCC_TIM15_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM15时钟
#define __TIM15_CLK_SLEEP_ENABLE __HAL_RCC_TIM15_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM15时钟
#define __TIM15_FORCE_RESET __HAL_RCC_TIM15_FORCE_RESET         // 强制复位TIM15外设
#define __TIM15_RELEASE_RESET __HAL_RCC_TIM15_RELEASE_RESET     // 释放TIM15外设的复位

#define __TIM16_CLK_DISABLE __HAL_RCC_TIM16_CLK_DISABLE         // 禁用定时器16(TIM16)时钟
#define __TIM16_CLK_ENABLE __HAL_RCC_TIM16_CLK_ENABLE           // 使能定时器16(TIM16)时钟
#define __TIM16_CLK_SLEEP_DISABLE __HAL_RCC_TIM16_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM16时钟
#define __TIM16_CLK_SLEEP_ENABLE __HAL_RCC_TIM16_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM16时钟
#define __TIM16_FORCE_RESET __HAL_RCC_TIM16_FORCE_RESET         // 强制复位TIM16外设
#define __TIM16_RELEASE_RESET __HAL_RCC_TIM16_RELEASE_RESET     // 释放TIM16外设的复位

#define __TIM17_CLK_DISABLE __HAL_RCC_TIM17_CLK_DISABLE         // 禁用定时器17(TIM17)时钟
#define __TIM17_CLK_ENABLE __HAL_RCC_TIM17_CLK_ENABLE           // 使能定时器17(TIM17)时钟
#define __TIM17_CLK_SLEEP_DISABLE __HAL_RCC_TIM17_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM17时钟
#define __TIM17_CLK_SLEEP_ENABLE __HAL_RCC_TIM17_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM17时钟
#define __TIM17_FORCE_RESET __HAL_RCC_TIM17_FORCE_RESET         // 强制复位TIM17外设
#define __TIM17_RELEASE_RESET __HAL_RCC_TIM17_RELEASE_RESET     // 释放TIM17外设的复位

#define __TIM2_CLK_DISABLE __HAL_RCC_TIM2_CLK_DISABLE           // 禁用定时器2(TIM2)时钟
#define __TIM2_CLK_ENABLE __HAL_RCC_TIM2_CLK_ENABLE             // 使能定时器2(TIM2)时钟
#define __TIM2_CLK_SLEEP_DISABLE __HAL_RCC_TIM2_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM2时钟
#define __TIM2_CLK_SLEEP_ENABLE __HAL_RCC_TIM2_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM2时钟
#define __TIM2_FORCE_RESET __HAL_RCC_TIM2_FORCE_RESET           // 强制复位TIM2外设
#define __TIM2_RELEASE_RESET __HAL_RCC_TIM2_RELEASE_RESET       // 释放TIM2外设的复位

#define __TIM3_CLK_DISABLE __HAL_RCC_TIM3_CLK_DISABLE           // 禁用定时器3(TIM3)时钟
#define __TIM3_CLK_ENABLE __HAL_RCC_TIM3_CLK_ENABLE             // 使能定时器3(TIM3)时钟
#define __TIM3_CLK_SLEEP_DISABLE __HAL_RCC_TIM3_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM3时钟
#define __TIM3_CLK_SLEEP_ENABLE __HAL_RCC_TIM3_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM3时钟
#define __TIM3_FORCE_RESET __HAL_RCC_TIM3_FORCE_RESET           // 强制复位TIM3外设
#define __TIM3_RELEASE_RESET __HAL_RCC_TIM3_RELEASE_RESET       // 释放TIM3外设的复位

#define __TIM4_CLK_DISABLE __HAL_RCC_TIM4_CLK_DISABLE           // 禁用定时器4(TIM4)时钟
#define __TIM4_CLK_ENABLE __HAL_RCC_TIM4_CLK_ENABLE             // 使能定时器4(TIM4)时钟
#define __TIM4_CLK_SLEEP_DISABLE __HAL_RCC_TIM4_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM4时钟
#define __TIM4_CLK_SLEEP_ENABLE __HAL_RCC_TIM4_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM4时钟
#define __TIM4_FORCE_RESET __HAL_RCC_TIM4_FORCE_RESET           // 强制复位TIM4外设
#define __TIM4_RELEASE_RESET __HAL_RCC_TIM4_RELEASE_RESET       // 释放TIM4外设的复位

#define __TIM5_CLK_DISABLE __HAL_RCC_TIM5_CLK_DISABLE           // 禁用定时器5(TIM5)时钟
#define __TIM5_CLK_ENABLE __HAL_RCC_TIM5_CLK_ENABLE             // 使能定时器5(TIM5)时钟
#define __TIM5_CLK_SLEEP_DISABLE __HAL_RCC_TIM5_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM5时钟
#define __TIM5_CLK_SLEEP_ENABLE __HAL_RCC_TIM5_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM5时钟
#define __TIM5_FORCE_RESET __HAL_RCC_TIM5_FORCE_RESET           // 强制复位TIM5外设
#define __TIM5_RELEASE_RESET __HAL_RCC_TIM5_RELEASE_RESET       // 释放TIM5外设的复位

#define __TIM6_CLK_DISABLE __HAL_RCC_TIM6_CLK_DISABLE           // 禁用定时器6(TIM6)时钟
#define __TIM6_CLK_ENABLE __HAL_RCC_TIM6_CLK_ENABLE             // 使能定时器6(TIM6)时钟
#define __TIM6_CLK_SLEEP_DISABLE __HAL_RCC_TIM6_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM6时钟
#define __TIM6_CLK_SLEEP_ENABLE __HAL_RCC_TIM6_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM6时钟
#define __TIM6_FORCE_RESET __HAL_RCC_TIM6_FORCE_RESET           // 强制复位TIM6外设
#define __TIM6_RELEASE_RESET __HAL_RCC_TIM6_RELEASE_RESET       // 释放TIM6外设的复位

#define __TIM7_CLK_DISABLE __HAL_RCC_TIM7_CLK_DISABLE           // 禁用定时器7(TIM7)时钟
#define __TIM7_CLK_ENABLE __HAL_RCC_TIM7_CLK_ENABLE             // 使能定时器7(TIM7)时钟
#define __TIM7_CLK_SLEEP_DISABLE __HAL_RCC_TIM7_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM7时钟
#define __TIM7_CLK_SLEEP_ENABLE __HAL_RCC_TIM7_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM7时钟
#define __TIM7_FORCE_RESET __HAL_RCC_TIM7_FORCE_RESET           // 强制复位TIM7外设
#define __TIM7_RELEASE_RESET __HAL_RCC_TIM7_RELEASE_RESET       // 释放TIM7外设的复位

#define __TIM8_CLK_DISABLE __HAL_RCC_TIM8_CLK_DISABLE           // 禁用定时器8(TIM8)时钟
#define __TIM8_CLK_ENABLE __HAL_RCC_TIM8_CLK_ENABLE             // 使能定时器8(TIM8)时钟
#define __TIM8_CLK_SLEEP_DISABLE __HAL_RCC_TIM8_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TIM8时钟
#define __TIM8_CLK_SLEEP_ENABLE __HAL_RCC_TIM8_CLK_SLEEP_ENABLE // 在睡眠模式下使能TIM8时钟
#define __TIM8_FORCE_RESET __HAL_RCC_TIM8_FORCE_RESET           // 强制复位TIM8外设
#define __TIM8_RELEASE_RESET __HAL_RCC_TIM8_RELEASE_RESET       // 释放TIM8外设的复位

#define __TIM9_CLK_DISABLE __HAL_RCC_TIM9_CLK_DISABLE           // 禁用定时器9(TIM9)时钟
#define __TIM9_CLK_ENABLE __HAL_RCC_TIM9_CLK_ENABLE             // 使能定时器9(TIM9)时钟
#define __TIM9_FORCE_RESET __HAL_RCC_TIM9_FORCE_RESET           // 强制复位TIM9外设
#define __TIM9_RELEASE_RESET __HAL_RCC_TIM9_RELEASE_RESET       // 释放TIM9外设的复位

#define __TSC_CLK_DISABLE __HAL_RCC_TSC_CLK_DISABLE             // 禁用触摸感应控制器(TSC)时钟
#define __TSC_CLK_ENABLE __HAL_RCC_TSC_CLK_ENABLE               // 使能触摸感应控制器(TSC)时钟
#define __TSC_CLK_SLEEP_DISABLE __HAL_RCC_TSC_CLK_SLEEP_DISABLE // 在睡眠模式下禁用TSC时钟
#define __TSC_CLK_SLEEP_ENABLE __HAL_RCC_TSC_CLK_SLEEP_ENABLE   // 在睡眠模式下使能TSC时钟
#define __TSC_FORCE_RESET __HAL_RCC_TSC_FORCE_RESET             // 强制复位TSC外设
#define __TSC_RELEASE_RESET __HAL_RCC_TSC_RELEASE_RESET         // 释放TSC外设的复位

#define __UART4_CLK_DISABLE __HAL_RCC_UART4_CLK_DISABLE         // 禁用通用异步收发器4(UART4)时钟
#define __UART4_CLK_ENABLE __HAL_RCC_UART4_CLK_ENABLE           // 使能通用异步收发器4(UART4)时钟
#define __UART4_CLK_SLEEP_DISABLE __HAL_RCC_UART4_CLK_SLEEP_DISABLE // 在睡眠模式下禁用UART4时钟
#define __UART4_CLK_SLEEP_ENABLE __HAL_RCC_UART4_CLK_SLEEP_ENABLE // 在睡眠模式下使能UART4时钟
#define __UART4_FORCE_RESET __HAL_RCC_UART4_FORCE_RESET         // 强制复位UART4外设
#define __UART4_RELEASE_RESET __HAL_RCC_UART4_RELEASE_RESET     // 释放UART4外设的复位

#define __UART5_CLK_DISABLE __HAL_RCC_UART5_CLK_DISABLE         // 禁用通用异步收发器5(UART5)时钟
#define __UART5_CLK_ENABLE __HAL_RCC_UART5_CLK_ENABLE           // 使能通用异步收发器5(UART5)时钟
#define __UART5_CLK_SLEEP_DISABLE __HAL_RCC_UART5_CLK_SLEEP_DISABLE // 在睡眠模式下禁用UART5时钟
#define __UART5_CLK_SLEEP_ENABLE __HAL_RCC_UART5_CLK_SLEEP_ENABLE // 在睡眠模式下使能UART5时钟
#define __UART5_FORCE_RESET __HAL_RCC_UART5_FORCE_RESET         // 强制复位UART5外设
#define __UART5_RELEASE_RESET __HAL_RCC_UART5_RELEASE_RESET     // 释放UART5外设的复位

#define __USART1_CLK_DISABLE __HAL_RCC_USART1_CLK_DISABLE       // 禁用通用同步异步收发器1(USART1)时钟
#define __USART1_CLK_ENABLE __HAL_RCC_USART1_CLK_ENABLE         // 使能通用同步异步收发器1(USART1)时钟
#define __USART1_CLK_SLEEP_DISABLE __HAL_RCC_USART1_CLK_SLEEP_DISABLE // 在睡眠模式下禁用USART1时钟
#define __USART1_CLK_SLEEP_ENABLE __HAL_RCC_USART1_CLK_SLEEP_ENABLE // 在睡眠模式下使能USART1时钟
#define __USART1_FORCE_RESET __HAL_RCC_USART1_FORCE_RESET       // 强制复位USART1外设
#define __USART1_RELEASE_RESET __HAL_RCC_USART1_RELEASE_RESET   // 释放USART1外设的复位

#define __USART2_CLK_DISABLE __HAL_RCC_USART2_CLK_DISABLE       // 禁用通用同步异步收发器2(USART2)时钟
#define __USART2_CLK_ENABLE __HAL_RCC_USART2_CLK_ENABLE         // 使能通用同步异步收发器2(USART2)时钟
#define __USART2_CLK_SLEEP_DISABLE __HAL_RCC_USART2_CLK_SLEEP_DISABLE // 在睡眠模式下禁用USART2时钟
#define __USART2_CLK_SLEEP_ENABLE __HAL_RCC_USART2_CLK_SLEEP_ENABLE // 在睡眠模式下使能USART2时钟
#define __USART2_FORCE_RESET __HAL_RCC_USART2_FORCE_RESET       // 强制复位USART2外设
#define __USART2_RELEASE_RESET __HAL_RCC_USART2_RELEASE_RESET   // 释放USART2外设的复位

#define __USART3_CLK_DISABLE __HAL_RCC_USART3_CLK_DISABLE       // 禁用通用同步异步收发器3(USART3)时钟
#define __USART3_CLK_ENABLE __HAL_RCC_USART3_CLK_ENABLE         // 使能通用同步异步收发器3(USART3)时钟
#define __USART3_CLK_SLEEP_DISABLE __HAL_RCC_USART3_CLK_SLEEP_DISABLE // 在睡眠模式下禁用USART3时钟
#define __USART3_CLK_SLEEP_ENABLE __HAL_RCC_USART3_CLK_SLEEP_ENABLE // 在睡眠模式下使能USART3时钟
#define __USART3_FORCE_RESET __HAL_RCC_USART3_FORCE_RESET       // 强制复位USART3外设
#define __USART3_RELEASE_RESET __HAL_RCC_USART3_RELEASE_RESET   // 释放USART3外设的复位

// USART4宏定义指向UART4的宏，USART4与UART4在某些芯片上功能相同
#define __USART4_CLK_DISABLE        __HAL_RCC_UART4_CLK_DISABLE        // 禁用USART4时钟（实际使用UART4的时钟控制）
#define __USART4_CLK_ENABLE         __HAL_RCC_UART4_CLK_ENABLE         // 使能USART4时钟（实际使用UART4的时钟控制）
#define __USART4_CLK_SLEEP_ENABLE   __HAL_RCC_UART4_CLK_SLEEP_ENABLE   // 在睡眠模式下使能USART4时钟（实际使用UART4的时钟控制）
#define __USART4_CLK_SLEEP_DISABLE  __HAL_RCC_UART4_CLK_SLEEP_DISABLE  // 在睡眠模式下禁用USART4时钟（实际使用UART4的时钟控制）
#define __USART4_FORCE_RESET        __HAL_RCC_UART4_FORCE_RESET        // 强制复位USART4外设（实际使用UART4的复位控制）
#define __USART4_RELEASE_RESET      __HAL_RCC_UART4_RELEASE_RESET      // 释放USART4外设的复位（实际使用UART4的复位控制）

// USART5宏定义指向UART5的宏，USART5与UART5在某些芯片上功能相同
#define __USART5_CLK_DISABLE        __HAL_RCC_UART5_CLK_DISABLE        // 禁用USART5时钟（实际使用UART5的时钟控制）
#define __USART5_CLK_ENABLE         __HAL_RCC_UART5_CLK_ENABLE         // 使能USART5时钟（实际使用UART5的时钟控制）
#define __USART5_CLK_SLEEP_ENABLE   __HAL_RCC_UART5_CLK_SLEEP_ENABLE   // 在睡眠模式下使能USART5时钟（实际使用UART5的时钟控制）
#define __USART5_CLK_SLEEP_DISABLE  __HAL_RCC_UART5_CLK_SLEEP_DISABLE  // 在睡眠模式下禁用USART5时钟（实际使用UART5的时钟控制）
#define __USART5_FORCE_RESET        __HAL_RCC_UART5_FORCE_RESET        // 强制复位USART5外设（实际使用UART5的复位控制）
#define __USART5_RELEASE_RESET      __HAL_RCC_UART5_RELEASE_RESET      // 释放USART5外设的复位（实际使用UART5的复位控制）

#define __USART7_CLK_DISABLE        __HAL_RCC_UART7_CLK_DISABLE        // 禁用USART7时钟
#define __USART7_CLK_ENABLE         __HAL_RCC_UART7_CLK_ENABLE         // 使能USART7时钟
#define __USART7_FORCE_RESET        __HAL_RCC_UART7_FORCE_RESET        // 强制复位USART7外设
#define __USART7_RELEASE_RESET      __HAL_RCC_UART7_RELEASE_RESET      // 释放USART7外设的复位

#define __USART8_CLK_DISABLE        __HAL_RCC_UART8_CLK_DISABLE        // 禁用USART8时钟
#define __USART8_CLK_ENABLE         __HAL_RCC_UART8_CLK_ENABLE         // 使能USART8时钟
#define __USART8_FORCE_RESET        __HAL_RCC_UART8_FORCE_RESET        // 强制复位USART8外设
#define __USART8_RELEASE_RESET      __HAL_RCC_UART8_RELEASE_RESET      // 释放USART8外设的复位

#define __USB_CLK_DISABLE         __HAL_RCC_USB_CLK_DISABLE            // 禁用USB时钟
#define __USB_CLK_ENABLE          __HAL_RCC_USB_CLK_ENABLE             // 使能USB时钟
#define __USB_FORCE_RESET         __HAL_RCC_USB_FORCE_RESET            // 强制复位USB外设
#define __USB_CLK_SLEEP_ENABLE    __HAL_RCC_USB_CLK_SLEEP_ENABLE       // 在睡眠模式下使能USB时钟
#define __USB_CLK_SLEEP_DISABLE   __HAL_RCC_USB_CLK_SLEEP_DISABLE      // 在睡眠模式下禁用USB时钟
#define __USB_OTG_FS_CLK_DISABLE __HAL_RCC_USB_OTG_FS_CLK_DISABLE      // 禁用USB OTG FS时钟
#define __USB_OTG_FS_CLK_ENABLE __HAL_RCC_USB_OTG_FS_CLK_ENABLE        // 使能USB OTG FS时钟
#define __USB_RELEASE_RESET __HAL_RCC_USB_RELEASE_RESET                // 释放USB外设的复位
#if defined(STM32H7)  /* 如果定义了STM32H7，则编译以下宏定义 */
#define __HAL_RCC_WWDG_CLK_DISABLE   __HAL_RCC_WWDG1_CLK_DISABLE  /* 禁用WWDG时钟 */
#define __HAL_RCC_WWDG_CLK_ENABLE   __HAL_RCC_WWDG1_CLK_ENABLE    /* 使能WWDG时钟 */
#define __HAL_RCC_WWDG_CLK_SLEEP_DISABLE  __HAL_RCC_WWDG1_CLK_SLEEP_DISABLE  /* 在睡眠模式下禁用WWDG时钟 */
#define __HAL_RCC_WWDG_CLK_SLEEP_ENABLE  __HAL_RCC_WWDG1_CLK_SLEEP_ENABLE    /* 在睡眠模式下使能WWDG时钟 */

#define __HAL_RCC_WWDG_FORCE_RESET    ((void)0U)  /* 在STM32H7上不可用 */
#define __HAL_RCC_WWDG_RELEASE_RESET ((void)0U) /* 在STM32H7上不可用 */


#define  __HAL_RCC_WWDG_IS_CLK_ENABLED    __HAL_RCC_WWDG1_IS_CLK_ENABLED    /* 检查WWDG时钟是否使能 */
#define  __HAL_RCC_WWDG_IS_CLK_DISABLED  __HAL_RCC_WWDG1_IS_CLK_DISABLED    /* 检查WWDG时钟是否禁用 */
#define  RCC_SPI4CLKSOURCE_D2PCLK1       RCC_SPI4CLKSOURCE_D2PCLK2          /* 将SPI4时钟源D2PCLK1重定义为D2PCLK2 */
#define  RCC_SPI5CLKSOURCE_D2PCLK1       RCC_SPI5CLKSOURCE_D2PCLK2          /* 将SPI5时钟源D2PCLK1重定义为D2PCLK2 */
#define  RCC_SPI45CLKSOURCE_D2PCLK1      RCC_SPI45CLKSOURCE_D2PCLK2         /* 将SPI45时钟源D2PCLK1重定义为D2PCLK2 */
#define  RCC_SPI45CLKSOURCE_CDPCLK1      RCC_SPI45CLKSOURCE_CDPCLK2         /* 将SPI45时钟源CDPCLK1重定义为CDPCLK2 */
#define  RCC_SPI45CLKSOURCE_PCLK1        RCC_SPI45CLKSOURCE_PCLK2           /* 将SPI45时钟源PCLK1重定义为PCLK2 */
#endif  /* 结束STM32H7条件编译 */

#define __WWDG_CLK_DISABLE __HAL_RCC_WWDG_CLK_DISABLE  /* 禁用WWDG时钟的简写宏 */
#define __WWDG_CLK_ENABLE __HAL_RCC_WWDG_CLK_ENABLE    /* 使能WWDG时钟的简写宏 */
#define __WWDG_CLK_SLEEP_DISABLE __HAL_RCC_WWDG_CLK_SLEEP_DISABLE  /* 在睡眠模式下禁用WWDG时钟的简写宏 */
#define __WWDG_CLK_SLEEP_ENABLE __HAL_RCC_WWDG_CLK_SLEEP_ENABLE    /* 在睡眠模式下使能WWDG时钟的简写宏 */
#define __WWDG_FORCE_RESET __HAL_RCC_WWDG_FORCE_RESET              /* 强制复位WWDG的简写宏 */
#define __WWDG_RELEASE_RESET __HAL_RCC_WWDG_RELEASE_RESET          /* 释放WWDG复位的简写宏 */

#define __TIM21_CLK_ENABLE   __HAL_RCC_TIM21_CLK_ENABLE            /* 使能TIM21时钟 */
#define __TIM21_CLK_DISABLE   __HAL_RCC_TIM21_CLK_DISABLE          /* 禁用TIM21时钟 */
#define __TIM21_FORCE_RESET   __HAL_RCC_TIM21_FORCE_RESET          /* 强制复位TIM21 */
#define __TIM21_RELEASE_RESET  __HAL_RCC_TIM21_RELEASE_RESET       /* 释放TIM21复位 */
#define __TIM21_CLK_SLEEP_ENABLE   __HAL_RCC_TIM21_CLK_SLEEP_ENABLE   /* 在睡眠模式下使能TIM21时钟 */
#define __TIM21_CLK_SLEEP_DISABLE   __HAL_RCC_TIM21_CLK_SLEEP_DISABLE /* 在睡眠模式下禁用TIM21时钟 */
#define __TIM22_CLK_ENABLE   __HAL_RCC_TIM22_CLK_ENABLE            /* 使能TIM22时钟 */
#define __TIM22_CLK_DISABLE   __HAL_RCC_TIM22_CLK_DISABLE          /* 禁用TIM22时钟 */
#define __TIM22_FORCE_RESET   __HAL_RCC_TIM22_FORCE_RESET          /* 强制复位TIM22 */
#define __TIM22_RELEASE_RESET  __HAL_RCC_TIM22_RELEASE_RESET       /* 释放TIM22复位 */
#define __TIM22_CLK_SLEEP_ENABLE   __HAL_RCC_TIM22_CLK_SLEEP_ENABLE   /* 在睡眠模式下使能TIM22时钟 */
#define __TIM22_CLK_SLEEP_DISABLE   __HAL_RCC_TIM22_CLK_SLEEP_DISABLE /* 在睡眠模式下禁用TIM22时钟 */
#define __CRS_CLK_DISABLE __HAL_RCC_CRS_CLK_DISABLE                /* 禁用CRS时钟 */
#define __CRS_CLK_ENABLE __HAL_RCC_CRS_CLK_ENABLE                  /* 使能CRS时钟 */
#define __CRS_CLK_SLEEP_DISABLE __HAL_RCC_CRS_CLK_SLEEP_DISABLE    /* 在睡眠模式下禁用CRS时钟 */
#define __CRS_CLK_SLEEP_ENABLE __HAL_RCC_CRS_CLK_SLEEP_ENABLE      /* 在睡眠模式下使能CRS时钟 */
#define __CRS_FORCE_RESET __HAL_RCC_CRS_FORCE_RESET                /* 强制复位CRS */
#define __CRS_RELEASE_RESET __HAL_RCC_CRS_RELEASE_RESET            /* 释放CRS复位 */
#define __RCC_BACKUPRESET_FORCE __HAL_RCC_BACKUPRESET_FORCE        /* 强制备份域复位 */
#define __RCC_BACKUPRESET_RELEASE __HAL_RCC_BACKUPRESET_RELEASE    /* 释放备份域复位 */
#define __USB_OTG_FS_FORCE_RESET  __HAL_RCC_USB_OTG_FS_FORCE_RESET        /* 强制复位USB OTG FS外设 */
#define __USB_OTG_FS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET    /* 释放USB OTG FS外设的复位 */
#define __USB_OTG_FS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE      /* 在睡眠模式下使能USB OTG FS时钟 */
#define __USB_OTG_FS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE    /* 在睡眠模式下禁用USB OTG FS时钟 */
#define __USB_OTG_HS_CLK_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_DISABLE                /* 禁用USB OTG HS时钟 */
#define __USB_OTG_HS_CLK_ENABLE          __HAL_RCC_USB_OTG_HS_CLK_ENABLE          /* 使能USB OTG HS时钟 */
#define __USB_OTG_HS_ULPI_CLK_ENABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE        /* 使能USB OTG HS ULPI时钟 */
#define __USB_OTG_HS_ULPI_CLK_DISABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE      /* 禁用USB OTG HS ULPI时钟 */
#define __TIM9_CLK_SLEEP_ENABLE          __HAL_RCC_TIM9_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能TIM9时钟 */
#define __TIM9_CLK_SLEEP_DISABLE  __HAL_RCC_TIM9_CLK_SLEEP_DISABLE                /* 在睡眠模式下禁用TIM9时钟 */
#define __TIM10_CLK_SLEEP_ENABLE  __HAL_RCC_TIM10_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能TIM10时钟 */
#define __TIM10_CLK_SLEEP_DISABLE  __HAL_RCC_TIM10_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用TIM10时钟 */
#define __TIM11_CLK_SLEEP_ENABLE  __HAL_RCC_TIM11_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能TIM11时钟 */
#define __TIM11_CLK_SLEEP_DISABLE  __HAL_RCC_TIM11_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用TIM11时钟 */
#define __ETHMACPTP_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACPTP_CLK_SLEEP_ENABLE        /* 在睡眠模式下使能以太网MAC PTP时钟 */
#define __ETHMACPTP_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACPTP_CLK_SLEEP_DISABLE      /* 在睡眠模式下禁用以太网MAC PTP时钟 */
#define __ETHMACPTP_CLK_ENABLE          __HAL_RCC_ETHMACPTP_CLK_ENABLE            /* 使能以太网MAC PTP时钟 */
#define __ETHMACPTP_CLK_DISABLE          __HAL_RCC_ETHMACPTP_CLK_DISABLE          /* 禁用以太网MAC PTP时钟 */
#define __HASH_CLK_ENABLE          __HAL_RCC_HASH_CLK_ENABLE                      /* 使能哈希(HASH)模块时钟 */
#define __HASH_FORCE_RESET          __HAL_RCC_HASH_FORCE_RESET                    /* 强制复位哈希(HASH)模块 */
#define __HASH_RELEASE_RESET          __HAL_RCC_HASH_RELEASE_RESET                /* 释放哈希(HASH)模块的复位 */
#define __HASH_CLK_SLEEP_ENABLE          __HAL_RCC_HASH_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能哈希模块时钟 */
#define __HASH_CLK_SLEEP_DISABLE  __HAL_RCC_HASH_CLK_SLEEP_DISABLE                /* 在睡眠模式下禁用哈希模块时钟 */
#define __HASH_CLK_DISABLE            __HAL_RCC_HASH_CLK_DISABLE                  /* 禁用哈希(HASH)模块时钟 */
#define __SPI5_CLK_ENABLE          __HAL_RCC_SPI5_CLK_ENABLE                      /* 使能SPI5时钟 */
#define __SPI5_CLK_DISABLE              __HAL_RCC_SPI5_CLK_DISABLE                /* 禁用SPI5时钟 */
#define __SPI5_FORCE_RESET          __HAL_RCC_SPI5_FORCE_RESET                    /* 强制复位SPI5外设 */
#define __SPI5_RELEASE_RESET          __HAL_RCC_SPI5_RELEASE_RESET                /* 释放SPI5外设的复位 */
#define __SPI5_CLK_SLEEP_ENABLE          __HAL_RCC_SPI5_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能SPI5时钟 */
#define __SPI5_CLK_SLEEP_DISABLE  __HAL_RCC_SPI5_CLK_SLEEP_DISABLE                /* 在睡眠模式下禁用SPI5时钟 */
#define __SPI6_CLK_ENABLE          __HAL_RCC_SPI6_CLK_ENABLE                      /* 使能SPI6时钟 */
#define __SPI6_CLK_DISABLE          __HAL_RCC_SPI6_CLK_DISABLE                    /* 禁用SPI6时钟 */
#define __SPI6_FORCE_RESET          __HAL_RCC_SPI6_FORCE_RESET                    /* 强制复位SPI6外设 */
#define __SPI6_RELEASE_RESET         __HAL_RCC_SPI6_RELEASE_RESET                 /* 释放SPI6外设的复位 */
#define __SPI6_CLK_SLEEP_ENABLE          __HAL_RCC_SPI6_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能SPI6时钟 */
#define __SPI6_CLK_SLEEP_DISABLE  __HAL_RCC_SPI6_CLK_SLEEP_DISABLE                /* 在睡眠模式下禁用SPI6时钟 */
#define __LTDC_CLK_ENABLE          __HAL_RCC_LTDC_CLK_ENABLE                      /* 使能LTDC（LCD-TFT显示控制器）时钟 */
#define __LTDC_CLK_DISABLE          __HAL_RCC_LTDC_CLK_DISABLE                    /* 禁用LTDC时钟 */
#define __LTDC_FORCE_RESET          __HAL_RCC_LTDC_FORCE_RESET                    /* 强制复位LTDC外设 */
#define __LTDC_RELEASE_RESET          __HAL_RCC_LTDC_RELEASE_RESET                /* 释放LTDC外设的复位 */
#define __LTDC_CLK_SLEEP_ENABLE          __HAL_RCC_LTDC_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能LTDC时钟 */
#define __ETHMAC_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMAC_CLK_SLEEP_ENABLE              /* 在睡眠模式下使能以太网MAC时钟 */
#define __ETHMAC_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMAC_CLK_SLEEP_DISABLE            /* 在睡眠模式下禁用以太网MAC时钟 */
#define __ETHMACTX_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACTX_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能以太网MAC发送时钟 */
#define __ETHMACTX_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACTX_CLK_SLEEP_DISABLE        /* 在睡眠模式下禁用以太网MAC发送时钟 */
#define __ETHMACRX_CLK_SLEEP_ENABLE  __HAL_RCC_ETHMACRX_CLK_SLEEP_ENABLE          /* 在睡眠模式下使能以太网MAC接收时钟 */
#define __ETHMACRX_CLK_SLEEP_DISABLE  __HAL_RCC_ETHMACRX_CLK_SLEEP_DISABLE        /* 在睡眠模式下禁用以太网MAC接收时钟 */
#define __TIM12_CLK_SLEEP_ENABLE  __HAL_RCC_TIM12_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能TIM12时钟 */
#define __TIM12_CLK_SLEEP_DISABLE  __HAL_RCC_TIM12_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用TIM12时钟 */
#define __TIM13_CLK_SLEEP_ENABLE  __HAL_RCC_TIM13_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能TIM13时钟 */
#define __TIM13_CLK_SLEEP_DISABLE  __HAL_RCC_TIM13_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用TIM13时钟 */
#define __TIM14_CLK_SLEEP_ENABLE  __HAL_RCC_TIM14_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能TIM14时钟 */
#define __TIM14_CLK_SLEEP_DISABLE  __HAL_RCC_TIM14_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用TIM14时钟 */
#define __BKPSRAM_CLK_ENABLE          __HAL_RCC_BKPSRAM_CLK_ENABLE                /* 使能备份SRAM（BKPSRAM）时钟 */
#define __BKPSRAM_CLK_DISABLE          __HAL_RCC_BKPSRAM_CLK_DISABLE              /* 禁用备份SRAM时钟 */
#define __BKPSRAM_CLK_SLEEP_ENABLE  __HAL_RCC_BKPSRAM_CLK_SLEEP_ENABLE            /* 在睡眠模式下使能备份SRAM时钟 */
#define __BKPSRAM_CLK_SLEEP_DISABLE  __HAL_RCC_BKPSRAM_CLK_SLEEP_DISABLE          /* 在睡眠模式下禁用备份SRAM时钟 */
#define __CCMDATARAMEN_CLK_ENABLE  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE              /* 使能CCM数据RAM时钟 */
#define __CCMDATARAMEN_CLK_DISABLE  __HAL_RCC_CCMDATARAMEN_CLK_DISABLE            /* 禁用CCM数据RAM时钟 */
#define __USART6_CLK_ENABLE          __HAL_RCC_USART6_CLK_ENABLE                  /* 使能USART6时钟 */
#define __USART6_CLK_DISABLE          __HAL_RCC_USART6_CLK_DISABLE                /* 禁用USART6时钟 */
#define __USART6_FORCE_RESET        __HAL_RCC_USART6_FORCE_RESET                  /* 强制复位USART6外设 */
#define __USART6_RELEASE_RESET        __HAL_RCC_USART6_RELEASE_RESET              /* 释放USART6外设的复位 */
#define __USART6_CLK_SLEEP_ENABLE  __HAL_RCC_USART6_CLK_SLEEP_ENABLE              /* 在睡眠模式下使能USART6时钟 */
#define __USART6_CLK_SLEEP_DISABLE  __HAL_RCC_USART6_CLK_SLEEP_DISABLE            /* 在睡眠模式下禁用USART6时钟 */
#define __SPI4_CLK_ENABLE          __HAL_RCC_SPI4_CLK_ENABLE                      /* 使能SPI4时钟 */
#define __SPI4_CLK_DISABLE          __HAL_RCC_SPI4_CLK_DISABLE                    /* 禁用SPI4时钟 */
#define __SPI4_FORCE_RESET          __HAL_RCC_SPI4_FORCE_RESET                    /* 强制复位SPI4外设 */
#define __SPI4_RELEASE_RESET        __HAL_RCC_SPI4_RELEASE_RESET                  /* 释放SPI4外设的复位 */
#define __SPI4_CLK_SLEEP_ENABLE   __HAL_RCC_SPI4_CLK_SLEEP_ENABLE                 /* 在睡眠模式下使能SPI4时钟 */
#define __SPI4_CLK_SLEEP_DISABLE  __HAL_RCC_SPI4_CLK_SLEEP_DISABLE                /* 在睡眠模式下禁用SPI4时钟 */
#define __GPIOI_CLK_ENABLE          __HAL_RCC_GPIOI_CLK_ENABLE                    /* 使能GPIOI端口时钟 */
#define __GPIOI_CLK_DISABLE          __HAL_RCC_GPIOI_CLK_DISABLE                  /* 禁用GPIOI端口时钟 */
#define __GPIOI_FORCE_RESET          __HAL_RCC_GPIOI_FORCE_RESET                  /* 强制复位GPIOI外设 */
#define __GPIOI_RELEASE_RESET          __HAL_RCC_GPIOI_RELEASE_RESET              /* 释放GPIOI外设的复位 */
#define __GPIOI_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOI_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能GPIOI时钟 */
#define __GPIOI_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOI_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用GPIOI时钟 */
#define __GPIOJ_CLK_ENABLE          __HAL_RCC_GPIOJ_CLK_ENABLE                    /* 使能GPIOJ端口时钟 */
#define __GPIOJ_CLK_DISABLE          __HAL_RCC_GPIOJ_CLK_DISABLE                  /* 禁用GPIOJ端口时钟 */
#define __GPIOJ_FORCE_RESET         __HAL_RCC_GPIOJ_FORCE_RESET                   /* 强制复位GPIOJ外设 */
#define __GPIOJ_RELEASE_RESET          __HAL_RCC_GPIOJ_RELEASE_RESET              /* 释放GPIOJ外设的复位 */
#define __GPIOJ_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOJ_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能GPIOJ时钟 */
#define __GPIOJ_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOJ_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用GPIOJ时钟 */
#define __GPIOK_CLK_ENABLE          __HAL_RCC_GPIOK_CLK_ENABLE                    /* 使能GPIOK端口时钟 */
#define __GPIOK_CLK_DISABLE          __HAL_RCC_GPIOK_CLK_DISABLE                  /* 禁用GPIOK端口时钟 */
#define __GPIOK_RELEASE_RESET          __HAL_RCC_GPIOK_RELEASE_RESET              /* 释放GPIOK外设的复位 */
#define __GPIOK_CLK_SLEEP_ENABLE  __HAL_RCC_GPIOK_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能GPIOK时钟 */
#define __GPIOK_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOK_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用GPIOK时钟 */
#define __ETH_CLK_ENABLE          __HAL_RCC_ETH_CLK_ENABLE                        /* 使能以太网时钟 */
#define __ETH_CLK_DISABLE          __HAL_RCC_ETH_CLK_DISABLE                      /* 禁用以太网时钟 */
#define __DCMI_CLK_ENABLE          __HAL_RCC_DCMI_CLK_ENABLE                      /* 使能DCMI（数字摄像头接口）时钟 */
#define __DCMI_CLK_DISABLE          __HAL_RCC_DCMI_CLK_DISABLE                    /* 禁用DCMI时钟 */
#define __DCMI_FORCE_RESET          __HAL_RCC_DCMI_FORCE_RESET                    /* 强制复位DCMI外设 */
#define __DCMI_RELEASE_RESET          __HAL_RCC_DCMI_RELEASE_RESET                /* 释放DCMI外设的复位 */
#define __DCMI_CLK_SLEEP_ENABLE   __HAL_RCC_DCMI_CLK_SLEEP_ENABLE                 /* 在睡眠模式下使能DCMI时钟 */
#define __DCMI_CLK_SLEEP_DISABLE  __HAL_RCC_DCMI_CLK_SLEEP_DISABLE                /* 在睡眠模式下禁用DCMI时钟 */
#define __UART7_CLK_ENABLE          __HAL_RCC_UART7_CLK_ENABLE                    /* 使能UART7时钟 */
#define __UART7_CLK_DISABLE          __HAL_RCC_UART7_CLK_DISABLE                  /* 禁用UART7时钟 */
#define __UART7_RELEASE_RESET       __HAL_RCC_UART7_RELEASE_RESET                 /* 释放UART7外设的复位 */
#define __UART7_FORCE_RESET       __HAL_RCC_UART7_FORCE_RESET                     /* 强制复位UART7外设 */
#define __UART7_CLK_SLEEP_ENABLE  __HAL_RCC_UART7_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能UART7时钟 */
#define __UART7_CLK_SLEEP_DISABLE  __HAL_RCC_UART7_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用UART7时钟 */
#define __UART8_CLK_ENABLE          __HAL_RCC_UART8_CLK_ENABLE                    /* 使能UART8时钟 */
#define __UART8_CLK_DISABLE          __HAL_RCC_UART8_CLK_DISABLE                  /* 禁用UART8时钟 */
#define __UART8_FORCE_RESET          __HAL_RCC_UART8_FORCE_RESET                  /* 强制复位UART8外设 */
#define __UART8_RELEASE_RESET          __HAL_RCC_UART8_RELEASE_RESET              /* 释放UART8外设的复位 */
#define __UART8_CLK_SLEEP_ENABLE  __HAL_RCC_UART8_CLK_SLEEP_ENABLE                /* 在睡眠模式下使能UART8时钟 */
#define __UART8_CLK_SLEEP_DISABLE  __HAL_RCC_UART8_CLK_SLEEP_DISABLE              /* 在睡眠模式下禁用UART8时钟 */
#define __OTGHS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE           /* 在睡眠模式下使能USB OTG HS时钟 (OTGHS是USB_OTG_HS的别名) */
#define __OTGHS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE         /* 在睡眠模式下禁用USB OTG HS时钟 */
#define __OTGHS_FORCE_RESET          __HAL_RCC_USB_OTG_HS_FORCE_RESET             /* 强制复位USB OTG HS外设 */
#define __OTGHS_RELEASE_RESET          __HAL_RCC_USB_OTG_HS_RELEASE_RESET         /* 释放USB OTG HS外设的复位 */
#define __OTGHSULPI_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE  /* 在睡眠模式下使能USB OTG HS ULPI时钟 */
#define __OTGHSULPI_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE /* 在睡眠模式下禁用USB OTG HS ULPI时钟 */
#define __HAL_RCC_OTGHS_CLK_SLEEP_ENABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE   /* HAL RCC函数: 在睡眠模式下使能USB OTG HS时钟 */
#define __HAL_RCC_OTGHS_CLK_SLEEP_DISABLE  __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE /* HAL RCC函数: 在睡眠模式下禁用USB OTG HS时钟 */
#define __HAL_RCC_OTGHS_IS_CLK_SLEEP_ENABLED __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_ENABLED /* HAL RCC函数: 检查USB OTG HS睡眠时钟是否已使能 */
#define __HAL_RCC_OTGHS_IS_CLK_SLEEP_DISABLED __HAL_RCC_USB_OTG_HS_IS_CLK_SLEEP_DISABLED /* HAL RCC函数: 检查USB OTG HS睡眠时钟是否已禁用 */
#define __HAL_RCC_OTGHS_FORCE_RESET          __HAL_RCC_USB_OTG_HS_FORCE_RESET     /* HAL RCC函数: 强制复位USB OTG HS外设 */
#define __HAL_RCC_OTGHS_RELEASE_RESET          __HAL_RCC_USB_OTG_HS_RELEASE_RESET /* HAL RCC函数: 释放USB OTG HS外设的复位 */
#define __HAL_RCC_OTGHSULPI_CLK_SLEEP_ENABLE      __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE      /* HAL RCC函数: 在睡眠模式下使能USB OTG HS ULPI时钟 */
#define __HAL_RCC_OTGHSULPI_CLK_SLEEP_DISABLE     __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE     /* HAL RCC函数: 在睡眠模式下禁用USB OTG HS ULPI时钟 */
#define __HAL_RCC_OTGHSULPI_IS_CLK_SLEEP_ENABLED  __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_ENABLED  /* HAL RCC函数: 检查USB OTG HS ULPI睡眠时钟是否已使能 */
#define __HAL_RCC_OTGHSULPI_IS_CLK_SLEEP_DISABLED __HAL_RCC_USB_OTG_HS_ULPI_IS_CLK_SLEEP_DISABLED /* HAL RCC函数: 检查USB OTG HS ULPI睡眠时钟是否已禁用 */
#define __SRAM3_CLK_SLEEP_ENABLE       __HAL_RCC_SRAM3_CLK_SLEEP_ENABLE           /* 在睡眠模式下使能SRAM3时钟 */
#define __CAN2_CLK_SLEEP_ENABLE        __HAL_RCC_CAN2_CLK_SLEEP_ENABLE            /* 在睡眠模式下使能CAN2时钟 */
#define __CAN2_CLK_SLEEP_DISABLE       __HAL_RCC_CAN2_CLK_SLEEP_DISABLE           /* 在睡眠模式下禁用CAN2时钟 */
#define __DAC_CLK_SLEEP_ENABLE         __HAL_RCC_DAC_CLK_SLEEP_ENABLE             /* 在睡眠模式下使能DAC时钟 */
#define __DAC_CLK_SLEEP_DISABLE        __HAL_RCC_DAC_CLK_SLEEP_DISABLE            /* 在睡眠模式下禁用DAC时钟 */
#define __ADC2_CLK_SLEEP_ENABLE        __HAL_RCC_ADC2_CLK_SLEEP_ENABLE            /* 在睡眠模式下使能ADC2时钟 */
#define __ADC2_CLK_SLEEP_DISABLE       __HAL_RCC_ADC2_CLK_SLEEP_DISABLE           /* 在睡眠模式下禁用ADC2时钟 */
#define __ADC3_CLK_SLEEP_ENABLE        __HAL_RCC_ADC3_CLK_SLEEP_ENABLE            /* 在睡眠模式下使能ADC3时钟 */
#define __ADC3_CLK_SLEEP_DISABLE       __HAL_RCC_ADC3_CLK_SLEEP_DISABLE           /* 在睡眠模式下禁用ADC3时钟 */
#define __FSMC_FORCE_RESET             __HAL_RCC_FSMC_FORCE_RESET                 /* 强制复位FSMC（灵活的静态存储控制器）外设 */
#define __FSMC_RELEASE_RESET           __HAL_RCC_FSMC_RELEASE_RESET               /* 释放FSMC外设的复位 */
#define __FSMC_CLK_SLEEP_ENABLE        __HAL_RCC_FSMC_CLK_SLEEP_ENABLE            /* 在睡眠模式下使能FSMC时钟 */
#define __FSMC_CLK_SLEEP_DISABLE       __HAL_RCC_FSMC_CLK_SLEEP_DISABLE           /* 在睡眠模式下禁用FSMC时钟 */
#define __SDIO_FORCE_RESET             __HAL_RCC_SDIO_FORCE_RESET                 /* 强制复位SDIO外设 */
#define __SDIO_RELEASE_RESET           __HAL_RCC_SDIO_RELEASE_RESET               /* 释放SDIO外设的复位 */
#define __SDIO_CLK_SLEEP_DISABLE       __HAL_RCC_SDIO_CLK_SLEEP_DISABLE           /* 在睡眠模式下禁用SDIO时钟 */
#define __SDIO_CLK_SLEEP_ENABLE        __HAL_RCC_SDIO_CLK_SLEEP_ENABLE            /* 在睡眠模式下使能SDIO时钟 */
#define __DMA2D_CLK_ENABLE             __HAL_RCC_DMA2D_CLK_ENABLE                 /* 使能DMA2D（直接存储器访问2D）时钟 */
#define __DMA2D_CLK_DISABLE            __HAL_RCC_DMA2D_CLK_DISABLE                /* 禁用DMA2D时钟 */
#define __DMA2D_FORCE_RESET            __HAL_RCC_DMA2D_FORCE_RESET                /* 强制复位DMA2D外设 */
#define __DMA2D_RELEASE_RESET          __HAL_RCC_DMA2D_RELEASE_RESET              /* 释放DMA2D外设的复位 */
#define __DMA2D_CLK_SLEEP_ENABLE       __HAL_RCC_DMA2D_CLK_SLEEP_ENABLE           /* 在睡眠模式下使能DMA2D时钟 */
#define __DMA2D_CLK_SLEEP_DISABLE      __HAL_RCC_DMA2D_CLK_SLEEP_DISABLE          /* 在睡眠模式下禁用DMA2D时钟 */
/* 为向后兼容而维护的别名定义 */
#define __HAL_RCC_OTGFS_FORCE_RESET    __HAL_RCC_USB_OTG_FS_FORCE_RESET    // 别名：强制复位 OTG FS（USB On-The-Go Full Speed）
#define __HAL_RCC_OTGFS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET  // 别名：释放复位 OTG FS（USB On-The-Go Full Speed）

#define __ADC12_CLK_ENABLE          __HAL_RCC_ADC12_CLK_ENABLE            // 别名：使能 ADC12 时钟
#define __ADC12_CLK_DISABLE         __HAL_RCC_ADC12_CLK_DISABLE           // 别名：禁用 ADC12 时钟
#define __ADC34_CLK_ENABLE          __HAL_RCC_ADC34_CLK_ENABLE            // 别名：使能 ADC34 时钟
#define __ADC34_CLK_DISABLE         __HAL_RCC_ADC34_CLK_DISABLE           // 别名：禁用 ADC34 时钟
#define __DAC2_CLK_ENABLE           __HAL_RCC_DAC2_CLK_ENABLE             // 别名：使能 DAC2 时钟
#define __DAC2_CLK_DISABLE          __HAL_RCC_DAC2_CLK_DISABLE            // 别名：禁用 DAC2 时钟
#define __TIM18_CLK_ENABLE          __HAL_RCC_TIM18_CLK_ENABLE            // 别名：使能 TIM18 时钟
#define __TIM18_CLK_DISABLE         __HAL_RCC_TIM18_CLK_DISABLE           // 别名：禁用 TIM18 时钟
#define __TIM19_CLK_ENABLE          __HAL_RCC_TIM19_CLK_ENABLE            // 别名：使能 TIM19 时钟
#define __TIM19_CLK_DISABLE         __HAL_RCC_TIM19_CLK_DISABLE           // 别名：禁用 TIM19 时钟
#define __TIM20_CLK_ENABLE          __HAL_RCC_TIM20_CLK_ENABLE            // 别名：使能 TIM20 时钟
#define __TIM20_CLK_DISABLE         __HAL_RCC_TIM20_CLK_DISABLE           // 别名：禁用 TIM20 时钟
#define __HRTIM1_CLK_ENABLE         __HAL_RCC_HRTIM1_CLK_ENABLE           // 别名：使能 HRTIM1（高分辨率定时器1）时钟
#define __HRTIM1_CLK_DISABLE        __HAL_RCC_HRTIM1_CLK_DISABLE          // 别名：禁用 HRTIM1（高分辨率定时器1）时钟
#define __SDADC1_CLK_ENABLE         __HAL_RCC_SDADC1_CLK_ENABLE           // 别名：使能 SDADC1（Sigma-Delta ADC1）时钟
#define __SDADC2_CLK_ENABLE         __HAL_RCC_SDADC2_CLK_ENABLE           // 别名：使能 SDADC2（Sigma-Delta ADC2）时钟
#define __SDADC3_CLK_ENABLE         __HAL_RCC_SDADC3_CLK_ENABLE           // 别名：使能 SDADC3（Sigma-Delta ADC3）时钟
#define __SDADC1_CLK_DISABLE        __HAL_RCC_SDADC1_CLK_DISABLE          // 别名：禁用 SDADC1（Sigma-Delta ADC1）时钟
#define __SDADC2_CLK_DISABLE        __HAL_RCC_SDADC2_CLK_DISABLE          // 别名：禁用 SDADC2（Sigma-Delta ADC2）时钟
#define __SDADC3_CLK_DISABLE        __HAL_RCC_SDADC3_CLK_DISABLE          // 别名：禁用 SDADC3（Sigma-Delta ADC3）时钟

#define __ADC12_FORCE_RESET         __HAL_RCC_ADC12_FORCE_RESET           // 别名：强制复位 ADC12
#define __ADC12_RELEASE_RESET       __HAL_RCC_ADC12_RELEASE_RESET         // 别名：释放复位 ADC12
#define __ADC34_FORCE_RESET         __HAL_RCC_ADC34_FORCE_RESET           // 别名：强制复位 ADC34
#define __ADC34_RELEASE_RESET       __HAL_RCC_ADC34_RELEASE_RESET         // 别名：释放复位 ADC34
#define __DAC2_FORCE_RESET          __HAL_RCC_DAC2_FORCE_RESET            // 别名：强制复位 DAC2
#define __DAC2_RELEASE_RESET        __HAL_RCC_DAC2_RELEASE_RESET          // 别名：释放复位 DAC2
#define __TIM18_FORCE_RESET         __HAL_RCC_TIM18_FORCE_RESET           // 别名：强制复位 TIM18
#define __TIM18_RELEASE_RESET       __HAL_RCC_TIM18_RELEASE_RESET         // 别名：释放复位 TIM18
#define __TIM19_FORCE_RESET         __HAL_RCC_TIM19_FORCE_RESET           // 别名：强制复位 TIM19
#define __TIM19_RELEASE_RESET       __HAL_RCC_TIM19_RELEASE_RESET         // 别名：释放复位 TIM19
#define __TIM20_FORCE_RESET         __HAL_RCC_TIM20_FORCE_RESET           // 别名：强制复位 TIM20
#define __TIM20_RELEASE_RESET       __HAL_RCC_TIM20_RELEASE_RESET         // 别名：释放复位 TIM20
#define __HRTIM1_FORCE_RESET        __HAL_RCC_HRTIM1_FORCE_RESET          // 别名：强制复位 HRTIM1（高分辨率定时器1）
#define __HRTIM1_RELEASE_RESET      __HAL_RCC_HRTIM1_RELEASE_RESET        // 别名：释放复位 HRTIM1（高分辨率定时器1）
#define __SDADC1_FORCE_RESET        __HAL_RCC_SDADC1_FORCE_RESET          // 别名：强制复位 SDADC1（Sigma-Delta ADC1）
#define __SDADC2_FORCE_RESET        __HAL_RCC_SDADC2_FORCE_RESET          // 别名：强制复位 SDADC2（Sigma-Delta ADC2）
#define __SDADC3_FORCE_RESET        __HAL_RCC_SDADC3_FORCE_RESET          // 别名：强制复位 SDADC3（Sigma-Delta ADC3）
#define __SDADC1_RELEASE_RESET      __HAL_RCC_SDADC1_RELEASE_RESET        // 别名：释放复位 SDADC1（Sigma-Delta ADC1）
#define __SDADC2_RELEASE_RESET      __HAL_RCC_SDADC2_RELEASE_RESET        // 别名：释放复位 SDADC2（Sigma-Delta ADC2）
#define __SDADC3_RELEASE_RESET      __HAL_RCC_SDADC3_RELEASE_RESET        // 别名：释放复位 SDADC3（Sigma-Delta ADC3）
#define __ADC1_IS_CLK_ENABLED       __HAL_RCC_ADC1_IS_CLK_ENABLED  /* 宏定义：检查ADC1外设时钟是否使能 */
#define __ADC1_IS_CLK_DISABLED      __HAL_RCC_ADC1_IS_CLK_DISABLED /* 宏定义：检查ADC1外设时钟是否禁用 */
#define __ADC12_IS_CLK_ENABLED      __HAL_RCC_ADC12_IS_CLK_ENABLED /* 宏定义：检查ADC1和ADC2外设时钟是否使能 */
#define __ADC12_IS_CLK_DISABLED     __HAL_RCC_ADC12_IS_CLK_DISABLED /* 宏定义：检查ADC1和ADC2外设时钟是否禁用 */
#define __ADC34_IS_CLK_ENABLED      __HAL_RCC_ADC34_IS_CLK_ENABLED /* 宏定义：检查ADC3和ADC4外设时钟是否使能 */
#define __ADC34_IS_CLK_DISABLED     __HAL_RCC_ADC34_IS_CLK_DISABLED /* 宏定义：检查ADC3和ADC4外设时钟是否禁用 */
#define __CEC_IS_CLK_ENABLED        __HAL_RCC_CEC_IS_CLK_ENABLED   /* 宏定义：检查CEC（消费电子控制）外设时钟是否使能 */
#define __CEC_IS_CLK_DISABLED       __HAL_RCC_CEC_IS_CLK_DISABLED  /* 宏定义：检查CEC（消费电子控制）外设时钟是否禁用 */
#define __CRC_IS_CLK_ENABLED        __HAL_RCC_CRC_IS_CLK_ENABLED   /* 宏定义：检查CRC（循环冗余校验）外设时钟是否使能 */
#define __CRC_IS_CLK_DISABLED       __HAL_RCC_CRC_IS_CLK_DISABLED  /* 宏定义：检查CRC（循环冗余校验）外设时钟是否禁用 */
#define __DAC1_IS_CLK_ENABLED       __HAL_RCC_DAC1_IS_CLK_ENABLED  /* 宏定义：检查DAC1（数模转换器1）外设时钟是否使能 */
#define __DAC1_IS_CLK_DISABLED      __HAL_RCC_DAC1_IS_CLK_DISABLED /* 宏定义：检查DAC1（数模转换器1）外设时钟是否禁用 */
#define __DAC2_IS_CLK_ENABLED       __HAL_RCC_DAC2_IS_CLK_ENABLED  /* 宏定义：检查DAC2（数模转换器2）外设时钟是否使能 */
#define __DAC2_IS_CLK_DISABLED      __HAL_RCC_DAC2_IS_CLK_DISABLED /* 宏定义：检查DAC2（数模转换器2）外设时钟是否禁用 */
#define __DMA1_IS_CLK_ENABLED       __HAL_RCC_DMA1_IS_CLK_ENABLED  /* 宏定义：检查DMA1（直接内存访问控制器1）外设时钟是否使能 */
#define __DMA1_IS_CLK_DISABLED      __HAL_RCC_DMA1_IS_CLK_DISABLED /* 宏定义：检查DMA1（直接内存访问控制器1）外设时钟是否禁用 */
#define __DMA2_IS_CLK_ENABLED       __HAL_RCC_DMA2_IS_CLK_ENABLED  /* 宏定义：检查DMA2（直接内存访问控制器2）外设时钟是否使能 */
#define __DMA2_IS_CLK_DISABLED      __HAL_RCC_DMA2_IS_CLK_DISABLED /* 宏定义：检查DMA2（直接内存访问控制器2）外设时钟是否禁用 */
#define __FLITF_IS_CLK_ENABLED      __HAL_RCC_FLITF_IS_CLK_ENABLED /* 宏定义：检查FLITF（Flash接口）时钟是否使能 */
#define __FLITF_IS_CLK_DISABLED     __HAL_RCC_FLITF_IS_CLK_DISABLED /* 宏定义：检查FLITF（Flash接口）时钟是否禁用 */
#define __FMC_IS_CLK_ENABLED        __HAL_RCC_FMC_IS_CLK_ENABLED   /* 宏定义：检查FMC（灵活内存控制器）时钟是否使能 */
#define __FMC_IS_CLK_DISABLED       __HAL_RCC_FMC_IS_CLK_DISABLED  /* 宏定义：检查FMC（灵活内存控制器）时钟是否禁用 */
#define __GPIOA_IS_CLK_ENABLED      __HAL_RCC_GPIOA_IS_CLK_ENABLED /* 宏定义：检查GPIOA端口时钟是否使能 */
#define __GPIOA_IS_CLK_DISABLED     __HAL_RCC_GPIOA_IS_CLK_DISABLED /* 宏定义：检查GPIOA端口时钟是否禁用 */
#define __GPIOB_IS_CLK_ENABLED      __HAL_RCC_GPIOB_IS_CLK_ENABLED /* 宏定义：检查GPIOB端口时钟是否使能 */
#define __GPIOB_IS_CLK_DISABLED     __HAL_RCC_GPIOB_IS_CLK_DISABLED /* 宏定义：检查GPIOB端口时钟是否禁用 */
#define __GPIOC_IS_CLK_ENABLED      __HAL_RCC_GPIOC_IS_CLK_ENABLED /* 宏定义：检查GPIOC端口时钟是否使能 */
#define __GPIOC_IS_CLK_DISABLED     __HAL_RCC_GPIOC_IS_CLK_DISABLED /* 宏定义：检查GPIOC端口时钟是否禁用 */
#define __GPIOD_IS_CLK_ENABLED      __HAL_RCC_GPIOD_IS_CLK_ENABLED /* 宏定义：检查GPIOD端口时钟是否使能 */
#define __GPIOD_IS_CLK_DISABLED     __HAL_RCC_GPIOD_IS_CLK_DISABLED /* 宏定义：检查GPIOD端口时钟是否禁用 */
#define __GPIOE_IS_CLK_ENABLED      __HAL_RCC_GPIOE_IS_CLK_ENABLED /* 宏定义：检查GPIOE端口时钟是否使能 */
#define __GPIOE_IS_CLK_DISABLED     __HAL_RCC_GPIOE_IS_CLK_DISABLED /* 宏定义：检查GPIOE端口时钟是否禁用 */
#define __GPIOF_IS_CLK_ENABLED      __HAL_RCC_GPIOF_IS_CLK_ENABLED /* 宏定义：检查GPIOF端口时钟是否使能 */
#define __GPIOF_IS_CLK_DISABLED     __HAL_RCC_GPIOF_IS_CLK_DISABLED /* 宏定义：检查GPIOF端口时钟是否禁用 */
#define __GPIOG_IS_CLK_ENABLED      __HAL_RCC_GPIOG_IS_CLK_ENABLED /* 宏定义：检查GPIOG端口时钟是否使能 */
#define __GPIOG_IS_CLK_DISABLED     __HAL_RCC_GPIOG_IS_CLK_DISABLED /* 宏定义：检查GPIOG端口时钟是否禁用 */
#define __GPIOH_IS_CLK_ENABLED      __HAL_RCC_GPIOH_IS_CLK_ENABLED /* 宏定义：检查GPIOH端口时钟是否使能 */
#define __GPIOH_IS_CLK_DISABLED     __HAL_RCC_GPIOH_IS_CLK_DISABLED /* 宏定义：检查GPIOH端口时钟是否禁用 */
#define __HRTIM1_IS_CLK_ENABLED     __HAL_RCC_HRTIM1_IS_CLK_ENABLED /* 宏定义：检查HRTIM1（高分辨率定时器1）外设时钟是否使能 */
#define __HRTIM1_IS_CLK_DISABLED    __HAL_RCC_HRTIM1_IS_CLK_DISABLED /* 宏定义：检查HRTIM1（高分辨率定时器1）外设时钟是否禁用 */
#define __I2C1_IS_CLK_ENABLED       __HAL_RCC_I2C1_IS_CLK_ENABLED  /* 宏定义：检查I2C1外设时钟是否使能 */
#define __I2C1_IS_CLK_DISABLED      __HAL_RCC_I2C1_IS_CLK_DISABLED /* 宏定义：检查I2C1外设时钟是否禁用 */
#define __I2C2_IS_CLK_ENABLED       __HAL_RCC_I2C2_IS_CLK_ENABLED  /* 宏定义：检查I2C2外设时钟是否使能 */
#define __I2C2_IS_CLK_DISABLED      __HAL_RCC_I2C2_IS_CLK_DISABLED /* 宏定义：检查I2C2外设时钟是否禁用 */
#define __I2C3_IS_CLK_ENABLED       __HAL_RCC_I2C3_IS_CLK_ENABLED  /* 宏定义：检查I2C3外设时钟是否使能 */
#define __I2C3_IS_CLK_DISABLED      __HAL_RCC_I2C3_IS_CLK_DISABLED /* 宏定义：检查I2C3外设时钟是否禁用 */
#define __PWR_IS_CLK_ENABLED        __HAL_RCC_PWR_IS_CLK_ENABLED   /* 宏定义：检查PWR（电源控制）外设时钟是否使能 */
#define __PWR_IS_CLK_DISABLED       __HAL_RCC_PWR_IS_CLK_DISABLED  /* 宏定义：检查PWR（电源控制）外设时钟是否禁用 */
#define __SYSCFG_IS_CLK_ENABLED     __HAL_RCC_SYSCFG_IS_CLK_ENABLED /* 宏定义：检查SYSCFG（系统配置）时钟是否使能 */
#define __SYSCFG_IS_CLK_DISABLED    __HAL_RCC_SYSCFG_IS_CLK_DISABLED /* 宏定义：检查SYSCFG（系统配置）时钟是否禁用 */
#define __SPI1_IS_CLK_ENABLED       __HAL_RCC_SPI1_IS_CLK_ENABLED  /* 宏定义：检查SPI1外设时钟是否使能 */
#define __SPI1_IS_CLK_DISABLED      __HAL_RCC_SPI1_IS_CLK_DISABLED /* 宏定义：检查SPI1外设时钟是否禁用 */
#define __SPI2_IS_CLK_ENABLED       __HAL_RCC_SPI2_IS_CLK_ENABLED  /* 宏定义：检查SPI2外设时钟是否使能 */
#define __SPI2_IS_CLK_DISABLED      __HAL_RCC_SPI2_IS_CLK_DISABLED /* 宏定义：检查SPI2外设时钟是否禁用 */
#define __SPI3_IS_CLK_ENABLED       __HAL_RCC_SPI3_IS_CLK_ENABLED  /* 宏定义：检查SPI3外设时钟是否使能 */
#define __SPI3_IS_CLK_DISABLED      __HAL_RCC_SPI3_IS_CLK_DISABLED /* 宏定义：检查SPI3外设时钟是否禁用 */
#define __SPI4_IS_CLK_ENABLED       __HAL_RCC_SPI4_IS_CLK_ENABLED  /* 宏定义：检查SPI4外设时钟是否使能 */
#define __SPI4_IS_CLK_DISABLED      __HAL_RCC_SPI4_IS_CLK_DISABLED /* 宏定义：检查SPI4外设时钟是否禁用 */
#define __SDADC1_IS_CLK_ENABLED     __HAL_RCC_SDADC1_IS_CLK_ENABLED /* 宏定义：检查SDADC1（Sigma-Delta ADC1）外设时钟是否使能 */
#define __SDADC1_IS_CLK_DISABLED    __HAL_RCC_SDADC1_IS_CLK_DISABLED /* 宏定义：检查SDADC1（Sigma-Delta ADC1）外设时钟是否禁用 */
#define __SDADC2_IS_CLK_ENABLED     __HAL_RCC_SDADC2_IS_CLK_ENABLED /* 宏定义：检查SDADC2（Sigma-Delta ADC2）外设时钟是否使能 */
#define __SDADC2_IS_CLK_DISABLED    __HAL_RCC_SDADC2_IS_CLK_DISABLED /* 宏定义：检查SDADC2（Sigma-Delta ADC2）外设时钟是否禁用 */
#define __SDADC3_IS_CLK_ENABLED     __HAL_RCC_SDADC3_IS_CLK_ENABLED /* 宏定义：检查SDADC3（Sigma-Delta ADC3）外设时钟是否使能 */
#define __SDADC3_IS_CLK_DISABLED    __HAL_RCC_SDADC3_IS_CLK_DISABLED /* 宏定义：检查SDADC3（Sigma-Delta ADC3）外设时钟是否禁用 */
#define __SRAM_IS_CLK_ENABLED       __HAL_RCC_SRAM_IS_CLK_ENABLED  /* 宏定义：检查SRAM（静态随机存取存储器）时钟是否使能 */
#define __SRAM_IS_CLK_DISABLED      __HAL_RCC_SRAM_IS_CLK_DISABLED /* 宏定义：检查SRAM（静态随机存取存储器）时钟是否禁用 */
#define __TIM1_IS_CLK_ENABLED       __HAL_RCC_TIM1_IS_CLK_ENABLED  /* 宏定义：检查TIM1（高级控制定时器1）外设时钟是否使能 */
#define __TIM1_IS_CLK_DISABLED      __HAL_RCC_TIM1_IS_CLK_DISABLED /* 宏定义：检查TIM1（高级控制定时器1）外设时钟是否禁用 */
#define __TIM2_IS_CLK_ENABLED       __HAL_RCC_TIM2_IS_CLK_ENABLED  /* 宏定义：检查TIM2（通用定时器2）外设时钟是否使能 */
#define __TIM2_IS_CLK_DISABLED      __HAL_RCC_TIM2_IS_CLK_DISABLED /* 宏定义：检查TIM2（通用定时器2）外设时钟是否禁用 */
#define __TIM3_IS_CLK_ENABLED       __HAL_RCC_TIM3_IS_CLK_ENABLED  /* 宏定义：检查TIM3（通用定时器3）外设时钟是否使能 */
#define __TIM3_IS_CLK_DISABLED      __HAL_RCC_TIM3_IS_CLK_DISABLED /* 宏定义：检查TIM3（通用定时器3）外设时钟是否禁用 */
#define __TIM4_IS_CLK_ENABLED       __HAL_RCC_TIM4_IS_CLK_ENABLED  /* 宏定义：检查TIM4（通用定时器4）外设时钟是否使能 */
#define __TIM4_IS_CLK_DISABLED      __HAL_RCC_TIM4_IS_CLK_DISABLED /* 宏定义：检查TIM4（通用定时器4）外设时钟是否禁用 */
#define __TIM5_IS_CLK_ENABLED       __HAL_RCC_TIM5_IS_CLK_ENABLED  /* 宏定义：检查TIM5（通用定时器5）外设时钟是否使能 */
#define __TIM5_IS_CLK_DISABLED      __HAL_RCC_TIM5_IS_CLK_DISABLED /* 宏定义：检查TIM5（通用定时器5）外设时钟是否禁用 */
#define __TIM6_IS_CLK_ENABLED       __HAL_RCC_TIM6_IS_CLK_ENABLED  /* 宏定义：检查TIM6（基本定时器6）外设时钟是否使能 */
#define __TIM6_IS_CLK_DISABLED      __HAL_RCC_TIM6_IS_CLK_DISABLED /* 宏定义：检查TIM6（基本定时器6）外设时钟是否禁用 */
#define __TIM7_IS_CLK_ENABLED       __HAL_RCC_TIM7_IS_CLK_ENABLED  /* 宏定义：检查TIM7（基本定时器7）外设时钟是否使能 */
#define __TIM7_IS_CLK_DISABLED      __HAL_RCC_TIM7_IS_CLK_DISABLED /* 宏定义：检查TIM7（基本定时器7）外设时钟是否禁用 */
#define __TIM8_IS_CLK_ENABLED       __HAL_RCC_TIM8_IS_CLK_ENABLED  /* 宏定义：检查TIM8（高级控制定时器8）外设时钟是否使能 */
#define __TIM8_IS_CLK_DISABLED      __HAL_RCC_TIM8_IS_CLK_DISABLED /* 宏定义：检查TIM8（高级控制定时器8）外设时钟是否禁用 */
#define __TIM12_IS_CLK_ENABLED      __HAL_RCC_TIM12_IS_CLK_ENABLED /* 宏定义：检查TIM12（通用定时器12）外设时钟是否使能 */
#define __TIM12_IS_CLK_DISABLED     __HAL_RCC_TIM12_IS_CLK_DISABLED /* 宏定义：检查TIM12（通用定时器12）外设时钟是否禁用 */
#define __TIM13_IS_CLK_ENABLED      __HAL_RCC_TIM13_IS_CLK_ENABLED /* 宏定义：检查TIM13（通用定时器13）外设时钟是否使能 */
#define __TIM13_IS_CLK_DISABLED     __HAL_RCC_TIM13_IS_CLK_DISABLED /* 宏定义：检查TIM13（通用定时器13）外设时钟是否禁用 */
#define __TIM14_IS_CLK_ENABLED      __HAL_RCC_TIM14_IS_CLK_ENABLED /* 宏定义：检查TIM14（通用定时器14）外设时钟是否使能 */
#define __TIM14_IS_CLK_DISABLED     __HAL_RCC_TIM14_IS_CLK_DISABLED /* 宏定义：检查TIM14（通用定时器14）外设时钟是否禁用 */
#define __TIM15_IS_CLK_ENABLED      __HAL_RCC_TIM15_IS_CLK_ENABLED /* 宏定义：检查TIM15（通用定时器15）外设时钟是否使能 */
#define __TIM15_IS_CLK_DISABLED     __HAL_RCC_TIM15_IS_CLK_DISABLED /* 宏定义：检查TIM15（通用定时器15）外设时钟是否禁用 */
#define __TIM16_IS_CLK_ENABLED      __HAL_RCC_TIM16_IS_CLK_ENABLED /* 宏定义：检查TIM16（通用定时器16）外设时钟是否使能 */
#define __TIM16_IS_CLK_DISABLED     __HAL_RCC_TIM16_IS_CLK_DISABLED /* 宏定义：检查TIM16（通用定时器16）外设时钟是否禁用 */
#define __TIM17_IS_CLK_ENABLED      __HAL_RCC_TIM17_IS_CLK_ENABLED /* 宏定义：检查TIM17（通用定时器17）外设时钟是否使能 */
#define __TIM17_IS_CLK_DISABLED     __HAL_RCC_TIM17_IS_CLK_DISABLED /* 宏定义：检查TIM17（通用定时器17）外设时钟是否禁用 */
#define __TIM18_IS_CLK_ENABLED      __HAL_RCC_TIM18_IS_CLK_ENABLED /* 宏定义：检查TIM18（通用定时器18）外设时钟是否使能 */
#define __TIM18_IS_CLK_DISABLED     __HAL_RCC_TIM18_IS_CLK_DISABLED /* 宏定义：检查TIM18（通用定时器18）外设时钟是否禁用 */
#define __TIM19_IS_CLK_ENABLED      __HAL_RCC_TIM19_IS_CLK_ENABLED /* 宏定义：检查TIM19（通用定时器19）外设时钟是否使能 */
#define __TIM19_IS_CLK_DISABLED     __HAL_RCC_TIM19_IS_CLK_DISABLED /* 宏定义：检查TIM19（通用定时器19）外设时钟是否禁用 */
#define __TIM20_IS_CLK_ENABLED      __HAL_RCC_TIM20_IS_CLK_ENABLED /* 宏定义：检查TIM20（高级控制定时器20）外设时钟是否使能 */
#define __TIM20_IS_CLK_DISABLED     __HAL_RCC_TIM20_IS_CLK_DISABLED /* 宏定义：检查TIM20（高级控制定时器20）外设时钟是否禁用 */
#define __TSC_IS_CLK_ENABLED        __HAL_RCC_TSC_IS_CLK_ENABLED   /* 宏定义：检查TSC（触摸感应控制器）外设时钟是否使能 */
#define __TSC_IS_CLK_DISABLED       __HAL_RCC_TSC_IS_CLK_DISABLED  /* 宏定义：检查TSC（触摸感应控制器）外设时钟是否禁用 */
#define __UART4_IS_CLK_ENABLED      __HAL_RCC_UART4_IS_CLK_ENABLED /* 宏定义：检查UART4外设时钟是否使能 */
#define __UART4_IS_CLK_DISABLED     __HAL_RCC_UART4_IS_CLK_DISABLED /* 宏定义：检查UART4外设时钟是否禁用 */
#define __UART5_IS_CLK_ENABLED      __HAL_RCC_UART5_IS_CLK_ENABLED /* 宏定义：检查UART5外设时钟是否使能 */
#define __UART5_IS_CLK_DISABLED     __HAL_RCC_UART5_IS_CLK_DISABLED /* 宏定义：检查UART5外设时钟是否禁用 */
#define __USART1_IS_CLK_ENABLED     __HAL_RCC_USART1_IS_CLK_ENABLED /* 宏定义：检查USART1外设时钟是否使能 */
#define __USART1_IS_CLK_DISABLED    __HAL_RCC_USART1_IS_CLK_DISABLED /* 宏定义：检查USART1外设时钟是否禁用 */
#define __USART2_IS_CLK_ENABLED     __HAL_RCC_USART2_IS_CLK_ENABLED /* 宏定义：检查USART2外设时钟是否使能 */
#define __USART2_IS_CLK_DISABLED    __HAL_RCC_USART2_IS_CLK_DISABLED /* 宏定义：检查USART2外设时钟是否禁用 */
#define __USART3_IS_CLK_ENABLED     __HAL_RCC_USART3_IS_CLK_ENABLED /* 宏定义：检查USART3外设时钟是否使能 */
#define __USART3_IS_CLK_DISABLED    __HAL_RCC_USART3_IS_CLK_DISABLED /* 宏定义：检查USART3外设时钟是否禁用 */
#define __USB_IS_CLK_ENABLED        __HAL_RCC_USB_IS_CLK_ENABLED   /* 宏定义：检查USB外设时钟是否使能 */
#define __USB_IS_CLK_DISABLED       __HAL_RCC_USB_IS_CLK_DISABLED  /* 宏定义：检查USB外设时钟是否禁用 */
#define __WWDG_IS_CLK_ENABLED       __HAL_RCC_WWDG_IS_CLK_ENABLED  /* 宏定义：检查WWDG（窗口看门狗）外设时钟是否使能 */
#define __WWDG_IS_CLK_DISABLED      __HAL_RCC_WWDG_IS_CLK_DISABLED /* 宏定义：检查WWDG（窗口看门狗）外设时钟是否禁用 */

#if defined(STM32L1) /* 条件编译：如果定义了STM32L1系列微控制器 */
#define __HAL_RCC_CRYP_CLK_DISABLE         __HAL_RCC_AES_CLK_DISABLE        /* 宏定义：将CRYP（加密）时钟禁用映射到AES时钟禁用（L1系列中两者可能相同） */
#define __HAL_RCC_CRYP_CLK_ENABLE          __HAL_RCC_AES_CLK_ENABLE         /* 宏定义：将CRYP（加密）时钟使能映射到AES时钟使能 */
#define __HAL_RCC_CRYP_CLK_SLEEP_DISABLE   __HAL_RCC_AES_CLK_SLEEP_DISABLE  /* 宏定义：将CRYP（加密）睡眠时钟禁用映射到AES睡眠时钟禁用 */
#define __HAL_RCC_CRYP_CLK_SLEEP_ENABLE    __HAL_RCC_AES_CLK_SLEEP_ENABLE   /* 宏定义：将CRYP（加密）睡眠时钟使能映射到AES睡眠时钟使能 */
#define __HAL_RCC_CRYP_FORCE_RESET         __HAL_RCC_AES_FORCE_RESET        /* 宏定义：将CRYP（加密）强制复位映射到AES强制复位 */
#define __HAL_RCC_CRYP_RELEASE_RESET       __HAL_RCC_AES_RELEASE_RESET      /* 宏定义：将CRYP（加密）释放复位映射到AES释放复位 */
#endif /* STM32L1 */ /* 条件编译结束 */

#if defined(STM32F4) /* 条件编译：如果定义了STM32F4系列微控制器 */
#define __HAL_RCC_SDMMC1_FORCE_RESET       __HAL_RCC_SDIO_FORCE_RESET       /* 宏定义：将SDMMC1（SD卡/MMC接口1）强制复位映射到SDIO强制复位（F4系列中两者可能相同） */
#define __HAL_RCC_SDMMC1_RELEASE_RESET     __HAL_RCC_SDIO_RELEASE_RESET     /* 宏定义：将SDMMC1释放复位映射到SDIO释放复位 */
#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE  __HAL_RCC_SDIO_CLK_SLEEP_ENABLE  /* 宏定义：将SDMMC1睡眠时钟使能映射到SDIO睡眠时钟使能 */
#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE __HAL_RCC_SDIO_CLK_SLEEP_DISABLE /* 宏定义：将SDMMC1睡眠时钟禁用映射到SDIO睡眠时钟禁用 */
#define __HAL_RCC_SDMMC1_CLK_ENABLE        __HAL_RCC_SDIO_CLK_ENABLE        /* 宏定义：将SDMMC1时钟使能映射到SDIO时钟使能 */
#define __HAL_RCC_SDMMC1_CLK_DISABLE       __HAL_RCC_SDIO_CLK_DISABLE       /* 宏定义：将SDMMC1时钟禁用映射到SDIO时钟禁用 */
#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED    __HAL_RCC_SDIO_IS_CLK_ENABLED    /* 宏定义：将检查SDMMC1时钟使能映射到检查SDIO时钟使能 */
#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED   __HAL_RCC_SDIO_IS_CLK_DISABLED   /* 宏定义：将检查SDMMC1时钟禁用映射到检查SDIO时钟禁用 */
#define Sdmmc1ClockSelection               SdioClockSelection               /* 宏定义：将SDMMC1时钟选择类型重命名为SDIO时钟选择类型 */
#define RCC_PERIPHCLK_SDMMC1               RCC_PERIPHCLK_SDIO               /* 宏定义：将SDMMC1外设时钟标识映射到SDIO外设时钟标识 */
#define RCC_SDMMC1CLKSOURCE_CLK48          RCC_SDIOCLKSOURCE_CK48           /* 宏定义：将SDMMC1时钟源CLK48映射到SDIO时钟源CK48 */
#define RCC_SDMMC1CLKSOURCE_SYSCLK         RCC_SDIOCLKSOURCE_SYSCLK         /* 宏定义：将SDMMC1时钟源SYSCLK映射到SDIO时钟源SYSCLK */
#define __HAL_RCC_SDMMC1_CONFIG            __HAL_RCC_SDIO_CONFIG            /* 宏定义：将SDMMC1配置宏映射到SDIO配置宏 */
#define __HAL_RCC_GET_SDMMC1_SOURCE        __HAL_RCC_GET_SDIO_SOURCE        /* 宏定义：将获取SDMMC1时钟源宏映射到获取SDIO时钟源宏 */
#endif /* 条件编译结束，这里缺少对应的 `#endif`，但根据要求不补充 */
#if defined(STM32F7) || defined(STM32L4)
#define __HAL_RCC_SDIO_FORCE_RESET         __HAL_RCC_SDMMC1_FORCE_RESET         // SDIO强制复位宏，映射到SDMMC1的强制复位
#define __HAL_RCC_SDIO_RELEASE_RESET       __HAL_RCC_SDMMC1_RELEASE_RESET       // SDIO释放复位宏，映射到SDMMC1的释放复位
#define __HAL_RCC_SDIO_CLK_SLEEP_ENABLE    __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE    // SDIO睡眠时钟使能宏，映射到SDMMC1的睡眠时钟使能
#define __HAL_RCC_SDIO_CLK_SLEEP_DISABLE   __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE   // SDIO睡眠时钟禁用宏，映射到SDMMC1的睡眠时钟禁用
#define __HAL_RCC_SDIO_CLK_ENABLE          __HAL_RCC_SDMMC1_CLK_ENABLE          // SDIO时钟使能宏，映射到SDMMC1的时钟使能
#define __HAL_RCC_SDIO_CLK_DISABLE         __HAL_RCC_SDMMC1_CLK_DISABLE         // SDIO时钟禁用宏，映射到SDMMC1的时钟禁用
#define __HAL_RCC_SDIO_IS_CLK_ENABLED      __HAL_RCC_SDMMC1_IS_CLK_ENABLED      // 检查SDIO时钟是否使能的宏，映射到SDMMC1的检查
#define __HAL_RCC_SDIO_IS_CLK_DISABLED     __HAL_RCC_SDMMC1_IS_CLK_DISABLED     // 检查SDIO时钟是否禁用的宏，映射到SDMMC1的检查
#define SdioClockSelection                 Sdmmc1ClockSelection                // SDIO时钟选择类型别名，映射到SDMMC1时钟选择
#define RCC_PERIPHCLK_SDIO                 RCC_PERIPHCLK_SDMMC1                // SDIO外设时钟宏，映射到SDMMC1外设时钟
#define __HAL_RCC_SDIO_CONFIG              __HAL_RCC_SDMMC1_CONFIG              // SDIO配置宏，映射到SDMMC1配置
#define __HAL_RCC_GET_SDIO_SOURCE          __HAL_RCC_GET_SDMMC1_SOURCE          // 获取SDIO时钟源宏，映射到获取SDMMC1时钟源
#endif

#if defined(STM32F7)
#define RCC_SDIOCLKSOURCE_CLK48             RCC_SDMMC1CLKSOURCE_CLK48           // SDIO时钟源为CLK48，映射到SDMMC1时钟源CLK48
#define RCC_SDIOCLKSOURCE_SYSCLK           RCC_SDMMC1CLKSOURCE_SYSCLK           // SDIO时钟源为SYSCLK，映射到SDMMC1时钟源SYSCLK
#endif

#if defined(STM32H7)
#define __HAL_RCC_USB_OTG_HS_CLK_ENABLE()              __HAL_RCC_USB1_OTG_HS_CLK_ENABLE()              // USB OTG高速时钟使能宏，映射到USB1 OTG高速时钟使能
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE()         __HAL_RCC_USB1_OTG_HS_ULPI_CLK_ENABLE()         // USB OTG高速ULPI时钟使能宏，映射到USB1 OTG高速ULPI时钟使能
#define __HAL_RCC_USB_OTG_HS_CLK_DISABLE()             __HAL_RCC_USB1_OTG_HS_CLK_DISABLE()             // USB OTG高速时钟禁用宏，映射到USB1 OTG高速时钟禁用
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE()        __HAL_RCC_USB1_OTG_HS_ULPI_CLK_DISABLE()        // USB OTG高速ULPI时钟禁用宏，映射到USB1 OTG高速ULPI时钟禁用
#define __HAL_RCC_USB_OTG_HS_FORCE_RESET()             __HAL_RCC_USB1_OTG_HS_FORCE_RESET()             // USB OTG高速强制复位宏，映射到USB1 OTG高速强制复位
#define __HAL_RCC_USB_OTG_HS_RELEASE_RESET()           __HAL_RCC_USB1_OTG_HS_RELEASE_RESET()           // USB OTG高速释放复位宏，映射到USB1 OTG高速释放复位
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE()        __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_ENABLE()        // USB OTG高速睡眠时钟使能宏，映射到USB1 OTG高速睡眠时钟使能
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE()   __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_ENABLE()   // USB OTG高速ULPI睡眠时钟使能宏，映射到USB1 OTG高速ULPI睡眠时钟使能
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE()       __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_DISABLE()       // USB OTG高速睡眠时钟禁用宏，映射到USB1 OTG高速睡眠时钟禁用
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE()  __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_DISABLE()  // USB OTG高速ULPI睡眠时钟禁用宏，映射到USB1 OTG高速ULPI睡眠时钟禁用

#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()             __HAL_RCC_USB2_OTG_FS_CLK_ENABLE()             // USB OTG全速时钟使能宏，映射到USB2 OTG全速时钟使能
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_ENABLE()        __HAL_RCC_USB2_OTG_FS_ULPI_CLK_ENABLE()        // USB OTG全速ULPI时钟使能宏，映射到USB2 OTG全速ULPI时钟使能
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()            __HAL_RCC_USB2_OTG_FS_CLK_DISABLE()            // USB OTG全速时钟禁用宏，映射到USB2 OTG全速时钟禁用
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_DISABLE()       __HAL_RCC_USB2_OTG_FS_ULPI_CLK_DISABLE()       // USB OTG全速ULPI时钟禁用宏，映射到USB2 OTG全速ULPI时钟禁用
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()            __HAL_RCC_USB2_OTG_FS_FORCE_RESET()            // USB OTG全速强制复位宏，映射到USB2 OTG全速强制复位
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()          __HAL_RCC_USB2_OTG_FS_RELEASE_RESET()          // USB OTG全速释放复位宏，映射到USB2 OTG全速释放复位
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()       __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_ENABLE()       // USB OTG全速睡眠时钟使能宏，映射到USB2 OTG全速睡眠时钟使能
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  // USB OTG全速ULPI睡眠时钟使能宏，映射到USB2 OTG全速ULPI睡眠时钟使能
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE()      __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_DISABLE()      // USB OTG全速睡眠时钟禁用宏，映射到USB2 OTG全速睡眠时钟禁用
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_DISABLE() __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_DISABLE() // USB OTG全速ULPI睡眠时钟禁用宏，映射到USB2 OTG全速ULPI睡眠时钟禁用
#endif

#define __HAL_RCC_I2SCLK            __HAL_RCC_I2S_CONFIG            // I2S时钟配置宏，映射到I2S配置宏
#define __HAL_RCC_I2SCLK_CONFIG     __HAL_RCC_I2S_CONFIG            // I2S时钟配置宏，映射到I2S配置宏

#define __RCC_PLLSRC                RCC_GET_PLL_OSCSOURCE           // 获取PLL振荡器源宏，映射到获取PLL振荡器源

#define IS_RCC_MSIRANGE             IS_RCC_MSI_CLOCK_RANGE          // 检查MSI时钟范围宏，映射到检查MSI时钟范围
#define IS_RCC_RTCCLK_SOURCE        IS_RCC_RTCCLKSOURCE            // 检查RTC时钟源宏，映射到检查RTC时钟源
#define IS_RCC_SYSCLK_DIV           IS_RCC_HCLK                    // 检查系统时钟分频宏，映射到检查HCLK分频
#define IS_RCC_HCLK_DIV             IS_RCC_PCLK                    // 检查HCLK分频宏，映射到检查PCLK分频
#define IS_RCC_PERIPHCLK            IS_RCC_PERIPHCLOCK             // 检查外设时钟宏，映射到检查外设时钟

#define RCC_IT_HSI14                RCC_IT_HSI14RDY                // HSI14就绪中断宏，映射到HSI14就绪中断

#define RCC_IT_CSSLSE               RCC_IT_LSECSS                  // LSE时钟安全系统中断宏，映射到LSE CSS中断
#define RCC_IT_CSSHSE               RCC_IT_CSS                     // HSE时钟安全系统中断宏，映射到CSS中断

#define RCC_PLLMUL_3                RCC_PLL_MUL3                   // PLL乘法因子3，映射到PLL乘法因子3
#define RCC_PLLMUL_4                RCC_PLL_MUL4                   // PLL乘法因子4，映射到PLL乘法因子4
#define RCC_PLLMUL_6                RCC_PLL_MUL6                   // PLL乘法因子6，映射到PLL乘法因子6
#define RCC_PLLMUL_8                RCC_PLL_MUL8                   // PLL乘法因子8，映射到PLL乘法因子8
#define RCC_PLLMUL_12               RCC_PLL_MUL12                  // PLL乘法因子12，映射到PLL乘法因子12
#define RCC_PLLMUL_16               RCC_PLL_MUL16                  // PLL乘法因子16，映射到PLL乘法因子16
#define RCC_PLLMUL_24               RCC_PLL_MUL24                  // PLL乘法因子24，映射到PLL乘法因子24
#define RCC_PLLMUL_32               RCC_PLL_MUL32                  // PLL乘法因子32，映射到PLL乘法因子32
#define RCC_PLLMUL_48               RCC_PLL_MUL48                  // PLL乘法因子48，映射到PLL乘法因子48

#define RCC_PLLDIV_2                RCC_PLL_DIV2                   // PLL除法因子2，映射到PLL除法因子2
#define RCC_PLLDIV_3                RCC_PLL_DIV3                   // PLL除法因子3，映射到PLL除法因子3
#define RCC_PLLDIV_4                RCC_PLL_DIV4                   // PLL除法因子4，映射到PLL除法因子4

#define IS_RCC_MCOSOURCE            IS_RCC_MCO1SOURCE              // 检查MCO时钟源宏，映射到检查MCO1时钟源
#define __HAL_RCC_MCO_CONFIG        __HAL_RCC_MCO1_CONFIG          // MCO配置宏，映射到MCO1配置
#define RCC_MCO_NODIV               RCC_MCODIV_1                   // MCO无分频，映射到MCO分频1
#define RCC_MCO_DIV1                RCC_MCODIV_1                   // MCO分频1，映射到MCO分频1
#define RCC_MCO_DIV2                RCC_MCODIV_2                   // MCO分频2，映射到MCO分频2
#define RCC_MCO_DIV4                RCC_MCODIV_4                   // MCO分频4，映射到MCO分频4
#define RCC_MCO_DIV8                RCC_MCODIV_8                   // MCO分频8，映射到MCO分频8
#define RCC_MCO_DIV16               RCC_MCODIV_16                  // MCO分频16，映射到MCO分频16
#define RCC_MCO_DIV32               RCC_MCODIV_32                  // MCO分频32，映射到MCO分频32
#define RCC_MCO_DIV64               RCC_MCODIV_64                  // MCO分频64，映射到MCO分频64
#define RCC_MCO_DIV128              RCC_MCODIV_128                 // MCO分频128，映射到MCO分频128
#define RCC_MCOSOURCE_NONE          RCC_MCO1SOURCE_NOCLOCK        // MCO时钟源为无时钟，映射到MCO1无时钟源
#define RCC_MCOSOURCE_LSI           RCC_MCO1SOURCE_LSI            // MCO时钟源为LSI，映射到MCO1 LSI时钟源
#define RCC_MCOSOURCE_LSE           RCC_MCO1SOURCE_LSE            // MCO时钟源为LSE，映射到MCO1 LSE时钟源
#define RCC_MCOSOURCE_SYSCLK        RCC_MCO1SOURCE_SYSCLK         // MCO时钟源为系统时钟，映射到MCO1系统时钟源
#define RCC_MCOSOURCE_HSI           RCC_MCO1SOURCE_HSI            // MCO时钟源为HSI，映射到MCO1 HSI时钟源
#define RCC_MCOSOURCE_HSI14         RCC_MCO1SOURCE_HSI14          // MCO时钟源为HSI14，映射到MCO1 HSI14时钟源
#define RCC_MCOSOURCE_HSI48         RCC_MCO1SOURCE_HSI48          // MCO时钟源为HSI48，映射到MCO1 HSI48时钟源
#define RCC_MCOSOURCE_HSE           RCC_MCO1SOURCE_HSE            // MCO时钟源为HSE，映射到MCO1 HSE时钟源
#define RCC_MCOSOURCE_PLLCLK_DIV1   RCC_MCO1SOURCE_PLLCLK         // MCO时钟源为PLL时钟（不分频），映射到MCO1 PLL时钟源
#define RCC_MCOSOURCE_PLLCLK_NODIV  RCC_MCO1SOURCE_PLLCLK         // MCO时钟源为PLL时钟（不分频），映射到MCO1 PLL时钟源
#define RCC_MCOSOURCE_PLLCLK_DIV2   RCC_MCO1SOURCE_PLLCLK_DIV2    // MCO时钟源为PLL时钟2分频，映射到MCO1 PLL时钟2分频源

#if defined(STM32U0)
#define RCC_SYSCLKSOURCE_STATUS_PLLR   RCC_SYSCLKSOURCE_STATUS_PLLCLK   // 系统时钟源状态为PLLR，映射到PLL时钟
#endif

#if defined(STM32L4) || defined(STM32WB) || defined(STM32G0) || defined(STM32G4) || defined(STM32L5) || \
    defined(STM32WL) || defined(STM32C0) || defined(STM32H7RS) || defined(STM32U0)
#define RCC_RTCCLKSOURCE_NO_CLK     RCC_RTCCLKSOURCE_NONE           // RTC时钟源为无时钟，映射到RTC时钟源无
#else
#define RCC_RTCCLKSOURCE_NONE       RCC_RTCCLKSOURCE_NO_CLK         // RTC时钟源为无，映射到RTC时钟源无时钟
#endif

#define RCC_USBCLK_PLLSAI1          RCC_USBCLKSOURCE_PLLSAI1        // USB时钟源为PLLSAI1
#define RCC_USBCLK_PLL              RCC_USBCLKSOURCE_PLL            // USB时钟源为PLL
#define RCC_USBCLK_MSI              RCC_USBCLKSOURCE_MSI            // USB时钟源为MSI
#define RCC_USBCLKSOURCE_PLLCLK     RCC_USBCLKSOURCE_PLL            // USB时钟源为PLL时钟，映射到USB时钟源PLL
#define RCC_USBPLLCLK_DIV1          RCC_USBCLKSOURCE_PLL            // USB PLL时钟不分频，映射到USB时钟源PLL
#define RCC_USBPLLCLK_DIV1_5        RCC_USBCLKSOURCE_PLL_DIV1_5     // USB PLL时钟1.5分频，映射到USB时钟源PLL 1.5分频
#define RCC_USBPLLCLK_DIV2          RCC_USBCLKSOURCE_PLL_DIV2       // USB PLL时钟2分频，映射到USB时钟源PLL 2分频
#define RCC_USBPLLCLK_DIV3          RCC_USBCLKSOURCE_PLL_DIV3       // USB PLL时钟3分频，映射到USB时钟源PLL 3分频

#define HSION_BitNumber        RCC_HSION_BIT_NUMBER                 // HSI使能位在寄存器中的位编号
#define HSION_BITNUMBER        RCC_HSION_BIT_NUMBER                 // HSI使能位在寄存器中的位编号
#define HSEON_BitNumber        RCC_HSEON_BIT_NUMBER                 // HSE使能位在寄存器中的位编号
#define HSEON_BITNUMBER        RCC_HSEON_BIT_NUMBER                 // HSE使能位在寄存器中的位编号
#define MSION_BITNUMBER        RCC_MSION_BIT_NUMBER                 // MSI使能位在寄存器中的位编号
#define CSSON_BitNumber        RCC_CSSON_BIT_NUMBER                 // CSS使能位在寄存器中的位编号
#define CSSON_BITNUMBER        RCC_CSSON_BIT_NUMBER                 // CSS使能位在寄存器中的位编号
#define PLLON_BitNumber        RCC_PLLON_BIT_NUMBER                 // PLL使能位在寄存器中的位编号
#define PLLON_BITNUMBER        RCC_PLLON_BIT_NUMBER                 // PLL使能位在寄存器中的位编号
#define PLLI2SON_BitNumber     RCC_PLLI2SON_BIT_NUMBER              // PLLI2S使能位在寄存器中的位编号
#define I2SSRC_BitNumber       RCC_I2SSRC_BIT_NUMBER                // I2S时钟源位在寄存器中的位编号
#define RTCEN_BitNumber        RCC_RTCEN_BIT_NUMBER                 // RTC使能位在寄存器中的位编号
#define RTCEN_BITNUMBER        RCC_RTCEN_BIT_NUMBER                 // RTC使能位在寄存器中的位编号
#define BDRST_BitNumber        RCC_BDRST_BIT_NUMBER                 // 备份域复位位在寄存器中的位编号
#define BDRST_BITNUMBER        RCC_BDRST_BIT_NUMBER                 // 备份域复位位在寄存器中的位编号
#define RTCRST_BITNUMBER       RCC_RTCRST_BIT_NUMBER                // RTC复位位在寄存器中的位编号
#define LSION_BitNumber        RCC_LSION_BIT_NUMBER                 // LSI使能位在寄存器中的位编号
#define LSION_BITNUMBER        RCC_LSION_BIT_NUMBER                 // LSI使能位在寄存器中的位编号
#define LSEON_BitNumber        RCC_LSEON_BIT_NUMBER                 // LSE使能位在寄存器中的位编号
#define LSEON_BITNUMBER        RCC_LSEON_BIT_NUMBER                 // LSE使能位在寄存器中的位编号
#define LSEBYP_BITNUMBER       RCC_LSEBYP_BIT_NUMBER                // LSE旁路位在寄存器中的位编号
#define PLLSAION_BitNumber     RCC_PLLSAION_BIT_NUMBER              // PLLSAI使能位在寄存器中的位编号
#define TIMPRE_BitNumber       RCC_TIMPRE_BIT_NUMBER                // 定时器时钟预分频位在寄存器中的位编号
#define RMVF_BitNumber         RCC_RMVF_BIT_NUMBER                  // 复位标志清除位在寄存器中的位编号
#define RMVF_BITNUMBER         RCC_RMVF_BIT_NUMBER                  // 复位标志清除位在寄存器中的位编号
#define RCC_CR2_HSI14TRIM_BitNumber RCC_HSI14TRIM_BIT_NUMBER        // HSI14微调位在寄存器中的位编号
#define CR_BYTE2_ADDRESS       RCC_CR_BYTE2_ADDRESS                 // CR寄存器字节2地址
#define CIR_BYTE1_ADDRESS      RCC_CIR_BYTE1_ADDRESS                // CIR寄存器字节1地址
#define CIR_BYTE2_ADDRESS      RCC_CIR_BYTE2_ADDRESS                // CIR寄存器字节2地址
#define BDCR_BYTE0_ADDRESS     RCC_BDCR_BYTE0_ADDRESS               // BDCR寄存器字节0地址
#define DBP_TIMEOUT_VALUE      RCC_DBP_TIMEOUT_VALUE                // 备份域保护解锁超时值
#define LSE_TIMEOUT_VALUE      RCC_LSE_TIMEOUT_VALUE                // LSE启动超时值

#define CR_HSION_BB            RCC_CR_HSION_BB                      // HSI使能位位带别名
#define CR_CSSON_BB            RCC_CR_CSSON_BB                      // CSS使能位位带别名
#define CR_PLLON_BB            RCC_CR_PLLON_BB                      // PLL使能位位带别名
#define CR_PLLI2SON_BB         RCC_CR_PLLI2SON_BB                   // PLLI2S使能位位带别名
#define CR_MSION_BB            RCC_CR_MSION_BB                      // MSI使能位位带别名
#define CSR_LSION_BB           RCC_CSR_LSION_BB                     // LSI使能位位带别名
#define CSR_LSEON_BB           RCC_CSR_LSEON_BB                     // LSE使能位位带别名
#define CSR_LSEBYP_BB          RCC_CSR_LSEBYP_BB                    // LSE旁路位位带别名
#define CSR_RTCEN_BB           RCC_CSR_RTCEN_BB                     // RTC使能位位带别名
#define CSR_RTCRST_BB          RCC_CSR_RTCRST_BB                    // RTC复位位位带别名
#define CFGR_I2SSRC_BB         RCC_CFGR_I2SSRC_BB                   // I2S时钟源位位带别名
#define BDCR_RTCEN_BB          RCC_BDCR_RTCEN_BB                    // RTC使能位位带别名（BDCR寄存器）
#define BDCR_BDRST_BB          RCC_BDCR_BDRST_BB                    // 备份域复位位位带别名
#define CR_HSEON_BB            RCC_CR_HSEON_BB                      // HSE使能位位带别名
#define CSR_RMVF_BB            RCC_CSR_RMVF_BB                      // 复位标志清除位位带别名
#define CR_PLLSAION_BB         RCC_CR_PLLSAION_BB                   // PLLSAI使能位位带别名
#define DCKCFGR_TIMPRE_BB      RCC_DCKCFGR_TIMPRE_BB                // 定时器时钟预分频位位带别名

#define __HAL_RCC_CRS_ENABLE_FREQ_ERROR_COUNTER     __HAL_RCC_CRS_FREQ_ERROR_COUNTER_ENABLE      // CRS频率误差计数器使能宏，映射到CRS频率误差计数器使能
#define __HAL_RCC_CRS_DISABLE_FREQ_ERROR_COUNTER    __HAL_RCC_CRS_FREQ_ERROR_COUNTER_DISABLE     // CRS频率误差计数器禁用宏，映射到CRS频率误差计数器禁用
#define __HAL_RCC_CRS_ENABLE_AUTOMATIC_CALIB        __HAL_RCC_CRS_AUTOMATIC_CALIB_ENABLE         // CRS自动校准使能宏，映射到CRS自动校准使能
#define __HAL_RCC_CRS_DISABLE_AUTOMATIC_CALIB       __HAL_RCC_CRS_AUTOMATIC_CALIB_DISABLE        // CRS自动校准禁用宏，映射到CRS自动校准禁用
#define __HAL_RCC_CRS_CALCULATE_RELOADVALUE         __HAL_RCC_CRS_RELOADVALUE_CALCULATE          // CRS计算重载值宏，映射到CRS计算重载值

#define __HAL_RCC_GET_IT_SOURCE                     __HAL_RCC_GET_IT                             // 获取中断源宏，映射到获取中断宏

#define RCC_CRS_SYNCWARM       RCC_CRS_SYNCWARN                      // CRS同步警告标志，映射到CRS同步警告
#define RCC_CRS_TRIMOV         RCC_CRS_TRIMOVF                       // CRS微调溢出标志，映射到CRS微调溢出

#define RCC_PERIPHCLK_CK48               RCC_PERIPHCLK_CLK48          // 外设时钟CK48，映射到外设时钟CLK48
#define RCC_CK48CLKSOURCE_PLLQ           RCC_CLK48CLKSOURCE_PLLQ      // CK48时钟源为PLLQ，映射到CLK48时钟源PLLQ
#define RCC_CK48CLKSOURCE_PLLSAIP        RCC_CLK48CLKSOURCE_PLLSAIP   // CK48时钟源为PLLSAIP，映射到CLK48时钟源PLLSAIP
#define RCC_CK48CLKSOURCE_PLLI2SQ        RCC_CLK48CLKSOURCE_PLLI2SQ   // CK48时钟源为PLLI2SQ，映射到CLK48时钟源PLLI2SQ
#define IS_RCC_CK48CLKSOURCE             IS_RCC_CLK48CLKSOURCE        // 检查CK48时钟源宏，映射到检查CLK48时钟源
#define RCC_SDIOCLKSOURCE_CK48           RCC_SDIOCLKSOURCE_CLK48      // SDIO时钟源为CK48，映射到SDIO时钟源CLK48
#define __HAL_RCC_DFSDM_CLK_ENABLE             __HAL_RCC_DFSDM1_CLK_ENABLE
#define __HAL_RCC_DFSDM_CLK_DISABLE            __HAL_RCC_DFSDM1_CLK_DISABLE
#define __HAL_RCC_DFSDM_IS_CLK_ENABLED         __HAL_RCC_DFSDM1_IS_CLK_ENABLED
#define __HAL_RCC_DFSDM_IS_CLK_DISABLED        __HAL_RCC_DFSDM1_IS_CLK_DISABLED
#define __HAL_RCC_DFSDM_FORCE_RESET            __HAL_RCC_DFSDM1_FORCE_RESET
#define __HAL_RCC_DFSDM_RELEASE_RESET          __HAL_RCC_DFSDM1_RELEASE_RESET
#define __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE       __HAL_RCC_DFSDM1_CLK_SLEEP_ENABLE
#define __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE      __HAL_RCC_DFSDM1_CLK_SLEEP_DISABLE
#define __HAL_RCC_DFSDM_IS_CLK_SLEEP_ENABLED   __HAL_RCC_DFSDM1_IS_CLK_SLEEP_ENABLED
#define __HAL_RCC_DFSDM_IS_CLK_SLEEP_DISABLED  __HAL_RCC_DFSDM1_IS_CLK_SLEEP_DISABLED
#define DfsdmClockSelection         Dfsdm1ClockSelection
#define RCC_PERIPHCLK_DFSDM         RCC_PERIPHCLK_DFSDM1
#define RCC_DFSDMCLKSOURCE_PCLK     RCC_DFSDM1CLKSOURCE_PCLK2
#define RCC_DFSDMCLKSOURCE_SYSCLK   RCC_DFSDM1CLKSOURCE_SYSCLK
#define __HAL_RCC_DFSDM_CONFIG      __HAL_RCC_DFSDM1_CONFIG
#define __HAL_RCC_GET_DFSDM_SOURCE  __HAL_RCC_GET_DFSDM1_SOURCE
#define RCC_DFSDM1CLKSOURCE_PCLK    RCC_DFSDM1CLKSOURCE_PCLK2
#define RCC_SWPMI1CLKSOURCE_PCLK    RCC_SWPMI1CLKSOURCE_PCLK1
#if !defined(STM32U0)
#define RCC_LPTIM1CLKSOURCE_PCLK    RCC_LPTIM1CLKSOURCE_PCLK1
#define RCC_LPTIM2CLKSOURCE_PCLK    RCC_LPTIM2CLKSOURCE_PCLK1
#endif

#define RCC_DFSDM1AUDIOCLKSOURCE_I2SAPB1    RCC_DFSDM1AUDIOCLKSOURCE_I2S1
#define RCC_DFSDM1AUDIOCLKSOURCE_I2SAPB2    RCC_DFSDM1AUDIOCLKSOURCE_I2S2
#define RCC_DFSDM2AUDIOCLKSOURCE_I2SAPB1    RCC_DFSDM2AUDIOCLKSOURCE_I2S1
#define RCC_DFSDM2AUDIOCLKSOURCE_I2SAPB2    RCC_DFSDM2AUDIOCLKSOURCE_I2S2
#define RCC_DFSDM1CLKSOURCE_APB2            RCC_DFSDM1CLKSOURCE_PCLK2
#define RCC_DFSDM2CLKSOURCE_APB2            RCC_DFSDM2CLKSOURCE_PCLK2
#define RCC_FMPI2C1CLKSOURCE_APB            RCC_FMPI2C1CLKSOURCE_PCLK1
#if defined(STM32U5)
#define MSIKPLLModeSEL                        RCC_MSIKPLL_MODE_SEL
#define MSISPLLModeSEL                        RCC_MSISPLL_MODE_SEL
#define __HAL_RCC_AHB21_CLK_DISABLE           __HAL_RCC_AHB2_1_CLK_DISABLE
#define __HAL_RCC_AHB22_CLK_DISABLE           __HAL_RCC_AHB2_2_CLK_DISABLE
#define __HAL_RCC_AHB1_CLK_Disable_Clear      __HAL_RCC_AHB1_CLK_ENABLE
#define __HAL_RCC_AHB21_CLK_Disable_Clear     __HAL_RCC_AHB2_1_CLK_ENABLE
#define __HAL_RCC_AHB22_CLK_Disable_Clear     __HAL_RCC_AHB2_2_CLK_ENABLE
#define __HAL_RCC_AHB3_CLK_Disable_Clear      __HAL_RCC_AHB3_CLK_ENABLE
#define __HAL_RCC_APB1_CLK_Disable_Clear      __HAL_RCC_APB1_CLK_ENABLE
#define __HAL_RCC_APB2_CLK_Disable_Clear      __HAL_RCC_APB2_CLK_ENABLE
#define __HAL_RCC_APB3_CLK_Disable_Clear      __HAL_RCC_APB3_CLK_ENABLE
#define IS_RCC_MSIPLLModeSelection            IS_RCC_MSIPLLMODE_SELECT
#define RCC_PERIPHCLK_CLK48                   RCC_PERIPHCLK_ICLK
#define RCC_CLK48CLKSOURCE_HSI48              RCC_ICLK_CLKSOURCE_HSI48
#define RCC_CLK48CLKSOURCE_PLL2               RCC_ICLK_CLKSOURCE_PLL2
#define RCC_CLK48CLKSOURCE_PLL1               RCC_ICLK_CLKSOURCE_PLL1
#define RCC_CLK48CLKSOURCE_MSIK               RCC_ICLK_CLKSOURCE_MSIK
#define __HAL_RCC_ADC1_CLK_ENABLE             __HAL_RCC_ADC12_CLK_ENABLE
#define __HAL_RCC_ADC1_CLK_DISABLE            __HAL_RCC_ADC12_CLK_DISABLE
#define __HAL_RCC_ADC1_IS_CLK_ENABLED         __HAL_RCC_ADC12_IS_CLK_ENABLED
#define __HAL_RCC_ADC1_IS_CLK_DISABLED        __HAL_RCC_ADC12_IS_CLK_DISABLED
#define __HAL_RCC_ADC1_FORCE_RESET            __HAL_RCC_ADC12_FORCE_RESET
#define __HAL_RCC_ADC1_RELEASE_RESET          __HAL_RCC_ADC12_RELEASE_RESET
#define __HAL_RCC_ADC1_CLK_SLEEP_ENABLE       __HAL_RCC_ADC12_CLK_SLEEP_ENABLE
#define __HAL_RCC_ADC1_CLK_SLEEP_DISABLE      __HAL_RCC_ADC12_CLK_SLEEP_DISABLE
#define __HAL_RCC_GET_CLK48_SOURCE            __HAL_RCC_GET_ICLK_SOURCE
#define __HAL_RCC_PLLFRACN_ENABLE             __HAL_RCC_PLL_FRACN_ENABLE
#define __HAL_RCC_PLLFRACN_DISABLE            __HAL_RCC_PLL_FRACN_DISABLE
#define __HAL_RCC_PLLFRACN_CONFIG             __HAL_RCC_PLL_FRACN_CONFIG
#define IS_RCC_PLLFRACN_VALUE                 IS_RCC_PLL_FRACN_VALUE
#endif /* STM32U5 */

#if defined(STM32H5)
#define __HAL_RCC_PLLFRACN_ENABLE       __HAL_RCC_PLL_FRACN_ENABLE
#define __HAL_RCC_PLLFRACN_DISABLE      __HAL_RCC_PLL_FRACN_DISABLE
#define __HAL_RCC_PLLFRACN_CONFIG       __HAL_RCC_PLL_FRACN_CONFIG
#define IS_RCC_PLLFRACN_VALUE           IS_RCC_PLL_FRACN_VALUE

#define RCC_PLLSOURCE_NONE              RCC_PLL1_SOURCE_NONE
#define RCC_PLLSOURCE_HSI               RCC_PLL1_SOURCE_HSI
#define RCC_PLLSOURCE_CSI               RCC_PLL1_SOURCE_CSI
#define RCC_PLLSOURCE_HSE               RCC_PLL1_SOURCE_HSE
#define RCC_PLLVCIRANGE_0               RCC_PLL1_VCIRANGE_0
#define RCC_PLLVCIRANGE_1               RCC_PLL1_VCIRANGE_1
#define RCC_PLLVCIRANGE_2               RCC_PLL1_VCIRANGE_2
#define RCC_PLLVCIRANGE_3               RCC_PLL1_VCIRANGE_3
#define RCC_PLL1VCOWIDE                 RCC_PLL1_VCORANGE_WIDE
#define RCC_PLL1VCOMEDIUM               RCC_PLL1_VCORANGE_MEDIUM

#define IS_RCC_PLLSOURCE                IS_RCC_PLL1_SOURCE
#define IS_RCC_PLLRGE_VALUE             IS_RCC_PLL1_VCIRGE_VALUE
#define IS_RCC_PLLVCORGE_VALUE          IS_RCC_PLL1_VCORGE_VALUE
#define IS_RCC_PLLCLOCKOUT_VALUE        IS_RCC_PLL1_CLOCKOUT_VALUE
#define IS_RCC_PLL_FRACN_VALUE          IS_RCC_PLL1_FRACN_VALUE
#define IS_RCC_PLLM_VALUE               IS_RCC_PLL1_DIVM_VALUE
#define IS_RCC_PLLN_VALUE               IS_RCC_PLL1_MULN_VALUE
#define IS_RCC_PLLP_VALUE               IS_RCC_PLL1_DIVP_VALUE
#define IS_RCC_PLLQ_VALUE               IS_RCC_PLL1_DIVQ_VALUE
#define IS_RCC_PLLR_VALUE               IS_RCC_PLL1_DIVR_VALUE

#define __HAL_RCC_PLL_ENABLE            __HAL_RCC_PLL1_ENABLE
#define __HAL_RCC_PLL_DISABLE           __HAL_RCC_PLL1_DISABLE
#define __HAL_RCC_PLL_FRACN_ENABLE      __HAL_RCC_PLL1_FRACN_ENABLE
#define __HAL_RCC_PLL_FRACN_DISABLE     __HAL_RCC_PLL1_FRACN_DISABLE
#define __HAL_RCC_PLL_CONFIG            __HAL_RCC_PLL1_CONFIG
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG  __HAL_RCC_PLL1_PLLSOURCE_CONFIG
#define __HAL_RCC_PLL_DIVM_CONFIG       __HAL_RCC_PLL1_DIVM_CONFIG
#define __HAL_RCC_PLL_FRACN_CONFIG      __HAL_RCC_PLL1_FRACN_CONFIG
#define __HAL_RCC_PLL_VCIRANGE          __HAL_RCC_PLL1_VCIRANGE
#define __HAL_RCC_PLL_VCORANGE          __HAL_RCC_PLL1_VCORANGE
#define __HAL_RCC_GET_PLL_OSCSOURCE     __HAL_RCC_GET_PLL1_OSCSOURCE
#define __HAL_RCC_PLLCLKOUT_ENABLE      __HAL_RCC_PLL1_CLKOUT_ENABLE
#define __HAL_RCC_PLLCLKOUT_DISABLE     __HAL_RCC_PLL1_CLKOUT_DISABLE
#define __HAL_RCC_GET_PLLCLKOUT_CONFIG  __HAL_RCC_GET_PLL1_CLKOUT_CONFIG

#define __HAL_RCC_PLL2FRACN_ENABLE      __HAL_RCC_PLL2_FRACN_ENABLE
#define __HAL_RCC_PLL2FRACN_DISABLE     __HAL_RCC_PLL2_FRACN_DISABLE
#define __HAL_RCC_PLL2CLKOUT_ENABLE     __HAL_RCC_PLL2_CLKOUT_ENABLE
#define __HAL_RCC_PLL2CLKOUT_DISABLE    __HAL_RCC_PLL2_CLKOUT_DISABLE
#define __HAL_RCC_PLL2FRACN_CONFIG      __HAL_RCC_PLL2_FRACN_CONFIG
#define __HAL_RCC_GET_PLL2CLKOUT_CONFIG __HAL_RCC_GET_PLL2_CLKOUT_CONFIG

#define __HAL_RCC_PLL3FRACN_ENABLE      __HAL_RCC_PLL3_FRACN_ENABLE
#define __HAL_RCC_PLL3FRACN_DISABLE     __HAL_RCC_PLL3_FRACN_DISABLE
#define __HAL_RCC_PLL3CLKOUT_ENABLE     __HAL_RCC_PLL3_CLKOUT_ENABLE
#define __HAL_RCC_PLL3CLKOUT_DISABLE    __HAL_RCC_PLL3_CLKOUT_DISABLE
#define __HAL_RCC_PLL3FRACN_CONFIG      __HAL_RCC_PLL3_FRACN_CONFIG
#define __HAL_RCC_GET_PLL3CLKOUT_CONFIG __HAL_RCC_GET_PLL3_CLKOUT_CONFIG

#define RCC_PLL2VCIRANGE_0              RCC_PLL2_VCIRANGE_0
#define RCC_PLL2VCIRANGE_1              RCC_PLL2_VCIRANGE_1
#define RCC_PLL2VCIRANGE_2              RCC_PLL2_VCIRANGE_2
#define RCC_PLL2VCIRANGE_3              RCC_PLL2_VCIRANGE_3

#define RCC_PLL2VCOWIDE                 RCC_PLL2_VCORANGE_WIDE
#define RCC_PLL2VCOMEDIUM               RCC_PLL2_VCORANGE_MEDIUM

#define RCC_PLL2SOURCE_NONE             RCC_PLL2_SOURCE_NONE
#define RCC_PLL2SOURCE_HSI              RCC_PLL2_SOURCE_HSI
#define RCC_PLL2SOURCE_CSI              RCC_PLL2_SOURCE_CSI
#define RCC_PLL2SOURCE_HSE              RCC_PLL2_SOURCE_HSE

#define RCC_PLL3VCIRANGE_0              RCC_PLL3_VCIRANGE_0
#define RCC_PLL3VCIRANGE_1              RCC_PLL3_VCIRANGE_1
#define RCC_PLL3VCIRANGE_2              RCC_PLL3_VCIRANGE_2
#define RCC_PLL3VCIRANGE_3              RCC_PLL3_VCIRANGE_3

#define RCC_PLL3VCOWIDE                 RCC_PLL3_VCORANGE_WIDE
#define RCC_PLL3VCOMEDIUM               RCC_PLL3_VCORANGE_MEDIUM

#define RCC_PLL3SOURCE_NONE             RCC_PLL3_SOURCE_NONE
#define RCC_PLL3SOURCE_HSI              RCC_PLL3_SOURCE_HSI
#define RCC_PLL3SOURCE_CSI              RCC_PLL3_SOURCE_CSI
#define RCC_PLL3SOURCE_HSE              RCC_PLL3_SOURCE_HSE


#endif /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_RNG_Aliased_Macros HAL RNG Aliased Macros maintained for legacy purpose
  * @brief 为了向后兼容而保留的RNG别名宏
  * @{
  */
#define  HAL_RNG_ReadyCallback(__HANDLE__)  HAL_RNG_ReadyDataCallback((__HANDLE__), uint32_t random32bit)

/**
  * @}
  */

/** @defgroup HAL_RTC_Aliased_Macros HAL RTC Aliased Macros maintained for legacy purpose
  * @brief 为了向后兼容而保留的RTC别名宏
  * @{
  */
#if defined (STM32G0) || defined (STM32L5) || defined (STM32L412xx) || defined (STM32L422xx) || \
    defined (STM32L4P5xx)|| defined (STM32L4Q5xx) || defined (STM32G4) || defined (STM32WL) || defined (STM32U5) || \
    defined (STM32WBA) || defined (STM32H5) || \
    defined (STM32C0) || defined (STM32H7RS) ||  defined (STM32U0)
#else
#define __HAL_RTC_CLEAR_FLAG                      __HAL_RTC_EXTI_CLEAR_FLAG
#endif
#define __HAL_RTC_DISABLE_IT                      __HAL_RTC_EXTI_DISABLE_IT
#define __HAL_RTC_ENABLE_IT                       __HAL_RTC_EXTI_ENABLE_IT

#if defined (STM32F1)
#define __HAL_RTC_EXTI_CLEAR_FLAG(RTC_EXTI_LINE_ALARM_EVENT)  __HAL_RTC_ALARM_EXTI_CLEAR_FLAG()

#define __HAL_RTC_EXTI_ENABLE_IT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_ENABLE_IT()

#define __HAL_RTC_EXTI_DISABLE_IT(RTC_EXTI_LINE_ALARM_EVENT)  __HAL_RTC_ALARM_EXTI_DISABLE_IT()
#define __HAL_RTC_EXTI_GET_FLAG(RTC_EXTI_LINE_ALARM_EVENT)    __HAL_RTC_ALARM_EXTI_GET_FLAG()  /* 获取RTC闹钟事件EXTI标志位（F1专用）*/

#define __HAL_RTC_EXTI_GENERATE_SWIT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_GENERATE_SWIT()  /* 生成RTC闹钟事件软件触发（F1专用）*/
#else
/* 根据EXTI线参数清除RTC事件标志位（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_CLEAR_FLAG(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_CLEAR_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_CLEAR_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_CLEAR_FLAG()))
/* 根据EXTI线参数使能RTC事件中断（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_ENABLE_IT(__EXTI_LINE__)   (((__EXTI_LINE__)  == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_ENABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_IT()))
/* 根据EXTI线参数禁用RTC事件中断（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_DISABLE_IT(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_DISABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_IT()))
/* 根据EXTI线参数获取RTC事件标志位状态（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_GET_FLAG(__EXTI_LINE__)    (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GET_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GET_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GET_FLAG()))
/* 根据EXTI线参数生成RTC事件软件中断（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_GENERATE_SWIT(__EXTI_LINE__)   (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GENERATE_SWIT() : \
                                                       (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GENERATE_SWIT() :  \
                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GENERATE_SWIT()))
#endif   /* STM32F1 */

/* 为特定系列定义RTC侵入事件获取中断标志的别名 */
#if defined (STM32F0) || defined (STM32F2) || defined (STM32F3) || defined (STM32F4) || defined (STM32F7) || \
    defined (STM32H7) || \
    defined (STM32L0) || defined (STM32L1) || \
    defined (STM32WB)
#define __HAL_RTC_TAMPER_GET_IT                   __HAL_RTC_TAMPER_GET_FLAG  /* 侵入事件获取中断标志别名 */
#endif

/* RTC功能检查宏的别名定义 */
#define IS_ALARM                                  IS_RTC_ALARM  /* 闹钟检查 */
#define IS_ALARM_MASK                             IS_RTC_ALARM_MASK  /* 闹钟掩码检查 */
#define IS_TAMPER                                 IS_RTC_TAMPER  /* 侵入检查 */
#define IS_TAMPER_ERASE_MODE                      IS_RTC_TAMPER_ERASE_MODE  /* 侵入擦除模式检查 */
#define IS_TAMPER_FILTER                          IS_RTC_TAMPER_FILTER  /* 侵入滤波器检查 */
#define IS_TAMPER_INTERRUPT                       IS_RTC_TAMPER_INTERRUPT  /* 侵入中断检查 */
#define IS_TAMPER_MASKFLAG_STATE                  IS_RTC_TAMPER_MASKFLAG_STATE  /* 侵入掩码标志状态检查 */
#define IS_TAMPER_PRECHARGE_DURATION              IS_RTC_TAMPER_PRECHARGE_DURATION  /* 侵入预充电持续时间检查 */
#define IS_TAMPER_PULLUP_STATE                    IS_RTC_TAMPER_PULLUP_STATE  /* 侵入上拉状态检查 */
#define IS_TAMPER_SAMPLING_FREQ                   IS_RTC_TAMPER_SAMPLING_FREQ  /* 侵入采样频率检查 */
#define IS_TAMPER_TIMESTAMPONTAMPER_DETECTION     IS_RTC_TAMPER_TIMESTAMPONTAMPER_DETECTION  /* 侵入检测时时间戳检查 */
#define IS_TAMPER_TRIGGER                         IS_RTC_TAMPER_TRIGGER  /* 侵入触发检查 */
#define IS_WAKEUP_CLOCK                           IS_RTC_WAKEUP_CLOCK  /* 唤醒时钟检查 */
#define IS_WAKEUP_COUNTER                         IS_RTC_WAKEUP_COUNTER  /* 唤醒计数器检查 */

/* RTC写保护宏的别名 */
#define __RTC_WRITEPROTECTION_ENABLE  __HAL_RTC_WRITEPROTECTION_ENABLE  /* 使能写保护 */
#define __RTC_WRITEPROTECTION_DISABLE  __HAL_RTC_WRITEPROTECTION_DISABLE  /* 禁用写保护 */

#if defined (STM32H5)
/* H5系列RTC时钟控制宏的别名 */
#define __HAL_RCC_RTCAPB_CLK_ENABLE   __HAL_RCC_RTC_CLK_ENABLE  /* 使能RTC APB时钟 */
#define __HAL_RCC_RTCAPB_CLK_DISABLE  __HAL_RCC_RTC_CLK_DISABLE  /* 禁用RTC APB时钟 */
#endif   /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_SD_Aliased_Macros HAL SD/MMC Aliased Macros maintained for legacy purpose
  * @brief HAL SD/MMC模块的别名宏，用于保持向后兼容性
  * @{
  */

#define SD_OCR_CID_CSD_OVERWRIETE   SD_OCR_CID_CSD_OVERWRITE  /* OCR寄存器CID/CSD覆盖标志 */
#define SD_CMD_SD_APP_STAUS         SD_CMD_SD_APP_STATUS  /* SD应用状态命令 */

/* eMMC电压范围和时钟分频器宏的别名 */
#if !defined(STM32F1) && !defined(STM32F2) && !defined(STM32F4) && !defined(STM32L1)
#define eMMC_HIGH_VOLTAGE_RANGE     EMMC_HIGH_VOLTAGE_RANGE  /* eMMC高电压范围 */
#define eMMC_DUAL_VOLTAGE_RANGE     EMMC_DUAL_VOLTAGE_RANGE  /* eMMC双电压范围 */
#define eMMC_LOW_VOLTAGE_RANGE      EMMC_LOW_VOLTAGE_RANGE  /* eMMC低电压范围 */

#define SDMMC_NSpeed_CLK_DIV        SDMMC_NSPEED_CLK_DIV  /* 正常速度时钟分频 */
#define SDMMC_HSpeed_CLK_DIV        SDMMC_HSPEED_CLK_DIV  /* 高速时钟分频 */
#endif

/* F4和F2系列SD/MMC功能宏的别名 */
#if defined(STM32F4) || defined(STM32F2)
#define  SD_SDMMC_DISABLED          SD_SDIO_DISABLED  /* SD/MMC禁用状态 */
#define  SD_SDMMC_FUNCTION_BUSY     SD_SDIO_FUNCTION_BUSY  /* SD/MMC功能忙 */
#define  SD_SDMMC_FUNCTION_FAILED   SD_SDIO_FUNCTION_FAILED  /* SD/MMC功能失败 */
#define  SD_SDMMC_UNKNOWN_FUNCTION  SD_SDIO_UNKNOWN_FUNCTION  /* SD/MMC未知功能 */
#define  SD_CMD_SDMMC_SEN_OP_COND   SD_CMD_SDIO_SEN_OP_COND  /* SD/MMC发送操作条件命令 */
#define  SD_CMD_SDMMC_RW_DIRECT     SD_CMD_SDIO_RW_DIRECT  /* SD/MMC直接读写命令 */
#define  SD_CMD_SDMMC_RW_EXTENDED   SD_CMD_SDIO_RW_EXTENDED  /* SD/MMC扩展读写命令 */
#define  __HAL_SD_SDMMC_ENABLE      __HAL_SD_SDIO_ENABLE  /* 使能SD/MMC */
#define  __HAL_SD_SDMMC_DISABLE     __HAL_SD_SDIO_DISABLE  /* 禁用SD/MMC */
#define  __HAL_SD_SDMMC_DMA_ENABLE  __HAL_SD_SDIO_DMA_ENABLE  /* 使能SD/MMC DMA */
#define  __HAL_SD_SDMMC_DMA_DISABLE __HAL_SD_SDIO_DMA_DISABL  /* 禁用SD/MMC DMA（注意：宏名有拼写错误） */
#define  __HAL_SD_SDMMC_ENABLE_IT   __HAL_SD_SDIO_ENABLE_IT  /* 使能SD/MMC中断 */
#define  __HAL_SD_SDMMC_DISABLE_IT  __HAL_SD_SDIO_DISABLE_IT  /* 禁用SD/MMC中断 */
#define  __HAL_SD_SDMMC_GET_FLAG    __HAL_SD_SDIO_GET_FLAG  /* 获取SD/MMC标志位 */
#define  __HAL_SD_SDMMC_CLEAR_FLAG  __HAL_SD_SDIO_CLEAR_FLAG  /* 清除SD/MMC标志位 */
#define  __HAL_SD_SDMMC_GET_IT      __HAL_SD_SDIO_GET_IT  /* 获取SD/MMC中断 */
#define  __HAL_SD_SDMMC_CLEAR_IT    __HAL_SD_SDIO_CLEAR_IT  /* 清除SD/MMC中断 */
#define  SDMMC_STATIC_FLAGS         SDIO_STATIC_FLAGS  /* SD/MMC静态标志位 */
#define  SDMMC_CMD0TIMEOUT          SDIO_CMD0TIMEOUT  /* SD/MMC命令0超时 */
#define  SD_SDMMC_SEND_IF_COND      SD_SDIO_SEND_IF_COND  /* SD/MMC发送接口条件命令 */
/* CMSIS别名 */
#define  SDMMC1_IRQn                SDIO_IRQn  /* SDMMC1中断编号 */
#define  SDMMC1_IRQHandler          SDIO_IRQHandler  /* SDMMC1中断处理函数 */
#endif

/* F7和L4系列SDIO功能宏的别名 */
#if defined(STM32F7) || defined(STM32L4)
#define  SD_SDIO_DISABLED           SD_SDMMC_DISABLED  /* SDIO禁用状态 */
#define  SD_SDIO_FUNCTION_BUSY      SD_SDMMC_FUNCTION_BUSY  /* SDIO功能忙 */
#define  SD_SDIO_FUNCTION_FAILED    SD_SDMMC_FUNCTION_FAILED  /* SDIO功能失败 */
#define  SD_SDIO_UNKNOWN_FUNCTION   SD_SDMMC_UNKNOWN_FUNCTION  /* SDIO未知功能 */
#define  SD_CMD_SDIO_SEN_OP_COND    SD_CMD_SDMMC_SEN_OP_COND  /* SDIO发送操作条件命令 */
#define  SD_CMD_SDIO_RW_DIRECT      SD_CMD_SDMMC_RW_DIRECT  /* SDIO直接读写命令 */
#define  SD_CMD_SDIO_RW_EXTENDED    SD_CMD_SDMMC_RW_EXTENDED  /* SDIO扩展读写命令 */
#define  __HAL_SD_SDIO_ENABLE       __HAL_SD_SDMMC_ENABLE  /* 使能SDIO */
#define  __HAL_SD_SDIO_DISABLE      __HAL_SD_SDMMC_DISABLE  /* 禁用SDIO */
#define  __HAL_SD_SDIO_DMA_ENABLE   __HAL_SD_SDMMC_DMA_ENABLE  /* 使能SDIO DMA */
#define  __HAL_SD_SDIO_DMA_DISABL   __HAL_SD_SDMMC_DMA_DISABLE  /* 禁用SDIO DMA（注意：宏名有拼写错误） */
#define  __HAL_SD_SDIO_ENABLE_IT    __HAL_SD_SDMMC_ENABLE_IT  /* 使能SDIO中断 */
#define  __HAL_SD_SDIO_DISABLE_IT   __HAL_SD_SDMMC_DISABLE_IT  /* 禁用SDIO中断 */
#define  __HAL_SD_SDIO_GET_FLAG     __HAL_SD_SDMMC_GET_FLAG  /* 获取SDIO标志位 */
#define  __HAL_SD_SDIO_CLEAR_FLAG   __HAL_SD_SDMMC_CLEAR_FLAG  /* 清除SDIO标志位 */
#define  __HAL_SD_SDIO_GET_IT       __HAL_SD_SDMMC_GET_IT  /* 获取SDIO中断 */
#define  __HAL_SD_SDIO_CLEAR_IT     __HAL_SD_SDMMC_CLEAR_IT  /* 清除SDIO中断 */
#define  SDIO_STATIC_FLAGS          SDMMC_STATIC_FLAGS  /* SDIO静态标志位 */
#define  SDIO_CMD0TIMEOUT           SDMMC_CMD0TIMEOUT  /* SDIO命令0超时 */
#define  SD_SDIO_SEND_IF_COND       SD_SDMMC_SEND_IF_COND  /* SDIO发送接口条件命令 */
/* CMSIS兼容性别名 */
#define  SDIO_IRQn                  SDMMC1_IRQn  /* SDIO中断编号 */
#define  SDIO_IRQHandler            SDMMC1_IRQHandler  /* SDIO中断处理函数 */
#endif

/* SD卡类型定义宏的别名 */
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F2) || defined(STM32L4) || defined(STM32H7)
#define  HAL_SD_CardCIDTypedef       HAL_SD_CardCIDTypeDef  /* SD卡CID类型定义 */
#define  HAL_SD_CardCSDTypedef       HAL_SD_CardCSDTypeDef  /* SD卡CSD类型定义 */
#define  HAL_SD_CardStatusTypedef    HAL_SD_CardStatusTypeDef  /* SD卡状态类型定义 */
#define  HAL_SD_CardStateTypedef     HAL_SD_CardStateTypeDef  /* SD卡状态类型定义 */
#endif

/* MMC和SD DMA双缓冲区回调函数宏的别名 */
#if defined(STM32H7) || defined(STM32L5)
#define HAL_MMCEx_Read_DMADoubleBuffer0CpltCallback   HAL_MMCEx_Read_DMADoubleBuf0CpltCallback  /* MMC DMA双缓冲区0读取完成回调 */
#define HAL_MMCEx_Read_DMADoubleBuffer1CpltCallback   HAL_MMCEx_Read_DMADoubleBuf1CpltCallback  /* MMC DMA双缓冲区1读取完成回调 */
#define HAL_MMCEx_Write_DMADoubleBuffer0CpltCallback  HAL_MMCEx_Write_DMADoubleBuf0CpltCallback  /* MMC DMA双缓冲区0写入完成回调 */
#define HAL_MMCEx_Write_DMADoubleBuffer1CpltCallback  HAL_MMCEx_Write_DMADoubleBuf1CpltCallback  /* MMC DMA双缓冲区1写入完成回调 */
#define HAL_SDEx_Read_DMADoubleBuffer0CpltCallback    HAL_SDEx_Read_DMADoubleBuf0CpltCallback  /* SD DMA双缓冲区0读取完成回调 */
#define HAL_SDEx_Read_DMADoubleBuffer1CpltCallback    HAL_SDEx_Read_DMADoubleBuf1CpltCallback  /* SD DMA双缓冲区1读取完成回调 */
#define HAL_SDEx_Write_DMADoubleBuffer0CpltCallback   HAL_SDEx_Write_DMADoubleBuf0CpltCallback  /* SD DMA双缓冲区0写入完成回调 */
#define HAL_SDEx_Write_DMADoubleBuffer1CpltCallback   HAL_SDEx_Write_DMADoubleBuf1CpltCallback  /* SD DMA双缓冲区1写入完成回调 */
#define HAL_SD_DriveTransciver_1_8V_Callback          HAL_SD_DriveTransceiver_1_8V_Callback  /* SD 1.8V驱动收发器回调（注意：宏名有拼写错误） */
#endif
/**
  * @}
  */

/** @defgroup HAL_SMARTCARD_Aliased_Macros HAL SMARTCARD Aliased Macros maintained for legacy purpose
  * @brief HAL智能卡模块的别名宏，用于保持向后兼容性
  * @{
  */

/* 智能卡控制宏的别名 */
#define __SMARTCARD_ENABLE_IT           __HAL_SMARTCARD_ENABLE_IT  /* 使能智能卡中断 */
#define __SMARTCARD_DISABLE_IT          __HAL_SMARTCARD_DISABLE_IT  /* 禁用智能卡中断 */
#define __SMARTCARD_ENABLE              __HAL_SMARTCARD_ENABLE  /* 使能智能卡 */
#define __SMARTCARD_DISABLE             __HAL_SMARTCARD_DISABLE  /* 禁用智能卡 */
#define __SMARTCARD_DMA_REQUEST_ENABLE  __HAL_SMARTCARD_DMA_REQUEST_ENABLE  /* 使能智能卡DMA请求 */
#define __SMARTCARD_DMA_REQUEST_DISABLE __HAL_SMARTCARD_DMA_REQUEST_DISABLE  /* 禁用智能卡DMA请求 */

/* 智能卡时钟源获取宏的别名 */
#define __HAL_SMARTCARD_GETCLOCKSOURCE  SMARTCARD_GETCLOCKSOURCE  /* 获取智能卡时钟源 */
#define __SMARTCARD_GETCLOCKSOURCE      SMARTCARD_GETCLOCKSOURCE  /* 获取智能卡时钟源（同上） */

#define IS_SMARTCARD_ONEBIT_SAMPLING    IS_SMARTCARD_ONE_BIT_SAMPLE  /* 智能卡单比特采样检查 */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Macros HAL SMBUS Aliased Macros maintained for legacy purpose
  * @brief HAL SMBUS模块的别名宏，用于保持向后兼容性
  * @{
  */
/* SMBUS控制宏的别名 */
#define __HAL_SMBUS_RESET_CR1           SMBUS_RESET_CR1  /* 重置SMBUS控制寄存器1 */
#define __HAL_SMBUS_RESET_CR2           SMBUS_RESET_CR2  /* 重置SMBUS控制寄存器2 */
#define __HAL_SMBUS_GENERATE_START      SMBUS_GENERATE_START  /* 生成SMBUS起始条件 */
#define __HAL_SMBUS_GET_ADDR_MATCH      SMBUS_GET_ADDR_MATCH  /* 获取SMBUS地址匹配状态 */
#define __HAL_SMBUS_GET_DIR             SMBUS_GET_DIR  /* 获取SMBUS传输方向 */
#define __HAL_SMBUS_GET_STOP_MODE       SMBUS_GET_STOP_MODE  /* 获取SMBUS停止模式 */
#define __HAL_SMBUS_GET_PEC_MODE        SMBUS_GET_PEC_MODE  /* 获取SMBUS PEC模式 */
#define __HAL_SMBUS_GET_ALERT_ENABLED   SMBUS_GET_ALERT_ENABLED  /* 获取SMBUS警报使能状态 */
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Macros HAL SPI Aliased Macros maintained for legacy purpose
  * @brief HAL SPI模块的别名宏，用于保持向后兼容性
  * @{
  */
#define __HAL_SPI_1LINE_TX              SPI_1LINE_TX   /* SPI单线发送模式宏定义 */
#define __HAL_SPI_1LINE_RX              SPI_1LINE_RX   /* SPI单线接收模式宏定义 */
#define __HAL_SPI_RESET_CRC             SPI_RESET_CRC  /* SPI CRC重置宏定义 */

/**
  * @}
  */

/** @defgroup HAL_UART_Aliased_Macros HAL UART Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_UART_GETCLOCKSOURCE       UART_GETCLOCKSOURCE       /* 获取UART时钟源宏定义 */
#define __HAL_UART_MASK_COMPUTATION     UART_MASK_COMPUTATION     /* UART掩码计算宏定义 */
#define __UART_GETCLOCKSOURCE           UART_GETCLOCKSOURCE       /* UART时钟源获取宏定义（旧版本） */
#define __UART_MASK_COMPUTATION         UART_MASK_COMPUTATION     /* UART掩码计算宏定义（旧版本） */

#define IS_UART_WAKEUPMETHODE           IS_UART_WAKEUPMETHOD      /* UART唤醒方法检查宏定义（旧版本拼写错误） */

#define IS_UART_ONEBIT_SAMPLE           IS_UART_ONE_BIT_SAMPLE    /* UART单比特采样检查宏定义（旧版本） */
#define IS_UART_ONEBIT_SAMPLING         IS_UART_ONE_BIT_SAMPLE    /* UART单比特采样检查宏定义（旧版本） */

/**
  * @}
  */


/** @defgroup HAL_USART_Aliased_Macros HAL USART Aliased Macros maintained for legacy purpose
  * @{
  */

#define __USART_ENABLE_IT               __HAL_USART_ENABLE_IT     /* USART中断使能宏定义（旧版本） */
#define __USART_DISABLE_IT              __HAL_USART_DISABLE_IT    /* USART中断禁用宏定义（旧版本） */
#define __USART_ENABLE                  __HAL_USART_ENABLE        /* USART使能宏定义（旧版本） */
#define __USART_DISABLE                 __HAL_USART_DISABLE       /* USART禁用宏定义（旧版本） */

#define __HAL_USART_GETCLOCKSOURCE      USART_GETCLOCKSOURCE      /* USART时钟源获取宏定义 */
#define __USART_GETCLOCKSOURCE          USART_GETCLOCKSOURCE      /* USART时钟源获取宏定义（旧版本） */

#if defined(STM32F0) || defined(STM32F3) || defined(STM32F7)      /* 针对STM32F0、F3、F7系列的条件编译 */
#define USART_OVERSAMPLING_16               0x00000000U           /* USART 16倍过采样宏定义 */
#define USART_OVERSAMPLING_8                USART_CR1_OVER8       /* USART 8倍过采样宏定义 */

#define IS_USART_OVERSAMPLING(__SAMPLING__) (((__SAMPLING__) == USART_OVERSAMPLING_16) || \
                                             ((__SAMPLING__) == USART_OVERSAMPLING_8))  /* USART过采样模式检查宏定义 */
#endif /* STM32F0 || STM32F3 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_USB_Aliased_Macros HAL USB Aliased Macros maintained for legacy purpose
  * @{
  */
#define USB_EXTI_LINE_WAKEUP                               USB_WAKEUP_EXTI_LINE  /* USB唤醒外部中断线宏定义 */

#define USB_FS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_FS_WAKEUP_EXTI_RISING_EDGE        /* USB FS外部中断上升沿触发宏定义 */
#define USB_FS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_FS_WAKEUP_EXTI_FALLING_EDGE       /* USB FS外部中断下降沿触发宏定义 */
#define USB_FS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_FS_WAKEUP_EXTI_RISING_FALLING_EDGE /* USB FS外部中断双边沿触发宏定义 */
#define USB_FS_EXTI_LINE_WAKEUP                            USB_OTG_FS_WAKEUP_EXTI_LINE               /* USB FS唤醒外部中断线宏定义 */

#define USB_HS_EXTI_TRIGGER_RISING_EDGE                    USB_OTG_HS_WAKEUP_EXTI_RISING_EDGE        /* USB HS外部中断上升沿触发宏定义 */
#define USB_HS_EXTI_TRIGGER_FALLING_EDGE                   USB_OTG_HS_WAKEUP_EXTI_FALLING_EDGE       /* USB HS外部中断下降沿触发宏定义 */
#define USB_HS_EXTI_TRIGGER_BOTH_EDGE                      USB_OTG_HS_WAKEUP_EXTI_RISING_FALLING_EDGE /* USB HS外部中断双边沿触发宏定义 */
#define USB_HS_EXTI_LINE_WAKEUP                            USB_OTG_HS_WAKEUP_EXTI_LINE               /* USB HS唤醒外部中断线宏定义 */

#define __HAL_USB_EXTI_ENABLE_IT                           __HAL_USB_WAKEUP_EXTI_ENABLE_IT           /* USB外部中断使能宏定义 */
#define __HAL_USB_EXTI_DISABLE_IT                          __HAL_USB_WAKEUP_EXTI_DISABLE_IT          /* USB外部中断禁用宏定义 */
#define __HAL_USB_EXTI_GET_FLAG                            __HAL_USB_WAKEUP_EXTI_GET_FLAG            /* 获取USB外部中断标志宏定义 */
#define __HAL_USB_EXTI_CLEAR_FLAG                          __HAL_USB_WAKEUP_EXTI_CLEAR_FLAG          /* 清除USB外部中断标志宏定义 */
#define __HAL_USB_EXTI_SET_RISING_EDGE_TRIGGER             __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_EDGE  /* 设置USB外部中断上升沿触发宏定义 */
#define __HAL_USB_EXTI_SET_FALLING_EDGE_TRIGGER            __HAL_USB_WAKEUP_EXTI_ENABLE_FALLING_EDGE /* 设置USB外部中断下降沿触发宏定义 */
#define __HAL_USB_EXTI_SET_FALLINGRISING_TRIGGER           __HAL_USB_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE /* 设置USB外部中断双边沿触发宏定义 */

#define __HAL_USB_FS_EXTI_ENABLE_IT                        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_IT           /* USB FS外部中断使能宏定义 */
#define __HAL_USB_FS_EXTI_DISABLE_IT                       __HAL_USB_OTG_FS_WAKEUP_EXTI_DISABLE_IT          /* USB FS外部中断禁用宏定义 */
#define __HAL_USB_FS_EXTI_GET_FLAG                         __HAL_USB_OTG_FS_WAKEUP_EXTI_GET_FLAG            /* 获取USB FS外部中断标志宏定义 */
#define __HAL_USB_FS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_FS_WAKEUP_EXTI_CLEAR_FLAG          /* 清除USB FS外部中断标志宏定义 */
#define __HAL_USB_FS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_EDGE  /* 设置USB FS外部中断上升沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_FS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_FALLING_EDGE /* 设置USB FS外部中断下降沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_FS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_FS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE /* 设置USB FS外部中断双边沿触发宏定义 */
#define __HAL_USB_FS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_FS_WAKEUP_EXTI_GENERATE_SWIT      /* USB FS外部中断生成软件中断宏定义（旧版本拼写错误） */

#define __HAL_USB_HS_EXTI_ENABLE_IT                        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_IT           /* USB HS外部中断使能宏定义 */
#define __HAL_USB_HS_EXTI_DISABLE_IT                       __HAL_USB_OTG_HS_WAKEUP_EXTI_DISABLE_IT          /* USB HS外部中断禁用宏定义 */
#define __HAL_USB_HS_EXTI_GET_FLAG                         __HAL_USB_OTG_HS_WAKEUP_EXTI_GET_FLAG            /* 获取USB HS外部中断标志宏定义 */
#define __HAL_USB_HS_EXTI_CLEAR_FLAG                       __HAL_USB_OTG_HS_WAKEUP_EXTI_CLEAR_FLAG          /* 清除USB HS外部中断标志宏定义 */
#define __HAL_USB_HS_EXTI_SET_RISING_EGDE_TRIGGER          __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_EDGE  /* 设置USB HS外部中断上升沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_HS_EXTI_SET_FALLING_EGDE_TRIGGER         __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_FALLING_EDGE /* 设置USB HS外部中断下降沿触发宏定义（旧版本拼写错误） */
#define __HAL_USB_HS_EXTI_SET_FALLINGRISING_TRIGGER        __HAL_USB_OTG_HS_WAKEUP_EXTI_ENABLE_RISING_FALLING_EDGE /* 设置USB HS外部中断双边沿触发宏定义 */
#define __HAL_USB_HS_EXTI_GENERATE_SWIT                    __HAL_USB_OTG_HS_WAKEUP_EXTI_GENERATE_SWIT      /* USB HS外部中断生成软件中断宏定义（旧版本拼写错误） */

#define HAL_PCD_ActiveRemoteWakeup                         HAL_PCD_ActivateRemoteWakeup   /* PCD激活远程唤醒宏定义（旧版本拼写错误） */
#define HAL_PCD_DeActiveRemoteWakeup                       HAL_PCD_DeActivateRemoteWakeup /* PCD去激活远程唤醒宏定义（旧版本拼写错误） */

#define HAL_PCD_SetTxFiFo                                  HAL_PCDEx_SetTxFiFo            /* PCD设置发送FIFO宏定义（旧版本） */
#define HAL_PCD_SetRxFiFo                                  HAL_PCDEx_SetRxFiFo            /* PCD设置接收FIFO宏定义（旧版本） */
/**
  * @}
  */

/** @defgroup HAL_TIM_Aliased_Macros HAL TIM Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_TIM_SetICPrescalerValue   TIM_SET_ICPRESCALERVALUE   /* 设置TIM输入捕获预分频值宏定义 */
#define __HAL_TIM_ResetICPrescalerValue TIM_RESET_ICPRESCALERVALUE /* 重置TIM输入捕获预分频值宏定义 */

#define TIM_GET_ITSTATUS                __HAL_TIM_GET_IT_SOURCE    /* 获取TIM中断状态宏定义（旧版本） */
#define TIM_GET_CLEAR_IT                __HAL_TIM_CLEAR_IT         /* 清除TIM中断宏定义（旧版本） */

#define __HAL_TIM_GET_ITSTATUS          __HAL_TIM_GET_IT_SOURCE    /* 获取TIM中断状态宏定义 */

#define __HAL_TIM_DIRECTION_STATUS      __HAL_TIM_IS_TIM_COUNTING_DOWN /* TIM计数方向状态检查宏定义（旧版本） */
#define __HAL_TIM_PRESCALER             __HAL_TIM_SET_PRESCALER        /* TIM预分频器设置宏定义（旧版本） */
#define __HAL_TIM_SetCounter            __HAL_TIM_SET_COUNTER          /* TIM计数器设置宏定义（旧版本） */
#define __HAL_TIM_GetCounter            __HAL_TIM_GET_COUNTER          /* TIM计数器获取宏定义（旧版本） */
#define __HAL_TIM_SetAutoreload         __HAL_TIM_SET_AUTORELOAD       /* TIM自动重载值设置宏定义（旧版本） */
#define __HAL_TIM_GetAutoreload         __HAL_TIM_GET_AUTORELOAD       /* TIM自动重载值获取宏定义（旧版本） */
#define __HAL_TIM_SetClockDivision      __HAL_TIM_SET_CLOCKDIVISION    /* TIM时钟分频设置宏定义（旧版本） */
#define __HAL_TIM_GetClockDivision      __HAL_TIM_GET_CLOCKDIVISION    /* TIM时钟分频获取宏定义（旧版本） */
#define __HAL_TIM_SetICPrescaler        __HAL_TIM_SET_ICPRESCALER      /* TIM输入捕获预分频设置宏定义（旧版本） */
#define __HAL_TIM_GetICPrescaler        __HAL_TIM_GET_ICPRESCALER      /* TIM输入捕获预分频获取宏定义（旧版本） */
#define __HAL_TIM_SetCompare            __HAL_TIM_SET_COMPARE          /* TIM比较值设置宏定义（旧版本） */
#define __HAL_TIM_GetCompare            __HAL_TIM_GET_COMPARE          /* TIM比较值获取宏定义（旧版本） */

#define TIM_BREAKINPUTSOURCE_DFSDM  TIM_BREAKINPUTSOURCE_DFSDM1   /* TIM刹车输入源DFSDM宏定义（旧版本） */

#define TIM_OCMODE_ASSYMETRIC_PWM1      TIM_OCMODE_ASYMMETRIC_PWM1  /* TIM非对称PWM1模式宏定义（旧版本拼写错误） */
#define TIM_OCMODE_ASSYMETRIC_PWM2      TIM_OCMODE_ASYMMETRIC_PWM2  /* TIM非对称PWM2模式宏定义（旧版本拼写错误） */
/**
  * @}
  */

/** @defgroup HAL_ETH_Aliased_Macros HAL ETH Aliased Macros maintained for legacy purpose
  * @{
  */

#define __HAL_ETH_EXTI_ENABLE_IT                   __HAL_ETH_WAKEUP_EXTI_ENABLE_IT           /* ETH外部中断使能宏定义 */
#define __HAL_ETH_EXTI_DISABLE_IT                  __HAL_ETH_WAKEUP_EXTI_DISABLE_IT          /* ETH外部中断禁用宏定义 */
#define __HAL_ETH_EXTI_GET_FLAG                    __HAL_ETH_WAKEUP_EXTI_GET_FLAG            /* 获取ETH外部中断标志宏定义 */
#define __HAL_ETH_EXTI_CLEAR_FLAG                  __HAL_ETH_WAKEUP_EXTI_CLEAR_FLAG          /* 清除ETH外部中断标志宏定义 */
#define __HAL_ETH_EXTI_SET_RISING_EGDE_TRIGGER     __HAL_ETH_WAKEUP_EXTI_ENABLE_RISING_EDGE_TRIGGER  /* 设置ETH外部中断上升沿触发宏定义（旧版本拼写错误） */
#define __HAL_ETH_EXTI_SET_FALLING_EGDE_TRIGGER    __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLING_EDGE_TRIGGER /* 设置ETH外部中断下降沿触发宏定义（旧版本拼写错误） */
#define __HAL_ETH_EXTI_SET_FALLINGRISING_TRIGGER   __HAL_ETH_WAKEUP_EXTI_ENABLE_FALLINGRISING_TRIGGER /* 设置ETH外部中断双边沿触发宏定义 */

#define ETH_PROMISCIOUSMODE_ENABLE   ETH_PROMISCUOUS_MODE_ENABLE   /* ETH混杂模式使能宏定义（旧版本拼写错误） */
#define ETH_PROMISCIOUSMODE_DISABLE  ETH_PROMISCUOUS_MODE_DISABLE  /* ETH混杂模式禁用宏定义（旧版本拼写错误） */
#define IS_ETH_PROMISCIOUS_MODE      IS_ETH_PROMISCUOUS_MODE       /* ETH混杂模式检查宏定义（旧版本拼写错误） */
/**
  * @}
  */

/** @defgroup HAL_LTDC_Aliased_Macros HAL LTDC Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_LTDC_LAYER LTDC_LAYER                             /* LTDC层宏定义（旧版本） */
#define __HAL_LTDC_RELOAD_CONFIG  __HAL_LTDC_RELOAD_IMMEDIATE_CONFIG /* LTDC重载配置宏定义（旧版本） */
/**
  * @}
  */

/** @defgroup HAL_SAI_Aliased_Macros HAL SAI Aliased Macros maintained for legacy purpose
  * @{
  */
#define SAI_OUTPUTDRIVE_DISABLED          SAI_OUTPUTDRIVE_DISABLE        /* SAI输出驱动禁用宏定义（旧版本） */
#define SAI_OUTPUTDRIVE_ENABLED           SAI_OUTPUTDRIVE_ENABLE         /* SAI输出驱动使能宏定义（旧版本） */
#define SAI_MASTERDIVIDER_ENABLED         SAI_MASTERDIVIDER_ENABLE       /* SAI主分频器使能宏定义（旧版本） */
#define SAI_MASTERDIVIDER_DISABLED        SAI_MASTERDIVIDER_DISABLE      /* SAI主分频器禁用宏定义（旧版本） */
#define SAI_STREOMODE                     SAI_STEREOMODE                 /* SAI立体声模式宏定义（旧版本拼写错误） */
#define SAI_FIFOStatus_Empty              SAI_FIFOSTATUS_EMPTY           /* SAI FIFO空状态宏定义（旧版本） */
#define SAI_FIFOStatus_Less1QuarterFull   SAI_FIFOSTATUS_LESS1QUARTERFULL /* SAI FIFO少于1/4满状态宏定义（旧版本） */
#define SAI_FIFOStatus_1QuarterFull       SAI_FIFOSTATUS_1QUARTERFULL    /* SAI FIFO 1/4满状态宏定义（旧版本） */
#define SAI_FIFOStatus_HalfFull           SAI_FIFOSTATUS_HALFFULL        /* SAI FIFO半满状态宏定义（旧版本） */
#define SAI_FIFOStatus_3QuartersFull      SAI_FIFOSTATUS_3QUARTERFULL    /* SAI FIFO 3/4满状态宏定义（旧版本） */
#define SAI_FIFOStatus_Full               SAI_FIFOSTATUS_FULL            /* SAI FIFO满状态宏定义（旧版本） */
#define IS_SAI_BLOCK_MONO_STREO_MODE      IS_SAI_BLOCK_MONO_STEREO_MODE  /* SAI块单声道/立体声模式检查宏定义（旧版本拼写错误） */
#define SAI_SYNCHRONOUS_EXT               SAI_SYNCHRONOUS_EXT_SAI1       /* SAI外部同步宏定义（旧版本） */
#define SAI_SYNCEXT_IN_ENABLE             SAI_SYNCEXT_OUTBLOCKA_ENABLE   /* SAI外部同步输入使能宏定义（旧版本） */
/**
  * @}
  */

/** @defgroup HAL_SPDIFRX_Aliased_Macros HAL SPDIFRX Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined(STM32H7)
#define HAL_SPDIFRX_ReceiveControlFlow      HAL_SPDIFRX_ReceiveCtrlFlow      /* SPDIFRX接收控制流宏定义（旧版本） */
#define HAL_SPDIFRX_ReceiveControlFlow_IT   HAL_SPDIFRX_ReceiveCtrlFlow_IT   /* SPDIFRX接收控制流中断宏定义（旧版本） */
#define HAL_SPDIFRX_ReceiveControlFlow_DMA  HAL_SPDIFRX_ReceiveCtrlFlow_DMA  /* SPDIFRX接收控制流DMA宏定义（旧版本） */
#endif
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Functions HAL HRTIM Aliased Functions maintained for legacy purpose
  * @{
  */
#if defined (STM32H7) || defined (STM32G4) || defined (STM32F3)
#define HAL_HRTIM_WaveformCounterStart_IT      HAL_HRTIM_WaveformCountStart_IT   /* HRTIM波形计数器启动中断宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStart_DMA     HAL_HRTIM_WaveformCountStart_DMA  /* HRTIM波形计数器启动DMA宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStart         HAL_HRTIM_WaveformCountStart      /* HRTIM波形计数器启动宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStop_IT       HAL_HRTIM_WaveformCountStop_IT    /* HRTIM波形计数器停止中断宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStop_DMA      HAL_HRTIM_WaveformCountStop_DMA   /* HRTIM波形计数器停止DMA宏定义（旧版本） */
#define HAL_HRTIM_WaveformCounterStop          HAL_HRTIM_WaveformCountStop       /* HRTIM波形计数器停止宏定义（旧版本） */
#endif
/**
  * @}
  */

/** @defgroup HAL_QSPI_Aliased_Macros HAL QSPI Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined (STM32L4) || defined (STM32F4) || defined (STM32F7) || defined(STM32H7)
#define HAL_QPSI_TIMEOUT_DEFAULT_VALUE HAL_QSPI_TIMEOUT_DEFAULT_VALUE  /* QSPI默认超时值宏定义（旧版本拼写错误） */
#endif /* STM32L4 || STM32F4 || STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_Generic_Aliased_Macros HAL Generic Aliased Macros maintained for legacy purpose
  * @{
  */
#if defined (STM32F7)
#define ART_ACCLERATOR_ENABLE ART_ACCELERATOR_ENABLE  /* ART加速器使能宏定义（旧版本拼写错误） */
#endif /* STM32F7 */
/**
  * @}
  */

/** @defgroup HAL_PPP_Aliased_Macros HAL PPP Aliased Macros maintained for legacy purpose
  * @{
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32_HAL_LEGACY */