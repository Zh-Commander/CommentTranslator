/**
  ******************************************************************************
  * @file    stm32f1xx_hal_i2c.h
  * @author  MCD Application Team
  * @brief   Header file of I2C HAL module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_HAL_I2C_H
#define __STM32F1xx_HAL_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup I2C_Exported_Types I2C Exported Types
  * @{
  */

/** @defgroup I2C_Configuration_Structure_definition I2C Configuration Structure definition
  * @brief  I2C Configuration Structure definition
  * @{
  */
typedef struct
{
  uint32_t ClockSpeed;       /*!< Specifies the clock frequency.
                                  This parameter must be set to a value lower than 400kHz */

  uint32_t DutyCycle;        /*!< Specifies the I2C fast mode duty cycle.
                                  This parameter can be a value of @ref I2C_duty_cycle_in_fast_mode */

  uint32_t OwnAddress1;      /*!< Specifies the first device own address.
                                  This parameter can be a 7-bit or 10-bit address. */

  uint32_t AddressingMode;   /*!< Specifies if 7-bit or 10-bit addressing mode is selected.
                                  This parameter can be a value of @ref I2C_addressing_mode */

  uint32_t DualAddressMode;  /*!< Specifies if dual addressing mode is selected.
                                  This parameter can be a value of @ref I2C_dual_addressing_mode */

  uint32_t OwnAddress2;      /*!< Specifies the second device own address if dual addressing mode is selected
                                  This parameter can be a 7-bit address. */

  uint32_t GeneralCallMode;  /*!< Specifies if general call mode is selected.
                                  This parameter can be a value of @ref I2C_general_call_addressing_mode */

  uint32_t NoStretchMode;    /*!< Specifies if nostretch mode is selected.
                                  This parameter can be a value of @ref I2C_nostretch_mode */

} I2C_InitTypeDef;

/**
  * @}
  */

/** @defgroup HAL_state_structure_definition HAL state structure definition
  * @brief  HAL State structure definition
  * @note  HAL I2C State value coding follow below described bitmap :
  *          b7-b6  Error information
  *             00 : No Error
  *             01 : Abort (Abort user request on going)
  *             10 : Timeout
  *             11 : Error
  *          b5     Peripheral initialization status
  *             0  : Reset (Peripheral not initialized)
  *             1  : Init done (Peripheral initialized and ready to use. HAL I2C Init function called)
  *          b4     (not used)
  *             x  : Should be set to 0
  *          b3
  *             0  : Ready or Busy (No Listen mode ongoing)
  *             1  : Listen (Peripheral in Address Listen Mode)
  *          b2     Intrinsic process state
  *             0  : Ready
  *             1  : Busy (Peripheral busy with some configuration or internal operations)
  *          b1     Rx state
  *             0  : Ready (no Rx operation ongoing)
  *             1  : Busy (Rx operation ongoing)
  *          b0     Tx state
  *             0  : Ready (no Tx operation ongoing)
  *             1  : Busy (Tx operation ongoing)
  * @{
  */
typedef enum
{
  HAL_I2C_STATE_RESET             = 0x00U,   /*!< Peripheral is not yet Initialized         */
  HAL_I2C_STATE_READY             = 0x20U,   /*!< Peripheral Initialized and ready for use  */
  HAL_I2C_STATE_BUSY              = 0x24U,   /*!< An internal process is ongoing            */
  HAL_I2C_STATE_BUSY_TX           = 0x21U,   /*!< Data Transmission process is ongoing      */
  HAL_I2C_STATE_BUSY_RX           = 0x22U,   /*!< Data Reception process is ongoing         */
  HAL_I2C_STATE_LISTEN            = 0x28U,   /*!< Address Listen Mode is ongoing            */
  HAL_I2C_STATE_BUSY_TX_LISTEN    = 0x29U,   /*!< Address Listen Mode and Data Transmission
                                                 process is ongoing                         */
  HAL_I2C_STATE_BUSY_RX_LISTEN    = 0x2AU,   /*!< Address Listen Mode and Data Reception
                                                 process is ongoing                         */
  HAL_I2C_STATE_ABORT             = 0x60U,   /*!< Abort user request ongoing                */
  HAL_I2C_STATE_TIMEOUT           = 0xA0U,   /*!< Timeout state                             */
  HAL_I2C_STATE_ERROR             = 0xE0U    /*!< Error                                     */

} HAL_I2C_StateTypeDef;

/**
  * @}
  */

/** @defgroup HAL_mode_structure_definition HAL mode structure definition
  * @brief  HAL Mode structure definition
  * @note  HAL I2C Mode value coding follow below described bitmap :\n
  *          b7     (not used)\n
  *             x  : Should be set to 0\n
  *          b6\n
  *             0  : None\n
  *             1  : Memory (HAL I2C communication is in Memory Mode)\n
  *          b5\n
  *             0  : None\n
  *             1  : Slave (HAL I2C communication is in Slave Mode)\n
  *          b4\n
  *             0  : None\n
  *             1  : Master (HAL I2C communication is in Master Mode)\n
  *          b3-b2-b1-b0  (not used)\n
  *             xxxx : Should be set to 0000
  * @{
  */
typedef enum
{
  HAL_I2C_MODE_NONE               = 0x00U,   /*!< No I2C communication on going             */
  HAL_I2C_MODE_MASTER             = 0x10U,   /*!< I2C communication is in Master Mode       */
  HAL_I2C_MODE_SLAVE              = 0x20U,   /*!< I2C communication is in Slave Mode        */
  HAL_I2C_MODE_MEM                = 0x40U    /*!< I2C communication is in Memory Mode       */

} HAL_I2C_ModeTypeDef;

/**
  * @}
  */

/** @defgroup I2C_Error_Code_definition I2C Error Code definition
  * @brief  I2C Error Code definition
  * @{
  */
#define HAL_I2C_ERROR_NONE              0x00000000U    /*!< No error              */
#define HAL_I2C_ERROR_BERR              0x00000001U    /*!< BERR error            */
#define HAL_I2C_ERROR_ARLO              0x00000002U    /*!< ARLO error            */
#define HAL_I2C_ERROR_AF                0x00000004U    /*!< AF error              */
#define HAL_I2C_ERROR_OVR               0x00000008U    /*!< OVR error             */
#define HAL_I2C_ERROR_DMA               0x00000010U    /*!< DMA transfer error    */
#define HAL_I2C_ERROR_TIMEOUT           0x00000020U    /*!< Timeout Error         */
#define HAL_I2C_ERROR_SIZE              0x00000040U    /*!< Size Management error */
#define HAL_I2C_ERROR_DMA_PARAM         0x00000080U    /*!< DMA Parameter Error   */
#define HAL_I2C_WRONG_START             0x00000200U    /*!< Wrong start Error     */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define HAL_I2C_ERROR_INVALID_CALLBACK  0x00000100U    /*!< Invalid Callback error */
#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/** @defgroup I2C_handle_Structure_definition I2C handle Structure definition
  * @brief  I2C handle Structure definition
  * @{
  */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
typedef struct __I2C_HandleTypeDef
#else
typedef struct
#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
{
  I2C_TypeDef                *Instance;      /*!< I2C registers base address               */

  I2C_InitTypeDef            Init;           /*!< I2C communication parameters             */

  uint8_t                    *pBuffPtr;      /*!< Pointer to I2C transfer buffer           */

  uint16_t                   XferSize;       /*!< I2C transfer size                        */

  __IO uint16_t              XferCount;      /*!< I2C transfer counter                     */

  __IO uint32_t              XferOptions;    /*!< I2C transfer options                     */

  __IO uint32_t              PreviousState;  /*!< I2C communication Previous state and mode
                                                  context for internal usage               */

  DMA_HandleTypeDef          *hdmatx;        /*!< I2C Tx DMA handle parameters             */

  DMA_HandleTypeDef          *hdmarx;        /*!< I2C Rx DMA handle parameters             */

  HAL_LockTypeDef            Lock;           /*!< I2C locking object                       */

  __IO HAL_I2C_StateTypeDef  State;          /*!< I2C communication state                  */

  __IO HAL_I2C_ModeTypeDef   Mode;           /*!< I2C communication mode                   */

  __IO uint32_t              ErrorCode;      /*!< I2C Error code                           */

  __IO uint32_t              Devaddress;     /*!< I2C Target device address                */

  __IO uint32_t              Memaddress;     /*!< I2C Target memory address                */

  __IO uint32_t              MemaddSize;     /*!< I2C Target memory address  size          */

  __IO uint32_t              EventCount;     /*!< I2C Event counter                        */


#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
  void (* MasterTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);           /*!< I2C Master Tx Transfer completed callback */
  void (* MasterRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);           /*!< I2C Master Rx Transfer completed callback */
  void (* SlaveTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);            /*!< I2C Slave Tx Transfer completed callback  */
  void (* SlaveRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);            /*!< I2C Slave Rx Transfer completed callback  */
  void (* ListenCpltCallback)(struct __I2C_HandleTypeDef *hi2c);             /*!< I2C Listen Complete callback              */
  void (* MemTxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Memory Tx Transfer completed callback */
  void (* MemRxCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Memory Rx Transfer completed callback */
  void (* ErrorCallback)(struct __I2C_HandleTypeDef *hi2c);                  /*!< I2C Error callback                        */
  void (* AbortCpltCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Abort callback                        */

  void (* AddrCallback)(struct __I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode);  /*!< I2C Slave Address Match callback */

  void (* MspInitCallback)(struct __I2C_HandleTypeDef *hi2c);                /*!< I2C Msp Init callback                     */
  void (* MspDeInitCallback)(struct __I2C_HandleTypeDef *hi2c);              /*!< I2C Msp DeInit callback                   */

#endif  /* USE_HAL_I2C_REGISTER_CALLBACKS */
} I2C_HandleTypeDef;

#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
/**
  * @brief  HAL I2C Callback ID enumeration definition
  */
typedef enum
{
  HAL_I2C_MASTER_TX_COMPLETE_CB_ID      = 0x00U,    /*!< I2C Master Tx Transfer completed callback ID  */
  HAL_I2C_MASTER_RX_COMPLETE_CB_ID      = 0x01U,    /*!< I2C Master Rx Transfer completed callback ID  */
  HAL_I2C_SLAVE_TX_COMPLETE_CB_ID       = 0x02U,    /*!< I2C Slave Tx Transfer completed callback ID   */
  HAL_I2C_SLAVE_RX_COMPLETE_CB_ID       = 0x03U,    /*!< I2C Slave Rx Transfer completed callback ID   */
  HAL_I2C_LISTEN_COMPLETE_CB_ID         = 0x04U,    /*!< I2C Listen Complete callback ID               */
  HAL_I2C_MEM_TX_COMPLETE_CB_ID         = 0x05U,    /*!< I2C Memory Tx Transfer callback ID            */
  HAL_I2C_MEM_RX_COMPLETE_CB_ID         = 0x06U,    /*!< I2C Memory Rx Transfer completed callback ID  */
  HAL_I2C_ERROR_CB_ID                   = 0x07U,    /*!< I2C Error callback ID                         */
  HAL_I2C_ABORT_CB_ID                   = 0x08U,    /*!< I2C Abort callback ID                         */

  HAL_I2C_MSPINIT_CB_ID                 = 0x09U,    /*!< I2C Msp Init callback ID                      */
  HAL_I2C_MSPDEINIT_CB_ID               = 0x0AU     /*!< I2C Msp DeInit callback ID                    */

} HAL_I2C_CallbackIDTypeDef;

/**
  * @brief  HAL I2C Callback pointer definition
  */
typedef  void (*pI2C_CallbackTypeDef)(I2C_HandleTypeDef *hi2c); /*!< pointer to an I2C callback function */
typedef  void (*pI2C_AddrCallbackTypeDef)(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode); /*!< pointer to an I2C Address Match callback function */

#endif /* USE_HAL_I2C_REGISTER_CALLBACKS */
/**
  * @}
  */

/**
  * @}
  */
/* Exported constants --------------------------------------------------------*/

/** @defgroup I2C_Exported_Constants I2C Exported Constants
  * @{
  */

/** @defgroup I2C_duty_cycle_in_fast_mode I2C duty cycle in fast mode
  * @{
  */
#define I2C_DUTYCYCLE_2                 0x00000000U
#define I2C_DUTYCYCLE_16_9              I2C_CCR_DUTY
/**
  * @}
  */

/** @defgroup I2C_addressing_mode I2C addressing mode
  * @{
  */
#define I2C_ADDRESSINGMODE_7BIT         0x00004000U
#define I2C_ADDRESSINGMODE_10BIT        (I2C_OAR1_ADDMODE | 0x00004000U)
/**
  * @}
  */

/** @defgroup I2C_dual_addressing_mode  I2C dual addressing mode
  * @{
  */
#define I2C_DUALADDRESS_DISABLE        0x00000000U
#define I2C_DUALADDRESS_ENABLE         I2C_OAR2_ENDUAL
/**
  * @}
  */

/** @defgroup I2C_general_call_addressing_mode I2C general call addressing mode
  * @{
  */
#define I2C_GENERALCALL_DISABLE        0x00000000U
#define I2C_GENERALCALL_ENABLE         I2C_CR1_ENGC
/**
  * @}
  */

/** @defgroup I2C_nostretch_mode I2C nostretch mode
  * @{
  */
#define I2C_NOSTRETCH_DISABLE          0x00000000U
#define I2C_NOSTRETCH_ENABLE           I2C_CR1_NOSTRETCH
/**
  * @}
  */

/** @defgroup I2C_Memory_Address_Size I2C Memory Address Size
  * @{
  */
#define I2C_MEMADD_SIZE_8BIT            0x00000001U
#define I2C_MEMADD_SIZE_16BIT           0x00000010U
/**
  * @}
  */

/** @defgroup I2C_XferDirection_definition I2C XferDirection definition
  * @{
  */
#define I2C_DIRECTION_RECEIVE           0x00000000U
#define I2C_DIRECTION_TRANSMIT          0x00000001U
/**
  * @}
  */

/** @defgroup I2C_XferOptions_definition I2C XferOptions definition
  * @{
  */
#define  I2C_FIRST_FRAME                0x00000001U
#define  I2C_FIRST_AND_NEXT_FRAME       0x00000002U
#define  I2C_NEXT_FRAME                 0x00000004U
#define  I2C_FIRST_AND_LAST_FRAME       0x00000008U
#define  I2C_LAST_FRAME_NO_STOP         0x00000010U
#define  I2C_LAST_FRAME                 0x00000020U

/* List of XferOptions in usage of :
 * 1- Restart condition in all use cases (direction change or not)
 */
#define  I2C_OTHER_FRAME                (0x00AA0000U)
#define  I2C_OTHER_AND_LAST_FRAME       (0xAA000000U)
/**
  * @}
  */

/** @defgroup I2C_Interrupt_configuration_definition I2C Interrupt configuration definition
  * @brief I2C Interrupt definition
  *        Elements values convention: 0xXXXXXXXX
  *           - XXXXXXXX  : Interrupt control mask
  * @{
  */
#define I2C_IT_BUF                      I2C_CR2_ITBUFEN
#define I2C_IT_EVT                      I2C_CR2_ITEVTEN
#define I2C_IT_ERR                      I2C_CR2_ITERREN
/**
  * @}
  */

/** @defgroup I2C_Flag_definition I2C Flag definition
  * @{
  */

#define I2C_FLAG_OVR                    0x00010800U
#define I2C_FLAG_AF                     0x00010400U
#define I2C_FLAG_ARLO                   0x00010200U
#define I2C_FLAG_BERR                   0x00010100U
#define I2C_FLAG_TXE                    0x00010080U
#define I2C_FLAG_RXNE                   0x00010040U
#define I2C_FLAG_STOPF                  0x00010010U
#define I2C_FLAG_ADD10                  0x00010008U
#define I2C_FLAG_BTF                    0x00010004U
#define I2C_FLAG_ADDR                   0x00010002U
#define I2C_FLAG_SB                     0x00010001U
#define I2C_FLAG_DUALF                  0x00100080U
#define I2C_FLAG_GENCALL                0x00100010U
#define I2C_FLAG_TRA                    0x00100004U
#define I2C_FLAG_BUSY                   0x00100002U
#define I2C_FLAG_MSL                    0x00100001U
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup I2C_Exported_Macros I2C Exported Macros
  * @{
  */

/** @brief Reset I2C handle state.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @retval None
  */
#if (USE_HAL_I2C_REGISTER_CALLBACKS == 1)
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                do{                                                   \
                                                                    (__HANDLE__)->State = HAL_I2C_STATE_RESET;       \
                                                                    (__HANDLE__)->MspInitCallback = NULL;            \
                                                                    (__HANDLE__)->MspDeInitCallback = NULL;          \
                                                                  } while(0)
#else
#define __HAL_I2C_RESET_HANDLE_STATE(__HANDLE__)                ((__HANDLE__)->State = HAL_I2C_STATE_RESET)
#endif

/** @brief  Enable or disable the specified I2C interrupts.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the interrupt source to enable or disable.
  *         This parameter can be one of the following values:
  *            @arg I2C_IT_BUF: Buffer interrupt enable
  *            @arg I2C_IT_EVT: Event interrupt enable
  *            @arg I2C_IT_ERR: Error interrupt enable
  * @retval None
  */
#define __HAL_I2C_ENABLE_IT(__HANDLE__, __INTERRUPT__)   SET_BIT((__HANDLE__)->Instance->CR2,(__INTERRUPT__))
#define __HAL_I2C_DISABLE_IT(__HANDLE__, __INTERRUPT__)  CLEAR_BIT((__HANDLE__)->Instance->CR2, (__INTERRUPT__))

/** @brief  Checks if the specified I2C interrupt source is enabled or disabled.
  * @param  __HANDLE__ specifies the I2C Handle.
  * @param  __INTERRUPT__ specifies the I2C interrupt source to check.
  *          This parameter can be one of the following values:
  *            @arg I2C_IT_BUF: Buffer interrupt enable
  *            @arg I2C_IT_EVT: Event interrupt enable
  *            @arg I2C_IT_ERR: Error interrupt enable
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_I2C_GET_IT_SOURCE(__HANDLE__, __INTERRUPT__) ((((__HANDLE__)->Instance->CR2 & (__INTERRUPT__)) == (__INTERRUPT__)) ? SET : RESET)
