/*********************************
 * DOS Coreutils cd Command File *
 *********************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   if(argc == 3)
   {
      if(chdir(argv[2]))
      {
         fprintf(stderr, "%s doesn't directory.\r\n", argv[3]);
         return 1;
      }
   }
   
   return 0;
}