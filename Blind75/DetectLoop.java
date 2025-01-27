package Blind75;

import java.util.HashSet;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class DetectLoop {

    // Function to detect loop using a naive approach
    boolean detectLoopNaive(ListNode head) {
        ListNode current = head;

        while (current != null) {
            ListNode temp = head;

            // Check if any node points back to the current node
            while (temp != current) {
                if (temp.next == current) {
                    return true; // Loop detected
                }
                temp = temp.next;
            }
            current = current.next;
        }
        return false; // No loop detected
        // Time: O(n2)
        // Space: O(1)
    }

    // Function to detect loop using hashing
    boolean detectLoopUsingHashing(ListNode head) {
        HashSet<ListNode> visited = new HashSet<>();
        ListNode current = head;

        while (current != null) {
            // If the node is already in the set, a loop is detected
            if (visited.contains(current)) {
                return true;
            }
            // Add the node to the set
            visited.add(current);
            current = current.next;
        }
        return false; // No loop detected
    }

    // Function to detect loop using Floyd’s Algorithm
    boolean detectLoopUsingFloyds(ListNode head) {
        ListNode slow = head, fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next; // Move slow pointer by one step
            fast = fast.next.next; // Move fast pointer by two steps

            if (slow == fast) { // If they meet, a loop is detected
                return true;
            }
        }
        return false; // No loop detected
    }

    public static void main(String[] args) {

    }
}
