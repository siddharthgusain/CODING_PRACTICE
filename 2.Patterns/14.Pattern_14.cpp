#include <iostream>

/*

*	*	*	*	*
    *		*
        *
    *	*	*
*	*	*	*	*

*/
int main()
{
    int n;
    std::cin >> n;

    int nst = n;
    int nsp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < nsp; j++)
        {
            std::cout << "\t";
        }

        for (int j = 0; j < nst; j++)
        {
            if (i > 0 && i < n / 2 && j > 0 && j < nst - 1)
            {
                std::cout << "\t";
            }
            else
            {
                std::cout << "*\t";
            }
        }

        if (i < n / 2)
        {
            nst -= 2;
            nsp++;
        }
        else
        {
            nst += 2;
            nsp--;
        }

        std::cout << std::endl;
    }

    return 0;
}