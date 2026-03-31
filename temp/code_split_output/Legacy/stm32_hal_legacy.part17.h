/* ADC（模数转换器）时钟控制宏定义 */
#define __ADC_CLK_DISABLE          __HAL_RCC_ADC_CLK_DISABLE          /* 禁用ADC时钟 */
#define __ADC_CLK_ENABLE           __HAL_RCC_ADC_CLK_ENABLE           /* 使能ADC时钟 */
#define __ADC_CLK_SLEEP_DISABLE    __HAL_RCC_ADC_CLK_SLEEP_DISABLE    /* 休眠模式下禁用ADC时钟 */
#define __ADC_CLK_SLEEP_ENABLE     __HAL_RCC_ADC_CLK_SLEEP_ENABLE     /* 休眠模式下使能ADC时钟 */
#define __ADC_FORCE_RESET          __HAL_RCC_ADC_FORCE_RESET          /* 强制复位ADC */
#define __ADC_RELEASE_RESET        __HAL_RCC_ADC_RELEASE_RESET        /* 释放ADC复位 */

/* ADC1（模数转换器1）时钟控制宏定义 */
#define __ADC1_CLK_DISABLE         __HAL_RCC_ADC1_CLK_DISABLE         /* 禁用ADC1时钟 */
#define __ADC1_CLK_ENABLE          __HAL_RCC_ADC1_CLK_ENABLE          /* 使能ADC1时钟 */
#define __ADC1_FORCE_RESET         __HAL_RCC_ADC1_FORCE_RESET         /* 强制复位ADC1 */
#define __ADC1_RELEASE_RESET       __HAL_RCC_ADC1_RELEASE_RESET       /* 释放ADC1复位 */
#define __ADC1_CLK_SLEEP_ENABLE    __HAL_RCC_ADC1_CLK_SLEEP_ENABLE    /* 休眠模式下使能ADC1时钟 */
#define __ADC1_CLK_SLEEP_DISABLE   __HAL_RCC_ADC1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用ADC1时钟 */

/* ADC2（模数转换器2）时钟控制宏定义 */
#define __ADC2_CLK_DISABLE         __HAL_RCC_ADC2_CLK_DISABLE         /* 禁用ADC2时钟 */
#define __ADC2_CLK_ENABLE          __HAL_RCC_ADC2_CLK_ENABLE          /* 使能ADC2时钟 */
#define __ADC2_FORCE_RESET         __HAL_RCC_ADC2_FORCE_RESET         /* 强制复位ADC2 */
#define __ADC2_RELEASE_RESET       __HAL_RCC_ADC2_RELEASE_RESET       /* 释放ADC2复位 */

/* ADC3（模数转换器3）时钟控制宏定义 */
#define __ADC3_CLK_DISABLE         __HAL_RCC_ADC3_CLK_DISABLE         /* 禁用ADC3时钟 */
#define __ADC3_CLK_ENABLE          __HAL_RCC_ADC3_CLK_ENABLE          /* 使能ADC3时钟 */
#define __ADC3_FORCE_RESET         __HAL_RCC_ADC3_FORCE_RESET         /* 强制复位ADC3 */
#define __ADC3_RELEASE_RESET       __HAL_RCC_ADC3_RELEASE_RESET       /* 释放ADC3复位 */

/* AES（高级加密标准）时钟控制宏定义 */
#define __AES_CLK_DISABLE          __HAL_RCC_AES_CLK_DISABLE          /* 禁用AES时钟 */
#define __AES_CLK_ENABLE           __HAL_RCC_AES_CLK_ENABLE           /* 使能AES时钟 */
#define __AES_CLK_SLEEP_DISABLE    __HAL_RCC_AES_CLK_SLEEP_DISABLE    /* 休眠模式下禁用AES时钟 */
#define __AES_CLK_SLEEP_ENABLE     __HAL_RCC_AES_CLK_SLEEP_ENABLE     /* 休眠模式下使能AES时钟 */
#define __AES_FORCE_RESET          __HAL_RCC_AES_FORCE_RESET          /* 强制复位AES */
#define __AES_RELEASE_RESET        __HAL_RCC_AES_RELEASE_RESET        /* 释放AES复位 */

/* CRYP（加密）时钟控制宏定义 */
#define __CRYP_CLK_SLEEP_ENABLE    __HAL_RCC_CRYP_CLK_SLEEP_ENABLE    /* 休眠模式下使能CRYP时钟 */
#define __CRYP_CLK_SLEEP_DISABLE   __HAL_RCC_CRYP_CLK_SLEEP_DISABLE   /* 休眠模式下禁用CRYP时钟 */
#define __CRYP_CLK_ENABLE          __HAL_RCC_CRYP_CLK_ENABLE          /* 使能CRYP时钟 */
#define __CRYP_CLK_DISABLE         __HAL_RCC_CRYP_CLK_DISABLE         /* 禁用CRYP时钟 */
#define __CRYP_FORCE_RESET         __HAL_RCC_CRYP_FORCE_RESET         /* 强制复位CRYP */
#define __CRYP_RELEASE_RESET       __HAL_RCC_CRYP_RELEASE_RESET       /* 释放CRYP复位 */

/* AFIO（复用功能I/O）时钟控制宏定义 */
#define __AFIO_CLK_DISABLE         __HAL_RCC_AFIO_CLK_DISABLE         /* 禁用AFIO时钟 */
#define __AFIO_CLK_ENABLE          __HAL_RCC_AFIO_CLK_ENABLE          /* 使能AFIO时钟 */
#define __AFIO_FORCE_RESET         __HAL_RCC_AFIO_FORCE_RESET         /* 强制复位AFIO */
#define __AFIO_RELEASE_RESET       __HAL_RCC_AFIO_RELEASE_RESET       /* 释放AFIO复位 */

/* AHB总线复位控制宏定义 */
#define __AHB_FORCE_RESET          __HAL_RCC_AHB_FORCE_RESET          /* 强制复位AHB总线 */
#define __AHB_RELEASE_RESET        __HAL_RCC_AHB_RELEASE_RESET        /* 释放AHB总线复位 */
#define __AHB1_FORCE_RESET         __HAL_RCC_AHB1_FORCE_RESET         /* 强制复位AHB1总线 */
#define __AHB1_RELEASE_RESET       __HAL_RCC_AHB1_RELEASE_RESET       /* 释放AHB1总线复位 */
#define __AHB2_FORCE_RESET         __HAL_RCC_AHB2_FORCE_RESET         /* 强制复位AHB2总线 */
#define __AHB2_RELEASE_RESET       __HAL_RCC_AHB2_RELEASE_RESET       /* 释放AHB2总线复位 */
#define __AHB3_FORCE_RESET         __HAL_RCC_AHB3_FORCE_RESET         /* 强制复位AHB3总线 */
#define __AHB3_RELEASE_RESET       __HAL_RCC_AHB3_RELEASE_RESET       /* 释放AHB3总线复位 */

/* APB总线复位控制宏定义 */
#define __APB1_FORCE_RESET         __HAL_RCC_APB1_FORCE_RESET         /* 强制复位APB1总线 */
#define __APB1_RELEASE_RESET       __HAL_RCC_APB1_RELEASE_RESET       /* 释放APB1总线复位 */
#define __APB2_FORCE_RESET         __HAL_RCC_APB2_FORCE_RESET         /* 强制复位APB2总线 */
#define __APB2_RELEASE_RESET       __HAL_RCC_APB2_RELEASE_RESET       /* 释放APB2总线复位 */

/* 针对STM32C0系列的特殊定义 */
#if defined(STM32C0)
#define __HAL_RCC_APB1_FORCE_RESET    __HAL_RCC_APB1_GRP1_FORCE_RESET    /* 强制复位APB1组1（STM32C0专用） */
#define __HAL_RCC_APB1_RELEASE_RESET  __HAL_RCC_APB1_GRP1_RELEASE_RESET  /* 释放APB1组1复位（STM32C0专用） */
#define __HAL_RCC_APB2_FORCE_RESET    __HAL_RCC_APB1_GRP2_FORCE_RESET    /* 强制复位APB1组2（STM32C0专用） */
#define __HAL_RCC_APB2_RELEASE_RESET  __HAL_RCC_APB1_GRP2_RELEASE_RESET  /* 释放APB1组2复位（STM32C0专用） */
#endif /* STM32C0 */

/* BKP（备份寄存器）时钟控制宏定义 */
#define __BKP_CLK_DISABLE          __HAL_RCC_BKP_CLK_DISABLE          /* 禁用BKP时钟 */
#define __BKP_CLK_ENABLE           __HAL_RCC_BKP_CLK_ENABLE           /* 使能BKP时钟 */
#define __BKP_FORCE_RESET          __HAL_RCC_BKP_FORCE_RESET          /* 强制复位BKP */
#define __BKP_RELEASE_RESET        __HAL_RCC_BKP_RELEASE_RESET        /* 释放BKP复位 */

/* CAN1（控制器局域网1）时钟控制宏定义 */
#define __CAN1_CLK_DISABLE         __HAL_RCC_CAN1_CLK_DISABLE         /* 禁用CAN1时钟 */
#define __CAN1_CLK_ENABLE          __HAL_RCC_CAN1_CLK_ENABLE          /* 使能CAN1时钟 */
#define __CAN1_CLK_SLEEP_DISABLE   __HAL_RCC_CAN1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用CAN1时钟 */
#define __CAN1_CLK_SLEEP_ENABLE    __HAL_RCC_CAN1_CLK_SLEEP_ENABLE    /* 休眠模式下使能CAN1时钟 */
#define __CAN1_FORCE_RESET         __HAL_RCC_CAN1_FORCE_RESET         /* 强制复位CAN1 */
#define __CAN1_RELEASE_RESET       __HAL_RCC_CAN1_RELEASE_RESET       /* 释放CAN1复位 */

/* CAN（控制器局域网）通用时钟控制宏定义 */
#define __CAN_CLK_DISABLE          __HAL_RCC_CAN1_CLK_DISABLE         /* 禁用CAN时钟（通常指向CAN1） */
#define __CAN_CLK_ENABLE           __HAL_RCC_CAN1_CLK_ENABLE          /* 使能CAN时钟（通常指向CAN1） */
#define __CAN_FORCE_RESET          __HAL_RCC_CAN1_FORCE_RESET         /* 强制复位CAN（通常指向CAN1） */
#define __CAN_RELEASE_RESET        __HAL_RCC_CAN1_RELEASE_RESET       /* 释放CAN复位（通常指向CAN1） */

/* CAN2（控制器局域网2）时钟控制宏定义 */
#define __CAN2_CLK_DISABLE         __HAL_RCC_CAN2_CLK_DISABLE         /* 禁用CAN2时钟 */
#define __CAN2_CLK_ENABLE          __HAL_RCC_CAN2_CLK_ENABLE          /* 使能CAN2时钟 */
#define __CAN2_FORCE_RESET         __HAL_RCC_CAN2_FORCE_RESET         /* 强制复位CAN2 */
#define __CAN2_RELEASE_RESET       __HAL_RCC_CAN2_RELEASE_RESET       /* 释放CAN2复位 */

/* CEC（消费电子控制）时钟控制宏定义 */
#define __CEC_CLK_DISABLE          __HAL_RCC_CEC_CLK_DISABLE          /* 禁用CEC时钟 */
#define __CEC_CLK_ENABLE           __HAL_RCC_CEC_CLK_ENABLE           /* 使能CEC时钟 */
#define __CEC_FORCE_RESET          __HAL_RCC_CEC_FORCE_RESET          /* 强制复位CEC */
#define __CEC_RELEASE_RESET        __HAL_RCC_CEC_RELEASE_RESET        /* 释放CEC复位 */

/* COMP（比较器）时钟控制宏定义 */
#define __COMP_CLK_DISABLE         __HAL_RCC_COMP_CLK_DISABLE         /* 禁用COMP时钟 */
#define __COMP_CLK_ENABLE          __HAL_RCC_COMP_CLK_ENABLE          /* 使能COMP时钟 */
#define __COMP_FORCE_RESET         __HAL_RCC_COMP_FORCE_RESET         /* 强制复位COMP */
#define __COMP_RELEASE_RESET       __HAL_RCC_COMP_RELEASE_RESET       /* 释放COMP复位 */
#define __COMP_CLK_SLEEP_ENABLE    __HAL_RCC_COMP_CLK_SLEEP_ENABLE    /* 休眠模式下使能COMP时钟 */
#define __COMP_CLK_SLEEP_DISABLE   __HAL_RCC_COMP_CLK_SLEEP_DISABLE   /* 休眠模式下禁用COMP时钟 */

/* CRC（循环冗余校验）时钟控制宏定义 */
#define __CRC_CLK_DISABLE          __HAL_RCC_CRC_CLK_DISABLE          /* 禁用CRC时钟 */
#define __CRC_CLK_ENABLE           __HAL_RCC_CRC_CLK_ENABLE           /* 使能CRC时钟 */
#define __CRC_CLK_SLEEP_DISABLE    __HAL_RCC_CRC_CLK_SLEEP_DISABLE    /* 休眠模式下禁用CRC时钟 */
#define __CRC_CLK_SLEEP_ENABLE     __HAL_RCC_CRC_CLK_SLEEP_ENABLE     /* 休眠模式下使能CRC时钟 */
#define __CRC_FORCE_RESET          __HAL_RCC_CRC_FORCE_RESET          /* 强制复位CRC */
#define __CRC_RELEASE_RESET        __HAL_RCC_CRC_RELEASE_RESET        /* 释放CRC复位 */

/* DAC（数模转换器）时钟控制宏定义 */
#define __DAC_CLK_DISABLE          __HAL_RCC_DAC_CLK_DISABLE          /* 禁用DAC时钟 */
#define __DAC_CLK_ENABLE           __HAL_RCC_DAC_CLK_ENABLE           /* 使能DAC时钟 */
#define __DAC_FORCE_RESET          __HAL_RCC_DAC_FORCE_RESET          /* 强制复位DAC */
#define __DAC_RELEASE_RESET        __HAL_RCC_DAC_RELEASE_RESET        /* 释放DAC复位 */

/* DAC1（数模转换器1）时钟控制宏定义 */
#define __DAC1_CLK_DISABLE         __HAL_RCC_DAC1_CLK_DISABLE         /* 禁用DAC1时钟 */
#define __DAC1_CLK_ENABLE          __HAL_RCC_DAC1_CLK_ENABLE          /* 使能DAC1时钟 */
#define __DAC1_CLK_SLEEP_DISABLE   __HAL_RCC_DAC1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用DAC1时钟 */
#define __DAC1_CLK_SLEEP_ENABLE    __HAL_RCC_DAC1_CLK_SLEEP_ENABLE    /* 休眠模式下使能DAC1时钟 */
#define __DAC1_FORCE_RESET         __HAL_RCC_DAC1_FORCE_RESET         /* 强制复位DAC1 */
#define __DAC1_RELEASE_RESET       __HAL_RCC_DAC1_RELEASE_RESET       /* 释放DAC1复位 */

/* DBGMCU（调试MCU）时钟控制宏定义 */
#define __DBGMCU_CLK_ENABLE        __HAL_RCC_DBGMCU_CLK_ENABLE        /* 使能DBGMCU时钟 */
#define __DBGMCU_CLK_DISABLE       __HAL_RCC_DBGMCU_CLK_DISABLE       /* 禁用DBGMCU时钟 */
#define __DBGMCU_FORCE_RESET       __HAL_RCC_DBGMCU_FORCE_RESET       /* 强制复位DBGMCU */
#define __DBGMCU_RELEASE_RESET     __HAL_RCC_DBGMCU_RELEASE_RESET     /* 释放DBGMCU复位 */

/* DFSDM（数字滤波器用于sigma-delta调制器）时钟控制宏定义 */
#define __DFSDM_CLK_DISABLE        __HAL_RCC_DFSDM_CLK_DISABLE        /* 禁用DFSDM时钟 */
#define __DFSDM_CLK_ENABLE         __HAL_RCC_DFSDM_CLK_ENABLE         /* 使能DFSDM时钟 */
#define __DFSDM_CLK_SLEEP_DISABLE  __HAL_RCC_DFSDM_CLK_SLEEP_DISABLE  /* 休眠模式下禁用DFSDM时钟 */
#define __DFSDM_CLK_SLEEP_ENABLE   __HAL_RCC_DFSDM_CLK_SLEEP_ENABLE   /* 休眠模式下使能DFSDM时钟 */
#define __DFSDM_FORCE_RESET        __HAL_RCC_DFSDM_FORCE_RESET        /* 强制复位DFSDM */
#define __DFSDM_RELEASE_RESET      __HAL_RCC_DFSDM_RELEASE_RESET      /* 释放DFSDM复位 */

/* DMA1（直接存储器访问1）时钟控制宏定义 */
#define __DMA1_CLK_DISABLE         __HAL_RCC_DMA1_CLK_DISABLE         /* 禁用DMA1时钟 */
#define __DMA1_CLK_ENABLE          __HAL_RCC_DMA1_CLK_ENABLE          /* 使能DMA1时钟 */
#define __DMA1_CLK_SLEEP_DISABLE   __HAL_RCC_DMA1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用DMA1时钟 */
#define __DMA1_CLK_SLEEP_ENABLE    __HAL_RCC_DMA1_CLK_SLEEP_ENABLE    /* 休眠模式下使能DMA1时钟 */
#define __DMA1_FORCE_RESET         __HAL_RCC_DMA1_FORCE_RESET         /* 强制复位DMA1 */
#define __DMA1_RELEASE_RESET       __HAL_RCC_DMA1_RELEASE_RESET       /* 释放DMA1复位 */

/* DMA2（直接存储器访问2）时钟控制宏定义 */
#define __DMA2_CLK_DISABLE         __HAL_RCC_DMA2_CLK_DISABLE         /* 禁用DMA2时钟 */
#define __DMA2_CLK_ENABLE          __HAL_RCC_DMA2_CLK_ENABLE          /* 使能DMA2时钟 */
#define __DMA2_CLK_SLEEP_DISABLE   __HAL_RCC_DMA2_CLK_SLEEP_DISABLE   /* 休眠模式下禁用DMA2时钟 */
#define __DMA2_CLK_SLEEP_ENABLE    __HAL_RCC_DMA2_CLK_SLEEP_ENABLE    /* 休眠模式下使能DMA2时钟 */
#define __DMA2_FORCE_RESET         __HAL_RCC_DMA2_FORCE_RESET         /* 强制复位DMA2 */
#define __DMA2_RELEASE_RESET       __HAL_RCC_DMA2_RELEASE_RESET       /* 释放DMA2复位 */

/* ETHMAC（以太网MAC）时钟控制宏定义 */
#define __ETHMAC_CLK_DISABLE       __HAL_RCC_ETHMAC_CLK_DISABLE       /* 禁用ETHMAC时钟 */
#define __ETHMAC_CLK_ENABLE        __HAL_RCC_ETHMAC_CLK_ENABLE        /* 使能ETHMAC时钟 */
#define __ETHMAC_FORCE_RESET       __HAL_RCC_ETHMAC_FORCE_RESET       /* 强制复位ETHMAC */
#define __ETHMAC_RELEASE_RESET     __HAL_RCC_ETHMAC_RELEASE_RESET     /* 释放ETHMAC复位 */
#define __ETHMACRX_CLK_DISABLE     __HAL_RCC_ETHMACRX_CLK_DISABLE     /* 禁用ETHMAC接收时钟 */
#define __ETHMACRX_CLK_ENABLE      __HAL_RCC_ETHMACRX_CLK_ENABLE      /* 使能ETHMAC接收时钟 */
#define __ETHMACTX_CLK_DISABLE     __HAL_RCC_ETHMACTX_CLK_DISABLE     /* 禁用ETHMAC发送时钟 */
#define __ETHMACTX_CLK_ENABLE      __HAL_RCC_ETHMACTX_CLK_ENABLE      /* 使能ETHMAC发送时钟 */

/* FIREWALL（防火墙）时钟控制宏定义 */
#define __FIREWALL_CLK_DISABLE     __HAL_RCC_FIREWALL_CLK_DISABLE     /* 禁用防火墙时钟 */
#define __FIREWALL_CLK_ENABLE      __HAL_RCC_FIREWALL_CLK_ENABLE      /* 使能防火墙时钟 */

/* FLASH（闪存）时钟控制宏定义 */
#define __FLASH_CLK_DISABLE        __HAL_RCC_FLASH_CLK_DISABLE        /* 禁用FLASH时钟 */
#define __FLASH_CLK_ENABLE         __HAL_RCC_FLASH_CLK_ENABLE         /* 使能FLASH时钟 */
#define __FLASH_CLK_SLEEP_DISABLE  __HAL_RCC_FLASH_CLK_SLEEP_DISABLE  /* 休眠模式下禁用FLASH时钟 */
#define __FLASH_CLK_SLEEP_ENABLE   __HAL_RCC_FLASH_CLK_SLEEP_ENABLE   /* 休眠模式下使能FLASH时钟 */
#define __FLASH_FORCE_RESET        __HAL_RCC_FLASH_FORCE_RESET        /* 强制复位FLASH */
#define __FLASH_RELEASE_RESET      __HAL_RCC_FLASH_RELEASE_RESET      /* 释放FLASH复位 */

/* FLITF（闪存接口）时钟控制宏定义 */
#define __FLITF_CLK_DISABLE        __HAL_RCC_FLITF_CLK_DISABLE        /* 禁用FLITF时钟 */
#define __FLITF_CLK_ENABLE         __HAL_RCC_FLITF_CLK_ENABLE         /* 使能FLITF时钟 */
#define __FLITF_FORCE_RESET        __HAL_RCC_FLITF_FORCE_RESET        /* 强制复位FLITF */
#define __FLITF_RELEASE_RESET      __HAL_RCC_FLITF_RELEASE_RESET      /* 释放FLITF复位 */
#define __FLITF_CLK_SLEEP_ENABLE   __HAL_RCC_FLITF_CLK_SLEEP_ENABLE   /* 休眠模式下使能FLITF时钟 */
#define __FLITF_CLK_SLEEP_DISABLE  __HAL_RCC_FLITF_CLK_SLEEP_DISABLE  /* 休眠模式下禁用FLITF时钟 */

/* FMC（灵活存储器控制器）时钟控制宏定义 */
#define __FMC_CLK_DISABLE          __HAL_RCC_FMC_CLK_DISABLE          /* 禁用FMC时钟 */
#define __FMC_CLK_ENABLE           __HAL_RCC_FMC_CLK_ENABLE           /* 使能FMC时钟 */
#define __FMC_CLK_SLEEP_DISABLE    __HAL_RCC_FMC_CLK_SLEEP_DISABLE    /* 休眠模式下禁用FMC时钟 */
#define __FMC_CLK_SLEEP_ENABLE     __HAL_RCC_FMC_CLK_SLEEP_ENABLE     /* 休眠模式下使能FMC时钟 */
#define __FMC_FORCE_RESET          __HAL_RCC_FMC_FORCE_RESET          /* 强制复位FMC */
#define __FMC_RELEASE_RESET        __HAL_RCC_FMC_RELEASE_RESET        /* 释放FMC复位 */

/* FSMC（灵活静态存储器控制器）时钟控制宏定义 */
#define __FSMC_CLK_DISABLE         __HAL_RCC_FSMC_CLK_DISABLE         /* 禁用FSMC时钟 */
#define __FSMC_CLK_ENABLE          __HAL_RCC_FSMC_CLK_ENABLE          /* 使能FSMC时钟 */

/* GPIOA时钟控制宏定义 */
#define __GPIOA_CLK_DISABLE        __HAL_RCC_GPIOA_CLK_DISABLE        /* 禁用GPIOA时钟 */
#define __GPIOA_CLK_ENABLE         __HAL_RCC_GPIOA_CLK_ENABLE         /* 使能GPIOA时钟 */
#define __GPIOA_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOA时钟 */
#define __GPIOA_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOA时钟 */
#define __GPIOA_FORCE_RESET        __HAL_RCC_GPIOA_FORCE_RESET        /* 强制复位GPIOA */
#define __GPIOA_RELEASE_RESET      __HAL_RCC_GPIOA_RELEASE_RESET      /* 释放GPIOA复位 */

/* GPIOB时钟控制宏定义 */
#define __GPIOB_CLK_DISABLE        __HAL_RCC_GPIOB_CLK_DISABLE        /* 禁用GPIOB时钟 */
#define __GPIOB_CLK_ENABLE         __HAL_RCC_GPIOB_CLK_ENABLE         /* 使能GPIOB时钟 */
#define __GPIOB_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOB时钟 */
#define __GPIOB_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOB时钟 */
#define __GPIOB_FORCE_RESET        __HAL_RCC_GPIOB_FORCE_RESET        /* 强制复位GPIOB */
#define __GPIOB_RELEASE_RESET      __HAL_RCC_GPIOB_RELEASE_RESET      /* 释放GPIOB复位 */

/* GPIOC时钟控制宏定义 */
#define __GPIOC_CLK_DISABLE        __HAL_RCC_GPIOC_CLK_DISABLE        /* 禁用GPIOC时钟 */
#define __GPIOC_CLK_ENABLE         __HAL_RCC_GPIOC_CLK_ENABLE         /* 使能GPIOC时钟 */
#define __GPIOC_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOC时钟 */
#define __GPIOC_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOC时钟 */
#define __GPIOC_FORCE_RESET        __HAL_RCC_GPIOC_FORCE_RESET        /* 强制复位GPIOC */
#define __GPIOC_RELEASE_RESET      __HAL_RCC_GPIOC_RELEASE_RESET      /* 释放GPIOC复位 */

/* GPIOD时钟控制宏定义 */
#define __GPIOD_CLK_DISABLE        __HAL_RCC_GPIOD_CLK_DISABLE        /* 禁用GPIOD时钟 */
#define __GPIOD_CLK_ENABLE         __HAL_RCC_GPIOD_CLK_ENABLE         /* 使能GPIOD时钟 */
#define __GPIOD_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOD时钟 */
#define __GPIOD_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOD时钟 */
#define __GPIOD_FORCE_RESET        __HAL_RCC_GPIOD_FORCE_RESET        /* 强制复位GPIOD */
#define __GPIOD_RELEASE_RESET      __HAL_RCC_GPIOD_RELEASE_RESET      /* 释放GPIOD复位 */

/* GPIOE时钟控制宏定义 */
#define __GPIOE_CLK_DISABLE        __HAL_RCC_GPIOE_CLK_DISABLE        /* 禁用GPIOE时钟 */
#define __GPIOE_CLK_ENABLE         __HAL_RCC_GPIOE_CLK_ENABLE         /* 使能GPIOE时钟 */
#define __GPIOE_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOE时钟 */
#define __GPIOE_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOE时钟 */
#define __GPIOE_FORCE_RESET        __HAL_RCC_GPIOE_FORCE_RESET        /* 强制复位GPIOE */
#define __GPIOE_RELEASE_RESET      __HAL_RCC_GPIOE_RELEASE_RESET      /* 释放GPIOE复位 */

/* GPIOF时钟控制宏定义 */
#define __GPIOF_CLK_DISABLE        __HAL_RCC_GPIOF_CLK_DISABLE        /* 禁用GPIOF时钟 */
#define __GPIOF_CLK_ENABLE         __HAL_RCC_GPIOF_CLK_ENABLE         /* 使能GPIOF时钟 */
#define __GPIOF_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOF时钟 */
#define __GPIOF_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOF时钟 */
#define __GPIOF_FORCE_RESET        __HAL_RCC_GPIOF_FORCE_RESET        /* 强制复位GPIOF */
#define __GPIOF_RELEASE_RESET      __HAL_RCC_GPIOF_RELEASE_RESET      /* 释放GPIOF复位 */

/* GPIOG时钟控制宏定义 */
#define __GPIOG_CLK_DISABLE        __HAL_RCC_GPIOG_CLK_DISABLE        /* 禁用GPIOG时钟 */
#define __GPIOG_CLK_ENABLE         __HAL_RCC_GPIOG_CLK_ENABLE         /* 使能GPIOG时钟 */
#define __GPIOG_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOG时钟 */
#define __GPIOG_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOG时钟 */
#define __GPIOG_FORCE_RESET        __HAL_RCC_GPIOG_FORCE_RESET        /* 强制复位GPIOG */
#define __GPIOG_RELEASE_RESET      __HAL_RCC_GPIOG_RELEASE_RESET      /* 释放GPIOG复位 */

/* GPIOH时钟控制宏定义 */
#define __GPIOH_CLK_DISABLE        __HAL_RCC_GPIOH_CLK_DISABLE        /* 禁用GPIOH时钟 */
#define __GPIOH_CLK_ENABLE         __HAL_RCC_GPIOH_CLK_ENABLE         /* 使能GPIOH时钟 */
#define __GPIOH_CLK_SLEEP_DISABLE  __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE  /* 休眠模式下禁用GPIOH时钟 */
#define __GPIOH_CLK_SLEEP_ENABLE   __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE   /* 休眠模式下使能GPIOH时钟 */
#define __GPIOH_FORCE_RESET        __HAL_RCC_GPIOH_FORCE_RESET        /* 强制复位GPIOH */
#define __GPIOH_RELEASE_RESET      __HAL_RCC_GPIOH_RELEASE_RESET      /* 释放GPIOH复位 */

/* I2C1时钟控制宏定义 */
#define __I2C1_CLK_DISABLE         __HAL_RCC_I2C1_CLK_DISABLE         /* 禁用I2C1时钟 */
#define __I2C1_CLK_ENABLE          __HAL_RCC_I2C1_CLK_ENABLE          /* 使能I2C1时钟 */
#define __I2C1_CLK_SLEEP_DISABLE   __HAL_RCC_I2C1_CLK_SLEEP_DISABLE   /* 休眠模式下禁用I2C1时钟 */
#define __I2C1_CLK_SLEEP_ENABLE    __HAL_RCC_I2C1_CLK_SLEEP_ENABLE    /* 休眠模式下使能I2C1时钟 */
#define __I2C1_FORCE_RESET         __HAL_RCC_I2C1_FORCE_RESET         /* 强制复位I2C1 */
#define __I2C1_RELEASE_RESET       __HAL_RCC_I2C1_RELEASE_RESET       /* 释放I2C1复位 */

/* I2C2时钟控制宏定义 */
#define __I2C2_CLK_DISABLE         __HAL_RCC_I2C2_CLK_DISABLE         /* 禁用I2C2时钟 */
#define __I2C2_CLK_ENABLE          __HAL_RCC_I2C2_CLK_ENABLE          /* 使能I2C2时钟 */
#define __I2C2_CLK_SLEEP_DISABLE   __HAL_RCC_I2C2_CLK_SLEEP_DISABLE   /* 休眠模式下禁用I2C2时钟 */
#define __I2C2_CLK_SLEEP_ENABLE    __HAL_RCC_I2C2_CLK_SLEEP_ENABLE    /* 休眠模式下使能I2C2时钟 */
#define __I2C2_FORCE_RESET         __HAL_RCC_I2C2_FORCE_RESET         /* 强制复位I2C2 */
#define __I2C2_RELEASE_RESET       __HAL_RCC_I2C2_RELEASE_RESET       /* 释放I2C2复位 */

/* I2C3时钟控制宏定义 */
#define __I2C3_CLK_DISABLE         __HAL_RCC_I2C3_CLK_DISABLE         /* 禁用I2C3时钟 */
#define __I2C3_CLK_ENABLE          __HAL_RCC_I2C3_CLK_ENABLE          /* 使能I2C3时钟 */
#define __I2C3_CLK_SLEEP_DISABLE   __HAL_RCC_I2C3_CLK_SLEEP_DISABLE   /* 休眠模式下禁用I2C3时钟 */
#define __I2C3_CLK_SLEEP_ENABLE    __HAL_RCC_I2C3_CLK_SLEEP_ENABLE    /* 休眠模式下使能I2C3时钟 */
#define __I2C3_FORCE_RESET         __HAL_RCC_I2C3_FORCE_RESET         /* 强制复位I2C3 */
#define __I2C3_RELEASE_RESET       __HAL_RCC_I2C3_RELEASE_RESET       /* 释放I2C3复位 */

/* LCD时钟控制宏定义 */
#define __LCD_CLK_DISABLE          __HAL_RCC_LCD_CLK_DISABLE          /* 禁用LCD时钟 */
#define __LCD_CLK_ENABLE           __HAL_RCC_LCD_CLK_ENABLE           /* 使能LCD时钟 */
#define __LCD_CLK_SLEEP_DISABLE    __HAL_RCC_LCD_CLK_SLEEP_DISABLE    /* 休眠模式下禁用LCD时钟 */
#define __LCD_CLK_SLEEP_ENABLE     __HAL_RCC_LCD_CLK_SLEEP_ENABLE     /* 休眠模式下使能LCD时钟 */
#define __LCD_FORCE_RESET          __HAL_RCC_LCD_FORCE_RESET          /* 强制复位LCD */
#define __LCD_RELEASE_RESET        __HAL_RCC_LCD_RELEASE_RESET        /* 释放LCD复位 */

/* LPTIM1（低功耗定时器1）时钟控制宏定义 */
#define __LPTIM1_CLK_DISABLE       __HAL_RCC_LPTIM1_CLK_DISABLE       /* 禁用LPTIM1时钟 */
#define __LPTIM1_CLK_ENABLE        __HAL_RCC_LPTIM1_CLK_ENABLE        /* 使能LPTIM1时钟 */
#define __LPTIM1_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE /* 休眠模式下禁用LPTIM1时钟 */
#define __LPTIM1_CLK_SLEEP_ENABLE  __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE  /* 休眠模式下使能LPTIM1时钟 */
#define __LPTIM1_FORCE_RESET       __HAL_RCC_LPTIM1_FORCE_RESET       /* 强制复位LPTIM1 */
#define __LPTIM1_RELEASE_RESET     __HAL_RCC_LPTIM1_RELEASE_RESET     /* 释放LPTIM1复位 */

/* LPTIM2（低功耗定时器2）时钟控制宏定义 */
#define __LPTIM2_CLK_DISABLE       __HAL_RCC_LPTIM2_CLK_DISABLE       /* 禁用LPTIM2时钟 */
#define __LPTIM2_CLK_ENABLE        __HAL_RCC_LPTIM2_CLK_ENABLE        /* 使能LPTIM2时钟 */
#define __LPTIM2_CLK_SLEEP_DISABLE __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE /* 休眠模式下禁用LPTIM2时钟 */
#define __LPTIM2_CLK_SLEEP_ENABLE  __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE  /* 休眠模式下使能LPTIM2时钟 */
#define __LPTIM2_FORCE_RESET       __HAL_RCC_LPTIM2_FORCE_RESET       /* 强制复位LPTIM2 */
#define __LPTIM2_RELEASE_RESET     __HAL_RCC_LPTIM2_RELEASE_RESET     /* 释放LPTIM2复位 */

/* LPUART1（低功耗通用异步收发器1）时钟控制宏定义 */
#define __LPUART1_CLK_DISABLE      __HAL_RCC_LPUART1_CLK_DISABLE      /* 禁用LPUART1时钟 */
#define __LPUART1_CLK_ENABLE       __HAL_RCC_LPUART1_CLK_ENABLE       /* 使能LPUART1时钟 */
#define __LPUART1_CLK_SLEEP_DISABLE __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE /* 休眠模式下禁用LPUART1时钟 */
#define __LPUART1_CLK_SLEEP_ENABLE __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE /* 休眠模式下使能LPUART1时钟 */
#define __LPUART1_FORCE_RESET      __HAL_RCC_LPUART1_FORCE_RESET      /* 强制复位LPUART1 */
#define __LPUART1_RELEASE_RESET    __HAL_RCC_LPUART1_RELEASE_RESET    /* 释放LPUART1复位 */

/* OPAMP（运算放大器）时钟控制宏定义 */
#define __OPAMP_CLK_DISABLE        __HAL_RCC_OPAMP_CLK_DISABLE        /* 禁用OPAMP时钟 */
#define __OPAMP_CLK_ENABLE         __HAL_RCC_OPAMP_CLK_ENABLE         /* 使能OPAMP时钟 */
#define __OPAMP_CLK_SLEEP_DISABLE  __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE  /* 休眠模式下禁用OPAMP时钟 */
#define __OPAMP_CLK_SLEEP_ENABLE   __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE   /* 休眠模式下使能OPAMP时钟 */
#define __OPAMP_FORCE_RESET        __HAL_RCC_OPAMP_FORCE_RESET        /* 强制复位OPAMP */
#define __OPAMP_RELEASE_RESET      __HAL_RCC_OPAMP_RELEASE_RESET      /* 释放OPAMP复位 */

/* OTGFS（USB OTG全速）时钟控制宏定义 */
#define __OTGFS_CLK_DISABLE        __HAL_RCC_OTGFS_CLK_DISABLE        /* 禁用OTGFS时钟 */
#define __OTGFS_CLK_ENABLE         __HAL_RCC_OTGFS_CLK_ENABLE         /* 使能OTGFS时钟 */
#define __OTGFS_CLK_SLEEP_DISABLE  __HAL_RCC_OTGFS_CLK_SLEEP_DISABLE  /* 休眠模式下禁用OTGFS时钟 */
#define __OTGFS_CLK_SLEEP_ENABLE   __HAL_RCC_OTGFS_CLK_SLEEP_ENABLE   /* 休眠模式下使能OTGFS时钟 */
#define __OTGFS_FORCE_RESET        __HAL_RCC_OTGFS_FORCE_RESET        /* 强制复位OTGFS */
#define __OTGFS_RELEASE_RESET      __HAL_RCC_OTGFS_RELEASE_RESET      /* 释放OTGFS复位 */

/* PWR（电源）时钟控制宏定义 */
#define __PWR_CLK_DISABLE          __HAL_RCC_PWR_CLK_DISABLE          /* 禁用PWR时钟 */
#define __PWR_CLK_ENABLE           __HAL_RCC_PWR_CLK_ENABLE           /* 使能PWR时钟 */
#define __PWR_CLK_SLEEP_DISABLE    __HAL_RCC_PWR_CLK_SLEEP_DISABLE    /* 休眠模式下禁用PWR时钟 */
#define __PWR_CLK_SLEEP_ENABLE     __HAL_RCC_PWR_CLK_SLEEP_ENABLE     /* 休眠模式下使能PWR时钟 */
#define __PWR_FORCE_RESET          __HAL_RCC_PWR_FORCE_RESET          /* 强制复位PWR */
#define __PWR_RELEASE_RESET        __HAL_RCC_PWR_RELEASE_RESET        /* 释放PWR复位 */

/* QSPI（四线SPI）时钟控制宏定义 */
#define __QSPI_CLK_DISABLE         __HAL_RCC_QSPI_CLK_DISABLE         /* 禁用QSPI时钟 */
#define __QSPI_CLK_ENABLE          __HAL_RCC_QSPI_CLK_ENABLE          /* 使能QSPI时钟 */
#define __QSPI_CLK_SLEEP_DISABLE   __HAL_RCC_QSPI_CLK_SLEEP_DISABLE   /* 休眠模式下禁用QSPI时钟 */
#define __QSPI_CLK_SLEEP_ENABLE    __HAL_RCC_QSPI_CLK_SLEEP_ENABLE    /* 休眠模式下使能QSPI时钟 */
#define __QSPI_FORCE_RESET         __HAL_RCC_QSPI_FORCE_RESET         /* 强制复位QSPI */
#define __QSPI_RELEASE_RESET       __HAL_RCC_QSPI_RELEASE_RESET       /* 释放QSPI复位 */