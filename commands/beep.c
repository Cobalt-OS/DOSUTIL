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
      puts(STRING_BEEP_OUTPUT_FROM_PC_SPEAKER);
      puts(STRING_BEEP_OPTIONS);
      puts("  beep --help|--version\r\n");
      puts(STRING_OPTIONS);
      puts(STRING_F_FREQUENCY_SPECIFIY_SOUND_S_FROM_FREQUENCY);
      puts(STRING_LENGTH_SPECFIY_SOUND_S_LENGTH_AS_MILLISECONDS);
      return 0;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[i], "--version"))
   {
      version();
      return 0;
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
         return 1;
      }
   }

   sound(frequency);
   delay(length);
   nosound();
   
   return 0;
}
