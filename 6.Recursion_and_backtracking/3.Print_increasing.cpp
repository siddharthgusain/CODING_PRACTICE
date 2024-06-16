#include <iostream>

void print_increasing(int number)
{
    if (number == 0)
        return;
    print_increasing(number - 1); // Head Recursion
    std::cout << number << std::endl;
}

int main()
{
    int number;
    std::cin >> number;
    print_increasing(number);
    return 0;
}