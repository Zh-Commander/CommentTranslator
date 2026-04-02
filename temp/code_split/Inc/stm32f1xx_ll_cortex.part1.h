
/**
  * @brief  Configure and enable a region
  * @rmtoll MPU_RNR      REGION        LL_MPU_ConfigRegion\n
  *         MPU_RBAR     REGION        LL_MPU_ConfigRegion\n
  *         MPU_RBAR     ADDR          LL_MPU_ConfigRegion\n
  *         MPU_RASR     XN            LL_MPU_ConfigRegion\n
  *         MPU_RASR     AP            LL_MPU_ConfigRegion\n
  *         MPU_RASR     S             LL_MPU_ConfigRegion\n
  *         MPU_RASR     C             LL_MPU_ConfigRegion\n
  *         MPU_RASR     B             LL_MPU_ConfigRegion\n
  *         MPU_RASR     SIZE          LL_MPU_ConfigRegion
  * @param  Region This parameter can be one of the following values:
  *         @arg @ref LL_MPU_REGION_NUMBER0
  *         @arg @ref LL_MPU_REGION_NUMBER1
  *         @arg @ref LL_MPU_REGION_NUMBER2
  *         @arg @ref LL_MPU_REGION_NUMBER3
  *         @arg @ref LL_MPU_REGION_NUMBER4
  *         @arg @ref LL_MPU_REGION_NUMBER5
  *         @arg @ref LL_MPU_REGION_NUMBER6
  *         @arg @ref LL_MPU_REGION_NUMBER7
  * @param  Address Value of region base address
  * @param  SubRegionDisable Sub-region disable value between Min_Data = 0x00 and Max_Data = 0xFF
  * @param  Attributes This parameter can be a combination of the following values:
  *         @arg @ref LL_MPU_REGION_SIZE_32B or @ref LL_MPU_REGION_SIZE_64B or @ref LL_MPU_REGION_SIZE_128B or @ref LL_MPU_REGION_SIZE_256B or @ref LL_MPU_REGION_SIZE_512B
  *           or @ref LL_MPU_REGION_SIZE_1KB or @ref LL_MPU_REGION_SIZE_2KB or @ref LL_MPU_REGION_SIZE_4KB or @ref LL_MPU_REGION_SIZE_8KB or @ref LL_MPU_REGION_SIZE_16KB
  *           or @ref LL_MPU_REGION_SIZE_32KB or @ref LL_MPU_REGION_SIZE_64KB or @ref LL_MPU_REGION_SIZE_128KB or @ref LL_MPU_REGION_SIZE_256KB or @ref LL_MPU_REGION_SIZE_512KB
  *           or @ref LL_MPU_REGION_SIZE_1MB or @ref LL_MPU_REGION_SIZE_2MB or @ref LL_MPU_REGION_SIZE_4MB or @ref LL_MPU_REGION_SIZE_8MB or @ref LL_MPU_REGION_SIZE_16MB
  *           or @ref LL_MPU_REGION_SIZE_32MB or @ref LL_MPU_REGION_SIZE_64MB or @ref LL_MPU_REGION_SIZE_128MB or @ref LL_MPU_REGION_SIZE_256MB or @ref LL_MPU_REGION_SIZE_512MB
  *           or @ref LL_MPU_REGION_SIZE_1GB or @ref LL_MPU_REGION_SIZE_2GB or @ref LL_MPU_REGION_SIZE_4GB
  *         @arg @ref LL_MPU_REGION_NO_ACCESS or @ref LL_MPU_REGION_PRIV_RW or @ref LL_MPU_REGION_PRIV_RW_URO or @ref LL_MPU_REGION_FULL_ACCESS
  *           or @ref LL_MPU_REGION_PRIV_RO or @ref LL_MPU_REGION_PRIV_RO_URO
  *         @arg @ref LL_MPU_TEX_LEVEL0 or @ref LL_MPU_TEX_LEVEL1 or @ref LL_MPU_TEX_LEVEL2 or @ref LL_MPU_TEX_LEVEL4
  *         @arg @ref LL_MPU_INSTRUCTION_ACCESS_ENABLE or  @ref LL_MPU_INSTRUCTION_ACCESS_DISABLE
  *         @arg @ref LL_MPU_ACCESS_SHAREABLE or @ref LL_MPU_ACCESS_NOT_SHAREABLE
  *         @arg @ref LL_MPU_ACCESS_CACHEABLE or @ref LL_MPU_ACCESS_NOT_CACHEABLE
  *         @arg @ref LL_MPU_ACCESS_BUFFERABLE or @ref LL_MPU_ACCESS_NOT_BUFFERABLE
  * @retval None
  */
__STATIC_INLINE void LL_MPU_ConfigRegion(uint32_t Region, uint32_t SubRegionDisable, uint32_t Address, uint32_t Attributes)
{
  /* Set Region number */
  WRITE_REG(MPU->RNR, Region);
  /* Set base address */
  WRITE_REG(MPU->RBAR, (Address & 0xFFFFFFE0U));
  /* Configure MPU */
  WRITE_REG(MPU->RASR, (MPU_RASR_ENABLE_Msk | Attributes | (SubRegionDisable << MPU_RASR_SRD_Pos)));
}

/**
  * @brief  Disable a region
  * @rmtoll MPU_RNR      REGION        LL_MPU_DisableRegion\n
  *         MPU_RASR     ENABLE        LL_MPU_DisableRegion
  * @param  Region This parameter can be one of the following values:
  *         @arg @ref LL_MPU_REGION_NUMBER0
  *         @arg @ref LL_MPU_REGION_NUMBER1
  *         @arg @ref LL_MPU_REGION_NUMBER2
  *         @arg @ref LL_MPU_REGION_NUMBER3
  *         @arg @ref LL_MPU_REGION_NUMBER4
  *         @arg @ref LL_MPU_REGION_NUMBER5
  *         @arg @ref LL_MPU_REGION_NUMBER6
  *         @arg @ref LL_MPU_REGION_NUMBER7
  * @retval None
  */
__STATIC_INLINE void LL_MPU_DisableRegion(uint32_t Region)
{
  /* Set Region number */
  WRITE_REG(MPU->RNR, Region);
  /* Disable the MPU region */
  CLEAR_BIT(MPU->RASR, MPU_RASR_ENABLE_Msk);
}

/**
  * @}
  */

#endif /* __MPU_PRESENT */
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

#endif /* __STM32F1xx_LL_CORTEX_H */

