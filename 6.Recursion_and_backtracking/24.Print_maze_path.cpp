#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr > dr || sc > dc)
    {
        return;
    }

    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }

    printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    printMazePaths(sr + 1, sc, dr, dc, psf + "v");
}

int main()
{
    int n;
    int m;
    cin >> n >> m;

    printMazePaths(0, 0, n - 1, m - 1, "");
}

/*
Question :- https://nados.io/question/print-maze-paths
Article:- https://nados.io/article/print-maze-path
Video:- https://www.youtube.com/watch?v=MHtAA5UE-6Y
*/