package DP_and_Greedy;

import java.util.Arrays;

public class ClimbingStairsWithJump {

    private static int climbingStairsWithJumpsRecursive(int currentStairNumber, int maxStairNumber,
            int[] allowedJumps) {
        if (currentStairNumber == maxStairNumber) {
            return 1;
        }

        System.out.println("Calculating All ways for Stair Number:" + currentStairNumber);
        int totalWaysfromCurrentStair = 0;
        for (int jump = 1; jump <= allowedJumps[currentStairNumber]
                && (currentStairNumber + jump) <= maxStairNumber; jump++) {
            totalWaysfromCurrentStair += climbingStairsWithJumpsRecursive(currentStairNumber + jump, maxStairNumber,
                    allowedJumps);
        }

        return totalWaysfromCurrentStair;
    }

    private static int climbingStairsWithJumpsMemoization(int currentStairNumber, int maxStairNumber,
            int[] allowedJumps, int[] dp) {
        if (currentStairNumber == maxStairNumber) {
            return 1;
        }

        if (dp[currentStairNumber] != -1)
            return dp[currentStairNumber];

        System.out.println("Calculating All ways for Stair Number:" + currentStairNumber);
        int totalWaysfromCurrentStair = 0;
        for (int jump = 1; jump <= allowedJumps[currentStairNumber]
                && (currentStairNumber + jump) <= maxStairNumber; jump++) {
            totalWaysfromCurrentStair += climbingStairsWithJumpsMemoization(currentStairNumber + jump, maxStairNumber,
                    allowedJumps, dp);
        }

        dp[currentStairNumber] = totalWaysfromCurrentStair;
        return totalWaysfromCurrentStair;
    }

    private static int climbingStairsWithJumpsTabulation(int n, int[] allowedJumps) {
        int[] dp = new int[n + 1];
        dp[n] = 1; // Base case: Only 1 way to be at the last stair (stay there)

        for (int i = n - 1; i >= 0; i--) { // Start from the second-last stair
            for (int jump = 1; jump <= allowedJumps[i] && (i + jump) <= n; jump++) {
                dp[i] += dp[i + jump]; // Accumulate ways from reachable stairs
            }
        }

        return dp[0]; // Answer is the number of ways from stair 0
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
