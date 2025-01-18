package practice;

import java.util.Arrays;

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

        if (memo[n] != 0) {
            return memo[n];
        }

        System.out.println("Computing for: " + n);
        int fib = fibRecursionMemoization(n - 1, memo) + fibRecursionMemoization(n - 2, memo);
        memo[n] = fib;
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

    public static void main(String[] args) {
        int n = 10;
        System.out.println("----------------RECURSION---------------------------");
        System.out.println(fibRecursion(n));
        System.out.println("---------------MEMOIZATION----------------------------");
        System.out.println(fibRecursionMemoization(n, new int[n + 1]));
        System.out.println("----------------TABULATION---------------------------");
        System.out.println(fibRecursionTabulation(n));
    }
}
