#include "controller.h"
#include "page_main.h"
#include "thermocouple.h"

#define TICK 1
static uint8_t flags;

uint8_t heating;

void controller_init()
{
	ioport_set_pin_dir(PIN_SSR,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_SSR,0);
	ioport_set_pin_dir(PIN_BEEPER,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_BEEPER,0);
}

void controller_tick()
{
	flags |= TICK;
}

void controller_task()
{
	if(flags & TICK){
		flags &= ~TICK;
		if(settings.on){
			if(temperature_is < settings.temperature){
				heating = 1;
				ioport_set_pin_level(PIN_SSR,1);
			}else{
				heating = 0;
				ioport_set_pin_level(PIN_SSR,1);
			}
		}else{
			heating = 0;
			ioport_set_pin_level(PIN_SSR,0);
		}
	}
}

