#define __HAL_RTC_EXTI_GET_FLAG(RTC_EXTI_LINE_ALARM_EVENT)    __HAL_RTC_ALARM_EXTI_GET_FLAG()  /* 获取RTC闹钟事件EXTI标志位（F1专用）*/

#define __HAL_RTC_EXTI_GENERATE_SWIT(RTC_EXTI_LINE_ALARM_EVENT)   __HAL_RTC_ALARM_EXTI_GENERATE_SWIT()  /* 生成RTC闹钟事件软件触发（F1专用）*/
#else
/* 根据EXTI线参数清除RTC事件标志位（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_CLEAR_FLAG(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_CLEAR_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_CLEAR_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_CLEAR_FLAG()))
/* 根据EXTI线参数使能RTC事件中断（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_ENABLE_IT(__EXTI_LINE__)   (((__EXTI_LINE__)  == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_ENABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_ENABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_ENABLE_IT()))
/* 根据EXTI线参数禁用RTC事件中断（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_DISABLE_IT(__EXTI_LINE__)  (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_DISABLE_IT() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_DISABLE_IT() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_DISABLE_IT()))
/* 根据EXTI线参数获取RTC事件标志位状态（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_GET_FLAG(__EXTI_LINE__)    (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GET_FLAG() : \
                                                   (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GET_FLAG() : \
                                                    __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GET_FLAG()))
/* 根据EXTI线参数生成RTC事件软件中断（支持闹钟、唤醒定时器、侵入和时间戳事件）*/
#define __HAL_RTC_EXTI_GENERATE_SWIT(__EXTI_LINE__)   (((__EXTI_LINE__) == RTC_EXTI_LINE_ALARM_EVENT) ? __HAL_RTC_ALARM_EXTI_GENERATE_SWIT() : \
                                                       (((__EXTI_LINE__) == RTC_EXTI_LINE_WAKEUPTIMER_EVENT) ? __HAL_RTC_WAKEUPTIMER_EXTI_GENERATE_SWIT() :  \
                                                        __HAL_RTC_TAMPER_TIMESTAMP_EXTI_GENERATE_SWIT()))
#endif   /* STM32F1 */

/* 为特定系列定义RTC侵入事件获取中断标志的别名 */
#if defined (STM32F0) || defined (STM32F2) || defined (STM32F3) || defined (STM32F4) || defined (STM32F7) || \
    defined (STM32H7) || \
    defined (STM32L0) || defined (STM32L1) || \
    defined (STM32WB)
#define __HAL_RTC_TAMPER_GET_IT                   __HAL_RTC_TAMPER_GET_FLAG  /* 侵入事件获取中断标志别名 */
#endif

/* RTC功能检查宏的别名定义 */
#define IS_ALARM                                  IS_RTC_ALARM  /* 闹钟检查 */
#define IS_ALARM_MASK                             IS_RTC_ALARM_MASK  /* 闹钟掩码检查 */
#define IS_TAMPER                                 IS_RTC_TAMPER  /* 侵入检查 */
#define IS_TAMPER_ERASE_MODE                      IS_RTC_TAMPER_ERASE_MODE  /* 侵入擦除模式检查 */
#define IS_TAMPER_FILTER                          IS_RTC_TAMPER_FILTER  /* 侵入滤波器检查 */
#define IS_TAMPER_INTERRUPT                       IS_RTC_TAMPER_INTERRUPT  /* 侵入中断检查 */
#define IS_TAMPER_MASKFLAG_STATE                  IS_RTC_TAMPER_MASKFLAG_STATE  /* 侵入掩码标志状态检查 */
#define IS_TAMPER_PRECHARGE_DURATION              IS_RTC_TAMPER_PRECHARGE_DURATION  /* 侵入预充电持续时间检查 */
#define IS_TAMPER_PULLUP_STATE                    IS_RTC_TAMPER_PULLUP_STATE  /* 侵入上拉状态检查 */
#define IS_TAMPER_SAMPLING_FREQ                   IS_RTC_TAMPER_SAMPLING_FREQ  /* 侵入采样频率检查 */
#define IS_TAMPER_TIMESTAMPONTAMPER_DETECTION     IS_RTC_TAMPER_TIMESTAMPONTAMPER_DETECTION  /* 侵入检测时时间戳检查 */
#define IS_TAMPER_TRIGGER                         IS_RTC_TAMPER_TRIGGER  /* 侵入触发检查 */
#define IS_WAKEUP_CLOCK                           IS_RTC_WAKEUP_CLOCK  /* 唤醒时钟检查 */
#define IS_WAKEUP_COUNTER                         IS_RTC_WAKEUP_COUNTER  /* 唤醒计数器检查 */

/* RTC写保护宏的别名 */
#define __RTC_WRITEPROTECTION_ENABLE  __HAL_RTC_WRITEPROTECTION_ENABLE  /* 使能写保护 */
#define __RTC_WRITEPROTECTION_DISABLE  __HAL_RTC_WRITEPROTECTION_DISABLE  /* 禁用写保护 */

#if defined (STM32H5)
/* H5系列RTC时钟控制宏的别名 */
#define __HAL_RCC_RTCAPB_CLK_ENABLE   __HAL_RCC_RTC_CLK_ENABLE  /* 使能RTC APB时钟 */
#define __HAL_RCC_RTCAPB_CLK_DISABLE  __HAL_RCC_RTC_CLK_DISABLE  /* 禁用RTC APB时钟 */
#endif   /* STM32H5 */

/**
  * @}
  */

/** @defgroup HAL_SD_Aliased_Macros HAL SD/MMC Aliased Macros maintained for legacy purpose
  * @brief HAL SD/MMC模块的别名宏，用于保持向后兼容性
  * @{
  */

#define SD_OCR_CID_CSD_OVERWRIETE   SD_OCR_CID_CSD_OVERWRITE  /* OCR寄存器CID/CSD覆盖标志 */
#define SD_CMD_SD_APP_STAUS         SD_CMD_SD_APP_STATUS  /* SD应用状态命令 */

/* eMMC电压范围和时钟分频器宏的别名 */
#if !defined(STM32F1) && !defined(STM32F2) && !defined(STM32F4) && !defined(STM32L1)
#define eMMC_HIGH_VOLTAGE_RANGE     EMMC_HIGH_VOLTAGE_RANGE  /* eMMC高电压范围 */
#define eMMC_DUAL_VOLTAGE_RANGE     EMMC_DUAL_VOLTAGE_RANGE  /* eMMC双电压范围 */
#define eMMC_LOW_VOLTAGE_RANGE      EMMC_LOW_VOLTAGE_RANGE  /* eMMC低电压范围 */

#define SDMMC_NSpeed_CLK_DIV        SDMMC_NSPEED_CLK_DIV  /* 正常速度时钟分频 */
#define SDMMC_HSpeed_CLK_DIV        SDMMC_HSPEED_CLK_DIV  /* 高速时钟分频 */
#endif

/* F4和F2系列SD/MMC功能宏的别名 */
#if defined(STM32F4) || defined(STM32F2)
#define  SD_SDMMC_DISABLED          SD_SDIO_DISABLED  /* SD/MMC禁用状态 */
#define  SD_SDMMC_FUNCTION_BUSY     SD_SDIO_FUNCTION_BUSY  /* SD/MMC功能忙 */
#define  SD_SDMMC_FUNCTION_FAILED   SD_SDIO_FUNCTION_FAILED  /* SD/MMC功能失败 */
#define  SD_SDMMC_UNKNOWN_FUNCTION  SD_SDIO_UNKNOWN_FUNCTION  /* SD/MMC未知功能 */
#define  SD_CMD_SDMMC_SEN_OP_COND   SD_CMD_SDIO_SEN_OP_COND  /* SD/MMC发送操作条件命令 */
#define  SD_CMD_SDMMC_RW_DIRECT     SD_CMD_SDIO_RW_DIRECT  /* SD/MMC直接读写命令 */
#define  SD_CMD_SDMMC_RW_EXTENDED   SD_CMD_SDIO_RW_EXTENDED  /* SD/MMC扩展读写命令 */
#define  __HAL_SD_SDMMC_ENABLE      __HAL_SD_SDIO_ENABLE  /* 使能SD/MMC */
#define  __HAL_SD_SDMMC_DISABLE     __HAL_SD_SDIO_DISABLE  /* 禁用SD/MMC */
#define  __HAL_SD_SDMMC_DMA_ENABLE  __HAL_SD_SDIO_DMA_ENABLE  /* 使能SD/MMC DMA */
#define  __HAL_SD_SDMMC_DMA_DISABLE __HAL_SD_SDIO_DMA_DISABL  /* 禁用SD/MMC DMA（注意：宏名有拼写错误） */
#define  __HAL_SD_SDMMC_ENABLE_IT   __HAL_SD_SDIO_ENABLE_IT  /* 使能SD/MMC中断 */
#define  __HAL_SD_SDMMC_DISABLE_IT  __HAL_SD_SDIO_DISABLE_IT  /* 禁用SD/MMC中断 */
#define  __HAL_SD_SDMMC_GET_FLAG    __HAL_SD_SDIO_GET_FLAG  /* 获取SD/MMC标志位 */
#define  __HAL_SD_SDMMC_CLEAR_FLAG  __HAL_SD_SDIO_CLEAR_FLAG  /* 清除SD/MMC标志位 */
#define  __HAL_SD_SDMMC_GET_IT      __HAL_SD_SDIO_GET_IT  /* 获取SD/MMC中断 */
#define  __HAL_SD_SDMMC_CLEAR_IT    __HAL_SD_SDIO_CLEAR_IT  /* 清除SD/MMC中断 */
#define  SDMMC_STATIC_FLAGS         SDIO_STATIC_FLAGS  /* SD/MMC静态标志位 */
#define  SDMMC_CMD0TIMEOUT          SDIO_CMD0TIMEOUT  /* SD/MMC命令0超时 */
#define  SD_SDMMC_SEND_IF_COND      SD_SDIO_SEND_IF_COND  /* SD/MMC发送接口条件命令 */
/* CMSIS别名 */
#define  SDMMC1_IRQn                SDIO_IRQn  /* SDMMC1中断编号 */
#define  SDMMC1_IRQHandler          SDIO_IRQHandler  /* SDMMC1中断处理函数 */
#endif

/* F7和L4系列SDIO功能宏的别名 */
#if defined(STM32F7) || defined(STM32L4)
#define  SD_SDIO_DISABLED           SD_SDMMC_DISABLED  /* SDIO禁用状态 */
#define  SD_SDIO_FUNCTION_BUSY      SD_SDMMC_FUNCTION_BUSY  /* SDIO功能忙 */
#define  SD_SDIO_FUNCTION_FAILED    SD_SDMMC_FUNCTION_FAILED  /* SDIO功能失败 */
#define  SD_SDIO_UNKNOWN_FUNCTION   SD_SDMMC_UNKNOWN_FUNCTION  /* SDIO未知功能 */
#define  SD_CMD_SDIO_SEN_OP_COND    SD_CMD_SDMMC_SEN_OP_COND  /* SDIO发送操作条件命令 */
#define  SD_CMD_SDIO_RW_DIRECT      SD_CMD_SDMMC_RW_DIRECT  /* SDIO直接读写命令 */
#define  SD_CMD_SDIO_RW_EXTENDED    SD_CMD_SDMMC_RW_EXTENDED  /* SDIO扩展读写命令 */
#define  __HAL_SD_SDIO_ENABLE       __HAL_SD_SDMMC_ENABLE  /* 使能SDIO */
#define  __HAL_SD_SDIO_DISABLE      __HAL_SD_SDMMC_DISABLE  /* 禁用SDIO */
#define  __HAL_SD_SDIO_DMA_ENABLE   __HAL_SD_SDMMC_DMA_ENABLE  /* 使能SDIO DMA */
#define  __HAL_SD_SDIO_DMA_DISABL   __HAL_SD_SDMMC_DMA_DISABLE  /* 禁用SDIO DMA（注意：宏名有拼写错误） */
#define  __HAL_SD_SDIO_ENABLE_IT    __HAL_SD_SDMMC_ENABLE_IT  /* 使能SDIO中断 */
#define  __HAL_SD_SDIO_DISABLE_IT   __HAL_SD_SDMMC_DISABLE_IT  /* 禁用SDIO中断 */
#define  __HAL_SD_SDIO_GET_FLAG     __HAL_SD_SDMMC_GET_FLAG  /* 获取SDIO标志位 */
#define  __HAL_SD_SDIO_CLEAR_FLAG   __HAL_SD_SDMMC_CLEAR_FLAG  /* 清除SDIO标志位 */
#define  __HAL_SD_SDIO_GET_IT       __HAL_SD_SDMMC_GET_IT  /* 获取SDIO中断 */
#define  __HAL_SD_SDIO_CLEAR_IT     __HAL_SD_SDMMC_CLEAR_IT  /* 清除SDIO中断 */
#define  SDIO_STATIC_FLAGS          SDMMC_STATIC_FLAGS  /* SDIO静态标志位 */
#define  SDIO_CMD0TIMEOUT           SDMMC_CMD0TIMEOUT  /* SDIO命令0超时 */
#define  SD_SDIO_SEND_IF_COND       SD_SDMMC_SEND_IF_COND  /* SDIO发送接口条件命令 */
/* CMSIS兼容性别名 */
#define  SDIO_IRQn                  SDMMC1_IRQn  /* SDIO中断编号 */
#define  SDIO_IRQHandler            SDMMC1_IRQHandler  /* SDIO中断处理函数 */
#endif

/* SD卡类型定义宏的别名 */
#if defined(STM32F7) || defined(STM32F4) || defined(STM32F2) || defined(STM32L4) || defined(STM32H7)
#define  HAL_SD_CardCIDTypedef       HAL_SD_CardCIDTypeDef  /* SD卡CID类型定义 */
#define  HAL_SD_CardCSDTypedef       HAL_SD_CardCSDTypeDef  /* SD卡CSD类型定义 */
#define  HAL_SD_CardStatusTypedef    HAL_SD_CardStatusTypeDef  /* SD卡状态类型定义 */
#define  HAL_SD_CardStateTypedef     HAL_SD_CardStateTypeDef  /* SD卡状态类型定义 */
#endif

/* MMC和SD DMA双缓冲区回调函数宏的别名 */
#if defined(STM32H7) || defined(STM32L5)
#define HAL_MMCEx_Read_DMADoubleBuffer0CpltCallback   HAL_MMCEx_Read_DMADoubleBuf0CpltCallback  /* MMC DMA双缓冲区0读取完成回调 */
#define HAL_MMCEx_Read_DMADoubleBuffer1CpltCallback   HAL_MMCEx_Read_DMADoubleBuf1CpltCallback  /* MMC DMA双缓冲区1读取完成回调 */
#define HAL_MMCEx_Write_DMADoubleBuffer0CpltCallback  HAL_MMCEx_Write_DMADoubleBuf0CpltCallback  /* MMC DMA双缓冲区0写入完成回调 */
#define HAL_MMCEx_Write_DMADoubleBuffer1CpltCallback  HAL_MMCEx_Write_DMADoubleBuf1CpltCallback  /* MMC DMA双缓冲区1写入完成回调 */
#define HAL_SDEx_Read_DMADoubleBuffer0CpltCallback    HAL_SDEx_Read_DMADoubleBuf0CpltCallback  /* SD DMA双缓冲区0读取完成回调 */
#define HAL_SDEx_Read_DMADoubleBuffer1CpltCallback    HAL_SDEx_Read_DMADoubleBuf1CpltCallback  /* SD DMA双缓冲区1读取完成回调 */
#define HAL_SDEx_Write_DMADoubleBuffer0CpltCallback   HAL_SDEx_Write_DMADoubleBuf0CpltCallback  /* SD DMA双缓冲区0写入完成回调 */
#define HAL_SDEx_Write_DMADoubleBuffer1CpltCallback   HAL_SDEx_Write_DMADoubleBuf1CpltCallback  /* SD DMA双缓冲区1写入完成回调 */
#define HAL_SD_DriveTransciver_1_8V_Callback          HAL_SD_DriveTransceiver_1_8V_Callback  /* SD 1.8V驱动收发器回调（注意：宏名有拼写错误） */
#endif
/**
  * @}
  */

/** @defgroup HAL_SMARTCARD_Aliased_Macros HAL SMARTCARD Aliased Macros maintained for legacy purpose
  * @brief HAL智能卡模块的别名宏，用于保持向后兼容性
  * @{
  */

/* 智能卡控制宏的别名 */
#define __SMARTCARD_ENABLE_IT           __HAL_SMARTCARD_ENABLE_IT  /* 使能智能卡中断 */
#define __SMARTCARD_DISABLE_IT          __HAL_SMARTCARD_DISABLE_IT  /* 禁用智能卡中断 */
#define __SMARTCARD_ENABLE              __HAL_SMARTCARD_ENABLE  /* 使能智能卡 */
#define __SMARTCARD_DISABLE             __HAL_SMARTCARD_DISABLE  /* 禁用智能卡 */
#define __SMARTCARD_DMA_REQUEST_ENABLE  __HAL_SMARTCARD_DMA_REQUEST_ENABLE  /* 使能智能卡DMA请求 */
#define __SMARTCARD_DMA_REQUEST_DISABLE __HAL_SMARTCARD_DMA_REQUEST_DISABLE  /* 禁用智能卡DMA请求 */

/* 智能卡时钟源获取宏的别名 */
#define __HAL_SMARTCARD_GETCLOCKSOURCE  SMARTCARD_GETCLOCKSOURCE  /* 获取智能卡时钟源 */
#define __SMARTCARD_GETCLOCKSOURCE      SMARTCARD_GETCLOCKSOURCE  /* 获取智能卡时钟源（同上） */

#define IS_SMARTCARD_ONEBIT_SAMPLING    IS_SMARTCARD_ONE_BIT_SAMPLE  /* 智能卡单比特采样检查 */

/**
  * @}
  */

/** @defgroup HAL_SMBUS_Aliased_Macros HAL SMBUS Aliased Macros maintained for legacy purpose
  * @brief HAL SMBUS模块的别名宏，用于保持向后兼容性
  * @{
  */
/* SMBUS控制宏的别名 */
#define __HAL_SMBUS_RESET_CR1           SMBUS_RESET_CR1  /* 重置SMBUS控制寄存器1 */
#define __HAL_SMBUS_RESET_CR2           SMBUS_RESET_CR2  /* 重置SMBUS控制寄存器2 */
#define __HAL_SMBUS_GENERATE_START      SMBUS_GENERATE_START  /* 生成SMBUS起始条件 */
#define __HAL_SMBUS_GET_ADDR_MATCH      SMBUS_GET_ADDR_MATCH  /* 获取SMBUS地址匹配状态 */
#define __HAL_SMBUS_GET_DIR             SMBUS_GET_DIR  /* 获取SMBUS传输方向 */
#define __HAL_SMBUS_GET_STOP_MODE       SMBUS_GET_STOP_MODE  /* 获取SMBUS停止模式 */
#define __HAL_SMBUS_GET_PEC_MODE        SMBUS_GET_PEC_MODE  /* 获取SMBUS PEC模式 */
#define __HAL_SMBUS_GET_ALERT_ENABLED   SMBUS_GET_ALERT_ENABLED  /* 获取SMBUS警报使能状态 */
/**
  * @}
  */

/** @defgroup HAL_SPI_Aliased_Macros HAL SPI Aliased Macros maintained for legacy purpose
  * @brief HAL SPI模块的别名宏，用于保持向后兼容性
  * @{
  */