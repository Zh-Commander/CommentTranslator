/**
  ******************************************************************************
  * @file    stm32f1xx_ll_bus.h
  * @author  MCD Application Team
  * @brief   总线底层(LL)模块头文件。

  @verbatim
                      ##### RCC Limitations #####  RCC限制说明
  ==============================================================================
    [..]
      A delay between an RCC peripheral clock enable and the effective peripheral
      enabling should be taken into account in order to manage the peripheral read/write
      from/to registers.
      在使能RCC外设时钟和有效的外设使能之间存在延迟，在管理外设寄存器的读写操作时必须考虑到这一点。
      (+) This delay depends on the peripheral mapping.
        (++) AHB & APB peripherals, 1 dummy read is necessary
        该延迟取决于外设的映射位置。
          (++) 对于AHB和APB外设，需要进行1次虚拟读取操作。

    [..]
      Workarounds: 解决方案
      (#) For AHB & APB peripherals, a dummy read to the peripheral register has been
          inserted in each LL_{BUS}_GRP{x}_EnableClock() function.
          对于AHB和APB外设，在每个 LL_{BUS}_GRP{x}_EnableClock() 函数中，
          都插入了一条对外设寄存器的虚拟读取指令。

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_LL_BUS_H
#define __STM32F1xx_LL_BUS_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined(RCC)

/** @defgroup BUS_LL BUS
  * @brief 总线操作相关函数和定义
  * @{
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/

/* 私有常量 ---------------------------------------------------------*/
/* 检查是否支持AHB外设复位寄存器，部分型号支持OTGFS或ETHMAC复位 */
#if defined(RCC_AHBRSTR_OTGFSRST) || defined(RCC_AHBRSTR_ETHMACRST)
#define RCC_AHBRSTR_SUPPORT // 定义宏：支持AHB外设复位功能
#endif /* RCC_AHBRSTR_OTGFSRST || RCC_AHBRSTR_ETHMACRST */

/* 私有宏 ------------------------------------------------------------*/

/* 导出类型 ------------------------------------------------------------*/
/* 导出常量 --------------------------------------------------------*/
/** @defgroup BUS_LL_Exported_Constants BUS Exported Constants
  * @brief 总线导出常量定义
  * @{
  */

/** @defgroup BUS_LL_EC_AHB1_GRP1_PERIPH  AHB1 GRP1 PERIPH
  * @brief AHB1总线外设组1的宏定义，用于时钟控制
  * @{
  */
#define LL_AHB1_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU // 所有AHB1外设
#define LL_AHB1_GRP1_PERIPH_CRC            RCC_AHBENR_CRCEN      // CRC校验计算单元
#define LL_AHB1_GRP1_PERIPH_DMA1           RCC_AHBENR_DMA1EN     // DMA1直接存储器访问控制器1
#if defined(DMA2)
#define LL_AHB1_GRP1_PERIPH_DMA2           RCC_AHBENR_DMA2EN     // DMA2直接存储器访问控制器2
#endif /*DMA2*/
#if defined(ETH)
#define LL_AHB1_GRP1_PERIPH_ETHMAC         RCC_AHBENR_ETHMACEN   // 以太网MAC
#define LL_AHB1_GRP1_PERIPH_ETHMACRX       RCC_AHBENR_ETHMACRXEN // 以太网MAC接收
#define LL_AHB1_GRP1_PERIPH_ETHMACTX       RCC_AHBENR_ETHMACTXEN // 以太网MAC发送
#endif /*ETH*/
#define LL_AHB1_GRP1_PERIPH_FLASH          RCC_AHBENR_FLITFEN    // Flash存储器接口
#if defined(FSMC_Bank1)
#define LL_AHB1_GRP1_PERIPH_FSMC           RCC_AHBENR_FSMCEN     // 可变静态存储控制器
#endif /*FSMC_Bank1*/
#if defined(USB_OTG_FS)
#define LL_AHB1_GRP1_PERIPH_OTGFS          RCC_AHBENR_OTGFSEN    // USB OTG全速
#endif /*USB_OTG_FS*/
#if defined(SDIO)
#define LL_AHB1_GRP1_PERIPH_SDIO           RCC_AHBENR_SDIOEN     // SDIO接口
#endif /*SDIO*/
#define LL_AHB1_GRP1_PERIPH_SRAM           RCC_AHBENR_SRAMEN     // SRAM存储器
/**
  * @}
  */

/** @defgroup BUS_LL_EC_APB1_GRP1_PERIPH  APB1 GRP1 PERIPH
  * @brief APB1总线外设组1的宏定义，用于时钟控制
  * @{
  */
#define LL_APB1_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU // 所有APB1外设
#define LL_APB1_GRP1_PERIPH_BKP            RCC_APB1ENR_BKPEN     // 备份寄存器
#if defined(CAN1)
#define LL_APB1_GRP1_PERIPH_CAN1           RCC_APB1ENR_CAN1EN    // CAN1控制器
#endif /*CAN1*/
#if defined(CAN2)
#define LL_APB1_GRP1_PERIPH_CAN2           RCC_APB1ENR_CAN2EN    // CAN2控制器
#endif /*CAN2*/
#if defined(CEC)
#define LL_APB1_GRP1_PERIPH_CEC            RCC_APB1ENR_CECEN     // HDMI-CEC外设
#endif /*CEC*/
#if defined(DAC)
#define LL_APB1_GRP1_PERIPH_DAC1           RCC_APB1ENR_DACEN     // DAC数模转换器
#endif /*DAC*/
#define LL_APB1_GRP1_PERIPH_I2C1           RCC_APB1ENR_I2C1EN    // I2C1接口
#if defined(I2C2)
#define LL_APB1_GRP1_PERIPH_I2C2           RCC_APB1ENR_I2C2EN    // I2C2接口
#endif /*I2C2*/
#define LL_APB1_GRP1_PERIPH_PWR            RCC_APB1ENR_PWREN     // 电源接口
#if defined(SPI2)
#define LL_APB1_GRP1_PERIPH_SPI2           RCC_APB1ENR_SPI2EN    // SPI2接口
#endif /*SPI2*/
#if defined(SPI3)
#define LL_APB1_GRP1_PERIPH_SPI3           RCC_APB1ENR_SPI3EN    // SPI3接口
#endif /*SPI3*/
#if defined(TIM12)
#define LL_APB1_GRP1_PERIPH_TIM12          RCC_APB1ENR_TIM12EN   // 定时器12
#endif /*TIM12*/
#if defined(TIM13)
#define LL_APB1_GRP1_PERIPH_TIM13          RCC_APB1ENR_TIM13EN   // 定时器13
#endif /*TIM13*/
#if defined(TIM14)
#define LL_APB1_GRP1_PERIPH_TIM14          RCC_APB1ENR_TIM14EN   // 定时器14
#endif /*TIM14*/
#define LL_APB1_GRP1_PERIPH_TIM2           RCC_APB1ENR_TIM2EN    // 定时器2
#define LL_APB1_GRP1_PERIPH_TIM3           RCC_APB1ENR_TIM3EN    // 定时器3
#if defined(TIM4)
#define LL_APB1_GRP1_PERIPH_TIM4           RCC_APB1ENR_TIM4EN    // 定时器4
#endif /*TIM4*/
#if defined(TIM5)
#define LL_APB1_GRP1_PERIPH_TIM5           RCC_APB1ENR_TIM5EN    // 定时器5
#endif /*TIM5*/
#if defined(TIM6)
#define LL_APB1_GRP1_PERIPH_TIM6           RCC_APB1ENR_TIM6EN    // 定时器6
#endif /*TIM6*/
#if defined(TIM7)
#define LL_APB1_GRP1_PERIPH_TIM7           RCC_APB1ENR_TIM7EN    // 定时器7
#endif /*TIM7*/
#if defined(UART4)
#define LL_APB1_GRP1_PERIPH_UART4          RCC_APB1ENR_UART4EN   // UART4接口
#endif /*UART4*/
#if defined(UART5)
#define LL_APB1_GRP1_PERIPH_UART5          RCC_APB1ENR_UART5EN   // UART5接口
#endif /*UART5*/
#define LL_APB1_GRP1_PERIPH_USART2         RCC_APB1ENR_USART2EN  // USART2接口
#if defined(USART3)
#define LL_APB1_GRP1_PERIPH_USART3         RCC_APB1ENR_USART3EN  // USART3接口
#endif /*USART3*/
#if defined(USB)
#define LL_APB1_GRP1_PERIPH_USB            RCC_APB1ENR_USBEN     // USB设备
#endif /*USB*/
#define LL_APB1_GRP1_PERIPH_WWDG           RCC_APB1ENR_WWDGEN    // 窗口看门狗
/**
  * @}
  */

/** @defgroup BUS_LL_EC_APB2_GRP1_PERIPH  APB2 GRP1 PERIPH
  * @brief APB2总线外设组1的宏定义，用于时钟控制
  * @{
  */
#define LL_APB2_GRP1_PERIPH_ALL            (uint32_t)0xFFFFFFFFU // 所有APB2外设
#define LL_APB2_GRP1_PERIPH_ADC1           RCC_APB2ENR_ADC1EN    // ADC1模数转换器1
#if defined(ADC2)
#define LL_APB2_GRP1_PERIPH_ADC2           RCC_APB2ENR_ADC2EN    // ADC2模数转换器2
#endif /*ADC2*/
#if defined(ADC3)
#define LL_APB2_GRP1_PERIPH_ADC3           RCC_APB2ENR_ADC3EN    // ADC3模数转换器3
#endif /*ADC3*/
#define LL_APB2_GRP1_PERIPH_AFIO           RCC_APB2ENR_AFIOEN    // AFIO复用功能I/O
#define LL_APB2_GRP1_PERIPH_GPIOA          RCC_APB2ENR_IOPAEN    // GPIOA端口A
#define LL_APB2_GRP1_PERIPH_GPIOB          RCC_APB2ENR_IOPBEN    // GPIOB端口B
#define LL_APB2_GRP1_PERIPH_GPIOC          RCC_APB2ENR_IOPCEN    // GPIOC端口C
#define LL_APB2_GRP1_PERIPH_GPIOD          RCC_APB2ENR_IOPDEN    // GPIOD端口D
#if defined(GPIOE)
#define LL_APB2_GRP1_PERIPH_GPIOE          RCC_APB2ENR_IOPEEN    // GPIOE端口E
#endif /*GPIOE*/
#if defined(GPIOF)
#define LL_APB2_GRP1_PERIPH_GPIOF          RCC_APB2ENR_IOPFEN    // GPIOF端口F
#endif /*GPIOF*/
#if defined(GPIOG)
#define LL_APB2_GRP1_PERIPH_GPIOG          RCC_APB2ENR_IOPGEN    // GPIOG端口G
#endif /*GPIOG*/
#define LL_APB2_GRP1_PERIPH_SPI1           RCC_APB2ENR_SPI1EN    // SPI1接口
#if defined(TIM10)
#define LL_APB2_GRP1_PERIPH_TIM10          RCC_APB2ENR_TIM10EN   // 定时器10
#endif /*TIM10*/
#if defined(TIM11)
#define LL_APB2_GRP1_PERIPH_TIM11          RCC_APB2ENR_TIM11EN   // 定时器11
#endif /*TIM11*/
#if defined(TIM15)
#define LL_APB2_GRP1_PERIPH_TIM15          RCC_APB2ENR_TIM15EN   // 定时器15
#endif /*TIM15*/
#if defined(TIM16)
#define LL_APB2_GRP1_PERIPH_TIM16          RCC_APB2ENR_TIM16EN   // 定时器16
#endif /*TIM16*/
#if defined(TIM17)
#define LL_APB2_GRP1_PERIPH_TIM17          RCC_APB2ENR_TIM17EN   // 定时器17
#endif /*TIM17*/
#define LL_APB2_GRP1_PERIPH_TIM1           RCC_APB2ENR_TIM1EN    // 定时器1
#if defined(TIM8)
#define LL_APB2_GRP1_PERIPH_TIM8           RCC_APB2ENR_TIM8EN    // 定时器8
#endif /*TIM8*/
#if defined(TIM9)
#define LL_APB2_GRP1_PERIPH_TIM9           RCC_APB2ENR_TIM9EN    // 定时器9
#endif /*TIM9*/
#define LL_APB2_GRP1_PERIPH_USART1         RCC_APB2ENR_USART1EN  // USART1接口
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/

/* 导出函数 --------------------------------------------------------*/
/** @defgroup BUS_LL_Exported_Functions BUS Exported Functions
  * @brief 总线导出函数
  * @{
  */

/** @defgroup BUS_LL_EF_AHB1 AHB1
  * @brief AHB1总线相关操作函数
  * @{
  */

/**
  * @brief  Enable AHB1 peripherals clock.
  *         使能AHB1总线外设时钟。
  * @rmtoll AHBENR       CRCEN         LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       DMA1EN        LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       DMA2EN        LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       ETHMACEN      LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       ETHMACRXEN    LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       ETHMACTXEN    LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       FLITFEN       LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       FSMCEN        LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       OTGFSEN       LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       SDIOEN        LL_AHB1_GRP1_EnableClock\n
  *         AHBENR       SRAMEN        LL_AHB1_GRP1_EnableClock
  * @param  Periphs This parameter can be a combination of the following values:
  *         参数 Periphs 可以是以下值的组合:
  *         @arg @ref LL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref LL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref LL_AHB1_GRP1_PERIPH_DMA2 (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMAC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMACRX (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMACTX (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_FLASH
  *         @arg @ref LL_AHB1_GRP1_PERIPH_FSMC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_OTGFS (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_SDIO (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_SRAM
  *
  *         (*) value not defined in all devices. (*) 并非在所有设备中都定义。
  * @retval None 无返回值
*/
__STATIC_INLINE void LL_AHB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg; // 定义一个临时变量，用于产生延迟
  SET_BIT(RCC->AHBENR, Periphs); // 设置AHBENR寄存器中的对应位，使能外设时钟
  /* Delay after an RCC peripheral clock enabling */
  /* 在使能RCC外设时钟后增加延迟，确保时钟稳定 */
  tmpreg = READ_BIT(RCC->AHBENR, Periphs); // 读取刚设置的寄存器位，这是一个“虚拟读取”
  (void)tmpreg; // 防止编译器警告未使用的变量
}

/**
  * @brief  Check if AHB1 peripheral clock is enabled or not
  *         检查AHB1总线外设时钟是否已使能。
  * @rmtoll AHBENR       CRCEN         LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       DMA1EN        LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       DMA2EN        LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       ETHMACEN      LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       ETHMACRXEN    LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       ETHMACTXEN    LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       FLITFEN       LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       FSMCEN        LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       OTGFSEN       LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       SDIOEN        LL_AHB1_GRP1_IsEnabledClock\n
  *         AHBENR       SRAMEN        LL_AHB1_GRP1_IsEnabledClock
  * @param  Periphs This parameter can be a combination of the following values:
  *         参数 Periphs 可以是以下值的组合:
  *         @arg @ref LL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref LL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref LL_AHB1_GRP1_PERIPH_DMA2 (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMAC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMACRX (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMACTX (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_FLASH
  *         @arg @ref LL_AHB1_GRP1_PERIPH_FSMC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_OTGFS (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_SDIO (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_SRAM
  *
  *         (*) value not defined in all devices. (*) 并非在所有设备中都定义。
  * @retval State of Periphs (1 or 0). 返回外设状态 (1: 已使能, 0: 未使能)。
*/
__STATIC_INLINE uint32_t LL_AHB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  return (READ_BIT(RCC->AHBENR, Periphs) == Periphs); // 读取并判断寄存器位是否与参数匹配
}

/**
  * @brief  Disable AHB1 peripherals clock.
  *         关闭AHB1总线外设时钟。
  * @rmtoll AHBENR       CRCEN         LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       DMA1EN        LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       DMA2EN        LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       ETHMACEN      LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       ETHMACRXEN    LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       ETHMACTXEN    LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       FLITFEN       LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       FSMCEN        LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       OTGFSEN       LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       SDIOEN        LL_AHB1_GRP1_DisableClock\n
  *         AHBENR       SRAMEN        LL_AHB1_GRP1_DisableClock
  * @param  Periphs This parameter can be a combination of the following values:
  *         参数 Periphs 可以是以下值的组合:
  *         @arg @ref LL_AHB1_GRP1_PERIPH_CRC
  *         @arg @ref LL_AHB1_GRP1_PERIPH_DMA1
  *         @arg @ref LL_AHB1_GRP1_PERIPH_DMA2 (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMAC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMACRX (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMACTX (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_FLASH
  *         @arg @ref LL_AHB1_GRP1_PERIPH_FSMC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_OTGFS (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_SDIO (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_SRAM
  *
  *         (*) value not defined in all devices. (*) 并非在所有设备中都定义。
  * @retval None 无返回值
*/
__STATIC_INLINE void LL_AHB1_GRP1_DisableClock(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHBENR, Periphs); // 清除AHBENR寄存器中的对应位，关闭外设时钟
}

#if defined(RCC_AHBRSTR_SUPPORT)
/**
  * @brief  Force AHB1 peripherals reset.
  *         强制复位AHB1总线外设。
  * @rmtoll AHBRSTR      ETHMACRST     LL_AHB1_GRP1_ForceReset\n
  *         AHBRSTR      OTGFSRST      LL_AHB1_GRP1_ForceReset
  * @param  Periphs This parameter can be a combination of the following values:
  *         参数 Periphs 可以是以下值的组合:
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ALL
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMAC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_OTGFS (*)
  *
  *         (*) value not defined in all devices. (*) 并非在所有设备中都定义。
  * @retval None 无返回值
*/
__STATIC_INLINE void LL_AHB1_GRP1_ForceReset(uint32_t Periphs)
{
  SET_BIT(RCC->AHBRSTR, Periphs); // 设置AHBRSTR寄存器中的对应位，强制复位外设
}

/**
  * @brief  Release AHB1 peripherals reset.
  *         释放AHB1总线外设复位（解除复位状态）。
  * @rmtoll AHBRSTR      ETHMACRST     LL_AHB1_GRP1_ReleaseReset\n
  *         AHBRSTR      OTGFSRST      LL_AHB1_GRP1_ReleaseReset
  * @param  Periphs This parameter can be a combination of the following values:
  *         参数 Periphs 可以是以下值的组合:
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ALL
  *         @arg @ref LL_AHB1_GRP1_PERIPH_ETHMAC (*)
  *         @arg @ref LL_AHB1_GRP1_PERIPH_OTGFS (*)
  *
  *         (*) value not defined in all devices. (*) 并非在所有设备中都定义。
  * @retval None 无返回值
*/
__STATIC_INLINE void LL_AHB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  CLEAR_BIT(RCC->AHBRSTR, Periphs); // 清除AHBRSTR寄存器中的对应位，释放外设复位
}
#endif /* RCC_AHBRSTR_SUPPORT */

/**
  * @}
  */

/** @defgroup BUS_LL_EF_APB1 APB1
  * @brief APB1总线相关操作函数
  * @{
  */

/**
  * @brief  Enable APB1 peripherals clock.
  *         使能APB1总线外设时钟。
  * @rmtoll APB1ENR      BKPEN         LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      CAN1EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      CAN2EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      CECEN         LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      DACEN         LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      I2C1EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      I2C2EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      PWREN         LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      SPI2EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      SPI3EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM12EN       LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM13EN       LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM14EN       LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM2EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM3EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM4EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM5EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM6EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      TIM7EN        LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      UART4EN       LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      UART5EN       LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      USART2EN      LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      USART3EN      LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      USBEN         LL_APB1_GRP1_EnableClock\n
  *         APB1ENR      WWDGEN        LL_APB1_GRP1_EnableClock
  * @param  Periphs This parameter can be a combination of the following values:
  *         参数 Periphs 可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) value not defined in all devices. (*) 并非在所有设备中都定义。
  * @retval None 无返回值
*/
__STATIC_INLINE void LL_APB1_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg; // 定义一个临时变量，用于产生延迟
  SET_BIT(RCC->APB1ENR, Periphs); // 设置APB1ENR寄存器中的对应位，使能外设时钟
  /* Delay after an RCC peripheral clock enabling */
  /* 在使能RCC外设时钟后增加延迟，确保时钟稳定 */
  tmpreg = READ_BIT(RCC->APB1ENR, Periphs); // 读取刚设置的寄存器位，这是一个“虚拟读取”
  (void)tmpreg; // 防止编译器警告未使用的变量
}
/**
  * @brief  检查APB1外设时钟是否使能
  * @rmtoll APB1ENR      BKPEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      CAN1EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      CAN2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      CECEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      DACEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      I2C1EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      I2C2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      PWREN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      SPI2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      SPI3EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM12EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM13EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM14EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM2EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM3EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM4EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM5EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM6EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      TIM7EN        LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      UART4EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      UART5EN       LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      USART2EN      LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      USART3EN      LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      USBEN         LL_APB1_GRP1_IsEnabledClock\n
  *         APB1ENR      WWDGEN        LL_APB1_GRP1_IsEnabledClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 外设状态 (1 或 0).
*/
__STATIC_INLINE uint32_t LL_APB1_GRP1_IsEnabledClock(uint32_t Periphs)
{
  /* 读取RCC->APB1ENR寄存器，检查指定的外设时钟位是否置位 */
  return (READ_BIT(RCC->APB1ENR, Periphs) == Periphs);
}

/**
  * @brief  关闭APB1外设时钟。
  * @rmtoll APB1ENR      BKPEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      CAN1EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      CAN2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      CECEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      DACEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      I2C1EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      I2C2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      PWREN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      SPI2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      SPI3EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM12EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM13EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM14EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM2EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM3EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM4EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM5EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM6EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      TIM7EN        LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      UART4EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      UART5EN       LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      USART2EN      LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      USART3EN      LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      USBEN         LL_APB1_GRP1_DisableClock\n
  *         APB1ENR      WWDGEN        LL_APB1_GRP1_DisableClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 无
*/
__STATIC_INLINE void LL_APB1_GRP1_DisableClock(uint32_t Periphs)
{
  /* 清除RCC->APB1ENR寄存器中对应的外设时钟使能位，关闭时钟 */
  CLEAR_BIT(RCC->APB1ENR, Periphs);
}

/**
  * @brief  强制复位APB1外设。
  * @rmtoll APB1RSTR     BKPRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     CAN1RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     CAN2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     CECRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     DACRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     I2C1RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     I2C2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     PWRRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     SPI2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     SPI3RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM12RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM13RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM14RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM2RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM3RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM4RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM5RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM6RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     TIM7RST       LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     UART4RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     UART5RST      LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     USART2RST     LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     USART3RST     LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     USBRST        LL_APB1_GRP1_ForceReset\n
  *         APB1RSTR     WWDGRST       LL_APB1_GRP1_ForceReset
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 无
*/
__STATIC_INLINE void LL_APB1_GRP1_ForceReset(uint32_t Periphs)
{
  /* 置位RCC->APB1RSTR寄存器中的对应位，强制产生复位信号 */
  SET_BIT(RCC->APB1RSTR, Periphs);
}

/**
  * @brief  释放APB1外设复位。
  * @rmtoll APB1RSTR     BKPRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     CAN1RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     CAN2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     CECRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     DACRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     I2C1RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     I2C2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     PWRRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     SPI2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     SPI3RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM12RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM13RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM14RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM2RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM3RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM4RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM5RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM6RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     TIM7RST       LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     UART4RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     UART5RST      LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     USART2RST     LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     USART3RST     LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     USBRST        LL_APB1_GRP1_ReleaseReset\n
  *         APB1RSTR     WWDGRST       LL_APB1_GRP1_ReleaseReset
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB1_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB1_GRP1_PERIPH_BKP
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CAN2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_CEC (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_DAC1 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C1
  *         @arg @ref LL_APB1_GRP1_PERIPH_I2C2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_PWR
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI2 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_SPI3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM12 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM13 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM14 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM2
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM3
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM6 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_TIM7 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART4 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_UART5 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART2
  *         @arg @ref LL_APB1_GRP1_PERIPH_USART3 (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_USB (*)
  *         @arg @ref LL_APB1_GRP1_PERIPH_WWDG
  *
  *         (*) 并非在所有设备中都定义.
  * @retval 无
*/
__STATIC_INLINE void LL_APB1_GRP1_ReleaseReset(uint32_t Periphs)
{
  /* 清除RCC->APB1RSTR寄存器中的对应位，释放复位信号 */
  CLEAR_BIT(RCC->APB1RSTR, Periphs);
}

/**
  * @}
  */

/** @defgroup BUS_LL_EF_APB2 APB2
  * @{
  */

/**
  * @brief  使能APB2外设时钟。
  * @rmtoll APB2ENR      ADC1EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      ADC2EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      ADC3EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      AFIOEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPAEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPBEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPCEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPDEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPEEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPFEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      IOPGEN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      SPI1EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM10EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM11EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM15EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM16EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM17EN       LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM1EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM8EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      TIM9EN        LL_APB2_GRP1_EnableClock\n
  *         APB2ENR      USART1EN      LL_APB2_GRP1_EnableClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_EnableClock(uint32_t Periphs)
{
  __IO uint32_t tmpreg;
  /* 置位RCC->APB2ENR寄存器中的对应位，使能外设时钟 */
  SET_BIT(RCC->APB2ENR, Periphs);
  /* 在RCC外设时钟使能后增加延迟，确保时钟稳定 */
  tmpreg = READ_BIT(RCC->APB2ENR, Periphs);
  (void)tmpreg;
}

/**
  * @brief  检查APB2外设时钟是否使能
  * @rmtoll APB2ENR      ADC1EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      ADC2EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      ADC3EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      AFIOEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPAEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPBEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPCEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPDEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPEEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPFEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      IOPGEN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      SPI1EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM10EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM11EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM15EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM16EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM17EN       LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM1EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM8EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      TIM9EN        LL_APB2_GRP1_IsEnabledClock\n
  *         APB2ENR      USART1EN      LL_APB2_GRP1_IsEnabledClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) 并非在所有设备中都定义。
  * @retval 外设状态 (1 或 0)。
*/
__STATIC_INLINE uint32_t LL_APB2_GRP1_IsEnabledClock(uint32_t Periphs)
{
  /* 读取RCC->APB2ENR寄存器，检查指定的外设时钟位是否置位 */
  return (READ_BIT(RCC->APB2ENR, Periphs) == Periphs);
}

/**
  * @brief  关闭APB2外设时钟。
  * @rmtoll APB2ENR      ADC1EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      ADC2EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      ADC3EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      AFIOEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPAEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPBEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPCEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPDEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPEEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPFEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      IOPGEN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      SPI1EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM10EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM11EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM15EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM16EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM17EN       LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM1EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM8EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      TIM9EN        LL_APB2_GRP1_DisableClock\n
  *         APB2ENR      USART1EN      LL_APB2_GRP1_DisableClock
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_DisableClock(uint32_t Periphs)
{
  /* 清除RCC->APB2ENR寄存器中对应的外设时钟使能位，关闭时钟 */
  CLEAR_BIT(RCC->APB2ENR, Periphs);
}

/**
  * @brief  强制复位APB2外设。
  * @rmtoll APB2RSTR     ADC1RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     ADC2RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     ADC3RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     AFIORST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPARST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPBRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPCRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPDRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPERST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPFRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     IOPGRST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     SPI1RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM10RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM11RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM15RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM16RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM17RST      LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM1RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM8RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     TIM9RST       LL_APB2_GRP1_ForceReset\n
  *         APB2RSTR     USART1RST     LL_APB2_GRP1_ForceReset
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_ForceReset(uint32_t Periphs)
{
  /* 置位RCC->APB2RSTR寄存器中的对应位，强制产生复位信号 */
  SET_BIT(RCC->APB2RSTR, Periphs);
}

/**
  * @brief  释放APB2外设复位。
  * @rmtoll APB2RSTR     ADC1RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     ADC2RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     ADC3RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     AFIORST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPARST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPBRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPCRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPDRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPERST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPFRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     IOPGRST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     SPI1RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM10RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM11RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM15RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM16RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM17RST      LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM1RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM8RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     TIM9RST       LL_APB2_GRP1_ReleaseReset\n
  *         APB2RSTR     USART1RST     LL_APB2_GRP1_ReleaseReset
  * @param  Periphs 此参数可以是以下值的组合:
  *         @arg @ref LL_APB2_GRP1_PERIPH_ALL
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC1
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC2 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_ADC3 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_AFIO
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOA
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOB
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOC
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOD
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOE (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOF (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_GPIOG (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_SPI1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM10 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM11 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM15 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM16 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM17 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM1
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM8 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_TIM9 (*)
  *         @arg @ref LL_APB2_GRP1_PERIPH_USART1
  *
  *         (*) 并非在所有设备中都定义。
  * @retval 无
*/
__STATIC_INLINE void LL_APB2_GRP1_ReleaseReset(uint32_t Periphs)
{
  /* 清除RCC->APB2RSTR寄存器中的对应位，释放复位信号 */
  CLEAR_BIT(RCC->APB2RSTR, Periphs);
}

/**
  * @}
  */


/**
  * @}
  */

/**
  * @}
  */

#endif /* defined(RCC) */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F1xx_LL_BUS_H */
