/** @defgroup HAL_COMP_Aliased_Macros HAL COMP 别名宏，为遗留目的维护
  * @{
  */
#if defined(STM32F3) /* 条件编译：仅在STM32F3系列芯片中定义 */
#define COMP_START                                       __HAL_COMP_ENABLE /* 启动比较器的别名宏 */
#define COMP_STOP                                        __HAL_COMP_DISABLE /* 停止比较器的别名宏 */
#define COMP_LOCK                                        __HAL_COMP_LOCK /* 锁定比较器配置的别名宏 */