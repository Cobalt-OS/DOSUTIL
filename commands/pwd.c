/* pwd.c - DOS Coreutils pwd command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char *buffer;
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(STRING_PWD_DESCRIPTION);
      puts("  pwd");
      puts("  pwd --help|--version");
      puts(STRING_OPTIONS);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);
   }
#endif

#ifdef VERSION
   else if(!strcmp(argv[1], "--version"))
   {
      version();
   }
#endif

   else
   {
      buffer = (char *)malloc(MAX_PATH_LENGTH);

      puts(getcwd(buffer, MAX_PATH_LENGTH));

      free(buffer);
   }

   return EXIT_SUCCESS;
}
