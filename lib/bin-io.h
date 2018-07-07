/* Binary mode I/O.
   Copyright (C) 2001, 2003, 2005, 2008-2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */
   /* Ported to FreeDOS by LiquidFox1776 */

#ifndef _BINARY_H
#define _BINARY_H
#include "const.h"

/* For systems that distinguish between text and binary I/O.
   O_BINARY is guaranteed by the gnulib <fcntl.h>. */
#include "fcntl.h" // includes <io.h>

/* The MSVC7 <stdio.h> doesn't like to be included after '#define fileno ...',
   so we include it here first.  */
#include <stdio.h>

#ifndef BINARY_IO_INLINE
#define BINARY_IO_INLINE _GL_INLINE
#endif

#define __gl_setmode setmode

extern int __gl_setmode_check (int);

/* Set FD's mode to MODE, which should be either O_TEXT or O_BINARY.
   Return the old mode if successful, -1 (setting errno) on failure.
   Ordinarily this function would be called 'setmode', since that is
   its name on MS-Windows, but it is called 'set_binary_mode' here
   to avoid colliding with a BSD function of another name.  */

BINARY_IO_INLINE int
set_binary_mode (int fd, int mode)
{
  int r = __gl_setmode_check (fd);
  return r != 0 ? r : __gl_setmode (fd, mode);
}

/* This macro is obsolescent.  */
#define SET_BINARY(fd) ((void) set_binary_mode (fd, O_BINARY))


#endif /* _BINARY_H */
