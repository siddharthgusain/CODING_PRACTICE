#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to find the middle of the linked list using slow and fast pointers
ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;       // Move slow pointer by 1
        fast = fast->next->next; // Move fast pointer by 2
    }
    return slow; // Slow is now at the middle
}

// Function to reverse the linked list starting from the given node
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;

    while (current)
    {
        ListNode *nextNode = current->next; // Store next node
        current->next = prev;               // Reverse the link
        prev = current;                     // Move prev to current
        current = nextNode;                 // Move to next node
    }
    return prev; // Return the new head of the reversed list
}

// Function to fold the linked list
void foldList(ListNode *head)
{
    if (!head || !head->next)
        return; // Handle empty or single node list

    // Step 1: Find the middle of the list
    ListNode *mid = findMiddle(head);
    ListNode *secondHalf = mid->next; // Start of the second half
    mid->next = nullptr;              // Split the list into two halves

    // Step 2: Reverse the second half of the list
    secondHalf = reverseList(secondHalf);

    // Step 3: Merge the two halves
    ListNode *firstHalf = head;
    while (secondHalf)
    {
        ListNode *temp1 = firstHalf->next; // Store the next node in the first half
        ListNode *temp2 = secondHalf;      // Current node from the second half

        firstHalf->next = secondHalf;  // Link the current first half node to the second half
        secondHalf = secondHalf->next; // Move to the next node in the second half
        firstHalf->next->next = temp1; // Link back to the next node in the first half
        firstHalf = temp1;             // Move to the next node in the first half
    }
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

// Main function to test folding the linked list
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original List: ";
    printList(head);

    // Fold the linked list
    foldList(head);

    std::cout << "Folded List: ";
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
