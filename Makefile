all:
	wcc -0 -s commands\beep.c -fo=commands\beep.obj
	wlink file commands\beep.obj
	upx -9 commands\beep.exe
	
	wcc -0 -s commands\cat.c -fo=commands\cat.obj
	wlink file commands\cat.obj
	upx -9 commands\cat.exe
	
	wcc -0 -s commands\cd.c  -fo=commands\cd.obj
	wlink file commands\cd.obj
	upx -9 commands\cd.exe
	
	wcc -0 -s commands\clear.c -fo=commands\clear.obj
	wlink file commands\clear.obj
	upx -9 commands\clear.exe
	
	wcc -0 -s commands\cp.c  -fo=commands\cp.obj
	wlink file commands\cp.obj
	upx -9 commands\cp.exe
	
	wcc -0 -s commands\date.c  -fo=commands\date.obj
	wlink file commands\date.obj
	upx -9 commands\date.exe
	
	wcc -0 -s commands\echo.c  -fo=commands\echo.obj
	wlink file commands\echo.obj
	upx -9 commands\echo.exe
	
	wcc -0 -s commands\ls.c  -fo=commands\ls.obj
	wlink file commands\ls.obj
	upx -9 commands\ls.exe
	
	wcc -0 -s commands\mkdir.c  -fo=commands\mkdir.obj
	wlink file commands\mkdir.obj
	upx -9 commands\mkdir.exe
	
	wcc -0 -s commands\mv.c  -fo=commands\mv.obj
	wlink file commands\mv.obj
	upx -9 commands\mv.exe
	
	wcc -0 -s commands\pwd.c  -fo=commands\pwd.obj
	wlink file commands\pwd.obj
	upx -9 commands\pwd.exe
	
	wcc -0 -s commands\rm.c  -fo=commands\rm.obj
	wlink file commands\rm.obj
	upx -9 commands\rm.exe
	
	wcc -0 -s commands\rmdir.c  -fo=commands\rmdir.obj
	wlink file commands\rmdir.obj
	upx -9 commands\rmdir.exe
	
	wcc -0 -s commands\sh.c  -fo=commands\sh.obj
	wlink file commands\sh.obj
	upx -9 commands\sh.exe
	
	wcc -0 -s commands\time.c  -fo=commands\time.obj
	wlink file commands\time.obj
	upx -9 commands\time.exe