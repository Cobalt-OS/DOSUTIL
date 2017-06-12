/**********************************
 * DOS Coreutils Main Header File *
 **********************************/

#include <conio.h>
#include <dirent.h>
#include <dos.h>
#include <errno.h>
#include <stdio.h>
#include <pc.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>
#include "config.h"

void version(void)
{
   puts("DOS Coreutils Version: 0.1");
}