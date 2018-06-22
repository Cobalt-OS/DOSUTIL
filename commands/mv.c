/* mv.c - DOS Coreutils mv command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
   if(argc == 2 && !strcmp(argv[1], "--help"))
   {
      puts(STRING_MV_DESCRIPTION_1);
      puts(STRING_MV_DESCRIPTION_2);
      puts(STRING_MV_USAGE);
      puts("  mv --help|--version");
      puts(STRING_OPTIONS);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);

      return EXIT_SUCCESS;
   }
#endif

#ifdef VERSION
   if(argc == 2 && !strcmp(argv[1], "--version"))
   {
      version();

      return EXIT_SUCCESS;
   }
#endif

   if(argc == 3)
   {
      if(rename(argv[1], argv[2]))
      { 
         fprintf(stderr, STRING_MV_CAN_NOT_MOVE, argv[1]);
      }
   }
   else if(argc < 3)
   {
      fputs(STRING_NO_ENOUGH_ARGUMENTS, stderr);
   }
   else
   {
      fputs(STRING_TOO_MUCH_ARGUMENTS, stderr);
   }

   return EXIT_SUCCESS;
}
