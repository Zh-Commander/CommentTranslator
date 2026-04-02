#if defined(STM32F0) || defined(STM32F3) || defined(STM32F1)
// 以下宏定义是为了兼容旧版本的GPIO速度枚举命名，将LOW/MEDIUM/HIGH映射到新的FREQ命名方式
#define  GPIO_SPEED_LOW    GPIO_SPEED_FREQ_LOW        // 定义GPIO速度为低频（旧命名兼容）
#define  GPIO_SPEED_MEDIUM GPIO_SPEED_FREQ_MEDIUM     // 定义GPIO速度为中频（旧命名兼容）
#define  GPIO_SPEED_HIGH   GPIO_SPEED_FREQ_HIGH       // 定义GPIO速度为高频（旧命名兼容）
#endif /* STM32F0 || STM32F3 || STM32F1 */

// GPIO复用功能定义：将DFSDM宏映射到DFSDM1
#define GPIO_AF6_DFSDM                            GPIO_AF6_DFSDM1

#if defined(STM32U5) || defined(STM32H5)
// GPIO复用功能定义：RTC 50Hz时钟输出，兼容大小写命名
#define GPIO_AF0_RTC_50Hz                         GPIO_AF0_RTC_50HZ
#endif /* STM32U5 || STM32H5 */
#if defined(STM32U5)
// GPIO复用功能定义：停止模式相关定义别名
#define GPIO_AF0_S2DSTOP                          GPIO_AF0_SRDSTOP
// GPIO复用功能定义：低功耗GPIO复用功能别名
#define GPIO_AF11_LPGPIO                          GPIO_AF11_LPGPIO1
#endif /* STM32U5 */

#if defined(STM32WBA)
// 以下宏定义针对STM32WBA系列，将具体的RF(射频)引脚功能统一映射到通用的GPIO_AF11_RF
#define GPIO_AF11_RF_ANTSW0    GPIO_AF11_RF        // 射频天线开关0
#define GPIO_AF11_RF_ANTSW1    GPIO_AF11_RF        // 射频天线开关1
#define GPIO_AF11_RF_ANTSW2    GPIO_AF11_RF        // 射频天线开关2
#define GPIO_AF11_RF_IO1       GPIO_AF11_RF        // 射频IO1
#define GPIO_AF11_RF_IO2       GPIO_AF11_RF        // 射频IO2
#define GPIO_AF11_RF_IO3       GPIO_AF11_RF        // 射频IO3
#define GPIO_AF11_RF_IO4       GPIO_AF11_RF        // 射频IO4
#define GPIO_AF11_RF_IO5       GPIO_AF11_RF        // 射频IO5
#define GPIO_AF11_RF_IO6       GPIO_AF11_RF        // 射频IO6
#define GPIO_AF11_RF_IO7       GPIO_AF11_RF        // 射频IO7
#define GPIO_AF11_RF_IO8       GPIO_AF11_RF        // 射频IO8
#define GPIO_AF11_RF_IO9       GPIO_AF11_RF        // 射频IO9
#endif /* STM32WBA */
/**
  * @}
  */

/** @defgroup HAL_GTZC_Aliased_Defines HAL GTZC Aliased Defines maintained for legacy purpose
  * @{
  */
#if defined(STM32U5)
// GTZC(全局信任区控制器)外设定义别名，用于兼容旧命名
#define GTZC_PERIPH_DCMI                      GTZC_PERIPH_DCMI_PSSI    // DCMI外设别名
#define GTZC_PERIPH_LTDC                      GTZC_PERIPH_LTDCUSB      // LTDC外设别名
#endif /* STM32U5 */
#if defined(STM32H5)
// GTZC外设定义别名，针对STM32H5系列
#define GTZC_PERIPH_DAC12                     GTZC_PERIPH_DAC1         // DAC1/2外设别名
#define GTZC_PERIPH_ADC12                     GTZC_PERIPH_ADC          // ADC1/2外设别名
#define GTZC_PERIPH_USBFS                     GTZC_PERIPH_USB          // USB全速设备别名
#endif /* STM32H5 */
#if defined(STM32H5) || defined(STM32U5)
// GTZC MPCBB(存储保护控制块)相关配置别名，修正了拼写错误(MCPBB -> MPCBB)并保持兼容性
#define GTZC_MCPBB_NB_VCTR_REG_MAX            GTZC_MPCBB_NB_VCTR_REG_MAX            // 最大向量寄存器数量
#define GTZC_MCPBB_NB_LCK_VCTR_REG_MAX        GTZC_MPCBB_NB_LCK_VCTR_REG_MAX        // 最大锁定向量寄存器数量
#define GTZC_MCPBB_SUPERBLOCK_UNLOCKED        GTZC_MPCBB_SUPERBLOCK_UNLOCKED        // 超级块未锁定状态
#define GTZC_MCPBB_SUPERBLOCK_LOCKED          GTZC_MPCBB_SUPERBLOCK_LOCKED          // 超级块锁定状态
#define GTZC_MCPBB_BLOCK_NSEC                 GTZC_MPCBB_BLOCK_NSEC                 // 块非安全属性
#define GTZC_MCPBB_BLOCK_SEC                  GTZC_MPCBB_BLOCK_SEC                  // 块安全属性
#define GTZC_MCPBB_BLOCK_NPRIV                GTZC_MPCBB_BLOCK_NPRIV                // 块非特权访问
#define GTZC_MCPBB_BLOCK_PRIV                 GTZC_MPCBB_BLOCK_PRIV                 // 块特权访问
#define GTZC_MCPBB_LOCK_OFF                   GTZC_MPCBB_LOCK_OFF                   // 锁定关闭
#define GTZC_MCPBB_LOCK_ON                    GTZC_MPCBB_LOCK_ON                    // 锁定开启
#endif /* STM32H5 || STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_HRTIM_Aliased_Macros HAL HRTIM Aliased Macros maintained for legacy purpose
  * @{
  */
// HRTIM(高分辨率定时器)延迟保护模式别名定义
#define HRTIM_TIMDELAYEDPROTECTION_DISABLED           HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DISABLED            // 禁用延迟保护
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_EEV6    // 延迟输出1，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_EEV6    // 延迟输出2，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV68  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV6    // 延迟两者，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV68     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV6       // 平衡模式，外部事件6/8
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT1_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT1_DEEV7   // 延迟输出1，去抖动外部事件7/9
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDOUT2_DEEV79 HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDOUT2_DEEV7   // 延迟输出2，去抖动外部事件7/9
#define HRTIM_TIMDELAYEDPROTECTION_DELAYEDBOTH_EEV79  HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_DELAYEDBOTH_EEV7    // 延迟两者，外部事件7/9
#define HRTIM_TIMDELAYEDPROTECTION_BALANCED_EEV79     HRTIM_TIMER_A_B_C_DELAYEDPROTECTION_BALANCED_EEV7       // 平衡模式，外部事件7/9

// HRTIM 寄存器操作宏别名，统一命名风格（大小写兼容）
#define __HAL_HRTIM_SetCounter        __HAL_HRTIM_SETCOUNTER        // 设置计数器值
#define __HAL_HRTIM_GetCounter        __HAL_HRTIM_GETCOUNTER        // 获取计数器值
#define __HAL_HRTIM_SetPeriod         __HAL_HRTIM_SETPERIOD         // 设置周期值
#define __HAL_HRTIM_GetPeriod         __HAL_HRTIM_GETPERIOD         // 获取周期值
#define __HAL_HRTIM_SetClockPrescaler __HAL_HRTIM_SETCLOCKPRESCALER // 设置时钟预分频
#define __HAL_HRTIM_GetClockPrescaler __HAL_HRTIM_GETCLOCKPRESCALER // 获取时钟预分频
#define __HAL_HRTIM_SetCompare        __HAL_HRTIM_SETCOMPARE        // 设置比较值
#define __HAL_HRTIM_GetCompare        __HAL_HRTIM_GETCOMPARE        // 获取比较值

#if defined(STM32G4)
// HRTIM 外部事件计数器配置相关函数别名，针对STM32G4系列
#define HAL_HRTIM_ExternalEventCounterConfig    HAL_HRTIM_ExtEventCounterConfig    // 配置外部事件计数器
#define HAL_HRTIM_ExternalEventCounterEnable    HAL_HRTIM_ExtEventCounterEnable    // 使能外部事件计数器
#define HAL_HRTIM_ExternalEventCounterDisable   HAL_HRTIM_ExtEventCounterDisable   // 禁用外部事件计数器
#define HAL_HRTIM_ExternalEventCounterReset     HAL_HRTIM_ExtEventCounterReset     // 复位外部事件计数器
// HRTIM 事件计数器相关定义
#define HRTIM_TIMEEVENT_A                       HRTIM_EVENTCOUNTER_A               // 事件计数器A
#define HRTIM_TIMEEVENT_B                       HRTIM_EVENTCOUNTER_B               // 事件计数器B
#define HRTIM_TIMEEVENTRESETMODE_UNCONDITIONAL  HRTIM_EVENTCOUNTER_RSTMODE_UNCONDITIONAL // 无条件复位模式
#define HRTIM_TIMEEVENTRESETMODE_CONDITIONAL    HRTIM_EVENTCOUNTER_RSTMODE_CONDITIONAL   // 有条件复位模式
#endif /* STM32G4 */

#if defined(STM32H7)
// HRTIM 输出设置/复位事件定义，针对STM32H7系列
// 这些宏定义了定时器之间的交叉触发事件，用于设置输出
#define HRTIM_OUTPUTSET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器A输出设置事件1：定时器B比较1
#define HRTIM_OUTPUTSET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2    // 定时器A输出设置事件2：定时器B比较2
#define HRTIM_OUTPUTSET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3    // 定时器A输出设置事件3：定时器C比较2
#define HRTIM_OUTPUTSET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4    // 定时器A输出设置事件4：定时器C比较3
#define HRTIM_OUTPUTSET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5    // 定时器A输出设置事件5：定时器D比较1
#define HRTIM_OUTPUTSET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6    // 定时器A输出设置事件6：定时器D比较2
#define HRTIM_OUTPUTSET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7    // 定时器A输出设置事件7：定时器E比较3
#define HRTIM_OUTPUTSET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8    // 定时器A输出设置事件8：定时器E比较4
#define HRTIM_OUTPUTSET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9    // 定时器A输出设置事件9：定时器F比较4
#define HRTIM_OUTPUTSET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器B输出设置事件1：定时器A比较1
#define HRTIM_OUTPUTSET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2    // 定时器B输出设置事件2：定时器A比较2
#define HRTIM_OUTPUTSET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3    // 定时器B输出设置事件3：定时器C比较3
#define HRTIM_OUTPUTSET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4    // 定时器B输出设置事件4：定时器C比较4
#define HRTIM_OUTPUTSET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5    // 定时器B输出设置事件5：定时器D比较3
#define HRTIM_OUTPUTSET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6    // 定时器B输出设置事件6：定时器D比较4
#define HRTIM_OUTPUTSET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7    // 定时器B输出设置事件7：定时器E比较1
#define HRTIM_OUTPUTSET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8    // 定时器B输出设置事件8：定时器E比较2
#define HRTIM_OUTPUTSET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9    // 定时器B输出设置事件9：定时器F比较3
#define HRTIM_OUTPUTSET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器C输出设置事件1：定时器A比较1
#define HRTIM_OUTPUTSET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2    // 定时器C输出设置事件2：定时器A比较2
#define HRTIM_OUTPUTSET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3    // 定时器C输出设置事件3：定时器B比较2
#define HRTIM_OUTPUTSET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4    // 定时器C输出设置事件4：定时器B比较3
#define HRTIM_OUTPUTSET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5    // 定时器C输出设置事件5：定时器D比较2
#define HRTIM_OUTPUTSET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6    // 定时器C输出设置事件6：定时器D比较4
#define HRTIM_OUTPUTSET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7    // 定时器C输出设置事件7：定时器E比较3
#define HRTIM_OUTPUTSET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8    // 定时器C输出设置事件8：定时器E比较4
#define HRTIM_OUTPUTSET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9    // 定时器C输出设置事件9：定时器F比较2
#define HRTIM_OUTPUTSET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1    // 定时器D输出设置事件1：定时器A比较1
#define HRTIM_OUTPUTSET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2    // 定时器D输出设置事件2：定时器A比较4
#define HRTIM_OUTPUTSET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3    // 定时器D输出设置事件3：定时器B比较2
#define HRTIM_OUTPUTSET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4    // 定时器D输出设置事件4：定时器B比较4
#define HRTIM_OUTPUTSET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5    // 定时器D输出设置事件5：定时器C比较4
#define HRTIM_OUTPUTSET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6    // 定时器D输出设置事件6：定时器E比较1
#define HRTIM_OUTPUTSET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7    // 定时器D输出设置事件7：定时器E比较4
#define HRTIM_OUTPUTSET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8    // 定时器D输出设置事件8：定时器F比较1
#define HRTIM_OUTPUTSET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9    // 定时器D输出设置事件9：定时器F比较3
#define HRTIM_OUTPUTSET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1    // 定时器E输出设置事件1：定时器A比较4
#define HRTIM_OUTPUTSET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2    // 定时器E输出设置事件2：定时器B比较3
#define HRTIM_OUTPUTSET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3    // 定时器E输出设置事件3：定时器B比较4
#define HRTIM_OUTPUTSET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4    // 定时器E输出设置事件4：定时器C比较1
#define HRTIM_OUTPUTSET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5    // 定时器E输出设置事件5：定时器D比较2
#define HRTIM_OUTPUTSET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6    // 定时器E输出设置事件6：定时器D比较1
#define HRTIM_OUTPUTSET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7    // 定时器E输出设置事件7：定时器D比较2
#define HRTIM_OUTPUTSET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8    // 定时器E输出设置事件8：定时器F比较3
#define HRTIM_OUTPUTSET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9    // 定时器E输出设置事件9：定时器F比较4
#define HRTIM_OUTPUTSET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1    // 定时器F输出设置事件1：定时器A比较3
#define HRTIM_OUTPUTSET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2    // 定时器F输出设置事件2：定时器B比较1
#define HRTIM_OUTPUTSET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3    // 定时器F输出设置事件3：定时器B比较4
#define HRTIM_OUTPUTSET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4    // 定时器F输出设置事件4：定时器C比较1
#define HRTIM_OUTPUTSET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5    // 定时器F输出设置事件5：定时器C比较4
#define HRTIM_OUTPUTSET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6    // 定时器F输出设置事件6：定时器D比较3
#define HRTIM_OUTPUTSET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7    // 定时器F输出设置事件7：定时器D比较4
#define HRTIM_OUTPUTSET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8    // 定时器F输出设置事件8：定时器E比较2
#define HRTIM_OUTPUTSET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9    // 定时器F输出设置事件9：定时器E比较3

// HRTIM 输出复位事件定义，逻辑与设置事件类似，用于复位输出
#define HRTIM_OUTPUTRESET_TIMAEV1_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMAEV2_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMAEV3_TIMCCMP2 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMAEV4_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMAEV5_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMAEV6_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMAEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMAEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMAEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMBEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMBEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMBEV3_TIMCCMP3 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMBEV4_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMBEV5_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMBEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMBEV7_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMBEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMBEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMCEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMCEV2_TIMACMP2 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMCEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMCEV4_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMCEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMCEV6_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMCEV7_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMCEV8_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMCEV9_TIMFCMP2 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMDEV1_TIMACMP1 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMDEV2_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMDEV3_TIMBCMP2 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMDEV4_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMDEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMDEV6_TIMECMP1 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMDEV7_TIMECMP4 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMDEV8_TIMFCMP1 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMDEV9_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMEEV1_TIMACMP4 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMEEV2_TIMBCMP3 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMEEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMEEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMEEV5_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMEEV6_TIMDCMP1 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMEEV7_TIMDCMP2 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMEEV8_TIMFCMP3 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMEEV9_TIMFCMP4 HRTIM_OUTPUTSET_TIMEV_9
#define HRTIM_OUTPUTRESET_TIMFEV1_TIMACMP3 HRTIM_OUTPUTSET_TIMEV_1
#define HRTIM_OUTPUTRESET_TIMFEV2_TIMBCMP1 HRTIM_OUTPUTSET_TIMEV_2
#define HRTIM_OUTPUTRESET_TIMFEV3_TIMBCMP4 HRTIM_OUTPUTSET_TIMEV_3
#define HRTIM_OUTPUTRESET_TIMFEV4_TIMCCMP1 HRTIM_OUTPUTSET_TIMEV_4
#define HRTIM_OUTPUTRESET_TIMFEV5_TIMCCMP4 HRTIM_OUTPUTSET_TIMEV_5
#define HRTIM_OUTPUTRESET_TIMFEV6_TIMDCMP3 HRTIM_OUTPUTSET_TIMEV_6
#define HRTIM_OUTPUTRESET_TIMFEV7_TIMDCMP4 HRTIM_OUTPUTSET_TIMEV_7
#define HRTIM_OUTPUTRESET_TIMFEV8_TIMECMP2 HRTIM_OUTPUTSET_TIMEV_8
#define HRTIM_OUTPUTRESET_TIMFEV9_TIMECMP3 HRTIM_OUTPUTSET_TIMEV_9
#endif /* STM32H7 */

#if defined(STM32F3)
/** @brief Constants defining available sources associated to external events.
  * @brief 定义与外部事件相关的可用源的常量
  */
#define HRTIM_EVENTSRC_1              (0x00000000U)    // 事件源1
#define HRTIM_EVENTSRC_2              (HRTIM_EECR1_EE1SRC_0)    // 事件源2
#define HRTIM_EVENTSRC_3              (HRTIM_EECR1_EE1SRC_1)    // 事件源3
#define HRTIM_EVENTSRC_4              (HRTIM_EECR1_EE1SRC_1 | HRTIM_EECR1_EE1SRC_0)    // 事件源4

/** @brief Constants defining the DLL calibration periods (in micro seconds)
  * @brief 定义DLL校准周期的常量（单位：微秒）
  */
#define HRTIM_CALIBRATIONRATE_7300             0x00000000U    // 校准周期7300us
#define HRTIM_CALIBRATIONRATE_910              (HRTIM_DLLCR_CALRTE_0)    // 校准周期910us
#define HRTIM_CALIBRATIONRATE_114              (HRTIM_DLLCR_CALRTE_1)    // 校准周期114us
#define HRTIM_CALIBRATIONRATE_14               (HRTIM_DLLCR_CALRTE_1 | HRTIM_DLLCR_CALRTE_0)    // 校准周期14us

#endif /* STM32F3 */
/**
  * @}
  */

/** @defgroup HAL_I2C_Aliased_Defines HAL I2C Aliased Defines maintained for legacy purpose
  * @{
  */
// I2C 配置参数别名，将旧的 ENABLED/DISABLED 命名映射到新的 ENABLE/DISABLE
#define I2C_DUALADDRESS_DISABLED                I2C_DUALADDRESS_DISABLE    // 禁用双地址模式
#define I2C_DUALADDRESS_ENABLED                 I2C_DUALADDRESS_ENABLE     // 使能双地址模式
#define I2C_GENERALCALL_DISABLED                I2C_GENERALCALL_DISABLE    // 禁用通用呼叫
#define I2C_GENERALCALL_ENABLED                 I2C_GENERALCALL_ENABLE     // 使能通用呼叫
#define I2C_NOSTRETCH_DISABLED                  I2C_NOSTRETCH_DISABLE      // 禁用时钟拉伸
#define I2C_NOSTRETCH_ENABLED                   I2C_NOSTRETCH_ENABLE       // 使能时钟拉伸
#define I2C_ANALOGFILTER_ENABLED                I2C_ANALOGFILTER_ENABLE    // 使能模拟滤波器
#define I2C_ANALOGFILTER_DISABLED               I2C_ANALOGFILTER_DISABLE   // 禁用模拟滤波器
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F3) || defined(STM32G0) || defined(STM32L4) || \
    defined(STM32L1) || defined(STM32F7)
// I2C 状态枚举别名，统一状态命名
#define HAL_I2C_STATE_MEM_BUSY_TX               HAL_I2C_STATE_BUSY_TX      // 存储器发送忙状态
#define HAL_I2C_STATE_MEM_BUSY_RX               HAL_I2C_STATE_BUSY_RX      // 存储器接收忙状态
#define HAL_I2C_STATE_MASTER_BUSY_TX            HAL_I2C_STATE_BUSY_TX      // 主机发送忙状态
#define HAL_I2C_STATE_MASTER_BUSY_RX            HAL_I2C_STATE_BUSY_RX      // 主机接收忙状态
#define HAL_I2C_STATE_SLAVE_BUSY_TX             HAL_I2C_STATE_BUSY_TX      // 从机发送忙状态
#define HAL_I2C_STATE_SLAVE_BUSY_RX             HAL_I2C_STATE_BUSY_RX      // 从机接收忙状态
#endif
/**
  * @}
  */

/** @defgroup HAL_IRDA_Aliased_Defines HAL IRDA Aliased Defines maintained for legacy purpose
  * @{
  */
// IRDA(红外数据协会)模块配置别名
#define IRDA_ONE_BIT_SAMPLE_DISABLED            IRDA_ONE_BIT_SAMPLE_DISABLE    // 禁用单比特采样
#define IRDA_ONE_BIT_SAMPLE_ENABLED             IRDA_ONE_BIT_SAMPLE_ENABLE     // 使能单比特采样

/**
  * @}
  */

/** @defgroup HAL_IWDG_Aliased_Defines HAL IWDG Aliased Defines maintained for legacy purpose
  * @{
  */
// IWDG(独立看门狗)键值定义别名
#define KR_KEY_RELOAD                   IWDG_KEY_RELOAD            // 重载键值
#define KR_KEY_ENABLE                   IWDG_KEY_ENABLE            // 使能键值
#define KR_KEY_EWA                      IWDG_KEY_WRITE_ACCESS_ENABLE    // 使能写访问键值
#define KR_KEY_DWA                      IWDG_KEY_WRITE_ACCESS_DISABLE   // 禁用写访问键值
/**
  * @}
  */

/** @defgroup HAL_LPTIM_Aliased_Defines HAL LPTIM Aliased Defines maintained for legacy purpose
  * @{
  */

// LPTIM(低功耗定时器)时钟采样时间定义，修正拼写错误 TRANSISTION -> TRANSITION
#define LPTIM_CLOCKSAMPLETIME_DIRECTTRANSISTION LPTIM_CLOCKSAMPLETIME_DIRECTTRANSITION    // 直接转换时钟采样时间
#define LPTIM_CLOCKSAMPLETIME_2TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_2TRANSITIONS        // 2次转换时钟采样时间
#define LPTIM_CLOCKSAMPLETIME_4TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_4TRANSITIONS        // 4次转换时钟采样时间
#define LPTIM_CLOCKSAMPLETIME_8TRANSISTIONS     LPTIM_CLOCKSAMPLETIME_8TRANSITIONS        // 8次转换时钟采样时间

// LPTIM 时钟极性定义别名
#define LPTIM_CLOCKPOLARITY_RISINGEDGE          LPTIM_CLOCKPOLARITY_RISING            // 上升沿
#define LPTIM_CLOCKPOLARITY_FALLINGEDGE         LPTIM_CLOCKPOLARITY_FALLING           // 下降沿
#define LPTIM_CLOCKPOLARITY_BOTHEDGES           LPTIM_CLOCKPOLARITY_RISING_FALLING    // 双沿

// LPTIM 触发采样时间定义，修正拼写错误
#define LPTIM_TRIGSAMPLETIME_DIRECTTRANSISTION  LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION    // 直接转换触发采样时间
#define LPTIM_TRIGSAMPLETIME_2TRANSISTIONS      LPTIM_TRIGSAMPLETIME_2TRANSITIONS        // 2次转换触发采样时间
#define LPTIM_TRIGSAMPLETIME_4TRANSISTIONS      LPTIM_TRIGSAMPLETIME_4TRANSITIONS        // 4次转换触发采样时间
#define LPTIM_TRIGSAMPLETIME_8TRANSISTIONS      LPTIM_TRIGSAMPLETIME_8TRANSITIONS        // 8次转换触发采样时间

/* The following 3 definition have also been present in a temporary version of lptim.h */
/* They need to be renamed also to the right name, just in case */
/* 以下3个定义也曾出现在lptim.h的临时版本中，为了以防万一，也需要重命名为正确的名称 */
#define LPTIM_TRIGSAMPLETIME_2TRANSITION        LPTIM_TRIGSAMPLETIME_2TRANSITIONS
#define LPTIM_TRIGSAMPLETIME_4TRANSITION        LPTIM_TRIGSAMPLETIME_4TRANSITIONS
#define LPTIM_TRIGSAMPLETIME_8TRANSITION        LPTIM_TRIGSAMPLETIME_8TRANSITIONS


/** @defgroup HAL_LPTIM_Aliased_Defines HAL LPTIM Aliased Defines maintained for legacy purpose
  * @{
  */
// LPTIM 函数别名，将读取比较值函数映射为读取捕获值函数
#define HAL_LPTIM_ReadCompare      HAL_LPTIM_ReadCapturedValue
/**
  * @}
  */

#if defined(STM32U5)
// LPTIM 中断状态标志定义，针对STM32U5系列
#define LPTIM_ISR_CC1        LPTIM_ISR_CC1IF    // 捕获/比较1中断标志
#define LPTIM_ISR_CC2        LPTIM_ISR_CC2IF    // 捕获/比较2中断标志
#define LPTIM_CHANNEL_ALL    0x00000000U        // 所有通道
#endif /* STM32U5 */
/**
  * @}
  */

/** @defgroup HAL_NAND_Aliased_Defines HAL NAND Aliased Defines maintained for legacy purpose
  * @{
  */
// NAND Flash 驱动函数别名，默认映射为8位宽度操作函数
#define HAL_NAND_Read_Page              HAL_NAND_Read_Page_8b        // 读取页（8位）
#define HAL_NAND_Write_Page             HAL_NAND_Write_Page_8b       // 写入页（8位）
#define HAL_NAND_Read_SpareArea         HAL_NAND_Read_SpareArea_8b   // 读取备用区（8位）
#define HAL_NAND_Write_SpareArea        HAL_NAND_Write_SpareArea_8b  // 写入备用区（8位）

// NAND Flash 类型定义别名
#define NAND_AddressTypedef             NAND_AddressTypeDef          // NAND地址结构体类型别名

// NAND Flash 宏定义别名，移除前导下划线以符合命名规范
#define __ARRAY_ADDRESS                 ARRAY_ADDRESS                // 数组地址宏
#define __ADDR_1st_CYCLE                ADDR_1ST_CYCLE               // 地址第1周期
#define __ADDR_2nd_CYCLE                ADDR_2ND_CYCLE               // 地址第2周期
#define __ADDR_3rd_CYCLE                ADDR_3RD_CYCLE               // 地址第3周期
#define __ADDR_4th_CYCLE                ADDR_4TH_CYCLE               // 地址第4周期
/**
  * @}
  */

/** @defgroup HAL_NOR_Aliased_Defines HAL NOR Aliased Defines maintained for legacy purpose
  * @{
  */
// NOR Flash 状态类型定义别名
#define NOR_StatusTypedef              HAL_NOR_StatusTypeDef         // NOR状态枚举类型别名
#define NOR_SUCCESS                    HAL_NOR_STATUS_SUCCESS        // 操作成功
#define NOR_ONGOING                    HAL_NOR_STATUS_ONGOING        // 操作进行中
#define NOR_ERROR                      HAL_NOR_STATUS_ERROR          // 操作错误
#define NOR_TIMEOUT                    HAL_NOR_STATUS_TIMEOUT        // 操作超时

// NOR Flash 宏定义别名
#define __NOR_WRITE                    NOR_WRITE                     // NOR写操作宏
#define __NOR_ADDR_SHIFT               NOR_ADDR_SHIFT                // NOR地址移位宏
/**
  * @}
  */

/** @defgroup HAL_OPAMP_Aliased_Defines HAL OPAMP Aliased Defines maintained for legacy purpose
  * @{
  */

// 运算放大器(OPAMP)输入引脚定义别名，将VPx/VMx映射到IOx命名方式
#define OPAMP_NONINVERTINGINPUT_VP0           OPAMP_NONINVERTINGINPUT_IO0    // 同相输入端IO0
#define OPAMP_NONINVERTINGINPUT_VP1           OPAMP_NONINVERTINGINPUT_IO1    // 同相输入端IO1
#define OPAMP_NONINVERTINGINPUT_VP2           OPAMP_NONINVERTINGINPUT_IO2    // 同相输入端IO2
#define OPAMP_NONINVERTINGINPUT_VP3           OPAMP_NONINVERTINGINPUT_IO3    // 同相输入端IO3

// 运算放大器次级同相输入引脚定义别名
#define OPAMP_SEC_NONINVERTINGINPUT_VP0       OPAMP_SEC_NONINVERTINGINPUT_IO0    // 次级同相输入端IO0
#define OPAMP_SEC_NONINVERTINGINPUT_VP1       OPAMP_SEC_NONINVERTINGINPUT_IO1    // 次级同相输入端IO1
#define OPAMP_SEC_NONINVERTINGINPUT_VP2       OPAMP_SEC_NONINVERTINGINPUT_IO2    // 次级同相输入端IO2
#define OPAMP_SEC_NONINVERTINGINPUT_VP3       OPAMP_SEC_NONINVERTINGINPUT_IO3    // 次级同相输入端IO3

// 运算放大器反相输入引脚定义别名
#define OPAMP_INVERTINGINPUT_VM0              OPAMP_INVERTINGINPUT_IO0    // 反相输入端IO0
#define OPAMP_INVERTINGINPUT_VM1              OPAMP_INVERTINGINPUT_IO1    // 反相输入端IO1

// 运算放大器反相输入引脚定义别名（IOPAMP前缀）
#define IOPAMP_INVERTINGINPUT_VM0             OPAMP_INVERTINGINPUT_IO0    // 反相输入端IO0
#define IOPAMP_INVERTINGINPUT_VM1             OPAMP_INVERTINGINPUT_IO1    // 反相输入端IO1

// 运算放大器次级反相输入引脚定义别名
#define OPAMP_SEC_INVERTINGINPUT_VM0          OPAMP_SEC_INVERTINGINPUT_IO0    // 次级反相输入端IO0
#define OPAMP_SEC_INVERTINGINPUT_VM1          OPAMP_SEC_INVERTINGINPUT_IO1    // 次级反相输入端IO1

// 运算放大器反相输入引脚别名
#define OPAMP_INVERTINGINPUT_VINM             OPAMP_SEC_INVERTINGINPUT_IO1    // 反相输入端VINM

// 运算放大器PGA(可编程增益放大器)连接模式定义
#define OPAMP_PGACONNECT_NO                   OPAMP_PGA_CONNECT_INVERTINGINPUT_NO    // PGA不连接反相输入
#define OPAMP_PGACONNECT_VM0                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO0   // PGA连接反相输入IO0
#define OPAMP_PGACONNECT_VM1                  OPAMP_PGA_CONNECT_INVERTINGINPUT_IO1   // PGA连接反相输入IO1

#if defined(STM32L1) || defined(STM32L4) || defined(STM32L5) || defined(STM32H7) || defined(STM32G4) || defined(STM32U5)
// 运算放大器 MSP 回调函数 ID 定义别名
#define HAL_OPAMP_MSP_INIT_CB_ID       HAL_OPAMP_MSPINIT_CB_ID       // MSP初始化回调ID
#define HAL_OPAMP_MSP_DEINIT_CB_ID     HAL_OPAMP_MSPDEINIT_CB_ID     // MSP反初始化回调ID
#endif

#if defined(STM32L4) || defined(STM32L5)
// 运算放大器功耗模式定义，针对STM32L4/L5系列
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALPOWER    // 正常功耗模式
#elif defined(STM32G4)
// 运算放大器功耗模式定义，针对STM32G4系列
#define OPAMP_POWERMODE_NORMAL                OPAMP_POWERMODE_NORMALSPEED    // 正常速度模式
#endif

/**
  * @}
  */

/** @defgroup HAL_I2S_Aliased_Defines HAL I2S Aliased Defines maintained for legacy purpose
  * @{
  */
// I2S 标准定义别名，修正拼写错误 PHILLIPS -> PHILIPS
#define I2S_STANDARD_PHILLIPS      I2S_STANDARD_PHILIPS

#if defined(STM32H7)
// I2S 中断标志定义别名，针对STM32H7系列
#define I2S_IT_TXE               I2S_IT_TXP    // 发送缓冲区空中断
#define I2S_IT_RXNE              I2S_IT_RXP    // 接收缓冲区非空中断
