#include <iostream>
#include <vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector<string> getMazePaths(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }

    vector<string> myAns;
    if (sc + 1 <= dc)
    {
        vector<string> Horizontal = getMazePaths(sr, sc + 1, dr, dc);
        for (string s : Horizontal)
        {
            myAns.push_back("h" + s);
        }
    }

    if (sr + 1 <= dr)
    {
        vector<string> Vertical = getMazePaths(sr + 1, sc, dr, dc);
        for (string s : Vertical)
        {
            myAns.push_back("v" + s);
        }
    }

    return myAns;
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
    vector<string> ans = getMazePaths(0, 0, n - 1, m - 1);
    display(ans);

    return 0;
}

/*
Question :- https://nados.io/question/get-maze-paths
Article:- https://nados.io/article/get-maze-paths
Video:- https://www.youtube.com/watch?v=7i41gZLXe5k
*/
