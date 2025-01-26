package Blind75;

public class NumberOfOneBits {
    private static int numberOfOneBits(int n) {
        int count = 0;
        while (n != 0) {
            int temp = n % 2;
            n = n >> 1;
            if (temp == 1)
                count++;
        }
        return count;
    }

    public static void main(String[] args) {
        int n = 1; // 00001010
        System.out.println(numberOfOneBits(n));
    }
}
