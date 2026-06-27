#include "myfactory.h"

#include <stdio.h>
#include <stdlib.h>

typedef char const* (*PTRFUN)();

struct Animal{
    PTRFUN* vtable;
    // vtable entries:
    // 0: char const* name(void* this);
    // 1: char const* greet();
    // 2: char const* menu();
};

// parrots and tigers defined in respective dynamic libraries

void animalPrintGreeting(struct Animal* this) {
    printf("%s pozdravlja: %s\n", this->vtable[0](this), this->vtable[1]());
}
void animalPrintMenu(struct Animal* this) {
    printf("%s voli %s\n", this->vtable[0](this), this->vtable[2]());
}

int main(int argc, char *argv[]){
    for (int i=0; i<argc/2; ++i){
        struct Animal* p=(struct Animal*)myfactory(argv[1+2*i], argv[1+2*i+1]);
        if (!p){
            printf("Creation of plug-in object %s failed.\n", argv[1+2*i]);
            continue;
        }

        animalPrintGreeting(p);
        animalPrintMenu(p);
        free(p);
    }

    printf("\nPreradjena myfactory:\n");
    for (int i=0; i<argc/2; ++i){
        // Dohvacanje velicine objekata
        int memory_size = size(argv[1+2*i]);

        if(memory_size == -1) {
            printf("Greska prilikom dohvacanja velicine objekta: %s", argv[1+2*i]);
        }

        // Alociranje memorijskog prostora za taj objekt
        void* memory = malloc(memory_size);

        // Inicijalizacija objekta Animal na prethodno rezerviranom memorijskom prostoru
        struct Animal* p = (struct Animal*)myfactory_prekrojena(argv[1+2*i], argv[1+2*i+1], memory);

        animalPrintGreeting(p);
        animalPrintMenu(p);

        free(p);
    }
}