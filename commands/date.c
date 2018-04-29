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
      puts(DATE_PRINT_OR_SET_SYSTEM_DATE_AND_TIME);
      puts(DATE_FORMAT);
      puts(DATE_S_FORMAT);
      puts("  date --help|--version\r\n");
      puts(OPTIONS);
      puts(S_SYSTEM_DATE_AND_TIME);
      puts(FORMAT_SPECIFIY_FORMATTED_OUTPUT_STRING_STRING_FORMAT_IS_C_PRINTF_TYPE);
      puts(EXAMPLE);
      puts(DEFAULT_FORMAT_IS_ISO_TYPE);
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
