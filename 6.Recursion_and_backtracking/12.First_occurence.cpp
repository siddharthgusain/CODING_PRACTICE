#include <iostream>
#include <vector>

int first_occurrence(std::vector<int> &vec, int index, int number)
{
    if (index == vec.size())
        return -1;

    if (vec[index] == number)
        return index;
    else
    {
        int first_occurrence_found = first_occurrence(vec, index + 1, number);
        return first_occurrence_found;
    }
}

int main()
{
    int size, number;
    std::cin >> size >> number;
    std::vector<int> vec(size, 0);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cin >> vec[i];
    }

    std::cout << first_occurrence(vec, 0, number);

    return 0;
}