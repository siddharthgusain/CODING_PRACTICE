#include <iostream>
#include <vector>

using namespace std;

vector<string> get_maze_path(int sr, int sc, int dr, int dc)
{
    vector<string> horizontal_paths;
    vector<string> vertical_paths;

    if (sr == dr && sc == dc) // Actual Base Case -> Destination Reached
    {
        vector<string> base;
        base.push_back(""); // Blank Path
        return base;
    }

    if (sc < dc)
    { // Bottom Wall not reached , so vertical movement allowed
        horizontal_paths = get_maze_path(sr, sc + 1, dr, dc);
    }

    if (sr < dr) // Right Wall Not Reached , so Horizontal Movement Allowed
    {
        vertical_paths = get_maze_path(sr + 1, sc, dr, dc);
    }

    vector<string> final_paths;

    for (auto path : horizontal_paths)
    {
        final_paths.push_back("h" + path);
    }

    for (auto path : vertical_paths)
    {
        final_paths.push_back("v" + path);
    }

    return final_paths;
}

int main()
{
    int rows, cols;

    cin >> rows >> cols;

    vector<string> result = get_maze_path(0, 0, rows - 1, cols - 1);

    cout << "[";

    for (auto path : result)
    {
        cout << path << ",";
    }

    cout << "]";

    return 0;
}