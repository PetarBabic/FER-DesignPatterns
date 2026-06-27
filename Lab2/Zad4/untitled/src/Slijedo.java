public class Slijedo implements Brojevi{
    private final int dGranica, gGranica, korak;

    public Slijedo(int dGranica, int gGranica, int korak) {
        this.dGranica = dGranica;
        this.gGranica = gGranica;
        this.korak = korak;
    }

    @Override
    public int[] Generiraj() {
        int[] brojevi = new int[(gGranica - dGranica)/korak + 1];

        brojevi[0] = dGranica;
        for(int i = 1; i <= (gGranica - dGranica)/korak; i++)
            brojevi[i] = brojevi[i - 1] + korak;

        return brojevi;
    }
}
