CC = wcc
CFLAGS = -0 -bt=DOS -s
LD = wlink

all: commands\*.c
	$(CC) $(CFLAGS) commands\beep.c -fo=commands\beep.obj
	$(LD) file commands\beep.obj
	upx -9 commands\beep.exe
	
	$(CC) $(CFLAGS) commands\cat.c -fo=commands\cat.obj
	$(LD) file commands\cat.obj
	upx -9 commands\cat.exe
	
	$(CC) $(CFLAGS) commands\cd.c -fo=commands\cd.obj
	$(LD) file commands\cd.obj
	upx -9 commands\cd.exe
	
	$(CC) $(CFLAGS) commands\clear.c -fo=commands\clear.obj
	$(LD) file commands\clear.obj
	upx -9 commands\clear.exe
	
	$(CC) $(CFLAGS) commands\cp.c -fo=commands\cp.obj
	$(LD) file commands\cp.obj
	upx -9 commands\cp.exe
	
	$(CC) $(CFLAGS) commands\date.c -fo=commands\date.obj
	$(LD) file commands\date.obj
	upx -9 commands\date.exe
	
	$(CC) $(CFLAGS) commands\echo.c -fo=commands\echo.obj
	$(LD) file commands\echo.obj
	upx -9 commands\echo.exe
	
	$(CC) $(CFLAGS) commands\help.c -fo=commands\help.obj
	$(LD) file commands\help.obj
	upx -9 commands\help.exe
	
	$(CC) $(CFLAGS) commands\ls.c -fo=commands\ls.obj
	$(LD) file commands\ls.obj
	upx -9 commands\ls.exe
	
	$(CC) $(CFLAGS) commands\mkdir.c -fo=commands\mkdir.obj
	$(LD) file commands\mkdir.obj
	upx -9 commands\mkdir.exe
	
	$(CC) $(CFLAGS) commands\mv.c -fo=commands\mv.obj
	$(LD) file commands\mv.obj
	upx -9 commands\mv.exe
	
	$(CC) $(CFLAGS) commands\pwd.c -fo=commands\pwd.obj
	$(LD) file commands\pwd.obj
	upx -9 commands\pwd.exe
	
	$(CC) $(CFLAGS) commands\rm.c -fo=commands\rm.obj
	$(LD) file commands\rm.obj
	upx -9 commands\rm.exe
	
	$(CC) $(CFLAGS) commands\rmdir.c -fo=commands\rmdir.obj
	$(LD) file commands\rmdir.obj
	upx -9 commands\rmdir.exe
	
	$(CC) $(CFLAGS) commands\sh.c -fo=commands\sh.obj
	$(LD) file commands\sh.obj
	upx -9 commands\sh.exe
	
	$(CC) $(CFLAGS) commands\time.c -fo=commands\time.obj
	$(LD) file commands\time.obj
	upx -9 commands\time.exe
	
clean-obj: commands\*.obj
	del commands\*.obj