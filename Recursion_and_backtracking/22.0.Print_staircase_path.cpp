#include <iostream>
using namespace std;

void print_stair_paths(int n, string path)
{
    if (n <= 0)
    {
        if (n == 0)
        {
            cout << path << endl;
        }
        return;
    }

    print_stair_paths(n - 1, path + "1");
    print_stair_paths(n - 2, path + "2");
    print_stair_paths(n - 3, path + "3");
}

int main()
{

    int n;
    cin >> n;

    print_stair_paths(n, "");
}
