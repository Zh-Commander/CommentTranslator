/**
  ******************************************************************************
  * @file    stm32f1xx_hal_cortex.c
  * @author  MCD Application Team
  * @brief   CORTEX HAL模块驱动程序。
  *          本文件提供固件函数以管理CORTEX的以下功能：
  *           + 初始化和反初始化函数
  *           + 外设控制函数
  *
  @verbatim  
  ==============================================================================
                        ##### 如何使用本驱动 #####
  ==============================================================================

    [..]  
    *** 如何使用CORTEX HAL驱动配置中断 ***
    ===========================================================
    [..]     
    本节提供允许配置NVIC中断(IRQ)的函数。
    Cortex-M3异常由CMSIS函数管理。
   
    (#) 使用HAL_NVIC_SetPriorityGrouping()函数配置NVIC优先级分组，
        根据下表进行配置。
    (#) 使用HAL_NVIC_SetPriority()配置选定IRQ通道的优先级。
    (#) 使用HAL_NVIC_EnableIRQ()使能选定的IRQ通道。
    (#) 请参考编程手册了解如何配置优先级的详细信息。
      
     -@- 当选择NVIC_PRIORITYGROUP_0时，IRQ抢占将不再可能。
         挂起的IRQ优先级将仅由子优先级管理。
   
     -@- IRQ优先级顺序（按最高到最低优先级排序）：
        (+@) 最低抢占优先级
        (+@) 最低子优先级
        (+@) 最低硬件优先级（IRQ编号）
 
    [..]  
    *** 如何使用CORTEX HAL驱动配置Systick ***
    ========================================================
    [..]
    设置SysTick定时器作为时基。
           
   (+) HAL_SYSTICK_Config()函数调用SysTick_Config()函数，该函数是CMSIS函数，功能如下：
        (++) 使用传递的参数值配置SysTick重装载寄存器。
        (++) 配置SysTick IRQ优先级为最低值0x0F。
        (++) 复位SysTick计数器寄存器。
        (++) 配置SysTick计数器时钟源为内核时钟源(HCLK)。
        (++) 使能SysTick中断。
        (++) 启动SysTick计数器。
    
   (+) 您可以通过调用宏__HAL_CORTEX_SYSTICKCLK_CONFIG(SYSTICK_CLKSOURCE_HCLK_DIV8)
       将SysTick时钟源更改为HCLK_Div8，只需在HAL_SYSTICK_Config()函数调用之后调用即可。
       __HAL_CORTEX_SYSTICKCLK_CONFIG()宏定义在stm32f1xx_hal_cortex.h文件中。

   (+) 您可以通过调用HAL_NVIC_SetPriority(SysTick_IRQn,...)函数更改SysTick IRQ优先级，
       只需在HAL_SYSTICK_Config()函数调用之后调用即可。
       HAL_NVIC_SetPriority()调用NVIC_SetPriority()函数，这是一个CMSIS函数。

   (+) 要调整SysTick时基，请使用以下公式：
                            
       重装载值 = SysTick计数器时钟 x 期望时基
       (++) 重装载值是传递给HAL_SYSTICK_Config()函数的参数
       (++) 重装载值不应超过0xFFFFFF
   
  @endverbatim
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * 版权所有。
  *
  * 本软件根据条款授权，条款可在本软件组件根目录的LICENSE文件中找到。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  */

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup CORTEX CORTEX
  * @brief CORTEX HAL模块驱动
  * @{
  */

#ifdef HAL_CORTEX_MODULE_ENABLED

/* 私有类型 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有常量 ---------------------------------------------------------*/
/* 私有宏 ------------------------------------------------------------*/
/* 私有函数 ---------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/

/** @defgroup CORTEX_Exported_Functions CORTEX导出函数
  * @{
  */


/** @defgroup CORTEX_Exported_Functions_Group1 初始化和反初始化函数
  * @brief    初始化和配置函数 
  *
@verbatim    
  ==============================================================================
              ##### 初始化和反初始化函数 #####
  ==============================================================================
    [..]
      本节提供CORTEX HAL驱动函数，允许配置中断和Systick功能 

@endverbatim
  * @{
  */


/**
  * @brief  使用所需的解锁序列设置优先级分组字段（抢占优先级和子优先级）。
  * @param  PriorityGroup: 优先级分组位长度。 
  *         此参数可以是以下值之一：
  *         @arg NVIC_PRIORITYGROUP_0: 0位抢占优先级
  *                                    4位子优先级
  *         @arg NVIC_PRIORITYGROUP_1: 1位抢占优先级
  *                                    3位子优先级
  *         @arg NVIC_PRIORITYGROUP_2: 2位抢占优先级
  *                                    2位子优先级
  *         @arg NVIC_PRIORITYGROUP_3: 3位抢占优先级
  *                                    1位子优先级
  *         @arg NVIC_PRIORITYGROUP_4: 4位抢占优先级
  *                                    0位子优先级
  * @note   当选择NVIC_PriorityGroup_0时，IRQ抢占不再可能。
  *         挂起的IRQ优先级将仅由子优先级管理。
  * @retval 无
  */
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  /* 检查参数 */
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));
  
  /* 根据PriorityGroup参数值设置PRIGROUP[10:8]位 */
  NVIC_SetPriorityGrouping(PriorityGroup);
}

/**
  * @brief  设置中断的优先级。
  * @param  IRQn: 外部中断号。
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xx.h)）
  * @param  PreemptPriority: IRQn通道的抢占优先级。
  *         此参数可以是0到15之间的值
  *         较低的优先级值表示较高的优先级 
  * @param  SubPriority: IRQ通道的子优先级。
  *         此参数可以是0到15之间的值
  *         较低的优先级值表示较高的优先级。          
  * @retval 无
  */
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority)
{ 
  uint32_t prioritygroup = 0x00U;
  
  /* 检查参数 */
  assert_param(IS_NVIC_SUB_PRIORITY(SubPriority));
  assert_param(IS_NVIC_PREEMPTION_PRIORITY(PreemptPriority));
  
  /* 获取当前的优先级分组 */
  prioritygroup = NVIC_GetPriorityGrouping();
  
  /* 编码优先级并设置 */
  NVIC_SetPriority(IRQn, NVIC_EncodePriority(prioritygroup, PreemptPriority, SubPriority));
}

/**
  * @brief  在NVIC中断控制器中使能特定设备中断。
  * @note   为了正确配置中断优先级，应先调用NVIC_PriorityGroupConfig()函数。
  * @param  IRQn 外部中断号。
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）
  * @retval 无
  */
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn)
{
  /* 检查参数 */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* 使能中断 */
  NVIC_EnableIRQ(IRQn);
}

/**
  * @brief  在NVIC中断控制器中禁用特定设备中断。
  * @param  IRQn 外部中断号。
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）  
  * @retval 无
  */
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn)
{
  /* 检查参数 */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* 禁用中断 */
  NVIC_DisableIRQ(IRQn);
}

/**
  * @brief  发起系统复位请求以复位MCU。
  * @retval 无
  */
void HAL_NVIC_SystemReset(void)
{
  /* 系统复位 */
  NVIC_SystemReset();
}

/**
  * @brief  初始化系统定时器及其中断，并启动系统滴答定时器。
  *         计数器处于自由运行模式以生成周期性中断。
  * @param  TicksNumb: 指定两次中断之间的滴答数。
  * @retval status:  - 0  函数执行成功。
  *                  - 1  函数执行失败。
  */
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb)
{
   return SysTick_Config(TicksNumb);
}
/**
  * @}
  */

/** @defgroup CORTEX_Exported_Functions_Group2 外设控制函数
  * @brief   Cortex控制函数 
  *
@verbatim   
  ==============================================================================
                      ##### 外设控制函数 #####
  ==============================================================================
    [..]
      本小节提供一组允许控制CORTEX (NVIC, SYSTICK, MPU)功能的函数。 
 
      
@endverbatim
  * @{
  */

#if (__MPU_PRESENT == 1U)
/**
  * @brief  禁用MPU（内存保护单元）
  * @retval 无
  */
void HAL_MPU_Disable(void)
{
  /* 确保未完成的传输已完成 */
  __DMB();

  /* 禁用故障异常 */
  SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk;
  
  /* 禁用MPU并清除控制寄存器 */
  MPU->CTRL = 0U;
}

/**
  * @brief  使能MPU。
  * @param  MPU_Control: 指定硬故障、NMI、FAULTMASK期间MPU的控制模式，
  *          以及对默认内存的特权访问
  *         此参数可以是以下值之一：
  *            @arg MPU_HFNMI_PRIVDEF_NONE
  *            @arg MPU_HARDFAULT_NMI
  *            @arg MPU_PRIVILEGED_DEFAULT
  *            @arg MPU_HFNMI_PRIVDEF
  * @retval 无
  */
void HAL_MPU_Enable(uint32_t MPU_Control)
{
  /* 使能MPU */
  MPU->CTRL = MPU_Control | MPU_CTRL_ENABLE_Msk;
  
  /* 使能故障异常 */
  SCB->SHCSR |= SCB_SHCSR_MEMFAULTENA_Msk;
  
  /* 确保MPU设置生效 */
  __DSB();
  __ISB();
}

/**
  * @brief  使能MPU区域。
  * @retval 无
  */
void HAL_MPU_EnableRegion(uint32_t RegionNumber)
{
  /* 检查参数 */
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

  /* 设置区域编号 */
  MPU->RNR = RegionNumber;

  /* 使能该区域 */
  SET_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

/**
  * @brief  禁用MPU区域。
  * @retval 无
  */
void HAL_MPU_DisableRegion(uint32_t RegionNumber)
{
  /* 检查参数 */
  assert_param(IS_MPU_REGION_NUMBER(RegionNumber));

  /* 设置区域编号 */
  MPU->RNR = RegionNumber;

  /* 禁用该区域 */
  CLEAR_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

/**
  * @brief  初始化并配置区域和要保护的内存。
  * @param  MPU_Init: 指向MPU_Region_InitTypeDef结构体的指针，包含初始化和配置信息。
  * @retval 无
  */
void HAL_MPU_ConfigRegion(MPU_Region_InitTypeDef *MPU_Init)
{
  /* 检查参数 */
  assert_param(IS_MPU_REGION_NUMBER(MPU_Init->Number));
  assert_param(IS_MPU_REGION_ENABLE(MPU_Init->Enable));
  assert_param(IS_MPU_INSTRUCTION_ACCESS(MPU_Init->DisableExec));
  assert_param(IS_MPU_REGION_PERMISSION_ATTRIBUTE(MPU_Init->AccessPermission));
  assert_param(IS_MPU_TEX_LEVEL(MPU_Init->TypeExtField));
  assert_param(IS_MPU_ACCESS_SHAREABLE(MPU_Init->IsShareable));
  assert_param(IS_MPU_ACCESS_CACHEABLE(MPU_Init->IsCacheable));
  assert_param(IS_MPU_ACCESS_BUFFERABLE(MPU_Init->IsBufferable));
  assert_param(IS_MPU_SUB_REGION_DISABLE(MPU_Init->SubRegionDisable));
  assert_param(IS_MPU_REGION_SIZE(MPU_Init->Size));

  /* 设置区域编号 */
  MPU->RNR = MPU_Init->Number;

  /* 禁用该区域以便配置 */
  CLEAR_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);

  /* 应用配置 */
  MPU->RBAR = MPU_Init->BaseAddress;
  MPU->RASR = ((uint32_t)MPU_Init->DisableExec             << MPU_RASR_XN_Pos)   |
              ((uint32_t)MPU_Init->AccessPermission        << MPU_RASR_AP_Pos)   |
              ((uint32_t)MPU_Init->TypeExtField            << MPU_RASR_TEX_Pos)  |
              ((uint32_t)MPU_Init->IsShareable             << MPU_RASR_S_Pos)    |
              ((uint32_t)MPU_Init->IsCacheable             << MPU_RASR_C_Pos)    |
              ((uint32_t)MPU_Init->IsBufferable            << MPU_RASR_B_Pos)    |
              ((uint32_t)MPU_Init->SubRegionDisable        << MPU_RASR_SRD_Pos)  |
              ((uint32_t)MPU_Init->Size                    << MPU_RASR_SIZE_Pos) |
              ((uint32_t)MPU_Init->Enable                  << MPU_RASR_ENABLE_Pos);
}
#endif /* __MPU_PRESENT */

/**
  * @brief  从NVIC中断控制器获取优先级分组字段。
  * @retval 优先级分组字段 (SCB->AIRCR [10:8] PRIGROUP 字段)
  */
uint32_t HAL_NVIC_GetPriorityGrouping(void)
{
  /* 获取PRIGROUP[10:8]字段值 */
  return NVIC_GetPriorityGrouping();
}

/**
  * @brief  获取中断的优先级。
  * @param  IRQn: 外部中断号。
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）
  * @param   PriorityGroup: 优先级分组位长度。
  *         此参数可以是以下值之一：
  *           @arg NVIC_PRIORITYGROUP_0: 0位抢占优先级
  *                                      4位子优先级
  *           @arg NVIC_PRIORITYGROUP_1: 1位抢占优先级
  *                                      3位子优先级
  *           @arg NVIC_PRIORITYGROUP_2: 2位抢占优先级
  *                                      2位子优先级
  *           @arg NVIC_PRIORITYGROUP_3: 3位抢占优先级
  *                                      1位子优先级
  *           @arg NVIC_PRIORITYGROUP_4: 4位抢占优先级
  *                                      0位子优先级
  * @param  pPreemptPriority: 指向抢占优先级值的指针（从0开始）。
  * @param  pSubPriority: 指向子优先级值的指针（从0开始）。
  * @retval 无
  */
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t *pPreemptPriority, uint32_t *pSubPriority)
{
  /* 检查参数 */
  assert_param(IS_NVIC_PRIORITY_GROUP(PriorityGroup));
 /* 获取Cortex-M系统或特定设备中断的优先级 */
  NVIC_DecodePriority(NVIC_GetPriority(IRQn), PriorityGroup, pPreemptPriority, pSubPriority);
}

/**
  * @brief  设置外部中断的挂起位。
  * @param  IRQn 外部中断号
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）  
  * @retval 无
  */
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  /* 检查参数 */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));
  
  /* 设置中断挂起状态 */
  NVIC_SetPendingIRQ(IRQn);
}

/**
  * @brief  获取挂起的中断（读取NVIC中的挂起寄存器并返回指定中断的挂起位）。
  * @param  IRQn 外部中断号。
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）  
  * @retval status: - 0  中断状态未挂起。
  *                 - 1  中断状态挂起。
  */
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  /* 检查参数 */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* 如果挂起则返回1，否则返回0 */
  return NVIC_GetPendingIRQ(IRQn);
}

/**
  * @brief  清除外部中断的挂起位。
  * @param  IRQn 外部中断号。
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）  
  * @retval 无
  */
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  /* 检查参数 */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* 清除挂起的中断 */
  NVIC_ClearPendingIRQ(IRQn);
}

/**
  * @brief 获取活动中断（读取NVIC中的活动寄存器并返回活动位）。
  * @param IRQn 外部中断号
  *         此参数可以是IRQn_Type枚举的枚举器
  *         （有关完整的STM32设备IRQ通道列表，请参考相应的CMSIS设备文件(stm32f10xxx.h)）  
  * @retval status: - 0  中断状态未挂起。
  *                 - 1  中断状态挂起。
  */
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn)
{
  /* 检查参数 */
  assert_param(IS_NVIC_DEVICE_IRQ(IRQn));

  /* 如果处于活动状态则返回1，否则返回0 */
  return NVIC_GetActive(IRQn);
}

/**
  * @brief  配置SysTick时钟源。
  * @param  CLKSource: 指定SysTick时钟源。
  *         此参数可以是以下值之一：
  *             @arg SYSTICK_CLKSOURCE_HCLK_DIV8: AHB时钟8分频作为SysTick时钟源。
  *             @arg SYSTICK_CLKSOURCE_HCLK: AHB时钟作为SysTick时钟源。
  * @retval 无
  */
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource)
{
  /* 检查参数 */
  assert_param(IS_SYSTICK_CLK_SOURCE(CLKSource));
  if (CLKSource == SYSTICK_CLKSOURCE_HCLK)
  {
    /* 选择内核时钟(HCLK)作为SysTick时钟源 */
    SysTick->CTRL |= SYSTICK_CLKSOURCE_HCLK;
  }
  else
  {
    /* 选择HCLK/8作为SysTick时钟源 */
    SysTick->CTRL &= ~SYSTICK_CLKSOURCE_HCLK;
  }
}

/**
  * @brief  此函数处理SYSTICK中断请求。
  * @retval 无
  */
void HAL_SYSTICK_IRQHandler(void)
{
  HAL_SYSTICK_Callback();
}

/**
  * @brief  SYSTICK回调函数。
  * @retval 无
  */
__weak void HAL_SYSTICK_Callback(void)
{
  /* 注意：不应修改此函数，当需要回调时，
            HAL_SYSTICK_Callback可以在用户文件中实现
   */
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_CORTEX_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

