#include <iostream>
#include <vector>

int max(std::vector<int> vec, int index)
{
    if (index == vec.size())
        return vec[index]; // base case

    int max_small_array = max(vec, index + 1);
    if (max_small_array > vec[index])
        return max_small_array;
    return vec[index];
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

    int max_result = max(vec, 0);
    std::cout << max_result;
    return 0;
}

/*
Question :- https://nados.io/question/max-of-an-array
Article:- https://nados.io/article/max-of-an-array
Video:- https://www.youtube.com/watch?v=XpUiZg9YZQg
*/