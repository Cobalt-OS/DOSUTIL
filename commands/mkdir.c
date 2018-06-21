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
      puts(STRING_MKDIR_DESCRIPTION);
      puts(STRING_MKDIR_USAGE);
      puts("  mkdir --help|--version");
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
      if(mkdir(argv[i]))
      {
         fprintf(stderr, STRING_MKDIR_CAN_NOT_CREATE_DIRECTORY, argv[i]);

         return EXIT_FAILURE;
      }
   }

   return EXIT_SUCCESS;
}
