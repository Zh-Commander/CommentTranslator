/**
  ******************************************************************************
  * @file    stm32f1xx_hal_tim_ex.h
  * @author  MCD Application Team
  * @brief   Header file of TIM HAL Extended module.
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
#ifndef STM32F1xx_HAL_TIM_EX_H
#define STM32F1xx_HAL_TIM_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup TIMEx
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/
/** @defgroup TIMEx_Exported_Types TIM Extended Exported Types
  * @{
  */

/**
  * @brief  TIM Hall sensor Configuration Structure definition
  *         TIM 霍尔传感器配置结构体定义
  */

typedef struct
{
  uint32_t IC1Polarity;         /*!< Specifies the active edge of the input signal.
                                     This parameter can be a value of @ref TIM_Input_Capture_Polarity */
                                 /*!< 指定输入信号的有效边沿。
                                      该参数可以是 @ref TIM_Input_Capture_Polarity 的值 */

  uint32_t IC1Prescaler;        /*!< Specifies the Input Capture Prescaler.
                                     This parameter can be a value of @ref TIM_Input_Capture_Prescaler */
                                 /*!< 指定输入捕获预分频器。
                                      该参数可以是 @ref TIM_Input_Capture_Prescaler 的值 */

  uint32_t IC1Filter;           /*!< Specifies the input capture filter.
                                     This parameter can be a number between Min_Data = 0x0 and Max_Data = 0xF */
                                 /*!< 指定输入捕获滤波器。
                                      该参数可以是 Min_Data = 0x0 和 Max_Data = 0xF 之间的数字 */

  uint32_t Commutation_Delay;   /*!< Specifies the pulse value to be loaded into the Capture Compare Register.
                                     This parameter can be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF */
                                 /*!< 指定加载到捕获比较寄存器(CCR)中的脉冲值(用于设置换相延迟)。
                                      该参数可以是 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数字 */
} TIM_HallSensor_InitTypeDef;
/**
  * @}
  */
/* 导出类型结束 -----------------------------------------------------*/

/* 导出常量 --------------------------------------------------------*/
/** @defgroup TIMEx_Exported_Constants TIM Extended Exported Constants
  * @{
  */

/** @defgroup TIMEx_Remap TIM Extended Remapping
  * @{
  */
/**
  * @}
  */

/**
  * @}
  */
/* 导出常量结束 -------------------------------------------------*/

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup TIMEx_Exported_Macros TIM Extended Exported Macros
  * @{
  */

/**
  * @}
  */
/* 导出宏结束 -----------------------------------------------------*/

/* 私有宏 -------------------------------------------------------------*/
/** @defgroup TIMEx_Private_Macros TIM Extended Private Macros
  * @{
  */

/**
  * @}
  */
/* 私有宏结束 ------------------------------------------------------*/

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup TIMEx_Exported_Functions TIM Extended Exported Functions
  * @{
  */

/** @addtogroup TIMEx_Exported_Functions_Group1 Extended Timer Hall Sensor functions
  *  @brief    Timer Hall Sensor functions
  * @{
  */
/*  定时器霍尔传感器函数  **********************************************/
// 初始化霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, const TIM_HallSensor_InitTypeDef *sConfig);
// 反初始化霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim);

// 霍尔传感器 MSP 初始化 (用户重定义)
void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim);
// 霍尔传感器 MSP 反初始化 (用户重定义)
void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim);

/* Blocking mode: Polling */ // 阻塞模式：轮询
// 启动霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim);
// 停止霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim);
/* Non-Blocking mode: Interrupt */ // 非阻塞模式：中断
// 以中断方式启动霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim);
// 以中断方式停止霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim);
/* Non-Blocking mode: DMA */ // 非阻塞模式：DMA
// 以 DMA 方式启动霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
// 以 DMA 方式停止霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group2 Extended Timer Complementary Output Compare functions
  *  @brief   Timer Complementary Output Compare functions
  * @{
  */
/*  定时器互补输出比较函数  *****************************/
/* Blocking mode: Polling */ // 阻塞模式：轮询
// 启动互补输出比较
HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止互补输出比较
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

/* Non-Blocking mode: Interrupt */ // 非阻塞模式：中断
// 以中断方式启动互补输出比较
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
// 以中断方式停止互补输出比较
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

/* Non-Blocking mode: DMA */ // 非阻塞模式：DMA
// 以 DMA 方式启动互补输出比较
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                          uint16_t Length);
// 以 DMA 方式停止互补输出比较
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group3 Extended Timer Complementary PWM functions
  *  @brief    Timer Complementary PWM functions
  * @{
  */
/*  定时器互补 PWM 函数  ****************************************/
/* Blocking mode: Polling */ // 阻塞模式：轮询
// 启动互补 PWM 输出
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止互补 PWM 输出
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

/* Non-Blocking mode: Interrupt */ // 非阻塞模式：中断
// 以中断方式启动互补 PWM 输出
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
// 以中断方式停止互补 PWM 输出
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* Non-Blocking mode: DMA */ // 非阻塞模式：DMA
// 以 DMA 方式启动互补 PWM 输出
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                           uint16_t Length);
// 以 DMA 方式停止互补 PWM 输出
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group4 Extended Timer Complementary One Pulse functions
  *  @brief    Timer Complementary One Pulse functions
  * @{
  */
/*  定时器互补单脉冲函数  **********************************/
/* Blocking mode: Polling */ // 阻塞模式：轮询
// 启动互补单脉冲输出
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
// 停止互补单脉冲输出
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);

/* Non-Blocking mode: Interrupt */ // 非阻塞模式：中断
// 以中断方式启动互补单脉冲输出
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
// 以中断方式停止互补单脉冲输出
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group5 Extended Peripheral Control functions
  *  @brief    Peripheral Control functions
  * @{
  */
/* 扩展控制函数  ************************************************/
// 配置换相事件
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                              uint32_t  CommutationSource);
// 配置换相事件并使能中断
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                 uint32_t  CommutationSource);
// 配置换相事件并使能 DMA
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_DMA(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                  uint32_t  CommutationSource);
// 主模式配置同步
HAL_StatusTypeDef HAL_TIMEx_MasterConfigSynchronization(TIM_HandleTypeDef *htim,
                                                        const TIM_MasterConfigTypeDef *sMasterConfig);
// 配置刹车和死区时间
HAL_StatusTypeDef HAL_TIMEx_ConfigBreakDeadTime(TIM_HandleTypeDef *htim,
                                                const TIM_BreakDeadTimeConfigTypeDef *sBreakDeadTimeConfig);
// 配置重映射
HAL_StatusTypeDef HAL_TIMEx_RemapConfig(TIM_HandleTypeDef *htim, uint32_t Remap);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group6 Extended Callbacks functions
  * @brief    Extended Callbacks functions
  * @{
  */
/* 扩展回调函数 **********************************************************/
// 换相回调函数
void HAL_TIMEx_CommutCallback(TIM_HandleTypeDef *htim);
// 换相完成一半回调函数
void HAL_TIMEx_CommutHalfCpltCallback(TIM_HandleTypeDef *htim);
// 刹车回调函数
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group7 Extended Peripheral State functions
  * @brief    Extended Peripheral State functions
  * @{
  */
/* 扩展外设状态函数  ***************************************/
// 获取霍尔传感器状态
HAL_TIM_StateTypeDef HAL_TIMEx_HallSensor_GetState(const TIM_HandleTypeDef *htim);
// 获取互补通道状态
HAL_TIM_ChannelStateTypeDef HAL_TIMEx_GetChannelNState(const TIM_HandleTypeDef *htim,  uint32_t ChannelN);
/**
  * @}
  */

/**
  * @}
  */
/* 导出函数结束 -------------------------------------------------*/

/* 私有函数----------------------------------------------------------*/
/** @addtogroup TIMEx_Private_Functions TIM Extended Private Functions
  * @{
  */
// DMA 换相传输完成回调
void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma);
// DMA 换相传输半完成回调
void TIMEx_DMACommutationHalfCplt(DMA_HandleTypeDef *hdma);
/**
  * @}
  */
/* 私有函数结束 --------------------------------------------------*/

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif


#endif /* STM32F1xx_HAL_TIM_EX_H */
