#include <iostream>
#include <vector>

int main()
{
    int n1, n2;
    std::cin >> n1;
    std::vector<int> arr1(n1, 0);
    for (int i = 0; i < n1; i++)
    {
        std::cin >> arr1[i];
    }
    std::cin >> n2;
    std::vector<int> arr2(n2, 0);
    for (int i = 0; i < n2; i++)
    {
        std::cin >> arr2[i];
    }
    int n3 = n1 > n2 ? n1 : n2;
    std::vector<int> arr3(n3, 0);
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int k = arr3.size() - 1;
    int carry = 0;
    while (k >= 0)
    {
        int digit = carry;
        if (i >= 0)
            digit += arr1[i];
        if (j >= 0)
            digit += arr2[j];

        carry = digit / 10;
        digit = digit % 10;

        arr3[k] = digit;
        i--;
        j--;
        k--;
    }

    if (carry > 0)
        std::cout << carry;

    for (int val : arr3)
    {
        std::cout << val;
    }
    return 0;
}

/*
Time Comp :- O(n)
space comp:- O(n); --> extra array
/*

Problem:- https://nados.io/question/sum-of-two-arrays
Articles:- https://nados.io/article/sum-of-two-arrays
Videos:- https://youtu.be/BzJK1zNXwcU
*/