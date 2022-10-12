#include <iostream>

int main()
{
    int num1, num2;

    std::cin >> num1 >> num2;
    int divisor = num2, dividend = num1;

    while (dividend % divisor != 0)
    {
        int remainder = dividend % divisor;
        dividend = divisor;
        divisor = remainder;
    }
    
    std::cout << "HCF=" << divisor << std::endl;
    int hcf = divisor;
    int lcm = (num1 * num2) / hcf;
    std::cout << "LCM= " << lcm;
    return 0;
}

/*Tip:- LCM * HCF = Num1 *  Num2 */

/*
Time Comp:- O(min(num1,num2))
Space Comp:- O(1)
*/

/*
Problem:- https://nados.io/question/gcd-and-lcm
Articles:- https://nados.io/article/gcd-and-lcm
Videos:- https://www.youtube.com/watch?v=ZtDeDD1VYLk
*/