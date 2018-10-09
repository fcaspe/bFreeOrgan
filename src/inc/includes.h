#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_syscfg.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_dac.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "misc.h"

#include "defines.h"
#include "midi.h"
#include "timer.h"
#include "synth.h"
#include "boot.h"

extern char sys_TXbuff[TX_BUFFOUT];
extern uint16_t sys_DACbuffer1[32];
extern uint16_t sys_DACbuffer0[32];
uint16_t *sys_DACcurrent;
extern uint16_t sys_sampleSent;
extern FlagStatus sys_bufferPending;
extern FlagStatus sys_bufferCrash;
