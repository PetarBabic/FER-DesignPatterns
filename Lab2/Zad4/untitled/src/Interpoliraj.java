import java.util.Arrays;

public class Interpoliraj implements Percentil {
    @Override
    public int Izracunaj(int percentil, int[] niz) {
        Arrays.sort(niz);

        double p1 = 0;
        double p2 = 0;

        for(int i = 0; i < niz.length; i++) {
            p1 = p2;
            p2 = 100*((i + 1)-0.5)/niz.length;

            if(percentil < p1)
                return niz[0];

            if(percentil == p2)
                return niz[i];

            if(percentil > p1 && percentil < p2) {
                //v(p) = v[i] + N * (p-p(v[i]))*(v[i+1]-v[i])/100
                return (int) (niz[i - 1] + niz.length * (percentil - p1) * (niz[i] - niz[i - 1]) / 100);
            }
        }

        return niz[niz.length - 1];
    }
}
