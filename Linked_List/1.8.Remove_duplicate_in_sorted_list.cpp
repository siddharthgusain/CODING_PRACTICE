#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove duplicates from a sorted linked list
ListNode *removeDuplicates(ListNode *head)
{
    if (!head)
        return nullptr;

    ListNode *current = head;

    while (current->next != nullptr)
    {
        if (current->val == current->next->val)
        {
            // Duplicate node found, remove it
            ListNode *duplicate = current->next;
            current->next = current->next->next;
            delete duplicate; // Free the memory of the duplicate node
        }
        else
        {
            // Move to the next node if no duplicate
            current = current->next;
        }
    }

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

// Main function to test remove duplicates from a sorted linked list
int main()
{
    // Create a sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Print original list
    std::cout << "Original List: ";
    printList(head);

    // Remove duplicates from the sorted linked list
    head = removeDuplicates(head);

    // Print the list after removing duplicates
    std::cout << "List after removing duplicates: ";
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
