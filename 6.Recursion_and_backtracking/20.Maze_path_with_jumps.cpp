#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> get_maze_paths(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> empty_ans;
        empty_ans.push_back("");
        return empty_ans;
    }

    vector<string> ans;

    for (int jump = 1; jump + sc <= dc; jump++)
    {
        vector<string> h_paths = get_maze_paths(sr, sc + jump, dr, dc);

        for (string str : h_paths)
        {
            ans.push_back("h" + to_string(jump) + str);
        }
    }

    for (int jump = 1; jump + sr <= dr; jump++)
    {
        vector<string> v_paths = get_maze_paths(sr + jump, sc, dr, dc);
        for (string str : v_paths)
        {
            ans.push_back("v" + to_string(jump) + str);
        }
    }

    for (int jump = 1; jump + sr <= dr && jump + sc <= dc; jump++)
    {
        vector<string> d_paths = get_maze_paths(sr + jump, sc + jump, dr, dc);
        for (string str : d_paths)
        {
            ans.push_back("d" + to_string(jump) + str);
        }
    }
    return ans;
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
    int n, m;
    cin >> n >> m;
    vector<string> ans = get_maze_paths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}

/*
Question :- https://nados.io/question/get-maze-path-with-jumps
Article:- https://nados.io/article/get-maze-path-with-jumps
Video:- https://www.youtube.com/watch?v=VaGBRiSdtFI
*/
