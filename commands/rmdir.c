/*******************************************
 * DOS Coreutils rmdir Command Source File *
 *******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 1;

#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(STRING_RMDIR_REMOVE_SPECIFIED_DIRECTORIES);
      puts(STRING_RMDIR_DIRECTORIES);
      puts("  rmdir --help|--version");
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
      if(rmdir(argv[i]))
      {
         fprintf(stderr, STRING_CAN_T_REMOVE, argv[i]);
      }
   }

   return 0;
}
