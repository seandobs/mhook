#!/bin/bash

set -xe

rm -rf build

mkdir build
mkdir build/obj
mkdir build/lib

"${CCOMPILER}" ${CFLAGS} -DUNICODE -c "disasm-lib/all.c" -o build/obj/disasm.obj
"${CXXCOMPILER}" ${CXXFLAGS} -DUNICODE -c "mhook-lib/mhook.cpp" -o build/obj/mhook.obj
"${ARCHIVER}" ${ARCHIVERFLAGS} build/lib/libmhook${LIBNAME_EXT}.a build/obj/disasm.obj build/obj/mhook.obj

