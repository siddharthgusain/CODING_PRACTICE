package blind75;

import java.util.Arrays;
import java.util.HashMap;

public class TwoSum {
    // Brute Force
    private static int[] twoSumBruteForce(int[] nums, int target) {
        if (nums == null || nums.length < 2)
            return null;

        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target && nums[j] != nums[i]) { // Preventing both Elements to be same
                    return new int[] { i, j };
                }
            }
        }

        return null;
    }

    // Unsorted With Hashmap
    private static int[] twoSumWithHashMap(int[] nums, int target) {
        if (nums == null || nums.length < 2)
            return null;

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement) && complement != nums[i]) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }

        return null;
    }

    // Sorting with Two Pointer
    private static int[] twoSumWithSorting(int[] nums, int target) {
        if (nums == null || nums.length < 2)
            return null;

        int[][] numWithIndex = new int[nums.length][2];
        for (int i = 0; i < nums.length; i++) { // n
            numWithIndex[i][0] = nums[i];
            numWithIndex[i][1] = i; // Store the original index
        }

        // Sort based on values
        Arrays.sort(numWithIndex, (a, b) -> Integer.compare(a[0], b[0])); // nlogn

        int left = 0, right = nums.length - 1;
        while (left < right) {
            int sum = numWithIndex[left][0] + numWithIndex[right][0];
            if (sum == target && numWithIndex[left][0] != numWithIndex[right][0]) {
                return new int[] { numWithIndex[right][1], numWithIndex[left][1] };
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return null;
    }

    public static void main(String[] args) {
        int[] arr = {}; // Can Contain Duplicates , Negative
        int target = 10;

        System.out.println(Arrays.toString(twoSumBruteForce(arr, target)));
        System.out.println(Arrays.toString(twoSumWithHashMap(arr, target)));
        System.out.println(Arrays.toString(twoSumWithSorting(arr, target)));

    }
}
