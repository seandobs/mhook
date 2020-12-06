@ECHO off

RMDIR build /s /q

MKDIR build
MKDIR build\obj
MKDIR build\lib

%CCOMPILER% %CFLAGS% /DUNICODE /MP1 /c .\disasm-lib\all.c /Fo.\build\obj\disasm.obj
%CXXCOMPILER% %CXXFLAGS% /DUNICODE /c .\mhook-lib\mhook.cpp /Fo.\build\obj\mhook.obj
%ARCHIVER% %LIBFLAGS% /OUT:.\build\lib\%LIBNAME_PREFIX%mhook%LIBNAME_SUFFIX%.%LIBNAME_FILE_EXTENSION% .\build\obj\disasm.obj .\build\obj\mhook.obj
