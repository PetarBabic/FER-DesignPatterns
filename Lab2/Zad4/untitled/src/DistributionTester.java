public class DistributionTester {
    private Brojevi brojevi;
    private Percentil percentil;

    public DistributionTester(Brojevi brojevi, Percentil percentil) {
        this.brojevi = brojevi;
        this.percentil = percentil;
    }

    public void Testiraj() {
        int[] niz = brojevi.Generiraj();

        System.out.println("Generirani niz brojeva: ");
        for (int i : niz) {
            System.out.print(i + ",");
        }
        System.out.println();

        System.out.println("Njihovi percentili");
        for(int i = 10; i <= 90; i += 10) {
            System.out.println("p(" + i + "): " + percentil.Izracunaj(i, niz));
        }
    }
}
