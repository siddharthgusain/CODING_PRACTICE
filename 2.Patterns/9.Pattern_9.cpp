#include <iostream>

/*

0
1	1
2	3	5
8	13	21	34
55	89	144	233	377

*/

int main()
{
    int num;
    std::cin >> num;
    int prev = 0, next = 1;
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            std::cout << prev << "\t";
            int c = prev + next;
            prev = next;
            next = c;
        }
        std::cout << std::endl;
    }
    return 0;
}