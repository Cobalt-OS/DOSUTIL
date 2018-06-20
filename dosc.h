/**********************************
 * DOS Coreutils Main Header File *
 **********************************/

#include <conio.h>
#include <direct.h>
#include <dos.h>
#include <errno.h>
#include <graph.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "lang\en.h"
#include "lang\tr.h"
#include "lib\getopt.h"

#define bool char
#define false 0
#define true 1
#define __DOS__ 1

#ifdef VERSION
void version(void)
{
   puts(STRING_DOS_COREUTILS_VERSION);
}
#endif

enum
{
  GETOPT_HELP_CHAR = (CHAR_MIN - 2),
  GETOPT_VERSION_CHAR = (CHAR_MIN - 3)
};

#define GETOPT_HELP_OPTION_DECL \
  "help", no_argument, NULL, GETOPT_HELP_CHAR
#define GETOPT_VERSION_OPTION_DECL \
  "version", no_argument, NULL, GETOPT_VERSION_CHAR

#define case_GETOPT_HELP_CHAR                   \
  case GETOPT_HELP_CHAR:                        \
    usage (EXIT_SUCCESS);                       \
    break;
    
#define case_GETOPT_VERSION_CHAR                        \
  case GETOPT_VERSION_CHAR:                                             \
    version();                                  \
    exit (EXIT_SUCCESS);                                                \
    break;

#define HELP_OPTION_DESCRIPTION \
        (STRING_HELP_OPTION_DESCRIPTION)
#define VERSION_OPTION_DESCRIPTION \
        (STRING_VERSION_OPTION_DESCRIPTION)

#define emit_try_help()\
        do\
            {\
               fprintf(stderr, STRING_EMIT_TRY_HELP,\
                       PROGRAM_NAME);\
            }\
        while(0)
                
