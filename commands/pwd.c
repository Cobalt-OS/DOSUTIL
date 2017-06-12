/***********************************
 * DOS Coreutils pwd Command  File *
 ***********************************/

#include "../dosc.h"

#define MAX_PATH_LENGTH 260

int main(int argc, char *argv[])
{
   char *buffer = (char *)malloc(MAX_PATH_LENGTH);
   
#ifdef HELP
   if(!strcmp(argv[2], "--help"))
   {
      puts("MINIBOX pwd - Creates directory.");
      puts("  MINIBOX pwd");
      puts("  MINIBOX pwd --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   else if(!strcmp(argv[2], "--version"))
   {
      version();
      return 0;
   }
#endif

   else
   {
      puts(getcwd(buffer, MAX_PATH_LENGTH));
   }

   free(buffer);

   return 0;
}