#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || defined(STM32F303x8) || \
    defined(STM32F334x8) || defined(STM32F328xx)
/* 针对特定STM32型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#if defined(STM32F302xE) || defined(STM32F302xC)
/* 针对STM32F302xE/F302xC型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#if defined(STM32F303xE) || defined(STM32F398xx) || defined(STM32F303xC) || defined(STM32F358xx)
/* 针对STM32F303xE/F398xx/F303xC/F358xx型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#if defined(STM32F373xC) ||defined(STM32F378xx)
/* 针对STM32F373xC/F378xx型号的比较器(COMP)外部中断(EXTI)配置宏 */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif
#else
/* 默认情况下的比较器(COMP)外部中断(EXTI)配置宏（针对其他STM32型号） */
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())  /* 使能指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())  /* 禁用指定COMP EXTI线的上升沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())  /* 使能指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())  /* 禁用指定COMP EXTI线的下降沿中断 */
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())  /* 使能指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())  /* 禁用指定COMP EXTI线的中断 */
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())  /* 获取指定COMP EXTI线的标志位状态 */
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())  /* 清除指定COMP EXTI线的标志位 */
#endif