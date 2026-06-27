public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!");

        Izvor izvor = new TipkovnickiIzvor();
        Izvor izvor2 = new DatotecniIzvor("/Users/petarbabic/Desktop/Faks/6 semestar/Ooup/Lab/Lab2/Zad6/untitled/src/test.txt");

        SlijedBrojeva slijed = new SlijedBrojeva(new TipkovnickiIzvor());

        slijed.dodajAkcije(new Zapisi(), new Suma(), new Medijan());

        slijed.kreni();
    }
}