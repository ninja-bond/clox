#ifndef clox_compiler_h
#define clox_interpret_h
#include "object.h"
#include "vm.h"

bool compile(const char* source, Chunk* chunk);

#endif