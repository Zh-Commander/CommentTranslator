/**
  * @brief  检查是否启用了0到31号线的中断线上升沿触发
  * @rmtoll RTSR        RTx           LL_EXTI_IsEnabledRisingTrig_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_EXTI_IsEnabledRisingTrig_0_31(uint32_t ExtiLine)
{
  /* 读取上升沿触发选择寄存器(RTSR)，判断指定的中断线是否被设置 */
  return (READ_BIT(EXTI->RTSR, ExtiLine) == (ExtiLine));
}


/**
  * @}
  */

/** @defgroup EXTI_LL_EF_Falling_Trigger_Management Falling_Trigger_Management
  * @{
  */

/**
  * @brief  使能ExtiLine 0到31号线的下降沿触发
  * @note 可配置的唤醒线是边沿触发的。在这些线路上不能产生毛刺。
  *       如果在向EXTI_FTSR寄存器写入操作期间，可配置中断线上发生了下降沿，
  *       则不会设置挂起位。可以为同一中断线设置上升沿和下降沿触发。
  *       在这种情况下，两者都会产生触发条件。
  * @rmtoll FTSR        FTx           LL_EXTI_EnableFallingTrig_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_EnableFallingTrig_0_31(uint32_t ExtiLine)
{
  /* 设置下降沿触发选择寄存器(FTSR)中对应的位，使能下降沿触发 */
  SET_BIT(EXTI->FTSR, ExtiLine);
}


/**
  * @brief  禁用ExtiLine 0到31号线的下降沿触发
  * @note 可配置的唤醒线是边沿触发的。在这些线路上不能产生毛刺。
  *       如果在向EXTI_FTSR寄存器写入操作期间，可配置中断线上发生了下降沿，
  *       则不会设置挂起位。可以为同一中断线设置上升沿和下降沿触发。
  *       在这种情况下，两者都会产生触发条件。
  * @rmtoll FTSR        FTx           LL_EXTI_DisableFallingTrig_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_DisableFallingTrig_0_31(uint32_t ExtiLine)
{
  /* 清除下降沿触发选择寄存器(FTSR)中对应的位，禁用下降沿触发 */
  CLEAR_BIT(EXTI->FTSR, ExtiLine);
}


/**
  * @brief  检查是否启用了0到31号线的中断线下降沿触发
  * @rmtoll FTSR        FTx           LL_EXTI_IsEnabledFallingTrig_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_EXTI_IsEnabledFallingTrig_0_31(uint32_t ExtiLine)
{
  /* 读取下降沿触发选择寄存器(FTSR)，判断指定的中断线是否被设置 */
  return (READ_BIT(EXTI->FTSR, ExtiLine) == (ExtiLine));
}


/**
  * @}
  */

/** @defgroup EXTI_LL_EF_Software_Interrupt_Management Software_Interrupt_Management
  * @{
  */

/**
  * @brief  为0到31号线产生软件中断事件
  * @note 如果在EXTI_IMR中使能了该线的中断，当该位为'0'时写入1，
  *       将在EXTI_PR中设置相应的挂起位，从而产生中断请求。
  *       该位通过清除EXTI_PR寄存器中的相应位来清除(通过向该位写入1)。
  * @rmtoll SWIER       SWIx          LL_EXTI_GenerateSWI_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_GenerateSWI_0_31(uint32_t ExtiLine)
{
  /* 设置软件中断事件寄存器(SWIER)中对应的位，触发软件中断 */
  SET_BIT(EXTI->SWIER, ExtiLine);
}


/**
  * @}
  */

/** @defgroup EXTI_LL_EF_Flag_Management Flag_Management
  * @{
  */

/**
  * @brief  检查0到31号线的ExtLine标志位是否被置位
  * @note 当选定的边沿事件到达中断线时，该位被置位。
  *       通过向该位写入1来清除该位。
  * @rmtoll PR          PIFx           LL_EXTI_IsActiveFlag_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 位状态 (1 或 0)。
  */
__STATIC_INLINE uint32_t LL_EXTI_IsActiveFlag_0_31(uint32_t ExtiLine)
{
  /* 读取挂起寄存器(PR)，判断指定的中断线是否有挂起标志 */
  return (READ_BIT(EXTI->PR, ExtiLine) == (ExtiLine));
}


/**
  * @brief  读取0到31号线的ExtLine组合标志
  * @note 当选定的边沿事件到达中断线时，该位被置位。
  *       通过向该位写入1来清除该位。
  * @rmtoll PR          PIFx           LL_EXTI_ReadFlag_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval @note 当选定的边沿事件到达中断线时，该位被置位
  */
__STATIC_INLINE uint32_t LL_EXTI_ReadFlag_0_31(uint32_t ExtiLine)
{
  /* 读取挂起寄存器(PR)的值，并返回指定中断线的状态 */
  return (uint32_t)(READ_BIT(EXTI->PR, ExtiLine));
}


/**
  * @brief  清除0到31号线的ExtLine标志
  * @note 当选定的边沿事件到达中断线时，该位被置位。
  *       通过向该位写入1来清除该位。
  * @rmtoll PR          PIFx           LL_EXTI_ClearFlag_0_31
  * @param  ExtiLine 该参数可以是以下值的组合:
  *         @arg @ref LL_EXTI_LINE_0
  *         @arg @ref LL_EXTI_LINE_1
  *         @arg @ref LL_EXTI_LINE_2
  *         @arg @ref LL_EXTI_LINE_3
  *         @arg @ref LL_EXTI_LINE_4
  *         @arg @ref LL_EXTI_LINE_5
  *         @arg @ref LL_EXTI_LINE_6
  *         @arg @ref LL_EXTI_LINE_7
  *         @arg @ref LL_EXTI_LINE_8
  *         @arg @ref LL_EXTI_LINE_9
  *         @arg @ref LL_EXTI_LINE_10
  *         @arg @ref LL_EXTI_LINE_11
  *         @arg @ref LL_EXTI_LINE_12
  *         @arg @ref LL_EXTI_LINE_13
  *         @arg @ref LL_EXTI_LINE_14
  *         @arg @ref LL_EXTI_LINE_15
  *         @arg @ref LL_EXTI_LINE_16
  *         @arg @ref LL_EXTI_LINE_18
  *         @arg @ref LL_EXTI_LINE_19
  * @note   请检查每个设备的线路映射以确认EXTI线的可用性
  * @retval 无
  */
__STATIC_INLINE void LL_EXTI_ClearFlag_0_31(uint32_t ExtiLine)
{
  /* 向挂起寄存器(PR)写入1，清除指定中断线的挂起标志 */
  WRITE_REG(EXTI->PR, ExtiLine);
}


/**
  * @}
  */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup EXTI_LL_EF_Init Initialization and de-initialization functions
  * @{
  */

uint32_t LL_EXTI_Init(LL_EXTI_InitTypeDef *EXTI_InitStruct);
uint32_t LL_EXTI_DeInit(void);
void LL_EXTI_StructInit(LL_EXTI_InitTypeDef *EXTI_InitStruct);


/**
  * @}
  */
#endif /* USE_FULL_LL_DRIVER */

/**
  * @}
  */

/**
  * @}
  */

#endif /* EXTI */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32F1xx_LL_EXTI_H */
