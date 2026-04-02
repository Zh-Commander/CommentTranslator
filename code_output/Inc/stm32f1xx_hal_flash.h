/**
  ******************************************************************************
  * @file    stm32f1xx_hal_flash.h
  * @author  MCD Application Team
  * @brief   Flash HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录中的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_FLASH_H
#define __STM32F1xx_HAL_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
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
/* Flash操作超时时间定义，单位为毫秒，此处为50秒 */
#define FLASH_TIMEOUT_VALUE              50000U 
/**
  * @}
  */

/** @addtogroup FLASH_Private_Macros
  * @{
  */

/* 检查Flash编程类型参数是否合法
   支持的类型：半字(16位)、字(32位)、双字(64位) */
#define IS_FLASH_TYPEPROGRAM(VALUE)  (((VALUE) == FLASH_TYPEPROGRAM_HALFWORD) || \
                                      ((VALUE) == FLASH_TYPEPROGRAM_WORD)     || \
                                      ((VALUE) == FLASH_TYPEPROGRAM_DOUBLEWORD))  

#if   defined(FLASH_ACR_LATENCY)
/* 检查Flash延迟周期参数是否合法 
   部分型号支持0、1、2个延迟周期 */
#define IS_FLASH_LATENCY(__LATENCY__) (((__LATENCY__) == FLASH_LATENCY_0) || \
                                       ((__LATENCY__) == FLASH_LATENCY_1) || \
                                       ((__LATENCY__) == FLASH_LATENCY_2))

#else
/* 检查Flash延迟周期参数是否合法 
   部分型号仅支持0个延迟周期 */
#define IS_FLASH_LATENCY(__LATENCY__)   ((__LATENCY__) == FLASH_LATENCY_0)
#endif /* FLASH_ACR_LATENCY */
/**
  * @}
  */  

/* 导出类型 ------------------------------------------------------------*/ 
/** @defgroup FLASH_Exported_Types FLASH 导出类型
  * @{
  */  

/**
  * @brief  Flash 操作过程枚举定义
  *         用于标识当前正在进行的Flash操作类型
  */
typedef enum 
{
  FLASH_PROC_NONE              = 0U,  // 无操作正在进行
  FLASH_PROC_PAGEERASE         = 1U,  // 正在进行页擦除
  FLASH_PROC_MASSERASE         = 2U,  // 正在进行全片擦除
  FLASH_PROC_PROGRAMHALFWORD   = 3U,  // 正在进行半字(16位)编程
  FLASH_PROC_PROGRAMWORD       = 4U,  // 正在进行字(32位)编程
  FLASH_PROC_PROGRAMDOUBLEWORD = 5U   // 正在进行双字(64位)编程
} FLASH_ProcedureTypeDef;

/** 
  * @brief  Flash 句柄结构体定义  
  *         用于管理Flash操作的状态、数据和错误信息
  */
typedef struct
{
  __IO FLASH_ProcedureTypeDef ProcedureOnGoing; // 内部变量，指示当前正在进行的操作过程，用于中断上下文
  
  __IO uint32_t               DataRemaining;    // 内部变量，保存剩余待擦除的页数或待编程的半字数，用于中断上下文

  __IO uint32_t               Address;          // 内部变量，保存当前编程或擦除操作的地址

  __IO uint64_t               Data;             // 内部变量，保存待编程的数据

  HAL_LockTypeDef             Lock;             // Flash锁定对象，用于资源管理，防止并发访问

  __IO uint32_t               ErrorCode;        // Flash错误代码
                                                // 该参数可以是 @ref FLASH_Error_Codes 中的值
} FLASH_ProcessTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup FLASH_Exported_Constants FLASH 导出常量
  * @{
  */  

/** @defgroup FLASH_Error_Codes Flash 错误代码
  * @{
  */

#define HAL_FLASH_ERROR_NONE      0x00U  // 无错误
#define HAL_FLASH_ERROR_PROG      0x01U  // 编程错误
#define HAL_FLASH_ERROR_WRP       0x02U  // 写保护错误
#define HAL_FLASH_ERROR_OPTV      0x04U  // 选项有效性错误

/**
  * @}
  */

/** @defgroup FLASH_Type_Program Flash 编程类型
  * @{
  */ 
#define FLASH_TYPEPROGRAM_HALFWORD             0x01U  // 在指定地址编程一个半字(16位)
#define FLASH_TYPEPROGRAM_WORD                 0x02U  // 在指定地址编程一个字(32位)
#define FLASH_TYPEPROGRAM_DOUBLEWORD           0x03U  // 在指定地址编程一个双字(64位)

/**
  * @}
  */

#if   defined(FLASH_ACR_LATENCY)
/** @defgroup FLASH_Latency Flash 延迟周期
  * @{
  */
#define FLASH_LATENCY_0            0x00000000U               // Flash零等待周期
#define FLASH_LATENCY_1            FLASH_ACR_LATENCY_0       // Flash一个等待周期
#define FLASH_LATENCY_2            FLASH_ACR_LATENCY_1       // Flash两个等待周期

/**
  * @}
  */

#else
/** @defgroup FLASH_Latency Flash 延迟周期
  * @{
  */
#define FLASH_LATENCY_0            0x00000000U    // Flash零等待周期

/**
  * @}
  */

#endif /* FLASH_ACR_LATENCY */
/**
  * @}
  */  
  
/* 导出宏 ------------------------------------------------------------*/

/** @defgroup FLASH_Exported_Macros FLASH 导出宏
 *  @brief 用于控制Flash特性的宏 
 *  @{
 */
 
/** @defgroup FLASH_Half_Cycle FLASH 半周期
 *  @brief 用于处理Flash半周期的宏
 * @{
 */

/**
  * @brief  使能Flash半周期访问。
  * @note   半周期访问仅能用于频率低于8MHz的低频时钟，可通过HSI或HSE获得，但不能使用PLL。
  * @retval 无
  */
#define __HAL_FLASH_HALF_CYCLE_ACCESS_ENABLE()  (FLASH->ACR |= FLASH_ACR_HLFCYA)

/**
  * @brief  禁用Flash半周期访问。
  * @note   半周期访问仅能用于频率低于8MHz的低频时钟，可通过HSI或HSE获得，但不能使用PLL。
  * @retval 无
  */
#define __HAL_FLASH_HALF_CYCLE_ACCESS_DISABLE() (FLASH->ACR &= (~FLASH_ACR_HLFCYA))

/**
  * @}
  */

#if defined(FLASH_ACR_LATENCY)
/** @defgroup FLASH_EM_Latency FLASH 延迟
 *  @brief 用于处理Flash延迟的宏
 * @{
 */ 
  
/**
  * @brief  设置Flash延迟周期。
  * @param  __LATENCY__ Flash延迟周期                   
  *         该参数的值取决于同一系列中使用的设备
  * @retval 无
  */ 
#define __HAL_FLASH_SET_LATENCY(__LATENCY__)    (FLASH->ACR = (FLASH->ACR&(~FLASH_ACR_LATENCY)) | (__LATENCY__))


/**
  * @brief  获取Flash延迟周期。
  * @retval Flash延迟周期                   
  *         该参数的值取决于同一系列中使用的设备
  */ 
#define __HAL_FLASH_GET_LATENCY()     (READ_BIT((FLASH->ACR), FLASH_ACR_LATENCY))

/**
  * @}
  */

#endif /* FLASH_ACR_LATENCY */
/** @defgroup FLASH_Prefetch FLASH 预取
 *  @brief 用于处理Flash预取缓冲区的宏
 * @{
 */   
/**
  * @brief  使能Flash预取缓冲区。
  * @retval 无
  */ 
#define __HAL_FLASH_PREFETCH_BUFFER_ENABLE()    (FLASH->ACR |= FLASH_ACR_PRFTBE)

/**
  * @brief  禁用Flash预取缓冲区。
  * @retval 无
  */
#define __HAL_FLASH_PREFETCH_BUFFER_DISABLE()   (FLASH->ACR &= (~FLASH_ACR_PRFTBE))

/**
  * @}
  */
  
/**
  * @}
  */ 

/* 包含Flash HAL扩展模块 */
#include "stm32f1xx_hal_flash_ex.h"  

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup FLASH_Exported_Functions
  * @{
  */
  
/** @addtogroup FLASH_Exported_Functions_Group1
  * @{
  */
/* IO操作函数 *****************************************************/
/* 以阻塞模式编程Flash */
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
/* 以中断非阻塞模式编程Flash */
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);

/* Flash中断处理函数 */
void       HAL_FLASH_IRQHandler(void);
/* 非阻塞模式下的回调函数 */ 
void       HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void       HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);

/**
  * @}
  */

/** @addtogroup FLASH_Exported_Functions_Group2
  * @{
  */
/* 外设控制函数 ***********************************************/
/* 解锁Flash控制寄存器 */
HAL_StatusTypeDef HAL_FLASH_Unlock(void);
/* 锁定Flash控制寄存器 */
HAL_StatusTypeDef HAL_FLASH_Lock(void);
/* 解锁Flash选项字节 */
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
/* 锁定Flash选项字节 */
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
/* 加载选项字节并触发系统复位 */
void HAL_FLASH_OB_Launch(void);

/**
  * @}
  */

/** @addtogroup FLASH_Exported_Functions_Group3
  * @{
  */
/* 外设状态和错误函数 ***************************************/
/* 获取Flash操作错误代码 */
uint32_t HAL_FLASH_GetError(void);

/**
  * @}
  */

/**
  * @}
  */

/* 私有函数 -------------------------------------------------*/
/** @addtogroup FLASH_Private_Functions
 * @{
 */
/* 等待上一次操作完成(轮询模式) */
HAL_StatusTypeDef       FLASH_WaitForLastOperation(uint32_t Timeout);
#if defined(FLASH_BANK2_END)
/* 等待Bank2上一次操作完成(针对大容量双Bank产品) */
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

