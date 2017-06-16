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
      puts("mkdir - Creates specified directories.");
      puts("  mkdir directories");
      puts("  mkdir --help|--version");
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
      if(mkdir(argv[i]))
      {
         fprintf(stderr, "%s can't create.\r\n", argv[i]);
      }
   }

   return 0;
}
