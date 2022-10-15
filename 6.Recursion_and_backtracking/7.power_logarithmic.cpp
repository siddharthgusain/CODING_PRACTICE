#include <iostream>

int pow(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
        return pow(x, n / 2) * pow(x, n / 2);
    else
        return x * pow(x, n / 2) * pow(x, n / 2);
}

int main()
{
    int x, n;
    std::cin >> x >> n;

    long long result = pow(x, n);
    std::cout << result;
    return 0;
}

/*
Question:- https://nados.io/question/power-logarithmic
Article:- https://nados.io/article/power-function
Videos:- https://www.youtube.com/watch?v=O84uumjBOMY
*/