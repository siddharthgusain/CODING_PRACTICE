#include <iostream>
#include <vector>

std::vector<int> all_indices(std::vector<int> vec, int index, int ele, int count)
{
    if (index == vec.size())
    {
        std::vector<int> sub_result_vec(count, 0);
        return sub_result_vec;
    }

    if (vec[index] == ele)
        count++; // to get the count of elements to determine size of resulting array while going up in recursion

    std::vector<int> result = all_indices(vec, index + 1, ele, count); // recursive call

    if (vec[index] == ele) // to fill vector given by base case while returning back from recursion
        result[count - 1] = index;

    return result;
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

    int element;
    std::cin >> element;

    std::vector<int> result = all_indices(vec, 0, element, 0); // count variable is very useful to count the total times the element is found to make resultant vector

    if (result.size() == 0)
        std::cout << "No index found";
    else
    {
        for (int ele : result)
            std::cout << ele << ",";
    }

    return 0;
}