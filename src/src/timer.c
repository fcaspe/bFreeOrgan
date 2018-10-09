/*
 * bFreeOrgan
 * by Franco Caspe
 *
 * FILE: timer.c
 *
 * Timer settings functions
 * ------------------------
 *
 * External DAC timer is configured as discussed in:
 * https://community.st.com/thread/23600
 *
 * TIM2: 	- Defines sampling frequency.
 * 			- Controls trigger for DMA to SPI2 transfer.
 *			- Triggers the latch line for the External DAC.
 *
 * TIM3: 	- Samples Drawbar Position.
 *
 * TIM7		- Time base for the LFO.
 *
 * */


#include "stm32f4xx.h"
#include "includes.h"

void timer_startup(void)
{

	//Prescaler = (TIM4CLK / TIM4 counter clock) - 1
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	uint16_t PrescalerValue;

	  /* TIM2 (DAC) Configuration */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	PrescalerValue = 84000000/2100000 -1;
	TIM_TimeBaseStructure.TIM_Period = 50 -1;
											//Prescaler = 50 = Interupcion a 42K (Siempre restar 1)
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	TIM_Cmd(TIM2,ENABLE);
	/* Configure the PWM Channel for the latch signal */

	/* PWM1 Mode configuration: Channel 4 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	/* Specifies the count on which we generate the latching edge. */
	//If you want a rising edge when it passes 26 counts, Set PULSE at 26, polarity LOW;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_Pulse = 26;
										//Must be generated after the 16bits of the word are sended to the DAC.
										//We can try combining a slow SPI SCK with fast timer pulses in order
										//To nail the latching and generate the desired sampling frequency.
	/* EXAMPLE:
	 * SPI_PCLK = 42MHz
	 * SPI_BAUDRATE PRESCALER = 32
	 * SPI TAKES (16*32)/42MHz = 12.19us to send the word to external DAC. Next edge comes at 12.95us
	 * We must latch the DAC between the 12.19us and 12.95us timeframe.
	 *
	 * TIM2_PCLK = 84MHz
	 * PrescalerValue = 39. Prescaled Clock = 2.1MHz
	 * 12.19us * 2.1MHz = 25.59 cycles.
	 * 12.95us * 2.1MHz = 27.19 cycles.
	 *
	 * If we generate a risig edge at timer pulse 26 or 27 we can rest assured we
	 * are going to latch the data before the next sck edge comes in.
	 * DAC is latched by rising the CS signal. Then it won't accept anything until is's lowered again.
	 *
	 *
	 *
	 */

	TIM_OC4Init(TIM2, &TIM_OCInitStructure); //INIT CHANNEL 4
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

	/* Select Output Trigger for TIM2 TRGO */

	//TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update); //DMA To be triggered using this trigger source.

	TIM_DMACmd(TIM2, TIM_DMA_Update, ENABLE);
\
	/* -- TIM2 END CONFIG--*/

	/* TIMER 3 (Drawbar Sampler) Configuration */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	PrescalerValue = 84000000/100000 -1; //100KHz

	TIM_TimeBaseStructure.TIM_Period = 100; //Periodo de disparo 1KHz
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* Select Output Trigger for TIM3 */
	TIM_SelectOutputTrigger(TIM3, TIM_TRGOSource_Update);
	// ADC will be Triggered by ADC_ExternalTrigConv_T3_TRGO

	/* -- TIM3 END CONFIG--*/


	/* TIMER 7 (Auxiliary LFO time base) Configuration */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

	PrescalerValue = 0xFFFF; //Generates a reload rate of about 5 Hz.
	TIM_TimeBaseStructure.TIM_Period = 0x7F; //Cuenta hasta llenar el registro.
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

	/* -- TIM7 END CONFIG--*/

	/* TIMER 7 --- Generador de efecto? */
	/* TIMER 6 --- Generador de efecto? */

	/*RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);

	PrescalerValue = 48000000/1000 -1;
	TIM_TimeBaseStructure.TIM_Period = 100; //Cuenta hasta llenar el registro.
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;


	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

	NVIC_InitTypeDef nvicStructure;
	nvicStructure.NVIC_IRQChannel = TIM7_IRQn;
	nvicStructure.NVIC_IRQChannelPreemptionPriority = 0;
	nvicStructure.NVIC_IRQChannelSubPriority = 1;
	nvicStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&nvicStructure);



	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	PrescalerValue = 48000000/1000 -1;
	TIM_TimeBaseStructure.TIM_Period = 0xFFFF; //Cuenta hasta llenar el registro.
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;


	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);
	*/


}

void timer_cnt_start(void)
{
	  TIM_Cmd(TIM6, ENABLE);
}

void timer_cnt_reset(void)
{
	TIM_SetCounter(TIM6,0);
}
void timer_cnt_stop(void)
{
	  TIM_Cmd(TIM6, DISABLE);
}

uint16_t timer_cnt_read(void)
{
	return TIM6->CNT;
}

