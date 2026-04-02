/**
  ******************************************************************************
  * @file    stm32f1xx_hal_flash_ex.h
  * @author  MCD Application Team
  * @brief   Flash HAL扩展模块头文件。
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据许可条款授权，许可条款可在本软件组件根目录下的LICENSE文件中找到。
  * 如果本软件未附带LICENSE文件，则按“原样”提供。
  ******************************************************************************
  */

/* 定义防止递归包含 -------------------------------------*/
#ifndef __STM32F1xx_HAL_FLASH_EX_H
#define __STM32F1xx_HAL_FLASH_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup FLASHEx
  * @{
  */ 

/** @addtogroup FLASHEx_Private_Constants
  * @{
  */

/* Flash容量数据寄存器地址，用于读取芯片的Flash大小 */
#define FLASH_SIZE_DATA_REGISTER     0x1FFFF7E0U
/* OBR寄存器索引 */
#define OBR_REG_INDEX                1U
/* SR标志掩码，包含忙、编程错误、写保护错误、操作结束标志 */
#define SR_FLAG_MASK                 ((uint32_t)(FLASH_SR_BSY | FLASH_SR_PGERR | FLASH_SR_WRPRTERR | FLASH_SR_EOP))

/**
  * @}
  */  

/** @addtogroup FLASHEx_Private_Macros
  * @{
  */

/* 检查擦除类型参数：页擦除或全片擦除 */
#define IS_FLASH_TYPEERASE(VALUE)   (((VALUE) == FLASH_TYPEERASE_PAGES) || ((VALUE) == FLASH_TYPEERASE_MASSERASE))

/* 检查选项字节类型参数：WRP(写保护), RDP(读保护), USER(用户配置), DATA(数据) */
#define IS_OPTIONBYTE(VALUE)        (((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_DATA)))

/* 检查写保护状态参数：使能或禁止 */
#define IS_WRPSTATE(VALUE)          (((VALUE) == OB_WRPSTATE_DISABLE) || ((VALUE) == OB_WRPSTATE_ENABLE))

/* 检查读保护等级参数：等级0或等级1 */
#define IS_OB_RDP_LEVEL(LEVEL)      (((LEVEL) == OB_RDP_LEVEL_0) || ((LEVEL) == OB_RDP_LEVEL_1))

/* 检查选项字节数据地址参数：Data0或Data1 */
#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == OB_DATA_ADDRESS_DATA0) || ((ADDRESS) == OB_DATA_ADDRESS_DATA1)) 

/* 检查独立看门狗源参数：软件模式或硬件模式 */
#define IS_OB_IWDG_SOURCE(SOURCE)   (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

/* 检查停机模式复位源参数：不复位或复位 */
#define IS_OB_STOP_SOURCE(SOURCE)   (((SOURCE) == OB_STOP_NO_RST) || ((SOURCE) == OB_STOP_RST))

/* 检查待机模式复位源参数：不复位或复位 */
#define IS_OB_STDBY_SOURCE(SOURCE)  (((SOURCE) == OB_STDBY_NO_RST) || ((SOURCE) == OB_STDBY_RST))

#if defined(FLASH_BANK2_END)
/* 检查BOOT1配置参数：复位或置位 */
#define IS_OB_BOOT1(BOOT1)         (((BOOT1) == OB_BOOT1_RESET) || ((BOOT1) == OB_BOOT1_SET))
#endif /* FLASH_BANK2_END */

/* 低密度设备 */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
/* 检查页数量是否有效，根据Flash容量寄存器判断地址范围 */
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08003FFFU))
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* 中密度设备 */
#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
/* 检查页数量是否有效，根据Flash容量寄存器判断地址范围 */
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08003FFFU))))
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/

/* 高密度设备 */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
/* 检查页数量是否有效，根据Flash容量寄存器判断地址范围 */
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0807FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0805FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU)))
#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* XL密度设备 */
#if defined(FLASH_BANK2_END)
/* 检查页数量是否有效，根据Flash容量寄存器判断地址范围 */
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080FFFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080BFFFFU))
#endif /* FLASH_BANK2_END */

/* 互联型设备 */
#if (defined(STM32F105xC) || defined(STM32F107xC))
/* 检查页数量是否有效，根据Flash容量寄存器判断地址范围 */
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) ==  0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU)))
#endif /* STM32F105xC || STM32F107xC */

/* 检查写保护页参数是否有效 */
#define IS_OB_WRP(PAGE) (((PAGE) != 0x0000000U))

#if defined(FLASH_BANK2_END)
/* 检查Flash Bank参数：Bank1, Bank2 或两者 */
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1)  || \
                             ((BANK) == FLASH_BANK_2)  || \
                             ((BANK) == FLASH_BANK_BOTH))
#else
/* 检查Flash Bank参数：仅Bank1 */
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1))
#endif /* FLASH_BANK2_END */

/* 低密度设备 */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
/* 检查Flash编程地址是否有效 */
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS)  (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                            ((ADDRESS) <= FLASH_BANK1_END) :  ((ADDRESS) <= 0x08003FFFU)))

#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* 中密度设备 */
#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
/* 检查Flash编程地址是否有效 */
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? \
                                           ((ADDRESS) <= 0x0800FFFF) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                           ((ADDRESS) <= 0x08007FFF) :  ((ADDRESS) <= 0x08003FFFU)))))

#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/

/* 高密度设备 */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
/* 检查Flash编程地址是否有效 */
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? \
                                           ((ADDRESS) <= 0x0805FFFFU) :  ((ADDRESS) <= 0x0803FFFFU))))

#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* XL密度设备 */
#if defined(FLASH_BANK2_END)
/* 检查Flash编程地址是否有效 */
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? \
                                           ((ADDRESS) <= FLASH_BANK2_END) :  ((ADDRESS) <= 0x080BFFFFU)))

#endif /* FLASH_BANK2_END */

/* 互联型设备 */
#if (defined(STM32F105xC) || defined(STM32F107xC))
/* 检查Flash编程地址是否有效 */
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= 0x0801FFFFU) :  ((ADDRESS) <= 0x0800FFFFU))))

#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */  

/* 导出类型 ------------------------------------------------------------*/ 
/** @defgroup FLASHEx_Exported_Types FLASHEx导出类型
  * @{
  */  

/**
  * @brief  Flash擦除结构体定义
  */
typedef struct
{
  uint32_t TypeErase;   /*!< 擦除类型：全片擦除或页擦除。
                             该参数可以是 @ref FLASHEx_Type_Erase 中的值 */
  
  uint32_t Banks;       /*!< 选择要擦除的Bank，仅在全片擦除时有效。
                             该参数必须是 @ref FLASHEx_Banks 中的值 */    
  
  uint32_t PageAddress; /*!< 页地址：当非全片擦除时，指定要擦除的起始Flash页地址。
                             该参数范围：Min_Data = 0x08000000 到 Max_Data = FLASH_BANKx_END 
                             (x = 1 或 2，取决于具体设备)*/
  
  uint32_t NbPages;     /*!< 页数量：要擦除的页数。
                             该参数范围：Min_Data = 1 到 Max_Data = (最大页数 - 起始页号)*/
                                                          
} FLASH_EraseInitTypeDef;

/**
  * @brief  Flash选项字节编程结构体定义
  */
typedef struct
{
  uint32_t OptionType;  /*!< 选项字节类型：要配置的选项字节。
                             该参数可以是 @ref FLASHEx_OB_Type 中的值 */

  uint32_t WRPState;    /*!< 写保护状态：激活或关闭写保护。
                             该参数可以是 @ref FLASHEx_OB_WRP_State 中的值 */

  uint32_t WRPPage;     /*!< 写保护页：指定要写保护的页。
                             该参数可以是 @ref FLASHEx_OB_Write_Protection 中的值 */

  uint32_t Banks;        /*!< 选择Bank用于激活/关闭所有扇区的写保护。
                              该参数必须是 @ref FLASHEx_Banks 中的值 */ 
    
  uint8_t RDPLevel;     /*!< 读保护等级：设置读保护等级。
                             该参数可以是 @ref FLASHEx_OB_Read_Protection 中的值 */

#if defined(FLASH_BANK2_END)
  uint8_t USERConfig;   /*!< 用户配置：编程Flash用户选项字节： 
                             IWDG(独立看门狗) / STOP(停机模式) / STDBY(待机模式) / BOOT1(启动模式)
                             该参数可以是以下值的组合：
                             @ref FLASHEx_OB_IWatchdog, @ref FLASHEx_OB_nRST_STOP, 
                             @ref FLASHEx_OB_nRST_STDBY, @ref FLASHEx_OB_BOOT1 */
#else
  uint8_t USERConfig;   /*!< 用户配置：编程Flash用户选项字节： 
                             IWDG(独立看门狗) / STOP(停机模式) / STDBY(待机模式)
                             该参数可以是以下值的组合：
                             @ref FLASHEx_OB_IWatchdog, @ref FLASHEx_OB_nRST_STOP, 
                             @ref FLASHEx_OB_nRST_STDBY */
#endif /* FLASH_BANK2_END */

  uint32_t DATAAddress; /*!< 数据地址：要编程的选项字节数据地址。
                             该参数可以是 @ref FLASHEx_OB_Data_Address 中的值 */
  
  uint8_t DATAData;     /*!< 数据内容：要存储在选项字节数据中的值。
                             该参数范围：Min_Data = 0x00 到 Max_Data = 0xFF */
} FLASH_OBProgramInitTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Constants FLASHEx导出常量
  * @{
  */  

/** @defgroup FLASHEx_Constants Flash常量
  * @{
  */ 

/** @defgroup FLASHEx_Page_Size 页大小
  * @{
  */ 
/* 低密度和中密度设备：页大小为1KB (0x400) */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define FLASH_PAGE_SIZE          0x400U
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */
       /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */

/* 高密度、XL密度和互联型设备：页大小为2KB (0x800) */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC))
#define FLASH_PAGE_SIZE          0x800U
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       /* STM32F101xG || STM32F103xG */ 
       /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup FLASHEx_Type_Erase 擦除类型
  * @{
  */ 
#define FLASH_TYPEERASE_PAGES     0x00U  /* 仅页擦除 */
#define FLASH_TYPEERASE_MASSERASE 0x02U  /* Flash全片擦除激活 */

/**
  * @}
  */

/** @defgroup FLASHEx_Banks Flash Bank
  * @{
  */
#if defined(FLASH_BANK2_END)
#define FLASH_BANK_1     1U /* Bank 1 */
#define FLASH_BANK_2     2U /* Bank 2 */
#define FLASH_BANK_BOTH  ((uint32_t)FLASH_BANK_1 | FLASH_BANK_2) /* Bank1 和 Bank2 */

#else
#define FLASH_BANK_1     1U /* Bank 1 */
#endif
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FLASHEx_OptionByte_Constants 选项字节常量
  * @{
  */ 

/** @defgroup FLASHEx_OB_Type 选项字节类型
  * @{
  */
#define OPTIONBYTE_WRP            0x01U  /* WRP(写保护)选项字节配置 */
#define OPTIONBYTE_RDP            0x02U  /* RDP(读保护)选项字节配置 */
#define OPTIONBYTE_USER           0x04U  /* USER(用户配置)选项字节配置 */
#define OPTIONBYTE_DATA           0x08U  /* DATA(数据)选项字节配置 */

/**
  * @}
  */

/** @defgroup FLASHEx_OB_WRP_State 选项字节写保护状态
  * @{
  */ 
#define OB_WRPSTATE_DISABLE       0x00U  /* 禁止所需页的写保护 */
#define OB_WRPSTATE_ENABLE        0x01U  /* 使能所需页的写保护 */

/**
  * @}
  */

/** @defgroup FLASHEx_OB_Write_Protection 选项字节写保护
  * @{
  */
/* STM32 低密度和中密度设备 */
#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) \
  || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) \
  || defined(STM32F103xB)
#define OB_WRP_PAGES0TO3               0x00000001U /* 写保护页 0 到 3 */
#define OB_WRP_PAGES4TO7               0x00000002U /* 写保护页 4 到 7 */
#define OB_WRP_PAGES8TO11              0x00000004U /* 写保护页 8 到 11 */
#define OB_WRP_PAGES12TO15             0x00000008U /* 写保护页 12 到 15 */
#define OB_WRP_PAGES16TO19             0x00000010U /* 写保护页 16 到 19 */
#define OB_WRP_PAGES20TO23             0x00000020U /* 写保护页 20 到 23 */
#define OB_WRP_PAGES24TO27             0x00000040U /* 写保护页 24 到 27 */
#define OB_WRP_PAGES28TO31             0x00000080U /* 写保护页 28 到 31 */
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */
       /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       
/* STM32 中密度设备 */
#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define OB_WRP_PAGES32TO35             0x00000100U   /* 写保护页 32 到 35 */
#define OB_WRP_PAGES36TO39             0x00000200U   /* 写保护页 36 到 39 */
#define OB_WRP_PAGES40TO43             0x00000400U   /* 写保护页 40 到 43 */
#define OB_WRP_PAGES44TO47             0x00000800U   /* 写保护页 44 到 47 */
#define OB_WRP_PAGES48TO51             0x00001000U   /* 写保护页 48 到 51 */
#define OB_WRP_PAGES52TO55             0x00002000U   /* 写保护页 52 到 55 */
#define OB_WRP_PAGES56TO59             0x00004000U   /* 写保护页 56 到 59 */
#define OB_WRP_PAGES60TO63             0x00008000U   /* 写保护页 60 到 63 */
#define OB_WRP_PAGES64TO67             0x00010000U   /* 写保护页 64 到 67 */
#define OB_WRP_PAGES68TO71             0x00020000U   /* 写保护页 68 到 71 */
#define OB_WRP_PAGES72TO75             0x00040000U   /* 写保护页 72 到 75 */
#define OB_WRP_PAGES76TO79             0x00080000U   /* 写保护页 76 到 79 */
#define OB_WRP_PAGES80TO83             0x00100000U   /* 写保护页 80 到 83 */
#define OB_WRP_PAGES84TO87             0x00200000U   /* 写保护页 84 到 87 */
#define OB_WRP_PAGES88TO91             0x00400000U   /* 写保护页 88 到 91 */
#define OB_WRP_PAGES92TO95             0x00800000U   /* 写保护页 92 到 95 */
#define OB_WRP_PAGES96TO99             0x01000000U   /* 写保护页 96 到 99 */
#define OB_WRP_PAGES100TO103           0x02000000U   /* 写保护页 100 到 103 */
#define OB_WRP_PAGES104TO107           0x04000000U   /* 写保护页 104 到 107 */
#define OB_WRP_PAGES108TO111           0x08000000U   /* 写保护页 108 到 111 */
#define OB_WRP_PAGES112TO115           0x10000000U   /* 写保护页 112 到 115 */
#define OB_WRP_PAGES116TO119           0x20000000U   /* 写保护页 115 到 119 */
#define OB_WRP_PAGES120TO123           0x40000000U   /* 写保护页 120 到 123 */
#define OB_WRP_PAGES124TO127           0x80000000U    /* 写保护页 124 到 127 */
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */

/* STM32 大容量、超大容量和互联型设备 */
#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) \
  || defined(STM32F101xG) || defined(STM32F103xG) \
  || defined(STM32F105xC) || defined(STM32F107xC)

/* 以下宏定义用于选项字节写保护，每一位对应保护2页 */
#define OB_WRP_PAGES0TO1               0x00000001U  /*!< 写保护页 0 和 1 */
#define OB_WRP_PAGES2TO3               0x00000002U  /*!< 写保护页 2 和 3 */
#define OB_WRP_PAGES4TO5               0x00000004U  /*!< 写保护页 4 和 5 */
#define OB_WRP_PAGES6TO7               0x00000008U  /*!< 写保护页 6 和 7 */
#define OB_WRP_PAGES8TO9               0x00000010U  /*!< 写保护页 8 和 9 */
#define OB_WRP_PAGES10TO11             0x00000020U  /*!< 写保护页 10 和 11 */
#define OB_WRP_PAGES12TO13             0x00000040U  /*!< 写保护页 12 和 13 */
#define OB_WRP_PAGES14TO15             0x00000080U  /*!< 写保护页 14 和 15 */
#define OB_WRP_PAGES16TO17             0x00000100U  /*!< 写保护页 16 和 17 */
#define OB_WRP_PAGES18TO19             0x00000200U  /*!< 写保护页 18 和 19 */
#define OB_WRP_PAGES20TO21             0x00000400U  /*!< 写保护页 20 和 21 */
#define OB_WRP_PAGES22TO23             0x00000800U  /*!< 写保护页 22 和 23 */
#define OB_WRP_PAGES24TO25             0x00001000U  /*!< 写保护页 24 和 25 */
#define OB_WRP_PAGES26TO27             0x00002000U  /*!< 写保护页 26 和 27 */
#define OB_WRP_PAGES28TO29             0x00004000U  /*!< 写保护页 28 和 29 */
#define OB_WRP_PAGES30TO31             0x00008000U  /*!< 写保护页 30 和 31 */
#define OB_WRP_PAGES32TO33             0x00010000U  /*!< 写保护页 32 和 33 */
#define OB_WRP_PAGES34TO35             0x00020000U  /*!< 写保护页 34 和 35 */
#define OB_WRP_PAGES36TO37             0x00040000U  /*!< 写保护页 36 和 37 */
#define OB_WRP_PAGES38TO39             0x00080000U  /*!< 写保护页 38 和 39 */
#define OB_WRP_PAGES40TO41             0x00100000U  /*!< 写保护页 40 和 41 */
#define OB_WRP_PAGES42TO43             0x00200000U  /*!< 写保护页 42 和 43 */
#define OB_WRP_PAGES44TO45             0x00400000U  /*!< 写保护页 44 和 45 */
#define OB_WRP_PAGES46TO47             0x00800000U  /*!< 写保护页 46 和 47 */
#define OB_WRP_PAGES48TO49             0x01000000U  /*!< 写保护页 48 和 49 */
#define OB_WRP_PAGES50TO51             0x02000000U  /*!< 写保护页 50 和 51 */
#define OB_WRP_PAGES52TO53             0x04000000U  /*!< 写保护页 52 和 53 */
#define OB_WRP_PAGES54TO55             0x08000000U  /*!< 写保护页 54 和 55 */
#define OB_WRP_PAGES56TO57             0x10000000U  /*!< 写保护页 56 和 57 */
#define OB_WRP_PAGES58TO59             0x20000000U  /*!< 写保护页 58 和 59 */
#define OB_WRP_PAGES60TO61             0x40000000U  /*!< 写保护页 60 和 61 */
#define OB_WRP_PAGES62TO127            0x80000000U   /*!< 写保护页 62 到 127 */
#define OB_WRP_PAGES62TO255            0x80000000U   /*!< 写保护页 62 到 255 */
#define OB_WRP_PAGES62TO511            0x80000000U   /*!< 写保护页 62 到 511 */
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       /* STM32F101xG || STM32F103xG */ 
       /* STM32F105xC || STM32F107xC */

/* 使能对所有页的写保护 */
#define OB_WRP_ALLPAGES                0xFFFFFFFFU  /*!< 写保护所有页 */
 
/* 小容量设备 */
#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6)
/* 页 0 到 31 的掩码，用于写保护配置 */
#define OB_WRP_PAGES0TO31MASK          0x000000FFU 
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* 中容量设备 */
#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
/* 页 0 到 31 的掩码 */
#define OB_WRP_PAGES0TO31MASK          0x000000FFU
/* 页 32 到 63 的掩码 */
#define OB_WRP_PAGES32TO63MASK         0x0000FF00U
/* 页 64 到 95 的掩码 */
#define OB_WRP_PAGES64TO95MASK         0x00FF0000U
/* 页 96 到 127 的掩码 */
#define OB_WRP_PAGES96TO127MASK        0xFF000000U
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/
       
/* 大容量设备 */
#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE)  
/* 页 0 到 15 的掩码 */
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
/* 页 16 到 31 的掩码 */
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
/* 页 32 到 47 的掩码 */
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
/* 页 48 到 255 的掩码 */
#define OB_WRP_PAGES48TO255MASK        0xFF000000U
#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* 超大容量设备 */
#if  defined(STM32F101xG) || defined(STM32F103xG) 
/* 页 0 到 15 的掩码 */
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
/* 页 16 到 31 的掩码 */
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
/* 页 32 到 47 的掩码 */
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
/* 页 48 到 511 的掩码 */
#define OB_WRP_PAGES48TO511MASK        0xFF000000U
#endif /* STM32F101xG || STM32F103xG */
      
/* 互联型设备 */
#if defined(STM32F105xC) || defined(STM32F107xC)
/* 页 0 到 15 的掩码 */
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
/* 页 16 到 31 的掩码 */
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
/* 页 32 到 47 的掩码 */
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
/* 页 48 到 127 的掩码 */
#define OB_WRP_PAGES48TO127MASK        0xFF000000U
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup FLASHEx_OB_Read_Protection Option Byte Read Protection
  * @brief 选项字节读保护配置
  * @{
  */
/* 读保护级别 0：无保护，此时可以读写Flash */
#define OB_RDP_LEVEL_0            ((uint8_t)0xA5)
/* 读保护级别 1：使能读保护，此时无法通过调试接口读取Flash内容 */
#define OB_RDP_LEVEL_1            ((uint8_t)0x00)
/**
  * @}
  */
  
/** @defgroup FLASHEx_OB_IWatchdog Option Byte IWatchdog
  * @brief 选项字节独立看门狗配置
  * @{
  */ 
/* 软件看门狗：由软件初始化启动看门狗 */
#define OB_IWDG_SW                ((uint16_t)0x0001)  /*!< 选择软件独立看门狗 */
/* 硬件看门狗：由硬件自动启动看门狗 */
#define OB_IWDG_HW                ((uint16_t)0x0000)  /*!< 选择硬件独立看门狗 */
/**
  * @}
  */

/** @defgroup FLASHEx_OB_nRST_STOP Option Byte nRST STOP
  * @brief 选项字节停机模式复位配置
  * @{
  */ 
/* 进入停机模式时不产生复位 */
#define OB_STOP_NO_RST            ((uint16_t)0x0002) /*!< 进入停机模式时不产生复位 */
/* 进入停机模式时产生复位 */
#define OB_STOP_RST               ((uint16_t)0x0000) /*!< 进入停机模式时产生复位 */
/**
  * @}
  */ 

/** @defgroup FLASHEx_OB_nRST_STDBY Option Byte nRST STDBY
  * @brief 选项字节待机模式复位配置
  * @{
  */ 
/* 进入待机模式时不产生复位 */
#define OB_STDBY_NO_RST           ((uint16_t)0x0004) /*!< 进入待机模式时不产生复位 */
/* 进入待机模式时产生复位 */
#define OB_STDBY_RST              ((uint16_t)0x0000) /*!< 进入待机模式时产生复位 */
/**
  * @}
  */

#if defined(FLASH_BANK2_END)
/** @defgroup FLASHEx_OB_BOOT1 Option Byte BOOT1
  * @brief 选项字节 BOOT1 配置，用于设置启动模式
  * @{
  */
/* BOOT1 引脚复位值（低电平），从主 Flash 启动 (0x08000000) */
#define OB_BOOT1_RESET            ((uint16_t)0x0000) /*!< BOOT1 复位 */
/* BOOT1 引脚置位值（高电平），从系统存储器启动 */
#define OB_BOOT1_SET              ((uint16_t)0x0008) /*!< BOOT1 置位 */
/**
  * @}
  */
#endif /* FLASH_BANK2_END */

/** @defgroup FLASHEx_OB_Data_Address  Option Byte Data Address
  * @brief 选项字节数据地址定义，用于存储用户自定义数据
  * @{
  */
/* 数据0的存储地址 */
#define OB_DATA_ADDRESS_DATA0     0x1FFFF804U
/* 数据1的存储地址 */
#define OB_DATA_ADDRESS_DATA1     0x1FFFF806U
/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FLASHEx_Constants
  * @{
  */ 

/** @defgroup FLASH_Flag_definition Flag definition
  * @brief FLASH 标志位定义，用于查询 FLASH 状态
  * @{
  */
#if defined(FLASH_BANK2_END)
/* Bank1 的状态标志位定义 */
 #define FLASH_FLAG_BSY             FLASH_FLAG_BSY_BANK1       /*!< FLASH Bank1 忙标志位                   */ 
 #define FLASH_FLAG_PGERR           FLASH_FLAG_PGERR_BANK1     /*!< FLASH Bank1 编程错误标志位      */
 #define FLASH_FLAG_WRPERR          FLASH_FLAG_WRPERR_BANK1    /*!< FLASH Bank1 写保护错误标志位  */
 #define FLASH_FLAG_EOP             FLASH_FLAG_EOP_BANK1       /*!< FLASH Bank1 操作结束标志位       */

 #define FLASH_FLAG_BSY_BANK1       FLASH_SR_BSY               /*!< FLASH Bank1 忙标志位                   */ 
 #define FLASH_FLAG_PGERR_BANK1     FLASH_SR_PGERR             /*!< FLASH Bank1 编程错误标志位      */
 #define FLASH_FLAG_WRPERR_BANK1    FLASH_SR_WRPRTERR          /*!< FLASH Bank1 写保护错误标志位  */
 #define FLASH_FLAG_EOP_BANK1       FLASH_SR_EOP               /*!< FLASH Bank1 操作结束标志位       */
       
/* Bank2 的状态标志位定义，通过移位操作映射到高16位 */
 #define FLASH_FLAG_BSY_BANK2       (FLASH_SR2_BSY << 16U)      /*!< FLASH Bank2 忙标志位                   */ 
 #define FLASH_FLAG_PGERR_BANK2     (FLASH_SR2_PGERR << 16U)    /*!< FLASH Bank2 编程错误标志位      */
 #define FLASH_FLAG_WRPERR_BANK2    (FLASH_SR2_WRPRTERR << 16U) /*!< FLASH Bank2 写保护错误标志位  */
 #define FLASH_FLAG_EOP_BANK2       (FLASH_SR2_EOP << 16U)      /*!< FLASH Bank2 操作结束标志位       */

#else  

/* 单 Bank 设备的状态标志位定义 */
 #define FLASH_FLAG_BSY             FLASH_SR_BSY              /*!< FLASH 忙标志位                          */ 
 #define FLASH_FLAG_PGERR           FLASH_SR_PGERR            /*!< FLASH 编程错误标志位             */
 #define FLASH_FLAG_WRPERR          FLASH_SR_WRPRTERR         /*!< FLASH 写保护错误标志位         */
 #define FLASH_FLAG_EOP             FLASH_SR_EOP              /*!< FLASH 操作结束标志位              */

#endif
/* 选项字节错误标志位 */
 #define FLASH_FLAG_OPTVERR         ((OBR_REG_INDEX << 8U | FLASH_OBR_OPTERR)) /*!< 选项字节错误        */
/**
  * @}
  */
  
/** @defgroup FLASH_Interrupt_definition Interrupt definition
  * @brief FLASH 中断定义
  * @{
  */
#if defined(FLASH_BANK2_END)
/* Bank1 的中断源定义 */
 #define FLASH_IT_EOP               FLASH_IT_EOP_BANK1        /*!< Bank1 FLASH 操作结束中断源 */
 #define FLASH_IT_ERR               FLASH_IT_ERR_BANK1        /*!< Bank1 错误中断源                  */

 #define FLASH_IT_EOP_BANK1         FLASH_CR_EOPIE            /*!< Bank1 FLASH 操作结束中断使能位 */
 #define FLASH_IT_ERR_BANK1         FLASH_CR_ERRIE            /*!< Bank1 错误中断使能位                  */

/* Bank2 的中断源定义，通过移位操作映射到高16位 */
 #define FLASH_IT_EOP_BANK2         (FLASH_CR2_EOPIE << 16U)   /*!< Bank2 FLASH 操作结束中断源 */
 #define FLASH_IT_ERR_BANK2         (FLASH_CR2_ERRIE << 16U)   /*!< Bank2 错误中断源                  */

#else

/* 单 Bank 设备的中断源定义 */
 #define FLASH_IT_EOP               FLASH_CR_EOPIE          /*!< FLASH 操作结束中断源 */
 #define FLASH_IT_ERR               FLASH_CR_ERRIE          /*!< 错误中断源                  */

#endif
/**
  * @}
  */  

/**
  * @}
  */
  

/**
  * @}
  */

/* 导出宏 ------------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Macros FLASHEx Exported Macros
  * @{
  */

/** @defgroup FLASH_Interrupt Interrupt
 *  @brief 用于处理 FLASH 中断的宏
 * @{
 */ 

#if defined(FLASH_BANK2_END)
/**
  * @brief  使能指定的 FLASH 中断。
  * @param  __INTERRUPT__  FLASH 中断源 
  *     该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP_BANK1 Bank1 FLASH 操作结束中断
  *     @arg @ref FLASH_IT_ERR_BANK1 Bank1 错误中断
  *     @arg @ref FLASH_IT_EOP_BANK2 Bank2 FLASH 操作结束中断
  *     @arg @ref FLASH_IT_ERR_BANK2 Bank2 错误中断
  * @retval 无
  */ 
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  do { \
                          /* 使能 Bank1 中断 */ \
                          SET_BIT(FLASH->CR, ((__INTERRUPT__) & 0x0000FFFFU)); \
                          /* 使能 Bank2 中断 */ \
                          SET_BIT(FLASH->CR2, ((__INTERRUPT__) >> 16U)); \
                    } while(0U)

/**
  * @brief  禁止指定的 FLASH 中断。
  * @param  __INTERRUPT__  FLASH 中断源 
  *     该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP_BANK1 Bank1 FLASH 操作结束中断
  *     @arg @ref FLASH_IT_ERR_BANK1 Bank1 错误中断
  *     @arg @ref FLASH_IT_EOP_BANK2 Bank2 FLASH 操作结束中断
  *     @arg @ref FLASH_IT_ERR_BANK2 Bank2 错误中断
  * @retval 无
  */ 
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)  do { \
                          /* 禁止 Bank1 中断 */ \
                          CLEAR_BIT(FLASH->CR, ((__INTERRUPT__) & 0x0000FFFFU)); \
                          /* 禁止 Bank2 中断 */ \
                          CLEAR_BIT(FLASH->CR2, ((__INTERRUPT__) >> 16U)); \
                    } while(0U)

/**
  * @brief  获取指定的 FLASH 标志位状态。 
  * @param  __FLAG__ 指定要检查的 FLASH 标志位。
  *          该参数可以是以下值之一:
  *            @arg @ref FLASH_FLAG_EOP_BANK1    Bank1 FLASH 操作结束标志位
  *            @arg @ref FLASH_FLAG_WRPERR_BANK1 Bank1 FLASH 写保护错误标志位
  *            @arg @ref FLASH_FLAG_PGERR_BANK1  Bank1 FLASH 编程错误标志位
  *            @arg @ref FLASH_FLAG_BSY_BANK1    Bank1 FLASH 忙标志位
  *            @arg @ref FLASH_FLAG_EOP_BANK2    Bank2 FLASH 操作结束标志位
  *            @arg @ref FLASH_FLAG_WRPERR_BANK2 Bank2 FLASH 写保护错误标志位
  *            @arg @ref FLASH_FLAG_PGERR_BANK2  Bank2 FLASH 编程错误标志位
  *            @arg @ref FLASH_FLAG_BSY_BANK2    Bank2 FLASH 忙标志位
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval __FLAG__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__) (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                        ((((__FLAG__) & SR_FLAG_MASK) != RESET)? \
                                            (FLASH->SR & ((__FLAG__) & SR_FLAG_MASK)) : \
                                            (FLASH->SR2 & ((__FLAG__) >> 16U))))

/**
  * @brief  清除指定的 FLASH 标志位。
  * @param  __FLAG__ 指定要清除的 FLASH 标志位。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref FLASH_FLAG_EOP_BANK1    Bank1 FLASH 操作结束标志位
  *            @arg @ref FLASH_FLAG_WRPERR_BANK1 Bank1 FLASH 写保护错误标志位
  *            @arg @ref FLASH_FLAG_PGERR_BANK1  Bank1 FLASH 编程错误标志位
  *            @arg @ref FLASH_FLAG_BSY_BANK1    Bank1 FLASH 忙标志位
  *            @arg @ref FLASH_FLAG_EOP_BANK2    Bank2 FLASH 操作结束标志位
  *            @arg @ref FLASH_FLAG_WRPERR_BANK2 Bank2 FLASH 写保护错误标志位
  *            @arg @ref FLASH_FLAG_PGERR_BANK2  Bank2 FLASH 编程错误标志位
  *            @arg @ref FLASH_FLAG_BSY_BANK2    Bank2 FLASH 忙标志位
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval 无
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)  do { \
                          /* 清除 FLASH_FLAG_OPTVERR 标志位 */ \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                          /* 清除 Bank1 标志位 */ \
                          if (((__FLAG__) & SR_FLAG_MASK) != RESET) \
                          { \
                            FLASH->SR  = ((__FLAG__) & SR_FLAG_MASK); \
                          } \
                          /* 清除 Bank2 标志位 */ \
                          if (((__FLAG__) >> 16U) != RESET) \
                          { \
                            FLASH->SR2 = ((__FLAG__) >> 16U); \
                          } \
                          } \
                    } while(0U)
#else
/**
  * @brief  使能指定的 FLASH 中断。
  * @param  __INTERRUPT__  FLASH 中断源 
  *         该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP FLASH 操作结束中断
  *     @arg @ref FLASH_IT_ERR 错误中断    
  * @retval 无
  */ 
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  (FLASH->CR |= (__INTERRUPT__))

/**
  * @brief  禁止指定的 FLASH 中断。
  * @param  __INTERRUPT__  FLASH 中断源 
  *         该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP FLASH 操作结束中断
  *     @arg @ref FLASH_IT_ERR 错误中断    
  * @retval 无
  */ 
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)   (FLASH->CR &= ~(__INTERRUPT__))

/**
  * @brief  获取指定的 FLASH 标志位状态。 
  * @param  __FLAG__ 指定要检查的 FLASH 标志位。
  *          该参数可以是以下值之一:
  *            @arg @ref FLASH_FLAG_EOP    FLASH 操作结束标志位 
  *            @arg @ref FLASH_FLAG_WRPERR FLASH 写保护错误标志位 
  *            @arg @ref FLASH_FLAG_PGERR  FLASH 编程错误标志位
  *            @arg @ref FLASH_FLAG_BSY    FLASH 忙标志位
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval __FLAG__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__)  (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                            (FLASH->SR & (__FLAG__)))
/**
  * @brief  清除指定的 FLASH 标志位。
  * @param  __FLAG__ 指定要清除的 FLASH 标志位。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref FLASH_FLAG_EOP    FLASH 操作结束标志位 
  *            @arg @ref FLASH_FLAG_WRPERR FLASH 写保护错误标志位 
  *            @arg @ref FLASH_FLAG_PGERR  FLASH 编程错误标志位 
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval 无
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)   do { \
                          /* 清除 FLASH_FLAG_OPTVERR 标志位 */ \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                            /* 清除 Bank1 标志位 */ \
                            FLASH->SR  = (__FLAG__); \
                          } \
                    } while(0U)

#endif

/**
  * @}
  */

/**
  * @}
  */

/* 导出函数 --------------------------------------------------------*/
/** @addtogroup FLASHEx_Exported_Functions
  * @{
  */

/** @addtogroup FLASHEx_Exported_Functions_Group1
  * @{
  */
/* IO 操作函数 *****************************************************/
/**
  * @brief  执行 FLASH 擦除操作（阻塞模式）。
  * @param  pEraseInit 指向 FLASH_EraseInitTypeDef 结构体的指针，包含擦除配置信息。
  * @param  PageError 指向 uint32_t 变量的指针，返回发生错误的页地址（如果有）。
  * @retval HAL 状态值
  */
HAL_StatusTypeDef  HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);

/**
  * @brief  执行 FLASH 擦除操作（非阻塞模式，中断方式）。
  * @param  pEraseInit 指向 FLASH_EraseInitTypeDef 结构体的指针，包含擦除配置信息。
  * @retval HAL 状态值
  */
HAL_StatusTypeDef  HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);

/**
  * @}
  */

/** @addtogroup FLASHEx_Exported_Functions_Group2
  * @{
  */
/* 外设控制函数 ***********************************************/
/**
  * @brief  擦除选项字节。
  * @retval HAL 状态值
  */
HAL_StatusTypeDef  HAL_FLASHEx_OBErase(void);

/**
  * @brief  编程选项字节。
  * @param  pOBInit 指向 FLASH_OBProgramInitTypeDef 结构体的指针，包含选项字节配置信息。
  * @retval HAL 状态值
  */
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);

/**
  * @brief  获取当前选项字节配置。
  * @param  pOBInit 指向 FLASH_OBProgramInitTypeDef 结构体的指针，用于返回配置信息。
  * @retval 无
  */
void               HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);

/**
  * @brief  获取选项字节中的用户数据。
  * @param  DATAAdress 用户数据地址（OB_DATA_ADDRESS_DATA0 或 OB_DATA_ADDRESS_DATA1）。
  * @retval 用户数据值
  */
uint32_t           HAL_FLASHEx_OBGetUserData(uint32_t DATAAdress);
/**
  * @}
  */

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

#endif /* __STM32F1xx_HAL_FLASH_EX_H */
