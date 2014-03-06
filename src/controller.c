#include "controller.h"
#include "settings.h"
#include "thermocouple.h"

#define TICK_1S 1
#define TICK_100MS 2
#define DEAD_TIME 30
static uint8_t flags;

uint8_t heating;
uint8_t beep_times;

struct profile profiles[] = {
	{"Profile 1",2,
		{{"Preheating",50.0,10,0,1},
		{"Solder",100.0,10,0,1}}}
};

static struct profile *active_profile;
static unsigned int profile_step_number;
static unsigned int profile_step_seconds;
static bool profile_running;

unsigned int controller_current_step_seconds()
{
	return profile_step_seconds;
}

void controller_start_profile(struct profile *prf)
{
	if(!prf) return;

	active_profile = prf;
	profile_step_number = 0;
	profile_step_seconds = 0;
	profile_running = 1;
	settings.on = 1;
}

void controller_beep_times(int times)
{
	beep_times = times;
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
	if(beep_times > 0 && !beep_off){
		beep_times--;
		beep_off = 1;
		ioport_set_pin_level(PIN_BEEPER,1);
	}else{
		beep_off = 0;
		ioport_set_pin_level(PIN_BEEPER,0);
	}		
}

static void controller_temperature_task(void)
{
	float kelvin_per_second;
	static float temperature_is_last;

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

static void controller_profile_task(void)
{
	if(profile_running){
		if(profile_step_seconds == 0){
			settings.temperature = active_profile->steps[profile_step_number].temperature;
		}
		if(settings.temperature < (temperature_is+3.0) && 
			settings.temperature > (temperature_is-10.0)){
			profile_step_seconds++;
		}
		if(profile_step_seconds >= active_profile->steps[profile_step_number].seconds){
			profile_step_number++;
			profile_step_seconds = 0;
		}
		if(profile_step_number == active_profile->num_steps){
			profile_running = 0;
			settings.on = 0;
			controller_beep_times(5);
		}
	}
}

void controller_task()
{

	if(flags & TICK_1S){
		flags &= ~TICK_1S;
		controller_temperature_task();
		controller_profile_task();
	}
}

