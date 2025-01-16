package blind75;

import java.lang.reflect.Array;
import java.util.Arrays;

public class MaximumSubArray {

    private static int maxSumSubArrayBruteForce1(int[] nums) {
        if (nums.length == 0)
            return 0;
        if (nums.length == 1)
            return nums[0];

        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                int currentSum = 0;
                for (int k = i; k <= j; k++) {
                    currentSum += nums[k];
                }
                maxSum = Math.max(maxSum, currentSum);
            }
        }

        return maxSum;
        // O(n3)
    }

    private static int maxSumSubArrayBruteForce2(int[] nums) {
        if (nums.length == 0)
            return 0;
        if (nums.length == 1)
            return nums[0];

        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            int currentSum = 0;
            for (int j = i; j < nums.length; j++) {
                currentSum += nums[j];
                maxSum = Math.max(maxSum, currentSum);
            }
        }

        return maxSum;
        // O(n2)
    }

    private static int maxSumSubArrayKadaneAlgorithm(int[] nums) {
        if (nums.length == 0)
            return 0;
        if (nums.length == 1)
            return nums[0];

        // Intuition is sum becomes negative , make it to zero , as negative Sum will
        // always decrease
        int overallSum = nums[0];
        int currentSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (currentSum >= 0) { // if Previous Array Sum is positive , element will add itself to previous train
                currentSum += nums[i];
            } else { // if it is negative or zero , element will start its own train
                currentSum = nums[i];
            }

            if (currentSum > overallSum) {
                overallSum = currentSum;
            }
        }

        return overallSum;
        // O(n)
    }

    private static int[] maxSumSubArrayIndexesKadaneAlgorithm(int[] nums) {
        if (nums.length == 0)
            return new int[0];
        if (nums.length == 1)
            return new int[] { 1, 1 };

        // Intuition is sum becomes negative , make it to zero , as negative Sum will
        // always decrease
        // Intuition is sum becomes negative , make it to zero , as negative Sum will
        // always decrease
        int overallSum = nums[0];
        int currentSum = nums[0];
        int startIndex = 0;
        int endIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (currentSum >= 0) { // if Previous Array Sum is positive , element will add itself to previous train
                currentSum += nums[i];
                endIndex = i;
            } else { // if it is negative or zero , element will start its own train
                currentSum = nums[i];
                startIndex = i;
            }

            if (currentSum > overallSum) {
                overallSum = currentSum;
            }
        }

        return new int[] { startIndex, endIndex };
        // O(n)
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4 };
        System.out.println(maxSumSubArrayBruteForce1(arr));
        System.out.println(maxSumSubArrayBruteForce2(arr));
        System.out.println(maxSumSubArrayKadaneAlgorithm(arr));
        System.out.println(Arrays.toString(maxSumSubArrayIndexesKadaneAlgorithm(arr)));
    }
}
