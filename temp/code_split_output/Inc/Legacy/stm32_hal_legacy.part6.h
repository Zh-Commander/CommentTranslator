/* 针对STM32F301x8, STM32F302x8, STM32F318xx, STM32F303x8, STM32F334x8, STM32F328xx 系列器件的配置 */
#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || defined(STM32F303x8) || \
    defined(STM32F334x8) || defined(STM32F328xx)

/* 使能比较器外部中断上升沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线，例如 COMP_EXTI_LINE_COMP2 */
/* 该宏根据传入的中断线，调用对应的具体函数来使能上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来禁能上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来使能下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来禁能下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来使能中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
/* 参数 __EXTILINE__: 比较器外部中断线 */
/* 该宏根据传入的中断线，调用对应的具体函数来禁能中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
/* 参数 __FLAG__: 比较器中断标志，对应具体的中断线 */
/* 返回值: 中断标志状态 (SET 或 RESET) */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
/* 参数 __FLAG__: 比较器中断标志，对应具体的中断线 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())
#endif

/* 针对STM32F302xE, STM32F302xC 系列器件的配置 */
#if defined(STM32F302xE) || defined(STM32F302xC)

/* 使能比较器外部中断上升沿触发 */
/* 支持 COMP1, COMP2, COMP4, COMP6 四个比较器的中断线 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())
#endif

/* 针对STM32F303xE, STM32F398xx, STM32F303xC, STM32F358xx 系列器件的配置 */
/* 这些系列拥有更多的比较器资源 (COMP1-COMP7) */
#if defined(STM32F303xE) || defined(STM32F398xx) || defined(STM32F303xC) || defined(STM32F358xx)

/* 使能比较器外部中断上升沿触发 */
/* 支持 COMP1 至 COMP7 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_CLEAR_FLAG())
#endif

/* 针对STM32F373xC, STM32F378xx 系列器件的配置 */
/* 这些系列仅支持 COMP1 和 COMP2 */
#if defined(STM32F373xC) ||defined(STM32F378xx)

/* 使能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())
#endif

/* 其他STM32系列的通用配置 (默认仅支持 COMP1 和 COMP2) */
#else
/* 使能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())

/* 禁能比较器外部中断上升沿触发 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())

/* 使能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())

/* 禁能比较器外部中断下降沿触发 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())

/* 使能比较器外部中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())

/* 禁能比较器外部中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())

/* 获取比较器外部中断标志 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())

/* 清除比较器外部中断标志 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())
#endif

/* 获取比较器对应的外部中断线宏定义 */
#define __HAL_COMP_GET_EXTI_LINE  COMP_GET_EXTI_LINE

/* 针对STM32L0和STM32L4系列的特定配置 */
#if defined(STM32L0) || defined(STM32L4)
/* 注意: 在这些STM32系列中，此宏的唯一参数是 COMP_FLAG_LOCK */
/*       此宏已被 __HAL_COMP_IS_LOCKED 取代，后者仅接受 HAL 句柄参数 */
/* 获取比较器标志状态 (用于检查锁定状态) */
/* 参数 __HANDLE__: COMP句柄指针 */
/* 参数 __FLAG__: 标志位，此处特指锁定标志 */
#define __HAL_COMP_GET_FLAG(__HANDLE__, __FLAG__)  (__HAL_COMP_IS_LOCKED(__HANDLE__))
#endif
/**
  * @}
  */
