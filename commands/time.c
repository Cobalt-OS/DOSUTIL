/***********************************
 * DOS Coreutils time Command File *
 ***********************************/

#include "../dosc.h"

#define MAX_COMMAND_LINE_LENGTH 1024

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
      puts("time - Measure specified command's execution time as second.");
      puts("  time command [argument]");
      puts("  time --help|--version");
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

      printf("%.2llf", measured_time);
   }
   else
   {
      puts("No enough arguments.");
   }
   
   return 0;
}
