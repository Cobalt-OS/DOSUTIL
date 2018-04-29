/*******************************************
 * DOS Coreutils mkdir Command Source File *
 *******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 1;

#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(MKDIR_CREATES_SPECIFIED_DIRECTORIES);
      puts(MKDIR_DIRECTORIES);
      puts("  mkdir --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[1], "--version"))
   {
      version();
      return 0;
   }
#endif

   for(i; i < argc; i++)
   {
      if(mkdir(argv[i]))
      {
         fprintf(stderr, CAN_T_CREATE, argv[i]);
      }
   }

   return 0;
}
