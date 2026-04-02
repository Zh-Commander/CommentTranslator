/**
  ******************************************************************************
  * @file    stm32f1xx_hal_dma.h
  * @author  MCD Application Team
  * @brief   Header file of DMA HAL module.
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
#ifndef __STM32F1xx_HAL_DMA_H
#define __STM32F1xx_HAL_DMA_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup DMA
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/

/** @defgroup DMA_Exported_Types DMA Exported Types
  * @{
  */

/**
  * @brief  DMA 配置结构体定义
  */
typedef struct
{
  uint32_t Direction;                 /*!< 指定数据传输方向：从内存到外设、内存到内存或从外设到内存。
                                           此参数可以是 @ref DMA_Data_transfer_direction 中的值 */

  uint32_t PeriphInc;                 /*!< 指定外设地址寄存器是否自增。
                                           此参数可以是 @ref DMA_Peripheral_incremented_mode 中的值 */

  uint32_t MemInc;                    /*!< 指定内存地址寄存器是否自增。
                                           此参数可以是 @ref DMA_Memory_incremented_mode 中的值 */

  uint32_t PeriphDataAlignment;       /*!< 指定外设数据宽度（字节/半字/字）。
                                           此参数可以是 @ref DMA_Peripheral_data_size 中的值 */

  uint32_t MemDataAlignment;          /*!< 指定内存数据宽度（字节/半字/字）。
                                           此参数可以是 @ref DMA_Memory_data_size 中的值 */

  uint32_t Mode;                      /*!< 指定 DMAy Channelx 的操作模式（正常模式或循环模式）。
                                           此参数可以是 @ref DMA_mode 中的值
                                           @note 如果配置了内存到内存传输，则不能使用循环缓冲模式 */

  uint32_t Priority;                  /*!< 指定 DMAy Channelx 的软件优先级。
                                           此参数可以是 @ref DMA_Priority_level 中的值 */
} DMA_InitTypeDef;

/**
  * @brief  HAL DMA 状态结构体定义
  */
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA 未初始化或已禁用    */
  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA 已初始化并准备使用      */
  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA 正在进行数据传输                 */
  HAL_DMA_STATE_TIMEOUT           = 0x03U   /*!< DMA 超时状态                      */
}HAL_DMA_StateTypeDef;

/**
  * @brief  HAL DMA 传输完成级别定义（用于查询传输状态）
  */
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,    /*!< 全部传输完成     */
  HAL_DMA_HALF_TRANSFER           = 0x01U     /*!< 半传输完成     */
}HAL_DMA_LevelCompleteTypeDef;

/** 
  * @brief  HAL DMA 回调函数 ID 结构体定义
  */
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,    /*!< 传输完成回调     */
  HAL_DMA_XFER_HALFCPLT_CB_ID      = 0x01U,    /*!< 半传输完成回调     */
  HAL_DMA_XFER_ERROR_CB_ID         = 0x02U,    /*!< 传输错误回调             */ 
  HAL_DMA_XFER_ABORT_CB_ID         = 0x03U,    /*!< 传输中止回调             */ 
  HAL_DMA_XFER_ALL_CB_ID           = 0x04U     /*!< 所有回调               */ 
    
}HAL_DMA_CallbackIDTypeDef;

/** 
  * @brief  DMA 句柄结构体定义
  */
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef        *Instance;                                                    /*!< 寄存器基地址                  */
  
  DMA_InitTypeDef            Init;                                                         /*!< DMA 通信参数配置           */
  
  HAL_LockTypeDef            Lock;                                                         /*!< DMA 锁对象（用于资源管理）                     */
  
  __IO HAL_DMA_StateTypeDef  State;                                                        /*!< DMA 传输状态                     */
  
  void                       *Parent;                                                      /*!< 父对象状态（通常指向上层外设句柄，如UART句柄）                    */
  
  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);     /*!< DMA 传输完成回调函数         */
  
  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma); /*!< DMA 半传输完成回调函数    */
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA 传输错误回调函数            */

  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);    /*!< DMA 传输中止回调函数            */
  
  __IO uint32_t              ErrorCode;                                                    /*!< DMA 错误代码                         */

  DMA_TypeDef                *DmaBaseAddress;                                             /*!< DMA 通道基地址（指向 DMA1 或 DMA2）               */
  
  uint32_t                   ChannelIndex;                                                /*!< DMA 通道索引（0-6 用于 DMA1，0-5 用于 DMA2）                      */

} DMA_HandleTypeDef;    
/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/

/** @defgroup DMA_Exported_Constants DMA Exported Constants
  * @{
  */

/** @defgroup DMA_Error_Code DMA Error Code
  * @{
  */
#define HAL_DMA_ERROR_NONE                     0x00000000U    /*!< 无错误             */
#define HAL_DMA_ERROR_TE                       0x00000001U    /*!< 传输错误       */
#define HAL_DMA_ERROR_NO_XFER                  0x00000004U    /*!< 无正在进行的传输  */
#define HAL_DMA_ERROR_TIMEOUT                  0x00000020U    /*!< 超时错误        */
#define HAL_DMA_ERROR_NOT_SUPPORTED            0x00000100U    /*!< 不支持的模式                    */ 
/**
  * @}
  */

/** @defgroup DMA_Data_transfer_direction DMA Data transfer direction
  * @{
  */
#define DMA_PERIPH_TO_MEMORY         0x00000000U                 /*!< 外设到内存方向 */
#define DMA_MEMORY_TO_PERIPH         ((uint32_t)DMA_CCR_DIR)     /*!< 内存到外设方向 */
#define DMA_MEMORY_TO_MEMORY         ((uint32_t)DMA_CCR_MEM2MEM) /*!< 内存到内存方向     */

/**
  * @}
  */

/** @defgroup DMA_Peripheral_incremented_mode DMA Peripheral incremented mode
  * @{
  */
#define DMA_PINC_ENABLE        ((uint32_t)DMA_CCR_PINC)  /*!< 外设地址自增模式使能 */
#define DMA_PINC_DISABLE       0x00000000U               /*!< 外设地址自增模式禁用 */
/**
  * @}
  */

/** @defgroup DMA_Memory_incremented_mode DMA Memory incremented mode
  * @{
  */
#define DMA_MINC_ENABLE         ((uint32_t)DMA_CCR_MINC)  /*!< 内存地址自增模式使能  */
#define DMA_MINC_DISABLE        0x00000000U               /*!< 内存地址自增模式禁用 */
/**
  * @}
  */

/** @defgroup DMA_Peripheral_data_size DMA Peripheral data size
  * @{
  */
#define DMA_PDATAALIGN_BYTE          0x00000000U                  /*!< 外设数据宽度：字节     */
#define DMA_PDATAALIGN_HALFWORD      ((uint32_t)DMA_CCR_PSIZE_0)  /*!< 外设数据宽度：半字 */
#define DMA_PDATAALIGN_WORD          ((uint32_t)DMA_CCR_PSIZE_1)  /*!< 外设数据宽度：字     */
/**
  * @}
  */

/** @defgroup DMA_Memory_data_size DMA Memory data size
  * @{
  */
#define DMA_MDATAALIGN_BYTE          0x00000000U                  /*!< 内存数据宽度：字节     */
#define DMA_MDATAALIGN_HALFWORD      ((uint32_t)DMA_CCR_MSIZE_0)  /*!< 内存数据宽度：半字 */
#define DMA_MDATAALIGN_WORD          ((uint32_t)DMA_CCR_MSIZE_1)  /*!< 内存数据宽度：字     */
/**
  * @}
  */

/** @defgroup DMA_mode DMA mode
  * @{
  */
#define DMA_NORMAL         0x00000000U                  /*!< 正常模式                  */
#define DMA_CIRCULAR       ((uint32_t)DMA_CCR_CIRC)     /*!< 循环模式                */
/**
  * @}
  */

/** @defgroup DMA_Priority_level DMA Priority level
  * @{
  */
#define DMA_PRIORITY_LOW             0x00000000U               /*!< 优先级：低       */
#define DMA_PRIORITY_MEDIUM          ((uint32_t)DMA_CCR_PL_0)  /*!< 优先级：中    */
#define DMA_PRIORITY_HIGH            ((uint32_t)DMA_CCR_PL_1)  /*!< 优先级：高      */
#define DMA_PRIORITY_VERY_HIGH       ((uint32_t)DMA_CCR_PL)    /*!< 优先级：极高 */
/**
  * @}
  */


/** @defgroup DMA_interrupt_enable_definitions DMA interrupt enable definitions
  * @{
  */
// 传输完成中断使能
#define DMA_IT_TC                         ((uint32_t)DMA_CCR_TCIE)
// 半传输完成中断使能
#define DMA_IT_HT                         ((uint32_t)DMA_CCR_HTIE)
// 传输错误中断使能
#define DMA_IT_TE                         ((uint32_t)DMA_CCR_TEIE)
/**
  * @}
  */

/** @defgroup DMA_flag_definitions DMA flag definitions
  * @{
  */
// 以下定义了 DMA1 各通道的标志位
// GL: 全局标志, TC: 传输完成, HT: 半传输, TE: 传输错误
// 数字后缀对应通道号 (1-7)
#define DMA_FLAG_GL1                      0x00000001U // 通道1全局标志
#define DMA_FLAG_TC1                      0x00000002U // 通道1传输完成标志
#define DMA_FLAG_HT1                      0x00000004U // 通道1半传输标志
#define DMA_FLAG_TE1                      0x00000008U // 通道1传输错误标志
#define DMA_FLAG_GL2                      0x00000010U
#define DMA_FLAG_TC2                      0x00000020U
#define DMA_FLAG_HT2                      0x00000040U
#define DMA_FLAG_TE2                      0x00000080U
#define DMA_FLAG_GL3                      0x00000100U
#define DMA_FLAG_TC3                      0x00000200U
#define DMA_FLAG_HT3                      0x00000400U
#define DMA_FLAG_TE3                      0x00000800U
#define DMA_FLAG_GL4                      0x00001000U
#define DMA_FLAG_TC4                      0x00002000U
#define DMA_FLAG_HT4                      0x00004000U
#define DMA_FLAG_TE4                      0x00008000U
#define DMA_FLAG_GL5                      0x00010000U
#define DMA_FLAG_TC5                      0x00020000U
#define DMA_FLAG_HT5                      0x00040000U
#define DMA_FLAG_TE5                      0x00080000U
#define DMA_FLAG_GL6                      0x00100000U
#define DMA_FLAG_TC6                      0x00200000U
#define DMA_FLAG_HT6                      0x00400000U
#define DMA_FLAG_TE6                      0x00800000U
#define DMA_FLAG_GL7                      0x01000000U
#define DMA_FLAG_TC7                      0x02000000U
#define DMA_FLAG_HT7                      0x04000000U
#define DMA_FLAG_TE7                      0x08000000U
/**
  * @}
  */

/**
  * @}
  */


/* 导出宏 -----------------------------------------------------------*/
/** @defgroup DMA_Exported_Macros DMA Exported Macros
  * @{
  */

/** @brief  复位 DMA 句柄状态。
  * @param  __HANDLE__: DMA 句柄
  * @retval 无
  */
#define __HAL_DMA_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DMA_STATE_RESET)

/**
  * @brief  使能指定的 DMA 通道。
  * @param  __HANDLE__: DMA 句柄
  * @retval 无
  */
#define __HAL_DMA_ENABLE(__HANDLE__)        (SET_BIT((__HANDLE__)->Instance->CCR, DMA_CCR_EN))

/**
  * @brief  禁用指定的 DMA 通道。
  * @param  __HANDLE__: DMA 句柄
  * @retval 无
  */
#define __HAL_DMA_DISABLE(__HANDLE__)       (CLEAR_BIT((__HANDLE__)->Instance->CCR, DMA_CCR_EN))


/* 中断与标志管理 */

/**
  * @brief  使能指定的 DMA 通道中断。
  * @param  __HANDLE__: DMA 句柄
  * @param __INTERRUPT__: 指定要使能的 DMA 中断源。
  *          此参数可以是以下值的任意组合：
  *            @arg DMA_IT_TC:  传输完成中断掩码
  *            @arg DMA_IT_HT:  半传输完成中断掩码
  *            @arg DMA_IT_TE:  传输错误中断掩码
  * @retval 无
  */
#define __HAL_DMA_ENABLE_IT(__HANDLE__, __INTERRUPT__)   (SET_BIT((__HANDLE__)->Instance->CCR, (__INTERRUPT__)))

/**
  * @brief  禁用指定的 DMA 通道中断。
  * @param  __HANDLE__: DMA 句柄
  * @param __INTERRUPT__: 指定要禁用的 DMA 中断源。
  *          此参数可以是以下值的任意组合：
  *            @arg DMA_IT_TC:  传输完成中断掩码
  *            @arg DMA_IT_HT:  半传输完成中断掩码
  *            @arg DMA_IT_TE:  传输错误中断掩码
  * @retval 无
  */
#define __HAL_DMA_DISABLE_IT(__HANDLE__, __INTERRUPT__)  (CLEAR_BIT((__HANDLE__)->Instance->CCR , (__INTERRUPT__)))

/**
  * @brief  检查指定的 DMA 通道中断是否已使能。
  * @param  __HANDLE__: DMA 句柄
  * @param  __INTERRUPT__: 指定要检查的 DMA 中断源。
  *          此参数可以是以下值之一：
  *            @arg DMA_IT_TC:  传输完成中断掩码
  *            @arg DMA_IT_HT:  半传输完成中断掩码
  *            @arg DMA_IT_TE:  传输错误中断掩码
  * @retval DMA_IT 的状态（SET 或 RESET）。
  */
#define __HAL_DMA_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__)  ((((__HANDLE__)->Instance->CCR & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)

/**
  * @brief  返回当前 DMA 通道传输中剩余的数据单元数量。
  * @param  __HANDLE__: DMA 句柄
  * @retval 当前 DMA 通道传输中剩余的数据单元数量。
  */
#define __HAL_DMA_GET_COUNTER(__HANDLE__) ((__HANDLE__)->Instance->CNDTR)

/**
  * @}
  */

/* 包含 DMA HAL 扩展模块 */
#include "stm32f1xx_hal_dma_ex.h"   

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup DMA_Exported_Functions
  * @{
  */

/** @addtogroup DMA_Exported_Functions_Group1
  * @{
  */
/* 初始化与反初始化函数 *****************************/
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit (DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group2
  * @{
  */
/* IO 操作函数 *****************************************************/
// 启动 DMA 传输（非中断方式，轮询）
HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
// 启动 DMA 传输（中断方式）
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
// 中止 DMA 传输（非中断方式）
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
// 中止 DMA 传输（中断方式）
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
// 轮询查询传输状态
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout);
// DMA 中断处理函数
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
// 注册回调函数
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma));
// 注销回调函数
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);

/**
  * @}
  */

/** @addtogroup DMA_Exported_Functions_Group3
  * @{
  */
/* 外设状态与错误函数 ***************************************/
// 获取 DMA 状态
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
// 获取 DMA 错误代码
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma);
/**
  * @}
  */

/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup DMA_Private_Macros DMA Private Macros
  * @{
  */

// 检查传输方向参数是否合法
#define IS_DMA_DIRECTION(DIRECTION) (((DIRECTION) == DMA_PERIPH_TO_MEMORY ) || \
                                     ((DIRECTION) == DMA_MEMORY_TO_PERIPH)  || \
                                     ((DIRECTION) == DMA_MEMORY_TO_MEMORY))

// 检查缓冲区大小是否合法 (1 到 65535)
#define IS_DMA_BUFFER_SIZE(SIZE) (((SIZE) >= 0x1U) && ((SIZE) < 0x10000U))

// 检查外设地址自增模式参数是否合法
#define IS_DMA_PERIPHERAL_INC_STATE(STATE) (((STATE) == DMA_PINC_ENABLE) || \
                                            ((STATE) == DMA_PINC_DISABLE))

// 检查内存地址自增模式参数是否合法
#define IS_DMA_MEMORY_INC_STATE(STATE) (((STATE) == DMA_MINC_ENABLE)  || \
                                        ((STATE) == DMA_MINC_DISABLE))

// 检查外设数据宽度参数是否合法
#define IS_DMA_PERIPHERAL_DATA_SIZE(SIZE) (((SIZE) == DMA_PDATAALIGN_BYTE)     || \
                                           ((SIZE) == DMA_PDATAALIGN_HALFWORD) || \
                                           ((SIZE) == DMA_PDATAALIGN_WORD))

// 检查内存数据宽度参数是否合法
#define IS_DMA_MEMORY_DATA_SIZE(SIZE) (((SIZE) == DMA_MDATAALIGN_BYTE)     || \
                                       ((SIZE) == DMA_MDATAALIGN_HALFWORD) || \
                                       ((SIZE) == DMA_MDATAALIGN_WORD ))

// 检查模式参数是否合法
#define IS_DMA_MODE(MODE) (((MODE) == DMA_NORMAL )  || \
                           ((MODE) == DMA_CIRCULAR))

// 检查优先级参数是否合法
#define IS_DMA_PRIORITY(PRIORITY) (((PRIORITY) == DMA_PRIORITY_LOW )   || \
                                   ((PRIORITY) == DMA_PRIORITY_MEDIUM) || \
                                   ((PRIORITY) == DMA_PRIORITY_HIGH)   || \
                                   ((PRIORITY) == DMA_PRIORITY_VERY_HIGH))

/**
  * @}
  */ 

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

#endif /* __STM32F1xx_HAL_DMA_H */
