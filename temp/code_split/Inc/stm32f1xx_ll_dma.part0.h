/**
  ******************************************************************************
  * @file    stm32f1xx_ll_dma.h
  * @author  MCD Application Team
  * @brief   Header file of DMA LL module.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_LL_DMA_H
#define __STM32F1xx_LL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined (DMA1) || defined (DMA2)

/** @defgroup DMA_LL DMA
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup DMA_LL_Private_Variables DMA Private Variables
  * @{
  */
/* Array used to get the DMA channel register offset versus channel index LL_DMA_CHANNEL_x */
static const uint8_t CHANNEL_OFFSET_TAB[] =
{
  (uint8_t)(DMA1_Channel1_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel2_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel3_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel4_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel5_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel6_BASE - DMA1_BASE),
  (uint8_t)(DMA1_Channel7_BASE - DMA1_BASE)
};
/**
  * @}
  */
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_Private_Macros DMA Private Macros
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup DMA_LL_ES_INIT DMA Exported Init structure
  * @{
  */
typedef struct
{
  uint32_t PeriphOrM2MSrcAddress;  /*!< Specifies the peripheral base address for DMA transfer
                                        or as Source base address in case of memory to memory transfer direction.

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t MemoryOrM2MDstAddress;  /*!< Specifies the memory base address for DMA transfer
                                        or as Destination base address in case of memory to memory transfer direction.

                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0xFFFFFFFF. */

  uint32_t Direction;              /*!< Specifies if the data will be transferred from memory to peripheral,
                                        from memory to memory or from peripheral to memory.
                                        This parameter can be a value of @ref DMA_LL_EC_DIRECTION

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetDataTransferDirection(). */

  uint32_t Mode;                   /*!< Specifies the normal or circular operation mode.
                                        This parameter can be a value of @ref DMA_LL_EC_MODE
                                        @note: The circular buffer mode cannot be used if the memory to memory
                                               data transfer direction is configured on the selected Channel

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetMode(). */

  uint32_t PeriphOrM2MSrcIncMode;  /*!< Specifies whether the Peripheral address or Source address in case of memory to memory transfer direction
                                        is incremented or not.
                                        This parameter can be a value of @ref DMA_LL_EC_PERIPH

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetPeriphIncMode(). */

  uint32_t MemoryOrM2MDstIncMode;  /*!< Specifies whether the Memory address or Destination address in case of memory to memory transfer direction
                                        is incremented or not.
                                        This parameter can be a value of @ref DMA_LL_EC_MEMORY

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetMemoryIncMode(). */

  uint32_t PeriphOrM2MSrcDataSize; /*!< Specifies the Peripheral data size alignment or Source data size alignment (byte, half word, word)
                                        in case of memory to memory transfer direction.
                                        This parameter can be a value of @ref DMA_LL_EC_PDATAALIGN

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetPeriphSize(). */

  uint32_t MemoryOrM2MDstDataSize; /*!< Specifies the Memory data size alignment or Destination data size alignment (byte, half word, word)
                                        in case of memory to memory transfer direction.
                                        This parameter can be a value of @ref DMA_LL_EC_MDATAALIGN

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetMemorySize(). */

  uint32_t NbData;                 /*!< Specifies the number of data to transfer, in data unit.
                                        The data unit is equal to the source buffer configuration set in PeripheralSize
                                        or MemorySize parameters depending in the transfer direction.
                                        This parameter must be a value between Min_Data = 0 and Max_Data = 0x0000FFFF

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetDataLength(). */

  uint32_t Priority;               /*!< Specifies the channel priority level.
                                        This parameter can be a value of @ref DMA_LL_EC_PRIORITY

                                        This feature can be modified afterwards using unitary function @ref LL_DMA_SetChannelPriorityLevel(). */

} LL_DMA_InitTypeDef;
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported constants --------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Constants DMA Exported Constants
  * @{
  */
/** @defgroup DMA_LL_EC_CLEAR_FLAG Clear Flags Defines
  * @brief    Flags defines which can be used with LL_DMA_WriteReg function
  * @{
  */
#define LL_DMA_IFCR_CGIF1                 DMA_IFCR_CGIF1        /*!< Channel 1 global flag            */
#define LL_DMA_IFCR_CTCIF1                DMA_IFCR_CTCIF1       /*!< Channel 1 transfer complete flag */
#define LL_DMA_IFCR_CHTIF1                DMA_IFCR_CHTIF1       /*!< Channel 1 half transfer flag     */
#define LL_DMA_IFCR_CTEIF1                DMA_IFCR_CTEIF1       /*!< Channel 1 transfer error flag    */
#define LL_DMA_IFCR_CGIF2                 DMA_IFCR_CGIF2        /*!< Channel 2 global flag            */
#define LL_DMA_IFCR_CTCIF2                DMA_IFCR_CTCIF2       /*!< Channel 2 transfer complete flag */
#define LL_DMA_IFCR_CHTIF2                DMA_IFCR_CHTIF2       /*!< Channel 2 half transfer flag     */
#define LL_DMA_IFCR_CTEIF2                DMA_IFCR_CTEIF2       /*!< Channel 2 transfer error flag    */
#define LL_DMA_IFCR_CGIF3                 DMA_IFCR_CGIF3        /*!< Channel 3 global flag            */
#define LL_DMA_IFCR_CTCIF3                DMA_IFCR_CTCIF3       /*!< Channel 3 transfer complete flag */
#define LL_DMA_IFCR_CHTIF3                DMA_IFCR_CHTIF3       /*!< Channel 3 half transfer flag     */
#define LL_DMA_IFCR_CTEIF3                DMA_IFCR_CTEIF3       /*!< Channel 3 transfer error flag    */
#define LL_DMA_IFCR_CGIF4                 DMA_IFCR_CGIF4        /*!< Channel 4 global flag            */
#define LL_DMA_IFCR_CTCIF4                DMA_IFCR_CTCIF4       /*!< Channel 4 transfer complete flag */
#define LL_DMA_IFCR_CHTIF4                DMA_IFCR_CHTIF4       /*!< Channel 4 half transfer flag     */
#define LL_DMA_IFCR_CTEIF4                DMA_IFCR_CTEIF4       /*!< Channel 4 transfer error flag    */
#define LL_DMA_IFCR_CGIF5                 DMA_IFCR_CGIF5        /*!< Channel 5 global flag            */
#define LL_DMA_IFCR_CTCIF5                DMA_IFCR_CTCIF5       /*!< Channel 5 transfer complete flag */
#define LL_DMA_IFCR_CHTIF5                DMA_IFCR_CHTIF5       /*!< Channel 5 half transfer flag     */
#define LL_DMA_IFCR_CTEIF5                DMA_IFCR_CTEIF5       /*!< Channel 5 transfer error flag    */
#define LL_DMA_IFCR_CGIF6                 DMA_IFCR_CGIF6        /*!< Channel 6 global flag            */
#define LL_DMA_IFCR_CTCIF6                DMA_IFCR_CTCIF6       /*!< Channel 6 transfer complete flag */
#define LL_DMA_IFCR_CHTIF6                DMA_IFCR_CHTIF6       /*!< Channel 6 half transfer flag     */
#define LL_DMA_IFCR_CTEIF6                DMA_IFCR_CTEIF6       /*!< Channel 6 transfer error flag    */
#define LL_DMA_IFCR_CGIF7                 DMA_IFCR_CGIF7        /*!< Channel 7 global flag            */
#define LL_DMA_IFCR_CTCIF7                DMA_IFCR_CTCIF7       /*!< Channel 7 transfer complete flag */
#define LL_DMA_IFCR_CHTIF7                DMA_IFCR_CHTIF7       /*!< Channel 7 half transfer flag     */
#define LL_DMA_IFCR_CTEIF7                DMA_IFCR_CTEIF7       /*!< Channel 7 transfer error flag    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_GET_FLAG Get Flags Defines
  * @brief    Flags defines which can be used with LL_DMA_ReadReg function
  * @{
  */
#define LL_DMA_ISR_GIF1                   DMA_ISR_GIF1          /*!< Channel 1 global flag            */
#define LL_DMA_ISR_TCIF1                  DMA_ISR_TCIF1         /*!< Channel 1 transfer complete flag */
#define LL_DMA_ISR_HTIF1                  DMA_ISR_HTIF1         /*!< Channel 1 half transfer flag     */
#define LL_DMA_ISR_TEIF1                  DMA_ISR_TEIF1         /*!< Channel 1 transfer error flag    */
#define LL_DMA_ISR_GIF2                   DMA_ISR_GIF2          /*!< Channel 2 global flag            */
#define LL_DMA_ISR_TCIF2                  DMA_ISR_TCIF2         /*!< Channel 2 transfer complete flag */
#define LL_DMA_ISR_HTIF2                  DMA_ISR_HTIF2         /*!< Channel 2 half transfer flag     */
#define LL_DMA_ISR_TEIF2                  DMA_ISR_TEIF2         /*!< Channel 2 transfer error flag    */
#define LL_DMA_ISR_GIF3                   DMA_ISR_GIF3          /*!< Channel 3 global flag            */
#define LL_DMA_ISR_TCIF3                  DMA_ISR_TCIF3         /*!< Channel 3 transfer complete flag */
#define LL_DMA_ISR_HTIF3                  DMA_ISR_HTIF3         /*!< Channel 3 half transfer flag     */
#define LL_DMA_ISR_TEIF3                  DMA_ISR_TEIF3         /*!< Channel 3 transfer error flag    */
#define LL_DMA_ISR_GIF4                   DMA_ISR_GIF4          /*!< Channel 4 global flag            */
#define LL_DMA_ISR_TCIF4                  DMA_ISR_TCIF4         /*!< Channel 4 transfer complete flag */
#define LL_DMA_ISR_HTIF4                  DMA_ISR_HTIF4         /*!< Channel 4 half transfer flag     */
#define LL_DMA_ISR_TEIF4                  DMA_ISR_TEIF4         /*!< Channel 4 transfer error flag    */
#define LL_DMA_ISR_GIF5                   DMA_ISR_GIF5          /*!< Channel 5 global flag            */
#define LL_DMA_ISR_TCIF5                  DMA_ISR_TCIF5         /*!< Channel 5 transfer complete flag */
#define LL_DMA_ISR_HTIF5                  DMA_ISR_HTIF5         /*!< Channel 5 half transfer flag     */
#define LL_DMA_ISR_TEIF5                  DMA_ISR_TEIF5         /*!< Channel 5 transfer error flag    */
#define LL_DMA_ISR_GIF6                   DMA_ISR_GIF6          /*!< Channel 6 global flag            */
#define LL_DMA_ISR_TCIF6                  DMA_ISR_TCIF6         /*!< Channel 6 transfer complete flag */
#define LL_DMA_ISR_HTIF6                  DMA_ISR_HTIF6         /*!< Channel 6 half transfer flag     */
#define LL_DMA_ISR_TEIF6                  DMA_ISR_TEIF6         /*!< Channel 6 transfer error flag    */
#define LL_DMA_ISR_GIF7                   DMA_ISR_GIF7          /*!< Channel 7 global flag            */
#define LL_DMA_ISR_TCIF7                  DMA_ISR_TCIF7         /*!< Channel 7 transfer complete flag */
#define LL_DMA_ISR_HTIF7                  DMA_ISR_HTIF7         /*!< Channel 7 half transfer flag     */
#define LL_DMA_ISR_TEIF7                  DMA_ISR_TEIF7         /*!< Channel 7 transfer error flag    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_IT IT Defines
  * @brief    IT defines which can be used with LL_DMA_ReadReg and  LL_DMA_WriteReg functions
  * @{
  */
#define LL_DMA_CCR_TCIE                   DMA_CCR_TCIE          /*!< Transfer complete interrupt */
#define LL_DMA_CCR_HTIE                   DMA_CCR_HTIE          /*!< Half Transfer interrupt     */
#define LL_DMA_CCR_TEIE                   DMA_CCR_TEIE          /*!< Transfer error interrupt    */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_CHANNEL CHANNEL
  * @{
  */
#define LL_DMA_CHANNEL_1                  0x00000001U /*!< DMA Channel 1 */
#define LL_DMA_CHANNEL_2                  0x00000002U /*!< DMA Channel 2 */
#define LL_DMA_CHANNEL_3                  0x00000003U /*!< DMA Channel 3 */
#define LL_DMA_CHANNEL_4                  0x00000004U /*!< DMA Channel 4 */
#define LL_DMA_CHANNEL_5                  0x00000005U /*!< DMA Channel 5 */
#define LL_DMA_CHANNEL_6                  0x00000006U /*!< DMA Channel 6 */
#define LL_DMA_CHANNEL_7                  0x00000007U /*!< DMA Channel 7 */
#if defined(USE_FULL_LL_DRIVER)
#define LL_DMA_CHANNEL_ALL                0xFFFF0000U /*!< DMA Channel all (used only for function @ref LL_DMA_DeInit(). */
#endif /*USE_FULL_LL_DRIVER*/
/**
  * @}
  */

/** @defgroup DMA_LL_EC_DIRECTION Transfer Direction
  * @{
  */
#define LL_DMA_DIRECTION_PERIPH_TO_MEMORY 0x00000000U             /*!< Peripheral to memory direction */
#define LL_DMA_DIRECTION_MEMORY_TO_PERIPH DMA_CCR_DIR             /*!< Memory to peripheral direction */
#define LL_DMA_DIRECTION_MEMORY_TO_MEMORY DMA_CCR_MEM2MEM         /*!< Memory to memory direction     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MODE Transfer mode
  * @{
  */
#define LL_DMA_MODE_NORMAL                0x00000000U             /*!< Normal Mode                  */
#define LL_DMA_MODE_CIRCULAR              DMA_CCR_CIRC            /*!< Circular Mode                */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_PERIPH Peripheral increment mode
  * @{
  */
#define LL_DMA_PERIPH_INCREMENT           DMA_CCR_PINC            /*!< Peripheral increment mode Enable */
#define LL_DMA_PERIPH_NOINCREMENT         0x00000000U             /*!< Peripheral increment mode Disable */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MEMORY Memory increment mode
  * @{
  */
#define LL_DMA_MEMORY_INCREMENT           DMA_CCR_MINC            /*!< Memory increment mode Enable  */
#define LL_DMA_MEMORY_NOINCREMENT         0x00000000U             /*!< Memory increment mode Disable */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_PDATAALIGN Peripheral data alignment
  * @{
  */
#define LL_DMA_PDATAALIGN_BYTE            0x00000000U             /*!< Peripheral data alignment : Byte     */
#define LL_DMA_PDATAALIGN_HALFWORD        DMA_CCR_PSIZE_0         /*!< Peripheral data alignment : HalfWord */
#define LL_DMA_PDATAALIGN_WORD            DMA_CCR_PSIZE_1         /*!< Peripheral data alignment : Word     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_MDATAALIGN Memory data alignment
  * @{
  */
#define LL_DMA_MDATAALIGN_BYTE            0x00000000U             /*!< Memory data alignment : Byte     */
#define LL_DMA_MDATAALIGN_HALFWORD        DMA_CCR_MSIZE_0         /*!< Memory data alignment : HalfWord */
#define LL_DMA_MDATAALIGN_WORD            DMA_CCR_MSIZE_1         /*!< Memory data alignment : Word     */
/**
  * @}
  */

/** @defgroup DMA_LL_EC_PRIORITY Transfer Priority level
  * @{
  */
#define LL_DMA_PRIORITY_LOW               0x00000000U             /*!< Priority level : Low       */
#define LL_DMA_PRIORITY_MEDIUM            DMA_CCR_PL_0            /*!< Priority level : Medium    */
#define LL_DMA_PRIORITY_HIGH              DMA_CCR_PL_1            /*!< Priority level : High      */
#define LL_DMA_PRIORITY_VERYHIGH          DMA_CCR_PL              /*!< Priority level : Very_High */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup DMA_LL_Exported_Macros DMA Exported Macros
  * @{
  */

/** @defgroup DMA_LL_EM_WRITE_READ Common Write and read registers macros
  * @{
  */
/**
  * @brief  Write a value in DMA register
  * @param  __INSTANCE__ DMA Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_DMA_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in DMA register
  * @param  __INSTANCE__ DMA Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_DMA_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/** @defgroup DMA_LL_EM_CONVERT_DMAxCHANNELy Convert DMAxChannely
  * @{
  */

/**
  * @brief  Convert DMAx_Channely into DMAx
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval DMAx
  */
#if defined(DMA2)
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) > ((uint32_t)DMA1_Channel7)) ?  DMA2 : DMA1)
#else
#define __LL_DMA_GET_INSTANCE(__CHANNEL_INSTANCE__)  (DMA1)
#endif

/**
  * @brief  Convert DMAx_Channely into LL_DMA_CHANNEL_y
  * @param  __CHANNEL_INSTANCE__ DMAx_Channely
  * @retval LL_DMA_CHANNEL_y
  */
#if defined (DMA2)
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
#define __LL_DMA_GET_CHANNEL(__CHANNEL_INSTANCE__)   \
(((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel1)) ? LL_DMA_CHANNEL_1 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel2)) ? LL_DMA_CHANNEL_2 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel3)) ? LL_DMA_CHANNEL_3 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel4)) ? LL_DMA_CHANNEL_4 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel5)) ? LL_DMA_CHANNEL_5 : \
 ((uint32_t)(__CHANNEL_INSTANCE__) == ((uint32_t)DMA1_Channel6)) ? LL_DMA_CHANNEL_6 : \
 LL_DMA_CHANNEL_7)
#endif
