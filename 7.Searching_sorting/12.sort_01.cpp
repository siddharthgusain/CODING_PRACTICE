#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    cout << "Swapping index " << i << " and index " << j << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort01(vector<int> &arr)
{
    // write your code here
    int curr = 0;
    int prev = -1;
    while (curr < arr.size())
    {
        if (arr[curr] == 0)
        {
            prev++;
            swap(arr, curr, prev);
        }
        curr++;
    }
}

void Display(vector<int> &arr)
{
    for (int ele : arr)
    {
        cout << ele << endl;
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

    sort01(arr);
    Display(arr);
    return 0;
}

/*
Question :- https://nados.io/question/sort-01
Article:- https://nados.io/article/sort-01
Video:- https://www.youtube.com/watch?v=jFrUwjx4eoA
*/