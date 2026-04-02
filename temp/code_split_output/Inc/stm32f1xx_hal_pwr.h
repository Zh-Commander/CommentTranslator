/**
  ******************************************************************************
  * @file    stm32f1xx_hal_pwr.h
  * @author  MCD Application Team
  * @brief   Header file of PWR HAL module.
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

/* 定义防止递归包含 -----------------------------------------------------*/
#ifndef __STM32F1xx_HAL_PWR_H
#define __STM32F1xx_HAL_PWR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup PWR
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/

/** @defgroup PWR_Exported_Types PWR Exported Types
  * @{
  */ 

/**
  * @brief  PWR PVD configuration structure definition
  *         PWR PVD(可编程电压检测器)配置结构体定义
  */
typedef struct
{
  uint32_t PVDLevel;   /*!< PVDLevel: Specifies the PVD detection level.
                            指定PVD检测电压阈值。
                            This parameter can be a value of @ref PWR_PVD_detection_level
                            该参数可以是 @ref PWR_PVD_detection_level 中的一个值 */

  uint32_t Mode;      /*!< Mode: Specifies the operating mode for the selected pins.
                           指定PVD中断/事件的工作模式。
                           This parameter can be a value of @ref PWR_PVD_Mode
                           该参数可以是 @ref PWR_PVD_Mode 中的一个值 */
}PWR_PVDTypeDef;


/**
  * @}
  */


/* 内部常量 --------------------------------------------------------*/

/** @addtogroup PWR_Private_Constants
  * @{
  */ 

#define PWR_EXTI_LINE_PVD  ((uint32_t)0x00010000)  /*!< External interrupt line 16 Connected to the PVD EXTI Line */
                                                    /*!< 外部中断线16，连接到PVD外部中断线 */

/**
  * @}
  */

 
/* 导出常量 --------------------------------------------------------*/

/** @defgroup PWR_Exported_Constants PWR Exported Constants
  * @{
  */ 

/** @defgroup PWR_PVD_detection_level PWR PVD detection level
  *         PWR PVD 检测电压阈值等级
  * @{
  */
#define PWR_PVDLEVEL_0                  PWR_CR_PLS_2V2  // 阈值 2.2V
#define PWR_PVDLEVEL_1                  PWR_CR_PLS_2V3  // 阈值 2.3V
#define PWR_PVDLEVEL_2                  PWR_CR_PLS_2V4  // 阈值 2.4V
#define PWR_PVDLEVEL_3                  PWR_CR_PLS_2V5  // 阈值 2.5V
#define PWR_PVDLEVEL_4                  PWR_CR_PLS_2V6  // 阈值 2.6V
#define PWR_PVDLEVEL_5                  PWR_CR_PLS_2V7  // 阈值 2.7V
#define PWR_PVDLEVEL_6                  PWR_CR_PLS_2V8  // 阈值 2.8V
#define PWR_PVDLEVEL_7                  PWR_CR_PLS_2V9  // 阈值 2.9V
                                                          
/**
  * @}
  */

/** @defgroup PWR_PVD_Mode PWR PVD Mode
  *         PWR PVD 工作模式
  * @{
  */
#define PWR_PVD_MODE_NORMAL                 0x00000000U   /*!< basic mode is used */
                                                          /*!< 基本模式(仅检测，不产生中断/事件) */
#define PWR_PVD_MODE_IT_RISING              0x00010001U   /*!< External Interrupt Mode with Rising edge trigger detection */
                                                          /*!< 外部中断模式，上升沿触发检测 */
#define PWR_PVD_MODE_IT_FALLING             0x00010002U   /*!< External Interrupt Mode with Falling edge trigger detection */
                                                          /*!< 外部中断模式，下降沿触发检测 */
#define PWR_PVD_MODE_IT_RISING_FALLING      0x00010003U   /*!< External Interrupt Mode with Rising/Falling edge trigger detection */
                                                          /*!< 外部中断模式，上升沿和下降沿都触发检测 */
#define PWR_PVD_MODE_EVENT_RISING           0x00020001U   /*!< Event Mode with Rising edge trigger detection */
                                                          /*!< 事件模式，上升沿触发检测 */
#define PWR_PVD_MODE_EVENT_FALLING          0x00020002U   /*!< Event Mode with Falling edge trigger detection */
                                                          /*!< 事件模式，下降沿触发检测 */
#define PWR_PVD_MODE_EVENT_RISING_FALLING   0x00020003U   /*!< Event Mode with Rising/Falling edge trigger detection */
                                                          /*!< 事件模式，上升沿和下降沿都触发检测 */

/**
  * @}
  */


/** @defgroup PWR_WakeUp_Pins PWR WakeUp Pins
  *         PWR 唤醒引脚定义
  * @{
  */

#define PWR_WAKEUP_PIN1                 PWR_CSR_EWUP    // 唤醒引脚1 (通常对应PA0)

/**
  * @}
  */

/** @defgroup PWR_Regulator_state_in_SLEEP_STOP_mode PWR Regulator state in SLEEP/STOP mode
  *         PWR 电压调节器在睡眠/停止模式下的状态
  * @{
  */
#define PWR_MAINREGULATOR_ON                        0x00000000U   // 主电压调节器开启(正常功耗模式)
#define PWR_LOWPOWERREGULATOR_ON                    PWR_CR_LPDS    // 低功耗电压调节器开启(进入低功耗模式)

/**
  * @}
  */

/** @defgroup PWR_SLEEP_mode_entry PWR SLEEP mode entry
  *         PWR 进入睡眠模式的方式
  * @{
  */
#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01)  // 使用 WFI (Wait For Interrupt) 指令进入睡眠
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02)  // 使用 WFE (Wait For Event) 指令进入睡眠

/**
  * @}
  */

/** @defgroup PWR_STOP_mode_entry PWR STOP mode entry
  *         PWR 进入停止模式的方式
  * @{
  */
#define PWR_STOPENTRY_WFI               ((uint8_t)0x01)  // 使用 WFI (Wait For Interrupt) 指令进入停止模式
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02)  // 使用 WFE (Wait For Event) 指令进入停止模式

/**
  * @}
  */

/** @defgroup PWR_Flag PWR Flag
  *         PWR 状态标志位
  * @{
  */
#define PWR_FLAG_WU                     PWR_CSR_WUF     // 唤醒标志位
#define PWR_FLAG_SB                     PWR_CSR_SBF     // 待机标志位
#define PWR_FLAG_PVDO                   PWR_CSR_PVDO    // PVD输出标志位


/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup PWR_Exported_Macros PWR Exported Macros
  * @{
  */

/** @brief  Check PWR flag is set or not.
  *         检查 PWR 标志位是否被置位
  * @param  __FLAG__: specifies the flag to check.
  *                   指定要检查的标志位。
  *           This parameter can be one of the following values:
  *             @arg PWR_FLAG_WU: Wake Up flag. This flag indicates that a wakeup event
  *                   was received from the WKUP pin or from the RTC alarm
  *                   An additional wakeup event is detected if the WKUP pin is enabled
  *                   (by setting the EWUP bit) when the WKUP pin level is already high.
  *                   唤醒标志。该标志表明从WKUP引脚或RTC闹钟接收到了唤醒事件。
  *             @arg PWR_FLAG_SB: StandBy flag. This flag indicates that the system was
  *                   resumed from StandBy mode.
  *                   待机标志。该标志表明系统从待机模式唤醒。
  *             @arg PWR_FLAG_PVDO: PVD Output. This flag is valid only if PVD is enabled
  *                   by the HAL_PWR_EnablePVD() function. The PVD is stopped by Standby mode
  *                   For this reason, this bit is equal to 0 after Standby or reset
  *                   until the PVDE bit is set.
  *                   PVD输出。该标志仅在通过 HAL_PWR_EnablePVD() 函数使能PVD后有效。
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  *         返回 __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_PWR_GET_FLAG(__FLAG__) ((PWR->CSR & (__FLAG__)) == (__FLAG__))

/** @brief  Clear the PWR's pending flags.
  *         清除 PWR 的挂起标志位
  * @param  __FLAG__: specifies the flag to clear.
  *                   指定要清除的标志位。
  *          This parameter can be one of the following values:
  *            @arg PWR_FLAG_WU: Wake Up flag
  *            @arg PWR_FLAG_SB: StandBy flag
  */
#define __HAL_PWR_CLEAR_FLAG(__FLAG__) SET_BIT(PWR->CR, ((__FLAG__) << 2))

/**
  * @brief Enable interrupt on PVD Exti Line 16.
  *        使能 PVD 外部中断线 16 的中断
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_IT()      SET_BIT(EXTI->IMR, PWR_EXTI_LINE_PVD)

/**
  * @brief Disable interrupt on PVD Exti Line 16. 
  *        禁用 PVD 外部中断线 16 的中断
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_IT()     CLEAR_BIT(EXTI->IMR, PWR_EXTI_LINE_PVD)

/**
  * @brief Enable event on PVD Exti Line 16.
  *        使能 PVD 外部中断线 16 的事件
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR, PWR_EXTI_LINE_PVD)

/**
  * @brief Disable event on PVD Exti Line 16.
  *        禁用 PVD 外部中断线 16 的事件
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR, PWR_EXTI_LINE_PVD)


/**
  * @brief  PVD EXTI line configuration: set falling edge trigger.  
  *         PVD EXTI 线配置：设置下降沿触发
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE()  SET_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)


/**
  * @brief Disable the PVD Extended Interrupt Falling Trigger.
  *        禁用 PVD 外部中断下降沿触发
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)


/**
  * @brief  PVD EXTI line configuration: set rising edge trigger.
  *         PVD EXTI 线配置：设置上升沿触发
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)

/**
  * @brief Disable the PVD Extended Interrupt Rising Trigger.
  *        禁用 PVD 外部中断上升沿触发
  * This parameter can be:
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)

/**
  * @brief  PVD EXTI line configuration: set rising & falling edge trigger.
  *         PVD EXTI 线配置：设置上升沿和下降沿触发
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_FALLING_EDGE()   __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();

/**
  * @brief Disable the PVD Extended Interrupt Rising & Falling Trigger.
  *        禁用 PVD 外部中断上升沿和下降沿触发
  * This parameter can be:
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_FALLING_EDGE()  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();



/**
  * @brief Check whether the specified PVD EXTI interrupt flag is set or not.
  *        检查指定的 PVD EXTI 中断标志位是否被置位
  * @retval EXTI PVD Line Status.
  *         返回 EXTI PVD 线状态。
  */
#define __HAL_PWR_PVD_EXTI_GET_FLAG()       (EXTI->PR & (PWR_EXTI_LINE_PVD))

/**
  * @brief Clear the PVD EXTI flag.
  *        清除 PVD EXTI 标志位
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_CLEAR_FLAG()     (EXTI->PR = (PWR_EXTI_LINE_PVD))

/**
  * @brief Generate a Software interrupt on selected EXTI line.
  *        在选定的 EXTI 线上产生软件中断
  * @retval None.
  */
#define __HAL_PWR_PVD_EXTI_GENERATE_SWIT()  SET_BIT(EXTI->SWIER, PWR_EXTI_LINE_PVD)
/**
  * @}
  */

/* 私有宏 -------------------------------------------------------------*/
/** @defgroup PWR_Private_Macros PWR Private Macros
  * @{
  */
// 判断 PVD 电压等级参数是否有效
#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLEVEL_0) || ((LEVEL) == PWR_PVDLEVEL_1)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_2) || ((LEVEL) == PWR_PVDLEVEL_3)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_4) || ((LEVEL) == PWR_PVDLEVEL_5)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_6) || ((LEVEL) == PWR_PVDLEVEL_7))


// 判断 PVD 模式参数是否有效
#define IS_PWR_PVD_MODE(MODE) (((MODE) == PWR_PVD_MODE_IT_RISING)|| ((MODE) == PWR_PVD_MODE_IT_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_IT_RISING_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING) || \
                              ((MODE) == PWR_PVD_MODE_EVENT_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_NORMAL)) 

// 判断唤醒引脚参数是否有效
#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN1))

// 判断电压调节器状态参数是否有效
#define IS_PWR_REGULATOR(REGULATOR) (((REGULATOR) == PWR_MAINREGULATOR_ON) || \
                                     ((REGULATOR) == PWR_LOWPOWERREGULATOR_ON))

// 判断睡眠模式进入方式参数是否有效
#define IS_PWR_SLEEP_ENTRY(ENTRY) (((ENTRY) == PWR_SLEEPENTRY_WFI) || ((ENTRY) == PWR_SLEEPENTRY_WFE))

// 判断停止模式进入方式参数是否有效
#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPENTRY_WFI) || ((ENTRY) == PWR_STOPENTRY_WFE))

/**
  * @}
  */



/* 导出函数 --------------------------------------------------------*/

/** @addtogroup PWR_Exported_Functions PWR Exported Functions
  * @{
  */
  
/** @addtogroup PWR_Exported_Functions_Group1 Initialization and de-initialization functions 
  * @{
  */

/* Initialization and de-initialization functions *******************************/
/* 初始化和反初始化函数 ***************************************************************/
void HAL_PWR_DeInit(void);              // PWR 反初始化，复位 PWR 寄存器
void HAL_PWR_EnableBkUpAccess(void);    // 使能对备份域的访问权限
void HAL_PWR_DisableBkUpAccess(void);   // 禁用对备份域的访问权限

/**
  * @}
  */

/** @addtogroup PWR_Exported_Functions_Group2 Peripheral Control functions 
  * @{
  */

/* Peripheral Control functions  ************************************************/
/* 外设控制函数 ****************************************************************/
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD); // 配置 PVD(可编程电压检测器)
/* #define HAL_PWR_ConfigPVD 12*/
void HAL_PWR_EnablePVD(void);           // 使能 PVD
void HAL_PWR_DisablePVD(void);          // 禁用 PVD

/* WakeUp pins configuration functions ****************************************/
/* 唤醒引脚配置函数 ************************************************************/
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);  // 使能唤醒引脚
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx); // 禁用唤醒引脚

/* Low Power modes configuration functions ************************************/
/* 低功耗模式配置函数 **********************************************************/
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);  // 进入停止模式
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry); // 进入睡眠模式
void HAL_PWR_EnterSTANDBYMode(void);  // 进入待机模式

void HAL_PWR_EnableSleepOnExit(void);  // 使能退出中断后进入睡眠模式
void HAL_PWR_DisableSleepOnExit(void); // 禁用退出中断后进入睡眠模式
void HAL_PWR_EnableSEVOnPend(void);    // 使能挂起中断/事件时发送事件
void HAL_PWR_DisableSEVOnPend(void);   // 禁用挂起中断/事件时发送事件



void HAL_PWR_PVD_IRQHandler(void);     // PVD 中断处理函数
void HAL_PWR_PVDCallback(void);        // PVD 中断回调函数
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


#endif /* __STM32F1xx_HAL_PWR_H */
