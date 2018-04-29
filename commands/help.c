/******************************************
 * DOS Coreutils help Command Source File *
 ******************************************/

#include "../dosc.h"

#ifdef HELP

int main(void)
{
   puts(DOS_COREUTILS_COMMANDS);
   puts("beep");
   puts("cat");
   puts("cd");
   puts("clear");
   puts("cp");
   puts("date");
   puts("echo");
   puts("ls");
   puts("mkdir");
   puts("mv");
   puts("help");
   puts("pwd");
   puts("rm");
   puts("rmdir");
   puts("sh");
   puts("time");
   
   return 0;
}

#endif
