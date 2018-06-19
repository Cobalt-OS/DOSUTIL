REM   build.bat build file for DOS-Coreutils
REM   Copyright (C) 1989-2018 Free Software Foundation, Inc.
REM   This program is free software; you can redistribute it and/or
REM   modify it under the terms of the GNU Lesser General Public
REM   License as published by the Free Software Foundation; either
REM   version 3 of the License, or (at your option) any later version.
REM   This program is distributed in the hope that it will be useful,
REM   but WITHOUT ANY WARRANTY; without even the implied warranty of
REM   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
REM   Lesser General Public License for more details.
REM   You should have received a copy of the GNU Lesser General Public
REM   License along with this program; if not, see
REM   <http://www.gnu.org/licenses/>.
REM   Written by LiquidFox1776
@ECHO OFF
CLS

IF "%1"=="clean" GOTO CLEAN

REM Make the library and command files
:MAKE

CD LIB
REM Attempt to make the library files
wmake
IF ERRORLEVEL 1 GOTO ERRLIB

REM Attempt to make the commands
CD ..
wmake
IF ERRORLEVEL 1 GOTO ERRCOMMAND
REM ECHO[ outputs a blank line
ECHO[  
ECHO Build Completed Successfully
GOTO END

:ERRLIB
ECHO[
ECHO Failed to build the library
GOTO END

:ERRCOMMAND
ECHO[
ECHO Failed to build the commands
GOTO END

REM Delete all lib objects, command objects, exe and COM files
:CLEAN
DEL lib\*.obj
DEL commands\*.obj
DEL commands\*.exe
DEL commands\*.com
GOTO MAKE

:END
ECHO[
