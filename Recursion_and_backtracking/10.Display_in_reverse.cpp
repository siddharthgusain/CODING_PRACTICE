#include <iostream>
#include <vector>

void display(const std::vector<int> &vec, int index)
{
    if (index == vec.size())
        return;
    display(vec, index + 1);
    std::cout << vec[index] << "\t";
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

    display(vec, 0);

    return 0;
}