/******************************************
 * DOS Coreutils date Command Source File *
 ******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   struct dosdate_t date;
   struct dostime_t time;

#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts("date - Print or set system date and time.");
      puts("  date [Format]");
      puts("  date -s [Format]");
      puts("  date --help|--version\r\n");
      puts("Options:");
      puts("-s      Set system date and time.");
      puts("Format  Specify fotmatted output string. String format is C printf type.");
      puts("        Example: \"%d-%d-%d %d:%d%:%d\"");
      puts("        Default format is ISO type.");
      return 0;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[1], "--version"))
   {
      version();
      return 0;
   }
#endif

   if(argc < 2)
   {
      _dos_getdate(&date);
      _dos_gettime(&time);
      printf("%4hu-%2hhu-%2hhu %2hhu:%2hhu:%2hhu", date.year, date.month, date.day, time.hour, time.minute, time.second);
      return 0;
   }
   else
   {
      if(!strcmp(argv[1], "-s"))
      {
         sscanf(argv[2], "%4hu-%2hhu-%2hhu %2hhu:%2hhu:%2hhu", &(date.year), &(date.month), &(date.day), &(time.hour), &(time.minute), &(time.second));
         
         _dos_setdate(&date);
         _dos_settime(&time);
         
         return 0;
      }
      else
      {
         _dos_getdate(&date);
         _dos_gettime(&time);
         printf(argv[1], date.year, date.month, date.day, time.hour, time.minute, time.second);
         return 0;
      }
   }
   
   return 0;
}
