package blind75;

import java.util.Arrays;

public class ProductArrayExceptSelf {

    private static int[] productExceptSelfBruteForce(int[] arr) {
        int[] ans = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            int product = 1;
            for (int j = 0; j < arr.length; j++) {
                if (j == i)
                    continue;
                product *= arr[j];
            }
            ans[i] = product;
        }

        return ans;
        // Time : O(n2)
    }

    private static int[] productExceptSelfDivisionApproach(int[] arr) {
        // Find Total Array product
        // Divide by current element to remove it from product
        int[] ans = new int[arr.length];
        int product = 1;
        for (int i = 0; i < arr.length; i++) {
            product *= arr[i];
        }

        for (int i = 0; i < arr.length; i++) {
            ans[i] = product / arr[i];
        }

        return ans;
        // Time : O(n)
    }

    private static int[] productExceptSelfPrefixAndSuffixArray(int[] arr) {
        // If Division is not allowed?
        int[] ans = new int[arr.length];
        int[] prefixArray = new int[arr.length];
        int[] suffixArray = new int[arr.length];

        prefixArray[0] = 1;
        for (int i = 1; i < arr.length; i++) {
            prefixArray[i] = prefixArray[i - 1] * arr[i - 1];
        }

        suffixArray[arr.length - 1] = 1;
        for (int i = arr.length - 2; i >= 0; i--) {
            suffixArray[i] = suffixArray[i + 1] * arr[i + 1];
        }

        for (int i = 0; i < arr.length; i++) {
            ans[i] = prefixArray[i] * suffixArray[i];
        }

        return ans;
        // Time : O(n)
        // Space: O(2*n)
    }

    private static int[] productExceptSelfWithoutExtraSpace(int[] arr) {
        int n = arr.length;
        int[] output = new int[n];

        // Initialize the output array with 1
        Arrays.fill(output, 1);

        // Compute the left product for each index
        int left = 1;
        for (int i = 0; i < n; i++) {
            output[i] *= left;
            left *= arr[i];
        }

        // Compute the right product for each index
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= right;
            right *= arr[i];
        }

        return output;
        // Time: O(n)
        // Space: O(1)
    }

    public static void main(String[] args) {
        int[] array = { 1, 2, 3, 4 };
        System.out.println(Arrays.toString(productExceptSelfBruteForce(array)));
        System.out.println(Arrays.toString(productExceptSelfDivisionApproach(array)));
        System.out.println(Arrays.toString(productExceptSelfPrefixAndSuffixArray(array)));
        System.out.println(Arrays.toString(productExceptSelfWithoutExtraSpace(array)));
    }
}
