void midi_startup(void);
void midi_test();

typedef enum
{
	MIDI_NODATA,
	NOTE_ON,
	NOTE_OFF,
	SYSEX_EXCEPTION
} midiStatus_t;
