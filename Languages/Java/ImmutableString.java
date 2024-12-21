public class ImmutableString {
    public static void main(String[] args) {
        String s = "hello"; // Immutable String // in Stack with null character
        // s[0] = 'g' // Cant do

        System.out.println(s.charAt(0));
        System.out.println(s.substring(0, 3));
        System.out.println(s.length());

        String heapString = new String("Hello"); // OS creates Memory and returns Pointer

        String s1 = "Hello";
        String s2 = "Hello";
        String s3 = new String("Hello");

        System.out.println(s1.equals(s3)); // true (compares content)
        System.out.println(s1 == s3); // false (compares references)
    }
}

/*
 * The actual string "Hello" is stored in the heap in a special part called the
 * String Pool.
 * Java optimizes memory usage for string literals by keeping a single instance
 * of each literal in the String Pool.
 */

/*
 * The variable s is a reference (or pointer) to the string object and is stored
 * in the stack.
 * It holds the memory address of the actual string object in the heap.
 */