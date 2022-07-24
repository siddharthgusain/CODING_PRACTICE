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
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
    for (int val : vec)
    {
        std::cout << val << " ";
    }
    return 0;
}

/*
Time Comp :- O(n)
space comp:- O(1); --> extra array
/*

/*
Problem:- https://nados.io/question/reverse-an-array
Articles:-https://nados.io/article/reverse-an-array
Videos:- https://youtu.be/CuvSfyO5iRU
*/