public class Arrays {
    public static void main(String[] args) {
        int[] staticArray = { 1, 2, 3, 4, 5 }; // Static Allocation in Stack

        int[] dynamicArray = new int[5]; // Dynamic Allocation in Heap using OS system calls

        for (int i = 0; i < staticArray.length; i++) {
            System.out.println(i);
        }
    }
}
