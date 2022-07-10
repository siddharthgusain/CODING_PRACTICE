#include <iostream>

/*
                        *
                        *       *
                        *       *       *
*       *       *       *       *       *       *
                        *       *       *
                        *       *
                        *

*/
int main()
{
    int n;
    std::cin >> n;
    int sp = n / 2; // variable to store space count
    int st = 1;     // variable to store star count
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sp; j++) // printing whitespaces
        {
            if (i == n / 2 + 1) // checking middle row
            {
                std::cout << "*	";
            }
            else
            {
                std::cout << "	";
            }
        }
        for (int j = 1; j <= st; j++) // printing the stars
        {
            std::cout << "*	";
        }
        if (i <= n / 2) // checking if less than or equal to middle row
        {
            st++; // increasing stars till middle row
        }
        else
        {
            st--; // decreasing stars post middle row
        }
        std::cout << std::endl; // Changing the row
    }
    return 0;
}