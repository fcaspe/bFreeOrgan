#include "stm32f4xx.h"
#include "includes.h"


void serial_RCC_Configuration(void);
void serial_GPIO_Configuration(void);
void serial_USART2_Configuration(void);
void buffer_send();


DMA_InitTypeDef  DMA_UART_TX_InitStructure; // La mantengo como variable global para cargar sus
											// parametros solo una vez, y luego modificar solo la
											// cantidad de bytes a enviar

void datalog_startup()
{
	serial_RCC_Configuration();
	serial_GPIO_Configuration();
	serial_USART2_Configuration();
}

void serial_ssend(char* str)
{
	uint16_t i;
	for(i=0;i<strlen(str);i++)
	{
			while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)  {}  // Espera que el registro de transmision este libre
			USART_SendData(USART2, (uint16_t)str[i]); // Envia un caracter
	}

	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)  {}
		USART_SendData(USART2, '\r'); // Retorno de Carro

	while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)  {}
		USART_SendData(USART2, '\n'); // Retorno de Carro
}



void serial_dbg(void)
{
serial_RCC_Configuration();
serial_GPIO_Configuration();
serial_USART2_Configuration();

}
void serial_RCC_Configuration(void)
{
  /* --------------------------- System Clocks Configuration -----------------*/
  /* USART3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
  /* GPIOB clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
}

  /* Initialize pins for USART2 */

void serial_GPIO_Configuration(void)
  {

    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);




    /*-------------------------- GPIO Configuration ----------------------------*/

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2; // Pins PA2 (TX)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
  }

void serial_USART2_Configuration(void)

{
    USART_InitTypeDef USART_InitStructure;

  /*---------------------------- USARTx configuration --------------------------*/

  /* USARTx configured as follow:

        - BaudRate = 115200 baud
        - Word Length = 8 Bits
        - one Stop Bit
        - Odd parity
        - Hardware flow control disabled (RTS and CTS signals) ya que estoy usando solo
          el pin Tx
        - Transmit enabled.

  */

  USART_InitStructure.USART_BaudRate = 9600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity =USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx;

  USART_Init(USART2, &USART_InitStructure);     //Inicializa USART2
  USART_Cmd(USART2, ENABLE);					//Activa USART2

}

void serial_DMA_Config()
{
	// Clock enable para el DMA
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);

		// Iniciliza canal del DMA para la UART4
		DMA_DeInit(DMA1_Stream7);
		DMA_UART_TX_InitStructure.DMA_BufferSize = TX_BUFFOUT;
		DMA_UART_TX_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
		DMA_UART_TX_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;
		DMA_UART_TX_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single ;
		DMA_UART_TX_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
		DMA_UART_TX_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
		DMA_UART_TX_InitStructure.DMA_Mode = DMA_Mode_Normal;
		DMA_UART_TX_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) (&(USART3->DR));
		DMA_UART_TX_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
		DMA_UART_TX_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
		DMA_UART_TX_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
		DMA_UART_TX_InitStructure.DMA_Priority = DMA_Priority_High;

		DMA_UART_TX_InitStructure.DMA_Channel = DMA_Channel_4;
		DMA_UART_TX_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
		DMA_UART_TX_InitStructure.DMA_Memory0BaseAddr =(uint32_t)sys_TXbuff;
		DMA_Init(DMA1_Stream7,&DMA_UART_TX_InitStructure);

		DMA_Cmd(DMA1_Stream7,ENABLE);
		USART_DMACmd(USART2, USART_DMAReq_Tx, ENABLE);

}

void serial_DMA_send(char* msj)
{
		uint16_t n;

		while(USART_GetFlagStatus(USART3, USART_FLAG_TC)==0);
		USART_ClearFlag(USART3, USART_FLAG_TC);  // Baja la bandera de la UART
		DMA_ClearFlag(DMA1_Stream7,DMA_FLAG_TCIF7); // Baja la bandera del DMA

		//INICIA LA COPIA DEL MENSAJE RECIBIDO Y CALCULA EL NUMERO DE CARACTERES
		n=0;
		while(n<TX_BUFFOUT){
			if(msj[n] == 0)
				break;
			else
			{
				sys_TXbuff[n] = msj[n];
				n++;
			}
		}

		if(n==0) return;
		sys_TXbuff[n] = 0;

		DMA_UART_TX_InitStructure.DMA_BufferSize = n;
		DMA_Init(DMA1_Stream7,&DMA_UART_TX_InitStructure);

		DMA_Cmd(DMA1_Stream7,ENABLE);
		USART_DMACmd(USART3, USART_DMAReq_Tx, ENABLE);

		return;

}

