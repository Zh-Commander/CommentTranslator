#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* Tx FIFO full */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* Tx FIFO not empty */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* Tx FIFO write active */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* Tx FIFO read status: Idle */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* Tx FIFO read status: Read (transferring data to 
                                                                      the MAC transmitter) */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* Tx FIFO read status: Waiting for TxStatus from 
                                                                      MAC transmitter */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* Tx FIFO read status: Writing the received TxStatus
                                                                      or flushing the TxFIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC transmitter in pause */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC transmit frame controller: Idle */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC transmit frame controller: Waiting for Status 
                                                                   of previous frame or IFG/backoff period to be over */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC transmit frame controller: Generating and 
                                                             transmitting a Pause control frame (in full duplex mode) */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC transmit frame controller: Transferring input 
                                                                      frame for transmission */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII transmit engine active */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* Rx FIFO fill level: empty */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* Rx FIFO fill level: fill-level below flow-control 
                                                              de-activate threshold */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* Rx FIFO fill level: fill-level above flow-control 
                                                              activate threshold */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* Rx FIFO fill level: full */
#if defined(STM32F1)
#else
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* Rx FIFO read controller IDLE state */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* Rx FIFO read controller Reading frame data */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* Rx FIFO read controller Reading frame status 
                                                             (or time-stamp) */
#endif
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* Rx FIFO read controller Flushing the frame data and 
                                                              status */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* Rx FIFO write controller active */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC small FIFO read / write controllers not active */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC small FIFO read controller active */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC small FIFO write controller active */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC small FIFO read / write controllers active */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII receive protocol engine active */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* Transmit Packet Configuration structure definition */

/**
  * @}
  */

/** @defgroup HAL_DCMI_Aliased_Defines HAL DCMI Aliased Defines maintained for legacy purpose
  * @{
  */
#define HAL_DCMI_ERROR_OVF      HAL_DCMI_ERROR_OVR
#define DCMI_IT_OVF             DCMI_IT_OVR
#define DCMI_FLAG_OVFRI         DCMI_FLAG_OVRRI
#define DCMI_FLAG_OVFMI         DCMI_FLAG_OVRMI

#define HAL_DCMI_ConfigCROP     HAL_DCMI_ConfigCrop
#define HAL_DCMI_EnableCROP     HAL_DCMI_EnableCrop
#define HAL_DCMI_DisableCROP    HAL_DCMI_DisableCrop

/**
  * @}
  */

#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7)
/** @defgroup HAL_DMA2D_Aliased_Defines HAL DMA2D Aliased Defines maintained for legacy purpose
  * @{
  */
#define DMA2D_ARGB8888          DMA2D_OUTPUT_ARGB8888
#define DMA2D_RGB888            DMA2D_OUTPUT_RGB888
#define DMA2D_RGB565            DMA2D_OUTPUT_RGB565
#define DMA2D_ARGB1555          DMA2D_OUTPUT_ARGB1555
#define DMA2D_ARGB4444          DMA2D_OUTPUT_ARGB4444

#define CM_ARGB8888             DMA2D_INPUT_ARGB8888
#define CM_RGB888               DMA2D_INPUT_RGB888
#define CM_RGB565               DMA2D_INPUT_RGB565
#define CM_ARGB1555             DMA2D_INPUT_ARGB1555
#define CM_ARGB4444             DMA2D_INPUT_ARGB4444
#define CM_L8                   DMA2D_INPUT_L8
#define CM_AL44                 DMA2D_INPUT_AL44
#define CM_AL88                 DMA2D_INPUT_AL88
#define CM_L4                   DMA2D_INPUT_L4
#define CM_A8                   DMA2D_INPUT_A8
#define CM_A4                   DMA2D_INPUT_A4
/**
  * @}
  */
#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 */

#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7) || defined(STM32U5)
/** @defgroup DMA2D_Aliases DMA2D API Aliases
  * @{
  */
#define HAL_DMA2D_DisableCLUT       HAL_DMA2D_CLUTLoading_Abort    /*!< Aliased to HAL_DMA2D_CLUTLoading_Abort
                                                                        for compatibility with legacy code */
/**
  * @}
  */

#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 || STM32U5 */

/** @defgroup HAL_PPP_Aliased_Defines HAL PPP Aliased Defines maintained for legacy purpose
  * @{
  */

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup HAL_CRYP_Aliased_Functions HAL CRYP Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_CRYP_ComputationCpltCallback     HAL_CRYPEx_ComputationCpltCallback
/**
  * @}
  */

/** @defgroup HAL_DCACHE_Aliased_Functions HAL DCACHE Aliased Functions maintained for legacy purpose
  * @{
  */

#if defined(STM32U5)
#define HAL_DCACHE_CleanInvalidateByAddr     HAL_DCACHE_CleanInvalidByAddr
#define HAL_DCACHE_CleanInvalidateByAddr_IT  HAL_DCACHE_CleanInvalidByAddr_IT
#endif /* STM32U5 */

/**
  * @}
  */

#if !defined(STM32F2)
/** @defgroup HASH_alias HASH API alias
  * @{
  */
#define HAL_HASHEx_IRQHandler   HAL_HASH_IRQHandler  /*!< Redirection for compatibility with legacy code */
/**
  *
  * @}
  */
#endif /* STM32F2 */
/** @defgroup HAL_HASH_Aliased_Functions HAL HASH Aliased Functions maintained for legacy purpose
  * @{
  */
#define HAL_HASH_STATETypeDef        HAL_HASH_StateTypeDef
#define HAL_HASHPhaseTypeDef         HAL_HASH_PhaseTypeDef
#define HAL_HMAC_MD5_Finish          HAL_HASH_MD5_Finish
#define HAL_HMAC_SHA1_Finish         HAL_HASH_SHA1_Finish
#define HAL_HMAC_SHA224_Finish       HAL_HASH_SHA224_Finish
#define HAL_HMAC_SHA256_Finish       HAL_HASH_SHA256_Finish

/*HASH Algorithm Selection*/

#define HASH_AlgoSelection_SHA1      HASH_ALGOSELECTION_SHA1
#define HASH_AlgoSelection_SHA224    HASH_ALGOSELECTION_SHA224
#define HASH_AlgoSelection_SHA256    HASH_ALGOSELECTION_SHA256
#define HASH_AlgoSelection_MD5       HASH_ALGOSELECTION_MD5

#define HASH_AlgoMode_HASH         HASH_ALGOMODE_HASH
#define HASH_AlgoMode_HMAC         HASH_ALGOMODE_HMAC

#define HASH_HMACKeyType_ShortKey  HASH_HMAC_KEYTYPE_SHORTKEY
#define HASH_HMACKeyType_LongKey   HASH_HMAC_KEYTYPE_LONGKEY

#if defined(STM32L4) || defined(STM32L5) || defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)

#define HAL_HASH_MD5_Accumulate                HAL_HASH_MD5_Accmlt
#define HAL_HASH_MD5_Accumulate_End            HAL_HASH_MD5_Accmlt_End
#define HAL_HASH_MD5_Accumulate_IT             HAL_HASH_MD5_Accmlt_IT
#define HAL_HASH_MD5_Accumulate_End_IT         HAL_HASH_MD5_Accmlt_End_IT

#define HAL_HASH_SHA1_Accumulate               HAL_HASH_SHA1_Accmlt
#define HAL_HASH_SHA1_Accumulate_End           HAL_HASH_SHA1_Accmlt_End
#define HAL_HASH_SHA1_Accumulate_IT            HAL_HASH_SHA1_Accmlt_IT
#define HAL_HASH_SHA1_Accumulate_End_IT        HAL_HASH_SHA1_Accmlt_End_IT

#define HAL_HASHEx_SHA224_Accumulate           HAL_HASHEx_SHA224_Accmlt
#define HAL_HASHEx_SHA224_Accumulate_End       HAL_HASHEx_SHA224_Accmlt_End
#define HAL_HASHEx_SHA224_Accumulate_IT        HAL_HASHEx_SHA224_Accmlt_IT
#define HAL_HASHEx_SHA224_Accumulate_End_IT    HAL_HASHEx_SHA224_Accmlt_End_IT

#define HAL_HASHEx_SHA256_Accumulate           HAL_HASHEx_SHA256_Accmlt
#define HAL_HASHEx_SHA256_Accumulate_End       HAL_HASHEx_SHA256_Accmlt_End
#define HAL_HASHEx_SHA256_Accumulate_IT        HAL_HASHEx_SHA256_Accmlt_IT
#define HAL_HASHEx_SHA256_Accumulate_End_IT    HAL_HASHEx_SHA256_Accmlt_End_IT

#endif  /* STM32L4 || STM32L5 || STM32F2 || STM32F4 || STM32F7 || STM32H7 */
/**
  * @}
  */

