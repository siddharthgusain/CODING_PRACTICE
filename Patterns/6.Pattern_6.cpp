#include <iostream>
/*
*				*
    *		*
        *
    *		*
*				*

*/

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || i + j == n + 1)
                std::cout << "*\t";
            else
                std::cout << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}