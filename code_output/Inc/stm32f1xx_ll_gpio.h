/**
  ******************************************************************************
  * @file    stm32f1xx_ll_gpio.h
  * @author  MCD Application Team
  * @brief   GPIO LL(底层库)模块头文件。
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

/* 定义防止递归包含 -------------------------------------*/
#ifndef STM32F1xx_LL_GPIO_H
#define STM32F1xx_LL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

/* 检查是否定义了GPIO端口，只有定义了才编译以下代码 */
#if defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF) || defined (GPIOG)

/** @defgroup GPIO_LL GPIO
  * @{
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/

/** @defgroup GPIO_LL_Private_Constants GPIO 私有常量
  * @{
  */
/* 用于引脚掩码初始化的定义 */
/* 引脚掩码偏移位置，用于计算寄存器操作位 */
#define GPIO_PIN_MASK_POS   8U
/* GPIO引脚数量，通常为16个 */
#define GPIO_PIN_NB         16U
/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_Private_Macros GPIO 私有宏
  * @{
  */

/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* 导出类型 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_ES_INIT GPIO 导出初始化结构体
  * @{
  */

/**
  * @brief LL GPIO 初始化结构体定义
  * @note  用于配置GPIO的基本参数
  */
typedef struct
{
  uint32_t Pin;          /*!< 指定要配置的GPIO引脚。
                              该参数可以是 @ref GPIO_LL_EC_PIN 中的任意值 */

  uint32_t Mode;         /*!< 指定所选引脚的操作模式。
                              该参数可以是 @ref GPIO_LL_EC_MODE 中的值。

                              GPIO硬件配置之后可以使用单元函数 @ref LL_GPIO_SetPinMode() 进行修改。*/

  uint32_t Speed;        /*!< 指定所选引脚的输出速度。
                              该参数可以是 @ref GPIO_LL_EC_SPEED 中的值。

                              GPIO硬件配置之后可以使用单元函数 @ref LL_GPIO_SetPinSpeed() 进行修改。*/

  uint32_t OutputType;   /*!< 指定所选引脚的输出类型。
                              该参数可以是 @ref GPIO_LL_EC_OUTPUT 中的值。

                              GPIO硬件配置之后可以使用单元函数 @ref LL_GPIO_SetPinOutputType() 进行修改。*/

  uint32_t Pull;         /*!< 指定所选引脚的上拉/下拉操作。
                              该参数可以是 @ref GPIO_LL_EC_PULL 中的值。

                              GPIO硬件配置之后可以使用单元函数 @ref LL_GPIO_SetPinPull() 进行修改。*/
} LL_GPIO_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Constants GPIO 导出常量
  * @{
  */

/** @defgroup GPIO_LL_EC_PIN 引脚定义
  * @{
  */
/* 引脚定义，通过移位操作组合成特定的配置值 */
#define LL_GPIO_PIN_0                    ((GPIO_BSRR_BS0  << GPIO_PIN_MASK_POS) | 0x00000001U)  /*!< 选择引脚 0  */
#define LL_GPIO_PIN_1                    ((GPIO_BSRR_BS1  << GPIO_PIN_MASK_POS) | 0x00000002U)  /*!< 选择引脚 1  */
#define LL_GPIO_PIN_2                    ((GPIO_BSRR_BS2  << GPIO_PIN_MASK_POS) | 0x00000004U)  /*!< 选择引脚 2  */
#define LL_GPIO_PIN_3                    ((GPIO_BSRR_BS3  << GPIO_PIN_MASK_POS) | 0x00000008U)  /*!< 选择引脚 3  */
#define LL_GPIO_PIN_4                    ((GPIO_BSRR_BS4  << GPIO_PIN_MASK_POS) | 0x00000010U)  /*!< 选择引脚 4  */
#define LL_GPIO_PIN_5                    ((GPIO_BSRR_BS5  << GPIO_PIN_MASK_POS) | 0x00000020U)  /*!< 选择引脚 5  */
#define LL_GPIO_PIN_6                    ((GPIO_BSRR_BS6  << GPIO_PIN_MASK_POS) | 0x00000040U)  /*!< 选择引脚 6  */
#define LL_GPIO_PIN_7                    ((GPIO_BSRR_BS7  << GPIO_PIN_MASK_POS) | 0x00000080U)  /*!< 选择引脚 7  */
#define LL_GPIO_PIN_8                    ((GPIO_BSRR_BS8  << GPIO_PIN_MASK_POS) | 0x04000001U)  /*!< 选择引脚 8  */
#define LL_GPIO_PIN_9                    ((GPIO_BSRR_BS9  << GPIO_PIN_MASK_POS) | 0x04000002U)  /*!< 选择引脚 9  */
#define LL_GPIO_PIN_10                   ((GPIO_BSRR_BS10 << GPIO_PIN_MASK_POS) | 0x04000004U)  /*!< 选择引脚 10 */
#define LL_GPIO_PIN_11                   ((GPIO_BSRR_BS11 << GPIO_PIN_MASK_POS) | 0x04000008U)  /*!< 选择引脚 11 */
#define LL_GPIO_PIN_12                   ((GPIO_BSRR_BS12 << GPIO_PIN_MASK_POS) | 0x04000010U)  /*!< 选择引脚 12 */
#define LL_GPIO_PIN_13                   ((GPIO_BSRR_BS13 << GPIO_PIN_MASK_POS) | 0x04000020U)  /*!< 选择引脚 13 */
#define LL_GPIO_PIN_14                   ((GPIO_BSRR_BS14 << GPIO_PIN_MASK_POS) | 0x04000040U)  /*!< 选择引脚 14 */
#define LL_GPIO_PIN_15                   ((GPIO_BSRR_BS15 << GPIO_PIN_MASK_POS) | 0x04000080U)  /*!< 选择引脚 15 */
/* 所有引脚的掩码，用于一次性操作所有引脚 */
#define LL_GPIO_PIN_ALL                  (LL_GPIO_PIN_0  | LL_GPIO_PIN_1  | LL_GPIO_PIN_2  | \
                                          LL_GPIO_PIN_3  | LL_GPIO_PIN_4  | LL_GPIO_PIN_5  | \
                                          LL_GPIO_PIN_6  | LL_GPIO_PIN_7  | LL_GPIO_PIN_8  | \
                                          LL_GPIO_PIN_9  | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | \
                                          LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | \
                                          LL_GPIO_PIN_15)                                      /*!< 选择所有引脚 */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_MODE 模式定义
  * @{
  */
#define LL_GPIO_MODE_ANALOG              0x00000000U       /*!< 选择模拟模式 */
#define LL_GPIO_MODE_FLOATING            GPIO_CRL_CNF0_0   /*!< 选择浮空输入模式 */
#define LL_GPIO_MODE_INPUT               GPIO_CRL_CNF0_1   /*!< 选择输入模式(上拉/下拉) */
#define LL_GPIO_MODE_OUTPUT              GPIO_CRL_MODE0_0  /*!< 选择通用输出模式 */
#define LL_GPIO_MODE_ALTERNATE           (GPIO_CRL_CNF0_1 | GPIO_CRL_MODE0_0) /*!< 选择复用功能模式 */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_OUTPUT 输出类型
  * @{
  */
#define LL_GPIO_OUTPUT_PUSHPULL          0x00000000U                /*!< 选择推挽输出类型 */
#define LL_GPIO_OUTPUT_OPENDRAIN         GPIO_CRL_CNF0_0            /*!< 选择开漏输出类型 */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_SPEED 输出速度
  * @{
  */
#define LL_GPIO_MODE_OUTPUT_10MHz        GPIO_CRL_MODE0_0            /*!< 选择输出模式，最大速度 10 MHz */
#define LL_GPIO_MODE_OUTPUT_2MHz         GPIO_CRL_MODE0_1            /*!< 选择输出模式，最大速度 2 MHz */
#define LL_GPIO_MODE_OUTPUT_50MHz        GPIO_CRL_MODE0              /*!< 选择输出模式，最大速度 50 MHz */
/**
  * @}
  */

/* 为了兼容性和可读性定义的频率速度别名 */
#define LL_GPIO_SPEED_FREQ_LOW           LL_GPIO_MODE_OUTPUT_2MHz    /*!< 选择低输出速度    */
#define LL_GPIO_SPEED_FREQ_MEDIUM        LL_GPIO_MODE_OUTPUT_10MHz   /*!< 选择中输出速度 */
#define LL_GPIO_SPEED_FREQ_HIGH          LL_GPIO_MODE_OUTPUT_50MHz   /*!< 选择高输出速度   */

/** @defgroup GPIO_LL_EC_PULL 上拉下拉
  * @{
  */
#define LL_GPIO_PULL_DOWN                0x00000000U    /*!< 选择下拉 */
#define LL_GPIO_PULL_UP                  GPIO_ODR_ODR0  /*!< 选择上拉 */

/**
  * @}
  */

/** @defgroup GPIO_LL_EVENTOUT_PIN 事件输出引脚
  * @{
  */

#define LL_GPIO_AF_EVENTOUT_PIN_0        AFIO_EVCR_PIN_PX0   /*!< 引脚 0 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_1        AFIO_EVCR_PIN_PX1   /*!< 引脚 1 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_2        AFIO_EVCR_PIN_PX2   /*!< 引脚 2 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_3        AFIO_EVCR_PIN_PX3   /*!< 引脚 3 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_4        AFIO_EVCR_PIN_PX4   /*!< 引脚 4 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_5        AFIO_EVCR_PIN_PX5   /*!< 引脚 5 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_6        AFIO_EVCR_PIN_PX6   /*!< 引脚 6 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_7        AFIO_EVCR_PIN_PX7   /*!< 引脚 7 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_8        AFIO_EVCR_PIN_PX8   /*!< 引脚 8 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_9        AFIO_EVCR_PIN_PX9   /*!< 引脚 9 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_10       AFIO_EVCR_PIN_PX10  /*!< 引脚 10 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_11       AFIO_EVCR_PIN_PX11  /*!< 引脚 11 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_12       AFIO_EVCR_PIN_PX12  /*!< 引脚 12 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_13       AFIO_EVCR_PIN_PX13  /*!< 引脚 13 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_14       AFIO_EVCR_PIN_PX14  /*!< 引脚 14 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PIN_15       AFIO_EVCR_PIN_PX15  /*!< 引脚 15 输出事件 */

/**
  * @}
  */

/** @defgroup GPIO_LL_EVENTOUT_PORT 事件输出端口
  * @{
  */

#define LL_GPIO_AF_EVENTOUT_PORT_A       AFIO_EVCR_PORT_PA  /*!< 端口 A 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PORT_B       AFIO_EVCR_PORT_PB  /*!< 端口 B 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PORT_C       AFIO_EVCR_PORT_PC  /*!< 端口 C 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PORT_D       AFIO_EVCR_PORT_PD  /*!< 端口 D 输出事件 */
#define LL_GPIO_AF_EVENTOUT_PORT_E       AFIO_EVCR_PORT_PE  /*!< 端口 E 输出事件 */

/**
  * @}
  */

/** @defgroup GPIO_LL_EC_EXTI_PORT GPIO 外部中断端口
  * @{
  */
#define LL_GPIO_AF_EXTI_PORTA            0U   /*!< 外部中断端口 A */
#define LL_GPIO_AF_EXTI_PORTB            1U   /*!< 外部中断端口 B */
#define LL_GPIO_AF_EXTI_PORTC            2U   /*!< 外部中断端口 C */
#define LL_GPIO_AF_EXTI_PORTD            3U   /*!< 外部中断端口 D */
#define LL_GPIO_AF_EXTI_PORTE            4U   /*!< 外部中断端口 E */
#define LL_GPIO_AF_EXTI_PORTF            5U   /*!< 外部中断端口 F */
#define LL_GPIO_AF_EXTI_PORTG            6U   /*!< 外部中断端口 G */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_EXTI_LINE GPIO 外部中断线
  * @{
  */
/* 定义外部中断线，包含寄存器索引和位位置信息 */
#define LL_GPIO_AF_EXTI_LINE0            (0x000FU << 16U | 0U)  /*!< EXTI线0  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE1            (0x00F0U << 16U | 0U)  /*!< EXTI线1  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE2            (0x0F00U << 16U | 0U)  /*!< EXTI线2  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE3            (0xF000U << 16U | 0U)  /*!< EXTI线3  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE4            (0x000FU << 16U | 1U)  /*!< EXTI线4  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE5            (0x00F0U << 16U | 1U)  /*!< EXTI线5  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE6            (0x0F00U << 16U | 1U)  /*!< EXTI线6  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE7            (0xF000U << 16U | 1U)  /*!< EXTI线7  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE8            (0x000FU << 16U | 2U)  /*!< EXTI线8  | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE9            (0x00F0U << 16U | 2U)  /*!< EXTI线9  | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE10           (0x0F00U << 16U | 2U)  /*!< EXTI线10 | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE11           (0xF000U << 16U | 2U)  /*!< EXTI线11 | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE12           (0x000FU << 16U | 3U)  /*!< EXTI线12 | EXTICR[3] */
#define LL_GPIO_AF_EXTI_LINE13           (0x00F0U << 16U | 3U)  /*!< EXTI线13 | EXTICR[3] */
#define LL_GPIO_AF_EXTI_LINE14           (0x0F00U << 16U | 3U)  /*!< EXTI线14 | EXTICR[3] */
#define LL_GPIO_AF_EXTI_LINE15           (0xF000U << 16U | 3U)  /*!< EXTI线15 | EXTICR[3] */
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Macros GPIO 导出宏
  * @{
  */

/** @defgroup GPIO_LL_EM_WRITE_READ 通用读写寄存器宏
  * @{
  */

/**
  * @brief  写入值到GPIO寄存器
  * @param  __INSTANCE__ GPIO 实例 (如 GPIOA, GPIOB)
  * @param  __REG__ 要写入的寄存器 (如 CRL, CRH, ODR)
  * @param  __VALUE__ 要写入寄存器的值
  * @retval 无
  */
#define LL_GPIO_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  读取GPIO寄存器中的值
  * @param  __INSTANCE__ GPIO 实例
  * @param  __REG__ 要读取的寄存器
  * @retval 寄存器值
  */
#define LL_GPIO_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Functions GPIO 导出函数
  * @{
  */

/** @defgroup GPIO_LL_EF_Port_Configuration 端口配置
  * @{
  */

/**
  * @brief  配置指定端口上指定引脚的GPIO模式。
  * @note   I/O模式可以是模拟、浮空输入、上拉/下拉输入、通用输出、复用功能输出。
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll CRL        CNFy         LL_GPIO_SetPinMode
  * @rmtoll CRL        MODEy        LL_GPIO_SetPinMode
  * @rmtoll CRH        CNFy         LL_GPIO_SetPinMode
  * @rmtoll CRH        MODEy        LL_GPIO_SetPinMode
  * @param  GPIOx GPIO 端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Mode 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_MODE_ANALOG
  *         @arg @ref LL_GPIO_MODE_FLOATING
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  *         @arg @ref LL_GPIO_MODE_ALTERNATE
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
  /* 根据引脚号计算寄存器地址：Pin>>24用于判断是低8位(CRL)还是高8位(CRH) */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  /* 修改寄存器值：先清除对应的CNF和MODE位，再设置新的Mode值 */
  MODIFY_REG(*pReg, ((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << (POSITION_VAL(Pin) * 4U)), (Mode << (POSITION_VAL(Pin) * 4U)));
}

/**
  * @brief  获取指定端口上指定引脚的GPIO模式。
  * @note   I/O模式可以是模拟、浮空输入、上拉/下拉输入、通用输出、复用功能输出。
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll CRL        CNFy         LL_GPIO_GetPinMode
  * @rmtoll CRL        MODEy        LL_GPIO_GetPinMode
  * @rmtoll CRH        CNFy         LL_GPIO_GetPinMode
  * @rmtoll CRH        MODEy        LL_GPIO_GetPinMode
  * @param  GPIOx GPIO 端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_MODE_ANALOG
  *         @arg @ref LL_GPIO_MODE_FLOATING
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  *         @arg @ref LL_GPIO_MODE_ALTERNATE
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 根据引脚号计算寄存器地址 */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  /* 读取寄存器值并右移对齐，获取当前引脚的模式配置 */
  return (READ_BIT(*pReg, ((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));
}

/**
  * @brief  配置指定端口上指定引脚的GPIO速度。
  * @note   I/O速度可以是低、中或高速。
  * @note   警告: 参数只能传递一个引脚。
  * @note   请参考数据手册了解频率规格以及每种速度的电源和负载条件。
  * @rmtoll CRL      MODEy       LL_GPIO_SetPinSpeed
  * @rmtoll CRH      MODEy       LL_GPIO_SetPinSpeed
  * @param  GPIOx GPIO 端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Speed 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref LL_GPIO_SPEED_FREQ_HIGH
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetPinSpeed(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t  Speed)
{
  /* 根据引脚号计算寄存器地址 */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  /* 修改寄存器值：清除对应的MODE位，然后设置新的Speed值 */
  MODIFY_REG(*pReg, (GPIO_CRL_MODE0 << (POSITION_VAL(Pin) * 4U)),
             (Speed << (POSITION_VAL(Pin) * 4U)));
}
/**
  * @brief  获取指定端口上指定引脚的速度配置。
  * @note   I/O速度可以是低速、中速、快速或高速。
  * @note   警告: 参数只能传递一个引脚。
  * @note   请参考数据手册中关于每种速度的频率规格以及电源和负载条件。
  * @rmtoll CRL      MODEy       LL_GPIO_GetPinSpeed
  * @rmtoll CRH      MODEy       LL_GPIO_GetPinSpeed
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref LL_GPIO_SPEED_FREQ_HIGH
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinSpeed(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 
     计算寄存器地址：根据引脚号判断是配置低8位寄存器(CRL)还是高8位寄存器(CRH)。
     Pin >> 24 用于获取引脚所在的寄存器偏移量（STM32F1系列设计中，Pin的高8位存储了偏移信息）。
  */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  
  /* 
     读取寄存器值，提取对应位的配置。
     1. POSITION_VAL(Pin) 获取引脚号(0-15)。
     2. 引脚配置每4位一组，所以偏移量为 引脚号 * 4。
     3. 读取对应位并右移到最低位，返回速度配置值。
  */
  return (READ_BIT(*pReg, (GPIO_CRL_MODE0 << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));
}

/**
  * @brief  配置指定端口上多个引脚的输出类型。
  * @note   输出类型必须在GPIO引脚处于输出模式或复用模式时设置。可能的类型是推挽或开漏。
  * @rmtoll CRL       MODEy           LL_GPIO_SetPinOutputType
  * @rmtoll CRH       MODEy           LL_GPIO_SetPinOutputType
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @param  OutputType 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_OUTPUT_PUSHPULL (推挽输出)
  *         @arg @ref LL_GPIO_OUTPUT_OPENDRAIN (开漏输出)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t OutputType)
{
  /* 计算配置寄存器地址(CRL或CRH) */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  
  /* 
     修改寄存器配置。
     使用MODIFY_REG宏：先清除对应的CNF配置位，然后设置新的OutputType配置位。
     注意：在STM32F1中，输出类型配置在CNF位中。
  */
  MODIFY_REG(*pReg, (GPIO_CRL_CNF0_0 << (POSITION_VAL(Pin) * 4U)),
             (OutputType << (POSITION_VAL(Pin) * 4U)));
}

/**
  * @brief  获取指定端口上多个引脚的输出类型。
  * @note   输出类型必须在GPIO引脚处于输出模式或复用模式时设置。可能的类型是推挽或开漏。
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll CRL       MODEy       LL_GPIO_GetPinOutputType
  * @rmtoll CRH       MODEy       LL_GPIO_GetPinOutputType
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_OUTPUT_PUSHPULL
  *         @arg @ref LL_GPIO_OUTPUT_OPENDRAIN
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinOutputType(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 计算配置寄存器地址(CRL或CRH) */
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  
  /* 读取并返回CNF配置位，获取输出类型 */
  return (READ_BIT(*pReg, (GPIO_CRL_CNF0_0 << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));

}

/**
  * @brief  配置指定端口上指定引脚的上拉或下拉。
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll ODR        ODR         LL_GPIO_SetPinPull
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @param  Pull 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PULL_DOWN
  *         @arg @ref LL_GPIO_PULL_UP
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Pull)
{
  /* 
     在STM32F1系列中，上拉/下拉是通过ODR(输出数据寄存器)配合模式配置实现的。
     这里通过修改ODR寄存器对应的位来设置上拉(Pull=1)或下拉(Pull=0)。
     Pin >> GPIO_PIN_MASK_POS 用于将Pin宏转换为位偏移。
  */
  MODIFY_REG(GPIOx->ODR, (Pin >> GPIO_PIN_MASK_POS), Pull << (POSITION_VAL(Pin >> GPIO_PIN_MASK_POS)));
}

/**
  * @brief  获取指定端口上指定引脚的上拉或下拉配置
  * @note   警告: 参数只能传递一个引脚。
  * @rmtoll ODR        ODR         LL_GPIO_GetPinPull
  * @param  GPIOx GPIO端口
  * @param  Pin 该参数可以是以下值之一:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_PULL_DOWN
  *         @arg @ref LL_GPIO_PULL_UP
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinPull(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  /* 读取ODR寄存器中对应位的值，判断是上拉还是下拉 */
  return (READ_BIT(GPIOx->ODR, (GPIO_ODR_ODR0 << (POSITION_VAL(Pin >> GPIO_PIN_MASK_POS)))) >> (POSITION_VAL(Pin >> GPIO_PIN_MASK_POS)));
}

/**
  * @brief  锁定指定端口上多个引脚的配置。
  * @note   当锁定序列应用于端口位时，该端口位的值在下次复位前不能再被修改。
  * @note   每个锁定位冻结特定的配置寄存器(控制和复用功能寄存器)。
  * @rmtoll LCKR         LCKK          LL_GPIO_LockPin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  __IO uint32_t temp;
  
  /* 
     GPIO锁定序列：
     写入LCKK位和引脚位
     这是一个特定的硬件锁定序列，用于锁定引脚配置。
  */
  /* 第1步: 写入LCKK=1 + 需要锁定的引脚位 */
  WRITE_REG(GPIOx->LCKR, GPIO_LCKR_LCKK | ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
  
  /* 第2步: 写入LCKK=0 + 需要锁定的引脚位 */
  WRITE_REG(GPIOx->LCKR, ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
  
  /* 第3步: 写入LCKK=1 + 需要锁定的引脚位 */
  WRITE_REG(GPIOx->LCKR, GPIO_LCKR_LCKK | ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
  
  /* 第4步: 读取LCKR寄存器，完成锁定 */
  temp = READ_REG(GPIOx->LCKR);
  (void) temp; // 防止编译器警告，确保读取操作发生
}

/**
  * @brief  如果指定端口上传递的所有引脚都被锁定，则返回1，否则返回0。
  * @rmtoll LCKR         LCKy          LL_GPIO_IsPinLocked
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsPinLocked(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取LCKR寄存器，检查指定引脚的锁定状态位是否匹配 */
  return (READ_BIT(GPIOx->LCKR, ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU)) == ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
}

/**
  * @brief  如果指定端口上有任意一个引脚被锁定，则返回1，否则返回0。
  * @rmtoll LCKR         LCKK          LL_GPIO_IsAnyPinLocked
  * @param  GPIOx GPIO端口
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsAnyPinLocked(GPIO_TypeDef *GPIOx)
{
  /* 读取LCKR寄存器的LCKK位(锁定键)，判断是否处于锁定状态 */
  return (READ_BIT(GPIOx->LCKR, GPIO_LCKR_LCKK) == (GPIO_LCKR_LCKK));
}

/**
  * @}
  */

/** @defgroup GPIO_LL_EF_Data_Access 数据访问
  * @{
  */

/**
  * @brief  返回指定端口的完整输入数据寄存器值。
  * @rmtoll IDR          IDy           LL_GPIO_ReadInputPort
  * @param  GPIOx GPIO端口
  * @retval 端口的输入数据寄存器值
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadInputPort(GPIO_TypeDef *GPIOx)
{
  /* 直接读取IDR寄存器，获取整个端口(16个引脚)的输入电平状态 */
  return (READ_REG(GPIOx->IDR));
}

/**
  * @brief  判断指定端口上多个引脚的输入数据电平是高还是低。
  * @rmtoll IDR          IDy           LL_GPIO_IsInputPinSet
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsInputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取IDR寄存器，判断指定引脚是否为高电平。如果所有指定引脚都为高，则返回1 */
  return (READ_BIT(GPIOx->IDR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU) == ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
}

/**
  * @brief  写入端口的输出数据寄存器。
  * @rmtoll ODR          ODy           LL_GPIO_WriteOutputPort
  * @param  GPIOx GPIO端口
  * @param  PortValue 端口每个引脚的电平值
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_WriteOutputPort(GPIO_TypeDef *GPIOx, uint32_t PortValue)
{
  /* 直接写入ODR寄存器，设置整个端口的输出电平 */
  WRITE_REG(GPIOx->ODR, PortValue);
}

/**
  * @brief  返回指定端口的完整输出数据寄存器值。
  * @rmtoll ODR          ODy           LL_GPIO_ReadOutputPort
  * @param  GPIOx GPIO端口
  * @retval 端口的输出数据寄存器值
  */
__STATIC_INLINE uint32_t LL_GPIO_ReadOutputPort(GPIO_TypeDef *GPIOx)
{
  /* 读取ODR寄存器，获取当前端口的输出配置 */
  return (uint32_t)(READ_REG(GPIOx->ODR));
}

/**
  * @brief  判断指定端口上多个引脚的输出数据电平是高还是低。
  * @rmtoll ODR          ODy           LL_GPIO_IsOutputPinSet
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_IsOutputPinSet(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取ODR寄存器，判断指定引脚当前的输出状态是否为高电平 */
  return (READ_BIT(GPIOx->ODR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU) == ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU));
}

/**
  * @brief  将指定GPIO端口上的多个引脚设置为高电平。
  * @rmtoll BSRR         BSy           LL_GPIO_SetOutputPin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_SetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 
     写入BSRR寄存器的低16位。
     BSRR寄存器是原子操作寄存器，写1置位，写0无影响。
     这里将对应的引脚设置为高电平。
  */
  WRITE_REG(GPIOx->BSRR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU);
}

/**
  * @brief  将指定GPIO端口上的多个引脚设置为低电平。
  * @rmtoll BRR          BRy           LL_GPIO_ResetOutputPin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_ResetOutputPin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 
     写入BRR寄存器。
     BRR寄存器用于复位引脚电平，写1清零(置低电平)，写0无影响。
  */
  WRITE_REG(GPIOx->BRR, (PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU);
}

/**
  * @brief  翻转指定端口上多个引脚的电平值。
  * @rmtoll ODR          ODy           LL_GPIO_TogglePin
  * @param  GPIOx GPIO端口
  * @param  PinMask 该参数可以是以下值的组合:
  *         @arg @ref LL_GPIO_PIN_0
  *         @arg @ref LL_GPIO_PIN_1
  *         @arg @ref LL_GPIO_PIN_2
  *         @arg @ref LL_GPIO_PIN_3
  *         @arg @ref LL_GPIO_PIN_4
  *         @arg @ref LL_GPIO_PIN_5
  *         @arg @ref LL_GPIO_PIN_6
  *         @arg @ref LL_GPIO_PIN_7
  *         @arg @ref LL_GPIO_PIN_8
  *         @arg @ref LL_GPIO_PIN_9
  *         @arg @ref LL_GPIO_PIN_10
  *         @arg @ref LL_GPIO_PIN_11
  *         @arg @ref LL_GPIO_PIN_12
  *         @arg @ref LL_GPIO_PIN_13
  *         @arg @ref LL_GPIO_PIN_14
  *         @arg @ref LL_GPIO_PIN_15
  *         @arg @ref LL_GPIO_PIN_ALL
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinMask)
{
  /* 读取当前ODR寄存器的值 */
  uint32_t odr = READ_REG(GPIOx->ODR);
  /* 计算有效的引脚掩码 */
  uint32_t pinmask = ((PinMask >> GPIO_PIN_MASK_POS) & 0x0000FFFFU);
  
  /* 
     利用BSRR寄存器实现原子翻转：
     - (odr & pinmask) << 16u: 获取当前为高电平的引脚，写入BSRR的高16位(复位)，使其变低。
     - (~odr & pinmask): 获取当前为低电平的引脚，写入BSRR的低16位(置位)，使其变高。
     这样可以在一条指令内完成多个引脚的电平翻转，避免读写修改过程中发生中断干扰。
  */
  WRITE_REG(GPIOx->BSRR, ((odr & pinmask) << 16u) | (~odr & pinmask));
}

/**
  * @}
  */

/** @defgroup GPIO_AF_REMAPPING 复用功能重映射
  * @brief 本节提供将复用功能重映射到其他端口/引脚的定义。
  * @{
  */

/**
  * @brief  启用SPI1复用功能NSS, SCK, MISO和MOSI的重映射。
  * @rmtoll MAPR          SPI1_REMAP           LL_GPIO_AF_EnableRemap_SPI1
  * @note   ENABLE: 重映射 (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SPI1(void)
{
  /* 设置AFIO_MAPR寄存器中的SPI1_REMAP位，开启重映射，同时保持SWJ_CFG配置 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SPI1_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用SPI1复用功能NSS, SCK, MISO和MOSI的重映射。
  * @rmtoll MAPR          SPI1_REMAP           LL_GPIO_AF_DisableRemap_SPI1
  * @note  DISABLE: 无重映射 (NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SPI1(void)
{
  /* 清除AFIO_MAPR寄存器中的SPI1_REMAP位，恢复默认引脚，同时保持SWJ_CFG配置 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_SPI1_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查SPI1是否已被重映射
  * @rmtoll MAPR         SPI1_REMAP         LL_GPIO_AF_IsEnabledRemap_SPI1
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_SPI1(void)
{
  /* 读取并检查SPI1_REMAP位是否置位 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_SPI1_REMAP) == (AFIO_MAPR_SPI1_REMAP));
}

/**
  * @brief 启用I2C1复用功能SCL和SDA的重映射。
  * @rmtoll MAPR          I2C1_REMAP           LL_GPIO_AF_EnableRemap_I2C1
  * @note  ENABLE: 重映射     (SCL/PB8, SDA/PB9)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_I2C1(void)
{
  /* 设置I2C1_REMAP位，将I2C1引脚映射到PB8/PB9 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_I2C1_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用I2C1复用功能SCL和SDA的重映射。
  * @rmtoll MAPR          I2C1_REMAP           LL_GPIO_AF_DisableRemap_I2C1
  * @note  DISABLE: 无重映射 (SCL/PB6, SDA/PB7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_I2C1(void)
{
  /* 清除I2C1_REMAP位，恢复默认引脚PB6/PB7 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_I2C1_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查I2C1是否已被重映射
  * @rmtoll MAPR         I2C1_REMAP         LL_GPIO_AF_IsEnabledRemap_I2C1
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_I2C1(void)
{
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_I2C1_REMAP) == (AFIO_MAPR_I2C1_REMAP));
}

/**
  * @brief 启用USART1复用功能TX和RX的重映射。
  * @rmtoll MAPR          USART1_REMAP           LL_GPIO_AF_EnableRemap_USART1
  * @note  ENABLE: 重映射     (TX/PB6, RX/PB7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART1(void)
{
  /* 设置USART1_REMAP位，将USART1引脚映射到PB6/PB7 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_USART1_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用USART1复用功能TX和RX的重映射。
  * @rmtoll MAPR          USART1_REMAP           LL_GPIO_AF_DisableRemap_USART1
  * @note  DISABLE: 无重映射 (TX/PA9, RX/PA10)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART1(void)
{
  /* 清除USART1_REMAP位，恢复默认引脚PA9/PA10 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART1_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief  检查USART1是否已被重映射
  * @rmtoll MAPR         USART1_REMAP         LL_GPIO_AF_IsEnabledRemap_USART1
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_USART1(void)
{
  // 读取AFIO_MAPR寄存器中的USART1_REMAP位，判断是否使能了重映射
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_USART1_REMAP) == (AFIO_MAPR_USART1_REMAP));
}

/**
  * @brief 使能USART2的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART2_REMAP           LL_GPIO_AF_EnableRemap_USART2
  * @note  使能: 重映射     (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART2(void)
{
  // 设置AFIO_MAPR寄存器中的USART2_REMAP位，将USART2引脚映射到PD端口
  // 同时保留SWJ_CFG配置（调试接口配置），防止修改调试引脚
  SET_BIT(AFIO->MAPR, AFIO_MAPR_USART2_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用USART2的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART2_REMAP           LL_GPIO_AF_DisableRemap_USART2
  * @note  禁用: 无重映射 (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART2(void)
{
  // 清除AFIO_MAPR寄存器中的USART2_REMAP位，恢复为默认引脚PA端口
  // 使用MODIFY_REG宏确保SWJ_CFG配置不受影响
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART2_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查USART2是否已被重映射
  * @rmtoll MAPR         USART2_REMAP         LL_GPIO_AF_IsEnabledRemap_USART2
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_USART2(void)
{
  // 读取AFIO_MAPR寄存器中的USART2_REMAP位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_USART2_REMAP) == (AFIO_MAPR_USART2_REMAP));
}

#if defined (AFIO_MAPR_USART3_REMAP)
/**
  * @brief 使能USART3的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_EnableRemap_USART3
  * @note  使能: 完全重映射     (TX/PD8,  RX/PD9,  CK/PD10, CTS/PD11, RTS/PD12)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_USART3(void)
{
  // 配置USART3为完全重映射模式，引脚映射到PD端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能USART3的复用功能部分重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_RemapPartial_USART3
  * @note  部分: 部分重映射 (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_USART3(void)
{
  // 配置USART3为部分重映射模式
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用USART3的复用功能重映射 (CTS, RTS, CK, TX 和 RX)。
  * @rmtoll MAPR          USART3_REMAP           LL_GPIO_AF_DisableRemap_USART3
  * @note  禁用: 无重映射      (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_USART3(void)
{
  // 配置USART3为无重映射模式，即默认引脚PB端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_USART3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_USART3_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}
#endif

/**
  * @brief 使能TIM1的复用功能重映射 (通道1到4, 1N到3N, 外部触发ETR和刹车输入BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_EnableRemap_TIM1
  * @note  使能: 完全重映射     (ETR/PE7,  CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8,  CH2N/PE10, CH3N/PE12)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM1(void)
{
  // 配置TIM1为完全重映射，引脚映射到PE端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM1的复用功能部分重映射 (通道1到4, 1N到3N, 外部触发ETR和刹车输入BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_RemapPartial_TIM1
  * @note  部分: 部分重映射 (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PA6,  CH1N/PA7,  CH2N/PB0,  CH3N/PB1)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_TIM1(void)
{
  // 配置TIM1为部分重映射
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用TIM1的复用功能重映射 (通道1到4, 1N到3N, 外部触发ETR和刹车输入BKIN)
  * @rmtoll MAPR          TIM1_REMAP           LL_GPIO_AF_DisableRemap_TIM1
  * @note  禁用: 无重映射      (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM1(void)
{
  // 配置TIM1为无重映射，恢复默认引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM1_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM1_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM2的复用功能重映射 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_EnableRemap_TIM2
  * @note  使能: 完全重映射       (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM2(void)
{
  // 配置TIM2为完全重映射
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM2的复用功能部分重映射2 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_RemapPartial2_TIM2
  * @note  部分_2: 部分重映射 (CH1/ETR/PA0,  CH2/PA1, CH3/PB10, CH4/PB11)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial2_TIM2(void)
{
  // 配置TIM2为部分重映射模式2
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM2的复用功能部分重映射1 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_RemapPartial1_TIM2
  * @note  部分_1: 部分重映射 (CH1/ETR/PA15, CH2/PB3, CH3/PA2,  CH4/PA3)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial1_TIM2(void)
{
  // 配置TIM2为部分重映射模式1
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用TIM2的复用功能重映射 (通道1到4 和 外部触发ETR)
  * @rmtoll MAPR          TIM2_REMAP           LL_GPIO_AF_DisableRemap_TIM2
  * @note  禁用: 无重映射        (CH1/ETR/PA0,  CH2/PA1, CH3/PA2,  CH4/PA3)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM2(void)
{
  // 配置TIM2为无重映射，恢复默认引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM2_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM3的复用功能重映射 (通道1到4)
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_EnableRemap_TIM3
  * @note  使能: 完全重映射     (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
  * @note  TIM3_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM3(void)
{
  // 配置TIM3为完全重映射，引脚映射到PC端口
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_FULLREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能TIM3的复用功能部分重映射 (通道1到4)
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_RemapPartial_TIM3
  * @note  部分: 部分重映射 (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial_TIM3(void)
{
  // 配置TIM3为部分重映射
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_PARTIALREMAP | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 禁用TIM3的复用功能重映射 (通道1到4)
  * @rmtoll MAPR          TIM3_REMAP           LL_GPIO_AF_DisableRemap_TIM3
  * @note  禁用: 无重映射      (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM3(void)
{
  // 配置TIM3为无重映射，恢复默认引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM3_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_TIM3_REMAP_NOREMAP | AFIO_MAPR_SWJ_CFG));
}

#if defined(AFIO_MAPR_TIM4_REMAP)
/**
  * @brief 使能TIM4的复用功能重映射 (通道1到4)。
  * @rmtoll MAPR          TIM4_REMAP           LL_GPIO_AF_EnableRemap_TIM4
  * @note  使能: 完全重映射 (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
  * @note  TIM4_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM4(void)
{
  // 设置TIM4重映射位，将TIM4引脚映射到PD端口
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM4_REMAP | AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief 禁用TIM4的复用功能重映射 (通道1到4)。
  * @rmtoll MAPR          TIM4_REMAP           LL_GPIO_AF_DisableRemap_TIM4
  * @note  禁用: 无重映射  (TIM4_CH1/PB6,  TIM4_CH2/PB7,  TIM4_CH3/PB8,  TIM4_CH4/PB9)
  * @note  TIM4_ETR on PE0 未被重映射。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM4(void)
{
  // 清除TIM4重映射位，恢复默认PB端口引脚
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM4_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查TIM4是否已被重映射
  * @rmtoll MAPR         TIM4_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM4
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM4(void)
{
  // 读取TIM4重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_TIM4_REMAP) == (AFIO_MAPR_TIM4_REMAP));
}
#endif

#if defined(AFIO_MAPR_CAN_REMAP_REMAP1)

/**
  * @brief 使能或禁用CAN复用功能 CAN_RX 和 CAN_TX 的重映射 (针对单CAN接口设备)。
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial1_CAN1
  * @note  情况 1: CAN_RX 映射到 PA11, CAN_TX 映射到 PA12
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial1_CAN1(void)
{
  // 配置CAN重映射为模式1 (PA11/PA12)
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP1 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能或禁用CAN复用功能 CAN_RX 和 CAN_TX 的重映射 (针对单CAN接口设备)。
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial2_CAN1
  * @note  情况 2: CAN_RX 映射到 PB8,  CAN_TX 映射到 PB9 (36引脚封装不可用)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial2_CAN1(void)
{
  // 配置CAN重映射为模式2 (PB8/PB9)
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP2 | AFIO_MAPR_SWJ_CFG));
}

/**
  * @brief 使能或禁用CAN复用功能 CAN_RX 和 CAN_TX 的重映射 (针对单CAN接口设备)。
  * @rmtoll MAPR          CAN_REMAP           LL_GPIO_AF_RemapPartial3_CAN1
  * @note  情况 3: CAN_RX 映射到 PD0,  CAN_TX 映射到 PD1
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_RemapPartial3_CAN1(void)
{
  // 配置CAN重映射为模式3 (PD0/PD1)
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN_REMAP | AFIO_MAPR_SWJ_CFG), (AFIO_MAPR_CAN_REMAP_REMAP3 | AFIO_MAPR_SWJ_CFG));
}
#endif

/**
  * @brief 使能PD0和PD1的重映射。当不使用HSE振荡器时
  *        (应用程序运行在内部8MHz RC时钟)，PD0和PD1可以映射到OSC_IN和
  *        OSC_OUT。这仅在36、48和64引脚封装上可用 (PD0和PD1在
  *        100引脚和144引脚封装上可用，无需重映射)。
  * @rmtoll MAPR          PD01_REMAP           LL_GPIO_AF_EnableRemap_PD01
  * @note  使能: PD0 重映射到 OSC_IN, PD1 重映射到 OSC_OUT。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_PD01(void)
{
  // 设置PD01重映射位，将PD0/PD1映射到晶振引脚，节省IO资源
  SET_BIT(AFIO->MAPR, AFIO_MAPR_PD01_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用PD0和PD1的重映射。当不使用HSE振荡器时
  *        (应用程序运行在内部8MHz RC时钟)，PD0和PD1可以映射到OSC_IN和
  *        OSC_OUT。这仅在36、48和64引脚封装上可用 (PD0和PD1在
  *        100引脚和144引脚封装上可用，无需重映射)。
  * @rmtoll MAPR          PD01_REMAP           LL_GPIO_AF_DisableRemap_PD01
  * @note  禁用: PD0和PD1无重映射
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_PD01(void)
{
  // 清除PD01重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_PD01_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查PD01是否已被重映射
  * @rmtoll MAPR         PD01_REMAP         LL_GPIO_AF_IsEnabledRemap_PD01
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_PD01(void)
{
  // 读取PD01重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_PD01_REMAP) == (AFIO_MAPR_PD01_REMAP));
}

#if defined(AFIO_MAPR_TIM5CH4_IREMAP)
/**
  * @brief 使能TIM5通道4的重映射。
  * @rmtoll MAPR          TIM5CH4_IREMAP           LL_GPIO_AF_EnableRemap_TIM5CH4
  * @note  使能: LSI内部时钟连接到TIM5_CH4输入，用于校准目的。
  * @note  此功能仅在高密度Value Line设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM5CH4(void)
{
  // 设置TIM5通道4内部重映射位，将LSI内部时钟连接到TIM5_CH4
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM5CH4_IREMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用TIM5通道4的重映射。
  * @rmtoll MAPR          TIM5CH4_IREMAP           LL_GPIO_AF_DisableRemap_TIM5CH4
  * @note  禁用: TIM5_CH4 连接到 PA3
  * @note  此功能仅在高密度Value Line设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM5CH4(void)
{
  // 清除TIM5通道4内部重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM5CH4_IREMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查TIM5CH4是否已被重映射
  * @rmtoll MAPR         TIM5CH4_IREMAP         LL_GPIO_AF_IsEnabledRemap_TIM5CH4
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM5CH4(void)
{
  // 读取TIM5通道4内部重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_TIM5CH4_IREMAP) == (AFIO_MAPR_TIM5CH4_IREMAP));
}
#endif

#if defined(AFIO_MAPR_ETH_REMAP)
/**
  * @brief 使能以太网MAC与PHY连接的重映射。
  * @rmtoll MAPR          ETH_REMAP           LL_GPIO_AF_EnableRemap_ETH
  * @note  使能: 重映射     (RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ETH(void)
{
  // 设置以太网重映射位，将以太网引脚映射到PD端口
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ETH_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用以太网MAC与PHY连接的重映射。
  * @rmtoll MAPR          ETH_REMAP           LL_GPIO_AF_DisableRemap_ETH
  * @note  禁用: 无重映射 (RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5,  RXD2/PB0,  RXD3/PB1)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ETH(void)
{
  // 清除以太网重映射位，恢复默认引脚配置
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ETH_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ETH是否已被重映射
  * @rmtoll MAPR         ETH_REMAP         LL_GPIO_AF_IsEnabledRemap_ETH
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ETH(void)
{
  // 读取以太网重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ETH_REMAP) == (AFIO_MAPR_ETH_REMAP));
}
#endif

#if defined(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief 使能CAN2复用功能 CAN2_RX 和 CAN2_TX 的重映射。
  * @rmtoll MAPR          CAN2_REMAP           LL_GPIO_AF_EnableRemap_CAN2
  * @note  使能: 重映射     (CAN2_RX/PB5,  CAN2_TX/PB6)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_CAN2(void)
{
  // 设置CAN2重映射位
  SET_BIT(AFIO->MAPR, AFIO_MAPR_CAN2_REMAP | AFIO_MAPR_SWJ_CFG);
}
/**
  * @brief 禁用CAN2复用功能 CAN2_RX 和 CAN2_TX 的重映射。
  * @rmtoll MAPR          CAN2_REMAP           LL_GPIO_AF_DisableRemap_CAN2
  * @note  禁用: 无重映射 (CAN2_RX/PB12, CAN2_TX/PB13)
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_CAN2(void)
{
  // 清除CAN2重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_CAN2_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查CAN2是否已被重映射
  * @rmtoll MAPR         CAN2_REMAP         LL_GPIO_AF_IsEnabledRemap_CAN2
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_CAN2(void)
{
  // 读取CAN2重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_CAN2_REMAP) == (AFIO_MAPR_CAN2_REMAP));
}
#endif

#if defined(AFIO_MAPR_MII_RMII_SEL)
/**
  * @brief 配置以太网MAC内部以用于外部MII或RMII PHY。
  * @rmtoll MAPR          MII_RMII_SEL           LL_GPIO_AF_Select_ETH_RMII
  * @note  ETH_RMII: 配置以太网MAC以连接RMII PHY
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Select_ETH_RMII(void)
{
  // 设置MII_RMII_SEL位，选择RMII模式
  SET_BIT(AFIO->MAPR, AFIO_MAPR_MII_RMII_SEL | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 配置以太网MAC内部以用于外部MII或RMII PHY。
  * @rmtoll MAPR          MII_RMII_SEL           LL_GPIO_AF_Select_ETH_MII
  * @note  ETH_MII: 配置以太网MAC以连接MII PHY
  * @note  此位仅在互联型设备中可用，在其他设备中保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Select_ETH_MII(void)
{
  // 清除MII_RMII_SEL位，选择MII模式
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_MII_RMII_SEL | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR_ADC1_ETRGINJ_REMAP)
/**
  * @brief 使能ADC1_ETRGINJ的重映射 (ADC 1 外部触发注入转换)。
  * @rmtoll MAPR          ADC1_ETRGINJ_REMAP           LL_GPIO_AF_EnableRemap_ADC1_ETRGINJ
  * @note  使能: ADC1 外部事件注入转换连接到 TIM8 通道4。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC1_ETRGINJ(void)
{
  // 设置ADC1外部触发注入转换重映射位
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用ADC1_ETRGINJ的重映射 (ADC 1 外部触发注入转换)。
  * @rmtoll MAPR          ADC1_ETRGINJ_REMAP           LL_GPIO_AF_DisableRemap_ADC1_ETRGINJ
  * @note  禁用: ADC1 外部触发注入转换连接到 EXTI15
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC1_ETRGINJ(void)
{
  // 清除ADC1外部触发注入转换重映射位
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC1_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC1_ETRGINJ是否已被重映射
  * @rmtoll MAPR         ADC1_ETRGINJ_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGINJ
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGINJ(void)
{
  // 读取ADC1外部触发注入转换重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGINJ_REMAP) == (AFIO_MAPR_ADC1_ETRGINJ_REMAP));
}
#endif

#if defined(AFIO_MAPR_ADC1_ETRGREG_REMAP)
/**
  * @brief 使能ADC1_ETRGREG的重映射 (ADC 1 外部触发常规转换)。
  * @rmtoll MAPR          ADC1_ETRGREG_REMAP           LL_GPIO_AF_EnableRemap_ADC1_ETRGREG
  * @note  使能: ADC1 外部事件常规转换连接到 TIM8 TRG0。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC1_ETRGREG(void)
{
  // 设置ADC1外部触发常规转换重映射位
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief 禁用ADC1_ETRGREG的重映射 (ADC 1 外部触发常规转换)。
  * @rmtoll MAPR          ADC1_ETRGREG_REMAP           LL_GPIO_AF_DisableRemap_ADC1_ETRGREG
  * @note  禁用: ADC1 外部触发常规转换连接到 EXTI11
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC1_ETRGREG(void)
{
   // 清除ADC1外部触发常规转换重映射位
   MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC1_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC1_ETRGREG是否已被重映射
  * @rmtoll MAPR         ADC1_ETRGREG_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGREG
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC1_ETRGREG(void)
{
  // 读取ADC1外部触发常规转换重映射位状态
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC1_ETRGREG_REMAP) == (AFIO_MAPR_ADC1_ETRGREG_REMAP));
}
#endif

#if defined(AFIO_MAPR_ADC2_ETRGINJ_REMAP)
/**
  * @brief  启用ADC2_ETRGREG的重映射（ADC2外部触发注入转换）。
  * @rmtoll MAPR          ADC2_ETRGINJ_REMAP           LL_GPIO_AF_EnableRemap_ADC2_ETRGINJ
  * @note  启用: ADC2外部事件注入转换连接到TIM8通道4。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC2_ETRGINJ(void)
{
  /* 设置AFIO_MAPR寄存器的ADC2_ETRGINJ_REMAP位，启用重映射，同时保持SWJ配置 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用ADC2_ETRGREG的重映射（ADC2外部触发注入转换）。
  * @rmtoll MAPR          ADC2_ETRGINJ_REMAP           LL_GPIO_AF_DisableRemap_ADC2_ETRGINJ
  * @note  禁用: ADC2外部触发注入转换连接到EXTI15
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC2_ETRGINJ(void)
{
  /* 清除ADC2_ETRGINJ_REMAP位以禁用重映射，保留SWJ配置 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC2_ETRGINJ_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC2_ETRGINJ是否已被重映射
  * @rmtoll MAPR         ADC2_ETRGINJ_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGINJ
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGINJ(void)
{
  /* 读取MAPR寄存器中的对应位，判断是否使能了重映射 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGINJ_REMAP) == (AFIO_MAPR_ADC2_ETRGINJ_REMAP));
}
#endif

#if defined (AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief  启用ADC2_ETRGREG的重映射（ADC2外部触发常规转换）。
  * @rmtoll MAPR          ADC2_ETRGREG_REMAP           LL_GPIO_AF_EnableRemap_ADC2_ETRGREG
  * @note  启用: ADC2外部事件常规转换连接到TIM8 TRG0。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ADC2_ETRGREG(void)
{
  /* 设置AFIO_MAPR寄存器的ADC2_ETRGREG_REMAP位，启用重映射 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用ADC2_ETRGREG的重映射（ADC2外部触发常规转换）。
  * @rmtoll MAPR          ADC2_ETRGREG_REMAP           LL_GPIO_AF_DisableRemap_ADC2_ETRGREG
  * @note  禁用: ADC2外部触发常规转换连接到EXTI11
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ADC2_ETRGREG(void)
{
  /* 清除ADC2_ETRGREG_REMAP位以禁用重映射 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_ADC2_ETRGREG_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查ADC2_ETRGREG是否已被重映射
  * @rmtoll MAPR         ADC2_ETRGREG_REMAP         LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGREG
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_ADC2_ETRGREG(void)
{
  /* 读取MAPR寄存器中的对应位，判断是否使能了重映射 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_ADC2_ETRGREG_REMAP) == (AFIO_MAPR_ADC2_ETRGREG_REMAP));
}
#endif

/**
  * @brief  启用串行线JTAG配置
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_EnableRemap_SWJ
  * @note  启用: 全SWJ (JTAG-DP + SW-DP): 复位状态
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SWJ(void)
{
  /* 配置SWJ_CFG为复位状态，即全SWJ使能（JTAG-DP + SW-DP） */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_RESET);
}

/**
  * @brief  启用串行线JTAG配置（无NJTRST）
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_Remap_SWJ_NONJTRST
  * @note  NONJTRST: 全SWJ (JTAG-DP + SW-DP) 但没有NJTRST
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_SWJ_NONJTRST(void)
{
  /* 配置SWJ_CFG为无NJTRST模式，释放JTRST引脚作为普通IO使用 */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_NOJNTRST);
}

/**
  * @brief  启用串行线JTAG配置（无JTAG）
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_Remap_SWJ_NOJTAG
  * @note  NOJTAG: JTAG-DP禁用且SW-DP启用
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_SWJ_NOJTAG(void)
{
  /* 配置SWJ_CFG为禁用JTAG模式，仅保留SW-DP，释放JTAG引脚作为普通IO */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_JTAGDISABLE);
}

/**
  * @brief  禁用串行线JTAG配置
  * @rmtoll MAPR          SWJ_CFG           LL_GPIO_AF_DisableRemap_SWJ
  * @note  禁用: JTAG-DP禁用且SW-DP禁用
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SWJ(void)
{
  /* 完全禁用JTAG和SWD接口，释放所有相关引脚作为普通IO */
  MODIFY_REG(AFIO->MAPR, AFIO_MAPR_SWJ_CFG, AFIO_MAPR_SWJ_CFG_DISABLE);
}

#if defined(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief  启用SPI3复用功能重映射 (SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD)。
  * @rmtoll MAPR          SPI3_REMAP           LL_GPIO_AF_EnableRemap_SPI3
  * @note  启用: 重映射     (SPI3_NSS-I2S3_WS/PA4,  SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12)
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_SPI3(void)
{
  /* 设置SPI3_REMAP位，将SPI3引脚映射到新的位置 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_SPI3_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用SPI3复用功能重映射 (SPI3_NSS/I2S3_WS, SPI3_SCK/I2S3_CK, SPI3_MISO, SPI3_MOSI/I2S3_SD)。
  * @rmtoll MAPR          SPI3_REMAP           LL_GPIO_AF_DisableRemap_SPI3
  * @note  禁用: 无重映射 (SPI3_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3,  SPI3_MISO/PB4,  SPI3_MOSI-I2S3_SD/PB5).
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_SPI3(void)
{
  /* 清除SPI3_REMAP位，恢复默认引脚位置 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_SPI3_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  检查SPI3是否已被重映射
  * @rmtoll MAPR         SPI3_REMAP         LL_GPIO_AF_IsEnabledRemap_SPI3_REMAP
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_SPI3(void)
{
  /* 读取SPI3重映射状态 */
  return (READ_BIT(AFIO->MAPR, AFIO_MAPR_SPI3_REMAP) == (AFIO_MAPR_SPI3_REMAP));
}
#endif

#if defined(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief  控制TIM2_ITR1内部映射。
  * @rmtoll MAPR          TIM2ITR1_IREMAP           LL_GPIO_AF_Remap_TIM2ITR1_TO_USB
  * @note  TO_USB: 将USB OTG SOF (帧开始) 输出连接到TIM2_ITR1用于校准目的。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_TIM2ITR1_TO_USB(void)
{
  /* 设置TIM2ITR1_IREMAP位，将TIM2内部触发输入1连接到USB SOF信号 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_TIM2ITR1_IREMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  控制TIM2_ITR1内部映射。
  * @rmtoll MAPR          TIM2ITR1_IREMAP           LL_GPIO_AF_Remap_TIM2ITR1_TO_ETH
  * @note  TO_ETH: 将TIM2_ITR1内部连接到以太网PTP输出用于校准目的。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Remap_TIM2ITR1_TO_ETH(void)
{
  /* 清除TIM2ITR1_IREMAP位，将TIM2内部触发输入1连接到以太网PTP信号 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_TIM2ITR1_IREMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief  启用ADC2_ETRGREG的重映射（ADC 2外部触发常规转换）。
  * @rmtoll MAPR          PTP_PPS_REMAP           LL_GPIO_AF_EnableRemap_ETH_PTP_PPS
  * @note  启用: PTP_PPS输出在PB5引脚。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_ETH_PTP_PPS(void)
{
  /* 设置PTP_PPS_REMAP位，将以太网PTP PPS信号映射到PB5引脚 */
  SET_BIT(AFIO->MAPR, AFIO_MAPR_PTP_PPS_REMAP | AFIO_MAPR_SWJ_CFG);
}

/**
  * @brief  禁用ADC2_ETRGREG的重映射（ADC 2外部触发常规转换）。
  * @rmtoll MAPR          PTP_PPS_REMAP           LL_GPIO_AF_DisableRemap_ETH_PTP_PPS
  * @note  禁用: PTP_PPS不在PB5引脚输出。
  * @note  此位仅在互联型设备中可用，其他情况下保留。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_ETH_PTP_PPS(void)
{
  /* 清除PTP_PPS_REMAP位，禁用PB5引脚的PPS输出功能 */
  MODIFY_REG(AFIO->MAPR, (AFIO_MAPR_PTP_PPS_REMAP | AFIO_MAPR_SWJ_CFG), AFIO_MAPR_SWJ_CFG);
}
#endif

#if defined(AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief  启用TIM9_CH1和TIM9_CH2的重映射。
  * @rmtoll MAPR2          TIM9_REMAP           LL_GPIO_AF_EnableRemap_TIM9
  * @note  启用: 重映射     (TIM9_CH1在PE5 且 TIM9_CH2在PE6)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM9(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM9_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP);
}

/**
  * @brief  禁用TIM9_CH1和TIM9_CH2的重映射。
  * @rmtoll MAPR2          TIM9_REMAP           LL_GPIO_AF_DisableRemap_TIM9
  * @note  禁用: 无重映射 (TIM9_CH1在PA2 且 TIM9_CH2在PA3)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM9(void)
{
  /* 清除TIM9_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP);
}

/**
  * @brief  检查TIM9_CH1和TIM9_CH2是否已被重映射
  * @rmtoll MAPR2         TIM9_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM9
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM9(void)
{
  /* 读取TIM9重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP) == (AFIO_MAPR2_TIM9_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief  启用TIM10_CH1的重映射。
  * @rmtoll MAPR2          TIM10_REMAP           LL_GPIO_AF_EnableRemap_TIM10
  * @note  启用: 重映射     (TIM10_CH1在PF6)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM10(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM10_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP);
}

/**
  * @brief  禁用TIM10_CH1的重映射。
  * @rmtoll MAPR2          TIM10_REMAP           LL_GPIO_AF_DisableRemap_TIM10
  * @note  禁用: 无重映射 (TIM10_CH1在PB8)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM10(void)
{
  /* 清除TIM10_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP);
}

/**
  * @brief  检查TIM10_CH1是否已被重映射
  * @rmtoll MAPR2         TIM10_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM10
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM10(void)
{
  /* 读取TIM10重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP) == (AFIO_MAPR2_TIM10_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM11_REMAP)
/**
  * @brief  启用TIM11_CH1的重映射。
  * @rmtoll MAPR2          TIM11_REMAP           LL_GPIO_AF_EnableRemap_TIM11
  * @note  启用: 重映射     (TIM11_CH1在PF7)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM11(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM11_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP);
}

/**
  * @brief  禁用TIM11_CH1的重映射。
  * @rmtoll MAPR2          TIM11_REMAP           LL_GPIO_AF_DisableRemap_TIM11
  * @note  禁用: 无重映射 (TIM11_CH1在PB9)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM11(void)
{
  /* 清除TIM11_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP);
}

/**
  * @brief  检查TIM11_CH1是否已被重映射
  * @rmtoll MAPR2         TIM11_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM11
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM11(void)
{
  /* 读取TIM11重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP) == (AFIO_MAPR2_TIM11_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief  启用TIM13_CH1的重映射。
  * @rmtoll MAPR2          TIM13_REMAP           LL_GPIO_AF_EnableRemap_TIM13
  * @note  启用: 重映射     STM32F100:(TIM13_CH1在PF8). 其他:(TIM13_CH1在PB0).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM13(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM13_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP);
}

/**
  * @brief  禁用TIM13_CH1的重映射。
  * @rmtoll MAPR2          TIM13_REMAP           LL_GPIO_AF_DisableRemap_TIM13
  * @note  禁用: 无重映射 STM32F100:(TIM13_CH1在PA6). 其他:(TIM13_CH1在PC8).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM13(void)
{
  /* 清除TIM13_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP);
}

/**
  * @brief  检查TIM13_CH1是否已被重映射
  * @rmtoll MAPR2         TIM13_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM13
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM13(void)
{
  /* 读取TIM13重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP) == (AFIO_MAPR2_TIM13_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief  启用TIM14_CH1的重映射。
  * @rmtoll MAPR2          TIM14_REMAP           LL_GPIO_AF_EnableRemap_TIM14
  * @note  启用: 重映射     STM32F100:(TIM14_CH1在PB1). 其他:(TIM14_CH1在PF9).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM14(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM14_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP);
}

/**
  * @brief  禁用TIM14_CH1的重映射。
  * @rmtoll MAPR2          TIM14_REMAP           LL_GPIO_AF_DisableRemap_TIM14
  * @note  禁用: 无重映射 STM32F100:(TIM14_CH1在PC9). 其他:(TIM14_CH1在PA7).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM14(void)
{
  /* 清除TIM14_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP);
}

/**
  * @brief  检查TIM14_CH1是否已被重映射
  * @rmtoll MAPR2         TIM14_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM14
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM14(void)
{
  /* 读取TIM14重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP) == (AFIO_MAPR2_TIM14_REMAP));
}
#endif

#if defined(AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief  控制可选FSMC_NADV信号的使用。
  * @rmtoll MAPR2          FSMC_NADV           LL_GPIO_AF_Disconnect_FSMCNADV
  * @note  断开: NADV信号未连接。I/O引脚可被其他外设使用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Disconnect_FSMCNADV(void)
{
  /* 设置FSMC_NADV_REMAP位，断开NADV引脚，释放该引脚供其他功能使用 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}

/**
  * @brief  控制可选FSMC_NADV信号的使用。
  * @rmtoll MAPR2          FSMC_NADV           LL_GPIO_AF_Connect_FSMCNADV
  * @note  连接: NADV信号连接到输出 (默认)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_Connect_FSMCNADV(void)
{
  /* 清除FSMC_NADV_REMAP位，连接NADV引脚，用于FSMC操作 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP);
}
#endif

#if defined(AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief  启用TIM15_CH1和TIM15_CH2的重映射。
  * @rmtoll MAPR2          TIM15_REMAP           LL_GPIO_AF_EnableRemap_TIM15
  * @note  启用: 重映射     (TIM15_CH1在PB14 且 TIM15_CH2在PB15)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM15(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM15_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP);
}
/**
  * @brief  禁用TIM15_CH1和TIM15_CH2的重映射。
  * @rmtoll MAPR2          TIM15_REMAP           LL_GPIO_AF_DisableRemap_TIM15
  * @note  禁用: 无重映射 (TIM15_CH1在PA2  且 TIM15_CH2在PA3)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM15(void)
{
  /* 清除TIM15_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP);
}

/**
  * @brief  检查TIM15_CH1是否已被重映射
  * @rmtoll MAPR2         TIM15_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM15
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM15(void)
{
  /* 读取TIM15重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP) == (AFIO_MAPR2_TIM15_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief  启用TIM16_CH1的重映射。
  * @rmtoll MAPR2          TIM16_REMAP           LL_GPIO_AF_EnableRemap_TIM16
  * @note  启用: 重映射     (TIM16_CH1在PA6)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM16(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM16_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP);
}

/**
  * @brief  禁用TIM16_CH1的重映射。
  * @rmtoll MAPR2          TIM16_REMAP           LL_GPIO_AF_DisableRemap_TIM16
  * @note  禁用: 无重映射 (TIM16_CH1在PB8)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM16(void)
{
  /* 清除TIM16_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP);
}

/**
  * @brief  检查TIM16_CH1是否已被重映射
  * @rmtoll MAPR2         TIM16_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM16
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM16(void)
{
  /* 读取TIM16重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP) == (AFIO_MAPR2_TIM16_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief  启用TIM17_CH1的重映射。
  * @rmtoll MAPR2          TIM17_REMAP           LL_GPIO_AF_EnableRemap_TIM17
  * @note  启用: 重映射     (TIM17_CH1在PA7)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM17(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM17_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP);
}

/**
  * @brief  禁用TIM17_CH1的重映射。
  * @rmtoll MAPR2          TIM17_REMAP           LL_GPIO_AF_DisableRemap_TIM17
  * @note  禁用: 无重映射 (TIM17_CH1在PB9)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM17(void)
{
  /* 清除TIM17_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP);
}

/**
  * @brief  检查TIM17_CH1是否已被重映射
  * @rmtoll MAPR2         TIM17_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM17
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM17(void)
{
  /* 读取TIM17重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP) == (AFIO_MAPR2_TIM17_REMAP));
}
#endif

#if defined(AFIO_MAPR2_CEC_REMAP)

/**
  * @brief  启用CEC的重映射。
  * @rmtoll MAPR2          CEC_REMAP           LL_GPIO_AF_EnableRemap_CEC
  * @note  启用: 重映射     (CEC在PB10)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_CEC(void)
{
  /* 设置AFIO_MAPR2寄存器的CEC_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP);
}

/**
  * @brief  禁用CEC的重映射。
  * @rmtoll MAPR2          CEC_REMAP           LL_GPIO_AF_DisableRemap_CEC
  * @note  禁用: 无重映射 (CEC在PB8)。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_CEC(void)
{
  /* 清除CEC_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP);
}

/**
  * @brief  检查CEC是否已被重映射
  * @rmtoll MAPR2         CEC_REMAP         LL_GPIO_AF_IsEnabledRemap_CEC
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_CEC(void)
{
  /* 读取CEC重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP) == (AFIO_MAPR2_CEC_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief  控制TIM1_CH1 TIM1_CH2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM1_DMA_REMAP           LL_GPIO_AF_EnableRemap_TIM1DMA
  * @note  启用: 重映射 (TIM1_CH1 DMA请求/DMA1通道6, TIM1_CH2 DMA请求/DMA1通道6)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM1DMA(void)
{
  /* 设置TIM1_DMA_REMAP位，改变TIM1 DMA请求的通道映射 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP);
}

/**
  * @brief  控制TIM1_CH1 TIM1_CH2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM1_DMA_REMAP           LL_GPIO_AF_DisableRemap_TIM1DMA
  * @note  禁用: 无重映射 (TIM1_CH1 DMA请求/DMA1通道2, TIM1_CH2 DMA请求/DMA1通道3).
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM1DMA(void)
{
  /* 清除TIM1_DMA_REMAP位，恢复默认DMA通道映射 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP);
}

/**
  * @brief  检查TIM1DMA是否已被重映射
  * @rmtoll MAPR2         TIM1_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM1DMA
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM1DMA(void)
{
  /* 读取TIM1 DMA重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP) == (AFIO_MAPR2_TIM1_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM76_DAC_DMA_REMAP           LL_GPIO_AF_EnableRemap_TIM67DACDMA
  * @note  启用: 重映射 (TIM6_DAC1 DMA请求/DMA1通道3, TIM7_DAC2 DMA请求/DMA1通道4)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM67DACDMA(void)
{
  /* 设置TIM67_DAC_DMA_REMAP位，改变TIM6/7 DAC DMA请求的通道映射 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP);
}

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道。
  * @rmtoll MAPR2          TIM76_DAC_DMA_REMAP           LL_GPIO_AF_DisableRemap_TIM67DACDMA
  * @note  禁用: 无重映射 (TIM6_DAC1 DMA请求/DMA2通道3, TIM7_DAC2 DMA请求/DMA2通道4)
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM67DACDMA(void)
{
  /* 清除TIM67_DAC_DMA_REMAP位，恢复默认DMA通道映射 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP);
}

/**
  * @brief  检查TIM67DACDMA是否已被重映射
  * @rmtoll MAPR2         TIM76_DAC_DMA_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM67DACDMA(void)
{
  /* 读取TIM6/7 DAC DMA重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP) == (AFIO_MAPR2_TIM67_DAC_DMA_REMAP));
}
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief  启用TIM12_CH1和TIM12_CH2的重映射。
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_EnableRemap_TIM12
  * @note  启用: 重映射     (TIM12_CH1在PB12 且 TIM12_CH2在PB13)。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_TIM12(void)
{
  /* 设置AFIO_MAPR2寄存器的TIM12_REMAP位 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief  禁用TIM12_CH1和TIM12_CH2的重映射。
  * @rmtoll MAPR2          TIM12_REMAP           LL_GPIO_AF_DisableRemap_TIM12
  * @note  禁用: 无重映射 (TIM12_CH1在PC4  且 TIM12_CH2在PC5)。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_TIM12(void)
{
  /* 清除TIM12_REMAP位 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP);
}

/**
  * @brief  检查TIM12_CH1是否已被重映射
  * @rmtoll MAPR2         TIM12_REMAP         LL_GPIO_AF_IsEnabledRemap_TIM12
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_TIM12(void)
{
  /* 读取TIM12重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP) == (AFIO_MAPR2_TIM12_REMAP));
}
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief  杂项功能重映射。
  *         此位由软件置位和清除。它控制杂项功能。
  *         DMA2通道5中断在向量表中的位置。
  *         DAC触发3的定时器选择 (TSEL[2:0] = 011, 更多细节请参考DAC_CR寄存器)。
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_EnableRemap_MISC
  * @note  启用: DMA2通道5中断单独映射到位置60，TIM15 TRGO事件被选为DAC触发3，TIM15触发TIM1/3。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableRemap_MISC(void)
{
  /* 设置MISC_REMAP位以启用杂项重映射功能 */
  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief  杂项功能重映射。
  *         此位由软件置位和清除。它控制杂项功能。
  *         DMA2通道5中断在向量表中的位置。
  *         DAC触发3的定时器选择 (TSEL[2:0] = 011, 更多细节请参考DAC_CR寄存器)。
  * @rmtoll MAPR2          MISC_REMAP           LL_GPIO_AF_DisableRemap_MISC
  * @note  禁用: DMA2通道5中断与DMA2通道4一起映射到位置59，TIM5 TRGO事件被选为DAC触发3，TIM5触发TIM1/3。
  * @note  此位仅在高密度值线设备中可用。
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableRemap_MISC(void)
{
  /* 清除MISC_REMAP位以禁用杂项重映射功能 */
  CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP);
}

/**
  * @brief  检查MISC是否已被重映射
  * @rmtoll MAPR2         MISC_REMAP         LL_GPIO_AF_IsEnabledRemap_MISC
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_IsEnabledRemap_MISC(void)
{
  /* 读取MISC重映射状态 */
  return (READ_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP) == (AFIO_MAPR2_MISC_REMAP));
}
#endif

/**
  * @}
  */

/** @defgroup GPIO_AF_LL_EVENTOUT 输出事件配置
  * @brief 本节提供定义以配置EVENTOUT Cortex特性。
  * @{
  */

/**
  * @brief  配置EVENTOUT Cortex信号连接的端口和引脚。
  * @rmtoll EVCR          PORT           LL_GPIO_AF_ConfigEventout\n
  *         EVCR          PIN            LL_GPIO_AF_ConfigEventout
  * @param  LL_GPIO_PortSource 此参数可以是以下值之一:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_A
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_B
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_C
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_D
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PORT_E
  * @param  LL_GPIO_PinSource 此参数可以是以下值之一:
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_0
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_1
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_2
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_3
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_4
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_5
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_6
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_7
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_8
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_9
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_10
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_11
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_12
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_13
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_14
  *      @arg @ref LL_GPIO_AF_EVENTOUT_PIN_15
  * @retval 无
*/
__STATIC_INLINE void LL_GPIO_AF_ConfigEventout(uint32_t LL_GPIO_PortSource, uint32_t LL_GPIO_PinSource)
{
  /* 配置EVCR寄存器，设置事件输出对应的GPIO端口和引脚号 */
  MODIFY_REG(AFIO->EVCR, (AFIO_EVCR_PORT) | (AFIO_EVCR_PIN), (LL_GPIO_PortSource) | (LL_GPIO_PinSource));
}

/**
  * @brief  启用事件输出。
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_EnableEventout
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_EnableEventout(void)
{
  /* 设置EVOE位，使能Cortex内核的事件输出功能到指定引脚 */
  SET_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @brief  禁用事件输出。
  * @rmtoll EVCR          EVOE           LL_GPIO_AF_DisableEventout
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_DisableEventout(void)
{
  /* 清除EVOE位，禁用事件输出功能 */
  CLEAR_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @}
  */
/** @defgroup GPIO_AF_LL_EXTI EXTI外部中断
  * @brief 本节配置EXTI外部中断的源输入。
  * @{
  */

/**
  * @brief  配置EXTI外部中断的源输入。
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_SetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_SetEXTISource
  * @param  Port 此参数可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  * @param  Line 此参数可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_LINE0
  *         @arg @ref LL_GPIO_AF_EXTI_LINE1
  *         @arg @ref LL_GPIO_AF_EXTI_LINE2
  *         @arg @ref LL_GPIO_AF_EXTI_LINE3
  *         @arg @ref LL_GPIO_AF_EXTI_LINE4
  *         @arg @ref LL_GPIO_AF_EXTI_LINE5
  *         @arg @ref LL_GPIO_AF_EXTI_LINE6
  *         @arg @ref LL_GPIO_AF_EXTI_LINE7
  *         @arg @ref LL_GPIO_AF_EXTI_LINE8
  *         @arg @ref LL_GPIO_AF_EXTI_LINE9
  *         @arg @ref LL_GPIO_AF_EXTI_LINE10
  *         @arg @ref LL_GPIO_AF_EXTI_LINE11
  *         @arg @ref LL_GPIO_AF_EXTI_LINE12
  *         @arg @ref LL_GPIO_AF_EXTI_LINE13
  *         @arg @ref LL_GPIO_AF_EXTI_LINE14
  *         @arg @ref LL_GPIO_AF_EXTI_LINE15
  * @retval 无
  */
__STATIC_INLINE void LL_GPIO_AF_SetEXTISource(uint32_t Port, uint32_t Line)
{
  /* 
     配置EXTI外部中断线源。
     Line参数的低8位用于索引EXTICR数组(0-3对应EXTICR1-4)。
     Line参数的高16位包含具体的配置位掩码。
     Port参数左移相应位置后写入寄存器。
  */
  MODIFY_REG(AFIO->EXTICR[Line & 0xFF], (Line >> 16), Port << POSITION_VAL((Line >> 16)));
}

/**
  * @brief  获取特定EXTI线的配置源
  * @rmtoll AFIO_EXTICR1      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR2      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR3      EXTIx         LL_GPIO_AF_GetEXTISource\n
  *         AFIO_EXTICR4      EXTIx         LL_GPIO_AF_GetEXTISource
  * @param  Line 此参数可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_LINE0
  *         @arg @ref LL_GPIO_AF_EXTI_LINE1
  *         @arg @ref LL_GPIO_AF_EXTI_LINE2
  *         @arg @ref LL_GPIO_AF_EXTI_LINE3
  *         @arg @ref LL_GPIO_AF_EXTI_LINE4
  *         @arg @ref LL_GPIO_AF_EXTI_LINE5
  *         @arg @ref LL_GPIO_AF_EXTI_LINE6
  *         @arg @ref LL_GPIO_AF_EXTI_LINE7
  *         @arg @ref LL_GPIO_AF_EXTI_LINE8
  *         @arg @ref LL_GPIO_AF_EXTI_LINE9
  *         @arg @ref LL_GPIO_AF_EXTI_LINE10
  *         @arg @ref LL_GPIO_AF_EXTI_LINE11
  *         @arg @ref LL_GPIO_AF_EXTI_LINE12
  *         @arg @ref LL_GPIO_AF_EXTI_LINE13
  *         @arg @ref LL_GPIO_AF_EXTI_LINE14
  *         @arg @ref LL_GPIO_AF_EXTI_LINE15
  * @retval 返回值可以是以下值之一:
  *         @arg @ref LL_GPIO_AF_EXTI_PORTA
  *         @arg @ref LL_GPIO_AF_EXTI_PORTB
  *         @arg @ref LL_GPIO_AF_EXTI_PORTC
  *         @arg @ref LL_GPIO_AF_EXTI_PORTD
  *         @arg @ref LL_GPIO_AF_EXTI_PORTE
  *         @arg @ref LL_GPIO_AF_EXTI_PORTF
  *         @arg @ref LL_GPIO_AF_EXTI_PORTG
  */
__STATIC_INLINE uint32_t LL_GPIO_AF_GetEXTISource(uint32_t Line)
{
  /* 
     读取EXTI外部中断线源配置。
     读取对应寄存器位，并右移对齐，返回端口号。
  */
  return (uint32_t)(READ_BIT(AFIO->EXTICR[Line & 0xFF], (Line >> 16)) >> POSITION_VAL(Line >> 16));
}

/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_EF_Init 初始化和反初始化函数
  * @{
  */

ErrorStatus LL_GPIO_DeInit(GPIO_TypeDef *GPIOx); // GPIO外设反初始化（复位）函数声明
ErrorStatus LL_GPIO_Init(GPIO_TypeDef *GPIOx, LL_GPIO_InitTypeDef *GPIO_InitStruct); // GPIO初始化函数声明，根据配置结构体初始化GPIO
void        LL_GPIO_StructInit(LL_GPIO_InitTypeDef *GPIO_InitStruct); // 初始化GPIO配置结构体为默认值

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF) || defined (GPIOG) */
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F1xx_LL_GPIO_H */
