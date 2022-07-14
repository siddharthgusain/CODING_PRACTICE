#include <iostream>
#include <math.h>

int main()
{
    int num1, num2;
    int base;
    std::cin >> num1 >> num2 >> base;
    int carry = 0, multiplier = 1, result = 0;
    while (num1 > 0 || num2 > 0 || carry > 0)
    {
        int rem1 = num1 % 10;
        int rem2 = num2 % 10;
        int sum_of_digits = carry + rem1 + rem2;
        int result_digit = sum_of_digits % base;
        carry = sum_of_digits / base;
        result += multiplier * result_digit;
        multiplier *= 10;
        num1 /= 10;
        num2 /= 10;
    }

    std::cout << result;
    return 0;
}

/*
Problem:- https://nados.io/question/any-base-addition
Articles:-https://nados.io/article/any-base-addition
Videos:- https://youtu.be/YVpTjZRShqo
*/