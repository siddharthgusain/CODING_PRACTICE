package Blind75;

public class ContainerWithMostWater {

    private static int maxAreaBruteForce(int[] height) {
        int maxArea = 0;
        for (int i = 0; i < height.length; i++) {
            for (int j = i + 1; j < height.length; j++) {
                int area = Math.min(height[i], height[j]) * (j - i);
                maxArea = Math.max(maxArea, area);
            }
        }
        return maxArea;
        // O(n2)
    }

    private static int maxAreaTwoPointer(int[] height) {
        int maxArea = 0;
        int left = 0, right = height.length - 1;

        while (left < right) {
            int area = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(maxArea, area);

            // Move the smaller height pointer inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
        // O(n)
    }

    public static void main(String[] args) {
        int[] arr = { 10, 8, 6, 4, 5, 3, 2, 1 };
        System.out.println(maxAreaBruteForce(arr));
        System.out.println(maxAreaTwoPointer(arr));
    }
}
