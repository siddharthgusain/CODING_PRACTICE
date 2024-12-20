public class MutableStrings {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("String");
        sb.append(" Builder");
        System.out.println(sb); // "Hello World"

        StringBuffer sBuffer = new StringBuffer("String");
        sBuffer.append(" Buffer");
        System.out.println(sBuffer); // "Hello World"
    }
}
