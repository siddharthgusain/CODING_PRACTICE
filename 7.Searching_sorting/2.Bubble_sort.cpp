#include <iostream>
#include <vector>

void swap(std::vector<int> &vec, int i, int j)
{
    std::cout << "Swapping:" << vec[i] << "," << vec[j] << std::endl;
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

bool is_smaller(std::vector<int> &vec, int i, int j)
{
    std::cout << "Comparing:" << vec[i] << "," << vec[j] << std::endl;
    if (vec[i] < vec[j])
        return true;
    return false;
}

void bubble_sort(std::vector<int> &vec)
{
    for (int iteration = 0; iteration < vec.size(); iteration++)
    {
        for (int j = 0; j < vec.size() - iteration - 1; j++)
        {
            if (is_smaller(vec, j + 1, j))
                swap(vec, j + 1, j);
        }
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

    bubble_sort(vec);

    for (int ele : vec)
        std::cout << ele << ",";

    return 0;
}

/*
Time comp:- o(n2)
Space comp:- o(1)
*/

/*
Question :- https://nados.io/question/print-decreasing
Article:- https://nados.io/article/print-decreasing
Video:- https://www.youtube.com/watch?v=5Q5ed7PWJ8I
*/