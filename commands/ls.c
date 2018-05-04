/****************************************
 * DOS Coreutils ls Command Source File *
 ****************************************/

#include "../dosc.h"

void path_current_directory(char *path)
{
   getcwd(path, MAX_PATH_LENGTH);
}

int main(int argc, char *argv[])
{
   int i = 1;
   char *path;
   DIR *directory;
   struct dirent *element;
   struct stat status;
   char one_column = 0;
   char do_not_ignore = 0;
   char long_listing = 0;
   short column_1 = 0;
   short column_2 = 0;
   unsigned char longest_name_length = 0;
   unsigned char column_count = 0;
   unsigned char column_size = 0;
   int j = 0;

   if(argc > 1)
   {
#ifdef HELP
      if(!strcmp(argv[1], "--help"))
      {
         puts(STRING_LS_LIST_DIRECTORY_CONTENTS);
         puts(STRING_LS_OPTIONS_FILE);
         puts("  ls --help|--version\r\n");
         puts(STRING_OPTIONS);
         puts(STRING__DISPLAY_OUTPUT_AS_ONE_COLUMN);
         puts(STRING_A_DON_T_IGNORE_AND);
         puts(STRING_L_DISPLAY_LONG_LISTING_FORMAT);
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

      path = malloc(MAX_PATH_LENGTH);

      for(i; i < argc; i++)
      {
         if(!strcmp(argv[i], "-1"))
         { 
            one_column = 1;
            path_current_directory(path);
            continue;
         }

         if(!strcmp(argv[i], "-a"))
         { 
            do_not_ignore = 1;
            path_current_directory(path);
            continue;
         }

         if(!strcmp(argv[i], "-l"))
         { 
            long_listing = 1;
            path_current_directory(path);
            continue;
         }

         path = argv[i];
      }
   }
   else
   {
      path_current_directory(path);
   }

   directory = opendir(path);
   if(directory)
   {
      if(one_column)
      {
         while(element = readdir(directory))
         {
            if(!do_not_ignore && (!strcmp(element->d_name, ".") || !strcmp(element->d_name, "..")))
            {
               continue;
            }

            puts(element->d_name);
         }
      }
      else if(long_listing)
      {
         while(element = readdir(directory))
         {
            stat(element->d_name, &status);
            if(!do_not_ignore && (!strcmp(element->d_name, ".") || !strcmp(element->d_name, "..")))
            {
               continue;
            }

            if(S_ISDIR(status.st_mode))
            {
               printf("d ");
            }
            else
            {
               printf("  ");
            }
			printf("%16d " ,status.st_size);
			puts(element->d_name);
         }
      }
      else
      {
         _gettextwindow(NULL, &column_1, NULL, &column_2);
		 
		 column_2 += column_1;
         
         while(element = readdir(directory))
         {
            if(!do_not_ignore && (!strcmp(element->d_name, ".") || !strcmp(element->d_name, "..")))
            {
               continue;
            }
            
            if(longest_name_length < strlen(element->d_name))
            {
               longest_name_length = strlen(element->d_name);
            }
         }

         column_count = column_2 / (longest_name_length + 2);
         if(column_count == 0)
         {
            column_count = 1;
         }

         column_size = column_2 / column_count;

         rewinddir(directory);

         i = 0;
         
         while(element = readdir(directory))
         {
            if(!do_not_ignore && (!strcmp(element->d_name, ".") || !strcmp(element->d_name, "..")))
            {
               continue;
            }

            printf("%s", element->d_name);
            for(j = strlen(element->d_name); j < column_size - 1; j++)
            {
               printf(" ");
            }

            i++;
            if(i == column_count)
            {
               printf("\r\n");
               i = 0;
            }
         }
      }
   }

   free(path);

   return 0;
}
