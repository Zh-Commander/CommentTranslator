/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc.c
  * @author  MCD Application Team
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Analog to Digital Convertor (ADC)
  *          peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *           + Peripheral State functions
  *          Other functions (extended functions) are available in file 
  *          "stm32f1xx_hal_adc_ex.c".
  *
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
  @verbatim
  ==============================================================================
                     ##### ADC peripheral features #####
  ==============================================================================
  [..]
  (+) 12-bit resolution

  (+) Interrupt generation at the end of regular conversion, end of injected
      conversion, and in case of analog watchdog or overrun events.
  
  (+) Single and continuous conversion modes.
  
  (+) Scan mode for conversion of several channels sequentially.
  
  (+) Data alignment with in-built data coherency.
  
  (+) Programmable sampling time (channel wise)
  
  (+) ADC conversion of regular group and injected group.

  (+) External trigger (timer or EXTI) 
      for both regular and injected groups.

  (+) DMA request generation for transfer of conversions data of regular group.

  (+) Multimode Dual mode (available on devices with 2 ADCs or more).
  
  (+) Configurable DMA data storage in Multimode Dual mode (available on devices
      with 2 DCs or more).
  
  (+) Configurable delay between conversions in Dual interleaved mode (available 
      on devices with 2 DCs or more).
  
  (+) ADC calibration

  (+) ADC supply requirements: 2.4 V to 3.6 V at full speed and down to 1.8 V at 
      slower speed.
  
  (+) ADC input range: from Vref- (connected to Vssa) to Vref+ (connected to 
      Vdda or to an external voltage reference).


                     ##### How to use this driver #####
  ==============================================================================
    [..]

     *** Configuration of top level parameters related to ADC ***
     ============================================================
     [..]

    (#) Enable the ADC interface
      (++) As prerequisite, ADC clock must be configured at RCC top level.
           Caution: On STM32F1, ADC clock frequency max is 14MHz (refer
                    to device datasheet).
                    Therefore, ADC clock prescaler must be configured in 
                    function of ADC clock source frequency to remain below
                    this maximum frequency.
        (++) One clock setting is mandatory:
             ADC clock (core clock, also possibly conversion clock).
             (+++) Example:
                   Into HAL_ADC_MspInit() (recommended code location) or with
                   other device clock parameters configuration:
               (+++) RCC_PeriphCLKInitTypeDef  PeriphClkInit;
               (+++) __ADC1_CLK_ENABLE();
               (+++) PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
               (+++) PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
               (+++) HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

    (#) ADC pins configuration
         (++) Enable the clock for the ADC GPIOs
              using macro __HAL_RCC_GPIOx_CLK_ENABLE()
         (++) Configure these ADC pins in analog mode
              using function HAL_GPIO_Init()

    (#) Optionally, in case of usage of ADC with interruptions:
         (++) Configure the NVIC for ADC
              using function HAL_NVIC_EnableIRQ(ADCx_IRQn)
         (++) Insert the ADC interruption handler function HAL_ADC_IRQHandler() 
              into the function of corresponding ADC interruption vector 
              ADCx_IRQHandler().

    (#) Optionally, in case of usage of DMA:
         (++) Configure the DMA (DMA channel, mode normal or circular, ...)
              using function HAL_DMA_Init().
         (++) Configure the NVIC for DMA
              using function HAL_NVIC_EnableIRQ(DMAx_Channelx_IRQn)
         (++) Insert the ADC interruption handler function HAL_ADC_IRQHandler() 
              into the function of corresponding DMA interruption vector 
              DMAx_Channelx_IRQHandler().

     *** Configuration of ADC, groups regular/injected, channels parameters ***
     ==========================================================================
     [..]

    (#) Configure the ADC parameters (resolution, data alignment, ...)
        and regular group parameters (conversion trigger, sequencer, ...)
        using function HAL_ADC_Init().

    (#) Configure the channels for regular group parameters (channel number, 
        channel rank into sequencer, ..., into regular group)
        using function HAL_ADC_ConfigChannel().

    (#) Optionally, configure the injected group parameters (conversion trigger, 
        sequencer, ..., of injected group)
        and the channels for injected group parameters (channel number, 
        channel rank into sequencer, ..., into injected group)
        using function HAL_ADCEx_InjectedConfigChannel().

    (#) Optionally, configure the analog watchdog parameters (channels
        monitored, thresholds, ...)
        using function HAL_ADC_AnalogWDGConfig().

    (#) Optionally, for devices with several ADC instances: configure the 
        multimode parameters
        using function HAL_ADCEx_MultiModeConfigChannel().

     *** Execution of ADC conversions ***
     ====================================
     [..]

    (#) Optionally, perform an automatic ADC calibration to improve the
        conversion accuracy
        using function HAL_ADCEx_Calibration_Start().

    (#) ADC driver can be used among three modes: polling, interruption,
        transfer by DMA.

        (++) ADC conversion by polling:
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start()
          (+++) Wait for ADC conversion completion 
                using function HAL_ADC_PollForConversion()
                (or for injected group: HAL_ADCEx_InjectedPollForConversion() )
          (+++) Retrieve conversion results 
                using function HAL_ADC_GetValue()
                (or for injected group: HAL_ADCEx_InjectedGetValue() )
          (+++) Stop conversion and disable the ADC peripheral 
                using function HAL_ADC_Stop()

        (++) ADC conversion by interruption: 
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start_IT()
          (+++) Wait for ADC conversion completion by call of function
                HAL_ADC_ConvCpltCallback()
                (this function must be implemented in user program)
                (or for injected group: HAL_ADCEx_InjectedConvCpltCallback() )
          (+++) Retrieve conversion results 
                using function HAL_ADC_GetValue()
                (or for injected group: HAL_ADCEx_InjectedGetValue() )
          (+++) Stop conversion and disable the ADC peripheral 
                using function HAL_ADC_Stop_IT()

        (++) ADC conversion with transfer by DMA:
          (+++) Activate the ADC peripheral and start conversions
                using function HAL_ADC_Start_DMA()
          (+++) Wait for ADC conversion completion by call of function
                HAL_ADC_ConvCpltCallback() or HAL_ADC_ConvHalfCpltCallback()
                (these functions must be implemented in user program)
          (+++) Conversion results are automatically transferred by DMA into
                destination variable address.
          (+++) Stop conversion and disable the ADC peripheral 
                using function HAL_ADC_Stop_DMA()

        (++) For devices with several ADCs: ADC multimode conversion 
             with transfer by DMA:
          (+++) Activate the ADC peripheral (slave) and start conversions
                using function HAL_ADC_Start()
          (+++) Activate the ADC peripheral (master) and start conversions
                using function HAL_ADCEx_MultiModeStart_DMA()
          (+++) Wait for ADC conversion completion by call of function
                HAL_ADC_ConvCpltCallback() or HAL_ADC_ConvHalfCpltCallback()
                (these functions must be implemented in user program)
          (+++) Conversion results are automatically transferred by DMA into
                destination variable address.
          (+++) Stop conversion and disable the ADC peripheral (master)
                using function HAL_ADCEx_MultiModeStop_DMA()
          (+++) Stop conversion and disable the ADC peripheral (slave)
                using function HAL_ADC_Stop_IT()

     [..]

    (@) Callback functions must be implemented in user program:
      (+@) HAL_ADC_ErrorCallback()
      (+@) HAL_ADC_LevelOutOfWindowCallback() (callback of analog watchdog)
      (+@) HAL_ADC_ConvCpltCallback()
      (+@) HAL_ADC_ConvHalfCpltCallback
      (+@) HAL_ADCEx_InjectedConvCpltCallback()

     *** Deinitialization of ADC ***
     ============================================================
     [..]

    (#) Disable the ADC interface
      (++) ADC clock can be hard reset and disabled at RCC top level.
        (++) Hard reset of ADC peripherals
             using macro __ADCx_FORCE_RESET(), __ADCx_RELEASE_RESET().
        (++) ADC clock disable
             using the equivalent macro/functions as configuration step.
             (+++) Example:
                   Into HAL_ADC_MspDeInit() (recommended code location) or with
                   other device clock parameters configuration:
               (+++) PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC
               (+++) PeriphClkInit.AdcClockSelection = RCC_ADCPLLCLK2_OFF
               (+++) HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit)

    (#) ADC pins configuration
         (++) Disable the clock for the ADC GPIOs
              using macro __HAL_RCC_GPIOx_CLK_DISABLE()

    (#) Optionally, in case of usage of ADC with interruptions:
         (++) Disable the NVIC for ADC
              using function HAL_NVIC_EnableIRQ(ADCx_IRQn)

    (#) Optionally, in case of usage of DMA:
         (++) Deinitialize the DMA
              using function HAL_DMA_Init().
         (++) Disable the NVIC for DMA
              using function HAL_NVIC_EnableIRQ(DMAx_Channelx_IRQn)

    [..]
    
    *** Callback registration ***
    =============================================
    [..]

     The compilation flag USE_HAL_ADC_REGISTER_CALLBACKS, when set to 1,
     allows the user to configure dynamically the driver callbacks.
     Use Functions HAL_ADC_RegisterCallback()
     to register an interrupt callback.
    [..]

     Function HAL_ADC_RegisterCallback() allows to register following callbacks:
       (+) ConvCpltCallback               : ADC conversion complete callback
       (+) ConvHalfCpltCallback           : ADC conversion DMA half-transfer callback
       (+) LevelOutOfWindowCallback       : ADC analog watchdog 1 callback
       (+) ErrorCallback                  : ADC error callback
       (+) InjectedConvCpltCallback       : ADC group injected conversion complete callback
       (+) MspInitCallback                : ADC Msp Init callback
       (+) MspDeInitCallback              : ADC Msp DeInit callback
     This function takes as parameters the HAL peripheral handle, the Callback ID
     and a pointer to the user callback function.
    [..]

     Use function HAL_ADC_UnRegisterCallback to reset a callback to the default
     weak function.
    [..]

     HAL_ADC_UnRegisterCallback takes as parameters the HAL peripheral handle,
     and the Callback ID.
     This function allows to reset following callbacks:
       (+) ConvCpltCallback               : ADC conversion complete callback
       (+) ConvHalfCpltCallback           : ADC conversion DMA half-transfer callback
       (+) LevelOutOfWindowCallback       : ADC analog watchdog 1 callback
       (+) ErrorCallback                  : ADC error callback
       (+) InjectedConvCpltCallback       : ADC group injected conversion complete callback
       (+) MspInitCallback                : ADC Msp Init callback
       (+) MspDeInitCallback              : ADC Msp DeInit callback
     [..]

     By default, after the HAL_ADC_Init() and when the state is HAL_ADC_STATE_RESET
     all callbacks are set to the corresponding weak functions:
     examples HAL_ADC_ConvCpltCallback(), HAL_ADC_ErrorCallback().
     Exception done for MspInit and MspDeInit functions that are
     reset to the legacy weak functions in the HAL_ADC_Init()/ HAL_ADC_DeInit() only when
     these callbacks are null (not registered beforehand).
    [..]

     If MspInit or MspDeInit are not null, the HAL_ADC_Init()/ HAL_ADC_DeInit()
     keep and use the user MspInit/MspDeInit callbacks (registered beforehand) whatever the state.
     [..]

     Callbacks can be registered/unregistered in HAL_ADC_STATE_READY state only.
     Exception done MspInit/MspDeInit functions that can be registered/unregistered
     in HAL_ADC_STATE_READY or HAL_ADC_STATE_RESET state,
     thus registered (user) MspInit/DeInit callbacks can be used during the Init/DeInit.
    [..]

     Then, the user first registers the MspInit/MspDeInit user callbacks
     using HAL_ADC_RegisterCallback() before calling HAL_ADC_DeInit()
     or HAL_ADC_Init() function.
     [..]

     When the compilation flag USE_HAL_ADC_REGISTER_CALLBACKS is set to 0 or
     not defined, the callback registration feature is not available and all callbacks
     are set to the corresponding weak functions.
  
  @endverbatim
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup ADC ADC
  * @brief ADC HAL module driver
  * @{
  */

#ifdef HAL_ADC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup ADC_Private_Constants ADC Private Constants
  * @{
  */

  /* Timeout values for ADC enable and disable settling time.                 */
  /* Values defined to be higher than worst cases: low clocks freq,           */
  /* maximum prescaler.                                                       */
  /* Ex of profile low frequency : Clock source at 0.1 MHz, ADC clock         */
  /* prescaler 4, sampling time 12.5 ADC clock cycles, resolution 12 bits.    */
  /* Unit: ms                                                                 */
  #define ADC_ENABLE_TIMEOUT              2U
  #define ADC_DISABLE_TIMEOUT             2U

  /* Delay for ADC stabilization time.                                        */
  /* Maximum delay is 1us (refer to device datasheet, parameter tSTAB).       */
  /* Unit: us                                                                 */
  #define ADC_STAB_DELAY_US               1U

  /* Delay for temperature sensor stabilization time.                         */
  /* Maximum delay is 10us (refer to device datasheet, parameter tSTART).     */
  /* Unit: us                                                                 */
  #define ADC_TEMPSENSOR_DELAY_US         10U

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @{
  */

/** @defgroup ADC_Exported_Functions_Group1 Initialization/de-initialization functions 
  * @brief    Initialization and Configuration functions
  *
@verbatim    
 ===============================================================================
              ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Initialize and configure the ADC. 
      (+) De-initialize the ADC.

@endverbatim
  * @{
  */

/**
  * @brief  Initializes the ADC peripheral and regular group according to  
  *         parameters specified in structure "ADC_InitTypeDef".
  * @note   As prerequisite, ADC clock must be configured at RCC top level
  *         (clock source APB2).
  *         See commented example code below that can be copied and uncommented 
  *         into HAL_ADC_MspInit().
  * @note   Possibility to update parameters on the fly:
  *         This function initializes the ADC MSP (HAL_ADC_MspInit()) only when
  *         coming from ADC state reset. Following calls to this function can
  *         be used to reconfigure some parameters of ADC_InitTypeDef  
  *         structure on the fly, without modifying MSP configuration. If ADC  
  *         MSP has to be modified again, HAL_ADC_DeInit() must be called
  *         before HAL_ADC_Init().
  *         The setting of these parameters is conditioned to ADC state.
  *         For parameters constraints, see comments of structure 
  *         "ADC_InitTypeDef".
  * @note   This function configures the ADC within 2 scopes: scope of entire 
  *         ADC and scope of regular group. For parameters details, see comments 
  *         of structure "ADC_InitTypeDef".
  * @param  hadc: ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  uint32_t tmp_cr1 = 0U;
  uint32_t tmp_cr2 = 0U;
  uint32_t tmp_sqr1 = 0U;
  
  /* Check ADC handle */
  if(hadc == NULL)
  {
    return HAL_ERROR;
  }
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_DATA_ALIGN(hadc->Init.DataAlign));
  assert_param(IS_ADC_SCAN_MODE(hadc->Init.ScanConvMode));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  assert_param(IS_ADC_EXTTRIG(hadc->Init.ExternalTrigConv));
  
  if(hadc->Init.ScanConvMode != ADC_SCAN_DISABLE)
  {
    assert_param(IS_ADC_REGULAR_NB_CONV(hadc->Init.NbrOfConversion));
    assert_param(IS_FUNCTIONAL_STATE(hadc->Init.DiscontinuousConvMode));
    if(hadc->Init.DiscontinuousConvMode != DISABLE)
    {
      assert_param(IS_ADC_REGULAR_DISCONT_NUMBER(hadc->Init.NbrOfDiscConversion));
    }
  }
  
  /* As prerequisite, into HAL_ADC_MspInit(), ADC clock must be configured    */
  /* at RCC top level.                                                        */
  /* Refer to header of this file for more details on clock enabling          */
  /* procedure.                                                               */

  /* Actions performed only if ADC is coming from state reset:                */
  /* - Initialization of ADC MSP                                              */
  if (hadc->State == HAL_ADC_STATE_RESET)
  {
    /* Initialize ADC error code */
    ADC_CLEAR_ERRORCODE(hadc);
    
    /* Allocate lock resource and initialize it */
    hadc->Lock = HAL_UNLOCKED;
