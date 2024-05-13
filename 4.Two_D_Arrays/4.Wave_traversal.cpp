#include <iostream>
#include <vector>

int main()
{
    int r1, c1;
    std::cin >> r1 >> c1;
    std::vector<std::vector<int>> a(r1, std::vector<int>(c1));

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            std::cin >> a[i][j];

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }

    for (int j = 0; j < a[0].size(); j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < a.size(); i++)
                std::cout << a[i][j] << "->";
        }
        else
        {
            for (int i = a.size() - 1; i >= 0; i--)
                std::cout << a[i][j] << "->";
        }
    }

    return 0;
};

/*
Problem:- https://nados.io/question/the-state-of-wakanda-1
Articles:-https://nados.io/article/the-state-of-wakanda-1
Videos:- https://www.youtube.com/watch?v=_olQ9Rrnm_c
*/
