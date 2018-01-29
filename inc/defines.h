 /* CONFIGURACIÓN PPAL MANUAL ------------------------------------------------------------------
	para PCLK2 = 6MHZ			*/
#define TABLE_BUFF 4096

 /* TRANSACCIÓN DMA ------------------------------------------------------------------*/
#define DMA_PDSIZE8 DMA_PeripheralDataSize_Byte
#define DMA_PDSIZE12 DMA_PeripheralDataSize_HalfWord

#define DMA_MDSIZE8 DMA_MemoryDataSize_Byte
#define DMA_MDSIZE12 DMA_MemoryDataSize_HalfWord

#define ADC1_DR_ADDRESS    ((uint32_t)0x4001204C)
#define DAC_DHR12R1_ADDR  0x40007408
/* LEDS ---------------------------------------------------------*/


#define LED_VERDE GPIO_Pin_12
#define LED_NARANJA GPIO_Pin_13
#define LED_ROJO GPIO_Pin_14
#define LED_AZUL GPIO_Pin_15


/* DEFINES DATALOGGER -------------------------------- ----------- */
#define TX_BUFFOUT 16
