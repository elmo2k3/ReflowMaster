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

#ifndef __PAGE_MAIN_H__
#define __PAGE_MAIN_H__

#include "menu.h"

struct _settings{
    int32_t temperature;
    int32_t on;
};

extern struct _settings settings;

void update_main(struct menuitem *self, uint8_t event);
void page_main(struct menuitem *self);
uint8_t main_button_pressed(struct menuitem *self, uint8_t button);
void main_drehgeber(struct menuitem *self, int8_t steps);

void page_main_settings_init(void);

#endif
