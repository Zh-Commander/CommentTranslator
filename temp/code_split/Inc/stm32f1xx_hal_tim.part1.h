
#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
  void (* Base_MspInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM Base Msp Init Callback                              */
  void (* Base_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);            /*!< TIM Base Msp DeInit Callback                            */
  void (* IC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM IC Msp Init Callback                                */
  void (* IC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM IC Msp DeInit Callback                              */
  void (* OC_MspInitCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM OC Msp Init Callback                                */
  void (* OC_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);              /*!< TIM OC Msp DeInit Callback                              */
  void (* PWM_MspInitCallback)(struct __TIM_HandleTypeDef *htim);               /*!< TIM PWM Msp Init Callback                               */
  void (* PWM_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);             /*!< TIM PWM Msp DeInit Callback                             */
  void (* OnePulse_MspInitCallback)(struct __TIM_HandleTypeDef *htim);          /*!< TIM One Pulse Msp Init Callback                         */
  void (* OnePulse_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM One Pulse Msp DeInit Callback                       */
  void (* Encoder_MspInitCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Encoder Msp Init Callback                           */
  void (* Encoder_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);         /*!< TIM Encoder Msp DeInit Callback                         */
  void (* HallSensor_MspInitCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM Hall Sensor Msp Init Callback                       */
  void (* HallSensor_MspDeInitCallback)(struct __TIM_HandleTypeDef *htim);      /*!< TIM Hall Sensor Msp DeInit Callback                     */
  void (* PeriodElapsedCallback)(struct __TIM_HandleTypeDef *htim);             /*!< TIM Period Elapsed Callback                             */
  void (* PeriodElapsedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);     /*!< TIM Period Elapsed half complete Callback               */
  void (* TriggerCallback)(struct __TIM_HandleTypeDef *htim);                   /*!< TIM Trigger Callback                                    */
  void (* TriggerHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Trigger half complete Callback                      */
  void (* IC_CaptureCallback)(struct __TIM_HandleTypeDef *htim);                /*!< TIM Input Capture Callback                              */
  void (* IC_CaptureHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);        /*!< TIM Input Capture half complete Callback                */
  void (* OC_DelayElapsedCallback)(struct __TIM_HandleTypeDef *htim);           /*!< TIM Output Compare Delay Elapsed Callback               */
  void (* PWM_PulseFinishedCallback)(struct __TIM_HandleTypeDef *htim);         /*!< TIM PWM Pulse Finished Callback                         */
  void (* PWM_PulseFinishedHalfCpltCallback)(struct __TIM_HandleTypeDef *htim); /*!< TIM PWM Pulse Finished half complete Callback           */
  void (* ErrorCallback)(struct __TIM_HandleTypeDef *htim);                     /*!< TIM Error Callback                                      */
  void (* CommutationCallback)(struct __TIM_HandleTypeDef *htim);               /*!< TIM Commutation Callback                                */
  void (* CommutationHalfCpltCallback)(struct __TIM_HandleTypeDef *htim);       /*!< TIM Commutation half complete Callback                  */
  void (* BreakCallback)(struct __TIM_HandleTypeDef *htim);                     /*!< TIM Break Callback                                      */
#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */
} TIM_HandleTypeDef;

#if (USE_HAL_TIM_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL TIM Callback ID enumeration definition
  */
typedef enum
{
  HAL_TIM_BASE_MSPINIT_CB_ID              = 0x00U   /*!< TIM Base MspInit Callback ID                               */
  , HAL_TIM_BASE_MSPDEINIT_CB_ID          = 0x01U   /*!< TIM Base MspDeInit Callback ID                             */
  , HAL_TIM_IC_MSPINIT_CB_ID              = 0x02U   /*!< TIM IC MspInit Callback ID                                 */
  , HAL_TIM_IC_MSPDEINIT_CB_ID            = 0x03U   /*!< TIM IC MspDeInit Callback ID                               */
  , HAL_TIM_OC_MSPINIT_CB_ID              = 0x04U   /*!< TIM OC MspInit Callback ID                                 */
  , HAL_TIM_OC_MSPDEINIT_CB_ID            = 0x05U   /*!< TIM OC MspDeInit Callback ID                               */
  , HAL_TIM_PWM_MSPINIT_CB_ID             = 0x06U   /*!< TIM PWM MspInit Callback ID                                */
  , HAL_TIM_PWM_MSPDEINIT_CB_ID           = 0x07U   /*!< TIM PWM MspDeInit Callback ID                              */
  , HAL_TIM_ONE_PULSE_MSPINIT_CB_ID       = 0x08U   /*!< TIM One Pulse MspInit Callback ID                          */
  , HAL_TIM_ONE_PULSE_MSPDEINIT_CB_ID     = 0x09U   /*!< TIM One Pulse MspDeInit Callback ID                        */
  , HAL_TIM_ENCODER_MSPINIT_CB_ID         = 0x0AU   /*!< TIM Encoder MspInit Callback ID                            */
  , HAL_TIM_ENCODER_MSPDEINIT_CB_ID       = 0x0BU   /*!< TIM Encoder MspDeInit Callback ID                          */
  , HAL_TIM_HALL_SENSOR_MSPINIT_CB_ID     = 0x0CU   /*!< TIM Hall Sensor MspDeInit Callback ID                      */
  , HAL_TIM_HALL_SENSOR_MSPDEINIT_CB_ID   = 0x0DU   /*!< TIM Hall Sensor MspDeInit Callback ID                      */
  , HAL_TIM_PERIOD_ELAPSED_CB_ID          = 0x0EU   /*!< TIM Period Elapsed Callback ID                             */
  , HAL_TIM_PERIOD_ELAPSED_HALF_CB_ID     = 0x0FU   /*!< TIM Period Elapsed half complete Callback ID               */
  , HAL_TIM_TRIGGER_CB_ID                 = 0x10U   /*!< TIM Trigger Callback ID                                    */
  , HAL_TIM_TRIGGER_HALF_CB_ID            = 0x11U   /*!< TIM Trigger half complete Callback ID                      */
  , HAL_TIM_IC_CAPTURE_CB_ID              = 0x12U   /*!< TIM Input Capture Callback ID                              */
  , HAL_TIM_IC_CAPTURE_HALF_CB_ID         = 0x13U   /*!< TIM Input Capture half complete Callback ID                */
  , HAL_TIM_OC_DELAY_ELAPSED_CB_ID        = 0x14U   /*!< TIM Output Compare Delay Elapsed Callback ID               */
  , HAL_TIM_PWM_PULSE_FINISHED_CB_ID      = 0x15U   /*!< TIM PWM Pulse Finished Callback ID                         */
  , HAL_TIM_PWM_PULSE_FINISHED_HALF_CB_ID = 0x16U   /*!< TIM PWM Pulse Finished half complete Callback ID           */
  , HAL_TIM_ERROR_CB_ID                   = 0x17U   /*!< TIM Error Callback ID                                      */
  , HAL_TIM_COMMUTATION_CB_ID             = 0x18U   /*!< TIM Commutation Callback ID                                */
  , HAL_TIM_COMMUTATION_HALF_CB_ID        = 0x19U   /*!< TIM Commutation half complete Callback ID                  */
  , HAL_TIM_BREAK_CB_ID                   = 0x1AU   /*!< TIM Break Callback ID                                      */
} HAL_TIM_CallbackIDTypeDef;

/**
  * @brief  HAL TIM Callback pointer definition
  */
typedef  void (*pTIM_CallbackTypeDef)(TIM_HandleTypeDef *htim);  /*!< pointer to the TIM callback function */

#endif /* USE_HAL_TIM_REGISTER_CALLBACKS */

/**
  * @}
  */
/* End of exported types -----------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup TIM_Exported_Constants TIM Exported Constants
  * @{
  */

/** @defgroup TIM_ClearInput_Source TIM Clear Input Source
  * @{
  */
#define TIM_CLEARINPUTSOURCE_NONE           0x00000000U   /*!< OCREF_CLR is disabled */
#define TIM_CLEARINPUTSOURCE_ETR            0x00000001U   /*!< OCREF_CLR is connected to ETRF input */
/**
  * @}
  */

/** @defgroup TIM_DMA_Base_address TIM DMA Base Address
  * @{
  */
#define TIM_DMABASE_CR1                    0x00000000U
#define TIM_DMABASE_CR2                    0x00000001U
#define TIM_DMABASE_SMCR                   0x00000002U
#define TIM_DMABASE_DIER                   0x00000003U
#define TIM_DMABASE_SR                     0x00000004U
#define TIM_DMABASE_EGR                    0x00000005U
#define TIM_DMABASE_CCMR1                  0x00000006U
#define TIM_DMABASE_CCMR2                  0x00000007U
#define TIM_DMABASE_CCER                   0x00000008U
#define TIM_DMABASE_CNT                    0x00000009U
#define TIM_DMABASE_PSC                    0x0000000AU
#define TIM_DMABASE_ARR                    0x0000000BU
#define TIM_DMABASE_RCR                    0x0000000CU
#define TIM_DMABASE_CCR1                   0x0000000DU
#define TIM_DMABASE_CCR2                   0x0000000EU
#define TIM_DMABASE_CCR3                   0x0000000FU
#define TIM_DMABASE_CCR4                   0x00000010U
#define TIM_DMABASE_BDTR                   0x00000011U
#define TIM_DMABASE_DCR                    0x00000012U
#define TIM_DMABASE_DMAR                   0x00000013U
/**
  * @}
  */

/** @defgroup TIM_Event_Source TIM Event Source
  * @{
  */
#define TIM_EVENTSOURCE_UPDATE              TIM_EGR_UG     /*!< Reinitialize the counter and generates an update of the registers */
#define TIM_EVENTSOURCE_CC1                 TIM_EGR_CC1G   /*!< A capture/compare event is generated on channel 1 */
#define TIM_EVENTSOURCE_CC2                 TIM_EGR_CC2G   /*!< A capture/compare event is generated on channel 2 */
#define TIM_EVENTSOURCE_CC3                 TIM_EGR_CC3G   /*!< A capture/compare event is generated on channel 3 */
#define TIM_EVENTSOURCE_CC4                 TIM_EGR_CC4G   /*!< A capture/compare event is generated on channel 4 */
#define TIM_EVENTSOURCE_COM                 TIM_EGR_COMG   /*!< A commutation event is generated */
#define TIM_EVENTSOURCE_TRIGGER             TIM_EGR_TG     /*!< A trigger event is generated */
#define TIM_EVENTSOURCE_BREAK               TIM_EGR_BG     /*!< A break event is generated */
/**
  * @}
  */

/** @defgroup TIM_Input_Channel_Polarity TIM Input Channel polarity
  * @{
  */
#define  TIM_INPUTCHANNELPOLARITY_RISING      0x00000000U                       /*!< Polarity for TIx source */
#define  TIM_INPUTCHANNELPOLARITY_FALLING     TIM_CCER_CC1P                     /*!< Polarity for TIx source */
#define  TIM_INPUTCHANNELPOLARITY_BOTHEDGE    (TIM_CCER_CC1P | TIM_CCER_CC1NP)  /*!< Polarity for TIx source */
/**
  * @}
  */

/** @defgroup TIM_ETR_Polarity TIM ETR Polarity
  * @{
  */
#define TIM_ETRPOLARITY_INVERTED              TIM_SMCR_ETP                      /*!< Polarity for ETR source */
#define TIM_ETRPOLARITY_NONINVERTED           0x00000000U                       /*!< Polarity for ETR source */
/**
  * @}
  */

/** @defgroup TIM_ETR_Prescaler TIM ETR Prescaler
  * @{
  */
#define TIM_ETRPRESCALER_DIV1                 0x00000000U                       /*!< No prescaler is used */
#define TIM_ETRPRESCALER_DIV2                 TIM_SMCR_ETPS_0                   /*!< ETR input source is divided by 2 */
#define TIM_ETRPRESCALER_DIV4                 TIM_SMCR_ETPS_1                   /*!< ETR input source is divided by 4 */
#define TIM_ETRPRESCALER_DIV8                 TIM_SMCR_ETPS                     /*!< ETR input source is divided by 8 */
/**
  * @}
  */

/** @defgroup TIM_Counter_Mode TIM Counter Mode
  * @{
  */
#define TIM_COUNTERMODE_UP                 0x00000000U                          /*!< Counter used as up-counter   */
#define TIM_COUNTERMODE_DOWN               TIM_CR1_DIR                          /*!< Counter used as down-counter */
#define TIM_COUNTERMODE_CENTERALIGNED1     TIM_CR1_CMS_0                        /*!< Center-aligned mode 1        */
#define TIM_COUNTERMODE_CENTERALIGNED2     TIM_CR1_CMS_1                        /*!< Center-aligned mode 2        */
#define TIM_COUNTERMODE_CENTERALIGNED3     TIM_CR1_CMS                          /*!< Center-aligned mode 3        */
/**
  * @}
  */

/** @defgroup TIM_ClockDivision TIM Clock Division
  * @{
  */
#define TIM_CLOCKDIVISION_DIV1             0x00000000U                          /*!< Clock division: tDTS=tCK_INT   */
#define TIM_CLOCKDIVISION_DIV2             TIM_CR1_CKD_0                        /*!< Clock division: tDTS=2*tCK_INT */
#define TIM_CLOCKDIVISION_DIV4             TIM_CR1_CKD_1                        /*!< Clock division: tDTS=4*tCK_INT */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_State TIM Output Compare State
  * @{
  */
#define TIM_OUTPUTSTATE_DISABLE            0x00000000U                          /*!< Capture/Compare 1 output disabled */
#define TIM_OUTPUTSTATE_ENABLE             TIM_CCER_CC1E                        /*!< Capture/Compare 1 output enabled */
/**
  * @}
  */

/** @defgroup TIM_AutoReloadPreload TIM Auto-Reload Preload
  * @{
  */
#define TIM_AUTORELOAD_PRELOAD_DISABLE                0x00000000U               /*!< TIMx_ARR register is not buffered */
#define TIM_AUTORELOAD_PRELOAD_ENABLE                 TIM_CR1_ARPE              /*!< TIMx_ARR register is buffered */

/**
  * @}
  */

/** @defgroup TIM_Output_Fast_State TIM Output Fast State
  * @{
  */
#define TIM_OCFAST_DISABLE                 0x00000000U                          /*!< Output Compare fast disable */
#define TIM_OCFAST_ENABLE                  TIM_CCMR1_OC1FE                      /*!< Output Compare fast enable  */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_State TIM Complementary Output Compare State
  * @{
  */
#define TIM_OUTPUTNSTATE_DISABLE           0x00000000U                          /*!< OCxN is disabled  */
#define TIM_OUTPUTNSTATE_ENABLE            TIM_CCER_CC1NE                       /*!< OCxN is enabled   */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Polarity TIM Output Compare Polarity
  * @{
  */
#define TIM_OCPOLARITY_HIGH                0x00000000U                          /*!< Capture/Compare output polarity  */
#define TIM_OCPOLARITY_LOW                 TIM_CCER_CC1P                        /*!< Capture/Compare output polarity  */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Polarity TIM Complementary Output Compare Polarity
  * @{
  */
#define TIM_OCNPOLARITY_HIGH               0x00000000U                          /*!< Capture/Compare complementary output polarity */
#define TIM_OCNPOLARITY_LOW                TIM_CCER_CC1NP                       /*!< Capture/Compare complementary output polarity */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_Idle_State TIM Output Compare Idle State
  * @{
  */
#define TIM_OCIDLESTATE_SET                TIM_CR2_OIS1                         /*!< Output Idle state: OCx=1 when MOE=0 */
#define TIM_OCIDLESTATE_RESET              0x00000000U                          /*!< Output Idle state: OCx=0 when MOE=0 */
/**
  * @}
  */

/** @defgroup TIM_Output_Compare_N_Idle_State TIM Complementary Output Compare Idle State
  * @{
  */
#define TIM_OCNIDLESTATE_SET               TIM_CR2_OIS1N                        /*!< Complementary output Idle state: OCxN=1 when MOE=0 */
#define TIM_OCNIDLESTATE_RESET             0x00000000U                          /*!< Complementary output Idle state: OCxN=0 when MOE=0 */
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Polarity TIM Input Capture Polarity
  * @{
  */
#define  TIM_ICPOLARITY_RISING             TIM_INPUTCHANNELPOLARITY_RISING      /*!< Capture triggered by rising edge on timer input                  */
#define  TIM_ICPOLARITY_FALLING            TIM_INPUTCHANNELPOLARITY_FALLING     /*!< Capture triggered by falling edge on timer input                 */
#define  TIM_ICPOLARITY_BOTHEDGE           TIM_INPUTCHANNELPOLARITY_BOTHEDGE    /*!< Capture triggered by both rising and falling edges on timer input*/
/**
  * @}
  */

/** @defgroup TIM_Encoder_Input_Polarity TIM Encoder Input Polarity
  * @{
  */
#define  TIM_ENCODERINPUTPOLARITY_RISING   TIM_INPUTCHANNELPOLARITY_RISING      /*!< Encoder input with rising edge polarity  */
#define  TIM_ENCODERINPUTPOLARITY_FALLING  TIM_INPUTCHANNELPOLARITY_FALLING     /*!< Encoder input with falling edge polarity */
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Selection TIM Input Capture Selection
  * @{
  */
#define TIM_ICSELECTION_DIRECTTI           TIM_CCMR1_CC1S_0                     /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to IC1, IC2, IC3 or IC4, respectively */
#define TIM_ICSELECTION_INDIRECTTI         TIM_CCMR1_CC1S_1                     /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to IC2, IC1, IC4 or IC3, respectively */
#define TIM_ICSELECTION_TRC                TIM_CCMR1_CC1S                       /*!< TIM Input 1, 2, 3 or 4 is selected to be connected to TRC */
/**
  * @}
  */

/** @defgroup TIM_Input_Capture_Prescaler TIM Input Capture Prescaler
  * @{
  */
#define TIM_ICPSC_DIV1                     0x00000000U                          /*!< Capture performed each time an edge is detected on the capture input */
#define TIM_ICPSC_DIV2                     TIM_CCMR1_IC1PSC_0                   /*!< Capture performed once every 2 events                                */
#define TIM_ICPSC_DIV4                     TIM_CCMR1_IC1PSC_1                   /*!< Capture performed once every 4 events                                */
#define TIM_ICPSC_DIV8                     TIM_CCMR1_IC1PSC                     /*!< Capture performed once every 8 events                                */
/**
  * @}
  */

/** @defgroup TIM_One_Pulse_Mode TIM One Pulse Mode
  * @{
  */
#define TIM_OPMODE_SINGLE                  TIM_CR1_OPM                          /*!< Counter stops counting at the next update event */
#define TIM_OPMODE_REPETITIVE              0x00000000U                          /*!< Counter is not stopped at update event          */
/**
  * @}
  */

/** @defgroup TIM_Encoder_Mode TIM Encoder Mode
  * @{
  */
#define TIM_ENCODERMODE_TI1                      TIM_SMCR_SMS_0                                                      /*!< Quadrature encoder mode 1, x2 mode, counts up/down on TI1FP1 edge depending on TI2FP2 level  */
#define TIM_ENCODERMODE_TI2                      TIM_SMCR_SMS_1                                                      /*!< Quadrature encoder mode 2, x2 mode, counts up/down on TI2FP2 edge depending on TI1FP1 level. */
#define TIM_ENCODERMODE_TI12                     (TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0)                                   /*!< Quadrature encoder mode 3, x4 mode, counts up/down on both TI1FP1 and TI2FP2 edges depending on the level of the other input. */
/**
  * @}
  */

/** @defgroup TIM_Interrupt_definition TIM interrupt Definition
  * @{
  */
#define TIM_IT_UPDATE                      TIM_DIER_UIE                         /*!< Update interrupt            */
#define TIM_IT_CC1                         TIM_DIER_CC1IE                       /*!< Capture/Compare 1 interrupt */
#define TIM_IT_CC2                         TIM_DIER_CC2IE                       /*!< Capture/Compare 2 interrupt */
#define TIM_IT_CC3                         TIM_DIER_CC3IE                       /*!< Capture/Compare 3 interrupt */
#define TIM_IT_CC4                         TIM_DIER_CC4IE                       /*!< Capture/Compare 4 interrupt */
#define TIM_IT_COM                         TIM_DIER_COMIE                       /*!< Commutation interrupt       */
#define TIM_IT_TRIGGER                     TIM_DIER_TIE                         /*!< Trigger interrupt           */
#define TIM_IT_BREAK                       TIM_DIER_BIE                         /*!< Break interrupt             */
/**
  * @}
  */
