
#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F101xE)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F101xG)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif
#if defined (STM32F103xE) || defined (STM32F103xG)
#define IS_ADC_EXTTRIG(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC2)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_TRGO)   || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T4_CC4)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_EXT_IT11)  || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T3_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T2_CC3)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC1)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T5_CC3)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T1_CC3)    || \
                                 ((REGTRIG) == ADC_EXTERNALTRIGCONV_T8_TRGO)   || \
                                 ((REGTRIG) == ADC_SOFTWARE_START))
#endif

#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101x6) || defined (STM32F101xB) || defined (STM32F102x6) || defined (STM32F102xB) || defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F101xE)
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif
#if defined (STM32F101xG)
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
#define IS_ADC_EXTTRIGINJEC(REGTRIG) (((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T2_CC1)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T3_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_EXT_IT15) || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T4_CC3)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC2)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T5_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_CC4)   || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T1_TRGO)  || \
                                      ((REGTRIG) == ADC_EXTERNALTRIGINJECCONV_T8_CC4)   || \
                                      ((REGTRIG) == ADC_INJECTED_SOFTWARE_START))
#endif

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
#define IS_ADC_MODE(MODE) (((MODE) == ADC_MODE_INDEPENDENT)                || \
                           ((MODE) == ADC_DUALMODE_REGSIMULT_INJECSIMULT)  || \
                           ((MODE) == ADC_DUALMODE_REGSIMULT_ALTERTRIG)    || \
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLFAST) || \
                           ((MODE) == ADC_DUALMODE_INJECSIMULT_INTERLSLOW) || \
                           ((MODE) == ADC_DUALMODE_INJECSIMULT)            || \
                           ((MODE) == ADC_DUALMODE_REGSIMULT)              || \
                           ((MODE) == ADC_DUALMODE_INTERLFAST)             || \
                           ((MODE) == ADC_DUALMODE_INTERLSLOW)             || \
                           ((MODE) == ADC_DUALMODE_ALTERTRIG) )
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */      
   
    

    
    
   
/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADCEx_Exported_Functions
  * @{
  */

/* IO operation functions  *****************************************************/
/** @addtogroup ADCEx_Exported_Functions_Group1
  * @{
  */

/* ADC calibration */
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc);

/* Blocking mode: Polling */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);

/* Non-blocking mode: Interruption */
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc);

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/* ADC multimode */
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc); 
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC retrieve conversion value intended to be used with polling or interruption */
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank);
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
uint32_t                HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef *hadc);
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/* ADC IRQHandler and Callbacks used in non-blocking modes (Interruption) */
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc);
/**
  * @}
  */


/* Peripheral Control functions ***********************************************/
/** @addtogroup ADCEx_Exported_Functions_Group2
  * @{
  */
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected);
#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
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
