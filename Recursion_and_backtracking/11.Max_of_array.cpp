#include <iostream>
#include <vector>

int max_of_array(std::vector<int> &vec, int index)
{
    if (index == vec.size() - 1)
        return vec[index];

    int partial_max = max_of_array(vec, index + 1);
    if (vec[index] > partial_max)
        return vec[index];
    else
        return partial_max;
}

int main()
{
    int size;
    std::cin >> size;
    std::vector<int> vec(size, 0);

    for (int i = 0; i < vec.size(); i++)
    {
        std::cin >> vec[i];
    }

    std::cout << max_of_array(vec, 0);

    return 0;
}