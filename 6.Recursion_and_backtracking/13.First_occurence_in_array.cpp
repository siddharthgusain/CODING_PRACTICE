#include <iostream>
#include <vector>

int first_occurence(std::vector<int> vec, int index, int element)
{
    if (index == vec.size())
        return -1;

    if (vec[index] == element)
        return index;

    int first_index = first_occurence(vec, index + 1, element);
    return first_index;
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
    int index = first_occurence(vec, 0, element);
    std::cout << index;
    return 0;
}

/*
Question :- https://nados.io/question/first-index
Article:- https://nados.io/article/first-index
Video:- https://www.youtube.com/watch?v=TU0xUG9eO3Y
*/