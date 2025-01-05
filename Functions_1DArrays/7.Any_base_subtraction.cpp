#include <iostream>

int main()
{
    int base, num1, num2;
    std::cin >> base >> num1 >> num2;
    int carry = 0, power = 1, result = 0;
    while (num2)
    {
        int digit1 = num1 % 10;
        num1 = num1 / 10;
        int digit2 = num2 % 10;
        num2 = num2 / 10;
        int result_digit;
        digit2 = digit2 + carry;
        if (digit2 >= digit1)
        {
            carry = 0;
            result_digit = digit2 - digit1;
        }
        else
        {
            carry = -1;
            result_digit = (digit2 + base) - digit1;
        }
        result = result + result_digit * power;
        power = power * 10;
    }

    std::cout << result;
    return 0;
}

/*
Problem:-  https://nados.io/question/any-base-subtraction
Articles:- https://nados.io/article/any-base-subtraction
Videos:- https://www.youtube.com/watch?v=TJtXba11yNU
*/
