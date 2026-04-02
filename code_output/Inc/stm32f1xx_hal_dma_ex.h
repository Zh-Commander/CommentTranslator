/**
  ******************************************************************************
  * @file    stm32f1xx_hal_dma_ex.h
  * @author  MCD Application Team
  * @brief   DMA HAL扩展模块的头文件。
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_DMA_EX_H
#define __STM32F1xx_HAL_DMA_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup DMAEx DMAEx
  * @brief DMA扩展模块
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/
/* 导出常量 --------------------------------------------------------*/
/* 导出宏 ------------------------------------------------------------*/
/** @defgroup DMAEx_Exported_Macros DMA扩展导出宏
  * @{
  */
/* 中断与标志管理 */
/* 针对高密度(High Density)和超大密度(XL Density)产品的配置 */
#if defined (STM32F100xE) || defined (STM32F101xE) || defined (STM32F101xG) || defined (STM32F103xE) || \
    defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/** @defgroup DMAEx_High_density_XL_density_Product_devices DMAEx高密度和超大密度产品设备
  * @brief 此部分宏定义适用于STM32F1系列的高密度及超大密度型号，这些型号通常拥有DMA2控制器。
  * @{
  */

/**
  * @brief  返回当前DMA通道的传输完成标志。
  * @param  __HANDLE__: DMA句柄指针，包含DMA通道实例信息。
  * @retval 指定的传输完成标志索引。
  * @note  该宏通过判断句柄中的Instance实例，返回对应的传输完成标志位(如DMA_FLAG_TC1)。
  *         支持DMA1的所有通道(1-7)和DMA2的所有通道(1-5)。
  */
#define __HAL_DMA_GET_TC_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel7))? DMA_FLAG_TC7 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_TC1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_TC2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_TC3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_TC4 :\
   DMA_FLAG_TC5)

/**
  * @brief  返回当前DMA通道的半传输完成标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的半传输完成标志索引。
  * @note  半传输标志在传输完成一半数据时置位，常用于双缓冲或流水线处理。
  */
#define __HAL_DMA_GET_HT_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel7))? DMA_FLAG_HT7 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_HT1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_HT2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_HT3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_HT4 :\
   DMA_FLAG_HT5)

/**
  * @brief  返回当前DMA通道的传输错误标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的传输错误标志索引。
  * @note  当DMA传输过程中发生错误（如地址越界）时，此标志会被置位。
  */
#define __HAL_DMA_GET_TE_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TE1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TE2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TE3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TE4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TE5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TE6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel7))? DMA_FLAG_TE7 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_TE1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_TE2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_TE3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_TE4 :\
   DMA_FLAG_TE5)

/**
  * @brief  返回当前DMA通道的全局中断标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的全局中断标志索引。
  * @note  全局中断标志在任何DMA中断产生时都会置位，用于快速判断是否有中断发生。
  */
#define __HAL_DMA_GET_GI_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_GL1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_GL2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_GL3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_GL4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_GL5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_GL6 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel7))? DMA_FLAG_GL7 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel1))? DMA_FLAG_GL1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel2))? DMA_FLAG_GL2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel3))? DMA_FLAG_GL3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA2_Channel4))? DMA_FLAG_GL4 :\
   DMA_FLAG_GL5)
   
/**
  * @brief  获取DMA通道的挂起标志状态。
  * @param  __HANDLE__: DMA句柄指针
  * @param  __FLAG__: 获取指定的标志。
  *         该参数可以是以下值的任意组合:
  *           @arg DMA_FLAG_TCx:  传输完成标志
  *           @arg DMA_FLAG_HTx:  半传输完成标志
  *           @arg DMA_FLAG_TEx:  传输错误标志
  *         其中 x 可以是 1_7 或 1_5 (取决于使用的是DMA1还是DMA2) 来选择DMA通道标志。
  * @retval 标志的状态 (SET 或 RESET)。
  * @note  该宏根据句柄判断是DMA1还是DMA2，并读取对应的ISR寄存器。
  */
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)\
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Channel7)? (DMA2->ISR & (__FLAG__)) :\
  (DMA1->ISR & (__FLAG__)))

/**
  * @brief  清除DMA通道的挂起标志。
  * @param  __HANDLE__: DMA句柄指针
  * @param  __FLAG__: 指定要清除的标志。
  *         该参数可以是以下值的任意组合:
  *           @arg DMA_FLAG_TCx:  传输完成标志
  *           @arg DMA_FLAG_HTx:  半传输完成标志
  *           @arg DMA_FLAG_TEx:  传输错误标志
  *         其中 x 可以是 1_7 或 1_5 (取决于使用的是DMA1还是DMA2) 来选择DMA通道标志。
  * @retval 无
  * @note  该宏通过向IFCR寄存器写1来清除对应的标志位。
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) \
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Channel7)? (DMA2->IFCR = (__FLAG__)) :\
  (DMA1->IFCR = (__FLAG__)))

/**
  * @}
  */

#else
/** @defgroup DMA_Low_density_Medium_density_Product_devices DMA低密度和中等密度产品设备
  * @brief 此部分宏定义适用于STM32F1系列的低密度及中等密度型号，这些型号只有DMA1控制器。
  * @{
  */

/**
  * @brief  返回当前DMA通道的传输完成标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的传输完成标志索引。
  * @note  仅包含DMA1的通道1至通道7。
  */
#define __HAL_DMA_GET_TC_FLAG_INDEX(__HANDLE__) \
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TC1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TC2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TC3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TC4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TC5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TC6 :\
   DMA_FLAG_TC7)

/**
  * @brief  返回当前DMA通道的半传输完成标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的半传输完成标志索引。
  */
#define __HAL_DMA_GET_HT_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_HT1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_HT2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_HT3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_HT4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_HT5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_HT6 :\
   DMA_FLAG_HT7)

/**
  * @brief  返回当前DMA通道的传输错误标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的传输错误标志索引。
  */
#define __HAL_DMA_GET_TE_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_TE1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_TE2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_TE3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_TE4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_TE5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_TE6 :\
   DMA_FLAG_TE7)

/**
  * @brief  返回当前DMA通道的全局中断标志。
  * @param  __HANDLE__: DMA句柄指针
  * @retval 指定的全局中断标志索引。
  */
#define __HAL_DMA_GET_GI_FLAG_INDEX(__HANDLE__)\
(((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel1))? DMA_FLAG_GL1 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel2))? DMA_FLAG_GL2 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel3))? DMA_FLAG_GL3 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel4))? DMA_FLAG_GL4 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel5))? DMA_FLAG_GL5 :\
 ((uint32_t)((__HANDLE__)->Instance) == ((uint32_t)DMA1_Channel6))? DMA_FLAG_GL6 :\
   DMA_FLAG_GL7)

/**
  * @brief  获取DMA通道的挂起标志状态。
  * @param  __HANDLE__: DMA句柄指针
  * @param  __FLAG__: 获取指定的标志。
  *         该参数可以是以下值的任意组合:
  *           @arg DMA_FLAG_TCx:  传输完成标志
  *           @arg DMA_FLAG_HTx:  半传输完成标志
  *           @arg DMA_FLAG_TEx:  传输错误标志
  *           @arg DMA_FLAG_GLx:  全局中断标志
  *         其中 x 可以是 1_7 来选择DMA通道标志。
  * @retval 标志的状态 (SET 或 RESET)。
  * @note  低/中密度产品仅包含DMA1，因此直接读取DMA1->ISR。
  */

#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))

/**
  * @brief  清除DMA通道的挂起标志。
  * @param  __HANDLE__: DMA句柄指针
  * @param  __FLAG__: 指定要清除的标志。
  *         该参数可以是以下值的任意组合:
  *           @arg DMA_FLAG_TCx:  传输完成标志
  *           @arg DMA_FLAG_HTx:  半传输完成标志
  *           @arg DMA_FLAG_TEx:  传输错误标志
  *           @arg DMA_FLAG_GLx:  全局中断标志
  *         其中 x 可以是 1_7 来选择DMA通道标志。
  * @retval 无
  * @note  低/中密度产品仅包含DMA1，因此直接写DMA1->IFCR。
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) (DMA1->IFCR = (__FLAG__))

/**
  * @}
  */

#endif
  
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
#endif /* STM32F100xE || STM32F101xE || STM32F101xG || STM32F103xE || */
       /* STM32F103xG || STM32F105xC || STM32F107xC */

#endif /* __STM32F1xx_HAL_DMA_H */
