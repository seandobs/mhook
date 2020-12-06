#!/bin/bash

set -xe

rm -rf build

mkdir build
mkdir build/obj
mkdir build/lib

c_compile --out "build/obj/disasm.obj" \
    --source "disasm-lib/all.c" \
    --define UNICODE

cxx_compile --out "build/obj/mhook.obj" \
    --source "mhook-lib/mhook.cpp" \
    --define UNICODE

archive --out "build/lib/${LIBNAME_PREFIX}mhook${LIBNAME_SUFFIX}.${LIBNAME_FILE_EXTENSION}" \
    --object "build/obj/disasm.obj" \
    --object "build/obj/mhook.obj"


