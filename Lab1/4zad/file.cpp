class Base{
public:
  //if in doubt, google "pure virtual"
  virtual void set(int x)=0;
  virtual int get()=0;
};
class CoolClass: public Base{
public:
  virtual void set(int x){x_=x;};
  virtual int get(){return x_;};
private:
  int x_;
};
class PlainOldClass{
public:
  void set(int x){x_=x;};
  int get(){return x_;};
private:
  int x_;
};
int main(){
  PlainOldClass poc;
  Base* pb=new CoolClass;
  poc.set(42);
  pb->set(42);
}

/*

1. Pronađite dijelove assemblerskog kôda u kojima se odvija alociranje memorije za objekte poc i *pb.

 Alociranje memorije za poc:
	mov	w1, #42                         
	str	w1, [sp, #12]

 Alociranje memorije za *pb:
	ldr	x0, [sp, #16]
	ldr	x8, [x0]
	ldr	x8, [x8]
	blr	x8

2. Objasnite razliku u načinu alociranja tih objekata.

 Kod alociranja memorije za objekt poc, jednostavno se spremi vrijednost 42 na STACK.
 Dok kod alociranja memorije za objekt *pb, se sprema na HEAP

3. Pronađite dio assemblerskog kôda koji je zadužen za poziv konstruktora objekta poc, ako takav poziv 
postoji.

 Ne postoji takav poziv, postoji jedino poziv za funkciju set (bl	__ZN13PlainOldClass3setEi)

4. Pronađite dio assemblerskog kôda koji je zadužen za poziv konstruktora objekta *pb. Razmotrite kako
se točno izvršava taj kôd. Što se u njemu događa?

 Poziv konstruktora:
	bl	__ZN9CoolClassC1Ev
 Unutar te funkcije se dogodi poziv funkciji __ZN9CoolClassC2Ev i unutar nje poziv __ZN4BaseC2Ev.
 Tj. __ZN9CoolClassC2Ev je ustvari pravi konstruktor kojeg će pozivati sve izvedene klase iz klase
 CoolClass. A __ZN4BaseC2Ev je glavni konstruktor klase Base.

5. Promotrite kako je prevoditelj izveo pozive pb->set i poc.set. Objasnite razliku između izvedbi tih
dvaju poziva. Koji od ta dva poziva zahtijeva manje instrukcija? Za koju od te dvije izvedbe bi
optimirajući prevoditelj mogao generirati kôd bez instrukcije CALL odnosno izravno umetnuti 
implementaciju funkcije (eng. inlining)?

 poc.set:
	mov	w1, #42
	str	w1, [sp, #12]

 pb->set:
	ldr	x0, [sp, #16]
	ldr	x8, [x0]
	ldr	x8, [x8]
	blr	x8

 Manje instrukcija zahtijeva poc.set, jer se njegova vrijednost direktno zapiše na STACK, dok se kod
 poziva pb->set treba prvo ucitati vrijednost pokazivaca iz virtualne tablice i onda spremiti vrijednost
 na tu adresu.
 Za poziv pb->set jer on ima skok.

6. Pronađite asemblerski kôd za definiciju i inicijalizaciju tablice virtualnih funkcija razreda CoolClass.

 Definicija tablice virtualnih funkcija:
 __ZTV9CoolClass:
	.quad	0
	.quad	__ZTI9CoolClass
	.quad	__ZN9CoolClass3setEi
	.quad	__ZN9CoolClass3getEv

	.private_extern	__ZTS9CoolClass
	.section	__TEXT,__const
	.globl	__ZTS9CoolClass
	.weak_definition	__ZTS9CoolClass

 Inicijalizacija tablice virtualnih funkcija:
 	ldr	x0, [sp]                        ; 8-byte Folded Reload
	adrp	x8, __ZTV9CoolClass@GOTPAGE
	ldr	x8, [x8, __ZTV9CoolClass@GOTPAGEOFF]
	add	x8, x8, #16
	str	x8, [x0]

 */