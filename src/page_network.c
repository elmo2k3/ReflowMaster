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
#include <math.h>
#include <stdio.h>

#include "menu.h"
#include "page_misc.h"
#include "ks0108/ks0108.h"
#include "page_network.h"
#include "settings.h"

static uint8_t state;
static enum cursor_state {
    STATE_IDLE,
    STATE_FREQUENCY_START,
    STATE_FREQUENCY_STOP
};

void draw_frequency_start(void)
{
    char f_val[20];

    if(settings.net.dhcp){
        strcpy(f_val,"DHCP");
    }else{
        strcpy(f_val,"Static");
    }
    draw_settings_line_variable_space("Configuration",f_val,0,80);
    snprintf(f_val,20,"%03d.%03d.%03d.%03d",settings.net.ip1,settings.net.ip2,
    settings.net.ip3,settings.net.ip4); 
    draw_settings_line_variable_space(("Address"),f_val,1,60);
    snprintf(f_val,20,"%03d.%03d.%03d.%03d",settings.net.netmask1,settings.net.netmask2,
    settings.net.netmask3,settings.net.netmask4); 
    draw_settings_line_variable_space(("Netmask"),f_val,2,60);
    snprintf(f_val,20,"%03d.%03d.%03d.%03d",settings.net.gw1,settings.net.gw2,
    settings.net.gw3,settings.net.gw4); 
    draw_settings_line_variable_space(("Gateway"),f_val,3,60);
}

void page_network(struct menuitem *self)
{
    clear_page_main();
    ks0108SelectFont(1, BLACK);
    draw_frequency_start();
}

void update_network(struct menuitem *self, uint8_t event)
{
}

uint8_t network_button_pressed(struct menuitem *self, uint8_t button)
{
    return 1;
    if(button != 4){
        return state!=0;
    }
    if (state == STATE_IDLE) {
        state = STATE_FREQUENCY_START;
        draw_arrow(90, 20);
    } else if (state == STATE_FREQUENCY_START) {
        state = STATE_FREQUENCY_STOP;
        ks0108FillRect(90, 17, 5, 10, WHITE);
        draw_arrow(90, 31);
    } else if (state == STATE_FREQUENCY_STOP) {
        state = STATE_IDLE;
        ks0108FillRect(90, 17, 5, 10, WHITE);
        ks0108FillRect(90,28,5,10,WHITE);
        return 1;
    }
    return 0;
}

void network_drehgeber(struct menuitem *self, int8_t steps)
{
}
