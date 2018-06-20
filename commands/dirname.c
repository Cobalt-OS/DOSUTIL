/* dirname -- strip suffix from file name
   Copyright (C) 1990-2018 Free Software Foundation, Inc.
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

/* Written by David MacKenzie and Jim Meyering. */
/* Ported to FreeDOS by LiquidFox1776 */

#include "..\dosc.h"
#include "..\lib\dirname.h"

/* The official name of this program (e.g., no 'g' prefix).  */
#define PROGRAM_NAME "dirname"

static struct option const longopts[] =
{
  {"zero", no_argument, NULL, 'z'},
  {GETOPT_HELP_OPTION_DECL},
  {GETOPT_VERSION_OPTION_DECL},
  {NULL, 0, NULL, 0}
};

void
usage (int status)
{
   if(status != EXIT_SUCCESS)
    {
        emit_try_help ();
    }
   else
    {
      printf (STRING_DIRNAME_USAGE, PROGRAM_NAME);
      fputs (STRING_DIRNAME_DESCRIPTION, stdout);
      fputs (STRING_DIRNAME_ARGUMENTS, stdout);
      fputs (HELP_OPTION_DESCRIPTION, stdout);
      fputs (VERSION_OPTION_DESCRIPTION, stdout);
      printf (STRING_DIRNAME_EXAMPLES, PROGRAM_NAME, PROGRAM_NAME, PROGRAM_NAME);
    }
  exit (status);
}

int
main (int argc, char **argv)
{
  static char const dot = '.';
  bool use_nuls = false;
  char const *result;
  size_t len;

  while (true)
    {
      int c = getopt_long (argc, argv, "z", longopts, NULL);

      if (c == -1)
        break;

      switch (c)
        {
        case 'z':
          use_nuls = true;
          break;

        case_GETOPT_HELP_CHAR;
        case_GETOPT_VERSION_CHAR;

        default:
          usage (EXIT_FAILURE);
        }
    }

  if (argc < optind + 1)
    {
      puts(STRING_MISSING_OPERAND);
      usage (EXIT_FAILURE);
    }

  for (; optind < argc; optind++)
    {
      result = argv[optind];
      len = dir_len (result);

      if (! len)
        {
          result = &dot;
          len = 1;
        }

      fwrite (result, 1, len, stdout);
      putchar (use_nuls ? '\0' :'\n');
    }

  return EXIT_SUCCESS;
}
