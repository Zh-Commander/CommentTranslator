/* 禁用备份域写保护状态改变的超时时间 */
#define RCC_DBP_TIMEOUT_VALUE          100U    /* 100 ms */
/* LSE(低速外部时钟)状态改变的超时时间 */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
/* 时钟切换的超时时间 */
#define CLOCKSWITCH_TIMEOUT_VALUE      5000    /* 5 s    */
/* HSE(高速外部时钟)状态改变的超时时间 */
#define HSE_TIMEOUT_VALUE              HSE_STARTUP_TIMEOUT
/* HSI(高速内部时钟)状态改变的超时时间 */
#define HSI_TIMEOUT_VALUE              2U      /* 2 ms (最小系统滴答 + 1) */
/* LSI(低速内部时钟)状态改变的超时时间 */
#define LSI_TIMEOUT_VALUE              2U      /* 2 ms (最小系统滴答 + 1) */
/* PLL(锁相环)状态改变的超时时间 */
#define PLL_TIMEOUT_VALUE              2U      /* 2 ms (最小系统滴答 + 1) */

/**
  * @}
  */

/** @defgroup RCC_Register_Offset Register offsets
  * @{
  */
/* RCC寄存器基于外设基地址的偏移量 */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)
/* RCC CR(时钟控制)寄存器偏移量 */
#define RCC_CR_OFFSET             0x00U
/* RCC CFGR(时钟配置)寄存器偏移量 */
#define RCC_CFGR_OFFSET           0x04U
/* RCC CIR(时钟中断)寄存器偏移量 */
#define RCC_CIR_OFFSET            0x08U
/* RCC BDCR(备份域控制)寄存器偏移量 */
#define RCC_BDCR_OFFSET           0x20U
/* RCC CSR(控制/状态)寄存器偏移量 */
#define RCC_CSR_OFFSET            0x24U

/**
  * @}
  */

/** @defgroup RCC_BitAddress_AliasRegion BitAddress AliasRegion
  * @brief RCC registers bit address in the alias region
  * @{
  */
/* RCC寄存器在位带别名区的偏移量计算基础 */
#define RCC_CR_OFFSET_BB          (RCC_OFFSET + RCC_CR_OFFSET)
#define RCC_CFGR_OFFSET_BB        (RCC_OFFSET + RCC_CFGR_OFFSET)
#define RCC_CIR_OFFSET_BB         (RCC_OFFSET + RCC_CIR_OFFSET)
#define RCC_BDCR_OFFSET_BB        (RCC_OFFSET + RCC_BDCR_OFFSET)
#define RCC_CSR_OFFSET_BB         (RCC_OFFSET + RCC_CSR_OFFSET)

/* --- CR Register ---*/
/* HSION位(内部高速时钟使能)的别名地址 */
#define RCC_HSION_BIT_NUMBER      RCC_CR_HSION_Pos
/* 计算HSION位在位带别名区的绝对地址 */
#define RCC_CR_HSION_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSION_BIT_NUMBER * 4U)))
/* HSEON位(外部高速时钟使能)的别名地址 */
#define RCC_HSEON_BIT_NUMBER      RCC_CR_HSEON_Pos
/* 计算HSEON位在位带别名区的绝对地址 */
#define RCC_CR_HSEON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_HSEON_BIT_NUMBER * 4U)))
/* CSSON位(时钟安全系统使能)的别名地址 */
#define RCC_CSSON_BIT_NUMBER      RCC_CR_CSSON_Pos
/* 计算CSSON位在位带别名区的绝对地址 */
#define RCC_CR_CSSON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_CSSON_BIT_NUMBER * 4U)))
/* PLLON位(锁相环使能)的别名地址 */
#define RCC_PLLON_BIT_NUMBER      RCC_CR_PLLON_Pos
/* 计算PLLON位在位带别名区的绝对地址 */
#define RCC_CR_PLLON_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CR_OFFSET_BB * 32U) + (RCC_PLLON_BIT_NUMBER * 4U)))

/* --- CSR Register ---*/
/* LSION位(内部低速时钟使能)的别名地址 */
#define RCC_LSION_BIT_NUMBER      RCC_CSR_LSION_Pos
/* 计算LSION位在位带别名区的绝对地址 */
#define RCC_CSR_LSION_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_LSION_BIT_NUMBER * 4U)))

/* RMVF位(清除复位标志)的别名地址 */
#define RCC_RMVF_BIT_NUMBER       RCC_CSR_RMVF_Pos
/* 计算RMVF位在位带别名区的绝对地址 */
#define RCC_CSR_RMVF_BB           ((uint32_t)(PERIPH_BB_BASE + (RCC_CSR_OFFSET_BB * 32U) + (RCC_RMVF_BIT_NUMBER * 4U)))

/* --- BDCR Registers ---*/
/* LSEON位(外部低速时钟使能)的别名地址 */
#define RCC_LSEON_BIT_NUMBER      RCC_BDCR_LSEON_Pos
/* 计算LSEON位在位带别名区的绝对地址 */
#define RCC_BDCR_LSEON_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEON_BIT_NUMBER * 4U)))

/* LSEBYP位(外部低速时钟旁路)的别名地址 */
#define RCC_LSEBYP_BIT_NUMBER     RCC_BDCR_LSEBYP_Pos
/* 计算LSEBYP位在位带别名区的绝对地址 */
#define RCC_BDCR_LSEBYP_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_LSEBYP_BIT_NUMBER * 4U)))

/* RTCEN位(RTC时钟使能)的别名地址 */
#define RCC_RTCEN_BIT_NUMBER      RCC_BDCR_RTCEN_Pos
/* 计算RTCEN位在位带别名区的绝对地址 */
#define RCC_BDCR_RTCEN_BB          ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_RTCEN_BIT_NUMBER * 4U)))

/* BDRST位(备份域软件复位)的别名地址 */
#define RCC_BDRST_BIT_NUMBER      RCC_BDCR_BDRST_Pos
/* 计算BDRST位在位带别名区的绝对地址 */
#define RCC_BDCR_BDRST_BB         ((uint32_t)(PERIPH_BB_BASE + (RCC_BDCR_OFFSET_BB * 32U) + (RCC_BDRST_BIT_NUMBER * 4U)))

/**
  * @}
  */

/* CR寄存器第2个字节(Bits[23:16])的基地址，用于直接操作特定字节 */
#define RCC_CR_BYTE2_ADDRESS          ((uint32_t)(RCC_BASE + RCC_CR_OFFSET + 0x02U))

/* CIR寄存器第1个字节(Bits[15:8])的基地址 */
#define RCC_CIR_BYTE1_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x01U))

/* CIR寄存器第2个字节(Bits[23:16])的基地址 */
#define RCC_CIR_BYTE2_ADDRESS     ((uint32_t)(RCC_BASE + RCC_CIR_OFFSET + 0x02U))

/* 用于标志位的寄存器索引定义 */
#define CR_REG_INDEX                     ((uint8_t)1)
#define BDCR_REG_INDEX                   ((uint8_t)2)
#define CSR_REG_INDEX                    ((uint8_t)3)

/* RCC标志位掩码 */
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
/* 为了兼容旧代码而保留的别名定义，将SYSCFG相关操作映射到AFIO */
#define __HAL_RCC_SYSCFG_CLK_DISABLE    __HAL_RCC_AFIO_CLK_DISABLE
#define __HAL_RCC_SYSCFG_CLK_ENABLE     __HAL_RCC_AFIO_CLK_ENABLE
#define __HAL_RCC_SYSCFG_FORCE_RESET    __HAL_RCC_AFIO_FORCE_RESET
#define __HAL_RCC_SYSCFG_RELEASE_RESET  __HAL_RCC_AFIO_RELEASE_RESET
/**
  * @}
  */

/* 检查PLL时钟源是否有效：HSI 2分频 或 HSE */
#define IS_RCC_PLLSOURCE(__SOURCE__) (((__SOURCE__) == RCC_PLLSOURCE_HSI_DIV2) || \
                                      ((__SOURCE__) == RCC_PLLSOURCE_HSE))
/* 检查振荡器类型参数是否有效：无、HSE、HSI、LSI、LSE */
#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                           || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE))
/* 检查HSE状态是否有效：关闭、开启、旁路 */
#define IS_RCC_HSE(__HSE__) (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                             ((__HSE__) == RCC_HSE_BYPASS))
/* 检查LSE状态是否有效：关闭、开启、旁路 */
#define IS_RCC_LSE(__LSE__) (((__LSE__) == RCC_LSE_OFF) || ((__LSE__) == RCC_LSE_ON) || \
                             ((__LSE__) == RCC_LSE_BYPASS))
/* 检查HSI状态是否有效：关闭、开启 */
#define IS_RCC_HSI(__HSI__) (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))
/* 检查HSI校准值是否有效：最大值为0x1F (5位) */
#define IS_RCC_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 0x1FU)
/* 检查LSI状态是否有效：关闭、开启 */
#define IS_RCC_LSI(__LSI__) (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON))
/* 检查PLL状态是否有效：无、关闭、开启 */
#define IS_RCC_PLL(__PLL__) (((__PLL__) == RCC_PLL_NONE) || ((__PLL__) == RCC_PLL_OFF) || \
                             ((__PLL__) == RCC_PLL_ON))

/* 检查时钟类型参数是否有效：SYSCLK、HCLK、PCLK1、PCLK2 */
#define IS_RCC_CLOCKTYPE(CLK) ((((CLK) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK) || \
                               (((CLK) & RCC_CLOCKTYPE_HCLK)   == RCC_CLOCKTYPE_HCLK)   || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK1)  == RCC_CLOCKTYPE_PCLK1)  || \
                               (((CLK) & RCC_CLOCKTYPE_PCLK2)  == RCC_CLOCKTYPE_PCLK2))
/* 检查系统时钟源是否有效：HSI、HSE、PLLCLK */
#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK))
/* 检查系统时钟源状态是否有效(用于获取当前时钟源状态) */
#define IS_RCC_SYSCLKSOURCE_STATUS(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSI) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_HSE) || \
                                                ((__SOURCE__) == RCC_SYSCLKSOURCE_STATUS_PLLCLK))
/* 检查HCLK(AHB时钟)分频系数是否有效：1, 2, 4, 8, 16, 64, 128, 256, 512 */
#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1) || ((__HCLK__) == RCC_SYSCLK_DIV2) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4) || ((__HCLK__) == RCC_SYSCLK_DIV8) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16) || ((__HCLK__) == RCC_SYSCLK_DIV64) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512))
/* 检查PCLK(APB时钟)分频系数是否有效：1, 2, 4, 8, 16 */
#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16))
/* 检查MCO(微控制器时钟输出)配置是否有效 */
#define IS_RCC_MCO(__MCO__)  ((__MCO__) == RCC_MCO)
/* 检查MCO分频系数是否有效 */
#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1))
/* 检查RTC时钟源是否有效：无时钟、LSE、LSI、HSE 128分频 */
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

