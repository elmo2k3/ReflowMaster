/*
 * Copyright (C) 2014 Bjoern Biesenbach <bjoern at bjoern-b.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <string.h>
#include <stdio.h>
#include "ks0108/ks0108.h"
#include "buttons.h"
#include "page_misc.h"
#include "controller.h"
#include "thermocouple.h"
#include "settings.h"

static uint8_t focus_not_here = 1;
static uint8_t state;

static uint8_t toggle = 0;

enum cursor_state {
    STATE_IDLE,
    STATE_TEMPERATURE
};

static void printTemperatureIs(uint8_t update)
{
    char str[15];
    static int16_t last_val = -1;
    int16_t current_val;

    if (update) {
        last_val = -1;
    }
    
    current_val = temperature_is;

    if (current_val != last_val) {
        ks0108SelectFont(1, BLACK);
        ks0108GotoXY(0, 17);
        ks0108Puts("Temperature is:");
        ks0108FillRect(85, 16, 42, 18, WHITE);
        ks0108GotoXY(85, 17);
        if(current_val > 1000){
            snprintf(str,15, "ERR");
        }else{
            snprintf(str,15, "%03dC", current_val);
        }
        ks0108SelectFont(3, BLACK);
        ks0108Puts(str);
    }
    last_val = current_val;
}

static void printTemperatureSet(uint8_t toggle)
{
    char str[15];
    static int16_t last_val = -1;
    int16_t current_val;

    current_val = settings.temperature;

    if (current_val != last_val) {
        ks0108SelectFont(1, BLACK);
        ks0108GotoXY(0, 17 + 20);
        ks0108Puts("Temperature set:");
        ks0108FillRect(85, 16 + 18, 37, 18, WHITE);
        ks0108GotoXY(85, 17 + 18);
        snprintf(str,15, "%03dC", current_val);
        ks0108SelectFont(3, BLACK);
        ks0108Puts(str);
        last_val = current_val;
    }else if(toggle){
        ks0108FillRect(85, 16 + 18, 42, 20, WHITE);
        last_val = -1; // force redraw next time
    }
}

static void printOn(uint8_t on)
{
    if(on){
        ks0108SelectFont(1, BLACK);
        ks0108GotoXY(90, 55);
        ks0108Puts("ON");
    }else{
        ks0108FillRect(90,55,57,10,WHITE);
    }
}

static void printHeating(uint8_t on)
{
    char buf[10];
    static unsigned int last_val = 1024;
    unsigned int current_val;

    current_val = controller_current_step_seconds();
    if(current_val != last_val){
        ks0108SelectFont(1, BLACK);
        snprintf(buf,10,"%d",controller_current_step_seconds());
        ks0108FillRect(0,55,57,10,WHITE);
        ks0108GotoXY(0, 55);
        ks0108Puts(buf);
        last_val = current_val;
    }else{
    }
}

void page_profile(struct menuitem *self)
{

    clear_page_main();
    printTemperatureIs(1);
    printTemperatureIs(0);
    printTemperatureSet(1);
    printTemperatureSet(0);
}


void update_profile(struct menuitem *self, uint8_t event)
{
    printTemperatureIs(0);
    printTemperatureSet(0);
    printHeating(1);
    printOn(settings.on);
    switch (state) {
    case STATE_TEMPERATURE:
        printTemperatureSet(toggle == 0);
        break;
    }
    if (++toggle == 10)
        toggle = 0;
}

uint8_t profile_button_pressed(struct menuitem *self, uint8_t button)
{

    toggle = 0;
    if(button == 1){
        controller_start_profile(&profiles[0]);
    }else if (button == 2) {
        focus_not_here = 0;
        if (state == STATE_IDLE) {
            state = STATE_TEMPERATURE;
        } else if (state == STATE_TEMPERATURE) {
            state = STATE_IDLE;
            focus_not_here = 1;
        }
    } else if (button == 3) {
    }

    return focus_not_here;
}

void profile_drehgeber(struct menuitem *self, int8_t steps)
{

    switch (state) {
    case STATE_TEMPERATURE:
        settings.temperature += steps;
        if (settings.temperature < 20)
            settings.temperature = 20;
        if (settings.temperature > 260)
            settings.temperature = 260;
        settings.temperature;
        printTemperatureSet(0);
        break;
    }
}
