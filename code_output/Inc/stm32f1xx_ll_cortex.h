/**
  ******************************************************************************
  * @file    stm32f1xx_ll_cortex.h
  * @author  MCD Application Team
  * @brief   CORTEX LL 模块头文件。
  @verbatim
  ==============================================================================
                     ##### 如何使用本驱动 #####
  ==============================================================================
    [..]
    LL CORTEX 驱动包含一组通用 API，用户可以使用：
      (+) SYSTICK 配置，用于 LL_mDelay 和 LL_Init1msTick 函数
      (+) 低功耗模式配置 (Cortex-MCU 的 SCB 寄存器)
      (+) MPU API 用于配置和使能区域
          (MPU 服务仅在部分设备上提供)
      (+) 访问 MCU 信息的 API (CPUID 寄存器)
      (+) 使能故障处理程序的 API (SHCSR 访问)

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * 本软件根据本软件组件根目录中的 LICENSE 文件中找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 定义以防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_LL_CORTEX_H
#define __STM32F1xx_LL_CORTEX_H

#ifdef __cplusplus
extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx.h"

/** @addtogroup STM32F1xx_LL_Driver
  * @{
  */

/** @defgroup CORTEX_LL CORTEX
  * @{
  */

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/

/* 私有常量 ---------------------------------------------------------*/

/* 私有宏 ------------------------------------------------------------*/

/* 导出类型 ------------------------------------------------------------*/
/* 导出常量 --------------------------------------------------------*/
/** @defgroup CORTEX_LL_Exported_Constants CORTEX 导出常量
  * @{
  */

/** @defgroup CORTEX_LL_EC_CLKSOURCE_HCLK SYSTICK 时钟源
  * @{
  */
#define LL_SYSTICK_CLKSOURCE_HCLK_DIV8     0x00000000U                 /*!< AHB 时钟 8 分频作为 SysTick 时钟源 */
#define LL_SYSTICK_CLKSOURCE_HCLK          SysTick_CTRL_CLKSOURCE_Msk  /*!< AHB 时钟作为 SysTick 时钟源 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_FAULT 处理程序故障类型
  * @{
  */
#define LL_HANDLER_FAULT_USG               SCB_SHCSR_USGFAULTENA_Msk              /*!< 用法故障 */
#define LL_HANDLER_FAULT_BUS               SCB_SHCSR_BUSFAULTENA_Msk              /*!< 总线故障 */
#define LL_HANDLER_FAULT_MEM               SCB_SHCSR_MEMFAULTENA_Msk              /*!< 内存管理故障 */
/**
  * @}
  */

#if __MPU_PRESENT

/** @defgroup CORTEX_LL_EC_CTRL_HFNMI_PRIVDEF MPU 控制
  * @{
  */
#define LL_MPU_CTRL_HFNMI_PRIVDEF_NONE     0x00000000U                                       /*!< 禁用 NMI 和特权软件访问 */
#define LL_MPU_CTRL_HARDFAULT_NMI          MPU_CTRL_HFNMIENA_Msk                             /*!< 在硬故障、NMI 和 FAULTMASK 处理程序期间启用 MPU 操作 */
#define LL_MPU_CTRL_PRIVILEGED_DEFAULT     MPU_CTRL_PRIVDEFENA_Msk                           /*!< 启用特权软件访问默认内存映射 */
#define LL_MPU_CTRL_HFNMI_PRIVDEF          (MPU_CTRL_HFNMIENA_Msk | MPU_CTRL_PRIVDEFENA_Msk) /*!< 启用 NMI 和特权软件访问 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_REGION MPU 区域编号
  * @{
  */
#define LL_MPU_REGION_NUMBER0              0x00U /*!< 区域编号 0 */
#define LL_MPU_REGION_NUMBER1              0x01U /*!< 区域编号 1 */
#define LL_MPU_REGION_NUMBER2              0x02U /*!< 区域编号 2 */
#define LL_MPU_REGION_NUMBER3              0x03U /*!< 区域编号 3 */
#define LL_MPU_REGION_NUMBER4              0x04U /*!< 区域编号 4 */
#define LL_MPU_REGION_NUMBER5              0x05U /*!< 区域编号 5 */
#define LL_MPU_REGION_NUMBER6              0x06U /*!< 区域编号 6 */
#define LL_MPU_REGION_NUMBER7              0x07U /*!< 区域编号 7 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_REGION_SIZE MPU 区域大小
  * @{
  */
#define LL_MPU_REGION_SIZE_32B             (0x04U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 32B */
#define LL_MPU_REGION_SIZE_64B             (0x05U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 64B */
#define LL_MPU_REGION_SIZE_128B            (0x06U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 128B */
#define LL_MPU_REGION_SIZE_256B            (0x07U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 256B */
#define LL_MPU_REGION_SIZE_512B            (0x08U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 512B */
#define LL_MPU_REGION_SIZE_1KB             (0x09U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 1KB */
#define LL_MPU_REGION_SIZE_2KB             (0x0AU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 2KB */
#define LL_MPU_REGION_SIZE_4KB             (0x0BU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 4KB */
#define LL_MPU_REGION_SIZE_8KB             (0x0CU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 8KB */
#define LL_MPU_REGION_SIZE_16KB            (0x0DU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 16KB */
#define LL_MPU_REGION_SIZE_32KB            (0x0EU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 32KB */
#define LL_MPU_REGION_SIZE_64KB            (0x0FU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 64KB */
#define LL_MPU_REGION_SIZE_128KB           (0x10U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 128KB */
#define LL_MPU_REGION_SIZE_256KB           (0x11U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 256KB */
#define LL_MPU_REGION_SIZE_512KB           (0x12U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 512KB */
#define LL_MPU_REGION_SIZE_1MB             (0x13U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 1MB */
#define LL_MPU_REGION_SIZE_2MB             (0x14U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 2MB */
#define LL_MPU_REGION_SIZE_4MB             (0x15U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 4MB */
#define LL_MPU_REGION_SIZE_8MB             (0x16U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 8MB */
#define LL_MPU_REGION_SIZE_16MB            (0x17U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 16MB */
#define LL_MPU_REGION_SIZE_32MB            (0x18U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 32MB */
#define LL_MPU_REGION_SIZE_64MB            (0x19U << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 64MB */
#define LL_MPU_REGION_SIZE_128MB           (0x1AU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 128MB */
#define LL_MPU_REGION_SIZE_256MB           (0x1BU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 256MB */
#define LL_MPU_REGION_SIZE_512MB           (0x1CU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 512MB */
#define LL_MPU_REGION_SIZE_1GB             (0x1DU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 1GB */
#define LL_MPU_REGION_SIZE_2GB             (0x1EU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 2GB */
#define LL_MPU_REGION_SIZE_4GB             (0x1FU << MPU_RASR_SIZE_Pos) /*!< MPU 保护区域大小为 4GB */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_REGION_PRIVILEDGES MPU 区域权限
  * @{
  */
#define LL_MPU_REGION_NO_ACCESS            (0x00U << MPU_RASR_AP_Pos) /*!< 无访问权限 */
#define LL_MPU_REGION_PRIV_RW              (0x01U << MPU_RASR_AP_Pos) /*!< 特权读写 (仅特权访问) */
#define LL_MPU_REGION_PRIV_RW_URO          (0x02U << MPU_RASR_AP_Pos) /*!< 特权读写 - 用户只读 (用户程序写入会产生故障) */
#define LL_MPU_REGION_FULL_ACCESS          (0x03U << MPU_RASR_AP_Pos) /*!< 特权读写 & 用户读写 (完全访问) */
#define LL_MPU_REGION_PRIV_RO              (0x05U << MPU_RASR_AP_Pos) /*!< 特权只读 (仅特权只读) */
#define LL_MPU_REGION_PRIV_RO_URO          (0x06U << MPU_RASR_AP_Pos) /*!< 特权只读 & 用户只读 (只读) */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_TEX MPU TEX 级别
  * @{
  */
#define LL_MPU_TEX_LEVEL0                  (0x00U << MPU_RASR_TEX_Pos) /*!< TEX 位为 b000 */
#define LL_MPU_TEX_LEVEL1                  (0x01U << MPU_RASR_TEX_Pos) /*!< TEX 位为 b001 */
#define LL_MPU_TEX_LEVEL2                  (0x02U << MPU_RASR_TEX_Pos) /*!< TEX 位为 b010 */
#define LL_MPU_TEX_LEVEL4                  (0x04U << MPU_RASR_TEX_Pos) /*!< TEX 位为 b100 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_INSTRUCTION_ACCESS MPU 指令访问
  * @{
  */
#define LL_MPU_INSTRUCTION_ACCESS_ENABLE   0x00U            /*!< 启用指令取指 */
#define LL_MPU_INSTRUCTION_ACCESS_DISABLE  MPU_RASR_XN_Msk  /*!< 禁用指令取指 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_SHAREABLE_ACCESS MPU 可共享访问
  * @{
  */
#define LL_MPU_ACCESS_SHAREABLE            MPU_RASR_S_Msk   /*!< 可共享内存属性 */
#define LL_MPU_ACCESS_NOT_SHAREABLE        0x00U            /*!< 不可共享内存属性 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_CACHEABLE_ACCESS MPU 可缓存访问
  * @{
  */
#define LL_MPU_ACCESS_CACHEABLE            MPU_RASR_C_Msk   /*!< 可缓存内存属性 */
#define LL_MPU_ACCESS_NOT_CACHEABLE        0x00U            /*!< 不可缓存内存属性 */
/**
  * @}
  */

/** @defgroup CORTEX_LL_EC_BUFFERABLE_ACCESS MPU 可缓冲访问
  * @{
  */
#define LL_MPU_ACCESS_BUFFERABLE           MPU_RASR_B_Msk   /*!< 可缓冲内存属性 */
#define LL_MPU_ACCESS_NOT_BUFFERABLE       0x00U            /*!< 不可缓冲内存属性 */
/**
  * @}
  */
#endif /* __MPU_PRESENT */
/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/

/* 导出函数 --------------------------------------------------------*/
/** @defgroup CORTEX_LL_Exported_Functions CORTEX 导出函数
  * @{
  */

/** @defgroup CORTEX_LL_EF_SYSTICK SYSTICK
  * @{
  */

/**
  * @brief  检查 Systick 计数器标志是否处于活动状态。
  * @note   它可以在应用程序端的超时函数中使用。
  * @rmtoll STK_CTRL     COUNTFLAG     LL_SYSTICK_IsActiveCounterFlag
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_SYSTICK_IsActiveCounterFlag(void)
{
  /* 读取 SysTick 控制及状态寄存器，判断 COUNTFLAG 标志位是否置 1 */
  return ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == (SysTick_CTRL_COUNTFLAG_Msk));
}

/**
  * @brief  配置 SysTick 时钟源
  * @rmtoll STK_CTRL     CLKSOURCE     LL_SYSTICK_SetClkSource
  * @param  Source 此参数可以是以下值之一：
  *         @arg @ref LL_SYSTICK_CLKSOURCE_HCLK_DIV8
  *         @arg @ref LL_SYSTICK_CLKSOURCE_HCLK
  * @retval 无
  */
__STATIC_INLINE void LL_SYSTICK_SetClkSource(uint32_t Source)
{
  if (Source == LL_SYSTICK_CLKSOURCE_HCLK)
  {
    /* 如果选择 HCLK 作为时钟源，则置位 CLKSOURCE 位 */
    SET_BIT(SysTick->CTRL, LL_SYSTICK_CLKSOURCE_HCLK);
  }
  else
  {
    /* 否则，清零 CLKSOURCE 位，选择 HCLK/8 作为时钟源 */
    CLEAR_BIT(SysTick->CTRL, LL_SYSTICK_CLKSOURCE_HCLK);
  }
}

/**
  * @brief  获取 SysTick 时钟源
  * @rmtoll STK_CTRL     CLKSOURCE     LL_SYSTICK_GetClkSource
  * @retval 返回值可以是以下值之一：
  *         @arg @ref LL_SYSTICK_CLKSOURCE_HCLK_DIV8
  *         @arg @ref LL_SYSTICK_CLKSOURCE_HCLK
  */
__STATIC_INLINE uint32_t LL_SYSTICK_GetClkSource(void)
{
  /* 读取 SysTick 控制寄存器的 CLKSOURCE 位 */
  return READ_BIT(SysTick->CTRL, LL_SYSTICK_CLKSOURCE_HCLK);
}

/**
  * @brief  启用 SysTick 异常请求
  * @rmtoll STK_CTRL     TICKINT       LL_SYSTICK_EnableIT
  * @retval 无
  */
__STATIC_INLINE void LL_SYSTICK_EnableIT(void)
{
  /* 置位 TICKINT 位，使能 SysTick 中断 */
  SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  禁用 SysTick 异常请求
  * @rmtoll STK_CTRL     TICKINT       LL_SYSTICK_DisableIT
  * @retval 无
  */
__STATIC_INLINE void LL_SYSTICK_DisableIT(void)
{
  /* 清零 TICKINT 位，禁用 SysTick 中断 */
  CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
}

/**
  * @brief  检查 SYSTICK 中断是启用还是禁用。
  * @rmtoll STK_CTRL     TICKINT       LL_SYSTICK_IsEnabledIT
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_SYSTICK_IsEnabledIT(void)
{
  /* 读取 TICKINT 位状态 */
  return (READ_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk) == (SysTick_CTRL_TICKINT_Msk));
}

/**
  * @}
  */

/** @defgroup CORTEX_LL_EF_LOW_POWER_MODE LOW POWER MODE
  * @{
  */

/**
  * @brief  处理器使用睡眠作为其低功耗模式
  * @rmtoll SCB_SCR      SLEEPDEEP     LL_LPM_EnableSleep
  * @retval 无
  */
__STATIC_INLINE void LL_LPM_EnableSleep(void)
{
  /* 清除 Cortex 系统控制寄存器的 SLEEPDEEP 位，进入睡眠模式 */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @brief  处理器使用深度睡眠作为其低功耗模式
  * @rmtoll SCB_SCR      SLEEPDEEP     LL_LPM_EnableDeepSleep
  * @retval 无
  */
__STATIC_INLINE void LL_LPM_EnableDeepSleep(void)
{
  /* 设置 Cortex 系统控制寄存器的 SLEEPDEEP 位，进入深度睡眠模式 */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPDEEP_Msk));
}

/**
  * @brief  配置从处理程序模式返回线程模式时的退出时睡眠。
  * @note   将此位设置为 1 可以使中断驱动的应用程序避免返回到空的主应用程序。
  * @rmtoll SCB_SCR      SLEEPONEXIT   LL_LPM_EnableSleepOnExit
  * @retval 无
  */
__STATIC_INLINE void LL_LPM_EnableSleepOnExit(void)
{
  /* 设置 Cortex 系统控制寄存器的 SLEEPONEXIT 位 */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}

/**
  * @brief  返回线程模式时不睡眠。
  * @rmtoll SCB_SCR      SLEEPONEXIT   LL_LPM_DisableSleepOnExit
  * @retval 无
  */
__STATIC_INLINE void LL_LPM_DisableSleepOnExit(void)
{
  /* 清除 Cortex 系统控制寄存器的 SLEEPONEXIT 位 */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SLEEPONEXIT_Msk));
}

/**
  * @brief  启用事件和所有中断，包括被禁用的中断，都可以唤醒处理器。
  * @rmtoll SCB_SCR      SEVEONPEND    LL_LPM_EnableEventOnPend
  * @retval 无
  */
__STATIC_INLINE void LL_LPM_EnableEventOnPend(void)
{
  /* 设置 Cortex 系统控制寄存器的 SEVEONPEND 位 */
  SET_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}

/**
  * @brief  只有启用的中断或事件才能唤醒处理器，禁用的中断被排除
  * @rmtoll SCB_SCR      SEVEONPEND    LL_LPM_DisableEventOnPend
  * @retval 无
  */
__STATIC_INLINE void LL_LPM_DisableEventOnPend(void)
{
  /* 清除 Cortex 系统控制寄存器的 SEVEONPEND 位 */
  CLEAR_BIT(SCB->SCR, ((uint32_t)SCB_SCR_SEVONPEND_Msk));
}

/**
  * @}
  */

/** @defgroup CORTEX_LL_EF_HANDLER HANDLER
  * @{
  */

/**
  * @brief  在系统处理程序控制寄存器 (SHCSR) 中启用故障
  * @rmtoll SCB_SHCSR    MEMFAULTENA   LL_HANDLER_EnableFault
  * @param  Fault 此参数可以是以下值的组合：
  *         @arg @ref LL_HANDLER_FAULT_USG
  *         @arg @ref LL_HANDLER_FAULT_BUS
  *         @arg @ref LL_HANDLER_FAULT_MEM
  * @retval 无
  */
__STATIC_INLINE void LL_HANDLER_EnableFault(uint32_t Fault)
{
  /* 启用系统处理程序故障 */
  SET_BIT(SCB->SHCSR, Fault);
}

/**
  * @brief  在系统处理程序控制寄存器 (SHCSR) 中禁用故障
  * @rmtoll SCB_SHCSR    MEMFAULTENA   LL_HANDLER_DisableFault
  * @param  Fault 此参数可以是以下值的组合：
  *         @arg @ref LL_HANDLER_FAULT_USG
  *         @arg @ref LL_HANDLER_FAULT_BUS
  *         @arg @ref LL_HANDLER_FAULT_MEM
  * @retval 无
  */
__STATIC_INLINE void LL_HANDLER_DisableFault(uint32_t Fault)
{
  /* 禁用系统处理程序故障 */
  CLEAR_BIT(SCB->SHCSR, Fault);
}

/**
  * @}
  */

/** @defgroup CORTEX_LL_EF_MCU_INFO MCU INFO
  * @{
  */

/**
  * @brief  获取实现者代码
  * @rmtoll SCB_CPUID    IMPLEMENTER   LL_CPUID_GetImplementer
  * @retval 值对于 ARM 应等于 0x41
  */
__STATIC_INLINE uint32_t LL_CPUID_GetImplementer(void)
{
  /* 读取 CPUID 寄存器中的 IMPLEMENTER 字段 */
  return (uint32_t)(READ_BIT(SCB->CPUID, SCB_CPUID_IMPLEMENTER_Msk) >> SCB_CPUID_IMPLEMENTER_Pos);
}

/**
  * @brief  获取变体编号 (rnpn 产品修订标识符中的 r 值)
  * @rmtoll SCB_CPUID    VARIANT       LL_CPUID_GetVariant
  * @retval 介于 0 和 255 之间的值 (0x1: 修订版 1, 0x2: 修订版 2)
  */
__STATIC_INLINE uint32_t LL_CPUID_GetVariant(void)
{
  /* 读取 CPUID 寄存器中的 VARIANT 字段 */
  return (uint32_t)(READ_BIT(SCB->CPUID, SCB_CPUID_VARIANT_Msk) >> SCB_CPUID_VARIANT_Pos);
}

/**
  * @brief  获取常量编号
  * @rmtoll SCB_CPUID    ARCHITECTURE  LL_CPUID_GetConstant
  * @retval 值对于 Cortex-M3 设备应等于 0xF
  */
__STATIC_INLINE uint32_t LL_CPUID_GetConstant(void)
{
  /* 读取 CPUID 寄存器中的 ARCHITECTURE 字段 */
  return (uint32_t)(READ_BIT(SCB->CPUID, SCB_CPUID_ARCHITECTURE_Msk) >> SCB_CPUID_ARCHITECTURE_Pos);
}

/**
  * @brief  获取部件编号
  * @rmtoll SCB_CPUID    PARTNO        LL_CPUID_GetParNo
  * @retval 值对于 Cortex-M3 应等于 0xC23
  */
__STATIC_INLINE uint32_t LL_CPUID_GetParNo(void)
{
  /* 读取 CPUID 寄存器中的 PARTNO 字段 */
  return (uint32_t)(READ_BIT(SCB->CPUID, SCB_CPUID_PARTNO_Msk) >> SCB_CPUID_PARTNO_Pos);
}

/**
  * @brief  获取修订编号 (rnpn 产品修订标识符中的 p 值，指示补丁发布)
  * @rmtoll SCB_CPUID    REVISION      LL_CPUID_GetRevision
  * @retval 介于 0 和 255 之间的值 (0x0: 补丁 0, 0x1: 补丁 1)
  */
__STATIC_INLINE uint32_t LL_CPUID_GetRevision(void)
{
  /* 读取 CPUID 寄存器中的 REVISION 字段 */
  return (uint32_t)(READ_BIT(SCB->CPUID, SCB_CPUID_REVISION_Msk) >> SCB_CPUID_REVISION_Pos);
}

/**
  * @}
  */

#if __MPU_PRESENT
/** @defgroup CORTEX_LL_EF_MPU MPU
  * @{
  */

/**
  * @brief  使用输入选项启用 MPU
  * @rmtoll MPU_CTRL     ENABLE        LL_MPU_Enable
  * @param  Options 此参数可以是以下值之一：
  *         @arg @ref LL_MPU_CTRL_HFNMI_PRIVDEF_NONE
  *         @arg @ref LL_MPU_CTRL_HARDFAULT_NMI
  *         @arg @ref LL_MPU_CTRL_PRIVILEGED_DEFAULT
  *         @arg @ref LL_MPU_CTRL_HFNMI_PRIVDEF
  * @retval 无
  */
__STATIC_INLINE void LL_MPU_Enable(uint32_t Options)
{
  /* 启用 MPU */
  WRITE_REG(MPU->CTRL, (MPU_CTRL_ENABLE_Msk | Options));
  /* 确保 MPU 设置生效 */
  __DSB();
  /* 使用更新设置进行指令同步 */
  __ISB();
}

/**
  * @brief  禁用 MPU
  * @rmtoll MPU_CTRL     ENABLE        LL_MPU_Disable
  * @retval 无
  */
__STATIC_INLINE void LL_MPU_Disable(void)
{
  /* 确保未完成的传输完成 */
  __DMB();
  /* 禁用 MPU */
  WRITE_REG(MPU->CTRL, 0U);
}

/**
  * @brief  检查 MPU 是否启用
  * @rmtoll MPU_CTRL     ENABLE        LL_MPU_IsEnabled
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_MPU_IsEnabled(void)
{
  /* 读取 MPU 控制寄存器的 ENABLE 位 */
  return (READ_BIT(MPU->CTRL, MPU_CTRL_ENABLE_Msk) == (MPU_CTRL_ENABLE_Msk));
}

/**
  * @brief  启用 MPU 区域
  * @rmtoll MPU_RASR     ENABLE        LL_MPU_EnableRegion
  * @param  Region 此参数可以是以下值之一：
  *         @arg @ref LL_MPU_REGION_NUMBER0
  *         @arg @ref LL_MPU_REGION_NUMBER1
  *         @arg @ref LL_MPU_REGION_NUMBER2
  *         @arg @ref LL_MPU_REGION_NUMBER3
  *         @arg @ref LL_MPU_REGION_NUMBER4
  *         @arg @ref LL_MPU_REGION_NUMBER5
  *         @arg @ref LL_MPU_REGION_NUMBER6
  *         @arg @ref LL_MPU_REGION_NUMBER7
  * @retval 无
  */
__STATIC_INLINE void LL_MPU_EnableRegion(uint32_t Region)
{
  /* 设置区域编号 */
  WRITE_REG(MPU->RNR, Region);
  /* 启用 MPU 区域 */
  SET_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

/**
  * @brief  配置并启用区域
  * @rmtoll MPU_RNR      REGION        LL_MPU_ConfigRegion\n
  *         MPU_RBAR     REGION        LL_MPU_ConfigRegion\n
  *         MPU_RBAR     ADDR          LL_MPU_ConfigRegion\n
  *         MPU_RASR     XN            LL_MPU_ConfigRegion\n
  *         MPU_RASR     AP            LL_MPU_ConfigRegion\n
  *         MPU_RASR     S             LL_MPU_ConfigRegion\n
  *         MPU_RASR     C             LL_MPU_ConfigRegion\n
  *         MPU_RASR     B             LL_MPU_ConfigRegion\n
  *         MPU_RASR     SIZE          LL_MPU_ConfigRegion
  * @param  Region 此参数可以是以下值之一：
  *         @arg @ref LL_MPU_REGION_NUMBER0
  *         @arg @ref LL_MPU_REGION_NUMBER1
  *         @arg @ref LL_MPU_REGION_NUMBER2
  *         @arg @ref LL_MPU_REGION_NUMBER3
  *         @arg @ref LL_MPU_REGION_NUMBER4
  *         @arg @ref LL_MPU_REGION_NUMBER5
  *         @arg @ref LL_MPU_REGION_NUMBER6
  *         @arg @ref LL_MPU_REGION_NUMBER7
  * @param  Address 区域基地址值
  * @param  SubRegionDisable 子区域禁用值，范围 Min_Data = 0x00 到 Max_Data = 0xFF
  * @param  Attributes 此参数可以是以下值的组合：
  *         @arg @ref LL_MPU_REGION_SIZE_32B or @ref LL_MPU_REGION_SIZE_64B or @ref LL_MPU_REGION_SIZE_128B or @ref LL_MPU_REGION_SIZE_256B or @ref LL_MPU_REGION_SIZE_512B
  *           or @ref LL_MPU_REGION_SIZE_1KB or @ref LL_MPU_REGION_SIZE_2KB or @ref LL_MPU_REGION_SIZE_4KB or @ref LL_MPU_REGION_SIZE_8KB or @ref LL_MPU_REGION_SIZE_16KB
  *           or @ref LL_MPU_REGION_SIZE_32KB or @ref LL_MPU_REGION_SIZE_64KB or @ref LL_MPU_REGION_SIZE_128KB or @ref LL_MPU_REGION_SIZE_256KB or @ref LL_MPU_REGION_SIZE_512KB
  *           or @ref LL_MPU_REGION_SIZE_1MB or @ref LL_MPU_REGION_SIZE_2MB or @ref LL_MPU_REGION_SIZE_4MB or @ref LL_MPU_REGION_SIZE_8MB or @ref LL_MPU_REGION_SIZE_16MB
  *           or @ref LL_MPU_REGION_SIZE_32MB or @ref LL_MPU_REGION_SIZE_64MB or @ref LL_MPU_REGION_SIZE_128MB or @ref LL_MPU_REGION_SIZE_256MB or @ref LL_MPU_REGION_SIZE_512MB
  *           or @ref LL_MPU_REGION_SIZE_1GB or @ref LL_MPU_REGION_SIZE_2GB or @ref LL_MPU_REGION_SIZE_4GB
  *         @arg @ref LL_MPU_REGION_NO_ACCESS or @ref LL_MPU_REGION_PRIV_RW or @ref LL_MPU_REGION_PRIV_RW_URO or @ref LL_MPU_REGION_FULL_ACCESS
  *           or @ref LL_MPU_REGION_PRIV_RO or @ref LL_MPU_REGION_PRIV_RO_URO
  *         @arg @ref LL_MPU_TEX_LEVEL0 or @ref LL_MPU_TEX_LEVEL1 or @ref LL_MPU_TEX_LEVEL2 or @ref LL_MPU_TEX_LEVEL4
  *         @arg @ref LL_MPU_INSTRUCTION_ACCESS_ENABLE or  @ref LL_MPU_INSTRUCTION_ACCESS_DISABLE
  *         @arg @ref LL_MPU_ACCESS_SHAREABLE or @ref LL_MPU_ACCESS_NOT_SHAREABLE
  *         @arg @ref LL_MPU_ACCESS_CACHEABLE or @ref LL_MPU_ACCESS_NOT_CACHEABLE
  *         @arg @ref LL_MPU_ACCESS_BUFFERABLE or @ref LL_MPU_ACCESS_NOT_BUFFERABLE
  * @retval 无
  */
__STATIC_INLINE void LL_MPU_ConfigRegion(uint32_t Region, uint32_t SubRegionDisable, uint32_t Address, uint32_t Attributes)
{
  /* 设置区域编号 */
  WRITE_REG(MPU->RNR, Region);
  /* 设置基地址 */
  WRITE_REG(MPU->RBAR, (Address & 0xFFFFFFE0U));
  /* 配置 MPU 属性和启用区域 */
  WRITE_REG(MPU->RASR, (MPU_RASR_ENABLE_Msk | Attributes | (SubRegionDisable << MPU_RASR_SRD_Pos)));
}

/**
  * @brief  禁用区域
  * @rmtoll MPU_RNR      REGION        LL_MPU_DisableRegion\n
  *         MPU_RASR     ENABLE        LL_MPU_DisableRegion
  * @param  Region 此参数可以是以下值之一：
  *         @arg @ref LL_MPU_REGION_NUMBER0
  *         @arg @ref LL_MPU_REGION_NUMBER1
  *         @arg @ref LL_MPU_REGION_NUMBER2
  *         @arg @ref LL_MPU_REGION_NUMBER3
  *         @arg @ref LL_MPU_REGION_NUMBER4
  *         @arg @ref LL_MPU_REGION_NUMBER5
  *         @arg @ref LL_MPU_REGION_NUMBER6
  *         @arg @ref LL_MPU_REGION_NUMBER7
  * @retval 无
  */
__STATIC_INLINE void LL_MPU_DisableRegion(uint32_t Region)
{
  /* 设置区域编号 */
  WRITE_REG(MPU->RNR, Region);
  /* 禁用 MPU 区域 */
  CLEAR_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

/**
  * @}
  */

#endif /* __MPU_PRESENT */
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

#endif /* __STM32F1xx_LL_CORTEX_H */
