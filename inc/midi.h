void midi_startup(void);

extern volatile uint8_t MIDI_buffer[512];

typedef enum {MIDI_NODATA,NOTE_ON,NOTE_OFF,SYSEX_EXCEPTION} MIDIStatus;
