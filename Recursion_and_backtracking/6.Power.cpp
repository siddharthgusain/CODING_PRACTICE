#include <iostream>

int pow(int num, int power)
{
    if (power == 0)
        return 1;
    int partial_pow = pow(num, power - 1);
    return num * partial_pow;
}

int main()
{
    int num, power;
    std::cin >> num >> power;

    std::cout << pow(num, power);
    return 0;
}