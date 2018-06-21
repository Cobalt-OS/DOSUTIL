/******************************************
 * DOS Coreutils beep Command Source File *
 ******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 1;
   int frequency = 750;
   int length = 1000;

#ifdef HELP
   if(!strcmp(argv[i], "--help"))
   {
      puts(STRING_BEEP_DESCRIPTION);
      puts(STRING_BEEP_USAGE);
      puts("  beep --help|--version\r\n");
      puts(STRING_OPTIONS);
      puts(STRING_BEEP_FREQUENCY);
      puts(STRING_BEEP_LENGTH);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);
      return EXIT_SUCCESS;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[i], "--version"))
   {
      version();
      return EXIT_SUCCESS;
   }
#endif

   for(i; i < argc; i++)
   {
      if(!strcmp(argv[i], "-f"))
      {
         i++;

         frequency = atoi(argv[i]);

         continue;
      }

      if(!strcmp(argv[i], "-l"))
      {
         i++;

         length = atoi(argv[i]);
      }
      
      else
      {
         puts(STRING_INVALID_SYNTAX);
         return EXIT_FAILURE;
      }
   }

   sound(frequency);
   delay(length);
   nosound();
   
   return EXIT_SUCCESS;
}
