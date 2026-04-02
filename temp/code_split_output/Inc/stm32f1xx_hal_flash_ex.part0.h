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

