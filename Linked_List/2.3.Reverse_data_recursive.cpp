#include <iostream>
#include <vector>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to reverse the data in the linked list recursively
void reverseDataHelper(ListNode *head, std::vector<int> &data, int index)
{
    if (!head)
        return; // Base case: if the list is empty

    // Recursive call for the next node
    reverseDataHelper(head->next, data, index + 1);

    // Assign the values in reverse order
    head->val = data[index];
}

// Function to reverse the data in the linked list
void reverseData(ListNode *head)
{
    std::vector<int> data;
    ListNode *current = head;

    // Store the data of the linked list in a vector
    while (current)
    {
        data.push_back(current->val);
        current = current->next;
    }

    // Start the recursive process to reverse the data
    reverseDataHelper(head, data, 0);
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

// Main function to test reversing the data in the linked list
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

    // Reverse the data in the linked list
    reverseData(head);

    // Print the list after reversing data
    std::cout << "List after reversing data: ";
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
