//
// Created by Petar Babic on 8/6/25.
//
#include <stdio.h>
#include "animal.h"

typedef char const* (*PTRFUN)();

typedef struct Animal{
    PTRFUN* vtable;
    // vtable entries:
    // 0: char const* name(void* this);
    // 1: char const* greet();
    // 2: char const* menu();
}animal_t;

// parrots and tigers defined in respective dynamic libraries

void animalPrintGreeting(struct Animal* this) {
    printf("%s pozdravlja: %s\n", this->vtable[0](this), this->vtable[1]());
}
void animalPrintMenu(struct Animal* this) {
    printf("%s voli %s\n", this->vtable[0](this), this->vtable[2]());
}