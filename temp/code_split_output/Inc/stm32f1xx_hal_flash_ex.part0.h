/**
  ******************************************************************************
  * @file    stm32f1xx_hal_flash_ex.h
  * @author  MCD Application Team
  * @brief   Header file of Flash HAL Extended module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file in
  * the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

// Flash大小数据寄存器地址，用于读取芯片实际的Flash容量
#define FLASH_SIZE_DATA_REGISTER     0x1FFFF7E0U
// OBR寄存器索引
#define OBR_REG_INDEX                1U
// SR标志位掩码，包含忙标志、编程错误、写保护错误、操作结束标志
#define SR_FLAG_MASK                 ((uint32_t)(FLASH_SR_BSY | FLASH_SR_PGERR | FLASH_SR_WRPRTERR | FLASH_SR_EOP))

/**
  * @}
  */  

/** @addtogroup FLASHEx_Private_Macros
  * @{
  */

// 判断是否为有效的擦除类型：页擦除或全片擦除
#define IS_FLASH_TYPEERASE(VALUE)   (((VALUE) == FLASH_TYPEERASE_PAGES) || ((VALUE) == FLASH_TYPEERASE_MASSERASE))

// 判断是否为有效的选项字节类型：WRP(写保护), RDP(读保护), USER(用户配置), DATA(数据)
#define IS_OPTIONBYTE(VALUE)        (((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_DATA)))

// 判断是否为有效的写保护状态：禁用或使能
#define IS_WRPSTATE(VALUE)          (((VALUE) == OB_WRPSTATE_DISABLE) || ((VALUE) == OB_WRPSTATE_ENABLE))

// 判断是否为有效的读保护等级：等级0或等级1
#define IS_OB_RDP_LEVEL(LEVEL)      (((LEVEL) == OB_RDP_LEVEL_0) || ((LEVEL) == OB_RDP_LEVEL_1))

// 判断是否为有效的选项字节数据地址：Data0或Data1
#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == OB_DATA_ADDRESS_DATA0) || ((ADDRESS) == OB_DATA_ADDRESS_DATA1)) 

// 判断是否为有效的独立看门狗源：软件IWDG或硬件IWDG
#define IS_OB_IWDG_SOURCE(SOURCE)   (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

// 判断是否为有效的停止模式复位源：停止模式不复位或停止模式复位
#define IS_OB_STOP_SOURCE(SOURCE)   (((SOURCE) == OB_STOP_NO_RST) || ((SOURCE) == OB_STOP_RST))

// 判断是否为有效的待机模式复位源：待机模式不复位或待机模式复位
#define IS_OB_STDBY_SOURCE(SOURCE)  (((SOURCE) == OB_STDBY_NO_RST) || ((SOURCE) == OB_STDBY_RST))

#if defined(FLASH_BANK2_END)
// 判断是否为有效的BOOT1配置：复位或置位（仅适用于大容量产品）
#define IS_OB_BOOT1(BOOT1)         (((BOOT1) == OB_BOOT1_RESET) || ((BOOT1) == OB_BOOT1_SET))
#endif /* FLASH_BANK2_END */

/* 小容量产品 */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
// 检查页数是否有效：根据Flash大小寄存器判断地址范围是否越界
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08003FFFU))
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* 中容量产品 */
#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
// 检查页数是否有效：针对不同Flash容量(128KB, 64KB, 32KB等)进行地址范围检查
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08003FFFU))))
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/

/* 大容量产品 */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
// 检查页数是否有效：针对512KB, 384KB, 256KB容量进行地址范围检查
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0807FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0805FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU)))
#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* 超大容量产品 */
#if defined(FLASH_BANK2_END)
// 检查页数是否有效：针对1MB或768KB容量，支持双Bank
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080FFFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080BFFFFU))
#endif /* FLASH_BANK2_END */

/* 互联型产品 */
#if (defined(STM32F105xC) || defined(STM32F107xC))
// 检查页数是否有效：针对256KB, 128KB, 64KB容量
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) ==  0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU)))
#endif /* STM32F105xC || STM32F107xC */

// 检查写保护页参数是否有效
#define IS_OB_WRP(PAGE) (((PAGE) != 0x0000000U))

#if defined(FLASH_BANK_END)
// 检查Bank参数是否有效：Bank1, Bank2 或 Both（双Bank产品）
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1)  || \
                             ((BANK) == FLASH_BANK_2)  || \
                             ((BANK) == FLASH_BANK_BOTH))
#else
// 单Bank产品仅支持Bank1
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1))
#endif /* FLASH_BANK2_END */

/* 小容量产品 */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
// 检查Flash编程地址是否有效
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS)  (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                            ((ADDRESS) <= FLASH_BANK1_END) :  ((ADDRESS) <= 0x08003FFFU)))

#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* 中容量产品 */
#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
// 检查Flash编程地址是否有效，根据实际容量判断
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? \
                                           ((ADDRESS) <= 0x0800FFFF) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                           ((ADDRESS) <= 0x08007FFF) :  ((ADDRESS) <= 0x08003FFFU)))))

#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/

/* 大容量产品 */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
// 检查Flash编程地址是否有效
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? \
                                           ((ADDRESS) <= 0x0805FFFFU) :  ((ADDRESS) <= 0x0803FFFFU))))

#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* 超大容量产品 */
#if defined(FLASH_BANK2_END)
// 检查Flash编程地址是否有效，支持双Bank全范围
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? \
                                           ((ADDRESS) <= FLASH_BANK2_END) :  ((ADDRESS) <= 0x080BFFFFU)))

#endif /* FLASH_BANK2_END */

/* 互联型产品 */
#if (defined(STM32F105xC) || defined(STM32F107xC))
// 检查Flash编程地址是否有效
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= 0x0801FFFFU) :  ((ADDRESS) <= 0x0800FFFFU))))

#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */  

/* 导出类型 ------------------------------------------------------------*/ 
/** @defgroup FLASHEx_Exported_Types FLASHEx Exported Types
  * @{
  */  

/**
  * @brief  FLASH Erase structure definition
  *         FLASH 擦除结构体定义
  */
typedef struct
{
  uint32_t TypeErase;   /*!< TypeErase: Mass erase or page erase.
                             擦除类型：全片擦除或页擦除。
                             This parameter can be a value of @ref FLASHEx_Type_Erase */
  
  uint32_t Banks;       /*!< Select banks to erase when Mass erase is enabled.
                             当全片擦除使能时，选择要擦除的Bank。
                             This parameter must be a value of @ref FLASHEx_Banks */    
  
  uint32_t PageAddress; /*!< PageAdress: Initial FLASH page address to erase when mass erase is disabled
                             页地址：当非全片擦除时，指定擦除的起始页地址。
                             This parameter must be a number between Min_Data = 0x08000000 and Max_Data = FLASH_BANKx_END 
                             (x = 1 or 2 depending on devices)*/
  
  uint32_t NbPages;     /*!< NbPages: Number of pagess to be erased.
                             页数：要擦除的页数量。
                             This parameter must be a value between Min_Data = 1 and Max_Data = (max number of pages - value of initial page)*/
                                                          
} FLASH_EraseInitTypeDef;

/**
  * @brief  FLASH Options bytes program structure definition
  *         FLASH 选项字节编程结构体定义
  */
typedef struct
{
  uint32_t OptionType;  /*!< OptionType: Option byte to be configured.
                             选项字节类型：指定要配置的选项字节类型。
                             This parameter can be a value of @ref FLASHEx_OB_Type */

  uint32_t WRPState;    /*!< WRPState: Write protection activation or deactivation.
                             写保护状态：激活或失能写保护。
                             This parameter can be a value of @ref FLASHEx_OB_WRP_State */

  uint32_t WRPPage;     /*!< WRPPage: specifies the page(s) to be write protected
                             写保护页：指定哪些页需要进行写保护。
                             This parameter can be a value of @ref FLASHEx_OB_Write_Protection */

  uint32_t Banks;        /*!< Select banks for WRP activation/deactivation of all sectors.
                              选择Bank用于激活/失能所有扇区的写保护。
                              This parameter must be a value of @ref FLASHEx_Banks */ 
    
  uint8_t RDPLevel;     /*!< RDPLevel: Set the read protection level..
                             读保护等级：设置读保护等级。
                             This parameter can be a value of @ref FLASHEx_OB_Read_Protection */

#if defined(FLASH_BANK2_END)
  uint8_t USERConfig;   /*!< USERConfig: Program the FLASH User Option Byte: 
                             用户配置：配置FLASH用户选项字节。
                             IWDG / STOP / STDBY / BOOT1
                             包括：独立看门狗/停止模式/待机模式/BOOT1配置。
                             This parameter can be a combination of @ref FLASHEx_OB_IWatchdog, @ref FLASHEx_OB_nRST_STOP, 
                             @ref FLASHEx_OB_nRST_STDBY, @ref FLASHEx_OB_BOOT1 */
#else
  uint8_t USERConfig;   /*!< USERConfig: Program the FLASH User Option Byte: 
                             用户配置：配置FLASH用户选项字节。
                             IWDG / STOP / STDBY
                             包括：独立看门狗/停止模式/待机模式配置。
                             This parameter can be a combination of @ref FLASHEx_OB_IWatchdog, @ref FLASHEx_OB_nRST_STOP, 
                             @ref FLASHEx_OB_nRST_STDBY */
#endif /* FLASH_BANK2_END */

  uint32_t DATAAddress; /*!< DATAAddress: Address of the option byte DATA to be programmed
                             数据地址：要编程的选项字节数据地址。
                             This parameter can be a value of @ref FLASHEx_OB_Data_Address */
  
  uint8_t DATAData;     /*!< DATAData: Data to be stored in the option byte DATA
                             数据内容：要存储在选项字节中的数据。
                             This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF */
} FLASH_OBProgramInitTypeDef;

/**
  * @}
  */

/* 导出常量 --------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Constants FLASHEx Exported Constants
  * @{
  */  

/** @defgroup FLASHEx_Constants FLASH Constants
  * @{
  */ 

/** @defgroup FLASHEx_Page_Size Page Size
  * @{
  */ 
// 小容量和中容量产品的页大小为1KB (0x400)
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define FLASH_PAGE_SIZE          0x400U
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */
       /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */

// 大容量、超大容量和互联型产品的页大小为2KB (0x800)
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) || defined(STM32F101xG) || defined(STM32F103xG) || defined(STM32F105xC) || defined(STM32F107xC))
#define FLASH_PAGE_SIZE          0x800U
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       /* STM32F101xG || STM32F103xG */ 
       /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup FLASHEx_Type_Erase Type Erase
  * @{
  */ 
#define FLASH_TYPEERASE_PAGES     0x00U  /*!<Pages erase only*/ // 页擦除
#define FLASH_TYPEERASE_MASSERASE 0x02U  /*!<Flash mass erase activation*/ // 全片擦除

/**
  * @}
  */

/** @defgroup FLASHEx_Banks Banks
  * @{
  */
#if defined(FLASH_BANK2_END)
#define FLASH_BANK_1     1U /*!< Bank 1   */ // Flash Bank 1
#define FLASH_BANK_2     2U /*!< Bank 2   */ // Flash Bank 2
#define FLASH_BANK_BOTH  ((uint32_t)FLASH_BANK_1 | FLASH_BANK_2) /*!< Bank1 and Bank2  */ // Bank 1 和 Bank 2

#else
#define FLASH_BANK_1     1U /*!< Bank 1   */ // 仅 Bank 1
#endif
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FLASHEx_OptionByte_Constants Option Byte Constants
  * @{
  */ 

/** @defgroup FLASHEx_OB_Type Option Bytes Type
  * @{
  */
#define OPTIONBYTE_WRP            0x01U  /*!<WRP option byte configuration*/ // 写保护选项字节配置
#define OPTIONBYTE_RDP            0x02U  /*!<RDP option byte configuration*/ // 读保护选项字节配置
#define OPTIONBYTE_USER           0x04U  /*!<USER option byte configuration*/ // 用户选项字节配置
#define OPTIONBYTE_DATA           0x08U  /*!<DATA option byte configuration*/ // 数据选项字节配置

/**
  * @}
  */

/** @defgroup FLASHEx_OB_WRP_State Option Byte WRP State
  * @{
  */ 
#define OB_WRPSTATE_DISABLE       0x00U  /*!<Disable the write protection of the desired pages*/ // 禁用指定页的写保护
#define OB_WRPSTATE_ENABLE        0x01U  /*!<Enable the write protection of the desired pagess*/ // 使能指定页的写保护

/**
  * @}
  */

/** @defgroup FLASHEx_OB_Write_Protection Option Bytes Write Protection
  * @{
  */
/* STM32 小容量和中容量设备 */
#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) \
  || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) \
  || defined(STM32F103xB)
#define OB_WRP_PAGES0TO3               0x00000001U /*!< Write protection of page 0 to 3 */ // 写保护页 0 至 3
#define OB_WRP_PAGES4TO7               0x00000002U /*!< Write protection of page 4 to 7 */ // 写保护页 4 至 7
#define OB_WRP_PAGES8TO11              0x00000004U /*!< Write protection of page 8 to 11 */ // 写保护页 8 至 11
#define OB_WRP_PAGES12TO15             0x00000008U /*!< Write protection of page 12 to 15 */ // 写保护页 12 至 15
#define OB_WRP_PAGES16TO19             0x00000010U /*!< Write protection of page 16 to 19 */ // 写保护页 16 至 19
#define OB_WRP_PAGES20TO23             0x00000020U /*!< Write protection of page 20 to 23 */ // 写保护页 20 至 23
#define OB_WRP_PAGES24TO27             0x00000040U /*!< Write protection of page 24 to 27 */ // 写保护页 24 至 27
#define OB_WRP_PAGES28TO31             0x00000080U /*!< Write protection of page 28 to 31 */ // 写保护页 28 至 31
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */
       /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       
/* STM32 中容量设备 */
#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define OB_WRP_PAGES32TO35             0x00000100U   /*!< Write protection of page 32 to 35 */ // 写保护页 32 至 35
#define OB_WRP_PAGES36TO39             0x00000200U   /*!< Write protection of page 36 to 39 */ // 写保护页 36 至 39
#define OB_WRP_PAGES40TO43             0x00000400U   /*!< Write protection of page 40 to 43 */ // 写保护页 40 至 43
#define OB_WRP_PAGES44TO47             0x00000800U   /*!< Write protection of page 44 to 47 */ // 写保护页 44 至 47
#define OB_WRP_PAGES48TO51             0x00001000U   /*!< Write protection of page 48 to 51 */ // 写保护页 48 至 51
#define OB_WRP_PAGES52TO55             0x00002000U   /*!< Write protection of page 52 to 55 */ // 写保护页 52 至 55
#define OB_WRP_PAGES56TO59             0x00004000U   /*!< Write protection of page 56 to 59 */ // 写保护页 56 至 59
#define OB_WRP_PAGES60TO63             0x00008000U   /*!< Write protection of page 60 to 63 */ // 写保护页 60 至 63
#define OB_WRP_PAGES64TO67             0x00010000U   /*!< Write protection of page 64 to 67 */ // 写保护页 64 至 67
#define OB_WRP_PAGES68TO71             0x00020000U   /*!< Write protection of page 68 to 71 */ // 写保护页 68 至 71
#define OB_WRP_PAGES72TO75             0x00040000U   /*!< Write protection of page 72 to 75 */ // 写保护页 72 至 75
#define OB_WRP_PAGES76TO79             0x00080000U   /*!< Write protection of page 76 to 79 */ // 写保护页 76 至 79
#define OB_WRP_PAGES80TO83             0x00100000U   /*!< Write protection of page 80 to 83 */ // 写保护页 80 至 83
#define OB_WRP_PAGES84TO87             0x00200000U   /*!< Write protection of page 84 to 87 */ // 写保护页 84 至 87
#define OB_WRP_PAGES88TO91             0x00400000U   /*!< Write protection of page 88 to 91 */ // 写保护页 88 至 91
#define OB_WRP_PAGES92TO95             0x00800000U   /*!< Write protection of page 92 to 95 */ // 写保护页 92 至 95
#define OB_WRP_PAGES96TO99             0x01000000U   /*!< Write protection of page 96 to 99 */ // 写保护页 96 至 99
#define OB_WRP_PAGES100TO103           0x02000000U   /*!< Write protection of page 100 to 103 */ // 写保护页 100 至 103
#define OB_WRP_PAGES104TO107           0x04000000U   /*!< Write protection of page 104 to 107 */ // 写保护页 104 至 107
#define OB_WRP_PAGES108TO111           0x08000000U   /*!< Write protection of page 108 to 111 */ // 写保护页 108 至 111
#define OB_WRP_PAGES112TO115           0x10000000U   /*!< Write protection of page 112 to 115 */ // 写保护页 112 至 115
#define OB_WRP_PAGES116TO119           0x20000000U   /*!< Write protection of page 115 to 119 */ // 写保护页 116 至 119
#define OB_WRP_PAGES120TO123           0x40000000U   /*!< Write protection of page 120 to 123 */ // 写保护页 120 至 123
#define OB_WRP_PAGES124TO127           0x80000000U    /*!< Write protection of page 124 to 127 */ // 写保护页 124 至 127
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */

