/**
  ******************************************************************************
  * @file    stm32f1xx_ll_dma.h
  * @author  MCD Application Team
  * @brief   DMA LL模块头文件。
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
#ifndef __STM32F1xx_LL_DMA_H
#define __STM32F1xx_LL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined (DMA1) || defined (DMA2)

/** @defgroup DMA_LL DMA
  * @{
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/** @defgroup DMA_LL_Private_Variables DMA 私有变量
  * @{
  */
/* 该数组用于获取DMA通道寄存器相对于通道索引 LL_DMA_CHANNEL_x 的偏移量 */
static const uint8_t CHANNEL_OFFSET_TAB[] =
{
  (uint8_t)(DMA1_Channel1_BASE - DMA1_BASE), // 通道1寄存器基地址相对于DMA1基地址的偏移
  (uint8_t)(DMA1_Channel2_BASE - DMA1_BASE), // 通道2寄存器基地址相对于DMA1基地址的偏移
  (uint8_t)(DMA1_Channel3_BASE - DMA1_BASE), // 通道3寄存器基地址相对于DMA1基地址的偏移
  (uint8_t)(DMA1_Channel4_BASE - DMA1_BASE), // 通道4寄存器基地址相对于DMA1基地址的偏移
  (uint8_t)(DMA1_Channel5_BASE - DMA1_BASE), // 通道5寄存器基地址相对于DMA1基地址的偏移
  (uint8_t)(DMA1_Channel6_BASE - DMA1_BASE), // 通道6寄存器基地址相对于DMA1基地址的偏移
  (uint8_t)(DMA1_Channel7_BASE - DMA1_BASE)  // 通道7寄存器基地址相对于DMA1基地址的偏移
};
/**
  * @}
  */
/* 私有常量 ---------------------------------------------------------*/
/* 私有宏 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_Private_Macros DMA 私有宏
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* 导出类型 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_ES_INIT DMA 导出初始化结构体
  * @{
  */
typedef struct
{
  uint32_t PeriphOrM2MSrcAddress;  /*!< 指定DMA传输的外设基地址，
                                        或者在存储器到存储器传输模式下作为源基地址。
                                        此参数必须是 Min_Data = 0 到 Max_Data = 0xFFFFFFFF 之间的值。 */

  uint32_t MemoryOrM2MDstAddress;  /*!< 指定DMA传输的存储器基地址，
                                        或者在存储器到存储器传输模式下作为目标基地址。
                                        此参数必须是 Min_Data = 0 到 Max_Data = 0xFFFFFFFF 之间的值。 */

  uint32_t Direction;              /*!< 指定数据传输方向：从存储器到外设、从存储器到存储器或从外设到存储器。
                                        此参数可以是 @ref DMA_LL_EC_DIRECTION 中的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetDataTransferDirection() 进行修改。 */

  uint32_t Mode;                   /*!< 指定正常模式或循环操作模式。
                                        此参数可以是 @ref DMA_LL_EC_MODE 中的值
                                        注意: 如果在选定的通道上配置了存储器到存储器的数据传输方向，
                                        则不能使用循环缓冲模式。
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetMode() 进行修改。 */

  uint32_t PeriphOrM2MSrcIncMode;  /*!< 指定外设地址是否递增，或者在存储器到存储器传输模式下源地址是否递增。
                                        此参数可以是 @ref DMA_LL_EC_PERIPH 中的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetPeriphIncMode() 进行修改。 */

  uint32_t MemoryOrM2MDstIncMode;  /*!< 指定存储器地址是否递增，或者在存储器到存储器传输模式下目标地址是否递增。
                                        此参数可以是 @ref DMA_LL_EC_MEMORY 中的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetMemoryIncMode() 进行修改。 */

  uint32_t PeriphOrM2MSrcDataSize; /*!< 指定外设数据宽度，或者在存储器到存储器传输模式下的源数据宽度（字节、半字、字）。
                                        此参数可以是 @ref DMA_LL_EC_PDATAALIGN 中的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetPeriphSize() 进行修改。 */

  uint32_t MemoryOrM2MDstDataSize; /*!< 指定存储器数据宽度，或者在存储器到存储器传输模式下的目标数据宽度（字节、半字、字）。
                                        此参数可以是 @ref DMA_LL_EC_MDATAALIGN 中的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetMemorySize() 进行修改。 */

  uint32_t NbData;                 /*!< 指定要传输的数据量，以数据单元为单位。
                                        数据单元等于在 PeripheralSize 或 MemorySize 参数中设置的源缓冲区配置，
                                        具体取决于传输方向。
                                        此参数必须是 Min_Data = 0 到 Max_Data = 0x0000FFFF 之间的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetDataLength() 进行修改。 */

  uint32_t Priority;               /*!< 指定通道优先级。
                                        此参数可以是 @ref DMA_LL_EC_PRIORITY 中的值
                                        此特性之后可以使用单元函数 @ref LL_DMA_SetChannelPriorityLevel() 进行修改。 */

} LL_DMA_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* 导出常量 --------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Constants DMA 导出常量
  * @{
  */
/** @defgroup DMA_LL_EC_CLEAR_FLAG 清除标志位定义
  * @brief    标志位定义，可用于 LL_DMA_WriteReg 函数
  * @{
  */
#define LL_DMA_IFCR_CGIF1                 DMA_IFCR_CGIF1        /*!< 通道1全局标志 */
#define LL_DMA_IFCR_CTCIF1                DMA_IFCR_CTCIF1       /*!< 通道1传输完成标志 */
#define LL_DMA_IFCR_CHTIF1                DMA_IFCR_CHTIF1       /*!< 通道1半传输标志 */
#define LL_DMA_IFCR_CTEIF1                DMA_IFCR_CTEIF1       /*!< 通道1传输错误标志 */
#define LL_DMA_IFCR_CGIF2                 DMA_IFCR_CGIF2        /*!< 通道2全局标志 */
#define LL_DMA_IFCR_CTCIF2                DMA_IFCR_CTCIF2       /*!< 通道2传输完成标志 */
#define LL_DMA_IFCR_CHTIF2                DMA_IFCR_CHTIF2       /*!< 通道2半传输标志 */
#define LL_DMA_IFCR_CTEIF2                DMA_IFCR_CTEIF2       /*!< 通道2传输错误标志 */
#define LL_DMA_IFCR_CGIF3                 DMA_IFCR_CGIF3        /*!< 通道3全局标志 */
#define LL_DMA_IFCR_CTCIF3                DMA_IFCR_CTCIF3       /*!< 通道3传输完成标志 */
#define LL_DMA_IFCR_CHTIF3                DMA_IFCR_CHTIF3       /*!< 通道3半传输标志 */
#define LL_DMA_IFCR_CTEIF3                DMA_IFCR_CTEIF3       /*!< 通道3传输错误标志 */
#define LL_DMA_IFCR_CGIF4                 DMA_IFCR_CGIF4        /*!< 通道4全局标志 */
#define LL_DMA_IFCR_CTCIF4                DMA_IFCR_CTCIF4       /*!< 通道4传输完成标志 */
#define LL_DMA_IFCR_CHTIF4                DMA_IFCR_CHTIF4       /*!< 通道4半传输标志 */
#define LL_DMA_IFCR_CTEIF4                DMA_IFCR_CTEIF4       /*!< 通道4传输错误标志 */
#define LL_DMA_IFCR_CGIF5                 DMA_IFCR_CGIF5        /*!< 通道5全局标志 */
#define LL_DMA_IFCR_CTCIF5                DMA_IFCR_CTCIF5       /*!< 通道5传输完成标志 */
#define LL_DMA_IFCR_CHTIF5                DMA_IFCR_CHTIF5       /*!< 通道5半传输标志 */
#define LL_DMA_IFCR_CTEIF5                DMA_IFCR_CTEIF5       /*!< 通道5传输错误标志 */
#define LL_DMA_IFCR_CGIF6                 DMA_IFCR_CGIF6        /*!< 通道6全局标志 */
#define LL_DMA_IFCR_CTCIF6                DMA_IFCR_CTCIF6       /*!< 通道6传输完成标志 */
#define LL_DMA_IFCR_CHTIF6                DMA_IFCR_CHTIF6       /*!< 通道6半传输标志 */
#define LL_DMA_IFCR_CTEIF6                DMA_IFCR_CTEIF6       /*!< 通道6传输错误标志 */
#define LL_DMA_IFCR_CGIF7                 DMA_IFCR_CGIF7        /*!< 通道7全局标志 */
#define LL_DMA_IFCR_CTCIF7                DMA_IFCR_CTCIF7       /*!< 通道7传输完成标志 */
#define LL_DMA_IFCR_CHTIF7                DMA_IFCR_CHTIF7       /*!< 通道7半传输标志 */
#define LL_DMA_IFCR_CTEIF7                DMA_IFCR_CTEIF7       /*!< 通道7传输错误标志 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_GET_FLAG 获取标志位定义
  * @brief    标志位定义，可用于 LL_DMA_ReadReg 函数
  * @{
  */
#define LL_DMA_ISR_GIF1                   DMA_ISR_GIF1          /*!< 通道1全局标志 */
#define LL_DMA_ISR_TCIF1                  DMA_ISR_TCIF1         /*!< 通道1传输完成标志 */
#define LL_DMA_ISR_HTIF1                  DMA_ISR_HTIF1         /*!< 通道1半传输标志 */
#define LL_DMA_ISR_TEIF1                  DMA_ISR_TEIF1         /*!< 通道1传输错误标志 */
#define LL_DMA_ISR_GIF2                   DMA_ISR_GIF2          /*!< 通道2全局标志 */
#define LL_DMA_ISR_TCIF2                  DMA_ISR_TCIF2         /*!< 通道2传输完成标志 */
#define LL_DMA_ISR_HTIF2                  DMA_ISR_HTIF2         /*!< 通道2半传输标志 */
#define LL_DMA_ISR_TEIF2                  DMA_ISR_TEIF2         /*!< 通道2传输错误标志 */
#define LL_DMA_ISR_GIF3                   DMA_ISR_GIF3          /*!< 通道3全局标志 */
#define LL_DMA_ISR_TCIF3                  DMA_ISR_TCIF3         /*!< 通道3传输完成标志 */
#define LL_DMA_ISR_HTIF3                  DMA_ISR_HTIF3         /*!< 通道3半传输标志 */
#define LL_DMA_ISR_TEIF3                  DMA_ISR_TEIF3         /*!< 通道3传输错误标志 */
#define LL_DMA_ISR_GIF4                   DMA_ISR_GIF4          /*!< 通道4全局标志 */
#define LL_DMA_ISR_TCIF4                  DMA_ISR_TCIF4         /*!< 通道4传输完成标志 */
#define LL_DMA_ISR_HTIF4                  DMA_ISR_HTIF4         /*!< 通道4半传输标志 */
#define LL_DMA_ISR_TEIF4                  DMA_ISR_TEIF4         /*!< 通道4传输错误标志 */
#define LL_DMA_ISR_GIF5                   DMA_ISR_GIF5          /*!< 通道5全局标志 */
#define LL_DMA_ISR_TCIF5                  DMA_ISR_TCIF5         /*!< 通道5传输完成标志 */
#define LL_DMA_ISR_HTIF5                  DMA_ISR_HTIF5         /*!< 通道5半传输标志 */
#define LL_DMA_ISR_TEIF5                  DMA_ISR_TEIF5         /*!< 通道5传输错误标志 */
#define LL_DMA_ISR_GIF6                   DMA_ISR_GIF6          /*!< 通道6全局标志 */
#define LL_DMA_ISR_TCIF6                  DMA_ISR_TCIF6         /*!< 通道6传输完成标志 */
#define LL_DMA_ISR_HTIF6                  DMA_ISR_HTIF6         /*!< 通道6半传输标志 */
#define LL_DMA_ISR_TEIF6                  DMA_ISR_TEIF6         /*!< 通道6传输错误标志 */
#define LL_DMA_ISR_GIF7                   DMA_ISR_GIF7          /*!< 通道7全局标志 */
#define LL_DMA_ISR_TCIF7                  DMA_ISR_TCIF7         /*!< 通道7传输完成标志 */
#define LL_DMA_ISR_HTIF7                  DMA_ISR_HTIF7         /*!< 通道7半传输标志 */
#define LL_DMA_ISR_TEIF7                  DMA_ISR_TEIF7         /*!< 通道7传输错误标志 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_IT 中断定义
  * @brief    中断定义，可用于 LL_DMA_ReadReg 和 LL_DMA_WriteReg 函数
  * @{
  */
#define LL_DMA_CCR_TCIE                   DMA_CCR_TCIE          /*!< 传输完成中断 */
#define LL_DMA_CCR_HTIE                   DMA_CCR_HTIE          /*!< 半传输中断 */
#define LL_DMA_CCR_TEIE                   DMA_CCR_TEIE          /*!< 传输错误中断 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CHANNEL 通道
  * @{
  */
#define LL_DMA_CHANNEL_1                  0x00000001U /*!< DMA 通道1 */
#define LL_DMA_CHANNEL_2                  0x00000002U /*!< DMA 通道2 */
#define LL_DMA_CHANNEL_3                  0x00000003U /*!< DMA 通道3 */
#define LL_DMA_CHANNEL_4                  0x00000004U /*!< DMA 通道4 */
#define LL_DMA_CHANNEL_5                  0x00000005U /*!< DMA 通道5 */
#define LL_DMA_CHANNEL_6                  0x00000006U /*!< DMA 通道6 */
#define LL_DMA_CHANNEL_7                  0x00000007U /*!< DMA 通道7 */
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_ALL                0xFFFF0000U /*!< DMA 所有通道 (仅用于函数 @ref LL_DMA_DeInit() */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DIRECTION 传输方向
  * @{
  */
#define LL_DMA_DIRECTION_PERIPH_TO_MEMORY 0x00000000U             /*!< 外设到存储器方向 */
#define LL_DMA_DIRECTION_MEMORY_TO_PERIPH DMA_CCR_DIR             /*!< 存储器到外设方向 */
#define LL_DMA_DIRECTION_MEMORY_TO_MEMORY DMA_CCR_MEM2MEM         /*!< 存储器到存储器方向 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MODE 传输模式
  * @{
  */
#define LL_DMA_MODE_NORMAL                0x00000000U             /*!< 正常模式 */
#define LL_DMA_MODE_CIRCULAR              DMA_CCR_CIRC            /*!< 循环模式 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_PERIPH 外设增量模式
  * @{
  */
#define LL_DMA_PERIPH_INCREMENT           DMA_CCR_PINC            /*!< 外设增量模式使能 */
#define LL_DMA_PERIPH_NOINCREMENT         0x00000000U             /*!< 外设增量模式禁止 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MEMORY 存储器增量模式
  * @{
  */
#define LL_DMA_MEMORY_INCREMENT           DMA_CCR_MINC            /*!< 存储器增量模式使能 */
#define LL_DMA_MEMORY_NOINCREMENT         0x00000000U             /*!< 存储器增量模式禁止 */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_PDATAALIGN 外设数据对齐
  * @{
  */
#define LL_DMA_PDATAALIGN_BYTE            0x00000000U             /*!< 外设数据宽度：字节 (8位) */
#define LL_DMA_PDATAALIGN_HALFWORD        DMA_CCR_PSIZE_0         /*!< 外设数据宽度：半字 (16位) */
#define LL_DMA_PDATAALIGN_WORD            DMA_CCR_PSIZE_1         /*!< 外设数据宽度：字 (32位) */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MDATAALIGN 存储器数据对齐
  * @{
  */
#define LL_DMA_MDATAALIGN_BYTE            0x00000000U             /*!< 存储器数据宽度：字节 (8位) */
#define LL_DMA_MDATAALIGN_HALFWORD        DMA_CCR_MSIZE_0         /*!< 存储器数据宽度：半字 (16位) */
#define LL_DMA_MDATAALIGN_WORD            DMA_CCR_MSIZE_1         /*!< 存储器数据宽度：字 (32位) */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_PRIORITY 传输优先级
  * @{
  */
#define LL_DMA_PRIORITY_LOW               0x00000000U             /*!< 优先级：低 */
#define LL_DMA_PRIORITY_MEDIUM            DMA_CCR_PL_0            /*!< 优先级：中 */
#define LL_DMA_PRIORITY_HIGH              DMA_CCR_PL_1            /*!< 优先级：高 */
#define LL_DMA_PRIORITY_VERYHIGH          DMA_CCR_PL              /*!< 优先级：非常高 */
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Macros DMA 导出宏
  * @{
  */

/** @defgroup DMA_LL_EM_WRITE_READ 通用读写寄存器宏
  * @{
  */
/**
  * @brief  向DMA寄存器写入值
  * @param  __INSTANCE__ DMA实例
  * @param  __REG__ 要写入的寄存器
  * @param  __VALUE__ 要写入寄存器的值
  * @retval 无
  */
#define LL_DMA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  从DMA寄存器读取值
  * @param  __INSTANCE__ DMA实例
  * @param  __REG__ 要读取的寄存器
  * @retval 寄存器值
  */
#define LL_DMA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup DMA_LL_EM_CONVERT_DMAxCHANNELy 转换 DMAxChannely
  * @{
  */

/**
  * @brief  将 DMAx_Channely 转换为 DMAx
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval DMAx
  */
#if defined(DMA2)
// 如果通道实例地址大于DMA1_Channel7的地址，则属于DMA2，否则属于DMA1
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) > ((uint32_t)DMA1_Channel7)) ?  DMA2 : DMA1)
#else
// 如果未定义DMA2，则实例只能是DMA1
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)  (DMA1)
#endif

/**
  * @brief  将 DMAx_Channely 转换为 LL_DMA_CHANNEL_y
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval LL_DMA_CHANNEL_y
  */
#if defined (DMA2)
// 根据通道实例地址判断属于哪个通道，支持DMA1和DMA2
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA2_Channel5)) ? LL_DMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel6)) ? LL_DMA_CHANNEL_6 : \
 LL_DMA_CHANNEL_7)
#else
// 仅支持DMA1的情况，根据通道实例地址判断通道号
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel6)) ? LL_DMA_CHANNEL_6 : \
 LL_DMA_CHANNEL_7)
#endif
