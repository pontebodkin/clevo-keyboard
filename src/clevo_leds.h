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

#ifndef CLEVO_LEDS_H
#define CLEVO_LEDS_H

#include <linux/types.h>
#include <linux/platform_device.h>
#include <linux/leds.h>
#include <linux/string.h>
#include <linux/led-class-multicolor.h>
#include <linux/delay.h>

#include "clevo_interfaces.h"
#include "tuxedo_logging.h"
#include "tuxedo_keyboard_colours.h"

#define CLEVO_KBD_BRIGHTNESS_MAX                    0xff
#define CLEVO_KBD_BRIGHTNESS_DEFAULT                0x00

#define CLEVO_KBD_BRIGHTNESS_WHITE_MAX              0x02 // White only keyboards can only be off, half, or full brightness
#define CLEVO_KBD_BRIGHTNESS_WHITE_DEFAULT          0x00

#define CLEVO_KBD_BRIGHTNESS_WHITE_MAX_5            0x05 // Devices <= Intel 7th gen had a different white control with 5 brightness values + off
#define CLEVO_KBD_BRIGHTNESS_WHITE_MAX_5_DEFAULT    0x00

// WHITE
#define CLEVO_KB_COLOR_DEFAULT_RED      0xff
#define CLEVO_KB_COLOR_DEFAULT_GREEN    0xff
#define CLEVO_KB_COLOR_DEFAULT_BLUE     0xff
#define CLEVO_KB_COLOR_DEFAULT			((CLEVO_KB_COLOR_DEFAULT_RED << 16) + (CLEVO_KB_COLOR_DEFAULT_GREEN << 8) + CLEVO_KB_COLOR_DEFAULT_BLUE)

enum clevo_kb_backlight_types {
	CLEVO_KB_BACKLIGHT_TYPE_NONE = 0x00,
	CLEVO_KB_BACKLIGHT_TYPE_FIXED_COLOR = 0x01,
	CLEVO_KB_BACKLIGHT_TYPE_3_ZONE_RGB = 0x02,
	CLEVO_KB_BACKLIGHT_TYPE_1_ZONE_RGB = 0x06,
	CLEVO_KB_BACKLIGHT_TYPE_PER_KEY_RGB = 0xf3
};

enum clevo_kb_backlight_types clevo_leds_get_backlight_type(void);

int clevo_leds_init(struct platform_device *dev);
int clevo_leds_suspend(struct platform_device *dev);
int clevo_leds_resume(struct platform_device *dev);
int clevo_leds_remove(struct platform_device *dev);

void clevo_leds_restore_state_extern(void);
void clevo_leds_notify_brightness_change_extern(void);
void clevo_leds_set_brightness_extern(enum led_brightness brightness);
void clevo_leds_set_color_extern(u32 color);
void clevo_leds_toggle_on_off(void);

MODULE_LICENSE("GPL");

#endif // CLEVO_LEDS_H
