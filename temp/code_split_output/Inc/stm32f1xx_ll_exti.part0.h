/**
  ******************************************************************************
  * @file    stm32f1xx_ll_exti.h
  * @author  MCD Application Team
  * @brief   EXTI LL模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录中的LICENSE文件中可以找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef STM32F1xx_LL_EXTI_H
#define STM32F1xx_LL_EXTI_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

#if defined (EXTI)

/** @defgroup EXTI_LL EXTI
  * @{
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/* 私有宏 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup EXTI_LL_Private_Macros EXTI 私有宏
  * @{
  */
/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/
/* 导出类型 ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup EXTI_LL_ES_INIT EXTI 导出初始化结构体
  * @{
  */
typedef struct
{
  /* 指定范围0到31的中断线是否使能 */
  uint32_t Line_0_31;           /*!< 指定范围0到31的EXTI线使能或禁用
                                     该参数可以是 @ref EXTI_LL_EC_LINE 的任意组合 */

  /* 指定所选EXTI线的新状态 */
  FunctionalState LineCommand;  /*!< 指定所选EXTI线的新状态。
                                     该参数可设置为 ENABLE 或 DISABLE */

  /* 指定EXTI线的模式 */
  uint8_t Mode;                 /*!< 指定EXTI线的模式。
                                     该参数可以是 @ref EXTI_LL_EC_MODE 的值 */

  /* 指定EXTI线的触发信号有效边沿 */
  uint8_t Trigger;              /*!< 指定EXTI线的触发信号有效边沿。
                                     该参数可以是 @ref EXTI_LL_EC_TRIGGER 的值 */
} LL_EXTI_InitTypeDef;

/**
  * @}
  */
#endif /*USE_FULL_LL_DRIVER*/

/* 导出常量 --------------------------------------------------------*/
/** @defgroup EXTI_LL_Exported_Constants EXTI 导出常量
  * @{
  */

/** @defgroup EXTI_LL_EC_LINE LINE
  * @{
  */
/* 定义EXTI线0到31的宏定义，对应中断屏蔽寄存器(IMR)的各位 */
#define LL_EXTI_LINE_0                 EXTI_IMR_IM0           /*!< 外部中断线 0 */
#define LL_EXTI_LINE_1                 EXTI_IMR_IM1           /*!< 外部中断线 1 */
#define LL_EXTI_LINE_2                 EXTI_IMR_IM2           /*!< 外部中断线 2 */
#define LL_EXTI_LINE_3                 EXTI_IMR_IM3           /*!< 外部中断线 3 */
#define LL_EXTI_LINE_4                 EXTI_IMR_IM4           /*!< 外部中断线 4 */
#define LL_EXTI_LINE_5                 EXTI_IMR_IM5           /*!< 外部中断线 5 */
#define LL_EXTI_LINE_6                 EXTI_IMR_IM6           /*!< 外部中断线 6 */
#define LL_EXTI_LINE_7                 EXTI_IMR_IM7           /*!< 外部中断线 7 */
#define LL_EXTI_LINE_8                 EXTI_IMR_IM8           /*!< 外部中断线 8 */
#define LL_EXTI_LINE_9                 EXTI_IMR_IM9           /*!< 外部中断线 9 */
#define LL_EXTI_LINE_10                EXTI_IMR_IM10          /*!< 外部中断线 10 */
#define LL_EXTI_LINE_11                EXTI_IMR_IM11          /*!< 外部中断线 11 */
#define LL_EXTI_LINE_12                EXTI_IMR_IM12          /*!< 外部中断线 12 */
#define LL_EXTI_LINE_13                EXTI_IMR_IM13          /*!< 外部中断线 13 */
#define LL_EXTI_LINE_14                EXTI_IMR_IM14          /*!< 外部中断线 14 */
#define LL_EXTI_LINE_15                EXTI_IMR_IM15          /*!< 外部中断线 15 */
#if defined(EXTI_IMR_IM16)
#define LL_EXTI_LINE_16                EXTI_IMR_IM16          /*!< 外部中断线 16 */
#endif
#define LL_EXTI_LINE_17                EXTI_IMR_IM17          /*!< 外部中断线 17 */
#if defined(EXTI_IMR_IM18)
#define LL_EXTI_LINE_18                EXTI_IMR_IM18          /*!< 外部中断线 18 */
#endif
#if defined(EXTI_IMR_IM19)
#define LL_EXTI_LINE_19                EXTI_IMR_IM19          /*!< 外部中断线 19 */
#endif
#if defined(EXTI_IMR_IM20)
#define LL_EXTI_LINE_20                EXTI_IMR_IM20          /*!< 外部中断线 20 */
#endif
#if defined(EXTI_IMR_IM21)
#define LL_EXTI_LINE_21                EXTI_IMR_IM21          /*!< 外部中断线 21 */
#endif
#if defined(EXTI_IMR_IM22)
#define LL_EXTI_LINE_22                EXTI_IMR_IM22          /*!< 外部中断线 22 */
#endif
#if defined(EXTI_IMR_IM23)
#define LL_EXTI_LINE_23                EXTI_IMR_IM23          /*!< 外部中断线 23 */
#endif
#if defined(EXTI_IMR_IM24)
#define LL_EXTI_LINE_24                EXTI_IMR_IM24          /*!< 外部中断线 24 */
#endif
#if defined(EXTI_IMR_IM25)
#define LL_EXTI_LINE_25                EXTI_IMR_IM25          /*!< 外部中断线 25 */
#endif
#if defined(EXTI_IMR_IM26)
#define LL_EXTI_LINE_26                EXTI_IMR_IM26          /*!< 外部中断线 26 */
#endif
#if defined(EXTI_IMR_IM27)
#define LL_EXTI_LINE_27                EXTI_IMR_IM27          /*!< 外部中断线 27 */
#endif
#if defined(EXTI_IMR_IM28)
#define LL_EXTI_LINE_28                EXTI_IMR_IM28          /*!< 外部中断线 28 */
#endif
#if defined(EXTI_IMR_IM29)
#define LL_EXTI_LINE_29                EXTI_IMR_IM29          /*!< 外部中断线 29 */
#endif
#if defined(EXTI_IMR_IM30)
#define LL_EXTI_LINE_30                EXTI_IMR_IM30          /*!< 外部中断线 30 */
#endif
#if defined(EXTI_IMR_IM31)
#define LL_EXTI_LINE_31                EXTI_IMR_IM31          /*!< 外部中断线 31 */
#endif
#define LL_EXTI_LINE_ALL_0_31          EXTI_IMR_IM            /*!< 所有非保留的外部中断线 */


#define LL_EXTI_LINE_ALL               (0xFFFFFFFFU)  /*!< 所有外部中断线 */

#if defined(USE_FULL_LL_DRIVER)
#define LL_EXTI_LINE_NONE              (0x00000000U)  /*!< 无外部中断线 */
#endif /*USE_FULL_LL_DRIVER*/

/**
  * @}
  */
#if defined(USE_FULL_LL_DRIVER)

/** @defgroup EXTI_LL_EC_MODE Mode
  * @{
  */
/* EXTI模式定义：中断模式、事件模式、中断与事件模式 */
#define LL_EXTI_MODE_IT                 ((uint8_t)0x00) /*!< 中断模式 */
#define LL_EXTI_MODE_EVENT              ((uint8_t)0x01) /*!< 事件模式 */
#define LL_EXTI_MODE_IT_EVENT           ((uint8_t)0x02) /*!< 中断和事件模式 */
/**
  * @}
  */

/** @defgroup EXTI_LL_EC_TRIGGER Edge Trigger
  * @{
  */
/* EXTI触发方式定义：无触发、上升沿、下降沿、双边沿 */
#define LL_EXTI_TRIGGER_NONE            ((uint8_t)0x00) /*!< 无触发模式 */
#define LL_EXTI_TRIGGER_RISING          ((uint8_t)0x01) /*!< 上升沿触发模式 */
#define LL_EXTI_TRIGGER_FALLING         ((uint8_t)0x02) /*!< 下降沿触发模式 */
#define LL_EXTI_TRIGGER_RISING_FALLING  ((uint8_t)0x03) /*!< 上升沿和下降沿触发模式 */

/**
  * @}
  */


#endif /*USE_FULL_LL_DRIVER*/


/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup EXTI_LL_Exported_Macros EXTI 导出宏
  * @{
  */

/** @defgroup EXTI_LL_EM_WRITE_READ 通用读写寄存器宏
  * @{
  */

/**
  * @brief  向EXTI寄存器写入值
  * @param  __REG__ 要写入的寄存器
  * @param  __VALUE__ 要写入寄存器的值
  * @retval 无
  */
#define LL_EXTI_WriteReg(__REG__, __VALUE__) WRITE_REG(EXTI->__REG__, (__VALUE__))

/**
  * @brief  读取EXTI寄存器中的值
  * @param  __REG__ 要读取的寄存器
  * @retval 寄存器值
  */
#define LL_EXTI_ReadReg(__REG__) READ_REG(EXTI->__REG__)
/**
  * @}
  */


/**
  * @}
  */



/* 导出函数 --------------------------------------------------------*/
/** @defgroup EXTI_LL_Exported_Functions EXTI 导出函数
 * @{
 */
/** @defgroup EXTI_LL_EF_IT_Management IT_Management 中断管理
  * @{
  */

/**
  * @brief  使能范围0到31的ExtiLine中断请求
  * @note 直接或内部线路的复位值（参见参考手册）默认设置为1，以便默认启用中断。
  *       上电时位自动置位。
  * @rmtoll IMR         IMx           LL_EXTI_EnableIT_0_31
  * @param  ExtiLine 此参数可以是以下值之一:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_17
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  *         @arg @ref LL_EXTI_LINE_ALL_0_31
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_EnableIT_0_31(uint32_t ExtiLine)
{
  /* 设置中断屏蔽寄存器(IMR)对应位，使能中断 */
  SET_BIT(EXTI->IMR, ExtiLine);
}

/**
  * @brief  禁用范围0到31的ExtiLine中断请求
  * @note 直接或内部线路的复位值（参见参考手册）默认设置为1，以便默认启用中断。
  *       上电时位自动置位。
  * @rmtoll IMR         IMx           LL_EXTI_DisableIT_0_31
  * @param  ExtiLine 此参数可以是以下值之一:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_17
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  *         @arg @ref LL_EXTI_LINE_ALL_0_31
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_DisableIT_0_31(uint32_t ExtiLine)
{
  /* 清除中断屏蔽寄存器(IMR)对应位，禁用中断 */
  CLEAR_BIT(EXTI->IMR, ExtiLine);
}


/**
  * @brief  指示范围0到31的ExtiLine中断请求是否使能
  * @note 直接或内部线路的复位值（参见参考手册）默认设置为1，以便默认启用中断。
  *       上电时位自动置位。
  * @rmtoll IMR         IMx           LL_EXTI_IsEnabledIT_0_31
  * @param  ExtiLine 此参数可以是以下值之一:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_17
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  *         @arg @ref LL_EXTI_LINE_ALL_0_31
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_EXTI_IsEnabledIT_0_31(uint32_t ExtiLine)
{
  /* 读取中断屏蔽寄存器(IMR)并判断对应位是否设置 */
  return (READ_BIT(EXTI->IMR, ExtiLine) == (ExtiLine));
}


/**
  * @}
  */

/** @defgroup EXTI_LL_EF_Event_Management Event_Management 事件管理
  * @{
  */

/**
  * @brief  使能范围0到31的ExtiLine事件请求
  * @rmtoll EMR         EMx           LL_EXTI_EnableEvent_0_31
  * @param  ExtiLine 此参数可以是以下值之一:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_17
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  *         @arg @ref LL_EXTI_LINE_ALL_0_31
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_EnableEvent_0_31(uint32_t ExtiLine)
{
  /* 设置事件屏蔽寄存器(EMR)对应位，使能事件 */
  SET_BIT(EXTI->EMR, ExtiLine);

}


/**
  * @brief  禁用范围0到31的ExtiLine事件请求
  * @rmtoll EMR         EMx           LL_EXTI_DisableEvent_0_31
  * @param  ExtiLine 此参数可以是以下值之一:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_17
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  *         @arg @ref LL_EXTI_LINE_ALL_0_31
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_DisableEvent_0_31(uint32_t ExtiLine)
{
  /* 清除事件屏蔽寄存器(EMR)对应位，禁用事件 */
  CLEAR_BIT(EXTI->EMR, ExtiLine);
}


/**
  * @brief  指示范围0到31的ExtiLine事件请求是否使能
  * @rmtoll EMR         EMx           LL_EXTI_IsEnabledEvent_0_31
  * @param  ExtiLine 此参数可以是以下值之一:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_17
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  *         @arg @ref LL_EXTI_LINE_ALL_0_31
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_EXTI_IsEnabledEvent_0_31(uint32_t ExtiLine)
{
  /* 读取事件屏蔽寄存器(EMR)并判断对应位是否设置 */
  return (READ_BIT(EXTI->EMR, ExtiLine) == (ExtiLine));

}


/**
  * @}
  */

/** @defgroup EXTI_LL_EF_Rising_Trigger_Management Rising_Trigger_Management 上升沿触发管理
  * @{
  */

/**
  * @brief  使能范围0到31的ExtiLine上升沿触发
  * @note 可配置的唤醒线是边沿触发的。这些线路上不得产生毛刺。
  *       如果在写入EXTI_RTSR寄存器期间可配置中断线上出现上升沿，则不会设置挂起位。
  *       可以为同一中断线设置上升沿和下降沿触发器。在这种情况下，两者都会产生触发条件。
  * @rmtoll RTSR        RTx           LL_EXTI_EnableRisingTrig_0_31
  * @param  ExtiLine 此参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_EnableRisingTrig_0_31(uint32_t ExtiLine)
{
  /* 设置上升沿触发选择寄存器(RTSR)对应位，使能上升沿触发 */
  SET_BIT(EXTI->RTSR, ExtiLine);

}


/**
  * @brief  禁用范围0到31的ExtiLine上升沿触发
  * @note 可配置的唤醒线是边沿触发的。这些线路上不得产生毛刺。
  *       如果在写入EXTI_RTSR寄存器期间可配置中断线上出现上升沿，则不会设置挂起位。
  *       可以为同一中断线设置上升沿和下降沿触发器。在这种情况下，两者都会产生触发条件。
  * @rmtoll RTSR        RTx           LL_EXTI_DisableRisingTrig_0_31
  * @param  ExtiLine 此参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_DisableRisingTrig_0_31(uint32_t ExtiLine)
{
  /* 清除上升沿触发选择寄存器(RTSR)对应位，禁用上升沿触发 */
  CLEAR_BIT(EXTI->RTSR, ExtiLine);

}

