#include <iostream>
#include <math.h>

int decimal_to_any_base(int num, int base)
{
    int converted_num = 0;
    int power = 0;
    while (num)
    {
        int rem = num % base;                  // get remainder
        converted_num += pow(10, power) * rem; // to make number
        num = num / base;                      // get quotient
        power++;
    }
    return converted_num;
}

int any_base_to_decimal(int num, int base)
{
    int converted_num = 0;
    int power = 0;
    while (num)
    {
        int rem = num % 10;                      // get remainder
        converted_num += pow(base, power) * rem; // to make number
        num = num / 10;                          // get quotient
        power++;
    }
    return converted_num;
}

int main()
{
    int num;
    int base1;
    int base2;
    std::cin >> num >> base1 >> base2;
    int decimal_number = any_base_to_decimal(num, base1);
    int base2_number = decimal_to_any_base(decimal_number, base2);
    std::cout << base2_number;
    return 0;
}

/*
Problem:- https://nados.io/question/any-base-to-any-base
Articles:-https://nados.io/article/any-base-to-any-base
Videos:- https://youtu.be/LJ697zHLL0M
*/