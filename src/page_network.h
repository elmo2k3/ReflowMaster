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

#ifndef __PAGE_NETWORK_H__
#define __PAGE_NETWORK_H__

#include <stdint.h>
#include "menu.h"

void page_network(struct menuitem *self);
void update_network(struct menuitem *self, uint8_t event);
uint8_t network_button_pressed(struct menuitem *self, uint8_t button);
void network_drehgeber(struct menuitem *self, int8_t steps);
void save_network(void);
void load_network(void);

#endif
