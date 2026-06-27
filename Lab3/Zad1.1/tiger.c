//
// Created by Petar Babic on 9/5/25.
//

#include <stdlib.h>

typedef char const* (*PTRFUN)();

struct Tiger{
    PTRFUN const* funcTable;
    const char* name;
};

char const* name(void *this) {
    return ((struct Tiger*)this)->name;
}

char const* greet() {
    return "rika";
}

char const* menu() {
    return "srnetinu";
}

PTRFUN tigerTable[3] = {name, greet, menu};

void* create(char const* name) {
    struct Tiger *tiger = malloc(sizeof(struct Tiger));
    tiger->funcTable=&tigerTable[0];
    tiger->name=name;

    return tiger;
}

int sizeof_internal() {
    return sizeof(struct Tiger);
}

void construct(void* memory, const char* name) {
    struct Tiger *tiger = (struct Tiger*) memory;
    tiger->name=name;
    tiger->funcTable=&tigerTable[0];
}