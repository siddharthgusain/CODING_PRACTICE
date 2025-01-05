#include <iostream>
/*

        *
    *	*	*
*	*	*	*	*
    *	*	*
        *

*/
int main()
{
    int n;
    std::cin >> n;
    int n_space = n / 2;
    int n_star = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n_space; j++)
            std::cout << "\t";
        for (int j = 1; j <= n_star; j++)
            std::cout << "*\t";
        if (i <= n / 2)
        {
            n_space--;
            n_star += 2;
        }
        else
        {
            n_space++;
            n_star -= 2;
        }
        std::cout << "\n";
    }
}