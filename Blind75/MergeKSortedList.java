package Blind75;

import java.util.PriorityQueue;

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

public class MergeKSortedList {
    private ListNode mergeKListsHelper(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode left = mergeKListsHelper(lists, start, mid);
        ListNode right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
        // Time Comp : NlogK
    }

    private ListNode merge(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            } else {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }

        curr.next = (l1 != null) ? l1 : l2;

        return dummy.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        return mergeKListsHelper(lists, 0, lists.length - 1);
    }

    public ListNode mergeKListWithHeap(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }

        // Min Heap to store the smallest node from each list
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);

        // Add first node of each list to heap
        for (ListNode list : lists) {
            if (list != null) {
                minHeap.add(list);
            }
        }

        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        // Extract the min node and add the next node from that list back to the heap
        while (!minHeap.isEmpty()) {
            ListNode minNode = minHeap.poll();
            curr.next = minNode;
            curr = curr.next;

            if (minNode.next != null) {
                minHeap.add(minNode.next);
            }
        }

        return dummy.next;
        // Time Comp : NlogK
        // Space Comp: O(K)
    }

}

/*
 * Extreme Naive Solution
 * 1. Traverse K Lists -> Add Elements to Array (N * K)
 * 3. Sort this Array -> NlogN
 * 4. Create a new List from this Array -> O(N)
 * Time Comp : N*K + (N*K)Log(N*K) + O(N*K)
 * Space Comp: O(N*K) + O(N*K)
 */