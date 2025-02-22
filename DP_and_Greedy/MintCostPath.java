package DP_and_Greedy;

import java.util.Arrays;

public class MintCostPath {

    private static int minCostPathRecursive(int[][] cost, int row, int col, int m, int n) {
        // Base Case: If we reach the bottom-right corner
        if (row == m - 1 && col == n - 1) {
            return cost[row][col];
        }
        // If out of bounds, return a large value (infinity)
        if (row >= m || col >= n) {
            return Integer.MAX_VALUE;
        }

        System.out.println("Calculating Min Cost for: " + row + "x" + col);

        // Move right
        int right = minCostPathRecursive(cost, row, col + 1, m, n);
        // Move down
        int down = minCostPathRecursive(cost, row + 1, col, m, n);

        // Return the minimum of the two possible paths plus the current cell cost
        return cost[row][col] + Math.min(right, down);
    }

    public static int minCostPathMemoization(int[][] cost, int row, int col, int m, int n, int[][] dp) {
        // Base Case: If we reach the bottom-right corner
        if (row == m - 1 && col == n - 1) {
            return cost[row][col];
        }
        // If out of bounds, return a large value (infinity)
        if (row >= m || col >= n) {
            return Integer.MAX_VALUE;
        }
        // If already computed, return stored value
        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        System.out.println("Calculating Min Cost for: " + row + "x" + col);

        // Move right
        int right = minCostPathMemoization(cost, row, col + 1, m, n, dp);
        // Move down
        int down = minCostPathMemoization(cost, row + 1, col, m, n, dp);

        // Store the result and return the minimum of the two possible paths plus the
        // current cell cost
        return dp[row][col] = cost[row][col] + Math.min(right, down);
    }

    public static int minCostPathTabulation(int[][] cost) {
        int m = cost.length, n = cost[0].length;
        int[][] dp = new int[m][n];

        // Fill the DP table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Base case: starting point
                if (i == 0 && j == 0) {
                    dp[i][j] = cost[i][j];
                } 
                // If we're in the first row, we can only come from the left
                else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + cost[i][j];
                } 
                // If we're in the first column, we can only come from the top
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + cost[i][j];
                } 
                // Otherwise, take the minimum of the top or left cell
                else {
                    dp[i][j] = cost[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m - 1][n - 1]; // The final answer is at the bottom-right cell
    }

    public static int minCostPathReverseTabulation(int[][] cost) {
        int m = cost.length, n = cost[0].length;
        int[][] dp = new int[m][n];

        // Fill the DP table from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Base case: ending point (bottom-right corner)
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = cost[i][j];
                } 
                // If we're in the last row, we can only come from the right
                else if (i == m - 1) {
                    dp[i][j] = dp[i][j + 1] + cost[i][j];
                } 
                // If we're in the last column, we can only come from below
                else if (j == n - 1) {
                    dp[i][j] = dp[i + 1][j] + cost[i][j];
                } 
                // Otherwise, take the minimum of coming from the right or below
                else {
                    dp[i][j] = cost[i][j] + Math.min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0]; // The minimum cost path to reach (0,0)
    }

    public static void main(String[] args) {
        int[][] arr = {
                { 12, 3, 0 },
                { 5, 4, 6 },
                { 10, 12, 13 }
        };
        System.out.println("----------------RECURSION---------------------------");
        System.out.println(minCostPathRecursive(arr, 0, 0, 3, 3));
        System.out.println("----------------MEMOIZATION---------------------------");
        // Initialize DP table with -1
        int[][] dp = new int[3][3];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        System.out.println(minCostPathMemoization(arr, 0, 0, 3, 3, dp));
        System.out.println("----------------TABULATION---------------------------");
        System.out.println(minCostPathReverseTabulation(arr));
    }
}
