
/**
  * @brief  Enable the write protection of the desired pages
  * @note   An option byte erase is done automatically in this function. 
  * @note   When the memory read protection level is selected (RDP level = 1), 
  *         it is not possible to program or erase the flash page i if
  *         debug features are connected or boot code is executed in RAM, even if nWRPi = 1 
  * 
  * @param  WriteProtectPage specifies the page(s) to be write protected.
  *         The value of this parameter depend on device used within the same series 
  * @retval HAL status 
  */
static HAL_StatusTypeDef FLASH_OB_EnableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint16_t WRP0_Data = 0xFFFF;
#if defined(FLASH_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFF;
#endif /* FLASH_WRP1_WRP1 */
#if defined(FLASH_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFF;
#endif /* FLASH_WRP2_WRP2 */
#if defined(FLASH_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFF;
#endif /* FLASH_WRP3_WRP3 */
  
  /* Check the parameters */
  assert_param(IS_OB_WRP(WriteProtectPage));
    
  /* Get current write protected pages and the new pages to be protected ******/
  WriteProtectPage = (uint32_t)(~((~FLASH_OB_GetWRP()) | WriteProtectPage));
  
#if defined(OB_WRP_PAGES0TO15MASK)
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#elif defined(OB_WRP_PAGES0TO31MASK)
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO31MASK);
#endif /* OB_WRP_PAGES0TO31MASK */
  
#if defined(OB_WRP_PAGES16TO31MASK)
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#elif defined(OB_WRP_PAGES32TO63MASK)
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO63MASK) >> 8U);
#endif /* OB_WRP_PAGES32TO63MASK */
 
#if defined(OB_WRP_PAGES64TO95MASK)
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES64TO95MASK) >> 16U);
#endif /* OB_WRP_PAGES64TO95MASK */
#if defined(OB_WRP_PAGES32TO47MASK)
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif /* OB_WRP_PAGES32TO47MASK */

#if defined(OB_WRP_PAGES96TO127MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES96TO127MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO255MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO511MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO511MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO127MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U); 
#endif /* OB_WRP_PAGES96TO127MASK */
  
  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    /* Clean the error context */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* To be able to write again option byte, need to perform a option byte erase */
    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)  
    {
      /* Enable write protection */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(FLASH_WRP0_WRP0)
      if(WRP0_Data != 0xFFU)
      {
        OB->WRP0 &= WRP0_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP0_WRP0 */

#if defined(FLASH_WRP1_WRP1)
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 &= WRP1_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP1_WRP1 */

#if defined(FLASH_WRP2_WRP2)
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 &= WRP2_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP2_WRP2 */

#if defined(FLASH_WRP3_WRP3)
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 &= WRP3_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP3_WRP3 */

      /* if the program operation is completed, disable the OPTPG Bit */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  
  return status;
}

/**
  * @brief  Disable the write protection of the desired pages
  * @note   An option byte erase is done automatically in this function. 
  * @note   When the memory read protection level is selected (RDP level = 1), 
  *         it is not possible to program or erase the flash page i if   
  *         debug features are connected or boot code is executed in RAM, even if nWRPi = 1 
  * 
  * @param  WriteProtectPage specifies the page(s) to be write unprotected.
  *         The value of this parameter depend on device used within the same series 
  * @retval HAL status 
  */
static HAL_StatusTypeDef FLASH_OB_DisableWRP(uint32_t WriteProtectPage)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint16_t WRP0_Data = 0xFFFF;
#if defined(FLASH_WRP1_WRP1)
  uint16_t WRP1_Data = 0xFFFF;
#endif /* FLASH_WRP1_WRP1 */
#if defined(FLASH_WRP2_WRP2)
  uint16_t WRP2_Data = 0xFFFF;
#endif /* FLASH_WRP2_WRP2 */
#if defined(FLASH_WRP3_WRP3)
  uint16_t WRP3_Data = 0xFFFF;
#endif /* FLASH_WRP3_WRP3 */
  
  /* Check the parameters */
  assert_param(IS_OB_WRP(WriteProtectPage));

  /* Get current write protected pages and the new pages to be unprotected ******/
  WriteProtectPage = (FLASH_OB_GetWRP() | WriteProtectPage);

#if defined(OB_WRP_PAGES0TO15MASK)
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO15MASK);
#elif defined(OB_WRP_PAGES0TO31MASK)
  WRP0_Data = (uint16_t)(WriteProtectPage & OB_WRP_PAGES0TO31MASK);
#endif /* OB_WRP_PAGES0TO31MASK */
  
#if defined(OB_WRP_PAGES16TO31MASK)
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES16TO31MASK) >> 8U);
#elif defined(OB_WRP_PAGES32TO63MASK)
  WRP1_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO63MASK) >> 8U);
#endif /* OB_WRP_PAGES32TO63MASK */
 
#if defined(OB_WRP_PAGES64TO95MASK)
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES64TO95MASK) >> 16U);
#endif /* OB_WRP_PAGES64TO95MASK */
#if defined(OB_WRP_PAGES32TO47MASK)
  WRP2_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES32TO47MASK) >> 16U);
#endif /* OB_WRP_PAGES32TO47MASK */

#if defined(OB_WRP_PAGES96TO127MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES96TO127MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO255MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO255MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO511MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO511MASK) >> 24U); 
#elif defined(OB_WRP_PAGES48TO127MASK)
  WRP3_Data = (uint16_t)((WriteProtectPage & OB_WRP_PAGES48TO127MASK) >> 24U); 
#endif /* OB_WRP_PAGES96TO127MASK */

    
  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

  if(status == HAL_OK)
  { 
    /* Clean the error context */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* To be able to write again option byte, need to perform a option byte erase */
    status = HAL_FLASHEx_OBErase();
    if (status == HAL_OK)  
    {
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);

#if defined(FLASH_WRP0_WRP0)
      if(WRP0_Data != 0xFFU)
      {
        OB->WRP0 |= WRP0_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP0_WRP0 */

#if defined(FLASH_WRP1_WRP1)
      if((status == HAL_OK) && (WRP1_Data != 0xFFU))
      {
        OB->WRP1 |= WRP1_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP1_WRP1 */

#if defined(FLASH_WRP2_WRP2)
      if((status == HAL_OK) && (WRP2_Data != 0xFFU))
      {
        OB->WRP2 |= WRP2_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP2_WRP2 */

#if defined(FLASH_WRP3_WRP3)
      if((status == HAL_OK) && (WRP3_Data != 0xFFU))
      {
        OB->WRP3 |= WRP3_Data;
        
        /* Wait for last operation to be completed */
        status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
      }
#endif /* FLASH_WRP3_WRP3 */

      /* if the program operation is completed, disable the OPTPG Bit */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  return status;
}

/**
  * @brief  Set the read protection level.
  * @param  ReadProtectLevel specifies the read protection level.
  *         This parameter can be one of the following values:
  *            @arg @ref OB_RDP_LEVEL_0 No protection
  *            @arg @ref OB_RDP_LEVEL_1 Read protection of the memory
  * @retval HAL status
  */
static HAL_StatusTypeDef FLASH_OB_RDP_LevelConfig(uint8_t ReadProtectLevel)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  /* Check the parameters */
  assert_param(IS_OB_RDP_LEVEL(ReadProtectLevel));
  
  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  { 
    /* Clean the error context */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;
    
    /* If the previous operation is completed, proceed to erase the option bytes */
    SET_BIT(FLASH->CR, FLASH_CR_OPTER);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* If the erase operation is completed, disable the OPTER Bit */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTER);

    if(status == HAL_OK)
    {
      /* Enable the Option Bytes Programming operation */
      SET_BIT(FLASH->CR, FLASH_CR_OPTPG);
      
      WRITE_REG(OB->RDP, ReadProtectLevel);
      
      /* Wait for last operation to be completed */
      status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE); 
      
      /* if the program operation is completed, disable the OPTPG Bit */
      CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
    }
  }
  
  return status;
}

/**
  * @brief  Program the FLASH User Option Byte.    
  * @note   Programming of the OB should be performed only after an erase (otherwise PGERR occurs)
  * @param  UserConfig The FLASH User Option Bytes values FLASH_OBR_IWDG_SW(Bit2), 
  *         FLASH_OBR_nRST_STOP(Bit3),FLASH_OBR_nRST_STDBY(Bit4).
  *         And BFBF2(Bit5) for STM32F101xG and STM32F103xG . 
  * @retval HAL status
  */
static HAL_StatusTypeDef FLASH_OB_UserConfig(uint8_t UserConfig)
{
  HAL_StatusTypeDef status = HAL_OK;

  /* Check the parameters */
  assert_param(IS_OB_IWDG_SOURCE((UserConfig&OB_IWDG_SW)));
  assert_param(IS_OB_STOP_SOURCE((UserConfig&OB_STOP_NO_RST)));
  assert_param(IS_OB_STDBY_SOURCE((UserConfig&OB_STDBY_NO_RST)));
#if defined(FLASH_BANK2_END)
  assert_param(IS_OB_BOOT1((UserConfig&OB_BOOT1_SET)));
#endif /* FLASH_BANK2_END */

  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {     
    /* Clean the error context */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* Enable the Option Bytes Programming operation */
    SET_BIT(FLASH->CR, FLASH_CR_OPTPG); 
 
#if defined(FLASH_BANK2_END)
    OB->USER = (UserConfig | 0xF0U);
#else
    OB->USER = (UserConfig | 0x88U);
#endif /* FLASH_BANK2_END */

    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);

    /* if the program operation is completed, disable the OPTPG Bit */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }
  
  return status; 
}

/**
  * @brief  Programs a half word at a specified Option Byte Data address.
  * @note   The function @ref HAL_FLASH_Unlock() should be called before to unlock the FLASH interface
  *         The function @ref HAL_FLASH_OB_Unlock() should be called before to unlock the options bytes
  *         The function @ref HAL_FLASH_OB_Launch() should be called after to force the reload of the options bytes 
  *         (system reset will occur)
  *         Programming of the OB should be performed only after an erase (otherwise PGERR occurs)
  * @param  Address specifies the address to be programmed.
  *         This parameter can be 0x1FFFF804 or 0x1FFFF806. 
  * @param  Data specifies the data to be programmed.
  * @retval HAL status
  */
static HAL_StatusTypeDef FLASH_OB_ProgramData(uint32_t Address, uint8_t Data)
{
  HAL_StatusTypeDef status = HAL_ERROR;
  
  /* Check the parameters */
  assert_param(IS_OB_DATA_ADDRESS(Address));
  
  /* Wait for last operation to be completed */
  status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
  
  if(status == HAL_OK)
  {
    /* Clean the error context */
    pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

    /* Enables the Option Bytes Programming operation */
    SET_BIT(FLASH->CR, FLASH_CR_OPTPG); 
    *(__IO uint16_t*)Address = Data;
    
    /* Wait for last operation to be completed */
    status = FLASH_WaitForLastOperation((uint32_t)FLASH_TIMEOUT_VALUE);
    
    /* If the program operation is completed, disable the OPTPG Bit */
    CLEAR_BIT(FLASH->CR, FLASH_CR_OPTPG);
  }
  /* Return the Option Byte Data Program Status */
  return status;
}

/**
  * @brief  Return the FLASH Write Protection Option Bytes value.
  * @retval The FLASH Write Protection Option Bytes value
  */
static uint32_t FLASH_OB_GetWRP(void)
{
  /* Return the FLASH write protection Register value */
  return (uint32_t)(READ_REG(FLASH->WRPR));
}

/**
  * @brief  Returns the FLASH Read Protection level.
  * @retval FLASH RDP level
  *         This parameter can be one of the following values:
  *            @arg @ref OB_RDP_LEVEL_0 No protection
  *            @arg @ref OB_RDP_LEVEL_1 Read protection of the memory
  */
static uint32_t FLASH_OB_GetRDP(void)
{
  uint32_t readstatus = OB_RDP_LEVEL_0;
  uint32_t tmp_reg = 0U;
  
  /* Read RDP level bits */
  tmp_reg = READ_BIT(FLASH->OBR, FLASH_OBR_RDPRT);

  if (tmp_reg == FLASH_OBR_RDPRT)
  {
    readstatus = OB_RDP_LEVEL_1;
  }
  else 
  {
    readstatus = OB_RDP_LEVEL_0;
  }

  return readstatus;
}

/**
  * @brief  Return the FLASH User Option Byte value.
  * @retval The FLASH User Option Bytes values: FLASH_OBR_IWDG_SW(Bit2), 
  *         FLASH_OBR_nRST_STOP(Bit3),FLASH_OBR_nRST_STDBY(Bit4).
  *         And FLASH_OBR_BFB2(Bit5) for STM32F101xG and STM32F103xG . 
  */
static uint8_t FLASH_OB_GetUser(void)
{
  /* Return the User Option Byte */
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
  * @brief  Erase the specified FLASH memory page
  * @param  PageAddress FLASH page to erase
  *         The value of this parameter depend on device used within the same series      
  * 
  * @retval None
  */
void FLASH_PageErase(uint32_t PageAddress)
{
  /* Clean the error context */
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;

#if defined(FLASH_BANK2_END)
  if(PageAddress > FLASH_BANK1_END)
  { 
    /* Proceed to erase the page */
    SET_BIT(FLASH->CR2, FLASH_CR2_PER);
    WRITE_REG(FLASH->AR2, PageAddress);
    SET_BIT(FLASH->CR2, FLASH_CR2_STRT);
  }
  else
  {
#endif /* FLASH_BANK2_END */
    /* Proceed to erase the page */
    SET_BIT(FLASH->CR, FLASH_CR_PER);
    WRITE_REG(FLASH->AR, PageAddress);
    SET_BIT(FLASH->CR, FLASH_CR_STRT);
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

