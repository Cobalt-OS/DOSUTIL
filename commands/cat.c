/**********************************
 * DOS Coreutils cat Command File *
 **********************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   int i = 1;
   char read_buffer;
   FILE *file_resource;
   unsigned char show_ends = 0;
   unsigned char show_tabs = 0; 

#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(STRING_CAT_OUTPUT_SPECIFIED_FILE_S_CONTENTS);
      puts(STRING_CAT_OPTIONS_FILE);
      puts("  cat --help|--version\r\n");
      puts(STRING_OPTIONS);
      puts(STRING_E_ENDS_ARE_SHOWN_AS);
      puts(STRING_T_TABS_ARE_SHOWN_AS);
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

   for(i; i < argc; i++)
   {
      if(!strcmp(argv[i], "-E"))
      {
         show_ends = 1;
      }

      if(!strcmp(argv[i], "-T"))
      {
         show_tabs = 1;
      }
   }

   file_resource = fopen(argv[1], "r");

   
   while(!feof(file_resource))
   {
      read_buffer = fgetc(file_resource);
      if(show_ends && read_buffer == '\n')
      {
         putchar('$');
      }

      if(show_tabs && read_buffer == '\t')
      {
         puts("^I");
         continue;
      }

      putchar(read_buffer);
   }

   fclose(file_resource);

   return 0;
}
