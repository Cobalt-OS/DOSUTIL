/****************************************
 * DOS Coreutils sh Command Source File *
 ****************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char *command_line;
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts("sh - DOS Coreuils shell");
      puts("  sh");
      puts("  sh --help|--version\r\n");
      puts("Note:");
      puts("  In DOS Coreutils shell, type \"exit\" to exit shell.");
      return 0;
   }
#endif

#ifdef VERSION
   else if(!strcmp(argv[1], "--version"))
   {
      version();
      return 0;
   }
#endif

   command_line = malloc(MAX_COMMAND_LINE_LENGTH);

   loop:
   printf("\r\n%s", "#");
   gets_s(command_line, MAX_COMMAND_LINE_LENGTH);
   
   if(strcmp(command_line, "exit") && strcmp(command_line, ""))
   {
      system(command_line);
   }
   else if(!strcmp(command_line, "exit"))
   {
      exit(0);
   }

   goto loop;

   return 0;
}
