/* 针对STM32F100、F101、F102、F103、F105、F107部分型号的条件编译 */
/* 检查ADC规则通道的外部触发源是否有效 */
#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较通道4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif

/* 针对STM32F101xE型号的条件编译 */
/* 检查ADC规则通道的外部触发源是否有效 */
#if defined (STM32F101xE)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较通道4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \ /* 定时器8触发输出 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif

/* 针对STM32F101xG型号的条件编译 */
/* 检查ADC规则通道的外部触发源是否有效 */
#if defined (STM32F101xG)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较通道4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif

/* 针对STM32F103xE和STM32F103xG型号的条件编译，拥有更多触发源 */
/* 检查ADC规则通道的外部触发源是否有效 */
#if defined (STM32F103xE) || defined (STM32F103xG)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ /* 定时器1捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ /* 定时器1捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ /* 定时器2捕获比较通道2 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ /* 定时器3触发输出 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ /* 定时器4捕获比较通道4 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ /* 外部中断线11 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_CC1)    || \ /* 定时器3捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC3)    || \ /* 定时器2捕获比较通道3 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_CC1)    || \ /* 定时器8捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC1)    || \ /* 定时器5捕获比较通道1 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC3)    || \ /* 定时器5捕获比较通道3 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC3)    || \ /* 定时器1捕获比较通道3 */
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \ /* 定时器8触发输出 */
                                 ((REGTRIG) == ADC_SOFTWARE_START)) /* 软件触发 */
#endif

/* 针对STM32F100、F101、F102、F103、F105、F107部分型号的条件编译 */
/* 检查ADC注入通道的外部触发源是否有效 */
#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较通道1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入通道软件触发 */
#endif

/* 针对STM32F101xE型号的条件编译 */
/* 检查ADC注入通道的外部触发源是否有效 */
#if defined (STM32F101xE)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较通道1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \ /* 定时器8捕获比较通道4 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入通道软件触发 */
#endif

/* 针对STM32F101xG型号的条件编译 */
/* 检查ADC注入通道的外部触发源是否有效 */
#if defined (STM32F101xG)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较通道1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入通道软件触发 */
#endif

/* 针对STM32F103xE和STM32F103xG型号的条件编译，拥有更多注入通道触发源 */
/* 检查ADC注入通道的外部触发源是否有效 */
#if defined (STM32F103xE) || defined (STM32F103xG)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ /* 定时器2触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ /* 定时器2捕获比较通道1 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ /* 定时器3捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ /* 定时器4触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \ /* 定时器5捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ /* 外部中断线15 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_CC3)   || \ /* 定时器4捕获比较通道3 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC2)   || \ /* 定时器8捕获比较通道2 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_TRGO)  || \ /* 定时器5触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \ /* 定时器5捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ /* 定时器1捕获比较通道4 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ /* 定时器1触发输出 */
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \ /* 定时器8捕获比较通道4 */
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) /* 注入通道软件触发 */
#endif

/* 针对拥有双ADC功能的STM32F103等型号的条件编译 */
/* 检查ADC工作模式是否有效（用于双ADC模式） */
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
#define IS_ADC_MODE(MODE) (((MODE) == ADC_MODE_INDEPENDENT)                || \ /* 独立模式 */
                           ((MODE) == ADC_DUALMODE_REGSIMULT_INJECSIMULT)  || \ /* 双重模式：规则同时 + 注入同时 */
                           ((MODE) == ADC_DUALMODE_REGSIMULT_ALTERTRIG)    || \ /* 双重模式：规则同时 + 交替触发 */
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLFAST) || \ /* 双重模式：注入同时 + 快速交错 */
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLSLOW) || \ /* 双重模式：注入同时 + 慢速交错 */
                           ((MODE) == ADC_DUALMODE_INJECSIMULT)            || \ /* 双重模式：注入同时 */
                           ((MODE) == ADC_DUALMODE_REGSIMULT)              || \ /* 双重模式：规则同时 */
                           ((MODE) == ADC_DUALMODE_INTERLFAST)             || \ /* 双重模式：快速交错 */
                           ((MODE) == ADC_DUALMODE_INTERLSLOW)             || \ /* 双重模式：慢速交错 */
                           ((MODE) == ADC_DUALMODE_ALTERTRIG) ) /* 双重模式：交替触发 */
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */      
   
    

    
    
   
/* 导出函数 --------------------------------------------------------*/
/** @addtogroup ADCEx_Exported_Functions
  * @{
  */

/* IO操作函数  *****************************************************/
/** @addtogroup ADCEx_Exported_Functions_Group1
  * @{
  */

/* ADC校准 */
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc); // 启动ADC校准，用于优化ADC精度

/* 阻塞模式：轮询方式 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc); // 启动注入通道ADC转换（阻塞模式，需轮询等待）
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc); // 停止注入通道ADC转换（阻塞模式）
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout); // 轮询等待注入通道转换完成，参数为超时时间

/* 非阻塞模式：中断方式 */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc); // 启动注入通道ADC转换（非阻塞模式，使用中断）
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc); // 停止注入通道ADC转换（非阻塞模式，使用中断）

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* ADC多模功能（仅适用于具有双ADC的型号） */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length); // 启动多模ADC转换并通过DMA传输数据
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc); // 停止多模ADC转换并停止DMA传输
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC获取转换值，旨在用于轮询或中断模式 */
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank); // 获取注入通道转换结果，需指定注入通道排名
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
uint32_t                HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef *hadc); // 获取多模ADC转换结果（返回一个包含两个ADC数据的32位值）
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC中断处理程序和回调函数，用于非阻塞模式（中断） */
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc); // 注入通道转换完成回调函数，用户可在自己的代码中重写此函数
/**
  * @}
  */


/* 外设控制函数 ***********************************************/
/** @addtogroup ADCEx_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected); // 配置注入通道参数（如通道号、采样时间等）
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
HAL_StatusTypeDef       HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef *hadc, ADC_MultiModeTypeDef *multimode); // 配置ADC多模参数（如双ADC模式选择、DMA模式等）
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
