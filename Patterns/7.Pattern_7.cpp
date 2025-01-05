#include <iostream>

/*
        *
    *		*
*				*
    *		*
        *

*/
int main()
{

    int n;
    std::cin >> n;
    int nos = n / 2;
    int nis = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= nos; j++)
        {
            std::cout << "\t";
        }
        std::cout << "*\t";

        for (int j = 1; j <= nis; j++)
        {
            std::cout << "\t";
        }
        if (i > 1 && i < n)
        {
            std::cout << "*\t";
        }

        if (i <= n / 2)
        {
            nos--;
            nis += 2;
        }
        else
        {
            nos++;
            nis -= 2;
        }

        std::cout << std::endl;
    }
    return 0;
}
