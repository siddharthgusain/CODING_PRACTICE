#include <iostream>
#include <math.h>

int main()
{
    int number, inverse_number = 0;
    int position = 1;
    std::cin >> number;
    if (number >= 0 && number < 10)
    {
        std::cout << number;
    }
    while (number)
    {
        int digit = number % 10; // extract digit
        inverse_number += position * pow(10, digit - 1);
        number /= 10; // remove digit from number
        position++;   // increase position
    }
    std::cout << inverse_number;
}

/*
Time Comp:- O(log10(number))
Space Comp:- O(1)
*/

/*
Problem:- https://nados.io/question/inverse-of-a-number
Articles:- https://nados.io/article/inverse-a-number
Videos:- https://www.youtube.com/watch?v=O7PlWc9lOzg
*/