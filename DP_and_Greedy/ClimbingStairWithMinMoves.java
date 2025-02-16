package DP_and_Greedy;

import java.util.Arrays;

public class ClimbingStairWithMinMoves {

    private static int climbingStairsWithJumpsRecursive(int currentStairNumber, int maxStairNumber,
            int[] allowedJumps) {
        if (currentStairNumber == maxStairNumber) {
            return 0;// Min Moves from Top to top is 0 but total Ways is 1
        }
        if (currentStairNumber > maxStairNumber || allowedJumps[currentStairNumber] == 0) {
            return Integer.MAX_VALUE; // Cannot proceed further
        }
        System.out.println("Calculating All ways for Stair Number:" + currentStairNumber);
        int minMoves = Integer.MAX_VALUE;
        for (int jump = 1; jump <= allowedJumps[currentStairNumber]; jump++) {
            int result = climbingStairsWithJumpsRecursive(currentStairNumber + jump, maxStairNumber, allowedJumps);
            if (result != Integer.MAX_VALUE) {
                minMoves = Math.min(minMoves, result + 1);
            }
        }

        return minMoves;
    }

    private static int climbingStairsWithJumpsMemoization(int currentStairNumber, int maxStairNumber,
            int[] allowedJumps, int[] dp) {
        if (currentStairNumber == maxStairNumber) {
            return 0;
        }
        if (currentStairNumber > maxStairNumber || allowedJumps[currentStairNumber] == 0) {
            return Integer.MAX_VALUE;
        }
        if (dp[currentStairNumber] != -1) {
            return dp[currentStairNumber];
        }

        System.out.println("Calculating All ways for Stair Number:" + currentStairNumber);
        int minMoves = Integer.MAX_VALUE;
        for (int jump = 1; jump <= allowedJumps[currentStairNumber]; jump++) {
            int result = climbingStairsWithJumpsMemoization(currentStairNumber + jump, maxStairNumber, allowedJumps,
                    dp);
            if (result != Integer.MAX_VALUE) {
                minMoves = Math.min(minMoves, result + 1);
            }
        }

        dp[currentStairNumber] = minMoves;
        return dp[currentStairNumber];
    }

    private static int climbingStairsWithJumpsTabulation(int n, int[] allowedJumps) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[n] = 0; // Base case: Min 0 moves to be at the last stair (stay there)

        for (int i = n - 1; i >= 0; i--) { // Start from the second-last stair
            if (allowedJumps[i] > 0) {
                int minMoves = Integer.MAX_VALUE;
                for (int jump = 1; jump <= allowedJumps[i] && (i + jump) <= n; jump++) {
                    if (dp[i + jump] != Integer.MAX_VALUE) {
                        minMoves = Math.min(minMoves, dp[i + jump] + 1);
                    }
                }
                dp[i] = minMoves;
            }
        }

        return dp[0] == Integer.MAX_VALUE ? -1 : dp[0]; // Answer is the number of moves from stair 0
    }

    public static void main(String[] args) {
        int n = 6;
        int[] allowedJumps = { 3, 3, 0, 2, 2, 3 };
        System.out.println("----------------RECURSION---------------------------");
        System.out.println(climbingStairsWithJumpsRecursive(0, n, allowedJumps));
        System.out.println("----------------MEMOIZATION---------------------------");
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        System.out.println(climbingStairsWithJumpsMemoization(0, n, allowedJumps, dp));
        System.out.println("----------------TABULATION---------------------------");
        System.out.println(climbingStairsWithJumpsTabulation(n, allowedJumps));
    }
}
