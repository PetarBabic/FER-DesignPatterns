#include <stdio.h>
#include <stdlib.h>

typedef char const* (*PTRFUN)();

struct Animal{
    const char* name;
    PTRFUN const* funcTable;
};

char const* dogGreet(void){
    return "vau!";
}
char const* dogMenu(void){
    return "kuhanu govedinu";
}
char const* catGreet(void){
    return "mijau!";
}
char const* catMenu(void){
    return "konzerviranu tunjevinu";
}
PTRFUN catTable[2] = {catGreet, catMenu};
PTRFUN dogTable[2] = {dogGreet, dogMenu};

struct Animal* constructDog(struct Animal* const this, char const* name) {
    this->name=name;
    this->funcTable=&dogTable[0];

    return this;
}
struct Animal* createDog(const char* name) {
    struct Animal *dog = malloc(sizeof(struct Animal));
    constructDog(dog, name);

    return dog;
}
struct Animal* constructCat(struct Animal* const this, char const* name) {
    this->name=name;
    this->funcTable=&catTable[0];

    return this;
}
struct Animal* createCat(const char* name) {
    struct Animal *cat = malloc(sizeof(struct Animal));
    constructCat(cat, name);

    return cat;
}
void animalPrintGreeting(struct Animal * const this) {
    printf("%s pozdravlja: %s\n", this->name, this->funcTable[0]());
}
void animalPrintMenu(struct Animal * const this) {
    printf("%s voli %s\n", this->name, this->funcTable[1]());
}
void testAnimals(void){
    struct Animal* p1=createDog("Hamlet");
    struct Animal* p2=createCat("Ofelija");
    struct Animal* p3=createDog("Polonije");

    animalPrintGreeting(p1);
    animalPrintGreeting(p2);
    animalPrintGreeting(p3);

    animalPrintMenu(p1);
    animalPrintMenu(p2);
    animalPrintMenu(p3);

    free(p1); free(p2); free(p3);
}

void testStack() {
    struct Animal a1, a2;

    constructDog(&a1, "Snoopy");
    constructCat(&a2, "Garfield");

    animalPrintGreeting(&a1);
    animalPrintGreeting(&a2);

    animalPrintMenu(&a1);
    animalPrintMenu(&a2);
}

void nPasa(int n) {
    struct Animal* psi = malloc(sizeof(struct Animal) * n);

    for(int i = 0; i < n; i++)
        constructDog(&psi[i], "Pas");

    for(int i = 0; i < n; i++)
        animalPrintGreeting(&psi[i]);

    free(psi);
}

int main() {
    testAnimals();
    testStack();
    nPasa(5);
}

/*
 Podatkovnim članovima objekta - const char* name;
 Metodama - char const* dogGreet(void), char const* dogMenu(void), char const* catGreet(void), char const* catMenu(void)
 Virtualnim metodama - u ovom slucaju nisu koristene, ali bi se zvale preko virtualne tablice (dogTable i catTable)
 Konstruktorima - struct Animal* constructDog, struct Animal* constructCat
 Virtualnim tablicama - PTRFUN catTable[2], PTRFUN dogTable[2]
 */