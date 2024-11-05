#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to check for palindrome recursively
bool isPalindromeUtil(ListNode *left, ListNode *&right)
{
    // Base case: reached the end of the list
    if (!right)
        return true;

    // Recursive call, moving right pointer ahead
    bool isPal = isPalindromeUtil(left, right->next);

    // Check the current values
    if (!isPal)
        return false; // If not a palindrome in the deeper recursion

    // Compare values from left and right pointers
    bool isEqual = (left->val == right->val);
    // Move the left pointer one step ahead
    left = left->next;

    return isEqual; // Return the comparison result
}

// Function to check if the linked list is a palindrome
bool isPalindrome(ListNode *head)
{
    ListNode *right = head; // Initialize right pointer at the head
    return isPalindromeUtil(head, right);
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

// Main function to test if a linked list is a palindrome
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1 (Palindrome)
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(2);
    head1->next->next->next->next = new ListNode(1);

    std::cout << "List 1: ";
    printList(head1);
    std::cout << "Is palindrome: " << (isPalindrome(head1) ? "Yes" : "No") << std::endl;

    // Create a linked list: 1 -> 2 -> 3 -> 4 (Not a palindrome)
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);

    std::cout << "List 2: ";
    printList(head2);
    std::cout << "Is palindrome: " << (isPalindrome(head2) ? "Yes" : "No") << std::endl;

    // Free the memory of the lists
    while (head1)
    {
        ListNode *temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2)
    {
        ListNode *temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
