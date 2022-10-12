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
        int rem = num % base;                  // get remainder
        converted_num += pow(10, power) * rem; // to make number
        num = num / base;                      // get quotient
        power++;
    }
    
    std::cout << converted_num;
    return 0;
}

/*
Problem:- https://nados.io/question/decimal-to-any-base
Articles:- https://nados.io/article/decimal-to-any-base
Videos:- https://youtu.be/lOsmPMihcTM
*/