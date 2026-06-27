import java.io.FileWriter;
import java.time.LocalDateTime;
import java.util.ArrayList;

public class Zapisi extends Akcija {
    private String datoteka = "tmp.txt";

    public void setDatoteka(String datoteka) {
        this.datoteka = datoteka;
    }

    @Override
    public void radi() {
        ArrayList<Integer> brojevi = new ArrayList<>(super.getSlijedBrojeva().getBrojevi());
        LocalDateTime datum = LocalDateTime.now();

        try(FileWriter file = new FileWriter(datoteka);){
            file.write(String.valueOf(brojevi));
            file.write(datum.toString());
        }
        catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
