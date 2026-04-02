/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc_ex.h
  * @author  MCD Application Team
  * @brief   Header file of ADC HAL extension module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_HAL_ADC_EX_H
#define __STM32F1xx_HAL_ADC_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"  

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup ADCEx
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 
/** @defgroup ADCEx_Exported_Types ADCEx Exported Types
  * @{
  */

/** 
  * @brief  ADC Configuration injected Channel structure definition
  * @note   Parameters of this structure are shared within 2 scopes:
  *          - Scope channel: InjectedChannel, InjectedRank, InjectedSamplingTime, InjectedOffset
  *          - Scope injected group (affects all channels of injected group): InjectedNbrOfConversion, InjectedDiscontinuousConvMode,
  *            AutoInjectedConv, ExternalTrigInjecConvEdge, ExternalTrigInjecConv.
  * @note   The setting of these parameters with function HAL_ADCEx_InjectedConfigChannel() is conditioned to ADC state.
  *         ADC state can be either:
  *          - For all parameters: ADC disabled (this is the only possible ADC state to modify parameter 'ExternalTrigInjecConv')
  *          - For all except parameters 'ExternalTrigInjecConv': ADC enabled without conversion on going on injected group.
  */
typedef struct 
{
  uint32_t InjectedChannel;                       /*!< Selection of ADC channel to configure
                                                       This parameter can be a value of @ref ADC_channels
                                                       Note: Depending on devices, some channels may not be available on package pins. Refer to device datasheet for channels availability.
                                                       Note: On STM32F1 devices with several ADC: Only ADC1 can access internal measurement channels (VrefInt/TempSensor)
                                                       Note: On STM32F10xx8 and STM32F10xxB devices: A low-amplitude voltage glitch may be generated (on ADC input 0) on the PA0 pin, when the ADC is converting with injection trigger.
                                                             It is advised to distribute the analog channels so that Channel 0 is configured as an injected channel.
                                                             Refer to errata sheet of these devices for more details. */
  uint32_t InjectedRank;                          /*!< Rank in the injected group sequencer
                                                       This parameter must be a value of @ref ADCEx_injected_rank
                                                       Note: In case of need to disable a channel or change order of conversion sequencer, rank containing a previous channel setting can be overwritten by the new channel setting (or parameter number of conversions can be adjusted) */
  uint32_t InjectedSamplingTime;                  /*!< Sampling time value to be set for the selected channel.
                                                       Unit: ADC clock cycles
                                                       Conversion time is the addition of sampling time and processing time (12.5 ADC clock cycles at ADC resolution 12 bits).
                                                       This parameter can be a value of @ref ADC_sampling_times
                                                       Caution: This parameter updates the parameter property of the channel, that can be used into regular and/or injected groups.
                                                                If this same channel has been previously configured in the other group (regular/injected), it will be updated to last setting.
                                                       Note: In case of usage of internal measurement channels (VrefInt/TempSensor),
                                                             sampling time constraints must be respected (sampling time can be adjusted in function of ADC clock frequency and sampling time setting)
                                                             Refer to device datasheet for timings values, parameters TS_vrefint, TS_temp (values rough order: 5us to 17.1us min). */
  uint32_t InjectedOffset;                        /*!< Defines the offset to be subtracted from the raw converted data (for channels set on injected group only).
                                                       Offset value must be a positive number.
                                                       Depending of ADC resolution selected (12, 10, 8 or 6 bits),
                                                       this parameter must be a number between Min_Data = 0x000 and Max_Data = 0xFFF, 0x3FF, 0xFF or 0x3F respectively. */
  uint32_t InjectedNbrOfConversion;               /*!< Specifies the number of ranks that will be converted within the injected group sequencer.
                                                       To use the injected group sequencer and convert several ranks, parameter 'ScanConvMode' must be enabled.
                                                       This parameter must be a number between Min_Data = 1 and Max_Data = 4.
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
  FunctionalState InjectedDiscontinuousConvMode;  /*!< Specifies whether the conversions sequence of injected group is performed in Complete-sequence/Discontinuous-sequence (main sequence subdivided in successive parts).
                                                       Discontinuous mode is used only if sequencer is enabled (parameter 'ScanConvMode'). If sequencer is disabled, this parameter is discarded.
                                                       Discontinuous mode can be enabled only if continuous mode is disabled. If continuous mode is enabled, this parameter setting is discarded.
                                                       This parameter can be set to ENABLE or DISABLE.
                                                       Note: For injected group, number of discontinuous ranks increment is fixed to one-by-one.
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
  FunctionalState AutoInjectedConv;               /*!< Enables or disables the selected ADC automatic injected group conversion after regular one
                                                       This parameter can be set to ENABLE or DISABLE.
                                                       Note: To use Automatic injected conversion, discontinuous mode must be disabled ('DiscontinuousConvMode' and 'InjectedDiscontinuousConvMode' set to DISABLE)
                                                       Note: To use Automatic injected conversion, injected group external triggers must be disabled ('ExternalTrigInjecConv' set to ADC_SOFTWARE_START)
                                                       Note: In case of DMA used with regular group: if DMA configured in normal mode (single shot) JAUTO will be stopped upon DMA transfer complete.
                                                             To maintain JAUTO always enabled, DMA must be configured in circular mode.
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
  uint32_t ExternalTrigInjecConv;                 /*!< Selects the external event used to trigger the conversion start of injected group.
                                                       If set to ADC_INJECTED_SOFTWARE_START, external triggers are disabled.
                                                       If set to external trigger source, triggering is on event rising edge.
                                                       This parameter can be a value of @ref ADCEx_External_trigger_source_Injected
                                                       Note: This parameter must be modified when ADC is disabled (before ADC start conversion or after ADC stop conversion).
                                                             If ADC is enabled, this parameter setting is bypassed without error reporting (as it can be the expected behaviour in case of another parameter update on the fly)
                                                       Caution: this setting impacts the entire injected group. Therefore, call of HAL_ADCEx_InjectedConfigChannel() to
                                                                configure a channel on injected group can impact the configuration of other channels previously set. */
}ADC_InjectionConfTypeDef;

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/** 
  * @brief  Structure definition of ADC multimode
  * @note   The setting of these parameters with function HAL_ADCEx_MultiModeConfigChannel() is conditioned to ADCs state (both ADCs of the common group).
  *         State of ADCs of the common group must be: disabled.
  */
typedef struct
{
  uint32_t Mode;              /*!< Configures the ADC to operate in independent or multi mode. 
                                   This parameter can be a value of @ref ADCEx_Common_mode
                                   Note: In dual mode, a change of channel configuration generates a restart that can produce a loss of synchronization. It is recommended to disable dual mode before any configuration change.
                                   Note: In case of simultaneous mode used: Exactly the same sampling time should be configured for the 2 channels that will be sampled simultaneously by ACD1 and ADC2.
                                   Note: In case of interleaved mode used: To avoid overlap between conversions, maximum sampling time allowed is 7 ADC clock cycles for fast interleaved mode and 14 ADC clock cycles for slow interleaved mode.
                                   Note: Some multimode parameters are fixed on STM32F1 and can be configured on other STM32 devices with several ADC (multimode configuration structure can have additional parameters).
                                         The equivalences are:
                                           - Parameter 'DMAAccessMode': On STM32F1, this parameter is fixed to 1 DMA channel (one DMA channel for both ADC, DMA of ADC master). On other STM32 devices with several ADC, this is equivalent to parameter 'ADC_DMAACCESSMODE_12_10_BITS'.
                                           - Parameter 'TwoSamplingDelay': On STM32F1, this parameter is fixed to 7 or 14 ADC clock cycles depending on fast or slow interleaved mode selected. On other STM32 devices with several ADC, this is equivalent to parameter 'ADC_TWOSAMPLINGDELAY_7CYCLES' (for fast interleaved mode). */

  
}ADC_MultiModeTypeDef;                                                          
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @}
  */


/* Exported constants --------------------------------------------------------*/
   
/** @defgroup ADCEx_Exported_Constants ADCEx Exported Constants
  * @{
  */

/** @defgroup ADCEx_injected_rank ADCEx rank into injected group
  * @{
  */
#define ADC_INJECTED_RANK_1                           0x00000001U
#define ADC_INJECTED_RANK_2                           0x00000002U
#define ADC_INJECTED_RANK_3                           0x00000003U
#define ADC_INJECTED_RANK_4                           0x00000004U
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_edge_Injected ADCEx external trigger enable for injected group
  * @{
  */
#define ADC_EXTERNALTRIGINJECCONV_EDGE_NONE           0x00000000U
#define ADC_EXTERNALTRIGINJECCONV_EDGE_RISING         ((uint32_t)ADC_CR2_JEXTTRIG)
/**
  * @}
  */
    
/** @defgroup ADC_External_trigger_source_Regular ADC External trigger selection for regular group
  * @{
  */
/*!< List of external triggers with generic trigger name, independently of    */
/* ADC target, sorted by trigger name:                                        */

/*!< External triggers of regular group for ADC1&ADC2 only */
#define ADC_EXTERNALTRIGCONV_T1_CC1         ADC1_2_EXTERNALTRIG_T1_CC1
#define ADC_EXTERNALTRIGCONV_T1_CC2         ADC1_2_EXTERNALTRIG_T1_CC2
#define ADC_EXTERNALTRIGCONV_T2_CC2         ADC1_2_EXTERNALTRIG_T2_CC2
#define ADC_EXTERNALTRIGCONV_T3_TRGO        ADC1_2_EXTERNALTRIG_T3_TRGO
#define ADC_EXTERNALTRIGCONV_T4_CC4         ADC1_2_EXTERNALTRIG_T4_CC4
#define ADC_EXTERNALTRIGCONV_EXT_IT11       ADC1_2_EXTERNALTRIG_EXT_IT11

#if defined (STM32F103xE) || defined (STM32F103xG)
/*!< External triggers of regular group for ADC3 only */
#define ADC_EXTERNALTRIGCONV_T2_CC3         ADC3_EXTERNALTRIG_T2_CC3
#define ADC_EXTERNALTRIGCONV_T3_CC1         ADC3_EXTERNALTRIG_T3_CC1
#define ADC_EXTERNALTRIGCONV_T5_CC1         ADC3_EXTERNALTRIG_T5_CC1
#define ADC_EXTERNALTRIGCONV_T5_CC3         ADC3_EXTERNALTRIG_T5_CC3
#define ADC_EXTERNALTRIGCONV_T8_CC1         ADC3_EXTERNALTRIG_T8_CC1
#endif /* STM32F103xE || defined STM32F103xG */

/*!< External triggers of regular group for all ADC instances */
#define ADC_EXTERNALTRIGCONV_T1_CC3         ADC1_2_3_EXTERNALTRIG_T1_CC3

#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/*!< Note: TIM8_TRGO is available on ADC1 and ADC2 only in high-density and   */
/*         XL-density devices.                                                */
/*         To use it on ADC or ADC2, a remap of trigger must be done from     */
/*         EXTI line 11 to TIM8_TRGO with macro:                              */
/*           __HAL_AFIO_REMAP_ADC1_ETRGREG_ENABLE()                           */
/*           __HAL_AFIO_REMAP_ADC2_ETRGREG_ENABLE()                           */

/* Note for internal constant value management: If TIM8_TRGO is available,    */
/* its definition is set to value for ADC1&ADC2 by default and changed to     */
/* value for ADC3 by HAL ADC driver if ADC3 is selected.                      */
#define ADC_EXTERNALTRIGCONV_T8_TRGO        ADC1_2_EXTERNALTRIG_T8_TRGO
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#define ADC_SOFTWARE_START                  ADC1_2_3_SWSTART
/**
  * @}
  */

/** @defgroup ADCEx_External_trigger_source_Injected ADCEx External trigger selection for injected group
  * @{
  */
/*!< List of external triggers with generic trigger name, independently of    */
/* ADC target, sorted by trigger name:                                        */

/*!< External triggers of injected group for ADC1&ADC2 only */
#define ADC_EXTERNALTRIGINJECCONV_T2_TRGO        ADC1_2_EXTERNALTRIGINJEC_T2_TRGO
#define ADC_EXTERNALTRIGINJECCONV_T2_CC1         ADC1_2_EXTERNALTRIGINJEC_T2_CC1
#define ADC_EXTERNALTRIGINJECCONV_T3_CC4         ADC1_2_EXTERNALTRIGINJEC_T3_CC4
#define ADC_EXTERNALTRIGINJECCONV_T4_TRGO        ADC1_2_EXTERNALTRIGINJEC_T4_TRGO 
#define ADC_EXTERNALTRIGINJECCONV_EXT_IT15       ADC1_2_EXTERNALTRIGINJEC_EXT_IT15

#if defined (STM32F103xE) || defined (STM32F103xG)
/*!< External triggers of injected group for ADC3 only */
#define ADC_EXTERNALTRIGINJECCONV_T4_CC3         ADC3_EXTERNALTRIGINJEC_T4_CC3
#define ADC_EXTERNALTRIGINJECCONV_T8_CC2         ADC3_EXTERNALTRIGINJEC_T8_CC2
#define ADC_EXTERNALTRIGINJECCONV_T5_TRGO        ADC3_EXTERNALTRIGINJEC_T5_TRGO
#define ADC_EXTERNALTRIGINJECCONV_T5_CC4         ADC3_EXTERNALTRIGINJEC_T5_CC4
#endif /* STM32F103xE || defined STM32F103xG */

/*!< External triggers of injected group for all ADC instances */
#define ADC_EXTERNALTRIGINJECCONV_T1_CC4         ADC1_2_3_EXTERNALTRIGINJEC_T1_CC4
#define ADC_EXTERNALTRIGINJECCONV_T1_TRGO        ADC1_2_3_EXTERNALTRIGINJEC_T1_TRGO

#if defined (STM32F101xE) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/*!< Note: TIM8_CC4 is available on ADC1 and ADC2 only in high-density and    */
/*         XL-density devices.                                                */
/*         To use it on ADC1 or ADC2, a remap of trigger must be done from    */
/*         EXTI line 11 to TIM8_CC4 with macro:                               */
/*           __HAL_AFIO_REMAP_ADC1_ETRGINJ_ENABLE()                           */
/*           __HAL_AFIO_REMAP_ADC2_ETRGINJ_ENABLE()                           */

/* Note for internal constant value management: If TIM8_CC4 is available,     */
/* its definition is set to value for ADC1&ADC2 by default and changed to     */
/* value for ADC3 by HAL ADC driver if ADC3 is selected.                      */
#define ADC_EXTERNALTRIGINJECCONV_T8_CC4         ADC1_2_EXTERNALTRIGINJEC_T8_CC4
#endif /* STM32F101xE || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#define ADC_INJECTED_SOFTWARE_START              ADC1_2_3_JSWSTART
/**
  * @}
  */
