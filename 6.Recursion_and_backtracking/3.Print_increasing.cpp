#include <iostream>

void print_increasing(int num)
{
    if (num == 0)
        return;
    print_increasing(num - 1);
    std::cout << num << std::endl;
}

int main()
{
    int num;
    std::cin >> num;
    print_increasing(num);
    return 0;
}

/*
Question :- https://nados.io/question/print-increasing
Article:- https://nados.io/article/print-increasing
Video:- https://www.youtube.com/watch?v=Y5IobAWmfjQ
*/