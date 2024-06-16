#include <iostream>

void print_decreasing(int number)
{
    if (number == 0) // Base Case
        return;
    std::cout << number << std::endl;
    print_decreasing(number - 1); // Tail Recursion
}

int main()
{
    int number;
    std::cin >> number;
    print_decreasing(number);
    return 0;
}