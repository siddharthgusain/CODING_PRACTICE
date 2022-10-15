#include <iostream>

void print_increasing_decreasing(int num)
{
    if (num == 0)
        return;
    std::cout << num << std::endl;
    print_increasing_decreasing(num - 1);
    std::cout << num << std::endl;
}

int main()
{
    int num;
    std::cin >> num;
    print_increasing_decreasing(num);
    return 0;
}

/*
Question :- https://nados.io/question/print-increasing-decreasing
Article:- https://nados.io/article/print-increasing-decreasing
Video:- https://www.youtube.com/watch?v=BWr4zBiRtJY
*/