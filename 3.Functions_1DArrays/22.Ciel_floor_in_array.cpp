#include <iostream>
#include <vector>
#include <climits>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> vec(n, 0);

    // input
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
    }

    int key;
    std::cin >> key;

    int start = 0, end = n - 1;
    int floor = INT_MIN, ciel = INT_MAX;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] == key)
        {
            ciel = vec[mid];
            floor = vec[mid];
            break;
        }
        else if (key > vec[mid])
        {
            start = mid + 1;
            floor = vec[mid];
        }
        else
        {
            end = mid - 1;
            ciel = vec[mid];
        }
    }

    std::cout << "FLOOR:" << floor << std::endl;
    std::cout << "CIEL:" << ciel << std::endl;
}

/*
-> array must be sorted
Time Comp :- O(log(n))
space comp:- )(1);
*/

/*
Problem:- https://nados.io/question/broken-economy
Articles:-https://nados.io/article/broken-economy
Videos:- https://www.youtube.com/watch?v=qaQRRWXgFIQ
*/