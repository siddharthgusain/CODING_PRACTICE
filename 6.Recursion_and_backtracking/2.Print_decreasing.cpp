#include <iostream>

void print_decreasing(int num)
{
    if (num == 0)
        return;
    std::cout << num << std::endl;
    print_decreasing(num - 1);
}

int main()
{
    int num;
    std::cin >> num;
    print_decreasing(num);
    return 0;
}

/*
Question :- https://nados.io/question/print-decreasing
Article:- https://nados.io/article/print-decreasing
Video:- https://www.youtube.com/watch?v=5Q5ed7PWJ8I
*/