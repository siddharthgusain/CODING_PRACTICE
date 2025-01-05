#include <iostream>
#include <vector>

int last_occurrence(std::vector<int> &vec, int index, int number)
{
    if (index == vec.size())
        return -1;

    int last_occurrence_found = last_occurrence(vec, index + 1, number);
    if (last_occurrence_found == -1)
    {
        if (vec[index] == number)
            return index;
        else
            return -1;
    }
    else
        return last_occurrence_found;
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

    std::cout << last_occurrence(vec, 0, number);

    return 0;
}