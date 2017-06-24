CC = wcc
CFLAGS = -oneatx -ohirbk -ol -ol+ -oi -ei -zp4 -0 -s -ri -ms /bt=dos
LD = wlink
LDFLAGS = option eliminate option vfremoval
UPXFLAGS = -9 --8086 --ultra-brute --crp-ms=999999

all: commands\beep.com commands\cat.com commands\cd.com commands\clear.exe commands\cp.com commands\date.com commands\echo.com commands\help.com commands\ls.exe commands\mkdir.com commands\mv.com commands\pwd.com commands\rm.com commands\rmdir.com commands\sh.com commands\time.exe

commands\beep.com: commands\beep.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\cat.com: commands\cat.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\cd.com: commands\cd.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\clear.exe: commands\clear.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\cp.com: commands\cp.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\date.com: commands\date.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\echo.com: commands\echo.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\help.com: commands\help.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\ls.exe: commands\ls.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\mkdir.com: commands\mkdir.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\mv.com: commands\mv.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\pwd.com: commands\pwd.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\rm.com: commands\rm.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\rmdir.com: commands\rmdir.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@
	
commands\sh.com: commands\sh.obj
	$(LD) $(LDFLAGS) system com file $?
	upx $(UPXFLAGS) $@

commands\time.exe: commands\time.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

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

commands\echo.obj: commands\echo.c
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

clean-obj: .SYMBOLIC
	@if exist commands\*.obj del commands\*.obj