import java.util.Random;

public class Slucajno implements Brojevi{
    private final int n;
    private final double stdev, srednjaVrijednost;

    public Slucajno(int n, float stdev, float srednjaVrijednost) {
        this.n = n;
        this.stdev = stdev;
        this.srednjaVrijednost = srednjaVrijednost;
    }

    @Override
    public int[] Generiraj() {
        int[] brojevi = new int[n];
        Random rnd = new Random();

        for(int i = 0; i < n; i++) {
            brojevi[i] = (int)(rnd.nextGaussian() * stdev + srednjaVrijednost);
        }

        return brojevi;
    }
}
