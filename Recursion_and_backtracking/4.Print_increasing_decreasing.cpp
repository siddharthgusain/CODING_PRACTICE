#include <iostream>

void print_increasing_decreasing(int number)
{
    if (number == 0)
        return;
    std::cout << number << std::endl;
    print_increasing_decreasing(number - 1);
    std::cout << number << std::endl;
}

int main()
{
    int number;
    std::cin >> number;
    print_increasing_decreasing(number);
    return 0;
}