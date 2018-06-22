/****************************************
 * DOS Coreutils cd Command Source File *
 ****************************************/
/* cd.c - DOS Coreutils cd command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
   if(argc == 2)
   {
      if(chdir(argv[1]))
      {
         fprintf(stderr, STRING_DOES_NOT_DIRECTORY, argv[3]);

         return EXIT_FAILURE;
      }
   }
   
   return EXIT_SUCCESS;
}
