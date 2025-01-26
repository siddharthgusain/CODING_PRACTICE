package Companies.Rippling;

import java.util.Arrays;

public class BoatsToSavePeople {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people); // Sort the array
        int left = 0; // Pointer for the lightest person
        int right = people.length - 1; // Pointer for the heaviest person
        int boats = 0; // Counter for the number of boats

        while (left <= right) {
            // If the lightest and heaviest can share a boat
            if (people[left] + people[right] <= limit) {
                left++; // Move the left pointer to the next lightest
            }
            // In either case, move the right pointer and use one boat
            right--;
            boats++;
        }

        return boats; // Return the total number of boats
    }

    public static void main(String[] args) {
        BoatsToSavePeople solution = new BoatsToSavePeople();
        int[] people = { 3, 2, 2, 1 };
        int limit = 3;
        System.out.println(solution.numRescueBoats(people, limit)); // Output: 3
    }
}
