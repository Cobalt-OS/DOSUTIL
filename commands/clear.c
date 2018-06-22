/* clear.c - DOS Coreutils clear command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(STRING_CLEAR_DESCRIPTION);
      puts("  clear");
      puts("  clear --help|--version\r\n");
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

   _clearscreen(_GCLEARSCREEN);

   return EXIT_SUCCESS;
}
