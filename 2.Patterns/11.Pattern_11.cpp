#include <iostream>

/*

        1
    2	3	2
3	4	5	4	3
    2	3	2
        1

*/
int main()
{
    int n;
    std::cin >> n;
    int n_space = n / 2;
    int n_number = 1;
    int value = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n_space; j++)
            std::cout << "\t";
        int c_value = value;
        for (int j = 1; j <= n_number; j++)
        {
            std::cout << c_value << "\t";
            if (j <= n_number / 2)
            {
                c_value++;
            }
            else
            {
                c_value--;
            }
        }
        std::cout << std::endl;
        if (i <= n / 2)
        {
            n_space--;
            n_number += 2;
            value++;
        }
        else
        {
            n_space++;
            n_number -= 2;
            value--;
        }
    }
    return 0;
}