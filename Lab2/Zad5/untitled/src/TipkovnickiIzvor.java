import java.util.Scanner;

public class TipkovnickiIzvor implements Izvor{
    @Override
    public int DohvatiBroj() {
        Scanner scanner = new Scanner(System.in);

        if(scanner.hasNextInt())
            return scanner.nextInt();
        return -1;
    }
}
