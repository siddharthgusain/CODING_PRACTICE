#include <iostream>
#include <math.h>

int reverse_digits(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

int main()
{
    int num = 4562;
    std::cout << "Reverse of no. is " << reverse_digits(num);
    return 0;
}

/*
Time Comp:- O(log10(number))
Space Comp:- O(1)
*/

/*
Problem:-https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
Articles:- https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
Videos:- https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
*/