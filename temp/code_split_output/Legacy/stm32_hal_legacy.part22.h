/* 为向后兼容而维护的别名定义 */
#define __HAL_RCC_OTGFS_FORCE_RESET    __HAL_RCC_USB_OTG_FS_FORCE_RESET    // 别名：强制复位 OTG FS（USB On-The-Go Full Speed）
#define __HAL_RCC_OTGFS_RELEASE_RESET  __HAL_RCC_USB_OTG_FS_RELEASE_RESET  // 别名：释放复位 OTG FS（USB On-The-Go Full Speed）

#define __ADC12_CLK_ENABLE          __HAL_RCC_ADC12_CLK_ENABLE            // 别名：使能 ADC12 时钟
#define __ADC12_CLK_DISABLE         __HAL_RCC_ADC12_CLK_DISABLE           // 别名：禁用 ADC12 时钟
#define __ADC34_CLK_ENABLE          __HAL_RCC_ADC34_CLK_ENABLE            // 别名：使能 ADC34 时钟
#define __ADC34_CLK_DISABLE         __HAL_RCC_ADC34_CLK_DISABLE           // 别名：禁用 ADC34 时钟
#define __DAC2_CLK_ENABLE           __HAL_RCC_DAC2_CLK_ENABLE             // 别名：使能 DAC2 时钟
#define __DAC2_CLK_DISABLE          __HAL_RCC_DAC2_CLK_DISABLE            // 别名：禁用 DAC2 时钟
#define __TIM18_CLK_ENABLE          __HAL_RCC_TIM18_CLK_ENABLE            // 别名：使能 TIM18 时钟
#define __TIM18_CLK_DISABLE         __HAL_RCC_TIM18_CLK_DISABLE           // 别名：禁用 TIM18 时钟
#define __TIM19_CLK_ENABLE          __HAL_RCC_TIM19_CLK_ENABLE            // 别名：使能 TIM19 时钟
#define __TIM19_CLK_DISABLE         __HAL_RCC_TIM19_CLK_DISABLE           // 别名：禁用 TIM19 时钟
#define __TIM20_CLK_ENABLE          __HAL_RCC_TIM20_CLK_ENABLE            // 别名：使能 TIM20 时钟
#define __TIM20_CLK_DISABLE         __HAL_RCC_TIM20_CLK_DISABLE           // 别名：禁用 TIM20 时钟
#define __HRTIM1_CLK_ENABLE         __HAL_RCC_HRTIM1_CLK_ENABLE           // 别名：使能 HRTIM1（高分辨率定时器1）时钟
#define __HRTIM1_CLK_DISABLE        __HAL_RCC_HRTIM1_CLK_DISABLE          // 别名：禁用 HRTIM1（高分辨率定时器1）时钟
#define __SDADC1_CLK_ENABLE         __HAL_RCC_SDADC1_CLK_ENABLE           // 别名：使能 SDADC1（Sigma-Delta ADC1）时钟
#define __SDADC2_CLK_ENABLE         __HAL_RCC_SDADC2_CLK_ENABLE           // 别名：使能 SDADC2（Sigma-Delta ADC2）时钟
#define __SDADC3_CLK_ENABLE         __HAL_RCC_SDADC3_CLK_ENABLE           // 别名：使能 SDADC3（Sigma-Delta ADC3）时钟
#define __SDADC1_CLK_DISABLE        __HAL_RCC_SDADC1_CLK_DISABLE          // 别名：禁用 SDADC1（Sigma-Delta ADC1）时钟
#define __SDADC2_CLK_DISABLE        __HAL_RCC_SDADC2_CLK_DISABLE          // 别名：禁用 SDADC2（Sigma-Delta ADC2）时钟
#define __SDADC3_CLK_DISABLE        __HAL_RCC_SDADC3_CLK_DISABLE          // 别名：禁用 SDADC3（Sigma-Delta ADC3）时钟

#define __ADC12_FORCE_RESET         __HAL_RCC_ADC12_FORCE_RESET           // 别名：强制复位 ADC12
#define __ADC12_RELEASE_RESET       __HAL_RCC_ADC12_RELEASE_RESET         // 别名：释放复位 ADC12
#define __ADC34_FORCE_RESET         __HAL_RCC_ADC34_FORCE_RESET           // 别名：强制复位 ADC34
#define __ADC34_RELEASE_RESET       __HAL_RCC_ADC34_RELEASE_RESET         // 别名：释放复位 ADC34
#define __DAC2_FORCE_RESET          __HAL_RCC_DAC2_FORCE_RESET            // 别名：强制复位 DAC2
#define __DAC2_RELEASE_RESET        __HAL_RCC_DAC2_RELEASE_RESET          // 别名：释放复位 DAC2
#define __TIM18_FORCE_RESET         __HAL_RCC_TIM18_FORCE_RESET           // 别名：强制复位 TIM18
#define __TIM18_RELEASE_RESET       __HAL_RCC_TIM18_RELEASE_RESET         // 别名：释放复位 TIM18
#define __TIM19_FORCE_RESET         __HAL_RCC_TIM19_FORCE_RESET           // 别名：强制复位 TIM19
#define __TIM19_RELEASE_RESET       __HAL_RCC_TIM19_RELEASE_RESET         // 别名：释放复位 TIM19
#define __TIM20_FORCE_RESET         __HAL_RCC_TIM20_FORCE_RESET           // 别名：强制复位 TIM20
#define __TIM20_RELEASE_RESET       __HAL_RCC_TIM20_RELEASE_RESET         // 别名：释放复位 TIM20
#define __HRTIM1_FORCE_RESET        __HAL_RCC_HRTIM1_FORCE_RESET          // 别名：强制复位 HRTIM1（高分辨率定时器1）
#define __HRTIM1_RELEASE_RESET      __HAL_RCC_HRTIM1_RELEASE_RESET        // 别名：释放复位 HRTIM1（高分辨率定时器1）
#define __SDADC1_FORCE_RESET        __HAL_RCC_SDADC1_FORCE_RESET          // 别名：强制复位 SDADC1（Sigma-Delta ADC1）
#define __SDADC2_FORCE_RESET        __HAL_RCC_SDADC2_FORCE_RESET          // 别名：强制复位 SDADC2（Sigma-Delta ADC2）
#define __SDADC3_FORCE_RESET        __HAL_RCC_SDADC3_FORCE_RESET          // 别名：强制复位 SDADC3（Sigma-Delta ADC3）
#define __SDADC1_RELEASE_RESET      __HAL_RCC_SDADC1_RELEASE_RESET        // 别名：释放复位 SDADC1（Sigma-Delta ADC1）
#define __SDADC2_RELEASE_RESET      __HAL_RCC_SDADC2_RELEASE_RESET        // 别名：释放复位 SDADC2（Sigma-Delta ADC2）
#define __SDADC3_RELEASE_RESET      __HAL_RCC_SDADC3_RELEASE_RESET        // 别名：释放复位 SDADC3（Sigma-Delta ADC3）