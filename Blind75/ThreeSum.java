package Blind75;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    // Brute Force for 3Sum
    private static List<List<Integer>> threeSumBruteForce(int[] nums, int target) {
        if (nums == null || nums.length < 3)
            return new ArrayList<>();

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                for (int k = j + 1; k < nums.length; k++) {
                    if (nums[i] + nums[j] + nums[k] == target) {
                        List<Integer> triplet = Arrays.asList(nums[i], nums[j], nums[k]);
                        if (!result.contains(triplet)) { // Avoid duplicates
                            result.add(triplet);
                        }
                    }
                }
            }
        }

        return result;
    }

    // Optimized: Sorting + Two Pointers for 3Sum
    private static List<List<Integer>> threeSumWithSorting(int[] nums, int target) {
        if (nums == null || nums.length < 3)
            return new ArrayList<>();

        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums); // Sort the array to use two-pointer approach

        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicates for the current number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1, right = nums.length - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == target) {
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    // Skip duplicates for the second and third numbers
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        int[] arr = { -1, 0, 1, 2, -1, -4 };
        int target = 0;

        // Brute Force Approach
        System.out.println("Brute Force Result: " + threeSumBruteForce(arr, target));

        // Optimized Sorting + Two Pointer Approach
        System.out.println("Optimized Result: " + threeSumWithSorting(arr, target));
    }
}
