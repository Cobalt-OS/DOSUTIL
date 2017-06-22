CC = wcc
CFLAGS = -0 -s /bt=dos
LD = wlink
UPXFLAGS = -9 --8086 --ultra-brute --crp-ms=999999

all: commands\*.c
	$(CC) $(CFLAGS) commands\beep.c -fo=commands\beep.obj
	$(LD) file commands\beep.obj
	upx $(UPXFLAGS) commands\beep.exe
	
	$(CC) $(CFLAGS) commands\cat.c -fo=commands\cat.obj
	$(LD) file commands\cat.obj
	upx $(UPXFLAGS) commands\cat.exe
	
	$(CC) $(CFLAGS) commands\cd.c -fo=commands\cd.obj
	$(LD) file commands\cd.obj
	upx $(UPXFLAGS) commands\cd.exe
	
	$(CC) $(CFLAGS) commands\clear.c -fo=commands\clear.obj
	$(LD) file commands\clear.obj
	upx $(UPXFLAGS) commands\clear.exe
	
	$(CC) $(CFLAGS) commands\cp.c -fo=commands\cp.obj
	$(LD) file commands\cp.obj
	upx $(UPXFLAGS) commands\cp.exe
	
	$(CC) $(CFLAGS) commands\date.c -fo=commands\date.obj
	$(LD) file commands\date.obj
	upx $(UPXFLAGS) commands\date.exe
	
	$(CC) $(CFLAGS) commands\echo.c -fo=commands\echo.obj
	$(LD) file commands\echo.obj
	upx $(UPXFLAGS) commands\echo.exe
	
	$(CC) $(CFLAGS) commands\help.c -fo=commands\help.obj
	$(LD) file commands\help.obj
	upx $(UPXFLAGS) commands\help.exe
	
	$(CC) $(CFLAGS) commands\ls.c -fo=commands\ls.obj
	$(LD) file commands\ls.obj
	upx $(UPXFLAGS) commands\ls.exe
	
	$(CC) $(CFLAGS) commands\mkdir.c -fo=commands\mkdir.obj
	$(LD) file commands\mkdir.obj
	upx $(UPXFLAGS) commands\mkdir.exe
	
	$(CC) $(CFLAGS) commands\mv.c -fo=commands\mv.obj
	$(LD) file commands\mv.obj
	upx $(UPXFLAGS) commands\mv.exe
	
	$(CC) $(CFLAGS) commands\pwd.c -fo=commands\pwd.obj
	$(LD) file commands\pwd.obj
	upx $(UPXFLAGS) commands\pwd.exe
	
	$(CC) $(CFLAGS) commands\rm.c -fo=commands\rm.obj
	$(LD) file commands\rm.obj
	upx $(UPXFLAGS) commands\rm.exe
	
	$(CC) $(CFLAGS) commands\rmdir.c -fo=commands\rmdir.obj
	$(LD) file commands\rmdir.obj
	upx $(UPXFLAGS) commands\rmdir.exe
	
	$(CC) $(CFLAGS) commands\sh.c -fo=commands\sh.obj
	$(LD) file commands\sh.obj
	upx $(UPXFLAGS) commands\sh.exe
	
	$(CC) $(CFLAGS) commands\time.c -fo=commands\time.obj
	$(LD) file commands\time.obj
	upx $(UPXFLAGS) commands\time.exe
	
clean-obj: commands\*.obj
	del commands\*.obj