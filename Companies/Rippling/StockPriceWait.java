package Rippling;

import java.util.*;

public class StockPriceWait {
    public static int[] calculateWaitDays(int[] prices) {
        int n = prices.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            // While stack is not empty and the current price is greater than the price at
            // the stack's top index
            while (!stack.isEmpty() && prices[i] > prices[stack.peek()]) {
                int idx = stack.pop(); // Get the index of the stock price that will have a higher price later
                result[idx] = i - idx; // Calculate days to wait
            }
            stack.push(i); // Push the current index onto the stack
        }

        // Remaining indices in the stack have no higher price, so their wait days
        // remain 0
        while (!stack.isEmpty()) {
            result[stack.pop()] = 0;
        }

        return result;
    }

    public static void main(String[] args) {
        int[] prices = { 4, 4, 6, 12, 5, 8 };
        int[] waitDays = calculateWaitDays(prices);

        // Output the result
        System.out.println(Arrays.toString(waitDays)); // Output: [2, 1, 1, 0, 1, 0]
    }
}
