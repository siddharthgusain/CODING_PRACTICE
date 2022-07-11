#include <iostream>

int main()
{
    int number;
    int digit;
    std::cin >> number >> digit;
    int count = 0;
    while (number)
    {
        int rem = number % 10;
        if (rem == digit)
            count++;
        number /= 10;
    }
    std::cout << "Count=" << count;
    return 0;
}