#if defined(STM32F301x8) || defined(STM32F302x8) || defined(STM32F318xx) || defined(STM32F303x8) || \
    defined(STM32F334x8) || defined(STM32F328xx)
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())
#endif
#if defined(STM32F302xE) || defined(STM32F302xC)
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_ENABLE_IT())
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP6_EXTI_DISABLE_IT())
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_GET_FLAG())
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP6_EXTI_CLEAR_FLAG())
#endif
#if defined(STM32F303xE) || defined(STM32F398xx) || defined(STM32F303xC) || defined(STM32F358xx)
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_RISING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_FALLING_EDGE() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_ENABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_ENABLE_IT())
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_DISABLE_IT() : \
                                                          ((__EXTILINE__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP7_EXTI_DISABLE_IT())
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_GET_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_GET_FLAG())
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP2) ? __HAL_COMP_COMP2_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP3) ? __HAL_COMP_COMP3_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP4) ? __HAL_COMP_COMP4_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP5) ? __HAL_COMP_COMP5_EXTI_CLEAR_FLAG() : \
                                                          ((__FLAG__)  == COMP_EXTI_LINE_COMP6) ? __HAL_COMP_COMP6_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP7_EXTI_CLEAR_FLAG())
#endif
#if defined(STM32F373xC) ||defined(STM32F378xx)
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())
#endif
#else
#define __HAL_COMP_EXTI_RISING_IT_ENABLE(__EXTILINE__)   (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_RISING_IT_DISABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_RISING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_RISING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_ENABLE(__EXTILINE__)  (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_FALLING_IT_DISABLE(__EXTILINE__) (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_FALLING_EDGE() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_FALLING_EDGE())
#define __HAL_COMP_EXTI_ENABLE_IT(__EXTILINE__)          (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_ENABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_ENABLE_IT())
#define __HAL_COMP_EXTI_DISABLE_IT(__EXTILINE__)         (((__EXTILINE__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_DISABLE_IT() : \
                                                          __HAL_COMP_COMP2_EXTI_DISABLE_IT())
#define __HAL_COMP_EXTI_GET_FLAG(__FLAG__)               (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_GET_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_GET_FLAG())
#define __HAL_COMP_EXTI_CLEAR_FLAG(__FLAG__)             (((__FLAG__)  == COMP_EXTI_LINE_COMP1) ? __HAL_COMP_COMP1_EXTI_CLEAR_FLAG() : \
                                                          __HAL_COMP_COMP2_EXTI_CLEAR_FLAG())
#endif

