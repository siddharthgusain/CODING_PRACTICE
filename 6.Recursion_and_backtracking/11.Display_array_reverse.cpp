#include <iostream>
#include <vector>

void display_array_element_reverse(std::vector<int> vec, int index)
{
    if (index == vec.size())
        return;
    display_array_element_reverse(vec, index + 1);
    std::cout << vec[index] << std::endl;
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

    display_array_element_reverse(vec, 0);
    return 0;
}

/*
Question :- https://nados.io/question/display-array-in-reverse
Article:- https://nados.io/article/display-array-reverse
Video:-https://www.youtube.com/watch?v=SJrfxaYBEFU
*/