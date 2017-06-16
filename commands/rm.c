/*********************************
 * DOS Coreutils rm Command File *
 *********************************/

#include "../dosc.h"

char item_remove(char *removing_item_path)
{
   DIR *element;
   struct dirent *item_properties;
   char *item_name = malloc(256);
   char *item_path = malloc(260);

   element = opendir(removing_item_path);
   item_properties = readdir(element);
   item_name = item_properties->d_name;

   while(item_name[0] != 1)
   {
      if(strcmp(item_name, ".") && strcmp(item_name, "..") && (strlen(item_path) + strlen(removing_item_path) <= 258))
      {
         strcpy(item_path, removing_item_path);
         strcat(item_path, "\\");
         strcat(item_path, item_name);
         if(remove(item_path))
         {
            item_remove(item_path);
         }
      }
      
      item_properties = readdir(element);
	  item_name = item_properties->d_name;
   }
   
   closedir(element);
   free(item_name);
   free(item_path);
   
   return rmdir(removing_item_path);
}

int main(int argc, char *argv[])
{
   int i = 1;
   
#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts("rm - Removes files.");
      puts("  rm [-r] items");
      puts("  rm --help|--version\r\n");
      puts("Option:");
      puts("-r  Remove specified directories and their contents recusively.");
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[1], "--version"))
   {
      version();
   }
#endif
   if(!strcmp(argv[1], "-r") && argc > 2)
   {
      for(i = 2; i < argc; i++)
      {
         if(item_remove(argv[i]))
         {
            fprintf(stderr, "%s can't remove.", argv[i]);
         }
      }
   }
   else
   {
      for(i; i < argc; i++)
      {
         if(remove(argv[i]))
         {
            fprintf(stderr, "%s can't remove.\r\n", argv[i]);
         }
      }
   }
   
   return 0;
}
