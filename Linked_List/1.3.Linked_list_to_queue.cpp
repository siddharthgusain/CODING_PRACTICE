#include <iostream>
#include <forward_list>

class Queue
{
public:
    // Add an element to the back of the queue
    void add(int data)
    {
        singly_linked_list.push_front(data);
        // Since we add to the front, we need to ensure the order
        // We reverse the list to maintain the correct queue order
        if (this->size() > 1)
        {
            reverse();
        }
    }

    // Remove an element from the front of the queue
    int remove()
    {
        if (size() == 0)
        {
            return -1; // Indicate underflow
        }
        int value = peek();
        singly_linked_list.pop_front();
        return value;
    }

    // Peek at the front element of the queue
    int peek()
    {
        if (size() == 0)
        {
            return -1; // Indicate empty queue
        }
        return singly_linked_list.front();
    }

    // Get the current size of the queue
    int size()
    {
        int count = 0;
        for (const auto &item : singly_linked_list)
        {
            ++count; // Increment count for each element
        }
        return count; // Return the total count
    }

private:
    std::forward_list<int> singly_linked_list;

    // Helper function to reverse the singly linked list
    void reverse()
    {
        std::forward_list<int> reversed_list;
        for (const auto &item : singly_linked_list)
        {
            reversed_list.push_front(item);
        }
        singly_linked_list = std::move(reversed_list);
    }
};

int main()
{
    Queue q;
    q.add(1);
    q.add(2);
    q.add(3);

    std::cout << "Front element: " << q.peek() << std::endl;     // Should show 1
    std::cout << "Removing: " << q.remove() << std::endl;        // Should remove 1
    std::cout << "New front element: " << q.peek() << std::endl; // Should show 2
    std::cout << "Current size: " << q.size() << std::endl;      // Size should be 2

    return 0; // Don't forget to return from main
}