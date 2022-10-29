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

void selection_sort(std::vector<int> &vec)
{
    for (int iteration = 0; iteration < vec.size(); iteration++)
    {
        int min = iteration; // position of min element

        // comparision loop to find minimum in rest of array
        for (int j = iteration + 1; j < vec.size(); j++)
        {
            if (is_smaller(vec, j, min))
                min = j;
        }
        swap(vec, iteration, min);
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

    selection_sort(vec);

    for (int ele : vec)
        std::cout << ele << ",";

    return 0;
}

/*
Time comp:- o(n2)
Space comp:- o(1)
*/

/*
Question :- https://nados.io/question/selection-sort
Article:- https://nados.io/article/selection-sort
Video:- https://www.youtube.com/watch?v=EU9FIt1t-Is
*/