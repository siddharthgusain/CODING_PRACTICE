#include <iostream>

/*

1
1	1
1	2	1
1	3	3	1
1	4	6	4	1

*/
int main()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int icj = 1;
        for (int j = 0; j <= i; j++)
        {
            std::cout << icj << "\t";
            int icj1 = (icj * (i - j)) / (j + 1);
            icj = icj1;
        }
        std::cout << std::endl;
    }

    return 0;
}