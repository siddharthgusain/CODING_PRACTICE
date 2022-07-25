#include <iostream>
#include <vector>

void reverse_array(std::vector<int> &vec, int pos1, int pos2)
{
    for (int i = pos1, j = pos2; i < j; i++, j--)
    {
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }
    int k;
    std::cin >> k;
    k = k % n;
    if (k < 0)
        k = k + vec.size();
    reverse_array(vec, 0, vec.size() - k - 1); // reverse first half
    reverse_array(vec, vec.size() - k, n - 1); // reverse second half
    reverse_array(vec, 0, n - 1);              // reverse whole array
    for (int val : vec)
    {
        std::cout << val;
    }
}

/*
Time Comp :- O(n)
space comp:- O(1);
/*

/*
Problem:- https://nados.io/question/rotate-an-array
Articles:-https://nados.io/article/rotate-an-array
Videos:- https://youtu.be/8RErc0VXAo8
*/