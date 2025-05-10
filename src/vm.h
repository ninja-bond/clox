#ifndef clox_vm_h
#define clox_vm_h
#include "object.h"
#include "value.h"
#include "table.h"
#include "object.h"
#include <stdint.h>

// #define STACK_MAX 256
#define FRAME_MAX 64
#define STACK_MAX (FRAME_MAX*UINT8_COUNT)

typedef struct{
    ObjClosure* closure;
    uint8_t* ip;
    Value* slots;
}CallFrame;

#include "chunk.h"

typedef struct{
    CallFrame frames[FRAME_MAX];
    int frameCount;
    // Chunk* chunk;
    // uint8_t* ip;
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