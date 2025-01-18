package blind75;

public class ClimbingStairs {

    private static int climbingStairsRecursive(int n) {
        if (n == 0)
            return 1; // Ways from 0 to 0 is 1
        else if (n < 0)
            return 0;

        System.out.println("Computing for: " + n);
        return climbingStairsRecursive(n - 1) + climbingStairsRecursive(n - 2);
    }

    private static int climbingStairsMemoization(int n, int[] memo) {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        if (memo[n] != 0)
            return memo[n];

        System.out.println("Computing for: " + n);
        int result = climbingStairsMemoization(n - 1, memo) + climbingStairsMemoization(n - 2, memo);
        memo[n] = result;
        return result;
    }

    private static int climbingStairsTabulation(int n) {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

    public static void main(String[] args) {
        int n = 3;
        System.out.println("----------------RECURSION---------------------------");
        System.out.println(climbingStairsRecursive(n));
        System.out.println("----------------MEMOIZATION---------------------------");
        System.out.println(climbingStairsMemoization(n, new int[n + 1]));
        System.out.println("----------------TABULATION---------------------------");
        System.out.println(climbingStairsTabulation(n));
    }
}
