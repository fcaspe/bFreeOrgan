/*
 * synth.h
 *
 *  Created on: Jul 12, 2017
 *      Author: franco
 */

typedef uint16_t q4q8_t;
typedef uint32_t q12q16_t;

#ifdef SYNTH_C
#include "sine_wave.h"
#include "calibration.h"
#endif

q4q8_t ampTable[79];
q4q8_t ampTableCurrent[79];
q4q8_t ampFirDelayLine[316];
q12q16_t phaseTable[79];
uint8_t midiActiveTable[16];
uint8_t Drawbars[9];

typedef enum
	{
	SAMPLE_NODATA,
	SAMPLE_WRITTEN,
	SAMPLE_PENDING,
	SAMPLE_CRASH
	} sampleStatus_t;

typedef enum
	{
	BUFFER_NODATA,
	BUFFER_WRITTEN,
	BUFFER_PENDING,
	BUFFER_CRASH
	} bufferStatus_t;

typedef enum
	{
	COMMAND_SYNTHESIZE,
	COMMAND_MENU
	} synthStatus_t;


sampleStatus_t write_sample(uint16_t sample);
void synth_FSM();
void synth_init();
void atender_crash();


