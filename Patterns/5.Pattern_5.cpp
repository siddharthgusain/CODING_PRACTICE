#include <iostream>

/*
*
    *
        *
            *
                *

*/
int main()
{
    int n;
    std::cin >> n;
    int n_space = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n_space; j++)
            std::cout << "\t";
        std::cout << "*" << std::endl;
        n_space++;
    }
    return 0;
}