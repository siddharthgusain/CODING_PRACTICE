package Blind75;

public class MissingNumber {
    private static int missingNumberWithoutBitOperation(int[] nums) {
        int arrLen = 0;
        int arrSum = 0;
        for(int i=1;i<=nums.length;i++){
            arrSum = arrSum + nums[i-1];
            arrLen = arrLen + i;
        }
        return arrLen-arrSum;
    }

    private static int missingNumberWithBitOperation(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = ans ^ i;
        }
        for (int i = 0; i < nums.length; i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] list = {0,1,2,4,5};
        System.out.println(missingNumberWithoutBitOperation(list));
        System.out.println(missingNumberWithBitOperation(list));
    }
}
