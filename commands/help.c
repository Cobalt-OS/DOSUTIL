/* help.c - DOS Coreutils help command source file
   Written by Ercan Ersoy. */

#include "../dosc.h"

#ifdef HELP

int main(void)
{
   puts(STRING_HELP_DOS_COREUTILS_COMMANDS);
   puts("beep");
   puts("cat");
   puts("cd");
   puts("clear");
   puts("cp");
   puts("date");
   puts("dirname");
   puts("echo");
   puts("false");
   puts("ls");
   puts("mkdir");
   puts("mv");
   puts("help");
   puts("pwd");
   puts("rm");
   puts("rmdir");
   puts("sh");
   puts("time");
   puts("true");
   
   return EXIT_SUCCESS;
}

#endif
