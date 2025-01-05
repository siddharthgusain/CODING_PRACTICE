#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print the linked list in reverse using recursion
void printReverse(ListNode *head)
{
    if (!head)
        return;                    // Base case: if the list is empty or reached the end
    printReverse(head->next);      // Recursive call with the next node
    std::cout << head->val << " "; // Print the current node after the recursive call
}

// Main function to test printing the linked list in reverse
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the linked list in reverse
    std::cout << "Linked list in reverse: ";
    printReverse(head);
    std::cout << std::endl;

    // Free the memory of the list
    while (head)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
