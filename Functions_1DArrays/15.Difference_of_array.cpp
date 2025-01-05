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
    int n3 = n2 > n1 ? n2 : n1;
    std::vector<int> arr3(n3, 0);
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    int k = arr3.size() - 1;
    int borrow = 0;
    while (k >= 0)
    {
        int digit;
        int arr2_value = j >= 0 ? arr2[j] : 0; // if the j value becomes negative(corner cases)
        if (arr1[i] + borrow >= arr2_value)
        {
            digit = (arr1[i] + borrow) - arr2_value;
            borrow = 0;
        }
        else
        {
            digit = (10 + arr1[i] + borrow) - arr2_value;
            borrow = -1;
        }
        arr3[k] = digit;
        i--;
        j--;
        k--;
    }
    int index = 0;
    // loop to remove starting Zero elements
    while (index < n3)
    {
        if (arr3[index] == 0)
            index++;
        else
            break;
    }

    for (int i = index; i < n3; i++)
    {
        std::cout << arr3[i];
    }
    return 0;
}

/*
Time Comp :- O(n)
space comp:- O(n); --> extra array
/*

/*
Problem:- https://nados.io/question/difference-of-two-arrays
Articles:- https://nados.io/article/difference-of-two-arrays
Videos:- https://youtu.be/jKyuWD8XKjw
*/