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
/* 如果ADC有效启用，则开始转换 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 设置ADC状态 */
    /* - 清除与注入组转换结果相关的状态位 */
    /* - 设置与注入操作相关的状态位 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_INJ_EOC,
                      HAL_ADC_STATE_INJ_BUSY);
    
    /* 独立模式或多重模式（适用于具有多个ADC的设备）的情况： */
    /* 设置多重模式状态。 */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      // 清除多重模式从机状态位，当前处于非多重模式或为主机模式
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    else
    {
      // 设置多重模式从机状态位
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
    }
    
    /* 检查是否有规则通道转换正在进行 */
    /* 注意：在该设备上，没有仅与注入组转换相关的ADC错误代码字段。 */
    /*       如果规则组上有转换正在进行，则不会重置错误代码。 */
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
    {
      /* 重置ADC所有错误代码字段 */
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    /* 进程解锁 */
    /* 在开始ADC转换之前解锁：以防发生中断，让进程能进入ADC中断处理程序。 */
    __HAL_UNLOCK(hadc);
    
    /* 清除注入组转换标志 */
    /* (确保不会受到之前潜在的ADC操作带来的未知状态影响) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_JEOC);
    
    /* 使能注入通道的转换结束中断 */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_JEOC);
    
    /* 如果选择了软件触发启动注入组转换，并且禁止了自动注入转换，则启动注入组转换 */
    /* 如果选择了外部触发，转换将在下一个触发事件开始。 */
    /* 如果使能了自动注入转换，转换将在下一个规则组转换之后开始。 */
    if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO))
    {
      // 判断是否为软件触发且非多模式从机
      if (ADC_IS_SOFTWARE_START_INJECTED(hadc)     &&
          ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
      {
        /* 使用软件启动ADC注入组转换 */
        // 设置软件启动位和外部触发使能位
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_JSWSTART | ADC_CR2_JEXTTRIG));
      }
      else
      {
        /* 使用外部触发启动ADC注入组转换 */
        // 仅设置外部触发使能位
        SET_BIT(hadc->Instance->CR2, ADC_CR2_JEXTTRIG);
      }
    }
  }
  else
  {
    /* 进程解锁 */
    __HAL_UNLOCK(hadc);
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止注入通道转换，禁止转换结束中断。
  *         如果没有正在进行的规则转换，则关闭ADC外设。
  * @note   如果需要关闭ADC且规则组正在进行转换，
  *         必须使用 HAL_ADC_Stop 函数来同时停止注入组和规则组，并关闭ADC。
  * @note   如果注入组模式自动注入已使能，
  *         必须使用 HAL_ADC_Stop 函数。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 进程锁定 */
  __HAL_LOCK(hadc);
    
  /* 停止潜在的转换并关闭ADC外设 */
  /* 条件： */
  /* - 另一组（规则组）没有打算继续转换（注入组和规则组停止转换和ADC关闭是共同操作） */
  /* - 在自动注入模式下，必须使用 HAL_ADC_Stop。 */ 
  if(((hadc->State & HAL_ADC_STATE_REG_BUSY) == RESET)  &&
     HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO)   )
  {
    /* 停止正在进行的规则和注入组潜在转换 */
    /* 关闭ADC外设 */
    tmp_hal_status = ADC_ConversionStop_Disable(hadc);
    
    /* 检查ADC是否有效关闭 */
    if (tmp_hal_status == HAL_OK)
    {
      /* 禁止注入通道的转换结束中断 */
      __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
      
      /* 设置ADC状态 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                        HAL_ADC_STATE_READY);
    }
  }
  else
  {
    /* 更新ADC状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
    tmp_hal_status = HAL_ERROR;
  }
  
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  使能ADC，启动规则组转换并通过DMA传输结果。
  *         多重模式必须事先使用 HAL_ADCEx_MultiModeConfigChannel() 函数配置。
  *         此函数中使能的中断：
  *          - DMA传输完成
  *          - DMA半传输
  *         每个中断都有其专用的回调函数。
  * @note:  在STM32F1设备上，ADC从机规则组必须配置为转换触发 ADC_SOFTWARE_START。
  * @note:  ADC从机可以预先使用单模式 HAL_ADC_Start() 函数使能。
  * @param  hadc: ADC主机句柄指针（不应使用ADC从机句柄）
  * @param  pData: 目标缓冲区地址。
  * @param  Length: 从ADC外设传输到内存的数据长度。
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};

  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  
  /* 进程锁定 */
  __HAL_LOCK(hadc);

  /* 设置与ADC主机关联的ADC从机的临时句柄 */
  ADC_MULTI_SLAVE(hadc, &tmphadcSlave);
  
  /* 在STM32F1设备上，ADC从机规则组必须配置为转换触发 ADC_SOFTWARE_START。 */
  /* 注意：ADC从机的外部触发必须使能，这已在函数 "HAL_ADC_Init()" 中完成。 */
  if(!ADC_IS_SOFTWARE_START_REGULAR(&tmphadcSlave))  
  {
    /* 更新ADC状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    /* 进程解锁 */
    __HAL_UNLOCK(hadc);
    
    return HAL_ERROR;
  }
  
  /* 使能ADC外设：主机和从机（如果之前尚未使能） */
  tmp_hal_status = ADC_Enable(hadc);
  if (tmp_hal_status == HAL_OK)
  {
    tmp_hal_status = ADC_Enable(&tmphadcSlave);
  }
  
  /* 如果多重模式下的所有ADC都有效使能，则开始转换 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 设置ADC状态（ADC主机） */
    /* - 清除与规则组转换结果相关的状态位 */
    /* - 设置与规则操作相关的状态位 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_MULTIMODE_SLAVE,
                      HAL_ADC_STATE_REG_BUSY);
      
    /* 如果规则组上的转换也触发注入组，更新ADC状态。 */
    if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
    {
      ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
    }
    
    /* 进程解锁 */
    /* 在开始ADC转换之前解锁：以防发生中断，让进程能进入ADC中断处理程序。 */
    __HAL_UNLOCK(hadc);
    
    /* 设置ADC错误代码为无 */
    ADC_CLEAR_ERRORCODE(hadc);
    
    
    /* 设置DMA传输完成回调函数 */
    hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;
       
    /* 设置DMA半传输完成回调函数 */
    hadc->DMA_Handle->XferHalfCpltCallback = ADC_DMAHalfConvCplt;
    
    /* 设置DMA错误回调函数 */
    hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;

    
    /* 管理ADC和DMA启动：ADC溢出中断，DMA启动，ADC启动（如果是软件启动）： */
    
    /* 清除规则组转换标志和溢出标志 */
    /* (确保不会受到之前潜在的ADC操作带来的未知状态影响) */
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    /* 使能ADC主机的DMA模式 */
    SET_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* 启动DMA通道 */
    HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);
    
    /* 如果选择了软件触发，则启动规则组转换。 */
    /* 如果选择了外部触发，转换将在下一个触发事件开始。 */
    /* 注意：单次转换的替代触发方式可以是强制设置ADON位 "hadc->Instance->CR2 |= ADC_CR2_ADON;"*/
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc))
    {
      /* 使用软件启动ADC规则组转换 */
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      /* 使用外部触发启动ADC规则组转换 */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    /* 进程解锁 */
    __HAL_UNLOCK(hadc);
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止规则组的ADC转换（如果是自动注入模式，也包括注入通道），
  *         禁止ADC DMA传输，关闭ADC外设。
  * @note   此函数后多重模式保持使能。要禁止多重模式
  *         （通过 HAL_ADCEx_MultiModeConfigChannel() 设置），ADC必须
  *         使用 HAL_ADC_Init() 或 HAL_ADC_ReInit() 重新初始化。
  * @note   如果DMA配置为循环模式，在此函数之后必须调用
  *         HAL_ADC_Stop_DMA 并使用ADC从机的句柄，以正确禁止DMA通道。
  * @param  hadc: ADC主机句柄指针（不应使用ADC从机句柄）
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};
  
  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  
  /* 进程锁定 */
  __HAL_LOCK(hadc);

  /* 停止正在进行的规则和注入组潜在转换 */
  /* 关闭ADC主机外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* 检查ADC是否有效关闭 */
  if(tmp_hal_status == HAL_OK)
  {
    /* 设置与ADC主机关联的ADC从机的临时句柄 */
    ADC_MULTI_SLAVE(hadc, &tmphadcSlave);

    /* 关闭ADC从机外设 */
    tmp_hal_status = ADC_ConversionStop_Disable(&tmphadcSlave);

    /* 检查ADC是否有效关闭 */
    if(tmp_hal_status != HAL_OK)
    {
      /* 更新ADC状态机为错误状态 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

      /* 进程解锁 */
      __HAL_UNLOCK(hadc);

      return HAL_ERROR;
    }

    /* 禁止ADC DMA模式 */
    CLEAR_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* 重置双模式下的ADC DMA连续请求配置 */
    CLEAR_BIT(hadc->Instance->CR1, ADC_CR1_DUALMOD);
        
    /* 禁止DMA通道（以防DMA处于循环模式或在DMA传输正在进行时停止） */
    tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);

    /* 更改ADC状态（ADC主机） */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief  获取ADC注入组转换结果。
  * @note   读取寄存器JDRx会自动清除ADC标志JEOC
  *         (ADC注入组单元转换结束)。
  * @note   此函数不清除ADC标志JEOS
  *         (ADC注入组序列转换结束)
  *         标志JEOS上升沿的发生：
  *          - 如果序列器由1个等级组成，标志JEOS等同于
  *            标志JEOC。
  *          - 如果序列器由多个等级组成，在扫描
  *            序列期间仅升起JEOC标志，在扫描序列结束时
  *            JEOC和EOS标志都会升起。
  *         标志JEOS不应由此函数清除，因为
  *         这将不符合低功耗特性
  *         （低功耗自动等待特性，并非所有STM32系列都可用）。
  *         要清除此标志，可以使用以下函数： 
  *         编程模型 IT: @ref HAL_ADC_IRQHandler(), 编程
  *         模型轮询: @ref HAL_ADCEx_InjectedPollForConversion() 
  *         或 @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_JEOS)。
  * @param  hadc: ADC句柄指针
  * @param  InjectedRank: 转换的ADC注入等级。
  *          该参数可以是以下值之一：
  *            @arg ADC_INJECTED_RANK_1: 选择注入通道1
  *            @arg ADC_INJECTED_RANK_2: 选择注入通道2
  *            @arg ADC_INJECTED_RANK_3: 选择注入通道3
  *            @arg ADC_INJECTED_RANK_4: 选择注入通道4
  * @retval ADC注入组转换数据
  */
uint32_t HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank)
{
  uint32_t tmp_jdr = 0U;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_INJECTED_RANK(InjectedRank));
  
  /* 获取ADC转换值 */ 
  switch(InjectedRank)
  {  
    case ADC_INJECTED_RANK_4: 
      // 获取注入组第4个通道的数据
      tmp_jdr = hadc->Instance->JDR4;
      break;
    case ADC_INJECTED_RANK_3: 
      // 获取注入组第3个通道的数据
      tmp_jdr = hadc->Instance->JDR3;
      break;
    case ADC_INJECTED_RANK_2: 
      // 获取注入组第2个通道的数据
      tmp_jdr = hadc->Instance->JDR2;
      break;
    case ADC_INJECTED_RANK_1:
    default:
      // 获取注入组第1个通道的数据
      tmp_jdr = hadc->Instance->JDR1;
      break;
  }
  
  /* 返回ADC转换值 */ 
  return tmp_jdr;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  在选定的多重模式下返回上次ADC主机和从机规则转换结果数据。
  * @param  hadc: ADC主机句柄指针（不应使用ADC从机句柄）
  * @retval 转换的数据值。
  */
uint32_t HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef* hadc)
{
  uint32_t tmpDR = 0U;
  
  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 注意：此处软件不清除EOC标志，因为读取寄存器DR时硬件会自动清除。 */
  
  /* 在STM32F1设备上，ADC1数据寄存器DR仅在ADC1 DMA模式使能时包含ADC2转换结果。 */
  tmpDR = hadc->Instance->DR;

  if (HAL_IS_BIT_CLR(ADC1->CR2, ADC_CR2_DMA))
  {
    // 如果DMA未使能，手动合并ADC2的数据（高16位）
    tmpDR |= (ADC2->DR << 16U);
  }
    
  /* 返回ADC转换值 */ 
  return tmpDR;
}
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */

/**
  * @brief  非阻塞模式下的注入转换完成回调函数 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数编译警告 */
  UNUSED(hadc);
  /* 注意：此函数不应被修改，当需要回调时，
           HAL_ADCEx_InjectedConvCpltCallback 可以在用户文件中实现
  */
}

/**
  * @}
  */

/** @defgroup ADCEx_Exported_Functions_Group2 扩展外设控制函数
  * @brief    扩展外设控制函数
  *
@verbatim   
 ===============================================================================
             ##### 外设控制函数 #####
 ===============================================================================  
    [..]  本节提供允许执行以下操作的函数：
      (+) 配置注入组上的通道
      (+) 配置多重模式

@endverbatim
  * @{
  */

/**
  * @brief  配置ADC注入组以及选定的通道链接到注入组。
  * @note   可以动态更新参数：
  *         此函数初始化注入组，随后调用此函数可用于动态重新配置
  *         结构体 "ADC_InjectionConfTypeDef" 的某些参数，而无需重置ADC。
  *         这些参数的设置取决于ADC状态：
  *         必须在ADC未进行转换时调用此函数。
  * @param  hadc: ADC句柄指针
  * @param  sConfigInjected: ADC注入组和注入组ADC通道的结构体指针。
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc, ADC_InjectionConfTypeDef* sConfigInjected)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  __IO uint32_t wait_loop_index = 0U;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_CHANNEL(sConfigInjected->InjectedChannel)); // 检查注入通道
  assert_param(IS_ADC_SAMPLE_TIME(sConfigInjected->InjectedSamplingTime)); // 检查采样时间
  assert_param(IS_FUNCTIONAL_STATE(sConfigInjected->AutoInjectedConv)); // 检查自动注入转换状态
  assert_param(IS_ADC_EXTTRIGINJEC(sConfigInjected->ExternalTrigInjecConv)); // 检查外部触发注入转换
  assert_param(IS_ADC_RANGE(sConfigInjected->InjectedOffset)); // 检查注入偏移量范围
  
  if(hadc->Init.ScanConvMode != ADC_SCAN_DISABLE)
  {
    assert_param(IS_ADC_INJECTED_RANK(sConfigInjected->InjectedRank)); // 检查注入等级
    assert_param(IS_ADC_INJECTED_NB_CONV(sConfigInjected->InjectedNbrOfConversion)); // 检查注入转换数目
    assert_param(IS_FUNCTIONAL_STATE(sConfigInjected->InjectedDiscontinuousConvMode)); // 检查注入不连续转换模式
  }
  
  /* 进程锁定 */
  __HAL_LOCK(hadc);
/* 注入组序列器配置： */
  /* - 如果扫描模式被禁用，注入通道序列长度被设置为 */
  /*   0x00：转换1个通道（常规序列排名1的通道） */
  /*   参数 "InjectedNbrOfConversion" 被忽略。 */
  /*   注意：此设备的硬件存在扫描模式，如果禁用，则自动丢弃转换数量。 */
  /*   无论如何，为了在所有STM32设备上保持一致，转换数量强制为0x00。 */
  /* - 如果扫描模式被启用，注入通道序列长度被设置为 */
  /*   参数 "InjectedNbrOfConversion"。 */
  if (hadc->Init.ScanConvMode == ADC_SCAN_DISABLE)
  {
    if (sConfigInjected->InjectedRank == ADC_INJECTED_RANK_1)
    {
      /* 清除所有注入排名的旧SQx位 */
      MODIFY_REG(hadc->Instance->JSQR                             ,
                 ADC_JSQR_JL   |
                 ADC_JSQR_JSQ4 |
                 ADC_JSQR_JSQ3 |
                 ADC_JSQR_JSQ2 |
                 ADC_JSQR_JSQ1                                    ,
                 ADC_JSQR_RK_JL(sConfigInjected->InjectedChannel,
                                  ADC_INJECTED_RANK_1,
                                  0x01U));
    }
    /* 如果试图设置除排名1以外的注入排名，由于扫描模式被禁用而无法设置，则报告错误。 */
    else
    {
      /* 更新ADC状态机为错误状态 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      tmp_hal_status = HAL_ERROR;
    }
  }
  else
  {
    /* 由于注入通道排名的转换顺序取决于注入转换的总数， */
    /* 所选排名必须小于或等于注入转换总数才能进行更新。 */
    if (sConfigInjected->InjectedRank <= sConfigInjected->InjectedNbrOfConversion)
    {
      /* 清除所选排名的旧SQx位 */
      /* 设置所选排名的SQx位 */
      MODIFY_REG(hadc->Instance->JSQR                                         ,
                 
                 ADC_JSQR_JL                                               |
                 ADC_JSQR_RK_JL(ADC_JSQR_JSQ1,                         
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion)   ,
                 
                 ADC_JSQR_JL_SHIFT(sConfigInjected->InjectedNbrOfConversion) |
                 ADC_JSQR_RK_JL(sConfigInjected->InjectedChannel,      
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion)    );
    }
    else
    {
      /* 清除所选排名的旧SQx位 */
      MODIFY_REG(hadc->Instance->JSQR                                       ,
                 
                 ADC_JSQR_JL                                               |
                 ADC_JSQR_RK_JL(ADC_JSQR_JSQ1,                         
                                  sConfigInjected->InjectedRank,         
                                  sConfigInjected->InjectedNbrOfConversion) ,
                 
                 0x00000000U);
    }
  } 
    
  /* 注入组配置 */
  /* 参数更新取决于ADC状态： */
  /* 只有当ADC被禁用时才能更新的参数： */
  /*  - 外部触发启动转换 */
  /* 更新不取决于ADC状态的参数： */
  /*  - 自动注入转换 */
  /*  - 注入不连续模式 */
  /* 注意：如果ADC已经启用，在修改寄存器CR2时通过写入1到ADON位要小心不要启动意外的转换。 */
  if (ADC_IS_ENABLE(hadc) == RESET)
  {    
    MODIFY_REG(hadc->Instance->CR2                                           ,
               ADC_CR2_JEXTSEL |
               ADC_CR2_ADON                                                  ,
               ADC_CFGR_JEXTSEL(hadc, sConfigInjected->ExternalTrigInjecConv) );
  }
  
  
  /* 注入组配置 */
  /*  - 自动注入转换 */
  /*  - 注入不连续模式 */
  
    /* 如果注入组外部触发被禁用，则可以启用自动注入转换。 */
    if (sConfigInjected->AutoInjectedConv == ENABLE)
    {
      if (sConfigInjected->ExternalTrigInjecConv == ADC_INJECTED_SOFTWARE_START)
      {
        SET_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO);
      }
      else
      {
        /* 更新ADC状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        tmp_hal_status = HAL_ERROR;
      }
    }
    
    /* 只有当自动注入模式被禁用时，才能启用注入不连续模式。 */  
    if (sConfigInjected->InjectedDiscontinuousConvMode == ENABLE)
    {
      if (sConfigInjected->AutoInjectedConv == DISABLE)
      {
        SET_BIT(hadc->Instance->CR1, ADC_CR1_JDISCEN);
      } 
      else
      {
        /* 更新ADC状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        tmp_hal_status = HAL_ERROR;
      }
    }


  /* 注入通道采样时间配置 */
  /* 对于通道10到17 */
  if (sConfigInjected->InjectedChannel >= ADC_CHANNEL_10)
  {
    MODIFY_REG(hadc->Instance->SMPR1                                                             ,
               ADC_SMPR1(ADC_SMPR1_SMP10, sConfigInjected->InjectedChannel)                      ,
               ADC_SMPR1(sConfigInjected->InjectedSamplingTime, sConfigInjected->InjectedChannel) );
  }
  else /* 对于通道0到9 */
  {
    MODIFY_REG(hadc->Instance->SMPR2                                                             ,
               ADC_SMPR2(ADC_SMPR2_SMP0, sConfigInjected->InjectedChannel)                       ,
               ADC_SMPR2(sConfigInjected->InjectedSamplingTime, sConfigInjected->InjectedChannel) );
  }
  
  /* 如果选择了ADC1的注入通道16或注入通道17，则使能温度传感器 */
  /* 和内部参考电压测量路径。 */
  if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfigInjected->InjectedChannel == ADC_CHANNEL_VREFINT)      )
  {
    SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
  }
  
  
  /* 配置偏移量：偏移量使能/禁用，注入通道，偏移值 */
  switch(sConfigInjected->InjectedRank)
  {
    case 1:
      /* 设置注入通道1偏移量 */
      MODIFY_REG(hadc->Instance->JOFR1,
                 ADC_JOFR1_JOFFSET1,
                 sConfigInjected->InjectedOffset);
      break;
    case 2:
      /* 设置注入通道2偏移量 */
      MODIFY_REG(hadc->Instance->JOFR2,
                 ADC_JOFR2_JOFFSET2,
                 sConfigInjected->InjectedOffset);
      break;
    case 3:
      /* 设置注入通道3偏移量 */
      MODIFY_REG(hadc->Instance->JOFR3,
                 ADC_JOFR3_JOFFSET3,
                 sConfigInjected->InjectedOffset);
      break;
    case 4:
    default:
      MODIFY_REG(hadc->Instance->JOFR4,
                 ADC_JOFR4_JOFFSET4,
                 sConfigInjected->InjectedOffset);
      break;
  }
  
  /* 如果选择了ADC1的通道16或通道17，则使能温度传感器 */
  /* 和内部参考电压测量路径。 */
  if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfigInjected->InjectedChannel == ADC_CHANNEL_VREFINT)      )
  {
    /* 对于具有多个ADC的STM32F1设备：只有ADC1能访问内部 */
    /* 测量通道（VrefInt/TempSensor）。如果这些通道 */
    /* 试图在其他ADC实例上设置，则报告错误。 */
    if (hadc->Instance == ADC1)
    {
      if (READ_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE) == RESET)
      {
        SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
        
        if ((sConfigInjected->InjectedChannel == ADC_CHANNEL_TEMPSENSOR))
        {
          /* 温度传感器稳定时间的延时 */
          /* 计算需要等待的CPU周期数 */
          wait_loop_index = (ADC_TEMPSENSOR_DELAY_US * (SystemCoreClock / 1000000U));
          while(wait_loop_index != 0U)
          {
            wait_loop_index--;
          }
        }
      }
    }
    else
    {
      /* 更新ADC状态机为错误状态 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      tmp_hal_status = HAL_ERROR;
    }
  }
  
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

#if defined (STM32F103x6) || defined (STM32F103xB) || defined (STM32F105xC) || defined (STM32F107xC) || defined (STM32F103xE) || defined (STM32F103xG)
/**
  * @brief  使能ADC多模模式并配置多模参数
  * @note   可以动态更新参数：
  *         此函数初始化多模参数，随后的调用可用于动态重新配置 
  *         结构体 "ADC_MultiModeTypeDef" 的某些参数，而无需复位 
  *         ADC（公共组的两个ADC）。
  *         这些参数的设置取决于ADC状态。
  *         关于参数约束，请参阅结构体 "ADC_MultiModeTypeDef" 的注释。
  * @note   要将配置从多模改回单模，必须复位ADC（使用函数 HAL_ADC_Init() ）。
  * @param  hadc: ADC句柄
  * @param  multimode: ADC多模配置结构体
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef* hadc, ADC_MultiModeTypeDef* multimode)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  ADC_HandleTypeDef tmphadcSlave={0};
  
  /* 检查参数 */
  assert_param(IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_MODE(multimode->Mode));
  
  /* 进程锁 */
  __HAL_LOCK(hadc);
  
  /* 设置与ADC主机关联的ADC从机的临时句柄 */
  ADC_MULTI_SLAVE(hadc, &tmphadcSlave);
  
  /* 参数更新取决于ADC状态： */
  /* 当ADC被禁用或启用但常规组没有正在进行的转换时可以更新的参数： */
  /*  - ADC主机和ADC从机DMA配置 */
  /* 只有当ADC被禁用时才能更新的参数： */
  /*  - 多模模式选择 */
  /* 为了优化代码，当公共组的两个ADC都处于禁用状态时， */
  /* 可以设置所有多模设置。 */
  if ((ADC_IS_ENABLE(hadc) == RESET)                     &&
      (ADC_IS_ENABLE(&tmphadcSlave) == RESET)            &&
      (IS_ADC_MULTIMODE_MASTER_INSTANCE(hadc->Instance))   )
  {
    MODIFY_REG(hadc->Instance->CR1,
               ADC_CR1_DUALMOD    ,
               multimode->Mode     );
  }
  /* 如果共享同一公共组的一个ADC被启用，则无法更新 */
  /* 任何多模结构参数。 */
  else
  {
    /* 更新ADC状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    tmp_hal_status = HAL_ERROR;
  }
    
    
  /* 进程解锁 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
} 
#endif /* defined STM32F103x6 || defined STM32F103xB || defined STM32F105xC || defined STM32F107xC || defined STM32F103xE || defined STM32F103xG */
/**
  * @}
  */  

/**
  * @}
  */

#endif /* HAL_ADC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */
