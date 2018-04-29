/**********************************
 * DOS Coreutils Main Header File *
 **********************************/

#include <conio.h>
#include <direct.h>
#include <dos.h>
#include <errno.h>
#include <graph.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include "config.h"
#include "lang\en.h"
#include "lang\tr.h"

#ifdef VERSION
void version(void)
{
   puts(DOS_COREUTILS_VERSION);
}
#endif
