#include <iostream>

int count_digits(int num)
{
    int count = 0;
    while (num)
    {
        count++;
        num = num / 10;
    }
    return count;
}

int main()
{
    int number;
    std::cin >> number;
    std::cout << count_digits(number);
    return 0;
}

/*
Time Comp:- O(digits)
Space Comp:- O(1)
*/

/*
Problem:- https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
Articles:- https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/
Videos:- https://www.youtube.com/watch?v=Ue3MTpyPHoU
*/