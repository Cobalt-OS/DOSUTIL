CC = *wcc
CFLAGS = -oneatx -ohirbk -ol -ol+ -oi -ei -zp4 -0 -s -ri -ms /bt=dos
LD = *wlink
LDFLAGS = option eliminate option vfremoval

all: commands\beep.com commands\cat.com commands\cd.com commands\clear.exe commands\cp.com commands\date.com commands\dirname.com commands\echo.com commands\false.com commands\help.com commands\ls.exe commands\mkdir.com commands\mv.com commands\pwd.com commands\rm.com commands\rmdir.com commands\sh.com commands\time.exe commands\true.com

commands\beep.com: commands\beep.obj
        $(LD) $(LDFLAGS) system com file $?

commands\cat.com: commands\cat.obj
        $(LD) $(LDFLAGS) system com file $?

commands\cd.com: commands\cd.obj
        $(LD) $(LDFLAGS) system com file $?

commands\clear.exe: commands\clear.obj
        $(LD) $(LDFLAGS) file $?

commands\cp.com: commands\cp.obj
        $(LD) $(LDFLAGS) system com file $?

commands\date.com: commands\date.obj
        $(LD) $(LDFLAGS) system com file $?

commands\dirname.com: commands\dirname.obj lib\getopt.obj lib\dirnamel.obj lib\basenaml.obj
        $(LD) $(LDFLAGS) system com file {$?}

commands\echo.com: commands\echo.obj
        $(LD) $(LDFLAGS) system com file $?

commands\false.com: commands\false.obj
        $(LD) $(LDFLAGS) system com file $?

commands\help.com: commands\help.obj
        $(LD) $(LDFLAGS) system com file $?

commands\ls.exe: commands\ls.obj
        $(LD) $(LDFLAGS) file $?

commands\mkdir.com: commands\mkdir.obj
        $(LD) $(LDFLAGS) system com file $?

commands\mv.com: commands\mv.obj
        $(LD) $(LDFLAGS) system com file $?

commands\pwd.com: commands\pwd.obj
        $(LD) $(LDFLAGS) system com file $?

commands\rm.com: commands\rm.obj
        $(LD) $(LDFLAGS) system com file $?

commands\rmdir.com: commands\rmdir.obj
        $(LD) $(LDFLAGS) system com file $?
        
commands\sh.com: commands\sh.obj
        $(LD) $(LDFLAGS) system com file $?

commands\time.exe: commands\time.obj
        $(LD) $(LDFLAGS) file $?

commands\true.com: commands\true.obj
        $(LD) $(LDFLAGS) system com file $?

commands\beep.obj: commands\beep.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\cat.obj: commands\cat.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\cd.obj: commands\cd.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\clear.obj: commands\clear.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\cp.obj: commands\cp.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\date.obj: commands\date.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\dirname.obj: commands\dirname.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\echo.obj: commands\echo.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\false.obj: commands\false.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\help.obj: commands\help.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\ls.obj: commands\ls.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\mkdir.obj: commands\mkdir.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\mv.obj: commands\mv.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\pwd.obj: commands\pwd.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\rm.obj: commands\rm.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\rmdir.obj: commands\rmdir.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\sh.obj: commands\sh.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\time.obj: commands\time.c
        $(CC) $(CFLAGS) $? -fo=$@

commands\true.obj: commands\true.c
        $(CC) $(CFLAGS) $? -fo=$@

clean-obj: .SYMBOLIC
        @if exist commands\*.obj del commands\*.obj
