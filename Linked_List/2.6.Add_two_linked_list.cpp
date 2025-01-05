#include <iostream>

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two linked lists recursively
ListNode *addTwoNumbersHelper(ListNode *l1, ListNode *l2, int &carry)
{
    // Base case: if both nodes are null and no carry, return null
    if (!l1 && !l2 && carry == 0)
    {
        return nullptr;
    }

    // Get the values from the current nodes or 0 if they are null
    int val1 = (l1 != nullptr) ? l1->val : 0;
    int val2 = (l2 != nullptr) ? l2->val : 0;

    // Calculate the sum including carry
    int sum = val1 + val2 + carry;
    carry = sum / 10; // Update carry for the next recursive call

    // Create a new node for the current digit
    ListNode *resultNode = new ListNode(sum % 10);

    // Recur for the next nodes
    resultNode->next = addTwoNumbersHelper(
        (l1 != nullptr) ? l1->next : nullptr,
        (l2 != nullptr) ? l2->next : nullptr,
        carry);

    return resultNode;
}

// Wrapper function to handle the carry and initialize recursion
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    return addTwoNumbersHelper(l1, l2, carry);
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

// Main function to test adding two linked lists
int main()
{
    // Create first linked list: 2 -> 4 -> 3 (represents 342)
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4 (represents 465)
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Print the input lists
    std::cout << "First List: ";
    printList(l1);
    std::cout << "Second List: ";
    printList(l2);

    // Add the two linked lists
    ListNode *result = addTwoNumbers(l1, l2);

    // Print the result list
    std::cout << "Sum List: ";
    printList(result);

    // Free the memory of the lists
    while (l1)
    {
        ListNode *temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2)
    {
        ListNode *temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result)
    {
        ListNode *temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
