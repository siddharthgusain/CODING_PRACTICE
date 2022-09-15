#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    if (n == 0)
        return false;

    int r = 0, c = n - 1;
    while (r < n && c >= 0)
    {
        if (matrix[r][c] == target)
        {
            cout << r << endl
                 << c << endl;
            return true;
        }
        if (matrix[r][c] < target)
            r++;
        else
            c--;
    }
    return false;
}

int main()
{
    int n, target;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    cin >> target;

    if (!searchMatrix(mat, target))
        cout << "Not Found\n";
}

/*
Problem:- https://nados.io/question/search-in-a-sorted-2d-array
Articles:- https://nados.io/article/search-in-a-2d-sorted-array
Videos:- https://www.youtube.com/5vP0-g94xEA
*/