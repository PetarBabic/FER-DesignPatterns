//
// Created by Petar Babic on 9/5/25.
//

#include <stdlib.h>

typedef char const* (*PTRFUN)();

struct Parrot{
    PTRFUN const* funcTable;
    const char* name;
};

char const* name(void *this) {
    return ((struct Parrot*)this)->name;
}

char const* greet() {
    return "krestanje";
}

char const* menu() {
    return "sjemenke";
}

PTRFUN parrotTable[3] = {name, greet, menu};

void* create(char const* name) {
    struct Parrot *parrot = malloc(sizeof(struct Parrot));
    parrot->funcTable=&parrotTable[0];
    parrot->name=name;

    return parrot;
}

int sizeof_internal() {
    return sizeof(struct Parrot);
}

void construct(void* memory, char const* name) {
    struct Parrot *parrot = (struct Parrot*) memory;
    parrot->funcTable=&parrotTable[0];
    parrot->name=name;
}