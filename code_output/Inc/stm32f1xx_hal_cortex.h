/**
  ******************************************************************************
  * @file    stm32f1xx_hal_cortex.h
  * @author  MCD Application Team
  * @brief   CORTEX HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2017 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据许可条款授权，许可条款可在本软件组件根目录下的LICENSE文件中找到。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
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
/** @defgroup CORTEX_Exported_Types Cortex 导出类型
  * @{
  */

#if (__MPU_PRESENT == 1U)
/** @defgroup CORTEX_MPU_Region_Initialization_Structure_definition MPU 区域初始化结构定义
  * @brief  MPU 区域初始化结构体 
  * @{
  */
typedef struct
{
  uint8_t                Enable;                /*!< 指定区域的使能状态。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Enable 中的一个值 */
  uint8_t                Number;                /*!< 指定要保护区域的编号。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Number 中的一个值 */
  uint32_t               BaseAddress;           /*!< 指定要保护区域的基地址。                           */
  uint8_t                Size;                  /*!< 指定要保护区域的大小。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Size 中的一个值 */
  uint8_t                SubRegionDisable;      /*!< 指定要禁用的子区域保护编号。
                                                     该参数必须是一个介于 Min_Data = 0x00 和 Max_Data = 0xFF 之间的数字 */         
  uint8_t                TypeExtField;          /*!< 指定 TEX 字段级别。
                                                     该参数可以是 @ref CORTEX_MPU_TEX_Levels 中的一个值 */                 
  uint8_t                AccessPermission;      /*!< 指定区域访问权限类型。
                                                     该参数可以是 @ref CORTEX_MPU_Region_Permission_Attributes 中的一个值 */
  uint8_t                DisableExec;           /*!< 指定指令访问状态。
                                                     该参数可以是 @ref CORTEX_MPU_Instruction_Access 中的一个值 */
  uint8_t                IsShareable;           /*!< 指定保护区域的共享状态。
                                                     该参数可以是 @ref CORTEX_MPU_Access_Shareable 中的一个值 */
  uint8_t                IsCacheable;           /*!< 指定保护区域的可缓存状态。
                                                     该参数可以是 @ref CORTEX_MPU_Access_Cacheable 中的一个值 */
  uint8_t                IsBufferable;          /*!< 指定保护区域的可缓冲状态。
                                                     该参数可以是 @ref CORTEX_MPU_Access_Bufferable 中的一个值 */
}MPU_Region_InitTypeDef;
/**
  * @}
  */
#endif /* __MPU_PRESENT */

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/

/** @defgroup CORTEX_Exported_Constants CORTEX 导出常量
  * @{
  */

/** @defgroup CORTEX_Preemption_Priority_Group CORTEX 抢占优先级分组
  * @{
  */
#define NVIC_PRIORITYGROUP_0         0x00000007U /*!< 抢占优先级占0位
                                                      子优先级占4位 */
#define NVIC_PRIORITYGROUP_1         0x00000006U /*!< 抢占优先级占1位
                                                      子优先级占3位 */
#define NVIC_PRIORITYGROUP_2         0x00000005U /*!< 抢占优先级占2位
                                                      子优先级占2位 */
#define NVIC_PRIORITYGROUP_3         0x00000004U /*!< 抢占优先级占3位
                                                      子优先级占1位 */
#define NVIC_PRIORITYGROUP_4         0x00000003U /*!< 抢占优先级占4位
                                                      子优先级占0位 */
/**
  * @}
  */

/** @defgroup CORTEX_SysTick_clock_source CORTEX SysTick 时钟源 
  * @{
  */
#define SYSTICK_CLKSOURCE_HCLK_DIV8    0x00000000U  // SysTick时钟源为HCLK 8分频
#define SYSTICK_CLKSOURCE_HCLK         0x00000004U  // SysTick时钟源为HCLK(系统时钟)

/**
  * @}
  */

#if (__MPU_PRESENT == 1)
/** @defgroup CORTEX_MPU_HFNMI_PRIVDEF_Control MPU HFNMI 和特权访问控制
  * @{
  */
#define  MPU_HFNMI_PRIVDEF_NONE           0x00000000U  // 不使能HFNMI和默认特权映射
#define  MPU_HARDFAULT_NMI                MPU_CTRL_HFNMIENA_Msk  // 使能HardFault和NMI期间的MPU
#define  MPU_PRIVILEGED_DEFAULT           MPU_CTRL_PRIVDEFENA_Msk // 使能默认特权访问
#define  MPU_HFNMI_PRIVDEF               (MPU_CTRL_HFNMIENA_Msk | MPU_CTRL_PRIVDEFENA_Msk) // 同时使能HFNMI和默认特权访问

/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Enable CORTEX MPU 区域使能
  * @{
  */
#define  MPU_REGION_ENABLE     ((uint8_t)0x01)  // MPU区域使能
#define  MPU_REGION_DISABLE    ((uint8_t)0x00)  // MPU区域禁用
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Instruction_Access CORTEX MPU 指令访问
  * @{
  */
#define  MPU_INSTRUCTION_ACCESS_ENABLE      ((uint8_t)0x00)  // 允许指令访问(可执行)
#define  MPU_INSTRUCTION_ACCESS_DISABLE     ((uint8_t)0x01)  // 禁止指令访问(不可执行)
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Shareable CORTEX MPU 访问共享属性
  * @{
  */
#define  MPU_ACCESS_SHAREABLE        ((uint8_t)0x01)  // 区域可共享
#define  MPU_ACCESS_NOT_SHAREABLE    ((uint8_t)0x00)  // 区域不可共享
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Cacheable CORTEX MPU 访问缓存属性
  * @{
  */
#define  MPU_ACCESS_CACHEABLE         ((uint8_t)0x01)  // 区域可缓存
#define  MPU_ACCESS_NOT_CACHEABLE     ((uint8_t)0x00)  // 区域不可缓存
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Access_Bufferable CORTEX MPU 访问缓冲属性
  * @{
  */
#define  MPU_ACCESS_BUFFERABLE         ((uint8_t)0x01)  // 区域可缓冲
#define  MPU_ACCESS_NOT_BUFFERABLE     ((uint8_t)0x00)  // 区域不可缓冲
/**
  * @}
  */

/** @defgroup CORTEX_MPU_TEX_Levels MPU TEX 级别
  * @{
  */
#define  MPU_TEX_LEVEL0    ((uint8_t)0x00)  // TEX级别0
#define  MPU_TEX_LEVEL1    ((uint8_t)0x01)  // TEX级别1
#define  MPU_TEX_LEVEL2    ((uint8_t)0x02)  // TEX级别2
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Size CORTEX MPU 区域大小
  * @{
  */
#define   MPU_REGION_SIZE_32B      ((uint8_t)0x04)  // 区域大小 32字节
#define   MPU_REGION_SIZE_64B      ((uint8_t)0x05)  // 区域大小 64字节
#define   MPU_REGION_SIZE_128B     ((uint8_t)0x06)  // 区域大小 128字节
#define   MPU_REGION_SIZE_256B     ((uint8_t)0x07)  // 区域大小 256字节
#define   MPU_REGION_SIZE_512B     ((uint8_t)0x08)  // 区域大小 512字节
#define   MPU_REGION_SIZE_1KB      ((uint8_t)0x09)  // 区域大小 1KB
#define   MPU_REGION_SIZE_2KB      ((uint8_t)0x0A)  // 区域大小 2KB
#define   MPU_REGION_SIZE_4KB      ((uint8_t)0x0B)  // 区域大小 4KB
#define   MPU_REGION_SIZE_8KB      ((uint8_t)0x0C)  // 区域大小 8KB
#define   MPU_REGION_SIZE_16KB     ((uint8_t)0x0D)  // 区域大小 16KB
#define   MPU_REGION_SIZE_32KB     ((uint8_t)0x0E)  // 区域大小 32KB
#define   MPU_REGION_SIZE_64KB     ((uint8_t)0x0F)  // 区域大小 64KB
#define   MPU_REGION_SIZE_128KB    ((uint8_t)0x10)  // 区域大小 128KB
#define   MPU_REGION_SIZE_256KB    ((uint8_t)0x11)  // 区域大小 256KB
#define   MPU_REGION_SIZE_512KB    ((uint8_t)0x12)  // 区域大小 512KB
#define   MPU_REGION_SIZE_1MB      ((uint8_t)0x13)  // 区域大小 1MB
#define   MPU_REGION_SIZE_2MB      ((uint8_t)0x14)  // 区域大小 2MB
#define   MPU_REGION_SIZE_4MB      ((uint8_t)0x15)  // 区域大小 4MB
#define   MPU_REGION_SIZE_8MB      ((uint8_t)0x16)  // 区域大小 8MB
#define   MPU_REGION_SIZE_16MB     ((uint8_t)0x17)  // 区域大小 16MB
#define   MPU_REGION_SIZE_32MB     ((uint8_t)0x18)  // 区域大小 32MB
#define   MPU_REGION_SIZE_64MB     ((uint8_t)0x19)  // 区域大小 64MB
#define   MPU_REGION_SIZE_128MB    ((uint8_t)0x1A)  // 区域大小 128MB
#define   MPU_REGION_SIZE_256MB    ((uint8_t)0x1B)  // 区域大小 256MB
#define   MPU_REGION_SIZE_512MB    ((uint8_t)0x1C)  // 区域大小 512MB
#define   MPU_REGION_SIZE_1GB      ((uint8_t)0x1D)  // 区域大小 1GB
#define   MPU_REGION_SIZE_2GB      ((uint8_t)0x1E)  // 区域大小 2GB
#define   MPU_REGION_SIZE_4GB      ((uint8_t)0x1F)  // 区域大小 4GB
/**
  * @}
  */
   
/** @defgroup CORTEX_MPU_Region_Permission_Attributes CORTEX MPU 区域权限属性 
  * @{
  */
#define  MPU_REGION_NO_ACCESS      ((uint8_t)0x00)  // 无访问权限
#define  MPU_REGION_PRIV_RW        ((uint8_t)0x01)  // 特权读写，用户无访问
#define  MPU_REGION_PRIV_RW_URO    ((uint8_t)0x02)  // 特权读写，用户只读
#define  MPU_REGION_FULL_ACCESS    ((uint8_t)0x03)  // 全访问(特权/用户均可读写)
#define  MPU_REGION_PRIV_RO        ((uint8_t)0x05)  // 特权只读，用户无访问
#define  MPU_REGION_PRIV_RO_URO    ((uint8_t)0x06)  // 特权只读，用户只读
/**
  * @}
  */

/** @defgroup CORTEX_MPU_Region_Number CORTEX MPU 区域编号
  * @{
  */
#define  MPU_REGION_NUMBER0    ((uint8_t)0x00)  // MPU区域编号0
#define  MPU_REGION_NUMBER1    ((uint8_t)0x01)  // MPU区域编号1
#define  MPU_REGION_NUMBER2    ((uint8_t)0x02)  // MPU区域编号2
#define  MPU_REGION_NUMBER3    ((uint8_t)0x03)  // MPU区域编号3
#define  MPU_REGION_NUMBER4    ((uint8_t)0x04)  // MPU区域编号4
#define  MPU_REGION_NUMBER5    ((uint8_t)0x05)  // MPU区域编号5
#define  MPU_REGION_NUMBER6    ((uint8_t)0x06)  // MPU区域编号6
#define  MPU_REGION_NUMBER7    ((uint8_t)0x07)  // MPU区域编号7
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
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);  // 设置中断优先级分组
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority); // 设置指定中断的抢占优先级和子优先级
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);  // 使能指定的中断
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn); // 禁用指定的中断
void HAL_NVIC_SystemReset(void);          // 复位系统
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb); // 配置SysTick定时器
/**
  * @}
  */

/** @addtogroup CORTEX_Exported_Functions_Group2
  * @{
  */
/* 外设控制函数 ***********************************************/
uint32_t HAL_NVIC_GetPriorityGrouping(void);  // 获取中断优先级分组
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority); // 获取指定中断的优先级
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn); // 获取指定中断的挂起状态
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);     // 设置指定中断的挂起位
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);   // 清除指定中断的挂起位
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);     // 获取指定中断的活动状态
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource); // 配置SysTick时钟源
void HAL_SYSTICK_IRQHandler(void);  // SysTick中断处理函数
void HAL_SYSTICK_Callback(void);    // SysTick中断回调函数

#if (__MPU_PRESENT == 1U)
void HAL_MPU_Enable(uint32_t MPU_Control);  // 使能MPU
void HAL_MPU_Disable(void);                 // 禁用MPU
void HAL_MPU_EnableRegion(uint32_t RegionNumber);  // 使能指定的MPU区域
void HAL_MPU_DisableRegion(uint32_t RegionNumber); // 禁用指定的MPU区域
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init); // 配置MPU区域
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
/** @defgroup CORTEX_Private_Macros CORTEX 私有宏
  * @{
  */
// 检查中断优先级分组参数是否有效
#define IS_NVIC_PRIORITY_GROUP(GROUP) (((GROUP) == NVIC_PRIORITYGROUP_0) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_1) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_2) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_3) || \
                                       ((GROUP) == NVIC_PRIORITYGROUP_4))

// 检查抢占优先级参数是否有效(0-15)
#define IS_NVIC_PREEMPTION_PRIORITY(PRIORITY)  ((PRIORITY) < 0x10U)

// 检查子优先级参数是否有效(0-15)
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

// 检查MPU指令访问状态参数是否有效
#define IS_MPU_INSTRUCTION_ACCESS(STATE) (((STATE) == MPU_INSTRUCTION_ACCESS_ENABLE) || \
                                          ((STATE) == MPU_INSTRUCTION_ACCESS_DISABLE))

// 检查MPU访问共享状态参数是否有效
#define IS_MPU_ACCESS_SHAREABLE(STATE)   (((STATE) == MPU_ACCESS_SHAREABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_SHAREABLE))

// 检查MPU访问缓存状态参数是否有效
#define IS_MPU_ACCESS_CACHEABLE(STATE)   (((STATE) == MPU_ACCESS_CACHEABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_CACHEABLE))

// 检查MPU访问缓冲状态参数是否有效
#define IS_MPU_ACCESS_BUFFERABLE(STATE)   (((STATE) == MPU_ACCESS_BUFFERABLE) || \
                                          ((STATE) == MPU_ACCESS_NOT_BUFFERABLE))

// 检查MPU TEX级别参数是否有效
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
 
