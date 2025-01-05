#include <iostream>
#include <vector>

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
    int first_occur, last_occur;

    // Finding First Occurrence
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] == key)
        {
            first_occur = mid;
            end = mid - 1;
        }
        else if (key > vec[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] == key)
        {
            last_occur = mid;
            start = mid + 1;
        }
        else if (key > vec[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    std::cout << "FIRST:" << first_occur << std::endl;
    std::cout << "LAST:" << last_occur << std::endl;
}

/*
-> array must be sorted
Time Comp :- O(log(n))
space comp:- O(1);
*/

/*
Problem:- https://nados.io/article/first-and-last-index
Articles:-https://nados.io/article/first-and-last-index
Videos:- https://www.youtube.com/watch?v=9NXZccIWNqU
*/