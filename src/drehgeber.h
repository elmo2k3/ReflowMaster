#ifndef __DREHGEBER_H__
#define __DREHGEBER_H__

#include <stdint.h>
#include "ioport.h"
// inits timer0

#define DREHGEBER_A PIO_PA22_IDX
#define DREHGEBER_B PIO_PA21_IDX

#define PHASE_B ioport_get_pin_level(DREHGEBER_B)
#define PHASE_A ioport_get_pin_level(DREHGEBER_A)

void drehgeber_init(void);
void drehgeber_work(void);      //call every 1ms
int8_t drehgeber_read(void);    // read four step encoders

#endif
