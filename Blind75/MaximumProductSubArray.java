package blind75;

import java.util.Arrays;

public class MaximumProductSubArray {

    private static int maxProductBruteForce1(int[] arr) {
        if (arr.length == 0)
            return 0;
        if (arr.length == 1)
            return arr[0];

        int maxProduct = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            for (int j = i; j < arr.length; j++) {
                int currentProduct = 1;
                for (int k = i; k <= j; k++) {
                    currentProduct *= arr[k];
                }
                maxProduct = Math.max(maxProduct, currentProduct);
            }
        }
        return maxProduct;
        // O(n3)
    }

    private static int maxProductBruteForce2(int[] arr) {
        if (arr.length == 0)
            return 0;
        if (arr.length == 1)
            return arr[0];

        int maxProduct = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            int currentProduct = 1;
            for (int j = i; j < arr.length; j++) {
                currentProduct *= arr[j];
                maxProduct = Math.max(maxProduct, currentProduct);
            }
        }
        return maxProduct;
        // O(n2)
    }

    private static int maxProductPrefixAndSuffix(int[] arr) {
        if (arr.length == 0)
            return 0;
        if (arr.length == 1)
            return arr[0];

        int maxProduct = Integer.MIN_VALUE;
        int prefixProduct = 1;
        int suffixProduct = 1;
        for (int i = 0; i < arr.length; i++) {
            if (prefixProduct == 0)
                prefixProduct = 1;
            if (suffixProduct == 0)
                suffixProduct = 1;

            prefixProduct *= arr[i];
            suffixProduct *= arr[arr.length - i - 1];
            int maxOfPrefixAndSuffix = Math.max(prefixProduct, suffixProduct);
            maxProduct = Math.max(maxProduct, maxOfPrefixAndSuffix);
        }

        return maxProduct;
    }

    private static int[] maxProductIndexes(int[] arr) {
        int maxProduct = Integer.MIN_VALUE;
        int prefixProduct = 1, prefixStart = 0;
        int suffixProduct = 1, suffixStart = arr.length - 1;

        int startIndex = 0, endIndex = arr.length - 1;

        for (int i = 0; i < arr.length; i++) {
            if (prefixProduct == 0) {
                prefixProduct = 1;
                prefixStart = i;
            } else {
                prefixProduct *= arr[i];
            }

            if (prefixProduct > maxProduct) {
                maxProduct = prefixProduct;
                startIndex = prefixStart;
                endIndex = i;
            }

            if (suffixProduct == 0) {
                suffixProduct = 1;
                suffixStart = arr.length - i - 1;
            } else {
                suffixProduct *= arr[arr.length - i - 1];
            }

            if (suffixProduct > maxProduct) {
                maxProduct = suffixProduct;
                startIndex = arr.length - i - 1;
                endIndex = suffixStart;
            }
        }

        return new int[] { startIndex, endIndex };
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 0, 4, 5, 6 };
        System.out.println(maxProductBruteForce1(arr));
        System.out.println(maxProductBruteForce2(arr));
        System.out.println(maxProductPrefixAndSuffix(arr));
        System.out.println(Arrays.toString(maxProductIndexes(arr)));
    }
}
