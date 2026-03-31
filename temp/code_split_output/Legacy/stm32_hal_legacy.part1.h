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