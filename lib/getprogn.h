/* Program name management.
   Copyright (C) 2016-2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */
   /* Ported to FreeDOS by LiquidFox1776 */

#ifndef _GL_GETPROGNAME_H
#define _GL_GETPROGNAME_H

#include <stdlib.h>

/* Return the base name of the executing program. */
   
#ifndef HAVE_GETPROGNAME
extern char const *getprogname (void);
#endif
#endif
