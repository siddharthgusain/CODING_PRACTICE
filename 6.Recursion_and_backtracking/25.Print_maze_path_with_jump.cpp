#include <iostream>
using namespace std;

void print_maze_paths(int sr, int sc, int dr, int dc, string psf)
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

    // horizontal
    for (int jumps = 1; jumps <= dc - sc; jumps++)
    {
        print_maze_paths(sr, sc + jumps, dr, dc, psf + "h" + (to_string)(jumps));
    }

    // vertical
    for (int jumps = 1; jumps <= dr - sr; jumps++)
    {
        print_maze_paths(sr + jumps, sc, dr, dc, psf + "v" + (to_string)(jumps));
    }

    // diagonal
    for (int jumps = 1; jumps <= dr - sr && jumps <= dc - sc; jumps++)
    {
        print_maze_paths(sr + jumps, sc + jumps, dr, dc, psf + "d" + (to_string)(jumps));
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;

    print_maze_paths(0, 0, n - 1, m - 1, "");
}

/*
Question :- https://nados.io/question/print-maze-paths-with-jumps
Article:- https://nados.io/article/print-maze-path-with-jumps
Video:- https://www.youtube.com/watch?v=zri_tftYphE
*/
