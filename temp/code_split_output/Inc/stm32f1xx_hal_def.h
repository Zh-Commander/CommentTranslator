/**
  ******************************************************************************
  * @file    stm32f1xx_hal_def.h
  * @author  MCD Application Team
  * @brief   This file contains HAL common defines, enumeration, macros and
  *          structures definitions.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -----------------------------------------------------*/
#ifndef __STM32F1xx_HAL_DEF
#define __STM32F1xx_HAL_DEF

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"              // 包含STM32F1系列芯片的头文件，定义了寄存器结构体等
#include "Legacy/stm32_hal_legacy.h" // 包含HAL库旧版本兼容性定义
#include <stddef.h>                 // 包含标准定义，如NULL指针

/* 导出类型 ------------------------------------------------------------*/

/**
  * @brief  HAL Status structures definition
  *         HAL状态结构体定义（枚举类型）
  */
typedef enum
{
  HAL_OK       = 0x00U,  // 操作成功
  HAL_ERROR    = 0x01U,  // 操作错误
  HAL_BUSY     = 0x02U,  // 设备忙（例如正在处理其他操作）
  HAL_TIMEOUT  = 0x03U   // 操作超时
} HAL_StatusTypeDef;

/**
  * @brief  HAL Lock structures definition
  *         HAL锁结构体定义（枚举类型），用于多线程或中断环境下的资源保护
  */
typedef enum
{
  HAL_UNLOCKED = 0x00U,  // 未锁定状态，资源可用
  HAL_LOCKED   = 0x01U   // 已锁定状态，资源被占用
} HAL_LockTypeDef;

/* 导出宏 ------------------------------------------------------------*/
#define HAL_MAX_DELAY      0xFFFFFFFFU  // 定义最大延迟时间，用于阻塞式等待函数

// 检查寄存器中的指定位是否被置位（为1）
#define HAL_IS_BIT_SET(REG, BIT)         (((REG) & (BIT)) != 0U)

// 检查寄存器中的指定位是否被清除（为0）
#define HAL_IS_BIT_CLR(REG, BIT)         (((REG) & (BIT)) == 0U)

/**
  * @brief  链接DMA句柄到外设句柄的宏
  * @param  __HANDLE__: 外设句柄指针（如 &huart1）
  * @param  __PPP_DMA_FIELD__: 外设句柄中的DMA字段名（如 hdmarx）
  * @param  __DMA_HANDLE__: DMA句柄变量（如 hdma_usart1_rx）
  * @note   此宏用于双向绑定：外设句柄指向DMA句柄，DMA句柄的Parent指回外设句柄
  */
#define __HAL_LINKDMA(__HANDLE__, __PPP_DMA_FIELD__, __DMA_HANDLE__)               \
                        do{                                                      \
                              (__HANDLE__)->__PPP_DMA_FIELD__ = &(__DMA_HANDLE__); \
                              (__DMA_HANDLE__).Parent = (__HANDLE__);             \
                          } while(0U)

#if !defined(UNUSED)
#define UNUSED(X) (void)X      // 避免gcc/g++编译器产生“未使用变量”的警告
#endif /* UNUSED */

/** @brief Reset the Handle's State field.
  * @param __HANDLE__ specifies the Peripheral Handle.
  * @note  This macro can be used for the following purpose:
  *          - When the Handle is declared as local variable; before passing it as parameter
  *            to HAL_PPP_Init() for the first time, it is mandatory to use this macro
  *            to set to 0 the Handle's "State" field.
  *            Otherwise, "State" field may have any random value and the first time the function
  *            HAL_PPP_Init() is called, the low level hardware initialization will be missed
  *            (i.e. HAL_PPP_MspInit() will not be executed).
  *          - When there is need to reconfigure the low level hardware: instead of calling
  *            HAL_PPP_DeInit() then HAL_PPP_Init(), user can make a call to this macro then HAL_PPP_Init().
  *            In this later function, when the Handle's "State" field is set to 0, it will execute the function
  *            HAL_PPP_MspInit() which will reconfigure the low level hardware.
  * @retval None
  */
#define __HAL_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = 0U)

#if (USE_RTOS == 1U)
/* Reserved for future use */
#error "USE_RTOS should be 0 in the current HAL release"
#else
/**
  * @brief  锁定句柄宏
  * @note   用于多任务环境下的资源保护。如果句柄已被锁定，则返回HAL_BUSY；
  *         如果未锁定，则将其锁定。
  */
#define __HAL_LOCK(__HANDLE__)                                           \
                                do{                                        \
                                    if((__HANDLE__)->Lock == HAL_LOCKED)   \
                                    {                                      \
                                       return HAL_BUSY;                    \
                                    }                                      \
                                    else                                   \
                                    {                                      \
                                       (__HANDLE__)->Lock = HAL_LOCKED;    \
                                    }                                      \
                                  }while (0U)

/**
  * @brief  解锁句柄宏
  * @note   将句柄的锁状态设置为未锁定
  */
#define __HAL_UNLOCK(__HANDLE__)                                          \
                                  do{                                       \
                                      (__HANDLE__)->Lock = HAL_UNLOCKED;    \
                                    }while (0U)
#endif /* USE_RTOS */

/* 编译器兼容性宏定义 ------------------------------------------------------*/
/* 不同的编译器（ARM Compiler V5/V6, GCC, IAR）对弱符号和 packed 结构体的关键字不同 */

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler V6 */
#ifndef __weak
#define __weak  __attribute__((weak))  // 弱符号定义，允许函数被重写
#endif
#ifndef __packed
#define __packed  __attribute__((packed)) // 结构体紧凑排列，无填充字节
#endif
#elif defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
#ifndef __weak
#define __weak   __attribute__((weak))
#endif /* __weak */
#ifndef __packed
#define __packed __attribute__((__packed__))
#endif /* __packed */
#endif /* __GNUC__ */


/* 内存对齐宏定义 -----------------------------------------------------------*/
/* 确保变量在4字节边界上对齐，对于__ICCARM__编译器，应使用"#pragma data_alignment=4"指令代替 */

#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler V6 */
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif
#ifndef __ALIGN_END
#define __ALIGN_END      __attribute__ ((aligned (4))) // 设置4字节对齐
#endif
#elif defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
#ifndef __ALIGN_END
#define __ALIGN_END    __attribute__ ((aligned (4)))
#endif /* __ALIGN_END */
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif /* __ALIGN_BEGIN */
#else
#ifndef __ALIGN_END
#define __ALIGN_END
#endif /* __ALIGN_END */
#ifndef __ALIGN_BEGIN
#if defined   (__CC_ARM)      /* ARM Compiler V5*/
#define __ALIGN_BEGIN    __align(4) // ARM V5编译器的对齐指令
#elif defined (__ICCARM__)    /* IAR Compiler */
#define __ALIGN_BEGIN
#endif /* __CC_ARM */
#endif /* __ALIGN_BEGIN */
#endif /* __GNUC__ */


/**
  * @brief  __RAM_FUNC definition
  *         定义在RAM中运行的函数
  *         某些情况下需要将函数放在RAM中以提高执行速度或Flash无法访问时执行（如Flash写入）
  */
#if defined ( __CC_ARM   ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
/* ARM Compiler V4/V5 and V6
   --------------------------
   RAM functions are defined using the toolchain options.
   Functions that are executed in RAM should reside in a separate source module.
   Using the 'Options for File' dialog you can simply change the 'Code / Const'
   area of a module to a memory space in physical RAM.
   Available memory areas are declared in the 'Target' tab of the 'Options for Target'
   dialog.
*/
#define __RAM_FUNC

#elif defined ( __ICCARM__ )
/* ICCARM Compiler
   ---------------
   RAM functions are defined using a specific toolchain keyword "__ramfunc".
*/
#define __RAM_FUNC __ramfunc // IAR编译器专用关键字

#elif defined   (  __GNUC__  )
/* GNU Compiler
   ------------
  RAM functions are defined using a specific toolchain attribute
   "__attribute__((section(".RamFunc")))".
*/
#define __RAM_FUNC __attribute__((section(".RamFunc"))) // GCC编译器将函数放入指定段

#endif

/**
  * @brief  __NOINLINE definition
  *         禁止函数内联定义
  *         强制编译器不进行内联优化，常用于调试或特定性能需求
  */
#if defined ( __CC_ARM   ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)) || defined   (  __GNUC__  )
/* ARM V4/V5 and V6 & GNU Compiler
   -------------------------------
*/
#define __NOINLINE __attribute__ ( (noinline) )

#elif defined ( __ICCARM__ )
/* ICCARM Compiler
   ---------------
*/
#define __NOINLINE _Pragma("optimize = no_inline") // IAR编译器禁止内联的方法

#endif

#ifdef __cplusplus
}
#endif

#endif /* ___STM32F1xx_HAL_DEF */

