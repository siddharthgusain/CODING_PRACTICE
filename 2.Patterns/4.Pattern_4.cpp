#include <iostream>

/*
 *	*	*		*	*	*
 *	*				*	*
 *						*
 *	*				*	*
 *	*	*		*	*	*
 */

int main()
{
    int n;
    std::cin >> n;
    int n_space = 1;
    int n_star = (n / 2) + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n_star; j++)
            std::cout << "*\t";
        for (int j = 1; j <= n_space; j++)
            std::cout << "\t";
        for (int j = 1; j <= n_star; j++)
            std::cout << "*\t";
        std::cout << std::endl;
        if (i <= n / 2)
        {
            n_star--;
            n_space += 2;
        }
        else
        {
            n_star++;
            n_space -= 2;
        }
    }
    return 0;
}