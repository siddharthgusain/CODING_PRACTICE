#include <iostream>

/*

1								1
1	2						2	1
1	2	3				3	2	1
1	2	3	4		4	3	2	1
1	2	3	4	5	4	3	2	1


*/
int main()
{
    int n;
    std::cin >> n;
    int n_number = 1;
    int n_space = 2 * n - 3;
    for (int i = 1; i <= n; i++)
    {
        int value = 1;
        for (int j = 1; j <= n_number; j++)
        {
            std::cout << value << "\t";
            value++;
        }
        for (int j = 1; j <= n_space; j++)
        {
            std::cout << "\t";
        }
        value--;
        if (i == n)
        {
            value--;
            n_number--;
        }
        for (int j = 1; j <= n_number; j++)
        {
            std::cout << value << "\t";
            value--;
        }
        n_number++;
        n_space -= 2;
        std::cout << std::endl;
    }
    return 0;
}