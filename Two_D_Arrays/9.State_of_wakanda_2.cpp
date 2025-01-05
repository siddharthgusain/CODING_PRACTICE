#include <iostream>
#include <vector>
using namespace std;

void upperDiagonal_traverse(int n, vector<vector<int>> &arr)
{
    for (int gap = 0; gap < n; gap++)
        for (int i = 0, j = gap; j < n; i++, j++)
            cout << arr[i][j] << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    upperDiagonal_traverse(n, arr);
}

/*
Problem:- https://nados.io/question/the-state-of-wakanda-2
Articles:-https://nados.io/article/the-state-of-wakanda-2
Videos:- https://www.youtube.com/watch?v=lvRdFCMD_Ew
*/