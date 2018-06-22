/* false.c - DOS Coreutils false command source file
   Written by LiquidFox1776. */

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
    if(!strcmp(argv[1], "--help"))
    {
        puts(STRING_FALSE_DESCRIPTION);
        puts("  false");
        puts("  false --help|--version\r\n");
        puts(STRING_OPTIONS);
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

   return EXIT_FAILURE;
}
