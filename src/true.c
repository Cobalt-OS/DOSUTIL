/* Exit with a status code indicating success.
   Copyright (C) 1999-2018 Free Software Foundation, Inc.
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */
   /* Ported to FreeDOS by LiquidFox1776 */

#include "..\config.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.c>
#include "..\lib\error.h"

#include "system.h"

/* Act like "true" by default; false.c overrides this.  */
#ifndef EXIT_STATUS
# define EXIT_STATUS EXIT_SUCCESS
#endif

#if EXIT_STATUS == EXIT_SUCCESS
# define PROGRAM_NAME "true"
#else
# define PROGRAM_NAME "false"
#endif

#define AUTHORS "Jim Meyering"

void
usage (int status)
{
  char *nls_string = get_nls_string(0,1,"Usage: %s [ignored command line arguments]\r\n  or:  %s OPTION\r\n");
  
 printf (nls_string, program_name, program_name);
  if(EXIT_STATUS == EXIT_SUCCESS)
      nls_string = get_nls_string(0,2,"Exit with a status code indicating success.");
  else
      nls_string = get_nls_string(0,2,"Exit with a status code indicating failure.");
  printf ("%s\r\n\r\n", nls_string);          
  fputs (HELP_OPTION_DESCRIPTION, stdout);
  fputs("\n", stdout);
  fputs (VERSION_OPTION_DESCRIPTION, stdout);
  //emit_ancillary_info (PROGRAM_NAME);
  close_nls_file(true);
  exit (status);
}

int
main (int argc, char **argv)
{
  /* Recognize --help or --version only if it's the only command-line
     argument.  */
     open_nls_file("", PROGRAM_NAME);
  if (argc == 2)
    {
      if (STREQ (argv[1], "--help"))
        usage (EXIT_STATUS);

      if (STREQ (argv[1], "--version"))
        version(PROGRAM_NAME, AUTHORS);
    }
   
  close_nls_file(true);
  return EXIT_STATUS;
}

