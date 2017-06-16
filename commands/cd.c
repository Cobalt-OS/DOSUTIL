/****************************************
 * DOS Coreutils cd Command Source File *
 ****************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   if(argc == 2)
   {
      if(chdir(argv[1]))
      {
         fprintf(stderr, "%s doesn't directory.\r\n", argv[3]);
         return 1;
      }
   }
   
   return 0;
}
