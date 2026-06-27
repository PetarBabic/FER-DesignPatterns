public class Prosjek extends Akcija {
    @Override
    public void radi() {
        int suma = 0;
        for (Integer broj : super.getSlijedBrojeva().getBrojevi()) {
            suma += broj;
        }

        System.out.println("Prosjek: " + suma/super.getSlijedBrojeva().getBrojevi().size());
    }
}
