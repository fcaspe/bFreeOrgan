#include "stm32f4xx.h"
#include "includes.h"

void timer_startup(void)
{

	//Prescaler = (TIM4CLK / TIM4 counter clock) - 1
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	uint16_t PrescalerValue;

	  /* TIMER 6 --- MASTER - DAC */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

	PrescalerValue = 84000000/2100000 -1;

	TIM_TimeBaseStructure.TIM_Period = 100;
											//Interupcion a 42K. 84 = 25K. 92 = 22.8Khz

	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure);

	/* Selección de TIM6 TRGO */

	TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);

	/* -- FIN CONFIGURACION TIMER 4 --*/


	  /* TIMER 3 --- SAMPLER */

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	PrescalerValue = 84000000/100000 -1; //100KHz

	TIM_TimeBaseStructure.TIM_Period = 100; //Periodo de disparo 1KHz
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	/* Selección de TIM3 TRGO */
	TIM_SelectOutputTrigger(TIM3, TIM_TRGOSource_Update);
	// Ahora el ADC será disparado por ADC_ExternalTrigConv_T3_TRGO


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //Genera aproximadamente un timer de 5hz

	PrescalerValue = 0xFFFF;
	TIM_TimeBaseStructure.TIM_Period = 0xAF; //Cuenta hasta llenar el registro.
	TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure);

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

