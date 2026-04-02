/**
  ******************************************************************************
  * @file    stm32f1xx_hal_pwr.h
  * @author  MCD Application Team
  * @brief   电源控制(PWR) HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录中的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义以防止递归包含 -------------------------------------*/
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

/** @defgroup PWR_Exported_Types PWR 导出类型
  * @{
  */ 

/**
  * @brief  PWR PVD(可编程电压检测器)配置结构体定义
  */
typedef struct
{
  uint32_t PVDLevel;   /* PVDLevel: 指定PVD检测电压阈值。
                            该参数可以是 @ref PWR_PVD_detection_level 中的一个值 */

  uint32_t Mode;      /* Mode: 指定选定引脚的操作模式(中断/事件触发方式)。
                           该参数可以是 @ref PWR_PVD_Mode 中的一个值 */
}PWR_PVDTypeDef;


/**
  * @}
  */


/* 内部常量 --------------------------------------------------------*/

/** @addtogroup PWR_Private_Constants
  * @{
  */ 

#define PWR_EXTI_LINE_PVD  ((uint32_t)0x00010000)  /* 外部中断线16，连接到PVD外部中断线 */

/**
  * @}
  */

 
/* 导出常量 --------------------------------------------------------*/

/** @defgroup PWR_Exported_Constants PWR 导出常量
  * @{
  */ 

/** @defgroup PWR_PVD_detection_level PWR PVD 检测电压阈值
  * @{
  */
/* PVD检测阈值级别配置，对应不同的电压值 */
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

/** @defgroup PWR_PVD_Mode PWR PVD 模式
  * @{
  */
/* PVD中断/事件触发模式配置 */
#define PWR_PVD_MODE_NORMAL                 0x00000000U   /* 常规模式，仅检测不产生中断/事件 */
#define PWR_PVD_MODE_IT_RISING              0x00010001U   /* 外部中断模式，上升沿触发检测 */
#define PWR_PVD_MODE_IT_FALLING             0x00010002U   /* 外部中断模式，下降沿触发检测 */
#define PWR_PVD_MODE_IT_RISING_FALLING      0x00010003U   /* 外部中断模式，上升沿和下降沿都触发检测 */
#define PWR_PVD_MODE_EVENT_RISING           0x00020001U   /* 事件模式，上升沿触发检测 */
#define PWR_PVD_MODE_EVENT_FALLING          0x00020002U   /* 事件模式，下降沿触发检测 */
#define PWR_PVD_MODE_EVENT_RISING_FALLING   0x00020003U   /* 事件模式，上升沿和下降沿都触发检测 */

/**
  * @}
  */


/** @defgroup PWR_WakeUp_Pins PWR 唤醒引脚
  * @{
  */

#define PWR_WAKEUP_PIN1                 PWR_CSR_EWUP  /* 唤醒引脚1 (WKUP引脚) */

/**
  * @}
  */

/** @defgroup PWR_Regulator_state_in_SLEEP_STOP_mode PWR 睡眠/停止模式下的稳压器状态
  * @{
  */
#define PWR_MAINREGULATOR_ON                        0x00000000U  /* 主稳压器开启，用于正常运行模式 */
#define PWR_LOWPOWERREGULATOR_ON                    PWR_CR_LPDS   /* 低功耗稳压器开启，用于低功耗模式 */

/**
  * @}
  */

/** @defgroup PWR_SLEEP_mode_entry PWR 睡眠模式进入方式
  * @{
  */
#define PWR_SLEEPENTRY_WFI              ((uint8_t)0x01)  // 使用 WFI (Wait For Interrupt) 指令进入睡眠模式
#define PWR_SLEEPENTRY_WFE              ((uint8_t)0x02)  // 使用 WFE (Wait For Event) 指令进入睡眠模式

/**
  * @}
  */

/** @defgroup PWR_STOP_mode_entry PWR 停止模式进入方式
  * @{
  */
#define PWR_STOPENTRY_WFI               ((uint8_t)0x01)  // 使用 WFI (Wait For Interrupt) 指令进入停止模式
#define PWR_STOPENTRY_WFE               ((uint8_t)0x02)  // 使用 WFE (Wait For Event) 指令进入停止模式

/**
  * @}
  */

/** @defgroup PWR_Flag PWR 标志位
  * @{
  */
#define PWR_FLAG_WU                     PWR_CSR_WUF   /* 唤醒标志位 */
#define PWR_FLAG_SB                     PWR_CSR_SBF   /* 待机标志位 */
#define PWR_FLAG_PVDO                   PWR_CSR_PVDO  /* PVD输出标志位 */


/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup PWR_Exported_Macros PWR 导出宏
  * @{
  */

/** @brief  检查PWR标志位是否被置位。
  * @param  __FLAG__: 指定要检查的标志位。
  *           该参数可以是以下值之一:
  *            @arg PWR_FLAG_WU: 唤醒标志。该标志表示从WKUP引脚或RTC闹钟接收到唤醒事件。
  *                  如果在WKUP引脚电平已经为高时使能WKUP引脚(通过设置EWUP位)，
  *                  则会检测到额外的唤醒事件。
  *            @arg PWR_FLAG_SB: 待机标志。该标志表示系统从待机模式唤醒。
  *            @arg PWR_FLAG_PVDO: PVD输出。该标志仅在通过HAL_PWR_EnablePVD()函数使能PVD时有效。
  *                  PVD在待机模式下停止。因此，在待机或复位后，直到PVDE位被置位，该位才等于0。
  * @retval __FLAG__的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_PWR_GET_FLAG(__FLAG__) ((PWR->CSR & (__FLAG__)) == (__FLAG__))

/** @brief  清除PWR的挂起标志位。
  * @param  __FLAG__: 指定要清除的标志位。
  *          该参数可以是以下值之一:
  *            @arg PWR_FLAG_WU: 唤醒标志
  *            @arg PWR_FLAG_SB: 待机标志
  */
#define __HAL_PWR_CLEAR_FLAG(__FLAG__) SET_BIT(PWR->CR, ((__FLAG__) << 2))

/**
  * @brief 使能PVD外部中断线16上的中断。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_IT()      SET_BIT(EXTI->IMR, PWR_EXTI_LINE_PVD)

/**
  * @brief 禁用PVD外部中断线16上的中断。 
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_IT()     CLEAR_BIT(EXTI->IMR, PWR_EXTI_LINE_PVD)

/**
  * @brief 使能PVD外部中断线16上的事件。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_EVENT()   SET_BIT(EXTI->EMR, PWR_EXTI_LINE_PVD)

/**
  * @brief 禁用PVD外部中断线16上的事件。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_EVENT()  CLEAR_BIT(EXTI->EMR, PWR_EXTI_LINE_PVD)


/**
  * @brief  PVD EXTI线配置：设置下降沿触发。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE()  SET_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)


/**
  * @brief 禁用PVD外部中断下降沿触发。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE()  CLEAR_BIT(EXTI->FTSR, PWR_EXTI_LINE_PVD)


/**
  * @brief  PVD EXTI线配置：设置上升沿触发。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE()   SET_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)

/**
  * @brief 禁用PVD外部中断上升沿触发。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE()  CLEAR_BIT(EXTI->RTSR, PWR_EXTI_LINE_PVD)

/**
  * @brief  PVD EXTI线配置：设置上升沿和下降沿触发。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_ENABLE_RISING_FALLING_EDGE()   __HAL_PWR_PVD_EXTI_ENABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_ENABLE_FALLING_EDGE();

/**
  * @brief 禁用PVD外部中断上升沿和下降沿触发。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_DISABLE_RISING_FALLING_EDGE()  __HAL_PWR_PVD_EXTI_DISABLE_RISING_EDGE();__HAL_PWR_PVD_EXTI_DISABLE_FALLING_EDGE();



/**
  * @brief 检查指定的PVD EXTI中断标志位是否被置位。
  * @retval EXTI PVD线状态。
  */
#define __HAL_PWR_PVD_EXTI_GET_FLAG()       (EXTI->PR & (PWR_EXTI_LINE_PVD))

/**
  * @brief 清除PVD EXTI标志位。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_CLEAR_FLAG()     (EXTI->PR = (PWR_EXTI_LINE_PVD))

/**
  * @brief 在选定的EXTI线上产生软件中断。
  * @retval 无。
  */
#define __HAL_PWR_PVD_EXTI_GENERATE_SWIT()  SET_BIT(EXTI->SWIER, PWR_EXTI_LINE_PVD)
/**
  * @}
  */

/* 私有宏 -------------------------------------------------------------*/
/** @defgroup PWR_Private_Macros PWR 私有宏
  * @{
  */
/* 检查PVD电压阈值参数是否有效 */
#define IS_PWR_PVD_LEVEL(LEVEL) (((LEVEL) == PWR_PVDLEVEL_0) || ((LEVEL) == PWR_PVDLEVEL_1)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_2) || ((LEVEL) == PWR_PVDLEVEL_3)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_4) || ((LEVEL) == PWR_PVDLEVEL_5)|| \
                                 ((LEVEL) == PWR_PVDLEVEL_6) || ((LEVEL) == PWR_PVDLEVEL_7))


/* 检查PVD模式参数是否有效 */
#define IS_PWR_PVD_MODE(MODE) (((MODE) == PWR_PVD_MODE_IT_RISING)|| ((MODE) == PWR_PVD_MODE_IT_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_IT_RISING_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING) || \
                              ((MODE) == PWR_PVD_MODE_EVENT_FALLING) || ((MODE) == PWR_PVD_MODE_EVENT_RISING_FALLING) || \
                              ((MODE) == PWR_PVD_MODE_NORMAL)) 

/* 检查唤醒引脚参数是否有效 */
#define IS_PWR_WAKEUP_PIN(PIN) (((PIN) == PWR_WAKEUP_PIN1))

/* 检查稳压器状态参数是否有效 */
#define IS_PWR_REGULATOR(REGULATOR) (((REGULATOR) == PWR_MAINREGULATOR_ON) || \
                                     ((REGULATOR) == PWR_LOWPOWERREGULATOR_ON))

/* 检查睡眠模式进入方式参数是否有效 */
#define IS_PWR_SLEEP_ENTRY(ENTRY) (((ENTRY) == PWR_SLEEPENTRY_WFI) || ((ENTRY) == PWR_SLEEPENTRY_WFE))

/* 检查停止模式进入方式参数是否有效 */
#define IS_PWR_STOP_ENTRY(ENTRY) (((ENTRY) == PWR_STOPENTRY_WFI) || ((ENTRY) == PWR_STOPENTRY_WFE))

/**
  * @}
  */



/* 导出函数 --------------------------------------------------------*/

/** @addtogroup PWR_Exported_Functions PWR 导出函数
  * @{
  */
  
/** @addtogroup PWR_Exported_Functions_Group1 初始化和反初始化函数 
  * @{
  */

/* 初始化和反初始化函数 *******************************/
void HAL_PWR_DeInit(void);              // 反初始化PWR外设寄存器
void HAL_PWR_EnableBkUpAccess(void);    // 使能对备份域的访问
void HAL_PWR_DisableBkUpAccess(void);   // 禁用对备份域的访问

/**
  * @}
  */

/** @addtogroup PWR_Exported_Functions_Group2 外设控制函数 
  * @{
  */

/* 外设控制函数  ************************************************/
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);  // 配置可编程电压检测器(PVD)
/* #define HAL_PWR_ConfigPVD 12*/
void HAL_PWR_EnablePVD(void);            // 使能PVD
void HAL_PWR_DisablePVD(void);           // 禁用PVD

/* 唤醒引脚配置函数 ****************************************/
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);   // 使能唤醒引脚
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);  // 禁用唤醒引脚

/* 低功耗模式配置函数 ************************************/
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);  // 进入停止模式
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry); // 进入睡眠模式
void HAL_PWR_EnterSTANDBYMode(void);                                // 进入待机模式

void HAL_PWR_EnableSleepOnExit(void);   // 使能退出中断时进入睡眠模式
void HAL_PWR_DisableSleepOnExit(void);  // 禁用退出中断时进入睡眠模式
void HAL_PWR_EnableSEVOnPend(void);     // 使能挂起中断时发送事件
void HAL_PWR_DisableSEVOnPend(void);    // 禁用挂起中断时发送事件



void HAL_PWR_PVD_IRQHandler(void);      // PVD中断处理函数
void HAL_PWR_PVDCallback(void);         // PVD中断回调函数
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
