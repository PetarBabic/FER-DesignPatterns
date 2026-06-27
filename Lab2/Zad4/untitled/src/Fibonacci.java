public class Fibonacci implements Brojevi {
    private final int n;

    public Fibonacci(int n) {
        this.n = n;
    }

    @Override
    public int[] Generiraj() {
        int[] brojevi = new int[n];

        brojevi[0] = 0;
        if(n == 1) return brojevi;

        brojevi[1] = 1;
        for(int i = 2; i < n; i++) {
            brojevi[i] = brojevi[i - 1] + brojevi[i - 2];
        }

        return brojevi;
    }
}
