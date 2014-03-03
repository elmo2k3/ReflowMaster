#include "controller.h"
#include "settings.h"
#include "thermocouple.h"

#define TICK_1S 1
#define TICK_100MS 2
static uint8_t flags;

uint8_t heating;
uint8_t beep_short;

void controller_beep_short()
{
	beep_short = 1;
}

void controller_init()
{
	ioport_set_pin_dir(PIN_SSR,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_SSR,0);
	ioport_set_pin_dir(PIN_BEEPER,IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIN_BEEPER,0);
}

void controller_tick()
{
	static uint32_t counter = 0;
	static uint8_t beep_off = 0;

	flags |= TICK_100MS;
	if(++counter == 10){ // 1s
		counter = 0;
		flags |= TICK_1S;
	}
	if(beep_short){
		beep_short = 0;
		beep_off = 1;
		ioport_set_pin_level(PIN_BEEPER,1);
	}else if(beep_off){
		beep_off = 0;
		ioport_set_pin_level(PIN_BEEPER,0);
	}		
}
#define DEAD_TIME 30

void controller_task()
{
	float kelvin_per_second;
	static float temperature_is_last;

	if(flags & TICK_1S){
		flags &= ~TICK_1S;
		kelvin_per_second = temperature_is-temperature_is_last;
		if(settings.on){
			if(temperature_is < settings.temperature && 
				(temperature_is+DEAD_TIME*kelvin_per_second < settings.temperature)){
				heating = 1;
				ioport_set_pin_level(PIN_SSR,1);
			}else{
				heating = 0;
				ioport_set_pin_level(PIN_SSR,0);
			}
		}else{
			heating = 0;
			ioport_set_pin_level(PIN_SSR,0);
		}
		temperature_is_last = temperature_is;
	}
}

