/* cp.c - DOS Coreutils cp command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
   FILE *source, *target;
   char buffer = 0;
#ifdef HELP
   if(argc == 2 && !strcmp(argv[1], "--help"))
   {
      puts(STRING_CP_DESCRIPTION);
      puts(STRING_CP_USAGE);
      puts("  cp --help|--version\r\n");
      puts(STRING_OPTIONS);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);
      return EXIT_SUCCESS;
   }
#endif

#ifdef VERSION
   if(argc == 2 && !strcmp(argv[1], "--version"))
   {
      version();
      return EXIT_SUCCESS;
   }
#endif

   if(argc == 3)
   {
      source = fopen(argv[1], "rb");
      target = fopen(argv[2], "wb");

      if(!source || !target)
      { 
         fprintf(stderr, STRING_CAN_NOT_COPY, argv[1]);
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

   return EXIT_SUCCESS;
}
