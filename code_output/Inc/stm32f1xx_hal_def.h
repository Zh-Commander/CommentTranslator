/**
  ******************************************************************************
  * @file    stm32f1xx_hal_def.h
  * @author  MCD Application Team
  * @brief   此文件包含HAL库通用的定义、枚举、宏和结构体定义。
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
#include "stm32f1xx.h"              // 包含STM32F1系列芯片的头文件，定义了寄存器映射等
#include "Legacy/stm32_hal_legacy.h"// 包含HAL库旧版本兼容性定义
#include <stddef.h>                 // 包含标准定义，如NULL指针

/* 导出类型 ------------------------------------------------------------*/

/**
  * @brief  HAL 状态结构体定义
  * @note   用于函数返回值，指示函数执行状态
  */
typedef enum
{
  HAL_OK       = 0x00U,  // 操作成功
  HAL_ERROR    = 0x01U,  // 操作错误
  HAL_BUSY     = 0x02U,  // 设备忙，通常用于锁定机制
  HAL_TIMEOUT  = 0x03U   // 操作超时
} HAL_StatusTypeDef;

/**
  * @brief  HAL 锁结构体定义
  * @note   用于资源锁定，防止多任务或中断中的重入问题
  */
typedef enum
{
  HAL_UNLOCKED = 0x00U,  // 未锁定状态
  HAL_LOCKED   = 0x01U   // 已锁定状态
} HAL_LockTypeDef;

/* 导出宏 ------------------------------------------------------------*/
#define HAL_MAX_DELAY      0xFFFFFFFFU  // 定义最大延时值，用于无限期等待

// 检查寄存器中的指定位是否被置位（为1）
#define HAL_IS_BIT_SET(REG, BIT)         (((REG) & (BIT)) != 0U)

// 检查寄存器中的指定位是否被清零（为0）
#define HAL_IS_BIT_CLR(REG, BIT)         (((REG) & (BIT)) == 0U)

/**
  * @brief  关联外设句柄与DMA句柄的宏
  * @param  __HANDLE__: 外设句柄指针（如 &huart1）
  * @param  __PPP_DMA_FIELD__: 外设句柄中的DMA字段名（如 hdmatx）
  * @param  __DMA_HANDLE__: DMA句柄变量（如 hdma_usart1_tx）
  * @note   此宏建立了外设与DMA之间的双向链接，方便后续操作
  */
#define __HAL_LINKDMA(__HANDLE__, __PPP_DMA_FIELD__, __DMA_HANDLE__)               \
                        do{                                                      \
                              (__HANDLE__)->__PPP_DMA_FIELD__ = &(__DMA_HANDLE__); \
                              (__DMA_HANDLE__).Parent = (__HANDLE__);             \
                          } while(0U)

#if !defined(UNUSED)
// 避免编译器对未使用变量产生警告的宏
#define UNUSED(X) (void)X
#endif /* UNUSED */

/**
  * @brief  重置句柄的状态字段。
  * @param  __HANDLE__ 指定外设句柄。
  * @note   此宏用于以下目的：
  *          - 当句柄声明为局部变量时；在第一次将其作为参数传递给 HAL_PPP_Init() 之前，
  *            必须使用此宏将句柄的 "State" 字段设置为 0。
  *            否则，"State" 字段可能具有随机值，第一次调用 HAL_PPP_Init() 时，
  *            将会跳过低级硬件初始化（即 HAL_PPP_MspInit() 不会被执行）。
  *          - 当需要重新配置低级硬件时：用户可以调用此宏，然后调用 HAL_PPP_Init()，
  *            而不必调用 HAL_PPP_DeInit() 再调用 HAL_PPP_Init()。
  *            在 HAL_PPP_Init() 函数中，当句柄的 "State" 字段设置为 0 时，
  *            它将执行 HAL_PPP_MspInit() 函数，从而重新配置低级硬件。
  * @retval 无
  */
#define __HAL_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = 0U)

#if (USE_RTOS == 1U)
/* Reserved for future use */
#error "USE_RTOS should be 0 in the current HAL release"
#else
/**
  * @brief  锁定句柄宏
  * @note   用于多任务环境或中断保护，防止资源冲突
  *         如果已锁定，返回 HAL_BUSY；否则进行锁定
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
  * @note   操作完成后释放资源
  */
#define __HAL_UNLOCK(__HANDLE__)                                          \
                                  do{                                       \
                                      (__HANDLE__)->Lock = HAL_UNLOCKED;    \
                                    }while (0U)
#endif /* USE_RTOS */

/* 编译器兼容性宏定义：弱定义和结构体对齐 */
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler V6 */
#ifndef __weak
#define __weak  __attribute__((weak))  // 弱定义符号，允许用户覆盖库函数
#endif
#ifndef __packed
#define __packed  __attribute__((packed)) // 取消结构体填充，紧凑存储
#endif
#elif defined ( __GNUC__ ) && !defined (__CC_ARM) /* GNU Compiler */
#ifndef __weak
#define __weak   __attribute__((weak))
#endif /* __weak */
#ifndef __packed
#define __packed __attribute__((__packed__))
#endif /* __packed */
#endif /* __GNUC__ */


/* 宏定义：使变量4字节对齐。对于 __ICCARM__ 编译器，必须使用 "#pragma data_alignment=4" 指令代替 */
#if defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050) /* ARM Compiler V6 */
#ifndef __ALIGN_BEGIN
#define __ALIGN_BEGIN
#endif
#ifndef __ALIGN_END
#define __ALIGN_END      __attribute__ ((aligned (4))) // 放置在变量定义后，指示4字节对齐
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
#define __ALIGN_BEGIN    __align(4) // 放置在变量定义前，指示4字节对齐
#elif defined (__ICCARM__)    /* IAR Compiler */
#define __ALIGN_BEGIN
#endif /* __CC_ARM */
#endif /* __ALIGN_BEGIN */
#endif /* __GNUC__ */


/**
  * @brief  __RAM_FUNC 定义
  * @note   用于定义在RAM中运行的函数，通常用于Flash操作或提高中断响应速度
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
#define __RAM_FUNC __ramfunc

#elif defined   (  __GNUC__  )
/* GNU Compiler
   ------------
  RAM functions are defined using a specific toolchain attribute
   "__attribute__((section(".RamFunc")))".
*/
#define __RAM_FUNC __attribute__((section(".RamFunc")))

#endif

/**
  * @brief  __NOINLINE 定义
  * @note   用于禁止函数内联，强制生成独立的函数调用代码
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
#define __NOINLINE _Pragma("optimize = no_inline")

#endif

#ifdef __cplusplus
}
#endif

#endif /* ___STM32F1xx_HAL_DEF */

