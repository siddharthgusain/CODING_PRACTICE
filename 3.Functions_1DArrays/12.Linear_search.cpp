#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int *ptr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> ptr[i];
    }
    int element;
    std::cin >> element;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i] == element)
        {
            std::cout << "FOUND AT INDEX:" << i;
            return 0;
        }
    }
    std::cout << -1;
    return 0;
}

/*
Array can be sorted or unsorted
Algo:- linear search
Time comp:- O(n)
Space Comp :- O(1)
/*

Problem:- https://nados.io/question/find-element-in-an-array
Articles:- https://nados.io/article/find-element-in-an-array
Videos:- https://youtu.be/3AcyounXhfg