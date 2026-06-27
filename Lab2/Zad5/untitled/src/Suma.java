public class Suma extends Akcija {
    @Override
    public void radi() {
        int suma = 0;
        for (Integer broj : super.getSlijedBrojeva().getBrojevi()) {
            suma += broj;
        }

        System.out.println("Suma: " + suma);
    }
}
