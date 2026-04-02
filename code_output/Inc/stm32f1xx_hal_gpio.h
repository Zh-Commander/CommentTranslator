/**
  ******************************************************************************
  * @file    stm32f1xx_hal_gpio.h
  * @author  MCD Application Team
  * @brief   GPIO HAL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录下的LICENSE文件中可以找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 防止递归包含 -----------------------------------------------------*/
#ifndef STM32F1xx_HAL_GPIO_H
#define STM32F1xx_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup GPIO
  * @{
  */

/* 导出类型 ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Types GPIO 导出类型
  * @{
  */

/**
  * @brief GPIO 初始化结构体定义
  * @note 该结构体用于配置GPIO引脚的基本参数，如引脚号、模式、上下拉和速度
  */
typedef struct
{
  uint32_t Pin;       /*!< 指定要配置的GPIO引脚。
                           该参数可以是 @ref GPIO_pins_define 中的任意值 */

  uint32_t Mode;      /*!< 指定所选引脚的操作模式。
                           该参数可以是 @ref GPIO_mode_define 中的值 */

  uint32_t Pull;      /*!< 指定所选引脚的上拉或下拉激活状态。
                           该参数可以是 @ref GPIO_pull_define 中的值 */

  uint32_t Speed;     /*!< 指定所选引脚的输出速度。
                           该参数可以是 @ref GPIO_speed_define 中的值 */
} GPIO_InitTypeDef;

/**
  * @brief  GPIO 引脚状态枚举定义（置位和复位）
  * @note 用于表示GPIO引脚的电平状态
  */
typedef enum
{
  GPIO_PIN_RESET = 0u, // 引脚复位状态（低电平）
  GPIO_PIN_SET         // 引脚置位状态（高电平）
} GPIO_PinState;
/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants GPIO 导出常量
  * @{
  */

/** @defgroup GPIO_pins_define GPIO 引脚定义
  * @{
  */
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* 选中引脚 0    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* 选中引脚 1    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* 选中引脚 2    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* 选中引脚 3    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* 选中引脚 4    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* 选中引脚 5    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* 选中引脚 6    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* 选中引脚 7    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* 选中引脚 8    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* 选中引脚 9    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* 选中引脚 10   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* 选中引脚 11   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* 选中引脚 12   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* 选中引脚 13   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* 选中引脚 14   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* 选中引脚 15   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* 选中所有引脚   */

#define GPIO_PIN_MASK              0x0000FFFFu /* 用于断言测试的引脚掩码 */
/**
  * @}
  */

/** @defgroup GPIO_mode_define GPIO 模式定义
  * @brief GPIO 配置模式
  *        元素值约定: 0xX0yz00YZ
  *           - X  : GPIO 模式或 EXTI 模式
  *           - y  : 外部中断或事件触发检测
  *           - z  : 外部中断或事件的 IO 配置
  *           - Y  : 输出类型 (推挽或开漏)
  *           - Z  : IO 方向模式 (输入, 输出, 复用或模拟)
  * @{
  */
#define  GPIO_MODE_INPUT                        0x00000000u   /*!< 输入浮空模式                   */
#define  GPIO_MODE_OUTPUT_PP                    0x00000001u   /*!< 输出推挽模式                 */
#define  GPIO_MODE_OUTPUT_OD                    0x00000011u   /*!< 输出开漏模式                */
#define  GPIO_MODE_AF_PP                        0x00000002u   /*!< 复用功能推挽模式     */
#define  GPIO_MODE_AF_OD                        0x00000012u   /*!< 复用功能开漏模式    */
#define  GPIO_MODE_AF_INPUT                     GPIO_MODE_INPUT          /*!< 复用功能输入模式         */

#define  GPIO_MODE_ANALOG                       0x00000003u   /*!< 模拟模式  */

#define  GPIO_MODE_IT_RISING                    0x10110000u   /*!< 带上升沿触发检测的外部中断模式          */
#define  GPIO_MODE_IT_FALLING                   0x10210000u   /*!< 带下降沿触发检测的外部中断模式         */
#define  GPIO_MODE_IT_RISING_FALLING            0x10310000u   /*!< 带上升/下降沿触发检测的外部中断模式  */

#define  GPIO_MODE_EVT_RISING                   0x10120000u   /*!< 带上升沿触发检测的外部事件模式               */
#define  GPIO_MODE_EVT_FALLING                  0x10220000u   /*!< 带下降沿触发检测的外部事件模式              */
#define  GPIO_MODE_EVT_RISING_FALLING           0x10320000u   /*!< 带上升/下降沿触发检测的外部事件模式       */

/**
  * @}
  */

/** @defgroup GPIO_speed_define  GPIO 速度定义
  * @brief GPIO 输出最大频率
  * @{
  */
#define  GPIO_SPEED_FREQ_LOW              (GPIO_CRL_MODE0_1) /*!< 低速 */
#define  GPIO_SPEED_FREQ_MEDIUM           (GPIO_CRL_MODE0_0) /*!< 中速 */
#define  GPIO_SPEED_FREQ_HIGH             (GPIO_CRL_MODE0)   /*!< 高速 */

/**
  * @}
  */

/** @defgroup GPIO_pull_define GPIO 上下拉定义
  * @brief GPIO 上拉或下拉激活
  * @{
  */
#define  GPIO_NOPULL        0x00000000u   /*!< 无上拉或下拉激活  */
#define  GPIO_PULLUP        0x00000001u   /*!< 上拉激活                  */
#define  GPIO_PULLDOWN      0x00000002u   /*!< 下拉激活                */
/**
  * @}
  */

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup GPIO_Exported_Macros GPIO 导出宏
  * @{
  */

/**
  * @brief  检查指定的EXTI线路标志位是否被置位。
  * @param  __EXTI_LINE__: 指定要检查的EXTI线路标志。
  *         该参数可以是 GPIO_PIN_x，其中 x 可以是(0..15)
  * @retval __EXTI_LINE__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_GPIO_EXTI_GET_FLAG(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

/**
  * @brief  清除EXTI线路的挂起标志。
  * @param  __EXTI_LINE__: 指定要清除的EXTI线路标志。
  *         该参数可以是 GPIO_PIN_x 的任意组合，其中 x 可以是 (0..15)
  * @retval 无
  */
#define __HAL_GPIO_EXTI_CLEAR_FLAG(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

/**
  * @brief  检查指定的EXTI线路是否被触发（中断挂起）。
  * @param  __EXTI_LINE__: 指定要检查的EXTI线路。
  *          该参数可以是 GPIO_PIN_x，其中 x 可以是(0..15)
  * @retval __EXTI_LINE__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_GPIO_EXTI_GET_IT(__EXTI_LINE__) (EXTI->PR & (__EXTI_LINE__))

/**
  * @brief  清除EXTI线路的挂起位（清除中断标志）。
  * @param  __EXTI_LINE__: 指定要清除的EXTI线路。
  *          该参数可以是 GPIO_PIN_x 的任意组合，其中 x 可以是 (0..15)
  * @retval 无
  */
#define __HAL_GPIO_EXTI_CLEAR_IT(__EXTI_LINE__) (EXTI->PR = (__EXTI_LINE__))

/**
  * @brief  在选定的EXTI线路上产生软件中断。
  * @param  __EXTI_LINE__: 指定要检查的EXTI线路。
  *          该参数可以是 GPIO_PIN_x，其中 x 可以是(0..15)
  * @retval 无
  */
#define __HAL_GPIO_EXTI_GENERATE_SWIT(__EXTI_LINE__) (EXTI->SWIER |= (__EXTI_LINE__))
/**
  * @}
  */

/* 包含 GPIO HAL 扩展模块 */
#include "stm32f1xx_hal_gpio_ex.h"

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup GPIO_Exported_Functions
  * @{
  */

/** @addtogroup GPIO_Exported_Functions_Group1
  * @{
  */
/* 初始化和反初始化函数 *****************************/
/**
  * @brief  初始化GPIO外设寄存器
  * @param  GPIOx: GPIO端口指针 (如GPIOA, GPIOB等)
  * @param  GPIO_Init: 指向GPIO_InitTypeDef结构体的指针，包含配置信息
  */
void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);

/**
  * @brief  将GPIO外设寄存器反初始化为默认复位值
  * @param  GPIOx: GPIO端口指针
  * @param  GPIO_Pin: 指定要反初始化的引脚
  */
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);
/**
  * @}
  */

/** @addtogroup GPIO_Exported_Functions_Group2
  * @{
  */
/* IO 操作函数 *****************************************************/
/**
  * @brief  读取指定的输入端口引脚状态
  * @param  GPIOx: GPIO端口指针
  * @param  GPIO_Pin: 指定要读取的引脚
  * @retval 返回引脚状态 (GPIO_PIN_SET 或 GPIO_PIN_RESET)
  */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
  * @brief  设置或清除选定的数据端口位
  * @param  GPIOx: GPIO端口指针
  * @param  GPIO_Pin: 指定要写入的引脚
  * @param  PinState: 指定要写入的值 (GPIO_PIN_RESET 或 GPIO_PIN_SET)
  */
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

/**
  * @brief  翻转指定的数据端口位
  * @param  GPIOx: GPIO端口指针
  * @param  GPIO_Pin: 指定要翻转的引脚
  */
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
  * @brief  锁定GPIO引脚配置寄存器
  * @param  GPIOx: GPIO端口指针
  * @param  GPIO_Pin: 指定要锁定的引脚
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/**
  * @brief  处理外部中断请求
  * @param  GPIO_Pin: 指定产生中断的引脚
  */
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);

/**
  * @brief  EXTI线路检测回调函数
  * @param  GPIO_Pin: 指定产生中断的引脚
  * @note   这是一个弱定义函数，用户应在自己的代码中重新实现它
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

/**
  * @}
  */

/**
  * @}
  */
/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Constants GPIO 私有常量
  * @{
  */

/**
  * @}
  */

/* 私有宏 ------------------------------------------------------------*/
/** @defgroup GPIO_Private_Macros GPIO 私有宏
  * @{
  */
/* 检查引脚动作参数是否有效 */
#define IS_GPIO_PIN_ACTION(ACTION) (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))

/* 检查引脚参数是否有效，确保至少选中了一个引脚且未超出范围 */
#define IS_GPIO_PIN(PIN)           (((((uint32_t)PIN) & GPIO_PIN_MASK ) != 0x00u) && ((((uint32_t)PIN) & ~GPIO_PIN_MASK) == 0x00u))

/* 检查模式参数是否有效 */
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
                            ((MODE) == GPIO_MODE_ANALOG))

/* 检查速度参数是否有效 */
#define IS_GPIO_SPEED(SPEED) (((SPEED) == GPIO_SPEED_FREQ_LOW) || \
                              ((SPEED) == GPIO_SPEED_FREQ_MEDIUM) || ((SPEED) == GPIO_SPEED_FREQ_HIGH))

/* 检查上下拉参数是否有效 */
#define IS_GPIO_PULL(PULL) (((PULL) == GPIO_NOPULL) || ((PULL) == GPIO_PULLUP) || \
                            ((PULL) == GPIO_PULLDOWN))
/**
  * @}
  */

/* 私有函数 ---------------------------------------------------------*/
/** @defgroup GPIO_Private_Functions GPIO 私有函数
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
