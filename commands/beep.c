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
      puts("beep - Output sound from PC speaker.");
      puts("  beep [options]");
      puts("  beep --help|--version\r\n");
      puts("Options:");
      puts("  -f Frequency: Specify sound's frequency.");
      puts("  -l Length: Specify sound's length as milliseconds.");
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
         puts("Invalid syntax.");
         return 1;
      }
   }

   sound(frequency);
   delay(length);
   nosound();
   
   return 0;
}
