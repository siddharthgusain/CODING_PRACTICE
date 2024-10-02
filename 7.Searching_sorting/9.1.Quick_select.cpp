#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int> &arr, int pivot, int lo, int hi)
{
    cout << "pivot -> " << pivot << endl;
    int curr = lo;
    int prev = lo - 1;
    while (curr <= hi)
    {
        if (arr[curr] <= pivot)
        {
            prev++;
            swap(arr, curr, prev);
        }
        curr++;
    }
    cout << "pivot index -> " << prev << endl;
    return prev;
}

int quick_select(vector<int> &arr, int lo, int hi, int k)
{

    int pivot = arr[hi];
    int pIdx = partition(arr, pivot, lo, hi); // This is changing actual Array

    if (pIdx > k) // Left side of Partition
    {
        quick_select(arr, lo, pIdx - 1, k);
    }
    else if (pIdx < k) // Right side of partition
    {
        quick_select(arr, pIdx + 1, hi, k);
    }
    else // If pivot index is equal to partitioned index
    {
        return arr[pIdx];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    int ans = quick_select(arr, 0, n - 1, k - 1);
    cout << ans << endl;
    return 0;
}

/*
Question :-https://nados.io/question/quick-select
Article:-https://nados.io/article/quick-select
Video:- https://www.youtube.com/watch?v=fnbImb8lo88
*/