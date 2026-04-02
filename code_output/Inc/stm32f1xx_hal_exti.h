/**
  ******************************************************************************
  * @file    stm32f1xx_hal_exti.h
  * @author  MCD Application Team
  * @brief   EXTI HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * 版权所有。
  *
  * 本软件根据LICENSE文件中的条款进行许可。
  * 本软件组件根目录中的LICENSE文件。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -----------------------------------------------------*/
#ifndef STM32F1xx_HAL_EXTI_H
#define STM32F1xx_HAL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup EXTI EXTI
  * @brief EXTI HAL模块驱动
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/

/** @defgroup EXTI_Exported_Types EXTI 导出类型
  * @{
  */

/**
  * @brief  HAL EXTI 通用回调ID枚举定义
  */
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U  // 通用回调ID
} EXTI_CallbackIDTypeDef;

/**
  * @brief  EXTI 句柄结构体定义
  */
typedef struct
{
  uint32_t Line;                    // EXTI中断线号
  void (* PendingCallback)(void);   // EXTI挂起回调函数指针
} EXTI_HandleTypeDef;

/**
  * @brief  EXTI 配置结构体定义
  */
typedef struct
{
  uint32_t Line;      // 要配置的EXTI中断线，参数可以是 @ref EXTI_Line 中的值
  uint32_t Mode;      // 要配置的退出模式（中断或事件），参数可以是 @ref EXTI_Mode 的组合
  uint32_t Trigger;   // 要配置的EXTI触发方式，参数可以是 @ref EXTI_Trigger 中的值
  uint32_t GPIOSel;   // 要配置的EXTI GPIO多路复用选择。
                      // 此参数仅适用于线0到15。它可以是 @ref EXTI_GPIOSel 中的值
} EXTI_ConfigTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup EXTI_Exported_Constants EXTI 导出常量
  * @{
  */

/** @defgroup EXTI_Line  EXTI 中断线
  * @{
  */
#define EXTI_LINE_0                        (EXTI_GPIO     | 0x00u)    // 外部中断线 0
#define EXTI_LINE_1                        (EXTI_GPIO     | 0x01u)    // 外部中断线 1
#define EXTI_LINE_2                        (EXTI_GPIO     | 0x02u)    // 外部中断线 2
#define EXTI_LINE_3                        (EXTI_GPIO     | 0x03u)    // 外部中断线 3
#define EXTI_LINE_4                        (EXTI_GPIO     | 0x04u)    // 外部中断线 4
#define EXTI_LINE_5                        (EXTI_GPIO     | 0x05u)    // 外部中断线 5
#define EXTI_LINE_6                        (EXTI_GPIO     | 0x06u)    // 外部中断线 6
#define EXTI_LINE_7                        (EXTI_GPIO     | 0x07u)    // 外部中断线 7
#define EXTI_LINE_8                        (EXTI_GPIO     | 0x08u)    // 外部中断线 8
#define EXTI_LINE_9                        (EXTI_GPIO     | 0x09u)    // 外部中断线 9
#define EXTI_LINE_10                       (EXTI_GPIO     | 0x0Au)    // 外部中断线 10
#define EXTI_LINE_11                       (EXTI_GPIO     | 0x0Bu)    // 外部中断线 11
#define EXTI_LINE_12                       (EXTI_GPIO     | 0x0Cu)    // 外部中断线 12
#define EXTI_LINE_13                       (EXTI_GPIO     | 0x0Du)    // 外部中断线 13
#define EXTI_LINE_14                       (EXTI_GPIO     | 0x0Eu)    // 外部中断线 14
#define EXTI_LINE_15                       (EXTI_GPIO     | 0x0Fu)    // 外部中断线 15
#define EXTI_LINE_16                       (EXTI_CONFIG   | 0x10u)    // 外部中断线 16，连接到PVD输出（可编程电压检测器）
#define EXTI_LINE_17                       (EXTI_CONFIG   | 0x11u)    // 外部中断线 17，连接到RTC闹钟事件
#if defined(EXTI_IMR_IM18)
#define EXTI_LINE_18                       (EXTI_CONFIG   | 0x12u)    // 外部中断线 18，连接到USB唤醒事件
#endif /* EXTI_IMR_IM18 */
#if defined(EXTI_IMR_IM19)
#define EXTI_LINE_19                       (EXTI_CONFIG   | 0x13u)    // 外部中断线 19，连接到以太网唤醒事件
#endif /* EXTI_IMR_IM19 */

/**
  * @}
  */

/** @defgroup EXTI_Mode  EXTI 模式
  * @{
  */
#define EXTI_MODE_NONE                      0x00000000u   // 无模式
#define EXTI_MODE_INTERRUPT                 0x00000001u   // 中断模式
#define EXTI_MODE_EVENT                     0x00000002u   // 事件模式
/**
  * @}
  */

/** @defgroup EXTI_Trigger  EXTI 触发方式
  * @{
  */
#define EXTI_TRIGGER_NONE                   0x00000000u   // 无触发
#define EXTI_TRIGGER_RISING                 0x00000001u   // 上升沿触发
#define EXTI_TRIGGER_FALLING                0x00000002u   // 下降沿触发
#define EXTI_TRIGGER_RISING_FALLING         (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING) // 双边沿触发（上升沿和下降沿）
/**
  * @}
  */

/** @defgroup EXTI_GPIOSel  EXTI GPIO选择
  * @brief  用于选择外部中断线对应的GPIO端口
  * @{
  */
#define EXTI_GPIOA                          0x00000000u   // 选择GPIOA端口
#define EXTI_GPIOB                          0x00000001u   // 选择GPIOB端口
#define EXTI_GPIOC                          0x00000002u   // 选择GPIOC端口
#define EXTI_GPIOD                          0x00000003u   // 选择GPIOD端口
#if defined (GPIOE)
#define EXTI_GPIOE                          0x00000004u   // 选择GPIOE端口
#endif /* GPIOE */
#if defined (GPIOF)
#define EXTI_GPIOF                          0x00000005u   // 选择GPIOF端口
#endif /* GPIOF */
#if defined (GPIOG)
#define EXTI_GPIOG                          0x00000006u   // 选择GPIOG端口
#endif /* GPIOG */
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup EXTI_Exported_Macros EXTI 导出宏
  * @{
  */

/**
  * @}
  */

/* 私有常量 --------------------------------------------------------*/
/** @defgroup EXTI_Private_Constants EXTI 私有常量
  * @{
  */
/**
  * @brief  EXTI 线属性定义（内部使用）
  */
#define EXTI_PROPERTY_SHIFT                 24u           // 属性移位位数
#define EXTI_CONFIG                         (0x02uL << EXTI_PROPERTY_SHIFT) // 配置属性标记
#define EXTI_GPIO                           ((0x04uL << EXTI_PROPERTY_SHIFT) | EXTI_CONFIG) // GPIO属性标记
#define EXTI_PROPERTY_MASK                  (EXTI_CONFIG | EXTI_GPIO) // 属性掩码

/**
  * @brief  EXTI 引脚使用掩码
  */
#define EXTI_PIN_MASK                       0x0000001Fu   // 引脚号掩码（低5位）

/**
  * @brief  EXTI 中断和事件模式掩码
  */
#define EXTI_MODE_MASK                      (EXTI_MODE_EVENT | EXTI_MODE_INTERRUPT)

/**
  * @brief  EXTI 触发可能性掩码
  */
#define EXTI_TRIGGER_MASK                   (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)

/**
  * @brief  EXTI 线数量
  */
#if defined(EXTI_IMR_IM19)
#define EXTI_LINE_NB                        20UL          // 共20根中断线
#elif defined(EXTI_IMR_IM18)
#define EXTI_LINE_NB                        19UL          // 共19根中断线
#else /* EXTI_IMR_IM17 */
#define EXTI_LINE_NB                        18UL          // 共18根中断线
#endif /* EXTI_IMR_IM19 */
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup EXTI_Private_Macros EXTI 私有宏
  * @{
  */

// 检查EXTI线参数是否合法
// 1. 必须是合法的属性(CONFIG或GPIO)
// 2. 必须在有效线号范围内
#define IS_EXTI_LINE(__EXTI_LINE__)          ((((__EXTI_LINE__) & ~(EXTI_PROPERTY_MASK | EXTI_PIN_MASK)) == 0x00u) && \
                                             ((((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_CONFIG)   || \
                                              (((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_GPIO))    && \
                                              (((__EXTI_LINE__) & EXTI_PIN_MASK) < EXTI_LINE_NB))

// 检查模式参数是否合法
#define IS_EXTI_MODE(__EXTI_LINE__)          ((((__EXTI_LINE__) & EXTI_MODE_MASK) != 0x00u) && \
                                              (((__EXTI_LINE__) & ~EXTI_MODE_MASK) == 0x00u))

// 检查触发方式参数是否合法
#define IS_EXTI_TRIGGER(__EXTI_LINE__)       (((__EXTI_LINE__) & ~EXTI_TRIGGER_MASK) == 0x00u)

// 检查挂起边沿参数是否合法
#define IS_EXTI_PENDING_EDGE(__EXTI_LINE__)  ((__EXTI_LINE__) == EXTI_TRIGGER_RISING_FALLING)

// 检查是否为可配置的EXTI线
#define IS_EXTI_CONFIG_LINE(__EXTI_LINE__)   (((__EXTI_LINE__) & EXTI_CONFIG) != 0x00u)

// 根据不同的GPIO端口定义，检查GPIO端口参数是否合法
#if defined (GPIOG)
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF) || \
                                         ((__PORT__) == EXTI_GPIOG))
#elif defined (GPIOF)
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF))
#elif defined (GPIOE)
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE))
#else
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD))
#endif /* GPIOG */

// 检查GPIO引脚号是否合法（0-15）
#define IS_EXTI_GPIO_PIN(__PIN__)       ((__PIN__) < 16u)

/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/
/** @defgroup EXTI_Exported_Functions EXTI 导出函数
  * @brief    EXTI 导出函数
  * @{
  */

/** @defgroup EXTI_Exported_Functions_Group1 配置函数
  * @brief    配置函数
  * @{
  */
/* 配置函数 ****************************************************/
// 设置EXTI线配置
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
// 获取EXTI线配置
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
// 清除EXTI线配置
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
// 注册回调函数
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
// 获取EXTI句柄
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);
/**
  * @}
  */

/** @defgroup EXTI_Exported_Functions_Group2 IO操作函数
  * @brief    IO操作函数
  * @{
  */
/* IO操作函数 *****************************************************/
// EXTI中断处理函数
void              HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);
// 获取挂起标志
uint32_t          HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
// 清除挂起标志
void              HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
// 产生软件中断
void              HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti);

/**
  * @}
  */

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

#endif /* STM32F1xx_HAL_EXTI_H */
