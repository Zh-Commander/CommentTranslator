
/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE).
  * @note Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not supported by this macro.
  * @note   As the LSE is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         @ref HAL_PWR_EnableBkUpAccess() function before to configure the LSE
  *         (to be done once after reset).
  * @note   After enabling the LSE (RCC_LSE_ON or RCC_LSE_BYPASS), the application
  *         software should wait on LSERDY flag to be set indicating that LSE clock
  *         is stable and can be used to clock the RTC.
  * @param  __STATE__ specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSE_OFF turn OFF the LSE oscillator, LSERDY flag goes low after
  *                              6 LSE oscillator clock cycles.
  *            @arg @ref RCC_LSE_ON turn ON the LSE oscillator.
  *            @arg @ref RCC_LSE_BYPASS LSE oscillator bypassed with external clock.
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
  * @{
  */

/** @brief Macro to enable the main PLL.
  * @note   After enabling the main PLL, the application software should wait on
  *         PLLRDY flag to be set indicating that PLL clock is stable and can
  *         be used as system clock source.
  * @note   The main PLL is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLL_ENABLE()          (*(__IO uint32_t *) RCC_CR_PLLON_BB = ENABLE)

/** @brief Macro to disable the main PLL.
  * @note   The main PLL can not be disabled if it is used as system clock source
  */
#define __HAL_RCC_PLL_DISABLE()         (*(__IO uint32_t *) RCC_CR_PLLON_BB = DISABLE)

/** @brief Macro to configure the main PLL clock source and multiplication factors.
  * @note   This function must be used only when the main PLL is disabled.
  *
  * @param  __RCC_PLLSOURCE__ specifies the PLL entry clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI oscillator clock selected as PLL clock entry
  *            @arg @ref RCC_PLLSOURCE_HSE HSE oscillator clock selected as PLL clock entry
  * @param  __PLLMUL__ specifies the multiplication factor for PLL VCO output clock
  *          This parameter can be one of the following values:
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
  * @retval The clock source used for PLL entry. The returned value can be one
  *         of the following:
  *             @arg @ref RCC_PLLSOURCE_HSI_DIV2 HSI oscillator clock selected as PLL input clock
  *             @arg @ref RCC_PLLSOURCE_HSE HSE oscillator clock selected as PLL input clock
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_PLLSRC)))

/**
  * @}
  */

/** @defgroup RCC_Get_Clock_source Get Clock source
  * @{
  */

/**
  * @brief  Macro to configure the system clock source.
  * @param  __SYSCLKSOURCE__ specifies the system clock source.
  *          This parameter can be one of the following values:
  *              @arg @ref RCC_SYSCLKSOURCE_HSI HSI oscillator is used as system clock source.
  *              @arg @ref RCC_SYSCLKSOURCE_HSE HSE oscillator is used as system clock source.
  *              @arg @ref RCC_SYSCLKSOURCE_PLLCLK PLL output is used as system clock source.
  */
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, (__SYSCLKSOURCE__))

/** @brief  Macro to get the clock source used as system clock.
  * @retval The clock source used as system clock. The returned value can be one
  *         of the following:
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSI HSI used as system clock
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_HSE HSE used as system clock
  *             @arg @ref RCC_SYSCLKSOURCE_STATUS_PLLCLK PLL used as system clock
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(READ_BIT(RCC->CFGR,RCC_CFGR_SWS)))

/**
  * @}
  */

/** @defgroup RCCEx_MCOx_Clock_Config RCC Extended MCOx Clock Config
  * @{
  */

#if   defined(RCC_CFGR_MCO_3)
/** @brief  Macro to configure the MCO clock.
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK      No clock selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK       System clock (SYSCLK) selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_HSI          HSI selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_HSE          HSE selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK       PLL clock divided by 2 selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_PLL2CLK      PLL2 clock selected by 2 selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK_DIV2 PLL3 clock divided by 2 selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_EXT_HSE XT1  external 3-25 MHz oscillator clock selected (for Ethernet) as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_PLL3CLK      PLL3 clock selected (for Ethernet) as MCO clock
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1 No division applied on MCO clock source
  */
#else
/** @brief  Macro to configure the MCO clock.
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK No clock selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK  System clock (SYSCLK) selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_HSI HSI selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_HSE HSE selected as MCO clock
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK  PLL clock divided by 2 selected as MCO clock
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1 No division applied on MCO clock source
  */
#endif

#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR, RCC_CFGR_MCO, (__MCOCLKSOURCE__))


/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Configuration RCC RTC Clock Configuration
* @{
*/

/** @brief Macro to configure the RTC clock (RTCCLK).
  * @note   As the RTC clock configuration bits are in the Backup domain and write
  *         access is denied to this domain after reset, you have to enable write
  *         access using the Power Backup Access macro before to configure
  *         the RTC clock source (to be done once after reset).
  * @note   Once the RTC clock is configured it can't be changed unless the
  *         Backup domain is reset using @ref __HAL_RCC_BACKUPRESET_FORCE() macro, or by
  *         a Power On Reset (POR).
  *
  * @param  __RTC_CLKSOURCE__ specifies the RTC clock source.
  *          This parameter can be one of the following values:
  *             @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *             @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *             @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *             @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE divided by 128 selected as RTC clock
  * @note   If the LSE or LSI is used as RTC clock source, the RTC continues to
  *         work in STOP and STANDBY modes, and can be used as wakeup source.
  *         However, when the HSE clock is used as RTC clock source, the RTC
  *         cannot be used in STOP and STANDBY modes.
  * @note   The maximum input clock frequency for RTC is 1MHz (when using HSE as
  *         RTC clock source).
  */
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__) MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))

/** @brief Macro to get the RTC clock source.
  * @retval The clock source can be one of the following values:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK No clock selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_LSE LSE selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_LSI LSI selected as RTC clock
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV128 HSE divided by 128 selected as RTC clock
  */
#define __HAL_RCC_GET_RTC_SOURCE() (READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL))

/** @brief Macro to enable the the RTC clock.
  * @note   These macros must be used only after the RTC clock source was selected.
  */
#define __HAL_RCC_RTC_ENABLE()          (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = ENABLE)

/** @brief Macro to disable the the RTC clock.
  * @note  These macros must be used only after the RTC clock source was selected.
  */
#define __HAL_RCC_RTC_DISABLE()         (*(__IO uint32_t *) RCC_BDCR_RTCEN_BB = DISABLE)

/** @brief  Macro to force the Backup domain reset.
  * @note   This function resets the RTC peripheral (including the backup registers)
  *         and the RTC clock source selection in RCC_BDCR register.
  */
#define __HAL_RCC_BACKUPRESET_FORCE()   (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = ENABLE)

/** @brief  Macros to release the Backup domain reset.
  */
#define __HAL_RCC_BACKUPRESET_RELEASE() (*(__IO uint32_t *) RCC_BDCR_BDRST_BB = DISABLE)

/**
  * @}
  */

/** @defgroup RCC_Flags_Interrupts_Management Flags Interrupts Management
  * @brief macros to manage the specified RCC Flags and interrupts.
  * @{
  */

/** @brief Enable RCC interrupt.
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be enabled.
  *          This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @endif
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS |= (__INTERRUPT__))

/** @brief Disable RCC interrupt.
  * @param  __INTERRUPT__ specifies the RCC interrupt sources to be disabled.
  *          This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY main PLL ready interrupt
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @endif
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE1_ADDRESS &= (uint8_t)(~(__INTERRUPT__)))

/** @brief Clear the RCC's interrupt pending bits.
  * @param  __INTERRUPT__ specifies the interrupt pending bit to clear.
  *          This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt.
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt.
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt.
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt.
  *            @arg @ref RCC_IT_PLLRDY Main PLL ready interrupt.
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @endif
  *            @arg @ref RCC_IT_CSS Clock Security System interrupt
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) (*(__IO uint8_t *) RCC_CIR_BYTE2_ADDRESS = (__INTERRUPT__))

/** @brief Check the RCC's interrupt has occurred or not.
  * @param  __INTERRUPT__ specifies the RCC interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_IT_LSIRDY LSI ready interrupt.
  *            @arg @ref RCC_IT_LSERDY LSE ready interrupt.
  *            @arg @ref RCC_IT_HSIRDY HSI ready interrupt.
  *            @arg @ref RCC_IT_HSERDY HSE ready interrupt.
  *            @arg @ref RCC_IT_PLLRDY Main PLL ready interrupt.
  @if STM32F105xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @elsif STM32F107xx
  *            @arg @ref RCC_IT_PLL2RDY Main PLL2 ready interrupt.
  *            @arg @ref RCC_IT_PLLI2S2RDY Main PLLI2S ready interrupt.
  @endif
  *            @arg @ref RCC_IT_CSS Clock Security System interrupt
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__) ((RCC->CIR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief Set RMVF bit to clear the reset flags.
  *         The reset flags are RCC_FLAG_PINRST, RCC_FLAG_PORRST, RCC_FLAG_SFTRST,
  *         RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST, RCC_FLAG_LPWRRST
  */
#define __HAL_RCC_CLEAR_RESET_FLAGS() (*(__IO uint32_t *)RCC_CSR_RMVF_BB = ENABLE)

/** @brief  Check RCC flag is set or not.
  * @param  __FLAG__ specifies the flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_FLAG_HSIRDY HSI oscillator clock ready.
  *            @arg @ref RCC_FLAG_HSERDY HSE oscillator clock ready.
  *            @arg @ref RCC_FLAG_PLLRDY Main PLL clock ready.
  @if STM32F105xx
  *            @arg @ref RCC_FLAG_PLL2RDY Main PLL2 clock ready.
  *            @arg @ref RCC_FLAG_PLLI2SRDY Main PLLI2S clock ready.
  @elsif STM32F107xx
  *            @arg @ref RCC_FLAG_PLL2RDY Main PLL2 clock ready.
  *            @arg @ref RCC_FLAG_PLLI2SRDY Main PLLI2S clock ready.
  @endif
  *            @arg @ref RCC_FLAG_LSERDY LSE oscillator clock ready.
  *            @arg @ref RCC_FLAG_LSIRDY LSI oscillator clock ready.
  *            @arg @ref RCC_FLAG_PINRST  Pin reset.
  *            @arg @ref RCC_FLAG_PORRST  POR/PDR reset.
  *            @arg @ref RCC_FLAG_SFTRST  Software reset.
  *            @arg @ref RCC_FLAG_IWDGRST Independent Watchdog reset.
  *            @arg @ref RCC_FLAG_WWDGRST Window Watchdog reset.
  *            @arg @ref RCC_FLAG_LPWRRST Low Power reset.
  * @retval The new state of __FLAG__ (TRUE or FALSE).
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
#include "stm32f1xx_hal_rcc_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* Peripheral Control functions  ************************************************/
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
void              HAL_RCC_DisableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

/* CSS NMI IRQ handler */
void              HAL_RCC_NMI_IRQHandler(void);

/* User Callbacks in non blocking mode (IT mode) */
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

/** @defgroup RCC_Timeout RCC Timeout
  * @{
  */

/* Disable Backup domain write protection state change timeout */
#define RCC_DBP_TIMEOUT_VALUE          100U    /* 100 ms */
/* LSE state change timeout */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
#define CLOCKSWITCH_TIMEOUT_VALUE      5000    /* 5 s    */
#define HSE_TIMEOUT_VALUE              HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */
#define LSI_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */
#define PLL_TIMEOUT_VALUE              2U      /* 2 ms (minimum Tick + 1) */

/**
  * @}
  */

/** @defgroup RCC_Register_Offset Register offsets
  * @{
  */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)
#define RCC_CR_OFFSET             0x00U
#define RCC_CFGR_OFFSET           0x04U
#define RCC_CIR_OFFSET            0x08U
#define RCC_BDCR_OFFSET           0x20U
#define RCC_CSR_OFFSET            0x24U

/**
  * @}
  */

/** @defgroup RCC_BitAddress_AliasRegion BitAddress AliasRegion
  * @brief RCC registers bit address in the alias region
  * @{
  */
#define RCC_CR_OFFSET_BB          (RCC_OFFSET + RCC_CR_OFFSET)
#define RCC_CFGR_OFFSET_BB        (RCC_OFFSET + RCC_CFGR_OFFSET)
#define RCC_CIR_OFFSET_BB         (RCC_OFFSET + RCC_CIR_OFFSET)
#define RCC_BDCR_OFFSET_BB        (RCC_OFFSET + RCC_BDCR_OFFSET)
#define RCC_CSR_OFFSET_BB         (RCC_OFFSET + RCC_CSR_OFFSET)

/* --- CR Register ---*/
/* Alias word address of HSION bit */
#define RCC_HSION_BIT_NUMBER      RCC_CR_HSION_Pos
#define RCC_CR_HSION_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSION_BIT_NUMBER * 4U)))
/* Alias word address of HSEON bit */
#define RCC_HSEON_BIT_NUMBER      RCC_CR_HSEON_Pos
#define RCC_CR_HSEON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSEON_BIT_NUMBER * 4U)))
/* Alias word address of CSSON bit */
#define RCC_CSSON_BIT_NUMBER      RCC_CR_CSSON_Pos
#define RCC_CR_CSSON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_CSSON_BIT_NUMBER * 4U)))
/* Alias word address of PLLON bit */
#define RCC_PLLON_BIT_NUMBER      RCC_CR_PLLON_Pos
#define RCC_CR_PLLON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_PLLON_BIT_NUMBER * 4U)))

/* --- CSR Register ---*/
/* Alias word address of LSION bit */
#define RCC_LSION_BIT_NUMBER      RCC_CSR_LSION_Pos
#define RCC_CSR_LSION_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_LSION_BIT_NUMBER * 4U)))

/* Alias word address of RMVF bit */
#define RCC_RMVF_BIT_NUMBER       RCC_CSR_RMVF_Pos
#define RCC_CSR_RMVF_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_RMVF_BIT_NUMBER * 4U)))

/* --- BDCR Registers ---*/
/* Alias word address of LSEON bit */
#define RCC_LSEON_BIT_NUMBER      RCC_BDCR_LSEON_Pos
#define RCC_BDCR_LSEON_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEON_BIT_NUMBER * 4U)))

/* Alias word address of LSEON bit */
#define RCC_LSEBYP_BIT_NUMBER     RCC_BDCR_LSEBYP_Pos
#define RCC_BDCR_LSEBYP_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEBYP_BIT_NUMBER * 4U)))

/* Alias word address of RTCEN bit */
#define RCC_RTCEN_BIT_NUMBER      RCC_BDCR_RTCEN_Pos
#define RCC_BDCR_RTCEN_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U)))

/* Alias word address of BDRST bit */
#define RCC_BDRST_BIT_NUMBER      RCC_BDCR_BDRST_Pos
#define RCC_BDCR_BDRST_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_BDRST_BIT_NUMBER * 4U)))

/**
  * @}
  */

/* CR register byte 2 (Bits[23:16]) base address */
#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))

/* CIR register byte 1 (Bits[15:8]) base address */
#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))

/* CIR register byte 2 (Bits[23:16]) base address */
#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))

/* Defines used for Flags */
#define CR_REG_INDEX                     ((uint8_t)1)
#define BDCR_REG_INDEX                   ((uint8_t)2)
#define CSR_REG_INDEX                    ((uint8_t)3)

#define RCC_FLAG_MASK                    ((uint8_t)0x1F)

/**
  * @}
  */

/** @addtogroup RCC_Private_Macros
  * @{
  */
/** @defgroup RCC_Alias_For_Legacy Alias define maintained for legacy
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_DISABLE    __HAL_RCC_AFIO_CLK_DISABLE
#define __HAL_RCC_SYSCFG_CLK_ENABLE     __HAL_RCC_AFIO_CLK_ENABLE
#define __HAL_RCC_SYSCFG_FORCE_RESET    __HAL_RCC_AFIO_FORCE_RESET
#define __HAL_RCC_SYSCFG_RELEASE_RESET  __HAL_RCC_AFIO_RELEASE_RESET
/**
  * @}
  */

#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_HSI_DIV2) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE))
#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE))
#define IS_RCC_HSE(__HSE__) (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                             ((__HSE__) == RCC_HSE_BYPASS))
#define IS_RCC_LSE(__LSE__) (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                             ((__LSE__) == RCC_LSE_BYPASS))
#define IS_RCC_HSI(__HSI__) (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))
#define IS_RCC_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 0x1FU)
#define IS_RCC_LSI(__LSI__) (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON))
#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON))

#define IS_RCC_CLOCKTYPE(CLK) ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                               (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2))
#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK))
#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK))
#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512))
#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16))
#define IS_RCC_MCO(__MCO__)  ((__MCO__) == RCC_MCO)
#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1))
#define IS_RCC_RTCCLKSOURCE(__SOURCE__)  (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI) || \
                                          ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV128))

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


