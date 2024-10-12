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
    list.push_front(60);

    int k;
    std::cin >> k;

    auto slow_ptr = list.begin();
    auto fast_ptr = list.begin();

    for (int i = 1; i <= k; i++)
    {
        if (fast_ptr == list.end())
        {
            std::cout << "k is greater than the size of the list." << std::endl;
            return 1; // Exit if k is greater than the size
        }
        fast_ptr++;
    }

    while (fast_ptr != list.end())
    {
        slow_ptr++;
        fast_ptr++;
    }

    // Check if slow_ptr is valid before dereferencing
    if (slow_ptr != list.end())
    {
        std::cout << "The k-th node from the end is: " << *slow_ptr << std::endl;
    }
    else
    {
        std::cout << "The list is empty or k is out of bounds." << std::endl;
    }
    return 0; // Don't forget to return from main
}