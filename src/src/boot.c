#include "stm32f4xx.h"
#include "includes.h"

void LED_Init(void);
void SPI_DAC_Config(void);
void button_init(void);
void tremoloButtn_boot();
void ADC1_DMA_Config(void);
void boot_periph(void)
{
	//Startup
	SystemInit();
	LED_Init();
	button_init(); //CONFIGURA BOTÓN DISCOVERY E INTERRUPCIONES
	tremoloButtn_boot();
	//serial_dbg();
	midi_startup();
	if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)) midi_test();
	SPI_DAC_Config(); //Configures SPI, GPIO and DMA.


	ADC1_DMA_Config();

	timer_startup();



}

void ADC1_DMA_Config(void)
{
  ADC_InitTypeDef       ADC_InitStructure;
  ADC_CommonInitTypeDef ADC_CommonInitStructure;
  DMA_InitTypeDef       DMA_InitStructure;
  GPIO_InitTypeDef		GPIO_InitStructure;

  /*	Habilitar periféricos	*/
  //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOC, ENABLE);
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2 | RCC_AHB1Periph_GPIOC |RCC_AHB1Periph_GPIOB, ENABLE);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

  /*	GPIO Config.		*/

  /* Configura como entrada analógica los pines 1,2,4,5 del Puerto C, los 1,2,3 del Puerto A y 0,1 de Puerto B.*/

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5 ;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;	//GPIO Analog Mode
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; //NoPull para entrada analogica
  GPIO_Init(GPIOC, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /*	DMA Config.		*/

  DMA_DeInit(DMA2_Stream0);
  DMA_InitStructure.DMA_Channel = DMA_Channel_0;
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_ADDRESS;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)Drawbars;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;

  DMA_InitStructure.DMA_BufferSize 				= 9;
  DMA_InitStructure.DMA_PeripheralInc 			= DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc 				= DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize 		= DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize     		= DMA_MemoryDataSize_Byte;

  DMA_InitStructure.DMA_Mode 					= DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority 				= DMA_Priority_High;
  DMA_InitStructure.DMA_MemoryBurst 			= DMA_MemoryBurst_Single;	//BURST MODE OFF
  DMA_InitStructure.DMA_PeripheralBurst 		= DMA_PeripheralBurst_Single; //BURST MODE OFF
  DMA_InitStructure.DMA_FIFOThreshold 			= DMA_FIFOThreshold_Full;	// . . .
  DMA_InitStructure.DMA_FIFOMode 				= DMA_FIFOMode_Disable;

  DMA_Init(DMA2_Stream0, &DMA_InitStructure);	//INIT: Carga la configuracion en el DMA
  DMA_Cmd(DMA2_Stream0, ENABLE);

  /*	ADC Config.		*/

  ADC_DeInit();
  ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
  ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;	//PCLK2 ->divide PCLK2
  ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
  	  	  //Acceso DMA sirve solo en modo MULTI ADC

  /*	USADO PARA DUAL OR TRIPLE MODE
   * CUANDO EL BUFFER ES CIRCULAR Y TIENE UN SOLO VALOR SE DEBE CONFIGURAR
  ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; //Delay entre Conversiones
  */

  ADC_CommonInit(&ADC_CommonInitStructure);


  ADC_InitStructure.ADC_Resolution = ADC_Resolution_8b;
  ADC_InitStructure.ADC_ScanConvMode = ENABLE;		//SCAN MODE OFF (escanea multiples canales)
  ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T3_TRGO;	// TIM3 TRIGGER EXTERNO
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_Rising; //Activo por Flanco positivo

  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 9;	//Numero de Conversiones a realizar
  	  	  	  	  	  	  	  	  	  	  	  	//En regular channel conversion sequence (REGULAR GROUP, VARIOS CANALES)

  ADC_Init(ADC1, &ADC_InitStructure);

  ADC_DMACmd(ADC1, ENABLE);

  /* Definición de la secuencia de conversión */
  /* Secuenciar de acuerdo a la mejor disposición de pines posible */
  /*
   * |---|----------|-------|---------------|
   * |POS|DRAWBAR	|GPIO	|ADC CHANNEL	|
   * |---|----------|-------|---------------|
   * |0	 |16		|PB0	|8				|
   * |1	 |5 1/3		|PC4	|14				|
   * |2	 |8			|PA2	|2				|
   * |3	 |4			|PC2	|12				|
   * |4	 |2 2/3		|PC1	|11				|
   * |5	 |2			|PA1	|1				|
   * |6	 |1 3/5		|PA3	|3				|
   * |7	 |1 1/3		|PC5	|15				|
   * |8	 |1			|PB1	|9				|
   * |---|----------|-------|---------------|
   */

  /* Estos valores pasarán a formar parte del arreglo synth_Drawbars */

  ADC_RegularChannelConfig(ADC1, ADC_Channel_8 ,1, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_14,2, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_2 ,3, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_12,4, ADC_SampleTime_3Cycles);

  ADC_RegularChannelConfig(ADC1, ADC_Channel_11,5, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_1 ,6, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_3 ,7, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_15,8, ADC_SampleTime_3Cycles);
  ADC_RegularChannelConfig(ADC1, ADC_Channel_9 ,9, ADC_SampleTime_3Cycles);

  ADC_DMARequestAfterLastTransferCmd(ADC1, ENABLE);

  ADC_Cmd(ADC1, ENABLE);

}
/*
 * Configures GPIOB, DMA1, SPI2 for driving the External DAC.
 */
void SPI_DAC_Config(void)
{

	GPIO_InitTypeDef GPIO_config;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);


	/*	SPI CONFIGURATION	*/

	SPI_InitTypeDef SPI_InitStructure;
	SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;       	//The SPI bus setup uses two lines, one for Rx and one for Tx
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;                   	//STM32 is the master with the TLC5940s as slaves
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;               	//Use 16-bit data transfers
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;                        //MAX5541 clock must be low when idle.
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;                        //MAX5541 uses first (rising) clock transition as the "capturing edge"
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;                           //Software slave-select operation


	/* SCK Source Frequency will be APB1 Periphear Clock frequency. */
	/* Both SPI2 and TIM2 are in APB1, so we should use a related prescaler value. */
	/* PCLK1 of APB1 is at 42MHz */

	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32; 	//Set the prescaler
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;                  //TLC5940 data is transferred MSB first
	SPI_InitStructure.SPI_CRCPolynomial = 0;                            //No CRC used

	SPI_Init(SPI2, &SPI_InitStructure);   //Initialise the SPI2 peripheral
	//SPI_SSOutputCmd(SPI2, ENABLE);        //Set the SS Pin as an Output (master mode)
	//SPI_I2S_DMACmd(SPI2,SPI_I2S_DMAReq_Tx,ENABLE); //FOR SPI TRIGGERING DMA DOESNT APPLY HERE.
	SPI_Cmd(SPI2, ENABLE);
	/*	GPIO CONFIGURATION	*/

	/* PB11 Timer OC Output. - TIM2 CH4 (NSS) */
	/* PB13 SPI CLK Output. (SPI2_SCK) */
	/* PB15 SPI MOSI (SPI2_MOSI) */

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_TIM2);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource13,GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_SPI2);

	GPIO_config.GPIO_Pin  = GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_15 ;
	GPIO_config.GPIO_Mode = GPIO_Mode_AF;
	GPIO_config.GPIO_OType = GPIO_OType_PP;
	GPIO_config.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_config.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_config);


	/*	DMA CONFIGURATION	*/

	DMA_InitTypeDef DMA_INIT;

	DMA_DeInit(DMA1_Stream7);
	DMA_INIT.DMA_Channel            = DMA_Channel_3;
	DMA_INIT.DMA_PeripheralBaseAddr = (uint32_t)&(SPI2->DR);
	DMA_INIT.DMA_Memory0BaseAddr    = (uint32_t)sys_DACbuffer0;
	DMA_INIT.DMA_DIR                = DMA_DIR_MemoryToPeripheral;
	DMA_INIT.DMA_BufferSize         = 32;
	DMA_INIT.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
	DMA_INIT.DMA_MemoryInc          = DMA_MemoryInc_Enable;
	DMA_INIT.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_INIT.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
	DMA_INIT.DMA_Mode               = DMA_Mode_Circular;
	DMA_INIT.DMA_Priority           = DMA_Priority_High;
	DMA_INIT.DMA_FIFOMode           = DMA_FIFOMode_Disable;
	DMA_INIT.DMA_FIFOThreshold      = DMA_FIFOThreshold_Full;
	DMA_INIT.DMA_MemoryBurst        = DMA_MemoryBurst_Single;
	DMA_INIT.DMA_PeripheralBurst    = DMA_PeripheralBurst_Single;


	//Two functions must be called before calling the DMA_Init() function.
	//Extracted from: http://www.hanese.nl/STM32/stm32f2stdlibrary/html/group___d_m_a___group3.html

	DMA_DoubleBufferModeConfig(DMA1_Stream7, (uint32_t)sys_DACbuffer1,(uint32_t)sys_DACbuffer0);

	DMA_DoubleBufferModeCmd(DMA1_Stream7, ENABLE);

	DMA_Init(DMA1_Stream7, &DMA_INIT);

	//Trabajo con la interrupción del DMA

	NVIC_InitTypeDef NVIC_InitStructure;

	/* Configure the Priority Group to 2 bits */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	/* Enable the DMA Stream IRQ Channel */
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Stream7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	DMA_ITConfig(DMA1_Stream7, DMA_IT_TC, ENABLE);



	/*   ENABLE PERIPHERALS   */
	DMA_Cmd(DMA1_Stream7, ENABLE);

}

void tremoloButtn_boot()
{
	 GPIO_InitTypeDef GPIO_InitStruct;
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	 GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
	 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	 GPIO_Init(GPIOE, &GPIO_InitStruct);

	 GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	 GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	 GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	 GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	 GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	 GPIO_Init(GPIOE, &GPIO_InitStruct);

	 GPIO_ResetBits(GPIOE,GPIO_Pin_9);

}

void LED_Init(void)

{

		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

		/* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */


		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD, &GPIO_InitStructure);

}

void button_init(void)
{

		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

		/* Configure PD12, PD13, PD14 and PD15 in output pushpull mode */


		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
		GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

		EXTI_InitTypeDef EXTI_InitStructure;
		EXTI_StructInit(&EXTI_InitStructure);
		EXTI_InitStructure.EXTI_Line = EXTI_Line0;
		EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
		EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
		EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		EXTI_Init(&EXTI_InitStructure);

		NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);

}
