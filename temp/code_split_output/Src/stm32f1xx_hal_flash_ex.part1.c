/**
  * @brief  使能（开启）指定页面的写保护功能
  * @note   在此函数中会自动执行选项字节擦除操作。
  * @note   当选择了内存读保护级别（RDP level = 1）时，
  *         如果连接了调试功能或在RAM中执行启动代码，则无法编程或擦除Flash页面i，
  *         即使nWRPi = 1也是如此。
  * 
  * @param  WriteProtectPage 指定要被写保护的页面。
  *         此参数的值取决于同一系列中使用的具体设备型号。
  * @retval HAL状态 (HAL_OK, HAL_ERROR, HAL_BUSY, HAL_TIMEOUT)
  */
static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量，初始化为OK
  uint16_t WRP0_Data = 0xFFFF;       // 定义WRP0数据变量，初始化为0xFFFF（全1表示无保护）
#if defined(FLASH_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFF;       // 如果定义了WRP1，则初始化WRP1数据
#endif /* FLASH_WRP1_WRP1 */
#if defined(FLASH_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFF;       // 如果定义了WRP2，则初始化WRP2数据
#endif /* FLASH_WRP2_WRP2 */
#if defined(FLASH_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFF;       // 如果定义了WRP3，则初始化WRP3数据
#endif /* FLASH_WRP3_WRP3 */
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_WRP(WriteProtectPage));
    
  /* 获取当前受写保护的页面，并计算新的需要保护的页面 ******/
  /* 逻辑解释：先获取当前保护状态，按位或上新的保护页，再取反。
     因为WRP寄存器中位为0表示保护，为1表示未保护。
     (~FLASH_OB_GetWRP()) 获取当前已保护的位(变为1)，
     | WriteProtectPage 加上新增的保护位，
     最后整体取反，使得需要保护的位置0，保持未保护的位置1 */
  WriteProtectPage = (uint32_t)(~((~FLASH_OB_GetWRP()) | WriteProtectPage));
  
#if defined(OB_WRP_PAGES0TO15MASK)
  // 提取低8位数据，对应0-15页的保护信息
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#elif defined(OB_WRP_PAGES0TO31MASK)
  // 提取低8位数据，对应0-31页的保护信息
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO31MASK);
#endif /* OB_WRP_PAGES0TO31MASK */
  
#if defined(OB_WRP_PAGES16TO31MASK)
  // 提取次低8位数据，对应16-31页，右移8位对齐
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#elif defined(OB_WRP_PAGES32TO63MASK)
  // 提取次低8位数据，对应32-63页，右移8位对齐
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO63MASK) >> 8U);
#endif /* OB_WRP_PAGES32TO63MASK */
 
#if defined(OB_WRP_PAGES64TO95MASK)
  // 提取次高8位数据，对应64-95页，右移16位对齐
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES64TO95MASK) >> 16U);
#endif /* OB_WRP_PAGES64TO95MASK */
#if defined(OB_WRP_PAGES32TO47MASK)
  // 提取次高8位数据，对应32-47页，右移16位对齐
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif /* OB_WRP_PAGES32TO47MASK */

#if defined(OB_WRP_PAGES96TO127MASK)
  // 提取高8位数据，对应96-127页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES96TO127MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO255MASK)
  // 提取高8位数据，对应48-255页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO511MASK)
  // 提取高8位数据，对应48-511页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO511MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO127MASK)
  // 提取高8位数据，对应48-127页，右移24位对齐
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U); 
#endif /* OB_WRP_PAGES96TO127MASK */
  
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 为了能够再次写入选项字节，需要执行选项字节擦除 */
    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)  
    {
      /* 使能选项字节编程操作 */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(FLASH_WRP0_WRP0)
      // 如果WRP0数据不是0xFF（即有页面需要保护），则进行编程
      if(WRP0_Data != 0xFFU)
      {
        // 写入WRP0寄存器，使用与运算（因为擦除后是全1，写入0生效）
        OB->WRP0 &= WRP0_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP0_WRP0 */

#if defined(FLASH_WRP1_WRP1)
      // 如果状态OK且WRP1数据有效，则编程WRP1
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 &= WRP1_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP1_WRP1 */

#if defined(FLASH_WRP2_WRP2)
      // 如果状态OK且WRP2数据有效，则编程WRP2
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 &= WRP2_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP2_WRP2 */

#if defined(FLASH_WRP3_WRP3)
      // 如果状态OK且WRP3数据有效，则编程WRP3
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 &= WRP3_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP3_WRP3 */

      /* 如果编程操作完成，禁用OPTPG位 */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  
  return status; // 返回操作状态
}

/**
  * @brief  失能（关闭）指定页面的写保护功能
  * @note   在此函数中会自动执行选项字节擦除操作。
  * @note   当选择了内存读保护级别（RDP level = 1）时，
  *         如果连接了调试功能或在RAM中执行启动代码，则无法编程或擦除Flash页面i，
  *         即使nWRPi = 1也是如此。
  * 
  * @param  WriteProtectPage 指定要解除写保护的页面。
  *         此参数的值取决于同一系列中使用的具体设备型号。
  * @retval HAL状态 (HAL_OK, HAL_ERROR, HAL_BUSY, HAL_TIMEOUT)
  */
static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量
  uint16_t WRP0_Data = 0xFFFF;       // 定义WRP0数据变量
#if defined(FLASH_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFF;       // 如果定义了WRP1，则初始化WRP1数据
#endif /* FLASH_WRP1_WRP1 */
#if defined(FLASH_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFF;       // 如果定义了WRP2，则初始化WRP2数据
#endif /* FLASH_WRP2_WRP2 */
#if defined(FLASH_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFF;       // 如果定义了WRP3，则初始化WRP3数据
#endif /* FLASH_WRP3_WRP3 */
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_WRP(WriteProtectPage));

  /* 获取当前受写保护的页面，并计算新的需要解除保护的页面 ******/
  /* 逻辑解释：解除保护意味着将对应位置1。
     FLASH_OB_GetWRP() 获取当前状态，
     | WriteProtectPage 将需要解除保护的位置1，
     结果即为新的保护状态（0为保护，1为未保护） */
  WriteProtectPage = (FLASH_OB_GetWRP() | WriteProtectPage);

#if defined(OB_WRP_PAGES0TO15MASK)
  // 提取低8位数据
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#elif defined(OB_WRP_PAGES0TO31MASK)
  // 提取低8位数据
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO31MASK);
#endif /* OB_WRP_PAGES0TO31MASK */
  
#if defined(OB_WRP_PAGES16TO31MASK)
  // 提取次低8位数据，右移8位
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#elif defined(OB_WRP_PAGES32TO63MASK)
  // 提取次低8位数据，右移8位
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO63MASK) >> 8U);
#endif /* OB_WRP_PAGES32TO63MASK */
 
#if defined(OB_WRP_PAGES64TO95MASK)
  // 提取次高8位数据，右移16位
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES64TO95MASK) >> 16U);
#endif /* OB_WRP_PAGES64TO95MASK */
#if defined(OB_WRP_PAGES32TO47MASK)
  // 提取次高8位数据，右移16位
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif /* OB_WRP_PAGES32TO47MASK */

#if defined(OB_WRP_PAGES96TO127MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES96TO127MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO255MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO511MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO511MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO127MASK)
  // 提取高8位数据，右移24位
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U); 
#endif /* OB_WRP_PAGES96TO127MASK */

    
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 为了能够再次写入选项字节，需要执行选项字节擦除 */
    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)  
    {
      /* 使能选项字节编程操作 */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(FLASH_WRP0_WRP0)
      // 如果WRP0数据不是0xFF（即有页面需要解除保护），则进行编程
      if(WRP0_Data != 0xFFU)
      {
        // 写入WRP0寄存器，使用或运算（将对应位置1以解除保护）
        OB->WRP0 |= WRP0_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP0_WRP0 */

#if defined(FLASH_WRP1_WRP1)
      // 如果状态OK且WRP1数据有效，则编程WRP1
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 |= WRP1_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP1_WRP1 */

#if defined(FLASH_WRP2_WRP2)
      // 如果状态OK且WRP2数据有效，则编程WRP2
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 |= WRP2_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP2_WRP2 */

#if defined(FLASH_WRP3_WRP3)
      // 如果状态OK且WRP3数据有效，则编程WRP3
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 |= WRP3_Data;
        
        /* 等待上次操作完成 */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP3_WRP3 */

      /* 如果编程操作完成，禁用OPTPG位 */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  return status; // 返回操作状态
}

/**
  * @brief  设置读保护级别。
  * @param  ReadProtectLevel 指定读保护级别。
  *         该参数可以是以下值之一：
  *            @arg @ref OB_RDP_LEVEL_0 无保护
  *            @arg @ref OB_RDP_LEVEL_1 内存读保护
  * @retval HAL状态
  */
static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_RDP_LEVEL(ReadProtectLevel));
  
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  { 
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;
    
    /* 如果上一步操作完成，开始擦除选项字节 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTER); // 使能选项字节擦除
    SET_BIT(FLASH->CR, FLASH_CR_STRT);  // 启动擦除操作

    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* 如果擦除操作完成，禁用OPTER位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTER);

    if(status == HAL_OK)
    {
      /* 使能选项字节编程操作 */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);
      
      // 写入新的RDP值到RDP寄存器
      WRITE_REG(OB->RDP, ReadProtectLevel);
      
      /* 等待上次操作完成 */
      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE); 
      
      /* 如果编程操作完成，禁用OPTPG位 */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  
  return status; // 返回操作状态
}

/**
  * @brief  编程FLASH用户选项字节。
  * @note   选项字节的编程应仅在擦除后执行（否则会发生PGERR错误）。
  * @param  UserConfig FLASH用户选项字节值：FLASH_OBR_IWDG_SW(Bit2),
  *         FLASH_OBR_nRST_STOP(Bit3),FLASH_OBR_nRST_STDBY(Bit4).
  *         对于STM32F101xG和STM32F103xG还有BFBF2(Bit5)。
  * @retval HAL状态
  */
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint8_t UserConfig)
{
  HAL_StatusTypeDef status = HAL_OK; // 定义状态变量

  /* 检查参数是否合法 */
  assert_param(IS_OB_IWDG_SOURCE((UserConfig&OB_IWDG_SW))); // 检查看门狗配置
  assert_param(IS_OB_STOP_SOURCE((UserConfig&OB_STOP_NO_RST))); // 检查停止模式复位配置
  assert_param(IS_OB_STDBY_SOURCE((UserConfig&OB_STDBY_NO_RST))); // 检查待机模式复位配置
#if defined(FLASH_BANK2_END)
  assert_param(IS_OB_BOOT1((UserConfig&OB_BOOT1_SET))); // 检查BOOT1配置（仅大容量双Bank设备）
#endif /* FLASH_BANK2_END */

  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {     
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 使能选项字节编程操作 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTPG); 
 
#if defined(FLASH_BANK2_END)
    // 对于双Bank设备，配置用户字节，高4位保留置1 (0xF0)
    OB->USER = (UserConfig | 0xF0U);
#else
    // 对于单Bank设备，配置用户字节，高5位保留置1 (0x88对应位操作，实际是设置保留位)
    OB->USER = (UserConfig | 0x88U);
#endif /* FLASH_BANK2_END */

    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* 如果编程操作完成，禁用OPTPG位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }
  
  return status; // 返回操作状态
}

/**
  * @brief  在指定的选项字节数据地址编程半字。
  * @note   在调用此函数前应调用 @ref HAL_FLASH_Unlock() 解锁FLASH接口
  *         在调用此函数前应调用 @ref HAL_FLASH_OB_Unlock() 解锁选项字节
  *         在调用此函数后应调用 @ref HAL_FLASH_OB_Launch() 强制重载选项字节
  *         （会发生系统复位）
  *         选项字节的编程应仅在擦除后执行（否则会发生PGERR错误）。
  * @param  Address 指定要编程的地址。
  *         此参数可以是 0x1FFFF804 或 0x1FFFF806（Data0和Data1）。
  * @param  Data 指定要编程的数据。
  * @retval HAL状态
  */
static HAL_StatusTypeDef FLASH_OB_ProgramData(uint32_t Address, uint8_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR; // 定义状态变量，初始化为ERROR
  
  /* 检查参数是否合法 */
  assert_param(IS_OB_DATA_ADDRESS(Address));
  
  /* 等待上次操作完成 */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    /* 清除错误标志 */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* 使能选项字节编程操作 */
    SET_BIT(FLASH->CR, FLASH_CR_OPTPG); 
    // 向指定地址写入数据（强制转换为16位指针访问）
    *(__IO uint16_t*)Address = Data;
    
    /* 等待上次操作完成 */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
    
    /* 如果编程操作完成，禁用OPTPG位 */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }
  /* 返回选项字节数据编程状态 */
  return status;
}

/**
  * @brief  返回FLASH写保护选项字节值。
  * @retval FLASH写保护选项字节值
  */
static uint32_t FLASH_OB_GetWRP(void)
{
  /* 返回FLASH写保护寄存器值 */
  return (uint32_t)(READ_REG(FLASH->WRPR));
}

/**
  * @brief  返回FLASH读保护级别。
  * @retval FLASH RDP级别
  *         该参数可以是以下值之一：
  *            @arg @ref OB_RDP_LEVEL_0 无保护
  *            @arg @ref OB_RDP_LEVEL_1 内存读保护
  */
static uint32_t FLASH_OB_GetRDP(void)
{
  uint32_t readstatus = OB_RDP_LEVEL_0; // 定义读状态变量，默认为Level 0
  uint32_t tmp_reg = 0U; // 定义临时寄存器变量
  
  /* 读取RDP级别位 */
  tmp_reg = READ_BIT(FLASH->OBR, FLASH_OBR_RDPRT);

  if (tmp_reg == FLASH_OBR_RDPRT)
  {
    readstatus = OB_RDP_LEVEL_1; // 如果标志位置位，则为Level 1
  }
  else 
  {
    readstatus = OB_RDP_LEVEL_0; // 否则为Level 0
  }

  return readstatus; // 返回读保护状态
}

/**
  * @brief  返回FLASH用户选项字节值。
  * @retval FLASH用户选项字节值：FLASH_OBR_IWDG_SW(Bit2),
  *         FLASH_OBR_nRST_STOP(Bit3),FLASH_OBR_nRST_STDBY(Bit4).
  *         对于STM32F101xG和STM32F103xG还有FLASH_OBR_BFB2(Bit5)。
  */
static uint8_t FLASH_OB_GetUser(void)
{
  /* 返回用户选项字节 */
  // 读取OBR寄存器，屏蔽出用户位，并右移到最低位
  return (uint8_t)((READ_REG(FLASH->OBR) & FLASH_OBR_USER) >> FLASH_POSITION_IWDGSW_BIT);
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FLASH
  * @{
  */

/** @addtogroup FLASH_Private_Functions
 * @{
 */

/**
  * @brief  擦除指定的FLASH内存页
  * @param  PageAddress 要擦除的FLASH页地址
  *         此参数的值取决于同一系列中使用的具体设备型号
  * 
  * @retval 无
  */
void FLASH_PageErase(uint32_t PageAddress)
{
  /* 清除错误标志 */
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

#if defined(FLASH_BANK2_END)
  // 如果定义了BANK2结束地址，说明是大容量双Bank设备
  if(PageAddress > FLASH_BANK1_END)
  { 
    /* 如果地址在BANK2范围内，执行BANK2页擦除 */
    SET_BIT(FLASH->CR2, FLASH_CR2_PER); // 设置BANK2页擦除标志
    WRITE_REG(FLASH->AR2, PageAddress); // 写入BANK2擦除地址
    SET_BIT(FLASH->CR2, FLASH_CR2_STRT); // 启动BANK2擦除
  }
  else
  {
#endif /* FLASH_BANK2_END */
    /* 执行BANK1页擦除 */
    SET_BIT(FLASH->CR, FLASH_CR_PER);  // 设置BANK1页擦除标志
    WRITE_REG(FLASH->AR, PageAddress); // 写入BANK1擦除地址
    SET_BIT(FLASH->CR, FLASH_CR_STRT); // 启动BANK1擦除
#if defined(FLASH_BANK2_END)
  }
#endif /* FLASH_BANK2_END */
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_FLASH_MODULE_ENABLED */
/**
  * @}
  */
