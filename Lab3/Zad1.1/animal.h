//
// Created by Petar Babic on 8/6/25.
//

#ifndef ZAD1_ANIMAL_H
#define ZAD1_ANIMAL_H

// dodano kako se linker nebi bunio
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef struct Animal animal_t;

void animalPrintGreeting(struct Animal* animal);
void animalPrintMenu(struct Animal* animal);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //ZAD1_ANIMAL_H