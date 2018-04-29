/*********************************
 * DOS Coreutils mv Command File *
 *********************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
   if(argc == 2 && !strcmp(argv[1], "--help"))
   {
      puts(MV_MOVE_AND_OR_RENAME_SPECIFIED_FILE_OR_DIRECTORY_TO_SPECIFIED_DIRECTORY_1);
      puts(MV_MOVE_AND_OR_RENAME_SPECIFIED_FILE_OR_DIRECTORY_TO_SPECIFIED_DIRECTORY_2);
      puts(MV_SOURCE_DESTINATION);
      puts("  mv --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   if(argc == 2 && !strcmp(argv[1], "--version"))
   {
      version();
      return 0;
   }
#endif

   if(argc == 3)
   {
      if(rename(argv[1], argv[2]))
      { 
         fprintf(stderr, "%s can\'t move.\r\n", argv[1]);
      }
   }
   else if(argc < 3)
   {
      fputs(NO_ENOUGH_ARGUMENTS, stderr);
   }
   else
   {
      fputs(TOO_MUCH_ARGUMENTS, stderr);
   }

   return 0;
}
