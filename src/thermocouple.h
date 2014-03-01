#ifndef __THERMOCOUPLE_H__
#define __THERMOCOUPLE_H__

extern float temperature_is;
extern uint8_t temperature_valid;

void thermocouple_init(void);
void thermocouple_task(void);

#endif
