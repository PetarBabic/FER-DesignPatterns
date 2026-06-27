#include <iostream>
class B{
public:
    virtual int prva()=0;
    virtual int druga(int)=0;
};

class D: public B{
public:
    virtual int prva(){return 42;}
    virtual int druga(int x){return prva()+x;}
};

void funkcija(B* ptr) {
    void** vptr = *(void***)ptr;

    typedef int (*pfun)(B*);
    typedef int (*dfun)(B*, int);

    pfun prva = (pfun)(vptr[0]);
    dfun druga = (dfun)(vptr[1]);

    std::cout << prva(ptr) << "\n";
    std::cout << druga(ptr, 5);
}

int main() {
    D d;

    funkcija(&d);

    return 0;
}