/**
  ******************************************************************************
  * @file    stm32f1xx_hal.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -----------------------------------------------------*/
#ifndef __STM32F1xx_HAL_H
#define __STM32F1xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
// 包含HAL库的配置文件，用户通常在这里配置是否使用某些外设
#include "stm32f1xx_hal_conf.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup HAL
  * @{
  */

/* 导出常量 ----------------------------------------------------------------*/

/** @defgroup HAL_Exported_Constants HAL Exported Constants
  * @{
  */

/** @defgroup HAL_TICK_FREQ Tick Frequency
  * @{
  */
// 定义滴答定时器的频率枚举类型
// 用于设置HAL库的时间基准频率
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U, // 10Hz频率，即每秒滴答100次 (100ms中断一次)
  HAL_TICK_FREQ_100HZ        = 10U,  // 100Hz频率，即每秒滴答10次 (10ms中断一次)
  HAL_TICK_FREQ_1KHZ         = 1U,   // 1KHz频率，即每秒滴答1次 (1ms中断一次，这是默认最常用的)
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ // 默认频率，设置为1KHz
} HAL_TickFreqTypeDef;
/**
  * @}
  */
/* 导出类型 ------------------------------------------------------------*/
// 全局滴答计数变量，记录系统启动后的毫秒数（或根据频率设置的时间单位）
// __IO 表示 volatile，防止编译器优化，因为这个变量会在中断中改变
extern __IO uint32_t uwTick;
// 滴答中断优先级
extern uint32_t uwTickPrio;
// 滴答频率结构体变量
extern HAL_TickFreqTypeDef uwTickFreq;

/**
  * @}
  */
/* 导出宏 ------------------------------------------------------------*/
/** @defgroup HAL_Exported_Macros HAL Exported Macros
  * @{
  */

/** @defgroup DBGMCU_Freeze_Unfreeze Freeze Unfreeze Peripherals in Debug mode
  * @brief   Freeze/Unfreeze Peripherals in Debug mode
  * Note: On devices STM32F10xx8 and STM32F10xxB,
  *                  STM32101xC/D/E and STM32103xC/D/E,
  *                  STM32101xF/G and STM32103xF/G
  *                  STM3210xx4 and STM3210xx6
  *       Debug registers DBGMCU_IDCODE and DBGMCU_CR are accessible only in
  *       debug mode (not accessible by the user software in normal mode).
  *       Refer to errata sheet of these devices for more details.
  * @{
  */

/* APB1总线上的外设 */
/**
  * @brief  TIM2 Peripherals Debug mode
  */
// 冻结TIM2：当内核暂停调试时，TIM2也暂停计数
#define __HAL_DBGMCU_FREEZE_TIM2()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM2_STOP)
// 解冻TIM2：当内核暂停调试时，TIM2继续计数
#define __HAL_DBGMCU_UNFREEZE_TIM2()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM2_STOP)

/**
  * @brief  TIM3 Peripherals Debug mode
  */
// 冻结TIM3
#define __HAL_DBGMCU_FREEZE_TIM3()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM3_STOP)
// 解冻TIM3
#define __HAL_DBGMCU_UNFREEZE_TIM3()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM3_STOP)

#if defined (DBGMCU_CR_DBG_TIM4_STOP)
/**
  * @brief  TIM4 Peripherals Debug mode
  */
// 冻结TIM4
#define __HAL_DBGMCU_FREEZE_TIM4()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM4_STOP)
// 解冻TIM4
#define __HAL_DBGMCU_UNFREEZE_TIM4()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM4_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM5_STOP)
/**
  * @brief  TIM5 Peripherals Debug mode
  */
// 冻结TIM5
#define __HAL_DBGMCU_FREEZE_TIM5()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM5_STOP)
// 解冻TIM5
#define __HAL_DBGMCU_UNFREEZE_TIM5()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM5_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM6_STOP)
/**
  * @brief  TIM6 Peripherals Debug mode
  */
// 冻结TIM6
#define __HAL_DBGMCU_FREEZE_TIM6()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM6_STOP)
// 解冻TIM6
#define __HAL_DBGMCU_UNFREEZE_TIM6()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM6_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM7_STOP)
/**
  * @brief  TIM7 Peripherals Debug mode
  */
// 冻结TIM7
#define __HAL_DBGMCU_FREEZE_TIM7()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM7_STOP)
// 解冻TIM7
#define __HAL_DBGMCU_UNFREEZE_TIM7()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM7_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM12_STOP)
/**
  * @brief  TIM12 Peripherals Debug mode
  */
// 冻结TIM12
#define __HAL_DBGMCU_FREEZE_TIM12()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM12_STOP)
// 解冻TIM12
#define __HAL_DBGMCU_UNFREEZE_TIM12()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM12_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM13_STOP)
/**
  * @brief  TIM13 Peripherals Debug mode
  */
// 冻结TIM13
#define __HAL_DBGMCU_FREEZE_TIM13()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM13_STOP)
// 解冻TIM13
#define __HAL_DBGMCU_UNFREEZE_TIM13()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM13_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM14_STOP)
/**
  * @brief  TIM14 Peripherals Debug mode
  */
// 冻结TIM14
#define __HAL_DBGMCU_FREEZE_TIM14()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM14_STOP)
// 解冻TIM14
#define __HAL_DBGMCU_UNFREEZE_TIM14()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM14_STOP)
#endif

/**
  * @brief  WWDG Peripherals Debug mode
  */
// 冻结窗口看门狗：调试时暂停看门狗计数，防止复位
#define __HAL_DBGMCU_FREEZE_WWDG()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_WWDG_STOP)
// 解冻窗口看门狗
#define __HAL_DBGMCU_UNFREEZE_WWDG()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_WWDG_STOP)

/**
  * @brief  IWDG Peripherals Debug mode
  */
// 冻结独立看门狗：调试时暂停看门狗计数，防止复位
#define __HAL_DBGMCU_FREEZE_IWDG()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_IWDG_STOP)
// 解冻独立看门狗
#define __HAL_DBGMCU_UNFREEZE_IWDG()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_IWDG_STOP)

/**
  * @brief  I2C1 Peripherals Debug mode
  */
// 冻结I2C1超时计数：调试时暂停SMBUS超时检测
#define __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT()    SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT)
// 解冻I2C1超时计数
#define __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT()  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT)

#if defined (DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT)
/**
  * @brief  I2C2 Peripherals Debug mode
  */
// 冻结I2C2超时计数
#define __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT()    SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT)
// 解冻I2C2超时计数
#define __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT()  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT)
#endif

#if defined (DBGMCU_CR_DBG_CAN1_STOP)
/**
  * @brief  CAN1 Peripherals Debug mode
  */
// 冻结CAN1：调试时暂停CAN接收
#define __HAL_DBGMCU_FREEZE_CAN1()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN1_STOP)
// 解冻CAN1
#define __HAL_DBGMCU_UNFREEZE_CAN1()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN1_STOP)
#endif

#if defined (DBGMCU_CR_DBG_CAN2_STOP)
/**
  * @brief  CAN2 Peripherals Debug mode
  */
// 冻结CAN2
#define __HAL_DBGMCU_FREEZE_CAN2()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN2_STOP)
// 解冻CAN2
#define __HAL_DBGMCU_UNFREEZE_CAN2()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN2_STOP)
#endif

/* APB2总线上的外设 */
#if defined (DBGMCU_CR_DBG_TIM1_STOP)
/**
  * @brief  TIM1 Peripherals Debug mode
  */
// 冻结TIM1
#define __HAL_DBGMCU_FREEZE_TIM1()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM1_STOP)
// 解冻TIM1
#define __HAL_DBGMCU_UNFREEZE_TIM1()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM1_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM8_STOP)
/**
  * @brief  TIM8 Peripherals Debug mode
  */
// 冻结TIM8
#define __HAL_DBGMCU_FREEZE_TIM8()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM8_STOP)
// 解冻TIM8
#define __HAL_DBGMCU_UNFREEZE_TIM8()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM8_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM9_STOP)
/**
  * @brief  TIM9 Peripherals Debug mode
  */
// 冻结TIM9
#define __HAL_DBGMCU_FREEZE_TIM9()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM9_STOP)
// 解冻TIM9
#define __HAL_DBGMCU_UNFREEZE_TIM9()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM9_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM10_STOP)
/**
  * @brief  TIM10 Peripherals Debug mode
  */
// 冻结TIM10
#define __HAL_DBGMCU_FREEZE_TIM10()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM10_STOP)
// 解冻TIM10
#define __HAL_DBGMCU_UNFREEZE_TIM10()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM10_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM11_STOP)
/**
  * @brief  TIM11 Peripherals Debug mode
  */
// 冻结TIM11
#define __HAL_DBGMCU_FREEZE_TIM11()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM11_STOP)
// 解冻TIM11
#define __HAL_DBGMCU_UNFREEZE_TIM11()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM11_STOP)
#endif


#if defined (DBGMCU_CR_DBG_TIM15_STOP)
/**
  * @brief  TIM15 Peripherals Debug mode
  */
// 冻结TIM15
#define __HAL_DBGMCU_FREEZE_TIM15()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM15_STOP)
// 解冻TIM15
#define __HAL_DBGMCU_UNFREEZE_TIM15()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM15_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM16_STOP)
/**
  * @brief  TIM16 Peripherals Debug mode
  */
// 冻结TIM16
#define __HAL_DBGMCU_FREEZE_TIM16()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM16_STOP)
// 解冻TIM16
#define __HAL_DBGMCU_UNFREEZE_TIM16()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM16_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM17_STOP)
/**
  * @brief  TIM17 Peripherals Debug mode
  */
// 冻结TIM17
#define __HAL_DBGMCU_FREEZE_TIM17()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM17_STOP)
// 解冻TIM17
#define __HAL_DBGMCU_UNFREEZE_TIM17()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM17_STOP)
#endif

/**
  * @}
  */

/** @defgroup HAL_Private_Macros HAL Private Macros
  * @{
  */
// 判断设置的滴答频率是否合法
#define IS_TICKFREQ(FREQ) (((FREQ) == HAL_TICK_FREQ_10HZ)  || \
                           ((FREQ) == HAL_TICK_FREQ_100HZ) || \
                           ((FREQ) == HAL_TICK_FREQ_1KHZ))
/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup HAL_Exported_Functions
  * @{
  */
/** @addtogroup HAL_Exported_Functions_Group1
  * @{
  */
/* 初始化和反初始化函数  ******************************/
// HAL库初始化函数（系统刚启动时调用，初始化Flash接口、滴答定时器等）
HAL_StatusTypeDef HAL_Init(void);
// HAL库反初始化函数（复位外设，关闭时钟）
HAL_StatusTypeDef HAL_DeInit(void);
// MSP初始化函数（MCU Specific Package，由用户实现，用于配置底层硬件如GPIO、时钟）
void HAL_MspInit(void);
// MSP反初始化函数（由用户实现，用于复位底层硬件）
void HAL_MspDeInit(void);
// 初始化滴答定时器（通常由HAL_Init调用，也可用于重新配置优先级）
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
/**
  * @}
  */

/** @addtogroup HAL_Exported_Functions_Group2
  * @{
  */
/* 外设控制函数  ************************************************/
// 滴答计数加1（通常在SysTick中断服务函数中调用）
void HAL_IncTick(void);
// 阻塞延时函数（单位由滴答频率决定，默认为毫秒）
void HAL_Delay(uint32_t Delay);
// 获取当前滴答计数值
uint32_t HAL_GetTick(void);
// 获取滴答定时器优先级
uint32_t HAL_GetTickPrio(void);
// 设置滴答定时器频率
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
// 获取滴答定时器频率
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
// 暂停滴答定时器计数（用于低功耗模式等）
void HAL_SuspendTick(void);
// 恢复滴答定时器计数
void HAL_ResumeTick(void);
// 获取HAL库版本号
uint32_t HAL_GetHalVersion(void);
// 获取芯片修订版本号
uint32_t HAL_GetREVID(void);
// 获取芯片设备ID
uint32_t HAL_GetDEVID(void);
// 获取唯一设备ID（Word 0）
uint32_t HAL_GetUIDw0(void);
// 获取唯一设备ID（Word 1）
uint32_t HAL_GetUIDw1(void);
// 获取唯一设备ID（Word 2）
uint32_t HAL_GetUIDw2(void);
// 使能睡眠模式下的调试功能
void HAL_DBGMCU_EnableDBGSleepMode(void);
// 禁用睡眠模式下的调试功能
void HAL_DBGMCU_DisableDBGSleepMode(void);
// 使能停止模式下的调试功能
void HAL_DBGMCU_EnableDBGStopMode(void);
// 禁用停止模式下的调试功能
void HAL_DBGMCU_DisableDBGStopMode(void);
// 使能待机模式下的调试功能
void HAL_DBGMCU_EnableDBGStandbyMode(void);
// 禁用待机模式下的调试功能
void HAL_DBGMCU_DisableDBGStandbyMode(void);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/** @defgroup HAL_Private_Variables HAL Private Variables
  * @{
  */
/**
  * @}
  */
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup HAL_Private_Constants HAL Private Constants
  * @{
  */
/**
  * @}
  */
/* 私有宏 ------------------------------------------------------------*/
/* 私有函数 ---------------------------------------------------------*/
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_HAL_H */

