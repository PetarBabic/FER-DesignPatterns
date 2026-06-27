import java.util.*;

public class SlijedBrojeva {
    private Izvor izvor;
    private ArrayList<Integer> brojevi = new ArrayList<Integer>();
    private ArrayList<Akcija> akcije = new ArrayList<>();

    public SlijedBrojeva(Izvor izvor) {
        this.izvor = izvor;
    }

    public SlijedBrojeva(Izvor izvor, Akcija... akcije) {
        this.izvor = izvor;
        this.akcije.addAll(List.of(akcije));
        this.akcije.forEach(a -> a.setSlijedBrojeva(this));
    }

    public void kreni() {
        int br = 0;

        while(true) {
            br = izvor.DohvatiBroj();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

            if(br < 0)
                break;
            brojevi.add(br);
            push();
        }
    }

    public ArrayList<Integer> getBrojevi() {
        return brojevi;
    }

     private void push() {
        akcije.forEach(a -> a.radi());
     }
     public void dodajAkcije(Akcija... akcije) {
        this.akcije.addAll(List.of(akcije));
        this.akcije.forEach(a -> a.setSlijedBrojeva(this));
     }
     public void obrisiAkcije(Akcija... akcije) {
         this.akcije.removeAll(List.of(akcije));
     }
}
