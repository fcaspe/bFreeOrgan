/*
 * synth.h
 *
 *  Created on: Jul 12, 2017
 *      Author: franco
 */

#define MIDI_NOTE_OFFSET 36 //OFFSET DE LA NOTA MAS BAJA DEL TECLADO DE NUESTRO ORGANO

extern const int16_t wave_sine[TABLE_BUFF];
extern const uint8_t switchbox[459];
extern const uint32_t qstep[79];


extern uint16_t q4q8ampTable[79]; //Bus de amplitud en formato Q4.8
extern uint32_t q12q16phaseTable[79];
extern uint8_t MIDI_activeTable[16];
extern uint8_t synth_Drawbars[9];

//extern uint16_t wav_sqr[TABLE_BUFF];
//extern uint16_t wav_tri[TABLE_BUFF];

extern const uint32_t qstep[79];


typedef enum {SAMPLE_NODATA,SAMPLE_WRITTEN,SAMPLE_PENDING,SAMPLE_CRASH} sampleStatus;

typedef enum {BUFFER_NODATA,BUFFER_WRITTEN,BUFFER_PENDING,BUFFER_CRASH} bufferStatus;

typedef enum {COMMAND_SYNTHESIZE,COMMAND_MENU} synthStatus;


sampleStatus write_sample(uint16_t sample);
void atender_crash();

