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
