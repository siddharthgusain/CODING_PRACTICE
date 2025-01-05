#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reorder the linked list into odd and even indexed nodes
ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *odd = head;        // Starting from the first node (odd)
    ListNode *even = head->next; // Starting from the second node (even)
    ListNode *evenHead = even;   // To connect the end of the odd list to the start of the even list

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    // Connect the last node of the odd list to the head of the even list
    odd->next = evenHead;

    return head;
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

// Main function to test the odd-even reordering of the linked list
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

    // Reorder the list to odd-even
    head = oddEvenList(head);

    // Print the reordered list
    std::cout << "Reordered List (Odd-Even): ";
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
