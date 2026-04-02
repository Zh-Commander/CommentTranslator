/**
  ******************************************************************************
  * @file    stm32f1xx_hal_gpio_ex.h
  * @author  MCD Application Team
  * @brief   GPIO HAL扩展模块头文件。
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

/* 防止递归包含 -------------------------------------------------------------*/
#ifndef STM32F1xx_HAL_GPIO_EX_H
#define STM32F1xx_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 -----------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
  * @brief GPIOEx扩展功能模块
  * @{
  */
/* 导出类型 -----------------------------------------------------------------*/
/* 导出常量 -----------------------------------------------------------------*/

/** @defgroup GPIOEx_Exported_Constants GPIOEx导出常量
  * @{
  */

/** @defgroup GPIOEx_EVENTOUT EVENTOUT Cortex配置
  * @brief 本节提供使用Cortex EVENTOUT信号的定义。
  * @{
  */

/** @defgroup GPIOEx_EVENTOUT_PIN EVENTOUT引脚
  * @{
  */

/* 定义EVENTOUT输出引脚编号，对应AFIO_EVCR寄存器的PIN选择位 */
#define AFIO_EVENTOUT_PIN_0  AFIO_EVCR_PIN_PX0 /*!< EVENTOUT输出在引脚0 */
#define AFIO_EVENTOUT_PIN_1  AFIO_EVCR_PIN_PX1 /*!< EVENTOUT输出在引脚1 */
#define AFIO_EVENTOUT_PIN_2  AFIO_EVCR_PIN_PX2 /*!< EVENTOUT输出在引脚2 */
#define AFIO_EVENTOUT_PIN_3  AFIO_EVCR_PIN_PX3 /*!< EVENTOUT输出在引脚3 */
#define AFIO_EVENTOUT_PIN_4  AFIO_EVCR_PIN_PX4 /*!< EVENTOUT输出在引脚4 */
#define AFIO_EVENTOUT_PIN_5  AFIO_EVCR_PIN_PX5 /*!< EVENTOUT输出在引脚5 */
#define AFIO_EVENTOUT_PIN_6  AFIO_EVCR_PIN_PX6 /*!< EVENTOUT输出在引脚6 */
#define AFIO_EVENTOUT_PIN_7  AFIO_EVCR_PIN_PX7 /*!< EVENTOUT输出在引脚7 */
#define AFIO_EVENTOUT_PIN_8  AFIO_EVCR_PIN_PX8 /*!< EVENTOUT输出在引脚8 */
#define AFIO_EVENTOUT_PIN_9  AFIO_EVCR_PIN_PX9 /*!< EVENTOUT输出在引脚9 */
#define AFIO_EVENTOUT_PIN_10 AFIO_EVCR_PIN_PX10 /*!< EVENTOUT输出在引脚10 */
#define AFIO_EVENTOUT_PIN_11 AFIO_EVCR_PIN_PX11 /*!< EVENTOUT输出在引脚11 */
#define AFIO_EVENTOUT_PIN_12 AFIO_EVCR_PIN_PX12 /*!< EVENTOUT输出在引脚12 */
#define AFIO_EVENTOUT_PIN_13 AFIO_EVCR_PIN_PX13 /*!< EVENTOUT输出在引脚13 */
#define AFIO_EVENTOUT_PIN_14 AFIO_EVCR_PIN_PX14 /*!< EVENTOUT输出在引脚14 */
#define AFIO_EVENTOUT_PIN_15 AFIO_EVCR_PIN_PX15 /*!< EVENTOUT输出在引脚15 */

/* 检查输入的引脚编号是否合法 */
#define IS_AFIO_EVENTOUT_PIN(__PIN__) (((__PIN__) == AFIO_EVENTOUT_PIN_0) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_1) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_2) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_3) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_4) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_5) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_6) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_7) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_8) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_9) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_10) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_11) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_12) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_13) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_14) || \
                                       ((__PIN__) == AFIO_EVENTOUT_PIN_15))
/**
  * @}
  */

/** @defgroup GPIOEx_EVENTOUT_PORT EVENTOUT端口
  * @{
  */

/* 定义EVENTOUT输出端口，对应AFIO_EVCR寄存器的PORT选择位 */
#define AFIO_EVENTOUT_PORT_A AFIO_EVCR_PORT_PA /*!< EVENTOUT输出在端口A */
#define AFIO_EVENTOUT_PORT_B AFIO_EVCR_PORT_PB /*!< EVENTOUT输出在端口B */
#define AFIO_EVENTOUT_PORT_C AFIO_EVCR_PORT_PC /*!< EVENTOUT输出在端口C */
#define AFIO_EVENTOUT_PORT_D AFIO_EVCR_PORT_PD /*!< EVENTOUT输出在端口D */
#define AFIO_EVENTOUT_PORT_E AFIO_EVCR_PORT_PE /*!< EVENTOUT输出在端口E */

/* 检查输入的端口号是否合法 */
#define IS_AFIO_EVENTOUT_PORT(__PORT__) (((__PORT__) == AFIO_EVENTOUT_PORT_A) || \
                                         ((__PORT__) == AFIO_EVENTOUT_PORT_B) || \
                                         ((__PORT__) == AFIO_EVENTOUT_PORT_C) || \
                                         ((__PORT__) == AFIO_EVENTOUT_PORT_D) || \
                                         ((__PORT__) == AFIO_EVENTOUT_PORT_E))
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIOEx_AFIO_AF_REMAPPING 复用功能重映射
  * @brief 本节提供将复用功能重映射到其他端口/引脚的定义。
  * @{
  */

/**
  * @brief 使能SPI1复用功能NSS, SCK, MISO和MOSI的重映射。
  * @note  ENABLE: 重映射     (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SPI1_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_SPI1_REMAP)

/**
  * @brief 禁止SPI1复用功能NSS, SCK, MISO和MOSI的重映射。
  * @note  DISABLE: 无重映射 (NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SPI1_DISABLE()  AFIO_REMAP_DISABLE(AFIO_MAPR_SPI1_REMAP)

/**
  * @brief 使能I2C1复用功能SCL和SDA的重映射。
  * @note  ENABLE: 重映射     (SCL/PB8, SDA/PB9)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_I2C1_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_I2C1_REMAP)

/**
  * @brief 禁止I2C1复用功能SCL和SDA的重映射。
  * @note  DISABLE: 无重映射 (SCL/PB6, SDA/PB7)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_I2C1_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_I2C1_REMAP)

/**
  * @brief 使能USART1复用功能TX和RX的重映射。
  * @note  ENABLE: 重映射     (TX/PB6, RX/PB7)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART1_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_USART1_REMAP)

/**
  * @brief 禁止USART1复用功能TX和RX的重映射。
  * @note  DISABLE: 无重映射 (TX/PA9, RX/PA10)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART1_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_USART1_REMAP)

/**
  * @brief 使能USART2复用功能CTS, RTS, CK, TX和RX的重映射。
  * @note  ENABLE: 重映射     (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART2_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_USART2_REMAP)

/**
  * @brief 禁止USART2复用功能CTS, RTS, CK, TX和RX的重映射。
  * @note  DISABLE: 无重映射 (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART2_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_USART2_REMAP)

/**
  * @brief 使能USART3复用功能CTS, RTS, CK, TX和RX的重映射。
  * @note  ENABLE: 完全重映射     (TX/PD8,  RX/PD9,  CK/PD10, CTS/PD11, RTS/PD12)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART3_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_USART3_REMAP_FULLREMAP, AFIO_MAPR_USART3_REMAP_FULLREMAP)

/**
  * @brief 使能USART3复用功能CTS, RTS, CK, TX和RX的部分重映射。
  * @note  PARTIAL: 部分重映射 (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART3_PARTIAL()  AFIO_REMAP_PARTIAL(AFIO_MAPR_USART3_REMAP_PARTIALREMAP, AFIO_MAPR_USART3_REMAP_FULLREMAP)

/**
  * @brief 禁止USART3复用功能CTS, RTS, CK, TX和RX的重映射。
  * @note  DISABLE: 无重映射      (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_USART3_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_USART3_REMAP_NOREMAP, AFIO_MAPR_USART3_REMAP_FULLREMAP)

/**
  * @brief 使能TIM1复用功能通道1到4, 1N到3N, 外部触发(ETR)和刹车输入(BKIN)的重映射
  * @note  ENABLE: 完全重映射     (ETR/PE7,  CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8,  CH2N/PE10, CH3N/PE12)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM1_REMAP_FULLREMAP, AFIO_MAPR_TIM1_REMAP_FULLREMAP)

/**
  * @brief 使能TIM1复用功能通道1到4, 1N到3N, 外部触发(ETR)和刹车输入(BKIN)的部分重映射
  * @note  PARTIAL: 部分重映射 (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PA6,  CH1N/PA7,  CH2N/PB0,  CH3N/PB1)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1_PARTIAL()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM1_REMAP_PARTIALREMAP, AFIO_MAPR_TIM1_REMAP_FULLREMAP)

/**
  * @brief 禁止TIM1复用功能通道1到4, 1N到3N, 外部触发(ETR)和刹车输入(BKIN)的重映射
  * @note  DISABLE: 无重映射      (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM1_REMAP_NOREMAP, AFIO_MAPR_TIM1_REMAP_FULLREMAP)

/**
  * @brief 使能TIM2复用功能通道1到4和外部触发(ETR)的重映射
  * @note  ENABLE: 完全重映射       (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM2_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_FULLREMAP, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief 使能TIM2复用功能通道1到4和外部触发(ETR)的部分重映射2
  * @note  PARTIAL_2: 部分重映射 (CH1/ETR/PA0,  CH2/PA1, CH3/PB10, CH4/PB11)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM2_PARTIAL_2()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief 使能TIM2复用功能通道1到4和外部触发(ETR)的部分重映射1
  * @note  PARTIAL_1: 部分重映射 (CH1/ETR/PA15, CH2/PB3, CH3/PA2,  CH4/PA3)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM2_PARTIAL_1()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief 禁止TIM2复用功能通道1到4和外部触发(ETR)的重映射
  * @note  DISABLE: 无重映射        (CH1/ETR/PA0,  CH2/PA1, CH3/PA2,  CH4/PA3)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM2_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_NOREMAP, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief 使能TIM3复用功能通道1到4的重映射
  * @note  ENABLE: 完全重映射     (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
  * @note  TIM3_ETR在PE0上未被重映射。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM3_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM3_REMAP_FULLREMAP, AFIO_MAPR_TIM3_REMAP_FULLREMAP)

/**
  * @brief 使能TIM3复用功能通道1到4的部分重映射
  * @note  PARTIAL: 部分重映射 (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR在PE0上未被重映射。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM3_PARTIAL()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM3_REMAP_PARTIALREMAP, AFIO_MAPR_TIM3_REMAP_FULLREMAP)

/**
  * @brief 禁止TIM3复用功能通道1到4的重映射
  * @note  DISABLE: 无重映射      (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR在PE0上未被重映射。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM3_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM3_REMAP_NOREMAP, AFIO_MAPR_TIM3_REMAP_FULLREMAP)

/**
  * @brief 使能TIM4复用功能通道1到4的重映射。
  * @note  ENABLE: 完全重映射 (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
  * @note  TIM4_ETR在PE0上未被重映射。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM4_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_TIM4_REMAP)

/**
  * @brief 禁止TIM4复用功能通道1到4的重映射。
  * @note  DISABLE: 无重映射  (TIM4_CH1/PB6,  TIM4_CH2/PB7,  TIM4_CH3/PB8,  TIM4_CH4/PB9)
  * @note  TIM4_ETR在PE0上未被重映射。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM4_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM4_REMAP)

#if defined(AFIO_MAPR_CAN_REMAP_REMAP1)

/**
  * @brief 在单CAN接口器件中使能或禁止CAN复用功能CAN_RX和CAN_TX的重映射。
  * @note  情况 1: CAN_RX映射到PA11, CAN_TX映射到PA12
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CAN1_1()  AFIO_REMAP_PARTIAL(AFIO_MAPR_CAN_REMAP_REMAP1, AFIO_MAPR_CAN_REMAP)

/**
  * @brief 在单CAN接口器件中使能或禁止CAN复用功能CAN_RX和CAN_TX的重映射。
  * @note  情况 2: CAN_RX映射到PB8,  CAN_TX映射到PB9 (在36引脚封装上不可用)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CAN1_2()  AFIO_REMAP_PARTIAL(AFIO_MAPR_CAN_REMAP_REMAP2, AFIO_MAPR_CAN_REMAP)

/**
  * @brief 在单CAN接口器件中使能或禁止CAN复用功能CAN_RX和CAN_TX的重映射。
  * @note  情况 3: CAN_RX映射到PD0,  CAN_TX映射到PD1
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CAN1_3()  AFIO_REMAP_PARTIAL(AFIO_MAPR_CAN_REMAP_REMAP3, AFIO_MAPR_CAN_REMAP)

#endif

/**
  * @brief 使能PD0和PD1的重映射。当不使用HSE振荡器时
  *        (应用程序运行在内部8 MHz RC振荡器)，PD0和PD1可以映射到OSC_IN和
  *        OSC_OUT。这仅在36、48和64引脚封装上可用(PD0和PD1在
  *        100引脚和144引脚封装上可用，无需重映射)。
  * @note  ENABLE: PD0重映射到OSC_IN, PD1重映射到OSC_OUT。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_PD01_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_PD01_REMAP)

/**
  * @brief 禁止PD0和PD1的重映射。当不使用HSE振荡器时
  *        (应用程序运行在内部8 MHz RC振荡器)，PD0和PD1可以映射到OSC_IN和
  *        OSC_OUT。这仅在36、48和64引脚封装上可用(PD0和PD1在
  *        100引脚和144引脚封装上可用，无需重映射)。
  * @note  DISABLE: 不重映射PD0和PD1
  * @retval 无
  */
#define __HAL_AFIO_REMAP_PD01_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_PD01_REMAP)

#if defined(AFIO_MAPR_TIM5CH4_IREMAP)
/**
  * @brief 使能TIM5通道4的重映射。
  * @note  ENABLE: LSI内部时钟连接到TIM5_CH4输入用于校准目的。
  * @note  此功能仅在高密度Value Line器件中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM5CH4_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_TIM5CH4_IREMAP)

/**
  * @brief 禁止TIM5通道4的重映射。
  * @note  DISABLE: TIM5_CH4连接到PA3
  * @note  此功能仅在高密度Value Line器件中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM5CH4_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM5CH4_IREMAP)
#endif

#if defined(AFIO_MAPR_ETH_REMAP)
/**
  * @brief 使能以太网MAC与PHY连接的重映射。
  * @note  ENABLE: 重映射     (RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12)
  * @note  此位仅在互联型器件中可用，否则保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ETH_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ETH_REMAP)

/**
  * @brief 禁止以太网MAC与PHY连接的重映射。
  * @note  DISABLE: 无重映射 (RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5,  RXD2/PB0,  RXD3/PB1)
  * @note  此位仅在互联型器件中可用，否则保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ETH_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ETH_REMAP)
#endif

#if defined(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief 使能CAN2复用功能CAN2_RX和CAN2_TX的重映射。
  * @note  ENABLE: 重映射     (CAN2_RX/PB5,  CAN2_TX/PB6)
  * @note  此位仅在互联型器件中可用，否则保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CAN2_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief 禁止CAN2复用功能CAN2_RX和CAN2_TX的重映射。
  * @note  DISABLE: 无重映射 (CAN2_RX/PB12, CAN2_TX/PB13)
  * @note  此位仅在互联型器件中可用，否则保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CAN2_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_CAN2_REMAP)
#endif

#if defined(AFIO_MAPR_MII_RMII_SEL)
/**
  * @brief 配置以太网MAC内部用于外部MII或RMII PHY。
  * @note  ETH_RMII: 配置以太网MAC用于连接RMII PHY
  * @note  此位仅在互联型器件中可用，否则保留。
  * @retval 无
  */
#define __HAL_AFIO_ETH_RMII() AFIO_REMAP_ENABLE(AFIO_MAPR_MII_RMII_SEL)

/**
  * @brief 配置以太网MAC内部用于外部MII或RMII PHY。
  * @note  ETH_MII: 配置以太网MAC用于连接MII PHY
  * @note  此位仅在互联型器件中可用，否则保留。
  * @retval 无
  */
#define __HAL_AFIO_ETH_MII()  AFIO_REMAP_DISABLE(AFIO_MAPR_MII_RMII_SEL)
#endif

/**
  * @brief 使能ADC1_ETRGINJ (ADC 1外部触发注入转换)的重映射。
  * @note  ENABLE: ADC1外部事件注入转换连接到TIM8通道4。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC1_ETRGINJ_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC1_ETRGINJ_REMAP)

/**
  * @brief 禁止ADC1_ETRGINJ (ADC 1外部触发注入转换)的重映射。
  * @note  DISABLE: ADC1外部触发注入转换连接到EXTI15
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC1_ETRGINJ_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC1_ETRGINJ_REMAP)

/**
  * @brief 使能ADC1_ETRGREG (ADC 1外部触发常规转换)的重映射。
  * @note  ENABLE: ADC1外部事件常规转换连接到TIM8 TRG0。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC1_ETRGREG_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC1_ETRGREG_REMAP)

/**
  * @brief 禁止ADC1_ETRGREG (ADC 1外部触发常规转换)的重映射。
  * @note  DISABLE: ADC1外部触发常规转换连接到EXTI11
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC1_ETRGREG_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC1_ETRGREG_REMAP)

#if defined(AFIO_MAPR_ADC2_ETRGINJ_REMAP)

/**
  * @brief 使能ADC2_ETRGREG (ADC 2外部触发注入转换)的重映射。
  * @note  ENABLE: ADC2外部事件注入转换连接到TIM8通道4。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC2_ETRGINJ_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC2_ETRGINJ_REMAP)

/**
  * @brief 禁止ADC2_ETRGREG (ADC 2外部触发注入转换)的重映射。
  * @note  DISABLE: ADC2外部触发注入转换连接到EXTI15
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC2_ETRGINJ_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC2_ETRGINJ_REMAP)
#endif

#if defined (AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief 使能ADC2_ETRGREG (ADC 2外部触发常规转换)的重映射。
  * @note  ENABLE: ADC2外部事件常规转换连接到TIM8 TRG0。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC2_ETRGREG_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief 禁止ADC2_ETRGREG (ADC 2外部触发常规转换)的重映射。
  * @note  DISABLE: ADC2外部触发常规转换连接到EXTI11
  * @retval 无
  */
#define __HAL_AFIO_REMAP_ADC2_ETRGREG_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC2_ETRGREG_REMAP)
#endif

/**
  * @brief 使能串行线JTAG配置
  * @note  ENABLE: 全SWJ (JTAG-DP + SW-DP): 复位状态
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SWJ_ENABLE()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_RESET)
/**
  * @brief  启用串行线JTAG配置（不含NJTRST引脚）
  * @note   NONJTRST模式：全SWJ（JTAG-DP + SW-DP）但禁用NJTRST引脚。
  *         此时JTAG接口仍可用，但失去JTAG复位功能，释放了NJTRST引脚供普通IO使用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SWJ_NONJTRST()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_NOJNTRST)

/**
  * @brief  启用串行线JTAG配置（禁用JTAG-DP）
  * @note   NOJTAG模式：禁用JTAG-DP，启用SW-DP。
  *         释放了JTAG占用的多个引脚，仅保留SWDIO和SWCLK两根线用于调试。
  * @retval 无
  */

#define __HAL_AFIO_REMAP_SWJ_NOJTAG()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_JTAGDISABLE)

/**
  * @brief  禁用串行线JTAG配置
  * @note   DISABLE模式：JTAG-DP和SW-DP均被禁用。
  *         释放所有调试引脚作为普通GPIO使用，注意此时将无法通过调试器连接MCU。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SWJ_DISABLE()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_DISABLE)

#if defined(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief  启用SPI3复用功能重映射
  * @note   启用重映射 (SPI3_NSS-I2S3_WS/PA4,  SPI3_SCK-I2S3_CK/PC10, SPI3_MISO/PC11, SPI3_MOSI-I2S3_SD/PC12)
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SPI3_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_SPI3_REMAP)

/**
  * @brief  禁用SPI3复用功能重映射
  * @note   禁用重映射 (SPI3_NSS-I2S3_WS/PA15, SPI3_SCK-I2S3_CK/PB3,  SPI3_MISO/PB4,  SPI3_MOSI-I2S3_SD/PB5)。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_SPI3_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_SPI3_REMAP)
#endif

#if defined(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief  控制TIM2_ITR1内部映射
  * @note   映射到USB：将USB OTG SOF (帧起始) 输出连接到TIM2_ITR1，用于校准目的。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_TIM2ITR1_TO_USB() AFIO_REMAP_ENABLE(AFIO_MAPR_TIM2ITR1_IREMAP)

/**
  * @brief  控制TIM2_ITR1内部映射
  * @note   映射到以太网：将TIM2_ITR1内部连接到以太网PTP输出，用于校准目的。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_TIM2ITR1_TO_ETH() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM2ITR1_IREMAP)
#endif

#if defined(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief  启用以太网PTP PPS功能重映射
  * @note   启用：PTP_PPS信号输出到PB5引脚。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_ETH_PTP_PPS_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_PTP_PPS_REMAP)

/**
  * @brief  禁用以太网PTP PPS功能重映射
  * @note   禁用：PTP_PPS信号不输出到PB5引脚。
  * @note   此位仅在互联型设备中可用，其他设备中保留。
  * @retval 无
  */
#define __HAL_AFIO_ETH_PTP_PPS_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_PTP_PPS_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief  启用TIM9通道重映射
  * @note   启用重映射 (TIM9_CH1 映射到 PE5, TIM9_CH2 映射到 PE6)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM9_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP)

/**
  * @brief  禁用TIM9通道重映射
  * @note   禁用重映射 (TIM9_CH1 映射到 PA2, TIM9_CH2 映射到 PA3)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM9_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM9_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief  启用TIM10通道重映射
  * @note   启用重映射 (TIM10_CH1 映射到 PF6)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM10_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP)

/**
  * @brief  禁用TIM10通道重映射
  * @note   禁用重映射 (TIM10_CH1 映射到 PB8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM10_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM10_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM11_REMAP)
/**
  * @brief  启用TIM11通道重映射
  * @note   启用重映射 (TIM11_CH1 映射到 PF7)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM11_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP)

/**
  * @brief  禁用TIM11通道重映射
  * @note   禁用重映射 (TIM11_CH1 映射到 PB9)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM11_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM11_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief  启用TIM13通道重映射
  * @note   启用重映射 STM32F100:(TIM13_CH1 映射到 PF8)。其他系列:(TIM13_CH1 映射到 PB0)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM13_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP)

/**
  * @brief  禁用TIM13通道重映射
  * @note   禁用重映射 STM32F100:(TIM13_CH1 映射到 PA6)。其他系列:(TIM13_CH1 映射到 PC8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM13_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM13_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief  启用TIM14通道重映射
  * @note   启用重映射 STM32F100:(TIM14_CH1 映射到 PB1)。其他系列:(TIM14_CH1 映射到 PF9)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM14_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP)

/**
  * @brief  禁用TIM14通道重映射
  * @note   禁用重映射 STM32F100:(TIM14_CH1 映射到 PC9)。其他系列:(TIM14_CH1 映射到 PA7)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM14_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM14_REMAP)
#endif

#if defined(AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief  控制FSMC_NADV信号的使用
  * @note   断开连接：NADV信号不连接。该I/O引脚可被其他外设使用。
  * @retval 无
  */
#define __HAL_AFIO_FSMCNADV_DISCONNECTED() SET_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP)

/**
  * @brief  控制FSMC_NADV信号的使用
  * @note   保持连接：NADV信号连接到输出（默认状态）。
  * @retval 无
  */
#define __HAL_AFIO_FSMCNADV_CONNECTED()    CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_FSMC_NADV_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief  启用TIM15通道重映射
  * @note   启用重映射 (TIM15_CH1 映射到 PB14, TIM15_CH2 映射到 PB15)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM15_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP)

/**
  * @brief  禁用TIM15通道重映射
  * @note   禁用重映射 (TIM15_CH1 映射到 PA2,  TIM15_CH2 映射到 PA3)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM15_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM15_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief  启用TIM16通道重映射
  * @note   启用重映射 (TIM16_CH1 映射到 PA6)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM16_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP)

/**
  * @brief  禁用TIM16通道重映射
  * @note   禁用重映射 (TIM16_CH1 映射到 PB8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM16_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM16_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief  启用TIM17通道重映射
  * @note   启用重映射 (TIM17_CH1 映射到 PA7)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM17_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP)

/**
  * @brief  禁用TIM17通道重映射
  * @note   禁用重映射 (TIM17_CH1 映射到 PB9)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM17_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM17_REMAP)
#endif

#if defined(AFIO_MAPR2_CEC_REMAP)

/**
  * @brief  启用CEC功能重映射
  * @note   启用重映射 (CEC 映射到 PB10)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CEC_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP)

/**
  * @brief  禁用CEC功能重映射
  * @note   禁用重映射 (CEC 映射到 PB8)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_CEC_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_CEC_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief  控制TIM1_CH1和TIM1_CH2 DMA请求映射到DMA1通道
  * @note   启用重映射 (TIM1_CH1 DMA请求映射到 DMA1 Channel6, TIM1_CH2 DMA请求映射到 DMA1 Channel6)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1DMA_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP)

/**
  * @brief  控制TIM1_CH1和TIM1_CH2 DMA请求映射到DMA1通道
  * @note   禁用重映射 (TIM1_CH1 DMA请求映射到 DMA1 Channel2, TIM1_CH2 DMA请求映射到 DMA1 Channel3)。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM1DMA_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM1_DMA_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道
  * @note   启用重映射 (TIM6_DAC1 DMA请求映射到 DMA1 Channel3, TIM7_DAC2 DMA请求映射到 DMA1 Channel4)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM67DACDMA_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP)

/**
  * @brief  控制TIM6_DAC1和TIM7_DAC2 DMA请求映射到DMA1通道
  * @note   禁用重映射 (TIM6_DAC1 DMA请求映射到 DMA2 Channel3, TIM7_DAC2 DMA请求映射到 DMA2 Channel4)
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM67DACDMA_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM67_DAC_DMA_REMAP)
#endif

#if defined(AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief  启用TIM12通道重映射
  * @note   启用重映射 (TIM12_CH1 映射到 PB12, TIM12_CH2 映射到 PB13)。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM12_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP)

/**
  * @brief  禁用TIM12通道重映射
  * @note   禁用重映射 (TIM12_CH1 映射到 PC4,  TIM12_CH2 映射到 PC5)。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_TIM12_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_TIM12_REMAP)
#endif

#if defined(AFIO_MAPR2_MISC_REMAP)

/**
  * @brief  杂项功能重映射配置
  *         此位由软件置位和清除，用于控制杂项功能。
  *         包括：DMA2通道5中断在中断向量表中的位置。
  *         DAC触发源3的定时器选择 (TSEL[2:0] = 011, 详情请参考DAC_CR寄存器)。
  * @note   启用：DMA2通道5中断单独映射到位置60，TIM15 TRGO事件被选为DAC触发源3，TIM15触发TIM1/3。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_MISC_ENABLE()  SET_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP)

/**
  * @brief  杂项功能重映射配置
  *         此位由软件置位和清除，用于控制杂项功能。
  *         包括：DMA2通道5中断在中断向量表中的位置。
  *         DAC触发源3的定时器选择 (TSEL[2:0] = 011, 详情请参考DAC_CR寄存器)。
  * @note   禁用：DMA2通道5中断与DMA2通道4共同映射到位置59，TIM5 TRGO事件被选为DAC触发源3，TIM5触发TIM1/3。
  * @note   此位仅在高密度Value Line设备中可用。
  * @retval 无
  */
#define __HAL_AFIO_REMAP_MISC_DISABLE() CLEAR_BIT(AFIO->MAPR2, AFIO_MAPR2_MISC_REMAP)
#endif

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup GPIOEx_Private_Macros GPIOEx 私有宏
  * @{
  */
/* 根据具体的芯片型号定义GPIO端口索引获取宏 */
#if defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F102xB) || defined(STM32F103x6)
/* 获取GPIO端口的索引号 (0-3)，用于数组查找或位操作 */
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :3uL)
#elif defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F103xB) || defined(STM32F105xC) || defined(STM32F107xC)
/* 获取GPIO端口的索引号 (0-4) */
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :\
                                   ((__GPIOx__) == (GPIOD))? 3uL :4uL)
#elif defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F101xG) || defined(STM32F103xE) || defined(STM32F103xG)
/* 获取GPIO端口的索引号 (0-6) */
#define GPIO_GET_INDEX(__GPIOx__) (((__GPIOx__) == (GPIOA))? 0uL :\
                                   ((__GPIOx__) == (GPIOB))? 1uL :\
                                   ((__GPIOx__) == (GPIOC))? 2uL :\
                                   ((__GPIOx__) == (GPIOD))? 3uL :\
                                   ((__GPIOx__) == (GPIOE))? 4uL :\
                                   ((__GPIOx__) == (GPIOF))? 5uL :6uL)
#endif

/* AFIO重映射使能宏定义 */
/* 参数 REMAP_PIN: 需要使能的重映射引脚定义 */
/* 使用do...while(0)结构确保宏在使用时可以像函数一样安全调用，避免分号问题 */
/* 注意：操作过程中保留了SWJ配置，防止调试接口意外失效 */
#define AFIO_REMAP_ENABLE(REMAP_PIN)       do{ uint32_t tmpreg = AFIO->MAPR; \
                                               tmpreg |= AFIO_MAPR_SWJ_CFG;  \
                                               tmpreg |= REMAP_PIN;          \
                                               AFIO->MAPR = tmpreg;          \
                                               }while(0u)

/* AFIO重映射禁用宏定义 */
/* 参数 REMAP_PIN: 需要禁用的重映射引脚定义 */
/* 使用位操作清除对应的重映射位 */
#define AFIO_REMAP_DISABLE(REMAP_PIN)      do{ uint32_t tmpreg = AFIO->MAPR;  \
                                               tmpreg |= AFIO_MAPR_SWJ_CFG;   \
                                               tmpreg &= ~REMAP_PIN;          \
                                               AFIO->MAPR = tmpreg;           \
                                               }while(0u)

/* AFIO重映射部分重映射宏定义 */
/* 参数 REMAP_PIN: 重映射设置值 */
/* 参数 REMAP_PIN_MASK: 重映射掩码，用于先清除相关位 */
#define AFIO_REMAP_PARTIAL(REMAP_PIN, REMAP_PIN_MASK) do{ uint32_t tmpreg = AFIO->MAPR; \
                                                          tmpreg &= ~REMAP_PIN_MASK;    \
                                                          tmpreg |= AFIO_MAPR_SWJ_CFG;  \
                                                          tmpreg |= REMAP_PIN;          \
                                                          AFIO->MAPR = tmpreg;          \
                                                          }while(0u)

/* AFIO调试配置宏定义 */
/* 参数 DBGAFR_SWJCFG: 调试接口配置值 */
/* 专门用于配置SWJ（JTAG/SWD）调试接口的模式 */
#define AFIO_DBGAFR_CONFIG(DBGAFR_SWJCFG)  do{ uint32_t tmpreg = AFIO->MAPR;     \
                                               tmpreg &= ~AFIO_MAPR_SWJ_CFG_Msk; \
                                               tmpreg |= DBGAFR_SWJCFG;          \
                                               AFIO->MAPR = tmpreg;              \
                                               }while(0u)

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------*/

/** @addtogroup GPIOEx_Exported_Functions
  * @{
  */

/** @addtogroup GPIOEx_Exported_Functions_Group1
  * @{
  */
/* 配置事件输出功能 */
void HAL_GPIOEx_ConfigEventout(uint32_t GPIO_PortSource, uint32_t GPIO_PinSource);
/* 使能事件输出功能 */
void HAL_GPIOEx_EnableEventout(void);
/* 禁用事件输出功能 */
void HAL_GPIOEx_DisableEventout(void);

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

#endif /* STM32F1xx_HAL_GPIO_EX_H */
