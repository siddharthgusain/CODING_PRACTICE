#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    std::vector<int> inverse_vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    for (int i = 0; i < n; i++)
    {
        int value = vec[i];
        inverse_vec[value] = i;
    }
    for (int val : inverse_vec)
    {
        std::cout << val << " ";
    }
    return 0;
}

/*
Time Comp :- O(n)
space comp:- O(n); --> extra array
/*

/*
Problem:- https://nados.io/question/inverse-of-an-array
Articles:-https://nados.io/article/inverse-of-an-array
Videos:- https://youtu.be/1NvhnN56NKc
*/