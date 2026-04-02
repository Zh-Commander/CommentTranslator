/**
  ******************************************************************************
  * @file    stm32f1xx_hal_exti.h
  * @author  MCD Application Team
  * @brief   Header file of EXTI HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
/* 防止递归包含 */
#ifndef STM32F1xx_HAL_EXTI_H
#define STM32F1xx_HAL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup EXTI EXTI
  * @brief EXTI HAL module driver
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* 导出类型 ------------------------------------------------------------------*/

/** @defgroup EXTI_Exported_Types EXTI Exported Types
  * @{
  */

/**
  * @brief  HAL EXTI common Callback ID enumeration definition
  * @brief  HAL EXTI 通用回调 ID 枚举定义
  */
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U  // 通用回调ID，用于注册回调函数时的标识
} EXTI_CallbackIDTypeDef;

/**
  * @brief  EXTI Handle structure definition
  * @brief  EXTI 句柄结构体定义
  */
typedef struct
{
  uint32_t Line;                    /*!<  Exti line number */
                                    /*!<  EXTI 中断线编号，取值范围参考 EXTI_Line 宏定义 */
  void (* PendingCallback)(void);   /*!<  Exti pending callback */
                                    /*!<  EXTI 挂起回调函数指针，当中断发生时执行 */
} EXTI_HandleTypeDef;

/**
  * @brief  EXTI Configuration structure definition
  * @brief  EXTI 配置结构体定义
  */
typedef struct
{
  uint32_t Line;      /*!< The Exti line to be configured. This parameter
                           can be a value of @ref EXTI_Line */
                      /*!< 需要配置的 EXTI 中断线。
                           该参数可以取值为 @ref EXTI_Line 中的值 */

  uint32_t Mode;      /*!< The Exit Mode to be configured for a core.
                           This parameter can be a combination of @ref EXTI_Mode */
                      /*!< 需要配置的 EXTI 模式（中断模式或事件模式）。
                           该参数可以是 @ref EXTI_Mode 的组合 */

  uint32_t Trigger;   /*!< The Exti Trigger to be configured. This parameter
                           can be a value of @ref EXTI_Trigger */
                      /*!< 需要配置的 EXTI 触发方式（上升沿、下降沿或双边沿）。
                           该参数可以取值为 @ref EXTI_Trigger 中的值 */

  uint32_t GPIOSel;   /*!< The Exti GPIO multiplexer selection to be configured.
                           This parameter is only possible for line 0 to 15. It
                           can be a value of @ref EXTI_GPIOSel */
                      /*!< EXTI GPIO 多路复用选择配置。
                           该参数仅对 Line 0 到 Line 15 有效。
                           可以取值为 @ref EXTI_GPIOSel 中的值 */
} EXTI_ConfigTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/* 导出常量 ------------------------------------------------------------------*/
/** @defgroup EXTI_Exported_Constants EXTI Exported Constants
  * @{
  */

/** @defgroup EXTI_Line  EXTI Line
  * @{
  */
/* EXTI 中断线定义 */
/* Line 0 - 15 对应外部 GPIO 引脚中断 */
#define EXTI_LINE_0                        (EXTI_GPIO     | 0x00u)    /*!< External interrupt line 0 */ // 外部中断线 0
#define EXTI_LINE_1                        (EXTI_GPIO     | 0x01u)    /*!< External interrupt line 1 */ // 外部中断线 1
#define EXTI_LINE_2                        (EXTI_GPIO     | 0x02u)    /*!< External interrupt line 2 */ // 外部中断线 2
#define EXTI_LINE_3                        (EXTI_GPIO     | 0x03u)    /*!< External interrupt line 3 */ // 外部中断线 3
#define EXTI_LINE_4                        (EXTI_GPIO     | 0x04u)    /*!< External interrupt line 4 */ // 外部中断线 4
#define EXTI_LINE_5                        (EXTI_GPIO     | 0x05u)    /*!< External interrupt line 5 */ // 外部中断线 5
#define EXTI_LINE_6                        (EXTI_GPIO     | 0x06u)    /*!< External interrupt line 6 */ // 外部中断线 6
#define EXTI_LINE_7                        (EXTI_GPIO     | 0x07u)    /*!< External interrupt line 7 */ // 外部中断线 7
#define EXTI_LINE_8                        (EXTI_GPIO     | 0x08u)    /*!< External interrupt line 8 */ // 外部中断线 8
#define EXTI_LINE_9                        (EXTI_GPIO     | 0x09u)    /*!< External interrupt line 9 */ // 外部中断线 9
#define EXTI_LINE_10                       (EXTI_GPIO     | 0x0Au)    /*!< External interrupt line 10 */ // 外部中断线 10
#define EXTI_LINE_11                       (EXTI_GPIO     | 0x0Bu)    /*!< External interrupt line 11 */ // 外部中断线 11
#define EXTI_LINE_12                       (EXTI_GPIO     | 0x0Cu)    /*!< External interrupt line 12 */ // 外部中断线 12
#define EXTI_LINE_13                       (EXTI_GPIO     | 0x0Du)    /*!< External interrupt line 13 */ // 外部中断线 13
#define EXTI_LINE_14                       (EXTI_GPIO     | 0x0Eu)    /*!< External interrupt line 14 */ // 外部中断线 14
#define EXTI_LINE_15                       (EXTI_GPIO     | 0x0Fu)    /*!< External interrupt line 15 */ // 外部中断线 15

/* Line 16 - 19 对应内部外设中断 */
#define EXTI_LINE_16                       (EXTI_CONFIG   | 0x10u)    /*!< External interrupt line 16 Connected to the PVD Output */
                                                                      // 外部中断线 16，连接到 PVD（可编程电压检测器）输出
#define EXTI_LINE_17                       (EXTI_CONFIG   | 0x11u)    /*!< External interrupt line 17 Connected to the RTC Alarm event */
                                                                      // 外部中断线 17，连接到 RTC 闹钟事件
#if defined(EXTI_IMR_IM18)
#define EXTI_LINE_18                       (EXTI_CONFIG   | 0x12u)    /*!< External interrupt line 18 Connected to the USB Wakeup from suspend event */
                                                                      // 外部中断线 18，连接到 USB 唤醒事件（取决于芯片是否支持）
#endif /* EXTI_IMR_IM18 */
#if defined(EXTI_IMR_IM19)
#define EXTI_LINE_19                       (EXTI_CONFIG   | 0x13u)    /*!< External interrupt line 19 Connected to the Ethernet Wakeup event */
                                                                      // 外部中断线 19，连接到以太网唤醒事件（取决于芯片是否支持）
#endif /* EXTI_IMR_IM19 */

/**
  * @}
  */

/** @defgroup EXTI_Mode  EXTI Mode
  * @{
  */
/* EXTI 模式定义 */
#define EXTI_MODE_NONE                      0x00000000u  // 无模式
#define EXTI_MODE_INTERRUPT                 0x00000001u  // 中断模式（产生中断请求）
#define EXTI_MODE_EVENT                     0x00000002u  // 事件模式（产生事件脉冲，用于唤醒内核等）
/**
  * @}
  */

/** @defgroup EXTI_Trigger  EXTI Trigger
  * @{
  */
/* EXTI 触发方式定义 */
#define EXTI_TRIGGER_NONE                   0x00000000u  // 无触发
#define EXTI_TRIGGER_RISING                 0x00000001u  // 上升沿触发
#define EXTI_TRIGGER_FALLING                0x00000002u  // 下降沿触发
#define EXTI_TRIGGER_RISING_FALLING         (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING) // 双边沿触发（上升沿和下降沿都触发）
/**
  * @}
  */

/** @defgroup EXTI_GPIOSel  EXTI GPIOSel
  * @brief
  * @{
  */
/* EXTI GPIO 端口选择定义 */
/* 用于选择哪个 GPIO 端口的中断线映射到 EXTI Line 0-15 */
#define EXTI_GPIOA                          0x00000000u  // 选择 GPIOA 端口
#define EXTI_GPIOB                          0x00000001u  // 选择 GPIOB 端口
#define EXTI_GPIOC                          0x00000002u  // 选择 GPIOC 端口
#define EXTI_GPIOD                          0x00000003u  // 选择 GPIOD 端口
#if defined (GPIOE)
#define EXTI_GPIOE                          0x00000004u  // 选择 GPIOE 端口（取决于芯片是否有 GPIOE）
#endif /* GPIOE */
#if defined (GPIOF)
#define EXTI_GPIOF                          0x00000005u  // 选择 GPIOF 端口（取决于芯片是否有 GPIOF）
#endif /* GPIOF */
#if defined (GPIOG)
#define EXTI_GPIOG                          0x00000006u  // 选择 GPIOG 端口（取决于芯片是否有 GPIOG）
#endif /* GPIOG */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup EXTI_Exported_Macros EXTI Exported Macros
  * @{
  */

/**
  * @}
  */

/* Private constants --------------------------------------------------------*/
/* 私有常量 ------------------------------------------------------------------*/
/** @defgroup EXTI_Private_Constants EXTI Private Constants
  * @{
  */
/**
  * @brief  EXTI Line property definition
  * @brief  EXTI 线属性定义（内部使用的位掩码）
  */
#define EXTI_PROPERTY_SHIFT                 24u          // 属性移位位数，用于区分 Line 类型
#define EXTI_CONFIG                         (0x02uL << EXTI_PROPERTY_SHIFT) // 配置属性标记，表示该线需要配置（如 PVD, RTC 等）
#define EXTI_GPIO                           ((0x04uL << EXTI_PROPERTY_SHIFT) | EXTI_CONFIG) // GPIO 属性标记，表示该线由 GPIO 触发
#define EXTI_PROPERTY_MASK                  (EXTI_CONFIG | EXTI_GPIO) // 属性掩码，用于提取属性位

/**
  * @brief  EXTI bit usage
  * @brief  EXTI 引脚位使用定义
  */
#define EXTI_PIN_MASK                       0x0000001Fu  // 引脚编号掩码，用于提取低 5 位表示的线号 (0-19)

/**
  * @brief  EXTI Mask for interrupt & event mode
  * @brief  EXTI 中断和事件模式掩码
  */
#define EXTI_MODE_MASK                      (EXTI_MODE_EVENT | EXTI_MODE_INTERRUPT)

/**
  * @brief  EXTI Mask for trigger possibilities
  * @brief  EXTI 触发方式掩码
  */
#define EXTI_TRIGGER_MASK                   (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)

/**
  * @brief  EXTI Line number
  * @brief  EXTI 线数量定义
  */
#if defined(EXTI_IMR_IM19)
#define EXTI_LINE_NB                        20UL         // 支持 20 条中断线
#elif defined(EXTI_IMR_IM18)
#define EXTI_LINE_NB                        19UL         // 支持 19 条中断线
#else /* EXTI_IMR_IM17 */
#define EXTI_LINE_NB                        18UL         // 支持 18 条中断线
#endif /* EXTI_IMR_IM19 */
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/* 私有宏 --------------------------------------------------------------------*/
/** @defgroup EXTI_Private_Macros EXTI Private Macros
  * @{
  */

/**
  * @brief  检查指定的 EXTI 线是否有效
  * @param  __EXTI_LINE__: EXTI 线号
  * @retval 如果有效则返回 1，否则返回 0
  */
#define IS_EXTI_LINE(__EXTI_LINE__)          ((((__EXTI_LINE__) & ~(EXTI_PROPERTY_MASK | EXTI_PIN_MASK)) == 0x00u) && \
                                             ((((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_CONFIG)   || \
                                              (((__EXTI_LINE__) & EXTI_PROPERTY_MASK) == EXTI_GPIO))    && \
                                              (((__EXTI_LINE__) & EXTI_PIN_MASK) < EXTI_LINE_NB))

/**
  * @brief  检查指定的 EXTI 模式是否有效
  * @param  __EXTI_LINE__: EXTI 模式
  * @retval 如果有效则返回 1，否则返回 0
  */
#define IS_EXTI_MODE(__EXTI_LINE__)          ((((__EXTI_LINE__) & EXTI_MODE_MASK) != 0x00u) && \
                                              (((__EXTI_LINE__) & ~EXTI_MODE_MASK) == 0x00u))

/**
  * @brief  检查指定的 EXTI 触发方式是否有效
  * @param  __EXTI_LINE__: EXTI 触发方式
  * @retval 如果有效则返回 1，否则返回 0
  */
#define IS_EXTI_TRIGGER(__EXTI_LINE__)       (((__EXTI_LINE__) & ~EXTI_TRIGGER_MASK) == 0x00u)

/**
  * @brief  检查指定的 EXTI 挂起边沿是否有效（仅支持双边沿）
  * @param  __EXTI_LINE__: EXTI 边沿
  * @retval 如果有效则返回 1，否则返回 0
  */
#define IS_EXTI_PENDING_EDGE(__EXTI_LINE__)  ((__EXTI_LINE__) == EXTI_TRIGGER_RISING_FALLING)

/**
  * @brief  检查指定的 EXTI 线是否为可配置线
  * @param  __EXTI_LINE__: EXTI 线号
  * @retval 如果是可配置线则返回 1，否则返回 0
  */
#define IS_EXTI_CONFIG_LINE(__EXTI_LINE__)   (((__EXTI_LINE__) & EXTI_CONFIG) != 0x00u)

#if defined (GPIOG)
/**
  * @brief  检查指定的 GPIO 端口是否有效（包含 GPIOG）
  * @param  __PORT__: GPIO 端口
  * @retval 如果有效则返回 1，否则返回 0
  */
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF) || \
                                         ((__PORT__) == EXTI_GPIOG))
#elif defined (GPIOF)
/**
  * @brief  检查指定的 GPIO 端口是否有效（包含 GPIOF）
  */
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE) || \
                                         ((__PORT__) == EXTI_GPIOF))
#elif defined (GPIOE)
/**
  * @brief  检查指定的 GPIO 端口是否有效（包含 GPIOE）
  */
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD) || \
                                         ((__PORT__) == EXTI_GPIOE))
#else
/**
  * @brief  检查指定的 GPIO 端口是否有效（仅基础端口 A-D）
  */
#define IS_EXTI_GPIO_PORT(__PORT__)     (((__PORT__) == EXTI_GPIOA) || \
                                         ((__PORT__) == EXTI_GPIOB) || \
                                         ((__PORT__) == EXTI_GPIOC) || \
                                         ((__PORT__) == EXTI_GPIOD))
#endif /* GPIOG */

/**
  * @brief  检查指定的 GPIO 引脚号是否有效（0-15）
  * @param  __PIN__: GPIO 引脚号
  * @retval 如果有效则返回 1，否则返回 0
  */
#define IS_EXTI_GPIO_PIN(__PIN__)       ((__PIN__) < 16u)

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------------*/
/** @defgroup EXTI_Exported_Functions EXTI Exported Functions
  * @brief    EXTI Exported Functions
  * @{
  */

/** @defgroup EXTI_Exported_Functions_Group1 Configuration functions
  * @brief    Configuration functions
  * @{
  */
/* Configuration functions ****************************************************/
/* 配置函数 ******************************************************************/

/**
  * @brief  设置 EXTI 线配置
  * @param  hexti: EXTI 句柄指针
  * @param  pExtiConfig: EXTI 配置结构体指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);

/**
  * @brief  获取 EXTI 线配置
  * @param  hexti: EXTI 句柄指针
  * @param  pExtiConfig: 用于存储配置的结构体指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);

/**
  * @brief  清除 EXTI 线配置
  * @param  hexti: EXTI 句柄指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);

/**
  * @brief  注册 EXTI 回调函数
  * @param  hexti: EXTI 句柄指针
  * @param  CallbackID: 回调 ID（目前仅支持通用 ID）
  * @param  pPendingCbfn: 回调函数指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));

/**
  * @brief  获取 EXTI 句柄
  * @param  hexti: EXTI 句柄指针
  * @param  ExtiLine: EXTI 线号
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);
/**
  * @}
  */

/** @defgroup EXTI_Exported_Functions_Group2 IO operation functions
  * @brief    IO operation functions
  * @{
  */
/* IO operation functions *****************************************************/
/* I/O 操作函数 ***************************************************************/

/**
  * @brief  EXTI 中断处理函数
  * @param  hexti: EXTI 句柄指针
  * @retval 无
  */
void              HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);

/**
  * @brief  获取 EXTI 挂起标志
  * @param  hexti: EXTI 句柄指针
  * @param  Edge: 触发边沿（未使用，保留兼容性）
  * @retval 挂起状态 (1: 挂起, 0: 未挂起)
  */
uint32_t          HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);

/**
  * @brief  清除 EXTI 挂起标志
  * @param  hexti: EXTI 句柄指针
  * @param  Edge: 触发边沿（未使用，保留兼容性）
  * @retval 无
  */
void              HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);

/**
  * @brief  产生软件中断
  * @param  hexti: EXTI 句柄指针
  * @retval 无
  */
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
