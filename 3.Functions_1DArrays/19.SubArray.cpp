#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                std::cout << vec[k] << " ";
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

/*
Time Comp :- O(n3)
space comp:- O(1);
/*

/*
Problem:- https://nados.io/question/subarray-problem
Articles:-https://nados.io/article/sub-arrays-of-an-array
Videos:- https://youtu.be/lUdWGkCUD54
*/