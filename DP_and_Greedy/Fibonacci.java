package DP_and_Greedy;

public class Fibonacci {
    private static int fibRecursion(int n) {
        if (n == 0 || n == 1) {
            System.out.println("Base Case Called: " + n);
            return n;
        }
        System.out.println("Computing for: " + n);
        return fibRecursion(n - 1) + fibRecursion(n - 2);
    }

    private static int fibRecursionMemoization(int n, int[] memo) { // Recursive DP
        if (n == 0 || n == 1) {
            System.out.println("Base Case Called: " + n);
            return n;
        }

        if (memo[n] != 0) { // Base case for not Re Computing
            return memo[n];
        }

        System.out.println("Computing for: " + n);
        int fib = fibRecursionMemoization(n - 1, memo) + fibRecursionMemoization(n - 2, memo);
        memo[n] = fib; // Storing
        return fib;
    }

    private static int fibRecursionTabulation(int n) { // Iterative DP
        if (n == 0 || n == 1) {
            return n;
        }

        int[] memo = new int[n + 1];
        memo[0] = 0; // We Already know base values
        memo[1] = 1; // We Already know base values
        for (int i = 2; i <= n; i++) {
            memo[i] = memo[i - 1] + memo[i - 2];
        }

        return memo[n];
    }

    private static int fibRecursionTabulationOptimizeSpace(int n) { // Iterative DP
        if (n == 0 || n == 1) {
            return n;
        }

        int first = 0;
        int second = 1;
        int curr = 0;
        for (int i = 2; i <= n; i++) {
            curr = first + second;
            first = second;
            second = curr;
        }

        return curr;
        // Removed Extra space , as we need only last value
    }

    public static void main(String[] args) {
        int n = 15;
        System.out.println("----------------RECURSION---------------------------");
        System.out.println(fibRecursion(n));
        System.out.println("---------------MEMOIZATION----------------------------");
        System.out.println(fibRecursionMemoization(n, new int[n + 1]));
        System.out.println("----------------TABULATION---------------------------");
        System.out.println(fibRecursionTabulation(n));
        System.out.println("----------------TABULATION OPTIMIZE---------------------------");
        System.out.println(fibRecursionTabulationOptimizeSpace(n));
    }
}
