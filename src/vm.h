#ifndef clox_vm_h
#define clox_vm_h
#include "value.h"
#include "table.h"

#define STACK_MAX 256

#include "chunk.h"

typedef struct{
    Chunk* chunk;
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
    Table globals;
    Table strings;
    Obj* objects;
}VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

void initVM();
void freeVM();

// InterpretResult interpret(Chunk* chunk);
InterpretResult interpret(const char* source);
void push(Value value);
Value pop();

#endif