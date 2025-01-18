package blind75;

public class ReverseBits {
    private static int reverseBits(int n) {
        if (n == 0)
            return 0;

        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            if ((n & 1) == 1)
                result++;
            n >>= 1;
        }
        return result;
    }

    public static void main(String[] args) {
        int n = 0;
        System.out.println(reverseBits(n));
    }
}
