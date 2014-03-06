#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "ioport.h"

#define PIN_BEEPER PIO_PA23_IDX
#define PIN_SSR PIO_PA25_IDX

extern uint8_t heating;

void controller_init(void);
void controller_tick(void);
void controller_task(void);
void controller_beep_times(int times);

#endif

