package Companies.Rippling;

import java.util.*;

public class UserTimeStamp {

    static class Log {
        int userId;
        long timestamp;

        public Log(int userId, long timestamp) {
            this.userId = userId;
            this.timestamp = timestamp;
        }
    }

    public static void main(String[] args) {
        // Sample logs (userId, timestamp)
        List<Log> logs = Arrays.asList(
                new Log(3, 1620045600000L), // userId=3, timestamp=1620045600000
                new Log(2, 1620045605000L), // userId=2, timestamp=1620045605000
                new Log(1, 1620045610000L) // userId=1, timestamp=1620045610000
        );

        // Call the method
        int result = countUsersWithConditions(logs);
        System.out.println("Number of users satisfying the conditions: " + result);
    }

    public static int countUsersWithConditions(List<Log> logs) {
        // Sort logs by timestamp in ascending order
        logs.sort(Comparator.comparingLong(log -> log.timestamp));

        // Find the unique user IDs for compression
        TreeSet<Integer> userIds = new TreeSet<>();
        for (Log log : logs) {
            userIds.add(log.userId);
        }

        // Map userId to a compressed index
        Map<Integer, Integer> userIdToIndex = new HashMap<>();
        int index = 1;
        for (int userId : userIds) {
            userIdToIndex.put(userId, index++);
        }

        // Fenwick Tree for counting users
        FenwickTree fenwickTree = new FenwickTree(userIds.size());
        int count = 0;

        for (Log log : logs) {
            // Query the number of users with userId > current userId
            int greaterUsers = fenwickTree.sumRange(userIdToIndex.size())
                    - fenwickTree.sumRange(userIdToIndex.get(log.userId));
            count += greaterUsers;

            // Update Fenwick Tree with current userId
            fenwickTree.update(userIdToIndex.get(log.userId), 1);
        }

        return count;
    }

    // Fenwick Tree implementation
    static class FenwickTree {
        private int[] tree;

        public FenwickTree(int size) {
            tree = new int[size + 1];
        }

        public void update(int index, int value) {
            while (index < tree.length) {
                tree[index] += value;
                index += index & -index;
            }
        }

        public int sumRange(int index) {
            int sum = 0;
            while (index > 0) {
                sum += tree[index];
                index -= index & -index;
            }
            return sum;
        }
    }
}