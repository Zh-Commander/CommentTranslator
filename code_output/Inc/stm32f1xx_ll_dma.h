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
/**
  * @brief  将DMA实例DMAx和通道LL_DMA_CHANNEL_y转换为DMAx_Channely格式的地址
  * @param  __DMA_INSTANCE__ DMA实例，如DMA1, DMA2
  * @param  __CHANNEL__ DMA通道，如LL_DMA_CHANNEL_1
  * @retval 返回对应的DMA通道实例地址，如DMA1_Channel1
  */
#if defined (DMA2)
/* 如果定义了DMA2，说明芯片具有两个DMA控制器，支持DMA1和DMA2的所有通道 */
#define __LL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA1_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA2_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA1_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA2_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA1_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA2_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA1_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA2_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA1_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA2)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA2_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_6))) ? DMA1_Channel6 : \
 DMA1_Channel7)
#else
/* 如果未定义DMA2，说明芯片只有一个DMA控制器(DMA1)，仅支持DMA1的通道 */
#define __LL_DMA_GET_CHANNEL_INSTANCE(__DMA_INSTANCE__, __CHANNEL__)   \
((((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_1))) ? DMA1_Channel1 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_2))) ? DMA1_Channel2 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_3))) ? DMA1_Channel3 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_4))) ? DMA1_Channel4 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_5))) ? DMA1_Channel5 : \
 (((uint32_t)(__DMA_INSTANCE__) == ((uint32_t)DMA1)) && ((uint32_t)(__CHANNEL__) == ((uint32_t)LL_DMA_CHANNEL_6))) ? DMA1_Channel6 : \
 DMA1_Channel7)
#endif

/**
  * @}
  */

/**
  * @}
  */

/* 导出函数 ------------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Functions DMA 导出函数
 * @{
 */

/** @defgroup DMA_LL_EF_Configuration 配置函数
  * @{
  */
/**
  * @brief  使能DMA通道。
  * @rmtoll CCR          EN            LL_DMA_EnableChannel
  * @param  DMAx DMA实例，可以是DMA1或DMA2
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 
     1. CHANNEL_OFFSET_TAB[Channel - 1U]: 获取通道对应的寄存器偏移地址
     2. (uint32_t)DMAx + ...: 计算通道寄存器组的基地址
     3. 强制转换为 (DMA_Channel_TypeDef *) 指针
     4. SET_BIT: 设置 CCR 寄存器中的 EN 位，使能该通道
  */
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_EN);
}

/**
  * @brief  失能DMA通道。
  * @rmtoll CCR          EN            LL_DMA_DisableChannel
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 清除 CCR 寄存器中的 EN 位，关闭该通道 */
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_EN);
}

/**
  * @brief  检查DMA通道是否已使能。
  * @rmtoll CCR          EN            LL_DMA_IsEnabledChannel
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledChannel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器中的 EN 位，并判断是否置1 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_EN) == (DMA_CCR_EN));
}

/**
  * @brief  配置所有与DMA传输相关的参数。
  * @rmtoll CCR          DIR           LL_DMA_ConfigTransfer\n
  *         CCR          MEM2MEM       LL_DMA_ConfigTransfer\n
  *         CCR          CIRC          LL_DMA_ConfigTransfer\n
  *         CCR          PINC          LL_DMA_ConfigTransfer\n
  *         CCR          MINC          LL_DMA_ConfigTransfer\n
  *         CCR          PSIZE         LL_DMA_ConfigTransfer\n
  *         CCR          MSIZE         LL_DMA_ConfigTransfer\n
  *         CCR          PL            LL_DMA_ConfigTransfer
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  Configuration 该参数必须是以下所有值的组合:
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH 或 @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY
  *         @arg @ref LL_DMA_MODE_NORMAL 或 @ref LL_DMA_MODE_CIRCULAR
  *         @arg @ref LL_DMA_PERIPH_INCREMENT 或 @ref LL_DMA_PERIPH_NOINCREMENT
  *         @arg @ref LL_DMA_MEMORY_INCREMENT 或 @ref LL_DMA_MEMORY_NOINCREMENT
  *         @arg @ref LL_DMA_PDATAALIGN_BYTE 或 @ref LL_DMA_PDATAALIGN_HALFWORD 或 @ref LL_DMA_PDATAALIGN_WORD
  *         @arg @ref LL_DMA_MDATAALIGN_BYTE 或 @ref LL_DMA_MDATAALIGN_HALFWORD 或 @ref LL_DMA_MDATAALIGN_WORD
  *         @arg @ref LL_DMA_PRIORITY_LOW 或 @ref LL_DMA_PRIORITY_MEDIUM 或 @ref LL_DMA_PRIORITY_HIGH 或 @ref LL_DMA_PRIORITY_VERYHIGH
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ConfigTransfer(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Configuration)
{
  /* 
     使用 MODIFY_REG 宏修改 CCR 寄存器。
     第二个参数是掩码，指定要修改的位（方向、模式、增量、数据宽度、优先级等）。
     第三个参数是新的配置值。
  */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
             DMA_CCR_DIR | DMA_CCR_MEM2MEM | DMA_CCR_CIRC | DMA_CCR_PINC | DMA_CCR_MINC | DMA_CCR_PSIZE | DMA_CCR_MSIZE | DMA_CCR_PL,
             Configuration);
}

/**
  * @brief  设置数据传输方向 (从外设读或从内存读)。
  * @rmtoll CCR          DIR           LL_DMA_SetDataTransferDirection\n
  *         CCR          MEM2MEM       LL_DMA_SetDataTransferDirection
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  Direction 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY (外设到内存)
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH (内存到外设)
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY (内存到内存)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetDataTransferDirection(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Direction)
{
  /* 修改 CCR 寄存器的 DIR 和 MEM2MEM 位来设置传输方向 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
             DMA_CCR_DIR | DMA_CCR_MEM2MEM, Direction);
}

/**
  * @brief  获取数据传输方向 (从外设读或从内存读)。
  * @rmtoll CCR          DIR           LL_DMA_GetDataTransferDirection\n
  *         CCR          MEM2MEM       LL_DMA_GetDataTransferDirection
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY
  */
__STATIC_INLINE uint32_t LL_DMA_GetDataTransferDirection(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器的 DIR 和 MEM2MEM 位 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_DIR | DMA_CCR_MEM2MEM));
}

/**
  * @brief  设置DMA模式：循环模式或正常模式。
  * @note   如果在选定的通道上配置了内存到内存的数据传输，则不能使用循环缓冲区模式。
  * @rmtoll CCR          CIRC          LL_DMA_SetMode
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  Mode 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_MODE_NORMAL (正常模式)
  *         @arg @ref LL_DMA_MODE_CIRCULAR (循环模式)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Mode)
{
  /* 修改 CCR 寄存器的 CIRC 位来设置是否循环传输 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_CIRC,
             Mode);
}

/**
  * @brief  获取DMA模式：循环模式或正常模式。
  * @rmtoll CCR          CIRC          LL_DMA_GetMode
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_DMA_MODE_NORMAL
  *         @arg @ref LL_DMA_MODE_CIRCULAR
  */
__STATIC_INLINE uint32_t LL_DMA_GetMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器的 CIRC 位 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_CIRC));
}

/**
  * @brief  设置外设地址增量模式。
  * @rmtoll CCR          PINC          LL_DMA_SetPeriphIncMode
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  PeriphOrM2MSrcIncMode 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_PERIPH_INCREMENT (外设地址自增)
  *         @arg @ref LL_DMA_PERIPH_NOINCREMENT (外设地址不自增)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetPeriphIncMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphOrM2MSrcIncMode)
{
  /* 修改 CCR 寄存器的 PINC 位 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_PINC,
             PeriphOrM2MSrcIncMode);
}

/**
  * @brief  获取外设地址增量模式。
  * @rmtoll CCR          PINC          LL_DMA_GetPeriphIncMode
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_DMA_PERIPH_INCREMENT
  *         @arg @ref LL_DMA_PERIPH_NOINCREMENT
  */
__STATIC_INLINE uint32_t LL_DMA_GetPeriphIncMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器的 PINC 位 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_PINC));
}

/**
  * @brief  设置内存地址增量模式。
  * @rmtoll CCR          MINC          LL_DMA_SetMemoryIncMode
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  MemoryOrM2MDstIncMode 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_MEMORY_INCREMENT (内存地址自增)
  *         @arg @ref LL_DMA_MEMORY_NOINCREMENT (内存地址不自增)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetMemoryIncMode(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryOrM2MDstIncMode)
{
  /* 修改 CCR 寄存器的 MINC 位 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_MINC,
             MemoryOrM2MDstIncMode);
}

/**
  * @brief  获取内存地址增量模式。
  * @rmtoll CCR          MINC          LL_DMA_GetMemoryIncMode
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_DMA_MEMORY_INCREMENT
  *         @arg @ref LL_DMA_MEMORY_NOINCREMENT
  */
__STATIC_INLINE uint32_t LL_DMA_GetMemoryIncMode(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器的 MINC 位 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_MINC));
}

/**
  * @brief  设置外设数据宽度。
  * @rmtoll CCR          PSIZE         LL_DMA_SetPeriphSize
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  PeriphOrM2MSrcDataSize 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_PDATAALIGN_BYTE (8位)
  *         @arg @ref LL_DMA_PDATAALIGN_HALFWORD (16位)
  *         @arg @ref LL_DMA_PDATAALIGN_WORD (32位)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetPeriphSize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphOrM2MSrcDataSize)
{
  /* 修改 CCR 寄存器的 PSIZE 位 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_PSIZE,
             PeriphOrM2MSrcDataSize);
}

/**
  * @brief  获取外设数据宽度。
  * @rmtoll CCR          PSIZE         LL_DMA_GetPeriphSize
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_DMA_PDATAALIGN_BYTE
  *         @arg @ref LL_DMA_PDATAALIGN_HALFWORD
  *         @arg @ref LL_DMA_PDATAALIGN_WORD
  */
__STATIC_INLINE uint32_t LL_DMA_GetPeriphSize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器的 PSIZE 位 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_PSIZE));
}

/**
  * @brief  设置内存数据宽度。
  * @rmtoll CCR          MSIZE         LL_DMA_SetMemorySize
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  MemoryOrM2MDstDataSize 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_MDATAALIGN_BYTE (8位)
  *         @arg @ref LL_DMA_MDATAALIGN_HALFWORD (16位)
  *         @arg @ref LL_DMA_MDATAALIGN_WORD (32位)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetMemorySize(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryOrM2MDstDataSize)
{
  /* 修改 CCR 寄存器的 MSIZE 位 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_MSIZE,
             MemoryOrM2MDstDataSize);
}

/**
  * @brief  获取内存数据宽度。
  * @rmtoll CCR          MSIZE         LL_DMA_GetMemorySize
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_DMA_MDATAALIGN_BYTE
  *         @arg @ref LL_DMA_MDATAALIGN_HALFWORD
  *         @arg @ref LL_DMA_MDATAALIGN_WORD
  */
__STATIC_INLINE uint32_t LL_DMA_GetMemorySize(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取 CCR 寄存器的 MSIZE 位 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_MSIZE));
}

/**
  * @brief  设置通道优先级。
  * @rmtoll CCR          PL            LL_DMA_SetChannelPriorityLevel
  * @param  DMAx DMA实例
  * @param  Channel 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @param  Priority 该参数可以是以下值之一:
  *         @arg @ref LL_DMA_PRIORITY_LOW (低)
  *         @arg @ref LL_DMA_PRIORITY_MEDIUM (中)
  *         @arg @ref LL_DMA_PRIORITY_HIGH (高)
  *         @arg @ref LL_DMA_PRIORITY_VERYHIGH (非常高)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t Priority)
{
  /* 修改 CCR 寄存器的 PL 位来配置优先级 */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_PL,
             Priority);
}
/**
  * @brief  获取DMA通道优先级等级。
  * @rmtoll CCR          PL            LL_DMA_GetChannelPriorityLevel
  * @param  DMAx DMAx实例指针，指向DMA控制器基地址
  * @param  Channel 通道号，该参数可以是以下值之一：
  *         @arg @ref LL_DMA_CHANNEL_1 (通道1)
  *         @arg @ref LL_DMA_CHANNEL_2 (通道2)
  *         @arg @ref LL_DMA_CHANNEL_3 (通道3)
  *         @arg @ref LL_DMA_CHANNEL_4 (通道4)
  *         @arg @ref LL_DMA_CHANNEL_5 (通道5)
  *         @arg @ref LL_DMA_CHANNEL_6 (通道6)
  *         @arg @ref LL_DMA_CHANNEL_7 (通道7)
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_DMA_PRIORITY_LOW (低优先级)
  *         @arg @ref LL_DMA_PRIORITY_MEDIUM (中优先级)
  *         @arg @ref LL_DMA_PRIORITY_HIGH (高优先级)
  *         @arg @ref LL_DMA_PRIORITY_VERYHIGH (极高优先级)
  */
__STATIC_INLINE uint32_t LL_DMA_GetChannelPriorityLevel(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 
     1. (Channel - 1U): 通道号减1，因为数组索引从0开始
     2. CHANNEL_OFFSET_TAB[...]: 查表获取该通道寄存器的地址偏移量
     3. (uint32_t)DMAx + ...: 基地址加上偏移量，计算出具体通道的寄存器组地址
     4. 强制转换为 (DMA_Channel_TypeDef *) 指针
     5. READ_BIT: 读取CCR寄存器中的PL位域（优先级配置位）
  */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_PL));
}

/**
  * @brief  设置要传输的数据长度（数量）。
  * @note   如果通道已使能，此操作无效。
  *         必须在DMA通道禁用状态下配置。
  * @rmtoll CNDTR        NDT           LL_DMA_SetDataLength
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  NbData 要传输的数据量，范围：Min_Data = 0 到 Max_Data = 0x0000FFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetDataLength(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t NbData)
{
  /* 
     配置CNDTR寄存器中的NDT位域。
     CNDTR寄存器保存当前还需要传输的数据数目。
     MODIFY_REG宏用于修改寄存器的部分位，不影响其他位。
  */
  MODIFY_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CNDTR,
             DMA_CNDTR_NDT, NbData);
}

/**
  * @brief  获取剩余待传输的数据长度。
  * @note   一旦通道使能，返回值表示剩余待传输的字节数。
  *         随着传输进行，该值会递减。
  * @rmtoll CNDTR        NDT           LL_DMA_GetDataLength
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回剩余数据长度，范围：Min_Data = 0 到 Max_Data = 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetDataLength(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CNDTR寄存器中的NDT位域，获取当前剩余传输数据量 */
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CNDTR,
                   DMA_CNDTR_NDT));
}

/**
  * @brief  配置源地址和目标地址。
  * @note   当DMA通道使能时，禁止调用此API。
  * @note   使用DMA的外设通常会提供API直接获取寄存器地址 (LL_PPP_DMA_GetRegAddr)。
  * @rmtoll CPAR         PA            LL_DMA_ConfigAddresses\n
  *         CMAR         MA            LL_DMA_ConfigAddresses
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  SrcAddress 源地址，范围：0 到 0xFFFFFFFF
  * @param  DstAddress 目标地址，范围：0 到 0xFFFFFFFF
  * @param  Direction 传输方向，该参数可以是以下值之一：
  *         @arg @ref LL_DMA_DIRECTION_PERIPH_TO_MEMORY (外设到内存)
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_PERIPH (内存到外设)
  *         @arg @ref LL_DMA_DIRECTION_MEMORY_TO_MEMORY (内存到内存)
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ConfigAddresses(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t SrcAddress,
                                            uint32_t DstAddress, uint32_t Direction)
{
  /* 方向：内存到外设 */
  if (Direction == LL_DMA_DIRECTION_MEMORY_TO_PERIPH)
  {
    /* 源是内存，写入CMAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, SrcAddress);
    /* 目标是外设，写入CPAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, DstAddress);
  }
  /* 方向：外设到内存 或 内存到内存 */
  else
  {
    /* 源是外设(或内存)，写入CPAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, SrcAddress);
    /* 目标是内存，写入CMAR寄存器 */
    WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, DstAddress);
  }
}

/**
  * @brief  设置内存地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CMAR         MA            LL_DMA_SetMemoryAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  MemoryAddress 内存地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetMemoryAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  /* 将地址写入CMAR（DMA通道内存地址寄存器） */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, MemoryAddress);
}

/**
  * @brief  设置外设地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CPAR         PA            LL_DMA_SetPeriphAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  PeriphAddress 外设地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetPeriphAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t PeriphAddress)
{
  /* 将地址写入CPAR（DMA通道外设地址寄存器） */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, PeriphAddress);
}

/**
  * @brief  获取内存地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @rmtoll CMAR         MA            LL_DMA_GetMemoryAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回内存地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetMemoryAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CMAR寄存器的值 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR));
}

/**
  * @brief  获取外设地址。
  * @note   仅用于 LL_DMA_DIRECTION_PERIPH_TO_MEMORY 或 LL_DMA_DIRECTION_MEMORY_TO_PERIPH 方向。
  * @rmtoll CPAR         PA            LL_DMA_GetPeriphAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回外设地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetPeriphAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CPAR寄存器的值 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR));
}

/**
  * @brief  设置内存到内存模式的源地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CPAR         PA            LL_DMA_SetM2MSrcAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  MemoryAddress 内存地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetM2MSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  /* 在M2M模式下，CPAR寄存器被用作源地址 */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR, MemoryAddress);
}

/**
  * @brief  设置内存到内存模式的目标地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @note   当DMA通道使能时，禁止调用此API。
  * @rmtoll CMAR         MA            LL_DMA_SetM2MDstAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @param  MemoryAddress 内存地址，范围：0 到 0xFFFFFFFF
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_SetM2MDstAddress(DMA_TypeDef *DMAx, uint32_t Channel, uint32_t MemoryAddress)
{
  /* 在M2M模式下，CMAR寄存器被用作目标地址 */
  WRITE_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR, MemoryAddress);
}

/**
  * @brief  获取内存到内存模式的源地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @rmtoll CPAR         PA            LL_DMA_GetM2MSrcAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回源地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetM2MSrcAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CPAR寄存器，作为M2M模式的源地址 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CPAR));
}

/**
  * @brief  获取内存到内存模式的目标地址。
  * @note   仅用于 LL_DMA_DIRECTION_MEMORY_TO_MEMORY 方向。
  * @rmtoll CMAR         MA            LL_DMA_GetM2MDstAddress
  * @param  DMAx DMAx实例指针
  * @param  Channel 通道号，取值范围同上
  * @retval 返回目标地址，范围：0 到 0xFFFFFFFF
  */
__STATIC_INLINE uint32_t LL_DMA_GetM2MDstAddress(DMA_TypeDef *DMAx, uint32_t Channel)
{
  /* 读取CMAR寄存器，作为M2M模式的目标地址 */
  return (READ_REG(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CMAR));
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_FLAG_Management 标志位管理
  * @{
  */

/**
  * @brief  获取通道1的全局中断标志。
  * @rmtoll ISR          GIF1          LL_DMA_IsActiveFlag_GI1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI1(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF1位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF1) == (DMA_ISR_GIF1));
}

/**
  * @brief  获取通道2的全局中断标志。
  * @rmtoll ISR          GIF2          LL_DMA_IsActiveFlag_GI2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI2(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF2位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF2) == (DMA_ISR_GIF2));
}

/**
  * @brief  获取通道3的全局中断标志。
  * @rmtoll ISR          GIF3          LL_DMA_IsActiveFlag_GI3
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI3(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF3位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF3) == (DMA_ISR_GIF3));
}

/**
  * @brief  获取通道4的全局中断标志。
  * @rmtoll ISR          GIF4          LL_DMA_IsActiveFlag_GI4
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI4(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF4位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF4) == (DMA_ISR_GIF4));
}

/**
  * @brief  获取通道5的全局中断标志。
  * @rmtoll ISR          GIF5          LL_DMA_IsActiveFlag_GI5
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI5(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF5位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF5) == (DMA_ISR_GIF5));
}

/**
  * @brief  获取通道6的全局中断标志。
  * @rmtoll ISR          GIF6          LL_DMA_IsActiveFlag_GI6
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI6(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF6位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF6) == (DMA_ISR_GIF6));
}

/**
  * @brief  获取通道7的全局中断标志。
  * @rmtoll ISR          GIF7          LL_DMA_IsActiveFlag_GI7
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_GI7(DMA_TypeDef *DMAx)
{
  /* 读取DMA中断状态寄存器(ISR)中的GIF7位 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_GIF7) == (DMA_ISR_GIF7));
}

/**
  * @brief  获取通道1的传输完成标志。
  * @rmtoll ISR          TCIF1         LL_DMA_IsActiveFlag_TC1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC1(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF1位，判断通道1是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF1) == (DMA_ISR_TCIF1));
}

/**
  * @brief  获取通道2的传输完成标志。
  * @rmtoll ISR          TCIF2         LL_DMA_IsActiveFlag_TC2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC2(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF2位，判断通道2是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF2) == (DMA_ISR_TCIF2));
}

/**
  * @brief  获取通道3的传输完成标志。
  * @rmtoll ISR          TCIF3         LL_DMA_IsActiveFlag_TC3
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC3(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF3位，判断通道3是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF3) == (DMA_ISR_TCIF3));
}

/**
  * @brief  获取通道4的传输完成标志。
  * @rmtoll ISR          TCIF4         LL_DMA_IsActiveFlag_TC4
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC4(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF4位，判断通道4是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF4) == (DMA_ISR_TCIF4));
}

/**
  * @brief  获取通道5的传输完成标志。
  * @rmtoll ISR          TCIF5         LL_DMA_IsActiveFlag_TC5
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC5(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF5位，判断通道5是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF5) == (DMA_ISR_TCIF5));
}

/**
  * @brief  获取通道6的传输完成标志。
  * @rmtoll ISR          TCIF6         LL_DMA_IsActiveFlag_TC6
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC6(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF6位，判断通道6是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF6) == (DMA_ISR_TCIF6));
}

/**
  * @brief  获取通道7的传输完成标志。
  * @rmtoll ISR          TCIF7         LL_DMA_IsActiveFlag_TC7
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TC7(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TCIF7位，判断通道7是否传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TCIF7) == (DMA_ISR_TCIF7));
}

/**
  * @brief  获取通道1的半传输完成标志。
  * @rmtoll ISR          HTIF1         LL_DMA_IsActiveFlag_HT1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT1(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF1位，判断通道1是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF1) == (DMA_ISR_HTIF1));
}

/**
  * @brief  获取通道2的半传输完成标志。
  * @rmtoll ISR          HTIF2         LL_DMA_IsActiveFlag_HT2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT2(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF2位，判断通道2是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF2) == (DMA_ISR_HTIF2));
}

/**
  * @brief  获取通道3的半传输完成标志。
  * @rmtoll ISR          HTIF3         LL_DMA_IsActiveFlag_HT3
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT3(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF3位，判断通道3是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF3) == (DMA_ISR_HTIF3));
}

/**
  * @brief  获取通道4的半传输完成标志。
  * @rmtoll ISR          HTIF4         LL_DMA_IsActiveFlag_HT4
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT4(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF4位，判断通道4是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF4) == (DMA_ISR_HTIF4));
}

/**
  * @brief  获取通道5的半传输完成标志。
  * @rmtoll ISR          HTIF5         LL_DMA_IsActiveFlag_HT5
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT5(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF5位，判断通道5是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF5) == (DMA_ISR_HTIF5));
}

/**
  * @brief  获取通道6的半传输完成标志。
  * @rmtoll ISR          HTIF6         LL_DMA_IsActiveFlag_HT6
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT6(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF6位，判断通道6是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF6) == (DMA_ISR_HTIF6));
}

/**
  * @brief  获取通道7的半传输完成标志。
  * @rmtoll ISR          HTIF7         LL_DMA_IsActiveFlag_HT7
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_HT7(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的HTIF7位，判断通道7是否半传输完成 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_HTIF7) == (DMA_ISR_HTIF7));
}

/**
  * @brief  获取通道1的传输错误标志。
  * @rmtoll ISR          TEIF1         LL_DMA_IsActiveFlag_TE1
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE1(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TEIF1位，判断通道1是否发生传输错误 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF1) == (DMA_ISR_TEIF1));
}

/**
  * @brief  获取通道2的传输错误标志。
  * @rmtoll ISR          TEIF2         LL_DMA_IsActiveFlag_TE2
  * @param  DMAx DMAx实例指针
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE2(DMA_TypeDef *DMAx)
{
  /* 读取ISR寄存器中的TEIF2位，判断通道2是否发生传输错误 */
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF2) == (DMA_ISR_TEIF2));
}
/**
  * @brief  获取通道3传输错误标志。
  * @rmtoll ISR          TEIF3         LL_DMA_IsActiveFlag_TE3
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE3(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道3的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF3) == (DMA_ISR_TEIF3));
}

/**
  * @brief  获取通道4传输错误标志。
  * @rmtoll ISR          TEIF4         LL_DMA_IsActiveFlag_TE4
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE4(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道4的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF4) == (DMA_ISR_TEIF4));
}

/**
  * @brief  获取通道5传输错误标志。
  * @rmtoll ISR          TEIF5         LL_DMA_IsActiveFlag_TE5
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE5(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道5的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF5) == (DMA_ISR_TEIF5));
}

/**
  * @brief  获取通道6传输错误标志。
  * @rmtoll ISR          TEIF6         LL_DMA_IsActiveFlag_TE6
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE6(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道6的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF6) == (DMA_ISR_TEIF6));
}

/**
  * @brief  获取通道7传输错误标志。
  * @rmtoll ISR          TEIF7         LL_DMA_IsActiveFlag_TE7
  * @param  DMAx DMAx 实例
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsActiveFlag_TE7(DMA_TypeDef *DMAx)
{
  // 读取ISR寄存器，判断通道7的传输错误中断标志位是否置位
  return (READ_BIT(DMAx->ISR, DMA_ISR_TEIF7) == (DMA_ISR_TEIF7));
}

/**
  * @brief  清除通道1全局中断标志。
  * @rmtoll IFCR         CGIF1         LL_DMA_ClearFlag_GI1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF1);
}

/**
  * @brief  清除通道2全局中断标志。
  * @rmtoll IFCR         CGIF2         LL_DMA_ClearFlag_GI2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF2);
}

/**
  * @brief  清除通道3全局中断标志。
  * @rmtoll IFCR         CGIF3         LL_DMA_ClearFlag_GI3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF3);
}

/**
  * @brief  清除通道4全局中断标志。
  * @rmtoll IFCR         CGIF4         LL_DMA_ClearFlag_GI4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF4);
}

/**
  * @brief  清除通道5全局中断标志。
  * @rmtoll IFCR         CGIF5         LL_DMA_ClearFlag_GI5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF5);
}

/**
  * @brief  清除通道6全局中断标志。
  * @rmtoll IFCR         CGIF6         LL_DMA_ClearFlag_GI6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF6);
}

/**
  * @brief  清除通道7全局中断标志。
  * @rmtoll IFCR         CGIF7         LL_DMA_ClearFlag_GI7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_GI7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的全局中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CGIF7);
}

/**
  * @brief  清除通道1传输完成标志。
  * @rmtoll IFCR         CTCIF1        LL_DMA_ClearFlag_TC1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF1);
}

/**
  * @brief  清除通道2传输完成标志。
  * @rmtoll IFCR         CTCIF2        LL_DMA_ClearFlag_TC2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF2);
}

/**
  * @brief  清除通道3传输完成标志。
  * @rmtoll IFCR         CTCIF3        LL_DMA_ClearFlag_TC3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF3);
}

/**
  * @brief  清除通道4传输完成标志。
  * @rmtoll IFCR         CTCIF4        LL_DMA_ClearFlag_TC4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF4);
}

/**
  * @brief  清除通道5传输完成标志。
  * @rmtoll IFCR         CTCIF5        LL_DMA_ClearFlag_TC5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF5);
}

/**
  * @brief  清除通道6传输完成标志。
  * @rmtoll IFCR         CTCIF6        LL_DMA_ClearFlag_TC6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF6);
}

/**
  * @brief  清除通道7传输完成标志。
  * @rmtoll IFCR         CTCIF7        LL_DMA_ClearFlag_TC7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TC7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的传输完成中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTCIF7);
}

/**
  * @brief  清除通道1半传输标志。
  * @rmtoll IFCR         CHTIF1        LL_DMA_ClearFlag_HT1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF1);
}

/**
  * @brief  清除通道2半传输标志。
  * @rmtoll IFCR         CHTIF2        LL_DMA_ClearFlag_HT2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF2);
}

/**
  * @brief  清除通道3半传输标志。
  * @rmtoll IFCR         CHTIF3        LL_DMA_ClearFlag_HT3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF3);
}

/**
  * @brief  清除通道4半传输标志。
  * @rmtoll IFCR         CHTIF4        LL_DMA_ClearFlag_HT4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF4);
}

/**
  * @brief  清除通道5半传输标志。
  * @rmtoll IFCR         CHTIF5        LL_DMA_ClearFlag_HT5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF5);
}

/**
  * @brief  清除通道6半传输标志。
  * @rmtoll IFCR         CHTIF6        LL_DMA_ClearFlag_HT6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF6);
}

/**
  * @brief  清除通道7半传输标志。
  * @rmtoll IFCR         CHTIF7        LL_DMA_ClearFlag_HT7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_HT7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的半传输中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CHTIF7);
}

/**
  * @brief  清除通道1传输错误标志。
  * @rmtoll IFCR         CTEIF1        LL_DMA_ClearFlag_TE1
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE1(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道1的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF1);
}

/**
  * @brief  清除通道2传输错误标志。
  * @rmtoll IFCR         CTEIF2        LL_DMA_ClearFlag_TE2
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE2(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道2的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF2);
}

/**
  * @brief  清除通道3传输错误标志。
  * @rmtoll IFCR         CTEIF3        LL_DMA_ClearFlag_TE3
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE3(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道3的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF3);
}

/**
  * @brief  清除通道4传输错误标志。
  * @rmtoll IFCR         CTEIF4        LL_DMA_ClearFlag_TE4
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE4(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道4的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF4);
}

/**
  * @brief  清除通道5传输错误标志。
  * @rmtoll IFCR         CTEIF5        LL_DMA_ClearFlag_TE5
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE5(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道5的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF5);
}

/**
  * @brief  清除通道6传输错误标志。
  * @rmtoll IFCR         CTEIF6        LL_DMA_ClearFlag_TE6
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE6(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道6的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF6);
}

/**
  * @brief  清除通道7传输错误标志。
  * @rmtoll IFCR         CTEIF7        LL_DMA_ClearFlag_TE7
  * @param  DMAx DMAx 实例
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_ClearFlag_TE7(DMA_TypeDef *DMAx)
{
  // 向IFCR寄存器写1，清除通道7的传输错误中断标志
  WRITE_REG(DMAx->IFCR, DMA_IFCR_CTEIF7);
}

/**
  * @}
  */

/** @defgroup DMA_LL_EF_IT_Management IT_Management
  * @{
  */

/**
  * @brief  使能传输完成中断。
  * @rmtoll CCR          TCIE          LL_DMA_EnableIT_TC
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并设置CCR寄存器中的TCIE位（传输完成中断使能）
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TCIE);
}

/**
  * @brief  使能半传输中断。
  * @rmtoll CCR          HTIE          LL_DMA_EnableIT_HT
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并设置CCR寄存器中的HTIE位（半传输中断使能）
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_HTIE);
}

/**
  * @brief  使能传输错误中断。
  * @rmtoll CCR          TEIE          LL_DMA_EnableIT_TE
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_EnableIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并设置CCR寄存器中的TEIE位（传输错误中断使能）
  SET_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TEIE);
}

/**
  * @brief  禁用传输完成中断。
  * @rmtoll CCR          TCIE          LL_DMA_DisableIT_TC
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并清除CCR寄存器中的TCIE位（传输完成中断使能）
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TCIE);
}

/**
  * @brief  禁用半传输中断。
  * @rmtoll CCR          HTIE          LL_DMA_DisableIT_HT
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并清除CCR寄存器中的HTIE位（半传输中断使能）
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_HTIE);
}

/**
  * @brief  禁用传输错误中断。
  * @rmtoll CCR          TEIE          LL_DMA_DisableIT_TE
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 无
  */
__STATIC_INLINE void LL_DMA_DisableIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 计算通道寄存器地址，并清除CCR寄存器中的TEIE位（传输错误中断使能）
  CLEAR_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR, DMA_CCR_TEIE);
}

/**
  * @brief  检查传输完成中断是否使能。
  * @rmtoll CCR          TCIE          LL_DMA_IsEnabledIT_TC
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TC(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 读取CCR寄存器，判断传输完成中断使能位是否置位
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_TCIE) == (DMA_CCR_TCIE));
}

/**
  * @brief  检查半传输中断是否使能。
  * @rmtoll CCR          HTIE          LL_DMA_IsEnabledIT_HT
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_HT(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 读取CCR寄存器，判断半传输中断使能位是否置位
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_HTIE) == (DMA_CCR_HTIE));
}

/**
  * @brief  检查传输错误中断是否使能。
  * @rmtoll CCR          TEIE          LL_DMA_IsEnabledIT_TE
  * @param  DMAx DMAx 实例
  * @param  Channel 此参数可以是以下值之一:
  *         @arg @ref LL_DMA_CHANNEL_1
  *         @arg @ref LL_DMA_CHANNEL_2
  *         @arg @ref LL_DMA_CHANNEL_3
  *         @arg @ref LL_DMA_CHANNEL_4
  *         @arg @ref LL_DMA_CHANNEL_5
  *         @arg @ref LL_DMA_CHANNEL_6
  *         @arg @ref LL_DMA_CHANNEL_7
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_DMA_IsEnabledIT_TE(DMA_TypeDef *DMAx, uint32_t Channel)
{
  // 读取CCR寄存器，判断传输错误中断使能位是否置位
  return (READ_BIT(((DMA_Channel_TypeDef *)((uint32_t)((uint32_t)DMAx + CHANNEL_OFFSET_TAB[Channel - 1U])))->CCR,
                   DMA_CCR_TEIE) == (DMA_CCR_TEIE));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_EF_Init Initialization and de-initialization functions
  * @{
  */
// 函数声明：DMA初始化函数
uint32_t LL_DMA_Init(DMA_TypeDef *DMAx, uint32_t Channel, LL_DMA_InitTypeDef *DMA_InitStruct);
// 函数声明：DMA反初始化函数（恢复默认状态）
uint32_t LL_DMA_DeInit(DMA_TypeDef *DMAx, uint32_t Channel);
// 函数声明：DMA结构体参数默认值设置函数
void LL_DMA_StructInit(LL_DMA_InitTypeDef *DMA_InitStruct);

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* DMA1 || DMA2 */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_LL_DMA_H */
