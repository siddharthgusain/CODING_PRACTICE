package Blind75;

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

public class RemoveNthFromLast {

    // Brute Force Approach: Two-pass method
    private ListNode removeNthFromEndBruteForce(ListNode head, int n) {
        if (head == null)
            return null;

        int length = 0;
        ListNode temp = head;

        // First pass: Count total nodes
        while (temp != null) {
            length++;
            temp = temp.next;
        }

        // Find the position from the start
        int indexToRemove = length - n;

        // If we need to remove the head
        if (indexToRemove == 0) {
            return head.next;
        }

        // Second pass: Reach the node before the one to be deleted
        temp = head;
        for (int i = 0; i < indexToRemove - 1; i++) {
            temp = temp.next;
        }

        // Remove the Nth node from end
        temp.next = temp.next.next;

        return head;
    }

    // Optimized Approach: Two-pointer method
    private ListNode removeNthFromEndOptimized(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode slow = dummy, fast = dummy;

        // Move fast pointer N steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        // Move both pointers until fast reaches the end
        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // Remove the Nth node from end
        slow.next = slow.next.next;

        return dummy.next;
    }

    public static void main(String[] args) {
        RemoveNthFromLast solution = new RemoveNthFromLast();

        // Example List: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

        // Remove 2nd node from end (Expected output: 1 -> 2 -> 3 -> 5)
        ListNode result = solution.removeNthFromEndOptimized(head, 2);

        // Print the result
        printList(result);
    }

    private static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " -> ");
            head = head.next;
        }
        System.out.println("null");
    }
}
