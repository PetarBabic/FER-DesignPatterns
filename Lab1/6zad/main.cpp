#include <stdio.h>

class Base{
public:
    Base() {
        metoda();
    }

    virtual void virtualnaMetoda() {
        printf("ja sam bazna implementacija!\n");
    }

    void metoda() {
        printf("Metoda kaze: ");
        virtualnaMetoda();
    }
};

class Derived: public Base{
public:
    Derived(): Base() {
        metoda();
    }
    virtual void virtualnaMetoda() {
        printf("ja sam izvedena implementacija!\n");
    }
};

int main(){
    Derived* pd=new Derived();
    pd->metoda();
}

/*
 Ova vježba ukazuje na različito ponašanje polimorfnih poziva tijekom i nakon završene konstrukcije objekta.
 Objasnite ispis programa analizirajući prevedeni strojni kod. Obratite pažnju na to tko, kada i gdje
 postavlja/modificira pokazivač na tablicu virtualnih funkcija.

 Metoda kaze: ja sam bazna implementacija!
 Konstruktor klase "Derived" prvo zove konstruktor klase "Base", kojemu vptr pokazuje na funkciju Base::virtualnaMetoda()
 zato što je po C++ standardu onemogućen poziv virtualnih funkcija iz konstruktora.
 Strojni kod:
  _main -> __ZN7DerivedC1Ev -> __ZN4BaseC2Ev:
  postavi vptr na funkcije klase "Base"
    adrp	x8, __ZTV4Base@GOTPAGE
	ldr	x8, [x8, __ZTV4Base@GOTPAGEOFF]

 Metoda kaze: ja sam izvedena implementacija!
 Nakon što završi konstruktor klase "Base", konstruktor klase "Derived" poziva funkciju "metoda", te je tada vptr postavljen
 na funkciju Derived::virtualnaMetoda()

 Strojni kod (prvo skoči na __ZN4BaseC2Ev koji postavi vptr na funkcije klase "Base", te kada se vrati iz te funkcije
 vptr se premjesti na funkcije "Derived"):
    bl	__ZN4BaseC2Ev
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	adrp	x8, __ZTV7Derived@GOTPAGE
	ldr	x8, [x8, __ZTV7Derived@GOTPAGEOFF]


 Metoda kaze: ja sam izvedena implementacija!
 Konstrukcija klase "Derived" je gotova pa je i očekivano bilo da će se ispisati "ja sam izvedena implementacija!" i
 nigdje više nisu mijenjani vptr.

*/