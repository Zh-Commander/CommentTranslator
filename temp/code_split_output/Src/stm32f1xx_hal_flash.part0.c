/**
  ******************************************************************************
  * @file    stm32f1xx_hal_flash.c
  * @author  MCD Application Team
  * @brief   FLASH HAL 模块驱动。
  *          本文件提供固件函数以管理内部 FLASH 存储器的以下功能：
  *           + 编程操作函数
  *           + 存储器控制函数
  *           + 外设状态函数
  *         
  @verbatim
  ==============================================================================
                        ##### FLASH 外设特性 #####
  ==============================================================================
  [..] Flash 存储器接口管理 CPU AHB I-Code 和 D-Code 对 Flash 存储器的访问。
       它实现了 Flash 存储器的擦除和编程操作以及读写保护机制。

  [..] Flash 存储器接口通过指令预取机制加速代码执行。

  [..] FLASH 的主要特性如下：
      (+) Flash 存储器读取操作
      (+) Flash 存储器编程/擦除操作
      (+) 读/写保护
      (+) I-Code 上的预取
      (+) 选项字节编程


                     ##### 如何使用本驱动 #####
  ==============================================================================
  [..]                             
      本驱动提供函数和宏来配置和编程所有 STM32F1xx 设备的 FLASH 存储器。
    
      (#) FLASH 存储器 I/O 编程函数：该组包括擦除和编程主存储器所需的所有函数：
        (++) 锁定和解锁 FLASH 接口
        (++) 擦除函数：页擦除，全片擦除
        (++) 编程函数：半字，字和双字
      (#) FLASH 选项字节编程函数：该组包括管理选项字节所需的所有函数：
        (++) 锁定和解锁选项字节
        (++) 设置/重置写保护
        (++) 设置读保护等级
        (++) 编程用户选项字节
        (++) 启动选项字节加载
        (++) 擦除选项字节
        (++) 编程数据选项字节
        (++) 获取写保护状态
        (++) 获取用户选项字节
    
      (#) 中断和标志管理函数：该组包括所需的所有函数：
        (++) 处理 FLASH 中断
        (++) 根据状态等待最后一次 FLASH 操作
        (++) 获取错误标志状态

  [..] 除了这些函数外，本驱动还包括一组宏，允许处理以下操作：
      
      (+) 设置/获取延迟
      (+) 使能/失能预取缓冲区
      (+) 使能/失能半周期访问
      (+) 使能/失能 FLASH 中断
      (+) 监控 FLASH 标志状态
          
  @endverbatim
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * 版权所有。
  *
  * 本软件根据本软件组件根目录中的 LICENSE 文件中找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  ******************************************************************************
  */

/* 包含 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

#ifdef HAL_FLASH_MODULE_ENABLED

/** @defgroup FLASH FLASH
  * @brief FLASH HAL 模块驱动
  * @{
  */

/* 私有类型定义 -----------------------------------------------------------*/
/* 私有定义 ------------------------------------------------------------*/
/** @defgroup FLASH_Private_Constants FLASH 私有常量
  * @{
  */
/**
  * @}
  */

/* 私有宏 --------------------------------- --------------------------------*/
/** @defgroup FLASH_Private_Macros FLASH 私有宏
  * @{
  */
 
/**
  * @}
  */

/* 私有变量 ---------------------------------------------------------*/
/** @defgroup FLASH_Private_Variables FLASH 私有变量
  * @{
  */
/* 用于中断下擦除页面的变量 */
FLASH_ProcessTypeDef pFlash; // Flash 处理过程结构体变量，用于记录Flash操作的状态、地址、数据等
/**
  * @}
  */

/* 私有函数原型 -----------------------------------------------*/
/** @defgroup FLASH_Private_Functions FLASH 私有函数
  * @{
  */
static  void   FLASH_Program_HalfWord(uint32_t Address, uint16_t Data); // 半字编程函数
static  void   FLASH_SetErrorCode(void); // 设置错误代码函数
extern void    FLASH_PageErase(uint32_t PageAddress); // 页擦除函数
/**
  * @}
  */

/* 导出函数 ---------------------------------------------------------*/
/** @defgroup FLASH_Exported_Functions FLASH 导出函数
  * @{
  */
  
/** @defgroup FLASH_Exported_Functions_Group1 编程操作函数 
  *  @brief   编程操作函数 
  *
@verbatim   
@endverbatim
  * @{
  */

/**
  * @brief  在指定地址编程半字、字或双字
  * @note   在解锁 FLASH 接口之前应调用函数 HAL_FLASH_Unlock()
  *         在锁定 FLASH 接口之后应调用函数 HAL_FLASH_Lock()
  *
  * @note   如果同时请求擦除和编程操作，擦除操作将在编程操作之前执行。
  *  
  * @note   在新编程之前应先擦除 FLASH（唯一的例外是编程 0x0000）
  *
  * @param  TypeProgram:  指示在指定地址编程的方式。
  *                       该参数可以是 @ref FLASH_Type_Program 的值
  * @param  Address:      指定要编程的地址。
  * @param  Data:         指定要编程的数据
  * 
  * @retval HAL_StatusTypeDef HAL 状态
  */
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR; // 初始化状态变量为错误
  uint8_t index = 0; // 循环索引变量
  uint8_t nbiterations = 0; // 循环次数变量，根据编程类型决定
  
  /* 进程锁定 */
  __HAL_LOCK(&pFlash); // 锁定进程，防止多任务冲突

  /* 检查参数 */
  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram)); // 检查编程类型参数是否合法
  assert_param(IS_FLASH_PROGRAM_ADDRESS(Address)); // 检查编程地址参数是否合法

#if defined(FLASH_BANK2_END)
  // 如果定义了 Flash Bank2 结束地址（大容量设备）
  if(Address <= FLASH_BANK1_END)
  {
    // 地址在 Bank1 范围内
#endif /* FLASH_BANK2_END */
    /* 等待最后一次操作完成 */
    status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE); // 等待 Bank1 操作完成
#if defined(FLASH_BANK2_END)
  }
  else
  {
    /* 等待最后一次操作完成 */
    status = FLASH_WaitForLastOperationBank2(FLASH_TIMEOUT_VALUE); // 等待 Bank2 操作完成
  }
#endif /* FLASH_BANK2_END */
  
  if(status == HAL_OK) // 如果上一步操作完成且无错误
  {
    if(TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
    {
      /* 在指定地址编程半字 (16-bit) */
      nbiterations = 1U; // 半字只需编程 1 次
    }
    else if(TypeProgram == FLASH_TYPEPROGRAM_WORD)
    {
      /* 在指定地址编程字 (32-bit = 2*16-bit) */
      nbiterations = 2U; // 字需要编程 2 次
    }
    else
    {
      /* 在指定地址编程双字 (64-bit = 4*16-bit) */
      nbiterations = 4U; // 双字需要编程 4 次
    }

    for (index = 0U; index < nbiterations; index++) // 循环进行半字编程
    {
      // 调用内部函数执行半字编程，地址每次偏移 2 字节，数据每次右移 16 位
      FLASH_Program_HalfWord((Address + (2U*index)), (uint16_t)(Data >> (16U*index)));

#if defined(FLASH_BANK2_END)
      if(Address <= FLASH_BANK1_END)
      {
#endif /* FLASH_BANK2_END */
        /* 等待最后一次操作完成 */
        status = FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE);
    
        /* 如果编程操作完成，禁用 PG Bit */
        CLEAR_BIT(FLASH->CR, FLASH_CR_PG); // 清除编程使能位
#if defined(FLASH_BANK2_END)
      }
      else
      {
        /* 等待最后一次操作完成 */
        status = FLASH_WaitForLastOperationBank2(FLASH_TIMEOUT_VALUE);
        
        /* 如果编程操作完成，禁用 PG Bit */
        CLEAR_BIT(FLASH->CR2, FLASH_CR2_PG); // 清除 Bank2 编程使能位
      }
#endif /* FLASH_BANK2_END */
      /* 如果发生错误，停止编程过程 */
      if (status != HAL_OK)
      {
        break; // 跳出循环
      }
    }
  }

  /* 进程解锁 */
  __HAL_UNLOCK(&pFlash); // 解锁进程

  return status; // 返回操作状态
}

/**
  * @brief  在指定地址编程半字、字或双字，并使能中断。
  * @note   在解锁 FLASH 接口之前应调用函数 HAL_FLASH_Unlock()
  *         在锁定 FLASH 接口之后应调用函数 HAL_FLASH_Lock()
  *
  * @note   如果同时请求擦除和编程操作，擦除操作将在编程操作之前执行。
  *
  * @param  TypeProgram: 指示在指定地址编程的方式。
  *                      该参数可以是 @ref FLASH_Type_Program 的值
  * @param  Address:     指定要编程的地址。
  * @param  Data:        指定要编程的数据
  * 
  * @retval HAL_StatusTypeDef HAL 状态
  */
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data)
{
  HAL_StatusTypeDef status = HAL_OK; // 初始化状态为 OK

  /* 检查参数 */
  assert_param(IS_FLASH_TYPEPROGRAM(TypeProgram));
  assert_param(IS_FLASH_PROGRAM_ADDRESS(Address));

#if defined(FLASH_BANK2_END)
  /* 如果过程已经在进行中，拒绝下一个请求 */
  if (pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
  {
    return HAL_ERROR;
  }
  
  if(Address <= FLASH_BANK1_END)
  {
    /* 使能 Flash 操作结束和错误源中断 */
    __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP_BANK1 | FLASH_IT_ERR_BANK1);

  }else
  {
    /* 使能 Flash 操作结束和错误源中断 */
    __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP_BANK2 | FLASH_IT_ERR_BANK2);
  }
#else
  /* 使能 Flash 操作结束和错误源中断 */
  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);
#endif /* FLASH_BANK2_END */
  
  pFlash.Address = Address; // 保存编程地址
  pFlash.Data = Data; // 保存编程数据

  if(TypeProgram == FLASH_TYPEPROGRAM_HALFWORD)
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMHALFWORD; // 设置当前进行的过程为半字编程
    /* 在指定地址编程半字 (16-bit) */
    pFlash.DataRemaining = 1U; // 剩余数据量设为 1
  }
  else if(TypeProgram == FLASH_TYPEPROGRAM_WORD)
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMWORD; // 设置当前进行的过程为字编程
    /* 在指定地址编程字 (32-bit : 2*16-bit) */
    pFlash.DataRemaining = 2U; // 剩余数据量设为 2
  }
  else
  {
    pFlash.ProcedureOnGoing = FLASH_PROC_PROGRAMDOUBLEWORD; // 设置当前进行的过程为双字编程
    /* 在指定地址编程双字 (64-bit : 4*16-bit) */
    pFlash.DataRemaining = 4U; // 剩余数据量设为 4
  }

  /* 在指定地址编程半字 (16-bit) */
  FLASH_Program_HalfWord(Address, (uint16_t)Data); // 启动第一次编程，后续在中断中完成

  return status;
}

/**
  * @brief 此函数处理 FLASH 中断请求。
  * @retval 无
  */
void HAL_FLASH_IRQHandler(void)
{
  uint32_t addresstmp = 0U; // 临时地址变量
  
  /* 检查 FLASH 操作错误标志 */
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK1) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK1) || \
    (__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2)))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) ||__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
#endif /* FLASH_BANK2_END */
  {
    /* 返回错误地址 */
    addresstmp = pFlash.Address;
    /* 重置地址 */
    pFlash.Address = 0xFFFFFFFFU;
  
    /* 保存错误代码 */
    FLASH_SetErrorCode();
    
    /* FLASH 错误中断用户回调函数 */
    HAL_FLASH_OperationErrorCallback(addresstmp);

    /* 停止正在进行的过程 */
    pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
  }

  /* 检查 FLASH 操作结束标志 */
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP_BANK1))
  {
    /* 清除 FLASH 操作结束挂起位 */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK1);
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {
    /* 清除 FLASH 操作结束挂起位 */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
#endif /* FLASH_BANK2_END */
    
    /* 只有在未检测到错误时过程才能继续 */
    if(pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
    {
      if(pFlash.ProcedureOnGoing == FLASH_PROC_PAGEERASE)
      {
        /* 待擦除页数递减 */
        pFlash.DataRemaining--;

        /* 检查是否还有页需要擦除 */
        if(pFlash.DataRemaining != 0U)
        {
          addresstmp = pFlash.Address;
          /* 通知用户哪个扇区已被擦除 */
          HAL_FLASH_EndOfOperationCallback(addresstmp);

          /* 扇区号递增 */
          addresstmp = pFlash.Address + FLASH_PAGE_SIZE; // 计算下一页地址
          pFlash.Address = addresstmp;

          /* 如果擦除操作完成，禁用 PER Bit */
          CLEAR_BIT(FLASH->CR, FLASH_CR_PER);

          FLASH_PageErase(addresstmp); // 擦除下一页
        }
        else
        {
          /* 没有更多页需要擦除，可以调用用户回调 */
          /* 重置扇区并停止擦除页过程 */
          pFlash.Address = addresstmp = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
          /* FLASH EOP 中断用户回调 */
          HAL_FLASH_EndOfOperationCallback(addresstmp);
        }
      }
      else if(pFlash.ProcedureOnGoing == FLASH_PROC_MASSERASE)
      {
        /* 操作完成，禁用 MER Bit */
        CLEAR_BIT(FLASH->CR, FLASH_CR_MER);

#if defined(FLASH_BANK2_END)
        /* 如果另一个 bank 上没有挂起的全片擦除，则停止全片擦除过程 */
        if (HAL_IS_BIT_CLR(FLASH->CR2, FLASH_CR2_MER))
        {
#endif /* FLASH_BANK2_END */
          /* 全片擦除结束。返回选定的 bank */
          /* FLASH EOP 中断用户回调 */
          HAL_FLASH_EndOfOperationCallback(0U);

          /* 停止全片擦除过程 */
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
#if defined(FLASH_BANK2_END)
      }
#endif /* FLASH_BANK2_END */
      else
      {
        /* 待编程的 16 位数据量递减 */
        pFlash.DataRemaining--;
        
        /* 检查是否还有 16 位数据需要编程 */
        if(pFlash.DataRemaining != 0U)
        {
          /* 地址递增 16 位 */
          pFlash.Address += 2U;
          addresstmp = pFlash.Address;
          
          /* 移位以获取下一个 16 位数据 */
          pFlash.Data = (pFlash.Data >> 16U);
          
          /* 操作完成，禁用 PG Bit */
          CLEAR_BIT(FLASH->CR, FLASH_CR_PG);

          /* 在指定地址编程半字 (16-bit) */
          FLASH_Program_HalfWord(addresstmp, (uint16_t)pFlash.Data);
        }
        else
        {
          /* 编程结束。返回选定的地址 */
          /* FLASH EOP 中断用户回调 */
          if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMHALFWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address);
          }
          else if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address - 2U);
          }
          else 
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address - 6U);
          }
        
          /* 重置地址并停止编程过程 */
          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
    }
  }
  
#if defined(FLASH_BANK2_END)
  /* 检查 FLASH Bank2 操作结束标志 */
  if(__HAL_FLASH_GET_FLAG( FLASH_FLAG_EOP_BANK2))
  {
    /* 清除 FLASH 操作结束挂起位 */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK2);
    
    /* 只有在未检测到错误时过程才能继续 */
    if(pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
    {
      if(pFlash.ProcedureOnGoing == FLASH_PROC_PAGEERASE)
      {
        /* 待擦除页数递减 */
        pFlash.DataRemaining--;
        
        /* 检查是否还有页需要擦除 */
        if(pFlash.DataRemaining != 0U)
        {
          /* 通知用户哪个页地址已被擦除 */
          HAL_FLASH_EndOfOperationCallback(pFlash.Address);
        
          /* 页地址递增到下一页 */
          pFlash.Address += FLASH_PAGE_SIZE;
          addresstmp = pFlash.Address;

          /* 操作完成，禁用 PER Bit */
          CLEAR_BIT(FLASH->CR2, FLASH_CR2_PER);

          FLASH_PageErase(addresstmp);
        }
        else
        {
          /* 没有更多页需要擦除 */
          
          /* 重置地址并停止擦除页过程 */
          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;

          /* FLASH EOP 中断用户回调 */
          HAL_FLASH_EndOfOperationCallback(pFlash.Address);
        }
      }
      else if(pFlash.ProcedureOnGoing == FLASH_PROC_MASSERASE)
      {
        /* 操作完成，禁用 MER Bit */
        CLEAR_BIT(FLASH->CR2, FLASH_CR2_MER);

        if (HAL_IS_BIT_CLR(FLASH->CR, FLASH_CR_MER))
        {
          /* 全片擦除结束。返回选定的 bank */
          /* FLASH EOP 中断用户回调 */
          HAL_FLASH_EndOfOperationCallback(0U);
        
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
      else
      {
        /* 待编程的 16 位数据量递减 */
        pFlash.DataRemaining--;
        
        /* 检查是否还有 16 位数据需要编程 */
        if(pFlash.DataRemaining != 0U)
        {
          /* 地址递增 16 位 */
          pFlash.Address += 2U;
          addresstmp = pFlash.Address;
          
          /* 移位以获取下一个 16 位数据 */
          pFlash.Data = (pFlash.Data >> 16U);
          
          /* 操作完成，禁用 PG Bit */
          CLEAR_BIT(FLASH->CR2, FLASH_CR2_PG);

          /* 在指定地址编程半字 (16-bit) */
          FLASH_Program_HalfWord(addresstmp, (uint16_t)pFlash.Data);
        }
        else
        {
          /* 编程结束。返回选定的地址 */
          /* FLASH EOP 中断用户回调 */
          if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMHALFWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address);
          }
          else if (pFlash.ProcedureOnGoing == FLASH_PROC_PROGRAMWORD)
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address-2U);
          }
          else 
          {
            HAL_FLASH_EndOfOperationCallback(pFlash.Address-6U);
          }
          
          /* 重置地址并停止编程过程 */
          pFlash.Address = 0xFFFFFFFFU;
          pFlash.ProcedureOnGoing = FLASH_PROC_NONE;
        }
      }
    }
  }
#endif 

  if(pFlash.ProcedureOnGoing == FLASH_PROC_NONE)
  {
#if defined(FLASH_BANK2_END)
    /* 操作完成，禁用两个 bank 的 PG, PER 和 MER 位 */
    CLEAR_BIT(FLASH->CR, (FLASH_CR_PG | FLASH_CR_PER | FLASH_CR_MER));
    CLEAR_BIT(FLASH->CR2, (FLASH_CR2_PG | FLASH_CR2_PER | FLASH_CR2_MER));  
  
    /* 禁用两个 bank 的 Flash 操作结束和错误源中断 */
    __HAL_FLASH_DISABLE_IT(FLASH_IT_EOP_BANK1 | FLASH_IT_ERR_BANK1 | FLASH_IT_EOP_BANK2 | FLASH_IT_ERR_BANK2);
#else
    /* 操作完成，禁用 PG, PER 和 MER 位 */
    CLEAR_BIT(FLASH->CR, (FLASH_CR_PG | FLASH_CR_PER | FLASH_CR_MER));

    /* 禁用 Flash 操作结束和错误源中断 */
    __HAL_FLASH_DISABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);
#endif /* FLASH_BANK2_END */

  }
}

/**
  * @brief  FLASH 操作结束中断回调函数
  * @param  ReturnValue: 此参数中保存的值取决于正在进行的过程
  *                 - Mass Erase: 无预期返回值
  *                 - Pages Erase: 已被擦除的页地址 
  *                    (如果是 0xFFFFFFFF，表示所有选定的页都已擦除)
  *                 - Program: 被选用于数据编程的地址
  * @retval 无
  */
__weak void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue)
{
  /* 防止未使用的参数编译警告 */
  UNUSED(ReturnValue);

  /* 注意：不应修改此函数，当需要回调时，
            HAL_FLASH_EndOfOperationCallback 可以在用户文件中实现
   */ 
}

/**
  * @brief  FLASH 操作错误中断回调函数
  * @param  ReturnValue: 此参数中保存的值取决于正在进行的过程
  *                 - Mass Erase: 无预期返回值
  *                 - Pages Erase: 返回错误的页地址
  *                 - Program: 被选用于数据编程的地址
  * @retval 无
  */
__weak void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{
  /* 防止未使用的参数编译警告 */
  UNUSED(ReturnValue);

  /* 注意：不应修改此函数，当需要回调时，
            HAL_FLASH_OperationErrorCallback 可以在用户文件中实现
   */ 
}

/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions_Group2 外设控制函数 
 *  @brief   管理函数 
 *
@verbatim   
 ===============================================================================
                      ##### 外设控制函数 #####
 ===============================================================================  
    [..]
    本小节提供一组允许控制 FLASH 存储器操作的函数。

@endverbatim
  * @{
  */

/**
  * @brief  解锁 FLASH 控制寄存器访问
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK; // 初始化状态为 OK

  if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET) // 检查 FLASH 是否已锁定
  {
    /* 授权访问 FLASH 寄存器 */
    WRITE_REG(FLASH->KEYR, FLASH_KEY1); // 写入钥匙 1
    WRITE_REG(FLASH->KEYR, FLASH_KEY2); // 写入钥匙 2

    /* 验证 Flash 是否已解锁 */
    if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET) // 再次检查锁定状态
    {
      status = HAL_ERROR; // 如果仍未解锁，返回错误
    }
  }
#if defined(FLASH_BANK2_END)
  if(READ_BIT(FLASH->CR2, FLASH_CR2_LOCK) != RESET) // 检查 Bank2 是否已锁定
  {
    /* 授权访问 FLASH BANK2 寄存器 */
    WRITE_REG(FLASH->KEYR2, FLASH_KEY1); // 写入钥匙 1
    WRITE_REG(FLASH->KEYR2, FLASH_KEY2); // 写入钥匙 2
    
    /* 验证 Flash BANK2 是否已解锁 */
    if(READ_BIT(FLASH->CR2, FLASH_CR2_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }
#endif /* FLASH_BANK2_END */

  return status; // 返回状态
}

/**
  * @brief  锁定 FLASH 控制寄存器访问
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_FLASH_Lock(void)
{
  /* 设置 LOCK 位以锁定 FLASH 寄存器访问 */
  SET_BIT(FLASH->CR, FLASH_CR_LOCK); // 设置锁定位
  
#if defined(FLASH_BANK2_END)
  /* 设置 LOCK 位以锁定 FLASH BANK2 寄存器访问 */
  SET_BIT(FLASH->CR2, FLASH_CR2_LOCK); // 设置 Bank2 锁定位

#endif /* FLASH_BANK2_END */
  return HAL_OK; // 返回 OK
}

/**
  * @brief  解锁 FLASH 选项控制寄存器访问。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void)
{
  if (HAL_IS_BIT_CLR(FLASH->CR, FLASH_CR_OPTWRE)) // 检查选项字节写使能位是否清除
  {
    /* 授权选项字节寄存器编程 */
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY1); // 写入选项钥匙 1
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY2); // 写入选项钥匙 2
  }
  else
  {
    return HAL_ERROR; // 如果已解锁，返回错误
  }  
  
  return HAL_OK; // 返回 OK
}

/**
  * @brief  锁定 FLASH 选项控制寄存器访问。
  * @retval HAL 状态 
  */
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void)
{
  /* 清除 OPTWRE 位以锁定 FLASH 选项字节寄存器访问 */
  CLEAR_BIT(FLASH->CR, FLASH_CR_OPTWRE); // 清除选项字节写使能位
  
  return HAL_OK; // 返回 OK
}
  
/**
  * @brief  启动选项字节加载。
  * @note   此函数将自动复位 MCU。
  * @retval 无
  */
void HAL_FLASH_OB_Launch(void)
{
  /* 发起系统复位请求以启动选项字节加载 */
  HAL_NVIC_SystemReset(); // 系统复位
}

/**
  * @}
  */  

/** @defgroup FLASH_Exported_Functions_Group3 外设错误函数 
 *  @brief    外设错误函数 
 *
@verbatim   
 ===============================================================================
                      ##### 外设错误函数 #####
 ===============================================================================  
    [..]
    本小节允许获取 FLASH 外设的运行时错误。

@endverbatim
  * @{
  */

/**
  * @brief  获取特定的 FLASH 错误标志。
  * @retval FLASH_ErrorCode 返回值可以是：
  *            @ref FLASH_Error_Codes
  */
uint32_t HAL_FLASH_GetError(void)
{
   return pFlash.ErrorCode; // 返回错误代码
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FLASH_Private_Functions
 * @{
 */

/**
  * @brief  在指定地址编程半字 (16-bit)。
  * @param  Address 指定要编程的地址。
  * @param  Data    指定要编程的数据。
  * @retval 无
  */
static void FLASH_Program_HalfWord(uint32_t Address, uint16_t Data)
{
  /* 清除错误上下文 */
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE; // 重置错误代码为无错误
  
#if defined(FLASH_BANK2_END)
  if(Address <= FLASH_BANK1_END)
  {
#endif /* FLASH_BANK2_END */
    /* 继续编程新数据 */
    SET_BIT(FLASH->CR, FLASH_CR_PG); // 设置编程使能位
#if defined(FLASH_BANK2_END)
  }
  else
  {
    /* 继续编程新数据 */
    SET_BIT(FLASH->CR2, FLASH_CR2_PG); // 设置 Bank2 编程使能位
  }
#endif /* FLASH_BANK2_END */

  /* 在地址中写入数据 */
  *(__IO uint16_t*)Address = Data; // 向指定地址写入 16 位数据
}

/**
  * @brief  等待 FLASH 操作完成。
  * @param  Timeout  最大 flash 操作超时时间
  * @retval HAL 状态
  */
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout)
{
  /* 等待 FLASH 操作完成，通过轮询 BUSY 标志复位。
     即使 FLASH 操作失败，BUSY 标志也会复位并设置错误标志 */
     
  uint32_t tickstart = HAL_GetTick(); // 获取当前滴答时间作为起始时间
     
  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY)) // 循环等待 BUSY 标志复位
  { 
    if (Timeout != HAL_MAX_DELAY) // 如果超时不是无限等待
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout)) // 检查是否超时
      {
        return HAL_TIMEOUT; // 返回超时状态
      }
    }
  }
  
  /* 检查 FLASH 操作结束标志 */
  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {
    /* 清除 FLASH 操作结束挂起位 */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR)  || // 检查写保护错误
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_OPTVERR) || // 检查选项字节错误
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR)) // 检查编程错误
  {
    /*保存错误代码*/
    FLASH_SetErrorCode();
    return HAL_ERROR; // 返回错误状态
  }

  /* 没有错误标志设置 */
  return HAL_OK; // 返回 OK 状态
}

#if defined(FLASH_BANK2_END)
/**
  * @brief  等待 FLASH BANK2 操作完成。
  * @param  Timeout 最大 flash 操作超时时间
  * @retval HAL_StatusTypeDef HAL 状态
  */
HAL_StatusTypeDef FLASH_WaitForLastOperationBank2(uint32_t Timeout)
{ 
  /* 等待 FLASH BANK2 操作完成，通过轮询 BUSY 标志复位。
     即使 FLASH BANK2 操作失败，BUSY 标志也会复位并设置错误标志 */
     
  uint32_t tickstart = HAL_GetTick(); // 获取当前滴答时间
     
  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY_BANK2)) // 循环等待 Bank2 BUSY 标志复位
  { 
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    }
  }
  
  /* 检查 FLASH 操作结束标志 */
  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP_BANK2))
  {
    /* 清除 FLASH 操作结束挂起位 */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK2);
  }

  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2))
  {
    /*保存错误代码*/
    FLASH_SetErrorCode();
    return HAL_ERROR;
  }

  /* 如果有错误标志设置 */
  return HAL_OK;
  
}
#endif /* FLASH_BANK2_END */

/**
  * @brief  设置特定的 FLASH 错误标志。
  * @retval 无
  */
static void FLASH_SetErrorCode(void)
{
  uint32_t flags = 0U; // 临时变量存储标志
  
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR)) // 检查写保护错误标志
#endif /* FLASH_BANK2_END */
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_WRP; // 设置写保护错误代码
#if defined(FLASH_BANK2_END)
    flags |= FLASH_FLAG_WRPERR | FLASH_FLAG_WRPERR_BANK2; // 记录需要清除的标志
#else
    flags |= FLASH_FLAG_WRPERR; // 记录需要清除的标志
#endif /* FLASH_BANK2_END */
  }
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR)) // 检查编程错误标志
#endif /* FLASH_BANK2_END */
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PROG; // 设置编程错误代码
#if defined(FLASH_BANK2_END)
    flags |= FLASH_FLAG_PGERR | FLASH_FLAG_PGERR_BANK2; // 记录需要清除的标志
#else
    flags |= FLASH_FLAG_PGERR; // 记录需要清除的标志
#endif /* FLASH_BANK2_END */
  }
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_OPTVERR)) // 检查选项字节错误
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_OPTV; // 设置选项字节错误代码
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR); // 清除选项字节错误标志
  }

  /* 清除 FLASH 错误挂起位 */
  __HAL_FLASH_CLEAR_FLAG(flags); // 清除记录的错误标志
}  
/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_FLASH_MODULE_ENABLED */

/**
  * @}
  */
