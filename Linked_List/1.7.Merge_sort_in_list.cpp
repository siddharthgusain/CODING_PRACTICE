#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle of the linked list (returns middle node)
ListNode *findMiddle(ListNode *head, ListNode *tail)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != tail && fast->next != tail) // Checking Next Null is to avoid Overflow
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to perform merge sort on the linked list with known head and tail
ListNode *mergeSort(ListNode *head, ListNode *tail)
{
    if (head == tail)
    {
        head->next = nullptr; // Ensure the last node is disconnected from the rest
        return head;
    }

    // Find the middle node
    ListNode *middle = findMiddle(head, tail);

    // Recursively sort the left and right halves
    ListNode *left = mergeSort(head, middle);
    ListNode *right = mergeSort(middle->next, tail);

    // Merge the sorted halves
    return merge(left, right);
}

// Function to print the linked list
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Main function to test merge sort on a linked list with head and tail
int main()
{
    // Create a linked list: 4 -> 2 -> 1 -> 3
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    ListNode *tail = head->next->next->next; // The tail node (3)

    // Print original list
    std::cout << "Original List: ";
    printList(head);

    // Perform merge sort on the linked list
    head = mergeSort(head, tail);

    // Print the sorted list
    std::cout << "Sorted List: ";
    printList(head);

    // Free the memory of the list
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
