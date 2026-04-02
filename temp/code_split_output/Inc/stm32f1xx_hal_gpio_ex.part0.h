/**
  ******************************************************************************
  * @file    stm32f1xx_hal_gpio_ex.h
  * @author  MCD Application Team
  * @brief   Header file of GPIO HAL Extension module.
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
// 防止重复包含头文件
#ifndef STM32F1xx_HAL_GPIO_EX_H
#define STM32F1xx_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
// 包含HAL库通用定义头文件
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
  * @{
  */
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIOEx_Exported_Constants GPIOEx Exported Constants
  * @{
  */

/** @defgroup GPIOEx_EVENTOUT EVENTOUT Cortex Configuration
  * @brief This section propose definition to use the Cortex EVENTOUT signal.
  * @{
  */

/** @defgroup GPIOEx_EVENTOUT_PIN EVENTOUT Pin
  * @{
  */

// 定义Cortex-M内核EVENTOUT信号输出的引脚位置，取值范围0-15
#define AFIO_EVENTOUT_PIN_0  AFIO_EVCR_PIN_PX0 /*!< EVENTOUT on pin 0 */ // EVENTOUT输出在引脚0
#define AFIO_EVENTOUT_PIN_1  AFIO_EVCR_PIN_PX1 /*!< EVENTOUT on pin 1 */ // EVENTOUT输出在引脚1
#define AFIO_EVENTOUT_PIN_2  AFIO_EVCR_PIN_PX2 /*!< EVENTOUT on pin 2 */ // EVENTOUT输出在引脚2
#define AFIO_EVENTOUT_PIN_3  AFIO_EVCR_PIN_PX3 /*!< EVENTOUT on pin 3 */ // EVENTOUT输出在引脚3
#define AFIO_EVENTOUT_PIN_4  AFIO_EVCR_PIN_PX4 /*!< EVENTOUT on pin 4 */ // EVENTOUT输出在引脚4
#define AFIO_EVENTOUT_PIN_5  AFIO_EVCR_PIN_PX5 /*!< EVENTOUT on pin 5 */ // EVENTOUT输出在引脚5
#define AFIO_EVENTOUT_PIN_6  AFIO_EVCR_PIN_PX6 /*!< EVENTOUT on pin 6 */ // EVENTOUT输出在引脚6
#define AFIO_EVENTOUT_PIN_7  AFIO_EVCR_PIN_PX7 /*!< EVENTOUT on pin 7 */ // EVENTOUT输出在引脚7
#define AFIO_EVENTOUT_PIN_8  AFIO_EVCR_PIN_PX8 /*!< EVENTOUT on pin 8 */ // EVENTOUT输出在引脚8
#define AFIO_EVENTOUT_PIN_9  AFIO_EVCR_PIN_PX9 /*!< EVENTOUT on pin 9 */ // EVENTOUT输出在引脚9
#define AFIO_EVENTOUT_PIN_10 AFIO_EVCR_PIN_PX10 /*!< EVENTOUT on pin 10 */ // EVENTOUT输出在引脚10
#define AFIO_EVENTOUT_PIN_11 AFIO_EVCR_PIN_PX11 /*!< EVENTOUT on pin 11 */ // EVENTOUT输出在引脚11
#define AFIO_EVENTOUT_PIN_12 AFIO_EVCR_PIN_PX12 /*!< EVENTOUT on pin 12 */ // EVENTOUT输出在引脚12
#define AFIO_EVENTOUT_PIN_13 AFIO_EVCR_PIN_PX13 /*!< EVENTOUT on pin 13 */ // EVENTOUT输出在引脚13
#define AFIO_EVENTOUT_PIN_14 AFIO_EVCR_PIN_PX14 /*!< EVENTOUT on pin 14 */ // EVENTOUT输出在引脚14
#define AFIO_EVENTOUT_PIN_15 AFIO_EVCR_PIN_PX15 /*!< EVENTOUT on pin 15 */ // EVENTOUT输出在引脚15

// 断言检查宏：用于检查输入的EVENTOUT引脚参数是否合法
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

/** @defgroup GPIOEx_EVENTOUT_PORT EVENTOUT Port
  * @{
  */

// 定义Cortex-M内核EVENTOUT信号输出的端口
#define AFIO_EVENTOUT_PORT_A AFIO_EVCR_PORT_PA /*!< EVENTOUT on port A */ // EVENTOUT输出在端口A
#define AFIO_EVENTOUT_PORT_B AFIO_EVCR_PORT_PB /*!< EVENTOUT on port B */ // EVENTOUT输出在端口B
#define AFIO_EVENTOUT_PORT_C AFIO_EVCR_PORT_PC /*!< EVENTOUT on port C */ // EVENTOUT输出在端口C
#define AFIO_EVENTOUT_PORT_D AFIO_EVCR_PORT_PD /*!< EVENTOUT on port D */ // EVENTOUT输出在端口D
#define AFIO_EVENTOUT_PORT_E AFIO_EVCR_PORT_PE /*!< EVENTOUT on port E */ // EVENTOUT输出在端口E

// 断言检查宏：用于检查输入的EVENTOUT端口参数是否合法
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

/** @defgroup GPIOEx_AFIO_AF_REMAPPING Alternate Function Remapping
  * @brief This section propose definition to remap the alternate function to some other port/pins.
  * @{
  */

/**
  * @brief Enable the remapping of SPI1 alternate function NSS, SCK, MISO and MOSI.
  * @note  ENABLE: Remap     (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)
  * @retval None
  */
// 启用SPI1重映射：将SPI1引脚映射到PA15(NSS), PB3(SCK), PB4(MISO), PB5(MOSI)
#define __HAL_AFIO_REMAP_SPI1_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_SPI1_REMAP)

/**
  * @brief Disable the remapping of SPI1 alternate function NSS, SCK, MISO and MOSI.
  * @note  DISABLE: No remap (NSS/PA4,  SCK/PA5, MISO/PA6, MOSI/PA7)
  * @retval None
  */
// 禁用SPI1重映射：恢复默认引脚PA4(NSS), PA5(SCK), PA6(MISO), PA7(MOSI)
#define __HAL_AFIO_REMAP_SPI1_DISABLE()  AFIO_REMAP_DISABLE(AFIO_MAPR_SPI1_REMAP)

/**
  * @brief Enable the remapping of I2C1 alternate function SCL and SDA.
  * @note  ENABLE: Remap     (SCL/PB8, SDA/PB9)
  * @retval None
  */
// 启用I2C1重映射：将I2C1引脚映射到PB8(SCL), PB9(SDA)
#define __HAL_AFIO_REMAP_I2C1_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_I2C1_REMAP)

/**
  * @brief Disable the remapping of I2C1 alternate function SCL and SDA.
  * @note  DISABLE: No remap (SCL/PB6, SDA/PB7)
  * @retval None
  */
// 禁用I2C1重映射：恢复默认引脚PB6(SCL), PB7(SDA)
#define __HAL_AFIO_REMAP_I2C1_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_I2C1_REMAP)

/**
  * @brief Enable the remapping of USART1 alternate function TX and RX.
  * @note  ENABLE: Remap     (TX/PB6, RX/PB7)
  * @retval None
  */
// 启用USART1重映射：将USART1引脚映射到PB6(TX), PB7(RX)
#define __HAL_AFIO_REMAP_USART1_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_USART1_REMAP)

/**
  * @brief Disable the remapping of USART1 alternate function TX and RX.
  * @note  DISABLE: No remap (TX/PA9, RX/PA10)
  * @retval None
  */
// 禁用USART1重映射：恢复默认引脚PA9(TX), PA10(RX)
#define __HAL_AFIO_REMAP_USART1_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_USART1_REMAP)

/**
  * @brief Enable the remapping of USART2 alternate function CTS, RTS, CK, TX and RX.
  * @note  ENABLE: Remap     (CTS/PD3, RTS/PD4, TX/PD5, RX/PD6, CK/PD7)
  * @retval None
  */
// 启用USART2重映射：将USART2引脚映射到PD3(CTS), PD4(RTS), PD5(TX), PD6(RX), PD7(CK)
#define __HAL_AFIO_REMAP_USART2_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_USART2_REMAP)

/**
  * @brief Disable the remapping of USART2 alternate function CTS, RTS, CK, TX and RX.
  * @note  DISABLE: No remap (CTS/PA0, RTS/PA1, TX/PA2, RX/PA3, CK/PA4)
  * @retval None
  */
// 禁用USART2重映射：恢复默认引脚PA0(CTS), PA1(RTS), PA2(TX), PA3(RX), PA4(CK)
#define __HAL_AFIO_REMAP_USART2_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_USART2_REMAP)

/**
  * @brief Enable the remapping of USART3 alternate function CTS, RTS, CK, TX and RX.
  * @note  ENABLE: Full remap     (TX/PD8,  RX/PD9,  CK/PD10, CTS/PD11, RTS/PD12)
  * @retval None
  */
// 启用USART3完全重映射：将USART3引脚映射到PD8(TX), PD9(RX), PD10(CK), PD11(CTS), PD12(RTS)
#define __HAL_AFIO_REMAP_USART3_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_USART3_REMAP_FULLREMAP, AFIO_MAPR_USART3_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of USART3 alternate function CTS, RTS, CK, TX and RX.
  * @note  PARTIAL: Partial remap (TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14)
  * @retval None
  */
// 启用USART3部分重映射：将USART3引脚映射到PC10(TX), PC11(RX), PC12(CK), PB13(CTS), PB14(RTS)
#define __HAL_AFIO_REMAP_USART3_PARTIAL()  AFIO_REMAP_PARTIAL(AFIO_MAPR_USART3_REMAP_PARTIALREMAP, AFIO_MAPR_USART3_REMAP_FULLREMAP)

/**
  * @brief Disable the remapping of USART3 alternate function CTS, RTS, CK, TX and RX.
  * @note  DISABLE: No remap      (TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14)
  * @retval None
  */
// 禁用USART3重映射：恢复默认引脚PB10(TX), PB11(RX), PB12(CK), PB13(CTS), PB14(RTS)
#define __HAL_AFIO_REMAP_USART3_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_USART3_REMAP_NOREMAP, AFIO_MAPR_USART3_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM1 alternate function channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN)
  * @note  ENABLE: Full remap     (ETR/PE7,  CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8,  CH2N/PE10, CH3N/PE12)
  * @retval None
  */
// 启用TIM1完全重映射
#define __HAL_AFIO_REMAP_TIM1_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM1_REMAP_FULLREMAP, AFIO_MAPR_TIM1_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM1 alternate function channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN)
  * @note  PARTIAL: Partial remap (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PA6,  CH1N/PA7,  CH2N/PB0,  CH3N/PB1)
  * @retval None
  */
// 启用TIM1部分重映射
#define __HAL_AFIO_REMAP_TIM1_PARTIAL()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM1_REMAP_PARTIALREMAP, AFIO_MAPR_TIM1_REMAP_FULLREMAP)

/**
  * @brief Disable the remapping of TIM1 alternate function channels 1 to 4, 1N to 3N, external trigger (ETR) and Break input (BKIN)
  * @note  DISABLE: No remap      (ETR/PA12, CH1/PA8, CH2/PA9,  CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15)
  * @retval None
  */
// 禁用TIM1重映射
#define __HAL_AFIO_REMAP_TIM1_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM1_REMAP_NOREMAP, AFIO_MAPR_TIM1_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @note  ENABLE: Full remap       (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
  * @retval None
  */
// 启用TIM2完全重映射
#define __HAL_AFIO_REMAP_TIM2_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_FULLREMAP, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @note  PARTIAL_2: Partial remap (CH1/ETR/PA0,  CH2/PA1, CH3/PB10, CH4/PB11)
  * @retval None
  */
// 启用TIM2部分重映射2
#define __HAL_AFIO_REMAP_TIM2_PARTIAL_2()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @note  PARTIAL_1: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2,  CH4/PA3)
  * @retval None
  */
// 启用TIM2部分重映射1
#define __HAL_AFIO_REMAP_TIM2_PARTIAL_1()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief Disable the remapping of TIM2 alternate function channels 1 to 4 and external trigger (ETR)
  * @note  DISABLE: No remap        (CH1/ETR/PA0,  CH2/PA1, CH3/PA2,  CH4/PA3)
  * @retval None
  */
// 禁用TIM2重映射
#define __HAL_AFIO_REMAP_TIM2_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM2_REMAP_NOREMAP, AFIO_MAPR_TIM2_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM3 alternate function channels 1 to 4
  * @note  ENABLE: Full remap     (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
  * @note  TIM3_ETR on PE0 is not re-mapped.
  * @retval None
  */
// 启用TIM3完全重映射
#define __HAL_AFIO_REMAP_TIM3_ENABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM3_REMAP_FULLREMAP, AFIO_MAPR_TIM3_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM3 alternate function channels 1 to 4
  * @note  PARTIAL: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 is not re-mapped.
  * @retval None
  */
// 启用TIM3部分重映射
#define __HAL_AFIO_REMAP_TIM3_PARTIAL()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM3_REMAP_PARTIALREMAP, AFIO_MAPR_TIM3_REMAP_FULLREMAP)

/**
  * @brief Disable the remapping of TIM3 alternate function channels 1 to 4
  * @note  DISABLE: No remap      (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
  * @note  TIM3_ETR on PE0 is not re-mapped.
  * @retval None
  */
// 禁用TIM3重映射
#define __HAL_AFIO_REMAP_TIM3_DISABLE()  AFIO_REMAP_PARTIAL(AFIO_MAPR_TIM3_REMAP_NOREMAP, AFIO_MAPR_TIM3_REMAP_FULLREMAP)

/**
  * @brief Enable the remapping of TIM4 alternate function channels 1 to 4.
  * @note  ENABLE: Full remap (TIM4_CH1/PD12, TIM4_CH2/PD13, TIM4_CH3/PD14, TIM4_CH4/PD15)
  * @note  TIM4_ETR on PE0 is not re-mapped.
  * @retval None
  */
// 启用TIM4重映射
#define __HAL_AFIO_REMAP_TIM4_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_TIM4_REMAP)

/**
  * @brief Disable the remapping of TIM4 alternate function channels 1 to 4.
  * @note  DISABLE: No remap  (TIM4_CH1/PB6,  TIM4_CH2/PB7,  TIM4_CH3/PB8,  TIM4_CH4/PB9)
  * @note  TIM4_ETR on PE0 is not re-mapped.
  * @retval None
  */
// 禁用TIM4重映射
#define __HAL_AFIO_REMAP_TIM4_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM4_REMAP)

#if defined(AFIO_MAPR_CAN_REMAP_REMAP1)

/**
  * @brief Enable or disable the remapping of CAN alternate function CAN_RX and CAN_TX in devices with a single CAN interface.
  * @note  CASE 1: CAN_RX mapped to PA11, CAN_TX mapped to PA12
  * @retval None
  */
// CAN重映射配置1：CAN_RX映射到PA11，CAN_TX映射到PA12
#define __HAL_AFIO_REMAP_CAN1_1()  AFIO_REMAP_PARTIAL(AFIO_MAPR_CAN_REMAP_REMAP1, AFIO_MAPR_CAN_REMAP)

/**
  * @brief Enable or disable the remapping of CAN alternate function CAN_RX and CAN_TX in devices with a single CAN interface.
  * @note  CASE 2: CAN_RX mapped to PB8,  CAN_TX mapped to PB9 (not available on 36-pin package)
  * @retval None
  */
// CAN重映射配置2：CAN_RX映射到PB8，CAN_TX映射到PB9 (36引脚封装不可用)
#define __HAL_AFIO_REMAP_CAN1_2()  AFIO_REMAP_PARTIAL(AFIO_MAPR_CAN_REMAP_REMAP2, AFIO_MAPR_CAN_REMAP)

/**
  * @brief Enable or disable the remapping of CAN alternate function CAN_RX and CAN_TX in devices with a single CAN interface.
  * @note  CASE 3: CAN_RX mapped to PD0,  CAN_TX mapped to PD1
  * @retval None
  */
// CAN重映射配置3：CAN_RX映射到PD0，CAN_TX映射到PD1
#define __HAL_AFIO_REMAP_CAN1_3()  AFIO_REMAP_PARTIAL(AFIO_MAPR_CAN_REMAP_REMAP3, AFIO_MAPR_CAN_REMAP)

#endif

/**
  * @brief Enable the remapping of PD0 and PD1. When the HSE oscillator is not used
  *        (application running on internal 8 MHz RC) PD0 and PD1 can be mapped on OSC_IN and
  *        OSC_OUT. This is available only on 36, 48 and 64 pins packages (PD0 and PD1 are available
  *        on 100-pin and 144-pin packages, no need for remapping).
  * @note  ENABLE: PD0 remapped on OSC_IN, PD1 remapped on OSC_OUT.
  * @retval None
  */
// 启用PD0和PD1重映射：当不使用HSE时，PD0映射到OSC_IN，PD1映射到OSC_OUT
#define __HAL_AFIO_REMAP_PD01_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_PD01_REMAP)

/**
  * @brief Disable the remapping of PD0 and PD1. When the HSE oscillator is not used
  *        (application running on internal 8 MHz RC) PD0 and PD1 can be mapped on OSC_IN and
  *        OSC_OUT. This is available only on 36, 48 and 64 pins packages (PD0 and PD1 are available
  *        on 100-pin and 144-pin packages, no need for remapping).
  * @note  DISABLE: No remapping of PD0 and PD1
  * @retval None
  */
// 禁用PD0和PD1重映射
#define __HAL_AFIO_REMAP_PD01_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_PD01_REMAP)

#if defined(AFIO_MAPR_TIM5CH4_IREMAP)
/**
  * @brief Enable the remapping of TIM5CH4.
  * @note  ENABLE: LSI internal clock is connected to TIM5_CH4 input for calibration purpose.
  * @note  This function is available only in high density value line devices.
  * @retval None
  */
// 启用TIM5通道4重映射：LSI内部时钟连接到TIM5_CH4输入用于校准
#define __HAL_AFIO_REMAP_TIM5CH4_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_TIM5CH4_IREMAP)

/**
  * @brief Disable the remapping of TIM5CH4.
  * @note  DISABLE: TIM5_CH4 is connected to PA3
  * @note  This function is available only in high density value line devices.
  * @retval None
  */
// 禁用TIM5通道4重映射：TIM5_CH4连接到PA3
#define __HAL_AFIO_REMAP_TIM5CH4_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_TIM5CH4_IREMAP)
#endif

#if defined(AFIO_MAPR_ETH_REMAP)
/**
  * @brief Enable the remapping of Ethernet MAC connections with the PHY.
  * @note  ENABLE: Remap     (RX_DV-CRS_DV/PD8, RXD0/PD9, RXD1/PD10, RXD2/PD11, RXD3/PD12)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 启用以太网MAC接口重映射
#define __HAL_AFIO_REMAP_ETH_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ETH_REMAP)

/**
  * @brief Disable the remapping of Ethernet MAC connections with the PHY.
  * @note  DISABLE: No remap (RX_DV-CRS_DV/PA7, RXD0/PC4, RXD1/PC5,  RXD2/PB0,  RXD3/PB1)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 禁用以太网MAC接口重映射
#define __HAL_AFIO_REMAP_ETH_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ETH_REMAP)
#endif

#if defined(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief Enable the remapping of CAN2 alternate function CAN2_RX and CAN2_TX.
  * @note  ENABLE: Remap     (CAN2_RX/PB5,  CAN2_TX/PB6)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 启用CAN2重映射
#define __HAL_AFIO_REMAP_CAN2_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_CAN2_REMAP)

/**
  * @brief Disable the remapping of CAN2 alternate function CAN2_RX and CAN2_TX.
  * @note  DISABLE: No remap (CAN2_RX/PB12, CAN2_TX/PB13)
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 禁用CAN2重映射
#define __HAL_AFIO_REMAP_CAN2_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_CAN2_REMAP)
#endif

#if defined(AFIO_MAPR_MII_RMII_SEL)
/**
  * @brief Configures the Ethernet MAC internally for use with an external MII or RMII PHY.
  * @note  ETH_RMII: Configure Ethernet MAC for connection with an RMII PHY
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 配置以太网MAC为RMII模式
#define __HAL_AFIO_ETH_RMII() AFIO_REMAP_ENABLE(AFIO_MAPR_MII_RMII_SEL)

/**
  * @brief Configures the Ethernet MAC internally for use with an external MII or RMII PHY.
  * @note  ETH_MII: Configure Ethernet MAC for connection with an MII PHY
  * @note  This bit is available only in connectivity line devices and is reserved otherwise.
  * @retval None
  */
// 配置以太网MAC为MII模式
#define __HAL_AFIO_ETH_MII()  AFIO_REMAP_DISABLE(AFIO_MAPR_MII_RMII_SEL)
#endif

/**
  * @brief Enable the remapping of ADC1_ETRGINJ (ADC 1 External trigger injected conversion).
  * @note  ENABLE: ADC1 External Event injected conversion is connected to TIM8 Channel4.
  * @retval None
  */
// 启用ADC1外部触发注入转换重映射：连接到TIM8通道4
#define __HAL_AFIO_REMAP_ADC1_ETRGINJ_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC1_ETRGINJ_REMAP)

/**
  * @brief Disable the remapping of ADC1_ETRGINJ (ADC 1 External trigger injected conversion).
  * @note  DISABLE: ADC1 External trigger injected conversion is connected to EXTI15
  * @retval None
  */
// 禁用ADC1外部触发注入转换重映射：连接到EXTI15
#define __HAL_AFIO_REMAP_ADC1_ETRGINJ_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC1_ETRGINJ_REMAP)

/**
  * @brief Enable the remapping of ADC1_ETRGREG (ADC 1 External trigger regular conversion).
  * @note  ENABLE: ADC1 External Event regular conversion is connected to TIM8 TRG0.
  * @retval None
  */
// 启用ADC1外部触发常规转换重映射：连接到TIM8 TRG0
#define __HAL_AFIO_REMAP_ADC1_ETRGREG_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC1_ETRGREG_REMAP)

/**
  * @brief Disable the remapping of ADC1_ETRGREG (ADC 1 External trigger regular conversion).
  * @note  DISABLE: ADC1 External trigger regular conversion is connected to EXTI11
  * @retval None
  */
// 禁用ADC1外部触发常规转换重映射：连接到EXTI11
#define __HAL_AFIO_REMAP_ADC1_ETRGREG_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC1_ETRGREG_REMAP)

#if defined(AFIO_MAPR_ADC2_ETRGINJ_REMAP)

/**
  * @brief Enable the remapping of ADC2_ETRGREG (ADC 2 External trigger injected conversion).
  * @note  ENABLE: ADC2 External Event injected conversion is connected to TIM8 Channel4.
  * @retval None
  */
// 启用ADC2外部触发注入转换重映射：连接到TIM8通道4
#define __HAL_AFIO_REMAP_ADC2_ETRGINJ_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC2_ETRGINJ_REMAP)

/**
  * @brief Disable the remapping of ADC2_ETRGREG (ADC 2 External trigger injected conversion).
  * @note  DISABLE: ADC2 External trigger injected conversion is connected to EXTI15
  * @retval None
  */
// 禁用ADC2外部触发注入转换重映射：连接到EXTI15
#define __HAL_AFIO_REMAP_ADC2_ETRGINJ_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC2_ETRGINJ_REMAP)
#endif

#if defined (AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief Enable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @note  ENABLE: ADC2 External Event regular conversion is connected to TIM8 TRG0.
  * @retval None
  */
// 启用ADC2外部触发常规转换重映射：连接到TIM8 TRG0
#define __HAL_AFIO_REMAP_ADC2_ETRGREG_ENABLE()  AFIO_REMAP_ENABLE(AFIO_MAPR_ADC2_ETRGREG_REMAP)

/**
  * @brief Disable the remapping of ADC2_ETRGREG (ADC 2 External trigger regular conversion).
  * @note  DISABLE: ADC2 External trigger regular conversion is connected to EXTI11
  * @retval None
  */
// 禁用ADC2外部触发常规转换重映射：连接到EXTI11
#define __HAL_AFIO_REMAP_ADC2_ETRGREG_DISABLE() AFIO_REMAP_DISABLE(AFIO_MAPR_ADC2_ETRGREG_REMAP)
#endif

/**
  * @brief Enable the Serial wire JTAG configuration
  * @note  ENABLE: Full SWJ (JTAG-DP + SW-DP): Reset State
  * @retval None
  */
// 启用串行线JTAG配置：完全SWJ (JTAG-DP + SW-DP)，复位状态
#define __HAL_AFIO_REMAP_SWJ_ENABLE()  AFIO_DBGAFR_CONFIG(AFIO_MAPR_SWJ_CFG_RESET)
