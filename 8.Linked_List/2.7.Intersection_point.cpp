#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to get the length of a linked list
int getLength(ListNode *head)
{
    int length = 0;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection of two linked lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Align the start of both lists
    while (lenA > lenB) // Move Long List by lenA -  LenB
    {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA)
    {
        headB = headB->next;
        lenB--;
    }

    // Traverse both lists together to find the intersection
    while (headA && headB)
    {
        if (headA == headB)
        {
            return headA; // Found the intersection
        }
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr; // No intersection
}

// Function to print the linked list (for debugging)
void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Main function to test intersection of two linked lists
int main()
{
    // Create first linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);

    // Create second linked list: 6 -> 4 -> 5 (intersection with headA)
    ListNode *headB = new ListNode(6);
    headB->next = headA->next->next; // 4 is the intersection point

    // Print the lists
    std::cout << "List A: ";
    printList(headA);
    std::cout << "List B: ";
    printList(headB);

    // Find intersection
    ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection)
    {
        std::cout << "Intersection at node with value: " << intersection->val << std::endl;
    }
    else
    {
        std::cout << "No intersection." << std::endl;
    }

    // Free the memory of the lists
    while (headA)
    {
        ListNode *temp = headA;
        headA = headA->next;
        delete temp;
    }
    while (headB)
    {
        ListNode *temp = headB;
        headB = headB->next;
        delete temp;
    }

    return 0;
}
