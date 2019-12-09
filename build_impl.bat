@ECHO off

RMDIR build /s /q

MKDIR build
MKDIR build\obj
MKDIR build\lib

CL %CFLAGS% /DUNICODE /TC /MP1 /c .\disasm-lib\all.c /Fo.\build\obj\disasm.obj
CL %CXXFLAGS% /DUNICODE /c .\mhook-lib\mhook.cpp /Fo.\build\obj\mhook.obj
LIB %LIBFLAGS% /OUT:.\build\lib\mhook%LIBNAME_EXT%.lib .\build\obj\disasm.obj .\build\obj\mhook.obj
