#include <iostream>
#include <vector>

int last_occurence(std::vector<int> vec, int index, int element)
{
    if (index < 0)
        return -1;

    if (vec[index] == element)
        return index;

    int last_index = last_occurence(vec, index - 1, element);
    return last_index;
}

int main()
{
    int n;
    std::cout << "Enter number of element:";
    std::cin >> n;
    std::vector<int> vec(n, 0);
    std::cout << "Enter Array elements:";

    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }

    int element;
    std::cout << "Enter element to find:";
    std::cin >> element;
    int index = last_occurence(vec, vec.size() - 1, element);
    std::cout << index;
    return 0;
}

/*
Question :- https://nados.io/question/last-index
Article:- https://nados.io/article/last-index
Video:- https://www.youtube.com/watch?v=xttMLI4Kb3k
*/