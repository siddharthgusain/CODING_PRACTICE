#include <bits/stdc++.h>
using namespace std;

bool is_Queen_Safe(int row, int col, vector<vector<int>> chess)
{
    for (int i = row - 1, j = col; i >= 0; i--) // vertically up checking
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) // diaganal left checking
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) // diagnally right checking
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void print_NQueens(vector<vector<int>> chess, string qsf, int row)
{
    // base case
    if (row == chess.size())
    {
        cout << qsf << ". " << endl;
        return;
    }
    // loop through columns
    for (int col = 0; col < chess.size(); col++)
    {
        if (is_Queen_Safe(row, col, chess))
        {
            chess[row][col] = 1; // v important
            print_NQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chess[row][col] = 0; // v imptant
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> chess(n, vector<int>(n));

    print_NQueens(chess, "", 0);
}

/*
Question :- https://nados.io/question/n-queens
Article:- https://nados.io/article/n-queens
Video:- https://www.youtube.com/watch?v=05y82cP3bJo
*/
