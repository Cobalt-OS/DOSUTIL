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
      puts(STRING_RMDIR_DESCRIPTION);
      puts(STRING_RMDIR_USAGE);
      puts("  rmdir --help|--version");
      puts(STRING_OPTIONS);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);

      return EXIT_SUCCESS;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[1], "--version"))
   {
      version();

      return EXIT_SUCCESS;
   }
#endif

   for(i; i < argc; i++)
   {
      if(rmdir(argv[i]))
      {
         fprintf(stderr, STRING_RMDIR_CAN_NOT_REMOVE, argv[i]);
      }
   }

   return EXIT_SUCCESS;
}
