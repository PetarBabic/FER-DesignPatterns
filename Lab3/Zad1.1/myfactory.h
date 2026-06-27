//
// Created by Petar Babic on 9/5/25.
//

#ifndef ZAD1_MYFACTORY_H
#define ZAD1_MYFACTORY_H

// dodano kako se linker nebi bunio
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

void* myfactory(char const* libname, char const* ctorarg);
void* myfactory_prekrojena(char const* libname, char const* ctorarg, void* memory);
int size(char const* libname);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //ZAD1_MYFACTORY_H
