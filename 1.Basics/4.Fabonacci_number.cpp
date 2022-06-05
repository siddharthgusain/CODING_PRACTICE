#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int first_number = 0, second_number = 1;
    if (num == 1)
        std::cout << first_number << std::endl;
    else if (num == 2)
        std::cout << first_number << " " << second_number << std::endl;
    else if (num > 2)
    {
        std::cout << first_number << " " << second_number << " ";
        for (int itr = 3; itr <= num; itr++)
        {
            int result = first_number + second_number;
            std::cout << result << " ";
            first_number = second_number;
            second_number = result;
        }
    }
    return 0;
}

/*
Time Comp:- O(n)
Space Comp:- O(1)
*/

/*
Problem:- https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1
Articles:- https://www.geeksforgeeks.org/program-to-print-first-n-fibonacci-numbers/
Videos:- https://www.youtube.com/watch?v=P07sxSfcF40
*/