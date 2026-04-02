
/**
  * @brief  FLASH end of operation interrupt callback
  * @param  ReturnValue: The value saved in this parameter depends on the ongoing procedure
  *                 - Mass Erase: No return value expected
  *                 - Pages Erase: Address of the page which has been erased 
  *                    (if 0xFFFFFFFF, it means that all the selected pages have been erased)
  *                 - Program: Address which was selected for data program
  * @retval none
  */
__weak void HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(ReturnValue);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FLASH_EndOfOperationCallback could be implemented in the user file
   */ 
}

/**
  * @brief  FLASH operation error interrupt callback
  * @param  ReturnValue: The value saved in this parameter depends on the ongoing procedure
  *                 - Mass Erase: No return value expected
  *                 - Pages Erase: Address of the page which returned an error
  *                 - Program: Address which was selected for data program
  * @retval none
  */
__weak void HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(ReturnValue);

  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_FLASH_OperationErrorCallback could be implemented in the user file
   */ 
}

/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions_Group2 Peripheral Control functions 
 *  @brief   management functions 
 *
@verbatim   
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================  
    [..]
    This subsection provides a set of functions allowing to control the FLASH 
    memory operations.

@endverbatim
  * @{
  */

/**
  * @brief  Unlock the FLASH control register access
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Unlock(void)
{
  HAL_StatusTypeDef status = HAL_OK;

  if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
  {
    /* Authorize the FLASH Registers access */
    WRITE_REG(FLASH->KEYR, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR, FLASH_KEY2);

    /* Verify Flash is unlocked */
    if(READ_BIT(FLASH->CR, FLASH_CR_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }
#if defined(FLASH_BANK2_END)
  if(READ_BIT(FLASH->CR2, FLASH_CR2_LOCK) != RESET)
  {
    /* Authorize the FLASH BANK2 Registers access */
    WRITE_REG(FLASH->KEYR2, FLASH_KEY1);
    WRITE_REG(FLASH->KEYR2, FLASH_KEY2);
    
    /* Verify Flash BANK2 is unlocked */
    if(READ_BIT(FLASH->CR2, FLASH_CR2_LOCK) != RESET)
    {
      status = HAL_ERROR;
    }
  }
#endif /* FLASH_BANK2_END */

  return status;
}

/**
  * @brief  Locks the FLASH control register access
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_Lock(void)
{
  /* Set the LOCK Bit to lock the FLASH Registers access */
  SET_BIT(FLASH->CR, FLASH_CR_LOCK);
  
#if defined(FLASH_BANK2_END)
  /* Set the LOCK Bit to lock the FLASH BANK2 Registers access */
  SET_BIT(FLASH->CR2, FLASH_CR2_LOCK);

#endif /* FLASH_BANK2_END */
  return HAL_OK;  
}

/**
  * @brief  Unlock the FLASH Option Control Registers access.
  * @retval HAL Status
  */
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void)
{
  if (HAL_IS_BIT_CLR(FLASH->CR, FLASH_CR_OPTWRE))
  {
    /* Authorizes the Option Byte register programming */
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY1);
    WRITE_REG(FLASH->OPTKEYR, FLASH_OPTKEY2);
  }
  else
  {
    return HAL_ERROR;
  }  
  
  return HAL_OK;  
}

/**
  * @brief  Lock the FLASH Option Control Registers access.
  * @retval HAL Status 
  */
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void)
{
  /* Clear the OPTWRE Bit to lock the FLASH Option Byte Registers access */
  CLEAR_BIT(FLASH->CR, FLASH_CR_OPTWRE);
  
  return HAL_OK;  
}
  
/**
  * @brief  Launch the option byte loading.
  * @note   This function will reset automatically the MCU.
  * @retval None
  */
void HAL_FLASH_OB_Launch(void)
{
  /* Initiates a system reset request to launch the option byte loading */
  HAL_NVIC_SystemReset();
}

/**
  * @}
  */  

/** @defgroup FLASH_Exported_Functions_Group3 Peripheral errors functions 
 *  @brief    Peripheral errors functions 
 *
@verbatim   
 ===============================================================================
                      ##### Peripheral Errors functions #####
 ===============================================================================  
    [..]
    This subsection permit to get in run-time errors of  the FLASH peripheral.

@endverbatim
  * @{
  */

/**
  * @brief  Get the specific FLASH error flag.
  * @retval FLASH_ErrorCode The returned value can be:
  *            @ref FLASH_Error_Codes
  */
uint32_t HAL_FLASH_GetError(void)
{
   return pFlash.ErrorCode;
}

/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup FLASH_Private_Functions
 * @{
 */

/**
  * @brief  Program a half-word (16-bit) at a specified address.
  * @param  Address specify the address to be programmed.
  * @param  Data    specify the data to be programmed.
  * @retval None
  */
static void FLASH_Program_HalfWord(uint32_t Address, uint16_t Data)
{
  /* Clean the error context */
  pFlash.ErrorCode = HAL_FLASH_ERROR_NONE;
  
#if defined(FLASH_BANK2_END)
  if(Address <= FLASH_BANK1_END)
  {
#endif /* FLASH_BANK2_END */
    /* Proceed to program the new data */
    SET_BIT(FLASH->CR, FLASH_CR_PG);
#if defined(FLASH_BANK2_END)
  }
  else
  {
    /* Proceed to program the new data */
    SET_BIT(FLASH->CR2, FLASH_CR2_PG);
  }
#endif /* FLASH_BANK2_END */

  /* Write data in the address */
  *(__IO uint16_t*)Address = Data;
}

/**
  * @brief  Wait for a FLASH operation to complete.
  * @param  Timeout  maximum flash operation timeout
  * @retval HAL Status
  */
HAL_StatusTypeDef FLASH_WaitForLastOperation(uint32_t Timeout)
{
  /* Wait for the FLASH operation to complete by polling on BUSY flag to be reset.
     Even if the FLASH operation fails, the BUSY flag will be reset and an error
     flag will be set */
     
  uint32_t tickstart = HAL_GetTick();
     
  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY)) 
  { 
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    }
  }
  
  /* Check FLASH End of Operation flag  */
  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP))
  {
    /* Clear FLASH End of Operation pending bit */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP);
  }
  
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR)  || 
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_OPTVERR) || 
     __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
  {
    /*Save the error code*/
    FLASH_SetErrorCode();
    return HAL_ERROR;
  }

  /* There is no error flag set */
  return HAL_OK;
}

#if defined(FLASH_BANK2_END)
/**
  * @brief  Wait for a FLASH BANK2 operation to complete.
  * @param  Timeout maximum flash operation timeout
  * @retval HAL_StatusTypeDef HAL Status
  */
HAL_StatusTypeDef FLASH_WaitForLastOperationBank2(uint32_t Timeout)
{ 
  /* Wait for the FLASH BANK2 operation to complete by polling on BUSY flag to be reset.
     Even if the FLASH BANK2 operation fails, the BUSY flag will be reset and an error
     flag will be set */
     
  uint32_t tickstart = HAL_GetTick();
     
  while(__HAL_FLASH_GET_FLAG(FLASH_FLAG_BSY_BANK2)) 
  { 
    if (Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U) || ((HAL_GetTick()-tickstart) > Timeout))
      {
        return HAL_TIMEOUT;
      }
    }
  }
  
  /* Check FLASH End of Operation flag  */
  if (__HAL_FLASH_GET_FLAG(FLASH_FLAG_EOP_BANK2))
  {
    /* Clear FLASH End of Operation pending bit */
    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP_BANK2);
  }

  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2))
  {
    /*Save the error code*/
    FLASH_SetErrorCode();
    return HAL_ERROR;
  }

  /* If there is an error flag set */
  return HAL_OK;
  
}
#endif /* FLASH_BANK2_END */

/**
  * @brief  Set the specific FLASH error flag.
  * @retval None
  */
static void FLASH_SetErrorCode(void)
{
  uint32_t flags = 0U;
  
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR_BANK2))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_WRPERR))
#endif /* FLASH_BANK2_END */
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_WRP;
#if defined(FLASH_BANK2_END)
    flags |= FLASH_FLAG_WRPERR | FLASH_FLAG_WRPERR_BANK2;
#else
    flags |= FLASH_FLAG_WRPERR;
#endif /* FLASH_BANK2_END */
  }
#if defined(FLASH_BANK2_END)
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR) || __HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR_BANK2))
#else
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_PGERR))
#endif /* FLASH_BANK2_END */
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_PROG;
#if defined(FLASH_BANK2_END)
    flags |= FLASH_FLAG_PGERR | FLASH_FLAG_PGERR_BANK2;
#else
    flags |= FLASH_FLAG_PGERR;
#endif /* FLASH_BANK2_END */
  }
  if(__HAL_FLASH_GET_FLAG(FLASH_FLAG_OPTVERR))
  {
    pFlash.ErrorCode |= HAL_FLASH_ERROR_OPTV;
  __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_OPTVERR);
  }

  /* Clear FLASH error pending bits */
  __HAL_FLASH_CLEAR_FLAG(flags);
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

