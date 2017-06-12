/************************************
 * DOS Coreutils clear Command File *
 ************************************/

#include "../dosc.h"

int command_clear(int argc, char *argv[])
{
#ifdef HELP
      if(!strcmp(argv[2], "--help"))
      {
         puts("clear - Output sound from PC speaker.");
         puts("  clear");
         puts("  clear --help|--version\r\n");
         return 0;
      }
#endif

#ifdef VERSION
      if(!strcmp(argv[2], "--version"))
      {
         version();
         return 0;
      }
#endif

   clrscr();

   return 0;
}