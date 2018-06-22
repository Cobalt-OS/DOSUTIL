/* time.c - DOS Coreutils time command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 0;
   char *command_line;
   struct dostime_t start;
   struct dostime_t end;
   long double measured_time = 0.0;

#ifdef HELP
   if(argc == 2 && !strcmp(argv[1], "--help"))
   {
      puts(STRING_TIME_DESCRIPTION);
      puts(STRING_TIME_ARGUMENTS);
      puts("  time --help|--version");
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

   if(argc > 1)
   {
      command_line = malloc(MAX_COMMAND_LINE_LENGTH);

      strcpy(command_line, argv[1]);

      if(argc > 2)
      {
         for(i = 2; i < argc; i++)
         {
            strcat(command_line, " ");
            strcat(command_line, argv[i]);
         }
      }

      _dos_gettime(&start);
      system(command_line);
      _dos_gettime(&end);
      measured_time = (long double)(((end.second - start.second) * 100 + end.hsecond) - start.hsecond) / 100;

      printf("%.2Lf", measured_time);
   }
   else
   {
      fprintf(stderr, STRING_NO_ENOUGH_ARGUMENTS);
   }
   
   return EXIT_SUCCESS;
}
