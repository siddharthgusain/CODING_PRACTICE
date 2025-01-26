package Blind75;

public class SearchInRotatedSortedArray {

    private static int searchInRotatedSortedArrayBruteForce(int[] arr, int target) {
        for (int i = 0; i <= arr.length - 1; i++) {
            if (arr[i] == target) {
                return i;
            }
        }

        return -1;
        // O(n)
    }

    private static int searchInRotatedSortedArrayBinarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] >= arr[left]) {
                if (arr[left] <= target && target <= arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (arr[mid] <= arr[right]) {
                if (arr[mid] <= target && target <= arr[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
        // O(logn)
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        System.out.println(searchInRotatedSortedArrayBruteForce(arr, 9));
        System.out.println(searchInRotatedSortedArrayBinarySearch(arr, 9));
    }
}
