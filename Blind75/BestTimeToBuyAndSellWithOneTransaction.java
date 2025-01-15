package blind75;

public class BestTimeToBuyAndSellWithOneTransaction {

    private static int bestTimeToBuyAndSellBruteForce(int[] arr) {
        if (arr == null || arr.length == 0)
            return 0;
        if (arr.length == 1)
            return 0;

        int maxProfit = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] > arr[i]) {
                    maxProfit = Math.max(maxProfit, arr[j] - arr[i]);
                }
            }
        }
        return maxProfit;
        // O(n2)
    }

    private static int bestTimeToBuyAndSellSinglePass(int[] arr) {
        int maxProfit = 0;
        int minTillNow = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < minTillNow) {
                minTillNow = arr[i];
            }
            int profit = arr[i] - minTillNow;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        return maxProfit;
        // O(n)
    }

    public static void main(String[] args) {
        int[] arr = { 7, 1, 5, 3, 6, 4 };
        System.out.println(bestTimeToBuyAndSellBruteForce(arr));
        System.out.println(bestTimeToBuyAndSellSinglePass(arr));
    }
}
