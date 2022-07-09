#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int max = a;
    if (b >= max)
        max = b;

    if (c >= max)
        max = c;

    if (max == a)
    {
        std::cout << ((b * b + c * c) == (a * a));
    }
    else if (max == b)
    {
        std::cout << ((a * a + c * c) == (b * b));
    }
    else
    {
        std::cout << ((a * a + b * b) == (c * c));
    }
    return 0;
}

/*
Time Complexity: O(1)
Space Comp:- O(1)
*/

/*
Problem:- https://nados.io/question/pythagorean-triplet
Articles:- https://nados.io/article/pythagorean-triplet
Videos:- https://www.youtube.com/watch?v=w4bRrZCEz6o
*/