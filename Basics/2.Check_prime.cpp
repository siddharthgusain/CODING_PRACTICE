#include <iostream>

void is_prime(int num)
{
    if (num <= 1) // Negative and 0 Case
    {
        std::cout << "Neither a Prime Nor a Composite Number" << std::endl;
        return;
    }
    bool is_prime = false;
    for (int div = 2; div * div <= num; div++)
    {
        if (num % div == 0)
        {
            is_prime = true;
            break;
        }
    }

    if (is_prime)
        std::cout << "Prime" << std::endl;
    else
        std::cout << "Not Prime" << std::endl;
}

int main()
{
    int n;
    std::cout << "Enter Number of Test Cases:";
    std::cin >> n; // number of test cases
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter Number:";
        int num;
        std::cin >> num;
        is_prime(num);
    }
    return 0;
}

/*
Problem:- https://practice.geeksforgeeks.org/problems/prime-number2314/1
Articles:- https://www.geeksforgeeks.org/prime-numbers/
Videos:- https://www.youtube.com/watch?v=HXSfAyjWM8A&t=1s
*/