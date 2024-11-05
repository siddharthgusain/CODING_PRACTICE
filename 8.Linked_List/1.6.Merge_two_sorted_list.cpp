#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    // Create a dummy node to simplify the merging process
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    // Traverse both lists and merge them in sorted order
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            current->next = l1;
            l1 = l1->next;
        }
        else
        {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    // Append the remaining nodes, if any
    if (l1)
    {
        current->next = l1;
    }
    else
    {
        current->next = l2;
    }

    // The head of the merged list is next to the dummy node
    ListNode *mergedHead = dummy->next;
    delete dummy; // Free up the dummy node memory
    return mergedHead;
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

// Main function to test the merge
int main()
{
    // Create first sorted linked list: 1 -> 2 -> 4
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    // Create second sorted linked list: 1 -> 3 -> 4
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Merge the two sorted linked lists
    ListNode *mergedList = mergeTwoLists(l1, l2);

    // Print the merged linked list
    std::cout << "Merged List: ";
    printList(mergedList);

    // Free the memory of the merged list
    while (mergedList)
    {
        ListNode *temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
