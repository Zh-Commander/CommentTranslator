/**
  ******************************************************************************
  * @file    stm32f1xx_hal.c
  * @author  MCD Application Team
  * @brief   HAL模块驱动。
  *          这是HAL初始化的通用部分
  *
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
  @verbatim
  ==============================================================================
                     ##### 如何使用本驱动 #####
  ==============================================================================
    [..]
    通用HAL驱动包含一组通用API，可供PPP外设驱动和用户使用以开始使用HAL。
    [..]
    HAL包含两类API：
         (+) 通用HAL API
         (+) 服务HAL API

  @endverbatim
  ******************************************************************************
  */

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup HAL HAL
  * @brief HAL模块驱动。
  * @{
  */

#ifdef HAL_MODULE_ENABLED

/* 私有类型定义 -----------------------------------------------------------*/
/* 私有定义 ------------------------------------------------------------*/

/** @defgroup HAL_Private_Constants HAL 私有常量
  * @{
  */
/**
 * @brief STM32F1xx HAL驱动版本号
   */
#define __STM32F1xx_HAL_VERSION_MAIN   (0x01U) /*!< [31:24] 主版本号 */
#define __STM32F1xx_HAL_VERSION_SUB1   (0x01U) /*!< [23:16] 子版本1 */
#define __STM32F1xx_HAL_VERSION_SUB2   (0x0AU) /*!< [15:8]  子版本2 */
#define __STM32F1xx_HAL_VERSION_RC     (0x00U) /*!< [7:0]  发布候选版本 */
#define __STM32F1xx_HAL_VERSION         ((__STM32F1xx_HAL_VERSION_MAIN << 24)\
                                        |(__STM32F1xx_HAL_VERSION_SUB1 << 16)\
                                        |(__STM32F1xx_HAL_VERSION_SUB2 << 8 )\
                                        |(__STM32F1xx_HAL_VERSION_RC))
// 定义HAL库的版本号，通过移位和或运算组合成一个32位的版本数值

#define IDCODE_DEVID_MASK    0x00000FFFU
// 设备ID掩码，用于获取IDCODE寄存器中的设备ID部分

/**
  * @}
  */

/* 私有宏 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/

/** @defgroup HAL_Private_Variables HAL 私有变量
  * @{
  */
__IO uint32_t uwTick;
// 定义一个全局变量uwTick，用于记录系统滴答定时器的计数值（毫秒级），__IO表示volatile，防止编译器优化
uint32_t uwTickPrio   = (1UL << __NVIC_PRIO_BITS); /* 无效优先级，用于初始化 */
HAL_TickFreqTypeDef uwTickFreq = HAL_TICK_FREQ_DEFAULT;  /* 默认1KHz，即1ms中断一次 */
/**
  * @}
  */
/* 私有函数原型 -----------------------------------------------*/
/* 导出函数 ---------------------------------------------------------*/

/** @defgroup HAL_Exported_Functions HAL 导出函数
  * @{
  */

/** @defgroup HAL_Exported_Functions_Group1 初始化与反初始化函数
 *  @brief    初始化与反初始化函数
 *
@verbatim
 ===============================================================================
              ##### 初始化与反初始化函数 #####
 ===============================================================================
   [..]  本节提供以下功能：
      (+) 初始化Flash接口、NVIC分配和初始时钟配置。
          当需要超时功能时，它也会初始化SysTick，并在启用时初始化备份域。
      (+) 反初始化HAL的通用部分。
      (+) 配置时间基准源，使其具有1ms的时间基准和专用的滴答中断优先级。
        (++) 默认情况下使用SysTick定时器作为时间基准源，但用户最终可以
             实现自己的时间基准源（例如通用定时器或其他时间源），但要记住
             时间基准持续时间应保持1ms，因为PPP_TIMEOUT_VALUEs是基于毫秒定义和处理的。
        (++) 时间基准配置函数 (HAL_InitTick ()) 在程序开始时由 HAL_Init() 
             自动调用，或者在时钟配置时由 HAL_RCC_ClockConfig() 调用。
        (++) 时间基准源被配置为按固定的时间间隔产生中断。
             如果从外设ISR进程中调用 HAL_Delay()，必须注意滴答中断线必须具有
             比外设中断更高的优先级（数值上更小）。否则调用者ISR进程将被阻塞。
       (++) 影响时间基准配置的函数被声明为 __weak，以便在用户文件中
             进行其他实现时可以重写。
@endverbatim
  * @{
  */

/**
  * @brief  该函数用于初始化HAL库；它必须是主程序中执行的第一条指令
  *         （在调用任何其他HAL函数之前），它执行以下操作：
  *           配置Flash预取。
  *           配置SysTick以每1毫秒产生一次中断，
  *           此时由HSI提供时钟（在此阶段，时钟尚未配置，因此系统运行在内部HSI 16 MHz）。
  *           将NVIC组优先级设置为4。
  *           调用用户文件 "stm32f1xx_hal_msp.c" 中定义的 HAL_MspInit() 回调函数
  *           进行全局底层硬件初始化
  *
  * @note   SysTick用作 HAL_Delay() 函数的时间基准，应用程序
  *         需要确保SysTick时间基准始终设置为1毫秒，以保证HAL正常工作。
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_Init(void)
{
  /* 配置Flash预取 */
#if (PREFETCH_ENABLE != 0)
#if defined(STM32F101x6) || defined(STM32F101xB) || defined(STM32F101xE) || defined(STM32F101xG) || \
    defined(STM32F102x6) || defined(STM32F102xB) || \
    defined(STM32F103x6) || defined(STM32F103xB) || defined(STM32F103xE) || defined(STM32F103xG) || \
    defined(STM32F105xC) || defined(STM32F107xC)

  /* 预取缓冲区在Value line设备上不可用 */
  __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
#endif
#endif /* PREFETCH_ENABLE */

  /* 设置中断组优先级 */
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* 使用systick作为时间基准源并配置1ms滴答（复位后的默认时钟为HSI） */
  HAL_InitTick(TICK_INT_PRIORITY);

  /* 初始化底层硬件 */
  HAL_MspInit();

  /* 返回函数状态 */
  return HAL_OK;
}

/**
  * @brief 该函数反初始化HAL的通用部分并停止systick。
  *        时间基准。
  * @note 该函数是可选的。
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_DeInit(void)
{
  /* 复位所有外设 */
  __HAL_RCC_APB1_FORCE_RESET();
  __HAL_RCC_APB1_RELEASE_RESET();
  // 强制复位APB1总线外设，然后释放复位

  __HAL_RCC_APB2_FORCE_RESET();
  __HAL_RCC_APB2_RELEASE_RESET();
  // 强制复位APB2总线外设，然后释放复位

#if defined(STM32F105xC) || defined(STM32F107xC)
  __HAL_RCC_AHB_FORCE_RESET();
  __HAL_RCC_AHB_RELEASE_RESET();
  // 对于互联型设备，复位AHB总线外设
#endif

  /* 反初始化底层硬件 */
  HAL_MspDeInit();

  /* 返回函数状态 */
  return HAL_OK;
}

/**
  * @brief  初始化MSP（MCU支持包）。
  * @retval 无
  */
__weak void HAL_MspInit(void)
{
  /* 注意：此函数不应被修改，当需要回调时，
            HAL_MspInit 可以在用户文件中实现
   */
}

/**
  * @brief  反初始化MSP。
  * @retval 无
  */
__weak void HAL_MspDeInit(void)
{
  /* 注意：此函数不应被修改，当需要回调时，
            HAL_MspDeInit 可以在用户文件中实现
   */
}

/**
  * @brief 该函数配置时间基准源。
  *        时间源被配置为具有1ms的时间基准和专用的滴答中断优先级。
  * @note 该函数在程序开始复位后由 HAL_Init() 自动调用，
  *       或者在时钟由 HAL_RCC_ClockConfig() 重新配置时随时调用。
  * @note 在默认实现中，SysTick定时器是时间基准源。
  *       它用于按固定的时间间隔产生中断。
  *       如果从外设ISR进程中调用 HAL_Delay()，必须注意，
  *       SysTick中断必须具有比外设中断更高的优先级（数值上更小）。
  *       否则调用者ISR进程将被阻塞。
  *       该函数被声明为 __weak，以便在用户文件中进行其他实现时被重写。
  * @param TickPriority 滴答中断优先级。
  * @retval HAL状态
  */
__weak HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
{
  /* 配置SysTick以在1ms时间基准上产生中断 */
  if (HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq)) > 0U)
  {
    return HAL_ERROR;
  }
  // SystemCoreClock为系统时钟频率，除以(1000/频率)得到重装载值

  /* 配置SysTick中断优先级 */
  if (TickPriority < (1UL << __NVIC_PRIO_BITS))
  {
    HAL_NVIC_SetPriority(SysTick_IRQn, TickPriority, 0U);
    uwTickPrio = TickPriority;
    // 设置SysTick中断优先级并记录
  }
  else
  {
    return HAL_ERROR;
  }

  /* 返回函数状态 */
  return HAL_OK;
}

/**
  * @}
  */

/** @defgroup HAL_Exported_Functions_Group2 HAL 控制函数
  *  @brief    HAL 控制函数
  *
@verbatim
 ===============================================================================
                      ##### HAL 控制函数 #####
 ===============================================================================
    [..]  本节提供以下功能：
      (+) 提供毫秒级的滴答值
      (+) 提供毫秒级的阻塞延时
      (+) 挂起时间基准源中断
      (+) 恢复时间基准源中断
      (+) 获取HAL API驱动版本
      (+) 获取设备标识符
      (+) 获取设备版本标识符
      (+) 在睡眠模式下启用/禁用调试模块
      (+) 在停止模式下启用/禁用调试模块
      (+) 在待机模式下启用/禁用调试模块

@endverbatim
  * @{
  */

/**
  * @brief 该函数用于递增一个全局变量 "uwTick"，
  *        该变量用作应用程序时间基准。
  * @note 在默认实现中，此变量在SysTick ISR中每1ms递增一次。
  * @note 该函数被声明为 __weak，以便在用户文件中进行其他实现时被重写。
  * @retval 无
  */
__weak void HAL_IncTick(void)
{
  uwTick += uwTickFreq;
  // 全局滴答计数器增加，增加的值取决于滴答频率
}

/**
  * @brief 提供毫秒级的滴答值。
  * @note  该函数被声明为 __weak，以便在用户文件中进行其他实现时被重写。
  * @retval 滴答值
  */
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
  // 返回当前系统滴答计数值
}

/**
  * @brief 该函数返回滴答优先级。
  * @retval 滴答优先级
  */
uint32_t HAL_GetTickPrio(void)
{
  return uwTickPrio;
}

/**
  * @brief 设置新的滴答频率。
  * @retval 状态
  */
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq)
{
  HAL_StatusTypeDef status  = HAL_OK;
  HAL_TickFreqTypeDef prevTickFreq;

  assert_param(IS_TICKFREQ(Freq));
  // 检查频率参数是否有效

  if (uwTickFreq != Freq)
  {
    /* 备份 uwTickFreq 频率 */
    prevTickFreq = uwTickFreq;

    /* 更新 HAL_InitTick() 使用的 uwTickFreq 全局变量 */
    uwTickFreq = Freq;

    /* 应用新的滴答频率  */
    status = HAL_InitTick(uwTickPrio);
    // 重新配置SysTick以应用新频率

    if (status != HAL_OK)
    {
      /* 恢复之前的滴答频率 */
      uwTickFreq = prevTickFreq;
    }
  }

  return status;
}

/**
  * @brief 返回滴答频率。
  * @retval 滴答频率。
  *         值为 @ref HAL_TickFreqTypeDef。
  */
HAL_TickFreqTypeDef HAL_GetTickFreq(void)
{
  return uwTickFreq;
}

/**
  * @brief 该函数提供基于变量递增的最小延时（毫秒）。
  * @note 在默认实现中，SysTick定时器是时间基准源。
  *       它用于按固定的时间间隔产生中断，uwTick在其中递增。
  * @note 该函数被声明为 __weak，以便在用户文件中进行其他实现时被重写。
  * @param Delay 指定延时时间长度，单位为毫秒。
  * @retval 无
  */
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* 增加一个频率以保证最小等待时间 */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }
  // 如果延时不是无限大，则加上一次滴答的时间，补偿可能的剩余时间

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
  // 循环等待直到时间到达
}

/**
  * @brief 挂起滴答递增。
  * @note 在默认实现中，SysTick定时器是时间基准源。它用于
  *       按固定的时间间隔产生中断。一旦调用 HAL_SuspendTick()，
  *       SysTick中断将被禁用，因此滴答递增被挂起。
  * @note 该函数被声明为 __weak，以便在用户文件中进行其他实现时被重写。
  * @retval 无
  */
__weak void HAL_SuspendTick(void)
{
  /* 禁用SysTick中断 */
  CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief 恢复滴答递增。
  * @note 在默认实现中，SysTick定时器是时间基准源。它用于
  *       按固定的时间间隔产生中断。一旦调用 HAL_ResumeTick()，
  *       SysTick中断将被启用，因此滴答递增被恢复。
  * @note 该函数被声明为 __weak，以便在用户文件中进行其他实现时被重写。
  * @retval 无
  */
__weak void HAL_ResumeTick(void)
{
  /* 启用SysTick中断 */
  SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  返回HAL版本
  * @retval 版本号 0xXYZR (每个十进制数占8位, R代表RC)
  */
uint32_t HAL_GetHalVersion(void)
{
  return __STM32F1xx_HAL_VERSION;
}

/**
  * @brief 返回设备版本标识符。
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 设备版本标识符
  */
uint32_t HAL_GetREVID(void)
{
  return ((DBGMCU->IDCODE) >> DBGMCU_IDCODE_REV_ID_Pos);
  // 右移获取版本ID
}

/**
  * @brief  返回设备标识符。
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 设备标识符
  */
uint32_t HAL_GetDEVID(void)
{
  return ((DBGMCU->IDCODE) & IDCODE_DEVID_MASK);
  // 与掩码运算获取设备ID
}

/**
  * @brief  返回唯一设备标识符的第一个字（UID基于96位）
  * @retval 设备标识符
  */
uint32_t HAL_GetUIDw0(void)
{
   return(READ_REG(*((uint32_t *)UID_BASE)));
   // 读取UID基地址处的数据
}

/**
  * @brief  返回唯一设备标识符的第二个字（UID基于96位）
  * @retval 设备标识符
  */
uint32_t HAL_GetUIDw1(void)
{
   return(READ_REG(*((uint32_t *)(UID_BASE + 4U))));
   // 读取UID基地址偏移4字节处的数据
}

/**
  * @brief  返回唯一设备标识符的第三个字（UID基于96位）
  * @retval 设备标识符
  */
uint32_t HAL_GetUIDw2(void)
{
   return(READ_REG(*((uint32_t *)(UID_BASE + 8U))));
   // 读取UID基地址偏移8字节处的数据
}

/**
  * @brief  在睡眠模式下启用调试模块
  * @retval 无
  */
void HAL_DBGMCU_EnableDBGSleepMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
  // 设置DBGMCU控制寄存器的DBG_SLEEP位
}

/**
  * @brief  在睡眠模式下禁用调试模块
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 无
  */
void HAL_DBGMCU_DisableDBGSleepMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_SLEEP);
  // 清除DBGMCU控制寄存器的DBG_SLEEP位
}

/**
  * @brief  在停止模式下启用调试模块
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * 注意: 在所有STM32F1设备上：
  *       如果在停止模式调试期间启用了系统滴答定时器中断
  *       （DBGMCU_CR寄存器中的DBG_STOP位置位），它将唤醒
  *       系统从停止模式。
  *       解决方法：要调试停止模式，请禁用系统滴答定时器
  *       中断。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * 注意: 在所有STM32F1设备上：
  *       如果在停止模式调试期间启用了系统滴答定时器中断
  *       （DBGMCU_CR寄存器中的DBG_STOP位置位），它将唤醒
  *       系统从停止模式。
  *       解决方法：要调试停止模式，请禁用系统滴答定时器
  *       中断。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 无
  */
void HAL_DBGMCU_EnableDBGStopMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
  // 设置DBGMCU控制寄存器的DBG_STOP位
}

/**
  * @brief  在停止模式下禁用调试模块
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 无
  */
void HAL_DBGMCU_DisableDBGStopMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STOP);
  // 清除DBGMCU控制寄存器的DBG_STOP位
}

/**
  * @brief  在待机模式下启用调试模块
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 无
  */
void HAL_DBGMCU_EnableDBGStandbyMode(void)
{
  SET_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
  // 设置DBGMCU控制寄存器的DBG_STANDBY位
}

/**
  * @brief  在待机模式下禁用调试模块
  * 注意: 在设备 STM32F10xx8 和 STM32F10xxB,
  *                  STM32F101xC/D/E 和 STM32F103xC/D/E,
  *                  STM32F101xF/G 和 STM32F103xF/G
  *                  STM32F10xx4 和 STM32F10xx6 上
  *       调试寄存器 DBGMCU_IDCODE 和 DBGMCU_CR 仅在调试模式下可访问
  *       （在正常模式下用户软件无法访问）。
  *       有关更多详细信息，请参阅这些设备的勘误表。
  * @retval 无
  */
void HAL_DBGMCU_DisableDBGStandbyMode(void)
{
  CLEAR_BIT(DBGMCU->CR, DBGMCU_CR_DBG_STANDBY);
  // 清除DBGMCU控制寄存器的DBG_STANDBY位
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

