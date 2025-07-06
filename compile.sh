#!/bin/bash

SOURCE_FILES="\
main.cpp \
DataStructs.cpp \
rk4.cpp \
FluxFunctions.cpp \
RHSoperator.cpp"

# Compilación con MPI - precisión doble
mpic++ -g -O3 -D_DOUBLE_ $SOURCE_FILES -Iincludes -o double.p

# Compilación con MPI - precisión simple
mpic++ -g -O3 $SOURCE_FILES -Iincludes -o single.p

# Compilación SIN MPI - precisión simple
g++ -g -O3 $SOURCE_FILES -Iincludes -o single_nmpi

