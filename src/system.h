/* system.h - FreeDOS Coreutils main header file
   Some of the code is given below from GNU Coreutils.
   Written by LiquidFox1776. */

#include "..\config.h"
#include "..\lib\lang\lang.h" /* Kitten Wrapper */
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define __DOS__ 1
#define _(String) String
extern void version(const char *prog_name, const char *authors);

void
version(const char *prog_name, const char *authors)
{
   printf("\n%s - %s\n", prog_name, authors);
}


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
    
#define case_GETOPT_VERSION_CHAR(Program_name, Authors)                        \
  case GETOPT_VERSION_CHAR:                                             \
    version(Program_name, Authors);                                  \
    exit (EXIT_SUCCESS);                                                \
    break;

#define HELP_OPTION_DESCRIPTION \
        ("  --help: Display this help and exit.")
#define VERSION_OPTION_DESCRIPTION \
        ("  --version: Display version information and exit.")

#define emit_try_help()\
        do\
            {\
               open_nls_file("","system-h");\
               fprintf(stderr, get_nls_string(0,2,"Try line '%s --help' for more information.\r\n"),\
                       program_name);\
                close_nls_file(false);\
            }\
        while(0)
            
static inline void
emit_stdin_note (void)
{
  open_nls_file("","system-h");
  fputs (get_nls_string(0,1,"\r\nWith no FILE, or when FILE is -, read standard input.\r\n"), stdout);
  close_nls_file(false);
}
static inline void
emit_mandatory_arg_note (void)
{
  fputs (_("\r\nMandatory arguments to long options are mandatory for short options too.\r\n"), stdout);
}

#define STREQ(a, b) (strcmp (a, b) == 0)

#ifndef MAX
# define MAX(a, b) ((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
# define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

