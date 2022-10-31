#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}
int findpivot(vector<int> &arr)
{
    int lo = 0;
    int hi = arr.size() - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] < arr[hi])
        {
            hi = mid;
        }
        else if (arr[mid] > arr[hi])
        {
            lo = mid + 1;
        }
    }

    return arr[hi];
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    input(vec);
    int pivot = findpivot(vec);
    cout << pivot;
    return 0;
}

/*
Question :- https://nados.io/question/pivot-in-sorted-and-rotated-array
Article:- https://nados.io/article/pivot-in-a-sorted-and-rotated-array
Video:- https://www.youtube.com/watch?v=vF7gk4iaklA
*/