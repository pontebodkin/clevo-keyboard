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
#ifndef TUXEDO_LOGGING_H
#define TUXEDO_LOGGING_H

/* ::::  Module specific Constants and simple Macros   :::: */
#define __TUXEDO_PR(lvl, fmt, ...) do { pr_##lvl(fmt, ##__VA_ARGS__); } while (0)
#define TUXEDO_INFO(fmt, ...) __TUXEDO_PR(info, fmt, ##__VA_ARGS__)
#define TUXEDO_ERROR(fmt, ...) __TUXEDO_PR(err, fmt, ##__VA_ARGS__)
#define TUXEDO_DEBUG(fmt, ...) __TUXEDO_PR(debug, "[%s:%u] " fmt, __func__, __LINE__, ##__VA_ARGS__)

#endif	// TUXEDO_LOGGING_H