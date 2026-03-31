#if defined (STM32F4)  // 如果定义了STM32F4系列
#define __HAL_PVD_EXTI_ENABLE_IT(PWR_EXTI_LINE_PVD)         __HAL_PWR_PVD_EXTI_ENABLE_IT()  // 启用PVD（可编程电压检测器）外部中断
#define __HAL_PVD_EXTI_DISABLE_IT(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_DISABLE_IT() // 禁用PVD外部中断
#define __HAL_PVD_EXTI_GET_FLAG(PWR_EXTI_LINE_PVD)          __HAL_PWR_PVD_EXTI_GET_FLAG()   // 获取PVD标志位状态
#define __HAL_PVD_EXTI_CLEAR_FLAG(PWR_EXTI_LINE_PVD)        __HAL_PWR_PVD_EXTI_CLEAR_FLAG() // 清除PVD标志位
#define __HAL_PVD_EXTI_GENERATE_SWIT(PWR_EXTI_LINE_PVD)     __HAL_PWR_PVD_EXTI_GENERATE_SWIT() // 生成PVD软件中断（SWIT: Software Interrupt）
#else  // 其他STM32系列
#define __HAL_PVD_EXTI_CLEAR_FLAG                                __HAL_PWR_PVD_EXTI_CLEAR_FLAG  // 清除PVD标志位的别名宏
#define __HAL_PVD_EXTI_DISABLE_IT                                __HAL_PWR_PVD_EXTI_DISABLE_IT // 禁用PVD外部中断的别名宏
#define __HAL_PVD_EXTI_ENABLE_IT                                 __HAL_PWR_PVD_EXTI_ENABLE_IT  // 启用PVD外部中断的别名宏
#define __HAL_PVD_EXTI_GENERATE_SWIT                             __HAL_PWR_PVD_EXTI_GENERATE_SWIT // 生成PVD软件中断的别名宏
#define __HAL_PVD_EXTI_GET_FLAG                                  __HAL_PWR_PVD_EXTI_GET_FLAG   // 获取PVD标志位的别名宏
#endif /* STM32F4 */
/**
  * @}
  */


/** @defgroup HAL_RCC_Aliased 为向后兼容而维护的HAL RCC（复位和时钟控制）别名
  * @{
  */

#define RCC_StopWakeUpClock_MSI     RCC_STOP_WAKEUPCLOCK_MSI  // 停止唤醒时钟使用MSI（内部多速振荡器）的别名
#define RCC_StopWakeUpClock_HSI     RCC_STOP_WAKEUPCLOCK_HSI  // 停止唤醒时钟使用HSI（内部高速振荡器）的别名

#define HAL_RCC_CCSCallback HAL_RCC_CSSCallback  // 时钟安全系统（CSS）回调函数的别名，用于兼容旧代码

#define HAL_RC48_EnableBuffer_Cmd(cmd) (((cmd)==ENABLE) ? \
                                        HAL_RCCEx_EnableHSI48_VREFINT() : HAL_RCCEx_DisableHSI48_VREFINT())  // 宏函数：根据命令启用或禁用HSI48（48MHz内部振荡器）和VREFINT（内部电压参考）缓冲区