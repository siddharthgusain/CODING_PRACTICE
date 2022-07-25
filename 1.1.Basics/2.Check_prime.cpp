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
        std::cout << "Not Prime" << std::endl;
    else
        std::cout << "Is Prime" << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        is_prime(num);
    }
    return 0;
}

/*
Time comp:- O(n*sqrt(num))
Space comp:- O(1)
*/

/*
Problem:- https://practice.geeksforgeeks.org/problems/prime-number2314/1
Articles:- https://www.geeksforgeeks.org/prime-numbers/
Videos:- https://www.youtube.com/watch?v=HXSfAyjWM8A&t=1s
*/