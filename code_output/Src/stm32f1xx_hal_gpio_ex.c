/**
  ******************************************************************************
  * @file    stm32f1xx_hal_gpio_ex.c
  * @author  MCD Application Team
  * @brief   GPIO 扩展 HAL 模块驱动。
  *         本文件提供固件函数用于管理通用输入/输出 (GPIO) 扩展外设的以下
  *          功能。
  *           + 扩展功能函数
  *
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的 LICENSE 文件中找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                    ##### GPIO 外设扩展功能 #####
  ==============================================================================
  [..] STM32F1 系列上的 GPIO 模块，同时也管理 AFIO 寄存器：
       (+) 可以使用 Cortex 的 EVENTOUT 功能

                     ##### 如何使用本驱动 #####
  ==============================================================================
  [..] 本驱动提供使用 Cortex EVENTOUT 功能的函数
    (#) 使用函数 HAL_GPIOEx_ConfigEventout() 配置 EVENTOUT Cortex 功能
    (#) 使用 HAL_GPIOEx_EnableEventout() 激活 EVENTOUT Cortex 功能
    (#) 使用 HAL_GPIOEx_DisableEventout() 停用 EVENTOUT Cortex 功能

  @endverbatim
  ******************************************************************************
  */

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup GPIOEx GPIOEx
  * @brief GPIO HAL 模块驱动
  * @{
  */

#ifdef HAL_GPIO_MODULE_ENABLED

/** @defgroup GPIOEx_Exported_Functions GPIOEx 导出函数
  * @{
  */

/** @defgroup GPIOEx_Exported_Functions_Group1 扩展功能函数
 *  @brief    扩展功能函数
 *
@verbatim
  ==============================================================================
                 ##### 扩展功能函数 #####
  ==============================================================================
    [..]  本节提供允许执行以下操作的函数：
    (+) 使用函数 HAL_GPIOEx_ConfigEventout() 配置 EVENTOUT Cortex 功能
    (+) 使用 HAL_GPIOEx_EnableEventout() 激活 EVENTOUT Cortex 功能
    (+) 使用 HAL_GPIOEx_DisableEventout() 停用 EVENTOUT Cortex 功能

@endverbatim
  * @{
  */

/**
  * @brief  配置用于连接 Cortex EVENTOUT 信号的端口和引脚。
  * @param  GPIO_PortSource 选择用于输出 Cortex EVENTOUT 信号的端口。
  *   该参数可以是 @ref GPIOEx_EVENTOUT_PORT 中的一个值。
  * @param  GPIO_PinSource 选择用于输出 Cortex EVENTOUT 信号的引脚。
  *   该参数可以是 @ref GPIOEx_EVENTOUT_PIN 中的一个值。
  * @retval 无
  */
void HAL_GPIOEx_ConfigEventout(uint32_t GPIO_PortSource, uint32_t GPIO_PinSource)
{
  /* 检查参数有效性 */
  assert_param(IS_AFIO_EVENTOUT_PORT(GPIO_PortSource));
  assert_param(IS_AFIO_EVENTOUT_PIN(GPIO_PinSource));

  /* 应用新配置 */
  /* 修改 AFIO->EVCR 寄存器，配置事件输出端口和引脚 */
  /* AFIO_EVCR_PORT: 端口选择掩码 */
  /* AFIO_EVCR_PIN: 引脚选择掩码 */
  MODIFY_REG(AFIO->EVCR, (AFIO_EVCR_PORT) | (AFIO_EVCR_PIN), (GPIO_PortSource) | (GPIO_PinSource));
}

/**
  * @brief  使能事件输出功能。
  * @retval 无
  */
void HAL_GPIOEx_EnableEventout(void)
{
  /* 设置 AFIO->EVCR 寄存器中的 EVOE 位，使能事件输出 */
  SET_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @brief  禁用事件输出功能。
  * @retval 无
  */
void HAL_GPIOEx_DisableEventout(void)
{
  /* 清除 AFIO->EVCR 寄存器中的 EVOE 位，禁用事件输出 */
  CLEAR_BIT(AFIO->EVCR, AFIO_EVCR_EVOE);
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_GPIO_MODULE_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

