import java.util.ArrayList;

public class Medijan extends Akcija {
    @Override
    public void radi() {
        ArrayList<Integer> brojevi = super.getSlijedBrojeva().getBrojevi();

        if(brojevi.size() % 2 != 0)
            System.out.println("Medijan: " + brojevi.get((brojevi.size())/2));
        else
            System.out.println("Medijan: " + (brojevi.get(brojevi.size()/2) + brojevi.get(brojevi.size()/2 - 1))/2);
    }
}
