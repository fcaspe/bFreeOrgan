#include "stm32f4xx.h"
#include "includes.h"


/* VARIABLES GLOBALES DEL SISTEMA */

uint16_t sys_DACbuffer1[32]; //Buffer de una muestra, leido por el DAC.
uint16_t sys_DACbuffer0[32]; //Buffer de una muestra, leido por el DAC.
uint16_t *sys_DACcurrent;
uint16_t sys_sampleSent; //Contador de numero de muestras enviadas
FlagStatus sys_bufferCrash; //Indica que en algun momento no se enviaron correctamente los datos al DAC.
FlagStatus sys_bufferPending;
char sys_TXbuff[TX_BUFFOUT];

int main(void)
{

	boot_periph();

	synth_init();
	synth_FSM();

	for(;;);
}
