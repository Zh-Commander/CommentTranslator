/**
  ******************************************************************************
  * @file    stm32f1xx_hal_dma.c
  * @author  MCD Application Team
  * @brief   DMA HAL 模块驱动。
  *          本文件提供固件函数用于管理直接存储器访问 (DMA) 外设的以下功能：
  *           + 初始化和反初始化函数
  *           + 输入输出操作函数
  *           + 外设状态和错误函数
  @verbatim
  ==============================================================================
                        ##### 如何使用本驱动 #####
  ==============================================================================
  [..]
   (#) 使能并配置连接到 DMA 通道的外设（内部 SRAM/FLASH 存储器除外：
       不需要初始化）。请参考参考手册中关于外设和 DMA 请求之间的连接说明。

   (#) 对于给定的通道，通过 HAL_DMA_Init() 函数编程所需的配置参数：
       通道请求、传输方向、源和目的数据格式、循环或正常模式、
       通道优先级、源和目的增量模式。

   (#) 使用 HAL_DMA_GetState() 函数返回 DMA 状态，在检测到错误时使用
       HAL_DMA_GetError() 获取错误信息。
                    
   (#) 使用 HAL_DMA_Abort() 函数中止当前传输
                   
     -@-   在存储器到存储器传输模式下，不允许使用循环模式。
     *** 轮询模式 IO 操作 ***
     =================================
    [..]
          (+) 使用 HAL_DMA_Start() 在配置好源地址、目的地址和数据传输长度后
              启动 DMA 传输。
          (+) 使用 HAL_DMA_PollForTransfer() 轮询当前传输的结束，这种情况下，
              用户可以根据应用配置一个固定的超时时间。

     *** 中断模式 IO 操作 ***
     ===================================
    [..]
          (+) 使用 HAL_NVIC_SetPriority() 配置 DMA 中断优先级
          (+) 使用 HAL_NVIC_EnableIRQ() 使能 DMA IRQ 处理程序
          (+) 使用 HAL_DMA_Start_IT() 在配置好源地址、目的地址和数据传输长度后
              启动 DMA 传输。这种情况下会配置 DMA 中断。
          (+) 在 DMA_IRQHandler() 中断服务程序中调用 HAL_DMA_IRQHandler()
          (+) 数据传输结束时执行 HAL_DMA_IRQHandler() 函数，用户可以通过
              自定义函数指针 XferCpltCallback 和 XferErrorCallback（即 DMA 句柄
              结构体的成员）添加自己的函数。

     *** DMA HAL 驱动宏列表 ***
     ============================================= 
      [..]
       以下是 DMA HAL 驱动中最常用的宏列表。

       (+) __HAL_DMA_ENABLE: 使能指定的 DMA 通道。
       (+) __HAL_DMA_DISABLE: 禁用指定的 DMA 通道。
       (+) __HAL_DMA_GET_FLAG: 获取 DMA 通道的挂起标志。
       (+) __HAL_DMA_CLEAR_FLAG: 清除 DMA 通道的挂起标志。
       (+) __HAL_DMA_ENABLE_IT: 使能指定的 DMA 通道中断。
       (+) __HAL_DMA_DISABLE_IT: 禁用指定的 DMA 通道中断。
       (+) __HAL_DMA_GET_IT_SOURCE: 检查指定的 DMA 通道中断是否发生。

    [..] 
      (@) 您可以参考 DMA HAL 驱动头文件了解更多有用的宏  

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * 版权所有。
  *
  * 本软件根据本软件组件根目录中的 LICENSE 文件中的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 包含 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup DMA DMA
  * @brief DMA HAL 模块驱动
  * @{
  */

#ifdef HAL_DMA_MODULE_ENABLED

/* 私有类型定义 -----------------------------------------------------------*/
/* 私有定义 ------------------------------------------------------------*/
/* 私有宏 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有函数原型 -----------------------------------------------*/
/** @defgroup DMA_Private_Functions DMA 私有函数
  * @{
  */
static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
/**
  * @}
  */

/* 导出函数 ---------------------------------------------------------*/

/** @defgroup DMA_Exported_Functions DMA 导出函数
  * @{
  */

/** @defgroup DMA_Exported_Functions_Group1 初始化和反初始化函数
  *  @brief   初始化和反初始化函数 
  *
@verbatim
 ===============================================================================
             ##### 初始化和反初始化函数  #####
 ===============================================================================
    [..]
    本节提供允许初始化 DMA 通道源地址和目的地址、增量和数据大小、
    传输方向、循环/正常模式选择、存储器到存储器模式选择和通道优先级的函数。
    [..]
    HAL_DMA_Init() 函数遵循参考手册中描述的 DMA 配置过程。

@endverbatim
  * @{
  */

/**
  * @brief  根据 DMA_InitTypeDef 中的指定参数初始化 DMA，并初始化关联的句柄。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma)
{
  uint32_t tmp = 0U;

  /* 检查 DMA 句柄分配 */
  if(hdma == NULL)
  {
    return HAL_ERROR;
  }

  /* 检查参数 */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance)); // 检查是否为有效的 DMA 实例
  assert_param(IS_DMA_DIRECTION(hdma->Init.Direction)); // 检查传输方向参数
  assert_param(IS_DMA_PERIPHERAL_INC_STATE(hdma->Init.PeriphInc)); // 检查外设增量模式参数
  assert_param(IS_DMA_MEMORY_INC_STATE(hdma->Init.MemInc)); // 检查存储器增量模式参数
  assert_param(IS_DMA_PERIPHERAL_DATA_SIZE(hdma->Init.PeriphDataAlignment)); // 检查外设数据宽度参数
  assert_param(IS_DMA_MEMORY_DATA_SIZE(hdma->Init.MemDataAlignment)); // 检查存储器数据宽度参数
  assert_param(IS_DMA_MODE(hdma->Init.Mode)); // 检查模式参数（循环或正常）
  assert_param(IS_DMA_PRIORITY(hdma->Init.Priority)); // 检查优先级参数

#if defined (DMA2)
  /* 计算通道索引 */
  /* 判断是 DMA1 还是 DMA2 */
  if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel1))
  {
    /* DMA1 */
    /* 计算通道在寄存器中的偏移位置，左移2位是因为通道间偏移量计算 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
    hdma->DmaBaseAddress = DMA1; // 设置 DMA1 基地址
  }
  else 
  {
    /* DMA2 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA2_Channel1) / ((uint32_t)DMA2_Channel2 - (uint32_t)DMA2_Channel1)) << 2;
    hdma->DmaBaseAddress = DMA2; // 设置 DMA2 基地址
  }
#else
  /* 仅存在 DMA1 的情况 */
  /* DMA1 */
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
  hdma->DmaBaseAddress = DMA1;
#endif /* DMA2 */

  /* 更改 DMA 外设状态 */
  hdma->State = HAL_DMA_STATE_BUSY;

  /* 获取 CCR 寄存器值 */
  tmp = hdma->Instance->CCR;

  /* 清除 PL, MSIZE, PSIZE, MINC, PINC, CIRC 和 DIR 位 */
  /* 这些位用于配置优先级、存储器/外设数据大小、增量模式、循环模式和方向 */
  tmp &= ((uint32_t)~(DMA_CCR_PL    | DMA_CCR_MSIZE  | DMA_CCR_PSIZE  | \
                      DMA_CCR_MINC  | DMA_CCR_PINC   | DMA_CCR_CIRC   | \
                      DMA_CCR_DIR));

  /* 准备 DMA 通道配置 */
  /* 将用户配置的参数通过或运算写入 tmp 变量 */
  tmp |=  hdma->Init.Direction        | // 传输方向
          hdma->Init.PeriphInc           | hdma->Init.MemInc           | // 外设/存储器增量模式
          hdma->Init.PeriphDataAlignment | hdma->Init.MemDataAlignment | // 外设/存储器数据宽度
          hdma->Init.Mode                | hdma->Init.Priority; // 模式和优先级

  /* 写入 DMA 通道 CCR 寄存器 */
  hdma->Instance->CCR = tmp;

  /* 初始化错误代码 */
  hdma->ErrorCode = HAL_DMA_ERROR_NONE;

  /* 初始化 DMA 状态*/
  hdma->State = HAL_DMA_STATE_READY;
  /* 分配锁资源并初始化 */
  hdma->Lock = HAL_UNLOCKED;

  return HAL_OK;
}

/**
  * @brief  反初始化 DMA 外设。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma)
{
  /* 检查 DMA 句柄分配 */
  if(hdma == NULL)
  {
    return HAL_ERROR;
  }

  /* 检查参数 */
  assert_param(IS_DMA_ALL_INSTANCE(hdma->Instance));

  /* 禁用选定的 DMA 通道x */
  __HAL_DMA_DISABLE(hdma);

  /* 复位 DMA 通道控制寄存器 */
  hdma->Instance->CCR  = 0U;

  /* 复位 DMA 通道数据传输数量寄存器 */
  hdma->Instance->CNDTR = 0U;

  /* 复位 DMA 通道外设地址寄存器 */
  hdma->Instance->CPAR  = 0U;

  /* 复位 DMA 通道存储器地址寄存器 */
  hdma->Instance->CMAR = 0U;

#if defined (DMA2)
  /* 计算通道索引 */
  if ((uint32_t)(hdma->Instance) < (uint32_t)(DMA2_Channel1))
  {
    /* DMA1 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
    hdma->DmaBaseAddress = DMA1;
  }
  else
  {
    /* DMA2 */
    hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA2_Channel1) / ((uint32_t)DMA2_Channel2 - (uint32_t)DMA2_Channel1)) << 2;
    hdma->DmaBaseAddress = DMA2;
  }
#else
  /* DMA1 */
  hdma->ChannelIndex = (((uint32_t)hdma->Instance - (uint32_t)DMA1_Channel1) / ((uint32_t)DMA1_Channel2 - (uint32_t)DMA1_Channel1)) << 2;
  hdma->DmaBaseAddress = DMA1;
#endif /* DMA2 */

  /* 清除所有标志 */
  /* IFCR 是中断标志清除寄存器，写入 1 清除对应位的 ISR 标志 */
  hdma->DmaBaseAddress->IFCR = (DMA_ISR_GIF1 << (hdma->ChannelIndex));

  /* 清除所有回调函数 */
  hdma->XferCpltCallback = NULL; // 传输完成回调
  hdma->XferHalfCpltCallback = NULL; // 半传输完成回调
  hdma->XferErrorCallback = NULL; // 传输错误回调
  hdma->XferAbortCallback = NULL; // 传输中止回调

  /* 复位错误代码 */
  hdma->ErrorCode = HAL_DMA_ERROR_NONE;

  /* 复位 DMA 状态 */
  hdma->State = HAL_DMA_STATE_RESET;

  /* 释放锁 */
  __HAL_UNLOCK(hdma);

  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Group2 输入和输出操作函数
  *  @brief   输入和输出操作函数
  *
@verbatim
 ===============================================================================
                      #####  IO 操作函数  #####
 ===============================================================================
    [..]  本节提供允许以下操作的函数：
      (+) 配置源地址、目的地址和数据长度并启动 DMA 传输
      (+) 配置源地址、目的地址和数据长度并使用中断启动 DMA 传输
      (+) 中止 DMA 传输
      (+) 轮询传输完成
      (+) 处理 DMA 中断请求

@endverbatim
  * @{
  */

/**
  * @brief  启动 DMA 传输。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @param  SrcAddress: 源内存缓冲区地址
  * @param  DstAddress: 目的内存缓冲区地址
  * @param  DataLength: 从源传输到目的的数据长度
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* 检查参数 */
  assert_param(IS_DMA_BUFFER_SIZE(DataLength)); // 检查数据长度是否有效

  /* 上锁 */
  __HAL_LOCK(hdma);

  if(HAL_DMA_STATE_READY == hdma->State)
  {
    /* 更改 DMA 外设状态 */
    hdma->State = HAL_DMA_STATE_BUSY;
    hdma->ErrorCode = HAL_DMA_ERROR_NONE;
            
    /* 禁用外设 */
    __HAL_DMA_DISABLE(hdma);
    
    /* 配置源地址、目的地址和数据长度并清除标志 */
    DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);
    
    /* 使能外设 */
    __HAL_DMA_ENABLE(hdma);
  }
  else
  {
   /* 解锁 */
   __HAL_UNLOCK(hdma);  
   status = HAL_BUSY; // 返回忙状态
  }  
  return status;
}

/**
  * @brief  启用中断启动 DMA 传输。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @param  SrcAddress: 源内存缓冲区地址
  * @param  DstAddress: 目的内存缓冲区地址
  * @param  DataLength: 从源传输到目的的数据长度
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* 检查参数 */
  assert_param(IS_DMA_BUFFER_SIZE(DataLength));

  /* 上锁 */
  __HAL_LOCK(hdma);
  
  if(HAL_DMA_STATE_READY == hdma->State)
  {
    /* 更改 DMA 外设状态 */
    hdma->State = HAL_DMA_STATE_BUSY;
    hdma->ErrorCode = HAL_DMA_ERROR_NONE;
    
    /* 禁用外设 */
    __HAL_DMA_DISABLE(hdma);
    
    /* 配置源地址、目的地址和数据长度并清除标志 */
    DMA_SetConfig(hdma, SrcAddress, DstAddress, DataLength);
    
    /* 使能传输完成中断 */
    /* 使能传输错误中断 */
    if(NULL != hdma->XferHalfCpltCallback)
    {
      /* 如果有半传输回调，则同时使能半传输中断 */
      __HAL_DMA_ENABLE_IT(hdma, (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE));
    }
    else
    {
      /* 否则禁用半传输中断，只使能传输完成和错误中断 */
      __HAL_DMA_DISABLE_IT(hdma, DMA_IT_HT);
      __HAL_DMA_ENABLE_IT(hdma, (DMA_IT_TC | DMA_IT_TE));
    }
    /* 使能外设 */
    __HAL_DMA_ENABLE(hdma);
  }
  else
  {      
    /* 解锁 */
    __HAL_UNLOCK(hdma); 

    /* 保持忙状态 */
    status = HAL_BUSY;
  }    
  return status;
}

/**
  * @brief  中止 DMA 传输。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  if(hdma->State != HAL_DMA_STATE_BUSY)
  {
    /* 没有正在进行的传输 */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
    
    /* 解锁 */
    __HAL_UNLOCK(hdma);
    
    return HAL_ERROR;
  }
  else

  {
    /* 禁用 DMA 中断 */
    __HAL_DMA_DISABLE_IT(hdma, (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE));
      
    /* 禁用通道 */
    __HAL_DMA_DISABLE(hdma);
      
    /* 清除所有标志 */
    hdma->DmaBaseAddress->IFCR = (DMA_ISR_GIF1 << hdma->ChannelIndex);
  }
  /* 更改 DMA 状态 */
  hdma->State = HAL_DMA_STATE_READY;

  /* 解锁 */
  __HAL_UNLOCK(hdma);      
  
  return status; 
}

/**
  * @brief  在中断模式下中止 DMA 传输。
  * @param  hdma  : 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma)
{  
  HAL_StatusTypeDef status = HAL_OK;
  
  if(HAL_DMA_STATE_BUSY != hdma->State)
  {
    /* 没有正在进行的传输 */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
        
    status = HAL_ERROR;
  }
  else
  { 
    /* 禁用 DMA 中断 */
    __HAL_DMA_DISABLE_IT(hdma, (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE));

    /* 禁用通道 */
    __HAL_DMA_DISABLE(hdma);

    /* 清除所有标志 */
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_GI_FLAG_INDEX(hdma));

    /* 更改 DMA 状态 */
    hdma->State = HAL_DMA_STATE_READY;

    /* 解锁 */
    __HAL_UNLOCK(hdma);

    /* 调用用户中止回调 */
    if(hdma->XferAbortCallback != NULL)
    {
      hdma->XferAbortCallback(hdma);
    } 
  }
  return status;
}

/**
  * @brief  轮询传输完成。
  * @param  hdma:    指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @param  CompleteLevel: 指定 DMA 完成级别（全传输或半传输）。
  * @param  Timeout:       超时时长。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout)
{
  uint32_t temp;
  uint32_t tickstart = 0U;

  if(HAL_DMA_STATE_BUSY != hdma->State)
  {
    /* 没有正在进行的传输 */
    hdma->ErrorCode = HAL_DMA_ERROR_NO_XFER;
    __HAL_UNLOCK(hdma);
    return HAL_ERROR;
  }

  /* 循环模式不支持轮询模式 */
  if (RESET != (hdma->Instance->CCR & DMA_CCR_CIRC))
  {
    hdma->ErrorCode = HAL_DMA_ERROR_NOT_SUPPORTED;
    return HAL_ERROR;
  }
  
  /* 获取级别传输完成标志 */
  if(CompleteLevel == HAL_DMA_FULL_TRANSFER)
  {
    /* 传输完成标志 */
    temp = __HAL_DMA_GET_TC_FLAG_INDEX(hdma);
  }
  else
  {
    /* 半传输完成标志 */
    temp = __HAL_DMA_GET_HT_FLAG_INDEX(hdma);
  }

  /* 获取滴答计数值 */
  tickstart = HAL_GetTick();

  /* 等待标志置位 */
  while(__HAL_DMA_GET_FLAG(hdma, temp) == RESET)
  {
    if((__HAL_DMA_GET_FLAG(hdma, __HAL_DMA_GET_TE_FLAG_INDEX(hdma)) != RESET))
    {
      /* 当发生 DMA 传输错误时 */
      /* 硬件会自动清除 EN 位 */
      /* 清除所有标志 */
      hdma->DmaBaseAddress->IFCR = (DMA_ISR_GIF1 << hdma->ChannelIndex);

      /* 更新错误代码 */
      SET_BIT(hdma->ErrorCode, HAL_DMA_ERROR_TE);

      /* 更改 DMA 状态 */
      hdma->State= HAL_DMA_STATE_READY;

      /* 解锁 */
      __HAL_UNLOCK(hdma);

      return HAL_ERROR;
    }
    /* 检查超时 */
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
      {
        /* 更新错误代码 */
        SET_BIT(hdma->ErrorCode, HAL_DMA_ERROR_TIMEOUT);

        /* 更改 DMA 状态 */
        hdma->State = HAL_DMA_STATE_READY;

        /* 解锁 */
        __HAL_UNLOCK(hdma);

        return HAL_ERROR;
      }
    }
  }

  if(CompleteLevel == HAL_DMA_FULL_TRANSFER)
  {
    /* 清除传输完成标志 */
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));

    /* 选定的通道 EN 位被清除（DMA 被禁用且所有传输完成） */
    hdma->State = HAL_DMA_STATE_READY;
  }
  else
  {
    /* 清除半传输完成标志 */
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));
  }
  
  /* 解锁 */
  __HAL_UNLOCK(hdma);

  return HAL_OK;
}

/**
  * @brief  处理 DMA 中断请求。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。  
  * @retval 无
  */
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma)
{
  uint32_t flag_it = hdma->DmaBaseAddress->ISR; // 获取中断状态寄存器值
  uint32_t source_it = hdma->Instance->CCR; // 获取通道控制寄存器值
  
  /* 半传输完成中断管理 ******************************/
  /* 检查半传输标志是否置位且半传输中断是否使能 */
  if (((flag_it & (DMA_FLAG_HT1 << hdma->ChannelIndex)) != RESET) && ((source_it & DMA_IT_HT) != RESET))
  {
    /* 如果 DMA 模式不是循环模式，则禁用半传输中断 */
    if((hdma->Instance->CCR & DMA_CCR_CIRC) == 0U)
    {
      /* 禁用半传输中断 */
      __HAL_DMA_DISABLE_IT(hdma, DMA_IT_HT);
    }
    /* 清除半传输完成标志 */
    __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_HT_FLAG_INDEX(hdma));

    /* 半传输情况下不更新 DMA 外设状态 */
    /* 但在传输完成情况下更新 */

    if(hdma->XferHalfCpltCallback != NULL)
    {
      /* 半传输回调 */
      hdma->XferHalfCpltCallback(hdma);
    }
  }

  /* 传输完成中断管理 ***********************************/
  /* 检查传输完成标志是否置位且传输完成中断是否使能 */
  else if (((flag_it & (DMA_FLAG_TC1 << hdma->ChannelIndex)) != RESET) && ((source_it & DMA_IT_TC) != RESET))
  {
    if((hdma->Instance->CCR & DMA_CCR_CIRC) == 0U)
    {
      /* 禁用传输完成和错误中断 */
      __HAL_DMA_DISABLE_IT(hdma, DMA_IT_TE | DMA_IT_TC);  

      /* 更改 DMA 状态 */
      hdma->State = HAL_DMA_STATE_READY;
    }
    /* 清除传输完成标志 */
      __HAL_DMA_CLEAR_FLAG(hdma, __HAL_DMA_GET_TC_FLAG_INDEX(hdma));

    /* 解锁 */
    __HAL_UNLOCK(hdma);

    if(hdma->XferCpltCallback != NULL)
    {
      /* 传输完成回调 */
      hdma->XferCpltCallback(hdma);
    }
  }

  /* 传输错误中断管理 **************************************/
  /* 检查传输错误标志是否置位且传输错误中断是否使能 */
  else if (( RESET != (flag_it & (DMA_FLAG_TE1 << hdma->ChannelIndex))) && (RESET != (source_it & DMA_IT_TE)))
  {
    /* 当发生 DMA 传输错误时 */
    /* 硬件会自动清除 EN 位 */
    /* 禁用所有 DMA 中断 */
    __HAL_DMA_DISABLE_IT(hdma, (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE));

    /* 清除所有标志 */
    hdma->DmaBaseAddress->IFCR = (DMA_ISR_GIF1 << hdma->ChannelIndex);

    /* 更新错误代码 */
    hdma->ErrorCode = HAL_DMA_ERROR_TE;

    /* 更改 DMA 状态 */
    hdma->State = HAL_DMA_STATE_READY;

    /* 解锁 */
    __HAL_UNLOCK(hdma);

    if (hdma->XferErrorCallback != NULL)
    {
      /* 传输错误回调 */
      hdma->XferErrorCallback(hdma);
    }
  }
  return;
}

/**
  * @brief 注册回调函数
  * @param hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @param CallbackID: 用户回调标识符，使用 HAL_DMA_CallbackIDTypeDef 枚举作为参数。
  * @param pCallback: 指向私有回调函数的指针，该函数以指向 DMA_HandleTypeDef 结构体的指针作为参数。
  * @retval HAL 状态
  */                          
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma))
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* 上锁 */
  __HAL_LOCK(hdma);
  
  if(HAL_DMA_STATE_READY == hdma->State)
  {
    switch (CallbackID)
    {
    case  HAL_DMA_XFER_CPLT_CB_ID: // 传输完成回调 ID
      hdma->XferCpltCallback = pCallback;
      break;
      
    case  HAL_DMA_XFER_HALFCPLT_CB_ID: // 半传输完成回调 ID
      hdma->XferHalfCpltCallback = pCallback;
      break;         

    case  HAL_DMA_XFER_ERROR_CB_ID: // 传输错误回调 ID
      hdma->XferErrorCallback = pCallback;
      break;         
      
    case  HAL_DMA_XFER_ABORT_CB_ID: // 传输中止回调 ID
      hdma->XferAbortCallback = pCallback;
      break; 
      
    default:
      status = HAL_ERROR; // 未知 ID 返回错误
      break;                                                            
    }
  }
  else
  {
    status = HAL_ERROR; // 状态非 Ready 返回错误
  } 
  
  /* 释放锁 */
  __HAL_UNLOCK(hdma);
  
  return status;
}

/**
  * @brief 注销回调函数
  * @param hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @param CallbackID: 用户回调标识符，使用 HAL_DMA_CallbackIDTypeDef 枚举作为参数。
  * @retval HAL 状态
  */              
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* 上锁 */
  __HAL_LOCK(hdma);
  
  if(HAL_DMA_STATE_READY == hdma->State)
  {
    switch (CallbackID)
    {
    case  HAL_DMA_XFER_CPLT_CB_ID:
      hdma->XferCpltCallback = NULL; // 注销传输完成回调
      break;

    case  HAL_DMA_XFER_HALFCPLT_CB_ID:
      hdma->XferHalfCpltCallback = NULL; // 注销半传输完成回调
      break;         

    case  HAL_DMA_XFER_ERROR_CB_ID:
      hdma->XferErrorCallback = NULL; // 注销传输错误回调
      break;         

    case  HAL_DMA_XFER_ABORT_CB_ID:
      hdma->XferAbortCallback = NULL; // 注销传输中止回调
      break; 

    case   HAL_DMA_XFER_ALL_CB_ID: // 注销所有回调
      hdma->XferCpltCallback = NULL;
      hdma->XferHalfCpltCallback = NULL;
      hdma->XferErrorCallback = NULL;
      hdma->XferAbortCallback = NULL;
      break; 

    default:
      status = HAL_ERROR;
      break;
    }
  }
  else
  {
    status = HAL_ERROR;
  } 
  
  /* 释放锁 */
  __HAL_UNLOCK(hdma);
  
  return status;
}
  
/**
  * @}
  */

/** @defgroup DMA_Exported_Functions_Group3 外设状态和错误函数
  *  @brief    外设状态和错误函数
  *
@verbatim
 ===============================================================================
            ##### 外设状态和错误函数 #####
 ===============================================================================  
    [..]
    本小节提供允许以下操作的函数：
      (+) 检查 DMA 状态
      (+) 获取错误代码

@endverbatim
  * @{
  */

/**
  * @brief  返回 DMA 句柄状态。
  * @param  hdma: 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @retval HAL 状态
  */
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma)
{
  /* 返回 DMA 句柄状态 */
  return hdma->State;
}

/**
  * @brief  返回 DMA 错误代码。
  * @param  hdma : 指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @retval DMA 错误代码
  */
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma)
{
  return hdma->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup DMA_Private_Functions
  * @{
  */

/**
  * @brief  设置 DMA 传输参数。
  * @param  hdma:       指向 DMA_HandleTypeDef 结构体的指针，该结构体包含指定 DMA 通道的配置信息。
  * @param  SrcAddress: 源内存缓冲区地址
  * @param  DstAddress: 目的内存缓冲区地址
  * @param  DataLength: 从源传输到目的的数据长度
  * @retval HAL 状态
  */
static void DMA_SetConfig(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength)
{
  /* 清除所有标志 */
  hdma->DmaBaseAddress->IFCR = (DMA_ISR_GIF1 << hdma->ChannelIndex);

  /* 配置 DMA 通道数据长度 */
  hdma->Instance->CNDTR = DataLength;

  /* 存储器到外设 */
  if((hdma->Init.Direction) == DMA_MEMORY_TO_PERIPH)
  {
    /* 配置 DMA 通道目的地址 (外设地址) */
    hdma->Instance->CPAR = DstAddress;

    /* 配置 DMA 通道源地址 (存储器地址) */
    hdma->Instance->CMAR = SrcAddress;
  }
  /* 外设到存储器 */
  else
  {
    /* 配置 DMA 通道源地址 (外设地址) */
    hdma->Instance->CPAR = SrcAddress;

    /* 配置 DMA 通道目的地址 (存储器地址) */
    hdma->Instance->CMAR = DstAddress;
  }
}

/**
  * @}
  */

#endif /* HAL_DMA_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

