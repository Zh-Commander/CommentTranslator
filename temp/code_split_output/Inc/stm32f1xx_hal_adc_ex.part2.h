#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
/* 检查ADC规则组外部触发源是否有效，适用于部分F1系列芯片 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif
#if defined (STM32F101xE)
/* 检查ADC规则组外部触发源是否有效，适用于STM32F101xE系列 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \ /* 定时器8触发输出 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif
#if defined (STM32F101xG)
/* 检查ADC规则组外部触发源是否有效，适用于STM32F101xG系列 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 检查ADC规则组外部触发源是否有效，适用于STM32F103xE/G系列（大容量产品），支持更多触发源 */
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_CC1)    || \ /* 定时器3捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC3)    || \ /* 定时器2捕获比较3 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_CC1)    || \ /* 定时器8捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC1)    || \ /* 定时器5捕获比较1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC3)    || \ /* 定时器5捕获比较3 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC3)    || \ /* 定时器1捕获比较3 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \ /* 定时器8触发输出 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif

#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
/* 检查ADC注入组外部触发源是否有效，适用于部分F1系列芯片 */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入组软件触发 */
#endif
#if defined (STM32F101xE)
/* 检查ADC注入组外部触发源是否有效，适用于STM32F101xE系列 */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \ /* 定时器8捕获比较4 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入组软件触发 */
#endif
#if defined (STM32F101xG)
/* 检查ADC注入组外部触发源是否有效，适用于STM32F101xG系列 */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入组软件触发 */
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
/* 检查ADC注入组外部触发源是否有效，适用于STM32F103xE/G系列（大容量产品） */
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \ /* 定时器5捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_CC3)   || \ /* 定时器4捕获比较3 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC2)   || \ /* 定时器8捕获比较2 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_TRGO)  || \ /* 定时器5触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \ /* 定时器5捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \ /* 定时器8捕获比较4 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入组软件触发 */
#endif

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* 检查ADC多模模式配置是否有效，仅适用于拥有多个ADC的F1系列芯片 */
#define IS_ADC_MODE(MODE) (((MODE) == ADC_MODE_INDEPENDENT)                || \ /* 独立模式，ADC1和ADC2各工作各的 */
                           ((MODE) == ADC_DUALMODE_REGSIMULT_INJECSIMULT)  || \ /* 双重模式：规则组同步+注入组同步 */
                           ((MODE) == ADC_DUALMODE_REGSIMULT_ALTERTRIG)    || \ /* 双重模式：规则组同步+交替触发 */
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLFAST) || \ /* 双重模式：注入组同步+快速交错 */
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLSLOW) || \ /* 双重模式：注入组同步+慢速交错 */
                           ((MODE) == ADC_DUALMODE_INJECSIMULT)            || \ /* 双重模式：仅注入组同步 */
                           ((MODE) == ADC_DUALMODE_REGSIMULT)              || \ /* 双重模式：仅规则组同步 */
                           ((MODE) == ADC_DUALMODE_INTERLFAST)             || \ /* 双重模式：仅快速交错 */
                           ((MODE) == ADC_DUALMODE_INTERLSLOW)             || \ /* 双重模式：仅慢速交错 */
                           ((MODE) == ADC_DUALMODE_ALTERTRIG) ) /* 双重模式：仅交替触发 */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */      
   
    

    
    
   
/* 导出函数 ----------------------------------------------------------------*/
/** @addtogroup ADCEx_Exported_Functions
  * @{
  */

/* 输入输出操作函数  *****************************************************/
/** @addtogroup ADCEx_Exported_Functions_Group1
  * @{
  */

/* ADC校验功能 */
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc); /* 启动ADC校准，用于消除内部误差，提高精度 */

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc); /* 启动注入组ADC转换（阻塞模式，不使用中断） */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc); /* 停止注入组ADC转换（阻塞模式） */
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout); /* 等待注入组转换完成，参数为超时时间（毫秒） */

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc); /* 启动注入组ADC转换（非阻塞模式，使能中断） */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc); /* 停止注入组ADC转换（非阻塞模式，关闭中断） */

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* ADC多模模式，仅适用于有多个ADC的芯片 */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length); /* 启动多模ADC转换并通过DMA传输数据 */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc); /* 停止多模ADC转换并关闭DMA */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC获取转换值，通常用于轮询或中断方式处理后的数据读取 */
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank); /* 获取注入组指定通道的转换结果 */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
uint32_t                HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef *hadc); /* 获取多模模式下的转换结果 */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC中断处理函数和回调函数，用于非阻塞模式 */
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc); /* 注入组转换完成回调函数，用户可在自己的代码中重写此函数 */
/**
  * @}
  */


/* 外设控制函数 ***********************************************/
/** @addtogroup ADCEx_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected); /* 配置注入组通道参数，如通道号、采样周期等 */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
HAL_StatusTypeDef       HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef *hadc, ADC_MultiModeTypeDef *multimode); /* 配置ADC多模工作模式 */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */
/**
  * @}
  */


/**
  * @}
  */


/**
  * @}
  */ 

/**
  * @}
  */
  
#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_HAL_ADC_EX_H */
