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
