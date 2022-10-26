#include <iostream>
#include <vector>

using namespace std;

void flood_fill(vector<vector<int>> maze, int sr, int sc, string asf, vector<vector<bool>> visited)
{
    if (sr == maze.size() - 1 && sc == maze[0].size() - 1)
    {
        cout << asf << endl;
        return;
    }

    if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || maze[sr][sc] == 1 || visited[sr][sc] == true)
    {
        return;
    }

    visited[sr][sc] = true; // required as in this question reverse direction is also there

    flood_fill(maze, sr - 1, sc, asf + "t", visited);
    flood_fill(maze, sr, sc - 1, asf + "l", visited);
    flood_fill(maze, sr + 1, sc, asf + "d", visited);
    flood_fill(maze, sr, sc + 1, asf + "r", visited);

    visited[sr][sc] = false; // very important step i.e removing visited while stack deallocation
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<bool>> visited(n, vector<bool>(m));

    flood_fill(arr, 0, 0, "", visited);
}

/*
Question :- https://nados.io/question/flood-fill
Article:-https://nados.io/article/flood-fill
Video:- https://www.youtube.com/watch?v=R1URUB6_y2k
*/
