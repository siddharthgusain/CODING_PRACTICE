#include <iostream>

int factorial(int num)
{
    if (num == 1)
        return 1;
    if (num == 2)
        return 2;
    int partial_fac = factorial(num - 1);
    return num * partial_fac;
}

int main()
{
    int num;
    std::cin >> num;

    std::cout << factorial(num);
    return 0;
}