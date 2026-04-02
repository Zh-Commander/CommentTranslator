/**
  ******************************************************************************
  * @file    stm32f1xx_hal_exti.c
  * @author  MCD Application Team
  * @brief   EXTI HAL模块驱动。
  *          本文件提供固件函数，用于管理外部中断和事件控制器(EXTI)外设的以下
  *          功能：
  *           + 初始化和反初始化函数
  *           + IO操作函数
  *
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2019 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录中的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                    ##### EXTI外设特性 #####
  ==============================================================================
  [..]
    (+) 每个Exti线都可以在此驱动程序中进行配置。

    (+) Exti线可以配置为3种不同的模式
        (++) 中断模式
        (++) 事件模式
        (++) 中断和事件模式

    (+) 可配置的Exti线可以配置3种不同的触发方式
        (++) 上升沿
        (++) 下降沿
        (++) 双边沿(上升沿和下降沿)

    (+) 当设置为中断模式时，可配置的Exti线有两个不同的中断挂起寄存器，
        允许区分发生了哪种转换：
        (++) 上升沿挂起中断
        (++) 下降沿挂起中断

    (+) Exti线0到15连接到gpio引脚号0到15。Gpio端口可以通过多路复用器选择。

                     ##### 如何使用本驱动 #####
  ==============================================================================
  [..]

    (#) 使用HAL_EXTI_SetConfigLine()配置EXTI线。
        (++) 通过设置EXTI_ConfigTypeDef结构中的"Line"成员来选择中断线号。
        (++) 通过EXTI_ConfigTypeDef结构中的"Mode"成员配置中断和/或事件模式。
        (++) 对于可配置线，通过EXTI_ConfigTypeDef结构中的"Trigger"成员配置
             上升沿和/或下降沿触发。
        (++) 对于连接到gpio的Exti线，使用GPIO_InitTypeDef结构中的"GPIOSel"
             成员选择gpio端口。

    (#) 使用HAL_EXTI_GetConfigLine()获取专用线的当前Exti配置。
        (++) 提供现有的句柄作为参数。
        (++) 提供指向EXTI_ConfigTypeDef结构的指针作为第二个参数。

    (#) 使用HAL_EXTI_ClearConfigLine()清除专用线的Exti配置。
        (++) 提供现有的句柄作为参数。

    (#) 使用HAL_EXTI_RegisterCallback()注册回调以处理Exti中断。
        (++) 提供现有的句柄作为第一个参数。
        (++) 使用EXTI_CallbackIDTypeDef中的一个值提供将要注册的回调。
        (++) 提供回调函数指针。

    (#) 使用HAL_EXTI_GetPending()获取中断挂起位。

    (#) 使用HAL_EXTI_ClearPending()清除中断挂起位。

    (#) 使用HAL_EXTI_GenerateSWI()生成软件中断。

  @endverbatim
  */

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup EXTI
  * @{
  */
/** MISRA C:2012 deviation rule has been granted for following rule:
  * Rule-18.1_b - Medium: Array `EXTICR' 1st subscript interval [0,7] may be out
  * of bounds [0,3] in following API :
  * HAL_EXTI_SetConfigLine
  * HAL_EXTI_GetConfigLine
  * HAL_EXTI_ClearConfigLine
  */

#ifdef HAL_EXTI_MODULE_ENABLED

/* 私有类型定义 -----------------------------------------------------------*/
/* 私有定义 -----------------------------------------------------------*/
/** @defgroup EXTI_Private_Constants EXTI私有常量
  * @{
  */

/**
  * @}
  */

/* 私有宏 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有函数原型 -------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/

/** @addtogroup EXTI_Exported_Functions
  * @{
  */

/** @addtogroup EXTI_Exported_Functions_Group1
  *  @brief    配置函数
  *
@verbatim
 ===============================================================================
              ##### 配置函数 #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  设置专用Exti线的配置。
  * @param  hexti Exti句柄指针。
  * @param  pExtiConfig 指向要设置的EXTI配置结构体的指针。
  * @retval HAL 状态值。
  */
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig)
{
  uint32_t regval;   // 用于临时存储寄存器值
  uint32_t linepos;  // 存储线号位置(0-18)
  uint32_t maskline; // 存储线号对应的掩码

  /* 检查空指针 */
  if ((hexti == NULL) || (pExtiConfig == NULL))
  {
    return HAL_ERROR;
  }

  /* 检查参数有效性 */
  assert_param(IS_EXTI_LINE(pExtiConfig->Line)); // 检查线号是否有效
  assert_param(IS_EXTI_MODE(pExtiConfig->Mode)); // 检查模式是否有效

  /* 将线号分配给句柄 */
  hexti->Line = pExtiConfig->Line;

  /* 计算线掩码 */
  linepos = (pExtiConfig->Line & EXTI_PIN_MASK); // 获取线号数值(低5位)
  maskline = (1uL << linepos); // 计算位掩码，例如线5对应 0x0020

  /* 为可配置线配置触发方式 */
  if ((pExtiConfig->Line & EXTI_CONFIG) != 0x00u)
  {
    assert_param(IS_EXTI_TRIGGER(pExtiConfig->Trigger)); // 检查触发方式参数

    /* 配置上升沿触发 */
    /* 根据配置设置或清除对应的位 */
    if ((pExtiConfig->Trigger & EXTI_TRIGGER_RISING) != 0x00u)
    {
      EXTI->RTSR |= maskline; // 设置上升沿触发选择寄存器对应位
    }
    else
    {
      EXTI->RTSR &= ~maskline; // 清除上升沿触发选择寄存器对应位
    }

    /* 配置下降沿触发 */
    /* 根据配置设置或清除对应的位 */
    if ((pExtiConfig->Trigger & EXTI_TRIGGER_FALLING) != 0x00u)
    {
      EXTI->FTSR |= maskline; // 设置下降沿触发选择寄存器对应位
    }
    else
    {
      EXTI->FTSR &= ~maskline; // 清除下降沿触发选择寄存器对应位
    }


    /* 在gpio exti线的情况下配置gpio端口选择 */
    if ((pExtiConfig->Line & EXTI_GPIO) == EXTI_GPIO)
    {
      assert_param(IS_EXTI_GPIO_PORT(pExtiConfig->GPIOSel)); // 检查GPIO端口参数
      assert_param(IS_EXTI_GPIO_PIN(linepos)); // 检查GPIO引脚参数
      
      /* 配置AFIO外部中断配置寄存器(EXTICR) */
      /* 计算寄存器索引：linepos / 4，因为每个EXTICR寄存器管理4个线 */
      regval = AFIO->EXTICR[linepos >> 2u];
      /* 清除对应位的旧配置 */
      regval &= ~(AFIO_EXTICR1_EXTI0 << (AFIO_EXTICR1_EXTI1_Pos * (linepos & 0x03u)));
      /* 设置新的GPIO端口选择 */
      regval |= (pExtiConfig->GPIOSel << (AFIO_EXTICR1_EXTI1_Pos * (linepos & 0x03u)));
      /* 写回寄存器 */
      AFIO->EXTICR[linepos >> 2u] = regval;
    }
  }

  /* 配置中断模式：读取当前模式 */
  /* 根据配置设置或清除对应的位 */
  if ((pExtiConfig->Mode & EXTI_MODE_INTERRUPT) != 0x00u)
  {
    EXTI->IMR |= maskline; // 设置中断屏蔽寄存器对应位，开启中断请求
  }
  else
  {
    EXTI->IMR &= ~maskline; // 清除中断屏蔽寄存器对应位，关闭中断请求
  }

  /* 配置事件模式：读取当前模式 */
  /* 根据配置设置或清除对应的位 */
  if ((pExtiConfig->Mode & EXTI_MODE_EVENT) != 0x00u)
  {
    EXTI->EMR |= maskline; // 设置事件屏蔽寄存器对应位，开启事件请求
  }
  else
  {
    EXTI->EMR &= ~maskline; // 清除事件屏蔽寄存器对应位，关闭事件请求
  }

  return HAL_OK;
}

/**
  * @brief  获取专用Exti线的配置。
  * @param  hexti Exti句柄指针。
  * @param  pExtiConfig 指向存储Exti配置的结构体指针。
  * @retval HAL 状态值。
  */
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig)
{
  uint32_t regval;   // 用于临时存储寄存器值
  uint32_t linepos;  // 存储线号位置
  uint32_t maskline; // 存储线号对应的掩码

  /* 检查空指针 */
  if ((hexti == NULL) || (pExtiConfig == NULL))
  {
    return HAL_ERROR;
  }

  /* 检查参数 */
  assert_param(IS_EXTI_LINE(hexti->Line));

  /* 将句柄线号存储到配置结构体 */
  pExtiConfig->Line = hexti->Line;

  /* 计算线掩码 */
  linepos = (pExtiConfig->Line & EXTI_PIN_MASK);
  maskline = (1uL << linepos);

  /* 1] 获取核心模式：中断 */

  /* 检查选定的线是否使能 */
  if ((EXTI->IMR & maskline) != 0x00u)
  {
    pExtiConfig->Mode = EXTI_MODE_INTERRUPT; // 如果IMR对应位置1，则为中断模式
  }
  else
  {
    pExtiConfig->Mode = EXTI_MODE_NONE; // 否则无模式
  }

  /* 获取事件模式 */
  /* 检查选定的线是否使能 */
  if ((EXTI->EMR & maskline) != 0x00u)
  {
    pExtiConfig->Mode |= EXTI_MODE_EVENT; // 如果EMR对应位置1，则或上事件模式
  }

  /* 获取默认触发和GPIOSel配置 */
  pExtiConfig->Trigger = EXTI_TRIGGER_NONE; // 默认无触发
  pExtiConfig->GPIOSel = 0x00u; // 默认GPIO选择为0

  /* 2] 获取可配置线的触发方式：上升沿 */
  if ((pExtiConfig->Line & EXTI_CONFIG) != 0x00u)
  {
    /* 检查选定线的配置是否使能 */
    if ((EXTI->RTSR & maskline) != 0x00u)
    {
      pExtiConfig->Trigger = EXTI_TRIGGER_RISING; // 如果RTSR对应位置1，则为上升沿触发
    }

    /* 获取下降沿配置 */
    /* 检查选定线的配置是否使能 */
    if ((EXTI->FTSR & maskline) != 0x00u)
    {
      pExtiConfig->Trigger |= EXTI_TRIGGER_FALLING; // 如果FTSR对应位置1，则或上下降沿触发
    }

    /* 获取gpio线的Gpio端口选择 */
    if ((pExtiConfig->Line & EXTI_GPIO) == EXTI_GPIO)
    {
      assert_param(IS_EXTI_GPIO_PIN(linepos));

      /* 读取AFIO外部中断配置寄存器 */
      regval = AFIO->EXTICR[linepos >> 2u];
      /* 提取对应的端口配置位 */
      pExtiConfig->GPIOSel = (regval >> (AFIO_EXTICR1_EXTI1_Pos * (linepos & 0x03u))) & AFIO_EXTICR1_EXTI0;
    }
  }

  return HAL_OK;
}

/**
  * @brief  清除专用Exti线的全部配置。
  * @param  hexti Exti句柄指针。
  * @retval HAL 状态值。
  */
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti)
{
  uint32_t regval;   // 用于临时存储寄存器值
  uint32_t linepos;  // 存储线号位置
  uint32_t maskline; // 存储线号对应的掩码

  /* 检查空指针 */
  if (hexti == NULL)
  {
    return HAL_ERROR;
  }

  /* 检查参数 */
  assert_param(IS_EXTI_LINE(hexti->Line));

  /* 计算线掩码 */
  linepos = (hexti->Line & EXTI_PIN_MASK);
  maskline = (1uL << linepos);

  /* 1] 清除中断模式 */
  EXTI->IMR = (EXTI->IMR & ~maskline); // 清除IMR对应位

  /* 2] 清除事件模式 */
  EXTI->EMR = (EXTI->EMR & ~maskline); // 清除EMR对应位

  /* 3] 在可配置线的情况下清除触发方式 */
  if ((hexti->Line & EXTI_CONFIG) != 0x00u)
  {
    EXTI->RTSR = (EXTI->RTSR & ~maskline); // 清除上升沿触发
    EXTI->FTSR = (EXTI->FTSR & ~maskline); // 清除下降沿触发

    /* 获取gpio线的Gpio端口选择 */
    if ((hexti->Line & EXTI_GPIO) == EXTI_GPIO)
    {
      assert_param(IS_EXTI_GPIO_PIN(linepos));

      /* 清除AFIO_EXTICR寄存器中的配置 */
      regval = AFIO->EXTICR[linepos >> 2u];
      regval &= ~(AFIO_EXTICR1_EXTI0 << (AFIO_EXTICR1_EXTI1_Pos * (linepos & 0x03u)));
      AFIO->EXTICR[linepos >> 2u] = regval;
    }
  }

  return HAL_OK;
}

/**
  * @brief  为专用Exti线注册回调函数。
  * @param  hexti Exti句柄指针。
  * @param  CallbackID 用户回调标识符。
  *         此参数可以是@arg @ref EXTI_CallbackIDTypeDef值之一。
  * @param  pPendingCbfn 要存储为回调的函数指针。
  * @retval HAL 状态值。
  */
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void))
{
  HAL_StatusTypeDef status = HAL_OK;

  switch (CallbackID)
  {
    case  HAL_EXTI_COMMON_CB_ID: // 通用回调ID
      hexti->PendingCallback = pPendingCbfn; // 注册回调函数
      break;

    default:
      status = HAL_ERROR; // 未知ID返回错误
      break;
  }

  return status;
}

/**
  * @brief  将线号存储为句柄私有字段。
  * @param  hexti Exti句柄指针。
  * @param  ExtiLine Exti线号。
  *         此参数可以从0到@ref EXTI_LINE_NB。
  * @retval HAL 状态值。
  */
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine)
{
  /* 检查参数 */
  assert_param(IS_EXTI_LINE(ExtiLine));

  /* 检查空指针 */
  if (hexti == NULL)
  {
    return HAL_ERROR;
  }
  else
  {
    /* 将线号存储为句柄私有字段 */
    hexti->Line = ExtiLine;

    return HAL_OK;
  }
}

/**
  * @}
  */

/** @addtogroup EXTI_Exported_Functions_Group2
  *  @brief EXTI IO函数。
  *
@verbatim
 ===============================================================================
                       ##### IO操作函数 #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
  * @brief  处理EXTI中断请求。
  * @param  hexti Exti句柄指针。
  * @retval 无。
  */
void HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti)
{
  uint32_t regval;  // 用于存储挂起寄存器状态
  uint32_t maskline; // 线掩码

  /* 计算线掩码 */
  maskline = (1uL << (hexti->Line & EXTI_PIN_MASK));

  /* 获取挂起位 */
  regval = (EXTI->PR & maskline); // 读取挂起寄存器(PR)
  if (regval != 0x00u) // 如果对应位不为0，说明发生了中断
  {
    /* 清除挂起位 */
    EXTI->PR = maskline; // 写1清除挂起位

    /* 调用回调函数 */
    if (hexti->PendingCallback != NULL) // 检查回调函数是否注册
    {
      hexti->PendingCallback(); // 执行用户定义的回调函数
    }
  }
}

/**
  * @brief  获取专用线的中断挂起位。
  * @param  hexti Exti句柄指针。
  * @param  Edge 指定要检查的挂起边沿。
  *         此参数可以是以下值之一：
  *           @arg @ref EXTI_TRIGGER_RISING_FALLING
  *         保留此参数是为了与其他系列兼容。
  * @retval 如果中断挂起则返回1，否则返回0。
  */
uint32_t HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge)
{
  uint32_t regval;
  uint32_t maskline;
  uint32_t linepos;

  /* 检查参数 */
  assert_param(IS_EXTI_LINE(hexti->Line));
  assert_param(IS_EXTI_CONFIG_LINE(hexti->Line));
  assert_param(IS_EXTI_PENDING_EDGE(Edge));

  /* 防止未使用的参数编译警告 */
  UNUSED(Edge);

  /* 计算线掩码 */
  linepos = (hexti->Line & EXTI_PIN_MASK);
  maskline = (1uL << linepos);

  /* 如果位置1则返回1，否则返回0 */
  regval = ((EXTI->PR & maskline) >> linepos); // 读取PR寄存器并移位到最低位
  return regval;
}

/**
  * @brief  清除专用线的中断挂起位。
  * @param  hexti Exti句柄指针。
  * @param  Edge 指定要清除的挂起边沿。
  *         此参数可以是以下值之一：
  *           @arg @ref EXTI_TRIGGER_RISING_FALLING
  *         保留此参数是为了与其他系列兼容。
  * @retval 无。
  */
void HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge)
{
  uint32_t maskline;

  /* 检查参数 */
  assert_param(IS_EXTI_LINE(hexti->Line));
  assert_param(IS_EXTI_CONFIG_LINE(hexti->Line));
  assert_param(IS_EXTI_PENDING_EDGE(Edge));

  /* 防止未使用的参数编译警告 */
  UNUSED(Edge);

  /* 计算线掩码 */
  maskline = (1uL << (hexti->Line & EXTI_PIN_MASK));

  /* 清除挂起位 */
  EXTI->PR =  maskline; // 写1清除挂起位
}

/**
  * @brief  为专用线生成软件中断。
  * @param  hexti Exti句柄指针。
  * @retval 无。
  */
void HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti)
{
  uint32_t maskline;

  /* 检查参数 */
  assert_param(IS_EXTI_LINE(hexti->Line));
  assert_param(IS_EXTI_CONFIG_LINE(hexti->Line));

  /* 计算线掩码 */
  maskline = (1uL << (hexti->Line & EXTI_PIN_MASK));

  /* 生成软件中断 */
  EXTI->SWIER = maskline; // 写入软件中断事件寄存器
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_EXTI_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

