#include <iostream>

void pzz(int n)
{
    if (n == 0)
        return;
    std::cout << n + " ";
    pzz(n - 1);
    std::cout << n + " ";
    pzz(n - 1);
    std::cout << n + " ";
}

int main()
{
    int n;
    std::cin >> n;
    pzz(n);
    return 0;
}

/*
Question:- https://nados.io/question/print-zigzag
Article:- https://nados.io/article/print-zigzag
Videos:- https://www.youtube.com/watch?v=R7qja_gZrvI
*/