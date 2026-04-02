/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc_ex.c
  * @author  MCD Application Team
  * @brief   本文件提供固件函数，用于管理模数转换器(ADC)外设的以下功能：
  *          + 外设控制功能
  *          其他功能（通用功能）可在文件 "stm32f1xx_hal_adc.c" 中找到。
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
  [..] 
  (@) "ADC外设特性"和"如何使用本驱动程序"章节可在
      通用函数文件 "stm32f1xx_hal_adc.c" 中找到。
  [..]
  @endverbatim
  */

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup ADCEx ADCEx
  * @brief ADC 扩展 HAL 模块驱动
  * @{
  */

#ifdef HAL_ADC_MODULE_ENABLED

/* 私有类型定义 --------------------------------------------------------------*/
/* 私有宏定义 ----------------------------------------------------------------*/
/** @defgroup ADCEx_Private_Constants ADCEx 私有常量
  * @{
  */

  /* ADC校准的延时：                                                          */
  /* 启动校准前的硬件先决条件：ADC必须处于上电状态至少两个ADC时钟周期。       */
  /* 单位：ADC时钟周期                                                        */
  #define ADC_PRECALIBRATION_DELAY_ADCCLOCKCYCLES       2U

  /* ADC校准的超时值                                                          */
  /* 定义该值以高于最坏情况：低时钟频率，最大预分频器。                        */
  /* 低频配置示例：时钟源 0.1 MHz，ADC时钟预分频器 4，采样时间 12.5 ADC时钟周期，分辨率 12 位。*/
  /* 单位：ms                                                                 */
  #define ADC_CALIBRATION_TIMEOUT          10U

  /* 温度传感器稳定时间的延时。                                               */
  /* 最大延时为 10us（参考设备数据手册，参数 tSTART）。                       */
  /* 单位：us                                                                 */
  #define ADC_TEMPSENSOR_DELAY_US         10U

/**
  * @}
  */

/* 私有宏 --------------------------------------------------------------------*/
/* 私有变量 ------------------------------------------------------------------*/
/* 私有函数原型 --------------------------------------------------------------*/
/* 私有函数 ------------------------------------------------------------------*/

/** @defgroup ADCEx_Exported_Functions ADCEx 导出函数
  * @{
  */

/** @defgroup ADCEx_Exported_Functions_Group1 扩展 IO 操作函数
 *  @brief    扩展输入输出操作函数
 *
@verbatim    
 ===============================================================================
                      ##### IO 操作函数 #####
 ===============================================================================
    [..]  本节提供允许执行以下操作的函数：
      (+) 启动注入组转换。
      (+) 停止注入组转换。
      (+) 轮询注入组转换完成。
      (+) 获取注入通道转换结果。
      (+) 启动注入组转换并使能中断。
      (+) 停止注入组转换并禁用中断。

      (+) 启动多模模式并使能 DMA 传输。
      (+) 停止多模模式并禁用 ADC DMA 传输。
      (+) 获取多模转换结果。

      (+) 执行 ADC 自校准（单端或差分）。
      (+) 获取校准因子（单端或差分）。
      (+) 设置校准因子（单端或差分）。
      
@endverbatim
  * @{
  */

/**
  * @brief  执行 ADC 自动自校准
  *         校准前提条件：ADC 必须处于禁用状态（在 HAL_ADC_Start() 之前或 HAL_ADC_Stop() 之后执行此函数）。
  *         在校准过程中，ADC 会被使能。函数完成后 ADC 保持使能状态。
  * @param  hadc: ADC 句柄指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK; // 定义临时状态变量，初始化为 OK
  uint32_t tickstart; // 用于存储超时起始时间
  __IO uint32_t wait_loop_index = 0U; // 用于软件延时循环的索引变量
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 锁定进程 */
  __HAL_LOCK(hadc);
    
   /* 1. 禁用 ADC 外设 */
   tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
   /* 2. 启动校准前的校准前提延时。       */
   /*    - ADC 必须使能至少两个 ADC 时钟周期               */
   tmp_hal_status = ADC_Enable(hadc);

   /* 检查 ADC 是否有效使能 */
   if (tmp_hal_status == HAL_OK)
   {
     /* 设置 ADC 状态 */
     ADC_STATE_CLR_SET(hadc->State, // 清除 REG_BUSY 和 INJ_BUSY 状态位，设置 BUSY_INTERNAL 状态位
                       HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                       HAL_ADC_STATE_BUSY_INTERNAL);
    
    /* 硬件前提：启动校准前的延时。          */
    /*  - 计算对应 ADC 时钟周期的 CPU 时钟周期数。  */
    /*  - 等待预期的 ADC 时钟周期延时 */
    wait_loop_index = ((SystemCoreClock // 计算公式：系统时钟频率 / ADC外设时钟频率 * 需要的ADC周期数
                        / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                       * ADC_PRECALIBRATION_DELAY_ADCCLOCKCYCLES        );

    while(wait_loop_index != 0U) // 软件延时循环
    {
      wait_loop_index--;
    }

    /* 3. 复位 ADC 校准寄存器 */  
    SET_BIT(hadc->Instance->CR2, ADC_CR2_RSTCAL); // 设置 CR2 寄存器中的 RSTCAL 位
    
    tickstart = HAL_GetTick();  // 获取当前系统滴答时间

    /* 等待校准复位完成 */
    while(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_RSTCAL)) // 等待 RSTCAL 位被硬件清零
    {
      if((HAL_GetTick() - tickstart) > ADC_CALIBRATION_TIMEOUT) // 检查是否超时
      {
        /* 新检查以避免在抢占情况下出现错误的超时检测 */
        if(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_RSTCAL)) // 再次确认 RSTCAL 位是否仍为 1
        {
          /* 更新 ADC 状态机为错误状态 */
          ADC_STATE_CLR_SET(hadc->State,
                            HAL_ADC_STATE_BUSY_INTERNAL,
                            HAL_ADC_STATE_ERROR_INTERNAL);

          /* 解锁进程 */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR; // 返回错误状态
        }
      }
    }
    
    /* 4. 启动 ADC 校准 */
    SET_BIT(hadc->Instance->CR2, ADC_CR2_CAL); // 设置 CR2 寄存器中的 CAL 位
    
    tickstart = HAL_GetTick();  // 获取当前系统滴答时间

    /* 等待校准完成 */
    while(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_CAL)) // 等待 CAL 位被硬件清零
    {
      if((HAL_GetTick() - tickstart) > ADC_CALIBRATION_TIMEOUT) // 检查是否超时
      {
        /* 新检查以避免在抢占情况下出现错误的超时检测 */
        if(HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_CAL)) // 再次确认 CAL 位是否仍为 1
        {
          /* 更新 ADC 状态机为错误状态 */
          ADC_STATE_CLR_SET(hadc->State,
                            HAL_ADC_STATE_BUSY_INTERNAL,
                            HAL_ADC_STATE_ERROR_INTERNAL);

          /* 解锁进程 */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR; // 返回错误状态
        }
      }
    }
    
    /* 设置 ADC 状态 */
    ADC_STATE_CLR_SET(hadc->State, // 清除 BUSY_INTERNAL 状态位，设置 READY 状态位
                      HAL_ADC_STATE_BUSY_INTERNAL,
                      HAL_ADC_STATE_READY);
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  使能 ADC，启动注入组转换。
  *         此函数中使能的中断：无。
  * @param  hadc: ADC 句柄指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK; // 定义临时状态变量，初始化为 OK
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* 锁定进程 */
  __HAL_LOCK(hadc);
    
  /* 使能 ADC 外设 */
  tmp_hal_status = ADC_Enable(hadc);
  
  /* 如果 ADC 有效使能，则启动转换 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 设置 ADC 状态                                                          */
    /* - 清除与注入组转换结果相关的状态位    */
    /* - 设置与注入操作相关的状态位                     */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_INJ_EOC,
                      HAL_ADC_STATE_INJ_BUSY);
    
    /* 独立模式或多模模式（针对具有多个 ADC 的设备）的情况： */
    /* 设置多模状态。                                                   */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)) // 判断是否为非多模模式或多模主模式
    {
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE); // 清除从模式状态位
    }
    else
    {
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE); // 设置从模式状态位
    }
    
    /* 检查是否有常规转换正在进行 */
    /* 注意：在此设备上，没有与仅注入组转换相关的 ADC 错误代码字段。     */
    /*       如果常规组上有转换正在进行，则不会重置错误代码。                  */
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY)) // 如果常规转换未在进行中
    {
      /* 复位 ADC 所有错误代码字段 */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* 解锁进程 */
    /* 在启动 ADC 转换之前解锁：以防潜在的           */
    /* 中断，让进程进入 ADC IRQ Handler。                   */
    __HAL_UNLOCK(hadc);
    
    /* 清除注入组转换标志 */
    /* （以确保没有来自潜在先前 ADC 操作的未知状态） */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JEOC);
        
    /* 使能注入组转换。                                   */
    /* 如果选择了软件启动，转换立即开始。    */
    /* 如果选择了外部触发，转换将在下一个   */
    /* 触发事件开始。                                                         */
    /* 如果使能了自动注入转换，转换将在     */
    /* 下一次常规组转换之后开始。                                   */
    /* 使能多模的情况（针对具有多个 ADC 的设备）：如果 ADC 是   */
    /* 从机，则仅使能 ADC（不启动转换）。如果 ADC 是      */
    /* 主机，则使能 ADC 并启动转换。                      */
    if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO)) // 检查是否禁用了自动注入模式
    {
      if (ADC_IS_SOFTWARE_START_INJECTED(hadc)     && // 如果是软件触发注入
          ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  ) // 且是非多模或多模主机
      {
        /* 通过软件启动 ADC 注入组转换 */
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG)); // 设置 JSWSTART 和 JEXTTRIG 位
      }
      else
      {
        /* 通过外部触发启动 ADC 注入组转换 */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_JEXTTRIG); // 设置 JEXTTRIG 位
      }
    }
  }
  else
  {
    /* 解锁进程 */
    __HAL_UNLOCK(hadc);
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止注入通道转换。如果没有常规转换正在进行，则禁用 ADC 外设。
  * @note   如果必须禁用 ADC 且常规组上有转换正在进行，
  *         必须使用函数 HAL_ADC_Stop 来停止注入组和常规组，并禁用 ADC。
  * @note   如果注入组模式自动注入已使能，
  *         必须使用函数 HAL_ADC_Stop。
  * @note   在自动注入模式下，必须使用 HAL_ADC_Stop。
  * @param  hadc: ADC 句柄指针
  * @retval 无
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK; // 定义临时状态变量，初始化为 OK
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 锁定进程 */
  __HAL_LOCK(hadc);
    
  /* 停止潜在转换并禁用 ADC 外设                     */
  /* 条件：                                                          */
  /* - 另一组（常规组）上没有转换打算        */
  /*   继续（注入组和常规组停止转换和 ADC 禁用  */
  /*   是通用的）                                                            */
  /* - 在自动注入模式下，必须使用 HAL_ADC_Stop。             */
  if(((hadc->State & HAL_ADC_STATE_REG_BUSY) == RESET)  && // 检查常规组是否忙
     HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO)   ) // 检查是否禁用了自动注入
  {
    /* 停止常规组和注入组上正在进行的潜在转换 */
    /* 禁用 ADC 外设 */
    tmp_hal_status = ADC_ConversionStop_Disable(hadc);
    
    /* 检查 ADC 是否有效禁用 */
    if (tmp_hal_status == HAL_OK)
    {
      /* 设置 ADC 状态 */
      ADC_STATE_CLR_SET(hadc->State, // 清除 REG_BUSY 和 INJ_BUSY 状态位，设置 READY 状态位
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }
  else
  {
    /* 更新 ADC 状态机为配置错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
    tmp_hal_status = HAL_ERROR; // 返回错误状态
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  等待注入组转换完成。
  * @param  hadc: ADC 句柄指针
  * @param  Timeout: 超时值（毫秒）。
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout)
{
  uint32_t tickstart; // 用于存储超时起始时间

  /* 用于扫描模式使能且轮询每次转换的情况的轮询变量。  */
  __IO uint32_t Conversion_Timeout_CPU_cycles = 0U; // CPU 周期计数变量
  uint32_t Conversion_Timeout_CPU_cycles_max = 0U; // CPU 周期最大超时变量
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 获取超时起始时间 */
  tickstart = HAL_GetTick();  
     
  /* 轮询转换结束：区分单次/序列        */
  /* 转换。                                                              */
  /* 对于注入组，标志 JEOC 仅在序列结束时置位，    */
  /* 而不是序列内的每次转换。                             */
  /*  - 如果注入组为单次转换（禁用扫描模式或        */
  /*    InjectedNbrOfConversion ==1），使用标志 JEOC 确定      */
  /*    转换完成。                                                */
  /*  - 如果注入组为序列转换（使能扫描模式且      */
  /*    InjectedNbrOfConversion >=2），标志 JEOC 仅在结束时置位 */
  /*    序列。                                                             */
  /*    要轮询每次转换，需计算最大转换时间  */
  /*    从 ADC 转换时间（选定的采样时间 + 转换时间 */
  /*    12.5 ADC 时钟周期）和 APB2/ADC 时钟预分频器（取决于    */
  /*    设置，转换时间范围可从 28 到 32256 CPU 周期）。  */
  /*    由于标志 JEOC 在每次转换后未置位，无超时状态可  */
  /*    设置。                                                               */
  if ((hadc->Instance->JSQR & ADC_JSQR_JL) == RESET) // 检查注入通道数量是否为 0（单次转换或禁用扫描）
  {
    /* 等待转换结束标志置位 */
    while(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_JEOC)) // 轮询 JEOC 标志
    {
      /* 检查超时是否禁用（设置为无限等待） */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout)) // 检查是否超时
        {
          /* 新检查以避免在抢占情况下出现错误的超时检测 */
          if(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_JEOC)) // 再次确认 JEOC 标志是否未置位
          {
            /* 更新 ADC 状态机为超时状态 */
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            /* 解锁进程 */
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT; // 返回超时状态
          }
        }
      }
    }
  }
  else // 序列转换模式
  {
    /* 用等待最大转换时间代替轮询 */
    /*  - 计算对应 ADC 时钟周期的 CPU 时钟周期数   */
    /*    以及所有通道上的 ADC 最大转换周期。                  */
    /*  - 等待预期的 ADC 时钟周期延时                        */
    Conversion_Timeout_CPU_cycles_max = ((SystemCoreClock // 计算最大 CPU 周期数
                                          / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                                         * ADC_CONVCYCLES_MAX_RANGE(hadc)                 );
    
    while(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max) // 循环等待
    {
      /* 检查超时是否禁用（设置为无限等待） */
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0)||((HAL_GetTick() - tickstart ) > Timeout)) // 检查是否超时
        {
          /* 新检查以避免在抢占情况下出现错误的超时检测 */
          if(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max) // 再次确认是否仍未达到最大周期
          {
            /* 更新 ADC 状态机为超时状态 */
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            /* 解锁进程 */
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT; // 返回超时状态
          }
        }
      }
      Conversion_Timeout_CPU_cycles ++; // 递增周期计数
    }
  }

  /* 清除注入组转换标志 */
  /* 注意：在 STM32F1 ADC 上，同时清除常规转换标志               */
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JSTRT | ADC_FLAG_JEOC | ADC_FLAG_EOC);
  
  /* 更新 ADC 状态机 */
  SET_BIT(hadc->State, HAL_ADC_STATE_INJ_EOC); // 设置注入组转换结束状态位
  
  /* 确定注入组上是否有后续转换即将进行      */
  /* 通过外部触发或自动注入转换                  */
  /* 来自常规组。                                                      */
  if(ADC_IS_SOFTWARE_START_INJECTED(hadc)                     || // 如果是软件启动注入
     (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO) &&     // 或者禁用了自动注入
     (ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&      // 且是软件启动常规
      (hadc->Init.ContinuousConvMode == DISABLE)   )        )   ) // 且禁用了连续转换模式
  {
    /* 设置 ADC 状态 */
    CLEAR_BIT(hadc->State, HAL_ADC_STATE_INJ_BUSY);   // 清除注入组忙状态位
    
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY)) // 如果常规组也不忙
    {
      SET_BIT(hadc->State, HAL_ADC_STATE_READY); // 设置 ADC 为就绪状态
    }
  }
  
  /* 返回 ADC 状态 */
  return HAL_OK;
}

/**
  * @brief  使能 ADC，启动注入组转换并使能中断。
  *          - JEOC（注入组转换结束）
  *         每个中断都有其专用的回调函数。
  * @param  hadc: ADC 句柄指针
  * @retval HAL 状态。
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK; // 定义临时状态变量，初始化为 OK
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* 锁定进程 */
  __HAL_LOCK(hadc);
    
  /* 使能 ADC 外设 */
  tmp_hal_status = ADC_Enable(hadc);
