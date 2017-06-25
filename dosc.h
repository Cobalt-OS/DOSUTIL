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

#define MAX_COMMAND_LINE_LENGTH 1024
#define MAX_PATH_LENGTH 260

void version(void)
{
   puts("DOS Coreutils Version: 0.3");
}
