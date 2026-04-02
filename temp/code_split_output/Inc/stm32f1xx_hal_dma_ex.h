/**
  ******************************************************************************
  * @file    stm32f1xx_hal_dma_ex.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL extension module.
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

/* 定义防止递归包含 -----------------------------------------------------*/
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
/** @defgroup DMAEx_Exported_Macros DMA Extended Exported Macros
  * @{
  */
/* 中断与标志管理 */
/* 这里的条件编译用于区分不同容量的STM32F1产品，高密度和超大容量产品通常拥有DMA2 */
#if defined (STM32F100xE) || defined (STM32F101xE) || defined (STM32F101xG) || defined (STM32F103xE) || \
    defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)
/** @defgroup DMAEx_High_density_XL_density_Product_devices DMAEx High density and XL density product devices
  * @brief DMA扩展 高密度和超大容量产品设备
  * @{
  */

/**
  * @brief  Returns the current DMA Channel transfer complete flag.
  *         返回当前DMA通道的传输完成标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄，包含DMA通道实例指针
  * @retval The specified transfer complete flag index.
  *         指定的传输完成标志索引。
  *         
  * 逻辑说明：该宏通过判断句柄中的Instance指针地址，确定当前使用的是哪个DMA通道，
  * 并返回对应的传输完成标志位(如 DMA_FLAG_TC1)。
  * 支持DMA1的通道1-7和DMA2的通道1-5。
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
  * @brief  Returns the current DMA Channel half transfer complete flag.
  *         返回当前DMA通道的半传输完成标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified half transfer complete flag index.
  *         指定的半传输完成标志索引。
  *         
  * 说明：当DMA传输完成一半数据时，硬件会置位此标志，常用于双缓冲或流水线处理。
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
  * @brief  Returns the current DMA Channel transfer error flag.
  *         返回当前DMA通道的传输错误标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified transfer error flag index.
  *         指定的传输错误标志索引。
  *         
  * 说明：当DMA传输过程中发生错误（如地址越界）时，硬件会置位此标志。
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
  * @brief  Return the current DMA Channel Global interrupt flag.
  *         返回当前DMA通道的全局中断标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified transfer error flag index.
  *         指定的全局中断标志索引。
  *         
  * 说明：这是一个全局标志，用于指示该通道是否发生了任何中断事件。
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
  * @brief  Get the DMA Channel pending flags.
  *         获取DMA通道的挂起标志位。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @param  __FLAG__: Get the specified flag.
  *         获取指定的标志位。
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCx:  Transfer complete flag (传输完成标志)
  *            @arg DMA_FLAG_HTx:  Half transfer complete flag (半传输完成标志)
  *            @arg DMA_FLAG_TEx:  Transfer error flag (传输错误标志)
  *         Where x can be 1_7 or 1_5 (depending on DMA1 or DMA2) to select the DMA Channel flag.   
  *         其中x可以是1_7或1_5（取决于DMA1或DMA2），用于选择DMA通道标志。
  * @retval The state of FLAG (SET or RESET).
  *         标志的状态（SET或RESET）。
  *
  * 实现逻辑：通过判断句柄实例地址是否大于DMA1_Channel7的地址，
  * 来区分是读取DMA2->ISR还是DMA1->ISR寄存器。
  */
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)\
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Channel7)? (DMA2->ISR & (__FLAG__)) :\
  (DMA1->ISR & (__FLAG__)))

/**
  * @brief  Clears the DMA Channel pending flags.
  *         清除DMA通道的挂起标志位。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @param  __FLAG__: specifies the flag to clear.
  *         指定要清除的标志位。
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCx:  Transfer complete flag (传输完成标志)
  *            @arg DMA_FLAG_HTx:  Half transfer complete flag (半传输完成标志)
  *            @arg DMA_FLAG_TEx:  Transfer error flag (传输错误标志)
  *         Where x can be 1_7 or 1_5 (depending on DMA1 or DMA2) to select the DMA Channel flag.   
  *         其中x可以是1_7或1_5（取决于DMA1或DMA2），用于选择DMA通道标志。
  * @retval None
  *         无返回值
  *
  * 实现逻辑：通过向DMA中断标志清除寄存器(IFCR)写入对应的标志位来清除标志。
  */
#define __HAL_DMA_CLEAR_FLAG(__HANDLE__, __FLAG__) \
(((uint32_t)((__HANDLE__)->Instance) > (uint32_t)DMA1_Channel7)? (DMA2->IFCR = (__FLAG__)) :\
  (DMA1->IFCR = (__FLAG__)))

/**
  * @}
  */

#else
/** @defgroup DMA_Low_density_Medium_density_Product_devices DMA Low density and Medium density product devices
  * @brief DMA 低密度和中等密度产品设备
  * @{
  */

/**
  * @brief  Returns the current DMA Channel transfer complete flag.
  *         返回当前DMA通道的传输完成标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified transfer complete flag index.
  *         指定的传输完成标志索引。
  *
  * 说明：低密度/中密度设备通常只有DMA1（7个通道），没有DMA2。
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
  * @brief  Return the current DMA Channel half transfer complete flag.
  *         返回当前DMA通道的半传输完成标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified half transfer complete flag index.
  *         指定的半传输完成标志索引。
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
  * @brief  Return the current DMA Channel transfer error flag.
  *         返回当前DMA通道的传输错误标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified transfer error flag index.
  *         指定的传输错误标志索引。
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
  * @brief  Return the current DMA Channel Global interrupt flag.
  *         返回当前DMA通道的全局中断标志。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @retval The specified transfer error flag index.
  *         指定的全局中断标志索引。
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
  * @brief  Get the DMA Channel pending flags.
  *         获取DMA通道的挂起标志位。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @param  __FLAG__: Get the specified flag.
  *         获取指定的标志位。
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCx:  Transfer complete flag (传输完成标志)
  *            @arg DMA_FLAG_HTx:  Half transfer complete flag (半传输完成标志)
  *            @arg DMA_FLAG_TEx:  Transfer error flag (传输错误标志)
  *            @arg DMA_FLAG_GLx:  Global interrupt flag (全局中断标志)
  *         Where x can be 1_7 to select the DMA Channel flag.   
  *         其中x可以是1_7，用于选择DMA通道标志。
  * @retval The state of FLAG (SET or RESET).
  *         标志的状态（SET或RESET）。
  *
  * 说明：低密度/中密度设备只需读取DMA1->ISR寄存器。
  */
#define __HAL_DMA_GET_FLAG(__HANDLE__, __FLAG__)   (DMA1->ISR & (__FLAG__))

/**
  * @brief  Clear the DMA Channel pending flags.
  *         清除DMA通道的挂起标志位。
  * @param  __HANDLE__: DMA handle
  *         DMA句柄
  * @param  __FLAG__: specifies the flag to clear.
  *         指定要清除的标志位。
  *          This parameter can be any combination of the following values:
  *            @arg DMA_FLAG_TCx:  Transfer complete flag (传输完成标志)
  *            @arg DMA_FLAG_HTx:  Half transfer complete flag (半传输完成标志)
  *            @arg DMA_FLAG_TEx:  Transfer error flag (传输错误标志)
  *            @arg DMA_FLAG_GLx:  Global interrupt flag (全局中断标志)
  *         Where x can be 1_7 to select the DMA Channel flag.   
  *         其中x可以是1_7，用于选择DMA通道标志。
  * @retval None
  *         无返回值
  *
  * 说明：低密度/中密度设备只需写DMA1->IFCR寄存器。
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
