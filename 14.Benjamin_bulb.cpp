#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        std::cout << (i * i) << " ";
    }
}

/*
Problem:- https://nados.io/question/the-curious-case-of-benjamin-bulbs
Articles:- https://nados.io/article/the-curious-case-of-benjamin-bulbs
Videos:- https://www.youtube.com/watch?v=7IbWTFOUP1U
*/