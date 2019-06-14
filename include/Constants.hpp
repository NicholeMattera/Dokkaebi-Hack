/*
 * Dokkaebi Hack
 * Copyright (c) 2019 Steven Mattera
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <switch.h>

#pragma once

namespace DokkaebiHack {
    typedef enum {
        BUTTON_HELD_EVENT = BIT(0),
        BUTTON_DOWN_EVENT = BIT(1),
        BUTTON_UP_EVENT = BIT(2)
    } EventTypes;

    typedef enum {
        ROMFS_SERVICE = BIT(0),
        SDL_SERVICE = BIT(1),
        SDL_IMG_SERVICE = BIT(2)
    } Services;
}
