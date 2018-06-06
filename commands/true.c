/*******************************************
 * DOS Coreutils true Command Source File *
 *******************************************/

#include "../dosc.h"

int main(int argc, char *argv[])
{
#ifdef HELP
    if(!strcmp(argv[1], "--help"))
    {
        puts(STRING_TRUE_RETURN_TRUE);
        puts("  true");
        puts("  true --help|--version\r\n");
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

   

   return EXIT_SUCCESS;
}
