# Makefile - DOS Coreutils Makefile
# Written by Ercan Ersoy and LiquidFox1776.
# TODO Implement autodepends

CC = *wcc
CFLAGS = -oneatx -ohirbk -ol -ol+ -oi -ei -zp4 -0 -s -ri -ms /bt=dos
LD = *wlink
LDFLAGS = option eliminate option vfremoval

all: src\base32.exe src\base64.exe src\echo.exe src\false.com src\rmdir.exe src\true.com

src\base64.exe: src\base64.obj lib\base64.obj lib\basenaml.obj lib\bin-io.obj lib\dirnamel.obj lib\error.obj lib\exitfail.obj lib\fcntl.obj lib\getopt.obj lib\getprogn.obj lib\xbin-io.obj lib\xdec2umx.obj lib\xstrtol.obj lib\xstr2umx.obj gl\fadvise.obj gl\xdec2int.obj lib\kitten\kitten.obj lib\lang\lang.obj
        $(LD) $(LDFLAGS) option stack=8192 file {$?} #the stack size must be increased from the default size or a stack overflow will occur

src\base32.exe: src\base32.obj lib\base32.obj lib\basenaml.obj lib\bin-io.obj lib\dirnamel.obj lib\error.obj lib\exitfail.obj lib\fcntl.obj lib\getopt.obj lib\getprogn.obj lib\xbin-io.obj lib\xdec2umx.obj lib\xstrtol.obj lib\xstr2umx.obj gl\fadvise.obj gl\xdec2int.obj lib\kitten\kitten.obj lib\lang\lang.obj
        $(LD) $(LDFLAGS) option stack=8192 file {$?} #the stack size must be increased from the default size or a stack overflow will occur

src\echo.exe: src\echo.obj lib\basenaml.obj lib\getprogn.obj lib\kitten\kitten.obj lib\lang\lang.obj
        $(LD) $(LDFLAGS) file {$?} 

src\false.com: src\false.obj lib\basenaml.obj lib\dirnamel.obj lib\error.obj lib\exitfail.obj lib\fcntl.obj lib\getopt.obj lib\getprogn.obj lib\kitten\kitten.obj lib\lang\lang.obj
        $(LD) $(LDFLAGS) system com file {$?} 

src\rmdir.exe: src\rmdir.obj lib\basenaml.obj lib\dirnamel.obj lib\error.obj lib\exitfail.obj lib\fcntl.obj lib\getopt.obj lib\getprogn.obj lib\stpslash.obj gl\fadvise.obj lib\kitten\kitten.obj lib\lang\lang.obj src\pfprintf.obj
        $(LD) $(LDFLAGS) file {$?}
        
src\true.com: src\true.obj lib\basenaml.obj lib\dirnamel.obj lib\error.obj lib\exitfail.obj lib\fcntl.obj lib\getopt.obj lib\getprogn.obj lib\kitten\kitten.obj lib\lang\lang.obj
        $(LD) $(LDFLAGS) system com file {$?} 

#commands\dirname.com: commands\dirname.obj lib\getopt.obj lib\dirnamel.obj lib\basenaml.obj
#	$(LD) $(LDFLAGS) system com file {$?}

gl\xdec2int.obj: gl\xdec2int.c
    $(CC) $(CFLAGS) $? -fo=$@

gl\fadvise.obj: gl\fadvise.c
    $(CC) $(CFLAGS) $? -fo=$@

gl\xdec2umx.obj: gl\xdec2umx.c
    $(CC) $(CFLAGS) $? -fo=$@

lib\basenaml.obj: lib\basenaml.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\dirnamel.obj: lib\dirnamel.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\getopt.obj: lib\getopt.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\fcntl.obj: lib\fcntl.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\xstrtol.obj: lib\xstrtol.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\base32.obj: lib\base32.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\error.obj: lib\error.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\bin-io.obj: lib\bin-io.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\getprogn.obj: lib\getprogn.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\exitfail.obj: lib\exitfail.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\stpslash.obj: lib\stpslash.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\xbin-io.obj: lib\xbin-io.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\base64.obj: lib\base64.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\xstr2umx.obj: lib\xstr2umx.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\xdec2umx.obj: lib\xdec2umx.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\kitten\kitten.obj: lib\kitten\kitten.c
    $(CC) $(CFLAGS) $? -fo=$@
    
lib\lang\lang.obj: lib\lang\lang.c
    $(CC) $(CFLAGS) $? -fo=$@

src\base32.obj: src\base32.c
	$(CC) $(CFLAGS) $? -fo=$@

src\base64.obj: src\base64.c
	$(CC) $(CFLAGS) $? -fo=$@
    
src\echo.obj: src\echo.c
	$(CC) $(CFLAGS) $? -fo=$@
    
src\false.obj: src\false.c
	$(CC) $(CFLAGS) $? -fo=$@
    
src\pfprintf.obj: src\pfprintf.c
	$(CC) $(CFLAGS) $? -fo=$@

src\rmdir.obj: src\rmdir.c
	$(CC) $(CFLAGS) $? -fo=$@
    
src\true.obj: src\true.c
	$(CC) $(CFLAGS) $? -fo=$@

#commands\dirname.obj: commands\dirname.c
#	$(CC) $(CFLAGS) $? -fo=$@

install: .SYMBOLIC
        #@if exist install\install.bat install\install.bat #execute the installer
        
clean-obj: .SYMBOLIC
	@if exist src\*.obj del src\*.obj
	@if exist lib\*.obj del lib\*.obj
    @if exist gl\*.obj del gl\*.obj
    @if exist lib\kitten\*.obj del lib\kitten\*.obj
    @if exist lib\lang\*.obj del lib\lang\*.obj

clean-all: .SYMBOLIC
	@if exist src\*.obj del src\*.obj
	@if exist lib\*.obj del lib\*.obj
    @if exist gl\*.obj del gl\*.obj
    @if exist lib\kitten\*.obj del lib\kitten\*.obj
    @if exist lib\lang\*.obj del lib\lang\*.obj
    @if exist src\*.exe del src\*.exe
    @if exist src\*.com del src\*.com

