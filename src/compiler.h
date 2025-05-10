#ifndef clox_compiler_h
#define clox_interpret_h
#include "object.h"
#include "vm.h"

ObjFunction* compiler(const char* source);
// bool compile(const char* source, Chunk* chunk);

#endif