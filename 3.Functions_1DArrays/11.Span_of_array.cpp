#include <iostream>
#include <vector>

int main()
{
    int n, temp;
    std::vector<int> vec;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }
    int min = vec[0];
    int max = vec[0];
    for (int i = 0; i < n; i++)
    {
        if (vec[i] < min)
            min = vec[i];
        if (vec[i] > max)
            max = vec[i];
    }

    std::cout << "span=" << max - min;
    return 0;
}

/*
Problem:- https://nados.io/question/span-of-array
Articles:- https://nados.io/article/span-of-an-array
Videos:- https://youtu.be/1SsXm5TI8W4
*/