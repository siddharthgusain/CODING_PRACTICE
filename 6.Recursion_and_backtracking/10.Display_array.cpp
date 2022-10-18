#include <iostream>
#include <vector>

void display_array_element(std::vector<int> vec, int index)
{
    if (index == vec.size())
        return;
    std::cout << vec[index] << std::endl;
    display_array_element(vec, index + 1);
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

    display_array_element(vec, 0);
    return 0;
}

/*
Question :- https://nados.io/question/display-array
Article:- https://nados.io/article/display-array
Video:- https://www.youtube.com/watch?v=SeU9D35MsK8
*/