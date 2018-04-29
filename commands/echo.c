/******************************************
 * DOS Coreutils echo Command Source File *
 ******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
   char backslash_escapes = 0;
   char new_line = 1;
   int i = 1;
   int parameter_length = 0;
   int j = 0;
   char character;

#ifdef HELP
   if(!strcmp(argv[1], "--help"))
   {
      puts(ECHO_PRINT_SPECIFIED_MESSAGES);
      puts(ECHO_OPTIONS_MESSAGES);
      puts("  echo --help|--version\r\n");
      puts(OPTIONS);
      puts(E_PRINTS_SPECIAL_CHARACTERS_MESSAGE_MUST_BE_QUOTED);
      puts(CHARACTERS_ARE);
      puts(IN_ADDITION_PRINTS_NEWLINE_CHARACTER);
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

   if(!strcmp(argv[1], "-e"))
   {
      backslash_escapes = 1;
      if(!strcmp(argv[2], "-n"))
      {
         new_line = 0;
         i = 3;
      }
      else
      {
         i = 2;
      }  
   }

   if(!strcmp(argv[1], "-n"))
   {
      new_line = 0;
      if(!strcmp(argv[2], "-e"))
      {
         backslash_escapes = 1;
         i = 3;
      }
      else
      {
         i = 2;
      }  
   }

   for(i; i < argc; i++)
   {
      parameter_length = strlen(argv[i]);

      for(j = 0; j < parameter_length; j++)
      {
         if(backslash_escapes && argv[i][j] == '\\')
         {
            j++;

            if(argv[i][j] == '\\')
            {
               character = '\\';
            }
            else if(argv[i][j] == 'a')
            {
               character = '\a';
            }
            else if(argv[i][j] == 'b')
            {
               character = '\b';
            }
            else if(argv[i][j] == 'c')
            {
               return 0;
            }
            else if(argv[i][j] == 'e')
            {
               character = 27;
            }
            else if(argv[i][j] == 'f')
            {
               character = '\f';
            }
            else if(argv[i][j] == 'n')
            {
               character = '\n';
            }
            else if(argv[i][j] == 'r')
            {
               character = '\r';
            }
            else if(argv[i][j] == 't')
            {
               character = '\t';
            }
            else if(argv[i][j] == 'v')
            {
               character = '\v';
            }
            /*else if(argv[i][j] == '0')   FIX ME!
            {
               
            }
            else if(argv[i][j] == 'x')     FIX ME!
            {
               
            }*/
            else
            {
               j--;

               continue;
            }
         }
         else
         {
            character = argv[i][j];
         }

         putchar(character);
      }

         if((i + 1) != argc)
         {
            putchar(' ');
         }
   }

   if(!new_line)
   {
      putchar('\r');
      putchar('\n');
   }

   return 0;
}
