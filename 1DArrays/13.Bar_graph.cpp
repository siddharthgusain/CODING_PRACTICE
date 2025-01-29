#include <iostream>
#include <climits>

int main()
{
    int n;
    std::cin >> n;
    int *ptr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> ptr[i];
    }
    // find max element to find the maximum height of chart
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] > max)
            max = ptr[i];
    }
    for (int j = max; j > 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (j > ptr[i])
                std::cout << "\t";
            else
                std::cout << "*\t";
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
Time Comp :- O(n^2)
space comp:- O(n);
/*

Problem:- https://nados.io/question/bar-chart
Articles:- https://nados.io/article/bar-chart
Videos:- https://youtu.be/L-0IxqvYQKs
*/