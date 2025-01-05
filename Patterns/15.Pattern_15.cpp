#include <iostream>

/*

* * * * *       *
        *       *
        *       *
        *       *
* * * * * * * * *
*       *
*       *
*       *
*       * * * * *

*/
int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1) // first component
            {
                if (j == n || j <= n / 2 + 1)
                {
                    std::cout << "* ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
            else if (i <= n / 2) // second component
            {
                if (j == n || j == n / 2 + 1)
                {
                    std::cout << "* ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
            else if (i == n / 2 + 1) // third component
            {
                std::cout << "* ";
            }
            else if (i < n) // fourth component
            {
                if (j == 1 || j == n / 2 + 1)
                {
                    std::cout << "* ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
            else // fifth component
            {
                if (j == 1 || j >= n / 2 + 1)
                {
                    std::cout << "* ";
                }
                else
                {
                    std::cout << "  ";
                }
            }
        }
        std::cout << std::endl; // changing row
    }
    return 0;
}
