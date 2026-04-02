/**
  ******************************************************************************
  * @file    stm32f1xx_hal_tim_ex.h
  * @author  MCD Application Team
  * @brief   TIM HAL 扩展模块的头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的 LICENSE 文件中可以找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义以防止递归包含 -------------------------------------*/
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
/** @defgroup TIMEx_Exported_Types TIM 扩展导出类型
  * @{
  */

/**
  * @brief  TIM 霍尔传感器配置结构体定义
  *         用于配置定时器工作在霍尔传感器接口模式下的参数。
  */

typedef struct
{
  uint32_t IC1Polarity;         /*!< 指定输入信号的有效边沿。
                                     该参数可以是 @ref TIM_Input_Capture_Polarity 中的一个值 */

  uint32_t IC1Prescaler;        /*!< 指定输入捕获预分频器。
                                     该参数可以是 @ref TIM_Input_Capture_Prescaler 中的一个值 */

  uint32_t IC1Filter;           /*!< 指定输入捕获滤波器。
                                     该参数可以是一个介于 Min_Data = 0x0 和 Max_Data = 0xF 之间的数字 */

  uint32_t Commutation_Delay;   /*!< 指定要加载到捕获比较寄存器中的脉冲值（延迟时间）。
                                     该参数可以是一个介于 Min_Data = 0x0000 和 Max_Data = 0xFFFF 之间的数字 */
} TIM_HallSensor_InitTypeDef;
/**
  * @}
  */
/* 导出类型结束 -----------------------------------------------------*/

/* 导出常量 --------------------------------------------------------*/
/** @defgroup TIMEx_Exported_Constants TIM 扩展导出常量
  * @{
  */

/** @defgroup TIMEx_Remap TIM 扩展重映射
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
/** @defgroup TIMEx_Exported_Macros TIM 扩展导出宏
  * @{
  */

/**
  * @}
  */
/* 导出宏结束 -----------------------------------------------------*/

/* 私有宏 -------------------------------------------------------------*/
/** @defgroup TIMEx_Private_Macros TIM 扩展私有宏
  * @{
  */

/**
  * @}
  */
/* 私有宏结束 ------------------------------------------------------*/

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup TIMEx_Exported_Functions TIM 扩展导出函数
  * @{
  */

/** @addtogroup TIMEx_Exported_Functions_Group1 扩展定时器霍尔传感器函数
  *  @brief    定时器霍尔传感器函数
  * @{
  */
/*  定时器霍尔传感器函数  **********************************************/
// 初始化霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Init(TIM_HandleTypeDef *htim, const TIM_HallSensor_InitTypeDef *sConfig);
// 反初始化霍尔传感器接口
HAL_StatusTypeDef HAL_TIMEx_HallSensor_DeInit(TIM_HandleTypeDef *htim);

// 霍尔传感器 MSP 初始化（用户代码层，用于配置GPIO、时钟、中断等）
void HAL_TIMEx_HallSensor_MspInit(TIM_HandleTypeDef *htim);
// 霍尔传感器 MSP 反初始化
void HAL_TIMEx_HallSensor_MspDeInit(TIM_HandleTypeDef *htim);

/* 阻塞模式：轮询 */
// 启动霍尔传感器接口（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start(TIM_HandleTypeDef *htim);
// 停止霍尔传感器接口（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop(TIM_HandleTypeDef *htim);
/* 非阻塞模式：中断 */
// 启动霍尔传感器接口（中断模式）
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_IT(TIM_HandleTypeDef *htim);
// 停止霍尔传感器接口（中断模式）
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_IT(TIM_HandleTypeDef *htim);
/* 非阻塞模式：DMA */
// 启动霍尔传感器接口（DMA模式）
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Start_DMA(TIM_HandleTypeDef *htim, uint32_t *pData, uint16_t Length);
// 停止霍尔传感器接口（DMA模式）
HAL_StatusTypeDef HAL_TIMEx_HallSensor_Stop_DMA(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group2 扩展定时器互补输出比较函数
  *  @brief   定时器互补输出比较函数
  * @{
  */
/*  定时器互补输出比较函数  *****************************/
/* 阻塞模式：轮询 */
// 启动互补输出比较（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_OCN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止互补输出比较（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

/* 非阻塞模式：中断 */
// 启动互补输出比较（中断模式）
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止互补输出比较（中断模式）
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);

/* 非阻塞模式：DMA */
// 启动互补输出比较（DMA模式）
HAL_StatusTypeDef HAL_TIMEx_OCN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                          uint16_t Length);
// 停止互补输出比较（DMA模式）
HAL_StatusTypeDef HAL_TIMEx_OCN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group3 扩展定时器互补 PWM 函数
  *  @brief    定时器互补 PWM 函数
  * @{
  */
/*  定时器互补 PWM 函数  ****************************************/
/* 阻塞模式：轮询 */
// 启动互补 PWM 输出（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止互补 PWM 输出（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop(TIM_HandleTypeDef *htim, uint32_t Channel);

/* 非阻塞模式：中断 */
// 启动互补 PWM 输出（中断模式）
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
// 停止互补 PWM 输出（中断模式）
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t Channel);
/* 非阻塞模式：DMA */
// 启动互补 PWM 输出（DMA模式）
HAL_StatusTypeDef HAL_TIMEx_PWMN_Start_DMA(TIM_HandleTypeDef *htim, uint32_t Channel, const uint32_t *pData,
                                           uint16_t Length);
// 停止互补 PWM 输出（DMA模式）
HAL_StatusTypeDef HAL_TIMEx_PWMN_Stop_DMA(TIM_HandleTypeDef *htim, uint32_t Channel);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group4 扩展定时器互补单脉冲函数
  *  @brief    定时器互补单脉冲函数
  * @{
  */
/*  定时器互补单脉冲函数  **********************************/
/* 阻塞模式：轮询 */
// 启动互补单脉冲输出（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
// 停止互补单脉冲输出（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop(TIM_HandleTypeDef *htim, uint32_t OutputChannel);

/* 非阻塞模式：中断 */
// 启动互补单脉冲输出（中断模式）
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Start_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
// 停止互补单脉冲输出（中断模式）
HAL_StatusTypeDef HAL_TIMEx_OnePulseN_Stop_IT(TIM_HandleTypeDef *htim, uint32_t OutputChannel);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group5 扩展外设控制函数
  *  @brief    外设控制函数
  * @{
  */
/* 扩展控制函数  ************************************************/
// 配置换相事件（轮询模式）
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                              uint32_t  CommutationSource);
// 配置换相事件（中断模式）
HAL_StatusTypeDef HAL_TIMEx_ConfigCommutEvent_IT(TIM_HandleTypeDef *htim, uint32_t  InputTrigger,
                                                 uint32_t  CommutationSource);
// 配置换相事件（DMA模式）
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

/** @addtogroup TIMEx_Exported_Functions_Group6 扩展回调函数
  * @brief    扩展回调函数
  * @{
  */
/* 扩展回调 **********************************************************/
// 换相完成回调函数
void HAL_TIMEx_CommutCallback(TIM_HandleTypeDef *htim);
// 换相完成半传输回调函数（DMA模式）
void HAL_TIMEx_CommutHalfCpltCallback(TIM_HandleTypeDef *htim);
// 刹车信号检测回调函数
void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim);
/**
  * @}
  */

/** @addtogroup TIMEx_Exported_Functions_Group7 扩展外设状态函数
  * @brief    扩展外设状态函数
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
/** @addtogroup TIMEx_Private_Functions TIM 扩展私有函数
  * @{
  */
// DMA 换相完成回调函数
void TIMEx_DMACommutationCplt(DMA_HandleTypeDef *hdma);
// DMA 换相半完成回调函数
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
