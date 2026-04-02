/* STM32 高密度、超大密度和互联型设备 */
#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE) \
  || defined(STM32F101xG) || defined(STM32F103xG) \
  || defined(STM32F105xC) || defined(STM32F107xC)
// 以下宏定义用于指定Flash页的写保护，每个宏对应保护特定的页范围
#define OB_WRP_PAGES0TO1               0x00000001U  /*!< 写保护页 0 到 1 */
#define OB_WRP_PAGES2TO3               0x00000002U  /*!< 写保护页 2 到 3 */
#define OB_WRP_PAGES4TO5               0x00000004U  /*!< 写保护页 4 到 5 */
#define OB_WRP_PAGES6TO7               0x00000008U  /*!< 写保护页 6 到 7 */
#define OB_WRP_PAGES8TO9               0x00000010U  /*!< 写保护页 8 到 9 */
#define OB_WRP_PAGES10TO11             0x00000020U  /*!< 写保护页 10 到 11 */
#define OB_WRP_PAGES12TO13             0x00000040U  /*!< 写保护页 12 到 13 */
#define OB_WRP_PAGES14TO15             0x00000080U  /*!< 写保护页 14 到 15 */
#define OB_WRP_PAGES16TO17             0x00000100U  /*!< 写保护页 16 到 17 */
#define OB_WRP_PAGES18TO19             0x00000200U  /*!< 写保护页 18 到 19 */
#define OB_WRP_PAGES20TO21             0x00000400U  /*!< 写保护页 20 到 21 */
#define OB_WRP_PAGES22TO23             0x00000800U  /*!< 写保护页 22 到 23 */
#define OB_WRP_PAGES24TO25             0x00001000U  /*!< 写保护页 24 到 25 */
#define OB_WRP_PAGES26TO27             0x00002000U  /*!< 写保护页 26 到 27 */
#define OB_WRP_PAGES28TO29             0x00004000U  /*!< 写保护页 28 到 29 */
#define OB_WRP_PAGES30TO31             0x00008000U  /*!< 写保护页 30 到 31 */
#define OB_WRP_PAGES32TO33             0x00010000U  /*!< 写保护页 32 到 33 */
#define OB_WRP_PAGES34TO35             0x00020000U  /*!< 写保护页 34 到 35 */
#define OB_WRP_PAGES36TO37             0x00040000U  /*!< 写保护页 36 到 37 */
#define OB_WRP_PAGES38TO39             0x00080000U  /*!< 写保护页 38 到 39 */
#define OB_WRP_PAGES40TO41             0x00100000U  /*!< 写保护页 40 到 41 */
#define OB_WRP_PAGES42TO43             0x00200000U  /*!< 写保护页 42 到 43 */
#define OB_WRP_PAGES44TO45             0x00400000U  /*!< 写保护页 44 到 45 */
#define OB_WRP_PAGES46TO47             0x00800000U  /*!< 写保护页 46 到 47 */
#define OB_WRP_PAGES48TO49             0x01000000U  /*!< 写保护页 48 到 49 */
#define OB_WRP_PAGES50TO51             0x02000000U  /*!< 写保护页 50 到 51 */
#define OB_WRP_PAGES52TO53             0x04000000U  /*!< 写保护页 52 到 53 */
#define OB_WRP_PAGES54TO55             0x08000000U  /*!< 写保护页 54 到 55 */
#define OB_WRP_PAGES56TO57             0x10000000U  /*!< 写保护页 56 到 57 */
#define OB_WRP_PAGES58TO59             0x20000000U  /*!< 写保护页 58 到 59 */
#define OB_WRP_PAGES60TO61             0x40000000U  /*!< 写保护页 60 到 61 */
#define OB_WRP_PAGES62TO127            0x80000000U   /*!< 写保护页 62 到 127 */
#define OB_WRP_PAGES62TO255            0x80000000U   /*!< 写保护页 62 到 255 */
#define OB_WRP_PAGES62TO511            0x80000000U   /*!< 写保护页 62 到 511 */
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB */
       /* STM32F101xG || STM32F103xG */ 
       /* STM32F105xC || STM32F107xC */

// 定义所有页的写保护宏
#define OB_WRP_ALLPAGES                0xFFFFFFFFU  /*!< 写保护所有页 */
 
/* 低密度设备 */
#if  defined(STM32F101x6) || defined(STM32F102x6) || defined(STM32F103x6)
// 页0到页31的掩码，用于低密度设备
#define OB_WRP_PAGES0TO31MASK          0x000000FFU 
#endif /* STM32F101x6 || STM32F102x6 || STM32F103x6 */

/* 中密度设备 */
#if  defined(STM32F100xB) || defined(STM32F101xB) || defined(STM32F102xB) || defined(STM32F103xB)
// 页范围掩码，用于中密度设备
#define OB_WRP_PAGES0TO31MASK          0x000000FFU  // 页 0-31 的掩码
#define OB_WRP_PAGES32TO63MASK         0x0000FF00U  // 页 32-63 的掩码
#define OB_WRP_PAGES64TO95MASK         0x00FF0000U  // 页 64-95 的掩码
#define OB_WRP_PAGES96TO127MASK        0xFF000000U  // 页 96-127 的掩码
#endif /* STM32F100xB || STM32F101xB || STM32F102xB || STM32F103xB*/
       
/* 高密度设备 */
#if  defined(STM32F100xE) || defined(STM32F101xE) || defined(STM32F103xE)  
// 页范围掩码，用于高密度设备
#define OB_WRP_PAGES0TO15MASK          0x000000FFU  // 页 0-15 的掩码
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U  // 页 16-31 的掩码
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U  // 页 32-47 的掩码
#define OB_WRP_PAGES48TO255MASK        0xFF000000U  // 页 48-255 的掩码
#endif /* STM32F100xE || STM32F101xE || STM32F103xE */

/* 超大密度设备 */
#if  defined(STM32F101xG) || defined(STM32F103xG) 
// 页范围掩码，用于超大密度设备
#define OB_WRP_PAGES0TO15MASK          0x000000FFU  // 页 0-15 的掩码
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U  // 页 16-31 的掩码
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U  // 页 32-47 的掩码
#define OB_WRP_PAGES48TO511MASK        0xFF000000U  // 页 48-511 的掩码
#endif /* STM32F101xG || STM32F103xG */
      
/* 互联型设备 */
#if defined(STM32F105xC) || defined(STM32F107xC)
// 页范围掩码，用于互联型设备
#define OB_WRP_PAGES0TO15MASK          0x000000FFU  // 页 0-15 的掩码
#define OB_WRP_PAGES16TO31MASK         0x0000FF00U  // 页 16-31 的掩码
#define OB_WRP_PAGES32TO47MASK         0x00FF0000U  // 页 32-47 的掩码
#define OB_WRP_PAGES48TO127MASK        0xFF000000U  // 页 48-127 的掩码
#endif /* STM32F105xC || STM32F107xC */

/**
  * @}
  */

/** @defgroup FLASHEx_OB_Read_Protection Option Byte Read Protection
  * @brief 选项字节读保护配置
  * @{
  */
// 读保护级别定义
#define OB_RDP_LEVEL_0            ((uint8_t)0xA5)  // 读保护级别0（无保护）
#define OB_RDP_LEVEL_1            ((uint8_t)0x00)  // 读保护级别1（读保护使能）
/**
  * @}
  */
  
/** @defgroup FLASHEx_OB_IWatchdog Option Byte IWatchdog
  * @brief 选项字节独立看门狗配置
  * @{
  */ 
// 独立看门狗硬件/软件选择
#define OB_IWDG_SW                ((uint16_t)0x0001)  /*!< 软件独立看门狗被选中 */
#define OB_IWDG_HW                ((uint16_t)0x0000)  /*!< 硬件独立看门狗被选中 */
/**
  * @}
  */

/** @defgroup FLASHEx_OB_nRST_STOP Option Byte nRST STOP
  * @brief 选项字节停机模式复位配置
  * @{
  */ 
// 进入停机模式时的复位行为
#define OB_STOP_NO_RST            ((uint16_t)0x0002) /*!< 进入停机模式时不产生复位 */
#define OB_STOP_RST               ((uint16_t)0x0000) /*!< 进入停机模式时产生复位 */
/**
  * @}
  */ 

/** @defgroup FLASHEx_OB_nRST_STDBY Option Byte nRST STDBY
  * @brief 选项字节待机模式复位配置
  * @{
  */ 
// 进入待机模式时的复位行为
#define OB_STDBY_NO_RST           ((uint16_t)0x0004) /*!< 进入待机模式时不产生复位 */
#define OB_STDBY_RST              ((uint16_t)0x0000) /*!< 进入待机模式时产生复位 */
/**
  * @}
  */

#if defined(FLASH_BANK2_END)
/** @defgroup FLASHEx_OB_BOOT1 Option Byte BOOT1
  * @brief 选项字节BOOT1配置
  * @{
  */
// BOOT1引脚配置
#define OB_BOOT1_RESET            ((uint16_t)0x0000) /*!< BOOT1 复位 */
#define OB_BOOT1_SET              ((uint16_t)0x0008) /*!< BOOT1 置位 */
/**
  * @}
  */
#endif /* FLASH_BANK2_END */

/** @defgroup FLASHEx_OB_Data_Address  Option Byte Data Address
  * @brief 选项字节数据地址
  * @{
  */
// 用户数据存储地址
#define OB_DATA_ADDRESS_DATA0     0x1FFFF804U  // 数据0的地址
#define OB_DATA_ADDRESS_DATA1     0x1FFFF806U  // 数据1的地址
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
  * @brief 标志位定义
  * @{
  */
#if defined(FLASH_BANK2_END)
// 针对双Bank Flash的标志位定义
 #define FLASH_FLAG_BSY             FLASH_FLAG_BSY_BANK1       /*!< FLASH Bank1 忙标志                   */ 
 #define FLASH_FLAG_PGERR           FLASH_FLAG_PGERR_BANK1     /*!< FLASH Bank1 编程错误标志      */
 #define FLASH_FLAG_WRPERR          FLASH_FLAG_WRPERR_BANK1    /*!< FLASH Bank1 写保护错误标志  */
 #define FLASH_FLAG_EOP             FLASH_FLAG_EOP_BANK1       /*!< FLASH Bank1 操作结束标志       */

 #define FLASH_FLAG_BSY_BANK1       FLASH_SR_BSY               /*!< FLASH Bank1 忙标志                   */ 
 #define FLASH_FLAG_PGERR_BANK1     FLASH_SR_PGERR             /*!< FLASH Bank1 编程错误标志      */
 #define FLASH_FLAG_WRPERR_BANK1    FLASH_SR_WRPRTERR          /*!< FLASH Bank1 写保护错误标志  */
 #define FLASH_FLAG_EOP_BANK1       FLASH_SR_EOP               /*!< FLASH Bank1 操作结束标志       */
       
 #define FLASH_FLAG_BSY_BANK2       (FLASH_SR2_BSY << 16U)      /*!< FLASH Bank2 忙标志                   */ 
 #define FLASH_FLAG_PGERR_BANK2     (FLASH_SR2_PGERR << 16U)    /*!< FLASH Bank2 编程错误标志      */
 #define FLASH_FLAG_WRPERR_BANK2    (FLASH_SR2_WRPRTERR << 16U) /*!< FLASH Bank2 写保护错误标志  */
 #define FLASH_FLAG_EOP_BANK2       (FLASH_SR2_EOP << 16U)      /*!< FLASH Bank2 操作结束标志       */

#else  

// 针对单Bank Flash的标志位定义
 #define FLASH_FLAG_BSY             FLASH_SR_BSY              /*!< FLASH 忙标志                          */ 
 #define FLASH_FLAG_PGERR           FLASH_SR_PGERR            /*!< FLASH 编程错误标志             */
 #define FLASH_FLAG_WRPERR          FLASH_SR_WRPRTERR         /*!< FLASH 写保护错误标志         */
 #define FLASH_FLAG_EOP             FLASH_SR_EOP              /*!< FLASH 操作结束标志              */

#endif
 // 选项字节错误标志
 #define FLASH_FLAG_OPTVERR         ((OBR_REG_INDEX << 8U | FLASH_OBR_OPTERR)) /*!< 选项字节错误        */
/**
  * @}
  */
  
/** @defgroup FLASH_Interrupt_definition Interrupt definition
  * @brief FLASH 中断定义
  * @{
  */
#if defined(FLASH_BANK2_END)
// 针对双Bank Flash的中断定义
 #define FLASH_IT_EOP               FLASH_IT_EOP_BANK1        /*!< Bank1 FLASH操作结束中断源 */
 #define FLASH_IT_ERR               FLASH_IT_ERR_BANK1        /*!< Bank1 错误中断源                  */

 #define FLASH_IT_EOP_BANK1         FLASH_CR_EOPIE            /*!< Bank1 FLASH操作结束中断源 */
 #define FLASH_IT_ERR_BANK1         FLASH_CR_ERRIE            /*!< Bank1 错误中断源                  */

 #define FLASH_IT_EOP_BANK2         (FLASH_CR2_EOPIE << 16U)   /*!< Bank2 FLASH操作结束中断源 */
 #define FLASH_IT_ERR_BANK2         (FLASH_CR2_ERRIE << 16U)   /*!< Bank2 错误中断源                  */

#else

// 针对单Bank Flash的中断定义
 #define FLASH_IT_EOP               FLASH_CR_EOPIE          /*!< FLASH操作结束中断源 */
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

/* Exported macro ------------------------------------------------------------*/
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
  * @param  __INTERRUPT__  FLASH 中断 
  *     该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP_BANK1 Bank1 FLASH操作结束中断
  *     @arg @ref FLASH_IT_ERR_BANK1 Bank1 错误中断
  *     @arg @ref FLASH_IT_EOP_BANK2 Bank2 FLASH操作结束中断
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
  * @param  __INTERRUPT__  FLASH 中断 
  *     该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP_BANK1 Bank1 FLASH操作结束中断
  *     @arg @ref FLASH_IT_ERR_BANK1 Bank1 错误中断
  *     @arg @ref FLASH_IT_EOP_BANK2 Bank2 FLASH操作结束中断
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
  * @brief  获取指定的 FLASH 标志状态。 
  * @param  __FLAG__ 指定要检查的 FLASH 标志。
  *          该参数可以是以下值之一:
  *            @arg @ref FLASH_FLAG_EOP_BANK1    Bank1 FLASH操作结束标志
  *            @arg @ref FLASH_FLAG_WRPERR_BANK1 Bank1 FLASH写保护错误标志
  *            @arg @ref FLASH_FLAG_PGERR_BANK1  Bank1 FLASH编程错误标志
  *            @arg @ref FLASH_FLAG_BSY_BANK1    Bank1 FLASH忙标志
  *            @arg @ref FLASH_FLAG_EOP_BANK2    Bank2 FLASH操作结束标志
  *            @arg @ref FLASH_FLAG_WRPERR_BANK2 Bank2 FLASH写保护错误标志
  *            @arg @ref FLASH_FLAG_PGERR_BANK2  Bank2 FLASH编程错误标志
  *            @arg @ref FLASH_FLAG_BSY_BANK2    Bank2 FLASH忙标志
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval __FLAG__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__) (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                        ((((__FLAG__) & SR_FLAG_MASK) != RESET)? \
                                            (FLASH->SR & ((__FLAG__) & SR_FLAG_MASK)) : \
                                            (FLASH->SR2 & ((__FLAG__) >> 16U))))

/**
  * @brief  清除指定的 FLASH 标志。
  * @param  __FLAG__ 指定要清除的 FLASH 标志。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref FLASH_FLAG_EOP_BANK1    Bank1 FLASH操作结束标志
  *            @arg @ref FLASH_FLAG_WRPERR_BANK1 Bank1 FLASH写保护错误标志
  *            @arg @ref FLASH_FLAG_PGERR_BANK1  Bank1 FLASH编程错误标志
  *            @arg @ref FLASH_FLAG_BSY_BANK1    Bank1 FLASH忙标志
  *            @arg @ref FLASH_FLAG_EOP_BANK2    Bank2 FLASH操作结束标志
  *            @arg @ref FLASH_FLAG_WRPERR_BANK2 Bank2 FLASH写保护错误标志
  *            @arg @ref FLASH_FLAG_PGERR_BANK2  Bank2 FLASH编程错误标志
  *            @arg @ref FLASH_FLAG_BSY_BANK2    Bank2 FLASH忙标志
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval 无
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)  do { \
                          /* 清除 FLASH_FLAG_OPTVERR 标志 */ \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                          /* 清除 Bank1 标志 */ \
                          if (((__FLAG__) & SR_FLAG_MASK) != RESET) \
                          { \
                            FLASH->SR  = ((__FLAG__) & SR_FLAG_MASK); \
                          } \
                          /* 清除 Bank2 标志 */ \
                          if (((__FLAG__) >> 16U) != RESET) \
                          { \
                            FLASH->SR2 = ((__FLAG__) >> 16U); \
                          } \
                          } \
                    } while(0U)
#else
/**
  * @brief  使能指定的 FLASH 中断。
  * @param  __INTERRUPT__  FLASH 中断 
  *         该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP FLASH操作结束中断
  *     @arg @ref FLASH_IT_ERR 错误中断    
  * @retval 无
  */ 
#define __HAL_FLASH_ENABLE_IT(__INTERRUPT__)  (FLASH->CR |= (__INTERRUPT__))

/**
  * @brief  禁止指定的 FLASH 中断。
  * @param  __INTERRUPT__  FLASH 中断 
  *         该参数可以是以下值的任意组合:
  *     @arg @ref FLASH_IT_EOP FLASH操作结束中断
  *     @arg @ref FLASH_IT_ERR 错误中断    
  * @retval 无
  */ 
#define __HAL_FLASH_DISABLE_IT(__INTERRUPT__)   (FLASH->CR &= ~(__INTERRUPT__))

/**
  * @brief  获取指定的 FLASH 标志状态。 
  * @param  __FLAG__ 指定要检查的 FLASH 标志。
  *          该参数可以是以下值之一:
  *            @arg @ref FLASH_FLAG_EOP    FLASH操作结束标志 
  *            @arg @ref FLASH_FLAG_WRPERR FLASH写保护错误标志 
  *            @arg @ref FLASH_FLAG_PGERR  FLASH编程错误标志
  *            @arg @ref FLASH_FLAG_BSY    FLASH忙标志
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval __FLAG__ 的新状态 (SET 或 RESET)。
  */
#define __HAL_FLASH_GET_FLAG(__FLAG__)  (((__FLAG__) == FLASH_FLAG_OPTVERR) ? \
                                            (FLASH->OBR & FLASH_OBR_OPTERR) : \
                                            (FLASH->SR & (__FLAG__)))
/**
  * @brief  清除指定的 FLASH 标志。
  * @param  __FLAG__ 指定要清除的 FLASH 标志。
  *          该参数可以是以下值的任意组合:
  *            @arg @ref FLASH_FLAG_EOP    FLASH操作结束标志 
  *            @arg @ref FLASH_FLAG_WRPERR FLASH写保护错误标志 
  *            @arg @ref FLASH_FLAG_PGERR  FLASH编程错误标志 
  *            @arg @ref FLASH_FLAG_OPTVERR  加载的选项字节与其补码不匹配
  * @retval 无
  */
#define __HAL_FLASH_CLEAR_FLAG(__FLAG__)   do { \
                          /* 清除 FLASH_FLAG_OPTVERR 标志 */ \
                          if ((__FLAG__) == FLASH_FLAG_OPTVERR) \
                          { \
                            CLEAR_BIT(FLASH->OBR, FLASH_OBR_OPTERR); \
                          } \
                          else { \
                            /* 清除 Bank1 标志 */ \
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
// 擦除函数，根据初始化结构体配置执行擦除操作
HAL_StatusTypeDef  HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
// 中断方式擦除函数
HAL_StatusTypeDef  HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);

/**
  * @}
  */

/** @addtogroup FLASHEx_Exported_Functions_Group2
  * @{
  */
/* Peripheral Control functions ***********************************************/
// 擦除选项字节
HAL_StatusTypeDef  HAL_FLASHEx_OBErase(void);
// 编程选项字节
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
// 获取选项字节配置
void               HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
// 获取选项字节数据
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
