public class Arrays {
    public static void main(String[] args) {
        int[] staticArray = { 1, 2, 3, 4, 5 }; // This array is also present in Heap but its Base address is present in
                                               // Stack inside staticArray variable

        int[] dynamicArray = new int[5]; // Runtime Allocation in Heap using OS system calls
        // dynamicArray Variable is present in Stack

        for (int i = 0; i < staticArray.length; i++) {
            System.out.println(i);
        }
    }
}
