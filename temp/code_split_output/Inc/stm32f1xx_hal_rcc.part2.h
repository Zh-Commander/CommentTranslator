/**
  * @brief  配置外部低速振荡器(LSE)的宏。
  * @note   此宏不支持从 LSE Bypass（旁路模式）转换到 LSE On（开启模式），
            也不支持从 LSE On 转换到 LSE Bypass。
  * @note   由于 LSE 位于备份域，复位后对该域的写访问被禁止，
            因此在配置 LSE 之前，必须使用 @ref HAL_PWR_EnableBkUpAccess() 函数
            使能写访问（复位后只需执行一次）。
  * @note   在使能 LSE (RCC_LSE_ON 或 RCC_LSE_BYPASS) 后，应用程序软件
            应等待 LSERDY 标志置位，这表明 LSE 时钟已稳定，
            可用于驱动 RTC。
  * @param  __STATE__ 指定 LSE 的新状态。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_LSE_OFF 关闭 LSE 振荡器，LSERDY 标志在
  *                              6 个 LSE 振荡器时钟周期后变低。
  *            @arg @ref RCC_LSE_ON 开启 LSE 振荡器。
  *            @arg @ref RCC_LSE_BYPASS LSE 振荡器被外部时钟旁路。
  */
#define __HAL_RCC_LSE_CONFIG(__STATE__)                                     \
                    do{                                                     \
                      if ((__STATE__) == RCC_LSE_ON)                        \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_OFF)                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                      else if ((__STATE__) == RCC_LSE_BYPASS)               \
                      {                                                     \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                  \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);                   \
                      }                                                     \
                      else                                                  \
                      {                                                     \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                 \
                        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                \
                      }                                                     \
                    }while(0U)

/**
  * @}
  */

/** @defgroup RCC_PLL_Configuration PLL 配置
  * @{
  */

/** @brief 使能主 PLL 的宏。
  * @note   在使能主 PLL 后，应用程序软件应等待 PLLRDY 标志置位，
            这表明 PLL 时钟已稳定，可用作系统时钟源。
  * @note   进入停止(STOP)和待机(STANDBY)模式时，硬件会自动禁用主 PLL。
  */
#define __HAL_RCC_PLL_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLON_BB = ENABLE)

/** @brief 禁用主 PLL 的宏。
  * @note   如果主 PLL 被用作系统时钟源，则不能被禁用。
  */
#define __HAL_RCC_PLL_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLON_BB = DISABLE)

/** @brief 配置主 PLL 时钟源和倍频因子的宏。
  * @note   此函数必须仅在主 PLL 被禁用时使用。
  *
  * @param  __RCC_PLLSOURCE__ 指定 PLL 输入时钟源。
  *          该参数可以是以下值之一:
  *            @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI 振荡器时钟经2分频后作为 PLL 输入时钟
  *            @arg @ref RCC_PLLSOURCE_HSE HSE 振荡器时钟作为 PLL 输入时钟
  * @param  __PLLMUL__ 指定 PLL VCO 输出时钟的倍频因子
  *          该参数可以是以下值之一:
  *             @arg @ref RCC_PLL_MUL4   PLLVCO = PLL 输入时钟 x 4
  *             @arg @ref RCC_PLL_MUL6   PLLVCO = PLL 输入时钟 x 6
  @if STM32F105xC
  *             @arg @ref RCC_PLL_MUL6_5 PLLVCO = PLL 输入时钟 x 6.5
  @elseif STM32F107xC
  *             @arg @ref RCC_PLL_MUL6_5 PLLVCO = PLL 输入时钟 x 6.5
  @else
  *             @arg @ref RCC_PLL_MUL2   PLLVCO = PLL 输入时钟 x 2
  *             @arg @ref RCC_PLL_MUL3   PLLVCO = PLL 输入时钟 x 3
  *             @arg @ref RCC_PLL_MUL10  PLLVCO = PLL 输入时钟 x 10
  *             @arg @ref RCC_PLL_MUL11  PLLVCO = PLL 输入时钟 x 11
  *             @arg @ref RCC_PLL_MUL12  PLLVCO = PLL 输入时钟 x 12
  *             @arg @ref RCC_PLL_MUL13  PLLVCO = PLL 输入时钟 x 13
  *             @arg @ref RCC_PLL_MUL14  PLLVCO = PLL 输入时钟 x 14
  *             @arg @ref RCC_PLL_MUL15  PLLVCO = PLL 输入时钟 x 15
  *             @arg @ref RCC_PLL_MUL16  PLLVCO = PLL 输入时钟 x 16
  @endif
  *             @arg @ref RCC_PLL_MUL8   PLLVCO = PLL 输入时钟 x 8
  *             @arg @ref RCC_PLL_MUL9   PLLVCO = PLL 输入时钟 x 9
  *
  */
#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSOURCE__, __PLLMUL__)\
          MODIFY_REG(RCC->CFGR, (RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL),((__RCC_PLLSOURCE__) | (__PLLMUL__) ))

/** @brief  获取选作 PLL 输入时钟的振荡器时钟
  * @retval 用于 PLL 输入的时钟源。返回值可以是以下值之一:
  *             @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI 振荡器时钟被选为 PLL 输入时钟
  *             @arg @ref RCC_PLLSOURCE_HSE HSE 振荡器时钟被选为 PLL 输入时钟
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PLLSRC)))

/**
  * @}
  */

/** @defgroup RCC_Get_Clock_source 获取时钟源
  * @{
  */

/**
  * @brief  配置系统时钟源的宏。
  * @param  __SYSCLKSOURCE__ 指定系统时钟源。
  *          该参数可以是以下值之一:
  *              @arg @ref RCC_SYSCLKSOURCE_HSI HSI 振荡器用作系统时钟源。
  *              @arg @ref RCC_SYSCLKSOURCE_HSE HSE 振荡器用作系统时钟源。
  *              @arg @ref RCC_SYSCLKSOURCE_PLLCLK PLL 输出用作系统时钟源。
  */
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))

/** @brief  获取用作系统时钟的时钟源。
  * @retval 用作系统时钟的时钟源。返回值可以是以下值之一:
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSI HSI 用作系统时钟
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSE HSE 用作系统时钟
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_PLLCLK PLL 用作系统时钟
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR,RCC_CFGR_SWS)))

/**
  * @}
  */

/** @defgroup RCCEx_MCOx_Clock_Config RCC 扩展 MCOx 时钟配置
  * @{
  */

#if   defined(RCC_CFGR_MCO_3)
/** @brief  配置 MCO 时钟的宏。
  * @param  __MCOCLKSOURCE__ 指定 MCO 时钟源。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK      无时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK       系统时钟 (SYSCLK) 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSI          HSI 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSE          HSE 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK       PLL 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLL2CLK      PLL2 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK_DIV2 PLL3 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_EXT_HSE XT1  外部 3-25 MHz 振荡器时钟被选为 MCO 时钟 (用于以太网)
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK      PLL3 时钟被选为 MCO 时钟 (用于以太网)
  * @param  __MCODIV__ 指定 MCO 时钟预分频器。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCODIV_1 MCO 时钟源不分频
  */
#else
/** @brief  配置 MCO 时钟的宏。
  * @param  __MCOCLKSOURCE__ 指定 MCO 时钟源。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK 无时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK  系统时钟 (SYSCLK) 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSI HSI 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSE HSE 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK  PLL 时钟 2 分频被选为 MCO 时钟
  * @param  __MCODIV__ 指定 MCO 时钟预分频器。
  *         该参数可以是以下值之一:
  *            @arg @ref RCC_MCODIV_1 MCO 时钟源不分频
  */
#endif

#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, (__MCOCLKSOURCE__))


/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Configuration RCC RTC 时钟配置
* @{
*/

/** @brief 配置 RTC 时钟 (RTCCLK) 的宏。
  * @note   由于 RTC 时钟配置位位于备份域，复位后对该域的写访问被禁止，
            因此在配置 RTC 时钟源之前，必须使用电源备份访问宏使能写访问
            （复位后只需执行一次）。
  * @note   一旦 RTC 时钟配置完成，除非使用 @ref __HAL_RCC_BACKUPRESET_FORCE() 宏
            复位备份域，或上电复位 (POR)，否则无法更改。
  *
  * @param  __RTC_CLKSOURCE__ 指定 RTC 时钟源。
  *          该参数可以是以下值之一:
  *             @arg @ref RCC_RTCCLKSOURCE_NO_CLK 无时钟被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_LSE LSE 被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_LSI LSI 被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE 128 分频被选为 RTC 时钟
  * @note   如果 LSE 或 LSI 用作 RTC 时钟源，RTC 在停止(STOP)和待机(STANDBY)模式下
            继续工作，并可用作唤醒源。
            然而，当 HSE 时钟用作 RTC 时钟源时，RTC 不能在停止和待机模式下使用。
  * @note   RTC 的最大输入时钟频率为 1MHz (当使用 HSE 作为 RTC 时钟源时)。
  */
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__) MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))

/** @brief 获取 RTC 时钟源的宏。
  * @retval 时钟源可以是以下值之一:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK 无时钟被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_LSE LSE 被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_LSI LSI 被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE 128 分频被选为 RTC 时钟
  */
#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

/** @brief 使能 RTC 时钟的宏。
  * @note   这些宏必须在选择了 RTC 时钟源之后使用。
  */
#define __HAL_RCC_RTC_ENABLE()          (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = ENABLE)

/** @brief 禁用 RTC 时钟的宏。
  * @note  这些宏必须在选择了 RTC 时钟源之后使用。
  */
#define __HAL_RCC_RTC_DISABLE()         (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = DISABLE)

/** @brief  强制备份域复位的宏。
  * @note   此函数复位 RTC 外设（包括备份寄存器）
            以及 RCC_BDCR 寄存器中的 RTC 时钟源选择。
  */
#define __HAL_RCC_BACKUPRESET_FORCE()   (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = ENABLE)

/** @brief  释放备份域复位的宏。
  */
#define __HAL_RCC_BACKUPRESET_RELEASE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = DISABLE)

/**
  * @}
  */

/** @defgroup RCC_Flags_Interrupts_Management 标志与中断管理
  * @brief 管理指定 RCC 标志和中断的宏。
  * @{
  */

/** @brief 使能 RCC 中断。
  * @param  __INTERRUPT__ 指定要使能的 RCC 中断源。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))

/** @brief 禁用 RCC 中断。
  * @param  __INTERRUPT__ 指定要禁用的 RCC 中断源。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))

/** @brief 清除 RCC 的中断挂起位。
  * @param  __INTERRUPT__ 指定要清除的中断挂起位。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断。
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断。
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断。
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断。
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断。
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  *            @arg @ref RCC_IT_CSS 时钟安全系统中断
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))

/** @brief 检查 RCC 中断是否发生。
  * @param  __INTERRUPT__ 指定要检查的 RCC 中断源。
  *          该参数可以是以下值之一:
  *            @arg @ref RCC_IT_LSIRDY LSI 就绪中断。
  *            @arg @ref RCC_IT_LSERDY LSE 就绪中断。
  *            @arg @ref RCC_IT_HSIRDY HSI 就绪中断。
  *            @arg @ref RCC_IT_HSERDY HSE 就绪中断。
  *            @arg @ref RCC_IT_PLLRDY 主 PLL 就绪中断。
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY 主 PLL2 就绪中断。
  *            @arg @ref RCC_IT_PLLI2S2RDY 主 PLLI2S 就绪中断。
  @endif
  *            @arg @ref RCC_IT_CSS 时钟安全系统中断
  * @retval __INTERRUPT__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief 设置 RMVF 位以清除复位标志。
  *         复位标志包括 RCC_FLAG_PINRST, RCC_FLAG_PORRST, RCC_FLAG_SFTRST,
  *         RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST, RCC_FLAG_LPWRRST
  */
#define __HAL_RCC_CLEAR_RESET_FLAGS() (*(__IO uint32_t *)RCC_CSR_RMVF_BB = ENABLE)

/** @brief  检查 RCC 标志是否置位。
  * @param  __FLAG__ 指定要检查的标志。
  *          该参数可以是以下值之一:
  *            @arg @ref RCC_FLAG_HSIRDY HSI 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_HSERDY HSE 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_PLLRDY 主 PLL 时钟就绪。
  @if STM32F105xx
  *            @arg @ref RCC_FLAG_PLL2RDY 主 PLL2 时钟就绪。
  *            @arg @ref RCC_FLAG_PLLI2SRDY 主 PLLI2S 时钟就绪。
  @elsif STM32F107xx
  *            @arg @ref RCC_FLAG_PLL2RDY 主 PLL2 时钟就绪。
  *            @arg @ref RCC_FLAG_PLLI2SRDY 主 PLLI2S 时钟就绪。
  @endif
  *            @arg @ref RCC_FLAG_LSERDY LSE 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_LSIRDY LSI 振荡器时钟就绪。
  *            @arg @ref RCC_FLAG_PINRST  引脚复位。
  *            @arg @ref RCC_FLAG_PORRST  POR/PDR 复位。
  *            @arg @ref RCC_FLAG_SFTRST  软件复位。
  *            @arg @ref RCC_FLAG_IWDGRST 独立看门狗复位。
  *            @arg @ref RCC_FLAG_WWDGRST 窗口看门狗复位。
  *            @arg @ref RCC_FLAG_LPWRRST 低功耗复位。
  * @retval __FLAG__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((__FLAG__) >> 5U) == CR_REG_INDEX)?   RCC->CR   : \
                                      ((((__FLAG__) >> 5U) == BDCR_REG_INDEX)? RCC->BDCR : \
                                                                              RCC->CSR)) & (1U << ((__FLAG__) & RCC_FLAG_MASK)))

/**
  * @}
  */

/**
  * @}
  */

/* 包含 RCC HAL 扩展模块 */
#include "stm32f1xx_hal_rcc_ex.h"

/* 导出的函数 --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */

/* 初始化和反初始化函数  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* 外设控制函数  ************************************************/
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
void              HAL_RCC_DisableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

/* CSS NMI IRQ 处理程序 */
void              HAL_RCC_NMI_IRQHandler(void);

/* 非阻塞模式下的用户回调函数 (中断模式) */
void              HAL_RCC_CSSCallback(void);

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCC_Private_Constants
  * @{
  */

/** @defgroup RCC_Timeout RCC 超时
  * @{
  */

/* 禁用备份域写保护状态改变的超时时间 */
#define RCC_DBP_TIMEOUT_VALUE          100U    /* 100 ms */
/* LSE 状态改变的超时时间 */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
#define CLOCKSWITCH_TIMEOUT_VALUE      5000    /* 5 s    */
#define HSE_TIMEOUT_VALUE              HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE              2U      /* 2 ms (最小 Tick + 1) */
#define LSI_TIMEOUT_VALUE              2U      /* 2 ms (最小 Tick + 1) */
#define PLL_TIMEOUT_VALUE              2U      /* 2 ms (最小 Tick + 1) */

/**
  * @}
  */

/** @defgroup RCC_Register_Offset 寄存器偏移
  * @{
  */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE) // RCC 基地址相对于外设基地址的偏移
#define RCC_CR_OFFSET             0x00U // CR 寄存器偏移
#define RCC_CFGR_OFFSET           0x04U // CFGR 寄存器偏移
#define RCC_CIR_OFFSET            0x08U // CIR 寄存器偏移
#define RCC_BDCR_OFFSET           0x20U // BDCR 寄存器偏移
#define RCC_CSR_OFFSET            0x24U // CSR 寄存器偏移

/**
  * @}
  */

/** @defgroup RCC_BitAddress_AliasRegion 位带别名区
  * @brief 别名区中 RCC 寄存器位的地址
  * @{
  */
#define RCC_CR_OFFSET_BB          (RCC_OFFSET + RCC_CR_OFFSET)
#define RCC_CFGR_OFFSET_BB        (RCC_OFFSET + RCC_CFGR_OFFSET)
#define RCC_CIR_OFFSET_BB         (RCC_OFFSET + RCC_CIR_OFFSET)
#define RCC_BDCR_OFFSET_BB        (RCC_OFFSET + RCC_BDCR_OFFSET)
#define RCC_CSR_OFFSET_BB         (RCC_OFFSET + RCC_CSR_OFFSET)

/* --- CR 寄存器 ---*/
/* HSION 位的别名地址 */
#define RCC_HSION_BIT_NUMBER      RCC_CR_HSION_Pos
#define RCC_CR_HSION_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSION_BIT_NUMBER * 4U)))
/* HSEON 位的别名地址 */
#define RCC_HSEON_BIT_NUMBER      RCC_CR_HSEON_Pos
#define RCC_CR_HSEON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSEON_BIT_NUMBER * 4U)))
/* CSSON 位的别名地址 */
#define RCC_CSSON_BIT_NUMBER      RCC_CR_CSSON_Pos
#define RCC_CR_CSSON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_CSSON_BIT_NUMBER * 4U)))
/* PLLON 位的别名地址 */
#define RCC_PLLON_BIT_NUMBER      RCC_CR_PLLON_Pos
#define RCC_CR_PLLON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_PLLON_BIT_NUMBER * 4U)))

/* --- CSR 寄存器 ---*/
/* LSION 位的别名地址 */
#define RCC_LSION_BIT_NUMBER      RCC_CSR_LSION_Pos
#define RCC_CSR_LSION_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_LSION_BIT_NUMBER * 4U)))

/* RMVF 位的别名地址 */
#define RCC_RMVF_BIT_NUMBER       RCC_CSR_RMVF_Pos
#define RCC_CSR_RMVF_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_RMVF_BIT_NUMBER * 4U)))

/* --- BDCR 寄存器 ---*/
/* LSEON 位的别名地址 */
#define RCC_LSEON_BIT_NUMBER      RCC_BDCR_LSEON_Pos
#define RCC_BDCR_LSEON_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEON_BIT_NUMBER * 4U)))

/* LSEBYP 位的别名地址 */
#define RCC_LSEBYP_BIT_NUMBER     RCC_BDCR_LSEBYP_Pos
#define RCC_BDCR_LSEBYP_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEBYP_BIT_NUMBER * 4U)))

/* RTCEN 位的别名地址 */
#define RCC_RTCEN_BIT_NUMBER      RCC_BDCR_RTCEN_Pos
#define RCC_BDCR_RTCEN_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U)))

/* BDRST 位的别名地址 */
#define RCC_BDRST_BIT_NUMBER      RCC_BDCR_BDRST_Pos
#define RCC_BDCR_BDRST_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_BDRST_BIT_NUMBER * 4U)))

/**
  * @}
  */

/* CR 寄存器字节 2 (位[23:16]) 基地址 */
#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))

/* CIR 寄存器字节 1 (位[15:8]) 基地址 */
#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))

/* CIR 寄存器字节 2 (位[23:16]) 基地址 */
#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))

/* 用于标志位的定义 */
#define CR_REG_INDEX                     ((uint8_t)1) // CR 寄存器索引
#define BDCR_REG_INDEX                   ((uint8_t)2) // BDCR 寄存器索引
#define CSR_REG_INDEX                    ((uint8_t)3) // CSR 寄存器索引

#define RCC_FLAG_MASK                    ((uint8_t)0x1F) // 标志位掩码

/**
  * @}
  */

/** @addtogroup RCC_Private_Macros
  * @{
  */
/** @defgroup RCC_Alias_For_Legacy 为兼容性保留的别名定义
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_DISABLE    __HAL_RCC_AFIO_CLK_DISABLE // SYSCFG 时钟禁用(兼容性宏)
#define __HAL_RCC_SYSCFG_CLK_ENABLE     __HAL_RCC_AFIO_CLK_ENABLE // SYSCFG 时钟使能(兼容性宏)
#define __HAL_RCC_SYSCFG_FORCE_RESET    __HAL_RCC_AFIO_FORCE_RESET // SYSCFG 强制复位(兼容性宏)
#define __HAL_RCC_SYSCFG_RELEASE_RESET  __HAL_RCC_AFIO_RELEASE_RESET // SYSCFG 释放复位(兼容性宏)
/**
  * @}
  */

#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_HSI_DIV2) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE)) // 检查是否为有效的 PLL 时钟源
#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)) // 检查是否为有效的振荡器类型
#define IS_RCC_HSE(__HSE__) (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                             ((__HSE__) == RCC_HSE_BYPASS)) // 检查是否为有效的 HSE 状态
#define IS_RCC_LSE(__LSE__) (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                             ((__LSE__) == RCC_LSE_BYPASS)) // 检查是否为有效的 LSE 状态
#define IS_RCC_HSI(__HSI__) (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON)) // 检查是否为有效的 HSI 状态
#define IS_RCC_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 0x1FU) // 检查是否为有效的 HSI 校准值
#define IS_RCC_LSI(__LSI__) (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON)) // 检查是否为有效的 LSI 状态
#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON)) // 检查是否为有效的 PLL 状态

#define IS_RCC_CLOCKTYPE(CLK) ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                               (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2)) // 检查是否为有效的时钟类型
#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK)) // 检查是否为有效的系统时钟源
#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK)) // 检查是否为有效的系统时钟源状态
#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512)) // 检查是否为有效的 AHB 分频系数
#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16)) // 检查是否为有效的 APB 分频系数
#define IS_RCC_MCO(__MCO__)  ((__MCO__) == RCC_MCO) // 检查是否为有效的 MCO
#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1)) // 检查是否为有效的 MCO 分频系数
#define IS_RCC_RTCCLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV128)) // 检查是否为有效的 RTC 时钟源

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

#endif /* __STM32F1xx_HAL_RCC_H */
