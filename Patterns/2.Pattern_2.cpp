#include <iostream>
/*

     *
   * *
 * * *

*/
int main()
{
    int n;
    std::cin >> n;
    int n_space = n - 1;
    int n_star = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n_space; j++)
        {
            std::cout << " ";
        }
        for (int j = 1; j <= n_star; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
        n_space--;
        n_star++;
    }
    return 0;
}