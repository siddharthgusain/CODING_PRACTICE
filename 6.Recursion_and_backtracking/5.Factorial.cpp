#include <iostream>

long long factorial(int num)
{
    if (num == 1)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    int num;
    std::cin >> num;
    long long result = factorial(num);
    std::cout << result;
    return 0;
}

/*
Question :- https://nados.io/question/factorial
Article:- https://nados.io/article/factorial
Video:- https://www.youtube.com/watch?v=m4rdYPuisKc
*/