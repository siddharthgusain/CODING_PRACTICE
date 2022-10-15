#include <iostream>

int pow(int x, int n)
{
    if (n == 0)
        return 1; // base case

    return x * pow(x, n - 1);
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
Question:- https://nados.io/question/power-linear
Article:-https://nados.io/article/power-function
Videos:- https://www.youtube.com/watch?v=EohIyWnQYBY
*/