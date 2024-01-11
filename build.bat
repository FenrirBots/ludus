@echo off
setlocal
set WORKSPACE_DIR=%~dp0
set WORKSPACE_DIR=%WORKSPACE_DIR:~0,-1%
set MINGW_TOOLS=D:\tools\mingw\bin
set CLANG_TOOLS=D:\tools\clang\bin
cd %MINGW_TOOLS%
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\minhook\hde\hde32.c -o %WORKSPACE_DIR%\build\obj\module\hde32.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\minhook\hde\hde64.c -o %WORKSPACE_DIR%\build\obj\module\hde64.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\minhook\buffer.c -o %WORKSPACE_DIR%\build\obj\module\buffer.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\minhook\hook.c -o %WORKSPACE_DIR%\build\obj\module\hook.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\minhook\trampoline.c -o %WORKSPACE_DIR%\build\obj\module\trampoline.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\patches\isdebuggerpresent.c -o %WORKSPACE_DIR%\build\obj\module\isdebuggerpresent.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\threads\startup.c -o %WORKSPACE_DIR%\build\obj\module\startup.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\threads\cleanup.c -o %WORKSPACE_DIR%\build\obj\module\cleanup.o
gcc.exe -c -std=c99 -I%WORKSPACE_DIR% %WORKSPACE_DIR%\src\module\entrypoint.c -o %WORKSPACE_DIR%\build\obj\module\entrypoint.o
gcc.exe --shared --static %WORKSPACE_DIR%\build\obj\module\*.o -o %WORKSPACE_DIR%\build\bin\module.dll
cd %WORKSPACE_DIR%
endlocal