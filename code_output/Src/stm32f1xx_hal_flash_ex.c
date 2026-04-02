/**
  ******************************************************************************
  * @file    stm32f1xx_hal_flash_ex.c
  * @author  MCD Application Team
  * @brief   FLASH扩展HAL模块驱动。
  *    
  *          本文件提供固件函数来管理FLASH外设的以下功能：
  *           + 扩展初始化/反初始化函数
  *           + 扩展输入/输出操作函数
  *           + 扩展外设控制函数 
  *         
  @verbatim
  ==============================================================================
               ##### Flash外设扩展特性 #####
  ==============================================================================
           
                      ##### 如何使用本驱动 #####
  ==============================================================================
  [..] 该驱动提供了配置和编程所有STM32F1xxx设备FLASH存储器的函数。
       它包括：
       
        (++) 设置/复位写保护
        (++) 编程用户选项字节
        (++) 获取读保护等级
  
  @endverbatim
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据许可条款授权，许可条款可在本软件组件根目录下的LICENSE文件中找到。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  ******************************************************************************
  */

/* 包含 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */
#ifdef HAL_FLASH_MODULE_ENABLED

/** @addtogroup FLASH
  * @{
  */
/** @addtogroup FLASH_Private_Variables
 * @{
 */
/* 用于中断下擦除页面的变量 */
extern FLASH_ProcessTypeDef pFlash;
/**
  * @}
  */

/**
  * @}
  */
  
/** @defgroup FLASHEx FLASHEx
  * @brief FLASH HAL扩展模块驱动
  * @{
  */

/* 私有类型定义 -----------------------------------------------------------*/
/* 私有定义 ------------------------------------------------------------*/
/** @defgroup FLASHEx_Private_Constants FLASHEx 私有常量
 * @{
 */
/* IWDG_SW位在OBR寄存器中的位置 */
#define FLASH_POSITION_IWDGSW_BIT        FLASH_OBR_IWDG_SW_Pos
/* 用户数据Data0在OBR寄存器中的位置 */
#define FLASH_POSITION_OB_USERDATA0_BIT  FLASH_OBR_DATA0_Pos
/* 用户数据Data1在OBR寄存器中的位置 */
#define FLASH_POSITION_OB_USERDATA1_BIT  FLASH_OBR_DATA1_Pos
/**
  * @}
  */

/* 私有宏 -------------------------------------------------------------*/
/** @defgroup FLASHEx_Private_Macros FLASHEx 私有宏
  * @{
  */
/**
  * @}
  */ 

/* 私有变量 ---------------------------------------------------------*/
/* 私有函数原型 ---------------------------------------------------------------*/
/** @defgroup FLASHEx_Private_Functions FLASHEx 私有函数
 * @{
 */
/* 擦除操作 */
static void              FLASH_MassErase(uint32_t Banks); // 全片擦除
void    FLASH_PageErase(uint32_t PageAddress); // 页擦除

/* 选项字节控制 */
static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WriteProtectPage); // 使能写保护
static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WriteProtectPage); // 禁止写保护
static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel); // 配置读保护等级
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint8_t UserConfig); // 用户配置
static HAL_StatusTypeDef FLASH_OB_ProgramData(uint32_t Address, uint8_t Data); // 编程用户数据
static uint32_t          FLASH_OB_GetWRP(void); // 获取写保护状态
static uint32_t          FLASH_OB_GetRDP(void); // 获取读保护等级
static uint8_t           FLASH_OB_GetUser(void); // 获取用户配置

/**
  * @}
  */

/* 导出函数 ---------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Functions FLASHEx 导出函数
  * @{
  */
  
/** @defgroup FLASHEx_Exported_Functions_Group1 FLASHEx 存储器擦除函数
 *  @brief   FLASH存储器擦除函数
  *
@verbatim   
  ==============================================================================
                ##### FLASH 擦除编程函数 ##### 
  ==============================================================================

    [..] FLASH存储器擦除函数包括以下函数：
    (+) HAL_FLASHEx_Erase: 仅在擦除完成后返回
    (+) HAL_FLASHEx_Erase_IT: 擦除结束时调用HAL_FLASH_EndOfOperationCallback 
        参数为0xFFFFFFFF

    [..] 任何擦除操作应遵循以下步骤：
    (#) 调用HAL_FLASH_Unlock()函数解锁FLASH控制寄存器和程序存储器访问。
    (#) 调用所需的函数擦除页面。
    (#) 调用HAL_FLASH_Lock()禁止FLASH程序存储器访问 
       (建议保护FLASH存储器防止可能的误操作)。

@endverbatim
  * @{
  */
  

/**
  * @brief  执行全片擦除或擦除指定的FLASH存储器页
  * @note   为了正确运行此函数，必须先调用@ref HAL_FLASH_Unlock()函数。
  *         调用@ref HAL_FLASH_Lock()禁止FLASH存储器访问 
  *         (建议保护FLASH存储器防止可能的误操作)
  * @param[in]  pEraseInit 指向FLASH_EraseInitTypeDef结构体的指针，
  *         该结构体包含擦除的配置信息。
  *
  * @param[out]  PageError 指向变量的指针，
  *         在发生错误时该变量包含错误页面的配置信息
  *         (0xFFFFFFFF表示所有页面已正确擦除)
  *
  * @retval HAL_StatusTypeDef HAL状态
  */
HAL_StatusTypeDef HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError)
{
  HAL_StatusTypeDef status = HAL_ERROR; // 初始化状态为错误
  uint32_t address = 0U; // 地址变量

  /* 进程锁定 */
  __HAL_LOCK(&pFlash);

  /* 检查参数 */
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  if (pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE) // 如果是全片擦除
  {
#if defined(FLASH_BANK2_END)
    if (pEraseInit->Banks == FLASH_BANK_BOTH) // 如果请求擦除Bank1和Bank2
    {
      /* 请求对Bank1和Bank2进行全片擦除 */
      /* 等待上次操作完成 */
      if ((FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK) && \
          (FLASH_WaitForLastOperationBank2((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK))
      {
        /* 执行全片擦除 */
        FLASH_MassErase(FLASH_BANK_BOTH);
        
        /* 等待上次操作完成 */
        if ((FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK) && \
            (FLASH_WaitForLastOperationBank2((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK))
        {
          status = HAL_OK; // 操作成功
        }
        
        /* 如果擦除操作完成，禁用MER位 */
        CLEAR_BIT(FLASH->CR, FLASH_CR_MER);
        CLEAR_BIT(FLASH->CR2, FLASH_CR2_MER);
      }
    }
    else if (pEraseInit->Banks == FLASH_BANK_2) // 如果请求擦除Bank2
    {
      /* 请求对Bank2进行全片擦除 */
      /* 等待上次操作完成 */
      if (FLASH_WaitForLastOperationBank2((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {
        /* 执行全片擦除 */
        FLASH_MassErase(FLASH_BANK_2);
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperationBank2((uint32_t)FLASH_TIMEOUT_VALUE);
        
        /* 如果擦除操作完成，禁用MER位 */
        CLEAR_BIT(FLASH->CR2, FLASH_CR2_MER);
      }
    }
    else 
#endif /* FLASH_BANK2_END */
    {
      /* 请求对Bank1进行全片擦除 */
      /* 等待上次操作完成 */
      if (FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {
        /* 执行全片擦除 */
        FLASH_MassErase(FLASH_BANK_1);
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
        
        /* 如果擦除操作完成，禁用MER位 */
        CLEAR_BIT(FLASH->CR, FLASH_CR_MER);
      }
    }
  }
  else // 如果是页擦除
  {
    /* 请求页擦除 */
    /* 检查参数 */
    assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->PageAddress));
    assert_param(IS_FLASH_NB_PAGES(pEraseInit->PageAddress, pEraseInit->NbPages));
    
#if defined(FLASH_BANK2_END)
    /* 请求擦除位于bank2上的地址 */
    if(pEraseInit->PageAddress > FLASH_BANK1_END)
    {   
      /* 等待上次操作完成 */
      if (FLASH_WaitForLastOperationBank2((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {
        /* 初始化PageError变量 */
        *PageError = 0xFFFFFFFFU;
        
        /* 逐页执行擦除 */
        for(address = pEraseInit->PageAddress;
            address < (pEraseInit->PageAddress + (pEraseInit->NbPages)*FLASH_PAGE_SIZE);
            address += FLASH_PAGE_SIZE)
        {
          FLASH_PageErase(address); // 擦除指定页
          
          /* 等待上次操作完成 */
          status = FLASH_WaitForLastOperationBank2((uint32_t)FLASH_TIMEOUT_VALUE);
          
          /* 如果擦除操作完成，禁用PER位 */
          CLEAR_BIT(FLASH->CR2, FLASH_CR2_PER);
          
          if (status != HAL_OK)
          {
            /* 如果发生错误，停止擦除过程并返回错误地址 */
            *PageError = address;
            break;
          }
        }
      }
    }
    else
#endif /* FLASH_BANK2_END */
   {
      /* 请求擦除位于bank1上的地址 */
      /* 等待上次操作完成 */
      if (FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE) == HAL_OK)
      {
        /* 初始化PageError变量 */
        *PageError = 0xFFFFFFFFU;
        
        /* 逐页执行擦除 */
        for(address = pEraseInit->PageAddress;
            address < ((pEraseInit->NbPages * FLASH_PAGE_SIZE) + pEraseInit->PageAddress);
            address += FLASH_PAGE_SIZE)
        {
          FLASH_PageErase(address); // 擦除指定页
          
          /* 等待上次操作完成 */
          status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
          
          /* 如果擦除操作完成，禁用PER位 */
          CLEAR_BIT(FLASH->CR, FLASH_CR_PER);
          
          if (status != HAL_OK)
          {
            /* 如果发生错误，停止擦除过程并返回错误地址 */
            *PageError = address;
            break;
          }
        }
      }
    }
  }

  /* 进程解锁 */
  __HAL_UNLOCK(&pFlash);

  return status; // 返回操作状态
}

/**
  * @brief  执行全片擦除或擦除指定的FLASH存储器页，并使能中断
  * @note   为了正确运行此函数，必须先调用@ref HAL_FLASH_Unlock()函数。
  *         调用@ref HAL_FLASH_Lock()禁止FLASH存储器访问 
  *         (建议保护FLASH存储器防止可能的误操作)
  * @param  pEraseInit 指向FLASH_EraseInitTypeDef结构体的指针，
  *         该结构体包含擦除的配置信息。
  *
  * @retval HAL_StatusTypeDef HAL状态
  */
HAL_StatusTypeDef HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* 如果进程已经在进行中，拒绝下一个请求 */
  if (pFlash.ProcedureOnGoing != FLASH_PROC_NONE)
  {
    return HAL_ERROR;
  }
  
  /* 检查参数 */
  assert_param(IS_FLASH_TYPEERASE(pEraseInit->TypeErase));

  /* 使能FLASH操作结束和错误源中断 */
  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP | FLASH_IT_ERR);

#if defined(FLASH_BANK2_END)
  /* 使能Bank2的FLASH操作结束和错误源中断 */
  __HAL_FLASH_ENABLE_IT(FLASH_IT_EOP_BANK2 | FLASH_IT_ERR_BANK2);
  
#endif
  if (pEraseInit->TypeErase == FLASH_TYPEERASE_MASSERASE) // 如果是全片擦除
  {
    /* 执行全片擦除 */
    pFlash.ProcedureOnGoing = FLASH_PROC_MASSERASE; // 标记当前正在进行全片擦除
        FLASH_MassErase(pEraseInit->Banks);
  }
  else // 如果是页擦除
  {
    /* 执行页擦除 */

    /* 检查参数 */
    assert_param(IS_FLASH_PROGRAM_ADDRESS(pEraseInit->PageAddress));
    assert_param(IS_FLASH_NB_PAGES(pEraseInit->PageAddress, pEraseInit->NbPages));

    pFlash.ProcedureOnGoing = FLASH_PROC_PAGEERASE; // 标记当前正在进行页擦除
    pFlash.DataRemaining = pEraseInit->NbPages; // 记录剩余待擦除页数
    pFlash.Address = pEraseInit->PageAddress; // 记录起始地址

    /* 擦除第一页并等待中断 */
    FLASH_PageErase(pEraseInit->PageAddress);
  }

  return status;
}

/**
  * @}
  */

/** @defgroup FLASHEx_Exported_Functions_Group2 选项字节编程函数
 *  @brief   选项字节编程函数
  *
@verbatim   
  ==============================================================================
                ##### 选项字节编程函数 ##### 
  ==============================================================================  
    [..]
    本小节提供了一组允许控制FLASH选项字节操作的函数。

@endverbatim
  * @{
  */

/**
  * @brief  擦除FLASH选项字节。
  * @note   此函数擦除除读保护(RDP)以外的所有选项字节。
  *         在解锁FLASH接口之前应调用@ref HAL_FLASH_Unlock()函数
  *         在解锁选项字节之前应调用@ref HAL_FLASH_OB_Unlock()函数
  *         在强制重新加载选项字节之后应调用@ref HAL_FLASH_OB_Launch()函数
  *         (将发生系统复位)
  * @retval HAL status HAL状态
  */

HAL_StatusTypeDef HAL_FLASHEx_OBErase(void)
{
  uint8_t rdptmp = OB_RDP_LEVEL_0; // 临时变量存储读保护等级
  HAL_StatusTypeDef status = HAL_ERROR;

  /* 获取实际的读保护选项字节值 */
  rdptmp = FLASH_OB_GetRDP();

  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  {
    /* 清除错误上下文 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 如果上一次操作完成，继续擦除选项字节 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTER); // 设置选项字节擦除使能位
    SET_BIT(FLASH->CR, FLASH_CR_STRT); // 启动擦除操作

    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* 如果擦除操作完成，禁用OPTER位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTER);

    if(status == HAL_OK)
    {
      /* 恢复上次的读保护选项字节值 */
      status = FLASH_OB_RDP_LevelConfig(rdptmp);
    }
  }

  /* 返回擦除状态 */
  return status;
}

/**
  * @brief  编程选项字节
  * @note   在解锁FLASH接口之前应调用@ref HAL_FLASH_Unlock()函数
  *         在解锁选项字节之前应调用@ref HAL_FLASH_OB_Unlock()函数
  *         在强制重新加载选项字节之后应调用@ref HAL_FLASH_OB_Launch()函数
  *         (将发生系统复位)
  *
  * @param  pOBInit 指向FLASH_OBInitStruct结构体的指针，
  *         该结构体包含编程的配置信息。
  *
  * @retval HAL_StatusTypeDef HAL状态
  */
HAL_StatusTypeDef HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit)
{
  HAL_StatusTypeDef status = HAL_ERROR;

  /* 进程锁定 */
  __HAL_LOCK(&pFlash);

  /* 检查参数 */
  assert_param(IS_OPTIONBYTE(pOBInit->OptionType));

  /* 写保护配置 */
  if((pOBInit->OptionType & OPTIONBYTE_WRP) == OPTIONBYTE_WRP)
  {
    assert_param(IS_WRPSTATE(pOBInit->WRPState));
    if (pOBInit->WRPState == OB_WRPSTATE_ENABLE)
    {
      /* 使能所选页面的写保护 */
      status = FLASH_OB_EnableWRP(pOBInit->WRPPage);
    }
    else
    {
      /* 禁止所选页面的写保护 */
      status = FLASH_OB_DisableWRP(pOBInit->WRPPage);
    }
    if (status != HAL_OK)
    {
      /* 进程解锁 */
      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }

  /* 读保护配置 */
  if((pOBInit->OptionType & OPTIONBYTE_RDP) == OPTIONBYTE_RDP)
  {
    status = FLASH_OB_RDP_LevelConfig(pOBInit->RDPLevel);
    if (status != HAL_OK)
    {
      /* 进程解锁 */
      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }

  /* 用户配置 */
  if((pOBInit->OptionType & OPTIONBYTE_USER) == OPTIONBYTE_USER)
  {
    status = FLASH_OB_UserConfig(pOBInit->USERConfig);
    if (status != HAL_OK)
    {
      /* 进程解锁 */
      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }

  /* 数据配置 */
  if((pOBInit->OptionType & OPTIONBYTE_DATA) == OPTIONBYTE_DATA)
  {
    status = FLASH_OB_ProgramData(pOBInit->DATAAddress, pOBInit->DATAData);
    if (status != HAL_OK)
    {
      /* 进程解锁 */
      __HAL_UNLOCK(&pFlash);
      return status;
    }
  }

  /* 进程解锁 */
  __HAL_UNLOCK(&pFlash);

  return status;
}

/**
  * @brief  获取选项字节配置
  * @param  pOBInit 指向FLASH_OBInitStruct结构体的指针，
  *         该结构体包含编程的配置信息。
  *
  * @retval None 无
  */
void HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit)
{
  pOBInit->OptionType = OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER; // 设置选项类型

  /* 获取WRP(写保护) */
  pOBInit->WRPPage = FLASH_OB_GetWRP();

  /* 获取RDP Level(读保护等级) */
  pOBInit->RDPLevel = FLASH_OB_GetRDP();

  /* 获取USER(用户配置) */
  pOBInit->USERConfig = FLASH_OB_GetUser();
}

/**
  * @brief  获取选项字节用户数据
  * @param  DATAAdress 选项字节DATA的地址
  *          该参数可以是以下值之一：
  *            @arg @ref OB_DATA_ADDRESS_DATA0
  *            @arg @ref OB_DATA_ADDRESS_DATA1
  * @retval 编程在USER数据中的值
  */
uint32_t HAL_FLASHEx_OBGetUserData(uint32_t DATAAdress)
{
  uint32_t value = 0;
  
  if (DATAAdress == OB_DATA_ADDRESS_DATA0)
  {
    /* 获取OB USER Data0中编程的值 */
    value = READ_BIT(FLASH->OBR, FLASH_OBR_DATA0) >> FLASH_POSITION_OB_USERDATA0_BIT;
  }
  else
  {
    /* 获取OB USER Data1中编程的值 */
    value = READ_BIT(FLASH->OBR, FLASH_OBR_DATA1) >> FLASH_POSITION_OB_USERDATA1_BIT;
  }
  
  return value;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FLASHEx_Private_Functions
 * @{
 */

/**
  * @brief  FLASH存储器Bank全片擦除 
  * @param  Banks 要擦除的Bank
  *          该参数可以是以下值之一：
  *            @arg @ref FLASH_BANK_1 擦除Bank1
  @if STM32F101xG
  *            @arg @ref FLASH_BANK_2 擦除Bank2
  *            @arg @ref FLASH_BANK_BOTH 擦除Bank1和Bank2
  @endif
  @if STM32F103xG
  *            @arg @ref FLASH_BANK_2 擦除Bank2
  *            @arg @ref FLASH_BANK_BOTH 擦除Bank1和Bank2
  @endif
  *
  * @retval None 无
  */
static void FLASH_MassErase(uint32_t Banks)
{
  /* 检查参数 */
  assert_param(IS_FLASH_BANK(Banks));

  /* 清除错误上下文 */
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

#if defined(FLASH_BANK2_END)
  if(Banks == FLASH_BANK_BOTH) // 如果擦除Bank1和Bank2
  {
    /* bank1 & bank2 将被擦除 */
    SET_BIT(FLASH->CR, FLASH_CR_MER); // 设置Bank1全片擦除使能位
    SET_BIT(FLASH->CR2, FLASH_CR2_MER); // 设置Bank2全片擦除使能位
    SET_BIT(FLASH->CR, FLASH_CR_STRT); // 启动Bank1擦除
    SET_BIT(FLASH->CR2, FLASH_CR2_STRT); // 启动Bank2擦除
  }
  else if(Banks == FLASH_BANK_2) // 如果只擦除Bank2
  {
    /* 仅bank2将被擦除 */
    SET_BIT(FLASH->CR2, FLASH_CR2_MER); // 设置Bank2全片擦除使能位
    SET_BIT(FLASH->CR2, FLASH_CR2_STRT); // 启动Bank2擦除
  }
  else
  {
#endif /* FLASH_BANK2_END */
#if !defined(FLASH_BANK2_END)
  /* 防止未使用的参数编译警告 */
  UNUSED(Banks);
#endif /* FLASH_BANK2_END */  
    /* 仅bank1将被擦除 */
    SET_BIT(FLASH->CR, FLASH_CR_MER); // 设置Bank1全片擦除使能位
    SET_BIT(FLASH->CR, FLASH_CR_STRT); // 启动Bank1擦除
#if defined(FLASH_BANK2_END)
  }
#endif /* FLASH_BANK2_END */
}
/**
  * @brief  使能（开启）指定页面的写保护功能
  * @note   在此函数中会自动执行选项字节擦除操作。
  * @note   当选择了内存读保护级别（RDP level = 1）时，
  *         如果连接了调试功能或在RAM中执行启动代码，则无法编程或擦除Flash页面i，
  *         即使nWRPi = 1也是如此。
  * 
  * @param  WriteProtectPage 指定要被写保护的页面。
  *         此参数的值取决于同一系列中使用的具体设备型号。
  * @retval HAL状态 (HAL_OK, HAL_ERROR, HAL_BUSY, HAL_TIMEOUT)
  */
static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量，初始化为OK
  uint16_t WRP0_Data = 0xFFFF;       // 定义WRP0数据变量，初始化为0xFFFF（全1表示无保护）
#if defined(FLASH_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFF;       // 如果定义了WRP1，则初始化WRP1数据
#endif /* FLASH_WRP1_WRP1 */
#if defined(FLASH_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFF;       // 如果定义了WRP2，则初始化WRP2数据
#endif /* FLASH_WRP2_WRP2 */
#if defined(FLASH_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFF;       // 如果定义了WRP3，则初始化WRP3数据
#endif /* FLASH_WRP3_WRP3 */
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_WRP(WriteProtectPage));
    
  /* 获取当前受写保护的页面，并计算新的需要保护的页面 ******/
  /* 逻辑解释：先获取当前保护状态，按位或上新的保护页，再取反。
     因为WRP寄存器中位为0表示保护，为1表示未保护。
     (~FLASH_OB_GetWRP()) 获取当前已保护的位(变为1)，
     | WriteProtectPage 加上新增的保护位，
     最后整体取反，使得需要保护的位置0，保持未保护的位置1 */
  WriteProtectPage = (uint32_t)(~((~FLASH_OB_GetWRP()) | WriteProtectPage));
  
#if defined(OB_WRP_PAGES0TO15MASK)
  // 提取低8位数据，对应0-15页的保护信息
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#elif defined(OB_WRP_PAGES0TO31MASK)
  // 提取低8位数据，对应0-31页的保护信息
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO31MASK);
#endif /* OB_WRP_PAGES0TO31MASK */
  
#if defined(OB_WRP_PAGES16TO31MASK)
  // 提取次低8位数据，对应16-31页，右移8位对齐
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#elif defined(OB_WRP_PAGES32TO63MASK)
  // 提取次低8位数据，对应32-63页，右移8位对齐
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO63MASK) >> 8U);
#endif /* OB_WRP_PAGES32TO63MASK */
 
#if defined(OB_WRP_PAGES64TO95MASK)
  // 提取次高8位数据，对应64-95页，右移16位对齐
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES64TO95MASK) >> 16U);
#endif /* OB_WRP_PAGES64TO95MASK */
#if defined(OB_WRP_PAGES32TO47MASK)
  // 提取次高8位数据，对应32-47页，右移16位对齐
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif /* OB_WRP_PAGES32TO47MASK */

#if defined(OB_WRP_PAGES96TO127MASK)
  // 提取高8位数据，对应96-127页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES96TO127MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO255MASK)
  // 提取高8位数据，对应48-255页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO511MASK)
  // 提取高8位数据，对应48-511页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO511MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO127MASK)
  // 提取高8位数据，对应48-127页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U); 
#endif /* OB_WRP_PAGES96TO127MASK */
  
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 为了能够再次写入选项字节，需要执行选项字节擦除 */
    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)  
    {
      /* 使能选项字节编程操作 */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(FLASH_WRP0_WRP0)
      // 如果WRP0数据不是0xFF（即有页面需要保护），则进行编程
      if(WRP0_Data != 0xFFU)
      {
        // 写入WRP0寄存器，使用与运算（因为擦除后是全1，写入0生效）
        OB->WRP0 &= WRP0_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP0_WRP0 */

#if defined(FLASH_WRP1_WRP1)
      // 如果状态OK且WRP1数据有效，则编程WRP1
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 &= WRP1_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP1_WRP1 */

#if defined(FLASH_WRP2_WRP2)
      // 如果状态OK且WRP2数据有效，则编程WRP2
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 &= WRP2_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP2_WRP2 */

#if defined(FLASH_WRP3_WRP3)
      // 如果状态OK且WRP3数据有效，则编程WRP3
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 &= WRP3_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP3_WRP3 */

      /* 如果编程操作完成，禁用OPTPG位 */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  
  return status; // 返回操作状态
}

/**
  * @brief  失能（关闭）指定页面的写保护功能
  * @note   在此函数中会自动执行选项字节擦除操作。
  * @note   当选择了内存读保护级别（RDP level = 1）时，
  *         如果连接了调试功能或在RAM中执行启动代码，则无法编程或擦除Flash页面i，
  *         即使nWRPi = 1也是如此。
  * 
  * @param  WriteProtectPage 指定要解除写保护的页面。
  *         此参数的值取决于同一系列中使用的具体设备型号。
  * @retval HAL状态 (HAL_OK, HAL_ERROR, HAL_BUSY, HAL_TIMEOUT)
  */
static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量
  uint16_t WRP0_Data = 0xFFFF;       // 定义WRP0数据变量
#if defined(FLASH_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFF;       // 如果定义了WRP1，则初始化WRP1数据
#endif /* FLASH_WRP1_WRP1 */
#if defined(FLASH_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFF;       // 如果定义了WRP2，则初始化WRP2数据
#endif /* FLASH_WRP2_WRP2 */
#if defined(FLASH_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFF;       // 如果定义了WRP3，则初始化WRP3数据
#endif /* FLASH_WRP3_WRP3 */
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_WRP(WriteProtectPage));

  /* 获取当前受写保护的页面，并计算新的需要解除保护的页面 ******/
  /* 逻辑解释：解除保护意味着将对应位置1。
     FLASH_OB_GetWRP() 获取当前状态，
     | WriteProtectPage 将需要解除保护的位置1，
     结果即为新的保护状态（0为保护，1为未保护） */
  WriteProtectPage = (FLASH_OB_GetWRP() | WriteProtectPage);

#if defined(OB_WRP_PAGES0TO15MASK)
  // 提取低8位数据
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#elif defined(OB_WRP_PAGES0TO31MASK)
  // 提取低8位数据
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO31MASK);
#endif /* OB_WRP_PAGES0TO31MASK */
  
#if defined(OB_WRP_PAGES16TO31MASK)
  // 提取次低8位数据，右移8位
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#elif defined(OB_WRP_PAGES32TO63MASK)
  // 提取次低8位数据，右移8位
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO63MASK) >> 8U);
#endif /* OB_WRP_PAGES32TO63MASK */
 
#if defined(OB_WRP_PAGES64TO95MASK)
  // 提取次高8位数据，右移16位
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES64TO95MASK) >> 16U);
#endif /* OB_WRP_PAGES64TO95MASK */
#if defined(OB_WRP_PAGES32TO47MASK)
  // 提取次高8位数据，右移16位
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif /* OB_WRP_PAGES32TO47MASK */

#if defined(OB_WRP_PAGES96TO127MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES96TO127MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO255MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO511MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO511MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO127MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U); 
#endif /* OB_WRP_PAGES96TO127MASK */

    
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 为了能够再次写入选项字节，需要执行选项字节擦除 */
    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)  
    {
      /* 使能选项字节编程操作 */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(FLASH_WRP0_WRP0)
      // 如果WRP0数据不是0xFF（即有页面需要解除保护），则进行编程
      if(WRP0_Data != 0xFFU)
      {
        // 写入WRP0寄存器，使用或运算（将对应位置1以解除保护）
        OB->WRP0 |= WRP0_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP0_WRP0 */

#if defined(FLASH_WRP1_WRP1)
      // 如果状态OK且WRP1数据有效，则编程WRP1
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 |= WRP1_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP1_WRP1 */

#if defined(FLASH_WRP2_WRP2)
      // 如果状态OK且WRP2数据有效，则编程WRP2
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 |= WRP2_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP2_WRP2 */

#if defined(FLASH_WRP3_WRP3)
      // 如果状态OK且WRP3数据有效，则编程WRP3
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 |= WRP3_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP3_WRP3 */

      /* 如果编程操作完成，禁用OPTPG位 */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  return status; // 返回操作状态
}

/**
  * @brief  设置读保护级别。
  * @param  ReadProtectLevel 指定读保护级别。
  *         该参数可以是以下值之一：
  *            @arg @ref OB_RDP_LEVEL_0 无保护
  *            @arg @ref OB_RDP_LEVEL_1 内存读保护
  * @retval HAL状态
  */
static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_RDP_LEVEL(ReadProtectLevel));
  
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  { 
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;
    
    /* 如果上一步操作完成，开始擦除选项字节 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTER); // 使能选项字节擦除
    SET_BIT(FLASH->CR, FLASH_CR_STRT);  // 启动擦除操作

    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* 如果擦除操作完成，禁用OPTER位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTER);

    if(status == HAL_OK)
    {
      /* 使能选项字节编程操作 */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);
      
      // 写入新的RDP值到RDP寄存器
      WRITE_REG(OB->RDP, ReadProtectLevel);
      
      /* 等待上次操作完成 */
      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE); 
      
      /* 如果编程操作完成，禁用OPTPG位 */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  
  return status; // 返回操作状态
}

/**
  * @brief  编程FLASH用户选项字节。
  * @note   选项字节的编程应仅在擦除后执行（否则会发生PGERR错误）。
  * @param  UserConfig FLASH用户选项字节值：FLASH_OBR_IWDG_SW(Bit2),
  *         FLASH_OBR_nRST_STOP(Bit3),FLASH_OBR_nRST_STDBY(Bit4).
  *         对于STM32F101xG和STM32F103xG还有BFBF2(Bit5)。
  * @retval HAL状态
  */
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint8_t UserConfig)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量

  /* 检查参数是否合法 */
  assert_param(IS_OB_IWDG_SOURCE((UserConfig&OB_IWDG_SW))); // 检查看门狗配置
  assert_param(IS_OB_STOP_SOURCE((UserConfig&OB_STOP_NO_RST))); // 检查停止模式复位配置
  assert_param(IS_OB_STDBY_SOURCE((UserConfig&OB_STDBY_NO_RST))); // 检查待机模式复位配置
#if defined(FLASH_BANK2_END)
  assert_param(IS_OB_BOOT1((UserConfig&OB_BOOT1_SET))); // 检查BOOT1配置（仅大容量双Bank设备）
#endif /* FLASH_BANK2_END */

  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {     
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 使能选项字节编程操作 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTPG); 
 
#if defined(FLASH_BANK2_END)
    // 对于双Bank设备，配置用户字节，高4位保留置1 (0xF0)
    OB->USER = (UserConfig | 0xF0U);
#else
    // 对于单Bank设备，配置用户字节，高5位保留置1 (0x88对应位操作，实际是设置保留位)
    OB->USER = (UserConfig | 0x88U);
#endif /* FLASH_BANK2_END */

    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* 如果编程操作完成，禁用OPTPG位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }
  
  return status; // 返回操作状态
}

/**
  * @brief  在指定的选项字节数据地址编程半字。
  * @note   在调用此函数前应调用 @ref HAL_FLASH_Unlock() 解锁FLASH接口
  *         在调用此函数前应调用 @ref HAL_FLASH_OB_Unlock() 解锁选项字节
  *         在调用此函数后应调用 @ref HAL_FLASH_OB_Launch() 强制重载选项字节
  *         （会发生系统复位）
  *         选项字节的编程应仅在擦除后执行（否则会发生PGERR错误）。
  * @param  Address 指定要编程的地址。
  *         此参数可以是 0x1FFFF804 或 0x1FFFF806（Data0和Data1）。
  * @param  Data 指定要编程的数据。
  * @retval HAL状态
  */
static HAL_StatusTypeDef FLASH_OB_ProgramData(uint32_t Address, uint8_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR; // 定义状态变量，初始化为ERROR
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_DATA_ADDRESS(Address));
  
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 使能选项字节编程操作 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTPG); 
    // 向指定地址写入数据（强制转换为16位指针访问）
    *(__IO uint16_t*)Address = Data;
    
    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
    
    /* 如果编程操作完成，禁用OPTPG位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }
  /* 返回选项字节数据编程状态 */
  return status;
}

/**
  * @brief  返回FLASH写保护选项字节值。
  * @retval FLASH写保护选项字节值
  */
static uint32_t FLASH_OB_GetWRP(void)
{
  /* 返回FLASH写保护寄存器值 */
  return (uint32_t)(READ_REG(FLASH->WRPR));
}

/**
  * @brief  返回FLASH读保护级别。
  * @retval FLASH RDP级别
  *         该参数可以是以下值之一：
  *            @arg @ref OB_RDP_LEVEL_0 无保护
  *            @arg @ref OB_RDP_LEVEL_1 内存读保护
  */
static uint32_t FLASH_OB_GetRDP(void)
{
  uint32_t readstatus = OB_RDP_LEVEL_0; // 定义读状态变量，默认为Level 0
  uint32_t tmp_reg = 0U; // 定义临时寄存器变量
  
  /* 读取RDP级别位 */
  tmp_reg = READ_BIT(FLASH->OBR, FLASH_OBR_RDPRT);

  if (tmp_reg == FLASH_OBR_RDPRT)
  {
    readstatus = OB_RDP_LEVEL_1; // 如果标志位置位，则为Level 1
  }
  else 
  {
    readstatus = OB_RDP_LEVEL_0; // 否则为Level 0
  }

  return readstatus; // 返回读保护状态
}

/**
  * @brief  返回FLASH用户选项字节值。
  * @retval FLASH用户选项字节值：FLASH_OBR_IWDG_SW(Bit2),
  *         FLASH_OBR_nRST_STOP(Bit3),FLASH_OBR_nRST_STDBY(Bit4).
  *         对于STM32F101xG和STM32F103xG还有FLASH_OBR_BFB2(Bit5)。
  */
static uint8_t FLASH_OB_GetUser(void)
{
  /* 返回用户选项字节 */
  // 读取OBR寄存器，屏蔽出用户位，并右移到最低位
  return (uint8_t)((READ_REG(FLASH->OBR) & FLASH_OBR_USER) >> FLASH_POSITION_IWDGSW_BIT);
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FLASH
  * @{
  */

/** @addtogroup FLASH_Private_Functions
 * @{
 */

/**
  * @brief  擦除指定的FLASH内存页
  * @param  PageAddress 要擦除的FLASH页地址
  *         此参数的值取决于同一系列中使用的具体设备型号
  * 
  * @retval 无
  */
void FLASH_PageErase(uint32_t PageAddress)
{
  /* 清除错误标志 */
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

#if defined(FLASH_BANK2_END)
  // 如果定义了BANK2结束地址，说明是大容量双Bank设备
  if(PageAddress > FLASH_BANK1_END)
  { 
    /* 如果地址在BANK2范围内，执行BANK2页擦除 */
    SET_BIT(FLASH->CR2, FLASH_CR2_PER); // 设置BANK2页擦除标志
    WRITE_REG(FLASH->AR2, PageAddress); // 写入BANK2擦除地址
    SET_BIT(FLASH->CR2, FLASH_CR2_STRT); // 启动BANK2擦除
  }
  else
  {
#endif /* FLASH_BANK2_END */
    /* 执行BANK1页擦除 */
    SET_BIT(FLASH->CR, FLASH_CR_PER);  // 设置BANK1页擦除标志
    WRITE_REG(FLASH->AR, PageAddress); // 写入BANK1擦除地址
    SET_BIT(FLASH->CR, FLASH_CR_STRT); // 启动BANK1擦除
#if defined(FLASH_BANK2_END)
  }
#endif /* FLASH_BANK2_END */
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
