package blind75;

import java.util.Arrays;

public class FindMinInSortedArray {

    private static int findMinBruteForce1(int[] arr) {
        Arrays.sort(arr);
        return arr[0];
        // O(nlogn)
    }

    private static int findMinBruteForce2(int[] arr) {
        if (arr == null || arr.length == 0)
            return -1;
        if (arr.length == 1)
            return arr[0];

        int min = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        return min;
        // O(n)
    }

    private static int findMinBinarySearch(int[] arr) {
        if (arr == null || arr.length == 0)
            return -1;
        if (arr.length == 1)
            return arr[0];

        int left = 0;
        int right = arr.length - 1;
        int min = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= arr[left]) {
                min = Math.min(min, arr[left]);
                left = mid + 1;
            } else if (arr[mid] <= arr[right]) {
                min = Math.min(min, arr[mid]);
                right = mid - 1;
            }
        }

        return min;
        // O(logn)
    }

    public static void main(String[] args) {
        int[] arr = { 8, 9, -1, -2, 3, 4, 5, 6, 7 };

        System.out.println(findMinBruteForce1(arr));
        System.out.println(findMinBruteForce2(arr));
        System.out.println(findMinBinarySearch(arr));
    }
}
