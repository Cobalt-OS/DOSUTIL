/* sh.c - DOS Coreutils sh command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char *command_line;
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(STRING_SH_DESCRIPTION);
      puts("  sh");
      puts("  sh --help|--version\r\n");
      puts(STRING_OPTIONS);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);
      puts(STRING_NOTE);
      puts(STRING_SH_TYPE_EXIT);

      return EXIT_SUCCESS;
   }
#endif

#ifdef VERSION
   else if(!strcmp(argv[1], "--version"))
   {
      version();

      return EXIT_SUCCESS;
   }
#endif

   command_line = (char *) malloc(MAX_COMMAND_LINE_LENGTH);

   loop:

   printf("\r\n#");
   fgets(command_line, MAX_COMMAND_LINE_LENGTH, stdin);

   if(!strcmp(command_line, "exit\n"))
   {
      exit(EXIT_SUCCESS);
   }
   else if(strcmp(command_line, "\n"))
   {
      system(command_line);
   }

   goto loop;

   return EXIT_SUCCESS;
}
