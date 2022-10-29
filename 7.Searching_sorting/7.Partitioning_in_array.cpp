#include <bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void partition(int arr[], int n, int pivot)
{
    int p1 = -1;
    int itr = 0;
    while (itr < n)
    {
        if (arr[itr] <= pivot)
        {
            swap(arr, itr, ++p1);
        }
        itr++;
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pivot;
    cin >> pivot;

    partition(arr, n, pivot);
    print(arr, n);

    return 0;
}

/*
Time comp:- o(n)
Space comp:- o(1)
*/

/*
Question :- https://nados.io/question/partition-an-array
Article:- https://nados.io/article/partition-an-array
Video:- https://www.youtube.com/watch?v=if40LxQ8_Xo
*/