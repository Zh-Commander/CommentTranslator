/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc.h
  * @author  MCD Application Team
  * @brief   Header file containing functions prototypes of ADC HAL library.
  ******************************************************************************
  * @attention
  *
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
#ifndef __STM32F1xx_HAL_ADC_H
#define __STM32F1xx_HAL_ADC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"  
/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */ 

/* Exported types ------------------------------------------------------------*/ 
/** @defgroup ADC_Exported_Types ADC Exported Types
  * @{
  */

/** 
  * @brief  Structure definition of ADC and regular group initialization 
  * @note   Parameters of this structure are shared within 2 scopes:
  *          - Scope entire ADC (affects regular and injected groups): DataAlign, ScanConvMode.
  *          - Scope regular group: ContinuousConvMode, NbrOfConversion, DiscontinuousConvMode, NbrOfDiscConversion, ExternalTrigConvEdge, ExternalTrigConv.
  * @note   The setting of these parameters with function HAL_ADC_Init() is conditioned to ADC state.
  *         ADC can be either disabled or enabled without conversion on going on regular group.
  */
typedef struct
{
  uint32_t DataAlign;                        /*!< Specifies ADC data alignment to right (MSB on register bit 11 and LSB on register bit 0) (default setting)
                                                  or to left (if regular group: MSB on register bit 15 and LSB on register bit 4, if injected group (MSB kept as signed value due to potential negative value after offset application): MSB on register bit 14 and LSB on register bit 3).
                                                  This parameter can be a value of @ref ADC_Data_align */
  uint32_t ScanConvMode;                     /*!< Configures the sequencer of regular and injected groups.
                                                  This parameter can be associated to parameter 'DiscontinuousConvMode' to have main sequence subdivided in successive parts.
                                                  If disabled: Conversion is performed in single mode (one channel converted, the one defined in rank 1).
                                                               Parameters 'NbrOfConversion' and 'InjectedNbrOfConversion' are discarded (equivalent to set to 1).
                                                  If enabled:  Conversions are performed in sequence mode (multiple ranks defined by 'NbrOfConversion'/'InjectedNbrOfConversion' and each channel rank).
                                                               Scan direction is upward: from rank1 to rank 'n'.
                                                  This parameter can be a value of @ref ADC_Scan_mode
                                                  Note: For regular group, this parameter should be enabled in conversion either by polling (HAL_ADC_Start with Discontinuous mode and NbrOfDiscConversion=1)
                                                        or by DMA (HAL_ADC_Start_DMA), but not by interruption (HAL_ADC_Start_IT): in scan mode, interruption is triggered only on the
                                                        the last conversion of the sequence. All previous conversions would be overwritten by the last one.
                                                        Injected group used with scan mode has not this constraint: each rank has its own result register, no data is overwritten. */
  FunctionalState ContinuousConvMode;         /*!< Specifies whether the conversion is performed in single mode (one conversion) or continuous mode for regular group,
                                                  after the selected trigger occurred (software start or external trigger).
                                                  This parameter can be set to ENABLE or DISABLE. */
  uint32_t NbrOfConversion;                  /*!< Specifies the number of ranks that will be converted within the regular group sequencer.
                                                  To use regular group sequencer and convert several ranks, parameter 'ScanConvMode' must be enabled.
                                                  This parameter must be a number between Min_Data = 1 and Max_Data = 16. */
  FunctionalState  DiscontinuousConvMode;    /*!< Specifies whether the conversions sequence of regular group is performed in Complete-sequence/Discontinuous-sequence (main sequence subdivided in successive parts).
                                                  Discontinuous mode is used only if sequencer is enabled (parameter 'ScanConvMode'). If sequencer is disabled, this parameter is discarded.
                                                  Discontinuous mode can be enabled only if continuous mode is disabled. If continuous mode is enabled, this parameter setting is discarded.
                                                  This parameter can be set to ENABLE or DISABLE. */
  uint32_t NbrOfDiscConversion;              /*!< Specifies the number of discontinuous conversions in which the  main sequence of regular group (parameter NbrOfConversion) will be subdivided.
                                                  If parameter 'DiscontinuousConvMode' is disabled, this parameter is discarded.
                                                  This parameter must be a number between Min_Data = 1 and Max_Data = 8. */
  uint32_t ExternalTrigConv;                 /*!< Selects the external event used to trigger the conversion start of regular group.
                                                  If set to ADC_SOFTWARE_START, external triggers are disabled.
                                                  If set to external trigger source, triggering is on event rising edge.
                                                  This parameter can be a value of @ref ADC_External_trigger_source_Regular */
}ADC_InitTypeDef;

/** 
  * @brief  Structure definition of ADC channel for regular group   
  * @note   The setting of these parameters with function HAL_ADC_ConfigChannel() is conditioned to ADC state.
  *         ADC can be either disabled or enabled without conversion on going on regular group.
  */ 
typedef struct 
{
  uint32_t Channel;                /*!< Specifies the channel to configure into ADC regular group.
                                        This parameter can be a value of @ref ADC_channels
                                        Note: Depending on devices, some channels may not be available on package pins. Refer to device datasheet for channels availability.
                                        Note: On STM32F1 devices with several ADC: Only ADC1 can access internal measurement channels (VrefInt/TempSensor) 
                                        Note: On STM32F10xx8 and STM32F10xxB devices: A low-amplitude voltage glitch may be generated (on ADC input 0) on the PA0 pin, when the ADC is converting with injection trigger.
                                              It is advised to distribute the analog channels so that Channel 0 is configured as an injected channel.
                                              Refer to errata sheet of these devices for more details. */
  uint32_t Rank;                   /*!< Specifies the rank in the regular group sequencer 
                                        This parameter can be a value of @ref ADC_regular_rank
                                        Note: In case of need to disable a channel or change order of conversion sequencer, rank containing a previous channel setting can be overwritten by the new channel setting (or parameter number of conversions can be adjusted) */
  uint32_t SamplingTime;           /*!< Sampling time value to be set for the selected channel.
                                        Unit: ADC clock cycles
                                        Conversion time is the addition of sampling time and processing time (12.5 ADC clock cycles at ADC resolution 12 bits).
                                        This parameter can be a value of @ref ADC_sampling_times
                                        Caution: This parameter updates the parameter property of the channel, that can be used into regular and/or injected groups.
                                                 If this same channel has been previously configured in the other group (regular/injected), it will be updated to last setting.
                                        Note: In case of usage of internal measurement channels (VrefInt/TempSensor),
                                              sampling time constraints must be respected (sampling time can be adjusted in function of ADC clock frequency and sampling time setting)
                                              Refer to device datasheet for timings values, parameters TS_vrefint, TS_temp (values rough order: 5us to 17.1us min). */
}ADC_ChannelConfTypeDef;

/**
  * @brief  ADC Configuration analog watchdog definition
  * @note   The setting of these parameters with function is conditioned to ADC state.
  *         ADC state can be either disabled or enabled without conversion on going on regular and injected groups.
  */
typedef struct
{
  uint32_t WatchdogMode;      /*!< Configures the ADC analog watchdog mode: single/all channels, regular/injected group.
                                   This parameter can be a value of @ref ADC_analog_watchdog_mode. */
  uint32_t Channel;           /*!< Selects which ADC channel to monitor by analog watchdog.
                                   This parameter has an effect only if watchdog mode is configured on single channel (parameter WatchdogMode)
                                   This parameter can be a value of @ref ADC_channels. */
  FunctionalState  ITMode;    /*!< Specifies whether the analog watchdog is configured in interrupt or polling mode.
                                   This parameter can be set to ENABLE or DISABLE */
  uint32_t HighThreshold;     /*!< Configures the ADC analog watchdog High threshold value.
                                   This parameter must be a number between Min_Data = 0x000 and Max_Data = 0xFFF. */
  uint32_t LowThreshold;      /*!< Configures the ADC analog watchdog High threshold value.
                                   This parameter must be a number between Min_Data = 0x000 and Max_Data = 0xFFF. */
  uint32_t WatchdogNumber;    /*!< Reserved for future use, can be set to 0 */
}ADC_AnalogWDGConfTypeDef;

/** 
  * @brief  HAL ADC state machine: ADC states definition (bitfields)
  */ 
/* States of ADC global scope */
#define HAL_ADC_STATE_RESET             0x00000000U    /*!< ADC not yet initialized or disabled */
#define HAL_ADC_STATE_READY             0x00000001U    /*!< ADC peripheral ready for use */
#define HAL_ADC_STATE_BUSY_INTERNAL     0x00000002U    /*!< ADC is busy to internal process (initialization, calibration) */
#define HAL_ADC_STATE_TIMEOUT           0x00000004U    /*!< TimeOut occurrence */

/* States of ADC errors */
#define HAL_ADC_STATE_ERROR_INTERNAL    0x00000010U    /*!< Internal error occurrence */
#define HAL_ADC_STATE_ERROR_CONFIG      0x00000020U    /*!< Configuration error occurrence */
#define HAL_ADC_STATE_ERROR_DMA         0x00000040U    /*!< DMA error occurrence */

/* States of ADC group regular */
#define HAL_ADC_STATE_REG_BUSY          0x00000100U    /*!< A conversion on group regular is ongoing or can occur (either by continuous mode,
                                                           external trigger, low power auto power-on, multimode ADC master control) */
#define HAL_ADC_STATE_REG_EOC           0x00000200U    /*!< Conversion data available on group regular */
#define HAL_ADC_STATE_REG_OVR           0x00000400U    /*!< Not available on STM32F1 device: Overrun occurrence */
#define HAL_ADC_STATE_REG_EOSMP         0x00000800U    /*!< Not available on STM32F1 device: End Of Sampling flag raised  */

/* States of ADC group injected */
#define HAL_ADC_STATE_INJ_BUSY          0x00001000U    /*!< A conversion on group injected is ongoing or can occur (either by auto-injection mode,
                                                           external trigger, low power auto power-on, multimode ADC master control) */
#define HAL_ADC_STATE_INJ_EOC           0x00002000U    /*!< Conversion data available on group injected */
#define HAL_ADC_STATE_INJ_JQOVF         0x00004000U    /*!< Not available on STM32F1 device: Injected queue overflow occurrence */

/* States of ADC analog watchdogs */
#define HAL_ADC_STATE_AWD1              0x00010000U    /*!< Out-of-window occurrence of analog watchdog 1 */
#define HAL_ADC_STATE_AWD2              0x00020000U    /*!< Not available on STM32F1 device: Out-of-window occurrence of analog watchdog 2 */
#define HAL_ADC_STATE_AWD3              0x00040000U    /*!< Not available on STM32F1 device: Out-of-window occurrence of analog watchdog 3 */

/* States of ADC multi-mode */
#define HAL_ADC_STATE_MULTIMODE_SLAVE   0x00100000U    /*!< ADC in multimode slave state, controlled by another ADC master ( */


/**
  * @brief  ADC handle Structure definition  
  */ 
typedef struct __ADC_HandleTypeDef
{
  ADC_TypeDef                   *Instance;              /*!< Register base address */

  ADC_InitTypeDef               Init;                   /*!< ADC required parameters */

  DMA_HandleTypeDef             *DMA_Handle;            /*!< Pointer DMA Handler */

  HAL_LockTypeDef               Lock;                   /*!< ADC locking object */
  
  __IO uint32_t                 State;                  /*!< ADC communication state (bitmap of ADC states) */

  __IO uint32_t                 ErrorCode;              /*!< ADC Error code */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  void (* ConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);              /*!< ADC conversion complete callback */
  void (* ConvHalfCpltCallback)(struct __ADC_HandleTypeDef *hadc);          /*!< ADC conversion DMA half-transfer callback */
  void (* LevelOutOfWindowCallback)(struct __ADC_HandleTypeDef *hadc);      /*!< ADC analog watchdog 1 callback */
  void (* ErrorCallback)(struct __ADC_HandleTypeDef *hadc);                 /*!< ADC error callback */
  void (* InjectedConvCpltCallback)(struct __ADC_HandleTypeDef *hadc);      /*!< ADC group injected conversion complete callback */       /*!< ADC end of sampling callback */
  void (* MspInitCallback)(struct __ADC_HandleTypeDef *hadc);               /*!< ADC Msp Init callback */
  void (* MspDeInitCallback)(struct __ADC_HandleTypeDef *hadc);             /*!< ADC Msp DeInit callback */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}ADC_HandleTypeDef;


#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL ADC Callback ID enumeration definition
  */
typedef enum
{
  HAL_ADC_CONVERSION_COMPLETE_CB_ID     = 0x00U,  /*!< ADC conversion complete callback ID */
  HAL_ADC_CONVERSION_HALF_CB_ID         = 0x01U,  /*!< ADC conversion DMA half-transfer callback ID */
  HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID   = 0x02U,  /*!< ADC analog watchdog 1 callback ID */
  HAL_ADC_ERROR_CB_ID                   = 0x03U,  /*!< ADC error callback ID */
  HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID = 0x04U,  /*!< ADC group injected conversion complete callback ID */
  HAL_ADC_MSPINIT_CB_ID                 = 0x09U,  /*!< ADC Msp Init callback ID          */
  HAL_ADC_MSPDEINIT_CB_ID               = 0x0AU   /*!< ADC Msp DeInit callback ID        */
} HAL_ADC_CallbackIDTypeDef;

/**
  * @brief  HAL ADC Callback pointer definition
  */
typedef  void (*pADC_CallbackTypeDef)(ADC_HandleTypeDef *hadc); /*!< pointer to a ADC callback function */

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */



/* Exported constants --------------------------------------------------------*/

/** @defgroup ADC_Exported_Constants ADC Exported Constants
  * @{
  */

/** @defgroup ADC_Error_Code ADC Error Code
  * @{
  */
#define HAL_ADC_ERROR_NONE                0x00U   /*!< No error                                              */
#define HAL_ADC_ERROR_INTERNAL            0x01U   /*!< ADC IP internal error: if problem of clocking, 
                                                       enable/disable, erroneous state                       */
#define HAL_ADC_ERROR_OVR                 0x02U   /*!< Overrun error                                         */
#define HAL_ADC_ERROR_DMA                 0x04U   /*!< DMA transfer error                                    */

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
#define HAL_ADC_ERROR_INVALID_CALLBACK  (0x10U)   /*!< Invalid Callback error */
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
/**
  * @}
  */


/** @defgroup ADC_Data_align ADC data alignment
  * @{
  */
#define ADC_DATAALIGN_RIGHT      0x00000000U
#define ADC_DATAALIGN_LEFT       ((uint32_t)ADC_CR2_ALIGN)
/**
  * @}
  */

/** @defgroup ADC_Scan_mode ADC scan mode
  * @{
  */
/* Note: Scan mode values are not among binary choices ENABLE/DISABLE for     */
/*       compatibility with other STM32 devices having a sequencer with       */
/*       additional options.                                                  */
#define ADC_SCAN_DISABLE         0x00000000U
#define ADC_SCAN_ENABLE          ((uint32_t)ADC_CR1_SCAN)
/**
  * @}
  */

/** @defgroup ADC_External_trigger_edge_Regular ADC external trigger enable for regular group
  * @{
  */
#define ADC_EXTERNALTRIGCONVEDGE_NONE           0x00000000U
#define ADC_EXTERNALTRIGCONVEDGE_RISING         ((uint32_t)ADC_CR2_EXTTRIG)
/**
  * @}
  */
