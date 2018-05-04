/****************************************
 * DOS Coreutils cp Command Source File *
 ****************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   FILE *source, *target;
   char buffer = 0;
#ifdef HELP
   if(argc == 2 && !strcmp(argv[1], "--help"))
   {
      puts(STRING_CP_COPY_SPECIFIED_FILE_OR_DIRECTORY_TO_SPECIFIED_DIRECTORY);
      puts(STRING_CP_SOURCE_DESTINATION);
      puts("  cp --help|--version");
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
      source = fopen(argv[1], "rb");
      target = fopen(argv[2], "wb");

      if(!source || !target)
      { 
         fprintf(stderr, STRING_CAN_T_COPY, argv[1]);
      }

      while((buffer = fgetc(source)) != 255 && !feof(source))
      {
         printf("%d %d\n", buffer, !feof(source));
         fputc(buffer, target);
      }

      fclose(target);
      fclose(source);

   }
   else if(argc < 3)
   {
      fputs(STRING_NO_ENOUGH_ARGUMENTS, stderr);
   }
   else
   {
      fputs(STRING_TOO_MUCH_ARGUMENTS, stderr);
   }

   return 0;
}
