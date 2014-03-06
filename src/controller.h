#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "ioport.h"

#define PIN_BEEPER PIO_PA23_IDX
#define PIN_SSR PIO_PA25_IDX

extern uint8_t heating;

#define MAX_STEPS 2
#define PROFILES 1

struct profile_steps{
    char *phase_name;
    float temperature;
    uint32_t seconds;
    uint8_t temperature_ramp;
    uint8_t start_counting_when_reached;
};

struct profile{
    char *profile_name;
    uint8_t num_steps;
    struct profile_steps steps[MAX_STEPS];
};

extern struct profile profiles[PROFILES];

void controller_init(void);
void controller_tick(void);
void controller_task(void);
void controller_beep_times(int times);
void controller_start_profile(struct profile *prf);
unsigned int controller_current_step_seconds(void);

#endif

