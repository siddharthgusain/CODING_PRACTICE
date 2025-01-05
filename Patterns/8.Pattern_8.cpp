#include <iostream>
/*

1
2 3
4 5 6

*/
int main()
{
    int n;
    std::cin >> n;
    int value = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << value << "\t";
            value++;
        }
        std::cout << std::endl;
    }
    return 0;
}