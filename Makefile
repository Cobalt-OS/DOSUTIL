CC = wcc
CFLAGS = -oneatx -ohirbk -ol -ol+ -oi -ei -zp4 -0 -s -ri -ms /bt=dos
LD = wlink
LDFLAGS = option eliminate option vfremoval
UPXFLAGS = -9 --8086 --ultra-brute --crp-ms=999999

all: commands\beep.exe commands\cat.exe commands\cd.exe commands\clear.exe commands\cp.exe commands\date.exe commands\echo.exe commands\help.exe commands\ls.exe commands\mkdir.exe commands\mv.exe commands\pwd.exe commands\rm.exe commands\rmdir.exe commands\sh.exe commands\time.exe

commands\beep.exe: commands\beep.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\cat.exe: commands\cat.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\cd.exe: commands\cd.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\clear.exe: commands\clear.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\cp.exe: commands\cp.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\date.exe: commands\date.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\echo.exe: commands\echo.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\help.exe: commands\help.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\ls.exe: commands\ls.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\mkdir.exe: commands\mkdir.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\mv.exe: commands\mv.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\pwd.exe: commands\pwd.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\rm.exe: commands\rm.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@

commands\rmdir.exe: commands\rmdir.obj
	$(LD) $(LDFLAGS) file $?
	upx $(UPXFLAGS) $@
	
commands\sh.exe: commands\sh.obj
	$(LD) $(LDFLAGS) file $?
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