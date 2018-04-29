/***********************************
 * DOS Coreutils pwd Command  File *
 ***********************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char *buffer;
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(PWD_OUTPUT_CURRENT_DIRECTORY_S_NAME);
      puts("  pwd");
      puts("  pwd --help|--version");
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

   return 0;
}
