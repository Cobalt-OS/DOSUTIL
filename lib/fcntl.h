/* Partial Implementation of  <fcntl.h>

   Copyright (C) 2006-2018 Free Software Foundation, Inc.

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

/* Written by LiquidFox1776 */

//TODO Not all constants or structs are currently in use but are included in the hopes that they will one day be implemented


#ifndef __FCNTL_H
#define __FCNTL_H 1

#include <sys/types.h>
#include <sys/stat.h>

//*******************************
//We just need some constants from fcntl and not the functions it provides
//
#define open    DO_NOT_USE_open
#define sopen   DO_NOT_USE_sopen
#define _wopen  DO_NOT_USE_wopen
#define _wsopen DO_NOT_USE_wsopen
#define _wcreat DO_NOT_USE_wcreat

#include <fcntl.h>

#undef open
#undef sopen
#undef _wopen
#undef _wsopen
#undef _wcreat
//************************************************************************

#include <io.h>

#define AT_FDCWD -30000
#define F_DUPFD 0 // Return a new file descriptor which shall be the lowest numbered available
#define F_GETFD 1 //Get the file descriptor flags defined in <fcntl.h> that are associated with the file descriptor fildes.
#define F_SETFD 2 //Set the file descriptor flags defined in <fcntl.h>, that are associated with fildes, to the third argument, arg, taken as type int
#define F_GETFL 3 //Get the file status flags and file access modes, defined in <fcntl.h>, for the file description associated with fildes
#define F_SETFL 4 //Set the file status flags, defined in <fcntl.h>, for the file description associated with fildes from the corresponding bits in the third argument, arg, taken as type int
#define FCNTL_ERROR -1 //The value FCNTL should return if an error occurs
#define FSTAT_ERROR -1 //Fstat Error Value
#define O_ACCMODE 0x000F //Mask used to get the file access mode
#define MINIMUM_FILE_HANDLE 0
#define MAXIMUM_FILE_HANDLE 65535 //Maximum file handle for FreeDOS

struct flock{
short  l_type;   //Type of lock; F_RDLCK, F_WRLCK, F_UNLCK.
short  l_whence; //Flag for starting offset.
off_t  l_start; // Relative offset in bytes.
off_t  l_len;    //Size; if 0 then until EOF.
pid_t  l_pid;    //Process ID of the process holding the lock; returned with F_GETLK.
};

//extern int  creat(const char *, mode_t); defined in <io.h>
//extern int  open(const char *, int, ...); defined in <io.h>

extern int fcntl(int fildes, int cmd, ...);


//TODO Optional Functions
//int  posix_fadvise(int, off_t, off_t, int);
//int  posix_fallocate(int, off_t, off_t);

#endif // __FCNTL_H


