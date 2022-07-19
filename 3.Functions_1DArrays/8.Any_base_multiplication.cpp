#include <iostream>

int any_base_addition(int base, int num1, int num2)
{
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

    return result;
}

int get_product_of_single_digit(int base, int num, int digit)
{
    int carry = 0, power = 1, result = 0;
    while (num || carry > 0)
    {
        int d = num % 10;
        num = num / 10;
        int multi_result = digit * d + carry;
        carry = multi_result / 10;
        multi_result = multi_result % 10;

        result = result + multi_result * power;
        power = power * 10;
    }
    return result;
}

int main()
{
    int num1, num2, base;
    std::cin >> base >> num1 >> num2;
    int power = 1, result = 0;
    while (num2)
    {
        int num2_digit = num2 % 10;
        num2 = num2 / 10;
        int partial_sum = get_product_of_single_digit(base, num1, num2_digit); // get the partial sum
        partial_sum = partial_sum * power;                                     // shift with power for addition
        power = power * 10;                                                    // increase power by 10 for next partial sum
        result = any_base_addition(base, result, partial_sum);                 // add the partial sum
    }

    std::cout << result;
    return 0;
}

/*
Problem:- https://nados.io/question/any-base-multiplication
Articles:- https://nados.io/article/any-base-multiplication
Videos:- https://youtu.be/_jcwos0_pSg
*/