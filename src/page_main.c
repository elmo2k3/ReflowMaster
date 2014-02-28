/*
 * Copyright (C) 2014 Bjoern Biesenbach <bjoern at bjoern-b.de>
 *               2014 homerj00			<homerj00 at web.de>
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
#include "page_main.h"
#include "page_misc.h"

static uint8_t focus_not_here = 1;
static uint8_t state;

static uint8_t toggle = 0;

struct _settings{
    uint32_t frequency;
    int8_t gain;
}settings;

void page_singletone_settings_init()
{
    settings.frequency = 10e6;
    settings.gain = 8;
}

enum cursor_state {
    STATE_IDLE,
    STATE_FREQUENCY_MHZ,
    STATE_FREQUENCY_KHZ,
    STATE_GAIN
};

void printForwardPower(uint8_t update)
{
    char str[15];
    static int16_t last_val = -1;
    int16_t current_val;

    if (update) {
        last_val = -1;
    }

    if (current_val != last_val) {
        ks0108FillRect(50, 16, 30, 10, WHITE);
        snprintf(str,15, "%d", current_val);
        ks0108SelectFont(1, BLACK);
        ks0108GotoXY(0, 17);
        ks0108Puts(("Forward"));
        ks0108GotoXY(50, 17);
        ks0108Puts(str);
    }
    last_val = current_val;
}

void printReflectPower(uint8_t update)
{
    char str[15];
    static int16_t last_val = -1;
    int16_t current_val;

    if (update) {
        last_val = -1;
    }

    if (current_val != last_val) {
        ks0108FillRect(50, 16 + 10, 30, 10, WHITE);
        snprintf(str,15, "%d", current_val);
        ks0108SelectFont(1, BLACK);
        ks0108GotoXY(0, 17 + 10);
        ks0108Puts(("Reverse"));
        ks0108GotoXY(50, 17 + 10);
        ks0108Puts(str);
    }
    last_val = current_val;
}

void printTransmitPower(uint8_t update)
{
    char str[15];
    static int16_t last_val = -1;
    int16_t current_val;
    if (update) {
        last_val = -1;
    }


    if (current_val != last_val) {
        ks0108FillRect(50, 16 + 20, 30, 10, WHITE);
        snprintf(str,15, "%d", current_val);
        ks0108SelectFont(1, BLACK);
        ks0108GotoXY(0, 17 + 20);
        ks0108Puts(("Received"));
        ks0108GotoXY(50, 17 + 20);
        ks0108Puts(str);
    }
    last_val = current_val;
}

void printGain(uint8_t toggle)
{
    char str[15];
    static uint8_t gain_last = 16;

    if (settings.gain != gain_last) {
        snprintf(str, 15,"v = %02d", settings.gain);
        ks0108SelectFont(3, BLACK);
        ks0108FillRect(93, 28, 34, 20, WHITE);
        ks0108GotoXY(85, 28);
        ks0108Puts(str);
        gain_last = settings.gain;
    } else if (toggle) {
        ks0108FillRect(106, 28, 21, 20, WHITE);
        gain_last = 16;
    }
}

void printFrequencyMhz(uint8_t toggle)
{
    char str[15];
    uint32_t mhz;
    static uint32_t frequency_last = 500000001;

    if (settings.frequency != frequency_last) {
        mhz = settings.frequency / 1000000ul;
        snprintf(str,15, "f = %03ld", mhz);
        ks0108SelectFont(3, BLACK);
        ks0108FillRect(12, 48, 33, 20, WHITE);
        ks0108GotoXY(12, 48);
        ks0108Puts(str);
        frequency_last = settings.frequency;
    } else if (toggle) {
        ks0108FillRect(25, 48, 33, 20, WHITE);
        frequency_last = 500000001;
    }
}

void printFrequencyKhz(uint8_t toggle)
{
    char str[15];
    uint32_t mhz, khz;
    static uint32_t frequency_last = 500000001;

    if (settings.frequency != frequency_last) {
        mhz = settings.frequency / 1000000ul;
        khz = (settings.frequency - mhz * 1000000ul) / 1000ul;
        snprintf(str,15, ".%03ldMHz", khz);
        ks0108SelectFont(3, BLACK);
        ks0108FillRect(60, 48, 66, 20, WHITE);
        ks0108GotoXY(60, 48);
        ks0108Puts(str);
        frequency_last = settings.frequency;
    } else if (toggle) {
        ks0108FillRect(60, 48, 66, 20, WHITE);
        frequency_last = 500000001;
    }
}

void page_singletone(struct menuitem *self)
{

    clear_page_main();
    printGain(1);
    printGain(0);
    printFrequencyMhz(1);
    printFrequencyMhz(0);
    printFrequencyKhz(1);
    printFrequencyKhz(0);
    printForwardPower(1);
    printReflectPower(1);
    printTransmitPower(1);
}


void printBootloader()
{
    clear_page_main();
    ks0108SelectFont(3, BLACK);
    ks0108GotoXY(14, 46);
    ks0108Puts(("Bootloader.."));
}

void update_singletone(struct menuitem *self, uint8_t event)
{

    //clear_page_singletone();
    //
    //tcData = getTcData();

    //frequency = (tcData>>4)&0xFFF;
    //frequency = (tcData>>18)&0x3FFF;
    //frequency = frequency *1000000/4;

    //printFrequencyMhz(0);
    //printFrequencyKhz(0);

    printForwardPower(0);
    printReflectPower(0);
    printTransmitPower(0);
    switch (state) {
    case STATE_FREQUENCY_MHZ:
        printFrequencyMhz(toggle == 0);
        break;
    case STATE_FREQUENCY_KHZ:
        printFrequencyMhz(0);
        printFrequencyKhz(toggle == 0);
        break;
    case STATE_GAIN:
        printFrequencyKhz(0);
        printGain(toggle == 0);
        break;
    default:
        printGain(0);
    }
    if (++toggle == 10)
        toggle = 0;
}

uint8_t singletone_button_pressed(struct menuitem *self, uint8_t button)
{

    toggle = 0;
    if (button == 2) {
        focus_not_here = 0;
        if (state == STATE_IDLE) {
            state = STATE_FREQUENCY_MHZ;
        } else if (state == STATE_FREQUENCY_MHZ) {
            state = STATE_FREQUENCY_KHZ;
        } else if (state == STATE_FREQUENCY_KHZ) {
            state = STATE_GAIN;
        } else if (state == STATE_GAIN) {
            state = STATE_IDLE;
            focus_not_here = 1;
        }
    } else if (button == 2) {
    } else if (button == 4) {
    }

    return focus_not_here;
}

void singletone_drehgeber(struct menuitem *self, int8_t steps)
{

    switch (state) {
    case STATE_GAIN:
        settings.gain += steps;
        if (settings.gain < 0)
            settings.gain = 0;
        if (settings.gain > 15)
            settings.gain = 15;
        printGain(0);
        break;
    case STATE_FREQUENCY_MHZ:
        printFrequencyMhz(0);
        break;
    case STATE_FREQUENCY_KHZ:
        printFrequencyKhz(0);
        break;
    }
}
