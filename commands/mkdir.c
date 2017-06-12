/************************************
 * DOS Coreutils mkdir Command File *
 ************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 2;

#ifdef HELP
   if(!strcmp(argv[2], "--help"))
   {
      puts("mkdir - Creates specified directories.");
      puts("  mkdir directories");
      puts("  mkdir --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[2], "--version"))
   {
      version();
      return 0;
   }
#endif

   for(i; i < argc; i++)
   {
      if(mkdir(argv[i], S_IWUSR))
      {
         fprintf(stderr, "%s can't create.\r\n", argv[i]);
      }
   }

   return 0;
}