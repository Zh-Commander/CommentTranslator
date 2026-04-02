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
