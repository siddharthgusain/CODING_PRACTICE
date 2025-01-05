#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_path_with_jumps(int sr, int sc, int dr, int dc)
{

    if (sr == dr && sc == dc) // Destination Block
    {
        vector<string> base_path;
        base_path.push_back("");
        return base_path;
    }

    vector<string> final_result;

    // ALl Horizontal Moves
    for (int jump = 1; sc + jump <= dc; jump++)
    {
        vector<string> horizontal_paths = get_maze_path_with_jumps(sr, sc + jump, dr, dc);
        for (auto ele : horizontal_paths)
        {
            final_result.push_back("h" + to_string(jump) + ele);
        }
    }

    // ALl Vertical Moves
    for (int jump = 1; sr + jump <= dr; jump++)
    {
        vector<string> vertical_paths = get_maze_path_with_jumps(sr + jump, sc, dr, dc);
        for (auto ele : vertical_paths)
        {
            final_result.push_back("v" + to_string(jump) + ele);
        }
    }

    // ALl Diagonal Moves
    for (int jump = 1; sr + jump <= dr && sc + jump <= dc; jump++) // Diagonal Movement is only allowed in Square Matrix
    {
        vector<string> diagonal_paths = get_maze_path_with_jumps(sr + jump, sc + jump, dr, dc);
        for (auto ele : diagonal_paths)
        {
            final_result.push_back("d" + to_string(jump) + ele);
        }
    }

    return final_result;
}

void display(vector<string> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<string> paths = get_maze_path_with_jumps(0, 0, rows - 1, cols - 1);

    display(paths);

    return 0;
}