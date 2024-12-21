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

/*
 * Description: A mutable sequence of characters that can be modified without
 * creating a new object. It is not synchronized, meaning it is faster but not
 * thread-safe.
 * Use case: Ideal for single-threaded applications where frequent string
 * modifications are required.
 */

/*
 * Description: Similar to StringBuilder but thread-safe because its methods are
 * synchronized.
 * Use case: Useful in multi-threaded environments where multiple threads might
 * access and modify the string.
 */
