/**
  ******************************************************************************
  * @file    stm32f1xx_ll_gpio.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO LL module.
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
#ifndef STM32F1xx_LL_GPIO_H
#define STM32F1xx_LL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined (GPIOA) || defined (GPIOB) || defined (GPIOC) || defined (GPIOD) || defined (GPIOE) || defined (GPIOF) || defined (GPIOG)

/** @defgroup GPIO_LL GPIO
  * @{
  */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/

/** @defgroup GPIO_LL_Private_Constants GPIO Private Constants
  * @{
  */
/* Defines used for Pin Mask Initialization */
#define GPIO_PIN_MASK_POS   8U
#define GPIO_PIN_NB         16U
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_Private_Macros GPIO Private Macros
  * @{
  */

/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup GPIO_LL_ES_INIT GPIO Exported Init structures
  * @{
  */

/**
  * @brief LL GPIO Init Structure definition
  */
typedef struct
{
  uint32_t Pin;          /*!< Specifies the GPIO pins to be configured.
                              This parameter can be any value of @ref GPIO_LL_EC_PIN */

  uint32_t Mode;         /*!< Specifies the operating mode for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_MODE.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinMode().*/

  uint32_t Speed;        /*!< Specifies the speed for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_SPEED.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinSpeed().*/

  uint32_t OutputType;   /*!< Specifies the operating output type for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_OUTPUT.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinOutputType().*/

  uint32_t Pull;         /*!< Specifies the operating Pull-up/Pull down for the selected pins.
                              This parameter can be a value of @ref GPIO_LL_EC_PULL.

                              GPIO HW configuration can be modified afterwards using unitary function @ref LL_GPIO_SetPinPull().*/
} LL_GPIO_InitTypeDef;

/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Constants GPIO Exported Constants
  * @{
  */

/** @defgroup GPIO_LL_EC_PIN PIN
  * @{
  */
#define LL_GPIO_PIN_0                    ((GPIO_BSRR_BS0  << GPIO_PIN_MASK_POS) | 0x00000001U)  /*!< Select pin 0  */
#define LL_GPIO_PIN_1                    ((GPIO_BSRR_BS1  << GPIO_PIN_MASK_POS) | 0x00000002U)  /*!< Select pin 1  */
#define LL_GPIO_PIN_2                    ((GPIO_BSRR_BS2  << GPIO_PIN_MASK_POS) | 0x00000004U)  /*!< Select pin 2  */
#define LL_GPIO_PIN_3                    ((GPIO_BSRR_BS3  << GPIO_PIN_MASK_POS) | 0x00000008U)  /*!< Select pin 3  */
#define LL_GPIO_PIN_4                    ((GPIO_BSRR_BS4  << GPIO_PIN_MASK_POS) | 0x00000010U)  /*!< Select pin 4  */
#define LL_GPIO_PIN_5                    ((GPIO_BSRR_BS5  << GPIO_PIN_MASK_POS) | 0x00000020U)  /*!< Select pin 5  */
#define LL_GPIO_PIN_6                    ((GPIO_BSRR_BS6  << GPIO_PIN_MASK_POS) | 0x00000040U)  /*!< Select pin 6  */
#define LL_GPIO_PIN_7                    ((GPIO_BSRR_BS7  << GPIO_PIN_MASK_POS) | 0x00000080U)  /*!< Select pin 7  */
#define LL_GPIO_PIN_8                    ((GPIO_BSRR_BS8  << GPIO_PIN_MASK_POS) | 0x04000001U)  /*!< Select pin 8  */
#define LL_GPIO_PIN_9                    ((GPIO_BSRR_BS9  << GPIO_PIN_MASK_POS) | 0x04000002U)  /*!< Select pin 9  */
#define LL_GPIO_PIN_10                   ((GPIO_BSRR_BS10 << GPIO_PIN_MASK_POS) | 0x04000004U)  /*!< Select pin 10 */
#define LL_GPIO_PIN_11                   ((GPIO_BSRR_BS11 << GPIO_PIN_MASK_POS) | 0x04000008U)  /*!< Select pin 11 */
#define LL_GPIO_PIN_12                   ((GPIO_BSRR_BS12 << GPIO_PIN_MASK_POS) | 0x04000010U)  /*!< Select pin 12 */
#define LL_GPIO_PIN_13                   ((GPIO_BSRR_BS13 << GPIO_PIN_MASK_POS) | 0x04000020U)  /*!< Select pin 13 */
#define LL_GPIO_PIN_14                   ((GPIO_BSRR_BS14 << GPIO_PIN_MASK_POS) | 0x04000040U)  /*!< Select pin 14 */
#define LL_GPIO_PIN_15                   ((GPIO_BSRR_BS15 << GPIO_PIN_MASK_POS) | 0x04000080U)  /*!< Select pin 15 */
#define LL_GPIO_PIN_ALL                  (LL_GPIO_PIN_0  | LL_GPIO_PIN_1  | LL_GPIO_PIN_2  | \
                                          LL_GPIO_PIN_3  | LL_GPIO_PIN_4  | LL_GPIO_PIN_5  | \
                                          LL_GPIO_PIN_6  | LL_GPIO_PIN_7  | LL_GPIO_PIN_8  | \
                                          LL_GPIO_PIN_9  | LL_GPIO_PIN_10 | LL_GPIO_PIN_11 | \
                                          LL_GPIO_PIN_12 | LL_GPIO_PIN_13 | LL_GPIO_PIN_14 | \
                                          LL_GPIO_PIN_15)                                      /*!< Select all pins */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_MODE Mode
  * @{
  */
#define LL_GPIO_MODE_ANALOG              0x00000000U       /*!< Select analog mode */
#define LL_GPIO_MODE_FLOATING            GPIO_CRL_CNF0_0   /*!< Select floating mode */
#define LL_GPIO_MODE_INPUT               GPIO_CRL_CNF0_1   /*!< Select input mode */
#define LL_GPIO_MODE_OUTPUT              GPIO_CRL_MODE0_0  /*!< Select general purpose output mode */
#define LL_GPIO_MODE_ALTERNATE           (GPIO_CRL_CNF0_1 | GPIO_CRL_MODE0_0) /*!< Select alternate function mode */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_OUTPUT Output Type
  * @{
  */
#define LL_GPIO_OUTPUT_PUSHPULL          0x00000000U                /*!< Select push-pull as output type */
#define LL_GPIO_OUTPUT_OPENDRAIN         GPIO_CRL_CNF0_0            /*!< Select open-drain as output type */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_SPEED Output Speed
  * @{
  */
#define LL_GPIO_MODE_OUTPUT_10MHz        GPIO_CRL_MODE0_0            /*!< Select Output mode, max speed 10 MHz */
#define LL_GPIO_MODE_OUTPUT_2MHz         GPIO_CRL_MODE0_1            /*!< Select Output mode, max speed 20 MHz */
#define LL_GPIO_MODE_OUTPUT_50MHz        GPIO_CRL_MODE0              /*!< Select Output mode, max speed 50 MHz */
/**
  * @}
  */

#define LL_GPIO_SPEED_FREQ_LOW           LL_GPIO_MODE_OUTPUT_2MHz    /*!< Select I/O low output speed    */
#define LL_GPIO_SPEED_FREQ_MEDIUM        LL_GPIO_MODE_OUTPUT_10MHz   /*!< Select I/O medium output speed */
#define LL_GPIO_SPEED_FREQ_HIGH          LL_GPIO_MODE_OUTPUT_50MHz   /*!< Select I/O high output speed   */

/** @defgroup GPIO_LL_EC_PULL Pull Up Pull Down
  * @{
  */
#define LL_GPIO_PULL_DOWN                0x00000000U    /*!< Select I/O pull down */
#define LL_GPIO_PULL_UP                  GPIO_ODR_ODR0  /*!< Select I/O pull up */

/**
  * @}
  */

/** @defgroup GPIO_LL_EVENTOUT_PIN EVENTOUT Pin
  * @{
  */

#define LL_GPIO_AF_EVENTOUT_PIN_0        AFIO_EVCR_PIN_PX0   /*!< EVENTOUT on pin 0 */
#define LL_GPIO_AF_EVENTOUT_PIN_1        AFIO_EVCR_PIN_PX1   /*!< EVENTOUT on pin 1 */
#define LL_GPIO_AF_EVENTOUT_PIN_2        AFIO_EVCR_PIN_PX2   /*!< EVENTOUT on pin 2 */
#define LL_GPIO_AF_EVENTOUT_PIN_3        AFIO_EVCR_PIN_PX3   /*!< EVENTOUT on pin 3 */
#define LL_GPIO_AF_EVENTOUT_PIN_4        AFIO_EVCR_PIN_PX4   /*!< EVENTOUT on pin 4 */
#define LL_GPIO_AF_EVENTOUT_PIN_5        AFIO_EVCR_PIN_PX5   /*!< EVENTOUT on pin 5 */
#define LL_GPIO_AF_EVENTOUT_PIN_6        AFIO_EVCR_PIN_PX6   /*!< EVENTOUT on pin 6 */
#define LL_GPIO_AF_EVENTOUT_PIN_7        AFIO_EVCR_PIN_PX7   /*!< EVENTOUT on pin 7 */
#define LL_GPIO_AF_EVENTOUT_PIN_8        AFIO_EVCR_PIN_PX8   /*!< EVENTOUT on pin 8 */
#define LL_GPIO_AF_EVENTOUT_PIN_9        AFIO_EVCR_PIN_PX9   /*!< EVENTOUT on pin 9 */
#define LL_GPIO_AF_EVENTOUT_PIN_10       AFIO_EVCR_PIN_PX10  /*!< EVENTOUT on pin 10 */
#define LL_GPIO_AF_EVENTOUT_PIN_11       AFIO_EVCR_PIN_PX11  /*!< EVENTOUT on pin 11 */
#define LL_GPIO_AF_EVENTOUT_PIN_12       AFIO_EVCR_PIN_PX12  /*!< EVENTOUT on pin 12 */
#define LL_GPIO_AF_EVENTOUT_PIN_13       AFIO_EVCR_PIN_PX13  /*!< EVENTOUT on pin 13 */
#define LL_GPIO_AF_EVENTOUT_PIN_14       AFIO_EVCR_PIN_PX14  /*!< EVENTOUT on pin 14 */
#define LL_GPIO_AF_EVENTOUT_PIN_15       AFIO_EVCR_PIN_PX15  /*!< EVENTOUT on pin 15 */

/**
  * @}
  */

/** @defgroup GPIO_LL_EVENTOUT_PORT EVENTOUT Port
  * @{
  */

#define LL_GPIO_AF_EVENTOUT_PORT_A       AFIO_EVCR_PORT_PA  /*!< EVENTOUT on port A */
#define LL_GPIO_AF_EVENTOUT_PORT_B       AFIO_EVCR_PORT_PB  /*!< EVENTOUT on port B */
#define LL_GPIO_AF_EVENTOUT_PORT_C       AFIO_EVCR_PORT_PC  /*!< EVENTOUT on port C */
#define LL_GPIO_AF_EVENTOUT_PORT_D       AFIO_EVCR_PORT_PD  /*!< EVENTOUT on port D */
#define LL_GPIO_AF_EVENTOUT_PORT_E       AFIO_EVCR_PORT_PE  /*!< EVENTOUT on port E */

/**
  * @}
  */

/** @defgroup GPIO_LL_EC_EXTI_PORT GPIO EXTI PORT
  * @{
  */
#define LL_GPIO_AF_EXTI_PORTA            0U   /*!< EXTI PORT A */
#define LL_GPIO_AF_EXTI_PORTB            1U   /*!< EXTI PORT B */
#define LL_GPIO_AF_EXTI_PORTC            2U   /*!< EXTI PORT C */
#define LL_GPIO_AF_EXTI_PORTD            3U   /*!< EXTI PORT D */
#define LL_GPIO_AF_EXTI_PORTE            4U   /*!< EXTI PORT E */
#define LL_GPIO_AF_EXTI_PORTF            5U   /*!< EXTI PORT F */
#define LL_GPIO_AF_EXTI_PORTG            6U   /*!< EXTI PORT G */
/**
  * @}
  */

/** @defgroup GPIO_LL_EC_EXTI_LINE GPIO EXTI LINE
  * @{
  */
#define LL_GPIO_AF_EXTI_LINE0            (0x000FU << 16U | 0U)  /*!< EXTI_POSITION_0  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE1            (0x00F0U << 16U | 0U)  /*!< EXTI_POSITION_4  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE2            (0x0F00U << 16U | 0U)  /*!< EXTI_POSITION_8  | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE3            (0xF000U << 16U | 0U)  /*!< EXTI_POSITION_12 | EXTICR[0] */
#define LL_GPIO_AF_EXTI_LINE4            (0x000FU << 16U | 1U)  /*!< EXTI_POSITION_0  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE5            (0x00F0U << 16U | 1U)  /*!< EXTI_POSITION_4  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE6            (0x0F00U << 16U | 1U)  /*!< EXTI_POSITION_8  | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE7            (0xF000U << 16U | 1U)  /*!< EXTI_POSITION_12 | EXTICR[1] */
#define LL_GPIO_AF_EXTI_LINE8            (0x000FU << 16U | 2U)  /*!< EXTI_POSITION_0  | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE9            (0x00F0U << 16U | 2U)  /*!< EXTI_POSITION_4  | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE10           (0x0F00U << 16U | 2U)  /*!< EXTI_POSITION_8  | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE11           (0xF000U << 16U | 2U)  /*!< EXTI_POSITION_12 | EXTICR[2] */
#define LL_GPIO_AF_EXTI_LINE12           (0x000FU << 16U | 3U)  /*!< EXTI_POSITION_0  | EXTICR[3] */
#define LL_GPIO_AF_EXTI_LINE13           (0x00F0U << 16U | 3U)  /*!< EXTI_POSITION_4  | EXTICR[3] */
#define LL_GPIO_AF_EXTI_LINE14           (0x0F00U << 16U | 3U)  /*!< EXTI_POSITION_8  | EXTICR[3] */
#define LL_GPIO_AF_EXTI_LINE15           (0xF000U << 16U | 3U)  /*!< EXTI_POSITION_12 | EXTICR[3] */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Macros GPIO Exported Macros
  * @{
  */

/** @defgroup GPIO_LL_EM_WRITE_READ Common Write and read registers Macros
  * @{
  */

/**
  * @brief  Write a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be written
  * @param  __VALUE__ Value to be written in the register
  * @retval None
  */
#define LL_GPIO_WriteReg(__INSTANCE__, __REG__, __VALUE__) WRITE_REG(__INSTANCE__->__REG__, (__VALUE__))

/**
  * @brief  Read a value in GPIO register
  * @param  __INSTANCE__ GPIO Instance
  * @param  __REG__ Register to be read
  * @retval Register value
  */
#define LL_GPIO_ReadReg(__INSTANCE__, __REG__) READ_REG(__INSTANCE__->__REG__)
/**
  * @}
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @defgroup GPIO_LL_Exported_Functions GPIO Exported Functions
  * @{
  */

/** @defgroup GPIO_LL_EF_Port_Configuration Port Configuration
  * @{
  */

/**
  * @brief  Configure gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Analog, Floating input, Input with pull-up/pull-down, General purpose Output,
  *         Alternate function Output.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll CRL        CNFy         LL_GPIO_SetPinMode
  * @rmtoll CRL        MODEy        LL_GPIO_SetPinMode
  * @rmtoll CRH        CNFy         LL_GPIO_SetPinMode
  * @rmtoll CRH        MODEy        LL_GPIO_SetPinMode
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
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
  * @param  Mode This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_MODE_ANALOG
  *         @arg @ref LL_GPIO_MODE_FLOATING
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  *         @arg @ref LL_GPIO_MODE_ALTERNATE
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  MODIFY_REG(*pReg, ((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << (POSITION_VAL(Pin) * 4U)), (Mode << (POSITION_VAL(Pin) * 4U)));
}

/**
  * @brief  Return gpio mode for a dedicated pin on dedicated port.
  * @note   I/O mode can be Analog, Floating input, Input with pull-up/pull-down, General purpose Output,
  *         Alternate function Output.
  * @note   Warning: only one pin can be passed as parameter.
  * @rmtoll CRL        CNFy         LL_GPIO_GetPinMode
  * @rmtoll CRL        MODEy        LL_GPIO_GetPinMode
  * @rmtoll CRH        CNFy         LL_GPIO_GetPinMode
  * @rmtoll CRH        MODEy        LL_GPIO_GetPinMode
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
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
  * @retval Returned value can be one of the following values:
  *         @arg @ref LL_GPIO_MODE_ANALOG
  *         @arg @ref LL_GPIO_MODE_FLOATING
  *         @arg @ref LL_GPIO_MODE_INPUT
  *         @arg @ref LL_GPIO_MODE_OUTPUT
  *         @arg @ref LL_GPIO_MODE_ALTERNATE
  */
__STATIC_INLINE uint32_t LL_GPIO_GetPinMode(GPIO_TypeDef *GPIOx, uint32_t Pin)
{
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  return (READ_BIT(*pReg, ((GPIO_CRL_CNF0 | GPIO_CRL_MODE0) << (POSITION_VAL(Pin) * 4U))) >> (POSITION_VAL(Pin) * 4U));
}

/**
  * @brief  Configure gpio speed for a dedicated pin on dedicated port.
  * @note   I/O speed can be Low, Medium or Fast speed.
  * @note   Warning: only one pin can be passed as parameter.
  * @note   Refer to datasheet for frequency specifications and the power
  *         supply and load conditions for each speed.
  * @rmtoll CRL      MODEy       LL_GPIO_SetPinSpeed
  * @rmtoll CRH      MODEy       LL_GPIO_SetPinSpeed
  * @param  GPIOx GPIO Port
  * @param  Pin This parameter can be one of the following values:
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
  * @param  Speed This parameter can be one of the following values:
  *         @arg @ref LL_GPIO_SPEED_FREQ_LOW
  *         @arg @ref LL_GPIO_SPEED_FREQ_MEDIUM
  *         @arg @ref LL_GPIO_SPEED_FREQ_HIGH
  * @retval None
  */
__STATIC_INLINE void LL_GPIO_SetPinSpeed(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t  Speed)
{
  register uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&GPIOx->CRL) + (Pin >> 24)));
  MODIFY_REG(*pReg, (GPIO_CRL_MODE0 << (POSITION_VAL(Pin) * 4U)),
             (Speed << (POSITION_VAL(Pin) * 4U)));
}
