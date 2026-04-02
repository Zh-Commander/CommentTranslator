/**
  ******************************************************************************
  * @file    stm32f1xx_hal_gpio.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
// 防止递归包含（防止头文件被重复包含）
#ifndef STM32F1xx_HAL_GPIO_H
#define STM32F1xx_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含HAL库通用的定义（如数据类型、宏定义等）
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Types GPIO Exported Types
  * @{
  */

/**
  * @brief GPIO Init structure definition
  */
// GPIO初始化结构体定义，用于配置GPIO引脚的各项参数
typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */
                        // 指定要配置的GPIO引脚号，例如 GPIO_PIN_0, GPIO_PIN_1 等

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */
                        // 指定引脚的工作模式，如输入、输出、复用功能、模拟模式或外部中断模式

  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */
                        // 指定引脚的上拉或下拉电阻配置，用于稳定输入状态

  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */
                        // 指定引脚的输出速度（频率），影响信号的翻转速率
} GPIO_InitTypeDef;

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
// GPIO引脚状态枚举定义，用于表示引脚的电平状态
typedef enum
{
  GPIO_PIN_RESET = 0u,  // 引脚低电平（复位状态）
  GPIO_PIN_SET          // 引脚高电平（置位状态）
} GPIO_PinState;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup GPIO_pins_define GPIO pins define
  * @{
  */
// GPIO引脚编号定义，采用位掩码方式，方便进行位操作
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */ // 选择引脚0
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */ // 选择引脚1
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */ // 选择引脚2
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */ // 选择引脚3
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */ // 选择引脚4
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */ // 选择引脚5
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */ // 选择引脚6
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */ // 选择引脚7
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */ // 选择引脚8
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */ // 选择引脚9
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */ // 选择引脚10
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */ // 选择引脚11
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */ // 选择引脚12
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */ // 选择引脚13
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */ // 选择引脚14
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */ // 选择引脚15
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */ // 选择所有引脚

#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */ // 引脚掩码，用于参数断言检查
/**
  * @}
  */

/** @defgroup GPIO_mode_define GPIO mode define
  * @brief GPIO Configuration Mode
  *        Elements values convention: 0xX0yz00YZ
  *           - X  : GPIO mode or EXTI Mode
  *           - y  : External IT or Event trigger detection
  *           - z  : IO configuration on External IT or Event
  *           - Y  : Output type (Push Pull or Open Drain)
  *           - Z  : IO Direction mode (Input, Output, Alternate or Analog)
  * @{
  */
// GPIO模式定义
#define  GPIO_MODE_INPUT                        0x00000000u   /*!< Input Floating Mode                   */ // 浮空输入模式
#define  GPIO_MODE_OUTPUT_PP                    0x00000001u   /*!< Output Push Pull Mode                 */ // 推挽输出模式
#define  GPIO_MODE_OUTPUT_OD                    0x00000011u   /*!< Output Open Drain Mode                */ // 开漏输出模式
#define  GPIO_MODE_AF_PP                        0x00000002u   /*!< Alternate Function Push Pull Mode     */ // 复用功能推挽输出模式
#define  GPIO_MODE_AF_OD                        0x00000012u   /*!< Alternate Function Open Drain Mode    */ // 复用功能开漏输出模式
#define  GPIO_MODE_AF_INPUT                     GPIO_MODE_INPUT          /*!< Alternate Function Input Mode         */ // 复用功能输入模式

#define  GPIO_MODE_ANALOG                       0x00000003u   /*!< Analog Mode  */ // 模拟模式（用于ADC等）

#define  GPIO_MODE_IT_RISING                    0x10110000u   /*!< External Interrupt Mode with Rising edge trigger detection          */ // 外部中断模式：上升沿触发
#define  GPIO_MODE_IT_FALLING                   0x10210000u   /*!< External Interrupt Mode with Falling edge trigger detection         */ // 外部中断模式：下降沿触发
#define  GPIO_MODE_IT_RISING_FALLING            0x10310000u   /*!< External Interrupt Mode with Rising/Falling edge trigger detection  */ // 外部中断模式：双边沿触发

#define  GPIO_MODE_EVT_RISING                   0x10120000u   /*!< External Event Mode with Rising edge trigger detection               */ // 外部事件模式：上升沿触发
#define  GPIO_MODE_EVT_FALLING                  0x10220000u   /*!< External Event Mode with Falling edge trigger detection              */ // 外部事件模式：下降沿触发
#define  GPIO_MODE_EVT_RISING_FALLING           0x10320000u   /*!< External Event Mode with Rising/Falling edge trigger detection       */ // 外部事件模式：双边沿触发

/**
  * @}
  */

/** @defgroup GPIO_speed_define  GPIO speed define
  * @brief GPIO Output Maximum frequency
  * @{
  */
// GPIO输出速度定义，决定了引脚的最大翻转频率和驱动能力
#define  GPIO_SPEED_FREQ_LOW              (GPIO_CRL_MODE0_1) /*!< Low speed */    // 低速（适用于低频信号，功耗较低）
#define  GPIO_SPEED_FREQ_MEDIUM           (GPIO_CRL_MODE0_0) /*!< Medium speed */ // 中速
#define  GPIO_SPEED_FREQ_HIGH             (GPIO_CRL_MODE0)   /*!< High speed */   // 高速（适用于高频信号，功耗较高）

/**
  * @}
  */

/** @defgroup GPIO_pull_define GPIO pull define
  * @brief GPIO Pull-Up or Pull-Down Activation
  * @{
  */
// GPIO上下拉配置定义
#define  GPIO_NOPULL        0x00000000u   /*!< No Pull-up or Pull-down activation  */ // 无上下拉
#define  GPIO_PULLUP        0x00000001u   /*!< Pull-up activation                  */ // 上拉（默认高电平）
#define  GPIO_PULLDOWN      0x00000002u   /*!< Pull-down activation                */ // 下拉（默认低电平）
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Macros GPIO Exported Macros
  * @{
  */

/**
  * @brief  Checks whether the specified EXTI line flag is set or not.
  * @param  __EXTI_LINE__: specifies the EXTI line flag to check.
  *         This parameter can be GPIO_PIN_x where x can be(0..15)
  * @retval The new state of __EXTI_LINE__ (SET or RESET).
  */
// 检查指定的外部中断线标志位是否被置位（读取挂起寄存器 EXTI->PR）
#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

/**
  * @brief  Clears the EXTI's line pending flags.
  * @param  __EXTI_LINE__: specifies the EXTI lines flags to clear.
  *         This parameter can be any combination of GPIO_PIN_x where x can be (0..15)
  * @retval None
  */
// 清除外部中断线的挂起标志位（通过写1清除）
#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

/**
  * @brief  Checks whether the specified EXTI line is asserted or not.
  * @param  __EXTI_LINE__: specifies the EXTI line to check.
  *          This parameter can be GPIO_PIN_x where x can be(0..15)
  * @retval The new state of __EXTI_LINE__ (SET or RESET).
  */
// 检查指定的外部中断线是否产生了中断请求
#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

/**
  * @brief  Clears the EXTI's line pending bits.
  * @param  __EXTI_LINE__: specifies the EXTI lines to clear.
  *          This parameter can be any combination of GPIO_PIN_x where x can be (0..15)
  * @retval None
  */
// 清除外部中断线的中断挂起位
#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

/**
  * @brief  Generates a Software interrupt on selected EXTI line.
  * @param  __EXTI_LINE__: specifies the EXTI line to check.
  *          This parameter can be GPIO_PIN_x where x can be(0..15)
  * @retval None
  */
// 在选定的外部中断线上产生软件中断
#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__) (EXTI->SWIER |= (__EXTI_LINE__))
/**
  * @}
  */

/* Include GPIO HAL Extension module */
// 包含GPIO HAL扩展模块头文件
#include "stm32f1xx_hal_gpio_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup GPIO_Exported_Functions
  * @{
  */

/** @addtogroup GPIO_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
// 初始化和反初始化函数
void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);   // GPIO初始化函数，配置引脚参数
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);           // GPIO反初始化函数，恢复引脚默认状态
/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
// IO操作函数
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);      // 读取指定引脚的电平状态
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState); // 写入指定引脚的电平状态
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);             // 翻转指定引脚的电平状态
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);  // 锁定指定引脚的配置，防止意外修改
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);                            // 外部中断中断服务函数，处理中断标志
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);                              // 外部中断回调函数，用户在此编写中断处理逻辑

/**
  * @}
  */

/**
  * @}
  */
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO Private Constants
  * @{
  */

/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @defgroup GPIO_Private_Macros GPIO Private Macros
  * @{
  */
// 以下为私有宏定义，主要用于库内部参数检查（断言 Assert）
#define IS_GPIO_PIN_ACTION(ACTION) (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET)) // 检查引脚动作是否合法
#define IS_GPIO_PIN(PIN)           (((((uint32_t)PIN) & GPIO_PIN_MASK ) != 0x00u) && ((((uint32_t)PIN) & ~GPIO_PIN_MASK) == 0x00u)) // 检查引脚号是否合法
#define IS_GPIO_MODE(MODE) (((MODE) == GPIO_MODE_INPUT)              ||\
                            ((MODE) == GPIO_MODE_OUTPUT_PP)          ||\
                            ((MODE) == GPIO_MODE_OUTPUT_OD)          ||\
                            ((MODE) == GPIO_MODE_AF_PP)              ||\
                            ((MODE) == GPIO_MODE_AF_OD)              ||\
                            ((MODE) == GPIO_MODE_IT_RISING)          ||\
                            ((MODE) == GPIO_MODE_IT_FALLING)         ||\
                            ((MODE) == GPIO_MODE_IT_RISING_FALLING)  ||\
                            ((MODE) == GPIO_MODE_EVT_RISING)         ||\
                            ((MODE) == GPIO_MODE_EVT_FALLING)        ||\
                            ((MODE) == GPIO_MODE_EVT_RISING_FALLING) ||\
                            ((MODE) == GPIO_MODE_ANALOG)) // 检查模式参数是否合法
#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_SPEED_FREQ_LOW) || \
                              ((SPEED) == GPIO_SPEED_FREQ_MEDIUM) || ((SPEED) == GPIO_SPEED_FREQ_HIGH)) // 检查速度参数是否合法
#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_NOPULL) || ((PULL) == GPIO_PULLUP) || \
                            ((PULL) == GPIO_PULLDOWN)) // 检查上下拉参数是否合法
/**
  * @}
  */

/* Private functions ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Functions GPIO Private Functions
  * @{
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

#endif /* STM32F1xx_HAL_GPIO_H */
