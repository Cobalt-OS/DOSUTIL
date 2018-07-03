/* Binary mode I/O.
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

#define BINARY_IO_INLINE _GL_EXTERN_INLINE
#include "bin-io.h"
# include "errno.h"
# include <io.h>


int
__gl_setmode_check (int fd)
{
return 0;
  /*if (isatty(fd))
    {
      errno = EINVAL;
      return -1;
    }
 else
    return 0;*/
}

