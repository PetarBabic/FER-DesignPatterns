import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DatotecniIzvor implements Izvor{
    private Scanner scanner;

    public DatotecniIzvor(String datoteka) {
        try {
            scanner = new Scanner(new File(datoteka));
        }
        catch (Exception e) {
            System.out.println(e.toString());
        }
    }
    @Override
    public int DohvatiBroj() {
        if(scanner.hasNextInt())
            return scanner.nextInt();
        scanner.close();
        return -1;
    }
}
