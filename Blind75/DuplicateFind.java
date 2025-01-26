package Blind75;

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class DuplicateFind {

    private static boolean findDuplicateBruteForce(int[] arr) {
        if (arr.length <= 1)
            return false;
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j]) {
                    return true;
                }
            }
        }
        return false;
        // O(n2)
    }

    private static boolean findDuplicateSorting(int[] arr) {
        int[] tempArr = arr.clone();
        Arrays.sort(tempArr);

        for (int i = 0; i < tempArr.length - 1; i++) {
            if (tempArr[i] == tempArr[i + 1]) {
                return true;
            }
        }

        return false;
        // O(nlogn + n)
    }

    private static boolean findDuplicateHashMap(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(arr[i])) {
                return true;
            }
            map.put(arr[i], 1);
        }

        return false;
        // Time: O(n)
        // Space: O(n)
    }

    private static boolean findDuplicateHashSet(int[] arr) {
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < arr.length; i++) {
            if (set.contains(arr[i])) {
                return true;
            }
            set.add(arr[i]);
        }

        return false;
        // Time: O(n)
        // Space: O(n)
    }

    public static void main(String[] args) {
        int[] arr = { 4, 5, 6, 7 };
        System.out.println(findDuplicateBruteForce(arr));
        System.out.println(findDuplicateSorting(arr));
        System.out.println(findDuplicateHashMap(arr));
        System.out.println(findDuplicateHashSet(arr));
    }
}
