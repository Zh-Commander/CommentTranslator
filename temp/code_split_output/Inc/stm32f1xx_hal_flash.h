/**
  ******************************************************************************
  * @file    stm32f1xx_hal_flash.h
  * @author  MCD Application Team
  * @brief   Header file of Flash HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
// 防止递归包含
#ifndef __STM32F1xx_HAL_FLASH_H
#define __STM32F1xx_HAL_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含HAL库通用定义头文件
#include "stm32f1xx_hal_def.h"
   
/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */
  
/** @addtogroup FLASH_Private_Constants
  * @{
  */
// 定义Flash操作超时时间为50秒
#define FLASH_TIMEOUT_VALUE              50000U /* 50 s */
/**
  * @}
  */

/** @addtogroup FLASH_Private_Macros
  * @{
  */

// 判断编程类型参数是否合法
// 检查是否为半字、全字或双字编程
#define IS_FLASH_TYPEPROGRAM(VALUE)  (((VALUE) == FLASH_TYPEPROGRAM_HALFWORD) || \
                                      ((VALUE) == FLASH_TYPEPROGRAM_WORD)     || \
                                      ((VALUE) == FLASH_TYPEPROGRAM_DOUBLEWORD))  

#if   defined(FLASH_ACR_LATENCY)
// 判断延迟参数是否合法（适用于有延迟寄存器的设备）
#define IS_FLASH_LATENCY(__LATENCY__) (((__LATENCY__) == FLASH_LATENCY_0) || \
                                       ((__LATENCY__) == FLASH_LATENCY_1) || \
                                       ((__LATENCY__) == FLASH_LATENCY_2))

#else
// 判断延迟参数是否合法（适用于无延迟寄存器的设备）
#define IS_FLASH_LATENCY(__LATENCY__)   ((__LATENCY__) == FLASH_LATENCY_0)
#endif /* FLASH_ACR_LATENCY */
/**
  * @}
  */  

/* Exported types ------------------------------------------------------------*/ 
/** @defgroup FLASH_Exported_Types FLASH Exported Types
  * @{
  */  

/**
  * @brief  FLASH Procedure structure definition
  *         FLASH 操作过程枚举定义
  */
typedef enum 
{
  FLASH_PROC_NONE              = 0U,  // 无操作
  FLASH_PROC_PAGEERASE         = 1U,  // 页擦除操作
  FLASH_PROC_MASSERASE         = 2U,  // 全片擦除操作
  FLASH_PROC_PROGRAMHALFWORD   = 3U,  // 半字（16位）编程操作
  FLASH_PROC_PROGRAMWORD       = 4U,  // 全字（32位）编程操作
  FLASH_PROC_PROGRAMDOUBLEWORD = 5U   // 双字（64位）编程操作
} FLASH_ProcedureTypeDef;

/** 
  * @brief  FLASH handle Structure definition  
  *         FLASH 句柄结构体定义
  */
typedef struct
{
  // 内部变量，用于指示中断上下文中正在进行或未进行的操作过程
  __IO FLASH_ProcedureTypeDef ProcedureOnGoing; /*!< Internal variable to indicate which procedure is ongoing or not in IT context */
  
  // 内部变量，用于保存中断上下文中剩余待擦除的页数或待编程的半字数
  __IO uint32_t               DataRemaining;    /*!< Internal variable to save the remaining pages to erase or half-word to program in IT context */

  // 内部变量，用于保存选定的编程或擦除地址
  __IO uint32_t               Address;          /*!< Internal variable to save address selected for program or erase */

  // 内部变量，用于保存待编程的数据
  __IO uint64_t               Data;             /*!< Internal variable to save data to be programmed */

  // FLASH 锁定对象，用于资源保护
  HAL_LockTypeDef             Lock;             /*!< FLASH locking object                */

  // FLASH 错误代码，参数值可以是 @ref FLASH_Error_Codes 中的一个
  __IO uint32_t               ErrorCode;        /*!< FLASH error code                    
                                                     This parameter can be a value of @ref FLASH_Error_Codes  */
} FLASH_ProcessTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Constants FLASH Exported Constants
  * @{
  */  

/** @defgroup FLASH_Error_Codes FLASH Error Codes
  * @{
  */

// 无错误
#define HAL_FLASH_ERROR_NONE      0x00U  /*!< No error */
// 编程错误
#define HAL_FLASH_ERROR_PROG      0x01U  /*!< Programming error */
// 写保护错误
#define HAL_FLASH_ERROR_WRP       0x02U  /*!< Write protection error */
// 选项有效性错误
#define HAL_FLASH_ERROR_OPTV      0x04U  /*!< Option validity error */

/**
  * @}
  */

/** @defgroup FLASH_Type_Program FLASH Type Program
  * @{
  */ 
// 编程类型：半字（16位）
#define FLASH_TYPEPROGRAM_HALFWORD             0x01U  /*!<Program a half-word (16-bit) at a specified address.*/
// 编程类型：全字（32位）
#define FLASH_TYPEPROGRAM_WORD                 0x02U  /*!<Program a word (32-bit) at a specified address.*/
// 编程类型：双字（64位）
#define FLASH_TYPEPROGRAM_DOUBLEWORD           0x03U  /*!<Program a double word (64-bit) at a specified address*/

/**
  * @}
  */

#if   defined(FLASH_ACR_LATENCY)
/** @defgroup FLASH_Latency FLASH Latency
  * @{
  */
// FLASH 延迟周期：0个延迟周期
#define FLASH_LATENCY_0            0x00000000U               /*!< FLASH Zero Latency cycle */
// FLASH 延迟周期：1个延迟周期
#define FLASH_LATENCY_1            FLASH_ACR_LATENCY_0       /*!< FLASH One Latency cycle */
// FLASH 延迟周期：2个延迟周期
#define FLASH_LATENCY_2            FLASH_ACR_LATENCY_1       /*!< FLASH Two Latency cycles */

/**
  * @}
  */

#else
/** @defgroup FLASH_Latency FLASH Latency
  * @{
  */
// FLASH 延迟周期：0个延迟周期（适用于部分低密度设备）
#define FLASH_LATENCY_0            0x00000000U    /*!< FLASH Zero Latency cycle */

/**
  * @}
  */

#endif /* FLASH_ACR_LATENCY */
/**
  * @}
  */  
  
/* Exported macro ------------------------------------------------------------*/

/** @defgroup FLASH_Exported_Macros FLASH Exported Macros
 *  @brief macros to control FLASH features 
 *  @{
 */
 
/** @defgroup FLASH_Half_Cycle FLASH Half Cycle
 *  @brief macros to handle FLASH half cycle
 * @{
 */

/**
  * @brief  Enable the FLASH half cycle access.
  *         使能 FLASH 半周期访问
  * @note   half cycle access can only be used with a low-frequency clock of less than
            8 MHz that can be obtained with the use of HSI or HSE but not of PLL.
            半周期访问只能用于低于8MHz的低频时钟，可通过HSI或HSE获得，不能使用PLL。
  * @retval None
  */
#define __HAL_FLASH_HALF_CYCLE_ACCESS_ENABLE()  (FLASH->ACR |= FLASH_ACR_HLFCYA)

/**
  * @brief  Disable the FLASH half cycle access.
  *         禁止 FLASH 半周期访问
  * @note   half cycle access can only be used with a low-frequency clock of less than
            8 MHz that can be obtained with the use of HSI or HSE but not of PLL.
  * @retval None
  */
#define __HAL_FLASH_HALF_CYCLE_ACCESS_DISABLE() (FLASH->ACR &= (~FLASH_ACR_HLFCYA))

/**
  * @}
  */

#if defined(FLASH_ACR_LATENCY)
/** @defgroup FLASH_EM_Latency FLASH Latency
 *  @brief macros to handle FLASH Latency
 * @{
 */ 
  
/**
  * @brief  Set the FLASH Latency.
  *         设置 FLASH 延迟周期
  * @param  __LATENCY__ FLASH Latency                   
  *         The value of this parameter depend on device used within the same series
  *         该参数的值取决于同一系列中使用的具体设备
  * @retval None
  */ 
#define __HAL_FLASH_SET_LATENCY(__LATENCY__)    (FLASH->ACR = (FLASH->ACR&(~FLASH_ACR_LATENCY)) | (__LATENCY__))


/**
  * @brief  Get the FLASH Latency.
  *         获取 FLASH 延迟周期
  * @retval FLASH Latency                   
  *         The value of this parameter depend on device used within the same series
  *         返回当前的延迟周期设置
  */ 
#define __HAL_FLASH_GET_LATENCY()     (READ_BIT((FLASH->ACR), FLASH_ACR_LATENCY))

/**
  * @}
  */

#endif /* FLASH_ACR_LATENCY */
/** @defgroup FLASH_Prefetch FLASH Prefetch
 *  @brief macros to handle FLASH Prefetch buffer
 * @{
 */   
/**
  * @brief  Enable the FLASH prefetch buffer.
  *         使能 FLASH 预取指缓冲区
  * @retval None
  */ 
#define __HAL_FLASH_PREFETCH_BUFFER_ENABLE()    (FLASH->ACR |= FLASH_ACR_PRFTBE)

/**
  * @brief  Disable the FLASH prefetch buffer.
  *         禁止 FLASH 预取指缓冲区
  * @retval None
  */
#define __HAL_FLASH_PREFETCH_BUFFER_DISABLE()   (FLASH->ACR &= (~FLASH_ACR_PRFTBE))

/**
  * @}
  */
  
/**
  * @}
  */ 

/* Include FLASH HAL Extended module */
// 包含 FLASH HAL 扩展模块头文件
#include "stm32f1xx_hal_flash_ex.h"  

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASH_Exported_Functions
  * @{
  */
  
/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */
/* IO operation functions *****************************************************/
// 以轮询方式执行Flash编程
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
// 以中断方式执行Flash编程
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);

/* FLASH IRQ handler function */
// FLASH 中断处理函数
void       HAL_FLASH_IRQHandler(void);
/* Callbacks in non blocking modes */ 
// 操作完成回调函数（非阻塞模式）
void       HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
// 操作错误回调函数（非阻塞模式）
void       HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);

/**
  * @}
  */

/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */
/* Peripheral Control functions ***********************************************/
// 解锁Flash控制寄存器
HAL_StatusTypeDef HAL_FLASH_Unlock(void);
// 锁定Flash控制寄存器
HAL_StatusTypeDef HAL_FLASH_Lock(void);
// 解锁Flash选项字节
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
// 锁定Flash选项字节
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
// 加载选项字节并触发系统复位
void HAL_FLASH_OB_Launch(void);

/**
  * @}
  */

/** @addtogroup FLASH_Exported_Functions_Group3
  * @{
  */
/* Peripheral State and Error functions ***************************************/
// 获取Flash错误代码
uint32_t HAL_FLASH_GetError(void);

/**
  * @}
  */

/**
  * @}
  */

/* Private function -------------------------------------------------*/
/** @addtogroup FLASH_Private_Functions
 * @{
 */
// 等待上一次操作完成（私有函数）
HAL_StatusTypeDef       FLASH_WaitForLastOperation(uint32_t Timeout);
#if defined(FLASH_BANK2_END)
// 等待Bank2上一次操作完成（适用于大容量产品）
HAL_StatusTypeDef       FLASH_WaitForLastOperationBank2(uint32_t Timeout);
#endif /* FLASH_BANK2_END */

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
#endif

#endif /* __STM32F1xx_HAL_FLASH_H */
