#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(int n, vector<vector<int>> &arr)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swap(arr[i][j], arr[j][i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            swap(arr[i][j], arr[i][n - 1 - j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    rotate(n, arr);
}

/*
Problem:- https://nados.io/question/rotate-by-90-degree
Articles:-https://nados.io/article/rotate-by-90-degrees
Videos:-https://www.youtube.com/watch?v=SoxrXQbhCPI
*/