package Blind75;

import java.util.Arrays;

public class CountingOneBitsInRange {

    // Helper
    private static int numberOfOneBits(int n) {
        int count = 0;
        while (n != 0) {
            int temp = n % 2;
            n = n >> 1; // n = n/2
            if (temp == 1)
                count++;
        }
        return count;
    }

    private static int[] countingBitsBruteForce(int n) {
        int[] result = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            int count = numberOfOneBits(i);
            result[i] = count;
        }
        return result;
        // O(nlogn)
    }

    private static int[] countingBitsDP(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        int sub = 1;

        for (int i = 1; i <= n; i++) {
            if (sub * 2 == i) {
                sub = i;
            }

            dp[i] = dp[i - sub] + 1;
        }

        return dp;
        // O(n)
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(countingBitsBruteForce(10)));
        System.out.println(Arrays.toString(countingBitsDP(10)));
    }
}
