#define __HAL_RTC_EXTI_GET_FLAG(RTC_EXTI_LINE_ALARM_EVENT)    __HAL_RTC_ALARM_EXTI_GET_FLAG()

#define __HAL_RTC_EXTI_GENERATE_SWIT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_GENERATE_SWIT()
#else
#define __HAL_RTC_EXTI_CLEAR_FLAG(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_CLEAR_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_CLEAR_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_CLEAR_FLAG()))
#define __HAL_RTC_EXTI_ENABLE_IT(__EXTI_LINE__)   (((__EXTI_LINE__)  == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_ENABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_IT()))
#define __HAL_RTC_EXTI_DISABLE_IT(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_DISABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_IT()))
#define __HAL_RTC_EXTI_GET_FLAG(__EXTI_LINE__)    (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GET_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GET_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GET_FLAG()))
#define __HAL_RTC_EXTI_GENERATE_SWIT(__EXTI_LINE__)   (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GENERATE_SWIT() : \
                                                       (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GENERATE_SWIT() :  \
                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GENERATE_SWIT()))
#endif   /* STM32F1 */

#if defined (STM32F0) || defined (STM32F2) || defined (STM32F3) || defined (STM32F4) || defined (STM32F7) || \
    defined (STM32H7) || \
    defined (STM32L0) || defined (STM32L1) || \
    defined (STM32WB)
#define __HAL_RTC_TAMPER_GET_IT                   __HAL_RTC_TAMPER_GET_FLAG
#endif

#define IS_ALARM                                  IS_RTC_ALARM
#define IS_ALARM_MASK                             IS_RTC_ALARM_MASK
#define IS_TAMPER                                 IS_RTC_TAMPER
#define IS_TAMPER_ERASE_MODE                      IS_RTC_TAMPER_ERASE_MODE
#define IS_TAMPER_FILTER                          IS_RTC_TAMPER_FILTER
#define IS_TAMPER_INTERRUPT                       IS_RTC_TAMPER_INTERRUPT
#define IS_TAMPER_MASKFLAG_STATE                  IS_RTC_TAMPER_MASKFLAG_STATE
#define IS_TAMPER_PRECHARGE_DURATION              IS_RTC_TAMPER_PRECHARGE_DURATION
#define IS_TAMPER_PULLUP_STATE                    IS_RTC_TAMPER_PULLUP_STATE
#define IS_TAMPER_SAMPLING_FREQ                   IS_RTC_TAMPER_SAMPLING_FREQ
#define IS_TAMPER_TIMESTAMPONTAMPER_DETECTION     IS_RTC_TAMPER_TIMESTAMPONTAMPER_DETECTION
#define IS_TAMPER_TRIGGER                         IS_RTC_TAMPER_TRIGGER
#define IS_WAKEUP_CLOCK                           IS_RTC_WAKEUP_CLOCK
#define IS_WAKEUP_COUNTER                         IS_RTC_WAKEUP_COUNTER

#define __RTC_WRITEPROTECTION_ENABLE  __HAL_RTC_WRITEPROTECTION_ENABLE
#define __RTC_WRITEPROTECTION_DISABLE  __HAL_RTC_WRITEPROTECTION_DISABLE

#if defined (STM32H5)
#define __HAL_RCC_RTCAPB_CLK_ENABLE   __HAL_RCC_RTC_CLK_ENABLE
#define __HAL_RCC_RTCAPB_CLK_DISABLE  __HAL_RCC_RTC_CLK_DISABLE
#endif   /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_SD_Aliased_Macros HAL SD/MMC Aliased Macros maintained for legacy purpose
  * @{
  */

#define SD_OCR_CID_CSD_OVERWRIETE   SD_OCR_CID_CSD_OVERWRITE
#define SD_CMD_SD_APP_STAUS         SD_CMD_SD_APP_STATUS

#if !defined(STM32F1) && !defined(STM32F2) && !defined(STM32F4) && !defined(STM32L1)
#define eMMC_HIGH_VOLTAGE_RANGE     EMMC_HIGH_VOLTAGE_RANGE
#define eMMC_DUAL_VOLTAGE_RANGE     EMMC_DUAL_VOLTAGE_RANGE
#define eMMC_LOW_VOLTAGE_RANGE      EMMC_LOW_VOLTAGE_RANGE

#define SDMMC_NSpeed_CLK_DIV        SDMMC_NSPEED_CLK_DIV
#define SDMMC_HSpeed_CLK_DIV        SDMMC_HSPEED_CLK_DIV
#endif

#if defined(STM32F4) || defined(STM32F2)
#define  SD_SDMMC_DISABLED          SD_SDIO_DISABLED
#define  SD_SDMMC_FUNCTION_BUSY     SD_SDIO_FUNCTION_BUSY
#define  SD_SDMMC_FUNCTION_FAILED   SD_SDIO_FUNCTION_FAILED
#define  SD_SDMMC_UNKNOWN_FUNCTION  SD_SDIO_UNKNOWN_FUNCTION
#define  SD_CMD_SDMMC_SEN_OP_COND   SD_CMD_SDIO_SEN_OP_COND
#define  SD_CMD_SDMMC_RW_DIRECT     SD_CMD_SDIO_RW_DIRECT
#define  SD_CMD_SDMMC_RW_EXTENDED   SD_CMD_SDIO_RW_EXTENDED
#define  __HAL_SD_SDMMC_ENABLE      __HAL_SD_SDIO_ENABLE
#define  __HAL_SD_SDMMC_DISABLE     __HAL_SD_SDIO_DISABLE
#define  __HAL_SD_SDMMC_DMA_ENABLE  __HAL_SD_SDIO_DMA_ENABLE
#define  __HAL_SD_SDMMC_DMA_DISABLE __HAL_SD_SDIO_DMA_DISABL
#define  __HAL_SD_SDMMC_ENABLE_IT   __HAL_SD_SDIO_ENABLE_IT
#define  __HAL_SD_SDMMC_DISABLE_IT  __HAL_SD_SDIO_DISABLE_IT
#define  __HAL_SD_SDMMC_GET_FLAG    __HAL_SD_SDIO_GET_FLAG
#define  __HAL_SD_SDMMC_CLEAR_FLAG  __HAL_SD_SDIO_CLEAR_FLAG
#define  __HAL_SD_SDMMC_GET_IT      __HAL_SD_SDIO_GET_IT
#define  __HAL_SD_SDMMC_CLEAR_IT    __HAL_SD_SDIO_CLEAR_IT
#define  SDMMC_STATIC_FLAGS         SDIO_STATIC_FLAGS
#define  SDMMC_CMD0TIMEOUT          SDIO_CMD0TIMEOUT
#define  SD_SDMMC_SEND_IF_COND      SD_SDIO_SEND_IF_COND
/* alias CMSIS */
#define  SDMMC1_IRQn                SDIO_IRQn
#define  SDMMC1_IRQHandler          SDIO_IRQHandler
#endif

#if defined(STM32F7) || defined(STM32L4)
#define  SD_SDIO_DISABLED           SD_SDMMC_DISABLED
#define  SD_SDIO_FUNCTION_BUSY      SD_SDMMC_FUNCTION_BUSY
#define  SD_SDIO_FUNCTION_FAILED    SD_SDMMC_FUNCTION_FAILED
#define  SD_SDIO_UNKNOWN_FUNCTION   SD_SDMMC_UNKNOWN_FUNCTION
#define  SD_CMD_SDIO_SEN_OP_COND    SD_CMD_SDMMC_SEN_OP_COND
#define  SD_CMD_SDIO_RW_DIRECT      SD_CMD_SDMMC_RW_DIRECT
#define  SD_CMD_SDIO_RW_EXTENDED    SD_CMD_SDMMC_RW_EXTENDED
#define  __HAL_SD_SDIO_ENABLE       __HAL_SD_SDMMC_ENABLE
#define  __HAL_SD_SDIO_DISABLE      __HAL_SD_SDMMC_DISABLE
#define  __HAL_SD_SDIO_DMA_ENABLE   __HAL_SD_SDMMC_DMA_ENABLE
#define  __HAL_SD_SDIO_DMA_DISABL   __HAL_SD_SDMMC_DMA_DISABLE
#define  __HAL_SD_SDIO_ENABLE_IT    __HAL_SD_SDMMC_ENABLE_IT
#define  __HAL_SD_SDIO_DISABLE_IT   __HAL_SD_SDMMC_DISABLE_IT
#define  __HAL_SD_SDIO_GET_FLAG     __HAL_SD_SDMMC_GET_FLAG
#define  __HAL_SD_SDIO_CLEAR_FLAG   __HAL_SD_SDMMC_CLEAR_FLAG
#define  __HAL_SD_SDIO_GET_IT       __HAL_SD_SDMMC_GET_IT
#define  __HAL_SD_SDIO_CLEAR_IT     __HAL_SD_SDMMC_CLEAR_IT
#define  SDIO_STATIC_FLAGS          SDMMC_STATIC_FLAGS
#define  SDIO_CMD0TIMEOUT           SDMMC_CMD0TIMEOUT
#define  SD_SDIO_SEND_IF_COND       SD_SDMMC_SEND_IF_COND
/* alias CMSIS for compatibilities */
#define  SDIO_IRQn                  SDMMC1_IRQn
#define  SDIO_IRQHandler            SDMMC1_IRQHandler
#endif

#if defined(STM32F7) || defined(STM32F4) || defined(STM32F2) || defined(STM32L4) || defined(STM32H7)
#define  HAL_SD_CardCIDTypedef       HAL_SD_CardCIDTypeDef
#define  HAL_SD_CardCSDTypedef       HAL_SD_CardCSDTypeDef
#define  HAL_SD_CardStatusTypedef    HAL_SD_CardStatusTypeDef
#define  HAL_SD_CardStateTypedef     HAL_SD_CardStateTypeDef
#endif

#if defined(STM32H7) || defined(STM32L5)
#define HAL_MMCEx_Read_DMADoubleBuffer0CpltCallback   HAL_MMCEx_Read_DMADoubleBuf0CpltCallback
#define HAL_MMCEx_Read_DMADoubleBuffer1CpltCallback   HAL_MMCEx_Read_DMADoubleBuf1CpltCallback
#define HAL_MMCEx_Write_DMADoubleBuffer0CpltCallback  HAL_MMCEx_Write_DMADoubleBuf0CpltCallback
#define HAL_MMCEx_Write_DMADoubleBuffer1CpltCallback  HAL_MMCEx_Write_DMADoubleBuf1CpltCallback
#define HAL_SDEx_Read_DMADoubleBuffer0CpltCallback    HAL_SDEx_Read_DMADoubleBuf0CpltCallback
#define HAL_SDEx_Read_DMADoubleBuffer1CpltCallback    HAL_SDEx_Read_DMADoubleBuf1CpltCallback
#define HAL_SDEx_Write_DMADoubleBuffer0CpltCallback   HAL_SDEx_Write_DMADoubleBuf0CpltCallback
#define HAL_SDEx_Write_DMADoubleBuffer1CpltCallback   HAL_SDEx_Write_DMADoubleBuf1CpltCallback
#define HAL_SD_DriveTransciver_1_8V_Callback          HAL_SD_DriveTransceiver_1_8V_Callback
#endif
/**
  * @}
  */

/** @defgroup HAL_SMARTCARD_Aliased_Macros HAL SMARTCARD Aliased Macros maintained for legacy purpose
  * @{
  */

#define __SMARTCARD_ENABLE_IT           __HAL_SMARTCARD_ENABLE_IT
#define __SMARTCARD_DISABLE_IT          __HAL_SMARTCARD_DISABLE_IT
#define __SMARTCARD_ENABLE              __HAL_SMARTCARD_ENABLE
#define __SMARTCARD_DISABLE             __HAL_SMARTCARD_DISABLE
#define __SMARTCARD_DMA_REQUEST_ENABLE  __HAL_SMARTCARD_DMA_REQUEST_ENABLE
#define __SMARTCARD_DMA_REQUEST_DISABLE __HAL_SMARTCARD_DMA_REQUEST_DISABLE

#define __HAL_SMARTCARD_GETCLOCKSOURCE  SMARTCARD_GETCLOCKSOURCE
#define __SMARTCARD_GETCLOCKSOURCE      SMARTCARD_GETCLOCKSOURCE

#define IS_SMARTCARD_ONEBIT_SAMPLING    IS_SMARTCARD_ONE_BIT_SAMPLE

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Macros HAL SMBUS Aliased Macros maintained for legacy purpose
  * @{
  */
#define __HAL_SMBUS_RESET_CR1           SMBUS_RESET_CR1
#define __HAL_SMBUS_RESET_CR2           SMBUS_RESET_CR2
#define __HAL_SMBUS_GENERATE_START      SMBUS_GENERATE_START
#define __HAL_SMBUS_GET_ADDR_MATCH      SMBUS_GET_ADDR_MATCH
#define __HAL_SMBUS_GET_DIR             SMBUS_GET_DIR
#define __HAL_SMBUS_GET_STOP_MODE       SMBUS_GET_STOP_MODE
#define __HAL_SMBUS_GET_PEC_MODE        SMBUS_GET_PEC_MODE
#define __HAL_SMBUS_GET_ALERT_ENABLED   SMBUS_GET_ALERT_ENABLED
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Macros HAL SPI Aliased Macros maintained for legacy purpose
  * @{
  */

