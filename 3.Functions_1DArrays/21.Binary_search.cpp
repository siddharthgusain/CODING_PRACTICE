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
    bool found = false;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (vec[mid] == key)
        {
            std::cout << "Found at:" << mid + 1 << " position";
            found = true;
            break;
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
    if(found == false)
    std::cout << "Not Found";
}

/*
-> array must be sorted
Time Comp :- O(log(n))
space comp:- )(1);
*/

/*
Problem:- https://nados.io/article/binary-search
Articles:-https://nados.io/article/binary-search
Videos:- https://www.youtube.com/watch?v=j6BgMBIOCLQ
*/