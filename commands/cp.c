/****************************************
 * DOS Coreutils cp Command Source File *
 ****************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   FILE *source, *target;
   char buffer = 0;
#ifdef HELP
   if(argc == 2 && !strcmp(argv[1], "--help"))
   {
      puts("cp - Copy specified file or directory to specified directory.");
      puts("  cp source destination");
      puts("  cp --help|--version");
      return 0;
   }
#endif

#ifdef VERSION
   if(argc == 2 && !strcmp(argv[1], "--version"))
   {
      version();
      return 0;
   }
#endif

   if(argc == 3)
   {
      source = fopen(argv[1], "rb");
      target = fopen(argv[2], "wb");

      if(!source || !target)
      { 
         fprintf(stderr, "%s can\'t copy.\r\n", argv[1]);
      }

      while((buffer = fgetc(source)) != 255 && !feof(source))
      {
         printf("%d %d\n", buffer, !feof(source));
         fputc(buffer, target);
      }

      fclose(target);
      fclose(source);

   }
   else if(argc < 3)
   {
      fputs("No enough arguments.\r\n", stderr);
   }
   else
   {
      fputs("Too much arguments.\r\n", stderr);
   }

   return 0;
}
