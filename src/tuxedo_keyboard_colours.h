/*!
 * Copyright (c) 2018-2020 TUXEDO Computers GmbH <tux@tuxedocomputers.com>
 *
 * This file is part of tuxedo-keyboard.
 *
 * tuxedo-keyboard is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef TUXEDO_KEYBOARD_COLOURS_H
#define TUXEDO_KEYBOARD_COLOURS_H

struct color_t {
	u32 code;
	char* name;
};

struct color_list_t {
	uint size;
	struct color_t colors[];
};

/**
 * Commonly used standard colors
 */
static struct color_list_t color_list = {
	.size = 11,
	.colors = {
		{ .name = "BLACK",    .code = 0x000000 },  // 0
		{ .name = "RED",      .code = 0xFF0000 },  // 1
		{ .name = "GREEN",    .code = 0x00FF00 },  // 2
		{ .name = "BLUE",     .code = 0x0000FF },  // 3
		{ .name = "YELLOW",   .code = 0xFFFF00 },  // 4
		{ .name = "MAGENTA",  .code = 0xFF00FF },  // 5
		{ .name = "CYAN",     .code = 0x00FFFF },  // 6
		{ .name = "WHITE",    .code = 0xFFFFFF },  // 7
		{ .name = "DUCKEGG",  .code = 0x19C864 },  // 8
		{ .name = "PURPLE",   .code = 0x320F64 },  // 9
		{ .name = "GOLD",     .code = 0xe0b643 },  // 10
	}
};

#endif	// TUXEDO_KEYBOARD_COLOURS
