#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse k nodes in the linked list
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || k <= 1)
        return head;

    // Function to check if there are at least k nodes left in the list
    auto hasKNodes = [](ListNode *current, int k)
    {
        while (current && k > 0)
        {
            current = current->next;
            k--;
        }
        return k == 0;
    };

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prevGroupEnd = &dummy;

    while (hasKNodes(prevGroupEnd->next, k))
    {
        ListNode *groupStart = prevGroupEnd->next;
        ListNode *groupEnd = groupStart;

        // Move groupEnd to the end of the k-group
        for (int i = 1; i < k; i++)
        {
            groupEnd = groupEnd->next;
        }

        ListNode *nextGroupStart = groupEnd->next;
        groupEnd->next = nullptr;

        // Reverse the k-group and attach it to the previous group's end
        prevGroupEnd->next = reverseList(groupStart);
        groupStart->next = nextGroupStart;

        // Move prevGroupEnd to the end of the reversed group
        prevGroupEnd = groupStart;
    }

    return dummy.next;
}

// Helper function to reverse a linked list
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *current = head;

    while (current)
    {
        ListNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
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

// Main function to test k-reverse in a linked list
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    // Print original list
    std::cout << "Original List: ";
    printList(head);

    // Reverse in groups of k
    int k = 3;
    head = reverseKGroup(head, k);

    // Print the list after reversing in groups of k
    std::cout << "List after reversing in groups of " << k << ": ";
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
