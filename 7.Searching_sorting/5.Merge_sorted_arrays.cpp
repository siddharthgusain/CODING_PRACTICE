#include <iostream>
#include <vector>

void merge_arrays(std::vector<int> &vec1, std::vector<int> &vec2, std::vector<int> &output)
{
    int i = 0, j = 0, k = 0;
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] <= vec2[j])
        {
            output[k] = vec1[i];
            i++;
            k++;
        }
        else
        {
            output[k] = vec2[j];
            j++;
            k++;
        }
    }

    while (i < vec1.size()) // if i is not at the end of first array
    {
        output[k] = vec1[i];
        k++;
        i++;
    }

    while (j < vec2.size()) // if j is not at the end of second array
    {
        output[k] = vec2[j];
        j++;
        k++;
    }
}

int main()
{
    int n, m;

    std::cin >> n;
    std::vector<int> vec1(n, 0);
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec1[i];
    }

    std::cin >> m;
    std::vector<int> vec2(m, 0);
    for (int i = 0; i < m; i++)
    {
        std::cin >> vec2[i];
    }

    std::vector<int> merged(n + m, 0);

    merge_arrays(vec1, vec2, merged);

    for (int ele : merged)
    {
        std::cout << ele << ",";
    }

    return 0;
}

/*
Time comp:- o(n)
Space comp:- o(1)
*/

/*
Question :-https://nados.io/question/merge-two-sorted-arrays
Article:- https://nados.io/article/merge-two-sorted-arrays
Video:- https://www.youtube.com/watch?v=WMxNhIBA92I
*/