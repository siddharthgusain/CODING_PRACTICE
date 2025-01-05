#include <iostream>

int main()
{
    int number;
    int digit;
    std::cin >> number >> digit;
    int count = 0;
    while (number)
    {
        int rem = number % 10;
        if (rem == digit)
            count++;
        number /= 10;
    }
    std::cout << "Count=" << count;
    return 0;
}

/*
Problem:- https://nados.io/question/digit-frequency
Articles:- https://nados.io/article/digit-frequency
Videos:- https://youtu.be/U3VZNsMJpD4
*/