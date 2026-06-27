//
// Created by Petar Babic on 9/5/25.
//

#include <dlfcn.h>
#include <string.h>
#include "myfactory.h"
#include <stdio.h>
#include <stdlib.h>

void* myfactory(char const* libname, char const* ctorarg) {
    // Dekoracija imena biblioteke
    char* libpath = malloc(strlen(libname) + sizeof("./.so"));
    strcat(libpath, "./");
    strcat(libpath, libname);
    strcat(libpath, ".so");

    // Otvaranje .so biblioteke
    void* handle = dlopen(libpath, RTLD_LAZY);

    if(!handle) {
        printf("Pogreska pri otvaranju biblioteke\n");
        return NULL;
    }

    // Ucitavanje funkcije create
    typedef void* (*PTRFUN)(const char*);
    PTRFUN create = (PTRFUN)dlsym(handle, "create");

    char* error = dlerror();
    if (error != NULL) {
        printf("Pogreska pri pokretanju funkcije");
        return NULL;
    }

    // Pozivanje funkcije zadane ctorarg i vracanje njenog pokazivaca
    return create(ctorarg);
}

void* myfactory_prekrojena(char const* libname, char const* ctorarg, void* memory_location) {
    // Dekoracija imena biblioteke
    char libpath[512];
    snprintf(libpath, sizeof(libpath), "./%s.so", libname);

    // Otvaranje .so biblioteke
    void* handle = dlopen(libpath, RTLD_LAZY);

    if(!handle) {
        printf("Pogreska pri otvaranju biblioteke\n");
        return NULL;
    }

    // Ucitavanje funkcije construct
    typedef void (*PTRFUN)(void*, const char*);
    PTRFUN construct = (PTRFUN)dlsym(handle, "construct");

    char* error = dlerror();
    if (error != NULL) {
        printf("Pogreska pri pokretanju funkcije");
        return NULL;
    }

    construct(memory_location, ctorarg);

    return memory_location;
}

int size(char const* libname) {
    // Dekoracija imena biblioteke
    char* libpath = malloc(sizeof(libname));
    strcat(libpath, "./");
    strcat(libpath, libname);
    strcat(libpath, ".so");

    // Otvaranje .so biblioteke
    void* handle = dlopen(libpath, RTLD_LAZY);

    if(!handle) {
        printf("Pogreska pri otvaranju biblioteke\n");
        return -1;
    }

    typedef int (*PTRFUN)();
    PTRFUN sizeof_internal = (PTRFUN)dlsym(handle, "sizeof_internal");

    return sizeof_internal();
}