#if defined(STM32F7) || defined(STM32L4)
#define __HAL_RCC_SDIO_FORCE_RESET         __HAL_RCC_SDMMC1_FORCE_RESET         // SDIO强制复位宏，映射到SDMMC1的强制复位
#define __HAL_RCC_SDIO_RELEASE_RESET       __HAL_RCC_SDMMC1_RELEASE_RESET       // SDIO释放复位宏，映射到SDMMC1的释放复位
#define __HAL_RCC_SDIO_CLK_SLEEP_ENABLE    __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE    // SDIO睡眠时钟使能宏，映射到SDMMC1的睡眠时钟使能
#define __HAL_RCC_SDIO_CLK_SLEEP_DISABLE   __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE   // SDIO睡眠时钟禁用宏，映射到SDMMC1的睡眠时钟禁用
#define __HAL_RCC_SDIO_CLK_ENABLE          __HAL_RCC_SDMMC1_CLK_ENABLE          // SDIO时钟使能宏，映射到SDMMC1的时钟使能
#define __HAL_RCC_SDIO_CLK_DISABLE         __HAL_RCC_SDMMC1_CLK_DISABLE         // SDIO时钟禁用宏，映射到SDMMC1的时钟禁用
#define __HAL_RCC_SDIO_IS_CLK_ENABLED      __HAL_RCC_SDMMC1_IS_CLK_ENABLED      // 检查SDIO时钟是否使能的宏，映射到SDMMC1的检查
#define __HAL_RCC_SDIO_IS_CLK_DISABLED     __HAL_RCC_SDMMC1_IS_CLK_DISABLED     // 检查SDIO时钟是否禁用的宏，映射到SDMMC1的检查
#define SdioClockSelection                 Sdmmc1ClockSelection                // SDIO时钟选择类型别名，映射到SDMMC1时钟选择
#define RCC_PERIPHCLK_SDIO                 RCC_PERIPHCLK_SDMMC1                // SDIO外设时钟宏，映射到SDMMC1外设时钟
#define __HAL_RCC_SDIO_CONFIG              __HAL_RCC_SDMMC1_CONFIG              // SDIO配置宏，映射到SDMMC1配置
#define __HAL_RCC_GET_SDIO_SOURCE          __HAL_RCC_GET_SDMMC1_SOURCE          // 获取SDIO时钟源宏，映射到获取SDMMC1时钟源
#endif

#if defined(STM32F7)
#define RCC_SDIOCLKSOURCE_CLK48             RCC_SDMMC1CLKSOURCE_CLK48           // SDIO时钟源为CLK48，映射到SDMMC1时钟源CLK48
#define RCC_SDIOCLKSOURCE_SYSCLK           RCC_SDMMC1CLKSOURCE_SYSCLK           // SDIO时钟源为SYSCLK，映射到SDMMC1时钟源SYSCLK
#endif

#if defined(STM32H7)
#define __HAL_RCC_USB_OTG_HS_CLK_ENABLE()              __HAL_RCC_USB1_OTG_HS_CLK_ENABLE()              // USB OTG高速时钟使能宏，映射到USB1 OTG高速时钟使能
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_ENABLE()         __HAL_RCC_USB1_OTG_HS_ULPI_CLK_ENABLE()         // USB OTG高速ULPI时钟使能宏，映射到USB1 OTG高速ULPI时钟使能
#define __HAL_RCC_USB_OTG_HS_CLK_DISABLE()             __HAL_RCC_USB1_OTG_HS_CLK_DISABLE()             // USB OTG高速时钟禁用宏，映射到USB1 OTG高速时钟禁用
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_DISABLE()        __HAL_RCC_USB1_OTG_HS_ULPI_CLK_DISABLE()        // USB OTG高速ULPI时钟禁用宏，映射到USB1 OTG高速ULPI时钟禁用
#define __HAL_RCC_USB_OTG_HS_FORCE_RESET()             __HAL_RCC_USB1_OTG_HS_FORCE_RESET()             // USB OTG高速强制复位宏，映射到USB1 OTG高速强制复位
#define __HAL_RCC_USB_OTG_HS_RELEASE_RESET()           __HAL_RCC_USB1_OTG_HS_RELEASE_RESET()           // USB OTG高速释放复位宏，映射到USB1 OTG高速释放复位
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE()        __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_ENABLE()        // USB OTG高速睡眠时钟使能宏，映射到USB1 OTG高速睡眠时钟使能
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_ENABLE()   __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_ENABLE()   // USB OTG高速ULPI睡眠时钟使能宏，映射到USB1 OTG高速ULPI睡眠时钟使能
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE()       __HAL_RCC_USB1_OTG_HS_CLK_SLEEP_DISABLE()       // USB OTG高速睡眠时钟禁用宏，映射到USB1 OTG高速睡眠时钟禁用
#define __HAL_RCC_USB_OTG_HS_ULPI_CLK_SLEEP_DISABLE()  __HAL_RCC_USB1_OTG_HS_ULPI_CLK_SLEEP_DISABLE()  // USB OTG高速ULPI睡眠时钟禁用宏，映射到USB1 OTG高速ULPI睡眠时钟禁用

#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()             __HAL_RCC_USB2_OTG_FS_CLK_ENABLE()             // USB OTG全速时钟使能宏，映射到USB2 OTG全速时钟使能
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_ENABLE()        __HAL_RCC_USB2_OTG_FS_ULPI_CLK_ENABLE()        // USB OTG全速ULPI时钟使能宏，映射到USB2 OTG全速ULPI时钟使能
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()            __HAL_RCC_USB2_OTG_FS_CLK_DISABLE()            // USB OTG全速时钟禁用宏，映射到USB2 OTG全速时钟禁用
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_DISABLE()       __HAL_RCC_USB2_OTG_FS_ULPI_CLK_DISABLE()       // USB OTG全速ULPI时钟禁用宏，映射到USB2 OTG全速ULPI时钟禁用
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET()            __HAL_RCC_USB2_OTG_FS_FORCE_RESET()            // USB OTG全速强制复位宏，映射到USB2 OTG全速强制复位
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET()          __HAL_RCC_USB2_OTG_FS_RELEASE_RESET()          // USB OTG全速释放复位宏，映射到USB2 OTG全速释放复位
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()       __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_ENABLE()       // USB OTG全速睡眠时钟使能宏，映射到USB2 OTG全速睡眠时钟使能
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_ENABLE()  // USB OTG全速ULPI睡眠时钟使能宏，映射到USB2 OTG全速ULPI睡眠时钟使能
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE()      __HAL_RCC_USB2_OTG_FS_CLK_SLEEP_DISABLE()      // USB OTG全速睡眠时钟禁用宏，映射到USB2 OTG全速睡眠时钟禁用
#define __HAL_RCC_USB_OTG_FS_ULPI_CLK_SLEEP_DISABLE() __HAL_RCC_USB2_OTG_FS_ULPI_CLK_SLEEP_DISABLE() // USB OTG全速ULPI睡眠时钟禁用宏，映射到USB2 OTG全速ULPI睡眠时钟禁用
#endif

#define __HAL_RCC_I2SCLK            __HAL_RCC_I2S_CONFIG            // I2S时钟配置宏，映射到I2S配置宏
#define __HAL_RCC_I2SCLK_CONFIG     __HAL_RCC_I2S_CONFIG            // I2S时钟配置宏，映射到I2S配置宏

#define __RCC_PLLSRC                RCC_GET_PLL_OSCSOURCE           // 获取PLL振荡器源宏，映射到获取PLL振荡器源

#define IS_RCC_MSIRANGE             IS_RCC_MSI_CLOCK_RANGE          // 检查MSI时钟范围宏，映射到检查MSI时钟范围
#define IS_RCC_RTCCLK_SOURCE        IS_RCC_RTCCLKSOURCE            // 检查RTC时钟源宏，映射到检查RTC时钟源
#define IS_RCC_SYSCLK_DIV           IS_RCC_HCLK                    // 检查系统时钟分频宏，映射到检查HCLK分频
#define IS_RCC_HCLK_DIV             IS_RCC_PCLK                    // 检查HCLK分频宏，映射到检查PCLK分频
#define IS_RCC_PERIPHCLK            IS_RCC_PERIPHCLOCK             // 检查外设时钟宏，映射到检查外设时钟

#define RCC_IT_HSI14                RCC_IT_HSI14RDY                // HSI14就绪中断宏，映射到HSI14就绪中断

#define RCC_IT_CSSLSE               RCC_IT_LSECSS                  // LSE时钟安全系统中断宏，映射到LSE CSS中断
#define RCC_IT_CSSHSE               RCC_IT_CSS                     // HSE时钟安全系统中断宏，映射到CSS中断

#define RCC_PLLMUL_3                RCC_PLL_MUL3                   // PLL乘法因子3，映射到PLL乘法因子3
#define RCC_PLLMUL_4                RCC_PLL_MUL4                   // PLL乘法因子4，映射到PLL乘法因子4
#define RCC_PLLMUL_6                RCC_PLL_MUL6                   // PLL乘法因子6，映射到PLL乘法因子6
#define RCC_PLLMUL_8                RCC_PLL_MUL8                   // PLL乘法因子8，映射到PLL乘法因子8
#define RCC_PLLMUL_12               RCC_PLL_MUL12                  // PLL乘法因子12，映射到PLL乘法因子12
#define RCC_PLLMUL_16               RCC_PLL_MUL16                  // PLL乘法因子16，映射到PLL乘法因子16
#define RCC_PLLMUL_24               RCC_PLL_MUL24                  // PLL乘法因子24，映射到PLL乘法因子24
#define RCC_PLLMUL_32               RCC_PLL_MUL32                  // PLL乘法因子32，映射到PLL乘法因子32
#define RCC_PLLMUL_48               RCC_PLL_MUL48                  // PLL乘法因子48，映射到PLL乘法因子48

#define RCC_PLLDIV_2                RCC_PLL_DIV2                   // PLL除法因子2，映射到PLL除法因子2
#define RCC_PLLDIV_3                RCC_PLL_DIV3                   // PLL除法因子3，映射到PLL除法因子3
#define RCC_PLLDIV_4                RCC_PLL_DIV4                   // PLL除法因子4，映射到PLL除法因子4

#define IS_RCC_MCOSOURCE            IS_RCC_MCO1SOURCE              // 检查MCO时钟源宏，映射到检查MCO1时钟源
#define __HAL_RCC_MCO_CONFIG        __HAL_RCC_MCO1_CONFIG          // MCO配置宏，映射到MCO1配置
#define RCC_MCO_NODIV               RCC_MCODIV_1                   // MCO无分频，映射到MCO分频1
#define RCC_MCO_DIV1                RCC_MCODIV_1                   // MCO分频1，映射到MCO分频1
#define RCC_MCO_DIV2                RCC_MCODIV_2                   // MCO分频2，映射到MCO分频2
#define RCC_MCO_DIV4                RCC_MCODIV_4                   // MCO分频4，映射到MCO分频4
#define RCC_MCO_DIV8                RCC_MCODIV_8                   // MCO分频8，映射到MCO分频8
#define RCC_MCO_DIV16               RCC_MCODIV_16                  // MCO分频16，映射到MCO分频16
#define RCC_MCO_DIV32               RCC_MCODIV_32                  // MCO分频32，映射到MCO分频32
#define RCC_MCO_DIV64               RCC_MCODIV_64                  // MCO分频64，映射到MCO分频64
#define RCC_MCO_DIV128              RCC_MCODIV_128                 // MCO分频128，映射到MCO分频128
#define RCC_MCOSOURCE_NONE          RCC_MCO1SOURCE_NOCLOCK        // MCO时钟源为无时钟，映射到MCO1无时钟源
#define RCC_MCOSOURCE_LSI           RCC_MCO1SOURCE_LSI            // MCO时钟源为LSI，映射到MCO1 LSI时钟源
#define RCC_MCOSOURCE_LSE           RCC_MCO1SOURCE_LSE            // MCO时钟源为LSE，映射到MCO1 LSE时钟源
#define RCC_MCOSOURCE_SYSCLK        RCC_MCO1SOURCE_SYSCLK         // MCO时钟源为系统时钟，映射到MCO1系统时钟源
#define RCC_MCOSOURCE_HSI           RCC_MCO1SOURCE_HSI            // MCO时钟源为HSI，映射到MCO1 HSI时钟源
#define RCC_MCOSOURCE_HSI14         RCC_MCO1SOURCE_HSI14          // MCO时钟源为HSI14，映射到MCO1 HSI14时钟源
#define RCC_MCOSOURCE_HSI48         RCC_MCO1SOURCE_HSI48          // MCO时钟源为HSI48，映射到MCO1 HSI48时钟源
#define RCC_MCOSOURCE_HSE           RCC_MCO1SOURCE_HSE            // MCO时钟源为HSE，映射到MCO1 HSE时钟源
#define RCC_MCOSOURCE_PLLCLK_DIV1   RCC_MCO1SOURCE_PLLCLK         // MCO时钟源为PLL时钟（不分频），映射到MCO1 PLL时钟源
#define RCC_MCOSOURCE_PLLCLK_NODIV  RCC_MCO1SOURCE_PLLCLK         // MCO时钟源为PLL时钟（不分频），映射到MCO1 PLL时钟源
#define RCC_MCOSOURCE_PLLCLK_DIV2   RCC_MCO1SOURCE_PLLCLK_DIV2    // MCO时钟源为PLL时钟2分频，映射到MCO1 PLL时钟2分频源

#if defined(STM32U0)
#define RCC_SYSCLKSOURCE_STATUS_PLLR   RCC_SYSCLKSOURCE_STATUS_PLLCLK   // 系统时钟源状态为PLLR，映射到PLL时钟
#endif

#if defined(STM32L4) || defined(STM32WB) || defined(STM32G0) || defined(STM32G4) || defined(STM32L5) || \
    defined(STM32WL) || defined(STM32C0) || defined(STM32H7RS) || defined(STM32U0)
#define RCC_RTCCLKSOURCE_NO_CLK     RCC_RTCCLKSOURCE_NONE           // RTC时钟源为无时钟，映射到RTC时钟源无
#else
#define RCC_RTCCLKSOURCE_NONE       RCC_RTCCLKSOURCE_NO_CLK         // RTC时钟源为无，映射到RTC时钟源无时钟
#endif

#define RCC_USBCLK_PLLSAI1          RCC_USBCLKSOURCE_PLLSAI1        // USB时钟源为PLLSAI1
#define RCC_USBCLK_PLL              RCC_USBCLKSOURCE_PLL            // USB时钟源为PLL
#define RCC_USBCLK_MSI              RCC_USBCLKSOURCE_MSI            // USB时钟源为MSI
#define RCC_USBCLKSOURCE_PLLCLK     RCC_USBCLKSOURCE_PLL            // USB时钟源为PLL时钟，映射到USB时钟源PLL
#define RCC_USBPLLCLK_DIV1          RCC_USBCLKSOURCE_PLL            // USB PLL时钟不分频，映射到USB时钟源PLL
#define RCC_USBPLLCLK_DIV1_5        RCC_USBCLKSOURCE_PLL_DIV1_5     // USB PLL时钟1.5分频，映射到USB时钟源PLL 1.5分频
#define RCC_USBPLLCLK_DIV2          RCC_USBCLKSOURCE_PLL_DIV2       // USB PLL时钟2分频，映射到USB时钟源PLL 2分频
#define RCC_USBPLLCLK_DIV3          RCC_USBCLKSOURCE_PLL_DIV3       // USB PLL时钟3分频，映射到USB时钟源PLL 3分频

#define HSION_BitNumber        RCC_HSION_BIT_NUMBER                 // HSI使能位在寄存器中的位编号
#define HSION_BITNUMBER        RCC_HSION_BIT_NUMBER                 // HSI使能位在寄存器中的位编号
#define HSEON_BitNumber        RCC_HSEON_BIT_NUMBER                 // HSE使能位在寄存器中的位编号
#define HSEON_BITNUMBER        RCC_HSEON_BIT_NUMBER                 // HSE使能位在寄存器中的位编号
#define MSION_BITNUMBER        RCC_MSION_BIT_NUMBER                 // MSI使能位在寄存器中的位编号
#define CSSON_BitNumber        RCC_CSSON_BIT_NUMBER                 // CSS使能位在寄存器中的位编号
#define CSSON_BITNUMBER        RCC_CSSON_BIT_NUMBER                 // CSS使能位在寄存器中的位编号
#define PLLON_BitNumber        RCC_PLLON_BIT_NUMBER                 // PLL使能位在寄存器中的位编号
#define PLLON_BITNUMBER        RCC_PLLON_BIT_NUMBER                 // PLL使能位在寄存器中的位编号
#define PLLI2SON_BitNumber     RCC_PLLI2SON_BIT_NUMBER              // PLLI2S使能位在寄存器中的位编号
#define I2SSRC_BitNumber       RCC_I2SSRC_BIT_NUMBER                // I2S时钟源位在寄存器中的位编号
#define RTCEN_BitNumber        RCC_RTCEN_BIT_NUMBER                 // RTC使能位在寄存器中的位编号
#define RTCEN_BITNUMBER        RCC_RTCEN_BIT_NUMBER                 // RTC使能位在寄存器中的位编号
#define BDRST_BitNumber        RCC_BDRST_BIT_NUMBER                 // 备份域复位位在寄存器中的位编号
#define BDRST_BITNUMBER        RCC_BDRST_BIT_NUMBER                 // 备份域复位位在寄存器中的位编号
#define RTCRST_BITNUMBER       RCC_RTCRST_BIT_NUMBER                // RTC复位位在寄存器中的位编号
#define LSION_BitNumber        RCC_LSION_BIT_NUMBER                 // LSI使能位在寄存器中的位编号
#define LSION_BITNUMBER        RCC_LSION_BIT_NUMBER                 // LSI使能位在寄存器中的位编号
#define LSEON_BitNumber        RCC_LSEON_BIT_NUMBER                 // LSE使能位在寄存器中的位编号
#define LSEON_BITNUMBER        RCC_LSEON_BIT_NUMBER                 // LSE使能位在寄存器中的位编号
#define LSEBYP_BITNUMBER       RCC_LSEBYP_BIT_NUMBER                // LSE旁路位在寄存器中的位编号
#define PLLSAION_BitNumber     RCC_PLLSAION_BIT_NUMBER              // PLLSAI使能位在寄存器中的位编号
#define TIMPRE_BitNumber       RCC_TIMPRE_BIT_NUMBER                // 定时器时钟预分频位在寄存器中的位编号
#define RMVF_BitNumber         RCC_RMVF_BIT_NUMBER                  // 复位标志清除位在寄存器中的位编号
#define RMVF_BITNUMBER         RCC_RMVF_BIT_NUMBER                  // 复位标志清除位在寄存器中的位编号
#define RCC_CR2_HSI14TRIM_BitNumber RCC_HSI14TRIM_BIT_NUMBER        // HSI14微调位在寄存器中的位编号
#define CR_BYTE2_ADDRESS       RCC_CR_BYTE2_ADDRESS                 // CR寄存器字节2地址
#define CIR_BYTE1_ADDRESS      RCC_CIR_BYTE1_ADDRESS                // CIR寄存器字节1地址
#define CIR_BYTE2_ADDRESS      RCC_CIR_BYTE2_ADDRESS                // CIR寄存器字节2地址
#define BDCR_BYTE0_ADDRESS     RCC_BDCR_BYTE0_ADDRESS               // BDCR寄存器字节0地址
#define DBP_TIMEOUT_VALUE      RCC_DBP_TIMEOUT_VALUE                // 备份域保护解锁超时值
#define LSE_TIMEOUT_VALUE      RCC_LSE_TIMEOUT_VALUE                // LSE启动超时值

#define CR_HSION_BB            RCC_CR_HSION_BB                      // HSI使能位位带别名
#define CR_CSSON_BB            RCC_CR_CSSON_BB                      // CSS使能位位带别名
#define CR_PLLON_BB            RCC_CR_PLLON_BB                      // PLL使能位位带别名
#define CR_PLLI2SON_BB         RCC_CR_PLLI2SON_BB                   // PLLI2S使能位位带别名
#define CR_MSION_BB            RCC_CR_MSION_BB                      // MSI使能位位带别名
#define CSR_LSION_BB           RCC_CSR_LSION_BB                     // LSI使能位位带别名
#define CSR_LSEON_BB           RCC_CSR_LSEON_BB                     // LSE使能位位带别名
#define CSR_LSEBYP_BB          RCC_CSR_LSEBYP_BB                    // LSE旁路位位带别名
#define CSR_RTCEN_BB           RCC_CSR_RTCEN_BB                     // RTC使能位位带别名
#define CSR_RTCRST_BB          RCC_CSR_RTCRST_BB                    // RTC复位位位带别名
#define CFGR_I2SSRC_BB         RCC_CFGR_I2SSRC_BB                   // I2S时钟源位位带别名
#define BDCR_RTCEN_BB          RCC_BDCR_RTCEN_BB                    // RTC使能位位带别名（BDCR寄存器）
#define BDCR_BDRST_BB          RCC_BDCR_BDRST_BB                    // 备份域复位位位带别名
#define CR_HSEON_BB            RCC_CR_HSEON_BB                      // HSE使能位位带别名
#define CSR_RMVF_BB            RCC_CSR_RMVF_BB                      // 复位标志清除位位带别名
#define CR_PLLSAION_BB         RCC_CR_PLLSAION_BB                   // PLLSAI使能位位带别名
#define DCKCFGR_TIMPRE_BB      RCC_DCKCFGR_TIMPRE_BB                // 定时器时钟预分频位位带别名

#define __HAL_RCC_CRS_ENABLE_FREQ_ERROR_COUNTER     __HAL_RCC_CRS_FREQ_ERROR_COUNTER_ENABLE      // CRS频率误差计数器使能宏，映射到CRS频率误差计数器使能
#define __HAL_RCC_CRS_DISABLE_FREQ_ERROR_COUNTER    __HAL_RCC_CRS_FREQ_ERROR_COUNTER_DISABLE     // CRS频率误差计数器禁用宏，映射到CRS频率误差计数器禁用
#define __HAL_RCC_CRS_ENABLE_AUTOMATIC_CALIB        __HAL_RCC_CRS_AUTOMATIC_CALIB_ENABLE         // CRS自动校准使能宏，映射到CRS自动校准使能
#define __HAL_RCC_CRS_DISABLE_AUTOMATIC_CALIB       __HAL_RCC_CRS_AUTOMATIC_CALIB_DISABLE        // CRS自动校准禁用宏，映射到CRS自动校准禁用
#define __HAL_RCC_CRS_CALCULATE_RELOADVALUE         __HAL_RCC_CRS_RELOADVALUE_CALCULATE          // CRS计算重载值宏，映射到CRS计算重载值

#define __HAL_RCC_GET_IT_SOURCE                     __HAL_RCC_GET_IT                             // 获取中断源宏，映射到获取中断宏

#define RCC_CRS_SYNCWARM       RCC_CRS_SYNCWARN                      // CRS同步警告标志，映射到CRS同步警告
#define RCC_CRS_TRIMOV         RCC_CRS_TRIMOVF                       // CRS微调溢出标志，映射到CRS微调溢出

#define RCC_PERIPHCLK_CK48               RCC_PERIPHCLK_CLK48          // 外设时钟CK48，映射到外设时钟CLK48
#define RCC_CK48CLKSOURCE_PLLQ           RCC_CLK48CLKSOURCE_PLLQ      // CK48时钟源为PLLQ，映射到CLK48时钟源PLLQ
#define RCC_CK48CLKSOURCE_PLLSAIP        RCC_CLK48CLKSOURCE_PLLSAIP   // CK48时钟源为PLLSAIP，映射到CLK48时钟源PLLSAIP
#define RCC_CK48CLKSOURCE_PLLI2SQ        RCC_CLK48CLKSOURCE_PLLI2SQ   // CK48时钟源为PLLI2SQ，映射到CLK48时钟源PLLI2SQ
#define IS_RCC_CK48CLKSOURCE             IS_RCC_CLK48CLKSOURCE        // 检查CK48时钟源宏，映射到检查CLK48时钟源
#define RCC_SDIOCLKSOURCE_CK48           RCC_SDIOCLKSOURCE_CLK48      // SDIO时钟源为CK48，映射到SDIO时钟源CLK48