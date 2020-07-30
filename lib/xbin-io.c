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

#define XBINARY_IO_INLINE _GL_EXTERN_INLINE
#include "lang\lang.h"
#include "errno.h"
#include "xbin-io.h"
#include "error.h"
#include <stdbool.h>
#include "exitfail.h"
#include "verify.h"

//#include "gettext.h"
//#define _(msgid) gettext (msgid)

//#if O_BINARY

void
xset_binary_mode_error (void)
{
  open_nls_file("lib", "xbin-io");
  error (exit_failure, errno,_(get_nls_string(0,0,"failed to set file descriptor text/binary mode")));
  close_nls_file(false);
  assume (false);
}

//#endif
