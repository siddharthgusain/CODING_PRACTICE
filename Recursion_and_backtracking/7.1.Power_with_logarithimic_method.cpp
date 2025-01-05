#include <iostream>

int pow(int num, int power)
{
    if (power == 0)
        return 1;

    int result = pow(num, power / 2);
    int partial_pow = result * result;

    if (power % 2 == 0)
        return partial_pow;
    else
        return partial_pow * num;
}

int main()
{
    int num, power;
    std::cin >> num >> power;

    std::cout << pow(num, power);
    return 0;
}