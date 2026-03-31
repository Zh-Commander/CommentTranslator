#define ETH_MAC_TXFIFO_FULL                           0x02000000U  /* Tx FIFO 满 */
#define ETH_MAC_TXFIFONOT_EMPTY                       0x01000000U  /* Tx FIFO 非空 */
#define ETH_MAC_TXFIFO_WRITE_ACTIVE                   0x00400000U  /* Tx FIFO 写操作活跃 */
#define ETH_MAC_TXFIFO_IDLE                           0x00000000U  /* Tx FIFO 读状态：空闲 */
#define ETH_MAC_TXFIFO_READ                           0x00100000U  /* Tx FIFO 读状态：读取（数据传输到 MAC 发送器） */
#define ETH_MAC_TXFIFO_WAITING                        0x00200000U  /* Tx FIFO 读状态：等待来自 MAC 发送器的 TxStatus */
#define ETH_MAC_TXFIFO_WRITING                        0x00300000U  /* Tx FIFO 读状态：写入接收到的 TxStatus 或清空 TxFIFO */
#define ETH_MAC_TRANSMISSION_PAUSE                    0x00080000U  /* MAC 发送器处于暂停状态 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_IDLE          0x00000000U  /* MAC 发送帧控制器：空闲 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_WAITING       0x00020000U  /* MAC 发送帧控制器：等待上一帧状态或 IFG/退避期结束 */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_GENRATING_PCF 0x00040000U  /* MAC 发送帧控制器：生成并发送暂停控制帧（全双工模式） */
#define ETH_MAC_TRANSMITFRAMECONTROLLER_TRANSFERRING  0x00060000U  /* MAC 发送帧控制器：传输输入帧以进行发送 */
#define ETH_MAC_MII_TRANSMIT_ACTIVE           0x00010000U  /* MAC MII 发送引擎活跃 */
#define ETH_MAC_RXFIFO_EMPTY                  0x00000000U  /* Rx FIFO 填充等级：空 */
#define ETH_MAC_RXFIFO_BELOW_THRESHOLD        0x00000100U  /* Rx FIFO 填充等级：填充水平低于流量控制停用阈值 */
#define ETH_MAC_RXFIFO_ABOVE_THRESHOLD        0x00000200U  /* Rx FIFO 填充等级：填充水平高于流量控制激活阈值 */
#define ETH_MAC_RXFIFO_FULL                   0x00000300U  /* Rx FIFO 填充等级：满 */
#if defined(STM32F1)  /* STM32F1 系列微控制器 */
#else  /* 非 STM32F1 系列微控制器 */
#define ETH_MAC_READCONTROLLER_IDLE           0x00000000U  /* Rx FIFO 读控制器空闲状态 */
#define ETH_MAC_READCONTROLLER_READING_DATA   0x00000020U  /* Rx FIFO 读控制器正在读取帧数据 */
#define ETH_MAC_READCONTROLLER_READING_STATUS 0x00000040U  /* Rx FIFO 读控制器正在读取帧状态（或时间戳） */
#endif  /* 条件编译结束 */
#define ETH_MAC_READCONTROLLER_FLUSHING       0x00000060U  /* Rx FIFO 读控制器正在清空帧数据和状态 */
#define ETH_MAC_RXFIFO_WRITE_ACTIVE           0x00000010U  /* Rx FIFO 写控制器活跃 */
#define ETH_MAC_SMALL_FIFO_NOTACTIVE          0x00000000U  /* MAC 小型 FIFO 读/写控制器不活跃 */
#define ETH_MAC_SMALL_FIFO_READ_ACTIVE        0x00000002U  /* MAC 小型 FIFO 读控制器活跃 */
#define ETH_MAC_SMALL_FIFO_WRITE_ACTIVE       0x00000004U  /* MAC 小型 FIFO 写控制器活跃 */
#define ETH_MAC_SMALL_FIFO_RW_ACTIVE          0x00000006U  /* MAC 小型 FIFO 读/写控制器均活跃 */
#define ETH_MAC_MII_RECEIVE_PROTOCOL_ACTIVE   0x00000001U  /* MAC MII 接收协议引擎活跃 */

#define ETH_TxPacketConfig        ETH_TxPacketConfigTypeDef   /* 发送数据包配置结构体定义 */

/**
  * @}
  */

/** @defgroup HAL_DCMI_Aliased_Defines HAL DCMI 别名的定义，为保持向后兼容而保留
  * @{
  */
#define HAL_DCMI_ERROR_OVF      HAL_DCMI_ERROR_OVR  /* 溢出错误别名 */
#define DCMI_IT_OVF             DCMI_IT_OVR         /* 溢出中断别名 */
#define DCMI_FLAG_OVFRI         DCMI_FLAG_OVRRI     /* 溢出原始中断标志别名 */
#define DCMI_FLAG_OVFMI         DCMI_FLAG_OVRMI     /* 溢出屏蔽中断标志别名 */

#define HAL_DCMI_ConfigCROP     HAL_DCMI_ConfigCrop  /* 配置裁剪区域函数别名 */
#define HAL_DCMI_EnableCROP     HAL_DCMI_EnableCrop  /* 启用裁剪函数别名 */
#define HAL_DCMI_DisableCROP    HAL_DCMI_DisableCrop /* 禁用裁剪函数别名 */

/**
  * @}
  */

#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7)  /* 适用于 STM32L4、STM32F7、STM32F4（特定型号）和 STM32H7 系列 */
/** @defgroup HAL_DMA2D_Aliased_Defines HAL DMA2D 别名的定义，为保持向后兼容而保留
  * @{
  */
#define DMA2D_ARGB8888          DMA2D_OUTPUT_ARGB8888  /* 输出格式别名：ARGB8888 */
#define DMA2D_RGB888            DMA2D_OUTPUT_RGB888    /* 输出格式别名：RGB888 */
#define DMA2D_RGB565            DMA2D_OUTPUT_RGB565    /* 输出格式别名：RGB565 */
#define DMA2D_ARGB1555          DMA2D_OUTPUT_ARGB1555  /* 输出格式别名：ARGB1555 */
#define DMA2D_ARGB4444          DMA2D_OUTPUT_ARGB4444  /* 输出格式别名：ARGB4444 */

#define CM_ARGB8888             DMA2D_INPUT_ARGB8888   /* 输入格式别名：ARGB8888 */
#define CM_RGB888               DMA2D_INPUT_RGB888     /* 输入格式别名：RGB888 */
#define CM_RGB565               DMA2D_INPUT_RGB565     /* 输入格式别名：RGB565 */
#define CM_ARGB1555             DMA2D_INPUT_ARGB1555   /* 输入格式别名：ARGB1555 */
#define CM_ARGB4444             DMA2D_INPUT_ARGB4444   /* 输入格式别名：ARGB4444 */
#define CM_L8                   DMA2D_INPUT_L8         /* 输入格式别名：L8（8位亮度） */
#define CM_AL44                 DMA2D_INPUT_AL44       /* 输入格式别名：AL44（4位Alpha + 4位亮度） */
#define CM_AL88                 DMA2D_INPUT_AL88       /* 输入格式别名：AL88（8位Alpha + 8位亮度） */
#define CM_L4                   DMA2D_INPUT_L4         /* 输入格式别名：L4（4位亮度） */
#define CM_A8                   DMA2D_INPUT_A8         /* 输入格式别名：A8（8位Alpha） */
#define CM_A4                   DMA2D_INPUT_A4         /* 输入格式别名：A4（4位Alpha） */
/**
  * @}
  */
#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 */

#if defined(STM32L4) || defined(STM32F7) || defined(STM32F427xx) || defined(STM32F437xx) \
  || defined(STM32F429xx) || defined(STM32F439xx) || defined(STM32F469xx) || defined(STM32F479xx) \
  || defined(STM32H7) || defined(STM32U5)  /* 适用于 STM32L4、STM32F7、STM32F4（特定型号）、STM32H7 和 STM32U5 系列 */
/** @defgroup DMA2D_Aliases DMA2D API 别名
  * @{
  */
#define HAL_DMA2D_DisableCLUT       HAL_DMA2D_CLUTLoading_Abort    /*!< 为兼容旧代码，别名到 HAL_DMA2D_CLUTLoading_Abort */
/**
  * @}
  */

#endif  /* STM32L4 ||  STM32F7 ||  STM32F4 ||  STM32H7 || STM32U5 */

/** @defgroup HAL_PPP_Aliased_Defines HAL PPP 别名的定义，为保持向后兼容而保留
  * @{
  */

/**
  * @}
  */

/* 导出的函数 --------------------------------------------------------*/

/** @defgroup HAL_CRYP_Aliased_Functions HAL CRYP 别名的函数，为保持向后兼容而保留
  * @{
  */
#define HAL_CRYP_ComputationCpltCallback     HAL_CRYPEx_ComputationCpltCallback  /* 计算完成回调函数别名 */
/**
  * @}
  */

/** @defgroup HAL_DCACHE_Aliased_Functions HAL DCACHE 别名的函数，为保持向后兼容而保留
  * @{
  */

#if defined(STM32U5)  /* STM32U5 系列微控制器 */
#define HAL_DCACHE_CleanInvalidateByAddr     HAL_DCACHE_CleanInvalidByAddr       /* 按地址清理并失效缓存别名 */
#define HAL_DCACHE_CleanInvalidateByAddr_IT  HAL_DCACHE_CleanInvalidByAddr_IT    /* 按地址清理并失效缓存（中断模式）别名 */
#endif /* STM32U5 */

/**
  * @}
  */

#if !defined(STM32F2)  /* 非 STM32F2 系列微控制器 */
/** @defgroup HASH_alias HASH API 别名
  * @{
  */
#define HAL_HASHEx_IRQHandler   HAL_HASH_IRQHandler  /*!< 为兼容旧代码，重定向到 HAL_HASH_IRQHandler */
/**
  *
  * @}
  */
#endif /* STM32F2 */
/** @defgroup HAL_HASH_Aliased_Functions HAL HASH 别名的函数，为保持向后兼容而保留
  * @{
  */
#define HAL_HASH_STATETypeDef        HAL_HASH_StateTypeDef  /* HASH 状态类型定义别名 */
#define HAL_HASHPhaseTypeDef         HAL_HASH_PhaseTypeDef  /* HASH 阶段类型定义别名 */
#define HAL_HMAC_MD5_Finish          HAL_HASH_MD5_Finish    /* HMAC MD5 完成函数别名 */
#define HAL_HMAC_SHA1_Finish         HAL_HASH_SHA1_Finish   /* HMAC SHA1 完成函数别名 */
#define HAL_HMAC_SHA224_Finish       HAL_HASH_SHA224_Finish /* HMAC SHA224 完成函数别名 */
#define HAL_HMAC_SHA256_Finish       HAL_HASH_SHA256_Finish /* HMAC SHA256 完成函数别名 */

/* HASH 算法选择 */

#define HASH_AlgoSelection_SHA1      HASH_ALGOSELECTION_SHA1    /* SHA1 算法选择别名 */
#define HASH_AlgoSelection_SHA224    HASH_ALGOSELECTION_SHA224  /* SHA224 算法选择别名 */
#define HASH_AlgoSelection_SHA256    HASH_ALGOSELECTION_SHA256  /* SHA256 算法选择别名 */
#define HASH_AlgoSelection_MD5       HASH_ALGOSELECTION_MD5     /* MD5 算法选择别名 */

#define HASH_AlgoMode_HASH         HASH_ALGOMODE_HASH  /* HASH 算法模式别名 */
#define HASH_AlgoMode_HMAC         HASH_ALGOMODE_HMAC  /* HMAC 算法模式别名 */

#define HASH_HMACKeyType_ShortKey  HASH_HMAC_KEYTYPE_SHORTKEY  /* HMAC 短密钥类型别名 */
#define HASH_HMACKeyType_LongKey   HASH_HMAC_KEYTYPE_LONGKEY   /* HMAC 长密钥类型别名 */

#if defined(STM32L4) || defined(STM32L5) || defined(STM32F2) || defined(STM32F4) || defined(STM32F7) || defined(STM32H7)  /* 适用于多个 STM32 系列 */

#define HAL_HASH_MD5_Accumulate                HAL_HASH_MD5_Accmlt             /* MD5 累积函数别名 */
#define HAL_HASH_MD5_Accumulate_End            HAL_HASH_MD5_Accmlt_End         /* MD5 累积结束函数别名 */
#define HAL_HASH_MD5_Accumulate_IT             HAL_HASH_MD5_Accmlt_IT          /* MD5 累积（中断模式）函数别名 */
#define HAL_HASH_MD5_Accumulate_End_IT         HAL_HASH_MD5_Accmlt_End_IT      /* MD5 累积结束（中断模式）函数别名 */

#define HAL_HASH_SHA1_Accumulate               HAL_HASH_SHA1_Accmlt            /* SHA1 累积函数别名 */
#define HAL_HASH_SHA1_Accumulate_End           HAL_HASH_SHA1_Accmlt_End        /* SHA1 累积结束函数别名 */
#define HAL_HASH_SHA1_Accumulate_IT            HAL_HASH_SHA1_Accmlt_IT         /* SHA1 累积（中断模式）函数别名 */
#define HAL_HASH_SHA1_Accumulate_End_IT        HAL_HASH_SHA1_Accmlt_End_IT     /* SHA1 累积结束（中断模式）函数别名 */

#define HAL_HASHEx_SHA224_Accumulate           HAL_HASHEx_SHA224_Accmlt        /* SHA224 累积函数别名 */
#define HAL_HASHEx_SHA224_Accumulate_End       HAL_HASHEx_SHA224_Accmlt_End    /* SHA224 累积结束函数别名 */
#define HAL_HASHEx_SHA224_Accumulate_IT        HAL_HASHEx_SHA224_Accmlt_IT     /* SHA224 累积（中断模式）函数别名 */
#define HAL_HASHEx_SHA224_Accumulate_End_IT    HAL_HASHEx_SHA224_Accmlt_End_IT /* SHA224 累积结束（中断模式）函数别名 */

#define HAL_HASHEx_SHA256_Accumulate           HAL_HASHEx_SHA256_Accmlt        /* SHA256 累积函数别名 */
#define HAL_HASHEx_SHA256_Accumulate_End       HAL_HASHEx_SHA256_Accmlt_End    /* SHA256 累积结束函数别名 */
#define HAL_HASHEx_SHA256_Accumulate_IT        HAL_HASHEx_SHA256_Accmlt_IT     /* SHA256 累积（中断模式）函数别名 */
#define HAL_HASHEx_SHA256_Accumulate_End_IT    HAL_HASHEx_SHA256_Accmlt_End_IT /* SHA256 累积结束（中断模式）函数别名 */

#endif  /* STM32L4 || STM32L5 || STM32F2 || STM32F4 || STM32F7 || STM32H7 */
/**
  * @}
  */