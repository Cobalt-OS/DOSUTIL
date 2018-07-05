/* dosc.h - DOS Coreutils main header file
   Some of the code is given below from GNU Coreutils.
   Written the other by Ercan Ersoy and LiquidFox1776. */

#include <conio.h>
#include <direct.h>
#include <dos.h>
#include <errno.h>
#include <graph.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "lang\en.h"
#include "lang\fr.h"
#include "lang\tr.h"
#include "lib\getopt.h"

#define __DOS__ 1
#define _(String) String

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
            
static inline void
emit_stdin_note (void)
{
  fputs (_(STRING_EMIT_STDIN_NOTE), stdout);
}
static inline void
emit_mandatory_arg_note (void)
{
  fputs (_(STRING_EMIT_MANDATORY_ARG_NOTE), stdout);
}

#define STREQ(a, b) (strcmp (a, b) == 0)

#ifndef MAX
# define MAX(a, b) ((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

