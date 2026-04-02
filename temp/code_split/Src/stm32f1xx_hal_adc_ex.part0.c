/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc_ex.c
  * @author  MCD Application Team
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the Analog to Digital Convertor (ADC)
  *          peripheral:
  *           + Peripheral Control functions
  *          Other functions (generic functions) are available in file 
  *          "stm32f1xx_hal_adc.c".
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
  [..] 
  (@) Sections "ADC peripheral features" and "How to use this driver" are
      available in file of generic functions "stm32f1xx_hal_adc.c".
  [..]
  @endverbatim
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup ADCEx ADCEx
  * @brief ADC Extension HAL module driver
  * @{
  */

#ifdef HAL_ADC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup ADCEx_Private_Constants ADCEx Private Constants
  * @{
  */

  /* Delay for ADC calibration:                                               */
  /* Hardware prerequisite before starting a calibration: the ADC must have   */
  /* been in power-on state for at least two ADC clock cycles.                */
  /* Unit: ADC clock cycles                                                   */
  #define ADC_PRECALIBRATION_DELAY_ADCCLOCKCYCLES       2U

  /* Timeout value for ADC calibration                                        */
  /* Value defined to be higher than worst cases: low clocks freq,            */
  /* maximum prescaler.                                                       */
  /* Ex of profile low frequency : Clock source at 0.1 MHz, ADC clock         */
  /* prescaler 4, sampling time 12.5 ADC clock cycles, resolution 12 bits.    */
  /* Unit: ms                                                                 */
  #define ADC_CALIBRATION_TIMEOUT          10U

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
/* Private functions ---------------------------------------------------------*/

/** @defgroup ADCEx_Exported_Functions ADCEx Exported Functions
  * @{
  */

/** @defgroup ADCEx_Exported_Functions_Group1 Extended Extended IO operation functions
 *  @brief    Extended Extended Input and Output operation functions
 *
@verbatim    
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Start conversion of injected group.
      (+) Stop conversion of injected group.
      (+) Poll for conversion complete on injected group.
      (+) Get result of injected channel conversion.
      (+) Start conversion of injected group and enable interruptions.
      (+) Stop conversion of injected group and disable interruptions.

      (+) Start multimode and enable DMA transfer.
      (+) Stop multimode and disable ADC DMA transfer.
      (+) Get result of multimode conversion.

      (+) Perform the ADC self-calibration for single or differential ending.
      (+) Get calibration factors for single or differential ending.
      (+) Set calibration factors for single or differential ending.
      
@endverbatim
  * @{
  */

/**
  * @brief  Perform an ADC automatic self-calibration
  *         Calibration prerequisite: ADC must be disabled (execute this
  *         function before HAL_ADC_Start() or after HAL_ADC_Stop() ).
  *         During calibration process, ADC is enabled. ADC is let enabled at
  *         the completion of this function.
  * @param  hadc: ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  uint32_t tickstart;
  __IO uint32_t wait_loop_index = 0U;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Process locked */
  __HAL_LOCK(hadc);
    
   /* 1. Disable ADC peripheral                                                 */
   tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
   /* 2. Calibration prerequisite delay before starting the calibration.       */
   /*    - ADC must be enabled for at least two ADC clock cycles               */
   tmp_hal_status = ADC_Enable(hadc);

   /* Check if ADC is effectively enabled */
   if (tmp_hal_status == HAL_OK)
   {
     /* Set ADC state */
     ADC_STATE_CLR_SET(hadc->State,
                       HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                       HAL_ADC_STATE_BUSY_INTERNAL);
    
    /* Hardware prerequisite: delay before starting the calibration.          */
    /*  - Computation of CPU clock cycles corresponding to ADC clock cycles.  */
    /*  - Wait for the expected ADC clock cycles delay */
    wait_loop_index = ((SystemCoreClock
                        / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                       * ADC_PRECALIBRATION_DELAY_ADCCLOCKCYCLES        );

    while(wait_loop_index != 0U)
    {
      wait_loop_index--;
    }

    /* 3. Resets ADC calibration registers */  
    SET_BIT(hadc->Instance->CR2, ADC_CR2_RSTCAL);
    
    tickstart = HAL_GetTick();  

    /* Wait for calibration reset completion */
    while(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_RSTCAL))
    {
      if((HAL_GetTick() - tickstart) > ADC_CALIBRATION_TIMEOUT)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_RSTCAL))
        {
          /* Update ADC state machine to error */
          ADC_STATE_CLR_SET(hadc->State,
                            HAL_ADC_STATE_BUSY_INTERNAL,
                            HAL_ADC_STATE_ERROR_INTERNAL);

          /* Process unlocked */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR;
        }
      }
    }
    
    /* 4. Start ADC calibration */
    SET_BIT(hadc->Instance->CR2, ADC_CR2_CAL);
    
    tickstart = HAL_GetTick();  

    /* Wait for calibration completion */
    while(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_CAL))
    {
      if((HAL_GetTick() - tickstart) > ADC_CALIBRATION_TIMEOUT)
      {
        /* New check to avoid false timeout detection in case of preemption */
        if(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_CAL))
        {
          /* Update ADC state machine to error */
          ADC_STATE_CLR_SET(hadc->State,
                            HAL_ADC_STATE_BUSY_INTERNAL,
                            HAL_ADC_STATE_ERROR_INTERNAL);

          /* Process unlocked */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR;
        }
      }
    }
    
    /* Set ADC state */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_BUSY_INTERNAL,
                      HAL_ADC_STATE_READY);
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Enables ADC, starts conversion of injected group.
  *         Interruptions enabled in this function: None.
  * @param  hadc: ADC handle
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Process locked */
  __HAL_LOCK(hadc);
    
  /* Enable the ADC peripheral */
  tmp_hal_status = ADC_Enable(hadc);
  
  /* Start conversion if ADC is effectively enabled */
  if (tmp_hal_status == HAL_OK)
  {
    /* Set ADC state                                                          */
    /* - Clear state bitfield related to injected group conversion results    */
    /* - Set state bitfield related to injected operation                     */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_INJ_EOC,
                      HAL_ADC_STATE_INJ_BUSY);
    
    /* Case of independent mode or multimode (for devices with several ADCs): */
    /* Set multimode state.                                                   */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    else
    {
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    
    /* Check if a regular conversion is ongoing */
    /* Note: On this device, there is no ADC error code fields related to     */
    /*       conversions on group injected only. In case of conversion on     */
    /*       going on group regular, no error code is reset.                  */
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
    {
      /* Reset ADC all error code fields */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* Process unlocked */
    /* Unlock before starting ADC conversions: in case of potential           */
    /* interruption, to let the process to ADC IRQ Handler.                   */
    __HAL_UNLOCK(hadc);
    
    /* Clear injected group conversion flag */
    /* (To ensure of no unknown state from potential previous ADC operations) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JEOC);
        
    /* Enable conversion of injected group.                                   */
    /* If software start has been selected, conversion starts immediately.    */
    /* If external trigger has been selected, conversion will start at next   */
    /* trigger event.                                                         */
    /* If automatic injected conversion is enabled, conversion will start     */
    /* after next regular group conversion.                                   */
    /* Case of multimode enabled (for devices with several ADCs): if ADC is   */
    /* slave, ADC is enabled only (conversion is not started). If ADC is      */
    /* master, ADC is enabled and conversion is started.                      */
    if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO))
    {
      if (ADC_IS_SOFTWARE_START_INJECTED(hadc)     &&
          ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
      {
        /* Start ADC conversion on injected group with SW start */
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
      }
      else
      {
        /* Start ADC conversion on injected group with external trigger */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_JEXTTRIG);
      }
    }
  }
  else
  {
    /* Process unlocked */
    __HAL_UNLOCK(hadc);
  }
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Stop conversion of injected channels. Disable ADC peripheral if
  *         no regular conversion is on going.
  * @note   If ADC must be disabled and if conversion is on going on 
  *         regular group, function HAL_ADC_Stop must be used to stop both
  *         injected and regular groups, and disable the ADC.
  * @note   If injected group mode auto-injection is enabled,
  *         function HAL_ADC_Stop must be used.
  * @note   In case of auto-injection mode, HAL_ADC_Stop must be used.
  * @param  hadc: ADC handle
  * @retval None
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Process locked */
  __HAL_LOCK(hadc);
    
  /* Stop potential conversion and disable ADC peripheral                     */
  /* Conditioned to:                                                          */
  /* - No conversion on the other group (regular group) is intended to        */
  /*   continue (injected and regular groups stop conversion and ADC disable  */
  /*   are common)                                                            */
  /* - In case of auto-injection mode, HAL_ADC_Stop must be used.             */
  if(((hadc->State & HAL_ADC_STATE_REG_BUSY) == RESET)  &&
     HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO)   )
  {
    /* Stop potential conversion on going, on regular and injected groups */
    /* Disable ADC peripheral */
    tmp_hal_status = ADC_ConversionStop_Disable(hadc);
    
    /* Check if ADC is effectively disabled */
    if (tmp_hal_status == HAL_OK)
    {
      /* Set ADC state */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }
  else
  {
    /* Update ADC state machine to error */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
    tmp_hal_status = HAL_ERROR;
  }
  
  /* Process unlocked */
  __HAL_UNLOCK(hadc);
  
  /* Return function status */
  return tmp_hal_status;
}

/**
  * @brief  Wait for injected group conversion to be completed.
  * @param  hadc: ADC handle
  * @param  Timeout: Timeout value in millisecond.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout)
{
  uint32_t tickstart;

  /* Variables for polling in case of scan mode enabled and polling for each  */
  /* conversion.                                                              */
  __IO uint32_t Conversion_Timeout_CPU_cycles = 0U;
  uint32_t Conversion_Timeout_CPU_cycles_max = 0U;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* Get timeout */
  tickstart = HAL_GetTick();  
     
  /* Polling for end of conversion: differentiation if single/sequence        */
  /* conversion.                                                              */
  /* For injected group, flag JEOC is set only at the end of the sequence,    */
  /* not for each conversion within the sequence.                             */
  /*  - If single conversion for injected group (scan mode disabled or        */
  /*    InjectedNbrOfConversion ==1), flag JEOC is used to determine the      */
  /*    conversion completion.                                                */
  /*  - If sequence conversion for injected group (scan mode enabled and      */
  /*    InjectedNbrOfConversion >=2), flag JEOC is set only at the end of the */
  /*    sequence.                                                             */
  /*    To poll for each conversion, the maximum conversion time is computed  */
  /*    from ADC conversion time (selected sampling time + conversion time of */
  /*    12.5 ADC clock cycles) and APB2/ADC clock prescalers (depending on    */
  /*    settings, conversion time range can be from 28 to 32256 CPU cycles).  */
  /*    As flag JEOC is not set after each conversion, no timeout status can  */
  /*    be set.                                                               */
  if ((hadc->Instance->JSQR & ADC_JSQR_JL) == RESET)
  {
    /* Wait until End of Conversion flag is raised */
    while(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_JEOC))
    {
      /* Check if timeout is disabled (set to infinite wait) */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
        {
          /* New check to avoid false timeout detection in case of preemption */
          if(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_JEOC))
          {
            /* Update ADC state machine to timeout */
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            /* Process unlocked */
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  else
  {
    /* Replace polling by wait for maximum conversion time */
    /*  - Computation of CPU clock cycles corresponding to ADC clock cycles   */
    /*    and ADC maximum conversion cycles on all channels.                  */
    /*  - Wait for the expected ADC clock cycles delay                        */
    Conversion_Timeout_CPU_cycles_max = ((SystemCoreClock
                                          / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                                         * ADC_CONVCYCLES_MAX_RANGE(hadc)                 );
    
    while(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
    {
      /* Check if timeout is disabled (set to infinite wait) */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout))
        {
          /* New check to avoid false timeout detection in case of preemption */
          if(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
          {
            /* Update ADC state machine to timeout */
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            /* Process unlocked */
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT;
          }
        }
      }
      Conversion_Timeout_CPU_cycles ++;
    }
  }

  /* Clear injected group conversion flag */
  /* Note: On STM32F1 ADC, clear regular conversion flag raised               */
  /* simultaneously.                                                          */
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JSTRT | ADC_FLAG_JEOC | ADC_FLAG_EOC);
  
  /* Update ADC state machine */
  SET_BIT(hadc->State, HAL_ADC_STATE_INJ_EOC);
  
  /* Determine whether any further conversion upcoming on group injected      */
  /* by external trigger or by automatic injected conversion                  */
  /* from group regular.                                                      */
  if(ADC_IS_SOFTWARE_START_INJECTED(hadc)                     || 
     (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO) &&     
     (ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&
      (hadc->Init.ContinuousConvMode == DISABLE)   )        )   )
  {
    /* Set ADC state */
    CLEAR_BIT(hadc->State, HAL_ADC_STATE_INJ_BUSY);   
    
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
    {
      SET_BIT(hadc->State, HAL_ADC_STATE_READY);
    }
  }
  
  /* Return ADC state */
  return HAL_OK;
}

/**
  * @brief  Enables ADC, starts conversion of injected group with interruption.
  *          - JEOC (end of conversion of injected group)
  *         Each of these interruptions has its dedicated callback function.
  * @param  hadc: ADC handle
  * @retval HAL status.
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* Process locked */
  __HAL_LOCK(hadc);
    
  /* Enable the ADC peripheral */
  tmp_hal_status = ADC_Enable(hadc);
