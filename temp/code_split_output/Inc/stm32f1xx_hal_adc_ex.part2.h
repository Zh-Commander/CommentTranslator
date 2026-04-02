#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
// 判断ADC外部触发转换源是否合法（适用于小容量/中容量/互联型等设备）
// 参数REGTRIG：外部触发源选择
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \ // 定时器1捕获比较1
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \ // 定时器1捕获比较2
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \ // 定时器2捕获比较2
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \ // 定时器3触发输出
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \ // 定时器4捕获比较4
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \ // 外部中断线11
                                 ((REGTRIG) == ADC_SOFTWARE_START)) // 软件触发
#endif
#if defined (STM32F101xE)
// 判断ADC外部触发转换源是否合法（适用于大容量设备STM32F101xE）
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \ // 定时器8触发输出（大容量特有）
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F101xG)
// 判断ADC外部触发转换源是否合法（适用于超大容量设备STM32F101xG）
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
// 判断ADC外部触发转换源是否合法（适用于大容量/超大容量设备STM32F103xE/G）
// 此系列拥有最丰富的外部触发源
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_CC1)    || \ // 定时器3捕获比较1
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC3)    || \ // 定时器2捕获比较3
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_CC1)    || \ // 定时器8捕获比较1
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC1)    || \ // 定时器5捕获比较1
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC3)    || \ // 定时器5捕获比较3
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC3)    || \ // 定时器1捕获比较3
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \ // 定时器8触发输出
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif

#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
// 判断ADC注入通道外部触发转换源是否合法（适用于小容量/中容量/互联型等设备）
// 参数REGTRIG：注入通道外部触发源选择
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \ // 定时器2触发输出
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \ // 定时器2捕获比较1
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \ // 定时器3捕获比较4
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \ // 定时器4触发输出
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \ // 外部中断线15
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \ // 定时器1捕获比较4
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \ // 定时器1触发输出
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START)) // 注入通道软件触发
#endif
#if defined (STM32F101xE)
// 判断ADC注入通道外部触发转换源是否合法（适用于大容量设备STM32F101xE）
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \ // 定时器8捕获比较4（大容量特有）
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F101xG)
// 判断ADC注入通道外部触发转换源是否合法（适用于超大容量设备STM32F101xG）
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
// 判断ADC注入通道外部触发转换源是否合法（适用于大容量/超大容量设备STM32F103xE/G）
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \ // 定时器5捕获比较4
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_CC3)   || \ // 定时器4捕获比较3
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC2)   || \ // 定时器8捕获比较2
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_TRGO)  || \ // 定时器5触发输出
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \ // 定时器5捕获比较4
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \ // 定时器8捕获比较4
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
// 判断ADC多模模式是否合法（仅适用于拥有双ADC的设备）
// 参数MODE：多模模式选择
#define IS_ADC_MODE(MODE) (((MODE) == ADC_MODE_INDEPENDENT)                || \ // 独立模式，ADC1和ADC2各工作各的
                           ((MODE) == ADC_DUALMODE_REGSIMULT_INJECSIMULT)  || \ // 双重模式：规则同步 + 注入同步
                           ((MODE) == ADC_DUALMODE_REGSIMULT_ALTERTRIG)    || \ // 双重模式：规则同步 + 交替触发
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLFAST) || \ // 双重模式：注入同步 + 快速交叉模式
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLSLOW) || \ // 双重模式：注入同步 + 慢速交叉模式
                           ((MODE) == ADC_DUALMODE_INJECSIMULT)            || \ // 双重模式：仅注入同步
                           ((MODE) == ADC_DUALMODE_REGSIMULT)              || \ // 双重模式：仅规则同步
                           ((MODE) == ADC_DUALMODE_INTERLFAST)             || \ // 双重模式：仅快速交叉
                           ((MODE) == ADC_DUALMODE_INTERLSLOW)             || \ // 双重模式：仅慢速交叉
                           ((MODE) == ADC_DUALMODE_ALTERTRIG) ) // 双重模式：仅交替触发
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */      
    
// 导出函数声明部分
    
   
/* Exported functions --------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/
/** @addtogroup ADCEx_Exported_Functions
  * @{
  */

/* IO operation functions  *****************************************************/
/* I/O操作函数  *****************************************************/
/** @addtogroup ADCEx_Exported_Functions_Group1
  * @{
  */

/* ADC calibration */
/* ADC 校验相关函数 */
// 开始ADC校准
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc);

/* Blocking mode: Polling */
/* 阻塞模式：轮询方式 */
// 启动注入通道转换（阻塞模式）
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc);
// 停止注入通道转换（阻塞模式）
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc);
// 轮询等待注入通道转换完成
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);

/* Non-blocking mode: Interruption */
/* 非阻塞模式：中断方式 */
// 启动注入通道转换（中断模式）
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc);
// 停止注入通道转换（中断模式）
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc);

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* ADC multimode */
/* ADC 多模相关函数（仅双ADC设备可用） */
// 启动多模DMA转换
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
// 停止多模DMA转换
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc); 
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC retrieve conversion value intended to be used with polling or interruption */
/* ADC 获取转换值函数，用于轮询或中断模式 */
// 获取注入通道转换结果
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank);
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
// 获取多模转换结果
uint32_t                HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef *hadc);
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC IRQHandler and Callbacks used in non-blocking modes (Interruption) */
/* ADC 中断处理函数和回调函数，用于非阻塞模式（中断） */
// 注入通道转换完成回调函数
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc);
/**
  * @}
  */


/* Peripheral Control functions ***********************************************/
/* 外设控制函数 ***********************************************/
/** @addtogroup ADCEx_Exported_Functions_Group2
  * @{
  */
// 配置注入通道参数
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected);
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
// 配置多模参数
HAL_StatusTypeDef       HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef *hadc, ADC_MultiModeTypeDef *multimode);
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
