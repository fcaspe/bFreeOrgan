
#include "stm32f4xx.h"
#include "includes.h"

volatile uint8_t MIDI_buffer[512]; //4 BYTES, PERO USAMOS SOLO

uint16_t MIDI_lastPos; //Última posición procesada del buffer
midiStatus_t runningStatus; //Indica si hay un estado de corrida MIDI.
void midi_test()
{
	while(1)
	{
		if(USART3->DR != 0) GPIO_SetBits(GPIOD,LED_NARANJA);

	}
}

void midi_startup(void)
{
	// MIDI POR GPIOD Y USART3
	/* ENABLE CLOCK */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	/* Config AF GPIOB */
    GPIO_InitTypeDef GPIO_InitStructure;



    /*-------------------------- GPIO Configuration ----------------------------*/

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // Pin PB11 (RX)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);


    USART_InitTypeDef USART_InitStructure;

  /*---------------------------- USARTx configuration --------------------------*/

    USART_InitStructure.USART_BaudRate = 31250;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity =USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx;

    USART_Init(USART3, &USART_InitStructure);     //Inicializa USART3
    USART_Cmd(USART3, ENABLE);					//Activa USART3

    // Clock enable para el DMA
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

    // Iniciliza canal del DMA para la UART4 para recibir


    DMA_InitTypeDef  DMA_UART_RX_InitStructure;


    DMA_DeInit(DMA1_Stream1); //PARA USART3, RX

    DMA_UART_RX_InitStructure.DMA_Channel = DMA_Channel_4;
    DMA_UART_RX_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_UART_RX_InitStructure.DMA_Memory0BaseAddr =(uint32_t)MIDI_buffer;
    DMA_UART_RX_InitStructure.DMA_BufferSize = 512;
    DMA_UART_RX_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable; //No puedo hacer burst porque debo recibir de a un byte.
    DMA_UART_RX_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_UART_RX_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_INC4;
    DMA_UART_RX_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_UART_RX_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_UART_RX_InitStructure.DMA_Mode = DMA_Mode_Circular;
    DMA_UART_RX_InitStructure.DMA_PeripheralBaseAddr = (uint32_t) (&(USART3->DR));
    DMA_UART_RX_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_UART_RX_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_UART_RX_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_UART_RX_InitStructure.DMA_Priority = DMA_Priority_Low;

    DMA_Init(DMA1_Stream1,&DMA_UART_RX_InitStructure);
    USART_DMACmd(USART3, USART_DMAReq_Rx, ENABLE);

    DMA_Cmd(DMA1_Stream1,ENABLE);


}

midiStatus_t MIDI_getCommand(uint8_t *command_data)
/*
 * BUSCA EN EL BUFFER UN MENSAJE DE TIPO NOTE ON O NOTE OFF hasta completar la sección llenada del arreglo.
 * - Si se reconoce un comando entonces:
 * 		- Se verifica que esté completo dentro del buffer
 * 	 	- Se cargan los datos del comando
 * 	 	- Se adelanta el índice 3 bytes.
 * 	 	- Se retorna el dato para cargarlo en la tabla MIDI.
 * 	- Si no se encuentra ningún comando en el buffer o si está incompleto
 * 		- Se devuelve MIDI_NODATA y la máquina de estados continúa su ciclo.
 *
 * 	COMPATIBLE CON LA CONDICIÓN MIDI RUNNING, DESCRIPTA EN
 * 	http://www.music-software-development.com/midi-tutorial.html
 * 	QUE PRESENTA POR EJEMPLO EL DX100.
 *
 */
{
	uint16_t i;
	uint16_t end_pos = 512 - DMA1_Stream1->NDTR;

	for(i = MIDI_lastPos;i != end_pos ;i = (i+1) & 511)
	{
		if(runningStatus != MIDI_NODATA)
		{
			if(MIDI_buffer[i] > 127) 			//Si el caracter que sigue no es un byte de datos,
				runningStatus = MIDI_NODATA;	// entonces no hay una corrida midi en curso; se espera un mensaje regular


			else
			{
			*command_data = MIDI_buffer[i];

			i = (i+1)&511;
			if(i== end_pos) return MIDI_NODATA; //En caso de mensaje incompleto, esperamos a completarlo.
			MIDI_lastPos = (i+1)&511;
			if(MIDI_buffer[i] == 0 ) return NOTE_OFF; //NOTE OFF ALTERNATIVO, ENVIAR NOTA CON VELOCIY EN CERO.

			return runningStatus;
			}
		}

		if(MIDI_buffer[i] == 0x80) //CANAL 1, NOTE OFF
		{

			MIDI_lastPos = i;

			i = (i+1)&511;
			if(i== end_pos) return MIDI_NODATA; //DETECCIÓN DE COMANDOS INCOMPLETOS.
												//RETORNAR ESTE VALOR OBLIGA A DESESTIMAR EL DATO DEL COMANDO
												//Y PERMITE RETOMAR SU LECTURA EN OTRO CICLO DE LA FSM.
			*command_data = MIDI_buffer[i];

			i = (i+1)&511;
			if(i== end_pos) return MIDI_NODATA;

			runningStatus = NOTE_OFF;			//EL dato recibido se procesará. Entonces abrimos la posibilidad de una corrida MIDI
			MIDI_lastPos = (i+1)&511;
			return NOTE_OFF;
		}

		if(MIDI_buffer[i] == 0x90) //CANAL 1, NOTE ON
		{
			MIDI_lastPos = i;

			i = (i+1)&511;
			if(i== end_pos) return MIDI_NODATA;
			*command_data = MIDI_buffer[i];

			i = (i+1)&511;
			if(i == end_pos) return MIDI_NODATA;

			runningStatus = NOTE_ON;			//EL dato recibido se procesará. Entonces abrimos la posibilidad de una corrida MIDI
			MIDI_lastPos = (i+1)&511;
			if(MIDI_buffer[i] == 0 ) return NOTE_OFF; //NOTE OFF ALTERNATIVO, ENVIAR NOTA CON VELOCIY EN CERO.
			return NOTE_ON;
		}
	}

	MIDI_lastPos = end_pos;

	return MIDI_NODATA;

}
