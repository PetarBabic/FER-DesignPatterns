import java.util.Arrays;

public class Najblizi implements Percentil {
    @Override
    public int Izracunaj(int percentil, int[] niz) {
        Arrays.sort(niz);

        return niz[(int) ((double) (percentil * niz.length) /100 + 0.5)];
    }
}
