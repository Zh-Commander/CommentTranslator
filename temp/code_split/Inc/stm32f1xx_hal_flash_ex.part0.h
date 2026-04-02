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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_HAL_FLASH_EX_H
#define __STM32F1xx_HAL_FLASH_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
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

#define FLASH_SIZE_DATA_REGISTER     0x1FFFF7E0U
#define OBR_REG_INDEX                1U
#define SR_FLAG_MASK                 ((uint32_t)(FLASH_SR_BSY | FLASH_SR_PGERR | FLASH_SR_WRPRTERR | FLASH_SR_EOP))

/**
  * @}
  */  

/** @addtogroup FLASHEx_Private_Macros
  * @{
  */

#define IS_FLASH_TYPEERASE(VALUE)   (((VALUE) == FLASH_TYPEERASE_PAGES) || ((VALUE) == FLASH_TYPEERASE_MASSERASE))

#define IS_OPTIONBYTE(VALUE)        (((VALUE) <= (OPTIONBYTE_WRP | OPTIONBYTE_RDP | OPTIONBYTE_USER | OPTIONBYTE_DATA)))

#define IS_WRPSTATE(VALUE)          (((VALUE) == OB_WRPSTATE_DISABLE) || ((VALUE) == OB_WRPSTATE_ENABLE))

#define IS_OB_RDP_LEVEL(LEVEL)      (((LEVEL) == OB_RDP_LEVEL_0) || ((LEVEL) == OB_RDP_LEVEL_1))

#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == OB_DATA_ADDRESS_DATA0) || ((ADDRESS) == OB_DATA_ADDRESS_DATA1)) 

#define IS_OB_IWDG_SOURCE(SOURCE)   (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

#define IS_OB_STOP_SOURCE(SOURCE)   (((SOURCE) == OB_STOP_NO_RST) || ((SOURCE) == OB_STOP_RST))

#define IS_OB_STDBY_SOURCE(SOURCE)  (((SOURCE) == OB_STDBY_NO_RST) || ((SOURCE) == OB_STDBY_RST))

#if defined(FLASH_BANK2_END)
#define IS_OB_BOOT1(BOOT1)         (((BOOT1) == OB_BOOT1_RESET) || ((BOOT1) == OB_BOOT1_SET))
#endif /* FLASH_BANK2_END */

/* Low Density */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)- 1 <= 0x08003FFFU))
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* Medium Density */
#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08007FFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x08003FFFU))))
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/

/* High Density */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0807FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0805FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU)))
#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* XL Density */
#if defined(FLASH_BANK2_END)
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080FFFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x080BFFFFU))
#endif /* FLASH_BANK2_END */

/* Connectivity Line */
#if (defined(STM32F105xC) || defined(STM32F107xC))
#define IS_FLASH_NB_PAGES(ADDRESS,NBPAGES) (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0803FFFFU) : \
                                           (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) ==  0x80U) ? ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0801FFFFU) : \
                                           ((ADDRESS)+((NBPAGES)*FLASH_PAGE_SIZE)-1 <= 0x0800FFFFU)))
#endif /* STM32F105xC || STM32F107xC */

#define IS_OB_WRP(PAGE) (((PAGE) != 0x0000000U))

#if defined(FLASH_BANK2_END)
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1)  || \
                             ((BANK) == FLASH_BANK_2)  || \
                             ((BANK) == FLASH_BANK_BOTH))
#else
#define IS_FLASH_BANK(BANK) (((BANK) == FLASH_BANK_1))
#endif /* FLASH_BANK2_END */

/* Low Density */
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS)  (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                            ((ADDRESS) <= FLASH_BANK1_END) :  ((ADDRESS) <= 0x08003FFFU)))

#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* Medium Density */
#if (defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x40U) ? \
                                           ((ADDRESS) <= 0x0800FFFF) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x20U) ? \
                                           ((ADDRESS) <= 0x08007FFF) :  ((ADDRESS) <= 0x08003FFFU)))))

#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/

/* High Density */
#if (defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x200U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x180U) ? \
                                           ((ADDRESS) <= 0x0805FFFFU) :  ((ADDRESS) <= 0x0803FFFFU))))

#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* XL Density */
#if defined(FLASH_BANK2_END)
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x400U) ? \
                                           ((ADDRESS) <= FLASH_BANK2_END) :  ((ADDRESS) <= 0x080BFFFFU)))

#endif /* FLASH_BANK2_END */

/* Connectivity Line */
#if (defined(STM32F105xC) || defined(STM32F107xC))
#define IS_FLASH_PROGRAM_ADDRESS(ADDRESS) (((ADDRESS) >= FLASH_BASE) && (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x100U) ? \
                                           ((ADDRESS) <= FLASH_BANK1_END) :  (((*((uint16_t *)FLASH_SIZE_DATA_REGISTER)) == 0x80U) ? \
                                           ((ADDRESS) <= 0x0801FFFFU) :  ((ADDRESS) <= 0x0800FFFFU))))

#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */  

/* Exported types ------------------------------------------------------------*/ 
/** @defgroup FLASHEx_Exported_Types FLASHEx Exported Types
  * @{
  */  

/**
  * @brief  FLASH Erase structure definition
  */
typedef struct
{
  uint32_t TypeErase;   /*!< TypeErase: Mass erase or page erase.
                             This parameter can be a value of @ref FLASHEx_Type_Erase */
  
  uint32_t Banks;       /*!< Select banks to erase when Mass erase is enabled.
                             This parameter must be a value of @ref FLASHEx_Banks */    
  
  uint32_t PageAddress; /*!< PageAdress: Initial FLASH page address to erase when mass erase is disabled
                             This parameter must be a number between Min_Data = 0x08000000 and Max_Data = FLASH_BANKx_END 
                             (x = 1 or 2 depending on devices)*/
  
  uint32_t NbPages;     /*!< NbPages: Number of pagess to be erased.
                             This parameter must be a value between Min_Data = 1 and Max_Data = (max number of pages - value of initial page)*/
                                                          
} FLASH_EraseInitTypeDef;

/**
  * @brief  FLASH Options bytes program structure definition
  */
typedef struct
{
  uint32_t OptionType;  /*!< OptionType: Option byte to be configured.
                             This parameter can be a value of @ref FLASHEx_OB_Type */

  uint32_t WRPState;    /*!< WRPState: Write protection activation or deactivation.
                             This parameter can be a value of @ref FLASHEx_OB_WRP_State */

  uint32_t WRPPage;     /*!< WRPPage: specifies the page(s) to be write protected
                             This parameter can be a value of @ref FLASHEx_OB_Write_Protection */

  uint32_t Banks;        /*!< Select banks for WRP activation/deactivation of all sectors.
                              This parameter must be a value of @ref FLASHEx_Banks */ 
    
  uint8_t RDPLevel;     /*!< RDPLevel: Set the read protection level..
                             This parameter can be a value of @ref FLASHEx_OB_Read_Protection */

#if defined(FLASH_BANK2_END)
  uint8_t USERConfig;   /*!< USERConfig: Program the FLASH User Option Byte: 
                             IWDG / STOP / STDBY / BOOT1
                             This parameter can be a combination of @ref FLASHEx_OB_IWatchdog, @ref FLASHEx_OB_nRST_STOP, 
                             @ref FLASHEx_OB_nRST_STDBY, @ref FLASHEx_OB_BOOT1 */
#else
  uint8_t USERConfig;   /*!< USERConfig: Program the FLASH User Option Byte: 
                             IWDG / STOP / STDBY
                             This parameter can be a combination of @ref FLASHEx_OB_IWatchdog, @ref FLASHEx_OB_nRST_STOP, 
                             @ref FLASHEx_OB_nRST_STDBY */
#endif /* FLASH_BANK2_END */

  uint32_t DATAAddress; /*!< DATAAddress: Address of the option byte DATA to be programmed
                             This parameter can be a value of @ref FLASHEx_OB_Data_Address */
  
  uint8_t DATAData;     /*!< DATAData: Data to be stored in the option byte DATA
                             This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF */
} FLASH_OBProgramInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Constants FLASHEx Exported Constants
  * @{
  */  

/** @defgroup FLASHEx_Constants FLASH Constants
  * @{
  */ 

/** @defgroup FLASHEx_Page_Size Page Size
  * @{
  */ 
#if (defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB))
#define FLASH_PAGE_SIZE          0x400U
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */
       /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */

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
#define FLASH_TYPEERASE_PAGES     0x00U  /*!<Pages erase only*/
#define FLASH_TYPEERASE_MASSERASE 0x02U  /*!<Flash mass erase activation*/

/**
  * @}
  */

/** @defgroup FLASHEx_Banks Banks
  * @{
  */
#if defined(FLASH_BANK2_END)
#define FLASH_BANK_1     1U /*!< Bank 1   */
#define FLASH_BANK_2     2U /*!< Bank 2   */
#define FLASH_BANK_BOTH  ((uint32_t)FLASH_BANK_1 | FLASH_BANK_2) /*!< Bank1 and Bank2  */

#else
#define FLASH_BANK_1     1U /*!< Bank 1   */
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
#define OPTIONBYTE_WRP            0x01U  /*!<WRP option byte configuration*/
#define OPTIONBYTE_RDP            0x02U  /*!<RDP option byte configuration*/
#define OPTIONBYTE_USER           0x04U  /*!<USER option byte configuration*/
#define OPTIONBYTE_DATA           0x08U  /*!<DATA option byte configuration*/

/**
  * @}
  */

/** @defgroup FLASHEx_OB_WRP_State Option Byte WRP State
  * @{
  */ 
#define OB_WRPSTATE_DISABLE       0x00U  /*!<Disable the write protection of the desired pages*/
#define OB_WRPSTATE_ENABLE        0x01U  /*!<Enable the write protection of the desired pagess*/

/**
  * @}
  */

/** @defgroup FLASHEx_OB_Write_Protection Option Bytes Write Protection
  * @{
  */
/* STM32 Low and Medium density devices */
#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6) \
  || defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) \
  || defined(STM32F103xB)
#define OB_WRP_PAGES0TO3               0x00000001U /*!< Write protection of page 0 to 3 */
#define OB_WRP_PAGES4TO7               0x00000002U /*!< Write protection of page 4 to 7 */
#define OB_WRP_PAGES8TO11              0x00000004U /*!< Write protection of page 8 to 11 */
#define OB_WRP_PAGES12TO15             0x00000008U /*!< Write protection of page 12 to 15 */
#define OB_WRP_PAGES16TO19             0x00000010U /*!< Write protection of page 16 to 19 */
#define OB_WRP_PAGES20TO23             0x00000020U /*!< Write protection of page 20 to 23 */
#define OB_WRP_PAGES24TO27             0x00000040U /*!< Write protection of page 24 to 27 */
#define OB_WRP_PAGES28TO31             0x00000080U /*!< Write protection of page 28 to 31 */
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */
       /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       
/* STM32 Medium-density devices */
#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define OB_WRP_PAGES32TO35             0x00000100U   /*!< Write protection of page 32 to 35 */
#define OB_WRP_PAGES36TO39             0x00000200U   /*!< Write protection of page 36 to 39 */
#define OB_WRP_PAGES40TO43             0x00000400U   /*!< Write protection of page 40 to 43 */
#define OB_WRP_PAGES44TO47             0x00000800U   /*!< Write protection of page 44 to 47 */
#define OB_WRP_PAGES48TO51             0x00001000U   /*!< Write protection of page 48 to 51 */
#define OB_WRP_PAGES52TO55             0x00002000U   /*!< Write protection of page 52 to 55 */
#define OB_WRP_PAGES56TO59             0x00004000U   /*!< Write protection of page 56 to 59 */
#define OB_WRP_PAGES60TO63             0x00008000U   /*!< Write protection of page 60 to 63 */
#define OB_WRP_PAGES64TO67             0x00010000U   /*!< Write protection of page 64 to 67 */
#define OB_WRP_PAGES68TO71             0x00020000U   /*!< Write protection of page 68 to 71 */
#define OB_WRP_PAGES72TO75             0x00040000U   /*!< Write protection of page 72 to 75 */
#define OB_WRP_PAGES76TO79             0x00080000U   /*!< Write protection of page 76 to 79 */
#define OB_WRP_PAGES80TO83             0x00100000U   /*!< Write protection of page 80 to 83 */
#define OB_WRP_PAGES84TO87             0x00200000U   /*!< Write protection of page 84 to 87 */
#define OB_WRP_PAGES88TO91             0x00400000U   /*!< Write protection of page 88 to 91 */
#define OB_WRP_PAGES92TO95             0x00800000U   /*!< Write protection of page 92 to 95 */
#define OB_WRP_PAGES96TO99             0x01000000U   /*!< Write protection of page 96 to 99 */
#define OB_WRP_PAGES100TO103           0x02000000U   /*!< Write protection of page 100 to 103 */
#define OB_WRP_PAGES104TO107           0x04000000U   /*!< Write protection of page 104 to 107 */
#define OB_WRP_PAGES108TO111           0x08000000U   /*!< Write protection of page 108 to 111 */
#define OB_WRP_PAGES112TO115           0x10000000U   /*!< Write protection of page 112 to 115 */
#define OB_WRP_PAGES116TO119           0x20000000U   /*!< Write protection of page 115 to 119 */
#define OB_WRP_PAGES120TO123           0x40000000U   /*!< Write protection of page 120 to 123 */
#define OB_WRP_PAGES124TO127           0x80000000U    /*!< Write protection of page 124 to 127 */
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */

