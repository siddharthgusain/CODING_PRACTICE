#include <iostream>

void is_prime(int num)
{
    if (num <= 1)
    {
        std::cout << "Neither Prime nor composite";
        return;
    }
    bool flag = false;
    for (int div = 2; div * div <= num; div++)
    {
        if (num % div == 0)
        {
            flag = true;
            break;
        }
    }
    if (flag)
        return;
    else
        std::cout << num << std::endl;
}

int main()
{
    std::cout << "Enter number:" << std::endl;
    int num;
    std::cin >> num;
    for (int i = 2; i <= num; i++)
    {
        is_prime(i);
    }
    return 0;
}

/*
Time comp:- O(num*sqrt(n))
Space comp:- O(1)
*/

/*
Problem:- https://practice.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1
Articles:- https://www.geeksforgeeks.org/print-all-prime-numbers-less-than-or-equal-to-n/
Videos:- https://www.youtube.com/watch?v=YOmq-Jr3QIk
*/
