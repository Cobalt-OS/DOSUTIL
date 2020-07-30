/* Partial implementation of some file descriptor control.

   Copyright (C) 2009-2018 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by LiquidFox1776*/

#include "fcntl.h"
#include <stdarg.h>
#include "errno.h"

int dupfd(int original_handle, int starting_handle); // duplicates a file handle
int getfl(int handle); // Get file access mode

int
fcntl(int fildes, int cmd, ...){
int ret;

va_list argument_pointer;
va_start(argument_pointer, cmd); //Initialize the argument list

switch(cmd){
case F_DUPFD :
    ret =  dupfd(fildes, va_arg (argument_pointer, int)); // a_arg (argument_pinter, int) should point to a int containing what could be a new handle
    break;
case F_GETFL :
    ret =  getfl(fildes);
    break;
default: //Invalid Command(or not yet implemented)
    errno = EINVAL;
    ret =  FCNTL_ERROR;
}
va_end(argument_pointer); // Cleanup
return ret;
}

int
getfl(int handle){

struct stat status_buffer;
int file_access_mode;
int tmp_ret;

tmp_ret = fstat(handle, &status_buffer);
if( tmp_ret == FSTAT_ERROR ){//An error has occurred
        return FCNTL_ERROR;
}

//get the file access mode
switch(status_buffer.st_mode){
    case S_IRWXU : //Read and Write Access
        file_access_mode |= O_RDWR;
        break;
    case S_IRUSR : //Read Access
        file_access_mode |= O_RDONLY;
        break;
    case S_IWUSR : // Write Access
        file_access_mode |= O_WRONLY;
        break;
    default :
        break;
}

return file_access_mode;
}

int
dupfd(int original_handle, int starting_handle){
int tmp_ret;// A temporary return value
struct stat status_buffer;//Stores the stat structure which contains information about a file handle
unsigned int d_handle;//Stores the next available handle that can(or cant) be duplicated

if(starting_handle < MINIMUM_FILE_HANDLE){
    errno = EINVAL; //File handles cant be negative
    return FCNTL_ERROR;
}

for(d_handle = starting_handle; d_handle <= MAXIMUM_FILE_HANDLE; ++d_handle){
    tmp_ret = fstat( d_handle, &status_buffer);
    if( tmp_ret == FSTAT_ERROR ){//An error has occurred which means that the handle does not exist(free to use) or it is out of range(should not occur)
        if( dup2(original_handle, d_handle) == 0){//No errors occurred
           errno = EZERO;
           return d_handle;
        }
        else {//An error has occurred
            errno = EINVAL;
            return FCNTL_ERROR;
           }
        }
    }
//If we get to here we are our at the MAXIMUM_FILE_HANDLE limit and cannot go beyond that point
errno = EMFILE;
return FCNTL_ERROR;
}
