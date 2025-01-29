#include <iostream>
#include <math.h>

int main()
{
    int num;
    int base;
    int converted_num = 0;
    std::cin >> num >> base;
    int power = 0;
    while (num)
    {
        int rem = num % 10;                      // get remainder
        converted_num += pow(base, power) * rem; // to make number
        num = num / 10;                          // get quotient
        power++;
    }
    std::cout << converted_num;
    return 0;
}

/*
Problem:- https://nados.io/question/any-base-to-decimal
Articles:- https://nados.io/article/any-base-to-decimal
Videos:- https://youtu.be/F0aTGc2vS5s
*/