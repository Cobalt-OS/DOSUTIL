all:
	gcc -o3 -s commands\beep.c -o commands\beep.exe
	upx -9 commands\beep.exe
	
	gcc -o3 -s commands\cat.c -o commands\cat.exe
	upx -9 commands\cat.exe
	
	gcc -o3 -s commands\cd.c -o commands\cd.exe
	upx -9 commands\cd.exe
	
	gcc -o3 -s commands\cd.c -o commands\clear.exe
	upx -9 commands\clear.exe
	
	gcc -o3 -s commands\cp.c -o commands\cp.exe
	upx -9 commands\cp.exe
	
	gcc -o3 -s commands\date.c -o commands\date.exe
	upx -9 commands\date.exe
	
	gcc -o3 -s commands\echo.c -o commands\echo.exe
	upx -9 commands\echo.exe
	
	gcc -o3 -s commands\ls.c -o commands\ls.exe
	upx -9 commands\ls.exe
	
	gcc -o3 -s commands\mkdir.c -o commands\mkdir.exe
	upx -9 commands\mkdir.exe
	
	gcc -o3 -s commands\mv.c -o commands\mv.exe
	upx -9 commands\mv.exe
	
	gcc -o3 -s commands\pwd.c -o commands\pwd.exe
	upx -9 commands\pwd.exe
	
	gcc -o3 -s commands\rm.c -o commands\rm.exe
	upx -9 commands\rm.exe
	
	gcc -o3 -s commands\rmdir.c -o commands\rmdir.exe
	upx -9 commands\rmdir.exe
	
	gcc -o3 -s commands\sh.c -o commands\sh.exe
	upx -9 commands\sh.exe
	
	gcc -o3 -s commands\time.c -o commands\time.exe
	upx -9 commands\time.exe