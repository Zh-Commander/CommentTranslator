/**
  ******************************************************************************
  * @file    stm32f1xx_hal.h
  * @author  MCD Application Team
  * @brief   本文件包含HAL模块驱动的所有函数原型。
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

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_H
#define __STM32F1xx_HAL_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
// 包含HAL库的配置文件，用户通常在此文件中使能或禁用特定的外设模块
#include "stm32f1xx_hal_conf.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup HAL
  * @{
  */

/* 导出常量 --------------------------------------------------------*/

/** @defgroup HAL_Exported_Constants HAL导出常量
  * @{
  */

/** @defgroup HAL_TICK_FREQ 滴答定时器频率定义
  * @{
  */
// 定义滴答定时器中断频率的枚举类型
// 用于配置SysTick定时器每秒中断多少次
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U, // 10Hz频率，即每秒中断10次，中断周期100ms
  HAL_TICK_FREQ_100HZ        = 10U,  // 100Hz频率，即每秒中断100次，中断周期10ms
  HAL_TICK_FREQ_1KHZ         = 1U,   // 1KHz频率，即每秒中断1000次，中断周期1ms (默认配置)
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ // 默认频率设置
} HAL_TickFreqTypeDef;
/**
  * @}
  */
/* 导出类型 ------------------------------------------------------------*/
// 全局滴答计数变量，记录系统启动后的毫秒数
extern __IO uint32_t uwTick;
// 滴答定时器中断优先级
extern uint32_t uwTickPrio;
// 滴答定时器频率变量
extern HAL_TickFreqTypeDef uwTickFreq;

/**
  * @}
  */
/* 导出宏 ------------------------------------------------------------*/
/** @defgroup HAL_Exported_Macros HAL导出宏
  * @{
  */

/** @defgroup DBGMCU_Freeze_Unfreeze 调试模式下外设冻结/解冻控制
  * @brief   在调试模式下冻结/解冻外设
  * 注意: 在STM32F10xx8、STM32F10xxB、STM32F101xC/D/E等某些设备上，
  *       调试寄存器DBGMCU_IDCODE和DBGMCU_CR仅在调试模式下可访问。
  *       更多细节请参考相关设备的勘误手册。
  * @{
  */

/* APB1总线上的外设 */
/**
  * @brief  TIM2外设调试模式配置
  */
// 冻结TIM2：当内核暂停调试时，TIM2也暂停计数
#define __HAL_DBGMCU_FREEZE_TIM2()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM2_STOP)
// 解冻TIM2：当内核暂停调试时，TIM2继续计数
#define __HAL_DBGMCU_UNFREEZE_TIM2()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM2_STOP)

/**
  * @brief  TIM3外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM3()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM3_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM3()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM3_STOP)

#if defined (DBGMCU_CR_DBG_TIM4_STOP)
/**
  * @brief  TIM4外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM4()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM4_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM4()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM4_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM5_STOP)
/**
  * @brief  TIM5外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM5()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM5_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM5()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM5_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM6_STOP)
/**
  * @brief  TIM6外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM6()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM6_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM6()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM6_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM7_STOP)
/**
  * @brief  TIM7外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM7()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM7_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM7()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM7_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM12_STOP)
/**
  * @brief  TIM12外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM12()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM12_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM12()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM12_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM13_STOP)
/**
  * @brief  TIM13外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM13()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM13_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM13()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM13_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM14_STOP)
/**
  * @brief  TIM14外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM14()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM14_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM14()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM14_STOP)
#endif

/**
  * @brief  WWDG(窗口看门狗)外设调试模式配置
  */
// 冻结窗口看门狗：调试时停止看门狗计数，防止调试时复位
#define __HAL_DBGMCU_FREEZE_WWDG()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_WWDG_STOP)
#define __HAL_DBGMCU_UNFREEZE_WWDG()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_WWDG_STOP)

/**
  * @brief  IWDG(独立看门狗)外设调试模式配置
  */
// 冻结独立看门狗：调试时停止看门狗计数
#define __HAL_DBGMCU_FREEZE_IWDG()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_IWDG_STOP)
#define __HAL_DBGMCU_UNFREEZE_IWDG()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_IWDG_STOP)

/**
  * @brief  I2C1外设调试模式配置
  */
// 冻结I2C1超时计数：调试时停止SMBus超时计数
#define __HAL_DBGMCU_FREEZE_I2C1_TIMEOUT()    SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_UNFREEZE_I2C1_TIMEOUT()  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT)

#if defined (DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT)
/**
  * @brief  I2C2外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_I2C2_TIMEOUT()    SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT)
#define __HAL_DBGMCU_UNFREEZE_I2C2_TIMEOUT()  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT)
#endif

#if defined (DBGMCU_CR_DBG_CAN1_STOP)
/**
  * @brief  CAN1外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_CAN1()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN1_STOP)
#define __HAL_DBGMCU_UNFREEZE_CAN1()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN1_STOP)
#endif

#if defined (DBGMCU_CR_DBG_CAN2_STOP)
/**
  * @brief  CAN2外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_CAN2()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN2_STOP)
#define __HAL_DBGMCU_UNFREEZE_CAN2()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_CAN2_STOP)
#endif

/* APB2总线上的外设 */
#if defined (DBGMCU_CR_DBG_TIM1_STOP)
/**
  * @brief  TIM1外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM1()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM1_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM1()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM1_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM8_STOP)
/**
  * @brief  TIM8外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM8()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM8_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM8()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM8_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM9_STOP)
/**
  * @brief  TIM9外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM9()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM9_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM9()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM9_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM10_STOP)
/**
  * @brief  TIM10外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM10()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM10_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM10()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM10_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM11_STOP)
/**
  * @brief  TIM11外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM11()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM11_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM11()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM11_STOP)
#endif


#if defined (DBGMCU_CR_DBG_TIM15_STOP)
/**
  * @brief  TIM15外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM15()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM15_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM15()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM15_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM16_STOP)
/**
  * @brief  TIM16外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM16()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM16_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM16()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM16_STOP)
#endif

#if defined (DBGMCU_CR_DBG_TIM17_STOP)
/**
  * @brief  TIM17外设调试模式配置
  */
#define __HAL_DBGMCU_FREEZE_TIM17()            SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM17_STOP)
#define __HAL_DBGMCU_UNFREEZE_TIM17()          CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_TIM17_STOP)
#endif

/**
  * @}
  */

/** @defgroup HAL_Private_Macros HAL私有宏
  * @{
  */
// 检查输入的滴答频率参数是否合法
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
// HAL库初始化函数：初始化Flash预取缓冲区，配置SysTick等
HAL_StatusTypeDef HAL_Init(void);
// HAL库反初始化函数：禁用中断，清除挂起标志等
HAL_StatusTypeDef HAL_DeInit(void);
// MSP初始化函数(MCU Specific Package)：用于配置底层硬件引脚时钟等，由用户在文件中重写
void HAL_MspInit(void);
// MSP反初始化函数：用于复位底层硬件，由用户在文件中重写
void HAL_MspDeInit(void);
// 初始化滴答定时器：配置SysTick中断优先级
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);
/**
  * @}
  */

/** @addtogroup HAL_Exported_Functions_Group2
  * @{
  */
/* 外设控制函数  ************************************************/
// 滴答计数增加函数：需在SysTick中断服务函数中调用
void HAL_IncTick(void);
// 阻塞延时函数：基于滴答定时器实现毫秒级延时
void HAL_Delay(uint32_t Delay);
// 获取当前滴答计数值：返回系统运行时间
uint32_t HAL_GetTick(void);
// 获取滴答定时器优先级
uint32_t HAL_GetTickPrio(void);
// 设置滴答定时器频率
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
// 获取滴答定时器频率
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
// 暂停滴答定时器：停止SysTick中断
void HAL_SuspendTick(void);
// 恢复滴答定时器：恢复SysTick中断
void HAL_ResumeTick(void);
// 获取HAL库版本号
uint32_t HAL_GetHalVersion(void);
// 获取设备修订版本号
uint32_t HAL_GetREVID(void);
// 获取设备ID号
uint32_t HAL_GetDEVID(void);
// 获取唯一设备ID(UID)的第一个字
uint32_t HAL_GetUIDw0(void);
// 获取唯一设备ID(UID)的第二个字
uint32_t HAL_GetUIDw1(void);
// 获取唯一设备ID(UID)的第三个字
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
/** @defgroup HAL_Private_Variables HAL私有变量
  * @{
  */
/**
  * @}
  */
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup HAL_Private_Constants HAL私有常量
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

