public class Main {
    public static void main(String[] args) {
        int a = 10;
        byte b = 'a';
        boolean c = true;
        char d = 'c';
        short e = 'e';
        long f = 123456789;
        float g = 2.56f;
        double h = 3.1415926d;
        short i = 1;
        // There's nothing known as unsigned in Java -> All Memory is Signed only

        String j = "hello"; // J is pointer internally -> String Class Object is Immutable
        char[] characterArray = { 'H', 'e', 'l', 'l', 'o' }; // Chracter Array

        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // Continuous Space of integer size space(Size of Integer depends on
                                                   // JVM , OS , Hardware)
    }
}