/* Header file for lang.c
   Copyright (C) 2004-2018 Free Software Foundation, Inc.
   This file is part of Base64.
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

/* Written by LiquidFox1776 2018*/

#ifndef __LANG_H_INCLUDED
#define __LANG_H_INCLUDED 1
#include <stdbool.h>

extern int open_nls_file(const char *sub_directory, const char *file_name);
extern void close_nls_file(bool from_main_program);
extern char *get_nls_string(int set_number, int message_number, char *message);
#endif /* __LANG_H_INCLUDED */

