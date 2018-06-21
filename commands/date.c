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
      puts(STRING_DATE_DESCRIPTION);
      puts(STRING_DATE_USAGE_1);
      puts(STRING_DATE_USAGE_2);
      puts("  date --help|--version\r\n");
      puts(STRING_OPTIONS);
      puts(STRING_DATE_SET_TIME_AND_DATE);
      puts(STRING_DATE_FORMAT);
      puts(STRING_DATE_EXAMPLE_FORMAT);
      puts(STRING_DATE_DEFAULT_FORMAT);
      puts(STRING_HELP_OPTION_DESCRIPTION);
      puts(STRING_VERSION_OPTION_DESCRIPTION);

      return EXIT_SUCCESS;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[1], "--version"))
   {
      version();

      return EXIT_SUCCESS;
   }
#endif

   if(argc < 2)
   {
      _dos_getdate(&date);
      _dos_gettime(&time);
      printf("%4hu-%2hhu-%2hhu %2hhu:%2hhu:%2hhu", date.year, date.month, date.day, time.hour, time.minute, time.second);

      return EXIT_SUCCESS;
   }
   else
   {
      if(!strcmp(argv[1], "-s"))
      {
         sscanf(argv[2], "%4hu-%2hhu-%2hhu %2hhu:%2hhu:%2hhu", &(date.year), &(date.month), &(date.day), &(time.hour), &(time.minute), &(time.second));
         
         _dos_setdate(&date);
         _dos_settime(&time);
         
         return EXIT_SUCCESS;
      }
      else
      {
         _dos_getdate(&date);
         _dos_gettime(&time);
         printf(argv[1], date.year, date.month, date.day, time.hour, time.minute, time.second);

         return EXIT_SUCCESS;
      }
   }
   
   return EXIT_SUCCESS;
}
