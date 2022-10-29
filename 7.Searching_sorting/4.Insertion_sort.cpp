#include <iostream>
#include <vector>

void swap(std::vector<int> &vec, int i, int j)
{
    std::cout << "Swapping:" << vec[i] << "," << vec[j] << std::endl;
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

bool is_greater(std::vector<int> &vec, int i, int j)
{
    std::cout << "Comparing:" << vec[i] << "," << vec[j] << std::endl;
    if (vec[i] > vec[j])
        return true;
    return false;
}

void insertion_sort(std::vector<int> &vec)
{
    for (int iteration = 1; iteration < vec.size(); iteration++)
    {
        for (int j = iteration - 1; j >= 0; j--)
        {
            if (is_greater(vec, j, j + 1))
                swap(vec, j, j + 1);
            else
                break;
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

    insertion_sort(vec);

    for (int ele : vec)
        std::cout << ele << ",";

    return 0;
}

/*
Time comp:- o(n2)
Space comp:- o(1)
*/

/*
Question :- https://nados.io/question/insertion-sort
Article:- https://nados.io/article/insertion-sort
Video:- https://www.youtube.com/watch?v=MMt2x6an_i8
*/