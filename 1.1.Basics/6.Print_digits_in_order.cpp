#include <iostream>
#include <math.h>

int main()
{
    int number, temp;
    std::cin >> number;
    temp = number;
    int count = 0;
    if (number == 0)
    {
        return;
    }
    while (temp)
    {
        count++;
        temp = temp / 10;
    }
    int divisor = pow(10, count - 1);
    while (divisor)
    {
        int digit = number / divisor;
        std::cout << digit << std::endl;
        number = number % divisor;
        divisor = divisor / 10;
    }
    return 0;
}

/*
Time Comp:- O(log10(number))
Space Comp:- O(1)
*/

/*
Problem:-https://www.geeksforgeeks.org/c-program-to-print-all-digits-of-a-given-number/
Articles:- https://www.geeksforgeeks.org/c-program-to-print-all-digits-of-a-given-number/
Videos:- https://www.youtube.com/watch?v=gZp776a-pbQ
*/