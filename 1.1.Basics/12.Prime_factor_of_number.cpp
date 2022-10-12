#include <iostream>

int main()
{
    int num;
    std::cin >> num;

    for (int div = 2; div * div < num; div++)
    {
        while (num % div == 0) // Run till that number divides actual number
        {
            std::cout << div << " ";
            num = num / div;
        }
    }

    if (num != 1) // edge case
        std::cout << num;

    return 0;
}

/*
Time Complexity: O(n^(1/2) log n)
Space Comp:- O(1)
*/

/*
Problem:- https://nados.io/question/prime-factorisation-of-a-number
Articles:- https://nados.io/article/prime-factorisation-of-a-number
https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
Videos:- https://www.youtube.com/watch?v=5gFC-ayyQMk
*/