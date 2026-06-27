public class Main {
    public static void main(String[] args) {
        Sheet sheet = new Sheet(5, 5);

        sheet.set("A1", "5");
        sheet.set("A2", "A1");
        sheet.set("A3", "A1+A2");
        sheet.set("A4", "A1+5");

        System.out.println(sheet);

        sheet.set("A1", "7");
        System.out.println(sheet);

        sheet.set("B1", "B2");
        System.out.println(sheet);

        sheet.set("B2", "B3");
        sheet.set("B3", "B1");
        sheet.set("B3", "E5");
        System.out.println(sheet);
        sheet.set("E5", "12");
        System.out.println(sheet);
        sheet.set("B2", "2");
        System.out.println(sheet);
        sheet.set("E5", "4");
        System.out.println(sheet);
    }
}