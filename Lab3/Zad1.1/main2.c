//
// Created by Petar Babic on 8/6/25.
//

#include "myfactory.h"
#include "animal.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i=0; i<argc/2; ++i){
        // Dohvacanje velicine objekata
        int memory_size = size(argv[1+2*i]);

        if(memory_size == -1) {
            printf("Greska prilikom dohvacanja velicine objekta: %s", argv[1+2*i]);
        }

        // Alociranje memorijskog prostora za taj objekt
        void* memory = malloc(memory_size);

        // Inicijalizacija objekta neprozirnog objekta animal_t na prethodno rezerviranom memorijskom prostoru
        animal_t* p = (animal_t*)myfactory_prekrojena(argv[1+2*i], argv[1+2*i+1], memory);

        animalPrintGreeting(p);
        animalPrintMenu(p);

        free(p);
    }
}