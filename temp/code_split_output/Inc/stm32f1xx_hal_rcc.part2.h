/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE).
  *         配置外部低速振荡器(LSE)的宏。
  * @note Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not supported by this macro.
  *       注意：该宏不支持从 LSE 旁路模式切换到 LSE 开启模式，也不支持从 LSE 开启模式切换到旁路模式。
  * @note   As the LSE is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         @ref HAL_PWR_EnableBkUpAccess() function before to configure the LSE
  *         (to be done once after reset).
  *       注意：由于 LSE 处于备份域，复位后对该域的写访问被禁止，
  *       因此在配置 LSE 之前，必须使用 @ref HAL_PWR_EnableBkUpAccess() 函数使能写访问
  *       (复位后执行一次即可)。
  * @note   After enabling the LSE (RCC_LSE_ON or RCC_LSE_BYPASS), the application
  *         software should wait on LSERDY flag to be set indicating that LSE clock
  *         is stable and can be used to clock the RTC.
  *       注意：在使能 LSE (RCC_LSE_ON 或 RCC_LSE_BYPASS) 之后，应用程序软件应该等待 
  *       LSERDY 标志位被置位，这表明 LSE 时钟已稳定，可用于驱动 RTC。
  * @param  __STATE__ specifies the new state of the LSE.
  *         指定 LSE 的新状态。
  *         This parameter can be one of the following values:
  *         该参数可以是以下值之一：
  *            @arg @ref RCC_LSE_OFF turn OFF the LSE oscillator, LSERDY flag goes low after
  *                              6 LSE oscillator clock cycles.
  *            关闭 LSE 振荡器，LSERDY 标志位在 6 个 LSE 振荡器时钟周期后变低。
  *            @arg @ref RCC_LSE_ON turn ON the LSE oscillator.
  *            开启 LSE 振荡器。
  *            @arg @ref RCC_LSE_BYPASS LSE oscillator bypassed with external clock.
  *            LSE 振荡器被外部时钟旁路。
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

/** @defgroup RCC_PLL_Configuration PLL Configuration
  *         PLL 配置
  * @{
  */

/** @brief Macro to enable the main PLL.
  *        使能主 PLL 的宏。
  * @note   After enabling the main PLL, the application software should wait on
  *         PLLRDY flag to be set indicating that PLL clock is stable and can
  *         be used as system clock source.
  *       注意：使能主 PLL 后，应用软件应等待 PLLRDY 标志位被置位，
  *       以表明 PLL 时钟稳定，可用作系统时钟源。
  * @note   The main PLL is disabled by hardware when entering STOP and STANDBY modes.
  *       注意：进入停止和待机模式时，硬件会自动禁用主 PLL。
  */
#define __HAL_RCC_PLL_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLON_BB = ENABLE)

/** @brief Macro to disable the main PLL.
  *        禁用主 PLL 的宏。
  * @note   The main PLL can not be disabled if it is used as system clock source
  *       注意：如果主 PLL 被用作系统时钟源，则不能被禁用。
  */
#define __HAL_RCC_PLL_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLON_BB = DISABLE)

/** @brief Macro to configure the main PLL clock source and multiplication factors.
  *        配置主 PLL 时钟源和倍频因子的宏。
  * @note   This function must be used only when the main PLL is disabled.
  *       注意：此功能必须在主 PLL 禁用时使用。
  *
  * @param  __RCC_PLLSOURCE__ specifies the PLL entry clock source.
  *         指定 PLL 入口时钟源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI oscillator clock selected as PLL clock entry
  *            HSI 振荡器时钟被选为 PLL 时钟输入（HSI 2分频）
  *            @arg @ref RCC_PLLSOURCE_HSE HSE oscillator clock selected as PLL clock entry
  *            HSE 振荡器时钟被选为 PLL 时钟输入
  * @param  __PLLMUL__ specifies the multiplication factor for PLL VCO output clock
  *         指定 PLL VCO 输出时钟的倍频因子
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *             @arg @ref RCC_PLL_MUL4   PLLVCO = PLL clock entry x 4
  *             @arg @ref RCC_PLL_MUL6   PLLVCO = PLL clock entry x 6
  @if STM32F105xC
  *             @arg @ref RCC_PLL_MUL6_5 PLLVCO = PLL clock entry x 6.5
  @elseif STM32F107xC
  *             @arg @ref RCC_PLL_MUL6_5 PLLVCO = PLL clock entry x 6.5
  @else
  *             @arg @ref RCC_PLL_MUL2   PLLVCO = PLL clock entry x 2
  *             @arg @ref RCC_PLL_MUL3   PLLVCO = PLL clock entry x 3
  *             @arg @ref RCC_PLL_MUL10  PLLVCO = PLL clock entry x 10
  *             @arg @ref RCC_PLL_MUL11  PLLVCO = PLL clock entry x 11
  *             @arg @ref RCC_PLL_MUL12  PLLVCO = PLL clock entry x 12
  *             @arg @ref RCC_PLL_MUL13  PLLVCO = PLL clock entry x 13
  *             @arg @ref RCC_PLL_MUL14  PLLVCO = PLL clock entry x 14
  *             @arg @ref RCC_PLL_MUL15  PLLVCO = PLL clock entry x 15
  *             @arg @ref RCC_PLL_MUL16  PLLVCO = PLL clock entry x 16
  @endif
  *             @arg @ref RCC_PLL_MUL8   PLLVCO = PLL clock entry x 8
  *             @arg @ref RCC_PLL_MUL9   PLLVCO = PLL clock entry x 9
  *
  */
#define __HAL_RCC_PLL_CONFIG(__RCC_PLLSOURCE__, __PLLMUL__)\
          MODIFY_REG(RCC->CFGR, (RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL),((__RCC_PLLSOURCE__) | (__PLLMUL__) ))

/** @brief  Get oscillator clock selected as PLL input clock
  *         获取被选为 PLL 输入时钟的振荡器时钟
  * @retval The clock source used for PLL entry. The returned value can be one
  *         of the following:
  *         用于 PLL 入口的时钟源。返回值可以是以下之一：
  *             @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI oscillator clock selected as PLL input clock
  *             HSI 振荡器时钟被选为 PLL 输入时钟
  *             @arg @ref RCC_PLLSOURCE_HSE HSE oscillator clock selected as PLL input clock
  *             HSE 振荡器时钟被选为 PLL 输入时钟
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PLLSRC)))

/**
  * @}
  */

/** @defgroup RCC_Get_Clock_source Get Clock source
  *         获取时钟源
  * @{
  */

/**
  * @brief  Macro to configure the system clock source.
  *         配置系统时钟源的宏。
  * @param  __SYSCLKSOURCE__ specifies the system clock source.
  *         指定系统时钟源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *              @arg @ref RCC_SYSCLKSOURCE_HSI HSI oscillator is used as system clock source.
  *              HSI 振荡器用作系统时钟源。
  *              @arg @ref RCC_SYSCLKSOURCE_HSE HSE oscillator is used as system clock source.
  *              HSE 振荡器用作系统时钟源。
  *              @arg @ref RCC_SYSCLKSOURCE_PLLCLK PLL output is used as system clock source.
  *              PLL 输出用作系统时钟源。
  */
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))

/** @brief  Macro to get the clock source used as system clock.
  *         获取用作系统时钟的时钟源的宏。
  * @retval The clock source used as system clock. The returned value can be one
  *         of the following:
  *         用作系统时钟的时钟源。返回值可以是以下之一：
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSI HSI used as system clock
  *             HSI 用作系统时钟
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSE HSE used as system clock
  *             HSE 用作系统时钟
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_PLLCLK PLL used as system clock
  *             PLL 用作系统时钟
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR,RCC_CFGR_SWS)))

/**
  * @}
  */

/** @defgroup RCCEx_MCOx_Clock_Config RCC Extended MCOx Clock Config
  *         RCC 扩展 MCOx 时钟配置
  * @{
  */

#if   defined(RCC_CFGR_MCO_3)
/** @brief  Macro to configure the MCO clock.
  *         配置 MCO 时钟的宏。
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *         指定 MCO 时钟源。
  *         This parameter can be one of the following values:
  *         该参数可以是以下值之一：
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK      No clock selected as MCO clock
  *            无时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK       System clock (SYSCLK) selected as MCO clock
  *            系统时钟 (SYSCLK) 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSI          HSI selected as MCO clock
  *            HSI 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSE          HSE selected as MCO clock
  *            HSE 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK       PLL clock divided by 2 selected as MCO clock
  *            PLL 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLL2CLK      PLL2 clock selected by 2 selected as MCO clock
  *            PLL2 时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK_DIV2 PLL3 clock divided by 2 selected as MCO clock
  *            PLL3 时钟 2 分频被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_EXT_HSE XT1  external 3-25 MHz oscillator clock selected (for Ethernet) as MCO clock
  *            外部 3-25 MHz 振荡器时钟被选为 MCO 时钟 (用于以太网)
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK      PLL3 clock selected (for Ethernet) as MCO clock
  *            PLL3 时钟被选为 MCO 时钟 (用于以太网)
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *         指定 MCO 时钟预分频器。
  *         This parameter can be one of the following values:
  *         该参数可以是以下值之一：
  *            @arg @ref RCC_MCODIV_1 No division applied on MCO clock source
  *            MCO 时钟源不进行分频
  */
#else
/** @brief  Macro to configure the MCO clock.
  *         配置 MCO 时钟的宏。
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *         指定 MCO 时钟源。
  *         This parameter can be one of the following values:
  *         该参数可以是以下值之一：
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK No clock selected as MCO clock
  *            无时钟被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK  System clock (SYSCLK) selected as MCO clock
  *            系统时钟 (SYSCLK) 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSI HSI selected as MCO clock
  *            HSI 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_HSE HSE selected as MCO clock
  *            HSE 被选为 MCO 时钟
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK  PLL clock divided by 2 selected as MCO clock
  *            PLL 时钟 2 分频被选为 MCO 时钟
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *         指定 MCO 时钟预分频器。
  *         This parameter can be one of the following values:
  *         该参数可以是以下值之一：
  *            @arg @ref RCC_MCODIV_1 No division applied on MCO clock source
  *            MCO 时钟源不进行分频
  */
#endif

#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, (__MCOCLKSOURCE__))


/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Configuration RCC RTC Clock Configuration
*           RCC RTC 时钟配置
* @{
*/

/** @brief Macro to configure the RTC clock (RTCCLK).
  *        配置 RTC 时钟 (RTCCLK) 的宏。
  * @note   As the RTC clock configuration bits are in the Backup domain and write
  *         access is denied to this domain after reset, you have to enable write
  *         access using the Power Backup Access macro before to configure
  *         the RTC clock source (to be done once after reset).
  *       注意：由于 RTC 时钟配置位处于备份域，复位后对该域的写访问被禁止，
  *       因此在配置 RTC 时钟源之前，必须使用电源备份访问宏使能写访问
  *       (复位后执行一次即可)。
  * @note   Once the RTC clock is configured it can't be changed unless the
  *         Backup domain is reset using @ref __HAL_RCC_BACKUPRESET_FORCE() macro, or by
  *         a Power On Reset (POR).
  *       注意：RTC 时钟一旦配置，就无法更改，除非使用 @ref __HAL_RCC_BACKUPRESET_FORCE() 宏复位备份域，
  *       或者通过上电复位 (POR)。
  *
  * @param  __RTC_CLKSOURCE__ specifies the RTC clock source.
  *         指定 RTC 时钟源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *             @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *             无时钟被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *             LSE 被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *             LSI 被选为 RTC 时钟
  *             @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE divided by 128 selected as RTC clock
  *             HSE 128 分频被选为 RTC 时钟
  * @note   If the LSE or LSI is used as RTC clock source, the RTC continues to
  *         work in STOP and STANDBY modes, and can be used as wakeup source.
  *         However, when the HSE clock is used as RTC clock source, the RTC
  *         cannot be used in STOP and STANDBY modes.
  *       注意：如果 LSE 或 LSI 用作 RTC 时钟源，RTC 在停止和待机模式下继续工作，
  *       并可用作唤醒源。但是，当 HSE 时钟用作 RTC 时钟源时，RTC 不能在停止和待机模式下使用。
  * @note   The maximum input clock frequency for RTC is 1MHz (when using HSE as
  *         RTC clock source).
  *       注意：RTC 的最大输入时钟频率为 1MHz (当使用 HSE 作为 RTC 时钟源时)。
  */
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__) MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))

/** @brief Macro to get the RTC clock source.
  *        获取 RTC 时钟源的宏。
  * @retval The clock source can be one of the following values:
  *         时钟源可以是以下值之一：
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *            无时钟被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *            LSE 被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *            LSI 被选为 RTC 时钟
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE divided by 128 selected as RTC clock
  *            HSE 128 分频被选为 RTC 时钟
  */
#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

/** @brief Macro to enable the the RTC clock.
  *        使能 RTC 时钟的宏。
  * @note   These macros must be used only after the RTC clock source was selected.
  *       注意：这些宏必须在选择了 RTC 时钟源之后使用。
  */
#define __HAL_RCC_RTC_ENABLE()          (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = ENABLE)

/** @brief Macro to disable the the RTC clock.
  *        禁用 RTC 时钟的宏。
  * @note  These macros must be used only after the RTC clock source was selected.
  *       注意：这些宏必须在选择了 RTC 时钟源之后使用。
  */
#define __HAL_RCC_RTC_DISABLE()         (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = DISABLE)

/** @brief  Macro to force the Backup domain reset.
  *         强制备份域复位的宏。
  * @note   This function resets the RTC peripheral (including the backup registers)
  *         and the RTC clock source selection in RCC_BDCR register.
  *       注意：此功能复位 RTC 外设 (包括备份寄存器) 以及 RCC_BDCR 寄存器中的 RTC 时钟源选择。
  */
#define __HAL_RCC_BACKUPRESET_FORCE()   (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = ENABLE)

/** @brief  Macros to release the Backup domain reset.
  *         释放备份域复位的宏。
  */
#define __HAL_RCC_BACKUPRESET_RELEASE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = DISABLE)

/**
  * @}
  */

/** @defgroup RCC_Flags_Interrupts_Management Flags Interrupts Management
  *         标志与中断管理
  * @brief macros to manage the specified RCC Flags and interrupts.
  *        管理指定 RCC 标志和中断的宏。
  * @{
  */

/** @brief Enable RCC interrupt.
  *        使能 RCC 中断。
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be enabled.
  *         指定要使能的 RCC 中断源。
  *          This parameter can be any combination of the following values:
  *          该参数可以是以下值的任意组合：
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  *            主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @endif
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))

/** @brief Disable RCC interrupt.
  *        禁用 RCC 中断。
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be disabled.
  *         指定要禁用的 RCC 中断源。
  *          This parameter can be any combination of the following values:
  *          该参数可以是以下值的任意组合：
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  *            主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @endif
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))

/** @brief Clear the RCC's interrupt pending bits.
  *        清除 RCC 的中断挂起位。
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *         指定要清除的中断挂起位。
  *          This parameter can be any combination of the following values:
  *          该参数可以是以下值的任意组合：
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt.
  *            LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt.
  *            LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt.
  *            HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt.
  *            HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY Main PLL ready interrupt.
  *            主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @endif
  *            @arg @ref RCC_IT_CSS Clock Security System interrupt
  *            时钟安全系统中断
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))

/** @brief Check the RCC's interrupt has occurred or not.
  *        检查 RCC 中断是否发生。
  * @param  __INTERRUPT__ specifies the RCC interrupt source to check.
  *         指定要检查的 RCC 中断源。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt.
  *            LSI 就绪中断
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt.
  *            LSE 就绪中断
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt.
  *            HSI 就绪中断
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt.
  *            HSE 就绪中断
  *            @arg @ref RCC_IT_PLLRDY Main PLL ready interrupt.
  *            主 PLL 就绪中断
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            主 PLL2 就绪中断
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  *            主 PLLI2S 就绪中断
  @endif
  *            @arg @ref RCC_IT_CSS Clock Security System interrupt
  *            时钟安全系统中断
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  *         __INTERRUPT__ 的新状态 (TRUE 或 FALSE)。
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief Set RMVF bit to clear the reset flags.
  *        设置 RMVF 位以清除复位标志。
  *         The reset flags are RCC_FLAG_PINRST, RCC_FLAG_PORRST, RCC_FLAG_SFTRST,
  *         RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST, RCC_FLAG_LPWRRST
  *         复位标志包括：引脚复位、POR/PDR 复位、软件复位、独立看门狗复位、窗口看门狗复位、低功耗复位。
  */
#define __HAL_RCC_CLEAR_RESET_FLAGS() (*(__IO uint32_t *)RCC_CSR_RMVF_BB = ENABLE)

/** @brief  Check RCC flag is set or not.
  *        检查 RCC 标志是否置位。
  * @param  __FLAG__ specifies the flag to check.
  *         指定要检查的标志。
  *          This parameter can be one of the following values:
  *          该参数可以是以下值之一：
  *            @arg @ref RCC_FLAG_HSIRDY HSI oscillator clock ready.
  *            HSI 振荡器时钟就绪
  *            @arg @ref RCC_FLAG_HSERDY HSE oscillator clock ready.
  *            HSE 振荡器时钟就绪
  *            @arg @ref RCC_FLAG_PLLRDY Main PLL clock ready.
  *            主 PLL 时钟就绪
  @if STM32F105xx
  *            @arg @ref RCC_FLAG_PLL2RDY Main PLL2 clock ready.
  *            主 PLL2 时钟就绪
  *            @arg @ref RCC_FLAG_PLLI2SRDY Main PLLI2S clock ready.
  *            主 PLLI2S 时钟就绪
  @elsif STM32F107xx
  *            @arg @ref RCC_FLAG_PLL2RDY Main PLL2 clock ready.
  *            主 PLL2 时钟就绪
  *            @arg @ref RCC_FLAG_PLLI2SRDY Main PLLI2S clock ready.
  *            主 PLLI2S 时钟就绪
  @endif
  *            @arg @ref RCC_FLAG_LSERDY LSE oscillator clock ready.
  *            LSE 振荡器时钟就绪
  *            @arg @ref RCC_FLAG_LSIRDY LSI oscillator clock ready.
  *            LSI 振荡器时钟就绪
  *            @arg @ref RCC_FLAG_PINRST  Pin reset.
  *            引脚复位
  *            @arg @ref RCC_FLAG_PORRST  POR/PDR reset.
  *            POR/PDR 复位
  *            @arg @ref RCC_FLAG_SFTRST  Software reset.
  *            软件复位
  *            @arg @ref RCC_FLAG_IWDGRST Independent Watchdog reset.
  *            独立看门狗复位
  *            @arg @ref RCC_FLAG_WWDGRST Window Watchdog reset.
  *            窗口看门狗复位
  *            @arg @ref RCC_FLAG_LPWRRST Low Power reset.
  *            低功耗复位
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  *         __FLAG__ 的新状态 (TRUE 或 FALSE)。
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

/* Include RCC HAL Extension module */
/* 包含 RCC HAL 扩展模块 */
#include "stm32f1xx_hal_rcc_ex.h"

/* Exported functions --------------------------------------------------------*/
/* 导出函数 ------------------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
/* 初始化和反初始化函数 **************************************************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void); // RCC 反初始化，将 RCC 寄存器恢复为默认值
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct); // 配置系统振荡器
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency); // 配置系统时钟

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* Peripheral Control functions  ************************************************/
/* 外设控制函数 ****************************************************************/
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv); // 配置微控制器时钟输出 (MCO)
void              HAL_RCC_EnableCSS(void); // 使能时钟安全系统 (CSS)
void              HAL_RCC_DisableCSS(void); // 禁用时钟安全系统 (CSS)
uint32_t          HAL_RCC_GetSysClockFreq(void); // 获取系统时钟频率
uint32_t          HAL_RCC_GetHCLKFreq(void); // 获取 HCLK 频率
uint32_t          HAL_RCC_GetPCLK1Freq(void); // 获取 PCLK1 频率
uint32_t          HAL_RCC_GetPCLK2Freq(void); // 获取 PCLK2 频率
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct); // 获取振荡器配置
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency); // 获取时钟配置

/* CSS NMI IRQ handler */
/* CSS NMI 中断处理程序 */
void              HAL_RCC_NMI_IRQHandler(void); // RCC NMI 中断服务程序

/* User Callbacks in non blocking mode (IT mode) */
/* 非阻塞模式 (中断模式) 下的用户回调函数 */
void              HAL_RCC_CSSCallback(void); // 时钟安全系统中断回调函数

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup RCC_Private_Constants
  *         RCC 私有常量
  * @{
  */

/** @defgroup RCC_Timeout RCC Timeout
  *         RCC 超时时间定义
  * @{
  */

/* Disable Backup domain write protection state change timeout */
/* 禁用备份域写保护状态更改超时时间 */
#define RCC_DBP_TIMEOUT_VALUE          100U    /* 100 ms */
/* LSE state change timeout */
/* LSE 状态更改超时时间 */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
#define CLOCKSWITCH_TIMEOUT_VALUE      5000    /* 5 s    */ // 时钟切换超时时间
#define HSE_TIMEOUT_VALUE              HSE_STARTUP_TIMEOUT // HSE 启动超时时间
#define HSI_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */ // HSI 超时时间
#define LSI_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */ // LSI 超时时间
#define PLL_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */ // PLL 超时时间

/**
  * @}
  */

/** @defgroup RCC_Register_Offset Register offsets
  *         寄存器偏移量
  * @{
  */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE) // RCC 外设基地址偏移
#define RCC_CR_OFFSET             0x00U // CR 寄存器偏移
#define RCC_CFGR_OFFSET           0x04U // CFGR 寄存器偏移
#define RCC_CIR_OFFSET            0x08U // CIR 寄存器偏移
#define RCC_BDCR_OFFSET           0x20U // BDCR 寄存器偏移 (备份域控制寄存器)
#define RCC_CSR_OFFSET            0x24U // CSR 寄存器偏移 (控制/状态寄存器)

/**
  * @}
  */

/** @defgroup RCC_BitAddress_AliasRegion BitAddress AliasRegion
  *         位带别名区
  * @brief RCC registers bit address in the alias region
  *        RCC 寄存器位在别名区的位地址
  * @{
  */
#define RCC_CR_OFFSET_BB          (RCC_OFFSET + RCC_CR_OFFSET)
#define RCC_CFGR_OFFSET_BB        (RCC_OFFSET + RCC_CFGR_OFFSET)
#define RCC_CIR_OFFSET_BB         (RCC_OFFSET + RCC_CIR_OFFSET)
#define RCC_BDCR_OFFSET_BB        (RCC_OFFSET + RCC_BDCR_OFFSET)
#define RCC_CSR_OFFSET_BB         (RCC_OFFSET + RCC_CSR_OFFSET)

/* --- CR Register ---*/
/* --- CR 寄存器 ---*/
/* Alias word address of HSION bit */
/* HSION 位的别名地址 */
#define RCC_HSION_BIT_NUMBER      RCC_CR_HSION_Pos
#define RCC_CR_HSION_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSION_BIT_NUMBER * 4U)))
/* Alias word address of HSEON bit */
/* HSEON 位的别名地址 */
#define RCC_HSEON_BIT_NUMBER      RCC_CR_HSEON_Pos
#define RCC_CR_HSEON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSEON_BIT_NUMBER * 4U)))
/* Alias word address of CSSON bit */
/* CSSON 位的别名地址 */
#define RCC_CSSON_BIT_NUMBER      RCC_CR_CSSON_Pos
#define RCC_CR_CSSON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_CSSON_BIT_NUMBER * 4U)))
/* Alias word address of PLLON bit */
/* PLLON 位的别名地址 */
#define RCC_PLLON_BIT_NUMBER      RCC_CR_PLLON_Pos
#define RCC_CR_PLLON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_PLLON_BIT_NUMBER * 4U)))

/* --- CSR Register ---*/
/* --- CSR 寄存器 ---*/
/* Alias word address of LSION bit */
/* LSION 位的别名地址 */
#define RCC_LSION_BIT_NUMBER      RCC_CSR_LSION_Pos
#define RCC_CSR_LSION_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_LSION_BIT_NUMBER * 4U)))

/* Alias word address of RMVF bit */
/* RMVF 位的别名地址 */
#define RCC_RMVF_BIT_NUMBER       RCC_CSR_RMVF_Pos
#define RCC_CSR_RMVF_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_RMVF_BIT_NUMBER * 4U)))

/* --- BDCR Registers ---*/
/* --- BDCR 寄存器 ---*/
/* Alias word address of LSEON bit */
/* LSEON 位的别名地址 */
#define RCC_LSEON_BIT_NUMBER      RCC_BDCR_LSEON_Pos
#define RCC_BDCR_LSEON_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEON_BIT_NUMBER * 4U)))

/* Alias word address of LSEON bit */
/* LSEBYP 位的别名地址 */
#define RCC_LSEBYP_BIT_NUMBER     RCC_BDCR_LSEBYP_Pos
#define RCC_BDCR_LSEBYP_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEBYP_BIT_NUMBER * 4U)))

/* Alias word address of RTCEN bit */
/* RTCEN 位的别名地址 */
#define RCC_RTCEN_BIT_NUMBER      RCC_BDCR_RTCEN_Pos
#define RCC_BDCR_RTCEN_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U)))

/* Alias word address of BDRST bit */
/* BDRST 位的别名地址 */
#define RCC_BDRST_BIT_NUMBER      RCC_BDCR_BDRST_Pos
#define RCC_BDCR_BDRST_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_BDRST_BIT_NUMBER * 4U)))

/**
  * @}
  */

/* CR register byte 2 (Bits[23:16]) base address */
/* CR 寄存器字节 2 (位[23:16]) 基地址 */
#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))

/* CIR register byte 1 (Bits[15:8]) base address */
/* CIR 寄存器字节 1 (位[15:8]) 基地址 */
#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))

/* CIR register byte 2 (Bits[23:16]) base address */
/* CIR 寄存器字节 2 (位[23:16]) 基地址 */
#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))

/* Defines used for Flags */
/* 用于标志位的定义 */
#define CR_REG_INDEX                     ((uint8_t)1) // CR 寄存器索引
#define BDCR_REG_INDEX                   ((uint8_t)2) // BDCR 寄存器索引
#define CSR_REG_INDEX                    ((uint8_t)3) // CSR 寄存器索引

#define RCC_FLAG_MASK                    ((uint8_t)0x1F) // 标志位掩码

/**
  * @}
  */

/** @addtogroup RCC_Private_Macros
  *         RCC 私有宏
  * @{
  */
/** @defgroup RCC_Alias_For_Legacy Alias define maintained for legacy
  *         为兼容性保留的别名定义
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_DISABLE    __HAL_RCC_AFIO_CLK_DISABLE // 禁用 SYSCFG 时钟 (兼容别名)
#define __HAL_RCC_SYSCFG_CLK_ENABLE     __HAL_RCC_AFIO_CLK_ENABLE  // 使能 SYSCFG 时钟 (兼容别名)
#define __HAL_RCC_SYSCFG_FORCE_RESET    __HAL_RCC_AFIO_FORCE_RESET // 强制复位 SYSCFG (兼容别名)
#define __HAL_RCC_SYSCFG_RELEASE_RESET  __HAL_RCC_AFIO_RELEASE_RESET // 释放 SYSCFG 复位 (兼容别名)
/**
  * @}
  */

// 以下是参数检查宏，用于确保传入函数的参数有效性
#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_HSI_DIV2) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE)) // 检查 PLL 源是否有效

#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)) // 检查振荡器类型是否有效

#define IS_RCC_HSE(__HSE__) (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                             ((__HSE__) == RCC_HSE_BYPASS)) // 检查 HSE 状态是否有效

#define IS_RCC_LSE(__LSE__) (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                             ((__LSE__) == RCC_LSE_BYPASS)) // 检查 LSE 状态是否有效

#define IS_RCC_HSI(__HSI__) (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON)) // 检查 HSI 状态是否有效

#define IS_RCC_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 0x1FU) // 检查 HSI 校准值范围

#define IS_RCC_LSI(__LSI__) (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON)) // 检查 LSI 状态是否有效

#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON)) // 检查 PLL 状态是否有效

#define IS_RCC_CLOCKTYPE(CLK) ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                               (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2)) // 检查时钟类型是否有效

#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK)) // 检查系统时钟源是否有效

#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK)) // 检查系统时钟源状态是否有效

#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512)) // 检查 AHB 时钟分频系数是否有效

#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16)) // 检查 APB 时钟分频系数是否有效

#define IS_RCC_MCO(__MCO__)  ((__MCO__) == RCC_MCO) // 检查 MCO 是否有效

#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1)) // 检查 MCO 分频系数是否有效

#define IS_RCC_RTCCLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV128)) // 检查 RTC 时钟源是否有效

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
