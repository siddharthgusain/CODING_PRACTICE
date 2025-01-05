#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list using recursion
ListNode *reverseListRecursive(ListNode *head)
{
    // Base case: if the list is empty or has reached the last node
    if (!head || !head->next)
        return head;

    // Recursively reverse the rest of the list
    ListNode *newHead = reverseListRecursive(head->next);

    // Reverse the current node's pointer
    head->next->next = head;
    head->next = nullptr;

    return newHead;
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

// Main function to test reversing the linked list recursively
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    std::cout << "Original List: ";
    printList(head);

    // Reverse the list using recursion
    head = reverseListRecursive(head);

    // Print the reversed list
    std::cout << "Reversed List: ";
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
