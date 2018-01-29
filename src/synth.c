/*
 * synth.c
 *
 *  Created on: Jul 12, 2017
 *      Author: franco
 *
 *  Manejo de la generacion de audio y control del muestreo
 */

#include "stm32f4xx.h"
#include "includes.h"

uint16_t synth_sample; //Muestra de 12 bits de salida del sintetizador
int32_t synth_q16q8ampAcc; //ACUMULADOR DE AMPLITUD, formato Q16.8 CON SIGNO
uint16_t synth_activeNotes; //Registro de notas activas
uint16_t synth_sampleReady; //Muestra lista que fue enviada al buffer circular del DAC
uint16_t synth_atenuator[16] = {20,24,28,30, //MEDIDO PARA CONSERVAR EL VALOR RMS DEL VOLTAJE DE SALIDA CON MUCHAS NOTAS APRETADAS
								32,34,35,36,
								36,36,40,42,
								44,45,46,48};

synthStatus synth_command;
bufferStatus estadoBuffer;
MIDIStatus MIDI_command;
uint8_t MIDI_dataRcv;

MIDIStatus MIDI_getCommand(uint8_t *command_data);
void ampTable_update();
bufferStatus check_timeout();

void synth_FSM()
/*
 * Máquina principal de estados del sintetizador.
 * Cicla a la velocidad de muestreo determinada.
 * Realiza las 5 acciones básicas para generación del audio.
 * 1. Leer MIDI
 * 2. Generar amplitudes por tono
 * 3. Sintetizar muestra
 * 4. Aplicar efectos y extras (click, etc)
 * 5. Enviar muestra al DAC
 */
{

	//MAIN LOOP
	while(synth_command == COMMAND_SYNTHESIZE)
	{

		/* --- PASO 1: LEER BUFFER MIDI Y ACTUALIZAR LISTA DE NOTAS --- */

		//if(synth_activeNotes) DAC_DMACmd(DAC_Channel_1, ENABLE);
		//else DAC_DMACmd(DAC_Channel_1, DISABLE);


		MIDI_command = MIDI_getCommand(&MIDI_dataRcv);

		while(MIDI_command != MIDI_NODATA)
		{

			if(MIDI_command == SYSEX_EXCEPTION)
				{
				atender_sysex();
				break;
				}

			MIDITable_update();
			MIDI_command = MIDI_getCommand(&MIDI_dataRcv);
		}

		/* --- PASO 2: ACTUALIZAR LISTA DE AMPLITUDES CON LISTA MIDI + DRAWBARS --- */

		ampTable_update(q4q8ampTable,MIDI_activeTable,switchbox,synth_Drawbars); // Esta funcion corre sola a 21Khz


		/* --- PASO 3: SINTETIZAR MUESTRA --- */

		for(synth_sampleReady = 0; synth_sampleReady < 32; synth_sampleReady++)
		{

			//SI SE FUERZA LA EJECUCION CUANDO NO HAY NOTAS ENCENDIDAS METE RUIDO!!!

			/*RUIDO -- RUIDO -- RUIDO*/
			//sinthesize_sample(&synth_q16q8ampAcc,q12q16phaseTable,q4q8ampTable,qstep,wave_sine);
			if(synth_activeNotes)
						{

				/*ACA SINTHESIZE SAMPLE NO METE RUIDO!! */

				sinthesize_sample(&synth_q16q8ampAcc,q12q16phaseTable,q4q8ampTable,qstep,wave_sine);

						//synth_q16q8ampAcc = synth_q16q8ampAcc /(synth_atenuator[synth_activeNotes - 1]); //IMPLEMENAR UNA MULTIPLICACION FRACCIONAL DE ACUERDO AL VALOR DE ACTIVE NOTES.
						//synth_q16q8ampAcc = synth_q16q8ampAcc /(8*synth_activeNotes); //IMPLEMENAR UNA MULTIPLICACION FRACCIONAL DE ACUERDO AL VALOR DE ACTIVE NOTES.

						//TEST MOD AMPLITUD
						synth_q16q8ampAcc = synth_q16q8ampAcc *(TIM7->CNT + 50);
						synth_q16q8ampAcc = synth_q16q8ampAcc >> 8;


						synth_q16q8ampAcc = synth_q16q8ampAcc /(48); //IMPLEMENAR UNA MULTIPLICACION FRACCIONAL DE ACUERDO AL VALOR DE ACTIVE NOTES.
						synth_q16q8ampAcc += 0x0007FF00; //SUMAMOS EL VALOR MEDIO EN FORMATO Q16.8
						synth_sample = (synth_q16q8ampAcc >> 8) & 0x0FFF;
						}
					else
						synth_sample = 0x07FF;

			sys_DACcurrent[synth_sampleReady] = synth_sample;

		}


		/* --- PASO 4: EFECTOS Y XTRAS --- */



		/* --- PASO 5: CHEQUEAR VENCIMIENTOS --- */

		//LEVANTO EL FLAG DE BUFFER PENDIENTE PARA AVISAR QUE ESTE BUFFER ESTÁ LISTO PARA SER ENVIADO

		sys_bufferPending = SET;

		//Chequear si hubo un crash
		estadoBuffer = check_timeout();

		if(estadoBuffer == BUFFER_CRASH)
			atender_crash();



		while(estadoBuffer != BUFFER_WRITTEN) estadoBuffer = check_timeout();


		//SWITCHEAR BUFFERS PARA PRÓXIMA CARGA
		if(sys_DACcurrent == sys_DACbuffer1) sys_DACcurrent = sys_DACbuffer0;
		else sys_DACcurrent = sys_DACbuffer1;

	}
	//FIN MAIN LOOP
}

bufferStatus check_timeout()
/*
 * Chequea si hay vencimientos pendientes relativos a la generación de audio.
 *
 */
{
	if (sys_bufferCrash == SET) //Si hubo un error avisamos una vez, y eliminamos el flag pendiente.
									//La máquina de estados se recuperará de alguna forma a determinar
		{
			sys_bufferCrash = RESET;
			GPIO_ResetBits(GPIOD,LED_ROJO); //Podriamos borrar el led rojo luego, una vez q determinemos como recuperar el error.
			return BUFFER_CRASH;

		}
		else if (sys_bufferPending == SET) return BUFFER_PENDING;//Mientras exista una muestra pendiente para enviar al DAC, esperamos.

		else // Si podemos escribir porque no hay muestra pendiente, lo informamos.
		{
			return BUFFER_WRITTEN;
		}

}

void DMA1_Stream5_IRQHandler(void)
/*
 * Interrupción de control de llenado de buffer.
 * Cuando interrumpe verifica que el proximo buffer a llenar esté lleno.
 */
{
  /* Test on DMA Stream Transfer Complete interrupt */
  if (DMA_GetITStatus(DMA1_Stream5, DMA_IT_TCIF5));
  {
	GPIO_ToggleBits(GPIOD,LED_AZUL);

	//Si hay un buffer esperando ser leído, entonces el DMA precargará
	//una muestra nueva de un buffer completo, sin error

	if(sys_bufferPending == SET)
		sys_bufferPending = RESET;
	else
		//Si no se terminó de llenar el próximo buffer, no podemos asegurar
		//que el DMA precargará una muestra nueva.
		{
		sys_bufferCrash = SET;
		GPIO_SetBits(GPIOD,LED_ROJO);
		}


	/* Clear DMA Stream Transfer Complete interrupt pending bit */

  }
	DMA_ClearITPendingBit(DMA1_Stream5, DMA_IT_TCIF5);

}

void MIDITable_update()
/*
 * Se extrae de ampTable_update() y se eliminan las comparaciones redundantes.
 * Funcionamiento:
 * 	Si hay comando NOTE_ON, se busca el primer lugar vacio para cargar la nota.
 *
 * 	Si hay comando NOTE_OFF, se busca la posicion de la nota que se soltó para eliminarla de la lista.
 */
{
	uint16_t i;
	uint8_t noteRcv = MIDI_dataRcv - MIDI_NOTE_OFFSET;
	if(MIDI_command == NOTE_ON)
	{
		synth_activeNotes++;
		GPIO_ToggleBits(GPIOD,LED_NARANJA);
		for(i=0;i<16;i++)
			if(MIDI_activeTable[i] == 0xFF) //Si hay un espacio vacío.
					{
					MIDI_activeTable[i] = noteRcv;//Si hay una carga pendiente, la ingreso en tabla OFFSETEADA AL VALOR
					break;
					}

	}
	if(MIDI_command == NOTE_OFF)
	{
		synth_activeNotes--;
		GPIO_ToggleBits(GPIOD,LED_VERDE);
		for(i=0;i<16;i++)
			if(MIDI_activeTable[i] == noteRcv) //Si se encuentra la nota que se apagó, se borra
					{
					MIDI_activeTable[i] = 0xFF;
					break;
					}
	}
	return;
}

void sinthesize_sample(int32_t *sample_acc, uint32_t *phase_table, uint16_t *amp_table,const uint32_t *step,const int16_t *sine_wave)
{
	/*
	 * Síntesis de la muestra según lo descripto en el paper
	 * base para este proyecto.
	 * Actualiza los acumuladores de fase de los tonos
	 * Y carga su amplitud, modificada por el bus de atenuadores
	 *
	 * OJO, ESTA FUNCION ES UN STUB DE ASSEMBLER!
	 */

	register int16_t *wave asm("r4") = sine_wave;   //Registramos la direccion de memoria del quinto parametro en r4.
	 	 	 	 	 	 	 	 	 	 	 	 	 //Los otros parámetros están grabados en r0,r1,r2 y r3.

	asm volatile(				//CON VOLATILE EL COMPILADOR NO NOS "OPTIMIZA" EL CODIGO DE ASSEMBLER

				"mov	r8,#0\n\t"		//R8 ES EL REGISTRO ACUMULADOR TEMPORAL DE AMPLITUD
				"mov	r5, #79\n\t"	//DEFINIMOS LA VARIABLE DE CUENTA I
			"loop:\n\t"

				//0. Verificar que el bus de amplitud no posee para el armónico el valor cero
				"ldrh	r9,[r2], #2\n\t"	//ACCEDEMOS AL VALOR CORRESPONDIENTE DEL BUS DE AMPLITUD. LDRH EXTIENDE A 32 BITS SIN SIGNO
				"ldr	r6,[r1], #0\n\t"
				"ldr	r7,[r3], #4\n\t"
				//1. sumar al valor actual de la tabla de fase el valor actual de la tabla de step
				"add	r6,r7\n\t"
				"str	r6,[r1], #4\n\t"
				"cmp	r9,#0\t\n"
				"beq	loop_end\t\n"

				//2. OBTENER LOS 12 BITS DEL ACUMULADOR DE FASE DE LA POSICION ACTUAL

				"lsr	r6,r6,#16\n\t"	//ROTA EL VALOR DEL ACUMULADOR DE FASE 16 BITS A LA DERECHA

				"ubfx    r6, r6, #0, #12\n\t" //EXTRAE LOS PRIMEROS 12 BITS


				//3. ACCEDER A LA TABLA DE ONDA CON ACUMULADOR DE FASE, MULTIPLICAR POR AMPLITUD Y GRABAR EN ACUMULADOR DE AMPLITUD

				"lsl	r6,r6,#1\n\t"	//MULTIPLICA POR DOS, PORQUE ACCEDEMOS DE A 16 BITS A LA TABLA
				"add	r7,r4,r6\n\t"	//SUMAMOS A LA DIRECCION INICIAL EL OFFSET DE TABLA Y GRABAMOS EN R7

				"ldrsh	r6,[r7, #0]\n\t"	//ACCEDEMOS A LA MUESTRA CORRESPONDIENTE DE LA TABLA DE ONDA Y GRABAMOS EN R6. LDRSH EXTIENDE A 32 BITS CON SIGNO
				"smlabb	r8,r6,r9,r8\n\t"	//GRABAMOS EN R8 EL RESULTADO DE LA OPERACION ( R6*R7 + R8 )
											//ES UNA OPERACIÓN DE MULTIPLICACIÓN SIGNADA DE DOS HALF Y ACUMULA 32 BITS. NO SE QUE ES BOTTOM BY BOTTOM



			"loop_end:\n\t"
				"subs	r5,#1\n\t"		//RESTO AL CONTADOR DE ITERACIONES Y GENERO FLAG
				"bne	loop\n\t"		//SALTA A LOOP SI R5 SI EL FLAG GENERADO NO ES EL DE IGUAL A CERO.

				"str	r8,[r0,#0]\n\t" //GRABO EN R0 EL RESULTADO DE LA ACUMULACION
				"add     r7, sp, #0\n\t" //RECUPERO EL ESTADO DEL REGISTRO R7 USADO POR EL COMPILADOR, ESTO SE VE EN EL DISSASEMBLY
	 );

	 return;		//REEMPLAZARIA A ESTA INSTRUCCION OMITIDA ARRIBA:
	 	 	 	 	//"bx	lr\n\t"
	 	 	 		//EN REALIDAD RETURN TAMBIEN REVIERTE LAS OPERACIONES SOBRE LA PILA QUE REALIZA EL COMPILADOR AL COMENZAR LA FUNCION
}

void ampTable_update(uint16_t *ampTable,uint8_t *MIDI_table,uint8_t *switchbox,uint8_t *drawbars)
{
	/*
	 * Lee las notas activas y construye una tabla de amplitud
	 * de todos los armónicos que debe generar el órgano.
	 *
	 * Esta tabla se utiliza luego para generar la muestra de audio.
	 *
	 * OJO, ESTA FUNCION ES UN STUB DE ASSEMBLER!
	 */


	asm volatile (

			"mov	r5,#79\n\t"			//INICIALIZAR VARIABLE ITERACIONES
			"mov	r6,#0\n\t"			//INICIALIZAR ESPACIO DE 16 BITS EN CERO
			"mov	r8,r0\n\t"

		"clean_table:\n\t"				//SE PODRIA BORRAR DE A 32 BITS Y TARDARIA LA MITAD
			"strh	r6,[r8], #2\n\t"	//POS INDEXACION
			"subs	r5,#1\n\t"
			"bne	clean_table\n\t"

			//FIN LIMPIEZA TABLA

			"mov	r5,#16\n\t"


		"load_table:\n\t"

			"cbz	r5,exit\n\t"
			"sub	r5,#1\n\t"

			"ldrb	r6,[r1],#1\n\t"		//CARGO UN BYTE EN LA TABLA MIDI Y LUEGO, MUEVO UNA POSICION
			"cmp	r6,0X000000FF\n\t"	//VERIFICO SI ES NOTE OFF
			"beq	load_table\n\t"		//SI ES IGUAL, ITERO
										//SI NO ES IGUAL . . .

										//TENGO QUE ENTRAR EN SWITCHBOX Y SUMAR LAS AMPLITUDES RELATIVAS
										//TENGO QUE MOVERME 8 POSICIONES EN SWBOX POR ITERACION

										//R6 TIENE LA NOTA MIDI
			"mov	r4,#9\n\t"			//CARGO EL VALOR 9 EN R4. SERVIRA PARA MULTIPLICAR A R6 Y LUEGO PARA ITERAR

			"mul	r6,r4\n\t"			//OBTENGO EL OFFSET PARA ENTRAR EN LA TABLA SWBOX (R6 es la nota)
			"add	r6,r2\n\t"			//SUMO A LA DIRECCION DE SWBOX EL OFFSET DE TABLA.
										//R6 CONTIENE AHORA LA DIRECCION DEL PRIMER CONTACTO, (TAMAÑO BYTE)

										//R6 AHORA RECORRE SWITCHBOX
			"read_switchbox:\n\t"

				"ldrb	r7,[r6], #1\n\t"//CARGO EN R7 EL VALOR DE SWBOX
				"lsl	r7,#1\n\t"		//MULTIPLICO POR DOS PARA ACCEDER DE A HALF WORD

				"add	r7,r0,r7\n\t"	//ACCEDO A LA DIRECCION DEL VALOR CORRESPONDIENTE AL ARMONICO EN LA TABLA DE AMPL.

				"ldrh	r9,[r7, #0]\n\t"//CARGO EL VALOR ACTUAL DE AMPLITUD

				"ldrb	r8,[r3],#1\n\t"	//CARGO EL DRAWBAR CORRESPONDIENTE

				"add	r9,r8\n\t"		//SUMO EL VALOR DEL DRAWBAR AL DE AMPLITUD

				"strh	r9,[r7, #0]\n\t"//GRABO EN LA TABLA DE AMPLITUD EL RESULTADO DE LA SUMA

							//LOOPEAR ACA A read_switchbox si r4 no es cero aun

				"subs	r4,#1\n\t"
				"bne	read_switchbox\n\t"

				"sub	r3,#9\n\t"			//RESETEO LA POSICION DEL PUNTERO A DRAWBAR
				"b	load_table\n\t"		//ITERAR AL PRINCIPIO

			"exit:\n\t"
			"mov	r7,sp\n\t"

	);


	//register int16_t *activeNotes asm("r4") = &synth_activeNotes;    //Registramos la direccion de memoria de la variable


	return;
}

void atender_sysex()
{
	return;
}

void atender_crash()
{
	//while(1);
	return;
}

void synth_init()
{

	int i;

	//Setear bus de amplitud a cero
	for(i=0;i<79;i++)
		q4q8ampTable[i] = 0;

	for(i=0;i<9;i++)
			synth_Drawbars[i] = 0x0000;


	//Definir estado inicial del sintetizador
	synth_command = COMMAND_SYNTHESIZE;

	//Borrar Notas Activas
	for(i=0;i<16;i++)
			MIDI_activeTable[i] = 0xFF;

	//Resetear los acumuladores de fase
	for(i=0;i<79;i++)
		q12q16phaseTable[i] = 0x0000;

	synth_activeNotes = 0;

	synth_Drawbars[0] = 0xFF;
	synth_Drawbars[1] = 0xFF;
	synth_Drawbars[2] = 0xFF;
	synth_Drawbars[3] = 0xFF;
	synth_Drawbars[4] = 0xFF;
	synth_Drawbars[5] = 0xFF;
	synth_Drawbars[6] = 0xFF;
	synth_Drawbars[7] = 0xFF;
	synth_Drawbars[8] = 0xFF;
	synth_Drawbars[9] = 0xFF;

	//MIDI_activeTable[0] = 0;
	//MIDI_activeTable[1] = 12;
	//MIDI_activeTable[2] = 19;
	//MIDI_activeTable[3] = 22;
	//MIDI_activeTable[9] = 23;
	//MIDI_activeTable[0] = 24;
	//MIDI_activeTable[2] = 31;
	//MIDI_activeTable[3] = 3;
	//MIDI_activeTable[4] = 4;
	//MIDI_activeTable[5] = 5;
	//MIDI_activeTable[6] = 6;
	//MIDI_activeTable[7] = 7;
	//MIDI_activeTable[8] = 8;
	//MIDI_activeTable[9] = 9;
	//MIDI_activeTable[10] = 10;
	//MIDI_activeTable[11] = 11;
	//MIDI_activeTable[12] = 14;

		//MIDI_activeTable[10] = 10;
	//MIDI_activeTable[11] = 11;

	synth_sampleReady = 0;


	//sys_bufferCrash = RESET;

	//Habilitar Timer DAC
	TIM_Cmd(TIM6, ENABLE);

	//Habilitar sampleo Drawbars
	TIM_Cmd(TIM3, ENABLE);

	TIM_Cmd(TIM7, ENABLE);

}
