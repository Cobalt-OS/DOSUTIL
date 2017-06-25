/***********************************
 * DOS Coreutils pwd Command  File *
 ***********************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char *buffer = (char *)malloc(MAX_PATH_LENGTH);
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts("pwd - Creates directory.");
      puts("  pwd");
      puts("  pwd --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   else if(!strcmp(argv[1], "--version"))
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
