/***********************************
 * DOS Coreutils time Command File *
 ***********************************/

#include "../dosc.h"

#define MAX_COMMAND_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
   int i = 0;
   char *command_line = alloca(MAX_COMMAND_LINE_LENGTH);
   struct timeval start;
   struct timeval end;
   long double measured_time = 0.0;

#ifdef HELP
   if(argc == 3 && !strcmp(argv[2], "--help"))
   {
      puts("time - Measure specified command's execution time as second.");
      puts("  time command [argument]");
      puts("  time --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   if(argc == 3 && !strcmp(argv[2], "--version"))
   {
      version();
      return 0;
   }
#endif

   if(argc > 2)
   {
      strcpy(command_line, argv[2]);

      if(argc > 3)
      {
         for(i = 3; i < argc; i++)
         {
            strcat(command_line, " ");
            strcat(command_line, argv[i]);
         }
      }

      gettimeofday(&start, NULL);
      system(command_line);
      gettimeofday(&end, NULL);
      measured_time = (long double)(((end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec) - start.tv_usec) / 1000000;

      printf("%llf", measured_time);
   }
}