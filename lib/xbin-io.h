/* Binary mode I/O with checking
   Copyright 2017-2018 Free Software Foundation, Inc.

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

#ifndef _XBINARY_IO_H
#define _XBINARY_IO_H

#include "bin-io.h"
#include "errno.h"

#ifndef XBINARY_IO_INLINE
# define XBINARY_IO_INLINE _GL_INLINE
#endif

#if O_BINARY
extern void xset_binary_mode_error (void);
#else
XBINARY_IO_INLINE void xset_binary_mode_error (void) {}
#endif

/* Set the mode of FD to MODE, which should be either O_TEXT or O_BINARY.
   Report an error and exit if this fails.  */

XBINARY_IO_INLINE void
xset_binary_mode (int fd, int mode)
{
  set_binary_mode (fd, mode); // calls setmode
  if(errno != EZERO){
    xset_binary_mode_error ();
  }
}

#endif /* _XBINARY_IO_H */
