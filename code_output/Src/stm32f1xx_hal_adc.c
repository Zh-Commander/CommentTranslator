/**
  ******************************************************************************
  * @file    stm32f1xx_hal_adc.c
  * @author  MCD Application Team
  * @brief   本文件提供固件函数，用于管理模数转换器(ADC)外设的以下功能：
  *          + 初始化和反初始化函数
  *          + 外设控制函数
  *          + 外设状态函数
  *          其他功能（扩展功能）位于文件 "stm32f1xx_hal_adc_ex.c" 中。
  *
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录中的LICENSE文件中找到的条款进行许可。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                     ##### ADC外设特性 #####
  ==============================================================================
  [..]
  (+) 12位分辨率

  (+) 在常规转换结束、注入转换结束以及发生模拟看门狗或溢出事件时产生中断。
  
  (+) 单次和连续转换模式。
  
  (+) 扫描模式，用于顺序转换多个通道。
  
  (+) 数据对齐，内置数据一致性。
  
  (+) 可编程采样时间（按通道配置）
  
  (+) 常规组和注入组的ADC转换。

  (+) 外部触发（定时器或EXTI）
      适用于常规组和注入组。

  (+) DMA请求生成，用于传输常规组的转换数据。

  (+) 多模式双模式（适用于具有2个或更多ADC的设备）。
  
  (+) 在多模式双模式下可配置DMA数据存储（适用于具有2个或更多ADC的设备）。
  
  (+) 在双交错模式下可配置转换之间的延迟（适用于具有2个或更多ADC的设备）。
  
  (+) ADC校准

  (+) ADC电源要求：全速时2.4 V至3.6 V，低速时低至1.8 V。
  
  (+) ADC输入范围：从Vref-（连接到Vssa）到Vref+（连接到Vdda或外部电压基准）。


                     ##### 如何使用本驱动程序 #####
  ==============================================================================
    [..]

     *** ADC顶层相关参数配置 ***
     ============================================================
     [..]

    (#) 使能ADC接口
      (++) 前提条件是必须在RCC顶层配置ADC时钟。
           注意：在STM32F1上，ADC时钟频率最大为14MHz（请参考设备数据手册）。
           因此，必须根据ADC时钟源频率配置ADC时钟预分频器，以保持低于此最大频率。
        (++) 必须进行一项时钟设置：
             ADC时钟（内核时钟，也可能也是转换时钟）。
             (+++) 示例：
                   在HAL_ADC_MspInit()（推荐的代码位置）中或与其他设备时钟参数配置一起：
               (+++) RCC_PeriphCLKInitTypeDef  PeriphClkInit;
               (+++) __ADC1_CLK_ENABLE();
               (+++) PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
               (+++) PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
               (+++) HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);

    (#) ADC引脚配置
         (++) 使用宏 __HAL_RCC_GPIOx_CLK_ENABLE() 使能ADC GPIO的时钟
         (++) 使用函数 HAL_GPIO_Init() 将这些ADC引脚配置为模拟模式

    (#) 可选，如果使用ADC中断：
         (++) 使用函数 HAL_NVIC_EnableIRQ(ADCx_IRQn) 配置ADC的NVIC
         (++) 将ADC中断处理函数 HAL_ADC_IRQHandler() 插入到相应的ADC中断向量函数 ADCx_IRQHandler() 中。

    (#) 可选，如果使用DMA：
         (++) 使用函数 HAL_DMA_Init() 配置DMA（DMA通道，模式为正常或循环等）。
         (++) 使用函数 HAL_NVIC_EnableIRQ(DMAx_Channelx_IRQn) 配置DMA的NVIC
         (++) 将ADC中断处理函数 HAL_ADC_IRQHandler() 插入到相应的DMA中断向量函数 DMAx_Channelx_IRQHandler() 中。

     *** ADC、常规组/注入组、通道参数的配置 ***
     ==========================================================================
     [..]

    (#) 使用函数 HAL_ADC_Init() 配置ADC参数（分辨率、数据对齐等）和常规组参数（转换触发、序列器等）。

    (#) 使用函数 HAL_ADC_ConfigChannel() 配置常规组的通道参数（通道号、序列器中的通道排名等）。

    (#) 可选，使用函数 HAL_ADCEx_InjectedConfigChannel() 配置注入组参数（转换触发、序列器等）和注入组的通道参数（通道号、序列器中的通道排名等）。

    (#) 可选，使用函数 HAL_ADC_AnalogWDGConfig() 配置模拟看门狗参数（监控的通道、阈值等）。

    (#) 可选，对于具有多个ADC实例的设备：使用函数 HAL_ADCEx_MultiModeConfigChannel() 配置多模式参数。

     *** 执行ADC转换 ***
     ====================================
     [..]

    (#) 可选，执行自动ADC校准以提高转换精度，使用函数 HAL_ADCEx_Calibration_Start()。

    (#) ADC驱动程序可以在三种模式下使用：轮询、中断、DMA传输。

        (++) 轮询方式进行ADC转换：
          (+++) 使用函数 HAL_ADC_Start() 激活ADC外设并开始转换
          (+++) 使用函数 HAL_ADC_PollForConversion() 等待ADC转换完成
                （对于注入组：HAL_ADCEx_InjectedPollForConversion() ）
          (+++) 使用函数 HAL_ADC_GetValue() 获取转换结果
                （对于注入组：HAL_ADCEx_InjectedGetValue() ）
          (+++) 使用函数 HAL_ADC_Stop() 停止转换并禁用ADC外设

        (++) 中断方式进行ADC转换: 
          (+++) 使用函数 HAL_ADC_Start_IT() 激活ADC外设并开始转换
          (+++) 通过调用函数 HAL_ADC_ConvCpltCallback() 等待ADC转换完成
                （此函数必须在用户程序中实现）
                （对于注入组：HAL_ADCEx_InjectedConvCpltCallback() ）
          (+++) 使用函数 HAL_ADC_GetValue() 获取转换结果
                （对于注入组：HAL_ADCEx_InjectedGetValue() ）
          (+++) 使用函数 HAL_ADC_Stop_IT() 停止转换并禁用ADC外设

        (++) DMA传输方式进行ADC转换:
          (+++) 使用函数 HAL_ADC_Start_DMA() 激活ADC外设并开始转换
          (+++) 通过调用函数 HAL_ADC_ConvCpltCallback() 或 HAL_ADC_ConvHalfCpltCallback() 等待ADC转换完成
                （这些函数必须在用户程序中实现）
          (+++) 转换结果通过DMA自动传输到目标变量地址。
          (+++) 使用函数 HAL_ADC_Stop_DMA() 停止转换并禁用ADC外设

        (++) 对于具有多个ADC的设备：通过DMA传输进行ADC多模式转换:
          (+++) 使用函数 HAL_ADC_Start() 激活ADC外设（从机）并开始转换
          (+++) 使用函数 HAL_ADCEx_MultiModeStart_DMA() 激活ADC外设（主机）并开始转换
          (+++) 通过调用函数 HAL_ADC_ConvCpltCallback() 或 HAL_ADC_ConvHalfCpltCallback() 等待ADC转换完成
                （这些函数必须在用户程序中实现）
          (+++) 转换结果通过DMA自动传输到目标变量地址。
          (+++) 使用函数 HAL_ADCEx_MultiModeStop_DMA() 停止转换并禁用ADC外设（主机）
          (+++) 使用函数 HAL_ADC_Stop_IT() 停止转换并禁用ADC外设（从机）

     [..]

    (@) 回调函数必须在用户程序中实现：
      (+@) HAL_ADC_ErrorCallback()
      (+@) HAL_ADC_LevelOutOfWindowCallback() (模拟看门狗回调)
      (+@) HAL_ADC_ConvCpltCallback()
      (+@) HAL_ADC_ConvHalfCpltCallback
      (+@) HAL_ADCEx_InjectedConvCpltCallback()

     *** ADC反初始化 ***
     ============================================================
     [..]

    (#) 禁用ADC接口
      (++) ADC时钟可以在RCC顶层进行硬复位和禁用。
        (++) 使用宏 __ADCx_FORCE_RESET(), __ADCx_RELEASE_RESET() 对ADC外设进行硬复位。
        (++) 使用与配置步骤等效的宏/函数禁用ADC时钟。
             (+++) 示例：
                   在HAL_ADC_MspDeInit()（推荐的代码位置）中或与其他设备时钟参数配置一起：
               (+++) PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC
               (+++) PeriphClkInit.AdcClockSelection = RCC_ADCPLLCLK2_OFF
               (+++) HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit)

    (#) ADC引脚配置
         (++) 使用宏 __HAL_RCC_GPIOx_CLK_DISABLE() 禁用ADC GPIO的时钟

    (#) 可选，如果使用ADC中断：
         (++) 使用函数 HAL_NVIC_EnableIRQ(ADCx_IRQn) 禁用ADC的NVIC

    (#) 可选，如果使用DMA：
         (++) 使用函数 HAL_DMA_Init() 反初始化DMA。
         (++) 使用函数 HAL_NVIC_EnableIRQ(DMAx_Channelx_IRQn) 禁用DMA的NVIC

    [..]
    
    *** 回调注册 ***
    =============================================
    [..]

     编译标志 USE_HAL_ADC_REGISTER_CALLBACKS 设置为1时，
     允许用户动态配置驱动程序回调。
     使用函数 HAL_ADC_RegisterCallback() 注册中断回调。
    [..]

     函数 HAL_ADC_RegisterCallback() 允许注册以下回调：
       (+) ConvCpltCallback               : ADC转换完成回调
       (+) ConvHalfCpltCallback           : ADC转换DMA半传输回调
       (+) LevelOutOfWindowCallback       : ADC模拟看门狗1回调
       (+) ErrorCallback                  : ADC错误回调
       (+) InjectedConvCpltCallback       : ADC注入组转换完成回调
       (+) MspInitCallback                : ADC MSP初始化回调
       (+) MspDeInitCallback              : ADC MSP反初始化回调
     此函数以HAL外设句柄、回调ID和指向用户回调函数的指针作为参数。
    [..]

     使用函数 HAL_ADC_UnRegisterCallback 将回调重置为默认的弱函数。
    [..]

     HAL_ADC_UnRegisterCallback 以HAL外设句柄和回调ID作为参数。
     此函数允许重置以下回调：
       (+) ConvCpltCallback               : ADC转换完成回调
       (+) ConvHalfCpltCallback           : ADC转换DMA半传输回调
       (+) LevelOutOfWindowCallback       : ADC模拟看门狗1回调
       (+) ErrorCallback                  : ADC错误回调
       (+) InjectedConvCpltCallback       : ADC注入组转换完成回调
       (+) MspInitCallback                : ADC MSP初始化回调
       (+) MspDeInitCallback              : ADC MSP反初始化回调
     [..]

     默认情况下，在 HAL_ADC_Init() 之后且状态为 HAL_ADC_STATE_RESET 时，
     所有回调都设置为相应的弱函数：
     例如 HAL_ADC_ConvCpltCallback(), HAL_ADC_ErrorCallback()。
     MspInit 和 MspDeInit 函数除外，它们仅在 HAL_ADC_Init()/ HAL_ADC_DeInit() 中
     当这些回调为空（未预先注册）时重置为传统的弱函数。
    [..]

     如果 MspInit 或 MspDeInit 不为空，则 HAL_ADC_Init()/ HAL_ADC_DeInit()
     无论状态如何，都将保留并使用用户 MspInit/MspDeInit 回调（预先注册）。
     [..]

     回调只能在 HAL_ADC_STATE_READY 状态下注册/注销。
     MspInit/MspDeInit 函数除外，它们可以在 HAL_ADC_STATE_READY 或 HAL_ADC_STATE_RESET 状态下注册/注销，
     因此注册的（用户）MspInit/DeInit 回调可以在 Init/DeInit 期间使用。
    [..]

     然后，用户首先使用 HAL_ADC_RegisterCallback() 注册 MspInit/MspDeInit 用户回调，
     然后再调用 HAL_ADC_DeInit() 或 HAL_ADC_Init() 函数。
     [..]

     当编译标志 USE_HAL_ADC_REGISTER_CALLBACKS 设置为0或未定义时，
     回调注册功能不可用，所有回调都设置为相应的弱函数。
  
  @endverbatim
  */

/* Includes ------------------------------------------------------------------*/
/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup ADC ADC
  * @brief ADC HAL模块驱动
  * @{
  */

#ifdef HAL_ADC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* 私有类型定义 --------------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
/* 私有定义 ------------------------------------------------------------------*/
/** @defgroup ADC_Private_Constants ADC Private Constants
  * @brief ADC私有常量
  * @{
  */

  /* Timeout values for ADC enable and disable settling time.                 */
  /* ADC使能和禁用稳定时间的超时值。                                           */
  /* Values defined to be higher than worst cases: low clocks freq,           */
  /* 定义值高于最坏情况：低时钟频率，                                           */
  /* maximum prescaler.                                                       */
  /* 最大预分频器。                                                            */
  /* Ex of profile low frequency : Clock source at 0.1 MHz, ADC clock         */
  /* 低频配置示例：时钟源为0.1 MHz，ADC时钟                                    */
  /* prescaler 4, sampling time 12.5 ADC clock cycles, resolution 12 bits.    */
  /* 预分频器为4，采样时间为12.5个ADC时钟周期，分辨率为12位。                    */
  /* Unit: ms                                                                 */
  /* 单位：毫秒                                                                */
  #define ADC_ENABLE_TIMEOUT              2U  // ADC使能超时时间定义为2ms
  #define ADC_DISABLE_TIMEOUT             2U  // ADC禁用超时时间定义为2ms

  /* Delay for ADC stabilization time.                                        */
  /* ADC稳定时间的延迟。                                                       */
  /* Maximum delay is 1us (refer to device datasheet, parameter tSTAB).       */
  /* 最大延迟为1us（请参考设备数据手册，参数tSTAB）。                            */
  /* Unit: us                                                                 */
  /* 单位：微秒                                                                */
  #define ADC_STAB_DELAY_US               1U  // ADC稳定延迟时间定义为1us

  /* Delay for temperature sensor stabilization time.                         */
  /* 温度传感器稳定时间的延迟。                                                 */
  /* Maximum delay is 10us (refer to device datasheet, parameter tSTART).     */
  /* 最大延迟为10us（请参考设备数据手册，参数tSTART）。                          */
  /* Unit: us                                                                 */
  /* 单位：微秒                                                                */
  #define ADC_TEMPSENSOR_DELAY_US         10U // 温度传感器稳定延迟时间定义为10us

/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/* 私有宏 --------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* 私有变量 ------------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* 私有函数原型 --------------------------------------------------------------*/
/** @defgroup ADC_Private_Functions ADC Private Functions
  * @brief ADC私有函数
  * @{
  */
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------------*/

/** @defgroup ADC_Exported_Functions ADC Exported Functions
  * @brief ADC导出函数
  * @{
  */

/** @defgroup ADC_Exported_Functions_Group1 Initialization/de-initialization functions 
  * @brief    初始化和反初始化函数
  *
@verbatim    
 ===============================================================================
              ##### 初始化和反初始化函数 #####
 ===============================================================================
    [..]  本节提供以下功能函数：
      (+) 初始化和配置ADC。 
      (+) 反初始化ADC。

@endverbatim
  * @{
  */

/**
  * @brief  根据结构体 "ADC_InitTypeDef" 中指定的参数初始化ADC外设和常规组。
  * @note   前提条件是必须在RCC顶层配置ADC时钟（时钟源APB2）。
  *         请参阅下方注释的示例代码，可将其复制并取消注释到 HAL_ADC_MspInit() 中。
  * @note   可以动态更新参数：
  *         此函数仅在来自ADC复位状态时初始化ADC MSP（HAL_ADC_MspInit()）。
  *         随后调用此函数可用于动态重新配置 ADC_InitTypeDef 结构体的某些参数，
  *         而无需修改MSP配置。如果需要再次修改ADC MSP，必须在调用 HAL_ADC_Init() 
  *         之前调用 HAL_ADC_DeInit()。
  *         这些参数的设置取决于ADC状态。
  *         有关参数约束，请参阅结构体 "ADC_InitTypeDef" 的注释。
  * @note   此函数在两个范围内配置ADC：整个ADC的范围和常规组的范围。
  *         有关参数详细信息，请参阅结构体 "ADC_InitTypeDef" 的注释。
  * @param  hadc: ADC句柄指针，包含ADC外设的配置信息
  * @retval HAL状态：HAL_OK表示成功，其他值表示错误
  */
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK; // 定义临时状态变量，初始化为HAL_OK
  uint32_t tmp_cr1 = 0U; // 临时存储ADC控制寄存器1(CR1)的值
  uint32_t tmp_cr2 = 0U; // 临时存储ADC控制寄存器2(CR2)的值
  uint32_t tmp_sqr1 = 0U; // 临时存储ADC常规序列寄存器1(SQR1)的值
  
  /* Check ADC handle */
  /* 检查ADC句柄是否为空 */
  if(hadc == NULL)
  {
    return HAL_ERROR; // 如果句柄为空指针，返回错误状态
  }
  
  /* Check the parameters */
  /* 检查参数有效性，使用断言宏检查配置参数是否符合要求 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance)); // 检查ADC实例是否有效
  assert_param(IS_ADC_DATA_ALIGN(hadc->Init.DataAlign)); // 检查数据对齐方式是否有效
  assert_param(IS_ADC_SCAN_MODE(hadc->Init.ScanConvMode)); // 检查扫描模式配置是否有效
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode)); // 检查连续转换模式是否有效
  assert_param(IS_ADC_EXTTRIG(hadc->Init.ExternalTrigConv)); // 检查外部触发转换配置是否有效
  
  /* 如果扫描模式未禁用，则需要检查与扫描模式相关的参数 */
  if(hadc->Init.ScanConvMode != ADC_SCAN_DISABLE)
  {
    assert_param(IS_ADC_REGULAR_NB_CONV(hadc->Init.NbrOfConversion)); // 检查常规组转换数量是否有效
    assert_param(IS_FUNCTIONAL_STATE(hadc->Init.DiscontinuousConvMode)); // 检查不连续转换模式是否有效
    /* 如果启用了不连续转换模式，则检查不连续转换的通道数量 */
    if(hadc->Init.DiscontinuousConvMode != DISABLE)
    {
      assert_param(IS_ADC_REGULAR_DISCONT_NUMBER(hadc->Init.NbrOfDiscConversion)); // 检查不连续转换通道数是否有效
    }
  }
  
  /* As prerequisite, into HAL_ADC_MspInit(), ADC clock must be configured    */
  /* at RCC top level.                                                        */
  /* Refer to header of this file for more details on clock enabling          */
  /* procedure.                                                               */
  /* 作为前提条件，在 HAL_ADC_MspInit() 中，必须在RCC顶层配置ADC时钟。          */
  /* 有关时钟使能过程的更多详细信息，请参阅本文件头部的说明。                     */

  /* Actions performed only if ADC is coming from state reset:                */
  /* - Initialization of ADC MSP                                              */
  /* 仅当ADC处于复位状态时才执行以下操作：                                      */
  /* - 初始化ADC MSP (底层硬件初始化)                                          */
  if (hadc->State == HAL_ADC_STATE_RESET)
  {
    /* Initialize ADC error code */
    /* 初始化ADC错误代码为无错误 */
    ADC_CLEAR_ERRORCODE(hadc);
    
    /* Allocate lock resource and initialize it */
    /* 分配锁资源并将其初始化为解锁状态 */
    hadc->Lock = HAL_UNLOCKED;
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* 初始化 ADC 回调函数设置 */
    hadc->ConvCpltCallback              = HAL_ADC_ConvCpltCallback;                 /* 注册默认的弱定义回调函数：转换完成回调 */
    hadc->ConvHalfCpltCallback          = HAL_ADC_ConvHalfCpltCallback;             /* 注册默认的弱定义回调函数：半转换完成回调 */
    hadc->LevelOutOfWindowCallback      = HAL_ADC_LevelOutOfWindowCallback;         /* 注册默认的弱定义回调函数：模拟看门狗越界回调 */
    hadc->ErrorCallback                 = HAL_ADC_ErrorCallback;                    /* 注册默认的弱定义回调函数：错误回调 */
    hadc->InjectedConvCpltCallback      = HAL_ADCEx_InjectedConvCpltCallback;       /* 注册默认的弱定义回调函数：注入组转换完成回调 */
    
    /* 如果用户没有注册底层的 MspInit 回调函数 */
    if (hadc->MspInitCallback == NULL)
    {
      /* 则使用默认的弱定义 MspInit 回调函数 */
      hadc->MspInitCallback = HAL_ADC_MspInit; 
    }
    
    /* 初始化底层硬件（如时钟、GPIO等） */
    hadc->MspInitCallback(hadc);
#else
    /* 初始化底层硬件（如时钟、GPIO等），不使用回调机制时直接调用函数 */
    HAL_ADC_MspInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }
  
  /* 停止正在进行中的转换，包括规则组和注入组 */
  /* 关闭 ADC 外设 */
  /* 注意：如果 ADC 已经使能，在修改 CR2 寄存器时写入 1 到 ADON 位可能会意外启动转换，需要特别注意 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  
  /* 如果上述预备操作正确完成，则配置 ADC 参数 */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL) &&
      (tmp_hal_status == HAL_OK)                                  )
  {
    /* 设置 ADC 状态：清除忙状态，置位内部忙状态 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_BUSY_INTERNAL);
    
    /* 设置 ADC 参数 */
    
    /* 配置 ADC 参数： */
    /*  - 数据对齐方式 */
    /*  - 外部触发转换选择 */
    /*  - 外部触发极性（始终设为 1，因为所有触发源都需要，包括软件触发） */
    /*  - 连续转换模式 */
    /* 注意：外部触发极性 (ADC_CR2_EXTTRIG) 在 HAL_ADC_Start_xxx 函数中设置， */
    /* 因为如果在此函数中设置，使能 ADC 后注入组转换可能会意外启动规则组转换。 */
    tmp_cr2 |= (hadc->Init.DataAlign                                          |
                ADC_CFGR_EXTSEL(hadc, hadc->Init.ExternalTrigConv)            |
                ADC_CR2_CONTINUOUS((uint32_t)hadc->Init.ContinuousConvMode)   );

    /* 配置 ADC 参数： */
    /*  - 扫描模式 */
    /*  - 不连续模式禁用/使能 */
    /*  - 不连续模式转换数量 */
    tmp_cr1 |= (ADC_CR1_SCAN_SET(hadc->Init.ScanConvMode));
    
    /* 仅在连续模式禁用时使能不连续模式 */
    /* 注意：如果参数 "Init.ScanConvMode" 为禁用，不连续模式设置无效，但不会影响硬件 */
    if (hadc->Init.DiscontinuousConvMode == ENABLE)
    {
      if (hadc->Init.ContinuousConvMode == DISABLE)
      {
        /* 使能选定的 ADC 规则组不连续模式 */
        /* 设置不连续模式下的转换通道数 */
        SET_BIT(tmp_cr1, ADC_CR1_DISCEN                                            |
                         ADC_CR1_DISCONTINUOUS_NUM(hadc->Init.NbrOfDiscConversion)  );
      }
      else
      {
        /* ADC 规则组设置：连续模式和序列器不连续模式不能同时使能 */
        
        /* 更新 ADC 状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
        
        /* 设置 ADC 错误码为内部错误 */
        SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      }
    }
    
    /* 使用之前的设置更新 ADC 配置寄存器 CR1 */
      MODIFY_REG(hadc->Instance->CR1,
                 ADC_CR1_SCAN    |
                 ADC_CR1_DISCEN  |
                 ADC_CR1_DISCNUM    ,
                 tmp_cr1             );
    
    /* 使用之前的设置更新 ADC 配置寄存器 CR2 */
      MODIFY_REG(hadc->Instance->CR2,
                 ADC_CR2_ALIGN   |
                 ADC_CR2_EXTSEL  |
                 ADC_CR2_EXTTRIG |
                 ADC_CR2_CONT       ,
                 tmp_cr2             );

    /* 配置规则组序列器： */
    /* - 如果扫描模式禁用，规则通道序列长度设为 0x00：转换 1 个通道（规则排名 1 的通道） */
    /*   参数 "NbrOfConversion" 被忽略。 */
    /*   注意：硬件上存在扫描模式，禁用时会自动忽略转换数量。强制设为 0x00 是为了兼容所有 STM32 设备。 */
    /* - 如果扫描模式使能，规则通道序列长度设为参数 "NbrOfConversion" */
    if (ADC_CR1_SCAN_SET(hadc->Init.ScanConvMode) == ADC_SCAN_ENABLE)
    {
      tmp_sqr1 = ADC_SQR1_L_SHIFT(hadc->Init.NbrOfConversion);
    }
      
    MODIFY_REG(hadc->Instance->SQR1,
               ADC_SQR1_L          ,
               tmp_sqr1             );
    
    /* 回读检查 ADC 寄存器是否已有效配置，确保 ADC 核心时钟没有问题 */
    /* 通过检查寄存器 CR2（排除其他函数设置的位：执行控制位 ADON, JSWSTART, SWSTART，规则组位 DMA，注入组位 JEXTTRIG 和 JEXTSEL，内部测量通道位 TSVREFE） */
    if (READ_BIT(hadc->Instance->CR2, ~(ADC_CR2_ADON | ADC_CR2_DMA |
                                        ADC_CR2_SWSTART | ADC_CR2_JSWSTART |
                                        ADC_CR2_JEXTTRIG | ADC_CR2_JEXTSEL |
                                        ADC_CR2_TSVREFE                     ))
         == tmp_cr2)
    {
      /* 设置 ADC 错误码为无错误 */
      ADC_CLEAR_ERRORCODE(hadc);
      
      /* 设置 ADC 状态为就绪 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_READY);
    }
    else
    {
      /* 更新 ADC 状态机为内部错误状态 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_BUSY_INTERNAL,
                        HAL_ADC_STATE_ERROR_INTERNAL);
      
      /* 设置 ADC 错误码为 ADC IP 内部错误 */
      SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);
      
      tmp_hal_status = HAL_ERROR;
    }
  
  }
  else
  {
    /* 更新 ADC 状态机为错误状态 */
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);
        
    tmp_hal_status = HAL_ERROR;
  }
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  反初始化 ADC 外设寄存器到默认复位值，同时反初始化 ADC MSP。
  *         如果需要，可以复制示例代码并取消注释到函数 HAL_ADC_MspDeInit() 中。
  * @param  hadc: ADC 句柄指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADC_DeInit(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查 ADC 句柄是否有效 */
  if(hadc == NULL)
  {
     return HAL_ERROR;
  }
  
  /* 检查参数有效性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  /* 设置 ADC 状态为内部忙 */
  SET_BIT(hadc->State, HAL_ADC_STATE_BUSY_INTERNAL);
  
  /* 停止正在进行中的转换，包括规则组和注入组 */
  /* 关闭 ADC 外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  
  /* 如果上述预备操作正确完成，则配置 ADC 参数 */
  if (tmp_hal_status == HAL_OK)
  {
    /* ========== 复位 ADC 寄存器 ========== */




    /* 复位状态寄存器 SR */
    __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_AWD | ADC_FLAG_JEOC | ADC_FLAG_EOC |
                                ADC_FLAG_JSTRT | ADC_FLAG_STRT));
                         
    /* 复位控制寄存器 CR1：清除模拟看门狗、扫描模式、中断使能等配置位 */
    CLEAR_BIT(hadc->Instance->CR1, (ADC_CR1_AWDEN   | ADC_CR1_JAWDEN | ADC_CR1_DISCNUM | 
                                    ADC_CR1_JDISCEN | ADC_CR1_DISCEN | ADC_CR1_JAUTO   | 
                                    ADC_CR1_AWDSGL  | ADC_CR1_SCAN   | ADC_CR1_JEOCIE  |   
                                    ADC_CR1_AWDIE   | ADC_CR1_EOCIE  | ADC_CR1_AWDCH    ));
    
    /* 复位控制寄存器 CR2：清除温度传感器、启动转换、外部触发、对齐、DMA、校准、连续模式等配置位 */
    CLEAR_BIT(hadc->Instance->CR2, (ADC_CR2_TSVREFE | ADC_CR2_SWSTART | ADC_CR2_JSWSTART | 
                                    ADC_CR2_EXTTRIG | ADC_CR2_EXTSEL  | ADC_CR2_JEXTTRIG |  
                                    ADC_CR2_JEXTSEL | ADC_CR2_ALIGN   | ADC_CR2_DMA      |        
                                    ADC_CR2_RSTCAL  | ADC_CR2_CAL     | ADC_CR2_CONT     |          
                                    ADC_CR2_ADON                                          ));
    
    /* 复位采样时间寄存器 SMPR1：清除通道 10-17 的采样时间配置 */
    CLEAR_BIT(hadc->Instance->SMPR1, (ADC_SMPR1_SMP17 | ADC_SMPR1_SMP16 | ADC_SMPR1_SMP15 | 
                                      ADC_SMPR1_SMP14 | ADC_SMPR1_SMP13 | ADC_SMPR1_SMP12 | 
                                      ADC_SMPR1_SMP11 | ADC_SMPR1_SMP10                    ));
    
    /* 复位采样时间寄存器 SMPR2：清除通道 0-9 的采样时间配置 */
    CLEAR_BIT(hadc->Instance->SMPR2, (ADC_SMPR2_SMP9 | ADC_SMPR2_SMP8 | ADC_SMPR2_SMP7 | 
                                      ADC_SMPR2_SMP6 | ADC_SMPR2_SMP5 | ADC_SMPR2_SMP4 | 
                                      ADC_SMPR2_SMP3 | ADC_SMPR2_SMP2 | ADC_SMPR2_SMP1 | 
                                      ADC_SMPR2_SMP0                                    ));

    /* 复位注入通道偏移寄存器 JOFR1 */
    CLEAR_BIT(hadc->Instance->JOFR1, ADC_JOFR1_JOFFSET1);
    /* 复位注入通道偏移寄存器 JOFR2 */
    CLEAR_BIT(hadc->Instance->JOFR2, ADC_JOFR2_JOFFSET2);
    /* 复位注入通道偏移寄存器 JOFR3 */
    CLEAR_BIT(hadc->Instance->JOFR3, ADC_JOFR3_JOFFSET3);
    /* 复位注入通道偏移寄存器 JOFR4 */
    CLEAR_BIT(hadc->Instance->JOFR4, ADC_JOFR4_JOFFSET4);
    
    /* 复位看门狗高阈值寄存器 HTR */
    CLEAR_BIT(hadc->Instance->HTR, ADC_HTR_HT);
    /* 复位看门狗低阈值寄存器 LTR */
    CLEAR_BIT(hadc->Instance->LTR, ADC_LTR_LT);
    
    /* 复位规则序列寄存器 SQR1：清除序列长度和通道配置 */
    CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L    |
                                    ADC_SQR1_SQ16 | ADC_SQR1_SQ15 | 
                                    ADC_SQR1_SQ14 | ADC_SQR1_SQ13  );
    
    /* 复位规则序列寄存器 SQR1（此处为源码重复操作） */
    CLEAR_BIT(hadc->Instance->SQR1, ADC_SQR1_L    |
                                    ADC_SQR1_SQ16 | ADC_SQR1_SQ15 | 
                                    ADC_SQR1_SQ14 | ADC_SQR1_SQ13  );
    
    /* 复位规则序列寄存器 SQR2：清除通道 7-12 的配置 */
    CLEAR_BIT(hadc->Instance->SQR2, ADC_SQR2_SQ12 | ADC_SQR2_SQ11 | ADC_SQR2_SQ10 | 
                                    ADC_SQR2_SQ9  | ADC_SQR2_SQ8  | ADC_SQR2_SQ7   );
    
    /* 复位规则序列寄存器 SQR3：清除通道 1-6 的配置 */
    CLEAR_BIT(hadc->Instance->SQR3, ADC_SQR3_SQ6 | ADC_SQR3_SQ5 | ADC_SQR3_SQ4 | 
                                    ADC_SQR3_SQ3 | ADC_SQR3_SQ2 | ADC_SQR3_SQ1  );
    
    /* 复位注入序列寄存器 JSQR */
    CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL |
                                    ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | 
                                    ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1  );
    
    /* 复位注入序列寄存器 JSQR（此处为源码重复操作） */
    CLEAR_BIT(hadc->Instance->JSQR, ADC_JSQR_JL |
                                    ADC_JSQR_JSQ4 | ADC_JSQR_JSQ3 | 
                                    ADC_JSQR_JSQ2 | ADC_JSQR_JSQ1  );
    
    /* 复位数据寄存器 DR */
    /* 该寄存器为只读，无法直接复位 */
    
    /* 复位注入数据寄存器 JDR1, JDR2, JDR3, JDR4 */
    /* 这些寄存器为只读，无法直接复位 */
    
    /* ========== ADC 外设硬件复位 ========== */
    /* 执行整个 ADC 外设的全局复位：ADC 状态被强制为类似上电后的状态。 */
    /* 如果需要，请将以下复位代码复制并取消注释到函数 "void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)" 中： */
    /*                                                                        */
    /*  __HAL_RCC_ADC1_FORCE_RESET()                                          */
    /*  __HAL_RCC_ADC1_RELEASE_RESET()                                        */
    
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    /* 如果未注册底层的 MspDeInit 回调函数 */
    if (hadc->MspDeInitCallback == NULL)
    {
      /* 则使用默认的弱定义 MspDeInit 回调函数 */
      hadc->MspDeInitCallback = HAL_ADC_MspDeInit; 
    }
    
    /* 反初始化底层硬件（如关闭时钟、反初始化 GPIO 等） */
    hadc->MspDeInitCallback(hadc);
#else
    /* 反初始化底层硬件（如关闭时钟、反初始化 GPIO 等），不使用回调机制时直接调用函数 */
    HAL_ADC_MspDeInit(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
    
    /* 设置 ADC 错误码为无错误 */
    ADC_CLEAR_ERRORCODE(hadc);
    
    /* 设置 ADC 状态为复位态 */
    hadc->State = HAL_ADC_STATE_RESET; 
  
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  初始化 ADC MSP（MCU特定包）。
  *         此函数用于配置底层硬件，如 GPIO、时钟等。
  * @param  hadc: ADC 句柄指针
  * @retval 无
  */
__weak void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  /* 防止编译器产生未使用参数的警告 */
  UNUSED(hadc);
  /* 注意：此函数不应被修改。当需要回调时，
           函数 HAL_ADC_MspInit 必须在用户文件中实现。
   */ 
}

/**
  * @brief  反初始化 ADC MSP（MCU特定包）。
  *         此函数用于复位底层硬件，如 GPIO、时钟等。
  * @param  hadc: ADC 句柄指针
  * @retval 无
  */
__weak void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  /* 防止编译器产生未使用参数的警告 */
  UNUSED(hadc);
  /* 注意：此函数不应被修改。当需要回调时，
           函数 HAL_ADC_MspDeInit 必须在用户文件中实现。
   */ 
}

#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
/**
  * @brief  注册用户自定义的 ADC 回调函数
  *         用于替代默认的弱定义回调函数
  * @param  hadc 指向 ADC_HandleTypeDef 结构体的指针，包含指定 ADC 的配置信息
  * @param  CallbackID 要注册的回调函数 ID
  *         此参数可以是以下值之一:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC 转换完成回调 ID
  *          @arg @ref HAL_ADC_CONVERSION_HALF_CB_ID          ADC 半转换完成回调 ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC 模拟看门狗 1 回调 ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC 错误回调 ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC 注入组转换完成回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp 初始化回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp 反初始化回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID MspInit 回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID MspDeInit 回调 ID
  * @param  pCallback 指向回调函数的指针
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADC_RegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID, pADC_CallbackTypeDef pCallback)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* 检查回调函数指针是否为空 */
  if (pCallback == NULL)
  {
    /* 更新错误码 */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

    return HAL_ERROR;
  }
  
  /* 如果 ADC 处于就绪状态 */
  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        /* 注册转换完成回调函数 */
        hadc->ConvCpltCallback = pCallback;
        break;
      
      case HAL_ADC_CONVERSION_HALF_CB_ID :
        /* 注册半转换完成回调函数 */
        hadc->ConvHalfCpltCallback = pCallback;
        break;
      
      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        /* 注册模拟看门狗越界回调函数 */
        hadc->LevelOutOfWindowCallback = pCallback;
        break;
      
      case HAL_ADC_ERROR_CB_ID :
        /* 注册错误回调函数 */
        hadc->ErrorCallback = pCallback;
        break;
      
      case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        /* 注册注入组转换完成回调函数 */
        hadc->InjectedConvCpltCallback = pCallback;
        break;
      
      case HAL_ADC_MSPINIT_CB_ID :
        /* 注册 Msp 初始化回调函数 */
        hadc->MspInitCallback = pCallback;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        /* 注册 Msp 反初始化回调函数 */
        hadc->MspDeInitCallback = pCallback;
        break;
      
      default :
        /* 更新错误码 */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;

        /* 返回错误状态 */
        status = HAL_ERROR;
        break;
    }
  }
  /* 如果 ADC 处于复位状态 */
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        /* 注册 Msp 初始化回调函数 */
        hadc->MspInitCallback = pCallback;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        /* 注册 Msp 反初始化回调函数 */
        hadc->MspDeInitCallback = pCallback;
        break;
      
      default :
        /* 更新错误码 */
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
      
        /* 返回错误状态 */
        status = HAL_ERROR;
        break;
    }
  }
  else
  {
    /* 更新错误码 */
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
    
    /* 返回错误状态 */
    status =  HAL_ERROR;
  }
  
  return status;
}

/**
  * @brief  注销 ADC 回调函数
  *         ADC 回调函数将被重定向到默认的弱定义回调函数
  * @param  hadc 指向 ADC_HandleTypeDef 结构体的指针，包含指定 ADC 的配置信息
  * @param  CallbackID 要注销的回调函数 ID
  *         此参数可以是以下值之一:
  *          @arg @ref HAL_ADC_CONVERSION_COMPLETE_CB_ID      ADC 转换完成回调 ID
  *          @arg @ref HAL_ADC_CONVERSION_HALF_CB_ID          ADC 半转换完成回调 ID
  *          @arg @ref HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID    ADC 模拟看门狗 1 回调 ID
  *          @arg @ref HAL_ADC_ERROR_CB_ID                    ADC 错误回调 ID
  *          @arg @ref HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID  ADC 注入组转换完成回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID                  ADC Msp 初始化回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID                ADC Msp 反初始化回调 ID
  *          @arg @ref HAL_ADC_MSPINIT_CB_ID MspInit 回调 ID
  *          @arg @ref HAL_ADC_MSPDEINIT_CB_ID MspDeInit 回调 ID
  * @retval HAL 状态
  */
HAL_StatusTypeDef HAL_ADC_UnRegisterCallback(ADC_HandleTypeDef *hadc, HAL_ADC_CallbackIDTypeDef CallbackID)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* 如果 ADC 处于就绪状态 */
  if ((hadc->State & HAL_ADC_STATE_READY) != 0)
  {
    switch (CallbackID)
    {
      case HAL_ADC_CONVERSION_COMPLETE_CB_ID :
        /* 恢复为默认的弱定义转换完成回调函数 */
        hadc->ConvCpltCallback = HAL_ADC_ConvCpltCallback;
        break;
      
      case HAL_ADC_CONVERSION_HALF_CB_ID :
        /* 恢复为默认的弱定义半转换完成回调函数 */
        hadc->ConvHalfCpltCallback = HAL_ADC_ConvHalfCpltCallback;
        break;
      
      case HAL_ADC_LEVEL_OUT_OF_WINDOW_1_CB_ID :
        /* 恢复为默认的弱定义模拟看门狗越界回调函数 */
        hadc->LevelOutOfWindowCallback = HAL_ADC_LevelOutOfWindowCallback;
        break;
      
      case HAL_ADC_ERROR_CB_ID :
        /* 恢复为默认的弱定义错误回调函数 */
        hadc->ErrorCallback = HAL_ADC_ErrorCallback;
        break;
case HAL_ADC_INJ_CONVERSION_COMPLETE_CB_ID :
        // 注册注入组转换完成回调函数，指向默认的弱定义函数
        hadc->InjectedConvCpltCallback = HAL_ADCEx_InjectedConvCpltCallback;
        break;
      
      case HAL_ADC_MSPINIT_CB_ID :
        // 注册MSP初始化回调函数，指向默认的弱定义函数
        hadc->MspInitCallback = HAL_ADC_MspInit;
        break;
      
      case HAL_ADC_MSPDEINIT_CB_ID :
        // 注册MSP反初始化回调函数，指向默认的弱定义函数
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;
        break;
      
      default :
        // 更新错误码，标记为无效的回调ID
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
        
        // 返回错误状态
        status =  HAL_ERROR;
        break;
    }
  }
  else if (HAL_ADC_STATE_RESET == hadc->State)
  {
    // 如果ADC处于复位状态，处理相关的回调注册
    switch (CallbackID)
    {
      case HAL_ADC_MSPINIT_CB_ID :
        // 注册MSP初始化回调函数
        hadc->MspInitCallback = HAL_ADC_MspInit;
        break;
        
      case HAL_ADC_MSPDEINIT_CB_ID :
        // 注册MSP反初始化回调函数
        hadc->MspDeInitCallback = HAL_ADC_MspDeInit;
        break;
        
      default :
        // 更新错误码，标记为无效的回调ID
        hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
        
        // 返回错误状态
        status =  HAL_ERROR;
        break;
    }
  }
  else
  {
    // 如果ADC状态既不是就绪也不是复位，则更新错误码
    hadc->ErrorCode |= HAL_ADC_ERROR_INVALID_CALLBACK;
    
    // 返回错误状态
    status =  HAL_ERROR;
  }
  
  return status;
}

#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */

/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group2 IO operation functions
 *  @brief    Input and Output operation functions
 *
@verbatim   
 ===============================================================================
                      ##### IO operation functions #####
 ===============================================================================
    [..]  This section provides functions allowing to:
      (+) Start conversion of regular group.
      (+) Stop conversion of regular group.
      (+) Poll for conversion complete on regular group.
      (+) Poll for conversion event.
      (+) Get result of regular channel conversion.
      (+) Start conversion of regular group and enable interruptions.
      (+) Stop conversion of regular group and disable interruptions.
      (+) Handle ADC interrupt request
      (+) Start conversion of regular group and enable DMA transfer.
      (+) Stop conversion of regular group and disable ADC DMA transfer.
@endverbatim
  * @{
  */

/**
  * @brief  Enables ADC, starts conversion of regular group.
  *         Interruptions enabled in this function: None.
  * @param  hadc: ADC handle
  * @retval HAL status
  */
// 函数功能: 使能ADC，启动常规组转换。注意：此函数不开启任何中断。
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  // 检查参数有效性，确认ADC实例是否合法
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  // 锁定进程，防止多线程冲突
  __HAL_LOCK(hadc);
   
  // 使能ADC外设
  tmp_hal_status = ADC_Enable(hadc);
  
  // 如果ADC成功使能，则启动转换
  if (tmp_hal_status == HAL_OK)
  {
    // 设置ADC状态
    // - 清除与常规组转换结果相关的状态位
    // - 设置与常规操作相关的状态位
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC,
                      HAL_ADC_STATE_REG_BUSY);
    
    // 设置注入组状态（针对自动注入模式）和多模式状态
    // 适用于多模式的所有情况：独立模式、多模式ADC主设备或多模式ADC从设备
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      // 设置ADC状态（独立模式或主模式）
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组（自动注入模式），则更新ADC状态
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      // 设置ADC状态（从模式）
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组（自动注入模式），则更新ADC状态
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
    
    // 状态机更新: 检查是否有注入转换正在进行
    if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    {
      // 仅清除与常规组转换相关的ADC错误码字段
      CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
    }
    else
    {
      // 清除所有ADC错误码字段
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    // 解锁进程
    // 在启动ADC转换之前解锁，以便在发生中断时允许ADC IRQ Handler处理
    __HAL_UNLOCK(hadc);
  
    // 清除常规组转换标志
    // 确保不会因为之前潜在的ADC操作而处于未知状态
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    // 使能常规组转换
    // 如果选择了软件启动，转换立即开始
    // 如果选择了外部触发，转换将在下一个触发事件开始
    // 多模式使能的情况:
    //  - 如果是从ADC，仅使能ADC（不启动转换）
    //  - 如果是主ADC，使能ADC并启动转换
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc)      &&
        ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
    {
      // 通过软件启动ADC常规组转换
      // 设置SWSTART位和EXTTRIG位
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      // 通过外部触发启动ADC常规组转换
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    // 如果ADC使能失败，解锁进程
    __HAL_UNLOCK(hadc);
  }
    
  // 返回函数执行状态
  return tmp_hal_status;
}

/**
  * @brief  Stop ADC conversion of regular group (and injected channels in 
  *         case of auto_injection mode), disable ADC peripheral.
  * @note:  ADC peripheral disable is forcing stop of potential 
  *         conversion on injected group. If injected group is under use, it
  *         should be preliminarily stopped using HAL_ADCEx_InjectedStop function.
  * @param  hadc: ADC handle
  * @retval HAL status.
  */
// 函数功能: 停止ADC常规组转换（如果是自动注入模式，也包括注入通道），并关闭ADC外设。
// 注意: 关闭ADC外设会强制停止注入组正在进行的转换。如果正在使用注入组，应先调用HAL_ADCEx_InjectedStop停止。
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
     
  // 锁定进程
  __HAL_LOCK(hadc);
  
  // 停止常规组和注入组正在进行的转换，并关闭ADC外设
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  // 检查ADC是否成功关闭
  if (tmp_hal_status == HAL_OK)
  {
    // 设置ADC状态为就绪
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  // 解锁进程
  __HAL_UNLOCK(hadc);
  
  // 返回函数执行状态
  return tmp_hal_status;
}

/**
  * @brief  Wait for regular group conversion to be completed.
  * @note   This function cannot be used in a particular setup: ADC configured 
  *         in DMA mode.
  *         In this case, DMA resets the flag EOC and polling cannot be
  *         performed on each conversion.
  * @note   On STM32F1 devices, limitation in case of sequencer enabled
  *         (several ranks selected): polling cannot be done on each 
  *         conversion inside the sequence. In this case, polling is replaced by
  *         wait for maximum conversion time.
  * @param  hadc: ADC handle
  * @param  Timeout: Timeout value in millisecond.
  * @retval HAL status
  */
// 函数功能: 等待常规组转换完成（轮询模式）。
// 注意: 此函数不能用于配置了DMA模式的ADC，因为DMA会清除EOC标志。
// 注意: 在STM32F1系列中，如果启用了扫描模式（多个通道），无法对每个转换进行轮询，
// 此时通过等待最大转换时间来替代。
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout)
{
  uint32_t tickstart = 0U;
  
  // 用于扫描模式轮询的变量
  __IO uint32_t Conversion_Timeout_CPU_cycles = 0U;
  uint32_t Conversion_Timeout_CPU_cycles_max = 0U;
 
  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  // 获取当前滴答计时器值，用于超时计算
  tickstart = HAL_GetTick();
  
  // 验证ADC配置是否支持轮询模式
  // 特殊情况：如果ADC配置为DMA模式
  if (HAL_IS_BIT_SET(hadc->Instance->CR2, ADC_CR2_DMA))
  {
    // 更新ADC状态机为配置错误
    SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
    
    // 解锁进程
    __HAL_UNLOCK(hadc);
    
    return HAL_ERROR;
  }
  
  // 轮询转换结束标志：区分单次转换和序列转换
  // - 如果是常规组单次转换（扫描模式禁用或转换数为1），使用EOC标志判断转换完成
  // - 如果是常规组序列转换（扫描模式使能且转换数>=2），EOC标志仅在序列结束时置位
  //   为了轮询每次转换，需要计算最大转换时间
  if (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_SCAN) &&
      HAL_IS_BIT_CLR(hadc->Instance->SQR1, ADC_SQR1_L)    )
  {
    // 等待转换结束标志(EOC)被置位
    while(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_EOC))
    {
      // 检查是否超时（如果不设置为无限等待）
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
        {
          // 再次检查以避免抢占导致的误判超时
          if(HAL_IS_BIT_CLR(hadc->Instance->SR, ADC_FLAG_EOC))
          {
            // 更新ADC状态机为超时
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);
            
            // 解锁进程
            __HAL_UNLOCK(hadc);
            
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  else
  {
    // 对于扫描模式序列转换，使用等待最大转换时间替代轮询EOC标志
    // 计算对应ADC时钟周期和所有通道最大转换周期的CPU时钟周期数
    Conversion_Timeout_CPU_cycles_max = ((SystemCoreClock
                                          / HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_ADC))
                                         * ADC_CONVCYCLES_MAX_RANGE(hadc)                 );
    
    // 循环等待计算出的CPU周期数
    while(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
    {
      // 检查是否超时
      if(Timeout != HAL_MAX_DELAY)
      {
        if((Timeout == 0U) || ((HAL_GetTick() - tickstart) > Timeout))
        {
          // 再次检查以避免误判
          if(Conversion_Timeout_CPU_cycles < Conversion_Timeout_CPU_cycles_max)
          {
            // 更新ADC状态机为超时
            SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

            // 解锁进程
            __HAL_UNLOCK(hadc);

            return HAL_TIMEOUT;
          }
        }
      }
      Conversion_Timeout_CPU_cycles ++;
    }
  }
  
  // 清除常规组转换标志（开始标志和转换结束标志）
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT | ADC_FLAG_EOC);
  
  // 更新ADC状态机，设置常规组转换结束标志
  SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
  
  // 判断是否还有后续转换（通过外部触发、连续模式或扫描序列）
  // 注意: 在STM32F1上，如果使能了扫描模式，转换结束标志在序列结束时产生
  if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        && 
     (hadc->Init.ContinuousConvMode == DISABLE)   )
  {   
    // 如果是软件启动且非连续转换模式，则认为转换已完成，清除忙状态
    CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);   

    // 如果注入组也不忙，则设置ADC为就绪状态
    if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    { 
      SET_BIT(hadc->State, HAL_ADC_STATE_READY);
    }
  }
  
  // 返回ADC状态
  return HAL_OK;
}

/**
  * @brief  Poll for conversion event.
  * @param  hadc: ADC handle
  * @param  EventType: the ADC event type.
  *          This parameter can be one of the following values:
  *            @arg ADC_AWD_EVENT: ADC Analog watchdog event.
  * @param  Timeout: Timeout value in millisecond.
  * @retval HAL status
  */
// 函数功能: 轮询转换事件。
// 参数 EventType: ADC事件类型，例如 ADC_AWD_EVENT (模拟看门狗事件)。
HAL_StatusTypeDef HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout)
{
  uint32_t tickstart = 0U; 

  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_EVENT_TYPE(EventType));
  
  // 获取当前滴答计时器值
  tickstart = HAL_GetTick();
  
  // 检查选定的事件标志
  while(__HAL_ADC_GET_FLAG(hadc, EventType) == RESET)
  {
    // 检查是否超时
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick() - tickstart ) > Timeout))
      {
        // 再次检查以避免误判
        if(__HAL_ADC_GET_FLAG(hadc, EventType) == RESET)
        {
          // 更新ADC状态机为超时
          SET_BIT(hadc->State, HAL_ADC_STATE_TIMEOUT);

          // 解锁进程
          __HAL_UNLOCK(hadc);

          return HAL_TIMEOUT;
        }
      }
    }
  }
  
  // 模拟看门狗事件（超出窗口范围）
  // 设置ADC状态
  SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);
    
  // 清除模拟看门狗标志
  __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD);
  
  // 返回ADC状态
  return HAL_OK;
}

/**
  * @brief  Enables ADC, starts conversion of regular group with interruption.
  *         Interruptions enabled in this function:
  *          - EOC (end of conversion of regular group)
  *         Each of these interruptions has its dedicated callback function.
  * @param  hadc: ADC handle
  * @retval HAL status
  */
// 函数功能: 使能ADC，启动常规组转换并开启中断。
// 此函数开启的中断：EOC (常规组转换结束中断)。
HAL_StatusTypeDef HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  // 检查参数有效性
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  
  // 锁定进程
  __HAL_LOCK(hadc);
    
  // 使能ADC外设
  tmp_hal_status = ADC_Enable(hadc);
  
  // 如果ADC成功使能，则启动转换
  if (tmp_hal_status == HAL_OK)
  {
    // 设置ADC状态
    // - 清除与常规组转换结果相关的状态位
    // - 设置与常规操作相关的状态位
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_OVR | HAL_ADC_STATE_REG_EOSMP,
                      HAL_ADC_STATE_REG_BUSY);
    
    // 设置注入组状态（针对自动注入模式）和多模式状态
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      // 设置ADC状态（独立模式或主模式）
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组，更新ADC状态
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      // 设置ADC状态（从模式）
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      // 如果常规组转换同时触发注入组，更新ADC状态
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
    
    // 状态机更新: 检查是否有注入转换正在进行
    if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
    {
      // 仅清除与常规组转换相关的ADC错误码字段
      CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
    }
    else
    {
      // 清除所有ADC错误码字段
      ADC_CLEAR_ERRORCODE(hadc);
    }
    
    // 解锁进程
    // 在启动ADC转换之前解锁，以便在发生中断时允许ADC IRQ Handler处理
    __HAL_UNLOCK(hadc);
    
    // 清除常规组转换标志和溢出标志
    // 确保不会因为之前潜在的ADC操作而处于未知状态
    __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
    
    // 使能常规组转换结束中断(EOC)
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_EOC);
    
    // 使能常规组转换
    // 如果选择了软件启动，转换立即开始
    // 如果选择了外部触发，转换将在下一个触发事件开始
    // 多模式使能的情况:
    //  - 如果是从ADC，仅使能ADC（不启动转换）
    //  - 如果是主ADC，使能ADC并启动转换
    if (ADC_IS_SOFTWARE_START_REGULAR(hadc)      &&
        ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc)  )
    {
      // 通过软件启动ADC常规组转换
      SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
    }
    else
    {
      // 通过外部触发启动ADC常规组转换
      SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
    }
  }
  else
  {
    // 如果ADC使能失败，解锁进程
    __HAL_UNLOCK(hadc);
  }
  
  // 返回函数执行状态
  return tmp_hal_status;
}
/**
  * @brief  停止ADC常规组的转换（如果是自动注入模式，也包括注入组），
  *         禁用转换结束中断，禁用ADC外设。
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
HAL_StatusTypeDef HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
     
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
  /* 停止当前正在进行的常规组和注入组的转换 */
  /* 禁用ADC外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* 检查ADC是否确实已被禁用 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 禁用ADC常规组的转换结束中断 */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC);
    
    /* 设置ADC状态 */
    /* 清除忙状态标志，设置为就绪状态 */
    ADC_STATE_CLR_SET(hadc->State,
                      HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                      HAL_ADC_STATE_READY);
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数执行状态 */
  return tmp_hal_status;
}

/**
  * @brief  使能ADC，启动常规组转换并通过DMA传输结果。
  *         此函数中使能的中断：
  *          - DMA传输完成中断
  *          - DMA半传输中断
  *         每个中断都有其专用的回调函数。
  * @note   对于具有多个ADC的设备：此函数仅适用于单ADC模式。
  *         对于多ADC模式，请使用专用的MultimodeStart函数。
  * @note   在STM32F1系列设备上，只有ADC1和ADC3（取决于具体设备）具有DMA功能。
  *         ADC2的转换数据可以在双ADC模式下使用ADC1的DMA进行传输（ADC1在多模式下为主ADC）。
  *         如果在具有2个ADC实例的设备上使用ADC1和DMA：
  *         ADC1转换寄存器DR包含ADC1转换结果（DR寄存器的0到11位），
  *         此外还包含ADC2的最后转换结果（DR寄存器的16到27位）。
  *         因此，如果只让DMA传输ADC1的转换结果，必须将DMA配置为半字传输。
  * @param  hadc: ADC句柄指针
  * @param  pData: 目标缓冲区地址（用于存储转换结果）
  * @param  Length: 要从ADC外设传输到内存的数据长度
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_DMA_CAPABILITY_INSTANCE(hadc->Instance));
    
  /* 验证多ADC模式是否禁用（针对有多个ADC的设备） */
  /* 如果启用了多ADC模式，必须使用专用的多模式转换启动DMA函数 */
  if(ADC_MULTIMODE_IS_ENABLE(hadc) == RESET)
  {
    /* 锁定进程 */
    __HAL_LOCK(hadc);
    
    /* 使能ADC外设 */
    tmp_hal_status = ADC_Enable(hadc);
    
    /* 如果ADC确实已使能，则开始转换 */
    if (tmp_hal_status == HAL_OK)
    {
      /* 设置ADC状态 */
      /* - 清除与常规组转换结果相关的状态位 */
      /* - 设置与常规操作相关的状态位 */
      ADC_STATE_CLR_SET(hadc->State,
                        HAL_ADC_STATE_READY | HAL_ADC_STATE_REG_EOC | HAL_ADC_STATE_REG_OVR | HAL_ADC_STATE_REG_EOSMP,
                        HAL_ADC_STATE_REG_BUSY);
    
    /* 设置注入组状态（来自自动注入）和多模式状态 */
    /* 适用于所有多模式情况：独立模式、多模式ADC主设备或多模式ADC从设备（针对有多个ADC的设备） */
    if (ADC_NONMULTIMODE_OR_MULTIMODEMASTER(hadc))
    {
      /* 设置ADC状态（ADC独立模式或主模式） */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* 如果常规组上的转换也触发注入组，则更新ADC状态 */
      if (READ_BIT(hadc->Instance->CR1, ADC_CR1_JAUTO) != RESET)
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);  
      }
    }
    else
    {
      /* 设置ADC状态（ADC从模式） */
      SET_BIT(hadc->State, HAL_ADC_STATE_MULTIMODE_SLAVE);
      
      /* 如果常规组上的转换也触发注入组，则更新ADC状态 */
      if (ADC_MULTIMODE_AUTO_INJECTED(hadc))
      {
        ADC_STATE_CLR_SET(hadc->State, HAL_ADC_STATE_INJ_EOC, HAL_ADC_STATE_INJ_BUSY);
      }
    }
      
      /* 状态机更新：检查是否有注入转换正在进行 */
      if (HAL_IS_BIT_SET(hadc->State, HAL_ADC_STATE_INJ_BUSY))
      {
        /* 复位与常规组转换相关的ADC错误代码字段 */
        CLEAR_BIT(hadc->ErrorCode, (HAL_ADC_ERROR_OVR | HAL_ADC_ERROR_DMA));         
      }
      else
      {
        /* 复位所有ADC错误代码字段 */
        ADC_CLEAR_ERRORCODE(hadc);
      }
      
      /* 解锁进程 */
      /* 在启动ADC转换之前解锁：以便在发生潜在中断时，让进程能进入ADC中断处理程序 */
      __HAL_UNLOCK(hadc);
      
      /* 设置DMA传输完成回调函数 */
      hadc->DMA_Handle->XferCpltCallback = ADC_DMAConvCplt;

      /* 设置DMA半传输完成回调函数 */
      hadc->DMA_Handle->XferHalfCpltCallback = ADC_DMAHalfConvCplt;
      
      /* 设置DMA错误回调函数 */
      hadc->DMA_Handle->XferErrorCallback = ADC_DMAError;

      
      /* 管理ADC和DMA启动：ADC溢出中断、DMA启动、ADC启动（如果是软件触发） */
      
      /* 清除常规组转换标志和溢出标志 */
      /* (确保没有来自之前ADC操作的未知状态) */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_EOC);
      
      /* 使能ADC DMA模式 */
      SET_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
      
      /* 启动DMA通道 */
      /* 源地址：ADC数据寄存器DR，目的地址：用户指定的内存缓冲区pData，长度：Length */
      HAL_DMA_Start_IT(hadc->DMA_Handle, (uint32_t)&hadc->Instance->DR, (uint32_t)pData, Length);
      
      /* 使能常规组转换 */
      /* 如果选择了软件启动，转换立即开始 */
      /* 如果选择了外部触发，转换将在下一个触发事件开始 */
      if (ADC_IS_SOFTWARE_START_REGULAR(hadc))
      {
        /* 使用软件触发启动ADC常规组转换 */
        SET_BIT(hadc->Instance->CR2, (ADC_CR2_SWSTART | ADC_CR2_EXTTRIG));
      }
      else
      {
        /* 使用外部触发启动ADC常规组转换 */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_EXTTRIG);
      }
    }
    else
    {
      /* 解锁进程 */
      __HAL_UNLOCK(hadc);
    }
  }
  else
  {
    tmp_hal_status = HAL_ERROR;
  }
  
  /* 返回函数执行状态 */
  return tmp_hal_status;
}

/**
  * @brief  停止ADC常规组的转换（如果是自动注入模式，也包括注入组），
  *         禁用ADC DMA传输，禁用ADC外设。
  * @note:  禁用ADC外设会强制停止注入组上可能正在进行的转换。
  *         如果正在使用注入组，应预先使用HAL_ADCEx_InjectedStop函数停止它。
  * @note   对于具有多个ADC的设备：此函数仅适用于单ADC模式。
  *         对于多ADC模式，请使用专用的MultimodeStop函数。
  * @note   在STM32F1系列设备上，只有ADC1和ADC3（取决于具体设备）具有DMA功能。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc)
{
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_DMA_CAPABILITY_INSTANCE(hadc->Instance));
     
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
  /* 停止当前正在进行的常规组和注入组的转换 */
  /* 禁用ADC外设 */
  tmp_hal_status = ADC_ConversionStop_Disable(hadc);
  
  /* 检查ADC是否确实已被禁用 */
  if (tmp_hal_status == HAL_OK)
  {
    /* 禁用ADC DMA模式 */
    CLEAR_BIT(hadc->Instance->CR2, ADC_CR2_DMA);
    
    /* 禁用DMA通道（防止DMA处于循环模式或DMA传输正在进行时停止失败） */
    if (hadc->DMA_Handle->State == HAL_DMA_STATE_BUSY)
    {
      tmp_hal_status = HAL_DMA_Abort(hadc->DMA_Handle);
      
      /* 检查DMA通道是否确实已被禁用 */
      if (tmp_hal_status == HAL_OK)
      {
        /* 设置ADC状态 */
        ADC_STATE_CLR_SET(hadc->State,
                          HAL_ADC_STATE_REG_BUSY | HAL_ADC_STATE_INJ_BUSY,
                          HAL_ADC_STATE_READY);
      }
      else
      {
        /* 更新ADC状态机为错误状态 */
        SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
      }
    }
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
    
  /* 返回函数执行状态 */
  return tmp_hal_status;
}

/**
  * @brief  获取ADC常规组的转换结果。
  * @note   读取DR寄存器会自动清除ADC标志位EOC
  *         (ADC常规组单元转换结束标志)。
  * @note   此函数不会清除ADC标志位EOS 
  *         (ADC常规组序列转换结束标志)。
  *         EOS标志出现的时机：
  *          - 如果序列器只配置了1个通道，EOS标志等同于EOC标志。
  *          - 如果序列器配置了多个通道，在扫描序列期间只会升起EOC标志，
  *            在扫描序列结束时，EOC和EOS标志都会升起。
  *         清除此标志的方法： 
  *         中断编程模式下使用：@ref HAL_ADC_IRQHandler()，
  *         轮询编程模式下使用：@ref HAL_ADC_PollForConversion() 
  *         或者 @ref __HAL_ADC_CLEAR_FLAG(&hadc, ADC_FLAG_EOS)。
  * @param  hadc: ADC句柄指针
  * @retval ADC常规组转换数据
  */
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef* hadc)
{
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));

  /* 注意: 此处软件不清除EOC标志，因为硬件在读取DR寄存器时会自动清除 */
  
  /* 返回ADC转换值 */ 
  return hadc->Instance->DR;
}

/**
  * @brief  处理ADC中断请求  
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
void HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc)
{
  uint32_t tmp_sr = hadc->Instance->SR; // 读取ADC状态寄存器
  uint32_t tmp_cr1 = hadc->Instance->CR1; // 读取ADC控制寄存器1

  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_FUNCTIONAL_STATE(hadc->Init.ContinuousConvMode));
  assert_param(IS_ADC_REGULAR_NB_CONV(hadc->Init.NbrOfConversion));
  
  
  /* ========== 检查常规组的转换结束标志 ========== */
  if((tmp_cr1 & ADC_IT_EOC) == ADC_IT_EOC) // 检查是否使能了EOC中断
  {
    if((tmp_sr & ADC_FLAG_EOC) == ADC_FLAG_EOC) // 检查是否产生了EOC标志
    {
      /* 如果不在内部错误状态，则更新转换状态的状态机 */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL))
      {
        /* 设置ADC状态：常规组转换完成 */
        SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC); 
      }
      
      /* 确定常规组是否还有后续转换 */
      /* 通过外部触发、连续模式或扫描序列正在进行来判断 */
      /* 注意: 在STM32F1设备上，如果序列器使能（选择了多个通道），转换结束标志会在序列结束时升起 */
      if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        && 
         (hadc->Init.ContinuousConvMode == DISABLE)   )
      {
        /* 禁用ADC常规组的转换结束中断 */
        __HAL_ADC_DISABLE_IT(hadc, ADC_IT_EOC);
        
        /* 设置ADC状态：清除常规组忙标志 */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);   
        
        /* 如果注入组也不忙，则设置ADC为就绪状态 */
        if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_INJ_BUSY))
        {
          SET_BIT(hadc->State, HAL_ADC_STATE_READY);
        }
      }

      /* 转换完成回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->ConvCpltCallback(hadc);
#else
      HAL_ADC_ConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* 清除常规组转换标志 */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_STRT | ADC_FLAG_EOC);
    }
  }
  
  /* ========== 检查注入组的转换结束标志 ========== */
  if((tmp_cr1 & ADC_IT_JEOC) == ADC_IT_JEOC) // 检查是否使能了JEQC中断
  {
    if((tmp_sr & ADC_FLAG_JEOC) == ADC_FLAG_JEOC) // 检查是否产生了JEQC标志
    {
      /* 如果不在内部错误状态，则更新转换状态的状态机 */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL))
      {
        /* 设置ADC状态：注入组转换完成 */
        SET_BIT(hadc->State, HAL_ADC_STATE_INJ_EOC);
      }

      /* 确定注入组是否还有后续转换 */
      /* 通过外部触发、扫描序列正在进行或来自常规组的自动注入转换判断 */
      /* (与上面常规组中断禁用的条件相同) */
      /* 注意: 在STM32F1设备上，如果序列器使能（选择了多个通道），转换结束标志会在序列结束时升起 */
      if(ADC_IS_SOFTWARE_START_INJECTED(hadc)                     || 
         (HAL_IS_BIT_CLR(hadc->Instance->CR1, ADC_CR1_JAUTO) &&     
         (ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&
          (hadc->Init.ContinuousConvMode == DISABLE)   )        )   )
      {
        /* 禁用ADC注入组的转换结束中断 */
        __HAL_ADC_DISABLE_IT(hadc, ADC_IT_JEOC);
        
        /* 设置ADC状态：清除注入组忙标志 */
        CLEAR_BIT(hadc->State, HAL_ADC_STATE_INJ_BUSY);   

        /* 如果常规组也不忙，则设置ADC为就绪状态 */
        if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_REG_BUSY))
        { 
          SET_BIT(hadc->State, HAL_ADC_STATE_READY);
        }
      }

      /* 转换完成回调函数 */ 
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->InjectedConvCpltCallback(hadc);
#else
      HAL_ADCEx_InjectedConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* 清除注入组转换标志 */
      __HAL_ADC_CLEAR_FLAG(hadc, (ADC_FLAG_JSTRT | ADC_FLAG_JEOC));
    }
  }
   
  /* ========== 检查模拟看门狗标志 ========== */
  if((tmp_cr1 & ADC_IT_AWD) == ADC_IT_AWD) // 检查是否使能了AWD中断
  {
    if((tmp_sr & ADC_FLAG_AWD) == ADC_FLAG_AWD) // 检查是否产生了AWD标志
    {
      /* 设置ADC状态：模拟看门狗标志位 */
      SET_BIT(hadc->State, HAL_ADC_STATE_AWD1);
      
      /* 超出窗口回调函数 */ 
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
      hadc->LevelOutOfWindowCallback(hadc);
#else
      HAL_ADC_LevelOutOfWindowCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
      
      /* 清除ADC模拟看门狗标志 */
      __HAL_ADC_CLEAR_FLAG(hadc, ADC_FLAG_AWD);
    }
  }
  
}

/**
  * @brief  非阻塞模式下的转换完成回调函数 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_ConvCpltCallback必须在用户文件中实现。
   */
}

/**
  * @brief  非阻塞模式下的转换DMA半传输回调函数 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_ConvHalfCpltCallback必须在用户文件中实现。
  */
}

/**
  * @brief  非阻塞模式下的模拟看门狗回调函数。 
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_LevelOutOfWindowCallback必须在用户文件中实现。
  */
}

/**
  * @brief  非阻塞模式下的ADC错误回调函数
  *         (带中断的ADC转换或DMA传输)
  * @param  hadc: ADC句柄指针
  * @retval 无
  */
__weak void HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc)
{
  /* 防止未使用的参数产生编译警告 */
  UNUSED(hadc);
  /* 注意: 此函数不应被修改。当需要回调时，
           函数HAL_ADC_ErrorCallback必须在用户文件中实现。
  */
}


/**
  * @}
  */

/** @defgroup ADC_Exported_Functions_Group3 Peripheral Control functions
 *  @brief    外设控制函数
 *
@verbatim   
 ===============================================================================
             ##### 外设控制函数 #####
 ===============================================================================  
    [..]  本节提供以下功能函数：
      (+) 配置常规组通道
      (+) 配置模拟看门狗
      
@endverbatim
  * @{
  */

/**
  * @brief  配置选定的通道链接到常规组。
  * @note   如果使用内部测量通道：
  *         Vbat/VrefInt/TempSensor。
  *         这些内部路径可以使用函数HAL_ADC_DeInit()禁用。
  * @note   可以动态更新参数：
  *         此函数将通道初始化到常规组中，后续调用此函数可以
  *         动态地重新配置结构体"ADC_ChannelConfTypeDef"的某些参数，
  *         而无需复位ADC。
  *         这些参数的设置受ADC状态限制。
  *         有关参数约束，请参阅结构体"ADC_ChannelConfTypeDef"的注释。
  * @param  hadc: ADC句柄指针
  * @param  sConfig: ADC常规组通道配置结构体指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig)
{ 
  HAL_StatusTypeDef tmp_hal_status = HAL_OK;
  __IO uint32_t wait_loop_index = 0U; // 用于延时等待的循环变量
  
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance));
  assert_param(IS_ADC_CHANNEL(sConfig->Channel)); // 检查通道号
  assert_param(IS_ADC_REGULAR_RANK(sConfig->Rank)); // 检查序列排名
  assert_param(IS_ADC_SAMPLE_TIME(sConfig->SamplingTime)); // 检查采样时间
  
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
/* 规则序列配置 */
  /* 对于排名 1 到 6 的通道 */
  if (sConfig->Rank < 7U)
  {
    /* 修改SQR3寄存器，配置排名1-6的通道 */
    MODIFY_REG(hadc->Instance->SQR3                        ,  // SQR3寄存器存放第1-6个转换通道
               ADC_SQR3_RK(ADC_SQR3_SQ1, sConfig->Rank)    ,  // 清除对应排名的通道位
               ADC_SQR3_RK(sConfig->Channel, sConfig->Rank) ); // 设置对应排名的通道号
  }
  /* 对于排名 7 到 12 的通道 */
  else if (sConfig->Rank < 13U)
  {
    /* 修改SQR2寄存器，配置排名7-12的通道 */
    MODIFY_REG(hadc->Instance->SQR2                        ,  // SQR2寄存器存放第7-12个转换通道
               ADC_SQR2_RK(ADC_SQR2_SQ7, sConfig->Rank)    ,  // 清除对应排名的通道位
               ADC_SQR2_RK(sConfig->Channel, sConfig->Rank) ); // 设置对应排名的通道号
  }
  /* 对于排名 13 到 16 的通道 */
  else
  {
    /* 修改SQR1寄存器，配置排名13-16的通道 */
    MODIFY_REG(hadc->Instance->SQR1                        ,  // SQR1寄存器存放第13-16个转换通道
               ADC_SQR1_RK(ADC_SQR1_SQ13, sConfig->Rank)   ,  // 清除对应排名的通道位
               ADC_SQR1_RK(sConfig->Channel, sConfig->Rank) ); // 设置对应排名的通道号
  }
  
  
  /* 通道采样时间配置 */
  /* 对于通道 10 到 17 */
  if (sConfig->Channel >= ADC_CHANNEL_10)
  {
    /* 修改SMPR1寄存器，配置通道10-17的采样时间 */
    MODIFY_REG(hadc->Instance->SMPR1                             ,
               ADC_SMPR1(ADC_SMPR1_SMP10, sConfig->Channel)      ,  // 清除对应通道的采样时间位
               ADC_SMPR1(sConfig->SamplingTime, sConfig->Channel) ); // 设置对应通道的采样时间
  }
  else /* 对于通道 0 到 9 */
  {
    /* 修改SMPR2寄存器，配置通道0-9的采样时间 */
    MODIFY_REG(hadc->Instance->SMPR2                             ,
               ADC_SMPR2(ADC_SMPR2_SMP0, sConfig->Channel)       ,  // 清除对应通道的采样时间位
               ADC_SMPR2(sConfig->SamplingTime, sConfig->Channel) ); // 设置对应通道的采样时间
  }
  
  /* 如果选择了ADC1的通道16或通道17，则使能温度传感器和内部参考电压测量路径 */
  if ((sConfig->Channel == ADC_CHANNEL_TEMPSENSOR) ||
      (sConfig->Channel == ADC_CHANNEL_VREFINT)      )
  {
    /* 对于具有多个ADC的STM32F1设备：只有ADC1能访问内部测量通道(VrefInt/TempSensor)。
       如果试图在其他ADC实例上设置这些通道，则报告错误。 */
    if (hadc->Instance == ADC1)
    {
      /* 检查TSVREFE位是否已置位，避免重复配置 */
      if (READ_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE) == RESET)
      {
        /* 使能温度传感器和VREFINT通道 */
        SET_BIT(hadc->Instance->CR2, ADC_CR2_TSVREFE);
        
        /* 如果是温度传感器通道，需要等待其稳定 */
        if (sConfig->Channel == ADC_CHANNEL_TEMPSENSOR)
        {
          /* 延时等待温度传感器稳定时间 */
          /* 计算需要等待的CPU时钟周期数 */
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
      /* 如果不是ADC1，则更新ADC状态机为配置错误 */
      SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_CONFIG);
      
      /* 返回错误状态 */
      tmp_hal_status = HAL_ERROR;
    }
  }
  
  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return tmp_hal_status;
}

/**
  * @brief  配置模拟看门狗
  * @note   模拟看门狗阈值可以在ADC转换进行时修改。
  *         在这种情况下，必须考虑到一些限制：
  *         编程的阈值将在下一个ADC EOC(单元转换结束)后生效。
  *         考虑到由于总线活动可能发生寄存器写入延迟，这可能会导致新编程阈值值的实际定时存在不确定性。
  * @param  hadc: ADC句柄指针
  * @param  AnalogWDGConfig: ADC模拟看门狗配置结构体指针
  * @retval HAL状态
  */
HAL_StatusTypeDef HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig)
{
  /* 检查参数合法性 */
  assert_param(IS_ADC_ALL_INSTANCE(hadc->Instance)); // 检查ADC实例是否有效
  assert_param(IS_ADC_ANALOG_WATCHDOG_MODE(AnalogWDGConfig->WatchdogMode)); // 检查看门狗模式
  assert_param(IS_FUNCTIONAL_STATE(AnalogWDGConfig->ITMode)); // 检查中断模式使能状态
  assert_param(IS_ADC_RANGE(AnalogWDGConfig->HighThreshold)); // 检查高阈值是否在有效范围
  assert_param(IS_ADC_RANGE(AnalogWDGConfig->LowThreshold)); // 检查低阈值是否在有效范围
  
  /* 如果看门狗模式配置为单通道模式(常规或注入或两者)，则需要检查通道号 */
  if((AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REG)     ||
     (AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_INJEC)   ||
     (AnalogWDGConfig->WatchdogMode == ADC_ANALOGWATCHDOG_SINGLE_REGINJEC)  )
  {
    assert_param(IS_ADC_CHANNEL(AnalogWDGConfig->Channel));
  }
  
  /* 锁定进程 */
  __HAL_LOCK(hadc);
  
  /* 模拟看门狗配置 */

  /* 配置ADC模拟看门狗中断 */
  if(AnalogWDGConfig->ITMode == ENABLE)
  {
    /* 使能ADC模拟看门狗中断 */
    __HAL_ADC_ENABLE_IT(hadc, ADC_IT_AWD);
  }
  else
  {
    /* 禁用ADC模拟看门狗中断 */
    __HAL_ADC_DISABLE_IT(hadc, ADC_IT_AWD);
  }
  
  /* 模拟看门狗的配置：                                        */
  /*  - 设置模拟看门狗使能模式：常规组和/或注入组，单通道或所有通道  */
  /*  - 设置模拟看门狗通道 (如果模式为"所有通道": ADC_CFGR_AWD1SGL=0，则不使用此设置) */
  MODIFY_REG(hadc->Instance->CR1            , // 修改CR1寄存器
             ADC_CR1_AWDSGL | // 单通道看门狗选择位
             ADC_CR1_JAWDEN | // 注入组看门狗使能位
             ADC_CR1_AWDEN  | // 常规组看门狗使能位
             ADC_CR1_AWDCH  , // 看门狗通道选择位
             AnalogWDGConfig->WatchdogMode | // 设置看门狗模式
             AnalogWDGConfig->Channel        ); // 设置看门狗监控的通道
  
  /* 设置高阈值 */
  WRITE_REG(hadc->Instance->HTR, AnalogWDGConfig->HighThreshold);
  
  /* 设置低阈值 */
  WRITE_REG(hadc->Instance->LTR, AnalogWDGConfig->LowThreshold);

  /* 解锁进程 */
  __HAL_UNLOCK(hadc);
  
  /* 返回函数状态 */
  return HAL_OK;
}


/**
  * @}
  */


/** @defgroup ADC_Exported_Functions_Group4 Peripheral State functions
  * @brief    外设状态函数
  *
@verbatim
 ===============================================================================
            ##### 外设状态和错误函数 #####
 ===============================================================================  
    [..]
    本小节提供在运行时获取外设状态的函数。
      (+) 检查ADC状态
      (+) 检查ADC错误代码

@endverbatim
  * @{
  */

/**
  * @brief  返回ADC状态
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
uint32_t HAL_ADC_GetState(ADC_HandleTypeDef* hadc)
{
  /* 返回ADC状态 */
  return hadc->State;
}

/**
  * @brief  返回ADC错误代码
  * @param  hadc: ADC句柄指针
  * @retval ADC错误代码
  */
uint32_t HAL_ADC_GetError(ADC_HandleTypeDef *hadc)
{
  return hadc->ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions ADC Private Functions
  * @{
  */

/**
  * @brief  使能选定的ADC
  * @note   使用此函数的前提条件：ADC必须处于禁用状态，且稳压器必须已使能(在HAL_ADC_Init()中完成)。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U; // 用于超时计时的变量
  __IO uint32_t wait_loop_index = 0U; // 用于延时循环的变量
  
  /* ADC使能并等待ADC就绪(如果ADC处于禁用状态或使能阶段尚未完成：就绪标志尚未置位) */
  /* 实施超时机制以避免在ADC无法使能时卡死(可能原因：ADC时钟未运行等) */
  if (ADC_IS_ENABLE(hadc) == RESET)
  {
    /* 使能外设 */
    __HAL_ADC_ENABLE(hadc);
    
    /* 延时等待ADC稳定时间 */
    /* 计算需要等待的CPU时钟周期数 */
    wait_loop_index = (ADC_STAB_DELAY_US * (SystemCoreClock / 1000000U));
    while(wait_loop_index != 0U)
    {
      wait_loop_index--;
    }
    
    /* 获取当前滴答数 */
    tickstart = HAL_GetTick();

    /* 等待ADC有效使能 */
    while(ADC_IS_ENABLE(hadc) == RESET)
    {
      /* 检查是否超时 */
      if((HAL_GetTick() - tickstart) > ADC_ENABLE_TIMEOUT)
      {
        /* 新的检查以避免在发生抢占时出现错误的超时检测 */
        if(ADC_IS_ENABLE(hadc) == RESET)
        {
          /* 更新ADC状态机为内部错误 */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* 设置ADC错误代码为ADC IP内部错误 */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          /* 解锁进程 */
          __HAL_UNLOCK(hadc);

          return HAL_ERROR;
        }
      }
    }
  }
   
  /* 返回HAL状态 */
  return HAL_OK;
}

/**
  * @brief  停止ADC转换并禁用选定的ADC
  * @note   使用此函数的前提条件：必须停止ADC转换才能禁用ADC。
  * @param  hadc: ADC句柄指针
  * @retval HAL状态
  */
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc)
{
  uint32_t tickstart = 0U; // 用于超时计时的变量
  
  /* 验证ADC是否尚未禁用 */
  if (ADC_IS_ENABLE(hadc) != RESET)
  {
    /* 禁用ADC外设 */
    __HAL_ADC_DISABLE(hadc);
     
    /* 获取当前滴答数 */
    tickstart = HAL_GetTick();
    
    /* 等待ADC有效禁用 */
    while(ADC_IS_ENABLE(hadc) != RESET)
    {
      /* 检查是否超时 */
      if((HAL_GetTick() - tickstart) > ADC_DISABLE_TIMEOUT)
      {
        /* 新的检查以避免在发生抢占时出现错误的超时检测 */
        if(ADC_IS_ENABLE(hadc) != RESET)
        {
          /* 更新ADC状态机为内部错误 */
          SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL);

          /* 设置ADC错误代码为ADC IP内部错误 */
          SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_INTERNAL);

          return HAL_ERROR;
        }
      }
    }
  }
  
  /* 返回HAL状态 */
  return HAL_OK;
}

/**
  * @brief  DMA传输完成回调函数
  * @param  hdma: 指向DMA句柄的指针
  * @retval 无
  */
void ADC_DMAConvCplt(DMA_HandleTypeDef *hdma)
{
  /* 获取当前DMA句柄对应的ADC句柄 */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
 
  /* 如果未处于错误状态，则更新转换状态的状态机 */
  if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_ERROR_INTERNAL | HAL_ADC_STATE_ERROR_DMA))
  {
    /* 更新ADC状态机：常规组转换结束 */
    SET_BIT(hadc->State, HAL_ADC_STATE_REG_EOC);
    
    /* 确定是否还有即将进行的常规组转换(通过外部触发、连续模式或正在进行的扫描序列) */
    /* 注意：在STM32F1设备上，如果排序器使能(选择了多个排名)，转换结束标志在序列结束时置起 */
    if(ADC_IS_SOFTWARE_START_REGULAR(hadc)        &&  // 如果是软件触发
       (hadc->Init.ContinuousConvMode == DISABLE)   )  // 且非连续转换模式
    {
      /* 设置ADC状态：清除常规组忙标志 */
      CLEAR_BIT(hadc->State, HAL_ADC_STATE_REG_BUSY);   
      
      /* 如果注入组也不忙，则设置ADC为就绪状态 */
      if (HAL_IS_BIT_CLR(hadc->State, HAL_ADC_STATE_INJ_BUSY))
      {
        SET_BIT(hadc->State, HAL_ADC_STATE_READY);
      }
    }
    
    /* 转换完成回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvCpltCallback(hadc);
#else
    HAL_ADC_ConvCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
  }
  else
  {
    /* 调用DMA错误回调函数 */
    hadc->DMA_Handle->XferErrorCallback(hdma);
  }
}

/**
  * @brief  DMA半传输完成回调函数
  * @param  hdma: 指向DMA句柄的指针
  * @retval 无
  */
void ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma)   
{
  /* 获取当前DMA句柄对应的ADC句柄 */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  
  /* 半转换回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
    hadc->ConvHalfCpltCallback(hadc);
#else
  HAL_ADC_ConvHalfCpltCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

/**
  * @brief  DMA错误回调函数
  * @param  hdma: 指向DMA句柄的指针
  * @retval 无
  */
void ADC_DMAError(DMA_HandleTypeDef *hdma)   
{
  /* 获取当前DMA句柄对应的ADC句柄 */
  ADC_HandleTypeDef* hadc = ( ADC_HandleTypeDef* )((DMA_HandleTypeDef* )hdma)->Parent;
  
  /* 设置ADC状态：DMA错误 */
  SET_BIT(hadc->State, HAL_ADC_STATE_ERROR_DMA);
  
  /* 设置ADC错误代码为DMA错误 */
  SET_BIT(hadc->ErrorCode, HAL_ADC_ERROR_DMA);
  
  /* 错误回调函数 */
#if (USE_HAL_ADC_REGISTER_CALLBACKS == 1)
  hadc->ErrorCallback(hadc);
#else
  HAL_ADC_ErrorCallback(hadc);
#endif /* USE_HAL_ADC_REGISTER_CALLBACKS */
}

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
