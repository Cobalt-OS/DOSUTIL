/************************************
 * DOS Coreutils rmdir Command File *
 ************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 1;

#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts("MINIBOX main - Removes specified directories.");
      puts("  MINIBOX main directories");
      puts("  MINIBOX main --help|--version");
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
      if(rmdir(argv[i]))
      {
         fprintf(stderr, "%s can\'t remove.\r\n", argv[i]);
      }
   }

   return 0;
}
