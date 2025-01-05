#include <iostream>
#include <string>
// using namespace std;

void print_maze_paths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr > dr || sc > dc)
    {
        return;
    }

    if (sr == dr && sc == dc)
    {
        std::cout << psf << std::endl;
        return;
    }

    // horizontal
    for (int jumps = 1; jumps <= dc - sc; jumps++)
    {
        print_maze_paths(sr, sc + jumps, dr, dc, psf + "h" + (std::to_string)(jumps));
    }

    // vertical
    for (int jumps = 1; jumps <= dr - sr; jumps++)
    {
        print_maze_paths(sr + jumps, sc, dr, dc, psf + "v" + (std::to_string)(jumps));
    }

    // diagonal
    for (int jumps = 1; jumps <= dr - sr && jumps <= dc - sc; jumps++)
    {
        print_maze_paths(sr + jumps, sc + jumps, dr, dc, psf + "d" + (std::to_string)(jumps));
    }
}

int main()
{
    int n;
    int m;
    std::cin >> n >> m;

    print_maze_paths(0, 0, n - 1, m - 1, "");
}