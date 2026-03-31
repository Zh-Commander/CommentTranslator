#if defined(STM32F0) || defined(STM32F3) || defined(STM32F1)
#define  GPIO_SPEED_LOW    GPIO_SPEED_FREQ_LOW      /* GPIO低速模式别名 */
#define  GPIO_SPEED_MEDIUM GPIO_SPEED_FREQ_MEDIUM   /* GPIO中速模式别名 */
#define  GPIO_SPEED_HIGH   GPIO_SPEED_FREQ_HIGH     /* GPIO高速模式别名 */
#endif /* 针对STM32F0、STM32F3或STM32F1系列 */

#define GPIO_AF6_DFSDM                            GPIO_AF6_DFSDM1  /* DFSDM1模块的AF6复用功能别名 */

#if defined(STM32U5) || defined(STM32H5)
#define GPIO_AF0_RTC_50Hz                         GPIO_AF0_RTC_50HZ  /* RTC 50Hz时钟的AF0复用功能别名 */
#endif /* 针对STM32U5或STM32H5系列 */
#if defined(STM32U5)
#define GPIO_AF0_S2DSTOP                          GPIO_AF0_SRDSTOP   /* 停止模式下的安全域复位AF0别名 */
#define GPIO_AF11_LPGPIO                          GPIO_AF11_LPGPIO1  /* 低功耗GPIO的AF11复用功能别名 */
#endif /* 针对STM32U5系列 */

#if defined(STM32WBA)
#define GPIO_AF11_RF_ANTSW0    GPIO_AF11_RF  /* RF天线开关0的AF11复用功能别名 */
#define GPIO_AF11_RF_ANTSW1    GPIO_AF11_RF  /* RF天线开关1的AF11复用功能别名 */
#define GPIO_AF11_RF_ANTSW2    GPIO_AF11_RF  /* RF天线开关2的AF11复用功能别名 */
#define GPIO_AF11_RF_IO1       GPIO_AF11_RF  /* RF IO1的AF11复用功能别名 */
#define GPIO_AF11_RF_IO2       GPIO_AF11_RF  /* RF IO2的AF11复用功能别名 */
#define GPIO_AF11_RF_IO3       GPIO_AF11_RF  /* RF IO3的AF11复用功能别名 */
#define GPIO_AF11_RF_IO4       GPIO_AF11_RF  /* RF IO4的AF11复用功能别名 */
#define GPIO_AF11_RF_IO5       GPIO_AF11_RF  /* RF IO5的AF11复用功能别名 */
#define GPIO_AF11_RF_IO6       GPIO_AF11_RF  /* RF IO6的AF11复用功能别名 */
#define GPIO_AF11_RF_IO7       GPIO_AF11_RF  /* RF IO7的AF11复用功能别名 */
#define GPIO_AF11_RF_IO8       GPIO_AF11_RF  /* RF IO8的AF11复用功能别名 */
#define GPIO_AF11_RF_IO9       GPIO_AF11_RF  /* RF IO9的AF11复用功能别名 */
#endif /* 针对STM32WBA系列 */
/**
  * @}
  */

/** @defgroup HAL_GTZC_Aliased_Defines HAL GTZC 别名定义，用于保持向后兼容性
  * @{
  */
#if defined(STM32U5)
#define GTZC_PERIPH_DCMI                      GTZC_PERIPH_DCMI_PSSI  /* DCMI外设的GTZC别名 */
#define GTZC_PERIPH_LTDC                      GTZC_PERIPH_LTDCUSB    /* LTDC外设的GTZC别名 */
#endif /* 针对STM32U5系列 */
#if defined(STM32H5)
#define GTZC_PERIPH_DAC12                     GTZC_PERIPH_DAC1       /* DAC1外设的GTZC别名 */
#define GTZC_PERIPH_ADC12                     GTZC_PERIPH_ADC        /* ADC外设的GTZC别名 */
#define GTZC_PERIPH_USBFS                     GTZC_PERIPH_USB        /* USB外设的GTZC别名 */
#endif /* 针对STM32H5系列 */
#if defined(STM32H5) || defined(STM32U5)
#define GTZC_MCPBB_NB_VCTR_REG_MAX            GTZC_MPCBB_NB_VCTR_REG_MAX        /* MPCBB向量寄存器最大数量的别名 */
#define GTZC_MCPBB_NB_LCK_VCTR_REG_MAX        GTZC_MPCBB_NB_LCK_VCTR_REG_MAX    /* MPCBB锁定向量寄存器最大数量的别名 */
#define GTZC_MCPBB_SUPERBLOCK_UNLOCKED        GTZC_MPCBB_SUPERBLOCK_UNLOCKED    /* MPCBB超级块未锁定状态的别名 */
#define GTZC_MCPBB_SUPERBLOCK_LOCKED          GTZC_MPCBB_SUPERBLOCK_LOCKED      /* MPCBB超级块锁定状态的别名 */
#define GTZC_MCPBB_BLOCK_NSEC                 GTZC_MPCBB_BLOCK_NSEC             /* MPCBB非安全块的别名 */
#define GTZC_MCPBB_BLOCK_SEC                  GTZC_MPCBB_BLOCK_SEC              /* MPCBB安全块的别名 */
#define GTZC_MCPBB_BLOCK_NPRIV                GTZC_MPCBB_BLOCK_NPRIV            /* MPCBB非特权块的别名 */
#define GTZC_MCPBB_BLOCK_PRIV                 GTZC_MPCBB_BLOCK_PRIV             /* MPCBB特权块的别名 */
#define GTZC_MCPBB_LOCK_OFF                   GTZC_MPCBB_LOCK_OFF               /* MPCBB锁定关闭的别名 */
#define GTZC_MCPBB_LOCK_ON                    GTZC_MPCBB_LOCK_ON                /* MPCBB锁定开启的别名 */
#endif /* 针对STM32H5或STM32U5系列 */
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Macros HAL HRTIM 别名宏，用于保持向后兼容性
  * @{
  */
#define HRTIM_TIMDELAYEDPROTECTION_DISABLED           HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DISABLED            /* HRTIM延迟保护禁用模式的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_EEV6    /* HRTIM输出1延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_EEV6    /* HRTIM输出2延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV6    /* HRTIM双输出延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV68     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV6       /* HRTIM平衡延迟保护模式（事件6/8）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_DEEV7   /* HRTIM输出1延迟保护模式（事件7/9）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_DEEV7   /* HRTIM输出2延迟保护模式（事件7/9）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV79  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV7    /* HRTIM双输出延迟保护模式（事件7/9）的别名 */
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV79     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV7       /* HRTIM平衡延迟保护模式（事件7/9）的别名 */

#define __HAL_HRTIM_SetCounter        __HAL_HRTIM_SETCOUNTER        /* 设置HRTIM计数器的别名 */
#define __HAL_HRTIM_GetCounter        __HAL_HRTIM_GETCOUNTER        /* 获取HRTIM计数器的别名 */
#define __HAL_HRTIM_SetPeriod         __HAL_HRTIM_SETPERIOD         /* 设置HRTIM周期的别名 */
#define __HAL_HRTIM_GetPeriod         __HAL_HRTIM_GETPERIOD         /* 获取HRTIM周期的别名 */
#define __HAL_HRTIM_SetClockPrescaler __HAL_HRTIM_SETCLOCKPRESCALER /* 设置HRTIM时钟预分频器的别名 */
#define __HAL_HRTIM_GetClockPrescaler __HAL_HRTIM_GETCLOCKPRESCALER /* 获取HRTIM时钟预分频器的别名 */
#define __HAL_HRTIM_SetCompare        __HAL_HRTIM_SETCOMPARE        /* 设置HRTIM比较值的别名 */
#define __HAL_HRTIM_GetCompare        __HAL_HRTIM_GETCOMPARE        /* 获取HRTIM比较值的别名 */

#if defined(STM32G4)
#define HAL_HRTIM_ExternalEventCounterConfig    HAL_HRTIM_ExtEventCounterConfig     /* 外部事件计数器配置函数的别名 */
#define HAL_HRTIM_ExternalEventCounterEnable    HAL_HRTIM_ExtEventCounterEnable     /* 启用外部事件计数器的别名 */
#define HAL_HRTIM_ExternalEventCounterDisable   HAL_HRTIM_ExtEventCounterDisable    /* 禁用外部事件计数器的别名 */
#define HAL_HRTIM_ExternalEventCounterReset     HAL_HRTIM_ExtEventCounterReset      /* 复位外部事件计数器的别名 */
#define HRTIM_TIMEEVENT_A                       HRTIM_EVENTCOUNTER_A                /* 事件计数器A的别名 */
#define HRTIM_TIMEEVENT_B                       HRTIM_EVENTCOUNTER_B                /* 事件计数器B的别名 */
#define HRTIM_TIMEEVENTRESETMODE_UNCONDITIONAL  HRTIM_EVENTCOUNTER_RSTMODE_UNCONDITIONAL  /* 无条件复位模式的别名 */
#define HRTIM_TIMEEVENTRESETMODE_CONDITIONAL    HRTIM_EVENTCOUNTER_RSTMODE_CONDITIONAL    /* 条件复位模式的别名 */
#endif /* 针对STM32G4系列 */

#if defined(STM32H7)
#define HRTIM_OUTPUTSET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器A事件1到定时器B比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器A事件2到定时器B比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器A事件3到定时器C比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器A事件4到定时器C比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器A事件5到定时器D比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器A事件6到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器A事件7到定时器E比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器A事件8到定时器E比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器A事件9到定时器F比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器B事件1到定时器A比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器B事件2到定时器A比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器B事件3到定时器C比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器B事件4到定时器C比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器B事件5到定时器D比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器B事件6到定时器D比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器B事件7到定时器E比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器B事件8到定时器E比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器B事件9到定时器F比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器C事件1到定时器A比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器C事件2到定时器A比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器C事件3到定时器B比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器C事件4到定时器B比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器C事件5到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器C事件6到定时器D比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器C事件7到定时器E比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器C事件8到定时器E比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器C事件9到定时器F比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器D事件1到定时器A比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器D事件2到定时器A比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器D事件3到定时器B比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器D事件4到定时器B比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器D事件5到定时器C比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器D事件6到定时器E比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器D事件7到定时器E比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器D事件8到定时器F比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器D事件9到定时器F比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器E事件1到定时器A比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器E事件2到定时器B比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器E事件3到定时器B比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器E事件4到定时器C比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器E事件5到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器E事件6到定时器D比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器E事件7到定时器D比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器E事件8到定时器F比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器E事件9到定时器F比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1  /* 定时器F事件1到定时器A比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2  /* 定时器F事件2到定时器B比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3  /* 定时器F事件3到定时器B比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4  /* 定时器F事件4到定时器C比较1的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5  /* 定时器F事件5到定时器C比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6  /* 定时器F事件6到定时器D比较3的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7  /* 定时器F事件7到定时器D比较4的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8  /* 定时器F事件8到定时器E比较2的输出设置别名 */
#define HRTIM_OUTPUTSET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9  /* 定时器F事件9到定时器E比较3的输出设置别名 */
