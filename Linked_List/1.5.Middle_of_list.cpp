#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_front(50);

    auto slow_ptr = list.begin();
    auto fast_ptr = list.begin();

    while (fast_ptr != list.end())
    {
        slow_ptr++;
        // Check if fast_ptr can be moved two steps
        if (std::next(fast_ptr) != list.end())
        {
            fast_ptr++;
            fast_ptr++; // Move fast_ptr two steps
        }
        else
        {
            break; // Break if there is no next node for fast_ptr
        }
    }

    // Check if slow_ptr is valid before dereferencing
    if (slow_ptr != list.end())
    {
        std::cout << "The middle value of the list is: " << *slow_ptr << std::endl;
    }
    else
    {
        std::cout << "The list is empty." << std::endl;
    }
    return 0; // Don't forget to return from main
}