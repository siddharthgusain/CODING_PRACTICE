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

void quick_sort(vector<int> &arr, int lo, int hi)
{
    if (lo > hi) // Base case
    {
        return;
    }

    int pivot = arr[hi];
    int pIdx = partition(arr, pivot, lo, hi); // This Partitioning Changes/Swaps original Vector

    quick_sort(arr, lo, pIdx - 1);
    quick_sort(arr, pIdx + 1, hi);
}

void display(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    display(arr);
    return 0;
}

/*
Time comp:- o(n2) --> worst case if we pass sorted array as input
Avg case:- o(nlogn)
Space comp:- o(n)
*/

/*
Question :-https://nados.io/question/quick-sort
Article:-https://nados.io/article/quick-sort
Video:- https://www.youtube.com/watch?v=kdO5Q0nmPjU
*/