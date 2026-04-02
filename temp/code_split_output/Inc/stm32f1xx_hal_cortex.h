/**
  ******************************************************************************
  * @file    stm32f1xx_hal_cortex.h
  * @author  MCD Application Team
  * @brief   Header file of CORTEX HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -----------------------------------------------------*/
#ifndef __STM32F1xx_HAL_CORTEX_H
#define __STM32F1xx_HAL_CORTEX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup CORTEX
  * @{
  */ 
/* 导出类型 ------------------------------------------------------------*/
/** @defgroup CORTEX_Exported_Types Cortex Exported Types
  * @{
  */

#if (__MPU_PRESENT == 1U)
/** @defgroup CORTEX_MPU_Region_Initialization_Structure_definition MPU Region Initialization Structure Definition
  * @brief  MPU Region initialization structure 
  * @{
  */
typedef struct
{
  uint8_t                Enable;                /*!< 指定区域的使能状态。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Enable 中的值                 */
  uint8_t                Number;                /*!< 指定要保护的区域编号。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Number 中的值                 */
  uint32_t               BaseAddress;           /*!< 指定要保护区域的基地址。                           */
  uint8_t                Size;                  /*!< 指定要保护区域的大小。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Size 中的值                   */
  uint8_t                SubRegionDisable;      /*!< 指定要禁用的子区域编号。
                                                     该参数必须是 Min_Data = 0x00 和 Max_Data = 0xFF 之间的数字    */         
  uint8_t                TypeExtField;          /*!< 指定 TEX 字段等级。
                                                     该参数可以是 @ref CORTEX_MPU_TEX_Levels 中的值                    */                 
  uint8_t                AccessPermission;      /*!< 指定区域访问权限类型。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Permission_Attributes 中的值  */
  uint8_t                DisableExec;           /*!< 指定指令访问状态。
                                                     该参数可以是 @ref CORTEX_MPU_Instruction_Access 中的值            */
  uint8_t                IsShareable;           /*!< 指定保护区域的共享状态。
                                                     该参数可以是 @ref CORTEX_MPU_Access_Shareable 中的值              */
  uint8_t                IsCacheable;           /*!< 指定保护区域的可缓存状态。
                                                     该参数可以是 @ref CORTEX_MPU_Access_Cacheable 中的值              */
  uint8_t                IsBufferable;          /*!< 指定保护区域的可缓冲状态。
                                                     该参数可以是 @ref CORTEX_MPU_Access_Bufferable 中的值             */
}MPU_Region_InitTypeDef;
/**
  * @}
  */
#endif /* __MPU_PRESENT */

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/

/** @defgroup CORTEX_Exported_Constants CORTEX Exported Constants
  * @{
  */

/** @defgroup CORTEX_Preemption_Priority_Group CORTEX Preemption Priority Group
  * @{
  */
#define NVIC_PRIORITYGROUP_0         0x00000007U /*!< 0位用于抢占优先级
                                                      4位用于子优先级 */
#define NVIC_PRIORITYGROUP_1         0x00000006U /*!< 1位用于抢占优先级
                                                      3位用于子优先级 */
#define NVIC_PRIORITYGROUP_2         0x00000005U /*!< 2位用于抢占优先级
                                                      2位用于子优先级 */
#define NVIC_PRIORITYGROUP_3         0x00000004U /*!< 3位用于抢占优先级
                                                      1位用于子优先级 */
#define NVIC_PRIORITYGROUP_4         0x00000003U /*!< 4位用于抢占优先级
                                                      0位用于子优先级 */
/**
  * @}
  */

/** @defgroup CORTEX_SysTick_clock_source CORTEX _SysTick clock source 
  * @{
  */
// SysTick时钟源选择：HCLK时钟8分频
#define SYSTICK_CLKSOURCE_HCLK_DIV8    0x00000000U
// SysTick时钟源选择：HCLK时钟（系统主频）
#define SYSTICK_CLKSOURCE_HCLK         0x00000004U

/**
  * @}
  */

#if (__MPU_PRESENT == 1)
/** @defgroup CORTEX_MPU_HFNMI_PRIVDEF_Control MPU HFNMI and PRIVILEGED Access control
  * @{
  */
// 不使能任何MPU控制
#define  MPU_HFNMI_PRIVDEF_NONE           0x00000000U
// 在硬故障和NMI处理程序中使能MPU
#define  MPU_HARDFAULT_NMI                MPU_CTRL_HFNMIENA_Msk
// 使能特权软件的默认存储器映射
#define  MPU_PRIVILEGED_DEFAULT           MPU_CTRL_PRIVDEFENA_Msk
// 同时使能硬故障/NMI控制和特权默认映射
#define  MPU_HFNMI_PRIVDEF               (MPU_CTRL_HFNMIENA_Msk | MPU_CTRL_PRIVDEFENA_Msk)

/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Enable CORTEX MPU Region Enable
  * @{
  */
// MPU区域使能
#define  MPU_REGION_ENABLE     ((uint8_t)0x01)
// MPU区域禁用
#define  MPU_REGION_DISABLE    ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Instruction_Access CORTEX MPU Instruction Access
  * @{
  */
// 允许指令执行（取指）
#define  MPU_INSTRUCTION_ACCESS_ENABLE      ((uint8_t)0x00)
// 禁止指令执行（取指）
#define  MPU_INSTRUCTION_ACCESS_DISABLE     ((uint8_t)0x01)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Shareable CORTEX MPU Instruction Access Shareable
  * @{
  */
// 可共享
#define  MPU_ACCESS_SHAREABLE        ((uint8_t)0x01)
// 不可共享
#define  MPU_ACCESS_NOT_SHAREABLE    ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Cacheable CORTEX MPU Instruction Access Cacheable
  * @{
  */
// 可缓存
#define  MPU_ACCESS_CACHEABLE         ((uint8_t)0x01)
// 不可缓存
#define  MPU_ACCESS_NOT_CACHEABLE     ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Bufferable CORTEX MPU Instruction Access Bufferable
  * @{
  */
// 可缓冲
#define  MPU_ACCESS_BUFFERABLE         ((uint8_t)0x01)
// 不可缓冲
#define  MPU_ACCESS_NOT_BUFFERABLE     ((uint8_t)0x00)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_TEX_Levels MPU TEX Levels
  * @{
  */
// TEX等级0，用于配置内存类型和缓存策略
#define  MPU_TEX_LEVEL0    ((uint8_t)0x00)
// TEX等级1
#define  MPU_TEX_LEVEL1    ((uint8_t)0x01)
// TEX等级2
#define  MPU_TEX_LEVEL2    ((uint8_t)0x02)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Size CORTEX MPU Region Size
  * @{
  */
// 定义MPU保护区域的大小，从32字节到4GB
#define   MPU_REGION_SIZE_32B      ((uint8_t)0x04)
#define   MPU_REGION_SIZE_64B      ((uint8_t)0x05)
#define   MPU_REGION_SIZE_128B     ((uint8_t)0x06)
#define   MPU_REGION_SIZE_256B     ((uint8_t)0x07)
#define   MPU_REGION_SIZE_512B     ((uint8_t)0x08)
#define   MPU_REGION_SIZE_1KB      ((uint8_t)0x09)
#define   MPU_REGION_SIZE_2KB      ((uint8_t)0x0A)
#define   MPU_REGION_SIZE_4KB      ((uint8_t)0x0B)
#define   MPU_REGION_SIZE_8KB      ((uint8_t)0x0C)
#define   MPU_REGION_SIZE_16KB     ((uint8_t)0x0D)
#define   MPU_REGION_SIZE_32KB     ((uint8_t)0x0E)
#define   MPU_REGION_SIZE_64KB     ((uint8_t)0x0F)
#define   MPU_REGION_SIZE_128KB    ((uint8_t)0x10)
#define   MPU_REGION_SIZE_256KB    ((uint8_t)0x11)
#define   MPU_REGION_SIZE_512KB    ((uint8_t)0x12)
#define   MPU_REGION_SIZE_1MB      ((uint8_t)0x13)
#define   MPU_REGION_SIZE_2MB      ((uint8_t)0x14)
#define   MPU_REGION_SIZE_4MB      ((uint8_t)0x15)
#define   MPU_REGION_SIZE_8MB      ((uint8_t)0x16)
#define   MPU_REGION_SIZE_16MB     ((uint8_t)0x17)
#define   MPU_REGION_SIZE_32MB     ((uint8_t)0x18)
#define   MPU_REGION_SIZE_64MB     ((uint8_t)0x19)
#define   MPU_REGION_SIZE_128MB    ((uint8_t)0x1A)
#define   MPU_REGION_SIZE_256MB    ((uint8_t)0x1B)
#define   MPU_REGION_SIZE_512MB    ((uint8_t)0x1C)
#define   MPU_REGION_SIZE_1GB      ((uint8_t)0x1D)
#define   MPU_REGION_SIZE_2GB      ((uint8_t)0x1E)
#define   MPU_REGION_SIZE_4GB      ((uint8_t)0x1F)
/**
  * @}
  */
   
/** @defgroup CORTEX_MPU_Region_Permission_Attributes CORTEX MPU Region Permission Attributes 
  * @{
  */
// 无访问权限
#define  MPU_REGION_NO_ACCESS      ((uint8_t)0x00)
// 特权级读写，用户级无访问
#define  MPU_REGION_PRIV_RW        ((uint8_t)0x01)
// 特权级读写，用户级只读
#define  MPU_REGION_PRIV_RW_URO    ((uint8_t)0x02)
// 特权级和用户级都可读写（全访问）
#define  MPU_REGION_FULL_ACCESS    ((uint8_t)0x03)
// 特权级只读，用户级无访问
#define  MPU_REGION_PRIV_RO        ((uint8_t)0x05)
// 特权级只读，用户级只读
#define  MPU_REGION_PRIV_RO_URO    ((uint8_t)0x06)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Number CORTEX MPU Region Number
  * @{
  */
// MPU区域编号0-7，STM32F1系列通常支持8个区域
#define  MPU_REGION_NUMBER0    ((uint8_t)0x00)
#define  MPU_REGION_NUMBER1    ((uint8_t)0x01)
#define  MPU_REGION_NUMBER2    ((uint8_t)0x02)
#define  MPU_REGION_NUMBER3    ((uint8_t)0x03)
#define  MPU_REGION_NUMBER4    ((uint8_t)0x04)
#define  MPU_REGION_NUMBER5    ((uint8_t)0x05)
#define  MPU_REGION_NUMBER6    ((uint8_t)0x06)
#define  MPU_REGION_NUMBER7    ((uint8_t)0x07)
/**
  * @}
  */
#endif /* __MPU_PRESENT */

/**
  * @}
  */


/* 导出宏 -----------------------------------------------------------*/

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup CORTEX_Exported_Functions
  * @{
  */
  
/** @addtogroup CORTEX_Exported_Functions_Group1
  * @{
  */
/* 初始化和反初始化函数 *****************************/
// 设置中断优先级分组
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
// 设置中断优先级
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
// 使能中断
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
// 禁用中断
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
// 复位系统
void HAL_NVIC_SystemReset(void);
// 配置SysTick重装载值
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);
/**
  * @}
  */

/** @addtogroup CORTEX_Exported_Functions_Group2
  * @{
  */
/* 外设控制函数 ***********************************************/
// 获取中断优先级分组
uint32_t HAL_NVIC_GetPriorityGrouping(void);
// 获取中断优先级
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);
// 获取挂起的中断
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
// 设置中断挂起位
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
// 清除中断挂起位
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
// 获取中断活动状态
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
// 配置SysTick时钟源
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
// SysTick中断处理函数
void HAL_SYSTICK_IRQHandler(void);
// SysTick回调函数
void HAL_SYSTICK_Callback(void);

#if (__MPU_PRESENT == 1U)
// 使能MPU
void HAL_MPU_Enable(uint32_t MPU_Control);
// 禁用MPU
void HAL_MPU_Disable(void);
// 使能MPU区域
void HAL_MPU_EnableRegion(uint32_t RegionNumber);
// 禁用MPU区域
void HAL_MPU_DisableRegion(uint32_t RegionNumber);
// 配置MPU区域
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init);
#endif /* __MPU_PRESENT */
/**
  * @}
  */

/**
  * @}
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/* 私有宏 ------------------------------------------------------------*/
/** @defgroup CORTEX_Private_Macros CORTEX Private Macros
  * @{
  */
// 检查中断优先级分组参数是否有效
#define IS_NVIC_PRIORITY_GROUP(GROUP) (((GROUP) == NVIC_PRIORITYGROUP_0) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_1) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_2) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_3) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_4))

// 检查抢占优先级参数是否有效（0-15）
#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10U)

// 检查子优先级参数是否有效（0-15）
#define IS_NVIC_SUB_PRIORITY(PRIORITY)         ((PRIORITY) < 0x10U)

// 检查设备中断号是否有效
#define IS_NVIC_DEVICE_IRQ(IRQ)                ((IRQ) >= (IRQn_Type)0x00U)

// 检查SysTick时钟源参数是否有效
#define IS_SYSTICK_CLK_SOURCE(SOURCE) (((SOURCE) == SYSTICK_CLKSOURCE_HCLK) || \
                                       ((SOURCE) == SYSTICK_CLKSOURCE_HCLK_DIV8))

#if (__MPU_PRESENT == 1U)
// 检查MPU区域使能状态参数是否有效
#define IS_MPU_REGION_ENABLE(STATE) (((STATE) == MPU_REGION_ENABLE) || \
                                     ((STATE) == MPU_REGION_DISABLE))

// 检查MPU指令访问参数是否有效
#define IS_MPU_INSTRUCTION_ACCESS(STATE) (((STATE) == MPU_INSTRUCTION_ACCESS_ENABLE) || \
                                          ((STATE) == MPU_INSTRUCTION_ACCESS_DISABLE))

// 检查MPU共享属性参数是否有效
#define IS_MPU_ACCESS_SHAREABLE(STATE)   (((STATE) == MPU_ACCESS_SHAREABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_SHAREABLE))

// 检查MPU缓存属性参数是否有效
#define IS_MPU_ACCESS_CACHEABLE(STATE)   (((STATE) == MPU_ACCESS_CACHEABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_CACHEABLE))

// 检查MPU缓冲属性参数是否有效
#define IS_MPU_ACCESS_BUFFERABLE(STATE)   (((STATE) == MPU_ACCESS_BUFFERABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_BUFFERABLE))

// 检查MPU TEX等级参数是否有效
#define IS_MPU_TEX_LEVEL(TYPE) (((TYPE) == MPU_TEX_LEVEL0)  || \
                                ((TYPE) == MPU_TEX_LEVEL1)  || \
                                ((TYPE) == MPU_TEX_LEVEL2))

// 检查MPU区域权限属性参数是否有效
#define IS_MPU_REGION_PERMISSION_ATTRIBUTE(TYPE) (((TYPE) == MPU_REGION_NO_ACCESS)   || \
                                                  ((TYPE) == MPU_REGION_PRIV_RW)     || \
                                                  ((TYPE) == MPU_REGION_PRIV_RW_URO) || \
                                                  ((TYPE) == MPU_REGION_FULL_ACCESS) || \
                                                  ((TYPE) == MPU_REGION_PRIV_RO)     || \
                                                  ((TYPE) == MPU_REGION_PRIV_RO_URO))

// 检查MPU区域编号参数是否有效
#define IS_MPU_REGION_NUMBER(NUMBER)    (((NUMBER) == MPU_REGION_NUMBER0) || \
                                         ((NUMBER) == MPU_REGION_NUMBER1) || \
                                         ((NUMBER) == MPU_REGION_NUMBER2) || \
                                         ((NUMBER) == MPU_REGION_NUMBER3) || \
                                         ((NUMBER) == MPU_REGION_NUMBER4) || \
                                         ((NUMBER) == MPU_REGION_NUMBER5) || \
                                         ((NUMBER) == MPU_REGION_NUMBER6) || \
                                         ((NUMBER) == MPU_REGION_NUMBER7))

// 检查MPU区域大小参数是否有效
#define IS_MPU_REGION_SIZE(SIZE)    (((SIZE) == MPU_REGION_SIZE_32B)   || \
                                     ((SIZE) == MPU_REGION_SIZE_64B)   || \
                                     ((SIZE) == MPU_REGION_SIZE_128B)  || \
                                     ((SIZE) == MPU_REGION_SIZE_256B)  || \
                                     ((SIZE) == MPU_REGION_SIZE_512B)  || \
                                     ((SIZE) == MPU_REGION_SIZE_1KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_2KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_4KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_8KB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_16KB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_32KB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_64KB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_128KB) || \
                                     ((SIZE) == MPU_REGION_SIZE_256KB) || \
                                     ((SIZE) == MPU_REGION_SIZE_512KB) || \
                                     ((SIZE) == MPU_REGION_SIZE_1MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_2MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_4MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_8MB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_16MB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_32MB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_64MB)  || \
                                     ((SIZE) == MPU_REGION_SIZE_128MB) || \
                                     ((SIZE) == MPU_REGION_SIZE_256MB) || \
                                     ((SIZE) == MPU_REGION_SIZE_512MB) || \
                                     ((SIZE) == MPU_REGION_SIZE_1GB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_2GB)   || \
                                     ((SIZE) == MPU_REGION_SIZE_4GB))

// 检查MPU子区域禁用参数是否有效
#define IS_MPU_SUB_REGION_DISABLE(SUBREGION)  ((SUBREGION) < (uint16_t)0x00FF)
#endif /* __MPU_PRESENT */

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

#endif /* __STM32F1xx_HAL_CORTEX_H */
 
