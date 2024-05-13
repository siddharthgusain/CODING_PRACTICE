#include <iostream>
#include <vector>

int main()
{
    int r1, c1, r2, c2, r3, c3;
    std::cin >> r1 >> c1 >> r2 >> c2;
    r3 = r1;
    c3 = c2;

    std::vector<std::vector<int>> a(r1, std::vector<int>(c1));
    std::vector<std::vector<int>> b(r2, std::vector<int>(c2));
    std::vector<std::vector<int>> c(r3, std::vector<int>(c3));

    // first matrix
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            std::cin >> a[i][j];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }

    // second matrix
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            std::cin >> b[i][j];

    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
            std::cout << b[i][j] << " ";
        std::cout << std::endl;
    }

    if (c1 != r2)
        std::cout << "Matrix multiplication not possible";
    else
    {
        for (int i = 0; i < r1; i++)
            for (int j = 0; j < c2; j++)
            {
                for (int k = 0; k < c1; k++)
                    c[i][j] += a[i][k] * b[k][j];
            }
        std::cout << std::endl;
        for (int i = 0; i < r3; i++)
        {
            for (int j = 0; j < c3; j++)
                std::cout << c[i][j] << " ";
            std::cout << std::endl;
        }
    }
}

/*
Time comp:- O(n^2)
Space Comp :- O(n*m)
*/

/*
Problem:- https://nados.io/question/matrix-multiplication
Articles:-https://nados.io/article/matrix-multiplication
Videos:- https://www.youtube.com/watch?v=0dGuTLr6xT4
*/
