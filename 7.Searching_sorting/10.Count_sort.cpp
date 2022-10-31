#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void count_sort(vector<int> &arr, int max, int min)
{

    int fsize = max - min + 1;
    vector<int> freq(fsize, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        int idx = arr[i] - min;
        freq[idx]++;
    }

    for (int i = 1; i < freq.size(); i++)
    {
        freq[i] = freq[i] + freq[i - 1]; // prefix summ array
    }

    vector<int> ans(arr.size(), 0);

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int idx = arr[i] - min;
        ans[freq[idx] - 1] = arr[i];
        freq[idx]--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = ans[i];
    }
}

void display(vector<int> &arr)
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

    int maxi = (int)-1e9;
    int mini = (int)1e9;

    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    count_sort(arr, maxi, mini);
    display(arr);
}

/*
Question :- https://nados.io/question/quick-select
Article:- https://nados.io/article/quick-select
Video:- https://www.youtube.com/watch?v=p-OyKUgIrx4
*/