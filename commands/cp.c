/*********************************
 * DOS Coreutils cp Command File *
 *********************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
   if(argc == 3 && !strcmp(argv[2], "--help"))
   {
      puts("cp - Copy specified file or directory to specified directory.");
      puts("  cp source destination");
      puts("  cp --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   if(argc == 3 && !strcmp(argv[2], "--version"))
   {
      version();
      return 0;
   }
#endif

   if(argc == 4)
   {
      if(link(argv[2], argv[3]))
      { 
         fprintf(stderr, "%s can\'t copy.\r\n", argv[2]);
      }
   }
   else if(argc < 4)
   {
      fputs("No enough arguments.\r\n", stderr);
   }
   else
   {
      fputs("Too much arguments.\r\n", stderr);
   }

   return 0;
}