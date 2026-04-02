/**
  ******************************************************************************
  * @file    stm32f1xx_hal_gpio.c
  * @author  MCD Application Team
  * @brief   GPIO HAL 模块驱动。
  *          本文件提供固件函数用于管理通用输入/输出 (GPIO) 外设的以下功能：
  *           + 初始化和反初始化函数
  *           + IO 操作函数
  *
  ******************************************************************************
  * @attention
  *
  * 版权所有 (c) 2016 STMicroelectronics。
  * 保留所有权利。
  *
  * 本软件根据在本软件组件根目录中的 LICENSE 文件中找到的条款进行许可。
  * 如果本软件未附带 LICENSE 文件，则按“原样”提供。
  *
  ******************************************************************************
  @verbatim
  ==============================================================================
                    ##### GPIO 外设特性 #####
  ==============================================================================
  [..]
  受数据手册中列出的每个 I/O 端口的特定硬件特性限制，通用 IO (GPIO) 端口的每个端口位都可以通过软件单独配置为多种模式：
  (+) 输入模式
  (+) 模拟模式
  (+) 输出模式
  (+) 复用功能模式
  (+) 外部中断/事件线

  [..]
  在复位期间和复位后，复用功能和外部中断线处于非活动状态，I/O 端口配置为浮空输入模式。

  [..]
  所有 GPIO 引脚都具有弱内部上拉和下拉电阻，可以激活或不激活。

  [..]
  在输出或复用模式下，每个 IO 可以配置为开漏或推挽类型，并且可以根据 VDD 值选择 IO 速度。

  [..]
  所有端口都具有外部中断/事件功能。要使用外部中断线，必须将端口配置为输入模式。所有可用的 GPIO 引脚都连接到从 EXTI0 到 EXTI15 的 16 条外部中断/事件线。

  [..]
  外部中断/事件控制器在互联型器件中包含多达 20 个边沿检测器，在其他器件中包含 19 个边沿检测器，用于产生事件/中断请求。
  每条输入线都可以独立配置以选择类型（事件或中断）和相应的触发事件（上升沿或下降沿或两者）。
  每条线也可以独立屏蔽。挂起寄存器维护中断请求的状态线。

                     ##### 如何使用本驱动 #####
  ==============================================================================
 [..]
   (#) 使用以下函数使能 GPIO APB2 时钟：__HAL_RCC_GPIOx_CLK_ENABLE()。

   (#) 使用 HAL_GPIO_Init() 配置 GPIO 引脚。
       (++) 使用 GPIO_InitTypeDef 结构体中的 "Mode" 成员配置 IO 模式
       (++) 使用 GPIO_InitTypeDef 结构体中的 "Pull" 成员激活上拉、下拉电阻
       (++) 如果选择输出或复用功能模式：速度通过 GPIO_InitTypeDef 结构体中的 "Speed" 成员配置
       (++) 当引脚用作 ADC 通道或 DAC 输出时需要模拟模式
       (++) 如果选择外部中断/事件，GPIO_InitTypeDef 结构体中的 "Mode" 成员选择类型（中断或事件）和相应的触发事件（上升沿或下降沿或两者）。

   (#) 如果选择外部中断/事件模式，使用 HAL_NVIC_SetPriority() 配置映射到 EXTI 线的 NVIC IRQ 优先级，并使用 HAL_NVIC_EnableIRQ() 使能它。

   (#) 要获取配置为输入模式的引脚电平，请使用 HAL_GPIO_ReadPin()。

   (#) 要设置/复位配置为输出模式的引脚电平，请使用 HAL_GPIO_WritePin()/HAL_GPIO_TogglePin()。

   (#) 要锁定引脚配置直到下次复位，请使用 HAL_GPIO_LockPin()。

   (#) 在复位期间和复位后，复用功能不活动，GPIO 引脚配置为浮空输入模式（JTAG 引脚除外）。

   (#) 当 LSE 振荡器关闭时，LSE 振荡器引脚 OSC32_IN 和 OSC32_OUT 可分别用作通用目的（PC14 和 PC15）。LSE 优先于 GPIO 功能。

   (#) 当 HSE 振荡器关闭时，HSE 振荡器引脚 OSC_IN/OSC_OUT 可分别用作通用目的 PD0 和 PD1。HSE 优先于 GPIO 功能。

  @endverbatim
  ******************************************************************************
  */

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @defgroup GPIO GPIO
  * @brief GPIO HAL 模块驱动
  * @{
  */

#ifdef HAL_GPIO_MODULE_ENABLED

/* 私有类型定义 -----------------------------------------------------------*/
/* 私有定义 ------------------------------------------------------------*/
/** @addtogroup GPIO_Private_Constants GPIO 私有常量
  * @{
  */
/* GPIO 模式定义掩码 */
#define GPIO_MODE             0x00000003u // 模式位掩码：用于提取基本的输入/输出模式
#define EXTI_MODE             0x10000000u // EXTI 模式掩码：用于判断是否配置为中断/事件模式
#define GPIO_MODE_IT          0x00010000u // 中断模式掩码
#define GPIO_MODE_EVT         0x00020000u // 事件模式掩码
#define RISING_EDGE           0x00100000u // 上升沿触发掩码
#define FALLING_EDGE          0x00200000u // 下降沿触发掩码
#define GPIO_OUTPUT_TYPE      0x00000010u // 输出类型掩码

#define GPIO_NUMBER           16u         // GPIO 引脚数量，用于移位操作

/* CRL 和 CRH 寄存器位操作的定义 */
/* STM32F1系列的GPIO配置通过CRL(低8位)和CRH(高8位)寄存器控制，每4位控制一个引脚(CNF[1:0], MODE[1:0]) */
#define  GPIO_CR_MODE_INPUT         0x00000000u /*!< 00: 输入模式 (复位状态)  */
#define  GPIO_CR_CNF_ANALOG         0x00000000u /*!< 00: 模拟模式  */
#define  GPIO_CR_CNF_INPUT_FLOATING 0x00000004u /*!< 01: 浮空输入 (复位状态)  */
#define  GPIO_CR_CNF_INPUT_PU_PD    0x00000008u /*!< 10: 上拉/下拉输入  */
#define  GPIO_CR_CNF_GP_OUTPUT_PP   0x00000000u /*!< 00: 通用推挽输出  */
#define  GPIO_CR_CNF_GP_OUTPUT_OD   0x00000004u /*!< 01: 通用开漏输出  */
#define  GPIO_CR_CNF_AF_OUTPUT_PP   0x00000008u /*!< 10: 复用功能推挽输出  */
#define  GPIO_CR_CNF_AF_OUTPUT_OD   0x0000000Cu /*!< 11: 复用功能开漏输出  */

/**
  * @}
  */
/* 私有宏 -------------------------------------------------------------*/
/* 私有变量 ---------------------------------------------------------*/
/* 私有函数原型 -----------------------------------------------*/
/* 私有函数 ---------------------------------------------------------*/
/* 导出函数 --------------------------------------------------------*/
/** @defgroup GPIO_Exported_Functions GPIO 导出函数
  * @{
  */

/** @defgroup GPIO_Exported_Functions_Group1 初始化和反初始化函数
 *  @brief    初始化和配置函数
 *
@verbatim
 ===============================================================================
              ##### 初始化和反初始化函数 #####
 ===============================================================================
  [..]
    本节提供允许初始化和反初始化 GPIO 的函数，使其准备好使用。

@endverbatim
  * @{
  */


/**
  * @brief  根据 GPIO_Init 中的指定参数初始化 GPIOx 外设。
  * @param  GPIOx: 其中 x 可以是 (A..G，取决于使用的器件) 以选择 GPIO 外设
  * @param  GPIO_Init: 指向 GPIO_InitTypeDef 结构体的指针，该结构体包含指定 GPIO 外设的配置信息。
  * @retval 无
  */
void HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
  uint32_t position = 0x00u;      // 当前引脚位置索引，用于遍历 Pin 字段
  uint32_t ioposition;            // 当前引脚的位置掩码 (如 0x0001, 0x0002...)
  uint32_t iocurrent;             // 当前引脚的值，用于确认是否配置该引脚
  uint32_t temp;                  // 临时变量，用于寄存器操作
  uint32_t config = 0x00u;        // 存储计算出的 CNF 和 MODE 配置值
  __IO uint32_t *configregister;  /* 存储基于引脚号的 CRL 或 CRH 寄存器地址 */
  uint32_t registeroffset;        /* 偏移量，用于计算 CNF 和 MODE 位在 CRL 或 CRH 寄存器中的位置 */

  /* 检查参数 */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Init->Pin));
  assert_param(IS_GPIO_MODE(GPIO_Init->Mode));

  /* 配置端口引脚 */
  /* 遍历 Pin 字段的每一位，直到所有位都处理完毕 */
  while (((GPIO_Init->Pin) >> position) != 0x00u)
  {
    /* 获取 IO 位置掩码，例如 position=0 时为 0x0001，position=1 时为 0x0002 */
    ioposition = (0x01uL << position);

    /* 获取当前 IO 位置值，判断 Pin 字段中是否包含当前引脚 */
    iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;

    /* 如果当前引脚需要配置 */
    if (iocurrent == ioposition)
    {
      /* 检查复用功能参数 */
      assert_param(IS_GPIO_AF_INSTANCE(GPIOx));

      /* 根据所需的模式，用 MODEy[1:0] 和 CNFy[3:2] 对应位填充 config 变量 */
      switch (GPIO_Init->Mode)
      {
        /* 如果我们正在将引脚配置为推挽输出模式 */
        case GPIO_MODE_OUTPUT_PP:
          /* 检查 GPIO 速度参数 */
          assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
          // 配置值 = 速度 + 通用推挽输出配置
          config = GPIO_Init->Speed + GPIO_CR_CNF_GP_OUTPUT_PP;
          break;

        /* 如果我们正在将引脚配置为开漏输出模式 */
        case GPIO_MODE_OUTPUT_OD:
          /* 检查 GPIO 速度参数 */
          assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
          // 配置值 = 速度 + 通用开漏输出配置
          config = GPIO_Init->Speed + GPIO_CR_CNF_GP_OUTPUT_OD;
          break;

        /* 如果我们正在将引脚配置为复用功能推挽模式 */
        case GPIO_MODE_AF_PP:
          /* 检查 GPIO 速度参数 */
          assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
          // 配置值 = 速度 + 复用推挽输出配置
          config = GPIO_Init->Speed + GPIO_CR_CNF_AF_OUTPUT_PP;
          break;

        /* 如果我们正在将引脚配置为复用功能开漏模式 */
        case GPIO_MODE_AF_OD:
          /* 检查 GPIO 速度参数 */
          assert_param(IS_GPIO_SPEED(GPIO_Init->Speed));
          // 配置值 = 速度 + 复用开漏输出配置
          config = GPIO_Init->Speed + GPIO_CR_CNF_AF_OUTPUT_OD;
          break;

        /* 如果我们正在将引脚配置为输入模式 (也适用于事件和中断模式) */
        case GPIO_MODE_INPUT:
        case GPIO_MODE_IT_RISING:
        case GPIO_MODE_IT_FALLING:
        case GPIO_MODE_IT_RISING_FALLING:
        case GPIO_MODE_EVT_RISING:
        case GPIO_MODE_EVT_FALLING:
        case GPIO_MODE_EVT_RISING_FALLING:
          /* 检查 GPIO 上下拉参数 */
          assert_param(IS_GPIO_PULL(GPIO_Init->Pull));
          if (GPIO_Init->Pull == GPIO_NOPULL)
          {
            // 无上下拉：配置为浮空输入
            config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_FLOATING;
          }
          else if (GPIO_Init->Pull == GPIO_PULLUP)
          {
            // 上拉输入：配置为上拉/下拉模式
            config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_PU_PD;

            /* 设置对应的 ODR 位以启用上拉电阻 */
            GPIOx->BSRR = ioposition;
          }
          else /* GPIO_PULLDOWN */
          {
            // 下拉输入：配置为上拉/下拉模式
            config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_PU_PD;

            /* 复位对应的 ODR 位以启用下拉电阻 */
            GPIOx->BRR = ioposition;
          }
          break;

        /* 如果我们正在将引脚配置为模拟输入模式 */
        case GPIO_MODE_ANALOG:
          // 模拟模式：配置为输入模式 + 模拟配置
          config = GPIO_CR_MODE_INPUT + GPIO_CR_CNF_ANALOG;
          break;

        /* 参数通过 assert_param 检查 */
        default:
          break;
      }

      /* 检查当前位属于引脚计数编号的前半部分还是后半部分，以寻址 CRH 或 CRL 寄存器 */
      /* Pin 0-7 对应 CRL，Pin 8-15 对应 CRH */
      configregister = (iocurrent < GPIO_PIN_8) ? &GPIOx->CRL     : &GPIOx->CRH;
      // 计算寄存器内的位偏移：Pin0-7 偏移为 position*4，Pin8-15 偏移为 (position-8)*4
      registeroffset = (iocurrent < GPIO_PIN_8) ? (position << 2u) : ((position - 8u) << 2u);

      /* 将引脚的新配置应用到寄存器 */
      /* 修改寄存器：先清除对应的 MODE 和 CNF 位，再设置新的配置值 */
      MODIFY_REG((*configregister), ((GPIO_CRL_MODE0 | GPIO_CRL_CNF0) << registeroffset), (config << registeroffset));

      /*--------------------- EXTI 模式配置 ------------------------*/
      /* 为当前 IO 配置外部中断或事件 */
      if ((GPIO_Init->Mode & EXTI_MODE) == EXTI_MODE)
      {
        /* 使能 AFIO 时钟 (用于 EXTI 配置) */
        __HAL_RCC_AFIO_CLK_ENABLE();
        // 读取当前的 AFIO_EXTICR 寄存器值
        temp = AFIO->EXTICR[position >> 2u];
        // 清除当前引脚对应的 EXTI 配置位
        CLEAR_BIT(temp, (0x0Fu) << (4u * (position & 0x03u)));
        // 设置当前引脚对应的 GPIO 端口到 EXTI 线
        SET_BIT(temp, (GPIO_GET_INDEX(GPIOx)) << (4u * (position & 0x03u)));
        // 写回 AFIO_EXTICR 寄存器
        AFIO->EXTICR[position >> 2u] = temp;


        /* 使能或禁用上升沿触发 */
        if ((GPIO_Init->Mode & RISING_EDGE) == RISING_EDGE)
        {
          SET_BIT(EXTI->RTSR, iocurrent);
        }
        else
        {
          CLEAR_BIT(EXTI->RTSR, iocurrent);
        }

        /* 使能或禁用下降沿触发 */
        if ((GPIO_Init->Mode & FALLING_EDGE) == FALLING_EDGE)
        {
          SET_BIT(EXTI->FTSR, iocurrent);
        }
        else
        {
          CLEAR_BIT(EXTI->FTSR, iocurrent);
        }

        /* 配置事件屏蔽 */
        if ((GPIO_Init->Mode & GPIO_MODE_EVT) == GPIO_MODE_EVT)
        {
          SET_BIT(EXTI->EMR, iocurrent);
        }
        else
        {
          CLEAR_BIT(EXTI->EMR, iocurrent);
        }

        /* 配置中断屏蔽 */
        if ((GPIO_Init->Mode & GPIO_MODE_IT) == GPIO_MODE_IT)
        {
          SET_BIT(EXTI->IMR, iocurrent);
        }
        else
        {
          CLEAR_BIT(EXTI->IMR, iocurrent);
        }
      }
    }

	position++;
  }
}

/**
  * @brief  将 GPIOx 外设寄存器反初始化为其默认复位值。
  * @param  GPIOx: 其中 x 可以是 (A..G，取决于使用的器件) 以选择 GPIO 外设
  * @param  GPIO_Pin: 指定要写入的端口位。
  *         此参数可以是 GPIO_PIN_x 之一，其中 x 可以是 (0..15)。
  * @retval 无
  */
void HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin)
{
  uint32_t position = 0x00u;
  uint32_t iocurrent;
  uint32_t tmp;
  __IO uint32_t *configregister; /* 存储基于引脚号的 CRL 或 CRH 寄存器地址 */
  uint32_t registeroffset;

  /* 检查参数 */
  assert_param(IS_GPIO_ALL_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  /* 配置端口引脚 */
  while ((GPIO_Pin >> position) != 0u)
  {
    /* 获取当前 io 位置 */
    iocurrent = (GPIO_Pin) & (1uL << position);

    if (iocurrent)
    {
      /*------------------------- EXTI 模式配置 --------------------*/
      /* 清除当前 IO 的外部中断或事件 */

      // 读取 AFIO 外部中断配置寄存器
      tmp = AFIO->EXTICR[position >> 2u];
      // 获取当前引脚配置的端口信息
      tmp &= 0x0FuL << (4u * (position & 0x03u));
      // 检查该 EXTI 线是否连接到了当前 GPIO 端口
      if (tmp == (GPIO_GET_INDEX(GPIOx) << (4u * (position & 0x03u))))
      {
        /* 清除 EXTI 线配置 */
        CLEAR_BIT(EXTI->IMR, (uint32_t)iocurrent); // 关闭中断请求
        CLEAR_BIT(EXTI->EMR, (uint32_t)iocurrent); // 关闭事件请求

        /* 清除上升沿和下降沿配置 */
        CLEAR_BIT(EXTI->FTSR, (uint32_t)iocurrent);
        CLEAR_BIT(EXTI->RTSR, (uint32_t)iocurrent);
        
        // 清除 AFIO 中的 EXTI 线路映射配置
        tmp = 0x0FuL << (4u * (position & 0x03u));
        CLEAR_BIT(AFIO->EXTICR[position >> 2u], tmp);
      }
      /*------------------------- GPIO 模式配置 --------------------*/
      /* 检查当前位属于引脚计数编号的前半部分还是后半部分，以寻址 CRH 或 CRL 寄存器 */
      configregister = (iocurrent < GPIO_PIN_8) ? &GPIOx->CRL     : &GPIOx->CRH;
      registeroffset = (iocurrent < GPIO_PIN_8) ? (position << 2u) : ((position - 8u) << 2u);

      /* CRL/CRH 默认值为浮空输入 (0x04) 移位到正确位置 */
      // GPIO_CRL_CNF0_0 代表 CNF0 位的位0，值为 0x04 (即 CNF=01, MODE=00)
      MODIFY_REG(*configregister, ((GPIO_CRL_MODE0 | GPIO_CRL_CNF0) << registeroffset), GPIO_CRL_CNF0_0 << registeroffset);

      /* ODR 默认值为 0 */
      CLEAR_BIT(GPIOx->ODR, iocurrent);
    }

    position++;
  }
}

/**
  * @}
  */

/** @defgroup GPIO_Exported_Functions_Group2 IO 操作函数
 *  @brief   GPIO 读写
 *
@verbatim
 ===============================================================================
                       ##### IO 操作函数 #####
 ===============================================================================
  [..]
    此小节提供一组允许管理 GPIO 的函数。

@endverbatim
  * @{
  */

/**
  * @brief  读取指定的输入端口引脚。
  * @param  GPIOx: 其中 x 可以是 (A..G，取决于使用的器件) 以选择 GPIO 外设
  * @param  GPIO_Pin: 指定要读取的端口位。
  *         此参数可以是 GPIO_PIN_x，其中 x 可以是 (0..15)。
  * @retval 输入端口引脚值。
  */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  GPIO_PinState bitstatus;

  /* 检查参数 */
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  /* 读取输入数据寄存器 (IDR) 并判断指定位是否为高电平 */
  if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)GPIO_PIN_RESET)
  {
    bitstatus = GPIO_PIN_SET; // 引脚为高电平
  }
  else
  {
    bitstatus = GPIO_PIN_RESET; // 引脚为低电平
  }
  return bitstatus;
}

/**
  * @brief  设置或清除选定的数据端口位。
  *
  * @note   此函数使用 GPIOx_BSRR 寄存器以允许原子读/修改访问。
  *         这样，就没有在读取和修改访问之间发生 IRQ(中断) 的风险。
  *
  * @param  GPIOx: 其中 x 可以是 (A..G，取决于使用的器件) 以选择 GPIO 外设
  * @param  GPIO_Pin: 指定要写入的端口位。
  *          此参数可以是 GPIO_PIN_x 之一，其中 x 可以是 (0..15)。
  * @param  PinState: 指定要写入选定位的值。
  *          此参数可以是 GPIO_PinState 枚举值之一：
  *            @arg GPIO_PIN_RESET: 清除端口引脚
  *            @arg GPIO_PIN_SET: 设置端口引脚
  * @retval 无
  */
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
  /* 检查参数 */
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_PIN_ACTION(PinState));

  if (PinState != GPIO_PIN_RESET)
  {
    // 写入 BSRR 低 16 位，设置对应引脚为高电平
    GPIOx->BSRR = GPIO_Pin;
  }
  else
  {
    // 写入 BSRR 高 16 位 (左移 16 位)，复位对应引脚为低电平
    GPIOx->BSRR = (uint32_t)GPIO_Pin << 16u;
  }
}

/**
  * @brief  翻转指定的 GPIO 引脚
  * @param  GPIOx: 其中 x 可以是 (A..G，取决于使用的器件) 以选择 GPIO 外设
  * @param  GPIO_Pin: 指定要翻转的引脚。
  * @retval 无
  */
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  uint32_t odr;

  /* 检查参数 */
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  /* 获取当前输出数据寄存器值 */
  odr = GPIOx->ODR;

  /* 设置选定的低电平引脚，复位选定的高电平引脚 */
  /* 逻辑：(ODR中为0的位 << 16) 置位 | (ODR中为1的位) 复位 */
  /* 结果：原来为0的位变为1，原来为1的位变为0 */
  GPIOx->BSRR = ((odr & GPIO_Pin) << GPIO_NUMBER) | (~odr & GPIO_Pin);
}

/**
* @brief  锁定 GPIO 引脚配置寄存器。
* @note   锁定机制允许冻结 IO 配置。当在端口位上应用了 LOCK 序列后，
*         直到下次复位之前，都无法修改端口位的值。
* @param  GPIOx: 其中 x 可以是 (A..G，取决于使用的器件) 以选择 GPIO 外设
* @param  GPIO_Pin: 指定要锁定的端口位。
*         此参数可以是 GPIO_PIN_x 的任意组合，其中 x 可以是 (0..15)。
* @retval 无
*/
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  __IO uint32_t tmp = GPIO_LCKR_LCKK; // 读取锁定键值，准备锁定序列

  /* 检查参数 */
  assert_param(IS_GPIO_LOCK_INSTANCE(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  /* 应用锁定键写入序列 */
  SET_BIT(tmp, GPIO_Pin);
  /* 设置 LCKx 位：LCKK='1' + LCK[15-0] */
  GPIOx->LCKR = tmp;
  /* 复位 LCKx 位：LCKK='0' + LCK[15-0] */
  GPIOx->LCKR = GPIO_Pin;
  /* 设置 LCKx 位：LCKK='1' + LCK[15-0] */
  GPIOx->LCKR = tmp;
  /* 读取 LCKK 寄存器。此读取是完成键锁定序列所必需的 */
  tmp = GPIOx->LCKR;

  /* 再次读取以确认锁定是否激活 */
  if ((uint32_t)(GPIOx->LCKR & GPIO_LCKR_LCKK))
  {
    return HAL_OK; // 锁定成功
  }
  else
  {
    return HAL_ERROR; // 锁定失败
  }
}

/**
  * @brief  此函数处理 EXTI 中断请求。
  * @param  GPIO_Pin: 指定连接 EXTI 线的引脚
  * @retval 无
  */
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin)
{
  /* EXTI 线中断检测 */
  if (__HAL_GPIO_EXTI_GET_IT(GPIO_Pin) != 0x00u)
  {
    __HAL_GPIO_EXTI_CLEAR_IT(GPIO_Pin); // 清除中断挂起位
    HAL_GPIO_EXTI_Callback(GPIO_Pin);   // 调用回调函数
  }
}

/**
  * @brief  EXTI 线检测回调函数。
  * @param  GPIO_Pin: 指定连接 EXTI 线的引脚
  * @retval 无
  */
__weak void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  /* 防止未使用的参数编译警告 */
  UNUSED(GPIO_Pin);
  /* 注意：不应修改此函数，当需要回调时，
           HAL_GPIO_EXTI_Callback 可以在用户文件中实现
   */
}

/**
  * @}
  */

/**
  * @}
  */

#endif /* HAL_GPIO_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

