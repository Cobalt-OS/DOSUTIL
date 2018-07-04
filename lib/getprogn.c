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

/* Specification.  */
#include "getprogn.h"
#include "errno.h" /* get program_invocation_name declaration */
#include <stdlib.h> /* get __argv declaration */
#include "dirname.h"

#ifndef HAVE_GETPROGNAME
#define HAVE_GETPROGNAME 1
char const *
getprogname (void)
{
#ifndef PROGRAM_NAME
return "";
#else
 return PROGRAM_NAME;
#endif
}

#endif

/*
 * Hey Emacs!
 * Local Variables:
 * coding: utf-8
 * End:
 */
