
/* STM32 High-density, XL-density and Connectivity line devices */
#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) \
  || defined(STM32F101xG) || defined(STM32F103xG) \
  || defined(STM32F105xC) || defined(STM32F107xC)
#define OB_WRP_PAGES0TO1               0x00000001U  /*!< Write protection of page 0 TO 1 */
#define OB_WRP_PAGES2TO3               0x00000002U  /*!< Write protection of page 2 TO 3 */
#define OB_WRP_PAGES4TO5               0x00000004U  /*!< Write protection of page 4 TO 5 */
#define OB_WRP_PAGES6TO7               0x00000008U  /*!< Write protection of page 6 TO 7 */
#define OB_WRP_PAGES8TO9               0x00000010U  /*!< Write protection of page 8 TO 9 */
#define OB_WRP_PAGES10TO11             0x00000020U  /*!< Write protection of page 10 TO 11 */
#define OB_WRP_PAGES12TO13             0x00000040U  /*!< Write protection of page 12 TO 13 */
#define OB_WRP_PAGES14TO15             0x00000080U  /*!< Write protection of page 14 TO 15 */
#define OB_WRP_PAGES16TO17             0x00000100U  /*!< Write protection of page 16 TO 17 */
#define OB_WRP_PAGES18TO19             0x00000200U  /*!< Write protection of page 18 TO 19 */
#define OB_WRP_PAGES20TO21             0x00000400U  /*!< Write protection of page 20 TO 21 */
#define OB_WRP_PAGES22TO23             0x00000800U  /*!< Write protection of page 22 TO 23 */
#define OB_WRP_PAGES24TO25             0x00001000U  /*!< Write protection of page 24 TO 25 */
#define OB_WRP_PAGES26TO27             0x00002000U  /*!< Write protection of page 26 TO 27 */
#define OB_WRP_PAGES28TO29             0x00004000U  /*!< Write protection of page 28 TO 29 */
#define OB_WRP_PAGES30TO31             0x00008000U  /*!< Write protection of page 30 TO 31 */
#define OB_WRP_PAGES32TO33             0x00010000U  /*!< Write protection of page 32 TO 33 */
#define OB_WRP_PAGES34TO35             0x00020000U  /*!< Write protection of page 34 TO 35 */
#define OB_WRP_PAGES36TO37             0x00040000U  /*!< Write protection of page 36 TO 37 */
#define OB_WRP_PAGES38TO39             0x00080000U  /*!< Write protection of page 38 TO 39 */
#define OB_WRP_PAGES40TO41             0x00100000U  /*!< Write protection of page 40 TO 41 */
#define OB_WRP_PAGES42TO43             0x00200000U  /*!< Write protection of page 42 TO 43 */
#define OB_WRP_PAGES44TO45             0x00400000U  /*!< Write protection of page 44 TO 45 */
#define OB_WRP_PAGES46TO47             0x00800000U  /*!< Write protection of page 46 TO 47 */
#define OB_WRP_PAGES48TO49             0x01000000U  /*!< Write protection of page 48 TO 49 */
#define OB_WRP_PAGES50TO51             0x02000000U  /*!< Write protection of page 50 TO 51 */
#define OB_WRP_PAGES52TO53             0x04000000U  /*!< Write protection of page 52 TO 53 */
#define OB_WRP_PAGES54TO55             0x08000000U  /*!< Write protection of page 54 TO 55 */
#define OB_WRP_PAGES56TO57             0x10000000U  /*!< Write protection of page 56 TO 57 */
#define OB_WRP_PAGES58TO59             0x20000000U  /*!< Write protection of page 58 TO 59 */
#define OB_WRP_PAGES60TO61             0x40000000U  /*!< Write protection of page 60 TO 61 */
#define OB_WRP_PAGES62TO127            0x80000000U   /*!< Write protection of page 62 TO 127 */
#define OB_WRP_PAGES62TO255            0x80000000U   /*!< Write protection of page 62 TO 255 */
#define OB_WRP_PAGES62TO511            0x80000000U   /*!< Write protection of page 62 TO 511 */
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       /* STM32F101xG || STM32F103xG */ 
       /* STM32F105xC || STM32F107xC */

#define OB_WRP_ALLPAGES                0xFFFFFFFFU  /*!< Write protection of all Pages */
 
/* Low Density */
#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6)
#define OB_WRP_PAGES0TO31MASK          0x000000FFU 
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* Medium Density */
#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
#define OB_WRP_PAGES0TO31MASK          0x000000FFU
#define OB_WRP_PAGES32TO63MASK         0x0000FF00U
#define OB_WRP_PAGES64TO95MASK         0x00FF0000U
#define OB_WRP_PAGES96TO127MASK        0xFF000000U
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/
       
/* High Density */
#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE)  
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
#define OB_WRP_PAGES48TO255MASK        0xFF000000U
#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* XL Density */
#if  defined(STM32F101xG) || defined(STM32F103xG) 
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
#define OB_WRP_PAGES48TO511MASK        0xFF000000U
#endif /* STM32F101xG || STM32F103xG */
      
/* Connectivity line devices */
#if defined(STM32F105xC) || defined(STM32F107xC)
#define OB_WRP_PAGES0TO15MASK          0x000000FFU
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U
#define OB_WRP_PAGES48TO127MASK        0xFF000000U
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup FLASHEx_OB_Read_Protection Option Byte Read Protection
  * @{
  */
#define OB_RDP_LEVEL_0            ((uint8_t)0xA5)
#define OB_RDP_LEVEL_1            ((uint8_t)0x00)
/**
  * @}
  */
  
/** @defgroup FLASHEx_OB_IWatchdog Option Byte IWatchdog
  * @{
  */ 
#define OB_IWDG_SW                ((uint16_t)0x0001)  /*!< Software IWDG selected */
#define OB_IWDG_HW                ((uint16_t)0x0000)  /*!< Hardware IWDG selected */
/**
  * @}
  */

/** @defgroup FLASHEx_OB_nRST_STOP Option Byte nRST STOP
  * @{
  */ 
#define OB_STOP_NO_RST            ((uint16_t)0x0002) /*!< No reset generated when entering in STOP */
#define OB_STOP_RST               ((uint16_t)0x0000) /*!< Reset generated when entering in STOP */
/**
  * @}
  */ 

/** @defgroup FLASHEx_OB_nRST_STDBY Option Byte nRST STDBY
  * @{
  */ 
#define OB_STDBY_NO_RST           ((uint16_t)0x0004) /*!< No reset generated when entering in STANDBY */
#define OB_STDBY_RST              ((uint16_t)0x0000) /*!< Reset generated when entering in STANDBY */
/**
  * @}
  */

#if defined(FLASH_BANK2_END)
/** @defgroup FLASHEx_OB_BOOT1 Option Byte BOOT1
  * @{
  */
#define OB_BOOT1_RESET            ((uint16_t)0x0000) /*!< BOOT1 Reset */
#define OB_BOOT1_SET              ((uint16_t)0x0008) /*!< BOOT1 Set */
/**
  * @}
  */
#endif /* FLASH_BANK2_END */

/** @defgroup FLASHEx_OB_Data_Address  Option Byte Data Address
  * @{
  */
#define OB_DATA_ADDRESS_DATA0     0x1FFFF804U
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
  * @brief Flag definition
  * @{
  */
#if defined(FLASH_BANK2_END)
 #define FLASH_FLAG_BSY             FLASH_FLAG_BSY_BANK1       /*!< FLASH Bank1 Busy flag                   */ 
 #define FLASH_FLAG_PGERR           FLASH_FLAG_PGERR_BANK1     /*!< FLASH Bank1 Programming error flag      */
 #define FLASH_FLAG_WRPERR          FLASH_FLAG_WRPERR_BANK1    /*!< FLASH Bank1 Write protected error flag  */
 #define FLASH_FLAG_EOP             FLASH_FLAG_EOP_BANK1       /*!< FLASH Bank1 End of Operation flag       */

 #define FLASH_FLAG_BSY_BANK1       FLASH_SR_BSY               /*!< FLASH Bank1 Busy flag                   */ 
 #define FLASH_FLAG_PGERR_BANK1     FLASH_SR_PGERR             /*!< FLASH Bank1 Programming error flag      */
 #define FLASH_FLAG_WRPERR_BANK1    FLASH_SR_WRPRTERR          /*!< FLASH Bank1 Write protected error flag  */
 #define FLASH_FLAG_EOP_BANK1       FLASH_SR_EOP               /*!< FLASH Bank1 End of Operation flag       */
       
 #define FLASH_FLAG_BSY_BANK2       (FLASH_SR2_BSY << 16U)      /*!< FLASH Bank2 Busy flag                   */ 
 #define FLASH_FLAG_PGERR_BANK2     (FLASH_SR2_PGERR << 16U)    /*!< FLASH Bank2 Programming error flag      */
 #define FLASH_FLAG_WRPERR_BANK2    (FLASH_SR2_WRPRTERR << 16U) /*!< FLASH Bank2 Write protected error flag  */
 #define FLASH_FLAG_EOP_BANK2       (FLASH_SR2_EOP << 16U)      /*!< FLASH Bank2 End of Operation flag       */

#else  

 #define FLASH_FLAG_BSY             FLASH_SR_BSY              /*!< FLASH Busy flag                          */ 
 #define FLASH_FLAG_PGERR           FLASH_SR_PGERR            /*!< FLASH Programming error flag             */
 #define FLASH_FLAG_WRPERR          FLASH_SR_WRPRTERR         /*!< FLASH Write protected error flag         */
 #define FLASH_FLAG_EOP             FLASH_SR_EOP              /*!< FLASH End of Operation flag              */

#endif
 #define FLASH_FLAG_OPTVERR         ((OBR_REG_INDEX << 8U | FLASH_OBR_OPTERR)) /*!< Option Byte Error        */
/**
  * @}
  */
  
/** @defgroup FLASH_Interrupt_definition Interrupt definition
  * @brief FLASH Interrupt definition
  * @{
  */
#if defined(FLASH_BANK2_END)
 #define FLASH_IT_EOP               FLASH_IT_EOP_BANK1        /*!< End of FLASH Operation Interrupt source Bank1 */
 #define FLASH_IT_ERR               FLASH_IT_ERR_BANK1        /*!< Error Interrupt source Bank1                  */

 #define FLASH_IT_EOP_BANK1         FLASH_CR_EOPIE            /*!< End of FLASH Operation Interrupt source Bank1 */
 #define FLASH_IT_ERR_BANK1         FLASH_CR_ERRIE            /*!< Error Interrupt source Bank1                  */

 #define FLASH_IT_EOP_BANK2         (FLASH_CR2_EOPIE << 16U)   /*!< End of FLASH Operation Interrupt source Bank2 */
 #define FLASH_IT_ERR_BANK2         (FLASH_CR2_ERRIE << 16U)   /*!< Error Interrupt source Bank2                  */

#else

 #define FLASH_IT_EOP               FLASH_CR_EOPIE          /*!< End of FLASH Operation Interrupt source */
 #define FLASH_IT_ERR               FLASH_CR_ERRIE          /*!< Error Interrupt source                  */

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

/* Exported macro ------------------------------------------------------------*/
/** @defgroup FLASHEx_Exported_Macros FLASHEx Exported Macros
  * @{
  */

/** @defgroup FLASH_Interrupt Interrupt
 *  @brief macros to handle FLASH interrupts
 * @{
 */ 

#if defined(FLASH_BANK2_END)
/**
  * @brief  Enable the specified FLASH interrupt.
  * @param  __INTERRUPT__  FLASH interrupt 
  *     This parameter can be any combination of the following values:
  *     @arg @ref FLASH_IT_EOP_BANK1 End of FLASH Operation Interrupt on bank1
  *     @arg @ref FLASH_IT_ERR_BANK1 Error Interrupt on bank1
  *     @arg @ref FLASH_IT_EOP_BANK2 End of FLASH Operation Interrupt on bank2
  *     @arg @ref FLASH_IT_ERR_BANK2 Error Interrupt on bank2
  * @retval none
  */ 
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  do { \
                          /* Enable Bank1 IT */ \
                          SET_BIT(FLASH->CR, ((__INTERRUPT__) & 0x0000FFFFU)); \
                          /* Enable Bank2 IT */ \
                          SET_BIT(FLASH->CR2, ((__INTERRUPT__) >> 16U)); \
                    } while(0U)

/**
  * @brief  Disable the specified FLASH interrupt.
  * @param  __INTERRUPT__  FLASH interrupt 
  *     This parameter can be any combination of the following values:
  *     @arg @ref FLASH_IT_EOP_BANK1 End of FLASH Operation Interrupt on bank1
  *     @arg @ref FLASH_IT_ERR_BANK1 Error Interrupt on bank1
  *     @arg @ref FLASH_IT_EOP_BANK2 End of FLASH Operation Interrupt on bank2
  *     @arg @ref FLASH_IT_ERR_BANK2 Error Interrupt on bank2
  * @retval none
  */ 
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)  do { \
                          /* Disable Bank1 IT */ \
                          CLEAR_BIT(FLASH->CR, ((__INTERRUPT__) & 0x0000FFFFU)); \
                          /* Disable Bank2 IT */ \
                          CLEAR_BIT(FLASH->CR2, ((__INTERRUPT__) >> 16U)); \
                    } while(0U)

/**
  * @brief  Get the specified FLASH flag status. 
  * @param  __FLAG__ specifies the FLASH flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref FLASH_FLAG_EOP_BANK1    FLASH End of Operation flag on bank1
  *            @arg @ref FLASH_FLAG_WRPERR_BANK1 FLASH Write protected error flag on bank1
  *            @arg @ref FLASH_FLAG_PGERR_BANK1  FLASH Programming error flag on bank1
  *            @arg @ref FLASH_FLAG_BSY_BANK1    FLASH Busy flag on bank1
  *            @arg @ref FLASH_FLAG_EOP_BANK2    FLASH End of Operation flag on bank2
  *            @arg @ref FLASH_FLAG_WRPERR_BANK2 FLASH Write protected error flag on bank2
  *            @arg @ref FLASH_FLAG_PGERR_BANK2  FLASH Programming error flag on bank2
  *            @arg @ref FLASH_FLAG_BSY_BANK2    FLASH Busy flag on bank2
  *            @arg @ref FLASH_FLAG_OPTVERR  Loaded OB and its complement do not match
  * @retval The new state of __FLAG__ (SET or RESET).
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__) (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                        ((((__FLAG__) & SR_FLAG_MASK) != RESET)? \
                                            (FLASH->SR & ((__FLAG__) & SR_FLAG_MASK)) : \
                                            (FLASH->SR2 & ((__FLAG__) >> 16U))))

/**
  * @brief  Clear the specified FLASH flag.
  * @param  __FLAG__ specifies the FLASH flags to clear.
  *          This parameter can be any combination of the following values:
  *            @arg @ref FLASH_FLAG_EOP_BANK1    FLASH End of Operation flag on bank1
  *            @arg @ref FLASH_FLAG_WRPERR_BANK1 FLASH Write protected error flag on bank1
  *            @arg @ref FLASH_FLAG_PGERR_BANK1  FLASH Programming error flag on bank1
  *            @arg @ref FLASH_FLAG_BSY_BANK1    FLASH Busy flag on bank1
  *            @arg @ref FLASH_FLAG_EOP_BANK2    FLASH End of Operation flag on bank2
  *            @arg @ref FLASH_FLAG_WRPERR_BANK2 FLASH Write protected error flag on bank2
  *            @arg @ref FLASH_FLAG_PGERR_BANK2  FLASH Programming error flag on bank2
  *            @arg @ref FLASH_FLAG_BSY_BANK2    FLASH Busy flag on bank2
  *            @arg @ref FLASH_FLAG_OPTVERR  Loaded OB and its complement do not match
  * @retval none
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)  do { \
                          /* Clear FLASH_FLAG_OPTVERR flag */ \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                          /* Clear Flag in Bank1 */ \
                          if (((__FLAG__) & SR_FLAG_MASK) != RESET) \
                          { \
                            FLASH->SR  = ((__FLAG__) & SR_FLAG_MASK); \
                          } \
                          /* Clear Flag in Bank2 */ \
                          if (((__FLAG__) >> 16U) != RESET) \
                          { \
                            FLASH->SR2 = ((__FLAG__) >> 16U); \
                          } \
                          } \
                    } while(0U)
#else
/**
  * @brief  Enable the specified FLASH interrupt.
  * @param  __INTERRUPT__  FLASH interrupt 
  *         This parameter can be any combination of the following values:
  *     @arg @ref FLASH_IT_EOP End of FLASH Operation Interrupt
  *     @arg @ref FLASH_IT_ERR Error Interrupt    
  * @retval none
  */ 
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  (FLASH->CR |= (__INTERRUPT__))

/**
  * @brief  Disable the specified FLASH interrupt.
  * @param  __INTERRUPT__  FLASH interrupt 
  *         This parameter can be any combination of the following values:
  *     @arg @ref FLASH_IT_EOP End of FLASH Operation Interrupt
  *     @arg @ref FLASH_IT_ERR Error Interrupt    
  * @retval none
  */ 
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)   (FLASH->CR &= ~(__INTERRUPT__))

/**
  * @brief  Get the specified FLASH flag status. 
  * @param  __FLAG__ specifies the FLASH flag to check.
  *          This parameter can be one of the following values:
  *            @arg @ref FLASH_FLAG_EOP    FLASH End of Operation flag 
  *            @arg @ref FLASH_FLAG_WRPERR FLASH Write protected error flag 
  *            @arg @ref FLASH_FLAG_PGERR  FLASH Programming error flag
  *            @arg @ref FLASH_FLAG_BSY    FLASH Busy flag
  *            @arg @ref FLASH_FLAG_OPTVERR  Loaded OB and its complement do not match
  * @retval The new state of __FLAG__ (SET or RESET).
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__)  (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                            (FLASH->SR & (__FLAG__)))
/**
  * @brief  Clear the specified FLASH flag.
  * @param  __FLAG__ specifies the FLASH flags to clear.
  *          This parameter can be any combination of the following values:
  *            @arg @ref FLASH_FLAG_EOP    FLASH End of Operation flag 
  *            @arg @ref FLASH_FLAG_WRPERR FLASH Write protected error flag 
  *            @arg @ref FLASH_FLAG_PGERR  FLASH Programming error flag 
  *            @arg @ref FLASH_FLAG_OPTVERR  Loaded OB and its complement do not match
  * @retval none
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)   do { \
                          /* Clear FLASH_FLAG_OPTVERR flag */ \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                            /* Clear Flag in Bank1 */ \
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

/* Exported functions --------------------------------------------------------*/
/** @addtogroup FLASHEx_Exported_Functions
  * @{
  */

/** @addtogroup FLASHEx_Exported_Functions_Group1
  * @{
  */
/* IO operation functions *****************************************************/
HAL_StatusTypeDef  HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
HAL_StatusTypeDef  HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);

/**
  * @}
  */

/** @addtogroup FLASHEx_Exported_Functions_Group2
  * @{
  */
/* Peripheral Control functions ***********************************************/
HAL_StatusTypeDef  HAL_FLASHEx_OBErase(void);
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void               HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
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

