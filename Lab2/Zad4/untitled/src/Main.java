public class Main {
    public static void main(String[] args) {
        System.out.println("Slijedno:");
        Brojevi slijedno = new Slijedo(1, 5, 3);
        for (int i : slijedno.Generiraj()) {
            System.out.println(i);
        }
        System.out.println("\nSlucajno:");
        Brojevi slucajno = new Slucajno(20, 5, 3);
        for (int i : slucajno.Generiraj()) {
            System.out.println(i);
        }
        System.out.println("\nFibanocci:");
        Brojevi fib = new Fibonacci(10);
        for (int i : fib.Generiraj()) {
            System.out.println(i);
        }

        Percentil perc = new Najblizi();
        System.out.println("Najblizi: " + perc.Izracunaj(80, new int[]{1, 10, 50}));
        Percentil inter = new Interpoliraj();
        System.out.println("Interpolirano: " + inter.Izracunaj(80, new int[]{1, 10, 50}));


        Brojevi generator = new Fibonacci(7);
        Percentil percentil = new Interpoliraj();

        DistributionTester tester = new DistributionTester(generator, percentil);
        tester.Testiraj();

        System.out.println("\nDrugi primjer s normalnom distribucijom:");
        Brojevi generator2 = new Slucajno(100, 10, 0);
        Percentil percentil2 = new Najblizi();

        DistributionTester tester2 = new DistributionTester(generator2, percentil2);
        tester2.Testiraj();
    }
}